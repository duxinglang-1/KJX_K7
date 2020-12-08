/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * jbt_gap.c
 *
 * Project:
 * --------
 * MAUI
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
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBT_SDPDB_C
#define _JBT_SDPDB_C

#ifdef __SUPPORT_JBT__

/***************************************************************************** 
* Include
*****************************************************************************/
/* basic system service headers */
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"     /* type of system module components */
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "uart_sw.h"
#include "bluetooth_struct.h"
#include "bluetooth_bm_struct.h"
#include "mmiapi_bt_struct.h"
#include "j2me_trace.h"
#include "jvm_interface.h"
#include "jam_internal.h"
#include "jbt_interface.h"
#include "jbt_internal.h"

JBT_SDPDB_CNTX jbt_sdpdb_context;


/*****************************************************************************
 * FUNCTION
 *  jbt_sdpdb_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_sdpdb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_SDPDB_INIT);
    kal_mem_set((kal_uint8*) & jbt_sdpdb_context, 0, sizeof(jbt_sdpdb_context));
}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdpdb_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_sdpdb_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_SDPDB_NO; i++)
    {
        jbt_sdpdb_release_entry(i);
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdpdb_get_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_sdpdb_get_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_SDPDB_NO; i++)
    {
        if (jbt_sdpdb_context.sdp_record[i].used == 0)
        {
            kal_trace(TRACE_JBT_GROUP, JBT_SDPDB_INDEXxD_IS_FREE, i);
            jbt_sdpdb_context.sdp_record[i].used = 1;
            if (jbt_sdpdb_context.sdp_record[i].bt_record_buffer != 0)
            {
                jbt_free_record((kal_uint8*) jbt_sdpdb_context.sdp_record[i].bt_record_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free((kal_uint8*) jbt_sdpdb_context.sdp_record[i].bt_record_buffer);
#else
                kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) jbt_sdpdb_context.sdp_record[i].bt_record_buffer); 
#endif
            }
            jbt_sdpdb_context.sdp_record[i].bt_record_buffer = 0;
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdpdb_release_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  db_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_sdpdb_release_entry(kal_uint8 db_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SDPDB_RELEASE_ENTRY, db_index);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_SDPDB_CONTEXTSDP_RECORDDB_INDEXUSED,
        jbt_sdpdb_context.sdp_record[db_index].used);
    if (jbt_sdpdb_context.sdp_record[db_index].used == 1)
    {
        jbt_sdpdb_context.sdp_record[db_index].used = 0;
        if (jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer != NULL)
        {
            jbt_free_record((kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer);
#endif
        }
        jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer = NULL;

        if (jbt_sdpdb_context.sdp_record[db_index].bt_raw_record != NULL)
        {
            jbt_free_record((kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#endif
        }
        jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdpdb_find_entry_by_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_sdpdb_find_entry_by_handle(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SDPDB_FIND_ENTRY_BY_HANDLE_x08X, handle);

    for (i = 0; i < JBT_MAX_SDPDB_NO; i++)
    {
        kal_trace(
            TRACE_JBT_GROUP,
            JBT_INDEXx02X_USEDx02XHANDLEx08X,
            i,
            jbt_sdpdb_context.sdp_record[i].used,
            jbt_sdpdb_context.sdp_record[i].handle);
        if ((jbt_sdpdb_context.sdp_record[i].used == 1) && (jbt_sdpdb_context.sdp_record[i].handle == handle))
        {
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_record_handle_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_get_record_handle_cmd(kal_int32 transaction_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    kal_uint8 db_index = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_RECORD_HANDLE_CMD);

#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
#endif /*__MVM__*/

    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_SDPDB_CONTEXTJBT_GET_RECORD_HANDLEOPERATION_STATEx02X,
        jbt_sdpdb_context.jbt_get_record_handle.operation_state);

    if (jbt_sdpdb_context.jbt_get_record_handle.operation_state == JBT_OPERATION_STATE_NONE)
    {
        db_index = jbt_sdpdb_get_entry();
        kal_trace(TRACE_JBT_GROUP, JBT_DB_INDEXx02X, db_index);

        if (db_index != JBT_MAX_SDPDB_NO)
        {
            jbt_sdpdb_context.jbt_get_record_handle.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_sdpdb_context.jbt_get_record_handle.transaction_id = transaction_id;
            jbt_sdpdb_context.jbt_get_record_handle.used_index = db_index;
            jbt_send_msg(MSG_ID_BT_APP_SDPDB_GET_HANDLE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

            result = JBT_CMD_SUCCESS;
        }
        else
        {
            result = JBT_CMD_FAILED;
        }
    }
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_register_record_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  handle              [IN]        
 *  record              [IN]        
 *  rec_size            [IN]        
 *  type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_register_record_cmd(
            kal_int32 transaction_id,
            kal_uint32 handle,
            kal_uint8 *record,
            kal_uint16 rec_size,
            kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    bt_app_sdpdb_register_req_struct *msg;
    kal_uint8 db_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_REGISTER_RECORD_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_REGISTER_RECORD_CMD_HANDLEx08X, handle);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_REGISTER_RECORD_CMD_RECORD_SIZEx08X, rec_size);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_REGISTER_RECORD_CMD_RECORD_TYPEx08X, type);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_REGISTER_RECORD_CMD_RECORD_TRANSACTION_IDx08X, transaction_id);

