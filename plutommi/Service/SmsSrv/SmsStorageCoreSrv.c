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
 *  SmsStorageCoreSrv.c
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
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_timer_gprot.h"
#include "nvram_common_defs.h"
#include "MMI_common_app_trc.h"
#include "ProtocolEvents.h"
#include "mmi_msg_context.h"
#include "sim_common_enums.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"
#include "SmsUtilSrv.h"
#include "SmsSettingSrv.h"
#include "SmsStorageCoreSrv.h"
#include "SmsConverterSrv.h"
#ifdef __SRV_SMS_SIM_CUST_DATA__
#include "SmsStorageSimCustSrv.h"
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
#include "SimAccessSrvGprot.h"
#include "SmsBackupRestoreSrv.h"


/**************************************************************
* MARCO
**************************************************************/
//#define SRV_SMS_HIDDEN_FLAG                     (0x08)
#define SMS_MULTI_ADDR_MAX_READ_RECORDS         (2048 / (sizeof(srv_sms_addr_record_struct)))
#define ADDR_STATUS_USED_FLAG                   (0x80)

#ifdef __SRV_SMS_SIMBOX_SUPPORT__
#define MSG_NODE_CMP_START(msg_node)            ((U8*)&((msg_node)->storage_type))
#else /* __SRV_SMS_SIMBOX_SUPPORT__ */
#define MSG_NODE_CMP_START(msg_node)            ((U8*)&((msg_node)->mti))
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

#define MSG_NODE_CMP_END(msg_node)              ((U8*)&((msg_node)->start_pdu_id))

#define MSG_NODE_CMP_SIZE   \
        (MSG_NODE_CMP_END(((srv_sms_msg_node_struct*)0)) - MSG_NODE_CMP_START(((srv_sms_msg_node_struct*)0)))


#ifdef __SRV_SMS_MULTI_ADDR__
#define IS_VALID_ADDR_STATUS(status)                \
            (((status) == SRV_SMS_STATUS_UNSENT) ||   \
             ((status) == SRV_SMS_STATUS_SENT)   ||   \
             ((status) == SRV_SMS_STATUS_DRAFT))
#endif /* __SRV_SMS_MULTI_ADDR__ */

/**************************************************************
* Structure Declaration
**************************************************************/

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_add_pdu_cntx_struct;

typedef struct
{
    U16 pdu_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_delete_pdu_cntx_struct;


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef struct
{
    srv_sms_action_enum action;
    S32 result;
    S32 error_cause;
    void * action_data;
    void *user_data;
    SrvSmsCallbackFunc callback_func;
} srv_sms_tcard_sync_struct;
#endif

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
} srv_sms_update_pdu_cntx_struct;

typedef struct
{
#ifdef __SRV_SMS_SIM_CUST_DATA__
    U16 record_index;
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
    srv_sms_sim_enum sim_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_read_sim_sms_cntx_struct;


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef struct
{
    srv_sms_sim_enum sim_id;
    void* spdu;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_read_tcard_sms_cntx_struct;


#endif

typedef struct
{
#ifdef __SRV_SMS_SIM_CUST_DATA__
    U16 record_index;
    srv_sms_sim_cust_data_struct cust_data;
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
    srv_sms_sim_enum sim_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_write_sim_sms_cntx_struct;

#ifdef __SRV_SMS_MULTI_ADDR__
typedef struct
{
    U16 curr_addr_id;
    U16 amount;
    U16 remain;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} sms_load_addr_cntx_struct;
#endif /* __SRV_SMS_MULTI_ADDR__ */


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
storage_manager_cntx_struct storage_cntx;
srv_sms_msg_node_struct srv_sms_msg_list[SRV_SMS_MAX_SMS_ENTRY];
srv_sms_pdu_node_struct srv_sms_pdu_list[SRV_SMS_MAX_SMS_ENTRY];
#ifdef __SRV_SMS_MULTI_ADDR__
srv_sms_addr_node_struct srv_sms_addr_list[SRV_SMS_MAX_ADDR_ENTRY];
#endif /* __SRV_SMS_MULTI_ADDR__ */
static srv_sms_pdu_trigger_struct *trigger_head;


/**************************************************************
* Static Function Declaration
**************************************************************/
static U16 srv_sms_get_unused_msg_id(void);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static U16 srv_sms_get_unused_tcard_msg_id(void);
#ifdef __SRV_SMS_MULTI_ADDR__

static void srv_sms_add_tcard_addr_node(U16 addr_id, srv_sms_tcard_addr_node_struct* addr);
static void srv_sms_del_tcard_addr_node(U16 addr_id);
#endif
static MMI_BOOL srv_sms_check_tcard_msg_flag(U16 msg_id, srv_sms_node_flag_enum flag);

#endif

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
static void srv_sms_update_msg_content(U16 msg_id, char* content, U8 curr_seg);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_update_tcard_msg_content(U16 msg_id, char* content, U8 curr_seg);
#endif/* __SRV_SMS_TCARD_STORAGE_SUPPORT__ */
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

static void srv_sms_pdu_trigger_hdlr(U16 pdu_id);

static void srv_sms_add_pdu_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_delete_pdu_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_update_pdu_callback(srv_sms_callback_struct *callback_data);

static void srv_sms_read_sim_sms_callback(srv_sim_cb_struct* callback_data);
static void srv_sms_write_sim_sms_callback(srv_sim_cb_struct* callback_data);

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_read_tcard_sms_callback(srv_tcard_callback_struct *callback_data);
static void srv_sms_tcard_delete_sync_handle(void *arg);

#endif


static void srv_sms_write_sim_sms(
                U16 index,
                srv_sms_sim_enum sim_id,
                srv_sms_spdu_struct* spdu_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

static void srv_sms_read_me_sms(
                U16 index,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_write_me_sms(
                U16 index,
                srv_sms_spdu_struct* spdu_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

static U16 srv_sms_get_unused_pdu_id(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id);
static U16 srv_sms_get_unused_pdu_id_between(U16 start_pdu_id, U16 end_pdu_id);
static void srv_sms_get_start_and_end_pdu_id(
                srv_sms_storage_enum storage_type,
                srv_sms_sim_enum sim_id,
                U16 *start_pdu_id,
                U16 *end_pdu_id);

static srv_sms_cause_enum srv_sms_check_common_pdu_error(U16 pdu_id, srv_sms_action_enum action);
static MMI_BOOL srv_sms_check_pdu_op_conflict(U16 pdu_id, srv_sms_action_enum action);

static void srv_sms_increment_used_memory(U16 pdu_id);
static void srv_sms_decrement_used_memory(U16 pdu_id);

#ifdef __SRV_SMS_MULTI_ADDR__
static void srv_sms_load_ext_addr_hdlr(sms_load_addr_cntx_struct *load_cntx);
static void srv_sms_load_ext_addr_callback(srv_sms_callback_struct* callback_data);
static void srv_sms_read_multi_addr_record(
                U16 start_addr_id,
                U16 record_amount,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_update_ext_addr_record(U16 start_addr_id);
static void srv_sms_add_addr_node(U16 addr_id, srv_sms_addr_node_struct* addr);
static void srv_sms_del_addr_node(U16 addr_id);
static void srv_sms_addr_to_addr_node(
                srv_sms_addr_node_struct *addr_node,
                srv_sms_addr_struct* addr);
static void srv_sms_addr_record_to_addr_node(
                srv_sms_addr_node_struct* addr_node,
                srv_sms_addr_record_struct *addr_record);
static void srv_sms_addr_node_to_addr_record(
                srv_sms_addr_record_struct *addr_record,
                srv_sms_addr_node_struct* addr_node);
static U16 srv_sms_get_unused_addr_between(U16 start_index, U16 end_index);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_addr_to_tcard_addr_node(
                srv_sms_tcard_addr_node_struct *addr_node,
                srv_sms_addr_struct* addr);
#endif/* __SRV_SMS_TCARD_STORAGE_SUPPORT__ */
#endif /* __SRV_SMS_MULTI_ADDR__ */

//static void srv_sms_delete_msg_node_callback(srv_sms_callback_struct *callback_data);

/**************************************************************
* Function Defination
**************************************************************/
void srv_sms_init_pdu_node(srv_sms_pdu_node_struct *pdu_node)
{
    pdu_node->type = SRV_SMS_NODE_USED; 
    pdu_node->read_count = 0; 
    pdu_node->next_pdu_id = SRV_SMS_INVALID_PDU_ID; 
    pdu_node->prev_pdu_id = SRV_SMS_INVALID_PDU_ID; 
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_storage_reset_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_storage_reset_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STORAGE_RESET_DATA);

    for (i = 0; i < SRV_SMS_MAX_SMS_ENTRY; i++)
    {
        srv_sms_msg_list[i].status = SRV_SMS_STATUS_NONE;
        srv_sms_msg_list[i].start_pdu_id = SRV_SMS_INVALID_PDU_ID;

        srv_sms_pdu_list[i].type = SRV_SMS_NODE_NONE;
        srv_sms_pdu_list[i].status = SRV_SMS_STATUS_NONE;
    }

    memset(&storage_cntx, 0, sizeof(storage_manager_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_msg_id
 * DESCRIPTION
 *  Get unused message ID
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 (Unused Message ID)
 *****************************************************************************/
static U16 srv_sms_get_unused_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 start_msg_id = storage_cntx.unused_msg_head_id;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_MSG_ID, start_msg_id, SRV_SMS_MAX_SMS_ENTRY);

    for (i = start_msg_id; i < SRV_SMS_MAX_SMS_ENTRY; i++)
    {
        /* If the status is invalid, this msg node is not used */
        if (srv_sms_msg_list[i].status == SRV_SMS_STATUS_NONE)
        {
            msg_id = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_MSG_ID_1, msg_id);

    return msg_id;
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_tcard_delete_sync_handle
 * DESCRIPTION
 *  Get unused message ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_tcard_delete_sync_handle(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_sync_struct *sync_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sync_cntx = (srv_sms_tcard_sync_struct*)arg;
    SRV_SMS_POST_CALLBACK(
        sync_cntx->action,
        sync_cntx->result,
        sync_cntx->error_cause,
        sync_cntx->action_data,
        sync_cntx->user_data,
        sync_cntx->callback_func);
    OslMfree(sync_cntx);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_msg_id
 * DESCRIPTION
 *  Get unused message ID
 * PARAMETERS
 *  void
 * RETURNS
 *  U16 (Unused Message ID)
 *****************************************************************************/
static U16 srv_sms_get_unused_tcard_msg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 start_msg_id = storage_cntx.unused_tcard_msg_head_id;
    U32 i;
    srv_sms_tcard_msg_node_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_MSG_ID, start_msg_id, SRV_SMS_MAX_SMS_ENTRY);
    msg_list = srv_sms_get_tcard_msg_list();
    for (i = start_msg_id; i < SRV_SMS_MAX_TCARD_ENTRY; i++)
    {
        /* If the status is invalid, this msg node is not used */
        if (msg_list[i].status == SRV_SMS_STATUS_NONE)
        {
            msg_id = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_MSG_ID_1, msg_id);

    return msg_id;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_node
 * DESCRIPTION
 *  Add a Message Node
 * PARAMETERS
 *  msg_node        [IN] message node data
 * RETURNS
 *  U16 (the new Added Message ID)
 *****************************************************************************/
U16 srv_sms_add_msg_node(srv_sms_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE);

    unused_msg_id = srv_sms_get_unused_msg_id();

    if (unused_msg_id != SRV_SMS_INVALID_MSG_ID)
    {
       
        memcpy(&srv_sms_msg_list[unused_msg_id], msg_node, sizeof(srv_sms_msg_node_struct));

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_1, storage_cntx.total_msg_num);
        storage_cntx.total_msg_num++;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_2, storage_cntx.unused_msg_head_id);

        /* unused_msg_id is the first unused msg, so its next msg is the new unused msg */
        if (storage_cntx.unused_msg_head_id < SRV_SMS_MAX_SMS_ENTRY)
        {
            storage_cntx.unused_msg_head_id = unused_msg_id + 1;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_3, storage_cntx.used_msg_tail_id);
        if (unused_msg_id > storage_cntx.used_msg_tail_id)
        {
            storage_cntx.used_msg_tail_id = unused_msg_id;
        }
    }

    return unused_msg_id;
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_msg_node
 * DESCRIPTION
 *  Add a Message Node
 * PARAMETERS
 *  msg_node        [IN] message node data
 * RETURNS
 *  U16 (the new Added Message ID)
 *****************************************************************************/
U16 srv_sms_add_tcard_msg_node(srv_sms_tcard_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_msg_id;
    srv_sms_tcard_msg_node_struct *msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE);

    unused_msg_id = srv_sms_get_unused_tcard_msg_id();

    if (unused_msg_id != SRV_SMS_INVALID_MSG_ID)
    {
    #if 0//performent
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
        msg_list = srv_sms_get_tcard_msg_list();
        memcpy(&msg_list[unused_msg_id], msg_node, sizeof(srv_sms_tcard_msg_node_struct));

        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_1, storage_cntx.total_msg_num);
        storage_cntx.total_msg_num++;

        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_2, storage_cntx.unused_msg_head_id);

        /* unused_msg_id is the first unused msg, so its next msg is the new unused msg */
        if (storage_cntx.unused_tcard_msg_head_id < SRV_SMS_MAX_TCARD_ENTRY)
        {
            storage_cntx.unused_tcard_msg_head_id = unused_msg_id + 1;
        }

        //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_MSG_NODE_3, storage_cntx.used_msg_tail_id);
        if (unused_msg_id > storage_cntx.used_tcard_msg_tail_id)
        {
            storage_cntx.used_tcard_msg_tail_id = unused_msg_id;
        }
        return unused_msg_id + SRV_SMS_MAX_MSG_NUM;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }
    return SRV_SMS_INVALID_MSG_ID;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_delete_msg_node(U16 msg_id, srv_sms_delete_msg_node_struct *delete_msg_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 temp_msg_id;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct *msg_list;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE, msg_id);
    //temp_msg_id = msg_id;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
        msg_id -= SRV_SMS_MAX_MSG_NUM;
        msg_list = srv_sms_get_tcard_msg_list();
        if (msg_list[msg_id].status != SRV_SMS_STATUS_NONE)
        {
            srv_tcard_op_struct read_cntx;

            msg_list[msg_id].status = SRV_SMS_STATUS_NONE;
            msg_list[msg_id].start_pdu_id = SRV_SMS_INVALID_PDU_ID;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_1, storage_cntx.total_msg_num);
         
            storage_cntx.total_tcard_msg_num--;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_2, storage_cntx.unused_msg_head_id);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_3, storage_cntx.used_msg_tail_id);

           
            if (storage_cntx.unused_tcard_msg_head_id > msg_id)
            {
                storage_cntx.unused_tcard_msg_head_id = msg_id;
            }

            if ((msg_id == storage_cntx.used_tcard_msg_tail_id) && 
                     (storage_cntx.used_tcard_msg_tail_id > 0))
            {
                storage_cntx.used_tcard_msg_tail_id--;
            }
            read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
            read_cntx.start_record_id = msg_id;
            read_cntx.record_num = 1;
            srv_tcard_sync_write_record(&read_cntx,(CHAR*)(&msg_list[msg_id]));
            //if()
        }
    }
    else
#endif
    {
        MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

        if (srv_sms_msg_list[msg_id].status != SRV_SMS_STATUS_NONE)
        {
            /* Reset Msg Node to unused;
             * If the status is NONE, the start_pdu_id must be Invalid */
            srv_sms_msg_list[msg_id].status = SRV_SMS_STATUS_NONE;
            srv_sms_msg_list[msg_id].start_pdu_id = SRV_SMS_INVALID_PDU_ID;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_1, storage_cntx.total_msg_num);
            /* Decrement Total Msg Number */
            storage_cntx.total_msg_num--;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_2, storage_cntx.unused_msg_head_id);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_NODE_3, storage_cntx.used_msg_tail_id);

            /* Adjust remind (Unused Header, and Used Tail) index */
            if (storage_cntx.unused_msg_head_id > msg_id)
            {
                storage_cntx.unused_msg_head_id = msg_id;
            }

            /* If it is the last used msg, decrement the count */
            if ((msg_id == storage_cntx.used_msg_tail_id) && 
                     (storage_cntx.used_msg_tail_id > 0))
            {
                storage_cntx.used_msg_tail_id--;
            }
        }
    }
}

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
    #ifdef __SRV_SMS_AT_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_AT_SUPPORT__ */
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
    #ifdef __SRV_SMS_AT_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __SRV_SMS_AT_SUPPORT__ */
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
 *  srv_sms_update_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_msg_node(
        U16 msg_id,
        srv_sms_msg_node_struct *msg_node,
        U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_node_struct *curr_msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

    curr_msg_node = &srv_sms_msg_list[msg_id];

    if ((curr_msg_node->status & SRV_SMS_STATUS_READ) &&
        (msg_node->status & SRV_SMS_STATUS_UNREAD))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE_1);
        curr_msg_node->status &= SRV_SMS_STATUS_UNSUPPORTED;
        curr_msg_node->status |= SRV_SMS_STATUS_UNREAD;
    }

    if (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        curr_msg_node->status |= SRV_SMS_STATUS_UNSUPPORTED;
    }

    if ((curr_msg_node->storage_type == SRV_SMS_STORAGE_ME) &&
        (msg_node->storage_type == SRV_SMS_STORAGE_SIM))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE_2);
        curr_msg_node->storage_type = SRV_SMS_STORAGE_SIM;

    #ifndef __SRV_SMS_SIM_TIMESTAMP__
        if (msg_node->mti == SRV_SMS_MTI_SUBMIT)
        {
            curr_msg_node->timestamp = 0;
        }
    #endif /* __SRV_SMS_SIM_TIMESTAMP__ */
    }

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    srv_sms_update_msg_content(msg_id, (S8*)msg_node->content, curr_seg);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_tcard_msg_node(
        U16 msg_id,
        srv_sms_msg_node_struct *msg_node,
        U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_msg_node_struct *curr_msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);

    curr_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);

    if ((curr_msg_node->status & SRV_SMS_STATUS_READ) &&
        (msg_node->status & SRV_SMS_STATUS_UNREAD))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE_1);
        curr_msg_node->status &= SRV_SMS_STATUS_UNSUPPORTED;
        curr_msg_node->status |= SRV_SMS_STATUS_UNREAD;
    }

    if (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        curr_msg_node->status |= SRV_SMS_STATUS_UNSUPPORTED;
    }

    if ((curr_msg_node->storage_type == SRV_SMS_STORAGE_ME) &&
        (msg_node->storage_type == SRV_SMS_STORAGE_SIM))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_NODE_2);
        curr_msg_node->storage_type = SRV_SMS_STORAGE_SIM;

    #ifndef __SRV_SMS_SIM_TIMESTAMP__
        if (msg_node->mti == SRV_SMS_MTI_SUBMIT)
        {
            curr_msg_node->timestamp = 0;
        }
    #endif /* __SRV_SMS_SIM_TIMESTAMP__ */
    }

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    srv_sms_update_tcard_msg_content(msg_id, (S8*)msg_node->content, curr_seg);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_msg_status(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_node_struct *msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

    msg_node = &srv_sms_msg_list[msg_id];

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_STATUS, msg_id, msg_node->status);

    if ((msg_node->status & SRV_SMS_STATUS_READ) ||
        (msg_node->status & SRV_SMS_STATUS_UNREAD))
    {
        U32 next_pdu_id = msg_node->start_pdu_id;
        srv_sms_status_enum status = SRV_SMS_STATUS_READ;

        while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            if (srv_sms_pdu_list[next_pdu_id].status == SRV_SMS_STATUS_UNREAD)
            {
                status = SRV_SMS_STATUS_UNREAD;
                break;
            }

            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_STATUS, status);

        msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | status;
    }
}


#ifdef __SRV_SMS_MSG_INFO_CONTENT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_msg_content(U16 msg_id, char* content, U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
    U32 content_size = mmi_ucs2strlen(content) * ENCODING_LENGTH;
    U32 max_content_size = SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT, msg_id, curr_seg, content_size);

    if ((curr_pdu_id != SRV_SMS_INVALID_PDU_ID) && (content_size > 0))
    {
        U16 start_seg = srv_sms_pdu_list[curr_pdu_id].segment;
        S8 *msg_content = (S8*)srv_sms_msg_list[msg_id].content;
        U32 msg_content_size = mmi_ucs2strlen(msg_content) * ENCODING_LENGTH;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_1, start_seg, msg_content_size);

        if (curr_seg < start_seg)
        {
            if (((curr_seg + 1) == start_seg) && (msg_content_size > 0) && 
                (content_size < max_content_size))
            {
                U32 remain_size = max_content_size - content_size;
                U16 tmp_content[SRV_SMS_MSG_INFO_CONTENT_LEN + 1];

                if (remain_size > msg_content_size)
                {
                    remain_size = msg_content_size;
                    max_content_size = content_size + msg_content_size;
                }

                memcpy(tmp_content, msg_content, (SRV_SMS_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH);
                memcpy(msg_content, content, content_size);
                memcpy((msg_content + content_size), tmp_content, remain_size);
            }
            else
            {
                if (max_content_size > content_size)
                {
                    max_content_size = content_size;
                }
            
                memcpy(msg_content, content, max_content_size);
            }

            msg_content[max_content_size] = '\0';
            msg_content[max_content_size + 1] = '\0';
        }
        else
        {        
            if (msg_content_size < max_content_size)
            {
                U16 end_seg = start_seg;
                U32 prev_pdu_id = curr_pdu_id;

                curr_pdu_id = srv_sms_pdu_list[curr_pdu_id].next_pdu_id;

                while (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_2, prev_pdu_id, curr_pdu_id);

                    /* If the segments are continuous */
                    if ((srv_sms_pdu_list[prev_pdu_id].segment + 1) ==
                        srv_sms_pdu_list[curr_pdu_id].segment)
                    {
                        end_seg = srv_sms_pdu_list[curr_pdu_id].segment;

                        prev_pdu_id = curr_pdu_id;
                        curr_pdu_id = srv_sms_pdu_list[curr_pdu_id].next_pdu_id;
                    }
                    else
                    {
                        break;
                    }
                }

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_3, end_seg);

                if ((curr_seg - 1) == end_seg)
                {
                    if (msg_content_size > 0)
                    {
                        if (content_size > (max_content_size - msg_content_size))
                        {
                            content_size = (max_content_size - msg_content_size);
                        }
                        else
                        {
                            max_content_size = msg_content_size + content_size;
                        }
                    
                        memcpy(msg_content + msg_content_size, content, content_size);
                    }
                    else
                    {
                        if (max_content_size > content_size)
                        {
                            max_content_size = content_size;
                        }
                    
                        memcpy(msg_content, content, max_content_size);
                    }

                    msg_content[max_content_size] = '\0';
                    msg_content[max_content_size + 1] = '\0';
                }
            }
        }
    }
}







