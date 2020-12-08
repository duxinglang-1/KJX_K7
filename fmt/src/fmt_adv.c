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
 *
 * Filename:
 * ---------
 * fmt_adv.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Pluto only FMT module
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
 *==============================================================================
 *******************************************************************************/
#define FMT_ADV_C

#if !defined(FMT_NOT_PRESENT) && defined(PLUTO_MMI)

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

/* MMI header */
#include "mmi_features.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"         /* Task message communiction */
#include "task_config.h"        /* Task creation */

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "fmt_def.h"
#include "fmt_struct.h"
#include "fmt_trc.h"

/****************************************************************************
* Macro
*****************************************************************************/

#define FMT_ADV_PRIORITY_INHERITANCE_ENABLE

/****************************************************************************
* Define
*****************************************************************************/

#define FMT_ADV_MAX_JOB_COUNT               20

#define FMT_TRACE0(trc, str)                kal_trace(TRACE_GROUP_1, trc)
#define FMT_TRACE1(trc, str, a1)            kal_trace(TRACE_GROUP_1, trc, a1)
#define FMT_TRACE2(trc, str, a1, a2)        kal_trace(TRACE_GROUP_1, trc, a1, a2)
#define FMT_TRACE3(trc, str, a1, a2, a3)    kal_trace(TRACE_GROUP_1, trc, a1, a2, a3)

#define FMT_ADV_MARK                        0xACE13579

#define FMT_ADV_JOB_STOPPED_EVENT           0x00000001

#define FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK   0x23456700

#define FMT_ADV_PROGRESS_PERIOD             1024

typedef struct 
{
    /* write by MMI task - begin */
    kal_uint32      seq_no;
    kal_bool        aborting, discarding;
    kal_bool        waiting;

    kal_uint32      seq_id_table[FMT_ADV_MAX_JOB_COUNT];
    kal_uint8       seq_state_table[FMT_ADV_MAX_JOB_COUNT];    /* see fmt_adv_seq_state_enum */
    /* write by MMI task - end */

    kal_uint32      task_index;    
    kal_eventgrpid  eventgrp;
    
    msg_type        working_message;
    kal_uint32      working_seq;
    void            *working_userdata;

    kal_uint32      cluster_size;
    kal_uint32      get_folder_size_last_time;

} fmt_adv_context_struct;

typedef void (*fmt_adv_req_hdlr)(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);

typedef struct
{
    msg_type            msg_id;
    fmt_adv_req_hdlr    handler;
} fmt_adv_msg_table_struct;

typedef void (*fmt_adv_msg_hdlr)(ilm_struct* ilm, const fmt_adv_msg_table_struct *msg_hdlr);

#ifdef __MMI_SLIM_FILE_MANAGER__
#ifndef __SLIM_FMT__
#define __SLIM_FMT__
#endif
#endif
/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/

static fmt_adv_context_struct g_fmt_adv_ctxt;

static void fmt_adv_load_folder_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);
static void fmt_adv_copy_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);
static void fmt_adv_delete_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);
static void fmt_adv_create_folder_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);
#if !defined(__SLIM_FMT__)
static void fmt_adv_get_folder_size_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort);
#endif
const static fmt_adv_msg_table_struct g_fmt_adv_msg_table_struct[] = {
    {MSG_ID_FMT_ADV_LOAD_FOLDER_REQ, fmt_adv_load_folder_req_hdlr},
    {MSG_ID_FMT_ADV_COPY_REQ, fmt_adv_copy_req_hdlr},
    {MSG_ID_FMT_ADV_DELETE_REQ, fmt_adv_delete_req_hdlr},
    {MSG_ID_FMT_ADV_CREATE_FOLDER_REQ, fmt_adv_create_folder_req_hdlr},
#if !defined(__SLIM_FMT__)
    {MSG_ID_FMT_ADV_GET_FOLDER_SIZE_REQ, fmt_adv_get_folder_size_req_hdlr},
#endif
    {MSG_ID_INVALID_TYPE, NULL}
};

#ifndef __MTK_TARGET__
static kal_int32 g_fmt_debug_progress_period = FMT_ADV_PROGRESS_PERIOD;
#endif

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

extern kal_uint32 kal_get_mytask_priority(void);

extern void fmt_move_ext_q_to_int_q(kal_msgqid task_ext_qid, kal_bool wait);
extern void fmt_clear_invalid_ilm_from_int_q(void);

static const fmt_adv_msg_table_struct* fmt_adv_find_handler(msg_type msg_id);

static kal_int32    fmt_adv_seqs_insert(kal_uint32 seq);
static kal_int32    fmt_adv_seqs_find(kal_uint32 seq);
static void         fmt_adv_seqs_remove_by_idx(kal_int32 idx);
static kal_uint8    fmt_adv_seqs_get_state_by_idx(kal_int32 idx);
static void         fmt_adv_seqs_set_state_by_idx(kal_int32 idx, kal_uint8 state);

static void fmt_adv_load_folder_send_progress_ind(UINT handle, kal_uint32 user_data, 
                                                  kal_int32 total, kal_int32 complete, 
                                                  kal_int32 cache_start, kal_int32 cache_count);

#define END_OF_FUNCTION_DECLARATION

/****************************************************************************
* Function Body
*****************************************************************************/

void fmt_adv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_set(&g_fmt_adv_ctxt, 0, sizeof(g_fmt_adv_ctxt));
    g_fmt_adv_ctxt.eventgrp = kal_create_event_group("fmt_adv_events");
    
    kal_get_my_task_index(&g_fmt_adv_ctxt.task_index);
}

kal_bool fmt_adv_is_ilm_valid(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_base_struct             *msg = NULL;
    kal_int32                       seq_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently, to check msg load folder only */
    if (ilm_ptr->msg_id == MSG_ID_FMT_ADV_LOAD_FOLDER_REQ)
    {
        msg = (fmt_adv_base_struct*)ilm_ptr->local_para_ptr;
        if(!msg)
            return KAL_FALSE;

        if(msg->adv_mark != FMT_ADV_MARK)
            return KAL_FALSE;

        seq_idx = fmt_adv_seqs_find(msg->req_seq);
        ASSERT(seq_idx >= 0);

        switch(fmt_adv_seqs_get_state_by_idx(seq_idx))
        {
        case FMT_SEQ_ABORTING:
        case FMT_SEQ_DISCARDING:
            return KAL_FALSE;
        default:
            return KAL_TRUE;
        }
    }

    return KAL_TRUE;
}

kal_bool fmt_adv_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const fmt_adv_msg_table_struct  *msg_hdlr;
    fmt_adv_base_struct             *msg;
#if defined(__MTK_TARGET__) && defined(FMT_ADV_PRIORITY_INHERITANCE_ENABLE)
    kal_uint32                      fmt_priority;
