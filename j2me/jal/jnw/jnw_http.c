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
 *  jnw_http.c
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

#if !defined(__MTK_TARGET__)
/* mdi_datatype.h include MMIDataType.h which conflict with soc_api.h  */
#include "Windows.h"
#endif /* !defined(__MTK_TARGET__) */ 

#include "jal.h"
#include "mmi_frm_gprot.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "syscomp_config.h"
#include "task_config.h"
#include "custom_config.h"

#include "wapadp.h"
#include "wap_ps_struct.h"
#include "j2me_trace.h"

#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "jnw_internal.h"
#include "jnw_interface.h"

#include "jvm_internal.h"
#include "jvm_adaptor.h"

#include "mmiapi.h"

/* Network */
#include "soc_api.h"
#include "soc2tcpip_struct.h"
#include "l3_inc_enums.h"

#include "app_str.h"
#include "cbm_api.h"

#include "Custom_events_notify.h"
#include "cbmSrvGprot.h"
#include "Dtcntsrvgprot.h"

#include "app_url.h"
#include "kal_public_api.h"


#if defined( __NEMO_VM__)
#include "thread_stack_switch.h"
#endif
/* HTTP status table */
const char *http_info_msg[] = 
{
    "Continue",             /* 100 continue */
    "Switching Protocols"   /* 101 switching protocols */
};

const char *http_success_msg[] = 
{
    "OK",                               /* 200 OK */
    "Created",                          /* 201 Created */
    "Accepted",                         /* 202 Accepted */
    "Non-Authoritative Information",    /* 203 Non-Authoritative Information */
    "No Content",                       /* 204 No Content */
    "Reset Content",                    /* 205 Reset Content */
    "Partial Content"                   /* 206 Partial Content */
};

const char *http_redirect_msg[] = 
{
    "Multiple Choices",     /* 300 Multiple Choices */
    "Moved Permanently",    /* 301 Moved Permanently */
    "Found",                /* 302 Found */
    "See Other",            /* 303 See Other */
    "Not Modified",         /* 304 Not Modified */
    "Use Proxy",            /* 305 Use Proxy */
    "",                     /* 306 Unused */
    "Temporary Redirect"    /* 307 Temporary Redirect */
};

const char *http_client_err_msg[] = 
{
    "Bad Request",                      /* 400 Bad Request */
    "Unauthorized",                     /* 401 Unauthorized */
    "Payment Required",                 /* 402 Payment Required */
    "Forbidden",                        /* 403 Forbidden */
    "Not Found",                        /* 404 Not Found */
    "Method Not Allowed",               /* 405 Method Not Allowed */
    "Not Acceptable",                   /* 406 Not Acceptable */
    "Proxy Authentication Required",    /* 407 Proxy Authentication Required */
    "Request Timeout",                  /* 408 Request Timeout */
    "Conflict",                         /* 409 Conflict */
    "Gone",                             /* 410 Gone */
    "Length Required",                  /* 411 Length Requred */
    "Precondition Failed",              /* 412 Precondition Failed */
    "Request Entity Too Large",         /* 413 Request Entity Too Large */
    "Request-URI Too Long",             /* 414 Request-URI Too Long */
    "Unsupported Media Type",           /* 415 Unsupported Media Type */
    "Requested Range Not Satisfiable",  /* 416 Requested Range Not Satisfiable */
    "Expectation Failed"                /* 417 Expectation Failed */
};

const char *http_server_err_msg[] = 
{
    "Internal Server Error",        /* 500 Internal Server Error */
    "Not Implemented",              /* 501 Not Implemented */
    "Bad Gateway",                  /* 502 Bad Gateway */
    "Service Unavailable",          /* 503 Service Unavailable */
    "Gateway Timeout",              /* 504 Gateway Timeout */
    "HTTP Version Not Supported"    /* 505 HTTP Version Not Supported */
};

const char **http_status_msg[] = 
{
    http_info_msg,
    http_success_msg,
    http_redirect_msg,
    http_client_err_msg,
    http_server_err_msg
};

extern srv_dtcnt_prof_proxy_info_cnf_struct net_prof_install;
extern kal_mutexid g_jam_http_async_mutex;
extern j2me_nwk_event_struct j2me_nwk_bearer_evt[];


static kal_uint16 jnw_http_current_req_id = 0;
static kal_uint16 jnw_https_current_req_id = 1;    /* odd for HTTPS */
static kal_bool   jnw_http_initialized = KAL_FALSE;

static j2me_http_app_data_struct j2me_http_app_data[J2ME_MAX_APP_NUM];
static jnw_http_callback_struct http_callback[J2ME_MAX_APP_NUM];

static jnw_http_sec_certificate_file_struct jnw_http_sec_certificate = {0, NULL, 0};
/* special code for WAP off */
#ifndef WAP_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_pun_var_part
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op          [IN]        
 *  msg_id      [IN]        
 *  p           [?]         
 *  buf         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 wps_pun_var_part(kal_uint8 op, kal_uint32 msg_id, void *p, kal_uint8 *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}
#endif /* WAP_SUPPORT */ 

/* static function */
static kal_int16 jnw_http_find_conn_slot(kal_uint32 channel_id);
static kal_int16 jnw_http_find_app_chan_slot(kal_uint32 vm_id);
static kal_int16 jnw_http_find_app_slot(kal_uint32 vm_id);
static kal_int8  jnw_http_find_app_req_slot(kal_uint32 req_id, kal_uint8 action_id, kal_uint32 *app_idx, kal_uint32 *req_idx);
static kal_int16 jnw_http_get_free_app_slot(void);
static kal_int16 jnw_http_get_free_app_req_slot(kal_uint32 app_idx);
static kal_int8  jnw_http_query_bearer_status(kal_uint32 vm_id);
static kal_int32 jnw_http_do_check(kal_uint32 vm_id, kal_uint32 req_id, kal_uint32 msg_id);
static void jnw_http_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id);
static void jnw_http_msg_cb(void *rsp_hdr, kal_int32 rsp_len, void *data, kal_int32 len, kal_int32 msg_id, kal_int32 request_id);


/*****************************************************************************
 * FUNCTION
 *  jnw_http_is_url_valid
 * DESCRIPTION
 *  check whether url is valid or not
 *
 * PARAMETERS
 *  url              [IN]        
 * RETURNS
 *  KAL_TRUE: valid
 *  KAL_FALSE: invalid
 *****************************************************************************/