#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_tcard_msg_content(U16 msg_id, char* content, U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_pdu_id ;
    U32 content_size = mmi_ucs2strlen(content) * ENCODING_LENGTH;
    U32 max_content_size = SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT, msg_id, curr_seg, content_size);
    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
    curr_pdu_id = tcard_msg_node->start_pdu_id;
    if ((curr_pdu_id != SRV_SMS_INVALID_PDU_ID) && (content_size > 0))
    {
        U16 start_seg = srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].segment;
        S8 *msg_content = (S8*)tcard_msg_node->content;
        U32 msg_content_size = mmi_ucs2strlen(msg_content) * ENCODING_LENGTH;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_1, start_seg, msg_content_size);

        if (curr_seg < start_seg)
        {
            if (((curr_seg + 1) == start_seg) && (msg_content_size > 0) && 
                (content_size < max_content_size))
            {
                U32 remain_size = max_content_size - content_size;
                U16 tmp_content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1];

                if (remain_size > msg_content_size)
                {
                    remain_size = msg_content_size;
                    max_content_size = content_size + msg_content_size;
                }

                memcpy(tmp_content, msg_content, (SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1) * ENCODING_LENGTH);
                memcpy(msg_content, content, content_size);
                memcpy((msg_content + content_size), tmp_content, remain_size);
            }
            else
            {
                if (max_content_size > content_size)
                {
                    max_content_size = content_size;
                }
            
                memcpy(msg_content, content, max_content_size);
            }

            msg_content[max_content_size] = '\0';
            msg_content[max_content_size + 1] = '\0';
        }
        else
        {        
            if (msg_content_size < max_content_size)
            {
                U16 end_seg = start_seg;
                U32 prev_pdu_id = curr_pdu_id;

                curr_pdu_id = srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;

                while (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_2, prev_pdu_id, curr_pdu_id);

                    /* If the segments are continuous */
                    if ((srv_sms_tcard_pdu_list[prev_pdu_id - SRV_SMS_MAX_MSG_NUM].segment + 1) ==
                        srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].segment)
                    {
                        end_seg = srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].segment;

                        prev_pdu_id = curr_pdu_id;
                        curr_pdu_id = srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                    }
                    else
                    {
                        break;
                    }
                }

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_MSG_CONTENT_3, end_seg);

                if ((curr_seg - 1) == end_seg)
                {
                    if (msg_content_size > 0)
                    {
                        if (content_size > (max_content_size - msg_content_size))
                        {
                            content_size = (max_content_size - msg_content_size);
                        }
                        else
                        {
                            max_content_size = msg_content_size + content_size;
                        }
                    
                        memcpy(msg_content + msg_content_size, content, content_size);
                    }
                    else
                    {
                        if (max_content_size > content_size)
                        {
                            max_content_size = content_size;
                        }
                    
                        memcpy(msg_content, content, max_content_size);
                    }

                    msg_content[max_content_size] = '\0';
                    msg_content[max_content_size + 1] = '\0';
                }
            }
        }
    }
}
#endif
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_concat_pdu_to_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_concat_pdu_to_msg(U16 msg_id, U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_seg;
    U32 curr_pdu_id;
    U32 prev_pdu_id = SRV_SMS_INVALID_PDU_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);
    MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

    

    curr_seg = srv_sms_pdu_list[pdu_id].segment;
    curr_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_TO_MSG, msg_id, pdu_id, curr_pdu_id);

    while (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_pdu_list[curr_pdu_id].segment < curr_seg)
        {
            prev_pdu_id = curr_pdu_id;
            curr_pdu_id = srv_sms_pdu_list[curr_pdu_id].next_pdu_id;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_TO_MSG_1, curr_pdu_id, prev_pdu_id);
        }
        else
        {
            break;
        }
    }

    if (prev_pdu_id == SRV_SMS_INVALID_PDU_ID)
    {
        srv_sms_msg_list[msg_id].start_pdu_id = pdu_id;
        srv_sms_pdu_list[pdu_id].prev_pdu_id = msg_id;

        srv_sms_pdu_list[pdu_id].type |= SRV_SMS_NODE_FIRST;

        if (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            srv_sms_pdu_list[curr_pdu_id].type &= (~SRV_SMS_NODE_FIRST);
        }
    }
    else
    {
        srv_sms_pdu_list[prev_pdu_id].next_pdu_id = pdu_id;
        srv_sms_pdu_list[pdu_id].prev_pdu_id = prev_pdu_id;
    }

    srv_sms_pdu_list[pdu_id].next_pdu_id = curr_pdu_id;

    if (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        srv_sms_pdu_list[curr_pdu_id].prev_pdu_id = pdu_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_search_concatenated_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_search_concatenated_sms(srv_sms_msg_node_struct *msg_node, U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS, msg_node->total_seg, curr_seg);
#ifdef __SRV_SMS_MULTI_SIM__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_1, msg_node->sim_id);
#endif /* __SRV_SMS_MULTI_SIM__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_2, msg_node->storage_type);
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_3, msg_node->mti, msg_node->status, msg_node->pid, msg_node->ref_num);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_4, (S8*)msg_node->number);

    if (msg_node->total_seg > 1)
    {
        U32 i;
        U16 end_msg_id = storage_cntx.used_msg_tail_id + 1;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_5, end_msg_id);

        for (i = 0; i < end_msg_id; i++)
        {
            srv_sms_msg_node_struct *curr_msg_node = &srv_sms_msg_list[i];

            /* The Msg node is used */
            if (curr_msg_node->status != SRV_SMS_STATUS_NONE)
            {
                /* 1. If the MTI is DELIVER, the SMS may be UNREAD or READ status;
                 *    It will consider as same Concatenated SMS even if its status is not same. 
                 * 2. If the MTI is SUBMIT, it may be DRAFT, UNSENT, SENT;
                 *    If the status is not same, it is not a Concatenated SMS. */
                if ((memcmp(MSG_NODE_CMP_START(curr_msg_node), 
                        MSG_NODE_CMP_START(msg_node), MSG_NODE_CMP_SIZE) == 0) &&
                    ((curr_msg_node->mti != SRV_SMS_MTI_SUBMIT) || 
                     (curr_msg_node->status & msg_node->status)) &&
                    (strcmp((S8*)curr_msg_node->number, (S8*)msg_node->number) == 0))
                {
                    MMI_BOOL is_exist_same_seg = MMI_FALSE;
                    U32 next_pdu_id;

                    next_pdu_id = curr_msg_node->start_pdu_id;

                    do
                    {
                        U8 segment = srv_sms_pdu_list[next_pdu_id].segment;

                        if (segment == curr_seg)
                        {
                            is_exist_same_seg = MMI_TRUE;
                            break;
                        }

                        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
                    } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                    if (is_exist_same_seg == MMI_FALSE)
                    {
                        msg_id = i;
                        break;
                    }
                }
            }
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_13, msg_id);

    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_find_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_find_msg(srv_sms_find_msg_struct *find_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U32 i = SRV_SMS_INVALID_MSG_ID;
    U16 end_msg_id = storage_cntx.used_msg_tail_id + 1;
    srv_sms_msg_node_struct *msg_node;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG, end_msg_id, find_data->is_check_concat);

