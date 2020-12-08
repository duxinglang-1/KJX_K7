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
 *  SmsStorageManagerSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager core codes
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "fs_errcode.h"

#include "mmi_common_app_trc.h"
#include "mmi_msg_struct.h"
#include "mmi_msg_context.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"
#include "SmsUtilSrv.h"
#include "SmsEmsSrv.h"
#include "SmsSettingSrv.h"
#include "SmsAtHandlerSrv.h"
#include "SmsStorageCoreSrv.h"
#include "SmsConverterSrv.h"
#include "mmi_frm_timer_gprot.h"

#ifdef __SRV_SMS_ARCHIVE__
#include "SmsArchiveSrv.h"
#endif /* __SRV_SMS_ARCHIVE__ */
#include "SmsDispatchSrv.h"
#include "PhbSrvGprot.h"
#ifdef __SRV_SMS_DELIVERY_STATUS__
#include "SmsStatusReportSrv.h"
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
#include "ems.h"
#include "smslib.h"
#include "ps_public_utility.h"

#include "SmsBackupRestoreSrv.h"
#include "SmsStatusReportSrv.h"

/**************************************************************
* MARCO
**************************************************************/
#ifdef __SRV_SMS_ARCHIVE__
#if (SRV_SMS_MAX_ARCH_ENTRY > SRV_SMS_MAX_SMS_ENTRY)
#define SRV_SMS_QUERY_LIST_SIZE     SRV_SMS_MAX_ARCH_ENTRY
#else /* (SRV_SMS_MAX_ARCH_ENTRY > SRV_SMS_MAX_SMS_ENTRY) */
#define SRV_SMS_QUERY_LIST_SIZE     SRV_SMS_MAX_SMS_ENTRY
#endif /* (SRV_SMS_MAX_ARCH_ENTRY > SRV_SMS_MAX_SMS_ENTRY) */
#else /* __SRV_SMS_ARCHIVE__ */
#define SRV_SMS_QUERY_LIST_SIZE     SRV_SMS_MAX_SMS_ENTRY
#endif /* __SRV_SMS_ARCHIVE__ */

#if (SRV_SMS_QUERY_LIST_SIZE > (SRV_SMS_MAX_BUFF_SIZE / 2)) 
#define __SRV_SMS_LARGE_LIST__
#else /* (SRV_SMS_QUERY_LIST_SIZE > (SRV_SMS_MAX_BUFF_SIZE / 2)) */
#undef __SRV_SMS_LARGE_LIST__
#endif /* (SRV_SMS_QUERY_LIST_SIZE > (SRV_SMS_MAX_BUFF_SIZE / 2)) */

#define SRV_SMS_TPUD_SIZE           140

#ifdef __SRV_SMS_AT_SUPPORT__

#define STORAGE_ASYNC_CALLBACK(action, result, cause, data, userdata, cb_func)   \
            srv_sms_exit_mmi_operating();       \
            srv_sms_async_callback(             \
                action,                         \
                result,                         \
                cause,                          \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define STORAGE_ASYNC_SUCC_CALLBACK(action, data, userdata, cb_func)    \
            srv_sms_exit_mmi_operating();       \
            srv_sms_async_callback(             \
                action,                         \
                MMI_TRUE,                       \
                SRV_SMS_CAUSE_NO_ERROR,         \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define STORAGE_ASYNC_ERR_CALLBACK(action, cause, userdata, cb_func)   \
            srv_sms_exit_mmi_operating();       \
            srv_sms_async_callback(             \
                action,                         \
                MMI_FALSE,                      \
                cause,                          \
                NULL,                           \
                0,                              \
                userdata,                       \
                cb_func);
#else

#define STORAGE_ASYNC_CALLBACK(action, result, cause, data, userdata, cb_func)   \
            srv_sms_async_callback(             \
                action,                         \
                result,                         \
                cause,                          \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define STORAGE_ASYNC_SUCC_CALLBACK(action, data, userdata, cb_func)    \
            srv_sms_async_callback(             \
                action,                         \
                MMI_TRUE,                       \
                SRV_SMS_CAUSE_NO_ERROR,         \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define STORAGE_ASYNC_ERR_CALLBACK(action, cause, userdata, cb_func)   \
            srv_sms_async_callback(             \
                action,                         \
                MMI_FALSE,                      \
                cause,                          \
                NULL,                           \
                0,                              \
                userdata,                       \
                cb_func);
#endif

/**************************************************************
* Structure Declaration
**************************************************************/

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    srv_sms_spdu_struct *spdu_list[SRV_SMS_MAX_SEG];
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U16 report_id;
    U8 total_pdu;
    U8 curr_index;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;
    srv_sms_cause_enum error_cause;
    srv_sms_msg_node_struct msg_node;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct tcard_msg_node;
#endif
} srv_sms_save_cntx_struct;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef struct
{
    void *cntx;
    U16 msg_id;
    void *event_data;
    srv_sms_action_enum action_type;
    srv_sms_update_tcard_op_enum total_flag;/*total number action*/
    srv_sms_update_tcard_op_enum curr_flag; /*the curr action*/
}srv_sms_update_tcard_cntx_struct;


typedef struct
{
    U16 msg_id;
    U16 pdu_id;
    MMI_BOOL is_add;
    MMI_BOOL is_hiden;
    void *user_data;
    SrvSmsCallbackFunc callback_func; 
}srv_sms_receive_tcard_cntx_struct;

typedef struct
{
    U16 msg_id;
    U16 pdu_id;
    void *event_data;
    MMI_BOOL is_hiden;
    void *user_data;
    SrvSmsCallbackFunc callback_func; 
}srv_sms_receive_tcard_append_cntx_struct;


typedef struct
{
    void *user_data;
    SrvSmsCallbackFunc callback_func; 
} srv_sms_for_tcard_cntx_struct;


typedef struct
{
    srv_tcard_op_struct *cntx;
    srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
} srv_sms_tcard_async_cntx_struct;


#endif






typedef struct
{
    SRV_SMS_HANDLE_HEADER
    srv_sms_event_delete_struct *event_data;
} srv_sms_delete_archive_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U8 *msg_bitmap;
    U8 *deleted_msg_bitmap;
    U16 bitmap_size;
    U16 deleted_num;
    U16 curr_msg_id;
} srv_sms_delete_bitmap_cntx_struct;


typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    S8 content[(SRV_SMS_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH];
    U16 content_len;
} srv_sms_get_content_cntx_struct;

typedef struct
{
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    U16 msg_id;
    srv_sms_msg_data_pdu_struct *msg_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_read_msg_pdu_cntx_struct;

typedef struct
{
    srv_sms_msg_node_struct msg_node;
    U8 curr_seg;
    U16 msg_id;
    MMI_BOOL is_hiden;
    MMI_BOOL is_search_concat;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_msg_add_pdu_cntx_struct;

typedef struct
{
    U16 msg_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_msg_delete_pdu_cntx_struct;

typedef struct
{
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_get_reply_path_cntx_struct;

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_msg_update_pdu_cntx_struct;

typedef struct
{
    U16 pdu_id;
    U16 msg_id;
    srv_sms_sr_status_enum old_sts;
    srv_sms_sr_status_enum tp_st;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_update_srs_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 src_pdu_list[SRV_SMS_MAX_SEG];
    U16 dest_pdu_list[SRV_SMS_MAX_SEG];     
    /* the PDU ID list which need to be moved to 
     * destination in the src_pdu_list */
    U16 moved_pdu_list[SRV_SMS_MAX_SEG];
    /* the PDU ID list which have added in destination
     * in the dest_pdu_list */
    U16 added_pdu_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 added_num;
    U8 moved_num;
    U8 curr_index;
    U16 msg_id;
    srv_sms_sim_enum msg_sim_id;
    srv_sms_storage_enum dest_storage;
    srv_sms_sim_enum dest_sim_id;
    srv_sms_cause_enum error_cause;
} srv_sms_copy_cntx_struct;

typedef struct
{
    MMI_BOOL result;
    MMI_BOOL is_add;
    U16 new_msg_id;
    srv_sms_copy_cntx_struct *copy_cntx;  
    void *event_info;
} srv_sms_copy_pdu_list_update_struct;


typedef struct
{
    U16 dest_msg_id;
} srv_sms_copy_int_cb_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    U16 dest_msg_id;
    EMSData *ems_data;
} copy_from_arch_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    U16 dest_entry_id;
    srv_sms_msg_data_struct msg_data;
    srv_sms_msg_info_struct msg_info;
} copy_to_arch_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    srv_sms_int_msg_data_struct *msg_data;
} backup_to_cloud_cntx_struct;

typedef MMI_BOOL(*SrvSmsCompareFunc)(U16 left_msg_id, U16 right_msg_id);


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
#ifdef __SRV_SMS_LARGE_LIST__
static U16 srv_sms_query_list[SRV_SMS_QUERY_LIST_SIZE];
#endif /* __SRV_SMS_LARGE_LIST__ */


/**************************************************************
* Static Function Declaration
**************************************************************/
static srv_sms_status_enum srv_sms_get_msg_status_int(U16 msg_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_tcard_update_list_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_tcard_receive_list_update_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_tcard_receive_append_list_update_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_tcard_delete_list_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_tcard_copy_list_callback(srv_sms_callback_struct *callback_data);

static void srv_sms_for_tcard_callback(srv_tcard_callback_struct *tcard_callback_data);
static void srv_sms_tcard_handle_asyc_copy(void *arg);

#endif
//static void srv_sms_read_msg_callback(srv_sms_callback_struct *callback_data);
//static void srv_sms_read_msg_change_status(srv_sms_read_cntx_struct* read_cntx);
//static void srv_sms_read_msg_update_callback(srv_sms_callback_struct *callback_data);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static srv_sms_cause_enum srv_sms_read_msg_init(
                            srv_sms_read_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL change_status,
                            srv_sms_msg_data_struct* msg_data);

//static void srv_sms_read_msg_deinit(srv_sms_read_cntx_struct *read_cntx);(skyfyx)

static void srv_sms_save_msg_curr_pdu(srv_sms_save_cntx_struct *save_cntx);
static void srv_sms_save_msg_del_callback(srv_sms_callback_struct *callback_data);
static srv_sms_cause_enum srv_sms_save_msg_init(srv_sms_save_cntx_struct* save_cntx);
static void srv_sms_save_msg_get_pdu_list(U8 **pdu_list, U8 pdu_total, void* user_data);
static void srv_sms_save_msg_deinit(srv_sms_save_cntx_struct *save_cntx);

static void srv_sms_update_msg_next(srv_sms_update_cntx_struct* update_cntx);
static void srv_sms_update_msg_restore(srv_sms_update_cntx_struct *update_cntx);
static void srv_sms_update_msg_restore_callback(srv_sms_callback_struct *callback_data);
#ifdef __SRV_SMS_DELIVERY_STATUS__
static MMI_BOOL srv_sms_update_msg_srs_changed_hdlr(srv_sms_event_struct* event_data);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
static MMI_BOOL srv_sms_update_msg_check_data(
                    U16 msg_id,
                    srv_sms_int_msg_data_struct* msg_data);
static void srv_sms_update_msg_convert_data(
                srv_sms_update_pdu_struct *update_data,
                srv_sms_spdu_struct *spdu_data,
                srv_sms_update_cntx_struct *update_cntx);
static void srv_sms_update_msg_init(
                srv_sms_update_cntx_struct* update_cntx,
                U16 msg_id);
static void srv_sms_update_msg_deinit(srv_sms_update_cntx_struct *update_cntx);

static SMS_HANDLE srv_sms_delete_msg_ext(
                    U16 msg_id,
                    MMI_BOOL is_backgroud,
                    SrvSmsCallbackFunc callback_func,
                    void *user_data);
static void srv_sms_delete_msg_ext_callback(srv_sms_callback_struct *callback_data);
#ifdef __SRV_SMS_ARCHIVE__
static void srv_sms_delete_archive_msg_callback(srv_sms_callback_struct *callback_data);
#endif /* __SRV_SMS_ARCHIVE__ */
static srv_sms_cause_enum srv_sms_delete_msg_init(
                            srv_sms_delete_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL is_background);

static void srv_sms_delete_msg_bitmap_callback(srv_sms_callback_struct *callback_data);

static void srv_sms_change_status_update_next(srv_sms_change_status_cntx_struct* change_cntx);
static void srv_sms_change_status_restore_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_change_status_restore_next(srv_sms_change_status_cntx_struct* change_cntx);
static srv_sms_cause_enum srv_sms_change_msg_status_init(
                            srv_sms_change_status_cntx_struct* change_cntx,
                            U16 msg_id,
                            srv_sms_status_enum status);

static void srv_sms_get_msg_content_callback(srv_sms_callback_struct *callback_data);
static srv_sms_cause_enum srv_sms_get_msg_content_init(
                            srv_sms_get_content_cntx_struct* get_content_cntx,
                            U16 msg_id);
static void srv_sms_get_msg_content_deinit(srv_sms_get_content_cntx_struct* get_content_cntx);

static void srv_sms_read_msg_pdu_callback(srv_sms_callback_struct *callback_data);
static srv_sms_cause_enum srv_sms_read_msg_pdu_init(
                            srv_sms_read_msg_pdu_cntx_struct* read_msg_cntx,
                            U16 msg_id,
                            srv_sms_msg_data_pdu_struct* msg_data,
                            SrvSmsCallbackFunc callback_func,
                            void* user_data);
static void srv_sms_read_msg_pdu_deinit(srv_sms_read_msg_pdu_cntx_struct* read_msg_cntx);

static void srv_sms_msg_add_pdu_callback(srv_sms_callback_struct* callback_data);

static void srv_sms_msg_append_pdu_callback(srv_sms_callback_struct* callback_data);

static void srv_sms_msg_delete_pdu_callback(srv_sms_callback_struct* callback_data);

static void srv_sms_msg_update_pdu_callback(srv_sms_callback_struct* callback_data);

#ifdef __SRV_SMS_DELIVERY_STATUS__
static void srv_sms_update_sr_status_trigger(void *user_data);
static void srv_sms_update_sr_status_callback(srv_sms_callback_struct* callback_data);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

static void srv_sms_query_msg_attribute(
                U16 *msg_id_list,
                U16 *msg_num,
                srv_sms_query_enum query_flag,
                srv_sms_query_struct *query_data);

static MMI_BOOL srv_sms_query_is_match(
                    U16 msg_id,
                    srv_sms_query_enum query_flag,
                    srv_sms_query_struct *query_data);

static void srv_sms_sort_msg_timestamp(
                    U16 *msg_id_array,
                    U16 msg_num,
                    srv_sms_order_enum order_flag);
static void srv_sms_sort_msg_timestamp_int(U16 *msg_id_array, U16 msg_num, MMI_BOOL flag);//  true for desc, false for asc
static void srv_sms_sort_msg_timestamp_asc(U16 *msg_id_array, U16 msg_num);
static void srv_sms_sort_msg_timestamp_desc(U16 *msg_id_array, U16 msg_num);

static void srv_sms_add_msg_into_list_by_desc_timestap(
                U16 *msg_id_list,
                U16 curr_num,
                U16 max_num,
                U16 add_msg_id);

static void srv_sms_get_msg_reply_path_callback(srv_sms_callback_struct* callback_data);

static srv_sms_cause_enum srv_sms_check_common_msg_error(U16 msg_id, srv_sms_action_enum action);
static srv_sms_cause_enum srv_sms_check_common_msg_error_without_at(
                            U16 msg_id,
                            srv_sms_action_enum action);

static void srv_sms_send_memory_status(MMI_BOOL is_mem_full, srv_sms_sim_enum sim_id);
static void srv_sms_emit_memory_status_event(
                MMI_BOOL is_mem_full,
                srv_sms_mem_enum mem_type,
                srv_sms_sim_enum sim_id);

#ifdef __SRV_SMS_ARCHIVE__
static MMI_BOOL srv_sms_is_archive_msg(U16 msg_id);
static U16 srv_sms_msg_id_to_archive_entry_id(U16 msg_id);
static U16 srv_sms_archive_entry_id_to_msg_id(U16 entry_id);
#endif /* __SRV_SMS_ARCHIVE__ */

static U16* srv_sms_malloc_query_msg_list(U32 msg_list_size);
static void srv_sms_free_query_msg_list(U16* query_msg_list);

static SMS_HANDLE srv_sms_copy_msg_int(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    srv_sms_storage_enum dest_storage,
                    srv_sms_sim_enum dest_sim_id,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);
static void srv_sms_copy_hdlr(srv_sms_copy_cntx_struct *copy_cntx);
//static void srv_sms_copy_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_copy_del_added_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_copy_del_moved_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_copy_succ_hdlr(srv_sms_copy_cntx_struct* copy_cntx);
static srv_sms_cause_enum srv_sms_copy_init(
                            srv_sms_copy_cntx_struct* copy_cntx,
                            U16 msg_id,
                            srv_sms_storage_enum dest_storage,
                            srv_sms_sim_enum dest_sim_id);
static void srv_sms_copy_deinit(srv_sms_copy_cntx_struct *copy_cntx);
#ifdef __SRV_SMS_ARCHIVE__
static SMS_HANDLE srv_sms_copy_to_archive(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

static void copy_to_arch_read_callback(srv_sms_callback_struct *callback_data);
static void copy_to_arch_read_abort_callback(srv_sms_callback_struct *callback_data);
static void copy_to_arch_del_callback(srv_sms_callback_struct *callback_data);
static srv_sms_cause_enum copy_to_arch_init(
                            copy_to_arch_cntx_struct *copy_cntx,
                            U16 msg_id);
static void copy_to_arch_deinit(copy_to_arch_cntx_struct *copy_cntx);


static SMS_HANDLE srv_sms_copy_from_archive(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    srv_sms_storage_enum dest_storage,
                    srv_sms_sim_enum dest_sim_id,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data);

static void copy_from_arch_save_callback(srv_sms_callback_struct* callback_data);
static void copy_from_arch_save_abort_callback(srv_sms_callback_struct* callback_data);
static void copy_from_arch_del_ori_callback(srv_sms_callback_struct* callback_data);
static void copy_from_arch_del_saved_callback(srv_sms_callback_struct* callback_data);
static void copy_from_arch_deinit(copy_from_arch_cntx_struct* copy_cntx);
#endif /* __SRV_SMS_ARCHIVE__ */


/**************************************************************
* Function Defination
**************************************************************/

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_tcard_valid
 * DESCRIPTION
 *  Check whether the tcard is valid.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_tcard_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return storage_cntx.is_tcard_ready;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_tcard_sms_valid
 * DESCRIPTION
 *  Check whether the SMS is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_tcard_sms_valid(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid = MMI_TRUE;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    U16 pdu_id;
    U16 temp_pdu_id;
    U16 status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id);
    pdu_id = tcard_msg_node->start_pdu_id;
    if (pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        temp_pdu_id = srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM].prev_pdu_id;
        status = srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM].status;
        if(status == SRV_SMS_STATUS_NONE || (temp_pdu_id - SRV_SMS_MAX_MSG_NUM)!= msg_id)
        {
            is_valid = MMI_FALSE;
        }
    }
    else
    {
        is_valid = MMI_FALSE;
    }
    
//    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_IS_TCARD_SMS_VALID, is_valid);

    return is_valid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_invalid_tcard_sms
 * DESCRIPTION
 *  Check whether the SMS is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void srv_sms_delete_invalid_tcard_sms(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    MMI_BOOL int_result;
    srv_sms_event_delete_struct delete_event;
    
    
    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id);
    delete_event.msg_id = msg_id + SRV_SMS_MAX_MSG_NUM;
    srv_sms_tcard_msg_node_to_msg_info(&delete_event.msg_info, tcard_msg_node);
    tcard_msg_node->status = SRV_SMS_STATUS_NONE;

    
    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_event);

    if(!int_result)
    {
        srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_event);
    }                
}

#endif




/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_sms_ready
 * DESCRIPTION
 *  Check whether the SMS is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_sms_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_SMS_READY, storage_cntx.is_ready);

    return storage_cntx.is_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_sms_busy
 * DESCRIPTION
 *  Check wheter the SMS storage is busy for Reading, Saving, Deleting, Updating, etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_sms_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((storage_cntx.is_ready == MMI_FALSE)
    #ifdef __SRV_SMS_AT_SUPPORT__
        || (srv_sms_is_in_mmi_operating() == MMI_TRUE)
    #endif
        )
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_SMS_BUSY, storage_cntx.is_ready, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_msg_exist
 * DESCRIPTION
 *  Check Wether the message is existed
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_msg_exist(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_MSG_EXIST, msg_id);

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
        {
            result = MMI_TRUE;
        }
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
            result = MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_MSG_EXIST_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_msg_complete
 * DESCRIPTION
 *  Check whether the message is completed
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_msg_complete(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        result = srv_sms_archive_get_complete_flag(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            U32 next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
            U16 start_seg = srv_sms_msg_list[msg_id].start_seg;
            U16 total_seg;
            U8 curr_seg = 0;

            total_seg = srv_sms_msg_list[msg_id].total_seg - start_seg + 1;

            if (total_seg > SRV_SMS_MAX_SEG)
            {
                total_seg = SRV_SMS_MAX_SEG;
            }

            while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                curr_seg++;

                /* If the segments are not continuous */
                if (srv_sms_pdu_list[next_pdu_id].segment != curr_seg)
                {
                    result = MMI_FALSE;
                    break;
                }

                next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
            }

            if (curr_seg < total_seg)
            {
                result = MMI_FALSE;
            }
        #else
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                U32 next_pdu_id;
                U16 start_seg;
                U16 total_seg;
                srv_sms_tcard_msg_node_struct *tcard_msg_list;
                U16 temp_msg_id;
                U8 curr_seg = 0;

                temp_msg_id = msg_id - SRV_SMS_MAX_MSG_NUM;
                tcard_msg_list = srv_sms_get_tcard_msg_list();
                next_pdu_id = tcard_msg_list[temp_msg_id].start_pdu_id;
                start_seg = tcard_msg_list[temp_msg_id].start_seg;
                total_seg = tcard_msg_list[temp_msg_id].total_seg - start_seg + 1;


                if (total_seg > SRV_SMS_MAX_SEG)
                {
                    total_seg = SRV_SMS_MAX_SEG;
                }

                while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    curr_seg++;

                    /* If the segments are not continuous */
                    if (srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].segment != curr_seg)
                    {
                        result = MMI_FALSE;
                        break;
                    }

                    next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                }

                if (curr_seg < total_seg)
                {
                    result = MMI_FALSE;
                }
                
            }
            else
            {
            U32 next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
            U16 start_seg = srv_sms_msg_list[msg_id].start_seg;
            U16 total_seg;
            U8 curr_seg = 0;

            total_seg = srv_sms_msg_list[msg_id].total_seg - start_seg + 1;

            if (total_seg > SRV_SMS_MAX_SEG)
            {
                total_seg = SRV_SMS_MAX_SEG;
            }

            while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                curr_seg++;

                /* If the segments are not continuous */
                if (srv_sms_pdu_list[next_pdu_id].segment != curr_seg)
                {
                    result = MMI_FALSE;
                    break;
                }

                next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
            }

            if (curr_seg < total_seg)
            {
                result = MMI_FALSE;
            }
        }
            
        #endif
            
            //end
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg
 * DESCRIPTION
 *  1. Read Message's Data, included message status, number, content and other attributes
 *     (Storage Type, SIM Card, Profile element, etc.) indicated by the flag;
 *  2. The buffer to save the content should be provided by caller.
 *  3. The Callback Action Data Structure is srv_sms_read_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  change_status   [IN]        Whether change the UNREAD Msg to READ
 *  msg_data        [IN/OUT]    Message Data For Filling back read data
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_read_msg(
                U16 msg_id,
                MMI_BOOL change_status,
                srv_sms_msg_data_struct* msg_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    srv_sms_read_cntx_struct *read_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG, msg_id, change_status, msg_data);

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id;
        srv_sms_para_enum para_flag = (srv_sms_para_enum)msg_data->para_flag;
        srv_sms_msg_info_struct msg_info; 
        EMSData *int_ems_data = NULL;
        EMSData *ems_data;
        MMI_BOOL result = MMI_TRUE;
        srv_sms_read_msg_cb_struct read_msg_cb_data;
        srv_sms_event_update_struct *event_data = NULL;
        MMI_BOOL is_update = change_status;
        srv_sms_status_enum status;
        MMI_BOOL int_result = MMI_TRUE;

        entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        if (para_flag & SRV_SMS_PARA_CONTENT_EMS)
        {
            ems_data = (EMSData*)msg_data->content_ems;
        }
        else
        {
            int_ems_data = (EMSData*)srv_sms_malloc_ems_data();
            ems_data = int_ems_data;
        }

        status = srv_sms_archive_get_msg_status(entry_id);

        if (!(status & SRV_SMS_STATUS_UNREAD))
        {
            is_update = MMI_FALSE;
        }

        if (is_update)
        {
            event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

            event_data->msg_id = msg_id;
            event_data->change_para_flag = SRV_SMS_PARA_STATUS;
            /* Get Old Msg Info */
            srv_sms_archive_get_msg_info(entry_id, &event_data->old_msg_info);
        }

        error_cause = srv_sms_archive_read_msg(entry_id, change_status, ems_data, &msg_info);

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            read_cntx = SRV_SMS_RESERVED_HANDLE;

            srv_sms_msg_info_to_msg_data(msg_data, &msg_info, ems_data);

            if (event_data)
            {
                /* Get new Msg Info */
                srv_sms_archive_get_msg_info(entry_id, &event_data->new_msg_info);
                /* Execute Message Delete Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
            }
        }
        else
        {
            result = MMI_FALSE;
        }

        if (int_ems_data != NULL)
        {
            srv_sms_free_ems_data(int_ems_data);
        }

        read_msg_cb_data.msg_data = msg_data;

        SMS_ASYNC_CALLBACK(
            SRV_SMS_ACTION_READ,
            result,
            error_cause,
            &read_msg_cb_data,
            user_data,
            callback_func);

        if (!int_result)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }

        if (event_data != NULL)
        {
            OslMfree(event_data);
        }
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        /* when exec the storage operation callback function, it will exist the MMI operating */
    #ifdef __SRV_SMS_AT_SUPPORT__
        srv_sms_enter_mmi_operating();
    #endif
    
    /*check if the sms is valid first,if not valid, delete it, and tell app to refresh,and reture false */
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            MMI_BOOL is_valid;
            
            is_valid = srv_sms_is_tcard_sms_valid(msg_id - SRV_SMS_MAX_MSG_NUM);
            if(!is_valid)
            {
                srv_sms_read_msg_cb_struct read_msg_cb_data;
                read_msg_cb_data.msg_data = msg_data;
                
                srv_sms_delete_invalid_tcard_sms(msg_id - SRV_SMS_MAX_MSG_NUM);
                
                STORAGE_ASYNC_CALLBACK(
                    SRV_SMS_ACTION_READ,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_DATA_INVALID,
                    &read_msg_cb_data,
                    user_data,
                    callback_func);
				return (SMS_HANDLE)read_cntx;
            }       
        }
    #endif
        error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_READ);

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
         #ifdef __SMS_CLOUD_SUPPORT__
            srv_sms_backup_cntx_struct *temp_backup_cntx;
         #endif
            /* Malloc Read Message Context Buffer */
            read_cntx = srv_sms_alloc_cntx(
                            sizeof(srv_sms_read_cntx_struct),
                            SRV_SMS_ACTION_READ,
                            callback_func,
                            user_data);

            /*add compile option*/
        #ifdef __SMS_CLOUD_SUPPORT__
            if(srv_sms_get_cloud_action_ctnx() == SRV_SMS_CLOUD_ACTION_BACKUP)
            {
                temp_backup_cntx = srv_sms_get_backup_ctnx();
                temp_backup_cntx->sms_hdlr = read_cntx;
            }
        #endif
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_1, read_cntx);

            if (read_cntx)
            {
               /* Init Read Message Context Buffer, fill some neccessary information */
                srv_sms_read_msg_init(
                    read_cntx,
                    msg_id,
                    change_status,
                    msg_data);

                /* Skip the invalid PDU, for the incompleted case */
                while (read_cntx->curr_index < read_cntx->total_pdu)
                {
                    pdu_id = read_cntx->pdu_id_list[read_cntx->curr_index];

                    if (pdu_id != SRV_SMS_INVALID_PDU_ID)
                    {
                        break;
                    }

                    read_cntx->curr_index++;
                }

                /* Check whether all of the PDU is read */
                if (read_cntx->curr_index < read_cntx->total_pdu)
                {
                    /* Read Next SPDU Data */
                    srv_sms_read_pdu(
                        pdu_id,
                        srv_sms_read_msg_callback,
                        read_cntx);
                }
                else
                {
                    /* It must have a valid PDU */
                    MMI_ASSERT(0);
                }
            }
            else
            {
                srv_sms_read_msg_cb_struct read_msg_cb_data;

                read_msg_cb_data.msg_data = msg_data;

                STORAGE_ASYNC_CALLBACK(
                    SRV_SMS_ACTION_READ,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_MEM_INSUFFICIENT,
                    &read_msg_cb_data,
                    user_data,
                    callback_func);
            }
        }
        else
        {
            srv_sms_read_msg_cb_struct read_msg_cb_data;

            read_msg_cb_data.msg_data = msg_data;

            STORAGE_ASYNC_CALLBACK(
                SRV_SMS_ACTION_READ,
                MMI_FALSE,
                error_cause,
                &read_msg_cb_data,
                user_data,
                callback_func);
        }
    }

    return (SMS_HANDLE)read_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_save_handle
 * DESCRIPTION
 *  Get a SMS_HANDLE For Saving or Updating Message
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_get_save_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_save_cntx_struct *save_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = srv_sms_alloc_cntx(
                    sizeof(srv_sms_save_cntx_struct),
                    SRV_SMS_ACTION_SAVE,
                    NULL,
                    NULL);

    if (save_cntx)
    {
        srv_sms_int_msg_data_struct *msg_data;

        msg_data = srv_sms_alloc_int_msg_data();

        CNTX_SET_HD_DATA(save_cntx, msg_data);
    }

    return (SMS_HANDLE)save_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg
 * DESCRIPTION
 *  1. Save a new message to SMS Storage.
 *  2. The Callers need to get a SMS save handle by API srv_sms_get_save_handle() first,
 *     then they can call the seting API (srv_sms_set_content() etc.) to set the parameters
 *     they concerned.
 *  3. If Caller specify those parameters (Status, Address, Content, SIM Card, Storage Type,
 *     Profile element, we will use them, otherwise, it will user the defaut value (If the 
 *     parameters is in the SMS setting, it will use the setting's value as defaut).
 *  4. The Callback Action Data Struct is srv_sms_save_msg_cb_struct.
 * PARAMETERS
 *  save_handle     [IN]        Save Handle
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_save_msg(
        SMS_HANDLE save_handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_save_cntx_struct *save_cntx = (srv_sms_save_cntx_struct*)save_handle;
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);
    MMI_BOOL is_init = MMI_FALSE;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	MMI_BOOL insert_tcard_flag = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This API may change to
     *      SMS_HANDLE srv_sms_save_msg(SMS_DATA sms_data, ...);
     * And need to provide a sets of SET SMS_DATA API to replace SET SMS_HANDLE API
     * ex. srv_sms_set_address(SMS_HANDLE handle, ...) need to change to 
     *     srv_sms_set_address(SMS_DATA data, ...) 
     */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG, save_handle);

#ifdef __SRV_SMS_AT_SUPPORT__
    srv_sms_enter_mmi_operating();
#endif

    do
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        //srv_sms_msg_node_struct *msg_node = &save_cntx->msg_node;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
         MMI_BOOL is_full = MMI_FALSE;
        srv_sms_tcard_msg_node_struct *tcard_msg_node = &save_cntx->tcard_msg_node;
    #endif
    #endif /* __SRV_SMS_MULTI_ADDR__ */

        U16 unused_space;

        if (storage_cntx.is_ready == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_NOT_READY;
            break;
        }
    #ifdef __SRV_SMS_AT_SUPPORT__        
        if (srv_sms_is_in_at_cmd_operating() == MMI_TRUE)
        {
            error_cause = SRV_SMS_CAUSE_AT_CONFLICT;
            break;
        }
    #endif /* __SRV_SMS_AT_SUPPORT__ */

        if (CNTX_GET_ACTION(save_cntx) != SRV_SMS_ACTION_SAVE)
        {
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
            break;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_1, error_cause);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_2, save_cntx);

        is_init = MMI_TRUE;

        CNTX_SET_CALLBACK(save_cntx, callback_func, user_data);

        /* Init Save Message Context Buffer, Convert the Input Message Data to SPDU */
        error_cause = srv_sms_save_msg_init(save_cntx);

        if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
        {
            break;
        }
        save_cntx->storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    #ifdef __SRV_SMS_MULTI_ADDR__
        /* Only ME Storage can support extension address */
        if (msg_data->ext_addr)
        {
            
			
            if (save_cntx->storage_type == SRV_SMS_STORAGE_SIM)
            {
                error_cause = SRV_SMS_CAUSE_OP_NOT_SUPPORTED;
                break;
            }
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if (save_cntx->storage_type == SRV_SMS_STORAGE_UNSPECIFIC)
            {
                
                save_cntx->storage_type = SRV_SMS_STORAGE_ME;
                //msg_node->storage_type = SRV_SMS_STORAGE_ME;
            }
        #endif
        }
	#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if (save_cntx->storage_type == SRV_SMS_STORAGE_UNSPECIFIC)
        {     
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
            srv_sms_storage_enum storage_type;
        
            storage_type = srv_sms_get_prefer_storage(save_cntx->sim_id);
            if(storage_type == SRV_SMS_STORAGE_ME)
            {
                if((memory_status->me_total - memory_status->me_used) >= save_cntx->total_pdu)
	            {
	                save_cntx->storage_type = SRV_SMS_STORAGE_ME;
                }
			    else
			    {
			        if(storage_cntx.is_tsms_ready)
			        {
		                if((memory_status->tcard_total - memory_status->tcard_used) >= save_cntx->total_pdu)
	                    {
	                        srv_sms_event_for_memory_status_struct mem_status;
	                        save_cntx->storage_type = SRV_SMS_STORAGE_TCARD; 
							mem_status.is_tcard_avail = MMI_TRUE;
							mem_status.pref_storage_type = storage_type;
							mem_status.is_phone_full = MMI_TRUE;
							mem_status.is_tcard_full = MMI_FALSE;
							mem_status.save_to_type = SRV_SMS_STORAGE_TCARD;

							srv_sms_emit_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS,&mem_status);
							//add phone full and save to tcard
	                    }
	                    else
	                    {		                        
							is_full = MMI_TRUE;
							
							//add memory full event,
	                    }
			        }
					else
					{
					    is_full = MMI_TRUE;
						
					}
				    
			    }  
                 
            }
            else
            {
                if (storage_type == SRV_SMS_STORAGE_TCARD)
                {
                    if(storage_cntx.is_tsms_ready)
                    {
                        if((memory_status->tcard_total - memory_status->tcard_used) >= save_cntx->total_pdu)
	                    {
	                        save_cntx->storage_type = SRV_SMS_STORAGE_TCARD; 
	                    }
	                    else
	                    {
	                        if((memory_status->me_total - memory_status->me_used) >= save_cntx->total_pdu)
	                        {
		                        srv_sms_event_for_memory_status_struct mem_status;

								save_cntx->storage_type = SRV_SMS_STORAGE_ME;
								
								mem_status.is_tcard_avail = MMI_TRUE;
								mem_status.pref_storage_type = storage_type;
								mem_status.is_phone_full = MMI_FALSE;
								mem_status.is_tcard_full = MMI_TRUE;
								mem_status.save_to_type = SRV_SMS_STORAGE_ME;
								srv_sms_emit_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS,&mem_status);
								//add tcard full and save to phone.
	                        }
							else
							{
							    is_full = MMI_TRUE;
								
								//add memory full event
							}
	                        
	                    } 
                    }
					else
					{
					    if((memory_status->me_total - memory_status->me_used) >= save_cntx->total_pdu)
					    {
					        srv_sms_event_for_memory_status_struct mem_status;
							
					        save_cntx->storage_type = SRV_SMS_STORAGE_ME; 

							mem_status.is_tcard_avail = MMI_FALSE;
							mem_status.pref_storage_type = storage_type;
							mem_status.is_phone_full = MMI_FALSE;
							mem_status.is_tcard_full = MMI_TRUE;
							mem_status.save_to_type = SRV_SMS_STORAGE_ME;
							srv_sms_emit_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS,&mem_status);
						    //add tcard remove,and save to phone.
					    }
						else
						{
						    insert_tcard_flag = MMI_TRUE;
						    is_full = MMI_TRUE;
							//add insert tcard
						}
						
					}
                    
                }
            }
        }	
	    if(is_full)
        {
            if(insert_tcard_flag)
            {
                error_cause = SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE;
            }
	    else
	    {
	        error_cause = SRV_SMS_CAUSE_MEM_FULL;
	    }
			
            break;   
        }
	#endif
    #else
        //send sms and save
        {
            MMI_BOOL is_full = MMI_FALSE;
            U16 total_num;
            U16 used_num;
            U32 index;
            srv_sms_storage_enum storage_type;
            
            sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
            index = srv_sms_sim_id_to_sim_index(save_cntx->sim_id);
            
            save_cntx->storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
            
            storage_type = srv_sms_get_prefer_storage(save_cntx->sim_id);
            if(storage_type == SRV_SMS_STORAGE_ME)
            {
                if((memory_status->me_total - memory_status->me_used) >= save_cntx->total_pdu)
            {
                save_cntx->storage_type = SRV_SMS_STORAGE_ME;
            }
                else
                {
                    total_num = memory_status->me_total + memory_status->sim_total[index];
                    used_num = memory_status->me_used + memory_status->sim_used[index];
                    if((total_num - used_num) <= save_cntx->total_pdu)
                    {
               #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                        if((memory_status->tcard_total - memory_status->tcard_used) > save_cntx->total_pdu)
                        {
                            save_cntx->storage_type = SRV_SMS_STORAGE_TCARD; 
                        }
                        else
                        {
                            is_full = MMI_TRUE;
                        }
               #endif
                    }
                }
                 
            }
            else
            {
                if(storage_type == SRV_SMS_STORAGE_SIM)
                {
                    if((memory_status->sim_total[index] - memory_status->sim_used[index]) >= save_cntx->total_pdu)
                    {
                        save_cntx->storage_type = SRV_SMS_STORAGE_SIM;     
                    }
                    else
                    {
                        total_num = memory_status->me_total + memory_status->sim_total[index];
                        used_num = memory_status->me_used + memory_status->sim_used[index];
                        if((total_num - used_num) <= save_cntx->total_pdu)
                        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                            if((memory_status->tcard_total - memory_status->tcard_used) > save_cntx->total_pdu)
                            {
                                save_cntx->storage_type = SRV_SMS_STORAGE_TCARD; 
                            }
            else
            {
                                is_full = MMI_TRUE;
                            }
                   #endif
                        }
                    }
                }
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                else
                {
                    if((memory_status->tcard_total - memory_status->tcard_used) >= save_cntx->total_pdu)
                    {
                        save_cntx->storage_type = SRV_SMS_STORAGE_TCARD;
                    }
                    else
                    {
                        total_num = memory_status->me_total + memory_status->sim_total[index];
                        used_num = memory_status->me_used + memory_status->sim_used[index];
                        if((total_num - used_num) <= save_cntx->total_pdu)
                        {
                            is_full = MMI_TRUE;
                    }
                }
            }
        #endif
        }
            if(is_full)
            {
                unused_space = srv_sms_get_unused_space(save_cntx->storage_type, save_cntx->sim_id);
                if (unused_space > 0)
                {
                    error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                }
                else
                {
                    error_cause = SRV_SMS_CAUSE_MEM_FULL;
                }
                break;   
            }
        }                        
    #endif /* __SRV_SMS_MULTI_ADDR__ */

        /* Get the unused Space */
        unused_space = srv_sms_get_unused_space(save_cntx->storage_type, save_cntx->sim_id);

        /* Check whether there is enough space to save this message or not */
        if (srv_sms_is_enough_unused_space(&(save_cntx->storage_type), save_cntx->sim_id, save_cntx->total_pdu))
        {
        
            /* Save Extension Address First */
            //MMI_BOOL is_tcard = MMI_FALSE;
        #ifdef __SRV_SMS_MULTI_ADDR__
            srv_sms_msg_node_struct *msg_node = &save_cntx->msg_node;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		    if(save_cntx->storage_type == SRV_SMS_STORAGE_TCARD)
		    {
		        error_cause = srv_sms_save_tcard_ext_addr(
                                msg_data->ext_addr,
                                &msg_node->start_addr_id,
                                &msg_node->ext_addr_num);
		    }
			else
			{
			    error_cause = srv_sms_save_ext_addr(
                            msg_data->ext_addr,
                            &msg_node->start_addr_id,
                            &msg_node->ext_addr_num);
			}
            

        #else
            error_cause = srv_sms_save_ext_addr(
                            msg_data->ext_addr,
                            &msg_node->start_addr_id,
                            &msg_node->ext_addr_num);
        #endif
            if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        #endif /* __SRV_SMS_MULTI_ADDR__ */
            {
                srv_sms_save_msg_curr_pdu(save_cntx);
            }
        }
        else /* The remaining space is not enough */
        {
            if (unused_space > 0)
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
            }
            else
            {
                error_cause = SRV_SMS_CAUSE_MEM_FULL;
            }
        }
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        if (is_init)
        {
            srv_sms_save_msg_deinit(save_cntx);
        }
        else
        {
            srv_sms_free_int_msg_data(msg_data);
        }

        srv_sms_free_cntx(save_cntx);

        STORAGE_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_SAVE,
            error_cause,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_update_handle
 * DESCRIPTION
 *  Get a SMS_HANDLE For Updating Message
 * PARAMETERS
 *  void
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_get_update_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_cntx_struct *update_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = srv_sms_alloc_cntx(
                    sizeof(srv_sms_update_cntx_struct),
                    SRV_SMS_ACTION_UPDATE,
                    NULL,
                    NULL);

    if (update_cntx)
    {
        srv_sms_int_msg_data_struct *msg_data;

        msg_data = srv_sms_alloc_int_msg_data();

        CNTX_SET_HD_DATA(update_cntx, msg_data);
    }

    return (SMS_HANDLE)update_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg
 * DESCRIPTION
 *  1. Update a existed message to the new message
 *  2. The usage of this API is similiar with srv_sms_save_msg();
 *  3. This API is not supported in this stage.
 *  4. The Callback Action Data Structure is srv_sms_update_msg_cb_struct;
 *  5. This API is not implemented in the current version.
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  save_handle     [IN]        Save Handle
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_update_msg(
        U16 msg_id,
        SMS_HANDLE update_handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_cntx_struct *update_cntx = (srv_sms_update_cntx_struct*)update_handle;
    srv_sms_int_msg_data_struct *msg_data;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_AT_SUPPORT__
    srv_sms_enter_mmi_operating();
#endif

    msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM && !storage_cntx.is_tsms_ready)
    {
        srv_sms_free_int_msg_data(msg_data);
        srv_sms_free_cntx(update_cntx);

        STORAGE_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_UPDATE,
            SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE,
            user_data,
            callback_func);
        return;
    }
