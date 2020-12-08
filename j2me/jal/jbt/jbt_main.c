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
 * removed!
 * removed!
 * removed!
 *
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBT_MAIN_C
#define _JBT_MAIN_C

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
#include "jvm_interface.h"
#include "jbt_interface.h"
#include "jbt_internal.h"
#include "kal_adm.h" /* ADM header file */

JBT_CORE_CNTX jbt_context;
kal_semid jbt_queue_sem;

#ifdef JBT_SUPPORT_ADM_MEM
/* ADM Size = 100K */
#define JBT_ADM_MEM_SIZE (100*1024)
kal_uint8 jbt_custom_mem_pool[JBT_ADM_MEM_SIZE]; /* memory pool */
static const kal_uint32 jbt_subpool_size[11] = { 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0xffffffff, 0 };
#ifdef JBT_CREATE_ADM_INIT
KAL_ADM_ID jbt_adm_init_mem_pool_id;
#endif /* JBT_CREATE_ADM_INIT */
#endif /* JBT_SUPPORT_ADM_MEM */

/* Add by mtk01411: 2007-1023 for JSR82 SPP connection request testing */
kal_uint8 jsr82_ut_session_con_addr[6];
extern kal_uint8 jbt_ut_transaction_id;
extern JBT_SPP_CNTX jbt_spp_context;
extern JBT_L2CAP_CNTX jbt_l2cap_context;

extern void JbtEventCallback(kal_uint8 opcode, kal_uint32 transaction_id, void *parm);
extern kal_bool jbt_trigger_panic_mechanism_cmd(void);


/*****************************************************************************
 * FUNCTION
 *  jbt_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg             [IN]        
 *  srcMod          [IN]        
 *  dstMod          [IN]        
 *  sap             [IN]        
 *  local_para      [IN]        
 *  peer_buff       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_send_msg(
        msg_type msg,
        module_type srcMod,
        module_type dstMod,
        sap_type sap,
        local_para_struct *local_para,
        peer_buff_struct *peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilmPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilmPtr = allocate_ilm(MOD_JASYN);
    ilmPtr->msg_id = msg;
    ilmPtr->local_para_ptr = local_para;
    ilmPtr->peer_buff_ptr = peer_buff;
    ilmPtr->dest_mod_id = dstMod;
    ilmPtr->src_mod_id = srcMod;
    ilmPtr->sap_id = sap;
    msg_send_ext_queue(ilmPtr);
}

#ifdef JBT_SUPPORT_ADM_MEM
/*****************************************************************************
 * FUNCTION
 *  jbt_create_adm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_create_adm_pool()
{
    KAL_ADM_ID mem_pool_id = 0;
    /* Create ADM Pool here once it is in POWER_ON state */
    mem_pool_id = kal_adm_create((void*)jbt_custom_mem_pool, JBT_ADM_MEM_SIZE, (kal_uint32*)jbt_subpool_size, KAL_TRUE);
    jbt_set_mem_pool_id(mem_pool_id);
}

/*****************************************************************************
 * FUNCTION
 *  jbt_delete_adm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_delete_adm_pool()
{
    kal_status mem_free_status = KAL_ERROR;
    mem_free_status = kal_adm_delete(jbt_get_mem_pool_id());
    kal_trace(TRACE_JBT_GROUP, FUNC_JBT_ADM_DELETE_STATUS, mem_free_status);
    if (mem_free_status != KAL_SUCCESS)
    {
        kal_adm_print_log(jbt_get_mem_pool_id());
        ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  jbt_set_mem_pool_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jbt_mem_pool_id
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_set_mem_pool_id(KAL_ADM_ID jbt_mem_pool_id)
{
#ifndef JBT_CREATE_ADM_INIT
    jbt_context.mem_pool_id = jbt_mem_pool_id;
#else
    jbt_adm_init_mem_pool_id = jbt_mem_pool_id;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_mem_pool_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mem_pool_id
 *****************************************************************************/
