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
 *   InetSrvIProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Interface file to let user use inet service functionality
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================*/

#ifndef INET_SRV_PROT_H
#define INET_SRV_PROT_H

#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))

/* header files inclusion */
#include "MMIDataType.h"
#include "wps_struct.h"
#include "InetSrvGprot.h"


#define INET_SRV_MAX_SESSION_CONTEXT		4
#define INET_SRV_MAX_REQUEST_PER_SESSION 	4
#define INET_SRV_SESSION_CNXT_INUSE			1

#define INET_SRV_REPLY_SEGMENT_LENGTH		1024
#define INET_SRV_APP_ID						10

#define INET_SRV_ERROR_INVALID_CHANNEL_ID	-1				
#define INET_SRV_ERROR_INVALID_REQUEST_ID   -2 


/* These structures are invisible to the user application */

typedef struct http_obj
{
    U32 req_handle;
	U16 wps_req_id;
	U8 channel_id;
    U8 method;               /* HTTP Method Constant */
    U8 reply_type;           /* Reply type (wps_data_type_enum) */
	U8 seq_num;
	U16 req_state;
    U8 post_type;
    MMI_BOOL more_post;
    U32 options;              /* HTTP request options */
    U32 reply_segment_len;
    U16 post_path[256];
	U32 post_path_len;
    U32 post_total_len;
	U8* content_type;
	U32 content_len;
	U32 request_url_len;     /* The request URL length */
    U8* request_url;         /* The request URL */
    U32 request_header_len;  /* The request header length */
    U8* request_header;      /* The request header */
    U32 post_segment_len;
    U8* post_segment;
	S32 file_handle;
	srv_inet_http_rsp_struct *rsp_object;

} srv_inet_http_req_obj_struct;

typedef struct session_obj
{
    U32 net_id;          /* Network ID */
    U32 timeout;         /* Timeout value (second) */
    U8 prx_ip[4];        /* Proxy IP address */
    U16 prx_port;        /* Proxy port number. 0 means default proxy 8080. */
    U8 username[WPS_MAX_USERNAME_LEN];     /* Username for the proxy. Only ASCII is allowed and NULL terminated. */
    U8 password[WPS_MAX_PASSWORD_LEN];     /* Password for the proxy. Only ASCII is allowed and NULL terminated. */
    U32 static_header_len;   /* The length of static header */
    U8* static_header;       /* static header */
	U8  state;		/*state variable*/
	U8  inuse;		/*is context is being used*/
	U8  channel_id;	/*channel id*/
	U8 app_id;
	U8 conn_type;        /* Connection type */
	MMI_BOOL use_default;       
    MMI_BOOL use_proxy;         /* Use proxy or not */
    U32 session_handle;
	U16 channel_req_id;
    srv_inet_http_req_obj_struct	*request[INET_SRV_MAX_REQUEST_PER_SESSION];
    srv_inet_http_req_callback		http_req_cb;
	inet_srv_mem_alloc_cb			mem_alloc;
	inet_srv_mem_free_cb			mem_free;
    
} srv_inet_session_obj_struct;

#define INET_SRV_CONTEXT_SESSION_HANDLE(x)		g_inet_srv_session_cntxt[x].session_handle
#define INET_SRV_CONTEXT_REQUEST_HANDLE(x,y)	g_inet_srv_session_cntxt[x].request[y]
#define INET_SRV_CONTEXT_STATE_VALUE(x)			g_inet_srv_session_cntxt[x].state
#define INET_SRV_CONTEXT_INUSE_VALUE(x)			g_inet_srv_session_cntxt[x].inuse
#define INET_SRV_CONTEXT_CHANNEL_VALUE(x)       g_inet_srv_session_cntxt[x].channel_id
#define INET_SRV_CONTEXT_USE_PROXY(x)           g_inet_srv_session_cntxt[x].use_proxy
#define INET_SRV_CONTEXT_SET_TIMEOUT(x)         g_inet_srv_session_cntxt[x].timeout
#define INET_SRV_CONTEXT_SET_NETID(x)			g_inet_srv_session_cntxt[x].net_id
#define INET_SRV_CONTEXT_USE_DEFAULT(x)			g_inet_srv_session_cntxt[x].use_default
#define INET_SRV_CONTEXT_SET_CALLBACK(x)        g_inet_srv_session_cntxt[x].http_req_cb
#define INET_SRV_CONTEXT_MEM_ALLOC(x, SIZE)	    g_inet_srv_session_cntxt[x].mem_alloc(SIZE)
#define INET_SRV_CONTEXT_MEM_FREE(x, PTR)		g_inet_srv_session_cntxt[x].mem_free(PTR)


/*For each context, these value ll depicts its state*/
typedef enum
{
	INET_SRV_SESSION_STATE_NULL = 1,   
	INET_SRV_SESSION_STATE_WAIT_QUERY_RSP,
	INET_SRV_SESSION_STATE_WPS_READY,
	INET_SRV_SESSION_STATE_WAIT_CHANNEL_RSP,
	INET_SRV_SESSION_STATE_SEND_HTTP_REQUEST,
	INET_SRV_SESSION_STATE_INVALID
} inet_srv_cntxt_state_enum;