#endif
    

    error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_UPDATE);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (srv_sms_update_msg_check_data(msg_id, msg_data))
        {
            CNTX_SET_CALLBACK(update_cntx, callback_func, user_data);

            srv_sms_update_msg_init(
                update_cntx,
                msg_id);

            srv_sms_update_msg_next(update_cntx);
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
        }
    }
    
    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_free_int_msg_data(msg_data);
        srv_sms_free_cntx(update_cntx);

        STORAGE_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_UPDATE,
            error_cause,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg
 * DESCRIPTION
 *  1. Delete an existed message;
 *  2. If the message is not existed, the result is FALSE;
 *  3. The Callback Action Data Structure is srv_sms_delete_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_delete_msg(
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE delete_hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG, msg_id);

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id;
        srv_sms_delete_archive_cntx_struct *delete_cntx;

        delete_cntx = srv_sms_alloc_cntx(
                        sizeof(srv_sms_delete_archive_cntx_struct),
                        SRV_SMS_ACTION_DELETE,
                        callback_func,
                        user_data);

        delete_hd = (SMS_HANDLE)delete_cntx;

        if (delete_cntx)
        {
            MMI_BOOL result;
            srv_sms_cause_enum error_cause;

            /* Get the Event Data For Delete Event */
            delete_cntx->event_data = OslMalloc(sizeof(srv_sms_event_delete_struct));

            entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

            delete_cntx->event_data->msg_id = msg_id;
            srv_sms_archive_get_msg_info(entry_id, &delete_cntx->event_data->msg_info);

            error_cause = srv_sms_archive_delete_msg(entry_id);

            if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }


            srv_sms_async_callback(
                SRV_SMS_ACTION_DELETE,
                result,
                error_cause,
                NULL,
                0,
                delete_cntx,
                srv_sms_delete_archive_msg_callback);
        }
        else
        {
            srv_sms_async_callback(
                SRV_SMS_ACTION_DELETE,
                MMI_FALSE,
                SRV_SMS_CAUSE_MEM_INSUFFICIENT,
                NULL,
                0,
                user_data,
                callback_func);
        }
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        delete_hd = srv_sms_delete_msg_ext(
                        msg_id,
                        MMI_FALSE,
                        callback_func,
                        user_data);
    }

    return delete_hd;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_bg
 * DESCRIPTION
 *  1. Delete an existed message in background;
 *  2. If the message is not existed, the result is FALSE;
 *  3. The Callback Action Data Structure is srv_sms_delete_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_delete_msg_bg(
            U16 msg_id,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_delete_msg_ext(
                msg_id,
                MMI_TRUE,
                callback_func,
                user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_bitmap
 * DESCRIPTION
 *  1. Delete the messages indicated by the msg_bitmap;
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_bitmap_cb_struct;
 * PARAMETERS
 *  msg_bitmap      [IN]        The bitmap of the Message IDs
 *  byte_size       [IN]        The byte number of the msg_bitmap
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_delete_msg_bitmap(
                U8 msg_bitmap[],
                U16 bitmap_size,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_bitmap_cntx_struct *del_bitmap_cntx = NULL;
    U16 curr_msg_id = SRV_SMS_INVALID_BITMAP_INDEX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_BITMAP, msg_bitmap, bitmap_size);

    if ((msg_bitmap != NULL) && (bitmap_size > 0))
    {
        curr_msg_id = srv_sms_get_bitmap_index(0, msg_bitmap, bitmap_size);
    }

    if (curr_msg_id != SRV_SMS_INVALID_BITMAP_INDEX)
    {
        del_bitmap_cntx = srv_sms_alloc_cntx(
                            (sizeof(srv_sms_delete_bitmap_cntx_struct) + bitmap_size),
                            SRV_SMS_ACTION_DELETE,
                            callback_func,
                            user_data);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_BITMAP_1, del_bitmap_cntx);

        if (del_bitmap_cntx)
        {
            del_bitmap_cntx->msg_bitmap = (U8*)del_bitmap_cntx + sizeof(srv_sms_delete_bitmap_cntx_struct);

            memcpy(del_bitmap_cntx->msg_bitmap, msg_bitmap, bitmap_size);

            del_bitmap_cntx->bitmap_size = bitmap_size;
            del_bitmap_cntx->curr_msg_id = curr_msg_id;
            del_bitmap_cntx->deleted_num = 0;
            del_bitmap_cntx->callback_func = callback_func;
            del_bitmap_cntx->user_data = user_data;

            del_bitmap_cntx->deleted_msg_bitmap = OslMalloc(bitmap_size);
            memset(del_bitmap_cntx->deleted_msg_bitmap, 0, bitmap_size);

            srv_sms_delete_msg(
                curr_msg_id,
                srv_sms_delete_msg_bitmap_callback,
                del_bitmap_cntx);
        }
        else
        {
            SMS_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_DELETE,
                SRV_SMS_CAUSE_MEM_INSUFFICIENT,
                user_data,
                callback_func);
        }
    }
    else
    {
        srv_sms_delete_msg_bitmap_cb_struct del_bitmap_cb_data;

        del_bitmap_cb_data.deleted_num = 0;
        del_bitmap_cb_data.bitmap_size = 0;
        del_bitmap_cb_data.deleted_msg_bitmap = NULL;

        SMS_ASYNC_SUCC_CALLBACK(
            SRV_SMS_ACTION_DELETE,
            &del_bitmap_cb_data,
            user_data,
            callback_func);
    }

    return del_bitmap_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg
 * DESCRIPTION
 *  1. Copy a existed message to the destination storage;
 *  2. The Callback Action Data Structure is srv_sms_copy_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  dest_storage    [IN]        Destination storage
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_copy_msg(
            U16 msg_id,
            srv_sms_storage_enum dest_storage,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum dest_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_sim_id = srv_sms_get_msg_sim_id(msg_id);

    return srv_sms_copy_msg_int(
            msg_id,
            SRV_SMS_ACTION_COPY,
            dest_storage,
            dest_sim_id,
            callback_func,
            user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
SMS_HANDLE srv_sms_copy_msg_ext(
                U16 msg_id,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_copy_msg_int(
                msg_id,
                SRV_SMS_ACTION_COPY,
                dest_storage,
                sim_id,
                callback_func,
                user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg
 * DESCRIPTION
 *  1. Move a existed message to the destination storage, the original message 
 *     will be deleted after moved successfully;
 *  2. The Callback Action Data Structure is srv_sms_move_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  dest_storage    [IN]        Destination storage
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_move_msg(
            U16 msg_id,
            srv_sms_storage_enum dest_storage,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum dest_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_sim_id = srv_sms_get_msg_sim_id(msg_id);

    return srv_sms_copy_msg_int(
            msg_id,
            SRV_SMS_ACTION_MOVE,
            dest_storage,
            dest_sim_id,
            callback_func,
            user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_msg_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
SMS_HANDLE srv_sms_move_msg_ext(
                U16 msg_id,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_copy_msg_int(
                msg_id,
                SRV_SMS_ACTION_MOVE,
                dest_storage,
                sim_id,
                callback_func,
                user_data);
}




/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_msg_status
 * DESCRIPTION
 *  1. Change message's status;
 *  2. The Callback Action Data Structure is srv_sms_change_msg_status_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  status          [IN]        Destination Status
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_change_msg_status(
                U16 msg_id,
                srv_sms_status_enum status,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_change_status_cntx_struct *change_cntx = NULL;
    srv_sms_cause_enum error_cause;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS, msg_id, status);

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        srv_sms_change_msg_status_cb_struct change_status_cb_data;
        U16 entry_id;
        MMI_BOOL result = MMI_TRUE;
        srv_sms_event_update_struct *event_data;
        MMI_BOOL int_result = MMI_TRUE;

        entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

        /* Get Old Msg Info */
        srv_sms_archive_get_msg_info(entry_id, &event_data->old_msg_info);

        error_cause = srv_sms_archive_change_msg_status(entry_id, status);

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            change_cntx = SRV_SMS_RESERVED_HANDLE;

            /* Set Event Data For Message Change */
            event_data->msg_id = msg_id;
            event_data->change_para_flag = SRV_SMS_PARA_STATUS;;
            srv_sms_archive_get_msg_info(entry_id, &event_data->new_msg_info);

            /* Exec Message Update Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }
        else
        {
            result = MMI_FALSE;
        }

        SMS_ASYNC_CALLBACK(
            SRV_SMS_ACTION_CHANGE_STATUS,
            result,
            error_cause,
            &change_status_cb_data,
            user_data,
            callback_func);

        if (int_result == MMI_FALSE)
        {
            /* Emit Update Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }

        OslMfree(event_data);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    {
    #ifdef __SRV_SMS_AT_SUPPORT__
        srv_sms_enter_mmi_operating();
    #endif

        error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_CHANGE_STATUS);

        do
        {
            srv_sms_status_enum msg_status;
            srv_sms_mti_enum mti;
            srv_sms_mti_enum msg_mti;

            if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
            {
                break;
            }

            msg_status = srv_sms_get_msg_status(msg_id);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS_1, msg_status);

            if (status == msg_status)
            {
                result = MMI_TRUE;
                break;
            }

            mti = srv_sms_status_to_mti(status);
            msg_mti = srv_sms_status_to_mti(msg_status);

            if (mti != msg_mti)
            {
                error_cause = SRV_SMS_CAUSE_OP_NOT_ALLOWED;
                break;
            }

            change_cntx = srv_sms_alloc_cntx(
                            sizeof(srv_sms_change_status_cntx_struct),
                            SRV_SMS_ACTION_CHANGE_STATUS,
                            callback_func,
                            user_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS_2, change_cntx);

            if (change_cntx == NULL)
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                break;
            }

            srv_sms_change_msg_status_init(
                change_cntx,
                msg_id,
                status);

            srv_sms_read_pdu(
                change_cntx->pdu_id_list[change_cntx->curr_index],
                srv_sms_change_status_callback,
                change_cntx);
        } while (0);

        if (result || (error_cause != SRV_SMS_CAUSE_NO_ERROR))
        {
            srv_sms_change_msg_status_cb_struct change_status_cb_data;

            change_cntx = SRV_SMS_RESERVED_HANDLE;

            STORAGE_ASYNC_CALLBACK(
                SRV_SMS_ACTION_CHANGE_STATUS,
                result,
                error_cause,
                &change_status_cb_data,
                user_data,
                callback_func);
        }
        
    }
#else
    if (msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        if(storage_cntx.is_tsms_ready)
        {
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            srv_sms_event_update_struct *event_data;
            MMI_BOOL int_result;
            srv_sms_change_msg_status_cb_struct change_status_cb_data;
            srv_tcard_op_struct read_cntx;

            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            event_data = OslMalloc(sizeof(srv_sms_event_update_struct));
            srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);
            
            tcard_msg_node->status = (tcard_msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) |  status;

            

            read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
            read_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            srv_sms_unhide_tcard_msg_node(msg_id);
            srv_tcard_sync_write_record(&read_cntx, (char*)tcard_msg_node);
            
            event_data->msg_id = msg_id;
            event_data->change_para_flag = SRV_SMS_PARA_STATUS;;
            srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);
           
            /* Exec Message Update Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);

            if (int_result == MMI_FALSE)
            {
                /* Emit Update Event */
                srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
            }
            
            result = MMI_TRUE;
            SRV_SMS_POST_CALLBACK(
                SRV_SMS_ACTION_CHANGE_STATUS,
                result,
                0,
                NULL,
                user_data,
                callback_func);
            OslMfree(event_data);
        }
        else
        {
            action_cntx.is_in_change = MMI_TRUE;
            action_cntx.msg_id = msg_id;
            action_cntx.status = status;
            SRV_SMS_POST_CALLBACK(
                SRV_SMS_ACTION_CHANGE_STATUS,
                result,
                0,
                NULL,
                user_data,
                callback_func);
        }
        

        
    }
    else
    {
    {
    #ifdef __SRV_SMS_AT_SUPPORT__
        srv_sms_enter_mmi_operating();
    #endif

        error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_CHANGE_STATUS);

        do
        {
            srv_sms_status_enum msg_status;
            srv_sms_mti_enum mti;
            srv_sms_mti_enum msg_mti;

            if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
            {
                break;
            }

            msg_status = srv_sms_get_msg_status(msg_id);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS_1, msg_status);

            if (status == msg_status)
            {
                result = MMI_TRUE;
                break;
            }

            mti = srv_sms_status_to_mti(status);
            msg_mti = srv_sms_status_to_mti(msg_status);

            if (mti != msg_mti)
            {
                error_cause = SRV_SMS_CAUSE_OP_NOT_ALLOWED;
                break;
            }

            change_cntx = srv_sms_alloc_cntx(
                            sizeof(srv_sms_change_status_cntx_struct),
                            SRV_SMS_ACTION_CHANGE_STATUS,
                            callback_func,
                            user_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS_2, change_cntx);

            if (change_cntx == NULL)
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                break;
            }

            srv_sms_change_msg_status_init(
                change_cntx,
                msg_id,
                status);

            srv_sms_read_pdu(
                change_cntx->pdu_id_list[change_cntx->curr_index],
                srv_sms_change_status_callback,
                change_cntx);
        } while (0);

        if (result || (error_cause != SRV_SMS_CAUSE_NO_ERROR))
        {
            srv_sms_change_msg_status_cb_struct change_status_cb_data;

            change_cntx = SRV_SMS_RESERVED_HANDLE;

            STORAGE_ASYNC_CALLBACK(
                SRV_SMS_ACTION_CHANGE_STATUS,
                result,
                error_cause,
                &change_status_cb_data,
                user_data,
                callback_func);
        }
        
    }
    }
#endif

    return (SMS_HANDLE)change_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_memory_status
 * DESCRIPTION
 *  Get SMS Memory status, if the sms is not ready, the result will be FALSE.
 * PARAMETERS
 *  status_data     [IN/OUT]    Memory Status Data Buffer
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_get_memory_status(srv_sms_sim_enum sim_id, srv_sms_memory_status_struct *status_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MEMORY_STATUS, storage_cntx.is_ready);

    sim_index = srv_sms_sim_id_to_sim_index(sim_id);
    
    if (storage_cntx.is_ready == MMI_TRUE)
    {
        sms_memory_status_struct *int_mem_status = &storage_cntx.memory_status;
        
        status_data->me_total = int_mem_status->me_total;
        status_data->me_used = int_mem_status->me_used;

        status_data->sim_total = int_mem_status->sim_total[sim_index];
        status_data->sim_used = int_mem_status->sim_used[sim_index];

    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        status_data->tcard_total = int_mem_status->tcard_total;
        status_data->tcard_used = int_mem_status->tcard_used;
    #endif

        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg_int
 * DESCRIPTION
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_query_msg_int(
        srv_sms_query_struct *query_data,
        U16* msg_list,
        U16 list_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U32 i;
    U32 query_flag = 0x01;
    U16 *query_msg_list = msg_list;
    U16 max_msg_num = list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG, query_data, query_data->query_flag);

#ifdef __SRV_SMS_ARCHIVE__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_1, query_data->folder_id);

    if (query_data->folder_id == SRV_SMS_FOLDER_ARCHIVE)
    {
        if (max_msg_num > SRV_SMS_MAX_ARCH_ENTRY)
        {
            max_msg_num = SRV_SMS_MAX_ARCH_ENTRY;
        }

        /* Get Valid Message */
        for (i = 0; i < max_msg_num; i++)
        {
            if (srv_sms_archive_is_msg_valid(i))
            {
                query_msg_list[count++] = srv_sms_archive_entry_id_to_msg_id(i);
            }
        }

        /* Query Other attribute */
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (storage_cntx.total_msg_num > 0)
        {
            if (max_msg_num > SRV_SMS_MAX_SMS_ENTRY)
            {
                max_msg_num = SRV_SMS_MAX_SMS_ENTRY;
            }

            /* Get Valid Message */
            for (i = 0; i < (U32)(storage_cntx.used_msg_tail_id + 1); i++)
            {
                if (srv_sms_is_msg_valid(i) && (count < max_msg_num))
                {
                    
                    query_msg_list[count++] = i;
                }
            }

            while ((count > 0) && (query_flag < SRV_SMS_QUERY_RESERVED))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_2, count, query_flag);

                if (query_data->query_flag & query_flag)
                {
                    srv_sms_query_msg_attribute(
                        query_msg_list,
                        &count,
                        (srv_sms_query_enum)query_flag,
                        query_data);
                }

                query_flag <<= 1;
            }

        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_2, count);

    if (count > 0)
    {
        srv_sms_sort_msg(
            query_msg_list,
            count,
            query_data->sort_flag,
            query_data->order_flag);
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg
 * DESCRIPTION
 *  1. Query the messages with some properties.
 *  2. The caller can set the query_flag, and the corresponding paramenters of
 *     the propertied they wanted. The folder ID is mandatory in the current version;
 *  3. The caller also can specify the sort flag, in the current version, we only 
 *     support sorting by timestamp.
 *  4. The Callback Action Data Structure is srv_sms_query_msg_cb_struct;
 * PARAMETERS
 *  query_data      [IN]        Query Data
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_query_msg(
        srv_sms_query_struct *query_data,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_query_msg_cb_struct query_cb_data;
    U16 *query_msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query_msg_list = srv_sms_malloc_query_msg_list(SRV_SMS_QUERY_LIST_SIZE);

    query_cb_data.msg_num = srv_sms_query_msg_int(
                                query_data,
                                query_msg_list,
                                SRV_SMS_QUERY_LIST_SIZE);

    query_cb_data.msg_id_list = query_msg_list;

    /* Must use sync callback, because the queried list is released after callback */
    srv_sms_succ_callback(
        SRV_SMS_ACTION_QUERY,
        &query_cb_data,
        user_data,
        callback_func);

    srv_sms_free_query_msg_list(query_msg_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg
 * DESCRIPTION
 *  1. Sort the messages list.
 *  2. In the current version, we only support sorting by timestamp.
 * PARAMETERS
 *  msg_id_array    :   [IN]        Message ID Array
 *  msg_num         :   [IN]        Message Number
 *  sort_flag       :   [IN]        Sorting Type Flag
 *  order_flag      :   [IN]        Ordering Flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_sort_msg(
        U16 *msg_id_array,
        U16 msg_num,
        srv_sms_sort_enum sort_flag,
        srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SORT_MSG, msg_num, sort_flag, order_flag);

    switch (sort_flag)
    {
        case SRV_SMS_SORT_TIMESTAMP:
            srv_sms_sort_msg_timestamp(msg_id_array, msg_num, order_flag);
            break;

        case SRV_SMS_SORT_NONE:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_asc_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
const char* srv_sms_get_msg_asc_address(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        address = srv_sms_archive_get_msg_address(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                address = tcard_msg_node->number;
            }
            else
            {
            address = srv_sms_msg_list[msg_id].number;
        }
        #else
            address = srv_sms_msg_list[msg_id].number;
        #endif  
        }
        else
        {
            address = NULL;
        }
    }

    return address;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_address
 * DESCRIPTION
 *  Get Message's Address (ASCII Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
void srv_sms_get_msg_address(U16 msg_id, char* ucs2_addr_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *asc_address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asc_address = srv_sms_get_msg_asc_address(msg_id);

    if (asc_address != NULL)
    {    
        mmi_asc_to_ucs2(ucs2_addr_buff, (S8*)asc_address);
    }
    else
    {
        ucs2_addr_buff[0] = '\0';
        ucs2_addr_buff[1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_multi_addr_num
 * DESCRIPTION
 *  Get Message's mutli Address's number
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_msg_addr_num(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id))
    {
        count = 1;
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id))
        {
        #ifdef __SRV_SMS_MULTI_ADDR__

		#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
		    {
		        srv_sms_tcard_msg_node_struct *tcard_msg_node;
				tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
			    
		        count = tcard_msg_node->ext_addr_num + 1;
		    }
			else
			{
			    count = srv_sms_msg_list[msg_id].ext_addr_num + 1;
			}
		#else
		    count = srv_sms_msg_list[msg_id].ext_addr_num + 1;
		#endif
            
        #else /* __SRV_SMS_MSG_INFO_CONTENT__ */
            count = 1;
        #endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
        }
    }

    return count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_multi_addr
 * DESCRIPTION
 *  Get Message's Address
 * PARAMETERS
 *  addr_buff       :   [IN]        ucs2 address buffer
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
void srv_sms_get_msg_multi_addr(
                WCHAR* addr_buff,
                srv_sms_status_enum* status,
                U16 msg_id,
                U16 addr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    count = srv_sms_get_msg_addr_num(msg_id);
#else /* __SRV_SMS_MULTI_ADDR__ */
    count = 1;
#endif /* __SRV_SMS_MULTI_ADDR__ */

    if (addr_index < count)
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
	#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		if (addr_index > 0)
        {
            U32 i;
            srv_sms_addr_node_struct *addr_node = NULL;
            U16 next_addr_id = srv_sms_msg_list[msg_id].start_addr_id;

            for (i = 0; i < addr_index; i++)
            {
                MMI_ASSERT(next_addr_id < SRV_SMS_MAX_ADDR_ENTRY);
                addr_node = &srv_sms_addr_list[next_addr_id];
                next_addr_id = addr_node->next_addr_id;
            }

            mmi_asc_to_wcs(addr_buff, (CHAR*)addr_node->address);
            *status = (srv_sms_status_enum)addr_node->status;
        }
	#else   
	    if (addr_index > 0)
        {
            if (msg_id >= SRV_SMS_MAX_MSG_NUM)
	    	{
	            U32 i;
	            srv_sms_tcard_addr_node_struct *addr_node = NULL;
				srv_sms_tcard_msg_node_struct *tcard_msg_list;
				U16 next_addr_id;

				tcard_msg_list = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
	            next_addr_id = tcard_msg_list->start_addr_id;

	            for (i = 0; i < addr_index; i++)
	            {
	                MMI_ASSERT(next_addr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);
	                addr_node = &srv_sms_tcard_addr_list[next_addr_id - SRV_SMS_MAX_ADDR_ENTRY];
	                next_addr_id = addr_node->next_addr_id;
	            }

	            mmi_asc_to_wcs(addr_buff, (CHAR*)addr_node->address);
	            *status = (srv_sms_status_enum)addr_node->status;
        	}
			else
			{
			    U32 i;
	            srv_sms_addr_node_struct *addr_node = NULL;
	            U16 next_addr_id = srv_sms_msg_list[msg_id].start_addr_id;

	            for (i = 0; i < addr_index; i++)
	            {
	                MMI_ASSERT(next_addr_id < SRV_SMS_MAX_ADDR_ENTRY);
	                addr_node = &srv_sms_addr_list[next_addr_id];
	                next_addr_id = addr_node->next_addr_id;
	            }

	            mmi_asc_to_wcs(addr_buff, (CHAR*)addr_node->address);
	            *status = (srv_sms_status_enum)addr_node->status;
			}
        }
	#endif       
        else
    #endif /* __SRV_SMS_MULTI_ADDR__ */
        {
            srv_sms_get_msg_address(msg_id, (S8*)addr_buff);

        #ifdef __SRV_SMS_ARCHIVE__
            if (srv_sms_is_archive_msg(msg_id))
            {
                U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
            
                *status = srv_sms_archive_get_msg_status(entry_id);
            }
            else
        #endif /* __SRV_SMS_ARCHIVE__ */
            {
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		        MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

                *status = (srv_sms_status_enum)srv_sms_msg_list[msg_id].status;
		#else
		        if (msg_id >= SRV_SMS_MAX_SMS_ENTRY)
	        	{
	        	    srv_sms_tcard_msg_node_struct *tcard_msg_list;
				    tcard_msg_list = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
					*status = (srv_sms_status_enum)tcard_msg_list->status;
	        	}
				else
				{
				    *status = (srv_sms_status_enum)srv_sms_msg_list[msg_id].status;
				}
		#endif
                
            }
        }
    }
    else
    {
        addr_buff[0] = '\0';
        *status = SRV_SMS_STATUS_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content
 * DESCRIPTION
 *  Get Message's Content For List Display.
 *  This API only for SMS application Internal Using
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  S8*
 *****************************************************************************/
const char* srv_sms_get_msg_content(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        content = srv_sms_archive_get_msg_content(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                content = (S8*)tcard_msg_node->content;
            }
            else
            {
            content = (S8*)srv_sms_msg_list[msg_id].content;
        }
        #else
            content = (S8*)srv_sms_msg_list[msg_id].content;
        #endif    
        }
        else
        {
            content = NULL;
        }
    }
#else /* __SRV_SMS_MSG_INFO_CONTENT__ */
    content = NULL;
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    return content;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content_async
 * DESCRIPTION
 *  1. Get Message's Content (For List display) async(The Content is returned in
 *     the callback function).
 *  2. This API is only for This API only for SMS application Internal Using.
 *  3. The Callback Action Data Structure is srv_sms_get_msg_content_async_cb_struct.
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_get_msg_content_async(
            U16 msg_id,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_get_content_cntx_struct *get_content_cntx = NULL;
    srv_sms_get_msg_content_async_cb_struct get_content_cb_data;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_ASYNC, msg_id);

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id;
        EMSData *ems_data;
        MMI_BOOL result;

        entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        ems_data = (EMSData*)srv_sms_malloc_ems_data();

        MMI_ASSERT(ems_data != NULL);

        error_cause = srv_sms_archive_read_msg(entry_id, MMI_FALSE, ems_data, NULL);

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
        #ifdef __EMS_NON_STD_7BIT_CHAR__
            if ((ems_data->dcs == SRV_SMS_DCS_7BIT) || (ems_data->dcs == SRV_SMS_DCS_UCS2))
        #else /* __EMS_NON_STD_7BIT_CHAR__ */
            if (ems_data->dcs == SRV_SMS_DCS_7BIT)
        #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
            {
                srv_sms_remove_escape_char_ext(
                    get_content_cb_data.content,
                    (S8*)ems_data->textBuffer,
                    SRV_SMS_MSG_INFO_CONTENT_LEN,
                    (U16)(ems_data->textLength / ENCODING_LENGTH));
            }
            else
            {
                mmi_ucs2ncpy(get_content_cb_data.content, (S8*)ems_data->textBuffer, SRV_SMS_MSG_INFO_CONTENT_LEN);
                get_content_cb_data.content[SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH] = '\0';
                get_content_cb_data.content[SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH + 1] = '\0';
            }

            get_content_cntx = SRV_SMS_RESERVED_HANDLE;
            result = MMI_TRUE;
        }
        else
        {
            get_content_cb_data.content[0] = '\0';
            get_content_cb_data.content[1] = '\0';

            result = MMI_FALSE;
        }

        srv_sms_free_ems_data(ems_data);

        SMS_ASYNC_CALLBACK(
            SRV_SMS_ACTION_GET_CONTENT,
            result,
            error_cause,
            &get_content_cb_data,
            user_data,
            callback_func);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        error_cause = srv_sms_check_common_msg_error_without_at(msg_id, SRV_SMS_ACTION_READ);

        do
        {
            if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
            {
                break;
            }
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            get_content_cntx = srv_sms_alloc_cntx(
                                    sizeof(srv_sms_get_content_cntx_struct),
                                    SRV_SMS_ACTION_GET_CONTENT,
                                    callback_func,
                                    user_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_ASYNC, get_content_cntx);

            if (get_content_cntx == NULL)
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                break;
            }

            srv_sms_get_msg_content_init(
                get_content_cntx,
                msg_id);

            /* Read First PDU's Data */
            srv_sms_read_pdu(
                get_content_cntx->pdu_id_list[get_content_cntx->curr_index],
                srv_sms_get_msg_content_callback,
                get_content_cntx);
        #else
            if (msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);

                if(SRV_SMS_MSG_INFO_CONTENT_LEN >= SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN)
                {
                    memcpy(get_content_cb_data.content,tcard_msg_node->content,SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH);
                    get_content_cb_data.content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH] = '\0';
                    get_content_cb_data.content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH +1] = '\0';
                }
                else
                {
                    memcpy(get_content_cb_data.content,tcard_msg_node->content,SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH);
                    get_content_cb_data.content[SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH] = '\0';
                    get_content_cb_data.content[SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH +1] = '\0';
                }

                /* The Message is not existed, exec the callback function with FALSE result */
                SMS_ASYNC_CALLBACK(
                    SRV_SMS_ACTION_GET_CONTENT,
                    MMI_TRUE,
                    error_cause,
                    &get_content_cb_data,
                    user_data,
                    callback_func);
            }
            else
            {
            get_content_cntx = srv_sms_alloc_cntx(
                                    sizeof(srv_sms_get_content_cntx_struct),
                                    SRV_SMS_ACTION_GET_CONTENT,
                                    callback_func,
                                    user_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_ASYNC, get_content_cntx);

            if (get_content_cntx == NULL)
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                break;
            }

            srv_sms_get_msg_content_init(
                get_content_cntx,
                msg_id);

            /* Read First PDU's Data */
            srv_sms_read_pdu(
                get_content_cntx->pdu_id_list[get_content_cntx->curr_index],
                srv_sms_get_msg_content_callback,
                get_content_cntx);
            }
        #endif
            
        } while (0);

        if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
        {
            get_content_cb_data.content[0] = '\0';
            get_content_cb_data.content[1] = '\0';

            /* The Message is not existed, exec the callback function with FALSE result */
            SMS_ASYNC_CALLBACK(
                SRV_SMS_ACTION_GET_CONTENT,
                MMI_FALSE,
                error_cause,
                &get_content_cb_data,
                user_data,
                callback_func);
        }
    }

    return (SMS_HANDLE)get_content_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_timestamp
 * DESCRIPTION
 *  Get Message's Timestamp (MTTIME Format)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  timestamp       [OUT]       Timestamp
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_get_msg_timestamp(U16 msg_id, MYTIME *time_stamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp_int;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timestamp_int = srv_sms_get_msg_timestamp_utc_sec(msg_id);
    timestamp_int = applib_dt_sec_utc_to_local(timestamp_int);

    mmi_dt_utc_sec_2_mytime(timestamp_int, time_stamp, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_timestamp_utc_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_get_msg_timestamp_utc_sec(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        timestamp = srv_sms_archive_get_msg_timestamp_utc_sec(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                timestamp = tcard_msg_node->timestamp;
            }
            else
            {
            timestamp = srv_sms_msg_list[msg_id].timestamp;
        }
        #else
            timestamp = srv_sms_msg_list[msg_id].timestamp;
        #endif
            
        }
        else
        {
            timestamp = 0;
        }
    }
    return timestamp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_storage_type
 * DESCRIPTION
 *  Get Message's Storage Tpye
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_storage_enum
 *****************************************************************************/
srv_sms_storage_enum srv_sms_get_msg_storage_type(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_storage_enum storage_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        storage_type = srv_sms_archive_get_msg_storage_type(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_list;
                
                tcard_msg_list = srv_sms_get_tcard_msg_list();
                storage_type = (srv_sms_storage_enum)tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].storage_type;
            }
            else
            {
            storage_type = (srv_sms_storage_enum)srv_sms_msg_list[msg_id].storage_type;
        }
            
        #else
            storage_type = (srv_sms_storage_enum)srv_sms_msg_list[msg_id].storage_type;
        #endif  
        }
        else
        {
            storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
        }
    }

    return storage_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_folder_id
 * DESCRIPTION
 *  Get Message's folder ID
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 * RETURNS
 *  srv_sms_folder_enum
 *****************************************************************************/