#ifdef __SRV_SMS_MULTI_SIM__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_1, find_data->sim_id);
#endif /* __SRV_SMS_MULTI_SIM__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_2, find_data->mti, find_data->pid);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_3, find_data->address);

    if (find_data->is_check_concat == MMI_FALSE)
    {
    #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        for (i = 0; i < end_msg_id; i++)
        {
            msg_node = &srv_sms_msg_list[i];

            /* The Msg node is used */
            if (msg_node->status != SRV_SMS_STATUS_NONE)
            {
                if (
                #ifdef __SRV_SMS_MULTI_SIM__
                    (msg_node->sim_id == find_data->sim_id) &&
                #endif /* __SRV_SMS_MULTI_SIM__ */
                    (msg_node->mti == find_data->mti) &&
                    (msg_node->pid == find_data->pid) &&
                    (strcmp((S8*)msg_node->number, find_data->address) == 0) && 
                    ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                     (find_data->storage_type == msg_node->storage_type)))
                {
                    msg_id = i;
                    break;
                }
            }
        }
    /*replace one msg, default msg will be replace first*/
    #else
        if (srv_sms_get_prefer_storage(find_data->sim_id) == SRV_SMS_STORAGE_TCARD && storage_cntx.memory_status.tcard_total > storage_cntx.memory_status.tcard_used)
        {    
            if(storage_cntx.is_tcard_ready)
            {
                srv_sms_tcard_msg_node_struct *msg_list;
                msg_list = srv_sms_get_tcard_msg_list();
                for (i = 0; i < storage_cntx.used_tcard_msg_tail_id + 1; i++)
                {
                    
                    tcard_msg_node = &msg_list[i];

                    /* The Msg node is used */
                    if (tcard_msg_node->status != SRV_SMS_STATUS_NONE)
                    {
                        if (
                        #ifdef __SRV_SMS_MULTI_SIM__
                            (tcard_msg_node->sim_id == find_data->sim_id) &&
                        #endif /* __SRV_SMS_MULTI_SIM__ */
                            (tcard_msg_node->mti == find_data->mti) &&
                            (tcard_msg_node->pid == find_data->pid) &&
                            (strcmp((S8*)tcard_msg_node->number, find_data->address) == 0) && 
                            ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                             (find_data->storage_type == tcard_msg_node->storage_type)))
                        {
                            msg_id = i + SRV_SMS_MAX_MSG_NUM;
                            break;
                        }
                    }
                }
                if (msg_id == SRV_SMS_INVALID_MSG_ID)
                {
                    for (i = 0; i < end_msg_id; i++)
                    {
                        msg_node = &srv_sms_msg_list[i];

                        /* The Msg node is used */
                        if (msg_node->status != SRV_SMS_STATUS_NONE)
                        {
                            if (
                            #ifdef __SRV_SMS_MULTI_SIM__
                                (msg_node->sim_id == find_data->sim_id) &&
                            #endif /* __SRV_SMS_MULTI_SIM__ */
                                (msg_node->mti == find_data->mti) &&
                                (msg_node->pid == find_data->pid) &&
                                (strcmp((S8*)msg_node->number, find_data->address) == 0) && 
                                ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                                 (find_data->storage_type == msg_node->storage_type)))
                            {
                                msg_id = i;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                for (i = 0; i < end_msg_id; i++)
                {
                    msg_node = &srv_sms_msg_list[i];

                    /* The Msg node is used */
                    if (msg_node->status != SRV_SMS_STATUS_NONE)
                    {
                        if (
                        #ifdef __SRV_SMS_MULTI_SIM__
                            (msg_node->sim_id == find_data->sim_id) &&
                        #endif /* __SRV_SMS_MULTI_SIM__ */
                            (msg_node->mti == find_data->mti) &&
                            (msg_node->pid == find_data->pid) &&
                            (strcmp((S8*)msg_node->number, find_data->address) == 0) && 
                            ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                             (find_data->storage_type == msg_node->storage_type)))
                        {
                            msg_id = i;
                            break;
                        }
                    }
                }
            }
        }
        else/*prefer storage is not tcard*/
        {
            for (i = 0; i < end_msg_id; i++)
            {
                msg_node = &srv_sms_msg_list[i];

                /* The Msg node is used */
                if (msg_node->status != SRV_SMS_STATUS_NONE)
                {
                    if (
                    #ifdef __SRV_SMS_MULTI_SIM__
                        (msg_node->sim_id == find_data->sim_id) &&
                    #endif /* __SRV_SMS_MULTI_SIM__ */
                        (msg_node->mti == find_data->mti) &&
                        (msg_node->pid == find_data->pid) &&
                        (strcmp((S8*)msg_node->number, find_data->address) == 0) && 
                        ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                         (find_data->storage_type == msg_node->storage_type)))
                    {
                        msg_id = i;
                        break;
                    }
                }
            }
            if (msg_id == SRV_SMS_INVALID_MSG_ID)
            {
                if (storage_cntx.is_tcard_ready)
                {
                    srv_sms_tcard_msg_node_struct *msg_list;
                    msg_list = srv_sms_get_tcard_msg_list();
                    for (i = 0; i < storage_cntx.used_tcard_msg_tail_id + 1; i++)
                    {
                        
                        tcard_msg_node = &msg_list[i];

                        /* The Msg node is used */
                        if (tcard_msg_node->status != SRV_SMS_STATUS_NONE)
                        {
                            if (
                            #ifdef __SRV_SMS_MULTI_SIM__
                                (tcard_msg_node->sim_id == find_data->sim_id) &&
                            #endif /* __SRV_SMS_MULTI_SIM__ */
                                (tcard_msg_node->mti == find_data->mti) &&
                                (tcard_msg_node->pid == find_data->pid) &&
                                (strcmp((S8*)tcard_msg_node->number, find_data->address) == 0) && 
                                ((find_data->storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || 
                                 (find_data->storage_type == tcard_msg_node->storage_type)))
                            {
                                msg_id = i + SRV_SMS_MAX_MSG_NUM;
                                break;
                            }
                        }
                    }
                }
            }            
        }
    #endif
    }
    else
    {
        U8 start_seg;
        U8 not_exist_seg;
        U8 total_seg;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_4, find_data->ref_num, find_data->total_seg, find_data->not_exist_seg);

        srv_sms_convert_segment(
            &total_seg,
            &start_seg,
            &not_exist_seg,
            find_data->total_seg,
            find_data->not_exist_seg);

        if (total_seg > 1)
        {
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            for (i = 0; i < end_msg_id; i++)
            {
                msg_node = &srv_sms_msg_list[i];

                /* The Msg node is used */
                if (msg_node->status != SRV_SMS_STATUS_NONE)
                {
                    if (
                    #ifdef __SRV_SMS_MULTI_SIM__
                        (msg_node->sim_id == find_data->sim_id) &&
                    #endif /* __SRV_SMS_MULTI_SIM__ */
                        (msg_node->mti == find_data->mti) &&
                        (msg_node->pid == find_data->pid) &&
                        (msg_node->ref_num == find_data->ref_num) &&
                        (msg_node->total_seg == total_seg) &&
                        (msg_node->start_seg == start_seg) &&
                        (strcmp((S8*)msg_node->number, find_data->address) == 0))
                    {
                        MMI_BOOL is_exist_same_seg = MMI_FALSE;
                        U32 next_pdu_id;

                        next_pdu_id = msg_node->start_pdu_id;

                        do
                        {
                            U8 segment = srv_sms_pdu_list[next_pdu_id].segment;
                        
                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                            if (segment == not_exist_seg)
                            {
                                is_exist_same_seg = MMI_TRUE;
                                break;
                            }

                            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
                        } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                        if (is_exist_same_seg == MMI_FALSE)
                        {
                            msg_id = i;
                            break;
                        }
                    }
                }
            }
        #else
            if(find_data->storage_type != SRV_SMS_STORAGE_SIM)
            {
                if (srv_sms_get_prefer_storage(find_data->sim_id) == SRV_SMS_STORAGE_TCARD)
                {
                    if (storage_cntx.is_tcard_ready && storage_cntx.memory_status.tcard_total > storage_cntx.memory_status.tcard_used)
                    {
                        srv_sms_tcard_msg_node_struct *msg_list;
                        msg_list = srv_sms_get_tcard_msg_list();
                        for (i = 0; i < storage_cntx.unused_tcard_msg_head_id + 1; i++)
                        {
                            tcard_msg_node = &msg_list[i];

                            /* The Msg node is used */
                            if (tcard_msg_node->status != SRV_SMS_STATUS_NONE)
                            {
                                if (
                                #ifdef __SRV_SMS_MULTI_SIM__
                                    (tcard_msg_node->sim_id == find_data->sim_id) &&
                                #endif /* __SRV_SMS_MULTI_SIM__ */
                                    (tcard_msg_node->mti == find_data->mti) &&
                                    (tcard_msg_node->pid == find_data->pid) &&
                                    (tcard_msg_node->ref_num == find_data->ref_num) &&
                                    (tcard_msg_node->total_seg == total_seg) &&
                                    (tcard_msg_node->start_seg == start_seg) &&
                                    (strcmp((S8*)tcard_msg_node->number, find_data->address) == 0))
                                {
                                    MMI_BOOL is_exist_same_seg = MMI_FALSE;
                                    U32 next_pdu_id;

                                    next_pdu_id = tcard_msg_node->start_pdu_id;

                                    do
                                    {
                                        U8 segment = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].segment;
                                    
                                        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                                        if (segment == not_exist_seg)
                                        {
                                            is_exist_same_seg = MMI_TRUE;
                                            break;
                                        }

                                        next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                                    } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                                    if (is_exist_same_seg == MMI_FALSE)
                                    {
                                        msg_id = i + SRV_SMS_MAX_MSG_NUM;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        U16 total;
                        U16 used;
                        U32 index;
                        index = srv_sms_sim_id_to_sim_index(find_data->sim_id);
                        total = storage_cntx.memory_status.me_total + storage_cntx.memory_status.sim_total[index];
                        used = storage_cntx.memory_status.me_used + storage_cntx.memory_status.sim_used[index];
                        if(total > used)
                        {
                             for (i = 0; i < end_msg_id; i++)
                            {
                                msg_node = &srv_sms_msg_list[i];

                                /* The Msg node is used */
                                if (msg_node->status != SRV_SMS_STATUS_NONE)
                                {
                                    if (
                                    #ifdef __SRV_SMS_MULTI_SIM__
                                        (msg_node->sim_id == find_data->sim_id) &&
                                    #endif /* __SRV_SMS_MULTI_SIM__ */
                                        (msg_node->mti == find_data->mti) &&
                                        (msg_node->pid == find_data->pid) &&
                                        (msg_node->ref_num == find_data->ref_num) &&
                                        (msg_node->total_seg == total_seg) &&
                                        (msg_node->start_seg == start_seg) &&
                                        (strcmp((S8*)msg_node->number, find_data->address) == 0))
                                    {
                                        MMI_BOOL is_exist_same_seg = MMI_FALSE;
                                        U32 next_pdu_id;

                                        next_pdu_id = msg_node->start_pdu_id;

                                        do
                                        {
                                            U8 segment = srv_sms_pdu_list[next_pdu_id].segment;
                                        
                                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                                            if (segment == not_exist_seg)
                                            {
                                                is_exist_same_seg = MMI_TRUE;
                                                break;
                                            }

                                            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
                                        } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                                        if (is_exist_same_seg == MMI_FALSE)
                                        {
                                            msg_id = i;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                       
                    }
                }
                else/*prefer storage not tcard*/
                {
                    U16 total;
                    U16 used;
                    U32 index;
                    index = srv_sms_sim_id_to_sim_index(find_data->sim_id);
                #ifdef __SRV_SMS_SIMBOX_SUPPORT__
                    total = storage_cntx.memory_status.me_total;
                    used = storage_cntx.memory_status.me_used;
                #else
                    total = storage_cntx.memory_status.me_total + storage_cntx.memory_status.sim_total[index];
                    used = storage_cntx.memory_status.me_used + storage_cntx.memory_status.sim_used[index];
                #endif
                    
                    if(total > used)
                    {
                        for (i = 0; i < end_msg_id; i++)
                        {
                            msg_node = &srv_sms_msg_list[i];

                            /* The Msg node is used */
                            if (msg_node->status != SRV_SMS_STATUS_NONE)
                            {
                                if (
                                #ifdef __SRV_SMS_MULTI_SIM__
                                    (msg_node->sim_id == find_data->sim_id) &&
                                #endif /* __SRV_SMS_MULTI_SIM__ */
                                    (msg_node->mti == find_data->mti) &&
                                    (msg_node->pid == find_data->pid) &&
                                    (msg_node->ref_num == find_data->ref_num) &&
                                    (msg_node->total_seg == total_seg) &&
                                    (msg_node->start_seg == start_seg) &&
                                    (strcmp((S8*)msg_node->number, find_data->address) == 0))
                                {
                                    MMI_BOOL is_exist_same_seg = MMI_FALSE;
                                    U32 next_pdu_id;

                                    next_pdu_id = msg_node->start_pdu_id;

                                    do
                                    {
                                        U8 segment = srv_sms_pdu_list[next_pdu_id].segment;
                                    
                                        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                                        if (segment == not_exist_seg)
                                        {
                                            is_exist_same_seg = MMI_TRUE;
                                            break;
                                        }

                                        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
                                    } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                                    if (is_exist_same_seg == MMI_FALSE)
                                    {
                                        msg_id = i;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (storage_cntx.is_tcard_ready && storage_cntx.memory_status.tcard_total > storage_cntx.memory_status.tcard_used)
                        {
                            srv_sms_tcard_msg_node_struct *msg_list;
                            msg_list = srv_sms_get_tcard_msg_list();
                            for (i = 0; i < storage_cntx.unused_tcard_msg_head_id + 1; i++)
                            {
                                tcard_msg_node = &msg_list[i];

                                /* The Msg node is used */
                                if (tcard_msg_node->status != SRV_SMS_STATUS_NONE)
                                {
                                    if (
                                    #ifdef __SRV_SMS_MULTI_SIM__
                                        (tcard_msg_node->sim_id == find_data->sim_id) &&
                                    #endif /* __SRV_SMS_MULTI_SIM__ */
                                        (tcard_msg_node->mti == find_data->mti) &&
                                        (tcard_msg_node->pid == find_data->pid) &&
                                        (tcard_msg_node->ref_num == find_data->ref_num) &&
                                        (tcard_msg_node->total_seg == total_seg) &&
                                        (tcard_msg_node->start_seg == start_seg) &&
                                        (strcmp((S8*)tcard_msg_node->number, find_data->address) == 0))
                                    {
                                        MMI_BOOL is_exist_same_seg = MMI_FALSE;
                                        U32 next_pdu_id;

                                        next_pdu_id = tcard_msg_node->start_pdu_id;

                                        do
                                        {
                                            U8 segment = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].segment;
                                        
                                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                                            if (segment == not_exist_seg)
                                            {
                                                is_exist_same_seg = MMI_TRUE;
                                                break;
                                            }

                                            next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                                        } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                                        if (is_exist_same_seg == MMI_FALSE)
                                        {
                                            msg_id = i + SRV_SMS_MAX_MSG_NUM;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    
                }
            }
            else
            {
                for (i = 0; i < end_msg_id; i++)
                {
                    msg_node = &srv_sms_msg_list[i];

                    /* The Msg node is used */
                    if (msg_node->status != SRV_SMS_STATUS_NONE)
                    {
                        if (
                        #ifdef __SRV_SMS_MULTI_SIM__
                            (msg_node->sim_id == find_data->sim_id) &&
                        #endif /* __SRV_SMS_MULTI_SIM__ */
                            (msg_node->mti == find_data->mti) &&
                            (msg_node->pid == find_data->pid) &&
                            (msg_node->ref_num == find_data->ref_num) &&
                            (msg_node->total_seg == total_seg) &&
                            (msg_node->start_seg == start_seg) &&
                            (strcmp((S8*)msg_node->number, find_data->address) == 0))
                        {
                            MMI_BOOL is_exist_same_seg = MMI_FALSE;
                            U32 next_pdu_id;

                            next_pdu_id = msg_node->start_pdu_id;

                            do
                            {
                                U8 segment = srv_sms_pdu_list[next_pdu_id].segment;
                            
                                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_10, next_pdu_id, segment);

                                if (segment == not_exist_seg)
                                {
                                    is_exist_same_seg = MMI_TRUE;
                                    break;
                                }

                                next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
                            } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                            if (is_exist_same_seg == MMI_FALSE)
                            {
                                msg_id = i;
                                break;
                            }
                        }
                    }
                }
            }
        #endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_MSG_11, msg_id);

    return msg_id;
}


#ifdef __SRV_SMS_DELIVERY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_search_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_search_pdu(char* number, U8 msg_ref, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_SMS_ENTRY; i++)
    {
        srv_sms_pdu_node_struct *pdu_node = &srv_sms_pdu_list[i];
    
        if ((pdu_node->status != SRV_SMS_STATUS_NONE) &&
            (pdu_node->tp_st == SRV_SMS_SRS_PENDING) &&
            (pdu_node->msg_ref == msg_ref))
        {
            U16 msg_id;

            msg_id = srv_sms_get_msg_id_by_pdu(i);

            if (msg_id != SRV_SMS_INVALID_MSG_ID)
            {
                srv_sms_msg_node_struct *msg_node;

                MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

                msg_node = &srv_sms_msg_list[msg_id];
        
                if (
                #ifdef __SRV_SMS_MULTI_SIM__
                    (msg_node->sim_id == sim_id) &&
                #endif /* __SRV_SMS_MULTI_SIM__ */
                    (srv_sms_cmp_asc_num(number, msg_node->number)))
                {
                    pdu_id = i;
                    break;
                }
            }
        }
    }

    return pdu_id;
}
#endif /* __SRV_SMS_DELIVERY_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_msg_hidden
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_msg_hidden(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id < SRV_SMS_MAX_MSG_NUM)
    {
        if (srv_sms_msg_list[msg_id].storage_type & SRV_SMS_HIDDEN_FLAG)
        {
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        srv_sms_tcard_msg_node_struct *msg_list;
        msg_list = srv_sms_get_tcard_msg_list();
        if (msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].storage_type & SRV_SMS_HIDDEN_FLAG)
        {
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }

#else
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);
    if (srv_sms_msg_list[msg_id].storage_type & SRV_SMS_HIDDEN_FLAG)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

#endif
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_MSG_HIDDEN, msg_id, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_hide_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_hide_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_HIDE_MSG_NODE, msg_id);
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);
    srv_sms_msg_list[msg_id].storage_type |= SRV_SMS_HIDDEN_FLAG;

   
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_hide_tcard_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_hide_tcard_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_msg_node_struct *msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_HIDE_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);

    msg_list = srv_sms_get_tcard_msg_list();

    msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].storage_type |= SRV_SMS_HIDDEN_FLAG;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_unhide_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_unhide_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNHIDE_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

    srv_sms_msg_list[msg_id].storage_type &= (~SRV_SMS_HIDDEN_FLAG);
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_unhide_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_unhide_tcard_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_msg_node_struct *msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UNHIDE_MSG_NODE, msg_id);

    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);

    msg_list = srv_sms_get_tcard_msg_list();
    msg_id -= SRV_SMS_MAX_MSG_NUM;
    msg_list[msg_id].storage_type &= (~SRV_SMS_HIDDEN_FLAG);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_msg_exist_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_msg_exist_ext(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(storage_cntx.is_tsms_ready)
    {
        if (msg_id < SRV_SMS_MAX_SMS_ENTRY)
        {
    if ((msg_id < SRV_SMS_MAX_SMS_ENTRY) && 
        (srv_sms_msg_list[msg_id].status != SRV_SMS_STATUS_NONE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
        }
        else
        {
            srv_sms_tcard_msg_node_struct *msg_list;
            msg_list = srv_sms_get_tcard_msg_list();
            if((msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY) && 
                (msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].status != SRV_SMS_STATUS_NONE))
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }
        }
    }
    else
    {
    if ((msg_id < SRV_SMS_MAX_SMS_ENTRY) && 
        (srv_sms_msg_list[msg_id].status != SRV_SMS_STATUS_NONE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
    }
    
#else
    if ((msg_id < SRV_SMS_MAX_SMS_ENTRY) && 
        (srv_sms_msg_list[msg_id].status != SRV_SMS_STATUS_NONE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
#endif

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_msg_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_msg_valid(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1> it is used;
     * 2> it is not hidden. */
    if ((srv_sms_msg_list[msg_id].status == SRV_SMS_STATUS_NONE) ||
        (srv_sms_msg_list[msg_id].storage_type & SRV_SMS_HIDDEN_FLAG))
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_concat_pdu_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_concat_pdu_list(U16 msg_id, U16 pdu_id_list[], U8 total_pdu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 prev_pdu_id = msg_id;
    U16 next_pdu_id = SRV_SMS_INVALID_PDU_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(total_pdu > 0);
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_LIST, msg_id, total_pdu);

    for (i = 0; i < (S32)total_pdu; i++)
    {
        srv_sms_pdu_list[pdu_id_list[i]].prev_pdu_id = prev_pdu_id;
        prev_pdu_id = pdu_id_list[i];
    }

    for (i = (S32)(total_pdu - 1); i >= 0; i--)
    {
        srv_sms_pdu_list[pdu_id_list[i]].next_pdu_id = next_pdu_id;
        next_pdu_id = pdu_id_list[i];
    }

    srv_sms_pdu_list[pdu_id_list[0]].type |= SRV_SMS_NODE_FIRST;

    srv_sms_msg_list[msg_id].start_pdu_id = pdu_id_list[0];
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_concat_tcard_pdu_to_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_concat_tcard_pdu_to_msg(U16 msg_id, U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_seg;
    U32 curr_pdu_id;
    U32 prev_pdu_id = SRV_SMS_INVALID_PDU_ID;
    srv_sms_tcard_msg_node_struct *msg_list;
    U16 temp_msg_id;
    U16 temp_pdu_id;
    srv_tcard_op_struct read_cntx;
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
    MMI_ASSERT(pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);    
    msg_list = srv_sms_get_tcard_msg_list();
    temp_msg_id = msg_id - SRV_SMS_MAX_MSG_NUM;
    temp_pdu_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
    curr_seg = srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM].segment;
    curr_pdu_id = msg_list[temp_msg_id].start_pdu_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_TO_MSG, msg_id, pdu_id, curr_pdu_id);

    while (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].segment < curr_seg)//check it for number range
        {
            prev_pdu_id = curr_pdu_id;
            curr_pdu_id = srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_TO_MSG_1, curr_pdu_id, prev_pdu_id);
        }
        else
        {
            break;
        }
    }

    if (prev_pdu_id == SRV_SMS_INVALID_PDU_ID)
    {
        msg_list[temp_msg_id].start_pdu_id = pdu_id;
        srv_sms_tcard_pdu_list[temp_pdu_id].prev_pdu_id = msg_id;

        srv_sms_tcard_pdu_list[temp_pdu_id].type |= SRV_SMS_NODE_FIRST;

        if (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].type &= (~SRV_SMS_NODE_FIRST);//check number range
        }
    }
    else
    {
        srv_sms_tcard_pdu_list[prev_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id = pdu_id;
        srv_sms_tcard_pdu_list[temp_pdu_id].prev_pdu_id = prev_pdu_id;
    }

    srv_sms_tcard_pdu_list[temp_pdu_id].next_pdu_id = curr_pdu_id;

    if (curr_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        srv_sms_tcard_pdu_list[curr_pdu_id - SRV_SMS_MAX_MSG_NUM].prev_pdu_id = pdu_id;//check number range
    }

    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
    read_cntx.start_record_id = temp_msg_id;
    result = srv_tcard_sync_write_record(&read_cntx, (char*)&msg_list[temp_msg_id]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_search_concatenated_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_tcard_search_concatenated_sms(srv_sms_tcard_msg_node_struct *msg_node, U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    srv_sms_tcard_msg_node_struct *msg_list;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS, msg_node->total_seg, curr_seg);
#ifdef __SRV_SMS_MULTI_SIM__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_1, msg_node->sim_id);
#endif /* __SRV_SMS_MULTI_SIM__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_2, msg_node->storage_type);
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_3, msg_node->mti, msg_node->status, msg_node->pid, msg_node->ref_num);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_4, (S8*)msg_node->number);
    msg_list = srv_sms_get_tcard_msg_list();
    if (msg_node->total_seg > 1)
    {
        U32 i;
        U16 end_msg_id = storage_cntx.used_tcard_msg_tail_id + 1;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_5, end_msg_id);

        for (i = 0; i < end_msg_id; i++)
        {
            srv_sms_tcard_msg_node_struct *curr_msg_node = &msg_list[i];

            /* The Msg node is used */
            if (curr_msg_node->status != SRV_SMS_STATUS_NONE)
            {
                /* 1. If the MTI is DELIVER, the SMS may be UNREAD or READ status;
                 *    It will consider as same Concatenated SMS even if its status is not same. 
                 * 2. If the MTI is SUBMIT, it may be DRAFT, UNSENT, SENT;
                 *    If the status is not same, it is not a Concatenated SMS. */
                if ((memcmp(MSG_NODE_CMP_START(curr_msg_node), 
                        MSG_NODE_CMP_START(msg_node), MSG_NODE_CMP_SIZE) == 0) &&
                    ((curr_msg_node->mti != SRV_SMS_MTI_SUBMIT) || 
                     (curr_msg_node->status & msg_node->status)) &&
                    (strcmp((S8*)curr_msg_node->number, (S8*)msg_node->number) == 0))
                {
                    MMI_BOOL is_exist_same_seg = MMI_FALSE;
                    U32 next_pdu_id;

                    next_pdu_id = curr_msg_node->start_pdu_id;

                    do
                    {
                        U8 segment = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].segment;

                        if (segment == curr_seg)
                        {
                            is_exist_same_seg = MMI_TRUE;
                            break;
                        }

                        next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
                    } while(next_pdu_id != SRV_SMS_INVALID_PDU_ID);

                    if (is_exist_same_seg == MMI_FALSE)
                    {
                        msg_id = i;
                        break;
                    }
                }
            }
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_CONCATENATED_SMS_13, msg_id);

    return msg_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_concat_pdu_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_concat_tcard_pdu_list(U16 msg_id, U16 pdu_id_list[], U8 total_pdu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 prev_pdu_id = msg_id;
    U16 next_pdu_id = SRV_SMS_INVALID_PDU_ID;
    srv_sms_tcard_msg_node_struct *msg_list;
#if 0
/* under construction !*/
#endif
    S32 result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(total_pdu > 0);
    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONCAT_PDU_LIST, msg_id, total_pdu);
    msg_list = srv_sms_get_tcard_msg_list();
    for (i = 0; i < (S32)total_pdu; i++)
    {
        srv_sms_tcard_pdu_list[pdu_id_list[i] - SRV_SMS_MAX_MSG_NUM].prev_pdu_id = prev_pdu_id;
        prev_pdu_id = pdu_id_list[i];
    }

    for (i = (S32)(total_pdu - 1); i >= 0; i--)
    {
        srv_sms_tcard_pdu_list[pdu_id_list[i] - SRV_SMS_MAX_MSG_NUM].next_pdu_id = next_pdu_id;
        next_pdu_id = pdu_id_list[i];
    }

    srv_sms_tcard_pdu_list[pdu_id_list[0]  - SRV_SMS_MAX_MSG_NUM].type |= SRV_SMS_NODE_FIRST;

    msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id = pdu_id_list[0];
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_msg_node_struct* srv_sms_get_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_NODE, msg_id);
    return &srv_sms_msg_list[msg_id];
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_tcard_msg_node_struct* srv_sms_get_tcard_msg_node(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_msg_node_struct *msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_NODE, msg_id);

    msg_list = srv_sms_get_tcard_msg_list();
    return &msg_list[msg_id];
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_get_msg_info(srv_sms_msg_info_struct* msg_info, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_node_struct *msg_node = NULL;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_msg_node_struct *tcard_msg_node = NULL;
#endif
#ifdef __SRV_SMS_MULTI_ADDR__
    srv_sms_status_enum old_status;
#endif /* __SRV_SMS_MULTI_ADDR__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_INFO, msg_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    MMI_ASSERT(msg_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
    if(msg_id < SRV_SMS_MAX_SMS_ENTRY)
    {
        msg_node = &srv_sms_msg_list[msg_id];
    }
    else
    {
        srv_sms_tcard_msg_node_struct *msg_list;       
        msg_list = srv_sms_get_tcard_msg_list();
        tcard_msg_node = &msg_list[msg_id - SRV_SMS_MAX_MSG_NUM]; 
    }
#else
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);
    msg_node = &srv_sms_msg_list[msg_id];
#endif


#ifdef __SRV_SMS_MULTI_ADDR__
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        old_status = (srv_sms_status_enum)(tcard_msg_node->status);
        tcard_msg_node->status = srv_sms_get_tcard_msg_node_status(tcard_msg_node);
    }
    else
    {
        old_status = (srv_sms_status_enum)(msg_node->status);
        msg_node->status = srv_sms_get_msg_node_status(msg_node);
    }
#else /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
    old_status = (srv_sms_status_enum)(msg_node->status);
    msg_node->status = srv_sms_get_msg_node_status(msg_node);
#endif /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        srv_sms_msg_node_struct temp_msg_node;
        srv_sms_tcard_msg_node_to_msg_info(msg_info, tcard_msg_node);
        temp_msg_node.start_pdu_id = tcard_msg_node->start_pdu_id;
    #ifdef __SRV_SMS_DELIVERY_STATUS__ 
        msg_info->sr_status = srv_sms_get_sr_status(msg_node); 
    #else /* __SRV_SMS_DELIVERY_STATUS__ */
        msg_info->sr_status = SRV_SMS_SRS_INVALID;
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */
    #ifdef __SRV_SMS_MULTI_ADDR__
        tcard_msg_node->status = old_status;
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    }
    else
    {
    srv_sms_msg_node_to_msg_info(msg_info, msg_node);

#ifdef __SRV_SMS_DELIVERY_STATUS__ 
    msg_info->sr_status = srv_sms_get_sr_status(msg_node);
#else /* __SRV_SMS_DELIVERY_STATUS__ */
    msg_info->sr_status = SRV_SMS_SRS_INVALID;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    msg_node->status = old_status;
#endif /* __SRV_SMS_MULTI_ADDR__ */
}

#else /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/

    srv_sms_msg_node_to_msg_info(msg_info, msg_node);
#ifdef __SRV_SMS_DELIVERY_STATUS__ 
    msg_info->sr_status = srv_sms_get_sr_status(msg_node); 
#else /* __SRV_SMS_DELIVERY_STATUS__ */
    msg_info->sr_status = SRV_SMS_SRS_INVALID;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    msg_node->status = old_status;
#endif /* __SRV_SMS_MULTI_ADDR__ */

#endif /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/


}


#ifdef __SRV_SMS_MULTI_ADDR__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_node_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_status_enum srv_sms_get_msg_node_status(srv_sms_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status = (srv_sms_status_enum)msg_node->status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (msg_node->ext_addr_num > 0)
    {
        U32 i = 0;
        srv_sms_status_enum temp_status = (srv_sms_status_enum)(status & (~SRV_SMS_STATUS_UNSUPPORTED));
        srv_sms_addr_node_struct *addr_node;
        U16 next_addr_id = msg_node->start_addr_id;

        MMI_ASSERT((temp_status == SRV_SMS_STATUS_UNSENT) || 
                   (temp_status == SRV_SMS_STATUS_SENT) ||
                   (temp_status == SRV_SMS_STATUS_DRAFT));

        if (temp_status == SRV_SMS_STATUS_SENT)
        {
            for (i = 0; i < msg_node->ext_addr_num; i++)
            {
                MMI_ASSERT(next_addr_id < SRV_SMS_MAX_ADDR_ENTRY);
                addr_node = &srv_sms_addr_list[next_addr_id];

                MMI_ASSERT(addr_node->status != SRV_SMS_STATUS_DRAFT);

                if (addr_node->status == SRV_SMS_STATUS_UNSENT)
                {
                    temp_status = SRV_SMS_STATUS_UNSENT;
                    break;
                }
                next_addr_id = addr_node->next_addr_id;
            }

            status = (srv_sms_status_enum)(temp_status | (status & SRV_SMS_STATUS_UNSUPPORTED));
        }
    }         

    return status;
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_node_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_status_enum srv_sms_get_tcard_msg_node_status(srv_sms_tcard_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status = (srv_sms_status_enum)msg_node->status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/       
    if (msg_node->ext_addr_num > 0)
    {
        U32 i = 0;
        srv_sms_status_enum temp_status = (srv_sms_status_enum)(status & (~SRV_SMS_STATUS_UNSUPPORTED));
        srv_sms_tcard_addr_node_struct *addr_node;
        U16 next_addr_id = msg_node->start_addr_id;

        MMI_ASSERT((temp_status == SRV_SMS_STATUS_UNSENT) || 
                   (temp_status == SRV_SMS_STATUS_SENT) ||
                   (temp_status == SRV_SMS_STATUS_DRAFT));

        if (temp_status == SRV_SMS_STATUS_SENT)
        {
            for (i = 0; i < msg_node->ext_addr_num; i++)
            {
                MMI_ASSERT(next_addr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);
                addr_node = &srv_sms_tcard_addr_list[next_addr_id - SRV_SMS_MAX_ADDR_ENTRY];

                MMI_ASSERT(addr_node->status != SRV_SMS_STATUS_DRAFT);

                if (addr_node->status == SRV_SMS_STATUS_UNSENT)
                {
                    temp_status = SRV_SMS_STATUS_UNSENT;
                    break;
                }
                next_addr_id = addr_node->next_addr_id;
            }

            status = (srv_sms_status_enum)(temp_status | (status & SRV_SMS_STATUS_UNSUPPORTED));
        }
    }         

    return status;
}
#endif
#endif /* __SRV_SMS_MULTI_ADDR__ */


#ifdef __SRV_SMS_DELIVERY_STATUS__ 
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sr_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_sr_status_enum srv_sms_get_sr_status(srv_sms_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_status_enum sr_status = SRV_SMS_SRS_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_node->status & SRV_SMS_STATUS_SENT)
    {
        U32 next_pdu_id = msg_node->start_pdu_id;
        U32 none_count = 0;
        U32 pending_count = 0;
        U32 failed_count = 0;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        U32 tmp_next_pdu_id;
        tmp_next_pdu_id = next_pdu_id;
        if(next_pdu_id >= SRV_SMS_MAX_SMS_ENTRY)
        {
            next_pdu_id -= SRV_SMS_MAX_MSG_NUM;
        }
    #endif
        while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            U8 tp_st;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            MMI_ASSERT(next_pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
            if(tmp_next_pdu_id >= SRV_SMS_MAX_SMS_ENTRY)
            {   
                tp_st = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].tp_st;
                next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
            }
            else
            {
                tp_st = srv_sms_pdu_list[next_pdu_id].tp_st;
                next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
            }

            tp_st = srv_sms_pdu_list[next_pdu_id].tp_st;
            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        #else
            MMI_ASSERT(next_pdu_id < SRV_SMS_MAX_SMS_ENTRY);
            tp_st = srv_sms_pdu_list[next_pdu_id].tp_st;
            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        #endif
            switch (tp_st)
            {
                case SRV_SMS_SRS_NONE:
                    none_count++;
                    break;

                case SRV_SMS_SRS_PENDING:
                    pending_count++;
                    break;

                case SRV_SMS_SRS_FAILED:
                    failed_count++;
                    break;

                case SRV_SMS_SRS_SUCC:
                    break;

                case SRV_SMS_SRS_INVALID:
                default:
                    MMI_ASSERT(0);
                    break;
            }
        }

        if (none_count > 0)
        {
            sr_status = SRV_SMS_SRS_NONE;
        }
        else if (pending_count > 0)
        {
            sr_status = SRV_SMS_SRS_PENDING;
        }
        else if (failed_count > 0)
        {
            sr_status = SRV_SMS_SRS_FAILED;
        }
        else
        {
            sr_status = SRV_SMS_SRS_SUCC;
        }
    }

    return sr_status;
}
#endif /* __SRV_SMS_DELIVERY_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_pdu_id(U16 pdu_id_array[], U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    U32 i;    
    U16 next_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_SMS_ENTRY)
    {
        srv_sms_tcard_msg_node_struct *msg_list;
        msg_list = srv_sms_get_tcard_msg_list();
        next_pdu_id = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

        for (count = 0; count < SRV_SMS_MAX_SEG; count++)
        {
            if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                pdu_id_array[count] = next_pdu_id ;
                next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    for (count = 0; count < SRV_SMS_MAX_SEG; count++)
    {
        if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            pdu_id_array[count] = next_pdu_id;
            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        }
        else
        {
            break;
        }
    }
    }
#else
    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    for (count = 0; count < SRV_SMS_MAX_SEG; count++)
    {
        if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            pdu_id_array[count] = next_pdu_id;
            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        }
        else
        {
            break;
        }
    }
#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_PDU_ID, msg_id, count);

    for (i = count; i < SRV_SMS_MAX_SEG; i++)
    {
        pdu_id_array[i] = SRV_SMS_INVALID_PDU_ID;
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_pdu_id_ext(U16 pdu_id_array[], U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_seg = 0;
    U32 i;    
    U32 next_pdu_id;
    U8 start_seg;
    U8 curr_seg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        pdu_id_array[i] = SRV_SMS_INVALID_PDU_ID;
    }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        srv_sms_tcard_msg_node_struct *msg_list;

        msg_list = srv_sms_get_tcard_msg_list();
        msg_id = msg_id - SRV_SMS_MAX_MSG_NUM;
        next_pdu_id = msg_list[msg_id].start_pdu_id;
        if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            start_seg = msg_list[msg_id].start_seg;

            total_seg = msg_list[msg_id].total_seg - start_seg + 1;

            if (total_seg > SRV_SMS_MAX_SEG)
            {
                total_seg = SRV_SMS_MAX_SEG;
            }

            do 
            {
                curr_seg = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].segment - 1;

                pdu_id_array[curr_seg] = next_pdu_id;

                next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
            } while (next_pdu_id != SRV_SMS_INVALID_PDU_ID);
        }
    }
    else
    {
    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
        if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            start_seg = srv_sms_msg_list[msg_id].start_seg;

            total_seg = srv_sms_msg_list[msg_id].total_seg - start_seg + 1;

            if (total_seg > SRV_SMS_MAX_SEG)
            {
                total_seg = SRV_SMS_MAX_SEG;
            }

            do 
            {
                curr_seg = srv_sms_pdu_list[next_pdu_id].segment - 1;

                pdu_id_array[curr_seg] = next_pdu_id;

                next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
            } while (next_pdu_id != SRV_SMS_INVALID_PDU_ID);
        }
    }

