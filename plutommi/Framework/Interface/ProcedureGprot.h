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
 *  ProcedureGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global interface of procedure utility.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PROCEDURE_GPROT_H__
#define __PROCEDURE_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "ProcedureConfig.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  Invalid procedure ID.
 *  Applications shall not use this ID for procedure ID.
 */
#define MMI_FRM_PROC_ID_INVALID     0

/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  Procedure ID.
 *  This ID is defined statically in mmi_frm_proc_id_enum in ProcedureConfig.h.
 *  Client can also allocate one by mmi_frm_proc_allocate_id() to get free ID
 *  dynamically.
 */
typedef U16 mmi_frm_proc_id;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The ID of procedure completed event.
 */
#define EVT_ID_PROC_COMPLETED 0


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The execution result of an entry function of a procedure.
 */
typedef enum
{
    /* A procedure complete right away in the entry function */
    MMI_FRM_PROC_RESULT_COMPLETED,
    /* A procedure needs more time to complete, it will call mmi_frm_proc_notify_completed() later. */
    MMI_FRM_PROC_RESULT_NOTIFY_LATER,
    
    MMI_FRM_PROC_RESULT_END_OF_ENUM
} mmi_frm_proc_result_enum;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  Execution control for procedure
 */
typedef enum
{
    /* Continue execution */
    MMI_FRM_PROC_CTRL_CONTINUE,
    /* Stop execution */
    MMI_FRM_PROC_CTRL_STOP,

    MMI_FRM_PROC_CTRL_END_OF_ENUM
} mmi_frm_proc_ctrl_enum;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The ID to identify a procedure's ID and its parent's ID.
 *  The content will be passed into mmi_frm_proc_notify_completed() to notify the completion
 *  of a procedure.
 */
typedef struct
{
    mmi_frm_proc_id parent_id; /* Parent procedure's ID */
    mmi_frm_proc_id this_id;   /* The procedure ID of current procedure */
} mmi_frm_proc_id_info_struct;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The type of the entry function of a procedure. Once this procedure is triggered to execute
 *  this function will be invoked, passed into the argument assigned by its creator,
 *  and its ID information.
 * PARAMETERS
 *  arg      : [IN] The argument passed by creator.
 *  id_info  : [IN] The ID infomation of the procedure. The content should be carried back to
 *                  mmi_frm_proc_notify_completed() without modification.
 * RETURNS
 *  mmi_frm_proc_result_enum, see the comment of mmi_frm_proc_result_enum.
 */
typedef mmi_frm_proc_result_enum (*mmi_frm_proc_entry_func_ptr)(void *arg, const mmi_frm_proc_id_info_struct id_info);

/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The structure to describe a procedure.
 *  Client should invoke mmi_frm_proc_execute() or mmi_frm_proc_post_complete_execute()
 *  to execute a procedure.
 */
typedef struct
{
    /* Procedure ID */
    mmi_frm_proc_id id;
    
    /*
     * Entry function of a procedure. Once this procedure is triggered to execute
     * this function will be invoked, passed into the argument assigned by its creator,
     * and its ID information.
     */
    mmi_frm_proc_entry_func_ptr entry;
    
    /* The argument to be passed into the entry function */
    void *arg;
} mmi_frm_proc_struct;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  Event structure of EVT_ID_PROC_COMPLETED.
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    
    /* The ID of the completed procedure */
    mmi_frm_proc_id id;
} mmi_frm_proc_completed_evt_struct;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The handle of a procedure instance.
 *  If you assign a callback to a procedure, the procedure may pass its handle to the callback,
 *  so that the callback can use the handle to get extra information or control the procedure.
 * SEE ALSO
 *  mmi_frm_proc_set_status_struct
 */
typedef void *mmi_frm_proc_instance_handle;


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The complete information to be passed to status callback.
 *  The callback can use the information to determine the completion of a procedure.
 * SEE ALSO
 *  mmi_frm_proc_con_create
 */
typedef struct
{
    /*
     * The handle of a procedure, this handle can be used to query the specific information
     * of a procedure, by the APIs which the procedure type provided.
     */
    mmi_frm_proc_instance_handle instance;

    /* The number of completed sub-procedures. */
    S16 n_completed;

    /* Total number of sub-procedures. */
    S16 n_total_procs;
} mmi_frm_proc_set_status_struct;


/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_status_callback
 * DESCRIPTION
 *  Callback function to determine the completion of a procedure.
 * PARAMETERS
 *  user_data   : [IN] The pointer passed into the create function.
 *  info        : [IN] The information to help determine completion.
 * RETURNS
 *  mmi_frm_proc_ctrl_enum
 *****************************************************************************/
