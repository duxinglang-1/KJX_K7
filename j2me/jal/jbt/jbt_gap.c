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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _JBT_GAP_C
#define _JBT_GAP_C

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
#include "jbt_interface.h"
#include "jbt_internal.h"
#include "jam_interface.h"
#include "jam_internal.h"
#include "jvm_interface.h"

#if 1
#define __RESTORE_COD_BY_JBT_TO_BTSTACK__
#endif 

#define JBT_POWER_OFF_BIT_EVENT(bit_offset) (1 << bit_offset)
#define JBT_POWER_ON_WAITING_EVENT (1<<JBT_POWER_ON_WAITING_BIT)

/* Set bit1,2,3,4 */
#define JBT_POWER_OFF_ALL_EVENTS ((1<<JBT_POWER_OFF_RESTORE_MEM_BIT) | (1<<JBT_POWER_OFF_RESTORE_COD_BIT) | (1<<JBT_POWER_OFF_RESTORE_MMI_BIT) | (1<<JBT_POWER_OFF_RESTORE_LINK_BIT))

extern kal_eventgrpid g_java_event_group_2;

JBT_GAP_CNTX jbt_gap_context;

/*****************************************************************************
 * FUNCTION
 *  jbt_gap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_gap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set((kal_uint8*) & jbt_gap_context, 0, sizeof(jbt_gap_context));
    kal_trace(TRACE_FUNC, JBT_GAP_INIT_RESET_POWER_STATE_TO_OFF);
    jbt_gap_context.jbt_power_status = JBT_POWER_OFF;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_gap_power_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
JBT_POWER_STATE_ENUM jbt_gap_power_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_POWER_STATE_RETURN_STATUSxD, jbt_gap_context.jbt_power_status);
    return jbt_gap_context.jbt_power_status;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_gap_obtain_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cmdType     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_op_info *jbt_gap_obtain_operation(JBT_CMDCODE cmdType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmdType == JBT_CMDCODE_POWER_ON)
    {
        return &jbt_gap_context.jbt_power_on;
    }
    else if (cmdType == JBT_CMDCODE_POWER_OFF)
    {
        return &jbt_gap_context.jbt_power_off;
    }
    else if (cmdType == JBT_CMDCODE_GET_LOCAL_ADDR)
    {
        return &jbt_gap_context.jbt_read_addr;
    }
    else if (cmdType == JBT_CMDCODE_GET_LOCAL_COD)
    {
        return &jbt_gap_context.jbt_get_cod;
    }
    else if (cmdType == JBT_CMDCODE_SET_LOCAL_COD)
    {
        return &jbt_gap_context.jbt_set_cod;
    }
    else if (cmdType == JBT_CMDCODE_GET_LOCAL_NAME)
    {
        return &jbt_gap_context.jbt_get_local_name;
    }
    else if (cmdType == JBT_CMDCODE_SET_LOCAL_DEVICE_NAME)
    {
        return &jbt_gap_context.jbt_set_local_name;
    }
    else if (cmdType == JBT_CMDCODE_GET_LOCAL_DISCOVERY_MODE)
    {
        return &jbt_gap_context.jbt_get_local_discoverable;
    }
    else if (cmdType == JBT_CMDCODE_SET_LOCAL_DISCOVERY_MODE)
    {
        return &jbt_gap_context.jbt_set_local_discoverable;
    }
    else if (cmdType == JBT_CMDCODE_GET_REMOTE_NAME)
    {
        return &jbt_gap_context.jbt_get_remote_name;
    }
    else if (cmdType == JBT_CMDCODE_DEVICE_DISCOVERY_CMD)
    {
        return &jbt_gap_context.jbt_device_discovery;
    }
    else if (cmdType == JBT_CMDCODE_GET_REMOTE_ACL_INFO)
    {
        return &jbt_gap_context.jbt_get_acl_info;
    }
    else if (cmdType == JBT_CMDCODE_SET_ACL_SECURITY_INFO)
    {
        return &jbt_gap_context.jbt_set_acl_security;
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jbt_check_inquiry_operation_ongoing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_bool
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_check_inquiry_operation_ongoing(void)
{
    if (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_DISCOVERY_SEARCHING)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jbt_check_inquiry_operation_in_cmdlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_bool
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_check_inquiry_operation_in_cmdlist(void)
{
    if (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_STATE_INQUEUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_general_non_poweron_reject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_general_non_poweron_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GENERAL_NON_POWERON_REJECT_RETURN_STATUSxD, jbt_gap_context.jbt_power_status);
    if (jbt_gap_context.jbt_power_status == JBT_POWER_ON)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}

#if JBT_CACHE_DEV_NAME


/*****************************************************************************
 * FUNCTION
 *  jbt_return_existed_device_name_enrty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bdaddr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_device_name *jbt_return_existed_device_name_enrty(kal_uint8 *bdaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    jbt_device_name *name_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_CACHE_NAME_TABLE_SIZE; i++)
    {
        /* Check if this bdaddr's device name is already in the table */
        name_entry = &(jbt_gap_context.jbt_cache_device_name_table[i]);
        if (name_entry->used == 1)
        {
            if (memcmp(name_entry->bd_addr, bdaddr, 6) == 0)
            {
                return name_entry;
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_return_device_name_enrty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bdaddr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jbt_device_name *jbt_return_device_name_enrty(kal_uint8 *bdaddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    jbt_device_name *name_entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < JBT_MAX_CACHE_NAME_TABLE_SIZE; i++)
    {
        /* Check if this bdaddr's device name is already in the table */
        name_entry = &(jbt_gap_context.jbt_cache_device_name_table[i]);
        if (name_entry->used == 1)
        {
            if (memcmp(name_entry->bd_addr, bdaddr, 6) == 0)
            {
                return name_entry;
            }
        }
    }

    for (i = 0; i < JBT_MAX_CACHE_NAME_TABLE_SIZE; i++)
    {
        /* Find a free name entry */
        name_entry = &(jbt_gap_context.jbt_cache_device_name_table[i]);
        if (name_entry->used == 0)
        {
            return name_entry;
        }
    }
    return NULL;
}
#endif /* JBT_CACHE_DEV_NAME */


/*****************************************************************************
 * FUNCTION
 *  jbt_restore_procedure
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_restore_procedure(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_RESTORE_PROCEDURE_RESULTxD, result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXT_JBT_RESTORE_STATExD, jbt_gap_context.jbt_restore_state);
    switch (jbt_gap_context.jbt_restore_state)
    {
        case BT_JSR82_RESTORE_NONE:
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_RESTORE_BTSTACK_LINK_CMD);
            jbt_restore_btstack_link_cmd();
            break;
        case BT_JSR82_RESTORE_LINK:
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_RESTORE_MMI_CMD);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_LINK_BIT),
                KAL_OR);
            jbt_restore_mmi_cmd();
            break;
        case BT_JSR82_RESTORE_MMI:
            if (result == JBT_CMD_SUCCESS)
            {
                kal_trace(TRACE_JBT_GROUP, JBT_JBT_RESTORE_BTSTACK_COD);
                kal_set_eg_events(
                    g_java_event_group_2,
                    JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MMI_BIT),
                    KAL_OR);
            #ifdef __RESTORE_COD_BY_JBT_TO_BTSTACK__
                jbt_restore_btstack_cod();
            #else /* __RESTORE_COD_BY_JBT_TO_BTSTACK__ */ 
                /* After restoring MMI, MMI will restore CoD correctly */
                if (jbt_gap_context.jbt_restore_state == BT_JSR82_RESTORE_MMI)
                {
                    jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_COD;
                    kal_trace(TRACE_JBT_GROUP, JBT_BT_COMPLETE_RESTORE_MMI_AND_COD);
                    kal_set_eg_events(
                        g_java_event_group_2,
                        JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_COD_BIT),
                        KAL_OR);
                    jbt_restore_btstack_memory();
                }
            #endif /* __RESTORE_COD_BY_JBT_TO_BTSTACK__ */ 
            }
            else
            {
                kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_POWER_OFF_REQ_RESULT_JBT_POWEROFF_BY_JBT);
                /*
                 * Note by mtk01411 2007-1122: If the result of restore MMI is failed (only result is mmi_bt_bcc_result_in_flight_mode):
                 * The memory and jbt's global context will be freed and reset in jbt_handle_power_off_req_result(),
                 * In flight mode, the native BT stack is in off state and disabled, it can skipped to reset btstack's step!
                 */
                kal_set_eg_events(
                    g_java_event_group_2,
                    JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MMI_BIT),
                    KAL_OR);
                kal_set_eg_events(
                    g_java_event_group_2,
                    JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_COD_BIT),
                    KAL_OR);
                kal_set_eg_events(
                    g_java_event_group_2,
                    JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MEM_BIT),
                    KAL_OR);
                jbt_handle_power_off_req_result(JBT_POWEROFF_BY_JBT);
            }
            break;
        case BT_JSR82_RESTORE_COD:
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_RESTORE_BTSTACK_MEMORY);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_COD_BIT),
                KAL_OR);
            jbt_restore_btstack_memory();
            break;
        case BT_JSR82_RESTORE_MEM:
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_POWER_OFF_REQ_RESULT);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MEM_BIT),
                KAL_OR);
            jbt_handle_power_off_req_result(JBT_POWEROFF_BY_JBT);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_power_on_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_power_on_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_POWER_ON_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }
