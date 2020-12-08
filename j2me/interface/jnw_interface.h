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
 *  jnw_interface.h
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

#ifndef _JNW_INTERFACE_H
#define _JNW_INTERFACE_H

#include "wps_struct.h"
#include "soc_consts.h"
#ifdef __SSL_SUPPORT__
#ifndef _TLS_APP_ENUMS_H_
#include "tls_app_enums.h"
#endif
#ifndef _TLS_CONST_H_
#include "tls_const.h"
#endif
#endif /* __SSL_SUPPORT__ */

/* define the server socket compile option */
#ifndef  __OP01__
#define __JAVA_SUPPORT_SERVER_SOCKET__  1
#endif

/*************************************************************************
 * Constants
*************************************************************************/
/*************************HTTP over WSP**********************************/
/* Maximum segment size of HTTP get/post/head response */
/* The suggested maximum value is 1024 bytes */
#define J2ME_HTTP_WPS_MAX_RSP_BUFFER   1024

/* Maximum segment size of HTTP read content response  */
/* The suggested maximum value is 2000 bytes */
#define J2ME_HTTP_WPS_MAX_INPUT_BUFFER  2000

#define jnw_get_http_block_size()			(J2ME_HTTP_WPS_MAX_INPUT_BUFFER)

/* The maximum time in seconds to wait HTTP response */
#define J2ME_HTTP_WPS_TIMEOUT   90

/*************************Socket**********************************/
/* current max socket number supported by java socket */
#define J2ME_MAX_SOC_NUM (MAX_IP_SOCKET_NUM)
/* current max dns number */
#define J2ME_MAX_DNS_NUM (5)

/* error cause */
#define IO_SUCCESS                                 (0)
#define IO_ERROR                                   (-1)
#define IO_WOULDBLOCK                              (-2)
#define IO_INTERRUPTED                             (-3)
#define IO_LIMIT_RESOURCE                          (-4)
#define IO_NEED_REHANDSHAKE                        (-5)
#define IO_BAD_CERT                                (-6)
#define IO_CHECK_CLIENT_CERT_AGAIN                 (-7)

/*************************SSL/TLS**********************************/
#ifdef __SSL_SUPPORT__
#define J2ME_TLS_MAX_CLIENT_AUTH	(TLS_MAX_CLIENT_AUTH) /* SSL_MAX_CLIENT_AUTH_MODES */
#endif

/*************************HTTP**********************************/
#define J2ME_MAX_APP_NUM   (MAX_VM_INSTANCE_NUM + 1)    /* max supported application numbers */
#define J2ME_HTTP_INSTALL_APP_ID    (MAX_VM_INSTANCE_NUM + 1) /* installer application id */

/*************************************************************************
 * Enums
 *************************************************************************/
/*************************HTTP over WSP**********************************/
/* HTTP response message type */
/* MUST the same as HTTP.protocol  */
typedef enum
{
    MSG_WPS_SET_CHANNEL_RSP = 1,
    MSG_WPS_UNSET_CHANNEL_RSP = 2,
    MSG_WPS_HTTP_RSP = 3,
    MSG_WPS_READ_CONTENT_RSP = 4,
    MSG_WPS_POST_CONTENT_IND = 5,
    MSG_WPS_SEC_GET_SESSION_INFO_RSP = 6,
    MSG_WPS_SEC_GET_CURRENT_CERT_RSP = 7,
    MSG_WPS_CANCEL_RSP = 8,
    MSG_WPS_CLEAR_RSP = 9,
    MSG_WPS_HTTP_AUTH_IND = 10,

    MSG_WPS_CREATE_STREAM_CONNECTION_RSP = 11,
    MSG_WPS_CLOSE_STREAM_CONNECTION_RSP = 12,
    MSG_WPS_STREAM_DATA_SEND_RSP = 13,
    MSG_WPS_STREAM_DATA_READ_RSP = 14,
    
    MSG_WPS_END
} J2me_http_wps_reply_enum;

/* HTTP/HTTPS Protocol type */
typedef enum
{
    J2ME_HTTP_WPS_CHANNEL_HTTP = 0,
    J2ME_HTTP_WPS_CHANNEL_HTTPS = 1
} J2me_http_wps_channel_enum;

/* HTTP method type */
/* MUST the same as httpOutputStream.java  */
typedef enum
{
    J2ME_HTTP_METHOD_GET = 0,
    J2ME_HTTP_METHOD_HEAD = 1,
    J2ME_HTTP_METHOD_POST = 2
} J2me_http_wps_method_enum;

