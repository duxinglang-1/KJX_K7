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
 *   wps_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS external message handler
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _WPS_MSG_C_

#include "stdio.h"

#include "kal_public_api.h"        /* Basic data type */

#include "stack_common.h"
#include "kal_public_defs.h"
#include "stack_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "fat_fs.h"

#include "wps_struct.h"
#include "profile_struct.h"

#include "cbm_api.h"

#include <clib.h>

#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_hdr.h"
#include "msf_core.h"
#include "msf_file.h"
#include "msf_pipe.h"
#include "msf_env.h"
#include "msf_url.h"
#include "msm.h"
#include "stk_if.h"
#ifdef WAP_SEC_SUPPORT
#ifdef STK_CFG_USE_MTK_TLS
#include "tls_api.h"
#include "msf_sock.h"
#endif /* STK_CFG_USE_MTK_TLS*/
#include "sec_awim.h"
#include "sec_if.h"
#include "sec_lib.h"
#include "sec_x509.h"
#include "sec_wtls.h"
#endif /* WAP_SEC_SUPPORT */ 
#include "bam_registry.h"
#include "wapadp.h"
#include "wps_if.h"
#include "wps_main.h"
#include "widget_extension.h"
#include "wap_cmn.h"
#ifdef OPERA_BROWSER
#include "opera_adp_prof.h"
#endif /*OPERA_BROWSER*/
#ifdef __WAP_PUSH_SUPPORT__
extern int pmg_external_msg_hdlr(void *msg);
#endif
#ifdef WPS_TASK_SUPPORT
extern void MSF_wps_fsm(void);
static void wps_clear_req_hdlr(module_type src_mod_id,
                               wps_clear_req_struct *clear_req,
                               wps_clear_req_var_struct *clear_req_var);
void wps_send_clear_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause);
static void wps_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id);
static kal_bool is_wps_ready(void);
#endif 

#ifdef WPS_SUPPORT

#define  WPS_PIPE_PREFIX "wps-crh-pipe"
#define WPS_PRX_PORT_MAX_ASCII_LEN  5


extern int msm_get_module_status(MSF_UINT8 modId);
extern void gmms_HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);


extern const char *bra_prof_accept_header[];

#define WPS_MAX_STATUS_REGISTER_NUM 32
static kal_uint8 wps_ready_status = WPS_READY_STATUS_NULL;
static kal_uint8 wps_status_idx = 0;
static module_type wps_status_register[WPS_MAX_STATUS_REGISTER_NUM];

#define WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN 1800
/************************************************************
 * Global function prototype
 ************************************************************/
#ifdef __IMPS__
void wps_send_imps_ready_ind(void);
#endif 

void wps_send_unset_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_release_all_req_rsp(module_type dst_id, kal_uint8 error_cause);

void wps_send_wps_termination_ind(module_type dst_id);
void wps_send_dl_progress_ind(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 status);

void wps_send_http_rsp(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 error_cause, kal_uint16 request_id);

void wps_send_set_channel_rsp(module_type dst_id, kal_uint32 req_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_reconfig_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void
wps_send_read_content_rsp(
    module_type dst_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_uint16 request_id);

void wps_send_cancel_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause);

void wps_send_post_content_ind(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause, kal_uint8 seq_num);


void wps_send_create_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

static void wps_send_close_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

void wps_send_stream_data_send_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause, kal_uint8 seq_num);

void
wps_send_stream_data_read_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_bool more);

#ifdef WAP_SEC_SUPPORT
void
wps_send_sec_get_session_info_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_session_info_response_t *session_info,
    kal_uint8 error_cause);

void
wps_send_sec_get_current_cert_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_current_cert_response_t *current_cert,
    kal_uint8 error_cause);

#ifdef __HTTP_INTERFACE__
void
wps_send_verify_cert_chain_rsp(
    module_type dst_id,
    sec_verify_cert_chain_response_t *rsp,
    kal_uint8 error_cause);
#endif

static void wps_sec_handle_delete_ca_cert( module_type src_mod_id, wps_sec_delete_ca_cert_req_struct *p);
static void wps_sec_get_x509_ca_cert_req_hdlr(module_type src_mod_id);
extern void wps_sec_show_confirm_dialog_res_hdlr(module_type src_mod_id, wps_show_confirm_dialog_res_struct *res);
extern void wps_send_sec_get_x509_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 error_cause);
extern void wps_send_sec_show_confirm_dialog_ind( MSF_UINT8 request_id, MSF_UINT8 dialog_type,
                                           MSF_UINT8 buttons, MSF_UINT32 title_id,
                                           MSF_UINT32 text_id);
extern void wps_send_delete_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 result);

extern void wps_ses_add_job(wps_ses_job_struct *job);
extern wps_ses_job_struct *wps_ses_create_job(int src);

#endif /* WAP_SEC_SUPPORT */ 

void
wps_send_http_auth_ind(
    module_type dst_id,
    kal_uint8 channel_id,
    kal_uint16 request_id,
    kal_uint8 auth_type,
    kal_uint8 *realm);

void wps_send_status_query_rsp(module_type dst_id, kal_uint8 status);

kal_int32 wps_check_recv_buf_size(wps_req_info_struct *req);

static void wps_http_set_cookie_req_hdlr( module_type src_mod_id,
						wps_set_cookie_req_struct *cookie_info,
						wps_set_cookie_req_var_struct *cookie_var);
unsigned int request_id;

#endif /*WPS_SUPPORT*/


#ifdef WPS_TASK_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  wps_send_ilm
 * DESCRIPTION
 *  this function is to send ILM to other tasks
 * CALLS
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send6(MOD_WPS, dst_id, WPS_APP_SAP, ilm_id, (local_para_struct*) local_para_ptr, (peer_buff_struct*) peer_buff_ptr);
}
#else /* WPS_TASK_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [?]         
 *  peer_buff_ptr       [?]         
 *  ilm_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send6(MOD_WAP, dst_id, WAP_MMI_SAP, ilm_id, (local_para_struct*) local_para_ptr, (peer_buff_struct*) peer_buff_ptr);

}
#endif /* WPS_TASK_SUPPORT */ 


#ifdef WPS_TASK_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  is_wps_ready
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
static kal_bool is_wps_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MSM) == MODULE_STATUS_ACTIVE && 
        msm_get_module_status(MSF_MODID_STK) == MODULE_STATUS_ACTIVE
#ifdef WPS_SUPPORT		
		&& msm_get_module_status(MSF_MODID_WPS) == MODULE_STATUS_ACTIVE
