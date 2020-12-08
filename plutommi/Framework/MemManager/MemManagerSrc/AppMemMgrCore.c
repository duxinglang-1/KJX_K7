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
 *  AppMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  App-Based Shared Memory Manager
 *
 *  App-based shared memory is allocated before entering an application, and 
 *  released when exiting an application. 
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "app_mem.h"
#include "mmi_frm_mem_prot.h"
#include "mmiapi_func.h"
#include "mmi_frm_scenario_prot.h"
#include "alertscreen.h"
#include "CustDataRes.h"
#include "UcmSrvGprot.h"
#include "Fix_size_mem.h"
#include "Mmi_frm_history.h"
#include "CommonScreensResDef.h"
#include "IdleGprot.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "AppMemMgrEnum.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_FRM_ASM_PREPARE_QUEUE_SIZE      (10)

#define MMI_FRM_ASM_SIZE_PLUS_EXTRA(size)    \
    (APPMEM_ALIGN_TO_N(size, ASM_ALIGN_SIZE) + APPLIB_MEM_GET_POOL_EXTRA_SIZE(APPLIB_MEM_AP_CHUNK_NUM)) 

#define __MMI_FRM_ASM_CORE_MUTEX__

#ifdef __MMI_FRM_ASM_CORE_MUTEX__
#define ASM_CORE_LOCK   mmi_frm_recursive_mutex_lock(&asm_core_rmutex)
#define ASM_CORE_UNLOCK mmi_frm_recursive_mutex_unlock(&asm_core_rmutex)
#else
#define ASM_CORE_LOCK
#define ASM_CORE_UNLOCK
#endif

/* max count of app allocates w/ reserve property simutaneously */
#define MMI_FRM_RESERVE_APP_MAX     (10)


/* asm property of app */
/* The sequence should be the same as mmi_frm_asm_property_struct */
#define ASM_F_PREPARE_W_RESERVE         (0)     /* prepare w/ reserve. internal use : base is reserved */
#define ASM_F_HIDE_IN_OOM               (1)     /* hide app in OOM dialog */
#define ASM_F_SKIP_SIZE_CHECKING        (2)     /* skip size checking */
#define ASM_F_SKIP_RESERVE_CHECKING     (3)     /* skip reserve checking (only for framework internal now) */
#define ASM_F_PLUTO_LAUNCHER            (4)

#define ASM_F_PREPARE_CANCELLED         (5)
#define ASM_F_DO_SHRINK_BASE_CHECKING   (6)     /*do the shrink base size checking*/


#define ASMC_TRACE(id, str, ...)    MMI_TRACE(MMI_FW_TRC_G1_FRM, id, __VA_ARGS__)
#define ASMC_STR_TRACE(mod, group, ...)  MMI_PRINT(mod, group, __VA_ARGS__)


#undef IS_BIT_SET
#define IS_BIT_SET(_data, _bit)   \
            ((((_data) >> (_bit)) & 0x01) == 0x01)

#undef SET_BIT
#define SET_BIT(_data_ptr, _bit, _val)  do {\
            if (_val)                       \
                *(_data_ptr) |= (1 << (_bit));  \
            else                            \
                *(_data_ptr) &= ~(1 << (_bit)); \
            } while(0)

#undef CHANGE_STATE
#define CHANGE_STATE(_new_state, _data)     prepare_change_state(_new_state, _data, __LINE__)

#undef DEFAULT_FAIL_LIST_SIZE
#define DEFAULT_FAIL_LIST_SIZE  (3)

#ifdef __32_32_SEG__
#define ASMC_ASSERT   MMI_ASSERT
#define ASMC_ASSERT_EXT MMI_EXT_ASSERT
#else
#define ASMC_ASSERT(_x)     do {    \
                                if (!(_x))  \
                                {   \
                                    HistoryDump();  \
                                }   \
                                MMI_ASSERT(_x);  \
                            }while(0)

#define ASMC_ASSERT_EXT(_x,e1,e2,e3)     do {    \
                                if (!(_x))  \
                                {   \
                                    HistoryDump();  \
                                }   \
                                MMI_EXT_ASSERT(_x,e1,e2,e3);  \
                            }while(0)
#endif

#define PREPARE_REQ_MAX_SIZE ((U32)0xFFFFFFFF)
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct {
    asm_core_state_enum current_state;
    asm_core_state_enum new_state;
} asm_core_state_check_struct;

/* prepare queue */
typedef struct _mmi_frm_asm_prepare_queue_struct{
    mmi_id app_id;
    U16 f_is_doing_prepare  : 1;
    mmi_proc_func callback;
    void *user_data;
    U32 required_size;                  /*total required size ( = non-continuous part + continuous part)*/
    U32 required_subsize_continuous; /*the sub size of continuous part, useful for MMv2 case*/
    mmi_frm_asm_prepare_flag_type flag;
    struct _mmi_frm_asm_prepare_queue_struct *next;
} mmi_frm_asm_prepare_queue_struct;

typedef struct {
    /* app's ID which OOM is serving for */
    mmi_id requester_id;
    /* require full pool or not */
    U32 require_full_pool : 1;
    U32 force_to_prepare : 1;
    /* required ASM size */
    U32 required_size;  /*total required size ( = non-continuous part + continuous part)*/
    U32 required_subsize_continuous; /*the sub size of continuous part, useful for MMv2 case*/
    /* Application success callback, when memory is enough */
    mmi_frm_appmem_success_cb success_callback;
    /* When ASM manager is canceled, call application cancel callback */
    mmi_frm_appmem_cb cancel_callback;       
} asm_core_requester_info_struct;

typedef struct {
    /* group ID for anonymous access */
    mmi_id anonymous_gid;
    mmi_id asm_dummy_gid;
    mmi_id asm_dummy_gid2;
    /* enable or disable auto-prompt */
    MMI_BOOL auto_prompt_screen;
    /* prepare queue */
    mmi_frm_asm_prepare_queue_struct *prepare_queue_head;
    mmi_frm_asm_prepare_queue_struct *prepare_queue_tail;
    mmi_frm_asm_prepare_queue_struct prepare_queue_pool[MMI_FRM_ASM_PREPARE_QUEUE_SIZE];
    /* oom requester info */
    asm_core_requester_info_struct req_info;
    mmi_id requester_bind_id; /*the app that related to requester and need to filter in release memory process*/
    asm_core_state_enum current_state;

    //asm_core_state_enum prepare_state;
    asm_core_wait_type_enum wait_type;

    asm_init_stage_enum init_stage;

    app_close_state_enum close_app_state;
    MMI_BOOL is_backward_prepare;
    MMI_BOOL is_unhide_prepare;
	MMI_BOOL is_set_active_prepare;
	MMI_BOOL is_active_idleapp_in_endkey;

	MMI_ID set_active_group_id;
} mmi_frm_asm_core_ctx_struct;;

typedef struct {
    mmi_id requester_id;
    U32 f_force_to_prepare : 1;
    U32 f_hierarchy_asm_compatible : 1;
    U32 f_unhidden_enlarge_heap : 1;
} asm_core_state_begin_struct;

typedef struct {
    asm_core_wait_type_enum wait_type;
    mmi_id id_to_stop;
    MMI_BOOL stopped;           /* stopped or not, only valid if wait_type != none */
} asm_core_state_free_struct;

typedef struct {
    asm_core_wait_type_enum type;
} asm_core_state_wait_struct;

typedef struct {
    mmi_frm_asm_cancel_reason_enum reason;
} asm_core_state_cancel_struct;


typedef struct {
    MMI_EVT_PARAM_HEADER
    mmi_id requester_id;
    U32 f_force_to_prepare : 1;
} asm_post_prepare_evt_struct;


typedef union {
        asm_core_state_begin_struct begin;
        asm_core_state_free_struct free;
        asm_core_state_wait_struct wait;
        asm_core_state_cancel_struct cancel;
} asm_core_state_data_struct;

typedef void (*asm_core_state_action_fptr)(mmi_id requester, asm_core_state_data_struct *data);

typedef struct {
    MMI_EVT_PARAM_HEADER
    MMI_ID_TYPE app_id;
    MMI_ID_TYPE app_icon;
    U32 required_size;
    void (*success_callback)(void);
} asm_core_v10_post_release_evt_struct;

#if defined __MMI_USE_MMV2__
typedef struct {
    mmi_frm_asm_change_heap_size_para para;
    U32 curr_heap_size;
} asm_slmm_heap_change_size_cb_data;
#endif
/*****************************************************************************              
 * function prototype                                                                   
 *****************************************************************************/
static U32 get_current_usage(mmi_id root_id);
static U32 get_remaining_quota(mmi_id root_id);
static MMI_BOOL prepare_check_state(asm_core_state_enum new_state);
static asm_core_state_enum prepare_get_state(void);
static void prepare_change_state(asm_core_state_enum new_state, asm_core_state_data_struct *data, U32 line);
static mmi_ret do_prepare_ucm_cb_hdlr(mmi_event_struct *evt);
static mmi_ret asm_core_proc(mmi_event_struct *evt);
#if defined __MMI_USE_MMV2__
static mmi_ret asm_change_heap_size_proc(mmi_event_struct *evt);
#endif /*__MMI_USE_MMV2__*/

