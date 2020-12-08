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
 *  EmailSrvStorFS.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __STORAGE_FS_H__
#define __STORAGE_FS_H__

#include "kal_debug.h"
#include "EmailSrvProt.h"
#include "customer_ps_inc.h"
#include "emailsrvgprot.h"
#include "EmailSrvStorage.h"
#include "MMIDataType.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "fs_type.h"

#define email_stor_malloc   srv_email_mem_alloc
#define email_stor_mfree    srv_email_mem_free 

#define email_stor_path_malloc(size)    email_stor_path_malloc_dbg(size, __FILE__, __LINE__)
#define email_stor_path_mfree(ptr)      email_stor_path_free_dbg(ptr)

/*
* Email Storage version numbers, include account verno and MSG verno, 
* used to check whether current storage version is latest.
* If not, reset storage (delete Email accounts if account verno do not match,
* delete mails if MSG verno do not match)
* Both are saved as U16, Maximum value: 65535
* If the structures of Storage are changed, please make sure these verno changed.
* e.g. you modified the subject length in MSG index file, please change MSG verno.
*/
#define EMAIL_STOR_ACCT_VERNO           (email_stor_acct_verno_compute() + 2)
#define EMAIL_STOR_MSG_VERNO            (email_stor_msg_verno_compute() + 3)


typedef EMAIL_CHECKSUM EMAIL_ACCT_VERNO;
typedef EMAIL_CHECKSUM EMAIL_MSG_VERNO;

/* reserved path buffer, global memory */
#define EMAIL_STOR_RESERVED_PATH_BUFFER (3)

#define EMAIL_STOR_SYS_PATH_LEN         (SRV_EMAIL_MAX_FILE_NAME_LEN + 1)
#define EMAIL_STOR_ASC_SYS_PATH_LEN     (EMAIL_STOR_SYS_PATH_LEN)
#define EMAIL_STOR_WCS_SYS_PATH_LEN     (sizeof(WCHAR) * EMAIL_STOR_SYS_PATH_LEN)

#define EMAIL_STOR_BASIC_FLDR_NUM       (5)     /* Max basics num supported in storage */

#define EMAIL_STOR_ACCT_BIT_NUM         (6)     /* max acct id is 63 */
#define EMAIL_STOR_ACCT_VALID_ID_MIN    (1)
#define EMAIL_STOR_ACCT_VALID_ID_MAX    (EMAIL_STOR_ACCT_NUM_MAX + EMAIL_STOR_ACCT_VALID_ID_MIN - 1)
#define EMAIL_STOR_ACCT_ID_IS_VALID(id) ((id) >= EMAIL_STOR_ACCT_VALID_ID_MIN && (id) <= EMAIL_STOR_ACCT_VALID_ID_MAX)

#define EMAIL_STOR_FLDR_BIT_NUM         (14)
#define EMAIL_STOR_FLDR_VALID_ID_MIN    (1)
#define EMAIL_STOR_FLDR_VALID_ID_MAX    (16384) /* 2^EMAIL_STOR_FLDR_BIT_NUM */
#define EMAIL_STOR_FLDR_REMOTE_ID_MIN   (EMAIL_STOR_ACCT_NUM_MAX * EMAIL_STOR_BASIC_FLDR_NUM + EMAIL_STOR_FLDR_VALID_ID_MIN)
                                                /* reserved for BASIC fldr */

#define EMAIL_STOR_OFFSET_BIT_NUM       (12)
#define EMAIL_STOR_OFFSET_MIN           (0)
#define EMAIL_STOR_OFFSET_MAX           (4095)  /* 2^EMAIL_STOR_OFFSET_BIT_NUM */

#define EMAIL_STOR_MSG_NUM_PER_ATTCH_DIR (30)   /* one MSG has 10 attch */
#define EMAIL_STOR_MSG_NUM_PER_PARTS_DIR (100)  /* one MSG has 3 parts */

#define EMAIL_STOR_MAX_MSG_NUM_PER_FLDR (SRV_EMAIL_GLOBAL_MAX_MSG_NUM)
#define EMAIL_STOR_MAX_ATTACH_NUM       (MMI_EMAIL_MAX_ATTACH_NUMBER)
#define EMAIL_STOR_MAX_MSG_CREATE_HANDLE (3)    // receiving and saving to draft

/* attachment */
#define EMAIL_STOR_ATTCH_INVALID_ID     (0)
#define EMAIL_STOR_ATTCH_VALID_ID_MIN   (1)
#define EMAIL_STOR_ATTCH_ID_STR_LEN     (sizeof(EMAIL_ATTCH_ID) * 2)    /* attach ID's length */

#define EMAIL_STOR_POS_IN_STRUCT(type, field)           ((U32)&((type*)0)->field)       /* calculate the field offset in struct */

#define EMAIL_STOR_INBOX_INDEX_POS                      (sizeof(EMAIL_CHECKSUM) + sizeof(srv_email_stor_fldr_struct))

#define EMAIL_STOR_MSG_RECORD_POS(offset)               (sizeof(EMAIL_CHECKSUM) + sizeof(srv_email_stor_fldr_struct) + \
                                                         sizeof(email_stor_fs_msg_struct) * (offset) +                   \
                                                        sizeof(email_stor_fs_inbox_index_struct) * (EMAIL_STOR_MAX_MSG_NUM_PER_FLDR))

#define EMAIL_STOR_MSG_LATEST_FLAG_POS(offset)          (EMAIL_STOR_MSG_RECORD_POS(offset) + \
                                                         EMAIL_STOR_POS_IN_STRUCT(email_stor_fs_msg_struct, flag_latest))

#define EMAIL_STOR_MSG_STATE_POS(offset)                (EMAIL_STOR_MSG_RECORD_POS(offset) + \
                                                         EMAIL_STOR_POS_IN_STRUCT(email_stor_fs_msg_struct, state))

#define EMAIL_STOR_MSG_LOCAL_SIZE_POS(offset)           (EMAIL_STOR_MSG_RECORD_POS(offset) + \
                                                         EMAIL_STOR_POS_IN_STRUCT(email_stor_fs_msg_struct, local_size))
/* INDEX/BACKUP header */
#define EMAIL_STOR_FLDR_TOTAL_NUM_POS                   (sizeof(EMAIL_CHECKSUM) + \
                                                        EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_fldr_struct, total_count))

