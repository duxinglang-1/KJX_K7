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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   wps_if.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares WPS module interface function prototype
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* Signals sent to the WPS */
#define WPS_SIG_CONFIGURE_CHANNEL                 ((MSF_MODID_WPS << 8) + 0x01)
#define WPS_SIG_CONFIGURE_PROXY_CHANNEL           ((MSF_MODID_WPS << 8) + 0x02)
#define WPS_SIG_REMOVE_CHANNEL                    ((MSF_MODID_WPS << 8) + 0x03)
#define WPS_SIG_HTTP_REQUEST                      ((MSF_MODID_WPS << 8) + 0x04)
#define WPS_SIG_CANCEL_REQUEST                    ((MSF_MODID_WPS << 8) + 0x05)
#define WPS_SIG_CLEAR                             ((MSF_MODID_WPS << 8) + 0x06)
#define WPS_SIG_HTTP_AUTH_INDICATION              ((MSF_MODID_WPS << 8) + 0x07)
#define WPS_SIG_SHOW_SEC_CONFIRM_DIALOG             ((MSF_MODID_WPS << 8) + 0x08)
#define WPS_SIG_SHOW_SEC_CONFIRM_DIALOG_RESPONSE    ((MSF_MODID_WPS << 8) + 0x09)


/* For the signal WPS_SIG_SHOW_CONFIRM_DIALOG */
typedef struct
{
    MSF_UINT32 title_id;
    MSF_UINT32 text_id;
    MSF_UINT32 callback;
    MSF_UINT8 type;
    MSF_UINT8 confirm;
} wps_show_sec_confirm_dialog_struct;

typedef struct
{
    MSF_UINT8 request_id;
    MSF_UINT8 result;
} wps_show_sec_confirm_dialog_response_struct;




extern void *wps_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

extern void wps_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p);

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
#endif

/*
 * Notify HTTP authentication reqest
 */

typedef struct
{
    MSF_INT32 requestId;
    MSF_INT32 authType;
    char *realm;
    char *username;
    MSF_INT32 warnings;
} wps_http_auth_ind_t;

extern void
WPSif_httpAuthIndication(
    MSF_UINT8 src,
    int requestId,
    int authType,
    const char *realm,
    const char *username,
    int warnings);

#ifdef WAP_SEC_SUPPORT
extern void WPSif_showSecConfirmDialog( MSF_UINT8 modId,
                                 int type,
                                 int confirm,
                                 int title_id,
                                 int text_id,
                                 void *callback);

#endif

extern kal_int32 WPSif_tls_new_ctx(MSF_INT32 tls_version_enum, MSF_INT32 tls_side_enum,
	                                            module_type mod_id, kal_uint16 app_str_id);
	                                            
extern kal_int32 WPSif_tls_delete_conn(kal_int8 sock_id);
extern kal_int32 WPSif_tls_delete_ctx(kal_uint8 ctx_id);
extern kal_int32 WPSif_tls_read(kal_int8 sock_id, void* buf, kal_int32 len);
extern kal_int32 WPSif_tls_write(kal_int8 sock_id, const void* buf, kal_int32 len);
extern kal_int32 WPSif_tls_handshake(kal_int8 sock_id);
extern kal_int32 WPSif_tls_rehandshake(kal_int8 sock_id);
extern kal_int32 WPSif_tls_new_conn(kal_uint8 ctx_id, kal_int8 sock_id, msf_sockaddr_t *addr);
extern kal_int32 WPSif_tls_check_invalid_cert(kal_int8 sock_id, kal_bool onoff);
extern kal_int32 WPSif_tls_get_prot_version(const kal_int8 socket);	                                            
extern char* WPSif_getUAprofString(void);
extern int WPSif_get_max_connections(void);



