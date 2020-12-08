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
 * BppSrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BPP service implementation.
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
#ifdef __MMI_BPP_SUPPORT__
#include "bluetooth_struct.h"
#include "BppSrvGprot.h"
#include "BppSrv.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "BtcmSrvGprot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "stdio.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mmi_frm_events_gprot.h"
#include "fs_errcode.h"
/* auto add by kw_check end */
static bpp_srv_cntx_struct g_bpp_srv_cntx;
static bpp_srv_cntx_struct *bpp_cntx = &g_bpp_srv_cntx;

#define g_init_done     (bpp_cntx->init_done)
#define g_insts         (bpp_cntx->insts)
#define g_inst_list     (&bpp_cntx->inst_list)
#define g_job_list      (&bpp_cntx->job_list)
#define g_config        (bpp_cntx->config)
#define g_job_sum       (bpp_cntx->job_sum)
#define g_id_seed       (bpp_cntx->id_seed)

#define MakeHandle(inst) \
            (((U32)inst >> 8) | ((U32)((U32)inst & 0xFF) << 24))
#define MakeParam(hi, low) \
            (((U32)(hi)<< 16) & 0xFFFF0000) | ((low) & 0xFFFF)
#define SameAddr(addr1, addr2) \
            ((addr1)->lap == (addr2)->lap && \
             (addr1)->nap == (addr2)->nap && \
             (addr1)->uap == (addr2)->uap)
#define ValidAddr(addr) \
            ((addr)->lap != 0 || (addr)->nap != 0 || (addr)->uap != 0)
#define DefragCriterion(job_count, del_count) \
            (del_count && (del_count * 100 / (job_count + del_count)) > 60)


static const CHAR GuardPattern[] = {'\x1B', '\x25', '\x2D', '1', '0', '0', '0', '5'};
#define DefJobFile  L"bpp_jobs.dat"
static const bpp_srv_config_struct DefaultConfig = {'Z', MAX_JOBS, DefJobFile};
static const U8 DefaultUpdateAttrs[BPP_ATTR_MAX_ATTRIBUTE] = {
    0,  /* PRINTER NAME */
    0,  /* PRINTER LOCATION */
    1,  /* PRINTER STATE */
    1,  /* PRINTER STATEREASONS */
    0,  /* PRINTER GENERAL CURRENT OPERATOR */
    1,  /* DOCUMENT FORMATS SUPPORTED */
    1,  /* IMAGE FORMATS SUPPORTED */
    0,  /* COLOR SUPPORTED */
    1,  /* MAX COPIES SUPPORTED */
    1,  /* SIDES SUPPORTED */
    1,  /* NUMBERUP SUPPORTED */
    1,  /* ORIENTATIONS SUPPORTED */
    1,  /* MEDIA SIZES SUPPORTED */
    1,  /* MEDIA TYPES SUPPORTED */
    0,  /* MEDIA LOADED */
    1,  /* PRINT QUALITY SUPPORTED */
    0,  /* QUEUED JOB COUNT */
};

static const PrinterAttribute DefaultPrinterAttrs = {
    BPP_SIZE_A4 | BPP_SIZE_4X6 | BPP_SIZE_LETTER,
    BPP_MEDIA_STATIONERY,
    0,
    0,
    10,
    BPP_DOC_XHTML_100,
    BPP_IMAGE_JPEG,
    0x01 | 0x02 | 0x04,
    BPP_QUALITY_DRAFT | BPP_QUALITY_NORMAL | BPP_QUALITY_HIGH,
    BPP_SIDED_ONE | BPP_SIDED_TWO_LONG | BPP_SIDED_TWO_SHORT,
    BPP_PORTRAIT | BPP_LANDSCAPE
};

static const PrintOption DefaultPrintOptions = {
    BPP_SIZE_A4,            /* Media size */
    BPP_MEDIA_STATIONERY,   /* Media type */
    BPP_QUALITY_DRAFT,      /* Quality */
    BPP_SIDED_ONE,          /* Sides support */
    BPP_PORTRAIT,           /* Orientation */
    1,                      /* Numberup */
    1                       /* Copies */
};

static S32 (* const BppStateHdlr[STATE_END])(
                U32 in,
                bpp_srv_job_struct *job,
                void *para) =
{
    bpp_state_close_ed,
    bpp_state_open,
    bpp_state_open_ed,
    bpp_state_close,
    bpp_state_disc,
    bpp_state_wait_start,
    bpp_state_wait_data,
    bpp_state_wait_auth,
};


void srv_bpp_init(BppSrvConfig *config)
{
    srv_bt_cm_profile_struct prof_struct;
    
    prof_struct.profile_id = SRV_BT_CM_OBEX_BPPS_PROFILE_UUID;
    prof_struct.activater = NULL;
    prof_struct.deactivater = NULL;
    prof_struct.disconnector = bpp_disconnect;
    srv_bt_cm_profile_register(&prof_struct);

    if (g_init_done)
        return;

    if (config)
    {
        g_config.storage = (config->storage) ? config->storage:DefaultConfig.storage;
        g_config.maxJobs = (config->maxJobs) ? config->maxJobs:DefaultConfig.maxJobs;
        g_config.jobFile = (config->jobFile) ? config->jobFile:DefaultConfig.jobFile;
    }
    else
        g_config = DefaultConfig;

    ListInit(g_job_list);
    ListInit(g_inst_list);

    g_id_seed = g_config.maxJobs + 256;

    bpp_create_storage();

    bpp_init_job_sum();
    
    bpp_init_msg_hdlr();

    g_init_done = MMI_TRUE;
}

void srv_bpp_deinit(void)
{
    g_init_done = MMI_FALSE;
}

BppHandle srv_bpp_open(S32 mode)
{
    bpp_srv_inst_struct *inst = bpp_new(mode);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_OPEN, mode, inst);
    if (inst == NULL) 
        return 0;

    return inst->handle;
}

void srv_bpp_close(BppHandle srv)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_CLOSE, srv, inst);

    if (inst == NULL)
        return;

    inst->notify = NULL;

    if (!ListEmpty(&inst->job_list))
    {
        bpp_list_struct *m, *n;
        ForEachOfListEx(&inst->job_list, m, n)
        {
            bpp_srv_job_struct *job = ListEntry(m, bpp_srv_job_struct, inst_entry);

            bpp_destroy_job(job);
        }
    }
    
    if (ListEmpty(&inst->job_list))
        bpp_delete(inst);
    else
        inst->flags |= FLAG_CLOSE;
}

S32 srv_bpp_set_notify(BppHandle srv, BppSrvNotify notify, U32 mask, U8 op)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);

    if (inst == NULL)
        return RESULT_FAIL;

    switch (op) {
    case EV_OP_NEW:
        inst->event_mask = mask;
        inst->notify = notify;
        break;

    case EV_OP_ADD:
        inst->event_mask |= mask;
        break;

    case EV_OP_DEL:
        inst->event_mask &= ~mask;
        break;    
    }

    return RESULT_SUCC;
}

S32 srv_bpp_change_mode(BppHandle srv, U32 mode)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);

    if (!inst)
        return RESULT_FAIL;
    
    if (inst->mode == mode)
        return RESULT_SUCC;

    if (mode == MODE_RDWRITE) 
    {
        bpp_list_struct *m;
        
        /* Only one Read-Write instance could be existed at the same time */
        ForEachOfList(g_inst_list, m);
        {
            bpp_srv_inst_struct *instance = (bpp_srv_inst_struct *)m;
            if (instance->mode == mode)
                return RESULT_FAIL;
        }
    }

    inst->mode = mode;

    return RESULT_SUCC;        
}