kal_bool jnw_http_is_url_valid(kal_uint8 *url)
{
    if (applib_url_is_valid((const char *)url) != 0)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_set_auto_redirect
 * DESCRIPTION
 *  enable or disable auto redirection. 
 *  By default, the auto redirection is enable.
 *
 * PARAMETERS
 *  enable              [IN]        on or off
 * RETURNS
 *  void
 *****************************************************************************/
kal_int8 jnw_http_set_non_auto_redirect(kal_uint32 vm_id, kal_bool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((idx = jnw_http_find_app_slot(vm_id)) < 0)
    {
        /* store the req id and app id */
        if ((idx = jnw_http_get_free_app_slot()) < 0)
        {
            /* Error: no free application slot */
            return J2ME_HTTP_ERROR;
        }
    }

    j2me_http_app_data[idx].app_id = (kal_int16) vm_id;
    kal_trace(TRACE_GROUP_3,J2ME_HTTP_NON_AUTO_REDIRECTION,enable);
    
    if (enable)
    {
        j2me_http_app_data[idx].option |= J2ME_HTTP_NON_AUTO_REDIRECT_OPT;
    }
    else
    {
        j2me_http_app_data[idx].option &= ~J2ME_HTTP_NON_AUTO_REDIRECT_OPT;
    }
    return J2ME_HTTP_OK;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_http_register_callback
 * DESCRIPTION
 *  register the callback function for HTTP response. The first parameter of the call back function
 *  is the message id getting from jnw_http_check_response_primitive, such as MSG_WPS_SET_CHANNEL_RSP,
 *  and the second parameter is channel id for channel ralitive messages, conneciton id (or request
 *  id) for http write and read relative messages, or a dummy number for other messages.
 * PARAMETERS
 *  app_id              [IN]        
 *  callback_ptr        [IN]        Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_http_register_callback(kal_int32 vm_id, void (*callback_ptr) (void *, kal_int32, void *, kal_int32, kal_int32, kal_int32))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_int8 found = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vm_id > J2ME_HTTP_INSTALL_APP_ID)
    {
        kal_trace(TRACE_GROUP_3,J2ME_VMID_ERROR ,vm_id);
        return;
    }
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (http_callback[i].app_id != -1 && http_callback[i].app_id == (kal_int32) vm_id)
        {
            found = i;
            break;
        }
        if (found == -1 && http_callback[i].app_id == -1)
        {
            found = i;
        }
    }

    if (found == -1)
    {
        /* impossible to have no slot to store the callback */
        EXT_ASSERT(0, 0, 0, 0);
    }

    http_callback[found].app_id = vm_id;
    http_callback[found].callback = callback_ptr;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_deregister_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_http_deregister_callback(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (http_callback[i].app_id != -1 && http_callback[i].app_id == (kal_int32) vm_id)
        {
            http_callback[i].app_id = -1;
            http_callback[i].callback = NULL;
            break;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_callback_handler
 * DESCRIPTION
 *  Not for exporting to be used by Java VM.
 * PARAMETERS
 *  callback_idx        [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  rsp_hdr     [?]         
 *  rsp_len     [IN]        
 *  data        [?]         
 *  len         [IN]        
 *  callback_id(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_callback_handler(kal_int32 callback_idx,
                                                          kal_int32 req_id,
                                                          kal_int32 msg_id,
                                                          void *rsp_hdr,
                                                          kal_int32 rsp_len,
                                                          void *data,
                                                          kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (http_callback[callback_idx].callback != NULL)
    {
        (*http_callback[callback_idx].callback) (rsp_hdr, rsp_len, data, len, msg_id, req_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  readHttpAsyncEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 jnw_http_do_check(kal_uint32 vm_id, kal_uint32 req_id, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_http_async_mutex);

    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (j2me_http_app_data[i].app_id == (kal_int16) vm_id)
        {
            if (j2me_http_app_data[i].sec_cert && j2me_http_app_data[i].sec_cert->msg_type == msg_id)
            {
                kal_give_mutex(g_jam_http_async_mutex);
                return J2ME_HTTP_OK;
            }

            if (j2me_http_app_data[i].sec_session && j2me_http_app_data[i].sec_session->msg_type == msg_id)
            {
                kal_give_mutex(g_jam_http_async_mutex);
                return J2ME_HTTP_OK;
            }

            for (j = 0; j < J2ME_MAX_HTTP_REQ_NUM; j++)
            {
                if (j2me_http_app_data[i].app_req[j].req_id == (kal_int16) req_id)
                {
                    if (j2me_http_app_data[i].app_req[j].data &&
                        j2me_http_app_data[i].app_req[j].data->msg_type == msg_id)
                    {
                        if (msg_id == MSG_WPS_HTTP_AUTH_IND)
                        {
                            if (j2me_http_app_data[i].app_req[j].data != NULL)
                            {
                                jvm_free(j2me_http_app_data[i].app_req[j].data);
                                j2me_http_app_data[i].app_req[j].data=NULL;
                            }
                        }
                        kal_give_mutex(g_jam_http_async_mutex);
                        return J2ME_HTTP_OK;
                    }
                }
            }
            kal_give_mutex(g_jam_http_async_mutex);
            return J2ME_HTTP_WOULDBLOCK;
        }
    }

    kal_give_mutex(g_jam_http_async_mutex);
    return J2ME_HTTP_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_http_get_channel_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *         
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 jnw_http_get_channel_id(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* channel has been set */
        kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_CHANNEL_ID, vm_id, -1);
        return J2ME_HTTP_ERROR;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_CHANNEL_ID, vm_id, j2me_http_app_data[idx].channel_id);
    return j2me_http_app_data[idx].channel_id;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [IN]
 *  peer_buff_ptr       [IN]
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_http_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sap_type sap_id;
    module_type src_mod_id;
    ilm_struct send_ilm; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_mod_id = kal_get_active_module_id();

    if (src_mod_id == MOD_JAM)
    {
        src_mod_id = MOD_JASYN_D3;
    }

    send_ilm.local_para_ptr = (local_para_struct*) local_para_ptr;
    send_ilm.msg_id = msg_id;
    send_ilm.peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    send_ilm.src_mod_id = src_mod_id;
    send_ilm.dest_mod_id = dst_id;
    send_ilm.sap_id = J2ME_WAP_SAP;
    msg_send(&send_ilm);
}


/*****************************************************************************
 * FUNCTION
 *  J2ME_http_unset_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int8 jnw_http_unset_channel(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;
    kal_int32 result;
    kal_bool is_abort = KAL_FALSE;
    ilm_struct send_ilm;
    module_type mod_id;
    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_UNSET_CHANNEL, vm_id, 0, 0);

    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* channel has been set */
        return J2ME_HTTP_ERROR;
    }

    unset_channel_req =
        (wps_unset_channel_req_struct*) construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL);
    unset_channel_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;

    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_WPS;
    send_ilm.local_para_ptr = (local_para_struct*) unset_channel_req;
    send_ilm.peer_buff_ptr = NULL;
    send_ilm.msg_id = MSG_ID_WPS_UNSET_CHANNEL_REQ;
    send_ilm.sap_id = J2ME_WAP_SAP;
    /* msg_send_ext_queue(send_ilm); */
    mod_id = kal_get_active_module_id();
    if (mod_id != MOD_JAM)
    {
        result = jvm_send_and_get_next_event(
                    &send_ilm,
                    KAL_TRUE,
                    MSG_ID_WPS_UNSET_CHANNEL_RSP,
                    KAL_FALSE,
                    KAL_TRUE,
                    &is_abort);
    }
    else
    {
        msg_send(&send_ilm);
        result = get_next_event(KAL_TRUE, MSG_ID_WPS_UNSET_CHANNEL_RSP, KAL_FALSE, KAL_TRUE, &is_abort);
    }

    if (is_abort == KAL_TRUE)
    {
        result = J2ME_HTTP_ABORT;
    }
    else
    {
        result = J2ME_HTTP_OK;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_close_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *  req_id              [IN]        
 *       
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_close_request(kal_uint32 vm_id, kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx, req_idx;
    kal_int8 result = J2ME_HTTP_ERROR;
    wps_cancel_req_struct *abort_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_SEND_ABORT, req_id);
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* no matched channel */
        return result;
    }

    if (jnw_http_find_app_req_slot(req_id, MSG_WPS_CANCEL_RSP, (kal_uint32*) & idx, (kal_uint32*) & req_idx) < 0)
    {
        if ((req_idx = jnw_http_get_free_app_req_slot(idx)) < 0)
        {
            /* no availbe req slot */
            return result;
        }
    }

    j2me_http_app_data[idx].app_req[req_idx].http_is_closing_connection = KAL_TRUE;
    j2me_http_app_data[idx].app_req[req_idx].req_id = req_id;
    j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_CANCEL_RSP;

    abort_req = (wps_cancel_req_struct*) construct_local_para(sizeof(wps_cancel_req_struct), TD_CTRL);
    abort_req->request_id = (kal_uint32) req_id;
    abort_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;

    jnw_http_send_ilm(abort_req, NULL, MSG_ID_WPS_CANCEL_REQ, MOD_WPS);
    return J2ME_HTTP_OK;
}


/*****************************************************************************
 * FUNCTION
 *  http_wps_response_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void http_wps_response_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 call_back_id = 0;
    kal_uint32 rsp_len = 0;
    kal_uint8 i;
    kal_int8 callback_idx = -1;
    kal_uint32 msg_id = 0;
    kal_int32 app_idx, req_idx;
    void *pdu_buf = NULL;
    kal_uint8 req_num = 0;
    kal_uint16 req_num_id[J2ME_MAX_HTTP_REQ_NUM];
    kal_uint16 pdu_length = 0;
    void *pending_actions[J2ME_MAX_HTTP_REQ_NUM];
    kal_int16 pending_action_len[J2ME_MAX_HTTP_REQ_NUM];
    kal_int8 pending_action_ids[J2ME_MAX_HTTP_REQ_NUM];
    kal_int8 cur_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER);

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_WPS_TERMINATION_IND:
        {
            for(i = 0; i < MAX_VM_INSTANCE_NUM; i++)
            {
                jnw_http_finalize(i);
                jnw_http_initialize(i);
            }
        }
            break;
        case MSG_ID_WPS_SET_CHANNEL_RSP:
        {
            wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) ilm_ptr->local_para_ptr;

            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_1);

            if (jnw_http_find_app_req_slot(p->req_id, MSG_WPS_SET_CHANNEL_RSP, (kal_uint32*) & app_idx, (kal_uint32*) & req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            /* count the number of set channel req */
            for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
            {
                if (j2me_http_app_data[app_idx].app_req[i].req_id != -1)
                {
                    req_num_id[req_num] = j2me_http_app_data[app_idx].app_req[i].req_id;
                    req_num++;
                    j2me_http_app_data[app_idx].app_req[i].action_ongoing = KAL_FALSE;

                    if (http_callback[callback_idx].callback != jnw_http_msg_cb &&
                        j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID)
                    {
                        j2me_http_app_data[app_idx].app_req[i].req_id = -1;
                        j2me_http_app_data[app_idx].app_req[i].action_id = 0;
                    }
                }
            }
            j2me_http_app_data[app_idx].channel_id = p->channel_id;
            rsp_len = sizeof(wps_set_channel_rsp_struct);
            call_back_id = p->req_id;
            msg_id = MSG_WPS_SET_CHANNEL_RSP;
        }
            break;

        case MSG_ID_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) ilm_ptr->local_para_ptr;
            kal_uint32 app_idx, req_idx;

            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_3);

            if (jnw_http_find_app_req_slot(p->request_id, MSG_WPS_HTTP_RSP, 
                &app_idx, &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                break;
            }
     
            if ((p->result == WPS_ERROR_REQ_ABORT) &&
                ((p->cause >= WPS_CAUSE_WTLS_BAD_RECORD) &&
                 (p->cause <= WPS_CAUSE_TLS_CANCEL)))
            {
                p->result = WPS_ERROR_ACCESS_DENY;
            }
            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            if (p->more!=1 &&
                http_callback[callback_idx].callback != jnw_http_msg_cb &&
                j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID)
            {
                j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
            }
            j2me_http_app_data[app_idx].app_req[req_idx].action_ongoing = KAL_FALSE;
            rsp_len = sizeof(wps_http_rsp_struct);
            call_back_id = p->request_id;
            msg_id = MSG_WPS_HTTP_RSP;
        }
            break;

        case MSG_ID_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) ilm_ptr->local_para_ptr;

            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_4);
            if (jnw_http_find_app_req_slot(p->request_id, MSG_WPS_READ_CONTENT_RSP,
                (kal_uint32*) & app_idx, (kal_uint32*) & req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            if (p->more!=1 &&
                http_callback[callback_idx].callback != jnw_http_msg_cb &&
                j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID)
            {
                j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
            }
            j2me_http_app_data[app_idx].app_req[req_idx].action_ongoing = KAL_FALSE;
            rsp_len = sizeof(wps_read_content_rsp_struct);
            call_back_id = p->request_id;
            msg_id = MSG_WPS_READ_CONTENT_RSP;
        }
            break;

        case MSG_ID_WPS_POST_CONTENT_IND:
        {
            wps_post_content_ind_struct *p = (wps_post_content_ind_struct*) ilm_ptr->local_para_ptr;
            wps_http_rsp_struct *http_rsp = NULL;

            if (jnw_http_find_app_req_slot(p->request_id, MSG_WPS_POST_CONTENT_IND,
                (kal_uint32*) & app_idx, (kal_uint32*) & req_idx) < 0)
            {
                if (p->result != WPS_OK)
                {
                    if (jnw_http_find_app_req_slot(p->request_id, MSG_WPS_HTTP_RSP,
                        (kal_uint32*) & app_idx, (kal_uint32*) & req_idx) < 0)
                    {
                        /* Error: no matched request id */
                        kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                        return;
                    }
                    else
                    {
                        if (j2me_http_app_data[app_idx].app_req[req_idx].action_id ==
                            MSG_WPS_HTTP_RSP)
                        {
                            http_rsp = (wps_http_rsp_struct*) construct_local_para(sizeof(wps_http_rsp_struct), TD_CTRL);
                            http_rsp->result = WPS_ERROR_REQ_ABORT;
                            http_rsp->request_id = p->request_id;
                            free_local_para((local_para_struct*)p);
                            msg_id = MSG_WPS_HTTP_RSP;
                            ilm_ptr->local_para_ptr = (local_para_struct*)http_rsp;
                            ilm_ptr->msg_id = MSG_ID_WPS_HTTP_RSP;
                        }
                        
                    }
                }
                else
                {
                    /* Error: no matched request id */
                    kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                    return;
                }
                
            }
            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_5);

            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            j2me_http_app_data[app_idx].app_req[req_idx].action_ongoing = KAL_FALSE;
            if (msg_id == MSG_WPS_HTTP_RSP)
            {
                rsp_len = sizeof(wps_http_rsp_struct);
                call_back_id = http_rsp->request_id;
            }
            else
            {
                rsp_len = sizeof(wps_post_content_ind_struct);
                call_back_id = p->request_id;
                msg_id = MSG_WPS_POST_CONTENT_IND;
            }
        }
            break;

        case MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP:
        {
            wps_sec_get_session_info_rsp_struct *p = (wps_sec_get_session_info_rsp_struct*) ilm_ptr->local_para_ptr;

            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_6);

            if ((app_idx = jnw_http_find_conn_slot(p->channel_id)) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            if (http_callback[callback_idx].callback != jnw_http_msg_cb &&
                j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID &&
                j2me_http_app_data[app_idx].session_ref_count > 0)
            {
                j2me_http_app_data[app_idx].session_ref_count--;
            }

            rsp_len = sizeof(wps_sec_get_session_info_rsp_struct);
            call_back_id = j2me_http_app_data[app_idx].app_id;
            msg_id = MSG_WPS_SEC_GET_SESSION_INFO_RSP;
        }
            break;

        case MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP:
        {
            wps_sec_get_current_cert_rsp_struct *p = (wps_sec_get_current_cert_rsp_struct*) ilm_ptr->local_para_ptr;

            kal_trace(TRACE_GROUP_3, FUNC_HTTP_WPS_RESPONSE_HANDLER_7);

            if ((app_idx = jnw_http_find_conn_slot(p->channel_id)) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            if (http_callback[callback_idx].callback != jnw_http_msg_cb &&
                j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID &&
                j2me_http_app_data[app_idx].cert_ref_count > 0)
            {
                j2me_http_app_data[app_idx].cert_ref_count--;
            }

            rsp_len = sizeof(wps_sec_get_current_cert_rsp_struct);
            call_back_id = j2me_http_app_data[app_idx].app_id;
            msg_id = MSG_WPS_SEC_GET_CURRENT_CERT_RSP;
        }
            break;

        case MSG_ID_WPS_CANCEL_RSP:
        {
            wps_cancel_rsp_struct *p = (wps_cancel_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jnw_http_find_app_req_slot(p->request_id, MSG_WPS_CANCEL_RSP, 
                (kal_uint32*) & app_idx, (kal_uint32*) & req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            /* generate the pending action items */
            for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
            {
                if (j2me_http_app_data[app_idx].app_req[i].req_id == p->request_id &&
                    j2me_http_app_data[app_idx].app_req[i].action_id != MSG_WPS_CANCEL_RSP)
                {
                    if (j2me_http_app_data[app_idx].app_req[i].action_ongoing)
                    {
                        j2me_http_app_data[app_idx].app_req[i].action_ongoing = KAL_FALSE;
                        if (j2me_http_app_data[app_idx].app_req[i].action_id ==
                        MSG_WPS_SET_CHANNEL_RSP)
                        {
                            wps_set_channel_rsp_struct *set_channel_rsp;
                            pending_actions[cur_idx] =
                            jvm_malloc(sizeof(wps_set_channel_rsp_struct));
                            memset(pending_actions[cur_idx], 0, sizeof(wps_set_channel_rsp_struct));
                            set_channel_rsp = (wps_set_channel_rsp_struct *)pending_actions[cur_idx];
                            set_channel_rsp->result = WPS_ERROR_REQ_ABORT;
                            set_channel_rsp->req_id = (kal_uint32)p->request_id;
                            set_channel_rsp->channel_id = (kal_uint8)j2me_http_app_data[app_idx].channel_id;
                            pending_action_ids[cur_idx] = MSG_WPS_SET_CHANNEL_RSP;
                            pending_action_len[cur_idx] = sizeof(wps_set_channel_rsp_struct);
                            cur_idx++;
                        }
                        else if (j2me_http_app_data[app_idx].app_req[i].action_id ==
                            MSG_WPS_HTTP_RSP)
                        {
                            wps_http_rsp_struct *http_rsp;
                            pending_actions[cur_idx] =
                            jvm_malloc(sizeof(wps_http_rsp_struct));
                            memset(pending_actions[cur_idx], 0, sizeof(wps_http_rsp_struct));
                            http_rsp = (wps_http_rsp_struct *)pending_actions[cur_idx];
                            http_rsp->result = WPS_ERROR_REQ_ABORT;
                            http_rsp->request_id = (kal_uint8)p->request_id;
                            pending_action_ids[cur_idx] = MSG_WPS_HTTP_RSP;
                            pending_action_len[cur_idx] = sizeof(wps_http_rsp_struct);
                            cur_idx++;
                        }
                        else if (j2me_http_app_data[app_idx].app_req[i].action_id ==
                            MSG_WPS_POST_CONTENT_IND)
                        {
                            wps_post_content_ind_struct *post_ind;
                            pending_actions[cur_idx] =
                            jvm_malloc(sizeof(wps_post_content_ind_struct));
                            memset(pending_actions[cur_idx], 0, sizeof(wps_post_content_ind_struct));
                            post_ind = (wps_post_content_ind_struct *)pending_actions[cur_idx];
                            post_ind->request_id = (kal_uint8)p->request_id;
                            post_ind->result = WPS_ERROR_REQ_ABORT;
                            pending_action_ids[cur_idx] = MSG_WPS_POST_CONTENT_IND;
                            pending_action_len[cur_idx] = sizeof(wps_post_content_ind_struct);
                            cur_idx++;
                        }
                        else if (j2me_http_app_data[app_idx].app_req[i].action_id ==
                            MSG_WPS_READ_CONTENT_RSP)
                        {
                            wps_read_content_rsp_struct *http_read_rsp;
                            pending_actions[cur_idx] =
                            jvm_malloc(sizeof(wps_read_content_rsp_struct));
                            memset(pending_actions[cur_idx], 0, sizeof(wps_read_content_rsp_struct));
                            http_read_rsp = (wps_read_content_rsp_struct *)pending_actions[cur_idx];
                            http_read_rsp->request_id = (kal_uint8)p->request_id;
                            http_read_rsp->result = WPS_ERROR_REQ_ABORT;  
                            pending_action_ids[cur_idx] = MSG_WPS_READ_CONTENT_RSP;
                            pending_action_len[cur_idx] = sizeof(wps_read_content_rsp_struct);
                            cur_idx++;   
                        }
                    }
                    else
                    {
                        if (j2me_http_app_data[app_idx].app_req[i].data == NULL)
                        {
                            j2me_http_app_data[app_idx].app_req[i].req_id = -1;
                            j2me_http_app_data[app_idx].app_req[i].action_id = 0;
                        }
                    }
                }
            
            }

            if (j2me_http_app_data[app_idx].app_req[req_idx].http_is_closing_connection)
            {
                j2me_http_app_data[app_idx].app_req[req_idx].http_is_closing_connection = KAL_FALSE;
                if (p->result == WPS_ERROR_INVALID_REQUEST_ID)
                {
                    p->result = WPS_OK;
                }
            }

            /* find the callback function */
            for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
            {
                if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[app_idx].app_id)
                {
                    break;
                }
            }
            if (callback_idx >= J2ME_MAX_APP_NUM)
            {
                /* should not happen. Callback should has been registered */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }
            if (http_callback[callback_idx].callback != jnw_http_msg_cb &&
                j2me_http_app_data[app_idx].app_id != J2ME_HTTP_INSTALL_APP_ID)
            {
                j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
            }
            rsp_len = sizeof(wps_cancel_rsp_struct);
            call_back_id = p->request_id;
            msg_id = MSG_WPS_CANCEL_RSP;
        }
            break;

        case MSG_ID_WPS_HTTP_AUTH_IND:
        {
            wps_http_auth_ind_struct *p = (wps_http_auth_ind_struct*) ilm_ptr->local_para_ptr;

            for (i = 0; i < J2ME_MAX_APP_NUM; i++)
            {
                if (j2me_http_app_data[i].channel_id == p->channel_id)
                {
                    break;
                }

            }
            if (i >= J2ME_MAX_APP_NUM)
            {
                /* No channel, Error!! */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                return;
            }

            if (j2me_http_app_data[i].auto_return_for_auth)
            {
                wps_http_auth_res_struct *auth_res;

                auth_res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);
                auth_res->channel_id = p->channel_id;
                auth_res->request_id = p->request_id;
                auth_res->username[0] = 0;
                auth_res->password[0] = 0;

                jnw_http_send_ilm(auth_res, NULL, MSG_ID_WPS_HTTP_AUTH_RES, MOD_WPS);
            }
            else
            {
                rsp_len = sizeof(wps_cancel_rsp_struct);
                call_back_id = p->request_id;
                /* find the callback function */
                for (callback_idx = 0; callback_idx < J2ME_MAX_APP_NUM; callback_idx++)
                {
                    if (http_callback[callback_idx].app_id == (kal_int32) j2me_http_app_data[i].app_id)
                    {
                        break;
                    }
                }
                if (callback_idx >= J2ME_MAX_APP_NUM)
                {
                    /* should not happen. Callback should has been registered */
                    kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, ilm_ptr->msg_id);
                    JNW_ASSERT_DBG(0);
                }
                msg_id = MSG_WPS_HTTP_AUTH_IND;
            }
        }
            break;

        default:
            break;

    }

    if (callback_idx != -1)
    {
        for (i = 0; i < cur_idx; i++)
        {
            if (pending_actions[i])
            {
                /* pending items is passed to the callback function */
                jnw_callback_handler(
                callback_idx,
                call_back_id,
                pending_action_ids[i],
                (void*)pending_actions[i],
                pending_action_len[i],
                (void*)NULL,
                0);
                /* release pending items memory */
                jvm_free(pending_actions[i]);
            }
        }
        
        if (ilm_ptr->peer_buff_ptr)
        {
            pdu_buf = get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length);
        }

        if (req_num > 0)
        {
            for (i = 0; i < req_num; i++)
            {
                wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) ilm_ptr->local_para_ptr;

                p->req_id = (kal_uint32) req_num_id[i];
                jnw_callback_handler(
                    callback_idx,
                    req_num_id[i],
                    msg_id,
                    (void*)ilm_ptr->local_para_ptr,
                    rsp_len,
                    (void*)pdu_buf,
                    pdu_length);
            }
        }
        else
        {
            jnw_callback_handler(
                callback_idx,
                call_back_id,
                msg_id,
                (void*)ilm_ptr->local_para_ptr,
                rsp_len,
                (void*)pdu_buf,
                pdu_length);
        }

    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_current_response_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_current_response_req_id(void *data, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 reqId = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_WPS_SET_CHANNEL_RSP:
        {
            wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) data;

            reqId = (kal_int32) p->req_id;
        }
            break;

        case MSG_WPS_CANCEL_RSP:
        {
            wps_cancel_rsp_struct *p = (wps_cancel_rsp_struct*) data;

            reqId = (kal_int32) p->request_id;
        }
            break;

        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) data;

            reqId = (kal_int32) p->request_id;
        }
            break;

        case MSG_WPS_POST_CONTENT_IND:
        {
            wps_post_content_ind_struct *p = (wps_post_content_ind_struct*) data;

            reqId = (kal_int32) p->request_id;
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) data;

            reqId = (kal_int32) p->request_id;
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPGETREQID, reqId);
    return reqId;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_status(void *data, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 status = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) data;

            status = (kal_int32) p->status;
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_STATUS, status);
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_chk_status_code
 * DESCRIPTION
 *  check if the status is the valid stats code defined in the HTTP RFC 2616
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jnw_http_chk_status_code(kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool valid = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status >= 100 && status <= 101)
    {
        valid = KAL_TRUE;
    }
    else if (status >= 200 && status <= 206)
    {
        valid = KAL_TRUE;
    }
    else if ((status != 306) && (status >= 300) && (status <= 307))
    {
        valid = KAL_TRUE;
    }
    else if (status >= 400 && status <= 417)
    {
        valid = KAL_TRUE;
    }
    else if (status >= 500 && status <= 505)
    {
        valid = KAL_TRUE;
    }

    return valid;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_status_message
 * DESCRIPTION
 *  get the status message by the status code
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  NULL when there is no status message for this status code
 *****************************************************************************/