#endif
    kal_int32                       seq_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_hdlr = fmt_adv_find_handler(ilm_ptr->msg_id);
    if(!msg_hdlr)
        return KAL_FALSE;

    msg = (fmt_adv_base_struct*)ilm_ptr->local_para_ptr;
    if(!msg)
        return KAL_FALSE;

    if(msg->adv_mark != FMT_ADV_MARK)
        return KAL_FALSE;

    FMT_TRACE2(TRC_FMT_D3DAC2AAEA544607B27696508467F3CE, "[FMTADV] fmt_adv_handler(%d,%d) begin",
        ilm_ptr->msg_id, msg->req_seq);

    seq_idx = fmt_adv_seqs_find(msg->req_seq);
    ASSERT(seq_idx >= 0);

    ASSERT(!g_fmt_adv_ctxt.working_message && !g_fmt_adv_ctxt.working_seq);
    g_fmt_adv_ctxt.working_message = ilm_ptr->msg_id;
    g_fmt_adv_ctxt.working_seq = msg->req_seq;
    g_fmt_adv_ctxt.working_userdata = ilm_ptr->local_para_ptr;
    
    switch(fmt_adv_seqs_get_state_by_idx(seq_idx))
    {
    case FMT_SEQ_ABORTING:
        msg_hdlr->handler(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr, KAL_TRUE);
        /* no break */

    case FMT_SEQ_DISCARDING:
        fmt_adv_seqs_remove_by_idx(seq_idx);

        g_fmt_adv_ctxt.working_message = MSG_ID_INVALID_TYPE;
        g_fmt_adv_ctxt.working_seq = 0;
        g_fmt_adv_ctxt.working_userdata = NULL;
        if(g_fmt_adv_ctxt.waiting)
            kal_set_eg_events(g_fmt_adv_ctxt.eventgrp, FMT_ADV_JOB_STOPPED_EVENT, KAL_OR);
        FMT_TRACE0(TRC_FMT_5C50AB03DD784424A2F7372F635A7986, "[FMTADV] fmt_adv_handler end");
        return KAL_TRUE;
    }

    fmt_adv_seqs_set_state_by_idx(seq_idx, FMT_SEQ_ONGOING);
    
#if defined(__MTK_TARGET__) && defined(FMT_ADV_PRIORITY_INHERITANCE_ENABLE)
    fmt_priority = kal_get_mytask_priority();
#endif

    msg_hdlr->handler(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr, KAL_FALSE);

    g_fmt_adv_ctxt.aborting = KAL_FALSE;
    g_fmt_adv_ctxt.working_message = MSG_ID_INVALID_TYPE;
    g_fmt_adv_ctxt.working_seq = 0;
    g_fmt_adv_ctxt.working_userdata = NULL;
    g_fmt_adv_ctxt.discarding = KAL_FALSE;

    fmt_adv_seqs_remove_by_idx(seq_idx);

    if(g_fmt_adv_ctxt.waiting)
        kal_set_eg_events(g_fmt_adv_ctxt.eventgrp, FMT_ADV_JOB_STOPPED_EVENT, KAL_OR);

#if defined(__MTK_TARGET__) && defined(FMT_ADV_PRIORITY_INHERITANCE_ENABLE)
    if(fmt_priority != kal_get_mytask_priority())
        stack_change_priority_by_module_ID(MOD_FMT, fmt_priority);
#endif

    FMT_TRACE0(TRC_FMT_5C50AB03DD784424A2F7372F635A7986, "[FMTADV] fmt_adv_handler end");
    return KAL_TRUE;
}

/* called by MMI task */
kal_uint32 fmt_adv_send_message(msg_type msg_id, local_para_struct* local_para, peer_buff_struct* peer_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct  *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(MOD_MMI == stack_get_active_module_id());

    if(!fmt_adv_find_handler(msg_id))
    {
        FMT_TRACE2(TRC_FMT_254896BC13EF44B2AF3CE94ADC2E45F1, "[FMTADV] fmt_adv_send_message(%d)=%d",
            msg_id, 0);
        return 0;
    }

    if (msg_id == MSG_ID_FMT_ADV_LOAD_FOLDER_REQ)
    {
        /* Remove aborting msg from external queue in order to avoid queue full */
        fmt_move_ext_q_to_int_q(task_info_g[INDX_FMT].task_ext_qid, KAL_FALSE);
        fmt_clear_invalid_ilm_from_int_q();
    }
    
    /* assign an unique seq */
    g_fmt_adv_ctxt.seq_no++;
    if(g_fmt_adv_ctxt.seq_no > FMT_ADV_JOB_MAX)
        g_fmt_adv_ctxt.seq_no = 1;
    if(!g_fmt_adv_ctxt.seq_no)
        g_fmt_adv_ctxt.seq_no++;

    fmt_adv_seqs_insert(g_fmt_adv_ctxt.seq_no);
    
    ((fmt_adv_base_struct*)local_para)->req_seq = g_fmt_adv_ctxt.seq_no;
    ((fmt_adv_base_struct*)local_para)->adv_mark = FMT_ADV_MARK;

    ilm_ptr = allocate_ilm(MOD_MMI);

    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = local_para;
    ilm_ptr->peer_buff_ptr = peer_buff;

    SEND_ILM(MOD_MMI, MOD_FMT, MMI_FMT_SAP, ilm_ptr);

    FMT_TRACE2(TRC_FMT_254896BC13EF44B2AF3CE94ADC2E45F1, "[FMTADV] fmt_adv_send_message(%d)=%d",
        msg_id, g_fmt_adv_ctxt.seq_no);
    return g_fmt_adv_ctxt.seq_no;
}

/* called by MMI task */
kal_bool fmt_adv_abort_message(kal_uint32 msg_seq, kal_bool wait, kal_bool cancel_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__) && defined(FMT_ADV_PRIORITY_INHERITANCE_ENABLE)
    kal_uint32 mmi_priority;
#endif
    kal_uint32 retrieve_event;
    kal_int32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(MOD_MMI == stack_get_active_module_id());
    
    idx = fmt_adv_seqs_find(msg_seq);
    if(idx < 0)
    {
        FMT_TRACE2(TRC_FMT_5EC7DB53773C44E0BC12D8CBC52C02BD, "[FMTADV] fmt_adv_abort_message(%d)=%d",
            msg_seq, 0);
        return KAL_FALSE;
    }
    
    if(cancel_rsp)
        fmt_adv_seqs_set_state_by_idx(idx, FMT_SEQ_DISCARDING);
    else
        fmt_adv_seqs_set_state_by_idx(idx, FMT_SEQ_ABORTING);
    
    if(g_fmt_adv_ctxt.working_seq && g_fmt_adv_ctxt.working_seq == msg_seq)
    {
        g_fmt_adv_ctxt.aborting = KAL_TRUE;
        if(cancel_rsp)
            g_fmt_adv_ctxt.discarding = KAL_TRUE;

        if(wait)
        {
            g_fmt_adv_ctxt.waiting = KAL_TRUE;
#if defined(__MTK_TARGET__) && defined(FMT_ADV_PRIORITY_INHERITANCE_ENABLE)
            mmi_priority = kal_get_mytask_priority();
            stack_change_priority_by_module_ID(MOD_FMT, mmi_priority);
#endif
            kal_retrieve_eg_events(g_fmt_adv_ctxt.eventgrp, FMT_ADV_JOB_STOPPED_EVENT, 
                                   KAL_OR_CONSUME, &retrieve_event, KAL_SUSPEND);
            g_fmt_adv_ctxt.waiting = KAL_FALSE;
        }
    }
    
    FMT_TRACE2(TRC_FMT_5EC7DB53773C44E0BC12D8CBC52C02BD, "[FMTADV] fmt_adv_abort_message(%d)=%d",
        msg_seq, 1);
    return KAL_TRUE;
}