srv_sms_folder_enum srv_sms_get_msg_folder_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_folder_enum folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {   
        folder_id = SRV_SMS_FOLDER_ARCHIVE;
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        folder_id = SRV_SMS_FOLDER_DEFAULT;
    }

    return folder_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pid
 * DESCRIPTION
 *  Get Message's PID (Protocol Identifier)
 * PARAMETERS
 *  msg_id      [IN]    Message ID
 * RETURNS
 *  srv_sms_pid_enum
 *****************************************************************************/
srv_sms_pid_enum srv_sms_get_msg_pid(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_pid_enum pid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
    {
        pid = (srv_sms_pid_enum)srv_sms_msg_list[msg_id].pid;
    }
    else
    {
        pid = SRV_SMS_PID_RESERVED;
    }

    return pid;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_sms_ready
 * DESCRIPTION
 *  Check whether the SMS is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static srv_sms_status_enum srv_sms_get_msg_status_int(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        status = srv_sms_archive_get_msg_status(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
            srv_sms_msg_node_struct *tmp_msg_node;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id < SRV_SMS_MAX_SMS_ENTRY)
            {
                srv_sms_msg_node_struct *msg_node = &srv_sms_msg_list[msg_id];
                #ifdef __SRV_SMS_MULTI_ADDR__
                    status = srv_sms_get_msg_node_status(msg_node);
                #else /* __SRV_SMS_MULTI_ADDR__ */
                    status = (srv_sms_status_enum)msg_node->status;
                #endif /* __SRV_SMS_MULTI_ADDR__ */
            }
            else
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_list;
                
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_list = srv_sms_get_tcard_msg_list();
                tcard_msg_node = &tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM];
            #ifdef __SRV_SMS_MULTI_ADDR__
                status = srv_sms_get_tcard_msg_node_status(tcard_msg_node);
            #else /* __SRV_SMS_MULTI_ADDR__ */
                status = (srv_sms_status_enum)tcard_msg_node->status;
            #endif /* __SRV_SMS_MULTI_ADDR__ */
            }
        #else /* __SRV_SMS_TCARD_STORAGE_SUPPORT__*/
        
            tmp_msg_node = &srv_sms_msg_list[msg_id];
        #ifdef __SRV_SMS_MULTI_ADDR__
            status = srv_sms_get_msg_node_status(tmp_msg_node);
        #else /* __SRV_SMS_MULTI_ADDR__ */
            status = (srv_sms_status_enum)tmp_msg_node->status;
        #endif /* __SRV_SMS_MULTI_ADDR__ */
        
        #endif /* __SRV_SMS_TCARD_STORAGE_SUPPORT__*/

        }
        else
        {
            status = SRV_SMS_STATUS_NONE;
        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_status
 * DESCRIPTION
 *  Get Message's Status
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_status_enum
 *****************************************************************************/
srv_sms_status_enum srv_sms_get_msg_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        status = srv_sms_archive_get_msg_status(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __SRV_SMS_MULTI_ADDR__
/* under construction !*/
        #else /* __SRV_SMS_MULTI_ADDR__ */
/* under construction !*/
        #endif /* __SRV_SMS_MULTI_ADDR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    status = srv_sms_get_msg_status_int(msg_id);
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_mti
 * DESCRIPTION
 *  Get Message's MTI (Message Type Indication)
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_mti_enum
 *****************************************************************************/
srv_sms_mti_enum srv_sms_get_msg_mti(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mti_enum mti;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        srv_sms_status_enum status;
        U16 entry_id;

        entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        status = srv_sms_archive_get_msg_status(entry_id);
        mti = srv_sms_status_to_mti(status);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                mti = tcard_msg_node->mti;
            }
            else
            {
            mti = (srv_sms_mti_enum)srv_sms_msg_list[msg_id].mti;
        }
        #else
            mti = (srv_sms_mti_enum)srv_sms_msg_list[msg_id].mti;
        #endif  
        }
        else
        {
            mti = SRV_SMS_MTI_RESERVED;
        }
    }

    return mti;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_sim_id
 * DESCRIPTION
 *  Get Message's SIM Card ID
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_sim_enum
 *****************************************************************************/
srv_sms_sim_enum srv_sms_get_msg_sim_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_SIM__
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);
    
        sim_id = srv_sms_archive_get_msg_sim_id(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
             if (msg_id >= SRV_SMS_MAX_MSG_NUM)
             {
                 srv_sms_tcard_msg_node_struct *tcard_msg_list;
                
                 tcard_msg_list = srv_sms_get_tcard_msg_list();
                 sim_id = (srv_sms_sim_enum)tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].sim_id;
             }
             else
             {
            sim_id = (srv_sms_sim_enum)srv_sms_msg_list[msg_id].sim_id;
        }
    #else
            sim_id = (srv_sms_sim_enum)srv_sms_msg_list[msg_id].sim_id;
    #endif
            
        }
        else
        {
            sim_id = SRV_SMS_SIM_1;
        }
    }
#else /* __SRV_SMS_MULTI_SIM__ */
    sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */

    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_port
 * DESCRIPTION
 *  Get Message's Destination Port Number
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_msg_port(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 port_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_INFO_PORT__
    if (srv_sms_is_msg_exist_ext(msg_id))
    {
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            port_num = tcard_msg_node->port_num;
        }
        else
#endif
        {
            port_num = srv_sms_msg_list[msg_id].port_num;
        }
        
    }
#endif /* __SRV_SMS_MSG_INFO_PORT__ */

    return port_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_size
 * DESCRIPTION
 *  Get Message's size, only for SMS application internal using
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U8
 *****************************************************************************/
U16 srv_sms_get_msg_size(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        msg_size = srv_sms_archive_get_msg_size(entry_id);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
        {

    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                msg_size = srv_sms_get_tcard_msg_total_seg(msg_id) * SRV_SMS_TPUD_SIZE;
            }
            else
            {
            msg_size = srv_sms_get_msg_total_seg(msg_id) * SRV_SMS_TPUD_SIZE;
        }
    #else
            msg_size = srv_sms_get_msg_total_seg(msg_id) * SRV_SMS_TPUD_SIZE;
    #endif
            
        }
        else
        {
            msg_size = 0;
        }
    }

    return msg_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_delivery_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_sr_status_enum srv_sms_get_delivery_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_status_enum sr_status = SRV_SMS_SRS_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_DELIVERY_STATUS__ 
    if (srv_sms_is_msg_exist_ext(msg_id))
    {
        sr_status = srv_sms_get_sr_status(&srv_sms_msg_list[msg_id]);
    }
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    return sr_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_ext_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_set_msg_ext_status(U16 msg_id, U8 ext_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_EXT_STATUS__ 
    if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
    {
        result = MMI_TRUE;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            srv_tcard_op_struct read_cntx;

            
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            tcard_msg_node->ext_status = ext_status;

            read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
            read_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;

            srv_tcard_sync_write_record(&read_cntx, (char*)tcard_msg_node);
        }
        else
        {
            srv_sms_msg_list[msg_id].ext_status = ext_status;
        }
    #else
        srv_sms_msg_list[msg_id].ext_status = ext_status;
    #endif
    }
    else
    {
        result = MMI_FALSE;
    }
#else /* __SRV_SMS_MSG_EXT_STATUS__ */
    result = MMI_FALSE;
#endif /* __SRV_SMS_MSG_EXT_STATUS__ */

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_ext_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_ext_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ext_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_EXT_STATUS__ 
    if (srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE)
    {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if (msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_tcard_msg_node_struct *tcard_msg_node;

            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            ext_status = tcard_msg_node->ext_status;
        }
        else
        {
            ext_status = srv_sms_msg_list[msg_id].ext_status;
        }
    #else
        ext_status = srv_sms_msg_list[msg_id].ext_status;
    #endif
        
    }
    else
    {
        ext_status = SRV_SMS_STATUS_NONE;
    }
#else /* __SRV_SMS_MSG_EXT_STATUS__ */
    ext_status = SRV_SMS_STATUS_NONE;
#endif /* __SRV_SMS_MSG_EXT_STATUS__ */

    return ext_status;
}

#ifdef __SRV_SMS_RESEND_COUNT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_resend_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_resend_count(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_msg_exist_ext(msg_id))
    {
        return srv_sms_msg_list[msg_id].resend_count;
    }
    else
    {
        return 0;
    }
}
#endif /* __SRV_SMS_RESEND_COUNT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_get_msg_reply_path(
        U16 msg_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_reply_path_cb_struct get_reply_cb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        get_reply_cb_data.reply_path = MMI_FALSE;
        get_reply_cb_data.sc_addr[0] = '\0';

        srv_sms_callback(
            SRV_SMS_ACTION_GET_REPLY_PATH,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &get_reply_cb_data,
            user_data,
            callback_func);
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
    {
        srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

        if (storage_cntx.is_ready == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_NOT_READY;
        }
        else if (srv_sms_is_msg_exist_ext(msg_id) == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
        }

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            srv_sms_get_reply_path_cntx_struct *reply_path_cntx;
            U8 total_pdu;
            U16 curr_pdu_id;
            U16 pdu_id_list[SRV_SMS_MAX_SEG];

            reply_path_cntx = OslMalloc(sizeof(srv_sms_get_reply_path_cntx_struct));

            reply_path_cntx->callback_func = callback_func;
            reply_path_cntx->user_data = user_data;

            total_pdu = srv_sms_get_msg_pdu_id(pdu_id_list, msg_id);

            MMI_ASSERT(total_pdu > 0);

            curr_pdu_id = pdu_id_list[0];

            /* Read The first PDU Data */
            srv_sms_read_pdu(
                curr_pdu_id,
                srv_sms_get_msg_reply_path_callback,
                reply_path_cntx);
        }
        else
        {
            get_reply_cb_data.reply_path = MMI_FALSE;
            get_reply_cb_data.sc_addr[0] = '\0';

            srv_sms_callback(
                SRV_SMS_ACTION_GET_REPLY_PATH,
                MMI_FALSE,
                error_cause,
                &get_reply_cb_data,
                user_data,
                callback_func);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_pdu(
        U16 msg_id,
        srv_sms_msg_data_pdu_struct *msg_data,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_PDU, msg_id, msg_data);

    /* when exec the storage operation callback function, it will exist the MMI operating */
#ifdef __SRV_SMS_AT_SUPPORT__
    srv_sms_enter_mmi_operating();
#endif

    error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_READ);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_read_msg_pdu_cntx_struct *read_msg_cntx;

        /* Malloc Read Message Context Buffer */
        read_msg_cntx = OslMalloc(sizeof(srv_sms_read_msg_pdu_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_PDU, read_msg_cntx);

        /* Init Read Message Context Buffer, fill some neccessary information */
        srv_sms_read_msg_pdu_init(
            read_msg_cntx,
            msg_id,
            msg_data,
            callback_func,
            user_data);

        /* Read First PDU's Data */
        srv_sms_read_pdu(
            read_msg_cntx->pdu_id_list[read_msg_cntx->curr_index],
            srv_sms_read_msg_pdu_callback,
            read_msg_cntx);
    }
    else
    {
        srv_sms_read_msg_pdu_cb_struct read_msg_cb_data;

        read_msg_cb_data.msg_data = msg_data;
    
        /* The Message is not existed, exec the callback function with FALSE result */
        STORAGE_ASYNC_CALLBACK(
            SRV_SMS_ACTION_READ,
            MMI_FALSE,
            error_cause,
            &read_msg_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_add_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_msg_add_pdu(
        srv_sms_msg_add_pdu_struct* add_pdu_data,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_add_pdu_cb_struct msg_add_pdu_cb_data;
    srv_sms_action_enum action;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_ADD_PDU, add_pdu_data);
    if(add_pdu_data->msg_id != SRV_SMS_INVALID_MSG_ID)
    {
        action = SRV_SMS_ACTION_UPDATE;
    }
    else
    {
        action = SRV_SMS_ACTION_SAVE;  
    }
    msg_add_pdu_cb_data.msg_id = SRV_SMS_INVALID_MSG_ID;
    msg_add_pdu_cb_data.pdu_id = SRV_SMS_INVALID_PDU_ID;
    if (!storage_cntx.is_ready)
    {   
        srv_sms_callback(
            action,
            MMI_FALSE,
            SRV_SMS_CAUSE_NOT_READY,
            &msg_add_pdu_cb_data,
            user_data,
            callback_func);
    }
    else
    {
        if (add_pdu_data->raw_data_size <= SRV_SMS_MAX_PDU_SIZE)
        {
            srv_sms_msg_add_pdu_cntx_struct *add_msg_pdu_cntx;
            srv_sms_msg_node_struct *msg_node;
            srv_sms_mti_enum msg_mti;
            U8 pdu_len = 0;
            U8 curr_seg;
            U8 msg_ref;
            MMI_BOOL result = MMI_TRUE;

            add_msg_pdu_cntx = OslMalloc(sizeof(srv_sms_msg_add_pdu_cntx_struct));
            if(add_pdu_data->msg_id == SRV_SMS_INVALID_MSG_ID)
            {
                add_msg_pdu_cntx->is_hiden = add_pdu_data->is_hidden;
                add_msg_pdu_cntx->is_search_concat = add_pdu_data->is_search_concat;                
            }
            add_msg_pdu_cntx->msg_id = add_pdu_data->msg_id;
            add_msg_pdu_cntx->callback_func = callback_func;
            add_msg_pdu_cntx->user_data = user_data;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_ADD_PDU_1, add_msg_pdu_cntx);

            msg_node = &add_msg_pdu_cntx->msg_node;
            msg_node->status = add_pdu_data->status;

            msg_mti = srv_sms_status_to_mti(add_pdu_data->status);

            /* Get Base Info From SPDU */
            if (add_pdu_data->decode_data == NULL)
            {
                result = srv_sms_get_msg_info_from_pdu(
                            msg_node,
                            &curr_seg,
                            &msg_ref,
                            &pdu_len,
                            add_pdu_data->pdu_raw_data);
            }
            else
            {
                srv_sms_decode_data_to_msg_node(
                    msg_node,
                    &curr_seg,
                    &msg_ref,
                    add_pdu_data->decode_data);

                pdu_len = add_pdu_data->decode_data->pdu_len;
            }

            /* if the MTI is RESERVED, we will consider it as DELVIER */
            if ((msg_mti != msg_node->mti) && 
                ((msg_mti != SRV_SMS_MTI_DELIVER) || (msg_node->mti != SRV_SMS_MTI_RESERVED)))
            {
                result = MMI_FALSE;
            }

            if (result)
            {
                srv_sms_spdu_struct *spdu_data;
                srv_sms_add_pdu_struct add_data;
    
                spdu_data = OslMalloc(sizeof(srv_sms_spdu_struct));

                srv_sms_encode_spdu(
                    spdu_data,
                    add_pdu_data->status,
                    add_pdu_data->pdu_raw_data,
                    pdu_len,
                    add_pdu_data->sim_id);

            #ifdef __SRV_SMS_MULTI_SIM__ 
                msg_node->sim_id = add_pdu_data->sim_id;
            #endif /* __SRV_SMS_MULTI_SIM__ */
                msg_node->start_pdu_id = SRV_SMS_INVALID_PDU_ID;
            #ifdef __SRV_SMS_MULTI_ADDR__
                msg_node->ext_addr_num = 0;
                msg_node->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
            #endif /*  __SRV_SMS_MULTI_ADDR__*/
                msg_node->storage_type = add_pdu_data->storage_type;
                if(add_pdu_data->msg_id == SRV_SMS_INVALID_MSG_ID)
                {     
            #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
                    msg_node->ext_status = SRV_SMS_STATUS_NONE;
            #endif /* __SRV_SMS_MSG_EXT_STATUS__ */
            #ifdef __SRV_SMS_RESEND_COUNT__ 
                    msg_node->resend_count = 0;
            #endif /* __SRV_SMS_RESEND_COUNT__ */

                    if ((add_pdu_data->status != SRV_SMS_STATUS_READ) &&
                        (add_pdu_data->status != SRV_SMS_STATUS_UNREAD))
                    {
                        msg_node->timestamp = spdu_data->timestamp;
                    }
                }
                else
                {
                    msg_node->timestamp = spdu_data->timestamp;
                }
                add_msg_pdu_cntx->curr_seg  = curr_seg;

                add_data.spdu_data = spdu_data;
                add_data.curr_seg = curr_seg;
                add_data.storage_type = add_pdu_data->storage_type;
            #ifdef __SRV_SMS_DELIVERY_STATUS__
                add_data.msg_ref = msg_ref;
            #endif /* __SRV_SMS_DELIVERY_STATUS__ */
                if(add_pdu_data->msg_id == SRV_SMS_INVALID_MSG_ID)
                    srv_sms_add_pdu(
                        &add_data,
                        srv_sms_msg_add_pdu_callback,
                        add_msg_pdu_cntx);
                else
                    srv_sms_add_pdu(
                        &add_data,
                        srv_sms_msg_append_pdu_callback,
                        add_msg_pdu_cntx);

                OslMfree(spdu_data);
            }
            else
            {
                OslMfree(add_msg_pdu_cntx);
                srv_sms_callback(
                    action,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_INVALID_PDU_PARA,
                    &msg_add_pdu_cb_data,
                    user_data,
                    callback_func);
            }
        }
        else
        {
            srv_sms_callback(
                action,
                MMI_FALSE,
                SRV_SMS_CAUSE_INVALID_PDU_PARA,
                &msg_add_pdu_cb_data,
                user_data,
                callback_func);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_delete_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_msg_delete_pdu(
        U16 pdu_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_DELETE_PDU, pdu_id);

    if (srv_sms_is_pdu_exist(pdu_id) == MMI_TRUE)
    {
        srv_sms_msg_delete_pdu_cntx_struct *del_msg_pdu_cntx;
        del_msg_pdu_cntx = OslMalloc(sizeof(srv_sms_msg_delete_pdu_cntx_struct));

        del_msg_pdu_cntx->callback_func = callback_func;
        del_msg_pdu_cntx->user_data = user_data;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_DELETE_PDU_1, del_msg_pdu_cntx);

        del_msg_pdu_cntx->msg_id = srv_sms_get_msg_id_by_pdu(pdu_id);

        srv_sms_delete_pdu(
            pdu_id,
            srv_sms_msg_delete_pdu_callback,
            del_msg_pdu_cntx);
    }
    else
    {
        srv_sms_error_callback(
            SRV_SMS_ACTION_DELETE,
            SRV_SMS_CAUSE_INVALID_MEM_INDEX,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_update_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_msg_update_pdu(
        U16 pdu_id,
        srv_sms_spdu_struct *spdu_data,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_pdu_exist(pdu_id) == MMI_TRUE)
    {
        srv_sms_msg_update_pdu_cntx_struct *update_msg_pdu_cntx;
        srv_sms_update_pdu_struct update_data;

        update_msg_pdu_cntx = OslMalloc(sizeof(srv_sms_msg_update_pdu_cntx_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_UPDATE_PDU, pdu_id, update_msg_pdu_cntx);

        update_msg_pdu_cntx->pdu_id = pdu_id;
        update_msg_pdu_cntx->callback_func = callback_func;
        update_msg_pdu_cntx->user_data = user_data;

        update_data.spdu_data = spdu_data;
        update_data.update_flag = SRV_SMS_PARA_STATUS;

        srv_sms_update_pdu(
            pdu_id,
            &update_data,
            srv_sms_msg_update_pdu_callback,
            update_msg_pdu_cntx);
    }
    else
    {
        srv_sms_error_callback(
            SRV_SMS_ACTION_UPDATE,
            SRV_SMS_CAUSE_DATA_INVALID,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_unhide_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_unhide_msg(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_sms_is_msg_exist_ext(msg_id) == MMI_TRUE) &&
        (srv_sms_is_msg_hidden(msg_id) == MMI_TRUE))
    {
        srv_sms_event_add_struct *add_event_data;
        MMI_BOOL int_result;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id < SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_unhide_msg_node(msg_id);
        }
        else
        {
            srv_tcard_op_struct read_cntx;
            srv_sms_tcard_msg_node_struct *tcard_msg_node;

            read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
            read_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            srv_sms_unhide_tcard_msg_node(msg_id);
            srv_tcard_sync_write_record(&read_cntx, (char*)tcard_msg_node);

        }        
#else
        srv_sms_unhide_msg_node(msg_id);
#endif
        /* Exec Add Msg Interrupt Event */
        add_event_data = OslMalloc(sizeof(srv_sms_event_add_struct));

        add_event_data->msg_id = msg_id;
        srv_sms_get_msg_info(&add_event_data->msg_info, msg_id);

        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);

        if (int_result == MMI_FALSE)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
        }

        OslMfree(add_event_data);
    }
}


#ifdef __SRV_SMS_DELIVERY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_sr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_sr_status(
        char* number,
        U8 msg_ref,
        srv_sms_sim_enum sim_id,
        srv_sms_sr_status_enum tp_st,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pdu_id = srv_sms_search_pdu(number, msg_ref, sim_id);

    if (pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        srv_sms_update_srs_cntx_struct *update_srs_cntx;
        U16 msg_id;

        msg_id = srv_sms_get_msg_id_by_pdu(pdu_id);

        update_srs_cntx = OslMalloc(sizeof(srv_sms_update_srs_cntx_struct));
        update_srs_cntx->pdu_id = pdu_id;
        update_srs_cntx->msg_id = msg_id;
        update_srs_cntx->old_sts = srv_sms_get_delivery_status(msg_id);
        update_srs_cntx->tp_st = tp_st;
        update_srs_cntx->callback_func = callback_func;
        update_srs_cntx->user_data = user_data;

        srv_sms_read_pdu(
            pdu_id,
            srv_sms_update_sr_status_callback,
            update_srs_cntx);
    }
#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
    else
    {
        U16 addr_id;
        U16 seg_index;        

        addr_id = srv_sms_search_ext_addr(&seg_index, number, msg_ref, sim_id);

        if (addr_id != SRV_SMS_INVALID_ADDR_ID)
        {
            MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY);

            srv_sms_addr_list[addr_id].tp_st[seg_index] = tp_st;
        }
        else
        {
            srv_sms_error_callback(
                SRV_SMS_ACTION_UPDATE,
                SRV_SMS_CAUSE_INVALID_MEM_INDEX,
                user_data,
                callback_func);
        }
    }
#else /* __SRV_SMS_MULTI_ADDR_REPORT__ */
    else
    {
        srv_sms_error_callback(
            SRV_SMS_ACTION_UPDATE,
            SRV_SMS_CAUSE_INVALID_MEM_INDEX,
            user_data,
            callback_func);
    }
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

}
#endif /* __SRV_SMS_DELIVERY_STATUS__ */


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_tcard_copy_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_pdu_list_update_struct *copy_list_cntx;
    srv_sms_copy_int_cb_struct copy_cb_data;
    srv_sms_copy_cntx_struct *copy_cntx;  
    MMI_BOOL is_added;
    MMI_BOOL int_result;
	srv_sms_event_add_struct *add_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_list_cntx = (srv_sms_copy_pdu_list_update_struct*)callback_data->user_data;
    copy_cntx = copy_list_cntx->copy_cntx;
    /* Set Event Data For Add Event */
    add_event = (srv_sms_event_add_struct*)copy_list_cntx->event_info;
    is_added = copy_list_cntx->is_add;

    /*if write is not ok,do not to add msg*/
    if (callback_data->result)
    {
        srv_tcard_op_struct read_cntx;
	srv_sms_tcard_msg_node_struct *tcard_msg_node;
	MMI_BOOL result;

	tcard_msg_node = srv_sms_get_tcard_msg_node(copy_list_cntx->new_msg_id - SRV_SMS_MAX_MSG_NUM);
		
        read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
        read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
        read_cntx.start_record_id = copy_list_cntx->new_msg_id - SRV_SMS_MAX_MSG_NUM;
        read_cntx.record_num = 1;
                    
        result = srv_tcard_sync_write_record(&read_cntx,(CHAR*)tcard_msg_node);  
        /* Exec Interrupt Add Event */
        if(result >= 0)
        {
	        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_event);
	        
	        /* Exec Callback Function */
	        copy_cb_data.dest_msg_id = copy_list_cntx->new_msg_id;
		    srv_sms_copy_deinit(copy_cntx);
	        STORAGE_INVOKE_CALLBACK(
	            copy_cntx,
	            MMI_TRUE,
	            SRV_SMS_CAUSE_NO_ERROR,
	            &copy_cb_data);
	            
	        if (!int_result)
	        {
	            if (is_added && !copy_move_list)
	            {
	                srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, copy_list_cntx->event_info);       
	            }
	        }	        
	        srv_sms_handle_mem_change(MMI_FALSE);
        }
	else
	{
	    srv_sms_copy_deinit(copy_cntx);
	    STORAGE_INVOKE_CALLBACK(
	            copy_cntx,
	            MMI_FALSE,
	            SRV_SMS_CAUSE_FS_ERROR,
	            &copy_cb_data);
	}
        
    }
    else
    {
        srv_sms_copy_deinit(copy_cntx);
        STORAGE_INVOKE_CALLBACK(
            copy_cntx,
            MMI_FALSE,
            SRV_SMS_CAUSE_FS_ERROR,
            &copy_cb_data);
    }


    OslMfree(copy_list_cntx->event_info);
    OslMfree(copy_list_cntx);
}

static void srv_sms_tcard_delete_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_msg_node_struct *delete_msg_cntx;
    srv_sms_delete_msg_cb_struct del_msg_cb_data;
    srv_sms_event_delete_struct *event_data = NULL;
    MMI_BOOL is_hidden;
    MMI_BOOL is_backgroud;
    MMI_BOOL int_result = MMI_FALSE;
    MMI_BOOL result;
    srv_sms_delete_cntx_struct *delete_cntx; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_msg_cntx = callback_data->user_data;
    delete_cntx = delete_msg_cntx->delete_cntx;
    event_data = delete_msg_cntx->event_info;
    is_hidden = delete_msg_cntx->is_hiden;
    is_backgroud = delete_msg_cntx->is_backgroud;
    result = callback_data->result;
    if(callback_data->result >= 0)
    {
        if (is_hidden == MMI_FALSE)
        {
            /* Execute Message Delete Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
        }
#ifdef __SRV_SMS_AT_SUPPORT__
        if (is_backgroud == MMI_FALSE)
        {
            //srv_sms_exit_mmi_operating();
        }
#endif /* __SRV_SMS_AT_SUPPORT__ */

        if (CNTX_IS_ABORT(delete_cntx))
        {
            result = MMI_FALSE;
        }

        srv_sms_cntx_callback(
            delete_cntx,
            result,
            callback_data->cause,
            &del_msg_cb_data);

        if ((is_hidden == MMI_FALSE) && (int_result == MMI_FALSE))
        {
            /* Emit Message Delete Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
        }

        if (event_data != NULL)
        {
            OslMfree(event_data);
        }

        srv_sms_handle_mem_change(MMI_FALSE);
    }
    else
    {
        MMI_BOOL temp_result;
        U16 *pdu_id_list = &delete_cntx->pdu_id_list[delete_cntx->curr_index];
        U8 remain_num = delete_cntx->total_pdu - delete_cntx->curr_index;

        temp_result = MMI_FALSE;
        srv_sms_clear_set_pdu_array_flag(
            pdu_id_list,
            remain_num,
            SRV_SMS_NODE_DELETING,
            MMI_TRUE);
    #ifdef __SRV_SMS_AT_SUPPORT__
        if (is_backgroud == MMI_FALSE)
        {
            srv_sms_exit_mmi_operating();
        }
    #endif /* __SRV_SMS_AT_SUPPORT__ */

        if (CNTX_IS_ABORT(delete_cntx))
        {
            temp_result = MMI_TRUE;
        }
       
        srv_sms_cntx_callback(
            delete_cntx,
            temp_result,
            result,
            NULL);
    }
    OslMfree(delete_msg_cntx);
}
static void srv_sms_tcard_receive_list_update_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_receive_tcard_cntx_struct *update_cntx;
    srv_sms_event_add_struct *add_event_data; 
    srv_sms_msg_add_pdu_cb_struct msg_add_pdu_cb_data;
    MMI_BOOL int_result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = (srv_sms_receive_tcard_cntx_struct*)callback_data->user_data;
    
    if (update_cntx->is_add)
    {
            add_event_data = OslMalloc(sizeof(srv_sms_event_add_struct));
            add_event_data->msg_id = update_cntx->msg_id;
        if (!update_cntx->is_hiden)
        {
            srv_sms_get_msg_info(&add_event_data->msg_info, update_cntx->msg_id);

            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
        }
            msg_add_pdu_cb_data.msg_id = update_cntx->msg_id;
            msg_add_pdu_cb_data.pdu_id = update_cntx->pdu_id;

            srv_sms_succ_callback(
                SRV_SMS_ACTION_SAVE,
                &msg_add_pdu_cb_data,
                update_cntx->user_data,
                update_cntx->callback_func);

            if (!int_result)
            {
               
                srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
                
            }

            if (add_event_data != NULL)
            {
                OslMfree(add_event_data);
            }
            srv_sms_handle_mem_change(MMI_FALSE);
        
    }
    else
    {
            srv_sms_event_update_struct *update_event_data;
            /* Exec Change Msg Interrupt Event */
            update_event_data = OslMalloc(sizeof(srv_sms_event_update_struct));
        if (!update_cntx->is_hiden)
        {


            /* Get Old Msg Info */
            srv_sms_get_msg_info(&update_event_data->old_msg_info, update_cntx->msg_id);

            update_event_data->msg_id = update_cntx->msg_id;
            update_event_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STATUS | SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_CONTENT);
            srv_sms_get_msg_info(&update_event_data->new_msg_info, update_cntx->msg_id);

            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, update_event_data);
        }
            msg_add_pdu_cb_data.msg_id = update_cntx->msg_id;
            msg_add_pdu_cb_data.pdu_id = update_cntx->pdu_id;

            srv_sms_succ_callback(
                SRV_SMS_ACTION_SAVE,
                &msg_add_pdu_cb_data,
                update_cntx->user_data,
                update_cntx->callback_func);

            if (!int_result)
            {

                srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, update_event_data);

            }

            if (update_event_data != NULL)
            {
                OslMfree(update_event_data);
            }

            srv_sms_handle_mem_change(MMI_FALSE);
            
    }
    OslMfree(update_cntx);
}

static void srv_sms_tcard_receive_append_list_update_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_receive_tcard_append_cntx_struct *update_cntx;
    srv_sms_event_update_struct *event_data;
    srv_sms_msg_add_pdu_cb_struct append_msg_cb_data;
    MMI_BOOL int_result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = (srv_sms_receive_tcard_append_cntx_struct*)callback_data->user_data;
    event_data = update_cntx->event_data;
    if (!update_cntx->is_hiden)
    {
        /* Exec Change Msg Interrupt Event */
        event_data->msg_id = update_cntx->msg_id;
        event_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STATUS | SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_CONTENT_BUFF);
        srv_sms_get_msg_info(&event_data->new_msg_info, update_cntx->msg_id);

        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
    }

    append_msg_cb_data.pdu_id = update_cntx->pdu_id;

    srv_sms_succ_callback(
        SRV_SMS_ACTION_UPDATE,
        &append_msg_cb_data,
        update_cntx->user_data,
        update_cntx->callback_func);

    /* Exec Change Msg Event */
    if (!int_result)
    {
        srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
    }

    if (event_data != NULL)
    {
        OslMfree(event_data);
    }

    srv_sms_handle_mem_change(MMI_FALSE);
    OslMfree(update_cntx);
}