#endif /*__MVM__*/
    if (jbt_gap_context.jbt_power_status == JBT_POWER_OFF)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_ONOPERATION_STATEx02X, jbt_gap_context.jbt_power_on.operation_state);
        if (jbt_gap_context.jbt_power_on.operation_state == JBT_OPERATION_STATE_NONE)
        {
            jbt_gap_context.jbt_power_on.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_gap_context.jbt_power_on.transaction_id = transaction_id;
            jbt_send_msg(MSG_ID_MMI_BT_BCC_POWER_ON_REQ, MOD_JASYN, MOD_MMI, BT_APP_SAP, NULL, NULL);

            result = KAL_TRUE;
        }
        return result;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_power_off_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_power_off_cmd(kal_int32 transaction_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_POWER_OFF_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    if (jbt_gap_context.jbt_power_status == JBT_POWER_ON)
    {
        jbt_gap_context.jbt_power_status = JBT_POWER_OTHERS;
        jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_NONE;
        jbt_gap_context.jbt_power_off.transaction_id = transaction_id;
        jbt_send_msg(MSG_ID_BT_JSR_POWER_OFF_REQ, MOD_JASYN, MOD_JASYN, BT_APP_SAP, NULL, NULL);

        result = KAL_TRUE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_restore_btstack_link_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_restore_btstack_link_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_RESTORE_BTSTACK_LINK_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_RESTORE_STATEx02X, jbt_gap_context.jbt_restore_state);

    if (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS)
    {
        if (jbt_gap_context.jbt_restore_state == BT_JSR82_RESTORE_NONE)
        {
            jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_LINK;
            jbt_send_msg(MSG_ID_BT_JSR82_RESTROE_ACL_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_restore_mmi_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_restore_mmi_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_RESTORE_MMI_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_RESTORE_STATEx02X, jbt_gap_context.jbt_restore_state);

    if (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS)
    {
        if ((jbt_gap_context.jbt_restore_state) == BT_JSR82_RESTORE_LINK)
        {
            jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_MMI;
            jbt_send_msg(MSG_ID_MMI_BT_BCC_RESTORE_REQ, MOD_JASYN, MOD_MMI, BT_APP_SAP, NULL, NULL);

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_restore_btstack_cod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_restore_btstack_cod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_local_cod_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_RESTORE_BTSTACK_COD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_RESTORE_STATEx02X, jbt_gap_context.jbt_restore_state);

    if (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS)
    {
        if (jbt_gap_context.jbt_restore_state == BT_JSR82_RESTORE_MMI)
        {
            jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_COD;

            msg = (bt_bm_write_local_cod_req_struct*) construct_local_para(
                                                        sizeof(bt_bm_write_local_cod_req_struct),
                                                        TD_CTRL);
            msg->cod = 0xFFFFFFFF;
            msg->write_type = BTBM_WRITE_COD_RESTORE;
            jbt_send_msg(
                MSG_ID_BT_BM_WRITE_LOCAL_COD_REQ,
                MOD_JASYN,
                MOD_BT,
                BT_APP_SAP,
                (local_para_struct*) msg,
                NULL);

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_restore_btstack_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_restore_btstack_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_RESTORE_BTSTACK_MEMORY);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_RESTORE_STATEx02X, jbt_gap_context.jbt_restore_state);

    if (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS)
    {
        if (jbt_gap_context.jbt_restore_state == BT_JSR82_RESTORE_COD)
        {
            jbt_gap_context.jbt_restore_state = BT_JSR82_RESTORE_MEM;
            jbt_send_msg(MSG_ID_BT_JSR_DEACTIVE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_power_status_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
JBT_POWER_STATE_ENUM jbt_get_power_status_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);
    return jbt_gap_context.jbt_power_status;
}



/*****************************************************************************
 * FUNCTION
 *  jbt_finalize
 * DESCRIPTION
 *  This function is used to JBT restore procedure to terminate all existing connections and reset JBT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 jbt_event_group = 0;
    kal_uint32 transaction_id = 0x1688;
    kal_status ret_status = KAL_ERROR;

    JBT_POWER_STATE_ENUM jbt_current_power_state = jbt_gap_power_state();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_send_terminate_ind();

    if (jbt_current_power_state == JBT_POWER_ON)
    {
        kal_uint32 on_requested_events = JBT_POWER_OFF_ALL_EVENTS;

        kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_REQ_EVENT, on_requested_events);
        jbt_power_off_cmd(transaction_id);
    #if JBT_FINALIZE_REFRESH_UI_SUPPORT
        /* We have to refresh UI periodically. Therefore, we invoke kal_retrieve_eg_events() in blocking mode. */
        while (ret_status != KAL_SUCCESS)
        {
            ret_status = kal_retrieve_eg_events(
                            g_java_event_group_2,
                            on_requested_events,
                            KAL_AND_CONSUME,
                            &jbt_event_group,
                            KAL_NO_SUSPEND);
            kal_sleep_task(30);
            jbt_finalize_for_jvm();
        }
    #else /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
        ret_status = kal_retrieve_eg_events(
                        g_java_event_group_2,
                        on_requested_events,
                        KAL_AND_CONSUME,
                        &jbt_event_group,
                        KAL_SUSPEND);
        /* We invoke kal_retrieve_eg_events() in blocking mode. Therefore, it must success.*/
        if (ret_status != KAL_SUCCESS)
        {
            ASSERT(0);
        }
    #endif /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
        kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_COMPLETE);
    }
    else if (jbt_current_power_state == JBT_POWER_OFF)
    {
        /* Check if the power_on request operation is ongoing or not */
        if (jbt_gap_context.jbt_power_on.operation_state == JBT_OPERATION_STATE_NONE)
        {
            kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_ALREADY_OFF);
        }
        else
        {
            /* POWER_ON request operation is ongoing */
            kal_uint32 requested_events = JBT_POWER_ON_WAITING_EVENT;
            kal_uint32 waiting_on_event_group = 0;

            jbt_gap_context.enable_vm_finalize = KAL_TRUE;

            kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_WAIT_POWER_ON);
        #if JBT_FINALIZE_REFRESH_UI_SUPPORT
            while (ret_status != KAL_SUCCESS)
            {
                ret_status = kal_retrieve_eg_events(
                                g_java_event_group_2,
                                requested_events,
                                KAL_OR_CONSUME,
                                &waiting_on_event_group,
                                KAL_NO_SUSPEND);
                kal_sleep_task(30);
                jbt_finalize_for_jvm();
            }
        #else /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
            ret_status = kal_retrieve_eg_events(
                            g_java_event_group_2,
                            requested_events,
                            KAL_OR_CONSUME,
                            &waiting_on_event_group,
                            KAL_SUSPEND);
            if (ret_status != KAL_SUCCESS)
            {
                ASSERT(0);
            }
        #endif /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
            if (jbt_gap_power_state() == JBT_POWER_ON)
            {
                kal_trace(TRACE_INFO, JBT_FINALIZE_START_POWER_OFF);
                requested_events = JBT_POWER_OFF_ALL_EVENTS;
                jbt_power_off_cmd(transaction_id);
            #if JBT_FINALIZE_REFRESH_UI_SUPPORT
                while (ret_status != KAL_ERROR)
                {
                    ret_status = kal_retrieve_eg_events(
                                    g_java_event_group_2,
                                    requested_events,
                                    KAL_AND_CONSUME,
                                    &jbt_event_group,
                                    KAL_NO_SUSPEND);
                    kal_sleep_task(30);
                    jbt_finalize_for_jvm();
                }
            #else /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
                ret_status = kal_retrieve_eg_events(
                                g_java_event_group_2,
                                requested_events,
                                KAL_AND_CONSUME,
                                &jbt_event_group,
                                KAL_SUSPEND);
                if (ret_status != KAL_SUCCESS)
                {
                    ASSERT(0);
                }
            #endif /* JBT_FINALIZE_REFRESH_UI_SUPPORT */ 
                jbt_gap_context.enable_vm_finalize = KAL_FALSE;
                kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_COMPLETE);
            }
            else
            {
                /* Wait for JBT POWER ON result, but it is failure */
                kal_trace(TRACE_JBT_GROUP, JBT_FINALIZE_COMPLETE_POWER_ON_FAILED);
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_addr_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_local_addr_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_get_local_addr *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_LOCAL_ADDR_CMD_TRANSACTION_IDx08X, transaction_id);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }
#endif
    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_READ_ADDROPERATION_STATEx02X,
        jbt_gap_context.jbt_read_addr.operation_state);

    if (jbt_gap_context.jbt_read_addr.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_get_local_addr_size = sizeof(jbt_gap_get_local_addr);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_get_local_addr_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_get_local_addr*) jvm_malloc(jbt_gap_get_local_addr_size);
