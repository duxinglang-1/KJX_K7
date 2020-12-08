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
 * EmailSrvFolder.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file is used to declare the Email service function.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _EMAIL_SRV_FOLDER_H
#define _EMAIL_SRV_FOLDER_H

#include "EmailSrvGProt.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvStorage.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

#define SRV_EMAIL_FOLDER_HANDLE_MAX_NUMBER              (5)
#define SRV_EMAIL_FOLDER_MAX_OPERATION_PER_JOB          (25)
#define SRV_EMAIL_FOLDER_REQ_MAX_NUMBER                 (10)
#define SRV_EMAIL_FOLDER_MAX_NUMBER_PER_SORT_JOB        (10)
#define SRV_EMAIL_MAX_TIME_TO_SORT_PER_TIME             (72)

/* The enum used for indicate operation of folder object */
typedef enum
{
    SRV_EMAIL_FLDR_OPERATION_NONE,
    SRV_EMAIL_FLDR_OPERATION_LIST_MSG,
    SRV_EMAIL_FLDR_OPERATION_SET_MSG_FLAG,
    SRV_EMAIL_FLDR_OPERATION_DELETE_MSG,
    SRV_EMAIL_FLDR_OPERATION_SEND,
    SRV_EMAIL_FLDR_OPERATION_RECEIVE,
    SRV_EMAIL_FLDR_OPERATION_SYNC,
    SRV_EMAIL_FLDR_OPERATION_SORT_MSG,
    SRV_EMAIL_FLDR_OPERATION_TOTAL
} srv_email_fldr_operation_enum;

typedef struct
{
    MMI_BOOL in_use;
    EMAIL_ACCT_ID acct_id;              /* Filled by app: The account id */
    srv_email_fldr_type_enum fldr_type;
    EMAIL_FLDR_ID fldr_id;              /* Filled by app:
                                         * The base folder id
                                         * All inbox folder id (for um)
    */
    WCHAR name[SRV_EMAIL_MAX_FOLDER_NAME_LEN + 1]; /* For SRV_EMAIL_FLDR_USER_DEFINE & SRV_EMAIL_FLDR_REMOTE
                                                    * It is the full path for remote folders.
    */
    WCHAR fldr_name_separator;
    srv_eamil_msg_text_type_enum text_type;
    srv_email_msg_date_type_enum date_type;
    srv_email_fldr_msg_info_node_struct *msg_list_header;  /* Used for storing the header of msg info list */
    srv_email_fldr_msg_info_node_struct *msg_list_tail;    /* Used for storing the tail of msg info list */
    U32 msg_num;                                           /* basic info of folder */
    U32 unread_msg_num;
    U32 marked_msg_num;
    srv_email_fldr_sort_msg_mode_enum sort_mode;           /* Filled by app: The key word of sort */
    MMI_BOOL sort_order;                                   /* Filled by app: decrease or increase */
    U32 list_field;                                        /* Filled by app address type, buffer type and time type */
    srv_email_fldr_funcptr_type callback;
    void *user_data;
    srv_email_nwk_proc_funcptr_type proc_callback;
    void *proc_user_data;
    srv_email_notify_func notify_func;
    void *notify_user_data;
    EMAIL_SRV_HANDLE srv_handle;
    EMAIL_STOR_HANDLE stor_handle;
    EMAIL_NWK_HANDLE nwk_handle;
    MMI_BOOL async_operating;
    srv_email_fldr_operation_enum operation;
    srv_email_req_id_action_map_struct req_id_action_map_list[SRV_EMAIL_FOLDER_REQ_MAX_NUMBER];
} srv_email_fldr_info_struct;


/* The parameter structure of async sort emails */
typedef struct
{
    srv_email_fldr_sort_msg_mode_enum sort_mode;    /* The sort mode */
    MMI_BOOL sort_order;  /* The sort order, MMI_TRUE is ascending */
    MMI_BOOL abort;       /* used to  check if the async job aborted, MMI_TRUE is aborted */
    MMI_BOOL finished;    /* MMI_TRUE is the pre sub_sort job has finished, and it just need                               
                             header_index  and  tail_index ,or  it will need header_index,tail_index,  
                             sub_sort_header_index, sub_sort_tail_index */
    MMI_BOOL director;    /*true is from left to right,false is from right to left*/
    srv_email_fldr_msg_info_node_struct *header_node;   /* used to  remember the  the next sub sort queue header */
    srv_email_fldr_msg_info_node_struct *tail_node;     /* used to  remember the  the next sub sort queue tail */
    srv_email_fldr_msg_info_node_struct *sub_sort_header_node;  /* when finished is not true used to  remember the  pre sub sort queue header */
    srv_email_fldr_msg_info_node_struct *sub_sort_tail_node;    /* when finished is not true used to  remember the  pre sub sort queue tail */
    srv_email_fldr_msg_info_node_struct *pivot;         /* when finished is not true used to  remember the  pre sub sort pivot */
    srv_email_fldr_msg_info_node_struct **mem_ptr;                                    /*the  memory  addr*/
    U32 stack_size;
    srv_email_fldr_info_struct *folder_object;
    EMAIL_REQ_ID req_id;    /*req id for async sort*/
    EMAIL_MSG_ID msg_id;    /* The message id */
    S32 *msg_index;         /* The new index of the msg_id after sorting */
} srv_email_fldr_sort_msg_async_struct;


typedef struct
{
    MMI_BOOL canceled;
    srv_email_fldr_info_struct *folder_object;
    EMAIL_REQ_ID req_id;
    S32 start_index;
} srv_email_fldr_list_msg_job_struct;

typedef struct
{
    MMI_BOOL canceled;
    srv_email_fldr_info_struct *folder_object;
    EMAIL_REQ_ID req_id;
    srv_email_fldr_msg_info_node_struct *curr_node;
} srv_email_fldr_list_msg_job_struct_ext;

typedef struct
{
    MMI_BOOL canceled;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *curr_node;
    MMI_BOOL marked;
    U8 msg_flag;
    U8 flag_mask;
    EMAIL_REQ_ID req_id;
} srv_email_fldr_set_msg_flag_job_struct;

typedef struct
{
    MMI_BOOL canceled;
    srv_email_fldr_info_struct *folder_object;
    srv_email_fldr_msg_info_node_struct *curr_node;
    EMAIL_MSG_ID *delete_sort_list;
    U32 total_msg_delete;
    U32 curr_delete_ind;
    MMI_BOOL marked;
    MMI_BOOL delete_server;
    EMAIL_REQ_ID req_id;
} srv_email_fldr_delete_msg_job_struct;

typedef struct
{
    srv_email_fldr_info_struct *folder_object;
    EMAIL_REQ_ID req_id;
} srv_email_fldr_nwk_finish_notify_struct;


extern srv_email_result_enum srv_email_fldr_init(void);


#endif /* _EMAIL_SRV_FOLDER_H */
