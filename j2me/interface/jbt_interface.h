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
 *  jwa_internal.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifdef __SUPPORT_JBT__
#ifndef _JBT_INTERFACE_H
#define _JBT_INTERFACE_H

typedef enum 
{
    JBT_CMDCODE_POWER_ON = 0,
    JBT_CMDCODE_POWER_OFF,
    JBT_CMDCODE_POWER_STATUS,
    JBT_CMDCODE_GET_LOCAL_NAME,                 //conncurrent  
    JBT_CMDCODE_GET_LOCAL_ADDR,                 //conncurrent
    JBT_CMDCODE_GET_LOCAL_DISCOVERY_MODE,       //not used
    JBT_CMDCODE_GET_LOCAL_COD,                  //conncurrent
    JBT_CMDCODE_SET_LOCAL_DEVICE_NAME,          //not used
    JBT_CMDCODE_SET_LOCAL_DISCOVERY_MODE,       //not used
    JBT_CMDCODE_SET_LOCAL_COD,                  //non-concurrent
    JBT_CMDCODE_GET_REMOTE_NAME,                //non-concurrent
    JBT_CMDCODE_GET_REMOTE_ACL_INFO,            //conncurrent
    JBT_CMDCODE_SET_ACL_SECURITY_INFO,          //non-concurrent
    JBT_CMDCODE_DEVICE_DISCOVERY_CMD,           //non-concurrent
    JBT_CMDCODE_DEVICE_DISCOVERY_CMD_CANCEL,    //conncurrent   
    JBT_CMDCODE_DEVICE_RESTORE_MMI,             //non-concurrent
    JBT_CMDCODE_DEVICE_RESTORE_COD,             //non-concurrent
    JBT_CMDCODE_GET_RECORD_HANDLE,
    JBT_CMDCODE_REGISTER_RECORD_RESULT,
    JBT_CMDCODE_DEREGISTER_RECORD_RESULT,
    JBT_CMDCODE_SDAP_RESULT,
    JBT_CMDCODE_SDAP_COMPLETED_RESULT,
    JBT_CMDCODE_BCC_AUTHORIZE,                  //conncurrent
    JBT_CMDCODE_BCC_IS_AUTHORIZED,              //conncurrent
    JBT_CMDCODE_BCC_IS_TRUSTED,                 //conncurrent
    JBT_CMDCODE_BCC_GET_HOST_SECURITY_MODE,     //conncurrent
    JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICE_COUNT,  //conncurrent
    JBT_CMDCODE_BCC_GET_PREKNOWN_DEVICES,       //conncurrent
    JBT_CMDCODE_BCC_GET_NATIVE_PWR_STATUS       //conncurrent
}JBT_CMDCODE;


#define JBT_OPCODE_POWER_ON 0x01
#define JBT_OPCODE_POWER_OFF 0x02
#define JBT_OPCODE_POWER_STATUS 0x03
#define JBT_OPCODE_GET_LOCAL_NAME 0x04
#define JBT_OPCODE_GET_LOCAL_ADDR 0x05
#define JBT_OPCODE_GET_LOCAL_DISCOVERY_MODE 0x06
#define JBT_OPCODE_GET_LOCAL_COD 0x07
#define JBT_OPCODE_SET_LOCAL_DEVICE_NAME 0x08
#define JBT_OPCODE_SET_LOCAL_DISCOVERY_MODE 0x09
#define JBT_OPCODE_SET_LOCAL_COD 0x0A
#define JBT_OPCODE_GET_REMOTE_NAME 0x0B
#define JBT_OPCODE_GET_REMOTE_ACL_INFO 0x0C
#define JBT_OPCODE_SET_ACL_SECURITY_INFO 0x0D
#define JBT_OPCODE_DEVICE_DISCOVERY_RESULT 0x0E
#define JBT_OPCODE_DEVICE_DISCOVERY_COMPLETED 0x0F
#define JBT_OPCODE_GET_RECORD_HANDLE 0x20
#define JBT_OPCODE_REGISTER_RECORD_RESULT 0x21
#define JBT_OPCODE_DEREGISTER_RECORD_RESULT 0x22
#define JBT_OPCODE_SDAP_RESULT 0x30
#define JBT_OPCODE_SDAP_COMPLETED_RESULT 0x31


