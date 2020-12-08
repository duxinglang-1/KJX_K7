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
 *    SampleAppAgent.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Adaptation for http/https services
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VMWPS_H
#define VMWPS_H

#include "mmi_features.h"
#include "vmswitch.h"

#if defined(__MRE_SAL_WPS__)

#include "kal_non_specific_general_types.h"
#include "vmhttps.h"
/*************************************************************************
 * WPS SERVICE  -- MACRO's And Typedef's structure definition
 ************************************************************************/


/*************************************************************************
 * WPS SERVICE  -- INTERFACE FUNCTION PROTOTYPE
 ************************************************************************/

void mre_wps_init_wps_agent_app(void);
void mre_wps_deinit_wps_agent_app(void);

/*****************************************************************************
 * FUNCTION
 *  mre_wps_register_wps_cntxt_and_callback
 * DESCRIPTION
 *  The application should(mandatory) register these wps context and callback function before requesting
 *  WPS for any service 
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mre_wps_register_wps_cntxt_and_callback( 
				kal_int32 apn,
				mre_wps_send_set_channel_rsp_cb set_channel_rsp_cb,
				mre_wps_unset_channel_rsp_cb unset_channel_cb,
				mre_wps_send_release_all_req_rsp_cb release_all_req_cb,
				mre_wps_send_wps_termination_ind_cb terminal_ind_cb,
				mre_wps_send_http_rsp_cb http_rsp_cb,
				mre_wps_send_read_content_rsp_cb read_content_rsp_cb,
				mre_wps_send_cancel_rsp_cb cancel_rsp_cb,
				mre_wps_send_status_query_rsp_cb status_query_rsp_cb);

/*****************************************************************************
 * DESCRIPTION
 * Configure a dedicated channel for HTTP/WSP requests. An channel can be 
 * configured to use proxy while  use_proxy is true. When use_proxy is true, 
 * prx_ip, prx_port, username, and password will be used to communicate with 
 * proxy server, thus prx_ip must not be 0.0.0.0 and if prx_port value 0 
 * means use default proxy port 8080. When the conn_type is 
 * WPS_CONN_TYPE_WSP_CO or WPS_CONN_TYPE_WSP_CL, then use_proxy is true 
 * default. However, if application simply wants to use current activated 
 * setting used in WAP, then just set use_default as true and ignore all 
 * other parameters. 
 * Static_header (if necessary) must be filled in 
 * WAP_PROF_CONN_TYPE_WSP_CO and the first WSP request  of some dedicated 
 * channel with connection type WSP_CONN_TYPE_WSP_CL. If application doesn't 
 * specify static_header, then WPS will use the value currently used by WAP.
 *****************************************************************************/
kal_uint8 mre_wps_send_set_channel_req(kal_bool use_default, /* Use default channel or not */
									   kal_uint8 conn_type,  /* Connection type */
									   kal_uint32 req_id,    /* Request ID */
									   kal_uint32 timeout,   /* Timeout value (second) */
									   kal_bool use_proxy,   /* Use proxy or not */
									   kal_uint8 prx_ip[4],  /* Proxy IP address */
									   kal_uint16 prx_port,  /* Proxy port number. 0 means default proxy 8080. */
									   kal_uint8 *username,  /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
									   kal_uint8 username_len, /*length should not exceed 40 character excluding NULL character*/
									   kal_uint8 *password,    /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
									   kal_uint8 password_len, /*length should not exceed 40 character excluding NULL character*/
									   kal_uint8 *server_auth_username, /* Username for the origin server. Only ASCII is allowed and NULL terminated. */
									   kal_uint8 server_auth_username_len, /*length should not exceed 128 character excluding NULL character*/
									   kal_uint8 *server_auth_password,    /* Password for the origin server. Only ASCII is allowed and NULL terminated. */
									   kal_uint8 server_auth_password_len, /*length should not exceed 40 character excluding NULL character*/
   									   kal_uint32 static_header_len,   /* The length of static header */
									   kal_uint8* static_header       /* static header */ );

/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_unset_channel_req
 * DESCRIPTION
 * Remove a configured channel identified by channel ID.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mre_wps_send_unset_channel_req( kal_uint8 channel_id );

#if 0 /* replaced by mre_wps_send_http_req_ext*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

/*****************************************************************************
* FUNCTION
*  mre_wps_send_http_req_ext
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
kal_uint8 mre_wps_send_http_req_ext(kal_uint16 request_id, kal_uint8 method,      
                                kal_uint32 option, kal_uint8 reply_type,  
                                kal_uint32 reply_segment_len,
                                kal_uint32 request_url_len, 
                                kal_uint8* request_url, kal_uint32 request_header_len, 
                                kal_uint8* request_header,
                                kal_uint32 post_segment_len,
                                kal_uint8* post_segment, 
                                kal_bool more_post,
                                kal_uint8 post_type,
                                kal_uint32 num_entries,
                                vm_wps_content_t content[WPS_MAX_MULTIPART_CONTENT_NUM]
                                );




#endif

                                
kal_uint8 mre_wps_send_post_content_res(kal_uint16 request_id,       
                                                                        kal_uint8 seq_num,           
                                                                        kal_bool more,               
                                                                        kal_uint32 post_segment_len, 
                                                                        kal_uint8* post_segment );


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_read_content_req
 * DESCRIPTION
 *  this function is to send request to continue to read HTTP/WSP reply content.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  read_content_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mre_wps_send_read_content_req(kal_uint16 request_id,/* Request ID */
										kal_uint8 seq_num,    /* Sequence number (for debug purpose) */
										/* The suggested segment data length of replied data in the peer buffer of 
										   response. 0 means use reply_segment_len in MSG_ID_WPS_HTTP_REQ or 
										   read_segment_length in previous request. */
										kal_uint32 read_segnemtn_len);


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_cancel_req
 * DESCRIPTION
 *  this function is to send a request to cancel an incomplete WSP/HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  cancel_req      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mre_wps_send_cancel_req(kal_uint16 request_id );



/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_clear_req
 * DESCRIPTION
 *  this function is to send a clear request to clear auth. or cache or cookeis info from
    centralized database
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id      [IN]        
 *  cancel_req      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mre_wps_send_clear_req(kal_uint16 request_id, kal_uint8 operation,
								 kal_uint32 cache_url_len, kal_uint8  *cache_url);

#endif /* __MRE_SAL_WPS__ */
#endif /*VMWPS_H*/