typedef enum
{
    J2ME_SEC_CONNECTION_TYPE_TLS = WPS_SEC_CONNECTION_TYPE_TLS,
    J2ME_SEC_CONNECTION_TYPE_WTLS = WPS_SEC_CONNECTION_TYPE_WTLS,
    J2ME_SEC_CONNECTION_TYPE_SSL = WPS_SEC_CONNECTION_TYPE_SSL
} J2me_http_security_connection_type_enum;

typedef enum
{
    /* The WTLS key exchange of cipher suite */
    J2ME_SEC_WTLS_KEY_EXCH_NULL = WPS_SEC_WTLS_KEY_EXCH_NULL,
    J2ME_SEC_WTLS_KEY_EXCH_SHARED_SECRET = WPS_SEC_WTLS_KEY_EXCH_SHARED_SECRET,
    J2ME_SEC_WTLS_KEY_EXCH_DH_ANON = WPS_SEC_WTLS_KEY_EXCH_DH_ANON,
    J2ME_SEC_WTLS_KEY_EXCH_DH_ANON_512 = WPS_SEC_WTLS_KEY_EXCH_DH_ANON_512,
    J2ME_SEC_WTLS_KEY_EXCH_DH_ANON_768 = WPS_SEC_WTLS_KEY_EXCH_DH_ANON_768,
    J2ME_SEC_WTLS_KEY_EXCH_RSA_ANON = WPS_SEC_WTLS_KEY_EXCH_RSA_ANON,
    J2ME_SEC_WTLS_KEY_EXCH_RSA_ANON_512 = WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_512,
    J2ME_SEC_WTLS_KEY_EXCH_RSA_ANON_768 = WPS_SEC_WTLS_KEY_EXCH_RSA_ANON_768,
    J2ME_SEC_WTLS_KEY_EXCH_RSA = WPS_SEC_WTLS_KEY_EXCH_RSA,
    J2ME_SEC_WTLS_KEY_EXCH_RSA_512 = WPS_SEC_WTLS_KEY_EXCH_RSA_512,
    J2ME_SEC_WTLS_KEY_EXCH_RSA_768 = WPS_SEC_WTLS_KEY_EXCH_RSA_768,
    J2ME_SEC_WTLS_KEY_EXCH_ECDH_ANON = WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON,
    J2ME_SEC_WTLS_KEY_EXCH_ECDH_ANON_113 = WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_113,
    J2ME_SEC_WTLS_KEY_EXCH_ECDH_ANON_131 = WPS_SEC_WTLS_KEY_EXCH_ECDH_ANON_131,
    J2ME_SEC_WTLS_KEY_EXCH_ECDH_ECDSA = WPS_SEC_WTLS_KEY_EXCH_ECDH_ECDSA
} J2me_http_key_exchange_WTLS_enum;

typedef enum
{
    /* The TLS key exchange of cipher suite */
    J2ME_SEC_TLS_KEYEXCH_NULL = WPS_SEC_TLS_KEYEXCH_NULL,
    J2ME_SEC_TLS_KEYEXCH_RSA = WPS_SEC_TLS_KEYEXCH_RSA,
    J2ME_SEC_TLS_KEYEXCH_RSA_EXPORT = WPS_SEC_TLS_KEYEXCH_RSA_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DH_DSS_EXPORT = WPS_SEC_TLS_KEYEXCH_DH_DSS_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DH_DSS = WPS_SEC_TLS_KEYEXCH_DH_DSS,
    J2ME_SEC_TLS_KEYEXCH_DH_RSA_EXPORT = WPS_SEC_TLS_KEYEXCH_DH_RSA_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DH_RSA = WPS_SEC_TLS_KEYEXCH_DH_RSA,
    J2ME_SEC_TLS_KEYEXCH_DHE_DSS_EXPORT = WPS_SEC_TLS_KEYEXCH_DHE_DSS_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DHE_DSS = WPS_SEC_TLS_KEYEXCH_DHE_DSS,
    J2ME_SEC_TLS_KEYEXCH_DHE_RSA_EXPORT = WPS_SEC_TLS_KEYEXCH_DHE_RSA_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DHE_RSA = WPS_SEC_TLS_KEYEXCH_DHE_RSA,
    J2ME_SEC_TLS_KEYEXCH_DH_ANON_EXPORT = WPS_SEC_TLS_KEYEXCH_DH_ANON_EXPORT,
    J2ME_SEC_TLS_KEYEXCH_DH_ANON = WPS_SEC_TLS_KEYEXCH_DH_ANON
} J2me_http_key_exchange_TLS_enum;

