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
 *  jwa_interface.h
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
 * -------
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

#ifndef _JWA_INTERFACE_H
#define _JWA_INTERFACE_H

#define  J2ME_MMS_LOCAL_PARAMETER_ARRAY_LEN  99
#define  J2ME_MMS_PEER_BUFFER_LEN            2048
#define  J2ME_MMS_MAX_FILE_PATH_LEN    64
#define  J2ME_MMS_REGISTER_APPID_NUM         10
#define  J2ME_MMS_MMSC_ADDR_LEN              128

typedef struct
{
    kal_uint8 mms_type;
    kal_uint8 priority;
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bcc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint64 delivery_time;
    kal_uint8 app_id_len;
    kal_uint8 reply_app_id_len;
    kal_uint8 start_cnt_id_len;
    kal_uint8 app_id[100];
    kal_uint8 reply_app_id[100];
    kal_uint8 start_cnt_id[100];
} jwa_mms_send_req_struct;

typedef struct
{
    kal_uint8 encoding_scheme;
    kal_uint8 content_type_len;
    kal_uint8 content_type[256];
    kal_uint8 content_id_len;
    kal_uint8 content_id[100];
    kal_uint8 content_location_len;
    kal_uint8 content_location[100];
    kal_uint8 filepath_len;
    kal_uint8 filepath[100];
} jwa_mms_send_msg_part_req_struct;

typedef struct
{
    kal_uint8 priority;
    kal_uint8 from_addr_no;
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint64 date;
    kal_uint8 start_cnt_id_len;
    kal_uint8 *start_cnt_id;
    kal_uint8 reply_app_id_len;
    kal_uint8 *reply_app_id;
    kal_uint16 msg_info_len;
    kal_uint8 *msg_info;
} jwa_mms_receive_msg_struct;

typedef struct
{
    kal_uint8 encoding_scheme;
    kal_uint8 content_type_len;
    kal_uint8 *content_type;
    kal_uint8 content_id_len;
    kal_uint8 *content_id;
    kal_uint8 content_location_len;
    kal_uint8 *content_location;
    kal_uint32 file_size;
} jwa_mms_receive_msg_part_struct;

typedef struct
{
    kal_uint8 filepath_len;
    kal_uint8 filepath[100];
    kal_uint32 file_size;
} jwa_mms_receive_msg_part_content_struct;

typedef struct
{
    void *mms_req_ptr;     //save the local_para for the operation
    void *mms_req_buff;     //save the peer_buff for the operation
    kal_uint8 pending_operation;   //jwa_mms_state_enum
    kal_int32 vm_id;
} jwa_mms_pending_operation_struct;

typedef enum
{
    J2ME_MMS_REGISTER = 0,
    J2ME_MMS_DEREGISTER = 1
} J2me_mms_register_type_enum;

typedef enum
{
    J2ME_MMS_PRIORITY_LOW = 0,
    J2ME_MMS_PRIORITY_MEDIUM = 1,
    J2ME_MMS_PRIORITY_HIGH = 2
} J2me_mms_priority_enum;

typedef enum
{
    J2ME_MMS_RELATED = 0,
    J2ME_MMS_MIXED = 1
} J2me_mms_msg_type_enum;

typedef enum
{
    J2ME_MMS_OK,
    J2ME_MMS_INVALID_PARAMETER,
    J2ME_MMS_EMPTY_MSG_CONTENT_PART,
    J2ME_MMS_READ_MSG_CONTENT_PART_FILE_ERROR,
    J2ME_MMS_INVALID_SIM,    /* No SIM or block SIM */
    J2ME_MMS_NOT_AVAILABLE,
    J2ME_MMS_END
} J2me_mms_result_enum;

typedef enum
{
    MSG_MMS_CFG_APPMMS_APPID_RSP = 1,
    MSG_MMS_SEND_APPMMS_RSP = 2,
    MSG_MMS_POST_APPMMS_MSG_PART_IND = 3,
    MSG_MMS_RECV_APPMMS_RSP = 4,
    MSG_MMS_READ_APPMMS_CONTENT_RSP = 5,
    MSG_MMS_CHECK_APPMMS_COMING_RSP = 6
} J2me_mms_reply_enum;

typedef enum
{
    J2ME_MMS_ADDR_TYPE_MSISDN = 0,
    J2ME_MMS_ADDR_TYPE_EMAIL = 1,
    J2ME_MMS_ADDR_TYPE_IPV4 = 2,
    J2ME_MMS_ADDR_TYPE_IPV6 = 3,
    J2ME_MMS_ADDR_TYPE_SHORTCODE = 4
} J2me_mms_address_type_enum;

typedef enum
{
    J2ME_MMS_ENCODING_TYPE_ISO_8859_1 = 4,
    J2ME_MMS_ENCODING_TYPE_US_ASCII = 3,
    J2ME_MMS_ENCODING_TYPE_UTF8 = 106,
    J2ME_MMS_ENCODING_TYPE_UCS2 = 1000,
    J2ME_MMS_ENCODING_TYPE_UTF16 = 1015,
    J2ME_MMS_ENCODING_TYPE_UNKNOWN_CHARSET = 0
} J2me_mms_encoding_type_enum;

