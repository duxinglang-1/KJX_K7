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
*  ProvBoxProt.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements all defines and function declarations used internally
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef SRV_PROVBOX_SRV_PROT_H
#define SRV_PROVBOX_SRV_PROT_H

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "MMIDataType.h"
#include "fs_type.h"
#include "stack_config.h"
#include "mmi_frm_queue_gprot.h"
#include "kal_general_types.h"

#include "mmi_rp_srv_provbox_def.h"
#include "ProvBoxSrvGprot.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxSrvConfig.h"

/*----------------------------------------------------------------------------*/
/* Internal constant                                                          */
/*----------------------------------------------------------------------------*/

/*----------------------Internal flag define--------------------------------*/

/* context flag */
#define SRV_PROVBOX_FLAG_MEM_FULL                   (0x0001)
#define SRV_PROVBOX_FLAG_DISK_FULL                  (0X0002)
#define SRV_PROVBOX_FLAG_SAVE_SIM_MSG_FAIL          (0x0004)

#define SRV_PROVBOX_FLAG_SRV_STATUS_READY           (0x0008)

/* box flag. */

/* message flag. */
/*
 * mesage flag, only use for message saved in Inbox and Archive box,
 * to indicate if a message node can not reclaim memory.
 * the low eight bits are use for external flag, please refer to srv_provbox_msg_flag_enum
 * the hight eight bits are use for internal flag 
 */
#define SRV_PROVBOX_MSG_FLAG_LOCK_RECLAIM_MEM       (0x10)
/*
 * message flag, only use for message saved in extra message.
 * to indicate if a new message is already saved permanently.  
 */
#define SRV_PROVBOX_MSG_FLAG_NEW_MSG_SAVED          (0x20)

/*----------------------Internal common define--------------------------------*/

#define SRV_PROVBOX_VERSION_MAX_CHAR_LEN            (100)       /* no change forever is preferred */

#define SRV_PROVBOX_MAX_U32_BIT_MASK_NUM            (32)        /* bit mask number of U32 */

#define SRV_PROVBOX_MAX_U8_BIT_MASK_NUM             (8) /* bit mask number of U8 */

/*----------------------Internal record file define---------------------------*/

#define SRV_PROVBOX_FILE_REC_HEAD_SIZE      (sizeof(srv_provbox_file_rec_head_struct))
#define SRV_PROVBOX_FILE_REC_FOOTER_SIZE    (sizeof(srv_provbox_file_rec_footer_struct))
#define SRV_PROVBOX_FILE_REC_PACK_SIZE      (SRV_PROVBOX_FILE_REC_HEAD_SIZE + SRV_PROVBOX_FILE_REC_FOOTER_SIZE)
#define SRV_PROVBOX_FILE_MAX_REC_SIZE       (SRV_PROVBOX_FILE_MAX_RECORD_VALUE_SIZE + SRV_PROVBOX_FILE_REC_PACK_SIZE)

/*----------------------Internal operation define-----------------------------*/

#define SRV_PROVBOX_GET_MAX_VALUE(X, Y)             ((X) >= (Y) ? (X) : (Y))

#define SRV_PROVBOX_SET_FLAG(flag, bit_mask)        ((flag) |= (bit_mask))

#define SRV_PPOVBOX_CLEAR_FLAG(flag, bit_mask)      ((flag) &= ~(bit_mask))

#define SRV_PROVBOX_CHECK_FLAG(flag, bit_mask)      (((flag) & (bit_mask)) > 0)

/*----------------------Internal structure define-----------------------------*/

#define SRV_PROVBOX_MSG_NODE_HEAD \
    U8 node_type

#define SRV_PROVBOX_MSG_BASE_INFO  \
    SRV_PROVBOX_MSG_NODE_HEAD;     \
    U8 msg_flag;                   \
    U16 bit_prop;                  \
    U32 msg_id;                    \
    U32 timestamp


#ifndef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__

/* addr field is in UTF8 encode, no more than 16 ASCII chars in most scenario, just to save memory */
#define SRV_PROVBOX_MSG_STD_INFO   \
    SRV_PROVBOX_MSG_BASE_INFO;     \
    U32 install_time;              \
    CHAR* addr

#else /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

#define SRV_PROVBOX_MSG_STD_INFO   \
    SRV_PROVBOX_MSG_BASE_INFO;     \
    U32 install_time;              \
    S16 msg_size;                  \
    CHAR* addr
    
#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

#define SRV_PROVBOX_BIT_1                               (0x01)
#define SRV_PROVBOX_BIT_2                               (0x03)
#define SRV_PROVBOX_BIT_3                               (0x07)

#define SRV_PROVBOX_MSG_BIT_IDX_SRC_ID                  (0)
#define SRV_PROVBOX_MSG_BIT_IDX_SIM_ID                  (0 + 3)
#define SRV_PROVBOX_MSG_BIT_IDX_MSG_TYPE                (0 + 3 + 3)
#define SRV_PROVBOX_MSG_BIT_IDX_READ_STATUS             (0 + 3 + 3 + 3)
#define SRV_PROVBOX_MSG_BIT_IDX_PIN_STATUS              (0 + 3 + 3 + 3 + 1)
#define SRV_PROVBOX_MSG_BIT_IDX_ADDR_TYPE               (0 + 3 + 3 + 3 + 1 + 1)
/*  Gemini_Plus */
#define SRV_PROVBOX_MSG_BIT_MASK_NODE_TYPE              (0xFF)  /* 8: 0000 0000 0000 0000 */

#define SRV_PROVBOX_MSG_BIT_MASK_SRC_ID                 \
    (SRV_PROVBOX_BIT_3 << SRV_PROVBOX_MSG_BIT_IDX_SRC_ID)       /* 3: 0000 0000 0000 0111 : 0x0007 */

#define SRV_PROVBOX_MSG_BIT_MASK_SIM_ID                 \
    (SRV_PROVBOX_BIT_3 << SRV_PROVBOX_MSG_BIT_IDX_SIM_ID)       /* 3: 0000 0000 0011 1000 : 0x0038 */

#define SRV_PROVBOX_MSG_BIT_MASK_MSG_TYPE               \
    (SRV_PROVBOX_BIT_3 << SRV_PROVBOX_MSG_BIT_IDX_MSG_TYPE)     /* 3: 0000 0001 1100 0000 :0x01C0 */

#define SRV_PROVBOX_MSG_BIT_MASK_READ_STATUS            \
    (SRV_PROVBOX_BIT_1 << SRV_PROVBOX_MSG_BIT_IDX_READ_STATUS)  /* 1: 0000 0010 0000 0000 :0x0200 */

#define SRV_PROVBOX_MSG_BIT_MASK_PIN_STATUS             \
    (SRV_PROVBOX_BIT_1 << SRV_PROVBOX_MSG_BIT_IDX_PIN_STATUS)   /* 1: 0000 0100 0000 0000 :0x0400 */

#define SRV_PROVBOX_MSG_BIT_MASK_ADDR_TYPE              \
    (SRV_PROVBOX_BIT_2 << SRV_PROVBOX_MSG_BIT_IDX_ADDR_TYPE)    /* 2: 0001 1000 0000 0000 :0x1800 */

#define SRV_PROVBOX_MSG_GET_NODE_TYPE(msg_node)         ((msg_node)->node_type)

