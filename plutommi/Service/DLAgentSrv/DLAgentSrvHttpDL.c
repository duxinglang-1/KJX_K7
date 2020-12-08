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
 * DLAgentHttpDL.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * Adaptation interfaces for DLAgent application
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
 
#include "MMI_include.h"

#ifdef __MMI_DOWNLOAD_AGENT__

#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "drm_gprot.h"
#include "DLAgentSrvDef.h"
#include "DLAgentSrvGprot.h"
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT

#include "DLAgentSrvIprot.h"
//#include "DLAgentResDef.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif
#include "DLAgentSrvOMA.h"
#include "DLAgentSrvWPS.h"
#include "DLAgentSrvProt.h"
#include "BrowserSrvGprot.h"
#include "das_struct.h"

//#include "SimDetectionDef.h"            /* SCR_SIM_INSERTION and SCR_SIM_BLOCK */
#include "IdleAppDef.h"                 /* IDLE_SCREEN_ID */
#include "MessagesResourceData.h"       /* IMG_NEW_MESSAGE_NOTIFICATION_MSG */
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileMgrSrvGprot.h"
#include "SettingDefs.h"
#include "UCMGProt.h"
#include "IdleAppProt.h"                /* mmi_idle_is_on_idle_screen */
#include "Cbm_api.h"
#include "wap_ps_struct.h"
#include "wapadp.h"
#include "Conversions.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "ExtDeviceDefs.h"
//#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "USBSrvGProt.h"
#endif 

#include "app_str.h"
#include "app_url.h"
#include "GpioSrvGprot.h"                    /* srv_backlight_turn_on */
#include "App_datetime.h"

/****************************************************************************
 * Define
 ****************************************************************************/


/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/
static void srv_da_http_dl_wps_created_callback(MMI_BOOL success, U32 arg);
static void srv_da_http_dl_wps_http_response_callback(U32 arg, U8 result, U16 status, S8 *header, S8 *content_type, U32 content_len, const wps_http_rsp_struct *rsp);
static void srv_da_http_dl_wps_http_auth_ind_callback(U32 arg);
static void srv_da_http_dl_wps_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause);
static void srv_da_http_dl_wps_session_aborted_callback(U32 arg);
/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
 
static void srv_da_http_dl_init_module(void);
static void srv_da_http_dl_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len);
static MMI_BOOL srv_da_http_dl_free_job(srv_da_job_struct* job);
static const U16* srv_da_http_dl_get_item_filepath(const srv_da_job_struct* job);
static U32 srv_da_http_dl_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info);
static void srv_da_http_dl_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback);
static void srv_da_http_dl_dispatch_job(const srv_da_job_struct* job);
extern U16 srv_da_http_dl_get_job_id(const srv_da_job_struct* job);
static void srv_da_http_dl_get_status_desc(
        const srv_da_job_struct *job,
        U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
        const U32 buffer_len,       /* Max length per buffer(line) */
        const U32 num_of_buffers,   /* Number of buffers(lines) */
        U32 *num_of_filled);        /* Number of buffers(lines) filled */
static void srv_da_http_dl_assign_filepath(srv_da_job_struct* job, const U16* new_filepath);
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
static void srv_da_http_dl_resume_job(srv_da_job_struct* job);
#endif

/* You Tube PGDL Download Support*/
#ifdef PGDL_SUPPORT_YOUTUBE

static void srv_da_yt_dl_init_module(void);
static void srv_da_yt_dl_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len);
static MMI_BOOL srv_da_yt_dl_free_job(srv_da_job_struct* job);
static const U16* srv_da_yt_dl_get_item_filepath(const srv_da_job_struct* job);
static U32 srv_da_yt_dl_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info);
static void srv_da_yt_dl_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback);
static void srv_da_yt_dl_dispatch_job(const srv_da_job_struct* job);
static U16 srv_da_yt_dl_get_job_id(const srv_da_job_struct* job);
static void srv_da_yt_dl_get_status_desc(
        const srv_da_job_struct *job,
        U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
        const U32 buffer_len,       /* Max length per buffer(line) */
        const U32 num_of_buffers,   /* Number of buffers(lines) */
        U32 *num_of_filled);        /* Number of buffers(lines) filled */
static void srv_da_yt_dl_assign_filepath(srv_da_job_struct* job, const U16* new_filepath);
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
static void srv_da_yt_dl_resume_job(srv_da_job_struct* job);
#endif
static void srv_da_yt_dl_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data);
const srv_da_module_funcptr_table srv_da_yt_dl_module =
{
    srv_da_yt_dl_init_module

    ,srv_da_yt_dl_get_name
    ,srv_da_yt_dl_get_item_filepath
    ,srv_da_yt_dl_get_item_progress
    ,srv_da_yt_dl_get_job_id
    ,srv_da_yt_dl_get_setting
    ,NULL /* is_object_desc_available() */
    ,NULL /* get_object_desc() */
    ,srv_da_yt_dl_get_status_desc
    ,NULL /* get_infoURL() */
    
    ,srv_da_yt_dl_free_job
    ,srv_da_yt_dl_abort_job
    ,srv_da_yt_dl_dispatch_job
    ,srv_da_yt_dl_assign_filepath
    
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
    ,srv_da_yt_dl_resume_job
#endif    
};
#endif

static void srv_da_http_created_callback(MMI_BOOL success, U32 arg);
static void srv_da_http_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause);


const srv_da_module_funcptr_table srv_da_http_dl_module =
{
    srv_da_http_dl_init_module

    ,srv_da_http_dl_get_name
    ,srv_da_http_dl_get_item_filepath
    ,srv_da_http_dl_get_item_progress
    ,srv_da_http_dl_get_job_id
    ,srv_da_http_dl_get_setting
    ,NULL /* is_object_desc_available() */
    ,NULL /* get_object_desc() */
    ,srv_da_http_dl_get_status_desc
    ,NULL /* get_infoURL() */
    
    ,srv_da_http_dl_free_job
    ,srv_da_http_dl_abort_job
    ,srv_da_http_dl_dispatch_job
    ,srv_da_http_dl_assign_filepath
    
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
    ,srv_da_http_dl_resume_job
#endif    
};

static void srv_da_http_response_callback(
    U32 arg,
    U8 result,
    U16 status,
    S8 *header,
    S8 *content_type,
    U32 content_len,
    const wps_http_rsp_struct *rsp);
static void srv_da_http_auth_ind_callback(U32 arg);

typedef struct
{
	WCHAR *url;
	S32 utc_time;
}srv_da_yt_cache_struct;

srv_da_yt_cache_struct g_srv_da_yt_cache;

/*****************************************************************************
 * FUNCTION
 *  srv_da_get_current_utc_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  Return the current UTC time.
 *****************************************************************************/
U32 srv_da_get_current_utc_time (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct curr_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&curr_time);
    return (applib_dt_mytime_2_utc_sec(&curr_time, MMI_FALSE));
}

U32 srv_da_get_current_time(void)
{
    kal_uint32 ticks = 0;
    kal_uint32 time = 0;
    kal_get_time(&ticks);
    time = kal_ticks_to_milli_secs(ticks);
    return time;
}
/* You Tube PGDL Download Begin */
#ifdef PGDL_SUPPORT_YOUTUBE
static void srv_da_yt_dl_init_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_srv_da_yt_cache.url = (WCHAR*)OslMalloc(2*(WAP_DL_MAX_URL_LEN +1));
	memset(g_srv_da_yt_cache.url, 0, WAP_DL_MAX_URL_LEN);
	g_srv_da_yt_cache.utc_time = 0;


}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_name
 * DESCRIPTION
 *  Get item name to be displayed
 * PARAMETERS
 *  job         [IN] Job
 *  buffer      [IN] Buffer to be filled in
 *  buffer_len  [IN] Buffer length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_yt_dl_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    mmi_wcsncpy(buffer, job_data->filepath, buffer_len - 1);
    srv_da_util_process_filepath_to_be_displayed(buffer);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_free_job
 * DESCRIPTION
 *  Free download job of HTTP.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_da_yt_dl_free_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
        return MMI_FALSE;
    
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;


    if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
    {
        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;
    }


    MMI_ASSERT(job_data->drm_process_session == NULL);