typedef enum
{
    J2ME_SEC_CIPHER_NULL = WPS_SEC_CIPHER_NULL,
    J2ME_SEC_CIPHER_RC5_CBC_40 = WPS_SEC_CIPHER_RC5_CBC_40,
    J2ME_SEC_CIPHER_RC5_CBC_56 = WPS_SEC_CIPHER_RC5_CBC_56,
    J2ME_SEC_CIPHER_RC5_CBC = WPS_SEC_CIPHER_RC5_CBC,
    J2ME_SEC_CIPHER_DES_CBC_40 = WPS_SEC_CIPHER_DES_CBC_40,
    J2ME_SEC_CIPHER_DES_CBC = WPS_SEC_CIPHER_DES_CBC,
    J2ME_SEC_CIPHER_3DES_CBC_EDE = WPS_SEC_CIPHER_3DES_CBC_EDE,
    J2ME_SEC_CIPHER_IDEA_CBC_40 = WPS_SEC_CIPHER_IDEA_CBC_40,
    J2ME_SEC_CIPHER_IDEA_CBC_56 = WPS_SEC_CIPHER_IDEA_CBC_56,
    J2ME_SEC_CIPHER_IDEA_CBC = WPS_SEC_CIPHER_IDEA_CBC,
    J2ME_SEC_CIPHER_RC5_CBC_64 = WPS_SEC_CIPHER_RC5_CBC_64,
    J2ME_SEC_CIPHER_IDEA_CBC_64 = WPS_SEC_CIPHER_IDEA_CBC_64,
    J2ME_SEC_CIPHER_RC2_CBC_40 = WPS_SEC_CIPHER_RC2_CBC_40,
    J2ME_SEC_CIPHER_RC4_40 = WPS_SEC_CIPHER_RC4_40,
    J2ME_SEC_CIPHER_RC4_128 = WPS_SEC_CIPHER_RC4_128,
    J2ME_SEC_CIPHER_AES_CBC_128 = WPS_SEC_CIPHER_AES_CBC_128
} J2me_http_cipher_enum;

typedef enum
{
    /* The hash algorithms of cipher suite */
    J2ME_SEC_HASH_NULL = WPS_SEC_HASH_NULL,
    J2ME_SEC_HASH_MD5 = WPS_SEC_HASH_MD5,
    J2ME_SEC_HASH_SHA = WPS_SEC_HASH_SHA,
    J2ME_SEC_HASH_MD2 = WPS_SEC_HASH_MD2
} J2me_http_hash_enum;

typedef enum
{
    J2ME_SEC_CERT_FORMAT_WTLS = WPS_SEC_CERT_FORMAT_WTLS,
    J2ME_SEC_CERT_FORMAT_X509 = WPS_SEC_CERT_FORMAT_X509
} J2me_http_certificate_type_enum;

typedef enum
{
    J2ME_HTTP_OK = 0,
    J2ME_HTTP_ERROR = -1,
    J2ME_HTTP_WOULDBLOCK = -2,
    J2ME_HTTP_ABORT = -3,
    J2ME_HTTP_ABM_WOULDBLOCK = -4
} J2me_http_error_enum;

typedef enum
{
    J2ME_SEC_OK = WPS_SEC_OK,
    J2ME_SEC_ERR_INSUFFICIENT_MEMORY = WPS_SEC_ERR_INSUFFICIENT_MEMORY,
    J2ME_SEC_ERR_INVALID_PARAMETER = WPS_SEC_ERR_INVALID_PARAMETER,
    J2ME_SEC_ERR_CRYPTOLIB_NOT_INITIALISED = WPS_SEC_ERR_CRYPTOLIB_NOT_INITIALISED,
    J2ME_SEC_ERR_INVALID_KEY = WPS_SEC_ERR_INVALID_KEY,
    J2ME_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE = WPS_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE,
    J2ME_SEC_ERR_BAD_CERTIFICATE = WPS_SEC_ERR_BAD_CERTIFICATE,
    J2ME_SEC_ERR_CERTIFICATE_EXPIRED = WPS_SEC_ERR_CERTIFICATE_EXPIRED,
    J2ME_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE = WPS_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE,
    J2ME_SEC_ERR_GENERAL_ERROR = WPS_SEC_ERR_GENERAL_ERROR,
    J2ME_SEC_ERR_NOT_READY = WPS_SEC_ERR_NOT_READY
} jnw_http_sec_result_error_enum;

