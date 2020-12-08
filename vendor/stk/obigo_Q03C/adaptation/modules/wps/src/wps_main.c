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
 *   wps_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements WPS internal signal handler and global context
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "mmi_platform.h"
#include "fmt_struct.h"

#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_errc.h"
#include "msf_wid.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_lib.h"
#include "msf_env.h"
#include "msf_cmmn.h"

#include "stk_if.h"
#ifdef WAP_SEC_SUPPORT
#include "sec_if.h"
#include "sec_lib.h"
#endif 
#include "wps_if.h"
#include "wps_main.h"
#include "wps_struct.h"
#include "widget_extension.h"

#ifdef WPS_SUPPORT

/************************************************************
 * Global variables
 ************************************************************/

mtk_jmpbuf wps_jmp_buf;
wps_context_struct g_wps_cntx;
int wps_request_handle;


#ifdef WAP_DOWNLOAD_SPEEDUP
#define WPS_PIPE_READ_BUFF_SIZE 8192
#endif

/************************************************************
 * Global function prototype
 ************************************************************/
extern void gmms_HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

extern void wps_send_unset_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

extern void
wps_send_http_rsp(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 error_cause, kal_uint16 request_id);

extern void wps_send_set_channel_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

extern void
wps_send_read_content_rsp(
    module_type dst_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_uint16 request_id);

extern void wps_send_cancel_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause);

extern void
wps_send_post_content_ind(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause, kal_uint8 seq_num);

extern void wps_send_clear_rsp(module_type dst_id, kal_uint16 request_id, kal_uint8 error_cause);

extern void wps_send_dl_progress_ind(module_type dst_id, wps_req_info_struct *req_info, kal_uint8 status);

extern void
wps_send_push_ind(module_type dst_id, kal_uint8 *content_type, kal_uint32 content_length, kal_wchar *data_path);

extern void wps_send_wps_termination_ind(module_type dst_id);

#ifdef WAP_SEC_SUPPORT
extern void
wps_send_sec_get_session_info_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_session_info_response_t *session_info,
    kal_uint8 error_cause);

extern void
wps_send_sec_get_current_cert_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    sec_get_current_cert_response_t *current_cert,
    kal_uint8 error_cause);

extern void
wps_send_sec_get_cert_ids_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 *cert_ids);

extern void
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
    MSF_UINT8 attribute);

#ifdef __HTTP_INTERFACE__
extern void
wps_send_verify_cert_chain_rsp(
    module_type dst_id,
    sec_verify_cert_chain_response_t *rsp,
    kal_uint8 error_cause);
#endif /*__HTTP_INTERFACE__*/

extern char *wps_sec_get_issuer_str(MSF_INT16 charSet, void *issuer, int issuerLen);

extern char *wps_sec_get_sig_alg_name(void *sig_alg_name, MSF_UINT16 sig_alg_name_len);

extern void wps_send_sec_get_x509_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 total, MSF_UINT8 error_cause);
extern void wps_send_sec_show_confirm_dialog_ind( MSF_UINT8 request_id, MSF_UINT8 dialog_type,
                                           MSF_UINT8 buttons, MSF_UINT32 title_id,
                                           MSF_UINT32 text_id);
extern void wps_send_delete_ca_cert_rsp(MSF_UINT8 dst_id, MSF_UINT8 result);

extern void wps_ses_add_job(wps_ses_job_struct *job);
extern wps_ses_job_struct *wps_ses_create_job(int src);

static int wait_for_response;
extern unsigned int request_id;

#endif /* WAP_SEC_SUPPORT */ 

extern void
wps_send_http_auth_ind(
    module_type dst_id,
    kal_uint8 channel_id,
    kal_uint16 request_id,
    kal_uint8 auth_type,
    kal_uint8 *realm);

extern void wps_send_create_stream_connection_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

extern void wps_send_stream_connection_close_ind(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause);

extern void wps_send_stream_data_send_rsp(module_type dst_id, kal_uint8 channel_id, kal_uint8 error_cause, kal_uint8 seq_num);

extern void
wps_send_stream_data_read_rsp(
    module_type dst_id,
    kal_uint8 channel_id,
    wps_req_info_struct *req_info,
    kal_uint8 error_cause,
    kal_bool more);

extern kal_int32 wps_check_recv_buf_size(wps_req_info_struct *req);

