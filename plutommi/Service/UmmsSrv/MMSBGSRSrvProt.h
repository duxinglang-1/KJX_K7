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
 *  MMSBGSRSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file local API's Variables and the local context for MMS BGSR Application
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#ifndef __MMI_BGSR_PROT_H_
#define __MMI_BGSR_PROT_H_

#include "MMI_features.h"

#include "MmsSrvGprot.h"

#include "FileMgrSrvGProt.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "WAPProfileSrvType.h"
#include "mma_struct.h"
#include "mma_api.h"
#include "Cbm_consts.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define SRV_MMS_BGSR_CALLBACK_NUM 1
#define SRV_MMS_BGSR_TOTAL_SOLUTION_NUM 2
#define SRV_MMS_BGSR_CFG_RETRY_QUOTA 2  /* can be customized */
#define SRV_MMS_BGSR_MAX_RSP_TEXT_LEN 40
#define SRV_MMS_BGSR_CFG_RETRY_TIMER 1
#define SRV_MMS_BGSR_POPUP_TIME 2000
#define SRV_MMS_BGSR_FAST_TIMEOUT_TIMER 5000    /* in ms */

#define SRV_MMS_BGSR_MAX_MSG_NUM    100
#define SRV_MMS_BGSR_ADM_MEM_SIZE 1000  /*  SRV_MMS_BGSR_MAX_MSG_NUM *           \
                                           (sizeof(srv_mms_bgsr_msg_struct))        \
                                           + sizeof(srv_mms_bgsr_context_struct) */
#define SRV_MMS_BGSR_MAX_NO_OF_TRIES 3
#define SRV_MMS_BGSR_SYSTEM_DRV SRV_FMGR_SYSTEM_DRV
#define SRV_MMS_BGSR_MEM_CARD_DRV SRV_FMGR_CARD_DRV
#define SRV_MMS_BGSR_FLDR_NAME  "@bgsr"
#define SRV_MMS_BGSR_MEM_CARD_FLDR_NAME  "@bgsr_1"      /* Implies Version */
#define SRV_MMS_BGSR_FILE_NAME "bgsr.o"
#define SRV_MMS_BGSR_FILE_NAME_BACKUP "bgsr.bk"
#define SRV_MMS_BGSR_FILE_NAME_TEMP "bgsr.tmp"
#define SRV_MMS_BGSR_DRIVE_NAME_LENGTH 5
#define SRV_MMS_BGSR_MAX_PATH_LEN 20
#define SRV_MMS_BGSR_MEM_CARD_BIT 0x80
/***************************************************************************** 
* Typedef
*****************************************************************************/

typedef struct srv_mms_bgsr_msg_struct_t
{
    kal_uint8 sim_id;
    kal_uint8 status;       /* srv_mms_bgsr_msg_status_enum */
    kal_uint8 result;       /* srv_mms_bgsr_result_enum */
    kal_uint8 msg_info;
    kal_uint32 msg_id;
    kal_uint8 ntt;
} srv_mms_bgsr_msg_struct;  /* size = 24 */

typedef struct
{
    srv_mms_bgsr_rsp_funcptr_type send_rsp_callback;
    srv_mms_bgsr_funcptr_type cancel_send_rsp_callback;
    srv_mms_bgsr_download_rsp_funcptr_type download_rsp_callback;
    srv_mms_bgsr_funcptr_type cancel_download_rsp_callback;
    srv_mms_bgsr_void_funcptr_type update_folder_callback;
    srv_mms_bgsr_funcptr_type update_menu_item_callback;
} srv_mms_bgsr_callback_struct;

