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
 * UMDefs.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#ifndef UM_SRV_DEFS_H
#define UM_SRV_DEFS_H

/* This file is used by MMI task and other task,Please do not use MMI type. */

/**********  KAL Layer Header **************/
#include "kal_general_types.h"
#include "customer_ps_inc.h"
#include "custom_wap_config.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "customer_email_num.h"
#include "mmi_msg_context.h"

#ifdef __MMI_PROV_IN_UM__
#include "Custom_ProvBox.h"
#endif
#if !defined(__MSG_SMS_EMAIL_SUPPORT__) && !defined(__MMI_MMS_IN_UM__) && !defined(__MMI_PUSH_IN_UM__) && !defined(__MMI_PROV_IN_UM__)
#include "SmsSrvGprot.h"
#endif

//#define __SRV_UM_THREAD_MESSAGE_SUPPORT__
//#define __SRV_UM_UT__

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
/* Maximum number when get message list in one primitive */
#define SRV_UM_MAX_GET_MSG_LIST_NUMBER (40)
#else
#define SRV_UM_MAX_GET_MSG_LIST_NUMBER (100)
#endif
/* Max number when get message infomation in one primitive */
#define SRV_UM_MAX_GET_MSG_INFO_NUMBER (5)

/* Max number when get message infomation in one primitive */
#define SRV_UM_MAX_TRAVERSE_MSG_NUMBER (5)

/* Max length of address */
#if !defined(__MSG_SMS_EMAIL_SUPPORT__) && !defined(__MMI_MMS_IN_UM__) && !defined(__MMI_PUSH_IN_UM__) && !defined(__MMI_PROV_IN_UM__)
#define SRV_UM_MAX_ADDR_LEN   (SRV_SMS_MAX_ADDR_LEN)
#else
#define SRV_UM_MAX_ADDR_LEN   (MMI_EMAIL_MAX_ADDR_LEN)
#endif

/* Max legnth of subject */
#if !defined(__MSG_SMS_EMAIL_SUPPORT__) && !defined(__MMI_MMS_IN_UM__) && !defined(__MMI_PUSH_IN_UM__) && !defined(__MMI_PROV_IN_UM__)
#define SRV_UM_MAX_SUBJECT_LEN   (SRV_SMS_MSG_INFO_CONTENT_LEN)
#else
#define SRV_UM_MAX_SUBJECT_LEN   (40)
#endif

/* For list index maximum length */
#define SRV_UM_MAX_LIST_INDEX_LEN   (15)

/***************************************************
 * For mark several operation,
 * the maximum number of messages during each operation
 * in one application.
 ****************************************************/
#define SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP (5)

/* Max support message type */
#define SRV_UM_MAX_SUPPORT_MSG_TYPE (8)

/* Max support message box */
#define SRV_UM_MAX_SUPPORT_MSG_BOX (12)

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/* Max SMS message number per box. */
#define SRV_UM_MAX_SMS_MSG_NUM_PER_BOX          ((CM_SMS_MAX_ENTRY_NUM) > (CM_SMS_MAX_ARMSG_NUM) ? (CM_SMS_MAX_ENTRY_NUM) : (CM_SMS_MAX_ARMSG_NUM) )
#else
#define SRV_UM_MAX_SMS_MSG_NUM_PER_BOX          CM_SMS_MAX_ENTRY_NUM
#endif

#ifdef __MMI_MMS_IN_UM__
/* Max MMS message number per box. */
#define SRV_UM_MAX_MMS_MSG_NUM_PER_BOX          ((WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG - 1) + WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG_ON_CARD)
#else
#define SRV_UM_MAX_MMS_MSG_NUM_PER_BOX          (0)
#endif

#ifdef __MMI_PUSH_IN_UM__
/* Max push message number per box. */
#define SRV_UM_MAX_PUSH_MSG_NUMB_PER_BOX        WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG
#else
#define SRV_UM_MAX_PUSH_MSG_NUMB_PER_BOX        (0)
#endif

#ifdef __MMI_PROV_IN_UM__
/* Max provisioning message number per box. */
#define SRV_UM_MAX_PROV_MSG_NUM_PER_BOX         CUSTOM_PROVBOX_MAX_MSG_NUM_PER_BOX
#else
#define SRV_UM_MAX_PROV_MSG_NUM_PER_BOX         (0)
#endif

/* Max message number supportted by UM */
#define SRV_UM_MAX_MSG_NUM          (SRV_UM_MAX_SMS_MSG_NUM_PER_BOX + \
                                     SRV_UM_MAX_MMS_MSG_NUM_PER_BOX + \
                                     SRV_UM_MAX_PUSH_MSG_NUMB_PER_BOX + \
                                     SRV_UM_MAX_PROV_MSG_NUM_PER_BOX)