/*************************Socket**********************************/
/* asyn event callback enum */
typedef enum 
{
    J2ME_ASYN_EVENT_DEFAULT,
    J2ME_NOTIFY_IND,
    J2ME_HOST_NAME,
    J2ME_HOST_ADDR,
    J2ME_BEARER_INFO,
    J2ME_ASYN_EVENT_TOTAL
} jnw_soc_asyn_ind_enum;

typedef enum
{
    JNW_SOC_ERROR_DEFAULT,
    JNW_SOC_ERROR_GET_IP_FAIL,
    JNW_SOC_ERROR_OPEN_FAIL,
    JNW_SOC_ERROR_ARGUMENT,
    JNW_SOC_ERROR_CONNECT_FAIL,
    JNW_SOC_ERROR_TOTAL
} jnw_soc_error_type_enum;

typedef enum
{
    JNW_SOC_SHUT_RD = 0x01,         /* shut down the reading side */
    JNW_SOC_SHUT_WR  = 0x02,         /* shut down the writing side */
    JNW_SOC_SHUT_RDWR = JNW_SOC_SHUT_RD | JNW_SOC_SHUT_WR   /* shut down both sides */
} jnw_soc_shutdown_enum;

/*************************TLS**********************************/

#ifdef __SSL_SUPPORT__
/* TLS response message type */
typedef enum
{
    MSG_TLS_NOTIFY_IND = 1,
    MSG_TLS_ALERT_IND = 2,
    MSG_TLS_INVALID_CERT_IND = 3,
    MSG_TLS_CLIENT_AUTH_IND = 4,    
    MSG_TLS_END
} jnw_tls_reply_enum;

typedef enum 
{
    JNW_TLS_HANDSHAKE_READY_EVENT   = TLS_HANDSHAKE_READY,
    JNW_TLS_HANDSHAKE_DONE_EVENT    = TLS_HANDSHAKE_DONE,
    JNW_TLS_READ_EVENT           	= TLS_READ,
    JNW_TLS_WRITE_EVENT          	= TLS_WRITE,
    JNW_TLS_CLOSE_EVENT          	= TLS_CLOSE
} jnw_tls_event_enum;

typedef enum 
{
    JNW_TLS_ALERT_LV_WARNING = TLS_ALERT_LV_WARNING,
    JNW_TLS_ALERT_LV_FATAL = TLS_ALERT_LV_FATAL
} jnw_tls_alert_level_enum;

typedef enum 
{
    JNW_TLS_ALERT_CLOSE_NOTIFY                = TLS_ALERT_CLOSE_NOTIFY,
    JNW_TLS_ALERT_UNEXPECTED_MESSAGE          = TLS_ALERT_UNEXPECTED_MESSAGE,
    JNW_TLS_ALERT_BAD_RECORD_MAC              = TLS_ALERT_BAD_RECORD_MAC,
    JNW_TLS_ALERT_DECRYPTION_FAILED           = TLS_ALERT_DECRYPTION_FAILED,
    JNW_TLS_ALERT_RECORD_OVERFLOW             = TLS_ALERT_RECORD_OVERFLOW,
    JNW_TLS_ALERT_DECOMPRESSION_FAILURE       = TLS_ALERT_DECOMPRESSION_FAILURE,
    JNW_TLS_ALERT_HANDSHAKE_FAILURE           = TLS_ALERT_HANDSHAKE_FAILURE,
    JNW_TLS_ALERT_NOCERTIFICATE_RESERVED      = TLS_ALERT_NOCERTIFICATE_RESERVED,
    JNW_TLS_ALERT_BAD_CERTIFICATE             = TLS_ALERT_BAD_CERTIFICATE,
    JNW_TLS_ALERT_UNSUPPORTED_CERTIFICATE     = TLS_ALERT_UNSUPPORTED_CERTIFICATE,
    JNW_TLS_ALERT_CERTIFICATE_REVOKED         = TLS_ALERT_CERTIFICATE_REVOKED,
    JNW_TLS_ALERT_CERTIFICATE_EXPIRED         = TLS_ALERT_CERTIFICATE_EXPIRED,
    JNW_TLS_ALERT_CERTIFICATE_UNKNOWN         = TLS_ALERT_CERTIFICATE_UNKNOWN,
    JNW_TLS_ALERT_ILLEGAL_PARAMETER           = TLS_ALERT_ILLEGAL_PARAMETER,
    JNW_TLS_ALERT_UNKNOWN_CA                  = TLS_ALERT_UNKNOWN_CA,
    JNW_TLS_ALERT_ACCESS_DENIED               = TLS_ALERT_ACCESS_DENIED,
    JNW_TLS_ALERT_DECODE_ERROR                = TLS_ALERT_DECODE_ERROR,
    JNW_TLS_ALERT_DECRYPT_ERROR               = TLS_ALERT_DECRYPT_ERROR,
    JNW_TLS_ALERT_EXPORT_RESTRICTION_RESERVED = TLS_ALERT_EXPORT_RESTRICTION_RESERVED,
    JNW_TLS_ALERT_PROTOCOL_VERSION            = TLS_ALERT_PROTOCOL_VERSION,
    JNW_TLS_ALERT_INSUFFICIENT_SECURITY       = TLS_ALERT_INSUFFICIENT_SECURITY,
    JNW_TLS_ALERT_INTERNAL_ERROR              = TLS_ALERT_INTERNAL_ERROR,
    JNW_TLS_ALERT_USER_CANCELLED              = TLS_ALERT_USER_CANCELLED,
    JNW_TLS_ALERT_NO_RENEGOTIATION            = TLS_ALERT_NO_RENEGOTIATION
} jnw_tls_alert_desc_enum;

