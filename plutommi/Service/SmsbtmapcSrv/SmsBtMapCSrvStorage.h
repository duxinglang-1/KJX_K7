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
 *  SmsBtMapCSrvStorage.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT File
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_BTMAP_STORAGE_SRV_H__
#define __SRV_SMS_BTMAP_STORAGE_SRV_H__
#include "MMI_features.h"
#include "MapSrvGprot.h"
#include "SmsBtMapCSrvProt.h"
#include "SmsBtMapCSrvGprot.h"
#include "SmsBtMapCSrvUtil.h"
#include "mmi_frm_mem_gprot.h"
#include "app_datetime.h"


#define SRV_SMS_BTMAPC_INVALID_PDU_ID                  0xFFFF       
#define SRV_SMS_BTMAPC_INVALID_INDEX                   0xFFFF       
#define SRV_SMS_BTMAPC_ACTION_INVALID_ID               0xFFFF

typedef U16 SMS_BTMAPC_CHECKSUM;

#define SRV_SMS_BTMAPC_MAX_SMS_ENTRY             100
#define SRV_SMS_BTMAPC_MAX_FILE_SUPPORT          4

#define SRV_SMS_BTMAPC_MAX_FOLDER_LEN            40
#define SRV_SMS_BTMAPC_ORIGINAL_FILE_EXT_NAME      ".o" 
#define SRV_SMS_BTMAPC_BACKUP_FILE_EXT_NAME      ".bak" 
#define SRV_SMS_BTMAPC_SERVICE_FOLDER_NAME      "\\@SMSBTMAPCSRV\\" 
#define SRV_SMS_BTMAPC_MSG_BTMAPC_NODE_NAME      "msg_btmapc_node" 
#define SRV_SMS_BTMAPC_MSG_BTMAPC_CNTX_NAME      "msg_btmapc_cntx" 
#define SRV_SMS_BTMAPC_MAX_PATH_LEN      (SRV_SMS_BTMAPC_MAX_FOLDER_LEN + 1)

typedef enum
{
    SRV_SMS_NODE_NONE       = 0x00,
    /* If set this flag, the PDU node is invalid */
    SRV_SMS_NODE_INVALID    = 0x01,
    /* If set this flag, the PDU node is used */
    SRV_SMS_NODE_USED       = 0x02,
    /* If set this flag, the prev_index of the PDU node is pointed to a node of msg list */
    SRV_SMS_NODE_FIRST      = 0x04,
    /* If set this flag, this PDU only can be read */
    SRV_SMS_NODE_READING    = 0x08,
    /* If set this flag, this PDU only can be updated */
    SRV_SMS_NODE_UPDATING   = 0x10,
    /* If set this flag, this PDU only can be deleted */
    SRV_SMS_NODE_DELETING   = 0x20,
    /* If set this flag, this PDU can't be read/Updated/Deleted */
    SRV_SMS_NODE_LOCKING    = 0x40
} srv_sms_btmapc_node_flag_enum;

typedef enum
{
    SRV_SMS_BTMAPC_FILE_INDEX_NONE = 0, /* none */
    SRV_SMS_BTMAPC_FILE_CNTX_INFO, /*sms base info for msg list*/
    SRV_SMS_BTMAPC_FILE_INDEX_SMS_INFO, /*sms base info for msg list*/
    SRV_SMS_BTMAPC_FILE_INDEX_SMS_PDU_INDEX,/*pdu list*/
    SRV_SMS_BTMAPC_FILE_INDEX_SMS_ADDR_INFO,/*addr list*/
    SRV_SMS_BTMAPC_FILE_INDEX_SMS_PDU,/*sms pdu*/
    SRV_SMS_BTMAPC_FILE_INDEX_SMS_HD_INDEX,
    SRV_SMS_BTMAPC_FILE_INDEX_TOTAL 
} srv_sms_btmapc_file_index_enum;