#define SRV_PROVBOX_MSG_GET_BIT_PROPERTY(msg_node)      ((msg_node)->bit_prop)

#define SRV_PROVBOX_MSG_GET_SRC_ID(msg_node)            \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_SRC_ID) >> SRV_PROVBOX_MSG_BIT_IDX_SRC_ID))

#define SRV_PROVBOX_MSG_GET_SIM_ID(msg_node)            \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_SIM_ID) >> SRV_PROVBOX_MSG_BIT_IDX_SIM_ID))

#define SRV_PROVBOX_MSG_GET_MSG_TYPE(msg_node)          \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_MSG_TYPE) >> SRV_PROVBOX_MSG_BIT_IDX_MSG_TYPE))

#define SRV_PROVBOX_MSG_GET_READ_STATUS(msg_node)       \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_READ_STATUS) >> SRV_PROVBOX_MSG_BIT_IDX_READ_STATUS))

#define SRV_PROVBOX_MSG_GET_PIN_STATUS(msg_node)        \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_PIN_STATUS) >> SRV_PROVBOX_MSG_BIT_IDX_PIN_STATUS))

#define SRV_PROVBOX_MSG_GET_ADDR_TYPE(msg_node)         \
    ((U8)(((msg_node)->bit_prop & SRV_PROVBOX_MSG_BIT_MASK_ADDR_TYPE) >> SRV_PROVBOX_MSG_BIT_IDX_ADDR_TYPE))

#define SRV_PROVBOX_MSG_SET_BIT_PROPERTY(msg_node, new_bit_prop) \
                   do {(msg_node)->bit_prop = (new_bit_prop); }while(0)

#define SRV_PROVBOX_MSG_SET_NODE_TYPE(msg_node, new_node_type) \
                   do {(msg_node)->node_type = (new_node_type); }while(0)

#define SRV_PROVBOX_MSG_SET_SRC_ID(msg_node, new_src_id) \
                   do {(msg_node)->bit_prop |= (new_src_id) << SRV_PROVBOX_MSG_BIT_IDX_SRC_ID; }while(0)

#define SRV_PROVBOX_MSG_SET_SIM_ID(msg_node, new_sim_id) \
                   do {(msg_node)->bit_prop |= ((U8)(new_sim_id)) << SRV_PROVBOX_MSG_BIT_IDX_SIM_ID; }while(0)

#define SRV_PROVBOX_MSG_SET_MSG_TYPE(msg_node, new_msg_type) \
                   do {(msg_node)->bit_prop |= (new_msg_type) << SRV_PROVBOX_MSG_BIT_IDX_MSG_TYPE; }while(0)

#define SRV_PROVBOX_MSG_SET_READ_STATUS(msg_node, new_read_status) \
                   do {(msg_node)->bit_prop = ((msg_node)->bit_prop & (~SRV_PROVBOX_MSG_BIT_MASK_READ_STATUS)) \
                   | (new_read_status) << SRV_PROVBOX_MSG_BIT_IDX_READ_STATUS; }while(0)

#define SRV_PROVBOX_MSG_SET_PIN_STATUS(msg_node, new_pin_status) \
                   do {(msg_node)->bit_prop |= (new_pin_status) << SRV_PROVBOX_MSG_BIT_IDX_PIN_STATUS; }while(0)

#define SRV_PROVBOX_MSG_SET_ADDR_TYPE(msg_node, new_addr_type) \
                   do {(msg_node)->bit_prop |= (new_addr_type) << SRV_PROVBOX_MSG_BIT_IDX_ADDR_TYPE; }while(0)


#define SRV_PROVBOX_SIM_IDX_TO_ID(_index) ((1) << (_index))
/*----------------------------------------------------------------------------*/
/* Internal enum                                                              */
/*----------------------------------------------------------------------------*/

typedef enum
{
    SRV_PROVBOX_CMP_RESULT_BEFORE = -1,     /* First element comes before second element */
    SRV_PROVBOX_CMP_RESULT_UNEQUAL = -1,    /* first element is not equal to second element */
    SRV_PROVBOX_CMP_RESULT_EQUAL = 0,       /* first element is equal to second element */
    SRV_PROVBOX_CMP_RESULT_AFTER = 1,       /* First element comes after second element  */
    SRV_PROVBOX_CMP_RESULT_MAX_ITEM
} srv_provbox_cmp_result_enum;

typedef enum
{
    SRV_PROVBOX_DIR_ID_APP = 1,
    SRV_PROVBOX_DIR_ID_INBOX,
    SRV_PROVBOX_DIR_ID_ARCHIVE,
    SRV_PROVBOX_DIR_ID_EXTRA,
    SRV_PROVBOX_DIR_ID_TEMP,
    SRV_PROVBOX_DIR_ID_MAX_ITEM
} srv_provbox_dir_id_enum;

typedef enum
{
    SRV_PROVBOX_FILE_ID_APPFILE = 1,
    SRV_PROVBOX_FILE_ID_CHECKFILE,

    SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA,
    SRV_PROVBOX_FILE_ID_IMSG_APP_DATA,

    SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA,
    SRV_PROVBOX_FILE_ID_AMSG_APP_DATA,

    SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA,
    SRV_PROVBOX_FILE_ID_EMSG_APP_DATA,

    SRV_PROVBOX_FILE_ID_MAX_ITEM
} srv_provbox_file_id_enum;

typedef enum
{
    SRV_PROVBOX_CHECK_TYPE_UNKNOWN,
    SRV_PROVBOX_CHECK_TYPE_SAVE_NEW,
    SRV_PROVBOX_CHECK_TYPE_MOVE,
    SRV_PROVBOX_CHECK_TYPE_DELETE,
    SRV_PROVBOX_CHECK_TYPE_DELETE_ALL,
    SRV_PROVBOX_CHECK_TYPE_RESTORE_FACTORY,
    SRV_PROVBOX_CHECK_TYPE_MAX_ITEM
} srv_provbox_check_type_enum;

typedef enum
{
    SRV_PROVBOX_FILE_OP_TYPE_OPEN,
    SRV_PROVBOX_FILE_OP_TYPE_CLOSE,
    SRV_PROVBOX_FILE_OP_TYPE_READ,
    SRV_PROVBOX_FILE_OP_TYPE_WRITE,
    SRV_PROVBOX_FILE_OP_TYPE_MOVE,
    SRV_PROVBOX_FILE_OP_TYPE_DELETE,
    SRV_PROVBOX_FILE_OP_TYPE_SEEK,
    SRV_PROVBOX_FILE_OP_TYPE_GET_FILE_SIZE,
    SRV_PROVBOX_FILE_OP_TYPE_CREATE_FOLDER,
    SRV_PROVBOX_FILE_OP_TYPE_MAX_ITEM
} srv_provbox_file_op_type_enum;

typedef enum
{
    SRV_PROVBOX_MSG_NODE_TYPE_EMPTY,
    SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO,
    SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO,
    SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO,

    SRV_PROVBOX_MSG_NODE_TYPE_MSG_STORE_INFO,
    SRV_PROVBOX_MSG_NODE_TYPE_MAX_ITEM
} srv_provbox_msg_node_type_enum;

