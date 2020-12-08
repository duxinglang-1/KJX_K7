/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   int_timer.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of timer used by timer integration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_int.h"

#include "kal_public_api.h"        /* Basic data type */
#include "kal_internal_api.h"

#include "stacklib.h"           /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"
#include "stack_timer.h"        /* Stack timer */

#include "int_cmmn.h"

static event_scheduler *msf_evshed_ptr = NULL;

/*****************************************************************************
 * FUNCTION
 *  msf_start_timer
 * DESCRIPTION
 *  To set a event with event scheduler
 * PARAMETERS
 *  timeInterval        [IN]        timer interval
 *  timer_hdlr          [IN]        tiemr expiry handler
 *  event_param         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void *mms_start_timer(MSF_UINT32 timeInterval, kal_timer_func_ptr timer_hdlr, void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 tick_interval;
    eventid event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tick_interval = kal_milli_secs_to_ticks(timeInterval * 100);
    
    event_id = evshed_set_event(msf_evshed_ptr, (kal_timer_func_ptr) timer_hdlr, event_param, tick_interval);

    return (void*)event_id;
}


/*****************************************************************************
 * FUNCTION
 *  mms_stop_timer
 * DESCRIPTION
 *  To cancel a event with event scheduler
 * PARAMETERS
 *  p       [IN]        event id
 * RETURNS
 *  void
 *****************************************************************************/
void mms_stop_timer(void **p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eventid *event_id = (eventid*) p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the is Timer Not Running it is not stopped */
    if (event_id && evshed_events_pending(msf_evshed_ptr))
    {
        evshed_cancel_event(msf_evshed_ptr, event_id);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mms_timer_expiry_hdlr
 * DESCRIPTION
 *  handler for timer expiry event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_timer_expiry_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evshed_timer_handler(msf_evshed_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  init_mms_timer
 * DESCRIPTION
 *  Initialize base stack timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void init_mms_timer(void)
{
    if(msf_evshed_ptr == NULL)
    {
    /* Create an Event Scheduler */
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
	   msf_evshed_ptr = evshed_create("MMS_MSF_TIMER", MOD_MMS, 0, 0);
#else
	   msf_evshed_ptr = evshed_create("MMS_MSF_TIMER", MOD_WAP, 0, 0);
#endif
       evshed_set_index(msf_evshed_ptr, MSF_MSM_TIMER_ID);
    }
}
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  MSM_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool deinit_mms_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Delete all the pending events and the event scheduler */
    evshed_delete_all_events(msf_evshed_ptr);
    return KAL_TRUE;
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