#endif /*WPS_SUPPORT*/		
		)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_clear_req_hdlr(module_type src_mod_id, wps_clear_req_struct *clear_req, wps_clear_req_var_struct *clear_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    int op;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = clear_req->channel_id;

    if (channel_id > WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if ((clear_req->operation == WPS_CLEAR_CACHE_URL_MATCH
         || clear_req->operation == WPS_CLEAR_CACHE_URL_PREFIX)
        && (clear_req_var == NULL || clear_req_var->cache_url_len == 0 || clear_req_var->cache_url == NULL))
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    switch (clear_req->operation)
    {
        case WPS_CLEAR_CACHE_URL_MATCH:
            op = STK_CLEAR_CACHE_URL_MATCH;
            break;
        case WPS_CLEAR_CACHE_URL_PREFIX:
            op = STK_CLEAR_CACHE_URL_PREFIX;
            break;
        case WPS_CLEAR_CACHE_ALL:
            op = STK_CLEAR_CACHE_ALL;
            break;
        case WPS_CLEAR_AUTH_HOST:
            op = STK_CLEAR_AUTH_HOST;
            break;
        case WPS_CLEAR_AUTH_PROXY:
            op = STK_CLEAR_AUTH_PROXY;
            break;
        case WPS_CLEAR_AUTH_ALL:
            op = STK_CLEAR_AUTH_ALL;
            break;
        case WPS_CLEAR_COOKIES_ALL:
            op = STK_CLEAR_COOKIES_ALL;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }
    if(((clear_req_var != NULL) && (clear_req_var->cache_url_len != 0) && (clear_req_var->cache_url != NULL)))
    {
#ifdef WAP_SEC_SUPPORT
        STKif_clear(3, op, (char*)clear_req_var->cache_url);
#else
        STKif_clear(2, op, (char*)clear_req_var->cache_url);
#endif
    }
    else
    {
#ifdef WAP_SEC_SUPPORT
        STKif_clear(3, op, (char*)NULL);
#else
        STKif_clear(2, op, (char*)NULL);
#endif
    }
    error_cause = WPS_OK;

  error:
    wps_send_clear_rsp(src_mod_id, clear_req->request_id, error_cause);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_clear_rsp
 * DESCRIPTION
 *  this function is to response clear request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_clear_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_rsp_struct *clear_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_rsp = (wps_clear_rsp_struct*) construct_local_para(sizeof(wps_clear_rsp_struct), TD_CTRL);
    clear_rsp->request_id = request_id;
    clear_rsp->result = error_cause;

    wps_send_ilm(clear_rsp, NULL, MSG_ID_WPS_CLEAR_RSP, dst_id);
}
#endif /* WPS_TASK_SUPPORT */

#ifdef WPS_SUPPORT
/************************************************************
 * Local function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_search_req_info_by_id
 * DESCRIPTION
 *  this function is used to search request info by request ID.
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wps_req_info_struct *wps_search_req_info_by_id(kal_uint8 channel_id, kal_uint16 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        return NULL;
    }

    for (i = 0; i < WPS_MAX_REQUESTS; i++)
    {
        req_info = chl_info->request_info[i];
        if (req_info != NULL && req_info->request_id == request_id)
        {
            return req_info;
        }
    }

    return NULL;
}



/*****************************************************************************
 * FUNCTION
 *  wps_wap_ready_ind_hdlr
 * DESCRIPTION
 *  this function is to used to handle WAP init. completion indication
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_wap_ready_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(wps_ready_status != WPS_READY_STATUS_OK)
    {
    wps_ready_status = WPS_READY_STATUS_OK;

#ifdef __IMPS__
    wps_send_imps_ready_ind();
#endif 

    /* send ready indication to each ready indication register */
    for (i = 0; i < wps_status_idx; i++)
    {
        wps_send_ilm(NULL, NULL, MSG_ID_WPS_READY_IND, wps_status_register[i]);
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  wps_set_channel_req_hdlr
 * DESCRIPTION
 *  this function is to configure a dedicated channel for HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  set_channel_req         [?]         
 *  set_channel_req_var     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_set_channel_req_hdlr(
    module_type src_mod_id,
    wps_set_channel_req_struct *set_channel_req,
    wps_set_channel_req_var_struct *set_channel_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause;
    kal_int8 channel_id = -1;
    kal_uint8 conn_type;
    kal_uint16 channel_options = 0;
    kal_uint8* prx_addr = NULL;
    kal_uint16 addr_len;
    kal_uint16 prx_port = 0;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_channel_req->use_default == KAL_TRUE)
    {
#ifdef OPERA_BROWSER
	opera_adp_prof_profile_content_struct *prof_cont;
	kal_bool result;
	
       prof_cont = (opera_adp_prof_profile_content_struct*)MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(opera_adp_prof_profile_content_struct));
       if (prof_cont == NULL)
       {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
       }
       result = opera_adp_prof_get_active_profile(&prof_cont);
       if (result != KAL_TRUE)
       {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
       }
       else
       {
            set_channel_req->conn_type = prof_cont->conn_type;
            set_channel_req->net_id = cbm_set_app_id(prof_cont->data_account_primary_id, set_channel_req->app_id);
            memcpy(set_channel_req->prx_addr, prof_cont->proxy_addr, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
            set_channel_req->prx_port = prof_cont->proxy_port;
            set_channel_req->timeout = 30;
            if (prof_cont->conn_type == OPERA_ADP_PROF_CONN_TYPE_HTTP && prof_cont->proxy_addr[0] == 0
                && prof_cont->proxy_addr[1] == 0 && prof_cont->proxy_addr[2] == 0 && prof_cont->proxy_addr[3] == 0)
            {
                set_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                set_channel_req->use_proxy = KAL_TRUE;
            }
	     if (strlen((char*)prof_cont->username) >= OPERA_ADP_PROF_USERNAME_LEN)
            {
                strncpy((char*)set_channel_req->username, (char*)prof_cont->username, OPERA_ADP_PROF_USERNAME_LEN - 1);
                set_channel_req->username[OPERA_ADP_PROF_USERNAME_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->username, (char*)prof_cont->username);
            }
            if (strlen((char*)prof_cont->password) >= OPERA_ADP_PROF_PASSWORD_LEN)
            {
                strncpy((char*)set_channel_req->password, (char*)prof_cont->password, OPERA_ADP_PROF_PASSWORD_LEN - 1);
                set_channel_req->password[OPERA_ADP_PROF_PASSWORD_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->password, (char*)prof_cont->password);
            }
        }
#elif defined(OBIGO_Q03C_BROWSER)
        bam_registry_content_t *prof_cont;
        kal_uint8 result;

        result = bam_registry_load_browser_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            set_channel_req->conn_type = prof_cont->con_type;
            set_channel_req->net_id = cbm_set_app_id(prof_cont->net_id, set_channel_req->app_id);
#ifdef MSF_CFG_WAP_PROF_SUPPORT
            memcpy(set_channel_req->prx_addr, prof_cont->prx_ip, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
#else
            memcpy(set_channel_req->prx_addr, prof_cont->prx_ip, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
#endif
            set_channel_req->prx_port = prof_cont->prx_port;
            set_channel_req->timeout = bam_registry_get_browser_timeout();
#ifdef MSF_CFG_WAP_PROF_SUPPORT
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
#else
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
#endif
            {
                set_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                set_channel_req->use_proxy = KAL_TRUE;
            }

            if (prof_cont->username == NULL)
            {
                set_channel_req->username[0] = '\0';
            }
            else if (strlen(prof_cont->username) >= WPS_MAX_USERNAME_LEN)
            {
                strncpy((char*)set_channel_req->username, prof_cont->username, WPS_MAX_USERNAME_LEN - 1);
                set_channel_req->username[WPS_MAX_USERNAME_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->username, prof_cont->username);
            }

            if (prof_cont->password == NULL)
            {
                set_channel_req->password[0] = '\0';
            }
            else if (strlen(prof_cont->password) >= WPS_MAX_PASSWORD_LEN)
            {
                strncpy((char*)set_channel_req->password, prof_cont->password, WPS_MAX_PASSWORD_LEN - 1);
                set_channel_req->password[WPS_MAX_PASSWORD_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)set_channel_req->password, prof_cont->password);
            }
        }
#else
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
#endif /*OPERA_BROWSER*/        
    }

    /*Check Channel options.*/
    if(set_channel_req->options & WPS_CHANNEL_OPTION_PERSISTENT_CONNECTION)
    {
        channel_options |= STK_CHANNEL_OPTION_USE_PERSISTENT_CONNECTION;
    }

    /* check connection type */
    switch (set_channel_req->conn_type)
    {
        case WPS_CONN_TYPE_HTTP:
        case WPS_CONN_TYPE_WSP_CL:
        case WPS_CONN_TYPE_WSP_CO:
            conn_type = set_channel_req->conn_type;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* convert and check proxy address */
    if (set_channel_req->use_proxy == KAL_TRUE
        || conn_type == WPS_CONN_TYPE_WSP_CL || conn_type == WPS_CONN_TYPE_WSP_CO)
    {
        set_channel_req->use_proxy = KAL_TRUE;
        if (set_channel_req->prx_addr[0] == 0 && set_channel_req->prx_addr[1] == 0
            && set_channel_req->prx_addr[2] == 0 && set_channel_req->prx_addr[3] == 0)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            if (set_channel_req->prx_port == 0)
            {
                switch (conn_type)
                {
                    case WPS_CONN_TYPE_HTTP:
                        prx_port = WPS_DEFAULT_PRX_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CO:
                        prx_port = WPS_DEFAULT_WSP_CO_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CL:
                        prx_port = WPS_DEFAULT_WSP_CL_PORT;
                        break;
                }
            }
            else
            {
                prx_port = set_channel_req->prx_port;
            }
            addr_len = strlen((const char*)set_channel_req->prx_addr)+ WPS_PRX_PORT_MAX_ASCII_LEN + 1;
            prx_addr = (kal_uint8*)MSF_MEM_ALLOC(MSF_MODID_WPS, addr_len);
            sprintf((char*)prx_addr, "%s:%d",set_channel_req->prx_addr,prx_port);
        }
    }

    /* get availabe channel ID */
    channel_id = wps_get_available_channel();
    if (channel_id == -1)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    else
    {
        chl_info = wps_create_channel(channel_id);
        if (chl_info == NULL)
        {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
        }
        chl_info->mod_id = src_mod_id;
        chl_info->conn_type = conn_type;
        chl_info->net_id = set_channel_req->net_id;
        chl_info->timeout = set_channel_req->timeout;
    }

    /* store server auth userame/password */
    if (chl_info->server_auth_username != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_username);
    }
    if(set_channel_req->server_auth_username[0] != '\0')
    {
        chl_info->server_auth_username =
            (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)set_channel_req->server_auth_username);
    }
    else
    {
        chl_info->server_auth_username = NULL;
    }

    if (chl_info->server_auth_password != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_password);
    }
    if(set_channel_req->server_auth_password[0] != '\0')
    {
        chl_info->server_auth_password =
            (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)set_channel_req->server_auth_password);
    }
    else
    {
        chl_info->server_auth_password = NULL;
    }

    /* store static header */
    if (set_channel_req_var != NULL && set_channel_req_var->static_header_len > 0)
    {
        chl_info->static_header = MSF_MEM_ALLOC(MSF_MODID_WPS, set_channel_req_var->static_header_len + 1);
        memcpy(chl_info->static_header, set_channel_req_var->static_header, set_channel_req_var->static_header_len);
        chl_info->static_header[set_channel_req_var->static_header_len] = '\0';
    }
    else
    {
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
    #endif /* 0 */ 
    }

    if (set_channel_req->use_proxy == KAL_TRUE)
    {
        STKif_configureProxyChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            (const char*)prx_addr,
            0,
            (char*)set_channel_req->username,
            (char*)set_channel_req->password,
            NULL,
            channel_options,
            (char*)chl_info->static_header);
    }
    else
    {
        STKif_configureChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            channel_options,
            (char*)chl_info->static_header);
    }

    error_cause = WPS_OK;

    wps_hold_bearer(chl_info->net_id);

  error:
    if(prx_addr)	  
	      MSF_MEM_FREE(MSF_MODID_WPS, prx_addr);    
    /* prepare and send MSG_ID_WPS_SET_CHANNEL_RSP with failure cause */
    wps_send_set_channel_rsp(src_mod_id, set_channel_req->req_id, channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_unset_channel_req_hdlr
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_unset_channel_req_hdlr(module_type src_mod_id, wps_unset_channel_req_struct *unset_channel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_uint8 i; */
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    if (unset_channel_req->channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    /* check channel if exists */
    chl_info = g_wps_cntx.channel_info[unset_channel_req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INACTIVE_CHANNEL;
        goto error;
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
#endif /* 0 */ 


    STKif_removeChannel(MSF_MODID_WPS, unset_channel_req->channel_id + 1);

    wps_clear_channel(unset_channel_req->channel_id);

    error_cause = WPS_OK;

  error:
    /* prepare and send MSG_ID_WPS_UNSET_CHANNEL_RSP with failure cause */
    wps_send_unset_channel_rsp(src_mod_id, unset_channel_req->channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_reconfig_channel_req_hdlr
 * DESCRIPTION
 *  this function is to reconfigure a dedicated channel for HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  set_channel_req         [?]         
 *  set_channel_req_var     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_reconfig_channel_req_hdlr(
    module_type src_mod_id,
    wps_reconfig_channel_req_struct *reconfig_channel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info = NULL;
    kal_uint8 conn_type;
    kal_uint8* prx_addr = NULL;
    kal_uint16 addr_len;
    kal_uint16 prx_port = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    chl_info = g_wps_cntx.channel_info[reconfig_channel_req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if (reconfig_channel_req->use_default == KAL_TRUE)
    {
#ifdef OPERA_BROWSER
	   opera_adp_prof_profile_content_struct *prof_cont;
	   kal_bool result;
	
       prof_cont = (opera_adp_prof_profile_content_struct*)MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(opera_adp_prof_profile_content_struct));
       if (prof_cont == NULL)
       {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
       }
       result = opera_adp_prof_get_active_profile(&prof_cont);
       if (result != KAL_TRUE)
       {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
       }
       else
       {
            reconfig_channel_req->conn_type = prof_cont->conn_type;
            /* If new bearer is different, try to release old one. */
            if (chl_info->net_id != prof_cont->data_account_primary_id)
            {
                wps_release_bearer(chl_info);
            }
            reconfig_channel_req->net_id = prof_cont->data_account_primary_id;
            memcpy(reconfig_channel_req->prx_addr, prof_cont->proxy_addr, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
            reconfig_channel_req->prx_port = prof_cont->proxy_port;
            reconfig_channel_req->timeout = 30;
            if (prof_cont->conn_type == OPERA_ADP_PROF_CONN_TYPE_HTTP && prof_cont->proxy_addr[0] == 0
                && prof_cont->proxy_addr[1] == 0 && prof_cont->proxy_addr[2] == 0 && prof_cont->proxy_addr[3] == 0)
            {
                reconfig_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                reconfig_channel_req->use_proxy = KAL_TRUE;
            }
	        if (strlen((char*)prof_cont->username) >= OPERA_ADP_PROF_USERNAME_LEN)
            {
                strncpy((char*)reconfig_channel_req->username, (char*)prof_cont->username, OPERA_ADP_PROF_USERNAME_LEN - 1);
                reconfig_channel_req->username[OPERA_ADP_PROF_USERNAME_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->username, (char*)prof_cont->username);
            }
            if (strlen((char*)prof_cont->password) >= OPERA_ADP_PROF_PASSWORD_LEN)
            {
                strncpy((char*)reconfig_channel_req->password, (char*)prof_cont->password, OPERA_ADP_PROF_PASSWORD_LEN - 1);
                reconfig_channel_req->password[OPERA_ADP_PROF_PASSWORD_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->password, (char*)prof_cont->password);
            }
        }
#elif defined(OBIGO_Q03C_BROWSER)

        bam_registry_content_t *prof_cont;
        kal_uint8 result;

        result = bam_registry_load_browser_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            reconfig_channel_req->conn_type = prof_cont->con_type;
            /* If new bearer is different, try to release old one. */
            if (chl_info->net_id != prof_cont->net_id)
            {
                wps_release_bearer(chl_info);
            }
            reconfig_channel_req->net_id = prof_cont->net_id;
#ifdef MSF_CFG_WAP_PROF_SUPPORT
            memcpy(reconfig_channel_req->prx_addr, prof_cont->prx_ip, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
#else
            memcpy(reconfig_channel_req->prx_addr, prof_cont->prx_ip, WPS_DOMAIN_NAME_PROXY_ADDR_LEN);
#endif
            reconfig_channel_req->prx_port = prof_cont->prx_port;
            reconfig_channel_req->timeout = bam_registry_get_browser_timeout();
#ifdef MSF_CFG_WAP_PROF_SUPPORT
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
#else
            if (prof_cont->con_type == WPS_CONN_TYPE_HTTP && prof_cont->prx_ip[0] == 0
                && prof_cont->prx_ip[1] == 0 && prof_cont->prx_ip[2] == 0 && prof_cont->prx_ip[3] == 0)
#endif
            {
                reconfig_channel_req->use_proxy = KAL_FALSE;
            }
            else
            {
                reconfig_channel_req->use_proxy = KAL_TRUE;
            }

            if (prof_cont->username == NULL)
            {
                reconfig_channel_req->username[0] = '\0';
            }
            else if (strlen(prof_cont->username) >= WPS_MAX_USERNAME_LEN)
            {
                strncpy((char*)reconfig_channel_req->username, prof_cont->username, WPS_MAX_USERNAME_LEN - 1);
                reconfig_channel_req->username[WPS_MAX_USERNAME_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->username, prof_cont->username);
            }

            if (prof_cont->password == NULL)
            {
                reconfig_channel_req->password[0] = '\0';
            }
            else if (strlen(prof_cont->password) >= WPS_MAX_PASSWORD_LEN)
            {
                strncpy((char*)reconfig_channel_req->password, prof_cont->password, WPS_MAX_PASSWORD_LEN - 1);
                reconfig_channel_req->password[WPS_MAX_PASSWORD_LEN - 1] = '\0';
            }
            else
            {
                strcpy((char*)reconfig_channel_req->password, prof_cont->password);
            }
        }
#else
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;        
#endif /*OPERA_BROWSER*/        
    }

    /* check connection type */
    switch (reconfig_channel_req->conn_type)
    {
        case WPS_CONN_TYPE_HTTP:
        case WPS_CONN_TYPE_WSP_CL:
        case WPS_CONN_TYPE_WSP_CO:
            conn_type = reconfig_channel_req->conn_type;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* convert and check proxy address */
    if (reconfig_channel_req->use_proxy == KAL_TRUE
        || conn_type == WPS_CONN_TYPE_WSP_CL || conn_type == WPS_CONN_TYPE_WSP_CO)
    {
        reconfig_channel_req->use_proxy = KAL_TRUE;
        if (reconfig_channel_req->prx_addr[0] == 0 && reconfig_channel_req->prx_addr[1] == 0
            && reconfig_channel_req->prx_addr[2] == 0 && reconfig_channel_req->prx_addr[3] == 0)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            if (reconfig_channel_req->prx_port == 0)
            {
                switch (conn_type)
                {
                    case WPS_CONN_TYPE_HTTP:
                        prx_port = WPS_DEFAULT_PRX_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CO:
                        prx_port = WPS_DEFAULT_WSP_CO_PORT;
                        break;
                    case WPS_CONN_TYPE_WSP_CL:
                        prx_port = WPS_DEFAULT_WSP_CL_PORT;
                        break;
                }
            }
            else
            {
                prx_port = reconfig_channel_req->prx_port;
            }
            addr_len = strlen((const char*)reconfig_channel_req->prx_addr)+ WPS_PRX_PORT_MAX_ASCII_LEN + 1;
            prx_addr = (kal_uint8*)MSF_MEM_ALLOC(MSF_MODID_WPS, addr_len);
            sprintf((char*)prx_addr, "%s:%d",reconfig_channel_req->prx_addr,prx_port);
        }
    }

    chl_info->mod_id = src_mod_id;
    chl_info->conn_type = conn_type;
    chl_info->net_id = reconfig_channel_req->net_id;
    chl_info->timeout = reconfig_channel_req->timeout;

    STKif_removeChannel (MSF_MODID_WPS, (int)(chl_info->channel_id + 1));

    if (reconfig_channel_req->use_proxy == KAL_TRUE)
    {
        STKif_configureProxyChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            (const char*)prx_addr,
            0,
            (char*)reconfig_channel_req->username,
            (char*)reconfig_channel_req->password,
            NULL,
            0,
            (char*)chl_info->static_header);
    }
    else
    {
        STKif_configureChannel(
            MSF_MODID_WPS,
            (int)(chl_info->channel_id + 1),
            (int)chl_info->conn_type,
            (int)chl_info->net_id,
            (int)(chl_info->timeout * 10),
            0,
            (char*)chl_info->static_header);
    }

    error_cause = WPS_OK;

    wps_hold_bearer(chl_info->net_id);

error:    
    if(prx_addr)
	      MSF_MEM_FREE(MSF_MODID_WPS, prx_addr);    
    /* prepare and send MSG_ID_WPS_SET_CHANNEL_RSP with failure cause */
    wps_send_reconfig_channel_rsp(src_mod_id, chl_info->channel_id, error_cause);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wps_http_release_all_req_hdlr
 * DESCRIPTION
 *  this function is to release all request for a particular WPS user
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  http_req            [?]         
 *  http_req_var        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_http_release_all_req_hdlr(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        if (g_wps_cntx.channel_info[i] != NULL)
        {
            if (g_wps_cntx.channel_info[i]->mod_id == src_mod_id )
            {
                STKif_removeChannel(MSF_MODID_WPS, (int)(g_wps_cntx.channel_info[i]->channel_id + 1));
                wps_clear_channel(i);
                wps_send_release_all_req_rsp(src_mod_id, WPS_OK);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  wps_http_req_hdlr
 * DESCRIPTION
 *  this function is to send a HTTP/WSP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  http_req            [?]         
 *  http_req_var        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_http_req_hdlr(module_type src_mod_id, wps_http_req_struct *http_req, wps_http_req_var_struct *http_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 error_cause = 0;
    kal_uint8 channel_id = 0;
    kal_uint8 request_idx = 0;
    kal_uint8 method;
    int options;
    wps_chl_info_struct *chl_info = NULL;
    wps_req_info_struct *req_info = NULL;
    stk_content_t stkData;
    stk_content_t *stkDataPtr = NULL;
    int numEntries = 0;
    char *pipeName = NULL, *pathName = NULL, *url = NULL;
    int reply_path_len = 0, post_path_len = 0;
    int j;
    kal_bool index_flag = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (http_req_var == NULL)
    {
        /* invalid param */
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    channel_id = http_req->channel_id;

    /* check channel id */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    if (http_req_var->request_url_len == 0 || http_req_var->request_url == NULL)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    if (wps_search_req_info_by_id(channel_id, http_req->request_id) != NULL)
    {
        error_cause = WPS_ERROR_PENDING_REQ_EXIST;
        goto error;
    }

    /* check method */
    method = http_req->method;
    switch (method)
    {
        case WPS_HTTP_METHOD_HEAD:
        case WPS_HTTP_METHOD_GET:
        case WPS_HTTP_METHOD_DELETE:
        case WPS_HTTP_METHOD_UNLOCK:
            break;
        case WPS_HTTP_METHOD_POST:
        case WPS_HTTP_METHOD_PUT:
        case WPS_HTTP_METHOD_PROPFIND:
        case WPS_HTTP_METHOD_PROPPATCH:
        case WPS_HTTP_METHOD_MKCOL:        
        case WPS_HTTP_METHOD_COPY:
        case WPS_HTTP_METHOD_MOVE:
        case WPS_HTTP_METHOD_LOCK:                           
        case WPS_HTTP_METHOD_REPORT:                          
            if (http_req->post_type == WPS_DATA_TYPE_FILE)
            {
                FS_HANDLE fd;

                post_path_len = widget_ucs2_length((kal_uint8*) http_req->post_path);
                if (post_path_len == 0)
                {
                    error_cause = WPS_ERROR_INVALID_PARAM;
                    goto error;
                }
                fd = FS_Open(http_req->post_path, FS_READ_ONLY);
                if (fd < 0)
                {
                    error_cause = WPS_ERROR_INVALID_PARAM;
                    goto error;
                }
                else
                {
                    FS_Close(fd);
                }
            }
            else if ((http_req->post_type != WPS_DATA_TYPE_BUFFER) && (http_req->post_type != WPS_DATA_TYPE_MULTIPART))
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    options = http_req->option;
#ifdef STK_DCMP_USE_ASM_POOL
    options |= STK_OPTION_DO_NOT_ACCEPT_ENCODING;
#endif /*STK_DCMP_USE_ASM_POOL*/
    options |= STK_OPTION_DO_NOT_HANDLE_MULTIPART;

    /* check reply type */
    switch (http_req->reply_type)
    {
        case WPS_DATA_TYPE_FILE:
        case WPS_DATA_TYPE_FILE_NO_PROG_IND:
        case WPS_DATA_TYPE_FILE_RESUME:
        case WPS_DATA_TYPE_FILE_RECREATE:			
            if (http_req->reply_path == NULL)
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            reply_path_len = widget_ucs2_length((kal_uint8*) http_req->reply_path);
            if (reply_path_len == 0)
            {
                error_cause = WPS_ERROR_INVALID_PARAM;
                goto error;
            }
            break;
        case WPS_DATA_TYPE_BUFFER:
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    /* get empty request entry */
    req_info = wps_create_request(channel_id, http_req->request_id);
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    request_idx = req_info->idx;

    if( http_req->option & WPS_HTTP_OPTION_FS_COMMIT)
	{
		req_info->flag |= WPS_FLAG_FILE_FS_COMMIT;
	}
    if( http_req->option & WPS_HTTP_OPTION_USE_PGDL_DOWNLOAD)
	{
		req_info->flag |= WPS_FLAG_PGDL_DL_FILE;
	}

#ifdef WAP_DOWNLOAD_SPEEDUP
    else if(http_req->option & WPS_HTTP_OPTION_USE_LARGE_PIPE)
    {
		req_info->flag |= WPS_FLAG_USE_LARGE_PIPE;
    }
#endif
    /* save method */
    req_info->method = method;

    /* prepare for content posting */
    if (method == STK_METHOD_POST || method == STK_METHOD_PUT || ( method >= STK_METHOD_PROPFIND && method < STK_METHOD_UNLOCK) )
    {
        if (http_req->post_type == WPS_DATA_TYPE_BUFFER && http_req_var->post_segment_len > 0)
        {
            /* create pipe for posting data */
            pipeName = MSF_MEM_ALLOC(MSF_MODID_WPS, strlen("wps-crh-pipe") + 9);
            sprintf(pipeName, "%s%d", WPS_PIPE_PREFIX, req_info->stk_request_id);
            req_info->pipe_handle = MSF_PIPE_CREATE(MSF_MODID_WPS, pipeName);
            if (req_info->pipe_handle < 0)
            {
                error_cause = WPS_ERROR_NO_RESOURCE;
                goto error;
            }

            req_info->post_buff_size = http_req_var->post_segment_len;
            req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->post_buff_size);
            if (req_info->buff == NULL)
            {
                error_cause = WPS_ERROR_NO_RESOURCE;
                goto error;
            }

            memcpy(req_info->buff, http_req_var->post_segment, http_req_var->post_segment_len);
            req_info->buff_pos = 0;
            req_info->more_post = http_req->more_post;

            stkData.contentType = NULL;
            stkData.charset = 0;
            stkData.name = NULL;
            stkData.fileName = NULL;
            stkData.dataType = STK_BODY_PIPE;
            stkData.dataLen = http_req->post_total_len;
            stkData._u.pipeName = pipeName;
            stkDataPtr = &stkData;
            numEntries++;
        }
        else if (http_req->post_type == WPS_DATA_TYPE_FILE && post_path_len > 0)
        {
            int len;

            stkData.contentType = NULL;
            stkData.charset = 0;
            stkData.name = NULL;
            stkData.fileName = NULL;
            stkData.dataType = STK_BODY_FILE;
            stkData.dataLen = http_req->post_total_len;
            len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) http_req->post_path);
            pathName = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, HDI_EXTERNAL_LEN + len + 1);
            sprintf(pathName, "%s", HDI_EXTERNAL_PATH);
            widget_ucs2_to_utf8_string(
                (kal_uint8*) (pathName + HDI_EXTERNAL_LEN),
                len + 1,
                (kal_uint8*) http_req->post_path);
            stkData._u.pathName = pathName;
            stkDataPtr = &stkData;
            numEntries++;
            /* save post path and request header for unauthorized resend */
            req_info->post_path = (kal_wchar*) MSF_MEM_ALLOC(MSF_MODID_WPS, (post_path_len + 1) * 2);
            memcpy(req_info->post_path, http_req->post_path, (post_path_len + 1) * 2);
            req_info->req_header =
                (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_WPS, strlen((char*)(http_req_var->request_header)) + 1);
            strcpy((char*)req_info->req_header, (const char*)http_req_var->request_header);
        }
		else if (http_req->post_type == WPS_DATA_TYPE_MULTIPART && http_req_var->content != NULL)
		{
			int i, len;
			
			req_info->multipart_content = MSF_MEM_ALLOC (MSF_MODID_WPS, http_req_var->num_entries * sizeof (stk_content_t));
            memset(req_info->multipart_content, 0, http_req_var->num_entries * sizeof (stk_content_t));

			req_info->numEntries = http_req_var->num_entries;
			req_info->multipart_pipe_handle  = MSF_MEM_ALLOC (MSF_MODID_WPS, http_req_var->num_entries * sizeof (int));

			for (i = 0; i < http_req_var->num_entries; i++)
			{
				if(http_req_var->content[i].contentTypelen > 0)
                {
				req_info->multipart_content[i].contentType = msf_cmmn_strdup (MSF_MODID_WPS, (const char*)http_req_var->content[i].contentType);
                }

				req_info->multipart_content[i].charset = http_req_var->content[i].charset;
				if(http_req_var->content[i].namelen)
				{
					req_info->multipart_content[i].name = msf_cmmn_strdup (MSF_MODID_WPS, (const char*)http_req_var->content[i].name);
				}

                if(http_req_var->content[i].fileNamelen)
                {
				req_info->multipart_content[i].fileName = msf_cmmn_strdup (MSF_MODID_WPS, (const char*)http_req_var->content[i].fileName);
                }

				if(http_req_var->content[i].dataType == WPS_DATA_TYPE_BUFFER)
				{
					req_info->multipart_content[i].dataType = STK_BODY_PIPE;
					/* create pipe for posting data */
					pipeName = MSF_MEM_ALLOC(MSF_MODID_WPS, strlen("wps-crh-pipe") + 9);
					sprintf(pipeName, "%s%d", WPS_PIPE_PREFIX, ((req_info->stk_request_id * 10)+ i));
					req_info->multipart_pipe_handle[i] = MSF_PIPE_CREATE(MSF_MODID_WPS, pipeName);
					if (req_info->multipart_pipe_handle[i] < 0)
					{
						error_cause = WPS_ERROR_NO_RESOURCE;
						goto error;
					}
			              req_info->multipart_content[i]._u.pathName = msf_cmmn_strdup (MSF_MODID_WPS, pipeName);
				}
				else if(http_req_var->content[i].dataType == WPS_DATA_TYPE_FILE)
				{
					req_info->multipart_content[i].dataType = STK_BODY_FILE;
					len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) http_req_var->content[i].filepathName);
					pathName = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, HDI_EXTERNAL_LEN + len + 1);
					sprintf(pathName, "%s", HDI_EXTERNAL_PATH);
					widget_ucs2_to_utf8_string( (kal_uint8*) (pathName + HDI_EXTERNAL_LEN),
						                         len + 1, (kal_uint8*) http_req_var->content[i].filepathName);
				  
					req_info->multipart_content[i]._u.pathName = msf_cmmn_strdup (MSF_MODID_WPS, pathName);
				}
				req_info->multipart_content[i].dataLen = http_req_var->content[i].dataLen;
			}
			if(http_req_var->request_header != NULL)
			{
                     req_info->req_header = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_WPS, strlen((char*)(http_req_var->request_header)) + 1);
                     strcpy((char*)req_info->req_header, (const char*)http_req_var->request_header);
			}

			req_info->buff_pos = 0;
			req_info->more_post = KAL_TRUE;
        req_info->post_total_len = http_req->post_total_len;
			 req_info->post_buff_size = http_req_var->post_segment_len;
			 numEntries = http_req_var->num_entries;
			 stkDataPtr = req_info->multipart_content;
			 req_info->post_type = WPS_DATA_TYPE_MULTIPART;
    }
    }

    /* prepare for content reply */
    if (http_req->reply_type == WPS_DATA_TYPE_FILE_NO_PROG_IND)
    {
        req_info->flag |= WPS_FLAG_FILE_NO_PROG_IND;
        req_info->reply_type = WPS_DATA_TYPE_FILE;
    }
    else if(http_req->reply_type == WPS_DATA_TYPE_FILE_RESUME)
    {
        req_info->flag |= WPS_FLAG_FILE_RESUME;
	req_info->flag |= WPS_STK_FALG_WAIT_CONFIRM;
        req_info->reply_type = WPS_DATA_TYPE_FILE;
    }
    else if(http_req->reply_type == WPS_DATA_TYPE_FILE_RECREATE)
    {
        req_info->flag |= WPS_FLAG_RECREATE_DL_FILE;
	req_info->flag |= WPS_STK_FALG_WAIT_CONFIRM;
        req_info->reply_type = WPS_DATA_TYPE_FILE;
    }
	
    else
    {
        req_info->reply_type = http_req->reply_type;
    }

    if (req_info->reply_type == WPS_DATA_TYPE_FILE)
    {
        req_info->flag |= WPS_STK_FALG_WAIT_CONFIRM;
        req_info->reply_buff_size = WPS_DEFAULT_READ_BUFF_SIZE;
        req_info->reply_path = (kal_wchar*) MSF_MEM_ALLOC(MSF_MODID_WPS, (reply_path_len + 1) * 2);
        memcpy(req_info->reply_path, http_req->reply_path, (reply_path_len + 1) * 2);
    }
    else
    {
        if (http_req->reply_segment_len == 0)
        {
            req_info->reply_buff_size = req_info->assigned_reply_buff_size = WPS_DEFAULT_READ_BUFF_SIZE;
        }
        else
        {
            req_info->reply_buff_size = req_info->assigned_reply_buff_size = http_req->reply_segment_len;
        }
    }

    url = (char *)MSF_MEM_ALLOC(MSF_MODID_WPS, http_req_var->request_url_len + 1);
    memcpy(url, http_req_var->request_url, http_req_var->request_url_len);
    url[http_req_var->request_url_len] = '\0';

    req_info->url = (kal_uint8*) msf_url_make_complete (MSF_MODID_WPS, url);
	MSF_MEM_FREE(MSF_MODID_WPS, url);

    if(chl_info->server_auth_username && chl_info->server_auth_password)
    {
        /* clear auth info anyway */
        STKif_clear(MSF_MODID_WPS, STK_CLEAR_AUTH_HOST, (const char*)req_info->url);
    }

    if (method == STK_METHOD_POST || method == STK_METHOD_PUT || ( method >= STK_METHOD_PROPFIND && method < STK_METHOD_UNLOCK))
    {
        STKif_httpRequest(
            MSF_MODID_WPS,
            channel_id + 1,
            req_info->stk_request_id,
            (const char*)req_info->url,
            method,
            options,
            (char*)http_req_var->request_header,
            NULL,
            0,
            numEntries,
            stkDataPtr);
        if (http_req->post_type == WPS_DATA_TYPE_BUFFER && numEntries > 0)
        {
            req_info->state = WPS_REQ_POSTING;
            wps_write_post_content(req_info);
        }
		else if(http_req->post_type == WPS_DATA_TYPE_MULTIPART && numEntries > 0)
		{
		    for(j=0; j < req_info->numEntries; j++)
	        {
		           	  if(req_info->multipart_content[j].dataType == STK_BODY_PIPE)
	           	  {
	                    req_info->state = WPS_REQ_POSTING;
						index_flag = KAL_TRUE;
						req_info->seq_num++;
						req_info->pipe_handle = req_info->multipart_pipe_handle[j];
						/*send post content indication to application*/
                        wps_send_post_content_ind(chl_info->mod_id, req_info->request_id, WPS_OK, req_info->seq_num);
			            break;
	           	  }
		    }
			req_info->currNumEntry = j;
			if(index_flag == KAL_FALSE)
			{
				req_info->state = WPS_REQ_WAIT_RSP;
			}
		}
        else
        {
            req_info->state = WPS_REQ_WAIT_RSP;
        }
    }
    else
    {
        STKif_httpRequest(
            MSF_MODID_WPS,
            channel_id + 1,
            req_info->stk_request_id,
            (const char*)req_info->url,
            method,
            options,
            (char*)http_req_var->request_header,
            NULL,
            0,
            0,
            NULL);
        req_info->state = WPS_REQ_WAIT_RSP;
    }

  error:
    MSF_MEM_FREE(MSF_MODID_WPS, pipeName);
    MSF_MEM_FREE(MSF_MODID_WPS, pathName);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        wps_send_http_rsp(src_mod_id, NULL, error_cause, http_req->request_id);
        if (req_info)
        {
            wps_clear_request(channel_id, request_idx);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_read_content_req_hdlr
 * DESCRIPTION
 *  this function is to continue to read HTTP/WSP reply content.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  read_content_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_read_content_req_hdlr(module_type src_mod_id, wps_read_content_req_struct *read_content_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = read_content_req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, read_content_req->request_id);
    if (req_info == NULL || req_info->state != WPS_REQ_RSP_SENT)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    request_idx = req_info->idx;

    if (read_content_req->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (read_content_req->read_segnemtn_len > 0)
    {
        if(read_content_req->read_segnemtn_len >= 1900)
			req_info->reply_buff_size = 1900;
		else
        req_info->reply_buff_size = read_content_req->read_segnemtn_len;
    }
	else
	{
		req_info->reply_buff_size = req_info->assigned_reply_buff_size;

	}
    
    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        /* send back response and delete content */
        wps_send_read_content_rsp(src_mod_id, req_info, WPS_ERROR_NO_RESOURCE, req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

    req_info->state = WPS_REQ_WAIT_CONTENT;
    wps_read_reply_content(req_info);
    return;

  error:
    wps_send_read_content_rsp(src_mod_id, req_info, error_cause, read_content_req->request_id);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_post_content_res_hdlr
 * DESCRIPTION
 *  this function is to to handle continuous content post of a HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  post_content_res            [?]         
 *  post_content_res_var        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_post_content_res_hdlr(
    module_type src_mod_id,
    wps_post_content_res_struct *post_content_res,
    wps_post_content_res_var_struct *post_content_res_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = post_content_res->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, post_content_res->request_id);
    if (req_info == NULL || req_info->state != WPS_REQ_POSTING)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }

    if (post_content_res->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    if (post_content_res_var == NULL || post_content_res_var->post_segment_len == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    req_info->post_buff_size = post_content_res_var->post_segment_len;

    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->post_buff_size);
    if (req_info->buff == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    memcpy(req_info->buff, post_content_res_var->post_segment, post_content_res_var->post_segment_len);
    req_info->buff_pos = 0;
    req_info->more_post = post_content_res->more;
    wps_write_post_content(req_info);
    return;

  error:
    /* send back post indication with error code */
    if (req_info == NULL)
    {
        wps_send_post_content_ind(src_mod_id, post_content_res->request_id, error_cause, 0);
    }
    else
    {
        wps_send_post_content_ind(src_mod_id, req_info->request_id, error_cause, 0);
        /* abort HTTP/WSP request */
        if (req_info->state == WPS_REQ_POSTING)
        {
            STKif_cancelRequest(MSF_MODID_WPS, req_info->stk_request_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_cancel_req_hdlr
 * DESCRIPTION
 *  this function is to cancel an incomplete WSP/HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  cancel_req      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_cancel_req_hdlr(module_type src_mod_id, wps_cancel_req_struct *cancel_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = cancel_req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, cancel_req->request_id);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    request_idx = req_info->idx;

    switch (req_info->state)
    {
        case WPS_REQ_CANCELING:
            error_cause = WPS_ERROR_PENDING_REQ_EXIST;
            goto error;
        case WPS_REQ_POSTING:
            /* post request */
            MSF_PIPE_CLOSE(req_info->pipe_handle);
            req_info->pipe_handle = -1;
            wps_clear_request_buff(req_info);
        case WPS_REQ_WAIT_RSP:
            STKif_cancelRequest(MSF_MODID_WPS, req_info->stk_request_id);
            req_info->state = WPS_REQ_CANCELING;
            break;
        case WPS_REQ_RSP_SENT:
        case WPS_REQ_WAIT_CONTENT:
            wps_send_cancel_rsp(src_mod_id, req_info->request_id, WPS_OK);
            wps_clear_request(channel_id, request_idx);
            break;
    }

    return;

  error:
    wps_send_cancel_rsp(src_mod_id, cancel_req->request_id, error_cause);
}


/*****************************************************************************
 * FUNCTION
 *  wps_create_stream_connection_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_create_stream_connection_req_hdlr(module_type src_mod_id, wps_create_stream_connection_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;
    kal_uint8 error_cause;
    kal_uint8 conn_type;
    int channel_id = -1;
    msf_sockaddr_t addr;
    char sendPipeName[23];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req->use_default == KAL_TRUE)
    {
#ifdef OPERA_BROWSER
	opera_adp_prof_profile_content_struct *prof_cont;
	kal_bool result;
	
       prof_cont = (opera_adp_prof_profile_content_struct*)MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(opera_adp_prof_profile_content_struct));
       if (prof_cont == NULL)
       {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
       }
       result = opera_adp_prof_get_active_profile(&prof_cont);
       if (result != KAL_TRUE)
       {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
       }
       else
       {
            /* req->conn_type = prof_cont->con_type; */
            req->net_id = prof_cont->data_account_primary_id;       
     	}
#elif defined(OBIGO_Q03C_BROWSER)
        bam_registry_content_t *prof_cont;
        kal_uint8 result;

        result= bam_registry_load_browser_active_profile(&prof_cont);
        if (result != WAP_PROF_SUCCESS)
        {
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
        }
        else
        {
            /* req->conn_type = prof_cont->con_type; */
            req->net_id = prof_cont->net_id;
        }
#else
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
#endif /*OPERA_BROWSER*/       
    }

    /* check connection type */
    switch (req->conn_type)
    {
        case WPS_CONN_TYPE_TLS:
            conn_type = STK_CONNECTION_TYPE_TLS;
            break;
        default:
            error_cause = WPS_ERROR_INVALID_PARAM;
            goto error;
    }

    if (req->addr[0] == 0 && req->addr[1] == 0 && req->addr[2] == 0 && req->addr[3] == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }
    else
    {
        addr.addrLen = 4;
        memcpy(addr.addr, req->addr, 4);
        addr.port = req->port;
    }


    /* get availabe channel ID */
    channel_id = wps_get_available_channel();
    if (channel_id == -1)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }
    else
    {
        chl_info = wps_create_channel((kal_uint8)channel_id);
        if (chl_info == NULL)
        {
            error_cause = WPS_ERROR_NO_RESOURCE;
            goto error;
        }
        chl_info->mod_id = src_mod_id;
        chl_info->conn_type = conn_type;
        chl_info->net_id = req->net_id;
    }

    /* get empty request entry */
    req_info = wps_create_request((kal_uint8)channel_id, 0);
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    sprintf(sendPipeName, "%s%d", WPS_PIPE_PREFIX, req_info->stk_request_id);
    req_info->send_pipe_handle = MSF_PIPE_CREATE(MSF_MODID_WPS, sendPipeName);
    if (req_info->send_pipe_handle < 0)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    req_info->state = WPS_REQ_CONNECTING;
    STKif_createStreamConnection (MSF_MODID_WPS, channel_id + 1, addr, conn_type,
        chl_info->net_id, sendPipeName, req->domain);

    wps_hold_bearer(chl_info->net_id);

    return;

error:
    /* prepare and send MSG_ID_WPS_CREATE_STREAM_RSP with failure cause */
    wps_send_create_stream_connection_rsp(src_mod_id, (kal_uint8)channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_close_stream_connection_req_hdlr(module_type src_mod_id, wps_close_stream_connection_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_uint8 i; */
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check channel id */
    if (req->channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    /* check channel if exists */
    chl_info = g_wps_cntx.channel_info[req->channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INACTIVE_CHANNEL;
        goto error;
    }

    STKif_closeConnection(MSF_MODID_WPS, req->channel_id + 1);

    wps_clear_request(req->channel_id, 0);
    wps_clear_channel(req->channel_id);

    error_cause = WPS_OK;

error:
   
    /* prepare and send MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP with failure cause */
    wps_send_close_stream_connection_rsp(src_mod_id, req->channel_id, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_data_send_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_stream_data_send_req_hdlr(
    module_type src_mod_id,
    wps_stream_data_send_req_struct *req,
    wps_stream_data_send_req_var_struct *send_req_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS || !g_wps_cntx.channel_info[channel_id])
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    req_info = g_wps_cntx.channel_info[channel_id]->request_info[0];
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }
    
    if (req->seq_num != req_info->send_seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (send_req_var == NULL || send_req_var->length == 0)
    {
        error_cause = WPS_ERROR_INVALID_PARAM;
        goto error;
    }

    req_info->send_buff_size = send_req_var->length;

    req_info->send_buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->send_buff_size);
    if (req_info->send_buff == NULL)
    {
        error_cause = WPS_ERROR_NO_RESOURCE;
        goto error;
    }

    memcpy(req_info->send_buff, send_req_var->data, send_req_var->length);
    req_info->send_buff_pos = 0;
    req_info->send_buff_size = send_req_var->length;
    req_info->send_seq_num = req->seq_num + 1;
    wps_write_to_sink(req_info);
    return;

error:
    wps_send_stream_data_send_rsp(src_mod_id, channel_id, error_cause, req->seq_num);

}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_data_read_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_stream_data_read_req_hdlr(module_type src_mod_id, wps_stream_data_read_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS || !g_wps_cntx.channel_info[channel_id])
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];

    req_info = chl_info->request_info[0];
    if (req_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_REQUEST_ID;
        goto error;
    }

    if (req->seq_num != req_info->seq_num)
    {
        error_cause = WPS_ERROR_INVALID_SEQUENCE_NUM;
        goto error;
    }

    if (req->read_length > 0)
    {
        req_info->reply_buff_size = req->read_length;
    }

    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        /* send back response and delete content */
        wps_send_stream_data_read_rsp(src_mod_id, channel_id, req_info, WPS_ERROR_NO_RESOURCE, KAL_FALSE);
        wps_clear_request(channel_id, 0);
        return;
    }

    req_info->seq_num = req->seq_num + 1;
    wps_read_reply_content(req_info);
    return;

error:
    wps_send_stream_data_read_rsp(src_mod_id, channel_id, req_info, error_cause, KAL_FALSE);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_req_hdlr
 * DESCRIPTION
 *  this function is to clear sharing information about HTTP.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 *  clear_req           [?]         
 *  clear_req_var       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_dl_progress_res_hdlr(module_type src_mod_id, wps_dl_progress_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info = NULL;
    int isOpen;
    long available;
	kal_uint32 reply_path_len = 0;
    kal_uint32 bytes_write = 0;
    kal_uint32 fileSize =0;
kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = res->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        return;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        return;
    }
    req_info = wps_search_req_info_by_id(channel_id, res->request_id);
    if (req_info == NULL || req_info->state == WPS_REQ_NULL)
    {
        return;
    }

    if((req_info->reply_type == WPS_DATA_TYPE_FILE) && (req_info->flag & WPS_FLAG_RECREATE_DL_FILE))
    {

		if (res->reply_path == NULL)
		{
			req_info->last_error = WPS_ERROR_INVALID_PARAM;
        	wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);	
        	wps_clear_request(req_info->channel_id, req_info->idx);		
        	return;
		}
		reply_path_len = widget_ucs2_length((kal_uint8*) res->reply_path);
		if (reply_path_len == 0)
		{
			req_info->last_error = WPS_ERROR_INVALID_PARAM;
        	wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);
        	wps_clear_request(req_info->channel_id, req_info->idx);
       	 	return;
		}
		if(req_info->reply_path != NULL)
			MSF_MEM_FREE (MSF_MODID_WPS, req_info->reply_path);
		
		req_info->reply_path = (kal_wchar*) MSF_MEM_ALLOC(MSF_MODID_WPS, (reply_path_len + 1) * 2);
		memcpy(req_info->reply_path, res->reply_path, (reply_path_len + 1) * 2);
	    req_info->flag &= ~WPS_FLAG_RECREATE_DL_FILE;
    }

    if(req_info->flag & WPS_FLAG_ENABLE_PGDL_DL)
    {
        /*Overwrite first 512 byes into File*/
	if((req_info->reply_type == WPS_DATA_TYPE_FILE) && (req_info->file_handle > 0))
	{
		ret= FS_Seek(req_info->file_handle, 0, FS_FILE_BEGIN);
	    if (ret >= 0)
	    {
		    FS_Write(req_info->file_handle, res->dl_buff, res->dl_buff_len, (U32*) & bytes_write);
	    }
	    else
	    {
		req_info->last_error = WPS_ERROR_FILE_ACCESS;
		wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);	
		wps_clear_request(req_info->channel_id, req_info->idx); 	
		return;
	    }
    	FS_GetFileSize(req_info->file_handle, &fileSize);			
		ret = FS_Seek(req_info->file_handle, fileSize, FS_FILE_BEGIN);
	    if ( ret < 0)
	    {
		req_info->last_error = WPS_ERROR_FILE_ACCESS;
		wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);	
		wps_clear_request(req_info->channel_id, req_info->idx); 	
		return;
	    }
	}
        req_info->flag &= ~WPS_FLAG_ENABLE_PGDL_DL;		
    }
    
    if ((req_info->flag & WPS_FLAG_PGDL_DL_FILE))
    {
	req_info->flag	|= WPS_FLAG_ENABLE_PGDL_DL;
        req_info->flag &= ~WPS_FLAG_PGDL_DL_FILE;		
    }
    req_info->ind_sent = 0;

    MSF_PIPE_STATUS(req_info->pipe_handle, &isOpen, &available);
    if(available)
    {
        wps_read_reply_content(req_info);
    }
	else
	{
		MSF_PIPE_POLL(req_info->pipe_handle);
	}

    return;
}


#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_ses_create_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src                 [IN]        
 *  screen_id(?)        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
wps_ses_job_struct *wps_ses_create_job(int src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = MSF_MEM_ALLOCTYPE(MSF_MODID_WPS, wps_ses_job_struct);
    job->request_id = ++request_id;
    job->src = src;
    job->next = NULL;
    return job;
}


/*****************************************************************************
 * FUNCTION
 *  wps_ses_add_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void wps_ses_add_job(wps_ses_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wps_cntx.wps_ses_queued_requests == NULL)
    {
        g_wps_cntx.wps_ses_queued_requests = job;
    }
    else
    {
        g_wps_cntx.wps_ses_queued_requests->next = job;
    }
}

#ifdef STK_CFG_USE_MTK_TLS
/* function to map tls enumerations and constants to old wps enumerations and constants */

kal_int32 wps_get_keyexch_algo(kal_int32 algo)
{
    switch(algo)
	{
		case TLS_KEY_ALGO_UNKNOWN:
			return WPS_SEC_TLS_KEYEXCH_NULL;
        case TLS_KEY_ALGO_RSA:                  /* RSA */
            return WPS_SEC_TLS_KEYEXCH_RSA;
		case TLS_KEY_ALGO_RSA_EXPORT:          /* RSA_EXPORT */
            return WPS_SEC_TLS_KEYEXCH_RSA_EXPORT;
	    case TLS_KEY_ALGO_DH:                  /* DH */
            return WPS_SEC_TLS_KEYEXCH_DH_DSS;
		case TLS_KEY_ALGO_DH_EXPORT:           /* DH_EXPORT */
            return WPS_SEC_TLS_KEYEXCH_DH_DSS_EXPORT;
		case TLS_KEY_ALGO_DHE:                 /* DH */
            return WPS_SEC_TLS_KEYEXCH_DHE_RSA;
		case TLS_KEY_ALGO_DHE_EXPORT:          /* DH_EXPORT */
			return WPS_SEC_TLS_KEYEXCH_DHE_RSA_EXPORT;
        case TLS_KEY_ALGO_ECDH:                /* ECDH */
		case TLS_KEY_ALGO_ECDHE:               /* ECDHE */
		case TLS_KEY_ALGO_ECMQV:               /* ECMQV */
		case TLS_KEY_ALGO_DSA:                 /* DSA */
		case TLS_KEY_ALGO_PSK:                 /* PSK */
		case TLS_KEY_ALGO_DHE_PSK:             /* DHE_PSK */
		case TLS_KEY_ALGO_RSA_PSK:             /* RSA_PSK */
		case TLS_KEY_ALGO_MAX:
		default:
			return WPS_SEC_TLS_KEYEXCH_NULL;
	}
}

kal_int32 wps_get_cipher_algo(kal_int32 algo)
{
	switch(algo)
	{
		case TLS_ENC_ALGO_UNKNOWN:
        case TLS_ENC_ALGO_NULL:
            return SEC_CIPHER_NULL;
		case TLS_ENC_ALGO_DES_40:
			return SEC_CIPHER_DES_CBC_40;
        case TLS_ENC_ALGO_DES:
			return SEC_CIPHER_DES_CBC;
		case TLS_ENC_ALGO_3DES:
            return SEC_CIPHER_3DES_CBC_EDE;
		case TLS_ENC_ALGO_RC5:
            return SEC_CIPHER_RC5_CBC;
		case TLS_ENC_ALGO_RC5_56:
			return SEC_CIPHER_RC5_CBC_56;
		case TLS_ENC_ALGO_AES_128:
            return SEC_CIPHER_AES_CBC_128;
		case TLS_ENC_ALGO_AES_192:
			return SEC_CIPHER_NULL;
		case TLS_ENC_ALGO_AES_256:
            return SEC_CIPHER_NULL;
		case TLS_ENC_ALGO_ARC4_40:
			return SEC_CIPHER_RC4_40;
		case TLS_ENC_ALGO_ARC4_56:
			return SEC_CIPHER_NULL;
		case TLS_ENC_ALGO_ARC4_128:
            return WPS_SEC_CIPHER_RC4_128;
		case TLS_ENC_ALGO_ARC2_40:
            return SEC_CIPHER_RC2_CBC_40;
		case TLS_ENC_ALGO_ARC2_56:
        case TLS_ENC_ALGO_ARC2_64:
		case TLS_ENC_ALGO_ARC2_128:
		default:
            return SEC_CIPHER_NULL;
	}
}

kal_int32 wps_get_hash_algo(kal_int32 algo)
{
	switch(algo)
	{
		case TLS_HASH_MD5:
            return WPS_SEC_HASH_MD5;			
        case TLS_HASH_SHA1:
		case TLS_HASH_SHA224:
		case TLS_HASH_SHA256:
		case TLS_HASH_SHA384:
		case TLS_HASH_SHA512:
		    return WPS_SEC_HASH_SHA;
        case TLS_HASH_MD2:
		    return WPS_SEC_HASH_MD2;			
		case TLS_HASH_MD4:
        case TLS_HASH_UNKNOWN:
		default:
			return WPS_SEC_HASH_NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_session_info
 * DESCRIPTION
 *  this function is to get current security session information.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_session_info_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_sec_get_session_info( wps_chl_info_struct *chl_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error;
    tls_cipher_info_struct cipher_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	error = tls_get_cipher_info((const kal_int8)chl_info->security_id, 
                                &cipher_info);
	if (error == TLS_ERR_NONE)
	{
		/* this is an assumption */
		if (cipher_info.version == TLSv1)
		{
                  chl_info->session_info.sec_conn_type = SEC_CONNECTION_TYPE_TLS;
		}
		else
		{
		    chl_info->session_info.sec_conn_type = SEC_CONNECTION_TYPE_SSL;
		}

              chl_info->session_info.blk_encrypt_alg = wps_get_cipher_algo(cipher_info.enc);
		chl_info->session_info.hash_alg = wps_get_hash_algo(cipher_info.hash);
		chl_info->session_info.key_exchange_alg = wps_get_keyexch_algo(cipher_info.key_ex);
	}
	
}

/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_current_cert
 * DESCRIPTION
 *  this function is to get current certificate used in security session.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_sec_get_current_cert(wps_chl_info_struct *chl_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_int32 error;
	tls_cert_struct cert;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       error = tls_get_peer_cert(chl_info->socket_id, &cert);
	if (error == TLS_ERR_NONE)
	{
		if(chl_info->cert_info.cert)
		{
			MSF_MEM_FREE(MSF_MODID_WPS, chl_info->cert_info.cert);	
 		       chl_info->cert_info.cert = NULL;
		}

	    chl_info->cert_info.certLen = cert.len;
	    chl_info->cert_info.format = SEC_CERT_FORMAT_X509;

           chl_info->cert_info.cert = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_WPS, cert.len);
	    memcpy(chl_info->cert_info.cert, cert.data, cert.len);
	}
}
#endif /* STK_CFG_USE_MTK_TLS */
/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_session_info_req_hdlr
 * DESCRIPTION
 *  this function is to get current security session information.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_session_info_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_session_info_req_hdlr(module_type src_mod_id, wps_sec_get_session_info_req_struct *get_session_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;
#ifdef STK_CFG_USE_MTK_TLS
	sec_get_session_info_response_t session_info;
#endif /* STK_CFG_USE_MTK_TLS */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = get_session_info_req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }
    
    if (chl_info->security_id < 0)
    {
    	error_cause = WPS_ERROR_NOT_FOUND;
    	goto error;
    }    	
#ifdef STK_CFG_USE_MTK_TLS
	session_info.connectionType =   chl_info->session_info.sec_conn_type;
  	session_info.encrAlg =	 chl_info->session_info.blk_encrypt_alg;
	session_info.hMacAlg =   chl_info->session_info.hash_alg;
	session_info.keyExchangeAlgorithm =   chl_info->session_info.key_exchange_alg;	   
  	wps_send_sec_get_session_info_rsp(src_mod_id, channel_id, &session_info, WPS_OK);		
#else
    SECif_getSessionInfo(MSF_MODID_WPS, channel_id, chl_info->security_id);
#endif /* STK_CFG_USE_MTK_TLS */
    return;

  error:
    wps_send_sec_get_session_info_rsp(src_mod_id, channel_id, NULL, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_current_cert_req_hdlr
 * DESCRIPTION
 *  this function is to get current certificate used in security session.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_current_cert_req_hdlr(module_type src_mod_id, wps_sec_get_current_cert_req_struct *get_current_cert_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    kal_uint8 error_cause;
    wps_chl_info_struct *chl_info;

#ifdef STK_CFG_USE_MTK_TLS
    sec_get_current_cert_response_t current_cert;
#endif /* STK_CFG_USE_MTK_TLS */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = get_current_cert_req->channel_id;

    if (channel_id >= WPS_MAX_CHANNELS)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        error_cause = WPS_ERROR_INVALID_CHANNEL_ID;
        goto error;
    }
    
    if (chl_info->security_id < 0)
    {
    	error_cause = WPS_ERROR_NOT_FOUND;
    	goto error;
    }    	

#ifdef STK_CFG_USE_MTK_TLS
	current_cert.cert = chl_info->cert_info.cert;
	current_cert.certLen = chl_info->cert_info.certLen;
	current_cert.format = chl_info->cert_info.format;
	current_cert.result = WPS_OK;

        /* remove parser from this function definition */
        wps_send_sec_get_current_cert_rsp(src_mod_id, channel_id, &current_cert, WPS_OK);

#else
    SECif_getCurrentCert(MSF_MODID_WPS, channel_id, chl_info->security_id);
#endif /* STK_CFG_USE_MTL_TLS */
    return;

  error:
    wps_send_sec_get_current_cert_rsp(src_mod_id, channel_id, NULL, error_cause);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_cert_ids_req_hdlr
 * DESCRIPTION
 *  this function is to get all X.509 CA certificates stored in this device
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_get_cert_ids_req_hdlr(module_type src_mod_id, wps_sec_get_cert_ids_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);
    
    SECif_getCertIds(MSF_MODID_WPS, job->request_id, p->cert_options);
}


/*****************************************************************************
 * FUNCTION
 *  wps_ses_handle_get_cert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_sec_get_cert_req_hdlr(module_type src_mod_id, wps_sec_get_cert_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    SECif_getCert(MSF_MODID_WPS, job->request_id, p->cert_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_handle_delete_ca_cert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_sec_handle_delete_ca_cert(module_type src_mod_id, wps_sec_delete_ca_cert_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    SECif_deleteCert(MSF_MODID_WPS, job->request_id, p->idx);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_delete_ca_cert_rsp
 * DESCRIPTION
 *  this function is to send the HTTP/WSP reply content downloading status indication to the callee.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  result          [IN]        
 *  status(?)       [IN]        
 *  req_info        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_delete_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_delete_ca_cert_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (wps_sec_delete_ca_cert_rsp_struct*) construct_local_para(sizeof(wps_sec_delete_ca_cert_rsp_struct), TD_RESET);
    rsp->result = result;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP, (module_type)dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_x509_ca_cert_req_hdlr
 * DESCRIPTION
 *  this function is to get all X.509 CA certificates stored in this device
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  get_current_cert_req        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_sec_get_x509_ca_cert_req_hdlr(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    SECif_getCertIds(MSF_MODID_WPS, job->request_id, SEC_GET_ROOT_CERT);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_x509_ca_cert_rsp
 * DESCRIPTION
 *  this function is to send the response of getting x509 ca certificate request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  total               [IN]        
 *  channel_id(?)       [IN]        
 *  error_cause(?)      [IN]        
 *  current_cert        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_sec_get_x509_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_x509_ca_cert_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (wps_sec_get_x509_ca_cert_rsp_struct*) construct_local_para(
                                                sizeof(wps_sec_get_x509_ca_cert_rsp_struct),
                                                TD_RESET);

    rsp->total = total;
    rsp->result = error_cause;
    wps_send_ilm(rsp, NULL, MSG_ID_WPS_SEC_GET_X509_CA_CERT_RSP, (module_type)dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_show_confirm_dialog_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request_id      [IN]        
 *  dialog_type     [IN]        
 *  buttons         [IN]        
 *  title_id        [IN]        
 *  text_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_show_confirm_dialog_ind(
    MSF_UINT8 request_id,
    MSF_UINT8 dialog_type,
    MSF_UINT8 buttons,
    MSF_UINT32 title_id,
    MSF_UINT32 text_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_show_confirm_dialog_ind_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_show_confirm_dialog_ind_struct*) construct_local_para(
                                                sizeof(wps_show_confirm_dialog_ind_struct),
                                                TD_RESET);

    p->request_id = request_id;
    p->dialog_type = dialog_type;
    p->buttons = buttons;
    p->title_id = title_id;
    p->text_id = text_id;

    wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_IND, MOD_MMI);
}

#ifdef __HTTP_INTERFACE__
/*****************************************************************************
 * FUNCTION
 *  wps_sec_verify_cert_chain_req_hdlr
 * DESCRIPTION
 *  this function is to get all X.509 CA certificates stored in this device
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id                  [IN]        
 *  get_current_cert_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void
wps_sec_verify_cert_chain_req_hdlr(module_type src_mod_id, wps_sec_verify_cert_chain_req_struct *verify_cert_chain_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sec_tls_asn1_certificate *certs;
    wps_sec_certificate_struct *wps_cert = NULL;
    wps_ses_job_struct *job;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!verify_cert_chain_req->cert_num)
    {
        wps_send_verify_cert_chain_rsp(src_mod_id, NULL, WPS_SEC_ERR_INVALID_PARAMETER);
        return;
    }    
    
    job = wps_ses_create_job(src_mod_id);
    wps_ses_add_job(job);

    certs = MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(sec_tls_asn1_certificate) * verify_cert_chain_req->cert_num);
    
    for(i = 0; i < verify_cert_chain_req->cert_num; i++)
    {
        wps_cert = &verify_cert_chain_req->certs[i];
        certs[i].format = wps_cert->format;
        certs[i].certLen = wps_cert->cert_len;
        certs[i].cert = wps_cert->cert;
    }
            
    SECif_verifyCertChain(MSF_MODID_WPS, job->request_id, certs, verify_cert_chain_req->cert_num);

    MSF_MEM_FREE(MSF_MODID_WPS, certs);
    return;
}
#endif/*__HTTP_INTERFACE__*/
#endif /* WAP_SEC_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_http_add_auth_info_req_hdlr
 * DESCRIPTION
 *  this function is to handle the username/password response for HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  auth_res        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_add_auth_info_req_hdlr( module_type src_mod_id,
						wps_http_auth_info_struct *auth_info,
						wps_http_auth_info_var_struct *http_auth_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *username = NULL;
    kal_uint8 *password = NULL;
    kal_uint8  *url = NULL;                  
    kal_uint8  *realm = NULL;
    kal_uint8  *nonce= NULL;  
    kal_uint8  *opaque= NULL;
    kal_uint8  *algorithm= NULL;
    kal_uint8  *qop= NULL;
	kal_uint8  proxy_auth = KAL_FALSE;
    kal_uint8* prx_addr = NULL;
    kal_uint16 addr_len;
    kal_uint16 prx_port = 0;
	MSF_UINT32 netAccId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth_info == NULL || http_auth_var == NULL)
    {
		/* No Need to add authentication information*/
		return;
    }
	
	/*Incase of Server authentication, URL should not be NULL */
	if((auth_info->auth_option == WPS_HTTP_AUTH_SERVER)  &&
	   ((http_auth_var->url == NULL) || (http_auth_var->url_len == 0)))	
	{
		return;
	}
	
	/*Is Proxy authentication */
	if(auth_info->auth_option == WPS_HTTP_AUTH_PROXY ) 	
	{	
		/*Add proxy information*/
        if (auth_info->prx_addr[0] == 0 && auth_info->prx_addr[1] == 0
            && auth_info->prx_addr[2] == 0 && auth_info->prx_addr[3] == 0)
        {
			return;
        }
        else
        {
			proxy_auth = KAL_TRUE;
            prx_port = auth_info->port;
            addr_len = strlen((const char*)auth_info->prx_addr)+ WPS_PRX_PORT_MAX_ASCII_LEN + 1;
            prx_addr = (kal_uint8*)MSF_MEM_ALLOC(MSF_MODID_WPS, addr_len);
            sprintf((char*)prx_addr, "%s:%d",auth_info->prx_addr,prx_port);
        }
	}
    /* store the username & password */
    if (http_auth_var->username != NULL)
    {
		username = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->username);
    }
    if (http_auth_var->password != NULL)
    {
		password = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->password);
    }
    if (http_auth_var->realm != NULL)
    {
		realm = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->realm);
    }
	if (http_auth_var->url != NULL)
    {
		url = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->url);
    }

	/*Is authentication type digest*/
	if (auth_info->auth_type == WPS_HTTP_AUTH_TYPE_DIGEST)
	{
		/* store the username & password */
		if (http_auth_var->nonce != NULL )
		{
			nonce = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->nonce);
		}
		if (http_auth_var->opaque != NULL)
		{
			opaque = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->opaque);
		}
		if (http_auth_var->algorithm != NULL)
		{
			algorithm = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->algorithm);
		}
		if (http_auth_var->qop != NULL)
		{
			qop = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)http_auth_var->qop);
		}
	}

    STKif_storeAuthInfo(	MSF_MODID_WPS, 	/*Requesting MSF module id*/
							auth_info->auth_type, 	/*STK_AUTH_TYPE_BASIC or STK_AUTH_TYPE_DIGEST*/
							proxy_auth, 	/*TRUE if proxy authorization, else FALSE*/
							(const char*)url, 	/*Must if no proxy*/
							(const char*)prx_addr, /*Must if proxy*/
							(char*)realm,	/*Must, returned by server*/
							(char*)username, 	/*entered by user*/
							(char*)password, 	/*entered by user*/
							(char*)nonce, 	/*Must if digest*/
							(char*)opaque, 	/*Must if digest*/
							(char*)algorithm, 	/*Must if digest*/
							(char*)qop,		/*Must if digest*/
							netAccId
						);

  
	MSF_MEM_FREE(MSF_MODID_WPS, username);
    MSF_MEM_FREE(MSF_MODID_WPS, password);
	MSF_MEM_FREE(MSF_MODID_WPS, url);
    MSF_MEM_FREE(MSF_MODID_WPS, realm);
    MSF_MEM_FREE(MSF_MODID_WPS, prx_addr);
	if (auth_info->auth_type == WPS_HTTP_AUTH_TYPE_DIGEST)
	{
		MSF_MEM_FREE(MSF_MODID_WPS, nonce);
		MSF_MEM_FREE(MSF_MODID_WPS, opaque);
		MSF_MEM_FREE(MSF_MODID_WPS, algorithm);
		MSF_MEM_FREE(MSF_MODID_WPS, qop);
	}
}