#define SRV_UM_MAX_THREAD_NUM   SRV_UM_MAX_MSG_NUM

#define SRV_UM_EXTEND_ADDRESS_NUM 2

/* This enum is used to specify the type of message.*/
typedef enum
{
    SRV_UM_MSG_NONE = 0x00,         /* none */
    SRV_UM_MSG_SMS = 0x01,          /* SMS */
    SRV_UM_MSG_MMS = 0x02,          /* MMS */
    SRV_UM_MSG_WAP_PUSH = 0x04,     /* WAP Push */
    SRV_UM_MSG_PROV = 0x08,         /* Provisioning */
    SRV_UM_MSG_UT = 0x80,           /* UT Message */
    SRV_UM_MSG_ALL = 0xFF,          /* All message type */
    SRV_UM_MSG_END = 0x80
} srv_um_msg_enum;

/* This enum is used to specify the type of address. */
typedef enum
{
   SRV_UM_ADDR_PHONE_NUMBER,        /* phone number */
   SRV_UM_ADDR_EMAIL_ADDRESS,       /* email address */
   SRV_UM_ADDR_IP_ADDRESS,          /* IP address */
   SRV_UM_ADDR_PLAIN_TEXT,          /* plain text */
   SRV_UM_ADDR_EMPTY,
   SRV_UM_ADDR_END                  /* END */
} srv_um_addr_enum;

/* This enum is used to specify the group types of addresses. */
typedef enum
{
    SRV_UM_ADDR_GROUP_TO,           /* To group.*/
//    SRV_UM_ADDR_GROUP_CC,           /* Cc group.*/
//    SRV_UM_ADDR_GROUP_BCC,          /* Bcc group.*/
    SRV_UM_ADDR_GROUP_FROM,         /* From group.*/
    SRV_UM_ADDR_GROUP_TOTAL_NUM     /* Max number of address group.*/
} srv_um_addr_group_enum;

/* This enum is used to specify the type of message box. */
typedef enum
{
    SRV_UM_MSG_BOX_NONE         = 0x0000,               /* None */
    SRV_UM_MSG_BOX_INBOX        = 0x0001,               /* Inbox */
    SRV_UM_MSG_BOX_UNSENT       = 0x0002,               /* Unset box */
    SRV_UM_MSG_BOX_SENT         = 0x0004,               /* Sent box */
    SRV_UM_MSG_BOX_DRAFT        = 0x0008,               /* draft box */
    SRV_UM_MSG_BOX_ARCHIVE      = 0x0010,               /* archive box */
    SRV_UM_MSG_BOX_SIM          = 0x0020,               /* sim box */
    SRV_UM_MSG_BOX_REPORT       = 0x0040,               /* report box */

    SRV_UM_MSG_BOX_PREDEF_TEMPLATES = 0x0100,     /* pre-defined template */
    SRV_UM_MSG_BOX_USRDEF_TEMPLATES = 0x0200,     /* user defined template */
    SRV_UM_MSG_BOX_SECURITY         = 0x0400,     /* security box */

#ifdef __MMI_UM_CONVERSATION_BOX_WITH_OUTBOX__
    SRV_UM_MSG_BOX_CONVERSATION = SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT | SRV_UM_MSG_BOX_UNSENT,
#else
    SRV_UM_MSG_BOX_CONVERSATION = SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT,
#endif

    SRV_UM_MSG_BOX_ALL = SRV_UM_MSG_BOX_INBOX
                         | SRV_UM_MSG_BOX_UNSENT
                         | SRV_UM_MSG_BOX_SENT
                         | SRV_UM_MSG_BOX_DRAFT
                    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                         | SRV_UM_MSG_BOX_ARCHIVE
                    #endif
                    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
                         | SRV_UM_MSG_BOX_SIM
                    #endif
                    #ifdef __MMI_UM_REPORT_BOX__
                         | SRV_UM_MSG_BOX_REPORT
                    #endif
                         ,
    SRV_UM_MSG_BOX_END = 0x0800                    /* END */
} srv_um_msg_box_enum;