typedef enum
{
    SRV_SMS_BTMAPC_OP_FS_SUCC = 0, /* none */
    SRV_SMS_BTMAPC_OP_INVALID_PARA = -1, /* the para is invalid, such, the buff is NULL, the record id is invalid*/
    SRV_SMS_BTMAPC_OP_NOT_AVAILABLE = -2,/*the app init is error, not finish*/
    SRV_SMS_BTMAPC_OP_INVALID_CONTENT = -3,/*the content size is not equ the size expect*/
    SRV_SMS_BTMAPC_OP_MEM_INSUFFICIENT = -4,/*there is no handle*/
    SRV_SMS_BTMAPC_OP_FS_ERROR = -5

} srv_sms_btmapc_op_result_enum;


typedef struct
{
    MMI_BOOL is_download;
    U16 msg_id;
    U8 msg_handle[(SRV_BT_MAP_MAX_HANDLE_STR_LEN + 1) * 2];
}srv_sms_btmapc_msg_index_struct;


typedef struct
{
    srv_sms_btmapc_file_index_enum file_index;         /* where to backup or restore the sms */
    U32 start_record_id;
    U32 record_num;
} srv_sms_btmapc_op_struct;



typedef struct
{
    U32 file_index;                  
    U32 record_size;                           
    U32 record_number;              
} srv_sms_btmapc_file_entry_struct;


typedef struct
{
    SRV_SMS_HANDLE_HEADER
}srv_sms_btmapc_action_struct;


typedef struct
{
    srv_sms_btmapc_box_enum curr_box_type;
    SRV_SMS_HANDLE_HEADER
}srv_sms_btmapc_change_folder_struct;

typedef struct
{
    U8 segment;
    U8 type;
    U8 read_count;
    U8 status;
    U16 prev_pdu_id;
    U16 next_pdu_id;
} srv_sms_btmapc_pdu_node_struct;

typedef struct
{
    MMI_BOOL is_ready;
    U16 total_msg_num;
    U16 unused_msg_head_id;
    U16 used_msg_tail_id;
    S32 hd;
} sms_btmapc_storage_manager_cntx_struct;

typedef struct
{
    srv_sms_status_enum status;
    srv_sms_storage_enum storage_type;
    MMI_BOOL is_hidden;
    MMI_BOOL is_search_concat;
    U8 raw_data_size;
    srv_sms_sim_enum sim_id;
    U16 msg_id;
    U8* pdu_raw_data;
    smslib_general_struct* decode_data;
} srv_sms_btmapc_msg_add_pdu_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    srv_sms_btmapc_spdu_struct *spdu_list[SRV_SMS_MAX_SEG];
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U16 report_id;
    U8 total_pdu;
    U8 curr_index;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;
    srv_sms_cause_enum error_cause;
    srv_sms_btmapc_msg_node_struct msg_node;
} srv_sms_btmapc_save_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    SMS_HANDLE save_handle;
    srv_sms_para_enum update_flag;

    U8 curr_index;
    U8 total_pdu;
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    srv_sms_btmapc_spdu_struct *ori_spdu[SRV_SMS_MAX_SEG];
    srv_sms_cause_enum error_cause;
} srv_sms_btmapc_update_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    S8 content[(SRV_SMS_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH];
    U16 content_len;
} srv_sms_btmapc_get_content_cntx_struct;

typedef struct
{
    U8 total_segment;
    srv_sms_status_enum status;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;
    MYTIME time_stamp;
    U8 **spdu_array;
} srv_sms_btmapc_msg_data_pdu_struct;


typedef struct
{
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    U16 msg_id;
    srv_sms_btmapc_msg_data_pdu_struct *msg_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_read_msg_pdu_cntx_struct;


typedef struct
{
    srv_sms_para_enum update_flag;
    srv_sms_btmapc_spdu_struct* spdu_data;
} srv_sms_btmapc_update_pdu_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U8 *msg_bitmap;
    U8 *deleted_msg_bitmap;
    U16 bitmap_size;
    U16 deleted_num;
    U16 curr_msg_id;
} srv_sms_btmapc_delete_bitmap_cntx_struct;

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_msg_update_pdu_cntx_struct;

typedef struct
{
    srv_sms_storage_enum storage_type;
    U8 curr_seg;
    srv_sms_btmapc_spdu_struct* spdu_data;
} srv_sms_btmapc_add_pdu_struct;