fmt_adv_seq_state_enum fmt_adv_get_message_state(kal_uint32 msg_seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.working_seq && g_fmt_adv_ctxt.working_seq == msg_seq)
    {
        if(g_fmt_adv_ctxt.aborting)
            return FMT_SEQ_ABORTING;
        else
            return FMT_SEQ_ONGOING;
    }

    idx = fmt_adv_seqs_find(msg_seq);
    if(idx < 0)
        return FMT_SEQ_NOT_EXIST;

    return (fmt_adv_seq_state_enum)fmt_adv_seqs_get_state_by_idx(idx);

}

kal_int32 fmt_adv_load_folder_check_changed(const WCHAR* folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_int32 fs_ret;
    UINT cache_mark;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(MOD_MMI == stack_get_active_module_id());

    do {
        fh = FS_Open(folderpath, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh < 0)
        {
            fs_ret = fh;
            break;
        }

        fs_ret = FS_GetDirCache(fh, &cache_mark);
        ASSERT(fs_ret < 0 || cache_mark > FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK);

        FS_Close(fh);
        
    } while(0);

    return fs_ret;
}

void fmt_adv_load_folder_check_release(const WCHAR* folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_int32 fs_ret;
    UINT cache_mark;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(MOD_MMI == stack_get_active_module_id());

    do {
        fh = FS_Open(folderpath, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh < 0)
        {
            fs_ret = fh;
            break;
        }

        fs_ret = FS_GetDirCache(fh, &cache_mark);
        if(fs_ret < 0)
        {
            FS_Close(fh);
            break;
        }

        ASSERT(cache_mark > FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK);

        cache_mark--;

        if(cache_mark == FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK)
        {
            FS_ExpireDirCache(fh);
        }
        else
        {
            FS_SetDirCache(fh, cache_mark);
        }

        FS_Close(fh);
    } while(0);

}

kal_bool fmt_adv_int_queue_abort_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const fmt_adv_msg_table_struct  *msg_hdlr;
    fmt_adv_base_struct             *msg = NULL;
    kal_int32                       seq_idx;
    kal_bool                        result  = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        msg_hdlr = fmt_adv_find_handler(ilm_ptr->msg_id);
        if(!msg_hdlr)
            break;

        msg = (fmt_adv_base_struct*)ilm_ptr->local_para_ptr;
        if(!msg)
            break;

        if(msg->adv_mark != FMT_ADV_MARK)
            break;

        seq_idx = fmt_adv_seqs_find(msg->req_seq);
        ASSERT(seq_idx >= 0);

        switch(fmt_adv_seqs_get_state_by_idx(seq_idx))
        {
        case FMT_SEQ_ABORTING:
            msg_hdlr->handler(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr, KAL_TRUE);
            /* no break */

        case FMT_SEQ_DISCARDING:
            fmt_adv_seqs_remove_by_idx(seq_idx);
            result = KAL_TRUE;
            break;
        }
    } while(0);

    FMT_TRACE2(TRC_FMT_88b6dcc1f31146ad81e4fd86d77b0e25, "[FMT] fmt_int_queue_abort_hdlr (%d,%d)", (msg != NULL)? msg->req_seq : 0, result);
    return result;
}

#define LOCAL_FUNCTION

static const fmt_adv_msg_table_struct* fmt_adv_find_handler(msg_type msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const fmt_adv_msg_table_struct    *msg_hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    msg_hdlr = g_fmt_adv_msg_table_struct;
    while(msg_hdlr->msg_id)
    {
        if(msg_hdlr->msg_id == msg_id)
        {
            return msg_hdlr;
        }
        msg_hdlr++;
    }

    return NULL;
}

static kal_int32 fmt_adv_seqs_insert(kal_uint32 seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0;i<FMT_ADV_MAX_JOB_COUNT;i++)
    {
        if(!g_fmt_adv_ctxt.seq_id_table[i])
        {
            g_fmt_adv_ctxt.seq_id_table[i] = seq;
            g_fmt_adv_ctxt.seq_state_table[i] = FMT_SEQ_IN_QUEUE;
            break;
        }
    }
    ASSERT(i != FMT_ADV_MAX_JOB_COUNT);

    return i;    
}

static kal_int32 fmt_adv_seqs_find(kal_uint32 seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!seq)
        return -1;

    for(i=0;i<FMT_ADV_MAX_JOB_COUNT;i++)
    {
        if(g_fmt_adv_ctxt.seq_id_table[i] == seq)
        {
            return i;
        }
    }

    return -1;
}

static void fmt_adv_seqs_remove_by_idx(kal_int32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(idx >= 0 && idx < FMT_ADV_MAX_JOB_COUNT)
        g_fmt_adv_ctxt.seq_id_table[idx] = 0;
}

static kal_uint8 fmt_adv_seqs_get_state_by_idx(kal_int32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(idx >= 0 && idx < FMT_ADV_MAX_JOB_COUNT && g_fmt_adv_ctxt.seq_id_table[idx])
        return g_fmt_adv_ctxt.seq_state_table[idx];
    
    return FMT_SEQ_NOT_EXIST;
}

static void fmt_adv_seqs_set_state_by_idx(kal_int32 idx, kal_uint8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(idx >= 0 && idx < FMT_ADV_MAX_JOB_COUNT && g_fmt_adv_ctxt.seq_id_table[idx])
        g_fmt_adv_ctxt.seq_state_table[idx] = state;
}

#define FMT_COPY

static kal_int32 fmt_adv_copy_check_free_size(WCHAR dest_drive, const WCHAR* src_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 free_space;
    kal_uint32 file_size;
    kal_int32 fs_ret;
    FS_HANDLE fh;
    WCHAR drv_path[4];
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    free_space = file_size = 0;
    fh = FS_Open(src_path, FS_READ_ONLY);
    if(fh >= 0)
    {
        if(FS_GetFileSize(fh, &file_size) < 0)
            file_size = 0;
        FS_Close(fh);
    }

    if(file_size)
    {
        drv_path[0] = dest_drive;
        drv_path[1] = ':';
        drv_path[2] = '\\';
        drv_path[3] = 0;
        
        fs_ret = FS_GetDiskInfo(drv_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if(fs_ret >= 0)
        {
            free_space = (kal_uint64)disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        }
        else
        {
            free_space = 0;
            file_size = 0;  // skip checking, if cannot get disk_info
        }
    }
    
    fs_ret = 0;
    if(file_size && free_space < file_size)
        fs_ret = FS_DISK_FULL;

    FMT_TRACE2(TRC_FMT_2894D24781DC4CAF86932F07F30D28CF, "[FMTADV] check free space(%d)=%d",
        dest_drive, fs_ret);
    return fs_ret;
}

static int fmt_adv_copy_progress_cb(int action, UINT total, UINT completed, UINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMT_TRACE3(TRC_FMT_A8BA85D7D2634106B1423B04809D473D, "[FMTADV] copy progress(%d/%d,abort=%d)",
        completed, total, g_fmt_adv_ctxt.aborting);

    if (action == FS_MOVE_PGS_FAIL)
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
#endif
    }
    else if (g_fmt_adv_ctxt.aborting)
    {
        if (handle > 0)
            FS_Abort(handle);
        return -1;
    }    
    else
    {
        /* send message to MMI to show progress */
    }

    fmt_move_ext_q_to_int_q(task_info_g[INDX_FMT].task_ext_qid, KAL_FALSE);
    fmt_clear_invalid_ilm_from_int_q();

    return KAL_TRUE;

}