/************************************************************
 * Local function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_hold_bearer
 * DESCRIPTION
 *  this function is to activate the bearer used by application. ref_count is incremented when a channel is set.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_hold_bearer(int net_id)
{
    extern void HDIa_holdBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);

    HDIa_holdBearer(MSF_MODID_WPS, net_id);
}


/*****************************************************************************
 * FUNCTION
 *  wps_release_bearer
 * DESCRIPTION
 *  this function is to release bearer used by a channel. the actual bearer is deactivated when ref_count decrement to 0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_release_bearer(wps_chl_info_struct *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    MSF_UINT32 i;
    kal_uint8 app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void HDIa_releaseBearer(MSF_UINT8 modId, MSF_INT32 networkAccountID);
    extern kal_uint8 cbm_get_app_id(kal_uint32 acct_id);

    app_id = cbm_get_app_id(ch->net_id);
    /*is any other application using the same data account*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        chl_info = g_wps_cntx.channel_info[i];
       
        if (chl_info && chl_info != ch && cbm_get_app_id(chl_info->net_id) == app_id)
        {
            return;
        }
    }

    HDIa_releaseBearer(MSF_MODID_WPS, ch->net_id);
}

/*****************************************************************************
 * FUNCTION
 *  wps_exception_handler
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        longjmp(wps_jmp_buf, 1);
}


/*****************************************************************************
 * FUNCTION
 *  wps_http_delete_content
 * DESCRIPTION
 *  this function is to free memory of a http reply content.
 * PARAMETERS
 *  content                 [?]         
 *  num_entries             [IN]        
 *  remove_file_or_pipe     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_delete_content(stk_content_t *content, int num_entries, int remove_file_or_pipe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_entries; i++)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, content[i].contentType);
        MSF_MEM_FREE(MSF_MODID_WPS, content[i].name);
        MSF_MEM_FREE(MSF_MODID_WPS, content[i].fileName);
        if (content[i].dataType == STK_BODY_BUFFER)
        {
            MSF_MEM_FREE(MSF_MODID_WPS, content[i]._u.data);
        }
        else if (content[i].dataType == STK_BODY_PIPE)
        {
            if (remove_file_or_pipe)
            {
                MSF_PIPE_DELETE(content[i]._u.pipeName);
            }
            MSF_MEM_FREE(MSF_MODID_WPS, content[i]._u.pipeName);
        }
        else if (content[i].dataType == STK_BODY_PIPE)
        {
            if (remove_file_or_pipe)
            {
                MSF_FILE_REMOVE(content[i]._u.pathName);
            }
            MSF_MEM_FREE(MSF_MODID_WPS, content[i]._u.pathName);
        }
    }
    MSF_MEM_FREE(MSF_MODID_WPS, content);
}


/*****************************************************************************
 * FUNCTION
 *  wps_http_delete_reply
 * DESCRIPTION
 *  this function is to free memory of a http reply.
 * PARAMETERS
 *  p                       [?]         
 *  remove_file_or_pipe     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_http_delete_reply(stk_http_reply_t *p, int remove_file_or_pipe)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_WPS, p->newUrl);
    MSF_MEM_FREE(MSF_MODID_WPS, p->headers);
    wps_http_delete_content(p->content, p->numEntries, remove_file_or_pipe);
    MSF_MEM_FREE(MSF_MODID_WPS, p->cacheFileName);
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_search_req_info_by_pipe
 * DESCRIPTION
 *  This function is used to search request info by pipe
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wps_req_info_struct *wps_search_req_info_by_pipe(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        chl_info = g_wps_cntx.channel_info[i];
        if (chl_info == NULL)
        {
            continue;
        }
        for (j = 0; j < WPS_MAX_REQUESTS; j++)
        {
            req_info = chl_info->request_info[j];
            if (req_info == NULL)
            {
                continue;
            }

            if (req_info->pipe_handle == handle)
            {
                return req_info;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_search_empty_req_info_id
 * DESCRIPTION
 *  this function is used to fine the request info ID of empty request info
 * PARAMETERS
 *  channel_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int8 wps_search_empty_req_info_id(kal_uint8 channel_id)
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
        return -1;
    }

    for (i = 0; i < WPS_MAX_REQUESTS; i++)
    {
        req_info = chl_info->request_info[i];
        if (req_info == NULL)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  wps_write_to_file
 * DESCRIPTION
 *  this function is to write HTTP/WSP reply content to the file specified by
 *  the request at the beginning.
 * PARAMETERS
 *  req_info        [?]         
 *  read_result     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wps_write_to_file(wps_req_info_struct *req_info, kal_uint8 read_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret, bytes_write;
    kal_uint8 status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_info->file_handle < 0)
    {
        return WPS_DL_STATUS_ABORT;
    }
    
    /* No need to perform write operation if connection is closed. */
    if (read_result == WPS_READ_UNKNOWN_ERROR)
    {
        return WPS_DL_STATUS_ABORT;
    }

    if (req_info->buff_pos > 0)
    {
        ret = FS_Write(req_info->file_handle, req_info->buff, req_info->buff_pos, (U32*) & bytes_write);
        req_info->buff_pos = 0;

        if (ret == FS_NO_ERROR)
        {
            req_info->acc_size += bytes_write;
            status = (read_result == WPS_READ_SEGMENT) ? WPS_DL_STATUS_DOWNLOADING : WPS_DL_STATUS_COMPLETE;
        }
        else
        {
            status = WPS_DL_STATUS_ABORT;
            req_info->last_error = ret;
        }
    }
    else if (read_result == WPS_READ_SOURCE_CLOSED)
    {
        status = WPS_DL_STATUS_COMPLETE;
    }
    else
    {
        status = WPS_DL_STATUS_DOWNLOADING;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  wps_read_pipe
 * DESCRIPTION
 *  this function is to read pipe of a http reply content.
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wps_read_pipe(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int length;
    kal_uint8 *buf, error_cause;
    kal_uint32 buf_size;
    kal_uint8 tmp_buf[4];
    kal_uint32 tmp_buf_len = 4;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(req_info->buff == NULL)
		return WPS_READ_DELAYED;

    do
    {
        buf = req_info->buff + req_info->buff_pos;
        buf_size = req_info->reply_buff_size - req_info->buff_pos;

        length = MSF_PIPE_READ(req_info->pipe_handle, buf, buf_size);

        if (length >= 0)
        {
            req_info->buff_pos += length;
            if (req_info->buff_pos == req_info->reply_buff_size)
            {
                ret = MSF_PIPE_PEEK( req_info->pipe_handle, tmp_buf, tmp_buf_len);
                if( (ret == MSF_PIPE_ERROR_DELAYED) || (ret >0))
                {
                return WPS_READ_SEGMENT;
            }
                else
                {
                    return WPS_READ_SOURCE_CLOSED;
                }
            }
        }
    } while (length >= 0);

    switch (length)
    {
        case MSF_PIPE_ERROR_BAD_HANDLE:
            error_cause = WPS_READ_UNKNOWN_ERROR;
            break;
        case MSF_PIPE_ERROR_CLOSED:
            error_cause = WPS_READ_SOURCE_CLOSED;
            break;
        case MSF_PIPE_ERROR_DELAYED:
            if (MSF_PIPE_POLL(req_info->pipe_handle) != 0)
            {
                error_cause = WPS_READ_UNKNOWN_ERROR;
                break;
            }
            error_cause = WPS_READ_DELAYED;
            break;
        default:
            error_cause = WPS_READ_UNKNOWN_ERROR;
            break;
    }

    if (error_cause != WPS_READ_DELAYED)
    {
        MSF_PIPE_CLOSE(req_info->pipe_handle);
        req_info->pipe_handle = -1;
    }

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  wps_write_pipe
 * DESCRIPTION
 *  this function is to write pipe of a http post content.
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wps_write_pipe(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int length;
    kal_uint8 *buf, error_cause;
    kal_uint32 buf_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        buf = req_info->buff + req_info->buff_pos;
        buf_size = req_info->post_buff_size - req_info->buff_pos;

        length = MSF_PIPE_WRITE(req_info->pipe_handle, buf, buf_size);

        if (length >= 0)
        {
            req_info->buff_pos += length;
            if (req_info->buff_pos == req_info->post_buff_size)
            {
                return WPS_WRITE_SEGMENT;
            }
        }
    } while (length >= 0);

    switch (length)
    {
        case MSF_PIPE_ERROR_BAD_HANDLE:
            error_cause = WPS_WRITE_UNKNOWN_ERROR;
            break;
        case MSF_PIPE_ERROR_CLOSED:
            error_cause = WPS_WRITE_SOURCE_CLOSED;
            break;
        case MSF_PIPE_ERROR_DELAYED:
            if (MSF_PIPE_POLL(req_info->pipe_handle) != 0)
            {
                error_cause = WPS_WRITE_UNKNOWN_ERROR;
                break;
            }
            error_cause = WPS_WRITE_DELAYED;
            break;
        default:
            error_cause = WPS_WRITE_UNKNOWN_ERROR;
            break;
    }

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  wps_process_reply_content
 * DESCRIPTION
 *  this function is to process a segment of http reply content.
 * PARAMETERS
 *  req_info        [?]         
 *  read_result     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wps_process_reply_content(wps_req_info_struct *req_info, kal_uint8 read_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    kal_uint8 write_result = WPS_DL_STATUS_DOWNLOADING;
    kal_uint8 request_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[req_info->channel_id];
    request_idx = req_info->idx;

    if (req_info->reply_type == WPS_DATA_TYPE_FILE)
    {
        write_result = wps_write_to_file(req_info, read_result);

        if (req_info->flag & WPS_FLAG_FILE_NO_PROG_IND)
        {
            if (write_result == WPS_DL_STATUS_COMPLETE)
            {
		 if (req_info->file_handle >= 0)
		 {
			FS_Close(req_info->file_handle);
			req_info->file_handle = -1;
		 }
                wps_send_http_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
            }
            else if (write_result == WPS_DL_STATUS_ABORT)
            {
                wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
            }
        }
        else
        {
            req_info->seq_num++;
            if (write_result == WPS_DL_STATUS_COMPLETE || write_result == WPS_DL_STATUS_ABORT)
            {
                wps_send_dl_progress_ind(chl_info->mod_id, req_info, write_result);
            }
        }
    }
    else /* Handle reply_type buffer case here */
    {
        if (read_result == WPS_READ_UNKNOWN_ERROR)
        {
            if (req_info->state == WPS_REQ_WAIT_RSP)
            {
                wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
            }
            else if (req_info->state == WPS_REQ_WAIT_CONTENT)
            {
                wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
            }
        }
        else if (read_result == WPS_READ_SOURCE_CLOSED)
        {
        	  if (req_info->pipe_handle >= 0)
    		  {
     				MSF_PIPE_CLOSE(req_info->pipe_handle);
        			req_info->pipe_handle = -1;
        	   }
        	   if (req_info->state == WPS_REQ_WAIT_RSP)
               {
                    /* send back reply */
                    wps_send_http_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
                    req_info->seq_num++;
               }
               else if (req_info->state == WPS_REQ_WAIT_CONTENT)
               {
                    /* send back read content response */
                    wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
                    req_info->seq_num++;
               }        			
        }
        else
        {
            if (req_info->state == WPS_REQ_WAIT_RSP)
            {
                /* send back reply but more data */
                wps_send_http_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
                req_info->seq_num++;
            }
            else if (req_info->state == WPS_REQ_WAIT_CONTENT)
            {
                /* send back read content response */
                wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
                req_info->seq_num++;
            }
        }
    }

    if (read_result == WPS_READ_SOURCE_CLOSED || read_result == WPS_READ_UNKNOWN_ERROR ||
        write_result == WPS_DL_STATUS_COMPLETE || write_result == WPS_DL_STATUS_ABORT)
    {
        wps_clear_request(req_info->channel_id, request_idx);
        return KAL_FALSE;
    }
    else if (read_result == WPS_READ_SEGMENT && req_info->reply_type == WPS_DATA_TYPE_BUFFER)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wps_process_post_result
 * DESCRIPTION
 *  this function is to process the result of http content post.
 * PARAMETERS
 *  req_info        [?]         
 *  post_result     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void wps_process_post_result(wps_req_info_struct *req_info, int post_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    kal_uint8 request_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[req_info->channel_id];
    request_idx = req_info->idx;

    if (post_result == WPS_WRITE_SOURCE_CLOSED || post_result == WPS_WRITE_UNKNOWN_ERROR)
    {
        wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
        wps_clear_request(req_info->channel_id, request_idx);
    }
    else if (post_result == WPS_WRITE_SEGMENT)
    {
        req_info->seq_num++;
        if (req_info->more_post == KAL_TRUE)
        {
            wps_send_post_content_ind(chl_info->mod_id, req_info->request_id, WPS_OK, req_info->seq_num);
        }
        else
        {
			if(req_info->post_type == WPS_DATA_TYPE_MULTIPART)
			{
				int j;
				kal_bool index_flag= KAL_FALSE;
				for(j=req_info->currNumEntry + 1; j < req_info->numEntries; j++)
				{
           			  if(req_info->multipart_content[j].dataType == STK_BODY_PIPE)
           			  {
							index_flag = KAL_TRUE;
							break;
           			  }
				}
				req_info->currNumEntry = j;

				req_info->seq_num = 0;
				MSF_PIPE_CLOSE(req_info->pipe_handle);
				req_info->pipe_handle = -1;
				/*is there any pending multipart object, if no, then close the pipe*/
				if(index_flag == KAL_FALSE)
				{
					req_info->state = WPS_REQ_WAIT_RSP;

				}
				else
				{
					req_info->more_post = KAL_TRUE;
					req_info->pipe_handle = req_info->multipart_pipe_handle[j];
                                        req_info->seq_num++;
                                        wps_send_post_content_ind(chl_info->mod_id, req_info->request_id, WPS_OK, req_info->seq_num);
				}
			}
			else
			{
            req_info->state = WPS_REQ_WAIT_RSP;
            req_info->seq_num = 0;
            MSF_PIPE_CLOSE(req_info->pipe_handle);
            req_info->pipe_handle = -1;
        }
             }
        wps_clear_request_buff(req_info);
    }
}

/************************************************************
 * Global function definitions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wps_initial
 * DESCRIPTION
 *  this function WPS module initial function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        g_wps_cntx.channel_info[i] = NULL;
    }

#ifdef WAP_SEC_SUPPORT
    g_wps_cntx.wps_ses_queued_requests = NULL;
#endif

    wps_request_handle = 1;

    MSF_MEM_INIT(MSF_MODID_WPS, wps_exception_handler);

    //MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_WPS, wps_convert, wps_destruct);

    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_WPS);

    MSF_MODULE_IS_CREATED(MSF_MODID_WPS, "0.1");

    MSF_MODULE_IS_ACTIVE(MSF_MODID_WPS);

    MSF_FILE_MKDIR(WPS_DEFAULT_FOLDER);

}


/*****************************************************************************
 * FUNCTION
 *  wps_send_reset_ind
 * DESCRIPTION
 *  this function will be called when WPS module is going to terminate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_send_reset_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    module_type dst_id = MOD_NIL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        if (g_wps_cntx.channel_info[i] != NULL)
        {
            dst_id = g_wps_cntx.channel_info[i]->mod_id;
            wps_clear_channel(i);
            wps_send_wps_termination_ind(dst_id);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  wps_terminate
 * DESCRIPTION
 *  this function will be called when WPS module is going to terminate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wps_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wps_send_reset_ind();

    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_WPS);

    MSF_MEM_FREE_ALL(MSF_MODID_WPS);

    MSF_MODULE_IS_TERMINATED(MSF_MODID_WPS);

    MSF_KILL_TASK(MSF_MODID_WPS);
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_request_buff
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_clear_request_buff(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->buff);
    req_info->buff = NULL;
    req_info->buff_pos = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_request_buff
 * DESCRIPTION
 *  this function is intend for process the outside message.
 * CALLS
 *  
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_clear_send_request_buff(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->send_buff);
    req_info->send_buff = NULL;
    req_info->send_buff_pos = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_available_channel
 * DESCRIPTION
 *  this function is to get an unused channel ID.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int wps_get_available_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        if (g_wps_cntx.channel_info[i] == NULL)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  wps_create_channel
 * DESCRIPTION
 *  this function is to allocate memory for a channel context.
 * CALLS
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
wps_chl_info_struct *wps_create_channel(kal_uint8 channel_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = (wps_chl_info_struct*) MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(wps_chl_info_struct));

    if (chl_info == NULL)
    {
        return NULL;
    }

    chl_info->static_header = NULL;
    for (i = 0; i < WPS_MAX_REQUESTS; i++)
    {
        chl_info->request_info[i] = NULL;
    }
    chl_info->server_auth_username = NULL;
    chl_info->server_auth_password = NULL;
	chl_info->security_id = -1;
    memset(&(chl_info->session_info), 0, sizeof(chl_info->session_info));
    memset(&(chl_info->cert_info), 0, sizeof(chl_info->cert_info));	

    chl_info->channel_id = channel_id;
    g_wps_cntx.channel_info[channel_id] = chl_info;

    return chl_info;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_request
 * DESCRIPTION
 *  this function is to free memory of a HTTP/WSP request context.
 * CALLS
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_clear_request(kal_uint8 channel_id, kal_uint8 request_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        return;
    }

    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL)
    {
        return;
    }

    if (req_info->pipe_handle >= 0)
    {
        MSF_PIPE_CLOSE(req_info->pipe_handle);
        /* TBD PIPE DELETE */
        req_info->pipe_handle = -1;
    }

    if (req_info->send_pipe_handle >= 0)
    {
        MSF_PIPE_CLOSE(req_info->send_pipe_handle);
        /* TBD PIPE DELETE */
        req_info->send_pipe_handle = -1;
    }    

    if (req_info->file_handle >= 0)
    {
        FS_Close(req_info->file_handle);
        req_info->file_handle = -1;
    }

    if (req_info->rep != NULL)
    {
        wps_http_delete_reply(req_info->rep, TRUE);
    }

    wps_clear_request_buff(req_info);
    wps_clear_send_request_buff(req_info);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->recv_pipe_name);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->username);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->password);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->reply_path);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->post_path);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->req_header);
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->url);

	if(req_info->post_type == WPS_DATA_TYPE_MULTIPART && req_info->multipart_content != NULL)
    {
        for (i = 0; i < req_info->numEntries; i++)
	{
     	    MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content[i].contentType);
	    MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content[i].name);
	    MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content[i].fileName);
	    if (req_info->multipart_content[i].dataType == STK_BODY_PIPE)
	    {
	        MSF_PIPE_DELETE (req_info->multipart_content[i]._u.pipeName);
		      MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content[i]._u.pipeName);
	    }
	    else if (req_info->multipart_content[i].dataType == STK_BODY_FILE)
	    {
		 MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content[i]._u.pathName);
	    }
	 }
	 MSF_MEM_FREE(MSF_MODID_WPS,req_info->multipart_pipe_handle );	
	 MSF_MEM_FREE (MSF_MODID_WPS,req_info->multipart_content);
	 req_info->multipart_content = NULL;
    }
    MSF_MEM_FREE(MSF_MODID_WPS, req_info);
    chl_info->request_info[request_idx] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_clear_channel
 * DESCRIPTION
 *  this function is to free channel context.
 * CALLS
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wps_clear_channel(kal_uint8 channel_id)
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
        return;
    }

    for (i = 0; i < WPS_MAX_REQUESTS; i++)
    {
        if (chl_info->request_info[i] != NULL)
        {
            req_info = chl_info->request_info[i];
            
            switch (req_info->state)
            {
                case WPS_REQ_POSTING:
                case WPS_REQ_WAIT_RSP:
                    /* send reply with error */
                    wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
                    break;
                case WPS_REQ_RSP_SENT:
                case WPS_REQ_WAIT_CONTENT:
                    if (req_info->reply_type == WPS_DATA_TYPE_FILE)
                    {
                        if(req_info->flag & WPS_FLAG_FILE_NO_PROG_IND)
                        {
                            wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
                        }
                        else
                        {
                            wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);
                        }
                    }
                    else /* reply type is buffer */
                    {
                        if (req_info->state == WPS_REQ_WAIT_CONTENT)
                        {
                            wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
                        }
                    }
                    break;
            }
            wps_clear_request(channel_id, i);
        }
    }

    wps_release_bearer(chl_info);
        
    MSF_MEM_FREE(MSF_MODID_WPS, chl_info->static_header);
    MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_username);
    MSF_MEM_FREE(MSF_MODID_WPS, chl_info->server_auth_password);
    if(chl_info->cert_info.cert)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, chl_info->cert_info.cert);	
        chl_info->cert_info.cert = NULL;		
    }
	
    MSF_MEM_FREE(MSF_MODID_WPS, chl_info);

    g_wps_cntx.channel_info[channel_id] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_create_request
 * DESCRIPTION
 *  this function is to allocate memory for a HTTP/WSP request context.
 * CALLS
 *  
 * PARAMETERS
 *  channel_id      [IN]        
 *  request_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
