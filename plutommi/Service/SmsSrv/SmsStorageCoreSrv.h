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
 *  SmsStorageCore.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager Core Internal Header File
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_STORAGE_CORE_SRV_H__
#define __SMS_STORAGE_CORE_SRV_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_msg_context.h"
#include "SmsSrvGProt.h"
#include "SmsStorageSrv.h"
#include "SmsProtSrv.h"
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#include "SmsStorageTcardSrv.h"
#endif




#define SRV_SMS_INVALID_PDU_ID                  0xFFFF       
#define SRV_SMS_INVALID_INDEX                   0xFFFF       

#define SRV_SMS_MAX_SIM_SPDU_SIZE               176

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
} srv_sms_node_flag_enum;


typedef struct
{
    U8 segment;
    U8 type;
    U8 read_count;
    U8 status;
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 msg_ref;
    U8 tp_st;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
    U16 prev_pdu_id;
    U16 next_pdu_id;
} srv_sms_pdu_node_struct;

#ifdef __SRV_SMS_MULTI_ADDR__
/* Make sure the structure is same as nvram_ef_srv_sms_addr_struct */
typedef struct
{
    U16 next_addr_id;
    U8 status;
#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
    U8 total_seg;
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U8 tp_st[SRV_SMS_MAX_SEG];
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */
    U8 address[SRV_SMS_MAX_ADDR_LEN + 1];
} srv_sms_addr_record_struct;
#endif /* __SRV_SMS_MULTI_ADDR__ */

typedef struct
{
    /* These parameters are the previous status of the memory, 
     * for handling the memory change */
    MMI_BOOL is_sim_valid[SMS_SIM_NUM];
    srv_sms_mem_enum mem_full_type[SMS_SIM_NUM];

    U16 me_total;
    U16 me_used;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 tcard_total;
    U16 tcard_used;
#endif
    U16 sim_start[SMS_SIM_NUM];
    U16 sim_total[SMS_SIM_NUM];
    U16 sim_used[SMS_SIM_NUM];
} sms_memory_status_struct;

typedef struct
{
    MMI_BOOL is_ready;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    MMI_BOOL is_tcard_ready;
    MMI_BOOL is_tsms_ready;
#endif
    U16 total_msg_num;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 total_tcard_msg_num;
    U16 unused_tcard_msg_head_id;
    U16 used_tcard_msg_tail_id;
#endif
    /* The head of the unused MSG; Before this it, all of the MSGs are used;
     * After it, the MSGs may be unused; For Find Unused Msg Node */
    U16 unused_msg_head_id;
    /* The tail of the used MSG, Before this it, the MSGs may be used;
     * After it, all of the MSGs are unused; For Search Msg */
    U16 used_msg_tail_id;
#ifdef __SRV_SMS_MULTI_ADDR__
    U16 unused_addr_num;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 unused_tcard_addr_num;
#endif
#endif /* __SRV_SMS_MULTI_ADDR__ */
    sms_memory_status_struct memory_status;
} storage_manager_cntx_struct;

typedef struct
{
    srv_sms_storage_enum storage_type;
    U8 curr_seg;
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 msg_ref;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
    srv_sms_spdu_struct* spdu_data;
} srv_sms_add_pdu_struct;

typedef struct
{
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 msg_ref;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
    srv_sms_para_enum update_flag;
    srv_sms_spdu_struct* spdu_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct* tcard_spdu_data;
#endif
} srv_sms_update_pdu_struct;

/* Add PDU Callback Data Structure */
typedef struct
{
    U8 curr_seg;
    U16 pdu_id;
} srv_sms_add_pdu_cb_struct;

/* Delete PDU Callback Data Struture */
typedef struct
{
    void *dummy;
} srv_sms_delete_pdu_cb_struct;

/* Update PDU Callback Data Struture */
typedef struct
{
    void *dummy;
} srv_sms_update_pdu_cb_struct;

typedef void(*SrvSmsTriggerFunc)(void*user_data);

typedef struct pdu_trigger_struct
{
    srv_sms_action_enum action;
    U16 pdu_id;
    SrvSmsTriggerFunc trigger_func;
    void *user_data;
    struct pdu_trigger_struct *next;
} srv_sms_pdu_trigger_struct;



typedef struct 
{
    MMI_BOOL is_hiden;
    MMI_BOOL is_backgroud;
    srv_sms_cause_enum cause;
    srv_sms_delete_cntx_struct *delete_cntx;  
    srv_sms_event_delete_struct *event_info;
} srv_sms_delete_msg_node_struct;


typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 msg_id;
    SMS_HANDLE save_handle;
    srv_sms_para_enum update_flag;

    U8 curr_index;
    U8 total_pdu;
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    srv_sms_spdu_struct *ori_spdu[SRV_SMS_MAX_SEG];
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 ori_msg_ref[SRV_SMS_MAX_SEG];
    srv_sms_sr_status_enum sr_status[SRV_SMS_MAX_SEG];
    U16 report_id;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct *tcard_pdu;