#define EMAIL_STOR_ACCT_ID_ARR_SIZE                     (sizeof(EMAIL_ACCT_ID) * EMAIL_STOR_ACCT_NUM_MAX)
#define EMAIL_STOR_ACCT_INFO_CHECKSUM_POS               (0)
#define EMAIL_STOR_ACCT_INFO_VERNO_POS                  (EMAIL_STOR_ACCT_INFO_CHECKSUM_POS + sizeof(EMAIL_CHECKSUM))
#define EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS             (EMAIL_STOR_ACCT_INFO_VERNO_POS + sizeof(EMAIL_ACCT_VERNO))
#define EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS          (EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS + sizeof(EMAIL_ACCT_ID))
#define EMAIL_STOR_ACCT_INFO_FIRST_INFO_POS             (EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS + EMAIL_STOR_ACCT_ID_ARR_SIZE)
#define EMAIL_STOR_ACCT_INFO_POS(acct_id)               (sizeof(srv_email_acct_info_struct) * ((acct_id) - EMAIL_STOR_ACCT_VALID_ID_MIN) + \
                                                         EMAIL_STOR_ACCT_INFO_FIRST_INFO_POS)

/* SAA */
#define EMAIL_STOR_SAA_OFFSET_CONT_HEADER_OFFSET        (0 * sizeof(U32))
#define EMAIL_STOR_SAA_OFFSET_ADDR_OFFSET               (1 * sizeof(U32))
#define EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET              (2 * sizeof(U32))
#define EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET               (3 * sizeof(U32))

#define EMAIL_STOR_SAA_CONT_HEADER_POS                  (EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET + sizeof(U32))
#define EMAIL_STOR_SAA_ADDR_POS                         (EMAIL_STOR_SAA_CONT_HEADER_POS + sizeof(srv_email_stor_cont_header_struct) * 2)        /* one for text, one for html */

#define EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY 5

//typedef enum
//{
#define EMAIL_STOR_SAA_HEADER_MIN_SIZE  (sizeof(U32) * 4)
#define EMAIL_STOR_SAA_CONT_MIN_SIZE    (sizeof(srv_email_stor_cont_header_struct) * 2)
#define EMAIL_STOR_SAA_ADDR_MIN_SIZE    (sizeof(U16) * 6 + sizeof(srv_email_stor_addr_struct) * 2)
#define EMAIL_STOR_SAA_ATTCH_MIN_SIZE   (sizeof(U32))
#define EMAIL_STOR_SAA_SUBJ_MIN_SIZE    (sizeof(U32))
#define EMAIL_STOR_SAA_PART_MIN_SIZE_TOTAL (EMAIL_STOR_SAA_HEADER_MIN_SIZE + EMAIL_STOR_SAA_CONT_MIN_SIZE + EMAIL_STOR_SAA_ADDR_MIN_SIZE + EMAIL_STOR_SAA_ATTCH_MIN_SIZE + EMAIL_STOR_SAA_SUBJ_MIN_SIZE)
//}
//email_stor_fs_saa_part_min_size_enum;

typedef U32 EMAIL_STOR_OFFSET;

/* file type */
typedef enum
{
    SRV_EMAIL_STOR_FILE_INDEX = 0,
    SRV_EMAIL_STOR_FILE_BACKUP,
    SRV_EMAIL_STOR_FILE_SAA,
    SRV_EMAIL_STOR_FILE_CONT_TEXT,
    SRV_EMAIL_STOR_FILE_CONT_HTML,
    SRV_EMAIL_STOR_FILE_ATTCH,
    SRV_EMAIL_STOR_FILE_TOTAL
} srv_email_stor_file_enum;

typedef enum
{
    EMAIL_STOR_MSG_TOTAL_NUM = 0,
    EMAIL_STOR_MSG_UNREAD_NUM,
    EMAIL_STOR_MSG_NUM_TYPE_TOTAL
} email_stor_fs_msg_num_type_enum;

typedef struct _email_stor_attch_id_link_struct
{
    EMAIL_ATTCH_ID attch_id;
    struct _email_stor_attch_id_link_struct *next;
} email_stor_attch_id_link_struct;

typedef struct _email_stor_fs_msg_offset_link_struct
{
    EMAIL_STOR_OFFSET offset;
    struct _email_stor_fs_msg_offset_link_struct *next;
} email_stor_fs_msg_offset_link_struct;

typedef struct _email_stor_fs_msg_del_link_struct
{
    EMAIL_STOR_OFFSET offset;
    EMAIL_MSG_STATE new_state;
    struct _email_stor_fs_msg_del_link_struct *next;
} email_stor_fs_msg_del_link_struct;

typedef struct _email_stor_fs_msg_flag_link_struct
{
    EMAIL_STOR_OFFSET offset;
    EMAIL_MSG_FLAG new_flag;
    struct _email_stor_fs_msg_flag_link_struct *next;
} email_stor_fs_msg_flag_link_struct;

typedef struct _email_stor_fs_msg_sync_link_struct
{
    EMAIL_STOR_OFFSET offset;
    MMI_BOOL del_server_flag;
    struct _email_stor_fs_msg_sync_link_struct *next;
} email_stor_fs_msg_sync_link_struct;

typedef struct
{
    MMI_BOOL abort;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID *fldr_id_arr;
    U32 fldr_id_num;
    U32 fldr_id_curr_index; /* start from 0 */
    EMAIL_STOR_OFFSET msg_offset;
    U16 msg_index;
    U16 del_unread_cnt;
    U16 del_total_cnt;
    srv_email_stor_fldr_del_funcptr_type fldr_del_callback;
    email_stor_fs_msg_offset_link_struct *offset_header;
    void *user_data;
} email_stor_fldr_del_struct;

typedef enum
{
    EMAIL_STOR_ACCT_ID_UNUSED = 0,
    EMAIL_STOR_ACCT_ID_USED = 1,
    EMAIL_STOR_ACCT_ID_LOCK = 2,
    EMAIL_STOR_ACCT_ID_STATE_TYPE_TOTAL
} email_stor_acct_id_used_type_enum;

typedef struct
{
    U16 offset;
    EMAIL_MSG_FLAG flag;
    U32 date;
} email_stor_fs_inbox_index_struct;

typedef struct
{
    email_stor_acct_id_used_type_enum acct_id_used;
    U16 next_search_offset;                             // only for INBOX
    srv_email_acct_info_cache_struct acct_info_cache;
} email_stor_acct_cache_struct;


typedef struct
{
    MMI_BOOL used_now;
    WCHAR buffer[EMAIL_STOR_SYS_PATH_LEN];
    const CHAR* filename;
    U32 line;
} email_stor_mem_path_buffer_struct;