KAL_ADM_ID jbt_get_mem_pool_id()
{
#ifndef JBT_CREATE_ADM_INIT
    return jbt_context.mem_pool_id;
#else
    return jbt_adm_init_mem_pool_id;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_adm_mem_start_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  start_addr_ptr
 *****************************************************************************/
kal_uint8* jbt_get_adm_mem_start_addr()
{
    return jbt_custom_mem_pool;
}

/*****************************************************************************
 * FUNCTION
 *  jbt_get_adm_mem_end_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  end_addr_ptr
 *****************************************************************************/
kal_uint8* jbt_get_adm_mem_end_addr()
{
    return (jbt_custom_mem_pool+JBT_ADM_MEM_SIZE-1);
}
#endif /* JBT_SUPPORT_ADM_MEM */


/*****************************************************************************
 * FUNCTION
 *  jbt_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JBT_INITIALIZE);
    kal_mem_set((kal_uint8*) & jbt_context, 0, sizeof(jbt_context));
    jbt_gap_init();
    jbt_bcc_init();
    jbt_sdpdb_init();
    jbt_sdap_init();
    jbt_spp_init();
    jbt_l2cap_init();
    jbt_cmd_queue_init();
    jbt_context.jbtEventCb = 0;
#if JBT_UT
    jbt_event_registration(JbtEventCallback);
#endif

#ifdef JBT_SUPPORT_ADM_MEM
#ifdef JBT_CREATE_ADM_INIT
    {
        ADM_CB *adm_cb = (ADM_CB*)jbt_adm_init_mem_pool_id;
        if (adm_cb!=NULL && adm_cb->adm_id == ADM_ID)
        {
            kal_trace(TRACE_JBT_GROUP,FUNC_JBT_ADM_ALREADY_CREATE_INIT);
        }
        else
        {
            jbt_create_adm_pool();
            kal_trace(TRACE_JBT_GROUP,FUNC_JBT_ADM_CREATE_INIT);
        }
    }
#endif /* JBT_CREATE_ADM_INIT */
#endif /* JBT_SUPPORT_ADM_MEM */

}

kal_uint8 bt_search_pattern[] = 
{
    0x35,
    9,
    0x19,
    0x11, 0x01,
    0x19,
    0x00, 0x03,
    0x19,
    0x01, 0x00,
    0x00, 0x64,
    0x35,
    3,
    0x09,
    0x00, 0x04
};