static void srv_sms_tcard_update_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_save_cntx_struct *save_cntx;
    MMI_BOOL result;
    MMI_BOOL int_result;
    srv_sms_cause_enum error_cause;
    srv_sms_save_msg_cb_struct save_msg_cb_data;
    srv_sms_event_add_struct *event_data;
    srv_sms_update_tcard_cntx_struct *update_cntx;
    srv_sms_update_tcard_op_enum op_flag;
    U16 msg_id;
    U16 start_index;
    U16 end_index;
    U16 temp_index;
    srv_tcard_op_struct cntx;
    CHAR *buff = NULL;
    srv_sms_tcard_msg_node_struct *msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = callback_data->result;
    update_cntx = (srv_sms_update_tcard_cntx_struct*)callback_data->user_data;
    save_cntx = (srv_sms_save_cntx_struct*)update_cntx->cntx;
    msg_id = update_cntx->msg_id;
    event_data = update_cntx->event_data;
    if(update_cntx->action_type == SRV_SMS_ACTION_SAVE)
    {
        if(result)
        {
            op_flag = update_cntx->total_flag & (~ update_cntx->curr_flag);
            if(op_flag)
            {
                if(op_flag & SRV_SMS_UPDATE_TCARD_PDU_LIST)
                {
                    srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
                    U16 big_index = 0;
                    U16 small_index = 0xFFFF;

                    for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                    cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                    update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                    update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                    update_cntx->action_type = SRV_SMS_ACTION_SAVE;
                    msg_list = srv_sms_get_tcard_msg_list();
                    temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

                    if(temp_index > big_index)
                    {
                        big_index = temp_index;
                    }
                    if(temp_index < small_index)
                    {
                        small_index = temp_index;
                    }
                    
                    while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id != SRV_SMS_INVALID_INDEX)
                    {
                        temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                        if(temp_index > big_index)
                        {
                            big_index = temp_index;
                        }
                        if(temp_index < small_index)
                        {
                            small_index = temp_index;
                        }
                    }
                    start_index = small_index - SRV_SMS_MAX_MSG_NUM;
                    end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                    cntx.start_record_id = start_index ;

                    cntx.record_num = end_index - start_index +1;
                    buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                    for_tcard_cntx->user_data = update_cntx;
                    for_tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
                    srv_tcard_write_record(
                            &cntx,
                            buff,
                            srv_sms_for_tcard_callback,
                            for_tcard_cntx);
                }
            }
            else
            {
                save_cntx = (srv_sms_save_cntx_struct*)update_cntx->cntx;
                srv_sms_save_msg_deinit(save_cntx);

                /* Execute Message Add Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);

                /* Execute Callback Function */
                
                msg_id = update_cntx->msg_id;
                save_msg_cb_data.msg_id = msg_id;

                STORAGE_INVOKE_CALLBACK(
                    save_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_NO_ERROR,
                    &save_msg_cb_data);

                if (int_result == MMI_FALSE)
                {
                    /* Emit Message Add Event */
                    srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                }

                OslMfree(event_data);
                OslMfree(update_cntx);
                srv_sms_handle_mem_change(MMI_FALSE);
            }  
        }
        else
        {
            /*need to delete pdu and msg list*/
            if(update_cntx->curr_flag == SRV_SMS_UPDATE_TCARD_ADDR_LIST)
            {
                if (save_cntx->curr_index > 0)
                {
                    /* Remind the Cause For Callback */
                    save_cntx->error_cause = callback_data->cause;
                    /* Set the added/Deleted PDU total number */
                    save_cntx->total_pdu = save_cntx->curr_index;
                    /* Set the deleted Index */
                    save_cntx->curr_index = 0;

                    /* Clear WRITING flag, Set DELETING flag */
                    srv_sms_clear_set_pdu_array_flag(
                        save_cntx->pdu_id_list,
                        save_cntx->total_pdu,
                        SRV_SMS_NODE_LOCKING,
                        MMI_TRUE);

                    srv_sms_clear_set_pdu_array_flag(
                        save_cntx->pdu_id_list,
                        save_cntx->total_pdu,
                        SRV_SMS_NODE_DELETING,
                        MMI_FALSE);

                    srv_sms_delete_pdu(
                        save_cntx->pdu_id_list[save_cntx->curr_index],
                        srv_sms_save_msg_del_callback,
                        save_cntx);
                }
            }
            else /*need to delete ext addr and pdu and msg list*/
            {
            #ifdef __SRV_SMS_MULTI_ADDR__
              
                cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                msg_list = srv_sms_get_tcard_msg_list();     
                if(msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].ext_addr_num > 0)
                {

                    srv_sms_for_tcard_cntx_struct *tcard_cntx;


                    tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                    cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_ADDR_INFO;
                    update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST | SRV_SMS_UPDATE_TCARD_ADDR_LIST;
                    update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_ADDR_LIST;
                    update_cntx->action_type = SRV_SMS_ACTION_DELETE;
                    temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_addr_id;
                    start_index = temp_index;
                    cntx.start_record_id = start_index - SRV_SMS_MAX_ADDR_ENTRY;
                    srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].status = 0;
                    while(srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id != SRV_SMS_INVALID_INDEX)
                    {
                        temp_index = srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id;
                        srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].status = 0;
                    }
                    end_index = temp_index - SRV_SMS_MAX_ADDR_ENTRY;;

                    cntx.record_num = end_index - start_index + 1;
                    buff = (CHAR*)(srv_sms_tcard_addr_list + cntx.start_record_id);
                    
                    tcard_cntx->user_data = update_cntx;
                    tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
                    
                    srv_tcard_write_record(
                            &cntx,
                            buff,
                            srv_sms_for_tcard_callback,
                            tcard_cntx);
                }
                else /*only need to delete the pdu*/
                {
                    if (save_cntx->curr_index > 0)
                    {
                        /* Remind the Cause For Callback */
                        save_cntx->error_cause = callback_data->cause;
                        /* Set the added/Deleted PDU total number */
                        save_cntx->total_pdu = save_cntx->curr_index;
                        /* Set the deleted Index */
                        save_cntx->curr_index = 0;

                        /* Clear WRITING flag, Set DELETING flag */
                        srv_sms_clear_set_pdu_array_flag(
                            save_cntx->pdu_id_list,
                            save_cntx->total_pdu,
                            SRV_SMS_NODE_LOCKING,
                            MMI_TRUE);

                        srv_sms_clear_set_pdu_array_flag(
                            save_cntx->pdu_id_list,
                            save_cntx->total_pdu,
                            SRV_SMS_NODE_DELETING,
                            MMI_FALSE);

                        srv_sms_delete_pdu(
                            save_cntx->pdu_id_list[save_cntx->curr_index],
                            srv_sms_save_msg_del_callback,
                            save_cntx);
                    }                        
                }
            #else
                if (save_cntx->curr_index > 0)
                {
                    /* Remind the Cause For Callback */
                    save_cntx->error_cause = callback_data->cause;
                    /* Set the added/Deleted PDU total number */
                    save_cntx->total_pdu = save_cntx->curr_index;
                    /* Set the deleted Index */
                    save_cntx->curr_index = 0;

                    /* Clear WRITING flag, Set DELETING flag */
                    srv_sms_clear_set_pdu_array_flag(
                        save_cntx->pdu_id_list,
                        save_cntx->total_pdu,
                        SRV_SMS_NODE_LOCKING,
                        MMI_TRUE);

                    srv_sms_clear_set_pdu_array_flag(
                        save_cntx->pdu_id_list,
                        save_cntx->total_pdu,
                        SRV_SMS_NODE_DELETING,
                        MMI_FALSE);

                    srv_sms_delete_pdu(
                        save_cntx->pdu_id_list[save_cntx->curr_index],
                        srv_sms_save_msg_del_callback,
                        save_cntx);
                }
            #endif
            }
        }
    }
    else
    {
        op_flag = update_cntx->total_flag & (~ update_cntx->curr_flag);
        if(op_flag & SRV_SMS_UPDATE_TCARD_PDU_LIST)
        {
            srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
            U16 big_index = 0;
            U16 small_index = 0xffff;
            
            for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
            cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
            update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
            update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
            update_cntx->action_type = SRV_SMS_ACTION_DELETE;
            msg_list = srv_sms_get_tcard_msg_list();
            temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;
            
            if(temp_index > big_index)
            {
                big_index = temp_index;
            }
            if(temp_index < small_index)
            {
                small_index = temp_index;
            }
            
            
            srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].status = 0;
            while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id != SRV_SMS_INVALID_INDEX)
            {
                temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].status = 0;
                if(temp_index > big_index)
                {
                    big_index = temp_index;
                }
                if(temp_index < small_index)
                {
                    small_index = temp_index;
                }
            }

            start_index = small_index  - SRV_SMS_MAX_MSG_NUM;
            end_index = big_index  - SRV_SMS_MAX_MSG_NUM;
            cntx.start_record_id = start_index;

            cntx.record_num = end_index - start_index + 1;
            buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);


            for_tcard_cntx->user_data = update_cntx;
            for_tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
            srv_tcard_write_record(
                    &cntx,
                    buff,
                    srv_sms_for_tcard_callback,
                    for_tcard_cntx);
        }
        else
        {
            if (save_cntx->curr_index > 0)
            {
                /* Remind the Cause For Callback */
                save_cntx->error_cause = callback_data->cause;
                /* Set the added/Deleted PDU total number */
                save_cntx->total_pdu = save_cntx->curr_index;
                /* Set the deleted Index */
                save_cntx->curr_index = 0;

                /* Clear WRITING flag, Set DELETING flag */
                srv_sms_clear_set_pdu_array_flag(
                    save_cntx->pdu_id_list,
                    save_cntx->total_pdu,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);

                srv_sms_clear_set_pdu_array_flag(
                    save_cntx->pdu_id_list,
                    save_cntx->total_pdu,
                    SRV_SMS_NODE_DELETING,
                    MMI_FALSE);

                srv_sms_delete_pdu(
                    save_cntx->pdu_id_list[save_cntx->curr_index],
                    srv_sms_save_msg_del_callback,
                    save_cntx);
                }
        }
    }
    
}
    

static void srv_sms_for_tcard_callback(srv_tcard_callback_struct *tcard_callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_cause_enum error_cause;
    srv_sms_callback_struct *callback_data;
    srv_sms_for_tcard_cntx_struct *cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (srv_sms_for_tcard_cntx_struct*)tcard_callback_data->user_data;
    callback_data = (srv_sms_callback_struct*)OslMalloc(sizeof(srv_sms_callback_struct));
    if(tcard_callback_data->result >= 0)
    {
        callback_data->result = MMI_TRUE;
    }
    else
    {
        callback_data->result = MMI_FALSE;
    }      
    callback_data->cause = tcard_callback_data->result;     
    callback_data->action_data = tcard_callback_data->action_data;            
    callback_data->user_data = cntx->user_data;
    cntx->callback_func(callback_data);

    OslMfree(callback_data);
    OslMfree(cntx);
}


static void srv_sms_tcard_handle_asyc_copy(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_async_cntx_struct *asyc_cntx;
    srv_tcard_op_struct *cntx;
    srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
    CHAR *buff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyc_cntx = (srv_sms_tcard_async_cntx_struct*)arg;
    cntx = asyc_cntx->cntx;
    for_tcard_cntx = asyc_cntx->for_tcard_cntx;
    buff = (CHAR*)(srv_sms_tcard_pdu_list + cntx->start_record_id);
    srv_tcard_write_record(
        cntx,
        buff,
        srv_sms_for_tcard_callback,
        for_tcard_cntx);
    OslMfree(cntx);
    OslMfree(asyc_cntx);
}

#endif

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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
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
 * FUNCTION
 *  srv_sms_read_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_read_msg_init(
                            srv_sms_read_cntx_struct* read_cntx,
                            U16 msg_id,
                            MMI_BOOL change_status,
                            srv_sms_msg_data_struct* msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_sms_status_enum msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_INIT);

    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        read_cntx->spdu_list[i] = NULL;
    }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        read_cntx->tcard_spdu_list[i] = NULL;
    }