static void do_prepare_none(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_begin(mmi_id old_requester, asm_core_state_data_struct *data);
static void do_prepare_free_volunteers(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_free_in_used(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_free_selected(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_wait(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_cancel(mmi_id requester_id, asm_core_state_data_struct *data);
static void do_prepare_success(mmi_id requester_id, asm_core_state_data_struct *data);

static void mmi_frm_asm_after_inactive(mmi_id app_id);
static void mmi_frm_asm_after_deinit(mmi_id app_id, asm_data_struct *p_data);
static void mmi_frm_asm_after_create(mmi_id app_id, asm_data_struct *p_data);
static void mmi_frm_asm_before_close(mmi_id app_id, base_node_struct *node, MMI_BOOL is_to_idle);
static void mmi_frm_asm_close_fail(mmi_id app_id, base_node_struct *node);
static mmi_ret mmi_frm_asm_set_active_app(MMI_ID id);
static mmi_ret post_prepare(asm_post_prepare_evt_struct *evt);

extern kal_uint32 applib_mem_ap_get_single_usage(kal_uint32 app_id);

extern void prepare_queue_put(U32 app_id, U32 req_continue_size, U32 req_noncontinue_size, mmi_proc_func cb, void *data, mmi_frm_asm_prepare_flag_type flag);
extern mmi_frm_asm_prepare_queue_struct *prepare_queue_get(mmi_id app_id);
extern void prepare_queue_free(mmi_frm_asm_prepare_queue_struct *ptr);

#ifdef __MMI_FRM_ASM_OOM_SCREEN__
static MMI_BOOL asm_core_process_reentry(asm_core_state_enum new_state, mmi_event_struct *evt, mmi_proc_func proc_to_run, void* user_data);
#endif
static void asm_core_v10_release_mem(applib_mem_ap_stop_type type);
static void asm_core_v10_wait_start(applib_mem_ap_stop_type type);
static void asm_core_v10_wait_end(void);
static U32 get_anonymous_quota(void);
static MMI_BOOL check_enough_by_ID (mmi_id id, U32 total_size, U32 continuous_subsize);
static void mmi_frm_appmem_prompt_to_release_mem_int(
        MMI_ID_TYPE app_id, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        U32 required_subsize_continuous,
        void (*success_callback)(void));
static void mmi_frm_appmem_default_group_success_callback(mmi_id app_id, U32 required_size);
static MMI_BOOL mmi_frm_asmi_invoke_success_callback_internal(mmi_scenario_id scen_id, void *arg);
#if defined(__MMI_UCM_SLIM__) && defined(__COSMOS_MMI_PACKAGE__)
static mmi_scenario_id mmi_frm_asm_is_call_exist_get_priority(mmi_scenario_id before);
#define AMS_DEFAULT_SCENARIO_ID(ID) mmi_frm_asm_is_call_exist_get_priority(ID)
#else
#define AMS_DEFAULT_SCENARIO_ID(ID) ID
#endif /* __MMI_UCM_SLIM__ && __COSMOS_MMI_PACKAGE__ */
/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

static mmi_frm_asm_core_ctx_struct g_asm_core_ctx = {0};
#ifdef __MMI_FRM_ASM_CORE_MUTEX__
static mmi_frm_recursive_mutex_struct  asm_core_rmutex;
#endif


static const scenario_tree_type_enum g_scenario_types[] = {GROUP_TREE, GROUP_BG_TREE, GROUP_DANGLE_TREE};

static const asm_core_state_action_fptr do_prepare_state_action[ASM_CORE_STATE_END_OF_ENUM] = {
    do_prepare_none,
    do_prepare_begin, 
    do_prepare_free_volunteers,
    do_prepare_free_in_used,
    do_prepare_free_selected,
    do_prepare_wait,
    do_prepare_cancel,
    do_prepare_success
};


#ifndef __MTK_TARGET__
const static asm_core_state_check_struct state_check_table[] = {
    {ASM_CORE_STATE_NONE, ASM_CORE_STATE_BEGIN},
    {ASM_CORE_STATE_BEGIN, ASM_CORE_STATE_FREE_VOLUNTEERS},
    {ASM_CORE_STATE_BEGIN, ASM_CORE_STATE_CANCEL},
    {ASM_CORE_STATE_BEGIN, ASM_CORE_STATE_SUCCESS},
    {ASM_CORE_STATE_BEGIN, ASM_CORE_STATE_NONE},
    {ASM_CORE_STATE_FREE_VOLUNTEERS, ASM_CORE_STATE_FREE_IN_USED},
    {ASM_CORE_STATE_FREE_VOLUNTEERS, ASM_CORE_STATE_FREE_SELECTED},
    {ASM_CORE_STATE_FREE_VOLUNTEERS, ASM_CORE_STATE_WAIT},
    {ASM_CORE_STATE_FREE_VOLUNTEERS, ASM_CORE_STATE_SUCCESS},
    {ASM_CORE_STATE_FREE_VOLUNTEERS, ASM_CORE_STATE_CANCEL},
    {ASM_CORE_STATE_FREE_IN_USED, ASM_CORE_STATE_FREE_SELECTED},
    {ASM_CORE_STATE_FREE_IN_USED, ASM_CORE_STATE_WAIT},
    {ASM_CORE_STATE_FREE_IN_USED, ASM_CORE_STATE_CANCEL},
    {ASM_CORE_STATE_FREE_IN_USED, ASM_CORE_STATE_SUCCESS},
    {ASM_CORE_STATE_FREE_SELECTED, ASM_CORE_STATE_WAIT},
    {ASM_CORE_STATE_FREE_SELECTED, ASM_CORE_STATE_CANCEL},
    {ASM_CORE_STATE_FREE_SELECTED, ASM_CORE_STATE_WAIT},
    {ASM_CORE_STATE_FREE_SELECTED, ASM_CORE_STATE_SUCCESS},
    {ASM_CORE_STATE_WAIT, ASM_CORE_STATE_FREE_VOLUNTEERS},
    {ASM_CORE_STATE_WAIT, ASM_CORE_STATE_FREE_IN_USED},
    {ASM_CORE_STATE_WAIT, ASM_CORE_STATE_FREE_SELECTED},
    {ASM_CORE_STATE_CANCEL, ASM_CORE_STATE_NONE},
    {ASM_CORE_STATE_SUCCESS, ASM_CORE_STATE_NONE},
};
#endif

#ifdef APPLIB_MEM_UNIT_TEST
MMI_BOOL test_single_action_only = MMI_FALSE;
#endif

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/
#if defined(__MMI_USE_MMV2__)
static kal_bool asm_get_usage_check_callback(kal_uint16 app_id)
{
    asm_data_struct* p_data;
	p_data = mmi_frm_group_get_asm_data_ptr(app_id);
	if (p_data && (mmi_res_get_app_global_size(app_id) >= p_data->usage))
	{
		return KAL_TRUE;
	}
	return KAL_FALSE;
}
#endif

static U32 mmi_frm_asm_get_asm_usage_ex(MMI_ID requester_id, MMI_ID bind_id, applib_mem_ap_usage_struct *applist, MMI_BOOL inc_hide, MMI_BOOL skip_v10)
{
	 U32 count = 0; 
	 MMI_ID skip_list[2];	 
	 skip_list[0] = requester_id;
	 skip_list[1] = bind_id;	
	 count = applib_mem_ap_get_current_usage_ex(
		 applist,
		 MMI_FRM_APPMEM_MAX_APP_PROMPTED,
		 inc_hide,
		 skip_v10, 
		 skip_list,
		 sizeof(skip_list) / sizeof(skip_list[0]), 
 #ifdef __MMI_USE_MMV2__
		 asm_get_usage_check_callback);
 #else
		 NULL);  
 #endif
     return count;
}

static MMI_BOOL is_in_fg(mmi_id root_id)
{
    MMI_BOOL ret1 = mmi_frm_group_is_in_active_serial(root_id);
    MMI_BOOL ret2 = mmi_frm_group_is_in_dangle(root_id);
    MMI_BOOL ret3 = (mmi_frm_group_get_active_id() == root_id) ? MMI_TRUE: MMI_FALSE;
    MMI_BOOL ret4 = MMI_FALSE;
	if (g_asm_core_ctx.is_backward_prepare &&
        root_id == mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT,g_asm_core_ctx.asm_dummy_gid, MMI_FRM_NODE_BEFORE_FLAG))
    {
       ret4 = MMI_TRUE;
    }
	if (g_asm_core_ctx.is_unhide_prepare)
	{
		mmi_group_node_struct node;
		mmi_frm_group_get_info(root_id, &node);
		if (node.parent == GRP_ID_BK)
		{
			ret4 = MMI_TRUE;
		}
	}

	if (g_asm_core_ctx.is_set_active_prepare)
	{
		if (g_asm_core_ctx.set_active_group_id == root_id)
		{
			ret4 = MMI_TRUE;
		}
	}
    return (ret1 || ret2 || ret3 || ret4) ? MMI_TRUE : MMI_FALSE;    
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_get_reserve_size
 * DESCRIPTION
 *  get total reserve size.
 * PARAMETERS
 *  b_output_log:   [IN]    output trace log or not
 * RETURNS
 *  total reserve size
 *****************************************************************************/
void mmi_frm_asm_get_reserve_size(U32* total_reserve, U32* global_reserve )
{
    group_node_struct **node_table;
    U32 i, j;
    U32 reserve_size = 0, quota = 0, usage = 0, val = 0, table_size = 0;
    U16 id;
#if defined __MMI_USE_MMV2__ 
    U32 unlive_ap_global_size = mmi_res_get_asm_global_pool_size();
    U32 global_reserve_size = 0;
#endif
    for (i=0; i<sizeof(g_scenario_types)/sizeof(scenario_tree_type_enum); i++)
    {
        table_size = mmi_frm_group_query_app_num(g_scenario_types[i]);
        if (table_size > 0)
        {
            node_table = (group_node_struct **)mmi_malloc(table_size*sizeof(group_node_struct *));
            if (mmi_frm_group_query_app_list(g_scenario_types[i], node_table, table_size) == MMI_RET_OK)
            {
                for (j=0; j<table_size; j++)
                {
                    if (IS_BIT_SET(node_table[j]->asm_data.flag, ASM_F_PREPARE_W_RESERVE))
                    {
                    #ifdef __MMI_USE_MMV2__
                        mmi_app_mem_info_struct mem_info;
                    #endif
                        id = node_table[j]->id;
                        #if defined __MMI_USE_MMV2__ 
                        mmi_res_get_app_mem_info (id, &mem_info);
                        //mmi_res_get_app_mem_info (id, &base_qta, NULL, &fg_qta, &global_qta);
                        quota = is_in_fg(id) ? mem_info.base_size + mem_info.fg_size : mem_info.base_size;
                        quota -= applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(id);
                        #else
                        //mmi_res_get_app_mem_size (id, base_qta, NULL, fg_qta, NULL);
                        //quota = is_in_fg(id) ? base_qta : base_qta + fg_qta;
                        quota = mmi_res_get_app_base_mem_size(id);
                        if (is_in_fg(id))
                        {
                            quota += mmi_res_get_app_fg_mem_size(id);
                        }
                        #endif
                        // minus the shrunk size
                        if (IS_BIT_SET(node_table[j]->asm_data.flag, ASM_F_DO_SHRINK_BASE_CHECKING))
                        {
                            quota -= node_table[j]->asm_data.shrunk_base;
                        }
                        usage = node_table[j]->asm_data.usage;
                        if (usage < quota)
                        {
                            val = quota - usage;
                            reserve_size += val;
                        }
                        #if defined __MMI_USE_MMV2__ 
                        unlive_ap_global_size -= mem_info.heap_global_size; /*unlive_ap_global_size = total global - each live ap global quota*/
                        if (usage != 0)
                            {
                            /*currently global_quota is for heap, it should be allocated at one time supposely */
                            /*so usage should >= global_qta , or be 0*/
                            ASMC_ASSERT(usage >= mem_info.heap_global_size);   /*Yehudi : for debug*/
                            }
                        if (usage < mem_info.heap_global_size )
                        {
                            global_reserve_size += mem_info.heap_global_size - usage ;
                            reserve_size -= mem_info.heap_global_size - usage ;
                        }
                        #endif
                    }
                }
            }
            mmi_mfree(node_table);
        }
    }
    reserve_size +=  get_anonymous_quota(); 
#if defined __MMI_USE_MMV2__         
    if (total_reserve)
        *total_reserve = reserve_size + unlive_ap_global_size + global_reserve_size;
    if (global_reserve)
        *global_reserve = unlive_ap_global_size + global_reserve_size;   
#else
    if (total_reserve)
        *total_reserve = reserve_size;
#endif
    return;
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asmi_invoke_cancel_callback
 * DESCRIPTION
 *  asm internal api to invoke cancel callback.
 * PARAMETERS
 *  app_id:     [IN]    app id
 *  type:       [IN]   cancel type
 * RETURNS
 *  true: cancel callback exists, false: no cancel callback registered
 *****************************************************************************/
MMI_BOOL mmi_frm_asmi_invoke_cancel_callback(mmi_id app_id, mmi_frm_appmem_event_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_evt_struct cancel_info;
    mmi_frm_appmem_cb cancel_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_nmgr_cancel_deferred_scenario(
        AMS_DEFAULT_SCENARIO_ID(MMI_SCENARIO_ID_DEFAULT),
        mmi_frm_asmi_invoke_success_callback_internal,
        NULL);
    if (g_asm_core_ctx.current_state == ASM_CORE_STATE_V10)
    {
        asm_core_v10_wait_end();
        mmi_frm_scrn_close(GRP_ID_ROOT, SCR_APPMEM_DUMMY);
        mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
        g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
    }
    if (g_asm_core_ctx.req_info.cancel_callback)
    {
        ASMC_TRACE(MMI_FRM_ASM_EXECUTE_CANCEL_CALLBACK, "", type);
        ASMC_ASSERT(app_id == g_asm_core_ctx.req_info.requester_id);

        cancel_callback = g_asm_core_ctx.req_info.cancel_callback;
        g_asm_core_ctx.req_info.cancel_callback = NULL;

        cancel_info.evt_type = type;
        cancel_info.app_id = g_asm_core_ctx.req_info.requester_id;
        cancel_callback((void *)&cancel_info);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

static MMI_BOOL mmi_frm_asmi_invoke_success_callback_internal(mmi_scenario_id scen_id, void *arg)
{
    ASMC_TRACE(MMI_FRM_ASM_INVOKE_SUCCESS_CB, "",
        g_asm_core_ctx.req_info.requester_id,
        g_asm_core_ctx.req_info.success_callback);
    /* Enter new app in success callback, when the new app group is inactive, just goback to previous group */
    MMI_ASSERT(g_asm_core_ctx.req_info.success_callback);
    g_asm_core_ctx.req_info.success_callback(g_asm_core_ctx.req_info.requester_id, g_asm_core_ctx.req_info.required_size);

    if (g_asm_core_ctx.req_info.success_callback != mmi_frm_appmem_default_group_success_callback)
    {
        if (g_asm_core_ctx.asm_dummy_gid != GRP_ID_INVALID)
        {
            mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
            g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
            g_asm_core_ctx.asm_dummy_gid = GRP_ID_INVALID;
        }
    }
    return MMI_TRUE;
}

/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asmi_invoke_success_callback
 * DESCRIPTION
 *  asm internal api to invoke success callback.
 * PARAMETERS
 *  app_id:     [IN]    app id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_asmi_invoke_success_callback(mmi_id app_id)
{
    ASMC_ASSERT(app_id == g_asm_core_ctx.req_info.requester_id);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGH_SCRN);
    mmi_frm_nmgr_notify_by_app(
	      AMS_DEFAULT_SCENARIO_ID(MMI_SCENARIO_ID_DEFAULT),
        MMI_EVENT_LAUNCH_APP,
        mmi_frm_asmi_invoke_success_callback_internal, 
        NULL);
    if (g_asm_core_ctx.current_state == ASM_CORE_STATE_V10)
    {
        g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asmi_check_enough_memory
 * DESCRIPTION
 *  Check if the free memory is enough
 * PARAMETERS
 *  app_id:     [IN] app id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_asmi_check_enough_memory(mmi_id app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    MMI_ID app_mgr_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    if (mmi_frm_asm_manager_is_launched(&app_mgr_id))
    {
        mmi_frm_display_dummy_screen_ex(app_mgr_id, SCR_ID_DUMMY);
    }
#endif
    ASMC_ASSERT(app_id == g_asm_core_ctx.req_info.requester_id);
    if ((g_asm_core_ctx.req_info.require_full_pool && (applib_mem_ap_get_alloc_count() == 0)) ||
        (!g_asm_core_ctx.req_info.require_full_pool && 
                 check_enough_by_ID(app_id, g_asm_core_ctx.req_info.required_size, g_asm_core_ctx.req_info.required_subsize_continuous)))
    {
        return MMI_TRUE;
    }
#ifdef __COSMOS_MMI_PACKAGE__
    if (mmi_frm_asm_manager_is_launched(&app_mgr_id))
    {
        mmi_frm_scrn_close(app_mgr_id, SCR_ID_DUMMY);
    }
#endif
    return MMI_FALSE;
}


MMI_BOOL mmi_frm_is_app_hide_in_oom(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID root_gid;
    mmi_frm_asm_property_struct property;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (applib_mem_ap_is_hide(app_id))
	{
		MMI_TRACE(MMI_FW_TRC_G1_FRM, 
			TRC_MMI_FRM_APP_HIDDEN_IN_OOM, 
			app_id);
		return MMI_TRUE;
	}

	root_gid = mmi_frm_get_root_app(app_id);    
    if (mmi_frm_asm_get_property(root_gid, &property))
    {
        if (property.f_hide_in_oom == 1)
        {
			MMI_TRACE(MMI_FW_TRC_G1_FRM, 
				TRC_MMI_FRM_APP_HIDDEN_IN_OOM, 
				app_id);
            return MMI_TRUE;
        }       
    }

    return MMI_FALSE;
}


/***************************************************************************** 
 * FUNCTION
 *  notify_mgr
 * DESCRIPTION
 *  interface to OOM Mgr app.
 * PARAMETERS
 *  evt:             [IN]   pointer to event
 *  direct_send:     [IN]   send (true) or post (false)
 * RETURNS
 *  void
 *****************************************************************************/
static void notify_mgr(mmi_event_struct *evt, MMI_BOOL direct_send)
{
    mmi_id mgr_id;
    if (mmi_frm_asm_manager_is_launched(&mgr_id))
    {
        mmi_group_node_struct node_info;
        mmi_frm_group_get_info(mgr_id, &node_info);
        if (direct_send)
        {
            MMI_FRM_SEND_EVENT(evt, node_info.proc, node_info.user_data);
        }
        else
        {
            MMI_FRM_POST_EVENT(evt, node_info.proc, node_info.user_data);
        }
    }
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_appmem_stop_finished_handler
 * DESCRIPTION
 *  stop finished handler. notify OOM Mgr that app has finished stop action.
 * PARAMETERS
 *  app_id:             [IN]   app id
 *  string_id:          [IN]   app name
 *  result:             [IN]   result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_finished_handler(kal_uint32 app_id, kal_uint32 string_id, kal_bool result)
{
    asm_core_state_data_struct data = {0};

    data.free.wait_type     = g_asm_core_ctx.wait_type;
    data.free.id_to_stop    = app_id;
    data.free.stopped       = result;

    ASMC_TRACE(MMI_FRM_ASM_STOP_FINISHED_HDLR, "[ASM][core] stop_finished_handler: app_id=%d, wait_type=%d, stopped=%d\n", app_id, data.free.wait_type, data.free.stopped);
    switch(g_asm_core_ctx.wait_type)
    {

    case ASM_CORE_WAIT_VOLUNTEER:
        CHANGE_STATE(ASM_CORE_STATE_FREE_VOLUNTEERS, &data);
        break;

    case ASM_CORE_WAIT_IN_USED:
        CHANGE_STATE(ASM_CORE_STATE_FREE_IN_USED, &data);
        break;

    case ASM_CORE_WAIT_V10:
        /* continue v10 release mem process */
        asm_core_v10_release_mem(MEM_AP_STOP_TYPE_REQ);
        break;
	case ASM_CORE_WAIT_V10_FORCE_FREE:
		asm_core_v10_release_mem(MEM_AP_STOP_TYPE_FORCE);
		break;
    case ASM_CORE_WAIT_SYNC_FREE : 
        break;
	
	case ASM_CORE_WAIT_SELECTED:
		/* continue to run default case for cosmos asmmgr */
		CHANGE_STATE(ASM_CORE_STATE_FREE_SELECTED, &data);

    /* this is for pluto asmmgr */
    default:
        {
            /* post event, EVT_ID_ASMI_STOP_FINISHED, to OOM mgr to notify stop finished */
            mmi_frm_asmi_stop_finished_evt_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_ASMI_STOP_FINISHED);
            evt.app_id  = (mmi_id)app_id;
            evt.str_id  = (U32)string_id;
            evt.result  = (MMI_BOOL)result;
            notify_mgr((mmi_event_struct *)&evt, MMI_FALSE);
        }
        break;
    }
}


/***************************************************************************** 
 * FUNCTION
 *  get_callback_info
 * DESCRIPTION
 *  get callback info from group node.
 * PARAMETERS
 *  app_id:             [IN]    application id
 *  cb_ptr:             [OUT]   pointer to callback
 *  user_data_ptr:      [OUT]   pointer to user data
 * RETURNS
 *  void
 *****************************************************************************/
static void get_callback_info(mmi_id app_id, void **cb_ptr, void **user_data_ptr)
{
    mmi_group_node_struct group_node;

    if (mmi_frm_group_get_info(app_id, &group_node) == MMI_RET_OK)
    {
        *cb_ptr         = (void *)group_node.proc;
        *user_data_ptr  = group_node.user_data;
    }
    else
    {
        ASMC_TRACE(MMI_FRM_ASM_ERROR_NO_GROUP_INFO, "", app_id);
    }
}

/***************************************************************************** 
 * FUNCTION
 *  group_invoke_cancel_callback
 * DESCRIPTION
 *  operation is cancelled, invoke cancel callback.
 * PARAMETERS
 *  app_id:         [IN]    app id
 *  callback:       [IN]    callback proc
 *  user_data:      [IN]    callback user data
 *  reason:         [IN]    cancel reason
 * RETURNS
 *  void
 *****************************************************************************/
static void group_invoke_cancel_callback(mmi_id app_id, mmi_proc_func callback, void *user_data, mmi_frm_asm_cancel_reason_enum reason)
{
    if (callback == NULL)
    {
        get_callback_info(app_id, (void **)&callback, &user_data);
    }
    
    /* send event to notify mem. is enough to use */
    if (callback)
    {
        mmi_frm_asm_cancel_evt_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_ASM_CANCELED);
        evt.app_id          = app_id;
        evt.cancel_reason   = reason;
        MMI_FRM_SEND_EVENT(&evt, callback, user_data);
    }           
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_appmem_default_cancel_callback
 * DESCRIPTION
 *  default cancel callback for screen group APs.
 *  it sends EVT_ID_MEM_CANCELED event to AP's screen group proc.
 * PARAMETERS
 *  mem_evt:              [IN]    event that contains app_id and cancel reason
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_default_cancel_callback(mmi_frm_appmem_evt_struct *mem_evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    asm_core_state_data_struct data = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.cancel.reason = (mmi_frm_asm_cancel_reason_enum)mem_evt->evt_type;
    CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
}


static MMI_BOOL mmi_frm_appmem_pre_allocation_handler(U16 app_id, U32 mem_size, U32 continuous_subsize)
{
    return check_enough_by_ID(app_id, mem_size, continuous_subsize) == MMI_FALSE? MMI_TRUE: MMI_FALSE;
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_appmem_default_group_stop_callback
 * DESCRIPTION
 *  default stop callback for screen group APs.
 * PARAMETERS
 *  app_id:              [IN]    application id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_default_group_stop_callback(U16 app_id, applib_mem_ap_stop_type stop_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id root_gid;
    mmi_frm_asm_evt_enum evt_id;
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (stop_type)
    {
    case MEM_AP_STOP_TYPE_REQ:
        evt_id = EVT_ID_ASM_FREE_REQ;
        break;
    case MEM_AP_STOP_TYPE_NO_WAIT:
        evt_id = EVT_ID_ASM_FREE_REQ_NO_WAIT;
        break;
    case MEM_AP_STOP_TYPE_FORCE:
    default:
        evt_id = EVT_ID_ASM_FORCE_FREE;
        break;
    }

    root_gid = mmi_frm_get_root_app((mmi_id)app_id);

    /* post event to root group ID */
    if (root_gid != GRP_ID_INVALID)
    {
        mmi_frm_appmem_asm_evt_struct evt;

        MMI_FRM_INIT_EVENT(&evt, evt_id);  /* post to root gid to free memory */
        evt.app_id = root_gid;
        result = mmi_frm_send_event_to_group(root_gid, (mmi_group_event_struct *)&evt);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_FREE_REQUEST, root_gid, evt_id, result);
        ASMC_ASSERT_EXT( !((stop_type == EVT_ID_ASM_FREE_REQ_NO_WAIT) && (result == MMI_FRM_ASM_WAITING_TO_FREE)),
                         (U32)root_gid, (U32)&evt, (U32)result);
        if (result != MMI_FRM_ASM_WAITING_TO_FREE)
        {
            if ((stop_type == MEM_AP_STOP_TYPE_REQ) || (stop_type == MEM_AP_STOP_TYPE_NO_WAIT))
            {
                result = MMI_FRM_ASM_FREE_FAIL; /* since ap may not handle free_req event, always treate as fail */
            }
        }

        switch (result)
        {
        case MMI_FRM_ASM_FREED:
        case MMI_FRM_ASM_FREE_FAIL:
            applib_mem_ap_notify_stop_finished(app_id, (result == MMI_FRM_ASM_FREED) ? MMI_TRUE : MMI_FALSE);
            break;

        case MMI_FRM_ASM_WAITING_TO_FREE:
            /* keep waiting, just return */
            break;
        default:
            ASMC_ASSERT(0);  /* incorrect result value */
        }
    }
    else
    {
        /* group not exists any more, just notify stop finished */
        applib_mem_ap_notify_stop_finished(app_id, MMI_TRUE);
    }
}


/***************************************************************************** 
 * FUNCTION
 *  group_invoke_success_callback
 * DESCRIPTION
 *  mem is enough, invoke success callback.
 * PARAMETERS
 *  app_id:         [IN]    app id
 *  callback:       [IN]    callback proc
 *  user_data:      [IN]    callback user data
 *  req_size:       [IN]    size required
 * RETURNS
 *  void
 *****************************************************************************/
static void group_invoke_success_callback(mmi_id app_id, mmi_proc_func callback, void *user_data, U32 req_size)
{
    if (callback == NULL)
    {
        get_callback_info(app_id, (void **)&callback, &user_data);
    }
    
    ASMC_TRACE(MMI_FRM_ASM_PREPARED, "", app_id, EVT_ID_ASM_PREPARED, req_size, user_data);

    /* send event to notify mem. is enough to use */

    if (callback)
    {
        mmi_frm_asm_prepare_evt_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_ASM_PREPARED);
        evt.app_id          = app_id;
        evt.required_size   = req_size;
        MMI_FRM_SEND_EVENT(&evt, callback, user_data);

        evt.evt_id = EVT_ID_ASM_POST_PREPARED;

        MMI_FRM_POST_EVENT(&evt, callback, user_data);
    }           
}


/***************************************************************************** 
 * FUNCTION
 *  invoke_prepare_queue_callback
 * DESCRIPTION
 *  invoke related success callbacks in prepare queue.
 * PARAMETERS
 *  root_id:         [IN]    app id
 * RETURNS
 *  void
 *****************************************************************************/
static void invoke_prepare_queue_callback(mmi_id root_id, asm_core_cb_type cb_type, U32 arg)
{
    mmi_frm_asm_prepare_queue_struct *q_ptr = NULL;
    root_id = mmi_frm_get_root_app(root_id);

    while ((q_ptr = prepare_queue_get(root_id)) != NULL)
    {
        mmi_proc_func callback  = q_ptr->callback;
        void * user_data        = q_ptr->user_data;
        U32 req_size            = q_ptr->required_size;
        mmi_id app_id           = q_ptr->app_id;

        prepare_queue_free(q_ptr);
        switch(cb_type)
        {
        case ASM_CORE_CB_SUCCESS:
            group_invoke_success_callback(app_id, callback, user_data, req_size);
            break;

        case ASM_CORE_CB_CANCEL:
            group_invoke_cancel_callback(app_id, callback, user_data, (mmi_frm_asm_cancel_reason_enum)arg);
            break;

        default:
            ASMC_ASSERT(0); /* wrong callback type */
            break;
        }
    }
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_appmem_default_group_success_callback
 * DESCRIPTION
 *  default success callback for screen group APs.
 *  it sends EVT_ID_MEM_IS_ENOUGH event to AP's screen group proc.
 * PARAMETERS
 *  app_id:              [IN]    application id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_default_group_success_callback(mmi_id app_id, U32 required_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHANGE_STATE(ASM_CORE_STATE_SUCCESS, NULL);
}


/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_appmem_auto_prompt_screen
 * DESCRIPTION
 *  this is a post function to trigger prompt screen asynchronously.
 * PARAMETERS
 *  evt:              [IN]    event that contains app_id and required mem. size
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_frm_appmem_auto_prompt_screen(mmi_frm_appmem_auto_prompt_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_prompt_not_exist = mmi_frm_asm_manager_is_launched(NULL) ? MMI_FALSE: MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASMC_TRACE(MMI_FRM_ASM_AUTO_PROMPT_SCREEN, "", is_prompt_not_exist, evt->app_id, evt->required_size);

    /* check to prevent from enter OOM again when AP already did it */
    if ((prepare_queue_get(evt->app_id)) != NULL)
    {
        if (evt->f_force_prompt || is_prompt_not_exist)
        {       
            /* prompt screen */
            mmi_frm_appmem_prompt_to_release_mem_int(evt->app_id, IMG_GLOBAL_SUCCESS, evt->required_size, evt->required_subsize_continuous,
                                                     (void (*)(void))mmi_frm_appmem_default_group_success_callback);
            mmi_frm_appmem_set_cancel_callback((applib_mem_ap_id_enum)evt->app_id, mmi_frm_appmem_default_cancel_callback);
        }
    }
    return MMI_RET_OK;
}


/***************************************************************************** 
 * FUNCTION
 *  queue_add
 * DESCRIPTION
 *  add to prepare queue.
 * PARAMETERS
 *  node:         [IN]    queue node
 * RETURNS
 *  void
 *****************************************************************************/
static void queue_add(mmi_frm_asm_prepare_queue_struct *node)
{
    if (g_asm_core_ctx.prepare_queue_head == NULL)
    {
        g_asm_core_ctx.prepare_queue_head = node;
    }
    else
    {
        g_asm_core_ctx.prepare_queue_tail->next = node;
    }

    g_asm_core_ctx.prepare_queue_tail = node;
    node->next = NULL;
}


/***************************************************************************** 
 * FUNCTION
 *  queue_remove
 * DESCRIPTION
 *  remove from prepare queue.
 * PARAMETERS
 *  node:         [IN]    queue node
 * RETURNS
 *  void
 *****************************************************************************/
static void queue_remove(mmi_frm_asm_prepare_queue_struct *node)
{
    mmi_frm_asm_prepare_queue_struct *i_node = g_asm_core_ctx.prepare_queue_head;
    mmi_frm_asm_prepare_queue_struct *prev_node = NULL;

    while (i_node)
    {
        if (i_node == node)
        {
            if (prev_node != NULL)
            {
                prev_node->next = i_node->next;
            }
            if (g_asm_core_ctx.prepare_queue_tail == node)
            {
                g_asm_core_ctx.prepare_queue_tail = prev_node;
            }

            if (g_asm_core_ctx.prepare_queue_head == node)
            {
                g_asm_core_ctx.prepare_queue_head = i_node->next;
            }
            break;
        }
        prev_node = i_node;
        i_node = i_node->next;
    }
}


/***************************************************************************** 
 * FUNCTION
 *  prepare_queue_put
 * DESCRIPTION
 *  get empty node, fill data, and add to prepare queue.
 * PARAMETERS
 *  app_id:         [IN]    app id
 *  total_size:         [IN]    the total request size (non-continuous + continuous)
 *  continuous_subsize: [IN]    only useful in MMv2 case, the continuous memory size part of request
 *  cb:             [IN]    prepare callback
 *  data:           [IN]    user data of prepare callback
 *  flag:           [IN]    prepare flag
 * RETURNS
 *  void
 *****************************************************************************/
static void prepare_queue_put(U32 app_id, U32 total_size, U32 continuous_subsize, mmi_proc_func cb, void *data, mmi_frm_asm_prepare_flag_type flag)
{
    mmi_frm_asm_prepare_queue_struct *node = NULL;
    U32 i;

    for (i=0; i<MMI_FRM_ASM_PREPARE_QUEUE_SIZE; i++)
    {
        if (g_asm_core_ctx.prepare_queue_pool[i].app_id == GRP_ID_INVALID)
        {
            node = &g_asm_core_ctx.prepare_queue_pool[i];
            break;
        }
    }
    ASMC_ASSERT(node);    /* should have enough prepare queue */

    /* add to queue */
    queue_add(node);
    node->app_id        = app_id;
    node->required_size = total_size;
    node->required_subsize_continuous = continuous_subsize;
    node->callback      = cb;
    node->user_data     = data;
    node->flag          = flag;
}


/***************************************************************************** 
 * FUNCTION
 *  prepare_queue_get
 * DESCRIPTION
 *  get first found prepare queue node for given root_id.
 * PARAMETERS
 *  root_id:         [IN]    app id
 * RETURNS
 *  node
 *****************************************************************************/
static mmi_frm_asm_prepare_queue_struct *prepare_queue_get(mmi_id root_id)
{
    mmi_frm_asm_prepare_queue_struct *node = g_asm_core_ctx.prepare_queue_head;
    root_id = mmi_frm_get_root_app(root_id);

    while (node)
    {
        if (mmi_frm_get_root_app(node->app_id) == root_id)
            break;
        node = node->next;
    }

    return node;
}


/***************************************************************************** 
 * FUNCTION
 *  prepare_queue_get_specific
 * DESCRIPTION
 *  get prepare queue node for given root_id, callback and user data.
 * PARAMETERS
 *  app_id:         [IN]    app id
 *  cb:             [IN]    prepare callback
 *  user_data:      [IN]    user data of prepare callback
 * RETURNS
 *  node
 *****************************************************************************/
static mmi_frm_asm_prepare_queue_struct *prepare_queue_get_specific(mmi_id app_id, mmi_proc_func cb, void *user_data)
{
    mmi_frm_asm_prepare_queue_struct *node = g_asm_core_ctx.prepare_queue_head;

    while (node)
    {
        if ((node->app_id == app_id) && (node->callback == cb) && (node->user_data == user_data))
            break;
        node = node->next;
    }

    return node;
}


/***************************************************************************** 
 * FUNCTION
 *  prepare_queue_free
 * DESCRIPTION
 *  free given prepare queue node.
 * PARAMETERS
 *  node:           [IN]    queue node
 * RETURNS
 *  void
 *****************************************************************************/
static void prepare_queue_free(mmi_frm_asm_prepare_queue_struct *node)
{
    node->app_id = GRP_ID_INVALID;
    queue_remove(node);
}


static U32 prepare_queue_get_total_size_int(mmi_id app_id, MMI_BOOL continuous_subsize)
{
    mmi_frm_asm_prepare_queue_struct *node = g_asm_core_ctx.prepare_queue_head;
    U32 total_size = 0;
    mmi_id root_id = mmi_frm_get_root_app(app_id);
	U32 size;

    while (node)
    {
        if (mmi_frm_get_root_app(node->app_id) == root_id)
        {
			size = (continuous_subsize == MMI_TRUE) ? node->required_subsize_continuous : node->required_size;
			if ( size == PREPARE_REQ_MAX_SIZE )
            {
                total_size = PREPARE_REQ_MAX_SIZE;
                break;
            }
            else
                total_size += size;
        }
        node = node->next;
    }
    return total_size;	
}


/***************************************************************************** 
 * FUNCTION
 *  get_current_usage
 * DESCRIPTION
 *  get app's current usage.
 * PARAMETERS
 *  root_id:             [IN]    app id
 * RETURNS
 *  app's current usage
 *****************************************************************************/
static U32 get_current_usage(mmi_id root_id)
{
    asm_data_struct *p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    if (p_data)
        return p_data->usage;
    else
        return 0;
}


/***************************************************************************** 
 * FUNCTION
 *  get_quota
 * DESCRIPTION
 *  get app's quota according to bg/fg status.
 * PARAMETERS
 *  root_id:             [IN]    app id
 * RETURNS
 *  app's quota
 *****************************************************************************/
U32 get_quota(mmi_id root_id)
{
    MMI_BOOL is_fg = is_in_fg(root_id);
    U32 quota = mmi_res_get_app_base_mem_size(root_id);
#if defined __MMI_USE_MMV2__
    U32 shrunk_heap_size = applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(root_id);
#endif
    asm_data_struct *p_data;
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    if (IS_BIT_SET(p_data->flag, ASM_F_DO_SHRINK_BASE_CHECKING))
    {
        ASMC_ASSERT(quota >= p_data->shrunk_base); 
        quota -= p_data->shrunk_base; /*base shrink size*/
    }
#if defined __MMI_USE_MMV2__
    ASMC_ASSERT(quota >= shrunk_heap_size); 
    quota -= shrunk_heap_size;
#endif
    if (is_fg)
        quota += mmi_res_get_app_fg_mem_size(root_id);

    return quota;
}


/***************************************************************************** 
 * FUNCTION
 *  get_remaining_quota
 * DESCRIPTION
 *  get app's remaining quota (= quota - current usage).
 * PARAMETERS
 *  root_id:             [IN]    app id
 * RETURNS
 *  app's remaining quota
 *****************************************************************************/
static U32 get_remaining_quota(mmi_id root_id)
{
    U32 quota = get_quota(root_id);
    U32 usage = get_current_usage(root_id);

    if (quota >= usage)
    {
        quota -= usage;
        return quota;
    }
    /* quota < usage */
    return 0;
}

static U32 get_prepare_size_int(mmi_id root_id, U32 required_size, MMI_BOOL is_continuous_subsize)
{
    U32 prepare_size = 0, app_usage, heap_size, app_total_size, continuous_remaining_quota;
#ifdef __MMI_USE_MMV2__
    U32  shrunk_heap_size;
#endif
    mmi_frm_asm_property_struct property;

    mmi_frm_asm_get_property(root_id, &property);

    app_usage = get_current_usage(root_id);
    app_total_size = get_quota(root_id);
	if (is_continuous_subsize == MMI_TRUE)
	{
    	heap_size = mmi_res_get_app_heap_size(root_id);
	#if defined __MMI_USE_MMV2__    
    	shrunk_heap_size = applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(root_id);
    	ASMC_ASSERT(heap_size >= shrunk_heap_size); 
    	heap_size -= shrunk_heap_size;
	#endif
    	/*here suppose app allocate heap firstly*/
    	continuous_remaining_quota = heap_size > app_usage ? app_total_size - heap_size : app_total_size - app_usage ; 
	}
	else
	{
		continuous_remaining_quota = app_total_size - app_usage;
	}
	
    if (required_size == PREPARE_REQ_MAX_SIZE)
    {
        // check mem. according to AP's status and usage
            prepare_size = continuous_remaining_quota;
    }
    else
    {
	    prepare_size = prepare_queue_get_total_size_int(root_id, is_continuous_subsize);
		prepare_size = (prepare_size == PREPARE_REQ_MAX_SIZE ? continuous_remaining_quota : prepare_size);
        if (!property.f_skip_size_checking && (prepare_size > continuous_remaining_quota))
        prepare_size = continuous_remaining_quota;
    }


	/* add extra overhead * alloc. counts for prepare_w_reserve */
	if (property.f_prepare_w_reserve && prepare_size > 0)
	{
		prepare_size = MMI_FRM_ASM_SIZE_PLUS_EXTRA(prepare_size);
	}

	return prepare_size;

}

static U32 get_prepare_size(mmi_id root_id, U32 required_size)
{
	return get_prepare_size_int(root_id, required_size, MMI_FALSE);
}


static U32 get_prepare_continuous_subsize(mmi_id root_id, U32 required_size)
{
	return get_prepare_size_int(root_id, required_size, MMI_TRUE);
}

static void do_prepare_begin(mmi_id old_requester, asm_core_state_data_struct *data)
{
    
    /* in prepqre queue, we use app_id, not root_id, since we will notify its proc when prepared w/ NULL cb */
    mmi_id requester_id;
    mmi_frm_asm_prepare_queue_struct *q_ptr = NULL;
    mmi_id root_id;
    U32 required_size, prepare_size, app_usage, app_total_size;
#if defined __MMI_USE_MMV2__
	U32 required_subsize_continuous;
#endif /*__MMI_USE_MMV2__*/
    mmi_frm_asm_property_struct property;

    ASMC_ASSERT(data);
    requester_id = data->begin.requester_id;

    if ((q_ptr = prepare_queue_get(requester_id)) == NULL)
    {
        /* prepare may be cancelled */
        CHANGE_STATE(ASM_CORE_STATE_NONE, NULL);
        return;
    }

    root_id = mmi_frm_get_root_app(requester_id);
    required_size   = q_ptr->required_size;
#if defined __MMI_USE_MMV2__
    required_subsize_continuous = q_ptr->required_subsize_continuous;
#endif /*__MMI_USE_MMV2__*/

    memset(&g_asm_core_ctx.req_info, 0, sizeof(g_asm_core_ctx.req_info));
    g_asm_core_ctx.req_info.requester_id    = requester_id;
    g_asm_core_ctx.req_info.required_size   = prepare_size = get_prepare_size(root_id, required_size);
#if defined __MMI_USE_MMV2__
    g_asm_core_ctx.req_info.required_subsize_continuous   = get_prepare_continuous_subsize(root_id, required_subsize_continuous);
#else
    g_asm_core_ctx.req_info.required_subsize_continuous   = prepare_size;
#endif
    g_asm_core_ctx.req_info.force_to_prepare = data->begin.f_force_to_prepare;

    /* check reserve property and do reserve if necessary */
    mmi_frm_asm_get_property(root_id, &property);


    if (!property.f_skip_size_checking)
    {
	    app_usage = get_current_usage(root_id);
	    app_total_size = get_quota(root_id);
        /* should have size configured in *.res file */
        /* actual usage should not exceed declared size */
        if (!app_total_size || (app_usage > app_total_size))
        {
            ASMC_ASSERT(0); 
            return;
        }
    }

    if (!check_enough_by_ID(root_id, prepare_size, g_asm_core_ctx.req_info.required_subsize_continuous))
    {
        /* only allow fg app to continue prepare process */
        if (!is_in_fg(root_id) && !data->begin.f_hierarchy_asm_compatible && !data->begin.f_unhidden_enlarge_heap)
        {
            CHANGE_STATE(ASM_CORE_STATE_NONE, NULL);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PREPARE_FAIL_FOR_INACTIVE_APP, prepare_size);
            ASMC_ASSERT(0); 
            return;
        }

        if (
        #if defined __MMI_USE_MMV2__
            1
        #else
            !applib_mem_ap_cache_free_till_enough_by_id(root_id, prepare_size)
        #endif
            )
        {
            //ASMC_TRACE(MMI_FRM_ASM_DO_PREPARE_POST_BEGIN, "", root_id, prepare_size, mmi_frm_asm_get_max_alloc_size_r(root_id));
            if ((g_asm_core_ctx.req_info.requester_id != GRP_ID_INVALID) && (g_asm_core_ctx.current_state == ASM_CORE_STATE_BEGIN))
            {
                asm_core_state_data_struct new_data = {0};
                /* handle interrupt events in proc */
                if (g_asm_core_ctx.is_backward_prepare == MMI_FALSE &&
					g_asm_core_ctx.is_unhide_prepare == MMI_FALSE &&
					g_asm_core_ctx.is_set_active_prepare == MMI_FALSE)
                {
                    g_asm_core_ctx.asm_dummy_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, asm_core_proc, (void *)'FAWD');
                    mmi_frm_group_enter(g_asm_core_ctx.asm_dummy_gid, MMI_FRM_NODE_NONE_FLAG);
                }
                mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
                mmi_frm_appmem_set_cancel_callback((applib_mem_ap_id_enum)g_asm_core_ctx.req_info.requester_id, mmi_frm_appmem_default_cancel_callback);
                
                /* memory is still not enough after free cache */
                new_data.free.wait_type = ASM_CORE_WAIT_NONE;
                CHANGE_STATE(ASM_CORE_STATE_FREE_VOLUNTEERS, &new_data);
            }
            return;
        }
    }
    CHANGE_STATE(ASM_CORE_STATE_SUCCESS, NULL);
    return;
}

static U32 do_prepare_free_volunteers_int(mmi_id requester_id, asm_core_state_data_struct *data)
{
    static U32 next_idx = 0;
    static U32 app_count = 0;
    asm_core_state_data_struct new_data = {0};
	static applib_mem_ap_usage_struct *applist = NULL;

	ASMC_ASSERT(data);

	if (applist == NULL)
	{
		applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * MMI_FRM_APPMEM_MAX_APP_PROMPTED);
		app_count = mmi_frm_asm_get_asm_usage(
			requester_id,
			applist,
			KAL_TRUE,
			KAL_TRUE);
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_FREE_VOLUNTEERS_COUNT, app_count);
	}

    /* back from waiting */
    if (data->free.wait_type != ASM_CORE_WAIT_NONE)
    {
        ASMC_ASSERT(data->free.wait_type == ASM_CORE_WAIT_VOLUNTEER);

        if (check_enough_by_ID(requester_id, g_asm_core_ctx.req_info.required_size, g_asm_core_ctx.req_info.required_subsize_continuous))
        {
            mmi_mfree(applist);
            applist = NULL;
            next_idx = 0;
            CHANGE_STATE(ASM_CORE_STATE_SUCCESS, NULL);   /* memory is enough */
            return 1;
        }
        next_idx++; /* memory still not enough, go for next volunteer */
    }

    /* free volunteer */
    
    /* ask app to free memory */
    if (next_idx < app_count)
    {
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_FREE_VOLUNTEERS_STOP_ID, next_idx, applist[next_idx]);

        new_data.wait.type = ASM_CORE_WAIT_VOLUNTEER;
        CHANGE_STATE(ASM_CORE_STATE_WAIT, &new_data);
        applib_mem_ap_stop_app_by_MMI_task(applist[next_idx].app_id, MEM_AP_STOP_TYPE_REQ);
        return 2;
    }

    /* no volunteer to free, go next state */
    if (applist)
    {
        mmi_mfree(applist);
        applist = NULL;
        next_idx = 0;
    }
    
    return 0;
}


static void do_prepare_free_volunteers(mmi_id requester_id, asm_core_state_data_struct *data)
{
    asm_core_state_data_struct new_data = {0};
	if (0 != do_prepare_free_volunteers_int(requester_id, data))
	{
	    return;
	}
    new_data.free.wait_type = ASM_CORE_WAIT_NONE;

#ifdef APPLIB_MEM_UNIT_TEST
    if (test_single_action_only == MMI_TRUE)
    {
        return;
    }
#endif
#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
    CHANGE_STATE(ASM_CORE_STATE_FREE_IN_USED, &new_data);
#else

#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if (g_asm_core_ctx.req_info.force_to_prepare)
        CHANGE_STATE(ASM_CORE_STATE_FREE_IN_USED, &new_data);
    else
        CHANGE_STATE(ASM_CORE_STATE_FREE_SELECTED, &new_data);
#else
    CHANGE_STATE(ASM_CORE_STATE_FREE_IN_USED, &new_data);
#endif
#endif
}
#if (defined(__MMI_USE_MMV2__)|| defined(APPLIB_MEM_UNIT_TEST))
static U32 do_free_volunteers_no_wait(mmi_id requester_id, mmi_id bind_id, U32 required_size, U32 required_subsize_continuous)
{
    applib_mem_ap_usage_struct *app_list = NULL;
    U32 next_idx = 0;
    U32 app_count = 0;
	U32 ret = 0;
    ASMC_ASSERT(g_asm_core_ctx.wait_type == ASM_CORE_WAIT_NONE);
    g_asm_core_ctx.wait_type = ASM_CORE_WAIT_SYNC_FREE;
	app_list = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * 10);
	app_count = mmi_frm_asm_get_asm_usage_ex(
		requester_id,
		bind_id,
		app_list,
		KAL_TRUE,
		KAL_TRUE);	
    /* ask app to free memory */
    while (next_idx < app_count)
    {
		 
        ASMC_TRACE(MMI_FRM_ASM_FREE_VOLUNTEERS, 
                    "[ASM][core] free_volunteers: IdToStop=%d\n",
                    app_list[next_idx]);
        applib_mem_ap_stop_app_by_MMI_task(app_list[next_idx].app_id, MEM_AP_STOP_TYPE_NO_WAIT);
        if (check_enough_by_ID(requester_id, required_size, required_subsize_continuous))
        {
            ret = 1;
            break;
        }
        next_idx++; /* memory still not enough, go for next volunteer */
    }
	mmi_mfree(app_list);
    g_asm_core_ctx.wait_type = ASM_CORE_WAIT_NONE;
    return ret;
}
#endif /* (defined(__MMI_USE_MMV2__)|| defined(APPLIB_MEM_UNIT_TEST))*/

static void do_prepare_free_in_used(mmi_id requester_id, asm_core_state_data_struct *data)
{
    asm_core_state_data_struct new_data = {0};

    applib_mem_ap_usage_struct *applist = NULL;
    U32 curr_idx = 0;
    U32 count = 0; 

    applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * MMI_FRM_APPMEM_MAX_APP_PROMPTED);
    count = mmi_frm_asm_get_asm_usage(
		requester_id,
		applist,
		KAL_FALSE,
		KAL_FALSE);	
  
    /* back from waiting */
    if (data->free.wait_type != ASM_CORE_WAIT_NONE)
    {
        ASMC_ASSERT(data->free.wait_type == ASM_CORE_WAIT_IN_USED);
        ASMC_ASSERT(data->free.id_to_stop != GRP_ID_INVALID);

        if (data->free.stopped)
        {
            /* successfully stopped */
            if (check_enough_by_ID(requester_id, g_asm_core_ctx.req_info.required_size, g_asm_core_ctx.req_info.required_subsize_continuous))
            {
                mmi_mfree(applist);
			#ifdef APPLIB_MEM_UNIT_TEST
    		    if (test_single_action_only == MMI_TRUE)
                {
                    return;
                }
            #endif	
                CHANGE_STATE(ASM_CORE_STATE_SUCCESS, NULL); /* memory is enough */
                return;
            }
        }
    }

    /* free in-used */
        

#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
	if (!g_asm_core_ctx.req_info.force_to_prepare) 
	{
		while(curr_idx < count)
		{
		    asm_data_struct *p_data = mmi_frm_group_get_asm_data_ptr(applist[curr_idx].app_id);	

			if(!p_data)
			    break;

			if(p_data->mem_prio == 0)
			    curr_idx++;
			else
			    break;
		}
	}
#endif

    if (curr_idx < count)
    {
        ASMC_TRACE(MMI_FRM_ASM_FREE_IN_USED, 
                "[ASM][core] free_in_used: IdToStop=%d\n",applist[curr_idx].app_id);

        new_data.wait.type = ASM_CORE_WAIT_IN_USED;
        CHANGE_STATE(ASM_CORE_STATE_WAIT, &new_data);
        applib_mem_ap_stop_app_by_MMI_task(applist[curr_idx].app_id, MEM_AP_STOP_TYPE_FORCE);
        mmi_mfree(applist);
        return;
    }

    mmi_mfree(applist);
    applist = NULL;

#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
	if (!g_asm_core_ctx.req_info.force_to_prepare) // if force_prepare (ex. backwarding), not enter free_selected state
	{
        new_data.free.wait_type = ASM_CORE_WAIT_NONE;
        CHANGE_STATE(ASM_CORE_STATE_FREE_SELECTED, &new_data);
		return;
	}
#endif
#ifdef APPLIB_MEM_UNIT_TEST
    if (test_single_action_only == MMI_TRUE)
    {
        return;
    }
#endif

    /* no more to free, print trace and assert */
	{
	    applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * MMI_FRM_APPMEM_MAX_APP_PROMPTED);
	    count = mmi_frm_asm_get_asm_usage(
			requester_id,
			applist,
			KAL_TRUE,
			KAL_FALSE);	
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_NO_MORE_FREE_ALL_COUNT, count);
		for(curr_idx = 0; curr_idx < count; curr_idx++)
		{			
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_NO_MORE_FREE_GID, 
				curr_idx, 
				applist[curr_idx].app_id, 
				applist[curr_idx].string_id);
		}
	    count = mmi_frm_asm_get_asm_usage(
			requester_id,
			applist,
			KAL_FALSE,
			KAL_FALSE);	
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_NO_MORE_FREE_NO_HIDDEN_COUNT, count);
		for(curr_idx = 0; curr_idx < count; curr_idx++)
		{			
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_NO_MORE_FREE_GID, 
				curr_idx, 
				applist[curr_idx].app_id, 
				applist[curr_idx].string_id);
		}
		mmi_mfree(applist);
	    ASMC_ASSERT(0);
	}
	return;
}