/* The order of each item is array index of g_srv_provbox_init_job_info_tbl[] */
typedef enum
{
    SRV_PROVBOX_JOB_TYPE_INIT_CHECK_VERSION,
    SRV_PROVBOX_JOB_TYPE_INIT_LOAD_CHECK_DATA,
    SRV_PROVBOX_JOB_TYPE_INIT_RECORD_LIST,
    SRV_PROVBOX_JOB_TYPE_INIT_MSG_LIST,
    SRV_PROVBOX_JOB_TYPE_INIT_CHECK_MSG_LIST,
//    SRV_PROVBOX_JOB_TYPE_DEFRAG_FILE,

    SRV_PROVBOX_JOB_TYPE_SHOW_EXT_MSG,
    SRV_PROVBOX_JOB_TYPE_SAVE_EXT_MSG,

    SRV_PROVBOX_JOB_TYPE_SAVE_MSG,

    SRV_PROVBOX_JOB_TYPE_GET_MSG_DATA,

//    SRV_PROVBOX_JOB_TYPE_GET_MSG_NUM,
//    SRV_PROVBOX_JOB_TYPE_GET_MSG_SORT_INFO,
//    SRV_PROVBOX_JOB_TYPE_GET_MSG_LIST_INFO_BY_ID,
//    SRV_PROVBOX_JOB_TYPE_GET_MSG_LIST_INFO_BY_INDEX,
    
//    SRV_PROVBOX_JOB_TYPE_MULTI_OP,
//    SRV_PROVBOX_JOB_TYPE_DEL_MSG,
//    SRV_PROVBOX_JOB_TYPE_DEL_ALL_MSG,
//    SRV_PROVBOX_JOB_TYPE_READ_PROPERTIES,

    /* SRV_PROVBOX_JOB_TYPE_GET_MSG_DATA_INFO, */
    SRV_PROVBOX_JOB_TYPE_SET_MSG_FLAG,
    SRV_PROVBOX_JOB_TYPE_GET_MSG_INFO,
    SRV_PROVBOX_JOB_TYPE_UPDATE_MSG_INFO,

//    SRV_PROVBOX_JOB_TYPE_DEINIT_MSG_LIST,
//    SRV_PROVBOX_JOB_TYPE_DEINIT_RECORD_LIST,
//    SRV_PROVBOX_JOB_TYPE_DEINIT,
//    SRV_PROVBOX_JOB_TYPE_RESTORE_FACTORY,

    SRV_PROVBOX_JOB_MAX_ITEM
} srv_provbox_job_type_enum;

typedef enum
{
    SRV_PROVBOX_JOB_SUB_TYPE_NONE,
    SRV_PROVBOX_JOB_SUB_TYPE_CHECK_FOLDER,
    SRV_PROVBOX_JOB_SUB_TYPE_CHECK_VERSION,
    SRV_PROVBOX_JOB_SUB_TYPE_RESET_PROVBOX,
    SRV_PROVBOX_JOB_SUB_TYPE_CHECK_RESTORE,
    SRV_PROVBOX_JOB_SUB_TYPE_CHECK_DELETE_ALL,
    SRV_PROVBOX_JOB_SUB_TYPE_DELETE_MSG,
    SRV_PROVBOX_JOB_SUB_TYPE_DELETE_ALL_MSG,
    SRV_PROVBOX_JOB_SUB_TYPE_MAX_ITEM
} srv_provbox_job_sub_type_enum;

typedef enum
{
    SRV_PROVBOX_JOB_STATE_PENDING,
    SRV_PROVBOX_JOB_STATE_ASYNC_CONTINUE,
    SRV_PROVBOX_JOB_STATE_MAX_ITEM
} srv_provbox_job_state_enum;

typedef enum
{
    SRV_PROVBOX_JOB_FLAG_HOLD_CTRL_BUFF = 0x00000001,
    SRV_PROVBOX_JOB_FLAG_MAX_ITEM
} srv_provbox_job_flag_enum;

typedef enum
{
    SRV_PROVBOX_SHOW_EXT_MSG_STATUS_INIT,
    SRV_PROVBOX_SHOW_EXT_MSG_STATUS_DELETE,
    SRV_PROVBOX_SHOW_EXT_MSG_STATUS_NEW_MSG,
    SRV_PROVBOX_SHOW_EXT_MSG_STATUS_MAX_ITEM
} srv_provbox_show_ext_msg_status_enum;


/*----------------------------------------------------------------------------*/
/* Internal structure                                                         */
/*----------------------------------------------------------------------------*/
#if (SRV_PROVBOX_MSG_NODE_INIT_LOAD_TYPE == 0)

    #define SRV_PROVBOX_DEF_MSG_NODE_TYPE           SRV_PROVBOX_MSG_NODE_TYPE_MSG_BASE_INFO

#elif (SRV_PROVBOX_MSG_NODE_INIT_LOAD_TYPE == 1)

    #define SRV_PROVBOX_DEF_MSG_NODE_TYPE           SRV_PROVBOX_MSG_NODE_TYPE_MSG_STD_INFO

#else 

    #define SRV_PROVBOX_DEF_MSG_NODE_TYPE           SRV_PROVBOX_MSG_NODE_TYPE_MSG_FULL_INFO

#endif 



/*----------------------Single Link-------------------------------------------*/

#define SRV_PROVBOX_SLINK_HEAD \
    struct srv_provbox_slist_st *next

typedef void (*SRV_PROVBOX_SLIST_FREE_NODE_FUNC) (void *node);

/* The first node is the one already in single link commonly */
typedef srv_provbox_cmp_result_enum(*SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) (void *src, void *dst);

typedef struct srv_provbox_slist_st
{
    SRV_PROVBOX_SLINK_HEAD; /* Please define the first field like this if use Single Link */
} srv_provbox_slist_struct;

/*------------------Primitive message struct: Inter API---------------------------*/
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 trans_id;                               /* Transaction id */
} srv_provbox_continue_process_job_ind_struct;


/* To store message number statistic information of all SIM  card */
typedef struct
{
    U32 sim_read_num[MMI_SIM_TOTAL];            /* Read number of  message from each SIM card */ 
    U32 sim_unread_num[MMI_SIM_TOTAL];          /* Unread number of message from each SIM card */ 
    U32 sim_sim_msg_num[MMI_SIM_TOTAL];         /* The number of SIM Provisonining message from each SIM card specially */
} srv_provbox_sim_msg_stat_struct;

/* To store message number statistic of all box type */
typedef struct
{
    srv_provbox_sim_msg_stat_struct imsg_stat;  /* Message number statistic of inbox */
    srv_provbox_sim_msg_stat_struct amsg_stat;  /* Message number staticstic of archive box */
    U32 extra_num;                              /* Message number statistic of extra box */    
} srv_provbox_box_msg_stat_struct;

#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__
/* To store the sort information which is used  sort message by requested sort type */
typedef union
{
    srv_provbox_msg_type_enum msg_type;                 /* Message type */
    srv_provbox_msg_read_status_enum read_status;       /* Read status */
    S32 msg_size;                                       /* Message size */
    U16 addr[SRV_PROVBOX_SORT_ADDR_MAX_CHAR_LEN + 1];   /* Message address */    
}srv_provbox_sort_data_union;

#endif /* __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__ */

