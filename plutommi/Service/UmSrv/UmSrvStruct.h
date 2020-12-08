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
 * UmSrvStruct.h
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
#ifndef UM_SRV_STRUCT_H
#define UM_SRV_STRUCT_H

/* This file is used by other task, Please only use kal level type. */
/**********  KAL Layer Header **************/
#include "kal_general_types.h"
#include "app_ltlcom.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "customer_email_num.h"
#include "UMSrvDefs.h"

typedef void *(*srv_um_mem_alloc_fn) (kal_uint32);
typedef void (*srv_um_mem_free_fn) (void *);

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  This structure is used to specify the list information
 *************************************************************/
typedef struct
{
    kal_uint32 timestamp;                   /* should be given in seconds since 1.Jan. 1970 GMT. If there is no timestamp information for the message, the field should be set to zero. */
    kal_uint32 msg_id;                      /* Message id is uniquely value to represent each message in different application. */
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum sim_id;                 /* The message is corresponding to which SIM card. */
#endif
} srv_um_msg_list_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related message: MSG_ID_MMI_UM_GET_MSG_LIST_RSP.
 *************************************************************/
typedef union
{
    kal_uint32 timestamp;
    kal_bool read_status;                               /* read status of message */
    kal_uint32 msg_size;                                /* message size */
    srv_um_msg_enum msg_type;                           /* message type */
    kal_wchar subject[SRV_UM_MAX_LIST_INDEX_LEN + 1];   /* message subject */
    kal_wchar address[SRV_UM_MAX_LIST_INDEX_LEN + 1];   /* message address */
} srv_um_list_idx_data_union;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
} srv_um_generic_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
} srv_um_generic_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_READY_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_bool result;                        /* KAL_TRUE means ready; KAL_FALSE means initialization failure */
    srv_um_msg_enum msg_type;               /* Type of ready message */
} srv_um_ready_ind_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_NUM_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum sim_id;                   /* request to the corresponding sim card */
#endif
} srv_um_get_msg_num_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_NUM_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                          /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                   /* Type of message */
    kal_bool result;                            /* KAL_TRUE means OK; KAL_FALSE means failed */
    kal_uint16 inbox_unread_msg_number;         /* unread message number in inbox */
    kal_uint16 inbox_read_msg_number;           /* read message number in inbox */
    kal_uint16 unsent_msg_number;               /* message number in unsent box */
    kal_uint16 sent_msg_number;                 /* message number in sent box */
    kal_uint16 draft_msg_number;                /* message number in draft box */
    kal_uint16 predefined_template_msg_number;  /* predefined message number in template */
    kal_uint16 userdefined_template_msg_number; /* userdefined message number in template */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    kal_uint16 archive_msg_number;              /* message number in archive */
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    kal_uint16 sim_msg_number;                  /* message number in sim card */
#endif

#ifdef __MMI_UM_REPORT_BOX__
    kal_uint16 report_msg_number;               /* message number in report box */
#endif

} srv_um_get_msg_num_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_LIST_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
    srv_um_msg_box_enum msg_box_type;       /* Type of message box */
    kal_uint16 start_entry;                 /* From which entry to get list info. Start from 0 */
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum sim_id;                   /* request to the corresponding sim card */
#endif
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_um_list_idx_enum list_idx_type;
#endif
} srv_um_get_msg_list_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_LIST_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;           /* Type of message */
    kal_bool result;                    /* KAL_TRUE means OK; KAL_FALSE means failed */
    srv_um_msg_box_enum msg_box_type;   /* Type of message box */
    kal_uint16 start_entry;             /* The first entry number in this response primitive */
    kal_uint16 msg_number;              /* Number of messages in this response primitive */
    srv_um_msg_list_struct list_info[SRV_UM_MAX_GET_MSG_LIST_NUMBER];  /* List info array */
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    srv_um_list_idx_data_union list_idx_data[SRV_UM_MAX_GET_MSG_LIST_NUMBER];   /* list index data */
#endif
    kal_bool more;                      /* If there are more msgs besides this response primitive */
} srv_um_get_msg_list_rsp_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_INFO_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                           /* Type of message */
    srv_um_msg_box_enum msg_box_type;                   /* Type of message box */
    kal_uint16 msg_number;                              /* Number of messages in this request primitive */
    kal_uint32 msg_id[SRV_UM_MAX_GET_MSG_INFO_NUMBER];  /* the sequence of message id */
} srv_um_get_msg_info_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_MSG_INFO_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;                           /* Type of message */
    kal_bool result[SRV_UM_MAX_GET_MSG_INFO_NUMBER];    /* KAL_TRUE means OK; KAL_FALSE means failed */
    srv_um_msg_box_enum msg_box_type;                   /* Type of message box, bit mask, may be SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT*/
    kal_uint16 msg_number;                              /* Number of messages in this response primitive */
    kal_uint32 msg_id[SRV_UM_MAX_GET_MSG_INFO_NUMBER];  /* the sequence of message id */
    srv_um_msg_info_struct msg_info[SRV_UM_MAX_GET_MSG_INFO_NUMBER];    /* Message info array */
} srv_um_get_msg_info_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_DELETE_FOLDER_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
    srv_um_msg_box_enum msg_box_type;       /* Types of message boxes to delete; bit mask */
    srv_um_sim_enum sim_id;                 /* request to the corresponding sim card */
} srv_um_delete_folder_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_DELETE_FOLDER_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;           /* Type of message */
    kal_bool result;                    /* KAL_TRUE means all msgs are deleted successfully; Otherwise KAL_FALSE */
} srv_um_delete_folder_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_NEW_MSG_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    kal_uint32 msg_id;
    kal_uint32 timestamp;
    kal_uint8 tone_id;
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum sim_id;               /* request to the corresponding sim card */
#endif
} srv_um_new_msg_ind_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    kal_uint32 msg_id;
} srv_um_highlight_msg_ind_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    kal_uint32 msg_id;
} srv_um_highlight_decided_by_UM_struct;


