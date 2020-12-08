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
 *  jnw_internal.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JNW_INTERNAL_H
#define _JNW_INTERNAL_H

#ifndef _APP2SOC_STRUCT_H
#include "app2soc_struct.h"
#endif
#ifndef _CBM_API_H
#include "cbm_api.h"
#endif /* !_CBM_API_H */

#ifdef __SSL_SUPPORT__
#ifndef _TLS_APP_ENUMS_H_
#include "tls_app_enums.h"
#endif

#ifndef _TLS_CONST_H_
#include "tls_const.h"
#endif
#endif /* __SSL_SUPPORT__ */

#if defined(_MTK_INTERNAL_)
#define JNW_ASSERT_DBG(x)     /* empty */
#else
#define JNW_ASSERT_DBG(exp)   ASSERT(exp)
#endif

#define J2ME_HTTP_NON_AUTO_REDIRECT_OPT  (0x01)  /* no auto redirection */
#define J2ME_MAX_HTTP_REQ_NUM    (10)    /* mac concurrent HTTP request */
#define JAVA_CSD_DISCONNECT_TIME (5 * 60)  /* This is the CSD disconnect time for Java environment */
#define J2ME_MAX_DNS_NAME_LEN   (255)

/*************************************************************************
* HTTP over WSP
*************************************************************************/
typedef enum
{
    JNW_NWK_EVT_OPEN = 0x01,
    JNW_NWK_EVT_CLOSE = 0x02,
    JNW_NWK_EVT_TOTAL
} jnw_nwk_event_enum;

typedef struct
{
    kal_int16 app_id;
    kal_uint32 account_id;
    kal_uint8 wait_event;
} j2me_nwk_event_struct;

typedef struct
{
    kal_uint32 msg_type;
    void *hdr;
    void *data;
    kal_uint16 hdr_len;
    kal_uint16 data_len;
} j2me_http_app_rcv_data_struct;

typedef struct
{
    kal_bool action_ongoing;
    kal_bool  http_is_closing_connection;
    kal_int8  action_id;
    kal_int16 req_id;
    j2me_http_app_rcv_data_struct *data; /* other data */
} j2me_http_app_req_struct;

typedef struct
{
    kal_bool is_channel_reset;
    kal_bool auto_return_for_auth;
    kal_uint8 option;
    kal_uint8 cert_ref_count; /*certificate reference count */
    kal_uint8 session_ref_count; /* session reference count */
    kal_int16 app_id;
    kal_int16 channel_id;
    kal_uint32 timeout_val;
    j2me_http_app_rcv_data_struct *sec_cert; /* certificate data */
    j2me_http_app_rcv_data_struct *sec_session; /* sessiont data */
    j2me_http_app_req_struct app_req[J2ME_MAX_HTTP_REQ_NUM];
} j2me_http_app_data_struct;

typedef void (*http_message_call_back) (void *, int, void *, int, int, int);
typedef struct
{
    kal_int32 app_id;
    http_message_call_back callback;
} jnw_http_callback_struct;

extern kal_int16 jnw_http_get_channel_id(kal_uint32 vm_id);
extern kal_int8 jnw_http_unset_channel(kal_uint32 vm_id);
extern kal_bool jnw_http_active(kal_bool by_vm_id, kal_uint32 vm_id);
extern kal_bool is_socket_activated(void);
extern void jnw_http_verify_cert_chain_hdlr(
                kal_uint8 format, 
                kal_uint32 root_len,
                kal_uint16* root_cert);
extern kal_int32 jnw_http_clear_cache_rsp_hdlr(kal_uint32 req_id, kal_int32 result);
extern kal_int32 jnw_http_unset_channel_rsp_hdlr(kal_uint8 channel_id, kal_uint8 result);
extern int jnw_socket_get_dns_idx(void);
extern void jnw_callback_handler(
                kal_int32 callback_idx,
                kal_int32 req_id,
                kal_int32 msg_id,
                void *rsp_hdr,
                kal_int32 rsp_len,
                void *data,
                kal_int32 len);