wps_req_info_struct *wps_create_request(kal_uint8 channel_id, kal_uint16 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;
    kal_int8 empty_request_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[channel_id];

    req_info = (wps_req_info_struct*) MSF_MEM_ALLOC(MSF_MODID_WPS, sizeof(wps_req_info_struct));

    if (req_info == NULL)
    {
        return NULL;
    }

    empty_request_id = wps_search_empty_req_info_id(channel_id);
    if (empty_request_id == -1)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, req_info);
        return NULL;
    }

    req_info->pipe_handle = -1;
    req_info->send_pipe_handle = -1;
    req_info->file_handle = -1;
    req_info->seq_num = 0;
    req_info->acc_size = 0;
    req_info->buff_pos = 0;
    req_info->url = NULL;
    req_info->reply_path = NULL;
    req_info->post_path = NULL;
    req_info->req_header = NULL;
    req_info->buff = NULL;
    req_info->rep = NULL;
    req_info->channel_id = channel_id;
    req_info->request_id = request_id;
    req_info->idx = empty_request_id;
    req_info->stk_request_id = wps_request_handle++;
    req_info->username = NULL;
    req_info->password = NULL;
    req_info->ind_sent = 0;
    req_info->send_buff = NULL;
    req_info->send_buff_pos = 0;
    req_info->send_buff_size = 0;
    req_info->send_seq_num = 0;
    req_info->recv_pipe_name = NULL;
    req_info->flag = 0;
	req_info->numEntries = 0;
	req_info->currNumEntry = 0;
	req_info->multipart_content = NULL;
	req_info->multipart_pipe_handle = NULL;
	req_info->post_type = 0;
    chl_info->request_info[empty_request_id] = req_info;

    return req_info;
}


