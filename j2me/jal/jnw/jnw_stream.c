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
 *  jnw_stream.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifdef __J2ME_STREAM_SUPPORT__

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

#include "jnw_internal.h"

/* Network */
#include "soc_api.h"
#include "soc2tcpip_struct.h"

static j2me_stream_struct j2me_stream[J2ME_STREAM_MAX_NUMBER] = 
                                {{J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},
                                 {J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},
                                 {J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},{J2ME_STREAM_INVALID},
                                 {J2ME_STREAM_INVALID}};
                                 
static jnw_stream_result_struct j2me_stream_result = {0,0};
static jnw_stream_send_result_struct j2me_stream_send_result = {0,0,0};
static jnw_stream_read_result_struct j2me_stream_read_result = {0,0,0,KAL_FALSE,0};
static kal_uint8* j2me_stream_read_data = NULL;
static kal_uint32 J2ME_async_stream_msgid = 0;
static kal_bool flag_wait_async_stream_msgid = KAL_FALSE;
extern kal_eventgrpid g_java_event_group_2;

/*****************************************************************************
 * FUNCTION
 *  readStreamAsyncEvent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long readStreamAsyncEvent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group, ret_msgid;
    kal_status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    flag_wait_async_stream_msgid = KAL_TRUE;

    result = kal_retrieve_eg_events(g_java_event_group_2, 0x8000, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

    if (result == KAL_NOT_PRESENT)
    {
        return (0);    /* IO_WOULDBLOCK */
    }
    else
    {
        ret_msgid = J2ME_async_stream_msgid;
        J2ME_async_stream_msgid = 0;
        flag_wait_async_stream_msgid = KAL_FALSE;

        /* 2nd bit notify complete retreive async event */
        kal_set_eg_events(g_java_event_group_2, 0x10000, KAL_OR);

        return ret_msgid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  j2me_stream_reset_read_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_stream_reset_read_data()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_RESET_NATIVE_DATA);

    if (j2me_stream_read_data != NULL)
    {
        jvm_free(j2me_stream_read_data);
        j2me_stream_read_data = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  j2me_stream_send_ilm
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
static void j2me_stream_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_WPS:
            sap_id = J2ME_WAP_SAP;
            break;
        default:
            sap_id = J2ME_WAP_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_JASYN);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_JASYN, dst_id, sap_id, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  j2me_stream_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stream_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 j2me_stream_search(kal_int16 stream_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for ( ; i < J2ME_STREAM_MAX_NUMBER; i++)
    {
        if (j2me_stream[i].id == stream_id)
        {
            return i;
        }
    }    

    return J2ME_STREAM_MAX_NUMBER;
}