/* BCC */
#define JBT_OPCODE_BCC_AUTHORIZE 						0x70
#define JBT_OPCODE_BCC_IS_AUTHORIZED 					0x71
#define JBT_OPCODE_BCC_IS_TRUSTED 						0x72
#define JBT_OPCODE_BCC_GET_HOST_SECURITY_MODE 			0x73
#define JBT_OPCODE_BCC_GET_PREKNOWN_DEVICE_COUNT 		0x74
#define JBT_OPCODE_BCC_GET_PREKNOWN_DEVICES 			0x75
#define JBT_OPCODE_BCC_GET_NATIVE_PWR_STATUS 			0x76

#define JBT_OPCODE_SESSION_CON_IND  0x51
#define JBT_OPCODE_SESSION_CON_CNF  0x52
#define JBT_OPCODE_SESSION_RX_READY_IND 0x53
#define JBT_OPCODE_SESSION_TX_READY_IND 0x54
#define JBT_OPCODE_SESSION_DISCONNECT_IND 0x55
#define JBT_OPCODE_SESSION_REGISTRATION_RESULT 0x56
#define JBT_OPCODE_SESSION_DEREGISTRATION_RESULT 0x57
#define JBT_OPCODE_SESSION_TURN_ON_RESULT 0x58
#define JBT_OPCODE_SESSION_TURN_OFF_RESULT 0x59



#define JBT_OPCODE_SYSTEM_ABNORMAL_RESET 0x99

#define JBT_OPERATION_DISCOVERY_SEARCHING           0x02
#define JBT_OPERATION_DISCOVERY_CANCEL     0x03

#define JBT_CMD_SUCCESS                 0x00
#define JBT_CMD_FAILED                  0x01
#define JBT_CMD_SDP_REGISTER_FAILED        0x02
/* JBT_CMD_INVALID_HANDLE: it is used if the handle for registration or de-registration sdp record  is invalid */
#define JBT_CMD_INVALID_HANDLE  0x03 
/* JBT_CMD_SDP_DEREGISTER_FAILED: It is used if this handle for de-registration sdp record is valid 
  * And it is allocated previously, during de-registration sdp record: 
  * 1.reset this handle first 
  * 2.but its corresponding sdp record is never registered 
  */
#define JBT_CMD_SDP_DEREGISTER_FAILED      0x04
/* JBT_CMD_SDP_DDB_FULL: it is used if no avaliable handle for getting record handle request */
#define JBT_CMD_SDP_DDB_FULL        0x05
#define JBT_CMD_SDP_RECORD_SYNTAX_ERROR     0x06
/* JBT_CMD_SDP_RECORD_TOO_LARGE: It is used if sdp record wanted to be registered is too large */
#define JBT_CMD_SDP_RECORD_TOO_LARGE        0x07
#define JBT_CMD_SDP_RECORD_ATTRIBUTE_BUFFER_TOO_SMALL       0x08
#define JBT_CMD_NOT_SUPPORT     0x09
#define JBT_CMD_WRONG_STATE     0x0A
/* JBT_CMD_SIZE_TOO_LARGE: it is used if search pattern size is too large or registration sdp record size too larger
  * return from jbt_sdap_ss_cmd(), jbt_sdap_sa_cmd(), jbt_sdap_ssa_cmd() and jbt_register_record_cmd() function directly
  */
#define JBT_CMD_SIZE_TOO_LARGE    0x0B
#define JBT_CMD_REJECT_DUE_TO_INQUIRY   0x0C

#define JBT_CMD_REJECT_DUE_TO_POWEROFF 0x0D
#define JBT_CMD_REJECT_CON_REQ_ALREADY_EXISTED  0x0E
#define JBT_CMD_REJECT_NO_RESOURCE  0x0F
#define JBT_CMD_REJECT_WRONG_STATE 0x10

#define JBT_CMD_REJECT_DUE_TO_VM_MINIMIZE   0x11

#define JBT_SECURITY_OFF                                       0x00
#define JBT_SECURITY_AUTHENTICATED                  0x01
#define JBT_SECURITY_ENCRYPTED                           0x02


/* BCC */
#define JBT_SECURITY_MODE_1  (0x01)
#define JBT_SECURITY_MODE_2  (0x02)
#define JBT_SECURITY_MODE_3  (0x03)

#define JBT_BCC_MAX_HOST_DEV_NAME_LEN (47)
/* end of BCC */