typedef struct
{
    U32 attch_index_next_avlid;                 /* attachment index, auto increment */
    EMAIL_FLDR_ID remote_fldr_id_next_avlid;    /* folder id, auto increment */

    srv_email_all_msg_unread_notify_funcptr msg_unread_notify_callback[EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY];
    void* msg_unread_notify_userdata[EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY];
    email_stor_acct_cache_struct acct[EMAIL_STOR_ACCT_NUM_MAX];
    EMAIL_ACCT_ID acct_id_sort[EMAIL_STOR_ACCT_NUM_MAX];
    MMI_BOOL need_pre_installed_acct;

    srv_email_stor_state_enum stor_state;   /* storage state */

    S32 _errno;
    
    email_stor_fs_inbox_index_struct inbox_index[EMAIL_STOR_MAX_MSG_NUM_PER_FLDR];
    U32 inbox_index_size;

    void *msg_create_cntx[EMAIL_STOR_MAX_MSG_CREATE_HANDLE];
    void *msg_update_cntx;

    email_stor_mem_path_buffer_struct path_buffer[EMAIL_STOR_RESERVED_PATH_BUFFER]; /* used by email_stor_path_malloc */

    srv_email_recent_list_query_funcptr_type recent_list_query_callback;
    srv_email_recent_list_answer_funcptr_type recent_list_answer_callback;

    MMI_BOOL is_storage_reset;

    /* for recent events, if the FLDR's damaged, should update the Recent Events when INIT APP */
    EMAIL_ACCT_ID acct_reset;
    EMAIL_FLDR_ID fldr_reset;
} email_stor_cntx_struct;

typedef struct
{
    MMI_BOOL valid;             /* once valid is MMI_FALSE, means this offset is unused */
    EMAIL_MSG_FLAG flag_latest;
    EMAIL_MSG_FLAG flag_orig;   /* {flag_org} must follow {flag_latest} */
    EMAIL_MSG_PRIO priority;
    EMAIL_MSG_STATE state;
    U32 uid_validity;
    EMAIL_UID uid;
    U8 uidl[SRV_EMAIL_MD5_DIGEST_LEN];
    U8 acct_digest[SRV_EMAIL_MD5_DIGEST_LEN];
    U32 created_date;
    U32 received_date;
    CHAR addr_disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1];
    CHAR addr_email[EMAIL_MAX_ENCODED_ADDR_LEN + 1];
    U32 local_size;
    U32 server_size;
    U16 attch_num;
    WCHAR list_subj[EMAIL_MAX_LIST_SUBJ_LEN + 1];
} email_stor_fs_msg_struct;

typedef enum
{
    EMAIL_STOR_DEL_ACCT = 0,
    EMAIL_STOR_DEL_FLDR,
    EMAIL_STOR_DEL_TOTAL
} email_stor_del_type;

typedef enum
{
    EMAIL_STOR_FLDR_INDEX = 0,
    EMAIL_STOR_FLDR_BACKUP,
    EMAIL_STOR_FLDR_TOTAL
} email_stor_fldr_file_type;

typedef struct
{
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    MMI_BOOL del_header;
    MMI_BOOL del_server_later;  /* it's just a Flag to mark this MSG need to delete from server after SYNC with server. */
    S32 unread_num_chg;
    S32 total_num_chg;
    U32 pos_end;
    email_stor_fs_msg_del_link_struct *offset_header;
} email_stor_fs_fldr_del_msg_struct;

typedef struct
{
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    U8 mask;
    EMAIL_MSG_FLAG flag;
    MMI_BOOL index_backup_file_updated; /* if TRUE, need calculate checksum */
    email_stor_fs_msg_flag_link_struct *offset_header;
    S32 unread_num_chg;
    U32 pos_end;
} email_stor_fs_fldr_set_msg_flag_struct;

typedef struct
{
    FS_FIND_HANDLE find_hd;
    MMI_BOOL first;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID first_fldr_id;
    srv_email_fldr_type_enum type;
    WCHAR filename[EMAIL_STOR_WCS_SYS_PATH_LEN];
} email_stor_fs_acct_get_fldr_handle_struct;

typedef struct
{
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_STOR_OFFSET current_offset;
    srv_eamil_msg_text_type_enum text_type;
    srv_email_msg_date_type_enum date_type;
    S32 base_index;
    email_stor_fs_msg_struct temp_msg;
    U32 pos_end;
} email_stor_fs_fldr_get_list_msg_struct;

typedef struct
{
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_STOR_OFFSET current_offset;
    email_stor_fs_msg_sync_link_struct *del_offset_list_header;
    email_stor_fs_msg_flag_link_struct *set_flag_list_header;
    S32 msg_total_num_chg;
    S32 msg_unread_num_chg;
    U32 new_unread_num;
    U32 new_total_num;
    U32 pos_end;
} email_stor_fs_fldr_sync_struct;

typedef struct
{
    U64 attch_id;
    WCHAR attch_original_path[EMAIL_STOR_ASC_SYS_PATH_LEN];
} email_stor_fs_original_attch_struct;

typedef enum
{
    EMAIL_STOR_MSG_EDIT_INIT = 0,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID          = 1,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_DONE     = 2,
    EMAIL_STOR_MSG_EDIT_COPY_ATTACH         = 3,
    EMAIL_STOR_MSG_EDIT_COPY_ATTACH_DONE    = 4,
    EMAIL_STOR_MSG_EDIT_SAA_INIT            = 5,
    EMAIL_STOR_MSG_EDIT_SAA_INIT_DONE       = 6,
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT          = 7,
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT_DONE     = 8,
    EMAIL_STOR_MSG_EDIT_WRITE_HTML          = 9,
    EMAIL_STOR_MSG_EDIT_WRITE_HTML_DONE     = 10,
    EMAIL_STOR_MSG_EDIT_WRITE_ADDR          = 11,
    EMAIL_STOR_MSG_EDIT_WRITE_ADDR_DONE     = 12,
    EMAIL_STOR_MSG_EDIT_WRITE_ATTACH        = 13,
    EMAIL_STOR_MSG_EDIT_WRITE_ATTACH_DONE   = 14,
    EMAIL_STOR_MSG_EDIT_WRITE_SUBJ          = 15,
    EMAIL_STOR_MSG_EDIT_WRITE_SUBJ_DONE     = 16,
    EMAIL_STOR_MSG_EDIT_WRITE_INDEX         = 17,
    EMAIL_STOR_MSG_EDIT_WRITE_INDEX_DONE    = 18,
    EMAIL_STOR_MSG_EIDT_NOTIFY_CHANGE       = 19,
    EMAIL_STOR_MSG_EIDT_NOTIFY_CHANGE_DONE  = 20,
    EMAIL_STOR_MSG_EDIT_WRITE_DONE          = 21,
} email_stor_msg_edit_state_enum;

typedef enum
{
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_INIT = 0,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_FIND,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_PARTS_DIR,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_ATTCH_DIR,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_PARTS_BRANCH_IDR,
    EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_ATTCH_BRANCH_IDR,
} email_stor_msg_edit_get_msg_id_state_enum;

