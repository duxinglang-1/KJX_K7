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
 *  Procedure.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Procedure control utility.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_include.h"
#include "ProcedureGprot.h"


#define MMI_FRM_PROC_TRACE MMI_FW_TRC_G8_PROC

#define MMI_FRM_PROC_MAX_RECURSIVE_EXECUTION_NUM 4


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct mmi_frm_proc_control_block_struct_s
{
    mmi_frm_proc_id_info_struct id_info;
    mmi_proc_func completed_proc;
    void *user_data;
    
    struct mmi_frm_proc_control_block_struct_s *next;
} mmi_frm_proc_control_block_struct;

typedef struct
{
    mmi_frm_proc_id available_id;
    mmi_frm_proc_control_block_struct *control_blocks;
} mmi_frm_proc_control_cntx_struct;


/****************************************************************************
 * Global Variables
 ****************************************************************************/

static mmi_frm_proc_control_cntx_struct g_mmi_frm_proc_control_cntx =
{
    MMI_FRM_PROC_ID_FREE_ID_BEGIN  /* available_id */
};


/****************************************************************************
 * [Procedure control]
 *
 * The control kernel of procedure mechanism.
 ****************************************************************************/

/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_id mmi_frm_proc_allocate_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_proc_control_cntx.available_id++;
    
    if (g_mmi_frm_proc_control_cntx.available_id >= 0xfff0)
    {
        g_mmi_frm_proc_control_cntx.available_id = MMI_FRM_PROC_ID_FREE_ID_BEGIN;
    }

    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_ALLOCATE_ID, g_mmi_frm_proc_control_cntx.available_id);
    
    return g_mmi_frm_proc_control_cntx.available_id;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_struct *mmi_frm_proc_init(
                        mmi_frm_proc_struct *proc,
                        mmi_frm_proc_id id,
                        mmi_frm_proc_entry_func_ptr entry,
                        void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    proc->id = id;
    proc->arg = arg;
    proc->entry = entry;
    
    return proc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_equals
 * DESCRIPTION
 *  Compare 2 id_info_structs to check whether they are the same.
 *  Why don't use memcmp()? Because the compiler seems not to optimize the
 *  comparison to simple inline comparsion. We want to reduce the overhead of
 *  memcmp() manually.
 * PARAMETERS
 *  a       [IN] The first id_info to be compared
 *  b       [IN] The second id_info to be compared.
 * RETURNS
 *  Equivalent or not
 *****************************************************************************/
static MMI_BOOL mmi_frm_proc_equals(
                    const mmi_frm_proc_id_info_struct *a,
                    const mmi_frm_proc_id_info_struct *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (a->parent_id == b->parent_id && a->this_id == b->this_id) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_remove_from_control_list
 * DESCRIPTION
 *  Remove a notification information block from control list. The id_info
 *  of the block to be removed should match the parameter.
 * PARAMETERS
 *  id_info      [IN] Specified ID info.
 * RETURNS
 *  The block matched. It is already removed from the list when return.
 *****************************************************************************/
static mmi_frm_proc_control_block_struct *mmi_frm_proc_remove_from_control_list(
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_control_block_struct *prev, *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find id_info in control block list */
    prev = NULL;
    curr = g_mmi_frm_proc_control_cntx.control_blocks;
    while (curr != NULL)
    {
        if (mmi_frm_proc_equals(&(curr->id_info), &(id_info)))
        {
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    /* Remove from control block list if found */
    if (curr != NULL)
    {
        MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_CONTROL_LIST, 'R',
            curr->id_info.parent_id, curr->id_info.this_id);
    
        if (prev == NULL)
        {
            g_mmi_frm_proc_control_cntx.control_blocks = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }

        curr->next = NULL;
    }

    return curr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_add_into_control_list
 * DESCRIPTION
 *  Add the control block into control list.
 * PARAMETERS
 *  control_block      [IN] The block to blocked.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_proc_add_into_control_list(mmi_frm_proc_control_block_struct *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(control_block != NULL);
    /* The same procedure can not be launched again while still executing */
    MMI_ASSERT(mmi_frm_proc_remove_from_control_list(control_block->id_info) == NULL);
    
    control_block->next = g_mmi_frm_proc_control_cntx.control_blocks;
    g_mmi_frm_proc_control_cntx.control_blocks = control_block;

    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_CONTROL_LIST, 'A',
        control_block->id_info.parent_id, control_block->id_info.this_id);
}


/*****************************************************************************
  * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_notify_completed(const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_control_block_struct *control_block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(id_info.parent_id != MMI_FRM_PROC_ID_INVALID &&
        id_info.this_id != MMI_FRM_PROC_ID_INVALID);

    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_NOTIFY_COMPLETED,
        id_info.parent_id, id_info.this_id);
    
    control_block = mmi_frm_proc_remove_from_control_list(id_info);
    
    if (control_block != NULL)
    {
        mmi_frm_proc_completed_evt_struct completed_evt;

        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_PROC_COMPLETED);
        completed_evt.id = id_info.this_id;
        MMI_FRM_SEND_EVENT(&completed_evt, control_block->completed_proc, control_block->user_data);
        
        OslMfree(control_block);
    }
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_invalidate(mmi_frm_proc_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_control_block_struct *prev, *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_INVALIDATE, id);
    
    prev = NULL;
    curr = g_mmi_frm_proc_control_cntx.control_blocks;
    while (curr != NULL)
    {
        if (curr->id_info.parent_id == id ||
            curr->id_info.this_id == id)
        {
            MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_INVALIDATE_REMOVED,
                (U32)curr, curr->id_info.parent_id, curr->id_info.this_id);
                
            /* Remove from list */
            if (prev != NULL)
            {
                prev->next = curr->next;
                OslMfree(curr);
                curr = prev->next;
            }
            else
            {
                g_mmi_frm_proc_control_cntx.control_blocks = curr->next;
                OslMfree(curr);
                curr = g_mmi_frm_proc_control_cntx.control_blocks;
            }
        }
        else
        {
            /* Reserve, go to next node */
            prev = curr;
            curr = curr->next;
        }
    }
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_frm_proc_execute(
                            mmi_frm_proc_id parent_id,
                            mmi_proc_func completed_proc,
                            void *user_data,
                            const mmi_frm_proc_struct *child)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_id_info_struct id_info;
    mmi_frm_proc_result_enum execution_result;
    mmi_frm_proc_control_block_struct *control_block;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(parent_id != MMI_FRM_PROC_ID_INVALID && completed_proc != NULL && child != NULL);

    id_info.parent_id = parent_id;
    id_info.this_id = child->id;

    if (id_info.this_id < MMI_FRM_PROC_ID_FREE_ID_BEGIN)
    {
        MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_ID_MAPPING, id_info.this_id, id_info.this_id);
    }


    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_EXECUTE_CALL,
        id_info.parent_id, id_info.this_id, (U32)(child->entry));

    /* Invoke the entry function of the procedure to be executed */
    execution_result = child->entry(child->arg, id_info);
    
    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_EXECUTE_RETURN,
        id_info.parent_id, id_info.this_id, (U32)(child->entry), execution_result);

    if (execution_result == MMI_FRM_PROC_RESULT_NOTIFY_LATER)
    {
        /*
         * If the procedure can not complete right away, insert it to the
         * control list; so that the notify_complete later can found its
         * parent's callback.
         */
        control_block = (mmi_frm_proc_control_block_struct*)
            OslMalloc(sizeof(mmi_frm_proc_control_block_struct));

        control_block->id_info = id_info;
        control_block->completed_proc = completed_proc;
        control_block->user_data = user_data;
        control_block->next = NULL;
        mmi_frm_proc_add_into_control_list(control_block);
    }
    
    return execution_result;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_result_enum mmi_frm_proc_post_complete_execute(
                            mmi_frm_proc_id parent_id,
                            mmi_proc_func completed_proc,
                            void *user_data,
                            const mmi_frm_proc_struct *child)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_result_enum execution_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    execution_result = mmi_frm_proc_execute(
        parent_id,
        completed_proc,
        user_data,
        child);

    if (execution_result == MMI_FRM_PROC_RESULT_COMPLETED)
    {
        mmi_frm_proc_completed_evt_struct completed_evt;

        MMI_FRM_INIT_EVENT(&completed_evt, EVT_ID_PROC_COMPLETED);
        completed_evt.id = child->id;
        MMI_FRM_POST_EVENT(&completed_evt, completed_proc, user_data);
    }

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/****************************************************************************
 * [Sequential procedure]
 *
 * Control component of sequential procedures. All procedure defined in a
 * sequential procedure set will be executed one by one. The completed_callback
 * will be invoked only after the final procedure completed.
 ****************************************************************************/

