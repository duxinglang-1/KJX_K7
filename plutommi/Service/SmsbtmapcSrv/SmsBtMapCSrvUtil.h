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
 *  SmsBtMapCSrvUtil.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Utility API Internal Header File
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
 * removed!
  * 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_UTIL_SRV_H__
#define __SRV_SMS_UTIL_SRV_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "MMIDataType.h"
#include "ps_public_struct.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "Ems.h"
#include "SmsBtMapCSrvConverter.h"
#include "SmsBtMapCSrvGprot.h"
#include "mmi_rp_srv_sms_btmapc_def.h"

#define SRV_SMS_INVALID_BITMAP_INDEX        0xFFFF

typedef void (*SrvSmsBtmapcFreeFunc)(void *buffer);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    /* the function to free the ation_data in callback_data, 
     * if the free_func is NULL, it will use OslMfree to free
     */
    SrvSmsBtmapcFreeFunc free_func;
    SrvSmsCallbackFunc callback_func;
    srv_sms_callback_struct callback_data;
} srv_sms_btmapc_evt_callback_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    srv_sms_btmapc_spdu_struct *spdu_list[SRV_SMS_MAX_SEG];
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    U16 msg_id;
    MMI_BOOL change_status;
    srv_sms_msg_data_struct *msg_data;
} srv_sms_btmapc_read_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
} srv_sms_btmapc_get_msg_cntx_struct;


typedef struct
{
    srv_sms_storage_enum storage_type;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_btmapc_read_pdu_cntx_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 ori_status[SRV_SMS_MAX_SEG];
    U8 curr_index;
    U8 total_pdu;
    U16 msg_id;
    srv_sms_status_enum status;
    srv_sms_cause_enum error_cause;
} srv_sms_btmapc_change_status_cntx_struct;


#ifdef __SRV_SMS_BTMAPC_TEST__

typedef enum
{
    OUTPUT_MSG_LIST = 0,
    OUTPUT_MSG_DETAIL
}srv_sms_btmapc_output_type;

#endif


