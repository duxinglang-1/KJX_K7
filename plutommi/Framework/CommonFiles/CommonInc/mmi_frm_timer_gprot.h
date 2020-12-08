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
 *  mmi_frm_timer_gprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI Timer header file.
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
#ifndef MMI_FRM_TIMER_GPROT_H
#define MMI_FRM_TIMER_GPROT_H

#ifndef MMI_TIMER_INT_H
#define MMI_TIMER_INT_H

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMIDataType.h"
#include "kal_public_defs.h"
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/
typedef enum
{
	/* This align MMI timer, which is the coarse timer */
	TIMER_IS_ALIGNMENT = 0,

	/* This is the non-align MMI timer, which is the precise timer */
	TIMER_IS_NO_ALIGNMENT,

	MMI_TIMER_NUMBER
} mmi_frm_timer_type_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    ilm_struct *expiry_msg;
} mmi_timer_event_struct;


/*****************************************************************************
 * FUNCTION
 *  StartTimer
 * DESCRIPTION
 *  This function is used to start an alignment timer. It takes in the Timer ID, 
 *  Duration and the Callback function as the parameters.
 * PARAMETERS
 *  timerid:         [IN]       MMI timer ID that needs define in enum MMI_TIMER_IDS. 
 *  delay:           [IN]       The duration time in ms, the duration should be times of 5 ms.
 *  funcPtr:         [IN]       The timer expiry function.
 * RETURNS
 *  void
 *****************************************************************************/
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);


/*****************************************************************************
 * FUNCTION
 *  StartTimerEx
 * DESCRIPTION
 *  This function is used to start an alignment timer. It takes in the Timer ID, Duration, 
 *  the Callback function, and the argument as the parameters. Note the Callback function¡¯s prototype is oslTimerFuncPtr.
 * PARAMETERS
 *  timerid:     [IN]  MMI timer ID that needs define in enum MMI_TIMER_IDS.      
 *  delay:       [IN]  The duration time in ms, the duration should be times of 5 ms.      
 *  funcPtr:     [IN]  Input	The timer expiry function.       
 *  arg:         [IN]  When calling timer expiry function, input the argument to be the param.
 * RETURNS
 *  void
 *****************************************************************************/
extern void StartTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimer
 * DESCRIPTION
 *  This function is used to start a non-alignment timer. 
 *  It takes in the Timer ID, Duration and the Callback function as the parameters.
 * PARAMETERS
 *  timerid:     [IN]  MMI timer ID that needs define in enum MMI_TIMER_IDS.       
 *  delay:       [IN]  The duration time in ms, the duration should be times of 5 ms.      
 *  funcPtr:     [IN]  The timer expiry function.      
 * RETURNS
 *  void
 *****************************************************************************/
extern void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr);


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimerEx
 * DESCRIPTION
 *  This function is used to start an non-alignment timer. It takes in the Timer ID, Duration, the Callback function, 
 *  and the argument as the parameters. Note the Callback function¡¯s prototype is oslTimerFuncPtr.
 * PARAMETERS
 *  timerid:     [IN]    MMI timer ID that needs define in enum MMI_TIMER_IDS.    
 *  delay:       [IN]    The duration time in ms, the duration should be times of 5 ms.    
 *  funcPtr:     [IN]    The timer expiry function.
 *  argument:    [IN]    When calling timer expiry function, input the argument to be the param.
 * RETURNS
 *  void
 *****************************************************************************/
extern void StartNonAlignTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);


/*****************************************************************************
 * FUNCTION
 *  StopTimer
 * DESCRIPTION
 *  This function is used to kill an alignment timer. It takes in the Timer ID as one of the parameters.
 * PARAMETERS
 *  timerid:     [IN] MMI timer ID that needs define in enum MMI_TIMER_IDS.       
 * RETURNS
 *  void
 *****************************************************************************/
extern void StopTimer(U16 timerid);


/*****************************************************************************
 * FUNCTION
 *  IsMyTimerExist
 * DESCRIPTION
 *  This function is used to check MMI timer is running.
 * PARAMETERS
 *  nTimerId:        [IN]   MMI timer ID that needs define in enum MMI_TIMER_IDS.     
 * RETURNS
 *  If the timer is existed.
 * RETURN VALUES
 *  MMI_TRUE: The timer ID started
 *  MMI_FALSE: The timer ID doesn¡¯t start.
 *****************************************************************************/
extern MMI_BOOL IsMyTimerExist(U16 nTimerId);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_align_base_timer
 * DESCRIPTION
 *  Is the given base timer an alignment one.
 * PARAMETERS
 *  base_timer_ptr:        [IN]    ilm message
 * RETURNS
 *  TIMER_IS_ALIGNMENT (MMI_TRUE) or TIMER_IS_NO_ALIGNMENT (MMI_FALSE).
 * RETURN VALUES
 *  MMI_TRUE: TIMER is align.
 *  MMI_FALSE:TIMER is not align.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_is_align_base_timer(void *ilm_ptr);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_timers
 * DESCRIPTION
 *  Suspend all timers of given type
 * PARAMETERS
 *  type  [IN]:      The timer type: TIMER_IS_NO_ALIGNMENT or TIMER_IS_ALIGNMENT.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_suspend_timers(U32 type);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resume_timers
 * DESCRIPTION
 *  Resume all timers of given type
 * PARAMETERS
 *  type:  [IN]      The timer type: TIMER_IS_NO_ALIGNMENT or TIMER_IS_ALIGNMENT.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_resume_timers(U32 type);


/*****************************************************************************
 * FUNCTION
 *  L4SetClockRSP
 * DESCRIPTION
 *  This function is to get to the result of clock set response.
 * PARAMETERS
 *  buf:    [IN]  Local parameter of RTC timer rsp msg         
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4SetClockRSP(void *buf);


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTime
 * DESCRIPTION
 *  This function is to request to get the clock.
 * PARAMETERS
 *  FuncRspPtr:   [IN] Rsp handler for this request.        
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4GetClockTime(oslTaskFuncPtr FuncRspPtr);


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTimeRSP
 * DESCRIPTION
 *  This function is to receive the clock response.
 * PARAMETERS
 *  buf:         [IN]    Local parameter of RTC timer rsp msg.          
 * RETURNS
 *  void
 *****************************************************************************/
extern void L4GetClockTimeRSP(void *buf);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_all_timer
 * DESCRIPTION
 *  This function is used to stop all MMI timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_stop_all_timer(void);
/* DOM-NOT_FOR_SDK-END */

#endif /* MMI_TIMER_INT_H */
#endif /* MMI_FRM_TIMER_GPROT_H */