typedef enum 
{
    JNW_TLS_USER_REJECT          = TLS_USER_REJECT,
    JNW_TLS_USER_ACCEPT_ONCE     = TLS_USER_ACCEPT_ONCE,
    JNW_TLS_USER_ACCEPT_FOREVER  = TLS_USER_ACCEPT_FOREVER
} jnw_tls_inval_cert_action;

typedef enum 
{
    JNW_TLS_CLIENT_AUTH_BEGIN		= TLS_CLIENT_AUTH_BEGIN,
    JNW_TLS_CLIENT_AUTH_RSA_CLIENT	= TLS_CLIENT_AUTH_RSA_CLIENT,
    JNW_TLS_CLIENT_AUTH_RSA_SERVER	= TLS_CLIENT_AUTH_RSA_SERVER,
    JNW_TLS_CLIENT_AUTH_DSS_CLIENT	= TLS_CLIENT_AUTH_DSS_CLIENT,
    JNW_TLS_CLIENT_AUTH_DSS_SERVER	= TLS_CLIENT_AUTH_DSS_SERVER,
    JNW_TLS_CLIENT_AUTH_END 		= TLS_CLIENT_AUTH_END
} jnw_tls_auth_mode_enum;
#endif /* __SSL_SUPPORT__ */

/*************************************************************************
 * Structures
 *************************************************************************/
/*************************HTTP over WSP**********************************/
typedef struct
{
    kal_uint32 cert_len;  /* length of  cert */
    kal_uint8 *cert; /* raw data of certificate */
    kal_uint8 format; /* J2me_http_certificate_type_enum */    
} jnw_http_sec_certificate_struct;

typedef struct
{
    kal_uint32 cert_len;  /* cert file size */
    kal_uint16* cert_file_path; /* cert file patch in UCS2 with null terminator */
    kal_uint8 format; /* J2me_http_certificate_type_enum */    
} jnw_http_sec_certificate_file_struct;

/*************************Socket**********************************/
/* added to save global memory space */
typedef struct
{
    kal_bool    result;
    kal_int32	request_id;
    kal_uint8   access_id;
    kal_uint8	addr_len;   /* the first record in entry,  */
    kal_uint8	addr[16];   /* for backward compatibility */
    
    /* New for DNS query reply for reporting bearer fail */
    kal_int8    error_cause;   /* bearer fail */
    kal_int32   detail_cause;  /* refer to ps_cause_enum if error_cause
                                * is SOC_BEARER_FAIL */
} j2me_soc_get_host_by_name_ind_struct;

typedef void (*java_async_callback_fn)(void *ind_ptr);
typedef struct  
{
    java_async_callback_fn notify_callback;
    java_async_callback_fn gethostbyname_callback;
    java_async_callback_fn gethostbyaddr_callback;
    java_async_callback_fn bearer_callback;    
}java_asyn_ind_table;

/*************************************************************************
 * Extern APIs
 *************************************************************************/