static void fmt_adv_copy_send_rsp(const fmt_adv_copy_req_struct *params, kal_int32 fs_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_copy_rsp_struct *rsp_ptr;
    peer_buff_struct        *peer_buff_ptr;
    ilm_struct              *ilm_ptr;
    kal_int32               path_len;
    kal_uint16              len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }

    FMT_TRACE1(TRC_FMT_7C6569D5E9624BED838C94C7750D64F1, "[FMTADV] fmt_adv_copy_send_rsp(%d)", fs_ret);
    
    path_len = kal_wstrlen(params->src_path);
    ASSERT(path_len < 260);
    peer_buff_ptr = construct_peer_buff((kal_uint16)((path_len+1)*2), 0, 0, TD_RESET);

    rsp_ptr = (fmt_adv_copy_rsp_struct*) construct_local_para(sizeof(fmt_adv_copy_rsp_struct), TD_CTRL | TD_RESET);
    rsp_ptr->req_seq = params->req_seq;
    rsp_ptr->user_data = params->user_data;

    rsp_ptr->result = fs_ret;
    rsp_ptr->flag = params->flag;
    rsp_ptr->callback_ptr = params->callback_ptr;
    rsp_ptr->src_path = (WCHAR*)get_pdu_ptr(peer_buff_ptr, &len);
    kal_wstrncpy(rsp_ptr->src_path, params->src_path, path_len);
    kal_wstrcpy(rsp_ptr->dest_path, params->dest_path);

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_COPY_RSP;
    ilm_ptr->peer_buff_ptr = peer_buff_ptr;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);

}

static void fmt_adv_copy_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_copy_req_struct *params = (fmt_adv_copy_req_struct*)local_para_ptr;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(abort)
    {
        fmt_adv_copy_send_rsp(params, FS_ABORTED_ERROR);
        return;
    }

    FMT_TRACE0(TRC_FMT_88844AC613784F20B073776FD61CD9CD, "[FMTADV] fmt_adv_copy_req_hdlr begin");
    
    do {
        /* free space checking if copy or move to different storage */
        if(params->flag == FS_MOVE_COPY || 
            params->src_path[0] != params->dest_path[0])
        {
            fs_ret = fmt_adv_copy_check_free_size(params->dest_path[0], params->src_path);
            if(fs_ret < 0)
                break;
        }
        
        if(g_fmt_adv_ctxt.aborting)
        {
            fs_ret = FS_ABORTED_ERROR;
            break;
        }

        FMT_TRACE0(TRC_FMT_6677863FC752448BABCA4DD40B7A8D65, "[FMTADV] FS_Move begin");

        fs_ret = FS_Move( params->src_path, 
                          params->dest_path, 
                          params->flag, 
                          fmt_adv_copy_progress_cb, 
                          (BYTE *)params->buffer, 
                          params->buffer_size);

        FMT_TRACE1(TRC_FMT_DF0A1F65A13B4B31B265B0EF1F2A4465, "[FMTADV] FS_Move end=%d", fs_ret);

    } while(0);


    fmt_adv_copy_send_rsp(params, fs_ret);
    
}

#define FMT_DELETE

static kal_int32 fmt_adv_delete_by_filter(const WCHAR* path, FS_Pattern_Struct* patterns, kal_uint16 pattern_count)
{
#ifndef __SLIM_FMT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry  fs_entry;
    WCHAR           filename[255+1];
    WCHAR           *find_path;
    FS_HANDLE       fh;
    kal_int32       fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        
        find_path = (WCHAR*)get_ctrl_buffer((kal_wstrlen((kal_wchar*)path) + 5)*2);

        kal_wstrcpy(find_path, path);
        kal_wstrcat(find_path, (WCHAR*)L"*.*");

        fh = FS_FindFirstN(find_path, 
                           patterns,
                           pattern_count,
                           0,
                           0, 
                           FS_ATTR_DIR | FS_ATTR_SYSTEM | FS_ATTR_VOLUME, 
                           &fs_entry,
                           filename, sizeof(filename),
                           0, FS_FIND_DEFAULT);

        free_ctrl_buffer(find_path);
        find_path = NULL;

        if(fh < 0)
        {
            fs_ret = fh;
            break;
        }

        fs_ret = FS_SetCurrentDir(path);
        if (fs_ret < 0)
            break;

        do {
            if(g_fmt_adv_ctxt.aborting)
            {
                fs_ret = FS_ABORTED_ERROR;
                break;
            }
            
            fs_ret = FS_Delete(filename);
            if(fs_ret < 0)
                break;
            
            fs_ret = FS_FindNextN(fh, patterns, pattern_count,
                                  0,
                                  &fs_entry,
                                  filename, sizeof(filename),
                                  FS_FIND_DEFAULT);
        } while(fs_ret >= 0);

        if(fs_ret == FS_NO_MORE_FILES)
            fs_ret = 0;

    } while(0);

    if(fh > 0)
        FS_FindClose(fh);

    /* reset to root */
    kal_wstrncpy(filename, path, 3);
    FS_SetCurrentDir(filename);

    return fs_ret;
#else
	return FS_PARAM_ERROR;
#endif
}

static int fmt_adv_delete_progress_cb(int action, UINT total, UINT completed, UINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMT_TRACE3(TRC_FMT_95BB547B36F743239201F16D34AA2C7B, "[FMTADV] delete progress(%d/%d,abort=%d)",
        completed, total, g_fmt_adv_ctxt.aborting);

    if (action == FS_MOVE_PGS_FAIL)
    {
        
    }
    else if (g_fmt_adv_ctxt.aborting)
    {
        return -1;
    }    
    else
    {
        /* send message to MMI to show progress */
    }

    fmt_move_ext_q_to_int_q(task_info_g[INDX_FMT].task_ext_qid, KAL_FALSE);
    fmt_clear_invalid_ilm_from_int_q();


    return KAL_TRUE;

}

