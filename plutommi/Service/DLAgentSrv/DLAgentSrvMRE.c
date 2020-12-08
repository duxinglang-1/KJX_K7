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
 * DLAgentMRE.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#ifndef DOWNLOAD_AGENT_MRE_C
#define DOWNLOAD_AGENT_MRE_C
#include "MMIDataType.h"
#include "MMI_features.h"

#if defined (__MMI_DOWNLOAD_AGENT__)
#include "DLAgentSrvDef.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentSrvMREProts.h"
#include "mmi_rp_srv_downloadagent_def.h"

#include "MREAppMgrSrvGprot.h"
#include "MRESrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrType.h"

#ifdef MMI_DLA_MRE_SUPPORT

#define DA_MRE_DEFAULT_FOLDER    FMGR_DEFAULT_FOLDER_RECEIVED

#define DA_SHOW_INFO(dst, format, tag_src, value_src) \
    kal_wsprintf((unsigned short*)(dst + mmi_ucs2strlen((S8*)dst)),(format),(tag_src), (value_src))

extern void srv_da_mre_start_download (srv_da_job_struct *job);
extern void srv_da_mre_download_callback (U32 app_id, U32 state, U32 file_size, mmi_app_package_char *app_name);

typedef struct
{
    U16     status;  /* refer srv_da_mre_get_detail_result_enum */
    U32     app_id;
    U32     size;
    U16	    *filename;  /* full pathname */
    U16	    *filepath;  /* full pathname */
    void    *arg;
} srv_da_mre_start_dl_struct;

typedef enum
{
    SRV_DA_MRE_GET_DETAIL_SUCCESS,
    SRV_DA_MRE_GET_DETAIL_NO_DETAIL,
    SRV_DA_MRE_GET_DETAIL_USER_CANCEL,

    SRV_DA_MRE_GET_DETAIL_END_OF_ENUM
} srv_da_mre_get_detail_result_enum;

typedef void (*srv_da_get_mre_dl_detail_callback)(void *data);



typedef struct
{
    srv_da_mre_start_dl_struct         *start_dl;
    srv_da_get_mre_dl_detail_callback  download_callback;
} srv_da_mre_dl_detail_struct;


typedef struct
{
    U16                              unique_id;
    U32                              app_id;

    /* attribute provide by lower layer */
    U32                              size;

    U16	                             *filename;
    U16	                             *filepath;  /* full pathname */
    S32	                             session_id;
    U32                              curr_size;
    U32                              dl_start_tick;
    U32                              dl_latest_tick;
    srv_da_abort_callback_type       abort_callback;
    srv_da_mre_dl_detail_struct      *detail;
} srv_da_mre_dl_job_struct;

srv_da_job_struct   *g_curr_job;

static void srv_da_mre_init_module(void);
static void srv_da_mre_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len);
static const U16* srv_da_mre_get_item_filepath(const srv_da_job_struct* job);
static U32 srv_da_mre_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info);
static U16 srv_da_mre_get_job_id(const srv_da_job_struct* job);
extern void srv_da_mre_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data);
static MMI_BOOL srv_da_mre_free_job(srv_da_job_struct* job);
static void srv_da_mre_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback);
static void srv_da_mre_dispatch_job(const srv_da_job_struct* job);
static void srv_da_mre_assign_filepath(srv_da_job_struct* job, const U16* new_filepath);
static void srv_da_mre_resume_job(srv_da_job_struct* job);
static void srv_da_mre_start_next_download (void);
static MMI_BOOL srv_da_mre_is_any_other_mre_job_in_progress (void);

const srv_da_module_funcptr_table srv_da_mre_module =
{
    srv_da_mre_init_module

    ,srv_da_mre_get_name                        /* Get item name to be displayed */
    ,srv_da_mre_get_item_filepath               /* Get the file path of the job. */
    ,srv_da_mre_get_item_progress               /* Get the percentage of download. check struct srv_da_item_progress_struct */
    ,srv_da_mre_get_job_id                      /* Unique job ID */
    ,srv_da_mre_get_setting                     /* to get the settings of download */
    ,NULL
    ,NULL
    ,NULL
    ,NULL

    ,srv_da_mre_free_job
    ,srv_da_mre_abort_job
    ,srv_da_mre_dispatch_job
    ,srv_da_mre_assign_filepath
#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__)
    ,srv_da_mre_resume_job
#endif
};

/*************************************  START Implementation of Module table functions ***********************************/

