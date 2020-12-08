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
 * ImgEdtSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service internal data type definitions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "syscomp_config.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"
#include "gdi_include.h"

DECLARE_STATIC_RESERVE_SLOT(srv_ies_job, SRV_IES_JOB_MAX_JOB_COUNT);

static srv_ies_job              *g_srv_ies_curr_job[SRV_IES_JOB_MAX_JOB_COUNT];

typedef struct ies_task_context_struct
{
    kal_eventgrpid              event;                      // Event command state
    srv_ies_list_head_struct    normal;                     // Normal priroity jobs
    srv_ies_list_head_struct    lowest;                     // Lowest priority jobs
    srv_ies_job                 *pJob;
} ies_task_context_struct;

static ies_task_context_struct  g_ies_task_context;

/* Mutex to protect inter-task job operations (e.g. cancel job from MMI task) */
static kal_mutexid              g_srv_ies_job_mutex   = 0;  // Mutex for protecting the job state control
static kal_mutexid              g_srv_ies_hdl_mutex   = 0;  // Mutex for protecting the allocating / free 
static kal_eventgrpid           g_srv_ies_job_event   = 0;  // Event for communicating between IES and MMI task
static S32                      g_srv_ies_job_user    = 0;  // Current user count of the job sub-module
static kal_uint32               g_srv_ies_job_seq_num = 0;  // Sequence number for identify the request
static kal_bool                 g_srv_ies_job_deinit  = KAL_FALSE;
static kal_bool                 g_srv_ies_meta_test[SRV_IES_JOB_MAX_JOB_COUNT] = { KAL_FALSE};

#define WAIT_IES_TASK_EVENT()                                                   \
do                                                                              \
{                                                                               \
    kal_uint32 abort_event = 0;                                                 \
    kal_retrieve_eg_events(g_srv_ies_job_event,                                 \
                           (1 << hJob->jobID),                                  \
                           KAL_OR_CONSUME,                                      \
                           &abort_event,                                        \
                           KAL_SUSPEND);                                        \
} while(0);


#define SET_IES_TASK_EVENT()                                                    \
do                                                                              \
{                                                                               \
    kal_set_eg_events(g_srv_ies_job_event,                                      \
                      (1 << pJob->jobID),                                       \
                      KAL_OR);                                                  \
}while(0);


static MMI_BOOL _srv_ies_job_compare_seq_num(srv_ies_job_id seq1,
                                             srv_ies_job_id seq2)
{
    return (seq1 == seq2)? MMI_TRUE: MMI_FALSE;
}


static kal_uint32 srv_ies_job_request_seq_num()
{
    ++g_srv_ies_job_seq_num;
    if(0 == g_srv_ies_job_seq_num)
    {
        ++g_srv_ies_job_seq_num;
    }
    return g_srv_ies_job_seq_num;
}


srv_ies_job_handle srv_ies_job_create(srv_ies_app_session_handle        hApp,
                                      module_type                       modID,
                                      SRV_IES_JOB_TYPE_ENUM             jobType,
                                      void                              *pOwner,
                                      void                              *pInput,
                                      CTIterator                        *pItr,
                                      void                              *pOutput,
                                      kal_uint32                        maxStep,
                                      srv_ies_async_callback_func_ptr   callback,
                                      void                              *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job *pJob;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_srv_ies_hdl_mutex);
    TYPED_ALLOC(pJob, srv_ies_job);
    g_srv_ies_curr_job[pJob->jobID] = pJob;
    kal_give_mutex(g_srv_ies_hdl_mutex);

    ASSERT(NULL != pJob);

    switch(jobType)
    {
        case SRV_IES_JOB_TYPE_RENDER_PREVIEW:
        case SRV_IES_JOB_TYPE_RENDER_BUFFER:
        case SRV_IES_JOB_TYPE_CREATE_META:
            pJob->pOutput = pOutput;
            break;
        case SRV_IES_JOB_TYPE_RENDER_FILE:
            ASSERT(NULL != pInput);
            mmi_wcsncpy(pJob->filePath, pOutput, SRV_FMGR_PATH_MAX_LEN);
            break;
        default:
            ASSERT(0);
            return NULL;
    }

    LIST_INIT((srv_ies_list_head_struct*)pJob);

    ((srv_ies_job_control*)pOwner)->pCurrJob = pJob;

    pJob->pParent   = hApp;
    pJob->state     = SRV_IES_JOB_STATE_CREATED;
    pJob->modID     = kal_get_active_module_id();
    pJob->jobType   = jobType;
    pJob->seqNum    = srv_ies_job_request_seq_num();
    pJob->pOwner    = pOwner;
    pJob->pItr      = pItr;
    pJob->pInput    = pInput;
    pJob->maxStep   = maxStep;
    pJob->callback  = callback;
    pJob->pData     = pData;

    return pJob;
}