U32 srv_bpp_list(BppHandle srv, U32 index, U32 *buff, U32 count)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    U32 i;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_LIST, inst, g_job_sum.job_count);
    
    if (!inst) return 0;

    if (!buff) return g_job_sum.job_count;

    for (i = 0; i < count && (i+index) < g_job_sum.job_count; i++)
    {
        buff[i] = g_job_sum.table[i].id;
    }

    return i;
}

S32 srv_bpp_edit(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_EDIT, inst, jobID);
    
    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    /* This is new created job */
    if (jobID > g_config.maxJobs)
        return RESULT_SUCC;

    /* Job in job list means:
        1. Job just been editing
        2. Job just been printing
       In both cases, should not be allowed enter edit mode */
    if (bpp_get_job(g_job_list, jobID))
        return RESULT_FAIL;

    job = bpp_load_job(inst, jobID, MODE_RDWRITE);
    if (job == NULL)
        return RESULT_FAIL;

    return RESULT_SUCC;
}

U32 srv_bpp_create(BppHandle srv)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_create_job(inst);
    if (job == NULL)
        return RESULT_FAIL;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_CREATE, inst, job->id);
    
    return job->id;
}

U32 srv_bpp_save(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;
    U32 event;
    U16 para = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_SAVE, inst, jobID);
    
    if (inst == NULL || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job || job->mode == MODE_RDONLY)
        return 0;

    if (jobID > g_config.maxJobs) 
    {
        jobID = bpp_add_job(job);
        event = EV_JOB_NEW;
        if (jobID)
            bpp_notify_all('post', event, MakeParam(para, jobID));
    }
    else 
    {
        jobID = bpp_save_job(job);
        event = EV_JOB_UPDATE;
        para = INFO_JOB;
    }

    bpp_destroy_job(job);

    return jobID;
}

S32 srv_bpp_cancel(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_CANCEL, inst, jobID);
    
    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    if (jobID > g_config.maxJobs)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    
    if (!job)
        return RESULT_FAIL;

    return bpp_destroy_job(job);
}

S32 srv_bpp_delete(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;
    S32 retval = RESULT_SUCC;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_DELETE, inst, jobID);
    
    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_get_job(g_job_list, jobID);

    if (job)
    {
        if (job->owner != inst)
            return RESULT_FAIL;
        
        retval = bpp_destroy_job(job);
        if (retval == RESULT_PENDING)
            job->flags |= FLAG_DELETE;
    }

    if (retval == RESULT_SUCC)
    {
        bpp_delete_job(jobID);
        bpp_notify_all('post', EV_JOB_DELETE, MakeParam(0, jobID));
    }

    return retval;
}

S32 srv_bpp_accept(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_ACCEPT, inst, jobID);
    
    if (!inst)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job || job->op_code == OP_NONE)
        return RESULT_FAIL;

    return bpp_state_hdlr(REQ_ACCEPT, job, NULL);
}

S32 srv_bpp_abort(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_ABORT, inst, jobID);

    if (!inst)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job || job->op_code == OP_NONE)
        return RESULT_SUCC;

    return bpp_state_hdlr(REQ_ABORT, job, NULL);
}

S32 srv_bpp_bind(BppHandle srv, U32 jobID, const PrinterAddr *addr, U32 update)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_BIND, inst, jobID, addr->lap, addr->uap, addr->nap);
    
    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job || job->mode == MODE_RDONLY || job->op_code != OP_NONE)
        return RESULT_FAIL;

    if (SameAddr(&job->device.addr, addr))
        return RESULT_SUCC;

    job->device.valid = 0;
    job->device.addr = *addr;
    job->device.attr = DefaultPrinterAttrs;
    job->status.dev = PRINTER_UNKNOWN;

    if (update)
        return bpp_state_hdlr(REQ_UPDATE, job, NULL);

    return RESULT_SUCC;
}

S32 srv_bpp_set_option(BppHandle srv, U32 jobID, const PrintOption *option)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    if (!option)
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_SET_DEFAULT_OPTION, inst, jobID);
    else
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_SET_OPTION, 
            inst, jobID, option->mediaSize, option->copies, option->orientation, option->quality, option->sides);

    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job || job->mode == MODE_RDONLY || job->op_code != OP_NONE)
        return RESULT_FAIL;

    if (option)
    {
        PrintOption *job_opt = &job->info.option;
        
        job_opt->mediaSize = option->mediaSize ? option->mediaSize : job_opt->mediaSize;
        job_opt->mediaType = option->mediaType ? option->mediaType : job_opt->mediaType;
        job_opt->quality = option->quality ? option->quality : job_opt->quality;
        job_opt->sides = option->sides ? option->sides : job_opt->sides;
        job_opt->orientation = option->orientation ? option->orientation : job_opt->orientation;
        job_opt->numberUp = option->numberUp ? option->numberUp : job_opt->numberUp;
        job_opt->copies = option->copies ? option->copies : job_opt->copies;
    }
    else
    {
        if (job->device.valid)
            bpp_get_compatible_options(&job->info.option, &job->device.attr);
        else
            job->info.option = DefaultPrintOptions;
    }

    job->info.use_default = 0;

    return RESULT_SUCC;
}

S32 srv_bpp_set_data(BppHandle srv, U32 jobID, const PrintData *data)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_SET_DATA, inst, jobID, data->type, data->size); 
    
    if (!inst || !data)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job)
        return RESULT_FAIL;

    if (job->op_code == OP_PRINT &&
        job->data.type != 'none' &&
        ((job->data.type == 'file' && data->type == BPP_DATA_BUFF) ||
        (job->data.type == 'buff' && data->type == BPP_DATA_FILE)))
    {
        /* We don't allow to change data type during printing */
        return RESULT_FAIL;
    }

    if (data->type == BPP_DATA_FILE)
    {
        job->data.type = 'file';
        mmi_wcscpy(job->data.u.file, data->u.file);
    }
    else
    {
        job->data.type = 'buff';
        job->data.u.buff = data->u.buff;
    }
    job->data.size = data->size;
    job->data.more = data->more;

    return RESULT_SUCC;
}

S32 srv_bpp_set_password(BppHandle srv, U32 jobID, const CHAR *passwd)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_SET_PASSWD, inst, jobID); 
    
    if (!inst || !passwd)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    if (!job)
        return RESULT_FAIL;

    strcpy(job->passwd, passwd);

    return RESULT_SUCC;
}

S32 srv_bpp_update(BppHandle srv, U32 jobID)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_UPDATE, inst, jobID); 
    
    if (!inst || inst->mode != MODE_RDWRITE)
        return RESULT_FAIL;

    job = bpp_get_job(&inst->job_list, jobID);
    
    if (!job || job->mode == JOB_MODE_RDONLY)
        return RESULT_FAIL;

    if (!ValidAddr(&job->device.addr))
        return RESULT_FAIL;
    
    return bpp_state_hdlr(REQ_UPDATE, job, NULL);
}

S32 srv_bpp_print(BppHandle srv, U32 jobID, U32 mode, const PrintData *data)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_PRINT, inst, jobID); 

    if (!inst)
        return RESULT_FAIL;

    if (job = bpp_get_job(g_job_list, jobID)) 
    {
        if (job->owner != inst)
            return RESULT_FAIL;
    }
    else
        job = bpp_load_job(inst, jobID, JOB_MODE_RDONLY);

    if (!job)
        return RESULT_FAIL;

    if (!ValidAddr(&job->device.addr))
        return RESULT_FAIL;

    job->print_mode = mode;

    if (data)
        srv_bpp_set_data(srv, jobID, data);
    else
        job->data.type = 'none';
    
    return bpp_state_hdlr(REQ_PRINT, job, (PrintData *)data);
}

