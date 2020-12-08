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

/*******************************************************************************
 * Filename:
 * ---------
 * UMSprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef UM_SRV_PROT_H
#define UM_SRV_PROT_H


/**********  KAL Layer Header **************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "customer_ps_inc.h"
#include "lcd_sw_inc.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Gui_Setting.h"
#include "gui_switch.h"
#include "wgui.h"
#include "mmi_msg_context.h"
#include "Custom_ProvBox.h"
#include "custom_wap_config.h"

#include "UmSrvDefs.h"
#include "UmSrvStruct.h"
#include "UmSrvGprot.h"

/************************************************************************/
/* Macro definition or Constant definition                              */
/************************************************************************/
#define SRV_UM_MAX_MSG_PER_PAGE     MMI_MAX_MENUITEMS_IN_CONTENT    /* Max number of messages */

#if defined(__MMI_MSG_UM_LOW_MEMORY_COST__) && defined(__MMI_UM_SLIM__)
#define SRV_UM_MIN_MSG_DETAIL_NUM   MMI_MAX_MENUITEMS_IN_CONTENT
#else
#define SRV_UM_MIN_MSG_DETAIL_NUM   MMI_MAX_MENUITEMS_IN_CONTENT * 3
#endif

#define SRV_UM_LIST_TIMESTAMP_MEMORY (sizeof(U32) * SRV_UM_MAX_MSG_NUM)
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
#define SRV_UM_LIST_IDX_DATA_MEMORY (sizeof(srv_um_list_idx_data_union) * SRV_UM_MAX_MSG_NUM)
#else
#define SRV_UM_LIST_IDX_DATA_MEMORY 0
#endif
#define SRV_UM_LIST_SORT_MEMORY (SRV_UM_LIST_TIMESTAMP_MEMORY + SRV_UM_LIST_IDX_DATA_MEMORY)

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
#define PROCESS_TYPE_DEF_MARK_SEVERAL() PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_MARK_SEVERAL_OP, mark_several_op)
#else
#define PROCESS_TYPE_DEF_MARK_SEVERAL()
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#define PROCESS_TYPE_DEF_TRAVERSE_MSG() PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_TRAVERSE_MSG, traverse_msg)
#define PROCESS_TYPE_DEF_GET_THREAD_LIST() PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_GET_THREAD_LIST, get_thread_list)
#define PROCESS_TYPE_DEF_GET_THREAD_INFO() PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_GET_THREAD_INFO, get_thread_info)
#else
#define PROCESS_TYPE_DEF_TRAVERSE_MSG()
#define PROCESS_TYPE_DEF_GET_THREAD_LIST()
#define PROCESS_TYPE_DEF_GET_THREAD_INFO()
#endif

#if defined(__SRV_UM_THREAD_MESSAGE_SUPPORT__) && defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__)
#define PROCESS_TYPE_DEF_MARK_SEVERAL_THREAD() PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_MARK_SEVERAL_THREAD_OP, mark_several_thread_op)
#else
#define PROCESS_TYPE_DEF_MARK_SEVERAL_THREAD()
#endif

/* sequence of definition must be sam as ums_process_type_enum */
#define ALL_PROCESS_TYPE_DEF \
    PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_GET_MSG_NUM, get_msg_num)			\
    PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_GET_MSG_LIST, get_msg_list)			\
    PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_GET_MSG_INFO, get_msg_info)			\
    PROCESS_TYPE_DEF_MARK_SEVERAL()                                             \
    PROCESS_TYPE_DEF_TRAVERSE_MSG()                                             \
    PROCESS_TYPE_DEF_GET_THREAD_LIST()                                          \
    PROCESS_TYPE_DEF_GET_THREAD_INFO()                                          \
    PROCESS_TYPE_DEF_MARK_SEVERAL_THREAD()                                      \
    PROCESS_TYPE_BASIC_DEF(UMS_PROCESS_TYPE_DELETE_FOLDER, delete_folder)

#define REQ_HANDLER(tag)    srv_um_##tag##_req
#define RSP_HANDLER(tag)    srv_um_##tag##_rsp
#define PARA_STRUCT(tag)    ums_##tag##_para_struct
#define CNTX_STRUCT(tag)    ums_##tag##_cntx_struct
#define RESULT_STRUCT(tag)  srv_um_##tag##_result
#define RSP_STRUCT(tag)     srv_um_##tag##_rsp_struct