#endif
    read_cntx->total_pdu = srv_sms_get_msg_pdu_id_ext(read_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(read_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        read_cntx->pdu_id_list,
        read_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);

    read_cntx->curr_index = 0;

    read_cntx->msg_id = msg_id;
    msg_status = srv_sms_get_msg_status(msg_id);

    if ((msg_status & SRV_SMS_STATUS_UNREAD) && (change_status == MMI_TRUE))
    {
        read_cntx->change_status = MMI_TRUE;
    }
    else
    {
        read_cntx->change_status = MMI_FALSE;
    }

    read_cntx->msg_data = msg_data;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_curr_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_save_msg_curr_pdu(srv_sms_save_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_spdu_struct *spdu_data;
    srv_sms_add_pdu_struct add_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdu_data = save_cntx->spdu_list[save_cntx->curr_index];

#ifdef __SRV_SMS_MULTI_ADDR__
    spdu_data->addr_num = save_cntx->msg_node.ext_addr_num;
    spdu_data->start_addr_id = save_cntx->msg_node.start_addr_id;
#endif /* __SRV_SMS_MULTI_ADDR__ */

    add_data.spdu_data = spdu_data;
    add_data.storage_type = save_cntx->storage_type;
    add_data.curr_seg = (U8)(save_cntx->curr_index + 1);
#ifdef __SRV_SMS_DELIVERY_STATUS__
    add_data.msg_ref = save_cntx->msg_ref[save_cntx->curr_index];
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    /* Save the fisrt PDU */
    srv_sms_add_pdu(
        &add_data,
        srv_sms_save_msg_callback,
        save_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_save_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_save_cntx_struct *save_cntx;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = callback_data->cause;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct tcard_msg_node;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = (srv_sms_save_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_CALLBACK, callback_data->result, save_cntx->curr_index);

    if (CNTX_IS_ABORT(save_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }

    if (result)
    {
        srv_sms_add_pdu_cb_struct *add_pdu_cb_data;
        U16 pdu_id;

        add_pdu_cb_data = (srv_sms_add_pdu_cb_struct*)callback_data->action_data;

        pdu_id = add_pdu_cb_data->pdu_id;

        MMI_ASSERT(save_cntx->curr_index < SRV_SMS_MAX_SEG);
        MMI_ASSERT(save_cntx->total_pdu <= SRV_SMS_MAX_SEG);

        /* Save the saved PDU's ID */
        save_cntx->pdu_id_list[save_cntx->curr_index] = pdu_id;

        /* Set LOCKING flag, don't allow to do any operation to this PDU */
        srv_sms_set_pdu_flag(pdu_id, SRV_SMS_NODE_LOCKING);

        /* Increment the Currenet Saved Index */
        save_cntx->curr_index++;

        /* Check whether all of the PDU is saved */
        if (save_cntx->curr_index < save_cntx->total_pdu)
        {
            srv_sms_save_msg_curr_pdu(save_cntx);
        }
        else
        {
            srv_sms_save_msg_cb_struct save_msg_cb_data;
            srv_sms_msg_node_struct *msg_node = &save_cntx->msg_node;
            U16 msg_id;

            /* If the storage type is not specified, set it based on the PDU's storage */
            if (save_cntx->storage_type == SRV_SMS_STORAGE_UNSPECIFIC)
            {
                msg_node->storage_type = srv_sms_get_storage_type_by_pdu(
                                            save_cntx->pdu_id_list,
                                            save_cntx->total_pdu);
            }
            else
            {
               msg_node->storage_type = save_cntx->storage_type;
            }

        #ifndef __SRV_SMS_SIM_TIMESTAMP__
            if ((msg_node->mti == SRV_SMS_MTI_SUBMIT) &&
                (msg_node->storage_type == SRV_SMS_STORAGE_SIM))
            {
                msg_node->timestamp = 0;
            }
        #endif /* __SRV_SMS_SIM_TIMESTAMP__ */

            /* Add a Message Node in the Mesage List */
            
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(save_cntx->storage_type == SRV_SMS_STORAGE_TCARD)
            {   
                
                   /* srv_sms_status_enum */
                tcard_msg_node.status = msg_node->status;
            #ifdef __SRV_SMS_MSG_INFO_DCS__ 
            	tcard_msg_node.dcs = msg_node->dcs;
            #else
                tcard_msg_node.dcs = 0;
            #endif
            #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
            	tcard_msg_node.ext_status = msg_node->ext_status;
            #else
                tcard_msg_node.ext_status = 0;
            #endif
            #ifdef __SRV_SMS_RESEND_COUNT__
                tcard_msg_node.resend_count = msg_node->resend_count;
            #else
                tcard_msg_node.resend_count = 0;
            #endif 
                /* <<-- msg node compare range start */
                tcard_msg_node.storage_type = SRV_SMS_STORAGE_TCARD;
                tcard_msg_node.mti = msg_node->mti;
            	tcard_msg_node.pid = msg_node->pid;

                /* Concatenated inforamtion */
                tcard_msg_node.total_seg = msg_node->total_seg;
                tcard_msg_node.start_seg = msg_node->start_seg;
                tcard_msg_node.ref_num = msg_node->ref_num;
            #ifdef __SRV_SMS_MULTI_SIM__ 
            	tcard_msg_node.sim_id = msg_node->sim_id;
            #else
                tcard_msg_node.sim_id = SIM1;
            #endif

            #ifdef __SRV_SMS_MULTI_ADDR__
                /* Extension address number */
                tcard_msg_node.ext_addr_num = msg_node->ext_addr_num;
                /* Start Externsion Address ID */
                tcard_msg_node.start_addr_id = msg_node->start_addr_id;
            #else
                tcard_msg_node.ext_addr_num = 0;
                /* Start Externsion Address ID */
                tcard_msg_node.start_addr_id = 0XFFFF;
            #endif
            #ifdef __SRV_SMS_MSG_INFO_PORT__
                tcard_msg_node.port_num = msg_node->port_num;
            #else
                tcard_msg_node.port_num = 0XFFFF;
            #endif
            
                tcard_msg_node.start_pdu_id = msg_node->start_pdu_id;
            
                memcpy(tcard_msg_node.number,msg_node->number,SRV_SMS_MAX_ADDR_LEN + 1);
            #ifdef __SRV_SMS_MSG_INFO_CONTENT__
                memcpy(tcard_msg_node.content,msg_node->content,SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1);
            #else
                memset(tcard_msg_node.content,0x00,SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1);
            #endif

                tcard_msg_node.timestamp = msg_node->timestamp;
                msg_id = srv_sms_add_tcard_msg_node(&tcard_msg_node);
            }
            else
        #endif
            {
                msg_id = srv_sms_add_msg_node(msg_node);
            }
        

            if (msg_id != SRV_SMS_INVALID_MSG_ID)
            {
                srv_sms_event_add_struct *event_data;
                MMI_BOOL int_result;
                if (msg_id < SRV_SMS_MAX_SMS_ENTRY)
                {
                    srv_sms_concat_pdu_list(
                        msg_id,
                        save_cntx->pdu_id_list,
                        save_cntx->total_pdu);
                }
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                else
                {
                    srv_tcard_op_struct read_cntx;
                    srv_sms_tcard_spdu_struct *spdu_data;
                    srv_sms_tcard_msg_node_struct *tcard_msg_node;


                    ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
                    srv_sms_concat_tcard_pdu_list(
                            msg_id,
                            save_cntx->pdu_id_list,
                            save_cntx->total_pdu);


                    //get content from pdu and add to msg node
                    spdu_data = OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                    read_cntx.start_record_id = tcard_msg_node->start_pdu_id - SRV_SMS_MAX_MSG_NUM;
                    srv_tcard_sync_read_record(&read_cntx,(CHAR*)spdu_data);           

                    srv_sms_get_content_from_pdu(
                            (char*)tcard_msg_node->content, 
                            SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH,
                            spdu_data->pdu);
                    tcard_msg_node->content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN] = 0;
                    OslMfree(spdu_data);

                    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);

                    //add content to msg_list
                    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
                    read_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;
                    read_cntx.record_num = 1;
                        
                    srv_tcard_sync_write_record(&read_cntx,(CHAR*)tcard_msg_node); 

                     
                }
            #endif

                /* Set Event data For Add Event */
                event_data = OslMalloc(sizeof(srv_sms_event_add_struct));

                event_data->msg_id = msg_id;
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    //srv_sms_tcard_msg_node_struct tcard_msg_node;
                    srv_sms_tcard_msg_node_to_msg_info(&event_data->msg_info, &tcard_msg_node);
                }
                else
            #endif
                {
	                srv_sms_msg_node_to_msg_info(&event_data->msg_info, msg_node);
                }

                

                srv_sms_clear_set_pdu_array_flag(
                    save_cntx->pdu_id_list,
                    save_cntx->total_pdu,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            #ifdef __SRV_SMS_MULTI_ADDR__
                if (msg_id >= SRV_SMS_MAX_SMS_ENTRY)
                {
                    U16 start_index;
                    U16 end_index;
                    U16 temp_index;
                    srv_tcard_op_struct cntx;
                    CHAR *buff = NULL;
                    srv_sms_update_tcard_cntx_struct *update_cntx;
                    srv_sms_tcard_msg_node_struct *msg_list; 
					srv_sms_tcard_msg_node_struct *temp_msg_node;

                    cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    update_cntx = OslMalloc(sizeof(srv_sms_update_tcard_cntx_struct));
					temp_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                    if (temp_msg_node->ext_addr_num > 0)
                    {
                        srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
                        U16 big_index = 0;
                        U16 small_index = 0xffff;
                        for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                        cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_ADDR_INFO;
                        update_cntx->msg_id = msg_id;
                        update_cntx->cntx = (void*)save_cntx;
                        update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_ADDR_LIST | SRV_SMS_UPDATE_TCARD_PDU_LIST;
                        update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_ADDR_LIST;
                        update_cntx->action_type = SRV_SMS_ACTION_SAVE;
                        update_cntx->event_data = event_data;
                        msg_list = srv_sms_get_tcard_msg_list();
                        //msg_list[msg_id - SRV_SMS_MAX_MSG_NUM];
                        temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_addr_id;

                        if(temp_index > big_index)
                        {
                            big_index = temp_index;
                        }
                        if(temp_index < small_index)
                        {
                            small_index = temp_index;
                        }
                        
                        while(srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id != SRV_SMS_INVALID_INDEX)
                        {
                            temp_index = srv_sms_tcard_addr_list[temp_index - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id;
                            if(temp_index > big_index)
                            {
                                big_index = temp_index;
                            }
                            if(temp_index < small_index)
                            {
                                small_index = temp_index;
                            }
                        }

                        
                        start_index = small_index ;
                        end_index = big_index;
                        cntx.start_record_id = start_index - SRV_SMS_MAX_ADDR_ENTRY;
                        cntx.record_num = end_index - start_index + 1;
                        buff = (CHAR*)(srv_sms_tcard_addr_list + start_index  - SRV_SMS_MAX_ADDR_ENTRY);

                        for_tcard_cntx->user_data = update_cntx;
                        for_tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
                        srv_tcard_write_record(
                                &cntx,
                                buff,
                                srv_sms_for_tcard_callback,
                                for_tcard_cntx);
                
                    }
                    else
                    {
                        /*only need to add pdu index*/
                        srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
                        U16 big_index = 0;
                        U16 small_index = 0XFFFF;
                       

                        for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                        
                        cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                        update_cntx->msg_id = msg_id;
                        update_cntx->cntx = (void*)save_cntx;
                        update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                        update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                        update_cntx->action_type = SRV_SMS_ACTION_SAVE;
                        update_cntx->event_data = event_data;
                        msg_list = srv_sms_get_tcard_msg_list();
                        temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

                        if(temp_index > big_index)
                        {
                            big_index = temp_index;
                        }
                        if(temp_index < small_index)
                        {
                            small_index = temp_index;
                        }

                        
                        while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id!= SRV_SMS_INVALID_INDEX)
                        {
                            temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;

                            if(temp_index > big_index)
                            {
                                big_index = temp_index;
                            }
                            if(temp_index < small_index)
                            {
                                small_index = temp_index;
                            }
                        }

                        
                        start_index = small_index- SRV_SMS_MAX_MSG_NUM;
                        end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                        cntx.start_record_id = start_index;
                        cntx.record_num = end_index - start_index + 1;
                        buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                        for_tcard_cntx->user_data = update_cntx;
                        for_tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
                        srv_tcard_write_record(
                                &cntx,
                                buff,
                                srv_sms_for_tcard_callback,
                                for_tcard_cntx);
                    }
                    
                }
                else
                {
                    srv_sms_save_msg_deinit(save_cntx);

                    /* Execute Message Add Interrupt Event */
                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);

                    /* Execute Callback Function */
                    save_msg_cb_data.msg_id = msg_id;

                    STORAGE_INVOKE_CALLBACK(
                        save_cntx,
                        MMI_TRUE,
                        SRV_SMS_CAUSE_NO_ERROR,
                        &save_msg_cb_data);

                    if (int_result == MMI_FALSE)
                    {
                        /* Emit Message Add Event */
                        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                    }

                    OslMfree(event_data);

                    srv_sms_handle_mem_change(MMI_FALSE);
                }
            #else /*__SRV_SMS_MULTI_ADDR__*/
            
                if (msg_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    U16 start_index;
                    U16 end_index;
                    U16 temp_index;
                    U16 big_index = 0;
                    U16 small_index = 0xFFFF;
                    srv_tcard_op_struct cntx;
                    CHAR *buff = NULL;
                    srv_sms_update_tcard_cntx_struct *update_cntx;
                    srv_sms_tcard_msg_node_struct *msg_list;
                    srv_sms_for_tcard_cntx_struct *for_tcard_cntx;

                    for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                    cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    update_cntx = OslMalloc(sizeof(srv_sms_update_tcard_cntx_struct));
                    /*only need to add pdu index*/
                    cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                    update_cntx->msg_id = msg_id;
                    update_cntx->cntx = (void*)save_cntx;
                    update_cntx->total_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                    update_cntx->curr_flag = SRV_SMS_UPDATE_TCARD_PDU_LIST;
                    update_cntx->action_type = SRV_SMS_ACTION_SAVE;
                    update_cntx->event_data = event_data;
                    msg_list = srv_sms_get_tcard_msg_list();
                    temp_index = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

                    if(temp_index > big_index)
                    {
                        big_index = temp_index;
                    }
                    if(temp_index < small_index)
                    {
                        small_index = temp_index;
                    }
                    
                    while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id!= SRV_SMS_INVALID_INDEX)
                    {
                        temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;

                        if(temp_index > big_index)
                        {
                            big_index = temp_index;
                        }
                        if(temp_index < small_index)
                        {
                            small_index = temp_index;
                        }
                    }

                    start_index = small_index - SRV_SMS_MAX_MSG_NUM;
                    end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                    cntx.start_record_id = start_index;
                    cntx.record_num = end_index - start_index + 1;
                    buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                    for_tcard_cntx->user_data = update_cntx;
                    for_tcard_cntx->callback_func = srv_sms_tcard_update_list_callback;
                    srv_tcard_write_record(
                            &cntx,
                            buff,
                            srv_sms_for_tcard_callback,
                            for_tcard_cntx);
                }
                else
                {
                    /* Free Save Content Buffer Before Execute Any Callback Function */
                    srv_sms_save_msg_deinit(save_cntx);

                    /* Execute Message Add Interrupt Event */
                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);

                    /* Execute Callback Function */
                    save_msg_cb_data.msg_id = msg_id;

                    STORAGE_INVOKE_CALLBACK(
                        save_cntx,
                        MMI_TRUE,
                        SRV_SMS_CAUSE_NO_ERROR,
                        &save_msg_cb_data);

                    if (int_result == MMI_FALSE)
                    {
                        /* Emit Message Add Event */
                        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                    }

                    OslMfree(event_data);

                    srv_sms_handle_mem_change(MMI_FALSE);

                }
            #endif/*__SRV_SMS_MULTI_ADDR__*/
            #else /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
                
                /* Free Save Content Buffer Before Execute Any Callback Function */
                srv_sms_save_msg_deinit(save_cntx);

                /* Execute Message Add Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);

                /* Execute Callback Function */
                save_msg_cb_data.msg_id = msg_id;

                STORAGE_INVOKE_CALLBACK(
                    save_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_NO_ERROR,
                    &save_msg_cb_data);

                if (int_result == MMI_FALSE)
                {
                    /* Emit Message Add Event */
                    srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                }

                OslMfree(event_data);

                srv_sms_handle_mem_change(MMI_FALSE);
            #endif
            }
            else
            {
                srv_sms_save_msg_deinit(save_cntx);

                STORAGE_INVOKE_CALLBACK(
                    save_cntx,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_MEM_FULL,
                    NULL);
             }
        }
    }
    else
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
    #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        srv_sms_del_ext_addr(save_cntx->msg_node.start_addr_id);
    #endif 
    #endif /* __SRV_SMS_MULTI_ADDR__ */

        if (save_cntx->curr_index > 0)
        {
            /* Remind the Cause For Callback */
            save_cntx->error_cause = callback_data->cause;
            /* Set the added/Deleted PDU total number */
            save_cntx->total_pdu = save_cntx->curr_index;
            /* Set the deleted Index */
            save_cntx->curr_index = 0;

            /* Clear WRITING flag, Set DELETING flag */
            srv_sms_clear_set_pdu_array_flag(
                save_cntx->pdu_id_list,
                save_cntx->total_pdu,
                SRV_SMS_NODE_LOCKING,
                MMI_TRUE);

            srv_sms_clear_set_pdu_array_flag(
                save_cntx->pdu_id_list,
                save_cntx->total_pdu,
                SRV_SMS_NODE_DELETING,
                MMI_FALSE);

            srv_sms_delete_pdu(
                save_cntx->pdu_id_list[save_cntx->curr_index],
                srv_sms_save_msg_del_callback,
                save_cntx);
        }
        else
        {
            if (CNTX_IS_ABORT(save_cntx))
            {
                result = MMI_TRUE;
            }

            srv_sms_save_msg_deinit(save_cntx);

            STORAGE_INVOKE_CALLBACK(
                save_cntx,
                result,
                error_cause,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_del_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_save_msg_del_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_save_cntx_struct *save_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_cntx = (srv_sms_save_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_DEL_CALLBACK, callback_data->result, save_cntx->curr_index);

    /* If result is TRUE, this PDU node is reset */
    if (!callback_data->result)
    {
        U16 pdu_id;

        pdu_id = save_cntx->pdu_id_list[save_cntx->curr_index];

        srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_DELETING);
    }

    save_cntx->curr_index++;

    if (save_cntx->curr_index < save_cntx->total_pdu)
    {
        srv_sms_delete_pdu(
            save_cntx->pdu_id_list[save_cntx->curr_index],
            srv_sms_save_msg_del_callback,
            save_cntx);
    }
    else
    {
        srv_sms_save_msg_deinit(save_cntx);

        STORAGE_INVOKE_CALLBACK(
            save_cntx,
            MMI_TRUE,
            save_cntx->error_cause,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_save_msg_init(srv_sms_save_cntx_struct* save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);
    srv_sms_msg_node_struct *msg_node = &save_cntx->msg_node;
    srv_sms_sim_enum sim_id = msg_data->sim_id;
    U8 pdu_len_list[SRV_SMS_MAX_SEG];
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_INIT);

    if ((msg_data->storage_type == SRV_SMS_STORAGE_SIM) &&
        (!srv_sms_is_sim_valid(sim_id)))
    {
        return SRV_SMS_CAUSE_SIM_FAILURE;
    }

    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        save_cntx->spdu_list[i] = NULL;
        save_cntx->pdu_id_list[i] = SRV_SMS_INVALID_PDU_ID;
    }

    error_cause = srv_sms_convert_msg_data_to_pdu_ext(
                    NULL,
                    pdu_len_list,
                    &save_cntx->total_pdu,
                    msg_node,
                    msg_data,
                    SRV_SMS_PACK_SAVE_NON_STD,
                    sim_id,
                    srv_sms_save_msg_get_pdu_list,
                    save_cntx);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        /* Init SPDU List */
        for (i = 0; i < save_cntx->total_pdu; i++)
        {
            save_cntx->spdu_list[i]->status = msg_data->status;
            save_cntx->spdu_list[i]->timestamp = msg_node->timestamp;
        #ifdef __SRV_SMS_MULTI_SIM__
            save_cntx->spdu_list[i]->sim_id = sim_id;
        #endif /* __SRV_SMS_MULTI_SIM__ */
        #ifdef __SRV_SMS_RESEND_COUNT__
            save_cntx->spdu_list[i]->resend_count = 0;
        #endif /* __SRV_SMS_RESEND_COUNT__ */
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            if (msg_data->status == SRV_SMS_STATUS_SENT)
            {
                save_cntx->spdu_list[i]->tp_st = SRV_SMS_SRS_NONE;
            }
            else
            {
                save_cntx->spdu_list[i]->tp_st = SRV_SMS_SRS_INVALID;
            }       
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
        }

        if (msg_data->para_flag & SRV_SMS_PARA_MSG_REF)
        {
            memcpy(save_cntx->msg_ref, msg_data->msg_ref, sizeof(save_cntx->msg_ref));
        }
        else
        {
            memset(save_cntx->msg_ref, 0, sizeof(save_cntx->msg_ref));
        }

        if (msg_data->para_flag & SRV_SMS_PARA_STATUS_REPORT)
        {
            save_cntx->report_id = msg_data->report_id;
        }
        else
        {
            save_cntx->report_id = SRV_SMS_INVALID_MSG_ID;
        }

    #ifdef __SRV_SMS_MULTI_SIM__ 
        msg_node->sim_id = sim_id;
    #endif /* __SRV_SMS_MULTI_SIM__ */

    #ifdef __SRV_SMS_MULTI_ADDR__
        msg_node->ext_addr_num = 0;
        msg_node->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
        msg_node->ext_status = SRV_SMS_STATUS_NONE;
    #endif /* __SRV_SMS_MSG_EXT_STATUS__ */
    #ifdef __SRV_SMS_RESEND_COUNT__ 
        msg_node->resend_count = 0;
    #endif /* __SRV_SMS_RESEND_COUNT__ */

        msg_node->storage_type = msg_data->storage_type;
        msg_node->start_pdu_id = SRV_SMS_INVALID_PDU_ID;

        /* Init Save Msg Context */
        save_cntx->curr_index = 0;
        save_cntx->error_cause = SRV_SMS_CAUSE_NO_ERROR;
        save_cntx->storage_type = msg_data->storage_type;
        save_cntx->sim_id = msg_data->sim_id;
    }

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_get_pdu_list
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_save_msg_get_pdu_list(U8 **pdu_list, U8 pdu_total, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_save_cntx_struct* save_cntx = (srv_sms_save_cntx_struct*)user_data;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < pdu_total; i++)
    {
        srv_sms_spdu_struct *spdu_data;

        spdu_data = OslMalloc(SRV_SMS_MAX_SPDU_SIZE);

        pdu_list[i] = spdu_data->pdu;
        save_cntx->spdu_list[i] = spdu_data;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_msg_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_save_msg_deinit(srv_sms_save_cntx_struct *save_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(save_cntx);
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_MSG_DEINIT);

    srv_sms_free_int_msg_data(msg_data);

    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        if (save_cntx->spdu_list[i] != NULL)
        {
            OslMfree(save_cntx->spdu_list[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_msg_next(srv_sms_update_cntx_struct* update_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx->curr_index < update_cntx->total_pdu)
    {
        srv_sms_read_pdu(
            update_cntx->pdu_id_list[update_cntx->curr_index],
            srv_sms_update_msg_callback,
            update_cntx);
    }
    else
    {
        srv_sms_msg_node_struct *msg_node = NULL;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	srv_sms_tcard_msg_node_struct *tcard_msg_node = NULL;
#endif
        srv_sms_event_update_struct *event_data;
        srv_sms_change_msg_status_cb_struct change_status_cb_data;
        U16 msg_id = update_cntx->msg_id;
        MMI_BOOL int_result;

        event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

        /* Get Old Msg Info */
        srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
	    {
	        tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
	    }
		else
		{
		    msg_node = srv_sms_get_msg_node(msg_id);
		}
	#else
	    msg_node = srv_sms_get_msg_node(msg_id);
	#endif
        

        if (update_cntx->update_flag & SRV_SMS_PARA_STATUS)
        {
            srv_sms_int_msg_data_struct *msg_data;

            msg_data = CNTX_GET_HD_DATA(update_cntx);

            /* Update the status in the msg list */
		#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
		if(msg_id >= SRV_SMS_MAX_MSG_NUM)
	    	{
	    	    tcard_msg_node->status = (tcard_msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | msg_data->status;
	    	}
			else
			{
			    msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | msg_data->status;
			}
		#else
		    msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | msg_data->status;
		#endif
            
        }

        /* Set Event Data For Message Change */
        event_data->msg_id = msg_id;
        event_data->change_para_flag = update_cntx->update_flag;
        srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);

        srv_sms_clear_set_pdu_array_flag(
            update_cntx->pdu_id_list,
            update_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        /* Free Update Msg Context Buffer */
        srv_sms_update_msg_deinit(update_cntx);

        /* Exec Message Update Interrupt Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);

        STORAGE_INVOKE_CALLBACK(
            update_cntx,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &change_status_cb_data);

        if (!int_result)
        {
            /* Emit Update Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }

        OslMfree(event_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_update_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_cntx_struct *update_cntx;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = callback_data->cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = (srv_sms_update_cntx_struct*)callback_data->user_data;

    if (CNTX_IS_ABORT(update_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }

    if (result)
    {
        switch (callback_data->action)
        {
            case SRV_SMS_ACTION_READ:
            {
                srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
                srv_sms_update_pdu_struct update_data;
                srv_sms_spdu_struct *spdu_data;
                srv_sms_spdu_struct *ori_spdu_data;
                U8 curr_index = update_cntx->curr_index;
                U16 pdu_id = update_cntx->pdu_id_list[curr_index];

                read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;
                spdu_data = read_pdu_cb_data->spdu_data;

                /* Clear READING flag and Set UPDATING flag for Update PDU */
                srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_READING);
                srv_sms_set_pdu_flag(pdu_id, SRV_SMS_NODE_UPDATING);

                ori_spdu_data = OslMalloc(sizeof(srv_sms_spdu_struct));

                /* Record the original Data for restoring */
                memcpy(ori_spdu_data, spdu_data, sizeof(srv_sms_spdu_struct));
                update_cntx->ori_spdu[curr_index] = ori_spdu_data;

                srv_sms_update_msg_convert_data(
                    &update_data,
                    spdu_data,
                    update_cntx);
			#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
			    update_data.tcard_spdu_data = update_cntx->tcard_pdu;
			#endif

                srv_sms_update_pdu(
                    pdu_id,
                    &update_data,
                    srv_sms_update_msg_callback,
                    update_cntx);
                break;
            }

            case SRV_SMS_ACTION_UPDATE:
            {
                update_cntx->curr_index++;

                srv_sms_update_msg_next(update_cntx);
                break;
            }

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        /* Clear All PDUs flag included the remaining PDU which don't be read */
        srv_sms_clear_set_pdu_array_flag(
            update_cntx->pdu_id_list,
            update_cntx->total_pdu,
            SRV_SMS_NODE_READING,
            MMI_TRUE);

        update_cntx->error_cause = error_cause;
        update_cntx->total_pdu = update_cntx->curr_index;
        update_cntx->curr_index = 0;

        srv_sms_update_msg_restore(update_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_restore
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_msg_restore(srv_sms_update_cntx_struct *update_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index = update_cntx->curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr_index < update_cntx->total_pdu)
    {
        srv_sms_update_pdu_struct update_data;

        update_data.spdu_data = update_cntx->ori_spdu[curr_index];
        update_data.update_flag = update_cntx->update_flag;
    #ifdef __SRV_SMS_DELIVERY_STATUS__
        if (update_cntx->update_flag & SRV_SMS_PARA_MSG_REF)
        {
            update_data.msg_ref = update_cntx->ori_msg_ref[curr_index];
        }
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */

        srv_sms_update_pdu(
            update_cntx->pdu_id_list[curr_index],
            &update_data,
            srv_sms_update_msg_restore_callback,
            update_cntx);
    }
    else
    {
        srv_sms_cause_enum error_cause;
        MMI_BOOL result = MMI_FALSE;

        error_cause = update_cntx->error_cause;

        if (CNTX_IS_ABORT(update_cntx))
        {
            result = MMI_TRUE;
        }

        srv_sms_clear_set_pdu_array_flag(
            update_cntx->pdu_id_list,
            update_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        srv_sms_update_msg_deinit(update_cntx);

        STORAGE_INVOKE_CALLBACK(
            update_cntx,
            result,
            error_cause,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_restore_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_msg_restore_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_cntx_struct *update_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = (srv_sms_update_cntx_struct*)callback_data->user_data;

    update_cntx->curr_index++;

    srv_sms_update_msg_restore(update_cntx);
}


#ifdef __SRV_SMS_DELIVERY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_srs_changed_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_update_msg_srs_changed_hdlr(srv_sms_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_cntx_struct *update_cntx;
    srv_sms_event_update_report_struct *update_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx = (srv_sms_update_cntx_struct*)event_data->user_data;
    update_info = (srv_sms_event_update_report_struct*)event_data->event_info;

    if (update_cntx->update_flag & SRV_SMS_PARA_DELIVERY_STATUS)
    {
        U16 report_id;

        report_id = update_cntx->report_id;

        if (report_id == update_info->report_id)
        {
            srv_sms_sr_get_total_status(report_id, update_cntx->sr_status);
        }
    }

    return MMI_FALSE;
}
#endif /* __SRV_SMS_DELIVERY_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_check_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_update_msg_check_data(
                    U16 msg_id,
                    srv_sms_int_msg_data_struct* msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        srv_sms_status_enum msg_status;
        srv_sms_mti_enum msg_mti;

        msg_status = srv_sms_get_msg_status(msg_id);
        msg_mti = srv_sms_status_to_mti(msg_status);

        if (msg_data->para_flag & SRV_SMS_PARA_STATUS)
        {
            srv_sms_mti_enum mti;

            mti = srv_sms_status_to_mti(msg_data->status);

            if (mti != msg_mti)
            {
                result = MMI_FALSE;
                break;
            }
        }

        if ((msg_data->para_flag & SRV_SMS_PARA_MSG_REF) &&
            (msg_mti != SRV_SMS_MTI_SUBMIT))
        {
            result = MMI_FALSE;
            break;
        }
    } while (0);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_convert_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_msg_convert_data(
                srv_sms_update_pdu_struct *update_data,
                srv_sms_spdu_struct *spdu_data,
                srv_sms_update_cntx_struct *update_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 curr_seg = update_cntx->curr_index;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_data->spdu_data = spdu_data;
    update_data->update_flag = msg_data->para_flag;

#ifdef __SRV_SMS_DELIVERY_STATUS__
    if (msg_data->para_flag & SRV_SMS_PARA_MSG_REF)
    {
        U8 msg_ref = msg_data->msg_ref[curr_seg];

        update_data->msg_ref = msg_ref;
        srv_sms_set_pdu_msg_ref(spdu_data->pdu, msg_ref);
    }

    if (msg_data->para_flag & SRV_SMS_PARA_DELIVERY_STATUS)
    {
        spdu_data->tp_st = update_cntx->sr_status[curr_seg];
    }
    else
    {
        srv_sms_status_enum ori_status = (srv_sms_status_enum)spdu_data->status;

        if ((msg_data->para_flag & SRV_SMS_PARA_STATUS) && 
            (msg_data->status == SRV_SMS_STATUS_SENT) &&
            (ori_status != SRV_SMS_STATUS_SENT))
        {
            spdu_data->tp_st = SRV_SMS_SRS_NONE;
            update_data->update_flag |= SRV_SMS_PARA_DELIVERY_STATUS;
        }
    }
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

#ifdef __SRV_SMS_RESEND_COUNT__
    if (msg_data->para_flag & SRV_SMS_PARA_RESEND_COUNT)
    {
        spdu_data->resend_count = msg_data->resend_count;
    }
#endif /* __SRV_SMS_RESEND_COUNT__ */

    if (msg_data->para_flag & SRV_SMS_PARA_STATUS)
    {
        spdu_data->status = (U8)msg_data->status;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_msg_init(
                srv_sms_update_cntx_struct* update_cntx,
                U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_cntx->total_pdu = srv_sms_get_msg_pdu_id(update_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(update_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        update_cntx->pdu_id_list,
        update_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);

    update_cntx->curr_index = 0;
    update_cntx->msg_id = msg_id;
    update_cntx->update_flag = msg_data->para_flag;

#ifdef __SRV_SMS_DELIVERY_STATUS__
    if (msg_data->para_flag & SRV_SMS_PARA_MSG_REF)
    {
        srv_sms_get_msg_ref(update_cntx->ori_msg_ref, msg_id);
    }

    if (msg_data->para_flag & SRV_SMS_PARA_DELIVERY_STATUS)
    {
        U16 report_id = msg_data->report_id;

        if (report_id == SRV_SMS_INVALID_MSG_ID)
        {
            U32 i;
        
            for (i = 0; i < (U32)update_cntx->total_pdu; i++)
            {
                update_cntx->sr_status[i] = SRV_SMS_SRS_NONE;
            }
        }
        else
        {
            srv_sms_sr_get_total_status(report_id, update_cntx->sr_status);

            srv_sms_set_interrupt_event_handler(
                EVT_ID_SRV_SMS_UPDATE_REPORT,
                srv_sms_update_msg_srs_changed_hdlr,
                update_cntx);
        }

        update_cntx->report_id = report_id;
    }
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_msg_deinit(srv_sms_update_cntx_struct *update_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(update_cntx);
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_free_int_msg_data(msg_data);

    for (i = 0; i < (U32)update_cntx->total_pdu; i++)
    {
        OslMfree(update_cntx->ori_spdu[i]);
    }

#ifdef __SRV_SMS_DELIVERY_STATUS__
    if (update_cntx->report_id != SRV_SMS_INVALID_MSG_ID)
    {
        srv_sms_clear_interrupt_event_handler(
            EVT_ID_SRV_SMS_UPDATE_REPORT,
            srv_sms_update_msg_srs_changed_hdlr,
            update_cntx);
    }
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_ext
 * DESCRIPTION
 *  1. Delete an existed message;
 *  2. If the message is not existed, the result is FALSE;
 *  3. The Callback Action Data Structure is srv_sms_delete_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
static SMS_HANDLE srv_sms_delete_msg_ext(
                        U16 msg_id,
                        MMI_BOOL is_backgroud,
                        SrvSmsCallbackFunc callback_func,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_cntx_struct *delete_cntx = NULL;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        MMI_BOOL is_valid;

        is_valid = srv_sms_is_tcard_sms_valid(msg_id - SRV_SMS_MAX_MSG_NUM);
        if(!is_valid)
        {
    #ifdef __SRV_SMS_AT_SUPPORT__
        srv_sms_enter_mmi_operating();
    #endif
         srv_sms_delete_invalid_tcard_sms(msg_id - SRV_SMS_MAX_MSG_NUM);
         
         STORAGE_ASYNC_ERR_CALLBACK(
             SRV_SMS_ACTION_DELETE,
             SRV_SMS_CAUSE_DATA_INVALID,
             user_data,
             callback_func);

         return (SMS_HANDLE)delete_cntx;
        }  
    }
#endif
    
    if (is_backgroud == MMI_TRUE)
    {
        error_cause = srv_sms_check_common_msg_error_without_at(msg_id, SRV_SMS_ACTION_DELETE);
    }
    else
    {
    #ifdef __SRV_SMS_AT_SUPPORT__
        srv_sms_enter_mmi_operating();
    #endif
    
        error_cause = srv_sms_check_common_msg_error(msg_id, SRV_SMS_ACTION_DELETE);
    }

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        delete_cntx = srv_sms_alloc_cntx(
                        (sizeof(srv_sms_delete_cntx_struct)),
                        SRV_SMS_ACTION_DELETE,
                        callback_func,
                        user_data);

        if (delete_cntx)
        {
        #ifdef __SMS_CLOUD_SUPPORT__
            U16 pdu_id;
            MMI_BOOL is_sim_msg = MMI_FALSE;
            //S32 sync_result;
        #endif
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_1, delete_cntx);

            srv_sms_delete_msg_init(
                delete_cntx,
                msg_id,
                is_backgroud);
        #ifdef __SMS_CLOUD_SUPPORT__
            /*only me sms will be support cloud */
            pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
            while (pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                if(pdu_id >= SRV_SMS_MAX_ME_SMS_ENTRY)
                {
                    is_sim_msg = MMI_TRUE;
                    break;
                }
                pdu_id = srv_sms_pdu_list[pdu_id].next_pdu_id;
            }

            if(!is_sim_msg)
            {
                pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
                while (srv_sms_pdu_list[pdu_id].next_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    pdu_id = srv_sms_pdu_list[pdu_id].next_pdu_id;
                }
            }

            srv_cloud_sync_set_store_uid(pdu_id, 
                                             NULL, 
                                             SRV_CLD_TYPE_SMS, 
                                             SRV_CLD_ACTION_DEL);
            //add trace
        #endif
            /* Delete First PDU */
            srv_sms_delete_pdu(
                delete_cntx->pdu_id_list[delete_cntx->curr_index],
                srv_sms_delete_msg_ext_callback,
                delete_cntx);
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        }
    }

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
    #ifdef __SRV_SMS_AT_SUPPORT__
        if (is_backgroud == MMI_FALSE)
        {
            srv_sms_exit_mmi_operating();
        }
    #endif /* __SRV_SMS_AT_SUPPORT__ */

        SMS_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_DELETE,
            error_cause,
            user_data,
            callback_func);
    }

    return (SMS_HANDLE)delete_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_ext_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_delete_msg_ext_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_cntx_struct *delete_cntx;
    MMI_BOOL result = callback_data->result;
    MMI_BOOL is_backgroud;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	MMI_BOOL multi_addr = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_cntx = (srv_sms_delete_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_CALLBACK, callback_data->result, delete_cntx->curr_index);

    is_backgroud = delete_cntx->is_background;

    if (result)
    {
        /* Increment Current Deleted Index */
        delete_cntx->curr_index++;

        /* Check whether all of the PDU is deleted */
        if (delete_cntx->curr_index < delete_cntx->total_pdu)
        {
            /* Delete Next PDU */
            srv_sms_delete_pdu(
                delete_cntx->pdu_id_list[delete_cntx->curr_index],
                srv_sms_delete_msg_ext_callback,
                delete_cntx);
        }
        else /* All PDU have been deleted. */
        {
            srv_sms_delete_msg_cb_struct del_msg_cb_data;
            srv_sms_event_delete_struct *event_data = NULL;
            U16 deleted_msg_id = delete_cntx->msg_id;
            MMI_BOOL is_hidden;
            MMI_BOOL int_result = MMI_FALSE;
        
        #ifdef __SRV_SMS_MULTI_ADDR__
            srv_sms_msg_node_struct *msg_node;
        #endif /* __SRV_SMS_MULTI_ADDR__ */

            is_hidden = srv_sms_is_msg_hidden(deleted_msg_id);

            if (is_hidden == MMI_FALSE)
            {
                /* Get the Event Data For Delete Event */
                event_data = OslMalloc(sizeof(srv_sms_event_delete_struct));
                event_data->msg_id = deleted_msg_id;
                srv_sms_get_msg_info(&event_data->msg_info, deleted_msg_id);
            }

        #ifdef __SRV_SMS_MULTI_ADDR__
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(deleted_msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                U16 end_id;
                srv_tcard_op_struct cntx;
                U16 start_index;
                U16 end_index;
                U16 temp_index;
                CHAR *buff = NULL;
                srv_sms_update_tcard_cntx_struct *update_cntx;
                srv_sms_tcard_msg_node_struct *msg_list;
                srv_sms_delete_msg_node_struct *delete_msg_cntx;
                    
                srv_sms_tcard_msg_node_struct *tcard_msg_node;
                tcard_msg_node = srv_sms_get_tcard_msg_node(deleted_msg_id - SRV_SMS_MAX_MSG_NUM);
                
                if(tcard_msg_node->ext_addr_num > 0) 
                {

                    srv_sms_for_tcard_cntx_struct *for_tcard_cntx;

	            multi_addr = MMI_TRUE;
		    end_id = srv_sms_del_ext_tcard_addr(tcard_msg_node->start_addr_id);
                    for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
	                delete_msg_cntx = OslMalloc(sizeof(srv_sms_delete_msg_node_struct));
	                delete_msg_cntx->is_hiden = is_hidden;
	                delete_msg_cntx->is_backgroud = is_backgroud;
	                delete_msg_cntx->delete_cntx = delete_cntx;
	                delete_msg_cntx->cause = callback_data->cause;
	                delete_msg_cntx->event_info = event_data;
                
                 
                    cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_ADDR_INFO;
                    cntx.start_record_id = tcard_msg_node->start_addr_id - SRV_SMS_MAX_ADDR_ENTRY;
                    cntx.record_num = end_id - cntx.start_record_id + 1;
                    buff = (CHAR*)(srv_sms_tcard_addr_list + cntx.start_record_id);



                    for_tcard_cntx->user_data = delete_msg_cntx;
                    for_tcard_cntx->callback_func = srv_sms_tcard_delete_list_callback;
                    srv_tcard_write_record(
                            &cntx,
                            buff,
                            srv_sms_for_tcard_callback,
                            for_tcard_cntx);
                }
                srv_sms_delete_msg_node(deleted_msg_id, NULL);
            }
            else
            {
            msg_node = srv_sms_get_msg_node(deleted_msg_id);
            srv_sms_del_ext_addr(msg_node->start_addr_id);
                srv_sms_delete_msg_node(deleted_msg_id,NULL);
            }
        #else
            msg_node = srv_sms_get_msg_node(deleted_msg_id);
            srv_sms_del_ext_addr(msg_node->start_addr_id);
            srv_sms_delete_msg_node(deleted_msg_id,NULL);
        #endif    
        #endif /* __SRV_SMS_MULTI_ADDR__ */
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            /* Delete Message Node */
            if(deleted_msg_id < SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_delete_msg_node(deleted_msg_id,NULL);
            if (is_hidden == MMI_FALSE)
            {
                /* Execute Message Delete Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
            }
        #ifdef __SRV_SMS_AT_SUPPORT__
            if (is_backgroud == MMI_FALSE)
            {
                srv_sms_exit_mmi_operating();
            }
        #endif /* __SRV_SMS_AT_SUPPORT__ */

            if (CNTX_IS_ABORT(delete_cntx))
            {
                result = MMI_FALSE;
            }

            srv_sms_cntx_callback(
                delete_cntx,
                result,
                callback_data->cause,
                &del_msg_cb_data);

            if ((is_hidden == MMI_FALSE) && (int_result == MMI_FALSE))
            {
                /* Emit Message Delete Event */
                srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
            }

            if (event_data != NULL)
            {
                OslMfree(event_data);
            }

            srv_sms_handle_mem_change(MMI_FALSE);
        }
            else
            {
                if(!multi_addr)
                {
                    srv_sms_tcard_msg_node_struct *tcard_msg_node;
	                srv_tcard_op_struct cntx;
	                
	                
	                tcard_msg_node = srv_sms_get_tcard_msg_node(deleted_msg_id - SRV_SMS_MAX_MSG_NUM);
	                srv_sms_delete_msg_node(deleted_msg_id, NULL);

                    if (is_hidden == MMI_FALSE)
                    {
                        /* Execute Message Delete Interrupt Event */
                        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
                    }
                #ifdef __SRV_SMS_AT_SUPPORT__
                    if (is_backgroud == MMI_FALSE)
                    {
                        srv_sms_exit_mmi_operating();
                    }
                #endif /* __SRV_SMS_AT_SUPPORT__ */

                    if (CNTX_IS_ABORT(delete_cntx))
                    {
                        result = MMI_FALSE;
                    }

                    srv_sms_cntx_callback(
                        delete_cntx,
                        result,
                        callback_data->cause,
                        &del_msg_cb_data);

                    if ((is_hidden == MMI_FALSE) && (int_result == MMI_FALSE))
                    {
                        /* Emit Message Delete Event */
                        srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
                    }

                    if (event_data != NULL)
                    {
                        OslMfree(event_data);
                    }

                    srv_sms_handle_mem_change(MMI_FALSE);
                }
                

            }
        #else
            if(deleted_msg_id < SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_delete_msg_node(deleted_msg_id,NULL);
            if (is_hidden == MMI_FALSE)
            {
                /* Execute Message Delete Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
            }
        #ifdef __SRV_SMS_AT_SUPPORT__
            if (is_backgroud == MMI_FALSE)
            {
                srv_sms_exit_mmi_operating();
            }
        #endif /* __SRV_SMS_AT_SUPPORT__ */

            if (CNTX_IS_ABORT(delete_cntx))
            {
                result = MMI_FALSE;
            }

            srv_sms_cntx_callback(
                delete_cntx,
                result,
                callback_data->cause,
                &del_msg_cb_data);

            if ((is_hidden == MMI_FALSE) && (int_result == MMI_FALSE))
            {
                /* Emit Message Delete Event */
                srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
            }

            if (event_data != NULL)
            {
                OslMfree(event_data);
            }

            srv_sms_handle_mem_change(MMI_FALSE);
        }
        #endif /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
        
        }
    }
    else
    {
        U16 *pdu_id_list = &delete_cntx->pdu_id_list[delete_cntx->curr_index];
        U8 remain_num = delete_cntx->total_pdu - delete_cntx->curr_index;

        srv_sms_clear_set_pdu_array_flag(
            pdu_id_list,
            remain_num,
            SRV_SMS_NODE_DELETING,
            MMI_TRUE);
    #ifdef __SRV_SMS_AT_SUPPORT__
        if (is_backgroud == MMI_FALSE)
        {
            srv_sms_exit_mmi_operating();
        }
    #endif /* __SRV_SMS_AT_SUPPORT__ */

        if (CNTX_IS_ABORT(delete_cntx))
        {
            result = MMI_TRUE;
        }

        srv_sms_cntx_callback(
            delete_cntx,
            result,
            callback_data->cause,
            NULL);
    }
}


#ifdef __SRV_SMS_ARCHIVE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_archive_msg_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_delete_archive_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_archive_cntx_struct *delete_cntx;
    srv_sms_event_delete_struct *event_data;
    srv_sms_delete_msg_cb_struct del_msg_cb_data;
    MMI_BOOL result = callback_data->result;
    MMI_BOOL int_result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_cntx = (srv_sms_delete_archive_cntx_struct*)callback_data->user_data;
    event_data = delete_cntx->event_data;

    if (result)
    {
        /* Execute Message Delete Interrupt Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
    }

    if (CNTX_IS_ABORT(delete_cntx))
    {
        result = MMI_FALSE;
    }

    srv_sms_cntx_callback(
        delete_cntx,
        result,
        callback_data->cause,
        &del_msg_cb_data);

    if (!int_result)
    {
        /* Emit Message Delete Event */
        srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, event_data);
    }

    OslMfree(event_data);
}
#endif /* __SRV_SMS_ARCHIVE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_delete_msg_init(
                            srv_sms_delete_cntx_struct* delete_cntx,
                            U16 msg_id,
                            MMI_BOOL is_background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_INIT);

    delete_cntx->total_pdu = srv_sms_get_msg_pdu_id(delete_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(delete_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        delete_cntx->pdu_id_list,
        delete_cntx->total_pdu,
        SRV_SMS_NODE_DELETING,
        MMI_FALSE);

    delete_cntx->curr_index = 0;
    delete_cntx->msg_id = msg_id;
    delete_cntx->is_background = is_background;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_bitmap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_delete_msg_bitmap_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_bitmap_cntx_struct *del_bitmap_cntx;
    srv_sms_delete_msg_bitmap_cb_struct del_bitmap_cb_data;
    MMI_BOOL result = callback_data->result;
    MMI_BOOL is_finished = MMI_TRUE;
    U16 curr_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_bitmap_cntx = (srv_sms_delete_bitmap_cntx_struct*)callback_data->user_data;
    curr_msg_id = del_bitmap_cntx->curr_msg_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_BITMAP_CALLBACK, callback_data->result);

    if (CNTX_IS_ABORT(del_bitmap_cntx))
    {
        curr_msg_id = srv_sms_get_bitmap_index(
                        (U16)(curr_msg_id + 1),
                        del_bitmap_cntx->msg_bitmap,
                        del_bitmap_cntx->bitmap_size);

        /* If all SMSs are deleted, the abort result is false */
        if (curr_msg_id == SRV_SMS_INVALID_BITMAP_INDEX)
        {
            result = MMI_FALSE;
        }
        else
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        if (result)
        {
            /* Set Deleted Bitmap For Callback */
            srv_sms_set_bitmap_index(curr_msg_id, del_bitmap_cntx->deleted_msg_bitmap);
            del_bitmap_cntx->deleted_num++;

            /* Get Next Msg ID */
            curr_msg_id = srv_sms_get_bitmap_index(
                            (U16)(curr_msg_id + 1),
                            del_bitmap_cntx->msg_bitmap,
                            del_bitmap_cntx->bitmap_size);

            if (curr_msg_id != SRV_SMS_INVALID_BITMAP_INDEX)
            {
                is_finished = MMI_FALSE;

                del_bitmap_cntx->curr_msg_id = curr_msg_id;

                srv_sms_delete_msg(
                    curr_msg_id,
                    srv_sms_delete_msg_bitmap_callback,
                    del_bitmap_cntx);
            }
        }
    }

    if (is_finished)
    {
        U8 *deleted_msg_bitmap;

        deleted_msg_bitmap = del_bitmap_cntx->deleted_msg_bitmap;

        del_bitmap_cb_data.deleted_num = del_bitmap_cntx->deleted_num;
        del_bitmap_cb_data.bitmap_size = del_bitmap_cntx->bitmap_size;
        del_bitmap_cb_data.deleted_msg_bitmap = deleted_msg_bitmap;

        srv_sms_cntx_callback(
            del_bitmap_cntx,
            result,
            callback_data->cause,
            &del_bitmap_cb_data);

        OslMfree(deleted_msg_bitmap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_status_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_change_status_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_change_status_cntx_struct *change_cntx;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = callback_data->cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_STATUS_CALLBACK, callback_data->result, callback_data->action);

    change_cntx = (srv_sms_change_status_cntx_struct*)callback_data->user_data;

    if (CNTX_IS_ABORT(change_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_STATUS_CALLBACK_1, change_cntx->curr_index);

    if (result)
    {
        switch (callback_data->action)
        {
            case SRV_SMS_ACTION_READ:
            {
                srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
                srv_sms_spdu_struct *spdu_data;
                U16 pdu_id;
                U8 ori_status;

                read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;

                pdu_id = change_cntx->pdu_id_list[change_cntx->curr_index];

                /* Clear READING flag and Set UPDATING flag for Update PDU */
                srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_READING);
                srv_sms_set_pdu_flag(pdu_id, SRV_SMS_NODE_UPDATING);

                spdu_data = read_pdu_cb_data->spdu_data;
            
                ori_status = spdu_data->status;

                change_cntx->ori_status[change_cntx->curr_index] = ori_status;

                if (ori_status == change_cntx->status)
                {
                    srv_sms_change_status_update_next(change_cntx);
                }
                else
                {
                    srv_sms_update_pdu_struct update_data;

                    spdu_data->status = (U8)change_cntx->status;

                    update_data.spdu_data = spdu_data;
                #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                    update_data.tcard_spdu_data = change_cntx->tcard_pdu;
                #endif
                    update_data.update_flag = SRV_SMS_PARA_STATUS;

                    srv_sms_update_pdu(
                        pdu_id,
                        &update_data,
                        srv_sms_change_status_callback,
                        change_cntx);

                    spdu_data->status = ori_status;
                }
                break;
            }

            case SRV_SMS_ACTION_UPDATE:
            {
                srv_sms_change_status_update_next(change_cntx);
                break;
            }

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        /* Clear All PDUs flag included the remaining PDU which don't be read */
        srv_sms_clear_set_pdu_array_flag(
            change_cntx->pdu_id_list,
            change_cntx->total_pdu,
            SRV_SMS_NODE_READING,
            MMI_TRUE);

        srv_sms_clear_set_pdu_array_flag(
            change_cntx->pdu_id_list,
            change_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        /* If it have change some PDU's status, restore it to the original status */
        if (change_cntx->curr_index > 0)
        {
            change_cntx->total_pdu = change_cntx->curr_index;
            change_cntx->curr_index = 0;

            srv_sms_clear_set_pdu_array_flag(
                change_cntx->pdu_id_list,
                change_cntx->total_pdu,
                SRV_SMS_NODE_READING,
                MMI_FALSE);

            srv_sms_read_pdu(
                change_cntx->pdu_id_list[change_cntx->curr_index],
                srv_sms_change_status_restore_callback,
                change_cntx);
        }
        else
        {
            if (CNTX_IS_ABORT(change_cntx))
            {
                result = MMI_TRUE;
            }

            STORAGE_INVOKE_CALLBACK(
                change_cntx,
                result,
                error_cause,
                NULL);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_status_update_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_change_status_update_next(srv_sms_change_status_cntx_struct* change_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_STATUS_UPDATE_NEXT, change_cntx->curr_index);

    change_cntx->curr_index++;

    if (change_cntx->curr_index < change_cntx->total_pdu)
    {
        srv_sms_read_pdu(
            change_cntx->pdu_id_list[change_cntx->curr_index],
            srv_sms_change_status_callback,
            change_cntx);
    }
    else
    {
        srv_sms_msg_node_struct *msg_node;
        srv_sms_event_update_struct *event_data;
        srv_sms_change_msg_status_cb_struct change_status_cb_data;
        U16 msg_id = change_cntx->msg_id;
        MMI_BOOL int_result;

        event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

        /* Get Old Msg Info */
        srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);

        msg_node = srv_sms_get_msg_node(msg_id);
        /* Update the status in the msg list */
        msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | change_cntx->status;

        /* Set Event Data For Message Change */
        event_data->msg_id = msg_id;
        event_data->change_para_flag = SRV_SMS_PARA_STATUS;;
        srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);

        srv_sms_clear_set_pdu_array_flag(
            change_cntx->pdu_id_list,
            change_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        /* Exec Message Update Interrupt Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);

        STORAGE_INVOKE_CALLBACK(
            change_cntx,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &change_status_cb_data);

        if (int_result == MMI_FALSE)
        {
            /* Emit Update Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }

        OslMfree(event_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_status_restore_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_change_status_restore_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_change_status_cntx_struct *change_cntx;
    U16 pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_STATUS_RESTORE_CALLBACK, callback_data->result);

    change_cntx = (srv_sms_change_status_cntx_struct*)callback_data->user_data;

    pdu_id = change_cntx->pdu_id_list[change_cntx->curr_index];

    if (callback_data->action == SRV_SMS_ACTION_READ)
    {
        srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_READING);
    }

    if (callback_data->result == MMI_TRUE)
    {
        switch (callback_data->action)
        {
            case SRV_SMS_ACTION_READ:
            {
                srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
                srv_sms_spdu_struct *spdu_data;
                U8 tmp_status;
                U8 ori_status;

                srv_sms_set_pdu_flag(pdu_id, SRV_SMS_NODE_UPDATING);

                read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;
                spdu_data = read_pdu_cb_data->spdu_data;

                tmp_status = spdu_data->status;

                ori_status = change_cntx->ori_status[change_cntx->curr_index];

                if (ori_status == spdu_data->status)
                {
                    srv_sms_change_status_restore_next(change_cntx);
                }
                else
                {
                    srv_sms_update_pdu_struct update_data;

                    spdu_data->status = ori_status;

                    update_data.spdu_data = spdu_data;
                    update_data.update_flag = SRV_SMS_PARA_STATUS;

                    srv_sms_update_pdu(
                        pdu_id,
                        &update_data,
                        srv_sms_change_status_restore_callback,
                        change_cntx);
                    spdu_data->status = tmp_status;
                }
                break;
            }

            case SRV_SMS_ACTION_UPDATE:
            {
                srv_sms_change_status_restore_next(change_cntx);
                break;
            }

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        srv_sms_change_status_restore_next(change_cntx);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_status_restore_next
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_change_status_restore_next(srv_sms_change_status_cntx_struct* change_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_STATUS_RESTORE_NEXT, change_cntx->curr_index);

    change_cntx->curr_index++;

    if (change_cntx->curr_index < change_cntx->total_pdu)
    {
        srv_sms_read_pdu(
            change_cntx->pdu_id_list[change_cntx->curr_index],
            srv_sms_change_status_restore_callback,
            change_cntx);
    }
    else
    {
        srv_sms_cause_enum error_cause;
        MMI_BOOL result = MMI_FALSE;

        error_cause = change_cntx->error_cause;

        srv_sms_clear_set_pdu_array_flag(
            change_cntx->pdu_id_list,
            change_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        if (CNTX_IS_ABORT(change_cntx))
        {
            result = MMI_TRUE;
        }

        STORAGE_INVOKE_CALLBACK(
            change_cntx,
            result,
            error_cause,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_change_msg_status_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_change_msg_status_init(
                            srv_sms_change_status_cntx_struct* change_cntx,
                            U16 msg_id,
                            srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHANGE_MSG_STATUS_INIT);

    change_cntx->total_pdu = srv_sms_get_msg_pdu_id(change_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(change_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        change_cntx->pdu_id_list,
        change_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);

    change_cntx->curr_index = 0;

    change_cntx->msg_id = msg_id;
    change_cntx->status = status;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_msg_content_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_content_async_cb_struct get_content_cb_data;
    srv_sms_get_content_cntx_struct *get_content_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_CALLBACK, callback_data->result);

    get_content_cntx = (srv_sms_get_content_cntx_struct*)callback_data->user_data;

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
        srv_sms_spdu_struct *spdu_data;
        S8 *content = get_content_cntx->content;
        U32 content_len = get_content_cntx->content_len;
        S8 *tmp_content;
        MMI_BOOL result;

        read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;

        spdu_data = read_pdu_cb_data->spdu_data;

        tmp_content = content + content_len * ENCODING_LENGTH;

        result = srv_sms_get_content_from_pdu(
                    tmp_content, 
                    (SRV_SMS_MSG_INFO_CONTENT_LEN - content_len) * ENCODING_LENGTH,
                    spdu_data->pdu);

        if (result == MMI_TRUE)
        {
            content_len = mmi_ucs2strlen(content);

            get_content_cntx->curr_index++;

            if ((content_len < SRV_SMS_MSG_INFO_CONTENT_LEN) &&
                (get_content_cntx->curr_index < get_content_cntx->total_pdu))
            {
                get_content_cntx->content_len = content_len; 

                /* Read Next SPDU Data */
                srv_sms_read_pdu(
                    get_content_cntx->pdu_id_list[get_content_cntx->curr_index],
                    srv_sms_get_msg_content_callback,
                    get_content_cntx);
            }
            else
            {
                mmi_ucs2cpy(get_content_cb_data.content, get_content_cntx->content);

                srv_sms_get_msg_content_deinit(get_content_cntx);
                
                srv_sms_cntx_callback(
                    get_content_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_UNKNOWN_ERROR,
                    &get_content_cb_data);
            }
        }
        else
        {
            mmi_ucs2cpy(get_content_cb_data.content, get_content_cntx->content);

            srv_sms_get_msg_content_deinit(get_content_cntx);

            srv_sms_cntx_callback(
                get_content_cntx,
                MMI_FALSE,
                SRV_SMS_CAUSE_UNKNOWN_ERROR,
                &get_content_cb_data);
        }
    }
    else
    {
        mmi_ucs2cpy(get_content_cb_data.content, get_content_cntx->content);

        srv_sms_get_msg_content_deinit(get_content_cntx);

        srv_sms_cntx_callback(
            get_content_cntx,
            MMI_FALSE,
            callback_data->cause,
            &get_content_cb_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_get_msg_content_init(
                            srv_sms_get_content_cntx_struct* get_content_cntx,
                            U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_INIT);

    get_content_cntx->total_pdu = srv_sms_get_msg_pdu_id(get_content_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(get_content_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        get_content_cntx->pdu_id_list,
        get_content_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);

    get_content_cntx->curr_index = 0;

    get_content_cntx->content[0] = '\0';
    get_content_cntx->content[1] = '\0';

    get_content_cntx->content_len = 0;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_content_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_msg_content_deinit(srv_sms_get_content_cntx_struct* get_content_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_DEINIT);

    srv_sms_clear_set_pdu_array_flag(
        get_content_cntx->pdu_id_list,
        get_content_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_msg_pdu_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_pdu_cb_struct read_msg_cb_data;
    srv_sms_read_msg_pdu_cntx_struct *read_msg_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_msg_cntx = (srv_sms_read_msg_pdu_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_PDU_CALLBACK, callback_data->result, read_msg_cntx->curr_index);

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
        srv_sms_msg_data_pdu_struct *msg_data = read_msg_cntx->msg_data;

        read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;

        /* Save the PDU Data */
        memcpy(
            msg_data->spdu_array[read_msg_cntx->curr_index], 
            read_pdu_cb_data->spdu_data->pdu,
            SRV_SMS_MAX_PDU_SIZE);

        /* Increment Current Read Index */
        read_msg_cntx->curr_index++;

        /* Check whether all of the PDU is read */
        if (read_msg_cntx->curr_index < read_msg_cntx->total_pdu)
        {
            /* Read Next SPDU Data */
            srv_sms_read_pdu(
                read_msg_cntx->pdu_id_list[read_msg_cntx->curr_index],
                srv_sms_read_msg_pdu_callback,
                read_msg_cntx);
        }
        else
        {
            U16 msg_id = read_msg_cntx->msg_id;

            msg_data->total_segment = read_msg_cntx->total_pdu;
            msg_data->status = srv_sms_get_msg_status(msg_id);
            msg_data->storage_type = srv_sms_get_msg_storage_type(msg_id);
            msg_data->sim_id = srv_sms_get_msg_sim_id(msg_id);
            srv_sms_get_msg_timestamp(msg_id, &msg_data->time_stamp);

            read_msg_cb_data.msg_data = read_msg_cntx->msg_data;    

            user_data = read_msg_cntx->user_data;
            callback_func = read_msg_cntx->callback_func;

            srv_sms_read_msg_pdu_deinit(read_msg_cntx);

            STORAGE_ASYNC_SUCC_CALLBACK(
                SRV_SMS_ACTION_READ,
                &read_msg_cb_data,
                user_data,
                callback_func);
        }
    }
    else
    {
        read_msg_cb_data.msg_data = read_msg_cntx->msg_data;    

        srv_sms_read_msg_pdu_deinit(read_msg_cntx);

        STORAGE_INVOKE_CALLBACK(
            read_msg_cntx,
            MMI_FALSE,
            callback_data->cause,
            &read_msg_cb_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_pdu_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_read_msg_pdu_init(
                            srv_sms_read_msg_pdu_cntx_struct* read_msg_cntx,
                            U16 msg_id,
                            srv_sms_msg_data_pdu_struct* msg_data,
                            SrvSmsCallbackFunc callback_func,
                            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_PDU_INIT);

    read_msg_cntx->total_pdu = srv_sms_get_msg_pdu_id(read_msg_cntx->pdu_id_list, msg_id);

    MMI_ASSERT(read_msg_cntx->total_pdu > 0);

    srv_sms_clear_set_pdu_array_flag(
        read_msg_cntx->pdu_id_list,
        read_msg_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);

    read_msg_cntx->curr_index = 0;

    read_msg_cntx->msg_id = msg_id;

    read_msg_cntx->msg_data = msg_data;
    read_msg_cntx->callback_func = callback_func;
    read_msg_cntx->user_data = user_data;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_pdu_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_msg_pdu_deinit(srv_sms_read_msg_pdu_cntx_struct* read_msg_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_PDU_DEINIT);

    srv_sms_clear_set_pdu_array_flag(
        read_msg_cntx->pdu_id_list,
        read_msg_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_add_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_msg_add_pdu_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_add_pdu_cb_struct msg_add_pdu_cb_data;
    srv_sms_msg_add_pdu_cntx_struct *add_msg_pdu_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_ADD_PDU_CALLBACK, callback_data->result);

    add_msg_pdu_cntx = (srv_sms_msg_add_pdu_cntx_struct*)callback_data->user_data;
    user_data = add_msg_pdu_cntx->user_data;
    callback_func = add_msg_pdu_cntx->callback_func;

    if (callback_data->result)
    {
        srv_sms_add_pdu_cb_struct *add_pdu_cb_data;
        srv_sms_msg_node_struct *msg_node;
        srv_sms_event_add_struct *add_event_data = NULL;
        srv_sms_event_update_struct *update_event_data = NULL;
        MMI_BOOL is_add_msg;
        MMI_BOOL int_result = MMI_TRUE;
        MMI_BOOL is_hidden;
        U8 curr_seg;
        U16 msg_id;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        srv_sms_tcard_msg_node_struct tcard_msg_node;
    #endif
        add_pdu_cb_data = (srv_sms_add_pdu_cb_struct*)callback_data->action_data;
        msg_node = &add_msg_pdu_cntx->msg_node;
        curr_seg = add_msg_pdu_cntx->curr_seg;

        if (msg_node->storage_type == SRV_SMS_STORAGE_UNSPECIFIC)
        {
            msg_node->storage_type = srv_sms_get_pdu_storage_type(add_pdu_cb_data->pdu_id);
        }

        if ((msg_node->storage_type == SRV_SMS_STORAGE_SIM) && 
            (msg_node->status == SRV_SMS_STATUS_UNSENT) &&
            (msg_node->number[0] == '\0'))
        {
            msg_node->status= SRV_SMS_STATUS_DRAFT;
        }
#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if (add_msg_pdu_cntx->is_search_concat)
        {
            msg_id = srv_sms_search_concatenated_sms(msg_node, curr_seg);
        }
        else
        {
            msg_id = SRV_SMS_INVALID_MSG_ID;
        }
#else
        if (add_pdu_cb_data->pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
           srv_sms_set_tcard_msg_node(msg_node,&tcard_msg_node);
            if (add_msg_pdu_cntx->is_search_concat)
            {
                msg_id = srv_sms_tcard_search_concatenated_sms(&tcard_msg_node, curr_seg);
            }
            else
            {
                msg_id = SRV_SMS_INVALID_MSG_ID;
            }
        }
        else
        {
	        if (add_msg_pdu_cntx->is_search_concat)
	        {
	            msg_id = srv_sms_search_concatenated_sms(msg_node, curr_seg);
	        }
	        else
	        {
	            msg_id = SRV_SMS_INVALID_MSG_ID;
	        }
        }
#endif
        if (msg_id == SRV_SMS_INVALID_MSG_ID)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if (add_pdu_cb_data->pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                msg_id = srv_sms_add_tcard_msg_node(&tcard_msg_node);//the msg_id + default sms num
            }
            else
        #endif
            {
	            msg_id = srv_sms_add_msg_node(msg_node);
            }

            

            is_add_msg = MMI_TRUE;
            is_hidden = add_msg_pdu_cntx->is_hiden;

            if (is_hidden)
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(add_pdu_cb_data->pdu_id >= SRV_SMS_MAX_MSG_NUM)
                {
                    srv_sms_hide_tcard_msg_node(msg_id);
                }
                else
            #endif
                {
	            srv_sms_hide_msg_node(msg_id);
	        }

                 
            }
        }
        else
        {
            is_add_msg = MMI_FALSE;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_node->storage_type == SRV_SMS_STORAGE_TCARD)
            {
                is_hidden = srv_sms_is_msg_hidden(msg_id + SRV_SMS_MAX_MSG_NUM);
            }
            else
        #endif
            {
	        is_hidden = srv_sms_is_msg_hidden(msg_id);
	    }

            
        }

        if (is_add_msg)
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_node->storage_type == SRV_SMS_STORAGE_TCARD)
            {
                U16 start_index;
                U16 end_index;
                U16 temp_index;
                U16 big_index = 0;
                U16 small_index = 0XFFFF;
                
                srv_tcard_op_struct cntx;
                CHAR *buff = NULL;
                srv_sms_receive_tcard_cntx_struct *update_cntx;
                srv_sms_tcard_msg_node_struct *tcard_msg_list;
                CHAR tmp_content[(SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH];
                srv_sms_copy_pdu_list_update_struct *list_copy_cntx; 
                srv_sms_tcard_spdu_struct *spdu_data;
                srv_tcard_op_struct read_cntx;
                srv_sms_tcard_msg_node_struct *tmp_msg_node;
                srv_sms_for_tcard_cntx_struct *for_tcard_cntx;

                for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                update_cntx = (srv_sms_receive_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_receive_tcard_cntx_struct));
                srv_sms_concat_tcard_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);


                //get the content from tcard pdu
                spdu_data = OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                tmp_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                read_cntx.start_record_id = tmp_msg_node->start_pdu_id - SRV_SMS_MAX_MSG_NUM;
                srv_tcard_sync_read_record(&read_cntx,(CHAR*)spdu_data);           

                srv_sms_get_content_from_pdu(
                        (char*)tmp_msg_node->content, 
                        SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH,
                        spdu_data->pdu);
                tmp_msg_node->content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN] = 0;
                OslMfree(spdu_data);
                //add the content to msg list file(tcard msg node)
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
                read_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;
                read_cntx.record_num = 1;
                    
                srv_tcard_sync_write_record(&read_cntx,(CHAR*)tmp_msg_node);

                update_cntx->msg_id = msg_id;
                update_cntx->is_add = MMI_TRUE;
                update_cntx->is_hiden = is_hidden;
                update_cntx->callback_func = callback_func;
                update_cntx->user_data = user_data;
                update_cntx->pdu_id = add_pdu_cb_data->pdu_id;
                tcard_msg_list = srv_sms_get_tcard_msg_list();
                temp_index = tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

                if(temp_index > big_index)
                {
                    big_index = temp_index;
                }
                if(temp_index < small_index)
                {
                    small_index = temp_index;
                }
                
                while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id!= SRV_SMS_INVALID_INDEX)
                {
                    temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                    if(temp_index > big_index)
                    {
                        big_index = temp_index;
                    }
                    if(temp_index < small_index)
                    {
                        small_index = temp_index;
                    }
                }

                start_index = small_index  - SRV_SMS_MAX_MSG_NUM;
                end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                cntx.start_record_id = start_index;
                cntx.record_num = end_index - start_index + 1;
                buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                for_tcard_cntx->user_data = update_cntx;
                for_tcard_cntx->callback_func = srv_sms_tcard_receive_list_update_callback;
                srv_tcard_write_record(
                        &cntx,
                        buff,
                        srv_sms_for_tcard_callback,
                        for_tcard_cntx);
                
            }
            else
        #endif
            {
                srv_sms_concat_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
                if (!is_hidden)
                {
                    /* Exec Add Msg Interrupt Event */
                    add_event_data = OslMalloc(sizeof(srv_sms_event_add_struct));
                    add_event_data->msg_id = msg_id;
                    srv_sms_get_msg_info(&add_event_data->msg_info, msg_id);

                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
                }
            }       
            
        }
        else
        {
            if (!is_hidden)
            {
                /* Exec Change Msg Interrupt Event */
                update_event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

                /* Get Old Msg Info */
                srv_sms_get_msg_info(&update_event_data->old_msg_info, msg_id);
            }


         #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_node->storage_type == SRV_SMS_STORAGE_TCARD)
            {
                srv_sms_concat_tcard_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
            }
            else
         #endif
            {
                /* Need to Update Messag Node (Content) First */
                srv_sms_update_msg_node(msg_id, msg_node, curr_seg);
                srv_sms_concat_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
            }
        

        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_node->storage_type == SRV_SMS_STORAGE_TCARD)
            {
                U16 start_index;
                U16 end_index;
                U16 temp_index;
                U16 big_index = 0;
                U16 small_index = 0XFFFF;
                srv_tcard_op_struct cntx;
                CHAR *buff = NULL;
                srv_sms_receive_tcard_cntx_struct *update_cntx;
                srv_sms_tcard_msg_node_struct *tcard_msg_list;
                srv_sms_for_tcard_cntx_struct *for_tcard_cntx;

                for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
                cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                
                cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                update_cntx = (srv_sms_receive_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_receive_tcard_cntx_struct));
                srv_sms_concat_tcard_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
                update_cntx->msg_id = msg_id;
                update_cntx->is_add = MMI_TRUE;
                update_cntx->is_hiden = is_hidden;
                update_cntx->callback_func = callback_func;
                update_cntx->user_data = user_data;
                update_cntx->pdu_id = add_pdu_cb_data->pdu_id;
                tcard_msg_list = srv_sms_get_tcard_msg_list();
                temp_index = tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;
                if(temp_index > big_index)
                {
                    big_index = temp_index;
                }
                if(temp_index < small_index)
                {
                    small_index = temp_index;
                }
                
                while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id!= SRV_SMS_INVALID_INDEX)
                {
                    temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                    if(temp_index > big_index)
                    {
                        big_index = temp_index;
                    }
                    if(temp_index < small_index)
                    {
                        small_index = temp_index;
                    }
                }

                
                start_index = small_index - SRV_SMS_MAX_MSG_NUM;
                end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                cntx.start_record_id = start_index;
                cntx.record_num = end_index - start_index + 1;
                buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                for_tcard_cntx->user_data = update_cntx;
                for_tcard_cntx->callback_func = srv_sms_tcard_receive_list_update_callback;
                srv_tcard_write_record(
                        &cntx,
                        buff,
                        srv_sms_for_tcard_callback,
                        for_tcard_cntx);

            }
            else
        #endif
            {
                if (!is_hidden)
                {
                    update_event_data->msg_id = msg_id;
                    update_event_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STATUS | SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_CONTENT);
                    srv_sms_get_msg_info(&update_event_data->new_msg_info, msg_id);

                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, update_event_data);
                }
            }
            
        }

        OslMfree(add_msg_pdu_cntx);

    #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        msg_add_pdu_cb_data.msg_id = msg_id;
        msg_add_pdu_cb_data.pdu_id = add_pdu_cb_data->pdu_id;

        srv_sms_succ_callback(
            SRV_SMS_ACTION_SAVE,
            &msg_add_pdu_cb_data,
            user_data,
            callback_func);

        if (!int_result)
        {
            if (is_add_msg)
            {
                /* Exec Add Msg Event */
                srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
            }
            else
            {
                /* Exec Change Msg Event */
                srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, update_event_data);
            }
        }

        if (add_event_data != NULL)
        {
            OslMfree(add_event_data);
        }

        if (update_event_data != NULL)
        {
            OslMfree(update_event_data);
        }

        srv_sms_handle_mem_change(MMI_FALSE);
    #else
        if(msg_node->storage_type != SRV_SMS_STORAGE_TCARD)
        {
            msg_add_pdu_cb_data.msg_id = msg_id;
            msg_add_pdu_cb_data.pdu_id = add_pdu_cb_data->pdu_id;

            srv_sms_succ_callback(
                SRV_SMS_ACTION_SAVE,
                &msg_add_pdu_cb_data,
                user_data,
                callback_func);

            if (!int_result)
            {
                if (is_add_msg)
                {
                    /* Exec Add Msg Event */
                    srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_event_data);
                }
                else
                {
                    /* Exec Change Msg Event */
                    srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, update_event_data);
                }
            }

            if (add_event_data != NULL)
            {
                OslMfree(add_event_data);
            }

            if (update_event_data != NULL)
            {
                OslMfree(update_event_data);
            }

            srv_sms_handle_mem_change(MMI_FALSE);
        }
    #endif
    }
    else
    {
        OslMfree(add_msg_pdu_cntx);

        msg_add_pdu_cb_data.msg_id = SRV_SMS_INVALID_MSG_ID;
        msg_add_pdu_cb_data.pdu_id = SRV_SMS_INVALID_PDU_ID;
    
        srv_sms_callback(
            SRV_SMS_ACTION_SAVE,
            MMI_FALSE,
            callback_data->cause,
            &msg_add_pdu_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_append_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_msg_append_pdu_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_add_pdu_cb_struct append_msg_cb_data;
    srv_sms_msg_add_pdu_cntx_struct *append_msg_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_APPEND_PDU_CALLBACK, callback_data->result);

    append_msg_cntx = (srv_sms_msg_add_pdu_cntx_struct*)callback_data->user_data;
    user_data = append_msg_cntx->user_data;
    callback_func = append_msg_cntx->callback_func;

    if (callback_data->result)
    {
        srv_sms_add_pdu_cb_struct *add_pdu_cb_data;
        U16 msg_id = append_msg_cntx->msg_id;
        srv_sms_msg_node_struct *msg_node;
        U8 curr_seg;
        srv_sms_event_update_struct *event_data = NULL;
        MMI_BOOL is_hidden;
        MMI_BOOL int_result = MMI_TRUE;

        add_pdu_cb_data = (srv_sms_add_pdu_cb_struct*)callback_data->action_data;

        is_hidden = srv_sms_is_msg_hidden(msg_id);

        if (!is_hidden)
        {
            event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

            /* Get Old Msg Info */
            srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);
        }

        msg_node = &append_msg_cntx->msg_node;
        curr_seg = append_msg_cntx->curr_seg;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__ 
        if (msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_update_tcard_msg_node(msg_id, msg_node, curr_seg); 
            srv_sms_concat_tcard_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
        }
        else
        {
            srv_sms_update_msg_node(msg_id, msg_node, curr_seg);   
            srv_sms_concat_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
        }
    #else
        srv_sms_update_msg_node(msg_id, msg_node, curr_seg);   
        srv_sms_concat_pdu_to_msg(msg_id, add_pdu_cb_data->pdu_id);
    #endif
        

        OslMfree(append_msg_cntx);
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_tcard_msg_node_struct *tcard_msg_list;
            U16 temp_index;
            U16 start_index;
            U16 end_index;
            U16 big_index = 0;
            U16 small_index = 0XFFFF;
            
            srv_tcard_op_struct cntx;
            CHAR *buff = NULL;
            srv_sms_receive_tcard_append_cntx_struct *update_cntx;
            srv_sms_for_tcard_cntx_struct *for_tcard_cntx; 
            
            for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));

            update_cntx = (srv_sms_receive_tcard_append_cntx_struct*)OslMalloc(sizeof(srv_sms_receive_tcard_append_cntx_struct));
            update_cntx->msg_id = msg_id;
            update_cntx->event_data = event_data;
            update_cntx->is_hiden = is_hidden;
            update_cntx->callback_func = callback_func;
            update_cntx->user_data = user_data;
            update_cntx->pdu_id = add_pdu_cb_data->pdu_id;
            tcard_msg_list = srv_sms_get_tcard_msg_list();
            temp_index = tcard_msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;
            if(temp_index > big_index)
            {
                big_index = temp_index;
            }
            if(temp_index < small_index)
            {
                small_index = temp_index;
            }
            
            while(srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id!= SRV_SMS_INVALID_INDEX)
            {
                temp_index = srv_sms_tcard_pdu_list[temp_index - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                if(temp_index > big_index)
                {
                    big_index = temp_index;
                }
                if(temp_index < small_index)
                {
                    small_index = temp_index;
                }
            }           
            start_index = small_index  - SRV_SMS_MAX_MSG_NUM;
            end_index = big_index - SRV_SMS_MAX_MSG_NUM;
            cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
            cntx.start_record_id = start_index;
            cntx.record_num = end_index - start_index + 1;
            buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

            for_tcard_cntx->user_data = update_cntx;
            for_tcard_cntx->callback_func = srv_sms_tcard_receive_append_list_update_callback;
            srv_tcard_write_record(
                    &cntx,
                    buff,
                    srv_sms_for_tcard_callback,
                    for_tcard_cntx);
        }
        else
    #endif
        {
            if (!is_hidden)
            {
                /* Exec Change Msg Interrupt Event */
                event_data->msg_id = msg_id;
                event_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STATUS | SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_CONTENT_BUFF);
                srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);

                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
            }

            append_msg_cb_data.pdu_id = add_pdu_cb_data->pdu_id;

            srv_sms_succ_callback(
                SRV_SMS_ACTION_UPDATE,
                &append_msg_cb_data,
                user_data,
                callback_func);

            /* Exec Change Msg Event */
            if (!int_result)
            {
                srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
            }

            if (event_data != NULL)
            {
                OslMfree(event_data);
            }

            srv_sms_handle_mem_change(MMI_FALSE);
        }       
        
    }
    else
    {
        OslMfree(append_msg_cntx);

        append_msg_cb_data.pdu_id = SRV_SMS_INVALID_PDU_ID;

        srv_sms_callback(
            SRV_SMS_ACTION_UPDATE,
            MMI_FALSE,
            callback_data->cause,
            &append_msg_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_delete_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_msg_delete_pdu_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_delete_pdu_cntx_struct *del_msg_pdu_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_DELETE_PDU_CALLBACK, callback_data->result);

    del_msg_pdu_cntx = (srv_sms_msg_delete_pdu_cntx_struct*)callback_data->user_data;
    user_data = del_msg_pdu_cntx->user_data;
    callback_func = del_msg_pdu_cntx->callback_func;

    if (callback_data->result)
    {
        srv_sms_msg_delete_pdu_cb_struct msg_del_pdu_cb_data;
        U16 msg_id = del_msg_pdu_cntx->msg_id;
        U16 is_delete = MMI_FALSE;
        U16 event_id = 0;
        void *event_info = NULL;
        MMI_BOOL int_result = MMI_TRUE;     
        MMI_BOOL is_hidden;

        OslMfree(del_msg_pdu_cntx);

        if (srv_sms_msg_list[msg_id].start_pdu_id == SRV_SMS_INVALID_PDU_ID)
        {
            is_delete = MMI_TRUE;
        }

        is_hidden = srv_sms_is_msg_hidden(msg_id);

        if (is_hidden)
        {
            if (is_delete)
            {
                srv_sms_delete_msg_node(msg_id,NULL);
            }
        }
        else
        {
            if (is_delete)
            {
                srv_sms_event_delete_struct *del_info;

                del_info = OslMalloc(sizeof(srv_sms_event_delete_struct));

                del_info->msg_id = msg_id;
                srv_sms_get_msg_info(&del_info->msg_info, msg_id);

                srv_sms_delete_msg_node(msg_id,NULL);

                event_id = EVT_ID_SRV_SMS_DEL_MSG;
                event_info = del_info;
            }
            else
            {
                srv_sms_event_update_struct *update_info;

                update_info = OslMalloc(sizeof(srv_sms_event_update_struct));

                /* Get Old Msg Info */
                srv_sms_get_msg_info(&update_info->old_msg_info, msg_id);

                update_info->msg_id = msg_id;
                update_info->change_para_flag = (srv_sms_para_enum)0xFFFFFFFF; 
                srv_sms_get_msg_info(&update_info->new_msg_info, msg_id);

                event_id = EVT_ID_SRV_SMS_UPDATE_MSG;
                event_info = update_info;
            }

            /* Exec Delete / Update Msg Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(event_id, event_info);
        }

        srv_sms_succ_callback(
            SRV_SMS_ACTION_DELETE,
            &msg_del_pdu_cb_data,
            user_data,
            callback_func);

        if (!int_result)
        {
        #ifdef __SRV_SMS_AT_SUPPORT__
            if(in_atcm_delete == 0)
            {
        #endif
                srv_sms_emit_event(event_id, event_info);
        #ifdef __SRV_SMS_AT_SUPPORT__
            }
        #endif
        }

        if (event_info)
        {
            OslMfree(event_info);
        }

        srv_sms_handle_mem_change(MMI_FALSE);
    }
    else
    {
        OslMfree(del_msg_pdu_cntx);
    
        srv_sms_error_callback(
            SRV_SMS_ACTION_SAVE,
            callback_data->cause,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_update_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_msg_update_pdu_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_update_pdu_cntx_struct *update_msg_pdu_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_UPDATE_PDU_CALLBACK, callback_data->result);

    update_msg_pdu_cntx = (srv_sms_msg_update_pdu_cntx_struct*)callback_data->user_data;
    user_data = update_msg_pdu_cntx->user_data;
    callback_func = update_msg_pdu_cntx->callback_func;

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_msg_update_pdu_cb_struct msg_update_pdu_cb_data;
        U16 msg_id;
        srv_sms_event_update_struct *event_data;
        MMI_BOOL int_result;

        event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

        msg_id = srv_sms_get_msg_id_by_pdu(update_msg_pdu_cntx->pdu_id);

        /* Get Old Msg Info */
        srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);

        srv_sms_update_msg_status(msg_id);

        event_data->change_para_flag = SRV_SMS_PARA_STATUS;
        srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);

        OslMfree(update_msg_pdu_cntx);

        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);

        srv_sms_succ_callback(
            SRV_SMS_ACTION_UPDATE,
            &msg_update_pdu_cb_data,
            user_data,
            callback_func);

        if (int_result == MMI_FALSE)
        {
#ifdef __SRV_SMS_AT_SUPPORT__
            if(in_atcm_cmgl == 0)
            {
#endif
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
#ifdef __SRV_SMS_AT_SUPPORT__                
        }
#endif
        }


        OslMfree(event_data);

        srv_sms_handle_mem_change(MMI_FALSE);
    }
    else
    {
        OslMfree(update_msg_pdu_cntx);
    
        srv_sms_error_callback(
            SRV_SMS_ACTION_UPDATE,
            callback_data->cause,
            user_data,
            callback_func);
    }
}