#else
        parms = (jbt_gap_get_local_addr*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_get_local_addr_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_get_local_addr_size);
        }
        /* Insert this cmd to concurrent type queue, so set operation_state as ongoing here is allowed */
        jbt_gap_context.jbt_read_addr.operation_state = JBT_OPERATION_STATE_ONGOING;
        parms->transaction_id = transaction_id;
        jbt_gap_context.jbt_read_addr.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_GET_LOCAL_ADDR, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) parms);
        jbt_free_record((kal_uint8*) parms);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) parms);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) parms);
#endif
        result = KAL_TRUE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_cod_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_local_cod_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_get_local_cod *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_LOCAL_COD_CMD_TRANSACTION_IDx08X, transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_CODOPERATION_STATEx02X,
        jbt_gap_context.jbt_get_cod.operation_state);

    if (jbt_gap_context.jbt_get_cod.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_get_local_cod_size = sizeof(jbt_gap_get_local_cod);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_get_local_cod_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_get_local_cod*) jvm_malloc(jbt_gap_get_local_cod_size);
#else
        parms = (jbt_gap_get_local_cod*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_get_local_cod_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_get_local_cod_size);
        }
        /* Insert this cmd to concurrent type queue, so set operation_state as ongoing here is allowed */
        jbt_gap_context.jbt_get_cod.operation_state = JBT_OPERATION_STATE_ONGOING;
        parms->transaction_id = transaction_id;
        jbt_gap_context.jbt_get_cod.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_GET_LOCAL_COD, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) parms);
        jbt_free_record((kal_uint8*) parms);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) parms);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) parms);
#endif
        result = KAL_TRUE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_name_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_local_name_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_get_local_name *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_LOCAL_NAME_CMD_TRANSACTION_IDx08X, transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_gap_context.jbt_get_local_name.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_get_local_name_size = sizeof(jbt_gap_get_local_name);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_get_local_name_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_get_local_name*) jvm_malloc(jbt_gap_get_local_name_size);
#else
        parms = (jbt_gap_get_local_name*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_get_local_name_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_get_local_name_size);
        }
        /* Insert this cmd to concurrent type queue, so set operation_state as ongoing here is allowed */
        jbt_gap_context.jbt_get_local_name.operation_state = JBT_OPERATION_STATE_ONGOING;
        parms->transaction_id = transaction_id;
        jbt_gap_context.jbt_get_local_name.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_GET_LOCAL_NAME, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) parms);
        jbt_free_record((kal_uint8*) parms);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) parms);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) parms);
#endif
        result = KAL_TRUE;
    }
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  jbt_trigger_panic_mechanism_cmd
 * DESCRIPTION
 *  Only for testing during development stage
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_trigger_panic_mechanism_cmd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_send_msg(MSG_ID_BT_JSR_PANIC, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_local_name_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  name                [IN]        
 *  length              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_set_local_name_cmd(kal_int32 transaction_id, kal_uint8 *name, kal_uint8 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_LOCAL_NAME_CMD_TRANSACTION_IDx08X, transaction_id);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_discovery_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_local_discovery_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_LOCAL_DISCOVERY_CMD_TRANSACTION_IDx08X, transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_LOCAL_DISCOVERABLEOPERATION_STATEx02X,
        jbt_gap_context.jbt_get_cod.operation_state);
    if (jbt_gap_context.jbt_get_local_discoverable.operation_state == JBT_OPERATION_STATE_NONE)
    {
        jbt_gap_context.jbt_get_local_discoverable.operation_state = JBT_OPERATION_STATE_ONGOING;
        jbt_gap_context.jbt_get_local_discoverable.transaction_id = transaction_id;
        jbt_send_msg(MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_REQ, MOD_JASYN, MOD_MMI, BT_APP_SAP, NULL, NULL);

        result = KAL_TRUE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_local_discovery_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  mode                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_set_local_discovery_cmd(kal_int32 transaction_id, kal_uint32 mode, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    mmi_bt_bcc_set_discoverable_mode_req_struct *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_LOCAL_DISCOVERY_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_LOCAL_DISCOVERY_CMD_MODEx08X, mode);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_SET_LOCAL_DISCOVERABLEOPERATION_STATEx02X,
        jbt_gap_context.jbt_set_local_discoverable.operation_state);

    if (jbt_gap_context.jbt_set_local_discoverable.operation_state == JBT_OPERATION_STATE_NONE)
    {
        jbt_gap_context.jbt_set_local_discoverable.operation_state = JBT_OPERATION_STATE_ONGOING;
        jbt_gap_context.jbt_set_local_discoverable.transaction_id = transaction_id;
        parms =
            (mmi_bt_bcc_set_discoverable_mode_req_struct*)
            construct_local_para(sizeof(mmi_bt_bcc_set_discoverable_mode_req_struct), TD_CTRL);
        switch (mode & 0x03)
        {
            case 0x00:
                parms->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_off_i_off;
                break;
            case 0x01:
                parms->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_off_i_on;
                break;
            case 0x02:
                parms->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_off;
                break;
            case 0x03:
                parms->discoverable_mode = mmi_bt_bcc_discoverable_mode_p_on_i_on;
                break;
        }
        jbt_send_msg(
            MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_REQ,
            MOD_JASYN,
            MOD_MMI,
            BT_APP_SAP,
            (local_para_struct*) parms,
            NULL);

        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_local_cod_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  cod                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_set_local_cod_cmd(kal_int32 transaction_id, kal_uint32 cod, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_set_local_cod *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_LOCAL_COD_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_LOCAL_COD_CMD_MODEx08X, cod);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_SET_CODOPERATION_STATEx02X,
        jbt_gap_context.jbt_set_cod.operation_state);

    if (jbt_gap_context.jbt_set_cod.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_set_local_cod_size = sizeof(jbt_gap_set_local_cod);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_set_local_cod_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_set_local_cod*) jvm_malloc(jbt_gap_set_local_cod_size);
#else
        parms = (jbt_gap_set_local_cod*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_set_local_cod_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_set_local_cod_size);
        }
        /*
         * Insert this cmd to non-concurrent type queue, so its operation_state is inqueue
         * BTW, its operation_state will be ongoing while kick-off this cmd from queue (at that time, cmd_run_no will be also increase 1)
         */
        jbt_gap_context.jbt_set_cod.operation_state = JBT_OPERATION_STATE_INQUEUE;
        parms->transaction_id = transaction_id;
        parms->cod = cod;
        jbt_gap_context.jbt_set_cod.transaction_id = transaction_id;
        
        /* Only for JBT_STACK_CMD_NOCONCURRENT: it is necessary to check returned value from jbt_cmd_insert_queue() */
        if (jbt_cmd_insert_queue(JBT_CMDCODE_SET_LOCAL_COD, JBT_STACK_CMD_NOCONCURRENT, (kal_uint8*) parms))
        {
            result = KAL_TRUE;
        }
        else
        {
            /* In this case: it means that no cmd node in empty list and this action will be rejected */
            jbt_gap_context.jbt_set_cod.operation_state = JBT_OPERATION_STATE_NONE;
            jbt_gap_context.jbt_set_cod.transaction_id = 0; 
            jbt_free_record((kal_uint8*)parms);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*)parms);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*)parms);
#endif
            parms = 0;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_remote_name_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_remote_name_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_get_remote_name *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_REMOTE_NAME_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GET_REMOTE_NAME_CMD_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        *status_result = JBT_CMD_REJECT_DUE_TO_POWEROFF;
        return KAL_FALSE;
    }

    if (jbt_check_inquiry_operation_ongoing())
    {
        *status_result = JBT_CMD_REJECT_DUE_TO_INQUIRY;
        return KAL_FALSE;
    }

    /*
      * Only remote name request cmd is necessary to check cmdlist
      * For sdap_ss_cmd,sdao_sa_cmd,sdap_ssa_cmd and con_req_cmd: they send message to BT in function directly
      * -> In this way, they are not necessary to check cmdlist, these page actions will be performed earlier than inquirt cmd still in cmdlist
      */
    if (jbt_check_inquiry_operation_in_cmdlist())
    {
        *status_result = JBT_CMD_REJECT_DUE_TO_INQUIRY;
        return KAL_FALSE;
    }
    
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_REMOTE_NAMEOPERATION_STATEx02X,
        jbt_gap_context.jbt_get_remote_name.operation_state);

    if (jbt_gap_context.jbt_get_remote_name.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_get_remote_name_size = sizeof(jbt_gap_get_remote_name);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_get_remote_name_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_get_remote_name*) jvm_malloc(jbt_gap_get_remote_name_size);