typedef enum {
    WPS_TLS_ERR_NONE                  = 0,   /* No error. */
    WPS_TLS_ERR_WOULDBLOCK            = -1,  /* Operation cannot complete now. */
    WPS_TLS_ERR_NO_FREE_CTX           = -2,  /* No free global context slots. */
    WPS_TLS_ERR_NO_MEMORY             = -3,  /* Allocate memory failed. */
    WPS_TLS_ERR_INVALID_CONTEXT       = -4,  /* Invalid global context id. */
    WPS_TLS_ERR_INVALID_CIPHER        = -5,  /* Invalid cipher enum value. */
    WPS_TLS_ERR_EXCESS_MAX_CIPHERS    = -6,  /* Too many ciphers. */
    WPS_TLS_ERR_INVALID_PARAMS        = -7,  /* Invalid parameter. */
    WPS_TLS_ERR_INVALID_ROOT_CERT     = -8,  /* Invalid root certificate id. */
    WPS_TLS_ERR_INVALID_PRIV_KEY      = -9,  /* Invalid private key id. */
    WPS_TLS_ERR_INVALID_PERSONAL_CERT = -10, /* Invalid personal certificate id. */
    WPS_TLS_ERR_INVALID_FILE_TYPE     = -11, /* Invalid file encoding type. */
    WPS_TLS_ERR_INVALID_AUTH_MODE     = -12, /* Invalid client auth mode. */
    WPS_TLS_ERR_EXCESS_MAX_AUTH_MODES = -13, /* Too many client auth modes. */
    WPS_TLS_ERR_ALREADY               = -14, /* The operation is progressing. */
    WPS_TLS_ERR_HANDSHAKED            = -15, /* Handshaked completed. */
    WPS_TLS_ERR_INVALID_SOCK_ID       = -16, /* Invalid socket id. */
    WPS_TLS_ERR_NO_CONN_CTX           = -17, /* No associated connection context. */
    WPS_TLS_ERR_HANDSHAKING           = -18, /* Opreation denied when connection is handshaking. */
    WPS_TLS_ERR_REHANDSHAKING         = -19, /* Connection is rehandshaking. */
    WPS_TLS_ERR_REHANDSHAKED          = -20, /* TLS auto re-handshaked completed. */
    WPS_TLS_ERR_SHUTDOWNED            = -21, /* Opreation denied when connection is shutdowned. */
    WPS_TLS_ERR_REQ_HANDSHAKE         = -22, /* TLS peer requested handshake. */
    WPS_TLS_ERR_NEED_HANDSHAKE        = -23, /* Need handshake first. */
    WPS_TLS_ERR_REHANDSHAKE_REJ       = -24, /* Peer rejects our renegotiation, connection still valid. */
    WPS_TLS_ERR_CONN_CLOSED           = -25, /* Connection closed by peer. */
    WPS_TLS_ERR_IO_ERROR              = -26, /* Lower-layer IO error. */
    WPS_TLS_ERR_OP_DENIED             = -27, /* Operation denied due to incorrect state. */
    WPS_TLS_ERR_READ_REQUIRED         = -28, /* Application data need to be read before processing rehandshake. */
    WPS_TLS_ERR_CERT_VALIDATE         = -29, /* Certificate validation failed. */
    WPS_TLS_ERR_PRNG_FAIL             = -30, /* Set PRNG failed. */
    WPS_TLS_ERR_WAITING_CERT          = -32, /* Waiting certificate confirm from CERTMAN. */
    WPS_TLS_ERR_FILESYS               = -33, /* File system operation failed. */
    WPS_TLS_ERR_TASK_NOT_READY        = -34, /* TLS task not ready, waiting for CERTMAN confirm message. */
    WPS_TLS_ERR_SSL_INTERNAL          = -100,/* SSL layer internal error. */
    WPS_TLS_ERR_SOC_INTERNAL          = -101,/* Socket layer internal error. */
    WPS_TLS_ERR_CERTMAN_INTERNAL       = -102 /* Certman internal error. */
} WPS_tls_error_enum;

typedef enum {
    WPS_TLS_CLIENT_SIDE , /* Client side */
    WPS_TLS_SERVER_SIDE/* Server side */
} WPS_tls_side_enum;

typedef enum {
    WPS_TLS_ALL_VERSIONS = 0, /* ALL supported SSL/TLS versions */
    WPS_SSLv2 = 0x01u << 0,   /* SSLv2 */
    WPS_SSLv3 = 0x01u << 1,   /* SSLv3 */
    WPS_TLSv1 = 0x01u << 2,   /* TLSv1 */
    WPS_TLS_UNKNOWN_VERSION = 0xffu /* Unknown */
} WPS_tls_version_enum;