srv_ies_result srv_ies_job_destroy(srv_ies_job_handle hJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job_id jobID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(hJob != NULL);

    jobID = hJob->jobID;

    hJob->seqNum = 0;

    ASSERT(KAL_FALSE == g_srv_ies_meta_test[hJob->jobID]);

    hJob->state = SRV_IES_JOB_STATE_INVALID;

    kal_take_mutex(g_srv_ies_hdl_mutex);
    if (hJob == g_srv_ies_curr_job[jobID])
    {
        g_srv_ies_curr_job[jobID] = NULL;
        TYPED_FREE(hJob, srv_ies_job);
    }
    kal_give_mutex(g_srv_ies_hdl_mutex);

    return SRV_IES_OK;
}


static U8 _srv_ies_job_response_handler(void *pMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_ilm_job_response        *pResp;
    srv_ies_job                     *pJob;
    SRV_IES_JOB_STATE_ENUM          state;
    srv_ies_result                  result;
    srv_ies_async_callback_func_ptr callback;
    void*                           pData;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_JOB_HANDLE_RESPONSE, 1, pMsg);

    pResp = (srv_ies_ilm_job_response*)pMsg;
    ASSERT(NULL != pResp);

    pJob  = pResp->pJob;
    ASSERT(NULL != pJob);

    // MAUI_02734511: The race condition for cancelling the jobs.
    // The sequence number is to identify if the job is cancelled.
    // That's because there may be some latency between IES and MMI.
    if (!_srv_ies_job_compare_seq_num(pResp->seqNum, pJob->seqNum))
    {
        IES_LOG_END(0);
        return 0;
    }

    result      = pResp->result;
    callback    = pJob->callback;
    pData       = pJob->pData;

    kal_take_mutex(g_srv_ies_job_mutex);
    state       = pJob->state;
    kal_give_mutex(g_srv_ies_job_mutex);

    if (SRV_IES_JOB_STATE_FINISHED == state)
    {  
       if (callback)
       {
          callback(result, pData);
       }
    }

    if (MMI_TRUE == _srv_ies_job_compare_seq_num(pResp->seqNum, pJob->seqNum))
    {
       srv_ies_job_destroy(pJob);
    }

    IES_LOG_END(0);
    return 0;
}