#define MMI_FRM_PROC_SEQUENTIAL

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_frm_proc_id my_id;
    mmi_frm_proc_id_info_struct id_info;
    const mmi_frm_proc_struct *children_proc;
    U32 n_children;
    U32 currently_executing_index;
    void *user_data;
    mmi_frm_proc_status_callback status_callback;
    MMI_BOOL is_completed;
} mmi_frm_proc_seq_cntx_struct;


/****************************************************************************
 * Local Functions
 ****************************************************************************/

static mmi_ret mmi_frm_proc_seq_child_completed_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_seq_continue_execute
 * DESCRIPTION
 *  Execute the procedure pointed by currently_executing_index.
 * PARAMETERS
 *  cntx        [IN] Context
 * RETURNS
 *  COMPLETED if all sub-procedure completed. Otherwise, NOTIFY_LATER.
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_frm_proc_seq_continue_execute(
    mmi_frm_proc_seq_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_frm_proc_struct *child_proc;
    mmi_frm_proc_result_enum execution_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx != NULL);
    
    while (cntx->currently_executing_index < cntx->n_children)
    {
        child_proc = &(cntx->children_proc[cntx->currently_executing_index]);
        
        execution_result = mmi_frm_proc_execute(
            cntx->my_id,
            mmi_frm_proc_seq_child_completed_proc,
            cntx,
            child_proc);
            
        if (execution_result == MMI_FRM_PROC_RESULT_NOTIFY_LATER)
        {
            return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
        }

        cntx->currently_executing_index++;
    }
    
    return MMI_FRM_PROC_RESULT_COMPLETED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_seq_entry
 * DESCRIPTION
 *  The entry function of a sequential procedure.
 * PARAMETERS
 *  user_data   [IN] mmi_frm_proc_seq_cntx_struct*
 *  id_info     [IN] ID information should be passed to notify_completed
 * RETURNS
 *  If all sub-procedures completed once entry function is called, COMPLETED
 *  will be returned. Otherwise, NOTIFY_LATER will be returned. And the
 *  complete notification will be through the callback.
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_frm_proc_seq_entry(
    void *user_data,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_seq_cntx_struct *cntx;
    mmi_frm_proc_result_enum execution_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL);
    cntx = (mmi_frm_proc_seq_cntx_struct*)user_data;
    
    if (cntx->is_completed)
    {
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    cntx->id_info = id_info;
    cntx->currently_executing_index = 0;
    execution_result = mmi_frm_proc_seq_continue_execute(cntx);
    
    if (execution_result == MMI_FRM_PROC_RESULT_COMPLETED)
    {
        cntx->is_completed = MMI_TRUE;
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }
    
    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_seq_child_completed_proc
 * DESCRIPTION
 *  The callback function of children completed.
 * PARAMETERS
 *  evt     [IN] mmi_frm_proc_completed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_frm_proc_seq_child_completed_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_completed_evt_struct *completed_evt;
    mmi_frm_proc_seq_cntx_struct *cntx;
    mmi_frm_proc_result_enum execution_result;
    mmi_frm_proc_id my_id;
    U32 n_completed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    completed_evt = (mmi_frm_proc_completed_evt_struct*)evt;
    MMI_ASSERT(completed_evt->user_data != NULL);
    cntx = (mmi_frm_proc_seq_cntx_struct*)completed_evt->user_data;

    if (cntx->is_completed)
    {
        return MMI_RET_OK; /* Already completed, ignore */
    }

    if (cntx->children_proc[cntx->currently_executing_index].id != completed_evt->id)
    {
        return MMI_RET_OK; /* The completed item is not expected, ignore */
    }

    execution_result = MMI_FRM_PROC_RESULT_NOTIFY_LATER;

    n_completed = cntx->currently_executing_index + 1;
    
    if (cntx->status_callback != NULL &&
        n_completed < cntx->n_children)
    {
        mmi_frm_proc_set_status_struct set_status;
        mmi_frm_proc_ctrl_enum ctrl;
    
        set_status.instance = cntx;
        set_status.n_completed = (S16)n_completed;
        set_status.n_total_procs = (S16)cntx->n_children;

        ctrl = cntx->status_callback(cntx->user_data, &set_status);
        if (ctrl == MMI_FRM_PROC_CTRL_STOP)
        {
            execution_result = MMI_FRM_PROC_RESULT_COMPLETED;
        }

        MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_SEQ_CHILD_COMPLETED,
            n_completed, cntx->n_children, cntx->status_callback, ctrl);
    }

    if (execution_result != MMI_FRM_PROC_RESULT_COMPLETED)
    {
        /* Execute next procedure */
        cntx->currently_executing_index++;
        execution_result = mmi_frm_proc_seq_continue_execute(cntx);
    }
    
    if (execution_result == MMI_FRM_PROC_RESULT_COMPLETED)
    {
        cntx->is_completed = MMI_TRUE;
        my_id = cntx->my_id;
        /* cntx may be destroyed by the callback */
        mmi_frm_proc_notify_completed(cntx->id_info);
        mmi_frm_proc_invalidate(my_id);
    }

    return MMI_RET_OK;
}