S32 srv_bpp_get_info(BppHandle srv, U32 jobID, void *info, U32 filter)
{
    bpp_srv_inst_struct *inst = bpp_find(srv);
    bpp_srv_job_struct *job;
    U32 read = 0;
    S32 retval = RESULT_SUCC;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_GET_INFO, inst, jobID, filter); 
    
    if (!inst)
        return RESULT_FAIL;

    if (inst->mode == MODE_RDONLY)
    {
        job = bpp_read_job(jobID);
        read = 1;
    }
    else
    {
        /* We should make sure that only owner can retrieve latest info */
        job = bpp_get_job(&inst->job_list, jobID);
        if (!job)
        {
            job = bpp_read_job(jobID);
            read = 1;
        }
    }

    if (job == NULL)
        return RESULT_FAIL;

    switch (filter) {
    case INFO_PRINTER_ADDR:

        *((PrinterAddr *)info) = job->device.addr;

        break;

    case INFO_PRINTER_ATTR:

        *((PrinterAttribute *)info) = job->device.attr;

        break;

    case INFO_PRINTER_VALID:

        *((U32 *)info) = job->device.valid;

        break;

    case INFO_PRINTER:
        
        *((PrinterInfo *)info) = job->device;

        break;
        
    case INFO_PRINT_OPTION:

        *((PrintOption *)info) = job->info.option;

        break;

    case INFO_JOB_OPTION:

        *((PrintOptionInfo *)info) = job->info;
        
        break;

    case INFO_JOB:
        {
            JobInfo *job_info = (JobInfo *)info;
            job_info->jobID = job->id;
            job_info->option = job->info;
            job_info->printer = job->device;
        }

        break;

    default:
        retval = RESULT_FAIL;
        break;
    }

    if (read)
        free_ctrl_buffer(job);

    return retval;
}

U32 srv_bpp_job_status(U32 jobID)
{
    bpp_srv_job_struct *job;
    U32 status;

    job = bpp_get_job(g_job_list, jobID);
    if (job)
    {
        if (jobID > g_config.maxJobs)
            status = BPP_JOB_NEW;
        else if (job->mode == MODE_RDWRITE)
            status = BPP_JOB_EDIT;
        else
            status = BPP_JOB_RDONLY;
    }
    else
    {
        job = bpp_read_job(jobID);
        if (job)
        {
            status = BPP_JOB_RDONLY;
            free_ctrl_buffer(job);
        }
        else
        {
            status = BPP_JOB_INVALID;
        }
    }

    return status;
}

U32 srv_bpp_is_busy(void)
{
    bpp_list_struct *m;
    
    ForEachOfList(g_job_list, m)
    {
        bpp_srv_job_struct *job = ListEntry(m, bpp_srv_job_struct, glb_entry);
        if (job->op_code != OP_NONE)
            return 1;
    }

    return 0;
}

S32 srv_bpp_media_size(U64 mediaSize, U32 *width, U32 *height)
{
    const CHAR *name;
    CHAR t_buff[16];
    U32 x = 0, y = 0;
    float w = 0, h = 0;
    U8 idx = bit_offset(mediaSize);

    if (idx >= BPP_MEIDA_SIZE_MAX_ENUM)
        return RESULT_FAIL;

    name = bpp_media_size_self_desc_name[idx];

    switch (idx) {
    case BPP_MEDIA_SIZE_4X6_POSTCARD:
    case BPP_MEDIA_SIZE_LETTER:
        
        sscanf(name + 3, "%[^_]s", t_buff);  /* read str after na_ */
        name += strlen(t_buff) + 1 + 3;
        sscanf(name, "%fx%fin", &w, &h);
        *width = (U32)(w * MmPerInch);
        *height =(U32)(h * MmPerInch);
        
        break;

    default:

        sscanf(name + 4, "%[^_]s", t_buff);  /* read str after iso_ */
        name += strlen(t_buff) + 1 + 4;
        sscanf(name, "%dx%dmm", &x, &y);
        *width = x;
        *height = y;

        break;
    }

    return RESULT_SUCC;
}


static MMI_RET bpp_event_proc(bpp_event_struct *evt)
{
    bpp_srv_inst_struct *inst = (bpp_srv_inst_struct *)evt->user_data;
    
    MMI_ASSERT(evt->evt_id == BPP_EVENT_ID);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_NOTIFY, inst, evt->notify, evt->para); 
    
    if (inst->handle && inst->notify) 
    {
        if (inst->event_mask & evt->notify)
            inst->notify(inst->handle, evt->notify, evt->para);
    }

    return MMI_RET_OK;
}

static void bpp_msg_hdlr(void *para, S32 mod_src, ilm_struct *ilm)
{
    U32 evt;
    bpp_srv_job_struct *job;
    bt_bpp_common_ind_struct *ind = (bt_bpp_common_ind_struct *)para;

    switch (ilm->msg_id) {
    case MSG_ID_BT_BPP_OPEN_CNF:
        evt = CNF_OPEN;
        break;
        
    case MSG_ID_BT_BPP_CLOSE_CNF:
        evt = CNF_CLOSE;
        break;
        
    case MSG_ID_BT_BPP_GET_ATTR_CNF:
        evt = CNF_UPDATE;
        break;

    case MSG_ID_BT_BPP_PRINT_DOC_CNF:
        evt = CNF_PRINT;
        break;
        
    case MSG_ID_BT_BPP_JOB_STATE_IND:
        evt = IND_STATUS;
        break;
        
    case MSG_ID_BT_BPP_PROGRESS_IND:
        evt = IND_PROGRESS;
        break;
        
    case MSG_ID_BT_BPP_DISC_IND:
        evt = IND_DISCONNECT;
        break;

    case MSG_ID_BT_BPP_AUTH_IND:
        evt = IND_AUTHENTICATE;
        break;

    default:
        return;
    }

    job = bpp_find_job(ind->hprinter);

    if (job)
        bpp_state_hdlr(evt, job, para);
}