/************************************************************************/
/* Enumaration                                                          */
/************************************************************************/
typedef enum
{
    UMS_PROCESS_TYPE_GET_MSG_NUM,
    UMS_PROCESS_TYPE_GET_MSG_LIST,
    UMS_PROCESS_TYPE_GET_MSG_INFO,
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    UMS_PROCESS_TYPE_MARK_SEVERAL_OP,
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    UMS_PROCESS_TYPE_TRAVERSE_MSG,
    UMS_PROCESS_TYPE_GET_THREAD_LIST,
    UMS_PROCESS_TYPE_GET_THREAD_INFO,
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    UMS_PROCESS_TYPE_MARK_SEVERAL_THREAD_OP,
#endif
#endif
    UMS_PROCESS_TYPE_DELETE_FOLDER,
    UMS_PROCESS_TYPE_MAX
} ums_process_type_enum;

typedef enum
{
    UMS_PROCESS_PRIORITY_NONE = 0,
    UMS_PROCESS_PRIORITY_HIGHEST = 1,
    UMS_PROCESS_PRIORITY_DEFAULT = 100,
    UMS_RPOCESS_PRIORITY_MEDIUM = 100,
    UMS_PROCESS_PRIORITY_LOWEST = 255
} ums_process_priority_enum;

typedef enum
{
    UMS_PROCESS_STATUS_INIT         = 0x00,
    UMS_PROCESS_STATUS_READY        = 0x01,
    UMS_PROCESS_STATUS_RUNNING      = 0x02,     /* cannot use with other status */
    UMS_PROCESS_STATUS_WAITING      = 0x04,
    UMS_PROCESS_STATUS_CANCELLING   = 0x08,     /* can use with other status */
    UMS_PROCESS_STATUS_RESET        = 0x10,     /* can use with other status */
    UMS_PROCESS_STATUS_FINISHED     = 0x20      /* cannot use with other status */
} ums_process_status_enum;

/************************************************************************/
/* Structure declaration                                                */
/************************************************************************/
typedef struct
{
    srv_um_general_cb cb_func;
    S32 user_data;
} ums_general_para_struct;

typedef struct
{
    srv_um_get_msg_num_cb cb_func;
    S32 user_data;
    srv_um_msg_enum msg_type;
    srv_um_sim_enum sim_id;
} ums_get_msg_num_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
} ums_get_msg_num_cntx_struct;

typedef struct
{
    U32 timestamp;
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_um_list_idx_data_union list_idx_data;
#endif
} ums_get_list_sort_idx;

typedef struct
{
    srv_um_get_list_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_list_filter_struct filter;
} ums_get_list_para_struct;

typedef ums_get_list_para_struct ums_get_msg_list_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    srv_um_msg_node_struct *msg_list;
    U16 msg_list_size;
    S32 list_cntx_id;
    U32 *timestamp_idx_data;
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_um_list_idx_data_union *list_idx_data;
#endif
    ums_get_list_sort_idx *sort_idx_data;
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_info_struct thread_info;
    U32 thread_head_timestamp;
#endif
    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE];
} ums_get_msg_list_cntx_struct;

typedef struct
{
    srv_um_get_msg_info_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_msg_node_struct *msg_list;
    U16 msg_number;
} ums_get_msg_info_para_struct;

#ifdef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    U16 req_msg_number;
} ums_get_msg_info_cntx_struct;

#else

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    U16 running_msg_number;
    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE];
} ums_get_msg_info_cntx_struct;

#endif

typedef struct
{
    srv_um_delete_folder_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
} ums_delete_folder_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
} ums_delete_folder_cntx_struct;

typedef struct
{
    srv_um_mark_several_op_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_msg_node_struct *msg_list;
    U16 msg_list_size;
    U32 mark_status[(SRV_UM_MAX_MSG_NUM + 31)>> 5];
    srv_um_mark_several_op_action_enum action_type;
} ums_mark_several_op_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE];
    S32 total_mark_item;
} ums_mark_several_op_cntx_struct;