typedef mmi_frm_proc_ctrl_enum (*mmi_frm_proc_status_callback)(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status);


/*
 * <GROUP Procedure>
 *
 * DESCRIPTION
 *  The set of procedures to be concurrently executed.
 *  This is the argument structure of mmi_frm_proc_con_create_and_execute().
 * SEE ALSO
 *  mmi_frm_proc_con_create_and_execute
 */
typedef struct
{
    mmi_frm_proc_struct *procs; /* Pointer of a procedure array */
    U32 n_procs;                /* Number of procedures */
    mmi_frm_proc_status_callback status_callback; /* The status callback */
    void *user_data;            /* To be passed into status_callback() */
} mmi_frm_proc_con_proc_struct;


/****************************************************************************
 * Exported functions
 ****************************************************************************/

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_allocate_id
 * DESCRIPTION
 *  Allocate a free procedure ID. Kernel will use this ID to identify a
 *  procedure. This ID is not need to be freed.
 * PARAMETERS
 *  void
 * RETURNS
 *  An unused procedure ID.
 *****************************************************************************/
extern mmi_frm_proc_id mmi_frm_proc_allocate_id(void);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_init
 * DESCRIPTION
 *  Initialize a procedure structure by given arguments.
 * PARAMETERS
 *  proc        : [OUT] The structure to be initialized.
 *  id          : [IN] Procedure ID.
 *  entry       : [IN] Entry function of the procedure.
 *  arg         : [IN] Argument to be passed into the entry function.
 * RETURNS
 *  The procedure pointer passed in.
 *****************************************************************************/
extern mmi_frm_proc_struct *mmi_frm_proc_init(
                                mmi_frm_proc_struct *proc,
                                mmi_frm_proc_id id,
                                mmi_frm_proc_entry_func_ptr entry,
                                void *arg);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_notify_completed
 * DESCRIPTION
 *  Notify a procedure has completed. The id_info should be the same as the
 *  argument of entry() of the procedure. This API is responsible to notify
 *  the parent of the procedure.
 * PARAMETERS
 *  id_info      : [IN] The id_info which was passed into the entry().
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_proc_notify_completed(const mmi_frm_proc_id_info_struct id_info);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_invalidate
 * DESCRIPTION
 *  Invalidate future notification. If a procedure is invalidated, it will no
 *  longer receive notification from children and can not communicate with
 *  its parent.
 * PARAMETERS
 *  id      : [IN] The ID to be invalidated.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_proc_invalidate(mmi_frm_proc_id id);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_execute
 * DESCRIPTION
 *  Execute a procedure.
 *  If the procedure completed right away, the completed_proc() will NOT be
 *  called but returns a COMPLETED. Otherwise, a NOTIFY_LATER will be returned
 *  and the completed_proc() will be called once the child completed.
 * PARAMETERS
 *  parent_id       : [IN] Parent procedure ID.
 *  completed_proc  : [IN] Completed proc. If the return value is COMPLETED,
 *                         this proc will be ignored. Otherwise if the return
 *                         value is NOTIFY_LATER, this proc will be invoked
 *                         as the child completed.
 *  user_data       : [IN] This argument will be passed into the callback
 *  child           : [IN] Procedure to be executed.
 * RETURNS
 *  mmi_frm_proc_result_enum
 *****************************************************************************/
extern mmi_frm_proc_result_enum mmi_frm_proc_execute(
                                    mmi_frm_proc_id parent_id,
                                    mmi_proc_func completed_proc,
                                    void *user_data,
                                    const mmi_frm_proc_struct *child);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_post_complete_execute
 * DESCRIPTION
 *  Execute a procedure.
 *  Different from mmi_frm_proc_execute(), it always returns NOTIFY_LATER and
 *  the completed_proc() will always be called.
 * PARAMETERS
 *  parent_id       : [IN] Parent procedure ID.
 *  user_data       : [IN] To be passed into the callback
 *  completed_proc  : [IN] Completed proc. Once the child completed, this proc
 *                         will be notified.
 *  child           : [IN] Procedure to be executed.
 * RETURNS
 *  Always MMI_FRM_PROC_RESULT_NOTIFY_LATER
 *****************************************************************************/