static void bpp_send_msg(U32 msg_id, bpp_srv_job_struct *job)
{
    local_para_struct *local_para = NULL;
    peer_buff_struct *peer_para = NULL;
    
    switch (msg_id) {
    case MSG_OPEN:
        {
            bt_bpp_open_req_struct *req = (bt_bpp_open_req_struct *)
                construct_local_para(sizeof(*req), TD_DL);
            
            msg_id = MSG_ID_BT_BPP_OPEN_REQ;
            
            req->prt_handle = job->conn_hd;
            req->add = *((goep_bd_addr_struct *)&job->device.addr);

            local_para = (local_para_struct *)req;
        }
        break;

    case MSG_CLOSE:
        {
            bt_bpp_close_req_struct *req = (bt_bpp_close_req_struct *)
                construct_local_para(sizeof(*req), TD_DL);

            msg_id = MSG_ID_BT_BPP_CLOSE_REQ;

            req->hprinter= job->conn_hd;

            local_para = (local_para_struct *)req;
        }
        break;

    case MSG_GET_ATTR:
        {
            bt_bpp_get_attr_req_struct *req = (bt_bpp_get_attr_req_struct *)
                construct_local_para(sizeof(*req), TD_DL);
            
            msg_id = MSG_ID_BT_BPP_GET_ATTR_REQ;
            
            req->hpriter = job->conn_hd;
            memcpy(req->attr_req, DefaultUpdateAttrs, sizeof(req->attr_req));

            local_para = (local_para_struct *)req;
        }
        break;

    case MSG_VALIDATE:
        {
            bt_bpp_authen_rsp_struct *rsp = (bt_bpp_authen_rsp_struct *)
                construct_local_para(sizeof(*rsp), TD_DL);

            msg_id = MSG_ID_BT_BPP_AUTH_RSP;

            rsp->hprinter = job->conn_hd;
            rsp->bt_addr = *((goep_bd_addr_struct *)&job->device.addr);

            if (strlen(job->passwd))
            {
                rsp->cancel = KAL_FALSE;
                rsp->passwd_len = strlen(job->passwd);
                strcpy(rsp->passwd, job->passwd);
            }
            else
                rsp->cancel = KAL_TRUE;
            
            rsp->userid[0] = '\0';
            rsp->userid_len = 0;

            local_para = (local_para_struct *)rsp;
        }
        break;

    case MSG_PRINT_DOC:
        {
            bt_bpp_print_doc_req_struct *req = (bt_bpp_print_doc_req_struct *)
                construct_local_para(sizeof(*req), TD_DL);
            peer_buff_struct *buff = NULL;

            msg_id = MSG_ID_BT_BPP_PRINT_DOC_REQ;

            req->hpriter = job->conn_hd;
            if (job->print_mode == PRINT_MODE_ADVANCED)
            {
                if (job->info.use_default)
                    req->print_mode = BPP_JOB_BASE_DEFAULT_PRINT;
                else
                    req->print_mode = BPP_JOB_BASE_NOT_DEFAULT_PRINT;
            }
            else
            {
                req->print_mode = BPP_SIMPLE_PUSH_PRINT;
            }

            if (req->print_mode == BPP_JOB_BASE_NOT_DEFAULT_PRINT)
            {
                PrintOption *opt = &job->info.option;

                req->pjob_name = NULL;
                req->puser_name = NULL;
                req->copies = opt->copies;
                req->numberup = (bpp_numberup_enum)opt->numberUp;
                req->side = (bpp_sided_enum)bit_offset(opt->sides);
                req->orientation = (bpp_orientation_enum)bit_offset(opt->orientation);
                req->quality = (bpp_print_quality_enum)bit_offset(opt->quality);
                req->media_type = (bpp_media_type_enum)bit_offset(opt->mediaType);
                req->media_size = (bpp_media_size_enum)bit_offset(opt->mediaSize);
            }

            if (job->data.type == 'file')
            {
                mmi_wcscpy(req->file_name, job->data.u.file);
            }
            else
            {
                U16 length;
                req->file_name[0] = '\0';
                buff = construct_peer_buff((U16)job->data.size, 0, 0, TD_DL);
                memcpy((CHAR *)get_pdu_ptr(buff, &length), job->data.u.buff, job->data.size);
            }
            req->total_data_len = job->data.size;

            local_para = (local_para_struct *)req;
            if (buff)
                peer_para = buff;
        }
        break;

    case MSG_PROGRESS:
        {
            bt_bpp_progress_rsp_struct *rsp = (bt_bpp_progress_rsp_struct *)
                construct_local_para(sizeof(*rsp), TD_DL);

            msg_id = MSG_ID_BT_BPP_PROGRESS_RSP;

            rsp->hprinter= job->conn_hd;

            local_para = (local_para_struct *)rsp;
        }
        break;

    default:
        return;
    }

    msg_send6(MOD_MMI, MOD_BT, BT_BPP_SAP, (msg_type)msg_id, local_para, peer_para);    
}

static bpp_srv_inst_struct *bpp_new(U32 mode)
{
    U32 i;
    bpp_srv_inst_struct *inst = NULL;

    if (mode == MODE_RDWRITE)
    {
        bpp_list_struct *m;
        ForEachOfList(g_inst_list, m)
        {
            bpp_srv_inst_struct *i = (bpp_srv_inst_struct *)m;
            if (i->mode == MODE_RDWRITE)
                return NULL;
        }
    }
    for (i = 0; i < MAX_INSTANCES; i++) 
    {
        if (!g_insts[i].handle) 
        {
            inst = &g_insts[i];
            break;
        }
    }

    if (!inst)
        return NULL;

    inst->handle = MakeHandle(inst);
    inst->mode = mode;

    ListInit(&inst->job_list);

    ListAdd(g_inst_list, &inst->entry);

    return inst;
}

static void bpp_delete(bpp_srv_inst_struct *inst)
{
    if (!in_list(g_inst_list, &inst->entry))
        return;

    inst->handle = 0;
    ListDelete(&inst->entry);
}

static bpp_srv_inst_struct *bpp_find(S32 inst_hd)
{
    bpp_list_struct *m;
        
    ForEachOfList(g_inst_list, m)
    {
        bpp_srv_inst_struct *inst = ListEntry(m, bpp_srv_inst_struct, entry);
        if (inst->handle == inst_hd)
            return inst;
    }

    return NULL;
}

static void bpp_disconnect(U32 conn_id)
{
    bpp_list_struct *m;

    ForEachOfList(g_job_list, m)
    {
        bpp_srv_job_struct *job = ListEntry(m, bpp_srv_job_struct, glb_entry);

        if (job->cm_conn_id == (S32)conn_id)
        {
            bpp_destroy_job(job);
            return;
        }
    }
}

static bpp_srv_job_struct *bpp_new_job(U32 job_id)
{
    bpp_srv_job_struct *job;
    
    job = get_ctrl_buffer(sizeof(*job));

    memset(job, 0, sizeof(*job));

    if (job_id)
        job->id = job_id;
    else
        job->id = alloc_new_job_id();
    
    ListInit(&job->glb_entry);
    ListInit(&job->inst_entry);
    
    job->op_code = OP_NONE;
    job->flags = 0;
    job->data.type = 'none';
    job->info.use_default = 1;

    job->state = STATE_CLOSE_ED;

    return job;
}

static bpp_srv_job_struct *bpp_create_job(bpp_srv_inst_struct *inst)
{
    bpp_srv_job_struct *job;

    if (g_job_sum.job_count >= MAX_JOBS)
        return NULL;

    job = bpp_new_job(0);

    job->owner = inst;
    job->mode = MODE_RDWRITE;

    job->info.option = DefaultPrintOptions;
    job->device.valid = 0;
    job->device.attr = DefaultPrinterAttrs;
    job->status.dev = PRINTER_UNKNOWN;

    ListAdd(g_job_list, &job->glb_entry);
    ListAdd(&inst->job_list, &job->inst_entry);

    return job;
}

static S32 bpp_destroy_job(bpp_srv_job_struct *job)
{
    S32 retval = RESULT_SUCC;

    if (job->state == STATE_CLOSE_ED)
    {
        ListDelete(&job->glb_entry);
        ListDelete(&job->inst_entry);
        free_ctrl_buffer(job);
    }
    else
    {
        job->flags |= FLAG_DESTROY;
        bpp_state_hdlr(REQ_ABORT, job, NULL);
        retval = RESULT_PENDING;
    }

    return retval;
}

static bpp_srv_job_struct *bpp_load_job(bpp_srv_inst_struct *inst, U32 jobID, U32 mode)
{
    bpp_srv_job_struct *job = bpp_read_job(jobID);

    if (job) 
    {
        job->owner = inst;
        job->mode = mode;

        ListAdd(&inst->job_list, &job->inst_entry);
        ListAdd(g_job_list, &job->glb_entry);
    }

    return job;
}