/****************************************************************************
 * Global Functions
 ****************************************************************************/

/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_struct *mmi_frm_proc_seq_create(
                        mmi_frm_proc_id id,
                        const mmi_frm_proc_struct *sub_procs,
                        U32 n_sub_procs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* mem_space;
    mmi_frm_proc_struct *proc;
    mmi_frm_proc_seq_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(id != MMI_FRM_PROC_ID_INVALID && sub_procs != NULL && n_sub_procs > 0);
    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_SEQ_CREATE, id, (U32)sub_procs, n_sub_procs);

    mem_space = (U8*)OslMalloc(sizeof(mmi_frm_proc_struct) + sizeof(mmi_frm_proc_seq_cntx_struct));
    proc = (mmi_frm_proc_struct*)mem_space;
    cntx = (mmi_frm_proc_seq_cntx_struct*)(mem_space + sizeof(mmi_frm_proc_struct));

    cntx->my_id = id;
    cntx->children_proc = sub_procs;
    cntx->n_children = n_sub_procs;
    cntx->currently_executing_index = 0;
    cntx->is_completed = MMI_FALSE;
    cntx->status_callback = NULL;
    cntx->user_data = NULL;

    mmi_frm_proc_init(proc, id, mmi_frm_proc_seq_entry, cntx);

    return proc;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_seq_set_status_callback(
        mmi_frm_proc_struct *proc,
        mmi_frm_proc_status_callback status_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *mem_space;
    mmi_frm_proc_seq_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mem_space = (U8*)proc;
    cntx = (mmi_frm_proc_seq_cntx_struct*)(mem_space + sizeof(mmi_frm_proc_struct));
    
    cntx->status_callback = status_callback;
    cntx->user_data = user_data;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_seq_destroy(mmi_frm_proc_struct *proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(proc != NULL);
    
    mmi_frm_proc_invalidate(proc->id);
    proc->id = 0;
    OslMfree(proc);
}


/****************************************************************************
 * [Concurrent procedure]
 *
 * Control component of concurrent procedures. All procedure defined in a
 * concurrent procedure set will be executed concurrently. They will be
 * triggered at the same time. This procedure component complete when all
 * assigned sub-procedures completed; or client can assign a complete-condition
 * function to determine the completion. Once complete, any uncompleted yet
 * sub-procedure notifies complete, the complete callback will not be triggered
 * again. That is, the complete callback will only be launched once.
 ****************************************************************************/

#define MMI_FRM_PROC_CONCURRENT


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    mmi_frm_proc_id my_id;
    mmi_frm_proc_id_info_struct id_info;
    const mmi_frm_proc_struct *children_proc;
    S16 n_children;
    S16 n_completed;
    MMI_BOOL is_completed;
    mmi_frm_proc_status_callback status_callback;
    void *user_data;
    MMI_BOOL complete_of_children[1];
} mmi_frm_proc_con_cntx_struct;


