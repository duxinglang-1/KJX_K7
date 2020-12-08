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
 *   gs_srv_um_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IUm type header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GS_SRV_UM_TYPE_
#define _GS_SRV_UM_TYPE_

#define GS_SRV_UM_MAX_GET_MSG_LIST_NUMBER (100)

/* Max number when get message infomation in one primitive */
#define GS_SRV_UM_MAX_GET_MSG_INFO_NUMBER (5)

/* Max number when get message infomation in one primitive */
#define GS_SRV_UM_MAX_TRAVERSE_MSG_NUMBER (5)

/* Max length of address */
#define GS_SRV_UM_MAX_ADDR_LEN   (70)

/* Max legnth of subject */
#define GS_SRV_UM_MAX_SUBJECT_LEN   (40)

/* For list index maximum length */
#define GS_SRV_UM_MAX_LIST_INDEX_LEN   (15)

/***************************************************
 * For mark several operation,
 * the maximum number of messages during each operation
 * in one application.
 ****************************************************/
#define GS_SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP (5)

/* Max support message type */
#define GS_SRV_UM_MAX_SUPPORT_MSG_TYPE (8)

/* Max support message box */
#define GS_SRV_UM_MAX_SUPPORT_MSG_BOX (12)

/* This enum is used to specify the type of message.*/
typedef enum
{
    GS_SRV_UM_MSG_NONE = 0x00,         /* none */
    GS_SRV_UM_MSG_SMS = 0x01,          /* SMS */
    GS_SRV_UM_MSG_MMS = 0x02,          /* MMS */
    GS_SRV_UM_MSG_WAP_PUSH = 0x04,     /* WAP Push */
    GS_SRV_UM_MSG_PROV = 0x08,         /* Provisioning */
    GS_SRV_UM_MSG_UT = 0x80,           /* UT Message */
    GS_SRV_UM_MSG_ALL = 0xFF,          /* All message type */
    GS_SRV_UM_MSG_END = 0x80
} gs_srv_um_msg_enum;

/* This enum is used to specify the type of address. */
typedef enum
{
   GS_SRV_UM_ADDR_PHONE_NUMBER,        /* phone number */
   GS_SRV_UM_ADDR_EMAIL_ADDRESS,       /* email address */
   GS_SRV_UM_ADDR_IP_ADDRESS,          /* IP address */
   GS_SRV_UM_ADDR_PLAIN_TEXT,          /* plain text */
   GS_SRV_UM_ADDR_EMPTY,
   GS_SRV_UM_ADDR_END                  /* END */
} gs_srv_um_addr_enum;

/* This enum is used to specify the group types of addresses. */
typedef enum
{
    GS_SRV_UM_ADDR_GROUP_TO,           /* To group.*/
//    GS_SRV_UM_ADDR_GROUP_CC,           /* Cc group.*/
//    GS_SRV_UM_ADDR_GROUP_BCC,          /* Bcc group.*/
    GS_SRV_UM_ADDR_GROUP_FROM,         /* From group.*/
    GS_SRV_UM_ADDR_GROUP_TOTAL_NUM     /* Max number of address group.*/
} gs_srv_um_addr_group_enum;