typedef enum
{
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT_INIT = 0,
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_GET_SIZE,
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_ASYNC,
    EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_HEADER,
} email_stor_msg_edit_write_text_state_enum;

typedef enum
{
    EMAIL_STOR_MSG_EDIT_WRITE_INDEX_INIT = 0,
    EMAIL_STOR_MSG_EDIT_WRITE_INDEX_BAK,
} email_stor_msg_edit_write_index_state_enum;

typedef enum
{
    EMAIL_CREATE = 0,
    EMAIL_UPDATE,
} email_stor_msg_edit_type;

typedef struct
{
    WCHAR *from_path;
    FS_HANDLE hd;
    S32 keep_file_src;
    srv_email_stor_cont_header_struct cont_header;
} email_stor_fs_msg_edit_text_write_struct;

typedef struct
{
    srv_email_result_enum result;
    email_stor_msg_edit_type edit_type;

    srv_email_stor_msg_query_text_funcptr_type query_text_callback;
    srv_email_stor_msg_query_addr_funcptr_type query_addr_callback;
    srv_email_stor_msg_query_attch_funcptr_type query_attch_callback;
    srv_email_stor_msg_create_funcptr_type callback;
    void *user_data;

    email_stor_msg_edit_state_enum edit_state;
    email_stor_msg_edit_get_msg_id_state_enum get_msg_id_state;
    email_stor_msg_edit_write_text_state_enum write_text_state;
    email_stor_msg_edit_write_index_state_enum write_index_state;
    
    FS_HANDLE get_msg_id_hd;
    FS_HANDLE saa_hd;

    EMAIL_CHECKSUM index_checksum;

    email_stor_fs_msg_edit_text_write_struct *text_write_cnxt;
    email_stor_attch_id_link_struct *attch_new_header;
    email_stor_attch_id_link_struct *attch_del_header;
    U16 attch_index_to_deal;

    // async fs write
    CHAR *fs_buf;
    U32   fs_buf_size;
    S32   fs_job_id;
    U32   fs_rw;
    fs_overlapped_struct fs_overlapped;

    email_stor_fs_msg_struct header;
    email_stor_fs_original_attch_struct attch_path[EMAIL_STOR_MAX_ATTACH_NUM];

    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    EMAIL_STOR_OFFSET offset;
    U16 remain_attach_num;
    U16 addr_to_num;
    U16 remain_addr_to_num;
    U16 addr_cc_num;
    U16 remain_addr_cc_num;
    U16 addr_bcc_num;
    U16 remain_addr_bcc_num;
    U32 subj_len;
    U32 text_len;
    U32 html_len;
    srv_email_stor_msg_type_enum msg_type;
    U32 new_unread_num;
    U32 new_total_num;
    S32 msg_unread_num_chg;
} email_stor_fs_msg_edit_struct;

typedef struct
{
    FS_HANDLE hd;
    U16 total_num;
    U32 base_index;
    U32 current_index;
    U32 start_offset;
    srv_email_addr_type_enum addr_type;
} email_stor_fs_msg_get_addr_handle_struct;

typedef struct
{
    WCHAR *new_dir;
    MMI_BOOL del_orig;
    MMI_BOOL copy_orig;
    MMI_BOOL del_orig_done;
    MMI_BOOL set_dir_done;
    MMI_BOOL copy_orig_done;
    srv_email_stor_sys_dir_chg_funcptr_type callback;
    void *user_data;
} srv_email_stor_sys_dir_chg_struct;

typedef struct
{
    EMAIL_CHECKSUM checksum;
    EMAIL_MSG_VERNO msg_verno;
    U32 attch_index_next_avlid;
    EMAIL_FLDR_ID remote_fldr_id_next_avlid;
} email_stor_fs_cntx_file_struct;   /* only for Storage CNTX file read/write */

typedef enum
{
    EMAIL_STOR_RESTORE_DONE = 0,
    EMAIL_STOR_RESTORE_DOING = 1
} email_stor_backup_restore_flag_enum;

typedef struct
{
    FS_HANDLE hd;
    U32 total_num;
    U32 base_index;
    U32 current_index;
    U32 start_offset;
} email_stor_fs_msg_get_attch_handle_struct;

typedef struct
{
    EMAIL_REQ_ID req_id;
    WCHAR path[EMAIL_STOR_WCS_SYS_PATH_LEN];
    srv_email_result_enum res;
    EMAIL_ACCT_ID curr_acct_id;
    EMAIL_ACCT_ID acct_to_xdel[MMI_EMAIL_MAX_ACCTS];
    srv_email_stor_res_funcptr_type callback;
    void *user_data;
} email_stor_fs_acct_dir_sync_struct;

typedef struct
{
    EMAIL_ACCT_ID acct_id;
    EMAIL_FLDR_ID fldr_id;
    email_stor_backup_restore_flag_enum type;
} email_stor_backup_restore_flag_struct;

/* only for storage initialization */
typedef struct
{
    MMI_BOOL check_root_dir;
    MMI_BOOL check_acct_info;
    MMI_BOOL check_other_dir;
    MMI_BOOL sync_acct;
    MMI_BOOL check_cntx_file;
    srv_email_stor_res_funcptr_type callback;
    void *user_data;
} email_stor_fs_init_struct;

typedef enum
{
    EMAIL_STOR_FS_ACCT_INFO_ORIG = 0,
    EMAIL_STOR_FS_ACCT_INFO_BAK = 1
} email_stor_fs_acct_info_enum;

S32 email_stor_fs_seek(FS_HANDLE hd, S32 offset, S32 whence, CHAR file, U32 line);
FS_HANDLE email_stor_fs_open(const WCHAR* file, S32 flag, CHAR file_flag, U32 line);
void email_stor_fs_close(FS_HANDLE hd);

#define EMAIL_FS_SEEK(hd, offset, whence)   email_stor_fs_seek(hd, offset, whence, EMAIL_STOR_FILE, __LINE__)
#define EMAIL_FS_OPEN(file, flag)           email_stor_fs_open(file, flag, EMAIL_STOR_FILE, __LINE__)
#define EMAIL_FS_CLOSE(hd)                  email_stor_fs_close(hd); hd = EMAIL_STOR_INVALID_FS_HANDLE

extern email_stor_cntx_struct *email_stor_p;

const extern CHAR *EMAIL_STOR_SYS_DIR;

const extern CHAR *EMAIL_STOR_MSG_CNTX;

const extern CHAR *EMAIL_ACCT_INFO_FILE_ORIG;
const extern CHAR *EMAIL_ACCT_INFO_FILE_BAK;