#ifdef __DRM_SUPPORT_SD_CALLBACK__
    /* It may still wait for rights (infinitely wait) */
    if (job_data->drm_wait_for_rights_session != NULL)
    {
        srv_da_drm_wait_for_rights_cancel(job_data->drm_wait_for_rights_session);
        job_data->drm_wait_for_rights_session = NULL;
    }
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */

    if ((job->state == SRV_DA_JOB_STATE_ABORTED ||
         job->state == SRV_DA_JOB_STATE_PAUSED ||
         job->state == SRV_DA_JOB_STATE_FAILED ||
		 job->state == SRV_DA_JOB_STATE_RESUMING) &&
         job_data->filepath != NULL && !job->reporting)
    {
        srv_da_util_file_delete(job_data->filepath);
    }
    
    DA_FREE_BUFFER(job_data->url_ptr);
    DA_FREE_BUFFER(job_data->mime_type_ptr);
    DA_FREE_BUFFER(job_data->filepath);
    DA_FREE_BUFFER(job_data->header);
    DA_FREE_BUFFER(job_data->etag);

    OslMfree(job_data);
    job->data_ptr = NULL;
    
    DA_TRACE_ENDFUNC(srv_da_http_free_job);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_item_filepath
 * DESCRIPTION
 *  Get the filepath of an HTTP download.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  Filepath; NOTE: DO NOT MODIFY THE CONTENT RETURNED
 *****************************************************************************/
static const U16* srv_da_yt_dl_get_item_filepath(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    
    return (job_data->filepath);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_item_progress
 * DESCRIPTION
 *  Get download progress & status of an HTTP download.
 * PARAMETERS
 *  job         [IN]  Job
 *  info        [OUT] Download status
 * RETURNS
 *  Progress in percent
 *****************************************************************************/
static U32 srv_da_yt_dl_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U32 secs;
    U32 progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    info->fileSize = job_data->size;
    info->currSize = job_data->curr_size;
    info->processing_string_id = 0;
    secs = srv_da_util_ticks_to_milli_seconds(job_data->dl_latest_tick - job_data->dl_start_tick) / 1000;
    if(job_data->size && job_data->curr_size && secs)
    {
        info->secs_remain = (U32)((U64)secs * (U64)(job_data->size - job_data->curr_size) / (U64)job_data->curr_size);
    }
    else
    {
        info->secs_remain = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
    }

    progress = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;

    if(job_data->size > 0)
    {
        progress = (U32)( ((U64)job_data->curr_size * (U64)100) / (U64)(job_data->size) );

        if (progress > 100)
        {
            progress = 100;
        }
    }
    else
    {
        switch(job->state)
        {
            case SRV_DA_JOB_STATE_COMPLETED:
            case SRV_DA_JOB_STATE_PROCESSING:
                progress = 100;
                break;

            default:
                progress = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
                break;
        }
    }

    return progress;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_status_desc
 * DESCRIPTION
 *  Fill the object description of job in string_buffer[]
 * PARAMETERS
 *  job                 [IN]  Job.
 *  string_buffer       [IN]  Array of string buffers
 *  buffer_len          [IN]  Length of each string buffer element (in U16)
 *  num_of_buffers      [IN]  Number of string buffers. That is, this function can only
 *                            fill string_buffer[0..number_of_buffers-1]
 *  num_of_filled       [OUT] Number of filled buffer by this function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_yt_dl_get_status_desc(
        const srv_da_job_struct *job,
        U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
        const U32 buffer_len,       /* Max length per buffer(line) */
        const U32 num_of_buffers,   /* Number of buffers(lines) */
        U32 *num_of_filled)         /* Number of buffers(lines) filled */
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U16 status_desc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    status_desc_id = 0;

    switch (job->state)
    {
        case SRV_DA_JOB_STATE_PROCESSING:
            switch (job_data->drm_status)
            {
#if 0 // sahil to do in app
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
                default:
                    break;
            }

            if (status_desc_id != 0)
            {
                mmi_wcsncpy(string_buffer[0], (U16*)GetString(status_desc_id), buffer_len - 1);
                string_buffer[0][buffer_len - 1] = L'\0';
                *num_of_filled = 1;
            }
            else
            {
                *num_of_filled = 0;
            }
            
            break;
            
        default:
            *num_of_filled = 0;
            break;
    }
    
#else /* __DRM_SUPPORT__ */

    *num_of_filled = 0;

#endif /* __DRM_SUPPORT__ */
}


static void srv_da_yt_dl_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mmi_file_dl_stop_req_struct* msg;
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTING);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    job_data->abort_callback = end_callback;

    switch (prev_state)
    {
        case SRV_DA_JOB_STATE_DOWNLOADING:
		case SRV_DA_JOB_STATE_RESUMING:
		


            if (job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                /* Resuming */
                srv_da_wps_close_session(job_data->session, srv_da_http_dl_wps_session_aborted_callback);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }
            else
            {
                job->state = SRV_DA_JOB_STATE_ABORTED;
                end_callback(job, 0);
            }

            break;

#ifdef __DRM_SUPPORT__

        case SRV_DA_JOB_STATE_PROCESSING:

            if (job_data->drm_process_session != NULL)
            {
                srv_da_drm_process_cancel(job_data->drm_process_session);
                return;
            }

#ifdef __DRM_SUPPORT_SD_CALLBACK__
            if (job_data->drm_wait_for_rights_session != NULL)
            {
                srv_da_drm_wait_for_rights_cancel(job_data->drm_wait_for_rights_session);
                job_data->drm_wait_for_rights_session = NULL;
            }
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */

            job->state = SRV_DA_JOB_STATE_ABORTED;
            job_data->drm_status = SRV_DA_DRM_STATUS_NONE;

            end_callback(job, 0);

            break;
            
#endif /*__DRM_SUPPORT__ */ 


        default:
        
            MMI_EXT_ASSERT(MMI_FALSE, job->state, 0, 0);
            break;
    }
}

static void srv_da_yt_dl_dispatch_job(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    srv_da_dispatch_to_app(
        DA_MAKE_UNIQUE_ID(job, srv_da_get_job_id(job)),
        job->mime_type,
        MMI_DA_WAP_DOWNLOAD,
        job_data->filepath,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job->type_handler);
        
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_job_id
 * DESCRIPTION
 *  Get LOCAL ID of an HTTP download job.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  Local ID
 *****************************************************************************/
static U16 srv_da_yt_dl_get_job_id(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    return job_data->unique_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_assign_filepath
 * DESCRIPTION
 *  Assign a new filepath for the file of the job.
 * PARAMETERS
 *  job             [IN/OUT] Job
 *  new_filepath    [IN]     Filepath
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_yt_dl_assign_filepath(srv_da_job_struct* job, const U16* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    UCS2_STR_MALLOC_COPY(job_data->filepath, new_filepath);
}


#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)

static void srv_da_yt_dl_resume_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U32                         size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_RESUMING);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    /* Before resume, check the file length again */
    size = srv_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;

    if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
    {
        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;
    }

    /* DLS do not support resume, so we use WPS session */
    job_data->session = srv_da_wps_create_session((U32)job,
                              SRV_DA_WPS_SETTING_DEFAULT,
                              srv_da_http_dl_wps_created_callback,
                              srv_da_http_dl_wps_http_response_callback,
                              srv_da_http_dl_wps_http_auth_ind_callback,
                              srv_da_http_dl_wps_dl_progress_callback);
}
#endif

void srv_da_yt_dl_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    srv_da_setting_hdlr         setting_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    setting_hdlr = srv_da_default_setting;
    MMI_ASSERT(job->type_handler);
    //if(job->type_handler->setting_hdlr)
        //setting_hdlr = job->type_handler->setting_hdlr;

    setting_hdlr(
        DA_MAKE_UNIQUE_ID(job, srv_da_yt_dl_get_job_id(job)),
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_WAP_DOWNLOAD,
        job_data->size,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job_data->content_len,
        job_data->content,
        setting_data
    );

    MMI_ASSERT(srv_da_setting_check(setting_data));
}


#endif
/* You Tube PGDL Download End */