typedef struct
{
    U16 msg_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_msg_delete_pdu_cntx_struct;


typedef struct
{
    srv_sms_btmapc_spdu_struct *spdu_data;
} srv_sms_btmapc_read_pdu_cb_struct;

typedef struct
{
    srv_sms_btmapc_msg_data_pdu_struct *msg_data;
} srv_sms_btmapc_read_msg_pdu_cb_struct;

typedef struct
{
    U16 msg_id;
    U16 pdu_id;
} srv_sms_btmapc_msg_add_pdu_cb_struct;

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_delete_pdu_cntx_struct;

typedef struct
{
    srv_sms_btmapc_msg_node_struct msg_node;
    U8 curr_seg;
    U16 msg_id;
    MMI_BOOL is_hiden;
    MMI_BOOL is_search_concat;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_msg_add_pdu_cntx_struct;

typedef struct
{
    U8 curr_seg;
    U16 pdu_id;
} srv_sms_btmapc_add_pdu_cb_struct;

typedef struct
{
    void *dummy;
} srv_sms_btmapc_msg_delete_pdu_cb_struct;

typedef struct
{
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 msg_ref;
    srv_sms_sr_status_enum tp_st;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
    U8 curr_seg;
    srv_sms_status_enum new_status;
    U16 pdu_id;
    srv_sms_para_enum update_flag;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_update_pdu_cntx_struct;


typedef struct
{
    void *dummy;
} srv_sms_btmapc_msg_update_pdu_cb_struct;


typedef struct
{
    U8 curr_seg;
    srv_sms_status_enum new_status;
    U16 pdu_id;
    srv_sms_para_enum update_flag;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_delete_pdu_cb_struct;

typedef struct
{
    void *dummy;
} srv_sms_btmapc_update_pdu_cb_struct;

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_add_pdu_cntx_struct;

typedef struct
{
    U16 msg_id;
    srv_sms_msg_data_struct *msg_data;  
} srv_sms_btmapc_get_msg_cb_struct;


typedef struct
{
    char folder_path[SRV_SMS_BTMAPC_MAX_FOLDER_LEN];
    char msg_handle[SRV_BT_MAP_MAX_HANDLE_STR_LEN];
} srv_sms_btmapc_node_event_struct;


extern srv_sms_btmapc_msg_node_struct srv_sms_btmapc_msg_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
extern srv_sms_btmapc_pdu_node_struct srv_sms_btmapc_pdu_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
extern U8 srv_sms_btmapc_pdu_detail[SRV_SMS_BTMAPC_MAX_SMS_ENTRY][SRV_SMS_BTMAPC_MAX_SPDU_SIZE];

extern srv_sms_btmapc_msg_index_struct srv_sms_btmapc_handle_list[SRV_SMS_BTMAPC_MAX_SMS_ENTRY];
extern sms_btmapc_storage_manager_cntx_struct sms_btmapc_storage_cntx;

extern srv_sms_btmapc_file_entry_struct sms_btmapc_file_mgr_common_table[SRV_SMS_BTMAPC_MAX_FILE_SUPPORT];

extern void srv_sms_btmapc_storage_reset_data(void);
extern void srv_sms_btmapc_storage_init_data(void);
extern void srv_sms_btmapc_storage_save_data(void);
void srv_sms_btmapc_list_init(void);
U16 srv_sms_btmapc_get_unread_sms_num(void);
U16 srv_sms_btmapc_get_msg_id(srv_sms_btmapc_box_enum msg_box_type, U16 list_index);
U16 srv_sms_btmapc_get_list_size(srv_sms_btmapc_box_enum msg_box_type);
srv_sms_btmapc_box_enum srv_sms_btmapc_get_list_type(
                    srv_sms_status_enum status,
                    srv_sms_storage_enum storage_type,
                    srv_sms_folder_enum folder_id);

U16 srv_sms_btmapc_get_msg_list_index(srv_sms_btmapc_box_enum* msg_box_type, U16 msg_id);
void srv_sms_btmapc_delete_msg_list(
        srv_sms_btmapc_box_enum msg_box_type,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data);
srv_sms_cause_enum srv_sms_btmapc_read_msg_init(
                            srv_sms_btmapc_read_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL change_status,
                            srv_sms_msg_data_struct* msg_data);
srv_sms_cause_enum srv_sms_btmapc_change_msg_status_init(
                            srv_sms_btmapc_change_status_cntx_struct* change_cntx,
                            U16 msg_id,
                            srv_sms_status_enum status);
srv_sms_cause_enum srv_sms_btmapc_delete_msg_init(
                            srv_sms_btmapc_delete_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL is_background);
srv_sms_cause_enum srv_sms_btmapc_check_common_msg_error(U16 msg_id, srv_sms_action_enum action);
srv_sms_btmapc_msg_node_struct* srv_sms_btmapc_get_msg_node(U16 msg_id);
U8* srv_sms_btmapc_get_msg_handle(U16 msgid);
SMS_HANDLE srv_sms_btmapc_read_msg_detail(
                U16 msg_id,
                MMI_BOOL change_status,
                void* msg_data, 
                void *user_data);
SMS_HANDLE srv_sms_btmapc_delete_msg_detail(
                        U16 msg_id,
                        MMI_BOOL is_backgroud,
                        srv_sms_btmapc_delete_cntx_struct *delete_cntx);
MMI_BOOL srv_sms_btmapc_add_msg_into_list(
            U16 *msg_id_list,
            U16 curr_num,
            U16 max_num,
            U16 add_msg_id,
            srv_sms_sort_enum sort_flag,
            srv_sms_order_enum order_flag);
MMI_BOOL srv_sms_btmapc_delete_msg_from_list(
            U16 *msg_id_list,
            U16 msg_num,
            U16 del_msg_id);
U16 srv_sms_btmapc_query_msg_int(
        srv_sms_query_struct *query_data,
        U16* msg_list,
        U16 list_size);
void srv_sms_btmapc_send_msg_callback(SMS_HANDLE sms_handle, MMI_BOOL result, srv_sms_cause_enum cause);
SMS_HANDLE srv_sms_btmapc_change_msg_status_detail(
                U16 msg_id,
                srv_sms_status_enum status,
                srv_sms_btmapc_change_status_cntx_struct *change_cntx);

MMI_BOOL srv_sms_btmapc_is_msg_download(U16 msg_id);
U16 srv_sms_btmapc_add_msg_node(srv_sms_btmapc_msg_node_struct *msg_node);
U16 srv_sms_btmapc_get_msg_id_by_handle(U8 *handle);
void srv_sms_btmapc_str_to_utctime(applib_time_struct * utc_time, const char * str);

MMI_BOOL srv_sms_btmapc_check_msg_op_conflict(U16 msg_id, srv_sms_action_enum action);
void srv_sms_btmapc_update_msg_status(U16 msg_id);
void srv_sms_btmapc_get_msg_info(srv_sms_msg_info_struct* msg_info, U16 msg_id);
void srv_sms_btmapc_update_msg_node(
        U16 msg_id,
        srv_sms_btmapc_msg_node_struct *msg_node,
        U8 curr_seg);
void srv_sms_btmapc_delete_msg_node(U16 msg_id);
void srv_sms_btmapc_set_msg_download(U16 msg_id);
void srv_sms_btmapc_clear_msg_download(U16 msg_id);
extern void srv_sms_btmapc_read_me_sms(
          U16 msg_id, 
        SrvSmsCallbackFunc callback_func,
        void *user_data);
extern void srv_sms_btmapc_write_me_sms(
            U16 msg_id,
            CHAR *content,
        SrvSmsCallbackFunc callback_func,
        void *user_data);
extern void srv_sms_btmapc_get_msg_name(
                U16 msg_id,
                MMI_BOOL is_backup,
                WCHAR* ucs2_buff);
extern void srv_sms_btmapc_get_file_name(
                srv_sms_btmapc_file_index_enum file_index,
                MMI_BOOL is_backup,
                WCHAR* ucs2_buff);
extern void srv_sms_btmapc_get_root_name(WCHAR* ucs2_buff);
extern MMI_BOOL custom_sms_btmapc_using_card_memory(void);

#endif /* __SRV_SMS_BTMAP_STORAGE_SRV_H__ */