#ifdef __SRV_SMS_DELIVERY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_sr_status_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_sr_status_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_srs_cntx_struct *update_srs_cntx;
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_srs_cntx = (srv_sms_update_srs_cntx_struct*)callback_data->user_data;
    pdu_id = update_srs_cntx->pdu_id;
    callback_func = update_srs_cntx->callback_func;
    user_data  = update_srs_cntx->user_data;

    if (callback_data->result)
    {
        switch (callback_data->action)
        {
            case SRV_SMS_ACTION_READ:
            {
                srv_sms_read_pdu_cb_struct *read_data;
                srv_sms_spdu_struct *spdu_data;
                srv_sms_update_pdu_struct update_data;

                read_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;

                spdu_data = read_data->spdu_data;
                spdu_data->tp_st = (U8)update_srs_cntx->tp_st;

                update_data.spdu_data = spdu_data;
                update_data.update_flag = SRV_SMS_PARA_DELIVERY_STATUS;

                srv_sms_update_pdu(
                    pdu_id,
                    &update_data,
                    srv_sms_update_sr_status_callback,
                    update_srs_cntx);
                break;
            }

            case SRV_SMS_ACTION_UPDATE:
            {
                U16 msg_id = update_srs_cntx->msg_id;
                srv_sms_event_update_struct event_data;
                srv_sms_sr_status_enum new_srs;
                MMI_BOOL int_result = MMI_TRUE;

                new_srs = srv_sms_get_delivery_status(msg_id);

                if (new_srs != update_srs_cntx->old_sts)
                {
                    srv_sms_msg_info_struct *old_info = &event_data.old_msg_info;
                    srv_sms_msg_info_struct *new_info = &event_data.new_msg_info;

                    event_data.msg_id = msg_id;
                    event_data.change_para_flag = SRV_SMS_PARA_DELIVERY_STATUS;

                    srv_sms_get_msg_info(old_info, msg_id);
                    memcpy(new_info, old_info, sizeof(srv_sms_msg_info_struct));

                    old_info->sr_status = update_srs_cntx->old_sts;
                    new_info->sr_status = new_srs;

                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);
                }

                OslMfree(update_srs_cntx);

                srv_sms_succ_callback(
                    SRV_SMS_ACTION_UPDATE,
                    NULL,
                    user_data,
                    callback_func);

                if (!int_result)
                {
                    srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);
                }

                break;
            }

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        if (callback_data->cause == SRV_SMS_CAUSE_OP_CONFLICT)
        {
            srv_sms_set_pdu_trigger(
                update_srs_cntx->pdu_id,
                SRV_SMS_ACTION_UPDATE,
                srv_sms_update_sr_status_trigger,
                update_srs_cntx);
        }
        else
        {
            OslMfree(update_srs_cntx);

            srv_sms_error_callback(
                SRV_SMS_ACTION_UPDATE,
                callback_data->cause,
                user_data,
                callback_func);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_sr_status_trigger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_sr_status_trigger(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_srs_cntx_struct *update_srs_cntx;
    U16 pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    update_srs_cntx = (srv_sms_update_srs_cntx_struct*)user_data;
    pdu_id = update_srs_cntx->pdu_id;

    srv_sms_read_pdu(
        pdu_id,
        srv_sms_update_sr_status_callback,
        update_srs_cntx);
}

#endif /* __SRV_SMS_DELIVERY_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_msg_attribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_query_msg_attribute(
                U16 *msg_id_list,
                U16 *msg_num,
                srv_sms_query_enum query_flag,
                srv_sms_query_struct *query_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total_num = *msg_num;
    U16 num_count = 0;
    U16 msg_id;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_ATTRIBUTE, query_flag);

    for (i = 0; i < total_num; i++)
    {
        msg_id = msg_id_list[i];
    
        if (srv_sms_query_is_match(msg_id, query_flag, query_data) == MMI_TRUE)
        {
            msg_id_list[num_count++] = msg_id;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_QUERY_MSG_ATTRIBUTE_1, num_count);

    *msg_num = num_count;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_query_is_match
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_query_is_match(
                    U16 msg_id,
                    srv_sms_query_enum query_flag,
                    srv_sms_query_struct *query_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_node_struct *curr_node = &srv_sms_msg_list[msg_id];
    MMI_BOOL result = MMI_FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (query_flag)
    {
        case SRV_SMS_QUERY_STATUS:
        {
        #ifdef __SRV_SMS_MULTI_ADDR__
            srv_sms_status_enum status = srv_sms_get_msg_node_status(curr_node);
        #else /* __SRV_SMS_MULTI_ADDR__ */
            srv_sms_status_enum status = (srv_sms_status_enum)curr_node->status;
        #endif /* __SRV_SMS_MULTI_ADDR__ */

            if (status & query_data->status)
            {
                result = MMI_TRUE;
            }
            break;
        }

        case SRV_SMS_QUERY_MTI:
            if (curr_node->mti == query_data->mti)
            {
                result = MMI_TRUE;
            }
            break;

        case SRV_SMS_QUERY_STORAGE_TYPE:
            if (curr_node->storage_type == query_data->storage_type)
            {
                result = MMI_TRUE;
            }
            break;

        case SRV_SMS_QUERY_PID:
            if (curr_node->pid == query_data->pid)
            {
                result = MMI_TRUE;
            }
            break;

    #ifdef __SRV_SMS_MULTI_SIM__
        case SRV_SMS_QUERY_SIM_ID:
            if (curr_node->sim_id == query_data->sim_id)
            {
                result = MMI_TRUE;
            }
            break;
    #endif /* __SRV_SMS_MULTI_SIM__ */

        case SRV_SMS_QUERY_TIMESTAMP:
        {
            U16 upper_time_int;
            U16 lower_time_int;

            upper_time_int = mmi_dt_mytime_2_utc_sec(&query_data->upper_time, MMI_FALSE);
            lower_time_int = mmi_dt_mytime_2_utc_sec(&query_data->lower_time, MMI_FALSE);
        
            if ((upper_time_int >= curr_node->timestamp) && (lower_time_int <= curr_node->timestamp))
            {
                result = MMI_TRUE;
            }
            break;
        }

        case SRV_SMS_QUERY_NUMBER:
        {
            U16 ucs2_num[SRV_SMS_MAX_ADDR_LEN + 1];

            mmi_asc_to_ucs2((S8*)ucs2_num, curr_node->number);

            if (srv_phb_compare_number(ucs2_num, (U16*)query_data->number) == MMI_TRUE)
            {
                result = MMI_TRUE;
            }
            break;
        }

    #ifdef __SRV_SMS_MSG_INFO_CONTENT__
        case SRV_SMS_QUERY_CONTENT:
    #endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
        default:
            result = MMI_TRUE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sort_msg_timestamp(
                U16 *msg_id_array,
                U16 msg_num,
                srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SORT_MSG_TIMESTAMP, msg_num, order_flag);

    switch (order_flag)
    {
        case SRV_SMS_ORDER_ASC:
            srv_sms_sort_msg_timestamp_asc(msg_id_array, msg_num);
            break;

        case SRV_SMS_ORDER_DESC:
        case SRV_SMS_ORDER_DEFAULT:
        default:
            srv_sms_sort_msg_timestamp_desc(msg_id_array, msg_num);
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/

static void srv_sms_sort_msg_timestamp_int(U16 *msg_id_array, U16 msg_num, MMI_BOOL flag)//  true for desc, false for asc
{
    /*----------------------------------------------------------------*/
    /* Local Variables*/
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    /*----------------------------------------------------------------*/
    /* Code Body                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id_array != NULL) && (msg_num > 1))
    {
        for (i = 0; i + 1 < msg_num; i++)
        {
            U16 temp_msg_id = msg_id_array[i];
            U32 index = i;
            U32 time;

            time = srv_sms_get_msg_timestamp_utc_sec(temp_msg_id);
            for (j = i + 1; j < msg_num; j++)
            {
                U32 curr_time;
                curr_time = srv_sms_get_msg_timestamp_utc_sec(msg_id_array[j]);
                if (((curr_time > time)&&(flag == MMI_TRUE)) || ((curr_time > time)&&(flag == MMI_TRUE)))
                {
                    time = curr_time;
                    index = j;
                }
            }

            if (index != i)
            {
                msg_id_array[i] = msg_id_array[index];
                msg_id_array[index] = temp_msg_id;
            }
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp_asc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sort_msg_timestamp_asc(U16 *msg_id_array, U16 msg_num)
{
    srv_sms_sort_msg_timestamp_int(msg_id_array, msg_num, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sort_msg_timestamp_desc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sort_msg_timestamp_desc(U16 *msg_id_array, U16 msg_num)
{
    srv_sms_sort_msg_timestamp_int(msg_id_array, msg_num, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_reply_path_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_msg_reply_path_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_reply_path_cb_struct get_reply_cb_data;
    srv_sms_get_reply_path_cntx_struct *reply_path_cntx;
    void *user_data;
    SrvSmsCallbackFunc callback_func;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_CONTENT_CALLBACK, callback_data->result);

    reply_path_cntx = (srv_sms_get_reply_path_cntx_struct*)callback_data->user_data;
    user_data = reply_path_cntx->user_data;
    callback_func = reply_path_cntx->callback_func;

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
        srv_sms_spdu_struct *spdu_data;

        read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;

        spdu_data = read_pdu_cb_data->spdu_data;

        result = srv_sms_get_reply_path_from_pdu(
                    &get_reply_cb_data.reply_path,
                    get_reply_cb_data.sc_addr,
                    spdu_data->pdu);

        if (result == MMI_FALSE)
        {
            error_cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
        }
    }
    else
    {
        get_reply_cb_data.reply_path = MMI_FALSE;
        get_reply_cb_data.sc_addr[0] = '\0';

        error_cause = callback_data->cause;
    }

    OslMfree(reply_path_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_GET_REPLY_PATH,
        result,
        error_cause,
        &get_reply_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_add_msg_into_list(
            U16 *msg_id_list,
            U16 curr_num,
            U16 max_num,
            U16 add_msg_id,
            srv_sms_sort_enum sort_flag,
            srv_sms_order_enum order_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_INTO_LIST, curr_num, max_num, add_msg_id, sort_flag, order_flag);

    switch (sort_flag)
    {
        case SRV_SMS_SORT_TIMESTAMP:
        {
            switch (order_flag)
            {
                case SRV_SMS_ORDER_ASC:
                    break;

                case SRV_SMS_ORDER_DEFAULT:
                case SRV_SMS_ORDER_DESC:
                default:
                    srv_sms_add_msg_into_list_by_desc_timestap(
                        msg_id_list,
                        curr_num,
                        max_num,
                        add_msg_id);
                    break;
            }    
            break;
        }

        default:
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_delete_msg_from_list(
            U16 *msg_id_list,
            U16 msg_num,
            U16 del_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_FROM_LIST, msg_num, del_msg_id);

    if (msg_num > 0)
    {
        for (i = 0; i < msg_num; i++)
        {
            if (msg_id_list[i] == del_msg_id)
            {
                result = MMI_TRUE;
                break;
            }
        }

        if (result == MMI_TRUE)
        {
            for (; i + 1 < msg_num; i++)
            {
                msg_id_list[i] = msg_id_list[i + 1];
            }

            msg_id_list[msg_num - 1] = SRV_SMS_INVALID_MSG_ID;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_into_list_by_desc_timestap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_add_msg_into_list_by_desc_timestap(
                U16 *msg_id_list,
                U16 curr_num,
                U16 max_num,
                U16 add_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_INTO_LIST_BY_DESC_TIMESTAP);

    if (curr_num < max_num)
    {
        S32 i;
        S32 j;
        U32 new_timestamp = srv_sms_get_msg_timestamp_utc_sec(add_msg_id);

        for (i = 0; i < (S32)curr_num; i++)
        {
            U32 comp_timestamp;

            comp_timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id_list[i]);

            if (new_timestamp > comp_timestamp)
            {
                break;
            }
        }

        for (j = (curr_num - 1); j >= (S32)i; j--)
        {
            msg_id_list[j + 1] = msg_id_list[j];
        }

        msg_id_list[i] = add_msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_common_msg_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_check_common_msg_error(U16 msg_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_COMMON_MSG_ERROR, msg_id, action);

    error_cause = srv_sms_check_common_msg_error_without_at(msg_id, action);

#ifdef __SRV_SMS_AT_SUPPORT__
    if ((error_cause == SRV_SMS_CAUSE_NO_ERROR) && (srv_sms_is_in_at_cmd_operating() == MMI_TRUE))
    {
        error_cause = SRV_SMS_CAUSE_AT_CONFLICT;
    }
#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_COMMON_MSG_ERROR_1, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_common_msg_error_without_at
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_check_common_msg_error_without_at(U16 msg_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage_cntx.is_ready == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_NOT_READY;
    }
    else if (srv_sms_is_msg_exist_ext(msg_id) == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
    }
    else if (srv_sms_check_msg_op_conflict(msg_id, action) == MMI_TRUE)
    {
        error_cause = SRV_SMS_CAUSE_OP_CONFLICT;
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_NO_ERROR;
    }

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_handle_mem_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_handle_mem_change(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    MMI_BOOL is_me_full;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	MMI_BOOL is_tcard_full = MMI_TRUE;
#endif
    U32 i;
    U32 mask ;
    U32 curr_avail_type;
    U32 prev_avail_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    is_me_full = srv_sms_is_memory_full(SRV_SMS_STORAGE_ME, SRV_SMS_SIM_1);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(storage_cntx.is_tsms_ready)
    {
        is_tcard_full = srv_sms_is_memory_full(SRV_SMS_STORAGE_TCARD, SRV_SMS_SIM_1);
    }
    
#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_HANDLE_MEM_CHANGE, is_me_full, MMI_FALSE);

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        srv_sms_sim_enum sim_id;
        U32 curr_full_type = SRV_SMS_MEM_NONE;
        U32 prev_full_type;

        if (is_me_full)
        {
            curr_full_type |= SRV_SMS_MEM_ME_ONLY;
        }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(storage_cntx.is_tsms_ready)
        {
            if (is_tcard_full)
	    {
	        curr_full_type |= SRV_SMS_MEM_TCARD_ONLY;
	    }
        }
        else
        {
            if(is_me_full)
            {
                curr_full_type |= SRV_SMS_MEM_TCARD_ONLY;
            }
        }
#endif

        sim_id = srv_sms_sim_index_to_sim_id(i);

        if (memory_status->is_sim_valid[i])
        {
            MMI_BOOL is_sim_full;

            is_sim_full = srv_sms_is_memory_full(SRV_SMS_STORAGE_SIM, sim_id);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_HANDLE_MEM_CHANGE_1, is_sim_full, MMI_TRUE);

            if (is_sim_full)
            {
                curr_full_type |= SRV_SMS_MEM_SIM_ONLY;
            }
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_HANDLE_MEM_CHANGE_1, MMI_TRUE, MMI_FALSE);

            /* If SIM Card is invalid and ME full, consider it as Normal full */
            if (is_me_full)
            {
                curr_full_type |= SRV_SMS_MEM_SIM_ONLY;
            }
        }

        prev_full_type = memory_status->mem_full_type[i];
        memory_status->mem_full_type[i] = (srv_sms_mem_enum)curr_full_type;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	mask = SRV_SMS_MEM_ME_ONLY | SRV_SMS_MEM_SIM_ONLY | SRV_SMS_MEM_TCARD_ONLY;
    #else
	mask = SRV_SMS_MEM_ME_ONLY | SRV_SMS_MEM_SIM_ONLY;
    #endif
        curr_avail_type = (~curr_full_type) & mask;
        prev_avail_type = (~prev_full_type) & mask;

        if (curr_full_type != prev_full_type)
        {
            /* If have memory change from available to full */
            if (curr_full_type & prev_avail_type)
            {
                if (curr_full_type == SRV_SMS_MEM_NORMAL)
                {
                    srv_sms_send_memory_status(MMI_TRUE, sim_id);
                }
            
                srv_sms_emit_memory_status_event(MMI_TRUE, (srv_sms_mem_enum)curr_full_type, sim_id);
            }

            /* If have memory change from full to available */
            if (curr_avail_type & prev_full_type)
            {
                srv_sms_send_memory_status(MMI_FALSE, sim_id);

                srv_sms_emit_memory_status_event(MMI_FALSE, (srv_sms_mem_enum)curr_avail_type, sim_id);
            }
        }
        if((curr_full_type == prev_full_type)&&(flag == MMI_TRUE))
        {
            srv_sms_emit_memory_status_event(MMI_FALSE, (srv_sms_mem_enum)curr_avail_type, sim_id);
        }
        if((curr_full_type == prev_full_type)&&(flag == MMI_TRUE) && is_in_sim_refresh[i])
        {
            is_in_sim_refresh[i] = MMI_FALSE;
            if(memory_status->is_sim_valid[i])
            {
                srv_sms_emit_memory_status_event(MMI_TRUE, (srv_sms_mem_enum)curr_full_type, sim_id);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_memory_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_memory_status(MMI_BOOL is_mem_full, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_mem_status_req_struct *mem_status_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mem_status_req = (mmi_sms_mem_status_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_mem_status_req_struct));

    mem_status_req->mem_status = is_mem_full;

    srv_sms_disp_send_msg_req(MSG_ID_MMI_SMS_MEM_STATUS_REQ, sim_id, mem_status_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_emit_memory_status_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_emit_memory_status_event(
                MMI_BOOL is_mem_full,
                srv_sms_mem_enum mem_type,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (is_mem_full)
    {
        srv_sms_event_mem_full_struct event_info;

        event_info.mem_type = mem_type;
        event_info.sim_id = sim_id;

        srv_sms_emit_event(EVT_ID_SRV_SMS_MEM_FULL, &event_info);
    }
    else
    {
        srv_sms_event_mem_available_struct event_info;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	if(!storage_cntx.is_tsms_ready)
	{
            mem_type |= SRV_SMS_MEM_TCARD_ONLY;
	}
#endif
        event_info.mem_type = mem_type;
        event_info.sim_id = sim_id;

        srv_sms_emit_event(EVT_ID_SRV_SMS_MEM_AVAILABLE, &event_info);
    }
}


#ifdef __SRV_SMS_ARCHIVE__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_to_archive
 * DESCRIPTION
 *  1. Copy a existed default folder message to Archive folder;
 *  2. The Callback Action Data Structure is srv_sms_copy_to_archive_cb_struct;
 * PARAMETERS
 *  msg_id          :   [IN]        Message ID
 *  callback_func   :   [IN]        Callback Function
 *  user_data       :   [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_copy_msg_to_archive(
            U16 msg_id,
            SrvSmsCallbackFunc callback_func,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_copy_to_archive(
            msg_id,
            SRV_SMS_ACTION_COPY_TO_ARCHIVE,
            callback_func,
            user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_msg_to_archive
 * DESCRIPTION
 *  1. Move a existed message to Archive,  the original message 
 *     will be deleted after moved;
 *  2. The Callback Action Data Structure is srv_sms_move_msg_to_archive_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
SMS_HANDLE srv_sms_move_msg_to_archive(
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_copy_to_archive(
            msg_id,
            SRV_SMS_ACTION_MOVE_TO_ARCHIVE,
            callback_func,
            user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_from_archive
 * DESCRIPTION
 *  1. Copy a existed Archive message to Default Folder.
 *  2. The Callback Action Data Structure is srv_sms_move_archive_msg_cb_struct;
 * PARAMETERS
 *  msg_id         :    [IN]        Message ID
 *  dest_storage   :    [IN]        Dest storage type
 *  callback_func  :    [IN]        Callback Function
 *  user_data      :    [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
 SMS_HANDLE srv_sms_copy_msg_from_archive(
                U16 msg_id,
                srv_sms_storage_enum dest_storage,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum dest_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_sim_id = srv_sms_get_msg_sim_id(msg_id);

    return srv_sms_copy_from_archive(
            msg_id,
            SRV_SMS_ACTION_COPY_FROM_ARCHIVE,
            dest_storage,
            dest_sim_id,
            callback_func,
            user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_archive_msg
 * DESCRIPTION
 *  1. Move a existed Archive message to Default Folder, the original message 
 *     will be deleted after moved successfully;
 *  2. The Callback Action Data Structure is srv_sms_move_archive_msg_cb_struct;
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 *  dest_storage    [IN]        Destination Storage (Phone or SIM Card)
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  SMS_HANDLE
 *****************************************************************************/
SMS_HANDLE srv_sms_move_archive_msg(
            U16 msg_id,
            srv_sms_storage_enum dest_storage,
            SrvSmsCallbackFunc callback_func,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum dest_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_sim_id = srv_sms_get_msg_sim_id(msg_id);

    return srv_sms_copy_from_archive(
            msg_id,
            SRV_SMS_ACTION_MOVE_FROM_ARCHIVE,
            dest_storage,
            dest_sim_id,
            callback_func,
            user_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_archive_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_is_archive_msg(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (msg_id >= SRV_SMS_MAX_SMS_ENTRY)
    {
#else
    if (msg_id >= SRV_SMS_MAX_SMS_ENTRY && msg_id < SRV_SMS_MAX_MSG_NUM)
    {
#endif
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_id_to_archive_entry_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_msg_id_to_archive_entry_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entry_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id >= SRV_SMS_MAX_SMS_ENTRY ) && 
        (msg_id < SRV_SMS_MAX_SMS_ENTRY + SRV_SMS_MAX_ARCH_ENTRY))
    {
        entry_id = msg_id - SRV_SMS_MAX_SMS_ENTRY;
    }
    else
    {
        entry_id = SRV_SMS_ARCHIVE_INVALID_ENTRY_ID;
    }

    return entry_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_entry_id_to_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_archive_entry_id_to_msg_id(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry_id < SRV_SMS_MAX_ARCH_ENTRY)
    {
        msg_id = entry_id + SRV_SMS_MAX_SMS_ENTRY;
    }
    else
    {
        msg_id = SRV_SMS_INVALID_MSG_ID;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_ENTRY_ID_TO_MSG_ID, entry_id, msg_id);

    return msg_id;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_format_archive
 * DESCRIPTION
 *  Remove all files in archive folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_format_archive(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_clear_folder_struct event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_archive_reset_all_msg();

    event_info.folder_id = SRV_SMS_FOLDER_ARCHIVE;

    srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_CLEAR_FOLDER, &event_info);
    srv_sms_emit_event(EVT_ID_SRV_SMS_CLEAR_FOLDER, &event_info);

}

#endif /* __SRV_SMS_ARCHIVE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_sms_malloc_query_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16* srv_sms_malloc_query_msg_list(U32 msg_list_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *query_msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_LARGE_LIST__
    query_msg_list = srv_sms_query_list;
#else /* __SRV_SMS_LARGE_LIST__ */
    query_msg_list = (U16*)OslMalloc(sizeof(U16) * msg_list_size);
#endif /* __SRV_SMS_LARGE_LIST__ */

    return query_msg_list;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_query_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_free_query_msg_list(U16* query_msg_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __SRV_SMS_LARGE_LIST__
     OslMfree(query_msg_list);
#endif /* (SRV_SMS_QUERY_LIST_SIZE <= (SRV_SMS_MAX_BUFF_SIZE / 2)) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_default_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static SMS_HANDLE srv_sms_copy_msg_int(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    srv_sms_storage_enum dest_storage,
                    srv_sms_sim_enum dest_sim_id,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;
    srv_sms_copy_cntx_struct *copy_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_MSG_INT, msg_id, action, dest_storage, dest_sim_id);


#ifdef __SRV_SMS_AT_SUPPORT__
    srv_sms_enter_mmi_operating();
#endif
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(dest_storage == SRV_SMS_STORAGE_TCARD && !storage_cntx.is_tsms_ready)
    {
        STORAGE_ASYNC_ERR_CALLBACK(
            action,
            SRV_SMS_CAUSE_NOT_READY,
            user_data,
            callback_func);
        
        return (SMS_HANDLE)copy_cntx;
    }

    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        MMI_BOOL is_valid;
        
        is_valid = srv_sms_is_tcard_sms_valid(msg_id  - SRV_SMS_MAX_MSG_NUM);
        if(!is_valid)
        {
            srv_sms_delete_invalid_tcard_sms(msg_id  - SRV_SMS_MAX_MSG_NUM);
            
            STORAGE_ASYNC_ERR_CALLBACK(
                action,
                SRV_SMS_CAUSE_DATA_INVALID,
                user_data,
                callback_func);
        
            return (SMS_HANDLE)copy_cntx;
        }        
    }
#endif

    error_cause = srv_sms_check_common_msg_error(msg_id, action);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_storage_enum msg_storage;
        srv_sms_sim_enum msg_sim_id;
        U16 unused_entry;
        U16 msg_seg_num;
        U16 same_pdu_num = 0;

        msg_storage = srv_sms_get_msg_storage_type(msg_id);
        msg_sim_id = srv_sms_get_msg_sim_id(msg_id);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_MSG_INT_1, msg_storage, msg_sim_id);

        if ((action == SRV_SMS_ACTION_MOVE) &&
            (msg_storage == dest_storage) && (msg_sim_id == dest_sim_id))
        {
            srv_sms_copy_int_cb_struct copy_cb_data;

            copy_cb_data.dest_msg_id = msg_id;

            copy_cntx = SRV_SMS_RESERVED_HANDLE;

            STORAGE_ASYNC_SUCC_CALLBACK(
                action,
                &copy_cb_data,
                user_data,
                callback_func);
        }
        else
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if( msg_id >= SRV_SMS_MAX_MSG_NUM)
            {
                msg_seg_num = srv_sms_get_tcard_msg_total_seg(msg_id);
            }
            else
            {
                msg_seg_num = srv_sms_get_msg_total_seg(msg_id);
            }
        #else
            msg_seg_num = srv_sms_get_msg_total_seg(msg_id);
        #endif
            unused_entry = srv_sms_get_unused_space(dest_storage, dest_sim_id);

            if ((action == SRV_SMS_ACTION_MOVE) &&
                (msg_sim_id == dest_sim_id))
            {
                /* If this message contains same storage tpye PDU as the destination storage,
                 * needn't to move it (include reading, adding, deleting this PDU) */
                if (msg_id < SRV_SMS_MAX_MSG_NUM)
                {
                same_pdu_num = srv_sms_get_msg_pdu_num_by_storage(msg_id, dest_storage);
            }
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(dest_storage == SRV_SMS_STORAGE_TCARD || msg_storage == SRV_SMS_STORAGE_TCARD)
                {
                    same_pdu_num = 0;
                }
            #endif
            }

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_MSG_INT_2, msg_seg_num, unused_entry, same_pdu_num);

            if (unused_entry < (msg_seg_num - same_pdu_num))
            {
                if (unused_entry > 0)
                {
                    error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
                }
                else
                {
                    error_cause = SRV_SMS_CAUSE_MEM_FULL;
                }

                STORAGE_ASYNC_ERR_CALLBACK(
                    action,
                    error_cause,
                    user_data,
                    callback_func);
            }
            else
            {
                copy_cntx = srv_sms_alloc_cntx(
                                (sizeof(srv_sms_copy_cntx_struct)),
                                action,
                                callback_func,
                                user_data);

                if (copy_cntx)
                {
                    srv_sms_copy_init(
                        copy_cntx,
                        msg_id,
                        dest_storage,
                        dest_sim_id);
                #ifdef __SMS_CLOUD_SUPPORT__
                    if(action == SRV_SMS_ACTION_MOVE && dest_storage == SRV_SMS_STORAGE_SIM && same_pdu_num == 0)
                    {
                        U16 pdu_id;
                        MMI_BOOL is_sim_msg = MMI_FALSE;
                        //S32 sync_result;
                        pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
                        while (pdu_id != SRV_SMS_INVALID_PDU_ID)
                        {
                            if(pdu_id >= SRV_SMS_MAX_ME_SMS_ENTRY)
                            {
                                is_sim_msg = MMI_TRUE;
                                break;
                            }
                            pdu_id = srv_sms_pdu_list[pdu_id].next_pdu_id;
                        }

                        if(!is_sim_msg)
                        {
                            pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
                            while (srv_sms_pdu_list[pdu_id].next_pdu_id != SRV_SMS_INVALID_PDU_ID)
                            {
                                pdu_id = srv_sms_pdu_list[pdu_id].next_pdu_id;
                            }
                        }

                        srv_cloud_sync_set_store_uid(pdu_id, 
                                                         NULL, 
                                                         SRV_CLD_TYPE_SMS, 
                                                         SRV_CLD_ACTION_DEL);
                        //add trace
                    }
                #endif
                    srv_sms_copy_hdlr(copy_cntx);
                }
                else
                {
                    STORAGE_ASYNC_ERR_CALLBACK(
                        action,
                        SRV_SMS_CAUSE_MEM_INSUFFICIENT,
                        user_data,
                        callback_func);
                }
            }
        }
    }
    else
    {
        STORAGE_ASYNC_ERR_CALLBACK(
            action,
            error_cause,
            user_data,
            callback_func);
    }

    return (SMS_HANDLE)copy_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_copy_hdlr(srv_sms_copy_cntx_struct *copy_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_pdu_id;
    srv_sms_storage_enum dest_storage = copy_cntx->dest_storage;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_HDLR, copy_cntx->curr_index);

    curr_pdu_id = copy_cntx->src_pdu_list[copy_cntx->curr_index];
#ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if ((CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE) &&
        (copy_cntx->msg_sim_id == copy_cntx->dest_sim_id))
    {
        /* Skip the same storage's PDU */
        while ((copy_cntx->curr_index < copy_cntx->total_pdu) &&
               (srv_sms_get_pdu_storage_type(curr_pdu_id) == dest_storage))
        {
            copy_cntx->dest_pdu_list[copy_cntx->curr_index] = curr_pdu_id;
            copy_cntx->curr_index++;
            curr_pdu_id = copy_cntx->src_pdu_list[copy_cntx->curr_index];
        }
    }
#else
    if(dest_storage != SRV_SMS_STORAGE_TCARD && copy_cntx->src_pdu_list[0] < SRV_SMS_MAX_SMS_ENTRY)
    {
    if ((CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE) &&
        (copy_cntx->msg_sim_id == copy_cntx->dest_sim_id))
    {
        /* Skip the same storage's PDU */
        while ((copy_cntx->curr_index < copy_cntx->total_pdu) &&
               (srv_sms_get_pdu_storage_type(curr_pdu_id) == dest_storage))
        {
            copy_cntx->dest_pdu_list[copy_cntx->curr_index] = curr_pdu_id;
            copy_cntx->curr_index++;
            curr_pdu_id = copy_cntx->src_pdu_list[copy_cntx->curr_index];
        }
    }
    }
#endif
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_HDLR_1, copy_cntx->curr_index);

    if (copy_cntx->curr_index < copy_cntx->total_pdu)
    {
        srv_sms_read_pdu(
            curr_pdu_id,
            srv_sms_copy_callback,
            copy_cntx);
    }
    else
    {
        /* Read Msg Finished, Clear the READING Flag */
        srv_sms_clear_set_pdu_array_flag(
            copy_cntx->src_pdu_list,
            copy_cntx->total_pdu,
            SRV_SMS_NODE_READING,
            MMI_TRUE);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_HDLR_2, copy_cntx->moved_num);

        /* If the some PDUs are to be moved, delete the original ones */
        if (copy_cntx->moved_num > 0)
        {
            copy_cntx->curr_index = 0;

            srv_sms_clear_set_pdu_array_flag(
                copy_cntx->moved_pdu_list,
                copy_cntx->moved_num,
                SRV_SMS_NODE_DELETING,
                MMI_FALSE);

            srv_sms_delete_pdu(
                copy_cntx->moved_pdu_list[copy_cntx->curr_index],
                srv_sms_copy_del_moved_callback,
                copy_cntx);
        }
        else
        {
            srv_sms_copy_succ_hdlr(copy_cntx);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_copy_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_cntx_struct *copy_cntx;
    MMI_BOOL result = callback_data->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (srv_sms_copy_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_CALLBACK, 
        result, copy_cntx->curr_index, callback_data->action, CNTX_IS_ABORT(copy_cntx));

    if (CNTX_IS_ABORT(copy_cntx))
    {
        result = MMI_FALSE;
    }

    if (result)
    {
        switch (callback_data->action)
        {
            case SRV_SMS_ACTION_READ:
            {
                srv_sms_read_pdu_cb_struct *read_pdu_cb_data;
                srv_sms_spdu_struct *spdu_data;
                srv_sms_add_pdu_struct add_data;
                srv_sms_pdu_node_struct *pdu_node = NULL;
                
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                srv_sms_tcard_pdu_node_struct *tcard_pdu_node = NULL;
                MMI_BOOL is_tcard_msg = MMI_FALSE;
            #endif
                srv_sms_status_enum msg_status;

                read_pdu_cb_data = (srv_sms_read_pdu_cb_struct*)callback_data->action_data;
                spdu_data = read_pdu_cb_data->spdu_data;

                /* 1. If the message's original status is UNREAD, all of the segments 
                 *    should be same after copying even if some original segments is not UNREAD
                 *    (If it exists segments which their status is UNREAD, we will consider this
                 *    message as UNREAD);
                 * 2> If the original status is Draft and its storage is SIM, after 
                 *    copy it to ME, the status should be Draft not the UNSENT. */
                msg_status = srv_sms_get_msg_status(copy_cntx->msg_id);

                spdu_data->status = (U8)msg_status;
            #ifdef __SRV_SMS_MULTI_SIM__
                spdu_data->sim_id = copy_cntx->dest_sim_id;
            #endif /* __SRV_SMS_MULTI_SIM__ */
            #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                pdu_node = srv_sms_get_pdu_node(copy_cntx->src_pdu_list[copy_cntx->curr_index]);
            #else
                if(copy_cntx->src_pdu_list[copy_cntx->curr_index] >= SRV_SMS_MAX_SMS_ENTRY)
                {
                    is_tcard_msg = MMI_TRUE;
                    tcard_pdu_node = srv_sms_get_tcard_pdu_node(copy_cntx->src_pdu_list[copy_cntx->curr_index]);
                }
                else
                {
                pdu_node = srv_sms_get_pdu_node(copy_cntx->src_pdu_list[copy_cntx->curr_index]);
                }
            #endif
                add_data.spdu_data = spdu_data;
                add_data.storage_type = copy_cntx->dest_storage;
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if (is_tcard_msg)
                {
                    add_data.curr_seg = tcard_pdu_node->segment;
                }
                else
                {
                add_data.curr_seg = pdu_node->segment;
                }
            #else
                add_data.curr_seg = pdu_node->segment;
            #endif
                
            #ifdef __SRV_SMS_DELIVERY_STATUS__
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(is_tcard_msg)
                {
                    add_data.msg_ref = tcard_pdu_node->msg_ref;
                }
                else
                {
                add_data.msg_ref = pdu_node->msg_ref;
                }
            #else
                add_data.msg_ref = pdu_node->msg_ref;
            #endif 
            #endif /* __SRV_SMS_DELIVERY_STATUS__ */

                srv_sms_add_pdu(
                    &add_data,
                    srv_sms_copy_callback,
                    copy_cntx);
                break;
            }

            case SRV_SMS_ACTION_SAVE:
            {
                srv_sms_add_pdu_cb_struct *add_pdu_cb_data;
                U16 pdu_id;

                add_pdu_cb_data = (srv_sms_add_pdu_cb_struct*)callback_data->action_data;
                pdu_id = add_pdu_cb_data->pdu_id;
                
                copy_cntx->dest_pdu_list[copy_cntx->curr_index] = pdu_id;
                copy_cntx->added_pdu_list[copy_cntx->added_num] = pdu_id;
                copy_cntx->added_num++;

                if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE)
                {
                    copy_cntx->moved_pdu_list[copy_cntx->moved_num] = copy_cntx->src_pdu_list[copy_cntx->curr_index];
                    copy_cntx->moved_num++;
                }
                copy_cntx->curr_index++;

                srv_sms_set_pdu_flag(pdu_id, SRV_SMS_NODE_LOCKING);

                srv_sms_copy_hdlr(copy_cntx);
                break;
            }

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
    {
        copy_cntx->error_cause = callback_data->cause;

        /* Read Message Finish, Clear the READING Flag */
        srv_sms_clear_set_pdu_array_flag(
            copy_cntx->src_pdu_list,
            copy_cntx->total_pdu,
            SRV_SMS_NODE_READING,
            MMI_TRUE);

        if (copy_cntx->added_num > 0)
        {
            copy_cntx->curr_index = 0;

            srv_sms_clear_set_pdu_array_flag(
                copy_cntx->added_pdu_list,
                copy_cntx->added_num,
                SRV_SMS_NODE_LOCKING,
                MMI_TRUE);

            srv_sms_clear_set_pdu_array_flag(
                copy_cntx->added_pdu_list,
                copy_cntx->added_num,
                SRV_SMS_NODE_DELETING,
                MMI_FALSE);

            srv_sms_delete_pdu(
                copy_cntx->added_pdu_list[copy_cntx->curr_index],
                srv_sms_copy_del_added_callback,
                copy_cntx);
        }
        else
        {
            srv_sms_copy_deinit(copy_cntx);

            STORAGE_INVOKE_CALLBACK(
                copy_cntx,
                MMI_FALSE,
                callback_data->cause,
                NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_del_added_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_copy_del_added_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_cntx_struct *copy_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (srv_sms_copy_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_DEL_ADDED_CALLBACK, callback_data->result, copy_cntx->curr_index);

    if (!callback_data->result)
    {
        U16 pdu_id = copy_cntx->added_pdu_list[copy_cntx->curr_index];

        srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_DELETING);
    }

    copy_cntx->curr_index++;

    if (copy_cntx->curr_index < copy_cntx->added_num)
    {
        srv_sms_delete_pdu(
            copy_cntx->added_pdu_list[copy_cntx->curr_index],
            srv_sms_copy_del_added_callback,
            copy_cntx);
    }
    else
    {
        srv_sms_cause_enum error_cause = copy_cntx->error_cause;

        srv_sms_copy_deinit(copy_cntx);

        STORAGE_INVOKE_CALLBACK(
            copy_cntx,
            MMI_FALSE,
            error_cause,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_del_moved_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_copy_del_moved_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_cntx_struct *copy_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (srv_sms_copy_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_DEL_MOVED_CALLBACK,
        callback_data->result, copy_cntx->curr_index);

    if (!callback_data->result)
    {
        U16 pdu_id = copy_cntx->moved_pdu_list[copy_cntx->curr_index];

        srv_sms_clear_pdu_flag(pdu_id, SRV_SMS_NODE_DELETING);
    }

    copy_cntx->curr_index++;

    if (copy_cntx->curr_index < copy_cntx->moved_num)
    {
        srv_sms_delete_pdu(
            copy_cntx->moved_pdu_list[copy_cntx->curr_index],
            srv_sms_copy_del_moved_callback,
            copy_cntx);
    }
    else
    {
        srv_sms_copy_succ_hdlr(copy_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_succ_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_copy_succ_hdlr(srv_sms_copy_cntx_struct* copy_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_copy_int_cb_struct copy_cb_data;
    void *event_data;
    MMI_BOOL int_result;
    srv_sms_msg_node_struct *msg_node;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
#endif
    U16 msg_id = copy_cntx->msg_id;
    U16 new_msg_id = msg_id;
    MMI_BOOL is_added = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_SUCC_HDLR);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(copy_cntx->dest_storage == SRV_SMS_STORAGE_TCARD)
    {
        //SIM or ME -->tCARD
        if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_COPY)
        {
            srv_sms_tcard_msg_node_struct new_msg_node;
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            srv_sms_event_add_struct *add_event;
            U16 start_index;
            U16 end_index;
            srv_tcard_op_struct *cntx;
            CHAR *buff;
            CHAR tmp_content[(SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH];
            srv_sms_copy_pdu_list_update_struct *list_copy_cntx;
            srv_sms_tcard_spdu_struct *spdu_data;
            srv_tcard_op_struct read_cntx;
            S32 size;
            srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
            srv_sms_tcard_async_cntx_struct *asyc_cntx;

            for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
            size = sizeof(srv_sms_tcard_spdu_struct);
            msg_node = srv_sms_get_msg_node(msg_id);
            srv_sms_set_tcard_msg_node(msg_node,&new_msg_node);
            new_msg_id = srv_sms_add_tcard_msg_node(&new_msg_node); 
            if(new_msg_id != SRV_SMS_INVALID_MSG_ID)
            {
                
                U16 big_index = 0;
                U16 small_index = 0XFFFF;
                S32 temp_pdu_num;
                
                srv_sms_concat_tcard_pdu_list(
                                   new_msg_id,
                                   copy_cntx->dest_pdu_list,
                                   copy_cntx->total_pdu);


                //get content from pdu
                spdu_data = OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                tcard_msg_node = srv_sms_get_tcard_msg_node(new_msg_id - SRV_SMS_MAX_MSG_NUM);
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                read_cntx.start_record_id = tcard_msg_node->start_pdu_id - SRV_SMS_MAX_MSG_NUM;
                srv_tcard_sync_read_record(&read_cntx,(CHAR*)spdu_data);           

                srv_sms_get_content_from_pdu(
                        (char*)tcard_msg_node->content, 
                        SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH,
                        spdu_data->pdu);
                tcard_msg_node->content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN] = 0;
                OslMfree(spdu_data);
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
            #endif  
                cntx = OslMalloc(sizeof(srv_tcard_op_struct));
                list_copy_cntx = OslMalloc(sizeof(srv_sms_copy_pdu_list_update_struct));
                add_event = OslMalloc(sizeof(srv_sms_event_add_struct));
                
                event_data = add_event;
                is_added = MMI_TRUE;

                add_event->msg_id = new_msg_id;
                srv_sms_clear_set_pdu_array_flag(
                    copy_cntx->added_pdu_list,
                    copy_cntx->added_num,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);
                srv_sms_tcard_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);

                
                
                list_copy_cntx->is_add = is_added;
                list_copy_cntx->event_info = event_data;
                list_copy_cntx->copy_cntx = copy_cntx;
                list_copy_cntx->new_msg_id = new_msg_id; 

                for (temp_pdu_num = 0; temp_pdu_num < copy_cntx->total_pdu; temp_pdu_num++)
                {
                    if(copy_cntx->dest_pdu_list[temp_pdu_num] > big_index)
                    {
                        big_index = copy_cntx->dest_pdu_list[temp_pdu_num];
                    }
                    if(copy_cntx->dest_pdu_list[temp_pdu_num] < small_index)
                    {
                        small_index = copy_cntx->dest_pdu_list[temp_pdu_num];
                    }
                }
                start_index = small_index - SRV_SMS_MAX_MSG_NUM;
                end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                cntx->app_index = SRV_TCARD_APP_INDEX_SMS;
                cntx->file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                cntx->start_record_id = start_index;
                cntx->record_num = end_index - start_index + 1;
                //buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);

                for_tcard_cntx->user_data = list_copy_cntx;
                for_tcard_cntx->callback_func = srv_sms_tcard_copy_list_callback;
                asyc_cntx = (srv_sms_tcard_async_cntx_struct*)OslMalloc(sizeof(srv_sms_tcard_async_cntx_struct));
                asyc_cntx->cntx = cntx;
                asyc_cntx->for_tcard_cntx = for_tcard_cntx;
                StartTimerEx(SRV_SMS_TCARD_ASYNC_TIMER_ID, 0, srv_sms_tcard_handle_asyc_copy, asyc_cntx);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            }
            else
            {
                STORAGE_INVOKE_CALLBACK(
                    copy_cntx,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_FS_ERROR,
                    &copy_cb_data);
            }
        }
        else
        {
        //add move action
            srv_sms_event_add_struct *add_event;
            srv_sms_tcard_msg_node_struct new_msg_node;
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
            U16 start_index;
            U16 end_index;
            srv_tcard_op_struct *cntx;
            CHAR *buff;
            MMI_BOOL int_result;
            srv_sms_event_delete_struct delete_event;
            srv_sms_copy_pdu_list_update_struct *list_copy_cntx;
            srv_sms_tcard_spdu_struct *spdu_data;
            srv_tcard_op_struct read_cntx;
            srv_sms_for_tcard_cntx_struct *for_tcard_cntx;
            srv_sms_tcard_async_cntx_struct *asyc_cntx;
            
            for_tcard_cntx = (srv_sms_for_tcard_cntx_struct*)OslMalloc(sizeof(srv_sms_for_tcard_cntx_struct));
            msg_node = srv_sms_get_msg_node(copy_cntx->msg_id);
            delete_event.msg_id = copy_cntx->msg_id;
            srv_sms_msg_node_to_msg_info(&delete_event.msg_info, msg_node);
            
            srv_sms_set_tcard_msg_node(msg_node,&new_msg_node);

            //delete the old one
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_event);

            if(!int_result & !copy_move_list)
            {
                srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_event);
            }
            //msg_node->status = SRV_SMS_STATUS_NONE;
            srv_sms_delete_msg_node(copy_cntx->msg_id,NULL);
            new_msg_id = srv_sms_add_tcard_msg_node(&new_msg_node);
            /*if msg node can not add to file, it should be error*/
            if (new_msg_id != SRV_SMS_INVALID_MSG_ID)
            {
                U16 big_index = 0;
                U16 small_index = 0XFFFF;
                S32 temp_pdu_num;
                
                list_copy_cntx = OslMalloc(sizeof(srv_sms_copy_pdu_list_update_struct));

                
                add_event = OslMalloc(sizeof(srv_sms_event_add_struct));
                event_data = add_event;
                is_added = MMI_TRUE;
                add_event->msg_id = new_msg_id;
                srv_sms_tcard_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);
                srv_sms_concat_tcard_pdu_list(
                    new_msg_id,
                    copy_cntx->dest_pdu_list,
                    copy_cntx->total_pdu);

                //get content and add to tcard_msg_list
                spdu_data = OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                tcard_msg_node = srv_sms_get_tcard_msg_node(new_msg_id - SRV_SMS_MAX_MSG_NUM);
                read_cntx.start_record_id = tcard_msg_node->start_pdu_id - SRV_SMS_MAX_MSG_NUM;
                srv_tcard_sync_read_record(&read_cntx,(CHAR*)spdu_data);           
                srv_sms_get_content_from_pdu(
                        (char*)tcard_msg_node->content, 
                        SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH,
                        spdu_data->pdu);
                tcard_msg_node->content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN] = 0;
                OslMfree(spdu_data);
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
            #endif
                srv_sms_tcard_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);

                srv_sms_clear_set_pdu_array_flag(
                    copy_cntx->added_pdu_list,
                    copy_cntx->added_num,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);
                
                
                
                list_copy_cntx->is_add = is_added;
                list_copy_cntx->event_info = event_data;
                list_copy_cntx->copy_cntx = copy_cntx;
                list_copy_cntx->new_msg_id = new_msg_id; 
                for (temp_pdu_num = 0; temp_pdu_num < copy_cntx->total_pdu; temp_pdu_num++)
                {
                    if(copy_cntx->dest_pdu_list[temp_pdu_num] > big_index)
                    {
                        big_index = copy_cntx->dest_pdu_list[temp_pdu_num];
                    }
                    if(copy_cntx->dest_pdu_list[temp_pdu_num] < small_index)
                    {
                        small_index = copy_cntx->dest_pdu_list[temp_pdu_num];
                    }
                }
                start_index = small_index - SRV_SMS_MAX_MSG_NUM;
                end_index = big_index - SRV_SMS_MAX_MSG_NUM;
                cntx =(srv_tcard_op_struct*)OslMalloc(sizeof(srv_tcard_op_struct));
                cntx->app_index = SRV_TCARD_APP_INDEX_SMS;
                cntx->file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                cntx->start_record_id = start_index;
                cntx->record_num = end_index - start_index + 1;
                //buff = (CHAR*)(srv_sms_tcard_pdu_list + start_index);
                
                for_tcard_cntx->user_data = list_copy_cntx;
                for_tcard_cntx->callback_func = srv_sms_tcard_copy_list_callback;
                asyc_cntx = (srv_sms_tcard_async_cntx_struct*)OslMalloc(sizeof(srv_sms_tcard_async_cntx_struct));
                asyc_cntx->cntx = cntx;
                asyc_cntx->for_tcard_cntx = for_tcard_cntx;
                StartTimerEx(SRV_SMS_TCARD_ASYNC_TIMER_ID, 0, srv_sms_tcard_handle_asyc_copy, asyc_cntx);
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            }
            else
            {
                STORAGE_INVOKE_CALLBACK(
                    copy_cntx,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_FS_ERROR,
                    &copy_cb_data);
            }
            
            
        }
        
    }
    else
    {
        if(copy_cntx->msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            // tCARD --> sim or me;
            tcard_msg_node = srv_sms_get_tcard_msg_node(copy_cntx->msg_id - SRV_SMS_MAX_MSG_NUM);
            if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_COPY)
            {
                srv_sms_msg_node_struct new_msg_node;
                srv_sms_msg_node_struct *msg_list;
                U16 index;
                srv_sms_event_add_struct *add_event;

                
                srv_sms_set_msg_node(tcard_msg_node,&new_msg_node);
	    #ifdef __SRV_SMS_MULTI_SIM__ 
                new_msg_node.sim_id= copy_cntx->dest_sim_id;
            #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
                new_msg_id = srv_sms_add_msg_node(&new_msg_node);
                srv_sms_concat_pdu_list(
                        new_msg_id,
                        copy_cntx->dest_pdu_list,
                        copy_cntx->total_pdu);
                msg_list = srv_sms_msg_list;
                index = msg_list[new_msg_id].start_pdu_id;
                
                while(index != SRV_SMS_INVALID_PDU_ID)
                {
                    if(index >= SRV_SMS_MAX_ME_SMS_ENTRY)
                    {
                         msg_list[new_msg_id].storage_type = SRV_SMS_STORAGE_SIM;
                         break;
                    }
                    index = srv_sms_pdu_list[index].next_pdu_id;
                }

                if(msg_list[new_msg_id].storage_type != SRV_SMS_STORAGE_SIM)
                {
                    msg_list[new_msg_id].storage_type = SRV_SMS_STORAGE_ME;
                }
                new_msg_node.storage_type = msg_list[new_msg_id].storage_type;
                /* Set Event Data For Add Event */
                add_event = OslMalloc(sizeof(srv_sms_event_add_struct));
                is_added = MMI_TRUE;

                add_event->msg_id = new_msg_id;
                srv_sms_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);

				srv_sms_clear_set_pdu_array_flag(
                    copy_cntx->added_pdu_list,
                    copy_cntx->added_num,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);
                /* Exec Interrupt Add Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_event);
				
				srv_sms_copy_deinit(copy_cntx);

                /* Exec Callback Function */
                copy_cb_data.dest_msg_id = new_msg_id;

                STORAGE_INVOKE_CALLBACK(
                    copy_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_NO_ERROR,
                    &copy_cb_data);

                if (!int_result)
                {
                    if (is_added & !copy_move_list)
                    {
                        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_event);
                    }
                }  

                OslMfree(add_event);

                srv_sms_handle_mem_change(MMI_FALSE);
            }  
            else
            {
                srv_sms_event_delete_struct delete_data;
                srv_sms_event_add_struct *add_data;
                srv_sms_msg_node_struct msg_node;
                S32 i;
                srv_tcard_op_struct read_cntx;
                srv_sms_msg_node_struct *msg_list;
                U32 index;
                    


                /* Get Old Msg Info */
                delete_data.msg_id = copy_cntx->msg_id;
                srv_sms_tcard_msg_node_to_msg_info(&delete_data.msg_info, tcard_msg_node);
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_data);
                if(!int_result & !copy_move_list)
                {
                    srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_MSG, &delete_data);

                }
                srv_sms_set_msg_node(tcard_msg_node,&msg_node);
	    #ifdef __SRV_SMS_MULTI_SIM__ 
                msg_node.sim_id= copy_cntx->dest_sim_id;
            #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
                new_msg_id = srv_sms_add_msg_node(&msg_node);  

                srv_sms_delete_msg_node(copy_cntx->msg_id,NULL);
                tcard_msg_node = srv_sms_get_tcard_msg_node(copy_cntx->msg_id - SRV_SMS_MAX_MSG_NUM);
                //tcard_msg_node->status = SRV_SMS_STATUS_NONE;
                
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
                read_cntx.start_record_id = copy_cntx->msg_id - SRV_SMS_MAX_MSG_NUM;
                read_cntx.record_num = 1;
                
                srv_tcard_sync_write_record(&read_cntx, (CHAR*)tcard_msg_node);  
                
                 

              
                add_data = OslMalloc(sizeof(srv_sms_event_add_struct));
                is_added = MMI_TRUE;
                add_data->msg_id = new_msg_id;
                srv_sms_concat_pdu_list(
                    new_msg_id,
                    copy_cntx->dest_pdu_list,
                    copy_cntx->total_pdu);

                /* Set Event Data For Message Change */
                msg_list = srv_sms_msg_list;
                index = msg_list[new_msg_id].start_pdu_id;
                
                while(index != SRV_SMS_INVALID_PDU_ID)
                {
                    if(index >= SRV_SMS_MAX_ME_SMS_ENTRY)
                    {
                         msg_list[new_msg_id].storage_type = SRV_SMS_STORAGE_SIM;
                         break;
                    }
                    index = srv_sms_pdu_list[index].next_pdu_id;
                }

                if(msg_list[new_msg_id].storage_type != SRV_SMS_STORAGE_SIM)
                {
                    msg_list[new_msg_id].storage_type = SRV_SMS_STORAGE_ME;
                }
                msg_node.storage_type = msg_list[new_msg_id].storage_type;
                
                srv_sms_msg_node_to_msg_info(&(add_data->msg_info), &msg_node);

                srv_sms_clear_set_pdu_array_flag(
                    copy_cntx->added_pdu_list,
                    copy_cntx->added_num,
                    SRV_SMS_NODE_LOCKING,
                    MMI_TRUE);


                /* Exec Message Change Interrupt Event */
                int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, add_data);


                srv_sms_copy_deinit(copy_cntx);

                /* Exec Callback Function */
                copy_cb_data.dest_msg_id = new_msg_id;

                STORAGE_INVOKE_CALLBACK(
                    copy_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_NO_ERROR,
                    &copy_cb_data);
                    
                if (!int_result)
                {
                    if (is_added & !copy_move_list)
                    {
                        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, add_data);
                    }
                }

                OslMfree(add_data);

                srv_sms_handle_mem_change(MMI_FALSE);
            }
                
        }
            else
            {
                // sim<==>me;
                msg_node = srv_sms_get_msg_node(msg_id);
                if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_COPY)
                {
                    srv_sms_event_add_struct *add_event;
                    srv_sms_msg_node_struct new_msg_node;

                    memcpy(&new_msg_node, msg_node, sizeof(srv_sms_msg_node_struct));

                    new_msg_node.storage_type = copy_cntx->dest_storage;
                #ifdef __SRV_SMS_MULTI_SIM__ 
                    new_msg_node.sim_id= copy_cntx->dest_sim_id;
                #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
                    new_msg_node.start_pdu_id = SRV_SMS_INVALID_PDU_ID;
                #ifdef __SRV_SMS_MULTI_ADDR__
                    /* 1. If copy to SIM Card, only copy the fisrt address, don't copy
                     *    the extension address, so need to reset its information.
                     * 2. If copy to Phone, it only have one address, also need to 
                     *    reset the extension address information.
                     */
                    new_msg_node.start_addr_id = SRV_SMS_INVALID_ADDR_ID;
                    new_msg_node.ext_addr_num = 0;
                #endif /* __SRV_SMS_MULTI_ADDR__ */
                #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
                    new_msg_node.ext_status = SRV_SMS_STATUS_NONE;
                #endif /* __SRV_SMS_MSG_EXT_STATUS__ */
                #ifdef __SRV_SMS_RESEND_COUNT__
                    new_msg_node.resend_count = 0;
                #endif /* __SRV_SMS_RESEND_COUNT__ */

                    new_msg_id = srv_sms_add_msg_node(&new_msg_node);

                    srv_sms_concat_pdu_list(
                        new_msg_id,
                        copy_cntx->dest_pdu_list,
                        copy_cntx->total_pdu);

                    /* Set Event Data For Add Event */
                    add_event = OslMalloc(sizeof(srv_sms_event_add_struct));
                    event_data = add_event;
                    is_added = MMI_TRUE;

                    add_event->msg_id = new_msg_id;
                    srv_sms_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);

                    /* Exec Interrupt Add Event */
                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                }  
                else
                {
                    srv_sms_event_update_struct *update_data;

                    update_data = OslMalloc(sizeof(srv_sms_event_update_struct));
                    event_data = update_data;

                    /* Get Old Msg Info */
                    srv_sms_msg_node_to_msg_info(&update_data->old_msg_info, msg_node);

                    /* Update Msg Node */
                    msg_node->storage_type = copy_cntx->dest_storage;
                #ifdef __SRV_SMS_MULTI_SIM__ 
                    msg_node->sim_id= copy_cntx->dest_sim_id;
                #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
                #ifdef __SRV_SMS_MULTI_ADDR__
                    /* similiar with the copy case */
                    msg_node->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
                    msg_node->ext_addr_num = 0;
                #endif /* __SRV_SMS_MULTI_ADDR__ */

                    srv_sms_concat_pdu_list(
                        new_msg_id,
                        copy_cntx->dest_pdu_list,
                        copy_cntx->total_pdu);

                    /* Set Event Data For Message Change */
                    update_data->msg_id = msg_id;
                    update_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_SIM_ID);
                    srv_sms_msg_node_to_msg_info(&update_data->new_msg_info, msg_node);

                    srv_sms_clear_set_pdu_array_flag(
                        copy_cntx->added_pdu_list,
                        copy_cntx->added_num,
                        SRV_SMS_NODE_LOCKING,
                        MMI_TRUE);


                    /* Exec Message Change Interrupt Event */
                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
                }

                srv_sms_copy_deinit(copy_cntx);

                /* Exec Callback Function */
                copy_cb_data.dest_msg_id = new_msg_id;

                STORAGE_INVOKE_CALLBACK(
                    copy_cntx,
                    MMI_TRUE,
                    SRV_SMS_CAUSE_NO_ERROR,
                    &copy_cb_data);
                    
                if (!int_result & !copy_move_list)
                {
                    if (is_added)
                    {
                        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
                    }
                    else
                    {
                        /* emit Message Change Event */
                        srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
                    }
                }

                OslMfree(event_data);

                srv_sms_handle_mem_change(MMI_FALSE);
            }
        }
        
#else
    msg_node = srv_sms_get_msg_node(msg_id);

    if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_COPY)
    {
        srv_sms_event_add_struct *add_event;
        srv_sms_msg_node_struct new_msg_node;

        memcpy(&new_msg_node, msg_node, sizeof(srv_sms_msg_node_struct));

        new_msg_node.storage_type = copy_cntx->dest_storage;
    #ifdef __SRV_SMS_MULTI_SIM__ 
        new_msg_node.sim_id= copy_cntx->dest_sim_id;
    #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
        new_msg_node.start_pdu_id = SRV_SMS_INVALID_PDU_ID;
    #ifdef __SRV_SMS_MULTI_ADDR__
        /* 1. If copy to SIM Card, only copy the fisrt address, don't copy
         *    the extension address, so need to reset its information.
         * 2. If copy to Phone, it only have one address, also need to 
         *    reset the extension address information.
         */
        new_msg_node.start_addr_id = SRV_SMS_INVALID_ADDR_ID;
        new_msg_node.ext_addr_num = 0;
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    #ifdef __SRV_SMS_MSG_EXT_STATUS__ 
        new_msg_node.ext_status = SRV_SMS_STATUS_NONE;
    #endif /* __SRV_SMS_MSG_EXT_STATUS__ */
    #ifdef __SRV_SMS_RESEND_COUNT__
        new_msg_node.resend_count = 0;
    #endif /* __SRV_SMS_RESEND_COUNT__ */

        new_msg_id = srv_sms_add_msg_node(&new_msg_node);

        srv_sms_concat_pdu_list(
            new_msg_id,
            copy_cntx->dest_pdu_list,
            copy_cntx->total_pdu);

        /* Set Event Data For Add Event */
        add_event = OslMalloc(sizeof(srv_sms_event_add_struct));
        event_data = add_event;
        is_added = MMI_TRUE;

        add_event->msg_id = new_msg_id;
        srv_sms_msg_node_to_msg_info(&add_event->msg_info, &new_msg_node);

        /* Exec Interrupt Add Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
    }  
    else
    {
        srv_sms_event_update_struct *update_data;

        update_data = OslMalloc(sizeof(srv_sms_event_update_struct));
        event_data = update_data;

        /* Get Old Msg Info */
        srv_sms_msg_node_to_msg_info(&update_data->old_msg_info, msg_node);

        /* Update Msg Node */
        msg_node->storage_type = copy_cntx->dest_storage;
    #ifdef __SRV_SMS_MULTI_SIM__ 
        msg_node->sim_id= copy_cntx->dest_sim_id;
    #endif /* #ifdef __SRV_SMS_MULTI_SIM__ */
    #ifdef __SRV_SMS_MULTI_ADDR__
        /* similiar with the copy case */
        msg_node->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
        msg_node->ext_addr_num = 0;
    #endif /* __SRV_SMS_MULTI_ADDR__ */

        srv_sms_concat_pdu_list(
            new_msg_id,
            copy_cntx->dest_pdu_list,
            copy_cntx->total_pdu);

        /* Set Event Data For Message Change */
        update_data->msg_id = msg_id;
        update_data->change_para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STORAGE_TYPE | SRV_SMS_PARA_SIM_ID);
        srv_sms_msg_node_to_msg_info(&update_data->new_msg_info, msg_node);

        srv_sms_clear_set_pdu_array_flag(
            copy_cntx->added_pdu_list,
            copy_cntx->added_num,
            SRV_SMS_NODE_LOCKING,
            MMI_TRUE);


        /* Exec Message Change Interrupt Event */
        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
    }

    srv_sms_copy_deinit(copy_cntx);

    /* Exec Callback Function */
    copy_cb_data.dest_msg_id = new_msg_id;

    STORAGE_INVOKE_CALLBACK(
        copy_cntx,
        MMI_TRUE,
        SRV_SMS_CAUSE_NO_ERROR,
        &copy_cb_data);
        
    if (!int_result)
    {
        if (is_added)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, event_data);
        }
        else
        {
            /* emit Message Change Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }
    }

    OslMfree(event_data);

    srv_sms_handle_mem_change(MMI_FALSE);
#endif
  
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_copy_init(
                            srv_sms_copy_cntx_struct* copy_cntx,
                            U16 msg_id,
                            srv_sms_storage_enum dest_storage,
                            srv_sms_sim_enum dest_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx->total_pdu = srv_sms_get_msg_pdu_id(copy_cntx->src_pdu_list, msg_id);

    MMI_ASSERT(copy_cntx->total_pdu > 0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_INIT, copy_cntx->total_pdu);

    /* Copy Message need to Read PDU first, so set those PDUs as Reading flag */
    srv_sms_clear_set_pdu_array_flag(
        copy_cntx->src_pdu_list,
        copy_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_FALSE);
    
    copy_cntx->curr_index = 0;
    copy_cntx->moved_num = 0;
    copy_cntx->added_num = 0;
    copy_cntx->msg_id = msg_id;
    copy_cntx->msg_sim_id = srv_sms_get_msg_sim_id(msg_id);
    copy_cntx->dest_storage = dest_storage;
    copy_cntx->dest_sim_id = dest_sim_id;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_copy_deinit(srv_sms_copy_cntx_struct *copy_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_DEINIT);

    srv_sms_clear_set_pdu_array_flag(
        copy_cntx->src_pdu_list,
        copy_cntx->total_pdu,
        SRV_SMS_NODE_READING,
        MMI_TRUE);

    srv_sms_clear_set_pdu_array_flag(
        copy_cntx->dest_pdu_list,
        copy_cntx->total_pdu,
        SRV_SMS_NODE_LOCKING,
        MMI_TRUE);
}