#else
        parms = (jbt_gap_get_remote_name*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_get_remote_name_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            *status_result = JBT_CMD_REJECT_NO_RESOURCE;
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_get_remote_name_size);
        }

        /*
         * Insert this cmd to non-concurrent type queue, so its operation_state is inqueue
         * BTW, its operation_state will be ongoing while kick-off this cmd from queue (at that time, cmd_run_no will be also increase 1)
         */
        jbt_gap_context.jbt_get_remote_name.operation_state = JBT_OPERATION_STATE_INQUEUE;
        parms->transaction_id = transaction_id;
        kal_mem_cpy(parms->addr, addr, 6);
        jbt_gap_context.jbt_get_remote_name.transaction_id = transaction_id;

        /* Only for JBT_STACK_CMD_NOCONCURRENT: it is necessary to check returned value from jbt_cmd_insert_queue() */
        if (jbt_cmd_insert_queue(JBT_CMDCODE_GET_REMOTE_NAME, JBT_STACK_CMD_NOCONCURRENT, (kal_uint8*) parms))
        {
            result = KAL_TRUE;
        }
        else
        {
            /* In this case: it means that no cmd node in empty list and this action will be rejected */
            jbt_gap_context.jbt_get_remote_name.operation_state = JBT_OPERATION_STATE_NONE;
            jbt_gap_context.jbt_get_remote_name.transaction_id = 0;
            jbt_free_record((kal_uint8*)parms);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*)parms);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*)parms); 
#endif
            parms = 0;
        }
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_acl_info_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_get_acl_info_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_gap_get_acl_info *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GET_ACL_INFO_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GET_ACL_INFO_CMD_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_ACL_INFOOPERATION_STATEx02X,
        jbt_gap_context.jbt_get_acl_info.operation_state);

    if (jbt_gap_context.jbt_get_acl_info.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_get_acl_info_size = sizeof(jbt_gap_get_acl_info);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_get_acl_info_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_get_acl_info*) jvm_malloc(jbt_gap_get_acl_info_size);
#else
        parms = (jbt_gap_get_acl_info*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_get_acl_info_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_get_acl_info_size);
        }
        /* Insert this cmd to concurrent type queue, so set operation_state as ongoing here is allowed */
        jbt_gap_context.jbt_get_acl_info.operation_state = JBT_OPERATION_STATE_ONGOING;
        parms->transaction_id = transaction_id;
        jbt_gap_context.jbt_get_acl_info.transaction_id = transaction_id;
        jbt_ConvertBdAddrOrder(parms->addr, addr);
        jbt_cmd_insert_queue(JBT_CMDCODE_GET_REMOTE_ACL_INFO, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) parms);
        jbt_free_record((kal_uint8*) parms);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) parms);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) parms);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_acl_security_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 *  security_mode       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_set_acl_security_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8 security_mode, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_FAILED;
    jbt_gap_set_security *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_ACL_SECURITY_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_SET_ACL_SECURITY_CMD_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SET_ACL_SECURITY_CMD_SECURITY_MODEx02X, security_mode);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }
    
    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }

    if (security_mode == JBT_SECURITY_OFF)
    {
        return result;
    }

    if (jbt_gap_context.jbt_set_acl_security.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_gap_set_security_size = sizeof(jbt_gap_set_security);
        kal_uint8 block_inx = 0;
        block_inx = jbt_malloc_block(jbt_gap_set_security_size);
#ifndef JBT_SUPPORT_ADM_MEM
        parms = (jbt_gap_set_security*) jvm_malloc(jbt_gap_set_security_size);
#else
        parms = (jbt_gap_set_security*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_set_security_size);
#endif
        if (parms == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_set_security_size);
        }

        /*
         * Insert this cmd to non-concurrent type queue, so its operation_state is inqueue
         * BTW, its operation_state will be ongoing while kick-off this cmd from queue (at that time, cmd_run_no will be also increase 1)
         */
        jbt_gap_context.jbt_set_acl_security.operation_state = JBT_OPERATION_STATE_INQUEUE;
        jbt_gap_context.jbt_set_acl_security.transaction_id = transaction_id;
        parms->transaction_id = transaction_id;
        parms->security_mode = security_mode;
        /* Modify 2007-1215: bd_addr array sent to BTStack from low byte to high byte (inx 0 to 5) */
        jbt_ConvertBdAddrOrder(parms->addr, addr);

        /* Only for JBT_STACK_CMD_NOCONCURRENT: it is necessary to check returned value from jbt_cmd_insert_queue() */
        if (jbt_cmd_insert_queue(JBT_CMDCODE_SET_ACL_SECURITY_INFO, JBT_STACK_CMD_NOCONCURRENT, (kal_uint8*) parms))
        {
            result = JBT_CMD_SUCCESS;
        }
        else
        {
            /* In this case: it means that no cmd node in empty list and this action will be rejected */
            jbt_gap_context.jbt_set_acl_security.operation_state = JBT_OPERATION_STATE_NONE;
            jbt_gap_context.jbt_set_acl_security.transaction_id = 0;
            jbt_free_record((kal_uint8*)parms);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free((kal_uint8*)parms);
#else
            kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*)parms);
#endif
            parms = 0;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_device_discovery_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  iac_code            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_device_discovery_cmd(kal_int32 transaction_id, kal_uint32 iac_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_FAILED;
    jbt_gap_device_discovery *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEVICE_DISCOVERY_CMD_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEVICE_DISCOVERY_CMD_IAC_CODEx08X, iac_code);

    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
    
    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }

    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_DEVICE_DISCOVERYOPERATION_STATEx02X,
        jbt_gap_context.jbt_device_discovery.operation_state);

    if (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_STATE_NONE)
    {
        if ((iac_code == 0x9E8B33) || (iac_code == 0x9E8B00))
        {
            kal_uint32 jbt_gap_device_discovery_size = sizeof(jbt_gap_device_discovery);
            kal_uint8 block_inx = 0;
            block_inx = jbt_malloc_block(jbt_gap_device_discovery_size);
#ifndef JBT_SUPPORT_ADM_MEM
            parms = (jbt_gap_device_discovery*) jvm_malloc(jbt_gap_device_discovery_size);
#else
            parms = (jbt_gap_device_discovery*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_device_discovery_size);
#endif
            if (parms == 0)
            {
                jbt_free_block(block_inx);
                return result;
            }
            else
            {
                jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_device_discovery_size);
            }
            
            /*
             * Insert this cmd to non-concurrent type queue, so its operation_state is inqueue
             * BTW, its operation_state will be ongoing while kick-off this cmd from queue (at that time, cmd_run_no will be also increase 1)
             */
            jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_STATE_INQUEUE;
            jbt_gap_context.jbt_device_discovery.transaction_id = transaction_id;
            parms->transaction_id = transaction_id;
            if (iac_code == 0x9E8B33)
            {
                parms->iac_code = BTBM_GENERAL_INQUIRY;
            }
            else
            {
                parms->iac_code = BTBM_LIMITED_INQUIRY;
            }

            /* Only for JBT_STACK_CMD_NOCONCURRENT: it is necessary to check returned value from jbt_cmd_insert_queue() */
            if (jbt_cmd_insert_queue(JBT_CMDCODE_DEVICE_DISCOVERY_CMD, JBT_STACK_CMD_NOCONCURRENT, (kal_uint8*) parms))
            {
                result = JBT_CMD_SUCCESS;
            }
            else
            {
                /* In this case: it means that no cmd node in empty list and this action will be rejected */
                jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_STATE_NONE;
                jbt_gap_context.jbt_device_discovery.transaction_id = 0;
                jbt_free_record((kal_uint8*)parms);
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free((kal_uint8*)parms);
#else
                kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*)parms);