static void do_prepare_free_selected(mmi_id requester_id, asm_core_state_data_struct *data)
{
    mmi_frm_appmem_auto_prompt_evt_struct evt;
    
    /* back from waiting */
    if (data->free.wait_type != ASM_CORE_WAIT_NONE)
        return;

    MMI_FRM_INIT_EVENT(&evt, 0);
    evt.app_id          = requester_id;
    evt.required_size   = g_asm_core_ctx.req_info.required_size;
    evt.required_subsize_continuous   = g_asm_core_ctx.req_info.required_subsize_continuous;
    evt.f_force_prompt  = MMI_TRUE;
    MMI_FRM_POST_EVENT(&evt, mmi_frm_appmem_auto_prompt_screen, NULL);
}

static mmi_ret post_core_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case ASM_CONTINUE_TO_CLOSE:
        {
            mmi_frm_group_urgent_close(g_asm_core_ctx.asm_dummy_gid);
            g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
            g_asm_core_ctx.asm_dummy_gid = GRP_ID_INVALID;
            break;
        }
        
        case ASM_CONTINUE_TO_IDLE:
        {
            mmi_frm_group_urgent_close(g_asm_core_ctx.asm_dummy_gid);
            g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
            g_asm_core_ctx.asm_dummy_gid = GRP_ID_INVALID;
            break;
        }

        case ASM_BACKWARD_PREPARE:
        {
            asm_core_state_data_struct data = {0};
            data.begin.requester_id = (mmi_id)(0x0FFFF & ((U32)(evt->user_data)));
            data.begin.f_force_to_prepare = 1;
            prepare_queue_put(data.begin.requester_id, PREPARE_REQ_MAX_SIZE, PREPARE_REQ_MAX_SIZE, asm_core_proc, NULL, MMI_FRM_ASM_F_NONE);
            CHANGE_STATE(ASM_CORE_STATE_BEGIN, &data);
            break;
        }
    #if defined __MMI_USE_MMV2__
        case ASM_ENLARGE_HEAP:
        {
            mmi_frm_asm_change_heap_size_para*  para;
            U32 res_heap_size, curr_heap_size;
            mmi_id heap_owner_id ;
            asm_core_state_data_struct data = {0};

            para = &((asm_slmm_heap_change_size_cb_data*)evt->user_data)->para;
            heap_owner_id = mmi_frm_asm_get_slmm_owner_id(para->frm_asm_slmm_id);
            curr_heap_size = ((asm_slmm_heap_change_size_cb_data*)evt->user_data)->curr_heap_size;
            data.begin.requester_id = heap_owner_id;

            if (para->flag & FRM_ASM_HEAP_CHANGE_FORCE_PREPARE)
                data.begin.f_force_to_prepare = 1;
            else
                data.begin.f_force_to_prepare = 0;

            if (para->flag & FRM_ASM_HEAP_CHANGE_IN_UNHIDDEN)
                data.begin.f_unhidden_enlarge_heap = 1;
            else
                data.begin.f_unhidden_enlarge_heap = 0;

            if (para->flag & FRM_ASM_HEAP_CHANGE_IN_BACKWARD)
                g_asm_core_ctx.is_backward_prepare = MMI_TRUE;
            else
                g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
            g_asm_core_ctx.requester_bind_id = para->app_id;
            ASMC_ASSERT( para->heap_size >= curr_heap_size);
            /*set shrink size before prepare in order to get correct quota during preparation*/
            res_heap_size = mmi_res_get_app_heap_size(heap_owner_id);
            applib_mem_ap_slmm_set_shrunk_heap_size((applib_mem_slmm_id)para->frm_asm_slmm_id, res_heap_size - para->heap_size);
            prepare_queue_put(data.begin.requester_id, para->heap_size - curr_heap_size, 0 /*continuous size*/, 
                              asm_change_heap_size_proc, evt->user_data, MMI_FRM_ASM_F_NONE);
            CHANGE_STATE(ASM_CORE_STATE_BEGIN, &data);
            break;

        }
    #endif
		case ASM_UNHIDE_PREPARE:
		case ASM_SET_ACTIVE_PREPARE:
		{
			asm_core_state_data_struct data = {0};
			data.begin.requester_id = (mmi_id)(0x0FFFF & ((U32)(evt->user_data)));
            data.begin.f_force_to_prepare = 0;
            prepare_queue_put(data.begin.requester_id, PREPARE_REQ_MAX_SIZE, PREPARE_REQ_MAX_SIZE, asm_core_proc, NULL, MMI_FRM_ASM_F_NONE);
            CHANGE_STATE(ASM_CORE_STATE_BEGIN, &data);
			break;
		}
    }

    return MMI_RET_OK;
}

