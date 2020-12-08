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
 *  MMITimer.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI Timer.
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

/*  Include: MMI header file */
#include "MMI_features.h"
#include "mmi_frm_prot.h"
#include "kal_internal_api.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_timer_gprot.h"
#include "ps_public_struct.h"
#include "app_ltlcom.h"
#include "mmi_msg_struct.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stack_msgs.h"
#include "device.h"
#include "stack_common.h"
#include "task_config.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "TimerEvents.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmiapi_func.h"
#include "mmi_cb_mgr_gprot.h"
#include "GlobalResDef.h"

/*****************************************************************************
* Define                                                                      
*****************************************************************************/ 

/* the recommended value: 12 or 24 */
#define SIMULTANEOUS_TIMER_NUM         (24)

/* ticks of 20 millisecond. because KAL did not define the value. define in floating falue to avoid early rouning */
#define MMI_TICKS_20_MSEC  (KAL_TICKS_1_SEC/50.0)

/* ticks of 5 millisecond. because KAL did not define the value. define in floating falue to avoid early rouning */
#define MMI_TICKS_5_MSEC  (KAL_TICKS_1_SEC/200.0)

#define TIMER_INDEX (0x10)
/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/

/* 
 * MTK added for two kinds of timer, one is for exactly time, another allow to delay.
 * TO Pixtel, This two defines should move to a proper place where 
 * can be used by other files.
 */

typedef struct {
	U16 timer_type;
    U16 timer_id;     /* timer info. */
    eventid event_id;   /* event_id returned from evshed_set_event() */
    oslTimerFuncPtr callback_func;  /* timer_expiry_func */
    void* arg;
} mmi_frm_timer_type;


typedef struct timertable
{
    mmi_frm_timer_type tm[SIMULTANEOUS_TIMER_NUM];  /* timer items */
    struct timertable *next;    /* point to the next TIMERTABLE data */
} TIMERTABLE;


/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/

/*
 * In most case, the timers won't run simultaneously.
 * We run-time allocate the memory to store the timer information. 
 */
static TIMERTABLE g_timer_table = {0};
static U16 g_timer_table_size = 0;
static U16 g_timer_table_used = 0;

static oslTaskFuncPtr get_clocktime_callback_func;
static oslTaskFuncPtr set_clocktime_callback_func;

/* 
 * MTK added for two kinds of timer, one is for exactly time, another allow to delay.
 */
static event_scheduler *event_scheduler_ptr[MMI_TIMER_NUMBER];

static void L4StartTimer(
        U16 nTimerId,
        oslTimerFuncPtr TimerExpiry,
        void *funcArg,
        U32 nTimeDuration,
        U16 alignment);

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/
extern void McfBaseTimerExpireProcess(void *basetimer);

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

//#define __MMI_FRM_TIMER_UNIT_TEST__

#ifdef __MMI_FRM_TIMER_UNIT_TEST__
static void mmi_frm_ut_timer(void);
static void mmi_frm_ut_align_timer(void *p);
static void mmi_frm_ut_nonalign_timer(void *p);
#endif /* __MMI_FRM_TIMER_UNIT_TEST__ */

static void L4CallBackTimer(void *p);
static void L4StopTimer(U16 nTimerId);
static void StartTimerCommon(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg,
							mmi_frm_timer_type_enum timer_type);



/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/
/*****************************************************************************
* FUNCTION
*	StartTimerCommon
* DESCRIPTION
*	This is used to set a timer
* PARAMETERS
*	timerid 		[IN]		
*	delay		[IN]		
*	funcPtr 		[IN]
*	  arg			[IN]
*	  need_arg		[IN]
*	  timer_type	[IN]
* RETURNS
*	void
*****************************************************************************/
	
static void StartTimerCommon(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg,
								mmi_frm_timer_type_enum timer_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	L4StopTimer(timerid);
	L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, (void *)arg, delay, timer_type);
}