/*****************************************************************************
 * FUNCTION
 *  wps_read_reply_content
 * DESCRIPTION
 *  this function is to read content from a http reply.
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_read_reply_content(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_chl_info_struct *chl_info;
    kal_uint8 read_result;
    kal_bool continue_read;
#ifdef WAP_DOWNLOAD_SPEEDUP	
    kal_uint32 fileSize = 0;	
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    chl_info = g_wps_cntx.channel_info[req_info->channel_id];

    if ((req_info->reply_type == WPS_DATA_TYPE_FILE) &&
        !(req_info->flag & WPS_FLAG_FILE_NO_PROG_IND) &&
        (req_info->ind_sent == 0) && (req_info->file_handle < 0) )
     {
        if( req_info->rep->status == STK_HTTP_PARTIAL_CONTENT)
        {
            if( !(req_info->flag & WPS_FLAG_FILE_FS_COMMIT))
            {
                req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_OPEN_SHARED);
            }
            else
            {
                req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_OPEN_SHARED | 
                                                                      FS_CREATE | FS_ATTR_SYSTEM | FS_COMMITTED);
            }
            if(req_info->file_handle >= 0)
                req_info->acc_size = FS_Seek(req_info->file_handle, 0, FS_FILE_END);
        }
        else
        {
            FS_Delete(req_info->reply_path);
            
            if(!(req_info->flag & WPS_FLAG_FILE_FS_COMMIT))
            {
                req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);
            }
            else
            {
                req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED |
                                                                      FS_ATTR_SYSTEM | FS_COMMITTED);
            }
        }
        if (req_info->file_handle < 0)
        {
            req_info->last_error = req_info->file_handle;
            wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);
            wps_clear_request(req_info->channel_id, req_info->idx);
            return;
        }                
    }
    else if ((req_info->flag & WPS_FLAG_FILE_NO_PROG_IND) && (req_info->file_handle < 0))
    {
        FS_Delete(req_info->reply_path);
        if( !(req_info->flag & WPS_FLAG_FILE_FS_COMMIT))
        {
            req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);
        }
        else
        {
            req_info->file_handle = FS_Open(req_info->reply_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED |
                                                                  FS_ATTR_SYSTEM | FS_COMMITTED);
        }
        if (req_info->file_handle < 0)
        {
            req_info->last_error = req_info->file_handle;
            wps_send_http_rsp( chl_info->mod_id,
                               req_info, WPS_ERROR_FILE_ACCESS,
                               req_info->request_id);
            wps_clear_request(req_info->channel_id, req_info->idx);
            return;
        }
    }

    do
    {


        /*To improve the performance of file write operation, the write operation should be cluster mapped*/
#ifdef WAP_DOWNLOAD_SPEEDUP
        if((req_info->reply_type == WPS_DATA_TYPE_FILE) && (req_info->flag & WPS_FLAG_USE_LARGE_PIPE) && (req_info->file_handle > 0))
        {
            FS_GetFileSize(req_info->file_handle, &fileSize);
            req_info->reply_buff_size = WPS_PIPE_READ_BUFF_SIZE - (fileSize % WPS_PIPE_READ_BUFF_SIZE);    
        }
#endif    			
        read_result = wps_read_pipe(req_info);

        if(chl_info->conn_type == STK_CONNECTION_TYPE_TLS)
        {
            if(read_result == WPS_READ_SEGMENT)
            {
                wps_send_stream_data_read_rsp(chl_info->mod_id, req_info->channel_id, req_info, WPS_OK, KAL_TRUE);
            }
            else if(read_result == WPS_READ_DELAYED)
            {
                wps_send_stream_data_read_rsp(chl_info->mod_id, req_info->channel_id, req_info, WPS_OK, KAL_TRUE);
            }
            else
            {
                wps_clear_request(req_info->channel_id, 0);
                wps_send_stream_data_read_rsp(chl_info->mod_id, req_info->channel_id, req_info, WPS_ERROR_UNKNOWN, KAL_FALSE);
            }
            return;
        }

        if (read_result == WPS_READ_DELAYED)
        {
            if(req_info->reply_type == WPS_DATA_TYPE_FILE && !(req_info->flag & WPS_FLAG_FILE_NO_PROG_IND) && req_info->ind_sent == 0)
            {
                wps_send_dl_progress_ind(
                    g_wps_cntx.channel_info[req_info->channel_id]->mod_id,
                    req_info,
                    WPS_DL_STATUS_DOWNLOADING);
                req_info->ind_sent++;
            }
            else if ((req_info->reply_type == WPS_DATA_TYPE_BUFFER) && (req_info->state == WPS_REQ_WAIT_CONTENT) && (req_info->buff_pos > 0))
            {
                /* send back read content response */
                wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_OK, req_info->request_id);
                req_info->seq_num++;
            }
            break;
        }

        continue_read = wps_process_reply_content(req_info, read_result);

    } while (continue_read);
}


