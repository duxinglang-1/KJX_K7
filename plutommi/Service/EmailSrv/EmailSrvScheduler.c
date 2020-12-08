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
 *  EmailSrvScheduler.c
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_srv_email_def.h"

#define EMAIL_SCHDL_REQ_BASE           (1)

const static U32 EMAIL_SCHEL_INTERVAL  = 0;

/* job scheduler request structure */
typedef struct _srv_email_schdl_req_sturct
{
    EMAIL_REQ_ID req_id;                        /* request id */
    MMI_BOOL abort;                             /* whether aborted */
    void *user_data;                            /* user data */
    srv_email_schdl_funcptr_type callback;      /* call back */
    struct _srv_email_schdl_req_sturct *next;   /* pointer point to next */
    const CHAR* call_file;
    const CHAR* func_name;
    U32 call_line;
} srv_email_schdl_req_sturct;

typedef struct
{
    srv_email_schdl_req_sturct *req_header; /* job scheduler contenxt */
} srv_email_schdl_cntx_struct;

srv_email_schdl_cntx_struct schdl_cnxt;
srv_email_schdl_cntx_struct *schdl_cnxt_p = &schdl_cnxt;

static void srv_email_schdl_run_job(void);


/*****************************************************************************
 * FUNCTION
 *  srv_email_schdl_start_job
 * DESCRIPTION
 *  Start a job
 * PARAMETERS
 *  callback        [IN]        Call back
 *  user_data       [IN]        User data
 * RETURNS
 *  Request id
 *****************************************************************************/
EMAIL_REQ_ID srv_email_schdl_start_job_ext(
    srv_email_schdl_funcptr_type callback, void *user_data,
    const CHAR* filename, const CHAR* function, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_schdl_req_sturct *req = schdl_cnxt_p->req_header;
    srv_email_schdl_req_sturct *req_new;
    EMAIL_REQ_ID req_id;
    MMI_BOOL run_schdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((req_new = srv_email_mem_alloc(sizeof(srv_email_schdl_req_sturct))) == NULL)
    {
        return 0;
    }

    if (req == NULL)
    {
        run_schdl = MMI_TRUE;
        req_id = EMAIL_SCHDL_REQ_BASE;
        schdl_cnxt_p->req_header = req_new;
    }
    else
    {
        run_schdl = MMI_FALSE;
        while (req->next != NULL)
        {
            req = req->next;
        }
        req_id = req->req_id + 1;
        req->next = req_new;
    }

    req = req_new;
    req->next = NULL;
    req->abort = MMI_FALSE;
    req->req_id = req_id;
    req->callback = callback;
    req->user_data = user_data;
    req->call_file = filename;
    req->func_name = function;
    req->call_line = line;

    if (run_schdl)
    {
        StartTimer(EMAIL_SRV_JOB_SCHEDULER, EMAIL_SCHEL_INTERVAL, srv_email_schdl_run_job);
    }
    return req_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_schdl_stop_job
 * DESCRIPTION
 *  Stop a job
 * PARAMETERS
 *  req_id      [IN]        Requst id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_schdl_stop_job(EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_schdl_req_sturct *req_pre = schdl_cnxt_p->req_header;
    srv_email_schdl_req_sturct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_pre == NULL)
    {
        return;
    }

    if (req_pre->req_id == req_id)
    {
        schdl_cnxt_p->req_header = schdl_cnxt_p->req_header->next;
        srv_email_mem_free(req_pre);
        return;
    }

    req = req_pre->next;
    while (req != NULL)
    {
        if (req->req_id == req_id)
        {
            req_pre->next = req->next;
            srv_email_mem_free(req);
            return;
        }
        req_pre = req_pre->next;
        req = req_pre->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_schdl_run_job
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_schdl_run_job(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_schdl_req_sturct *req = schdl_cnxt_p->req_header;
    //kal_uint32 start_ticks = 0, end_ticks = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req == NULL)
    {
        return;
    }

#ifdef __MAUI_SOFTWARE_LA__
    //SLA_CustomLogging("EM9", SA_start);
#endif
    //kal_prompt_trace(MOD_MMI, "[EmailSrvScheduler] --> ");
    //kal_get_time(&start_ticks);
    (req->callback)(req->user_data);
    //kal_get_time(&end_ticks);
    //kal_prompt_trace(MOD_MMI, "[EmailSrvScheduler] <-- ticks:%d, FUNC:%s, FILE:%s, LINE:%d",
    //    end_ticks - start_ticks, req->func_name, req->call_file, req->call_line);
#ifdef __MAUI_SOFTWARE_LA__
    //SLA_CustomLogging("EM9", SA_stop);
#endif

    schdl_cnxt_p->req_header = req->next;

    srv_email_mem_free(req);

    if (schdl_cnxt_p->req_header != NULL)
    {
        StartTimer(EMAIL_SRV_JOB_SCHEDULER, EMAIL_SCHEL_INTERVAL, srv_email_schdl_run_job);
    }
}