/* This enum is used to specify the type of message box. */
typedef enum
{
    GS_SRV_UM_MSG_BOX_NONE         = 0x0000,               /* None */
    GS_SRV_UM_MSG_BOX_INBOX        = 0x0001,               /* Inbox */
    GS_SRV_UM_MSG_BOX_UNSENT       = 0x0002,               /* Unset box */
    GS_SRV_UM_MSG_BOX_SENT         = 0x0004,               /* Sent box */
    GS_SRV_UM_MSG_BOX_DRAFT        = 0x0008,               /* draft box */
    GS_SRV_UM_MSG_BOX_ARCHIVE      = 0x0010,               /* archive box */
    GS_SRV_UM_MSG_BOX_SIM          = 0x0020,               /* sim box */
    GS_SRV_UM_MSG_BOX_REPORT       = 0x0040,               /* report box */

    GS_SRV_UM_MSG_BOX_PREDEF_TEMPLATES = 0x0100,     /* pre-defined template */
    GS_SRV_UM_MSG_BOX_USRDEF_TEMPLATES = 0x0200,     /* user defined template */

    GS_SRV_UM_MSG_BOX_ALL = GS_SRV_UM_MSG_BOX_INBOX
                         | GS_SRV_UM_MSG_BOX_UNSENT
                         | GS_SRV_UM_MSG_BOX_SENT
                         | GS_SRV_UM_MSG_BOX_DRAFT  
                         | GS_SRV_UM_MSG_BOX_ARCHIVE
                         | GS_SRV_UM_MSG_BOX_SIM
                         | GS_SRV_UM_MSG_BOX_REPORT
                         ,
    GS_SRV_UM_MSG_BOX_END = 0x0800                    /* END */
} gs_srv_um_msg_box_enum;

/* This enum is used to specify the action in mark several mode. */
typedef enum
{
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_NONE,                   /* none action */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE,                 /* delete operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE,        /* move to archive operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM,            /* move to archive operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE,          /* move to archive operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM,            /* move to archive operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE,          /* move to archive operation */
    GS_SRV_UM_MARK_SEVERAL_OP_ACTION_MAX                     /* number of action type */
} gs_srv_um_mark_several_op_action_enum;

/* This enum is used to specify the SIM information. */
typedef enum
{
    GS_SRV_UM_SIM_UNCLASSIFIED = 0x01,      /* unclassified message */
    GS_SRV_UM_SIM_GSM_SIM1 = 0x02,          /* SIM1 card message */
    GS_SRV_UM_SIM_GSM_SIM2 = 0x04,          /* SIM2 card message */
    GS_SRV_UM_SIM_ALL = 0xff                /* all message */
} gs_srv_um_sim_enum;

/* This enum is used to specify the type of index sorting information. */
typedef enum
{
    GS_SRV_UM_LIST_IDX_TIMESTAMP,          /* Timestamp */
    GS_SRV_UM_LIST_IDX_ADDRESS,            /* Address */
    GS_SRV_UM_LIST_IDX_SUBJECT,            /* subject */
    GS_SRV_UM_LIST_IDX_READ_STATUS,        /* read status */
    GS_SRV_UM_LIST_IDX_MSG_TYPE,           /* message type */
    GS_SRV_UM_LIST_IDX_MSG_SIZE,           /* message size */
    GS_SRV_UM_LIST_IDX_TOTAL               /* TOTAL */
} gs_srv_um_list_idx_enum;


/* This enum is used to specify the type sorting algorithm */
typedef enum
{
    GS_SRV_UM_SORT_ALGO_INSERTION,         /* insertion sort */
    GS_SRV_UM_SORT_ALGO_QUICK,             /* quick sort */
    GS_SRV_UM_SORT_ALGO_MERGE,             /* merge sort */
    GS_SRV_UM_SORT_ALGO_HEAP,              /* heap sort */
    GS_SRV_UM_SORT_ALGO_TOTAL              /* TOTAL */
} gs_srv_um_sort_algorithm_enum;

/* This enum is used to specify the type sorting order */
typedef enum
{
    GS_SRV_UM_SORT_ORDER_UNCLASSIFIED,     /* unclassified order */
    GS_SRV_UM_SORT_ORDER_ASCENDING,        /* Ascending order */
    GS_SRV_UM_SORT_ORDER_DESCENDING        /* descend order */
} gs_srv_um_sort_order_enum;


/*  This enum is used to specify the field in mmi_um_msg_detail_struct.
    Application can use bitwise OR operator to check if this field is
    required in this primitive */