/*****************************************************************************
 * FUNCTION
 *  StartTimer
 * DESCRIPTION
 *  This is used to set a timer
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_START_ALIGN_TIMER, timerid, delay, funcPtr);
    //L4StopTimer(timerid);
    //L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
    //                (void *)timerid, delay, TIMER_IS_ALIGNMENT);
    StartTimerCommon(timerid, delay, (oslTimerFuncPtr)funcPtr, (void*)timerid, TIMER_IS_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartTimerEx
 * DESCRIPTION
 *  This is used to set a timer with the argument
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 *  arg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void StartTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_START_ALIGN_TIMER_EX, timerid, delay, funcPtr, arg);
    //L4StopTimer(timerid);
    //L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
    //                (void *)arg, delay, TIMER_IS_ALIGNMENT);
    StartTimerCommon(timerid, delay, funcPtr, arg, TIMER_IS_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimer
 * DESCRIPTION
 *  start a non-alignment timer
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StartNonAlignTimer(U16 timerid, U32 delay, FuncPtr funcPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_START_NON_ALIGN_TIMER, timerid, delay, funcPtr);
    //L4StopTimer(timerid);
    //L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
    //                (void *)timerid, delay, TIMER_IS_NO_ALIGNMENT);
    StartTimerCommon(timerid, delay, (oslTimerFuncPtr)funcPtr, (void*)timerid, TIMER_IS_NO_ALIGNMENT);
}


/*****************************************************************************
 * FUNCTION
 *  StartNonAlignTimerEx
 * DESCRIPTION
 *  start a non-alignment timer with the argument
 * PARAMETERS
 *  timerid     [IN]        
 *  delay       [IN]        
 *  funcPtr     [IN]        
 *  argument    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void StartNonAlignTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_START_NON_ALIGN_TIMER_EX, timerid, delay, funcPtr, arg);
    //L4StopTimer(timerid);
    //L4StartTimer(timerid, (oslTimerFuncPtr)funcPtr, 
    //                (void *)arg, delay, TIMER_IS_NO_ALIGNMENT);
    StartTimerCommon(timerid, delay, funcPtr, arg, TIMER_IS_NO_ALIGNMENT);
}

/*****************************************************************************
 * FUNCTION
 *  StopTimer
 * DESCRIPTION
 *  This is used to reset a timer
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void StopTimer(U16 timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_STOP_TIMER, timerid);
    L4StopTimer(timerid);
    if (mmiapi_is_MMI_task())
    {
        mmi_frm_fetch_msg_from_extQ_to_circularQ();
        /*
            if (OslLookUpLastCircularQMsg((void*)&Message))
            {
                if (MSG_ID_TIMER_EXPIRY == Message.msg_id)
                {
	            mmi_frm_fetch_msg_from_extQ_to_circularQ();
	        }
	    }
	    */
    }
}


/*****************************************************************************
 * FUNCTION
 *  EvshedMMITimerHandler
 * DESCRIPTION
 *  MMI Timer Event Scheduler
 * PARAMETERS
 *  dataPtr     [IN]        Data from L4
 * RETURNS
 *  void
 *****************************************************************************/
void EvshedMMITimerHandler(void *dataPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	MMI_BOOL is_applib_timer = MMI_TRUE;
    kal_uint16 timer_index = evshed_get_index((ilm_struct*)dataPtr);
    mmi_timer_event_struct timer_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_TIMER_NUMBER; i++)
	{
		if (timer_index == (TIMER_INDEX+i))
		{
		    evshed_timer_handler(event_scheduler_ptr[i]);
            return;
		}
	}
    
    if (is_applib_timer)
    {
        extern void applib_timer_hdlr(stack_timer_struct *timer_ptr);
        applib_timer_hdlr((stack_timer_struct*)(((ilm_struct*)dataPtr)->local_para_ptr));
    }

    MMI_FRM_INIT_EVENT(&timer_event, EVT_ID_MMI_TIMER_EXPIRY_PROC_EXT);
    timer_event.expiry_msg = (ilm_struct *)dataPtr;
    MMI_FRM_CB_EMIT_EVENT(&timer_event);

    #if defined( __MCAREV30__) ||defined(__MCARE_COMMON__)
      McfBaseTimerExpireProcess((stack_timer_struct*)(((ilm_struct*)dataPtr)->local_para_ptr));
    #endif

}


