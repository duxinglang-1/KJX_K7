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
 * mma_msgmgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions definitions and functions used by MMA MSGMGR submodule.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_MSGMGR_H
#define _MMA_MSGMGR_H

#include "MMI_features.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "mma_api.h"
#include "mma_struct.h"
#include "mms_def.h"   
#include "mma_cfg.h"

#define MMA_PARSING_DRM_ENCODING_REQD_FREE_MEMORY ((kal_uint32)(80*1024))
typedef enum
{
    MMA_MSGMGR_STATE_IDLE,
    MMA_MSGMGR_STATE_CREATE_PHONE_MSG_LIST,
    MMA_MSGMGR_STATE_CREATE_CARD_MSG_LIST,
    MMA_MSGMGR_STATE_CREATE_CARD_PLUG_IN_MSG_LIST,
    MMA_MSGMGR_STATE_READY,
    MMA_MSGMGR_STATE_UPDATING_MSG_LIST
} mma_msgmgr_state_enum;

typedef enum
{
    MMA_MSGMGR_GET_FROM_NONE,
    MMA_MSGMGR_GET_FROM_CREATE,
    MMA_MSGMGR_GET_FROM_NOTIFICATION,
    MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD,
    MMA_MSGMGR_GET_FROM_MESSAGE,
    MMA_MSGMGR_GET_FROM_READ_REPORT,
    MMA_MSGMGR_GET_FROM_DELIVERY_REPORT
} mma_msgmgr_new_message_source_enum;

typedef enum
{
    MMA_MSGMGR_MSG_OPER_NONE = 0x00,
    MMA_MSGMGR_MSG_OPER_NEED_PARSE = 0x01,
    MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT = 0x02,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND = 0x04,   /* Before we process this operation, there is no pending operation */
    MMA_MSGMGR_MSG_OPER_DELETE = 0x08,
    MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT = 0x10,
    MMA_MSGMGR_MSG_OPER_DELETE_DONE = 0x20,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP = 0x40,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_REFRESH_IND = 0x80,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_HIGHLIGHT_IND = 0x100,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_DELETE_RSP = 0x200,
    MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG = 0x400,
    MMA_MSGMGR_MSG_OPER_MOVE_REQ_SENT = 0x800,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_CREATE_MMS_RSP = 0x1000,
    MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP = 0x2000,
    MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND = 0x4000,
    MMA_MSGMGR_MSG_OPER_NEED_SEND_SAVE_RSP = 0x8000
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    ,MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE = 0x10000
    ,MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT = 0x20000
    ,MMA_MSGMGR_MSG_OPER_PARSING_STATUS_IND = 0x40000
    ,MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED = 0x80000
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    ,MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND = 0x100000
#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
    ,MMA_MSGMGR_MSG_OPER_COPY_ARCHIVE_REQ = 0x200000
#endif   /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */
} mma_msgmgr_msg_oper_enum;

typedef enum
{
    MMA_MSGMGR_IS_RECENT_EVT = 0,
    MMA_MSGMGR_UNSET_RECENT_EVT
} mma_msgmgr_recent_evt_enum;

typedef enum
{
    MMA_MSGMGR_MSG_STATE_STARTED = 0,
    MMA_MSGMGR_MSG_STATE_MMS_CREATING,
    MMA_MSGMGR_MSG_STATE_DRM_ENCODING,
    MMA_MSGMGR_MSG_STATE_DELETE_OLD_MSG,
    MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG,
    MMA_MSGMGR_MSG_STATE_MMS_PARSING,
    MMA_MSGMGR_MSG_STATE_FINISHING
} mma_msgmgr_msg_state_enum;

typedef enum
{
    MMA_MSGMGR_MSG_TYPE_PUSH,
    MMA_MSGMGR_MSG_TYPE_DEFER_DOWNLOAD,
    MMA_MSGMGR_MSG_TYPE_USER_CREATE,
    MMA_MSGMGR_MSG_TYPE_TOTAL
} mma_msgmgr_msg_type_enum;


typedef struct mma_msgmgr_msg_id_list_struct_st
{
    kal_uint32 msg_id;
    kal_uint32 date;
    struct mma_msgmgr_msg_id_list_struct_st *next;
    kal_uint8 suffix;
} mma_msgmgr_msg_id_list_struct;