#ifdef __SRV_SMS_ARCHIVE__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_to_archive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static SMS_HANDLE srv_sms_copy_to_archive(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_to_arch_cntx_struct *copy_cntx = NULL;

    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCHIVE, msg_id, action);

    do
    {
        srv_sms_status_enum status;
        SMS_HANDLE read_hd;

        if (!srv_sms_is_msg_exist_ext(msg_id))
        {
            error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
            break;
        }

        status = srv_sms_get_msg_status(msg_id);

        if (status & SRV_SMS_STATUS_UNSUPPORTED)
        {
            error_cause = SRV_SMS_CAUSE_OP_NOT_SUPPORTED;
            break;
        }

        copy_cntx = srv_sms_alloc_cntx(
                    sizeof(copy_to_arch_cntx_struct),
                    action,
                    callback_func,
                    user_data);

        if (copy_cntx == NULL)
        {
            error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
            break;
        }

        copy_to_arch_init(copy_cntx, msg_id);

        read_hd = srv_sms_read_msg(
                    msg_id,
                    MMI_FALSE,
                    &copy_cntx->msg_data,
                    copy_to_arch_read_callback,
                    copy_cntx);

         CNTX_SET_SUB_HANDLE(copy_cntx, read_hd, copy_to_arch_read_abort_callback);
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_async_callback(
            action,
            MMI_FALSE,
            error_cause,
            NULL,
            0,
            user_data,
            callback_func);
    }

    return (SMS_HANDLE)copy_cntx;
}