#endif
                parms = 0;
            }
        }
        else
        {
            result = JBT_CMD_NOT_SUPPORT;
        }

    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_device_discovery_cancel_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_device_discovery_cancel_cmd(kal_int32 transaction_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    kal_bool status;
    jbt_gap_device_discovery_cancel *parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEVICE_DISCOVERY_CANCEL_CMD_TRANSACTION_IDx02X, transaction_id);

    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }

    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_JBT_CMDCODE_DEVICE_DISCOVERY_CMD);
    /* Note: Remove the non-kick-off discovery_cmd from queue due to discovery_cancel cmd, then a device_discovery_cancel_cnf will be sent to MOD_JASYN */
    status = jbt_cmd_check_device_in_queue(JBT_CMDCODE_DEVICE_DISCOVERY_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_CHECK_DEVICE_IN_QUEUE_STATUS_x02X, status);

    if (status != KAL_TRUE)
    {
        kal_trace(
            TRACE_JBT_GROUP,
            JBT_JBT_GAP_CONTEXTJBT_DEVICE_DISCOVERYOPERATION_STATEx02X,
            jbt_gap_context.jbt_device_discovery.operation_state);
        if (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_DISCOVERY_SEARCHING)
        {
            kal_trace(
                TRACE_JBT_GROUP,
                JBT_OLD_TRANSACTION_IDx08X_NEW_TRANSACTION_IDx08X,
                jbt_gap_context.jbt_device_discovery.transaction_id,
                transaction_id);
            if (jbt_gap_context.jbt_device_discovery.transaction_id == transaction_id)
            {
                kal_uint32 jbt_gap_device_discovery_cancel_size = sizeof(jbt_gap_device_discovery_cancel);
                kal_uint8 block_inx = 0;
                block_inx = jbt_malloc_block(jbt_gap_device_discovery_cancel_size);
#ifndef JBT_SUPPORT_ADM_MEM
                parms = (jbt_gap_device_discovery_cancel*) jvm_malloc(jbt_gap_device_discovery_cancel_size);
#else
                parms = (jbt_gap_device_discovery_cancel*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_gap_device_discovery_cancel_size); 
#endif
                if (parms == 0)
                {
                    /* Failed of jvm_malloc() */
                    jbt_free_block(block_inx);
                    return result;
                }
                else
                {
                    jbt_malloc_record(block_inx, (kal_uint8*)parms, jbt_gap_device_discovery_cancel_size);
                }

                jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_DISCOVERY_CANCEL;
                parms->transaction_id = transaction_id;
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
                result = JBT_CMD_SUCCESS;
            }
        }
    }
    else
    {
        result = JBT_CMD_SUCCESS;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_addr_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_get_local_addr_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_get_local_addr *info = (jbt_gap_get_local_addr*) parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_LOCAL_ADDR_CMD_BODY);
    jbt_gap_context.jbt_read_addr.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_read_addr.transaction_id = info->transaction_id;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_READ_ADDRTRANSACTION_IDx08X,
        jbt_gap_context.jbt_read_addr.transaction_id);

    jbt_send_msg(MSG_ID_BT_BM_READ_LOCAL_ADDR_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_cod_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_get_local_cod_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_get_local_cod *info = (jbt_gap_get_local_cod*) parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_LOCAL_COD_CMD_BODY);
    jbt_gap_context.jbt_get_cod.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_get_cod.transaction_id = info->transaction_id;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_CODTRANSACTION_IDx08X,
        jbt_gap_context.jbt_get_cod.transaction_id);

    jbt_send_msg(MSG_ID_BT_BM_READ_LOCAL_COD_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_local_name_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_get_local_name_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_get_local_name *info = (jbt_gap_get_local_name*) parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_LOCAL_NAME_CMD_BODY);
    jbt_gap_context.jbt_get_local_name.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_get_local_name.transaction_id = info->transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_BT_GET_LOCAL_NAME_TRANSACTION_ID, jbt_gap_context.jbt_get_local_name.transaction_id);

    jbt_send_msg(MSG_ID_BT_BM_READ_LOCAL_NAME_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_local_cod_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_set_local_cod_cmd_body(void *parms, btbm_write_cod_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_set_local_cod *info = (jbt_gap_set_local_cod*) parms;
    bt_bm_write_local_cod_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SET_LOCAL_COD_CMD_BODY);

    msg = (bt_bm_write_local_cod_req_struct*) construct_local_para(sizeof(bt_bm_write_local_cod_req_struct), TD_CTRL);
    msg->cod = info->cod;
    msg->write_type = type;
    kal_trace(TRACE_JBT_GROUP, JBT_MSGCODx08X, msg->cod);
    kal_trace(TRACE_JBT_GROUP, JBT_MSGWRITE_TYPEx08X, msg->write_type);

    jbt_gap_context.jbt_set_cod.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_set_cod.transaction_id = info->transaction_id;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_SET_CODTRANSACTION_IDx08X,
        jbt_gap_context.jbt_set_cod.transaction_id);

    jbt_send_msg(MSG_ID_BT_BM_WRITE_LOCAL_COD_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_remote_name_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_get_remote_name_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_get_remote_name *info = (jbt_gap_get_remote_name*) parms;
    bt_bm_read_remote_name_req_struct *msg;

#if JBT_RETURN_CACHE_NAME_DIRECTLY
    jbt_device_name *name_entry = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_REMOTE_NAME_CMD_BODY);

#if JBT_RETURN_CACHE_NAME_DIRECTLY
    /* Lookup cache name table first */
    name_entry = jbt_return_existed_device_name_enrty(info->addr);
    if (name_entry != NULL)
    {
        /* generate a MSG_ID_BT_BM_READ_REMOTE_NAME_CNF and send this msg to MOD_JASYNC */
        bt_bm_read_remote_name_cnf_struct *btbm_adp_msg;
        btbm_bd_addr_t rem_addr;

        jbt_ConvertToBdAddr(&rem_addr, info->addr);

        btbm_adp_msg = (bt_bm_read_remote_name_cnf_struct*)
            construct_local_para(sizeof(bt_bm_read_remote_name_cnf_struct), TD_UL);

        btbm_adp_msg->bd_addr.lap = rem_addr.lap;
        btbm_adp_msg->bd_addr.uap = rem_addr.uap;
        btbm_adp_msg->bd_addr.nap = rem_addr.nap;
        btbm_adp_msg->result = BTBM_ADP_SUCCESS;
        btbm_adp_msg->name_len = name_entry->name_len;
        memcpy(btbm_adp_msg->name, name_entry->name, name_entry->name_len);
        /*
         * Before entering jbt_get_remote_name_cmd_body(): cmd_run_no alredy add one, 
         * it must set operation state as JBT_OPERATION_STATE_ONGOING, then in jbt_handle_get_remote_name_result():
         * it will discount one of cmd_run_no due to operation_state is matched with JBT_OPERATION_STATE_ONGOING
         */
        jbt_gap_context.jbt_get_remote_name.operation_state = JBT_OPERATION_STATE_ONGOING;
        jbt_gap_context.jbt_get_remote_name.transaction_id = info->transaction_id;
        jbt_send_msg(
            MSG_ID_BT_BM_READ_REMOTE_NAME_CNF,
            MOD_JASYN,
            MOD_JASYN,
            BT_APP_SAP,
            (local_para_struct*) btbm_adp_msg,
            NULL);
        return;
    }

