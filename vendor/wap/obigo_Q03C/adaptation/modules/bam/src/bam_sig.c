#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_sig.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Internal signal queue.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_sig.c
 *
 * Description:
 *   Internal signal queue.
 *
 */
#include "bam_sig.h"
#include "msf_def.h"
#include "msf_mem.h"

/************************************************************
 * Constants
 ************************************************************/
/* Max number of signal structs stored in the free list: */
#define BAM_SIG_MAX_FREE_LIST_LENGTH   5

/************************************************************
 * Global variables
 ************************************************************/

/* The global queue of signals to be delivered: */

static bam_signal_struct *bam_signal_queue_first;
static bam_signal_struct *bam_signal_queue_last;

/* List of available signal structs. This is used
   to reduce the number of allocations. */
static bam_signal_struct *bam_signal_free_list;
static int bam_signal_free_list_length;

/* The table of known destinations */
static bam_signal_function_t *bam_signal_func[BAM_SIG_NUM_OF_DESTINATIONS];

/************************************************************
 * Function declarations
 ************************************************************/

extern void bam_signal_process_external(bam_signal_struct *sig);

/************************************************************
 * Functions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_signal_init
 * DESCRIPTION
 *  Initialize the signal module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_signal_queue_first = bam_signal_queue_last = NULL;
    bam_signal_free_list = NULL;
    bam_signal_free_list_length = 0;

    for (i = 0; i < BAM_SIG_NUM_OF_DESTINATIONS; i++)
    {
        bam_signal_func[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_terminate
 * DESCRIPTION
 *  Terminate the signal module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_signal_struct *sig;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!bam_signal_queue_is_empty())
    {
        sig = bam_signal_queue_first;
        bam_signal_queue_first = sig->next;
        bam_signal_delete(sig);
    }

    while (bam_signal_free_list != NULL)
    {
        sig = bam_signal_free_list;
        bam_signal_free_list = sig->next;
        MSF_MEM_FREE(MSF_MODID_BAM, sig);
    }

    for (i = 0; i < BAM_SIG_NUM_OF_DESTINATIONS; i++)
    {
        bam_signal_func[i] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_process
 * DESCRIPTION
 *  Process the first signal in the signal queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_signal_struct *sig;
    bam_signal_function_t *func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sig = bam_signal_queue_first;

    if (sig != NULL)
    {
        bam_signal_queue_first = sig->next;

        if (bam_signal_queue_first == NULL)
        {
            bam_signal_queue_last = NULL;
        }

        if ((sig->dst >= 0) && (sig->dst < BAM_SIG_NUM_OF_DESTINATIONS) && ((func = bam_signal_func[sig->dst]) != NULL))
        {
            func(sig);
        }
        else
        {
            bam_signal_delete(sig);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_register_dst
 * DESCRIPTION
 *  Register the function "f" to be called when a signal
 *  is delivered to destination "dst".
 * PARAMETERS
 *  dst     [IN]
 *  f       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_register_dst(int dst, bam_signal_function_t *f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_signal_func[dst] = f;
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_deregister
 * DESCRIPTION
 *  Remove the registered function for destination "dst".
 * PARAMETERS
 *  dst     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_deregister(int dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_signal_func[dst] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_delete
 * DESCRIPTION
 *  Delete a signal.
 * PARAMETERS
 *  sig     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_delete(bam_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!sig)
    {
        return;
    }

    if (bam_signal_free_list_length < BAM_SIG_MAX_FREE_LIST_LENGTH)
    {
        sig->next = bam_signal_free_list;
        bam_signal_free_list = sig;
        bam_signal_free_list_length++;
    }
    else
    {
        MSF_MEM_FREE(MSF_MODID_BAM, sig);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_queue_is_empty
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  Return TRUE if the global signal queue is empty,
 *  FALSE otherwise.
 *****************************************************************************/
int bam_signal_queue_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_signal_queue_first == NULL;
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_sendto
 * DESCRIPTION
 *  Add a new signal to the end of the global queue.
 * PARAMETERS
 *  dst             [IN]
 *  signum          [IN]
 *  i_param1        [IN]
 *  i_param2        [IN]
 *  u_param1        [IN]
 *  u_param2        [IN]
 *  p_param         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_signal_sendto(
    int dst,
    int signum,
    long int i_param1,
    long int i_param2,
    unsigned long int u_param1,
    unsigned long int u_param2,
    void *p_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_signal_struct *sig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_signal_free_list == NULL)
    {
        sig = MSF_MEM_ALLOCTYPE(MSF_MODID_BAM, bam_signal_struct);

        if (sig == NULL)
        {
            MSF_MEM_FREE(MSF_MODID_BAM, p_param);
            return;
        }
    }
    else
    {
        sig = bam_signal_free_list;
        bam_signal_free_list = sig->next;
        bam_signal_free_list_length--;
    }

    sig->type = signum;
    sig->dst = dst;
    sig->i_param1 = i_param1;
    sig->i_param2 = i_param2;
    sig->u_param1 = u_param1;
    sig->u_param2 = u_param2;
    sig->p_param = p_param;

    sig->next = NULL;

    if (bam_signal_queue_last != NULL)
    {
        bam_signal_queue_last->next = sig;
        bam_signal_queue_last = sig;
    }
    else
    {
        bam_signal_queue_first = bam_signal_queue_last = sig;
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_signal_prepend
 * DESCRIPTION
 *  Add an old signal to the beginning of the queue.
 * PARAMETERS
 *  sig     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_signal_prepend(bam_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sig == NULL)
    {
        return;
    }

    sig->next = bam_signal_queue_first;

    if (bam_signal_queue_last == NULL)
    {
        bam_signal_queue_last = sig;
    }
    bam_signal_queue_first = sig;
}


#endif /*OBIGO_Q03C_BROWSER*/