#else
    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;
    if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        start_seg = srv_sms_msg_list[msg_id].start_seg;

        total_seg = srv_sms_msg_list[msg_id].total_seg - start_seg + 1;

        if (total_seg > SRV_SMS_MAX_SEG)
        {
            total_seg = SRV_SMS_MAX_SEG;
        }

        do 
        {
            curr_seg = srv_sms_pdu_list[next_pdu_id].segment - 1;

            pdu_id_array[curr_seg] = next_pdu_id;

            next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        } while (next_pdu_id != SRV_SMS_INVALID_PDU_ID);
    }
#endif
    return total_seg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_id_by_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_msg_id_by_pdu(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_pdu_id = SRV_SMS_INVALID_PDU_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

    if (srv_sms_pdu_list[pdu_id].status != SRV_SMS_STATUS_NONE)
    {
        U8 type = srv_sms_pdu_list[pdu_id].type;

        prev_pdu_id = srv_sms_pdu_list[pdu_id].prev_pdu_id;

        while ((!(type & SRV_SMS_NODE_FIRST)) &&
               (prev_pdu_id != SRV_SMS_INVALID_PDU_ID))
        {
            type = srv_sms_pdu_list[prev_pdu_id].type;
            prev_pdu_id = srv_sms_pdu_list[prev_pdu_id].prev_pdu_id;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_ID_BY_PDU, pdu_id, prev_pdu_id);

    return prev_pdu_id;
}


#ifdef __SRV_SMS_DELIVERY_STATUS__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_ref
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_ref(U8 msg_ref[], U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U32 next_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        msg_ref[count++] = srv_sms_pdu_list[next_pdu_id].msg_ref;
        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;

        MMI_ASSERT(count <= SRV_SMS_MAX_SEG);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_PDU_ID_AND_SEG, msg_id, count);

    return count;
}
#endif /* __SRV_SMS_DELIVERY_STATUS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_total_seg
 * DESCRIPTION
 *  Get Message's Total Segments
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_sms_get_msg_total_seg(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_seg = 0;
    U32 next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
        total_seg++;

        MMI_ASSERT(total_seg <= SRV_SMS_MAX_SEG);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_TOTAL_SEG, msg_id, total_seg);

    return total_seg;
}


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_tcard_msg_total_seg
 * DESCRIPTION
 *  Get Message's Total Segments
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_sms_get_tcard_msg_total_seg(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_seg = 0;
    srv_sms_tcard_msg_node_struct *msg_list;
        
        
    U32 next_pdu_id ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = srv_sms_get_tcard_msg_list();
    next_pdu_id = msg_list[ msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;
    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
        total_seg++;

        MMI_ASSERT(total_seg <= SRV_SMS_MAX_SEG);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_TOTAL_SEG, msg_id, total_seg);

    return total_seg;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pdu_num_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_pdu_num_by_storage(U16 msg_id, srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U32 next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_get_pdu_storage_type(next_pdu_id) == storage_type)
        {
            count++;
        }

        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_PDU_NUM_BY_STORAGE, msg_id, storage_type, count);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_pdu_id_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_get_msg_pdu_id_by_storage(
        U16 pdu_id_array[],
        U16 msg_id,
        srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U32 next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_get_pdu_storage_type(next_pdu_id) == storage_type)
        {
            pdu_id_array[count] = next_pdu_id;
            count++;
        }

        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_PDU_ID_BY_STORAGE, msg_id, storage_type, count);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_storage_type_by_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_storage_enum srv_sms_get_storage_type_by_pdu(U16 pdu_id_list[], U8 total_pdu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_sms_storage_enum storage_type = SRV_SMS_STORAGE_ME;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < total_pdu; i++)
    {
        /* If a part of the concatenated message is stored in SIM Card,
         * the rest stored in ME, we will consider its storage tpye as SIM. */
        if (srv_sms_get_pdu_storage_type(pdu_id_list[i]) == SRV_SMS_STORAGE_SIM)
        {
            storage_type = SRV_SMS_STORAGE_SIM;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_STORAGE_TYPE_BY_PDU, storage_type, total_pdu);

    return storage_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_msg_op_conflict
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_check_msg_op_conflict(U16 msg_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    srv_sms_node_flag_enum not_allow_flag = SRV_SMS_NODE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_MSG_OP_CONFLICT, msg_id, action);

    switch (action)
    {
        /* Read PDU Case, COPY is contained two operaton : READ then SAVE */
        case SRV_SMS_ACTION_READ:
        case SRV_SMS_ACTION_COPY:
            not_allow_flag = (srv_sms_node_flag_enum)(SRV_SMS_NODE_UPDATING | SRV_SMS_NODE_DELETING | SRV_SMS_NODE_LOCKING);
            break;

        /* For Message, if this message is being modified/Deleted, we don't allow
         * to do any operation with it even if it is allowed in the PDU level;
         * <1> Update Case need to delete the original PDUs;
         * <2> Move Case need to delete the source storage PDUs;
         * <3> Change Status need to Update the PDUs. */
        case SRV_SMS_ACTION_UPDATE:
        case SRV_SMS_ACTION_DELETE:
        case SRV_SMS_ACTION_MOVE:
        case SRV_SMS_ACTION_CHANGE_STATUS:
            not_allow_flag = (srv_sms_node_flag_enum)(SRV_SMS_NODE_READING | SRV_SMS_NODE_UPDATING | 
                              SRV_SMS_NODE_DELETING | SRV_SMS_NODE_LOCKING);
            break;

        /* Add New PDU Case */
        case SRV_SMS_ACTION_SAVE:
        default:
            MMI_ASSERT(0);
            break;
    }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM)
    {
        if (srv_sms_check_tcard_msg_flag(msg_id, not_allow_flag) == MMI_TRUE)
        {
            result = MMI_TRUE;
        }
    }
    else
    {
        if (srv_sms_check_msg_flag(msg_id, not_allow_flag) == MMI_TRUE)
        {
            result = MMI_TRUE;
        }
    }
#else
    if (srv_sms_check_msg_flag(msg_id, not_allow_flag) == MMI_TRUE)
    {
        result = MMI_TRUE;
    }
