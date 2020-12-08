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

/*******************************************************************************
 * Filename:
 * ---------
 *   soc_trc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

#ifndef _SOC_TRC_H
#define _SOC_TRC_H

#ifndef GEN_FOR_PC
#include "stack_config.h"
#endif /* GEN_FOR_PC */
#include "kal_trace.h"

#ifndef _KAL_TRACE_H
#error "kal_trace.h should be included before tst_trace.h"
#endif /* _KAL_TRACE_H */

 
#define TRACE_SOC_EVENT         (TRACE_GROUP_1)
#define TRACE_SOC_NONBLOCK      (TRACE_GROUP_2)
#define TRACE_SOC_DATAIO        (TRACE_GROUP_3)
#define TRACE_SOC_TIMER         (TRACE_GROUP_5)


/* ERROR */
#define SOC_ERROR_LOG(TAG, id)                     kal_lib_trace(TRACE_ERROR, TAG, id)

#define DNS_ERROR_LOG(TAG)                         kal_lib_trace(TRACE_ERROR, TAG)
#define DNS_SOCKET_ERROR_LOG(TAG, ret)             kal_lib_trace(TRACE_ERROR, TAG, ret)

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "soc_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_SOC)

    /* 
     * TRACE_FUNC trace class 
     */      

    /* soc_abm.c */
    TRC_MSG(SOC_FUNC_SOC_ABM_ACTIVATE_CNF_HDLR, "SOC: enter soc_abm_activate_cnf_hdlr()")
    TRC_MSG(SOC_FUNC_SOC_ACTIVATE_NWK_ACCOUNT, "SOC: enter soc_activate_nwk_account(acct=%d, qos=%d)")
    TRC_MSG(SOC_FUNC_EXIT_SOC_ACTIVATE_NWK_ACCTOUNT,   "SOC: exit soc_activate_nwk_account(ret=%d)")
    TRC_MSG(SOC_FUNC_SOC_DEACTIVATE_NWK_ACCOUNT, "SOC: enter soc_deactivate_nwk_account()")
    TRC_MSG(SOC_FUNC_SOC_ABM_IPADDR_UPDATE_IND_HDLR, "SOC: enter soc_abm_ipaddr_update_ind_hdlr")
    TRC_MSG(SOC_IS_BEARER_READY, "SOC: soc_is_bearer_ready(ret=%d)")

    /* soc_api.c */
    TRC_MSG(SOC_FUNC_SOCREATE, "SOC: enter socreate(type=%Msocket_type_enum, acct_id=%d)")
    TRC_MSG(SOC_FUNC_ENTER_SOC_CREATE, "SOC: enter soc_create")
    TRC_MSG(SOC_FUNC_SOC_CREATE, "SOC: soc_create, socket_id=%d")
    TRC_MSG(SOC_FUNC_CLOSE, "SOC: enter soc_close(%d)")  
    TRC_MSG(SOC_FUNC_SOC_BIND, "SOC: enter soc_bind(s=%d, laddr=%u.%u.%u.%u:%u)")
    TRC_MSG(SOC_FUNC_SOC_LISTEN, "SOC: enter soc_listen(%d)")
    TRC_MSG(SOC_FUNC_SOC_ACCEPT, "SOC: enter soc_accept(%d)")
    TRC_MSG(SOC_FUNC_SOC_CONNECT, "SOC: enter soc_connect(s=%d, faddr=%u.%u.%u.%u:%u)")
    TRC_MSG(SOC_FUNC_SOC_SHUTDOWN, "SOC: enter soc_shutdown(%d, how=%Msoc_shutdown_enum)")
    TRC_MSG(SOC_FUNC_SOC_SELECT, "SOC: enter soc_select()") 
    TRC_MSG(SOC_FUNC_SOC_SETSOCKOPT, "SOC: enter soc_setsockopt(s=%d, opt=%Msoc_option_enum)")
    TRC_MSG(SOC_FUNC_SOC_GETSOCKOPT, "SOC: enter soc_getsockopt(s=%d, opt=%Msoc_option_enum)")
    TRC_MSG(SOC_FUNC_SOC_RECV, "SOC: enter soc_recv(%d)")
    TRC_MSG(SOC_FUNC_SOC_RECVFROM, "SOC: enter soc_recvfrom(%d)")
    TRC_MSG(SOC_FUNC_SOC_SEND, "SOC: enter soc_send(%d)") 
    TRC_MSG(SOC_FUNC_SOC_SENDTO, "SOC: enter soc_sendto(s=%d, faddr=%u.%u.%u.%u:%u)") 
    TRC_MSG(SOC_FUNC_SOC_SET_MODULE, "SOC: enter soc_set_module(s=%d, mod=%Mmodule_type)") 
    TRC_MSG(SOC_FUNC_GET_ACCT_LOCAL_ADDR, "SOC: soc_get_localip_by_account: account_id=%d, laddr=%u.%u.%u.%u")
    TRC_MSG(SOC_FUNC_SET_DNS_SRV_ADDR, "SOC: soc_set_dns_srv_addr: account_id=%d, srv_type:%d addr=%u.%u.%u.%u")
    TRC_MSG(SOC_FUNC_SOC_SENDMSG, "SOC: soc_sendmsg(): %d")
    TRC_MSG(SOC_FUNC_SOC_RECVMSG, "SOC: soc_recvmsg(): %d")

    /* soc_flc.c */
    TRC_MSG(SOC_FUNC_SOC_GROW_SSPDU, "SOC: enter soc_grow_sspdu(s=%d)")
    TRC_MSG(SOC_FUNC_SOC_SSPDU_BECOME_AVAIL, "SOC: enter soc_sspdu_become_avail(s=%d)")
    TRC_MSG(SOC_FUNC_SOC_ACTIVATE_SSPDU, "SOC: enter soc_activate_sspdu(s=%d)")
    TRC_MSG(SOC_FUNC_SOC_DEACTIVATE_SSPDU, "SOC: enter soc_deactivate_sspdu(s=%d)")

    /* soc_tcpip.c */
    TRC_MSG(SOC_FUNC_SOC_TCPIP_ACCEPT_IND_HDLR, "SOC: enter soc_tcpip_accept_ind_hdlr")
    TRC_MSG(SOC_RECV_TCPIP_CONNECT_CNF_FUNC, "SOC: enter soc_tcpip_connect_cnf_hdlr: socket id=%d, result=%d")
    TRC_MSG(SOC_RECV_TCPIP_CLOSE_IND_FUNC,   "SOC: enter soc_tcpip_close_ind_hdlr: socket id=%d")

    /* soc_dns.c */
    TRC_MSG(SOC_FUNC_DNS_RECV_RSP_FROM_SERVER, "DNS: enter dns_recv_rsp_from_server()")
    TRC_MSG(SOC_FUNC_DNS_QUERY_RETRY, "DNS: enter dns_query_retry")
    TRC_MSG(SOC_FUNC_DNS_SEND_QUERY_TO_SERVER, "DNS: enter dns_send_query_to_server()")
    TRC_MSG(SOC_FUNC_DNS_ADD_CACHE, "DNS: enter dns_add_cache()")
    TRC_MSG(SOC_FUNC_DNS_FIND_CACHE, "DNS: enter dns_find_cache()")
    TRC_MSG(SOC_FUNC_DNS_GET_IP_BY_NAME, "DNS: enter dns_get_ip_by_name(acct_id=%d)")
    TRC_MSG(SOC_FUNC_DNS_GET_NAME_BY_IP, "DNS: enter dns_get_name_by_ip(%u.%u.%u.%u)")
    TRC_MSG(SOC_FUNC_DNS_GET_DNS_RR, "DNS: enter dns_get_dns_rr()")
    TRC_MSG(SOC_FUNC_DNS_MAKE_QUERY, "DNS: enter dns_make_query()")
    TRC_MSG(SOC_FUNC_DNS_ALLOC_TRANSACTION, "DNS: enter dns_alloc_transaction()")
    TRC_MSG(SOC_FUNC_DNS_FREE_TRANSACTION, "DNS: enter dns_free_transaction()")
    TRC_MSG(SOC_FUNC_DNS_FIND_PEND_REQ, "[SOC] dns_find_dup_pending_req: pend_acct:%d acct:d")
    
    /* TRACE_STATE */
    TRC_MSG(SOC_STATE_SOCKET,  "SOC: socket=%d, state=%d")
    TRC_MSG(SOC_STATE_ACCOUNT, "SOC: account=%d, qos_profile=%d, ps_ctx_id=%d, state=%Msoc_account_state_enum")
    TRC_MSG(SOC_STATE_IP, "SOC: account=%d, ip_state=%Msoc_ip_state_enum")
    TRC_MSG(SOC_LINGER_FOR_RECV, "SOC: option=%d, wait linger time to recv FIN and ACK")

    /* TRACE_INFO trace class */ 
    TRC_MSG(SOC_INFO_ABM_NUM, "SOC: account num info: account_id=%d, socket_num=%d, is_increment=%d")
    TRC_MSG(SOC_INFO_RCVD_SOC_ABM_DEACTIVATE_CNF, "SOC: recv SOC_ABM_DEACTIVATE_CNF")
    TRC_MSG(SOC_INFO_RCVD_SOC_ABM_DEACTIVATE_IND, "SOC: recv SOC_ABM_DEACTIVATE_IND")
    TRC_MSG(SOC_INFO_DNS_NOTIFY_APP_IP, "DNS: notify app ip=%u.%u.%u.%u")
    TRC_MSG(SOC_INFO_SOC_RCVD_TCPIP_CNF, "SOC: socket=%d exp_state=%x, waiting_event=%Msoc_wait_event_enum, result=%d")
    TRC_MSG(SOC_CONFIG_BEARER, "SOC: config bearer set=%d, bearer=%Mgprs_flc_socket_mode_bearer_enum, bearer_map=%u")
    TRC_MSG(SOC_INFO_SOC_DEACTIVATE_NWK_ACCOUNT, "SOC: enter soc_deactivate_nwk_account(mod=%Mmodule_type, ap_id=%d, acct_id=%d)")
    TRC_MSG(NWK_ACCOUNT_OCCUPIED, "SOC: nwk_acct %d, qos=%d, ctx=%d occupied by mod_id=%Mmodule_type, ap_id=%d")
    TRC_MSG(SOC_CHANGE_IP_ADDR, "SOC: change IP address from %u.%u.%u.%u to %u.%u.%u.%u")
    TRC_MSG(SOC_READ_NOTIFY, "SOC: soc_read_notify(s=%d, set=%Mkal_bool)")
    TRC_MSG(SOC_NWK_ACCOUNT_INFO, "nwk_account: i=%d, account_id=%u, app_proc->account_id[%d]=%d")
    TRC_MSG(SOC_INFO_SOC_CLOSE_NWK_ACCOUNT, "SOC: soc_close_nwk_account(mod=%Mmodule_type)")
    TRC_MSG(SOC_SMS_RECV_NOTIFY, "SOC: soc sms rcvd from: len=%d, fport=%d")
    TRC_MSG(SOC_SMS_RECV_NOTIFY_SC, "SOC: soc sms rcvd sc_addr: addr=0x%02X-%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X")
    TRC_MSG(SOC_SMS_RECV_NOTIFY_OA, "SOC: soc sms rcvd oa_addr: addr=0x%02X-%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X%X")
    TRC_MSG(SOC_ACTIVATE_AGAIN, "SOC: %Mmodule_type (s=%d) needs activate bearer again")
    TRC_MSG(SOC_MARK_ACTIVATE_AGAIN, "SOC: %Mmodule_type marks activate bearer again")
    TRC_MSG(SOC_RECV_SMS_FORWARD_PKT, "SOC: forward packet from port %d to 2948")
    TRC_MSG(SOC_INFO_DNS_RECV_TOO_BIG_TTL, "DNS: ttl is too long")
    TRC_MSG(SOC_INFO_ACT_OPEN_BY_OTHER, "SOC: opened by other module:%Mmodule_type")
    TRC_MSG(SOC_INFO_ACT_HAS_CLOSE, "SOC: account has benn closed")
    TRC_MSG(SOC_INFO_CUR_RECORD, "SOC: current stored record: %d")
    TRC_MSG(SOC_INFO_START_AUTO_DEACT_TIMER, "SOC: start the auto deactivate bearer timer")
    TRC_MSG(SOC_INFO_STOP_AUTO_DEACT_TIMER, "SOC: stop the auto deactivate bearer timer")
    TRC_MSG(SOC_INFO_ALWAYS_ASK_CANCEL, "[SOC] always-ask account is canceled by users")
    TRC_MSG(CREATE_QOS_PROFILE, "SOC: attach socket %d to new QOS profile %d")
    TRC_MSG(ATTACH_QOS_PROFILE, "SOC: attach socket %d to QoS profile %d")
    TRC_MSG(SOC_NO_IP_DEACT, "SOC: no ip address and deactivate the bearer: mod_id=%Mmodule_type, ap_id=%d")
    TRC_MSG(SOC_RESET_ACCT_SLOT, "[SOC] soc_reset_acc_slot: account_id=%d")
    TRC_MSG(SOC_FIND_ACCT_SLOT, "[SOC] soc_find_acc_slot: idx=%d account_id=%d")
    TRC_MSG(SOC_FIND_FREE_ACCT_SLOT, "[SOC] find free acct slot: idx=%d")
    TRC_MSG(SOC_NO_ACTIVATED_ACCT, "SOC: currently, there is no wanted activated account!!")
    TRC_MSG(SOC_CONNECT_RET_VAL, "[SOC] soc_connect: %d")
    TRC_MSG(SOC_NOT_ALL_CLOSED, "[SOC] sockets are not all closed: module_id:%Mmodule_type, ap_id:%d")
    TRC_MSG(SOC_START_GPRS_LINGER_TIMER, "[SOC] start the gprs linger timer: acct_id=%d val=%d")
    TRC_MSG(SOC_REL_PKT_LEN, "[SOC] recv successfully. Released bytes: %d")
    TRC_MSG(SOC_NWK_READY_FOR_SEND,"[SOC] soc_is_nwk_ready_for_send!! ret=%d")
    TRC_MSG(SOC_RECV_QUEUE_READY, "[SOC] soc_is_recv_queue_ready!! ret=%d")
    TRC_MSG(SOC_RESET_NWK_STATUS, "[SOC] soc_reset_nwk_status!!(%d), bearer=%Mcbm_bearer_enum")

    /* DNS info */
    TRC_MSG(DNS_FOUND_A_FROM_CACHE, "DNS: found IP address %d.%d.%d.%d in cache")
    TRC_MSG(DNS_FOUND_A_FROM_NEG_CACHE, "DNS: found IP address %d.%d.%d.%d in neg cache")    
    TRC_MSG(DNS_FOUND_PTR_FROM_CACHE, "DNS: found name for %u.%u.%u.%u in cache")
    TRC_MSG(DNS_FOUND_PTR_FROM_NEG_CACHE, "DNS: found name for %u.%u.%u.%u in neg cache")
    TRC_MSG(DNS_FOUND_SRV_FROM_CACHE, "DNS: found %d srv entry in cache")
    TRC_MSG(DNS_FOUND_SRV_FROM_NEG_CACHE, "DNS: found %d srv entry in neg cache")
    TRC_MSG(DNS_FOUND_NAPTR_FROM_CACHE, "DNS: found %d naptr entry in cache")
    TRC_MSG(DNS_FOUND_NAPTR_FROM_NEG_CACHE, "DNS: found %d naptr entry in neg cache")
    TRC_MSG(DNS_FOUND_DUP_PENDING_REQ, "DNS: found duplicate pending request")
    TRC_MSG(DNS_UPDATE_AUX_SERVER, "DNS: update aux server %d: %u.%u.%u.%u")

    /* wait/receive/set event */
    TRC_MSG(SOC_EVENT_SOC_WAIT_EVENT, "SOC: waits %Msoc_wait_event_enum: socket id=%d")
    TRC_MSG(SOC_EVENT_SOC_RECV_EVENT, "SOC: received %Msoc_wait_event_enum: socket id=%d")
    TRC_MSG(SOC_EVENT_SOC_SET_EVENT,  "SOC: set %Msoc_wait_event_enum: socket id=%d")

    TRC_MSG(SOC_INFO_SOC_TCPIP_WAIT_EVENT, "SOC: socket %d sends REQ to TCPIP and wait for %Msoc_wait_event_enum")
    TRC_MSG(SOC_INFO_SOC_NOTIFY_APP_EVENT, "SOC: notify application: s=%d event=%Msoc_event_enum result=%d cause=%d")
    TRC_MSG(SOC_SEND_ACCEPT_RES,     "SOC: send accept res to tcp/ip, ori_socket_id=%d new_socket_id=%d")

    /* DATA path */
    TRC_MSG(SOC_DATAIO_SOSEND, "SOC: sosend(%d), return=%d")
    TRC_MSG(SOC_DATAIO_SORECV, "SOC: sorecv(%d), return=%d")
    TRC_MSG(SOC_DATAIO_SOC_PRU_SEND, "SOC: soc_pru_send(s=%d)")
    TRC_MSG(SOC_DATAIO_SOC_RECEIVE_IND_HDLR, "SOC: receive ind from TCPIP, socket=%d, %u bytes")
    TRC_MSG(SOC_DATAIO_SOC_RCV_DROP, "SOC: incoming packets are dropped")

    /* FLC info */
    TRC_MSG(SOC_ACTIVATE_SRPDU_INFO,   "SOC: activate SRPDU")

    /* TRACE_WARNING trace class */   
    TRC_MSG(SOC_NO_BUFF_TO_SEND, "SOC: no buffer to send, socket=%d")
    TRC_MSG(SOC_POSTPONE_NOTIFY, "SOC: postpone notificatoin to socket %d")
    TRC_MSG(SOC_SOCKET_HIT_LIMIT, "SOC: socket number of %Mmodule_type hit limit %d")
    TRC_MSG(SOC_DGRAM_RECV_BUFF_TOO_SMALL, "SOC: DGRAM soc_recvfrom() buffer too small: buf_size=%d < data_len=%d")
    TRC_MSG(SOC_SMS_RECV_BUFF_TOO_SMALL, "SOC: SMS soc_recvfrom() buffer too small: buf_size=%d < data_len=%d")
    TRC_MSG(SOC_LOCAL_ADDR_NOT_READY, "SOC: local IP address not ready")
    TRC_MSG(SOC_SMS_NO_SC_ADDR, "SMS: no room for SC addr: MAX_ADDR_LEN=%d, sc_addr size=%d")
    TRC_MSG(SOC_SMS_NO_OA_ADDR, "SMS: no room for OA addr: MAX_ADDR_LEN=%d, sc_addr size=%d, os_addr size=%d")
    TRC_MSG(SOC_DATA_RCVD_QUEUE_NOT_EMPTY, "SOC: data received for socket %d, rcvd=%d, freed=%d")
    TRC_MSG(SOC_DROP_7BIT_ENCODING_SMS, "SOC: SMS discard 7-bit encoding message to socket %d")
    TRC_MSG(SOC_INVALID_AP_ID, "SOC: didn't register the AP id->mod_id:%Mmodule_typed ap_id:%d")
    TRC_MSG(SOC_APP_SLOT_UNRESET, "SOC: AP slot is not reset(bearer is hold): mod_id=%Mmodule_typed, ap_id=%d")

    /* TRACE_ERROR trace class */       
    TRC_MSG(SOC_ABM_CNF_WRONG_STATE, "SOC: receive ACT CNF but state is wrong, state=%d")
    TRC_MSG(SOC_ABM_ACT_BUT_CLOSING, "SOC: attempt to activate bearer but state is CLOSING: account id=%d")
    TRC_MSG(SOC_CREATE_FAIL1,        "SOC: create socket fail, invalid parameter: domain=%d protocol=%d type=%Msocket_type_enum")
    TRC_MSG(SOC_CREATE_FAIL2,        "SOC: create socket fail, invalid nwk account id=%d")
    TRC_MSG(SOC_INVALID_SOCKET_ID,   "SOC: invalid socket id=%d")
    TRC_MSG(SOC_PIPE_BROKEN,            "SOC: pipe broken, socket id=%d")
    TRC_MSG(SOC_INVALID_SOCKET_ADDRESS, "SOC: invalid socket address, len=%d port=%d addr=%u.%u.%u.%u")
    TRC_MSG(SOC_NO_FREE_SOCKET_SLOT,    "SOC: no free socket slot")
    TRC_MSG(SOC_NO_FREE_APP_SLOT,       "SOC: no free application slot")
    TRC_MSG(SOC_RECV_ACCEPT_IND_ERROR,  "SOC: receive accept ind but something error: state=%x, qlen=%d, qlimit=%d")
    TRC_MSG(SOC_NO_FREE_SLOT_FOR_NEW_CONN, "SOC: receive accept ind but no free socket slot found, socket id=%d")
    TRC_MSG(SOC_SELECT_CHECK_ERROR,        "SOC: select check error")
    TRC_MSG(SOC_NB_WOULDBLOCK,             "SOC: soc_connect(%d) returns WOULDBLOCK")
    TRC_MSG(SOC_RECV_BUT_NOT_CONNECTED,    "SOC: receive recv ind (tcp type) from tcp/ip but socket not connected: state=%x socket id=%d")
    TRC_MSG(SOC_RECV_BUT_CLOSING,          "SOC: receive recv ind (tcp type) from tcp/ip but socket is closing: state=%x socket id=%d")
    TRC_MSG(SOC_RECV_BUT_SMS_QFULL,        "SOC: receive recv ind (sms type) but queue full, socket id=%d")
    TRC_MSG(SOC_RECV_BUT_BAD_UDHL,         "SOC: receive SMS but udhl(%d) is wrong, socket id=%d")
    TRC_MSG(SOC_RECV_BUT_BAD_LEN,          "SOC: receive SMS but length(%d) is wrong, socket id=%d")
    TRC_MSG(SOC_RECV_BUT_TOO_MANY_CONC_MSG,"SOC: receive SMS but too many concat. msg, socket id=%d")
    TRC_MSG(SOC_RECV_BUT_TOO_MANY_SEG,     "SOC: receive SMS but too many segments, total_seg=%d, seg=%d, socket id=%d") 
    TRC_MSG(SOC_RECV_BUT_NO_SOCKET_WANT_THIS_MSG, "SOC: receive SMS but cannot find socket match the dest port=%d")
    TRC_MSG(SOC_SENDTO_INVALID_FADDR, "SOC: soc_sendto(s=%d, faddr=%u.%u.%u.%u:%u) invalid faddr") 
    TRC_MSG(SOC_ABM_ACTIVATE_FAIL, "SOC: account activate fail")
    TRC_MSG(SOC_ACT_NOT_OPEN, "SOC: account is not opened: %d")
    TRC_MSG(SOC_DNS_NAME_TOO_LONG, "SOC: dns cache name too long: %d %d")
    TRC_MSG(SOC_GET_ERROR_ACCOUNT, "SOC: account should has been obtained")
    TRC_MSG(SOC_NO_DNS_ACCT_SLOT ,"SOC: DNS add srv addr error!! no account's slot.")
    TRC_MSG(SOC_INVALID_PARAMETER, "SOC: invalid input parameter (socket_id = %d)")

    /* FLC error */
    TRC_MSG(SOC_GROW_TOO_MANY, "SOC: grow too many times, socket id=%d")
    TRC_MSG(SOC_GROW_FAILED,   "SOC: grow failed, socket id=%d")
    TRC_MSG(SOC_SSPDU_STILL_OCCUPIED, "SOC: SSPDU %d still be occupied when socket attempt to deactivate")
    TRC_MSG(SOC_RECV_TCPIP_CONNECT_CNF_BUT_WRONG_STATE, "SOC: receive connect cnf for socket %d but state %x is wrong")

    /* error in receiving wrong messages */
    TRC_MSG(SOC_WRONG_MSG_FROM_ABM, "SOC: wrong message from ABM: msg=%Mmsg_type")
    TRC_MSG(SOC_WRONG_MSG_FROM_TCPIP, "SOC: wrong message from TCPIP: msg=%Mmsg_type")
    TRC_MSG(SOC_WRONG_MSG, "SOC: received wrong message: msg=%Mmsg_type")
    TRC_MSG(SOC_WRONG_MSG_FROM_MMI, "SOC: wrong message from MMI: msg=%Mmsg_type")

    /* DNS error */
    TRC_MSG(DNS_NO_PENDING_REQ,       "DNS: get no pending req slot")
    TRC_MSG(DNS_UNPACK_DNS_RES_ERROR, "DNS: unpack dns response error")
    TRC_MSG(DNS_RECV_ERROR,           "DNS: socket recv error: %d")
    TRC_MSG(DNS_CREATE_SOCKET_ERROR,  "DNS: socket create error: %d")
    TRC_MSG(DNS_SENDTO_ERROR,         "DNS: socket send error: %d")
    TRC_MSG(DNS_SETSOCKOPT_ERROR,     "DNS: socket setoption error: %d")
    TRC_MSG(DNS_TOO_MANY_RETRY,       "DNS: retry exceed max count")
    TRC_MSG(DNS_WRONG_DOMAIN_NAME,    "DNS: wrong domain name")
    TRC_MSG(SOC_ERROR_DNS_ACCT_NOT_FOUND, "DNS: account %d not found")
    TRC_MSG(SOC_DNS_RECV_RSP_PKT_TRUNC, "DNS: packet has been truncated")

    /* timer */
    TRC_MSG(SOC_TIMER_EXPIRED, "SOC: timer expire, timer type = %Msoc_timer_enum")
    TRC_MSG(SOC_NO_FREE_TIMER, "SOC: soc_get_free_timer() failed")
    TRC_MSG(SOC_GET_TIMER_PTR_FAIL, "SOC: get timer ptr fail, timer type = %Msoc_timer_enum, invoke id=%d")
    TRC_MSG(SOC_START_TIMER, "SOC: start timer, timer type=%Msoc_timer_enum, invoke_id=%d, sub_id=%u, val=%d")
    TRC_MSG(SOC_STOP_TIMER, "SOC: stop timer, timer type=%Msoc_timer_enum invoke id=%d, sub_id=%u")
    TRC_MSG(SOC_SET_AUTODISC_TIMER, "SOC: soc_set_csd_auto_disconnect_timer(orig=%d, new=%d)")

    /* FOR SOCKET UT*/
    TRC_MSG(SOC_UT_CNF_RET_WARN, "SOC_UT: return value in CNF message could be incorrect")

END_TRACE_MAP(MOD_SOC)

#endif /* !_SOC_TRC_H */