const extern CHAR *EMAIL_INDEX_FILE_FLDR;
const extern CHAR *EMAIL_FLDR_SUFFIX_INDEX;
const extern CHAR *EMAIL_FLDR_SUFFIX_BACKUP;

const extern CHAR *EMAIL_PARTS_FLDR;
const extern CHAR *EMAIL_PARTS_SUFFIX_SAA;
const extern CHAR *EMAIL_PARTS_SUFFIX_TXT;
const extern CHAR *EMAIL_PARTS_SUFFIX_HTML;

const extern CHAR *EMAIL_ATTCH_FLDR;
const extern CHAR *EMAIL_ATTCH_SUFFIX_ATTCH;

const extern CHAR *EMAIL_STOR_RESTOR_FILE;

const extern WCHAR *EMAIL_STOR_TMP_SUFFIX;

const extern WCHAR *EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX;

srv_email_result_enum email_stor_fs_cntx_file_reset(const WCHAR *path);
srv_email_result_enum email_stor_fs_cntx_info_write(U32 attch_id_next_avlid, EMAIL_FLDR_ID remote_fldr_id_next_avlid);

void email_stor_fs_acct_id_mem_global_set(EMAIL_ACCT_ID acct_id, email_stor_acct_id_used_type_enum type);
email_stor_acct_id_used_type_enum email_stor_fs_acct_id_mem_global_get(EMAIL_ACCT_ID acct_id);

void email_stor_fs_acct_cache_notify_msg_unread_chg(
    srv_email_all_msg_unread_notify_type type, U32 new_unread_num);

MMI_BOOL email_stor_fs_acct_id_valid(EMAIL_ACCT_ID acct_id);

U32 email_stor_fs_acct_id_get(EMAIL_ACCT_ID *acct_id);
srv_email_result_enum email_stor_fs_acct_default_id_get(EMAIL_ACCT_ID *default_acct_id);
srv_email_result_enum email_stor_fs_acct_default_id_set(EMAIL_ACCT_ID acct_id);
srv_email_result_enum email_stor_fs_acct_default_id_del(void);
void email_stor_fs_acct_info_gen_path(WCHAR *path, email_stor_fs_acct_info_enum type);
srv_email_result_enum email_stor_fs_acct_info_file_create(const WCHAR *orig_path, const WCHAR *bak_path);
srv_email_result_enum email_stor_fs_acct_info_read(srv_email_acct_info_struct *acct_info);
srv_email_result_enum email_stor_fs_acct_info_write(const srv_email_acct_info_struct *acct_info);
srv_email_result_enum email_stor_fs_acct_info_write_async(const srv_email_acct_info_struct *acct_info,
                         srv_email_stor_acct_write_funcptr_type callback, void* user_data);
void email_stor_fs_acct_info_write_async_abort(void);

extern srv_email_result_enum email_stor_acct_set_cloud_acct(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL is_cloud_acct);

void email_stor_fs_acct_info_cache_get(EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache);
void email_stor_fs_acct_info_cache_set(
        EMAIL_ACCT_ID acct_id,
        MMI_BOOL is_cloud_acct,
        srv_email_prot_type_enum protocol,
        const WCHAR *acct_name,
        const WCHAR *acct_addr);

void email_stor_fs_msg_next_valid_offset_set(EMAIL_ACCT_ID acct_id, EMAIL_STOR_OFFSET offset);
EMAIL_STOR_OFFSET email_stor_fs_msg_next_valid_offset_get(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id);

void email_stor_fs_acct_cache_notify_set(srv_email_all_msg_unread_notify_funcptr callback, void*userdata);
void email_stor_fs_acct_cache_update_msg_unread_chg(EMAIL_ACCT_ID acct_id, S32 unread_num_chg);
void email_stor_fs_acct_cache_update_msg_unread_reset(EMAIL_ACCT_ID acct_id);

U32 email_stor_fs_acct_info_cache_cnt_msg_unread(void);
void email_stor_fs_acct_unread_set_directly(EMAIL_ACCT_ID acct_id, U32 unread_num);

void email_stor_fs_acct_gen_path(EMAIL_ACCT_ID acct_id, WCHAR *path);  /* from acct_id to Account Dir Path */

srv_email_result_enum email_stor_fs_acct_create_request(EMAIL_ACCT_ID *acct_id);
srv_email_result_enum email_stor_fs_acct_create_cancel(EMAIL_ACCT_ID acct_id);

srv_email_result_enum email_stor_fs_acct_pre_install_open(EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_acct_pre_install_create(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_acct_info_struct *acct_info);
srv_email_result_enum email_stor_fs_acct_pre_install_close(EMAIL_STOR_HANDLE handle);

srv_email_result_enum email_stor_fs_acct_del(EMAIL_ACCT_ID acct_id);

srv_email_result_enum email_stor_fs_acct_get_fldr_id_open(
                        EMAIL_ACCT_ID acct_id,
                        srv_email_fldr_type_enum type,
                        EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_acct_get_fldr_id_next(EMAIL_STOR_HANDLE handle, EMAIL_FLDR_ID *fldr_id);
srv_email_result_enum email_stor_fs_acct_get_fldr_id_close(EMAIL_STOR_HANDLE handle);

MMI_BOOL email_stor_fs_fldr_type_is_inbox(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id);
MMI_BOOL email_stor_fs_fldr_type_is_basic(srv_email_fldr_type_enum fldr_type);

void email_stor_fs_fldr_parts_root_gen_path(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, WCHAR *path);
void email_stor_fs_fldr_attch_root_gen_path(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, WCHAR *path);

void email_stor_fs_fldr_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        email_stor_fldr_file_type type,
        WCHAR *path);
srv_email_result_enum email_stor_fs_fldr_gen_remote_id(EMAIL_FLDR_ID *fldr_id);
EMAIL_FLDR_ID email_stor_fs_fldr_gen_basic_id(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type);
srv_email_fldr_type_enum email_stor_fs_fldr_id_to_fldr_type(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id);

srv_email_result_enum email_stor_fs_fldr_create_simple(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_fldr_type_enum fldr_type);

srv_email_result_enum email_stor_fs_fldr_create(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        const srv_email_stor_fldr_create_info_struct *fldr_info);

srv_email_result_enum email_stor_fs_fldr_get_info(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_stor_fldr_struct *fldr_info);

srv_email_result_enum email_stor_fs_fldr_sync_msg_open(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle,
                        EMAIL_MSG_ID last_msg_id);

srv_email_result_enum email_stor_fs_fldr_sync_msg_get_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info);
srv_email_result_enum email_stor_fs_fldr_sync_msg_set_flag(
                        EMAIL_STOR_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG new_flag);