typedef struct
{
    KAL_ADM_ID mem_pool_id;     /* ADM pool ID */
    kal_uint32 send_msg_id;
    kal_uint32 cancel_send_msg_id;
    kal_uint32 download_msg_id;
    kal_uint32 cancel_download_msg_id;
#ifdef __MMI_UMMS_JSR205__
    kal_uint32 java_send_msg_id;
    kal_uint8 java_sim_id;
#endif /* __MMI_UMMS_JSR205__ */ 
    kal_uint8 storage_exported;
    kal_uint8 sync_flag;
    kal_uint8 mma_ready_flag;
    kal_uint8 immd_retr_sim_id;
    kal_uint8 bgsr_state;
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    kal_uint32 vendor_send_msg_id;
    kal_uint8 vendor_sim_id;
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
#ifdef __MMI_MMS_FALLBACK__
    kal_uint32 acct_id;
    kal_uint32 fallback_send_id;
    kal_uint32 fallback_download_id;
    kal_uint8 fallback_sim_id;
    MMI_ID cbm_cui_id;
    kal_uint8 fallback_mask;
#endif /* __MMI_MMS_FALLBACK__ */ 
    kal_uint8 send_sim_id;
    kal_uint8 download_sim_id;
    kal_uint32 is_sim_valid;    /* 0th bit for Sim1; 1st bit for Sim2; so on... 0 => Invalid and 1 => Valid */
#ifdef __DM_LAWMO_SUPPORT__
    kal_uint8 lawmo_scomo_flag;
#endif 

    kal_uint8 srv_mms_bgsr_send_q;
    kal_uint8 srv_mms_bgsr_send_fail_q;
    kal_uint8 srv_mms_bgsr_download_q;
    kal_uint8 srv_mms_bgsr_download_fail_q;
    kal_uint8 srv_mms_bgsr_free_q;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    kal_uint8 srv_mms_bgsr_free_mem_q;
    kal_uint8 mem_card_state;
    kal_uint8 send_receive_flag;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
} srv_mms_bgsr_context_struct;

typedef enum
{
    SRV_MMS_BGSR_INTERRUPT_CALL = 0x01,
    SRV_MMS_BGSR_INTERRUPT_USB = 0x02,
    SRV_MMS_BGSR_INTERRUPT_FLIGHT_MODE = 0x04,
    SRV_MMS_BGSR_INTERRUPT_WAP_RESET = 0x08,
    SRV_MMS_BGSR_INTERRUPT_OP_CANCEL_ALL = 0x10,
    SRV_MMS_BGSR_INTERRUPT_TOTAL = 0xFF
} srv_mms_bgsr_interrupt_reason_enum;

typedef enum
{
    SRV_MMS_BGSR_ACTION_SEND_RSP,
    SRV_MMS_BGSR_ACTION_CANCEL_SEND_RSP,
    SRV_MMS_BGSR_ACTION_DOWNLOAD_RSP,
    SRV_MMS_BGSR_ACTION_CANCEL_DOWNLOAD_RSP,
    SRV_MMS_BGSR_ACTION_SAVE_RSP,
    SRV_MMS_BGSR_ACTION_DELETE_RSP,
    SRV_MMS_BGSR_ACTION_SYNC_MSG_RSP,
    SRV_MMS_BGSR_ACTION_GET_MEM_STATUS_RSP,
    SRV_MMS_BGSR_ACTION_TOTAL_NUM
} srv_mms_bgsr_action_type_enum;

typedef enum
{
    SRV_MMS_BGSR_INDICATOR_BUSY,
    SRV_MMS_BGSR_INDICATOR_IDLE,
    SRV_MMS_BGSR_INDICATOR_TOTAL_NUM
} srv_mms_bgsr_indicator_type_enum;

typedef enum
{
    SRV_MMS_BGSR_INDICATOR_NONE_OP,
    SRV_MMS_BGSR_INDICATOR_SEND_OP,
    SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP,
    SRV_MMS_BGSR_INDICATOR_IMMD_DOWNLOAD_OP,
    SRV_MMS_BGSR_INDICATOR_TOTAL_OP_NUM
} srv_mms_bgsr_indicator_op_enum;