extern mmi_frm_proc_result_enum mmi_frm_proc_post_complete_execute(
                                    mmi_frm_proc_id parent_id,
                                    mmi_proc_func completed_proc,
                                    void *user_data,
                                    const mmi_frm_proc_struct *child);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_seq_create
 * DESCRIPTION
 *  Create a sequential procedure by given table.
 * PARAMETERS
 *  id          : [IN] Procedure ID, can get from mmi_frm_proc_allocate_id().
 *  sub_procs   : [IN] Procedures to be executed.
 *  n_sub_procs : [IN] Number of sub_procs.
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_frm_proc_struct *mmi_frm_proc_seq_create(
                                mmi_frm_proc_id id,
                                const mmi_frm_proc_struct *sub_procs,
                                U32 n_sub_procs);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_seq_destroy
 * DESCRIPTION
 *  Free the resource hold by a sequential procedure set. Once a procedure is
 *  destoryed, the completed_callback will not be invoked again.
 * PARAMETERS
 *  proc    : [IN] The procedure to be destroyed.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_proc_seq_destroy(mmi_frm_proc_struct *proc);


/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_seq_set_status_callback
 * DESCRIPTION
 *  Set the status callback.
 *  Client can know execution status and control the execution by this callback.
 * PARAMETERS
 *  proc                [IN] A sequential proc
 *  status_callback     [IN] Status callback
 *  user_data           [IN] To be passed into status_callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_proc_seq_set_status_callback(
                mmi_frm_proc_struct *proc,
                mmi_frm_proc_status_callback status_callback,
                void *user_data);


/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_con_create
 * DESCRIPTION
 *  Create a concurrent procedure set.
 * PARAMETERS
 *  id          : [IN] Procedure ID, can get from mmi_frm_proc_allocate_id().
 *  sub_procs   : [IN] Procedures to be executed.
 *  n_sub_procs : [IN] Number of sub_procs.
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_frm_proc_struct *mmi_frm_proc_con_create(
                                mmi_frm_proc_id id,
                                const mmi_frm_proc_struct *sub_procs,
                                U32 n_sub_procs);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_con_destroy
 * DESCRIPTION
 *  Free the resource hold by a concurrent procedure set. Once a procedure is
 *  destoryed, the completed_callback will not be invoked again.
 * PARAMETERS
 *  proc    : [IN] The procedure to be destroyed.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_proc_con_destroy(mmi_frm_proc_struct *proc);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_con_is_completed
 * DESCRIPTION
 *  To query whether a procedure is completed or not in a complete query
 *  function.
 * PARAMETERS
 *  instance        : [IN] Instance handler given in the complete info.
 *  child_id        : [IN] Child ID to be queried.
 * RETURNS
 *  Completed or not.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_proc_con_is_completed(
                    mmi_frm_proc_instance_handle instance,
                    mmi_frm_proc_id child_id);

/*****************************************************************************
 * <GROUP Procedure>
 *
 * FUNCTION
 *  mmi_frm_proc_con_create_and_execute
 * DESCRIPTION
 *  Entry function of a procedure. This function will create a concurrent
 *  procedure for the passed-in table(user_data). It is used to be the entry
 *  function an entry of a static procedure table. For example, <code>
 *  { MMI_FRM_PROC_ID_CON_PROC, con_procs, mmi_frm_proc_con_create_and_execute }
 *  </code>
 *  The con_procs is pointer of mmi_frm_proc_con_proc_struct. Procedures
 *  in the set will be launched concurrently when this entry is triggered.
 * PARAMETERS
 *  user_data   : [IN] mmi_frm_proc_con_proc_struct: array of sub-procedures.
 *  id_info     : [IN] ID information should be passed to notify_completed
 * RETURNS
 *  Completed or not.
 * SEE ALSO
 *  mmi_frm_proc_con_proc_struct
 *****************************************************************************/
extern mmi_frm_proc_result_enum mmi_frm_proc_con_create_and_execute(
                                    void *arg,
                                    const mmi_frm_proc_id_info_struct id_info);


#define MMI_FRM_PROC_CON_DECLARE_BEGIN(proc_name) \
    static const mmi_frm_proc_struct proc_name##_table[] = {
    
#define MMI_FRM_PROC_CON_ENTRY(id, entry_func, arg) \
    { (id), (entry_func), (arg) },
    
#define MMI_FRM_PROC_CON_DECLARE_END(proc_name, status_callback, user_data) \
    }; \
    static const mmi_frm_proc_con_proc_struct proc_name = \
    { \
        (mmi_frm_proc_struct*)(proc_name##_table), \
        sizeof(proc_name##_table) / sizeof(proc_name##_table[0]), \
        (status_callback), \
        (user_data) \
    };
    
#endif /* __PROCEDURE_GPROT_H__ */


