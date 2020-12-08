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
 *   InetSrvGprot.h
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

#ifndef __INET_SRV_GPROT_H__
#define __INET_SRV_GPROT_H__

#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))

/* header files inclusion */
#include "MMIDataType.h"


/*******************************************************************************/
/*---------------------------Macro's------------------------------------*/
/*******************************************************************************/

#define SRV_INET_DEFAULT_TIMEOUT_VALUE	     300 /*Default timeout value if application don't set it*/

#define SRV_INET_MAX_USERNAME_LEN            41 /* Max. length of the username for authenticating proxy server */
#define SRV_INET_MAX_PASSWORD_LEN            41 /* Max. length of the password for authenticating proxy server*/
#define SRV_INET_MAX_CONTENT_TYPE_LEN        256 /* Maximum size of content type buffer */
#define SRV_INET_MAX_AUTH_USERNAME_LENGTH	 129 /* Max. length of the username for authenticating origin server */
#define SRV_INET_MAX_AUTH_PASSWORD_LENGTH	 41  /* Max. length of the password for authenticating origin server*/

#define SRV_INET_DEFAULT_PRX_PORT            8080 /*Default proxy port for HTTP connection*/
#define SRV_INET_DEFAULT_WSP_CO_PORT         9201 /*Default WAP connection oriented Port*/
#define SRV_INET_DEFAULT_WSP_CL_PORT         9200 /*Deafault WAP connection less Port*/

/* HTTP authentication constants */
#define SRV_INET_HTTP_AUTH_SERVER               1  /*Server authentication*/
#define SRV_INET_HTTP_AUTH_PROXY                2  /*Proxy authentication*/
#define SRV_INET_HTTP_AUTH_TYPE_BASIC           1  /*Authentication type basic*/
#define SRV_INET_HTTP_AUTH_TYPE_DIGEST          2  /*Authentication type Digest*/

/* Clear operation constants */
#define SRV_INET_CLEAR_CACHE_URL_MATCH   		1   /*Clear Operation - Cache URL*/
#define SRV_INET_CLEAR_CACHE_URL_PREFIX  		2   /*Clear Operation - URL's which has prefix mentioned by user */
#define SRV_INET_CLEAR_CACHE_ALL         		3   /*Clear Operation - Complete cache*/

#define SRV_INET_CLEAR_AUTH_HOST         		4   /*Clear Host server authentication information*/
#define SRV_INET_CLEAR_AUTH_PROXY        		5   /*Clear Proxy server authentication information*/
#define SRV_INET_CLEAR_AUTH_ALL          		6   /*Clear Host and Proxy server authentication information*/

#define SRV_INET_CLEAR_COOKIES_ALL       		7   /*Clear all cookies information*/

/* HTTP method constants */
#define SRV_INET_HTTP_METHOD_GET     			0x40 /*HTTP method type GET*/
#define SRV_INET_HTTP_METHOD_HEAD    			0x42 /*HTTP method type HEAD*/   
#define SRV_INET_HTTP_METHOD_POST    			0x60 /*HTTP method type POST*/   
#define SRV_INET_HTTP_METHOD_PUT     			0x61 /*HTTP method type PUT*/   
#define SRV_INET_HTTP_METHOD_DELETE  			0x43 /*HTTP method type DELETE*/   


#define SRV_INET_HTTP_OPTION_NO_CACHE                  0x00000001  /*HTTP request option, no cache*/
#define SRV_INET_HTTP_OPTION_DO_NOT_CACHE_REPLY        0x00000002  /*HTTP request option, do not add reply to cache*/
#define SRV_INET_HTTP_OPTION_ALWAYS_CACHE              0x00000004  /*HTTP request option, always add reply to cache */
#define SRV_INET_HTTP_OPTION_CACHE_ONLY                0x00000008  /*HTTP request option, reply only from cache*/
#define SRV_INET_HTTP_OPTION_STALE_CACHE               0x00000010  /*HTTP request option, reply from cache even if content has expired cache*/

