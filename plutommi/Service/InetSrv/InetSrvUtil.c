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
#include "MMIDataType.h"
#include "fat_fs.h"
#include "InetSrvGprot.h"
#include "InetSrvIProt.h"



/*****************************************************************************
 * FUNCTION
 *  inet_srv_find_free_session_slot
 * DESCRIPTION
 *  this function is to find available wps context slot
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S8 inet_srv_find_free_session_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*traverse the global list and hunt for available slot*/
	for(i =0; i< INET_SRV_MAX_SESSION_CONTEXT; i++)
	{
		/*is this context free*/
		if( INET_SRV_CONTEXT_INUSE_VALUE(i) == 0 )
		{
			return i;
		}
	}
	return (S8)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_find_session_cntx_by_handle
 * DESCRIPTION
 *  this function is 
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S8 inet_srv_find_session_cntx_by_handle( U32 session_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* traverse the entire session context */
	for(cntxt_idx =0; cntxt_idx< INET_SRV_MAX_SESSION_CONTEXT; cntxt_idx++)
	{
		/* find session context based on session handle */
		if(g_inet_srv_session_cntxt[cntxt_idx].session_handle == session_handle )
		{
			return cntxt_idx;
		}
	}
	return (S8)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_session_find_free_req_slot
 * DESCRIPTION
 *  this function is 
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S8 inet_srv_session_find_free_req_slot( U8 cntxt_idx,
									    U32 session_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* find free request slot based on session context */
	for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
	{
		if( (g_inet_srv_session_cntxt[cntxt_idx].request[i] == NULL))
		{
			return i;
		}
	}
	return (S8)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_session_search_req_handle
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
srv_inet_http_req_obj_struct* inet_srv_session_search_req_handle( U32 session_handle,
												                  U32 req_handle )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntxt_idx = inet_srv_find_session_cntx_by_handle(session_handle);
	if((int *)cntxt_idx < 0)
		return NULL;

	for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
	{
		/* find free request slot based on session context */
		if( (g_inet_srv_session_cntxt[cntxt_idx].request[i] != NULL))
		{
			if(g_inet_srv_session_cntxt[cntxt_idx].request[i]->req_handle == req_handle)
			{
				return g_inet_srv_session_cntxt[cntxt_idx].request[i];
			}
		}
	}

	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_search_session_cntxt_by_channel_id
 * DESCRIPTION
 *  this function is to search the context based on channel id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S8 inet_srv_search_session_cntxt_by_channel_id (U8 channel_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* traverse the entire session context */
	for(cntxt_idx =0; cntxt_idx< INET_SRV_MAX_SESSION_CONTEXT; cntxt_idx++)
	{
		/* match session context based on channel id */
		if( INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx) == channel_id)
		{
			return cntxt_idx;
		}
	}	
	return (S8)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_search_session_cntxt_request_id
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 inet_srv_search_session_cntxt_request_id( U16 wps_req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(cntxt_idx =0; cntxt_idx< INET_SRV_MAX_REQUEST_PER_SESSION; cntxt_idx++)
	{
		if( (g_inet_srv_session_cntxt[cntxt_idx].channel_req_id == wps_req_id))
		{
			return cntxt_idx;
		}
	}

	return (S32)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_search_session_cntxt_wps_req_id
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 inet_srv_search_session_cntxt_wps_req_id( U16 wps_req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* traverse the entire session context */
	for(cntxt_idx =0; cntxt_idx< INET_SRV_MAX_SESSION_CONTEXT; cntxt_idx++)
	{
		for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
		{
			if( (g_inet_srv_session_cntxt[cntxt_idx].request[i] != NULL))
			{
				if(g_inet_srv_session_cntxt[cntxt_idx].request[i]->wps_req_id == wps_req_id)
				{
					return cntxt_idx;
				}
			}
		}
	}
	return (S32)-1;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_search_session_cntxt_wps_req_id
 * DESCRIPTION
 *  this function is to search the context based on application request id
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
srv_inet_http_req_obj_struct* inet_srv_find_http_request_object( U16 cntxt_idx,
																 U16 wps_req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
	{
		if( (g_inet_srv_session_cntxt[cntxt_idx].request[i] != NULL))
		{
			if(g_inet_srv_session_cntxt[cntxt_idx].request[i]->wps_req_id == wps_req_id)
			{
				return g_inet_srv_session_cntxt[cntxt_idx].request[i];
			}
		}
	}
	return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_session_clear_session_info
 * DESCRIPTION
 *  this function is clear global context info
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_session_clear_session_info(U32 session_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 cntxt_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* traverse the entire session context */
	for(cntxt_idx =0; cntxt_idx < INET_SRV_MAX_SESSION_CONTEXT; cntxt_idx++)
	{
		/* find session context based on session handle */
		if(g_inet_srv_session_cntxt[cntxt_idx].session_handle == session_handle )
		{
			INET_SRV_CONTEXT_INUSE_VALUE(cntxt_idx)	= 0;
			g_inet_srv_session_cntxt[cntxt_idx].session_handle = 0;
			g_inet_srv_session_cntxt[cntxt_idx].http_req_cb = NULL;
			g_inet_srv_session_cntxt[cntxt_idx].mem_alloc = NULL;
			g_inet_srv_session_cntxt[cntxt_idx].mem_free = NULL;
		}
	}
}



/*****************************************************************************
 * FUNCTION
 *  inet_srv_session_clear_channel_info
 * DESCRIPTION
 *  this function is to clear channel information
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_session_clear_channel_info(U8 cntxt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_inet_srv_session_cntxt[cntxt_idx].net_id				= 0;
    g_inet_srv_session_cntxt[cntxt_idx].timeout				= SRV_INET_DEFAULT_TIMEOUT_VALUE;
	g_inet_srv_session_cntxt[cntxt_idx].use_default			= MMI_TRUE;
	g_inet_srv_session_cntxt[cntxt_idx].use_proxy			= MMI_FALSE;
	g_inet_srv_session_cntxt[cntxt_idx].prx_port			=  0;
	g_inet_srv_session_cntxt[cntxt_idx].static_header_len	=  0;
	g_inet_srv_session_cntxt[cntxt_idx].static_header		= '\0';
	g_inet_srv_session_cntxt[cntxt_idx].conn_type			= 0;
	g_inet_srv_session_cntxt[cntxt_idx].channel_req_id		= 0;

	memset(g_inet_srv_session_cntxt[cntxt_idx].prx_ip, 0, 4);
	memset(g_inet_srv_session_cntxt[cntxt_idx].username, 0, WPS_MAX_USERNAME_LEN);
	memset(g_inet_srv_session_cntxt[cntxt_idx].password, 0, WPS_MAX_PASSWORD_LEN);

	INET_SRV_CONTEXT_STATE_VALUE(cntxt_idx)		= INET_SRV_SESSION_STATE_NULL; 
	INET_SRV_CONTEXT_CHANNEL_VALUE(cntxt_idx)	= 0xff;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_clear_req_info
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_clear_request_object( U16 cntxt_id,
								  srv_inet_http_req_obj_struct* http_req_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(http_req_obj->content_type != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_req_obj->content_type);
		http_req_obj->content_type = NULL;
	}
	if(http_req_obj->request_url != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_req_obj->request_url);
		http_req_obj->request_url = NULL;
	}
	if(http_req_obj->request_header != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_req_obj->request_header);
		http_req_obj->request_header = NULL;
	}
	if(http_req_obj->post_segment != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_req_obj->post_segment);
		http_req_obj->post_segment = NULL;
	}
	if(http_req_obj->post_path[0] != '\0')
	{
		FS_Delete(http_req_obj->post_path);
	}
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_clear_response_object
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_clear_response_object( U16 cntxt_id,
								    srv_inet_http_rsp_struct* http_rsp_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(http_rsp_obj->new_url != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_rsp_obj->new_url);
		http_rsp_obj->new_url = NULL;
	}
	if(http_rsp_obj->response_header != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_rsp_obj->response_header);
		http_rsp_obj->response_header = NULL;
	}
	if(http_rsp_obj->response_segment != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(cntxt_id, http_rsp_obj->response_segment);
		http_rsp_obj->response_segment = NULL;
	}
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_session_write_to_file
 * DESCRIPTION
 *  this function is clear request information
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 inet_srv_session_write_to_file( srv_inet_http_req_obj_struct*	http_req,
									const char *buffer,
									U32 buf_length,
									U32* no_bytes_written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 error;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    error = FS_Write(http_req->file_handle, (char*)buffer, buf_length, no_bytes_written);
	if(error != FS_NO_ERROR)
	{
		FS_Close(http_req->file_handle);
		http_req->file_handle = -1;
		return error;
	}

	return SRV_INET_OK;
}

#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/