static void srv_da_http_dl_init_module(void)
{
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_name
 * DESCRIPTION
 *  Get item name to be displayed
 * PARAMETERS
 *  job         [IN] Job
 *  buffer      [IN] Buffer to be filled in
 *  buffer_len  [IN] Buffer length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_http_dl_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    mmi_wcsncpy(buffer, job_data->filepath, buffer_len - 1);
    srv_da_util_process_filepath_to_be_displayed(buffer);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_item_filepath
 * DESCRIPTION
 *  Get the filepath of an HTTP download.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  Filepath; NOTE: DO NOT MODIFY THE CONTENT RETURNED
 *****************************************************************************/
static const U16* srv_da_http_dl_get_item_filepath(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    
    return (job_data->filepath);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_item_progress
 * DESCRIPTION
 *  Get download progress & status of an HTTP download.
 * PARAMETERS
 *  job         [IN]  Job
 *  info        [OUT] Download status
 * RETURNS
 *  Progress in percent
 *****************************************************************************/
static U32 srv_da_http_dl_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U32 secs;
    U32 progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    info->fileSize = job_data->size;
    info->currSize = job_data->curr_size;
    info->processing_string_id = 0;
    secs = srv_da_util_ticks_to_milli_seconds(job_data->dl_latest_tick - job_data->dl_start_tick) / 1000;
    if(job_data->size && job_data->curr_size && secs)
    {
        info->secs_remain = (U32)((U64)secs * (U64)(job_data->size - job_data->curr_size) / (U64)job_data->curr_size);
    }
    else
    {
        info->secs_remain = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
    }

    progress = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;

    if(job_data->size > 0)
    {
        progress = (U32)( ((U64)job_data->curr_size * (U64)100) / (U64)(job_data->size) );

        if (progress > 100)
        {
            progress = 100;
        }
    }
    else
    {
        switch(job->state)
        {
            case SRV_DA_JOB_STATE_COMPLETED:
            case SRV_DA_JOB_STATE_PROCESSING:
                progress = 100;
                break;

            default:
                progress = MMI_DA_UTIL_ESTIMATED_TIME_UNKNOWN;
                break;
        }
    }

    return progress;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void srv_da_http_dl_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    srv_da_setting_hdlr         setting_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
	if (job_data->setting_hdlr)
		setting_hdlr = job_data->setting_hdlr;
	else
    setting_hdlr = srv_da_default_setting;
    setting_hdlr(
        DA_MAKE_UNIQUE_ID(job, srv_da_http_dl_get_job_id(job)),
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_WAP_DOWNLOAD,
        job_data->size,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job_data->content_len,
        job_data->content,
        setting_data
    );

    MMI_ASSERT(srv_da_setting_check(setting_data));
}

void srv_da_http_dl_get_setting_ext(const srv_da_job_struct* job, srv_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    srv_da_setting_hdlr         setting_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    setting_hdlr = srv_da_default_setting;
    MMI_ASSERT(job->type_handler);
    if(job->type_handler->setting_hdlr)
	{
		DA_TRACE_FUNC1(srv_da_job_start, 81);
		if (job_data->setting_hdlr)
			setting_hdlr = job_data->setting_hdlr;
		else
        setting_hdlr = job->type_handler->setting_hdlr;
	}

    setting_hdlr(
        DA_MAKE_UNIQUE_ID(job, srv_da_get_job_id(job)),
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_WAP_DOWNLOAD,
        job_data->size,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job_data->content_len,
        job_data->content,
        setting_data
    );

    MMI_ASSERT(srv_da_setting_check(setting_data));

	

}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_get_status_desc
 * DESCRIPTION
 *  Fill the object description of job in string_buffer[]
 * PARAMETERS
 *  job                 [IN]  Job.
 *  string_buffer       [IN]  Array of string buffers
 *  buffer_len          [IN]  Length of each string buffer element (in U16)
 *  num_of_buffers      [IN]  Number of string buffers. That is, this function can only
 *                            fill string_buffer[0..number_of_buffers-1]
 *  num_of_filled       [OUT] Number of filled buffer by this function
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_http_dl_get_status_desc(
        const srv_da_job_struct *job,
        U16 *string_buffer[],       /* string_buffer[num_of_buffers] */
        const U32 buffer_len,       /* Max length per buffer(line) */
        const U32 num_of_buffers,   /* Number of buffers(lines) */
        U32 *num_of_filled)         /* Number of buffers(lines) filled */
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U16 status_desc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    status_desc_id = 0;

    switch (job->state)
    {
        case SRV_DA_JOB_STATE_PROCESSING:
            switch (job_data->drm_status)
            {
#if 0 //sahil to do in app
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
                default:
                    break;
            }

            if (status_desc_id != 0)
            {
                mmi_wcsncpy(string_buffer[0], (U16*)GetString(status_desc_id), buffer_len - 1);
                string_buffer[0][buffer_len - 1] = L'\0';
                *num_of_filled = 1;
            }
            else
            {
                *num_of_filled = 0;
            }
            
            break;
            
        default:
            *num_of_filled = 0;
            break;
    }
    
#else /* __DRM_SUPPORT__ */

    *num_of_filled = 0;

#endif /* __DRM_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_free_job
 * DESCRIPTION
 *  Free download job of HTTP.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_da_http_dl_free_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
	//srv_da_download_progress_struct report = {0, };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->type != SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
        return MMI_FALSE;
    
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   if(job->state == SRV_DA_JOB_STATE_INIT && job_data->session != SRV_DA_WPS_INVALID_SESSION)
    {
        srv_da_wps_send_dl_progress_res(job_data->session_handle, job_data->seq_num, (wps_dl_status_enum)job_data->status, NULL,job_data->content_len, (kal_uint8 *)job_data->content);
    }




    if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
    {
        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;
    }

    MMI_ASSERT(job_data->drm_process_session == NULL);

#ifdef __DRM_SUPPORT_SD_CALLBACK__
    /* It may still wait for rights (infinitely wait) */
    if (job_data->drm_wait_for_rights_session != NULL)
    {
        srv_da_drm_wait_for_rights_cancel(job_data->drm_wait_for_rights_session);
        job_data->drm_wait_for_rights_session = NULL;
    }
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */

    if ((job->state == SRV_DA_JOB_STATE_ABORTED ||
         job->state == SRV_DA_JOB_STATE_PAUSED ||
         job->state == SRV_DA_JOB_STATE_FAILED ||
		 job->state == SRV_DA_JOB_STATE_RESUMING) &&
         job_data->filepath != NULL && !job->reporting)
    {
        srv_da_util_file_delete(job_data->filepath);
    }
    
    DA_FREE_BUFFER(job_data->url_ptr);
    DA_FREE_BUFFER(job_data->mime_type_ptr);
    DA_FREE_BUFFER(job_data->filepath);
    //DA_FREE_BUFFER(job_data->content);
    DA_FREE_BUFFER(job_data->header);
    DA_FREE_BUFFER(job_data->etag);

    OslMfree(job_data);
    job->data_ptr = NULL;
    
    DA_TRACE_ENDFUNC(srv_da_http_free_job);
    return MMI_TRUE;
}

static void srv_da_http_dl_wps_session_aborted_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    U32                         size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    /* session closed */
    job_data->session = SRV_DA_WPS_INVALID_SESSION;
 
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTING);
    job->state = SRV_DA_JOB_STATE_ABORTED;
    
    size = srv_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;

    if(job_data->abort_callback)
        job_data->abort_callback(job, 0);
    // After callback, job may be removed, do not use it.
}

static void srv_da_http_dl_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    srv_da_normal_dl_job_struct *job_data;
	srv_da_download_progress_struct report = {0, };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTING);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    job_data->abort_callback = end_callback;

    switch (prev_state)
    {
        case SRV_DA_JOB_STATE_DOWNLOADING:
		case SRV_DA_JOB_STATE_RESUMING:
		


            if (job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                /* Resuming */
                srv_da_wps_close_session(job_data->session, srv_da_http_dl_wps_session_aborted_callback);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }
            else
            {
                job->state = SRV_DA_JOB_STATE_ABORTED;
                end_callback(job, 0);
            }

            break;

#ifdef __DRM_SUPPORT__

        case SRV_DA_JOB_STATE_PROCESSING:

            if (job_data->drm_process_session != NULL)
            {
                srv_da_drm_process_cancel(job_data->drm_process_session);
                return;
            }

#ifdef __DRM_SUPPORT_SD_CALLBACK__
            if (job_data->drm_wait_for_rights_session != NULL)
            {
                srv_da_drm_wait_for_rights_cancel(job_data->drm_wait_for_rights_session);
                job_data->drm_wait_for_rights_session = NULL;
            }
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */

            job->state = SRV_DA_JOB_STATE_ABORTED;
            job_data->drm_status = SRV_DA_DRM_STATUS_NONE;

            end_callback(job, 0);

            break;
            
#endif /*__DRM_SUPPORT__ */ 


        default:
        
            MMI_EXT_ASSERT(MMI_FALSE, job->state, 0, 0);
            break;
    }
	if (job_data->dl_progress_cb)
		{
			report.arg = (U32) job;
			report.status = WPS_DL_STATUS_ABORT;
			report.curr_size = job_data->curr_size;
			report.total_size = job_data->size;
			report.savepath = job_data->filepath;
			report.cause = WPS_ERROR_REQ_ABORT;
			report.user_data = job_data->user_data;
			job_data->dl_progress_cb(&report);
		}
}