static void srv_da_mre_init_module(void)
{
}


static void srv_da_mre_get_name(const srv_da_job_struct *job, U16 *buffer, U32 buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    mmi_wcsncpy(buffer, job_data->filepath, buffer_len - 1);
    srv_da_util_process_filepath_to_be_displayed(buffer);
}

static const U16* srv_da_mre_get_item_filepath(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
    
    return (job_data->filepath);
}


static U32 srv_da_mre_get_item_progress(const srv_da_job_struct* job, srv_da_item_progress_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;
    U32 secs;
    U32 progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

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


static U16 srv_da_mre_get_job_id(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    return job_data->unique_id;
}

U32 srv_da_mre_get_download_size (void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
    if (job_data)
    {
        return job_data->size;
    }
    return -1;
}

void srv_da_mre_decide_default_filename (void* arg, U16 *temp_filename, U16 *ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    start_dl = job_data->detail->start_dl;
    mmi_ucs2cpy ((S8*)temp_filename, (S8*)start_dl->filename);
    mmi_asc_to_ucs2 ((S8*)ext, (S8*)"VXP"); //TODO: Remove hardcoding
}



void srv_da_mre_get_setting(const srv_da_job_struct* job, srv_da_setting_struct *setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct   *job_data;
    srv_da_setting_hdlr         setting_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
    setting_hdlr = srv_da_default_setting;
    setting_hdlr(
        DA_MAKE_UNIQUE_ID(job, srv_da_mre_get_job_id(job)),
        job->mime_type ? job->mime_type->mime_type : 0,
        job->mime_type ? job->mime_type->mime_subtype : 0,
        MMI_DA_WAP_DOWNLOAD,
        job_data->size,
        NULL,
        NULL,
        NULL,
        NULL,
        setting_data
    );
    MMI_ASSERT(srv_da_setting_check(setting_data));
}

static MMI_BOOL srv_da_mre_free_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;
    srv_da_mre_dl_detail_struct *dl_detail;
    srv_da_mre_start_dl_struct  *start_dl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(job->type != SRV_DA_JOB_TYPE_MREDL)
        return MMI_FALSE;
    
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    if(job->state == SRV_DA_JOB_STATE_INIT)
    {
        // TODO: Check whether MRE app need this information or not srv_da_send_wap_file_dl_res(job_data->session_id, WAP_DL_ERROR_CANCELLED, NULL);
    }

    if ((job->state == SRV_DA_JOB_STATE_ABORTED ||
         job->state == SRV_DA_JOB_STATE_PAUSED ||
         job->state == SRV_DA_JOB_STATE_FAILED) &&
         job_data->filepath != NULL && !job->reporting)
    {
        // TODO: need to ask MRE service to cancel srv_da_util_file_delete(job_data->filepath);
    }
    
    dl_detail = job_data->detail;
    if (dl_detail != NULL)
    {
        start_dl = dl_detail->start_dl;
        DA_FREE_BUFFER(start_dl->filename);
        DA_FREE_BUFFER(start_dl->filepath);
        OslMfree (start_dl);
        OslMfree (job_data->detail);
    }
    OslMfree(job_data);
    job->data_ptr = NULL;

    // TODO:  DA_TRACE_ENDFUNC(srv_da_mre_free_job); 
    return MMI_TRUE;
}


static void srv_da_mre_abort_job(srv_da_job_struct* job, S32 prev_state, MMI_BOOL pauseOnly,
                                  srv_da_abort_callback_type end_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_ABORTING);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    job_data->abort_callback = end_callback;

    switch (prev_state)
    {
        case SRV_DA_JOB_STATE_DOWNLOADING:
        case SRV_DA_JOB_STATE_RESUMING:
            if (pauseOnly)
            {
                srv_mre_appmgr_da_download_stop (job_data->app_id);
                job->state = SRV_DA_JOB_STATE_ABORTED;
            }
            else
            {
                srv_mre_appmgr_da_download_cancel(job_data->app_id);
                job->state = SRV_DA_JOB_STATE_ABORTED;
            }
            end_callback(job, 0);
            srv_da_mre_start_next_download();
            break;
            // TODO: Need to handle waiting state here
        case SRV_DA_JOB_STATE_WAITING:
        case SRV_DA_JOB_STATE_PAUSED_WAITING:
            if (pauseOnly)
            {
                job->state = SRV_DA_JOB_STATE_PAUSED_WAITING;
                srv_da_update_job_status(job);
            }
            else
            {
                srv_mre_appmgr_da_download_cancel(job_data->app_id);
                job->state = SRV_DA_JOB_STATE_ABORTED;
            }
            srv_da_mre_start_next_download();
            break;
        default:
            MMI_EXT_ASSERT(MMI_FALSE, job->state, 0, 0);
            break;
    }
}

