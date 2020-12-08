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
 *    InetSrvMain.c
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
/* header files inclusion */
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "wps_struct.h"
#include "InetSrvGprot.h"
#include "InetSrvIProt.h"

#include "App_str.h"
#include "fat_fs.h"

#define INET_SRV_TEMP_WPS_FILE_PREFIX	"z:\\@wap\\temp\\"
#define INET_SRV_TEMP_FILE_EXT	".bin"


/*Global context of INET SRV SESSION contains info about all channels*/
srv_inet_session_obj_struct g_inet_srv_session_cntxt[INET_SRV_MAX_SESSION_CONTEXT] = {0, 0, 0, 0};

/*global variable to assign unique value */
U32 inet_srv_handle;

/*****************************************************************************
 * FUNCTION
 *  srv_inet_session_new
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_session_new( inet_srv_mem_alloc_cb mem_alloc,
						  inet_srv_mem_free_cb mem_free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 index;
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(mem_alloc == NULL || mem_free == NULL)
		return SRV_INET_ERROR_INVALID_PARAM;
	
	
	/*create new session */
    index = inet_srv_find_free_session_slot();
	if((int *)index >= 0)
	{
        /*Initialize all the elements to default values*/
		g_inet_srv_session_cntxt[index].prx_port			= 0;
		g_inet_srv_session_cntxt[index].static_header_len	= 0;
		g_inet_srv_session_cntxt[index].static_header		= NULL;
		g_inet_srv_session_cntxt[index].conn_type			= WPS_CONN_TYPE_HTTP;
		g_inet_srv_session_cntxt[index].app_id				= INET_SRV_APP_ID;

		memset(g_inet_srv_session_cntxt[index].prx_ip, 0, 4);
		memset(g_inet_srv_session_cntxt[index].username, 0, WPS_MAX_USERNAME_LEN);
		memset(g_inet_srv_session_cntxt[index].password, 0, WPS_MAX_PASSWORD_LEN);
		
		g_inet_srv_session_cntxt[index].channel_req_id		= ++inet_srv_handle;
		g_inet_srv_session_cntxt[index].session_handle      = ++inet_srv_handle; 
		g_inet_srv_session_cntxt[index].mem_alloc           = mem_alloc;
		g_inet_srv_session_cntxt[index].mem_free            = mem_free;
		
		INET_SRV_CONTEXT_USE_DEFAULT(index)					= MMI_TRUE;
		INET_SRV_CONTEXT_SET_NETID(index)					= 0;
		INET_SRV_CONTEXT_SET_TIMEOUT(index)					= SRV_INET_DEFAULT_TIMEOUT_VALUE;
		INET_SRV_CONTEXT_USE_PROXY(index)					= MMI_FALSE;
		INET_SRV_CONTEXT_SET_CALLBACK(index)				= NULL;
		INET_SRV_CONTEXT_STATE_VALUE(index)					= INET_SRV_SESSION_STATE_NULL; 
		INET_SRV_CONTEXT_INUSE_VALUE(index)					= INET_SRV_SESSION_CNXT_INUSE;
		INET_SRV_CONTEXT_CHANNEL_VALUE(index)				= 0xff; 
		
		for(i=0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
		{
			g_inet_srv_session_cntxt[index].request[i] = NULL;
		}
		
		inet_srv_send_status_query_req();
		INET_SRV_CONTEXT_STATE_VALUE(index)	= INET_SRV_SESSION_STATE_WAIT_QUERY_RSP; 

		return inet_srv_handle;
	}
	return SRV_INET_ERROR_CREATING_SESSION;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_session_set_proxy_param
 * DESCRIPTION
 *  this function is to de-initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_session_set_proxy_param( U32 session_handle,
								      const U8* prx_ip,
                                      U16 prx_port,
                                      const U8* username,
                                      const U8* password )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*find session index based on session handle*/
	index = inet_srv_find_session_cntx_by_handle(session_handle);
	if((int *)index < 0)
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;

	strncpy( (char*)g_inet_srv_session_cntxt[index].prx_ip, (char*)prx_ip, 4);

	strncpy( (char*)g_inet_srv_session_cntxt[index].username,
		    (char*)username, WPS_MAX_USERNAME_LEN);

	strncpy( (char*)g_inet_srv_session_cntxt[index].password,
		    (char*)password, WPS_MAX_PASSWORD_LEN);

	g_inet_srv_session_cntxt[index].prx_port	= prx_port;
	INET_SRV_CONTEXT_USE_PROXY(index) = MMI_TRUE;
	/* search for session based on session_handle */
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_session_set_config_param
 * DESCRIPTION
 *  this function is to find available wps context slot
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_session_set_config_param( U32 session_handle,
                                       const U8* common_header,
									   U32 netid, 
									   U16 timeout)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 index;
	U32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*find session index based on session handle*/
	index = inet_srv_find_session_cntx_by_handle(session_handle);
	if((int *)index < 0)
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;

	INET_SRV_CONTEXT_USE_DEFAULT(index)					= MMI_FALSE;
	INET_SRV_CONTEXT_SET_NETID(index)					= netid;
	INET_SRV_CONTEXT_SET_TIMEOUT(index)					= timeout;

	if(common_header)
	{
	len = strlen((char*)common_header);

	g_inet_srv_session_cntxt[index].static_header = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(index, len+1);
	if(g_inet_srv_session_cntxt[index].static_header == NULL)
	{
		return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
	}
	memcpy(g_inet_srv_session_cntxt[index].static_header, common_header, len);
	g_inet_srv_session_cntxt[index].static_header[len] = '\0';
	g_inet_srv_session_cntxt[index].static_header_len	= len;
	}
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_session_close
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_session_close( U32 session_handle )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 cntxt_idx;
	S16 i;
	srv_inet_http_req_obj_struct* http_req_obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*find session index based on session handle*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle(session_handle);
	if((int *)cntxt_idx < 0)
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;

	/* check if session is being in use */
	if( INET_SRV_CONTEXT_INUSE_VALUE(cntxt_idx) == INET_SRV_SESSION_CNXT_INUSE )
	{
		if(INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx) != 0xff)	
		{
			inet_srv_send_unset_channel_req( INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx) );
			/*clear all request information*/
			for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
			{
				http_req_obj = g_inet_srv_session_cntxt[cntxt_idx].request[i];
				if( http_req_obj != NULL)
				{
					/*clear request object*/
					inet_srv_clear_request_object( cntxt_idx, http_req_obj);
					if(http_req_obj->rsp_object !=NULL)
					{
						/* clear response object information */
						inet_srv_clear_response_object( cntxt_idx, http_req_obj->rsp_object);
						/*free response object memory*/
						INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req_obj->rsp_object);
					}
					/*free request object memory*/
					INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req_obj);
					g_inet_srv_session_cntxt[cntxt_idx].request[i] = NULL;
				}
			}
			inet_srv_session_clear_channel_info( cntxt_idx );
		}
		inet_srv_session_clear_session_info(session_handle);
	}
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_new
 * DESCRIPTION
 *  this function is to search the context based on src app id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_new( U32 session_handle, 
                           U8 method,
						   U32 options,
                           const U8* req_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 cntxt_idx;
	S8 req_idx;
	srv_inet_http_req_obj_struct*	http_req;
	U16	url_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	req_idx = inet_srv_session_find_free_req_slot( cntxt_idx, session_handle);
	if((int *)req_idx < 0)
	{
		return SRV_INET_ERROR_CREATING_REQUEST;
	}

	http_req = INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, sizeof (srv_inet_http_req_obj_struct));
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
	}
	
	/*create request object*/
	memset(http_req, 0, sizeof(srv_inet_http_req_obj_struct));

	http_req->method = method;
	http_req->options = options;
	
	url_len = strlen((char *)req_url);
	if(url_len == 0)
	{
		/*free object memory*/
		INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req);
		return SRV_INET_ERROR_INVALID_URL;
	}

	http_req->request_url = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, url_len + 1);	
	if(http_req->request_url == NULL)
	{
		/*free object memory*/
		INET_SRV_CONTEXT_MEM_FREE(cntxt_idx,http_req);
		return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
	}
	memcpy (http_req->request_url, req_url, url_len);
	http_req->request_url[url_len] = '\0';
	http_req->request_url_len = url_len;


	http_req->file_handle = -1;

	INET_SRV_CONTEXT_REQUEST_HANDLE(cntxt_idx,req_idx) = http_req;

	http_req->req_handle = ++inet_srv_handle;

	http_req->req_state  = INET_SRV_HTTP_REQ_STATE_NULL; 

	return http_req->req_handle;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_send_request
 * DESCRIPTION
 *  this function is to search the context based on channel id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_send_request( U32 session_handle,
							    U32 req_handle,
								const char *content_type,
								const char *req_body,
								U32 req_length,
                                const U8* req_header,
								srv_inet_http_req_callback http_request_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct* http_req;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}

	if(content_type !=NULL)
	{
		http_req->content_len = strlen((char*)content_type);

		http_req->content_type = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, http_req->content_len + 1);	
		if(http_req->content_type == NULL)
		{
			/*free object memory*/
			return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
		}
		memcpy (http_req->content_type, content_type, http_req->content_len);
		http_req->content_type[http_req->content_len] = '\0';
	}

	if( req_header != NULL)
	{
		http_req->request_header_len = strlen((char*)req_header);

		http_req->request_header = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, http_req->request_header_len + 1);	
		if(http_req->request_header == NULL)
		{
			/*free object memory*/
			INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->content_type);
			return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
		}
		memcpy (http_req->request_header, req_header, http_req->request_header_len);
		http_req->request_header[http_req->request_header_len] = '\0';
	}
	
	if( req_body != NULL)
	{
		http_req->post_segment_len = req_length;

		http_req->post_segment = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, req_length + 1);	
		if(http_req->post_segment == NULL)
		{
			/*free object memory*/
			INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->content_type);
			INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->request_header);
			return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
		}
		memcpy (http_req->post_segment, req_body, req_length);
     	http_req->post_segment[req_length] = '\0';
	}

	http_req->wps_req_id			= (++inet_srv_handle) + 100;
	http_req->reply_type			= WPS_DATA_TYPE_BUFFER;
	http_req->reply_segment_len		= INET_SRV_REPLY_SEGMENT_LENGTH;
	http_req->post_type				= WPS_DATA_TYPE_BUFFER;

	INET_SRV_CONTEXT_SET_CALLBACK(cntxt_idx) = http_request_cb;
	http_req->req_state = INET_SRV_HTTP_REQ_STATE_READY_TO_SEND;

	if(INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx) == INET_SRV_SESSION_STATE_SEND_HTTP_REQUEST)
	{
		inet_srv_send_http_req(http_req);
	}
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_send_request_ext
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_send_request_ext( U32 session_handle,
								    U32 req_handle,
									const char *content_type,
									const char *req_body,
									U32 req_length,
                                    const U8* req_header,
									srv_inet_http_req_callback http_request_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct* http_req;
	S8 cntxt_idx;
	S32 error = SRV_INET_OK;
	U32 no_bytes_written = 0;
	char post_file_ascii[64] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(http_request_cb == NULL)
		return SRV_INET_ERROR_INVALID_CALLBACK;
	
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}

	/*Is content type NULL*/
	if(content_type !=NULL)
	{
		http_req->content_len = strlen((char*)content_type);

		http_req->content_type = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, http_req->content_len + 1);	
		if(http_req->content_type == NULL)
		{
			/*free object memory*/
			return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
		}
		memcpy (http_req->content_type, content_type, http_req->content_len);
		http_req->content_type[http_req->content_len] = '\0';
	}

	/*does user has provided request headers*/
	if( req_header != NULL)
	{
		http_req->request_header_len = strlen((char*)req_header);

		http_req->request_header = (U8*)INET_SRV_CONTEXT_MEM_ALLOC(cntxt_idx, http_req->request_header_len + 1);	
		if(http_req->request_header == NULL)
		{
			/*free object memory*/
			INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->content_type);
			return SRV_INET_ERROR_MEM_NOT_AVAILABLE;
		}
		memcpy (http_req->request_header, req_header, http_req->request_header_len);
		http_req->request_header[http_req->request_header_len] = '\0';
	}
	

	sprintf(post_file_ascii, "%s%d%s",  INET_SRV_TEMP_WPS_FILE_PREFIX, ++inet_srv_handle, INET_SRV_TEMP_FILE_EXT);

	app_asc_str_to_ucs2_str((kal_int8*)http_req->post_path, (kal_int8*)post_file_ascii);

	http_req->file_handle = FS_Open( http_req->post_path, FS_READ_WRITE | FS_CREATE );	

    if (http_req->file_handle < 0)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->request_header);
					/*free object memory*/
		INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->content_type);
		return SRV_INET_ERROR_FILE_ACCESS;
	}
	
	/*register callback function for http response*/
	INET_SRV_CONTEXT_SET_CALLBACK(cntxt_idx) = http_request_cb;

	http_req->wps_req_id			= (++inet_srv_handle) + 100;
	http_req->reply_type			= WPS_DATA_TYPE_BUFFER;
	http_req->reply_segment_len		= INET_SRV_REPLY_SEGMENT_LENGTH;
	http_req->post_type				= WPS_DATA_TYPE_FILE;
	http_req->post_path_len			= strlen(post_file_ascii);
	http_req->more_post				= MMI_FALSE;


	error = inet_srv_session_write_to_file( http_req, req_body,
									        req_length, &no_bytes_written);

	if(error != SRV_INET_OK )
		return SRV_INET_ERROR_FILE_ACCESS;

	http_req->post_total_len		= no_bytes_written;
	
	return error;

}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_write_data
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_write_data( U32 session_handle,
								  U32 req_handle,
								  const char *buffer,
								  U32 buf_length,
								  U32* no_bytes_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req;
	S8 cntxt_idx;
	S32 error = SRV_INET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}

	error = inet_srv_session_write_to_file( http_req, buffer,
									        buf_length, no_bytes_written);
	
	if(error != SRV_INET_OK )
		return SRV_INET_ERROR_FILE_ACCESS;	

	http_req->post_total_len += (*no_bytes_written);

	return error;

}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_write_data_completed
 * DESCRIPTION
 *  this function is to search the context based on external request id
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_write_data_completed( U32 session_handle,
										    U32 req_handle )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}

	 FS_Close(http_req->file_handle);
	 http_req->file_handle = -1;

	http_req->req_state  = INET_SRV_HTTP_REQ_STATE_READY_TO_SEND; 

	if(INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx) == INET_SRV_SESSION_STATE_SEND_HTTP_REQUEST)
	{
		inet_srv_send_http_req(http_req);
	}
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_set_cookies
 * DESCRIPTION
 *  this function is to search the context based on external request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_set_cookies( U32 session_handle,
								   U32 req_handle,
								   U8* cookieName,
								   U8* CookieData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_send_auth_data
 * DESCRIPTION
 *  this function is to clear channel information
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_send_auth_data( U32 session_handle,
									  U32 req_handle,
			                          const U8* username,
			                          const U8* password )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}

	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}
	
	inet_srv_send_http_auth_res( INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx),
								 http_req->wps_req_id,
								 username, password );
	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_req_cancel_req
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_req_cancel_req( U32 session_handle,
								  U32 req_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req;
	S8 cntxt_idx;
	S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*is session handle valid, if yes, find global session context*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle( session_handle);
	if((int *)cntxt_idx < 0)
	{
		return SRV_INET_ERROR_INVALID_SESSION_HANDLE;
	}
	/*search http request object based on request handle*/
	http_req = inet_srv_session_search_req_handle(session_handle, req_handle);	
	if(http_req == NULL)
	{
		return SRV_INET_ERROR_INVALID_REQUEST_HANDLE;
	}

	inet_srv_send_cancel_req( INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx), http_req->wps_req_id );

	/*clear request object*/
	inet_srv_clear_request_object( cntxt_idx, http_req);
	if(http_req->rsp_object !=NULL)
	{
		/* clear response object information */
		inet_srv_clear_response_object( cntxt_idx, http_req->rsp_object);
		/*free response object memory*/
		INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req->rsp_object);
		http_req->rsp_object = NULL;
	}

	for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
	{
		if(g_inet_srv_session_cntxt[cntxt_idx].request[i] == http_req)
		{
			g_inet_srv_session_cntxt[cntxt_idx].request[i] = NULL;
		}
	}
	/*free request object memory*/
	INET_SRV_CONTEXT_MEM_FREE(cntxt_idx, http_req);


	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_send_clear_cache_req
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_send_clear_cache_req( U8 clear_auth_op,
    								    U8  *cache_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inet_srv_send_clear_req( 0, 0, clear_auth_op, cache_url);

	return SRV_INET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_send_clear_auth_req
 * DESCRIPTION
 *  this function is to register callback function
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_send_clear_auth_req( U8 clear_auth_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inet_srv_send_clear_req( 0, 0, clear_auth_op, NULL);

	return SRV_INET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_inet_http_send_clear_cookies_req
 * DESCRIPTION
 *  this function is send status query request to WPS module
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_inet_http_send_clear_cookies_req( U8 clear_cookie_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	inet_srv_send_clear_req( 0, 0, clear_cookie_op, NULL);

	return SRV_INET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_inet_session_process_request
 * DESCRIPTION
 *  this function is send status query request to WPS module
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_inet_session_process_request(U32 cntxt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8  session_state;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	session_state = INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx);

	switch (session_state)
	{
		case INET_SRV_SESSION_STATE_WPS_READY:
			inet_srv_process_wps_ready_response(cntxt_idx);
			break;
		case INET_SRV_SESSION_STATE_WAIT_CHANNEL_RSP:	
			inet_srv_process_set_channel_response(cntxt_idx);
			break;
		default:
			break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_set_session_query_response
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_set_session_query_response(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cntxt_idx;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(cntxt_idx =0; cntxt_idx< INET_SRV_MAX_SESSION_CONTEXT; cntxt_idx++)
	{
		/* find session context based on session handle */
		if(INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx) == INET_SRV_SESSION_STATE_WAIT_QUERY_RSP )
		{
			INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx)	= INET_SRV_SESSION_STATE_WPS_READY; 
			srv_inet_session_process_request(cntxt_idx);
			return MMI_TRUE;
		}
	}	
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_process_set_channel_response
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_process_set_channel_response(U32 cntxt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_inet_http_req_obj_struct*	http_req_obj = NULL;
	U8 i;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx) = INET_SRV_SESSION_STATE_SEND_HTTP_REQUEST;

	/* find request, which are ready to be sent*/
	/* find free request slot based on session context */
	for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
	{
		http_req_obj = g_inet_srv_session_cntxt[cntxt_idx].request[i];
		if( http_req_obj != NULL)
		{
			http_req_obj->channel_id = INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx);
			if(http_req_obj->req_state == INET_SRV_HTTP_REQ_STATE_READY_TO_SEND)
			{
				inet_srv_send_http_req(http_req_obj);
			}
		}
	}

}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_process_wps_ready_response
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_process_wps_ready_response(U32 cntxt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	inet_srv_send_set_channel_req( &g_inet_srv_session_cntxt[cntxt_idx]);
	INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx) = INET_SRV_SESSION_STATE_WAIT_CHANNEL_RSP;
}
#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/