/*****************************************************************************
 * FUNCTION
 *  j2me_stream_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stream_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_stream_remove(kal_uint8 stream_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_REMOVE, stream_id);
    
    i = j2me_stream_search((kal_int16)stream_id);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_REMOVE_2, stream_id);
        return;
    }

    j2me_stream[i].id = J2ME_STREAM_INVALID;

    return;
}

/*****************************************************************************
 * FUNCTION
 *  j2me_stream_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stream_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_stream_add(kal_uint8 stream_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    kal_int16 id = (kal_int16)stream_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_ADD, stream_id);
    
    i = j2me_stream_search((kal_int16) J2ME_STREAM_INVALID);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        ASSERT(0);
    }

    j2me_stream[i].id = id;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  j2me_stream_close_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_stream_close_stream(kal_uint8 stream_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_close_stream_connection_req_struct *close_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_CLOSE_STREAM, stream_id);

    
    close_req = (wps_close_stream_connection_req_struct*) construct_local_para(sizeof(wps_close_stream_connection_req_struct), TD_CTRL);
    close_req->channel_id = stream_id;
    j2me_stream_send_ilm(close_req, NULL, MSG_ID_WPS_CLOSE_STREAM_CONNECTION_REQ, MOD_WPS);

    return;
}

/*****************************************************************************
 * FUNCTION
 *  j2me_stream_response_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_stream_response_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_RESPONSE_HANDLER);

    if (ilm_ptr->msg_id == MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND)
    {
        wps_stream_connection_closed_ind_struct *p = (wps_stream_connection_closed_ind_struct*) ilm_ptr->local_para_ptr;
        
        kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_CLOSE_IND, p->channel_id);

        j2me_stream_remove(p->channel_id);

        return;
    }

    if (J2ME_async_stream_msgid && flag_wait_async_stream_msgid)
    {
        /* Pedning async event */
        kal_uint32 event_group, polling = 0;
        kal_status result;

        while (1)
        {
            /* 2nd bit indicate wait pending async event consumed */
            result = kal_retrieve_eg_events(g_java_event_group_2, 0x10000, KAL_OR_CONSUME, &event_group, KAL_NO_SUSPEND);

            if (result != KAL_NOT_PRESENT || polling++ >= 100)
            {
                break;
            }
            /* To avoid deadlock and complicated timer control, use polling */
            kal_sleep_task(1);
        }
    }

    J2ME_async_stream_msgid = ilm_ptr->msg_id;

    switch (ilm_ptr->msg_id)
    {

        case MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP:
        {
            wps_create_stream_connection_rsp_struct *p = (wps_create_stream_connection_rsp_struct*) ilm_ptr->local_para_ptr;

            if (p->result == WPS_OK)
            {
                j2me_stream_add(p->channel_id);
            }

            j2me_stream_result.result = p->result;
            j2me_stream_result.channel_id = p->channel_id;
        }
            break;

        case MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP:
        {
            wps_close_stream_connection_rsp_struct *p = (wps_close_stream_connection_rsp_struct*) ilm_ptr->local_para_ptr;
            
            if (p->result == WPS_OK)
            {
                j2me_stream_remove(p->channel_id);
            }

            j2me_stream_result.result = p->result;
            j2me_stream_result.channel_id = p->channel_id;
        }
            break;

        case MSG_ID_WPS_STREAM_DATA_SEND_RSP:
        {
            wps_stream_data_send_rsp_struct *p = (wps_stream_data_send_rsp_struct*) ilm_ptr->local_para_ptr;
            
            j2me_stream_send_result.result = p->result;
            j2me_stream_send_result.channel_id = p->channel_id;
            j2me_stream_send_result.seq_num = p->seq_num;
        }
            break;

        case MSG_ID_WPS_STREAM_DATA_READ_RSP:
        {
            wps_stream_data_read_rsp_struct *p = (wps_stream_data_read_rsp_struct*) ilm_ptr->local_para_ptr;
            wps_stream_data_read_rsp_var_struct read_rsp_var;
            kal_uint16 pdu_length;            

            j2me_stream_reset_read_data();            
            
            j2me_stream_read_result.channel_id = p->channel_id;
            j2me_stream_read_result.result = p->result;
            j2me_stream_read_result.more = p->more;
            j2me_stream_read_result.seq_num = p->seq_num;

            if (p->result == WPS_OK && ilm_ptr->peer_buff_ptr != NULL)
            {
                if (wps_pun_var_part
                        (WPS_PUN_UNPACK, ilm_ptr->msg_id, &read_rsp_var,
                         get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length)) > 0)
                {
                    j2me_stream_read_result.read_data_length = read_rsp_var.length;

                    j2me_stream_read_data = (kal_uint8*) jvm_malloc(j2me_stream_read_result.read_data_length);
                    
                    if (j2me_stream_read_data == NULL)
                    {
                        j2me_stream_read_result.result = JNW_STREAM_NO_RESOURCE;
                    }
                    else
                    {
                        memcpy(
                            j2me_stream_read_data,
                            read_rsp_var.data,
                            j2me_stream_read_result.read_data_length);
                    }
                }
                else
                {
                    j2me_stream_read_result.read_data_length = 0;                                    
                }                
            }
            else
            {
                j2me_stream_read_result.read_data_length = 0;                                    
            }  
        }
            break;

        default:
            break;

    }

    /* notify J2ME thread to process coming async event */
    kal_set_eg_events(g_java_event_group_2, 0x8000, KAL_OR);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_open_stream_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channelType     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_stream_open_stream_req
                (kal_bool use_java_setting, 
        		 kal_uint8 conn_type, 
        		 kal_uint8 addr[4], 
        	   	 kal_uint16 port, 
        	   	 kal_uint16 domain_length, 
        	     kal_uint8* domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_create_stream_connection_req_struct *set_channel_req;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_OPEN_STREAM_REQ, use_java_setting, conn_type, domain_length);
    
    i = j2me_stream_search((kal_int16) J2ME_STREAM_INVALID);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        return JNW_STREAM_NO_RESOURCE;
    }

    if (domain_length > J2ME_STREAM_MAX_DOMAIN_LENGTH)
    {
        return JNW_STREAM_INVALID_PARAMETER;
    }

    set_channel_req = (wps_create_stream_connection_req_struct*) construct_local_para(sizeof(wps_create_stream_connection_req_struct), TD_CTRL);

    if (use_java_setting == KAL_FALSE)
    {
        set_channel_req->use_default = KAL_TRUE;
    }
    else
    {
        set_channel_req->use_default = KAL_FALSE;

        set_channel_req->net_id = jam_mvm_get_account_id(0);
    }        

    set_channel_req->conn_type = conn_type;    

	for (i = 0; i < 4;i++)
    {
        set_channel_req->addr[i] = addr[i];
    }

    set_channel_req->port = port;

    memset(set_channel_req->domain,0,sizeof(set_channel_req->domain));    

    if (domain_length > 0)
    {
        memcpy(set_channel_req->domain,domain,domain_length);    
    }

    j2me_stream_send_ilm(set_channel_req, NULL, MSG_ID_WPS_CREATE_STREAM_CONNECTION_REQ, MOD_WPS);

    return JNW_STREAM_OK;

}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_close_stream_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_stream_close_stream_req(kal_uint8 channel_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_CLOSE_STREAM_REQ, channel_id);
    
    i = j2me_stream_search((kal_int16) channel_id);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        return JNW_STREAM_CLOSED_STREAM;
    }

    j2me_stream_close_stream (channel_id);

    return JNW_STREAM_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_send_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_id                         [IN]        
 *  seq_num                     [IN]        
 *  length                      [IN]        
 *  data                             [IN]         
 * RETURNS
 *  
 *****************************************************************************/