#endif
    

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_MSG_OP_CONFLICT_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_msg_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_check_msg_flag(U16 msg_id, srv_sms_node_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U32 next_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_MSG_FLAG, msg_id, flag);

    next_pdu_id = srv_sms_msg_list[msg_id].start_pdu_id;

    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_pdu_list[next_pdu_id].type & flag)
        {
            result = MMI_TRUE;
            break;
        }

        next_pdu_id = srv_sms_pdu_list[next_pdu_id].next_pdu_id;
    }

    return result;
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_tcard_msg_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_check_tcard_msg_flag(U16 msg_id, srv_sms_node_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U32 next_pdu_id;
    srv_sms_tcard_msg_node_struct *msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_MSG_FLAG, msg_id, flag);

    msg_list = srv_sms_get_tcard_msg_list();
    next_pdu_id = msg_list[msg_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id;

    while (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
    {
        if (srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].type & flag)
        {
            result = MMI_TRUE;
            break;
        }

        next_pdu_id = srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id;
    }

    return result;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_id_to_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_pdu_id_to_record_index(
        U16 pdu_id,
        srv_sms_storage_enum *storage_type,
        srv_sms_sim_enum *sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PDU_ID_TO_RECORD_INDEX, pdu_id);

    if (pdu_id < memory_status->me_total)
    {
        record_index = pdu_id;
        *storage_type = SRV_SMS_STORAGE_ME;
        *sim_id = SRV_SMS_SIM_1;
    }
    else
    {
        U32 i;
        U16 start_pdu_id = 0;

        for (i = 0; i < SMS_SIM_NUM; i++)
        {
            U16 end_pdu_id;

            start_pdu_id = memory_status->sim_start[i];
            end_pdu_id = start_pdu_id + memory_status->sim_total[i];
        
            if ((pdu_id >= start_pdu_id) && (pdu_id < end_pdu_id))
            {
                break;
            }
        }

        if (i < SMS_SIM_NUM)
        {
            record_index = pdu_id - start_pdu_id;
            *storage_type = SRV_SMS_STORAGE_SIM;
            *sim_id = srv_sms_sim_index_to_sim_id(i);
        }
        else
        {
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY)
            {
                record_index = pdu_id - SRV_SMS_MAX_MSG_NUM;
                *storage_type = SRV_SMS_STORAGE_TCARD;
                *sim_id = SRV_SMS_SIM_1;
            }
            else
            {
                record_index = SRV_SMS_INVALID_INDEX;
                *storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
                *sim_id = SRV_SMS_SIM_1;
            }
        #else
            record_index = SRV_SMS_INVALID_INDEX;
            *storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
            *sim_id = SRV_SMS_SIM_1;
        #endif
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PDU_ID_TO_RECORD_INDEX_1, record_index, *storage_type, *sim_id);

    return record_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_record_index_to_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_record_index_to_pdu_id(
        U16 record_index,
        srv_sms_storage_enum storage_type,
        srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_RECORD_INDEX_TO_PDU_ID, record_index, storage_type, sim_id);

    if (storage_type == SRV_SMS_STORAGE_ME)
    {
        if (record_index < memory_status->me_total)
        {
            pdu_id = record_index;
        }
    }
    else
    {
        U32 index;

        index = srv_sms_sim_id_to_sim_index(sim_id);

        if (record_index < memory_status->sim_total[index])
        {
            pdu_id = memory_status->sim_start[index] + record_index;
        }
    }

    return pdu_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_me_record_index_to_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_me_record_index_to_pdu_id(U16 record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_record_index_to_pdu_id(record_index, SRV_SMS_STORAGE_ME, SRV_SMS_SIM_1);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_id_to_me_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_pdu_id_to_me_record_index(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_pdu_id_to_record_index(pdu_id, &storage_type, &sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_record_index_to_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_sim_record_index_to_pdu_id(U16 record_index, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_record_index_to_pdu_id(record_index, SRV_SMS_STORAGE_SIM, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_id_to_sim_record_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_pdu_id_to_sim_record_index(U16 pdu_id, srv_sms_sim_enum* sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_storage_enum storage_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_pdu_id_to_record_index(pdu_id, &storage_type, sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_id_to_sim_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_pdu_id_to_sim_index(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PDU_ID_TO_SIM_INDEX, pdu_id);

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        U16 start_pdu_id = memory_status->sim_start[i];
        U16 end_pdu_id = start_pdu_id + memory_status->sim_total[i];

        if ((pdu_id >= start_pdu_id) && (pdu_id < end_pdu_id))
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_add_pdu_node(U16 pdu_id, srv_sms_pdu_node_struct* pdu_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_PDU_NODE, pdu_id, pdu_node->segment, pdu_node->status);

    MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);
    MMI_ASSERT(pdu_node->status != SRV_SMS_STATUS_NONE);

    memcpy(&srv_sms_pdu_list[pdu_id], pdu_node, sizeof(srv_sms_pdu_node_struct));

    /* Update Memory Status, increment used number */
    srv_sms_increment_used_memory(pdu_id);
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_tcard_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_add_tcard_pdu_node(U16 pdu_id, srv_sms_tcard_pdu_node_struct* pdu_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_PDU_NODE, pdu_id, pdu_node->segment, pdu_node->status);

    MMI_ASSERT(pdu_id >= SRV_SMS_MAX_SMS_ENTRY && pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
    MMI_ASSERT(pdu_node->status != SRV_SMS_STATUS_NONE);
    pdu_id -= SRV_SMS_MAX_MSG_NUM;
    memcpy(&srv_sms_tcard_pdu_list[pdu_id], pdu_node, sizeof(srv_sms_tcard_pdu_node_struct));
    pdu_id += SRV_SMS_MAX_MSG_NUM;
    /* Update Memory Status, increment used number */
    srv_sms_increment_used_memory(pdu_id);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_delete_pdu_node(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_pdu_node_struct *del_node = &srv_sms_pdu_list[pdu_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU_NODE, pdu_id);

    MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

    if (del_node->type & SRV_SMS_NODE_USED)
    {
        if (del_node->status != SRV_SMS_STATUS_NONE)
        {
            U16 prev_pdu_id = del_node->prev_pdu_id;
            U16 next_pdu_id = del_node->next_pdu_id;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU_NODE_1, prev_pdu_id, next_pdu_id, del_node->type);

            if (del_node->type & SRV_SMS_NODE_FIRST)
            {
                srv_sms_msg_list[prev_pdu_id].start_pdu_id = next_pdu_id;

                if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    srv_sms_pdu_list[next_pdu_id].type |= SRV_SMS_NODE_FIRST;
                }
            }
            else
            {
                if (prev_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    srv_sms_pdu_list[prev_pdu_id].next_pdu_id = next_pdu_id;
                }              
            }

            if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                srv_sms_pdu_list[next_pdu_id].prev_pdu_id = prev_pdu_id;
            }
        }

        del_node->type = SRV_SMS_NODE_NONE;
        del_node->status = SRV_SMS_STATUS_NONE;
        del_node->prev_pdu_id = SRV_SMS_INVALID_PDU_ID;
        del_node->next_pdu_id = SRV_SMS_INVALID_PDU_ID;

        /* Update Memory Status, decrement used number */
        srv_sms_decrement_used_memory(pdu_id);

        srv_sms_pdu_trigger_hdlr(pdu_id);
    }
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_tcard_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_delete_tcard_pdu_node(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_pdu_node_struct *del_node = &srv_sms_tcard_pdu_list[pdu_id];
    srv_sms_tcard_msg_node_struct *msg_list;
    srv_tcard_op_struct read_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU_NODE, pdu_id);

    MMI_ASSERT(pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY);
    
        
    msg_list = srv_sms_get_tcard_msg_list();

    if (del_node->type & SRV_SMS_NODE_USED)
    {
        if (del_node->status != SRV_SMS_STATUS_NONE)
        {
            U16 prev_pdu_id = del_node->prev_pdu_id;
            U16 next_pdu_id = del_node->next_pdu_id;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU_NODE_1, prev_pdu_id, next_pdu_id, del_node->type);

            if (del_node->type & SRV_SMS_NODE_FIRST)
            {
                msg_list[prev_pdu_id - SRV_SMS_MAX_MSG_NUM].start_pdu_id = next_pdu_id;

                if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].type |= SRV_SMS_NODE_FIRST;
                }
            }
            else
            {
                if (prev_pdu_id != SRV_SMS_INVALID_PDU_ID)
                {
                    srv_sms_tcard_pdu_list[prev_pdu_id - SRV_SMS_MAX_MSG_NUM].next_pdu_id = next_pdu_id;
                }
                
            }

            if (next_pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                srv_sms_tcard_pdu_list[next_pdu_id - SRV_SMS_MAX_MSG_NUM].prev_pdu_id = prev_pdu_id;
            }
        }

        del_node->type = SRV_SMS_NODE_NONE;
        del_node->status = SRV_SMS_STATUS_NONE;
        del_node->prev_pdu_id = SRV_SMS_INVALID_PDU_ID;
        del_node->next_pdu_id = SRV_SMS_INVALID_PDU_ID;

        read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
        read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
        read_cntx.start_record_id = pdu_id;
        srv_tcard_sync_write_record(&read_cntx,(CHAR *)del_node);
        /* Update Memory Status, decrement used number */
        pdu_id += SRV_SMS_MAX_MSG_NUM;
        srv_sms_decrement_used_memory(pdu_id);

        srv_sms_pdu_trigger_hdlr(pdu_id);
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_pdu_node_struct* srv_sms_get_pdu_node(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

    return &srv_sms_pdu_list[pdu_id];
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pdu_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_tcard_pdu_node_struct* srv_sms_get_tcard_pdu_node(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(pdu_id < SRV_SMS_MAX_SMS_ENTRY);

    return &srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM];
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_pdu_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_set_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_PDU_FLAG, pdu_id, flag);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
    {
        pdu_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
        srv_sms_tcard_pdu_list[pdu_id].type |= flag;
        if (flag & SRV_SMS_NODE_READING)
        {
            srv_sms_tcard_pdu_list[pdu_id].read_count++;

            MMI_ASSERT(srv_sms_tcard_pdu_list[pdu_id].read_count > 0);
        }
    }
    else
    {
    srv_sms_pdu_list[pdu_id].type |= flag;
        if (flag & SRV_SMS_NODE_READING)
        {
            srv_sms_pdu_list[pdu_id].read_count++;

            MMI_ASSERT(srv_sms_pdu_list[pdu_id].read_count > 0);
        }
    }

#else
    srv_sms_pdu_list[pdu_id].type |= flag;
    if (flag & SRV_SMS_NODE_READING)
    {
        srv_sms_pdu_list[pdu_id].read_count++;

        MMI_ASSERT(srv_sms_pdu_list[pdu_id].read_count > 0);
    }

#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_pdu_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_clear_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_node_flag_enum tmp_flag = flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_PDU_FLAG, pdu_id, flag);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
    {
        pdu_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
        if ((flag & SRV_SMS_NODE_READING) &&
            (srv_sms_tcard_pdu_list[pdu_id].type & SRV_SMS_NODE_READING))
        {
            MMI_ASSERT(srv_sms_tcard_pdu_list[pdu_id].read_count > 0);

            srv_sms_tcard_pdu_list[pdu_id].read_count--;

            if (srv_sms_tcard_pdu_list[pdu_id].read_count > 0)
            {
                tmp_flag &= (~SRV_SMS_NODE_READING);
            }
        }
        srv_sms_tcard_pdu_list[pdu_id].type &= (~tmp_flag);
    }
    else
    {
    if ((flag & SRV_SMS_NODE_READING) &&
        (srv_sms_pdu_list[pdu_id].type & SRV_SMS_NODE_READING))
    {
        MMI_ASSERT(srv_sms_pdu_list[pdu_id].read_count > 0);

        srv_sms_pdu_list[pdu_id].read_count--;

        if (srv_sms_pdu_list[pdu_id].read_count > 0)
        {
            tmp_flag &= (~SRV_SMS_NODE_READING);
        }
    }
        srv_sms_pdu_list[pdu_id].type &= (~tmp_flag);
    }
#else
    if ((flag & SRV_SMS_NODE_READING) &&
        (srv_sms_pdu_list[pdu_id].type & SRV_SMS_NODE_READING))
    {
        MMI_ASSERT(srv_sms_pdu_list[pdu_id].read_count > 0);

        srv_sms_pdu_list[pdu_id].read_count--;

        if (srv_sms_pdu_list[pdu_id].read_count > 0)
        {
            tmp_flag &= (~SRV_SMS_NODE_READING);
        }
    }
    srv_sms_pdu_list[pdu_id].type &= (~tmp_flag);
#endif
    

    srv_sms_pdu_trigger_hdlr(pdu_id);   
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_pdu_trigger
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_set_pdu_trigger(
        U16 pdu_id,
        srv_sms_action_enum action,
        SrvSmsTriggerFunc trigger_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_pdu_trigger_struct *new_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_node = OslMalloc(sizeof(srv_sms_pdu_trigger_struct));
    new_node->pdu_id = pdu_id;
    new_node->action = action;
    new_node->trigger_func = trigger_func;
    new_node->user_data = user_data;
    new_node->next = NULL;

    if (trigger_head)
    {
        srv_sms_pdu_trigger_struct *last_node = trigger_head;

        while (last_node->next)
        {
            last_node = last_node->next;
        }

        last_node->next = new_node;
    }
    else
    {
        trigger_head = new_node;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_trigger_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_pdu_trigger_hdlr(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_pdu_trigger_struct *prev_node = NULL;
    srv_sms_pdu_trigger_struct *curr_node = trigger_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr_node)
    {
        if ((curr_node->pdu_id == pdu_id) && 
            (!srv_sms_check_pdu_op_conflict(pdu_id, curr_node->action)))
        {
            srv_sms_pdu_trigger_struct *del_node;
            SrvSmsTriggerFunc trigger_func = curr_node->trigger_func;
            void *user_data = curr_node->user_data;

            if (prev_node)
            {
                prev_node->next = curr_node->next;
            }
            else
            {
                trigger_head = curr_node->next;
            }

            del_node = curr_node;
            curr_node = curr_node->next;

            OslMfree(del_node);

            if (trigger_func)
            {
                trigger_func(user_data);
            }
        }
        else
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
}



//SLIM
/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_pdu_array_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_clear_set_pdu_array_flag(
        U16 pdu_id_list[],
        U8 total_pdu,
        srv_sms_node_flag_enum flag,
        MMI_BOOL is_clear)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < total_pdu; i++)
    {
        U16 pdu_id = pdu_id_list[i];

        if (pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
			if(is_clear == MMI_TRUE)
            {
                srv_sms_clear_pdu_flag(pdu_id, flag);//fix
            }
			else
            {
				srv_sms_set_pdu_flag(pdu_id, flag);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_pdu_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_check_pdu_flag(U16 pdu_id, srv_sms_node_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_PDU_FLAG, pdu_id, flag, srv_sms_pdu_list[pdu_id].type);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
    {
        if (srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM].type & flag)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (srv_sms_pdu_list[pdu_id].type & flag)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
#else
    if (srv_sms_pdu_list[pdu_id].type & flag)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pdu_storage_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_storage_enum srv_sms_get_pdu_storage_type(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_PDU_STORAGE_TYPE, pdu_id);

    if (pdu_id < storage_cntx.memory_status.me_total)
    {
        return SRV_SMS_STORAGE_ME;
    }
    else
    {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
             return SRV_SMS_STORAGE_TCARD;
        }
        else
        {
        return SRV_SMS_STORAGE_SIM;
    }
    #else
        return SRV_SMS_STORAGE_SIM;
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_pdu_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_pdu_exist(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__  
    if (((pdu_id < SRV_SMS_MAX_MSG_NUM) && 
        (srv_sms_pdu_list[pdu_id].status != SRV_SMS_STATUS_NONE)) ||
        ((pdu_id >= SRV_SMS_MAX_MSG_NUM) && 
        (srv_sms_tcard_pdu_list[pdu_id - SRV_SMS_MAX_MSG_NUM].status != SRV_SMS_STATUS_NONE)))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
#else
    if ((pdu_id < SRV_SMS_MAX_SMS_ENTRY) && 
        (srv_sms_pdu_list[pdu_id].status != SRV_SMS_STATUS_NONE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_PDU_EXIST, pdu_id, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pdu_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_status_enum srv_sms_get_pdu_status(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_PDU_STATUS, pdu_id);

    return (srv_sms_status_enum)(srv_sms_pdu_list[pdu_id].status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_get_unused_pdu_id(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id;
    U16 start_pdu_id;
    U16 end_pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID);

    srv_sms_get_start_and_end_pdu_id(storage_type, sim_id, &start_pdu_id, &end_pdu_id);

    pdu_id = srv_sms_get_unused_pdu_id_between(start_pdu_id, end_pdu_id);

    return pdu_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_start_and_end_pdu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_start_and_end_pdu_id(
                srv_sms_storage_enum storage_type,
                srv_sms_sim_enum sim_id,
                U16 *start_pdu_id,
                U16 *end_pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_id = SRV_SMS_INVALID_PDU_ID;
    U16 end_id = SRV_SMS_INVALID_PDU_ID;
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID, storage_type, sim_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID_1, memory_status->me_used, memory_status->me_total);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID_2, memory_status->sim_used[index], memory_status->sim_total[index]);

    switch (storage_type)
    {
        case SRV_SMS_STORAGE_SIM:
            if (memory_status->is_sim_valid[index] &&
                (memory_status->sim_used[index] < memory_status->sim_total[index]))
            {
                start_id =  memory_status->sim_start[index];
                end_id = start_id + memory_status->sim_total[index] - 1;
            }
            break;

    #ifdef __SRV_SMS_ME_PREFER_STORAGE_ONLY__
        case SRV_SMS_STORAGE_ME:
            if (memory_status->me_used < memory_status->me_total)
            {
                start_id = 0;
                end_id = memory_status->me_total - 1;
            }
            break;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        case SRV_SMS_STORAGE_TCARD:
            if (memory_status->tcard_used < memory_status->tcard_total)
            {
                start_id = SRV_SMS_MAX_MSG_NUM;
                end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
            }
            break;
    #endif
        case SRV_SMS_STORAGE_UNSPECIFIC:
        default:
	#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__  
            if (srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_TCARD)
            {
                if(memory_status->tcard_total > memory_status->tcard_used)
            	{    
	            	start_id = SRV_SMS_MAX_MSG_NUM;
                    end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
            	}
				else
				{
				    start_id = 0;
	                end_id = memory_status->me_total - 1;
				}
                
            }
            else
            {
                if(memory_status->me_total > memory_status->me_used)
                {
                    start_id = 0;
	                end_id = memory_status->me_total - 1;
                }
				else
				{
				    start_id = SRV_SMS_MAX_MSG_NUM;
                    end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
				}
                
            }
	#else
	        if (memory_status->me_used < memory_status->me_total)
            {
                start_id = 0;
                end_id = memory_status->me_total - 1;
            }
    #endif
            break;
    #else /* __SRV_SMS_ME_PREFER_STORAGE_ONLY__ */
        case SRV_SMS_STORAGE_ME:
            if (memory_status->me_used < memory_status->me_total)
            {
                start_id = 0;
                end_id = memory_status->me_total - 1;
            }
            break;
     #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        case SRV_SMS_STORAGE_TCARD:
            if (memory_status->tcard_used < memory_status->tcard_total)
            {
                start_id = SRV_SMS_MAX_MSG_NUM;
                end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
            }
            break;
    #endif

        case SRV_SMS_STORAGE_UNSPECIFIC:
        default:
            if (srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_ME)
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID_3);

                if (memory_status->me_used < memory_status->me_total)
                {
                    start_id = 0;
                    end_id = memory_status->me_total - 1;
                }
                else
                {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                    if (memory_status->is_sim_valid[index] &&
                        (memory_status->sim_used[index] < memory_status->sim_total[index]))
                    {
                        start_id =  memory_status->sim_start[index];
                        end_id = start_id + memory_status->sim_total[index] - 1;
                    }
                    else
                    {
                        if(storage_cntx.is_tcard_ready)
                        {
                            start_id =  SRV_SMS_MAX_MSG_NUM;
                            end_id = SRV_SMS_MAX_MSG_NUM + memory_status->tcard_total - 1;
                        }
                    }
            #else
                    if (memory_status->is_sim_valid[index] &&
                        (memory_status->sim_used[index] < memory_status->sim_total[index]))
                    {
                        start_id =  memory_status->sim_start[index];
                        end_id = start_id + memory_status->sim_total[index] - 1;
                    }
            #endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
                }
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_SIM)
                {
                    if (memory_status->is_sim_valid[index] &&
                        (memory_status->sim_used[index] < memory_status->sim_total[index]))
                    {
                        start_id =  memory_status->sim_start[index];
                        end_id = start_id + memory_status->sim_total[index] - 1;
                    }
                    else if(memory_status->me_used < memory_status->me_total)
                    {
                        start_id = 0;
                        end_id = memory_status->me_total - 1;
                    }
                    else
                    {
                        if(storage_cntx.is_tcard_ready)
                        {
                            start_id = SRV_SMS_MAX_MSG_NUM;
                            end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
                        }
                }
            }
            else
            {
                    if(memory_status->tcard_used < memory_status->tcard_total)
                    {
                        start_id = SRV_SMS_MAX_MSG_NUM;
                        end_id = memory_status->tcard_total - 1 + SRV_SMS_MAX_MSG_NUM;
                    }
                    else if(memory_status->me_used < memory_status->me_total)
                    {
                        start_id = 0;
                        end_id = memory_status->me_total - 1;
                    }
            else
            {
                        if (memory_status->is_sim_valid[index])
                        {
                            start_id =  memory_status->sim_start[index];
                            end_id = start_id + memory_status->sim_total[index] - 1;
                        }
                    }
                }
            
            #else
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID_4);

                if (memory_status->is_sim_valid[index] &&
                    (memory_status->sim_used[index] < memory_status->sim_total[index]))
                {
                    start_id =  memory_status->sim_start[index];
                    end_id = start_id + memory_status->sim_total[index] - 1;
                }
                else if (memory_status->me_used < memory_status->me_total)
                {
                    start_id = 0;
                    end_id = memory_status->me_total - 1;
                }
            #endif
                
            }
            break;
    #endif /* __SRV_SMS_ME_PREFER_STORAGE_ONLY__ */
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_START_AND_END_PDU_ID_5, start_id, end_id);

    *start_pdu_id = start_id;
    *end_pdu_id = end_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_pdu_id_between
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_get_unused_pdu_id_between(U16 start_pdu_id, U16 end_pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID_BETWEEN, start_pdu_id, end_pdu_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if((start_pdu_id <= end_pdu_id) && (start_pdu_id >= SRV_SMS_MAX_SMS_ENTRY) &&
        (end_pdu_id < SRV_SMS_MAX_TOTAL_SMS_ENTRY))
    {
        start_pdu_id -= SRV_SMS_MAX_MSG_NUM;
        end_pdu_id -= SRV_SMS_MAX_MSG_NUM;
        for (i = start_pdu_id; i < (end_pdu_id + 1); i++)
        {
            srv_sms_node_flag_enum node_flag = (srv_sms_node_flag_enum)(SRV_SMS_NODE_USED | SRV_SMS_NODE_INVALID);

            /* The PDU is Valid and not Used. */
            if ((srv_sms_tcard_pdu_list[i].type & node_flag) == 0)
            {
                pdu_id = i;
                break;
            }
        }

        if(pdu_id == SRV_SMS_INVALID_PDU_ID)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID_BETWEEN_1, pdu_id);
            return pdu_id;
        }
        else
        {
        pdu_id += SRV_SMS_MAX_MSG_NUM;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID_BETWEEN_1, pdu_id);
            return pdu_id;
        }
        
    }
    else
    {
    if ((start_pdu_id <= end_pdu_id) && (start_pdu_id < SRV_SMS_MAX_SMS_ENTRY) &&
        (end_pdu_id < SRV_SMS_MAX_SMS_ENTRY))
    {
        for (i = start_pdu_id; i < (end_pdu_id + 1); i++)
        {
            srv_sms_node_flag_enum node_flag = (srv_sms_node_flag_enum)(SRV_SMS_NODE_USED | SRV_SMS_NODE_INVALID);

            /* The PDU is Valid and not Used. */
            if ((srv_sms_pdu_list[i].type & node_flag) == 0)
            {
                pdu_id = i;
                break;
            }
        }
    }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID_BETWEEN_1, pdu_id);

        return pdu_id;
    }

#else
    if ((start_pdu_id <= end_pdu_id) && (start_pdu_id < SRV_SMS_MAX_SMS_ENTRY) &&
        (end_pdu_id < SRV_SMS_MAX_SMS_ENTRY))
    {
        for (i = start_pdu_id; i < (U32)(end_pdu_id + 1); i++)
        {
            srv_sms_node_flag_enum node_flag = (srv_sms_node_flag_enum)(SRV_SMS_NODE_USED | SRV_SMS_NODE_INVALID);

            /* The PDU is Valid and not Used. */
            if ((srv_sms_pdu_list[i].type & node_flag) == 0)
            {
                pdu_id = i;
                break;
            }
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_PDU_ID_BETWEEN_1, pdu_id);

    return pdu_id;
#endif


}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_common_pdu_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_check_common_pdu_error(U16 pdu_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_COMMON_PDU_ERROR, pdu_id, action);

    if (srv_sms_is_pdu_exist(pdu_id) == MMI_FALSE)
    {
        error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
    }
    else if (srv_sms_check_pdu_op_conflict(pdu_id, action) == MMI_TRUE)
    {
        error_cause = SRV_SMS_CAUSE_OP_CONFLICT;
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_NO_ERROR;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_COMMON_PDU_ERROR_1, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_pdu_op_conflict
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_check_pdu_op_conflict(U16 pdu_id, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_PDU_OP_CONFLICT, pdu_id, action);

    if (pdu_id != SRV_SMS_INVALID_MSG_ID)
    {
        srv_sms_node_flag_enum not_allow_flag = SRV_SMS_NODE_LOCKING;

        switch (action)
        {
            case SRV_SMS_ACTION_READ:
                not_allow_flag |= (SRV_SMS_NODE_UPDATING | SRV_SMS_NODE_DELETING);
                break;

            case SRV_SMS_ACTION_UPDATE:
                not_allow_flag |= (SRV_SMS_NODE_READING | SRV_SMS_NODE_DELETING);
                break;

            case SRV_SMS_ACTION_DELETE:
                not_allow_flag |= (SRV_SMS_NODE_READING | SRV_SMS_NODE_UPDATING);
                break;

            default:
                MMI_ASSERT(0);
                break;
        }

        result = srv_sms_check_pdu_flag(pdu_id, not_allow_flag);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CHECK_PDU_OP_CONFLICT_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_memory_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_memory_full(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unused_num = srv_sms_get_unused_space(storage_type, sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_MEMORY_FULL, unused_num);

    if (unused_num > 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_total_used_sms_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_total_used_sms_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U16 total_num;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total_num = memory_status->me_used;

    for (i = 0; i < SMS_SIM_NUM; i++)
    {
        total_num += memory_status->sim_used[i];
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_TOTAL_USED_SMS_SPACE, total_num);

    return total_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_space
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_unused_space(srv_sms_storage_enum storage_type, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U16 max_entry;
    U16 used_entry;
    U16 unused_entry;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_SPACE, storage_type, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    switch (storage_type)
    {
        case SRV_SMS_STORAGE_ME:
            max_entry = memory_status->me_total;
            used_entry = memory_status->me_used;
            break;

        case SRV_SMS_STORAGE_SIM:
            max_entry = memory_status->sim_total[index];
            used_entry = memory_status->sim_used[index];
            break;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        case SRV_SMS_STORAGE_TCARD:
            if(storage_cntx.is_tsms_ready)
            {
                max_entry = memory_status->tcard_total;
                used_entry = memory_status->tcard_used;
            }
            else
            {
                max_entry = used_entry = memory_status->tcard_total;
            }
            
            break;
    #endif

        case SRV_SMS_STORAGE_UNSPECIFIC:
        default:
        {
	    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(storage_cntx.is_tcard_ready)
            {
                max_entry = memory_status->me_total + memory_status->tcard_total;
                used_entry = memory_status->me_used + memory_status->tcard_used;
            }
            else
            {
    	        max_entry = memory_status->me_total;
                used_entry = memory_status->me_used;
            }
        #else
	        max_entry = memory_status->me_total;
            used_entry = memory_status->me_used;
        #endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
        
	    #else 
        
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(storage_cntx.is_tcard_ready)
            {
                max_entry = memory_status->me_total + memory_status->sim_total[index]+ memory_status->tcard_total;
                used_entry = memory_status->me_used + memory_status->sim_used[index]+ memory_status->tcard_used;
            }
            else
            {
                max_entry = memory_status->me_total + memory_status->sim_total[index];
                used_entry = memory_status->me_used + memory_status->sim_used[index];
            }
            
	    #else 
            max_entry = memory_status->me_total + memory_status->sim_total[index];
            used_entry = memory_status->me_used + memory_status->sim_used[index];
        #endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
            
	    #endif
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_SPACE_1, max_entry, used_entry);

    if (max_entry > used_entry)
    {
        unused_entry = max_entry - used_entry;
    }
    else
    {
        unused_entry = 0;
    }
    
    return unused_entry;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_enough_unused_space
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_enough_unused_space(srv_sms_storage_enum *storage_type, srv_sms_sim_enum sim_id, U16 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;
    U16 max_entry;
    U16 used_entry;
    //U16 unused_entry;
    U32 index;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_SPACE, storage_type, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    switch (*storage_type)
    {
        case SRV_SMS_STORAGE_ME:
            max_entry = memory_status->me_total;
            used_entry = memory_status->me_used;
            if(max_entry - used_entry >= number)
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }
            break;

        case SRV_SMS_STORAGE_SIM:
            max_entry = memory_status->sim_total[index];
            used_entry = memory_status->sim_used[index];
            if(max_entry - used_entry >= number)
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
        
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        case SRV_SMS_STORAGE_TCARD:
            max_entry = memory_status->tcard_total;
            used_entry = memory_status->tcard_used;
            if(max_entry - used_entry >= number)
            {
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }
            break;
    #endif
        case SRV_SMS_STORAGE_UNSPECIFIC:
        default:
    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            if(srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_ME)
            { 
                if(memory_status->me_total - memory_status->me_used >= number)//only modify for test
                {
                    *storage_type = SRV_SMS_STORAGE_ME; 
                    result = MMI_TRUE;
                    
                }
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                else
                {
                    if(storage_cntx.is_tsms_ready)
                    {
                    if(memory_status->tcard_total - memory_status->tcard_used >= number)
                    {
                        result = MMI_TRUE;
                        *storage_type = SRV_SMS_STORAGE_TCARD; 
                    }
                }
                    
                }
        #endif
            }
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            else
            {
                if(srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_TCARD)
                {
                    if(storage_cntx.is_tsms_ready && (memory_status->tcard_total - memory_status->tcard_used >= number))
                    {
                        result = MMI_TRUE;
                        *storage_type = SRV_SMS_STORAGE_TCARD; 
                    }
                    else
                    {
                        if(memory_status->me_total - memory_status->me_used >= number)
                        {
                            *storage_type = SRV_SMS_STORAGE_ME;
                            result = MMI_TRUE;
                        }
                        else
                        {
                            result = MMI_FALSE;
                        }
                    }
                }
            }
        #endif
    
    #else/*__SRV_SMS_SIMBOX_SUPPORT__*/
            if (srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_ME || srv_sms_get_prefer_storage(sim_id) == SRV_SMS_STORAGE_SIM)
            {
                max_entry = memory_status->me_total + memory_status->sim_total[index];
                used_entry = memory_status->me_used + memory_status->sim_used[index];
                if (max_entry - used_entry > number)
                {
                    result = MMI_TRUE;
                }
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                else
                {
                    if(storage_cntx.is_tsms_ready && (memory_status->tcard_total - memory_status->tcard_used >= number))
                    {
                        *storage_type = SRV_SMS_STORAGE_TCARD; 
                        result = MMI_TRUE;
                    }
                    else
                    {
                        result = MMI_FALSE;
                    }
                }
        #endif
            }
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            else
            {
                if(storage_cntx.is_tsms_ready && (memory_status->tcard_total - memory_status->tcard_used>= number))
                {
                    *storage_type = SRV_SMS_STORAGE_TCARD; 
                    return MMI_TRUE;
                }
                else
                {
                    max_entry = memory_status->me_total + memory_status->sim_total[index];
                    used_entry = memory_status->me_used + memory_status->sim_used[index];
                    if (max_entry - used_entry >= number)
                    {
                        return MMI_TRUE;
                    }
                    else
                    {
                        result = MMI_FALSE;
                    }
                }
            }
        #endif
    
    #endif/*__SRV_SMS_SIMBOX_SUPPORT__*/
            
            break;
    }

   // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_SPACE_1, max_entry, used_entry);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_increment_used_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_increment_used_memory(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_INCREMENT_USED_MEMORY, pdu_id, memory_status->me_total);

    if (pdu_id < memory_status->me_total)
    {
        memory_status->me_used++;
    }
    else
    {
        U32 index;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
             memory_status->tcard_used++;
        }
        else
        {
            index = srv_sms_pdu_id_to_sim_index(pdu_id);

            MMI_ASSERT(index < SMS_SIM_NUM);

            memory_status->sim_used[index]++;
        }
    #else
        index = srv_sms_pdu_id_to_sim_index(pdu_id);

        MMI_ASSERT(index < SMS_SIM_NUM);

        memory_status->sim_used[index]++;
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_decrement_used_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_decrement_used_memory(U16 pdu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_memory_status_struct *memory_status = &storage_cntx.memory_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DECREMENT_USED_MEMORY, pdu_id, memory_status->me_total);

    if (pdu_id < memory_status->me_total)
    {
        memory_status->me_used--;
    }
    else
    {
        U32 index;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(pdu_id < SRV_SMS_MAX_MSG_NUM)
        {
            index = srv_sms_pdu_id_to_sim_index(pdu_id);
            MMI_ASSERT(index < SMS_SIM_NUM);
            memory_status->sim_used[index]--;
        }
        else
        {
             memory_status->tcard_used--;
        }
    #else  
        index = srv_sms_pdu_id_to_sim_index(pdu_id);
        MMI_ASSERT(index < SMS_SIM_NUM);
        memory_status->sim_used[index]--;
    #endif

    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_pdu(  
        U16 pdu_id,
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
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_PDU, pdu_id);

    error_cause = srv_sms_check_common_pdu_error(pdu_id, SRV_SMS_ACTION_READ);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        U16 index;
        srv_sms_storage_enum storage_type;
        srv_sms_sim_enum sim_id;

        index = srv_sms_pdu_id_to_record_index(pdu_id, &storage_type, &sim_id);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_PDU_1, storage_type);

        if (index != SRV_SMS_INVALID_INDEX)
        {
            srv_sms_read_pdu_cntx_struct *read_pdu_cntx;

            read_pdu_cntx = OslMalloc(sizeof(srv_sms_read_pdu_cntx_struct));

            read_pdu_cntx->storage_type = storage_type;
            read_pdu_cntx->callback_func = callback_func;
            read_pdu_cntx->user_data = user_data;

            if (storage_type == SRV_SMS_STORAGE_ME)
            {
                srv_sms_read_me_sms(index, srv_sms_read_pdu_callback, read_pdu_cntx);
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(storage_type == SRV_SMS_STORAGE_SIM)
                {
                srv_sms_read_sim_sms(index, sim_id, srv_sms_read_pdu_callback, read_pdu_cntx);
            }
                else
                {
                    srv_sms_read_tcard_sms(index, sim_id, srv_sms_read_pdu_callback, read_pdu_cntx);
                }  
            #else
                srv_sms_read_sim_sms(index, sim_id, srv_sms_read_pdu_callback, read_pdu_cntx);
            #endif
            }
        }
        else
        {
            SMS_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_READ,
                SRV_SMS_CAUSE_INVALID_MEM_INDEX,
                user_data,
                callback_func);
        }
    }
    else 
    {
        SMS_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_READ,
            error_cause,
            user_data,
            callback_func);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_add_pdu(
        srv_sms_add_pdu_struct *add_data,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_pdu_id;
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;
    srv_sms_storage_enum storage_type = add_data->storage_type;
    srv_sms_spdu_struct *spdu_data = add_data->spdu_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_SIM__
    sim_id = (srv_sms_sim_enum)spdu_data->sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_PDU, add_data->curr_seg, storage_type, sim_id);

    if (storage_cntx.is_ready)
    {
        unused_pdu_id = srv_sms_get_unused_pdu_id(storage_type, sim_id);

        if (unused_pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            srv_sms_add_pdu_cntx_struct *add_pdu_cntx;
            srv_sms_pdu_node_struct pdu_node;
            srv_sms_storage_enum dest_storage;
            srv_sms_sim_enum tmp_sim_id;
            U8 ori_msg_status;
            U16 index;
        #ifdef __SMS_CLOUD_SUPPORT__
            srv_sms_restore_cntx_struct *temp_restore_cntx;
        #endif

            /*backup or restore*/
        #ifdef __SMS_CLOUD_SUPPORT__
            if((srv_sms_get_cloud_action_ctnx() == SRV_SMS_CLOUD_ACTION_RESTORE) && (callback_func == srv_sms_save_msg_callback))
            {
                temp_restore_cntx = srv_sms_get_restore_ctnx();
                temp_restore_cntx->uid_index = unused_pdu_id;
            }
        #endif   
            add_pdu_cntx = OslMalloc(sizeof(srv_sms_add_pdu_cntx_struct));

            add_pdu_cntx->pdu_id = unused_pdu_id;
            add_pdu_cntx->callback_func = callback_func;
            add_pdu_cntx->user_data = user_data;

            /* Remind the original status */
            ori_msg_status = spdu_data->status;

            srv_sms_init_pdu_node(&pdu_node);
            pdu_node.segment = add_data->curr_seg;
            pdu_node.status = ori_msg_status;
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            pdu_node.msg_ref = add_data->msg_ref;
            pdu_node.tp_st = spdu_data->tp_st;
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */

        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if (unused_pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_pdu_node_struct tcard_pdu_node;
                tcard_pdu_node.segment = pdu_node.segment;
                tcard_pdu_node.status = pdu_node.status;
                tcard_pdu_node.type = pdu_node.type; 
                tcard_pdu_node.read_count = pdu_node.read_count; 
                tcard_pdu_node.next_pdu_id = pdu_node.next_pdu_id; 
                tcard_pdu_node.prev_pdu_id = pdu_node.prev_pdu_id;
            #ifdef __SRV_SMS_DELIVERY_STATUS__
                tcard_pdu_node.msg_ref = add_data->msg_ref;
                tcard_pdu_node.tp_st = spdu_data->tp_st;
            #else
                tcard_pdu_node.msg_ref = 0xff;
                tcard_pdu_node.tp_st = 0xff; /*check again*/
            #endif
                srv_sms_add_tcard_pdu_node(unused_pdu_id, &tcard_pdu_node);
            }
            else
        #endif
            {
                srv_sms_add_pdu_node(unused_pdu_id, &pdu_node);
            }

            index = srv_sms_pdu_id_to_record_index(unused_pdu_id, &dest_storage, &tmp_sim_id);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_PDU_1, dest_storage, ori_msg_status);

            MMI_ASSERT(index != SRV_SMS_INVALID_INDEX);
            MMI_ASSERT((storage_type == SRV_SMS_STORAGE_UNSPECIFIC) || (storage_type == dest_storage));

            /* In the SIM Card, there isn't DRAFT status */
            if ((dest_storage == SRV_SMS_STORAGE_SIM) &&
                (ori_msg_status == SRV_SMS_STATUS_DRAFT))
            {
                spdu_data->status = SRV_SMS_STATUS_UNSENT;
            }

            spdu_data->status = srv_sms_msg_status_to_spdu_status((srv_sms_status_enum)spdu_data->status);

            if (dest_storage == SRV_SMS_STORAGE_ME)
            {
                srv_sms_write_me_sms(
                    index,
                    spdu_data,
                    srv_sms_add_pdu_callback,
                    add_pdu_cntx);
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if (dest_storage == SRV_SMS_STORAGE_TCARD)
                {
                    srv_tcard_op_struct read_cntx;
                    S32 error_cause;
                    MMI_BOOL result;
                    srv_sms_tcard_spdu_struct *tcard_spdu_data;
                    tcard_spdu_data = (srv_sms_tcard_spdu_struct*)OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                    tcard_spdu_data->status = spdu_data->status;
                    tcard_spdu_data->timestamp = spdu_data->timestamp;
                #ifdef __SRV_SMS_MULTI_SIM__
                    tcard_spdu_data->sim_id = spdu_data->sim_id;
                #else
                    tcard_spdu_data->sim_id = SRV_SMS_SIM_1;
                #endif

                #ifdef __SRV_SMS_MULTI_ADDR__
                    tcard_spdu_data->addr_num = spdu_data->addr_num;
                    tcard_spdu_data->start_addr_id = spdu_data->start_addr_id;
                #else
                    tcard_spdu_data->addr_num = 0;
                    tcard_spdu_data->start_addr_id = 0xffff;
                #endif

                #ifdef __SRV_SMS_RESEND_COUNT__
                    tcard_spdu_data->resend_count = spdu_data->resend_count;
                #else
                    tcard_spdu_data->resend_count = 0;
                #endif
                
                #ifdef __SRV_SMS_DELIVERY_STATUS__
                    tcard_spdu_data->tp_st = spdu_data->tp_st;
                #else
                    tcard_spdu_data->tp_st = 0;
                #endif
               
                    memcpy(tcard_spdu_data->pdu,spdu_data->pdu,SRV_SMS_MAX_PDU_SIZE);
                    //OslMfree(spdu_data);
                    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                    read_cntx.record_num = 1;
                    read_cntx.start_record_id = index;
                    error_cause = srv_tcard_sync_write_record(&read_cntx, (CHAR*)tcard_spdu_data);
                    if (error_cause >= 0)
                    {
                        result = MMI_TRUE;
                        SRV_SMS_POST_CALLBACK(
                            SRV_SMS_ACTION_SAVE,
                            result,
                            error_cause,
                            NULL,
                            add_pdu_cntx,
                            srv_sms_add_pdu_callback);
  
                    }
                    else
                    {
                        result = MMI_FALSE;
                        SRV_SMS_POST_CALLBACK(
                            SRV_SMS_ACTION_SAVE,
                            result,
                            error_cause,
                            NULL,
                            add_pdu_cntx,
                            srv_sms_add_pdu_callback);
                    }
                    OslMfree(tcard_spdu_data);
                    if(add_pdu_cntx->callback_func == srv_sms_copy_callback)
                    {
                        srv_sms_free_pdu_block(spdu_data);
                    }
       

                    
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
            #endif
                srv_sms_write_sim_sms(
                    index,
                    sim_id,
                    spdu_data,
                    srv_sms_add_pdu_callback,
                    add_pdu_cntx);
			#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            }
		    #endif

            }

            /* Restore the status */
            spdu_data->status = ori_msg_status;
        }
        else
        {
            SMS_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_SAVE,
                SRV_SMS_CAUSE_MEM_FULL,
                user_data,
                callback_func);
        }
    }
    else
    {
        SMS_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_SAVE,
            SRV_SMS_CAUSE_NOT_READY,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_add_pdu_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_add_pdu_cntx_struct *add_pdu_cntx = (srv_sms_add_pdu_cntx_struct*)callback_data->user_data;
    srv_sms_add_pdu_cb_struct add_pdu_cb_data;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    void *user_data;
    SrvSmsCallbackFunc callback_func;
    U16 pdu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_PDU_CALLBACK, callback_data->result, callback_data->cause);

    add_pdu_cntx = (srv_sms_add_pdu_cntx_struct*)callback_data->user_data;
    pdu_id = add_pdu_cntx->pdu_id;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(add_pdu_cntx->pdu_id >= SRV_SMS_MAX_MSG_NUM && (!storage_cntx.is_tsms_ready))
    {
        result = MMI_FALSE; 
        cause = SRV_SMS_CAUSE_NOT_READY;
    }
#endif
    if (result)
    {
        /* The added PDU may be removed when SIM refresh or SIM card removed*/
        if (srv_sms_is_pdu_exist(pdu_id))
        {
            add_pdu_cb_data.pdu_id = pdu_id;

        #ifdef __SRV_SMS_RECENT_EVENT__
            srv_sms_set_pdu_recent_event_flag(pdu_id, MMI_TRUE);
        #endif /* __SRV_SMS_RECENT_EVENT__ */
        }
        else
        {
            result = MMI_FALSE;
            cause = SRV_SMS_CAUSE_NOT_READY;

            add_pdu_cb_data.pdu_id = SRV_SMS_INVALID_PDU_ID;
        }
    }
    else
    {
        add_pdu_cb_data.pdu_id = SRV_SMS_INVALID_PDU_ID;

        /* Delete the added PDU node */
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_delete_tcard_pdu_node(pdu_id - SRV_SMS_MAX_MSG_NUM);
        }
        else
    #endif
        {
            srv_sms_delete_pdu_node(pdu_id);
        }      
    }

    user_data = add_pdu_cntx->user_data;
    callback_func = add_pdu_cntx->callback_func;

    /* Free Add PDU Context Data */
    OslMfree(add_pdu_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_SAVE,
        result,
        cause,
        &add_pdu_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_delete_pdu(
        U16 pdu_id,
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
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU, pdu_id);

    error_cause = srv_sms_check_common_pdu_error(pdu_id, SRV_SMS_ACTION_DELETE);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        U16 index;
        srv_sms_storage_enum storage_type;
        srv_sms_sim_enum sim_id;

        index = srv_sms_pdu_id_to_record_index(pdu_id, &storage_type, &sim_id);

        if (index != SRV_SMS_INVALID_INDEX)
        {
            srv_sms_delete_pdu_cntx_struct  *delete_pdu_cntx;
            srv_sms_spdu_struct *spdu_data = NULL;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            srv_sms_tcard_spdu_struct *tcard_spdu_data = NULL;
        #endif
            delete_pdu_cntx = OslMalloc(sizeof(srv_sms_delete_pdu_cntx_struct));

        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(storage_type == SRV_SMS_STORAGE_TCARD)
            {
                tcard_spdu_data = OslMalloc(sizeof(srv_sms_tcard_spdu_struct));
                srv_sms_reset_tcard_spdu(tcard_spdu_data);            
            }
            else
        #endif
            {
                spdu_data = OslMalloc(sizeof(srv_sms_spdu_struct));
                srv_sms_reset_spdu(spdu_data);
            }



            delete_pdu_cntx->pdu_id = pdu_id;
            delete_pdu_cntx->callback_func = callback_func;
            delete_pdu_cntx->user_data = user_data;

            if (storage_type == SRV_SMS_STORAGE_ME)
            {
                srv_sms_write_me_sms(
                    index,
                    spdu_data,
                    srv_sms_delete_pdu_callback,
                    delete_pdu_cntx);
                OslMfree(spdu_data);
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(storage_type == SRV_SMS_STORAGE_TCARD)
                {
                    srv_tcard_op_struct cntx;
                    srv_sms_tcard_sync_struct *asyc_cntx;
                    S32 result;
                    S32 error_cause;
                    cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                    cntx.record_num = 1;
                    cntx.start_record_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
                    result = srv_tcard_sync_write_record(
                                &cntx,
                                (void*)tcard_spdu_data);

                    OslMfree(tcard_spdu_data);
                    if (result >= 0)
                    {
                        result = MMI_TRUE;
                        error_cause = 0;
                    }
                    else
                    {
                        error_cause = result;
                        result = MMI_FALSE;
                    }
                    asyc_cntx = (srv_sms_tcard_sync_struct*)OslMalloc(sizeof(srv_sms_tcard_sync_struct));
                    asyc_cntx->action = SRV_SMS_ACTION_SAVE;
                    asyc_cntx->result = result;
                    asyc_cntx->error_cause = error_cause;
                    asyc_cntx->action_data = NULL;
                    asyc_cntx->user_data = delete_pdu_cntx;
                    asyc_cntx->callback_func = srv_sms_delete_pdu_callback;
                    StartTimerEx(SRV_SMS_TCARD_ASYNC_TIMER_ID, 0, srv_sms_tcard_delete_sync_handle, asyc_cntx);
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif    
                }           
                else
            #endif
                {
                    srv_sms_write_sim_sms(
                        index,
                        sim_id,
                        spdu_data,
                        srv_sms_delete_pdu_callback,
                        delete_pdu_cntx);
                        OslMfree(spdu_data);
                }
            }

            
        }
        else
        {
            SMS_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_DELETE,
                SRV_SMS_CAUSE_INVALID_MEM_INDEX,
                user_data,
                callback_func);
        }
    }
    else
    {
        SMS_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_DELETE,
            error_cause,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_delete_pdu_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_pdu_cntx_struct *delete_pdu_cntx;
    srv_sms_delete_pdu_cb_struct delete_pdu_cb_data;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_PDU_CALLBACK, callback_data->result, callback_data->cause);

    delete_pdu_cntx = (srv_sms_delete_pdu_cntx_struct*)callback_data->user_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(delete_pdu_cntx->pdu_id >= SRV_SMS_MAX_MSG_NUM && (!storage_cntx.is_tsms_ready))
    {
        result = MMI_FALSE;
        cause = SRV_SMS_CAUSE_NOT_READY;
    }
#endif
    if (result)
    {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(delete_pdu_cntx->pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_sms_delete_tcard_pdu_node(delete_pdu_cntx->pdu_id - SRV_SMS_MAX_MSG_NUM);
        }
        else
        {
            srv_sms_delete_pdu_node(delete_pdu_cntx->pdu_id);
        }
    
    #else
        srv_sms_delete_pdu_node(delete_pdu_cntx->pdu_id);
    #endif
    #ifdef __SRV_SMS_RECENT_EVENT__
        srv_sms_set_pdu_recent_event_flag(delete_pdu_cntx->pdu_id, MMI_FALSE);
    #endif /* __SRV_SMS_RECENT_EVENT__ */
    }

    user_data = delete_pdu_cntx->user_data;
    callback_func = delete_pdu_cntx->callback_func;

    /* Free Delete PDU Context Data */
    OslMfree(delete_pdu_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_DELETE,
        result,
        cause,
        &delete_pdu_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_pdu(
        U16 pdu_id,
        srv_sms_update_pdu_struct* update_data,
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
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_PDU, pdu_id);

    error_cause = srv_sms_check_common_pdu_error(pdu_id, SRV_SMS_ACTION_UPDATE);

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        U16 index;
        srv_sms_storage_enum dest_storage;
        srv_sms_sim_enum sim_id;

        index = srv_sms_pdu_id_to_record_index(pdu_id, &dest_storage, &sim_id);

        if (index != SRV_SMS_INVALID_INDEX)
        {
            srv_sms_update_pdu_cntx_struct *update_pdu_cntx;
            srv_sms_spdu_struct *spdu_data = update_data->spdu_data;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            srv_sms_tcard_spdu_struct *tcard_spdu_data = update_data->tcard_spdu_data;
        #endif
            U8 ori_msg_status;

            update_pdu_cntx = OslMalloc(sizeof(srv_sms_update_pdu_cntx_struct));

            update_pdu_cntx->pdu_id = pdu_id;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if (pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                update_pdu_cntx->new_status = (srv_sms_status_enum)tcard_spdu_data->status;
            }
            else
            {
                update_pdu_cntx->new_status = (srv_sms_status_enum)spdu_data->status;
            }
        #else
            update_pdu_cntx->new_status = (srv_sms_status_enum)spdu_data->status;
        #endif
            
            update_pdu_cntx->update_flag = update_data->update_flag;
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            update_pdu_cntx->msg_ref = update_data->msg_ref;
            update_pdu_cntx->tp_st = (srv_sms_sr_status_enum)spdu_data->tp_st;
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
            update_pdu_cntx->callback_func = callback_func;
            update_pdu_cntx->user_data = user_data;

            /* Remind the original status */
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(dest_storage == SRV_SMS_STORAGE_TCARD)
            {
                ori_msg_status = tcard_spdu_data->status;
            }
            else
            {
                ori_msg_status = spdu_data->status;
            }
        #else
            ori_msg_status = spdu_data->status;
        #endif

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_PDU_1, dest_storage, ori_msg_status);

            /* In the SIM Card, there isn't DRAFT status */
            if ((dest_storage == SRV_SMS_STORAGE_SIM) &&
                (ori_msg_status == SRV_SMS_STATUS_DRAFT))
            {
                spdu_data->status = SRV_SMS_STATUS_UNSENT;
            }
         #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(dest_storage == SRV_SMS_STORAGE_TCARD)
            {
                tcard_spdu_data->status = srv_sms_msg_status_to_spdu_status((srv_sms_status_enum)tcard_spdu_data->status);
            }
            else
            {
                spdu_data->status = srv_sms_msg_status_to_spdu_status((srv_sms_status_enum)spdu_data->status);
            } 
         #else
            spdu_data->status = srv_sms_msg_status_to_spdu_status((srv_sms_status_enum)spdu_data->status);
         #endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/

            if (dest_storage == SRV_SMS_STORAGE_ME)
            {
                srv_sms_write_me_sms(
                    index,
                    spdu_data,
                    srv_sms_update_pdu_callback,
                    update_pdu_cntx);
            }
            else
            {
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                if(dest_storage == SRV_SMS_STORAGE_TCARD)
                {
                    srv_tcard_op_struct write_cntx;
                    S32 error_cause;
                    MMI_BOOL result = MMI_FALSE;
                    
                    write_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                    write_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
                    write_cntx.record_num = 1;
                    write_cntx.start_record_id = index;
                    error_cause = srv_tcard_sync_write_record(
                        &write_cntx,
                        (void*)tcard_spdu_data);
                    if (error_cause >= 0)
                    {
                        result = MMI_TRUE;
                    }
                    
                    SRV_SMS_POST_CALLBACK(
                        SRV_SMS_ACTION_UPDATE,
                        result,
                        error_cause,
                        NULL,
                        update_pdu_cntx,
                        srv_sms_update_pdu_callback);
                    
                        srv_sms_free_tcard_pdu_block(tcard_spdu_data);
                    
                }
                else
            #endif
                {
                    srv_sms_write_sim_sms(
                        index,
                        sim_id,
                        spdu_data,
                        srv_sms_update_pdu_callback,
                        update_pdu_cntx);
                }
            
            }

            /* Restore the status */
            spdu_data->status = ori_msg_status;
        }
        else
        {
            SMS_ASYNC_ERR_CALLBACK(
                SRV_SMS_ACTION_UPDATE,
                SRV_SMS_CAUSE_INVALID_MEM_INDEX,
                user_data,
                callback_func);
        }
    }
    else
    {
        SMS_ASYNC_ERR_CALLBACK(
            SRV_SMS_ACTION_UPDATE,
            error_cause,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_pdu_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_update_pdu_cntx_struct *update_pdu_cntx;
    srv_sms_update_pdu_cb_struct update_pdu_cb_data;
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_PDU_CALLBACK, callback_data->result, callback_data->cause);

    update_pdu_cntx = (srv_sms_update_pdu_cntx_struct*)callback_data->user_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (update_pdu_cntx->pdu_id >= SRV_SMS_MAX_MSG_NUM && (!storage_cntx.is_tsms_ready))
    {
        result = MMI_FALSE;
        cause = SRV_SMS_CAUSE_NOT_READY;
    }
#endif
    if (result)
    {
        U16 pdu_id;

        pdu_id = update_pdu_cntx->pdu_id;

        /* The added PDU may be removed when SIM refresh or SIM card removed*/
        if (srv_sms_is_pdu_exist(pdu_id))
        {
            srv_sms_pdu_node_struct *pdu_node;



        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                srv_sms_tcard_pdu_node_struct *tcard_pdu_node;
                srv_tcard_op_struct read_cntx;


                
                tcard_pdu_node = srv_sms_get_tcard_pdu_node(pdu_id);
                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_STATUS)
                {
                    tcard_pdu_node->status = update_pdu_cntx->new_status;
                }
                tcard_pdu_node->type &= ~(SRV_SMS_NODE_UPDATING);
            #ifdef __SRV_SMS_DELIVERY_STATUS__
                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_MSG_REF)
                {
                    tcard_pdu_node->msg_ref = update_pdu_cntx->msg_ref;
                }

                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_DELIVERY_STATUS)
                {
                    tcard_pdu_node->tp_st = update_pdu_cntx->tp_st;
                }
            #endif
                //update pdu index file
                read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX;
                read_cntx.start_record_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
                read_cntx.record_num = 1;
                srv_tcard_sync_write_record(&read_cntx, (CHAR*)tcard_pdu_node);
                
            }
            else
            {
                pdu_node = srv_sms_get_pdu_node(pdu_id);

                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_STATUS)
                {
                    pdu_node->status = update_pdu_cntx->new_status;
                }

            #ifdef __SRV_SMS_DELIVERY_STATUS__
                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_MSG_REF)
                {
                    pdu_node->msg_ref = update_pdu_cntx->msg_ref;
                }

                if (update_pdu_cntx->update_flag & SRV_SMS_PARA_DELIVERY_STATUS)
                {
                    pdu_node->tp_st = update_pdu_cntx->tp_st;
                }
            #endif
            }

        #else
            pdu_node = srv_sms_get_pdu_node(pdu_id);

            if (update_pdu_cntx->update_flag & SRV_SMS_PARA_STATUS)
            {
                pdu_node->status = update_pdu_cntx->new_status;
            }

        #ifdef __SRV_SMS_DELIVERY_STATUS__
            if (update_pdu_cntx->update_flag & SRV_SMS_PARA_MSG_REF)
            {
                pdu_node->msg_ref = update_pdu_cntx->msg_ref;
            }

            if (update_pdu_cntx->update_flag & SRV_SMS_PARA_DELIVERY_STATUS)
            {
                pdu_node->tp_st = update_pdu_cntx->tp_st;
            }
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
        #endif
            
        }
        else
        {
            result = MMI_FALSE;
            cause = SRV_SMS_CAUSE_NOT_READY;
        }
    }

    user_data = update_pdu_cntx->user_data;
    callback_func = update_pdu_cntx->callback_func;

    /* Free Update PDU Context Data */
    OslMfree(update_pdu_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_UPDATE,
        result,
        cause,
        &update_pdu_cb_data,
        user_data,
        callback_func);
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_tcard_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_tcard_sms(
        U16 index,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct read_cntx;
    srv_sms_read_tcard_sms_cntx_struct *read_tcard_cntx;
    CHAR *buff;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SIM_SMS, index, sim_id);
    buff = srv_sms_alloc_tcard_pdu_block();
    read_tcard_cntx = OslMalloc(sizeof(srv_sms_read_tcard_sms_cntx_struct));
    //read_cntx = OslMalloc(sizeof(srv_tcard_op_struct));
    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
    read_cntx.record_num = 1;
    read_cntx.start_record_id = index;
    read_tcard_cntx->callback_func = callback_func;
    read_tcard_cntx->user_data = user_data;
    read_tcard_cntx->spdu = buff;
    srv_tcard_read_record(
            &read_cntx, 
            buff,
            srv_sms_read_tcard_sms_callback,
            read_tcard_cntx);

}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_sim_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_tcard_sms_callback(srv_tcard_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_tcard_sms_cntx_struct *read_tcard_cntx;
    srv_sms_spdu_struct *spdu_data;
    srv_sms_callback_struct temp_cb_data;
    SrvSmsCallbackFunc callback_func;
    srv_sms_read_cntx_struct *read_cntx;
    srv_sms_read_pdu_cntx_struct *read_pdu_cntx;
    SrvSmsCallbackFunc  temp_callback_func = NULL;
    srv_sms_tcard_spdu_struct *tcard_spdu_data;
		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_tcard_cntx = (srv_sms_read_tcard_sms_cntx_struct*)callback_data->user_data;
    tcard_spdu_data = (srv_sms_tcard_spdu_struct*)read_tcard_cntx->spdu;
    //MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SIM_SMS_CALLBACK, callback_data->result, callback_data->cause);

    spdu_data =  srv_sms_alloc_pdu_block();
    if(spdu_data == NULL)
    {
    	temp_cb_data.result = MMI_FALSE;
    	temp_cb_data.cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
    }
    else
   {

    if (callback_data->result >= 0)
    {
        
        temp_cb_data.result = MMI_TRUE;
        temp_cb_data.cause = SRV_SMS_CAUSE_NO_ERROR;

        /* Convert TCARD SPDU Data to Common SPDU */
        
        /* this status is msg status, not the SPDU status, refer to srv_sms_status_enum */
        spdu_data->status = tcard_spdu_data->status;
        memcpy(spdu_data->pdu,tcard_spdu_data->pdu,SRV_SMS_MAX_PDU_SIZE);
        spdu_data->timestamp = tcard_spdu_data->timestamp;
    #ifdef __SRV_SMS_MULTI_SIM__
        spdu_data->sim_id = tcard_spdu_data->sim_id;
    #endif /* __SRV_SMS_MULTI_SIM__ */

    #ifdef __SRV_SMS_MULTI_ADDR__
        spdu_data->addr_num = tcard_spdu_data->addr_num;
        spdu_data->start_addr_id = tcard_spdu_data->start_addr_id;
    #endif 

    #ifdef __SRV_SMS_RESEND_COUNT__
        spdu_data->resend_count = tcard_spdu_data->resend_count;
    #endif 
    #ifdef __SRV_SMS_DELIVERY_STATUS__
        spdu_data->tp_st = tcard_spdu_data->tp_st;
    #endif 
    }
    else
    {
        temp_cb_data.result = MMI_FALSE;
        if(SRV_TCARD_OP_MEM_INSUFFICIENT == callback_data->result)
        {
            temp_cb_data.cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        }
        else
        {
            temp_cb_data.cause = SRV_SMS_CAUSE_SIM_FAILURE;
        }
    }
	}
    temp_cb_data.action = SRV_SMS_ACTION_READ;
    temp_cb_data.action_data = spdu_data;
    temp_cb_data.user_data = read_tcard_cntx->user_data;

    callback_func = read_tcard_cntx->callback_func;
   // srv_sms_free_tcard_pdu_block(tcard_spdu_data);
    if(callback_func == srv_sms_read_pdu_callback)
    {
    	read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)read_tcard_cntx->user_data;
            
    	if(read_pdu_cntx->callback_func == srv_sms_read_msg_callback)
    	{
            read_cntx = (srv_sms_read_cntx_struct*)read_pdu_cntx->user_data;
            read_cntx->spdu_list[read_cntx->curr_index] = spdu_data;
            srv_sms_free_tcard_pdu_block(tcard_spdu_data);
    	    read_cntx->curr_index ++;
    	}
        if(read_pdu_cntx->callback_func == srv_sms_change_status_callback)
        {
            srv_sms_change_status_cntx_struct *change_cntx;
            change_cntx = (srv_sms_change_status_cntx_struct*)read_pdu_cntx->user_data;
            change_cntx->tcard_pdu = tcard_spdu_data;//for update
        }
		if(read_pdu_cntx->callback_func == srv_sms_update_msg_callback)
		{
		    srv_sms_update_cntx_struct *update_cntx;
			update_cntx = (srv_sms_update_cntx_struct*)read_pdu_cntx->user_data;
			update_cntx->tcard_pdu = tcard_spdu_data;//for update
		}

    }
    if(callback_func == srv_sms_read_pdu_callback)
    {
        read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)read_tcard_cntx->user_data;
        temp_callback_func = read_pdu_cntx->callback_func;
    }

    if (callback_func != NULL)
    {
        callback_func(&temp_cb_data);
    }
    
    if(callback_func != srv_sms_read_pdu_callback)
    {
    	srv_sms_free_pdu_block(spdu_data);
    }
    else
    {
        if(temp_callback_func != srv_sms_read_msg_callback)
    	{
            srv_sms_free_pdu_block(spdu_data);
            srv_sms_free_tcard_pdu_block(tcard_spdu_data);
    	}
    }
    OslMfree(read_tcard_cntx);
}