#endif
    srv_sms_cause_enum error_cause;
} srv_sms_update_cntx_struct;


extern storage_manager_cntx_struct storage_cntx;
extern srv_sms_msg_node_struct srv_sms_msg_list[SRV_SMS_MAX_SMS_ENTRY];
extern srv_sms_pdu_node_struct srv_sms_pdu_list[SRV_SMS_MAX_SMS_ENTRY];
#ifdef __SRV_SMS_MULTI_ADDR__
extern srv_sms_addr_node_struct srv_sms_addr_list[SRV_SMS_MAX_ADDR_ENTRY];
#endif /* __SRV_SMS_MULTI_ADDR__ */
void srv_sms_init_pdu_node(srv_sms_pdu_node_struct *pdu_node);
extern void srv_sms_storage_reset_data(void);

extern U16 srv_sms_add_msg_node(srv_sms_msg_node_struct *msg_node);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern U16 srv_sms_add_tcard_msg_node(srv_sms_tcard_msg_node_struct *msg_node);
extern void srv_sms_update_tcard_msg_node(
            U16 msg_id,
            srv_sms_msg_node_struct *msg_node,
            U8 curr_seg);

#endif
extern void srv_sms_delete_msg_node(U16 msg_id, srv_sms_delete_msg_node_struct *delete_msg_cntx);
extern void srv_sms_update_msg_node(
                U16 msg_id,
                srv_sms_msg_node_struct *msg_node,
                U8 curr_seg);
extern void srv_sms_update_msg_status(U16 msg_id);
extern void srv_sms_concat_pdu_to_msg(U16 msg_id, U16 pdu_id);

extern void srv_sms_concat_pdu_list(U16 msg_id, U16 pdu_id_list[], U8 total_pdu);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_concat_tcard_pdu_list(U16 msg_id, U16 pdu_id_list[], U8 total_pdu);
#endif

extern U16 srv_sms_search_concatenated_sms(srv_sms_msg_node_struct *msg_node, U8 curr_seg);

#ifdef __SRV_SMS_DELIVERY_STATUS__
extern U16 srv_sms_search_pdu(char* number, U8 msg_ref, srv_sms_sim_enum sim_id);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

extern srv_sms_msg_node_struct* srv_sms_get_msg_node(U16 msg_id);


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern srv_sms_tcard_msg_node_struct* srv_sms_get_tcard_msg_node(U16 msg_id);
#endif 
extern void srv_sms_get_msg_info(srv_sms_msg_info_struct* msg_info, U16 msg_id);

#ifdef __SRV_SMS_MULTI_ADDR__
extern srv_sms_status_enum srv_sms_get_msg_node_status(srv_sms_msg_node_struct* msg_node);
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_DELIVERY_STATUS__ 
extern srv_sms_sr_status_enum srv_sms_get_sr_status(srv_sms_msg_node_struct *msg_node);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

extern MMI_BOOL srv_sms_is_msg_exist_ext(U16 msg_id);
extern MMI_BOOL srv_sms_is_msg_valid(U16 msg_id);

extern MMI_BOOL srv_sms_is_msg_hidden(U16 msg_id);
extern void srv_sms_hide_msg_node(U16 msg_id);
extern void srv_sms_unhide_msg_node(U16 msg_id);
extern MMI_BOOL srv_sms_check_msg_op_conflict(U16 msg_id, srv_sms_action_enum action);

extern U16 srv_sms_get_total_used_sms_space(void);
extern U16 srv_sms_get_unused_space(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id);
extern MMI_BOOL srv_sms_is_enough_unused_space(srv_sms_storage_enum *storage_type, srv_sms_sim_enum sim_id, U16 number);

extern U16 srv_sms_get_msg_id_by_pdu(U16 pdu_id);
extern U8 srv_sms_get_msg_pdu_id(U16 pdu_id_array[], U16 msg_id);
extern U8 srv_sms_get_msg_pdu_id_ext(U16 pdu_id_array[], U16 msg_id);
#ifdef __SRV_SMS_DELIVERY_STATUS__
extern U8 srv_sms_get_msg_ref(U8 msg_ref[], U16 msg_id);
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

extern U8 srv_sms_get_msg_pdu_num_by_storage(
            U16 msg_id,
            srv_sms_storage_enum storage_type);
extern U8 srv_sms_get_msg_pdu_id_by_storage(
            U16 pdu_id_array[],
            U16 msg_id,
            srv_sms_storage_enum storage_type);
extern srv_sms_storage_enum srv_sms_get_storage_type_by_pdu(U16 pdu_id_list[], U8 total_pdu);

