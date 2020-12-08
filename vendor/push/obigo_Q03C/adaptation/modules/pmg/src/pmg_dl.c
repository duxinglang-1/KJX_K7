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
 *   pmg_dl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions for forward push message to DL handling
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_pipe.h"
#include "msf_file.h"
//#include "msf_dcvt.h"
//#include "msf_log.h"
//#include "msf_lib.h"
#include "msf_hdr.h"
#include "msf_url.h"
#include "msf_chrs.h"
#include "Cbm_api.h"
//#include "wps_struct.h"
//#include "custom_events_notify.h"
//#include "CommonScreens.h"
//#include "filemanagergprot.h"
//#include "wap_cmn.h"
//#include "fat_fs.h"
//#include "ctk.h"
#include "DLAgentSrvDef.h"
#include "pmg_dl.h"
#include "pmg_if.h"
#include "pmg_main.h"
//#include "pmg_phs.h"
#include "pmg_env.h"
//#include "WAPPushResDef.h"
#include "GlobalResDef.h"

//suggested add
    #include "kal_general_types.h"
    #include "msf_cmmn.h"
    #include "string.h"
    #include "fs_func.h"
    #include "fs_type.h"
    #include "app_ltlcom.h"
    #include "MMI_features.h"
    #include "cbm_consts.h"
    #include "stack_config.h"
    #include "stack_ltlcom.h"
    #include "stack_msgs.h"
    #include "stack_common.h"
    #include "task_config.h"
    #include "kal_public_api.h"
    #include "stdio.h"
    #include "MMIDataType.h"
    #include "fs_errcode.h"
    #include "pmg_struct.h"
#ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_mmi_wap_push_def.h"
#endif /*__COSMOS_MMI_PACKAGE__*/

static pmg_job_t *pmg_job_queue;
static pmg_job_t *pmg_job_queue_last;
static MSF_BOOL is_pmg_completed;

static int flush_buffer(pmg_job_t *job);

static int pmg_process_push_download_result(pmg_job_t *job);

static int write_to_buffer(pmg_job_t *job, char *buf, unsigned int size);


static int pmg_get_drive_free_space(const char *file_name);

static void pmg_display_error(int cause);

static void pmg_add_job(pmg_job_t *job);

extern kal_int8 *app_ucs2_strcpy(kal_int8 *strDestination, const kal_int8 *strSource);

extern kal_uint8 *HDIa_fileGetExternalFileName(MSF_UINT8 modId, const char * src);

kal_uint8 *pmg_get_push_location(int id, const char *file_name, int size);

static void pmg_handle_buffer_content(int id, MSF_UINT8 mod_src, const char *url,
							const char *mime_type, const unsigned char *data, MSF_INT32 data_len,
							const char *src_path, const char *file_name, const char *header,
							MSF_INT32 network_account_id, MSF_INT32 attr_len, unsigned char *attr_string);

static int pmg_send_dl_ind(MSF_UINT8 mod_src, MSF_UINT8 data_type, const char *url, const char *mime_type,
						   const kal_uint8 *path, const kal_uint8 *file_name, const char *header,
						   MSF_INT32 network_account_id, MSF_INT32 attr_len, unsigned char *attr_string);

static void pmg_handle_file_content(int id, MSF_UINT8 mod_src, const char *url, const char *mime_type,
							const unsigned char *data, MSF_INT32 data_len, const char *src_path, const char *file_name,
							const char *header, MSF_INT32 network_account_id);

void pmg_abort_download(pmg_job_t *job, int cause);

static pmg_job_t *pmg_create_job(int id, MSF_UINT8 mod_id, const char *url, const char *mime_type, MsfResourceType data_type,
							const unsigned char *data, MSF_INT32 data_len, const char *pipe_name, const char *file_name);

static int pmg_handle_push_pipe_content(int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id,
    MSF_INT32 attr_len,
    unsigned char *attr_string);