/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_REFRESH_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes */
    srv_um_refresh_enum refresh_type;   /* reason to send refresh indication, 0: unknown */
    kal_uint32          msg_id;             /* which message is changed, 0: unknown */
    kal_uint32          addr_number;        /* if address_number > 1, addr_type and address can be skppied */
    srv_um_addr_enum    addr_type;          /* the address type, sender for inbox, recipient for outbox */
    kal_wchar address[SRV_UM_MAX_ADDR_LEN + 1];  /* sender address */
} srv_um_refresh_ind_struct;

/*
 * Rule 1: msg_type and msg_box_type is mandatory field
 * Rule 2: msg_id is mandatory field unless the type is SRV_UM_REFRESH_NONE.
 * Rule 3: if refresh type is SRV_UM_REFRESH_CREATE_MSG or SRV_UM_REFRESH_NEW_INCOMING_MSG,
 *         addr_number is mandatory. Sender's address for inbox. Recipient's address for unsent/sent box
 *         No address for draft box is acceptable.
 *         a. addr_number = 0,  please ignore addr_type and address.
 *         b. addr_number = 1,  please fill in addr_type and address.
 *         c. addr_number > 1,  please ignore addr_type and address.
 * Rule 4: if refresh type is SRV_UM_REFRESH_MSG_FOLDER_CHANGED,
 *         please fill in new folder type for the message.
 */

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_DELETE_ALL_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes to delete; bit mask */
} srv_um_delete_all_ind_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_DELETE_ALL_RES
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    kal_bool result;                    /* KAL_TRUE means all msgs are deleted successfully; Otherwise KAL_FALSE */
} srv_um_delete_all_res_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_CANCEL_NEW_MSG_IND
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_msg_enum msg_type;           /* Type of message */
    srv_um_msg_box_enum msg_box_type;   /* Types of message boxes only support SRV_UM_MSG_BOX_INBOX in current design. */
} srv_um_cancel_new_msg_ind_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                              /* application id. for UM, always 0 */
    srv_um_msg_enum msg_type;                       /* type of message */
    srv_um_msg_box_enum msg_box_type;               /* message folder */
    kal_uint32 msg_id;                              /* unique message id */
} srv_um_entry_mark_several_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                              /* application id. for UM, always 0 */
    srv_um_msg_enum msg_type;                       /* type of message */
    srv_um_msg_box_enum msg_box_type;               /* message folder */
    kal_bool result;                                /* entry mark several screen result */
} srv_um_entry_mark_several_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                                          /* application id. for UM, always 0 */
    srv_um_msg_enum msg_type;                                   /* type of message */
    srv_um_msg_box_enum msg_box_type;                           /* message folder */
    srv_um_mark_several_op_action_enum action_type;             /* the multi-op action type */
    kal_uint16 msg_number;                                      /* number of message should be executed */
    kal_uint32 msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];      /* an array of the executed message id */
} srv_um_mark_several_op_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                                          /* application id. for UM, always 0 */
    srv_um_msg_enum msg_type;                                   /* type of message */
    srv_um_msg_box_enum msg_box_type;                           /* message folder */
    srv_um_mark_several_op_action_enum action_type;             /* the multi-op action type */
    kal_uint16 msg_number;                                      /* number of message should be executed */
    kal_uint32 msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];      /* an array of the executed message id */
    kal_bool action_result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP]; /* an array of results corresponding to the executed msg id */
} srv_um_mark_several_op_rsp_struct;