#ifdef __J2ME_STREAM_SUPPORT__
extern kal_bool is_stream_activated(void);
/*************************************************************************
* Global Declaration
*************************************************************************/
extern void finalizeStream(void);
#define J2ME_STREAM_INVALID (-1)

typedef struct
{
    kal_int16 id;
} j2me_stream_struct;

#endif

/* SSL internal API for JAM */
#ifdef __SSL_SUPPORT__
extern void process_tls_async_ind(ilm_struct *ilm_ptr);
extern void jnw_tls_initialize(void);
#endif /* __SSL_SUPPORT__ */


extern void _jnw_socket_enter(kal_char * file,kal_uint32 line);
extern void _jnw_socket_leave(kal_char * file,kal_uint32 line);

#define jnw_socket_enter() _jnw_socket_enter(__FILE__, __LINE__)
#define jnw_socket_leave() _jnw_socket_leave(__FILE__, __LINE__)

#define JNW_ENTER()                          \
    do                                  \
    {                                   \
        jnw_socket_enter();    \
    } while (0)
    
#define JNW_LEAVE(return_value)      \
    do                                  \
    {                                   \
        jnw_socket_leave();    \
        return return_value;            \
    } while (0)

typedef struct
{
    kal_int8 socket_id;
    kal_uint8 event_type;
    kal_bool result;

    /* SHK: I add the following attribute to record the error cause for Bearer Fallback requirement. */
    kal_int8    error_cause;
    kal_int32   detail_cause;
} j2me_soc_notify_ind_struct;

typedef struct
{
    kal_bool	result;
    kal_int32   request_id;
    kal_uint8   access_id;
    kal_char    name[J2ME_MAX_DNS_NAME_LEN];    /* null terminated */
} j2me_soc_get_host_by_addr_ind_struct;

typedef struct
{
    kal_bool                    is_waited;
    kal_bool                    is_recvd;
    cbm_bearer_state_enum       state;
    kal_int32                   account_id;
} j2me_soc_open_bearer_struct;


#ifdef __SSL_SUPPORT__
/* tls structure */
typedef struct
{
    tls_event_enum  event;     /* event */
    kal_bool        result;
} j2me_tls_notify_ind_struct;

typedef struct
{
    tls_alert_level_enum  alert_level;     /* alert level */
    tls_alert_desc_enum   alert_desc;      /* alert description */
    kal_int32             error;
    kal_int32             cause;
} j2me_tls_alert_ind_struct;

typedef struct
{
    kal_bool        result;        /* TRUE: user select continue or install */
    kal_bool        is_recvd;      /* TRUE: server invalid certificate is received, FALSE: server invalid certificate is not received */
    tls_inval_cert_action action;
} j2me_tls_invalid_cert_ind_struct;

typedef struct
{
    kal_bool            result;        /* TRUE: user select continue or install */
    kal_bool            is_recvd;      /* TRUE: client auth ind is received, FALSE: client auth ind is not received */
    kal_uint8           auth_mode_num;
    kal_uint8           auth_modes[TLS_MAX_CLIENT_AUTH];
    kal_uint32          identity_id;
} j2me_tls_client_auth_ind_struct;

typedef enum {
    JNW_TLS_OK                = 0,
    JNW_TLS_NOT_DONE          = -2,
    JNW_TLS_FATAL_ERROR       = -5,
    JNW_TLS_CLOSE_NOTIFY      = -6,
    JNW_TLS_NEED_REHANDSHAKE  = -7,
    JNW_TLS_NEED_HANDSHAKE    = -8,
    JNW_TLS_BAD_CERTIFICATE   = -9,
    JNW_TLS_NEED_CLIENT_AUTH  = -10,
    JNW_TLS_BAD_CLIENT_AUTH = -11
} jnw_tls_error_enum;

#endif /* __SSL_SUPPORT__ */

#endif /* _JNW_INTERNAL_H */ 