/*****************************************************************************
 * FUNCTION
 *  pmg_dl_handle_content_data_route
 * DESCRIPTION
 *  initialise PMG's inbox component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int pmg_dl_handle_content_data_route(MSF_UINT8 src_modId, void *p)
{
    
    /* Dump data in file and Notify to DLA  */

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_content_send_t *send = (pmg_content_send_t*) p;
	pmg_content_data_t *contentData = (pmg_content_data_t*) (send->contentData);
    char *filename = NULL;
    char *contentType = NULL;
    long data_length = 0;
	MSF_UINT32 content_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!send->contentDataExists)
    {
        return FALSE;
    }

    if (contentData->contentDataType == MSF_CONTENT_DATA_NONE)  /* Downloading data */
    {
        return FALSE;   /* Not handled */
    }

    if (contentData->contentHeaders != NULL)
    {
        msf_hdr_t *hdr = msf_hdr_create(MSF_MODID_PMG);

        msf_hdr_add_headers_from_text(hdr, contentData->contentHeaders);

        /* To extract content type from header for the case that routingIdentifier is not a MIME type */
        contentType = msf_cmmn_strdup(MSF_MODID_PMG, msf_hdr_get_string(hdr, MSF_HDR_CONTENT_TYPE));

        {
            /* Try to obtain the correct filename from header */
            filename = msf_cmmn_strdup(
                        MSF_MODID_PMG,
                        msf_hdr_get_parameter(hdr, MSF_HDR_CONTENT_DISPOSITION, "filename"));
        }

        /* To obtain the content length from header */
        if (msf_hdr_get_uint32(hdr, MSF_HDR_CONTENT_LENGTH, &content_length) && (content_length > 0))
        {
            data_length = (long)content_length;
        }

        msf_hdr_delete(hdr);
    }

    if (!contentType || strlen(contentType) == 0)
    {
        /* Use routingIdentifier instead if we cannnot find Content Type in header */
        contentType = msf_cmmn_strdup(MSF_MODID_PMG, contentData->routingIdentifier);
    }

    /* To generate a default filename if it is not available in header */
    if (filename == NULL && contentData->contentUrl != NULL)
    {
        char *s;
        char *f;
        int len = 0;

        s = msf_url_get_path(MSF_MODID_PMG, (const char*)contentData->contentUrl);
        if (s != NULL)
        {
            f = strrchr(s, '/');
            if (f != NULL)
            {
                filename = msf_cmmn_strdup(MSF_MODID_PMG, (f + 1));
            }
            else
            {
                filename = msf_cmmn_strdup(MSF_MODID_PMG, s);
            }
			msf_url_unescape_string_in_place(filename,filename);
            PMG_MEM_FREE(s);
        }
        else
        {
            len = strlen (PMG_DEFAULT_FILENAME) + 1;
            filename = pmg_mem_alloc(len);
            memset(filename, 0, len);
            strncpy(filename, PMG_DEFAULT_FILENAME, (len -1));
        }
    }

    job_count++;

    switch (contentData->contentDataType)
    {
        case MSF_CONTENT_DATA_RAW:
            pmg_handle_buffer_content(
                job_count,
                src_modId,
                contentData->contentUrl,
                contentType,
                contentData->contentData,
                contentData->contentDataLength,
                contentData->contentSource,
                filename,
                contentData->contentHeaders,
                contentData->networkAccountId,
                contentData->attrLength,
                contentData->attrString);
            break;

        case MSF_CONTENT_DATA_FILE:
            pmg_handle_file_content(
                job_count,
                src_modId,
                contentData->contentUrl,
                contentType,
                contentData->contentData,
                data_length,
                contentData->contentSource,
                filename,
                contentData->contentHeaders,
                contentData->networkAccountId);
            break;

        case MSF_CONTENT_DATA_PIPE:
                pmg_handle_push_pipe_content(
                    job_count,
                    src_modId,
                    contentData->contentUrl,
                    contentType,
                    contentData->contentData,
                    data_length,
                    contentData->contentSource,
                    filename,
                    contentData->contentHeaders,
                    contentData->networkAccountId,
                    contentData->attrLength,
                    contentData->attrString);
            break;

        default:
            break;
    }

    PMG_MEM_FREE(contentType);
    PMG_MEM_FREE(filename);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_handle_push_pipe_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id                      [IN]        
 *  mod_src                 [IN]        
 *  url                     [IN]        
 *  mime_type               [IN]        
 *  data                    [IN]        
 *  data_len                [IN]        
 *  src_path                [IN]        
 *  file_name               [IN]        
 *  header                  [IN]        
 *  network_account_id      [IN] 
 *  attr_len                [IN]
 *  attr_string             [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int
pmg_handle_push_pipe_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id,
    MSF_INT32 attr_len,
    unsigned char *attr_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pipe_handle;
    pmg_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pipe_handle = MSF_PIPE_OPEN(MSF_MODID_PMG, src_path);
    if (pipe_handle < 0)
    {
        return FALSE;
    }

    job = pmg_create_job(id, mod_src, url, mime_type, MsfResourcePipe, NULL, data_len, src_path, NULL);

    job->pipe_handle = pipe_handle;
    job->network_account_id = network_account_id;

    job->file_name = (char*)pmg_get_push_location(id, "pushmsg", data_len);

    if (!job->file_name)
    {
        goto error;
    }

    if (header)
    {
        job->header = msf_cmmn_strdup(MSF_MODID_PMG, header);
    }
    pmg_add_job(job);

    FS_Delete((WCHAR*) job->file_name);

    job->file_handle = FS_Open((WCHAR*) job->file_name, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

    if (job->file_handle <= 0)
    {
        goto error;
    }
    job->status = PMG_STATUS_DOWNLOADING;

    if(attr_len > 0)
    {
        job->attr_len = attr_len;
        job->attr_string = pmg_mem_alloc(attr_len);
        if(job->attr_string == NULL)
        {
            goto error;
        }
        memcpy(job->attr_string, attr_string, attr_len);
    }

    pmg_read_push_pipe_data(job);

    return TRUE;

  error:
    pmg_delete_job(job);
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  pmg_delete_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_delete_job(pmg_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_job_t *prev_job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pmg_job_queue == job)
    {
        pmg_job_queue = job->next;
    }
    else
    {

        prev_job = pmg_job_queue;

        while (prev_job != NULL)
        {
            if (prev_job->next == job)
            {
                prev_job->next = job->next;
                break;
            }
            prev_job = prev_job->next;
        }
    }

    if (pmg_job_queue_last == job)
    {
        pmg_job_queue_last = prev_job;
    }

    if (job->status == PMG_STATUS_DOWNLOADING || job->status == PMG_STATUS_PREFETCHING || job->status == PMG_STATUS_PREFETCHING_COMPLETED)
    {
        if (job->file_handle > 0)
        {
            FS_Close(job->file_handle);
            FS_Delete((WCHAR*) job->file_name);
        }

        if (job->pipe_handle > 0)
        {
            MSF_PIPE_CLOSE(job->pipe_handle);
            MSF_PIPE_DELETE(job->pipe_name);
        }
    }

    PMG_MEM_FREE(job->mime_type);
    PMG_MEM_FREE(job->url);
    PMG_MEM_FREE(job->pipe_name);

    PMG_MEM_FREE(job->file_name);

    PMG_MEM_FREE(job->header);
    PMG_MEM_FREE(job->attr_string);
    PMG_MEM_FREE(job);

    /* If there is no more pending job, remove browser if necessary */
    if ((!pmg_job_queue) && (!is_pmg_completed))
    {
      //  BRAif_downloadComplete(BRA_DNSTATUS_OK);
    }
}

/*****************************************************************************
 * FUNCTION
 *  pmg_set_browser_destroy_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  destroy       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void pmg_set_browser_destroy_flag (MSF_BOOL destroy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    is_pmg_completed = destroy;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_read_push_pipe_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int pmg_read_push_pipe_data(pmg_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int bufsize = 1024;
    char *buf;
    int bytes_read;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buf = pmg_mem_alloc(bufsize);
    do
    {
        bytes_read = MSF_PIPE_READ(job->pipe_handle, buf, bufsize);

        if (bytes_read > 0)
        {
            ret = write_to_buffer(job, buf, bytes_read);
            if (ret < 0)
            {
                goto error;
            }

            job->download_size += bytes_read;
        }
    } while (bytes_read >= 0);

    if (bytes_read == MSF_PIPE_ERROR_DELAYED)
    {
        MSF_PIPE_POLL(job->pipe_handle);
    }
    else if (bytes_read == MSF_PIPE_ERROR_CLOSED)
    {
        pmg_process_push_download_result(job);
    }
    else
    {
        goto error;
    }
    PMG_MEM_FREE(buf);
    return TRUE;

  error:
    pmg_delete_job(job);
    PMG_MEM_FREE(buf);
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  pmg_send_dl_ind
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
static int pmg_send_dl_ind(
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
	#if(MMI_MAX_SIM_NUM >= 2)
	kal_uint32		sim_id;
	#endif

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

    if (mod_src == MSF_MODID_PHS)
    {
#if(MMI_MAX_SIM_NUM >= 2)
        
sim_id = cbm_get_sim_id((kal_uint32) network_account_id);

switch(sim_id)
        {
case CBM_SIM_ID_SIM1:
	 p->action = MMI_DA_PUSH_SIM1;
	 break;

case CBM_SIM_ID_SIM2:
            p->action = MMI_DA_PUSH_SIM2;
	 break;
	#if(MMI_MAX_SIM_NUM >= 3)	
 case CBM_SIM_ID_SIM3:
	 p->action = MMI_DA_PUSH_SIM3;
	 break;	 
	#endif	 
 
	#if(MMI_MAX_SIM_NUM >= 4)	 
 case CBM_SIM_ID_SIM4:
	 p->action = MMI_DA_PUSH_SIM4;
	 break;
	#endif
    
default:
            p->action = MMI_DA_PUSH_SIM1;
	break; // add some log for wrong sim_id;
        }
#else	
	p->action = MMI_DA_PUSH;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
	
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
    ilm_ptr = allocate_ilm(MOD_WPS);

    ilm_ptr->msg_id =  MSG_ID_MMI_DA_DISPATCH_FILE_REQ;     /* Set the message id */
    ilm_ptr->peer_buff_ptr = peer_buff_ptr; /* there are no peer message */
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    SEND_ILM(MOD_WPS, MOD_MMI, WPS_APP_SAP, ilm_ptr);
    return 1;
}