/*For each context, these value ll depicts its state*/
typedef enum
{
	INET_SRV_HTTP_REQ_STATE_NULL = 1,   
	INET_SRV_HTTP_REQ_STATE_READY_TO_SEND,
	INET_SRV_HTTP_REQ_STATE_INVALID
} inet_srv_http_req_state_enum;


/*Global context of INET SRV SESSION contains info about all channels*/
extern srv_inet_session_obj_struct g_inet_srv_session_cntxt[];
/*global variable to assign unique value */
extern U32 inet_srv_handle;


/*Internal Exported fucntion protoype */
extern MMI_BOOL inet_srv_status_query_rsp_hdlr(void *msg);
extern MMI_BOOL inet_srv_set_channel_rsp_hdlr(void *msg);
extern MMI_BOOL inet_srv_wps_termination_ind_hdlr(void);
extern MMI_BOOL inet_srv_unset_channel_rsp_hdlr(void *msg);
extern MMI_BOOL inet_srv_cancel_rsp_hdlr(void *msg);
extern MMI_BOOL inet_srv_ready_ind_hdlr(void);
extern MMI_BOOL inet_srv_http_rsp_hdlr( void *msg, U8 src_id, void *ilm_p);
extern MMI_BOOL inet_srv_http_auth_ind_hdlr(void *msg);
extern MMI_BOOL inet_srv_read_content_rsp_hdlr(void *msg, U8 src_id,  void *ilm_p);



/*Utility functions*/
extern S8 inet_srv_find_free_session_slot(void);
extern S8 inet_srv_find_session_cntx_by_handle( U32 session_handle);
extern S8 inet_srv_session_find_free_req_slot( U8 cntxt_idx,
											   U32 session_handle);
extern srv_inet_http_req_obj_struct* inet_srv_session_search_req_handle( U32 session_handle,
												                         U32 req_handle );

extern S8 inet_srv_search_session_cntxt_by_channel_id (U8 channel_id );
extern S32 inet_srv_search_session_cntxt_request_id( U16 wps_req_id );
extern S32 inet_srv_search_session_cntxt_wps_req_id( U16 wps_req_id );
extern void inet_srv_session_clear_session_info(U32 session_handle);
extern void inet_srv_session_clear_channel_info(U8 cntxt_idx);


extern srv_inet_http_req_obj_struct* inet_srv_find_http_request_object( U16 cntxt_idx,
																	    U16 wps_req_id );

extern void inet_srv_clear_request_object( U16 cntxt_id,
								           srv_inet_http_req_obj_struct* http_req_obj);

extern void inet_srv_clear_response_object( U16 cntxt_id,
								            srv_inet_http_rsp_struct* http_rsp_obj);

extern S32 inet_srv_session_write_to_file( srv_inet_http_req_obj_struct*	http_req,
									             const char *buffer,
										   U32 buf_length,
									       U32* no_bytes_written);


/*Response handlers coming from WPS*/

extern void inet_srv_process_wps_ready_response(U32 cntxt_idx);
extern void inet_srv_process_set_channel_response(U32 cntxt_idx);
extern MMI_BOOL inet_srv_set_session_query_response(void);
extern void srv_inet_session_process_request(U32 cntxt_idx);
extern void inet_srv_abort_session(U8 index, S32 error_cause);


/*************************************************************************
 * INET SERVICE  -- INTERFACE FUNCTION PROTOTYPE
 ************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_status_query_req
 * DESCRIPTION
 *  this function is to send the query of WPS ready status. Before using this, 
 *  the app. need to register above callback function. The application shouldn't proceed
 * until it recieve successful query response.
 * CALLS
 *  
 * PARAMETERS
 *  src_app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void inet_srv_send_status_query_req(void);

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
extern void inet_srv_send_set_channel_req( srv_inet_session_obj_struct* session_obj );

/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_unset_channel_req
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
extern void inet_srv_send_unset_channel_req( U8 channel_id );


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_req
 * DESCRIPTION
 *  this function is to send a request 
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void inet_srv_send_http_req(srv_inet_http_req_obj_struct* http_req_obj);


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_release_all_req
 * DESCRIPTION
 *  this function is to send a request to release all request for a particular WPS user
 * CALLS
 *  
 * PARAMETERS
 *  src_mod_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void inet_srv_send_http_release_all_req(void);


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_read_content_req
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
extern void inet_srv_send_read_content_req(srv_inet_http_req_obj_struct* http_req_obj);


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_cancel_req
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
extern void inet_srv_send_cancel_req( U8 channel_id, 
								      U16 request_id );


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_clear_req
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
extern void inet_srv_send_clear_req( U8 channel_id, 
								     U16 request_id,
								     U8 operation,
								     U8  *cache_url);


/*****************************************************************************
 * FUNCTION
 *  inet_srv_send_http_auth_res
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
extern void inet_srv_send_http_auth_res( U8 channel_id,       
										 U16 request_id,
								         const U8 *auth_username, 
								         const U8 *auth_password );

#endif /* INET_SRV_PROT_H */
#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/