typedef enum
{
    JWA_MMS_STATE_IDLE,
    JWA_MMS_STATE_SEND,
    JWA_MMS_STATE_CHECK_INCOMING_MSG,
    JWA_MMS_STATE_GET_INCOMING_MSG,
    JWA_MMS_STATE_REGISTER_APPID,
    JWA_MMS_STATE_ABORT,
    JWA_MMS_STATE_END
} jwa_mms_state_enum;


extern kal_bool jwa_mms_register(int app_id_len, char *app_id, int operation, int type, int vm_id);
extern int jwa_mms_send_message(jwa_mms_send_req_struct *send_data, kal_uint32 msg_info_len, kal_uint8 *msg_info, int vm_id);
extern int jwa_mms_send_message_part(jwa_mms_send_msg_part_req_struct *send_msg_part_data);
extern int jwa_mms_get_message_req(int app_id_length, char *app_id, int vm_id);
extern int jwa_mms_get_message_part_req(int more);
extern int jwa_mms_check_incoming_message(int app_id_len, char *app_id, kal_bool only_new, int vm_id);
extern int jwa_mms_get_message(jwa_mms_receive_msg_struct *receive_data);
extern int jwa_mms_get_mseesag_part(jwa_mms_receive_msg_part_struct *receive_msg_part);
extern int jwa_mms_get_message_part_content(jwa_mms_receive_msg_part_content_struct *receive_msg_part);
extern int jwa_mms_get_primitive_result(void);
extern int jwa_mms_get_response_primitive(void);
extern kal_int32 jwa_mms_initialize(void);
extern kal_int32 jwa_mms_finalize(void);
extern kal_char* jwa_mms_get_mmsc_addr (void);

/* ////////////////////////////////////////////////////////////////////////////////// */

typedef struct
{
    void *sms_req_ptr;     //save the local_para for the operation
    kal_uint8 pending_operation;   //jwa_sms_state_enum
    kal_int32 vm_id;
} jwa_sms_pending_operation_struct;

typedef enum
{
    MSG_J2ME_SMS_SEND_RSP = 1,
    MSG_J2ME_SMS_CHECK_INCOMING_MSG_RSP = 2,
    MSG_J2ME_SMS_GET_INCOMING_MSG_RSP = 3,
    MSG_J2ME_SMS_REGISTER_PORT_RSP = 4
} J2me_sms_reply_enum;

typedef enum
{
    MSG_J2ME_SMS_TEXT = 0,
    MSG_J2ME_SMS_BINARY = 1
} J2me_sms_receive_type_enum;

typedef enum
{
    J2ME_SMS_OK,
    J2ME_SMS_BLOCK,
    J2ME_SMS_PORT_IN_USE,
    J2ME_SMS_PORT_NOT_IN_USE,
    J2ME_SMS_CONTENT_SIZE_EXCEED,
    J2ME_SMS_PORT_IN_USE_BY_PUSH,
    J2ME_SMS_NOT_AVAILABLE,
    J2ME_SMS_END
} J2me_sms_result_enum;

typedef enum
{
    JWA_SMS_STATE_IDLE,
    JWA_SMS_STATE_SEND,
    JWA_SMS_STATE_CHECK_INCOMING_MSG,
    JWA_SMS_STATE_GET_INCOMING_MSG,
    JWA_SMS_STATE_REGISTER_PORT,
    JWA_SMS_STATE_SEND_ABORT,
    JWA_SMS_STATE_END
} jwa_sms_state_enum;


typedef enum
{
    JWA_SMS_SIM_TYPE_SIM1,
    JWA_SMS_SIM_TYPE_SIM2,
    JWA_SMS_SIM_TYPE_SIM3,
    JWA_SMS_SIM_TYPE_SIM4,
    JWA_SMS_SIM_TYPE_END    
} J2me_sms_sim_type_enum;

extern int jwa_sms_register(long portNumber, int type, int vm_id);
extern int jwa_sms_send_binary_message(unsigned short *addr, char *pBuffer, int buflength, long portNumber, int vm_id);
extern int jwa_sms_send_text_message(unsigned short *addr, unsigned short *pBuffer, int buflength, long portNumber, int vm_id);
extern int jwa_sms_check_incoming_msg(long portNumber, kal_bool only_new , int *result);
extern int jwa_sms_receive_binary_msg_req(long portNumber);
extern char *jwa_sms_receive_binary_msg_rsp(int *len);
extern int jwa_sms_receive_text_msg_req(long portNumber);
extern unsigned short *jwa_sms_receive_text_msg_rsp(int *len);
extern int jwa_sms_number_of_text_segments(unsigned short *pBuffer, int pBufferLen);
extern int jwa_sms_number_of_binary_segments(char *pBuffer, int pBufferLen);
extern int jwa_sms_unregister(long portNumber, int type, int vm_id);
extern kal_uint64 jwa_sms_get_timestamp(long portNumber);
extern unsigned short *jwa_sms_get_incoming_msg_addr(long portNumber, int *len);
extern int jwa_sms_get_primitive_result(void);
extern int jwa_sms_get_response_primitive(void);
extern kal_int32 jwa_sms_initialize(void);
extern kal_int32 jwa_sms_finalize(void);
extern int jwa_sms_get_state(void);

extern void jwa_sms_register_callback(void (*callback_ptr)(int , int , int ));
extern void jwa_sms_deregister_callback(void);
extern void jwa_sms_callback_handler(int result, J2me_sms_reply_enum eventMsg, int vm_id);
extern kal_char *jwa_sms_get_smsc_addr(void);

#endif /* _JWA_INTERFACE_H */ 