/*****************************************************************************
 * FUNCTION
 *  pmg_get_drive_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_get_drive_free_space(const char *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    FS_DiskInfo diskinfo;
    kal_uint8 *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	path = (MSF_UINT8*)MSF_FILE_GET_EXTERNAL_FILENAME(MSF_MODID_PMG, file_name );
    result = FS_GetDiskInfo((WCHAR*) path, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);


	PMG_MEM_FREE(path);

    if (result < 0)
    {
        return result;
    }
    return diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_get_push_location
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id              [IN]        
 *  file_name       [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *pmg_get_push_location(int id, const char *file_name, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *path = "/push/";
    char *temp, *temp2;
    char temp_ext[24] = "";
    kal_uint8 *dest_file;
    int r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_FILE_MKDIR("/push/" );

    r = pmg_get_drive_free_space(path);
    if (r < size)
    {
        return NULL;
    }

    temp = msf_cmmn_strcat(MSF_MODID_PMG, path, file_name);
    sprintf(temp_ext, ".t%02d", (short)(id % 10));
    temp2 = msf_cmmn_strcat(MSF_MODID_PMG, temp, temp_ext);

    /* Convert to UCS2 filename here, need to be freed by caller */
	dest_file = (MSF_UINT8*)MSF_FILE_GET_EXTERNAL_FILENAME(MSF_MODID_PMG, temp2 );

	PMG_MEM_FREE(temp);
    PMG_MEM_FREE(temp2);
    return dest_file;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_handle_buffer_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id                      [IN]        
 *  mod_src                 [IN]        
 *  url                     [IN]        
 *  mime_type               [IN]        
 *  data                    [IN]        
 *  data_len                [IN]        
 *  src_path                [IN]        
 *  file_name               [IN]        
 *  header                  [IN]        
 *  network_account_id      [IN]  
 *  attr_len                [IN]
 *  attr_string             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void