#endif /* JBT_RETURN_CACHE_NAME_DIRECTLY */ 
    msg = (bt_bm_read_remote_name_req_struct*) construct_local_para(
                                                sizeof(bt_bm_read_remote_name_req_struct),
                                                TD_CTRL);
    jbt_ConvertToBdAddr(&msg->bd_addr, info->addr);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_MSGBDADDRx02Xx02Xx02Xx02Xx02Xx02X,
        info->addr[0],
        info->addr[1],
        info->addr[2],
        info->addr[3],
        info->addr[4],
        info->addr[5]);

    jbt_gap_context.jbt_get_remote_name.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_get_remote_name.transaction_id = info->transaction_id;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_REMOTE_NAMETRANSACTION_IDx08X,
        jbt_gap_context.jbt_get_remote_name.transaction_id);

    jbt_send_msg(MSG_ID_BT_BM_READ_REMOTE_NAME_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_acl_info_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_get_acl_info_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_get_acl_info *info = (jbt_gap_get_acl_info*) parms;
    bt_bm_get_link_state_req *msg;
    kal_uint8 *addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_GET_ACL_INFO_CMD_BODY);
    jbt_gap_context.jbt_get_acl_info.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_get_acl_info.transaction_id = info->transaction_id;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_GET_ACL_INFOTRANSACTION_IDx08X,
        jbt_gap_context.jbt_get_acl_info.transaction_id);

    addr = (kal_uint8*) info->addr;
    msg = (bt_bm_get_link_state_req*) construct_local_para(sizeof(bt_bm_get_link_state_req), TD_CTRL);
    memcpy(msg->bdaddr, addr, 6);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_MSGBDADDRx02Xx02Xx02Xx02Xx02Xx02X,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);

    jbt_send_msg(MSG_ID_BT_BM_GET_LINK_STATE_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_device_discovery_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_device_discovery_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_discovery_req_struct *msg;
    jbt_gap_device_discovery *info = (jbt_gap_device_discovery*) parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_DEVICE_DISCOVERY_CMD_BODY);

    jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_DISCOVERY_SEARCHING;
    jbt_gap_context.jbt_device_discovery.transaction_id = info->transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_DEVICE_DISCOVERYx08X, jbt_gap_context.jbt_device_discovery.transaction_id);

    msg = (bt_bm_discovery_req_struct*) construct_local_para(sizeof(bt_bm_discovery_req_struct), TD_CTRL);
    msg->cod = 0xFFFFFFFF;
    msg->inquiry_length = 20;
    msg->inquiry_number = 10;
    if (info->iac_code == 0)
    {
        msg->access_mode = BTBM_GENERAL_INQUIRY;
    }
    else
    {
        msg->access_mode = BTBM_LIMITED_INQUIRY;
    }
    msg->discovery_mode = BTBM_DISCOVERY_WITH_NAME;
    jbt_send_msg(MSG_ID_BT_BM_DISCOVERY_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_device_discovery_cancel_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_device_discovery_cancel_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_device_discovery_cancel *info = (jbt_gap_device_discovery_cancel*) parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_DEVICE_DISCOVERY_CMD_BODY);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_DEVICE_DISCOVERYTRANSACTION_IDx08X,
        jbt_gap_context.jbt_device_discovery.transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_INFOTRANSACTION_IDx08X, info->transaction_id);

    jbt_gap_context.jbt_device_discovery.transaction_id = info->transaction_id;

    if (jbt_gap_context.jbt_device_discovery.transaction_id == info->transaction_id)
    {
        jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_DISCOVERY_CANCEL;
        jbt_send_msg(MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, NULL, NULL);

    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_set_acl_security_cmd_body
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parms       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_set_acl_security_cmd_body(void *parms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_gap_set_security *info = (jbt_gap_set_security*) parms;
    bt_jsr82_set_acl_security_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg =
        (bt_jsr82_set_acl_security_req_struct*) construct_local_para(
                                                    sizeof(bt_jsr82_set_acl_security_req_struct),
                                                    TD_CTRL);
    msg->transaction_id = info->transaction_id;
    memcpy(msg->bd_addr, info->addr, 6);
    msg->security_mode = info->security_mode;

    jbt_gap_context.jbt_set_acl_security.operation_state = JBT_OPERATION_STATE_ONGOING;
    jbt_gap_context.jbt_set_acl_security.transaction_id = info->transaction_id;

    jbt_send_msg(MSG_ID_BT_JSR82_SET_ACL_SECURITY_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_restore_btstack_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_restore_btstack_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_RESTORE_BTSTACK_RESULT);
    jbt_restore_procedure(JBT_CMD_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_restore_mmi_req_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_restore_mmi_req_result(mmi_bt_bcc_restore_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_RESTORE_MMI_REQ_RESULT);

    result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);

    switch (msg->result)
    {
        case mmi_bt_bcc_result_succeeded:
        case mmi_bt_bcc_result_failed:
            result = JBT_CMD_SUCCESS;
            break;
        case mmi_bt_bcc_result_in_flight_mode:
            result = JBT_CMD_FAILED;
            break;
    }
    kal_trace(TRACE_INFO, JBT_RESULTx02X, result);
    jbt_restore_procedure(result);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_power_on_req_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_power_on_req_result(mmi_bt_bcc_power_on_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_power_on_result parms;
    mmi_bt_bcc_result_code result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_POWER_ON_REQ_RESULT);

    parms.result = JBT_CMD_FAILED;
    result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);

    switch (result)
    {
        case mmi_bt_bcc_result_succeeded:
        case mmi_bt_bcc_result_power_already_on:
        {
            
#ifdef JBT_SUPPORT_ADM_MEM 
#ifndef JBT_CREATE_ADM_INIT
            jbt_create_adm_pool();
            kal_trace(TRACE_JBT_GROUP,FUNC_JBT_ADM_CREATE_POWER_ON_SUCCESS);
#endif /* JBT_CREATE_ADM_INIT */           
#endif /* JBT_SUPPORT_ADM_MEM */

            parms.result = JBT_CMD_SUCCESS;
            jbt_gap_context.jbt_power_status = JBT_POWER_ON;
        }
            break;
        case mmi_bt_bcc_result_failed:
        case mmi_bt_bcc_result_in_flight_mode:
        case mmi_bt_bcc_result_during_power_switching:
        case mmi_bt_bcc_result_simap_activated:	
            jbt_gap_context.jbt_power_status = JBT_POWER_OFF;
            break;
    }
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);

    if (jbt_gap_context.enable_vm_finalize == KAL_TRUE)
    {
        kal_set_eg_events(g_java_event_group_2, JBT_POWER_ON_WAITING_EVENT, KAL_OR);
        kal_trace(TRACE_JBT_GROUP, JBT_SET_END_POWER_ON_EVENT);
    }

    transaction_id = jbt_gap_context.jbt_power_on.transaction_id;
    jbt_gap_context.jbt_power_on.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_power_on.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_POWER_ON, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_power_off_req_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_power_off_req_result(kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    kal_uint8 opcode;
    jbt_power_off_result parms;
    JbtEventCBF jbt_abnormal_event_cb = NULL; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_POWER_OFF_REQ_RESULT_TYPEx02X, type);

    parms.result = JBT_CMD_SUCCESS;
    /*
     * Note by mtk01411: 2007-1122
     * If the type is JBT_POWEROFF_BY_MMI, the BT Stack is already in off s tate
     * So, it is only necessary to free memory and reset context used in JBT
     */
    if (type == JBT_POWEROFF_BY_MMI)
    {
        if (jbt_gap_context.jbt_power_status == JBT_POWER_OFF)
        {
            return;
        }
        else
        {
            transaction_id = 0; /* TODO CODE_SIZE We can move the init to in the beginning of this function*/
        }

        if (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS)
        {
            /*
             * Race condition: After JBT is proceeding power off procedure, mmi power off or panic reset is going on at same time 
             * Because VM will block at retrieve event once the jbt_finalize() is invoked:
             * In this case, JBT will set events here to let VM terminate successfully 
             */
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_LINK_BIT),
                KAL_OR);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MMI_BIT),
                KAL_OR);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_COD_BIT),
                KAL_OR);
            kal_set_eg_events(
                g_java_event_group_2,
                JBT_POWER_OFF_BIT_EVENT(JBT_POWER_OFF_RESTORE_MEM_BIT),
                KAL_OR);
            kal_trace(TRACE_JBT_GROUP, JBT_POWEROFF_BY_MMI_END_BEFORE_JBT_POWER_OFF);
            /* Change opcode to JBT_OPCODE_POWER_OFF */
            opcode = JBT_OPCODE_POWER_OFF;
        }
        else   
        {
            /* In JBT_POWER_ON state received ABNORMAL_RESET due to MMI power off operation or panic reset */
            opcode = JBT_OPCODE_SYSTEM_ABNORMAL_RESET;
        }
    }
    else
    {
        transaction_id = jbt_gap_context.jbt_power_off.transaction_id;
        opcode = JBT_OPCODE_POWER_OFF;

    }

    jbt_gap_context.jbt_power_off.transaction_id = 0;
    jbt_gap_context.jbt_power_status = JBT_POWER_OFF;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_POWER_OFF_REQ_RESULT_OPCODEx02X, opcode);
    /* Before reseting vm's registered cb function, it will be recorded first */
    jbt_abnormal_event_cb = jbt_retrieve_cb_func();
#if 0
/* under construction !*/
/* under construction !*/
#endif
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_FREE_ALL);
    jbt_free_all();
#ifdef JBT_SUPPORT_ADM_MEM 
#ifndef JBT_CREATE_ADM_INIT
    jbt_delete_adm_pool();