srv_ies_result srv_ies_job_get_meta(srv_ies_job_handle  hJob,
                                    srv_ies_meta_handle *pHMeta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL == hJob) || (pHMeta == NULL))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    ASSERT(SRV_IES_JOB_TYPE_CREATE_META == hJob->jobType);

    *pHMeta = hJob->pOutput;

    g_srv_ies_meta_test[hJob->jobID] = KAL_FALSE;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_job_init(srv_ies_app_session_handle hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 taskID;
    kal_int32  index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_srv_ies_hdl_mutex)
    {
        g_srv_ies_hdl_mutex = kal_create_mutex("IESHDLMX");
        ASSERT(0 != g_srv_ies_hdl_mutex);
    }

    kal_take_mutex(g_srv_ies_hdl_mutex);
    if (0 == g_srv_ies_job_user)
    {
        kal_get_my_task_index(&taskID);
        if(INDX_MMI == taskID)
        {
            mmi_frm_set_protocol_event_handler(MSG_ID_IES_JOB_RSP,
                                               &_srv_ies_job_response_handler,
                                               MMI_FALSE);
        }

        memset(g_srv_ies_curr_job, 0x0, sizeof(srv_ies_job*) * SRV_IES_JOB_MAX_JOB_COUNT);
   
        for (index = 0; index < SRV_IES_JOB_MAX_JOB_COUNT; index++)
        {
            g_srv_ies_job_pool[index].jobID = index;
        }
    }

    hApp->appState |= SRV_IES_APP_STATE_JOB_INITED;

    g_srv_ies_job_user++;
    kal_give_mutex(g_srv_ies_hdl_mutex);

    g_srv_ies_job_deinit = KAL_FALSE;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_job_deinit(srv_ies_app_session_handle hApp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job             *pJob;
    kal_int32               index;
    SRV_IES_JOB_STATE_ENUM  state;
    kal_uint32              taskID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hApp->appState &= ~SRV_IES_APP_STATE_JOB_INITED;

    for (index = 0; index < SRV_IES_JOB_MAX_JOB_COUNT; index++)
    {
        kal_take_mutex(g_srv_ies_hdl_mutex);
        pJob = g_srv_ies_curr_job[index];
        kal_give_mutex(g_srv_ies_hdl_mutex);
        if (pJob)
        {
            kal_take_mutex(g_srv_ies_job_mutex);
            state = pJob->state;
            kal_give_mutex(g_srv_ies_job_mutex);

            if ((pJob->pParent == hApp) &&
                (SRV_IES_JOB_STATE_INVALID  != state) &&
                (SRV_IES_JOB_STATE_FINISHED != state))
            {
                srv_ies_job_cancel(pJob);
            }
            else if ((pJob->pParent == hApp) &&
                     (SRV_IES_JOB_STATE_FINISHED == state))
            {
               g_srv_ies_curr_job[index] = NULL;
               pJob->seqNum = 0;
               TYPED_FREE(pJob, srv_ies_job);
            }

            pJob->state = SRV_IES_JOB_STATE_INVALID;
        }
    }

    kal_take_mutex(g_srv_ies_hdl_mutex);

    g_srv_ies_job_user--;
    ASSERT(g_srv_ies_job_user >= 0);

    if (0 == g_srv_ies_job_user)
    {
        kal_get_my_task_index(&taskID);
        if(INDX_MMI == taskID)
        {
            mmi_frm_clear_protocol_event_handler(MSG_ID_IES_JOB_RSP,
                                                 &_srv_ies_job_response_handler);
        }

        g_srv_ies_job_deinit = KAL_TRUE;
    }
    kal_give_mutex(g_srv_ies_hdl_mutex);

    return SRV_IES_OK;
}


kal_bool srv_ies_job_send_request(srv_ies_job_handle hJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_app_session     *pApp;
    srv_ies_ilm_job_request *pReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(hJob != NULL);

    pApp = hJob->pParent;

    if ((KAL_TRUE == g_srv_ies_job_deinit) ||
        ((pApp->appState & SRV_IES_APP_STATE_JOB_INITED) == 0) ||
        (SRV_IES_JOB_STATE_INVALID == hJob->state))
    {
        return MMI_FALSE;
    }

    pReq = (srv_ies_ilm_job_request*)construct_local_para(sizeof(srv_ies_ilm_job_request), TD_CTRL);
    ASSERT(NULL != pReq);

    pReq->type           = SRV_IES_JOB_REQUEST_START;
    pReq->pJob           = hJob;
    pReq->seqNum         = hJob->seqNum;

    return msg_send5(hJob->modID, MOD_IES, MMI_MMI_SAP, MSG_ID_IES_JOB_REQ, (local_para_struct*)pReq);
}


static kal_bool _srv_ies_job_cancel_request(srv_ies_job_handle hJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_ilm_job_request *pReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pReq = (srv_ies_ilm_job_request*)construct_local_para(sizeof(srv_ies_ilm_job_request), TD_CTRL);
    ASSERT(NULL != pReq);

    pReq->type              = SRV_IES_JOB_REQUEST_CANCEL;
    pReq->pJob              = hJob;
    pReq->seqNum            = hJob->seqNum;

    return msg_send5(hJob->modID, MOD_IES, MMI_MMI_SAP, MSG_ID_IES_JOB_REQ, (local_para_struct*)pReq);
}