/* Service Registration, not SDP record registration */
#define JSR82_SESSION_REGISTRARION_SUCCESS  (0x01)
#define JSR82_SESSION_REGISTRARION_FAILED   (0x02)

#define JSR82_SESSION_TURNON_SUCCESS  (0x01)
#define JSR82_SESSION_TURNON_FAILED   (0x02)

#define JSR82_SESSION_TURNOFF_SUCCESS  (0x01)
#define JSR82_SESSION_TURNOFF_FAILED   (0x02)

#define JSR82_SET_ACL_SECURITY_SUCCESS (0x01)
#define JSR82_SET_ACL_SECURITY_FAILED (0x02)

#define JSR82_SESSION_CONNECT_IND_REQUEST   (0x01)
#define JSR82_SESSION_CONNECT_IND_CONNECTED   (0x02)

#define JSR82_SESSION_PS_RFCOMM  (0x01)
#define JSR82_SESSION_PS_L2CAP   (0x02)

#define JSR82_SESSION_CONNECT_ACCEPT   (0x01)
#define JSR82_SESSION_CONNECT_REJECT   (0x02)

#define JSR82_SESSION_TX_SUCCESS               (0x01)
#define JSR82_SESSION_TX_SIZE_TOO_LARGE   (0x02)
#define JSR82_SESSION_TX_ERROR   (0x03)

#define JSR82_SESSION_MAX_RX_DATA (339)

#define JSR82_SESSION_CONNECT_CLIENT_SUCCESS   (0x00)
#define JSR82_SESSION_CONNECT_CLIENT_FAILED      (0x01)
#define JSR82_SESSION_CONNECT_CLIENT_INVALID_PARMS      (0x02)

#define BT_JSR82_CHANNEL_STATE_IDLE     (0x00)
#define BT_JSR82_CHANNEL_STATE_OPEN     (0x01)

#define BT_JSR82_SESSION_DISABLED_SUCCESS   (0x00)
#define BT_JSR82_SESSION_DISABLED_FAILED   (0x01)

#define JBT_POWEROFF_BY_MMI (0x00)
#define JBT_POWEROFF_BY_JBT (0x01)

#define JSR82_SESSION_PS_RFCOMM_MTU  (330)
#define JSR82_SESSION_PS_L2CAP_MTU   (339)

typedef enum 
{
    JBT_POWER_OFF = 0,
    JBT_POWER_ON,
    /* Bluetooth is in the switch state such as ON to OFF or OFF to ON */ /*COMMENTS*/
    JBT_POWER_OTHERS    
}JBT_POWER_STATE_ENUM;

/* Add by mtk01411: 2007-1128 */
typedef enum
{
    JBT_POWER_OFF_RESTORE_LINK_BIT = 10,
    JBT_POWER_OFF_RESTORE_MMI_BIT,
    JBT_POWER_OFF_RESTORE_COD_BIT,
    JBT_POWER_OFF_RESTORE_MEM_BIT,
    JBT_POWER_ON_WAITING_BIT

}JBT_POWER_OFF_EVENT_ENUM;


#define BT_JSR82_RESTORE_NONE   (0x00)
#define BT_JSR82_RESTORE_LINK  (0x01)
#define BT_JSR82_RESTORE_MMI   (0x02)
#define BT_JSR82_RESTORE_COD   (0x03)
#define BT_JSR82_RESTORE_MEM   (0x04)

/* Definitions for JBT session */
#define JBT_SESSION_TYPE_SPP 1
#define JBT_SESSION_TYPE_L2CAP 2

#define JBT_SESSION_RX_BUF_TYPE 1
#define JBT_SESSION_TX_BUF_TYPE 2

#define JBT_SESSION_FIND_NO_ENTRY -1
#define JBT_SESSION_INVALID_SESSION_TYPE -2
#define JBT_SESSION_INVALID_BUFF_TYPE -3
#define JBT_SESSION_ERR_STATE -4
#define JBT_SESSION_NOT_POWERON -5
#define JBT_SESSION_FAILED_ALLOCATE_RINGBUF -6

typedef struct {
    kal_uint8 result; 
    kal_uint8 bd_addr[6];
}jbt_bcc_authorize_result;

typedef struct {
    kal_uint8 result;
    kal_uint8 bd_addr[6];	
}jbt_bcc_is_authorized_result;

typedef struct {
    kal_uint8 result;
    kal_uint8 bd_addr[6];	
}jbt_bcc_is_trusted_result;