kal_uint8 *jnw_http_get_status_message(kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 major_code = ((status / 100) - 1);
    kal_uint8 minor_code = (status % 100);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jnw_http_chk_status_code(status))
    {
        return NULL;
    }

    return (kal_uint8*) http_status_msg[major_code][minor_code];
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_check_more
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jnw_http_check_more(void *data, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool more = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return more;
    }

    switch (msg_id)
    {
        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) data;

            more = p->more;
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) data;

            more = p->more;
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_CHK_MORE, more);
    return more;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_reply_header_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_reply_header_length(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_var_struct http_rsp_var;
    kal_int32 headerLength = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return headerLength;
    }

    memset(&http_rsp_var, 0, sizeof(wps_http_rsp_var_struct));
    if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, (kal_uint8*) data) > 0)
    {
        headerLength = (kal_int32) http_rsp_var.reply_header_len;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_RPLY_LEN, headerLength);
    return headerLength;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_reply_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 *  header      [OUT]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jnw_http_get_reply_header(void *data, kal_uint8 *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_var_struct http_rsp_var;
    kal_int32 headerLength = -1;
    kal_uint8 *reply_header = header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL || header == NULL)
    {
        return KAL_FALSE;
    }

    memset(&http_rsp_var, 0, sizeof(wps_http_rsp_var_struct));
    if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, data) > 0)
    {
        headerLength = (kal_int32) http_rsp_var.reply_header_len;
        if (headerLength > 0)
        {
            memcpy(reply_header, http_rsp_var.reply_header, headerLength);
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_reply_segment_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_reply_segment_length(void *data, kal_int32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 segLength = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return segLength;
    }

    switch (msg_id)
    {
        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_var_struct http_rsp_var;

            memset(&http_rsp_var, 0, sizeof(wps_http_rsp_var_struct));
            if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, data) > 0)
            {
                segLength = (kal_int32) http_rsp_var.reply_segment_len;
            }
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_var_struct http_read_content_rsp_var;

            memset(&http_read_content_rsp_var, 0, sizeof(wps_read_content_rsp_var_struct));
            if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_READ_CONTENT_RSP, &http_read_content_rsp_var, data) > 0)
            {
                segLength = (kal_int32) http_read_content_rsp_var.reply_segment_len;
            }
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_RPLY_SEG_LEN, segLength);
    return segLength;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_reply_segment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  seg         [OUT]
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jnw_http_get_reply_segment(void *data, kal_uint8 *seg, kal_int32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *reply_segment = seg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL || seg == NULL)
    {
        return KAL_FALSE;
    }

    switch (msg_id)
    {
        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_var_struct http_rsp_var;

            memset(&http_rsp_var, 0, sizeof(wps_http_rsp_var_struct));
            if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_HTTP_RSP, &http_rsp_var, data) > 0)
            {
                memcpy(reply_segment, http_rsp_var.reply_segment, http_rsp_var.reply_segment_len);
                return KAL_TRUE;
            }
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_var_struct http_read_content_rsp_var;

            memset(&http_read_content_rsp_var, 0, sizeof(wps_read_content_rsp_var_struct));
            if (wps_pun_var_part(WPS_PUN_UNPACK, MSG_ID_WPS_READ_CONTENT_RSP, &http_read_content_rsp_var, data) > 0)
            {
                memcpy(
                    reply_segment,
                    http_read_content_rsp_var.reply_segment,
                    http_read_content_rsp_var.reply_segment_len);
                return KAL_TRUE;
            }
        }
            break;

        default:
            break;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_find_conn_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_id          [IN]        
 *         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 jnw_http_find_conn_slot(kal_uint32 channel_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (j2me_http_app_data[i].channel_id == (kal_int16) channel_id)
        {
            return i;
        }
    }

    return J2ME_HTTP_ERROR;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_find_app_chan_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *         
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 jnw_http_find_app_chan_slot(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (j2me_http_app_data[i].app_id == (kal_int16) vm_id)
        {
            if (j2me_http_app_data[i].channel_id != -1)
            {
                return (kal_int16)i;
            }
        }
    }

    return J2ME_HTTP_ERROR;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_find_app_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 jnw_http_find_app_slot(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (j2me_http_app_data[i].app_id == (kal_int16) vm_id)
        {
            return i;
        }
    }

    return J2ME_HTTP_ERROR;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_free_app_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *       
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 jnw_http_get_free_app_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        if (j2me_http_app_data[i].app_id == -1)
        {
            return i;
        }
    }

    return J2ME_HTTP_ERROR;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_free_app_req_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_idx             [IN]        
 *       
 * RETURNS
 *  
 *****************************************************************************/