pmg_handle_buffer_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id,
    MSF_INT32 attr_len,
    unsigned char *attr_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int file_handle;
    int size_remain;
    int bytes_written;
    int size;
    kal_uint8 *in_filename = NULL;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_name == NULL)
    {
        file_name = "pushmsg";
    }

    if (mod_src == MSF_MODID_PHS)
    {
        in_filename = pmg_get_push_location(id, file_name, data_len);
    }
    else
    {
        //TO Do in_filename = pmg_get_save_location(id, file_name, data_len);
    }

    if (!in_filename)
    {
		pmg_display_error(PMG_ERR_SAVE_FULL);
        return;
    }

    FS_Delete((WCHAR*) in_filename);

    file_handle = FS_Open((WCHAR*) in_filename, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

    if (file_handle <= 0)
    {
        pmg_display_error(file_handle);
        return;
    }

    size_remain = data_len;
    bytes_written = 0;

    while (size_remain > 0)
    {
        ret = FS_Write(file_handle, (void*)(data + bytes_written), size_remain, (U32*) & size);
        if (ret != FS_NO_ERROR)
        {
            pmg_display_error(ret);
            FS_Close(file_handle);
            FS_Delete((WCHAR*) in_filename);
            return;
        }
        if (size <= 0)
        {
            break;
        }
        bytes_written += size;
        size_remain -= size;
    }

    FS_Close(file_handle);
    pmg_send_dl_ind(mod_src, MsfResourceBuffer, url, mime_type, in_filename, NULL, header, network_account_id, attr_len, attr_string);
   
    PMG_MEM_FREE(in_filename);

}