static void asm_active_previous_app(mmi_event_struct *para)
{
    mmi_event_struct evt;
    MMI_ID event_id = (g_asm_core_ctx.close_app_state == CLOSING_TO_IDLE)? ASM_CONTINUE_TO_IDLE : ASM_CONTINUE_TO_CLOSE;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ACTIVE_PREVIOUS_APP);

    MMI_FRM_INIT_EVENT(&evt, event_id);
    MMI_FRM_SEND_EVENT(&evt, post_core_proc, NULL);

}

static MMI_BOOL asm_prepare(MMI_ID app_id, U16 way)
{
    U32 total_size, continuous_subsize;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PREPARE1);
    if (mmi_frm_group_is_present(app_id) == MMI_TRUE)
    {
        asm_data_struct *p_data = mmi_frm_group_get_asm_data_ptr(app_id);
        ASMC_ASSERT(p_data);
        if (IS_BIT_SET(p_data->flag, ASM_F_DO_SHRINK_BASE_CHECKING))
        {
            SET_BIT(&(p_data->flag), ASM_F_DO_SHRINK_BASE_CHECKING, 0); /*restore the quota for prepare process*/
        }
        total_size = get_prepare_size(app_id, PREPARE_REQ_MAX_SIZE);
        continuous_subsize = get_prepare_continuous_subsize(app_id, PREPARE_REQ_MAX_SIZE);
        if (IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE) && 
                 !check_enough_by_ID(app_id, total_size, continuous_subsize))
        {
            
            mmi_group_node_struct node_info;
            mmi_event_struct p;
            SET_BIT(&(p_data->flag), ASM_F_PREPARE_CANCELLED, 0);

            mmi_frm_group_get_info(app_id, &node_info);
            MMI_FRM_INIT_EVENT(&p, way);
            MMI_FRM_POST_EVENT(&p, post_core_proc, (void*)app_id);
            return MMI_FALSE;
        }
        else
        {
            p_data->shrunk_base = 0; /*restore the base size if prepare success*/
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_TRUE;
    }
}


static mmi_ret asm_core_proc(mmi_event_struct *evt)
{
    asm_core_state_data_struct data;    
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CORE_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            if (evt->user_data == (void *)'FAWD')
            {
                if (prepare_get_state() == ASM_CORE_STATE_WAIT)
                {
                    data.cancel.reason = MMI_FRM_ASM_CANCEL_DEL_BY_INTERRUPT;
                    CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
                }
                break;
            }
            else if (evt->user_data == (void *)'BCWD')
            {
                if (g_asm_core_ctx.close_app_state == CLOSING_TO_IDLE)
                {                
                    return MMI_RET_ERR;
                }
                else if (g_asm_core_ctx.close_app_state == CLOSED)
                {
                    return MMI_RET_OK;
                }
                else if (g_asm_core_ctx.close_app_state == CLOSING)
                {
                    return MMI_RET_OK;
                }
                else
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
        }
        
        case EVT_ID_GROUP_ACTIVE:
        {
            if (evt->user_data == (void *)'BCWD')
            {
                if (mmi_frm_nmgr_is_scenario_deferred(
                	  AMS_DEFAULT_SCENARIO_ID(MMI_SCENARIO_ID_DEFAULT),
                    mmi_frm_asmi_invoke_success_callback_internal ,
                    NULL) == MMI_FALSE)
                {
                    MMI_ID app_id = mmi_frm_get_previous_app_id(g_asm_core_ctx.asm_dummy_gid);
                #if defined   __MMI_USE_MMV2__
                    mmi_event_struct p;
                    MMI_FRM_INIT_EVENT(&p, EVT_ID_ASM_BACKWARD_ENLARGE_HEAP);
                    p.user_data = (void *)app_id;
                    if ( MMI_FRM_ASM_WAITING_TO_FREE == mmi_frm_group_send_event_ex(g_asm_core_ctx.asm_dummy_gid, app_id, &p) )
                    {   /*here means async enlarge heap case, the EVT_ID_ASM_BACKWARD_ENLARGE_HEAP would be handled by VfxApp::processGroupProc
                        the following job will be done by asm_backward_enlarge_slmm_proc*/
                        break;
                    }
                #endif
                    g_asm_core_ctx.is_backward_prepare = MMI_TRUE;
                    if (asm_prepare(app_id, ASM_BACKWARD_PREPARE) == MMI_TRUE)
                    {
                        asm_active_previous_app(evt);
                    }
                }
            }
            break;
        }

        case EVT_ID_ASM_PREPARED:
        {
            if (g_asm_core_ctx.is_backward_prepare || g_asm_core_ctx.is_unhide_prepare || g_asm_core_ctx.is_set_active_prepare)
            {
				mmi_frm_asm_prepare_evt_struct *p = (mmi_frm_asm_prepare_evt_struct *)evt;
                mmi_frm_asm_clean_base_shrink(p->app_id);
            }
			if (g_asm_core_ctx.is_backward_prepare)
				asm_active_previous_app(evt);
			if (g_asm_core_ctx.is_unhide_prepare)
			{
				mmi_frm_asm_prepare_evt_struct *p = (mmi_frm_asm_prepare_evt_struct *)evt;
				mmi_frm_group_unhide(p->app_id);
				mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
				g_asm_core_ctx.is_unhide_prepare = MMI_FALSE;
			}

			if (g_asm_core_ctx.is_set_active_prepare)
			{
				mmi_frm_set_active_group_int(g_asm_core_ctx.set_active_group_id);
				mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
				g_asm_core_ctx.is_set_active_prepare = MMI_FALSE;
			}
            break;
        }

		case EVT_ID_ASM_CANCELED:
		{
			if (g_asm_core_ctx.is_unhide_prepare || g_asm_core_ctx.is_set_active_prepare)
			{
                /*restore the shrink base -- start*/
				mmi_frm_asm_prepare_evt_struct *p = (mmi_frm_asm_prepare_evt_struct *)evt;
                asm_data_struct *p_data;
                p_data = mmi_frm_group_get_asm_data_ptr(mmi_frm_get_root_app(p->app_id));
                if (p_data != NULL)
                {
                    if (p_data->shrunk_base != 0)
                    {
                        SET_BIT(&(p_data->flag), ASM_F_DO_SHRINK_BASE_CHECKING, 1);
                    }
                }
                /*restore the shrink base -- end*/
				mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
				g_asm_core_ctx.is_unhide_prepare = MMI_FALSE;
				g_asm_core_ctx.is_set_active_prepare = MMI_FALSE;
			}
			break;
		}

		case EVT_ID_GROUP_GOBACK:
		{
			if (g_asm_core_ctx.close_app_state == CLOSING_TO_IDLE)
			{
				g_asm_core_ctx.is_active_idleapp_in_endkey = MMI_TRUE;
			}
			break;
		}

        case EVT_ID_GROUP_DEINIT:
        {
             g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
             g_asm_core_ctx.asm_dummy_gid = GRP_ID_INVALID;
             g_asm_core_ctx.close_app_state = CLOSED;
             break;
        }

    }

    return MMI_RET_OK;
}

#if defined __MMI_USE_MMV2__
static mmi_ret asm_change_heap_size_proc(mmi_event_struct *evt)
{
    /*enter twice : sent evt & post evt*/
    mmi_frm_asm_change_heap_size_para  para;
    mmi_id heap_owner_id;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHANGE_HEAP_SIZE_PROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_ASM_PREPARED:
        {
            mmi_frm_asm_prepare_evt_struct *cb_evt;
            U32 old_heap_size = ((asm_slmm_heap_change_size_cb_data*)evt->user_data)->curr_heap_size;
            memcpy(&para, &((asm_slmm_heap_change_size_cb_data*)evt->user_data)->para, sizeof(para));
            mmi_frm_free(evt->user_data);
            heap_owner_id = mmi_frm_asm_get_slmm_owner_id(para.frm_asm_slmm_id);
            g_asm_core_ctx.requester_bind_id = APPLIB_MEM_AP_ID_DUMMY;
            cb_evt = (mmi_frm_asm_prepare_evt_struct *) evt;
            mmi_frm_asm_slmm_limit_size(heap_owner_id, (applib_mem_slmm_id)para.frm_asm_slmm_id,
                                        old_heap_size, para.heap_size);
            /*applib_mem_ap_slmm_set_shrunk_heap_size() already done in the begining of change size*/
            MMI_FRM_SEND_EVENT(cb_evt, para.user_cb, para.user_data);
            break;
        }
        case EVT_ID_ASM_CANCELED:
        {
            mmi_frm_asm_cancel_evt_struct *cb_evt;
            U32 res_heap_size;
            U32 old_heap_size = ((asm_slmm_heap_change_size_cb_data*)evt->user_data)->curr_heap_size;
            memcpy(&para, &((asm_slmm_heap_change_size_cb_data*)evt->user_data)->para, sizeof(para));
            mmi_frm_free(evt->user_data);
            heap_owner_id = mmi_frm_asm_get_slmm_owner_id(para.frm_asm_slmm_id);
            g_asm_core_ctx.requester_bind_id = APPLIB_MEM_AP_ID_DUMMY;
            cb_evt = (mmi_frm_asm_cancel_evt_struct *) evt;
            /*restore the shrunk size because the size change canceled*/
            res_heap_size = mmi_res_get_app_heap_size(heap_owner_id);
            applib_mem_ap_slmm_set_shrunk_heap_size((applib_mem_slmm_id)para.frm_asm_slmm_id, res_heap_size - old_heap_size);
            MMI_FRM_SEND_EVENT(cb_evt, para.user_cb, para.user_data);
            break;
        }
    }
    return MMI_RET_OK;
}

static mmi_ret asm_backward_enlarge_slmm_proc(mmi_event_struct *evt)
{
    mmi_id app_id = (mmi_id)evt->user_data;
    switch (evt->evt_id)
    {
        case EVT_ID_ASM_PREPARED:
            break;
        case EVT_ID_ASM_CANCELED:
        {
            ASMC_ASSERT(0);
            break;
        }
    }
    if (asm_prepare(app_id, ASM_BACKWARD_PREPARE) == MMI_TRUE)
    {
        asm_active_previous_app(evt);
    }
    return MMI_RET_OK;
}
#endif


static void do_prepare_wait(mmi_id requester_id, asm_core_state_data_struct *data)
{
    g_asm_core_ctx.wait_type = data->wait.type;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_DO_PREPARE_wait, g_asm_core_ctx.wait_type);
    /* block most interrupt */
    mmi_frm_start_scenario(MMI_FRM_ASM_SCENARIO_ID);

    /* handle incoming call event */
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, do_prepare_ucm_cb_hdlr, NULL);   
}

static void do_prepare_success(mmi_id requester_id, asm_core_state_data_struct *data)
{
    invoke_prepare_queue_callback(requester_id, ASM_CORE_CB_SUCCESS, 0);
    CHANGE_STATE(ASM_CORE_STATE_NONE, NULL);
}

static void do_prepare_cancel(mmi_id requester_id, asm_core_state_data_struct *data)
{
    asm_data_struct *p_data;
    mmi_id root_id = mmi_frm_get_root_app(requester_id);

    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    ASMC_ASSERT(p_data);
    SET_BIT(&(p_data->flag), ASM_F_PREPARE_CANCELLED, 1);

    mmi_frm_nmgr_cancel_deferred_scenario(
        AMS_DEFAULT_SCENARIO_ID(MMI_SCENARIO_ID_DEFAULT),
        mmi_frm_asmi_invoke_success_callback_internal,
        NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CANCEL, data->cancel.reason);
    invoke_prepare_queue_callback(requester_id, ASM_CORE_CB_CANCEL, data->cancel.reason);
    CHANGE_STATE(ASM_CORE_STATE_NONE, NULL);    
}

static void do_prepare_none(mmi_id requester_id, asm_core_state_data_struct *data)
{
    mmi_id asm_dummy_gid = g_asm_core_ctx.asm_dummy_gid;
    memset(&g_asm_core_ctx.req_info, 0, sizeof(g_asm_core_ctx.req_info));
    g_asm_core_ctx.wait_type = ASM_CORE_WAIT_NONE;
    if (g_asm_core_ctx.is_backward_prepare == MMI_FALSE &&
		g_asm_core_ctx.is_unhide_prepare == MMI_FALSE &&
		g_asm_core_ctx.is_set_active_prepare == MMI_FALSE)
    {
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_DO_PREPARE_NONE, asm_dummy_gid);
        mmi_frm_group_close(asm_dummy_gid);
        g_asm_core_ctx.asm_dummy_gid = GRP_ID_INVALID;
    }
}


static MMI_BOOL prepare_check_state(asm_core_state_enum new_state)
{
#ifndef __MTK_TARGET__
    U32 i;
    for (i=0; i<sizeof(state_check_table)/sizeof(asm_core_state_check_struct); i++)
    {
        if ((state_check_table[i].current_state == g_asm_core_ctx.current_state) &&
            (state_check_table[i].new_state == new_state))
            return MMI_TRUE;
    }
    return MMI_FALSE;
#else
    return MMI_TRUE;
#endif
}

static void prepare_change_state(asm_core_state_enum new_state, asm_core_state_data_struct *data, U32 line)
{
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PREPARE_CHANGE_STATE, g_asm_core_ctx.req_info.requester_id, line, g_asm_core_ctx.current_state, new_state);

    switch(g_asm_core_ctx.current_state)
    {
    case ASM_CORE_STATE_WAIT:
        /* do actions for leaving wait state */
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, do_prepare_ucm_cb_hdlr, NULL);
        mmi_frm_end_scenario(MMI_FRM_ASM_SCENARIO_ID);
        g_asm_core_ctx.wait_type = ASM_CORE_WAIT_NONE;
        break;
    }

    ASMC_ASSERT(prepare_check_state(new_state));
    g_asm_core_ctx.current_state = new_state;

    ASMC_ASSERT(new_state < ASM_CORE_STATE_END_OF_ENUM);
    if (do_prepare_state_action[new_state])
        do_prepare_state_action[new_state](g_asm_core_ctx.req_info.requester_id, data);
}


static asm_core_state_enum prepare_get_state()
{
    return g_asm_core_ctx.current_state;
}


static mmi_ret do_prepare_ucm_cb_post_process(mmi_event_struct *evt)
{
   if(g_asm_core_ctx.current_state != ASM_CORE_STATE_NONE)
   {
			asm_core_state_data_struct data;
    	data.cancel.reason = MMI_FRM_ASM_CANCEL_BY_UCM_CALL;
    	CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
    }

    return MMI_RET_OK;
}

static mmi_ret do_prepare_ucm_cb_hdlr(mmi_event_struct *evt)
{
    mmi_event_struct postInvoke;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_UCM_HDLR);
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        MMI_FRM_INIT_EVENT(&postInvoke, 0);
        MMI_FRM_POST_EVENT(&postInvoke, do_prepare_ucm_cb_post_process, NULL);
    }
    return MMI_RET_OK;
}

static MMI_BOOL is_node_under_root(group_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (node->parent->id == GRP_ID_ROOT || node->parent->id == GRP_ID_BK) ? MMI_TRUE : MMI_FALSE;
}


/***************************************************************************** 
 * FUNCTION
 *  check_enough_by_ID
 * DESCRIPTION
 *  check if the ID 's ASM remaining size is enough for the request
 * PARAMETERS
 *  mmi_id:             [IN]    app id
 *  total_size:         [IN]    the total request size (non-continuous + continuous)
 *  continuous_subsize: [IN]    only useful in MMv2 case, the continuous memory size part of request
 * RETURNS
 *  1 : success ; 0 : fail
  *****************************************************************************/
static MMI_BOOL check_enough_by_ID (mmi_id id, U32 total_size, U32 continuous_subsize)
{
    U32 total_left = 0;
    mmi_id root_id;
/*MMv2 can do the physical memory page moving, so the non-continuous request size should always can be allocated if the total request size <= remaining quota.
 but we need to guarantee the continuous part by mmi_frm_asm_check_enough*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHECK_ENOUGH, id, total_size, continuous_subsize);
    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(id);
    if (root_id == GRP_ID_INVALID)
    { /*case of asm 1.0 app_id*/
          root_id = id;
    }
    //OOM has launched, some one else also want to launch
    if (mmi_frm_asm_manager_is_launched(NULL) &&
        root_id != g_asm_core_ctx.anonymous_gid &&
        root_id != g_asm_core_ctx.req_info.requester_id)
    {
        ASM_CORE_UNLOCK;
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHECK_ENOUGH_EXIT1);
        return MMI_FALSE;
    }
    if (root_id == g_asm_core_ctx.anonymous_gid && total_size <= get_anonymous_quota())
    {
        /*size enough*/
    }
    else
    {
        total_left = mmi_frm_asm_get_total_left_size_r(root_id);
        if (total_left < total_size)
        {
            ASM_CORE_UNLOCK;
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHECK_ENOUGH_EXIT2, id, total_left, total_size);
            HistoryDump();
            return MMI_FALSE;
        }
    }
    #if defined __MMI_USE_MMV2__
    ASMC_ASSERT(total_size >= continuous_subsize);
    /*continuous part check*/
    if (continuous_subsize)
    {
        if (!applib_mem_ap_check_enough_try_alloc(continuous_subsize, KAL_TRUE))
        {
            if (!applib_mem_ap_cache_free_till_enough_int(continuous_subsize, KAL_TRUE, NULL, __LINE__))
            {
                ASM_CORE_UNLOCK;
				MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHECK_ENOUGH_EXIT3);
                HistoryDump();
                return MMI_FALSE;
            }
        }
    }
    /*non_continuous part is movable so it is guaranteed by above quota check*/
    #else
    if (!applib_mem_ap_check_enough_try_alloc(total_size, KAL_TRUE))
    {
        if (!applib_mem_ap_cache_free_till_enough_int(total_size, KAL_TRUE, NULL, __LINE__))
        {
            ASM_CORE_UNLOCK;
			MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CHECK_ENOUGH_EXIT4, total_size);
            HistoryDump();
            return MMI_FALSE;
        }
    }
    #endif
    ASM_CORE_UNLOCK;
    return MMI_TRUE;                            
}