static kal_int16 jnw_http_get_free_app_req_slot(kal_uint32 app_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
    {
        if (j2me_http_app_data[app_idx].app_req[i].req_id == -1)
        {
            return (kal_int16)i;
        }
    }

    return J2ME_HTTP_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_find_app_req_slot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id              [IN]        
 *  app_idx             [?]         
 *  req_idx             [?]         
 *        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int8 jnw_http_find_app_req_slot(kal_uint32 req_id, kal_uint8 action_id, 
                                           kal_uint32 *app_idx, kal_uint32 *req_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    kal_int8 action_id2 = MSG_WPS_END;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action_id == MSG_WPS_HTTP_AUTH_IND)
    {
        action_id = MSG_WPS_HTTP_RSP;
        action_id2 = MSG_WPS_POST_CONTENT_IND;
    }
    
    for (i = 0; i < J2ME_MAX_APP_NUM; i++)
    {
        for (j = 0; j < J2ME_MAX_HTTP_REQ_NUM; j++)
        {
            if (j2me_http_app_data[i].app_req[j].req_id == (kal_int16) req_id &&
                (j2me_http_app_data[i].app_req[j].action_id == action_id ||
                 j2me_http_app_data[i].app_req[j].action_id == action_id2))
            {
                if (app_idx)
                {
                    *app_idx = i;
                }

                if (req_idx)
                {
                    *req_idx = j;
                }

                return J2ME_HTTP_OK;
            }
        }
    }

    return J2ME_HTTP_ERROR;

}