typedef struct mma_msgmgr_new_msg_info_struct_st
{
    kal_uint32 req_id;
    kal_uint32 msg_id;
    kal_uint32 def_noti_msg_id;
    kal_uint8 msg_type; /* mma_msgmgr_msg_type_enum */
    kal_uint8 state;    /* mma_msgmgr_msg_state_enum */
    kal_uint8 new_msg_state;    /* mma_msgmgr_new_message_source_enum */
    kal_uint8 msg_sim_id;       /* srv_um_sim_enum */
    void *data;
    struct mma_msgmgr_new_msg_info_struct_st *next;
} mma_msgmgr_new_msg_info_struct;

/* required for the list of msg_id and their corresponding result */
typedef struct
{
    MSF_UINT32 req_id;
    MSF_UINT32 no_of_msg;
    MSF_UINT32 *msg_id;
    MSF_UINT32 *result;
    MSF_UINT16 folder;
    MSF_UINT8  app_id;
    module_type source;
} mma_msgmgr_req_info_struct;

/* required for storing the notification information */
typedef struct mma_msgmgr_recv_notif_data_struct_st
{
    MmsMsgReplyNotification *data;
    struct mma_msgmgr_recv_notif_data_struct_st *next;
} mma_msgmgr_recv_notif_data_struct;

typedef struct
{
    kal_uint8 state;        /*mma_msgmgr_state_enum */
    kal_uint8 is_cnt_msg_oper_sent;
    kal_uint8 is_notify_sig_sent;
    kal_uint8 process_create_req_num;
    kal_uint32 count_int_parse_req;
    kal_uint32 source_module;   /* To put the source module ID in Delete folder */
    mma_signal_struct *pending_req_list;
    mma_msg_info_list_struct *msg_list;
    mma_msgmgr_new_msg_info_struct *new_msg_req_queue;  /* Request queue of adding new message */
	mma_msgmgr_req_info_struct *delete_req;		/* need for the mark several feature */
    void *move_req;		/* to move msg storage */
    void *user_data;    /* for delete folder */
    void *copy_archive_req;		/* to copy mms to Archive */
    mma_mms_folder_mms_count_status_struct mms_folder_status;
    mma_msgmgr_msg_id_list_struct *unread_msg_list;
    mma_msgmgr_msg_id_list_struct *recent_event_list;
	mma_msg_info_list_struct *cache_msg_list; // Sandeep: For unlimited handling
    mma_msgmgr_recv_notif_data_struct *notif_data;
    mma_result_enum delete_result;                      /* Used for MMI_UM_DELETE_FOLDER_REQ and WAP_MMA_DELETE_REQ */              /* It is used for WAP_MMA_DELETE_RECENT_EVT_REQ */
} mma_msgmgr_context_strcut;

typedef struct
{
    kal_uint16 inbox_unread_msg_number;
    kal_uint16 inbox_read_msg_number;
    kal_uint16 unsent_msg_number;
    kal_uint16 sent_msg_number;
    kal_uint16 draft_msg_number;
    kal_uint16 predefined_template_msg_number;
    kal_uint16 userdefined_template_msg_number;
    kal_uint16 archive_msg_number;
	kal_uint8 msg_sim_id;
} mma_msgmgr_msg_num_status_strcut;


typedef struct
{
    kal_uint32 source;
    kal_uint32 req_id;
    kal_uint32 o_msg_id;    /* send / forward */
    kal_uint32 xml_size;
    kal_uint32 buffer_index;
    kal_uint32 msg_id;
    char *upload_filepath;  /* upload */
    kal_wchar *xml_filepath;
    kal_uint8 app_id;
    kal_bool more;
    MmsFileType msg_filetype;
    mma_app_mode_enum mode;
	mma_mms_description_struct *mms_dsr;
} mma_msgmgr_create_info_struct;

#define MMA_MSGMGR_GET_STATE() g_mma_msgmgr_cntx.state
#define MMA_MSGMGR_SET_STATE(x) mma_msgmgr_set_state(x, __LINE__)

#define MMA_MSGMGR_MSG_SET_FLAG(x,y) x |= y
#define MMA_MSGMGR_MSG_UNSET_FLAG(x,y) x &= ~y
#define MMA_MSGMGR_MSG_CHK_FLAG(x,y) (x&y)

