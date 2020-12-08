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
#ifndef _JBT_SDAP_C
#define _JBT_SDAP_C

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


JBT_SDAP_CNTX jbt_sdap_context;


/*****************************************************************************
 * FUNCTION
 *  jbt_sdap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_sdap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_SDAP_INIT);
    kal_mem_set((kal_uint8*) & jbt_sdap_context, 0, sizeof(jbt_sdap_context));
}


/*****************************************************************************
 * FUNCTION
 *  jbt_get_sdp_delay_ticks
 * DESCRIPTION
 *  This function is provided for VM Porting Layer to invoke
 *  To delay each a new sdp request of another peer device from VM after it receives a sdp response of current peer device
 *  The return ticks value is 120 ticks:
 *  due to the acl link of current peer device will be started to terminated after 500ms(about 108 ticks) of end of  current sdp session
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jbt_get_sdp_delay_ticks()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JBT_DELAY_SDP_TICKS;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdap_ss_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 *  uuid                [IN]        
 *  uuid_no             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_sdap_ss_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint16 uuid[], kal_uint16 uuid_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    bt_bm_search_raw_req_struct *msg = 0;
    kal_uint8 i = 0;
    kal_uint8 *raw_buffer = 0;
    kal_uint16 offset = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SDAP_SS_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X, addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_SIZEx02X, uuid_no);
    {
        kal_uint16 i = 0;

        for (i = 0; i < uuid_no; i++)
        {
            kal_trace(TRACE_JBT_GROUP, JBT_UUIDx04X, uuid[i]);
        }
    }
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
#endif /*__MVM__*/
    if (jbt_check_inquiry_operation_ongoing())
    {
        return JBT_CMD_REJECT_DUE_TO_INQUIRY;
    }
    
    if (uuid_no == 0)
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_sdap_context.jbt_service_search.operation_state == JBT_OPERATION_STATE_NONE)
    {
        if (uuid_no > BT_MAX_SDAP_UUID_NO)
        {
            result = JBT_CMD_SIZE_TOO_LARGE;
        }
        else
        {
            kal_uint8 block_inx = 0;
            block_inx = jbt_malloc_block(BT_MAX_SDAP_RAW_SIZE * 3);
#ifndef JBT_SUPPORT_ADM_MEM
            raw_buffer = (kal_uint8*)jvm_malloc(BT_MAX_SDAP_RAW_SIZE * 3);
#else
            raw_buffer = (kal_uint8*)kal_adm_alloc(jbt_get_mem_pool_id(),BT_MAX_SDAP_RAW_SIZE * 3);
#endif
            if (raw_buffer != NULL)
            {
                jbt_malloc_record(block_inx, raw_buffer, BT_MAX_SDAP_RAW_SIZE * 3);
            }
            else
            {
                /* Failed of jvm_malloc() */
                jbt_free_block(block_inx);
                result = JBT_CMD_REJECT_NO_RESOURCE;
                return result;
            }            
            
            /* 0x35: Data Element Sequence */
            raw_buffer[0] = 0x35;
            /* Each UUID needs 3 bytes to present (if UUID-16 is used) and its first byte always be 0x19  */
            raw_buffer[1] = uuid_no * 3;
            offset = 2;
            for (i = 0; i < uuid_no; i++)
            {
                raw_buffer[offset] = 0x19;
                raw_buffer[offset + 1] = ((U16) uuid[i] & 0xFF00) >> 8;
                raw_buffer[offset + 2] = ((U16) uuid[i] & 0x00FF);
                offset += 3;
            }

            if (offset > BT_MAX_SDAP_RAW_SIZE)
            {
                jbt_free_record(raw_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free(raw_buffer);
#else
                kal_adm_free(jbt_get_mem_pool_id(),raw_buffer); 
#endif
                return JBT_CMD_SIZE_TOO_LARGE;

            }
            jbt_sdap_context.jbt_service_search.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_sdap_context.jbt_service_search.transaction_id = transaction_id;
            jbt_sdap_context.search_result_size = 0;
            msg = (bt_bm_search_raw_req_struct*) construct_local_para(sizeof(bt_bm_search_raw_req_struct), TD_CTRL);

            jbt_ConvertToBdAddr(&msg->bd_addr, addr);
            msg->search_type = 0x00;    /* Service Search */
            memset(msg->search_pattern, 0, sizeof(msg->search_pattern));
            memcpy(msg->search_pattern, raw_buffer, offset);
            jbt_free_record(raw_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(raw_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),raw_buffer); 
#endif            
            msg->search_pattern_size = offset;
            jbt_send_msg(MSG_ID_BT_BM_SEARCH_RAW_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

            result = JBT_CMD_SUCCESS;
        }
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdap_sa_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 *  record_hdl          [IN]        
 *  attribute           [IN]        
 *  attribute_no        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_sdap_sa_cmd(
            kal_int32 transaction_id,
            kal_uint8 *addr,
            kal_uint32 record_hdl,
            kal_uint16 attribute[],
            kal_uint16 attribute_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    bt_bm_search_raw_req_struct *msg = 0;
    kal_uint8 i = 0;
    kal_uint8 *raw_buffer = 0;
    kal_uint16 offset = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SDAP_SA_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X, addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_SIZEx02X, attribute_no);
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_SDAP_SA_RECORD_HANDLERx08X, record_hdl);
    for (i = 0; i < attribute_no; i++)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_UUIDx04X, attribute[i]);
    }