/*****************************************************************************
 * FUNCTION
 *  wps_write_post_content
 * DESCRIPTION
 *  this function is to post content for a http request.
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_write_post_content(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int post_result;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[req_info->channel_id];

    if(chl_info->conn_type == WPS_CONN_TYPE_TLS)
    {
        wps_write_to_sink(req_info);
        return;
    }

    post_result = wps_write_pipe(req_info);

    if (post_result == WPS_WRITE_DELAYED)
    {
        return;
    }

    wps_process_post_result(req_info, post_result);
}


/*****************************************************************************
 * FUNCTION
 *  wps_write_post_content
 * DESCRIPTION
 *  this function is to post content for a http request.
 * PARAMETERS
 *  req_info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_write_to_sink(wps_req_info_struct *req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int post_result = WPS_WRITE_UNKNOWN_ERROR;
    wps_chl_info_struct *chl_info;
    int length;
    kal_uint8 *buf;
    kal_uint32 buf_size;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chl_info = g_wps_cntx.channel_info[req_info->channel_id];
    do
    {
        buf = req_info->send_buff + req_info->send_buff_pos;
        buf_size = req_info->send_buff_size - req_info->send_buff_pos;

        length = MSF_PIPE_WRITE(req_info->send_pipe_handle, buf, buf_size);

        if (length >= 0)
        {
            req_info->send_buff_pos += length;
            if (req_info->send_buff_pos == req_info->send_buff_size)
            {
                post_result = WPS_WRITE_SEGMENT;
                break;
            }
        }
    } while (length >= 0);

    switch (length)
    {
        case MSF_PIPE_ERROR_BAD_HANDLE:
            post_result = WPS_WRITE_UNKNOWN_ERROR;
            break;
        case MSF_PIPE_ERROR_CLOSED:
            post_result = WPS_WRITE_SOURCE_CLOSED;
            break;
        case MSF_PIPE_ERROR_DELAYED:
            if (MSF_PIPE_POLL(req_info->pipe_handle) != 0)
            {
                post_result = WPS_WRITE_UNKNOWN_ERROR;
                break;
            }
            post_result = WPS_WRITE_DELAYED;
            break;
        default:
            break;
    }

    if (post_result == WPS_WRITE_SOURCE_CLOSED || post_result == WPS_WRITE_UNKNOWN_ERROR)
    {
        wps_clear_request(req_info->channel_id, 0);
        wps_send_stream_data_send_rsp(chl_info->mod_id, req_info->channel_id, WPS_ERROR_SEND, req_info->send_seq_num);
    }
    else if (post_result == WPS_WRITE_SEGMENT)
    {
        req_info->send_seq_num++;
        wps_clear_send_request_buff(req_info);
        wps_send_stream_data_send_rsp(chl_info->mod_id, req_info->channel_id, WPS_OK, req_info->send_seq_num);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wps_http_reply
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_http_reply(stk_http_reply_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;
    int pipe_handle;
    kal_int32 check_recv_buf_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = WPS_GET_CHANNEL_ID(p->requestId);
    request_idx = WPS_GET_REQUEST_ID(p->requestId);

    if(channel_id == 0xff || request_idx == 0xff)
    {
        /* delete http reply */
        wps_http_delete_reply(p, TRUE);
        return;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        /* delete http reply */
        wps_http_delete_reply(p, TRUE);
        return;
    }

    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        /* delete http reply */
        wps_http_delete_reply(p, TRUE);
        return;
    }

    req_info->rep = p;

    /* update socket ID and security ID*/
    chl_info->socket_id = p->socketId;
    
    if(p->securityId != -1)
    {
        chl_info->security_id = p->securityId;
#ifdef STK_CFG_USE_MTK_TLS		
  	wps_sec_get_session_info(chl_info);
        wps_sec_get_current_cert(chl_info);
#endif /* STK_CFG_USE_MTK_TLS */
    }

    /* Because the control buffer might not be large enough to pack the header
       and response content at the same time, need to refine the size specified
       by the user. */
    check_recv_buf_size = wps_check_recv_buf_size(req_info);
    if (check_recv_buf_size == 0)
    {
        /* send back response and delete content */
        wps_send_http_rsp(
            g_wps_cntx.channel_info[channel_id]->mod_id,
            req_info,
            WPS_ERROR_REQ_MSG_TOO_LARGE,
            req_info->request_id);
        wps_clear_request(channel_id, request_idx);
		return;
    }

    /* check content */
    if (p->numEntries == 0 || p->content == NULL)
    {
        /* send back response and delete content */
        wps_send_http_rsp(g_wps_cntx.channel_info[channel_id]->mod_id, req_info, WPS_OK, req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

    /* get content */
    if (p->content[0].dataType != STK_BODY_PIPE)
    {
        /* This implies the content is not reply_content due to pipe resource limit */
        wps_send_http_rsp(
            g_wps_cntx.channel_info[channel_id]->mod_id,
            req_info,
            WPS_ERROR_NO_RESOURCE,
            req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

#ifdef WAP_DOWNLOAD_SPEEDUP
    if(req_info->flag & WPS_FLAG_USE_LARGE_PIPE)
    {
        pipe_handle = MSF_PIPE_OPEN_EXTENDED(MSF_MODID_WPS, p->content[0]._u.pipeName);
    }
    else
#endif
    {
        pipe_handle = MSF_PIPE_OPEN(MSF_MODID_WPS, p->content[0]._u.pipeName);
    }
    if (pipe_handle < 0)
    {
        /* send back response and delete content */
        wps_send_http_rsp(
            g_wps_cntx.channel_info[channel_id]->mod_id,
            req_info,
            WPS_ERROR_NO_RESOURCE,
            req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

    req_info->pipe_handle = pipe_handle;

	if( check_recv_buf_size < req_info->reply_buff_size )
	{
		req_info->reply_buff_size = check_recv_buf_size;
	}

#ifdef WAP_DOWNLOAD_SPEEDUP
    if ((req_info->reply_type == WPS_DATA_TYPE_FILE) && (req_info->flag & WPS_FLAG_USE_LARGE_PIPE))
    {
        req_info->reply_buff_size = WPS_PIPE_READ_BUFF_SIZE;
    }    
#endif    
    req_info->buff = MSF_MEM_ALLOC(MSF_MODID_WPS, req_info->reply_buff_size);
    if (req_info->buff == NULL)
    {
        /* send back response and delete content */
        wps_send_http_rsp(
            g_wps_cntx.channel_info[channel_id]->mod_id,
            req_info,
            WPS_ERROR_NO_RESOURCE,
            req_info->request_id);
        wps_clear_request(channel_id, request_idx);
        return;
    }

    if (req_info->reply_type == WPS_DATA_TYPE_FILE)
    {
        if (req_info->flag & WPS_FLAG_FILE_NO_PROG_IND)
        {
            req_info->state = WPS_REQ_WAIT_CONTENT;
        }
        else
        {
            wps_send_http_rsp(g_wps_cntx.channel_info[channel_id]->mod_id, req_info, WPS_OK, req_info->request_id);
            req_info->seq_num++;
            req_info->state = WPS_REQ_WAIT_CONTENT;
            /* To make sure this 206 response is proper, before WPS write this
               partially downloaded file, send indication and wait until APP sends 
               the response or abort the request. */
            if ((req_info->flag & WPS_STK_FALG_WAIT_CONFIRM))
            {
                req_info->flag &= ~WPS_STK_FALG_WAIT_CONFIRM;
                wps_send_dl_progress_ind(g_wps_cntx.channel_info[channel_id]->mod_id, req_info, WPS_DL_STATUS_DOWNLOADING );
	            req_info->ind_sent++;
            }            
            return;
        }
    }

    wps_read_reply_content(req_info);
}


/*****************************************************************************
 * FUNCTION
 *  wps_http_abort
 * DESCRIPTION
 *  this function is used to handle HTTP/WSP request abort indication.
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_http_abort(stk_http_request_aborted_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;

    stk_http_request_aborted_t *http_abort;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_abort = (stk_http_request_aborted_t*) p;

    /* check request id */
    channel_id = WPS_GET_CHANNEL_ID(p->requestId);
    request_idx = WPS_GET_REQUEST_ID(p->requestId);

    if(channel_id == 0xff || request_idx == 0xff)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    /* update socket ID and security ID*/
    chl_info->socket_id = -1;

    /* resend post or put if unauthorized */
    if (http_abort->errorCode == STK_ERR_COMM_RESEND_POST_REQUEST ||
        http_abort->errorCode == STK_ERR_COMM_RESEND_PUT_REQUEST)
    {
        int len;
        stk_content_t stkData;
        char *pathName;

        /* the request type must be */
        if (req_info->method != STK_METHOD_PUT && req_info->method != STK_METHOD_POST)
        {
            EXT_ASSERT(0 ,0,0,0);
        }

        if(req_info->post_path != NULL)
        {
            stkData.contentType = NULL;
            stkData.charset = 0;
            stkData.name = NULL;
            stkData.fileName = NULL;
            stkData.dataType = STK_BODY_FILE;
            stkData.dataLen = req_info->post_total_len;
            len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*) req_info->post_path);
            pathName = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, HDI_EXTERNAL_LEN + len + 1);
            sprintf(pathName, "%s", HDI_EXTERNAL_PATH);
            widget_ucs2_to_utf8_string(
                (kal_uint8*) (pathName + HDI_EXTERNAL_LEN),
                len + 1,
                (kal_uint8*) req_info->post_path);
            stkData._u.pathName = pathName;

            STKif_httpRequest(
                MSF_MODID_WPS,
                channel_id + 1,
                req_info->stk_request_id,
                (const char*)req_info->url,
                req_info->method,
#ifdef STK_DCMP_USE_ASM_POOL
                STK_OPTION_DO_NOT_ACCEPT_ENCODING,
#else
                0,
#endif /*STK_DCMP_USE_ASM_POOL*/
                (char*)req_info->req_header,
                NULL,
                0,
                1,
                &stkData);
            req_info->state = WPS_REQ_WAIT_RSP;

            MSF_MEM_FREE(MSF_MODID_WPS, p);
            return;
        }
    }

    req_info->last_error = http_abort->errorCode;
    
    switch (req_info->state)
    {
        case WPS_REQ_POSTING:
        case WPS_REQ_WAIT_RSP:
            /* send reply with error */
            wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
            wps_clear_request(req_info->channel_id, request_idx);
            break;
        case WPS_REQ_RSP_SENT:
        case WPS_REQ_WAIT_CONTENT:
            if (req_info->reply_type == WPS_DATA_TYPE_FILE)
            {
                if(req_info->flag & WPS_FLAG_FILE_NO_PROG_IND)
                {
                    wps_send_http_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
                }
                else
                {
                    wps_send_dl_progress_ind(chl_info->mod_id, req_info, WPS_DL_STATUS_ABORT);
                }
            }
            else /* reply type is buffer */
            {
                wps_send_read_content_rsp(chl_info->mod_id, req_info, WPS_ERROR_REQ_ABORT, req_info->request_id);
            }
            wps_clear_request(req_info->channel_id, request_idx);
            break;
        case WPS_REQ_CANCELING:
            wps_send_cancel_rsp(chl_info->mod_id, req_info->request_id, WPS_OK);
            wps_clear_request(req_info->channel_id, request_idx);
            break;
        default:
            break;
    }
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_handle_command
 * DESCRIPTION
 *  this function is used to handle the command from framework. Here is handling push.
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_handle_command(msf_module_execute_cmd_t *p)
{
#if WPS_PUSH_REGISTRAR_NUM > 0
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern kal_uint8 *HDI_FileNameTranslate(const char *filename);
    const char *content_type = NULL;
    module_type dst_id = MOD_NIL;

    if (p->contentDataExists == 1
        && p->contentData->contentDataType == MSF_CONTENT_DATA_RAW && p->contentData->contentData != NULL)
    {
        kal_uint8 i, j;

        for (i = 0; i < WPS_PUSH_REGISTRAR_NUM; i++)
        {
            for (j = 0; j < wps_push_reg[i].mime_type_num; j++)
            {
                if (strstr(p->contentData->contentHeaders, wps_push_reg[i].mime_type[j]) != NULL)
                {
                    content_type = wps_push_reg[i].mime_type[j];
                    dst_id = wps_push_reg[i].registrar;
                    break;
                }
            }
            if (content_type != NULL)
            {
                break;
            }
        }

        if (content_type != NULL)
        {
            char *tmpfile;
            kal_wchar *ucs2file;
            int file_handle, bytes_write, ret;

            tmpfile = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, 128);
            sprintf(tmpfile, "%s/%lu", WPS_DEFAULT_FOLDER, HDIa_timeGetCurrent());
            ucs2file = (kal_wchar*) HDI_FileNameTranslate(tmpfile);

            file_handle = FS_Open(ucs2file, FS_READ_WRITE | FS_CREATE);
            if (file_handle <= 0)
            {
                /* tricky to specify MSF_MODID_MSM as module ID because of HDI_FileNameTranslate */
                MSF_MEM_FREE(MSF_MODID_MSM, ucs2file);
                MSF_MEM_FREE(MSF_MODID_WPS, tmpfile);
                return;
            }
            ret = FS_Write(
                    file_handle,
                    p->contentData->contentData,
                    p->contentData->contentDataLength,
                    (U32*) & bytes_write);
            if (ret == FS_NO_ERROR && bytes_write == p->contentData->contentDataLength)
            {
                wps_send_push_ind(
                    dst_id,
                    (kal_uint8*) content_type,
                    (kal_uint32) p->contentData->contentDataLength,
                    ucs2file);
                FS_Close(file_handle);
            }
            else
            {
                FS_Close(file_handle);
                FS_Delete(ucs2file);
            }

            /* tricky to specify MSF_MODID_MSM as module ID because of HDI_FileNameTranslate */
            MSF_MEM_FREE(MSF_MODID_MSM, ucs2file);
            MSF_MEM_FREE(MSF_MODID_WPS, tmpfile);
        }
    }

    MSF_MEM_FREE(MSF_MODID_WPS, p);
#else /* WPS_PUSH_REGISTRAR_NUM > 0 */ 

    MSF_MEM_FREE(MSF_MODID_WPS, p);
    return;

#endif /* WPS_PUSH_REGISTRAR_NUM > 0 */ 
}

#ifdef WAP_SEC_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wps_ses_find_job_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wps_ses_job_struct *wps_ses_find_job_by_id(int request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = g_wps_cntx.wps_ses_queued_requests;

    while (job != NULL)
    {
        if (job->request_id == request_id)
        {
            return job;
        }
        job = job->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wps_ses_delete_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wps_ses_delete_job(wps_ses_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wps_cntx.wps_ses_queued_requests == job)
    {
        g_wps_cntx.wps_ses_queued_requests = job->next;
    }
    else
    {
        wps_ses_job_struct *prev_job;

        prev_job = g_wps_cntx.wps_ses_queued_requests;

        while (prev_job != NULL)
        {
            if (prev_job->next == job)
            {
                prev_job->next = job->next;
                break;
            }
        }
    }

    MSF_MEM_FREE(MSF_MODID_WPS, job);

}


/*****************************************************************************
 * FUNCTION
 *  wps_get_session_info_rsp
 * DESCRIPTION
 *  this function is used to handle SEC_SIG_GET_SESSION_INFO_RESPONSE
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_get_session_info_rsp(sec_get_session_info_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_id = p->objectId;
    chl_info = g_wps_cntx.channel_info[channel_id];

    if (chl_info == NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    if (p->result != SEC_ERR_OK)
    {
        wps_send_sec_get_session_info_rsp(chl_info->mod_id, channel_id, NULL, WPS_ERROR_NOT_FOUND);
    }
    else
    {
        wps_send_sec_get_session_info_rsp(chl_info->mod_id, channel_id, p, WPS_OK);
    }

    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_current_cert_rsp
 * DESCRIPTION
 *  this function is used to handle SEC_SIG_GET_CURRENT_CERT_RESPONSE
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_get_current_cert_rsp(sec_get_current_cert_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_id = p->objectId;
    chl_info = g_wps_cntx.channel_info[channel_id];

    if (chl_info == NULL)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p->cert);
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    if (p->result != SEC_ERR_OK)
    {
        wps_send_sec_get_current_cert_rsp(chl_info->mod_id, channel_id, NULL, WPS_ERROR_NOT_FOUND);
    }
    else
    {
        wps_send_sec_get_current_cert_rsp(chl_info->mod_id, channel_id, p, WPS_OK);
    }

    MSF_MEM_FREE(MSF_MODID_WPS, p->cert);
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_cert_ids_rsp
 * DESCRIPTION
 *  this function is used to handle SEC_SIG_GET_CERT_IDS_RESPONSE
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_get_cert_ids_rsp(sec_get_cert_ids_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_find_job_by_id(p->id);

    if (!job)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    wps_send_sec_get_cert_ids_rsp(job->src, p->nbrCerts, p->certIds);
    wps_ses_delete_job(job);

	if(p->nbrCerts > 0)
	{
		MSF_MEM_FREE(MSF_MODID_WPS, p->certIds);
	}
	MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_cert_rsp
 * DESCRIPTION
 *  this function is used to handle SEC_SIG_GET_CERT_RESPONSE
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_get_cert_rsp(sec_get_cert_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;
    sec_certificate_t parsed_cert;
    sec_x509_rsa_mod_and_exp_t rsa_mod_and_exp;
    char *issuer = NULL, *subject = NULL, *serial_num = NULL, *sig_alg_name = NULL;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_find_job_by_id(p->id);

    if (!job)
    {
        goto end;
    }

    if (p->result != SEC_ERR_OK)
    {
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
        wps_send_sec_get_cert_rsp(job->src, p->certId, (MSF_UINT8)p->result, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, p->attribute);
#else
        wps_send_sec_get_cert_rsp(job->src, p->certId, (MSF_UINT8)p->result, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, 1);
#endif /* MSF_CFG_RDONLY_CERT_SUPPORT */
        wps_ses_delete_job(job);

        goto end;
    }
    ret = SEClib_parseCertificate(p->cert[0], p->cert + 1, (MSF_UINT16)(p->certLen - 1), &parsed_cert);

    if (ret != SEC_ERR_OK)
    {
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
        wps_send_sec_get_cert_rsp(job->src, p->certId, WPS_SEC_ERR_BAD_CERTIFICATE, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, p->attribute);
#else
        wps_send_sec_get_cert_rsp(job->src, p->certId, WPS_SEC_ERR_BAD_CERTIFICATE, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, 1);
#endif /*MSF_CFG_RDONLY_CERT_SUPPORT*/
        wps_ses_delete_job(job);
        goto end;
    }

    if (p->cert[0] == SEC_CERT_FORMAT_X509)
    {
        if (parsed_cert.issuer)
        {
            issuer = wps_sec_get_issuer_str(-1, parsed_cert.issuer, parsed_cert._u.x509.issuerLen);
        }
        if (parsed_cert.subject)
        {
            subject = wps_sec_get_issuer_str(-1, parsed_cert.subject, parsed_cert._u.x509.subjectLen);
        }
        if (parsed_cert._u.x509.serialNumber)
        {
            serial_num = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, parsed_cert._u.x509.serialNumberLen);
            memcpy(serial_num, parsed_cert._u.x509.serialNumber, parsed_cert._u.x509.serialNumberLen);
        }
        if (parsed_cert._u.x509.signatureAlgorithm)
        {
            sig_alg_name = wps_sec_get_sig_alg_name(
                            parsed_cert._u.x509.signatureAlgorithm,
                            parsed_cert._u.x509.signatureAlgorithmLen);
        }
        
        ret = SEClib_parseX509RSAModAndExp(parsed_cert._u.x509.publicKeyVal, parsed_cert._u.x509.publicKeyValLen, &rsa_mod_and_exp);
        if(ret != SEC_ERR_OK)
        {
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
            wps_send_sec_get_cert_rsp(job->src, p->certId, (MSF_UINT8)ret, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, p->attribute);
#else
            wps_send_sec_get_cert_rsp(job->src, p->certId, (MSF_UINT8)ret, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, 1);
#endif /*MSF_CFG_RDONLY_CERT_SUPPORT*/
            wps_ses_delete_job(job);
            goto end;
        }
        
        wps_send_sec_get_cert_rsp(
            job->src,
            p->certId,
            WPS_OK,
            parsed_cert.valid_not_after,
            parsed_cert.valid_not_before,
            SEC_CERT_FORMAT_X509,
            parsed_cert.certificate_version,
            issuer,
            subject,
            serial_num,
            sig_alg_name,
            rsa_mod_and_exp.rsa_modulus,
            rsa_mod_and_exp.modLen,
            rsa_mod_and_exp.rsa_exponent,
            rsa_mod_and_exp.expLen,
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
            p->attribute
#else
            1
#endif /*MSF_CFG_RDONLY_CERT_SUPPORT*/
);
        
    }
    else
    {
        if (parsed_cert.issuer)
        {
            issuer = wps_sec_get_issuer_str(
                        parsed_cert._u.wtls.issuercharacterSet,
                        parsed_cert.issuer,
                        parsed_cert._u.wtls.issuerLen);
        }
        if (parsed_cert.subject)
        {
            subject = wps_sec_get_issuer_str(parsed_cert._u.wtls.subjectcharacterSet, parsed_cert.subject, parsed_cert._u.wtls.subjectLen);
        }

        sig_alg_name = (char*)MSF_MEM_ALLOC(MSF_MODID_WPS, 32);

        if (parsed_cert._u.wtls.signature_algorithm == 0)   /* anonymous */
        {
            strcpy(sig_alg_name, "anonymous");
        }
        else if (parsed_cert._u.wtls.signature_algorithm == 1)      /* ecdsa_sha */
        {
            strcpy(sig_alg_name, "ecdsa_sha");
        }
        else if (parsed_cert._u.wtls.signature_algorithm == 2)      /* rsa_sha */
        {
            strcpy(sig_alg_name, "rsa_sha");
        }
        wps_send_sec_get_cert_rsp(
            job->src,
            p->certId,
            WPS_OK,
            parsed_cert.valid_not_after,
            parsed_cert.valid_not_before,
            SEC_CERT_FORMAT_WTLS,
            parsed_cert.certificate_version,
            issuer,
            subject,
            serial_num,
            sig_alg_name,
            NULL,
            0,
            NULL,
            0,
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
            p->attribute
#else
            1
#endif /*MSF_CFG_RDONLY_CERT_SUPPORT*/
             );
    }

    MSF_MEM_FREE(MSF_MODID_WPS, issuer);
    MSF_MEM_FREE(MSF_MODID_WPS, subject);
    MSF_MEM_FREE(MSF_MODID_WPS, serial_num);
    MSF_MEM_FREE(MSF_MODID_WPS, sig_alg_name);
    wps_ses_delete_job(job);
