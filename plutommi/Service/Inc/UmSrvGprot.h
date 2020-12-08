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
 * UMSrvGprot.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef UM_SRV_GPROT_H
#define UM_SRV_GPROT_H

/* This file is used by MMI task only, please use MMI type as possible */

/**********  KAL Layer Header **************/
#include "kal_general_types.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "customer_email_num.h"

#include "UmSrvDefs.h"

/*********************************
 *  structure
 ********************************************/

/* To identify a message */
typedef struct
{
    srv_um_msg_enum msg_type;                   /* message type */
    U32 msg_id;                                 /* message id */
} srv_um_msg_node_struct;

/* To identify a message box */
typedef struct
{
    srv_um_msg_enum msg_type;                   /* the message type in box */
    srv_um_msg_box_enum msg_box_type;           /* the type of box */
    srv_um_sim_enum sim_id;                     /* the sim id of messages */
} srv_um_box_identity_struct;

/* Filter used to get message list */
typedef struct
{
    srv_um_list_idx_enum idx_type;              /* the index data type */
    srv_um_sort_order_enum order;               /* the order of sorting */
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    srv_um_thread_id_struct thread_id;          /* messages in the thread */
#endif
} srv_um_list_filter_struct;

/* To identify a message list */
typedef struct
{
    srv_um_list_type_enum list_type;                        /* the type of list */
    srv_um_box_identity_struct msg_box;                     /* Message box  */
    srv_um_list_filter_struct filter;                       /* Sorting type */
    void *list;                                             /* Data list, may be srv_um_msg_node_struct or srv_um_thread_id_struct*/
    U16 msg_number;                                         /* Number of nodes */
} srv_um_list_cntx_struct;

/* This structure is used to specify thread information. */
typedef struct
{
    srv_um_thread_id_struct thread_id;       /* A identifier to indicate this message thread */
    srv_um_msg_node_struct list_head;        /* head of message list in this thread, normally is the neweset one */
//    U32 timestamp;                           /* timestamp of the list head */
//    srv_um_msg_link_list_struct *msg_list;   /* message list in this message thread */
    U16 total_msg_number;                    /* total message in this message thread */
    U16 unread_msg_number;                   /* unread message in this message thread */
} srv_um_thread_info_struct;

/*********************************
 *  Process Result Structure
 ********************************************/

/* The structure of "Get Message Number" result */
typedef struct
{
    S32 error;                              /* error code */
    srv_um_msg_enum msg_type;               /* message type */
    srv_um_sim_enum sim_id;                 /* sim id */
    U16 inbox_msg_number;                   /* inbox message number */
    U16 inbox_unread_msg_number;            /* inbox unread message number */
    U16 unsent_msg_number;                  /* message number in unsent box */
    U16 sent_msg_number;                    /* message number in sent box */
    U16 draft_msg_number;                   /* message number if draft box */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    U16 archive_msg_number;                 /* message number in archive box */
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 sim_msg_number;                     /* message number in sim box */
#endif
#ifdef __MMI_UM_REPORT_BOX__
    U16 report_msg_number;                  /* message number in report box */
#endif
} srv_um_get_msg_num_result;

typedef struct
{
    S32 error;                                      /* error code */
    union
    {
        S32 msg_number;                                 /* message number */
        S32 thread_number;
    }n;
} srv_um_get_list_result;

/* The structure of "Get Message List" result */
typedef srv_um_get_list_result srv_um_get_msg_list_result;

/* The structure of "Get Message Info" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} srv_um_get_msg_info_result;

/* The structure of "Mark Several Operation" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} srv_um_mark_several_op_result;

/* The structure of "Traverse Message" result */
typedef struct
{
    S32 error;                                      /* error code */
    S32 msg_number;                                 /* message number */
} srv_um_traverse_msg_result;

/* The structure of "Get Thread List" result */
typedef srv_um_get_list_result srv_um_get_thread_list_result;

/* The structure of "Get Thread Info" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} srv_um_get_thread_info_result;

/* The structure of "Mark Several Thread Operation" result */
typedef struct
{
    S32 error;                                      /* error code */
    U16 no_of_success;                              /* number of success */
    U16 no_of_fail;                                 /* number of fail */
} srv_um_mark_several_thread_op_result;

/* The structure of "Delete Folder" result */
typedef struct
{
    S32 error;                                      /* error code */
    srv_um_box_identity_struct msg_box;             /* message box */
} srv_um_delete_folder_result;