srv_ies_result srv_ies_job_query_progress(srv_ies_job_handle    hJob,
                                          U32                   *pProg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job     *pJob;
    CRESULT         result;
    CTuint32        count;
    CTuint32        total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((NULL == pProg) || (NULL == hJob))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    kal_take_mutex(g_srv_ies_hdl_mutex);
    pJob = g_srv_ies_curr_job[hJob->jobID];
    kal_give_mutex(g_srv_ies_hdl_mutex);

    total = 0;

    kal_take_mutex(g_srv_ies_job_mutex);
    if ((pJob != hJob) || (NULL == pJob->pItr))
    {
        *pProg = SRV_IES_JOB_PROGRESS_MAX;
    }
    else
    {
        result = caps_getCurIterationCount(pJob->pItr, &count);
        ASSERT(CERR_OK == result);

        result = caps_estimateIterationCount(pJob->pItr, &total);
        ASSERT(CERR_OK == result);
    }
    kal_give_mutex(g_srv_ies_job_mutex);

    if (0 != total)
    {
       *pProg = (count * SRV_IES_JOB_PROGRESS_MAX) / total;
    }
    else
    {
       *pProg = SRV_IES_JOB_PROGRESS_MAX;
    }

    return SRV_IES_OK;
}


srv_ies_result srv_ies_job_cancel(srv_ies_job_handle hJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool cancelled;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_JOB_CANCEL, 1, hJob);    

    kal_trace(MOD_IES, TRACE_GROUP_2, "srv_ies_job_cancel on job %x", hJob);

    cancelled = KAL_FALSE;

    kal_take_mutex(g_srv_ies_hdl_mutex);
    if (hJob != g_srv_ies_curr_job[hJob->jobID])
    {
        g_srv_ies_meta_test[hJob->jobID] = KAL_FALSE;
        cancelled = KAL_TRUE;
    }
    else
    {
        hJob->seqNum = 0;
        g_srv_ies_curr_job[hJob->jobID] = NULL;
    }
    kal_give_mutex(g_srv_ies_hdl_mutex);

    // Send abort request and wait for event
    if (KAL_FALSE == cancelled)
    {
        kal_take_mutex(g_srv_ies_job_mutex);
        hJob->state = SRV_IES_JOB_STATE_CANCELLED;
        kal_give_mutex(g_srv_ies_job_mutex);

        _srv_ies_job_cancel_request(hJob);
        WAIT_IES_TASK_EVENT();

        hJob->state = SRV_IES_JOB_STATE_INVALID;

        kal_take_mutex(g_srv_ies_hdl_mutex);
        TYPED_FREE(hJob, srv_ies_job);
        kal_give_mutex(g_srv_ies_hdl_mutex);
    }

    // We don't care any further results.
    IES_LOG_END(SRV_IES_OK);
    return SRV_IES_OK;
}


static void _ies_task_job_respond(srv_ies_job               *pJob,
                                  kal_uint32                seqNum,
                                  srv_ies_result            result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_ilm_job_response    *pResp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pResp = (srv_ies_ilm_job_response*)construct_local_para(sizeof(srv_ies_ilm_job_response), TD_CTRL);
    ASSERT(NULL != pResp);

    pResp->pJob           = pJob;
    pResp->seqNum         = seqNum;
    pResp->result         = result;

    msg_send5(MOD_IES, pJob->modID, MMI_MMI_SAP, MSG_ID_IES_JOB_RSP, (local_para_struct*)pResp);

}


