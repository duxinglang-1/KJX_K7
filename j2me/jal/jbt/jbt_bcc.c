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
 * jbt_bcc.c
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __SUPPORT_JBT__

/***************************************************************************** 
* Included Files
*****************************************************************************/
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"     /* type of system module components */
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "mmiapi_bt_struct.h"
#include "j2me_trace.h"
#include "uart_sw.h"
#include "jvm_interface.h"
#include "jam_internal.h"
#include "jbt_interface.h"
#include "jbt_internal.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
JBT_BCC_CNTX jbt_bcc_context;

/***************************************************************************** 
* External Functions
*****************************************************************************/
extern kal_bool jbt_cmd_insert_queue(kal_uint8 opcode, kal_uint8 type, kal_uint8 *parms);

/***************************************************************************** 
* Functions
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  jbt_bcc_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_bcc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JBT_BCC_INIT);

    kal_mem_set((kal_uint8*) & jbt_bcc_context, 0, sizeof(JBT_BCC_CNTX));

}

/* cmd */


/*****************************************************************************
 * FUNCTION
 *  jbt_authorize_req_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_authorize_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_authorize *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_AUTHORIZE_REQ_CMD,
        jbt_bcc_context.jbt_authorize_req.operation_state,
        transaction_id,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }    
#endif /*__MVM__*/
    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_bcc_context.jbt_authorize_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_authorize_size = sizeof(jbt_bcc_authorize);
        kal_uint8 block_inx = 0;
        
        block_inx = jbt_malloc_block(jbt_bcc_authorize_size);
#ifndef JBT_SUPPORT_ADM_MEM        
        params_p = (jbt_bcc_authorize*) jvm_malloc(jbt_bcc_authorize_size);
#else
        params_p = (jbt_bcc_authorize*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_authorize_size);
#endif
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_authorize_size);
        }
        
        jbt_bcc_context.jbt_authorize_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        memcpy(params_p->bd_addr, addr, 6);
        jbt_bcc_context.jbt_authorize_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_AUTHORIZE, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_authorized_req_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_authorized_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_is_authorized *params_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_IS_AUTHORIZED_REQ_CMD,
        jbt_bcc_context.jbt_is_authorized_req.operation_state,
        transaction_id,
        addr[0],
        addr[1],
        addr[2],
        addr[3],
        addr[4],
        addr[5]);
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return KAL_FALSE;
    }    
#endif /*__MVM__*/
    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_bcc_context.jbt_is_authorized_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_is_authorized_size = sizeof(jbt_bcc_is_authorized);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_is_authorized_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_is_authorized*) jvm_malloc(jbt_bcc_is_authorized_size);
#else
        params_p = (jbt_bcc_is_authorized*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_is_authorized_size);
#endif
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_is_authorized_size);
        }
        jbt_bcc_context.jbt_is_authorized_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        memcpy(params_p->bd_addr, addr, 6);
        jbt_bcc_context.jbt_is_authorized_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_IS_AUTHORIZED, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_trusted_req_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_trusted_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_is_trusted *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_IS_TRUSTED_REQ_CMD,
        jbt_bcc_context.jbt_is_trusted_req.operation_state,
        transaction_id,
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

    if (jbt_bcc_context.jbt_is_trusted_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_is_trusted_size = sizeof(jbt_bcc_is_trusted);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_is_trusted_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_is_trusted*) jvm_malloc(jbt_bcc_is_trusted_size);
#else
        params_p = (jbt_bcc_is_trusted*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_is_trusted_size);
#endif
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_is_trusted_size);
        }
        
        jbt_bcc_context.jbt_is_authorized_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        memcpy(params_p->bd_addr, addr, 6);
        jbt_bcc_context.jbt_is_trusted_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_IS_TRUSTED, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_host_security_mode_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_host_security_mode_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_get_host_security_mode *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_GET_HOST_SECURITY_MODE_REQ_CMD,
        jbt_bcc_context.jbt_get_host_security_mode_req.operation_state,
        transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    } 

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_bcc_context.jbt_get_host_security_mode_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_get_host_security_mode_size = sizeof(jbt_bcc_get_host_security_mode);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_get_host_security_mode_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_get_host_security_mode*) jvm_malloc(jbt_bcc_get_host_security_mode_size);
#else
        params_p = (jbt_bcc_get_host_security_mode*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_get_host_security_mode_size);    