/*****************************************************************************
 * FUNCTION
 *  L4SetClock
 * DESCRIPTION
 *  This function is to set the clock request.
 * PARAMETERS
 *  datetime        [IN]        
 *  FuncRspPtr      [IN]        
 *  a(?)            [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4SetClock(rtc_format_struct datetime, oslTaskFuncPtr FuncRspPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_eq_set_rtc_time_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the set time clock callback function */
    set_clocktime_callback_func = FuncRspPtr;

    local_data = (mmi_eq_set_rtc_time_req_struct*)
        construct_local_para(sizeof(mmi_eq_set_rtc_time_req_struct), TD_CTRL);

    local_data->set_type = RTC_SETTING_TYPE_DATETIME;
    local_data->rtc_type = RTC_TIME_CLOCK_IND;
    local_data->info.alarm_format = 0;
    local_data->info.alarm_index = 0;
    local_data->info.type = 0;
    local_data->info.text[0] = '\0';
    local_data->info.recurr = 0;
    local_data->info.data_time.rtc_year = datetime.rtc_year;
    local_data->info.data_time.rtc_wday = datetime.rtc_wday;
    local_data->info.data_time.rtc_mon = datetime.rtc_mon;
    local_data->info.data_time.rtc_day = datetime.rtc_day;
    local_data->info.data_time.rtc_hour = datetime.rtc_hour;
    local_data->info.data_time.rtc_min = datetime.rtc_min;
    local_data->info.data_time.rtc_sec = datetime.rtc_sec;

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_RTC_TIME_REQ, (oslParaType*)local_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  L4SetClockRSP
 * DESCRIPTION
 *  This function is to get to the result of clock set response.
 * PARAMETERS
 *  buf         [?]         
 *  a(?)        [IN]        Buf
 * RETURNS
 *  void
 *****************************************************************************/
