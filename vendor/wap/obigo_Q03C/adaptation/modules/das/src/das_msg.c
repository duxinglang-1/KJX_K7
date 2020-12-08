#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   das_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines primitive related functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_int.h"
//#include "msf_lib.h"
//#include "msf_core.h"
//#include "msf_mem.h"
#include "msf_chrs.h"

//#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "app_buff_alloc.h"

//#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
//#include "custom_config.h"

#include "app_str.h"

//#include "fat_fs.h"
//#include "wap_ps_struct.h"

#include "das_main.h"
#include "das_msg.h"

#include "das_struct.h"
#include "DLAgentSrvDef.h"
#include "cbm_api.h"


    #include "kal_general_types.h"
    #include "string.h"
    #include "msf_cfg.h"
    #include "MMI_features.h"
    #include "cbm_consts.h"
    #include "stack_config.h"
    #include "stack_ltlcom.h"
    #include "wps_struct.h"
    #include "kal_public_api.h"
    #include "fs_func.h"
    #include "fs_type.h"


/*****************************************************************************
 * FUNCTION
 *  das_send_dl_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_src                 [IN]        
 *  data_type               [IN]        
 *  url                     [IN]        
 *  mime_type               [IN]        
 *  path                    [IN]        
 *  file_name               [IN]        
 *  header                  [IN]        
 *  network_account_id      [IN]
 *  attr_len                [IN]
 *  attr_string             [IN]
 * RETURNS
 *  
 *****************************************************************************/
int das_send_dl_ind(
        MSF_UINT8 mod_src,
        MSF_UINT8 data_type,
        const char *url,
        const char *mime_type,
        const kal_uint8 *path,
        const kal_uint8 *file_name,
        const char *header,
        MSF_INT32 network_account_id,
        MSF_INT32 attr_len,
        unsigned char *attr_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    mmi_da_dispatch_file_var_struct *peer_pdu = NULL;
    mmi_da_dispatch_file_req_struct *p;
    kal_uint16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_RESET);
    p->mime_type = 0;
    p->mime_subtype = 0;
    if(attr_len > 0 && attr_len <= SRV_DA_MAX_EXTRA_INFO_DATA_SIZE)
    {
        p->extra_info.size = (kal_uint32)attr_len;
        memcpy(p->extra_info.data, attr_string, attr_len);
    }    
    else
    {
        p->extra_info.size = 0;
    }
    p->ui_setting.title_string_id = 0 ; 
	p->ui_setting.title_icon_id = 0;
    memset(p->url, 0, sizeof(p->url));
#if 0
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM != 2)
/* under construction !*/
    #else /* (MMI_MAX_SIM_NUM == 2) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (MMI_MAX_SIM_NUM == 2)*/ 