mmi_ret mmi_frm_asm_scenario_hook(scenario_hook_evt_enum evt, base_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    group_node_struct *grp_node = (group_node_struct *)node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (node == NULL)
	{
		return MMI_RET_OK;
	}
    if (is_node_under_root(grp_node))
    {
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_SCENARIO_HOOK, evt, node->id);
        switch (evt)
        {
        #ifdef __PLUTO_MMI_PACKAGE__
            case HOOK_EVT_BEFORE_ENTER:
            {
                if (!(IS_BIT_SET(grp_node->asm_data.flag, ASM_F_PLUTO_LAUNCHER)))
                {
                    SET_BIT(&(grp_node->asm_data.flag), ASM_F_SKIP_SIZE_CHECKING, 1);
                    SET_BIT(&(grp_node->asm_data.flag), ASM_F_SKIP_RESERVE_CHECKING, 1);
                }
                break;
            }
        #endif

            case HOOK_EVT_AFTER_INACTIVE:
            {
                mmi_frm_asm_after_inactive(node->id);
                break;
            }
        
            case HOOK_EVT_AFTER_DEINIT:
            {
                mmi_frm_asm_after_deinit(node->id, &(grp_node->asm_data));
                break;
            }
        
            case HOOK_EVT_AFTER_CREATE:
            {
                mmi_frm_asm_after_create(node->id, &(grp_node->asm_data));
                break;
            }
        
            case HOOK_EVT_BEFORE_CLOSE:
            {
                mmi_frm_asm_before_close(node->id, node, MMI_FALSE);
                break;
            }
            
            case HOOK_EVT_CLOSE_FAIL:
            {
                mmi_frm_asm_close_fail(node->id, node);
                break;
            }

			case HOOK_EVT_BEFORE_TO_IDLE:
			{
				mmi_frm_asm_before_close(node->id, node, MMI_TRUE);
				break;
			}

			case HOOK_EVT_SET_ACTIVE_APP:
			{
				return mmi_frm_asm_set_active_app(node->id);
			}

			case HOOK_EVT_BEFORE_ACTIVE:
			{
				if (g_asm_core_ctx.is_active_idleapp_in_endkey)
				{
					mmi_event_struct p;
					MMI_FRM_INIT_EVENT(&p, EVT_ID_PRE_ACTIVE_IDLE_APP_IN_END_KEY);
					MMI_FRM_CB_EMIT_EVENT(&p);
				}
				break;
			}

			case HOOK_EVT_AFTER_ACTIVE:
			{
				if (g_asm_core_ctx.is_active_idleapp_in_endkey)
				{
					mmi_event_struct p;
					g_asm_core_ctx.is_active_idleapp_in_endkey = MMI_FALSE;
					MMI_FRM_INIT_EVENT(&p, EVT_ID_POST_ACTIVE_IDLE_APP_IN_END_KEY);
					MMI_FRM_CB_EMIT_EVENT(&p);
				}
				break;
			}
        }
    } 
    return MMI_RET_OK;
}


static void mmi_frm_asm_after_inactive(mmi_id app_id)
{
    U32 quota_size = 0, current_usage;
    asm_data_struct *p_data;

#if defined __MMI_USE_MMV2__
    mmi_event_struct p;
    MMI_FRM_INIT_EVENT(&p, EVT_ID_ASM_INACTIVE_SHRINK_HEAP);
    p.user_data = (void *)app_id;
    mmi_frm_group_send_event_ex(app_id, app_id, &p); 
#endif
    /* use app_id for root_id, since if flag exists, that's app node */

    p_data = mmi_frm_group_get_asm_data_ptr(app_id);
    ASMC_ASSERT(p_data);
    if (IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE))
    {
#if defined __MMI_USE_MMV2__
        mmi_app_mem_info_struct mem_info;
        mmi_res_get_app_mem_info (app_id, &mem_info);
        quota_size = mem_info.base_size + mem_info.heap_global_size; /*base + global*/
        quota_size -= applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(app_id);
#else
        quota_size = mmi_res_get_app_base_mem_size(app_id);
#endif
        current_usage = get_current_usage(app_id);

        if (!IS_BIT_SET(p_data->flag, ASM_F_SKIP_SIZE_CHECKING) && (current_usage > APPLIB_MEM_AP_POOL_SIZE_CONFIG(quota_size)))
        {
            /* APP w/ reserve property should free its FG mem. after inactive */
            ASMC_ASSERT(0);
        }
    }
}


static void mmi_frm_asm_after_deinit(mmi_id app_id, asm_data_struct *p_data)
{
    mmi_event_struct evt;

	if (g_asm_core_ctx.asm_dummy_gid == app_id)
	{
		return;
	}
    /* clear reserve flag if set */
    if (IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE))
    {
        SET_BIT(&(p_data->flag), ASM_F_PREPARE_W_RESERVE, 0);
    }
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_TERMINATED);
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


static void mmi_frm_asm_after_create(mmi_id app_id, asm_data_struct *p_data)
{
    /* check if there is previous non-freed asm buffer, collect them */
    p_data->usage = applib_mem_ap_get_single_usage(app_id);
#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
	p_data->mem_prio = MMI_FRM_APP_MEM_PRIORITY_DEFAULT;
#endif
}


static void mmi_frm_asm_close_fail(mmi_id app_id, base_node_struct *p)
{
	MMI_ID id;
	MMI_BOOL ret = mmi_frm_asm_manager_is_launched(&id);
    if (app_id != g_asm_core_ctx.asm_dummy_gid && !ret && p->parent->id != GRP_ID_BK)
    {
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_CLOSE_FAIL, g_asm_core_ctx.asm_dummy_gid);
        mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
    }
}

mmi_ret set_active_prepare(mmi_event_struct *evt)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
	if (asm_core_process_reentry(ASM_CORE_STATE_BEGIN, (mmi_event_struct *)evt, (mmi_proc_func)set_active_prepare, NULL))
		return MMI_RET_ERR;
#endif
	g_asm_core_ctx.asm_dummy_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, asm_core_proc, (void *)'FAWD');
	mmi_frm_group_enter(g_asm_core_ctx.asm_dummy_gid, MMI_FRM_NODE_NONE_FLAG);
	g_asm_core_ctx.is_set_active_prepare = MMI_TRUE;
	if(asm_prepare(g_asm_core_ctx.set_active_group_id, ASM_SET_ACTIVE_PREPARE))
	{
		g_asm_core_ctx.is_set_active_prepare = MMI_FALSE;
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_SET_ACTIVE_PREPARE, g_asm_core_ctx.asm_dummy_gid);
		mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
		return MMI_RET_OK;
	}
	else
	{
		return MMI_RET_ERR;
	}
}
static mmi_ret mmi_frm_asm_set_active_app(MMI_ID id)
{
	mmi_ret ret = MMI_RET_OK;
	mmi_event_struct evt;
	g_asm_core_ctx.set_active_group_id = id;
	MMI_FRM_INIT_EVENT(&evt, 0);
	ret = set_active_prepare(&evt);
	return  ret;
}

static void mmi_frm_asm_before_close(mmi_id app_id, base_node_struct *p, MMI_BOOL is_to_idle)
{
    mmi_frm_node_struct node;
    group_node_struct *grp = (group_node_struct *)p;
    group_node_struct *parent = (group_node_struct *)p->parent;
    if (grp->m_prev == NULL || 
        parent->m_tail != p ||
        g_asm_core_ctx.asm_dummy_gid != GRP_ID_INVALID ||
        parent->id != GRP_ID_ROOT
        ) 
    {
        return;
    }
#ifdef __MMI_FRM_HISTORY__
	if (get_active_history_node_id() != app_id)
	{
		return;
	}
#endif
    g_asm_core_ctx.asm_dummy_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, asm_core_proc, (void *)'BCWD');
    node.id = g_asm_core_ctx.asm_dummy_gid;
    node.entry_proc = asm_core_proc;
    node.user_data = (void *)'BCWD';
    if (IsBitSet(grp->attrib, NODE_ATTRIB_IN_END_KEY_PROCESS_IDX) || is_to_idle)
    {
        MMI_ID idle_id;
        g_asm_core_ctx.close_app_state = CLOSING_TO_IDLE;
		idle_id = mmi_frm_app_get_idle_app_id();
        mmi_frm_group_insert(GRP_ID_ROOT, idle_id, &node, MMI_FRM_NODE_AFTER_FLAG);
    }
    else
    {
        g_asm_core_ctx.close_app_state = CLOSING;
        mmi_frm_group_insert(GRP_ID_ROOT, app_id, &node, MMI_FRM_NODE_BEFORE_FLAG);
        
    }
}


static mmi_ret asm_anonymous_access_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_ASM_FREE_REQ:
    case EVT_ID_ASM_FORCE_FREE:
        return MMI_FRM_ASM_FREE_FAIL;
#ifdef __MMI_FRM_HISTORY__
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        /* do not delete this dangle group */
        return MMI_RET_ERR;
#endif
    }
    return MMI_RET_OK;
}

void mmi_frm_appmem_stage1_init(void)
{
    applib_mem_ap_init(mmi_frm_appmem_stop_finished_handler, 
                       #if defined __MMI_USE_MMV2__
                       mmi_res_get_asm_va_pool(), 
                       #else
                       mmi_res_get_asm_pool(), 
                       #endif
                       mmi_res_get_asm_pool_size());
    g_asm_core_ctx.init_stage = ASM_INIT_STAGE1;
    g_asm_core_ctx.anonymous_gid = ASM_ANONYMOUS_ID;
#ifdef __MMI_FRM_ASM_CORE_MUTEX__
    mmi_frm_recursive_mutex_init(&asm_core_rmutex, "asm core rmutex");
#endif
}


MMI_BOOL mmi_frm_appmem_is_in_first_stage(void)
{
    return  (g_asm_core_ctx.init_stage == ASM_INIT_STAGE1) ? MMI_TRUE: MMI_FALSE;
}


void mmi_frm_appmem_mem_freed_handler(mmi_id app_id, MMI_BOOL is_hide)
{
#ifdef __PLUTO_MMI_PACKAGE__
    if (is_hide == MMI_FALSE && mmiapi_is_MMI_task())
    {
        if (applib_mem_ap_get_single_usage(app_id) == 0)
        {
            mmi_frm_asmi_app_all_mem_freed_evt_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_ASMI_APP_FREE_ALL_MEM);
            evt.app_id = app_id;
            notify_mgr((mmi_event_struct *)&evt, MMI_FALSE);
        }
    }
#endif
}

/*****************************************************************************              
 * Export Function                                                                    
 *****************************************************************************/
void mmi_frm_appmem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_asm_property_struct p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_register_default_stop_callback(mmi_frm_appmem_default_group_stop_callback);
    applib_mem_ap_register_pre_alloc_handler(mmi_frm_appmem_pre_allocation_handler);
    applib_mem_ap_register_mem_freed_handler(mmi_frm_appmem_mem_freed_handler);



    memset(&g_asm_core_ctx, 0, sizeof(g_asm_core_ctx));
    g_asm_core_ctx.req_info.requester_id    = GRP_ID_INVALID;
    g_asm_core_ctx.auto_prompt_screen       = MMI_TRUE;
    g_asm_core_ctx.init_stage = ASM_INIT_STAGE2;
    g_asm_core_ctx.close_app_state = CLOSED;
    /* create group for anonymous access */
    g_asm_core_ctx.anonymous_gid = mmi_frm_group_create(GRP_ID_ROOT, ASM_ANONYMOUS_ID, asm_anonymous_access_proc, NULL);
    g_asm_core_ctx.requester_bind_id = APPLIB_MEM_AP_ID_DUMMY;
    ASMC_ASSERT(g_asm_core_ctx.anonymous_gid == ASM_ANONYMOUS_ID);
    mmi_frm_asm_get_property(g_asm_core_ctx.anonymous_gid, &p);
    p.f_hide_in_oom         = 1;
    p.f_skip_size_checking  = 1;
    p.f_skip_reserve_checking = 1;
    mmi_frm_asm_set_property(g_asm_core_ctx.anonymous_gid, &p);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mem_ap_cache_free_till_enough_by_id
 * DESCRIPTION
 *  This API is used to get total cache memory size in the ASM buffer pool
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_mem_ap_cache_free_till_enough_by_id(kal_uint16 root_id, kal_uint32 req_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (applib_mem_ap_check_enough_try_alloc(req_size, KAL_TRUE) || \
		(applib_mem_ap_cache_free_till_enough_int(req_size, KAL_TRUE, NULL, __LINE__)))
	{
		if (mmi_frm_asm_get_total_left_size_r(root_id) >= req_size)
            return MMI_TRUE;
	}
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_disable_auto_prompt_screen
 * DESCRIPTION
 *  disable auto-prompt when app-ASM allocation failed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_disable_auto_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASM_CORE_LOCK;
    g_asm_core_ctx.auto_prompt_screen = MMI_FALSE;
    ASM_CORE_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_enable_auto_prompt_screen
 * DESCRIPTION
 *  re-enable auto-prompt when app-ASM allocation failed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_enable_auto_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASM_CORE_LOCK;
    g_asm_core_ctx.auto_prompt_screen = MMI_TRUE;
    ASM_CORE_UNLOCK;
}


/*****************************************************************************/

void mmi_frm_appmem_set_cancel_callback(applib_mem_ap_id_enum app_id, mmi_frm_appmem_cb cancel_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_asm_core_ctx.req_info.requester_id == app_id)
    {
        g_asm_core_ctx.req_info.cancel_callback = cancel_callback;
    }
}


/*****************************************************************************/

static void asm_core_v10_deinit(void)
{
    g_asm_core_ctx.wait_type = ASM_CORE_WAIT_NONE;
}


static mmi_ret asm_core_v10_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    /* interrupt AP force to go back to IDLE, e.g. USB plug-in */
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:

        asm_core_v10_deinit();
        mmi_frm_asmi_invoke_cancel_callback(g_asm_core_ctx.req_info.requester_id, MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT);
        break;

    case EVT_ID_GROUP_DEINIT:

        asm_core_v10_deinit();
        break;
    }
    return MMI_RET_OK;
}

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
#endif

static mmi_ret asm_core_v10_ucm_cb_hdlr(mmi_event_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        asm_core_v10_deinit();
        mmi_frm_asmi_invoke_cancel_callback(g_asm_core_ctx.req_info.requester_id, MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL);
    }
    return MMI_RET_OK;
}


static void asm_core_v10_wait_start(applib_mem_ap_stop_type type)
{
    if (type == MEM_AP_STOP_TYPE_REQ)
    {
        g_asm_core_ctx.wait_type = ASM_CORE_WAIT_V10;
    }
	else
	{
		g_asm_core_ctx.wait_type = ASM_CORE_WAIT_V10_FORCE_FREE;
	}

    /* handle END key events */
    //SetKeyHandler(asm_core_v10_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
    
    /* block most interrupt */
    mmi_frm_start_scenario(MMI_FRM_ASM_SCENARIO_ID);
    
    /* handle incoming call event */
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, asm_core_v10_ucm_cb_hdlr, NULL);
}


static void asm_core_v10_wait_end()
{
    /* do actions for leaving wait state */
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, asm_core_v10_ucm_cb_hdlr, NULL);
    mmi_frm_end_scenario(MMI_FRM_ASM_SCENARIO_ID);
    g_asm_core_ctx.wait_type = ASM_CORE_WAIT_NONE;
}


static mmi_ret asm_core_v10_post_release(asm_core_v10_post_release_evt_struct *evt)
{
    mmi_frm_appmem_prompt_to_release_mem(evt->app_id, evt->app_icon, evt->required_size, evt->success_callback);
    return MMI_RET_OK;
}

#ifdef __MMI_FRM_ASM_OOM_SCREEN__
static MMI_BOOL asm_core_process_reentry(asm_core_state_enum new_state, mmi_event_struct *evt, mmi_proc_func proc_to_run, void* user_data)
{
    mmi_id app_mgr_id;
    /* cancel current process */
    if (g_asm_core_ctx.current_state == ASM_CORE_STATE_NONE)
        return MMI_FALSE;   /* not reentry */
        
    if (mmi_frm_asm_manager_is_launched(&app_mgr_id))
    {
        mmi_frm_asm_manager_close(app_mgr_id);
    } 
    if (g_asm_core_ctx.current_state == ASM_CORE_STATE_V10)
    {
        asm_core_v10_deinit();
        mmi_frm_asmi_invoke_cancel_callback(g_asm_core_ctx.req_info.requester_id, MMI_FRM_APPMEM_CANCEL_BY_REENTRY);
    }
    else
    {
        asm_core_state_data_struct data = {0};
        data.cancel.reason = MMI_FRM_ASM_CANCEL_BY_REENTRY;
        CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
    }

    /* post to continue new state */
    MMI_FRM_POST_EVENT(evt, proc_to_run, user_data);
    return MMI_TRUE;
}
#endif


static mmi_ret post_to_cancel(mmi_event_struct *evt)
{
    mmi_frm_asmi_invoke_cancel_callback(g_asm_core_ctx.req_info.requester_id, MMI_FRM_APPMEM_CANCEL_BY_PRIORITY);
    return MMI_RET_OK;
}

static asm_core_cancel(MMI_BOOL is_V20)
{
    if (is_V20 == MMI_TRUE)
    {
        asm_core_state_data_struct data = {0};
        g_asm_core_ctx.current_state = ASM_CORE_STATE_BEGIN;
        data.cancel.reason = MMI_FRM_ASM_CANCEL_BY_PRIORITY;
        CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
    }
    else
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, post_to_cancel, NULL);
    }
}