/*****************************************************************************
 * FUNCTION
 *  wps_http_auth_res_hdlr
 * DESCRIPTION
 *  this function is to handle the username/password response for HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  auth_res        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_auth_res_hdlr(module_type src_mod_id, wps_http_auth_res_struct *auth_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info = NULL;
    wps_req_info_struct *req_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (auth_res == NULL)
    {
        /* invalid param */
        goto error;
    }

    channel_id = auth_res->channel_id;

    /* check channel id */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        goto error;
    }

    req_info = wps_search_req_info_by_id(channel_id, auth_res->request_id);

    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        goto error;
    }

    if (strlen((char*)auth_res->username) == 0)
    {
        /* Abort the authentication */
        HDIc_widgetAction(MSF_MODID_STK, 0xfffffffe, req_info->stk_request_id);
        return;
    }

    /* store the username & password */
    if (req_info->username != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, req_info->username);
    }
    req_info->username = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)auth_res->username);

    if (req_info->password != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, req_info->password);
    }
    req_info->password = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)auth_res->password);

    /* notify STK to use the username and password */
    HDIc_widgetAction(MSF_MODID_STK, 0xffffffff, req_info->stk_request_id);
  error:
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wps_status_query_duplicate_req_hdlr
 * DESCRIPTION
 *  this function is to handle the duplicate query of WPS ready status
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool wps_status_query_duplicate_req_hdlr(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wps_ready_status == WPS_READY_STATUS_NULL)
    {
	for( i=0; i < wps_status_idx; i++)
	{
		if (wps_status_register[i] == src_mod_id)
		{
			return KAL_TRUE;
		}
	}

    }
   return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_status_query_req_hdlr
 * DESCRIPTION
 *  this function is to handle the query of WPS ready status
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_status_query_req_hdlr(module_type src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wps_ready_status == WPS_READY_STATUS_NULL)
    {
	if(!wps_status_query_duplicate_req_hdlr(src_mod_id))
	{
		
        if (wps_status_idx >= WPS_MAX_STATUS_REGISTER_NUM)
        {
            ASSERT(0);
        }
        wps_status_register[wps_status_idx++] = src_mod_id;
    }
    }

    wps_send_status_query_rsp(src_mod_id, wps_ready_status);
}