static void srv_da_http_dl_dispatch_job(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
	S32 mime_type_enum_value, mime_subtype_enum_value;
	S8* mime_type_ptr = (S8*)OslMalloc(255);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
	if (job_data->dispatch_callback)
	{
		
		if (job_data->mime_type_ptr == NULL && job->mime_type != NULL)
		{
			//job_data->mime_type_ptr = job->mime_type->mime_string;
			memcpy(mime_type_ptr, job->mime_type->mime_string, 256);
		}
		
		mime_type_enum_value = (job->mime_type != NULL ? job->mime_type->mime_type : 0);
		mime_subtype_enum_value = (job->mime_type != NULL ? job->mime_type->mime_subtype : 0);
		job_data->dispatch_callback(DA_MAKE_UNIQUE_ID(job, srv_da_http_dl_get_job_id(job)),
									mime_type_enum_value,
									mime_subtype_enum_value,
									MMI_DA_WAP_DOWNLOAD,
									job_data->filepath,
									job_data->url_ptr,
									(S8*)job_data->mime_type_ptr
									);

	}
    else
    srv_da_dispatch_to_app(
        DA_MAKE_UNIQUE_ID(job, srv_da_http_dl_get_job_id(job)),
        job->mime_type,
        MMI_DA_WAP_DOWNLOAD,
        job_data->filepath,
        job_data->url_ptr,
        job_data->mime_type_ptr,
        job->type_handler);
        
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_assign_filepath
 * DESCRIPTION
 *  Assign a new filepath for the file of the job.
 * PARAMETERS
 *  job             [IN/OUT] Job
 *  new_filepath    [IN]     Filepath
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_http_dl_assign_filepath(srv_da_job_struct* job, const U16* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    UCS2_STR_MALLOC_COPY(job_data->filepath, new_filepath);
}

#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)

static void srv_da_http_dl_wps_created_callback(MMI_BOOL success, U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    S8                          *header;
	srv_da_download_progress_struct report = {0, };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    if (!success)
    {
        srv_da_adp_popup_error_for_job(job,SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DA_ERROR_RESUME_FAIL, MMI_FALSE);
if (job_data->dl_progress_cb)
		{
			report.arg = (U32) job;
			report.status = WPS_DL_STATUS_ABORT;
			report.curr_size = job_data->curr_size;
			report.total_size = job_data->size;
			report.savepath = job_data->filepath;
			report.cause = WPS_ERROR_REQ_ABORT;
			report.user_data = job_data->user_data;
			job_data->dl_progress_cb(&report);
		}

        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;

#ifndef __COSMOS_MMI_PACKAGE__
        srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
#endif
        return;
    }

    header = OslMalloc(128);
   
    if (!srv_da_wps_http_req(
        job_data->session,
        WPS_HTTP_METHOD_GET,
        job_data->url_ptr,
        srv_da_util_gen_http_header_to_resume(header, job_data->etag, job_data->curr_size),
        NULL,
        job_data->filepath,
        WPS_DATA_TYPE_FILE))
    {
        MMI_ASSERT(0);
    }


    OslMfree(header);
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_http_wps_http_response_callback
 * DESCRIPTION
 *  HTTP response handler for manual resumption.
 * PARAMETERS
 *  arg             [IN] (mmi_da_oma_send_report_session_struct*)Session
 *  result          [IN] Result
 *  status          [IN] Status code which server responded
 *  header          [IN] HTTP header
 *  content_type    [IN] Content-Type
 *  content_len     [IN] Content-Length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_http_dl_wps_http_response_callback(
    U32 arg,
    U8 result,
    U16 status,
    S8 *header,
    S8 *content_type,
    U32 content_len,
    const wps_http_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
   
    const applib_mime_type_struct *mime_type;
    
	srv_da_download_progress_struct report = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC3(srv_da_http_wps_http_response_callback, result, status, content_len);
    
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_RESUMING);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    

    if(result != WPS_OK)
    {
        goto error_cleanup;
    }
    else if (status >= 300 || status < 200)
    {
        goto error_cleanup;
    }
    
    /* check content len */
    if (status != 206)
    {
        /* full content */
        if(job_data->size == 0)
           job_data->size = content_len;
        if(content_len != job_data->size)
        {
            DA_TRACE_FUNC1(srv_da_http_wps_http_response_callback, 1);
            goto error_cleanup;
        }
    }
    else
    {
        if (content_len > 0) /* Content-Length is present */
        {
            if (job_data->size == 0)
            {
                job_data->size = job_data->curr_size + content_len;
            }
            else if (content_len + job_data->curr_size == job_data->size)
            {
                /* OK */
            }
            else if (content_len == job_data->size)
            {
                /*
                 * [MAUI_02630704]
                 * Some server may send the total file length for Content-Length
                 * even for 206 Partial Content.
                 */
            }
            else
            {
                DA_TRACE_FUNC1(srv_da_http_wps_http_response_callback, 2);
                goto error_cleanup;
            }
        }
    }
    
    /* check mimetype */
    mime_type = srv_da_util_lookup_mime_type((U8*)content_type, 
                                                  srv_da_util_get_extension((U16*)job_data->filepath), 
                                                  MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
    /* only need to check if file is typed */
    if(job->mime_type && 
        (!mime_type || 
         mime_type->mime_type != job->mime_type->mime_type || 
         mime_type->mime_subtype != job->mime_type->mime_subtype) )
    {
        DA_TRACE_FUNC1(srv_da_http_wps_http_response_callback, 99);
        goto error_cleanup;
    }
    
    /* its all ok now, Download start! */
    job->state = SRV_DA_JOB_STATE_DOWNLOADING;
	if(job->setting_info.filepath_hdlr)
	{
			S32 job_id = DA_MAKE_UNIQUE_ID(job, srv_da_get_job_id(job));
    
			MMI_ASSERT(job->mime_type);

			MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_FILEPATH_HDLR, job_id);
        
			job->setting_info.filepath_hdlr(
				job_id,
				job->mime_type->mime_type,
				job->mime_type->mime_subtype,
				job_data->filepath);
			job->reporting = MMI_TRUE;
	}	

    if(status != 206)   /* full content, so reset size */
        job_data->curr_size = 0;
    
    //srv_da_job_start(job);
    kal_get_time(&job_data->dl_start_tick);
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_handle_wps_http_response_callback ((U32)job, status, MMI_FALSE);
#endif   
    return;
    
error_cleanup:
	job->state = SRV_DA_JOB_STATE_PAUSED;
    srv_da_adp_popup_error_for_job(job,SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DA_ERROR_RESUME_FAIL, MMI_FALSE);
if (job_data->dl_progress_cb)
		{
			report.arg = (U32) job;
			report.status = WPS_DL_STATUS_ABORT;
			report.curr_size = job_data->curr_size;
			report.total_size = job_data->size;
			report.savepath = job_data->filepath;
			report.cause = WPS_ERROR_REQ_ABORT;
			report.user_data = job_data->user_data;
			job_data->dl_progress_cb(&report);
		}

    srv_da_wps_close_session(job_data->session, NULL);
    job_data->session = SRV_DA_WPS_INVALID_SESSION;
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_handle_wps_http_response_callback ((U32)job, status, MMI_TRUE);
#endif
}
                                                  
static void srv_da_http_dl_wps_http_auth_ind_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    

    // Temp solution, remove job
    srv_da_adp_popup_error_for_job(job,SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DA_ERROR_RESUME_FAIL, MMI_TRUE);
  #ifndef __COSMOS_MMI_PACKAGE__
    srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
#endif  
    srv_da_update_job_status(job);
}