typedef enum
{
    GS_SRV_UM_DETAIL_NONE          = 0x0000,
    GS_SRV_UM_DETAIL_MSG_BOX       = 0x0001,
    GS_SRV_UM_DETAIL_TIMESTAMP     = 0x0002,
    GS_SRV_UM_DETAIL_READ_STATUS   = 0x0004,
    GS_SRV_UM_DETAIL_MSG_SIZE      = 0x0008,
    GS_SRV_UM_DETAIL_SUBJECT       = 0x0010,
    GS_SRV_UM_DETAIL_ADDRESS       = 0x0020,     /* Send: first recipient in "To", Receive: recipeint in "From" */
    GS_SRV_UM_DETAIL_MULTI_ADDRESS = 0x0040,     /* Send: all recipients in "To", Receive: only recipient in "From"*/
    GS_SRV_UM_DETAIL_SIM_ID        = 0x0080,
    GS_SRV_UM_DETAIL_ALL           = 0xFFFF
} gs_srv_um_detail_field_enum;

/* This enum is used to specify the hash type */
typedef enum
{
    GS_SRV_UM_HASH_NONE,
    GS_SRV_UM_HASH_PHONEBOOK_ID,
    GS_SRV_UM_HASH_INTEGER64,
    GS_SRV_UM_HASH_STRING
} gs_srv_um_hash_enum;

/* This enum is used to spcify the list type */
typedef enum
{
    GS_SRV_UM_LIST_TYPE_MSG_NODE,
    GS_SRV_UM_LIST_TYPE_THREAD
} gs_srv_um_list_type_enum;

/* This enum is used UM internal */
typedef enum{
	GS_SRV_UM_EG_GET_THREAD_ID     = 0x00000001,
    GS_SRV_UM_EG_LOOKUP_NUMBER     = 0x00000002,
	GS_SRV_UM_EG_RESET_MASK        = 0x0FFFFFFF
}gs_srv_um_event_group_enum;

/* This enum is used to present the result of UM Interface */
typedef enum
{
    GS_SRV_UM_RESULT_INVALID_PARA          = -0x00000001,
    GS_SRV_UM_RESULT_NO_MEMORY             = -0x00000002,
    GS_SRV_UM_RESULT_DATA_NOT_FOUND        = -0x00000003,
    GS_SRV_UM_RESULT_TOO_MANY_PROCESS      = -0x00000004,
    GS_SRV_UM_RESULT_INVALID_PID           = -0x00000005,
    GS_SRV_UM_RESULT_CANCELLLED            = -0x00000006,
    GS_SRV_UM_RESULT_PARTIAL_READY         = -0x00000008,
    GS_SRV_UM_RESULT_NOT_READY             = -0x00000009,
    GS_SRV_UM_RESULT_NOT_SUPPORT           = -0x0000000A,
    GS_SRV_UM_RESULT_TOO_MANY_MESSAGE      = -0x0000000B,
    GS_SRV_UM_RESULT_TOO_MANY_LIST         = -0x0000000C,
    GS_SRV_UM_RESULT_BUFFER_FULL           = -0x0000000D,
    GS_SRV_UM_RESULT_TOO_MANY_THREAD       = -0x0000000E,

    GS_SRV_UM_RESULT_PROCESS_BUSY      = -0x00001004,
    GS_SRV_UM_RESULT_PROCESS_WAITING   = -0x00001005,
    GS_SRV_UM_RESULT_PROCESS_FINISH    = -0x00001006,

    GS_SRV_UM_RESULT_UNKNOWN_ERROR     = -0x7FFFFFFF,

    GS_SRV_UM_RESULT_OK    = 0
} gs_srv_um_result_enum;

typedef enum
{
    GS_SRV_UM_NOTIFY_LIST_RELEASED_IND,            /* Notify the list cntx is released */
    GS_SRV_UM_NOTIFY_LIST_CLEANED_IND              /* Notify the list cntx is cleaned */
} gs_srv_um_notiy_event_enum;

typedef enum
{
    GS_SRV_UM_REFRESH_NONE,                        /* unknown reason, default value */
    GS_SRV_UM_REFRESH_NEW_MSG,                     /* new message coming */
    GS_SRV_UM_REFRESH_MSG_DELETED,                 /* some message is deleted */
    GS_SRV_UM_REFRESH_MSG_STORAGE_CHANGED,         /* some message is moved to archive or different folder */
    GS_SRV_UM_REFRESH_MSG_STATUS_CHANGED,          /* status of message is changed, ex: unread -> read */
    GS_SRV_UM_REFRESH_MSG_CONTENT_CHANGED,         /* the conent is changed */
    GS_SRV_UM_REFRESH_TOTAL
} gs_srv_um_refresh_enum;