static MMI_BOOL _ies_task_job_handle_start(srv_ies_job *pJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CRESULT                         result;
    srv_ies_app_session_handle      hApp;
    kal_uint32                      count;
    srv_ies_result                  error;
    srv_ies_job_control             *pOwner;
    CTImage                         *pImage;
    kal_bool                        postDel;
    WCHAR                           file[SRV_FMGR_PATH_MAX_LEN + 1];

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // 0

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "_ies_task_job_handle_start job %x", pJob);

    IES_LOG_BEGIN(SRV_IES_JOB_HANDLE_START, 1, pJob);

    hApp = (srv_ies_app_session_handle)(pJob->pParent);
    ASSERT(NULL != hApp);

    // Reserve memory for foreground task (i.e. MMI task)
    if (hApp->feature == SRV_IES_FEATURE_VIEW)
    {
        count = oslmem_free_space();
    #ifdef __MMI_SRV_IES_META__
        if (SRV_IES_JOB_TYPE_CREATE_META == pJob->jobType)
        {
            if (count <= (7.5 * 1024 * 1024))
            {
                kal_sleep_task(1);

                IES_LOG_END(MMI_FALSE);
                return MMI_FALSE;
            }
        }
    #else
        if (count <= (4.5 * 1024 * 1024))
        {
            kal_sleep_task(1);

            IES_LOG_END(MMI_FALSE);
            return MMI_FALSE;
        }
    #endif  // __MMI_SRV_IES_META__
    }

    result  = CRES_TASK_COMPLETE;
    postDel = KAL_FALSE;

    kal_take_mutex(g_srv_ies_job_mutex);

    ASSERT(SRV_IES_JOB_STATE_FINISHED  != pJob->state);

    if (SRV_IES_JOB_STATE_CANCELLED == pJob->state)
    {
        if (!LIST_EMPTY(((srv_ies_list_head_struct*)pJob)))
        {
            LIST_DEL(((srv_ies_list_head_struct*)pJob));
        }
    }

    while(SRV_IES_JOB_STATE_CANCELLED != pJob->state)
    {       
        pJob->state = SRV_IES_JOB_STATE_RUNNING;

        CAPS_MEM_USAGE();
        
        kal_trace(MOD_IES, TRACE_GROUP_2, "caps_doNextIteration begin for pItr %x uid %d", pJob->pItr, pJob->jobID);
        count = 0;
        do
        {
            result = caps_doNextIteration(pJob->pItr);
            if (++count >= pJob->maxStep)
            {
                break;
            }
        } while(CERR_OK == result);
        kal_trace(MOD_IES, TRACE_GROUP_2, "caps_doNextIteration end for pItr %x uid %d", pJob->pItr, pJob->jobID);

        // CERR_OK means there are more iterations left
        if(CERR_OK == result)
        {
            break;
        }
        else
        { 
            CAPS_MEM_USAGE();
            
            // job finished, see if succeeded
            error = srv_ies_util_error_get_result(result); 

            kal_trace(MOD_IES, TRACE_GROUP_2, "_ies_task_job_handle_start done for job %x with result %x", pJob, error);

            pJob->state = SRV_IES_JOB_STATE_FINISHED;
            caps_destroyIterator(pJob->pItr);
            pJob->pItr = NULL;

            pOwner = (srv_ies_job_control*)pJob->pOwner;
            if (NULL != pOwner)
            {
               pOwner->pCurrJob = NULL;
            }

            switch(pJob->jobType)
            {
                case SRV_IES_JOB_TYPE_RENDER_PREVIEW:
                    if (SRV_IES_OK == error)
                    {
                        result = caps_getSourceRenderResult(((srv_ies_image*)pOwner)->session);
                        if (CFAILED(result))
                        {
                            error = srv_ies_util_error_get_result(result);
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
                    #endif // 0
                    }
                    break;
                case SRV_IES_JOB_TYPE_RENDER_BUFFER:
                    pImage = (CTImage*)(pJob->pOutput);

                    if (SRV_IES_OK == error)
                    {
                        result = caps_getSourceRenderResult(((srv_ies_image*)pOwner)->session);
                        if (CFAILED(result))
                        {
                            error  = srv_ies_util_error_get_result(result);
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
                     #endif // 0

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
                    #endif // 0
                    }

                    pImage->pixels = NULL;
                    caps_destroyImage(pImage);
                    pJob->pOutput = NULL;
                    break;
                case SRV_IES_JOB_TYPE_RENDER_FILE:
                    if (pJob->pInput)
                    {
                        ctstream_destroy((CTStream*)pJob->pInput);
                        pJob->pInput = NULL;
                    }

                    if (SRV_IES_OK != error)
                    {
                        memcpy(file, pJob->filePath, sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1));
                        postDel = KAL_TRUE;
                    }
                    break;
                case SRV_IES_JOB_TYPE_CREATE_META:
                    if (SRV_IES_OK != error)
                    {
                        srv_ies_meta_destroy((srv_ies_meta_handle)(pJob->pOutput));
                        pJob->pOutput = NULL;
                    }
                    else
                    {
                        g_srv_ies_meta_test[pJob->jobID] = KAL_TRUE;
                    }
                    break;
                default:
                    ASSERT(0);
                    IES_LOG_END(MMI_TRUE);
                    return MMI_TRUE;
            }

            if(MOD_NIL != pJob->modID)
            {
                _ies_task_job_respond(pJob, pJob->seqNum, error);
            }
            result = CRES_TASK_COMPLETE;
            break;
        }
    }
    kal_give_mutex(g_srv_ies_job_mutex);

    if (KAL_TRUE == postDel)
    {
       if (srv_fmgr_fs_path_exist(file) >= 0)
       {
          srv_fmgr_fs_delete(file);
       }
    }

    IES_LOG_END(((result == CERR_OK)? MMI_FALSE: MMI_TRUE));
    return (result == CERR_OK)? MMI_FALSE: MMI_TRUE;

}