#endif

        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_get_host_security_mode_size);
        }
        jbt_bcc_context.jbt_get_host_security_mode_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        jbt_bcc_context.jbt_is_trusted_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_GET_HOST_SECURITY_MODE, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_device_count_req_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_device_count_req_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_get_preknown_device_count *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_GET_PREKNOWN_DEV_COUNT_REQ_CMD,
        jbt_bcc_context.jbt_get_preknown_device_count_req.operation_state,
        transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    } 

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_bcc_context.jbt_get_preknown_device_count_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_get_preknown_device_count_size = sizeof(jbt_bcc_get_preknown_device_count);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_get_preknown_device_count_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_get_preknown_device_count*) jvm_malloc(jbt_bcc_get_preknown_device_count_size);
#else
        params_p = (jbt_bcc_get_preknown_device_count*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_get_preknown_device_count_size);
#endif
        
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_get_preknown_device_count_size);
        }
        jbt_bcc_context.jbt_get_preknown_device_count_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        jbt_bcc_context.jbt_get_preknown_device_count_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(
            JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICE_COUNT,
            JBT_STACK_CMD_CONCURRENT,
            (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_devices_req_cmd
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_devices_req_cmd(kal_int32 transaction_id, kal_uint8* status_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_get_preknown_devices *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_GET_PREKNOWN_DEV_REQ_CMD,
        jbt_bcc_context.jbt_get_preknown_devices_req.operation_state,
        transaction_id);

    if (jam_is_minimize_mode())
    {   
        *status_result = JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        return result;
    }

    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }

    if (jbt_bcc_context.jbt_get_preknown_devices_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_get_preknown_devices_size = sizeof(jbt_bcc_get_preknown_devices);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_get_preknown_devices_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_get_preknown_devices*) jvm_malloc(jbt_bcc_get_preknown_devices_size);
#else
        params_p = (jbt_bcc_get_preknown_devices*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_get_preknown_devices_size);
#endif
        
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_get_preknown_devices_size);
        }
        jbt_bcc_context.jbt_get_preknown_devices_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        jbt_bcc_context.jbt_get_preknown_devices_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICES, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif
        result = KAL_TRUE;
    }
    return result;

}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_native_pwr_status_req_cmd
 * DESCRIPTION
 *  This function is to get power status of native Bluetooth
 * PARAMETERS
 *  transaction_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_native_pwr_status_req_cmd(kal_int32 transaction_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    jbt_bcc_get_native_pwr_status *params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_GET_NATIVE_PWR_STATUS_REQ_CMD,
        jbt_bcc_context.jbt_get_native_pwr_status_req.operation_state,
        transaction_id);

	/*
    if (jbt_general_non_poweron_reject())
    {
        return KAL_FALSE;
    }
    */

    if (jbt_bcc_context.jbt_get_native_pwr_status_req.operation_state == JBT_OPERATION_STATE_NONE)
    {
        kal_uint32 jbt_bcc_get_native_pwr_status_size = sizeof(jbt_bcc_get_native_pwr_status);
        kal_uint8 block_inx = 0;

        block_inx = jbt_malloc_block(jbt_bcc_get_native_pwr_status_size);
#ifndef JBT_SUPPORT_ADM_MEM
        params_p = (jbt_bcc_get_native_pwr_status*) jvm_malloc(jbt_bcc_get_native_pwr_status_size);
#else
        params_p = (jbt_bcc_get_native_pwr_status*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_get_native_pwr_status_size);
#endif
        
        if (params_p == 0)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            return result;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params_p, jbt_bcc_get_native_pwr_status_size);
        }
        jbt_bcc_context.jbt_get_native_pwr_status_req.operation_state = JBT_OPERATION_STATE_ONGOING;
        params_p->transaction_id = transaction_id;
        jbt_bcc_context.jbt_get_native_pwr_status_req.transaction_id = transaction_id;
        jbt_cmd_insert_queue(JBT_CMDCODE_BCC_GET_NATIVE_PWR_STATUS, JBT_STACK_CMD_CONCURRENT, (kal_uint8*) params_p);
        jbt_free_record((kal_uint8*) params_p);