static bpp_srv_job_struct *bpp_get_job(bpp_list_struct *list, U32 jobID)
{
    bpp_list_struct *m;

    ForEachOfList(list, m)
    {
        bpp_srv_job_struct *job;

        if (list == g_job_list)
            job = ListEntry(m, bpp_srv_job_struct, glb_entry);
        else
            job = ListEntry(m, bpp_srv_job_struct, inst_entry);

        if (job->id == jobID)
            return job;
    }

    return NULL;
}

static bpp_srv_job_struct *bpp_find_job(S32 conn_hd)
{
    bpp_list_struct *m;

    ForEachOfList(g_job_list, m)
    {
        bpp_srv_job_struct *job = ListEntry(m, bpp_srv_job_struct, glb_entry);

        if ((job->conn_hd & 0x7FFFFFFF) == (conn_hd & 0x7FFFFFFF))
            return job;
    }

    return NULL;
}

static bpp_srv_job_struct *bpp_read_job(U32 jobID)
{
    FS_HANDLE fh;
    U32 pos = 0, read, i;
    bpp_srv_job_struct *job = NULL;
    bpp_job_save_struct save;

    for (i = 0; i < g_job_sum.job_count; i++) 
    {
        if (g_job_sum.table[i].id && jobID == g_job_sum.table[i].id) 
        {
            pos = g_job_sum.table[i].pos;
            break;
        }
    }

    if (i == g_job_sum.job_count)
        return NULL;

    if ((fh = bpp_open_file(FS_READ_ONLY)) < 0)
        return NULL;

    FS_Seek(fh, pos, FS_FILE_BEGIN);
    FS_Read(fh, &save, sizeof(save), &read);

    FS_Close(fh);
    
    if (read != sizeof(save))
        return NULL;

    job = bpp_new_job(jobID);

    job->device = save.device;
    job->status.dev = PRINTER_UNKNOWN;
    if (save.info.use_default)
        job->info.option = DefaultPrintOptions;
    else
        job->info.option = save.info.option;
    job->info.use_default = save.info.use_default;

    return job;
}

static U32 bpp_add_job(bpp_srv_job_struct *job)
{
    FS_HANDLE fh;
    U32 job_id = 0;
    bpp_job_save_struct save_job;

    if ((fh = bpp_open_file(FS_READ_WRITE)) < 0) 
        fh = bpp_open_file(FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fh > 0) 
    {
        U32 size, pos;

        FS_Seek(fh, 0, FS_FILE_END);
        FS_GetFilePosition(fh, &pos);

        job_id = alloc_job_id();
        save_job.head.del_flag = 0;
        save_job.head.id = job_id;
        save_job.device = job->device;
        save_job.info = job->info;

        FS_Write(fh, &save_job, sizeof(save_job), &size);
        if (size == sizeof(save_job)) 
        {
            g_job_sum.table[g_job_sum.job_count].id = job_id;
            g_job_sum.table[g_job_sum.job_count].pos = pos;
            g_job_sum.job_count++;
        }
        else
            job_id = 0;

        FS_Close(fh);
    }

    return job_id;
}

static U32 bpp_save_job(bpp_srv_job_struct *job)
{
    S32 fh;
    U32 pos = 0, i, written;
    bpp_job_save_struct save;

    for (i = 0; i < g_job_sum.job_count; i++) 
    {
        if (g_job_sum.table[i].id && job->id == g_job_sum.table[i].id) 
        {
            pos = g_job_sum.table[i].pos;
            break;
        }
    }
    if (i == g_job_sum.job_count)
        return 0;

    if ((fh = bpp_open_file(FS_READ_WRITE)) < 0)
        return 0;
    
    FS_Seek(fh, pos, FS_FILE_BEGIN);

    save.head.del_flag = 0;
    save.head.id = job->id;
    save.device = job->device;
    save.info = job->info;

    FS_Write(fh, &save, sizeof(save), &written);

    FS_Close(fh);

    return (written == sizeof(save)) ? job->id : 0;
}

static S32 bpp_delete_job(U32 jobID)
{
    S32 retval = 0; 
    U32 pos, i;
    FS_HANDLE fh;
    bpp_job_head_struct head;

    pos = 0;
    for (i = 0; i < g_job_sum.job_count; i++) 
    {
        if (g_job_sum.table[i].id && jobID == g_job_sum.table[i].id)
        {
            pos = g_job_sum.table[i].pos;
            break;
        }
    }
    if (i == g_job_sum.job_count)
        return RESULT_FAIL;

    if ((fh = bpp_open_file(FS_READ_WRITE)) < 0)
        return RESULT_FAIL;

    FS_Seek(fh, pos, FS_FILE_BEGIN);
    
    head.del_flag = 1;
    head.id = jobID;
    retval = FS_Write(fh, &head, sizeof(head), NULL);

    FS_Close(fh);

    if (retval < 0)
        return RESULT_FAIL;

    if (retval >= 0) 
    {
        for (; i < g_job_sum.job_count-1; i++) 
        {
            g_job_sum.table[i].id = g_job_sum.table[i+1].id;
            g_job_sum.table[i].pos = g_job_sum.table[i+1].pos;
        }
        g_job_sum.table[i].id = 0;
        g_job_sum.job_count--;
        g_job_sum.del_count++;
    }

    if (DefragCriterion(g_job_sum.job_count, g_job_sum.del_count))
        bpp_defrag();

    return RESULT_SUCC;
}

static FS_HANDLE bpp_open_file(U32 flag)
{
    WCHAR file[64];
    S32 fh;
    U8 buff[8];
    
    kal_wsprintf(file, "%c:\\@bpp\\%w", g_config.storage, g_config.jobFile);

    fh = FS_Open(file, flag);
    if (fh < 0)
        return fh;

    if (flag & FS_CREATE_ALWAYS)
    {
        FS_Write(fh, (CHAR *)GuardPattern, sizeof(GuardPattern), NULL);
    }
    else
    {
        FS_Read(fh, buff, sizeof(buff), NULL);
        if (memcmp(buff, GuardPattern, sizeof(buff)) != 0)
        {
            FS_Close(fh);
            FS_Delete(file);
            fh = -1;
        }
        FS_Seek(fh, sizeof(buff), FS_FILE_BEGIN);
    }

    return fh;
}

static void bpp_defrag(void)
{
    if (!g_job_sum.job_count)
    {
        WCHAR file[64];
        
        kal_wsprintf(file, "%c:\\@bpp\\%w", g_config.storage, g_config.jobFile);
        FS_Delete(file);
        g_job_sum.del_count = 0;
    }
}

static S32 bpp_state_hdlr(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval;
    U8 state = job->state;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_STATE_HDLR_BEGIN, in, job->state); 

    retval = BppStateHdlr[job->state](in, job, para);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_SRV_STATE_HDLR_END, retval, job->state); 
    
    if (retval != RESULT_SUCC && retval != RESULT_PENDING)
    {
        if (in == REQ_UPDATE)
            bpp_notify('post', job->owner, 
                EV_UPDATE_FAIL, MakeParam(E_OP_BUSY, job->id));
        else if ((in == REQ_PRINT) || (in == REQ_ACCEPT))
            bpp_notify('post', job->owner,
                EV_JOB_FINISH, MakeParam(E_OP_BUSY, job->id));
    }

    if (state != STATE_CLOSE_ED && job->state == STATE_CLOSE_ED)
    {
        bpp_srv_inst_struct *inst = job->owner;
            
        if (job->flags & FLAG_DELETE)
            bpp_delete_job(job->id);
        if (job->flags & FLAG_DESTROY || job->mode == MODE_RDONLY)
            bpp_destroy_job(job);

        if (inst->flags & FLAG_CLOSE && ListEmpty(&inst->job_list))
            bpp_delete(inst);
    }

    return retval;
}