#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
#endif /*__MVM__*/


    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_SDPDB_CONTEXTJBT_REGISTER_RECORDOPERATION_STATE_x02X,
        jbt_sdpdb_context.jbt_register_record.operation_state);

    if (jbt_sdpdb_context.jbt_register_record.operation_state == JBT_OPERATION_STATE_NONE)
    {
        if (rec_size <= 0x200)
        {
            /* Using the service_record handle obtained from the result of get_record_handle command */
            db_index = jbt_sdpdb_find_entry_by_handle(handle);
            kal_trace(TRACE_JBT_GROUP, JBT_DB_INDEXx02X, db_index);

            if (db_index != JBT_MAX_SDPDB_NO)
            {
                msg =
                    (bt_app_sdpdb_register_req_struct*) construct_local_para(
                                                            sizeof(bt_app_sdpdb_register_req_struct),
                                                            TD_CTRL);

                msg->handle = handle;
                jbt_sdpdb_context.jbt_register_record.operation_state = JBT_OPERATION_STATE_ONGOING;
                jbt_sdpdb_context.jbt_register_record.transaction_id = transaction_id;
                jbt_sdpdb_context.jbt_register_record.used_index = db_index;
                if (type == 0x00)
                {
                    kal_uint8 record_buf_block_inx = 0, raw_record_block_inx = 0;
                    
                    record_buf_block_inx = jbt_malloc_block(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);

#ifndef JBT_SUPPORT_ADM_MEM
                    jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer =
                        (kal_uint8*) jvm_malloc(JBT_MAX_BTSTACK_USED_BUFFER_SIZE);    
#else
                    jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer =
                        (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),JBT_MAX_BTSTACK_USED_BUFFER_SIZE); 
#endif  
                    
                    if (jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer == NULL)
                    {
                        /* Failed of jvm_malloc() */
                        jbt_free_block(record_buf_block_inx);
                        ASSERT(0);
                    }
                    else
                    {
                        jbt_malloc_record(record_buf_block_inx, jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer, JBT_MAX_BTSTACK_USED_BUFFER_SIZE);
                    }

                    raw_record_block_inx = jbt_malloc_block(rec_size);
#ifndef JBT_SUPPORT_ADM_MEM
                    jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = (kal_uint8*) jvm_malloc(rec_size);
#else
                    jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),rec_size);
#endif
                    if (jbt_sdpdb_context.sdp_record[db_index].bt_raw_record == NULL)
                    {
                        /* Failed of jvm_malloc() */
                        jbt_free_block(raw_record_block_inx);
                        ASSERT(0);
                    }
                    else
                    {
                        jbt_malloc_record(raw_record_block_inx, jbt_sdpdb_context.sdp_record[db_index].bt_raw_record, rec_size);
                    }
                    /* msg->record_raw points to a allocated memory block */
                    msg->record_raw = jbt_sdpdb_context.sdp_record[db_index].bt_raw_record;
                    memcpy(msg->record_raw, record, rec_size);
                    msg->type = BT_APP_REGISTER_RECORD;
                }
                else
                {
                    kal_uint8 block_inx = 0;
                    msg->type = BT_APP_UPDATE_RECORD;
                    /* Using newer raw record to update: delete old space and its corresponding data, then allocatee newest space */
                    if (jbt_sdpdb_context.sdp_record[db_index].bt_raw_record != NULL)
                    {
                        jbt_free_record(jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#ifndef JBT_SUPPORT_ADM_MEM
                        jvm_free(jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#else
                        kal_adm_free(jbt_get_mem_pool_id(),jbt_sdpdb_context.sdp_record[db_index].bt_raw_record);
#endif
                        jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = NULL;
                    }

                    block_inx = jbt_malloc_block(rec_size);
#ifndef JBT_SUPPORT_ADM_MEM
                    jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = (kal_uint8*) jvm_malloc(rec_size);
#else
                    jbt_sdpdb_context.sdp_record[db_index].bt_raw_record = (kal_uint8*) kal_adm_alloc(jbt_get_mem_pool_id(),rec_size);
#endif
                    if (jbt_sdpdb_context.sdp_record[db_index].bt_raw_record == NULL)
                    {   
                        /* Failed of jvm_malloc() */
                        jbt_free_block(block_inx);
                        ASSERT(0);
                    }
                    else
                    {
                        jbt_malloc_record(block_inx, jbt_sdpdb_context.sdp_record[db_index].bt_raw_record, rec_size);
                    }
                    /* msg->record_raw points to a allocated memory block */
                    msg->record_raw = jbt_sdpdb_context.sdp_record[db_index].bt_raw_record;
                    memcpy(msg->record_raw, record, rec_size);
                }

                msg->record_raw_length = rec_size;
                msg->attribs_buffer = (kal_uint8*) jbt_sdpdb_context.sdp_record[db_index].bt_record_buffer;
                msg->attribs_buffer_size = JBT_MAX_BTSTACK_USED_BUFFER_SIZE;
                jbt_send_msg(
                    MSG_ID_BT_APP_SDPDB_REGISTER_REQ,
                    MOD_JASYN,
                    MOD_BT,
                    BT_APP_SAP,
                    (local_para_struct*) msg,
                    NULL);

                result = JBT_CMD_SUCCESS;
            }
            else
            {
                result = JBT_CMD_WRONG_STATE;
            }
        }
        else
        {
            result = JBT_CMD_SIZE_TOO_LARGE;
        }
    }
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_deregister_record_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  handle              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_deregister_record_cmd(kal_int32 transaction_id, kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    bt_app_sdpdb_deregister_req_struct *msg;
    kal_uint8 db_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_DEREGISTER_RECORD_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEREGISTER_RECORD_CMD_HANDLEx08X, handle);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEREGISTER_RECORD_CMD_RECORD_TRANSACTION_IDx08X, transaction_id);