/*************************HTTP over WSP**********************************/
extern kal_int32 jnw_http_get_current_response_req_id(void *data, kal_uint32 msg_id);
extern kal_uint32 jnw_http_get_req_id(kal_uint32 channelType);
extern kal_int32 jnw_http_get_status(void *data, kal_uint32 msg_id);
extern kal_bool jnw_http_chk_status_code(kal_uint16 status);
extern kal_uint8* jnw_http_get_status_message(kal_uint16 status);
extern kal_bool jnw_http_check_more(void *data, kal_uint32 msg_id);
extern kal_int32 jnw_http_get_reply_header_length(void *data);
extern kal_bool jnw_http_get_reply_header(void *data, kal_uint8 *header);
extern kal_int32 jnw_http_get_reply_segment_length(void *data, kal_int32 msg_id);
extern kal_bool jnw_http_get_reply_segment(void *data, kal_uint8 *seg, kal_int32 msg_id);
extern kal_int8 jnw_http_set_time_out(kal_uint32 vm_id, kal_uint32 time_val);
extern kal_int8 jnw_http_open_connection(kal_uint32 vm_id, kal_uint32 req_id);
extern kal_int8 jnw_http_close_connection(kal_uint32 vm_id, kal_uint32 req_id);
extern kal_int8 jnw_http_read_req(kal_uint32 req_id, kal_int32 seq_no);
extern kal_int8 jnw_http_set_auto_return_auth(kal_uint32 vm_id, kal_bool auth);
extern kal_int8 jnw_http_write_req(
            kal_uint32 vm_id,
            kal_uint32 req_id,
            kal_uint32 http_method,
            kal_uint32 url_length,
            kal_uint8 *url,
            kal_uint32 header_length,
            kal_uint8 *header,
            kal_uint32 total_post_content_length,
            kal_uint32 post_segment_length,
            kal_uint8 *post_segment,
                    kal_bool more_post);
extern kal_int8 jnw_http_write_content_req(
            kal_uint32 req_id,
            kal_uint32 seq_no,
            kal_uint32 post_segment_length,
            kal_uint8 *post_segment,
                    kal_bool more_post);
extern kal_int8 jnw_https_get_security_info_req(kal_uint32 vm_id);
extern kal_int8 jnw_https_get_certificate_req(kal_uint32 vm_id);
extern kal_int32 jnw_https_get_security_info_sec_conn_type(void *data);
extern kal_int32 jnw_https_get_security_info_key_exchange_alg(void *data);
extern kal_int32 jnw_https_get_security_info_bulk_encryption_alg(void *data);
extern kal_int32 jnw_https_get_security_info_sec_hash_alg(void *data);
extern kal_int32 jnw_https_get_certificate_issuer_length(void *data);
extern kal_int32 jnw_https_get_certificate_serial_num_length(void *data);
extern kal_int32 jnw_https_get_certificate_sig_alg_name_length(void *data);
extern kal_int32 jnw_https_get_certificate_subject_length(void *data);
extern kal_uint8 *jnw_https_get_certificate_issuer(void *data);
extern kal_uint8 *jnw_https_get_certificate_serial_num(void *data);
extern kal_uint8 *jnw_https_get_certificate_sig_alg_name(void *data);
extern kal_uint8 *jnw_https_get_certificate_subject(void *data);
extern kal_int32 jnw_https_get_certificate_type(void *data);
extern kal_int32 jnw_https_get_certificate_version(void *data);
extern kal_uint32 jnw_https_get_not_after(void *data);
extern kal_uint32 jnw_https_get_not_before(void *data);
extern kal_int32 jnw_http_check_response_primitive(kal_uint32 vm_id, 
                                                   kal_uint32 req_id,
                                                   kal_uint32 msg_id);
extern kal_int32 jnw_http_get_rsp_msg_len(kal_uint32 vm_id, 
                                          kal_uint32 req_id,
                                          kal_uint32 msg_id,
                                          kal_uint32 *rsp_len,
                                          kal_uint32 *data_len);
extern kal_int32 jnw_http_get_rsp_msg(kal_uint32 vm_id, 
                                      kal_uint32 req_id,
                                      kal_uint32 msg_id,
                                      kal_uint8 *rsp_hdr,
                                      kal_uint8 *data);
extern kal_int32 jnw_http_get_result(void *data, kal_uint32 msg_id);
extern kal_int32 jnw_http_clear_cache(kal_uint32 vm_id, kal_uint32 req_id, 
                                      kal_uint32 url_length, kal_char *url);
extern kal_int8 jnw_http_auth_res(kal_uint32 vm_id, kal_uint32 req_id, 
                                  kal_uint8* user_name, kal_int32 user_name_len, 
                                  kal_uint8* passwd, kal_int32 passwd_len);
extern int jnw_http_get_root_cert_by_cert_chain (
                    kal_uint8 cert_num ,
                    jnw_http_sec_certificate_struct **cert_chain,
                    jnw_http_sec_certificate_file_struct *root_cert);