#define MMA_MAX_FILE_NAME_LENGTH 50
#define MMA_MSGMGR_MAX_FILE_NAME_LENGTH 50
/* data in the app_data array */
#define MMA_MSGMGR_LOCK_MODE_APP_DATA_POS 0
#define MMA_MSGMGR_CORRUPT_MMS_POS 1
#define MMA_MSGMGR_PREV_FOLDER_POS 2
#define MMA_MSGMGR_INT_VERSION_POS 3            /* to differentaite between different MMS functionality */
#define MMA_MSGMGR_RECEIVED_MMS_POS 4
#define MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_SIZE_POS 4	/* 5-8*/
#define MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_OFFSET_POS 8	/*9-12 */
#define MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_CHARSET_POS 12	/*13-14 */
#define MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_DRM_INFO_POS 14	/*15 only */
#define MMA_MSGMGR_MAX_CREATE_TASK_NUM 1        /* Only 1 creation process is handled at a time */

extern kal_bool mma_msgmgr_init(void);
extern kal_bool mma_msgmgr_terminate(void);
extern void mma_msgmgr_process_int_sig(mma_signal_struct *sig);
extern mma_msg_info_list_struct *mma_msgmgr_get_msg_from_list(kal_uint32 msg_id);
extern void mma_msgmgr_set_state(kal_uint32 state, int line_no);
extern mma_msg_info_list_struct *mma_msgmgr_get_msg_info_by_idx(kal_uint32 folder, kal_uint32 index, kal_uint8 sim_id);
extern void mma_msgmgr_send_int_perform_msg_oper_ind(void);
extern kal_bool mma_msgmgr_handle_rsp(kal_uint16 sig, void *sigData);
extern kal_uint16 mma_msgmgr_get_total_msg_num(kal_uint8 storage_type);
extern kal_bool mma_msgmgr_is_busy(void);
extern kal_bool mma_msgmgr_check_msg_exist(kal_uint32 msg_id);
extern mma_result_enum mma_msgmgr_add_new_message_req_hdlr(
                kal_uint32 msg_id,
                mma_msgmgr_new_message_source_enum new_msg_source,
                kal_uint32 def_ori_msg_id,
                kal_uint32 sim_id);
extern mma_result_enum mma_msgmgr_add_new_report_notif_req_hdlr( mma_msgmgr_new_message_source_enum new_msg_source, void *data);
extern kal_bool mma_msgmgr_is_valid_notifiction(kal_uint32 msg_id);
extern kal_uint8 mma_msgmgr_get_msg_suffix(kal_uint32 msg_id);
extern kal_bool mma_msgmgr_msg_info_exist(kal_uint32 msg_id);
//extern void mma_msgmgr_set_msg_status(kal_uint32 msg_id, mma_msg_status_enum status);
extern mma_result_enum mma_msgmgr_update_postcard_subject_address(kal_uint32 msg_id, kal_char* greeting_text, kal_char* recipient_name);
extern mma_msg_type_enum mma_msgmgr_parse_mode_msg_type(kal_uint32 mode, kal_uint32 msg_id);
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
extern void mma_msgmgr_get_encode_filepath(MSF_UINT32 msg_id, char *dest);
extern kal_bool mma_msgmgr_check_parsing_status(void);
extern void mma_msgmgr_reset_parsing_status(kal_uint32 msg_id);
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
extern void mma_msgmgr_check_any_pending_int_parse_msg(void);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern kal_bool mma_msgmgr_get_report_data(kal_uint32 msg_id, MmaReport *get_report_data);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern kal_uint16 mma_msgmgr_get_msg_num_of_folder(mma_folder_enum folder);
extern void mma_msgmgr_update_mms_folder_status(mma_msg_info_list_struct *msg_list, kal_bool is_update,
                                                kal_uint8 old_folder, kal_uint8 new_folder);
extern mma_result_enum mma_msgmgr_get_msg_folder_count(mma_mms_folder_mms_count_status_struct *result);
extern mma_result_enum mma_msgmgr_set_read_status(kal_uint32 msg_id, kal_bool is_read,
                                                  mms_msg_info_property_struct *property_st);
extern mma_result_enum mma_msgmgr_set_lock_status(kal_uint32 msg_id, kal_uint8 is_lock, kal_uint8 is_corrupt,
                                                  mms_msg_info_large_data_struct *large_data_st);
extern mma_result_enum mma_msgmgr_set_sim_status(kal_uint32 msg_id, kal_uint8 sim_id,
                                                  mms_msg_info_property_struct *property_st);
extern void mma_msgmgr_reset_unread_report_count(void);
extern kal_uint16 mma_msgmgr_get_unread_report_count(void);
extern kal_wchar* mma_translate_report_status_to_string(kal_uint8 report_type, kal_uint8 status);
#endif /* _MMA_MSGMGR_H */ 

