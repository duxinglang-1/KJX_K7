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
 *    vmhttps.c
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"

#if defined(__MRE_SAL_WPS__)

#include "vmsock.h"
#include "mmi_include.h"
#include "wps_sap.h"
#include "wps_struct.h"
#include "vmhttps.h"
#include "vmwps.h"
#include "cbm_api.h"
#include "mmi_rp_app_mre_def.h"


/*****************************************************************************
 * FUNCTION
 *  mre_wps_register_wps_cntxt_and_callback
 * DESCRIPTION
 *  this function is to register callback function
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 vm_https_register_wps_cntxt_and_callback(
                        VMINT apn,
						mre_wps_send_set_channel_rsp_cb set_channel_rsp_cb,
						mre_wps_unset_channel_rsp_cb unset_channel_cb,
						mre_wps_send_release_all_req_rsp_cb release_all_req_cb,
						mre_wps_send_wps_termination_ind_cb terminal_ind_cb,
						mre_wps_send_http_rsp_cb http_rsp_cb,
						mre_wps_send_read_content_rsp_cb read_content_rsp_cb,
						mre_wps_send_cancel_rsp_cb cancel_rsp_cb,
						mre_wps_send_status_query_rsp_cb status_query_rsp_cb)
{
    return mre_wps_register_wps_cntxt_and_callback( 
                                             apn,
                    						 set_channel_rsp_cb,
                    						 unset_channel_cb,
                    						 release_all_req_cb,
                    						 terminal_ind_cb,
                    						 http_rsp_cb,
                    						 read_content_rsp_cb,
                    						 cancel_rsp_cb,
                    						 status_query_rsp_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_set_channel_req
 * DESCRIPTION
 *  this function is  to send set channel request information to WPS
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 vm_https_send_set_channel_req( 
                                        VMUINT16 req_id,    /* Request ID */
                                        VMUINT8 use_proxy,   /* Use proxy or not */
                                        VMUINT8 prx_ip[4],  /* Proxy IP address */
                                        VMUINT16 prx_port,  /* Proxy port number. 0 means default proxy 8080. */
                                        VMUINT8 *username,  /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 username_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT8 *password,    /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 password_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT8 *server_auth_username, /* Username for the origin server. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 server_auth_username_len, /*length should not exceed 128 character excluding NULL character*/
                                        VMUINT8 *server_auth_password,    /* Password for the origin server. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 server_auth_password_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT32 static_header_len,   /* The length of static header */
                                        VMUINT8 *static_header       /* static header */ )

{
    return mre_wps_send_set_channel_req(KAL_FALSE, WPS_CONN_TYPE_HTTP,
        							   req_id, 
        							   60, (kal_bool)use_proxy,
        							   prx_ip, prx_port,
        							   username, username_len,
        							   password, password_len,
        							   server_auth_username,
        							   server_auth_username_len,
        							   server_auth_password,   
        							   server_auth_password_len,
           							   static_header_len,
        							   static_header );
}


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_unset_channel_req
 * DESCRIPTION
 *  this function is  to send unset channel request information to WPS
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
 VMUINT8 vm_https_send_unset_channel_req(VMUINT8 channel_id )

{
    return mre_wps_send_unset_channel_req(channel_id );
}


/*****************************************************************************
 * FUNCTION
 *  vm_https_send_req
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
VMUINT8 vm_https_send_req(      VMUINT16 request_id, /* Request ID */
                                VMUINT8 method,      /* HTTP Method Constant */
                                VMUINT32 option,     /* HTTP request options */
                                VMUINT8 reply_type,  /* Reply type (wps_data_type_enum) */
                                VMUINT32 reply_segment_len,
                                VMUINT32 request_url_len, /* The request URL length */
                                VMUINT8 *request_url,     /* The request URL */
                                VMUINT32 request_header_len, /* The request header length */
                                VMUINT8 *request_header,     /* The request header */
                                VMUINT32 post_segment_len,
                                VMUINT8 *post_segment )

