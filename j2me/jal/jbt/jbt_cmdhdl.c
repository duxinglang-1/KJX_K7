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
 * jbt_main.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _JBT_CMDHDL_C
#define _JBT_CMDHDL_C

#ifdef __SUPPORT_JBT__

/***************************************************************************** 
* Include
*****************************************************************************/
/* basic system service headers */
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "stack_ltlcom.h"
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
#include "jbt_interface.h"
#include "jvm_interface.h"
#include "jbt_internal.h"

JBT_CMD_CNTX jbt_cmd_queue_context;
static kal_semid jbt_cmd_sem;
static kal_semid jbt_cmd_process_sem;
static kal_semid jbt_cmd_kick_sem;


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_take_sem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_list_take_sem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(jbt_cmd_sem, KAL_INFINITE_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_give_sem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_list_give_sem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_give_sem(jbt_cmd_sem);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_list_init(JBT_cmd_node *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_cmd_list_take_sem();
    list->flink = list;
    list->blink = list;
    jbt_cmd_list_give_sem();
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_list_reset(JBT_cmd_node *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->flink = list;
    list->blink = list;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_check_completed
 * DESCRIPTION
 *  This function is used to check if this list is a circular list or not 
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  TRUE: This list is a completed and circular list
 *****************************************************************************/
kal_bool jbt_cmd_list_check_completed(JBT_cmd_node *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *temp;
    kal_bool status = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_cmd_list_take_sem();
    ASSERT(list != 0);
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
#endif
    if (list->flink == list && list->blink == list)
    {
        /* In this case: this list is a circular list with only single node */
        status = KAL_TRUE;
        goto jbt_return;
    }

    temp = list;
    for (temp = temp->flink; temp != list; temp = temp->flink)
    {
        ASSERT(temp->flink != 0);
        ASSERT(temp->blink != 0);
        if (temp->flink->blink != temp)
        {
            status = KAL_FALSE;
            break;
        }
        if (temp->blink->flink != temp)
        {
            status = KAL_FALSE;
            break;
        }
        status = KAL_TRUE;
    }
  jbt_return:
    jbt_cmd_list_give_sem();
    return (status);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_insert_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [IN]        
 *  new_node        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_list_insert_tail(JBT_cmd_node *list, JBT_cmd_node *new_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_cmd_list_check_completed(list) == KAL_FALSE)
    {
        ASSERT(0);
    }
    jbt_cmd_list_take_sem();
    new_node->flink = list;
    new_node->blink = list->blink;
    list->blink->flink = new_node;
    list->blink = new_node;
    jbt_cmd_list_give_sem();

}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_remove_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JBT_cmd_node *jbt_cmd_list_remove_head(JBT_cmd_node *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *new_node = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_cmd_list_check_completed(list) == KAL_FALSE)
    {
        ASSERT(0);
    }
    jbt_cmd_list_take_sem();
    if (list->flink == list)
    {
        goto jbt_return;
    }
    if (list->blink == list)
    {
        goto jbt_return;
    }
    new_node = list->flink;
    list->flink->flink->blink = list;
    list->flink = list->flink->flink;
    jbt_cmd_list_reset(new_node);
  jbt_return:
    jbt_cmd_list_give_sem();
    return new_node;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_remove_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_cmd_list_remove_node(JBT_cmd_node *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool status = KAL_FALSE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_cmd_list_check_completed(node) == KAL_FALSE)
    {
        ASSERT(0);
    }
    jbt_cmd_list_take_sem();
    if (node->flink == node)
    {
        status = KAL_FALSE;
        goto jbt_return;
    }
    if (node->blink == node)
    {
        status = KAL_FALSE;
        goto jbt_return;
    }
    ASSERT(node->flink != 0);
    ASSERT(node->blink != 0);
    node->blink->flink = node->flink;
    node->flink->blink = node->blink;
    jbt_cmd_list_reset(node);
    status = KAL_TRUE;
  jbt_return:
    jbt_cmd_list_give_sem();
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_list_check_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_cmd_list_check_empty(JBT_cmd_node *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool status = KAL_TRUE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_cmd_list_check_completed(node) == KAL_FALSE)
    {
        ASSERT(0);
    }
    jbt_cmd_list_take_sem();
    if (node->flink == node)
    {
        status = KAL_TRUE;
    }
    else
    {
        status = KAL_FALSE;
    }
    jbt_cmd_list_give_sem();
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_queue_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_queue_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_cmd_sem = kal_create_sem("jbt_cmd_sem", 1);
    jbt_cmd_process_sem = kal_create_sem("jbt_cmd_process_sem", 1);
    jbt_cmd_kick_sem = kal_create_sem("jbt_cmd_kick_sem", 1);

    kal_mem_set((kal_uint8*) & jbt_cmd_queue_context, 0, sizeof(jbt_cmd_queue_context));
    jbt_cmd_list_init(&jbt_cmd_queue_context.empty_list);
    jbt_cmd_list_init(&jbt_cmd_queue_context.cmd_list);
    jbt_cmd_queue_context.queue_kick_off = 0;

    for (i = 0; i < JBT_MAX_COMMAND_QUEUE; i++)
    {
        jbt_cmd_list_init(&jbt_cmd_queue_context.cmd_node[i]);
        jbt_cmd_list_insert_tail(&jbt_cmd_queue_context.empty_list, &jbt_cmd_queue_context.cmd_node[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_kick_check_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_kick_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilmPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(jbt_cmd_kick_sem, KAL_INFINITE_WAIT);
    kal_trace(TRACE_FUNC, JBT_JBT_CMD_KICK_CHECK_LIST);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_CONTEXTQUEUE_KICK_OFF_D, jbt_cmd_queue_context.queue_kick_off);

    if (jbt_cmd_queue_context.queue_kick_off != 1)
    {
        jbt_cmd_queue_context.queue_kick_off = 1;
        ilmPtr = allocate_ilm(MOD_JASYN);
        ilmPtr->msg_id = MSG_ID_BT_JSR_KICK_NEW_COMMAND;
        ilmPtr->local_para_ptr = NULL;
        ilmPtr->peer_buff_ptr = NULL;
        ilmPtr->dest_mod_id = MOD_JASYN;
        ilmPtr->src_mod_id = MOD_JASYN;
        ilmPtr->sap_id = BT_APP_SAP;
        msg_send_ext_queue(ilmPtr);
    }
    kal_give_sem(jbt_cmd_kick_sem);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_kick_check_list_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_kick_check_list_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(jbt_cmd_kick_sem, KAL_INFINITE_WAIT);
    jbt_cmd_queue_context.queue_kick_off = 0;
    kal_trace(TRACE_FUNC, JBT_JBT_CMD_KICK_CHECK_LIST_DONE);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_CONTEXTQUEUE_KICK_OFF_D, jbt_cmd_queue_context.queue_kick_off);
    kal_give_sem(jbt_cmd_kick_sem);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_insert_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opcode      [IN]        
 *  type        [IN]        
 *  parms       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_cmd_insert_queue(kal_uint8 opcode, kal_uint8 type, kal_uint8 *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool node_empty;
    kal_bool status = KAL_TRUE;
    JBT_cmd_node *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_INSERT_QUEUE_TYPExD, type);

    switch (type)
    {
        case JBT_STACK_CMD_CONCURRENT:
            jbt_cmd_queue_concurrent_processing(opcode, parms);
            break;
        case JBT_STACK_CMD_NOCONCURRENT:
            node_empty = jbt_cmd_list_check_empty(&jbt_cmd_queue_context.empty_list);
            if (!node_empty)
            {
                node = (JBT_cmd_node*) jbt_cmd_list_remove_head(&jbt_cmd_queue_context.empty_list);
                node->cmd_code = opcode;
                kal_trace(TRACE_JBT_GROUP, JBT_JBT_NODECMD_CODExD, node->cmd_code);
                node->parms = parms;
                jbt_cmd_list_insert_tail(&jbt_cmd_queue_context.cmd_list, node);
                status = KAL_TRUE;
                jbt_cmd_kick_check_list();
            }
            else
            {
                status = KAL_FALSE;
            }
            break;
    }
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_INSERT_QUEUE_RETURN_STATUS_xD, status);
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_check_and_remove_in_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opcode      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JBT_cmd_node *jbt_cmd_check_and_remove_in_queue(kal_uint8 opcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *temp;
    JBT_cmd_node *node = 0;
    JBT_cmd_node *list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_AND_REMOVE_IN_QUEUE_OPCODEx02X, opcode);

    list = &jbt_cmd_queue_context.cmd_list;

    if (jbt_cmd_list_check_completed(list) == KAL_FALSE)
    {
        ASSERT(0);
    }

    jbt_cmd_list_take_sem();

    if (list->flink != list)
    {
        temp = list;
        for (temp = temp->flink; temp != list; temp = temp->flink)
        {

            ASSERT(temp->flink != 0);
            ASSERT(temp->blink != 0);
            if (temp->flink->blink != temp)
            {
                node = 0;
                break;
            }
            if (temp->blink->flink != temp)
            {
                node = 0;
                break;
            }
            if (temp->cmd_code == opcode)
            {
                kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_AND_REMOVE_IN_QUEUE_MATCHED);
                node = temp;
                temp->blink->flink = temp->flink;
                temp->flink->blink = temp->blink;
                kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_AND_REMOVE_IN_QUEUE_JBT_CMD_LIST_RESET);
                jbt_cmd_list_reset(node);
                break;
            }
        }
    }
    jbt_cmd_list_give_sem();
    return node;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_queue_nonconcurrent_processing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_queue_nonconcurrent_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(jbt_cmd_process_sem, KAL_INFINITE_WAIT);

    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_NONCONCURRENT_PROCESSING);

    if (jbt_cmd_queue_context.cmd_run_no < JBT_MAX_COMMAND_NO)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_LIST_REMOVE_HEAD);
        node = jbt_cmd_list_remove_head(&jbt_cmd_queue_context.cmd_list);
        jbt_cmd_queue_context.cmd_run_no++;
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_CONTEXTCMD_RUN_NOxD, jbt_cmd_queue_context.cmd_run_no);
        kal_trace(TRACE_JBT_GROUP, JBT_NODECMD_CODExD, node->cmd_code);
        switch (node->cmd_code)
        {
            case JBT_CMDCODE_DEVICE_RESTORE_COD:
                jbt_set_local_cod_cmd_body(node->parms, BTBM_WRITE_COD_RESTORE);
                break;
            case JBT_CMDCODE_DEVICE_RESTORE_MMI:
                break;
            case JBT_CMDCODE_SET_LOCAL_COD:
                jbt_set_local_cod_cmd_body(node->parms, BTBM_WRITE_COD_MASK);
                break;
            case JBT_CMDCODE_GET_REMOTE_NAME:
                jbt_get_remote_name_cmd_body(node->parms);
                break;
            case JBT_CMDCODE_DEVICE_DISCOVERY_CMD:
                jbt_device_discovery_cmd_body(node->parms);
                break;
                /* Add 2007-1119 */
            case JBT_CMDCODE_SET_ACL_SECURITY_INFO:
                jbt_set_acl_security_cmd_body(node->parms);
                break;
            default:
                ASSERT(0);
                break;
        }
        if (node->parms != 0)
        {
            jbt_free_record(node->parms);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(node->parms);
#else
            kal_adm_free(jbt_get_mem_pool_id(),node->parms);
#endif
        }
        node->parms = 0;
        node->cmd_code = 0;
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_LIST_INIT);
        jbt_cmd_list_init(node);
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_LIST_INSERT_TAIL);
        jbt_cmd_list_insert_tail(&jbt_cmd_queue_context.empty_list, node);

    }
    kal_give_sem(jbt_cmd_process_sem);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_NONCONCURRENT_PROCESSING_END);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_queue_nonconcurrent_completed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_queue_nonconcurrent_completed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *list = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(jbt_cmd_process_sem, KAL_INFINITE_WAIT);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_NONCONCURRENT_COMPLETED);

    ASSERT(jbt_cmd_queue_context.cmd_run_no > 0);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_CONTEXTCMD_RUN_NOx02X, jbt_cmd_queue_context.cmd_run_no);
    jbt_cmd_queue_context.cmd_run_no--;
    list = &jbt_cmd_queue_context.cmd_list;
    if (list->flink != list)
    {
        jbt_cmd_kick_check_list();
    }
    kal_give_sem(jbt_cmd_process_sem);

    if ((jbt_cmd_queue_context.cmd_run_no == 0) && (jbt_gap_power_state() == JBT_POWER_OTHERS))
    {
        jbt_restore_procedure(JBT_CMD_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_queue_concurrent_processing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opcode      [IN]        
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_queue_concurrent_processing(kal_uint8 opcode, void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_CONCURRENT_PROCESSING_OPCODExD, opcode);
    switch (opcode)
    {
        case JBT_CMDCODE_GET_LOCAL_ADDR:
            jbt_get_local_addr_cmd_body(parms);
            break;
        case JBT_CMDCODE_GET_LOCAL_COD:
            jbt_get_local_cod_cmd_body(parms);
            break;
        case JBT_CMDCODE_GET_LOCAL_NAME:
            jbt_get_local_name_cmd_body(parms);
            break;
        case JBT_CMDCODE_GET_REMOTE_ACL_INFO:
            jbt_get_acl_info_cmd_body(parms);
            break;
        case JBT_CMDCODE_DEVICE_DISCOVERY_CMD_CANCEL:
            jbt_device_discovery_cancel_cmd_body(parms);
            break;
            /* BCC */
        case JBT_CMDCODE_BCC_AUTHORIZE:
            jbt_authorize_req_cmd_body(parms);
            break;
        case JBT_CMDCODE_BCC_IS_AUTHORIZED:
            jbt_is_authorized_req_body(parms);
            break;
        case JBT_CMDCODE_BCC_IS_TRUSTED:
            jbt_is_trusted_req_body(parms);
            break;
        case JBT_CMDCODE_BCC_GET_HOST_SECURITY_MODE:
            jbt_get_host_security_mode_body(parms);
            break;
        case JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICE_COUNT:
            jbt_get_preknown_device_count_req_body(parms);
            break;
        case JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICES:
            jbt_get_preknown_devices_req_body(parms);
            break;
        case JBT_CMDCODE_BCC_GET_NATIVE_PWR_STATUS:
            jbt_get_native_pwr_status_req_cmd_body(parms);
            break;

			
    }
    kal_trace(TRACE_INFO, JBT_JBT_CMD_QUEUE_CONCURRENT_PROCESSING_END);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_check_device_in_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cmd_opcode      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_cmd_check_device_in_queue(kal_uint8 cmd_opcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JBT_cmd_node *node = 0;
    kal_bool status = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_RESULT, 0xB1);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_CMD_OPCODExD, cmd_opcode);

    node = jbt_cmd_check_and_remove_in_queue(cmd_opcode);
    if (node != 0)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_NODE_NOT_0);
        switch (cmd_opcode)
        {
            case JBT_CMDCODE_DEVICE_DISCOVERY_CMD:
            {
                bt_bm_discovery_cancel_cnf_struct *msg;

                msg = (bt_bm_discovery_cancel_cnf_struct*)
                    construct_local_para(sizeof(bt_bm_discovery_cancel_cnf_struct), TD_UL);

                msg->result = BTBM_ADP_SUCCESS;
                msg->total_number = 0;
                jbt_send_msg(
                    MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF,
                    MOD_JASYN,
                    MOD_JASYN,
                    BT_APP_SAP,
                    (local_para_struct*) msg,
                    NULL);

            }

                break;
            case JBT_CMDCODE_GET_REMOTE_NAME:
            {
                bt_bm_read_remote_name_cnf_struct *msg;
                jbt_gap_get_remote_name *info;

                info = (jbt_gap_get_remote_name*) node->parms;
                msg = (bt_bm_read_remote_name_cnf_struct*)
                    construct_local_para(sizeof(bt_bm_read_remote_name_cnf_struct), TD_UL);
                msg->result = BTBM_ADP_FAILED;
                msg->name_len = 0;
                memset(msg->name, 0, BTBM_ADP_MAX_NAME_LEN);
                msg->cod = 0;
                jbt_ConvertToBdAddr(&(msg->bd_addr), info->addr);
                jbt_send_msg(
                    MSG_ID_BT_BM_READ_REMOTE_NAME_CNF,
                    MOD_JASYN,
                    MOD_JASYN,
                    BT_APP_SAP,
                    (local_para_struct*) msg,
                    NULL);

            }
                break;
            case JBT_CMDCODE_SET_LOCAL_COD:
            {
                bt_bm_write_local_cod_cnf_struct *msg;

                msg = (bt_bm_write_local_cod_cnf_struct*)
                    construct_local_para(sizeof(bt_bm_write_local_cod_cnf_struct), TD_UL);
                msg->result = BTBM_ADP_FAILED;
                jbt_send_msg(
                    MSG_ID_BT_BM_WRITE_LOCAL_COD_CNF,
                    MOD_JASYN,
                    MOD_JASYN,
                    BT_APP_SAP,
                    (local_para_struct*) msg,
                    NULL);

            }
                break;
            case JBT_CMDCODE_SET_ACL_SECURITY_INFO:
            {
                bt_jsr82_set_acl_security_cnf_struct *msg;
                jbt_gap_set_security *info = (jbt_gap_set_security*) node->parms;

                msg = (bt_jsr82_set_acl_security_cnf_struct*)
                    construct_local_para(sizeof(bt_jsr82_set_acl_security_cnf_struct), TD_UL);
                msg->result = BTBM_ADP_FAILED;
                msg->transaction_id = info->transaction_id;
                memcpy(msg->bdAddr, info->addr, 6);
                jbt_send_msg(
                    MSG_ID_BT_JSR82_SET_ACL_SECURITY_CNF,
                    MOD_JASYN,
                    MOD_JASYN,
                    BT_APP_SAP,
                    (local_para_struct*) msg,
                    NULL);

            }
                break;
            default:
                ASSERT(0);
        }
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_NODEPARMS_08X, node->parms);
        if (node->parms != 0)
        {
            jbt_free_record(node->parms);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(node->parms);
#else
            kal_adm_free(jbt_get_mem_pool_id(),node->parms);
#endif
        }
        node->parms = 0;
        node->cmd_code = 0;
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_JBT_CMD_LIST_INIT);
        jbt_cmd_list_init(node);
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_JBT_CMD_LIST_INSERT_TAIL);
        jbt_cmd_list_insert_tail(&jbt_cmd_queue_context.empty_list, node);
        status = KAL_TRUE;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_cmd_handle_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_cmd_handle_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_RESULT, 0xA1);

    /* TODO the check range may be furthur optimized. we only need to check specific non-concurrent commands */
    for (i = JBT_CMDCODE_GET_LOCAL_NAME; i < JBT_CMDCODE_DEVICE_DISCOVERY_CMD_CANCEL; i++)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_HANDLE_RESTORE_INDEXx02X, i);
        jbt_cmd_check_device_in_queue(i);
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_CMD_HANDLE_RESTORE_JBT_CMD_QUEUE_CONTEXTCMD_RUN_NOx02X,
        jbt_cmd_queue_context.cmd_run_no);

    if (jbt_cmd_queue_context.cmd_run_no == 0)
    {
        jbt_restore_procedure(JBT_CMD_SUCCESS);
    }
    else
    {
        /* Add check: If JBT is in POWER_OTHERS state (caused by VM finalize), if there is an inquiry ongoing, just cancels it */
        if (jbt_gap_power_state() == JBT_POWER_OTHERS)
        {
            jbt_op_info *discovery_operation = jbt_gap_obtain_operation(JBT_CMDCODE_DEVICE_DISCOVERY_CMD);

            if (discovery_operation->operation_state == JBT_OPERATION_DISCOVERY_SEARCHING)
            {
                /* Existing an ongoing discovery operation, sends discovery cancel cmd to btstack to speed the process of VM termination */
                jbt_gap_device_discovery_cancel *parms;
                kal_uint32 jbt_gap_device_discovery_cancel_size = sizeof(jbt_gap_device_discovery_cancel);
                kal_uint8 block_inx = 0;
                
                /*
                 * DONT invoke the function jbt_device_discovery_cancel_cmd() directly:
                 * Because JBT is not power_on status during VM termination, if invoking this function will return failure
                 */
                block_inx = jbt_malloc_block(jbt_gap_device_discovery_cancel_size);

#ifndef JBT_SUPPORT_ADM_MEM
                parms = (jbt_gap_device_discovery_cancel*) jvm_malloc(jbt_gap_device_discovery_cancel_size);
#else                
                parms = (jbt_gap_device_discovery_cancel*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_device_discovery_cancel_size);
#endif
                if (parms != 0)
                {
                    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CANCEL_INQUIRY_DUE_TO_VM_TERMINATE);
                    jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_device_discovery_cancel_size);
                    parms->transaction_id = discovery_operation->transaction_id;
                    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_INSERT_QUEUE);
                    jbt_cmd_insert_queue(
                        JBT_CMDCODE_DEVICE_DISCOVERY_CMD_CANCEL,
                        JBT_STACK_CMD_CONCURRENT,
                        (kal_uint8*) parms);
                    
                    jbt_free_record((kal_uint8*) parms);
#ifndef JBT_SUPPORT_ADM_MEM
                    jvm_free((kal_uint8*) parms);
#else
                    kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) parms);
#endif
                }
                else
                {
                    /* Failed of jvm_malloc() */
                    jbt_free_block(block_inx);
                    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_CANCEL_INQUIRY_FAILED_WHILE_VM_TERMINATE);
                }
            }
        }
    }
}

#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_CMDHDL_C */ 