static void _ies_task_job_handle_cancel(srv_ies_job *pJob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job_control  *pOwner;
    CTImage              *pImage;
    kal_bool             postDel;
    WCHAR                file[SRV_FMGR_PATH_MAX_LEN + 1];

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(MOD_IES, TRACE_GROUP_2, "_ies_task_job_handle_cancel job %x", pJob);

    IES_LOG_BEGIN(SRV_IES_JOB_HANDLE_CANCEL, 1, pJob);

    postDel = KAL_FALSE;

    kal_take_mutex(g_srv_ies_job_mutex);
    while(NULL != pJob->pItr)
    {
        // Abort the iterator
        caps_abortIterator(pJob->pItr);
        caps_destroyIterator(pJob->pItr);
        pJob->pItr = NULL;
    }

    switch(pJob->jobType)
    {
        case SRV_IES_JOB_TYPE_RENDER_PREVIEW:
            break;  
        case SRV_IES_JOB_TYPE_RENDER_BUFFER:
            if (NULL != pJob->pOutput)
            {
                pImage = (CTImage*)(pJob->pOutput);
                pImage->pixels = NULL;
                caps_destroyImage(pImage);
                pJob->pOutput = NULL;
            }
            break;
        case SRV_IES_JOB_TYPE_RENDER_FILE:
            if (pJob->pInput)
            {
                ctstream_destroy((CTStream*)pJob->pInput);
                pJob->pInput = NULL;
            }

            memcpy(file, pJob->filePath, sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1));
            postDel = KAL_TRUE;
            break;
        case SRV_IES_JOB_TYPE_CREATE_META:
            if (NULL != pJob->pOutput)
            {
                srv_ies_meta_destroy((srv_ies_meta_handle)(pJob->pOutput));
                pJob->pOutput = NULL;
            }
            g_srv_ies_meta_test[pJob->jobID] = KAL_FALSE;
            break;
        default:
            ASSERT(0);
            break;
    }

    pOwner = (srv_ies_job_control*)pJob->pOwner;
    if (pOwner)
    {
       pOwner->pCurrJob = NULL;
    }
    kal_give_mutex(g_srv_ies_job_mutex);

    if (KAL_TRUE == postDel)
    {
       if (srv_fmgr_fs_path_exist(file) >= 0)
       {
          srv_fmgr_fs_delete(file);
       }
    }

    // set event to notify client. (this is a blocking action)
    kal_trace(MOD_IES, TRACE_GROUP_2, "_ies_task_job_handle_cancel set event");
    SET_IES_TASK_EVENT();

    IES_LOG_END(0);
}