#define SRV_INET_HTTP_OPTION_DO_NOT_HANDLE_SERVER_AUTH 0x00008000  /*HTTP request option, do not handle authentication*/
#define SRV_INET_HTTP_OPTION_DO_NOT_HANDLE_PROXY_AUTH  0x00010000  /*HTTP request option, do not handle proxy authentication*/
#define SRV_INET_HTTP_OPTION_DO_NOT_REDIRECT           0x00020000  /*HTTP request option, do not redirect itself*/
#define SRV_INET_HTTP_OPTION_USE_LARGE_PIPE            0x40000000  /*HTTP request option, use large pipes*/
#define SRV_INET_HTTP_OPTION_FS_COMMIT                 0x80000000  /*HTTP request option, commit as soon as it write on File*/

#define SRV_INET_ERR_CAUSE_COMM_NO_RESPONSE          21 /* 'Communication' errors */ 


/*******************************************************************************/
/*---------------------------ERROR CODES------------------------------------*/
/*******************************************************************************/

#define SRV_INET_OK								0 /* Success */
#define SRV_INET_ERROR_UNKNOWN   				-1/* Unknonw error */
#define SRV_INET_ERROR_SEND                     -2/* Fail to write content error */
#define SRV_INET_ERROR_INVALID_PARAM            -3/* Invalid parameters error*/
#define SRV_INET_ERROR_INVALID_HEADER           -4 /* Invalid headers error */
#define SRV_INET_ERROR_INVALID_SESSION_HANDLE   -5 /* Invalid channel ID error*/
#define SRV_INET_ERROR_INVALID_REQUEST_HANDLE   -6 /* Invalid request ID error*/
#define SRV_INET_ERROR_INVALID_DEFAULT_PROFILE  -8 /*Invalid Profile error*/
#define SRV_INET_ERROR_INACTIVE_SESSION         -9/* Inactive channel error*/
#define SRV_INET_ERROR_INVALID_CONN_TYPE        -10/* Invalid connection type error */
#define SRV_INET_ERROR_NO_RESOURCE              -11/* Resource limitation error*/
#define SRV_INET_ERROR_ACCESS_DENY              -12/* Access deny error*/
#define SRV_INET_ERROR_PENDING_REQ_EXIST        -13/* Pending request exists error */
#define SRV_INET_ERROR_FILE_ACCESS              -13/* File system operation error */
#define SRV_INET_ERROR_REQ_ABORT                -14/* Request aborted error*/
#define SRV_INET_ERROR_NOT_FOUND                -15/* Not found error*/
#define SRV_INET_ERROR_REQ_MSG_TOO_LARGE        -16/* Message header is too large error*/
#define SRV_INET_ERROR_REQ_NOT_SUPPORT          -17/* Request is not supported error*/
#define SRV_INET_ERROR_DNS_RESOLVE              -18/* DNS error */
#define SRV_INET_ERROR_USE_PROXY                -19/* Proxy error */
#define SRV_INET_ERROR_MEM_NOT_AVAILABLE        -20 /* memory is not enough, the application should cancle all request and close the session */
#define SRV_INET_ERROR_INVALID_URL				-21 /* Invalid URL error*/
#define SRV_INET_ERROR_INVALID_CALLBACK			-22 /* Invalid callback function pointer error*/
#define SRV_INET_ERROR_INVALID_REQUEST_ID       -23 /* Invalid request ID error*/    
#define SRV_INET_ERROR_INTERNAL_ERROR           -24 /* Problem occured internally at inet service */    
#define SRV_INET_ERROR_CREATING_SESSION	        -25 /*Inet Service unable to create session*/
#define SRV_INET_ERROR_CREATING_REQUEST		-26 /*Inet Service unable to create request*/


