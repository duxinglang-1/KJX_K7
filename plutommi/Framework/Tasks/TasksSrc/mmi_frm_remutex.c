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
 *    mmi_frm_remutex.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Recursive mutex mechanism
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_frm_remutex_gprot.h"
#include "MMI_trc_int.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"


extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32 x);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_init
 * DESCRIPTION
 *  Recursive mutex intialize.
 * PARAMETERS
 *  mutex       [IN]       the mutex that needs to create.
 *  pattern     [IN]       mutex name.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_recursive_mutex_init(mmi_frm_recursive_mutex_struct *mutex, S8 *mutex_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mutex->mutexID)
    {
        mutex->mutexID = kal_create_mutex(mutex_name);
        mutex->ref_count = 0;
        mutex->taskid = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_lock
 * DESCRIPTION
 *  get the recursive mutex.
 * PARAMETERS
 *  The mutex
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_recursive_mutex_lock(mmi_frm_recursive_mutex_struct *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_taskid taskID;
    kal_uint32 save_irq_mask;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mutex || (mutex->mutexID == 0))
    {
        MMI_ASSERT(0);
    }
    taskID = kal_get_task_self_id();

    
    if (mutex->taskid != taskID)
    {
        kal_take_mutex(mutex->mutexID);
        MMI_ASSERT(mutex->ref_count == 0);
        save_irq_mask = SaveAndSetIRQMask();
        mutex->ref_count++;
        mutex->taskid = taskID;
        RestoreIRQMask(save_irq_mask);
    }
    else
    {   
        MMI_ASSERT(mutex->ref_count >= 1);
        save_irq_mask = SaveAndSetIRQMask();
        mutex->ref_count++;
        RestoreIRQMask(save_irq_mask);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_recursive_mutex_unlock
 * DESCRIPTION
 *  release the recursive mutex.
 * PARAMETERS
 *  The mutex.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_recursive_mutex_unlock(mmi_frm_recursive_mutex_struct *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_taskid taskID;
    kal_uint32 save_irq_mask;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mutex || (mutex->mutexID == 0))
    {
        MMI_ASSERT(0);
    }    
    taskID = kal_get_task_self_id();
    if (mutex->ref_count > 1)
    {
        MMI_ASSERT(taskID == mutex->taskid);
        save_irq_mask = SaveAndSetIRQMask();
        mutex->ref_count--;
        RestoreIRQMask(save_irq_mask);        
    }
    else
    {
       
        save_irq_mask = SaveAndSetIRQMask();
        mutex->ref_count--;
        mutex->taskid = NULL;
        RestoreIRQMask(save_irq_mask);  
        MMI_ASSERT(0 == mutex->ref_count); 
        kal_give_mutex(mutex->mutexID);
    }    
}

#ifdef MMI_FRM_RECURSIVE_MUTEX_UT
static mmi_frm_recursive_mutex_struct g_mmi_frm_recursive_mutex_ut;
static kal_taskid g_mmi_taskid;

static void mmi_frm_recursive_mutex_ut_init(void)
{
    mmi_frm_recursive_mutex_init(&g_mmi_frm_recursive_mutex_ut, "mutex_ut");
    g_mmi_taskid = kal_get_task_self_id();
}


void mmi_frm_recursive_mutex_ut_take(void)
{
    mmi_frm_recursive_mutex_lock(&g_mmi_frm_recursive_mutex_ut);
}

void mmi_frm_recursive_mutex_ut_give(void)
{
    mmi_frm_recursive_mutex_unlock(&g_mmi_frm_recursive_mutex_ut); 
}

void mmi_frm_recursive_mutex_ut_in_one_task(void)
{
    mmi_frm_recursive_mutex_ut_init();
    mmi_frm_recursive_mutex_ut_take();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.taskid == g_mmi_taskid);
    mmi_frm_recursive_mutex_ut_take();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 2);
    mmi_frm_recursive_mutex_ut_give();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 1);
    mmi_frm_recursive_mutex_ut_give();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 0);
    mmi_frm_recursive_mutex_ut_take();
    mmi_frm_recursive_mutex_ut_give();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 0);
    mmi_frm_recursive_mutex_ut_take();
    mmi_frm_recursive_mutex_ut_give();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 0);
    mmi_frm_recursive_mutex_ut_take();
    mmi_frm_recursive_mutex_ut_take();
    mmi_frm_recursive_mutex_ut_give();
    mmi_frm_recursive_mutex_ut_take();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 2);
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.taskid == g_mmi_taskid);
    mmi_frm_recursive_mutex_ut_give();
    MMI_ASSERT(g_mmi_frm_recursive_mutex_ut.ref_count == 1);
    mmi_frm_recursive_mutex_ut_give();
    

}
#endif