typedef struct {
    kal_uint32 transaction_id;
    kal_uint8 security_mode;	
}jbt_bcc_get_host_security_mode_result;

typedef struct {
    kal_uint32 dev_count;
}jbt_bcc_get_preknown_device_count_result;

typedef struct
{
    kal_uint32 cod;
    kal_uint8 name[JBT_BCC_MAX_HOST_DEV_NAME_LEN];
    kal_uint8 bd_addr[6];
} jbt_bcc_dev_info_struct;

typedef struct {
    kal_uint32	device_count;
    jbt_bcc_dev_info_struct *preknown_dev_p;	
}jbt_bcc_get_preknown_devices_result;

typedef struct {
    kal_uint8 native_pwr_status;	
}jbt_bcc_get_native_pwr_status_result;

/* end of BCC */

typedef struct{
    kal_uint8 result;
    kal_uint8 bd_addr[6];
}jbt_get_local_addr_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 cod;
}jbt_get_local_cod_result;

typedef struct{
    kal_uint8 result;
}jbt_set_local_cod_result;

typedef struct{
    kal_uint8 result;
    kal_uint8 addr[6];
    kal_uint8 name[255];
    kal_uint8 length;
}jbt_get_remote_name_result;


typedef struct{
    kal_uint8 addr[6];
    kal_uint8 name[255];
    kal_uint8 length;
    kal_uint32 cod;
}jbt_device_discovery_entry_result;

typedef struct{
    kal_uint8 result;
}jbt_device_discovery_completed_result;

typedef struct{
    kal_uint8 result;
}jbt_power_on_result;

typedef struct{
    kal_uint8 result;
}jbt_power_off_result;

typedef struct{
    kal_uint8 result;
    kal_bool power_status;
}jbt_get_power_status_result;

typedef struct{
    kal_uint8 result;
    kal_uint8 name[254];
    kal_uint8 name_length;
}jbt_get_local_name_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 mode;
}jbt_get_local_discovery_mode_result;

typedef struct{
    kal_uint8 result;
}jbt_set_local_device_name_result;

typedef struct{
    kal_uint8 result;
}jbt_set_local_discovery_result;


typedef struct{
    kal_uint8 result;
    kal_uint8 is_master;
    kal_uint8 is_authenticated;
    kal_uint8 is_encrypted;
}jbt_get_acl_info_result;


typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 bdAddr[6];
}jbt_set_acl_security_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 record_handle;
}jbt_get_record_handle_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 record_handle;
}jbt_register_record_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 record_handle;
}jbt_deregister_record_result;

typedef struct{
    kal_uint8 addr[6];
    kal_uint16	len;
    kal_uint8	data[100];
}jbt_device_sdap_entry_result;

typedef struct{
    kal_uint8 addr[6];
    kal_uint8 result;
}jbt_device_sdap_completed_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 ps_type;
    kal_uint16 psm_channel;
    kal_uint8 con_id;
}jbt_session_registration_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 ps_type;
    kal_uint8 con_id;
}jbt_session_deregistration_result;


typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 con_id;
}jbt_session_turnon_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 con_id;
}jbt_session_turnoff_result;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 bd_addr[6];
    kal_uint16 con_id;
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint16 l2cap_id;    
}jbt_session_connect_ind;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 con_id;
    kal_uint8 l2cap_id;
}jbt_session_connect_cnf;


/* RX_READY_IND: Application can start to read data from ReadRingBuf again */
typedef struct{
    kal_uint8 con_id;
    kal_uint16 l2cap_id;
    kal_uint16 length;
}jbt_session_rx_ready_ind;

/* TX_READY_IND: Application can start to write data to WriteRingBuf again */
typedef struct{
    kal_uint8 con_id;
    kal_uint16 l2cap_id;
}jbt_session_tx_ready_ind;

typedef struct{
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 con_id;
    kal_uint16 l2cap_id;
}jbt_session_disconnect_ind;


extern kal_bool jbt_power_on_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_power_off_cmd(kal_int32 transaction_id);
extern void jbt_restore_btstack_link_cmd(void);
extern void jbt_restore_mmi_cmd(void);
extern void jbt_restore_btstack_cod(void);
extern void jbt_restore_btstack_memory(void);


extern JBT_POWER_STATE_ENUM jbt_get_power_status_cmd(void);