#define SRV_INET_FLAG_DATA_AVAILABLE		1 /*flag indicates that more data is available for read*/
#define SRV_INET_FLAG_READ_COMPLETED		2  /*flag indicates that this is last chunk of data  */

/*******************************************************************************/
/*---------------------------Enumeration------------------------------------*/
/*******************************************************************************/



/* This enumeration is used to indicate the event id for which the callback function has been 
   trigerred. */
typedef enum
{
    SRV_INET_EVENT_RESONSE_RECEIVED  = 1,	/* Represent http response arrival event */
	SRV_INET_EVENT_DATA_INDICATION,			/* Represent more response data is available*/
    SRV_INET_EVENT_AUTHENITCATE,			/* Represent authentication (401 challenge) indication event */
	SRV_INET_EVENT_ABORTED,					/* Represent session aborted due to internal error e.g memory exhaust, serivce stack reset,
											   the application should clear all session context at its ends */
	SRV_INET_EVENT_ID_INVALID				/* Represent invalid event*/
    
} srv_inet_event_id_cb_enum;


/* This Structure is used to indicate that http response has been received from the server and it contains response body information*/
typedef struct
{
    S32 result;            /* Result (ERROR CODES macro's) */
    U16 status;           /* HTTP response codes */
    S32 cause;             /* Error cause if result is not ok */
    U8 content_type[256]; /* The mime type of the replied content. */

	/* The length of replied content. The Content-Length header is not a mandatory
	   header per HTTP specification. It is possible that the content length is unknown.
	  Please use the more field to know whether there is more data to be arrived*/
    U32 content_length;   

	/* Indicate if more data is needed to be retrieved. this flag is true means, 
	application needs to wait for data indication callback of type SRV_INET_EVENT_DATA_INDICATION*/ 
    MMI_BOOL more;               
    U32 new_url_len;      /* The length of new redirected URL */
    U8* new_url;          /* The new redirected URL */
    U32 response_header_len; /* The length of response header */
    U8* response_header;     /* The response header pointer */
    U32 response_segment_len;/* The response segment buffer length */
	/* The response data segment.user should copy this buffer locally as it
	   will be free after callback */
    U8* response_segment;    

}srv_inet_http_rsp_struct;

/* This Structure is used to indicate that more data is available from the server */
typedef struct
{
    U8* buffer;    /*Buffer which holds response body data pointer*/
    U32 buf_len;   /*Length of buffer*/	
	U32 flag;	  /*Flag value would be SRV_INET_FLAG_DATA_AVAILABE (more data will arrive after this chunk)
							or SRV_INET_FLAG_READ_COMPLETE (this is the last chunk, no more data will come)*/	
}srv_inet_http_data_ind_struct;


/* This Structure is used to indicate that server has thrown a 401 challenge and user need to provide username and password */
typedef struct
{
    U8 auth_type;        /* Authentication type (HTTP authentication constant) */
    U8 realm_len;        /* Realm string length */
    U8 realm[256];       /* Realm string */
    U8 username_len;     /* Username string length */
    U8 username[256];    /* Username string */
    
} srv_inet_http_auth_ind_struct;


/* This Structure is used to indicate the reason for abnormal shutdown of Inet Service */
typedef struct
{
    S32 error_code;  /*Inet service will completely abort the session , user may need to create the session again*/
} srv_inet_http_session_aborted_struct;

/* This structure is used as an argument to application callback function. All events from Inet service are sent in this callback */
typedef struct
{
    U16 event_id; /*The event id is one of the srv_inet_event_id_cb_enum */
    void* data;	  /*User may need to typecast this void* pointer according to event id*/
    
} srv_inet_event_notify_struct;