void L4SetClockRSP(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set_clocktime_callback_func != NULL)
    {
        set_clocktime_callback_func(buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTime
 * DESCRIPTION
 *  This function is to request to get the clock.
 * PARAMETERS
 *  FuncRspPtr      [IN]        
 *  a(?)            [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4GetClockTime(oslTaskFuncPtr FuncRspPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_get_rtc_time_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store the get time clock callback function */
    get_clocktime_callback_func = FuncRspPtr;
    
    local_data = (mmi_eq_get_rtc_time_req_struct*)
        construct_local_para(sizeof(mmi_eq_get_rtc_time_req_struct), TD_CTRL);
    local_data->rtc_type = RTC_TIME_CLOCK_IND;

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_GET_RTC_TIME_REQ, (oslParaType*)local_data, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  L4GetClockTimeRSP
 * DESCRIPTION
 *  This function is to receive the clock response.
 * PARAMETERS
 *  buf         [?]         
 *  a(?)        [IN]        Buf
 * RETURNS
 *  void
 *****************************************************************************/
void L4GetClockTimeRSP(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_clocktime_callback_func != NULL)
    {
        get_clocktime_callback_func(buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  L4InitTimer
 * DESCRIPTION
 *  This function is to init the timer while task create.
 * PARAMETERS
 *  void
 *  a(?)        [IN]        Void
 * RETURNS
 *  void
 *****************************************************************************/
void L4InitTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
	U8 max_delay[MMI_TIMER_NUMBER] = {254, 0};
	CHAR *timer_name[MMI_TIMER_NUMBER] = {"MMI_a", "MMI_na"};
	mmi_timer_event_struct timer_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset g_timer_talbe */
    g_timer_table_size = SIMULTANEOUS_TIMER_NUM;

    for (i = 0; i < MMI_TIMER_NUMBER; i++)
    {
        event_scheduler_ptr[i] = evshed_create(timer_name[i], MOD_MMI, 0, max_delay[i]);
        evshed_set_index(event_scheduler_ptr[i], (TIMER_INDEX+i));
    }

#ifdef __MMI_FRM_TIMER_UNIT_TEST__	 
    mmi_frm_ut_timer();
#endif /* __MMI_FRM_TIMER_UNIT_TEST__ */

    MMI_FRM_INIT_EVENT(&timer_event, EVT_ID_MMI_TIMER_INIT_EXT);
    MMI_FRM_CB_EMIT_EVENT(&timer_event);


}


/*****************************************************************************
 * FUNCTION
 *  L4StartTimer
 * DESCRIPTION
 *  This function is to start timer. To added for two kinds of timer, 
 *  one is for exactly time, another allow to delay.
 * PARAMETERS
 *  nTimerId            [IN]        timer id 
 *  TimerExpiry         [IN]        timer expiry callback function
 *  funcArg             [IN]        argument for expiry callback function 
 *  nTimeDuration       [IN]        timeout value
 *  alignment           [IN]        alignment/non-alignment attribute
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StartTimer(
        U16 nTimerId,
        oslTimerFuncPtr TimerExpiry,
        void *funcArg,
        U32 nTimeDuration,
        U16 alignment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = NULL;
    U16 i = 0;
    U32 temp = 0, sec = 0, milli_secs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(TimerExpiry);


/*
    if (nTimeDuration == 1000)
    {
        temp = KAL_TICKS_1_SEC - 4;
    }
    else
    {
        temp = (U32)((nTimeDuration / 5) * MMI_TICKS_5_MSEC);
    }
*/    
    sec = nTimeDuration / 1000;
    milli_secs = nTimeDuration % 1000;

    if(sec > 0)
        temp = kal_secs_to_ticks(sec);
    if(milli_secs > 0)
        temp += kal_milli_secs_to_ticks(milli_secs);

    if (temp == 0)
    {
        /* Cause by by rounding. If expire immediately, MoDIS boot-up failure because MMI keeps running and block NVRAM task */
        temp = (U32)MMI_TICKS_5_MSEC;
    }


    pTable = &g_timer_table;
    if (g_timer_table_used >= g_timer_table_size)
    {
        /*
         * TIMERTABLE list doesn't have enough space, allocate the memory 
         *
         * If we need to allocate the memeory, it means that MMI may have 
         * such many timers run simultaneously. We won't free the memory 
         * after we allocate more memory in TIMERTABLE list.
         */
        do
        {
            if (pTable->next == NULL)
            {
                pTable->next = OslMalloc(sizeof(TIMERTABLE));
                memset(pTable->next, 0, sizeof(TIMERTABLE));
                g_timer_table_size += SIMULTANEOUS_TIMER_NUM;
                pTable = pTable->next;
                i = 0;
                break;
            }
            pTable = pTable->next;
        } while (pTable != NULL);
    }
    else
    {
        /* find the empty record in g_timer_table list */
        i = 0;
        do
        {
            if (pTable->tm[i].event_id == NULL)
            {   /* find the empty space */
                break;
            }
            i++;
            if (i >= SIMULTANEOUS_TIMER_NUM)
            {
                pTable = pTable->next;
                i = 0;
            }
        } while (pTable != NULL);

        if (pTable == NULL)
        {
            /* Can't find the empty space in TIMERTABLE list, assert!!! */
            MMI_ASSERT(0);
        }
    }   /* if (g_timer_table_used >= g_timer_table_size) */



	pTable->tm[i].timer_type = alignment;
    pTable->tm[i].timer_id = nTimerId;
    pTable->tm[i].event_id = evshed_set_event(
                                event_scheduler_ptr[alignment],
                                (kal_timer_func_ptr) L4CallBackTimer,
                                (void*)&(pTable->tm[i]),
                                temp);
    pTable->tm[i].arg = funcArg;
    pTable->tm[i].callback_func = TimerExpiry;
    g_timer_table_used++;
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_align_base_timer
 * DESCRIPTION
 *  is the given base timer an alignment one
 * PARAMETERS
 *  ilm_ptr        [IN]        ilm message
 * RETURNS
 *  IMER_IS_ALIGNMENT (MMI_TRUE) or TIMER_IS_NO_ALIGNMENT (MMI_FALSE)
 *****************************************************************************/
MMI_BOOL mmi_frm_is_align_base_timer(void *ilm_ptr)
{
    U32 i;
    kal_uint16 timer_index = evshed_get_index((ilm_struct*)ilm_ptr);

    for (i = 0; i < MMI_TIMER_NUMBER; i++)
    {
        if (timer_index == (TIMER_INDEX+i))
        {
            break;
        }
    }

    return (mmi_frm_timer_type_enum)i == TIMER_IS_ALIGNMENT ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_timers
 * DESCRIPTION
 *  suspend all timers of given type
 * PARAMETERS
 *  type        [IN]        timer type (alignment or non-alignment)
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_suspend_timers(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_SUSPEND_TIMER, type);
	MMI_ASSERT(type < 2);
    evshed_suspend_all_events(event_scheduler_ptr[type]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_resume_timers
 * DESCRIPTION
 *  resume all timers of given type
 * PARAMETERS
 *  type        [IN]        timer type (alignment or non-alignment)
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_resume_timers(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_RESUME_TIMER, type);
    evshed_resume_all_events(event_scheduler_ptr[type]);
}


/*****************************************************************************
 * FUNCTION
 *  IsMyTimerExist
 * DESCRIPTION
 *  does the timer exist
 * PARAMETERS
 *  nTimerId        [IN]        
 * RETURNS
 *  timer exists or not
 *****************************************************************************/
MMI_BOOL IsMyTimerExist(U16 nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = &g_timer_table;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     do
     {
         if (pTable->tm[i].timer_id == nTimerId)
         {
            /* timer found */
            return MMI_TRUE;
         }
         i++;
         if (i >= SIMULTANEOUS_TIMER_NUM)
         {
             pTable = pTable->next;
             i = 0;
         }
     } while (pTable != NULL);
    
    return MMI_FALSE;
}


/***************************************************************************** 
* Local Function
*****************************************************************************/

#ifdef __MMI_FRM_TIMER_UNIT_TEST__

#define ALIGN_TEST_TIMEOUT      1000   /* ms */
#define NON_ALIGN_TEST_TIMEOUT  1100   /* ms */

#define ALIGN_TEST_TM_ID        65500
#define NON_ALIGN_TEST_TM_ID    65501

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_timer
 * DESCRIPTION
 *  timer unit-test
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_timer(void)
{
    /* unit test for non-alignment timer in NVRAM access */
	StartNonAlignTimer(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer);

    
    /* unit test for alignment timer in NVRAM access */
    StartTimer(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_nonalign_timer
 * DESCRIPTION
 *  timer callback for non-align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_nonalign_timer(void *p)
{
    static U32 pre_tick = 0;
	U32 current_tick;
	kal_get_time(&current_tick);
	kal_printf("\n[UT] mmi_frm_ut_nonalign_timer %f\n", (current_tick - pre_tick) * 5.0);
	if (IsInNVRAMProcedure())
    {
        kal_print("\n[UT] non-align timer works in nvram access\n");
    }
	StartNonAlignTimer(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer);
	pre_tick = current_tick;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_align_timer
 * DESCRIPTION
 *  timer callback for align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer(void *p)
{
	static U32 pre_tick = 0;
	U32 current_tick;
	kal_get_time(&current_tick);
	kal_printf("\n[UT] mmi_frm_ut_align_timer %f\n", (current_tick - pre_tick) * 5.0);
    if (IsInNVRAMProcedure())
    {
        kal_printf("[UT] align timer will die in nvram access\n");
        MMI_ASSERT(0);
    }
    else
    {
		StartTimer(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer);
    }
	pre_tick = current_tick;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_timer_with_arg
 * DESCRIPTION
 *  time unit-test:
 *  StartTimerEx(), StartNonAlignTimerEx(), StopTimer()
 * PARAMETERS
 *  tc          [IN]        test case id  
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer_with_arg(void *p);
static void mmi_frm_ut_nonalign_timer_with_arg(void *p);
void mmi_frm_ut_timer_with_arg(int tc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We could parser the string to execute the different actions. */
    switch(tc)
    {
        case 1:
            kal_printf("[Timer-UT] mmi_frm_ut_timer_with_arg : 1\n");
            StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)1);
            StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)110);
            /* add the code here */
            break;
        case 2:
            kal_printf("[Timer-UT] mmi_frm_ut_timer_with_arg : 2\n");
            StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)20);
            StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)220);

            /* add the code here */
            break;
        case 3:
            kal_printf("[Timer-UT] mmi_frm_ut_timer_with_arg : 3\n");
            StopTimer(ALIGN_TEST_TM_ID);
            StopTimer(NON_ALIGN_TEST_TM_ID);
            /* add the code here */
            break;
        default:
            /* add the code here */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_align_timer_with_arg
 * DESCRIPTION
 *  timer callback for align timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_align_timer_with_arg(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((int)p == 1)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (1)\n");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT/3, mmi_frm_ut_align_timer_with_arg, (void*)2);
    }
    else if ((int)p == 2)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (2)\n");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT*2/3, mmi_frm_ut_align_timer_with_arg, (void*)3);
    }
    else if ((int)p == 3)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (3) - finish\n");
    }
    else if ((int)p == 20)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (20)\n");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT, mmi_frm_ut_align_timer_with_arg, (void*)21);
    }
    else if ((int)p == 21)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_align_timer_with_arg timeout (21)\n");
        StartTimerEx(ALIGN_TEST_TM_ID, ALIGN_TEST_TIMEOUT/2, mmi_frm_ut_align_timer_with_arg, (void*)20);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_nonalign_timer_with_arg
 * DESCRIPTION
 *  timer callback for nonalign timer unit test
 * PARAMETERS
 *  timer id
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_nonalign_timer_with_arg(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((int)p == 110)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (110)\n");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT*2, mmi_frm_ut_nonalign_timer_with_arg, (void*)120);
    }
    else if ((int)p == 120)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (120) - finish\n");
    }
    else if ((int)p == 220)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (220)\n");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT/2, mmi_frm_ut_nonalign_timer_with_arg, (void*)221);
    }
    else if ((int)p == 221)
    {
        kal_printf("[Timer-UT] mmi_frm_ut_nonalign_timer_with_arg timeout (221)\n");
        StartNonAlignTimerEx(NON_ALIGN_TEST_TM_ID, NON_ALIGN_TEST_TIMEOUT, mmi_frm_ut_nonalign_timer_with_arg, (void*)220);
    }
}