#ifdef __MMI_FRM_ASM_OOM_SCREEN__
static MMI_BOOL asm_core_process_priority(MMI_BOOL is_V20)
{
	MMI_BOOL ret;
	ret = mmi_frm_is_scrn_priority_enough(AMS_DEFAULT_SCENARIO_ID(MMI_SCENARIO_ID_DEFAULT));
    if (ret == MMI_FALSE)
    {        
        asm_core_cancel(is_V20);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif

static mmi_ret asm_core_v10_launch_proc(mmi_event_struct *evt)
{
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    mmi_frm_asm_manager_launch(g_asm_core_ctx.req_info.requester_id);
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_V10_LAUNCH_PROC, g_asm_core_ctx.asm_dummy_gid);
    mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
    g_asm_core_ctx.asm_dummy_gid = 0;
#else
    asm_core_v10_release_mem(MEM_AP_STOP_TYPE_FORCE);
#endif

    return MMI_RET_OK;
}

static void asm_core_v10_release_mem(applib_mem_ap_stop_type type)
{
    static U32 next_idx = 0;
    static U32 app_count = 0;
	static applib_mem_ap_usage_struct *applist = NULL;
    mmi_event_struct evt;

	if (applist == NULL)
	{
		applist = (applib_mem_ap_usage_struct *)mmi_malloc(sizeof(applib_mem_ap_usage_struct) * MMI_FRM_APPMEM_MAX_APP_PROMPTED);
		app_count = mmi_frm_asm_get_asm_usage(
			g_asm_core_ctx.req_info.requester_id,
			applist,
			(type == MEM_AP_STOP_TYPE_FORCE) ? KAL_FALSE : KAL_TRUE,
			(type == MEM_AP_STOP_TYPE_FORCE) ? KAL_FALSE : KAL_TRUE);		
	}

    if (g_asm_core_ctx.wait_type != ASM_CORE_WAIT_NONE)
    {
        asm_core_v10_wait_end();

        if (check_enough_by_ID(g_asm_core_ctx.req_info.requester_id, g_asm_core_ctx.req_info.required_size, g_asm_core_ctx.req_info.required_subsize_continuous))
        {
            if (applist)
            {
                mmi_mfree(applist);
                applist = NULL;
                app_count = 0;
                next_idx = 0;
            }
        #ifdef APPLIB_MEM_UNIT_TEST
            if (test_single_action_only == MMI_TRUE)
            {
                return;
            }
        #endif	
            mmi_frm_asmi_invoke_success_callback(g_asm_core_ctx.req_info.requester_id);
            mmi_frm_scrn_close(GRP_ID_ROOT, SCR_APPMEM_DUMMY);
            mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
            g_asm_core_ctx.asm_dummy_gid = 0;
            return;
        }
        next_idx++; /* memory still not enough, go for next volunteer */
    }

#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
		if (!g_asm_core_ctx.req_info.force_to_prepare) 
		{
			MMI_PRINT(MOD_MMI_FW,MMI_FW_TRC_G1_FRM,"[ASM] asm_core_v10_release_mem, auto_kill");
			while(next_idx < app_count)
			{
				asm_data_struct *p_data = mmi_frm_group_get_asm_data_ptr(applist[next_idx].app_id);	
	
				if(!p_data)
					break;
	
				MMI_PRINT(MOD_MMI_FW,MMI_FW_TRC_G1_FRM,"[ASM] asm_core_v10_release_mem, auto_kill memory priority: %d", p_data->mem_prio);
				if(p_data->mem_prio == 0)
					next_idx++;
				else
					break;
			}
		}
#endif

    
    /* ask app to free memory */
    if (next_idx < app_count)
    {
        MMI_ASSERT(applist);
        ASMC_TRACE(MMI_FRM_ASM_FREE_VOLUNTEERS, 
                    "[ASM][core] free_volunteers: IdToStop=%d\n",
                    applist[next_idx].app_id);

        asm_core_v10_wait_start(type);
#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
        applib_mem_ap_stop_app_by_MMI_task(applist[next_idx].app_id, MEM_AP_STOP_TYPE_FORCE);
#else
        applib_mem_ap_stop_app_by_MMI_task(applist[next_idx].app_id, type);
#endif
        return;
    }

    if (applist)
    {
        mmi_mfree(applist);
        applist = NULL;
        app_count = 0;
        next_idx = 0;
    }

#ifdef APPLIB_MEM_UNIT_TEST
    if (test_single_action_only == MMI_TRUE)
    {
        return;
    }
#endif	
    //g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
    /* no volunteer to free, do next */
    MMI_FRM_INIT_EVENT(&evt, 0);
    MMI_FRM_POST_EVENT(&evt, asm_core_v10_launch_proc, NULL);
}


void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_id, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    asm_core_v10_post_release_evt_struct evt = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* handle reentry */
    MMI_FRM_INIT_EVENT(&evt, 0);
    #if defined __MMI_USE_MMV2__
    /*it's a temp workaround for opera case overhead caused by 4k align page*/
    #define CONCERN_FRAG_OVER_SIZE (20*1024*1024)
    #define FRAG_OVERHEAD          (3*4096)
    if ( required_size > CONCERN_FRAG_OVER_SIZE)
    {
        required_size += FRAG_OVERHEAD;
    }
    ASMC_TRACE(TRC_MMI_FRM_ASM_PROMPT_RELEASE_INFO,
               "[ASM]mmi_frm_appmem_prompt_to_release_mem required_size %d \n",
                   required_size);
    #endif
    evt.app_id = app_id;
    evt.app_icon = app_icon;
    evt.required_size = required_size;
    evt.success_callback = success_callback;
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if (asm_core_process_reentry(ASM_CORE_STATE_V10, (mmi_event_struct *)&evt, (mmi_proc_func)asm_core_v10_post_release, NULL))
        return;
#endif
    ASMC_TRACE(MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM, "", app_id, required_size); 

    g_asm_core_ctx.current_state                = ASM_CORE_STATE_V10; 

    g_asm_core_ctx.req_info.requester_id        = app_id;
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if (asm_core_process_priority(MMI_FALSE))
    {
        return;
    }
#endif

#if defined(__OP01__) && defined(__PLUTO_MMI_PACKAGE__)
	if (srv_ucm_is_any_call())
	{
		asm_core_cancel(MMI_FALSE);
		mmi_popup_display_simple_ext(STR_GLOBAL_INSUFFICIENT_MEMORY, MMI_EVENT_INFO, GRP_ID_ROOT, NULL);
		return;
	}
#endif
    g_asm_core_ctx.req_info.required_size       = required_size; /*[ToDo?] size > app quota check*/
    g_asm_core_ctx.req_info.required_subsize_continuous  = required_size; /*[ToDo?] size > app quota check*/
    g_asm_core_ctx.req_info.success_callback    = (mmi_frm_appmem_success_cb)success_callback;
    g_asm_core_ctx.req_info.require_full_pool   = MMI_FALSE;

    /* put dummy screen */
    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_APPMEM_DUMMY, MMI_dummy_function, MMI_dummy_function, MMI_FRM_UNKNOW_SCRN);

    mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);

    /* handle interrupt events in proc */
    g_asm_core_ctx.asm_dummy_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, asm_core_v10_proc, NULL);
    mmi_frm_group_enter(g_asm_core_ctx.asm_dummy_gid, MMI_FRM_NODE_NONE_FLAG);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    asm_core_v10_release_mem(MEM_AP_STOP_TYPE_REQ);
}


static void mmi_frm_appmem_prompt_to_release_mem_int(
        MMI_ID_TYPE app_id, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        U32 required_subsize_continuous,
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_asm_core_ctx.req_info.requester_id        = app_id;
    g_asm_core_ctx.req_info.required_size       = required_size;
    g_asm_core_ctx.req_info.required_subsize_continuous  = required_subsize_continuous;
    g_asm_core_ctx.req_info.success_callback    = (mmi_frm_appmem_success_cb)success_callback;
    g_asm_core_ctx.req_info.require_full_pool   = MMI_FALSE;
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM_INT, app_id, required_size, required_subsize_continuous);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    mmi_frm_asm_manager_launch(app_id);
#else
    asm_core_v10_release_mem(MEM_AP_STOP_TYPE_FORCE);
#endif
}


/*****************************************************************************/

void mmi_frm_appmem_prompt_to_release_full_pool(
        MMI_ID_TYPE app_id, 
        MMI_ID_TYPE app_icon, 
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASMC_TRACE(MMI_FRM_ASM_PROMPT_TO_RELEASE_FULL_POOL, "", app_id);
    g_asm_core_ctx.req_info.requester_id        = app_id;
    g_asm_core_ctx.req_info.required_size       = 0;  /*no use in full pool case*/
    g_asm_core_ctx.req_info.required_subsize_continuous  = 0; /*no use in full pool case*/
    g_asm_core_ctx.req_info.success_callback    = (mmi_frm_appmem_success_cb)success_callback;
    g_asm_core_ctx.req_info.require_full_pool   = MMI_TRUE;
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    mmi_frm_asm_manager_launch(app_id);
#else
    asm_core_v10_release_mem(MEM_AP_STOP_TYPE_FORCE);    
#endif
}


void mmi_frm_asm_property_init(mmi_frm_asm_property_struct *p)
{
    p->f_prepare_w_reserve  = 0;
    p->f_hide_in_oom        = 0;
    p->f_skip_size_checking = 0;
	p->f_skip_reserve_checking = 0;
}



MMI_BOOL mmi_frm_asm_get_property(mmi_id app_id, mmi_frm_asm_property_struct *p)
{
    mmi_id root_id;

    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    memset(p, 0, sizeof(mmi_frm_asm_property_struct));
    if ((root_id != GRP_ID_INVALID) && p)
    {
        asm_data_struct *p_data;
        p_data = mmi_frm_group_get_asm_data_ptr(root_id);
        ASMC_ASSERT(p_data);
        p->f_hide_in_oom        = IS_BIT_SET(p_data->flag, ASM_F_HIDE_IN_OOM);
        p->f_prepare_w_reserve  = IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE);
        p->f_skip_size_checking = IS_BIT_SET(p_data->flag, ASM_F_SKIP_SIZE_CHECKING);
        p->f_skip_reserve_checking  = IS_BIT_SET(p_data->flag, ASM_F_SKIP_RESERVE_CHECKING);
        p->f_pluto_launcher = IS_BIT_SET(p_data->flag, ASM_F_PLUTO_LAUNCHER);
        ASM_CORE_UNLOCK;
        return MMI_TRUE;
    }
    ASM_CORE_UNLOCK;
    return MMI_FALSE;
}

MMI_BOOL mmi_frm_asm_set_property(mmi_id app_id, mmi_frm_asm_property_struct *p)
{
    mmi_id root_id;
    U32 *temp = (U32 *)p;
    U32 i;
	MMI_BOOL ret = MMI_FALSE;

    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);

    if ((root_id != GRP_ID_INVALID) && p)
    {
        asm_data_struct *p_data;

        p_data = mmi_frm_group_get_asm_data_ptr(root_id);
        ASMC_ASSERT(p_data);
	    for (i = ASM_F_PREPARE_W_RESERVE; i <= ASM_F_PLUTO_LAUNCHER; i++, temp++)
        {
            SET_BIT(&(p_data->flag), i, *temp);
        }
		applib_mem_ap_update_node_flag(app_id, APPLIB_MEM_HEADER_FLAG_IS_HIDE, p->f_hide_in_oom);
        ret = MMI_TRUE;
    }
    ASM_CORE_UNLOCK;
    return ret;
}

MMI_BOOL mmi_frm_asm_base_shrink_size(mmi_id app_id, U32 new_base_size)
{
    mmi_id root_id;

    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    if (root_id != GRP_ID_INVALID)
    {
        asm_data_struct *p_data;
        U32 res_base_size;

        p_data = mmi_frm_group_get_asm_data_ptr(root_id);
        ASMC_ASSERT(p_data);
        res_base_size = mmi_res_get_app_base_mem_size(root_id);
        ASMC_ASSERT_EXT(res_base_size >= new_base_size, app_id, res_base_size, new_base_size);        
        SET_BIT(&(p_data->flag), ASM_F_DO_SHRINK_BASE_CHECKING, 1);
        p_data->shrunk_base = res_base_size - new_base_size;
        ASM_CORE_UNLOCK;
        return MMI_TRUE;
    }
    ASM_CORE_UNLOCK;
    return MMI_FALSE;
}

MMI_BOOL mmi_frm_asm_clean_base_shrink(mmi_id app_id)
{
    mmi_id root_id;

    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    if (root_id != GRP_ID_INVALID) 
    {
        asm_data_struct *p_data;
        p_data = mmi_frm_group_get_asm_data_ptr(root_id);
        ASMC_ASSERT(p_data);
        SET_BIT(&(p_data->flag), ASM_F_DO_SHRINK_BASE_CHECKING, 0);
        p_data->shrunk_base = 0;
        ASM_CORE_UNLOCK;
        return MMI_TRUE;
    }
    ASM_CORE_UNLOCK;
    return MMI_FALSE;
}
#if defined __MMI_USE_MMV2__
MMI_FRM_ASM_SLMM_ID mmi_frm_asm_create_slmm_pool(mmi_id app_id, U32 mem_size, U32 is_log)
{
    applib_mem_slmm_id applib_slmm_id ;
    mmi_id root_id;
    asm_data_struct *p_data = NULL;
    MMI_BOOL skip_size_checking;
    
    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    
    skip_size_checking  = IS_BIT_SET(p_data->flag, ASM_F_SKIP_SIZE_CHECKING) ? MMI_TRUE: MMI_FALSE;
    if ( mem_size <= get_remaining_quota(root_id) || skip_size_checking)
    {
        applib_slmm_id = applib_mem_ap_create_slmm_pool(app_id, mem_size, MMI_TRUE, is_log);
        if (p_data)
        {
            p_data->usage += mem_size;
        }
        ASM_CORE_UNLOCK;
        return (MMI_FRM_ASM_SLMM_ID)applib_slmm_id;
    }
    else
    {
        ASM_CORE_UNLOCK;
        return NULL;
    }
}

kal_uint32 mmi_frm_asm_delete_slmm_pool (MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    kal_status retval;
    mmi_id root_id, app_id;
    asm_data_struct *p_data = NULL;
    ASM_CORE_LOCK;
    app_id = mmi_frm_asm_get_slmm_owner_id(frm_asm_slmm_id);
    root_id = mmi_frm_get_root_app(app_id);
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    if (p_data)
    {
        p_data->usage -= ((applib_mem_slmm_id)frm_asm_slmm_id)->applib_mem_header.chunk_size;
    }
    retval = applib_mem_ap_delete_slmm_pool((applib_mem_slmm_id) frm_asm_slmm_id, MMI_TRUE );
    ASM_CORE_UNLOCK;
    if (retval != KAL_SUCCESS)
    {
        ASMC_ASSERT_EXT(0, (kal_uint32)retval,(kal_uint32)frm_asm_slmm_id, (kal_uint32)root_id);
    }

    return 0;
}

void* _mmi_frm_asm_slmm_alloc(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 mem_size, MMI_BOOL is_cacheable, MMI_BOOL is_continuous, CHAR* file, U32 line)
{
    asm_alloc_flag flag = ASM_ALLOC_DEFAULT_FLAG;
    void* ptr;
    if (is_cacheable == MMI_TRUE && is_continuous == MMI_TRUE)
    {
        flag = ASM_ALLOC_DEFAULT_FLAG;
    }
    else if (is_cacheable == MMI_FALSE && is_continuous == MMI_TRUE)
    {
        flag = ASM_ALLOC_IS_FB_FLAG;
    }
    else if (is_cacheable == MMI_TRUE && is_continuous == MMI_FALSE)
    {
        flag = ASM_ALLOC_IS_SW_FLAG;
    }
    else
    {
        ASMC_ASSERT(0);
    }
    ptr = applib_mem_ap_slmm_alloc_dbg((applib_mem_slmm_id) frm_asm_slmm_id, mem_size, flag, (kal_uint32)file,  line, KAL_FALSE);
    return ptr;
}

kal_uint32 mmi_frm_asm_slmm_free(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, void *ptr)
{
    applib_mem_ap_slmm_free((applib_mem_slmm_id) frm_asm_slmm_id, ptr, KAL_FALSE);
    return 0;
}

kal_uint32 mmi_frm_asm_get_slmm_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return ((applib_mem_slmm_id)frm_asm_slmm_id)->applib_mem_header.chunk_size;
}

kal_uint32 mmi_frm_asm_get_slmm_shrunk_heap_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_slmm_get_shrunk_heap_size((applib_mem_slmm_id) frm_asm_slmm_id);
}

kal_uint32 mmi_frm_asm_get_slmm_total_left_size(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_slmm_total_left_size((applib_mem_slmm_id) frm_asm_slmm_id);
}

void* mmi_frm_asm_slmm_check_integrity(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_slmm_check((applib_mem_slmm_id) frm_asm_slmm_id);
}

kal_uint32 mmi_frm_asm_get_slmm_vm_start(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_slmm_vm_start((applib_mem_slmm_id) frm_asm_slmm_id);
}

kal_uint32 mmi_frm_asm_get_slmm_vm_end(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_slmm_vm_end((applib_mem_slmm_id) frm_asm_slmm_id);
}

mmi_id mmi_frm_asm_get_slmm_owner_id(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_slmm_owner_id((applib_mem_slmm_id)frm_asm_slmm_id);
}

KAL_SLMM_ID mmi_frm_asm_get_kal_slmm_id(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_kal_slmm_id((applib_mem_slmm_id)frm_asm_slmm_id);
}

kal_uint32 mmi_frm_asm_get_slmm_log_flag(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id)
{
    return applib_mem_ap_get_slmm_log_flag((applib_mem_slmm_id)frm_asm_slmm_id);
}

kal_uint32 mmi_frm_asm_slmm_limit_size(mmi_id app_id, MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 old_size, U32 new_size)
{
    mmi_id root_id;
    asm_data_struct *p_data = NULL;
    kal_int32 retVal;
    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
    retVal = applib_mem_ap_slmm_limit_size((applib_mem_slmm_id)frm_asm_slmm_id, new_size);
    if ( retVal < 0 && (new_size > old_size) )
    {   /*enlarge fail case*/
        /*free cache memory if necessary*/
        if (!applib_mem_ap_check_enough_try_alloc(new_size-old_size, KAL_FALSE))
        {
            if (!applib_mem_ap_cache_free_till_enough_int(new_size-old_size, KAL_FALSE, NULL, __LINE__))
            {
                ASM_CORE_UNLOCK;
                ASMC_ASSERT(0);
                return 0;
            }
        }
        retVal = applib_mem_ap_slmm_limit_size((applib_mem_slmm_id)frm_asm_slmm_id, new_size);
    }
    if ( retVal < 0)
    {
        ASM_CORE_UNLOCK;
        ASMC_ASSERT_EXT( 0 , (kal_uint32)retVal, (kal_uint32)app_id, (kal_uint32)((applib_mem_slmm_id)frm_asm_slmm_id)->kal_slmm_id);
    }

    if (p_data)
    {
        p_data->usage += new_size - old_size;
    }
    ASM_CORE_UNLOCK;
    return 1;
}
kal_uint32 mmi_frm_asm_slmm_change_heap_size ( mmi_frm_asm_change_heap_size_para*  para_p)
{
    kal_uint32 res_heap_size, shrunk_size, cur_heap_size ; 
    mmi_event_struct p;
    asm_slmm_heap_change_size_cb_data* my_data;
    mmi_id bkup_request_id;
    mmi_id heap_owner_id = mmi_frm_asm_get_slmm_owner_id(para_p->frm_asm_slmm_id);

    res_heap_size = mmi_res_get_app_heap_size(heap_owner_id);
    shrunk_size = applib_mem_ap_slmm_get_shrunk_heap_size((applib_mem_slmm_id) para_p->frm_asm_slmm_id);
    ASMC_ASSERT(res_heap_size >= para_p->heap_size);
    ASMC_ASSERT(res_heap_size >= shrunk_size);
    cur_heap_size = res_heap_size - shrunk_size;

    if ( cur_heap_size == para_p->heap_size)
        return 1; 
    /*check if it's a shrinking case*/
    if ( cur_heap_size > para_p->heap_size)
    {   
        mmi_frm_asm_slmm_limit_size(heap_owner_id, (applib_mem_slmm_id)para_p->frm_asm_slmm_id, 
                                    cur_heap_size, para_p->heap_size);
        applib_mem_ap_slmm_set_shrunk_heap_size((applib_mem_slmm_id)para_p->frm_asm_slmm_id, res_heap_size - para_p->heap_size);
        return 1; 
    }
    /*here means it's a enlarging size case*/
    /*enlarge the shrunk size to get correct quota during check_enough_by_ID*/
    applib_mem_ap_slmm_set_shrunk_heap_size((applib_mem_slmm_id)para_p->frm_asm_slmm_id, res_heap_size - para_p->heap_size);
    /* backup requester_id and replace w/ heap_owner_id is in order to call check_enough_by_ID.
      because this function is possible to be called in OOM due to the LOCK & UCM that trigger the platform context enlarge, 
      we need the check_enough_by_ID NOT block by OOM condition */
    ASM_CORE_LOCK;
    bkup_request_id = g_asm_core_ctx.req_info.requester_id;
    g_asm_core_ctx.req_info.requester_id = heap_owner_id;
    if ( check_enough_by_ID( heap_owner_id, para_p->heap_size - cur_heap_size, 0) )
    { /*current asm size is enough to enlarge the slmm*/
        g_asm_core_ctx.req_info.requester_id = bkup_request_id;
        ASM_CORE_UNLOCK;
        mmi_frm_asm_slmm_limit_size(heap_owner_id, (applib_mem_slmm_id)para_p->frm_asm_slmm_id, 
                                    cur_heap_size, para_p->heap_size);
        return 1; 
    }
    g_asm_core_ctx.req_info.requester_id = bkup_request_id;
    ASM_CORE_UNLOCK;
    if (para_p->flag & FRM_ASM_HEAP_CHANGE_ONLY_FREE_VOLUNTEERS)
    { /*try to free vluntters in sync process*/
        if (do_free_volunteers_no_wait(heap_owner_id, para_p->app_id, para_p->heap_size - cur_heap_size, 0))
    {
            mmi_frm_asm_slmm_limit_size(heap_owner_id, (applib_mem_slmm_id)para_p->frm_asm_slmm_id, 
                                        cur_heap_size, para_p->heap_size);
            return 1; 
        }
    }
    /*here means free size insufficient*/
        /*restore the shrunk size*/
        applib_mem_ap_slmm_set_shrunk_heap_size((applib_mem_slmm_id)para_p->frm_asm_slmm_id, res_heap_size - cur_heap_size);
        if ( para_p->flag & FRM_ASM_HEAP_CHANGE_IF_ENOUGH )
            return 0;
    /*here means it's a enlarging size case & the asm is insufficient, it need to do the prepare process */
    /*cancel the previous prepare (& OOM screen) if it exists*/
    ASMC_ASSERT(para_p->user_cb != NULL);
    my_data = mmi_frm_malloc(sizeof(*my_data));
    memcpy(&my_data->para, para_p, sizeof(*para_p));
    my_data->curr_heap_size = cur_heap_size;
    /*SET_BIT(&(p_data->flag), ASM_F_PREPARE_CANCELLED, 0);*/
    MMI_FRM_INIT_EVENT(&p, ASM_ENLARGE_HEAP);
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if ( asm_core_process_reentry(ASM_CORE_STATE_NONE, &p, post_core_proc, (void*)my_data )== MMI_FALSE )
#endif
    {
        MMI_FRM_POST_EVENT(&p, post_core_proc, (void*)my_data);
    }
    return 0;
}