/*****************************************************************************

 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This callback function is required to receive http response from the inet service.
 * The application should register this function and in-turn the service will provide http response data structure which
 * contains information about response header and body. Based on event id, the void* data is mapped to different structure
 *
 *		Event ID										void* data
 * SRV_INET_EVENT_RESONSE_RECEIVED          pointer to srv_inet_http_rsp_struct
 * SRV_INET_EVENT_DATA_INDICATION			pointer to srv_inet_http_data_ind_struct
 * SRV_INET_EVENT_AUTHENITCATE			    pointer to srv_inet_http_auth_ind_struct
 * SRV_INET_EVENT_ABORTED					pointer to srv_inet_http_session_aborted_struct
 * 
 * In this callback function, the application needs to typecast the void* data based on event id.
 * Even in future, if service add more callback, the interface will remain the same.
 * The application need to use switch case statement based on event id and call corresponding function at it ends.
 * The user is advised not to close the session within the callback function definition otherwise the Inet service will behave abnormally.
 * 
 * PARAMETERS
 *	req_handle		:	Request handle
 *	evt				:	Notification structure which contains info about 
						what type of event occured and its data
 *
 *****************************************************************************/
typedef void (*srv_inet_http_req_callback)( U32 req_handle, 
										    srv_inet_event_notify_struct* evt);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This is a Memory allocation callback function prototype.
 * The user should provide function pointer to allocate memory. Inet service will use this callback function to allocate memory.
 * 
 * PARAMETERS
 *	block_size		:	size of block to be allocated
 *
 *****************************************************************************/
typedef void* (*inet_srv_mem_alloc_cb)(U32 block_size);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 * DESCRIPTION
 * This is a Memory de-allocation callback function prototype.
 * The user should provide function pointer to free the memory. Inet service will use this callback function to free the memory.
 * 
 * PARAMETERS
 *	mem_block		:	pointer to memory block
 *
 *****************************************************************************/
typedef void (*inet_srv_mem_free_cb)(void* mem_block);


/*******************************************************************************/
/*---------------------------HTTP session API's-----------------------------------*/
/*******************************************************************************/


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_session_new
 *
 * DESCRIPTION
 *  This function is used to create a new HTTP session object. The inet services will initializes the 
 *  session object with default values. 
 *
 * PARAMETERS
 *  mem_alloc    : [IN]    Memory allocation callback function pointer.
 *  mem_free     : [IN]    Memory free callback function pointer.
 *
 * RETURN VALUES
 *  Session object handle. if the value is positive, then successful otherwise application
 *  should try later on when the resources are availabe.
 *****************************************************************************/
extern S32 srv_inet_session_new( inet_srv_mem_alloc_cb mem_alloc,
							     inet_srv_mem_free_cb mem_free);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_session_set_proxy_param
 *
 * DESCRIPTION
 *  This function is used to set the proxy settings for a session. 
 *  If the user doesn't call this API, the inet service will not use proxy settings
 *
 * PARAMETERS
 *  session_handle  : [IN]    Session object handle.
 *  prx_ip          : [IN]    Proxy IP address.
 *  prx_port        : [IN]    Proxy port number.
 *  username        : [IN]    Username, the string should be NULL terminated and less
 *                            than or equal to SRV_INET_MAX_USERNAME_LEN.
 *  password        : [IN]    Password, the string should be NULL terminated and less
 *                            than or equal to SRV_INET_MAX_PASSWORD_LEN.
 *
 * RETURN VALUES
 *  Error code
 *****************************************************************************/
extern S32 srv_inet_session_set_proxy_param( U32 session_handle,
										     const U8* prx_ip,
                                             U16 prx_port,
                                             const U8* username,
                                             const U8* password );

/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_session_set_config_param
 *
 * DESCRIPTION
 *  This function is used to set the configuration parameter of a session. If the user doesn't call this API, 
 *  the inet service will use default data account settings.
 *
 * PARAMETERS
 *  session_handle  : [IN]    Session object handle.
 *  common_header   : [IN]    Common headers, string should be NULL terminated. 
 *  netid			: [IN]    Network account id.
 *  timeout			: [IN]    Timeout value, how long the http service should wait for server response.
 *
 * RETURN VALUES
 *  Error code.