/* Message sort information */
typedef struct
{
    U32 msg_id;                                 /* Message id */
    U32 timestamp;                              /* Timestamp */
    U8 sim_id;                                  /* SIM id, please refer to mmi_sim_enum */    
#ifdef __MMI_PROVBOX_LIST_INDEX_DATA_SUPPORT__  
    srv_provbox_sort_data_union sort_data;      /* Sort data */
#endif
} srv_provbox_msg_sort_info_struct;


/*----------------------Dynamic Pointer Array---------------------------------*/

typedef void *(*SRV_PROVBOX_DPARY_MALLOC) (U32 size);
typedef void (*SRV_PROVBOX_DPARY_FREE) (void *p);

typedef void (*SRV_PROVBOX_DPARY_FREE_ELM_FUNC) (void *elm);

/* The first element is the one already in dynamic pointer array commonly */
typedef srv_provbox_cmp_result_enum(*SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC) (void *src, void *dst);

typedef struct
{
    U32 ary_size;
    U32 init_size;
    U32 inc_size;
    U32 dec_size;
    U32 elm_num;
    SRV_PROVBOX_DPARY_MALLOC malloc;
    SRV_PROVBOX_DPARY_FREE free;
    void *elm[1];
} srv_provbox_dpary_struct;

/*----------------------File Structure----------------------------------------*/

typedef struct
{
    U8 check_type;
    U8 box_type;
    U16 reserved;
    U32 msg_id;

    S32 info_pos;

    S32 app_pos;
    S32 app_data_size;

    S32 prov_data_size;

    U32 check_sum;
    U32 valid;
} srv_provbox_check_info_struct;

/*----------------------Record file-------------------------------------------*/

/* Record type (4byte) + Record id (4byte) + Record size (4byte) + value (size - 12) */

typedef struct
{
    U32 rec_type;
    U32 rec_id;
    U32 rec_size;   /* total tag size */
    /* U32 checksum; */
} srv_provbox_file_rec_head_struct;

typedef struct
{
    U32 check_sum;
    U32 footer;
} srv_provbox_file_rec_footer_struct;

typedef struct srv_provbox_file_rec_st
{
    struct srv_provbox_file_rec_st *next;
    U32 rec_id;
    U32 start_pos;
    U32 rec_size;   /* rec_size */
} srv_provbox_file_rec_struct;

typedef struct
{
    U32 flag;
    S32 init_size;
    S32 defrag_size;
    S32 inc_size;
    srv_provbox_file_id_enum file_id;

    U32 total_size; /* total size of all record, not same as file size */
    U32 free_size;
    U32 file_size;
    U32 max_rec_num;

    FS_HANDLE fd;
    U32 start_pos;      /* start file postion */
    S32 load_rec_num;   /* current max load record num in one sync event handler */
    U32 cur_free_rec_id;
    U32 use_rec_num;    /* the record num in use_list */
    srv_provbox_file_rec_struct *use_list;
    srv_provbox_file_rec_struct *free_list;
    srv_provbox_file_rec_struct *cur_use_rec;
} srv_provbox_file_mgr_struct;

/*----------------------Message Structure-------------------------------------*/

typedef struct
{
    U8 config_id;
    U8 status;
} srv_provbox_store_app_config_status_struct;

typedef struct
{
    U16 app_num;
    U16 config_status;  /* the install status of whole message */
    srv_provbox_store_app_config_status_struct app_config_status[SRV_PROVBOX_MAX_APP_INFO_NUM];
} srv_provbox_store_msg_config_status_struct;

typedef struct
{
    SRV_PROVBOX_MSG_NODE_HEAD;
} srv_provbox_msg_node_struct;

typedef struct
{
    SRV_PROVBOX_MSG_BASE_INFO;
} srv_provbox_msg_base_info_struct;

typedef struct
{
    SRV_PROVBOX_MSG_STD_INFO;   /* UTF8 encode, ASCII in most scenario, just to save memory */
} srv_provbox_msg_std_info_struct;

typedef struct
{
    SRV_PROVBOX_MSG_STD_INFO;
    srv_provbox_msg_config_status_struct msg_config_status;
    srv_provbox_msg_data_struct msg_data;
} srv_provbox_msg_full_info_struct;

typedef struct
{
    SRV_PROVBOX_MSG_BASE_INFO;

    U32 install_time;

    U8 src_id;
    U8 sim_id;
    U8 msg_type;
    U8 read_status;

    U8 pin_status;
    U8 addr_type;
    U16 addr_len;

    U16 addr[SRV_PROVBOX_ADDR_MAX_CHAR_LEN + 1];
    S16 app_data_size;  /* -1 means no app_data */
    S16 prov_data_size; /* -1 means no prov data */

    srv_provbox_store_msg_config_status_struct msg_config_status;
}srv_provbox_msg_store_info_struct;


typedef struct
{
    U16 msg_flag;
    U8 flag_num[SRV_PROVBOX_MAX_U8_BIT_MASK_NUM];
} srv_provbox_msg_flag_stat_struct;

typedef struct
{
    U8 box_type;
    U8 sort_type;
    U8 init_node_type;
    U32 cursor;
    S32 info_fh;    /* file handle of message info data */
    S32 app_fh;     /* file handle of message app data */
    S32 msg_ah;     /* handle of message dynamic pointer array, use to store messages */

    srv_provbox_sim_msg_stat_struct sim_msg_stat;
    srv_provbox_msg_flag_stat_struct flag_stat;

} srv_provbox_msg_list_struct;

typedef struct srv_provbox_job_st
{
    struct srv_provbox_job_st *next;
    int src_mod;
    U8 job_type;
    U8 sub_type;
    U8 job_state;
    U32 flag;
    S32 int_value;
    void *req_data;
    void *cnf_data; /* to store the job result */
} srv_provbox_job_struct;


typedef struct
{
    U32 max_msg_id;
    U32 max_trans_id;
    U32 flag;
    
    /* New */
    U32 new_msg_id;
    
    srv_provbox_msg_list_struct *imsg_list; /* Inbox message list */
    
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_msg_list_struct *amsg_list; /* Archive message list */
#endif

    srv_provbox_msg_list_struct *emsg_list; /* Extra message list */

    srv_provbox_job_struct *job_list;
    srv_provbox_job_struct *cur_job;

} srv_provbox_cntx_struct;


#ifdef __MMI_PROV_IN_UM__

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                             /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                      /* Type of message */
    kal_bool result;                               /* KAL_TRUE means OK; KAL_FALSE means failed */
    srv_um_msg_box_enum msg_box_type;              /* Type of message box */
    kal_uint16 start_entry;                        /* The first entry number in this response primitive */
    kal_uint16 msg_number;                         /* Number of messages in this response primitive */
    srv_um_msg_list_struct list_info[20];          /* List info array */
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_um_list_idx_data_union list_idx_data[20];  /* list index data */
#endif
    kal_bool more;
} srv_provbox_um_get_msg_list_rsp_struct;

#endif


/*----------------------------------------------------------------------------*/
/* Internal Function declaration                                              */
/*----------------------------------------------------------------------------*/

/*----------------------Memory------------------------------------------------*/

extern void *srv_provbox_app_alloc(U32 size);

extern void srv_provbox_app_free(void *p);

#define SRV_PROVBOX_MALLOC                          srv_provbox_app_alloc

#define SRV_PROVBOX_ALLOC_TYPE(type)                (type*)SRV_PROVBOX_MALLOC(sizeof(type))