static S32 bpp_state_close_ed(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;
    
    switch (in) {
    case REQ_UPDATE:

        retval = bpp_update_req_hdlr(job);

        break;
        
    case REQ_PRINT:

        retval = bpp_print_req_hdlr(job);
        
        break;

    case REQ_ACCEPT:

        retval = RESULT_FAIL;

        break;

    case REQ_ABORT:

        retval = RESULT_SUCC;

        break;

    default:
        break;
    }

    return retval;
}

static S32 bpp_state_wait_start(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;

    switch (in) {
    case REQ_ACCEPT:

        job->conn_hd = bt_bpp_alloc_prt_handle((goep_bd_addr_struct *)&job->device.addr);

        job->cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_BASIC_PRINTING, &(job->device.addr), NULL);
        if (job->cm_conn_id < 0)
        {
            job->state = STATE_CLOSE_ED;
            return RESULT_FAIL;
        }
        
        bpp_send_msg(MSG_OPEN, job);

        job->state = STATE_OPEN;

        retval = RESULT_SUCC;

        break;
        
    case REQ_ABORT:
        
        job->state = STATE_CLOSE_ED;
        retval = RESULT_SUCC;
        
        break;

    default:
        break;
    }

    return retval;
}

static S32 bpp_state_open(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;
    bt_bpp_open_cnf_struct *open_cnf = (bt_bpp_open_cnf_struct *)para;

    switch (in) {
    case CNF_OPEN:

        if (open_cnf->ret == BPP_ADP_SUCCESS) 
            retval = bpp_open_succ_hdlr(job, open_cnf->cm_conn_id);
        else
        {
            U16 cause = conv_cause(open_cnf->ret);
            retval = bpp_open_fail_hdlr(job, cause);
        }

        break;

    case IND_DISCONNECT:

        retval = bpp_open_fail_hdlr(job, E_LINK_BROKEN);

        break;

    case IND_AUTHENTICATE:

        if (strlen(job->passwd))
            bpp_send_msg(MSG_VALIDATE, job);
        else
        {
            job->state = STATE_WAIT_AUTH;
            bpp_notify('post', job->owner, 
                EV_JOB_REQUEST, MakeParam(REQUEST_AUTH, job->id));
        }

        break;

    case REQ_ABORT:

        job->op_result = E_USER_ABORT;
        job->flags |= FLAG_ABORT;
        job->state = STATE_CLOSE;
        bpp_send_msg(MSG_CLOSE, job);
        
        retval = RESULT_SUCC;

        break;

    default:
        break;
    }

    return retval;
}

static S32 bpp_state_wait_auth(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;
    bt_bpp_open_cnf_struct *open_cnf = (bt_bpp_open_cnf_struct *)para;

    switch (in) {
    case REQ_ACCEPT:

        job->state = STATE_OPEN;
        bpp_send_msg(MSG_VALIDATE, job);
        retval = RESULT_SUCC;

        break;

    case REQ_ABORT:

        job->passwd[0] = '\0';
        job->state = STATE_OPEN;
        bpp_send_msg(MSG_VALIDATE, job);
        retval = RESULT_SUCC;

        break;

    case CNF_OPEN: /* Must be fail case */
        {
            U16 cause = conv_cause(open_cnf->ret);
            retval = bpp_open_fail_hdlr(job, cause);
        }
        break;

    case IND_DISCONNECT:

        retval = bpp_open_fail_hdlr(job, E_LINK_BROKEN);

        break;

    default:
        break;
        
    }

    return retval;
}

static S32 bpp_state_open_ed(U32 evt, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;

    switch (evt){
    case CNF_UPDATE:
        {
            bt_bpp_get_attr_cnf_struct *cnf = 
                (bt_bpp_get_attr_cnf_struct *)para;
            
            if (cnf->ret == BPP_ADP_SUCCESS)
                bpp_update_hdlr(job, &cnf->capability);

            job->op_result = conv_cause(cnf->ret);
            job->state = STATE_CLOSE;
            bpp_send_msg(MSG_CLOSE, job);
        }
        break;

    case CNF_PRINT:
        {
            bt_bpp_print_doc_cnf_struct *cnf = 
                (bt_bpp_print_doc_cnf_struct *)para;
            
            job->op_result = conv_cause(cnf->ret);
            
            if (job->op_result == E_NONE)
                bpp_notify('post', job->owner, 
                    EV_JOB_PROGRESS, MakeParam(100, job->id));

            job->state = STATE_CLOSE;
            bpp_send_msg(MSG_CLOSE, job);
            
        }
        break;

    case IND_STATUS:
        {
            bt_bpp_job_state_ind_struct *status =
                (bt_bpp_job_state_ind_struct *)para;

            if ((status->job_state == BPP_JOB_STATE_WAITING ||
                 status->job_state == BPP_JOB_STATE_STOPPED) && 
                 status->state_reson)
            {
                bpp_notify('post', job->owner, 
                    EV_JOB_STATUS, MakeParam(status->state_reson, job->id)); 
            }
        }
        break;

    case IND_PROGRESS:
        {
            bt_bpp_progress_ind_struct *ind = 
                (bt_bpp_progress_ind_struct *)para;

            bpp_notify('post', job->owner, 
                EV_JOB_PROGRESS, MakeParam(ind->precent, job->id));

            if (job->data.more)
            {
                job->state = STATE_WAIT_DATA;
                bpp_notify('post', job->owner, 
                    EV_JOB_REQUEST, MakeParam(REQUEST_DATA, job->id));
            }
            else
            {
                bpp_send_msg(MSG_PROGRESS, job);
            }
        }
        break;

    case IND_DISCONNECT:

        job->state = STATE_CLOSE_ED;
        srv_bt_cm_stop_conn(job->cm_conn_id);
        bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_DOWN, job->conn_id));

        if (job->op_code == OP_UPDATE)
            bpp_notify('post', job->owner, EV_UPDATE_FAIL,
                MakeParam(E_LINK_BROKEN, job->id));
        else
            bpp_notify('post', job->owner, EV_JOB_FINISH,
                MakeParam(E_LINK_BROKEN, job->id));

        job->op_code = OP_NONE;

        break;

    case REQ_ABORT:

        job->op_result = E_USER_ABORT;

        job->state = STATE_CLOSE;
        bpp_send_msg(MSG_CLOSE, job);

        retval = RESULT_SUCC;

        break;

    default:
        break;
    }

    return retval;
}

static S32 bpp_state_close(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;
    bt_bpp_open_cnf_struct *open_cnf = (bt_bpp_open_cnf_struct *)para;

    if (in == CNF_OPEN && open_cnf->ret == BPP_ADP_SUCCESS)
        return retval;

    switch (in) {
    case IND_DISCONNECT:
    case CNF_OPEN:        
    case CNF_CLOSE:

        if (in == IND_DISCONNECT)        
        {
            srv_bt_cm_stop_conn(job->cm_conn_id);
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_DOWN, job->conn_id));
        }
        else if (in == CNF_OPEN)
        {
            srv_bt_cm_stop_conn(job->cm_conn_id);
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_FAIL, job->conn_id));
        }

        if (job->op_code == OP_UPDATE)
        {
            if (job->op_result == E_NONE)
                bpp_notify('post', job->owner, 
                    EV_JOB_UPDATE, MakeParam(INFO_PRINTER_ATTR, job->id));
            else
                bpp_notify('post', job->owner,
                    EV_UPDATE_FAIL, MakeParam(job->op_result, job->id));
        }
        else
            bpp_notify('post', job->owner, 
                EV_JOB_FINISH, MakeParam(job->op_result, job->id));
        
        job->op_code = OP_NONE;
        if (in == CNF_CLOSE)
            job->state = STATE_DISC;
        else
            job->state = STATE_CLOSE_ED;

        break;
    }

    return retval;
}