srv_email_result_enum email_stor_fs_fldr_sync_msg_del(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id);
srv_email_result_enum email_stor_fs_fldr_sync_msg_close(EMAIL_STOR_HANDLE *handle);

srv_email_result_enum email_stor_fs_fldr_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id_arr,
                        U32 fldr_id_num);
srv_email_result_enum email_stor_fs_fldr_del_dir_files(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, MMI_BOOL care_error);


srv_email_result_enum email_stor_fs_fldr_list_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_eamil_msg_text_type_enum text_type,
                        srv_email_msg_date_type_enum date_type,
                        S32 base_index,
                        EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_fldr_list_msg_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_msg_list_header_struct *header);
srv_email_result_enum email_stor_fs_fldr_list_msg_close(EMAIL_STOR_HANDLE handle);

srv_email_result_enum email_stor_fs_fldr_del_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        MMI_BOOL del_header,
                        MMI_BOOL del_server_later,
                        EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_fldr_del_msg_next(EMAIL_STOR_HANDLE handle, EMAIL_STOR_OFFSET offset);
srv_email_result_enum email_stor_fs_fldr_del_msg_close(EMAIL_STOR_HANDLE handle);

srv_email_result_enum email_stor_fs_fldr_set_msg_flag_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        U8 mask,
                        EMAIL_MSG_FLAG flag,
                        EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_fldr_set_msg_flag_next(EMAIL_STOR_HANDLE handle, EMAIL_STOR_OFFSET offset);
srv_email_result_enum email_stor_fs_fldr_set_msg_flag_close(EMAIL_STOR_HANDLE handle);

srv_email_result_enum email_stor_fs_msg_id_valid_ext(EMAIL_MSG_ID msg_id, MMI_BOOL chk_attch, MMI_BOOL *is_valid);

void email_stor_fs_msg_parts_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        srv_email_stor_file_enum type,
        WCHAR *path);
srv_email_result_enum email_stor_fs_msg_parts_read(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        srv_eamil_msg_text_type_enum text_type,
                        U32 text_buff_len,
                        CHAR *buffer);

srv_email_result_enum email_stor_fs_msg_parts_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        srv_email_stor_file_enum type);

srv_email_result_enum email_stor_fs_msg_get_attch_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        email_stor_attch_id_link_struct **header);
srv_email_result_enum email_stor_fs_msg_del_remove_record(
                        FS_HANDLE hd,
                        email_stor_fs_msg_offset_link_struct *header);

srv_email_result_enum email_stor_fs_msg_edit(
                        srv_email_stor_msg_create_header_struct *header,
                        srv_email_stor_msg_query_text_funcptr_type query_text_callback,
                        srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
                        srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
                        srv_email_stor_msg_create_funcptr_type callback,
                        void *userdata,
                        EMAIL_STOR_HANDLE *msg_edit_handle,
                        email_stor_msg_edit_type type);
srv_email_result_enum email_stor_fs_msg_edit_abort(EMAIL_STOR_HANDLE msg_edit_handle);

srv_email_result_enum email_stor_fs_msg_num_update(
                        FS_HANDLE hd,
                        U32 *orig_num,
                        S32 add,
                        email_stor_fs_msg_num_type_enum type);

srv_email_result_enum email_stor_fs_msg_move(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id);

srv_email_result_enum email_stor_fs_msg_set_flag(EMAIL_MSG_ID msg_id, U8 mask, EMAIL_MSG_FLAG flag);

srv_email_result_enum email_stor_fs_msg_get_flag_state(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG *flag,
                        EMAIL_MSG_STATE *state);

srv_email_result_enum email_stor_fs_msg_get_header(EMAIL_MSG_ID msg_id, srv_email_stor_msg_get_header_struct *header);

srv_email_result_enum email_stor_fs_msg_get_subj_len(EMAIL_MSG_ID msg_id, U32 *subj_len);
srv_email_result_enum email_stor_fs_msg_get_subj(EMAIL_MSG_ID msg_id, CHAR *subj, U32 *buffer_size);

srv_email_result_enum email_stor_fs_msg_load_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        const WCHAR *cont_path,
                        MMI_BOOL keep_src);
srv_email_result_enum email_stor_fs_msg_get_cont_len(EMAIL_MSG_ID msg_id, srv_email_stor_msg_cont_type type, U32 *cont_len);
srv_email_result_enum email_stor_fs_msg_get_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        srv_email_stor_cont_header_struct *cont_header,
                        WCHAR *buff,
                        U32 *size);
srv_email_result_enum email_stor_fs_msg_cont_exist(EMAIL_MSG_ID msg_id, S8 *text_exist_mask, S8 *html_exist_mask);
srv_email_result_enum email_stor_fs_msg_cont_size(EMAIL_MSG_ID msg_id, U32 *text_size, U32 *html_size);


srv_email_result_enum email_stor_fs_msg_get_addr_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        srv_email_addr_type_enum addr_type,
                        EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_msg_get_addr_next(
                        EMAIL_STOR_HANDLE handle,
                        U32 disp_name_buff_len,
                        U32 addr_buff_len,
                        CHAR *disp_name,
                        CHAR *addr);
srv_email_result_enum email_stor_fs_msg_get_addr_close(EMAIL_STOR_HANDLE handle);

srv_email_result_enum email_stor_fs_msg_get_attch_open(EMAIL_MSG_ID msg_id, U32 base_index, EMAIL_STOR_HANDLE *handle);
srv_email_result_enum email_stor_fs_msg_get_attch_next(EMAIL_STOR_HANDLE handle, srv_email_stor_attch_struct *attch);
srv_email_result_enum email_stor_fs_msg_get_attch_close(EMAIL_STOR_HANDLE handle);
srv_email_result_enum email_stor_fs_msg_get_attch_path(EMAIL_ATTCH_ID attch_id, WCHAR *attch_path, U32 buff_size);
srv_email_result_enum email_stor_fs_msg_load_attch(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_ATTCH_ID attch_id,
                        const WCHAR *attch_path,
                        MMI_BOOL keep_src,
                        MMI_BOOL drm,
                        const CHAR *drm_content_type,
                        const CHAR *new_filename,
                        const CHAR *new_charset);

void email_stor_fs_msg_offset_link_free(email_stor_fs_msg_offset_link_struct *header);
void email_stor_fs_msg_offset_link_add(email_stor_fs_msg_offset_link_struct **header, EMAIL_STOR_OFFSET offset);

EMAIL_MSG_ID email_stor_fs_msg_id_gen(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, EMAIL_STOR_OFFSET offset);
EMAIL_ACCT_ID email_stor_fs_msg_id_to_acct_id(EMAIL_MSG_ID msg_id);
EMAIL_FLDR_ID email_stor_fs_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id);
EMAIL_STOR_OFFSET email_stor_fs_msg_id_to_offset(EMAIL_MSG_ID msg_id);
EMAIL_MSG_ID email_stor_fs_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id);