*****************************************************************************/
extern S32 srv_inet_session_set_config_param( U32 session_handle,
                                              const U8* common_header,
											  U32 netid, 
											  U16 timeout);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_session_close
 *
 * DESCRIPTION
 *  This function is used to close the session. 
 *  The inet service will abort all pending requests using this session.
 *
 * PARAMETERS
 *  session_handle   : [IN]   Session handle.
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_session_close( U32 session_handle );



/*---------------------------HTTP Request API's-----------------------------------*/

/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_req_new
 *
 * DESCRIPTION
 *  This function is used to create a new http request object and intializes it with default value.
 *
 * PARAMETERS
 *  session_handle 	: [IN]    Session handle.
 *  method       	: [IN]    The HTTP method should be GET, POST, etc.
 *  options       	: [IN]    Various request options, like no cache, don't handle redirection etc.
 *  req_url  	    : [IN]    The destination endpoint (as a string), string should be NULL terminated. 
 
  * RETURN VALUES
 *  if return value is >0, it returns handle to the request object otherwise error.
 *****************************************************************************/
extern S32 srv_inet_http_req_new( U32 session_handle, 
                                  U8 method,
								  U32 options,
                                  const U8* req_url);
                                            

/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_send_request
 *
 * DESCRIPTION
 *  This function is used to sends a request to the server.
 *
 * PARAMETERS
 *  session_handle      : [IN]    Session handle
 *  req handle  		: [IN]    Request handle
 *  content_type  	    : [IN]    Represents MIME Type of the body,If the content_type is NULL,
 *                                the request body must be empty as well.  
 *  req_body        	: [IN]    A data buffer containing the body of the message request.
 *                                This does not allow the application to send any extra data
 *                                beyond the single buffer that was passed to this api(max 1K).
 *                                Callers that need to send extra data beyond what is normally
 *                                passed can do so by calling srv_inet_http_req_set_param_ext instead.
 *                                After the call to srv_inet_http_req_set_param_ext, 
 *                                send the remaining data by calling srv_inet_http_req_write_file.
 *                                Finally, follow up with a call to srv_inet_http_req_write_data_completed
 *                                to let service know about data completion.
 *  req_len 	        : [IN]    The length of req_body. 
 *  req_header  	    : [IN]    Request headers (as a string), and it should be NULL terminated. 
 *  http_request_cb     : [IN]    http response callback pointer. This would be called multiple
 *                                times depending upon the response.
 * RETURN VALUES
 *  error codes
 *****************************************************************************/
extern S32 srv_inet_http_send_request( U32 session_handle, 
									   U32 req_handle,
									   const char *content_type,
									   const char *req_body,
									   U32 req_length,
                                       const U8* req_header,
									   srv_inet_http_req_callback http_request_cb);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_send_request_ext
 *
 * DESCRIPTION
 *  This function is used to send request to the server when the data is too large 
 *  to be sent using POST method.
 *
 * PARAMETERS
 *  session_handle 	    : [IN]    Session handle.
 *  req handle  		: [IN]    Request handle.
 *  content_type  	    : [IN]    represents MIME Type of the request body, If content_type is NULL, 
 *                                the request body must be empty as well.  
 *  req_body        	: [IN]    A data buffer containing the body of the message request.
 *                                After the call to srv_inet_http_req_set_param_ext, user should send 
 *                                the remaining data by calling srv_inet_http_req_write_data and
 *                                finally, follow up with a call to srv_inet_http_req_write_data_completed.
 *  req_len 	        : [IN]    the byte length of req_body. 
 *  req_header  	    : [IN]    Request headers (as a string), and it should be NULL terminated. 
 *  http_request_cb     : [IN]    Http response callback pointer. This would be called multiple
 *                                times depending upon the response.
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_send_request_ext( U32 session_handle, 
										   U32 req_handle,
										   const char *content_type,
										   const char *req_body,
										   U32 req_length,
                                           const U8* req_header,
										   srv_inet_http_req_callback http_request_cb);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_req_write_data
 *
 * DESCRIPTION
 *  This function is used to send the remaining data when using srv_inet_http_send_request_ext API.
 *
 * PARAMETERS
 *  session_handle 	    : [IN]    Session handle.
 *  req handle  		: [IN]    Request handle.
 *  buffer        	    : [IN]    A data buffer containing the body of the message request.
 *  buf_length 	        : [IN]    The byte length of request body. (the length of buffer should not exceeds 2K).
 *  no_bytes_written 	: [IN]    Pointer to a variable that receives the number of bytes written to the file
 *			                      this API sets this value to zero before doing any work or error checking.
 * RETURN VALUES
 *  Error code.	
 *****************************************************************************/