end:
	if(p->cert != NULL)
	{
		MSF_MEM_FREE(MSF_MODID_WPS, p->cert);
	}
	if(p->trustedUsage != NULL)
	{
		MSF_MEM_FREE(MSF_MODID_WPS, p->trustedUsage);
	}
	MSF_MEM_FREE(MSF_MODID_WPS, p);

}

#ifdef __HTTP_INTERFACE__
/*****************************************************************************
 * FUNCTION
 *  wps_verify_cert_chain_rsp
 * DESCRIPTION
 *  this function is used to handle SEC_SIG_VERIFY_CERT_CHAIN_RESPONSE
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_verify_cert_chain_rsp(sec_verify_cert_chain_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_find_job_by_id(p->id);

    ASSERT(job);

    wps_send_verify_cert_chain_rsp((module_type)job->src, p, WPS_SEC_OK);
    
    wps_ses_delete_job(job);

	if(p->rootCert != NULL)
	{
		MSF_MEM_FREE(MSF_MODID_WPS, p->rootCert);
	}
	MSF_MEM_FREE(MSF_MODID_WPS, p);

}
#endif /*__HTTP_INTERFACE__*/
/*****************************************************************************
 * FUNCTION
 *  wps_sec_handle_delete_ca_cert_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_sec_handle_delete_ca_cert_response(sec_delete_cert_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = wps_ses_find_job_by_id(p->id);

    if (!job)
    {
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    if (p->result == SEC_ERR_OK)
    {
        wps_send_delete_ca_cert_rsp(job->src, WPS_OK);
    }
    else
    {
        wps_send_delete_ca_cert_rsp(job->src, WPS_ERROR_NOT_FOUND);
    }
    wps_ses_delete_job(job);

	MSF_MEM_FREE(MSF_MODID_WPS, p);
}

/*****************************************************************************
 * FUNCTION
 *  wps_sec_handle_show_confirm_dialog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_sec_handle_show_confirm_dialog(wps_show_sec_confirm_dialog_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sec_ti_confirm_dlg_response_t *sig;
    wps_ses_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sig = MSF_MEM_ALLOC(MSF_MODID_SEC, sizeof(sec_ti_confirm_dlg_response_t));
    memset(sig, 0, sizeof(sec_ti_confirm_dlg_response_t));		

    if (wait_for_response)
        {
        sig->result = (p->confirm == 0) ? SEC_ERR_OK : SEC_ERR_CANCEL;

       MSF_SIGNAL_SEND (MSF_MODID_WPS, MSF_MODID_SEC, SEC_SIG_TI_CONFIRM_DLG_RESPONSE, sig);     			
    }
    else
    {
        /* not support certificate type */
        if(p->confirm == 0xFF)
        {
            job = wps_ses_create_job(MSF_MODID_WPS);
            wps_ses_add_job(job);
            wps_send_sec_show_confirm_dialog_ind(request_id, p->type, 0, p->title_id, p->text_id);
        }
        else
        {
            wps_send_sec_show_confirm_dialog_ind(++request_id, p->type, p->confirm, p->title_id, p->text_id);
        }
        wait_for_response = 1;
    }
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}