S32 email_stor_fs_flag_mem_set(EMAIL_MSG_FLAG *flag, U8 mask, EMAIL_MSG_FLAG new_flag);

S32 email_stor_fs_errno_detail_get(srv_email_result_enum res);
void email_stor_fs_errno_detail_set(S32 hd);

void email_stor_fs_inbox_index_read(FS_HANDLE hd);
srv_email_result_enum email_stor_fs_inbox_index_write(FS_HANDLE hd);
void email_stor_fs_inbox_index_memset(void);
void email_stor_fs_inbox_index_add(email_stor_fs_inbox_index_struct *note);
srv_email_result_enum email_stor_fs_inbox_index_del(U16 offset);
void email_stor_fs_inbox_index_update(U16 offset, EMAIL_MSG_FLAG flag);
void email_stor_fs_inbox_index_update_by_list(email_stor_fs_msg_flag_link_struct *set_flag_list_header);
void email_stor_fs_inbox_index_del_by_list(email_stor_fs_msg_offset_link_struct *del_offset_list_header);
srv_email_result_enum email_stor_fs_inbox_get_recent_list(
                        EMAIL_ACCT_ID acct_id,
                        S32 start_index,
                        U32 *count,
                        U8 flag_mask,
                        EMAIL_MSG_FLAG matched_flag,
                        srv_email_inbox_index_msg_struct *msg_array);

void email_stor_fs_attch_id_link_free(email_stor_attch_id_link_struct *header);

srv_email_result_enum email_stor_fs_attch_del(email_stor_attch_id_link_struct *header);

S32 email_stor_fs_util_ucs2_cmp_asc(const WCHAR *wstr, const CHAR *str, S32 len);
MMI_BOOL email_stor_fs_util_wcs_to_u32(const WCHAR *w, U32 *u, U8 mode);
MMI_BOOL email_stor_fs_util_wcs_to_u64(const WCHAR *w, U64 *u, U8 mode);

srv_email_result_enum email_stor_fs_init(srv_email_stor_res_funcptr_type callback, void *user_data);

srv_email_stor_state_enum email_stor_fs_state_get(void);

MMI_BOOL email_stor_fs_state_available(void);

void email_stor_fs_fldr_parts_branch_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        WCHAR *path);

void email_stor_fs_fldr_attch_branch_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        WCHAR *path);

void *email_stor_path_malloc_dbg(U32 size, const CHAR *filename, U32 line);
void email_stor_path_free_dbg(void *ptr);

MMI_BOOL email_stor_fs_recent_envent_unread_query(U32 count, EMAIL_MSG_ID *msg_id, S8 *unread);
srv_email_result_enum email_stor_fs_recent_envent_info_query(srv_email_msg_prio_read_struct *msg, U32 count);

srv_email_result_enum email_stor_fs_get_all_msg_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        U8 flag_mask, 
                        EMAIL_MSG_FLAG matched_flag,
                        U32 *count,
                        EMAIL_MSG_ID *msg_id);