int jnw_stream_send_data_req
        (kal_uint8 channel_id, 
         kal_uint8 seq_num, 
         kal_uint32 length, 
         kal_uint8* data )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    wps_stream_data_send_req_struct *send_req;
    peer_buff_struct *peer_buff_ptr;
    wps_stream_data_send_req_var_struct send_req_var;
    kal_uint16 pdu_length;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_SEND_STREAM_REQ, channel_id, length);
    
    i = j2me_stream_search((kal_int16) channel_id);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        return JNW_STREAM_CLOSED_STREAM;
    }
    
    if (length > 2000)
    {
        return JNW_STREAM_INVALID_PARAMETER;
    }

    send_req = (wps_stream_data_send_req_struct*) construct_local_para(sizeof(wps_stream_data_send_req_struct), TD_CTRL);

    send_req->channel_id = channel_id;
    send_req->seq_num = seq_num;

    send_req_var.length = (kal_uint32) length;
    send_req_var.data = (kal_uint8*) data;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_STREAM_DATA_SEND_REQ, &send_req_var, NULL);

    /* Add one more byte to avoid allocating empty peer buffer */
    peer_buff_ptr = construct_peer_buff((pdu_length + 1), 0, 0, TD_CTRL);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_STREAM_DATA_SEND_REQ, &send_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));

    j2me_stream_send_ilm(send_req, peer_buff_ptr, MSG_ID_WPS_STREAM_DATA_SEND_REQ, MOD_WPS);

    return JNW_STREAM_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_read_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id     [IN]        
 *  seq_no      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jnw_stream_read_data_req
        (kal_uint8 channel_id, 
         kal_uint8 seq_num, 
         kal_uint32 read_length )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    wps_stream_data_read_req_struct *read_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_READ_STREAM_REQ, channel_id, read_length);
    
    i = j2me_stream_search((kal_int16) channel_id);

    if (i >= J2ME_STREAM_MAX_NUMBER)
    {
        return JNW_STREAM_CLOSED_STREAM;
    }
    
    if (read_length > 2000)
    {
        return JNW_STREAM_INVALID_PARAMETER;
    }
    
    read_req =
        (wps_stream_data_read_req_struct*) construct_local_para(sizeof(wps_stream_data_read_req_struct), TD_CTRL);

    read_req->channel_id = channel_id;

    read_req->seq_num = seq_num;
    read_req->read_length = read_length;

    j2me_stream_send_ilm(read_req, NULL, MSG_ID_WPS_STREAM_DATA_READ_REQ, MOD_WPS);

    return JNW_STREAM_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_check_response_primitive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int jnw_stream_check_response_primitive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned long message_id;
    int result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    message_id = readStreamAsyncEvent();

    switch (message_id)
    {
        case MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP:
        {
            result = MSG_WPS_CREATE_STREAM_CONNECTION_RSP;
        }
            break;

        case MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP:
        {
            result = MSG_WPS_CLOSE_STREAM_CONNECTION_RSP;
        }
            break;

        case MSG_ID_WPS_STREAM_DATA_SEND_RSP:
        {
            result = MSG_WPS_STREAM_DATA_SEND_RSP;
        }
            break;

        case MSG_ID_WPS_STREAM_DATA_READ_RSP:
        {
            result = MSG_WPS_STREAM_DATA_READ_RSP;
        }
            break;

        default:
        {
            result = -1;
        }
            break;

    }
    
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_CHECK_RESPONSE_PRIMITIVE, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_open_stream_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jnw_stream_open_stream_get_result (jnw_stream_result_struct* result )

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_OPEN_STREAM_RESULT);
    result->result = j2me_stream_result.result;
    result->channel_id = j2me_stream_result.channel_id;
}