#ifndef JBT_SUPPORT_ADM_MEM        
        jvm_free((kal_uint8*) params_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params_p);
#endif        
        result = KAL_TRUE;
    }
    return result;

}



/*****************************************************************************
 * FUNCTION
 *  jbt_authorize_req_cmd_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_authorize_req_cmd_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_authorize_req_struct *msg_p;
    jbt_bcc_authorize *info_p = (jbt_bcc_authorize*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_authorize_req.transaction_id = info_p->transaction_id;
    msg_p = (mmi_bt_bcc_authorize_req_struct*) construct_local_para(sizeof(mmi_bt_bcc_authorize_req_struct), TD_CTRL);
    /* init local parameters */
    jbt_ConvertToBdAddr((btbm_bd_addr_t*) & msg_p->dev_addr, info_p->bd_addr);

    jbt_send_msg(MSG_ID_MMI_BT_BCC_AUTHORIZE_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, (local_para_struct*) msg_p, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_authorized_req_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_authorized_req_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_is_authorized_req_struct *msg_p;
    jbt_bcc_is_authorized *info_p = (jbt_bcc_is_authorized*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_is_authorized_req.transaction_id = info_p->transaction_id;
    msg_p = (mmi_bt_bcc_is_authorized_req_struct*) construct_local_para(
                                                    sizeof(mmi_bt_bcc_is_authorized_req_struct),
                                                    TD_CTRL);
    /* init local parameters */
    jbt_ConvertToBdAddr((btbm_bd_addr_t*) & msg_p->dev_addr, info_p->bd_addr);

    jbt_send_msg(
        MSG_ID_MMI_BT_BCC_IS_AUTHORIZED_REQ,
        MOD_JASYN,
        MOD_MMI,
        J2ME_MMI_SAP,
        (local_para_struct*) msg_p,
        NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_trusted_req_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_trusted_req_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bcc_is_trusted_req_struct *msg_p;
    jbt_bcc_is_trusted *info_p = (jbt_bcc_is_trusted*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_is_authorized_req.transaction_id = info_p->transaction_id;
    msg_p = (mmi_bt_bcc_is_trusted_req_struct*) construct_local_para(
                                                    sizeof(mmi_bt_bcc_is_trusted_req_struct),
                                                    TD_CTRL);
    /* init local parameters */
    jbt_ConvertToBdAddr((btbm_bd_addr_t*) & msg_p->dev_addr, info_p->bd_addr);

    jbt_send_msg(MSG_ID_MMI_BT_BCC_IS_TRUSTED_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, (local_para_struct*) msg_p, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_host_security_mode_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_host_security_mode_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_bcc_get_host_security_mode *info_p = (jbt_bcc_get_host_security_mode*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_get_host_security_mode_req.transaction_id = info_p->transaction_id;

    jbt_send_msg(MSG_ID_MMI_BT_BCC_GET_HOST_SECURITY_MODE_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, NULL, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_device_count_req_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_device_count_req_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_bcc_get_preknown_device_count *info_p = (jbt_bcc_get_preknown_device_count*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_get_preknown_device_count_req.transaction_id = info_p->transaction_id;

    jbt_send_msg(MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICE_COUNT_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, NULL, NULL);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_devices_req_body
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_devices_req_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_bcc_get_preknown_devices *info_p = (jbt_bcc_get_preknown_devices*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_get_preknown_devices_req.transaction_id = info_p->transaction_id;

    jbt_send_msg(MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICES_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, NULL, NULL);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_native_pwr_status_req_cmd_body
 * DESCRIPTION
 *  This function is to get the power status of native Bluetooth
 * PARAMETERS
 *  params_p        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_native_pwr_status_req_cmd_body(void *params_p)
{
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jbt_bcc_get_native_pwr_status *info_p = (jbt_bcc_get_native_pwr_status*) params_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_bcc_context.jbt_get_native_pwr_status_req.transaction_id = info_p->transaction_id;

    jbt_send_msg(MSG_ID_MMI_BT_BCC_GET_NATIVE_PWR_STATUS_REQ, MOD_JASYN, MOD_MMI, J2ME_MMI_SAP, NULL, NULL);

    return KAL_TRUE;
}

/* result */


/*****************************************************************************
 * FUNCTION
 *  jbt_authorize_req_cmd_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_authorize_req_cmd_result(mmi_bt_bcc_authorize_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_authorize_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.result = msg_p->result;
    transaction_id = jbt_bcc_context.jbt_authorize_req.transaction_id;
    jbt_ConvertBdAddr(params.bd_addr, (btbm_bd_addr_t*) & msg_p->dev_addr);
    jbt_bcc_context.jbt_authorize_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_authorize_req.transaction_id = 0;

    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_AUTHORIZE_REQ_CMD_RESULT,
        params.result,
        transaction_id,
        params.bd_addr[0],
        params.bd_addr[1],
        params.bd_addr[2],
        params.bd_addr[3],
        params.bd_addr[4],
        params.bd_addr[5]);

    jbt_event_callback(JBT_OPCODE_BCC_AUTHORIZE, transaction_id, &params);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_authorized_req_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_authorized_req_result(mmi_bt_bcc_is_authorized_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_is_authorized_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.result = msg_p->result;
    transaction_id = jbt_bcc_context.jbt_is_authorized_req.transaction_id;
    jbt_ConvertBdAddr(params.bd_addr, (btbm_bd_addr_t*) & msg_p->dev_addr);
    jbt_bcc_context.jbt_is_authorized_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_is_authorized_req.transaction_id = 0;

    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_IS_AUTHORIZED_REQ_CMD_RESULT,
        params.result,
        transaction_id,
        params.bd_addr[0],
        params.bd_addr[1],
        params.bd_addr[2],
        params.bd_addr[3],
        params.bd_addr[4],
        params.bd_addr[5]);

    jbt_event_callback(JBT_OPCODE_BCC_IS_AUTHORIZED, transaction_id, &params);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_is_trusted_req_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_is_trusted_req_result(mmi_bt_bcc_is_trusted_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_is_trusted_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.result = msg_p->result;
    transaction_id = jbt_bcc_context.jbt_is_trusted_req.transaction_id;
    jbt_ConvertBdAddr(params.bd_addr, (btbm_bd_addr_t*) & msg_p->dev_addr);
    jbt_bcc_context.jbt_is_trusted_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_is_trusted_req.transaction_id = 0;

    kal_trace(
        TRACE_FUNC,
        FUNC_JBT_BCC_IS_TRUSTED_REQ_CMD_RESULT,
        params.result,
        transaction_id,
        params.bd_addr[0],
        params.bd_addr[1],
        params.bd_addr[2],
        params.bd_addr[3],
        params.bd_addr[4],
        params.bd_addr[5]);

    jbt_event_callback(JBT_OPCODE_BCC_IS_TRUSTED, transaction_id, &params);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_host_security_mode_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_host_security_mode_result(mmi_bt_bcc_get_host_security_mode_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_get_host_security_mode_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.security_mode = msg_p->security_mode;
    transaction_id = jbt_bcc_context.jbt_get_host_security_mode_req.transaction_id;
    jbt_bcc_context.jbt_get_host_security_mode_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_get_host_security_mode_req.transaction_id = 0;

    kal_trace(TRACE_FUNC, FUNC_JBT_BCC_GET_HOST_SECURITY_MODE_REQ_CMD_RESULT, params.security_mode, transaction_id);

    jbt_event_callback(JBT_OPCODE_BCC_GET_HOST_SECURITY_MODE, transaction_id, &params);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_device_count_req_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_device_count_req_result(mmi_bt_bcc_get_preknown_device_count_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_get_preknown_device_count_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.dev_count = msg_p->device_count;
    transaction_id = jbt_bcc_context.jbt_get_preknown_device_count_req.transaction_id;
    jbt_bcc_context.jbt_get_preknown_device_count_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_get_preknown_device_count_req.transaction_id = 0;

    kal_trace(TRACE_FUNC, FUNC_JBT_BCC_GET_PREKNOWN_DEV_COUNT_REQ_CMD_RESULT, params.dev_count, transaction_id);

    jbt_event_callback(JBT_OPCODE_BCC_GET_PREKNOWN_DEVICE_COUNT, transaction_id, &params);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_preknown_devices_req_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_preknown_devices_req_result(mmi_bt_bcc_get_preknown_devices_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    kal_uint32 i;
    jbt_bcc_get_preknown_devices_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_p->device_count != 0)
    {
        kal_uint32 jbt_bcc_dev_info_size = sizeof(jbt_bcc_dev_info_struct) * (msg_p->device_count);
        kal_uint8 block_inx = 0;
        
        block_inx = jbt_malloc_block(jbt_bcc_dev_info_size);

#ifndef JBT_SUPPORT_ADM_MEM
        params.preknown_dev_p =
            (jbt_bcc_dev_info_struct*) jvm_malloc(jbt_bcc_dev_info_size);
#else
        params.preknown_dev_p =
            (jbt_bcc_dev_info_struct*) kal_adm_alloc(jbt_get_mem_pool_id(),jbt_bcc_dev_info_size);
#endif
        
        if (params.preknown_dev_p == NULL)
        {
            /* Failed of jvm_malloc() */
            jbt_free_block(block_inx);
            params.device_count = 0;
        }
        else
        {
            jbt_malloc_record(block_inx, (kal_uint8*)params.preknown_dev_p, jbt_bcc_dev_info_size);
            params.device_count = msg_p->device_count;
        }

    }
    
    for (i = 0; i < params.device_count; i++)
    {
        /* cod */
        params.preknown_dev_p[i].cod = msg_p->preknown_dev_p[i].cod;
        /* name */
        memcpy((params.preknown_dev_p[i].name), (msg_p->preknown_dev_p[i].name), MMI_BT_BCC_MAX_HOST_DEV_NAME_LEN);
        /* address */
        jbt_ConvertBdAddr(params.preknown_dev_p[i].bd_addr, (btbm_bd_addr_t*) & msg_p->preknown_dev_p[i].bd_addr);
    }

    transaction_id = jbt_bcc_context.jbt_get_preknown_devices_req.transaction_id;
    jbt_bcc_context.jbt_get_preknown_devices_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_get_preknown_devices_req.transaction_id = 0;

    kal_trace(TRACE_FUNC, FUNC_JBT_BCC_GET_PREKNOWN_DEV_REQ_CMD_RESULT, params.device_count, transaction_id);

    jbt_event_callback(JBT_OPCODE_BCC_GET_PREKNOWN_DEVICES, transaction_id, &params);
    if (params.preknown_dev_p != NULL)
    {
        jbt_free_record((kal_uint8*) params.preknown_dev_p);
#ifndef JBT_SUPPORT_ADM_MEM
        jvm_free((kal_uint8*) params.preknown_dev_p);
#else
        kal_adm_free(jbt_get_mem_pool_id(),(kal_uint8*) params.preknown_dev_p);
#endif
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_native_pwr_status_req_result
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg_p       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jbt_get_native_pwr_status_req_result(mmi_bt_bcc_get_native_pwr_status_cnf_struct *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_bcc_get_native_pwr_status_result params;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    params.native_pwr_status = msg_p->native_pwr_status;
    transaction_id = jbt_bcc_context.jbt_get_native_pwr_status_req.transaction_id;
    jbt_bcc_context.jbt_get_native_pwr_status_req.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_bcc_context.jbt_get_native_pwr_status_req.transaction_id = 0;

    kal_trace(TRACE_FUNC, FUNC_JBT_BCC_GET_NATIVE_PWR_STATUS_REQ_CMD_RESULT, params.native_pwr_status, transaction_id);

    jbt_event_callback(JBT_OPCODE_BCC_GET_NATIVE_PWR_STATUS, transaction_id, &params);
    return KAL_TRUE;
}

#endif /* __SUPPORT_JBT__ */ 