void srv_sms_write_tcard_sms(
        U16 index,
        srv_sms_tcard_spdu_struct *spdu_data,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct read_cntx;
    CHAR *buff;    
    S32 error_cause;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SIM_SMS, index, sim_id);
    //read_cntx = OslMalloc(sizeof(srv_tcard_op_struct));
    read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
    read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
    read_cntx.record_num = 1;
    read_cntx.start_record_id = index;
    error_cause = srv_tcard_sync_write_record(
            &read_cntx, 
                        (CHAR*)spdu_data);


    if (error_cause >= 0)
    {
        result = MMI_TRUE;
        SRV_SMS_POST_CALLBACK(
            SRV_SMS_ACTION_SAVE,
            result,
            error_cause,
            NULL,
            user_data,
            callback_func);

    }
    else
    {
        result = MMI_FALSE;
        SRV_SMS_POST_CALLBACK(
            SRV_SMS_ACTION_SAVE,
            result,
            error_cause,
            NULL,
            user_data,
            callback_func);
    }

}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_sim_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_sim_sms(
        U16 index,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_sim_sms_cntx_struct *read_sim_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SIM_SMS, index, sim_id);

    read_sim_cntx = OslMalloc(sizeof(srv_sms_read_sim_sms_cntx_struct));

#ifdef __SRV_SMS_SIM_CUST_DATA__
    read_sim_cntx->record_index = index;