typedef struct
{
    mmi_frm_proc_struct *proc;
    mmi_frm_proc_id_info_struct id_info;
} mmi_frm_proc_con_cr_ex_struct;


/****************************************************************************
 * Local Functions
 ****************************************************************************/

static mmi_ret mmi_frm_proc_con_child_completed_proc(mmi_event_struct *evt);

static mmi_ret mmi_frm_proc_con_cr_ex_child_completed_proc(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_con_can_complete
 * DESCRIPTION
 *  Determine if all completed. If not, query the condition callback whether
 *  can complete or not.
 * PARAMETERS
 *  cntx    [IN] Context
 * RETURNS
 *  MMI_TRUE if completed.
 *****************************************************************************/
static MMI_BOOL mmi_frm_proc_con_can_complete(mmi_frm_proc_con_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_set_status_struct set_status;
    mmi_frm_proc_ctrl_enum ctrl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx != NULL);
    
    set_status.instance = cntx;
    set_status.n_completed = cntx->n_completed;
    set_status.n_total_procs = cntx->n_children;

    if (cntx->n_completed == cntx->n_children)
    {
        return MMI_TRUE;
    }
    else if (cntx->status_callback != NULL)
    {
        ctrl = cntx->status_callback(cntx->user_data, &set_status);
        
        MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_CON_COMPLETE,
            cntx->my_id, cntx->n_completed, cntx->n_children, (U32)(cntx->status_callback), ctrl);

        return (ctrl == MMI_FRM_PROC_CTRL_STOP) ? MMI_TRUE : MMI_FALSE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_con_entry
 * DESCRIPTION
 *  The entry function of a concurrent procedure set.
 * PARAMETERS
 *  user_data   [IN] mmi_frm_proc_con_cntx_struct
 *  id_info     [IN] ID information should be passed to notify_completed
 * RETURNS
 *  COMPLETED if all procedure completed. Otherwise notify later.
 *****************************************************************************/
static mmi_frm_proc_result_enum mmi_frm_proc_con_entry(
    void *user_data,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_con_cntx_struct *cntx;
    mmi_frm_proc_result_enum execution_result;
    const mmi_frm_proc_struct *child_proc;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL);
    
    cntx = (mmi_frm_proc_con_cntx_struct*)user_data;
    
    if (cntx->is_completed)
    {
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    cntx->id_info = id_info;
    cntx->n_completed = 0;
    
    for (i = 0; i < cntx->n_children; i++)
    {
        child_proc = &(cntx->children_proc[i]);
    
        execution_result = mmi_frm_proc_execute(
                            cntx->my_id,
                            mmi_frm_proc_con_child_completed_proc,
                            cntx,
                            child_proc);
                            
        if (execution_result == MMI_FRM_PROC_RESULT_COMPLETED)
        {
            cntx->complete_of_children[i] = MMI_TRUE;
            cntx->n_completed++;
        }
    }

    if (mmi_frm_proc_con_can_complete(cntx))
    {
        cntx->is_completed = MMI_TRUE;
        mmi_frm_proc_invalidate(cntx->my_id);
        return MMI_FRM_PROC_RESULT_COMPLETED;
    }

    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_con_entry
 * DESCRIPTION
 *  The callback of children complete notification.
 * PARAMETERS
 *  evt     [IN] mmi_frm_proc_completed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_frm_proc_con_child_completed_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_completed_evt_struct *completed_evt;
    mmi_frm_proc_con_cntx_struct *cntx;
    S32 i;
    mmi_frm_proc_id my_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    completed_evt = (mmi_frm_proc_completed_evt_struct*)evt;
    
    MMI_ASSERT(completed_evt->user_data != NULL);
    cntx = (mmi_frm_proc_con_cntx_struct*)completed_evt->user_data;

    if (cntx->is_completed)
    {
        return MMI_RET_OK;
    }

    for (i = 0; i < cntx->n_children; i++)
    {
        if (cntx->children_proc[i].id == completed_evt->id)
        {
            if (!cntx->complete_of_children[i])
            {
                cntx->complete_of_children[i] = MMI_TRUE;
                cntx->n_completed++;
            }
            else /* Already completed */
            {
                return MMI_RET_OK; /* Ignore */
            }
            break;
        }
    }

    if (mmi_frm_proc_con_can_complete(cntx))
    {
        cntx->is_completed = MMI_TRUE;
        my_id = cntx->my_id;
        /* cntx may be destroyed by the callback */
        mmi_frm_proc_notify_completed(cntx->id_info);
        mmi_frm_proc_invalidate(my_id);
    }

    return MMI_RET_OK;
}


/****************************************************************************
 * Global Functions
 ****************************************************************************/

/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
mmi_frm_proc_struct *mmi_frm_proc_con_create(
                        mmi_frm_proc_id id,
                        const mmi_frm_proc_struct *sub_procs,
                        U32 n_sub_procs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *mem_space;
    mmi_frm_proc_struct *proc;
    mmi_frm_proc_con_cntx_struct *cntx;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(id != MMI_FRM_PROC_ID_INVALID && sub_procs != NULL && n_sub_procs > 0);
    MMI_TRACE(MMI_FRM_PROC_TRACE, TRC_MMI_FRM_PROC_CON_CREATE,
        id, (U32)sub_procs, n_sub_procs);
    
    mem_space = (U8*)OslMalloc(
        sizeof(mmi_frm_proc_struct) +
        sizeof(mmi_frm_proc_con_cntx_struct) + sizeof(MMI_BOOL) * (n_sub_procs - 1));
        
    proc = (mmi_frm_proc_struct*)mem_space;
    cntx = (mmi_frm_proc_con_cntx_struct*)(mem_space + sizeof(mmi_frm_proc_struct));

    cntx->my_id = id;
    cntx->children_proc = sub_procs;
    cntx->n_children = (S16)n_sub_procs;
    cntx->user_data = NULL;
    cntx->status_callback = NULL;
    cntx->n_completed = 0;
    cntx->is_completed = MMI_FALSE;
    
    for (i = 0; i < n_sub_procs; i++)
    {
        cntx->complete_of_children[i] = MMI_FALSE;
    }

    mmi_frm_proc_init(proc, id, mmi_frm_proc_con_entry, cntx);

    return proc;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_con_set_status_callback(
        mmi_frm_proc_struct *proc,
        mmi_frm_proc_status_callback status_callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *mem_space;
    mmi_frm_proc_con_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mem_space = (U8*)proc;
    cntx = (mmi_frm_proc_con_cntx_struct*)(mem_space + sizeof(mmi_frm_proc_struct));
    
    cntx->status_callback = status_callback;
    cntx->user_data = user_data;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
void mmi_frm_proc_con_destroy(mmi_frm_proc_struct *proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(proc != NULL);

    mmi_frm_proc_invalidate(proc->id);
    proc->id = 0;
    OslMfree(proc);
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 *****************************************************************************/
MMI_BOOL mmi_frm_proc_con_is_completed(
            mmi_frm_proc_instance_handle instance,
            mmi_frm_proc_id child_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_con_cntx_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(instance != NULL);
    
    cntx = (mmi_frm_proc_con_cntx_struct*)instance;

    for (i = 0; i < cntx->n_children; i++)
    {
        if (cntx->children_proc[i].id == child_id)
        {
            return (cntx->complete_of_children[i]);
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Please refer to ProcedureGprot.h
 ****************************************************************************/
mmi_frm_proc_result_enum mmi_frm_proc_con_create_and_execute(
                            void *arg,
                            const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_con_cr_ex_struct *cntx;
    mmi_frm_proc_con_proc_struct *sub_procs;
    mmi_frm_proc_result_enum execution_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(arg != NULL);

    cntx = (mmi_frm_proc_con_cr_ex_struct*)OslMalloc(sizeof(mmi_frm_proc_con_cr_ex_struct));

    cntx->id_info = id_info;

    sub_procs = (mmi_frm_proc_con_proc_struct*)arg;
    cntx->proc = mmi_frm_proc_con_create(
                    mmi_frm_proc_allocate_id(),
                    sub_procs->procs,
                    sub_procs->n_procs);

    mmi_frm_proc_con_set_status_callback(
        cntx->proc,
        sub_procs->status_callback,
        sub_procs->user_data);

    execution_result = mmi_frm_proc_execute(
                        id_info.this_id,
                        mmi_frm_proc_con_cr_ex_child_completed_proc,
                        cntx,
                        cntx->proc);

    if (execution_result == MMI_FRM_PROC_RESULT_COMPLETED)
    {
        mmi_frm_proc_con_destroy(cntx->proc);
        OslMfree(cntx);
    }

    return execution_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_proc_con_cr_ex_child_completed_proc
 * DESCRIPTION
 *  Completed proc of the concurrent procedure set.
 *  This will notify parent the set is completed and destroy the concurrent
 *  procedure set.
 * PARAMETERS
 *  evt     [IN] mmi_frm_proc_completed_evt_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_frm_proc_con_cr_ex_child_completed_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_con_cr_ex_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt->user_data != NULL);

    cntx = (mmi_frm_proc_con_cr_ex_struct*)evt->user_data;
    mmi_frm_proc_con_destroy(cntx->proc);
    mmi_frm_proc_notify_completed(cntx->id_info);
    OslMfree(cntx);

    return MMI_RET_OK;
}