static S32 bpp_state_disc(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;
    bt_bpp_open_cnf_struct *open_cnf = (bt_bpp_open_cnf_struct *)para;
    
    switch (in) {
    case REQ_UPDATE:
    
        bpp_notify('post', job->owner, 
            EV_UPDATE_FAIL, MakeParam(E_OP_BUSY, job->id));

        break;

    case REQ_PRINT:

        bpp_notify('post', job->owner,
            EV_JOB_FINISH, MakeParam(E_OP_BUSY, job->id));

        break;

    case CNF_OPEN:
        if (open_cnf->ret == BPP_ADP_SUCCESS)
        {
            job->conn_id = open_cnf->cm_conn_id;
            srv_bt_cm_connect_ind(job->cm_conn_id);
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_UP, job->conn_id));
            bpp_send_msg(MSG_CLOSE, job);
        }
        else
        {
            srv_bt_cm_stop_conn(job->cm_conn_id);
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_FAIL, job->conn_id));
            job->state = STATE_CLOSE_ED;
        }
        break;

    case CNF_CLOSE:
         break;

    case IND_DISCONNECT:
        srv_bt_cm_stop_conn(job->cm_conn_id);
        if (job->flags & FLAG_ABORT)
        {
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_FAIL, job->conn_id));
            job->flags &= ~FLAG_ABORT;
        }
        else
        {
            bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_DOWN, job->conn_id));
        }
        job->state = STATE_CLOSE_ED;        
        break;
    }

    return retval;
}

static S32 bpp_state_wait_data(U32 in, bpp_srv_job_struct *job, void *para)
{
    S32 retval = RESULT_FAIL;

    switch (in) {
    case REQ_ACCEPT:

        if (job->data.type == 'none')
        {
            job->op_result = E_INVALID_DATA;
            
            job->state = STATE_CLOSE;
            bpp_send_msg(MSG_CLOSE, job);
        }
        else
        {
            job->state = STATE_OPEN_ED;
            bpp_send_msg(MSG_PRINT_DOC, job);
        }
        retval = RESULT_SUCC;

        break;

    case REQ_ABORT:

        job->op_result = E_USER_ABORT;
        
        job->state = STATE_CLOSE;
        bpp_send_msg(MSG_CLOSE, job);
        
        retval = RESULT_SUCC;
        
        break;

    case IND_DISCONNECT:

        job->state = STATE_CLOSE_ED;
        srv_bt_cm_stop_conn(job->cm_conn_id);
        bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_DOWN, job->conn_id));
        bpp_notify('post', job->owner,
            EV_JOB_FINISH, MakeParam(E_LINK_BROKEN, job->conn_id));

        break;

    default:
        break;
    }

    return retval;
}

static S32 bpp_update_req_hdlr(bpp_srv_job_struct *job)
{
    job->conn_hd = bt_bpp_alloc_prt_handle((goep_bd_addr_struct *)&job->device.addr);
    job->cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_BASIC_PRINTING, &(job->device.addr), NULL);
    if (job->cm_conn_id < 0)
        return RESULT_FAIL;
    bpp_send_msg(MSG_OPEN, job);
    
    job->state = STATE_OPEN;
    job->op_code = OP_UPDATE;

    return RESULT_PENDING;
}

static S32 bpp_print_req_hdlr(bpp_srv_job_struct *job)
{
    U16 conflict;

    if (bpp_job_conflict(job->print_mode, &job->device, &job->info))
        conflict = 1;
    else
        conflict = 0;

    job->state = STATE_WAIT_START;
    bpp_notify('post', job->owner, 
        EV_JOB_START_REQ, MakeParam(conflict, job->id));
    job->op_code = OP_PRINT;

    return RESULT_PENDING;
}

static S32 bpp_open_succ_hdlr(bpp_srv_job_struct *job, U32 conn_id)
{
    S32 retval = RESULT_SUCC;

    job->conn_id = conn_id;
    srv_bt_cm_connect_ind(job->cm_conn_id);
    bpp_notify_all('post', EV_BEARER_INFO, MakeParam(BEARER_UP, job->conn_id));

    if (job->op_code == OP_UPDATE)
    {
        job->state = STATE_OPEN_ED;
        bpp_send_msg(MSG_GET_ATTR, job);
    }
    else
    {
        if (job->data.type == 'none')
        {
            job->state = STATE_WAIT_DATA;
            bpp_notify('post', job->owner, 
                EV_JOB_REQUEST, MakeParam(REQUEST_DATA, job->id));
        }
        else
        {
            job->state = STATE_OPEN_ED;
            bpp_send_msg(MSG_PRINT_DOC, job);
        }
    }

    return retval;    
}

static S32 bpp_open_fail_hdlr(bpp_srv_job_struct *job, U16 cause)
{
    S32 retval = RESULT_SUCC;

    job->state = STATE_CLOSE_ED;
    srv_bt_cm_stop_conn(job->cm_conn_id);
    bpp_notify_all('post', EV_BEARER_INFO, 
        MakeParam(BEARER_FAIL, job->conn_id));

    if (job->op_code == OP_UPDATE)
        bpp_notify('post', job->owner, EV_UPDATE_FAIL,
            MakeParam(cause, job->id));
    else
        bpp_notify('post', job->owner, EV_JOB_FINISH,
            MakeParam(cause, job->id));
    
    job->op_code = OP_NONE;

    return retval;    
}

static S32 bpp_update_hdlr(bpp_srv_job_struct *job, bt_bpp_prt_capability *capb)
{
    PrinterAttribute *attr = &job->device.attr;
    U32 i;

    job->device.valid = 1;

    memset(attr, 0, sizeof(*attr));

    attr->textPageHeight = capb->basictextpageheight;
    attr->textPageWidth = capb->basictextpagewidth;
    attr->maxCopies = capb->copies;
    attr->numberUp = (U8)capb->numberup;

    for (i = 0; i < sizeof(capb->doc_format); i++)
    {
        if (capb->doc_format[i])
            attr->docFormat |= (1 << i);
    }
    for (i = 0; i < sizeof(capb->imagetype); i++)
    {
        if (capb->imagetype[i])
            attr->imageType |= (1 << i);
    }
    for (i = 0; i < sizeof(capb->media_size); i++)
    {
        if (capb->media_size[i])
            attr->mediaSize |= ((U64)1 << i);
    }
    for (i = 0; i < sizeof(capb->media_type); i++)
    {
        if (capb->media_type[i])
            attr->mediaType |= ((U64)1 << i);
    }
    for (i = 0; i < sizeof(capb->sides); i++)
    {
        if (capb->sides[i])
            attr->sides |= (1 << i);
    }
    for (i = 0; i < sizeof(capb->orientation); i++)
    {
        if (capb->orientation[i])
            attr->orientation |= (1 << i);
    }
    for (i = 0; i < sizeof(capb->quality); i++)
    {
        if (capb->quality[i])
            attr->quality |= (1 << i);
    }

    return RESULT_SUCC;
}