#define SRV_PROVBOX_FREE(x)                         do {if (x){ srv_provbox_app_free(x); x = NULL; } }while(0)

/*----------------------Log---------------------------------------------------*/

extern void srv_provbox_enable_log(MMI_BOOL enable);

extern void srv_provbox_log(CHAR *format, ...);

#define SRV_PROVBOX_LOG(x)        srv_provbox_log x


/*----------------------Event---------------------------------------------------*/
#define SRV_PROVBOX_INIT_EVENT_HEAD(_evt, _evt_type)                 \
        do {                                                         \
            MMI_FRM_INIT_EVENT(&(_evt), EVT_ID_SRV_PROVBOX_NOTIFY_IND); \
            (_evt).evt_type = (_evt_type);                           \
        } while (0)

/*---------------------Time---------------------------------------------------*/

U32 srv_provbox_get_curr_time(void);

/*---------------------Flag---------------------------------------------------*/

extern S32 srv_provbox_get_flag_index(U32 flag, U32 max_flag_num);

/*----------------------String------------------------------------------------*/

extern CHAR *srv_provbox_ucs2_copy(CHAR *dst_str, S32 dst_buf_size, const CHAR *src_str);

extern CHAR *srv_provbox_utf8_strdup(const CHAR *src);

/*----------------------List--------------------------------------------------*/

extern srv_provbox_slist_struct *srv_provbox_slist_add_head(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node);

extern srv_provbox_slist_struct *srv_provbox_slist_add_tail(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node);

extern srv_provbox_slist_struct *srv_provbox_slist_insert_sorted(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node,
                                    SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC compare_func);
/*
extern srv_provbox_slist_struct *srv_provbox_slist_insert_afer(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *cur_node,
                                    srv_provbox_slist_struct *new_node);
*/
extern U32 srv_provbox_slist_get_length(srv_provbox_slist_struct *slist);
/*
extern srv_provbox_slist_struct *srv_provbox_slist_get_head(srv_provbox_slist_struct *slist);

extern srv_provbox_slist_struct *srv_provbox_slist_get_tail(srv_provbox_slist_struct *slist);
*/
extern MMI_BOOL srv_provbox_slist_get_index(
                    srv_provbox_slist_struct *slist,
                    srv_provbox_slist_struct *node,
                    U32 *index);

extern srv_provbox_slist_struct *srv_provbox_slist_get_node_by_data(
                                    srv_provbox_slist_struct *slist,
                                    SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC compare_func,
                                    void *data);
/*
extern srv_provbox_slist_struct *srv_provbox_slist_get_node_before(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node);
*/

extern srv_provbox_slist_struct *srv_provbox_slist_get_node_by_index(srv_provbox_slist_struct *slist, U32 index);

extern srv_provbox_slist_struct *srv_provbox_slist_reverse(srv_provbox_slist_struct *slist);
/*
extern srv_provbox_slist_struct *srv_provbox_slist_remove_head(srv_provbox_slist_struct **slist);

extern srv_provbox_slist_struct *srv_provbox_slist_remove_tail(srv_provbox_slist_struct **slist);
*/
extern srv_provbox_slist_struct *srv_provbox_slist_remove(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node);
/*
extern srv_provbox_slist_struct *srv_provbox_slist_remove_by_data(
                                    srv_provbox_slist_struct **slist,
                                    SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC compare_func,
                                    void *data);

extern srv_provbox_slist_struct *srv_provbox_slist_delete_head(
                                    srv_provbox_slist_struct *slist,
                                    SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func);

extern srv_provbox_slist_struct *srv_provbox_slist_delete_tail(
                                    srv_provbox_slist_struct *slist,
                                    SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func);
*/
extern srv_provbox_slist_struct *srv_provbox_slist_delete(
                                    srv_provbox_slist_struct *slist,
                                    srv_provbox_slist_struct *node,
                                    SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func);

extern srv_provbox_slist_struct *srv_provbox_slist_free_slist(
                                    srv_provbox_slist_struct *slist,
                                    SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func);

/*----------------------Dynamic Pointer Array---------------------------------*/

extern S32 srv_provbox_dpary_new(
            U32 init_size,
            U32 inc_size,
            U32 dec_size,
            SRV_PROVBOX_DPARY_MALLOC malloc,
            SRV_PROVBOX_DPARY_FREE free);

/*
extern S32 srv_provbox_dpary_free(S32 hary);

extern S32 srv_provbox_dpary_free_with_elm(S32 hary, SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm);

extern S32 srv_provbox_dpary_add_head(S32 hary, void *elm);

extern S32 srv_provbox_dpary_add_tail(S32 hary, void *elm);

extern S32 srv_provbox_dpary_insert_index(S32 hary, U32 index, void *elm);
*/

extern MMI_BOOL srv_provbox_dpary_insert_sorted(
                    S32 *hary,
                    void *elm,
                    SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
                    U32 *index);

extern U32 srv_provbox_dpary_get_num(S32 hary);

extern MMI_BOOL srv_provbox_dpary_get_elm_by_index(S32 hary, U32 index, void **elm);

extern MMI_BOOL srv_provbox_dpary_get_elm_by_data(
                    S32 hary,
                    void *data,
                    SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
                    void **elm,
                    U32 *index);
/*
extern MMI_BOOL srv_provbox_dpary_get_index_by_elm(S32 hary, void *elm, U32 *index);
*/
extern MMI_BOOL srv_provbox_dpary_get_index_by_data(
                    S32 hary,
                    void *data,
                    SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
                    U32 *index);

extern MMI_BOOL srv_provbox_dpary_replace_elm_by_index(S32 hary, U32 index, void *new_elm, void **old_elm);

extern S32 srv_provbox_dpary_sort(S32 hary, SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare);

/*
extern void *srv_provbox_dpary_remove_head(S32 *hary);

extern void *srv_provbox_dpary_remove_tail(S32 *hary);
*/
extern void *srv_provbox_dpary_remove_elm_by_index(S32 *hary, U32 index);
/*
extern S32 srv_provbox_dpary_remove_elm(S32 hary, void *elm);
*/
extern MMI_BOOL srv_provbox_dpary_delete_elm_by_index(S32 *hary, U32 index, SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm);
/*
extern MMI_BOOL srv_provbox_dpary_delete_elm_by_data(
                    S32 *hary,
                    void *data,
                    SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
                    SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm);
*/
extern S32 srv_provbox_dpary_delete_all(S32 hary, SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm);

/*----------------------File I/O----------------------------------------------*/

extern srv_provbox_result_enum srv_provbox_error_code_file_to_provbox(srv_provbox_file_op_type_enum op, int file_ret);

extern srv_provbox_result_enum srv_provbox_check_folder(S32 max_del_num, S32 *total_del_num);

extern srv_provbox_result_enum srv_provbox_reset_provbox(
                                srv_provbox_cntx_struct *cntx,
                                S32 max_del_num,
                                S32 *total_del_num);

extern srv_provbox_result_enum srv_provbox_clean_folder_by_box_type(
                                srv_provbox_box_type_enum box_type,
                                S32 max_del_num,
                                S32 *total_del_num);

extern const CHAR * srv_provbox_get_dir_by_id(srv_provbox_dir_id_enum dir_id);

extern srv_provbox_result_enum srv_provbox_check_version(srv_provbox_cntx_struct *cntx);

