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
 *    inet_srv_agent.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    WPS Adaptation exported services
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================*/
#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))

#include "stdio.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "fat_fs.h"
#include "mmi_include.h"

#include "App_str.h"

#include "wps_sap.h"
#include "wps_struct.h"
#include "InetSrvIProt.h"


 /*****************************************************************************
 * FUNCTION
 *  inet_srv_send_ilm
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static void inet_srv_send_ilm( void *local_para_ptr, void *peer_buff_ptr,
							  msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send6(MOD_MMI, dst_id, WPS_APP_SAP, ilm_id, local_para_ptr, peer_buff_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wps_send_status_query_req
 * DESCRIPTION
 *  this function is send status query request to WPS module
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_status_query_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*register protocol event handler*/
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_STATUS_QUERY_RSP, (PsIntFuncPtr)inet_srv_status_query_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_READY_IND, (PsIntFuncPtr)inet_srv_ready_ind_hdlr, MMI_TRUE);	

    inet_srv_send_ilm( NULL, NULL, MSG_ID_WPS_STATUS_QUERY_REQ, MOD_WPS);
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_set_channel_req
 * DESCRIPTION
 *  this function is  to send set channel request information to WPS
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_set_channel_req(srv_inet_session_obj_struct* session_obj )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req = NULL;
    wps_set_channel_req_var_struct set_channel_req_var = {0};
    kal_uint16 pdu_length = 0;
    peer_buff_struct * peer_buff_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_channel_req = (wps_set_channel_req_struct*)
		              construct_local_para(sizeof(wps_set_channel_req_struct),
					  TD_CTRL | TD_RESET);

    set_channel_req->use_default	= session_obj->use_default;
    set_channel_req->app_id			= INET_SRV_APP_ID;
    set_channel_req->conn_type		= session_obj->conn_type;
    set_channel_req->req_id			= session_obj->channel_req_id;
    set_channel_req->net_id			= session_obj->net_id;
    set_channel_req->timeout		= session_obj->timeout;
    set_channel_req->use_proxy		= session_obj->use_proxy;
    
    if (session_obj->prx_ip[0] != '\0')
    {
        int i;
        for (i = 0; i < 4; i++)
        {
            set_channel_req->prx_addr[i] = (kal_uint8)session_obj->prx_ip[i];
        }
        set_channel_req->prx_port = session_obj->prx_port;
    }
    if (session_obj->username[0] != '\0')
    {
        strncpy((char*)set_channel_req->username, (char*)session_obj->username, WPS_MAX_USERNAME_LEN);
    }
    if (session_obj->password[0] != '\0')
    {
        strncpy((char*)set_channel_req->password, (char*)session_obj->password, WPS_MAX_PASSWORD_LEN);
    }
    /*Process Static headers*/
    if (session_obj->static_header)
    {
        set_channel_req_var.static_header_len = strlen((char*)session_obj->static_header);
        if (set_channel_req_var.static_header_len > 2000)
        {
            set_channel_req_var.static_header_len = 2000;
        }
        set_channel_req_var.static_header = session_obj->static_header;
        pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
        wps_pun_var_part(
            WPS_PUN_PACK,
            MSG_ID_WPS_SET_CHANNEL_REQ,
            &set_channel_req_var,
            get_peer_buff_pdu(peer_buff_ptr, &pdu_length));        
    }        

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_SET_CHANNEL_RSP, (PsIntFuncPtr)inet_srv_set_channel_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_TERMINATION_IND, (PsIntFuncPtr)inet_srv_wps_termination_ind_hdlr, MMI_TRUE);	

    inet_srv_send_ilm( set_channel_req, peer_buff_ptr, MSG_ID_WPS_SET_CHANNEL_REQ, MOD_WPS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wps_send_unset_channel_req
 * DESCRIPTION
 *  this function is  to send unset channel request information to WPS
 * CALLS
 *  
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_unset_channel_req( U8 channel_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *unset_channel_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    unset_channel_req = (wps_unset_channel_req_struct*)
		                 construct_local_para(sizeof(wps_unset_channel_req_struct),
						 TD_CTRL | TD_RESET);
    unset_channel_req->channel_id = channel_id;

    inet_srv_send_ilm( unset_channel_req, NULL, MSG_ID_WPS_UNSET_CHANNEL_REQ, MOD_WPS);
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_req
 * DESCRIPTION
 *  this function is to send a HTTP/WSP request.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_http_req( srv_inet_http_req_obj_struct* http_req_obj  )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req = NULL;
    wps_http_req_var_struct http_req_var = {0};    
    kal_uint16 pdu_length = 0;
    peer_buff_struct *peer_buff_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL | TD_RESET);

    http_req->request_id	= http_req_obj->wps_req_id;
    http_req->channel_id	= http_req_obj->channel_id;
    http_req->method		= http_req_obj->method;
    http_req->option		= http_req_obj->options;
    http_req->reply_type	= http_req_obj->reply_type;
    
    if (http_req_obj->post_path[0] != '\0')
    {
        app_ucs2_strncpy((kal_int8*)http_req->post_path, (kal_int8*)http_req_obj->post_path, 255);
    }    

    http_req->reply_segment_len		= http_req_obj->reply_segment_len;
    http_req->post_type				= http_req_obj->post_type;
    http_req->post_total_len		= http_req_obj->post_total_len;
    http_req->more_post				= http_req_obj->more_post;


    http_req_var.post_segment_len	= http_req_obj->post_segment_len;
    http_req_var.post_segment		= http_req_obj->post_segment;
    http_req_var.request_url_len	= http_req_obj->request_url_len;
    http_req_var.request_url		= (kal_uint8*)http_req_obj->request_url;
    http_req_var.request_header_len = http_req_obj->request_header_len;
    http_req_var.request_header		= (kal_uint8*)http_req_obj->request_header;    

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ,
		                          &http_req_var, NULL);

    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var,
		              get_peer_buff_pdu(peer_buff_ptr, &pdu_length));

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)inet_srv_http_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_AUTH_IND, (PsIntFuncPtr)inet_srv_http_auth_ind_hdlr, MMI_TRUE);	

    inet_srv_send_ilm( (void*)http_req, (void*)peer_buff_ptr,
		              MSG_ID_WPS_HTTP_REQ, MOD_WPS);

}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_release_all_req
 * DESCRIPTION
 *  this function is to send a request to release all request for a particular WPS user
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_http_release_all_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    inet_srv_send_ilm( NULL, NULL, MSG_ID_WPS_RELEASE_ALL_REQ, MOD_WPS);

}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_read_content_req
 * DESCRIPTION
 *  this function is to send request to continue to read HTTP/WSP reply content.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_read_content_req( srv_inet_http_req_obj_struct* http_req_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_req_struct *read_content_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    read_content_req=(wps_read_content_req_struct*)
		              construct_local_para(sizeof(wps_read_content_req_struct),
					  TD_CTRL | TD_RESET);

    read_content_req->request_id			= http_req_obj->wps_req_id;
    read_content_req->channel_id			= http_req_obj->channel_id;
    read_content_req->seq_num				= ++http_req_obj->seq_num;
    read_content_req->read_segnemtn_len		= http_req_obj->reply_segment_len;

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_READ_CONTENT_RSP, (PsIntFuncPtr)inet_srv_read_content_rsp_hdlr, MMI_TRUE);
	
    inet_srv_send_ilm( (void*)read_content_req, NULL,
		              MSG_ID_WPS_READ_CONTENT_REQ, MOD_WPS);
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_cancel_req
 * DESCRIPTION
 *  this function is to send a request to cancel an incomplete WSP/HTTP request.
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_cancel_req( U8 channel_id, 
							   U16 request_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_req_struct *cancel_req = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cancel_req = (wps_cancel_req_struct*) 
		         construct_local_para(sizeof(wps_cancel_req_struct),
				 TD_CTRL | TD_RESET);

    cancel_req->request_id = request_id;
    cancel_req->channel_id = channel_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_CANCEL_RSP, (PsIntFuncPtr)inet_srv_cancel_rsp_hdlr, MMI_TRUE);	
    inet_srv_send_ilm((void*)cancel_req, NULL, MSG_ID_WPS_CANCEL_REQ, MOD_WPS);  
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_clear_req
 * DESCRIPTION
 *  this function is to send a request to cancel an incomplete WSP/HTTP request.
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_clear_req( U8 channel_id, 
						      U16 request_id,
							  U8 operation,
							  U8* cache_url )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *clear_req = NULL;
    wps_clear_req_var_struct clear_cache_var;
	peer_buff_struct *peer_buff_ptr = NULL;
	kal_uint16 pdu_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_req = (wps_clear_req_struct*) 
		         construct_local_para(sizeof(wps_clear_req_struct),
				 TD_CTRL | TD_RESET);

    clear_req->request_id = request_id;
    clear_req->channel_id = channel_id;
    clear_req->operation =  operation;

	if(cache_url != NULL)
	{
        clear_cache_var.cache_url = (kal_uint8*)cache_url;
        clear_cache_var.cache_url_len = strlen((const char*)cache_url);

        pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_CLEAR_REQ, &clear_cache_var, NULL);
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        wps_pun_var_part( WPS_PUN_PACK,
                         MSG_ID_WPS_CLEAR_REQ,
                         &clear_cache_var,
                         get_peer_buff_pdu(peer_buff_ptr, &pdu_length));
	}
    inet_srv_send_ilm((void*)clear_req, peer_buff_ptr, MSG_ID_WPS_CLEAR_REQ, MOD_WPS);  
}


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_auth_res
 * DESCRIPTION
 *  this function is to handle the username/password response for HTTP authentication request
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_send_http_auth_res( U8 channel_id,
								  U16 request_id,
								  const U8* username,
								  const U8* password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct    *p;
	int len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wps_http_auth_res_struct *) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);

    p->channel_id = channel_id;
    p->request_id = request_id;

    if(username)
	{
		len = strlen((char*)username);
		kal_mem_cpy((char*)p->username, (char*)username, len);
		p->username[len]= '\0';	
	}
    if(password)
	{
		len = strlen((char*)password);
		kal_mem_cpy((char*)p->password, (char*)password, len);
		p->password[len]= '\0';	
	}

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)inet_srv_http_rsp_hdlr, MMI_TRUE);	
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_AUTH_IND, (PsIntFuncPtr)inet_srv_http_auth_ind_hdlr, MMI_TRUE);		

    inet_srv_send_ilm(p, NULL, MSG_ID_WPS_HTTP_AUTH_RES, MOD_WPS);    
}
#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/