/* This enum is used to specify the action in mark several mode. */
typedef enum
{
    SRV_UM_MARK_SEVERAL_OP_ACTION_NONE,                   /* none action */
    SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE,                 /* delete operation */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE,        /* move to archive operation */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM,            /* move to archive operation */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE,          /* move to archive operation */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM,            /* copy to sim */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE,          /* copy to phone */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_ARCHIVE,        /* copy to archive */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM1,           /* copy to sim1 */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM2,           /* copy to sim2 */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM3,           /* copy to sim3 */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM4,           /* copy to sim4 */
    SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_MEMORY_CARD,    /* copy to memory card */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SECURITY,       /* move to security box */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ORIGINAL_BOX,   /* move back to original box from security */
    SRV_UM_MARK_SEVERAL_OP_ACTION_MAX                     /* number of action type */
} srv_um_mark_several_op_action_enum;

/* This enum is used to specify the SIM information. */
typedef enum
{
    SRV_UM_SIM_UNCLASSIFIED = 0x01,      /* unclassified message */
    SRV_UM_SIM_GSM_SIM1 = 0x02,          /* SIM1 card message */
    SRV_UM_SIM_GSM_SIM2 = 0x04,          /* SIM2 card message */
    SRV_UM_SIM_GSM_SIM3 = 0x08,          /* SIM3 card message */
    SRV_UM_SIM_GSM_SIM4 = 0x10,          /* SIM4 card message */    
    
    SRV_UM_SIM_ALL = 0xff                /* all message */
} srv_um_sim_enum;

/* This enum is used to specify the type of index sorting information. */
typedef enum
{
    SRV_UM_LIST_IDX_TIMESTAMP,          /* Timestamp */
    SRV_UM_LIST_IDX_ADDRESS,            /* Address */
    SRV_UM_LIST_IDX_SUBJECT,            /* subject */
    SRV_UM_LIST_IDX_READ_STATUS,        /* read status */
    SRV_UM_LIST_IDX_MSG_TYPE,           /* message type */
    SRV_UM_LIST_IDX_MSG_SIZE,           /* message size */
    SRV_UM_LIST_IDX_TOTAL               /* TOTAL */
} srv_um_list_idx_enum;


/* This enum is used to specify the type sorting algorithm */
typedef enum
{
    SRV_UM_SORT_ALGO_INSERTION,         /* insertion sort */
    SRV_UM_SORT_ALGO_QUICK,             /* quick sort */
    SRV_UM_SORT_ALGO_MERGE,             /* merge sort */
    SRV_UM_SORT_ALGO_HEAP,              /* heap sort */
    SRV_UM_SORT_ALGO_TOTAL              /* TOTAL */
} srv_um_sort_algorithm_enum;

/* This enum is used to specify the type sorting order */
typedef enum
{
    SRV_UM_SORT_ORDER_UNCLASSIFIED,     /* unclassified order */
    SRV_UM_SORT_ORDER_ASCENDING,        /* Ascending order */
    SRV_UM_SORT_ORDER_DESCENDING        /* descend order */
} srv_um_sort_order_enum;


/*  This enum is used to specify the field in mmi_um_msg_detail_struct.
    Application can use bitwise OR operator to check if this field is
    required in this primitive */
typedef enum
{
    SRV_UM_DETAIL_NONE          = 0x0000,
    SRV_UM_DETAIL_MSG_BOX       = 0x0001,
    SRV_UM_DETAIL_TIMESTAMP     = 0x0002,
    SRV_UM_DETAIL_READ_STATUS   = 0x0004,
    SRV_UM_DETAIL_MSG_SIZE      = 0x0008,
    SRV_UM_DETAIL_SUBJECT       = 0x0010,
    SRV_UM_DETAIL_ADDRESS       = 0x0020,     /* Send: first recipient in "To", Receive: recipeint in "From" */
    SRV_UM_DETAIL_MULTI_ADDRESS = 0x0040,     /* Send: all recipients in "To", Receive: only recipient in "From"*/
    SRV_UM_DETAIL_SIM_ID        = 0x0080,
    SRV_UM_DETAIL_MSG_STATUS    = 0x0100,
    SRV_UM_DETAIL_ALL           = 0xFFFF
} srv_um_detail_field_enum;

/* This enum is used to specify the hash type */
typedef enum
{
    SRV_UM_HASH_NONE,
    SRV_UM_HASH_PHONEBOOK_ID,
    SRV_UM_HASH_INTEGER64,
    SRV_UM_HASH_STRING,
    SRV_UM_ADDR_MULTIPLE_ADDR   /* put messages with multiple address into isolated group */
} srv_um_hash_enum;

/* This enum is used to spcify the list type */
typedef enum
{
    SRV_UM_LIST_TYPE_MSG_NODE,
    SRV_UM_LIST_TYPE_THREAD,
    SRV_UM_LIST_TYPE_ALL
} srv_um_list_type_enum;