static void srv_da_mre_dispatch_job(const srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    //job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
    //srv_da_free_job(job);
    /* TODO: need to directly dispatch to app menager */
}

static void srv_da_mre_assign_filepath(srv_da_job_struct* job, const U16* new_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    MMI_ASSERT(job->state == SRV_DA_JOB_STATE_COMPLETED);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    UCS2_STR_MALLOC_COPY(job_data->filepath, new_filepath);
}

static void srv_da_mre_resume_job(srv_da_job_struct* job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error = 0;
    srv_da_mre_dl_job_struct    *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(job->type == SRV_DA_JOB_TYPE_MREDL);
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    if (srv_da_mre_is_any_other_mre_job_in_progress())
    {
        job->state = SRV_DA_JOB_STATE_WAITING;
        srv_da_update_job_status(job);
        return;
    }
    job->state = SRV_DA_JOB_STATE_DOWNLOADING;
    error =  srv_mre_appmgr_da_download_start(job_data->app_id, job_data->filepath, srv_da_mre_download_callback);
}
/*************************************  END Implementation of Module table functions *************************************/
void srv_da_mre_get_app_dir (U16 *folder)
{
    mmi_wcscpy(folder, DA_MRE_DEFAULT_FOLDER);
}



static MMI_BOOL srv_da_mre_match_app_id(const srv_da_job_struct *job, U32 criteria)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_dl_job_struct *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->type == SRV_DA_JOB_TYPE_MREDL)
    {
        job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;
        return (job_data->app_id == criteria);
    }
    return MMI_FALSE;
}



srv_da_job_struct* srv_da_mre_get_job_by_app_id(U32 id)
{
    return srv_da_find_job(srv_da_mre_match_app_id, id);
}



static S32 srv_dla_mre_get_total_num_of_mre_download (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) srv_da_count_job (srv_da_job_match_job_type_func, SRV_DA_JOB_TYPE_MREDL);
}

void srv_da_mre_reset_dl_detail_context (void)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
}

static void srv_da_mre_confirm_start_to_download_callback(void *arg, U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    start_dl = job_data->detail->start_dl;
    if (filepath != NULL)
    {
        UCS2_STR_MALLOC_COPY (start_dl->filepath, filepath);
    }
    else
    {
        ASSERT (0);
    }
    start_dl->status = SRV_DA_MRE_GET_DETAIL_SUCCESS;
    job_data->detail->download_callback ((void*)start_dl);
    //srv_da_mre_reset_dl_detail_context ();
    g_curr_job = NULL;
}


static void srv_da_mre_confirm_cancel_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct  *job = (srv_da_job_struct*)arg;
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;


    start_dl = job_data->detail->start_dl;
    start_dl->status = SRV_DA_MRE_GET_DETAIL_USER_CANCEL;
    job_data->detail->download_callback ((void*)start_dl);
    //srv_da_mre_reset_dl_detail_context ();
    g_curr_job = NULL;
}


void srv_da_mre_get_download_info_callback (U32 app_id, U32 state, U32 file_size, U16 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_job_struct    *job_data = NULL;
    srv_da_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = g_curr_job;
    if (job == NULL)
    {
        return; /* Job have been canceled by User */
    }
    if (job->state == SRV_DA_JOB_STATE_ABORTED)
    {
        return;
    }
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    if (app_id != job_data->detail->start_dl->app_id)
    {
        return;
    }
    start_dl = job_data->detail->start_dl;

    if (state != SRV_MRE_APPMGR_DOWNLOAD_GETINFO_SUCCESS)
    {
        start_dl->status = SRV_DA_MRE_GET_DETAIL_NO_DETAIL;
        job_data->detail->download_callback (start_dl);
        return;
    }
    if (job->state != SRV_DA_JOB_STATE_INIT)
    {
        start_dl->status = SRV_DA_MRE_GET_DETAIL_USER_CANCEL;
        job_data->detail->download_callback (start_dl);
        return;
    }
    start_dl->app_id = app_id;
    start_dl->size = file_size;
    job_data->size = file_size;
    UCS2_STR_MALLOC_COPY (start_dl->filename, file_name);
    srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PLEASE_WAIT);
    srv_da_adp_show_choice_screen(
        MMI_FALSE,
        g_curr_job,
        sizeof (srv_da_job_struct),
        srv_da_mre_confirm_start_to_download_callback,
        srv_da_mre_confirm_cancel_callback,
        srv_da_mre_confirm_cancel_callback, 
        MMI_TRUE);
}