typedef enum
{
    SRV_MMS_BGSR_POPUP_NORMAL,
    SRV_MMS_BGSR_POPUP_NO_SOUND,
    SRV_MMS_BGSR_POPUP_NO_POPUP,
    SRV_MMS_BGSR_POPUP_TOTAL_NUM
} srv_mms_bgsr_popup_type_enum;

typedef enum
{
    SRV_MMS_BGSR_MESSAGE_TYPE_SEND,
    SRV_MMS_BGSR_MESSAGE_TYPE_DOWNLOAD,
    SRV_MMS_BGSR_MESSAGE_TYPE_TOTAL
} srv_mms_bgsr_message_type_enum;

#ifdef __DM_LAWMO_SUPPORT__
typedef enum
{
    SRV_MMS_BGSR_LAWMO_SEND_MASK = 0x01,
    SRV_MMS_BGSR_LAWMO_DOWNLOAD_MASK = 0x02,
    SRV_MMS_BGSR_LAWMO_MASK_TOTAL = 0xFF
} srv_mms_bgsr_lawmo_flag_enum;
#endif /* __DM_LAWMO_SUPPORT__ */ 

typedef enum
{
    SRV_MMS_BGSR_SEND_AND_SAVE_INFO = (0x01) << 6,
    SRV_MMS_BGSR_IS_RR_INFO = (0x01) << 5,
    SRV_MMS_BGSR_FAIL_FLAG_INFO = (0x01) << 4,
    SRV_MMS_BGSR_NO_OF_TRIES_INFO = (0x03) << 2,
    SRV_MMS_BGSR_QUOTA_INFO = (0x03)
} srv_mms_bgsr_msg_info_enum;

#ifdef __MMI_MMS_FALLBACK__
typedef enum
{
    SRV_MMS_BGSR_FALLBACK_MASK_SENDING = 0x01,
    SRV_MMS_BGSR_FALLBACK_MASK_DOWNLOADING = 0x02,
    SRV_MMS_BGSR_FALLBACK_MASK_IMME_RETR = 0x04,
    SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK = 0x08,
    SRV_MMS_BGSR_FALLBACK_MASK_TOTAL = 0xFF
} srv_mms_bgsr_fallback_mask_enum;
#endif /* __MMI_MMS_FALLBACK__ */ 

typedef enum
{
    SRV_MMS_BGSR_STATE_NONE,
    SRV_MMS_BGSR_STATE_FILE_OP_PENDING,
    SRV_MMS_BGSR_STATE_MEM_CARD_FILE_OP_PENDING,
    SRV_MMS_BGSR_STATE_ACTIVE = 0x04,
    SRV_MMS_BGSR_STATE_TOTAL = 0xFF
} srv_mms_bgsr_state_enum;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
typedef enum
{
    SRV_MMS_BGSR_MEM_CARD_STATE_NONE,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PROCESS,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PENDING,
    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING,
    SRV_MMS_BGSR_MEM_CARD_STATE_TOTAL
} srv_mms_bgsr_mem_card_state_enum;
typedef enum
{
    SRV_MMS_BGSR_MEM_CARD_SENDING = 0x01,
    SRV_MMS_BGSR_MEM_CARD_DOWNLOADING = 0x02
} srv_mms_bgsr_send_receive_flag_enum;

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

typedef enum
{
    SRV_MMS_BGSR_SYNC_REQ_PH_MEM = 0x01,
    SRV_MMS_BGSR_SYNC_REQ_MEM_CARD = 0x02,
    SRV_MMS_BGSR_SYNC_REQ_PH_MEM_PENDING = 0x04,
    SRV_MMS_BGSR_SYNC_REQ_MEM_CARD_PENDING = 0x08,
    SRV_MMS_BGSR_PH_MEM_SYNCED = 0x10,
    SRV_MMS_BGSR_MEM_CARD_SYNCED = 0x20
} srv_mms_bgsr_sync_enum;

typedef enum
{
    SRV_MMS_BGSR_SIM1 = 0x01,
    SRV_MMS_BGSR_SIM2 = 0x02,
    SRV_MMS_BGSR_SIM3 = 0x04,
    SRV_MMS_BGSR_SIM4 = 0x08,
    SRV_MMS_BGSR_SIM_TOTAL = 0xFF
} srv_mms_bgsr_sim_id_enum;

