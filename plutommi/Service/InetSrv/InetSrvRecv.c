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
 *    InetSrvRecv.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Inet Services recevies response from WPS adaptation
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
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "fat_fs.h"

    /* Basic data type */
#include "wps_sap.h"
#include "wps_struct.h"
#include "InetSrvGprot.h"
#include "InetSrvIProt.h"

static srv_inet_event_notify_struct g_event_msg = {0, NULL};
static srv_inet_http_data_ind_struct g_data_obj = {NULL, 0, 0};
/*****************************************************************************
 * FUNCTION
 *  inet_srv_status_query_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_status_query_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_status_query_rsp_struct *status_query_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	status_query_rsp = (wps_status_query_rsp_struct*) msg;
    ASSERT(status_query_rsp);

	if (status_query_rsp->status == WPS_READY_STATUS_OK)
    {	
		inet_srv_set_session_query_response();
    }
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_set_channel_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_set_channel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 index;
	S32 temp;
	wps_set_channel_rsp_struct *channel_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	channel_rsp = (wps_set_channel_rsp_struct*) msg;
	ASSERT(channel_rsp);

	temp = inet_srv_search_session_cntxt_request_id(channel_rsp->req_id);
	if(temp < 0)
		return MMI_FALSE;
	index = temp;
	if(channel_rsp->result == WPS_OK)
	{
		/*update the wps context with channel id*/	
		INET_SRV_CONTEXT_CHANNEL_VALUE(index) = channel_rsp->channel_id;
		srv_inet_session_process_request(index);
	}
	else
	{
		inet_srv_abort_session(index, SRV_INET_ERROR_INVALID_PARAM);
	}
	
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  inet_srv_unset_channel_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_unset_channel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_http_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_http_rsp_hdlr( void *msg, kal_uint8 src_id, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_http_rsp_struct *http_rsp;
    wps_http_rsp_var_struct http_rsp_var = {0};
    kal_uint16 pdu_length = 0;
	S8 index;
	S32 temp;
    ilm_struct  *ilm_ptr;
	srv_inet_http_rsp_struct *http_rsp_obj;			
	srv_inet_http_req_obj_struct* http_obj;
	kal_uint32 content_type_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	http_rsp = (wps_http_rsp_struct*) msg;
    ASSERT(http_rsp);

    ilm_ptr = (ilm_struct*)ilm_p;
	/*search wps context based on channel id which is always unique */
	temp = inet_srv_search_session_cntxt_wps_req_id(http_rsp->request_id);
	if(temp < 0)
		return MMI_FALSE; 
	index = temp;
	if (ilm_ptr->peer_buff_ptr)
    {
        wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id, &http_rsp_var,
			             get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length));
    }

	http_obj = inet_srv_find_http_request_object(index, http_rsp->request_id);
	if(http_obj == NULL)
	{
		return MMI_FALSE; 
	}

	http_rsp_obj = (srv_inet_http_rsp_struct*)INET_SRV_CONTEXT_MEM_ALLOC(index, sizeof(srv_inet_http_rsp_struct));
	if(http_rsp_obj == NULL)
	{
		inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		return MMI_TRUE; 
	}
	memset(http_rsp_obj, 0, sizeof(srv_inet_http_rsp_struct));	

	if(http_rsp->result != WPS_OK)
	{
	    http_rsp_obj->result = -(http_rsp->result);
	    http_rsp_obj->more = MMI_FALSE;		
	}
	else
	{
	http_rsp_obj->result = http_rsp->result;
	http_rsp_obj->more = http_rsp->more;
	}
	http_rsp_obj->status = http_rsp->status;
	http_rsp_obj->cause = http_rsp->cause;

	if(http_rsp->result == WPS_OK)
	{
	content_type_len = strlen((const char*)http_rsp->content_type);
	http_rsp_obj->content_length = http_rsp->content_length;
	if(content_type_len > 0)
	{
		memcpy(http_rsp_obj->content_type, http_rsp->content_type, content_type_len );
		http_rsp_obj->content_type[content_type_len] = '\0';
	}
	
	if( (http_rsp_var.new_url != NULL) && (http_rsp_var.new_url_len != 0))
	{
		http_rsp_obj->new_url = (kal_uint8*)INET_SRV_CONTEXT_MEM_ALLOC(index, http_rsp_var.new_url_len + 1);	
		if(http_rsp_obj->new_url == NULL)
		{
			inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		    return MMI_TRUE; 
		}
		memcpy (http_rsp_obj->new_url, http_rsp_var.new_url, http_rsp_var.new_url_len);
		http_rsp_obj->new_url[http_rsp_var.new_url_len] = '\0';
		http_rsp_obj->new_url_len = http_rsp_var.new_url_len;
	}

	if( (http_rsp_var.reply_header != NULL) && (http_rsp_var.reply_header_len != 0))
	{
		http_rsp_obj->response_header = (kal_uint8*)INET_SRV_CONTEXT_MEM_ALLOC(index, http_rsp_var.reply_header_len + 1);	
		if(http_rsp_obj->response_header == NULL)
		{
			/*free object memory*/
			INET_SRV_CONTEXT_MEM_FREE(index,http_rsp_obj->new_url);
			inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		    return MMI_TRUE;
		}
		memcpy (http_rsp_obj->response_header, http_rsp_var.reply_header, http_rsp_var.reply_header_len);
		http_rsp_obj->response_header[http_rsp_var.reply_header_len] = '\0';
		http_rsp_obj->response_header_len = http_rsp_var.reply_header_len;
	}

	if( (http_rsp_var.reply_segment != NULL) && (http_rsp_var.reply_segment_len != 0))
	{
		http_rsp_obj->response_segment = (kal_uint8*)INET_SRV_CONTEXT_MEM_ALLOC(index, http_rsp_var.reply_segment_len + 1);	
		if(http_rsp_obj->response_segment == NULL)
		{
			/*free object memory*/
			INET_SRV_CONTEXT_MEM_FREE(index,http_rsp_obj->new_url);
			INET_SRV_CONTEXT_MEM_FREE(index,http_rsp_obj->response_header);
			inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		    return MMI_TRUE; 
		}
		memcpy (http_rsp_obj->response_segment, http_rsp_var.reply_segment, http_rsp_var.reply_segment_len);
		http_rsp_obj->response_segment[http_rsp_var.reply_segment_len] = '\0';
		http_rsp_obj->response_segment_len = http_rsp_var.reply_segment_len;
	}
	}
	http_obj->rsp_object = http_rsp_obj;

	g_event_msg.event_id = SRV_INET_EVENT_RESONSE_RECEIVED;
	g_event_msg.data = (void*)http_rsp_obj;

	/*callback application handler to get unset channel result*/
	if(g_inet_srv_session_cntxt[index].http_req_cb )
	{
			/*clear request object*/
			inet_srv_clear_request_object(index, http_obj);
		
		if(http_rsp->more == KAL_TRUE)
			{
			inet_srv_send_read_content_req( http_obj );
		}
		/*send http response through callback*/
 		(*g_inet_srv_session_cntxt[index].http_req_cb)(http_obj->req_handle, &g_event_msg);
		/*is more data would come */
	}
	/* clear response object information */
	inet_srv_clear_response_object( index, http_rsp_obj);
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_read_content_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_read_content_rsp_hdlr(void *msg, kal_uint8 src_id, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wps_read_content_rsp_struct *read_content_rsp;
    wps_read_content_rsp_var_struct read_content_rsp_var = {0};
    kal_uint16 pdu_length = 0;   
	S8 index;	
	S32 temp;
    ilm_struct  *ilm_ptr;
	srv_inet_http_req_obj_struct* http_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	read_content_rsp = (wps_read_content_rsp_struct*) msg;
    ASSERT(read_content_rsp);

    ilm_ptr = (ilm_struct*)ilm_p;

	/*search wps context based on channel id which is always unique */
	temp = inet_srv_search_session_cntxt_wps_req_id(read_content_rsp->request_id);
	if(temp < 0)
		return MMI_FALSE; 
	index = temp;
	http_obj = inet_srv_find_http_request_object(index, read_content_rsp->request_id);
	if(http_obj == NULL)
	{
		return MMI_FALSE; 
	}

    if (ilm_ptr->peer_buff_ptr)
    {
        wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id,
			             &read_content_rsp_var, 
						 get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &pdu_length));
    }    

	if( (read_content_rsp_var.reply_segment!= NULL) && (read_content_rsp_var.reply_segment_len != 0))
	{
		g_data_obj.buffer = (kal_uint8*)INET_SRV_CONTEXT_MEM_ALLOC(index, read_content_rsp_var.reply_segment_len + 1);	
		if(g_data_obj.buffer == NULL)
		{
			inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		    return MMI_TRUE; 
		}
		memcpy (g_data_obj.buffer, read_content_rsp_var.reply_segment, read_content_rsp_var.reply_segment_len);
		g_data_obj.buffer[read_content_rsp_var.reply_segment_len] = '\0';
		g_data_obj.buf_len = read_content_rsp_var.reply_segment_len;
	}

		if(read_content_rsp->more == KAL_FALSE)
		{
		g_data_obj.flag = SRV_INET_FLAG_READ_COMPLETED;
		}
		else
		{
		g_data_obj.flag = SRV_INET_FLAG_DATA_AVAILABLE;
	}

	g_event_msg.event_id = SRV_INET_EVENT_DATA_INDICATION;
	g_event_msg.data = (void*)&g_data_obj;

	/*callback application handler to get unset channel result*/
	if(g_inet_srv_session_cntxt[index].http_req_cb )
	{
			/*send http response through callback*/
 			(*g_inet_srv_session_cntxt[index].http_req_cb)(http_obj->req_handle, &g_event_msg);			
		/*is more data is about to come*/
		if(read_content_rsp->more == KAL_TRUE)
			{
			inet_srv_send_read_content_req( http_obj );
			}
		}
	/*free response memory chunk which has been delivered to application*/
	if(g_data_obj.buffer != NULL)
	{
		INET_SRV_CONTEXT_MEM_FREE(index, g_data_obj.buffer);
		g_data_obj.buffer = NULL;
	}
    return MMI_TRUE; 
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_http_auth_ind_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_http_auth_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 index;
	S32 temp;
	wps_http_auth_ind_struct *auth_ind;
	srv_inet_http_auth_ind_struct *auth_data;
	srv_inet_http_req_obj_struct* http_obj;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	auth_ind = (wps_http_auth_ind_struct*) msg;
    ASSERT(auth_ind);

	temp = inet_srv_search_session_cntxt_wps_req_id(auth_ind->request_id);
	if(temp < 0)
		return MMI_FALSE; 
	index = temp;
	http_obj = inet_srv_find_http_request_object(index, auth_ind->request_id);
	if(http_obj == NULL)
	{
		return MMI_FALSE; 
	}

	auth_data = (srv_inet_http_auth_ind_struct*)INET_SRV_CONTEXT_MEM_ALLOC( index,
		                                        sizeof(srv_inet_http_auth_ind_struct));
	if(auth_data == NULL)
	{
		inet_srv_abort_session(index, SRV_INET_ERROR_MEM_NOT_AVAILABLE);
		return MMI_TRUE; 
	}

	auth_data->auth_type	= auth_ind->auth_type;
	auth_data->realm_len	= auth_ind->realm_len;
	auth_data->username_len = auth_ind->username_len;

	if(auth_ind->realm_len > 0)
		memcpy (auth_data->realm, auth_ind->realm, auth_data->realm_len);

	if (auth_ind->username_len > 0)
		memcpy (auth_data->username, auth_ind->username, auth_data->username_len);


	g_event_msg.event_id = SRV_INET_EVENT_AUTHENITCATE;
	g_event_msg.data = (void*)auth_data;

	/*callback application handler to get unset channel result*/
	if(g_inet_srv_session_cntxt[index].http_req_cb != NULL )
	{
 		(*(g_inet_srv_session_cntxt[index].http_req_cb))(http_obj->req_handle, &g_event_msg);
		INET_SRV_CONTEXT_MEM_FREE(index, auth_data);
	}
    return MMI_TRUE; 
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_cancel_rsp_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_cancel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_ready_ind_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_ready_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int resp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	resp = inet_srv_set_session_query_response();
	if(resp)
    {	
		return MMI_TRUE;
    }	
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_wps_termination_ind_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inet_srv_wps_termination_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index;    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*check all WPS context which wants to know query status*/
	for(index =0; index< INET_SRV_MAX_SESSION_CONTEXT; index++)
	{
		inet_srv_abort_session(index, SRV_INET_ERROR_INTERNAL_ERROR);
	}
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  inet_srv_abort_session
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void inet_srv_abort_session(U8 index, S32 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;
	srv_inet_http_session_aborted_struct* abort_obj = NULL;
	srv_inet_http_req_obj_struct* http_obj = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*check all WPS context which wants to know query status*/
	if(INET_SRV_CONTEXT_INUSE_VALUE(index) == INET_SRV_SESSION_CNXT_INUSE)
	{
		abort_obj = (srv_inet_http_session_aborted_struct*)INET_SRV_CONTEXT_MEM_ALLOC( index,
													sizeof(srv_inet_http_session_aborted_struct));
		abort_obj->error_code = error_cause;


		g_event_msg.event_id = SRV_INET_EVENT_ABORTED;
		g_event_msg.data = (void*)abort_obj;

		for(i =0; i< INET_SRV_MAX_REQUEST_PER_SESSION; i++)
		{
			if( (g_inet_srv_session_cntxt[index].request[i] != NULL))
			{
				http_obj = g_inet_srv_session_cntxt[index].request[i];
				/*callback application handler to get unset channel result*/
				if(g_inet_srv_session_cntxt[index].http_req_cb != NULL )
				{
 					(*(g_inet_srv_session_cntxt[index].http_req_cb))(http_obj->req_handle, &g_event_msg);
				}
			}
		}
		srv_inet_session_close(INET_SRV_CONTEXT_SESSION_HANDLE(index));
	}
}

#endif /*#if ((defined __HTTP_INTERFACE__ ) ||(defined WAP_SEC_SUPPORT))*/