/*****************************************************************************
 * FUNCTION
 *  pmg_handle_file_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id                      [IN]        
 *  mod_src                 [IN]        
 *  url                     [IN]        
 *  mime_type               [IN]        
 *  data                    [IN]        
 *  data_len                [IN]        
 *  src_path                [IN]        
 *  file_name               [IN]        
 *  header                  [IN]        
 *  network_account_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void
pmg_handle_file_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *to_filename = NULL, *src_filename = NULL;
    long len, destLen;
    char *destBuffer = NULL;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_path)
    {
        pmg_display_error(PMG_ERR_CREATE_FILE_FAILED);
        goto end;
    }

    if (data_len == 0)
    {
        data_len = MSF_FILE_GETSIZE(src_path );
    }

    if (!file_name || file_name[0] == '\0')
    {
        file_name = "untitled";
    }

    to_filename = pmg_get_push_location(id, file_name, data_len);

    if (!to_filename)
    {
        goto end;
    }

	src_filename = (MSF_UINT8*)MSF_FILE_GET_EXTERNAL_FILENAME(MSF_MODID_PMG, src_path );
    ret = FS_Move((const WCHAR*)src_filename, (const WCHAR*)to_filename, FS_MOVE_COPY | FS_MOVE_OVERWRITE, 0, NULL, 0);

    if (ret != FS_NO_ERROR)
    {
        pmg_display_error(ret);
        goto end;
    }

    len = strlen(file_name) + 1;

    destLen = len * 2;

    destBuffer = (char*)pmg_mem_alloc(destLen);

    msf_charset_utf8_to_ucs2le(file_name, &len, destBuffer, &destLen);

    pmg_send_dl_ind(
        mod_src,
        MsfResourceFile,
        url,
        mime_type,
        to_filename,
        (const kal_uint8*)destBuffer,
        header,
        network_account_id,
        0,
        NULL);
  end:
    PMG_MEM_FREE(destBuffer);
	PMG_MEM_FREE(src_filename);
    PMG_MEM_FREE(to_filename);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_create_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id              [IN]        
 *  mod_id          [IN]        
 *  url             [IN]        
 *  mime_type       [IN]        
 *  data_type       [IN]        
 *  data            [IN]        
 *  data_len        [IN]        
 *  pipe_name       [IN]        
 *  file_name       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static pmg_job_t *pmg_create_job(
                    int id,
                    MSF_UINT8 mod_id,
                    const char *url,
                    const char *mime_type,
                    MsfResourceType data_type,
                    const unsigned char *data,
                    MSF_INT32 data_len,
                    const char *pipe_name,
                    const char *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = pmg_mem_alloc(sizeof(pmg_job_t));

    job->next = NULL;
    job->mod_id = mod_id;
    job->id = id;
    job->pipe_handle = 0;
    job->file_handle = 0;
    job->download_size = 0;
    job->total_size = data_len;
    job->mime_type = msf_cmmn_strdup(MSF_MODID_PMG, mime_type);
    job->url = msf_cmmn_strdup(MSF_MODID_PMG, url);
    job->pipe_name = msf_cmmn_strdup(MSF_MODID_PMG, pipe_name);
    job->file_name = msf_cmmn_strdup(MSF_MODID_PMG, file_name);
    memset(job->buffer, 0, PMG_DL_BUFFER_SIZE);
    job->buffer_tail = 0;
    job->seq_num = 0;
    job->cause = WPS_DL_ERROR_OK;
    job->indication_sent = FALSE;
    job->header = NULL;
    job->network_account_id = -1;
    job->attr_len = 0;
    job->attr_string = NULL;

    return job;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_add_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_add_job(pmg_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pmg_job_queue == NULL)
    {
        pmg_job_queue = job;
    }
    else
    {
        pmg_job_queue_last->next = job;
    }

    pmg_job_queue_last = job;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_display_error
 * DESCRIPTION
 *  Display error dialog
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_display_error(int cause)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 string_id;
	wps_pmg_error_dlg_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cause)
    {
        case PMG_ERR_CONNECTION_ABORT:
	#ifdef 	__COSMOS_MMI_PACKAGE__
			string_id = STR_GLOBAL_ERROR;
	#else
            string_id = STR_ID_BRW_PUSH_REQUEST_TIMED_OUT; /* to be fixed *///BRA_STR_ID_REQUEST_TIMED_OUT;
	#endif /*__COSMOS_MMI_PACKAGE__*/
            break;
        case PMG_ERR_SAVE_FULL:

	#ifdef 	__COSMOS_MMI_PACKAGE__
			string_id = STR_GLOBAL_ERROR;
	#else
            string_id = STR_ID_BRW_PUSH_ERROR_FULL;/*to be fixed*///MSF_STR_ID_SAS_ERROR_FULL;
	#endif /*__COSMOS_MMI_PACKAGE__*/
            break;
	
        case PMG_ERR_SAVE_SIZE:
	#ifdef 	__COSMOS_MMI_PACKAGE__	
			string_id = STR_GLOBAL_ERROR;
	#else
            string_id = STR_ID_BRW_PUSH_ERROR_SIZE;/*to be fixed*///MSF_STR_ID_SAS_ERROR_SIZE;
	#endif /*__COSMOS_MMI_PACKAGE__*/
            break;
        default:
	#ifdef 	__COSMOS_MMI_PACKAGE__	
			string_id = STR_GLOBAL_ERROR;
	#else		
            string_id = STR_ID_BRW_PUSH_DLG_SAVE_ERROR;/* to be fixed *///MSF_STR_ID_DLG_SAVE_ERROR;
	#endif /*__COSMOS_MMI_PACKAGE__*/
            break;
    }
   
	local_param =
        (wps_pmg_error_dlg_struct*) construct_local_para((kal_uint16) sizeof(wps_pmg_error_dlg_struct), TD_RESET);
	local_param->str_id = string_id;
	pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_ERROR_DLG_IND, (void*)local_param, (void*)0);

    return;

}