extern void jnw_http_initialize(kal_uint32 vm_id);
extern void jnw_http_finalize(kal_uint32 vm_id);
extern kal_int8 jnw_http_clear_pending_request(kal_uint32 vm_id, kal_uint32 req_id);
extern kal_int8 jnw_http_set_non_auto_redirect(kal_uint32 vm_id, kal_bool enable);
extern kal_bool jnw_http_is_url_valid(kal_uint8 *url);


/*************************Socket**********************************/
extern void jnw_network_initialize(void);
extern void jnw_network_finalize(void);
extern void socketDeactive(kal_int32 vm_id);
extern kal_int32 j2me_deactivate_socket(kal_int32 vm_id);

/* callback register/deregister functions */
extern void jnw_register_callback(jnw_soc_asyn_ind_enum type, java_async_callback_fn callback_ptr);
extern void jnw_deregister_callback(jnw_soc_asyn_ind_enum type);

extern char *jnw_socket_getlocaladdress_string(void);
extern int jnw_socket_getport(int handle, int local);
extern char *jnw_socket_getipnumber(int handle, int local);
extern int jnw_socket_setsockopt(int handle, int flag, int optval, int *exception);
extern int jnw_socket_getsockopt(int handle, int flag, int *optval, int *exception);
extern int jnw_get_errno(void);
extern int jnw_serversocket_close(int vm_id, int handle);
extern int jnw_socket_close(int vm_id, int handle);
extern int jnw_serversocket_accept(int handle);
extern int jnw_serversocket_open(int vm_id, int port, int *fd, int *exception);
extern void jnw_socket_shutdown(int handle, int how);
extern int jnw_socket_send(int handle, char *p, int len);
extern int jnw_socket_available(int handle);
extern int jnw_socket_recv(int handle, char *p, int len);
extern int jnw_socket_open(int vm_id, char *name, int port, int *exception, int *fd, int *dns_idx);
extern int jnw_socket_getipnumber_byname(int vm_id, char *host, int *dns_idx);
extern char *jnw_getlocaladdress_string(int fd);

extern int _jnw_socket_connect(int *handle, int *exception);
extern int _jnw_socket_gethost(int *dns_idx);

/*************************SSL/TLS**********************************/
extern void jnw_tls_register_callback(void (*callback_ptr)(kal_int32, kal_int32));
extern void jnw_tls_deregister_callback(void);
extern kal_int32 _jnw_tls_tryget_secure_conn(kal_int32 handle);
extern kal_int32 jnw_tls_open(
                       kal_int32 vm_id, kal_int32 handle, kal_uint8 *host, 
                       kal_int32 port, kal_bool chk_srv_cert,
                       kal_bool chk_client_cert, kal_uint8 auth_mode_num,
                       kal_uint8 *auth_modes, kal_uint32 identity_id);
extern kal_int32 jnw_tls_close(kal_int32 handle);
extern kal_int32 jnw_tls_read(kal_int32 handle, kal_uint8 *p, kal_int32 len);
extern kal_int32 jnw_tls_write(kal_int32 handle, kal_uint8 *p, kal_int32 len);
extern kal_int32 jnw_tls_get_alert_ind_info_by_id(kal_int8 sock_id, kal_uint8 *alert_level, 
                                                  kal_uint8 *alert_desc);
extern kal_int32 jnw_tls_get_notify_info_by_id(kal_int8 sock_id, kal_uint8 *event, kal_bool *result);
extern kal_int32 jnw_tls_get_client_auth_ind_info_by_id(kal_int8 sock_id, kal_bool *result, 
									   	 kal_uint8 auth_mode_num, kal_uint8 *auth_modes, 
									   	 kal_uint32 *identity_id);
extern kal_int32 jnw_tls_get_invalid_cert_ind_info_by_id(kal_int8 sock_id, 
								 		          kal_bool *result, kal_uint8 *action);
extern kal_int32 jnw_tls_get_security_info(kal_int32 handle, kal_uint32 *version, kal_uint32 *ciphersuites);
extern kal_int32 jnw_tls_get_server_certificate_len(kal_int32 handle, kal_int32 *issuer_len, 
                                                    kal_int32 *serial_len, 
                                                    kal_int32 *subject_len);
extern kal_int32 jnw_tls_get_server_certificate(kal_int32 handle, kal_uint8 *issuer_string, kal_uint32 issuer_len, 
                                         kal_uint8 *serial_num_string, kal_uint32 serial_len, 
                                         kal_uint8 *subject_string, kal_uint32 subject_len,
                                         kal_uint32 *sig_alg_name, kal_uint32 *version, 
                                         kal_uint32 *not_before, kal_uint32 *not_after);

