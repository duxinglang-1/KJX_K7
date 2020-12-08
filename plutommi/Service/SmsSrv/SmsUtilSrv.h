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
 *  SmsUtilSrv.h
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
 * removed!
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
#include "SmsProtSrv.h"
#include "Ems.h"
#include "SmsAtHandlerSrv.h"
#include "SmsConverterSrv.h"
#include "SmsStorageSrv.h"
#include "SmsStorageCoreSrv.h"




#define SRV_SMS_INVALID_BITMAP_INDEX        0xFFFF
#define SRV_SMS_DELIVERY_REPORT_SIZE      15
#define SRV_SMS_HIDDEN_FLAG                     (0x08)

#define SRV_SMS_SEND_ILM(dest_mod, msg_id, local_ptr) \
            mmi_frm_send_ilm(dest_mod, (oslMsgType)msg_id, (oslParaType*)local_ptr, NULL)
extern storage_manager_cntx_struct storage_cntx;

#ifdef __SRV_SMS_AT_SUPPORT__
extern U32 in_atcm_delete ;
extern U32 in_atcm_cmgl ;
#endif

extern MMI_BOOL copy_move_list;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_total_size;
extern U16 srv_sms_outbox_total_size;
extern U16 srv_sms_drafts_total_size;
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_total_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_tcard_size;
extern U16 srv_sms_outbox_tcard_size;
extern U16 srv_sms_drafts_tcard_size;
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_tcard_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
extern U16 srv_sms_outbox_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
extern U16 srv_sms_drafts_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
extern U16 srv_sms_outbox_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
extern U16 srv_sms_drafts_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_show_size;
extern U16 srv_sms_outbox_show_size;
extern U16 srv_sms_drafts_show_size;
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_show_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_inbox_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
extern U16 srv_sms_outbox_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
extern U16 srv_sms_drafts_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
extern U16 srv_sms_unsent_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif

extern MMI_BOOL is_in_sim_refresh[SMS_SIM_NUM];
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
extern U16 srv_sms_sim_size;
#endif


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern srv_sms_tcard_action_cntx_struct action_cntx;
#endif

#ifdef __SRV_SMS_ARCHIVE__
extern U16 srv_sms_archive_size;
#endif /* __SRV_SMS_ARCHIVE__ */


typedef void (*SrvSmsFreeFunc)(void *buffer);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    /* the function to free the ation_data in callback_data, 
     * if the free_func is NULL, it will use OslMfree to free
     */
    SrvSmsFreeFunc free_func;
    SrvSmsCallbackFunc callback_func;
    srv_sms_callback_struct callback_data;
} srv_sms_evt_callback_struct;
typedef struct
{
    SRV_SMS_HANDLE_HEADER
    srv_sms_spdu_struct *spdu_list[SRV_SMS_MAX_SEG];
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct *tcard_spdu_list[SRV_SMS_MAX_SEG];
#endif
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    U16 msg_id;
    MMI_BOOL change_status;
    srv_sms_msg_data_struct *msg_data;
} srv_sms_read_cntx_struct;

typedef struct
{
    srv_sms_storage_enum storage_type;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_read_pdu_cntx_struct;

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
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct *tcard_pdu;
#endif

} srv_sms_change_status_cntx_struct;

typedef struct
{
    void *dummy;
} srv_sms_event_refresh_struct;

#ifdef __SRV_SMS_AT_SUPPORT__
#define STORAGE_INVOKE_CALLBACK(cntx, result, cause, action_data)   \
            srv_sms_exit_mmi_operating();       \
            srv_sms_cntx_callback(              \
                cntx,                           \
                result,                         \
                cause,                          \
                action_data)
#else
#define STORAGE_INVOKE_CALLBACK(cntx, result, cause, action_data)   \
                srv_sms_cntx_callback(              \
                    cntx,                           \
                    result,                         \
                    cause,                          \
                    action_data)
#endif/*__SRV_SMS_AT_SUPPORT__*/