/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_req_id
 * DESCRIPTION
 *  Get the request id
 * PARAMETERS
 *  channelType     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jnw_http_get_req_id(kal_uint32 channelType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 CurrReqId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (channelType == J2ME_HTTP_WPS_CHANNEL_HTTP)
    {
        jnw_http_current_req_id +=  2;
        if (jnw_http_current_req_id >= 256)
        {
            jnw_http_current_req_id = 2;
        }

        CurrReqId = (kal_uint32) jnw_http_current_req_id;
    }
    else
    {   /* channelType == J2ME_HTTP_WPS_CHANNEL_HTTPS */
        jnw_https_current_req_id += 2;
        if (jnw_https_current_req_id >= 255)
        {
            jnw_https_current_req_id = 1;
        }
        
        CurrReqId = (kal_uint32) jnw_https_current_req_id;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPGETCURRENTREQID, CurrReqId);
    return CurrReqId;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_http_set_time_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *  req_id              [IN]        
 *        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_set_time_out(kal_uint32 vm_id, kal_uint32 time_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if ((idx = jnw_http_find_app_slot(vm_id)) < 0)
    {
        /* store the req id and app id */
        if ((idx = jnw_http_get_free_app_slot()) < 0)
        {
            /* Error: no free application slot */
            return J2ME_HTTP_ERROR;
        }
    }

    j2me_http_app_data[idx].timeout_val = time_val;
    return J2ME_HTTP_OK;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_http_open_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *  req_id              [IN]        
 *        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_open_connection_newsp(kal_uint32 vm_id, kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req;
    kal_int16 idx;
    kal_int32 req_idx;
    kal_int32 ret;
    kal_uint8 i = 0;
    kal_int8 app_id = 0;
    kal_bool is_success = KAL_FALSE;
    kal_bool need_to_query = KAL_TRUE;
    //kal_bool is_always_ask = KAL_TRUE;
    srv_dtcnt_prof_proxy_info_cnf_struct *da_prof = NULL;
    kal_uint32 account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_J2ME_HTTP_OPEN_CONN, vm_id, req_id);
    /* check if the channel has been set by app id */
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
    {
        /* channel has been set */
        return (kal_int8) j2me_http_app_data[idx].channel_id;
    }

    if ((idx = jnw_http_find_app_slot(vm_id)) < 0)
    {
        /* store the req id and app id */
        if ((idx = jnw_http_get_free_app_slot()) < 0)
        {
            /* Error: no free application slot */
            return J2ME_HTTP_ERROR;
        }
    }

    if ((req_idx = jnw_http_get_free_app_req_slot(idx)) < 0)
    {
        /* Error: no free request slot */
        return J2ME_HTTP_ERROR;
    }

    account_id = jam_mvm_get_account_id(vm_id);
    /*check the account id's validity*/
    if (account_id ==255 || !cbm_is_account_valid(account_id))
    {
        kal_trace(TRACE_INFO, FUNC_J2ME_HTTP_ACCOUNT_VALID, vm_id, account_id);
        return J2ME_HTTP_ERROR;
    }
    
    for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
    {
        if (j2me_http_app_data[idx].app_req[req_idx].action_id == MSG_WPS_SET_CHANNEL_RSP)
        {
            need_to_query = KAL_FALSE;
            break;
        }
    }

    /* open bearer first*/
    if ((ret = jnw_http_query_bearer_status(vm_id)) != J2ME_HTTP_OK)
    {
        kal_trace(TRACE_INFO,FUNC_JNW_QUERY_BEARER_STATUS,vm_id,ret);
        if(ret == J2ME_HTTP_ERROR)
        {
            return J2ME_HTTP_ERROR;
        }
        else
        {
            return J2ME_HTTP_ABM_WOULDBLOCK;
        }
    }

    /*for Installer, need to get profile form WAP*/
    if (vm_id == J2ME_HTTP_INSTALL_APP_ID)
    {
        if (jam_nw_get_proxy_for_install(&is_success) == KAL_TRUE)
        {
            /* user abort */
            return J2ME_HTTP_ERROR;
        }
        else
        {
            if (!is_success)
            {
                return J2ME_HTTP_ERROR;
            }
        }
    }
    else
    {
        /*for Installer, need to get profile form data account servicer*/
        jam_nw_mids_set_bearer_content(account_id, KAL_FALSE, vm_id);
    }
        
    /*get the structure network profile*/
    da_prof  = jam_mvm_get_network_profile_by_vm_id(vm_id);
    if(da_prof == NULL)
    {
        kal_trace(TRACE_INFO, J2ME_JNW_DACCOUNT_NULL);
        return J2ME_HTTP_ERROR;
    }
        
    j2me_http_app_data[idx].auto_return_for_auth = KAL_TRUE;
    j2me_http_app_data[idx].app_id = (kal_int16) vm_id;
    j2me_http_app_data[idx].app_req[req_idx].req_id = (kal_int16) req_id;
    j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_SET_CHANNEL_RSP;
    j2me_http_app_data[idx].app_req[req_idx].action_ongoing = KAL_TRUE;
    if (!need_to_query)
    {
        return J2ME_HTTP_WOULDBLOCK;
    }
    app_id = jam_get_app_id(vm_id);

    set_channel_req = (wps_set_channel_req_struct*) construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);

    set_channel_req->req_id = req_id;
    set_channel_req->username[0] = 0;
    set_channel_req->password[0] = 0;
    set_channel_req->server_auth_password[0] = 0;
    set_channel_req->server_auth_username[0] = 0;
    set_channel_req->app_id = app_id;
    
    set_channel_req->use_default = KAL_FALSE;

    if (da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_HTTP ||
        da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_HTTP_TLS)
    {
        set_channel_req->conn_type = WPS_CONN_TYPE_HTTP;
    }
    else if (da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CO_WSP ||
         da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP ||
         da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA)
    {
        set_channel_req->conn_type = WPS_CONN_TYPE_WSP_CO;
    }
    else if (da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CL_WSP ||
        da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP ||
        da_prof->px_info.px_service == SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA)
    {
        set_channel_req->conn_type = WPS_CONN_TYPE_WSP_CL;
    }

    set_channel_req->net_id = da_prof->px_info.acc_id;
    if (j2me_http_app_data[idx].timeout_val  == 0)
    {
        // use default value
        set_channel_req->timeout = J2ME_HTTP_WPS_TIMEOUT;
    }
    else
    {
        set_channel_req->timeout = j2me_http_app_data[idx].timeout_val;
    }

    set_channel_req->use_proxy = da_prof->px_info.use_proxy;

    memcpy(set_channel_req->prx_addr,da_prof->px_info.px_addr,sizeof(set_channel_req->prx_addr));
    set_channel_req->prx_port = da_prof->px_info.px_port;

    memset(set_channel_req->username, 0, sizeof(set_channel_req->username));
    strcpy((char*)set_channel_req->username, (char*)da_prof->px_info.px_authid);
    memset(set_channel_req->password, 0, sizeof(set_channel_req->password));
    strcpy((char*)set_channel_req->password, (char*)da_prof->px_info.px_authpw);
    
    jnw_http_send_ilm(set_channel_req, NULL, MSG_ID_WPS_SET_CHANNEL_REQ, MOD_WPS);

    return J2ME_HTTP_WOULDBLOCK;

}
/*****************************************************************************
 * FUNCTION
 *  jnw_http_open_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *  req_id              [IN]        
 *        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_open_connection(kal_uint32 vm_id, kal_uint32 req_id)
{
    module_type module_id = kal_get_active_module_id();

    if (module_id == MOD_J2ME || module_id == MOD_J2ME_D)
    {
#ifdef USE_NEWSP_LOADJNI
    
        return jnwHttpOpenConnNewSP(vm_id,req_id);
    
#endif
    }

    return jnw_http_open_connection_newsp(vm_id,req_id);

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_close_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_close_connection(kal_uint32 vm_id, kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 result = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_HTTP_CLOSE_CONN, vm_id, req_id);
    
    result = jnw_http_close_request(vm_id, req_id);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_read_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  seq_no      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_read_req(kal_uint32 req_id, kal_int32 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 requestId, seq, idx, req_idx;
    wps_read_content_req_struct *read_content_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPREAD, req_id, seq_no);
    
    requestId = req_id;
    seq = seq_no;
    if (jnw_http_find_app_req_slot(req_id, MSG_WPS_HTTP_RSP, &idx, &req_idx) < 0)
    {
        if (jnw_http_find_app_req_slot(req_id, MSG_WPS_READ_CONTENT_RSP, &idx, &req_idx) < 0)
        {
            return J2ME_HTTP_ERROR;
        }
    }
    j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_READ_CONTENT_RSP;
    j2me_http_app_data[idx].app_req[req_idx].action_ongoing = KAL_TRUE;

    read_content_req =
        (wps_read_content_req_struct*) construct_local_para(sizeof(wps_read_content_req_struct), TD_CTRL);

    read_content_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;

    read_content_req->request_id = (kal_uint8) requestId;
    read_content_req->seq_num = (kal_uint8) seq;
    read_content_req->read_segnemtn_len = J2ME_HTTP_WPS_MAX_INPUT_BUFFER;

    jnw_http_send_ilm(read_content_req, NULL, MSG_ID_WPS_READ_CONTENT_REQ, MOD_WPS);

    return J2ME_HTTP_OK;
}

void jnw_cbm_bearer_info_handler(app_cbm_bearer_info_ind_struct *ind_ptr)
{
    kal_int32 i = 0;
    switch(ind_ptr->state)
    {
        case CBM_GPRS_AUTO_DISC_TIMEOUT:
            kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_GPRS_BEARER_TOMEROUT);
            /*Search and reset j2me_nwk_bearer_evt[i]*/
            for (i = 0; i < J2ME_MAX_APP_NUM; i++)
            {
                if (j2me_nwk_bearer_evt[i].account_id == ind_ptr->account_id &&
                    j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN )
                {
                    j2me_nwk_bearer_evt[i].wait_event = JNW_NWK_EVT_CLOSE;
                }
            }
            break;
        case CBM_CSD_AUTO_DISC_TIMEOUT:
                kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_CSD_BEARER_TOMEROUT);
            break;
        case CBM_DEACTIVATED:
                kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_BEARER_DEACTIVATED);
            if(ind_ptr->bearer == CBM_WIFI && ind_ptr->error_cause== ABM_E_REJECTED )
            {
                terminated_by_user_cancel = KAL_TRUE;
            }
            else if(ind_ptr->bearer == CBM_BEARER_NONE)
            {
                if(ind_ptr->error == CBM_INVALID_ACCT_ID ||ind_ptr->error == CBM_CANCEL_ACT_BEARER)
                    terminated_by_user_cancel = KAL_TRUE;
            }
            else
            {
                    kal_trace(TRACE_GROUP_3,FUNC_JNW_CBM_BEARER_ERROR, ind_ptr->state,ind_ptr->error,ind_ptr->error_cause);
            }
            /*Search and reset j2me_nwk_bearer_evt[i]*/
            for (i = 0; i < J2ME_MAX_APP_NUM; i++)
            {
                if (j2me_nwk_bearer_evt[i].account_id == ind_ptr->account_id &&
                    j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN )
                {
                    j2me_nwk_bearer_evt[i].wait_event = JNW_NWK_EVT_CLOSE;
                }
            }
            break;
        case CBM_ACTIVATING :
                kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_BEARER_ACTIVATING);
            break;
        case CBM_ACTIVATED:
                kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_BEARER_ACTIVATED);
            break;
        case CBM_DEACTIVATING:
                kal_trace(TRACE_GROUP_3,FUNC_JNW_ABM_BEARER_DEACTIVATING);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_query_bearer_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id                          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int8 jnw_http_query_bearer_status(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_int8 ret;
    kal_int32 bearer_status = 0;
    kal_uint32 account_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    account_id = jam_mvm_get_account_id(vm_id);
    kal_trace(TRACE_INFO,J2ME_HTTP_ABM_ACCOUNTID,account_id);
    if ((bearer_status = cbm_get_bearer_status(account_id))== CBM_ACTIVATED)
    {
        kal_trace(TRACE_INFO,J2ME_JNW_OPEN_BEARER_SUCCESS);
        /*Search and reset j2me_nwk_bearer_evt[i]*/
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (j2me_nwk_bearer_evt[i].app_id == vm_id)
            {
                j2me_nwk_bearer_evt[i].app_id = -1;
                j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                j2me_nwk_bearer_evt[i].wait_event = 0;
            }
        }
        return J2ME_HTTP_OK;
    }
    else
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (j2me_nwk_bearer_evt[i].app_id == vm_id)
            {
                if ((j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN) ||
                    (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_CLOSE))
                {
                    kal_prompt_trace(MOD_JAM,"jnw_http_query_bearer_status: break=%d",i);
                    break;
                }
            }
        }
        if (i < J2ME_MAX_APP_NUM)
        {
            if (j2me_nwk_bearer_evt[i].wait_event & JNW_NWK_EVT_OPEN)
            {
                kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER,  9, account_id, -2);
                return J2ME_HTTP_WOULDBLOCK;
            }
            else
            {
                kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER, 10, account_id, -1);
                j2me_nwk_bearer_evt[i].app_id = -1;
                j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                j2me_nwk_bearer_evt[i].wait_event = 0;
                return J2ME_HTTP_ERROR;
            }
        }
        else
        {
            for (i = 0; i < J2ME_MAX_APP_NUM; i++)
            {
                if (j2me_nwk_bearer_evt[i].app_id == -1)
                {   
                    /* bearer is not activated yet */
                    j2me_nwk_bearer_evt[i].app_id = vm_id;
                    j2me_nwk_bearer_evt[i].account_id = account_id;
                    j2me_nwk_bearer_evt[i].wait_event = JNW_NWK_EVT_OPEN;
                    ret = cbm_open_bearer(account_id);
                    kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER, 11, account_id, J2ME_HTTP_WOULDBLOCK);
                    if (ret == CBM_WOULDBLOCK)
                    {    
                        kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER,13, account_id, ret);
                        return J2ME_HTTP_WOULDBLOCK;           
                    }
                    j2me_nwk_bearer_evt[i].app_id = -1;
                    j2me_nwk_bearer_evt[i].account_id = CBM_INVALID_NWK_ACCT_ID;
                    j2me_nwk_bearer_evt[i].wait_event = 0;
                    if(ret != CBM_OK)/*return !CBM_OK  immediatelly*/
                    {
                        kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER, 14, account_id, ret);
                        return J2ME_HTTP_ERROR;
                    }
                    else /*return CBM_OK  immediatelly*/
                    {
                        kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER, 15, account_id, 0);
                        return J2ME_HTTP_OK;
                    }
                 }
                 else
                 {                 
                    kal_trace(TRACE_INFO, J2ME_JNW_OPEN_BEARER, 16, account_id, 0);
                 }
            }
        }
    }
    return J2ME_HTTP_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_write_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id                          [IN]        
 *  req_id                          [IN]        
 *  http_method                     [IN]        
 *  url_length                      [IN]        
 *  url                             [IN]        
 *  header_length                   [IN]        
 *  header                          [IN]        
 *  total_post_content_length       [IN]        
 *  post_segment_length             [IN]        
 *  post_segment                    [IN]        
 *  more_post                       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_write_req(
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
            kal_bool more_post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int requestId, method, urlLen, reqHeaderLen, contentLen = 0, postSegmentLen = 0;
    kal_bool morePost = KAL_FALSE;
    kal_uint8 *headerBuffer = NULL;
    kal_uint8 *segmentBuffer = NULL;
    kal_uint8 *urlBuffer = NULL;
    wps_http_req_struct *http_req;
    peer_buff_struct *peer_buff_ptr;
    wps_http_req_var_struct http_req_var = {0};
    kal_uint16 pdu_length;
    kal_int32 idx = 0;
    kal_int32 req_idx = -1;
    kal_uint8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    requestId = req_id;
    method = http_method;
    urlLen = url_length;
    reqHeaderLen = header_length;
    contentLen = total_post_content_length;
    postSegmentLen = post_segment_length;
    morePost = more_post;
    headerBuffer = header;
    segmentBuffer = post_segment;
    urlBuffer = url;

    kal_trace(TRACE_FUNC, FUNC_J2ME_HTTP_WRITE_REQ, vm_id, req_id);
    if ((urlLen + sizeof(urlLen) + reqHeaderLen + sizeof(reqHeaderLen) +
         postSegmentLen + sizeof(postSegmentLen)) > 2048)
    {
        kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPWRITE_1, 
                  urlLen, reqHeaderLen, postSegmentLen);
        return J2ME_HTTP_ERROR;
    }

    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* no matched channel */
        return J2ME_HTTP_ERROR;
    }

    /* profile content has been obtained, we can send data now */
    if ((req_id % 2) != 0)
    {
        /* HTTPS connection */
        for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
        {
            if (j2me_http_app_data[idx].app_req[i].req_id != req_id &&
                j2me_http_app_data[idx].app_req[i].req_id != -1 &&
                (j2me_http_app_data[idx].app_req[i].req_id % 2) != 0)
            {
                /* other HTTPs connection is existed. Please retry later!! */
                return J2ME_HTTP_WOULDBLOCK;
            }
        }
    }

    if (req_idx < 0 &&
        (req_idx = jnw_http_get_free_app_req_slot((kal_uint32)idx)) < 0)
    {
        /* no availbe req slot */
        return J2ME_HTTP_WOULDBLOCK;
    }

    j2me_http_app_data[idx].app_req[req_idx].req_id = requestId;
    if (more_post)
    {
        j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_POST_CONTENT_IND;
    }
    else
    {
        j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_HTTP_RSP;
    }

    j2me_http_app_data[idx].app_req[req_idx].action_ongoing = KAL_TRUE;

    http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);

    http_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;

    http_req->request_id = (kal_uint8) requestId;

    if (method == J2ME_HTTP_METHOD_GET)
    {
        http_req->method = WPS_HTTP_METHOD_GET;
    }
    else if (method == J2ME_HTTP_METHOD_POST)
    {
        http_req->method = WPS_HTTP_METHOD_POST;
    }
    else if (method == J2ME_HTTP_METHOD_HEAD)
    {
        http_req->method = WPS_HTTP_METHOD_HEAD;
    }

    http_req->option = WPS_HTTP_OPTION_NO_CACHE|WPS_HTTP_OPTION_DO_NOT_CACHE_REPLY;
    if (j2me_http_app_data[idx].auto_return_for_auth)
    {
        /* don't care the authentication */
        http_req->option |= 
        (WPS_HTTP_OPTION_DO_NOT_HANDLE_SERVER_AUTH | WPS_HTTP_OPTION_DO_NOT_HANDLE_PROXY_AUTH);
    }
    if (j2me_http_app_data[idx].option & J2ME_HTTP_NON_AUTO_REDIRECT_OPT)
    {
        http_req->option |= WPS_HTTP_OPTION_DO_NOT_REDIRECT;
    }
    http_req->reply_type = WPS_DATA_TYPE_BUFFER;
    http_req->reply_path[0] = '\0';
    http_req->reply_path[1] = '\0';
    http_req->reply_segment_len = J2ME_HTTP_WPS_MAX_RSP_BUFFER;

    if (method != J2ME_HTTP_METHOD_POST)
    {
        http_req->post_type = 0;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = 0;
        http_req->more_post = KAL_FALSE;
    }
    else
    {
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = contentLen;
        http_req->more_post = morePost;
    }

    http_req_var.request_url_len = (kal_uint32) urlLen;
    http_req_var.request_url = (kal_uint8*) urlBuffer;
    http_req_var.request_header_len = (kal_uint32) reqHeaderLen;
    http_req_var.request_header = (kal_uint8*) headerBuffer;

    if (method != J2ME_HTTP_METHOD_POST)
    {
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }
    else
    {
        http_req_var.post_segment_len = (kal_uint32) postSegmentLen;
        http_req_var.post_segment = (kal_uint8*) segmentBuffer;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));

    jnw_http_send_ilm(http_req, peer_buff_ptr, MSG_ID_WPS_HTTP_REQ, MOD_WPS);

    return J2ME_HTTP_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_write_content_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id                  [IN]        
 *  seq_no                  [IN]        
 *  post_segment_length     [IN]        
 *  post_segment            [IN]
 *  more_post               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_write_content_req(
            kal_uint32 req_id,
            kal_uint32 seq_no,
            kal_uint32 post_segment_length,
            kal_uint8 *post_segment,
            kal_bool more_post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int requestId, seq, postSegmentLen = 0;
    kal_bool morePost;
    kal_uint8 *segmentBuffer = NULL;
    wps_post_content_res_struct *http_post_rsp;
    peer_buff_struct *peer_buff_ptr;
    wps_post_content_res_var_struct http_post_rsp_var;
    kal_uint16 pdu_length;
    kal_uint32 idx, req_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    requestId = req_id;
    seq = seq_no;
    postSegmentLen = post_segment_length;
    morePost = more_post;
    segmentBuffer = post_segment;

    kal_trace(TRACE_FUNC, FUNC_J2ME_HTTP_WRITE_CONTENT_REQ, req_id, seq_no);
    if (postSegmentLen > 2048)
    {
        return J2ME_HTTP_ERROR;
    }

    if (jnw_http_find_app_req_slot(req_id, MSG_WPS_POST_CONTENT_IND, &idx, &req_idx) < 0)
    {
        return J2ME_HTTP_ERROR;
    }

    if (!more_post)
    {
        j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_HTTP_RSP;
    }
    j2me_http_app_data[idx].app_req[req_idx].action_ongoing = KAL_TRUE;
    
    http_post_rsp = (wps_post_content_res_struct*) construct_local_para(sizeof(wps_post_content_res_struct), TD_CTRL);

    http_post_rsp->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;
    http_post_rsp->request_id = (kal_uint8) requestId;
    http_post_rsp->seq_num = (kal_uint8) seq;
    http_post_rsp->more = morePost;

    http_post_rsp_var.post_segment_len = (kal_uint32) postSegmentLen;
    http_post_rsp_var.post_segment = (kal_uint8*) segmentBuffer;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_POST_CONTENT_RES, &http_post_rsp_var, NULL);
    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
    wps_pun_var_part(
        WPS_PUN_PACK,
        MSG_ID_WPS_POST_CONTENT_RES,
        &http_post_rsp_var,
        get_pdu_ptr(peer_buff_ptr, &pdu_length));

    jnw_http_send_ilm(http_post_rsp, peer_buff_ptr, MSG_ID_WPS_POST_CONTENT_RES, MOD_WPS);

    return J2ME_HTTP_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_clear_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id          [IN]        
 *  req_id          [IN]        
 *  url_length      [IN]        
 *  url             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_clear_cache(kal_uint32 vm_id, kal_uint32 req_id, kal_uint32 url_length, kal_char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *clear_cache;
    wps_clear_req_var_struct clear_req_var;
    kal_uint16 pdu_length;
    peer_buff_struct *peer_buff_ptr;
    kal_int32 idx, req_idx;
    ilm_struct send_ilm;
    kal_int32 result;
    kal_bool is_abort = KAL_FALSE;
    module_type mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* no matched channel */
        return J2ME_HTTP_ERROR;
    }

    if ((req_idx = jnw_http_get_free_app_req_slot(idx)) < 0)
    {
        /* no availbe req slot */
        return J2ME_HTTP_ERROR;
    }
    j2me_http_app_data[idx].app_req[req_idx].req_id = (kal_int16) req_id;
    j2me_http_app_data[idx].app_req[req_idx].action_id = MSG_WPS_CLEAR_RSP;

    clear_req_var.cache_url = (kal_uint8*) url;
    clear_req_var.cache_url_len = url_length + 1;

    clear_cache = (wps_clear_req_struct*) construct_local_para(sizeof(wps_clear_req_struct), TD_CTRL);

    clear_cache->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;

    clear_cache->request_id = (kal_uint8) req_id;
    clear_cache->operation = WPS_CLEAR_CACHE_URL_MATCH;
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, NULL);
    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_CLEAR_REQ, &clear_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));

    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_WPS;
    send_ilm.local_para_ptr = (local_para_struct*) clear_cache;
    send_ilm.peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    send_ilm.msg_id = MSG_ID_WPS_CLEAR_REQ;
    send_ilm.sap_id = J2ME_WAP_SAP;

    mod_id = kal_get_active_module_id();
    if (mod_id != MOD_JAM)
    {
        result = jvm_send_and_get_next_event(&send_ilm, KAL_TRUE, MSG_ID_WPS_CLEAR_RSP, KAL_FALSE, KAL_FALSE, &is_abort);
    }
    else
    {
        msg_send(&send_ilm);
        result = get_next_event(KAL_TRUE, MSG_ID_WPS_CLEAR_RSP, KAL_FALSE, KAL_FALSE, &is_abort);
    }
    if (is_abort == KAL_TRUE)
    {
        result = J2ME_HTTP_ABORT;
    }

    /* clear request id */
    j2me_http_app_data[idx].app_req[req_idx].req_id = -1;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_auth_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id              [IN]        
 *  req_id              [IN]        
 *  user_name           [IN]        
 *  user_name_len       [IN]        
 *  passwd              [IN]        
 *  passwd_len          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_auth_res(
            kal_uint32 vm_id,
            kal_uint32 req_id,
            kal_uint8 *user_name,
            kal_int32 user_name_len,
            kal_uint8 *passwd,
            kal_int32 passwd_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *auth_res;
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* no matched channel */
        return J2ME_HTTP_ERROR;
    }
    auth_res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);
    auth_res->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;
    auth_res->request_id = (kal_uint8) req_id;
    if (user_name_len > WPS_MAX_AUTH_USERNAME_LENGTH)
    {
        user_name_len = WPS_MAX_AUTH_USERNAME_LENGTH;
    }
    if (passwd_len > WPS_MAX_AUTH_PASSWORD_LENGTH)
    {
        passwd_len = WPS_MAX_AUTH_PASSWORD_LENGTH;
    }
    memcpy(auth_res->username, user_name, user_name_len);
    memcpy(auth_res->password, passwd, passwd_len);

    jnw_http_send_ilm(auth_res, NULL, MSG_ID_WPS_HTTP_AUTH_RES, MOD_WPS);
    return J2ME_HTTP_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_set_auto_return_auth
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  auth        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_set_auto_return_auth(kal_uint32 vm_id, kal_bool auth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
    {
        j2me_http_app_data[idx].auto_return_for_auth = auth;
        return J2ME_HTTP_OK;
    }

    return J2ME_HTTP_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_security_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_https_get_security_info_req(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_req_struct *get_session_info_req;
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETSECINFOREQ);
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        return J2ME_HTTP_ERROR;
    }
    j2me_http_app_data[idx].session_ref_count++;
    get_session_info_req =
        (wps_sec_get_session_info_req_struct*) construct_local_para(
                                                sizeof(wps_sec_get_session_info_req_struct),
                                                TD_CTRL);
    get_session_info_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;
    jnw_http_send_ilm(get_session_info_req, NULL, MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ, MOD_WPS);

    return J2ME_HTTP_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_https_get_certificate_req(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_req_struct *get_cert_req;
    kal_int16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERTREQ);
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        return J2ME_HTTP_ERROR;
    }
    j2me_http_app_data[idx].cert_ref_count++;

    get_cert_req =
        (wps_sec_get_current_cert_req_struct*) construct_local_para(
                                                sizeof(wps_sec_get_current_cert_req_struct),
                                                TD_CTRL);
    get_cert_req->channel_id = (kal_uint8) j2me_http_app_data[idx].channel_id;
    jnw_http_send_ilm(get_cert_req, NULL, MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ, MOD_WPS);

    return J2ME_HTTP_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_security_info_sec_conn_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_security_info_sec_conn_type(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_session_info_rsp_struct*) data;
    kal_trace(
        TRACE_GROUP_3,
        FUNC_J2ME_HTTP_HTTPSGETPROTOANDCIPHER,
        1, p->sec_conn_type,0, 0, 0);
    return (kal_int32) p->sec_conn_type;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_security_info_key_exchange_alg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_security_info_key_exchange_alg(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_session_info_rsp_struct*) data;
    kal_trace(
        TRACE_GROUP_3,
        FUNC_J2ME_HTTP_HTTPSGETPROTOANDCIPHER,
        2, 0,p->key_exchange_alg, 0, 0);
    return (kal_int32) p->key_exchange_alg;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_security_info_bulk_encryption_alg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_security_info_bulk_encryption_alg(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_session_info_rsp_struct*) data;
    kal_trace(
        TRACE_GROUP_3,
        FUNC_J2ME_HTTP_HTTPSGETPROTOANDCIPHER,
        3, 0, 0,p->blk_encrypt_alg, 0);
    return (kal_int32) p->blk_encrypt_alg;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_security_info_sec_hash_alg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_security_info_sec_hash_alg(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_session_info_rsp_struct*) data;
    kal_trace(
        TRACE_GROUP_3,
        FUNC_J2ME_HTTP_HTTPSGETPROTOANDCIPHER,
        4, 0, 0, 0, p->hash_alg);
    return (kal_int32) p->hash_alg;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_issuer_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_issuer_length(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERTLEN, 1, p->issuer_len, 0, 0, 0);
    return (kal_int32) p->issuer_len;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_serial_num_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_serial_num_length(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERTLEN, 2, 0, 
              p->serial_num_len, 0, 0);
    return (kal_int32) p->serial_num_len;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_sig_alg_name_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_sig_alg_name_length(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERTLEN, 3, 0, 
              0, p->sig_alg_name_len, 0);
    return (kal_int32) p->sig_alg_name_len;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_subject_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_subject_length(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERTLEN, 3, 0, 
              0, 0, p->subject_len);
    return (kal_int32) p->subject_len;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_issuer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jnw_https_get_certificate_issuer(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return NULL;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    return (kal_uint8*) p->issuer;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_serial_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jnw_https_get_certificate_serial_num(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return NULL;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    return (kal_uint8*) p->serial_num;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_sig_alg_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jnw_https_get_certificate_sig_alg_name(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return NULL;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    return (kal_uint8*) p->sig_alg_name;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_subject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jnw_https_get_certificate_subject(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return NULL;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    return (kal_uint8*) p->subject;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_type(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERT_1, p->type, 0);
    return (kal_int32) p->type;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_certificate_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_https_get_certificate_version(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return J2ME_HTTP_ERROR;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCERT_1, 0, p->version);
    return (kal_int32) p->version;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_not_after
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jnw_https_get_not_after(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return 0;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_DATE, p->not_after);
    return (kal_uint32) p->not_after;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_https_get_not_before
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jnw_https_get_not_before(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data == NULL)
    {
        return 0;
    }

    p = (wps_sec_get_current_cert_rsp_struct*) data;

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_DATE, p->not_before);
    return (kal_uint32) p->not_before;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_check_response_primitive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_check_response_primitive(kal_uint32 vm_id, kal_uint32 req_id, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = jnw_http_do_check(vm_id, req_id, msg_id);

    if (result != -2)
    {
        kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_HTTPSGETCURRENTMSG, result);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_rsp_msg_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id          [IN]        
 *  req_id          [IN]        
 *  msg_id          [IN]        
 *  rsp_len         [IN]         
 *  data_len        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_rsp_msg_len(
            kal_uint32 vm_id,
            kal_uint32 req_id,
            kal_uint32 msg_id,
            kal_uint32 *rsp_len,
            kal_uint32 *data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 app_idx, req_idx;
    j2me_http_app_rcv_data_struct *wps_data;
    kal_int32 result = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_WPS_CANCEL_RSP:
        case MSG_WPS_POST_CONTENT_IND:
        case MSG_WPS_SET_CHANNEL_RSP:
        {
            if (jnw_http_find_app_req_slot(req_id, msg_id, (kal_uint32*) &app_idx, 
                (kal_uint32*) & req_idx) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                if (wps_data != NULL)
                {
                    if (rsp_len)
                    {
                        *rsp_len = wps_data->hdr_len;
                    }

                    if (data_len)
                    {
                        *data_len = 0;
                    }
                    result = J2ME_HTTP_OK;
                }
               
            }
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        case MSG_WPS_HTTP_RSP:
        {
            if (jnw_http_find_app_req_slot(req_id, msg_id, (kal_uint32*) &app_idx, 
                (kal_uint32*) & req_idx) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                if (wps_data != NULL)
                {
                    if (rsp_len)
                    {
                        *rsp_len = wps_data->hdr_len;
                    }

                    if (data_len)
                    {
                        *data_len = wps_data->data_len;
                    }
                    result = J2ME_HTTP_OK;
                }
            }
        }
            break;

        case MSG_WPS_SEC_GET_SESSION_INFO_RSP:
        {
            if ((app_idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].sec_session;
                if (wps_data != NULL)
                {
                    if (rsp_len)
                    {
                        *rsp_len = wps_data->hdr_len;
                    }

                    if (data_len)
                    {
                        *data_len = 0;
                    }
                    result = J2ME_HTTP_OK;
                }
                
            }
        }
            break;

        case MSG_WPS_SEC_GET_CURRENT_CERT_RSP:
        {
            if ((app_idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].sec_cert;
                if (wps_data != NULL)
                {
                    if (rsp_len)
                    {
                        *rsp_len = wps_data->hdr_len;
                    }

                    if (data_len)
                    {
                        *data_len = 0;
                    }
                    result = J2ME_HTTP_OK;
                }
               
            }
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_RSP_LEN, msg_id, vm_id, req_id, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_rsp_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  rsp_hdr     [IN]         
 *  data        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_rsp_msg(
            kal_uint32 vm_id,
            kal_uint32 req_id,
            kal_uint32 msg_id,
            kal_uint8 *rsp_hdr,
            kal_uint8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 app_idx, req_idx;
    kal_uint8 i;
    j2me_http_app_rcv_data_struct *wps_data;
    wps_http_rsp_struct *http_rsp = NULL;
    wps_read_content_rsp_struct *http_read_rsp = NULL;
    kal_bool more = KAL_FALSE;
    kal_int32 result = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_WPS_CANCEL_RSP:
        case MSG_WPS_POST_CONTENT_IND:
        case MSG_WPS_SET_CHANNEL_RSP:
        {
            if (rsp_hdr != NULL &&
                jnw_http_find_app_req_slot(req_id, msg_id, 
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                if (wps_data)
                {
                    memcpy((kal_uint8*) rsp_hdr, wps_data->hdr, wps_data->hdr_len);
                    if (wps_data->hdr)
                    {
                        jvm_free(wps_data->hdr);
                    }
                    jvm_free(wps_data);

                    j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;

                    if (msg_id != MSG_WPS_POST_CONTENT_IND)
                    {
                        j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                        j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
                    }

                    /* reset all pending slot which session is finish with the same req_id */
                    for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
                    {
                        if (i != req_idx)
                        {
                            if ((j2me_http_app_data[app_idx].app_req[i].req_id == (kal_int16)req_id) &&
                            (!j2me_http_app_data[app_idx].app_req[i].action_ongoing))
                            {
                                j2me_http_app_data[app_idx].app_req[i].req_id = -1;
                                j2me_http_app_data[app_idx].app_req[i].action_id = 0;
                                wps_data = j2me_http_app_data[app_idx].app_req[i].data;
                                if (wps_data)
                                {
                                    if (wps_data->hdr)
                                    {
                                        jvm_free(wps_data->hdr);
                                        wps_data->hdr = NULL;
                                    }
                                    if (wps_data->data)
                                    {
                                        jvm_free(wps_data->data);
                                        wps_data->data = NULL;
                                    }
                                    jvm_free(wps_data);
                                    j2me_http_app_data[app_idx].app_req[i].data = NULL;
                                }
                            }
                        }
                    }
                    result = J2ME_HTTP_OK;
                }
            }
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        case MSG_WPS_HTTP_RSP:
        {
            if (rsp_hdr != NULL &&
                jnw_http_find_app_req_slot(req_id, msg_id,
                (kal_uint32*) &app_idx, (kal_uint32*) & req_idx) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                if (wps_data)
                {
                    if (wps_data->hdr)
                    {
                        if (msg_id == MSG_WPS_HTTP_RSP)
                        {
                            http_rsp = (wps_http_rsp_struct*) wps_data->hdr;
                            more = http_rsp->more;
                            result = (kal_int32)http_rsp->result;
                        }
                        if (msg_id == MSG_WPS_READ_CONTENT_RSP)
                        {
                            http_read_rsp = (wps_read_content_rsp_struct*) wps_data->hdr;
                            more = http_read_rsp->more;
                            result = (kal_int32)http_read_rsp->result;
                        }
                        if (rsp_hdr)
                        {
                            memcpy((kal_uint8*) rsp_hdr, wps_data->hdr, wps_data->hdr_len);
                        }
                        jvm_free(wps_data->hdr);
                    }
                    if (wps_data->data)
                    {
                        if (data)
                        {
                            memcpy((kal_uint8*) data, wps_data->data, wps_data->data_len);
                        }
                        jvm_free(wps_data->data);
                    }

                    jvm_free(wps_data);
                    j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                    if (result == WPS_OK)
                    {
                        if (!more)
                        {
                            j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                            j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
                        }
                    }
                    else
                    {
                        j2me_http_app_data[app_idx].app_req[req_idx].req_id = -1;
                        j2me_http_app_data[app_idx].app_req[req_idx].action_id = 0;
                    }

                    result = J2ME_HTTP_OK;
                }
            }
        }
            break;

        case MSG_WPS_SEC_GET_SESSION_INFO_RSP:
        {
            if (rsp_hdr != NULL && (app_idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].sec_session;
                if (wps_data)
                {
                    memcpy((kal_uint8*) rsp_hdr, wps_data->hdr, wps_data->hdr_len);
                    j2me_http_app_data[app_idx].session_ref_count--;
                    if (j2me_http_app_data[app_idx].session_ref_count == 0)
                    {
                        if (wps_data->hdr)
                        {
                            jvm_free(wps_data->hdr);
                        }
                        jvm_free(wps_data);
                        j2me_http_app_data[app_idx].session_ref_count = 0;
                        j2me_http_app_data[app_idx].sec_session = NULL;
                    }
                    result = J2ME_HTTP_OK;
                }
            }
        }
            break;

        case MSG_WPS_SEC_GET_CURRENT_CERT_RSP:
        {
            if (rsp_hdr != NULL && (app_idx = jnw_http_find_app_chan_slot(vm_id)) >= 0)
            {
                wps_data = j2me_http_app_data[app_idx].sec_cert;
                if (wps_data)
                {
                    memcpy((kal_uint8*) rsp_hdr, wps_data->hdr, wps_data->hdr_len);
                    j2me_http_app_data[app_idx].cert_ref_count--;
                    if (j2me_http_app_data[app_idx].cert_ref_count == 0)
                    {
                        if (wps_data->hdr)
                        {
                            jvm_free(wps_data->hdr);
                        }
                        jvm_free(wps_data);
                        j2me_http_app_data[app_idx].cert_ref_count = 0;
                        j2me_http_app_data[app_idx].sec_cert = NULL;
                    }
                    result = J2ME_HTTP_OK;
                }
            }
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_RSP, msg_id, vm_id, req_id, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]         
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_get_result(void *data, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
        case MSG_WPS_SET_CHANNEL_RSP:
        {
            wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) data;

            result = (kal_int32) p->result;
        }
            break;

        case MSG_WPS_CANCEL_RSP:
        {
            wps_cancel_rsp_struct *p = (wps_cancel_rsp_struct*) data;

            result = (kal_int32) p->result;
        }
            break;

        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) data;

            result = (kal_int32) p->result;
        }
            break;

        case MSG_WPS_POST_CONTENT_IND:
        {
            wps_post_content_ind_struct *p = (wps_post_content_ind_struct*) data;

            result = (kal_int32) p->result;
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) data;

            result = p->result;
        }
            break;

        case MSG_WPS_SEC_GET_SESSION_INFO_RSP:
        {
            wps_sec_get_session_info_rsp_struct *p = (wps_sec_get_session_info_rsp_struct*) data;

            result = p->result;
        }
            break;

        case MSG_WPS_SEC_GET_CURRENT_CERT_RSP:
        {
            wps_sec_get_current_cert_rsp_struct *p = (wps_sec_get_current_cert_rsp_struct*) data;

            result = p->result;
        }
            break;

        default:
            break;
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_GET_RET, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_msg_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_hdr         [IN]         
 *  rsp_len         [IN]        
 *  data            [IN]         
 *  len             [IN]        
 *  msg_id          [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void jnw_http_msg_cb(void *rsp_hdr, kal_int32 rsp_len, void *data, kal_int32 len, kal_int32 msg_id, kal_int32 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 app_idx, req_idx;
    kal_bool need_to_store_data = KAL_FALSE;
    j2me_http_app_rcv_data_struct *wps_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_MSG_CALLBACK, msg_id, request_id, rsp_len, len);
    kal_take_mutex(g_jam_http_async_mutex);

    switch (msg_id)
    {
        case MSG_WPS_SET_CHANNEL_RSP:
        {
            wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->req_id, msg_id, 
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_CANCEL_RSP:
        {
            wps_cancel_rsp_struct *p = (wps_cancel_rsp_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->request_id, msg_id, 
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_HTTP_RSP:
        {
            wps_http_rsp_struct *p = (wps_http_rsp_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->request_id, msg_id,
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
            }
            else
            {
                need_to_store_data = KAL_TRUE;
            }
        }
            break;

        case MSG_WPS_POST_CONTENT_IND:
        {
            wps_post_content_ind_struct *p = (wps_post_content_ind_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->request_id, msg_id,
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_READ_CONTENT_RSP:
        {
            wps_read_content_rsp_struct *p = (wps_read_content_rsp_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->request_id, msg_id,
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_SEC_GET_SESSION_INFO_RSP:
        {
            wps_sec_get_session_info_rsp_struct *p = (wps_sec_get_session_info_rsp_struct*) rsp_hdr;

            if ((app_idx = jnw_http_find_conn_slot(p->channel_id)) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_SEC_GET_CURRENT_CERT_RSP:
        {
            wps_sec_get_current_cert_rsp_struct *p = (wps_sec_get_current_cert_rsp_struct*) rsp_hdr;

            if ((app_idx = jnw_http_find_conn_slot(p->channel_id)) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }
            break;

        case MSG_WPS_HTTP_AUTH_IND:
        {
            wps_http_auth_ind_struct *p = (wps_http_auth_ind_struct*) rsp_hdr;

            if (jnw_http_find_app_req_slot(p->request_id, msg_id,
                (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
            {
                /* Error: no matched request id */
                kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                JNW_ASSERT_DBG(0);
            }
            need_to_store_data = KAL_TRUE;
        }

        default:
            break;
    }

    if (need_to_store_data)
    {
        switch (msg_id)
        {
            case MSG_WPS_POST_CONTENT_IND:
            case MSG_WPS_CANCEL_RSP:
            case MSG_WPS_SET_CHANNEL_RSP:
            {
                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                    j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                }
                j2me_http_app_data[app_idx].app_req[req_idx].data = jvm_malloc(sizeof(j2me_http_app_rcv_data_struct));

                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                    memset(wps_data, 0, sizeof(j2me_http_app_rcv_data_struct));
                    wps_data->msg_type = msg_id;
                
                    wps_data->hdr = jvm_malloc(rsp_len);
                    if(wps_data->hdr == NULL)
                    {
                        jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                        j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                    }
                    else
                    {
                        memcpy((kal_uint8*) wps_data->hdr, (kal_uint8*) rsp_hdr, rsp_len);
                        wps_data->hdr_len = rsp_len;
                    }
                }
            }
                break;

            case MSG_WPS_READ_CONTENT_RSP:
            case MSG_WPS_HTTP_RSP:
            {
                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                    j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                }
                j2me_http_app_data[app_idx].app_req[req_idx].data = jvm_malloc(sizeof(j2me_http_app_rcv_data_struct));

                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                    memset(wps_data, 0, sizeof(j2me_http_app_rcv_data_struct));
                    wps_data->msg_type = msg_id;

                    wps_data->hdr = jvm_malloc(rsp_len);
                    if(wps_data->hdr == NULL)
                    {
                        jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                        j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                    }
                    else
                    {        
                        memcpy((kal_uint8*) wps_data->hdr, (kal_uint8*) rsp_hdr, rsp_len);
                        wps_data->hdr_len = rsp_len;
           
                        if (len > 0)
                        {
                            wps_data->data = jvm_malloc(len);
                            if(wps_data->data == NULL)
                            {
                                jvm_free(wps_data->hdr);
                                jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                                j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                            }
                            else
                            {
                                memcpy((kal_uint8*) wps_data->data, (kal_uint8*) data, len);
                                wps_data->data_len = len;
                            }
                        }
                    }
                }
            }
                break;

            case MSG_WPS_SEC_GET_SESSION_INFO_RSP:
            {
                if (j2me_http_app_data[app_idx].session_ref_count <= 1)
                {

                    if (j2me_http_app_data[app_idx].sec_session != NULL)
                    {
                        jvm_free(j2me_http_app_data[app_idx].sec_session);
                        j2me_http_app_data[app_idx].sec_session = NULL;
                    }
                    j2me_http_app_data[app_idx].sec_session = jvm_malloc(sizeof(j2me_http_app_rcv_data_struct));
                    if (j2me_http_app_data[app_idx].sec_session != NULL)
                    {
                        wps_data = j2me_http_app_data[app_idx].sec_session;
                        memset(wps_data, 0, sizeof(j2me_http_app_rcv_data_struct));
                        wps_data->msg_type = msg_id;

                        wps_data->hdr = jvm_malloc(rsp_len);
                        if(wps_data->hdr == NULL)
                        {
                            jvm_free(j2me_http_app_data[app_idx].sec_session);
                            j2me_http_app_data[app_idx].sec_session = NULL;
                        }else{
                            memcpy((kal_uint8*) wps_data->hdr, (kal_uint8*) rsp_hdr, rsp_len);
                            wps_data->hdr_len = rsp_len;
                        }
                    }
                }
            }
                break;

            case MSG_WPS_SEC_GET_CURRENT_CERT_RSP:
            {
                if (j2me_http_app_data[app_idx].cert_ref_count <= 1)
                {
                    if (j2me_http_app_data[app_idx].sec_cert != NULL)
                    {
                        jvm_free(j2me_http_app_data[app_idx].sec_cert);
                        j2me_http_app_data[app_idx].sec_cert = NULL;
                    }

                    j2me_http_app_data[app_idx].sec_cert = jvm_malloc(sizeof(j2me_http_app_rcv_data_struct));
                    if (j2me_http_app_data[app_idx].sec_cert != NULL)
                    {
                        wps_data = j2me_http_app_data[app_idx].sec_cert;
                        memset(wps_data, 0, sizeof(j2me_http_app_rcv_data_struct));
                        wps_data->msg_type = msg_id;
                        wps_data->hdr = jvm_malloc(rsp_len);
                        if(wps_data->hdr == NULL)
                        {
                            jvm_free(j2me_http_app_data[app_idx].sec_cert);
                            j2me_http_app_data[app_idx].sec_cert = NULL;
                        }
                        else
                        {
                            memcpy((kal_uint8*) wps_data->hdr, (kal_uint8*) rsp_hdr, rsp_len);
                            wps_data->hdr_len = rsp_len;
                        }
                    }
                }
            }
                break;

            case MSG_WPS_HTTP_AUTH_IND:
            {
                wps_http_auth_ind_struct *p = (wps_http_auth_ind_struct*) rsp_hdr;

                if (jnw_http_find_app_req_slot(p->request_id, msg_id,
                    (kal_uint32*) &app_idx, (kal_uint32*) &req_idx) < 0)
                {
                    /* Error: no matched request id */
                    kal_trace(TRACE_ERROR, FUNC_J2ME_HTTP_ERROR_RSP, msg_id);
                    JNW_ASSERT_DBG(0);
                }
                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    jvm_free(j2me_http_app_data[app_idx].app_req[req_idx].data);
                    j2me_http_app_data[app_idx].app_req[req_idx].data = NULL;
                }
                j2me_http_app_data[app_idx].app_req[req_idx].data = jvm_malloc(sizeof(j2me_http_app_rcv_data_struct));
                if (j2me_http_app_data[app_idx].app_req[req_idx].data != NULL)
                {
                    wps_data = j2me_http_app_data[app_idx].app_req[req_idx].data;
                    memset(wps_data, 0, sizeof(j2me_http_app_rcv_data_struct));
                    wps_data->msg_type = msg_id;
                }
            }

            default:
                break;
        }
    }

    kal_give_mutex(g_jam_http_async_mutex);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_http_initialize(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_HTTP_INITIALIZE, vm_id);
    
    if (!jnw_http_initialized)
    {
        jnw_network_initialize();
        cbm_release_bearer(jam_get_app_id(vm_id));
        cbm_abort_app_bearer_event(jam_get_app_id(vm_id));
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            http_callback[i].app_id = -1;
            http_callback[i].callback = NULL;

            j2me_http_app_data[i].app_id = -1;
            j2me_http_app_data[i].channel_id = -1;
            j2me_http_app_data[i].timeout_val = 0;
            j2me_http_app_data[i].is_channel_reset = KAL_FALSE;
            j2me_http_app_data[i].option = 0;
            j2me_http_app_data[i].auto_return_for_auth = KAL_FALSE;
            j2me_http_app_data[i].cert_ref_count = 0;
            j2me_http_app_data[i].session_ref_count = 0;
            j2me_http_app_data[i].sec_cert = NULL;
            j2me_http_app_data[i].sec_session = NULL;
            for (j = 0; j < J2ME_MAX_HTTP_REQ_NUM; j++)
            {
                j2me_http_app_data[i].app_req[j].req_id = -1;
                j2me_http_app_data[i].app_req[j].action_id = 0;
                j2me_http_app_data[i].app_req[j].action_ongoing = KAL_FALSE;
                j2me_http_app_data[i].app_req[j].http_is_closing_connection = KAL_FALSE;
                j2me_http_app_data[i].app_req[j].data = NULL;
            }
        }
        jnw_http_initialized = KAL_TRUE;
    }
    
    if (vm_id == J2ME_HTTP_INSTALL_APP_ID)
    {
        /* register the callback for the insatller */
        jnw_http_register_callback(J2ME_HTTP_INSTALL_APP_ID, jnw_http_msg_cb);
    }
    else
    {
    #ifndef __JBLENDIA__
        /* register the RollTech Callback to store the data temporary */
        jnw_http_register_callback(vm_id, jnw_http_msg_cb);
    #endif /* __JBLENDIA__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_http_finalize(kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_FINALIZEHTTP);
    cbm_release_bearer(jam_get_app_id(vm_id));
    cbm_abort_app_bearer_event(jam_get_app_id(vm_id));
    jnw_http_deregister_callback(vm_id);    
    jnw_http_unset_channel(vm_id);
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_clear_pending_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int8 jnw_http_clear_pending_request(kal_uint32 vm_id, kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 idx;
    kal_uint8 i;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_HTTP_CLEAR_PENDING_REQ, vm_id, req_id);
    
    if ((idx = jnw_http_find_app_chan_slot(vm_id)) < 0)
    {
        /* no matched channel */
        return J2ME_HTTP_ERROR;
    }

    /* clear */
    for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
    {
        if (j2me_http_app_data[idx].app_req[i].req_id == (kal_int16)req_id)
        {
            j2me_http_app_data[idx].app_req[i].req_id = -1;
            j2me_http_app_data[idx].app_req[i].action_id = 0;
            j2me_http_app_data[idx].app_req[i].action_ongoing = KAL_FALSE;
            j2me_http_app_data[idx].app_req[i].http_is_closing_connection = KAL_FALSE;
            if (j2me_http_app_data[idx].app_req[i].data != NULL)
            {
                jvm_free(j2me_http_app_data[idx].app_req[i].data);
                j2me_http_app_data[idx].app_req[i].data = NULL;
            }
        }
    }

    
    return J2ME_HTTP_OK;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_http_active
 * DESCRIPTION
 *  check if there is any activated http or https channel.
 * PARAMETERS
 *  by_app_id   [IN] by application id or not
 *  app_id      [IN] application id
 * RETURNS
 *  TRUE if http or https channel is activated, FALSE otherwise.
 *****************************************************************************/
kal_bool jnw_http_active(kal_bool by_vm_id, kal_uint32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (by_vm_id)
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if ((j2me_http_app_data[i].app_id == (kal_int16)vm_id) &&
                (j2me_http_app_data[i].channel_id != -1))
            {
                return KAL_TRUE;
            }
        }
    }
    else
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (j2me_http_app_data[i].channel_id != -1)
            {
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_get_root_cert_by_cert_chain
 * DESCRIPTION
 *  Get root certificate by given certificate chain.
 *  The certificates should be given in reverse order.  i.e. cert_chain[0] should be the leaf certificate.
 * PARAMETERS
 *  cert_num        [IN]        Number of certificates in certificate chain
 *  cert_chain      [IN]        Certificate chain
 *  root_cert       [OUT]       Root certificate
 * RETURNS
 *  TRUE: jnw_http_sec_result_error_enum
 *****************************************************************************/
extern int wap_is_ready();
int jnw_http_get_root_cert_by_cert_chain(
        kal_uint8 cert_num,
        jnw_http_sec_certificate_struct **cert_chain,
        jnw_http_sec_certificate_file_struct *root_cert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct send_ilm;
    wps_sec_verify_cert_chain_req_struct *verify_cert_chain_req;
    int i = 0;
    int result = J2ME_SEC_OK;
    kal_bool is_abort = KAL_FALSE;
    module_type mod_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cert_num > MAX_WPS_CERTIFICATE_NUM)
    {
        return J2ME_SEC_ERR_INVALID_PARAMETER;
    }

#ifdef WAP_SUPPORT
    if (!wap_is_ready())
    {
        return J2ME_SEC_ERR_CRYPTOLIB_NOT_INITIALISED;
    }

    verify_cert_chain_req =
        (wps_sec_verify_cert_chain_req_struct*) construct_local_para(
                                                    sizeof(wps_sec_verify_cert_chain_req_struct),
                                                    TD_CTRL);

    verify_cert_chain_req->cert_num = cert_num;

    memset(verify_cert_chain_req->certs, 0, sizeof(verify_cert_chain_req->certs));
    while (i < cert_num)
    {
        verify_cert_chain_req->certs[i].format = cert_chain[i]->format;
        verify_cert_chain_req->certs[i].cert_len = cert_chain[i]->cert_len;
        verify_cert_chain_req->certs[i].cert = cert_chain[i]->cert;

        i++;
    }

    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_WPS;
    send_ilm.local_para_ptr = (local_para_struct*) verify_cert_chain_req;
    send_ilm.peer_buff_ptr = NULL;
    send_ilm.msg_id = MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ;
    send_ilm.sap_id = J2ME_WAP_SAP;
    /* msg_send_ext_queue(send_ilm); */
    mod_id = kal_get_active_module_id();
    if (mod_id != MOD_JAM)
    {
        result = jvm_send_and_get_next_event(
                    &send_ilm,
                    KAL_TRUE,
                    MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP,
                    KAL_FALSE,
                    KAL_FALSE,
                    &is_abort);
    }
    else
    {
        msg_send(&send_ilm);
        result = get_next_event(KAL_TRUE, MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP, KAL_FALSE, KAL_FALSE, &is_abort);
    }

    if (is_abort == KAL_FALSE)
    {
        root_cert->format = jnw_http_sec_certificate.format;
        root_cert->cert_len = jnw_http_sec_certificate.cert_len;
        root_cert->cert_file_path = jnw_http_sec_certificate.cert_file_path;
        jnw_http_sec_certificate.cert_file_path = NULL;
    }
    else
    {
        result = J2ME_SEC_ERR_GENERAL_ERROR;
    }

    return result;
#else /* WAP_SUPPORT */ 
    return J2ME_SEC_ERR_CRYPTOLIB_NOT_INITIALISED;
#endif /* WAP_SUPPORT */ 
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_verify_cert_chain_hdlr
 * DESCRIPTION
 *  Store result of MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP
 * PARAMETERS
 *  format          [IN]        
 *  root_len        [IN]        
 *  root_cert       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void jnw_http_verify_cert_chain_hdlr(kal_uint8 format, kal_uint32 root_len, kal_uint16 *root_cert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cert_file_len = (app_ucs2_strlen((kal_int8*) root_cert) + 1) * ENCODING_LENGTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jnw_http_sec_certificate.format = format;
    jnw_http_sec_certificate.cert_len = root_len;

    if (jnw_http_sec_certificate.cert_file_path != NULL)
    {
        jvm_free(jnw_http_sec_certificate.cert_file_path);
        jnw_http_sec_certificate.cert_file_path = NULL;
    }
    jnw_http_sec_certificate.cert_file_path = jvm_malloc(cert_file_len);
    memset(jnw_http_sec_certificate.cert_file_path, 0, cert_file_len);
    app_ucs2_strncpy(
        (kal_int8*) jnw_http_sec_certificate.cert_file_path,
        (kal_int8*) root_cert,
        app_ucs2_strlen((kal_int8*) root_cert));

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_clear_cache_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_clear_cache_rsp_hdlr(kal_uint32 req_id, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 app_idx, req_idx;
    kal_int32 ret = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == WPS_OK)
    {
        if (jnw_http_find_app_req_slot(req_id, MSG_WPS_CLEAR_RSP, &app_idx, &req_idx) >= 0)
        {
            ret = J2ME_HTTP_OK;
        }
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_CLEAR_CACHE, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_http_unset_channel_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 *  result          [IN]        
 *        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jnw_http_unset_channel_rsp_hdlr(kal_uint8 channel_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    kal_int16 app_idx;
    kal_int32 ret = J2ME_HTTP_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((app_idx = jnw_http_find_conn_slot(channel_id)) >= 0)
    {
        for (i = 0; i < J2ME_MAX_APP_NUM; i++)
        {
            if (http_callback[i].app_id == j2me_http_app_data[app_idx].app_id)
            {
                http_callback[i].app_id = -1;
                http_callback[i].callback = NULL;
                break;
            }
        }

        j2me_http_app_data[app_idx].channel_id = -1;
        j2me_http_app_data[app_idx].timeout_val = 0;
        j2me_http_app_data[app_idx].app_id = -1;
        j2me_http_app_data[app_idx].is_channel_reset = KAL_FALSE;
        j2me_http_app_data[app_idx].option = 0;
        j2me_http_app_data[app_idx].auto_return_for_auth = KAL_FALSE;
        /* clear all application's data */
        j2me_http_app_data[app_idx].cert_ref_count = 0;
        j2me_http_app_data[app_idx].session_ref_count = 0;
        if (j2me_http_app_data[app_idx].sec_cert)
        {
            jvm_free(j2me_http_app_data[app_idx].sec_cert);
            j2me_http_app_data[app_idx].sec_cert = NULL;
        }

        if (j2me_http_app_data[app_idx].sec_session)
        {
            jvm_free(j2me_http_app_data[app_idx].sec_session);
            j2me_http_app_data[app_idx].sec_session = NULL;
        }

        for (i = 0; i < J2ME_MAX_HTTP_REQ_NUM; i++)
        {
            j2me_http_app_data[app_idx].app_req[i].http_is_closing_connection = KAL_FALSE;
            j2me_http_app_data[app_idx].app_req[i].req_id = -1;
            j2me_http_app_data[app_idx].app_req[i].action_id = 0;
            j2me_http_app_data[app_idx].app_req[i].action_ongoing = KAL_FALSE;

            if (j2me_http_app_data[app_idx].app_req[i].data)
            {
                if (j2me_http_app_data[app_idx].app_req[i].data->data)
                {
                    jvm_free(j2me_http_app_data[app_idx].app_req[i].data->data);
                }

                if (j2me_http_app_data[app_idx].app_req[i].data->hdr)
                {
                    jvm_free(j2me_http_app_data[app_idx].app_req[i].data->hdr);
                }

                jvm_free(j2me_http_app_data[app_idx].app_req[i].data);
                j2me_http_app_data[app_idx].app_req[i].data = NULL;
            }
        }

        if (result == WPS_OK)
        {
            ret = J2ME_HTTP_OK;
        }
    }

    kal_trace(TRACE_GROUP_3, FUNC_J2ME_HTTP_UNSET_CHAN, ret);
    return ret;
}