#endif /* __MMI_FRM_TIMER_UNIT_TEST__ */


/*****************************************************************************
 * FUNCTION
 *  L4StopTimer
 * DESCRIPTION
 *  This function is to stop timer. 
 *  To added for two kinds of timer, one is for exactly time, another allow to delay.
 * PARAMETERS
 *  nTimerId        [IN]        
 *  a(?)            [IN]        NTimerId
 * RETURNS
 *  void
 *****************************************************************************/
static void L4StopTimer(unsigned short nTimerId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *pTable = &g_timer_table;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* find the nTimerId in TIMERTABLE list */
    do
    {
        if (pTable->tm[i].timer_id == nTimerId)
        {
            /* find the nTimerId */
            if (pTable->tm[i].event_id != NULL)
            {
				evshed_cancel_event(event_scheduler_ptr[pTable->tm[i].timer_type], &(pTable->tm[i].event_id));
                MMI_ASSERT(g_timer_table_used > 0);
                g_timer_table_used--;
                memset( &(pTable->tm[i]), 0, sizeof(mmi_frm_timer_type));
            }
            break;
        }
        i++;
        if (i >= SIMULTANEOUS_TIMER_NUM)
        {
            pTable = pTable->next;
            i = 0;
        }
    } while (pTable != NULL);
}