extern srv_provbox_result_enum srv_provbox_reset_version(srv_provbox_cntx_struct *cntx);

extern srv_provbox_result_enum srv_provbox_save_max_msg_id(srv_provbox_cntx_struct *cntx);

extern srv_provbox_result_enum srv_provbox_file_get_file_size(U16 *filename, S32 *size);

extern srv_provbox_result_enum srv_provbox_file_read_file(U16 *filename, void *data_buf, S32 *buf_size);

extern srv_provbox_result_enum srv_provbox_file_get_prov_data_filename(
                                srv_provbox_box_type_enum box_type,
                                U32 msg_id,
                                U16 *filename,
                                S32 name_size);
/*
extern S32 srv_provbox_file_get_prov_file_size(srv_provbox_box_type_enum box_type, U32 msg_id);
*/
extern srv_provbox_result_enum srv_provbox_file_save_prov_data(
                                srv_provbox_box_type_enum box_type,
                                U32 msg_id,
                                void *prov_data,
                                S32 prov_data_size);

/*----------------------check file--------------------------------------------*/

extern srv_provbox_result_enum srv_provbox_file_set_check_info(
                                srv_provbox_check_info_struct *check_info,
                                U8 check_type,
                                U8 box_type,
                                U32 msg_id,
                                S32 info_pos,
                                S32 app_pos,
                                S32 app_data_size,
                                S32 prov_data_size);

extern srv_provbox_result_enum srv_provbox_file_read_check_file(
                                U16 *filename,
                                srv_provbox_check_type_enum check_type,
                                U32 msg_id, 
                                srv_provbox_check_info_struct *check_info);

extern srv_provbox_result_enum srv_provbox_file_write_check_file(srv_provbox_check_info_struct *check_info);

extern srv_provbox_result_enum srv_provbox_file_delete_check_file(srv_provbox_check_type_enum check_type, U32 msg_id);

/*----------------------Record List-------------------------------------------*/

extern srv_provbox_file_id_enum srv_provbox_file_get_info_file_id_by_box_type(srv_provbox_box_type_enum box_type);

extern srv_provbox_file_id_enum srv_provbox_file_get_app_file_id_by_box_type(srv_provbox_box_type_enum box_type);

extern S32 srv_provbox_file_new_handle(
            S32 init_size,
            S32 frag_size,
            S32 inc_size,
            srv_provbox_file_id_enum file_id,
            U32 max_rec_num);

extern srv_provbox_result_enum srv_provbox_file_free_handle(S32 hfile);
/*
extern srv_provbox_file_id_enum srv_provbox_file_get_file_id(S32 hfile);
*/
extern U32 srv_provbox_file_get_record_num(S32 hfile);

extern U32 srv_provbox_file_get_max_use_rec_id(S32 hfile);

extern srv_provbox_result_enum srv_provbox_file_init_record_list(S32 hfile, S32 load_num);

extern srv_provbox_result_enum srv_provbox_file_delete_record_list(S32 hfile);

extern srv_provbox_result_enum srv_provbox_file_cursor_read_index_record(
                                S32 hfile,
                                U32 *rec_id,
                                void *data_buf,
                                S32 buf_size,
                                S32 *data_size,
                                U32 index);

extern srv_provbox_result_enum srv_provbox_file_cursor_read_next_record(
                                S32 hfile,
                                U32 *rec_id,
                                void *data_buf,
                                S32 buf_size,
                                S32 *data_size);

extern srv_provbox_result_enum srv_provbox_file_cursor_read_record_close(S32 hfile, U32 *index);

extern srv_provbox_result_enum srv_provbox_file_read_record(
                                S32 hfile,
                                U32 rec_id,
                                void *data_buf,
                                S32 buf_size,
                                S32 *data_size);
/*
extern srv_provbox_result_enum srv_provbox_file_get_pos_before_write(S32 hfile, S32 data_size, U32 *start_pos);
*/
extern srv_provbox_result_enum srv_provbox_file_write_record(S32 hfile, U32 rec_id, void *rec_data, S32 data_size);
/*
extern srv_provbox_result_enum srv_provbox_file_get_pos_before_update(S32 hfile, U32 rec_id, U32 *start_pos);
*/
extern srv_provbox_result_enum srv_provbox_file_update_record(S32 hfile, U32 rec_id, void *rec_data, S32 data_size);

extern srv_provbox_result_enum srv_provbox_file_delete_record(S32 hfile, U32 rec_id);

/*
extern MMI_BOOL srv_provbox_file_check_need_defrag(S32 hfile);

extern srv_provbox_result_enum srv_provbox_file_defrag_file(S32 hfile);
*/

/*----------------------Message List------------------------------------------*/

MMI_BOOL srv_provbox_msg_is_sim_message(srv_provbox_msg_type_enum msg_type);

extern srv_provbox_result_enum srv_provbox_msg_copy_msg_config_status(
                                srv_provbox_msg_config_status_struct *src_msg_config_status,
                                srv_provbox_msg_config_status_struct *dst_msg_config_status);

extern srv_provbox_result_enum srv_provbox_msg_copy_cmn_info(
                                srv_provbox_msg_cmn_info_struct *src_cmn_info,
                                srv_provbox_msg_cmn_info_struct *dst_cmn_info);

extern srv_provbox_result_enum srv_provbox_msg_copy_sim_msg_stat_by_sim_id(
                                srv_provbox_sim_msg_stat_struct *dst_sim_msg_stat,
                                srv_provbox_sim_msg_stat_struct *src_sim_msg_stat,
                                U8 sim_id);

extern srv_provbox_msg_list_struct *srv_provbox_msg_create_list(
                                        srv_provbox_box_type_enum box_type,
                                        srv_provbox_msg_sort_type_enum sort_type,
                                        srv_provbox_msg_node_type_enum init_node_type,
                                        S32 init_msg_list_size);
/*
extern srv_provbox_result_enum srv_provbox_msg_free_list(srv_provbox_msg_list_struct *msg_list);
*/
extern U32 srv_provbox_msg_get_msg_num(srv_provbox_msg_list_struct *msg_list, U8 sim_id);

/*
extern srv_provbox_sim_msg_stat_struct *srv_provbox_msg_get_sim_msg_stat(srv_provbox_msg_list_struct *msg_list);
*/

extern srv_provbox_result_enum srv_provbox_msg_get_sim_id_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                U8 *sim_id);

extern srv_provbox_result_enum srv_provbox_msg_get_msg_node_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_node_struct **msg_node);

extern srv_provbox_result_enum srv_provbox_msg_format_msg_list_section(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 start_index,
                                U32 op_msg_num,
                                MMI_BOOL format_all);

extern srv_provbox_result_enum srv_provbox_msg_format_msg_list_except(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_box_type_enum except_box_type,
                                U32 except_start_index,
                                U32 except_msg_num,
                                MMI_BOOL format_all);

extern srv_provbox_result_enum srv_provbox_msg_init_multi_msg_node(
                                srv_provbox_msg_list_struct *msg_list,
                                S32 load_msg_num);

extern srv_provbox_result_enum srv_provbox_msg_save_ext_msg_by_index(srv_provbox_msg_list_struct *msg_list, U32 index);

extern srv_provbox_result_enum srv_provbox_msg_save_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_save_msg_req_struct *new_msg,
                                srv_provbox_save_data_type_enum *save_type);