static void fmt_adv_delete_send_rsp(const fmt_adv_delete_req_struct *params, kal_int32 fs_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_delete_rsp_struct *rsp_ptr;
    ilm_struct              *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }

    FMT_TRACE1(TRC_FMT_9D76264667B1438CA9552D8D318448B9, "[FMTADV] fmt_adv_delete_send_rsp(%d)", fs_ret);
    
    rsp_ptr = (fmt_adv_delete_rsp_struct*) construct_local_para(sizeof(fmt_adv_delete_rsp_struct), TD_CTRL | TD_RESET);
    rsp_ptr->req_seq = params->req_seq;
    rsp_ptr->user_data = params->user_data;

    rsp_ptr->result = fs_ret;
    rsp_ptr->flag = params->flag;
    rsp_ptr->callback_ptr = params->callback_ptr;
    kal_wstrcpy(rsp_ptr->path, params->path);

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_DELETE_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);
}

static void fmt_adv_delete_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_delete_req_struct *params = (fmt_adv_delete_req_struct*)local_para_ptr;
    kal_int32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(abort)
    {
        fmt_adv_delete_send_rsp(params, FS_ABORTED_ERROR);
        return;
    }

    FMT_TRACE1(TRC_FMT_3601B08749FE461DA251EA1C23702F9B, "[FMTADV] fmt_adv_delete_req_hdlr(%d)",
        params->flag);

    switch(params->flag)
    {
    case FMT_DELETE_SINGLE:
        fs_ret = FS_Delete(params->path);
        break;

    case FMT_DELETE_FOLDER:
        fs_ret = FS_XDeleteEx(params->path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
                            fmt_adv_delete_progress_cb,
                            params->buffer, params->buffer_size);
        break;

    case FMT_DELETE_ALL:
        fs_ret = FS_XDeleteEx(params->path, FS_FILE_TYPE, 
                            fmt_adv_delete_progress_cb,
                            NULL, 0);
        break;

    case FMT_DELETE_ALL_BY_FILTER:
        fs_ret = fmt_adv_delete_by_filter(params->path, params->filter_array, params->filter_count);
        break;

    default:
        fs_ret = FS_PARAM_ERROR;
        break;
    }

    fmt_adv_delete_send_rsp(params, fs_ret);
    
}

#define FMT_CREATE_FOLDER

static void fmt_adv_create_folder_send_rsp(const fmt_adv_create_folder_req_struct *params, kal_int32 fs_ret)
{

//#if (!defined(__SLIM_FMT__) || defined(__COSMOS_MMI_PACKAGE__)) 


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_create_folder_rsp_struct *rsp_ptr;
    ilm_struct              *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }

    //FMT_TRACE1(TRC_FMT_9D76264667B1438CA9552D8D318448B9, "[FMTADV] fmt_adv_delete_send_rsp(%d)", fs_ret);
    
    rsp_ptr = (fmt_adv_create_folder_rsp_struct*) construct_local_para(sizeof(fmt_adv_create_folder_rsp_struct), TD_CTRL | TD_RESET);
    rsp_ptr->req_seq = params->req_seq;
    rsp_ptr->user_data = params->user_data;
    rsp_ptr->callback_ptr = params->callback_ptr;

    rsp_ptr->result = fs_ret;
    kal_wstrcpy(rsp_ptr->path, params->path);

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_CREATE_FOLDER_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);
//#endif
}

static void fmt_adv_create_folder_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort)
{
//#if (!defined(__SLIM_FMT__) || defined(__COSMOS_MMI_PACKAGE__)) 


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_create_folder_req_struct *params = (fmt_adv_create_folder_req_struct*)local_para_ptr;
    kal_int32 fs_ret;
    kal_int32 len, i;
    WCHAR *buf_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(abort)
    {
        fmt_adv_create_folder_send_rsp(params, FS_ABORTED_ERROR);
        return;
    }

    do {
        len = kal_wstrlen(params->path);

        if(len <= 3)
            fs_ret = FS_GetDevType(params->path);
        else
            fs_ret = FS_GetAttributes(params->path);

        if(fs_ret >= 0)
        {
            // path already exists
            fs_ret = 0;
            break;
        }

        /* create directory if it is not there */
        buf_path = get_ctrl_buffer((len + 1) * 2);

        /* skip drive. "C:\" */
        for (i = 3; i < len; i ++)
        {
            if (params->path[i] != '\\' && params->path[i] != 0)
                continue;

            /* create dir */
            kal_wstrncpy(buf_path, params->path, i);
            buf_path[i] = 0;

            if(FS_GetAttributes(buf_path) >= 0)
                continue;

            fs_ret = FS_CreateDir(buf_path);
            
            if(fs_ret == FS_FILE_EXISTS)
                fs_ret = 0;
            if(fs_ret < 0)
                break;
        }

        free_ctrl_buffer(buf_path);
        
    } while(0);

    fmt_adv_create_folder_send_rsp(params, fs_ret);
//#endif
}

#define FMT_FOLDER_SIZE

#if !defined(__SLIM_FMT__)
static void fmt_adv_get_folder_size_send_rsp(const fmt_adv_get_folder_size_req_struct *params, kal_int32 fs_ret, kal_uint64 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_rsp_struct *rsp_ptr;
    ilm_struct              *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }

    //FMT_TRACE1(TRC_FMT_9D76264667B1438CA9552D8D318448B9, "[FMTADV] fmt_adv_delete_send_rsp(%d)", fs_ret);
    
    rsp_ptr = (fmt_adv_get_folder_size_rsp_struct*) construct_local_para(sizeof(fmt_adv_get_folder_size_rsp_struct), TD_CTRL | TD_RESET);
    rsp_ptr->req_seq = params->req_seq;
    rsp_ptr->user_data = params->user_data;
    rsp_ptr->callback_ptr = params->callback_ptr;

    rsp_ptr->result = fs_ret;
    kal_wstrcpy(rsp_ptr->path, params->path);
    rsp_ptr->size = size;

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_GET_FOLDER_SIZE_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);
}

static void fmt_adv_get_folder_size_send_ind(const fmt_adv_get_folder_size_req_struct *params, kal_uint64 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_ind_struct *ind_ptr;
    ilm_struct              *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }

    //FMT_TRACE1(TRC_FMT_9D76264667B1438CA9552D8D318448B9, "[FMTADV] fmt_adv_delete_send_rsp(%d)", fs_ret);
    
    ind_ptr = (fmt_adv_get_folder_size_ind_struct*) construct_local_para(sizeof(fmt_adv_get_folder_size_ind_struct), TD_CTRL | TD_RESET);
    ind_ptr->req_seq = params->req_seq;
    ind_ptr->user_data = params->user_data;
    ind_ptr->callback_ptr = params->callback_ptr;

    kal_wstrcpy(ind_ptr->path, params->path);
    ind_ptr->size = size;

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_GET_FOLDER_SIZE_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);
}