extern srv_mms_bgsr_context_struct g_srv_mms_bgsr_context;
extern srv_mms_bgsr_context_struct *srv_mms_bgsr_p;
extern kal_uint8 srv_mms_bgsr_adm_mem[SRV_MMS_BGSR_ADM_MEM_SIZE];
extern srv_mms_bgsr_msg_struct ph_mem_msg_array[SRV_MMS_BGSR_MAX_MSG_NUM];
extern kal_uint8 ph_mem_next_array[SRV_MMS_BGSR_MAX_MSG_NUM];

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern srv_mms_bgsr_msg_struct mem_card_msg_array[SRV_MMS_BGSR_MAX_MSG_NUM];
extern kal_uint8 mem_card_next_array[SRV_MMS_BGSR_MAX_MSG_NUM];
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
/***************************************************************************** 
* Function Declaration
*****************************************************************************/
extern kal_uint8 srv_mms_bgsr_cancel_send_req(kal_uint32 msg_id);
extern kal_uint8 srv_mms_bgsr_send_rr_req(kal_uint8 sim_id, kal_uint32 msg_id, kal_uint8 storage_type);
extern void srv_mms_bgsr_download_req_no_progressing(kal_uint8 sim_id, kal_uint32 msg_id, kal_uint8 storage_type);
extern kal_uint8 srv_mms_bgsr_cancel_download_req(kal_uint32 msg_id);
extern kal_uint8 srv_mms_bgsr_get_fail_msg_count(void);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
extern void srv_mms_bgsr_multi_change_msg_notify(
                kal_uint32 msg_id[],
                kal_uint32 msg_count,
                srv_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
                srv_mms_bgsr_msg_box_enum msg_folder,
                srv_mms_bgsr_multi_funcptr_type change_msg_notify_callback);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void srv_mms_bgsr_mem_card_plug_in_notify(void);