/* To identify a message thread */
typedef struct
{
    gs_srv_um_hash_enum type;             /* the type of hash value */
    U64 value;                  /* the hash value */
} gs_srv_um_thread_id_struct;

/* Move this structure to UmSrvStruct.h if possible */
typedef struct
{
    U32 msg_id;                              /* message index */
    U32 timestamp;                           /* message timestamp array */
    gs_srv_um_addr_enum address_type;
    U8 address_length;                       /* Number of characters in address string */
    WCHAR address[GS_SRV_UM_MAX_ADDR_LEN + 1];     /* sender address for MT msg; receiver address for MO msg */
    U8 subject_length;                       /* Number of characters in subject string */
    WCHAR subject[GS_SRV_UM_MAX_SUBJECT_LEN + 1];  /* subject for MMS, WAP Push and E-mai; part of content for SMS */
    U16 icon_id;
    gs_srv_um_sim_enum sim_id;                         /* request to the corresponding sim card */
    U16 csk_icon_id;
    gs_srv_um_thread_id_struct thread_id;              /* thread id */
} gs_srv_um_msg_info_struct;

typedef struct
{
    gs_srv_um_msg_enum msg_type;                   /* message type */
    U32 msg_id;                                 /* message id */
} gs_srv_um_msg_node_struct;

/* To identify a message box */
typedef struct
{
    gs_srv_um_msg_enum msg_type;                   /* the message type in box */
    gs_srv_um_msg_box_enum msg_box_type;           /* the type of box */
    gs_srv_um_sim_enum sim_id;                     /* the sim id of messages */
} gs_srv_um_box_identity_struct;

/* Filter used to get message list */
typedef struct
{
    gs_srv_um_list_idx_enum idx_type;              /* the index data type */
    gs_srv_um_sort_order_enum order;               /* the order of sorting */
    gs_srv_um_thread_id_struct thread_id;          /* messages in the thread ,do NOT support now!*/
} gs_srv_um_list_filter_struct;

/* To identify a message list */
typedef struct
{
//    gs_srv_um_list_type_enum list_type;                        /* the type of list */
//    gs_srv_um_box_identity_struct msg_box;                     /* Message box  */
//    gs_srv_um_list_filter_struct filter;                       /* Sorting type */
    void *list;                                             /* Data list, may be gs_srv_um_msg_node_struct or gs_srv_um_thread_id_struct*/
    U16 msg_number;                                         /* Number of nodes */
} gs_srv_um_list_cntx_struct;


/* This structure is used to specify thread information. */
typedef struct
{
    gs_srv_um_thread_id_struct thread_id;       /* A identifier to indicate this message thread */
    gs_srv_um_msg_node_struct list_head;        /* head of message list in this thread, normally is the neweset one */
    U16 total_msg_number;                    /* total message in this message thread */
    U16 unread_msg_number;                   /* unread message in this message thread */
} gs_srv_um_thread_info_struct;

/*********************************
 *  Process Result Structure
 ********************************************/

/* The structure of "Get Message Number" result */
typedef struct
{
    S32 error;                              /* error code */
    gs_srv_um_msg_enum msg_type;               /* message type */
    gs_srv_um_sim_enum sim_id;                 /* sim id */
    U16 inbox_msg_number;                   /* inbox message number */
    U16 inbox_unread_msg_number;            /* inbox unread message number */
    U16 unsent_msg_number;                  /* message number in unsent box */
    U16 sent_msg_number;                    /* message number in sent box */
    U16 draft_msg_number;                   /* message number if draft box */
//#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    U16 archive_msg_number;                 /* message number in archive box */
//#endif
//#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 sim_msg_number;                     /* message number in sim box */
//#endif
//#ifdef __MMI_UM_REPORT_BOX__
    U16 report_msg_number;                  /* message number in report box */
//#endif
} gs_srv_um_get_msg_num_result;