static void _ies_task_dispatch_message(ilm_struct *pIlm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_ilm_job_request     *pReq;
    srv_ies_job                 *pJob;
    srv_ies_job                 *pLow;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(pIlm->msg_id)
    {
    case MSG_ID_IES_JOB_REQ:
        pReq = (srv_ies_ilm_job_request*)pIlm->local_para_ptr;
        ASSERT(NULL != pReq);

        pJob = pReq->pJob;
        ASSERT(NULL != pJob);

        ASSERT(KAL_FALSE == g_srv_ies_job_deinit);

        if(!_srv_ies_job_compare_seq_num(pReq->seqNum, pJob->seqNum))
        {
            kal_trace(MOD_IES, TRACE_GROUP_2, "_ies_task_dispatch_message got inconsistent sequence number %d, %d", pReq->seqNum, pReq->pJob->seqNum);
            break;
        }

        if (SRV_IES_JOB_REQUEST_CANCEL == pReq->type)
        {          
            if (!LIST_EMPTY(((srv_ies_list_head_struct*)pJob)))
            {
                LIST_DEL(((srv_ies_list_head_struct*)pJob));
            }
            _ies_task_job_handle_cancel(pJob);

            if (pJob == g_ies_task_context.pJob)
            {
                g_ies_task_context.pJob = NULL;
            }
        }
        else
        {
            ASSERT(SRV_IES_JOB_REQUEST_START == pReq->type);

            ASSERT(SRV_IES_JOB_STATE_FINISHED != pJob->state);

            if (g_ies_task_context.pJob)
            {
                if (g_ies_task_context.pJob->jobType > pJob->jobType)
                {
                    pLow = g_ies_task_context.pJob;
                    g_ies_task_context.pJob = pJob;

                    ASSERT(SRV_IES_JOB_STATE_FINISHED != pLow->state);

                    switch(pLow->jobType)
                    {
                        case SRV_IES_JOB_TYPE_RENDER_PREVIEW:
                        case SRV_IES_JOB_TYPE_RENDER_BUFFER:
                        case SRV_IES_JOB_TYPE_RENDER_FILE:
                            LIST_ADD_HEAD(&(g_ies_task_context.normal), (srv_ies_list_head_struct*)pLow);
                            break;
                        case SRV_IES_JOB_TYPE_CREATE_META:
                            LIST_ADD_HEAD(&(g_ies_task_context.lowest), (srv_ies_list_head_struct*)pLow);
                            break;
                        default:
                            ASSERT(0);
                    }
                }
                else
                {
                    pLow = pJob;

                    switch(pLow->jobType)
                    {
                        case SRV_IES_JOB_TYPE_RENDER_PREVIEW:
                        case SRV_IES_JOB_TYPE_RENDER_BUFFER:
                        case SRV_IES_JOB_TYPE_RENDER_FILE:
                            LIST_ADD_TAIL(&(g_ies_task_context.normal), (srv_ies_list_head_struct*)pLow);
                            break;
                        case SRV_IES_JOB_TYPE_CREATE_META:
                            LIST_ADD_TAIL(&(g_ies_task_context.lowest), (srv_ies_list_head_struct*)pLow);
                            break;
                        default:
                            ASSERT(0);
                    }

                }

                kal_take_mutex(g_srv_ies_job_mutex);
                if (SRV_IES_JOB_STATE_CANCELLED != pLow->state)
                {
                    pLow->state = SRV_IES_JOB_STATE_PENDING;
                }
                kal_give_mutex(g_srv_ies_job_mutex);
            }
            else
            {
                ASSERT(SRV_IES_JOB_STATE_FINISHED != pJob->state);
                g_ies_task_context.pJob = pJob;
            }

            if (_ies_task_job_handle_start(g_ies_task_context.pJob))
            {
                g_ies_task_context.pJob = NULL;
            }
        }
        break;
    default:
        break;
    }
}