extern U32 srv_provbox_msg_get_max_msg_id(srv_provbox_msg_list_struct *msg_list);

extern srv_provbox_result_enum srv_provbox_msg_get_list_index_by_msg_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                U32 *index);

extern srv_provbox_result_enum srv_provbox_msg_get_list_index_by_id_and_box(
                                   srv_provbox_cntx_struct *cntx,
                                   srv_provbox_box_type_enum box_type,
                                   U32 msg_id,
                                   srv_provbox_msg_list_struct **msg_list,
                                   U32 *index);

extern srv_provbox_result_enum srv_provbox_msg_get_msg_data_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                U8 *sim_id,
                                void **app_data,
                                S16 *app_data_size,
                                U16 *filename,
                                S32 name_len);
/*
extern srv_provbox_result_enum srv_provbox_msg_get_msg_data_by_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                U8 *sim_id,
                                void **app_data,
                                S16 *app_data_size,
                                U16 *filename,
                                S32 name_len);
*/
extern srv_provbox_result_enum srv_provbox_msg_get_msg_num_stat(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_box_type_enum box_type,
                                U8 sim_id,
                                srv_provbox_box_msg_stat_struct *box_msg_stat);

extern srv_provbox_result_enum srv_provbox_msg_sort_msg_list(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_sort_type_enum sort_type);

extern srv_provbox_result_enum srv_provbox_msg_get_sort_info_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U8 sim_id,
                                srv_provbox_msg_sort_type_enum sort_type,
                                U32 index,
                                srv_provbox_msg_sort_info_struct *sort_info,
                                U32 *next_index);

extern srv_provbox_result_enum srv_provbox_msg_get_list_info_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U8 sim_id,
                                U32 index,
                                S16 *msg_size,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                U32 *next_index);

extern srv_provbox_result_enum srv_provbox_msg_get_list_info_by_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U8 sim_id,
                                U32 msg_id,
                                S16 *msg_size,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                U32 *next_msg_id);

extern srv_provbox_result_enum srv_provbox_msg_delete_msg_by_index(srv_provbox_msg_list_struct *msg_list, U32 index);

extern srv_provbox_result_enum srv_provbox_msg_delete_msg_by_id(srv_provbox_msg_list_struct *msg_list, U32 msg_id);

extern srv_provbox_result_enum srv_provbox_msg_force_delete_msg_by_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id);

extern srv_provbox_result_enum srv_provbox_msg_force_delete_sim_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_msg_type_enum *msg_type_list,
                                int list_num);

extern srv_provbox_result_enum srv_provbox_msg_delete_all_msg(
                                srv_provbox_msg_list_struct *msg_list,
                                srv_provbox_del_all_msg_mode_enum *mode, mmi_sim_enum sim_id);

extern srv_provbox_result_enum srv_provbox_msg_set_msg_flag(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                srv_provbox_msg_flag_op_enum op,
                                U32 msg_flag);

extern srv_provbox_result_enum srv_provbox_msg_get_read_info_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_msg_pin_status_enum *pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status);
/*
extern srv_provbox_result_enum srv_provbox_msg_get_read_info_by_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                srv_provbox_msg_cmn_info_struct *cmn_info,
                                srv_provbox_msg_pin_status_enum *pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status);
*/

extern srv_provbox_result_enum srv_provbox_msg_update_read_info_by_index(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 index,
                                U32 info_mask,
                                U32 install_time,
                                srv_provbox_msg_read_status_enum read_status,
                                srv_provbox_msg_pin_status_enum pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status);
/*
extern srv_provbox_result_enum srv_provbox_msg_update_read_info_by_id(
                                srv_provbox_msg_list_struct *msg_list,
                                U32 msg_id,
                                U32 info_mask,
                                U32 install_time,
                                srv_provbox_msg_read_status_enum read_status,
                                srv_provbox_msg_pin_status_enum pin_status,
                                srv_provbox_msg_config_status_struct *msg_config_status);
*/
extern srv_provbox_result_enum srv_provbox_msg_move_to_box_by_index(
                                srv_provbox_msg_list_struct *cur_msg_list,
                                srv_provbox_msg_list_struct *new_msg_list,
                                U32 index,
                                U32 *new_index);

extern srv_provbox_result_enum srv_provbox_msg_move_to_box_by_id(
                                srv_provbox_msg_list_struct *cur_msg_list,
                                srv_provbox_msg_list_struct *new_msg_list,
                                U32 msg_id,
                                U32 *new_index);
/*
extern MMI_BOOL srv_provbox_msg_check_defrag_file(
                    srv_provbox_cntx_struct *cntx,
                    srv_provbox_msg_list_struct *msg_list);
*/
/*----------------------Primitive---------------------------------------------*/

extern void srv_provbox_event_hdlr_init(void);

oslModuleType srv_provbox_get_module_type_by_source_id(srv_provbox_source_id_enum src_id);

extern void srv_provbox_send_continue_process_job_ind(int dest_mod_id, U32 trans_id);

//extern void srv_provbox_send_new_msg_ind(int dest_mod_id, srv_provbox_msg_cmn_info_struct *cmn_info);

void srv_provbox_send_list_info_changed_ind(int dest_mod_id, srv_provbox_msg_cmn_info_struct *cmn_info);

extern void srv_provbox_send_save_msg_available_ind(int dest_mod_id, U32 trans_id);

extern void srv_provbox_send_save_msg_cnf(
                int dest_mod_id,
                srv_provbox_save_msg_req_struct *req_data,
                U32 msg_id,
                srv_provbox_result_enum result);

extern void srv_provbox_send_get_msg_data_cnf(
                int dest_mod_id,
                srv_provbox_get_msg_data_req_struct *req_data,
                U8 sim_id,
                void *app_data,
                S16 app_data_size,
                U16 *filename,
                srv_provbox_result_enum result);

/*
extern void srv_provbox_send_get_msg_num_cnf(
                int dest_mod_id,
                srv_provbox_get_msg_num_req_struct *req_data,
                srv_provbox_box_msg_stat_struct *msg_stat,
                srv_provbox_result_enum result);

extern void srv_provbox_send_get_sort_info_cnf(
                int dest_mod_id,
                srv_provbox_get_sort_info_req_struct *req_data,
                U16 msg_num,
                srv_provbox_msg_sort_info_struct *sort_info,
                S32 msg_info_num,
                U32 next_start_idx,
                srv_provbox_result_enum result);


extern void srv_provbox_send_get_list_info_by_index_cnf(
                int dest_mod_id,
                srv_provbox_get_list_info_by_index_req_struct *req_data,
                U16 msg_num,
                S16 *msg_size_list,
                srv_provbox_msg_cmn_info_struct *cmn_info,
                S32 msg_info_num,
                U32 next_start_idx,
                srv_provbox_result_enum result);

extern void srv_provbox_send_get_list_info_by_id_cnf(
                int dest_mod_id,
                srv_provbox_get_list_info_by_id_req_struct *req_data,
                U16 msg_num,
                S16 *msg_size_list,
                srv_provbox_msg_cmn_info_struct *cmn_info,
                S32 msg_info_num,
                U32 next_start_msg_id,
                 srv_provbox_result_enum *op_result,
                 srv_provbox_result_enum result);

extern void srv_provbox_send_delete_msg_cnf(
                int dest_mod_id,
                srv_provbox_delete_msg_req_struct *req_data,
                srv_provbox_result_enum result);

extern void srv_provbox_send_delete_all_msg_cnf(
                int dest_mod_id,
                srv_provbox_delete_all_msg_req_struct *req_data,
                U32 left_num,
                srv_provbox_result_enum result);

extern void srv_provbox_send_multi_op_cnf(
                int dest_mod_id,
                srv_provbox_multi_op_req_struct *req_data,
                U32 msg_num,
                U16 *op_result,
                U16 op_result_num,
                srv_provbox_result_enum result);
*/
extern void srv_provbox_send_set_msg_flag_cnf(
                int dest_mod_id,
                srv_provbox_set_msg_flag_req_struct *req_data,
                srv_provbox_result_enum result);