/*****************************************************************************
 * FUNCTION
 *  copy_to_arch_read_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_to_arch_read_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_to_arch_cntx_struct *copy_cntx;
    srv_sms_copy_msg_to_archive_cb_struct copy_cb_data;
    MMI_BOOL is_done = MMI_TRUE;
    MMI_BOOL result;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_event_add_struct event_data;
    MMI_BOOL int_result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (copy_to_arch_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCH_READ_CALLBACK,
        callback_data->result, CNTX_IS_ABORT(copy_cntx));

    if (CNTX_IS_ABORT(copy_cntx))
    {
        result = MMI_TRUE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }
    else
    {
        result = callback_data->result;

        if (result)
        {
            U16 msg_id = copy_cntx->msg_id;
            EMSData *ems_data = (EMSData*)copy_cntx->msg_data.content_ems;
            srv_sms_msg_info_struct *msg_info = &copy_cntx->msg_info;
            U16 dest_entry_id;
            MMI_BOOL is_complete;


            srv_sms_get_msg_info(msg_info, msg_id);

            is_complete = srv_sms_is_msg_complete(msg_id);
        
            error_cause = srv_sms_archive_save_msg(
                            &dest_entry_id,
                            ems_data,
                            msg_info,
                            is_complete);

            if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
            {
                if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE_TO_ARCHIVE)
                {               
                    copy_cntx->dest_entry_id = dest_entry_id;

                    srv_sms_delete_msg(
                        msg_id,
                        copy_to_arch_del_callback,
                        copy_cntx);

                    is_done = MMI_FALSE;
                }
                else
                {
                    U16 dest_msg_id;

                    dest_msg_id = srv_sms_archive_entry_id_to_msg_id(dest_entry_id);

                    memcpy(&event_data.msg_info, &copy_cntx->msg_info, sizeof(srv_sms_msg_info_struct));
                    event_data.msg_info.folder_id = SRV_SMS_FOLDER_ARCHIVE;
                    event_data.msg_id = dest_msg_id;

                    /* Exec Add Message Interrupt Event */
                    int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, &event_data);

                    copy_cb_data.dest_msg_id = dest_entry_id;
                    copy_cb_data.fs_error = FS_NO_ERROR;
                }
            }
            else
            {
                result = MMI_FALSE;
                copy_cb_data.dest_msg_id = SRV_SMS_INVALID_MSG_ID;
                copy_cb_data.fs_error = srv_sms_archive_get_fs_error();
            }
        }
        else
        {
            error_cause = callback_data->cause;
            copy_cb_data.dest_msg_id = SRV_SMS_INVALID_MSG_ID;
            copy_cb_data.fs_error = FS_NO_ERROR;
        }
    }

    if (is_done)
    {
        copy_to_arch_deinit(copy_cntx);

        srv_sms_cntx_callback(
            copy_cntx,
            result,
            error_cause,
            &copy_cb_data);

        if (!int_result)
        {
            /* Exec Add Message Event */
            srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, &event_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_to_arch_abort_read_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_to_arch_read_abort_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_to_arch_cntx_struct *copy_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCH_READ_ABORT_CALLBACK, callback_data->result);

    copy_cntx = (copy_to_arch_cntx_struct*)callback_data->user_data;

    copy_to_arch_deinit(copy_cntx);

    /* Don't care the read abort result, always consider the abort is success */
    srv_sms_cntx_callback(
        copy_cntx,
        MMI_TRUE,
        SRV_SMS_CAUSE_ABORT,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  copy_to_arch_del_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_to_arch_del_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_to_arch_cntx_struct *copy_cntx;
    srv_sms_copy_msg_to_archive_cb_struct copy_cb_data;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_event_add_struct event_data;
    MMI_BOOL int_result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCH_DEL_CALLBACK, callback_data->result);

    copy_cntx = (copy_to_arch_cntx_struct*)callback_data->user_data;

    if (result)
    {
        U16 entry_id = copy_cntx->dest_entry_id;

        if (srv_sms_archive_is_msg_exist(entry_id))
        {
            U16 dest_msg_id;

            dest_msg_id = srv_sms_archive_entry_id_to_msg_id(entry_id);

            copy_cb_data.dest_msg_id = dest_msg_id;
            copy_cb_data.fs_error = FS_NO_ERROR;

            memcpy(&event_data.msg_info, &copy_cntx->msg_info, sizeof(srv_sms_msg_info_struct));
            event_data.msg_info.folder_id = SRV_SMS_FOLDER_ARCHIVE;
            event_data.msg_id = dest_msg_id;

            /* Exec Add Message Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_ADD_MSG, &event_data);
        }

        if (CNTX_IS_ABORT(copy_cntx))
        {
            result = MMI_FALSE;
            error_cause = SRV_SMS_CAUSE_ABORT;
        }
    }
    else
    {
        error_cause = srv_sms_archive_delete_msg(copy_cntx->dest_entry_id);

        if (CNTX_IS_ABORT(copy_cntx))
        {
            /* Set Abort result */
            if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }

            error_cause = SRV_SMS_CAUSE_ABORT;
        }
        else
        {
            error_cause = callback_data->cause;
            copy_cb_data.dest_msg_id = SRV_SMS_INVALID_MSG_ID;
            copy_cb_data.fs_error = FS_NO_ERROR;
        }
    }

    copy_to_arch_deinit(copy_cntx);

    srv_sms_cntx_callback(
        copy_cntx,
        result,
        error_cause,
        &copy_cb_data);

    if (!int_result)
    {
        /* Exec Add Message Event */
        srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_MSG, &event_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_to_archive_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum copy_to_arch_init(
                            copy_to_arch_cntx_struct *copy_cntx,
                            U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ems_data; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCH_INIT);

    ems_data = srv_sms_malloc_ems_data();

    MMI_ASSERT(ems_data);

    copy_cntx->msg_id = msg_id;
    copy_cntx->msg_data.para_flag = SRV_SMS_PARA_CONTENT_EMS;
    copy_cntx->msg_data.content_ems = ems_data;

    return SRV_SMS_CAUSE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_to_archive_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_to_arch_deinit(copy_to_arch_cntx_struct *copy_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_TO_ARCH_DEINIT);

    srv_sms_free_ems_data(copy_cntx->msg_data.content_ems);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_from_archive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static SMS_HANDLE srv_sms_copy_from_archive(
                    U16 msg_id,
                    srv_sms_action_enum action,
                    srv_sms_storage_enum dest_storage,
                    srv_sms_sim_enum dest_sim_id,
                    SrvSmsCallbackFunc callback_func,
                    void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_from_arch_cntx_struct *copy_cntx = NULL;

    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    EMSData *ems_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCHIVE,
        msg_id, action, dest_storage, dest_sim_id);

    if (srv_sms_is_archive_msg(msg_id) == MMI_TRUE)
    {
        U16 entry_id;
        srv_sms_cause_enum error_cause;
        srv_sms_msg_info_struct msg_info;

        entry_id = srv_sms_msg_id_to_archive_entry_id(msg_id);

        ems_data = (EMSData*)srv_sms_malloc_ems_data();

        error_cause = srv_sms_archive_read_msg(entry_id, MMI_FALSE, ems_data, &msg_info);

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            SMS_HANDLE save_hd;

            copy_cntx = srv_sms_alloc_cntx(
                            sizeof(copy_from_arch_cntx_struct),
                            action,
                            callback_func,
                            user_data);
            if (copy_cntx)
            {
                copy_cntx->msg_id = msg_id;
                copy_cntx->ems_data = ems_data;
                copy_cntx->callback_func = callback_func;
                copy_cntx->user_data = user_data;

                save_hd = srv_sms_get_save_handle();

                srv_sms_set_status(save_hd, msg_info.status);
                srv_sms_set_address(save_hd, msg_info.number);
                srv_sms_set_save_timestamp(save_hd, &msg_info.timestamp);
                srv_sms_set_pid(save_hd, msg_info.pid);
                srv_sms_set_sim_id(save_hd, dest_sim_id);
                srv_sms_set_content_ems(save_hd, ems_data);
                srv_sms_set_storage_type(save_hd, dest_storage);

                srv_sms_save_msg(
                    save_hd,
                    copy_from_arch_save_callback,
                    copy_cntx);

                CNTX_SET_SUB_HANDLE(copy_cntx, save_hd, copy_from_arch_save_abort_callback);
            }
            else
            {
                error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
            }
        }
    }

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        if (ems_data)
        {
            srv_sms_free_ems_data(ems_data);
        }

        srv_sms_async_callback(
            action,
            MMI_FALSE,
            error_cause,
            NULL,
            0,
            user_data,
            callback_func);
    }



    return (SMS_HANDLE)copy_cntx;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_archive_msg_save_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_from_arch_save_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_from_arch_cntx_struct *copy_cntx;
    srv_sms_move_archive_msg_cb_struct copy_cb_data;
    MMI_BOOL is_done = MMI_FALSE;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum error_cause = callback_data->cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (copy_from_arch_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCH_SAVE_CALLBACK,
        callback_data->result, CNTX_IS_ABORT(copy_cntx));

    if (result)
    {
        srv_sms_save_msg_cb_struct *save_cb_data;
        U16 saved_msg_id;

        save_cb_data = (srv_sms_save_msg_cb_struct*)callback_data->action_data;
        saved_msg_id = save_cb_data->msg_id;
        copy_cntx->dest_msg_id = saved_msg_id;

        if (CNTX_IS_ABORT(copy_cntx))
        {
            /* Delete the saved msg */
            srv_sms_delete_msg(
                saved_msg_id,
                copy_from_arch_del_saved_callback,
                copy_cntx);
        }
        else
        {
            if (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE_FROM_ARCHIVE)
            {
                srv_sms_delete_msg(
                    copy_cntx->msg_id,
                    copy_from_arch_del_ori_callback,
                    copy_cntx);
            }
            else
            {
                is_done = MMI_TRUE;
                copy_cb_data.dest_msg_id = saved_msg_id;
            }
        }
    }
    else
    {
        is_done = MMI_TRUE;

        if (CNTX_IS_ABORT(copy_cntx))
        {
            /* If saved failed, the abort result is TRUE */
            result = MMI_TRUE;
            error_cause = SRV_SMS_CAUSE_ABORT;
        }
    }

    if (is_done)
    {
        copy_from_arch_deinit(copy_cntx);
        srv_sms_cntx_callback(
            copy_cntx,
            result,
            error_cause,
            &copy_cb_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_from_arch_save_abort_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_from_arch_save_abort_callback(srv_sms_callback_struct* callback_data) {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_from_arch_cntx_struct *copy_cntx;
    MMI_BOOL result = callback_data->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCH_SAVE_ABORT_CALLBACK, callback_data->result);

    copy_cntx = (copy_from_arch_cntx_struct*)callback_data->user_data;

    if ((!result) && (CNTX_GET_ACTION(copy_cntx) == SRV_SMS_ACTION_MOVE_FROM_ARCHIVE))
    {
        srv_sms_save_msg_cb_struct *save_cb_data;
        U16 saved_msg_id;

        save_cb_data = (srv_sms_save_msg_cb_struct*)callback_data->action_data;
        saved_msg_id = save_cb_data->msg_id;

        copy_cntx->dest_msg_id = saved_msg_id;

        /* Delete the saved msg */
        srv_sms_delete_msg(
            saved_msg_id,
            copy_from_arch_del_saved_callback,
            copy_cntx);
    }
    else
    {
        copy_from_arch_deinit(copy_cntx);

        srv_sms_cntx_callback(
            copy_cntx,
            result,
            SRV_SMS_CAUSE_ABORT,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_from_arch_del_ori_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_from_arch_del_ori_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_from_arch_cntx_struct *copy_cntx;
    MMI_BOOL result = callback_data->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cntx = (copy_from_arch_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCH_DEL_ORI_CALLBACK,
        callback_data->result, CNTX_IS_ABORT(copy_cntx));

    if (CNTX_IS_ABORT(copy_cntx))
    {
        result = MMI_FALSE;
    }

    if (result)
    {
        srv_sms_move_archive_msg_cb_struct copy_cb_data;

        copy_cb_data.dest_msg_id = copy_cntx->dest_msg_id;

        copy_from_arch_deinit(copy_cntx);

        srv_sms_cntx_callback(
            copy_cntx,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &copy_cb_data);
    }
    else
    {
        /* Delete the saved msg */
        srv_sms_delete_msg(
            copy_cntx->dest_msg_id,
            copy_from_arch_del_saved_callback,
            copy_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  copy_from_arch_del_saved_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_from_arch_del_saved_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    copy_from_arch_cntx_struct *copy_cntx;
    srv_sms_move_archive_msg_cb_struct copy_cb_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCH_DEL_SAVED_CALLBACK, callback_data->result);

    copy_cntx = (copy_from_arch_cntx_struct*)callback_data->user_data;

    copy_cb_data.dest_msg_id = copy_cntx->dest_msg_id;

    copy_from_arch_deinit(copy_cntx);

    srv_sms_cntx_callback(
        copy_cntx,
        callback_data->result,
        SRV_SMS_CAUSE_ABORT,
        &copy_cb_data);
}


/*****************************************************************************
 * FUNCTION
 *  copy_from_arch_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void copy_from_arch_deinit(copy_from_arch_cntx_struct* copy_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_FROM_ARCH_DEINIT);

    srv_sms_free_ems_data(copy_cntx->ems_data);
}
#endif /* __SRV_SMS_ARCHIVE__ */


#ifdef __SRV_SMS_MULTI_ADDR__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_msg_ext_addr(
        U16 msg_id,
        U16 ext_addr_index,
        srv_sms_update_addr_struct* update_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_addr_node_struct *addr_node;
    U16 addr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_EXT_ADDR, msg_id, ext_addr_index);

    addr_id = srv_sms_get_ext_addr_id(msg_id, ext_addr_index);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY);

    addr_node = &srv_sms_addr_list[addr_id];

    if (addr_node)
    {
        srv_sms_event_update_struct event_data;
        MMI_BOOL int_result;
    #ifdef __SRV_SMS_MULTI_ADDR_REPORT__
        U32 i;
        srv_sms_sr_status_enum sr_status[SRV_SMS_MAX_SEG];
    #endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

        event_data.msg_id = msg_id;
        event_data.change_para_flag = SRV_SMS_PARA_NONE;
        srv_sms_get_msg_info(&event_data.old_msg_info, msg_id);
    
    #ifdef __SRV_SMS_MULTI_ADDR_REPORT__
        srv_sms_sr_get_total_status(update_info->report_id, sr_status);

        if (update_info->total_seg > SRV_SMS_MAX_SEG)
        {
            addr_node->total_seg = SRV_SMS_MAX_SEG;
        }
        else
        {
            addr_node->total_seg = update_info->total_seg;
        }

        for (i = 0; i < SRV_SMS_MAX_SEG; i++)
        {
            addr_node->tp_st[i] = (U8)sr_status[i];
            addr_node->msg_ref[i] = update_info->msg_ref[i];
        }

        event_data.change_para_flag |= SRV_SMS_PARA_MSG_REF | SRV_SMS_PARA_DELIVERY_STATUS;
    #endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

        addr_node->status = update_info->status;
        event_data.change_para_flag = SRV_SMS_PARA_STATUS;

        srv_sms_write_addr_record(addr_id, addr_node);

        srv_sms_get_msg_info(&event_data.new_msg_info, msg_id);

        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);

        if (!int_result)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);
        }
    }
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_update_tcard_msg_ext_addr(
                U16 msg_id,
                U16 ext_addr_index,
                srv_sms_update_addr_struct* update_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_addr_node_struct *addr_node;
    U16 addr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_EXT_ADDR, msg_id, ext_addr_index);

    addr_id = srv_sms_get_tcard_ext_addr_id(msg_id, ext_addr_index);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);

    addr_node = &srv_sms_tcard_addr_list[addr_id - SRV_SMS_MAX_ADDR_ENTRY];

    if (addr_node)
    {
        srv_sms_event_update_struct event_data;
		srv_tcard_op_struct read_cntx;
        MMI_BOOL int_result;
    #ifdef __SRV_SMS_MULTI_ADDR_REPORT__
        U32 i;
        srv_sms_sr_status_enum sr_status[SRV_SMS_MAX_SEG];
    #endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

        event_data.msg_id = msg_id;
        event_data.change_para_flag = SRV_SMS_PARA_NONE;
        srv_sms_get_msg_info(&event_data.old_msg_info, msg_id);
    
    #ifdef __SRV_SMS_MULTI_ADDR_REPORT__
        srv_sms_sr_get_total_status(update_info->report_id, sr_status);

        if (update_info->total_seg > SRV_SMS_MAX_SEG)
        {
            addr_node->total_seg = SRV_SMS_MAX_SEG;
        }
        else
        {
            addr_node->total_seg = update_info->total_seg;
        }

        for (i = 0; i < SRV_SMS_MAX_SEG; i++)
        {
            addr_node->tp_st[i] = (U8)sr_status[i];
            addr_node->msg_ref[i] = update_info->msg_ref[i];
        }

        event_data.change_para_flag |= SRV_SMS_PARA_MSG_REF | SRV_SMS_PARA_DELIVERY_STATUS;
    #endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

        addr_node->status = update_info->status;
        event_data.change_para_flag = SRV_SMS_PARA_STATUS;

        
		read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
		read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_ADDR_INFO;
		read_cntx.start_record_id = addr_id - SRV_SMS_MAX_ADDR_ENTRY;
		read_cntx.record_num = 1;
		srv_tcard_sync_write_record(&read_cntx,(CHAR*)addr_node);

        srv_sms_get_msg_info(&event_data.new_msg_info, msg_id);

        int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);

        if (!int_result)
        {
            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, &event_data);
        }
    }
}

#endif

#endif /* __SRV_SMS_MULTI_ADDR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_id_to_index
 * DESCRIPTION
 *  a safe api for changing SMS SRV SIM id into SIM index
 *  if no No SIM is matched, it returns 0 as default and will tell user with the is_valid_sim
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_sms_sim_id_to_index(srv_sms_sim_enum sim_id, MMI_BOOL *is_valid_sim)
{

    S32 i = 0;
    S32 total_sim;
    MMI_BOOL is_found;
    const srv_sms_sim_enum sim_array[] = { 
                                SRV_SMS_SIM_1
                            #if (MMI_MAX_SIM_NUM >= 2)
                                ,SRV_SMS_SIM_2
                            #if (MMI_MAX_SIM_NUM >= 3)
                                ,SRV_SMS_SIM_3
                            #if (MMI_MAX_SIM_NUM >= 4)
                                ,SRV_SMS_SIM_4
                            #endif /* MMI_MAX_SIM_NUM >= 4 */
                            #endif /* MMI_MAX_SIM_NUM >= 3 */
                            #endif /* MMI_MAX_SIM_NUM >= 2 */
                                              };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_sim = sizeof(sim_array)/sizeof(srv_sms_sim_enum);
    for (i = 0; i < total_sim; i++)
    {
        if (sim_array[i] == sim_id)
        {
            break;
        }
    }
    is_found = (MMI_BOOL)(total_sim != i);
    if(is_valid_sim != NULL)
    {
        *is_valid_sim = is_found;
    }
    if(is_found)
    {
        return i;
    }
    return 0;
}

#endif /* __MOD_SMSAL__ */