static int fmt_adv_get_folder_size_progress_cb(int action, UINT total, UINT completed, UINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    FMT_TRACE3(TRC_FMT_95BB547B36F743239201F16D34AA2C7B, "[FMTADV] delete progress(%d/%d,abort=%d)",
//        completed, total, g_fmt_adv_ctxt.aborting);

    if (action == FS_PGS_FAIL)
    {
        
    }
    else if (g_fmt_adv_ctxt.aborting)
    {
        return -1;
    }    
    else
    {
        /* send message to MMI to show progress */
        kal_uint32 cur_time;
        kal_get_time(&cur_time);

        if(cur_time - g_fmt_adv_ctxt.get_folder_size_last_time > KAL_TICKS_500_MSEC)
        {
            kal_uint64 s = (kal_uint64)g_fmt_adv_ctxt.cluster_size * completed;
            fmt_adv_get_folder_size_send_ind(g_fmt_adv_ctxt.working_userdata, s);

            g_fmt_adv_ctxt.get_folder_size_last_time = cur_time;
        }
    }

    fmt_move_ext_q_to_int_q(task_info_g[INDX_FMT].task_ext_qid, KAL_FALSE);
    fmt_clear_invalid_ilm_from_int_q();


    return KAL_TRUE;

}

static void fmt_adv_get_folder_size_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_get_folder_size_req_struct *params = (fmt_adv_get_folder_size_req_struct*)local_para_ptr;
    kal_int32 fs_ret, cluster_size;
    kal_uint64 total_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(abort)
    {
        fmt_adv_get_folder_size_send_rsp(params, FS_ABORTED_ERROR, 0);
        return;
    }

    do {
        total_size = 0;

        fs_ret = FS_GetClusterSize(params->path[0]);
        if(fs_ret < 0)
            break;
        cluster_size = fs_ret;
        g_fmt_adv_ctxt.cluster_size = (kal_uint32)cluster_size;
        
        kal_get_time(&g_fmt_adv_ctxt.get_folder_size_last_time);

        fs_ret = FS_GetFolderSizeEx(params->path, FS_COUNT_IN_CLUSTER, NULL, 0, fmt_adv_get_folder_size_progress_cb);
        if(fs_ret < 0)
            break;

        // map from cluster to size
        total_size = (kal_uint64)fs_ret * cluster_size;

    } while(0);

    fmt_adv_get_folder_size_send_rsp(params, fs_ret, total_size);

}
#endif
#define FMT_LOAD_FOLDER

#if defined(__FS_SORT_SUPPORT__)
typedef enum {
    FMT_ADV_SORT_STATE_INIT,
    FMT_ADV_SORT_STATE_PROGRESSING,
    FMT_ADV_SORT_STATE_DONE
} fmt_adv_sort_state_enum;

typedef struct 
{
    fmt_adv_load_folder_req_struct  *params;
    FS_SortingParam                 *sort_para;
    
    fmt_adv_sort_state_enum         state;
    kal_int32                       total_count;
    kal_int32                       progress_count;
    kal_int32                       prev_progress_count;

    kal_uint32                      last_time;
} fmt_adv_sort_context_struct;

static int fmt_adv_sort_progress_callback(
                FS_SORT_PGS_ENUM Status,
                int Total, 
                UINT Completed, 
                void *CallbackParam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_sort_context_struct *ctxt = (fmt_adv_sort_context_struct*)CallbackParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_fmt_adv_ctxt.aborting)
        return -1;

    switch(Status)
    {
    case FS_SORT_PGS_PREPARE:
        break;
        
    case FS_SORT_PGS_START:
        ASSERT(ctxt->state == FMT_ADV_SORT_STATE_INIT);
        ctxt->state = FMT_ADV_SORT_STATE_PROGRESSING;

        ctxt->total_count = Total;
        ctxt->progress_count = 0;
        ctxt->prev_progress_count = 0;
        kal_get_time(&ctxt->last_time);

        fmt_adv_load_folder_send_progress_ind(*(ctxt->sort_para->Position), 
            ctxt->params->user_data, ctxt->total_count, ctxt->progress_count,
            0, 0);
        break;

    case FS_SORT_PGS_ING:
    case FS_SORT_PGS_DONE:
        if(ctxt->state == FMT_ADV_SORT_STATE_INIT)
        {
            ctxt->state = FMT_ADV_SORT_STATE_PROGRESSING;
            ctxt->total_count = Total;
            ctxt->progress_count = 0;
            ctxt->prev_progress_count = 0;
            kal_get_time(&ctxt->last_time);
            fmt_adv_load_folder_send_progress_ind(*(ctxt->sort_para->Position), 
                ctxt->params->user_data, ctxt->total_count, ctxt->progress_count,
                0, 0);
            break;
        }

        ASSERT(ctxt->total_count == Total);
        ctxt->progress_count = Completed;

        if(ctxt->state == FMT_ADV_SORT_STATE_PROGRESSING && (ctxt->params->Flag & 0x80000000))
        {
            kal_uint32 cur_time;
            kal_get_time(&cur_time);

            if(cur_time - ctxt->last_time > KAL_TICKS_500_MSEC)
            {
                fmt_adv_load_folder_send_progress_ind(*(ctxt->sort_para->Position),
                    ctxt->params->user_data, ctxt->total_count, ctxt->progress_count,
                    0, 0);
                ctxt->prev_progress_count = ctxt->progress_count;
                ctxt->last_time = cur_time;
            }
        }

        break;
    }
    return 0;
}

static kal_int32 fmt_adv_load_folder_sort_hdlr(fmt_adv_load_folder_req_struct *params, kal_int32* found_index_p, kal_int32* folder_count_p, UINT* sort_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_SortingParam                 para;
    kal_int32                       fs_ret, i, index, folder_count;
    UINT                            sort_handle;
    fmt_adv_sort_context_struct     sort_userdata;

    FS_DOSDirEntry                  fs_entry;
    WCHAR                           *filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMT_TRACE0(TRC_FMT_CDDA02DF298943ADA9DD8335F64E0472, "[FMTADV] fmt_adv_load_folder_sort_hdlr");

    ASSERT(found_index_p && sort_handle_p);
    
    index = -1;
    folder_count = -1;
    do {
        kal_mem_set(&sort_userdata, 0, sizeof(sort_userdata));
        sort_userdata.params = params;
        sort_userdata.sort_para = &para;
        sort_userdata.state = FMT_ADV_SORT_STATE_INIT;
        
        para.Pattern = params->folderpath;
        para.PatternArray = params->filter_array;
        para.PatternNum = params->filter_count;
        para.ArrayMask = params->ArrayMask;
        para.AttrMask = params->AttrMask;
        para.Flag = (params->Flag & 0x0FFFFFFF);
        para.Timeout = 0;
        para.Position = &sort_handle;
        para.ProgressCallback = fmt_adv_sort_progress_callback;
        para.ProgressCallbackParam = (void*)&sort_userdata;
        para.CompareFunc = (SortingCompareFunc)params->sort_compare_func;
        para.SortingBuffer = (BYTE*)params->sort_buffer;
        para.SortingBufferSize = params->sort_buffer_size;
        para.WorkingBuffer = (BYTE*)params->work_buffer;
        para.WorkingBufferSize = params->work_buffer_size;

        fs_ret = FS_XFindReset(&para);

        if(fs_ret < 0)
            break;

        /* sort complete */
        ASSERT(fs_ret == sort_userdata.total_count);
        ASSERT(sort_userdata.progress_count == sort_userdata.total_count);

        /* find index of preferred filename if required*/
        if(!params->search_filename || !params->search_filename[0])
            index = 0;

        filename = (WCHAR*)get_ctrl_buffer(256*2);

        for(i=0;i<sort_userdata.total_count;i++)
        {
            if(g_fmt_adv_ctxt.aborting)
                break;
            
            fs_ret = FS_XFindStart(params->folderpath, 
                                   &fs_entry,
                                   filename,
                                   256*2,
                                   (UINT)i,
                                   &sort_handle,
                                   FS_FIND_DEFAULT);

            if(fs_ret < 0)
                break;

            if(folder_count < 0 && !(fs_entry.Attributes & FS_ATTR_DIR))
            {
                folder_count = i;
            }

            if(params->search_filename && params->search_filename[0] &&
                !kal_wstrcmp(filename, params->search_filename))
            {
                index = i;
            }

            // both found
            if(index >= 0 && folder_count >= 0)
                break;
        }

        free_ctrl_buffer(filename);
        filename = NULL;

        fs_ret = sort_userdata.total_count;
        if(folder_count < 0)
            folder_count = fs_ret;

    } while(0);

    if(!params->search_filename || !params->search_filename[0])
        index = -1;
    
    *found_index_p = index;
    *folder_count_p = folder_count;
    *sort_handle_p = (fs_ret >= 0) ? sort_handle : 0;

    return fs_ret;
}
#endif

