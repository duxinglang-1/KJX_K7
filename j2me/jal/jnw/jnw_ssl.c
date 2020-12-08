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
 *   jnw_ssl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   SSL connection machine dependent API
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
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include files
*************************************************************************/

#if !defined(__MTK_TARGET__)
/* mdi_datatype.h include MMIDataType.h which conflict with soc_api.h  */
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 


#include "jal.h"
#include "jam_internal.h"
#include "jnw_internal.h"
#include "jnw_interface.h"
#include "jvm_adaptor.h"

#include "app2soc_struct.h"
#include "soc_api.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "task_main_func.h"
#include "app_ltlcom.h"
#include <stdlib.h>
#include <string.h>

/* Network */
#include "soc_api.h"
#include "soc2tcpip_struct.h"

#ifdef __SSL_SUPPORT__

#include "tls_const.h"
#include "tls2app_struct.h"
#include "tls_api.h"
#include "cbm_api.h"
#include "abm_api.h"

/* PKI */
#include "app_datetime.h"
#include "certman_api.h"
#include "pki_api.h"
#include "jsec_interface.h"
#include "jvm_resource_manager.h"

#define JNW_TLS_INVALID_CTX -1

/* Global variable */
j2me_tls_notify_ind_struct jnw_tls_notify_ind[J2ME_MAX_SOC_NUM];
j2me_tls_alert_ind_struct  jnw_tls_alert_ind[J2ME_MAX_SOC_NUM];
j2me_tls_invalid_cert_ind_struct jnw_tls_invalid_cert_ind[J2ME_MAX_SOC_NUM];
j2me_tls_client_auth_ind_struct jnw_tls_client_auth_ind[J2ME_MAX_SOC_NUM];
kal_int8 jnw_tls_ctxt[J2ME_MAX_SOC_NUM];
/* external variables */
extern kal_mutexid g_jam_async_ssl_mutex;

/* internal function declaration */
static void jnw_tls_notify_ind_hdlr(app_tls_notify_ind_struct *tls_notify_ind);
static void jnw_tls_alert_ind_hdlr(app_tls_alert_ind_struct *tls_alert_ind);
static void jnw_tls_invalid_cert_ind_hdlr(app_tls_invalid_cert_ind_struct *tls_invalid_cert_ind);
static void jnw_tls_client_auth_ind_hdlr(app_tls_client_auth_ind_struct *tls_client_auth_ind);
static kal_int32 readAsyncEvent(kal_int32 handle);