/* This enum is used UM internal */
typedef enum{
	SRV_UM_EG_GET_THREAD_ID     = 0x00000001,
    SRV_UM_EG_LOOKUP_NUMBER     = 0x00000002,
	SRV_UM_EG_RESET_MASK        = 0x0FFFFFFF
}srv_um_event_group_enum;

/* This enum is used to present the result of UM Interface */
typedef enum
{
    SRV_UM_RESULT_INVALID_PARA          = -0x00000001,
    SRV_UM_RESULT_NO_MEMORY             = -0x00000002,
    SRV_UM_RESULT_DATA_NOT_FOUND        = -0x00000003,
    SRV_UM_RESULT_TOO_MANY_PROCESS      = -0x00000004,
    SRV_UM_RESULT_INVALID_PID           = -0x00000005,
    SRV_UM_RESULT_CANCELLLED            = -0x00000006,
    SRV_UM_RESULT_PARTIAL_READY         = -0x00000008,
    SRV_UM_RESULT_NOT_READY             = -0x00000009,
    SRV_UM_RESULT_NOT_SUPPORT           = -0x0000000A,
    SRV_UM_RESULT_TOO_MANY_MESSAGE      = -0x0000000B,
    SRV_UM_RESULT_TOO_MANY_LIST         = -0x0000000C,
    SRV_UM_RESULT_BUFFER_FULL           = -0x0000000D,
    SRV_UM_RESULT_TOO_MANY_THREAD       = -0x0000000E,

    SRV_UM_RESULT_PROCESS_BUSY      = -0x00001004,
    SRV_UM_RESULT_PROCESS_WAITING   = -0x00001005,
    SRV_UM_RESULT_PROCESS_FINISH    = -0x00001006,

    SRV_UM_RESULT_UNKNOWN_ERROR     = -0x7FFFFFFF,

    SRV_UM_RESULT_OK    = 0
} srv_um_result_enum;

typedef enum
{
    SRV_UM_NOTIFY_LIST_RELEASED_IND,            /* Notify the list cntx is released */
    SRV_UM_NOTIFY_LIST_CLEANED_IND              /* Notify the list cntx is cleaned */
} srv_um_notiy_event_enum;

typedef enum
{
    SRV_UM_REFRESH_NONE,                        /* unknown reason, default value */
    SRV_UM_REFRESH_NEW_INCOMING_MSG,            /* new message coming */
    SRV_UM_REFRESH_CREATE_MSG,                  /* 1. MO message,
                                                   2. upload message from phonesuite,
                                                   3. copy message to another folder */
    SRV_UM_REFRESH_MSG_DELETED,                 /* message is deleted */
    SRV_UM_REFRESH_MSG_FOLDER_CHANGED,          /* message is moved to another folder */
    SRV_UM_REFRESH_MSG_STATUS_CHANGED,          /* status of message is changed,
                                                   ex: unread -> read
                                                   ex: sim -> phone     */
    SRV_UM_REFRESH_MSG_CONTENT_CHANGED,         /* the conent is changed */
    SRV_UM_REFRESH_TOTAL
} srv_um_refresh_enum;


/* To identify a message thread */
typedef struct
{
    srv_um_hash_enum type;             /* the type of hash value */
    srv_um_sim_enum sim_id;
    kal_uint64 value;                  /* the hash value */
} srv_um_thread_id_struct;

/* Move this structure to UmSrvStruct.h if possible */
typedef struct
{
    kal_uint32 msg_id;                              /* message index */
    kal_uint32 timestamp;                           /* message timestamp array */
    srv_um_addr_enum address_type;
    kal_uint8 address_length;                       /* Number of characters in address string */
    kal_uint8 subject_length;                       /* Number of characters in subject string */
#ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    kal_uint8 address_number;
    kal_bool address_more;
#endif
    kal_wchar address[SRV_UM_MAX_ADDR_LEN + 1];     /* sender address for MT msg; receiver address for MO msg */
#ifdef  __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    kal_wchar address_ext[SRV_UM_EXTEND_ADDRESS_NUM][SRV_UM_MAX_ADDR_LEN + 1];
#endif
    kal_wchar subject[SRV_UM_MAX_SUBJECT_LEN + 1];  /* subject for MMS, WAP Push and E-mai; part of content for SMS */

    kal_uint16 icon_id;
    kal_uint16 csk_icon_id;
    kal_uint32 msg_status;

#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum sim_id;                         /* request to the corresponding sim card */
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_id_struct thread_id;              /* thread id */
#endif
} srv_um_msg_info_struct;

#endif /* __UMDEFS_H__ */