typedef struct 
{
    fmt_adv_load_folder_req_struct  *params;
    
    kal_int32                       total_count;
    kal_int32                       progress_count;

    kal_int32                       cache_start;
    kal_int32                       cache_count;

    kal_uint32                      last_time;
} fmt_adv_list_context_struct;

static kal_int32 fmt_adv_list_progress_callback(FS_HANDLE handle, fs_pgs_enum status, kal_int32 total, kal_uint32 completed, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_list_context_struct *ctxt = (fmt_adv_list_context_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_fmt_adv_ctxt.aborting)
        return -1;

    switch(status)
    {
    case FS_PGS_PREPARE:
        break;
        
    case FS_SORT_PGS_ING:
    case FS_SORT_PGS_DONE:
        ctxt->progress_count = completed + ctxt->cache_start;

        if(ctxt->params->Flag & 0x80000000)
        {
            kal_uint32 cur_time;
            kal_get_time(&cur_time);

            if(cur_time - ctxt->last_time > KAL_TICKS_500_MSEC)
            {
                fmt_adv_load_folder_send_progress_ind(handle, ctxt->params->user_data, 
                    ctxt->total_count, ctxt->progress_count,
                    ctxt->cache_start, ctxt->cache_count);

                ctxt->last_time = cur_time;
            }
        }

        break;
    }
    return 0;
}

static kal_int32 fmt_adv_load_folder_read_hdlr(fmt_adv_load_folder_req_struct *params, kal_int32* found_index_p, kal_int32* folder_count_p, 
                                         kal_int32* cache_start_index_p, kal_int32* cache_count_p, UINT* list_handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32       fs_ret, fh, total_count, index, cache_count, folder_count;
    BYTE            Attr_must_have;
    FS_DOSDirEntry  fs_entry;
    WCHAR           *filename;
    /*fmt_adv_load_folder_cache_item_struct* cache_buffer;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMT_TRACE0(TRC_FMT_1F14A07871284BDCAFD12669EB059534, "[FMTADV] fmt_adv_load_folder_read_hdlr");
    
    /* For this case, sort buffer is not enough (or sort not enable), 
     * so we need to use old FS_FindFirstN(...) to do following:
     *  1. find Total file count
     *  2. find index of preferred file by name
     *  3. load cache of prefered index
     *  4. use sort_buffer to cache some data 
     */
    ASSERT(found_index_p && cache_start_index_p && cache_count_p);

    /* adjust params for FS_FindFirstN */
    if(!(params->Flag & FS_DIR_TYPE))
        params->AttrMask |= FS_ATTR_DIR;
    
    Attr_must_have = 0;
    if(!(params->Flag & FS_FILE_TYPE))
        Attr_must_have |= FS_ATTR_DIR;

    if(params->search_filename && !params->search_filename[0])
        params->search_filename = NULL;
    
    index = *found_index_p = -1;
    folder_count = *folder_count_p = -1;
    filename = NULL;
    do {
        
        /* if we already know total count, and no need to search file, it is case 3 */
        if(params->total_count > 0 && !params->search_filename)
        {
            ASSERT(params->load_index >= 0);
            total_count = params->total_count;
            fs_ret = total_count;
            break;
        }

        folder_count = 0;
        total_count = 0;
        index = -1;

        /* do not search */
        if(!params->search_filename)
            index = 0;

        filename = (WCHAR*)get_ctrl_buffer(256*2);
    
        /* find total file count */
        fh = FS_FindFirstN(params->folderpath, 
                           params->filter_array,
                           params->filter_count,
                           params->ArrayMask,
                           Attr_must_have, 
                           params->AttrMask, 
                           &fs_entry,
                           filename, 256*2,
                           0, FS_FIND_DEFAULT);

        if(fh < 0)
        {
            if(fh == FS_NO_MORE_FILES)
            {
                fs_ret = 0;
                break;
            }
            fs_ret = fh;
            break;
        }

        do {
            if(g_fmt_adv_ctxt.aborting)
            {
                total_count = FS_ABORTED_ERROR;
                break;
            }
            
            /* do match if necessary */
            if( index < 0 && !kal_wstrcmp(filename, params->search_filename))
            {
                index = total_count;
                *found_index_p = index;

                /* already have total count, can stop */
                if(params->total_count >= 0)
                {
                    total_count = params->total_count;
                    break;
                }
            }

            if(fs_entry.Attributes & FS_ATTR_DIR)
                folder_count++;
            total_count++;
            fs_ret = FS_FindNextN(fh, params->filter_array, params->filter_count,
                                  params->ArrayMask,
                                  &fs_entry,
                                  filename, 256*2,
                                  FS_FIND_DEFAULT);
        } while(fs_ret >= 0);

        fs_ret = total_count;

        FS_FindClose(fh);
    } while(0);
    
    if(filename)
    {
       free_ctrl_buffer(filename); 
       filename = NULL;
    }

    /* here, fs_ret = total_count is ready */

    do {
        fs_list_param_struct list_params;
        fmt_adv_list_context_struct list_context;

        if(fs_ret <= 0) /* error or no file */
            break;

        filename = (WCHAR*)get_ctrl_buffer(sizeof(fmt_adv_load_folder_cache_item_struct));

        /* 3. write cache into sort_buffer according to load_index */
        cache_count = FS_LIST_ENTRY(params->sort_buffer_size);

        if(!params->search_filename)
            index = params->load_index;
        if(index < 0)
            index = 0;

        index = index - (cache_count/2);
        if(index > total_count - cache_count)
            index = total_count - cache_count;
        if(index < 0)
            index = 0;
        
        kal_mem_set(&list_params, 0, sizeof(list_params));

        list_params.path = params->folderpath;
        list_params.attr_mask = params->AttrMask;
        list_params.attr = Attr_must_have;
        list_params.index = index;
        list_params.name_pattern = params->filter_array;
        list_params.name_pattern_count = params->filter_count;
        list_params.attr_pattern = params->ArrayMask;
        list_params.callback = fmt_adv_list_progress_callback;
        list_params.param = &list_context;
        list_params.buff = params->sort_buffer;
        list_params.buff_size = params->sort_buffer_size;

        kal_mem_set(&list_context, 0, sizeof(list_context));
        list_context.params = params;
        list_context.total_count = total_count;
        list_context.cache_start = index;
        list_context.cache_count = cache_count;
        kal_get_time(&list_context.last_time);
        
        fs_ret = FS_ListOpen(&list_params, (FS_HANDLE*)list_handle_p);
        if(fs_ret < 0)
            break;

        fs_ret = total_count;

        *cache_start_index_p = index;
        *cache_count_p = cache_count;
    } while(0);

    if(filename)
    {
       free_ctrl_buffer(filename); 
       filename = NULL;
    }

    if(fs_ret >= 0)
        *folder_count_p = folder_count;

    return fs_ret;  

}