/*****************************************************************************
 * FUNCTION
 *  jbt_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_BT_JSR_TEST_CMD1_REQ:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_TEST_CMD1_REQ);
            /* Get SDP Record Handler before registration a new sdp record */
            jbt_get_record_handle_cmd(101);
            break;
        case MSG_ID_BT_JSR_TEST_CMD2_REQ:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_TEST_CMD2_REQ);
            /* Deregistration SDP record with its corresponding record handler */
            jbt_deregister_record_cmd(102, 0x00010030);
            break;
        case MSG_ID_BT_JSR_KICK_NEW_COMMAND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_KICK_NEW_COMMAND);
            jbt_cmd_kick_check_list_done();
            kal_trace(TRACE_JBT_GROUP, JBT_JBT_CMD_KICK_CHECK_LIST_DONE);
            jbt_cmd_queue_nonconcurrent_processing();
            break;
        case MSG_ID_BT_JSR_POWER_OFF_REQ:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_POWER_OFF_REQ);
            jbt_cmd_handle_restore();
            break;
        case MSG_ID_BT_JSR_TEST_CMD5_REQ:
            {
            /* Service Registration */
            /* 1st parm: PS_Type (0x01: RFCOMM, 0x02: L2CAP), 4th parm: Transaction_id: 1000 */
                kal_uint8 status_result =0;
                jbt_session_service_registration(0x01, 330, 0x00, (++jbt_ut_transaction_id) + 1000,&status_result);
            }
            break;
    #if 1
        case MSG_ID_BT_JSR_TEST_CMD6_REQ:
        {
            /* RFCOMM Connection Request */
            /* JSR82: SPP Server uses server channel num =12 */
            kal_uint32 transaction_id = 0x02;
            kal_uint8 ps_type = JSR82_SESSION_PS_RFCOMM;
            kal_uint16 psm_chnl = 12;   /* psm_chnl=2 for IVT SPP Session Test usage */
            kal_uint16 mtu = JSR82_SESSION_PS_RFCOMM_MTU;
            kal_uint8 security_value = 0;
            kal_uint8 status_result;
            jbt_session_connect_req(transaction_id, jsr82_ut_session_con_addr, ps_type, psm_chnl, mtu, security_value, &status_result);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD7_REQ:
        {
            /* L2CAP Connection Request */
            kal_uint32 transaction_id = 0x03;
            kal_uint8 ps_type = JSR82_SESSION_PS_L2CAP;
            kal_uint16 psm_chnl = 0x2001;   /* for L2CAP Session Test usage: BT_JSR82_DYNAMIC_PSM (0x2001) */
            kal_uint16 mtu = JSR82_SESSION_PS_L2CAP_MTU;
            kal_uint8 security_value = 0;
            kal_uint8 status_result;
            jbt_session_connect_req(transaction_id, jsr82_ut_session_con_addr, ps_type, psm_chnl, mtu, security_value, &status_result);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD8_REQ:
        {
            /* RFCOMM Disconnection Request */
            /* JSR82: SPP Server uses server channel num =12 */
            kal_uint32 transaction_id = 0x04;
            kal_uint8 ps_type = JSR82_SESSION_PS_RFCOMM;
            jbt_session_info *session_entry = NULL;
            kal_uint8 status_result = 0;
            int i = 0;

            for (i = 0; i < JBT_MAX_SPP_NO; i++)
            {
                session_entry = &jbt_spp_context.spp[i].spp_session;
                if (session_entry->used == 1 &&
                    session_entry->subsession[0].subsession_state == JBT_SESSION_STATE_CONNECTED)
                {
                    break;
                }
            }
            if (i == JBT_MAX_SPP_NO)
            {
                return KAL_TRUE;
            }
            jbt_session_disconnect_req(
                transaction_id,
                ps_type,
                session_entry->index,
                session_entry->subsession[0].subsession_id,
                &status_result);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD9_REQ:
        {
            /* L2CAP Disconnection Request */
            kal_uint32 transaction_id = 0x05;
            kal_uint8 ps_type = JSR82_SESSION_PS_L2CAP;
            jbt_session_info *session_entry = NULL;
            kal_uint8 status_result = 0;
            int i = 0;

            for (i = 0; i < JBT_MAX_L2CAP_NO; i++)
            {
                session_entry = &jbt_l2cap_context.l2cap[i].l2cap_session;
                if (session_entry->used == 1 &&
                    session_entry->subsession[0].subsession_state == JBT_SESSION_STATE_CONNECTED)
                {
                    break;
                }
            }
            if (i == JBT_MAX_L2CAP_NO)
            {
                return KAL_TRUE;
            }
            jbt_session_disconnect_req(
                transaction_id,
                ps_type,
                session_entry->index,
                session_entry->subsession[0].subsession_id,
                &status_result);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD10_REQ:
        {
            /* RFCOMM Deregistration Service */
            kal_uint32 transaction_id = 0x06;
            kal_uint8 ps_type = JSR82_SESSION_PS_RFCOMM;
            jbt_session_info *session_entry = NULL;
            kal_uint8 status_result = 0;
            int i = 0;

            for (i = 0; i < JBT_MAX_SPP_NO; i++)
            {
                session_entry = &jbt_spp_context.spp[i].spp_session;
                if (session_entry->used == 1 && session_entry->initiator == 0x00)
                {
                    break;
                }
            }
            if (i == JBT_MAX_SPP_NO)
            {
                return KAL_TRUE;
            }
            jbt_session_service_deregistration(ps_type, transaction_id, session_entry->index,&status_result);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD11_REQ:
        {
            /* L2CAP Deregistration Service */
            kal_uint32 transaction_id = 0x07;
            kal_uint8 ps_type = JSR82_SESSION_PS_L2CAP;
            jbt_session_info *session_entry = NULL;
            kal_uint8 status_result = 0;
            int i = 0;

            for (i = 0; i < JBT_MAX_L2CAP_NO; i++)
            {
                session_entry = &jbt_l2cap_context.l2cap[i].l2cap_session;
                if (session_entry->used == 1 && session_entry->initiator == 0x00)
                {
                    break;
                }
            }
            if (i == JBT_MAX_L2CAP_NO)
            {
                return KAL_TRUE;
            }
            jbt_session_service_deregistration(ps_type, transaction_id, session_entry->index,&status_result);
        }
        case MSG_ID_BT_JSR_TEST_CMD12_REQ:
        {
            /* Authentication one specific ACL Link */
            kal_int32 transaction_id = 6283;
            /* 1: authentication; 2: encryption */ 
            kal_uint8 security_mode = 2;    
            kal_uint8 status_result = 0;

            jbt_set_acl_security_cmd(transaction_id, jsr82_ut_session_con_addr, security_mode,&status_result);
        }
            break;

        case MSG_ID_BT_JSR_TEST_CMD13_REQ:
        {
            /* Trigger to terminate JSR82 all connections */
            jbt_power_off_cmd(0x11);
        }
            break;
        case MSG_ID_BT_JSR_TEST_CMD14_REQ:
        {
            kal_uint8 status_result;
            jbt_get_remote_name_cmd(0x12, jsr82_ut_session_con_addr, &status_result);
        }

    #endif /* 1 */ 
            break;
        case MSG_ID_MMI_BT_BCC_RESTORE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_MMI_BT_BCC_RESTORE_CNF);
            /* jbt_handle_restore_btstack_result(); */
            /* Modified by mtk01411: 2007-1121 */
            jbt_handle_restore_mmi_req_result((mmi_bt_bcc_restore_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_RESTROE_ACL_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_RESTROE_ACL_CNF);
            jbt_handle_restore_btstack_result();
            break;
        case MSG_ID_BT_JSR_DEACTIVE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_DEACTIVE_CNF);
            jbt_handle_restore_btstack_result();
            break;
        case MSG_ID_BT_JSR_POWER_OFF_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR_POWER_OFF_IND);
            jbt_handle_power_off_req_result(JBT_POWEROFF_BY_MMI);
            break;
            /* BCC test commands */
        case MSG_ID_BT_JSR_TEST_BCC_CMD1_REQ:
        {
            /* kal_uint8 addr[6]={0x01,0x02,0x03,0x04,0x05,0x06}; */
            kal_uint8 status_result = 0;
            jbt_authorize_req_cmd(0x10, jsr82_ut_session_con_addr,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD2_REQ:
        {
            /* kal_uint8 addr[6]={0x01,0x02,0x03,0x04,0x05,0x06}; */
            kal_uint8 status_result = 0;
            jbt_is_authorized_req_cmd(0x10, jsr82_ut_session_con_addr,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD3_REQ:
        {
            /* kal_uint8 addr[6]={0x01,0x02,0x03,0x04,0x05,0x06}; */
            kal_uint8 status_result = 0;
            jbt_is_trusted_req_cmd(0x10, jsr82_ut_session_con_addr,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD4_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_get_host_security_mode_cmd(0x10,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD5_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_get_preknown_device_count_req_cmd(0x10,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD6_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_get_preknown_devices_req_cmd(0x10,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD7_REQ:
        {
            kal_uint8 status_result = 0;    
            jbt_power_on_cmd(0x10,&status_result);
            jbt_get_local_cod_cmd(0x10,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD8_REQ:
            jbt_restore_mmi_cmd();
            break;
        case MSG_ID_BT_JSR_TEST_BCC_CMD10_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_get_local_cod_cmd(0x10,&status_result);
            jbt_get_local_name_cmd(0x10,&status_result);
            /* jbt_set_local_cod_cmd(0x10,0x00140680); */
            jbt_trigger_panic_mechanism_cmd();
            break;
        }    
        case MSG_ID_BT_JSR_TEST_BCC_CMD11_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_set_local_discovery_cmd(0x10, 0x00,&status_result);
            break;
        }
        case MSG_ID_BT_JSR_TEST_BCC_CMD12_REQ:
        {
            kal_uint8 status_result = 0;
            jbt_get_local_discovery_cmd(0x10,&status_result);
            break;
        }
        case MSG_ID_MMI_BT_BCC_POWER_ON_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_MMI_BT_BCC_POWER_ON_CNF);
            jbt_handle_power_on_req_result((mmi_bt_bcc_power_on_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_MMI_BT_BCC_SET_DISCOVERABLE_MODE_CNF);
            jbt_handle_set_discoverable_mode_result((mmi_bt_bcc_set_discoverable_mode_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_MMI_BT_BCC_GET_DISCOVERABLE_MODE_CNF);
            jbt_handle_get_discoverable_mode_result((mmi_bt_bcc_get_discoverable_mode_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_READ_LOCAL_ADDR_CNF);
            jbt_handle_get_local_addr_result((bt_bm_read_local_addr_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_READ_LOCAL_COD_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_READ_LOCAL_COD_CNF);
            jbt_handle_get_local_cod_result((bt_bm_read_local_cod_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_READ_LOCAL_NAME_CNF:
            jbt_handle_get_local_name_result((bt_bm_read_local_name_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_WRITE_LOCAL_COD_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_WRITE_LOCAL_COD_CNF);
            jbt_handle_set_local_cod_result((bt_bm_write_local_cod_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_READ_REMOTE_NAME_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_READ_REMOTE_NAME_CNF);
            jbt_handle_get_remote_name_result((bt_bm_read_remote_name_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_DISCOVERY_RESULT_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_DISCOVERY_RESULT_IND);
            jbt_handle_device_discovery_entry_result((bt_bm_discovery_result_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_DISCOVERY_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_DISCOVERY_CNF);
            jbt_handle_device_discovery_completed_result((bt_bm_discovery_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF);
            jbt_handle_device_discovery_cancel_result((bt_bm_discovery_cancel_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_GET_LINK_STATE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_GET_LINK_STATE_CNF);
            jbt_handle_get_acl_info_result((bt_bm_get_link_state_cnf*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_APP_SDPDB_GET_HANDLE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_APP_SDPDB_GET_HANDLE_CNF);
            jbt_handle_get_record_handle_result((bt_app_sdpdb_get_handle_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_APP_SDPDB_REGISTER_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_APP_SDPDB_REGISTER_CNF);
            jbt_handle_register_record_result((bt_app_sdpdb_register_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_APP_SDPDB_DEREGISTER_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_APP_SDPDB_DEREGISTER_CNF);
            jbt_handle_deregister_record_result((bt_app_sdpdb_deregister_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_SEARCH_RAW_RESULT:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_SEARCH_RAW_RESULT);
            jbt_handle_sdap_result((bt_bm_search_raw_result_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_BM_SEARCH_RAW_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_BM_SEARCH_RAW_CNF);
            jbt_handle_sdap_completed_result((bt_bm_search_raw_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_ENABLE_SERVICE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_ENABLE_SERVICE_CNF);
            jbt_handle_session_enabled_result((bt_jsr82_enable_service_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_DISABLE_SERVICE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_DISABLE_SERVICE_CNF);
            jbt_handle_session_deregistration_result((bt_jsr82_disable_service_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_TURNON_SERVICE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_TURNON_SERVICE_CNF);
            jbt_handle_session_turnon_result((bt_jsr82_turnon_service_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_TURNOFF_SERVICE_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_TURNOFF_SERVICE_CNF);
            jbt_handle_session_turnoff_result((bt_jsr82_turnoff_service_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_CONNECT_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_CONNECT_IND);
            jbt_handle_session_connect_ind((bt_jsr82_connect_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_CONNECT_CNF:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_CONNECT_CNF);
            jbt_handle_session_connect_req_cnf((bt_jsr82_connect_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_RX_READY_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_RX_READY_IND);
            jbt_handle_session_rx_ready_ind((bt_jsr82_rx_ready_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_TX_READY_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_TX_READY_IND);
            jbt_handle_session_tx_ready_ind((bt_jsr82_tx_ready_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_DISCONNECT_IND:
            kal_trace(TRACE_JBT_GROUP, JBT_MSG_ID_BT_JSR82_DISCONNECT_IND);
            jbt_handle_session_disconnect_ind((bt_jsr82_disconnect_ind_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_BT_JSR82_SET_ACL_SECURITY_CNF:
            jbt_handle_set_acl_security_result((bt_jsr82_set_acl_security_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
            /* BCC */
        case MSG_ID_MMI_BT_BCC_AUTHORIZE_CNF:
            jbt_authorize_req_cmd_result((mmi_bt_bcc_authorize_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_IS_AUTHORIZED_CNF:
            jbt_is_authorized_req_result((mmi_bt_bcc_is_authorized_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_IS_TRUSTED_CNF:
            jbt_is_trusted_req_result((mmi_bt_bcc_is_trusted_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_GET_HOST_SECURITY_MODE_CNF:
            jbt_get_host_security_mode_result((mmi_bt_bcc_get_host_security_mode_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICE_COUNT_CNF:
            jbt_get_preknown_device_count_req_result((mmi_bt_bcc_get_preknown_device_count_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_GET_PREKNOWN_DEVICES_CNF:
            jbt_get_preknown_devices_req_result((mmi_bt_bcc_get_preknown_devices_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_MMI_BT_BCC_GET_NATIVE_PWR_STATUS_CNF:
            jbt_get_native_pwr_status_req_result((mmi_bt_bcc_get_native_pwr_status_cnf_struct*) ilm_ptr->local_para_ptr);
            break;
        default :
        	return KAL_FALSE;

    }
    kal_trace(TRACE_JBT_GROUP, JBT_JSR82_HANDLE_MESSAGE_COMPLETED);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jbt_event_registration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cb      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jbt_event_registration(JbtEventCBF cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jbt_context.jbtEventCb = cb;
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jbt_retrieve_cb_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NONE        
 * RETURNS
 *  
 *****************************************************************************/
JbtEventCBF jbt_retrieve_cb_func()
{
    if (jbt_context.jbtEventCb != NULL)
    {
        return jbt_context.jbtEventCb;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opcode              [IN]        
 *  transaction_id      [IN]        
 *  parm                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_event_callback(kal_uint8 opcode, kal_uint32 transaction_id, void *parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_context.jbtEventCb != 0)
    {
        jbt_context.jbtEventCb(opcode, transaction_id, parm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jbt_ConvertBdAddr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]       
 *  src         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_ConvertBdAddr(kal_uint8 *dest, btbm_bd_addr_t *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ((kal_uint8*) dest)[5] = ((kal_uint8) (((kal_uint32) src->lap) & 0x000000FF));
    ((kal_uint8*) dest)[4] = ((kal_uint8) ((((kal_uint32) src->lap) & 0x0000FF00) >> 8));
    ((kal_uint8*) dest)[3] = ((kal_uint8) ((((kal_uint32) src->lap) & 0x00FF0000) >> 16));
    ((kal_uint8*) dest)[2] = ((kal_uint8) src->uap);
    ((kal_uint8*) dest)[1] = ((kal_uint8) (((kal_uint16) src->nap) & 0x00FF));
    ((kal_uint8*) dest)[0] = ((kal_uint8) ((((kal_uint16) src->nap) & 0xFF00) >> 8));
}


/*****************************************************************************
 * FUNCTION
 *  jbt_ConvertToBdAddr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [OUT]       
 *  src         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_ConvertToBdAddr(btbm_bd_addr_t *dest, kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ((btbm_bd_addr_t*) dest)->nap =
        (((kal_uint16) ((kal_uint8*) src)[1])) | ((kal_uint16) ((kal_uint8*) src)[0] << 8);
    ((btbm_bd_addr_t*) dest)->uap = (kal_uint8) ((kal_uint8*) src)[2];
    ((btbm_bd_addr_t*) dest)->lap =
        (((kal_uint32) ((kal_uint8*) src)[3]) << 16) | ((kal_uint32) ((kal_uint8*) src)[4] << 8) |
        ((kal_uint32) ((kal_uint8*) src)[5]);
}


/*****************************************************************************
 * FUNCTION
 *  jbt_ConvertBdAddrOrder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  src         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_ConvertBdAddrOrder(kal_uint8 *dest, kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest[0] = src[5];
    dest[1] = src[4];
    dest[2] = src[3];
    dest[3] = src[2];
    dest[4] = src[1];
    dest[5] = src[0];
}

/*****************************************************************************
 * FUNCTION
 *  jbt_malloc_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jbt_malloc_block(kal_uint32 size)
{
#ifdef JBT_MEMORY_DEBUG
    kal_uint8 i = 0;

    if (size == 0)
    {
        ASSERT(0);
    }
    for (i = 0; i < JBT_MAX_MEMORY_BLOCK; i++)
    {
        if (jbt_context.jbt_mem.mem_block[i].size == 0)
        {
            jbt_context.jbt_mem.mem_block[i].size = size;
            break;
        }
    }
    if (i == JBT_MAX_MEMORY_BLOCK)
    {
#ifdef JBT_SUPPORT_ADM_MEM
        kal_adm_print_log(jbt_get_mem_pool_id());
#endif
        ASSERT(0);
    }
    kal_trace(TRACE_JBT_GROUP, JBT_JBT_MALLOC_INDEXxD_SIZExD, i, size);
    return i;
#else
    return 0;
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  jbt_malloc_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jbt_malloc_record(kal_uint8 block_inx, kal_uint8*buf_ptr, kal_uint32 size)
{
#ifdef JBT_MEMORY_DEBUG
    if (buf_ptr != NULL)
    {
        /* Check if this new obtained mem_address ptr is belonged to any previous allocated memory block's range */
        kal_uint8 i =0;
        
#ifdef JBT_SUPPORT_ADM_MEM
        if ((buf_ptr < jbt_get_adm_mem_start_addr()) || (buf_ptr > jbt_get_adm_mem_end_addr()))
        {
            /* This check is used to avoid mis-used the jvm_malloc() to obtain buf_ptr in somewhere */
            ASSERT(0);
        } 
#endif

        for (i=0; i < JBT_MAX_MEMORY_BLOCK; i++)
        {
            kal_uint8* start_addr = jbt_context.jbt_mem.mem_block[i].ptr;
            kal_uint8* end_addr = start_addr + jbt_context.jbt_mem.mem_block[i].size;
            if ((buf_ptr >= start_addr) && (buf_ptr <= end_addr))
            {
                /* jvm_malloc()/kal_adm_alloc() should not return one overlapped mem addr belongs to one previous allocated mem block */
#ifdef JBT_SUPPORT_ADM_MEM
                kal_adm_print_log(jbt_get_mem_pool_id());
#endif
                ASSERT(0);
            }
        }
        kal_trace(TRACE_JBT_GROUP, FUNC_JBT_MEM_ALLOC_INX_SIZE_PTR,block_inx,size,buf_ptr);
        jbt_context.jbt_mem.jbt_memory_size += size;
        jbt_context.jbt_mem.mem_block[block_inx].ptr = buf_ptr;        
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  jbt_free_block_by_inx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jbt_free_block(kal_uint8 block_index)
{
#ifdef JBT_MEMORY_DEBUG
    jbt_context.jbt_mem.mem_block[block_index].size = 0;
#ifdef JBT_SUPPORT_ADM_MEM
    kal_adm_print_log(jbt_get_mem_pool_id());
#endif
    ASSERT(0);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  jbt_free_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void jbt_free_record(kal_uint8* ptr)
{
#ifdef JBT_MEMORY_DEBUG
    kal_uint8 i;
    for (i = 0; i < JBT_MAX_MEMORY_BLOCK; i++)
    {
        if (jbt_context.jbt_mem.mem_block[i].ptr == ptr)
        {
            jbt_context.jbt_mem.jbt_memory_size -= jbt_context.jbt_mem.mem_block[i].size;
            kal_trace(TRACE_JBT_GROUP, FUNC_JBT_MEM_FREE_INX_SIZE_PTR,i, jbt_context.jbt_mem.mem_block[i].size,ptr);
            jbt_context.jbt_mem.mem_block[i].size = 0;
            jbt_context.jbt_mem.mem_block[i].ptr = 0;
            return;
        }
    }
#ifdef JBT_SUPPORT_ADM_MEM
    kal_adm_print_log(jbt_get_mem_pool_id());
#endif
    ASSERT(0);
    
#endif    
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
#ifndef JBT_MEMORY_DEBUG
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
#else /* JBT_MEMORY_DEBUG */ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* JBT_MEMORY_DEBUG */ 
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
#ifndef JBT_MEMORY_DEBUG
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* JBT_MEMORY_DEBUG */ 
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
#endif /* JBT_MEMORY_DEBUG */ 
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  jbt_free_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_free_all(void)
{
#ifndef JBT_MEMORY_DEBUG
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Parameter ptr passed to jvm_free() is invalid */
    jvm_free((void*)ptr);
#else /* JBT_MEMORY_DEBUG */ 
    kal_uint8 i;
    kal_uint8 *ptr;

    for (i = 0; i < JBT_MAX_MEMORY_BLOCK; i++)
    {
        if (jbt_context.jbt_mem.mem_block[i].size != 0)
        {
            kal_trace(TRACE_JBT_GROUP,FUNC_JBT_MEM_FREE_INX_SIZE_PTR,i, jbt_context.jbt_mem.mem_block[i].size,jbt_context.jbt_mem.mem_block[i].ptr);
            jbt_context.jbt_mem.jbt_memory_size -= jbt_context.jbt_mem.mem_block[i].size;
            jbt_context.jbt_mem.mem_block[i].size = 0;
            ptr = jbt_context.jbt_mem.mem_block[i].ptr;
            jbt_context.jbt_mem.mem_block[i].ptr = 0;
            if (ptr != NULL)
            {
#ifndef JBT_SUPPORT_ADM_MEM
                jvm_free((void*)ptr);
#else
                kal_adm_free(jbt_get_mem_pool_id(),(void*)ptr);
#endif
            }

        }
    }

#endif /* JBT_MEMORY_DEBUG */ 
}

#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_MAIN_C */ 