typedef enum
{
    EVT_ID_SRV_UM_NOTIFY_READY = (SRV_UNIFIED_MESSAGE_BASE + 1),  /* Notify ready indication */
    EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG,                           /* Notify highlight message indication */
    EVT_ID_SRV_UM_NOTIFY_REFRESH,                                 /* Notify refresh indication */
    EVT_ID_SRV_UM_TOTAL
} srv_um_event_enum;

/* event structure for EVT_ID_SRV_UM_NOTIFY_READY */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    MMI_BOOL result;                        /* KAL_TRUE means ready; KAL_FALSE means initialization failure */
    srv_um_msg_enum msg_type;               /* Type of ready message */
} srv_um_notify_ready_evt_struct;

/* event structure for EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    U32 msg_id;
} srv_um_notify_highlight_msg_evt_struct;

/* event structure for EVT_ID_SRV_UM_NOTIFY_REFRESH */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    srv_um_refresh_enum refresh_type;       /* reason to send refresh indication, 0: unknown */
    U32 msg_id;                             /* which message is changed, 0: unknown */
    srv_um_addr_enum addr_type;             /* the address type, only used in new message */
    U16 address[SRV_UM_MAX_ADDR_LEN + 1];  /* sender address, only used in new message */
} srv_um_notify_refresh_evt_struct;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_general_cb
 * DESCRIPTION
 *  Callback function to return the result
 * PARAMETERS
 *  pid:        [IN]   The process id
 *  rsp:        [IN]   The result
 *  user_data:  [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_general_cb) (S32 pid, void* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_msg_num_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Number"
 * PARAMETERS
 *  pid:        [IN]   The process id
 *  rsp:        [IN]   The result
 *  user_data:  [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_get_msg_num_cb) (S32 pid, srv_um_get_msg_num_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_get_list_cb) (S32 pid, srv_um_get_list_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_msg_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef srv_um_get_list_cb srv_um_get_msg_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_msg_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_get_msg_info_cb) (S32 pid, srv_um_get_msg_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_mark_several_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_mark_several_op_cb) (S32 pid, srv_um_mark_several_op_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_traverse_msg_cb
 * DESCRIPTION
 *  Callback function to return the result of "Traverse Message"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_traverse_msg_cb) (S32 pid, srv_um_traverse_msg_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_thread_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef srv_um_get_list_cb srv_um_get_thread_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_thread_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_get_thread_info_cb) (S32 pid, srv_um_get_thread_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_mark_several_thread_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Thread Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_mark_several_thread_op_cb) (S32 pid, srv_um_mark_several_thread_op_result* rsp, S32 user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_delete_folder_cb
 * DESCRIPTION
 *  Callback function to return the result of "Delete Folder"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_delete_folder_cb) (S32 pid, srv_um_delete_folder_result* rsp, S32 user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_thread_list_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Message Thread List"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  para:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef srv_um_get_list_cb srv_um_get_thread_list_cb;

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_get_thread_info_cb
 * DESCRIPTION
 *  Callback function to return the result of "Get Thread Information"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_get_thread_info_cb) (S32 pid, srv_um_get_thread_info_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_mark_several_thread_op_cb
 * DESCRIPTION
 *  Callback function to return the result of "Mark Several Thread Operation"
 * PARAMETERS
 *  pid:     [IN]   The process id
 *  rsp:     [IN]   The result
 *  user_data:    [IN]   A paramter used by UI, the value shall be identical as the request
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
typedef S32 (*srv_um_mark_several_thread_op_cb) (S32 pid, srv_um_mark_several_thread_op_result* rsp, S32 user_data);

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_list_notify_handler
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
typedef void (*srv_um_notify_list_handler) (S32 event, S32 list_cid, S32 user_data);

/*********************************
 *  Blocking Interface
 ********************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_support_type
 * DESCRIPTION
 *  Check specific msg types are supported by UM.
 * PARAMETERS
 *  msg_type:       [IN]    Message type, bit mask
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all support
 *  MMI_FALSE:  only partial support
 *****************************************************************************/
extern MMI_BOOL srv_um_check_support_type(srv_um_msg_enum msg_type);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_ready_type
 * DESCRIPTION
 *  Check specific message types are ready or not.
 * PARAMETERS
 *  msg_type:       [IN]    Message type, bit mask
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all ready
 *  MMI_FALSE:  only partial ready
 *****************************************************************************/
extern MMI_BOOL srv_um_check_ready_type(srv_um_msg_enum msg_type);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_ready
 * DESCRIPTION
 *  Check if all msg types UM supports are ready
 * PARAMETERS
 *  void
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all ready
 *  MMI_FALSE:  only partial ready
 *****************************************************************************/
extern MMI_BOOL srv_um_check_ready(void);

/***********************************************************************************
  * FUNCTION
  *   srv_um_support_msg_type
  * Description
  *   This function is for application to get the message type that supported by UMS
  * Returns
  *   message types that are supported by UM, bit mask
  ***********************************************************************************/
extern srv_um_msg_enum srv_um_support_msg_type(void);

/***************************************************************************
  * FUNCTION
  *   srv_um_ready_msg_type
  * Description
  *   This function is for application to check if all the message is ready.
  * Returns
  *   message types that are ready, bit mask
  ***************************************************************************/
extern srv_um_msg_enum srv_um_ready_msg_type(void);

/*************************************************************************************
  * FUNCTION
  *   srv_um_clear_msg_info_cache
  * Description
  *   This function is for application to clear the message cache in UMS. In some
  *   situation, application need to clean the message cache or they may get old data.
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   0 :           Success
  *   Neg. Value :  Error code
  *
  *************************************************************************************/
extern S32 srv_um_clear_msg_info_cache(void);

/**************************************************************************************
  * FUNCTION
  *   srv_um_cancel_request
  * Description
  *   This function is for application to cancel the request they submit to UMS before.
  *   This function can be used for all the asynchoronous request. ex: srv_um_get_list
  *   or srv_um_get_msg_num ....
  * Parameters
  *   pid :  [IN] The process id
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   0 :           success
  *   Neg. Value :  error code
  *
  **************************************************************************************/
extern S32 srv_um_cancel_request(S32 pid);

/*****************************************************************************
 * FUNCTION
 *   srv_um_get_request_progress
 * Description
 *   This function is to get the progress of a request
 * Parameters
 *  pid :           [IN] The process id
 *  finish_number:  [OUT] number of finished item
 *  total_number:   [OUT] number of total items
 * Returns
 *  srv_um_result_enum
 *  Please check the total_number when you get the result. It may be zero
 *  in some special situation that we cannot get the information.
 * Return Values
 *   0 :           success
 *   Neg. Value :  error code
 *
 *****************************************************************************/
extern S32 srv_um_get_request_progress(S32 pid, S32 *finish_number, S32 *total_number);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_list
 * DESCRIPTION
 *  To get the message list or thread list. (Synchronize way)
 *  There are two alias API to avoid assigning the list type.
 *  srv_um_check_msg_list
 *  srv_um_check_thread_list
 * PARAMETERS
 *  list_type:          [IN]    type of list
 *  msg_box:            [IN]    The message box information
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function to notify the list is changed.
 *  user_data:          [IN]    A callback parameter in callback function
 *  list_cntx:          [OUT]   pionter to the list context
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: list context id
 *  = 0: impossible
 *  < 0: error
 *****************************************************************************/
extern S32 srv_um_check_list(
        srv_um_list_type_enum list_type,
        srv_um_box_identity_struct msg_box,
        srv_um_list_filter_struct *filter,
        srv_um_notify_list_handler cb_func,
        S32 user_data,
        srv_um_list_cntx_struct **list_cntx);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_list
 * DESCRIPTION
 *  To get the mesage list. (Synchronize way)
 * PARAMETERS
 *  list_type:          [IN]    type of list
 *  msg_box:            [IN]    The message box information
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function to notify the list is changed.
 *  user_data:          [IN]    A callback parameter in callback function
 *  list_cntx:          [OUT]   pionter to the list context
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: list context id
 *  = 0: impossible
 *  < 0: error
 *****************************************************************************/
#define srv_um_check_msg_list(msg_box, filter, cb_func, user_data, list_cntx) \
            srv_um_check_list(SRV_UM_LIST_TYPE_MSG_NODE, msg_box, filter, cb_func, user_data, list_cntx)

/***************************************************************************************
  * \FUNCTION: srv_um_check_msg_info
  * Description
  *   Get the message detail information. UMS will check if the message listed in
  *   list_info exist in the cache. If all the data exist in the cache, it will return
  *   the message detail information directly. Otherwise, caller need to invoke
  *   srv_um_get_msg_info to trigger UMS to get the data.
  *   If all the data exist in the cache, unified message service will peek the message
  *   near the original request. And if the message near the original request do not
  *   exist in the cache, unified message service will try to get them back. This
  *   design is to decrease progressing screen for better user experience.
  *
  *   <img name="srv_um_check_msg_info-1" />
  * Parameters
  *   msg_box :         [IN] The message box information<p />
  *   msg_list :        [IN] The message list<p />
  *   list_info_size :  [IN] Size of message list<p />
  *   start_entry :     [IN] The start entry in message list to get<p />information<p />
  *   msg_number :      [IN] How much message to get<p />
  *   msg_info :        [OUT] A buffer contains message information
  * Returns
  *     srv_um_result_enum
  * Return Values
  *   0 :           Success<p />
  *   Neg. Value :  Error Code
  *
  ***************************************************************************************/
extern S32 srv_um_check_msg_info(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        srv_um_msg_info_struct msg_info[]);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_info_by_ref
 * DESCRIPTION
 *  To get the message information but the UM service return the pointers in cache
 *  directly.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of message list
 *  start_entry:        [IN]    The start entry in message list to get information
 *  msg_number:         [IN]    How much message to get
 *  msg_info:           [OUT]   A pointer array contains message information pointers
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_check_msg_info_by_ref(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        srv_um_msg_info_struct *msg_info[]);

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_num
 * DESCRIPTION
 *  currently, only can get all SIM in each box message number,
 *  please set sim_id = SRV_UM_SIM_ALL
 *  msg_type must has value, other wise no message number can be got.
 *  If need get all message type number, set msg_type = SRV_UM_MSG_ALL
 *  If return FALSE, data->error will indicate error casue using srv_um_result_enum
 *  and data->msg_type will indicate success got type message number
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_check_msg_num(
            srv_um_sim_enum sim_id,
            srv_um_msg_enum msg_type,
            srv_um_get_msg_num_result *data);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*********************************************************************
  * FUNCTION
  *   srv_um_entry_mark_several_rsp
  * Description
  *   To send response message of MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ
  * Parameters
  *   msg_box :  [IN] The message box information<p />
  *   result\ :  [IN] The result
  * Returns
  *     srv_um_result_enum
  *
  *********************************************************************/
extern S32 srv_um_entry_mark_several_rsp(srv_um_box_identity_struct msg_box, MMI_BOOL result);
#endif

/*********************************
 *  Non-Blocking Interface
 ********************************************/

/*************************************************************************************
  * FUNCTION
  *   srv_um_get_msg_num
  * Description
  *   This function get the number of message in each message box. Due to this is a
  *   non-blocking process, application needs to register a callback function. After
  *   UMS finishes this process, UMS would invoke the callback function and return the
  *   \result with srv_um_get_msg_num_result.
  * Parameters
  *   msg_type :  [IN] The message type, bit mask<p />
  *   sim_id :    [IN] The sim id, set as SRV_UM_SIM_ALL if no use.<p />
  *   cb_func :   [IN] The callback function when the response message back<p />
  *   user_data : [IN] A callback parameter in callback function<p />
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_num_cb
  *
  *   Callback Function Parameter: srv_um_get_msg_num_result
  *************************************************************************************/
extern S32 srv_um_get_msg_num(
        srv_um_msg_enum msg_type,
        srv_um_sim_enum sim_id,
        srv_um_get_msg_num_cb cb_func,
        S32 user_data);

/*************************************************************************************
  * FUNCTION
  *   srv_um_get_list
  * Description
  *   This function gets the whole list in a specific message box. Due to this
  *   is a non-blocking process, application needs to register a callback function.
  *   After UMS finishes this process, UMS would invoke the callback function and
  *   return the result
  *
  *   Note that if Caller need to release the buffer before UMS finish the request,
  *   Caller MUST cancel the request before release the buffer or UMS may corrupt the
  *   memory incident.
  * Parameters
  *   list_type:       [IN] type of list
  *   msg_box :        [IN] The message box information<p />
  *   filter :         [IN] A filter to decide which message should be excluded<p />
  *   cb_func :        [IN] The callback function when the response message back<p />
  *   user_data :      [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_list_cb
  *   Callback Function Argument: srv_um_get_msg_list_result
  *************************************************************************************/
extern S32 srv_um_get_list(
        srv_um_list_type_enum list_type,
        srv_um_box_identity_struct msg_box,
        srv_um_list_filter_struct *filter,
        srv_um_get_msg_list_cb cb_func,
        S32 user_data);

/*************************************************************************************
  * FUNCTION
  *   srv_um_get_msg_list
  * Description
  *   This function gets the whole message list in a specific message box. Due to this
  *   is a non-blocking process, application needs to register a callback function.
  *   After UMS finishes this process, UMS would invoke the callback function and
  *   return the result
  *
  *   Note that if Caller need to release the buffer before UMS finish the request,
  *   Caller MUST cancel the request before release the buffer or UMS may corrupt the
  *   memory incident.
  * Parameters
  *   list_type:       [IN] type of list
  *   msg_box :        [IN] The message box information<p />
  *   filter :         [IN] A filter to decide which message should be excluded<p />
  *   cb_func :        [IN] The callback function when the response message back<p />
  *   user_data :      [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_list_cb
  *   Callback Function Argument: srv_um_get_msg_list_result
  *************************************************************************************/
#define srv_um_get_msg_list(msg_box, filter, cb_func, user_data)    \
            srv_um_get_list(SRV_UM_LIST_TYPE_MSG_NODE, msg_box, filter, cb_func, user_data)

/*****************************************************************************
 * FUNCTION
 *  srv_um_release_list
 * DESCRIPTION
 *  To release a message list
 * PARAMETERS
 *  list_cntx:      [IN]   pionter to the list context
 *  out_of_date:    [IN]   the message list is out of data or not, if yes,
 *                         service will clean the message list or reserve it.
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  = 0: success
 *  < 0: error
 *****************************************************************************/
extern S32 srv_um_release_list(S32 list_cid, MMI_BOOL out_of_date);

/*****************************************************************************
 * FUNCTION
 *  srv_um_release_msg_list
 * DESCRIPTION
 *  To release a message list
 * PARAMETERS
 *  list_cntx:      [IN]   pionter to the list context
 *  out_of_date:    [IN]   the message list is out of data or not, if yes,
 *                         service will clean the message list or reserve it.
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  = 0: success
 *  < 0: error
 *****************************************************************************/
#define srv_um_release_msg_list(list_cid, out_of_date)  \
            srv_um_release_list(list_cid, out_of_date)

/***********************************************************************************
  * FUNCTION
  *   srv_um_get_msg_info
  * Description
  *   This function gets the message information. Due to this is a non-blocking
  *   process, application needs to register a callback function. After UMS finishes
  *   this process, UMS would invoke the callback function and return the result.
  * Parameters
  *   msg_box :     [IN] The message box information
  *   msg_list :    [IN] The message list need to get message information
  *   msg_number :  [IN] How much message to get message information
  *   cb_func :     [IN] The callback function when the response message back
  *   user_data :   [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_info_cb
  *
  *   Callback Function Argument: srv_um_get_msg_info_result
  ***********************************************************************************/
extern S32 srv_um_get_msg_info (
    srv_um_box_identity_struct msg_box,
    srv_um_msg_node_struct msg_list[],
    U16 msg_number,
    srv_um_get_msg_info_cb cb_func,
    S32 user_data);

/*************************************************************************
  * FUNCTION
  *   srv_um_delete_folder
  * Description
  *   This function is for application to delete specific message box.
  * Parameters
  *   msg_box :  [IN] The message box information
  *   cb_func :  [IN] The callback function when the response message back
  *   user_data :[IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A serial number that can control the whole process
  *   0 :           Impossible value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_delete_folder_cb
  *
  *   Callback Function Argument: srv_um_delete_folder_result
  *************************************************************************/
extern S32 srv_um_delete_folder(
    srv_um_box_identity_struct msg_box,
    srv_um_delete_folder_cb cb_func,
    S32 user_data);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/************************************************************************************
  * FUNCTION
  *   srv_um_mark_several_op
  * Description
  *   This function is for application to do some operation on multiple messages.
  * Parameters
  *   msg_box :        [IN] The message box information
  *   msg_list :       [IN] The message list to do mark several operation
  *   msg_list_size :  [IN] The size of message list
  *   mark_status :    [IN] The mark status of each message node in list. Each bit is
  *                    corresponed to one message node. The left-most bit (MSB) in
  *                    mark_status[0] is corresponded to the first message node. The
  *                    right-most bit (LSB) in mark_Status[0] is corresponed to 32th
  *                    message node.
  *   action_type :    [IN] The type of action
  *   cb_func :        [IN] The callback function when the response message back
  *   user_data :      [IN] a callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_mark_several_op_cb
  *
  *   Callback Function Argument: srv_um_mark_several_op_result
  ************************************************************************************/
extern S32 srv_um_mark_several_op(
    srv_um_box_identity_struct msg_box,
    srv_um_msg_node_struct msg_list[],
    U16 msg_list_size,
    U32 mark_status[],
    srv_um_mark_several_op_action_enum action_type,
    srv_um_mark_several_op_cb cb_func,
    S32 user_data);
#endif

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_um_check_thread_list
 * DESCRIPTION
 *  To get the thread list. (Synchronize way)
 * PARAMETERS
 *  list_type:          [IN]    type of list
 *  msg_box:            [IN]    The message box information
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function to notify the list is changed.
 *  user_data:          [IN]    A callback parameter in callback function
 *  list_cntx:          [OUT]   pionter to the list context
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: list context id
 *  = 0: impossible
 *  < 0: error
 *****************************************************************************/
#define srv_um_check_thread_list(msg_box, filter, cb_func, user_data, list_cntx) \
            srv_um_check_list(SRV_UM_LIST_TYPE_THREAD, msg_box, filter, cb_func, user_data, list_cntx)

/*************************************************************************************
  * FUNCTION
  *   srv_um_get_thread_list
  * Description
  *   This function gets the whole thread list in a specific message box. Due to this
  *   is a non-blocking process, application needs to register a callback function.
  *   After UMS finishes this process, UMS would invoke the callback function and
  *   return the result
  *
  *   Note that if Caller need to release the buffer before UMS finish the request,
  *   Caller MUST cancel the request before release the buffer or UMS may corrupt the
  *   memory incident.
  * Parameters
  *   list_type:       [IN] type of list
  *   msg_box :        [IN] The message box information<p />
  *   filter :         [IN] A filter to decide which message should be excluded<p />
  *   cb_func :        [IN] The callback function when the response message back<p />
  *   user_data :      [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_list_cb
  *   Callback Function Argument: srv_um_get_msg_list_result
  *************************************************************************************/
#define srv_um_get_thread_list(msg_box, filter, cb_func, user_data)    \
            srv_um_get_list(SRV_UM_LIST_TYPE_THREAD, msg_box, filter, cb_func, user_data)

/*****************************************************************************
 * FUNCTION
 *  srv_um_release_thread_list
 * DESCRIPTION
 *  To release a thread list
 * PARAMETERS
 *  list_cntx:      [IN]   pionter to the list context
 *  out_of_date:    [IN]   the message list is out of data or not, if yes,
 *                         service will clean the message list or reserve it.
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  = 0: success
 *  < 0: error
 *****************************************************************************/
#define srv_um_release_thread_list(list_cid, out_of_date)  \
            srv_um_release_list(list_cid, out_of_date)

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_thread_info
 * DESCRIPTION
 *  To get the thread information but the UM service return the pointers in cache
 *  directly.
 * PARAMETERS
 *  thread_list:        [IN]    The thread list
 *  list_info_size:     [IN]    Size of thread list
 *  start_entry:        [IN]    The start entry in thread list to get information
 *  thread_number:      [IN]    How many thread information to get
 *  thread_info:        [OUT]   A pointer array contains thread information pointers
 *  msg_info:           [OUT]   If you want to get the message info of the first message
 *                              in each message thread. This is the pointer array contains
 *                              message information pointers.
 *                              You also can set it as NULL to get the simple thread information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_check_thread_info(
        srv_um_box_identity_struct msg_box,
        srv_um_thread_id_struct thread_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 thread_number,
        srv_um_thread_info_struct *thread_info[],
        srv_um_msg_info_struct *msg_info[]);

/***********************************************************************************
  * FUNCTION
  *   srv_um_get_thread_info
  * Description
  *   This function gets the thread information. Due to this is a non-blocking
  *   process, application needs to register a callback function. After UMS finishes
  *   this process, UMS would invoke the callback function and return the result.
  * Parameters
  *   thread_list :   [IN] The message list need to get message information
  *   thread_number : [IN] How much message to get message information
  *   cb_func :       [IN] The callback function when the response message back
  *   user_data :     [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_info_cb
  *   Callback Function Argument: srv_um_get_msg_info_result
  ***********************************************************************************/
extern S32 srv_um_get_thread_info (
    srv_um_box_identity_struct msg_box,
    srv_um_thread_id_struct thread_list[],
    U16 thread_number,
    srv_um_get_thread_info_cb cb_func,
    S32 user_data);

/************************************************************************************
  * FUNCTION
  *   srv_um_mark_several_thread_op
  * Description
  *   This function is for application to do some operation on multiple thread.
  * Parameters
  *   thread_list :       [IN] The message list to do mark several operation
  *   thread_list_size :  [IN] The size of message list
  *   mark_status :    [IN] The mark status of each message node in list. Each bit is
  *                    corresponed to one message node. The left-most bit (MSB) in
  *                    mark_status[0] is corresponded to the first message node. The
  *                    right-most bit (LSB) in mark_Status[0] is corresponed to 32th
  *                    message node.
  *   action_type :    [IN] The type of action
  *   cb_func :        [IN] The callback function when the response message back
  *   user_data :      [IN] a callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_mark_several_op_cb
  *   Callback Function Argument: srv_um_mark_several_op_result
  ************************************************************************************/
extern S32 srv_um_mark_several_thread_op(
    srv_um_box_identity_struct msg_box,
    srv_um_thread_id_struct thread_list[],
    U16 thread_list_size,
    U32 mark_status[],
    srv_um_mark_several_op_action_enum action_type,
    srv_um_mark_several_thread_op_cb cb_func,
    S32 user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_address_to_thread_id
 * DESCRIPTION
 *  transfer address to thread id
 * PARAMETERS
 *  type:           [IN]    address type
 *  ucs2_str:       [IN]    address
 *  sim_id:         [IN]    sim id
 *  thread_id:      [OUT]   thread id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_tsfr_address_to_thread_id(srv_um_addr_enum type, U16* ucs2_str, srv_um_sim_enum sim_id, srv_um_thread_id_struct *thread_id);

/*****************************************************************************
 * FUNCTION
 *  srv_um_update_thread_id
 * DESCRIPTION
 *  update the thread_id if the number saved into phonebook
 * PARAMETERS
 *  thread_id:       [IN]   the thread_id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_update_thread_id(srv_um_thread_id_struct *thread_id);
/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msg_id_to_thread_id
 * DESCRIPTION
 *  transfer msg id to thread id, only used for messages with multiple address
 * PARAMETERS
 *  msg_type:       [IN]    message type
 *  msg_id:         [IN]    message id
 *  thread_id:      [OUT]   thread id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_tsfr_msg_id_to_thread_id(srv_um_msg_enum msg_type, U32 msg_id, srv_um_thread_id_struct *thread_id);

#if (defined(__OP01__) && (MMI_MAX_SIM_NUM >= 2))
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_prefer_sim
 * DESCRIPTION
 *
 * PARAMETERS
 *  void        
 * RETURNS
 *  srv_um_sim_enum   preferred SIM, SRV_UM_SIM_UNCLASSIFIED if no prefer sim is set
 *****************************************************************************/
extern srv_um_sim_enum srv_um_get_prefer_sim(void);
/*****************************************************************************
 * FUNCTION
 *  srv_um_get_prefer_sim
 * DESCRIPTION
 *
 * PARAMETERS
 *  srv_um_sim_enum   preferred SIM, SRV_UM_SIM_UNCLASSIFIED if no prefer sim is set
 * RETURNS
 *  MMI_TRUE if save successful
 *  MMI_FALSE if not save failed
 *****************************************************************************/
extern MMI_BOOL srv_um_set_prefer_sim(srv_um_sim_enum prefer_sim);
#endif /* (defined(__OP01__) && defined(__MMI_DUAL_SIM_MASTER__)) */

/* DOM-NOT_FOR_SDK-END */
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_um_service_init
 * DESCRIPTION
 *  To initiate the unified message service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_um_service_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_um_send_delete_all_res
 * DESCRIPTION
 *  To send delete all response message
 * PARAMETERS
 *  msg_type:   [IN]    message type
 *  result:     [IN]    result
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_um_send_delete_all_res(srv_um_msg_enum msg_type, MMI_BOOL result);

/***********************************************
 * Extra definition
 **************************************/



#include "UmSrvStruct.h"

#endif /* __UMSGPROT_H__ */