/*****************************************************************************
 * FUNCTION
 *  write_to_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job         [IN]        
 *  buf         [IN]        
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int write_to_buffer(pmg_job_t *job, char *buf, unsigned int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned int bytes_to_write, bytes_written;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!buf || size == 0)
    {
        return -1;
    }

    bytes_to_write = (job->buffer_tail + size <= PMG_DL_BUFFER_SIZE) ? size : PMG_DL_BUFFER_SIZE - job->buffer_tail;
    memcpy(job->buffer + job->buffer_tail, buf, bytes_to_write);
    job->buffer_tail = (job->buffer_tail + bytes_to_write) % PMG_DL_BUFFER_SIZE;

    if (job->buffer_tail == 0)
    {
        ret = FS_Write(job->file_handle, job->buffer, PMG_DL_BUFFER_SIZE, (U32*) & bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return ret;
        }
    }

    if (size > bytes_to_write)
    {
        return write_to_buffer(job, buf + bytes_to_write, size - bytes_to_write);
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_process_push_download_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int pmg_process_push_download_result(pmg_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = flush_buffer(job);
    if (ret < 0)
    {
        pmg_delete_job(job);
        return FALSE;
    }
    FS_Close(job->file_handle);
    MSF_PIPE_CLOSE(job->pipe_handle);
    MSF_PIPE_DELETE(job->pipe_name);
    job->status = PMG_STATUS_COMPLETE;
    pmg_send_dl_ind(
        job->mod_id,
        MsfResourceBuffer,
        job->url,
        job->mime_type,
        (const kal_uint8*)job->file_name,
        NULL,
        job->header,
        job->network_account_id,
        job->attr_len,
        job->attr_string);
    pmg_delete_job(job);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  flush_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  job     [IN]
 * RETURNS
 *  
 *****************************************************************************/
static int flush_buffer(pmg_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned int bytes_written;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->buffer_tail > 0)
    {
        ret = FS_Write(job->file_handle, job->buffer, job->buffer_tail, (U32*) & bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return ret;
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_abort_download
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  job         [IN]        
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_abort_download(pmg_job_t *job, int cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->file_handle >= 0)
    {
        flush_buffer(job);
        FS_Close(job->file_handle);
        job->file_handle = -1;
    }    

    if(job->pipe_handle >= 0)
    {
        MSF_PIPE_CLOSE(job->pipe_handle);
        MSF_PIPE_DELETE(job->pipe_name); 
        job->pipe_handle = -1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  pmg_find_job_by_pipe_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pipe_handle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pmg_job_t *pmg_find_job_by_pipe_handle(int pipe_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = pmg_job_queue;

    while (job != NULL)
    {
        if (job->pipe_handle == pipe_handle)
        {
            return job;
        }
        job = job->next;
    }
    return NULL;
}