/* This structure contains the linked list for address information. */
typedef struct srv_um_addr_struct_t
{
    struct srv_um_addr_struct_t* next;              /* Next address*/
    struct srv_um_addr_struct_t* previous;          /* Previous address*/
    kal_wchar* addr;                                /* UCS2 format. NULL terminator is needed. */
    srv_um_addr_enum type;                          /* srv_um_addr_enum */
    srv_um_addr_group_enum group;                   /* srv_um_addr_group_enum */
} srv_um_addr_struct;

/* This structure contains all the message detail informtion. */
typedef struct
{
    srv_um_msg_enum         msg_type;       /* Message type */
    kal_uint32              msg_id;         /* Message id is uniquely value to represent each message in different application. */
    kal_uint32              timestamp;      /* should be given in seconds since 1.Jan. 1970 GMT. If there is
                                                no timestamp information for the message, the timestamp field
                                                should be set to zero. If this item is corrupted, please set
                                                the timestamp to -1. */
    srv_um_msg_box_enum     msg_box_type;   /* Meessage box */
    kal_bool                read_status;    /* read status of message */
    kal_uint32              msg_status;     /* defined by each message ap itself, ex: SRV_SMS_STATUS_UNREAD */
    kal_uint32              msg_size;       /* message size */
    srv_um_addr_struct      address;        /* sender address for MT msg; receiver address for MO msg.
                                                Application should construct the address link list if there are
                                                more than one receiver. And the memory of next address should be
                                                prepared by application. UM prepares two function to help application
                                                to construct the address link list easily.
                                                srv_um_add_address and srv_um_free_address_list
                                                But please read the usage of these two function first before use it. */
    kal_wchar               *subject;       /* subject for MMS, WAP Push and E-mai; part of content for SMS, UCS2*/
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_um_sim_enum         sim_id;         /* request to the corresponding sim card */
#endif
} srv_um_msg_detail_struct;

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
#endif

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_um_traverse_msg_cb
 * DESCRIPTION
 *  Callback function to traverse message in MSG_ID_MMI_UM_TRAVERSE_MSG_REQ
 * PARAMETERS
 *  user_data:      [IN]   a user data, should be same in srv_um_traverse_msg_req_struct
 *  message:        [IN]   Application fill in the required field in message
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_BUFFER_FULL:  the buffer is full, application must stop to traverse message and send response message
 *                              UM will send next request message to application later.
 *  SRV_UM_RESULT_OK:   process data success, application can traverse next message
 *  Other:              user cancel or any unknown error, application must stop to traverse message.
 *****************************************************************************/
typedef kal_int32 (*srv_um_traverse_func) (kal_int32 user_data, srv_um_msg_detail_struct* message);

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_TRAVERSE_MSG_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                      /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;               /* Type of message */
    kal_int16 start_entry;                  /* From which entry to get list info. Start from 0.
                                               If the value is -1, then please only traverse the messages in msg_id array */
    kal_uint16 msg_number;                              /* Number of messages in the msg_id array */
    kal_uint32 msg_id[SRV_UM_MAX_TRAVERSE_MSG_NUMBER];  /* the sequence of message id */
    srv_um_msg_box_enum msg_box_type;       /* Type of message box */
    srv_um_detail_field_enum field;         /* bitwise field, indicate which field is required. */
    srv_um_traverse_func traverse_func;     /* Application use this function to traverse messages */
    kal_int32 user_data;                    /* a user_data that needed by traverse callback function */
} srv_um_traverse_msg_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_TRAVERSE_MSG_RSP
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32 app_id;                  /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    srv_um_msg_enum msg_type;           /* Type of message */
    kal_bool result;                    /* KAL_TRUE means OK; KAL_FALSE means failed */
    kal_uint16 msg_number;              /* Number of messages in this response primitive */
    kal_bool more;                      /* If there are more msgs besides this response primitive */
} srv_um_traverse_msg_rsp_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_GET_THREAD_ID_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    srv_um_addr_enum type;
    srv_um_sim_enum sim_id;
    kal_wchar *number;
    srv_um_thread_id_struct *thread_id;
} srv_um_get_thread_id_req_struct;

/*************************************************************
 *  <GROUP Local_Parameter_Structure>
 *  Related Message: MSG_ID_MMI_UM_LOOKUP_NUMBER_REQ
 *************************************************************/
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_wchar *number;
    kal_wchar *name;
    kal_uint16 len;
} srv_um_lookup_number_req_struct;

/*************************************************************
 *  Dummy Structure
 *************************************************************/
typedef srv_um_generic_rsp_struct srv_um_get_thread_list_rsp_struct;

typedef srv_um_generic_rsp_struct srv_um_get_thread_info_rsp_struct;