#endif /* JBT_CREATE_ADM_INIT */   
#endif /* JBT_SUPPORT_ADM_MEM */   
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_INIT);
    jbt_init();
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_INIT_COMPLETED);
    
    if (jbt_abnormal_event_cb != NULL)
    {
        /* When VM receives this abnormal reset event, it must invoke jbt_event_registration() again */
        /* Three parms are local variables and passed to jbt_abnormal_event_cb */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_REPORT_JBT_POWER_OFF_OR_ABNORMAL_RESET);
        jbt_abnormal_event_cb(opcode, transaction_id, &parms);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_set_discoverable_mode_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_set_discoverable_mode_result(mmi_bt_bcc_set_discoverable_mode_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_set_local_discovery_result parms;
    mmi_bt_bcc_result_code result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SET_DISCOVERABLE_MODE_RESULT);

    transaction_id = jbt_gap_context.jbt_set_local_discoverable.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    parms.result = JBT_CMD_FAILED;

    result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);

    switch (result)
    {
        case mmi_bt_bcc_result_succeeded:
            parms.result = JBT_CMD_SUCCESS;
            break;
        case mmi_bt_bcc_result_failed:
        case mmi_bt_bcc_result_in_flight_mode:
        default:
            break;
    }
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);
    transaction_id = jbt_gap_context.jbt_set_local_discoverable.transaction_id;
    jbt_gap_context.jbt_set_local_discoverable.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_set_local_discoverable.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_SET_LOCAL_DISCOVERY_MODE, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_discoverable_mode_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_discoverable_mode_result(mmi_bt_bcc_get_discoverable_mode_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_local_discovery_mode_result parms;
    mmi_bt_bcc_result_code result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_DISCOVERABLE_MODE_RESULT);

    transaction_id = jbt_gap_context.jbt_get_local_discoverable.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    parms.result = JBT_CMD_FAILED;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_MSGDISCOVERABLE_MODEx02X, msg->discoverable_mode);

    switch (msg->discoverable_mode)
    {
        case mmi_bt_bcc_discoverable_mode_p_off_i_off:
            parms.mode = 0x00;
            break;
        case mmi_bt_bcc_discoverable_mode_p_off_i_on:
            parms.mode = 0x01;
            break;
        case mmi_bt_bcc_discoverable_mode_p_on_i_off:
            /*
             * Modify from 0x02 to 0x00: 2008-0327
             * As long as the inquiry_scan is off, it is in non-discoverable mode (This is also MMI's visiblity off) 
             * In this case, the mode = 0x00 is mapping to JSR Spec getDiscoverable() function:
             * If local device is in non-discoverable, its return value will be zero
             */
            parms.mode = 0x00;
            break;
        case mmi_bt_bcc_discoverable_mode_p_on_i_on:
            parms.mode = 0x03;
            break;
    }
    result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_RESULTx02X, result);

    switch (result)
    {
        case mmi_bt_bcc_result_succeeded:
            parms.result = JBT_CMD_SUCCESS;
            break;
        case mmi_bt_bcc_result_failed:
        case mmi_bt_bcc_result_in_flight_mode:
        default:
            break;
    }
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);
    transaction_id = jbt_gap_context.jbt_get_local_discoverable.transaction_id;
    jbt_gap_context.jbt_get_local_discoverable.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_get_local_discoverable.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_GET_LOCAL_DISCOVERY_MODE, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_local_addr_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_local_addr_result(bt_bm_read_local_addr_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_local_addr_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_LOCAL_ADDR_RESULT);

    parms.result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);

    jbt_ConvertBdAddr(parms.bd_addr, &msg->bd_addr);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_MSGBDADDRx02Xx02Xx02Xx02Xx02Xx02X,
        parms.bd_addr[0],
        parms.bd_addr[1],
        parms.bd_addr[2],
        parms.bd_addr[3],
        parms.bd_addr[4],
        parms.bd_addr[5]);

    transaction_id = jbt_gap_context.jbt_read_addr.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    jbt_gap_context.jbt_read_addr.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_read_addr.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_GET_LOCAL_ADDR, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_local_cod_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_local_cod_result(bt_bm_read_local_cod_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_local_cod_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_LOCAL_COD_RESULT);

    parms.result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);
    transaction_id = jbt_gap_context.jbt_get_cod.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    parms.cod = msg->cod;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSCODx08X, parms.cod);

    jbt_gap_context.jbt_get_cod.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_get_cod.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_GET_LOCAL_COD, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_local_name_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_local_name_result(bt_bm_read_local_name_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_local_name_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_HANDLE_GET_LOCAL_NAME_RESULT);

    parms.name_length = msg->name_len;
    memset(parms.name, 0, sizeof(parms.name));

    if (parms.name_length == 0)
    {
        parms.result = JBT_CMD_FAILED;
    }
    else
    {
        parms.result = JBT_CMD_SUCCESS;
        memcpy(parms.name, msg->name, msg->name_len);
    }
    jbt_gap_context.jbt_get_local_name.operation_state = JBT_OPERATION_STATE_NONE;
    transaction_id = jbt_gap_context.jbt_get_local_name.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    jbt_gap_context.jbt_get_local_name.transaction_id = 0;

    jbt_event_callback(JBT_OPCODE_GET_LOCAL_NAME, transaction_id, &parms);

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_set_local_cod_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_set_local_cod_result(bt_bm_write_local_cod_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_set_local_cod_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SET_LOCAL_COD_RESULT);

    parms.result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, parms.result);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_GAP_CONTEXTJBT_POWER_STATUSx02X, jbt_gap_context.jbt_power_status);

    if (jbt_gap_context.jbt_set_cod.operation_state == JBT_OPERATION_STATE_ONGOING)
    {
        /* In this case, set_local_cod cmd is issued before VM termination */
        jbt_cmd_queue_nonconcurrent_completed();
        transaction_id = jbt_gap_context.jbt_set_cod.transaction_id;
        kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
        jbt_gap_context.jbt_set_cod.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_set_cod.transaction_id = 0;
        jbt_event_callback(JBT_OPCODE_SET_LOCAL_COD, transaction_id, &parms);
    }
    else if (jbt_gap_context.jbt_restore_state == BT_JSR82_RESTORE_COD)
    {
        /* In this case, set_local_cod cmd is issued during VM termination and one of steps of VM termination procedure */
        jbt_restore_procedure(JBT_CMD_SUCCESS);
    }
    else if ((jbt_gap_context.jbt_set_cod.operation_state == JBT_OPERATION_STATE_INQUEUE)
             && (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS))
    {
        /* Note: In this case, set_local_cod_cmd is not issued, this cnf is generated and returned by JBT directly */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_GET_CNF_GENERATE_BY_JBT_DUE_TO_VM_TERMINATE, 1);
    }
    else
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_remote_name_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_remote_name_result(bt_bm_read_remote_name_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_remote_name_result parms;
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_REMOTE_NAME_RESULT);

    if (jbt_gap_context.jbt_get_remote_name.operation_state == JBT_OPERATION_STATE_ONGOING)
    {
        jbt_cmd_queue_nonconcurrent_completed();
        kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_QUEUE_NONCONCURRENT_COMPLETED);
        transaction_id = jbt_gap_context.jbt_get_remote_name.transaction_id;
        jbt_gap_context.jbt_get_remote_name.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_get_remote_name.transaction_id = 0;
    #if 0