/* callback function */
static void (*jnw_tls_message_call_back) (int , int);

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_notify_ind_hdlr
 * DESCRIPTION
 *  Process the incoming TLS notification indication
 * PARAMETERS
 *  tls_notify_ind     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_tls_notify_ind_hdlr(app_tls_notify_ind_struct *tls_notify_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JNW_TLS_NOTIFY_IND_HDLR, tls_notify_ind->sock_id,
              tls_notify_ind->event, tls_notify_ind->result, tls_notify_ind->error);
    
    jnw_tls_notify_ind[tls_notify_ind->sock_id].event =  tls_notify_ind->event;
    jnw_tls_notify_ind[tls_notify_ind->sock_id].result = tls_notify_ind->result;   
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_tls_alert_ind_hdlr
 * DESCRIPTION
 *  Process the incoming TLS alert indication
 * PARAMETERS
 *  tls_alert_ind     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_tls_alert_ind_hdlr(app_tls_alert_ind_struct *tls_alert_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JNW_TLS_ALERT_IND_HDLR, tls_alert_ind->sock_id,
              tls_alert_ind->alert_desc, tls_alert_ind->alert_level);

    /* update the tls alert info */
    jnw_tls_alert_ind[tls_alert_ind->sock_id].alert_desc = tls_alert_ind->alert_desc;
    jnw_tls_alert_ind[tls_alert_ind->sock_id].alert_level = tls_alert_ind->alert_level;
    jnw_tls_alert_ind[tls_alert_ind->sock_id].cause = tls_alert_ind->cause;
    jnw_tls_alert_ind[tls_alert_ind->sock_id].error = tls_alert_ind->error;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_tls_invalid_cert_ind_hdlr
 * DESCRIPTION
 *  Process the incoming invlid certificate indicaiton (server authentication failed)
 * PARAMETERS
 *  ilm_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_tls_invalid_cert_ind_hdlr(app_tls_invalid_cert_ind_struct *tls_invalid_cert_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JNW_TLS_INVALID_CERT_HDLR, tls_invalid_cert_ind->sock_id,
              tls_invalid_cert_ind->result, tls_invalid_cert_ind->action);
    
    jnw_tls_invalid_cert_ind[tls_invalid_cert_ind->sock_id].is_recvd = KAL_TRUE;
    jnw_tls_invalid_cert_ind[tls_invalid_cert_ind->sock_id].result = tls_invalid_cert_ind->result;
    jnw_tls_invalid_cert_ind[tls_invalid_cert_ind->sock_id].action = tls_invalid_cert_ind->action;

    return;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_client_auth_ind_hdlr
 * DESCRIPTION
 *  Process the incoming client authentication request indication
 * PARAMETERS
 *  ilm_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_tls_client_auth_ind_hdlr(app_tls_client_auth_ind_struct *tls_client_auth_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JNW_TLS_INVALID_CERT_HDLR, tls_client_auth_ind->sock_id,
              tls_client_auth_ind->result);
    
    jnw_tls_client_auth_ind[tls_client_auth_ind->sock_id].is_recvd = KAL_TRUE;
    jnw_tls_client_auth_ind[tls_client_auth_ind->sock_id].result = tls_client_auth_ind->result;
    jnw_tls_client_auth_ind[tls_client_auth_ind->sock_id].auth_mode_num = 
        tls_client_auth_ind->auth_mode_num;
    jnw_tls_client_auth_ind[tls_client_auth_ind->sock_id].identity_id =
        tls_client_auth_ind->identity_id;
    for (i = 0; i < J2ME_TLS_MAX_CLIENT_AUTH; i++)
    {
        jnw_tls_client_auth_ind[tls_client_auth_ind->sock_id].auth_modes[i] = 
            (kal_uint8)tls_client_auth_ind->auth_modes[i];
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_tls_initialize
 * DESCRIPTION
 *  initialize the tls table
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_tls_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize the TLS callback function */
    jnw_tls_message_call_back = NULL;

    kal_mem_set(jnw_tls_notify_ind, 0, sizeof(jnw_tls_notify_ind));
    kal_mem_set(jnw_tls_alert_ind, 0, sizeof(jnw_tls_alert_ind));
    kal_mem_set(jnw_tls_invalid_cert_ind, 0, sizeof(jnw_tls_invalid_cert_ind));
    kal_mem_set(jnw_tls_client_auth_ind, 0, sizeof(jnw_tls_client_auth_ind));
    for( idx = 0; idx <sizeof(jnw_tls_ctxt);idx++)
    {
        jnw_tls_ctxt[idx] = JNW_TLS_INVALID_CTX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  process_tls_async_ind
 * DESCRIPTION
 *  Called by main while message loop of JDaemon to process incoming message from TLS
 * PARAMETERS
 *  ilm_ptr     [IN]    received indication 
 * RETURNS
 *  void
 *****************************************************************************/
void process_tls_async_ind(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 msg_id = 0;
    kal_int8 sock_id = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_ssl_mutex);

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_APP_TLS_NOTIFY_IND:
            JNW_ASSERT_DBG(ilm_ptr->local_para_ptr != NULL); 
            jnw_tls_notify_ind_hdlr((app_tls_notify_ind_struct*)ilm_ptr->local_para_ptr);
            sock_id = ((app_tls_notify_ind_struct*)ilm_ptr->local_para_ptr)->sock_id;
            msg_id = MSG_TLS_NOTIFY_IND;
            break;
            
        case MSG_ID_APP_TLS_ALERT_IND:
            JNW_ASSERT_DBG(ilm_ptr->local_para_ptr != NULL);
            jnw_tls_alert_ind_hdlr((app_tls_alert_ind_struct*)ilm_ptr->local_para_ptr);
            sock_id = ((app_tls_alert_ind_struct*)ilm_ptr->local_para_ptr)->sock_id;
            msg_id = MSG_TLS_ALERT_IND;
            break;
            
        case MSG_ID_APP_TLS_INVALID_CERT_IND:
            JNW_ASSERT_DBG(ilm_ptr->local_para_ptr != NULL);
            jnw_tls_invalid_cert_ind_hdlr((app_tls_invalid_cert_ind_struct*)ilm_ptr->local_para_ptr);
            sock_id = ((app_tls_invalid_cert_ind_struct*)ilm_ptr->local_para_ptr)->sock_id;
            msg_id = MSG_TLS_INVALID_CERT_IND;
            break;

        case MSG_ID_APP_TLS_CLIENT_AUTH_IND:
            JNW_ASSERT_DBG(ilm_ptr->local_para_ptr != NULL);
            jnw_tls_client_auth_ind_hdlr((app_tls_client_auth_ind_struct*)ilm_ptr->local_para_ptr);
            sock_id = ((app_tls_client_auth_ind_struct*)ilm_ptr->local_para_ptr)->sock_id;
            msg_id = MSG_TLS_CLIENT_AUTH_IND;
            break;
            
        default:
            break;
    }

    kal_give_mutex(g_jam_async_ssl_mutex);

    if (sock_id != -1)
    {
        /* call the application's callback to tell its result */
        if (jnw_tls_message_call_back)
        {
            jnw_tls_message_call_back((int)msg_id, (int)sock_id);
        }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  readAsyncEvent
 * DESCRIPTION
 *  J2ME polling set event (internal used API)
 * PARAMETERS
 *  handle      [IN]    socket id   
 * RETURNS
 *  jnw_tls_error_enum
 *****************************************************************************/
static kal_int32 readAsyncEvent(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = JNW_TLS_NOT_DONE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_async_ssl_mutex);

    if (jnw_tls_alert_ind[handle].alert_level == TLS_ALERT_LV_FATAL ||
        jnw_tls_alert_ind[handle].alert_level == TLS_ALERT_LV_WARNING
        )
    {
        /* we receive the fatal alert or close notify from the peer side.
               * Thus, we need to close the tls connection.
               */
        if (jnw_tls_alert_ind[handle].alert_level == TLS_ALERT_LV_FATAL)
        {
            result = JNW_TLS_FATAL_ERROR;
        }
        else
        {
            /* if the warning is others beside close_notify, we ignore it*/
            if (jnw_tls_alert_ind[handle].alert_desc == TLS_ALERT_CLOSE_NOTIFY)
            {
                result = JNW_TLS_CLOSE_NOTIFY;
            }
        }
        memset(&jnw_tls_alert_ind[handle], 0, sizeof(j2me_tls_alert_ind_struct));
    }
    else if (jnw_tls_notify_ind[handle].event != 0)
    {
        if (jnw_tls_notify_ind[handle].event == TLS_HANDSHAKE_READY)
        {
            if (jnw_tls_notify_ind[handle].result == KAL_TRUE)
            {
            result = JNW_TLS_NEED_HANDSHAKE;
        }
            else
            {
                result = JNW_TLS_FATAL_ERROR;
            }
        }
        if (jnw_tls_notify_ind[handle].event == TLS_HANDSHAKE_DONE)
        {
            if (jnw_tls_notify_ind[handle].result == KAL_TRUE)
            {
                result = JNW_TLS_OK;
            }
            else
            {
                result = JNW_TLS_FATAL_ERROR;
            }
        }
        if (jnw_tls_notify_ind[handle].event == TLS_READ ||
            jnw_tls_notify_ind[handle].event == TLS_WRITE)
        {
            result = JNW_TLS_OK;
        }
        if (jnw_tls_notify_ind[handle].event == TLS_CLOSE)
        {
            result = JNW_TLS_CLOSE_NOTIFY;
        }
        memset(&jnw_tls_notify_ind[handle], 0, sizeof(j2me_tls_notify_ind_struct));
    }
    else if (jnw_tls_invalid_cert_ind[handle].is_recvd)
    {
        if (jnw_tls_invalid_cert_ind[handle].result == KAL_TRUE &&
            (jnw_tls_invalid_cert_ind[handle].action == TLS_USER_ACCEPT_ONCE ||
             jnw_tls_invalid_cert_ind[handle].action == TLS_USER_ACCEPT_FOREVER))
        {
            /* we need to do handshake again with disabled cert authentication */
            result = JNW_TLS_NEED_REHANDSHAKE;
        }
        else
        {
            result = JNW_TLS_BAD_CERTIFICATE;
        }
        
        memset(&jnw_tls_invalid_cert_ind[handle], 0, sizeof(j2me_tls_invalid_cert_ind_struct));
    }
    else if(jnw_tls_client_auth_ind[handle].is_recvd)
    {
        if (jnw_tls_client_auth_ind[handle].result)
        {
            result = JNW_TLS_NEED_CLIENT_AUTH;
        }
        else
        {
            result = JNW_TLS_BAD_CLIENT_AUTH;
            memset(&jnw_tls_client_auth_ind[handle], 0, sizeof(j2me_tls_client_auth_ind_struct));
        } 
    }
    
    kal_give_mutex(g_jam_async_ssl_mutex);
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_tls_register_callback
 * DESCRIPTION
 * register the callback function for TLS response. 
 * The first parameter of the call back function
 * is the message id, such as MSG_TLS_NOTIFY_IND(jnw_tls_reply_enum),
 * and the second parameter is socket id.
 * PARAMETERS
 *  callback_ptr [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_tls_register_callback(void (*callback_ptr)(int, int))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jnw_tls_message_call_back = callback_ptr;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_deregister_callback
 * DESCRIPTION
 *  deregister the tls callback
 * PARAMETERS      
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_tls_deregister_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jnw_tls_message_call_back = NULL;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_alert_ind_info_by_id
 * DESCRIPTION
 *    get the content of tls alert notification indication by socket id
 * PARAMETERS        
 *  sock_id                  [IN]  socket id
 *    alert_level            [OUT] alert level (jnw_tls_alert_level_enum)
 *    alert_desc            [OUT] alert description (jnw_tls_alert_desc_enum)
 * RETURNS
 *  IO_ERROR : error occurs
 *  IO_SUCCESS : success
 *****************************************************************************/
kal_int32 jnw_tls_get_alert_ind_info_by_id(kal_int8 sock_id, kal_uint8 *alert_level, 
                                           kal_uint8 *alert_desc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sock_id >= J2ME_MAX_SOC_NUM)
    {
        return IO_ERROR;
    }
    
    if (alert_level)
    {
        *alert_level = jnw_tls_alert_ind[sock_id].alert_level;
    }
    if (alert_desc)
    {
        *alert_desc = jnw_tls_alert_ind[sock_id].alert_desc;
    }
    
    kal_mem_set(&jnw_tls_alert_ind[sock_id], 0, sizeof(j2me_tls_alert_ind_struct));
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_invalid_cert_ind_info_by_id
 * DESCRIPTION
 *    get the content of tls invalid certificate indication by socket id
 * PARAMETERS     
 *  sock_id                 [IN]  socket id
 *    result                [OUT] invalid certificate result
 *    action                [OUT] invalid certificate action (jnw_tls_inval_cert_action)
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_get_invalid_cert_ind_info_by_id(kal_int8 sock_id, 
                                                   kal_bool *result, kal_uint8 *action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sock_id >= J2ME_MAX_SOC_NUM)
    {
        return IO_ERROR;
    }
    
    if (result)
    {
        *result = jnw_tls_invalid_cert_ind[sock_id].result;
    }
    if (action)
    {
        *action = jnw_tls_invalid_cert_ind[sock_id].action;
    }
    
    kal_mem_set(&jnw_tls_invalid_cert_ind[sock_id], 0, sizeof(j2me_tls_invalid_cert_ind_struct));
    return IO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_notify_info_by_id
 * DESCRIPTION
 *    get the content of tls notification indication by socket id
 * PARAMETERS      
 *  sock_id          [IN]  socket id
 *    event            [OUT] tls notification event (jnw_tls_event_enum)
 *    result            [OUT] tls notification result
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_get_notify_info_by_id(kal_int8 sock_id, kal_uint8 *event, kal_bool *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sock_id >= J2ME_MAX_SOC_NUM)
    {
        return IO_ERROR;
    }
    
    if (event)
    {
        *event = (kal_uint8)jnw_tls_notify_ind[sock_id].event;
    }
    if (result)
    {
        *result = jnw_tls_notify_ind[sock_id].result;
    }
    
    kal_mem_set(&jnw_tls_notify_ind[sock_id], 0, sizeof(j2me_tls_notify_ind_struct));
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_client_auth_ind_info_by_id
 * DESCRIPTION
 *    get the content of tls client authentication request indication by socket id
 *  
 * PARAMETERS    
 *  sock_id                  [IN]
 *    result                [OUT]
 *    auth_mod_num        [IN]
 *    auth_mode            [OUT]    jnw_tls_auth_mode_enum
 *    identity_ind        [OUT]
 *
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_get_client_auth_ind_info_by_id(kal_int8 sock_id, kal_bool *result, 
                                       kal_uint8 auth_mode_num, kal_uint8 *auth_modes, 
                                       kal_uint32 *identity_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth_mode_num > J2ME_TLS_MAX_CLIENT_AUTH ||
        sock_id >= J2ME_MAX_SOC_NUM)
    {
        return IO_ERROR;
    }
    
    if (result)
    {
        *result = jnw_tls_client_auth_ind[sock_id].result;
    }
    if (auth_modes)
    {
        memcpy((kal_uint8 *)auth_modes, (kal_uint8 *)jnw_tls_client_auth_ind[sock_id].auth_modes, auth_mode_num);
    }
    if (identity_id)
    {
        *identity_id = jnw_tls_client_auth_ind[sock_id].identity_id;
    }
    
    memset(&jnw_tls_client_auth_ind[sock_id], 0, sizeof(j2me_tls_client_auth_ind_struct));
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  _jnw_tls_tryget_secure_conn
 * DESCRIPTION
 *  check if the secure coonection is created successfully
 * PARAMETERS
 *  handle     [IN]        socket handle
 *  ctx_id     [IN]        context id
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_WOULDBLOCK : not done yet
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 _jnw_tls_tryget_secure_conn(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_int32 ctx_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ((result = readAsyncEvent(handle)) == JNW_TLS_NOT_DONE)
    {
        return IO_WOULDBLOCK;
    }
    else
    {
        /* 1. check to see if we need to do handshake
         * 2. check to see if we need to disable client or 
         *    server authentication and do rehandshake.
         * 3. check to see if we need to close the tls connecton 
         */
        ctx_id = jnw_tls_ctxt[handle];
        if (result == JNW_TLS_NEED_HANDSHAKE)
        {
            /* enable the auto rehandshake */
            if (tls_auto_rehandshake((kal_int8)handle, KAL_TRUE) < 0)
            {
                /* free the tls context */
                tls_delete_conn((kal_int8)handle);
                tls_delete_ctx((kal_uint8)ctx_id);
                jnw_tls_ctxt[handle] = JNW_TLS_INVALID_CTX;
                return IO_ERROR;
            }
            /* Do the TLS handshake */
            result = tls_handshake((kal_int8)handle);
            if (result < 0)
            {
                if (result == TLS_ERR_WOULDBLOCK)
                {
                    return IO_WOULDBLOCK;
                }
                else
                {
                    /* free the tls context */
                    jnw_tls_ctxt[handle] = JNW_TLS_INVALID_CTX;
                    tls_delete_conn((kal_int8)handle);
                    tls_delete_ctx((kal_uint8)ctx_id);
                    return IO_ERROR;
                }
            }

        }
        else if (result == JNW_TLS_NEED_CLIENT_AUTH)
        {
            /* free the tls context */
            tls_delete_conn((kal_int8)handle);
            tls_delete_ctx((kal_uint8)ctx_id);
            jnw_tls_ctxt[handle] = JNW_TLS_INVALID_CTX;
            return IO_CHECK_CLIENT_CERT_AGAIN;
        }
        else if (result == JNW_TLS_CLOSE_NOTIFY ||
                 result == JNW_TLS_FATAL_ERROR ||
                 result == JNW_TLS_NEED_REHANDSHAKE ||
                 result == JNW_TLS_BAD_CERTIFICATE ||
                 result == JNW_TLS_BAD_CLIENT_AUTH)
        {
            /* free the tls context */
            tls_delete_conn((kal_int8)handle);
            tls_delete_ctx((kal_uint8)ctx_id);
            jnw_tls_ctxt[handle] = JNW_TLS_INVALID_CTX;
            if (result == JNW_TLS_NEED_REHANDSHAKE)
            {
                /* need to close the original socket and 
                   create the new connection again with
                   server authentication disalbe */
                return IO_NEED_REHANDSHAKE;
            }
            else if (result == JNW_TLS_BAD_CERTIFICATE ||
                     result == JNW_TLS_BAD_CLIENT_AUTH)
            {
                /* invalid certificate sent from the peer */
                return IO_BAD_CERT;
            }
            else
            {
                return IO_ERROR;
            }
        }
    }
    jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SSL_DEVICE, handle, NULL, NULL, &jnw_tls_close);
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_open
 * DESCRIPTION
 *  open a SSL/TLS stream connection
 * PARAMETERS
 *  handle          [IN]         socket handle
 *  host            [IN]         host name
 *  port            [IN]         port number
 *  ctx_id          [OUT]         context id
 *  chk_srv_cert    [IN]         do server authenticaiton
 *  chk_client_cert [IN]         do client authenticaiton
 *  auth_mode_num   [IN]         client authentication mode number
 *  auth_modes      [IN]         client authentication mode
 *  identity_id     [IN]         client certificate 
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_open(
                       kal_int32 vm_id, kal_int32 handle, kal_uint8 *host, 
                       kal_int32 port,  kal_bool chk_srv_cert,
                       kal_bool chk_client_cert, kal_uint8 auth_mode_num,
                       kal_uint8 *auth_modes, kal_uint32 identity_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 app_id;
    kal_int32 ret;
    kal_uint8 i;
    cbm_app_info_struct app_info;
    sockaddr_struct addr;
    tls_auth_mode_enum client_auth_modes[J2ME_TLS_MAX_CLIENT_AUTH];
    kal_bool is_ipaddr = KAL_FALSE;
    kal_uint8 ctx_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JNW_TLS_OPEN, handle, port, chk_srv_cert, chk_client_cert);
    /* invalid socket id */
    if (!(handle >=0 && handle < J2ME_MAX_SOC_NUM))
    {
        return IO_ERROR;
    }
    
    app_id =  jam_get_app_id(vm_id);
    abm_get_registered_app_name(app_id, &app_info);
    /* create tls global context */
    ret = tls_new_ctx(
                    TLS_ALL_VERSIONS,
                    TLS_CLIENT_SIDE,
                    MOD_JASYN_D,
                    app_info.app_str_id);
    if (ret < 0)
    {
        /* trace and log */
        kal_trace(TRACE_ERROR, JNW_SEC_CREATE_CTX_FAIL, ret);
        return IO_ERROR;
    }
    /* store tls context id */
    ctx_id =(kal_uint8) ret;
    
    if (soc_ip_check((kal_char *)host, addr.addr, &is_ipaddr) == KAL_FALSE)
    {
        /* free the tls context */
        tls_delete_ctx((kal_uint8)ctx_id);
        return IO_ERROR;
    }
    if (!is_ipaddr)
    {
        /* free the tls context */
        tls_delete_ctx((kal_uint8)ctx_id);
        return IO_ERROR;
    }
    
    addr.addr_len = 4;
    addr.port = (unsigned short)port;
    
    /* Create the connection between socket and TLS context */
    ret = tls_new_conn((kal_uint8)ctx_id, (kal_int8)handle, &addr);
    if (ret < 0)
    {
        if (ret == TLS_ERR_WAITING_CERT)
        {
            jnw_tls_ctxt[handle] = ctx_id;
            return IO_WOULDBLOCK;
        }
        else
        {
            /* free the tls context */
            tls_delete_ctx((kal_uint8)ctx_id);
            return IO_ERROR;
        }
    }

    /* disable the server ceritifcate authentication */
    ret = tls_check_invalid_cert((kal_int8)handle, chk_srv_cert);
    if (ret != TLS_ERR_NONE)
    {
        /* free the tls context */
        tls_delete_conn((kal_int8)handle);
        tls_delete_ctx((kal_uint8)ctx_id);
        return IO_ERROR;
    }

    if (chk_client_cert)
    {
        /* client cert authentication has failed and we needs to disable it or 
           set the client's identify to try again */
        if (identity_id != 0)
        {
            if (auth_mode_num > J2ME_TLS_MAX_CLIENT_AUTH)
            {
                /* free the tls context */
                tls_delete_conn((kal_int8)handle);
                tls_delete_ctx((kal_uint8)ctx_id);
                kal_trace(TRACE_ERROR, JNW_TLS_DISABLE_CLIENT_AUTH_FAIL, ret);
                return IO_ERROR;
            }

            for (i = 0; i < auth_mode_num; i++)
            {
                client_auth_modes[i] = (tls_auth_mode_enum)auth_modes[i];
            }
            
            ret = tls_set_client_auth((kal_uint8)ctx_id, 
                (tls_auth_mode_enum *)client_auth_modes, auth_mode_num);
            if (ret < 0)
            {
                /* free the tls context */
                tls_delete_conn((kal_int8)handle);
                tls_delete_ctx((kal_uint8)ctx_id);
                kal_trace(TRACE_ERROR, JNW_TLS_DISABLE_CLIENT_AUTH_FAIL, ret);
                return IO_ERROR;
            }
            ret = tls_set_identity((kal_uint8)ctx_id, identity_id);
        }
        else
        {
            /* disable client authentication if there is no client id */
            ret = tls_set_null_client_auth((kal_int8)handle);
        }
        
        if (ret < 0)
        {
            /* free the tls context */
            tls_delete_conn((kal_int8)handle);
            tls_delete_ctx((kal_uint8)ctx_id);
            kal_trace(TRACE_ERROR, JNW_TLS_DISABLE_CLIENT_AUTH_FAIL, ret);
            return IO_ERROR;
        }
    }

    /* enable the auto rehandshake */
    if (tls_auto_rehandshake((kal_int8)handle, KAL_TRUE) < 0)
    {
        /* free the tls context */
        tls_delete_conn((kal_int8)handle);
        tls_delete_ctx((kal_uint8)ctx_id);
        return IO_ERROR;
    }
    
    /* Do the TLS handshake */
    ret = tls_handshake((kal_int8)handle);
    if (ret < 0)
    {
        if (ret == TLS_ERR_WOULDBLOCK)
        {
            jnw_tls_ctxt[handle] = ctx_id;
            return IO_WOULDBLOCK;
        }
        else
        {
            kal_trace(TRACE_ERROR, JNW_TLS_HANDSHAKE_FAIL);
            /* free the tls context */
            tls_delete_conn((kal_int8)handle);
            tls_delete_ctx((kal_uint8)ctx_id);
            return IO_ERROR;
        }
    }
    jnw_tls_ctxt[handle] = ctx_id;
    jvm_resource_mgr_register(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SSL_DEVICE, handle, NULL, NULL, &jnw_tls_close);
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_close
 * DESCRIPTION
 *  close a TLS stream connection
 * PARAMETERS
 *  handle     [IN]        socket handle id
 *  ctx_id     [IN]        tls stream context id
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_close(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_int8 ctx_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == -1)
    {
        return IO_ERROR;
    } 
    ctx_id = jnw_tls_ctxt[handle];
    kal_trace(TRACE_FUNC, JNW_TLS_CLOSE, handle, ctx_id);   
    if( ctx_id == JNW_TLS_INVALID_CTX)
    {
        return IO_ERROR;
    }

    if ((ret = tls_shutdown((kal_int8)handle)) != TLS_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_SHUTDOWN_FAIL, ret);
    }
    
    if ((ret = tls_delete_conn((kal_int8)handle)) != TLS_ERR_NONE)
    {
        
        kal_trace(TRACE_ERROR, JNW_TLS_DELETE_CONN_FAIL, ret);
    }
    
    if ((ret = tls_delete_ctx((kal_uint8)ctx_id)) != TLS_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_DELETE_CTX_FAIL, ret);
    }
    jvm_resource_mgr_deregister(JVM_RESOURCE_MGR_INVALIDE_VM_ID,JAVA_IO_SSL_DEVICE,handle);

    kal_mem_set(&jnw_tls_notify_ind[handle], 0, sizeof(j2me_tls_notify_ind_struct));
    kal_mem_set(&jnw_tls_alert_ind[handle], 0, sizeof(j2me_tls_alert_ind_struct));
    kal_mem_set(&jnw_tls_invalid_cert_ind[handle], 0, sizeof(j2me_tls_invalid_cert_ind_struct));
    kal_mem_set(&jnw_tls_client_auth_ind[handle], 0, sizeof(j2me_tls_client_auth_ind_struct));
    jnw_tls_ctxt[handle] = JNW_TLS_INVALID_CTX;
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_read
 * DESCRIPTION
 *  Read the data through the secured connection
 * PARAMETERS
 *  handle      [IN]   socket handle     
 *  p           [OUT]  recv buffer
 *  len         [IN]   recv buffer length
 * RETURNS
 *  >0 : received data length
 *  0 : no data is received
 *  IO_WOULDBLOCK : not done yet
 *  IO_INTERRUPTED : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_read(kal_int32 handle, kal_uint8 *p, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 recv_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recv_len = tls_read((kal_int8) handle, (kal_uint8*) p, len);

    kal_trace(TRACE_GROUP_3, JNW_TLS_READ, handle, len, recv_len);

    if (recv_len <= 0)
    {

        if (recv_len == 0 ||
            recv_len == TLS_ERR_WOULDBLOCK ||
            recv_len == TLS_ERR_HANDSHAKING ||
            recv_len == TLS_ERR_REHANDSHAKING ||
            recv_len == TLS_ERR_REHANDSHAKED)
        {
            return IO_WOULDBLOCK;
        }
        else
        {
            return IO_INTERRUPTED;
        }
    }

    return recv_len;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_write
 * DESCRIPTION
 *  Write the data through the secured connection
 * PARAMETERS
 *  handle      [IN]    socket id       
 *  p           [IN]    send data        
 *  len         [IN]    send data length
 * RETURNS
 *  >=0 : written length (0 is impossible in the current design, we will get error)
 *  IO_WOULDBLOCK : not done yet
 *  IO_INTERRUPTED : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_write(kal_int32 handle, kal_uint8 *p, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 write_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    write_len = tls_write((kal_int8) handle, (kal_uint8*) p, len);

    kal_trace(TRACE_GROUP_3, JNW_TLS_WRITE, handle, len, write_len);

    if (write_len < 0)
    {
        if (write_len == TLS_ERR_WOULDBLOCK ||
            write_len == TLS_ERR_REHANDSHAKING ||
            write_len == TLS_ERR_HANDSHAKING)
        {
            return IO_WOULDBLOCK;
        }
        else
        {
            return IO_INTERRUPTED;
        }
    }

    return write_len;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_security_info
 * DESCRIPTION
 *  Get the SSL/TLS security info
 * PARAMETERS
 *  handle             [IN]    socket id
 *  version            [OUT]   SSL/TLS version       
 *  ciphersuites       [OUT]   cipher suites (tls_ciphersuites_enum)
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs
 *****************************************************************************/
kal_int32 jnw_tls_get_security_info(kal_int32 handle, kal_uint32 *version, kal_uint32 *ciphersuites)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    tls_cipher_info_struct cipher_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (version == NULL || ciphersuites ==NULL)
    {
        return IO_ERROR;
    }

    /* get the handshaked protocol version and name */
    ret = tls_get_cipher_info((kal_int8)handle, &cipher_info);
    if (ret != TLS_ERR_NONE)
    {
        return IO_ERROR;
    }
  
    *version = cipher_info.version;
   
    /* get the handshaked ciphersuites */
    ret = tls_get_cipher((kal_int8)handle, (tls_ciphersuites_enum *)ciphersuites);

    kal_trace(TRACE_FUNC, JNW_TLS_GET_SECURITY_INFO, handle, ret);
    if (ret != TLS_ERR_NONE)
    {
        return IO_ERROR;
    }
    
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_server_certificate_len
 * DESCRIPTION
 *  Get the buffer length to store the info of server certificate
 * PARAMETERS
 *  handle             [IN]    socket id        
 *  issuer_len         [OUT]   issuer length        
 *  serial_len         [OUT]   serial number length
 *  subject_len        [OUT]   subject length
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs  
 *****************************************************************************/
kal_int32 jnw_tls_get_server_certificate_len(kal_int32 handle, kal_int32 *issuer_len, 
                                             kal_int32 *serial_len, 
                                             kal_int32 *subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tls_cert_struct cert;
    kal_int32 ret;
    jsec_pki_data_struct jsec_cert;
    jsec_cert_info_struct jsec_cert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (issuer_len == NULL || serial_len == NULL || subject_len == NULL)
    {
        return IO_ERROR;
    }

    /* get the server certificate */
    ret = tls_get_peer_cert((kal_int8) handle, &cert);
    if (ret != TLS_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_GET_PEER_CERT_FAIL, ret);
        return IO_ERROR;
    }
    
    jsec_cert.data = (void *)cert.data;
    jsec_cert.size = (kal_uint32)cert.len;
    memset(&jsec_cert_info, 0, sizeof(jsec_cert_info));

    /* get the certificate info */
    if (jsec_get_cert_info(&jsec_cert, &jsec_cert_info) < 0)
    {
        /* get the certificate info unsuccessfully */
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }

    *issuer_len = 0;
    *issuer_len = (kal_int32)jsec_get_cert_name_len(jsec_cert_info.issuer);
    if (*issuer_len <= 0)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_ISSUER_NAME_FAIL, *issuer_len);
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }

    *subject_len = 0;
    *subject_len = (kal_int32)jsec_get_cert_name_len(jsec_cert_info.subject);
    if (*subject_len <= 0)
    {
        kal_trace(TRACE_ERROR, JNW_SEC_GET_ISSUER_NAME_FAIL, *subject_len);
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }
    
    *serial_len = (kal_int32)jsec_cert_info.serial_num_len;
    jsec_free_cert_info(&jsec_cert_info);
    return IO_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_tls_get_server_certificate
 * DESCRIPTION
 *  Get the server certificate
 * PARAMETERS
 *  handle               [IN]        
 *  issuer_string        [OUT]        
 *  issuer_len           [OUT]        
 *  serial_num_string    [OUT]
 *  serial_len           [OUT]
 *  subject_string       [OUT]
 *  subject_len          [OUT]
 *  sig_alg_name         [OUT]
 *  version              [OUT]
 *  not_before           [OUT]
 *  not_after            [OUT]
 * RETURNS
 *  IO_SUCCESS : success
 *  IO_ERROR : error occurs 
 *****************************************************************************/
kal_int32 jnw_tls_get_server_certificate(kal_int32 handle, kal_uint8 *issuer_string, 
                                         kal_uint32 issuer_len, kal_uint8 *serial_num_string, 
                                         kal_uint32 serial_len, kal_uint8 *subject_string, 
                                         kal_uint32 subject_len, kal_uint32 *sig_alg_name, 
                                         kal_uint32 *version, kal_uint32 *not_before, kal_uint32 *not_after)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tls_cert_struct cert;
    kal_int32 ret;
    jsec_pki_data_struct jsec_cert;
    jsec_cert_info_struct jsec_cert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check parameters */
    if (issuer_string == NULL || serial_num_string == NULL || subject_string == NULL ||
        sig_alg_name == NULL || version == NULL || not_before == NULL || not_after == NULL)
    {
        return IO_ERROR;
    }

    /* get the server certificate */
    ret = tls_get_peer_cert((kal_int8) handle, &cert);
    if (ret != TLS_ERR_NONE)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_GET_PEER_CERT_FAIL, ret);
        return IO_ERROR;
    }
    
    jsec_cert.data = (void *)cert.data;
    jsec_cert.size = (kal_uint32)cert.len;
    memset(&jsec_cert_info, 0, sizeof(jsec_cert_info));
    
    /* get the certificate info */
    if (jsec_get_cert_info(&jsec_cert, &jsec_cert_info) < 0)
    {
        /* get the certificate info unsuccessfully */
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }
    
    /* copy issuer name */
    memset(issuer_string, 0, issuer_len);
    jsec_get_cert_name(jsec_cert_info.issuer, (kal_uint8 *)issuer_string, issuer_len);
    
    /* copy serial number */
    memcpy((kal_uint8 *)serial_num_string, (kal_uint8 *)jsec_cert_info.serial_num, 
           jsec_cert_info.serial_num_len);

    /* copy subject name */
    memset(subject_string, 0, subject_len);
    jsec_get_cert_name(jsec_cert_info.subject, (kal_uint8 *)subject_string, subject_len);

    /* get the signature algorithm */
    *sig_alg_name = (kal_uint32)jsec_cert_info.sig_alg;

    /* get the certificate version */
    *version = (kal_uint32)jsec_cert_info.version;

    /* get the valid date */
    /* compute the date in seconds and convert it to the UTC time*/
    ret = applib_dt_mytime_2_utc_sec(&jsec_cert_info.not_before, KAL_FALSE);
    if (ret == 0)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_CONVERT_DATE_FAIL, ret);
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }
    *not_before = (kal_uint32)ret;
    ret = applib_dt_mytime_2_utc_sec(&jsec_cert_info.not_after, KAL_FALSE);
    if (ret == 0)
    {
        kal_trace(TRACE_ERROR, JNW_TLS_CONVERT_DATE_FAIL, ret);
        jsec_free_cert_info(&jsec_cert_info);
        return IO_ERROR;
    }
    *not_after = (kal_uint32)ret;
    
    jsec_free_cert_info(&jsec_cert_info);
    
    return IO_SUCCESS;
}

#endif