#ifdef __IMPS__


/*****************************************************************************
 * FUNCTION
 *  wps_send_imps_ready_ind
 * DESCRIPTION
 *  this function is to notify WPS user that it is ready to provide service
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_imps_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wps_send_ilm(NULL, NULL, MSG_ID_WPS_READY_IND, MOD_IMPS);
}

#endif /* __IMPS__ */ 



/*****************************************************************************
 * FUNCTION
 *  wps_http_set_cookie_req_hdlr
 * DESCRIPTION
 *  this function is to handle the username/password response for HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  auth_res        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_set_cookie_req_hdlr( module_type src_mod_id,
					  wps_set_cookie_req_struct *cookie_info,
					  wps_set_cookie_req_var_struct *cookie_var)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *url = NULL;
    kal_uint8 *name = NULL;
    kal_uint8  *value = NULL;                  
    kal_uint8  *domain = NULL;
    kal_uint8  *path= NULL;  
    kal_uint16 cookie_header_len = 0;
    kal_uint8* cookie_header = NULL;
    kal_uint8 portlist[WPS_COOKIE_PORT_NUM*6+1] = {0}; /*5 digits in port num + ,*/	
	kal_uint32 portlist_offset = 0;
	int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cookie_info == NULL || cookie_var == NULL)
    {
		/* No Need to add cookie information*/
		return;
    }
	/*Incase of Cookie info, URL should not be NULL */
	if((cookie_info->maxage == 0)  &&
	   ((cookie_var->url == NULL) || (cookie_var->url_len == 0)))	
	{
		return;
	}
	
	/*Add cookie header information*/
    if(cookie_info->cookie_header[0] != 0)
    {
        cookie_header_len = strlen((const char*)cookie_info->cookie_header)+ 1;
        cookie_header = (kal_uint8*)MSF_MEM_ALLOC(MSF_MODID_WPS, cookie_header_len);
        memcpy(cookie_header, cookie_info->cookie_header, cookie_header_len -1);
        cookie_header[cookie_header_len - 1] = '\0';
    }
	for(i=0; i<WPS_COOKIE_PORT_NUM; i++)
	{
		if(cookie_info->portlist[i] != 0)
		{
			portlist_offset += sprintf((char*)(&portlist[i + portlist_offset]), "%s,",(char*)(cookie_info->portlist[i]));
		}
		else
		{
			if(i>0)
				portlist[portlist_offset -1] = 0;
			break;
		}
	}
    /* store the cookie info */
	if (cookie_var->url != NULL)
    {
		url = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)cookie_var->url);
    }
    if (cookie_var->name != NULL)
    {
		name = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)cookie_var->name);
    }
    if (cookie_var->value != NULL)
    {
		value = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)cookie_var->value);
    }
    if (cookie_var->domain != NULL)
    {
		domain = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)cookie_var->domain);
    }
    if (cookie_var->path != NULL)
    {
		path = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)cookie_var->path);
    }
	

    STKif_setCookie(   MSF_MODID_WPS,
		               (char*)url,
		               (char*)name,
		               (char*)value,
		               (char*)domain,
		               (char*)path,
		               (char*)portlist,
		               cookie_info->maxage ,
		               0,
		               cookie_info->secure,
		               cookie_info->version_major ,
		               cookie_info->version_minor);

  
	MSF_MEM_FREE(MSF_MODID_WPS, name);
    MSF_MEM_FREE(MSF_MODID_WPS, value);
	MSF_MEM_FREE(MSF_MODID_WPS, url);
    MSF_MEM_FREE(MSF_MODID_WPS, domain);
    MSF_MEM_FREE(MSF_MODID_WPS, path);
    MSF_MEM_FREE(MSF_MODID_WPS, cookie_header);	
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_set_channel_rsp
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_set_channel_rsp(module_type dst_id, kal_uint32 req_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *set_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_channel_rsp = (wps_set_channel_rsp_struct*) construct_local_para(sizeof(wps_set_channel_rsp_struct), TD_CTRL);
    set_channel_rsp->result = error_cause;
    set_channel_rsp->channel_id = channel_id;
    set_channel_rsp->req_id = req_id;

    wps_send_ilm(set_channel_rsp, NULL, MSG_ID_WPS_SET_CHANNEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_unset_channel_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_unset_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *unset_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unset_channel_rsp =
        (wps_unset_channel_rsp_struct*) construct_local_para(sizeof(wps_unset_channel_rsp_struct), TD_CTRL);
    unset_channel_rsp->channel_id = channel_id;
    unset_channel_rsp->result = error_cause;

    wps_send_ilm(unset_channel_rsp, NULL, MSG_ID_WPS_UNSET_CHANNEL_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_reconfig_channel_rsp
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_reconfig_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_reconfig_channel_rsp_struct *reconfig_channel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reconfig_channel_rsp = (wps_reconfig_channel_rsp_struct*) construct_local_para(sizeof(wps_reconfig_channel_rsp_struct), TD_CTRL);
    reconfig_channel_rsp->result = error_cause;
    reconfig_channel_rsp->channel_id = channel_id;

    wps_send_ilm(reconfig_channel_rsp, NULL, MSG_ID_WPS_RECONFIG_CHANNEL_RSP, dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_wps_termination_ind
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_wps_termination_ind(module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wps_send_ilm(NULL, NULL, MSG_ID_WPS_TERMINATION_IND, dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_release_all_req_rsp
 * DESCRIPTION
 *  this function is to response channel setup request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_release_all_req_rsp(module_type dst_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_release_all_rsp_struct *release_all_req_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    release_all_req_rsp = (wps_release_all_rsp_struct*) construct_local_para(sizeof(wps_release_all_rsp_struct), TD_CTRL);
    release_all_req_rsp->result = error_cause;

    wps_send_ilm(release_all_req_rsp, NULL, MSG_ID_WPS_RELEASE_ALL_RSP, dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_send_http_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_http_rsp(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 error_cause, kal_uint16 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *http_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_rsp = (wps_http_rsp_struct*) construct_local_para(sizeof(wps_http_rsp_struct), TD_CTRL);
    http_rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_http_rsp_var_struct http_rsp_var;
        msf_hdr_t *hdr = NULL;
        MSF_UINT32 content_length;
        char *content_type;

        req_info->state = WPS_REQ_RSP_SENT;

        /* extract content length and content type */
        hdr = msf_hdr_create(MSF_MODID_WPS);
        msf_hdr_add_headers_from_text(hdr, req_info->rep->headers);

        if (msf_hdr_get_uint32(hdr, MSF_HDR_CONTENT_LENGTH, &content_length) && (content_length > 0))
        {
            http_rsp->content_length = content_length;
        }
        else
        {
            http_rsp->content_length = 0;
        }

        content_type = (char*)msf_hdr_get_string(hdr, MSF_HDR_CONTENT_TYPE);
        if (content_type != NULL)
        {
            if (strlen(content_type) >= 256)
                EXT_ASSERT(0, 0, 0, 0);
            strcpy((char*)http_rsp->content_type, content_type);
        }
        http_rsp->more = (req_info->pipe_handle < 0) ? KAL_FALSE : KAL_TRUE;
        http_rsp->protocol = req_info->rep->protocol;
        http_rsp->request_id = req_info->request_id;
        http_rsp->status = req_info->rep->status;
        if (req_info->rep->newUrl != NULL)
        {
            http_rsp_var.new_url_len = strlen(req_info->rep->newUrl);
            http_rsp_var.new_url = (kal_uint8*) req_info->rep->newUrl;
        }
        else
        {
            http_rsp_var.new_url_len = 0;
        }
        if (req_info->rep->headers != NULL)
        {
            http_rsp_var.reply_header_len = strlen(req_info->rep->headers);
            http_rsp_var.reply_header = (kal_uint8*) req_info->rep->headers;
        }
        else
        {
            http_rsp_var.reply_header_len = 0;
        }
        if (req_info->reply_type == WPS_DATA_TYPE_BUFFER && req_info->buff_pos > 0)
        {
            http_rsp_var.reply_segment_len = req_info->buff_pos;
            http_rsp_var.reply_segment = req_info->buff;
        }
        else
        {
            http_rsp_var.reply_segment_len = 0;
        }

        pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_RSP, (void*)&http_rsp_var, NULL);
        if (pdu_len > 0)
        {
            peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
            if (wps_pun_var_part
                (WPS_PUN_PACK, MSG_ID_WPS_HTTP_RSP, (void*)&http_rsp_var, get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_len)
            {
                free_peer_buff(peer_buff_ptr);
                peer_buff_ptr = NULL;
            }
        }
        if (req_info->reply_type == WPS_DATA_TYPE_BUFFER)
        {
            wps_clear_request_buff(req_info);
        }
        else
        {
            req_info->buff_pos = 0;
            http_rsp->more = KAL_FALSE;
        }

        msf_hdr_delete(hdr);
        wps_send_ilm(http_rsp, peer_buff_ptr, MSG_ID_WPS_HTTP_RSP, dst_id);
    }
    else
    {
        if (req_info != NULL)
        {
            http_rsp->request_id = req_info->request_id;
            http_rsp->cause = req_info->last_error;
            
            if(error_cause == WPS_ERROR_REQ_ABORT)
            {
                extern MSF_INT32 HDIa_getLastError(void);
                http_rsp->status = (kal_uint16)HDIa_getLastError();
            }
        }
        else
        {
            http_rsp->request_id = request_id;
        }
        wps_send_ilm(http_rsp, NULL, MSG_ID_WPS_HTTP_RSP, dst_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_read_content_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_read_content_rsp(
    module_type dst_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_uint16 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *read_content_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_content_rsp =
        (wps_read_content_rsp_struct*) construct_local_para(sizeof(wps_read_content_rsp_struct), TD_CTRL);
    read_content_rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_read_content_rsp_var_struct read_content_rsp_var;

        read_content_rsp->more = (req_info->pipe_handle < 0) ? KAL_FALSE : KAL_TRUE;
        read_content_rsp->request_id = req_info->request_id;
        read_content_rsp->seq_num = req_info->seq_num;

        if (req_info->buff_pos > 0)
        {
            read_content_rsp_var.reply_segment_len = req_info->buff_pos;
            read_content_rsp_var.reply_segment = req_info->buff;
            pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_READ_CONTENT_RSP, (void*)&read_content_rsp_var, NULL);
            if (pdu_len > 0)
            {
                peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
                if (wps_pun_var_part
                    (WPS_PUN_PACK, MSG_ID_WPS_READ_CONTENT_RSP, (void*)&read_content_rsp_var,
                     get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_len)
                {
                    free_peer_buff(peer_buff_ptr);
                    peer_buff_ptr = NULL;
                }
            }
        }

        wps_clear_request_buff(req_info);
        wps_send_ilm(read_content_rsp, peer_buff_ptr, MSG_ID_WPS_READ_CONTENT_RSP, dst_id);
        
        req_info->state = WPS_REQ_RSP_SENT;
    }
    else
    {
        read_content_rsp->request_id = request_id;
        wps_send_ilm(read_content_rsp, NULL, MSG_ID_WPS_READ_CONTENT_RSP, dst_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_dl_progress_ind
 * DESCRIPTION
 *  this function is to send the HTTP/WSP reply content downloading status indication to the callee.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  status          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_dl_progress_ind(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *dl_prog_ind;
    kal_uint32 fileSize = 0; 
    kal_int32 ret;
    kal_uint32 len = 0; 	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dl_prog_ind = (wps_dl_progress_ind_struct*) construct_local_para(sizeof(wps_dl_progress_ind_struct), TD_CTRL|TD_RESET);
    dl_prog_ind->request_id = req_info->request_id;
    dl_prog_ind->acc_size = req_info->acc_size;
    dl_prog_ind->seq_num = req_info->seq_num;
    dl_prog_ind->status = status;
    if(status == WPS_DL_STATUS_ABORT)
    {
        dl_prog_ind->cause = req_info->last_error;
    }
    else if(req_info->flag & WPS_FLAG_ENABLE_PGDL_DL)
    {
	if((req_info->reply_type == WPS_DATA_TYPE_FILE) && (req_info->file_handle > 0))
	{
	    FS_GetFileSize(req_info->file_handle, &fileSize);
	    if(fileSize > WPS_DEFAULT_DL_BUFF_LEN)
	    {
			ret = FS_Seek(req_info->file_handle, 0, FS_FILE_BEGIN);
			if (ret == FS_NO_ERROR)
			{
		    ret = FS_Read(req_info->file_handle, dl_prog_ind->dl_buff, WPS_DEFAULT_DL_BUFF_LEN, &len);
			if(ret >=0 )
		    {
		        if(len < WPS_DEFAULT_DL_BUFF_LEN)
		        {
		            dl_prog_ind->dl_buff_len = len;
			}
			else
			{
			    dl_prog_ind->dl_buff_len = WPS_DEFAULT_DL_BUFF_LEN;
			}
		    }
		 }
	    }
	}
    }

    wps_send_ilm(dl_prog_ind, NULL, MSG_ID_WPS_DL_PROGRESS_IND, dst_id);
}

/************************************************************
 * Global function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_send_cancel_rsp
 * DESCRIPTION
 *  this function is to response cancel request.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_cancel_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_rsp_struct *cancel_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cancel_rsp = (wps_cancel_rsp_struct*) construct_local_para(sizeof(wps_cancel_rsp_struct), TD_CTRL);
    cancel_rsp->request_id = request_id;
    cancel_rsp->result = error_cause;

    wps_send_ilm(cancel_rsp, NULL, MSG_ID_WPS_CANCEL_RSP, dst_id);
}



/*****************************************************************************
 * FUNCTION
 *  wps_send_post_content_ind
 * DESCRIPTION
 *  this function is to send complete indication of segment content post
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_post_content_ind(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause, kal_uint8 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_post_content_ind_struct *post_content_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    post_content_ind =
        (wps_post_content_ind_struct*) construct_local_para(sizeof(wps_post_content_ind_struct), TD_CTRL);
    post_content_ind->request_id = request_id;
    post_content_ind->result = error_cause;
    post_content_ind->seq_num = seq_num;

    wps_send_ilm(post_content_ind, NULL, MSG_ID_WPS_POST_CONTENT_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_push_ind
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_push_ind(module_type dst_id, kal_uint8 *content_type, kal_uint32 content_length, kal_wchar *data_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_push_ind_struct *push_ind;
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    push_ind = (wps_push_ind_struct*) construct_local_para(sizeof(wps_push_ind_struct), TD_CTRL);
    strcpy((char*)push_ind->content_type, (const char*)content_type);
    push_ind->content_length = content_length;
    len = widget_ucs2_length((kal_uint8*) data_path);
    if (len >= 256)
    {
        ASSERT(0);
    }
    kal_mem_cpy(push_ind->data_path, data_path, ((len + 1) * 2));
    wps_send_ilm(push_ind, NULL, MSG_ID_WPS_PUSH_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_create_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_create_stream_connection_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_create_stream_connection_rsp_struct*) construct_local_para(sizeof(wps_create_stream_connection_rsp_struct), TD_CTRL);
    rsp->result = error_cause;
    rsp->channel_id = channel_id;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_send_close_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_close_stream_connection_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_close_stream_connection_rsp_struct*) construct_local_para(sizeof(wps_close_stream_connection_rsp_struct), TD_CTRL);
    rsp->result = error_cause;
    rsp->channel_id = channel_id;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_create_stream_connection_rsp
 * DESCRIPTION
 *  this function is to send push data indication to the registrar
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  content_type        [?]         
 *  content_length      [IN]        
 *  data_path           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_stream_connection_close_ind(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_connection_closed_ind_struct *ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (wps_stream_connection_closed_ind_struct*) construct_local_para(sizeof(wps_stream_connection_closed_ind_struct), TD_CTRL);
    ind->error_cause = error_cause;
    ind->channel_id = channel_id;

    wps_send_ilm(ind, NULL, MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_post_content_ind
 * DESCRIPTION
 *  this function is to send complete indication of segment content post
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  request_id      [IN]        
 *  error_cause     [IN]        
 *  seq_num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_stream_data_send_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause, kal_uint8 seq_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_data_send_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_stream_data_send_rsp_struct*) construct_local_para(sizeof(wps_stream_data_send_rsp_struct), TD_CTRL);
    rsp->channel_id = channel_id;
    rsp->result = error_cause;
    rsp->seq_num = seq_num;

    wps_send_ilm(rsp, NULL, MSG_ID_WPS_STREAM_DATA_SEND_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_read_content_rsp
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  req_info        [?]         
 *  error_cause     [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_stream_data_read_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_bool more)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_stream_data_read_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (wps_stream_data_read_rsp_struct*) construct_local_para(sizeof(wps_stream_data_read_rsp_struct), TD_CTRL);
    rsp->channel_id = channel_id;
    rsp->result = error_cause;

    if (error_cause == WPS_OK && req_info != NULL)
    {
        peer_buff_struct *peer_buff_ptr = NULL;
        kal_uint16 pdu_len;
        kal_uint16 len;
        wps_stream_data_read_rsp_var_struct read_rsp_var;

        rsp->more = more;
        rsp->seq_num = req_info->seq_num;

        if (req_info->buff_pos > 0)
        {
            read_rsp_var.length = req_info->buff_pos;
            read_rsp_var.data = req_info->buff;
            pdu_len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_STREAM_DATA_READ_RSP, (void*)&read_rsp_var, NULL);
            if (pdu_len > 0)
            {
                peer_buff_ptr = construct_peer_buff(pdu_len, 0, 0, TD_CTRL);
                if (wps_pun_var_part
                    (WPS_PUN_PACK, MSG_ID_WPS_STREAM_DATA_READ_RSP, (void*)&read_rsp_var,
                     get_peer_buff_pdu(peer_buff_ptr, &len)) != pdu_len)
                {
                    free_peer_buff(peer_buff_ptr);
                    peer_buff_ptr = NULL;
                }
            }
        }

        wps_clear_request_buff(req_info);
        wps_send_ilm(rsp, peer_buff_ptr, MSG_ID_WPS_STREAM_DATA_READ_RSP, dst_id);
        
        req_info->state = WPS_REQ_RSP_SENT;
    }
    else
    {
        wps_send_ilm(rsp, NULL, MSG_ID_WPS_STREAM_DATA_READ_RSP, dst_id);
    }
}

#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_session_info_rsp
 * DESCRIPTION
 *  this function is to send the result of getting session information request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  session_info        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_session_info_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_session_info_response_t *session_info,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_rsp_struct *get_session_info_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_session_info_rsp =
        (wps_sec_get_session_info_rsp_struct*) construct_local_para(
                                                sizeof(wps_sec_get_session_info_rsp_struct),
                                                TD_CTRL);

    get_session_info_rsp->channel_id = channel_id;

    if (error_cause == WPS_OK && session_info != NULL)
    {
        get_session_info_rsp->result = WPS_OK;
        get_session_info_rsp->sec_conn_type = (kal_uint8) session_info->connectionType;
        get_session_info_rsp->key_exchange_alg = (kal_uint16) session_info->keyExchangeAlgorithm;
        get_session_info_rsp->blk_encrypt_alg = (kal_uint8) session_info->encrAlg;
        get_session_info_rsp->hash_alg = (kal_uint8) session_info->hMacAlg;
    }
    else
    {
    #if 1    	
        get_session_info_rsp->result = WPS_ERROR_NOT_FOUND;    
    #else    	    
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
    }

    wps_send_ilm(get_session_info_rsp, NULL, MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_issuer_str
 * DESCRIPTION
 *  this function is to used to get the issuer (or subject) name of a certificate
 * CALLS
 *  
 * PARAMETERS
 *  charSet         [IN]        
 *  issuer          [?]         
 *  issuerLen       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_sec_get_issuer_str(MSF_INT16 charSet, void *issuer, int issuerLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 nbrIssuerAtts;
    sec_name_attribute_t *issuerAtt = NULL;
    int i, attLen, attStrPos;
    char *attStr, *tmpStr;
    long tmpStrLen;
    int result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int sec_tiCvtToUtf8(unsigned char *strToCvt, long strToCvtLen, char *dst, long *dstLen, MSF_INT16 charSet);

    /* Use parser to get issuer attributes. */
    if (charSet == -1)  /* X.509 certificate */
    {
        SEC_x509GetNbrIssuerStrings(issuer, (MSF_UINT16) issuerLen, &nbrIssuerAtts);
        issuerAtt = (sec_name_attribute_t*) MSF_MEM_ALLOC(MSF_MODID_WPS, nbrIssuerAtts * sizeof(sec_name_attribute_t));
        SEC_x509GetIssuerAttributes(
            MSF_MODID_WPS,
            (const unsigned char*)issuer,
            (MSF_UINT16) issuerLen,
            &nbrIssuerAtts,
            issuerAtt);
    }
    else    /* WTLS certificate */
    {
        SEC_wtlsGetIssuerAttributes(MSF_MODID_WPS, issuer, (MSF_UINT16) issuerLen, &nbrIssuerAtts, NULL);
        issuerAtt = (sec_name_attribute_t*) MSF_MEM_ALLOC(MSF_MODID_WPS, nbrIssuerAtts * sizeof(sec_name_attribute_t));
        SEC_wtlsGetIssuerAttributes(
            MSF_MODID_WPS,
            (const unsigned char*)issuer,
            (MSF_UINT16) issuerLen,
            &nbrIssuerAtts,
            issuerAtt);
        for (i = 0; i < nbrIssuerAtts; i++)
        {
            issuerAtt[i].attributeCharSet = charSet;
        }
    }

    /* Get length of string to show */
    attLen = 0;
    attStrPos = 0;
    for (i = 0; i < nbrIssuerAtts; i++)
    {
        attLen += issuerAtt[i].attributeValueLen * 2;
    }

    attStr = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, (attLen * 2 + attStrPos + (2*nbrIssuerAtts) + 5));
    tmpStr = attStr;

    for (i = 0; i < nbrIssuerAtts; i++)
    {
        tmpStrLen = (issuerAtt[i].attributeValueLen * 2) + 2;

        result = sec_tiCvtToUtf8(
                    issuerAtt[i].attributeValue,
                    issuerAtt[i].attributeValueLen,
                    tmpStr,
                    &tmpStrLen,
                    issuerAtt[i].attributeCharSet);
        if (result != SEC_ERR_OK)
        {
            for (i = 0; i < nbrIssuerAtts; i++)
            {
                MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt[i].attributeValue);
            }
            MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt);
            return NULL;
        }

        attStrPos += tmpStrLen;
        tmpStr += (tmpStrLen + 2);
        attStr[attStrPos++] = ',';
        attStr[attStrPos++] = ' ';
    }   /* for */

    attStrPos -= 2;

    attStr[attStrPos] = '\0';
    for (i = 0; i < nbrIssuerAtts; i++)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt[i].attributeValue);
    }
    MSF_MEM_FREE(MSF_MODID_WPS, issuerAtt);

    return attStr;
}


/*****************************************************************************
 * FUNCTION
 *  wps_sec_get_sig_alg_name
 * DESCRIPTION
 *  this function is to used to get signature algorithm name of a certificate
 * CALLS
 *  
 * PARAMETERS
 *  sig_alg_name            [?]         
 *  sig_alg_name_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_sec_get_sig_alg_name(void *sig_alg_name, MSF_UINT16 sig_alg_name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const unsigned char wps_oid_rsa[] = "\x2A\x86\x48\x86\xF7\x0D\x01\x01";
    const unsigned char wps_oid_dsa[] = "\x2A\x86\x48\xCE\x38\x04\x03";
    unsigned char *cert = (unsigned char*)sig_alg_name;
    MSF_UINT16 i = 0, dsa = 0;
    char *name = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, 32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (sig_alg_name_len - 1); i++)
    {
        if (*cert == wps_oid_rsa[i])
        {
            cert++;
        }
        else if (*cert == wps_oid_dsa[i])
        {
            dsa = 1;
            cert++;
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }

    if (dsa == 0)
    {
        if (*cert == 5)
        {
            sprintf(name, "sha1RSA");
        }
        else if (*cert == 4)
        {
            sprintf(name, "md5RSA");
        }
        else if (*cert == 2)
        {
            sprintf(name, "md2RSA");
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }
    else
    {
        if (*cert == 3)
        {
            sprintf(name, "sha1DSA");
        }
        else
        {
            MSF_MEM_FREE(MSF_MODID_WPS, name);
            return NULL;
        }
    }

    return name;
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_current_cert_rsp
 * DESCRIPTION
 *  this function is to send the result of getting current certificate request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  current_cert        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_current_cert_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_current_cert_response_t *current_cert,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_rsp_struct *get_current_cert_rsp;
    sec_certificate_t parsed_cert;
    kal_uint8 format = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&parsed_cert, 0, sizeof(sec_certificate_t));

    get_current_cert_rsp =
        (wps_sec_get_current_cert_rsp_struct*) construct_local_para(
                                                sizeof(wps_sec_get_current_cert_rsp_struct),
                                                TD_CTRL|TD_RESET);

    get_current_cert_rsp->channel_id = channel_id;

    if (error_cause == WPS_OK && current_cert != NULL)
    {
        format = current_cert->format;
        if (SEClib_parseCertificate(current_cert->format, current_cert->cert, current_cert->certLen, &parsed_cert) ==
            SEC_ERR_OK)
        {
            error_cause = WPS_OK;
        }
        else
        {
            error_cause = WPS_ERROR_NOT_FOUND;
        }
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

    if (error_cause == WPS_OK)
    {
        get_current_cert_rsp->result = WPS_OK;
        get_current_cert_rsp->channel_id = channel_id;
        get_current_cert_rsp->type = format;
        get_current_cert_rsp->version = (kal_uint8) parsed_cert.certificate_version;
        get_current_cert_rsp->not_after = (kal_uint32) parsed_cert.valid_not_after;
        get_current_cert_rsp->not_before = (kal_uint32) parsed_cert.valid_not_before;

        if (format == SEC_CERT_FORMAT_X509)
        {
            if (parsed_cert.issuer)
            {
                kal_uint8 *issuer =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.issuer, parsed_cert._u.x509.issuerLen);
                if (issuer)
                {
                    get_current_cert_rsp->issuer_len = strlen((char*)issuer);
					memset(get_current_cert_rsp->issuer,0,256);					
                    if (get_current_cert_rsp->issuer_len > 256)
                    {
                        get_current_cert_rsp->issuer_len = 255;
                    }
                    kal_mem_cpy(get_current_cert_rsp->issuer, issuer, get_current_cert_rsp->issuer_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, issuer);
                }
            }
            if (parsed_cert.subject)
            {
                kal_uint8 *subject =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.subject, parsed_cert._u.x509.subjectLen);
                if (subject)
                {
                    get_current_cert_rsp->subject_len = strlen((char*)subject);
					memset(get_current_cert_rsp->subject,0,256);								
                    if (get_current_cert_rsp->subject_len > 256)
                    {
                        get_current_cert_rsp->subject_len = 255;						
                    }
                    kal_mem_cpy(get_current_cert_rsp->subject, subject, get_current_cert_rsp->subject_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, subject);
                }
            }
            if (parsed_cert._u.x509.serialNumber)
            {
                get_current_cert_rsp->serial_num_len = (kal_uint16) parsed_cert._u.x509.serialNumberLen;
                if (get_current_cert_rsp->serial_num_len > 128)
                {
                    ASSERT(0);
                }
                kal_mem_cpy(
                    get_current_cert_rsp->serial_num,
                    parsed_cert._u.x509.serialNumber,
                    parsed_cert._u.x509.serialNumberLen);
            }
            if (parsed_cert._u.x509.signatureAlgorithm)
            {
                kal_uint8 *sig_alg_name =
                    (kal_uint8*) wps_sec_get_sig_alg_name(
                                    parsed_cert._u.x509.signatureAlgorithm,
                                    parsed_cert._u.x509.signatureAlgorithmLen);
                if (sig_alg_name)
                {
                    get_current_cert_rsp->sig_alg_name_len = strlen((char*)sig_alg_name);
                    if (get_current_cert_rsp->sig_alg_name_len > 128)
                    {
                        ASSERT(0);
                    }
                    kal_mem_cpy(
                        get_current_cert_rsp->sig_alg_name,
                        sig_alg_name,
                        get_current_cert_rsp->sig_alg_name_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, sig_alg_name);
                }
            }
        }
        else if (format == SEC_CERT_FORMAT_WTLS)
        {
            if (parsed_cert.issuer)
            {
                kal_uint8 *issuer =
                    (kal_uint8*) wps_sec_get_issuer_str(
                                    parsed_cert._u.wtls.issuercharacterSet,
                                    parsed_cert.issuer,
                                    parsed_cert._u.wtls.issuerLen);
                if (issuer)
                {
                    get_current_cert_rsp->issuer_len = strlen((char*)issuer);
					memset(get_current_cert_rsp->issuer,0,256);		
                    if (get_current_cert_rsp->issuer_len > 256)
                    {
                        get_current_cert_rsp->issuer_len = 255;
                    }
                    kal_mem_cpy(get_current_cert_rsp->issuer, issuer, get_current_cert_rsp->issuer_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, issuer);
                }
            }
            if (parsed_cert.subject)
            {
                kal_uint8 *subject =
                    (kal_uint8*) wps_sec_get_issuer_str(-1, parsed_cert.subject, parsed_cert._u.wtls.subjectLen);
                if (subject)
                {
                    get_current_cert_rsp->subject_len = strlen((char*)subject);
	                memset(get_current_cert_rsp->subject,0,256);						
                    if (get_current_cert_rsp->subject_len > 256)
                    {
						get_current_cert_rsp->subject_len = 255;	

                    }
                    kal_mem_cpy(get_current_cert_rsp->subject, subject, get_current_cert_rsp->subject_len);
                    MSF_MEM_FREE(MSF_MODID_WPS, subject);
                }
            }
            
            get_current_cert_rsp->serial_num_len = 0;
            
            if (parsed_cert._u.wtls.signature_algorithm == 0)   /* anonymous */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "anonymous");
            }
            else if (parsed_cert._u.wtls.signature_algorithm == 1)      /* ecdsa_sha */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "ecdsa_sha");
            }
            else if (parsed_cert._u.wtls.signature_algorithm == 2)      /* rsa_sha */
            {
                kal_sprintf((char*)get_current_cert_rsp->sig_alg_name, "rsa_sha");
            }
        }
    }
    else
    {
        get_current_cert_rsp->result = WPS_ERROR_NOT_FOUND;
    }

    wps_send_ilm(get_current_cert_rsp, NULL, MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_cert_ids_rsp
 * DESCRIPTION
 *  this function is to send the indication of a x509 ca certificate
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  total               [IN]        
 *  cert_ids            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_sec_get_cert_ids_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 *cert_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_rsp_struct *p;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_sec_get_cert_ids_rsp_struct*) construct_local_para(sizeof(wps_sec_get_cert_ids_rsp_struct), TD_RESET);

    p->total = total;

    if (total > 0)
    {
        ASSERT(cert_ids);
        for(i = 0; i < total; i++)
        {
            p->cert_ids[i] = cert_ids[i];
        }
    }

    wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, (module_type)dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_sec_get_cert_rsp
 * DESCRIPTION
 *  this function is to send the indication of a x509 ca certificate
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  index               [IN]        
 *  result              [IN]        
 *  not_after           [IN]        
 *  not_before          [IN]        
 *  type                [IN]        
 *  version             [IN]        
 *  issuer              [IN]        
 *  subject             [IN]        
 *  serial_num          [IN]        
 *  sig_alg_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_sec_get_cert_rsp(
    MSF_UINT8 dst_id,
    MSF_UINT8 index,
    MSF_UINT8 result,
    MSF_UINT32 not_after,
    MSF_UINT32 not_before,
    MSF_UINT8 type,
    MSF_UINT8 version,
    const char *issuer,
    const char *subject,
    const char *serial_num,
    const char *sig_alg_name,
    unsigned char *rsa_modulus,
    MSF_UINT16 mod_len,
    unsigned char *rsa_exponent,
    MSF_UINT16 exp_len,
    MSF_UINT8 attribute )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_rsp_struct *p;
    wps_sec_cert_content_struct *cert;
    wps_sec_rsa_public_key_struct *key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_sec_get_cert_rsp_struct*) construct_local_para(sizeof(wps_sec_get_cert_rsp_struct), TD_RESET);

    p->result = result;
    p->cert_id = index;

    if (result != WPS_OK)
    {
        wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_RSP, (module_type)dst_id);
		return;
    }

    cert = &p->cert;
    key = &p->rsa_public_key;

    cert->type = type;
    cert->version = (kal_uint8) version;
    cert->not_after = (kal_uint32) not_after;
    cert->not_before = (kal_uint32) not_before;
    cert->cert_attribute = attribute;	

    if (issuer)
    {
        cert->issuer_len = strlen(issuer);
        kal_mem_cpy(cert->issuer, issuer, cert->issuer_len);
    }
    if (subject)
    {
        cert->subject_len = strlen(subject);
        kal_mem_cpy(cert->subject, subject, cert->subject_len);
    }
    if (serial_num)
    {
        cert->serial_num_len = strlen(serial_num);
        kal_mem_cpy(cert->serial_num, serial_num, cert->serial_num_len);
    }
    if (sig_alg_name)
    {
        cert->sig_alg_name_len = strlen((char*)sig_alg_name);
        kal_mem_cpy(cert->sig_alg_name, sig_alg_name, cert->sig_alg_name_len);
    }

    if (rsa_modulus && mod_len > 0)
    {
        key->mod_len = mod_len;
        key->rsa_modulus = (kal_uint8*) get_ctrl_buffer((kal_uint16) mod_len);
        kal_mem_cpy(key->rsa_modulus, rsa_modulus, mod_len);
    }

    /* exponent */
    if (rsa_exponent && exp_len > 0)
    {
        key->exp_len = exp_len;
        key->rsa_exponent = (kal_uint8*) get_ctrl_buffer((kal_uint16) exp_len);
        kal_mem_cpy(key->rsa_exponent, rsa_exponent, exp_len);
    }

    wps_send_ilm(p, NULL, MSG_ID_WPS_SEC_GET_CERT_RSP, (module_type)dst_id);
}