/* under construction !*/
    #endif /* 0 */ 
        /* 2008-0318 modification: Some midlets will be terminated due to ask name failure, always returns SUCCESS */
        parms.result = JBT_CMD_SUCCESS;

        kal_trace(TRACE_JBT_GROUP, JBT_PARMSRESULTx02X, msg->result);
        kal_trace(TRACE_JBT_GROUP, JBT_MSGNAME_LENx02X, msg->name_len);
        jbt_ConvertBdAddr(parms.addr, &msg->bd_addr);
        kal_trace(
            TRACE_JBT_GROUP,
            JBT_MSGBDADDRx02Xx02Xx02Xx02Xx02Xx02X,
            parms.addr[0],
            parms.addr[1],
            parms.addr[2],
            parms.addr[3],
            parms.addr[4],
            parms.addr[5]);

        kal_mem_set(parms.name, 0, sizeof(parms.name));

        if ((msg->result == JBT_CMD_SUCCESS) && (msg->name_len != 0))
        {

            kal_mem_cpy(parms.name, msg->name, msg->name_len);
            parms.length = msg->name_len;
        }
        else
        {
            /* If result is not successful, try to find if it is in cache table */
            jbt_device_name *name_entry = NULL;

            name_entry = jbt_return_existed_device_name_enrty(parms.addr);
            if (name_entry != NULL)
            {
                kal_mem_cpy(parms.name, name_entry->name, name_entry->name_len);
                parms.length = name_entry->name_len;
            }
            else
            {
                /* Can not find this device's name in Cache Name Table. Just use fake name */
            #if 0    
/* under construction !*/
/* under construction !*/
            #else
                for (i=0; i <6; i++)
                {
                    int x=0,y=0;
                    x = (parms.addr[i]/16);
                    y = (parms.addr[i]%16);
                    if (x >= 10)
                    {
                        parms.name[0+3*i] = (x-10)+'A';
                    }
                    else
                    {
                        parms.name[0+3*i] = x+'0';
                    }
                    
                    if (y >= 10)
                    {
                        parms.name[1+3*i] = (y-10)+'A';
                    }
                    else
                    {
                        parms.name[1+3*i] = y+'0';
                    }
                    /* 0x3A is ':' */
                    parms.name[2+3*i] = 0x3A;
                }
                /* The format will be AA:BB:CC:DD:EE:FF (total 11 bytes) */
                parms.name[17] = 0;
                parms.length = 17;
            #endif    
            }
        }

        for (i = 0; i < parms.length; i++)
        {
            kal_trace(TRACE_JBT_GROUP, JBT_DEVICE_NAMEx02X_xC, parms.name[i], parms.name[i]);
        }

    #if JBT_CACHE_DEV_NAME
        /* Cache the device name into Cache Name table */
        if ((msg->name_len > 0) && (msg->result == JBT_CMD_SUCCESS))
        {
            jbt_device_name *name_entry = NULL;

            name_entry = jbt_return_device_name_enrty(parms.addr);
            if (name_entry != NULL)
            {
                /* name_entry != NULL: 1) existed entry or 2) a new allocated entry */
                if (name_entry->used == 0)
                {
                    /* name_entry->used=1: This is a new allocated entry for storing this device's name */
                    kal_uint8 block_inx = 0;
                    block_inx = jbt_malloc_block(JBT_MAX_CACHE_NAME_ENTRY_LEN);
#ifndef JBT_SUPPORT_ADM_MEM
                    name_entry->name = jvm_malloc(JBT_MAX_CACHE_NAME_ENTRY_LEN);
#else
                    name_entry->name = kal_adm_alloc(jbt_get_mem_pool_id(),JBT_MAX_CACHE_NAME_ENTRY_LEN);
#endif
                    if (name_entry->name != NULL)
                    {
                        jbt_malloc_record(block_inx, name_entry->name, JBT_MAX_CACHE_NAME_ENTRY_LEN);
                        name_entry->used = 1;
                    }
                    else
                    {
                        /* Failed of jvm_malloc() */
                        jbt_free_block(block_inx);
                    }
                }

                if (name_entry->used == 1)
                {
                    name_entry->name_len =
                        (parms.length > JBT_MAX_CACHE_NAME_ENTRY_LEN ? JBT_MAX_CACHE_NAME_ENTRY_LEN : parms.length);
                    memset(name_entry->name, 0, JBT_MAX_CACHE_NAME_ENTRY_LEN);
                    memcpy(name_entry->name, parms.name, name_entry->name_len);
                    memcpy(name_entry->bd_addr, parms.addr, 6);
                }
            }
        }
    #endif /* JBT_CACHE_DEV_NAME */ 

        jbt_event_callback(JBT_OPCODE_GET_REMOTE_NAME, transaction_id, &parms);
    }
    else if ((jbt_gap_context.jbt_get_remote_name.operation_state == JBT_OPERATION_STATE_INQUEUE)
             && (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS))
    {
        /* Note: In this case, get_remote_name_cmd is not issued, this cnf is generated and returned by JBT directly */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_GET_CNF_GENERATE_BY_JBT_DUE_TO_VM_TERMINATE, 2);
    }
    else
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_device_discovery_entry_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_device_discovery_entry_result(bt_bm_discovery_result_ind_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_device_discovery_entry_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_DEVICE_DISCOVERY_ENTRY_RESULT);

    transaction_id = jbt_gap_context.jbt_device_discovery.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    jbt_ConvertBdAddr(parms.addr, &msg->bd_addr);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_MSGBDADDRx02Xx02Xx02Xx02Xx02Xx02X,
        parms.addr[0],
        parms.addr[1],
        parms.addr[2],
        parms.addr[3],
        parms.addr[4],
        parms.addr[5]);

    kal_mem_set(parms.name, 0, sizeof(parms.name));
    kal_mem_cpy(parms.name, msg->name, msg->name_len);
    parms.length = msg->name_len;
    parms.cod = msg->cod;
    kal_trace(TRACE_JBT_GROUP, JBT_PARMSCODx08X, parms.cod);
    {
        kal_uint8 i = 0;

        for (i = 0; i < msg->name_len; i++)
        {
            kal_trace(TRACE_JBT_GROUP, JBT_DEVICE_NAMEx02X_xC, parms.name[i], parms.name[i]);
        }

    #if JBT_CACHE_DEV_NAME
        /* Cache the device name into Cache Name table */
        if (msg->name_len > 0)
        {
            jbt_device_name *name_entry = NULL;

            name_entry = jbt_return_device_name_enrty(parms.addr);
            if (name_entry != NULL)
            {
                /* name_entry != NULL: 1) existed entry or 2) a new allocated entry */
                if (name_entry->used == 0)
                {
                    kal_uint8 block_inx = 0;
                    block_inx = jbt_malloc_block(JBT_MAX_CACHE_NAME_ENTRY_LEN);
                    /* name_entry->used=1: This is a new allocated entry for storing this device's name */
#ifndef JBT_SUPPORT_ADM_MEM
                    name_entry->name = jvm_malloc(JBT_MAX_CACHE_NAME_ENTRY_LEN);
#else
                    name_entry->name = kal_adm_alloc(jbt_get_mem_pool_id(),JBT_MAX_CACHE_NAME_ENTRY_LEN);
#endif
                    if (name_entry->name != NULL)
                    {
                        jbt_malloc_record(block_inx, name_entry->name, JBT_MAX_CACHE_NAME_ENTRY_LEN);
                        name_entry->used = 1;
                    }
                    else
                    {
                        /* Faild of jvm_malloc() */
                        jbt_free_block(block_inx);
                    }
                }

                if (name_entry->used == 1)
                {
                    name_entry->name_len =
                        (parms.length > JBT_MAX_CACHE_NAME_ENTRY_LEN ? JBT_MAX_CACHE_NAME_ENTRY_LEN : parms.length);
                    memset(name_entry->name, 0, JBT_MAX_CACHE_NAME_ENTRY_LEN);
                    memcpy(name_entry->name, parms.name, name_entry->name_len);
                    memcpy(name_entry->bd_addr, parms.addr, 6);
                }
            }
        }
    #endif /* JBT_CACHE_DEV_NAME */ 
    }

    jbt_event_callback(JBT_OPCODE_DEVICE_DISCOVERY_RESULT, transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_device_discovery_completed_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_device_discovery_completed_result(bt_bm_discovery_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_device_discovery_completed_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_DEVICE_DISCOVERY_COMPLETED_RESULT);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_DEVICE_DISCOVERYOPERATION_STATEx02X,
        jbt_gap_context.jbt_device_discovery.operation_state);

    if ((jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_DISCOVERY_SEARCHING)
        || (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_DISCOVERY_CANCEL))
    {
        /*
         * Add this ccas to check: This DICOVERY_COMPLETE event is triggered by DISCOVERY_CANCEL cmd: 2008-0203 
         * cmd_run_no must be decreased by 1 to repsent the inquiry cmd is processed 
         * The transaction_id of DISCOVERY_CANCEL and of DISCOVERY cmd must be the same
         */

        transaction_id = jbt_gap_context.jbt_device_discovery.transaction_id;
        kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
        jbt_cmd_queue_nonconcurrent_completed();
        jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_device_discovery.transaction_id = 0;
        jbt_event_callback(JBT_OPCODE_DEVICE_DISCOVERY_COMPLETED, transaction_id, &parms);
    }
    else
    {
        /* Note: In this case, device_discovery_cmd or device_discovery_cancel_cmd is not issued, this cnf is generated and returned by JBT directly */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_GET_CNF_GENERATE_BY_JBT_DUE_TO_VM_TERMINATE, 3);
    }

}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_device_discovery_cancel_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_device_discovery_cancel_result(bt_bm_discovery_cancel_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_device_discovery_completed_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_DEVICE_DISCOVERY_CANCEL_RESULT);
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_JBT_GAP_CONTEXTJBT_DEVICE_DISCOVERYOPERATION_STATEx02X,
        jbt_gap_context.jbt_device_discovery.operation_state);
    if (jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_DISCOVERY_CANCEL)
    {
        jbt_cmd_queue_nonconcurrent_completed();
        transaction_id = jbt_gap_context.jbt_device_discovery.transaction_id;
        kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
        jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_device_discovery.transaction_id = 0;
        jbt_event_callback(JBT_OPCODE_DEVICE_DISCOVERY_COMPLETED, transaction_id, &parms);
    }
    else if ((jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_STATE_INQUEUE)
             && (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS))
    {
        /* Note: In this case, device_discovery_cmd is not issued and removed from queue, this device_discovery_cancel_cnf is generated and returned by JBT directly */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_GET_CNF_GENERATE_BY_JBT_DUE_TO_VM_TERMINATE, 4);
    }
    else if ((jbt_gap_context.jbt_device_discovery.operation_state == JBT_OPERATION_STATE_INQUEUE)
             && (jbt_gap_context.jbt_power_status == JBT_POWER_ON))
    {
        transaction_id = jbt_gap_context.jbt_device_discovery.transaction_id;
        kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
        jbt_gap_context.jbt_device_discovery.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_device_discovery.transaction_id = 0;
        jbt_event_callback(JBT_OPCODE_DEVICE_DISCOVERY_COMPLETED, transaction_id, &parms);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_get_acl_info_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_get_acl_info_result(bt_bm_get_link_state_cnf *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_get_acl_info_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_GET_ACL_INFO_RESULT);

    transaction_id = jbt_gap_context.jbt_get_acl_info.transaction_id;
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);

    jbt_gap_context.jbt_get_acl_info.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_gap_context.jbt_get_acl_info.transaction_id = 0;
    parms.result = msg->result;
    parms.is_master = msg->is_master;
    parms.is_authenticated = msg->is_authenticated;
    parms.is_encrypted = msg->is_encrypted;
    kal_trace(
        TRACE_JBT_GROUP,
        JBT_RESULTx02X_IS_MASTERx02X_IS_AUTHx02X_IS_ENCRYPTED,
        parms.result,
        parms.is_master,
        parms.is_authenticated,
        parms.is_encrypted);

    jbt_event_callback(JBT_OPCODE_GET_REMOTE_ACL_INFO, transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_set_acl_security_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_set_acl_security_result(bt_jsr82_set_acl_security_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_set_acl_security_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_JBT_GROUP, JBT_HANDLE_SET_ACL_SECURITY_RESULT);
    ASSERT(msg->transaction_id == jbt_gap_context.jbt_set_acl_security.transaction_id);

    if (jbt_gap_context.jbt_set_acl_security.operation_state == JBT_OPERATION_STATE_ONGOING)
    {
        /* Modify 2007-1215 */
        if (msg->result == JSR82_SET_ACL_SECURITY_SUCCESS)
        {
            parms.result = JBT_CMD_SUCCESS;
        }
        else
        {
            parms.result = JBT_CMD_FAILED;
        }

        parms.transaction_id = msg->transaction_id;
        memcpy(parms.bdAddr, msg->bdAddr, 6);

        kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, parms.transaction_id);
        jbt_cmd_queue_nonconcurrent_completed();

        jbt_gap_context.jbt_set_acl_security.operation_state = JBT_OPERATION_STATE_NONE;
        jbt_gap_context.jbt_set_acl_security.transaction_id = 0;

        jbt_event_callback(JBT_OPCODE_SET_ACL_SECURITY_INFO, parms.transaction_id, &parms);
    }
    else if ((jbt_gap_context.jbt_set_acl_security.operation_state == JBT_OPERATION_STATE_INQUEUE)
             && (jbt_gap_context.jbt_power_status == JBT_POWER_OTHERS))
    {
        /* Note: In this case, get_remote_name_cmd is not issued, this cnf is generated and returned by JBT directly */
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_GET_CNF_GENERATE_BY_JBT_DUE_TO_VM_TERMINATE, 5);
    }
    else
    {
        ASSERT(0);
    }
}

#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_GAP_C */ 