typedef struct
{
    S32 error;                                      /* error code */
    union
    {
        S32 msg_number;                                 /* message number */
        S32 thread_number;
    }n;
} gs_srv_um_get_list_result;

/* The structure of "Get Message List" result */
typedef gs_srv_um_get_list_result gs_srv_um_get_msg_list_result;

/* The structure of "Get Message Info" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} gs_srv_um_get_msg_info_result;

/* The structure of "Mark Several Operation" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} gs_srv_um_mark_several_op_result;

/* The structure of "Traverse Message" result */
typedef struct
{
    S32 error;                                      /* error code */
    S32 msg_number;                                 /* message number */
} gs_srv_um_traverse_msg_result;

/* The structure of "Get Thread List" result */
typedef gs_srv_um_get_list_result gs_srv_um_get_thread_list_result;

/* The structure of "Get Thread Info" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} gs_srv_um_get_thread_info_result;

/* The structure of "Mark Several Thread Operation" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} gs_srv_um_mark_several_thread_op_result;

/* The structure of "Delete Folder" result */
typedef struct
{
    S32 error;                                      /* error code */
    gs_srv_um_box_identity_struct msg_box;             /* message box */
} gs_srv_um_delete_folder_result;
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
/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_general_cb
 * DESCRIPTION
 *  Callback function to return the result
 * PARAMETERS
 *  pid:        [IN]   The process id
 *  rsp:        [IN]   The result
 *  user_data:  [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_general_cb) (S32 pid, void* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_msg_num_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Number"
 * PARAMETERS
 *  pid:        [IN]   The process id
 *  rsp:        [IN]   The result
 *  user_data:  [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_get_msg_num_cb) (S32 pid, gs_srv_um_get_msg_num_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_get_list_cb) (S32 pid, gs_srv_um_get_list_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_msg_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef gs_srv_um_get_list_cb gs_srv_um_get_msg_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_msg_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_get_msg_info_cb) (S32 pid, gs_srv_um_get_msg_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_mark_several_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_mark_several_op_cb) (S32 pid, gs_srv_um_mark_several_op_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_traverse_msg_cb
 * DESCRIPTION
 *  Callback function to return the result of "Traverse Message"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_traverse_msg_cb) (S32 pid, gs_srv_um_traverse_msg_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_thread_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef gs_srv_um_get_list_cb gs_srv_um_get_thread_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_thread_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_get_thread_info_cb) (S32 pid, gs_srv_um_get_thread_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_mark_several_thread_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Thread Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_mark_several_thread_op_cb) (S32 pid, gs_srv_um_mark_several_thread_op_result* rsp, S32 user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_delete_folder_cb
 * DESCRIPTION
 *  Callback function to return the result of "Delete Folder"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_delete_folder_cb) (S32 pid, gs_srv_um_delete_folder_result* rsp, S32 user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_thread_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Thread List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  para:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef gs_srv_um_get_list_cb gs_srv_um_get_thread_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_get_thread_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_get_thread_info_cb) (S32 pid, gs_srv_um_get_thread_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_mark_several_thread_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Thread Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  gs_srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*gs_srv_um_mark_several_thread_op_cb) (S32 pid, gs_srv_um_mark_several_thread_op_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  gs_srv_um_list_notify_handler
 * DESCRIPTION
 *  Callback function to notify AP the list is changed. ex: release, clean
 * PARAMETERS
 *  event:           [IN]   Type of notification, SRV_UM_NOTIFY_LIST_RELEASED_IND or
 *                             SRV_UM_NOTIFY_LIST_CLEANED_IND
 *  list_cid:        [IN]   list cid
 *  user_data:       [IN]   User data
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*gs_srv_um_notify_list_handler) (S32 event, S32 list_cid, S32 user_data);


#endif //_GS_SRV_UM_TYPE_


