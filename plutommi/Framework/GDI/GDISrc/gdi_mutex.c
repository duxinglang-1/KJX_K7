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
 * Filename:
 * ---------
 *  gdi_mutex.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "gdc_include.h"

#if defined(GDI_MUTEX_DEBUG) && defined(__MTK_TARGET__)
    //#define GDI_MUTEX_DEBUG_DUMP_STACK
#endif /* GDI_MUTEX_DEBUG */ 

/* extern void* TCD_Current_Thread; */
extern kal_uint8 INT_Exception_Enter;
extern void INT_ExceptionDumpStack(long *dumpbuf, long *current_thread);

#include "drv_comm.h"
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMIDataType.h"

#include "gdi_mutex.h"
#include "gdi_primitive.h"
#include "gdi_image.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "intrCtrl.h"


/* global mutex variable */
#if defined(__MTK_TARGET__)
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif 

#define GDI_MUTEX_GUARD_PATTERN 0x87654321

gdi_mutex_struct gdi_mutex = {GDI_MUTEX_GUARD_PATTERN,0,NULL,0,GDI_MUTEX_GUARD_PATTERN};
// int gdi_mutex_serial = 0;

#if defined(__MTK_TARGET__)
#pragma arm section rwdata, rodata , zidata
#endif 

#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
long gdi_mutex_stack_backup[120];
#endif 
/* ///////////////////////////////////////////////////////////////////////////////////////////////////// */


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  m       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_init(gdi_mutex_struct *m)
{
    m->cnt = 0;
    m->tid = NULL;
    m->front_guard = GDI_MUTEX_GUARD_PATTERN;
    m->rear_guard = GDI_MUTEX_GUARD_PATTERN;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_lock(gdi_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 save_irq_mask;
    kal_taskid gdi_current_thread_id = kal_get_current_thread_ID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INT_Exception_Enter)
    {
        return;
    }
    if (gdi_current_thread_id == NULL)
    {
        return;
    }

    if (gdi_current_thread_id != M->tid)
    {
        /* wait gdi mutex free */
        while (1)
        {
            save_irq_mask = SaveAndSetIRQMask();
            if (M->cnt == 0)
            {
                M->cnt = 1;
                RestoreIRQMask(save_irq_mask);
                break;
            }
            RestoreIRQMask(save_irq_mask);
            kal_sleep_task(1);  /* waiting */
        }

        /* get gdi mutex */

        GDI_GET_RETURN_ADDRESS(M->lr);
        M->tid = gdi_current_thread_id;
        // gdi_mutex_serial++;
    #ifdef GDI_MUTEX_DEBUG_DUMP_STACK
        /* Store Stack Status when gdi mutex lock */
        INT_ExceptionDumpStack(gdi_mutex_stack_backup, (long*)gdi_current_thread_id);
    #endif /* GDI_MUTEX_DEBUG */ 
    }
    else
    {
        ++(M->cnt);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  M       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_mutex_unlock(gdi_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_taskid gdi_current_thread_id = kal_get_current_thread_ID();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (INT_Exception_Enter)
    {
        return;
    }

    if (gdi_current_thread_id != NULL)
    {
        GDI_DEBUG_ASSERT(M->tid == gdi_current_thread_id);

        if (M->cnt == 1)
        {
            M->tid = NULL;
        }
        --M->cnt;

    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_mutex_get_count
 * DESCRIPTION
 *  get count of the mutex
 * PARAMETERS
 *  M       [IN]     
 * RETURNS
 *  S32     the count of the mutex
 *****************************************************************************/
S32 gdi_mutex_get_count(gdi_mutex_struct *M)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return M->cnt;
}


#if defined(__MTK_TARGET__)
#pragma arm section code = "INTERNCODE"
#endif 


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_fast_mutex_lock(void)
{
    kal_taskid gdi_current_thread_id;
    U32 save_irq_mask;

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */ 

    if (INT_Exception_Enter)
        return;

    if ((gdi_current_thread_id = kal_get_current_thread_ID()) != NULL)
    {
        if (gdi_current_thread_id != gdi_mutex.tid)
        {
            save_irq_mask = SaveAndSetIRQMask();
            if(gdi_mutex.tid == gdc_thread_id) // Is current GDI user GDC task ( non-blocking task ) ?
            {
                /* if nb is set as high priority or begin aborted too many times, don't abort the nb decoding. */
                if((!gdi_nb_is_high_priority()) && (!gdc_reach_max_force_abort_count()))   
                {
                    gdi_image_set_abort(TRUE); // Force abort non-blocking job
                }
            }

            /* wait gdi mutex free */
            while (gdi_mutex.cnt)
            {
                RestoreIRQMask(save_irq_mask);
                kal_sleep_task(1);  /* waiting */
                save_irq_mask = SaveAndSetIRQMask();
            }
            GDI_GET_RETURN_ADDRESS(gdi_mutex.lr);
            gdi_mutex.cnt = 1;
            gdi_mutex.tid = gdi_current_thread_id;
            // gdi_mutex_serial++;

            gdi_image_set_abort(FALSE); // disable force abort, because we had got the mutex

    		#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
    		//Store Stack Status when gdi mutex lock
    		INT_ExceptionDumpStack(gdi_mutex_stack_backup,(long*)gdi_current_thread_id);
    		#endif // GDI_MUTEX_DEBUG
            RestoreIRQMask(save_irq_mask);
        }
        else
        {
            ++(gdi_mutex.cnt);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_lock_internal
 * DESCRIPTION
 *  gdi_fast_mutex_lock with the parameter to_wait
 *  if to_wait is false, it won't wait the mutex if it can't get the mutex immediately 
 * PARAMETERS
 *  to_wait [IN]
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_fast_mutex_lock_internal(MMI_BOOL to_wait)
{
    S32 ret = GDI_SUCCEED;
    kal_taskid gdi_current_thread_id;
    U32 save_irq_mask;

#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */ 

    if (INT_Exception_Enter)
        return ret;

    save_irq_mask = SaveAndSetIRQMask();
    do
    {
        if ((gdi_current_thread_id = kal_get_current_thread_ID()) != NULL)
        {
            if (gdi_current_thread_id != gdi_mutex.tid)
            {
                if(gdi_mutex.tid == gdc_thread_id) // Is current GDI user GDC task ( non-blocking task ) ?
                {
                    /* if nb is set as high priority or begin aborted too many times, don't abort the nb decoding. */
                    if((!gdi_nb_is_high_priority()) && (!gdc_reach_max_force_abort_count()))   
                    {
                        gdi_image_set_abort(TRUE); // Force abort non-blocking job
                    }
                }
                
                if (to_wait)
                {
                    /* wait gdi mutex free */
                    while (gdi_mutex.cnt)
                    {
                        RestoreIRQMask(save_irq_mask);
                        kal_sleep_task(1);  /* waiting */
                        save_irq_mask = SaveAndSetIRQMask();
                    }
                }
                else
                {
                    if (gdi_mutex.cnt > 0)
                    {
                        ret = GDI_FAILED;
                        break;
                    }
                }
                
                gdi_mutex.cnt = 1;
                gdi_mutex.tid = gdi_current_thread_id;
                // gdi_mutex_serial++;

                gdi_image_set_abort(FALSE); // disable force abort, because we had got the mutex

        		#ifdef GDI_MUTEX_DEBUG_DUMP_STACK
        		//Store Stack Status when gdi mutex lock
        		INT_ExceptionDumpStack(gdi_mutex_stack_backup,(long*)gdi_current_thread_id);
        		#endif // GDI_MUTEX_DEBUG
            }
            else
            {
                ++(gdi_mutex.cnt);
            }
        }
    }while(0);
    RestoreIRQMask(save_irq_mask);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_lock_no_wait
 * DESCRIPTION
 *  the same with gdi_fast_mutex_lock 
 *  but it won't wait the mutex if it can't get the mutex immediately
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_fast_mutex_lock_no_wait(void)
{
    return gdi_fast_mutex_lock_internal(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_fast_mutex_unlock(void)
{
    kal_taskid gdi_current_thread_id;

    /* kal_taskid gdi_current_thread_id = kal_get_current_thread_ID(); */

    if (INT_Exception_Enter)
        return;

    gdi_current_thread_id = kal_get_current_thread_ID();
    if (gdi_current_thread_id != NULL)
    {
        GDI_DEBUG_ASSERT(gdi_mutex.tid == gdi_current_thread_id);

        if (gdi_mutex.cnt == 1)
        {
            gdi_mutex.tid = NULL;
        }
        --gdi_mutex.cnt;
    }

}

#ifdef __MTK_TARGET__
#pragma arm section code
#endif 

BOOL gdi_fast_mutex_is_owner(void)
{
    BOOL ret;
    U32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
        ret = (gdi_mutex.tid == kal_get_current_thread_ID());
    RestoreIRQMask(save_irq_mask);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_fast_mutex_get_count
 * DESCRIPTION
 *  get count of the gdi_mutex
 * PARAMETERS
 *  M       [IN]     
 * RETURNS
 *  S32     the count of the gdi_mutex
 *****************************************************************************/
S32 gdi_fast_mutex_get_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_mutex.cnt;
}