static _ies_task_job_handle_queue()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_job             *pJob;
    SRV_IES_JOB_STATE_ENUM  state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pJob = NULL;

    if (LIST_EMPTY(&(g_ies_task_context.normal)))
    {
        if (!LIST_EMPTY(&(g_ies_task_context.lowest)))
        {
            pJob = (srv_ies_job*)(g_ies_task_context.lowest.pNext);
            LIST_DEL((srv_ies_list_head_struct*)pJob);
        }
    }
    else
    {
        pJob = (srv_ies_job*)(g_ies_task_context.normal.pNext);
        LIST_DEL(((srv_ies_list_head_struct*)pJob));
    }

    if (pJob)
    {
        kal_take_mutex(g_srv_ies_job_mutex);
        state = pJob->state;
        kal_give_mutex(g_srv_ies_job_mutex);

        ASSERT(SRV_IES_JOB_STATE_FINISHED != pJob->state);

        if (SRV_IES_JOB_STATE_CANCELLED != state)
        {
            g_ies_task_context.pJob = pJob;
            if (_ies_task_job_handle_start(g_ies_task_context.pJob))
            {
                g_ies_task_context.pJob = NULL;
            }
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  ies_task_main
 * DESCRIPTION
 *  image viewer daemon task main function & MSG loop
 * PARAMETERS
 *  *task_entry_ptr    [IN]    task entry structure
 * RETURNS
 *  void
 *****************************************************************************/
static void ies_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 msg_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_set_active_module_id(MOD_IES);

    while(1)
    {
        /* peek and check command */
        msg_count = msg_get_extq_messages();
        while(msg_count > 0)
        {
            msg_receive_extq_for_stack(&current_ilm);
            _ies_task_dispatch_message(&current_ilm);
            destroy_ilm(&current_ilm);

            // consume ext queue eagerly
            msg_count = msg_get_extq_messages();
        }
        
        if(!g_ies_task_context.pJob)
        {
            // At this point, there may be pending jobs.
            _ies_task_job_handle_queue();
            if (!g_ies_task_context.pJob)
            {
                // We still have nothing to do
                if ((LIST_EMPTY(&(g_ies_task_context.normal))) &&
                    (LIST_EMPTY(&(g_ies_task_context.lowest))))
                {
                    msg_receive_extq_for_stack(&current_ilm);
                    _ies_task_dispatch_message(&current_ilm);
                    destroy_ilm(&current_ilm);
                }
            }
        }
        else
        {
            /* after processed all commands,
            perform job iteration if there are active jobs. */
            if(_ies_task_job_handle_start(g_ies_task_context.pJob))
            {
                // job finished
                g_ies_task_context.pJob = NULL;
                _ies_task_job_handle_queue();
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  ies_task_init
 * DESCRIPTION
 *  image viewer daemon task init function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE init OK
 *****************************************************************************/
static kal_bool ies_task_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_set_active_module_id(INDX_IES, MOD_IES);

    g_ies_task_context.pJob    = NULL;

    LIST_INIT(&(g_ies_task_context.normal));
    LIST_INIT(&(g_ies_task_context.lowest));

    g_srv_ies_job_mutex = kal_create_mutex("IESJOBMX");
    g_srv_ies_job_event = kal_create_event_group("ies_evt");
   
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ies_task_reset
 * DESCRIPTION
 *  image viewer daemon task reset function
 * PARAMETERS
 *  *task_indx    [IN]    task index
 * RETURNS
 *  KAL_TRUE    reset OK
 *****************************************************************************/
static kal_bool ies_task_reset( task_indx_type task_indx )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/******************************************************************
 * FUNCTION
 *  ies_create
 * DESCRIPTION
 *  image editing service task creation for KAL task protocol
 * PARAMETERS
 *  *handle    [IN]    task handle
 * RETURNS
 *  KAL_TRUE    create OK
 ******************************************************************/
kal_bool ies_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct ies_handler_info = 
    {
       ies_task_main,    /* task entry function */
       ies_task_init,    /* task initialization function */
       NULL,             /* task configuration function */
       ies_task_reset,   /* task reset handler */
       NULL,             /* task termination handler */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   *handle = (comptask_handler_struct*)&ies_handler_info;
   return KAL_TRUE;
}

#else /* __MMI_SRV_IES__ */

/*****************************************************************************
 * FUNCTION
 *  ies_create
 * DESCRIPTION
 *  avoid build error
 * PARAMETERS
 *  handle      [OUT]    task handle
 * RETURNS
 *  KAL_FALSE    always false
 *****************************************************************************/
kal_bool ies_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}

#endif /* __MMI_SRV_IES__ */