/*****************************************************************************
 * FUNCTION
 *  jnw_stream_close_stream_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jnw_stream_close_stream_get_result	(jnw_stream_result_struct* result )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_CLOSE_STREAM_RESULT);
    result->result = j2me_stream_result.result;
    result->channel_id = j2me_stream_result.channel_id;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_send_data_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jnw_stream_send_data_get_result (jnw_stream_send_result_struct* result )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_SEND_RESULT);
    
    result->result = j2me_stream_send_result.result;
    result->channel_id =  j2me_stream_send_result.channel_id;
    result->seq_num = j2me_stream_send_result.seq_num;
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_send_data_get_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jnw_stream_read_data_get_result (jnw_stream_read_result_struct* result,kal_uint8* data )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_READ_RESULT);
    
    result->result = j2me_stream_read_result.result;
    result->channel_id =  j2me_stream_read_result.channel_id;
    result->seq_num = j2me_stream_read_result.seq_num;
    result->more = j2me_stream_read_result.more;
    result->read_data_length = j2me_stream_read_result.read_data_length;

    if (j2me_stream_read_data != NULL)
    {
        memcpy(data, j2me_stream_read_data, j2me_stream_read_result.read_data_length);
        j2me_stream_reset_read_data();
    }
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  finalizeStream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void finalizeStream()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_FINALIZE_INTERNAL);

    for (; i < J2ME_STREAM_MAX_NUMBER; i++)
    {
        if (j2me_stream[i].id != J2ME_STREAM_INVALID)
        {
            j2me_stream_close_stream((kal_uint8)j2me_stream[i].id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jnw_stream_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jnw_stream_finalize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_FINALIZE);
    finalizeStream();
}


/*****************************************************************************
 * FUNCTION
 *  is_stream_activated
 * DESCRIPTION
 *  get if there is any activated stream.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if some stream is activated, FALSE otherwise.
 *****************************************************************************/
kal_bool is_stream_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < J2ME_STREAM_MAX_NUMBER; i++)
    {
        if (j2me_stream[i].id != J2ME_STREAM_INVALID)
        {
            result = KAL_TRUE;
            break;
        }
    }
    
    kal_trace(TRACE_GROUP_3, FUNC_J2ME_STREAM_IS_ACTIVATE, result);
    
    return result;
}
#endif /* __J2ME_STREAM_SUPPORT__ */