typedef enum {
    WPS_TLS_ALERT_CLOSE_NOTIFY                = 0,  /* Peer shuts down the connection. */
    WPS_TLS_ALERT_UNEXPECTED_MESSAGE          = 10, /* Received an unexped mesage, always a fatal. */
    WPS_TLS_ALERT_BAD_RECORD_MAC              = 20, /* Bad MAC, always a fatal. */
    WPS_TLS_ALERT_DECRYPTION_FAILED           = 21, /* Decryption failed, always a fatal. */
    WPS_TLS_ALERT_RECORD_OVERFLOW             = 22, /* Record size exceeds the limitation, always a fatal. */
    WPS_TLS_ALERT_DECOMPRESSION_FAILURE       = 30, /* Deccompression failed, always a fatal. */
    WPS_TLS_ALERT_HANDSHAKE_FAILURE           = 40, /* Handshake failed, fatal. */
    WPS_TLS_ALERT_NOCERTIFICATE_RESERVED      = 41, /* Response to a certification request if no appropriate certificate is available, SSLv3 only. */
    WPS_TLS_ALERT_BAD_CERTIFICATE             = 42, /* A certificate was corrupt, signatures that did not verify correctly. */
    WPS_TLS_ALERT_UNSUPPORTED_CERTIFICATE     = 43, /* Unsupported certificate type. */
    WPS_TLS_ALERT_CERTIFICATE_REVOKED         = 44, /* Received a revoked certificate from peer. */
    WPS_TLS_ALERT_CERTIFICATE_EXPIRED         = 45, /* A certificate has expired or not yet valid. */
    WPS_TLS_ALERT_CERTIFICATE_UNKNOWN         = 46, /* Some unspecificate issue in processing the certificate.  */
    WPS_TLS_ALERT_ILLEGAL_PARAMETER           = 47, /* Illegal parameter in the message, always a fatal. */
    WPS_TLS_ALERT_UNKNOWN_CA                  = 48, /* The certificate chain cannot be verified successfully due to untrusted CA, always a fatal. */
    WPS_TLS_ALERT_ACCESS_DENIED               = 49, /* sender decided not to proceed with negotiation when access control was applied, always a fatal. */
    WPS_TLS_ALERT_DECODE_ERROR                = 50, /* The field in a message is incorrect, always a fatal. */
    WPS_TLS_ALERT_DECRYPT_ERROR               = 51, /* a handshake cryptographic operation failed, including verify a signature, decrypt a key exchange, or validate a finished mesasge. */
    WPS_TLS_ALERT_EXPORT_RESTRICTION_RESERVED = 60, /* A negotiation not in compliance with export restrictions was detected. */
    WPS_TLS_ALERT_PROTOCOL_VERSION            = 70, /* The protocol version proposed by client is not supported by server side, always a fatal. */
    WPS_TLS_ALERT_INSUFFICIENT_SECURITY       = 71, /* The server requires cphers more secure than those supported by the client, always a fatal. */
    WPS_TLS_ALERT_INTERNAL_ERROR              = 80, /* An internal error unrelated to the peer, always a fatal. */
    WPS_TLS_ALERT_USER_CANCELLED              = 90, /* The handshake is canceled for some reason unrelated to a protocol failure, generally a warning. */
    WPS_TLS_ALERT_NO_RENEGOTIATION            = 100 /* When peer suggest to renegotiate again but local rejects it, always a warning. */
} WPS_tls_alert_desc_enum;
   
typedef enum {
    WPS_TLS_ALERT_LV_WARNING = 1, /* Warning alert. */
    WPS_TLS_ALERT_LV_FATAL = 2     /* Fatal alert, application MUST terminate the connection immediately. */
} WPS_tls_alert_level_enum;
   
typedef enum {
    WPS_TLS_HANDSHAKE_READY    = 0x01u << 0, /* The connection is ready for performing handshake. */
    WPS_TLS_HANDSHAKE_DONE     = 0x01u << 1, /* Handshake procedure is finished, success or failure. */
    WPS_TLS_READ               = 0x01u << 2, /* There is data for reading. */
    WPS_TLS_WRITE              = 0x01u << 3, /* There is buffer for writing. */
    WPS_TLS_CLOSE              = 0x01u << 4  /* The SSL connection is closed. */
} WPS_tls_event_enum;

typedef enum {
    WPS_TLS_USER_REJECT, /* User rejects the invalid certificate. */
    WPS_TLS_USER_ACCEPT_ONCE, /* User accepts the invalid certificate for this time */
    WPS_TLS_USER_ACCEPT_FOREVER   /* User accepts the invalid cert forever */
} WPS_tls_inval_cert_action;