#ifdef __MTK_TARGET__
#define EMAIL_STOR_TRACE_FS_SEEK(f,l,r)     MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_SEEK, EMAIL_STOR_FILE, l, r)
#define EMAIL_STOR_TRACE_FS_COPY(r)         MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_COPY, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_RENAME(r)       MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_RENAME, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_DEL(r)          MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_DEL, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_OPEN(r)         MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_OPEN, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_ACS_DND(f,l,w)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_OPEN_ACS_DND, f, l)
#define EMAIL_STOR_TRACE_FS_READ(r,s)       MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_READ, EMAIL_STOR_FILE, __LINE__, r, s);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_WRITE(r,s)      MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_WRITE,EMAIL_STOR_FILE,  __LINE__, r, s);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_CREATE_DIR(r)   MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FS_CREATE_DIR, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_MALLOC(s)          MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MALLOC, EMAIL_STOR_FILE, __LINE__, s)
#define EMAIL_STOR_TRACE_INIT(r)            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT, EMAIL_STOR_FILE, __LINE__, r)
#define EMAIL_STOR_TRACE_INIT_START()       MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_START, EMAIL_STOR_FILE, __LINE__)
#define EMAIL_STOR_TRACE_INIT_ACCT(a)       MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_ACCT, EMAIL_STOR_FILE, __LINE__, a)
#define EMAIL_STOR_TRACE_INIT_ACCT_FLDR(a,f) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_ACCT_FLDR, EMAIL_STOR_FILE, __LINE__, a, f)
#define EMAIL_STOR_TRACE_INIT_ACCT_CHK(r)   MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_ACCT_CHK, EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_INIT_CNTX(r)       MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_CNTX, EMAIL_STOR_FILE, __LINE__, r)
#define EMAIL_STOR_TRACE_INIT_DONE()		MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_INIT_DONE)
#define EMAIL_STOR_TRACE_RESTORE_START()    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_RESTORE_START, EMAIL_STOR_FILE, __LINE__)
#define EMAIL_STOR_TRACE_ACCT_DEL(a,sod)    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_ACCT_DEL, EMAIL_STOR_FILE, __LINE__, a,sod)
#define EMAIL_STOR_TRACE_ACCT_REACH_MAX(a)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_ACCT_REACH_MAX, EMAIL_STOR_FILE, __LINE__,a)
#define EMAIL_STOR_TRACE_FLDR_REACH_MAX(a,f)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FLDR_REACH_MAX, EMAIL_STOR_FILE, __LINE__,a, f)
#define EMAIL_STOR_TRACE_OFST_REACH_MAX(a,f,o) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_OFST_REACH_MAX, EMAIL_STOR_FILE, __LINE__,a,f,o)
#define EMAIL_STOR_TRACE_FLDR_LIST_ID(a,s)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FLDR_LIST_ID, EMAIL_STOR_FILE, __LINE__, a, s)
#define EMAIL_STOR_TRACE_FLDR_DEL(a, f, s)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FLDR_DEL, EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_FLDR_SYNC(a,f,o,s) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_SYNC, EMAIL_STOR_FILE, __LINE__, a, f, o, s)
#define EMAIL_STOR_TRACE_MSG_DEL(a, f, s)   MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_DEL, EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_MSG_EDIT(a,f,o,t,e)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_EDIT, EMAIL_STOR_FILE, __LINE__, a, f, o, t, e)
#define EMAIL_STOR_TRACE_MSG_EDIT_FSM(s, in, r)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_EDIT_FSM, EMAIL_STOR_FILE, __LINE__, s, in, r)
#define EMAIL_STOR_TRACE_MSG_SET_FLAG(a, f,s) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_SET_FLAG, EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_MSG_LIST(a, f, s)    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_LIST, EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_MSG_NUM_UPDATE(a,f,t,n) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_NUM_UPDATE, EMAIL_STOR_FILE, __LINE__, a, f, t, n)
#define EMAIL_STOR_TRACE_MSG_NUM_CHANGE(t,o,c,n) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_NUM_CHANGE, EMAIL_STOR_FILE, __LINE__, t, o, c, n)
#define EMAIL_STOR_TRACE_MSG_DEL_IND_ERR(o) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_MSG_IND_DEL_ERR, EMAIL_STOR_FILE, __LINE__, o)
#define EMAIL_STOR_TRACE_FLDR_CREATE(s)      MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_STOR_FLDR_CREATE, EMAIL_STOR_FILE, __LINE__, s)
#else /* __MTK_TARGET__ */
#define __E_STOR__ kal_printf("*** [STORAGE] FILE:%c, LINE:%d "
#define EMAIL_STOR_TRACE_FS_SEEK(f,l,r)         __E_STOR__"SEEK:  ERRNO:%d\n", f, l, r)
#define EMAIL_STOR_TRACE_FS_COPY(r)             __E_STOR__"COPY:  ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_RENAME(r)           __E_STOR__"RENAME:ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_DEL(r)              __E_STOR__"DELETE:ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_OPEN(r)             __E_STOR__"OPEN:  ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_ACS_DND(f,l,w)      __E_STOR__"ACCESS DENIED, %w\n", f, l, w)
#define EMAIL_STOR_TRACE_FS_READ(r, s)          __E_STOR__"READ:  ERRNO:%d SIZE:%d\n", EMAIL_STOR_FILE, __LINE__, r, s);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_WRITE(r,s)          __E_STOR__"WRITE: ERRNO:%d SIZE:%d\n", EMAIL_STOR_FILE, __LINE__, r, s);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_FS_CREATE_DIR(r)       __E_STOR__"CREAT: ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);email_stor_fs_errno_detail_set(r)
#define EMAIL_STOR_TRACE_MALLOC(s)              __E_STOR__"ALLOC: SIZE:%d\n", EMAIL_STOR_FILE, __LINE__, s);
#define EMAIL_STOR_TRACE_INIT(r)                __E_STOR__"INIT:  ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r);
#define EMAIL_STOR_TRACE_INIT_START()           __E_STOR__"INIT START DOING ...\n", EMAIL_STOR_FILE, __LINE__);
#define EMAIL_STOR_TRACE_INIT_ACCT(a)           __E_STOR__"INIT ACCT CHK, ACCT:[%d]\n", EMAIL_STOR_FILE, __LINE__, a);
#define EMAIL_STOR_TRACE_INIT_ACCT_FLDR(a,f)    __E_STOR__"INIT ACCT FLDR CHK, ACCT:[%d] FLDR:[%d]\n", EMAIL_STOR_FILE, __LINE__, a, f);
#define EMAIL_STOR_TRACE_INIT_ACCT_CHK(r)       __E_STOR__"INIT ACCT CHK: RES:%d\n", EMAIL_STOR_FILE, __LINE__, r);
#define EMAIL_STOR_TRACE_INIT_DONE()            __E_STOR__"INIT DONE !!!\n", EMAIL_STOR_FILE, __LINE__);
#define EMAIL_STOR_TRACE_INIT_CNTX(r)           __E_STOR__"INIT CNTX: ERRNO:%d\n", EMAIL_STOR_FILE, __LINE__, r); 
#define EMAIL_STOR_TRACE_RESTORE_START()        __E_STOR__"RESTORE BGN: FILE:%c, LINE:%d\n", EMAIL_STOR_FILE, __LINE__);               
#define EMAIL_STOR_TRACE_ACCT_DEL(a,sod)        __E_STOR__"ACCT DELETE:  ACCT:%d SoD:%d\n", EMAIL_STOR_FILE, __LINE__, a, sod);
#define EMAIL_STOR_TRACE_ACCT_REACH_MAX(a)      __E_STOR__"ACCT REACH MAX:  ACCT:%d\n", EMAIL_STOR_FILE, __LINE__, a);  
#define EMAIL_STOR_TRACE_FLDR_REACH_MAX(a,f)    __E_STOR__"FLDR REACH MAX: ACCT:%d FLDR:%d\n", EMAIL_STOR_FILE, __LINE__, a, f);    
#define EMAIL_STOR_TRACE_OFST_REACH_MAX(a,f,o)  __E_STOR__"OFST REACH MAX: ACCT:%d FLDR:%d OFFSET:%d\n", EMAIL_STOR_FILE, __LINE__, a, f, o);
#define EMAIL_STOR_TRACE_FLDR_LIST_ID(a,s)      __E_STOR__"FLDR LIST: ACCT:%d SoD:%d\n", EMAIL_STOR_FILE, __LINE__, a, s)
#define EMAIL_STOR_TRACE_FLDR_DEL(a,f,s)        __E_STOR__"FLDR DELETE: ACCT:%d FLDR:%d SoD:%d\n", EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_FLDR_SYNC(a,f,o,s)     __E_STOR__"FLDR SYNC: ACCT:%d FLDR:%d OFST:%d SoD:%d\n", EMAIL_STOR_FILE, __LINE__, a, f, o, s)
#define EMAIL_STOR_TRACE_MSG_DEL(a,f,s)         __E_STOR__"MSG DEL: ACCT:%d FLDR:%d SoD:%d\n", EMAIL_STOR_FILE, __LINE__, a, f, s)
#define EMAIL_STOR_TRACE_MSG_EDIT(a,f,o,t,e)
#define EMAIL_STOR_TRACE_MSG_EDIT_FSM(s, in, r)
#define EMAIL_STOR_TRACE_MSG_SET_FLAG(a,f,s)
#define EMAIL_STOR_TRACE_MSG_LIST(a,f,s)
#define EMAIL_STOR_TRACE_MSG_NUM_UPDATE(a,f,t,n) __E_STOR__"ACCT:%d FLDR:%d Total/Unread:%d NUM:%d\n", EMAIL_STOR_FILE, __LINE__, a, f, t, n)
#define EMAIL_STOR_TRACE_MSG_NUM_CHANGE(t,o,c,n)
#define EMAIL_STOR_TRACE_MSG_DEL_IND_ERR(o)     __E_STOR__"INDEX NOT FOUND IN INDEX, OFST:%d\n", EMAIL_STOR_FILE, __LINE__, o)
#define EMAIL_STOR_TRACE_FLDR_CREATE(s)
#endif /* __MTK_TARGET__ */

#endif /* __STORAGE_FS_H__ */ 