extern kal_bool jbt_get_local_addr_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_get_local_cod_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_get_local_name_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_set_local_cod_cmd(kal_int32 transaction_id, kal_uint32 cod, kal_uint8* status_result);
extern kal_uint8 jbt_device_discovery_cmd(kal_int32 transaction_id, kal_uint32 iac_code);
extern kal_uint8 jbt_device_discovery_cancel_cmd(kal_int32 transaction_id);
extern kal_bool jbt_get_acl_info_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result);
extern kal_bool jbt_set_acl_security_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8 security_mode, kal_uint8* status_result) ;
extern kal_bool jbt_get_remote_name_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result);
extern kal_bool jbt_get_local_discovery_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_set_local_discovery_cmd(kal_int32 transaction_id, kal_uint32 mode, kal_uint8* status_result);

extern kal_uint8 jbt_get_record_handle_cmd(kal_int32 transaction_id);
extern kal_uint8 jbt_register_record_cmd(kal_int32 transaction_id, kal_uint32 handle, kal_uint8 *record, kal_uint16 rec_size, kal_uint8 type);
extern kal_uint8 jbt_deregister_record_cmd(kal_int32 transaction_id, kal_uint32 handle);
extern kal_uint8 jbt_sdap_ss_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint16 uuid[], kal_uint16 uuid_no);
extern kal_uint8 jbt_sdap_sa_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint32 record_hdl,  kal_uint16 attribute[], kal_uint16 attribute_no);

#ifdef __JBT_SUPPORT_UUID16__
extern kal_uint8 jbt_sdap_ssa_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint16 uuid[], kal_uint16 uuid_no, kal_uint16 attribute[], kal_uint16 attribute_no);
#elif defined (__JBT_SUPPORT_UUID32__)
extern kal_uint8 jbt_sdap_ssa_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint32 uuid[], kal_uint16 uuid_no, kal_uint16 attribute[], kal_uint16 attribute_no);
#else
extern kal_uint8 jbt_sdap_ssa_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8 uuid[], kal_uint16 uuid_no, kal_uint16 attribute[], kal_uint16 attribute_no);
#endif

extern kal_uint32 jbt_get_sdp_delay_ticks(void);

extern kal_bool jbt_authorize_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result);
extern kal_bool jbt_is_authorized_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result);
extern kal_bool jbt_is_trusted_req_cmd(kal_int32 transaction_id, kal_uint8 *addr, kal_uint8* status_result);
extern kal_bool jbt_get_host_security_mode_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_get_preknown_device_count_req_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_get_preknown_devices_req_cmd(kal_int32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_get_native_pwr_status_req_cmd(kal_int32 transaction_id);


extern kal_bool jbt_session_service_registration(kal_uint8 ps_type, kal_uint16 mtu, kal_uint8 security, kal_uint32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_session_service_turn_on(kal_uint8 ps_type, kal_uint8 con_id, kal_uint32 transaction_id, kal_uint8* status_result);
extern kal_bool jbt_session_service_turn_off(kal_uint8 ps_type, kal_uint8 con_id, kal_uint32 transaction_id, kal_uint8* status_result);

extern kal_bool jbt_session_service_deregistration(kal_uint8 ps_type, kal_uint32 transaction_id, kal_uint8 con_id, kal_uint8* status_result);
extern kal_bool jbt_session_connect_req(kal_uint32 transaction_id,
                                                    kal_uint8* bd_addr, 
                                                    kal_uint8 ps_type,
                                                    kal_uint16 psm_channel, 
                                                    kal_uint16 mtu, 
                                                    kal_uint8 security_value,
                                                    kal_uint8* status_result);
extern kal_bool jbt_session_disconnect_req(kal_uint32 transaction_id,kal_uint8 ps_type, kal_uint8 con_id, kal_uint16 l2cap_id, kal_uint8* status_result);
extern kal_bool jbt_check_inquiry_operation_ongoing(void);
extern kal_bool jbt_check_inquiry_operation_in_cmdlist(void);
extern void jbt_set_mem_pool_id(KAL_ADM_ID jbt_mem_pool_id);
extern KAL_ADM_ID jbt_get_mem_pool_id(void);
extern kal_uint8* jbt_get_adm_mem_start_addr(void);
extern kal_uint8* jbt_get_adm_mem_end_addr(void);
#endif /* _JBT_INTERFACE_H */ 
#endif /* __SUPPORT_JBT__ */