static void srv_da_http_dl_wps_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    /* state checking */
    if(job->state == SRV_DA_JOB_STATE_ABORTING ||
        job_data->session == SRV_DA_WPS_INVALID_SESSION)
    {
        return;
    }

    
    if(job->state != SRV_DA_JOB_STATE_DOWNLOADING)
    {
        MMI_ASSERT(0);
        return;
    }

    /* update status */
    job_data->curr_size = curr_size;
    kal_get_time(&job_data->dl_latest_tick);

    switch(status)
    {
        case WPS_DL_STATUS_ABORT:
            job->error_cause = srv_da_wps_map_error_code(cause);
        
            if (cause > 0 && /* Network problem */
                !job->was_stopped_by_upper_layer &&
                job_data->size > 0 &&
                srv_da_is_allowed_to_trigger_connection())
            {
        #ifdef MMI_DA_WLAN_PREFER_SUPPORT
                /*
                 * MAUI_02662312: When auto resume channel does not get unset because this job status is still in 
                 * downloading, pause download and change the total active download count of WPS, it will be dcreased
                 * and now channel will be released if it is only active download.
                 */
                job->state = SRV_DA_JOB_STATE_PAUSED;
                srv_da_update_job_status(job);
                job->state = SRV_DA_JOB_STATE_DOWNLOADING;
        #endif /* MMI_DA_WLAN_PREFER_SUPPORT */   

                if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
                {
                    srv_da_wps_close_session(job_data->session, NULL);
                    job_data->session = SRV_DA_WPS_INVALID_SESSION;
                }

           
            }
        #ifdef MMI_DA_WLAN_PREFER_SUPPORT
            if (!srv_da_is_bearer_switching())
        #endif
            srv_da_adp_popup_wps_aborted(job, cause);

#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
            if(job->setting_info.can_minimize)
            {
                job->state = SRV_DA_JOB_STATE_PAUSED;
            }
            else
#endif /* defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__) */
            {
                job->state = SRV_DA_JOB_STATE_ABORTED;
            }

            if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                srv_da_wps_close_session(job_data->session, NULL);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }

            break;
            
        case WPS_DL_STATUS_COMPLETE:
            job->state = SRV_DA_JOB_STATE_COMPLETED;


			// close session
            if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                srv_da_wps_close_session(job_data->session, NULL);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }

            
#ifdef __DRM_SUPPORT__
            /* parse DRM type first */
            if(srv_da_is_drm_require_processing(job->mime_type))
            {
                //srv_da_http_drm_process(job);
                return;
            }
#endif
            break;
            
        case WPS_DL_STATUS_DOWNLOADING:
            job->state = SRV_DA_JOB_STATE_DOWNLOADING;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    srv_da_update_job_status(job);
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void srv_da_http_dl_resume_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;
    U32                         size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_RESUMING);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

#if 0  // NO need to display progress in this case
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    /* Before resume, check the file length again */
    size = srv_da_util_get_file_size(job_data->filepath);
    if(size)
        job_data->curr_size = size;

    if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
    {
        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;
    }

    /* DLS do not support resume, so we use WPS session */
    job_data->session = srv_da_wps_create_session((U32)job,
                              SRV_DA_WPS_SETTING_DEFAULT,
                              srv_da_http_dl_wps_created_callback,
                              srv_da_http_dl_wps_http_response_callback,
                              srv_da_http_dl_wps_http_auth_ind_callback,
                              srv_da_http_dl_wps_dl_progress_callback);

}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_confirm_cancel_callback
 * DESCRIPTION
 *  Handler for user rejected (selected No) the download.
 * PARAMETERS
 *  arg         [IN] srv_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_confirm_cancel_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_set_active_download_confirm_screen(job, 0);
#endif
    /* cancel, free resource */
    srv_da_job_cancel(job);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_da_http_get_job_id
 * DESCRIPTION
 *  Get LOCAL ID of an HTTP download job.
 * PARAMETERS
 *  job         [IN] Job
 * RETURNS
 *  Local ID
 *****************************************************************************/
U16 srv_da_http_dl_get_job_id(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    return job_data->unique_id;
}

srv_da_acceptance_enum srv_da_yt_filename_done(
    U32 criteria, U16* filepath, MMI_BOOL canback, MMI_BOOL canpopup, void *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    job = (srv_da_job_struct*)criteria;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    
    if(!filepath)
    {
        /* user cancel, free resource */
        srv_da_job_cancel(job);

        srv_da_adp_set_active_select_storage_instance(NULL);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }

    /* assign final path */
    UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);

    /* notify DLS for path */
   // srv_da_send_wap_file_dl_res(job_data->session_id, WAP_DL_ERROR_OK, job_data->filepath);

    /* starting download */
    job->state = SRV_DA_JOB_STATE_DOWNLOADING;
    job_data->curr_size = 0;
    kal_get_time(&job_data->dl_start_tick);

    /* download is starting!, push it into list */
    srv_da_job_start(job);
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
    srv_da_wap_reset_bearer_type();