/*****************************************************************************
 * FUNCTION
 *  L4CallBackTimer
 * DESCRIPTION
 *  This function is to execute the timer expire.
 * PARAMETERS
 *  p           [IN]         pointer to timer item
 * RETURNS
 *  void
 *****************************************************************************/
static void L4CallBackTimer(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_timer_type *pTimer = (mmi_frm_timer_type *)p;
    U32 nTimerId = pTimer->timer_id;
    oslTimerFuncPtr pTimerExpiry = pTimer->callback_func;
    void * arg = pTimer->arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_TIMER_EXECUTE_TIMER_CALL_BACK, nTimerId, pTimerExpiry, arg);
    MMI_ASSERT(g_timer_table_used > 0);
    g_timer_table_used--;
    memset( pTimer, 0, sizeof(mmi_frm_timer_type)); /* clear timer */
    
    /*
     * we process g_timer_table_used, event_id and timer_id ... first 
     * because the user may call stoptimer() in the timer_expiry_func
     */

    if (pTimerExpiry)
    {
        pTimerExpiry((void *)arg);
    }
    /* Invoke post event */
    if (IsInNVRAMProcedure() == MMI_FALSE)
    {
        mmi_frm_invoke_post_event();
    }
    mmi_frm_fetch_msg_from_extQ_to_circularQ();
}


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
void mmi_frm_stop_all_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    TIMERTABLE *p;
    MMI_ID  timer_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &g_timer_table;
    while (p != NULL)
    {
        int i;
        for (i = 0; i < SIMULTANEOUS_TIMER_NUM; i++)
        {
            timer_id = p->tm[i].timer_id;
            StopTimer(timer_id);
        }
        p = p->next;
    }
}