#ifndef __MVM__
    if (jam_is_minimize_mode())
    {   
        return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
    }
#endif /*__MVM__*/
    if (jbt_check_inquiry_operation_ongoing())
    {
        return JBT_CMD_REJECT_DUE_TO_INQUIRY;
    }
    
    if (attribute_no == 0)
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_sdap_context.jbt_service_search.operation_state == JBT_OPERATION_STATE_NONE)
    {
        if (attribute_no > BT_MAX_SDAP_UUID_NO)
        {
            result = JBT_CMD_SIZE_TOO_LARGE;
        }
        else
        {
            kal_uint8 block_inx = 0;
            block_inx = jbt_malloc_block(BT_MAX_SDAP_RAW_SIZE * 3);
#ifndef JBT_SUPPORT_ADM_MEM
            raw_buffer = (kal_uint8*)jvm_malloc(BT_MAX_SDAP_RAW_SIZE * 3);
#else
            raw_buffer = (kal_uint8*)kal_adm_alloc(jbt_get_mem_pool_id(),BT_MAX_SDAP_RAW_SIZE * 3);
#endif
            if (raw_buffer != NULL)
            {
                jbt_malloc_record(block_inx, raw_buffer, BT_MAX_SDAP_RAW_SIZE * 3);
            }
            else
            {
                /* Failed of jvm_malloc() */
                jbt_free_block(block_inx);
                result = JBT_CMD_REJECT_NO_RESOURCE;
                return result;
            }
            
            /* Modify 2007-1216: highest byte of service record handle must be inx 0 */
            raw_buffer[3] = (U8) record_hdl;
            raw_buffer[2] = (U8) (record_hdl >> 8);
            raw_buffer[1] = (U8) (record_hdl >> 16);
            raw_buffer[0] = (U8) (record_hdl >> 24);
            /* raw_buffer[4] and raw_buffer[5] are two bytes: maximum attribute byte count 0x0064 --> max 100 bytes */
            raw_buffer[4] = 0x00;
            raw_buffer[5] = 0x64;
            /* AttributeIDList: Data Element Sequence: 0x35 */
            raw_buffer[6] = 0x35;
            raw_buffer[7] = attribute_no * 3;
            offset += 8;
            for (i = 0; i < attribute_no; i++)
            {
                /* Each attributeID is an 16-bits unsigned integer: 0b00001 (type descriptor: unsigned integer) 0b001(size descriptor: 2bytes) -> 0x09 :modified by mtk01411 2007-1122 */
                raw_buffer[offset] = 0x09;
                raw_buffer[offset + 1] = ((U16) attribute[i] & 0xFF00) >> 8;
                raw_buffer[offset + 2] = ((U16) attribute[i] & 0x00FF);
                offset += 3;
            }

            if (offset > BT_MAX_SDAP_RAW_SIZE)
            {
                jbt_free_record(raw_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free(raw_buffer);
#else
                kal_adm_free(jbt_get_mem_pool_id(),raw_buffer);
#endif
                return JBT_CMD_SIZE_TOO_LARGE;
            }
            jbt_sdap_context.jbt_service_search.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_sdap_context.jbt_service_search.transaction_id = transaction_id;
            jbt_sdap_context.search_result_size = 0;
            msg = (bt_bm_search_raw_req_struct*) construct_local_para(sizeof(bt_bm_search_raw_req_struct), TD_CTRL);

            jbt_ConvertToBdAddr(&msg->bd_addr, addr);
            msg->search_type = 0x01;    /* Service Attribute: modified by mtk01411 2007-1122 */
            memset(msg->search_pattern, 0, sizeof(msg->search_pattern));
            memcpy(msg->search_pattern, raw_buffer, offset);
            jbt_free_record(raw_buffer);

#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(raw_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),raw_buffer);
#endif
            msg->search_pattern_size = offset;
            jbt_send_msg(MSG_ID_BT_BM_SEARCH_RAW_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);

            result = JBT_CMD_SUCCESS;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_sdap_ssa_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  transaction_id      [IN]        
 *  addr                [IN]        
 *  uuid                [IN]        
 *  uuid_no             [IN]        
 *  attribute           [IN]        
 *  attribute_no        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_sdap_ssa_cmd(kal_int32 transaction_id, kal_uint8 *addr,
#ifdef __JBT_SUPPORT_UUID16__
                           kal_uint16 uuid[],
#elif defined(__JBT_SUPPORT_UUID32__)
                           kal_uint32 uuid[],
#else /*  UUID128 version */
                           kal_uint8 uuid[],
#endif 
                           kal_uint16 uuid_no, kal_uint16 attribute[], kal_uint16 attribute_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result = JBT_CMD_WRONG_STATE;
    bt_bm_search_raw_req_struct *msg = 0;
    kal_uint8 i = 0;
    kal_uint8 *raw_buffer = 0;
    kal_uint16 offset = 0;
    kal_int32 vm_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_SDAP_SSA_CMD);
    kal_trace(TRACE_JBT_GROUP, JBT_TRANSACTION_IDx08X, transaction_id);
    kal_trace(TRACE_JBT_GROUP, JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X, addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);
    kal_trace(TRACE_JBT_GROUP, JBT_SIZEx02X, uuid_no);

    for (i = 0; i < uuid_no; i++)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_UUIDx04X, uuid[i]);
    }
    kal_trace(TRACE_JBT_GROUP, JBT_SIZEx02X, attribute_no);
    for (i = 0; i < attribute_no; i++)
    {
        kal_trace(TRACE_JBT_GROUP, JBT_UUIDx04X, attribute[i]);
    }

#ifndef __MVM__
        if (jam_is_minimize_mode())
        {   
            return JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE;
        }
#endif /*__MVM__*/

    if (jbt_check_inquiry_operation_ongoing())
    {
        return JBT_CMD_REJECT_DUE_TO_INQUIRY;
    }
    
    if (uuid_no == 0)
    {
        return JBT_CMD_FAILED;
    }
    if (attribute_no == 0)
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_general_non_poweron_reject())
    {
        return JBT_CMD_FAILED;
    }

    if (jbt_sdap_context.jbt_service_search.operation_state == JBT_OPERATION_STATE_NONE)
    {
        if ((uuid_no > BT_MAX_SDAP_UUID_NO) || (attribute_no > BT_MAX_SDAP_UUID_NO))
        {
            result = JBT_CMD_SIZE_TOO_LARGE;
        }
        else
        {
            kal_uint8 block_inx = 0;
            block_inx = jbt_malloc_block(BT_MAX_SDAP_RAW_SIZE * 3);
#ifndef JBT_SUPPORT_ADM_MEM
            raw_buffer = (kal_uint8*)jvm_malloc(BT_MAX_SDAP_RAW_SIZE * 3);
#else
            raw_buffer = (kal_uint8*)kal_adm_alloc(jbt_get_mem_pool_id(),BT_MAX_SDAP_RAW_SIZE * 3);
#endif
            if (raw_buffer != NULL)
            {
                jbt_malloc_record(block_inx, raw_buffer, BT_MAX_SDAP_RAW_SIZE * 3);
            }
            else
            {
                /* Failed of jvm_malloc() */
                jbt_free_block(block_inx);
                result = JBT_CMD_REJECT_NO_RESOURCE;
                return result;
            }
            
            /* 0x35: Data Element Sequence */
            raw_buffer[0] = 0x35;
        #ifdef __JBT_SUPPORT_UUID16__
            /* UUID16 version */
            raw_buffer[1] = uuid_no * 3;
        #elif defined(__JBT_SUPPORT_UUID32__)
            /* UUID32 version */
            raw_buffer[1] = uuid_no * 5;    /* 1 byte + 4bytes UUID */
        #else 
            /* UUID128 version */
            raw_buffer[1] = uuid_no * 17;   /* 1 byte + 16bytes UUID */
        #endif 
            offset = 2;
            for (i = 0; i < uuid_no; i++)
            {

            #ifdef __JBT_SUPPORT_UUID16__
                /* UUID16 version */
                raw_buffer[offset] = 0x19;
                raw_buffer[offset + 1] = ((U16) uuid[i] & 0xFF00) >> 8;
                raw_buffer[offset + 2] = ((U16) uuid[i] & 0x00FF);
                offset += 3;

            #elif defined(__JBT_SUPPORT_UUID32__)
                raw_buffer[offset] = 0x1A;
                raw_buffer[offset + 1] = ((U32) uuid[i] & 0xFF000000) >> 24;
                raw_buffer[offset + 2] = ((U32) uuid[i] & 0x00FF0000) >> 16;
                raw_buffer[offset + 3] = ((U32) uuid[i] & 0x0000FF00) >> 8;
                raw_buffer[offset + 4] = ((U32) uuid[i] & 0x000000FF);
                offset += 5;
            #else 
                /* UUID128 version */
                raw_buffer[offset] = 0x1C;
                {
                    int j = 0;

                    for (j = 0; j < 16; j++)
                    {
                        raw_buffer[offset + 1 + j] = uuid[i * 16 + j];
                    }

                    offset += 17;
                }
            #endif 
                /*
                 * raw_buffer[offset+1] = ((U32)uuid[i] & 0xFF000000000000000000000000000000) >> 120;
                 * raw_buffer[offset+2] = ((U32)uuid[i] & 0x00FF0000000000000000000000000000) >> 112;
                 * raw_buffer[offset+3] = ((U32)uuid[i] & 0x0000FF00000000000000000000000000) >> 104;
                 * raw_buffer[offset+4] = ((U32)uuid[i] & 0x000000FF000000000000000000000000) >> 96;
                 * raw_buffer[offset+5] = ((U32)uuid[i] & 0x00000000FF0000000000000000000000) >> 88;
                 * raw_buffer[offset+6] = ((U32)uuid[i] & 0x0000000000FF00000000000000000000) >> 80;
                 * raw_buffer[offset+7] = ((U32)uuid[i] & 0x000000000000FF000000000000000000) >> 72;
                 * raw_buffer[offset+8] = ((U32)uuid[i] & 0x00000000000000FF0000000000000000) >> 64;
                 * raw_buffer[offset+9] = ((U32)uuid[i] & 0x0000000000000000FF00000000000000) >> 56;
                 * raw_buffer[offset+10] = ((U32)uuid[i] & 0x000000000000000000FF000000000000) >> 48;
                 * raw_buffer[offset+11] = ((U32)uuid[i] & 0x00000000000000000000FF0000000000) >> 40;
                 * raw_buffer[offset+12] = ((U32)uuid[i] & 0x0000000000000000000000FF00000000) >> 32;
                 * raw_buffer[offset+13] = ((U32)uuid[i] & 0x000000000000000000000000FF000000) >> 24;
                 * raw_buffer[offset+14] = ((U32)uuid[i] & 0x00000000000000000000000000FF0000) >> 16;
                 * raw_buffer[offset+15] = ((U32)uuid[i] & 0x0000000000000000000000000000FF00) >> 8;
                 * raw_buffer[offset+16] = ((U32)uuid[i] & 0x000000000000000000000000000000FF);
                 */
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
            #endif /* 0 */ 

            }
            /* 0x0064: 100 bytes: Maximum Attribute Byte Count */
            raw_buffer[offset] = 0x00;
            raw_buffer[offset + 1] = 0x64;
            offset += 2;
            raw_buffer[offset] = 0x35;
            raw_buffer[offset + 1] = attribute_no * 3;
            offset += 2;
            for (i = 0; i < attribute_no; i++)
            {
                /* 0b00001 (type descriptor: unsigned integer) 0b001 (size descriptor: 2bytes data) --> 0x09 */
                raw_buffer[offset] = 0x09;
                raw_buffer[offset + 1] = ((U16) attribute[i] & 0xFF00) >> 8;
                raw_buffer[offset + 2] = ((U16) attribute[i] & 0x00FF);
                offset += 3;
            }

            if (offset > BT_MAX_SDAP_RAW_SIZE)
            {
                jbt_free_record(raw_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free(raw_buffer);
#else
                kal_adm_free(jbt_get_mem_pool_id(),raw_buffer);
#endif
                return JBT_CMD_SIZE_TOO_LARGE;
            }
            jbt_sdap_context.jbt_service_search.operation_state = JBT_OPERATION_STATE_ONGOING;
            jbt_sdap_context.jbt_service_search.transaction_id = transaction_id;
            jbt_sdap_context.search_result_size = 0;
            msg = (bt_bm_search_raw_req_struct*) construct_local_para(sizeof(bt_bm_search_raw_req_struct), TD_CTRL);
            /* Convert address after construct this local para: 2007-1129 */
            jbt_ConvertToBdAddr(&msg->bd_addr, addr);
            msg->search_type = 0x02;    /* Service Search Attribute */
            memset(msg->search_pattern, 0, sizeof(msg->search_pattern));
            memcpy(msg->search_pattern, raw_buffer, offset);
            jbt_free_record(raw_buffer);
#ifndef JBT_SUPPORT_ADM_MEM
            jvm_free(raw_buffer);
#else
            kal_adm_free(jbt_get_mem_pool_id(),raw_buffer);
#endif            
            msg->search_pattern_size = offset;
            jbt_send_msg(MSG_ID_BT_BM_SEARCH_RAW_REQ, MOD_JASYN, MOD_BT, BT_APP_SAP, (local_para_struct*) msg, NULL);
        
            result = JBT_CMD_SUCCESS;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_sdap_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_sdap_result(bt_bm_search_raw_result_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_device_sdap_entry_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    transaction_id = jbt_sdap_context.jbt_service_search.transaction_id;
    jbt_ConvertBdAddr(parms.addr, &msg->bd_addr);
    parms.len = msg->len;
    kal_mem_cpy(parms.data, msg->data, msg->len);
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SDAP_RESULT);

    kal_trace(
        TRACE_JBT_GROUP,
        JBT_ADDRx02Xx02Xx02Xx02Xx02Xx02X,
        parms.data[0],
        parms.data[1],
        parms.data[2],
        parms.data[3],
        parms.data[4],
        parms.data[5]);

    kal_trace(TRACE_JBT_GROUP, JBT_MSGLENx02X, msg->len);
    {
        kal_uint16 i = 0;

        for (i = 0; i < (msg->len + 4); i += 4)
        {
            kal_trace(
                TRACE_JBT_GROUP,
                JBT_SDAP_SEARCH_PATTx02Xx02Xx02Xx02X,
                msg->data[i],
                msg->data[i + 1],
                msg->data[i + 2],
                msg->data[i + 3]);
        }
    }
    jbt_event_callback(JBT_OPCODE_SDAP_RESULT, transaction_id, &parms);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_handle_sdap_completed_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_handle_sdap_completed_result(bt_bm_search_raw_cnf_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 transaction_id;
    jbt_device_sdap_completed_result parms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_JBT_HANDLE_SDAP_COMPLETED_RESULT);

    transaction_id = jbt_sdap_context.jbt_service_search.transaction_id;
    jbt_ConvertBdAddr(parms.addr, &msg->bd_addr);
    jbt_sdap_context.jbt_service_search.operation_state = JBT_OPERATION_STATE_NONE;
    jbt_sdap_context.jbt_service_search.transaction_id = 0;
    parms.result = msg->result;
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_HANDLE_SDAP_COMPLETED_RESULT_PARMSRESULTx02X, parms.result);

    jbt_event_callback(JBT_OPCODE_SDAP_COMPLETED_RESULT, transaction_id, &parms);
}
#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_SDAP_C */ 