#endif /* MMI_DA_WLAN_PREFER_SUPPORT */

    srv_da_set_allow_to_trigger_connection(MMI_TRUE);

	
	srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);

    srv_da_adp_set_active_select_storage_instance(NULL);
    return SRV_DA_ACCEPTANCE_ACCEPT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_http_confirm_start_to_download_callback
 * DESCRIPTION
 *  Handler for user accepted (Select Yes) the download.
 * PARAMETERS
 *  arg         [IN] srv_da_job_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_confirm_start_to_download_callback(void *arg, U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    srv_da_setting_struct       *setting_data;
    srv_da_storage_parameter_struct *para;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    if (filepath != NULL)
    {
        /* 
         * Venus UI can provide filepath in one go, do not need to activate storage selection 
         * this filepath should never be invalid or co-exist with another download.
         */
        /* assign final path */
		srv_da_util_file_move(job_data->filepath, filepath, FS_MOVE_KILL);
        UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);
		//job->op->assign_filepath(job, filepath);

        /* notify DLS for path */
        //srv_da_send_wap_file_dl_res(job_data->session_id, WAP_DL_ERROR_OK, job_data->filepath);

		if (job_data->show_confirm)
		{

			srv_da_wps_send_dl_progress_res(job_data->session_handle, job_data->seq_num, (wps_dl_status_enum)job_data->status, job_data->filepath,job_data->content_len, (kal_uint8 *)job_data->content);
        /* starting download */

		}
		else
		{
			setting_data = srv_da_get_setting_buffer();
			srv_da_job_get_setting(job, setting_data);

    /* store setting */
			srv_da_copy_setting(job, setting_data);
		}
        job->state = SRV_DA_JOB_STATE_DOWNLOADING;
        job_data->curr_size = 0;
        kal_get_time(&job_data->dl_start_tick);

        /* download is starting!, push it into list */
        srv_da_job_start(job);
        srv_da_set_allow_to_trigger_connection(MMI_TRUE);
if (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
{
#ifndef MMI_DA_PLUTO_SLIM
        srv_da_adp_show_ncenter (job, SRV_DA_JOB_TYPE_HTTP_DOWNLOAD);
#endif
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    if(job->setting_info.can_minimize)
    {
        /* bring up list screen */
        //srv_da_adp_display_job_list(job, MMI_TRUE);
    }
    else
#endif

    {
        /* directly go to job detail */
        srv_da_adp_display_job_detail(job);
    }        
#endif
}
else
{
		srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
		
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		

        return;
    }
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_set_active_download_confirm_screen(job, 0);
#endif
    /* retrieve setting */
    setting_data = srv_da_get_setting_buffer();
    srv_da_job_get_setting(job, setting_data);

    /* store setting */
    srv_da_copy_setting(job, setting_data);

    /* prepare storage parameter */
    
    para = (srv_da_storage_parameter_struct*)OslMalloc(sizeof(srv_da_storage_parameter_struct));
    
    memset(para, 0, sizeof(srv_da_storage_parameter_struct));
    
    para->drv = setting_data->drv;
    para->storage = setting_data->storage;
    
#ifdef MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD
#ifdef PGDL_SUPPORT_YOUTUBE 
	if (job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)
	{
		para->select_storage = MMI_FALSE;	
        para->storage = SRV_DA_STORAGE_AUTO;
	
	    

	} 
	else
#endif
    para->select_storage = setting_data->storage == SRV_DA_STORAGE_NONE ? MMI_TRUE : MMI_FALSE;
#else
    if (para->storage == SRV_DA_STORAGE_NONE)
    {
        para->storage = SRV_DA_STORAGE_AUTO;
    }
    para->select_storage = MMI_FALSE;
#endif

    mmi_wcscpy(para->folder, setting_data->folder);
	if (job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)
	{
		mmi_wcscat(para->folder, L"youtube\\");
		//mmi_wcscpy(para->fileext, L"yts");
	}

    if (!setting_data->default_filename && setting_data->filename[0])
    {
        srv_da_extract_filepath(setting_data->filename, para->filename, para->fileext);
    }
    else if (job_data->filepath!= NULL && job_data->filepath[0] != L'\0')
    {
        /* Assigned filepath in FILE_DL msg */
        srv_da_extract_filepath(job_data->filepath, para->filename, para->fileext);
    }
    else
    {
        srv_da_extract_filename_from_url(job_data->url_ptr, para->filename, para->fileext);
    }
if (job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
{
    if(job->mime_type != NULL)
    {
        mmi_asc_n_to_wcs(para->fileext, job->mime_type->file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }
}
else
{
	mmi_wcscpy(para->fileext, L"yts");
}
    
#ifdef MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD
#ifdef PGDL_SUPPORT_YOUTUBE 
	if (job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)
	{
		para->select_filename = MMI_FALSE;
	} 
	else
#endif
    para->select_filename = (!setting_data->default_filename && setting_data->filename[0] == 0) ? MMI_TRUE : MMI_FALSE;
#else
    para->select_filename = MMI_FALSE;
#endif


    para->filesize = job_data->size;
    
#ifdef __DRM_SUPPORT__
    /* DRM V1.0 content require twice space */
    if( job->mime_type && 
        (job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
         job->mime_type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) )
    {
        para->filesize *= 2;
    }
#endif

    /* if app control (provide filepath callback), skip file size checking */
    if(job->setting_info.filepath_hdlr)
        para->filesize = 0;

    para->filecheck_func = srv_da_does_job_with_filepath_exist;

    if (!(para->select_storage || para->select_filename)) /* Vikas: need to stop redundant event firing from service */
    {
        if (job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)
		{
#ifndef MMI_DA_PLUTO_SLIM
			srv_da_decide_yt_filepath ((U32) job, para, MMI_DA_WAP_DOWNLOAD, srv_da_yt_filename_done);
#endif
		}
        OslMfree(para);
        return;
    }

    /* confirmed, select storage now. */
    srv_da_adp_display_select_storage ((U32) job, para, MMI_DA_WAP_DOWNLOAD);
    OslMfree(para);

}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
#endif /* MMI_DA_HTTP_DOWLOAD_SUPPORT*/

void srv_da_http_dl_operation(U32 arg, srv_da_download_cause_enum cause)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
    srv_da_job_struct* job = (srv_da_job_struct*)arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
DA_TRACE_FUNC1(srv_da_http_dl_operation, 1);    
if (job && job->data_ptr != NULL)
{
	if (srv_da_get_curr_job_in_setuping_state() != NULL && srv_da_get_curr_job_in_setuping_state() == job)
	{
		DA_TRACE_FUNC1(srv_da_http_dl_operation, 2);  
    
			  srv_da_job_cancel(srv_da_get_curr_job_in_setuping_state());
              srv_da_set_curr_job_in_setuping_state(NULL);
	}
	else
	{
		DA_TRACE_FUNC1(srv_da_http_dl_operation, 3);    

		if (job->state == SRV_DA_JOB_STATE_DOWNLOADING)
			job->state = SRV_DA_JOB_STATE_ABORTED;
		srv_da_free_job_and_remove_screens(job);
	}
			
}
        
    
#endif
}

#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
U16 *srv_da_get_temp_file_path(srv_da_job_struct *arg)
{
	srv_da_storage_parameter_struct *para;
	U16 *filepath = (U16 *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
	srv_da_normal_dl_job_struct *job_data = (srv_da_normal_dl_job_struct *)arg->data_ptr;
	
	para = (srv_da_storage_parameter_struct*)OslMalloc(sizeof(srv_da_storage_parameter_struct));
	memset(para, 0, sizeof(srv_da_storage_parameter_struct));
	memset(filepath, 0, SRV_FMGR_PATH_MAX_LEN+1);
	para->select_storage = MMI_FALSE;
	para->storage = SRV_DA_STORAGE_AUTO;
	para->select_filename = MMI_FALSE;
if (arg->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
{
	para->filesize = 2048;
	srv_da_extract_filename_from_url(job_data->url_ptr, para->filename, para->fileext);
}
else
{
	para->filesize = job_data->size;
}
	para->filecheck_func = srv_da_does_job_with_filepath_exist;
	
	if (arg->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD)
	{
		mmi_wcscpy(para->folder, L"Videos\\Temp\\");
		mmi_wcscpy(para->fileext, L"yts");
		mmi_wcscpy(para->filename, L"data");

	}
	if (arg->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
	srv_da_select_storage_final (para, filepath);
	else
	{
		if (srv_da_select_storage_final_ext (para, filepath) != SRV_DA_SCR_SELECT_STORAGE_CAUSE_NONE)
		{
			srv_srv_da_adp_mem_free(filepath);
			OslMfree(para);
			return NULL;
		}
	}
	OslMfree(para);
	return filepath;
}
#endif
MMI_BOOL srv_da_http_dl_job_match_url_func(const srv_da_job_struct* job, U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(job->type != SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
        return MMI_FALSE;
        
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    if(job_data && strcmp(job_data->url_ptr, (S8*)criteria) == 0)
        return MMI_TRUE;

    return MMI_FALSE;
}

MMI_BOOL srv_da_yt_job_match_url_func(const srv_da_job_struct* job, U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_normal_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
        return MMI_FALSE;
        
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    if(job_data && (strcmp(job_data->url_ptr, (S8*)criteria) == 0))
        return MMI_TRUE;

    return MMI_FALSE;
}

U32 srv_da_start_http_download(srv_da_start_download_struct *arg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT 
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
	CHAR *dest_url;
	//U16 *filepath;
#ifdef PGDL_SUPPORT_YOUTUBE
	applib_url_struct url_info;
	U32 curr_utc_time;
	U32 yesterday_utc_time;
    applib_time_struct  curr_rtc_time;
	applib_time_struct  yesterday_rtc_time;
	applib_time_struct  decrease_time = {0};
#endif
	MMI_BOOL is_yt = MMI_FALSE;
	srv_da_start_download_struct *dl_struct = (srv_da_start_download_struct*)arg ;
	DA_TRACE_FUNC3(srv_da_start_http_download, 1, dl_struct->acc_id, dl_struct->show_confirm);
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	dest_url = (CHAR*)OslMalloc(WAP_DL_MAX_URL_LEN);
	memset(dest_url, 0, sizeof(WAP_DL_MAX_URL_LEN));
    mmi_wcs_to_asc(dest_url, dl_struct->url);


#ifdef PGDL_SUPPORT_YOUTUBE
				/* parse the url to know whether its a yt pgdl url */
				if (!(S32)(applib_parse_url((CHAR*) dest_url, &url_info)))
				{
					CHAR *lower_case_url = (CHAR*)OslMalloc(WAP_DL_MAX_URL_LEN + 1);
					CHAR *is_substr;
					memset(lower_case_url, 0, sizeof(WAP_DL_MAX_URL_LEN + 1));
					strncpy(lower_case_url, url_info.parts[APPLIB_URL_HOST_PART], WAP_DL_MAX_URL_LEN);
					is_substr = (CHAR*)(strstr(app_strtolower((kal_char*)(lower_case_url)), "youtube"));
					OslMfree(lower_case_url);
					if (is_substr)
					{
						/* its a you tube url, need to be handled in different flow*/
						if (mmi_wcscmp(g_srv_da_yt_cache.url, dl_struct->url) == 0)
						{
							job = srv_da_find_job(srv_da_yt_job_match_url_func, (U32)dest_url);
							curr_utc_time = srv_da_get_current_utc_time();
							decrease_time.nDay = 1;
							applib_dt_utc_sec_2_mytime(curr_utc_time, &curr_rtc_time, MMI_FALSE);
							applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &yesterday_rtc_time);
							yesterday_utc_time = applib_dt_mytime_2_utc_sec(&yesterday_rtc_time, MMI_FALSE);
							if (g_srv_da_yt_cache.utc_time != 0 && g_srv_da_yt_cache.utc_time < yesterday_utc_time)
							{
								srv_da_free_job(job);
								job = NULL;
								mmi_wcscpy(g_srv_da_yt_cache.url, dl_struct->url);
								g_srv_da_yt_cache.utc_time = srv_da_get_current_utc_time();
							}

							 if(job)
							 {
								if (job->state == SRV_DA_JOB_STATE_COMPLETED)
								{
									job->reporting = MMI_FALSE;
									srv_da_job_on_play_selected(job);
									OslMfree(dest_url);
									return (U32)job;

								}
								else
								{
								
									//job->state = SRV_DA_JOB_STATE_RESUMING;
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
									const U16*  filepath = NULL;
									FS_HANDLE   filehandle = 0;
									filepath = job->op->get_filepath(job);
									filehandle = FS_Open((U16*)filepath, FS_READ_ONLY);
    
									if(filehandle >= 0)
									{      

										FS_Close(filehandle);
										if ((job->state == SRV_DA_JOB_STATE_PAUSED) || (job->state == SRV_DA_JOB_STATE_FAILED) || (job->state == SRV_DA_JOB_STATE_PAUSED_WAITING))
										{
											if (job->op->resume != NULL)
											{
												job->was_stopped_by_upper_layer = MMI_FALSE;
												job->state = SRV_DA_JOB_STATE_RESUMING;
												job->op->resume(job);
									OslMfree(dest_url);
									return (U32)job;
											}
								}
								
							 }
							 else
							 {
										/* drive has been removed, start download from beginning */
										
									}
									
#endif
								 
							 }
							
						}
						else
						{
								 
							 }
						}
						else
						{
							job = srv_da_search_job(SRV_DA_JOB_TYPE_YT_DOWNLOAD);
							if (job)
							{
								job->state = SRV_DA_JOB_STATE_ABORTED;
								
								// close session
								job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
								if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
								{
									srv_da_wps_close_session(job_data->session, NULL);
									job_data->session = SRV_DA_WPS_INVALID_SESSION;
								}
								
								srv_da_update_job_status(job);
								//srv_da_free_job(job);
							}
							mmi_wcscpy(g_srv_da_yt_cache.url, dl_struct->url);
							g_srv_da_yt_cache.utc_time = srv_da_get_current_utc_time();
						}
						is_yt = MMI_TRUE;		

					}
				}
#endif

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    job = srv_da_find_job(srv_da_http_dl_job_match_url_func, (U32)dest_url);
    if(job)
    {
        //srv_da_send_wap_file_dl_res(msg->session_id, WAP_DL_ERROR_CANCELLED, NULL);
        srv_da_adp_click_job(job);
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
				if(job->setting_info.can_minimize)
				{
					/* bring up list screen */
					srv_da_adp_click_job(job);
				}
				else
#endif	

				{
					/* directly go to job detail */
					srv_da_adp_display_job_detail(job);
				}        
#endif
		OslMfree(dest_url);
        return (U32)job;
    }
#endif

if (!is_yt)
	job = srv_da_job_create(SRV_DA_JOB_TYPE_HTTP_DOWNLOAD, NULL);
else
	job = srv_da_job_create(SRV_DA_JOB_TYPE_YT_DOWNLOAD, NULL);
    if (job == NULL)
    {
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
        srv_da_adp_popup_for_error_code_with_callback (srv_da_get_last_error(), srv_da_http_display_job_list_callback);
#endif
		//if(dl_struct->dl_progress)
			//dl_struct->dl_progress((U32) job, SRV_DA_JOB_STATE_ABORTED, 0, srv_da_get_last_error());
		return (U32) job;
	}
	job_data = (srv_da_normal_dl_job_struct*)OslMalloc(sizeof(srv_da_normal_dl_job_struct));
    memset(job_data, 0, sizeof(srv_da_normal_dl_job_struct));
	job->data_ptr = job_data;
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
    job_data->session = SRV_DA_WPS_INVALID_SESSION;
#endif
	
	//DA_TRACE_FUNC2(srv_da_start_http_download, 2, dest_url);
	
	ANSI_STR_MALLOC_COPY(job_data->url_ptr, dest_url, WAP_DL_MAX_URL_LEN);
	OslMfree(dest_url);
    job_data->content = NULL;
    job_data->content_len = 0;
    job_data->header = NULL;
    job_data->header_len = 0;
    job_data->etag = NULL;
#ifdef __DRM_SUPPORT__
    job_data->drm_method = DRM_METHOD_NONE;
#endif
    job_data->drm_status = SRV_DA_DRM_STATUS_NONE;
    job_data->drm_process_session = NULL;
    job_data->drm_wait_for_rights_session = NULL;
    job_data->time_to_wait_for_rights = -1;
	job_data->unique_id = srv_da_job_get_new_unique_id();
	if (dl_struct->setting_hdlr)
	job_data->setting_hdlr = dl_struct->setting_hdlr;
	if (dl_struct->dispatch_callback)
	job_data->dispatch_callback = dl_struct->dispatch_callback;
	if (dl_struct->dl_progress)
	job_data->dl_progress_cb = dl_struct->dl_progress;
	job_data->acc_id = dl_struct->acc_id;
	//dl_struct->dl_operation = srv_da_http_abort_callback;
	srv_da_set_http_flag((U32) job, MMI_TRUE);
	job_data->show_confirm = dl_struct->show_confirm;
	job_data->size = dl_struct->file_length;
	if (dl_struct->user_data)
		job_data->user_data = dl_struct->user_data;
	if (dl_struct->filepath != NULL)
	{
		
		job_data->filepath = (U16 *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
		memset(job_data->filepath, 0, SRV_FMGR_PATH_MAX_LEN+1);
		memcpy(job_data->filepath, dl_struct->filepath, SRV_FMGR_PATH_MAX_LEN);
	}
	else
	job_data->filepath = srv_da_get_temp_file_path(job);
	if (job_data->filepath == NULL)
	{
		
		srv_da_job_cancel(job);
		
		return 1;
	}
	if (dl_struct->show_confirm)
	job_data->need_sent = MMI_FALSE;
	else
		job_data->need_sent = MMI_TRUE;
	srv_da_adp_show_progressing(
            SRV_DA_ACTION_SCR_PLEASE_WAIT,
            0,
            0,
            STR_GLOBAL_PLEASE_WAIT,
            MMI_FALSE,
            NULL,
            NULL);

	job_data->session = srv_da_wps_create_session_ex((U32)job,
                              SRV_DA_WPS_SETTING_DEFAULT,
							  NULL,
                              srv_da_http_created_callback,
                              srv_da_http_response_callback,
                              srv_da_http_auth_ind_callback,
                              srv_da_http_dl_progress_callback);

	
	return (U32)job;
#else
        return 1;
#endif
        


}

#ifdef MMI_DA_HTTP_DOWNLOAD_SUPPORT
static void srv_da_http_created_callback(MMI_BOOL success, U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
    S8                          *header;
	U8 reply_type;
	srv_da_download_progress_struct report = {0, };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
	DA_TRACE_FUNC2(srv_da_start_http_download, 3, success);
	if (job_data->show_confirm)
		reply_type = WPS_DATA_TYPE_FILE_RECREATE;
	else
		reply_type = WPS_DATA_TYPE_FILE;
    if (!success)
    {
        srv_da_adp_popup_error_for_job(job, SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DA_ERROR_RESUME_FAIL, MMI_FALSE);
		if (job_data->dl_progress_cb)
		{
			report.arg = (U32) job;
			report.status = WPS_DL_STATUS_ABORT;
			report.curr_size = job_data->curr_size;
			report.total_size = job_data->size;
			report.savepath = job_data->filepath;
			report.cause = WPS_ERROR_REQ_ABORT;
			report.user_data = job_data->user_data;
			job_data->dl_progress_cb(&report);
		}

        srv_da_wps_close_session(job_data->session, NULL);
        job_data->session = SRV_DA_WPS_INVALID_SESSION;

        srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
        return;
    }

    header = OslMalloc(128);
   
    if (!srv_da_wps_http_req(
        job_data->session,
        WPS_HTTP_METHOD_GET,
        job_data->url_ptr,
        NULL,
        NULL,
        job_data->filepath,    //need to decide the filepath
        reply_type)
		)
    {
        MMI_ASSERT(0);
    }

    OslMfree(header);
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_oma_http_response_callback
 * DESCRIPTION
 *  HTTP response handler for manual resumption.
 * PARAMETERS
 *  arg             [IN] (mmi_da_oma_send_report_session_struct*)Session
 *  result          [IN] Result
 *  status          [IN] Status code which server responded
 *  header          [IN] HTTP header
 *  content_type    [IN] Content-Type
 *  content_len     [IN] Content-Length
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_http_response_callback(
                U32 arg,
                U8 result,
                U16 status,
                S8 *header,
                S8 *content_type,
                U32 content_len,
                const wps_http_rsp_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct     *job_data;
    
   
    
    const applib_mime_type_struct *mime_type;
	srv_da_download_progress_struct report = {0, };
	srv_da_storage_enum storage;
    U16 drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC3(srv_da_http_wps_http_response_callback, result, status, content_len);
    
  

    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(srv_da_is_job_valid(job));
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_CREATED);
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;
    

    /* check result */
   if(result != WPS_OK)
    {
        goto error_cleanup;
    }
    
    /* check content len */
    if (status == 200)
    {
        /* full content */
		if(job_data->size == 0)
           job_data->size = content_len;
        if(content_len != job_data->size)
        {
            DA_TRACE_FUNC1(srv_da_http_wps_http_response_callback, 1);
            goto error_cleanup;
        }
    }
	else
		goto error_cleanup;

  if (!srv_da_util_decide_drive_to_save_file(
            job_data->filepath,
            content_len, 
            &(drv),
            &(storage)))  

    /* check mimetype */
	{
				
				job->state = SRV_DA_JOB_STATE_ABORTED;

				if (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD)
					{
			
						if (srv_da_get_number_of_available_drives() > 1)
							{
								srv_da_adp_popup(SRV_DA_GLOBAL_NOT_ENOUGH_MEMORY, 0,  SRV_DA_POPUP_TYPE_ERROR);
						
							}
						else
							{
								srv_da_adp_popup(SRV_DA_INSERT_MEM_CARD, 0, SRV_DA_POPUP_TYPE_ERROR);
				                    
							}
					}
			if (job_data->dl_progress_cb)
			{
				report.arg = (U32) job;
				report.status = WPS_DL_STATUS_ABORT;
				report.curr_size = job_data->curr_size;
				report.total_size = job_data->size;
				report.savepath = job_data->filepath;
				report.cause = WPS_ERROR_REQ_ABORT;
				report.user_data = job_data->user_data;
				job_data->dl_progress_cb(&report);
			}
	#ifdef __MMI_DA_RESUME__
		srv_da_wps_close_session(job_data->session, NULL);
		job_data->session = SRV_DA_WPS_INVALID_SESSION;
	#endif
		srv_da_job_cancel(job);
		srv_da_adp_scr_progressing_close(0);
		return;
		}

    mime_type = srv_da_util_lookup_mime_type((U8*)content_type, 
                                                  srv_da_util_get_extension((U16*)job_data->filepath), 
                                                  MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
    /* only need to check if file is typed */

	job->mime_type = (const applib_mime_type_struct *) mime_type;
	//job->mime_type->mime_subtype = mime_type->mime_subtype;
DA_TRACE1(MMI_DA_TRC_MIMETYPE, (S32)(mime_type != NULL ? mime_type->mime_subtype : 0));
	job->type_handler = srv_da_search_mime_type_handler(mime_type);
DA_TRACE1(MMI_DA_TRC_MIMETYPE, (S32)(job->type_handler != NULL ? job->type_handler->setting_hdlr : 0));
   
    /* its all ok now, Download start! */
    job->state = SRV_DA_JOB_STATE_INIT;

    if(status != 206)   /* full content, so reset size */
        job_data->curr_size = 0;
	 //srv_da_adp_close_app();
#ifndef MMI_DA_PLUTO_SLIM
	if (job_data->show_confirm)
         srv_da_adp_show_choice_screen(
            MMI_FALSE,
            job,
            sizeof (srv_da_job_struct),
            srv_da_confirm_start_to_download_callback,
            srv_da_confirm_cancel_callback,
            srv_da_confirm_cancel_callback, 
            MMI_TRUE);
	else
#endif
	{
		//if (job->type != SRV_DA_JOB_TYPE_YT_DOWNLOAD)
		srv_da_confirm_start_to_download_callback(job, job_data->filepath);
		//else
			//srv_da_confirm_start_to_download_callback(job, NULL);
	}
	 srv_da_adp_scr_progressing_close(0);
    return;
    
error_cleanup:
	job->state = SRV_DA_JOB_STATE_ABORTED;
//sahil: todo error fail type
    srv_da_adp_popup_error_for_job(job, SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DLA_FAILED_TO_DOWNLOAD, MMI_FALSE);
if (job_data->dl_progress_cb)
		{
			report.arg = (U32) job;
			report.status = WPS_DL_STATUS_ABORT;
			report.curr_size = job_data->curr_size;
			report.total_size = job_data->size;
			report.savepath = job_data->filepath;
			report.cause = WPS_ERROR_REQ_ABORT;
			report.user_data = job_data->user_data;
			job_data->dl_progress_cb(&report);
		}

    srv_da_wps_close_session(job_data->session, NULL);
    job_data->session = SRV_DA_WPS_INVALID_SESSION;
#ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_handle_wps_http_response_callback ((U32)job, status, MMI_TRUE);
#endif
	srv_da_job_cancel(job);
}

static void srv_da_http_auth_ind_callback(U32 arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD);
    

    // Temp solution, remove job
    srv_da_adp_popup_error_for_job(job, SRV_DA_POPUP_TYPE_ERROR, 0, SRV_DA_ERROR_RESUME_FAIL, MMI_TRUE);
#ifndef __COSMOS_MMI_PACKAGE__    
    srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
#endif
    srv_da_update_job_status(job);
}

static void srv_da_http_dl_progress_callback(U32 arg, U8 status, U32 curr_size, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_normal_dl_job_struct *job_data;
	srv_da_download_progress_struct report = {0, };
	//U16 t_drive;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    MMI_ASSERT(job && (job->type == SRV_DA_JOB_TYPE_HTTP_DOWNLOAD || job->type == SRV_DA_JOB_TYPE_YT_DOWNLOAD));
    job_data = (srv_da_normal_dl_job_struct*)job->data_ptr;

    /* state checking */
    if(job->state == SRV_DA_JOB_STATE_ABORTING ||
        job_data->session == SRV_DA_WPS_INVALID_SESSION)
    {
        return;
    }

	MMI_ASSERT(job->state != SRV_DA_JOB_STATE_INIT || job->state != SRV_DA_JOB_STATE_DOWNLOADING);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* update status */
    job_data->curr_size = curr_size;
    kal_get_time(&job_data->dl_latest_tick);
    switch(status)
    {
        case WPS_DL_STATUS_ABORT:
            job->error_cause = srv_da_wps_map_error_code(cause);
        
            if (cause > 0 && /* Network problem */
                !job->was_stopped_by_upper_layer &&
                job_data->size > 0 &&
                srv_da_is_allowed_to_trigger_connection())
            {
							

        #ifdef MMI_DA_WLAN_PREFER_SUPPORT
                /*
                 * MAUI_02662312: When auto resume channel does not get unset because this job status is still in 
                 * downloading, pause download and change the total active download count of WPS, it will be dcreased
                 * and now channel will be released if it is only active download.
                 */
                job->state = SRV_DA_JOB_STATE_PAUSED;
                srv_da_update_job_status(job);
                job->state = SRV_DA_JOB_STATE_DOWNLOADING;
        #endif /* MMI_DA_WLAN_PREFER_SUPPORT */ 

                if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
                {
                    srv_da_wps_close_session(job_data->session, NULL);
                    job_data->session = SRV_DA_WPS_INVALID_SESSION;
                }


            }
        #ifdef MMI_DA_WLAN_PREFER_SUPPORT
            if (!srv_da_is_bearer_switching())
        #endif
			{ 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            srv_da_adp_popup_wps_aborted(job, cause);
			}

#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
            if(job->setting_info.can_minimize)
            {
                job->state = SRV_DA_JOB_STATE_PAUSED;
            }
            else
#endif /* defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__) */
            {
                job->state = SRV_DA_JOB_STATE_ABORTED;
            }

            if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                srv_da_wps_close_session(job_data->session, NULL);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }

            break;
            
        case WPS_DL_STATUS_COMPLETE:
            job->state = SRV_DA_JOB_STATE_COMPLETED;

            // close session
            if(job_data->session != SRV_DA_WPS_INVALID_SESSION)
            {
                srv_da_wps_close_session(job_data->session, NULL);
                job_data->session = SRV_DA_WPS_INVALID_SESSION;
            }
            
#ifdef __DRM_SUPPORT__
            /* parse DRM type first */
            if(srv_da_is_drm_require_processing(job->mime_type))
            {
                //srv_da_http_drm_process(job);  //to do 
                return;
            }
#endif
            break;
            
        case WPS_DL_STATUS_DOWNLOADING:
             if (job->state !=SRV_DA_JOB_STATE_INIT)
            {
            job->state = SRV_DA_JOB_STATE_DOWNLOADING;
             }
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
srv_da_update_job_status(job);
if (job->state !=SRV_DA_JOB_STATE_INIT)
{
    if (job_data->dl_progress_cb)
	{
		report.arg = (U32) job;
		report.status = status;
		report.curr_size = curr_size;
		report.total_size = job_data->size;
		report.savepath = job_data->filepath;
		report.cause = cause;
		report.user_data = job_data->user_data;
		job_data->dl_progress_cb(&report);
	}
   
}

}
#endif
#endif /* __MMI_DOWNLOAD_AGENT__ */
#endif