static kal_int32 fmt_adv_load_folder_set_dircache(const WCHAR* folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_int32 fs_ret;
    UINT cache_mark;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        fh = FS_Open(folderpath, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
        if(fh < 0)
        {
            fs_ret = fh;
            break;
        }

        fs_ret = FS_GetDirCache(fh, &cache_mark);
        if(fs_ret < 0)
        {
            fs_ret = FS_SetDirCache(fh, FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK+1);
        }
        else
        {
            ASSERT(cache_mark > FMT_ADV_LOAD_FOLDER_DIRCACHE_MARK);
            cache_mark ++;
            fs_ret = FS_SetDirCache(fh, cache_mark);
        }

        FS_Close(fh);
    } while(0);
    return fs_ret;
}

static void fmt_adv_load_folder_send_rsp(fmt_adv_load_folder_req_struct *params, kal_int32 fs_ret,
                                         UINT sort_handle, kal_int32 found_index, kal_int32 folder_count,
                                         kal_int32 cache_start_index, kal_int32 cache_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    fmt_adv_load_folder_rsp_struct  *rsp_ptr;
    ilm_struct                      *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_fmt_adv_ctxt.aborting)
        return;

    FMT_TRACE2(TRC_FMT_EA2E6993C7AF4B3E9307F18A0CD30EF8, "[FMTADV] fmt_adv_load_folder_send_rsp(%d,%d)", fs_ret, found_index);

    rsp_ptr = (fmt_adv_load_folder_rsp_struct*) construct_local_para(sizeof(fmt_adv_load_folder_rsp_struct), TD_CTRL | TD_RESET);
    rsp_ptr->req_seq = params->req_seq;

    rsp_ptr->user_data = params->user_data;

    rsp_ptr->result = (fs_ret < 0) ? fs_ret : 0;
    rsp_ptr->total_count = (fs_ret > 0) ? fs_ret : 0;
    rsp_ptr->total_folder_count = (fs_ret > 0) ? folder_count : 0;

    if(fs_ret >= 0)
    {
        rsp_ptr->sort_handle = sort_handle;

        rsp_ptr->found_index = found_index;
        
        rsp_ptr->cache_start_index = cache_start_index;
        rsp_ptr->cache_count = cache_count;
    }

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_LOAD_FOLDER_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) rsp_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);
}

static void fmt_adv_load_folder_send_progress_ind(UINT handle, kal_uint32 user_data, 
                                                  kal_int32 total, kal_int32 complete, 
                                                  kal_int32 cache_start, kal_int32 cache_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_load_folder_progress_ind_struct *ind_ptr;
    ilm_struct                              *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_fmt_adv_ctxt.discarding)
    {
        FMT_TRACE2(TRC_FMT_1071288846DA4F40ADD6B040E9FA6210, "[FMTADV] [FMTADV] discarded(%d,%d)", g_fmt_adv_ctxt.working_message, g_fmt_adv_ctxt.working_seq);
        return;
    }
    
    ind_ptr = (fmt_adv_load_folder_progress_ind_struct*) construct_local_para(
                    sizeof(fmt_adv_load_folder_progress_ind_struct), TD_CTRL | TD_RESET);
    ind_ptr->req_seq = g_fmt_adv_ctxt.working_seq;

    ind_ptr->user_data = user_data;

    ind_ptr->sort_handle = handle;
    ind_ptr->total_count = total;
    ind_ptr->complete_count = complete;
    
    ind_ptr->cache_start_index = cache_start;
    ind_ptr->cache_count = cache_count;

    ilm_ptr = allocate_ilm(MOD_FMT);
    ilm_ptr->msg_id = MSG_ID_FMT_ADV_LOAD_FOLDER_PROGRESS_IND;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) ind_ptr;

    SEND_ILM(MOD_FMT, MOD_MMI, MMI_FMT_SAP, ilm_ptr);

}


static void fmt_adv_load_folder_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr, kal_bool abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmt_adv_load_folder_req_struct  *params = (fmt_adv_load_folder_req_struct*)local_para_ptr;
    kal_int32                       len, fs_ret, found_index, folder_count;
    kal_int32                       cache_start_index, cache_count;
    UINT                            sort_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(abort)
    {
        /* do nothing */
        return;
    }

    FMT_TRACE0(TRC_FMT_C7B5A8515AF846038AE82193061DDA15, "[FMTADV] fmt_adv_load_folder_req_hdlr");

    cache_start_index = cache_count = 0;
    
    do {
        /* check length */
        len = kal_wstrlen(params->folderpath);
        if(len <= 0)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        /* add "\\" if necessary */
        if(params->folderpath[len-1] != '\\')
        {
            params->folderpath[len++] = '\\';
            params->folderpath[len] = 0;
        }
        
        if(len >= 260)
        {
            fs_ret = FS_PATH_OVER_LEN_ERROR;
            break;
        }

        kal_wstrcat(params->folderpath, L"*.*");

#if defined(__FS_SORT_SUPPORT__)
        if(params->total_count < 0 && params->work_buffer)
        {
            fs_ret = fmt_adv_load_folder_sort_hdlr(params, &found_index, &folder_count, &sort_handle);
        }
        else
#endif
        {
            sort_handle = 0;
            fs_ret = FS_TOO_MANY_FILES;
        }

        if(fs_ret == FS_TOO_MANY_FILES)
        {
            fs_ret = fmt_adv_load_folder_read_hdlr(params, &found_index, &folder_count, 
                                                   &cache_start_index, &cache_count, &sort_handle);
        }

        if(fs_ret < 0)
            break;

        /* set DirCache */
        params->folderpath[len] = 0;
        len = fmt_adv_load_folder_set_dircache(params->folderpath);
        if(len < 0)
        {
            fs_ret = len;
            break;
        }

    } while(0);

    fmt_adv_load_folder_send_rsp(params, fs_ret, sort_handle, found_index, folder_count, cache_start_index, cache_count);

}

#endif /* FMT_NOT_PRESENT */ 