#define SMS_BTMAPC_ASYNC_CALLBACK(action, result, cause, data, userdata, cb_func)   \
            srv_sms_btmapc_async_callback(             \
                action,                         \
                result,                         \
                cause,                          \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define SMS_BTMAPC_ASYNC_SUCC_CALLBACK(action, data, userdata, cb_func)   \
            srv_sms_btmapc_async_callback(             \
                action,                         \
                MMI_TRUE,                       \
                SRV_SMS_CAUSE_NO_ERROR,         \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define SMS_BTMAPC_ASYNC_ERR_CALLBACK(action, cause, userdata, cb_func)   \
            srv_sms_btmapc_async_callback(             \
                action,                         \
                MMI_FALSE,                      \
                cause,                          \
                NULL,                           \
                0,                              \
                userdata,                       \
                cb_func);

#define SRV_SMS_BTMAPC_POST_CALLBACK_EX(_action, _result, _cause, _data, _userdata, _cb_func, _free_func) \
            do                                                                      \
            {                                                                       \
                srv_sms_btmapc_evt_callback_struct post_evt;                        \
                                                                                    \
                MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_SMS_BTMAPC_ASYNC_CALLBACK);       \
                post_evt.free_func = _free_func;                                    \
                post_evt.callback_func = _cb_func;                                  \
                post_evt.callback_data.result = _result;                            \
                post_evt.callback_data.cause = _cause;                              \
                post_evt.callback_data.action = _action;                            \
                post_evt.callback_data.action_data = _data;                         \
                post_evt.callback_data.user_data = _userdata;                       \
                MMI_FRM_POST_EVENT(&post_evt, srv_sms_btmapc_async_callback_proc, NULL);   \
            } while (0)

#define SRV_SMS_BTMAPC_POST_CALLBACK(_action, _result, _cause, _data, _userdata, _cb_func) \
            SRV_SMS_BTMAPC_POST_CALLBACK_EX(_action, _result, _cause, _data, _userdata, _cb_func, NULL)

#define SRV_SMS_BTMAPC_POST_SUCC_CALLBACK_EX(_action, _data, _userdata, _cb_func, _free_func) \
            SRV_SMS_BTMAPC_POST_CALLBACK_EX(_action, MMI_TRUE, SRV_SMS_CAUSE_NO_ERROR, _data, _userdata, _cb_func, _free_func);



#ifdef __SRV_SMS_BTMAPC_TEST__
extern void srv_sms_btmapc_write_file(srv_sms_btmapc_output_type output_type, void *data);
#endif


extern MMI_BOOL srv_sms_btmapc_check_sms_handle(SMS_HANDLE sms_handle, srv_sms_action_enum action);
extern void srv_sms_btmapc_callback(
                srv_sms_action_enum action,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data,
                void *user_data,
                SrvSmsCallbackFunc callback_func);
extern void srv_sms_btmapc_succ_callback(
                srv_sms_action_enum action,
                void *action_data,
                void *user_data,
                SrvSmsCallbackFunc callback_func);
extern void srv_sms_btmapc_error_callback(
                srv_sms_action_enum action,
                srv_sms_cause_enum cause,
                void *user_data,
                SrvSmsCallbackFunc callback_func);
extern void srv_sms_btmapc_async_callback(
                srv_sms_action_enum action,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data,
                U32 action_data_size,
                void *user_data,
                SrvSmsCallbackFunc callback_func);
extern MMI_BOOL srv_sms_btmapc_exec_interrupt_event(
                    U16 event_id,
                    void* event_info);
void srv_sms_btmapc_set_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data);
void srv_sms_btmapc_clear_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data);
extern void srv_sms_btmapc_set_msg_data(SMS_HANDLE sms_handle, srv_sms_btmapc_int_msg_data_struct *msg_data);
extern void srv_sms_btmapc_set_content_asc(MMI_BOOL is_asc_content, srv_sms_btmapc_int_msg_data_struct *int_msg_data);
extern U16 srv_sms_btmapc_get_bitmap_index(U16 start_index, U8 *bitmap, U16 bitmap_size);
extern void srv_sms_btmapc_set_bitmap_index(U16 index, U8 *bitmap);
extern void srv_sms_btmapc_clear_bitmap_index(U16 index, U8 *bitmap);
extern MMI_BOOL srv_sms_btmapc_check_bitmap_index(U16 index, U8 *bitmap);
extern void srv_sms_btmapc_emit_event(U32 event_id, void* event_info);
extern U32 srv_sms_btmapc_get_local_sec(void);
extern srv_sms_btmapc_int_msg_data_struct* srv_sms_btmapc_get_int_msg_data(SMS_HANDLE sms_handle);
extern srv_sms_btmapc_int_msg_data_struct* srv_sms_btmapc_alloc_int_msg_data(void);
extern void srv_sms_btmapc_free_int_msg_data(srv_sms_btmapc_int_msg_data_struct *msg_data);
extern void srv_sms_btmapc_set_msg_ref(SMS_HANDLE sms_handle, U8 msg_ref[], U8 total);
extern void srv_sms_btmapc_set_delivery_status(SMS_HANDLE sms_handle, U16 report_id);

extern void* srv_sms_btmapc_alloc_cntx(
                U32 size,
                srv_sms_action_enum action,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
extern void srv_sms_btmapc_free_cntx(void* cntx);
extern void srv_sms_btmapc_cntx_callback(
                void *cntx,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data);
extern mmi_ret srv_sms_btmapc_async_callback_proc(mmi_event_struct *param);
extern MMI_BOOL srv_sms_btmapc_cmp_asc_num(char* dest, char* src);
#ifdef __SMS_R8_NATION_LANGUAGE__
extern EMSNationalLanguageType srv_sms_btmapc_get_system_ems_lang_type(void);
#endif /* __SMS_R8_NATION_LANGUAGE__ */
extern void srv_sms_btmapc_read_msg_callback(srv_sms_callback_struct *callback_data);
extern void srv_sms_btmapc_read_msg_succ_hdlr(srv_sms_btmapc_read_cntx_struct* read_cntx);
extern void srv_sms_btmapc_read_msg_error_hdlr(
                srv_sms_btmapc_read_cntx_struct* read_cntx,
                srv_sms_cause_enum error_cause);
extern MMI_BOOL srv_sms_btmapc_get_list_and_size(
                        U16 **msg_id_list,
                        U16 *msg_list_size,
                        srv_sms_btmapc_box_enum msg_box_type);
extern MMI_BOOL srv_sms_btmapc_file_exist(const WCHAR *filename);

#endif /* __SRV_SMS_UTIL_SRV_H__ */