{
    return mre_wps_send_http_req_ext( 
							 request_id, method,      
							 option, reply_type,  
							 reply_segment_len,
							 request_url_len, 
							 request_url, request_header_len, 
							 request_header,
							 post_segment_len,
							 post_segment,
							 KAL_FALSE,
							 MRE_WPS_DATA_TYPE_BUFFER,
							 0,
							 NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_read_content_req
 * DESCRIPTION
 *  this function is to send request to continue to read HTTP/WSP reply content.
 * CALLS
 *  
 * PARAMETERS
 *  request_id              [IN]        
 *  seq_num                 [IN]         
 *  read_segnemtn_len       [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 vm_https_send_read_content_req(    VMUINT16 request_id,/* Request ID */
                                            VMUINT8 seq_num,    /* Sequence number (for debug purpose) */
                                            VMUINT32 read_segnemtn_len)

{
    return mre_wps_send_read_content_req( 
									 request_id,
									 seq_num,    
									 read_segnemtn_len);
}




/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_cancel_req
 * DESCRIPTION
 *  this function is to send a request to cancel an incomplete WSP/HTTP request.
 * CALLS
 *  
 * PARAMETERS
 *  request_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 vm_https_send_cancel_req( VMUINT16 request_id )
{
    return mre_wps_send_cancel_req(request_id );
}

extern VMINT mre_wps_reg_post_content(mre_wps_post_ind_cb cb);
VMINT vm_https_send_req_ext(VMUINT16 request_id, 
                                                VMUINT8 method, 
                                                VMUINT32 option, 
                                                VMUINT8 reply_type, 
                                                VMUINT32 reply_segment_len,
                                                VMBYTE more_post,
                                                VMUINT8 post_type,
                                                const vm_wps_http_req_var_struct * req,
                                                mre_wps_post_ind_cb cb)
{
    VMINT ret = MRE_WPS_OK;

    if (NULL == req)
    {
        return -2;
    }
    
    if (cb)
    {
        ret = mre_wps_reg_post_content(cb);
    }

    if (MRE_WPS_OK != ret)
        return -3;

        
        
    return mre_wps_send_http_req_ext( 
							 request_id, 
							 method,      
							 option, 
							 reply_type,  
							 reply_segment_len,
							 req->request_url_len, 
							 req->request_url, 
							 req->request_header_len, 
							 req->request_header,
							 req->post_segment_len,
							 req->post_segment,
							 (kal_bool)more_post,
							 (kal_bool)post_type,
							 (kal_uint32)req->num_entries,
							 req->content
							 );
}

VMINT vm_https_send_post_content_res(VMUINT16 request_id,       
                                        VMUINT8 seq_num,           
                                        VMBYTE more,               
                                        VMUINT32 post_segment_len, 
                                        VMUINT8* post_segment)
{
    return mre_wps_send_post_content_res(request_id,       
                                        seq_num,           
                                        (kal_bool)more,               
                                        post_segment_len, 
                                        post_segment);
}



void mre_https_init(void)
{
    
}


/*****************************************************************************
 * FUNCTION
 *  mre_wps_register_wps_cntxt_and_callback
 * DESCRIPTION
 *  this function is to register callback function
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 mre_https_register_wps_cntxt_and_callback(
						mre_wps_send_set_channel_rsp_cb set_channel_rsp_cb,
						mre_wps_unset_channel_rsp_cb unset_channel_cb,
						mre_wps_send_release_all_req_rsp_cb release_all_req_cb,
						mre_wps_send_wps_termination_ind_cb terminal_ind_cb,
						mre_wps_send_http_rsp_cb http_rsp_cb,
						mre_wps_send_read_content_rsp_cb read_content_rsp_cb,
						mre_wps_send_cancel_rsp_cb cancel_rsp_cb,
						mre_wps_send_status_query_rsp_cb status_query_rsp_cb)
{
    return vm_https_register_wps_cntxt_and_callback( 
                                             VM_TCP_APN_CMNET,
                    						 set_channel_rsp_cb,
                    						 unset_channel_cb,
                    						 release_all_req_cb,
                    						 terminal_ind_cb,
                    						 http_rsp_cb,
                    						 read_content_rsp_cb,
                    						 cancel_rsp_cb,
                    						 status_query_rsp_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_set_channel_req
 * DESCRIPTION
 *  this function is  to send set channel request information to WPS
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT8 mre_https_send_set_channel_req( 
                                        VMUINT16 req_id,    /* Request ID */
                                        VMUINT8 use_proxy,   /* Use proxy or not */
                                        VMUINT8 prx_ip[4],  /* Proxy IP address */
                                        VMUINT16 prx_port,  /* Proxy port number. 0 means default proxy 8080. */
                                        VMUINT8 *username,  /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 username_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT8 *password,    /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 password_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT8 *server_auth_username, /* Username for the origin server. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 server_auth_username_len, /*length should not exceed 128 character excluding NULL character*/
                                        VMUINT8 *server_auth_password,    /* Password for the origin server. Only ASCII is allowed and NULL terminated. */
                                        VMUINT8 server_auth_password_len, /*length should not exceed 40 character excluding NULL character*/
                                        VMUINT32 static_header_len,   /* The length of static header */
                                        VMUINT8 *static_header       /* static header */ )

{
    return vm_https_send_set_channel_req( req_id, 
        							   use_proxy,
        							   prx_ip, 
                                       prx_port,
        							   username, username_len,
        							   password, password_len,
        							   server_auth_username,
        							   server_auth_username_len,
        							   server_auth_password,   
        							   server_auth_password_len,
           							   static_header_len,
        							   static_header );
}


/*****************************************************************************
 * FUNCTION
 *  mre_wps_send_unset_channel_req
 * DESCRIPTION
 *  this function is  to send unset channel request information to WPS
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id              [IN]        
 *  unset_channel_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
 VMUINT8 mre_https_send_unset_channel_req(VMUINT8 channel_id )

{
    return vm_https_send_unset_channel_req(channel_id );
}


/*****************************************************************************
 * FUNCTION
 *  mre_https_send_req
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
VMUINT8 mre_https_send_req(
                                VMUINT8 channel_id,  /* Channel ID */
                                VMUINT16 request_id, /* Request ID */
                                VMUINT8 method,      /* HTTP Method Constant */
                                VMUINT32 option,     /* HTTP request options */
                                VMUINT8 reply_type,  /* Reply type (wps_data_type_enum) */
                                VMUINT32 reply_segment_len,
                                VMUINT32 request_url_len, /* The request URL length */
                                VMUINT8 *request_url,     /* The request URL */
                                VMUINT32 request_header_len, /* The request header length */
                                VMUINT8 *request_header,     /* The request header */
                                VMUINT32 post_segment_len,
                                VMUINT8 *post_segment )

{
    return vm_https_send_req( 
							 request_id, method,      
							 option, reply_type,  
							 reply_segment_len,
							 request_url_len, 
							 request_url, request_header_len, 
							 request_header,
							 post_segment_len,
							 post_segment);

}

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
VMUINT8 mre_https_send_read_content_req(
                                            VMUINT8 channel_id, /* Channel ID */
                                            VMUINT16 request_id,/* Request ID */
                                            VMUINT8 seq_num,    /* Sequence number (for debug purpose) */
                                            VMUINT32 read_segnemtn_len)

{
    return vm_https_send_read_content_req( 
									 request_id,
									 seq_num,    
									 read_segnemtn_len);
}

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
VMUINT8 mre_https_send_cancel_req(
                                   VMUINT8 channel_id, 
                                   VMUINT16 request_id )

{
    return vm_https_send_cancel_req(request_id );
}

VMINT vm_https_is_supported(void)
{
    return 0;
}


#endif /* __MRE_SAL_WPS__ */