typedef struct
{
    srv_um_traverse_msg_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_msg_node_struct *msg_list;
    U16 msg_number;
    srv_um_traverse_func traverse_func;
    srv_um_detail_field_enum field;
} ums_traverse_msg_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    srv_um_msg_box_enum running_req_box;
    srv_um_msg_box_enum pending_req_box[SRV_UM_MAX_SUPPORT_MSG_BOX];
    S32 start_time;
    S32 counter;
    S32 request_number;
    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE][SRV_UM_MAX_SUPPORT_MSG_BOX];
} ums_traverse_msg_cntx_struct;


typedef ums_get_list_para_struct ums_get_thread_list_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
//    srv_um_msg_enum running_req_type;
    srv_um_thread_id_struct *thread_list;
    U16 thread_list_size;
    S32 list_cntx_id;
//    srv_um_detail_field_enum field;
    ums_get_list_sort_idx *sort_idx_data;
//    U16 finish_idx[SRV_UM_MAX_SUPPORT_MSG_TYPE];
} ums_get_thread_list_cntx_struct;

typedef struct
{
    srv_um_get_thread_info_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_thread_id_struct *thread_list;
    srv_um_thread_id_struct backup_thread_list[SRV_UM_MAX_TRAVERSE_MSG_NUMBER];
    U16 thread_number;
} ums_get_thread_info_para_struct;

typedef struct
{
    srv_um_msg_enum pending_req_type;
    srv_um_msg_enum running_req_type;
    srv_um_msg_node_struct msg_list[SRV_UM_MIN_MSG_DETAIL_NUM];
    srv_um_msg_node_struct req_msg_list[SRV_UM_MIN_MSG_DETAIL_NUM];
    U16 req_msg_number;
} ums_get_thread_info_cntx_struct;


typedef struct
{
    srv_um_mark_several_thread_op_cb cb_func;
    S32 user_data;
    srv_um_box_identity_struct msg_box;
    srv_um_thread_id_struct *thread_list;
    srv_um_thread_id_struct backup_thread_list[SRV_UM_MAX_TRAVERSE_MSG_NUMBER];
    U16 thread_list_size;
    U32 mark_status[(SRV_UM_MAX_MSG_NUM + 31) >> 5];
    srv_um_mark_several_op_action_enum action_type;
} ums_mark_several_thread_op_para_struct;

typedef struct
{
//    srv_um_msg_enum pending_req_type;
//    srv_um_msg_enum running_req_type;
    srv_um_msg_node_struct *msg_list;
    S32 msg_list_cid;
    U16 msg_list_size;
    U16 msg_number;
    U32 mark_status[(SRV_UM_MAX_MSG_NUM + 31) >> 5];
    U32 start_timestamp;

} ums_mark_several_thread_op_cntx_struct;

typedef struct
{
    S32 pid;
    S32 child;
    void *para;
    void *cntx;
    void *result;
    ums_process_priority_enum priority;
    U32 status;  /* bitwise OR by ums_process_status_enum */
    ums_process_type_enum type;
    MMI_BOOL is_reset;
} ums_process_struct;

typedef struct
{
    U32 support_type;   /* bitwise OR by srv_um_msg_enum */    
    srv_um_msg_enum ready_type;     /* bitwise OR by srv_um_msg_enum */
    ums_process_struct *running_process;
    kal_eventgrpid event_group;
    MMI_BOOL is_create_process;
    S32 peek_msg_pid;
} ums_context_struct;

/************************************************************************/
/* Internal Global variable or function                                 */
/************************************************************************/

extern ums_context_struct *g_ums_p;