extern S32 srv_inet_http_req_write_data( U32 session_handle,
									     U32 req_handle,
										 const char *buffer,
										 U32 buf_length,
										 U32* no_bytes_written);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_req_write_data_completed
 *
 * DESCRIPTION
 *  The function is used to indicate the completion of POST data to inet service. 
 * This is used along with srv_inet_http_send_request_ext API.
 *
 * PARAMETERS
 *  session_handle 	    : [IN]    Session handle
 *  req handle  		: [IN]    Request handle
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_req_write_data_completed( U32 session_handle, 
												   U32 req_handle );



/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_req_send_auth_data
 *
 * DESCRIPTION
 *  This function is used to send authentication data in response to server's challenge.
 *
 * PARAMETERS
 *  session_handle 	: [IN]    Session handle.
 *  req_handle      : [IN]    Request object handle.
 *  username  		: [IN]    Username,string should be NULL terminated.
 *  password  		: [IN]    Password, string should be NULL terminated. 
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_req_send_auth_data( U32 session_handle,
										     U32 req_handle,
			                                 const U8* username,
			                                 const U8* password );                        				 
			                                       
			                                                                                        

/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_req_cancel_req
 *
 * DESCRIPTION
 *  This function is used to cancel a http request.
 *
 * PARAMETERS
 *  session_handle 	: [IN]    Session handle.
 *  req_handle      : [IN]    Request handle.
 *
 * RETURN VALUES
 *  Error code.
*****************************************************************************/
extern S32 srv_inet_http_req_cancel_req( U32 session_handle,
									     U32 req_handle);



/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_send_clear_cache_req
 *
 * DESCRIPTION
 *  This function is used to send a clear cache request.
 *
 * PARAMETERS
 *  clear_operation : [IN]    Clear operation, use Clear operation constants OR'ed together
 *  cache_url       : [IN]    The string is mandatory if the operation is SRV_INET_CLEAR_CACHE_URL_MATCH or
 *                            SRV_INET_CLEAR_CACHE_URL_PREFIX and it should be NULL terminated string 
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_send_clear_cache_req( U8 clear_operation,
    										   U8  *cache_url);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_send_clear_auth_req
 *
 * DESCRIPTION
 *  This function is used to send clear authentication request.
 *
 * PARAMETERS
 *  clear_auth_op   : [IN]    Clear operation, use Clear operation constants OR'ed together
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_send_clear_auth_req( U8 clear_auth_op);


/*****************************************************************************
 *
 * FUNCTION
 *  srv_inet_http_send_clear_cookies_req
 *
 * DESCRIPTION
 *  This function is used to send clear cookies request.
 *
 * PARAMETERS
 *  clear_cookie_op   : [IN]    Clear cookie operation, use Clear operation constants OR'ed together
 *
 * RETURN VALUES
 *  Error code.
 *****************************************************************************/
extern S32 srv_inet_http_send_clear_cookies_req( U8 clear_cookie_op);

#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/
#endif /* __INET_SRV_GPROT_H__ */