#define SMS_ASYNC_CALLBACK(action, result, cause, data, userdata, cb_func)   \
            srv_sms_async_callback(             \
                action,                         \
                result,                         \
                cause,                          \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define SMS_ASYNC_SUCC_CALLBACK(action, data, userdata, cb_func)   \
            srv_sms_async_callback(             \
                action,                         \
                MMI_TRUE,                       \
                SRV_SMS_CAUSE_NO_ERROR,         \
                data,                           \
                sizeof(*(data)),                \
                userdata,                       \
                cb_func);
#define SMS_ASYNC_ERR_CALLBACK(action, cause, userdata, cb_func)   \
            srv_sms_async_callback(             \
                action,                         \
                MMI_FALSE,                      \
                cause,                          \
                NULL,                           \
                0,                              \
                userdata,                       \
                cb_func);

#define SRV_SMS_POST_CALLBACK_EX(_action, _result, _cause, _data, _userdata, _cb_func, _free_func) \
            do                                                                      \
            {                                                                       \
                srv_sms_evt_callback_struct post_evt;                               \
                                                                                    \
                MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_SRV_SMS_ASYNC_CALLBACK);       \
                post_evt.free_func = _free_func;                                    \
                post_evt.callback_func = _cb_func;                                  \
                post_evt.callback_data.result = _result;                            \
                post_evt.callback_data.cause = _cause;                              \
                post_evt.callback_data.action = _action;                            \
                post_evt.callback_data.action_data = _data;                         \
                post_evt.callback_data.user_data = _userdata;                       \
                MMI_FRM_POST_EVENT(&post_evt, srv_sms_async_callback_proc, NULL);   \
            } while (0)

#define SRV_SMS_POST_CALLBACK(_action, _result, _cause, _data, _userdata, _cb_func) \
            SRV_SMS_POST_CALLBACK_EX(_action, _result, _cause, _data, _userdata, _cb_func, NULL)

#define SRV_SMS_POST_SUCC_CALLBACK_EX(_action, _data, _userdata, _cb_func, _free_func) \
            SRV_SMS_POST_CALLBACK_EX(_action, MMI_TRUE, SRV_SMS_CAUSE_NO_ERROR, _data, _userdata, _cb_func, _free_func);





extern U16 srv_sms_get_list_size_for_send(srv_sms_box_enum msg_box_type);
extern U16 srv_sms_get_msg_id_for_send(srv_sms_box_enum msg_box_type, U16 list_index);


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_set_tcard_msg_node(srv_sms_msg_node_struct *msg_node,srv_sms_tcard_msg_node_struct *tcard_msg_node);
extern void srv_sms_set_msg_node(srv_sms_tcard_msg_node_struct *tcard_msg_node,srv_sms_msg_node_struct *msg_node);
extern MMI_BOOL srv_sms_is_tcard_sms_valid(U16 msg_id);
extern void srv_sms_delete_invalid_tcard_sms(U16 msg_id);

#endif
extern MMI_BOOL srv_sms_check_sms_handle(SMS_HANDLE sms_handle, srv_sms_action_enum action);

extern void srv_sms_callback(
                srv_sms_action_enum action,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data,
                void *user_data,
                SrvSmsCallbackFunc callback_func);

extern void srv_sms_succ_callback(
                srv_sms_action_enum action,
                void *action_data,
                void *user_data,
                SrvSmsCallbackFunc callback_func);

extern void srv_sms_error_callback(
                srv_sms_action_enum action,
                srv_sms_cause_enum cause,
                void *user_data,
                SrvSmsCallbackFunc callback_func);

extern void srv_sms_async_callback(
                srv_sms_action_enum action,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data,
                U32 action_data_size,
                void *user_data,
                SrvSmsCallbackFunc callback_func);

extern MMI_BOOL srv_sms_exec_interrupt_event(
                    U16 event_id,
                    void* event_info);

extern void srv_sms_set_msg_data(SMS_HANDLE sms_handle, srv_sms_int_msg_data_struct *msg_data);

extern void srv_sms_set_content_asc(MMI_BOOL is_asc_content, srv_sms_int_msg_data_struct *int_msg_data);

extern void srv_sms_convert_l4_num_to_ascii_num(U8 *ascii_number, l4c_number_struct *l4_number, U8 max_ascii_num_len);
extern void srv_sms_convert_ascii_num_to_l4_num(l4c_number_struct *l4_number, U8 *ascii_number);

#ifdef __SRV_SMS_RECENT_EVENT__
extern void srv_sms_set_msg_recent_event_flag(U16 msg_id, MMI_BOOL flag);
extern void srv_sms_set_pdu_recent_event_flag(U16 index, MMI_BOOL flag);
extern MMI_BOOL srv_sms_get_pdu_recent_event_flag(U16 index);
extern void srv_sms_read_sms_recent_event_setting(void);
#endif /* __SRV_SMS_RECENT_EVENT__ */

extern U16 srv_sms_get_bitmap_index(U16 start_index, U8 *bitmap, U16 bitmap_size);
extern void srv_sms_set_bitmap_index(U16 index, U8 *bitmap);
extern void srv_sms_clear_bitmap_index(U16 index, U8 *bitmap);
extern MMI_BOOL srv_sms_check_bitmap_index(U16 index, U8 *bitmap);