#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
#endif /*__MVM__*/


    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_SDPDB_CONTEXTJBT_DEREGISTER_RECORDOPERATION_STATEx08X,
        jbt_sdpdb_context.jbt_deregister_record.operation_state);

    if (jbt_sdpdb_context.jbt_deregister_record.operation_state == JBT_OPERATION_STATE_NONE)
    {
        db_index = jbt_sdpdb_find_entry_by_handle(handle);
        if (db_index != JBT_MAX_SDPDB_NO)
        {

            msg =
                (bt_app_sdpdb_deregister_req_struct*) construct_local_para(
                                                        sizeof(bt_app_sdpdb_deregister_req_struct),
                                                        TD_CTRL);

            msg->handle = handle;
            jbt_sdpdb_context.jbt_deregister_record.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_sdpdb_context.jbt_deregister_record.transaction_id = transaction_id;
            jbt_sdpdb_context.jbt_deregister_record.used_index = db_index;

            jbt_send_msg(
                MSG_ID_BT_APP_SDPDB_DEREGISTER_REQ,
                MOD_JASYN,
                MOD_BT,
                BT_APP_SAP,
                (local_para_struct*) msg,
                NULL);

            result = JBT_CMD_SUCCESS;
        }
        else
        {
            result = JBT_CMD_WRONG_STATE;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_record_handle_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_record_handle_result(bt_app_sdpdb_get_handle_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_record_handle_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    transaction_id = jbt_sdpdb_context.jbt_get_record_handle.transaction_id;
    jbt_sdpdb_context.jbt_get_record_handle.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_sdpdb_context.jbt_get_record_handle.transaction_id = 0;

    /* Add by mtk01411: 2007-1122 */
    if (msg->result == 0)        
    {
        /* result is success, then keeps the service_record handle with its corresponding db_inx */
        jbt_sdpdb_context.sdp_record[jbt_sdpdb_context.jbt_get_record_handle.used_index].handle = msg->handle;
    }
    else
    {
        jbt_sdpdb_context.jbt_get_record_handle.used_index = 0;
    }

    parms.result = msg->result;
    parms.record_handle = msg->handle;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_RECORD_HANDLE_RESULT_x02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_RECORD_HANDLE_RESULT_x08X, parms.record_handle);

    jbt_event_callback(JBT_OPCODE_GET_RECORD_HANDLE, transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_register_record_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_register_record_result(bt_app_sdpdb_register_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_register_record_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_REGISTER_RECORD_RESULT);

    transaction_id = jbt_sdpdb_context.jbt_register_record.transaction_id;
    jbt_sdpdb_context.jbt_register_record.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_sdpdb_context.jbt_register_record.transaction_id = 0;
    parms.result = msg->result;
    parms.record_handle = msg->handle;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_REGISTER_RECORD_RESULT_x02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_REGISTER_RECORD_RESULT_x08X, parms.record_handle);
    jbt_event_callback(JBT_OPCODE_REGISTER_RECORD_RESULT, transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_deregister_record_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_deregister_record_result(bt_app_sdpdb_deregister_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_deregister_record_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    transaction_id = jbt_sdpdb_context.jbt_deregister_record.transaction_id;
    jbt_sdpdb_context.jbt_deregister_record.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_sdpdb_context.jbt_deregister_record.transaction_id = 0;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_HANDLE_DEREGISTER_RECORD_RESULTx02X,
        jbt_sdpdb_context.jbt_deregister_record.used_index);

    jbt_sdpdb_release_entry(jbt_sdpdb_context.jbt_deregister_record.used_index);
    /* Add this bt mtk01411: 2007-1123 */
    jbt_sdpdb_context.jbt_deregister_record.used_index = 0;
    parms.result = msg->result;
    parms.record_handle = msg->handle;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_DEREGISTER_RECORD_RESULT_x02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_DEREGISTER_RECORD_RESULT_x08X, parms.record_handle);

    jbt_event_callback(JBT_OPCODE_DEREGISTER_RECORD_RESULT, transaction_id, &parms);
}
#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_SDPDB_C */ 