#endif /* __SRV_SMS_SIM_CUST_DATA__ */
    read_sim_cntx->sim_id = sim_id;
    read_sim_cntx->callback_func = callback_func;
    read_sim_cntx->user_data = user_data;

    srv_sim_read_record(
        FILE_SMS_IDX,
        NULL,        
        (U16)(index + 1),
        SRV_SMS_MAX_SIM_SPDU_SIZE,
        (mmi_sim_enum)(sim_id & 0xFF),
        srv_sms_read_sim_sms_callback,
        read_sim_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_sim_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_sim_sms_callback(srv_sim_cb_struct*  callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_sim_sms_cntx_struct *read_sim_cntx;
    srv_sim_data_struct *read_sim_rsp;
    srv_sms_spdu_struct *spdu_data;
    srv_sms_callback_struct temp_cb_data;
    SrvSmsCallbackFunc callback_func;
    srv_sms_read_cntx_struct *read_cntx;
    srv_sms_read_pdu_cntx_struct *read_pdu_cntx;
    SrvSmsCallbackFunc  temp_callback_func = NULL;
		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_sim_cntx = (srv_sms_read_sim_sms_cntx_struct*)callback_data->user_data;
    read_sim_rsp = (srv_sim_data_struct*)callback_data->data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SIM_SMS_CALLBACK, callback_data->result, callback_data->cause);

    spdu_data =  srv_sms_alloc_pdu_block();
    if(spdu_data == NULL)
    {
	temp_cb_data.result = MMI_FALSE;
	temp_cb_data.cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
    }
    else
   {
#ifdef __SRV_SMS_MULTI_SIM__
    spdu_data->sim_id = read_sim_cntx->sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

    if (callback_data->result)
    {
    #ifdef __SRV_SMS_SIM_CUST_DATA__
        srv_sms_sim_cust_data_struct cust_data;
        MMI_BOOL result;
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */

        temp_cb_data.result = MMI_TRUE;
        temp_cb_data.cause = SRV_SMS_CAUSE_NO_ERROR;

        /* Convert SIM SPDU Data to Common SPDU */
        memcpy(spdu_data, read_sim_rsp->data, SRV_SMS_MAX_SIM_SPDU_SIZE);

        spdu_data->timestamp = 0;

    #ifdef __SRV_SMS_MULTI_ADDR__
        spdu_data->addr_num = 0;
        spdu_data->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
    #endif /* __SRV_SMS_MULTI_ADDR__ */

    #ifdef __SRV_SMS_SIM_CUST_DATA__
        result = srv_sms_read_write_sim_cust_data(
                    read_sim_cntx->record_index,
                    read_sim_cntx->sim_id,
                    &cust_data,
                    MMI_TRUE);

        /* If read SIM Customized Data Failed, set it to the default value */
        if (result)
        {
        #ifdef __SRV_SMS_SIM_TIMESTAMP__
            spdu_data->timestamp = cust_data.timestamp;
        #endif /* __SRV_SMS_SIM_TIMESTAMP__ */

        #ifdef __SRV_SMS_RESEND_COUNT__
            spdu_data->resend_count = cust_data.timestamp;
        #endif /* __SRV_SMS_RESEND_COUNT__ */

        #ifdef __SRV_SMS_DELIVERY_STATUS__
            spdu_data->tp_st = cust_data.tp_st;
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
        }
    #ifdef __SRV_SMS_RESEND_COUNT__
        else
        {
            spdu_data->resend_count = 0;
        }
    #endif /* __SRV_SMS_RESEND_COUNT__ */
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */
    }
    else
    {
        temp_cb_data.result = MMI_FALSE;
        temp_cb_data.cause = SRV_SMS_CAUSE_SIM_FAILURE;
    }
	}
    temp_cb_data.action = SRV_SMS_ACTION_READ;
    temp_cb_data.action_data = spdu_data;
    temp_cb_data.user_data = read_sim_cntx->user_data;

    callback_func = read_sim_cntx->callback_func;

    if(callback_func == srv_sms_read_pdu_callback)
    {
	read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)read_sim_cntx->user_data;
        
	if(read_pdu_cntx->callback_func == srv_sms_read_msg_callback)
	{
            read_cntx = (srv_sms_read_cntx_struct*)read_pdu_cntx->user_data;
            read_cntx->spdu_list[read_cntx->curr_index] = spdu_data;
	    read_cntx->curr_index ++;
	}

    }
    if(callback_func == srv_sms_read_pdu_callback)
    {
        read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)read_sim_cntx->user_data;
        temp_callback_func = read_pdu_cntx->callback_func;
    }

    if (callback_func != NULL)
    {
        callback_func(&temp_cb_data);
    }
    
    if(callback_func != srv_sms_read_pdu_callback)
    {
	srv_sms_free_pdu_block(spdu_data);
    }
    else
    {
        if(temp_callback_func != srv_sms_read_msg_callback)
	{
            srv_sms_free_pdu_block(spdu_data);
	}
    }
    OslMfree(read_sim_cntx);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_sim_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_write_sim_sms(
                U16 index,
                srv_sms_sim_enum sim_id,
                srv_sms_spdu_struct* spdu_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_write_sim_sms_cntx_struct *write_sim_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_SIM_SMS, index, sim_id);

    write_sim_cntx = OslMalloc(sizeof(srv_sms_write_sim_sms_cntx_struct));

#ifdef __SRV_SMS_SIM_CUST_DATA__
    write_sim_cntx->record_index = index;
#ifdef __SRV_SMS_SIM_TIMESTAMP__
    write_sim_cntx->cust_data.timestamp = spdu_data->timestamp;
#endif /* __SRV_SMS_SIM_TIMESTAMP__ */
#ifdef __SRV_SMS_RESEND_COUNT__
    write_sim_cntx->cust_data.resend_count = spdu_data->resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */
#ifdef __SRV_SMS_DELIVERY_STATUS__
    write_sim_cntx->cust_data.tp_st = spdu_data->tp_st;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