extern void srv_sms_emit_event(U32 event_id, void* event_info);

extern void srv_sms_init_sms_counter(void);
extern void srv_sms_update_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type);

extern srv_sms_sim_enum srv_sms_sim_index_to_sim_id(U32 index);
extern U32 srv_sms_sim_id_to_sim_index(srv_sms_sim_enum sim_id);
extern mmi_sim_enum srv_sms_sim_id_to_mmi_sim(srv_sms_sim_enum sim_id);

extern U32 srv_sms_get_local_sec(void);

extern srv_sms_int_msg_data_struct* srv_sms_get_int_msg_data(SMS_HANDLE sms_handle);
extern srv_sms_int_msg_data_struct* srv_sms_alloc_int_msg_data(void);
extern void srv_sms_free_int_msg_data(srv_sms_int_msg_data_struct *msg_data);

extern void srv_sms_set_msg_ref(SMS_HANDLE sms_handle, U8 msg_ref[], U8 total);
extern void srv_sms_set_delivery_status(SMS_HANDLE sms_handle, U16 report_id);

extern void* srv_sms_alloc_cntx(
                U32 size,
                srv_sms_action_enum action,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
extern void srv_sms_free_cntx(void* cntx);

extern void srv_sms_cntx_callback(
                void *cntx,
                MMI_BOOL result,
                srv_sms_cause_enum cause,
                void *action_data);

extern void srv_sms_pdu_block_init(void);
extern void* srv_sms_alloc_pdu_block(void);
extern void srv_sms_free_pdu_block(void *buffer);


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_tcard_pdu_block_init(void);
extern void* srv_sms_alloc_tcard_pdu_block(void);
extern void srv_sms_free_tcard_pdu_block(void *buffer);
#endif 


extern mmi_ret srv_sms_async_callback_proc(mmi_event_struct *param);

extern MMI_BOOL srv_sms_cmp_asc_num(char* dest, char* src);

#ifdef __SRV_SMS_TEMPLATE__
extern MMI_BOOL srv_sms_template_init_proc(void);
#endif

#ifdef __SMS_R8_NATION_LANGUAGE__
extern EMSNationalLanguageType srv_sms_get_system_ems_lang_type(void);
#endif /* __SMS_R8_NATION_LANGUAGE__ */

extern U8 srv_sms_storage_type_to_protocol_mem(srv_sms_storage_enum storage_type);
extern void srv_sms_read_msg_deinit(srv_sms_read_cntx_struct *read_cntx);
extern void srv_sms_read_msg_change_status(srv_sms_read_cntx_struct* read_cntx);
extern void srv_sms_read_msg_callback(srv_sms_callback_struct *callback_data);
extern void srv_sms_read_msg_succ_hdlr(srv_sms_read_cntx_struct* read_cntx);
extern void srv_sms_read_msg_error_hdlr(
                srv_sms_read_cntx_struct* read_cntx,
                srv_sms_cause_enum error_cause);
extern void srv_sms_read_msg_update_callback(srv_sms_callback_struct *callback_data);
extern void srv_sms_read_pdu_callback(srv_sms_callback_struct *callback_data);
extern MMI_BOOL srv_sms_get_list_and_size(
                        U16 **msg_id_list,
                        U16 *msg_list_size,
                        srv_sms_box_enum msg_box_type);
extern void srv_sms_save_msg_callback(srv_sms_callback_struct *callback_data);
extern void srv_sms_change_status_callback(srv_sms_callback_struct *callback_data);
extern void srv_sms_copy_callback(srv_sms_callback_struct *callback_data);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern MMI_BOOL srv_sms_get_show_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type);
extern MMI_BOOL srv_sms_get_total_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type);
extern MMI_BOOL srv_sms_get_tcard_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type);
extern void srv_sms_tcard_add_msg_list(MMI_BOOL sort_flag, U16 msg_id, srv_sms_box_enum msg_box_type);

extern void srv_sms_tcard_delete_msg_list(U16 msg_id, srv_sms_box_enum msg_box_type);
extern void srv_sms_set_show_list(srv_sms_box_enum msg_box_type);
extern void srv_sms_tcard_update_msg_list(U16 msg_id ,srv_sms_box_enum srv_box_type,srv_sms_box_enum dest_box_type);

#endif
#endif /* __SRV_SMS_UTIL_SRV_H__ */