static void srv_da_mre_get_info_cancel_callback(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct *job;
    srv_da_mre_dl_job_struct *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = (srv_da_job_struct*)arg;
    job_data = (srv_da_mre_dl_job_struct*)job->data_ptr;

    if (job->state == SRV_DA_JOB_STATE_ABORTED)
    {
        return;
    }

    if (job->state == SRV_DA_JOB_STATE_INIT)
    {
        job->state = SRV_DA_JOB_STATE_ABORTED;
    }
    srv_mre_appmgr_da_download_cancel_get_app_info();
    if (job = g_curr_job)
    {
        g_curr_job = NULL;
    }
    srv_da_job_cancel(job);
}


void srv_da_mre_get_job_info (U32 app_id, void *arg, srv_da_get_mre_dl_detail_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_mre_dl_job_struct    *job_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)g_curr_job->data_ptr;
    MMI_ASSERT (job_data->detail == NULL);

    job_data->detail = (srv_da_mre_dl_detail_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_mre_dl_detail_struct));
    memset (job_data->detail, 0, sizeof(srv_da_mre_dl_detail_struct));
    job_data->detail->download_callback = callback;

    start_dl = (srv_da_mre_start_dl_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_mre_start_dl_struct));
    memset (start_dl, 0, sizeof(srv_da_mre_start_dl_struct));
    start_dl->app_id = app_id;
    start_dl->arg = arg;

    job_data->detail->start_dl = start_dl;

    srv_da_adp_show_progressing(
        SRV_DA_ACTION_SCR_PLEASE_WAIT,
        SRV_DA_PROCESSING,
        srv_da_job_get_title_icon(g_curr_job),
        SRV_DA_PLEASE_WAIT,
        MMI_TRUE,
        g_curr_job,
        srv_da_mre_get_info_cancel_callback);

    srv_mre_appmgr_da_download_get_app_info(app_id, srv_da_mre_get_download_info_callback);
}


void srv_da_mre_cancel_job (srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_adp_set_active_download_confirm_screen(job, 0);
    job->state = SRV_DA_JOB_STATE_ABORTED;
    srv_da_job_cancel (job);
    srv_da_adp_scr_progressing_close (SRV_DA_ACTION_SCR_PLEASE_WAIT);
}


void srv_da_mre_start_next_download (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_find_job (srv_da_job_match_state_func, SRV_DA_JOB_STATE_WAITING);
    if (job != NULL)
    {
        srv_da_mre_start_download (job);
    }
}

void srv_da_mre_download_callback (U32 app_id, U32 state, U32 file_size, mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error = 0;
    srv_da_job_struct           *job;
    srv_da_mre_dl_job_struct    *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_mre_get_job_by_app_id (app_id);
    if (job == NULL)
    {
        return;
    }
    job_data = job->data_ptr;

    switch (state)
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
#endif /* 0 */
    case SRV_MRE_APPMGR_DOWNLOAD_DOWNLOADING:
        job->state = SRV_DA_JOB_STATE_DOWNLOADING;
        job_data->curr_size = file_size;
        srv_da_update_job_status(job);
        break;
    case SRV_MRE_APPMGR_DOWNLOAD_DONE:
        job->state = SRV_DA_JOB_STATE_COMPLETED;
        if (job_data->size != file_size)
        {
            /* TODO: print error- "downloaded filesize is not equals to start download size" */
        }
        srv_da_update_job_status(job);
        /* TODO: need to dispatch to app_manager by using app_name */

        /* Starting the first waiting MRE download*/
        srv_da_free_job(job);
        srv_da_mre_start_next_download();

        break;
    case SRV_MRE_APPMGR_DOWNLOAD_NETWORK_ERROR:
    case SRV_MRE_APPMGR_DOWNLOAD_IO_ERROR:
    case SRV_MRE_APPMGR_DOWNLOAD_OTHER_ERROR:
        job->state = SRV_DA_JOB_STATE_FAILED;
        srv_da_update_job_status(job); /* TODO: Need to modify this API for failed status also have to add update NCenter part in this */
        srv_da_mre_start_next_download();
        break;
    default:
        break;
    }
}