#endif /* __SRV_SMS_SIM_CUST_DATA__ */

    write_sim_cntx->sim_id = sim_id;
    write_sim_cntx->callback_func = callback_func;
    write_sim_cntx->user_data = user_data;

    srv_sim_write_record(
        FILE_SMS_IDX,
        NULL,
        (U16)(index + 1),
        SRV_SMS_MAX_SIM_SPDU_SIZE,
        (U8*)spdu_data,
        (mmi_sim_enum)(sim_id & 0xFF),
        srv_sms_write_sim_sms_callback,
        write_sim_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_sim_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_write_sim_sms_callback(srv_sim_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_write_sim_sms_cntx_struct *write_sim_cntx;
    srv_sms_callback_struct write_cb_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_sim_cntx = (srv_sms_write_sim_sms_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_SIM_SMS_CALLBACK, callback_data->result, callback_data->cause);

    write_cb_data.action = SRV_SMS_ACTION_SAVE;

    if (callback_data->result)
    {
        write_cb_data.result = MMI_TRUE;
        write_cb_data.cause = SRV_SMS_CAUSE_NO_ERROR;

    #ifdef __SRV_SMS_SIM_CUST_DATA__
        srv_sms_read_write_sim_cust_data(
            write_sim_cntx->record_index,
            write_sim_cntx->sim_id,
            &write_sim_cntx->cust_data,
            MMI_FALSE);
    #endif /* __SRV_SMS_SIM_CUST_DATA__ */
    }
    else
    {
        write_cb_data.result = MMI_FALSE;
        write_cb_data.cause = SRV_SMS_CAUSE_SIM_FAILURE;
    }

    write_cb_data.action_data = NULL;
    write_cb_data.user_data = write_sim_cntx->user_data;

    callback_func = write_sim_cntx->callback_func;

    OslMfree(write_sim_cntx);

    if (callback_func != NULL)
    {
        callback_func(&write_cb_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_me_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_me_sms(U16 index, SrvSmsCallbackFunc callback_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = index + 1;
    U8 *spdu_raw_data;
    S16 error_code;
    srv_sms_read_pdu_cntx_struct *read_pdu_cntx;
    srv_sms_read_cntx_struct *read_cntx;
    SrvSmsCallbackFunc temp_callback_func;
	
    MMI_BOOL result = MMI_TRUE;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_ME_SMS, index);

    /* This buffer will be released after the callback_func is 
     * excuted in SRV_SMS_POST_CALLBACK() */
#if 0
/* under construction !*/
#endif	
    spdu_raw_data = srv_sms_alloc_pdu_block();

    if (spdu_raw_data == NULL)
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
    }
    if(result == MMI_TRUE)
    {
    if (ReadRecord(NVRAM_EF_SRV_SMS_PDU_LID, record_index, spdu_raw_data, SRV_SMS_MAX_SPDU_SIZE, &error_code) < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_ME_SMS_1, error_code);

        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ME_FAILURE;
    }
    }
    /* Sync with Write SMS case */
    read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)user_data;
    temp_callback_func = read_pdu_cntx->callback_func;
    if(temp_callback_func == srv_sms_read_msg_callback)
    {
	read_cntx = (srv_sms_read_cntx_struct*)read_pdu_cntx->user_data;
	read_cntx->spdu_list[read_cntx->curr_index] = (srv_sms_spdu_struct*)spdu_raw_data;
	read_cntx->curr_index ++;
    }

    /* Sync with Write SMS case */
    SRV_SMS_POST_CALLBACK(
        SRV_SMS_ACTION_READ,
        result,
        error_cause,
        spdu_raw_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_me_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_write_me_sms(
                U16 index,
                srv_sms_spdu_struct *spdu_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = index + 1;
    S16 error_code;
    MMI_BOOL result = MMI_TRUE;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_ME_SMS, index);

    if (WriteRecord(NVRAM_EF_SRV_SMS_PDU_LID, record_index, spdu_data, SRV_SMS_MAX_SPDU_SIZE, &error_code) < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_ME_SMS_1, error_code);

        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ME_FAILURE;
    }

    /* Use primitive to callback can avoid recursion and avoid below case: 
     *      When Add/Delete/Modify a SMS, we will send refresh primitive to UM.
     *      If we operate a lot of SMS (ex. delete all SMS), and not use primitive
     *      to callback, we will send a lot of refresh primitive to UM in the short time.
     *      The procedure like:
     *      1. Delete SMS A.
     *      2. Delete SMS B.
     *         ...
     *      3. Send refresh primitive A.
     *      4. Send refresh primitive B.
     *         ...
     *      5. Handle refresh primitive A.
     *      6. Handle refresh primitive B.
     *         ...
     *
     *      If use primitive to callback, the procedure like:
     *          1. Delete SMS A.
     *          2. Send refresh primitive A.
     *          3. Delete SMS B.
     *          4. Handle Refresh Primitve A.
     *          5. Send refresh primitive B.
     *          6. Delete SMS C.
     *          7. Handle Refresh Primitve A.
     *             ...
     */
    SRV_SMS_POST_CALLBACK(
        SRV_SMS_ACTION_SAVE,
        result,
        error_cause,
        NULL,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_sim_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_sim_valid(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    return storage_cntx.memory_status.is_sim_valid[index];
}


#ifdef __SRV_SMS_MULTI_ADDR__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_ext_addr_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_ext_addr_num(U16 start_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 next_id = start_addr_id;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next_id < SRV_SMS_MAX_ADDR_ENTRY)
    {
        next_id = srv_sms_addr_list[next_id].next_addr_id;
        count++;
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_ext_addr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_ext_addr_id(U16 msg_id, U16 addr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32 addr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id < SRV_SMS_MAX_SMS_ENTRY);

    addr_id = srv_sms_msg_list[msg_id].start_addr_id;

    while ((addr_id < SRV_SMS_MAX_ADDR_ENTRY) && (i < addr_index))
    {
        addr_id = srv_sms_addr_list[addr_id].next_addr_id;
        i++;
    }

    return addr_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_load_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_load_ext_addr(
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_load_addr_cntx_struct *load_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LOAD_EXT_ADDR);

    load_cntx = (sms_load_addr_cntx_struct*)OslMalloc(sizeof(sms_load_addr_cntx_struct));
    load_cntx->curr_addr_id = 0;
    load_cntx->amount = 0;
    load_cntx->remain = SRV_SMS_MAX_ADDR_ENTRY;
    load_cntx->callback_func = callback_func;
    load_cntx->user_data = user_data;

    srv_sms_load_ext_addr_hdlr(load_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_cause_enum srv_sms_save_ext_addr(
                    srv_sms_addr_struct *addr_list,
                    U16* start_addr_id,
                    U16* total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U16 count = 0;
    U16 start_id = SRV_SMS_INVALID_ADDR_ID;
    srv_sms_addr_struct *addr = addr_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_EXT_ADDR, addr_list);

    while (addr)
    {
        if (!srv_sms_check_ucs2_number((S8*)addr->address))
        {
            error_cause = SRV_SMS_CAUSE_NUMBER_INVALID;
            break;
        }

        if (!IS_VALID_ADDR_STATUS(addr->status))
        {
            error_cause = SRV_SMS_CAUSE_INVALID_TEXT_PARA;
            break;
        }

        count++;
        addr = addr->next;
    }

    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (count < storage_cntx.unused_addr_num)
        {
            if (count > 0)
            {
                U16 curr_id = 0;
                U16 prev_id = SRV_SMS_INVALID_ADDR_ID;

                addr = addr_list;

                while (addr)
                {
                    srv_sms_addr_node_struct new_node;

                    srv_sms_addr_to_addr_node(&new_node, addr);

                    curr_id = srv_sms_get_unused_addr_between(curr_id, (SRV_SMS_MAX_ADDR_ENTRY - 1));

                    MMI_ASSERT(curr_id < SRV_SMS_MAX_ADDR_ENTRY);

                    srv_sms_add_addr_node(curr_id, &new_node);

                    if (prev_id != SRV_SMS_INVALID_ADDR_ID)
                    {
                        srv_sms_addr_list[prev_id].next_addr_id = curr_id;
                    }
                    prev_id = curr_id;

                    if (start_id == SRV_SMS_INVALID_ADDR_ID)
                    {
                        start_id = curr_id;
                    }

                    addr = addr->next;
                }

                srv_sms_update_ext_addr_record(start_id);
            }
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        }
    }

    if (start_addr_id)
    {
        *start_addr_id = start_id;
    }

    if (total_num)
    {
        *total_num = count;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_EXT_ADDR_1, error_cause, start_id, count);

    return error_cause;
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_save_tcard_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_cause_enum srv_sms_save_tcard_ext_addr(
                    srv_sms_addr_struct *addr_list,
                    U16* start_addr_id,
                    U16* total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U16 count = 0;
    U16 start_id = SRV_SMS_INVALID_ADDR_ID;
    srv_sms_addr_struct *addr = addr_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_EXT_ADDR, addr_list);

    while (addr)
    {
        if (!srv_sms_check_ucs2_number((S8*)addr->address))
        {
            error_cause = SRV_SMS_CAUSE_NUMBER_INVALID;
            break;
        }

        if (!IS_VALID_ADDR_STATUS(addr->status))
        {
            error_cause = SRV_SMS_CAUSE_INVALID_TEXT_PARA;
            break;
        }

        count++;
        addr = addr->next;
    }
    if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        if (count < storage_cntx.unused_tcard_addr_num)
        {
            if (count > 0)
            {
                U16 curr_id = SRV_SMS_MAX_ADDR_ENTRY;
                U16 prev_id = SRV_SMS_INVALID_ADDR_ID;

                addr = addr_list;

                while (addr)
                {
                    srv_sms_tcard_addr_node_struct new_node;
                    srv_sms_tcard_addr_node_struct tcard_new_node;
                    srv_sms_addr_to_tcard_addr_node(&new_node, addr);
                    curr_id = srv_sms_get_unused_addr_between(curr_id, (SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_ADDR_ENTRY));

                    MMI_ASSERT(curr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);

                    srv_sms_add_tcard_addr_node(curr_id, &new_node);

                    if (prev_id != SRV_SMS_INVALID_ADDR_ID)
                    {
                        srv_sms_tcard_addr_list[prev_id - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id = curr_id;
                    }
                    prev_id = curr_id;

                    if (start_id == SRV_SMS_INVALID_ADDR_ID)
                    {
                        start_id = curr_id;
                    }

                    addr = addr->next;
                }

                //srv_sms_update_ext_addr_record(start_id);
            }
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        }
    }

    if (start_addr_id)
    {
        *start_addr_id = start_id;
    }

    if (total_num)
    {
        *total_num = count;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SAVE_EXT_ADDR_1, error_cause, start_id, count);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_tcard_ext_addr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_tcard_ext_addr_id(U16 msg_id, U16 addr_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U32 addr_id;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_id >= SRV_SMS_MAX_MSG_NUM);
    tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
    addr_id = tcard_msg_node->start_addr_id;

    while ((addr_id < (SRV_SMS_MAX_TCARD_ADDR_ENTRY + SRV_SMS_MAX_ADDR_ENTRY)) && (i < addr_index))
    {
        addr_id = srv_sms_tcard_addr_list[addr_id - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id;
        i++;
    }

    return addr_id;
}


U16 srv_sms_get_tcard_ext_addr_num(U16 start_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 next_id = start_addr_id - SRV_SMS_MAX_ADDR_ENTRY;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (next_id < SRV_SMS_MAX_TCARD_ADDR_ENTRY)
    {
        next_id = srv_sms_tcard_addr_list[next_id - SRV_SMS_MAX_ADDR_ENTRY].next_addr_id;
        count++;
    }

    return count;
}

#endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_duplicate_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_cause_enum srv_sms_duplicate_ext_addr(
                    U16 src_addr_id,
                    U16* dest_addr_id,
                    U16* total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U16 start_id = SRV_SMS_INVALID_ADDR_ID;
    U16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DUPLICATE_EXT_ADDR, src_addr_id);

    count = srv_sms_get_ext_addr_num(src_addr_id);

    if (count < storage_cntx.unused_addr_num)
    {
        if (count > 0)
        {
            U16 prev_id = SRV_SMS_INVALID_ADDR_ID;
            U32 src_next_id = src_addr_id;

            while (src_next_id < SRV_SMS_MAX_ADDR_ENTRY)
            {
                U16 dest_id = 0;
                srv_sms_addr_node_struct *src_node;

                src_node = &srv_sms_addr_list[src_next_id];

                dest_id = srv_sms_get_unused_addr_between(dest_id, (SRV_SMS_MAX_ADDR_ENTRY - 1));

                MMI_ASSERT(dest_id < SRV_SMS_MAX_ADDR_ENTRY);

                srv_sms_add_addr_node(dest_id, src_node);

                if (prev_id != SRV_SMS_INVALID_ADDR_ID)
                {
                    srv_sms_addr_list[prev_id].next_addr_id = dest_id;
                }
                prev_id = dest_id;

                if (start_id == SRV_SMS_INVALID_ADDR_ID)
                {
                    start_id = dest_id;
                }

                src_next_id = src_node->next_addr_id;
            }

            srv_sms_update_ext_addr_record(start_id);
        }
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
    }

    if (dest_addr_id)
    {
        *dest_addr_id = start_id;
    }

    if (total_num)
    {
        *total_num = count;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DUPLICATE_EXT_ADDR_1, error_cause, start_id, count);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_del_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_del_ext_addr(U16 start_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DEL_EXT_ADDR, start_addr_id);

    if (start_addr_id < SRV_SMS_MAX_ADDR_ENTRY)
    {
        U32 next_id = start_addr_id;

        do
        {
            srv_sms_addr_node_struct *addr_node;
            U16 del_id = next_id;

            addr_node = &srv_sms_addr_list[next_id];
            next_id = addr_node->next_addr_id;

            srv_sms_del_addr_node(del_id);
            srv_sms_write_addr_record(del_id, addr_node);
        } while (next_id < SRV_SMS_MAX_ADDR_ENTRY);
    }
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_del_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_del_ext_tcard_addr(U16 start_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 next_id = 0;
	U32 end_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DEL_EXT_ADDR, start_addr_id);
    ASSERT(start_addr_id >= SRV_SMS_MAX_ADDR_ENTRY && start_addr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);
    start_addr_id = start_addr_id - SRV_SMS_MAX_ADDR_ENTRY;
	if (start_addr_id < SRV_SMS_MAX_TCARD_ADDR_ENTRY)
    {
        next_id = start_addr_id;

        do
        {
            srv_sms_tcard_addr_node_struct *addr_node;
            U16 del_id = next_id;
            end_id = next_id;
            addr_node = &srv_sms_tcard_addr_list[next_id ];
            next_id = addr_node->next_addr_id - SRV_SMS_MAX_ADDR_ENTRY;

            srv_sms_del_tcard_addr_node(del_id);
            //srv_sms_write_addr_record(del_id, addr_node);
        } while (next_id < SRV_SMS_MAX_TCARD_ADDR_ENTRY);
    }
    return end_id;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_ext_addr_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_update_ext_addr_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 used_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_EXT_ADDR_INFO);

    for (i = 0; i < (U32)(storage_cntx.used_msg_tail_id + 1); i++)
    {
        MMI_BOOL is_invalid = MMI_TRUE;
        srv_sms_msg_node_struct *msg_node = &srv_sms_msg_list[i];

        if ((msg_node->status != SRV_SMS_STATUS_NONE) &&
            (msg_node->storage_type == SRV_SMS_STORAGE_ME) &&
            (msg_node->ext_addr_num > 0))
        {
            U32 next_addr_id = msg_node->start_addr_id;
            U16 addr_count = 0;

            while ((next_addr_id < SRV_SMS_MAX_ADDR_ENTRY) && 
                   (!(srv_sms_addr_list[next_addr_id].status & ADDR_STATUS_USED_FLAG)))
            {
                /* If the next_page_id is used, it means there are more than
                 * one msg pointed to the same address */
                addr_count++;
                next_addr_id = srv_sms_addr_list[next_addr_id].next_addr_id;
            }

            if ((addr_count == msg_node->ext_addr_num) &&
                (next_addr_id == SRV_SMS_INVALID_ADDR_ID))
            {
                is_invalid = MMI_FALSE;

                next_addr_id = msg_node->start_addr_id;

                do
                {
                    srv_sms_addr_list[next_addr_id].status |= ADDR_STATUS_USED_FLAG;
                    next_addr_id = srv_sms_addr_list[next_addr_id].next_addr_id;
                } while (next_addr_id < SRV_SMS_MAX_ADDR_ENTRY);
            }
        }

        if (is_invalid)
        {
            msg_node->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
            msg_node->ext_addr_num = 0;
        }
    }

    /* Count the unused Address number */
    for (i = 0; i < SRV_SMS_MAX_ADDR_ENTRY; i++)
    {
        if (srv_sms_addr_list[i].status & ADDR_STATUS_USED_FLAG)
        {
            srv_sms_addr_list[i].status &= (~ADDR_STATUS_USED_FLAG);
            used_count++;
        }
        else
        {
            srv_sms_addr_list[i].status = SRV_SMS_STATUS_NONE;
            srv_sms_addr_list[i].next_addr_id = SRV_SMS_INVALID_ADDR_ID;
        }
    }

    storage_cntx.unused_addr_num = SRV_SMS_MAX_ADDR_ENTRY - used_count;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_EXT_ADDR_INFO_1, used_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_load_ext_addr_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_load_ext_addr_hdlr(sms_load_addr_cntx_struct *load_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LOAD_EXT_ADDR_HDLR, load_cntx->remain);

    if (load_cntx->remain > 0)
    {
        if (load_cntx->remain > SMS_MULTI_ADDR_MAX_READ_RECORDS)
        {
            load_cntx->amount = SMS_MULTI_ADDR_MAX_READ_RECORDS;
        }
        else
        {
            load_cntx->amount = load_cntx->remain;
        }

        srv_sms_read_multi_addr_record(
            load_cntx->curr_addr_id,
            load_cntx->amount,
            srv_sms_load_ext_addr_callback,
            load_cntx);
    }
    else
    {
        void * user_data = load_cntx->user_data;
        SrvSmsCallbackFunc callback_func = load_cntx->callback_func;

        OslMfree(load_cntx);
    
        srv_sms_callback(
            SRV_SMS_ACTION_READ,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_load_ext_addr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_load_ext_addr_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_load_addr_cntx_struct *load_cntx;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LOAD_EXT_ADDR_CALLBACK, callback_data->result);

    load_cntx = (sms_load_addr_cntx_struct*)callback_data->user_data;

    if (callback_data->result)
    {
        srv_sms_addr_record_struct *addr_record = (srv_sms_addr_record_struct*)callback_data->action_data;
        srv_sms_addr_node_struct *addr_node;

        MMI_ASSERT(load_cntx->curr_addr_id < SRV_SMS_MAX_ADDR_ENTRY);

        addr_node = &srv_sms_addr_list[load_cntx->curr_addr_id];

        for (i = 0; i < load_cntx->amount; i++)
        {
            if ((IS_VALID_ADDR_STATUS(addr_record->status)) &&
                ((addr_record->next_addr_id < SRV_SMS_MAX_ADDR_ENTRY) ||
                 (addr_record->next_addr_id == SRV_SMS_INVALID_ADDR_ID)))
            {
                srv_sms_addr_record_to_addr_node(addr_node, addr_record);
            }
            addr_record++;
            addr_node++;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LOAD_EXT_ADDR_CALLBACK_1, load_cntx->curr_addr_id, load_cntx->amount);

    load_cntx->curr_addr_id += load_cntx->amount;
    load_cntx->remain -= load_cntx->amount;

    srv_sms_load_ext_addr_hdlr(load_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_multi_addr_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_read_multi_addr_record(
                U16 start_addr_id,
                U16 record_amount,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_index = start_addr_id + 1;
    S16 error_code;
    S32 read_result;
    U32 record_buff_size;
    void *record_buff;
    MMI_BOOL result;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MULTI_ADDR_RECORD, start_addr_id, record_amount);

    record_buff_size = sizeof(srv_sms_addr_record_struct) * record_amount;
    record_buff = OslMalloc(record_buff_size);

    read_result = ReadMultiRecord(
                        NVRAM_EF_SRV_SMS_ADDR_LID,
                        start_index,
                        record_buff,
                        record_buff_size,
                        record_amount,
                        &error_code);

    if (read_result < 0)
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ME_FAILURE;
    }
    else
    {
        result = MMI_TRUE;
        error_cause = SRV_SMS_CAUSE_NO_ERROR;
    }

    /* the record buffer will be released in the async callback function */
    SRV_SMS_POST_CALLBACK(
        SRV_SMS_ACTION_READ,
        result,
        error_cause,
        record_buff,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_addr_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_write_addr_record(U16 addr_id, srv_sms_addr_node_struct *addr_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = addr_id + 1;
    S16 error_code;
    srv_sms_addr_record_struct addr_record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_ADDR_RECORD, addr_id);

    srv_sms_addr_node_to_addr_record(&addr_record, addr_node);

    WriteRecord(
        NVRAM_EF_SRV_SMS_ADDR_LID,
        record_index,
        &addr_record,
        sizeof(srv_sms_addr_record_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_ext_addr_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_update_ext_addr_record(U16 start_addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 next_id = start_addr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UPDATE_EXT_ADDR_RECORD, start_addr_id);

    while (next_id < SRV_SMS_MAX_ADDR_ENTRY)
    {
        srv_sms_addr_node_struct *addr_node = &srv_sms_addr_list[next_id];

        srv_sms_write_addr_record(next_id, addr_node);

        next_id = addr_node->next_addr_id;
    }
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_add_tcard_addr_node(U16 addr_id, srv_sms_tcard_addr_node_struct* addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_addr_node_struct *addr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ADDR_NODE, addr_id);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY + SRV_SMS_MAX_TCARD_ADDR_ENTRY);

    addr_node = &srv_sms_tcard_addr_list[addr_id - SRV_SMS_MAX_ADDR_ENTRY];

    /* If the original node is unused, increment the count */
    if (addr_node->status == SRV_SMS_STATUS_NONE)
    {
        storage_cntx.unused_tcard_addr_num--;
    }

    memset(addr_node, 0, sizeof(srv_sms_tcard_addr_node_struct));
    addr_node->status = addr->status;
    strcpy(addr_node->address, addr->address);
    addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;
}
#endif/*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/ 
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_add_addr_node(U16 addr_id, srv_sms_addr_node_struct* addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_addr_node_struct *addr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ADD_ADDR_NODE, addr_id);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY);

    addr_node = &srv_sms_addr_list[addr_id];

    /* If the original node is unused, increment the count */
    if (addr_node->status == SRV_SMS_STATUS_NONE)
    {
        storage_cntx.unused_addr_num--;
    }

    memset(addr_node, 0, sizeof(srv_sms_addr_node_struct));
    addr_node->status = addr->status;
    strcpy(addr_node->address, addr->address);
    addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_del_addr_node(U16 addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_addr_node_struct *addr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DEL_ADDR_NODE, addr_id);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_ADDR_ENTRY);

    addr_node = &srv_sms_addr_list[addr_id];

    if (addr_node->status != SRV_SMS_STATUS_NONE)
    {
        addr_node->status = SRV_SMS_STATUS_NONE;
        addr_node->address[0] = '\0';
        addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;

        storage_cntx.unused_addr_num--;
    }
}
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_del_tcard_addr_node(U16 addr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_tcard_addr_node_struct *addr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DEL_ADDR_NODE, addr_id);

    MMI_ASSERT(addr_id < SRV_SMS_MAX_TCARD_ADDR_ENTRY);

    addr_node = &srv_sms_tcard_addr_list[addr_id];

    if (addr_node->status != SRV_SMS_STATUS_NONE)
    {
        addr_node->status = SRV_SMS_STATUS_NONE;
        addr_node->address[0] = '\0';
        addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;

        storage_cntx.unused_tcard_addr_num--;
    }
}


static void srv_sms_addr_to_tcard_addr_node(
                srv_sms_tcard_addr_node_struct *addr_node,
                srv_sms_addr_struct* addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_node->status = (U8)addr->status;
    mmi_wcs_to_asc((CHAR*)addr_node->address, addr->address);
    addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_addr_to_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_addr_to_addr_node(
                srv_sms_addr_node_struct *addr_node,
                srv_sms_addr_struct* addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_node->status = (U8)addr->status;
    mmi_wcs_to_asc((CHAR*)addr_node->address, addr->address);
    addr_node->next_addr_id = SRV_SMS_INVALID_ADDR_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_addr_record_to_addr_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_addr_record_to_addr_node(
                srv_sms_addr_node_struct* addr_node,
                srv_sms_addr_record_struct *addr_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(addr_node, addr_record, sizeof(srv_sms_addr_record_struct));
    addr_node->address[SRV_SMS_MAX_ADDR_LEN] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_addr_node_to_addr_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_addr_node_to_addr_record(
                srv_sms_addr_record_struct *addr_record,
                srv_sms_addr_node_struct* addr_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(addr_record, addr_node, sizeof(srv_sms_addr_record_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_addr_between
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_get_unused_addr_between(U16 start_index, U16 end_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_index = SRV_SMS_INVALID_ADDR_ID;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_ADDR_BETWEEN, start_index, end_index);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__


    if(start_index >= SRV_SMS_MAX_ADDR_ENTRY)
    {
         for (i = start_index; i < (end_index + 1); i++)
        {
            srv_sms_tcard_addr_node_struct *tcard_curr_node = &srv_sms_tcard_addr_list[i - SRV_SMS_MAX_ADDR_ENTRY];
            if (tcard_curr_node->status == SRV_SMS_STATUS_NONE)
            {
                unused_index = i;
                break;
            }
        }
    }
    else
    {
        for (i = start_index; i < (end_index + 1); i++)
        {
            srv_sms_addr_node_struct *curr_node = &srv_sms_addr_list[i];

            /* If status is NONE, the node is unused */
            if (curr_node->status == SRV_SMS_STATUS_NONE)
            {
                unused_index = i;
                break;
            }
        }
    }
#else
    MMI_ASSERT((start_index < SRV_SMS_MAX_ADDR_ENTRY) && (end_index < SRV_SMS_MAX_ADDR_ENTRY));
    
    for (i = start_index; i < (U32)(end_index + 1); i++)
    {
        srv_sms_addr_node_struct *curr_node = &srv_sms_addr_list[i];

        /* If status is NONE, the node is unused */
        if (curr_node->status == SRV_SMS_STATUS_NONE)
        {
            unused_index = i;
            break;
        }
    }

#endif
    

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_UNUSED_ADDR_BETWEEN_1, unused_index);

    return unused_index;
}


#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_search_ext_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_search_ext_addr(U16* seg_index, char* number, U8 msg_ref, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_EXT_ADDR, msg_ref, sim_id);

    for (i = 0; i < (U32)(storage_cntx.used_msg_tail_id + 1); i++)
    {
        srv_sms_msg_node_struct *msg_node = &srv_sms_msg_list[i];

        if ((msg_node->status != SRV_SMS_STATUS_NONE) &&
            (msg_node->storage_type == SRV_SMS_STORAGE_ME) &&
            (msg_node->ext_addr_num > 0)
        #ifdef __SRV_SMS_MULTI_SIM__
            && (msg_node->sim_id == sim_id)
        #endif /* __SRV_SMS_MULTI_SIM__ */
           )
        {
            U32 next_addr_id = msg_node->start_addr_id;

            while (next_addr_id < SRV_SMS_MAX_ADDR_ENTRY)
            {
                srv_sms_addr_node_struct *addr_node = &srv_sms_addr_list[next_addr_id];
            
                if (srv_sms_cmp_asc_num(number, addr_node->address))
                {
                    U32 j;
                
                    for (j = 0; i < (U32)addr_node->total_seg; j++)
                    {
                        if (addr_node->msg_ref[j] == msg_ref)
                        {
                            *seg_index = j;

                            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEARCH_EXT_ADDR_1, next_addr_id, j);

                            return next_addr_id;
                        }
                    }
                }

                next_addr_id = addr_node->next_addr_id;
            }
        }
    }

    return SRV_SMS_INVALID_ADDR_ID;
}
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */

#endif /* __SRV_SMS_MULTI_ADDR__ */

#endif /* __MOD_SMSAL__ */