static S32 bpp_notify(U32 action, bpp_srv_inst_struct *inst, U32 event, U32 param)
{
    bpp_event_struct evt;

    MMI_FRM_INIT_EVENT(&evt, BPP_EVENT_ID);

    evt.notify = event;
    evt.para = param;

    if (action == 'post')    
        mmi_frm_post_event((mmi_event_struct *)&evt, (mmi_proc_func)bpp_event_proc, inst);
    else
        mmi_frm_send_event((mmi_event_struct *)&evt, (mmi_proc_func)bpp_event_proc, inst);

    return RESULT_SUCC;
}

static S32 bpp_notify_all(U32 action, U32 event, U32 param)
{
    U32 i;
    
    for (i = 0; i < MAX_INSTANCES; i++) 
    {
        if (g_insts[i].handle)
            bpp_notify(action, &g_insts[i], event, param);
    }

    return RESULT_SUCC;
}

static void bpp_init_msg_hdlr(void)
{
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_OPEN_CNF,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);

    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_CLOSE_CNF,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_GET_ATTR_CNF,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_PRINT_DOC_CNF,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_DISC_IND,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_JOB_STATE_IND,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_PROGRESS_IND,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_BT_BPP_AUTH_IND,
        (PsIntFuncPtr)bpp_msg_hdlr,
        MMI_FALSE);
}

static void bpp_create_storage(void)
{
    S32 retval;
    WCHAR path[32];

    kal_wsprintf(path, "%c:\\@bpp\\", g_config.storage);
    
    retval = FS_CreateDir(path);
    if (retval == FS_NO_ERROR || retval == FS_FILE_EXISTS)
        FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
}

static void bpp_init_job_sum(void)
{
    WCHAR file[32];
    FS_HANDLE fh;
    S32 retval = 0;
    U32 i, pos, size, job_count = 0, del_count = 0;
    U8 buff[8];

    g_job_sum.job_count = 0;
    g_job_sum.del_count = 0;
    
    for (i = 0; i < g_config.maxJobs; i++)
        g_job_sum.table[i].id = 0;
    
    kal_wsprintf(file, "%c:\\@bpp\\%w", g_config.storage, g_config.jobFile);

    if (FS_GetAttributes(file) < 0)
        return;

    fh = FS_Open(file, FS_READ_ONLY);
    if (fh < 0)
        return;

    FS_Read(fh, buff, sizeof(buff), NULL);
    if (memcmp(buff, GuardPattern, sizeof(GuardPattern)) != 0)
    {
        FS_Close(fh);
        FS_Delete(file);
        return;
    }

    FS_GetFileSize(fh, &size);
    FS_GetFilePosition(fh, &pos);

    while (pos < size && job_count < g_config.maxJobs && retval >= 0) 
    {
        U32 read;
        bpp_job_save_struct info;
        
        retval = FS_Read(fh, &info, sizeof(info), &read);
        if (info.head.del_flag ||
            (ValidAddr(&info.device.addr) &&
            (!srv_bt_cm_dev_property_check(&info.device.addr, SRV_BT_CM_DEV_PROPERTY_PAIR) ||
            srv_bt_cm_dev_property_check(&info.device.addr, SRV_BT_CM_DEV_PROPERTY_BLOCK))))
        {
            del_count++;
        }
        else
        {
            g_job_sum.table[g_job_sum.job_count].id = info.head.id;
            g_job_sum.table[g_job_sum.job_count].pos = pos;
            job_count++;
        }            

        pos += sizeof(bpp_job_save_struct);
        retval = FS_Seek(fh, pos, FS_FILE_BEGIN);
    }

    FS_Close(fh);

    g_job_sum.job_count = job_count;
    g_job_sum.del_count = del_count;

    if (DefragCriterion(job_count, del_count))
        bpp_defrag();
}

static U32 bpp_job_conflict(U32 mode, bpp_dev_info_struct *dev, bpp_job_info_struct *opt_info)
{
    PrintOption *opt;
    PrinterAttribute *attr;
    
    /* For simple push or default job case, we don't need to get printer attributes */
    if (mode == PRINT_MODE_SIMPLE || opt_info->use_default)
        return 0;

    if (!dev->valid)
        return 1;

    opt = &opt_info->option;
    attr = &dev->attr;
    
    if (opt->copies <= attr->maxCopies &&
        opt->mediaSize & attr->mediaSize &&
        opt->mediaType & attr->mediaType &&
        opt->numberUp & attr->numberUp &&
        opt->orientation & attr->orientation &&
        opt->quality & attr->quality &&
        opt->sides & attr->sides)
        return 0;

    return 1;
}

static U32 bpp_get_compatible_options(PrintOption *opt, PrinterAttribute *attr)
{
    PrintOption option;

    option = DefaultPrintOptions;

    if (option.copies > attr->maxCopies)
        option.copies = attr->maxCopies;
    
    if (!(option.mediaSize & attr->mediaSize))
        option.mediaSize = (U64)1 << bit_offset(attr->mediaSize);
    
    if (!(option.mediaType & attr->mediaType))
        option.mediaType = (U64)1 << bit_offset(attr->mediaType);

    if (!(option.numberUp & attr->numberUp))
        option.numberUp = (U8)(1 << bit_offset(attr->numberUp));

    if (!(option.orientation & attr->orientation))
        option.orientation = (U8)(1 << bit_offset(attr->orientation));

    if (!(option.quality & attr->quality))
        option.quality = (U8)(1 << bit_offset(attr->quality));

    if (!(option.sides & attr->sides))
        option.sides = (U8)(1 << bit_offset(attr->sides));

    *opt = option;

    return RESULT_SUCC;
}

static U16 conv_cause(S32 ret)
{
    U16 cause;
    
    switch (ret) {
    case BPP_ADP_SUCCESS:

        cause = E_NONE;

        break;

    case BPP_ADP_ERROR_LINK_DISC:
        
        cause = E_LINK_BROKEN;
        
        break;
        
    case BPP_ADP_ERROR_PEER_ABORT:
    case BPP_ADP_ERROR_USER_ABORT:

        cause = E_REQ_CANCELLED;

        break;

    case BPP_ADP_ERROR_SCO_REJECT:

        cause = E_SCO_REJECT;

        break;
        
    case BPP_ADP_ERROR_INVALID_PARAM:

        cause = E_INVALID_PARA;

        break;

    default:
        cause = E_GENERAL;
        break;
    }

    return cause;        
}

static U32 alloc_new_job_id(void)
{
    U32 id = g_id_seed++;

    if (g_id_seed == 0)
        g_id_seed = g_config.maxJobs + 256;

    return id;
}

static U8 bit_offset(U64 value)
{
    U32 i;
    U64 t;

    if (!value)
        return 0;

    for (i = 0, t = 1; i < 64; i++)
    {
        t = (U64)1 << i;
        if (value & t)
            break;
    }

    return i;
}

static U32 alloc_job_id(void)
{
    U8 flag[MAX_JOBS] = {0};
    U32 i;

    for (i = 0; i < g_job_sum.job_count; i++) 
    {
        if (g_job_sum.table[i].id)
            flag[g_job_sum.table[i].id-1] = 1;
    }

    for (i = 0; i < g_config.maxJobs; i++) 
    {
        if (!flag[i])
            return i+1;
    }

    MMI_ASSERT(0);

    return 0;
}

static S32 in_list(bpp_list_struct *list, bpp_list_struct *node)
{
    bpp_list_struct *m;

    ForEachOfList(list, m)
    {
        if (m == node)
            return 1;
    }

    return 0;
}


#endif /* __MMI_BPP_SUPPORT__ */