MMI_BOOL srv_da_mre_is_any_other_mre_job_in_progress (void)
{
    srv_da_job_struct *job = NULL;
    job = srv_da_get_first_job_of_type_in_state (SRV_DA_JOB_STATE_DOWNLOADING, SRV_DA_JOB_TYPE_MREDL);
    return (!(job == NULL));
}


void srv_da_mre_start_download (srv_da_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error = 0;
    srv_da_mre_dl_job_struct    *job_data;
    srv_da_setting_struct       *setting_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = job->data_ptr;
    
    setting_data = srv_da_get_setting_buffer();
    srv_da_mre_get_setting(job, setting_data);
    srv_da_copy_setting(job, setting_data);

    if (srv_da_mre_is_any_other_mre_job_in_progress())
    {
        job->state = SRV_DA_JOB_STATE_WAITING;
    }
    else
    {
        job->state = SRV_DA_JOB_STATE_DOWNLOADING;
        error =  srv_mre_appmgr_da_download_start(job_data->app_id, job_data->filepath, srv_da_mre_download_callback);
    }
    srv_da_job_start(job);
}


void srv_da_mre_start_download_callback (void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_mre_start_dl_struct  *start_dl;
    srv_da_job_struct           *job;
    srv_da_mre_dl_job_struct    *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job_data = (srv_da_mre_dl_job_struct*)g_curr_job->data_ptr;
    start_dl = (srv_da_mre_start_dl_struct*)arg;
    job = (srv_da_job_struct*)start_dl->arg;
    job_data = job->data_ptr;
    switch (start_dl->status)
    {
    case SRV_DA_MRE_GET_DETAIL_SUCCESS:
        {
            if ((start_dl->filepath == NULL) || !(strlen ((S8*)start_dl->filepath)))
            {
                srv_da_mre_cancel_job (job);
            }
            else
            {
                job_data->size = start_dl->size;
                UCS2_STR_MALLOC_COPY (job_data->filename, start_dl->filename);
                UCS2_STR_MALLOC_COPY(job_data->filepath, start_dl->filepath);
                srv_da_mre_start_download (job);
            }
        }
        break;
    case SRV_DA_MRE_GET_DETAIL_NO_DETAIL:
        /* TODO: Need to display error popup */
        srv_da_mre_cancel_job (job);
        break;
    case SRV_DA_MRE_GET_DETAIL_USER_CANCEL:
        /* User canceled download */
        /* TODO: May be we need to tell MRE APP about this */
        srv_da_mre_cancel_job (job);
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_get_download_status
 * DESCRIPTION
 *  To query status of a MRE download in DLAgent
 * PARAMETERS
 *  app_id       : [IN]  applicatiion ID: unique id of every MRE download. provided by MRE APP when download start first time.
 * RETURNS
 *  values in enum srv_da_mre_state_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
S32 srv_da_mre_get_download_status (U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    S32 status = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = srv_da_mre_get_job_by_app_id (app_id);
    if (job == NULL)
    {
        return SRV_DA_MRE_DOWNLOAD_NOT_FOUND;
    }
    switch (job->state)
    {
    case SRV_DA_JOB_STATE_INIT:
        status = SRV_DA_MRE_DOWNLOAD_INITIALIZING;
        break;
    case SRV_DA_JOB_STATE_DOWNLOADING:
        status = SRV_DA_MRE_DOWNLOAD_DOWNLOADING;
        break;
    case SRV_DA_JOB_STATE_ABORTING:
    case SRV_DA_JOB_STATE_ABORTED:
        ASSERT (0);
        break;
    case SRV_DA_JOB_STATE_PAUSED:
	case SRV_DA_JOB_STATE_RESUMING:
    case SRV_DA_JOB_STATE_PAUSED_WAITING:
        status = SRV_DA_MRE_DOWNLOAD_PAUSED;
        break;
    case SRV_DA_JOB_STATE_COMPLETED:
        status = SRV_DA_MRE_DOWNLOAD_COMPLETED;
        break;
    case SRV_DA_JOB_STATE_FAILED:
        status = SRV_DA_MRE_DOWNLOAD_FAILED;
        break;
    case SRV_DA_JOB_STATE_WAITING:
        status = SRV_DA_MRE_DOWNLOAD_WAITING;
        break;
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_start_new_download
 * DESCRIPTION
 *  To start a new MRE download.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be download: unique id of every MRE download.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
S32 srv_da_mre_start_new_download (U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_mre_dl_job_struct    *job_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_mre_get_download_status(app_id) != SRV_DA_MRE_DOWNLOAD_NOT_FOUND)
    {
        /* Can be ASSERT as MRE app need to check this before start download request */
        return SRV_DA_MRE_ERROR_ALREADY_EXISTS;
    }
    if (srv_dla_mre_get_total_num_of_mre_download() >= SRV_DA_MAX_NUM_MRE_DOWNLOAD)
    {
        /* TODO: MAY need to diaply dialogue here before returning error  */
        return SRV_DA_MRE_ERROR_MAX_DOWNLOAD_EXCEEDS;
    }
    
    job = srv_da_job_create_ex(SRV_DA_JOB_TYPE_MREDL, NULL);
    job->state = SRV_DA_JOB_STATE_INIT;



    job_data = (srv_da_mre_dl_job_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_mre_dl_job_struct));
    memset(job_data, 0, sizeof(srv_da_mre_dl_job_struct));

    job->data_ptr = job_data;
    job->type_handler = srv_da_get_default_mime_type_handler();
    job_data->unique_id = srv_da_job_get_new_unique_id();
    job_data->app_id = app_id;
    job_data->session_id = 0;
    job_data->detail = NULL;

    g_curr_job = job;

    srv_da_mre_get_job_info (app_id, job, srv_da_mre_start_download_callback);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_start_bg_download
 * DESCRIPTION
 *  To start a new MRE download in background.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be download: unique id of every MRE download.
 *  filepath     : [IN]  Path to store the downloaded file.
 *  filename     : [IN]  FIlename to finally save application with.
 *  filesize     : [IN]  filesize.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
S32 srv_da_mre_start_bg_download (U32 app_id, U16 *filepath, U16 *filename, U32 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;
    srv_da_mre_dl_job_struct    *job_data;
    const applib_mime_type_struct *mime_type;
    const srv_da_type_handler_struct *type_handler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_da_mre_get_download_status(app_id) != SRV_DA_MRE_DOWNLOAD_NOT_FOUND)
    {
        /* Can be ASSERT as MRE app need to check this before start download request */
        return SRV_DA_MRE_ERROR_ALREADY_EXISTS;
    }
    if (srv_dla_mre_get_total_num_of_mre_download() >= SRV_DA_MAX_NUM_MRE_DOWNLOAD)
    {
        return SRV_DA_MRE_ERROR_MAX_DOWNLOAD_EXCEEDS;
    }

    mime_type = srv_da_util_lookup_mime_type(
    (U8*)("MREDL"),
    srv_da_util_get_extension((U16*)"default.ext"),
    0,
    0);
    type_handler = srv_da_search_mime_type_handler(mime_type);
        
    job = srv_da_job_create_ex(SRV_DA_JOB_TYPE_MREDL, NULL);
    job->state = SRV_DA_JOB_STATE_INIT;
    job->mime_type = mime_type;
    job->type_handler = type_handler;
    job->type = SRV_DA_JOB_TYPE_MREDL;

    job_data = (srv_da_mre_dl_job_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_mre_dl_job_struct));
    memset(job_data, 0, sizeof(srv_da_mre_dl_job_struct));

    job->data_ptr = job_data;
    job_data->unique_id = srv_da_job_get_new_unique_id();
    job_data->app_id = app_id;
    job_data->session_id = 0;

    UCS2_STR_MALLOC_COPY(job_data->filepath, filepath);
    UCS2_STR_MALLOC_COPY(job_data->filename, filename);
    job_data->size = filesize;
    job_data->detail = NULL;

    g_curr_job = job;
    srv_da_mre_start_download (job);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_enter_download_list
 * DESCRIPTION
 *  To open list of all downloading items with provided ID highlighted.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be focused in Download list: unique id of every MRE download.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
S32 srv_da_mre_enter_download_list (U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_job_struct           *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (srv_da_mre_get_download_status(app_id) != SRV_DA_MRE_DOWNLOAD_NOT_FOUND);
    job = srv_da_mre_get_job_by_app_id (app_id);
    srv_da_adp_display_job_list (job, MMI_TRUE);
}





void srv_da_start_mre_test_download(void)
{
    static int app_id = 0;
    app_id++;
    srv_da_mre_start_new_download (app_id);
}

#endif /* MMI_DLA_MRE_SUPPORT */
#endif
#endif /* DOWNLOAD_AGENT_MRE_C */