/* under construction !*/
/* under construction !*/
#ifdef OBIGO_Q03C_MMS_V01
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*OBIGO_Q03C_MMS_V01*/
#endif
  if (data_type == MsfResourceFile)
    {
        p->action = MMI_DA_SAVE_AS;
    }
    else
    {
        p->action = MMI_DA_WAP_DOWNLOAD;

        if (url != NULL && strlen(url) > 0)
        {
            strncpy((char*)p->url, url, strlen(url) > sizeof(p->url) ? sizeof(p->url) : strlen(url));
        }
        else
        {
            strcpy((char*)p->url, "http://");
        }
    }

    memset(p->filepath, 0, sizeof(p->filepath));
    app_ucs2_strcpy((kal_int8*) p->filepath, (const kal_int8*)path);
    if (file_name)
    {
        app_ucs2_strcpy((kal_int8*) p->filename, (const kal_int8*)file_name);
    }

    if (mime_type)
    {
        strcpy((char*)p->mime_type_string, (const char*)mime_type);
    }

    if (!header)
    {
        goto end;
    }

    peer_buff_ptr = construct_peer_buff((kal_uint16)(sizeof(mmi_da_dispatch_file_var_struct) + strlen(header)), 0, 0, TD_RESET);

    peer_pdu = (mmi_da_dispatch_file_var_struct*) get_pdu_ptr(peer_buff_ptr, &length);
    peer_pdu->header_len = strlen(header);
    memcpy(peer_pdu->header, header, peer_pdu->header_len);

  end:
    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_MMI_DA_DISPATCH_FILE_REQ;     /* Set the message id */
    ilm_ptr->peer_buff_ptr = peer_buff_ptr; /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  das_send_file_dl_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void das_send_file_dl_ind(das_job_t *job, kal_bool content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long len, dest_len = WAP_DL_MAX_FILE_NAME_LEN - 2;
    kal_uint16 length;
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_ind_struct *p;
    peer_buff_struct *peer_buff_ptr = NULL;
    wap_mmi_file_dl_var_struct var = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmi_file_dl_ind_struct*) construct_local_para(sizeof(wap_mmi_file_dl_ind_struct), TD_RESET);
    p->session_id = job->id;

    memset(p->url, 0, WAP_DL_MAX_URL_LEN);
    if (job->url)
    {
        len = strlen(job->url);
        strncpy((char*)p->url, job->url, len > WAP_DL_MAX_URL_LEN ? WAP_DL_MAX_URL_LEN : len);
    }

    memset(p->mime_type, 0, WAP_DL_MAX_MIME_TYPE_LEN);
    if (job->mime_type)
    {
        len = strlen(job->mime_type);
        strncpy((char*)p->mime_type, job->mime_type, len > WAP_DL_MAX_MIME_TYPE_LEN ? WAP_DL_MAX_MIME_TYPE_LEN : len);
    }

    memset(p->file_name, 0, WAP_DL_MAX_FILE_NAME_LEN);
    if (job->file_name)
    {
        len = strlen(job->file_name);
        msf_charset_utf8_to_ucs2le(job->file_name, &len, (char*)p->file_name, &dest_len);
    }

    p->file_length = job->total_size;

    if (job->header)
    {
        var.header_len = strlen(job->header);
        var.header = (kal_uint8*) job->header;
    }

    p->with_content = content;
    if (job->buffer_tail > 0)
    {
        var.content_len = job->buffer_tail;
        var.content = (kal_uint8*) job->buffer;
    }

    len = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WAP_MMI_FILE_DL_IND, (void*)&var, NULL);
    if (len > 0)
    {
        peer_buff_ptr = construct_peer_buff((kal_uint16)len, 0, 0, TD_RESET);
        if (wps_pun_var_part
            (WPS_PUN_PACK, MSG_ID_WAP_MMI_FILE_DL_IND, (void*)&var, get_pdu_ptr(peer_buff_ptr, &length)) != len)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_IND;  /* Set the message id */
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  das_send_file_dl_progress_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void das_send_file_dl_progress_ind(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_progress_ind_struct *p;
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(session_id);

    p = (wap_mmi_file_dl_progress_ind_struct*) construct_local_para(
                                                sizeof(wap_mmi_file_dl_progress_ind_struct),
                                                TD_RESET);
    p->session_id = session_id;

    if (!job)
    {
        p->seq_num = 0;
        p->acc_size = 0;
    }
    else
    {
        if (job->status == DAS_STATUS_DOWNLOADING)
        {
            p->status = WAP_DL_STATUS_DOWNLOADING;
            p->cause = WAP_DL_ERROR_OK;
        }
        else if (job->status == DAS_STATUS_COMPLETE)
        {
            p->status = WAP_DL_STATUS_COMPLETE;
            p->cause = WAP_DL_ERROR_OK;
        }
        else
        {
            p->status = WAP_DL_STATUS_ABORTED;
            p->cause = job->cause;
        }
        p->seq_num = ++job->seq_num;
        p->acc_size = job->download_size;
        job->indication_sent = TRUE;
        job->status = DAS_STATUS_WAITING;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND; /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  das_send_dl_stop_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void das_send_dl_stop_rsp(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_stop_rsp_struct *p;
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmi_file_dl_stop_rsp_struct*) construct_local_para(sizeof(wap_mmi_file_dl_stop_rsp_struct), TD_RESET);

    p->session_id = session_id;
    p->status = WAP_DL_STATUS_CANCELLED;

    job = das_find_job_by_session_id(session_id);

    if (!job)
    {
        p->seq_num = 0;
        p->cause = WAP_DL_ERROR_INVALID_SESSION_ID;
        p->acc_size = 0;
    }
    else
    {
        p->seq_num = ++job->seq_num;
        p->cause = WAP_DL_ERROR_CANCELLED;
        p->acc_size = job->download_size;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_STOP_RSP;     /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  das_file_dl_res_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int das_file_dl_res_hdlr(wap_mmi_file_dl_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;
    int file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(res->session_id);

    if (!job)
    {
        das_send_file_dl_progress_ind(res->session_id); /* Invalid Session Id */
        return 0;
    }
#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)
    if (res->result == WAP_DL_ERROR_NEED_CONTENT)
    {
        job->status = DAS_STATUS_PREFETCHING;
        return 1;
    }
#endif
    if (res->result != WAP_DL_ERROR_OK)
    {
        job->cause = DAS_ERR_USER_CANCELLED;
        job->status = DAS_STATUS_ABORTED;
    }
    else
    {
        ASSERT(job->status != DAS_STATUS_WAITING);

        FS_Delete((WCHAR*) res->file_path);

        file_handle = FS_Open((WCHAR*) res->file_path, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

        if (file_handle <= 0)
        {
            job->cause = file_handle;
            job->status = DAS_STATUS_ABORTED;
        }
        else
        {
            job->file_handle = file_handle;
            job->status = DAS_STATUS_DOWNLOADING;
            if (job->buffer_tail > 0)
            {
                das_write_data_to_file(job);
            }
        }
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  das_file_dl_progress_res_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int das_file_dl_progress_res_hdlr(wap_mmi_file_dl_progress_res_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(res->session_id);

    if (!job)
    {
        return -1;
    }

    job->indication_sent = 0;
    job->status = DAS_STATUS_DOWNLOADING;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  das_file_dl_stop_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int das_file_dl_stop_req_hdlr(wap_mmi_file_dl_stop_req_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(res->session_id);

    if (!job)
    {
        das_send_dl_stop_rsp(res->session_id);
        return 0;
    }

    job->status = DAS_STATUS_ABORTED;
    job->cause = DAS_ERR_USER_CANCELLED;
    das_send_dl_stop_rsp(res->session_id);
    return 1;
}

#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)
/*****************************************************************************
 * FUNCTION
 *  das_send_file_dl_prefetch_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void das_send_file_dl_prefetch_abort_req(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    das_job_t *job;
    wap_mmi_file_dl_prefetch_aborted_ind_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(session_id);

    p = (wap_mmi_file_dl_prefetch_aborted_ind_struct*) construct_local_para(
                                                sizeof(wap_mmi_file_dl_prefetch_aborted_ind_struct),
                                                TD_RESET);
    if (!job)
    {
        p->session_id = session_id;
        p->cause = WAP_DL_ERROR_INVALID_SESSION_ID;
    }
    else
    {
        p->session_id = session_id;
        p->cause = job->cause;
    }

    ilm_ptr = allocate_ilm(MOD_WAP);

    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_PREFETCH_ABORTED_IND; /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}



/*****************************************************************************
 * FUNCTION
 *  das_send_dl_cancel_prefetch_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void das_send_dl_cancel_prefetch_rsp(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wap_mmi_file_dl_cancel_prefetch_rsp_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (wap_mmi_file_dl_cancel_prefetch_rsp_struct*) construct_local_para (
        sizeof(wap_mmi_file_dl_cancel_prefetch_rsp_struct), TD_RESET);

    p->session_id = session_id;
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_RSP;     /* Set the message id */
    ilm_ptr->peer_buff_ptr = NULL;  /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    return;
}



/*****************************************************************************
 * FUNCTION
 *  das_file_dl_cancel_prefetch_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int das_file_dl_cancel_prefetch_req_hdlr(wap_mmi_file_dl_cancel_prefetch_req_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_session_id(res->session_id);

    if (!job)
    {
        das_send_dl_cancel_prefetch_rsp(res->session_id);
        return 0;
    }
    das_send_dl_cancel_prefetch_rsp(res->session_id);
    job->status = DAS_STATUS_ABORTED;
    job->cause = DAS_ERR_USER_CANCELLED;
    return 1;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  das_handle_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int das_handle_message(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = (ilm_struct*) p;
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_WAP_MMI_FILE_DL_RES:
            ret = das_file_dl_res_hdlr((wap_mmi_file_dl_res_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES:
            ret = das_file_dl_progress_res_hdlr((wap_mmi_file_dl_progress_res_struct*) ilm_ptr->local_para_ptr);
            break;
        case MSG_ID_WAP_MMI_FILE_DL_STOP_REQ:
            ret = das_file_dl_stop_req_hdlr((wap_mmi_file_dl_stop_req_struct*) ilm_ptr->local_para_ptr);
            break;
#if defined(__MMI_VIDEO_PDL__) || defined(__MMI_AUDIO_PDL__)
        case MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_REQ:
            ret = das_file_dl_cancel_prefetch_req_hdlr((wap_mmi_file_dl_cancel_prefetch_req_struct*) ilm_ptr->local_para_ptr);
            break;
#endif

        default:
            return 0;
    }
    if (ret)
    {
        das_wantsToRun = 1;
    }
    return 1;
}


#endif /*OBIGO_Q03C_BROWSER*/