kal_uint32 mmi_frm_asm_backward_enlarge_slmm_heap (
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size)
{
    mmi_frm_asm_change_heap_size_para para;
    kal_uint32 ret;

    para.app_id = app_id;
    para.heap_size = size;
    para.frm_asm_slmm_id = frm_asm_slmm_id;
    para.user_cb = asm_backward_enlarge_slmm_proc ;
    para.user_data = (void*) app_id;
    para.flag = FRM_ASM_HEAP_CHANGE_IN_BACKWARD | FRM_ASM_HEAP_CHANGE_FORCE_PREPARE ;
    ret = mmi_frm_asm_slmm_change_heap_size(&para);

    return ret;

}

kal_uint32 mmi_frm_asm_slmm_heap_shrink_size  ( 
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size)
{
    mmi_frm_asm_change_heap_size_para para;
    kal_uint32 ret;

    para.app_id = app_id;
    para.heap_size = size;
    para.frm_asm_slmm_id = frm_asm_slmm_id;
    para.user_cb = NULL ;
    para.user_data = (void*) app_id;
    para.flag = FRM_ASM_HEAP_CHANGE_DEFAULT ;
    ret = mmi_frm_asm_slmm_change_heap_size(&para);
    ASMC_ASSERT(ret == 1);
    return ret;
}

kal_uint32 mmi_frm_asm_slmm_heap_enlarge_size_if_enough ( 
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size )
{
    mmi_frm_asm_change_heap_size_para para;
    kal_uint32 ret;

    para.app_id = app_id;
    para.heap_size = size;
    para.frm_asm_slmm_id = frm_asm_slmm_id;
    para.user_cb = NULL ;
    para.user_data = (void*) app_id;
    para.flag = FRM_ASM_HEAP_CHANGE_IF_ENOUGH ;
    ret = mmi_frm_asm_slmm_change_heap_size(&para);

    return ret ;
}


kal_uint32 mmi_frm_asm_slmm_heap_enlarge_size_only_free_volunteers ( 
    mmi_id app_id,   
    MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id,                                                     
    kal_uint32 size)
{
    mmi_frm_asm_change_heap_size_para para;
    kal_uint32 ret;

    para.app_id = app_id;
    para.heap_size = size;
    para.frm_asm_slmm_id = frm_asm_slmm_id;
    para.user_cb = NULL ;
    para.user_data = (void*) app_id;
    para.flag = FRM_ASM_HEAP_CHANGE_ONLY_FREE_VOLUNTEERS ;
    ret = mmi_frm_asm_slmm_change_heap_size(&para);

    return ret ;
}

kal_uint32 mmi_frm_asm_slmm_get_used_page_size( MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id )
{
    return applib_mem_ap_slmm_get_used_page_size((applib_mem_slmm_id) frm_asm_slmm_id);
}
#else
/*for Gabget Lib dummy link, remove if MMv2 support pluto project*/
void *_mmi_frm_asm_slmm_alloc(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, U32 mem_size, MMI_BOOL is_cacheable, MMI_BOOL is_continuous, CHAR* file, U32 line)
{
    MMI_ASSERT( "DUMMY FOR LINK" == NULL);
    return NULL ;
}
kal_uint32 mmi_frm_asm_slmm_free(MMI_FRM_ASM_SLMM_ID frm_asm_slmm_id, void *ptr)
{
    MMI_ASSERT( "DUMMY FOR LINK" == NULL);
    return 0 ;
}
#endif




static mmi_ret post_prepare(asm_post_prepare_evt_struct *evt)
{
    asm_core_state_data_struct data = {0};
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_POST_PREPARE);
    if (mmi_frm_get_root_app(evt->requester_id) == GRP_ID_INVALID)
    {
        return MMI_RET_OK;
    }

    // put a dummy screen group here
    // avoid reentry to trigger backward procedure
    // if group enter => prepare should not put dummy
    if (g_asm_core_ctx.asm_dummy_gid2 == GRP_ID_INVALID && mmi_frm_group_is_in_dangle(evt->requester_id) == MMI_TRUE)
    {
        g_asm_core_ctx.asm_dummy_gid2 = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if (asm_core_process_reentry(ASM_CORE_STATE_BEGIN, (mmi_event_struct *)evt, (mmi_proc_func)post_prepare, NULL))
        return MMI_RET_OK;
#endif
    g_asm_core_ctx.req_info.requester_id        = evt->requester_id;

#ifdef __MMI_FRM_ASM_OOM_SCREEN__
    if (!evt->f_force_to_prepare && asm_core_process_priority(MMI_TRUE))
    {
        return MMI_RET_OK;
    }
#endif

    data.begin.requester_id         = evt->requester_id;
    data.begin.f_force_to_prepare   = evt->f_force_to_prepare;
    CHANGE_STATE(ASM_CORE_STATE_BEGIN, &data);
    mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid2);
    g_asm_core_ctx.asm_dummy_gid2 = GRP_ID_INVALID;
    return MMI_RET_OK;
}

MMI_BOOL mmi_frm_asm_prepare(
            mmi_id app_id, 
            U32 size, 
            mmi_proc_func prepare_cb, 
            void *user_data, 
            mmi_frm_asm_prepare_flag_type flag)
{
    asm_post_prepare_evt_struct evt;
    mmi_frm_asm_property_struct p;
    mmi_id root_id;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PREPARE, app_id, size, flag);
    root_id = mmi_frm_get_root_app(app_id);

    /* default reserve */
    mmi_frm_asm_get_property(root_id, &p);
    if (!p.f_prepare_w_reserve)
    {
        p.f_prepare_w_reserve = 1;
        mmi_frm_asm_set_property(root_id, &p);
    }
    g_asm_core_ctx.is_backward_prepare = MMI_FALSE;
    g_asm_core_ctx.is_unhide_prepare   = MMI_FALSE;
	g_asm_core_ctx.is_set_active_prepare = MMI_FALSE;
    size = (size == 0 ? PREPARE_REQ_MAX_SIZE : size);
    prepare_queue_put(app_id, size, size, prepare_cb, user_data, flag);
    MMI_FRM_INIT_EVENT(&evt, 0);
    evt.requester_id = app_id;
    evt.f_force_to_prepare = (flag & MMI_FRM_ASM_F_FORCE_PREPARE) == MMI_FRM_ASM_F_FORCE_PREPARE;
    MMI_FRM_POST_EVENT(&evt, (mmi_proc_func)post_prepare, NULL);
    return MMI_FALSE;
}


MMI_BOOL mmi_frm_asm_prepare_w_subsize(
            mmi_id app_id, 
            U32 total_size, 
            U32 continuous_subsize, 
            mmi_proc_func prepare_cb, 
            void *user_data, 
            mmi_frm_asm_prepare_flag_type flag)
{
    asm_post_prepare_evt_struct evt;
    mmi_frm_asm_property_struct p;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PREPARE_W_SUBSIZE, app_id, total_size, continuous_subsize, flag);

    /* default reserve */
    mmi_frm_asm_get_property(app_id, &p);
    if (!p.f_prepare_w_reserve)
    {
        p.f_prepare_w_reserve = 1;
        mmi_frm_asm_set_property(app_id, &p);
    }

    prepare_queue_put(app_id, total_size, continuous_subsize, prepare_cb, user_data, flag);
    MMI_FRM_INIT_EVENT(&evt, 0);
    evt.requester_id = app_id;
    evt.f_force_to_prepare = (flag & MMI_FRM_ASM_F_FORCE_PREPARE) == MMI_FRM_ASM_F_FORCE_PREPARE;
    MMI_FRM_POST_EVENT(&evt, (mmi_proc_func)post_prepare, NULL);
    return MMI_FALSE;
}

void mmi_frm_asm_cancel_prepare(mmi_id app_id, mmi_proc_func prepare_cb, void *user_data)
{
    /* cancel prepare request, may dismiss OOM dialog as well */
    mmi_frm_asm_prepare_queue_struct *q_ptr;

    q_ptr = prepare_queue_get_specific(app_id, prepare_cb, user_data);
    if (q_ptr)
    {
        // remove from prepare queue
        prepare_queue_free(q_ptr);

        // close OOM mgr if associate w/ this
        if (g_asm_core_ctx.req_info.requester_id == app_id) 
        {
        #ifdef __MMI_FRM_ASM_OOM_SCREEN__
            mmi_id app_mgr_id;
        #endif
            asm_core_state_data_struct data = {0};
		#ifdef __MMI_FRM_ASM_OOM_SCREEN__
            if (mmi_frm_asm_manager_is_launched(&app_mgr_id) &&
                (mmi_frm_asm_manager_get_app_id() == app_id))
            {
                mmi_frm_asm_manager_close(app_mgr_id);
            }
		#endif
            data.cancel.reason = MMI_FRM_ASM_CANCEL_BY_DEMAND;
            CHANGE_STATE(ASM_CORE_STATE_CANCEL, &data);
        }
    }
}


void *mmi_frm_asm_alloc_int(mmi_id app_id, U32 size, asm_alloc_flag alloc_flag, CHAR* file, U32 line)
{
    asm_data_struct *p_data = NULL;
    void *mem_ptr = NULL;
    applib_mem_chunk_info_struct chunk_info;
    mmi_id root_id;
    MMI_BOOL is_anonymous; 
	if (app_id == 0) app_id = g_asm_core_ctx.anonymous_gid;
	is_anonymous = (app_id == g_asm_core_ctx.anonymous_gid) ? MMI_TRUE : MMI_FALSE;

    ASM_CORE_LOCK;
    root_id = mmi_frm_get_root_app(app_id);
    /* app should be alive to allocate mem. */
    if (root_id != GRP_ID_INVALID)
    {
        p_data = mmi_frm_group_get_asm_data_ptr(root_id);
        if (p_data)
        {
            MMI_BOOL skip_size_checking;
            U32 remaining_quota;
            
            skip_size_checking  = IS_BIT_SET(p_data->flag, ASM_F_SKIP_SIZE_CHECKING) ? MMI_TRUE: MMI_FALSE;
            remaining_quota = get_remaining_quota(root_id);
    
            /* total allocate size should NOT exceed configured size */
            if (skip_size_checking ||
                (!skip_size_checking && (size <= APPLIB_MEM_AP_POOL_SIZE_CONFIG(remaining_quota))))
            {
                mmi_frm_appmem_disable_auto_prompt_screen();
                mem_ptr = applib_mem_ap_alloc_int(app_id, size, alloc_flag, file, line, is_anonymous);
                mmi_frm_appmem_enable_auto_prompt_screen();

                if (mem_ptr)
                {
                    /* update app's usage */
                    applib_mem_asm_get_chunk_info(mem_ptr, &chunk_info);
                    p_data->usage += chunk_info.chunk_size;
                }
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_INSUFFICIENT_QUOTA, app_id, size, APPLIB_MEM_AP_POOL_SIZE_CONFIG(remaining_quota), line);
                HistoryDump();
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_INVALID_ALLOCATOR, app_id, line);
        HistoryDump();
    }
    ASM_CORE_UNLOCK;
    return mem_ptr;
}


void mmi_frm_asm_free_int(mmi_id id, void *ptr, CHAR* file, U32 line)
{
    asm_data_struct *p_data = NULL;
    applib_mem_chunk_info_struct chunk_info;
    mmi_id root_id;
    MMI_BOOL is_anonymous;
	
	if (id == 0) id = g_asm_core_ctx.anonymous_gid;
	is_anonymous = (id == g_asm_core_ctx.anonymous_gid) ? MMI_TRUE : MMI_FALSE; 


    if (!ptr)
        return;

    ASM_CORE_LOCK;
    applib_mem_asm_get_chunk_info(ptr, &chunk_info);
    /* free in ASM pool */
    applib_mem_ap_free_thread_safe(ptr, file, line, is_anonymous);

    root_id = mmi_frm_get_root_app(chunk_info.owner_id);
    if (root_id != GRP_ID_INVALID)
    {
        if ((p_data = mmi_frm_group_get_asm_data_ptr(root_id)) != NULL)
        {
            p_data->usage -= chunk_info.chunk_size;  /* decrease app's usage */
        }
    }
    ASM_CORE_UNLOCK;
}

void *mmi_frm_asm_alloc_anonymous_int(U32 size, asm_alloc_flag alloc_flag, CHAR* file, U32 line)
{
    ASMC_ASSERT(g_asm_core_ctx.anonymous_gid != GRP_ID_INVALID);
    if (MMI_TRUE == mmi_frm_appmem_is_in_first_stage())
    {
        return applib_mem_ap_alloc_int(
            g_asm_core_ctx.anonymous_gid,
            size,
            alloc_flag,
            file,
            line,
            KAL_TRUE);
    }
    else
    {
        return mmi_frm_asm_alloc_int(g_asm_core_ctx.anonymous_gid, size,alloc_flag, file, line);
    }
}

void mmi_frm_asm_free_anonymous_int(void *ptr, CHAR* file, U32 line)
{
    ASMC_ASSERT(g_asm_core_ctx.anonymous_gid != GRP_ID_INVALID);

    if (MMI_TRUE == mmi_frm_appmem_is_in_first_stage())
    {
        applib_mem_ap_free_thread_safe(ptr, file, line, KAL_TRUE);
    }
    else
    {
        mmi_frm_asm_free_int(g_asm_core_ctx.anonymous_gid, ptr, file, line);
    }
}


U32 mmi_frm_asm_get_max_alloc_anonymous(void)
{
    ASMC_ASSERT(g_asm_core_ctx.anonymous_gid != GRP_ID_INVALID);    
    return mmi_frm_asm_get_max_alloc_size_r(g_asm_core_ctx.anonymous_gid);
}

static U32 get_anonymous_quota()
{
    U32 quota;
    asm_data_struct *p_data = NULL;
    p_data = mmi_frm_group_get_asm_data_ptr(g_asm_core_ctx.anonymous_gid);
    if (p_data)
    {
       if (GDI_ASM_MEM_SIZE > p_data->usage)
       {
           quota = GDI_ASM_MEM_SIZE-p_data->usage;
       }
       else
       {
           quota = 0;
       }
    }
    else
    {
        quota = GDI_ASM_MEM_SIZE;
    }
    return quota;
}

U32 mmi_frm_asm_get_total_left_size_r(mmi_id id)
{
    U32 result, reserved_size;
#if defined __MMI_USE_MMV2__
    U32 global_reserve;
#endif
    mmi_id root_id;
    asm_data_struct *p_data = NULL;
    
    ASM_CORE_LOCK;
    result = applib_mem_ap_get_total_left_size_int();
    result += applib_mem_ap_cache_get_size();   /* add cache size since we can free it while allocating */
    if ((root_id = mmi_frm_get_root_app(id)) != GRP_ID_INVALID)
        p_data = mmi_frm_group_get_asm_data_ptr(root_id);

#if defined __MMI_USE_MMV2__ 
    mmi_frm_asm_get_reserve_size(&reserved_size, &global_reserve);
    if (p_data && IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE))
    {
        /* remaining quota is add in reserved_size, let's remove it */       
        reserved_size -= get_remaining_quota(root_id);
    }
    if (!p_data || !IS_BIT_SET(p_data->flag, ASM_F_SKIP_RESERVE_CHECKING))
    {
        result = (result > reserved_size) ? result - reserved_size : 0;
    }
    else
    {   /*for id that skip reserve checking (i.e. anomyous), 
          it can ignore the reserved space in asm common pool but not in global pool*/
        result = (result > global_reserve) ? result - global_reserve : 0;
    }
#else
    if (p_data && IS_BIT_SET(p_data->flag, ASM_F_PREPARE_W_RESERVE))
    {
        /* max alloc = total left - reserved + remaining quota.
           remaining quota is to add back same size counted in reserved */
        result += get_remaining_quota(root_id);
    }

    if (!p_data || !IS_BIT_SET(p_data->flag, ASM_F_SKIP_RESERVE_CHECKING))
    {
        mmi_frm_asm_get_reserve_size(&reserved_size, NULL);
        result = (result > reserved_size) ? result - reserved_size : 0;
    }
#endif
    ASM_CORE_UNLOCK;

    return result;    
}


U32 mmi_frm_asm_get_max_alloc_size_r(mmi_id id)
{
    U32 total_left = 0, max_alloc = 0, result = 0;
    
    ASM_CORE_LOCK;
    total_left = mmi_frm_asm_get_total_left_size_r(id);
    max_alloc = applib_mem_ap_get_max_alloc_size_int();

    /* get the min. one */
    result = (max_alloc > total_left) ? total_left : max_alloc;
    //ASMC_TRACE(MMI_FRM_ASM_GET_MAX_ALLOC_SIZE, "[ASM][core] get max alloc of %d = min (%d, %d)\n", id, total_left, max_alloc);
    ASM_CORE_UNLOCK;

    return result;
}


MMI_BOOL mmi_frm_asm_check_enough(mmi_id id, U32 size)
{
    return check_enough_by_ID (id, size, size);
}

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
U32 mmi_frm_asm_check_enough_with_subsize(mmi_id id, U32 total_size, U32 continuous_subsize)
    {
    return check_enough_by_ID (id, total_size, continuous_subsize);
}

void mmi_frm_asm_app_hide(MMI_ID app_id)
{
	mmi_frm_group_hide(app_id);
}

void mmi_frm_asm_app_unhide(MMI_ID app_id)
{
	g_asm_core_ctx.asm_dummy_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, asm_core_proc, (void *)'FAWD');
	mmi_frm_group_enter(g_asm_core_ctx.asm_dummy_gid, MMI_FRM_NODE_NONE_FLAG);
	g_asm_core_ctx.is_unhide_prepare = MMI_TRUE;
	if(asm_prepare(app_id, ASM_UNHIDE_PREPARE))
	{
		mmi_frm_group_unhide(app_id);
		mmi_frm_group_close(g_asm_core_ctx.asm_dummy_gid);
		g_asm_core_ctx.is_unhide_prepare = MMI_FALSE;
	}
}

/***************************************************************************** 
 * FUNCTION
 *  mmi_frm_asm_get_asm_state
 * DESCRIPTION
 *  Get asm state.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the state
 **************************************************************************/
U16 mmi_frm_asm_get_asm_state(void)
{       
	if(g_asm_core_ctx.wait_type != ASM_CORE_WAIT_NONE)
	{
		return MMI_FRM_ASM_IS_WAITING_APP_STOP;
	}
	else if (g_asm_core_ctx.current_state != ASM_CORE_STATE_NONE)
	{
		return MMI_FRM_ASM_IS_PREPARING_MEMORY;
	}
	else
	{
		return MMI_FRM_ASM_NOT_PREPARE_MEMORY;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_stop_app_by_MMI_task
 * DESCRIPTION
 *  Stop an application. This function must be invoked by MMI task only.
 *  (The API is used by MMI framework only)
 * PARAMETERS
 *  app_id:    [IN]    ID of the application to be stopped
 *	stop_type: [IN]    type of stopping
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_asm_stop_app_by_MMI_task(kal_uint32 app_id, applib_mem_ap_stop_type stop_type)
{       
	if (g_asm_core_ctx.current_state == ASM_CORE_STATE_FREE_SELECTED)
	{
		asm_core_state_data_struct new_data = {0};
		
		new_data.wait.type = ASM_CORE_WAIT_SELECTED;
		CHANGE_STATE(ASM_CORE_STATE_WAIT, &new_data);			
	}
	
	applib_mem_ap_stop_app_by_MMI_task(app_id, stop_type);
}



U32 mmi_frm_asm_get_asm_usage(MMI_ID requester_id, applib_mem_ap_usage_struct *applist, MMI_BOOL inc_hide, MMI_BOOL skip_v10)
{
    return mmi_frm_asm_get_asm_usage_ex(requester_id, g_asm_core_ctx.requester_bind_id, applist, inc_hide, skip_v10);
}


#ifdef __MMI_ASM_OOM_AUTO_KILL__ 
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
extern void mmi_frm_asm_set_app_priority(mmi_id app_id, U32 priority)
{
    mmi_id root_id;
    asm_data_struct *p_data = NULL;
    
	ASM_CORE_LOCK;

	if(priority > 255)
	{
		priority = 255;
	}

    root_id = mmi_frm_get_root_app(app_id);
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
      
    if(p_data)
	{
	    p_data->mem_prio = priority;
        MMI_PRINT(MOD_MMI_FW,MMI_FW_TRC_G1_FRM,"[ASM] set priority, app_id: %d, priority: %d", app_id, p_data->mem_prio);
	}

    ASM_CORE_UNLOCK;


}

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
extern U32 mmi_frm_asm_get_app_priority(mmi_id app_id)
{
    mmi_id root_id;
    asm_data_struct *p_data = NULL;
    U32 priority = MMI_FRM_APP_MEM_PRIORITY_DEFAULT;
    
	ASM_CORE_LOCK;

    root_id = mmi_frm_get_root_app(app_id);
    p_data = mmi_frm_group_get_asm_data_ptr(root_id);
      
    if(p_data)
	{
	    priority = p_data->mem_prio;
	}

    ASM_CORE_UNLOCK;
    return priority;


}
#endif

#if defined(__MMI_UCM_SLIM__) && defined(__COSMOS_MMI_PACKAGE__)
static mmi_scenario_id mmi_frm_asm_is_call_exist_get_priority(mmi_scenario_id before)
{
    if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_INCOMING_CALL))
    {
        return MMI_SCENARIO_ID_UCM_INCOMING_CALL;
    }
	else if (mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_OUTGOING_CALL))
	{
		return MMI_SCENARIO_ID_UCM_OUTGOING_CALL;
	}
	return before;
}
#endif /* __MMI_UCM_SLIM__ && __COSMOS_MMI_PACKAGE__ */