extern int jnw_datagram_close(int vm_id, int fd);
extern int jnw_datagram_recv(int vm_id, int fd, int *ipnumber, int *port, char *buffer, int length);
extern void _jnw_datagram_set_nonblocking(int fd);
extern int jnw_datagram_gethost_byaddress(int vm_id, int ipn, char *host, int len, int *dns_idx);
extern int _jnw_datagram_gethost_byaddress(int dns_idx);
extern int jnw_datagram_get_packetsize(int fd);
extern int jnw_datagram_open(int vm_id, int port, int *exception);
extern void jnw_http_register_callback(kal_int32 vm_id, void (*callback_ptr) (void *, kal_int32, void *, kal_int32, kal_int32, kal_int32));
extern void jnw_http_deregister_callback(kal_int32 vm_id);
/*************************************************************************
* SSL stream
*************************************************************************/
#ifdef __J2ME_STREAM_SUPPORT__

/* Maximum stream number in JAL layer */
/* However, WPS may support fewer stream number! */
#define J2ME_STREAM_MAX_NUMBER  10

/* refer to size of wps_create_stream_connection_req_struct.domain */
#define J2ME_STREAM_MAX_DOMAIN_LENGTH (255)

typedef struct
{
    kal_uint8 result;
    kal_uint8 channel_id;
} jnw_stream_result_struct;

typedef struct
{
    kal_uint8 result;
    kal_uint8 channel_id;
    kal_uint8 seq_num;
} jnw_stream_send_result_struct;

typedef struct
{
    kal_uint8 result;
    kal_uint8 channel_id;
    kal_uint8 seq_num;
    kal_bool more;
    kal_uint32 read_data_length;    
} jnw_stream_read_result_struct;

typedef enum
{
    JNW_STREAM_OK, /* Should wait for response */
    JNW_STREAM_INVALID_PARAMETER,
    JNW_STREAM_CLOSED_STREAM,
    JNW_STREAM_NO_RESOURCE, 
    
    JNW_STREAM_END    
} jnw_stream_result_enum;

    
extern int jnw_stream_open_stream_req
        		(kal_bool use_java_setting, /* KAL_TRUE means use Java network setting; KAL_FALSE means use WAP profile setting */
        		 kal_uint8 conn_type, /* Currently, only WPS_CONN_TYPE_TLS is supported */
        		 kal_uint8 addr[4], /* destination IP */
        	   	 kal_uint16 port, /* destination port number */
        	   	 kal_uint16 domain_length, /* maximum length is 255 */
        	     kal_uint8* domain	/* caller should free this buffer. maximum length is 255 */     
        		);

extern void jnw_stream_open_stream_get_result
        		(jnw_stream_result_struct* result /* caller provides the structure and the value would be filled in this structure. */	 	
        		);  								/* Channel ID for this stream can be gotten in this API. */	 	

extern int jnw_stream_close_stream_req(kal_uint8 channel_id);

extern void jnw_stream_close_stream_get_result
        		(jnw_stream_result_struct* result 
        		);  								

extern int jnw_stream_send_data_req
        		(kal_uint8 channel_id, /* channel ID of this stream */
        	   	 kal_uint8 seq_num, /* sequence number. would be loopback in send response */
        	   	 kal_uint32 length, /* Length of data. maximum length is 2000 */
        	     kal_uint8* data /* caller should free this buffer. maximum length is 2000 */
        		);

extern void jnw_stream_send_data_get_result
        		(jnw_stream_send_result_struct* result 
        		);

extern int jnw_stream_read_data_req
        		(kal_uint8 channel_id, /* channel ID of this stream */
        	   	 kal_uint8 seq_num, /* sequence number. would be loopback in read response */
        	   	 kal_uint32 read_length /* maximum length is 2000 */
        		);

extern void jnw_stream_read_data_get_result
        		(jnw_stream_read_result_struct* result,
        		 kal_uint8* data /* caller should prepare this buffer and the read data would be filled in it. */
        		 				  /* size of this buffer should be read_length in jnw_stream_read_data_req() */
        		);

extern int jnw_stream_check_response_primitive(void); /* return received pritimive. -1 means NO response is received.*/

extern void jnw_stream_finalize(void);
#endif /*__J2ME_STREAM_SUPPORT__*/
#endif /* _JNW_INTERFACE_H */ 