#ifdef __HTTP_INTERFACE__
/*****************************************************************************
 * FUNCTION
 *  wps_send_verify_cert_chain_rsp
 * DESCRIPTION
 *  this function is to send the result of verify certificate chain request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id              [IN]        
 *  channel_id          [IN]        
 *  current_cert        [?]         
 *  error_cause         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_verify_cert_chain_rsp(
    module_type dst_id,
    sec_verify_cert_chain_response_t *rsp,
    kal_uint8 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_verify_cert_chain_rsp_struct *verify_cert_chain_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    verify_cert_chain_rsp =
        (wps_sec_verify_cert_chain_rsp_struct*) construct_local_para(sizeof(wps_sec_verify_cert_chain_rsp_struct), TD_RESET);

    if(rsp == NULL)
    {
        verify_cert_chain_rsp->result = error_cause;
        goto error;
    }

    switch(rsp->result)
    {
    case SEC_ERR_OK:
        verify_cert_chain_rsp->result = WPS_SEC_OK;
        break;
    case SEC_ERR_INSUFFICIENT_MEMORY:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INSUFFICIENT_MEMORY;
        break;
    case SEC_ERR_INVALID_PARAMETER:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INVALID_PARAMETER;
        break;
    case SEC_ERR_CRYPTOLIB_NOT_INITIALISED:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_CRYPTOLIB_NOT_INITIALISED;
        break;
    case SEC_ERR_INVALID_KEY:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_INVALID_KEY;
        break;
    case SEC_ERR_UNKNOWN_CERTIFICATE_TYPE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_UNKNOWN_CERTIFICATE_TYPE;
        break;
    case SEC_ERR_BAD_CERTIFICATE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_BAD_CERTIFICATE;
        break;
    case SEC_ERR_CERTIFICATE_EXPIRED:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_CERTIFICATE_EXPIRED;
        break;
    case SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_NO_MATCHING_ROOT_CERTIFICATE;
        break;
    default:
        verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
        break;
    }

    verify_cert_chain_rsp->format = rsp->format;
    if(rsp->rootCert != NULL && rsp->rootLen > 0)
    {
        int file_handle, result;
        kal_uint8 *filename;
        char tempfile[] = "/jal_root.cer";
        
        MSF_FILE_REMOVE(tempfile);
        file_handle = MSF_FILE_OPEN(MSF_MODID_WPS, tempfile, MSF_FILE_SET_WRONLY| MSF_FILE_SET_CREATE, rsp->rootLen);
        if(file_handle < 1)
        {
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
            goto error;
        }
        
    	result = MSF_FILE_WRITE(file_handle, rsp->rootCert, rsp->rootLen);
        if ((result < rsp->rootLen) || (result == -1))
    	{
    		MSF_FILE_CLOSE(file_handle);		
    		MSF_FILE_REMOVE(tempfile);
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
    		goto error;
    	}

        MSF_FILE_CLOSE(file_handle);		

        filename = HDI_FileNameTranslate(tempfile);

        if (!filename)
    	{
    		MSF_FILE_REMOVE(tempfile);
            verify_cert_chain_rsp->result = WPS_SEC_ERR_GENERAL_ERROR;
    		goto error;
    	}

        widget_ucs2_strcpy((kal_uint8*)verify_cert_chain_rsp->root_cert, (const kal_uint8*)filename);
        verify_cert_chain_rsp->root_len = rsp->rootLen;

        HDI_FileNameFree(filename);            
    }

error:
    wps_send_ilm(verify_cert_chain_rsp, NULL, MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP, dst_id);
}
#endif/*#__HTTP_INTERFACE__*/
#endif /* WAP_SEC_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_send_http_auth_ind
 * DESCRIPTION
 *  this function is to send the indication of HTTP authentication request
 * CALLS
 *  
 * PARAMETERS
 *  dst_id          [IN]        
 *  channel_id      [IN]        
 *  request_id      [IN]        
 *  auth_type       [IN]        
 *  realm           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void