extern void srv_sms_add_pdu_node(U16 pdu_id, srv_sms_pdu_node_struct* pdu_node);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_add_tcard_pdu_node(U16 pdu_id, srv_sms_tcard_pdu_node_struct* pdu_node);
#endif
extern void srv_sms_delete_pdu_node(U16 pdu_id);
extern srv_sms_pdu_node_struct* srv_sms_get_pdu_node(U16 pdu_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern srv_sms_tcard_pdu_node_struct* srv_sms_get_tcard_pdu_node(U16 pdu_id);
#endif
extern srv_sms_storage_enum srv_sms_get_pdu_storage_type(U16 pdu_id);
extern U8 srv_sms_get_msg_total_seg(U16 msg_id);

extern MMI_BOOL srv_sms_is_pdu_exist(U16 pdu_id);
extern srv_sms_status_enum srv_sms_get_pdu_status(U16 pdu_id);

extern U16 srv_sms_pdu_id_to_record_index(
            U16 pdu_id,
            srv_sms_storage_enum *storage_type,
            srv_sms_sim_enum *sim_id);
extern U16 srv_sms_record_index_to_pdu_id(
            U16 record_index,
            srv_sms_storage_enum storage_type,
            srv_sms_sim_enum sim_id);

extern U16 srv_sms_me_record_index_to_pdu_id(U16 record_index);
extern U16 srv_sms_pdu_id_to_me_record_index(U16 pdu_id);
extern U16 srv_sms_sim_record_index_to_pdu_id(U16 record_index, srv_sms_sim_enum sim_id);
extern U16 srv_sms_pdu_id_to_sim_record_index(U16 pdu_id, srv_sms_sim_enum* sim_id);

extern U32 srv_sms_pdu_id_to_sim_index(U16 pdu_id);

extern MMI_BOOL srv_sms_check_msg_flag(U16 msg_id, srv_sms_node_flag_enum flag);
extern MMI_BOOL srv_sms_check_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag);
extern void srv_sms_update_msg_callback(srv_sms_callback_struct *callback_data);

extern void srv_sms_set_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag);
extern void srv_sms_clear_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag);

extern void srv_sms_clear_set_pdu_array_flag(
                U16 pdu_id_list[],
                U8 total_pdu,
                srv_sms_node_flag_enum flag,
                MMI_BOOL is_clear);

extern void srv_sms_add_pdu(
                srv_sms_add_pdu_struct* add_data,
                SrvSmsCallbackFunc callback_func,
                void* user_data);
extern void srv_sms_delete_pdu(
                U16 pdu_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);
extern void srv_sms_update_pdu(
                U16 pdu_id,
                srv_sms_update_pdu_struct* update_data,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

extern void srv_sms_read_sim_sms(
                U16 index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern void srv_sms_read_tcard_sms(
                U16 index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

extern void srv_sms_write_tcard_sms(
                U16 index,
                srv_sms_tcard_spdu_struct *spdu_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
#endif
extern void srv_sms_handle_mem_change(MMI_BOOL flag);

extern MMI_BOOL srv_sms_is_sim_valid(srv_sms_sim_enum sim_id);
extern void srv_sms_set_pdu_trigger(
                U16 pdu_id,
                srv_sms_action_enum action,
                SrvSmsTriggerFunc trigger_func,
                void* user_data);

#ifdef __SRV_SMS_MULTI_ADDR__
extern U16 srv_sms_get_ext_addr_num(U16 start_addr_id);
extern U16 srv_sms_get_ext_addr_id(U16 msg_id, U16 addr_index);
extern void srv_sms_load_ext_addr(
                SrvSmsCallbackFunc callback_func,
                void *user_data);
extern srv_sms_cause_enum srv_sms_save_ext_addr(
                            srv_sms_addr_struct *addr_list,
                            U16* start_addr_id,
                            U16* total_num);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern srv_sms_cause_enum srv_sms_save_tcard_ext_addr(
                                    srv_sms_addr_struct *addr_list,
                                    U16* start_addr_id,
                                    U16* total_num);
extern U16 srv_sms_get_tcard_ext_addr_num(U16 start_addr_id);
extern U16 srv_sms_get_tcard_ext_addr_id(U16 msg_id, U16 addr_index);


#endif

extern srv_sms_cause_enum srv_sms_duplicate_ext_addr(
                            U16 src_addr_id,
                            U16* dest_addr_id,
                            U16* total_num);
extern void srv_sms_del_ext_addr(U16 start_addr_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
extern srv_sms_status_enum srv_sms_get_tcard_msg_node_status(srv_sms_tcard_msg_node_struct *msg_node);
extern U16 srv_sms_del_ext_tcard_addr(U16 start_addr_id);
#endif
extern void srv_sms_update_ext_addr_info(void);
extern void srv_sms_write_addr_record(U16 addr_id, srv_sms_addr_node_struct *addr);
#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
extern U16 srv_sms_search_ext_addr(U16* seg_index, char* number, U8 msg_ref, srv_sms_sim_enum sim_id);
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

#endif /* __SRV_SMS_MULTI_ADDR__ */

#endif /* __SMS_STORAGE_CORE_SRV_H__ */