extern void srv_um_set_protocol_event_handler(void);
extern S32 srv_um_scheduler(void);
extern S32 srv_um_create_process(ums_process_type_enum type, void** para);
extern S32 srv_um_start_process(S32 pid);
extern S32 srv_um_find_process(S32 pid);
extern S32 srv_um_cancel_process(S32 pid);
extern S32 srv_um_reset_process(ums_process_struct *process);
extern S32 srv_um_get_process_status(S32 pid);
extern S32 srv_um_set_process_priority(S32 pid, ums_process_priority_enum priority);
extern S32 srv_um_get_process_progress(S32 pid, S32 *finish_number, S32 *total_number);
extern void srv_um_send_message(srv_um_msg_enum msg_type, S32 msg_id, void *local_para_ptr, void *peer_buff_ptr);
extern S32 srv_um_ready_ind(MMI_BOOL ready, srv_um_msg_enum msg_type);
extern S32 srv_um_refresh_ind(srv_um_refresh_ind_struct* refresh_ind);
extern S32 srv_um_cache_init(void);
extern void srv_um_refresh_ind_interanl(srv_um_refresh_enum refresh_type, srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type);
extern S32 srv_um_cache_clean(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type);
extern S32 srv_um_cache_add(srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type, srv_um_msg_info_struct msg_list[], S32 msg_number);
extern S32 srv_um_cache_delete(srv_um_msg_node_struct msg_list[], S32 msg_number);
extern srv_um_msg_info_struct *srv_um_cache_search(srv_um_list_type_enum list_type, void *list, MMI_BOOL fast_search);
extern void *srv_um_cache_memory_borrow(S32 app_id, S32 size);
extern S32 srv_um_cache_memory_return(S32 app_id);
extern S32 srv_um_response_handler(ums_process_type_enum type, void *inMsg);

extern S32 srv_um_listmgr_create(srv_um_list_type_enum list_type, void **list);
extern S32 srv_um_listmgr_delete(S32 cntx_id);
extern S32 srv_um_listmgr_clean(srv_um_list_type_enum list_type, srv_um_msg_enum msg_type, srv_um_msg_box_enum msg_box_type);
extern S32 srv_um_listmgr_register(S32 cntx_id, srv_um_notify_list_handler cb_func, S32 user_data);
extern S32 srv_um_listmgr_unregister(S32 cntx_id);
extern S32 srv_um_listmgr_search(
    srv_um_list_type_enum list_type,
    srv_um_box_identity_struct msg_box,
    srv_um_list_filter_struct *filter,
    srv_um_list_cntx_struct **list_cntx);
extern S32 srv_um_listmgr_init(void);
extern S32 srv_um_listmgr_update_cntx(
            S32 list_cid,
            S32 msg_number,
            srv_um_box_identity_struct msg_box,
            srv_um_list_filter_struct *filter);

extern srv_um_thread_info_struct *srv_um_thread_info_search(srv_um_thread_id_struct thread_id);
extern srv_um_thread_info_struct *srv_um_thread_info_get_by_index(S32 index);
extern srv_um_thread_info_struct *srv_um_thread_info_set_by_index(S32 index, srv_um_thread_id_struct thread_id);
extern S32 srv_um_thread_info_init(void);
extern S32 srv_um_thread_info_update(srv_um_thread_info_struct *thread_info);

/************************************************************************/
/* Hidden Interface                                                     */
/************************************************************************/
extern S32 srv_um_traverse_msg(
    srv_um_box_identity_struct msg_box,
    srv_um_msg_node_struct *msg_list,
    U16 msg_number,
    srv_um_traverse_func traverse_func,
    srv_um_detail_field_enum field,
    srv_um_traverse_msg_cb cb_func,
    S32 user_data);

#ifdef __SRV_UM_UT__
/************************************************************************/
/* UT Interface                                                         */
/************************************************************************/
extern void srv_um_ut_set_protocol_event_handler(void);
#endif

/************************************************************************/
/* Utility function                                                     */
/************************************************************************/
extern S32 srv_um_tsfr_msg_type_to_idx(srv_um_msg_enum msg_type);

/************************************************************************/
/* Utility Macro                                                        */
/************************************************************************/
#if 1//!defined(__PRODUCTION_RELEASE__)
#define CHECK_PARA_VALID(value)                                 \
{                                                               \
    if (!(value))                                                 \
    {                                                           \
        ASSERT(0);                                              \
        return SRV_UM_RESULT_INVALID_PARA;                      \
    }                                                           \
}

#define CHECK_MSG_TYPE_VALID(msg_type)                          \
{                                                               \
    CHECK_PARA_VALID(srv_um_check_support_type(msg_type))       \
}
#else
/* under construction !*/
/* under construction !*/
#endif

#endif /* UM_SRV_PROT_H */