wps_send_http_auth_ind(
    module_type dst_id,
    kal_uint8 channel_id,
    kal_uint16 request_id,
    kal_uint8 auth_type,
    kal_uint8 *realm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_ind_struct *http_auth_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_auth_ind = (wps_http_auth_ind_struct*) construct_local_para(sizeof(wps_http_auth_ind_struct), TD_CTRL);

    http_auth_ind->request_id = request_id;
    http_auth_ind->channel_id = channel_id;
    http_auth_ind->auth_type = auth_type;
    memcpy(http_auth_ind->realm, realm, 256);
    http_auth_ind->realm[255] = 0;
    http_auth_ind->realm_len = strlen((char*)http_auth_ind->realm);

    wps_send_ilm(http_auth_ind, NULL, MSG_ID_WPS_HTTP_AUTH_IND, dst_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_send_status_query_rsp
 * DESCRIPTION
 *  this function is to send the response of status query
 * CALLS
 *  
 * PARAMETERS
 *  dst_id      [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_status_query_rsp(module_type dst_id, kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *status_query_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status_query_rsp =
        (wps_status_query_rsp_struct*) construct_local_para(sizeof(wps_status_query_rsp_struct), TD_CTRL);

    status_query_rsp->status = status;

    wps_send_ilm(status_query_rsp, NULL, MSG_ID_WPS_STATUS_QUERY_RSP, dst_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_check_recv_buf_size
 * DESCRIPTION
 *  Because the control buffer has limited size, e.g., 2KB, this function will
 *  decrease the content segment buffer size specified by the user if it is 
 *  unable to pack the new URL, response header, and content segment at the same
 *  time.
 * PARAMETERS
 *  req                     [IN]            Pointer to a HTTP request     
 * RETURNS
 *  If a usable size is found, return positve value; otherwise, return zero
 *  to indicate a error.
 *****************************************************************************/
kal_int32 wps_check_recv_buf_size(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_var_struct http_rsp_var;
    kal_int32 hdr_len, remained_len;
    kal_uint8* buff = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* new URL: */
    if (req_info->rep->newUrl != NULL)
    {
        http_rsp_var.new_url_len = strlen(req_info->rep->newUrl);
        http_rsp_var.new_url = (kal_uint8*) req_info->rep->newUrl;
    }
    else
    {
        http_rsp_var.new_url_len = 0;
    }

    /* response header: */
    if (req_info->rep->headers != NULL)
    {
        http_rsp_var.reply_header_len = strlen(req_info->rep->headers);
		if(http_rsp_var.reply_header_len > WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN)
		{

			buff = MSF_MEM_ALLOC(MSF_MODID_WPS, WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN);
			memcpy(buff, req_info->rep->headers, WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN -5);
			memcpy(buff+(WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN-5), "\r\n\r\n\0", 5);
			MSF_MEM_FREE(MSF_MODID_WPS,req_info->rep->headers);
			req_info->rep->headers = (char*)buff;
			http_rsp_var.reply_header_len = WPS_HTTP_REPLY_TRUNCATE_HEADER_LEN;
		}
        http_rsp_var.reply_header = (kal_uint8 *)req_info->rep->headers;
    }
    else
    {
        http_rsp_var.reply_header_len = 0;
    }

    /* zero segment length: */
    http_rsp_var.reply_segment_len = 0;

    /* Calculate the buffer length of new URL and response header. */
    hdr_len = wps_pun_var_part(
                WPS_PUN_SIZE, 
                MSG_ID_WPS_HTTP_RSP, 
                (void*)&http_rsp_var, 
                NULL);

    remained_len = WPS_PEER_BUF_MAX_SIZE - hdr_len;
    
    if (remained_len < WPS_SEGMENT_MIN_SIZE || remained_len < 0)
    {
        return 0;
    }
    else
    {
        return remained_len;
    }
}

#endif /* WPS_SUPPORT */ 

#ifdef WAP_SEC_SUPPORT
#ifdef STK_CFG_USE_MTK_TLS

/*****************************************************************************
 * FUNCTION
 *  wps_handle_tls_notify_ind
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
void wps_handle_tls_notify_ind(app_tls_notify_ind_struct* ind)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    STKif_tls_adp_notify(ind->sock_id, ind->event, ind->result, ind->error, ind->detail_cause);
}

/*****************************************************************************
 * FUNCTION
 *  wps_handle_soc_notify_ind
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
void wps_handle_soc_notify_ind(app_soc_notify_ind_struct* ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int event_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(ind->event_type)
	{
		case SOC_READ:
			event_type = MSF_SOCKET_EVENT_RECV;
			break;
		case SOC_WRITE:
			event_type = MSF_SOCKET_EVENT_SEND ;			
			break;
		case SOC_ACCEPT:
			event_type = MSF_SOCKET_EVENT_ACCEPT;			
			break;
		case SOC_CLOSE:
			event_type = MSF_SOCKET_EVENT_CLOSED;			
			break;
	}
	STKif_tls_adp_soc_notify(ind->socket_id, event_type, ind->result, ind->error_cause, ind->detail_cause);
}

/*****************************************************************************
 * FUNCTION
 *  wps_handle_tls_alert_ind
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
void wps_handle_tls_alert_ind(app_tls_alert_ind_struct* ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Alert received from TLS task */
    STKif_tls_adp_alert_ind(ind->sock_id, ind->alert_level, ind->alert_desc, ind->error, ind->cause);
}

/*****************************************************************************
 * FUNCTION
 *  wps_handle_tls_invalid_cert_ind
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
void wps_handle_tls_invalid_cert_ind(app_tls_invalid_cert_ind_struct* ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Invalid certificate handling result from TLS task */
    STKif_tls_adp_invalid_cert_ind(ind->sock_id, ind->result, ind->action);
}

/*****************************************************************************
 * FUNCTION
 *  wps_handle_tls_client_auth_ind
 * DESCRIPTION
 *  This function checks whether the WPS service is ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  On ready, return KAL_TRUE; otherwise, return KAL_FALSE.
 *****************************************************************************/
void wps_handle_tls_client_auth_ind(app_tls_client_auth_ind_struct* ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* not expected */
    ASSERT(0);
}

#endif /* STK_CFG_USE_MTK_TLS */
#endif /*WAP_SEC_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  wps_fsm
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_fsm(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WAP_PUSH_SUPPORT__
    if (msf_modules[MSF_MODID_PMG].isActive)
    {
        pmg_external_msg_hdlr((void *)ilm_ptr);
    }
#endif
    switch (ilm_ptr->msg_id)
    {
#ifdef WPS_SUPPORT
        case MSG_ID_WAP_READY_IND:
            wps_wap_ready_ind_hdlr();
            break;
        case MSG_ID_WPS_SET_CHANNEL_REQ:
        {
            wps_set_channel_req_var_struct set_channel_req_var;

            wps_set_channel_req_struct *p = (wps_set_channel_req_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_set_channel_rsp(ilm_ptr->src_mod_id, p->req_id, 0xff, WPS_ERROR_NOT_READY);                
                break;
            }
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &set_channel_req_var,
                    get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_set_channel_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_set_channel_req_struct*) ilm_ptr->local_para_ptr,
                    &set_channel_req_var);
            }
            else
            {
                wps_set_channel_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_set_channel_req_struct*) ilm_ptr->local_para_ptr,
                    NULL);
            }
        }
            break;
        case MSG_ID_WPS_UNSET_CHANNEL_REQ:
        {    
            wps_unset_channel_req_struct *p = (wps_unset_channel_req_struct*)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_unset_channel_rsp(ilm_ptr->src_mod_id, p->channel_id, WPS_ERROR_NOT_READY);
                break;
            }
            wps_unset_channel_req_hdlr(ilm_ptr->src_mod_id, (wps_unset_channel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WPS_RECONFIG_CHANNEL_REQ:
        {
            wps_reconfig_channel_req_struct *p = (wps_reconfig_channel_req_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_reconfig_channel_rsp(ilm_ptr->src_mod_id, p->channel_id, WPS_ERROR_NOT_READY);
                break;
            }
            wps_reconfig_channel_req_hdlr(ilm_ptr->src_mod_id, (wps_reconfig_channel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WPS_CREATE_STREAM_CONNECTION_REQ:
            wps_create_stream_connection_req_hdlr(ilm_ptr->src_mod_id, (wps_create_stream_connection_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_CLOSE_STREAM_CONNECTION_REQ:
            wps_close_stream_connection_req_hdlr(ilm_ptr->src_mod_id, (wps_close_stream_connection_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_STREAM_DATA_SEND_REQ:
            {
                wps_stream_data_send_req_var_struct send_req_var;

                memset(&send_req_var, 0, sizeof(wps_stream_data_send_req_var_struct));
                if (ilm_ptr->peer_buff_ptr && 
                    wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id, &send_req_var, get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
                {
                    wps_stream_data_send_req_hdlr(ilm_ptr->src_mod_id, 
                        (wps_stream_data_send_req_struct*) ilm_ptr->local_para_ptr, &send_req_var);
                }
                else
                {
                    wps_stream_data_send_req_hdlr(ilm_ptr->src_mod_id, 
                        (wps_stream_data_send_req_struct*) ilm_ptr->local_para_ptr, NULL);
                }
            }
            break;
        case MSG_ID_WPS_STREAM_DATA_READ_REQ:
            wps_stream_data_read_req_hdlr(ilm_ptr->src_mod_id, (wps_stream_data_read_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_HTTP_REQ:
        {
            wps_http_req_var_struct http_req_var;

            wps_http_req_struct *p = (wps_http_req_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_http_rsp(ilm_ptr->src_mod_id, NULL, WPS_ERROR_NOT_READY, p->request_id);
                break;
            }
            memset(&http_req_var, 0, sizeof(wps_http_req_var_struct));
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &http_req_var,
                    get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_http_req_hdlr(ilm_ptr->src_mod_id, (wps_http_req_struct*) ilm_ptr->local_para_ptr, &http_req_var);
            }
            else
            {
                wps_http_req_hdlr(ilm_ptr->src_mod_id, (wps_http_req_struct*) ilm_ptr->local_para_ptr, NULL);
            }
        }
            break;
        case MSG_ID_WPS_READ_CONTENT_REQ:
        {    
            wps_read_content_req_struct *p = (wps_read_content_req_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_read_content_rsp(ilm_ptr->src_mod_id, NULL, WPS_ERROR_NOT_READY, p->request_id);
                break;
            }
            wps_read_content_req_hdlr(ilm_ptr->src_mod_id, (wps_read_content_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WPS_POST_CONTENT_RES:
        {
            wps_post_content_res_var_struct post_content_res_var;

            wps_post_content_res_struct *p = (wps_post_content_res_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_post_content_ind(ilm_ptr->src_mod_id, p->request_id, WPS_ERROR_NOT_READY, p->seq_num);
                break;
            }

            memset(&post_content_res_var, 0, sizeof(wps_post_content_res_var_struct));
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &post_content_res_var,
                    get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_post_content_res_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_post_content_res_struct*) ilm_ptr->local_para_ptr,
                    &post_content_res_var);
            }
            else
            {
                wps_post_content_res_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_post_content_res_struct*) ilm_ptr->local_para_ptr,
                    NULL);
            }
        }
            break;
        case MSG_ID_WPS_CANCEL_REQ:
        {    
            wps_cancel_req_struct *p = (wps_cancel_req_struct *)ilm_ptr->local_para_ptr;
            if( !is_wps_ready())
            {
                wps_send_cancel_rsp(ilm_ptr->src_mod_id, p->request_id, WPS_ERROR_NOT_READY);
                break;
            }
            wps_cancel_req_hdlr(ilm_ptr->src_mod_id, (wps_cancel_req_struct*) ilm_ptr->local_para_ptr);
            break;
        }
        case MSG_ID_WPS_DL_PROGRESS_RES:
            wps_dl_progress_res_hdlr(ilm_ptr->src_mod_id, (wps_dl_progress_res_struct*) ilm_ptr->local_para_ptr);
            break;
    #ifdef WAP_SEC_SUPPORT
        case MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ:
            wps_sec_get_session_info_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_get_session_info_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ:
            wps_sec_get_current_cert_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_get_current_cert_req_struct*) ilm_ptr->local_para_ptr);
            break;
	#ifdef __HTTP_INTERFACE__
        case MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_REQ:
            wps_sec_verify_cert_chain_req_hdlr(
                ilm_ptr->src_mod_id,
                (wps_sec_verify_cert_chain_req_struct*) ilm_ptr->local_para_ptr);
            break;
	#endif
        case MSG_ID_WPS_SEC_GET_CERT_IDS_REQ:
            wps_sec_get_cert_ids_req_hdlr(ilm_ptr->src_mod_id, 
                (wps_sec_get_cert_ids_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_GET_CERT_REQ:
            wps_sec_get_cert_req_hdlr(ilm_ptr->src_mod_id, 
                (wps_sec_get_cert_req_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WPS_SEC_DELETE_CA_CERT_REQ:
            if (!is_wps_ready())
            {
                wps_send_delete_ca_cert_rsp(ilm_ptr->src_mod_id, WPS_ERROR_NOT_READY);
                break;
            }           
            wps_sec_handle_delete_ca_cert(ilm_ptr->src_mod_id, 
                (wps_sec_delete_ca_cert_req_struct*) ilm_ptr->local_para_ptr);
            break;

        case MSG_ID_WPS_SEC_GET_X509_CA_CERT_REQ:
            if (!is_wps_ready())
            {
                wps_send_sec_get_x509_ca_cert_rsp(ilm_ptr->src_mod_id, 0, WPS_ERROR_NOT_READY);
                break;
            }           
            wps_sec_get_x509_ca_cert_req_hdlr(ilm_ptr->src_mod_id);
            break;

        case MSG_ID_WPS_SEC_SHOW_CONFIRM_DIALOG_RES:
            if (is_wps_ready())
            {
            wps_sec_show_confirm_dialog_res_hdlr(ilm_ptr->src_mod_id, (wps_show_confirm_dialog_res_struct*) ilm_ptr->local_para_ptr);
            }           
            break;
    #endif /* WAP_SEC_SUPPORT */ 
		case MSG_ID_WPS_HTTP_AUTH_INFO:
            if( is_wps_ready())
            {
				wps_http_auth_info_var_struct http_auth_var;
				memset(&http_auth_var, 0, sizeof(wps_http_auth_info_var_struct));
				if (ilm_ptr->peer_buff_ptr &&
					wps_pun_var_part(
						WPS_PUN_UNPACK,
						ilm_ptr->msg_id,
						&http_auth_var,
						get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
				{
				    wps_http_add_auth_info_req_hdlr(ilm_ptr->src_mod_id, (wps_http_auth_info_struct*) ilm_ptr->local_para_ptr, &http_auth_var);					
				}
				else
				{
				    wps_http_add_auth_info_req_hdlr(ilm_ptr->src_mod_id, (wps_http_auth_info_struct*) ilm_ptr->local_para_ptr, NULL);										
				}
            }
                break;
        case MSG_ID_WPS_HTTP_AUTH_RES:
            if (is_wps_ready())
            {
            wps_http_auth_res_hdlr(ilm_ptr->src_mod_id, (wps_http_auth_res_struct*) ilm_ptr->local_para_ptr);
            }           
            break;
        case MSG_ID_WPS_STATUS_QUERY_REQ:
            wps_status_query_req_hdlr(ilm_ptr->src_mod_id);
            break;
	case MSG_ID_WPS_SET_COOKIE_REQ:
            if( is_wps_ready())
            {
				wps_set_cookie_req_var_struct cookie_var;
				memset(&cookie_var, 0, sizeof(wps_set_cookie_req_var_struct));
				if (ilm_ptr->peer_buff_ptr &&
					wps_pun_var_part( WPS_PUN_UNPACK,
						          ilm_ptr->msg_id,
						          &cookie_var,
						          get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
				{
				    wps_http_set_cookie_req_hdlr(ilm_ptr->src_mod_id, (wps_set_cookie_req_struct*) ilm_ptr->local_para_ptr, &cookie_var);					
				}
				else
				{
				    wps_http_set_cookie_req_hdlr(ilm_ptr->src_mod_id, (wps_set_cookie_req_struct*) ilm_ptr->local_para_ptr, NULL);										
				}
            }
            break;
        case MSG_ID_WPS_RELEASE_ALL_REQ:
            if( !is_wps_ready())
            {
                wps_send_release_all_req_rsp(ilm_ptr->src_mod_id, WPS_ERROR_NOT_READY);
                break;
            }
            wps_http_release_all_req_hdlr(ilm_ptr->src_mod_id);
            break;
#ifdef WAP_SEC_SUPPORT
#ifdef STK_CFG_USE_MTK_TLS
        case MSG_ID_APP_TLS_NOTIFY_IND:
			wps_handle_tls_notify_ind((app_tls_notify_ind_struct*)ilm_ptr->local_para_ptr);
			break;
		case MSG_ID_APP_SOC_NOTIFY_IND:
			wps_handle_soc_notify_ind((app_soc_notify_ind_struct*)ilm_ptr->local_para_ptr);
			break;
        case MSG_ID_APP_TLS_ALERT_IND:
		    wps_handle_tls_alert_ind((app_tls_alert_ind_struct*)ilm_ptr->local_para_ptr);
			break;
        case MSG_ID_APP_TLS_INVALID_CERT_IND:
			wps_handle_tls_invalid_cert_ind((app_tls_invalid_cert_ind_struct*)ilm_ptr->local_para_ptr);
			break;
        case MSG_ID_APP_TLS_CLIENT_AUTH_IND:
			wps_handle_tls_client_auth_ind((app_tls_client_auth_ind_struct*)ilm_ptr->local_para_ptr);
			break;
#endif /* STK_CFG_USE_MTK_TLS */
#endif /*WAP_SEC_SUPPORT*/


#endif /* WPS_SUPPORT */ 
#ifdef WPS_TASK_SUPPORT
        case MSG_ID_WPS_CLEAR_REQ:
        {
            wps_clear_req_var_struct clear_req_var;
            wps_clear_req_struct *p = (wps_clear_req_struct *)ilm_ptr->local_para_ptr;                        
            memset(&clear_req_var, 0, sizeof(wps_clear_req_var_struct));
            
            if( !is_wps_ready())
            {
                wps_send_clear_rsp(ilm_ptr->src_mod_id, p->request_id, WPS_ERROR_NOT_READY);                
                break;
            }
            if (ilm_ptr->peer_buff_ptr &&
                wps_pun_var_part(
                    WPS_PUN_UNPACK,
                    ilm_ptr->msg_id,
                    &clear_req_var,
                    get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &len)) > 0)
            {
                wps_clear_req_hdlr(
                    ilm_ptr->src_mod_id,
                    (wps_clear_req_struct*) ilm_ptr->local_para_ptr,
                    &clear_req_var);
            }
            else
            {
                wps_clear_req_hdlr(ilm_ptr->src_mod_id, (wps_clear_req_struct*) ilm_ptr->local_para_ptr, NULL);
            }
    }
        break;
#endif/* WPS_TASK_SUPPORT */ 
    }


#ifdef WPS_TASK_SUPPORT
    destroy_ilm(ilm_ptr);
    MSF_wps_fsm();
#endif /* WPS_TASK_SUPPORT */ 
}

/*************************************************************
 * Test Code
 *************************************************************/
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
#ifdef WAP_SEC_SUPPORT	  
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
#endif /* 0 */ 