extern void srv_provbox_send_get_msg_info_cnf(
                int dest_mod_id,
                srv_provbox_get_msg_info_req_struct *req_data,
                srv_provbox_msg_cmn_info_struct *cmn_info,
                srv_provbox_msg_pin_status_enum pin_status,
                srv_provbox_msg_config_status_struct *msg_config_status,
                srv_provbox_result_enum result);

extern void srv_provbox_send_update_msg_info_cnf(
                int dest_mod_id,
                srv_provbox_update_msg_info_req_struct *req_data,
                srv_provbox_result_enum result);

/*
extern void srv_provbox_send_update_msg_num_ind(
                U32 msg_id,
                srv_provbox_box_msg_stat_struct *msg_stat,
                srv_provbox_result_enum result);
*/

extern void srv_provbox_send_um_ready_ind(void);

/*----------------------Job operation-----------------------------------------*/

extern srv_provbox_result_enum srv_provbox_job_submit_new_job(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_job_type_enum job_type,
                                srv_provbox_job_sub_type_enum sub_type,
                                int src_mod,
                                S32 int_value,
                                void *req_data,
                                MMI_BOOL hold_ctrl_buff);

extern srv_provbox_result_enum srv_provbox_job_process_current_job(srv_provbox_cntx_struct *cntx);


/*----------------------ProvBox Context---------------------------------------*/

extern void srv_provbox_mem_send_disk_full_event(srv_provbox_cntx_struct *cntx);

extern srv_provbox_cntx_struct *srv_provbox_cntx_get_cntx(void);

extern srv_provbox_msg_list_struct *srv_provbox_cntx_get_msg_list_by_box_type(
                                        srv_provbox_cntx_struct *cntx,
                                        srv_provbox_box_type_enum box_type,
                                        U32 *msg_num);


/*----------------------ProvBox operate box type------------------------------*/
#define SRV_PROVBOX_GET_SIMPLE_BOX_TYPE(_box_type, _index) ((_box_type) & ((1) << (_index)))

#define SRV_PROVBOX_RET_BOX_TYPE(_box_type, _index) (_box_type) = (_box_type) & (~((1) << (_index)))


/*---------------------- Misc ------------------------------------------------*/
/* Reset factory setting, to remove all messages in @ProvBox and reset the whole application. */
//extern void srv_provbox_restore_factory_setting(void);

extern U8 srv_provbox_change_sim_id(U8 sim_id);

extern srv_provbox_result_enum srv_provbox_set_msg_status_ex(U32 msg_id, srv_provbox_msg_read_status_enum status);
/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/
extern void srv_provbox_new_msg_update_app_hdlr(srv_provbox_msg_cmn_info_struct *cmn_info);

extern void srv_provbox_event_send_update_msg_status_ind(srv_provbox_notify_type_enum type);

extern void srv_provbox_event_send_new_msg_ind(srv_provbox_msg_cmn_info_struct *cmn_info);

extern void srv_provbox_sent_box_full_event(srv_provbox_cntx_struct *cntx);

#ifdef __MMI_PROV_IN_UM__
extern srv_provbox_box_type_enum srv_provbox_box_type_um2pbox(srv_um_msg_box_enum um_box_type);


extern mmi_sim_enum srv_provbox_sim_um2pbox(srv_um_sim_enum um_sim);

extern srv_um_sim_enum srv_provbox_sim_pbox2um(mmi_sim_enum prov_box_sim);



extern srv_provbox_msg_op_enum srv_provbox_op_type_um2pbox(srv_um_mark_several_op_action_enum um_op_type);

extern void srv_provbox_event_send_set_msg_info_ind(
                srv_um_msg_info_struct *um_msg_info, 
                srv_provbox_msg_cmn_info_struct* msg_info);

extern void srv_provbox_event_send_set_sort_info_ind(
                srv_um_list_idx_data_union *list_data, 
                srv_provbox_msg_cmn_info_struct* msg_info,
                const S16 msg_size,
                U8 list_idx_type);
                
extern S32 srv_provbox_evnet_send_set_traverse_process_msg_deatil_ind(
                srv_provbox_msg_cmn_info_struct *info, 
                S16 msg_size,
                U32 um_user_data,
                srv_um_detail_field_enum um_detail_field,
                srv_um_traverse_func um_traverse_callback);

#ifdef __COSMOS_MMI__
extern void srv_provbox_event_send_set_msg_state_ready_ind(
                srv_provbox_callback_func um_callback,
                srv_provbox_result_enum set_result,
                void *user_data);
#endif /* __COSMOS_MMI__ */

extern U8   srv_provbox_msg_handle_um_get_msg_num_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_msg_send_um_get_msg_num_rsp(srv_um_get_msg_num_rsp_struct *msg_num_rsp);

extern void srv_provbox_handle_um_get_msg_num_req(srv_um_get_msg_num_req_struct *data);

extern U8   srv_provbox_msg_handle_um_get_list_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_msg_send_um_get_list_rsp(srv_provbox_um_get_msg_list_rsp_struct *rsp_data);

extern void srv_provbox_handle_um_get_list_req(srv_um_get_msg_list_req_struct *data);

extern U8   srv_provbox_msg_handle_um_get_msg_info_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_send_um_get_msg_info_rsp(srv_um_get_msg_info_rsp_struct *rsp_data);

extern void srv_provbox_handle_um_get_msg_info_req(srv_um_get_msg_info_req_struct *data);

#ifdef __MMI_UM_CONVERSATION_BOX__
extern void srv_provbox_handle_um_traverse_msg_req(srv_um_traverse_msg_req_struct *data);

extern U8   srv_provbox_msg_handle_um_traverse_msg_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_send_um_traverse_msg_rsp(srv_um_traverse_msg_rsp_struct *rsp);
#endif /* __MMI_UM_CONVERSATION_BOX__ */

extern U8 srv_provbox_msg_handle_um_delete_folder_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_send_um_delete_folder_rsp(srv_provbox_result_enum result);

extern void srv_provbox_handle_um_delete_folder_req(srv_um_delete_folder_req_struct *data);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
extern U8 srv_provbox_msg_handle_um_multi_op_req(void *msg, int src_mod, void *peer_buf);

extern void srv_provbox_handle_um_multi_op_req(srv_um_mark_several_op_req_struct *data);

extern void srv_provbox_send_um_multi_op_rsp(srv_um_mark_several_op_rsp_struct *rsp);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

#endif /* __MMI_PROV_IN_UM__ */

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

#endif /* MMI_PROVBOX_SRV_PROT_H */ 