/*****************************************************************************
 * FUNCTION
 *  wps_sec_show_confirm_dialog_res_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_sec_show_confirm_dialog_res_hdlr(module_type src_mod_id, wps_show_confirm_dialog_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sec_ti_confirm_dlg_response_t *sig;
    wps_ses_job_struct *job = wps_ses_find_job_by_id(res->request_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sig = MSF_MEM_ALLOC(MSF_MODID_SEC, sizeof(sec_ti_confirm_dlg_response_t));
    memset(sig, 0, sizeof(sec_ti_confirm_dlg_response_t));		

    /* handle not support certificate type dialog response */
    if (job)
    {
        sig->result = SEC_ERR_CANCEL;
        wps_ses_delete_job(job);
    }
    else
    {
        sig->result = (res->result == WPS_DLG_OK) ? SEC_ERR_OK : SEC_ERR_CANCEL;
    }
    
    MSF_SIGNAL_SEND (MSF_MODID_WPS, MSF_MODID_SEC, SEC_SIG_TI_CONFIRM_DLG_RESPONSE, sig);     				
    wait_for_response = 0;
}

#endif /* WAP_SEC_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wps_http_auth_ind
 * DESCRIPTION
 *  this function is used to handle WPS_SIG_HTTP_AUTH_INDICATION
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_http_auth_ind(wps_http_auth_ind_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* check if the requestId is valid or not */
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;
    int last_auth_failed = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_id = WPS_GET_CHANNEL_ID(p->requestId);
    request_idx = WPS_GET_REQUEST_ID(p->requestId);

    if(channel_id == 0xff || request_idx == 0xff)
    {
        EXT_ASSERT(0, 0,0,0);
    }

    /* check if channel exists */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        ASSERT(0);
    }

    /* check if reqeust exists */
    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        ASSERT(0);
    }

    /* If username is not NULL then it implies that previous authentication failed.*/
    if(req_info->username != NULL)
    {
        last_auth_failed = TRUE;
    }
    
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->username);
    req_info->username = NULL;
    MSF_MEM_FREE(MSF_MODID_WPS, req_info->password);
    req_info->password = NULL;

    if (chl_info->server_auth_username == NULL || strlen((char*)chl_info->server_auth_username) == 0)
    {
        /* send MSG_ID_WPS_HTTP_AUTH_IND to the source of HTTP request if no default server authentication username/password */
        wps_send_http_auth_ind(
            chl_info->mod_id,
            req_info->channel_id,
            req_info->request_id,
            (kal_uint8) p->authType,
            (kal_uint8*) p->realm);
    }
    else
    {
        if (last_auth_failed)
        {
            /* Abort the authentication because username is already sent */
            HDIc_widgetAction(MSF_MODID_STK, 0xfffffffe, req_info->stk_request_id);
        }
        else
        {
            /* store the username & password */
            req_info->username = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)chl_info->server_auth_username);
            req_info->password = (kal_uint8*) msf_cmmn_strdup(MSF_MODID_WPS, (const char*)chl_info->server_auth_password);
        
            /* notify STK to use the username and password */
            HDIc_widgetAction(MSF_MODID_STK, 0xffffffff, req_info->stk_request_id);
        }
    }
    MSF_MEM_FREE(MSF_MODID_WPS, p->realm);
    MSF_MEM_FREE(MSF_MODID_WPS, p->username);
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_pipe_notify
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_pipe_notify(msf_pipe_notify_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search corresponding request info by pipe handle */
    req_info = wps_search_req_info_by_pipe(p->handle);

    if (req_info == NULL)
    {
        /* delete and remove pipe */
        MSF_MEM_FREE(MSF_MODID_WPS, p);
        return;
    }

    switch (p->eventType)
    {
        case MSF_PIPE_EVENT_CLOSED:
            if (req_info->state == WPS_REQ_POSTING)
            {
                wps_process_post_result(req_info, WPS_WRITE_SOURCE_CLOSED);
            }
            else if (req_info->state == WPS_REQ_WAIT_RSP || req_info->state == WPS_REQ_WAIT_CONTENT)
            {
                wps_process_reply_content(req_info, WPS_READ_SOURCE_CLOSED);
            }
            break;
        case MSF_PIPE_EVENT_CLOSED_ERROR:
            if (req_info->state == WPS_REQ_POSTING)
            {
                wps_process_post_result(req_info, WPS_WRITE_UNKNOWN_ERROR);
            }
            else if (req_info->state == WPS_REQ_WAIT_RSP || req_info->state == WPS_REQ_WAIT_CONTENT)
            {
                wps_process_reply_content(req_info, WPS_READ_UNKNOWN_ERROR);
            }
            break;
        case MSF_PIPE_EVENT_READ:
            {
                wps_chl_info_struct *chl_info = g_wps_cntx.channel_info[req_info->channel_id];
                if(chl_info->conn_type == STK_CONNECTION_TYPE_TLS)
                {
                    goto end;
                }
                else if(req_info->reply_type == WPS_DATA_TYPE_FILE && !(req_info->flag & WPS_FLAG_FILE_NO_PROG_IND) && req_info->ind_sent)
                {
                    goto end;
                }
            }
            wps_read_reply_content(req_info);
            break;
        case MSF_PIPE_EVENT_WRITE:
            wps_write_post_content(req_info);
            break;
        default:
            ASSERT(0);
    }
end:
    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_channel_in_use
 * DESCRIPTION
 *  this function will be called to check if any channel in use exists
 * PARAMETERS
 *  net_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int wps_channel_in_use(int net_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* deactivate bearer if no active channel exists */
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        if (g_wps_cntx.channel_info[i] != NULL && g_wps_cntx.channel_info[i]->net_id == net_id)
        {
            return 1;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_auth_username
 * DESCRIPTION
 *  this function will be called to get the username of
 *  the authentication of a request
 * PARAMETERS
 *  requestId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_get_auth_username(int requestId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = WPS_GET_CHANNEL_ID(requestId);
    request_idx = WPS_GET_REQUEST_ID(requestId);

    if(channel_id == 0xff || request_idx == 0xff)
    {
        EXT_ASSERT(0, 0, 0, 0);
    }

    /* check if channel exists */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        ASSERT(0);
    }

    /* check if reqeust exists */
    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        ASSERT(0);
    }

    if (req_info->username == NULL || strlen((char*)req_info->username) == 0)
        ASSERT(0);
   
    return (char*)req_info->username;
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_auth_password
 * DESCRIPTION
 *  this function will be called to get the password of
 *  the authentication of a request
 * PARAMETERS
 *  requestId       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *wps_get_auth_password(int requestId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 request_idx;
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = WPS_GET_CHANNEL_ID(requestId);
    request_idx = WPS_GET_REQUEST_ID(requestId);

    if(channel_id == 0xff || request_idx == 0xff)
    {
        EXT_ASSERT(0, 0,0,0);
    }

    /* check if channel exists */
    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        ASSERT(0);
    }

    /* check if reqeust exists */
    req_info = chl_info->request_info[request_idx];
    if (req_info == NULL || req_info->state != WPS_REQ_WAIT_RSP)
    {
        ASSERT(0);
    }

    return (char*)req_info->password;
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_channel_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stk_request_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int wps_get_channel_id(int stk_request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        chl_info = g_wps_cntx.channel_info[i];

        if (chl_info == NULL)
        {
            continue;
        }

        for (j = 0; j < WPS_MAX_REQUESTS; j++)
        {
            req_info = chl_info->request_info[j];
            if (req_info == NULL)
            {
                continue;
            }

            if (req_info->stk_request_id == stk_request_id)
            {
                return i;
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  wps_get_request_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  stk_request_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int wps_get_request_id(int stk_request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WPS_MAX_CHANNELS; i++)
    {
        chl_info = g_wps_cntx.channel_info[i];

        if (chl_info == NULL)
        {
            continue;
        }

        for (j = 0; j < WPS_MAX_REQUESTS; j++)
        {
            req_info = chl_info->request_info[j];
            if (req_info == NULL)
            {
                continue;
            }

            if (req_info->stk_request_id == stk_request_id)
            {
                return j;
            }
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_connection_created
 * DESCRIPTION
 *  Handle STK_SIG_STREAM_CONNECTION_CREATED signal
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_stream_connection_created(stk_stream_connection_created_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_req_info_struct *req_info;
    wps_chl_info_struct *chl_info;
    int pipe_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id */
    channel_id = p->connectionId - 1;

    chl_info = g_wps_cntx.channel_info[channel_id];
    if (chl_info == NULL)
    {
        MSF_PIPE_DELETE(p->receivePipeName);
        STKif_closeConnection(MSF_MODID_WPS, p->connectionId);
        return;
    }

    req_info = chl_info->request_info[0];
    req_info->state = WPS_REQ_CONNECTED;

    /* update socket ID and security ID*/
    chl_info->socket_id = p->socketId;
    chl_info->security_id = p->socketId;


    pipe_handle = MSF_PIPE_OPEN(MSF_MODID_WPS, p->receivePipeName);

    if (pipe_handle < 0)
    {
        /* send back response and delete content */
        wps_send_create_stream_connection_rsp(chl_info->mod_id, channel_id, WPS_ERROR_NO_RESOURCE);
        MSF_PIPE_DELETE(p->receivePipeName);
        STKif_closeConnection(MSF_MODID_WPS, p->connectionId);
        wps_clear_request(channel_id, 0);
        wps_clear_channel(channel_id);
        return;
    }

    req_info->recv_pipe_name = msf_cmmn_strdup(MSF_MODID_WPS, p->receivePipeName);
    req_info->pipe_handle = pipe_handle;

    wps_send_create_stream_connection_rsp(chl_info->mod_id, channel_id, WPS_OK);

    MSF_MEM_FREE(MSF_MODID_WPS, p);
}


/*****************************************************************************
 * FUNCTION
 *  wps_stream_connection_closed
 * DESCRIPTION
 *  Handle STK_SIG_CONNECTION_CLOSED signal
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wps_stream_connection_closed(stk_connection_closed_t* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 channel_id;
    wps_chl_info_struct *chl_info;
    wps_req_info_struct *req_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_id = p->connectionId - 1;
    
    chl_info = g_wps_cntx.channel_info[channel_id];

    if (chl_info == NULL)
    {
        return;
    }
    
    req_info = chl_info->request_info[0];
    
    if(req_info->state == WPS_REQ_CONNECTING)
    {
        wps_send_create_stream_connection_rsp(chl_info->mod_id, channel_id, p->errorCode);
    }
    else
    {
        wps_send_stream_connection_close_ind(chl_info->mod_id, channel_id, p->errorCode);
    }

    wps_clear_request(channel_id, 0);
    wps_clear_channel(channel_id);
}



#endif /* WPS_SUPPORT */ 