#ifdef APPLIB_MEM_UNIT_TEST
/***************************************************************************** 
 * Unit Test 
 *****************************************************************************/
void test_prepare_queue_get_total_size_int(void)
{
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);

	/* There is no one to do prepare */
	ASSERT(0 == prepare_queue_get_total_size_int(0x1000, MMI_TRUE));
	ASSERT(0 == prepare_queue_get_total_size_int(0x1000, MMI_FALSE));
	
	prepare_queue_put(0x1000, 1000,  500, NULL, NULL, 0);
	mmi_frm_group_close(0x2000);

	/* someone has done the prepare but ID is not match */
    ASSERT(0 == prepare_queue_get_total_size_int(0x2000, MMI_TRUE));
	ASSERT(0 == prepare_queue_get_total_size_int(0x2000, MMI_TRUE));

    /* check size and continuous sub size */
	ASSERT(1000 == prepare_queue_get_total_size_int(0x1000, MMI_FALSE));
	ASSERT(500 == prepare_queue_get_total_size_int(0x1000, MMI_TRUE));

	mmi_frm_group_create_ex(0x1000, 0x2000, NULL, NULL, 0);

	/* use sub group id to prepare case */
	prepare_queue_put(0x2000, 2500, 1000, NULL, NULL, 0);

	/* need to add all that's root id are same */
	ASSERT(3500 == prepare_queue_get_total_size_int(0x1000, MMI_FALSE));
	ASSERT(1500 == prepare_queue_get_total_size_int(0x1000, MMI_TRUE));

	/* if one of them's prepare size is PREPARE_REQ_MAX_SIZE, the size should be PREPARE_REQ_MAX_SIZE */
	prepare_queue_put(0x1000, PREPARE_REQ_MAX_SIZE,  PREPARE_REQ_MAX_SIZE, NULL, NULL, 0);
	ASSERT(PREPARE_REQ_MAX_SIZE == prepare_queue_get_total_size_int(0x1000, MMI_FALSE));
	ASSERT(PREPARE_REQ_MAX_SIZE == prepare_queue_get_total_size_int(0x1000, MMI_TRUE));
	
	prepare_queue_free(prepare_queue_get(0x2000));
	prepare_queue_free(prepare_queue_get(0x1000));
	prepare_queue_free(prepare_queue_get(0x1000));

	/* make sure prepare queue is empty */
	ASSERT(0 == prepare_queue_get_total_size_int(0x1000, MMI_TRUE));
	ASSERT(0 == prepare_queue_get_total_size_int(0x1000, MMI_FALSE));

	mmi_frm_group_close(0x1000);
}
/*
 * To test this function please put
 * {0x1000, 0x1050, STR_GLOBAL_0, 5 * 1024,  10 * 1024, 3 * 1024, 1 * 1024, 0.5},
 * at the beginning of mmi_app_info[] in mmi_rp_app_data.c
 */
void test_get_prepare_size_int(void)
{
    asm_data_struct *pdata;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
    mmi_frm_group_create_ex(GRP_ID_ROOT, 0x1000, NULL, NULL, 0);

	ASSERT(5 * 1024 + 10 * 1024 == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_FALSE));
	ASSERT(12 * 1024 == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_TRUE));
	
	pdata = mmi_frm_group_get_asm_data_ptr(0x1000);
	pdata->usage = 1 * 1024;
	ASSERT(14 * 1024  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_FALSE));
	ASSERT(12 * 1024  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_TRUE));
	
	pdata->usage = 12 * 1024;
	ASSERT(3 * 1024  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_FALSE));
	ASSERT(3 * 1024  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_TRUE));
	p.f_prepare_w_reserve = 1;
	mmi_frm_asm_set_property(0x1000, &p);
	ASSERT(MMI_FRM_ASM_SIZE_PLUS_EXTRA(3 * 1024)  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_FALSE));
	
	p.f_prepare_w_reserve = 0;
	mmi_frm_asm_set_property(0x1000, &p);
    prepare_queue_put(0x1000, PREPARE_REQ_MAX_SIZE,  PREPARE_REQ_MAX_SIZE, NULL, NULL, 0);

	ASSERT(3 * 1024  == get_prepare_size_int(0x1000, PREPARE_REQ_MAX_SIZE, MMI_FALSE));
	prepare_queue_free(prepare_queue_get(0x1000));
	
	prepare_queue_put(0x1000, 1024,  512, NULL, NULL, 0);
	ASSERT(1024  == get_prepare_size_int(0x1000, 15, MMI_FALSE));
	prepare_queue_put(0x1000, 3 * 1024,  512, NULL, NULL, 0);
	ASSERT(3 * 1024  == get_prepare_size_int(0x1000, 15, MMI_FALSE));

	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(0x1000, &p);
	ASSERT(4 * 1024  == get_prepare_size_int(0x1000, 15, MMI_FALSE));
	prepare_queue_free(prepare_queue_get(0x1000));
	prepare_queue_free(prepare_queue_get(0x1000));
	pdata->usage = 0;
	mmi_frm_group_close(0x1000);
}

typedef enum
{
    SYNC_FREE,
	ACTION_NONE
} asm_test_action_enum;
typedef struct
{
    MMI_ID app_id;
	void *ptr;
	asm_test_action_enum action;
} asm_test_grp_cntx;

static MMI_RET scrn_group_proc_for_asm_test(mmi_event_struct *evt)
{
    asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)evt->user_data;
	mmi_scenario_evt_struct *p = (mmi_scenario_evt_struct *)evt;
	switch (evt->evt_id)
	{
	    case EVT_ID_ASM_FREE_REQ_NO_WAIT:
			ASSERT(cntx != NULL);
			ASSERT(cntx->app_id != 4000);
			ASSERT(cntx->app_id != 5000);
			if (cntx->action == SYNC_FREE)
			{
			    mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
			}
			break;

		case EVT_ID_ASM_FREE_REQ:
			ASSERT(cntx != NULL);
			ASSERT(cntx->app_id != 4000);
			ASSERT(cntx->app_id != 5000);
			if (cntx->action == SYNC_FREE)
			{
			    mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
			}
			break;

		case EVT_ID_ASM_FORCE_FREE:
			ASSERT(cntx != NULL);
			ASSERT(cntx->app_id != 4000);
			ASSERT(cntx->app_id != 5000);
			if (cntx->action == SYNC_FREE)
			{
			    mmi_frm_asm_free_r(cntx->app_id, cntx->ptr);
				cntx->ptr = NULL;
			}
			break;			
		case EVT_ID_GROUP_ENTER:
			ASSERT(cntx == NULL);
			cntx = (asm_test_grp_cntx *)mmi_malloc(sizeof(asm_test_grp_cntx));
			cntx->app_id = p->targ_group;
			cntx->ptr = NULL;
			mmi_frm_group_set_user_data(p->targ_group, (void *)cntx);
			break;

		case EVT_ID_GROUP_DEINIT:
			mmi_mfree(cntx);
			break;
	}
    return MMI_RET_OK;
}

void asm_test_v10_stop_callback(kal_uint16 app_id, applib_mem_ap_stop_type stop_type)
{
    switch (stop_type)
    {
        case MEM_AP_STOP_TYPE_NO_WAIT:
		case MEM_AP_STOP_TYPE_REQ:
			ASSERT(0);
			break;
		case MEM_AP_STOP_TYPE_FORCE:
			applib_mem_ap_free_all(app_id);
			break;
    }
}

static void set_ptr(MMI_ID app_id, void *ptr)
{
	asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)mmi_frm_group_get_user_data(app_id);
	if (cntx != NULL)
	{
		ASSERT(app_id == cntx->app_id);
		cntx->ptr = ptr;
	}
	else
	{
		ASSERT(0);
	}
}

static void set_action(MMI_ID app_id, asm_test_action_enum action)
{
	asm_test_grp_cntx *cntx = (asm_test_grp_cntx *)mmi_frm_group_get_user_data(app_id);
	if (cntx != NULL)
	{
		ASSERT(app_id == cntx->app_id);
		cntx->action = action;
	}
	else
	{
		ASSERT(0);
	}
}



void test_do_free_volunteers_no_wait(void)
{
    U32 total_size = 0;
	void *ptr = NULL;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	asm_test_grp_cntx *cntx;

	/* create three apps for test */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);

	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

	/* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* make sure we can get the max anonymous size */
	total_size = mmi_frm_asm_get_max_alloc_anonymous();
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	/* because we don't do the config in res, skip the size check */
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(1000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(3000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	/* sync free all these three apps, memory should be enough */
	ASSERT(1 == do_free_volunteers_no_wait(ASM_ANONYMOUS_ID, GRP_ID_INVALID, total_size , total_size));

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create a new app, make it same as anonymous */
    mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	p.f_skip_reserve_checking = 1;
	mmi_frm_asm_set_property(4000, &p);

    /* allocate memory and set action for the apps */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ACTION_NONE);
	
    /* sync free memory for app 4000, should not enough and 4000's memory should not be freed */
	ASSERT(0 == do_free_volunteers_no_wait(4000, GRP_ID_INVALID, total_size, total_size));
	cntx = mmi_frm_group_get_user_data(4000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(4000, cntx->ptr);
	cntx->ptr = NULL;

    /* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* check allocate max size */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create app 5 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 5000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(5000, &p);

    /* alloc memory and set action */
	ptr = mmi_frm_asm_alloc_r(5000, 500 * 1024);
	set_ptr(5000, ptr);
	set_action(5000, ACTION_NONE);
	
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
	ASSERT(0 == do_free_volunteers_no_wait(ASM_ANONYMOUS_ID, 5000, total_size , total_size));

    /* check bind app */
	cntx = mmi_frm_group_get_user_data(5000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(5000, cntx->ptr);
	cntx->ptr = NULL;

	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* register an v10 app */
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        (FuncPtr)asm_test_v10_stop_callback);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 500 * 1024);

	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
	ASSERT(0 == do_free_volunteers_no_wait(ASM_ANONYMOUS_ID, GRP_ID_INVALID, total_size , total_size));

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
	
	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


	p.f_hide_in_oom = 1;
	mmi_frm_asm_set_property(3000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(1000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	/* sync free all these three apps, memory should be enough */
	ASSERT(1 == do_free_volunteers_no_wait(ASM_ANONYMOUS_ID, GRP_ID_INVALID, total_size , total_size));

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


	mmi_frm_group_close(1000);
	mmi_frm_group_close(2000);
	mmi_frm_group_close(3000);
	mmi_frm_group_close(4000);
	mmi_frm_group_close(5000);
}

void test_do_prepare_free_volunteers_int(void)
{
    U32 total_size = 0;
	void *ptr = NULL;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	asm_test_grp_cntx *cntx;
	asm_core_state_data_struct data;
	/* create three apps for test */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);

	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

	/* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* make sure we can get the max anonymous size */
	total_size = mmi_frm_asm_get_max_alloc_anonymous();
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	/* because we don't do the config in res, skip the size check */
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(1000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(3000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	ASSERT(2 == do_prepare_free_volunteers_int(ASM_ANONYMOUS_ID, &data));
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	
	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create a new app, make it same as anonymous */
    mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	p.f_skip_reserve_checking = 1;
	mmi_frm_asm_set_property(4000, &p);

    /* allocate memory and set action for the apps */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ACTION_NONE);
	
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = 4000;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	ASSERT(2 == do_prepare_free_volunteers_int(4000, &data));
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;
	
	cntx = mmi_frm_group_get_user_data(4000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(4000, cntx->ptr);
	cntx->ptr = NULL;

    /* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* check allocate max size */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


    /* create app 5 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 5000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(5000, &p);

	g_asm_core_ctx.requester_bind_id = 5000;
	
    /* alloc memory and set action */
	ptr = mmi_frm_asm_alloc_r(5000, 500 * 1024);
	set_ptr(5000, ptr);
	set_action(5000, ACTION_NONE);
	
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	ASSERT(2 == do_prepare_free_volunteers_int(ASM_ANONYMOUS_ID, &data));
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;


    /* check bind app */
	cntx = mmi_frm_group_get_user_data(5000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(5000, cntx->ptr);
	cntx->ptr = NULL;

	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* register an v10 app */
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        (FuncPtr)asm_test_v10_stop_callback);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 500 * 1024);

	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	ASSERT(2 == do_prepare_free_volunteers_int(ASM_ANONYMOUS_ID, &data));
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
	
	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	p.f_hide_in_oom = 1;
	mmi_frm_asm_set_property(3000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(1000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	ASSERT(2 == do_prepare_free_volunteers_int(ASM_ANONYMOUS_ID, &data));
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


	mmi_frm_group_close(1000);
	mmi_frm_group_close(2000);
	mmi_frm_group_close(3000);
	mmi_frm_group_close(4000);
	mmi_frm_group_close(5000);    
}


void test_asm_core_v10_release_mem_int(applib_mem_ap_stop_type type)
{
    U32 total_size = 0;
	void *ptr = NULL;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	asm_test_grp_cntx *cntx;
	asm_core_state_data_struct data;

	test_single_action_only = MMI_TRUE;
	
	/* create three apps for test */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);

	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

	/* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* make sure we can get the max anonymous size */
	total_size = mmi_frm_asm_get_max_alloc_anonymous();
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	/* because we don't do the config in res, skip the size check */
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(1000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(3000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);
	
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	asm_core_v10_release_mem(type);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create a new app, make it same as anonymous */
    mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	p.f_skip_reserve_checking = 1;
	mmi_frm_asm_set_property(4000, &p);

    /* allocate memory and set action for the apps */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ACTION_NONE);
	
	g_asm_core_ctx.req_info.requester_id = 4000;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	asm_core_v10_release_mem(type);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;
	
	cntx = mmi_frm_group_get_user_data(4000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(4000, cntx->ptr);
	cntx->ptr = NULL;

    /* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* check allocate max size */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create app 5 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 5000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(5000, &p);

	g_asm_core_ctx.requester_bind_id = 5000;
	
    /* alloc memory and set action */
	ptr = mmi_frm_asm_alloc_r(5000, 500 * 1024);
	set_ptr(5000, ptr);
	set_action(5000, ACTION_NONE);
	
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	asm_core_v10_release_mem(type);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	test_single_action_only = MMI_FALSE;


    /* check bind app */
	cntx = mmi_frm_group_get_user_data(5000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(5000, cntx->ptr);
	cntx->ptr = NULL;

	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* register an v10 app */
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        (FuncPtr)asm_test_v10_stop_callback);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 500 * 1024);

	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_VOLUNTEERS;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	asm_core_v10_release_mem(type);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	test_single_action_only = MMI_FALSE;

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
	
	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	p.f_hide_in_oom = 1;
	mmi_frm_asm_set_property(3000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(1000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	asm_core_v10_release_mem(type);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	test_single_action_only = MMI_FALSE;

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	mmi_frm_group_close(1000);
	mmi_frm_group_close(2000);
	mmi_frm_group_close(3000);
	mmi_frm_group_close(4000);
	mmi_frm_group_close(5000);
	test_single_action_only = MMI_FALSE;

}
void test_asm_core_v10_release_mem()
{
    test_asm_core_v10_release_mem_int(MEM_AP_STOP_TYPE_REQ);
}

void test_asm_core_v10_release_mem_force()
{
	test_asm_core_v10_release_mem_int(MEM_AP_STOP_TYPE_FORCE);
}

void test_do_prepare_free_in_used()
{
    U32 total_size = 0;
	void *ptr = NULL;
	mmi_frm_asm_property_struct p = {0, 0, 0, 0, 0};
	asm_test_grp_cntx *cntx;
	asm_core_state_data_struct data;
	/* create three apps for test */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 1000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 2000, scrn_group_proc_for_asm_test, NULL, 0);
	mmi_frm_group_create_ex(GRP_ID_ROOT, 3000, scrn_group_proc_for_asm_test, NULL, 0);

	/* need to clean up cache memory, make sure the ASM pool is empty */
	applib_mem_ap_free_all_cache();

	/* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* make sure we can get the max anonymous size */
	total_size = mmi_frm_asm_get_max_alloc_anonymous();
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	/* because we don't do the config in res, skip the size check */
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(1000, &p);
	mmi_frm_asm_set_property(2000, &p);
	mmi_frm_asm_set_property(3000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_IN_USED;
	/* sync free all these three apps, memory should be enough */
	do_prepare_free_in_used(ASM_ANONYMOUS_ID, &data);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	
	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* create a new app, make it same as anonymous */
    mmi_frm_group_create_ex(GRP_ID_ROOT, 4000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	p.f_skip_reserve_checking = 1;
	mmi_frm_asm_set_property(4000, &p);

    /* allocate memory and set action for the apps */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(4000, 500 * 1024);
	set_ptr(4000, ptr);
	set_action(4000, ACTION_NONE);
	
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = 4000;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_IN_USED;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	do_prepare_free_in_used(4000, &data);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;
	
	cntx = mmi_frm_group_get_user_data(4000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(4000, cntx->ptr);
	cntx->ptr = NULL;

    /* check allocation count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* check allocate max size */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


    /* create app 5 */
	mmi_frm_group_create_ex(GRP_ID_ROOT, 5000, scrn_group_proc_for_asm_test, NULL, 0);
	p.f_skip_size_checking = 1;
	mmi_frm_asm_set_property(5000, &p);

	g_asm_core_ctx.requester_bind_id = 5000;
	
    /* alloc memory and set action */
	ptr = mmi_frm_asm_alloc_r(5000, 500 * 1024);
	set_ptr(5000, ptr);
	set_action(5000, ACTION_NONE);
	
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);

	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_IN_USED;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	do_prepare_free_in_used(ASM_ANONYMOUS_ID, &data);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;


    /* check bind app */
	cntx = mmi_frm_group_get_user_data(5000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(5000, cntx->ptr);
	cntx->ptr = NULL;

	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

    /* register an v10 app */
	applib_mem_ap_register(
        APPLIB_MEM_AP_ID_TEST1, 
        STR_GLOBAL_1, 
        IMG_GLOBAL_L1, 
        (FuncPtr)asm_test_v10_stop_callback);
	applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, 500 * 1024);

	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_IN_USED;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	do_prepare_free_in_used(ASM_ANONYMOUS_ID, &data);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;
	
	/* check allocate count */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);

	p.f_hide_in_oom = 1;
	mmi_frm_asm_set_property(3000, &p);

	/* alloc memory for the three apps and set the action as sync free */
	ptr = mmi_frm_asm_alloc_r(1000, 500 * 1024);
	set_ptr(1000, ptr);
	set_action(1000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(2000, 500 * 1024);
	set_ptr(2000, ptr);
	set_action(2000, SYNC_FREE);
	ptr = mmi_frm_asm_alloc_r(3000, 500 * 1024);
	set_ptr(3000, ptr);
	set_action(3000, SYNC_FREE);

    /* call free */
    data.free.wait_type = ASM_CORE_WAIT_NONE;
	g_asm_core_ctx.req_info.requester_id = ASM_ANONYMOUS_ID;
	g_asm_core_ctx.req_info.required_size = total_size;
	g_asm_core_ctx.req_info.required_subsize_continuous = total_size;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_FREE_IN_USED;
	/* sync free all these three apps, memory should be enough */
	test_single_action_only = MMI_TRUE;
	do_prepare_free_in_used(ASM_ANONYMOUS_ID, &data);
	g_asm_core_ctx.req_info.required_size = 0;
	g_asm_core_ctx.req_info.required_subsize_continuous = 0;
	g_asm_core_ctx.req_info.requester_id = 0;
	g_asm_core_ctx.current_state = ASM_CORE_STATE_NONE;
	test_single_action_only = MMI_FALSE;
	
	cntx = mmi_frm_group_get_user_data(3000);
	ASSERT(cntx->ptr != NULL);
	mmi_frm_asm_free_r(3000, cntx->ptr);
	cntx->ptr = NULL;

	/* check allocation count again */
	ASSERT(applib_mem_ap_get_alloc_count() == 0);

	/* do allocation check */
	ptr = mmi_frm_asm_alloc_anonymous(total_size);
	ASSERT(ptr != NULL);
	mmi_frm_asm_free_anonymous(ptr);


	mmi_frm_group_close(1000);
	mmi_frm_group_close(2000);
	mmi_frm_group_close(3000);
	mmi_frm_group_close(4000);
	mmi_frm_group_close(5000);        
}


#endif