typedef srv_um_generic_rsp_struct srv_um_mark_several_thread_op_rsp_struct;

/*************************************************************
  * FUNCTION
  *   srv_um_add_address
  * Description
  *   Step1. Allocate memory for srv_um_addr_struct
  *   Step2. Assign the value of addr, type and group in srv_um_addr_struct
  *   Step3. Find the last address in detail and append the new addr struct on it.
  *
  *   In this function, it would not allocate another memory to save
  *   parameter "addr", therefore, please do not free the addr until invoke
  *   traverse function.
  *
  * Parameters
  *   detail    :  [IN] the destination
  *   addr      :  [IN] address
  *   type      :  [IN] type of address
  *   group     :  [IN] group of address
  *   mem_alloc_fn  : [IN] alloc memory function
  * Returns
  *   srv_um_result_enum
  *************************************************************/
extern kal_int32 srv_um_add_address(
    srv_um_msg_detail_struct* detail,
    kal_wchar* addr,
    srv_um_addr_enum type,
    srv_um_addr_group_enum group,
    srv_um_mem_alloc_fn mem_alloc_fn);

/*************************************************************
  * FUNCTION
  *   srv_um_free_address_list
  * Description
  *   Step1. Find the last address, and free the srv_um_addr_struct memory
  *   Step2. Set the next pointer as NULL
  *   Step3. Repeat Step1 and Setp2 until all extended address are freed.
  *
  *   In default, it would not use the free function to free addr in
  *   srv_um_addr_struct. Therefore, if application also need to
  *   free the addr, please set the paramter free_addr as KAL_TRUE.
  * Parameters
  *   detail              : [IN] the destination
  *   applib_mem_free_fn  : [IN] free memory function
  *   free_addr           : [IN] also free the addr in srv_um_addr_struct
  * Returns
  *   srv_um_result_enum
  *************************************************************/
extern kal_int32 srv_um_free_address_list(
    srv_um_msg_detail_struct* detail,
    srv_um_mem_free_fn mem_free_fn,
    kal_bool free_addr);

/**************************************
 *  Structure Definition Wrapper
 **********************************************/
typedef srv_um_ready_ind_struct                     mmi_um_ready_ind_struct                ;
typedef srv_um_get_msg_num_req_struct               mmi_um_get_msg_num_req_struct          ;
typedef srv_um_get_msg_num_rsp_struct               mmi_um_get_msg_num_rsp_struct          ;
typedef srv_um_get_msg_list_req_struct              mmi_um_get_msg_list_req_struct         ;
typedef srv_um_get_msg_list_rsp_struct              mmi_um_get_msg_list_rsp_struct         ;
typedef srv_um_get_msg_info_req_struct              mmi_um_get_msg_info_req_struct         ;
typedef srv_um_get_msg_info_rsp_struct              mmi_um_get_msg_info_rsp_struct         ;
typedef srv_um_delete_folder_req_struct             mmi_um_delete_folder_req_struct        ;
typedef srv_um_delete_folder_rsp_struct             mmi_um_delete_folder_rsp_struct        ;
typedef srv_um_new_msg_ind_struct                   mmi_um_new_msg_ind_struct              ;
typedef srv_um_highlight_msg_ind_struct             mmi_um_highlight_msg_ind_struct        ;
typedef srv_um_highlight_decided_by_UM_struct       mmi_um_highlight_decided_by_UM_struct  ;
typedef srv_um_refresh_ind_struct                   mmi_um_refresh_ind_struct              ;
typedef srv_um_delete_all_ind_struct                mmi_um_delete_all_ind_struct           ;
typedef srv_um_delete_all_res_struct                mmi_um_delete_all_res_struct           ;
typedef srv_um_cancel_new_msg_ind_struct            mmi_um_cancel_new_msg_ind_struct       ;
typedef srv_um_entry_mark_several_req_struct        mmi_um_entry_mark_several_req_struct   ;
typedef srv_um_entry_mark_several_rsp_struct        mmi_um_entry_mark_several_rsp_struct   ;
typedef srv_um_mark_several_op_req_struct           mmi_um_mark_several_op_req_struct      ;
typedef srv_um_mark_several_op_rsp_struct           mmi_um_mark_several_op_rsp_struct      ;
typedef srv_um_traverse_msg_req_struct              mmi_um_traverse_msg_req_struct         ;
typedef srv_um_traverse_msg_rsp_struct              mmi_um_traverse_msg_rsp_struct         ;
typedef srv_um_get_thread_id_req_struct             mmi_um_get_thread_id_req_struct        ;
typedef srv_um_lookup_number_req_struct             mmi_um_lookup_number_req_struct        ;

#endif /* UM_STRUCT_H */