extern void srv_mms_bgsr_mem_card_plug_out_notify(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
extern void srv_mms_bgsr_fmgr_format_notify(U16 drive);
extern void srv_mms_bgsr_interrupt_end_cb(kal_uint32 interrupt_reason);
extern kal_uint8 srv_mms_bgsr_send_mms_ind_hdlr(void *in_msg);
extern kal_uint8 srv_mms_bgsr_send_mms_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_abort_send_mms_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_delete_mms_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_save_mms_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_download_mms_ind_hdlr(void *in_msg);
extern kal_uint8 srv_mms_bgsr_download_mms_rsp(void *inMsg);
extern kal_uint8 srv_mms_bgsr_abort_download_mms_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_msg_is_valid_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_delete_folder_ind_hdlr(void *in_msg, int mod_src, void *ilm_p);
extern kal_uint8 srv_mms_bgsr_mma_ready_ind_hdlr(void *in_msg);
extern kal_uint8 srv_mms_bgsr_mma_terminate_ind_hdlr(void *in_msg);

#ifdef __MMI_UMMS_JSR205__
extern void srv_mms_bgsr_send_java_msg_req(U32 msg_id, U8 sim_id);
extern void srv_mms_bgsr_cancel_send_java_msg_req(U32 msg_id);
#endif /* __MMI_UMMS_JSR205__ */ 
extern void srv_mms_bgsr_set_rr_rsp(void *in_msg);
extern kal_uint8 srv_mms_bgsr_start_immd_retr_ind(void *inMsg);
extern kal_uint8 srv_mms_bgsr_stop_immd_retr_ind(void *inMsg);

#ifdef __MMI_MMS_FALLBACK__
extern void srv_mms_bgsr_suspend_mms_service_req(void);
extern kal_uint8 srv_mms_bgsr_suspend_mms_service_rsp(void *in_msg);
extern void srv_mms_bgsr_resume_mms_service_req(void);
extern kal_uint8 srv_mms_bgsr_resume_mms_service_rsp(void *in_msg);
#endif /* __MMI_MMS_FALLBACK__ */ 
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
extern void srv_mms_bgsr_vendor_send_msg_req(U32 msg_id, U8 sim_id);
#endif 

void srv_mms_bgsr_init(void);

#ifdef MMS_IN_LARGE_STORAGE
extern void srv_mms_bgsr_ph_mem_format_hdlr(void);
#endif 

extern kal_uint8 *srv_mms_bgsr_get_next_array(U8 index);
extern srv_mms_bgsr_msg_struct *srv_mms_bgsr_get_msg_array(U8 index);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void srv_mms_bgsr_init_mem_card_state_hdlr(void);
extern void srv_mms_bgsr_mem_card_plug_out_state_hdlr(void);
extern void srv_mms_bgsr_mem_card_plug_out_hdlr(void);
extern void srv_mms_bgsr_mem_card_plug_in_hdlr(void);
extern void srv_mms_bgsr_init_mem_card_file_system(void);
extern U8 srv_mms_bgsr_is_mem_card_sync(void);
extern void srv_mms_bgsr_read_from_mem_file(void);
extern void srv_mms_bgsr_init_mem_card_msg_array(void);
extern void srv_mms_bgsr_write_into_mem_card_file(void);
extern void srv_mms_bgsr_mem_card_format_hdlr(void);
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

extern U8 srv_mms_bgsr_is_ph_sync(void);
extern void srv_mms_bgsr_init_ph_mem_file_system(void);
extern void srv_mms_bgsr_write_into_ph_mem_file(void);
extern void srv_mms_bgsr_read_from_ph_mem_file(void);
extern kal_uint8 srv_mms_bgsr_generate_check_sum(kal_uint8 *data, kal_uint32 len);
extern U8 srv_mms_bgsr_extract_q(kal_uint32 msg_id, U8 *queue);
extern U8 srv_mms_bgsr_get_q(kal_uint32 msg_id, U8 queue);
extern BOOL srv_mms_bgsr_find_q(kal_uint32 msg_id, U8 queue, U8 fail_q);
extern void srv_mms_bgsr_enqueue(U8 msg, U8 *queue);
extern U8 srv_mms_bgsr_delete_queue(U8 *queue, kal_uint32 except_msg_id);
extern U8 srv_mms_bgsr_find_msg(U32 msg_id);
extern U8 srv_mms_bgsr_update_status(U8 local_msg, U8 status);

extern void srv_mms_bgsr_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
extern void srv_mms_bgsr_set_rr_flag_req(kal_uint32 msg_id, kal_uint8 flag);
extern void srv_mms_bgsr_set_no_of_tries(U8 index, U8 value);
extern U8 srv_mms_bgsr_get_no_of_tries(U8 index);
extern U8 srv_mms_bgsr_get_sim_id_value(U8 index);
extern void srv_mms_bgsr_set_sim_id(U8 index, U8 sim_id);

extern kal_uint32 srv_mms_bgsr_get_request_id(void);
extern void srv_mms_bgsr_init_context(void);
extern void srv_mms_bgsr_create_adm_mem(void);
extern void srv_mms_bgsr_set_protocol_event_handler(void);
extern BOOL srv_mms_bgsr_send_mms_req(U8 msg);
extern void srv_mms_bgsr_abort_send_mms_req(kal_uint32 msg_id);
extern void srv_mms_bgsr_delete_mms_req(kal_uint32 msg_id);
extern void srv_mms_bgsr_save_mms_req(kal_uint32 msg_id, kal_uint16 folder);
extern BOOL srv_mms_bgsr_download_mms_req(U8 msg);
extern void srv_mms_bgsr_abort_download_mms_req(kal_uint32 msg_id);
extern void srv_mms_bgsr_delete_rr_sending(srv_mms_bgsr_msg_box_enum msg_folder);
extern U8 srv_mms_bgsr_get_next_sending_node(void);
extern U8 srv_mms_bgsr_get_next_downloading_node(void);

extern srv_wap_prof_sim_id_enum srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(kal_uint8 bgsr_sim_id);
extern mma_sim_id_enum srv_mms_bgsr_convert_wap_sim_to_mma(kal_uint8 wap_sim_id);
extern void srv_mms_bgsr_show_mms_status_icon(
                const srv_mms_bgsr_indicator_type_enum status,
                srv_mms_bgsr_indicator_op_enum op_type);
extern kal_bool srv_mms_bgsr_is_message_ready(U8 message, U32 sim_valid, U8 message_type);
extern kal_bool srv_mms_bgsr_is_sim_profile_valid(U32 *sim_valid);

extern void srv_mms_bgsr_action_send_rsp(wap_mma_send_rsp_struct *send_rsp);
extern void srv_mms_bgsr_action_cancel_send_rsp(wap_mma_rsp_struct *cancel_send_rsp);
extern void srv_mms_bgsr_action_download_rsp(wap_mma_download_rsp_struct *download_rsp);
extern void srv_mms_bgsr_action_cancel_download_rsp(wap_mma_rsp_struct *cancel_dl_rsp);
extern void srv_mms_bgsr_action_save_rsp(wap_mma_save_rsp_struct *save_rsp);
extern void srv_mms_bgsr_action_delete_rsp(wap_mma_delete_rsp_struct *delete_rsp);
extern void srv_mms_bgsr_action_sync_rsp(wap_mma_msg_is_valid_rsp_struct *sync_rsp);
extern kal_uint16 *srv_mms_bgsr_set_fail_cause(void *msg_rsp, srv_mms_bgsr_message_type_enum message_type);
extern kal_uint8 srv_mms_bgsr_is_mma_ready(void);
extern void srv_mms_bgsr_timeout_procedure(void);
extern void srv_mms_bgsr_init_msg_array(void);
extern void srv_mms_bgsr_timeout_procedure(void);
extern kal_uint8 srv_mms_bgsr_is_ready(void);
extern void srv_mms_bgsr_sync(U8 storage_type);
extern kal_uint8 srv_mms_bgsr_mms_is_exported(void);
extern void srv_mms_bgsr_echo_current_info(void);

#ifdef __MMI_MMS_FALLBACK__
extern mmi_ret srv_mms_bgsr_bearer_fallback_proc(mmi_event_struct *event);
extern void srv_mms_bgsr_update_profile(U8 mma_sim_id);
extern void srv_mms_bgsr_send_select_rsp_handler(kal_uint8);
extern kal_uint8 srv_mms_bgsr_get_sim_id(kal_uint32 acct_id);
void srv_mms_bgsr_set_profile_req(srv_wap_prof_profile_content_struct *profile_struct, U8 mma_sim_id);
extern void srv_mms_bgsr_send_events(mmi_id evt_id, kal_uint32 act_id);
#endif /* __MMI_MMS_FALLBACK__ */ 
extern MMI_BOOL srv_mms_bgsr_is_any_waiting_msg(void);
extern U16 srv_mms_bgsr_waiting_msg_count(void);
extern kal_uint8 srv_mms_bgsr_is_sim_valid(kal_uint8 bgsr_sim_id);
extern srv_mms_bgsr_sim_id_enum srv_mms_bgsr_convert_mmi_sim_id_to_bgsr_sim_id(U8 mmi_sim_id);
extern kal_uint8 srv_mms_bgsr_convert_index(U8 index);
extern srv_mms_bgsr_sim_id_enum srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(U8 mma_sim_id);
extern mmi_sim_enum srv_mms_bgsr_convert_bgsr_sim_id_to_mmi_sim_id(U8 bgsr_sim_id);
extern cbm_sim_id_enum srv_mms_bgsr_convert_mma_sim_id_to_cbm_sim_id(U8 mma_sim_id);
#endif /* __MMI_BGSR_PROT_H_ */ 

