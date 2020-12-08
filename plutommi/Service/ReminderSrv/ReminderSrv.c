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
 *  ReminderSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Reminder srvice impliment file.
 *
 * Author:
 * -------
 * -------
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

#include "app_datetime.h"

#include "mmi_rp_srv_reminder_def.h"

#include "BootupSrvGprot.h"
#include "DateTimeGprot.h"
#include "ReminderSrvGprot.h"
#include "ShutdownSrvGprot.h"

#include "ReminderSrv.h"
#include "ReminderSrvQueue.h"
#include "ReminderSrvUtil.h"
#include "nvram_common_defs.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#define SRV_REMINDER_INVALID_TYPE 			0xFFFFFFFF
#define SRV_REMINDER_TYPE_DISABLE(type)    (g_srv_remdr_cntx.disable_mask |= (1 << type))
#define SRV_REMINDER_TYPE_ENABLE(type) 	   (g_srv_remdr_cntx.disable_mask &= (~(1 << type)))
#define SRV_REMINDER_TYPE_IS_DISABLE(type) (g_srv_remdr_cntx.disable_mask & (1 << type))

#define POWER_OFF_TIMER_STAGE_1  12000
#define POWER_OFF_TIMER_STAGE_2  3000   // 5000 /* to align with mmi_shutdown_froce_terminate_display */

#define ALM_MAX_DELAY_ALLOWANCE  ((REMINDER_Q_TOTAL) / 2 + 1)       /* maximum delay of each alarm */
#define ALM_TOLERANCE_TIME       10000
#define POWER_OFF_TOLERANCE  	(POWER_OFF_TIMER_STAGE_1 + POWER_OFF_TIMER_STAGE_2 + ALM_TOLERANCE_TIME)
#define SRV_RMDR_MALLOC_MSG(type) ((type *)OslConstructDataPtr(sizeof(type)))

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct{
	srv_reminder_q_type *queue; 	/* Reminder data queue */
	srv_reminder_type active_type;	/* The current active reminder */
	U32 disable_mask;				/* Disabled reminder type */
	srv_reminder_result_funcptr result_callback;
	U32 usr_data;
}srv_reminder_cntx_struct;

static srv_reminder_cntx_struct g_srv_remdr_cntx;
/****************************************************************************
 * Global variables
 ****************************************************************************/


/****************************************************************************
 * Local variables
 ****************************************************************************/

/****************************************************************************
 * Global function
 ****************************************************************************/
extern kal_int8 mmi_dmui_is_phone_lock(void);

/****************************************************************************
 * Local Function
 ****************************************************************************/
static void srv_reminder_init_hdlr(void);
static void srv_reminder_expiry_hdlr(void *msg);
static void srv_reminder_set_rtc_alarm(MYTIME *alm_time);
static void srv_reminder_clear_rtc_alarm(void);
//static void srv_reminder_notify_all(srv_reminder_notify_enum notify);
static void srv_reminder_notify(srv_reminder_notify_enum notify, srv_reminder_type type);
static MMI_BOOL srv_reminder_do_schedule(MMI_BOOL peek_flag);
static MMI_BOOL srv_reminder_is_dm_lock(void);


/*****************************************************************************
* FUNCTION
*  srv_reminder_init
* DESCRIPTION
*  To set alarm to RTC
* PARAMETERS
*  msg			 [?]		 
* RETURNS
*  void
*****************************************************************************/
mmi_id srv_reminder_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		   */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													   	   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_INIT);
	
	/* Already init */
	if (g_srv_remdr_cntx.queue != NULL)
	{	
		return MMI_RET_OK;
	}
	
	g_srv_remdr_cntx.queue = srv_reminder_q_create();
	g_srv_remdr_cntx.active_type = SRV_REMINDER_TYPE_TOTAL;
	g_srv_remdr_cntx.disable_mask = 0;

	srv_reminder_q_init(g_srv_remdr_cntx.queue);
	
	//srv_reminder_notify_all(SRV_REMINDER_NOTIFY_INIT);
	srv_reminder_notify(SRV_REMINDER_NOTIFY_INIT, SRV_REMINDER_TYPE_TOTAL);

	/*
	 *  1. for Keypad, USB, Charger pwr-on, pending the current immidiate reminder.
	 *  2. for alarm pwr-on, alarm_ind message will come quickly, don't need to pend it.
	 */
    if (!srv_reminder_q_is_empty(g_srv_remdr_cntx.queue) && 
		(srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_ALARM))
    {
    	if (srv_reminder_do_schedule(MMI_TRUE))
    	{
			srv_reminder_clear_rtc_alarm();
    	}
    }

	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  srv_reminder_deinit
* DESCRIPTION
*  To set alarm to RTC
* PARAMETERS
*  msg			 [?]		 
* RETURNS
*  void
*****************************************************************************/
void srv_reminder_deinit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		   */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node;

	/*----------------------------------------------------------------*/
	/* Code Body													   	   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_DEINIT);
	
	if (srv_reminder_is_expiring())
	{
		srv_reminder_notify(SRV_REMINDER_NOTIFY_DEINIT, g_srv_remdr_cntx.active_type);
	}	

	q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, 0);
	
    /* Set next alarm. if alarm will expire during power off period, delay it */
	if (q_node != NULL 
        && q_node->type != SRV_REMINDER_TYPE_PWR_RESET
        && !(SRV_REMINDER_TYPE_IS_DISABLE(q_node->type))
        )
    {
        MYTIME curr_time, inc_time;
		
        DTGetRTCTime(&curr_time);

        memset(&inc_time, 0, sizeof(MYTIME));
        inc_time.nSec = (POWER_OFF_TOLERANCE / 1000);

        IncrementTime(curr_time, inc_time, &curr_time);

		SRV_RMDR_LOG1(SRV_RMDR_DEINIT_DELAY, inc_time.nSec);

		/* alarm almost expire */
        if (CompareTime(q_node->time, curr_time, NULL) != DT_TIME_GREATER)
        {
        	srv_reminder_set_rtc_alarm(&curr_time);
        }
    }	
}


/*****************************************************************************
  * FUNCTION
  *  srv_reminder_set_rtc_alarm_rsp
  * DESCRIPTION
  *  To del RTC from HW.
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
static void srv_reminder_set_rtc_alarm_rsp(void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   			*/
	/*----------------------------------------------------------------*/
	mmi_eq_set_rtc_time_rsp_struct *rsp;
	
	/*----------------------------------------------------------------*/
	/* Code Body													   		*/
	/*----------------------------------------------------------------*/
	rsp = (mmi_eq_set_rtc_time_rsp_struct *)msg;
	
	srv_reminder_init_hdlr();

	if (g_srv_remdr_cntx.result_callback != NULL)
	{
		g_srv_remdr_cntx.result_callback(rsp->result);
		g_srv_remdr_cntx.result_callback = NULL;
	}	
}
 
 
 /*****************************************************************************
  * FUNCTION
  *  srv_reminder_set_rtc_alarm
  * DESCRIPTION
  *  To register RTC alarm on HW
  * PARAMETERS
  *  alarmTime		 [IN]		 
  * RETURNS
  *  void
  *****************************************************************************/
static void srv_reminder_set_rtc_alarm(MYTIME *alm_time)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		*/
	/*----------------------------------------------------------------*/
	mmi_eq_set_rtc_time_req_struct *alarmReq;


	/*----------------------------------------------------------------*/
	/* Code Body													    */
	/*----------------------------------------------------------------*/
	alarmReq = SRV_RMDR_MALLOC_MSG(mmi_eq_set_rtc_time_req_struct);
	alarmReq->rtc_type = RTC_ALARM_IND;
	alarmReq->set_type = RTC_SETTING_TYPE_DATETIME;
	alarmReq->info.alarm_format = DEVICE_AL_EN_ChkYMDHMS;
	alarmReq->info.alarm_index = RTC_ALARM1_IND;	 /* Should be always zeor as only 1 alarm */
	alarmReq->info.type = RTC_ALARM_SOUND;
	alarmReq->info.text[0] = '\0';
	alarmReq->info.recurr = RTC_ALARM_DAY1;
	alarmReq->info.data_time.rtc_year = alm_time->nYear - YEARFORMATE;
	alarmReq->info.data_time.rtc_wday = alm_time->DayIndex;
	alarmReq->info.data_time.rtc_mon = alm_time->nMonth;
	alarmReq->info.data_time.rtc_day = alm_time->nDay;
	alarmReq->info.data_time.rtc_hour = alm_time->nHour;
	alarmReq->info.data_time.rtc_min = alm_time->nMin;
	alarmReq->info.data_time.rtc_sec = alm_time->nSec;

	SetProtocolEventHandler(srv_reminder_set_rtc_alarm_rsp, MSG_ID_MMI_EQ_EXE_RTC_TIMER_RSP);
	ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);

	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_EXE_RTC_TIMER_REQ, (oslParaType *)alarmReq, NULL);

#ifndef __MTK_TARGET__
	if (g_srv_remdr_cntx.result_callback != NULL)
	{
		g_srv_remdr_cntx.result_callback(MMI_TRUE);
		g_srv_remdr_cntx.result_callback = NULL;
	}	
#endif
}
 
 
/*****************************************************************************
* FUNCTION
*  srv_reminder_clear_rtc_alarm
* DESCRIPTION
*  To del RTC from HW.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_reminder_clear_rtc_alarm_rsp(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											           */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	SetProtocolEventHandler(srv_reminder_expiry_hdlr, MSG_ID_MMI_EQ_ALARM_IND);
}

  
 /*****************************************************************************
  * FUNCTION
  *  srv_reminder_clear_rtc_alarm
  * DESCRIPTION
  *  To del RTC from HW.
  * PARAMETERS
  *  void
  * RETURNS
  *  void
  *****************************************************************************/
static void srv_reminder_clear_rtc_alarm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	mmi_eq_del_rtc_timer_req_struct *alm_req;

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/

	alm_req = SRV_RMDR_MALLOC_MSG(mmi_eq_del_rtc_timer_req_struct);

	alm_req->rtc_type = RTC_ALARM_IND;
	alm_req->rtc_index = RTC_ALARM1_IND;
	/* MTK end */
	SetProtocolEventHandler(srv_reminder_clear_rtc_alarm_rsp, MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_RSP);
	ClearProtocolEventHandler(MSG_ID_MMI_EQ_ALARM_IND);

	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_EXE_DEL_RTC_TIMER_REQ, (oslParaType *)alm_req, NULL);
}

static void srv_reminder_set_remdr_evt(srv_reminder_evt_struct *remdr_evt)
{
	MMI_FRM_INIT_EVENT(remdr_evt, EVT_ID_SRV_REMINDER_NOTIFY);

    if ((srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL) &&
             !srv_bootup_is_exception_mode())
    {
        remdr_evt->pwr_off = MMI_TRUE;;
    }
    else
    {
        remdr_evt->pwr_off = MMI_FALSE;
    }
}
/*****************************************************************************
 * FUNCTION
 *	srv_reminder_notify
 * DESCRIPTION
 *	Notify reminder type about reminder event.
 * PARAMETERS
 *	notify	:[IN]	notify type
 *	type		:[IN]	reminder type
 * RETURNS
 *	void
 *****************************************************************************/
static void srv_reminder_notify(srv_reminder_notify_enum notify, srv_reminder_type type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  	   */
	/*----------------------------------------------------------------*/
	srv_reminder_evt_struct remdr_evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  	   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG2(SRV_RMDR_NOTIFY, notify, type);
	
	/*MMI_FRM_INIT_EVENT(&remdr_evt, EVT_ID_SRV_REMINDER_NOTIFY);

	if ((srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL) &&
         !srv_bootup_is_exception_mode())
	{
		remdr_evt.pwr_off = MMI_TRUE;;
	}
	else
	{
		remdr_evt.pwr_off = MMI_FALSE;
	}*/
    srv_reminder_set_remdr_evt(&remdr_evt);
	
	remdr_evt.notify = notify;
	remdr_evt.reminder_type = type;	
	MMI_FRM_CB_EMIT_EVENT(&remdr_evt);

}

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
/*****************************************************************************
 * FUNCTION
 *	srv_reminder_do_schedule
 * DESCRIPTION
 *	reminder scheduler will trigger the next reminder.
 * PARAMETERS
 *	peek_flag		[IN]	 need to schedule the immediate reminder.
 * RETURNS
 *	MMI_TRUE	-> the next reminder will come immediatly
 *	MMI_FALSE	-> the next reminder will not come or not come immedialy.
 *****************************************************************************/
static MMI_BOOL srv_reminder_do_schedule(MMI_BOOL peek_flag)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_evt_struct remdr_evt;
	srv_reminder_q_node_type *q_node;
	applib_time_struct curr_time;
	U32 i = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_DO_SCHEDULE, peek_flag);
	
	if (srv_reminder_is_expiring())
	{
		return MMI_FALSE;
	}
	
	/* Loop until the expiriable reminder */
	do{
		q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, i);
		
		RETURN_VAL_IF_FAIL(q_node != NULL, MMI_FALSE);
		
		i++;
		/* skip disabled reminders */
		if (SRV_REMINDER_TYPE_IS_DISABLE(q_node->type))
		{
			continue;
		}

		applib_dt_get_rtc_time(&curr_time);
		if (CompareTime(q_node->time, curr_time, NULL) == DT_TIME_GREATER)
		{
			SRV_RMDR_LOG0(SRV_RMDR_DO_SCHEDULE_NEXT);
			srv_reminder_set_rtc_alarm(&q_node->time);
			
			return MMI_FALSE;
		}
		else
		{
			break;
		}
		
	}while(MMI_TRUE);

	/* Find a recent reminder, but don't trigger it right now */
	if (peek_flag)
	{
		return MMI_TRUE;
	}
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_CURR_TIME,
				  curr_time.nYear, 
				  curr_time.nMonth, 
				  curr_time.nDay, 
				  curr_time.nHour, 
				  curr_time.nMin, 
				  curr_time.nSec);
	SRV_RMDR_LOG6(SRV_RMDR_LOG_TIME,
				  q_node->time.nYear,
				  q_node->time.nMonth,
				  q_node->time.nDay,
				  q_node->time.nHour,
				  q_node->time.nMin,
				  q_node->time.nSec);
	
	/* Trigger a reminder. */
	/*MMI_FRM_INIT_EVENT(&remdr_evt, EVT_ID_SRV_REMINDER_NOTIFY);
	
	if ((srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL) &&
         !srv_bootup_is_exception_mode())
	{
		remdr_evt.pwr_off = MMI_TRUE;
	}
	else
	{
		remdr_evt.pwr_off = MMI_FALSE;
	}*/
	
    srv_reminder_set_remdr_evt(&remdr_evt);
	remdr_evt.reminder_type = (srv_reminder_type)q_node->type;
	remdr_evt.notify = SRV_REMINDER_NOTIFY_EXPIRY;
	remdr_evt.usr_data = q_node->usr_data;

	g_srv_remdr_cntx.active_type = (srv_reminder_type)q_node->type;

	SRV_RMDR_LOG3(SRV_RMDR_DO_SCHEDULE_EXPIRY, remdr_evt.reminder_type, remdr_evt.pwr_off, remdr_evt.usr_data);

	MMI_FRM_CB_EMIT_POST_EVENT(&remdr_evt);

	srv_reminder_q_delete(g_srv_remdr_cntx.queue, q_node);

	return MMI_TRUE;
}


#define EXPIRY_HANDLER 
/*****************************************************************************
   * FUNCTION
   *  srv_reminder_expiry_hdlr
   * DESCRIPTION
   *  To set alarm to RTC
   * PARAMETERS
   *  msg			  [?]		  
   * RETURNS
   *  void
   *****************************************************************************/
static void srv_reminder_init_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												*/
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body														*/
	/*----------------------------------------------------------------*/
	if (srv_reminder_is_dm_lock())
	{
		return;
	}

	SetProtocolEventHandler(srv_reminder_expiry_hdlr, MSG_ID_MMI_EQ_ALARM_IND);	  
}


/*****************************************************************************
  * FUNCTION
  *	srv_reminder_check_bootup
  * DESCRIPTION
  *	To check whether bootup has been completed
  * PARAMETERS
  *	void
  * RETURNS
  *	MMI_TRUE
  *	MMI_FALSE
  *****************************************************************************/
static MMI_BOOL srv_reminder_check_bootup(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		   */
	/*----------------------------------------------------------------*/
	srv_bootup_mode_enum bootup_mode;
	MMI_BOOL pwr_check;

	/*----------------------------------------------------------------*/
	/* Code Body													   	   */
	/*----------------------------------------------------------------*/
	bootup_mode = srv_bootup_get_booting_mode();

	if((bootup_mode == SRV_BOOTUP_MODE_USB) ||
	   (bootup_mode == SRV_BOOTUP_MODE_CHARGE) || 
	   (bootup_mode == SRV_BOOTUP_MODE_ALARM))
	{
		pwr_check = MMI_TRUE;
	}
	/* Only normal power-on */
	else if (bootup_mode == SRV_BOOTUP_MODE_NORMAL && srv_bootup_is_completed())
	{
		pwr_check = MMI_TRUE;
	}
	else
	{
		pwr_check = MMI_FALSE;	 /* the case of power on animation + alarm expiration */
	}

	SRV_RMDR_LOG2(SRV_RMDR_CHK_BOOTUP, bootup_mode, pwr_check);
	return pwr_check;
}


 /*****************************************************************************
  * FUNCTION
  *  srv_reminder_update_time
  * DESCRIPTION
  *	Update system time
  * PARAMETERS
  *  msg		:[IN]	alarm indication struct		 
  * RETURNS
  *  void
  *****************************************************************************/
static void srv_reminder_update_time(mmi_eq_alarm_ind_struct *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   	         */
	/*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__	
	mmi_eq_clock_tick_ind_struct clock_tick;
#endif

	/*----------------------------------------------------------------*/
	/* Code Body													     	   */
	/*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__	 
	clock_tick.rtc_type = 0;
	memcpy(&clock_tick.rtc_time, &msg->rtc_time, sizeof(rtc_format_struct));
	 
	DateTimerIndication((void *)&clock_tick);
#endif /* __MTK_TARGET__ */
 
	mmi_dt_check_rtc_time();
 
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_reminder_expiry_hdlr
 * DESCRIPTION
 *  reminder expiry handler
 * PARAMETERS
 *  msg			 :[IN]		 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_reminder_expiry_hdlr(void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		   */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													   	   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_EXPIRY_HDLR);
	
	srv_reminder_update_time(msg);

	/* for DM lock, Reminder won't come any more. */
	RETURN_IF_FAIL(!srv_reminder_is_dm_lock());

	if (!srv_reminder_check_bootup())
	{
		return;
	}
	
	srv_reminder_do_schedule(MMI_FALSE);
}


/*****************************************************************************
  * FUNCTION
  *  srv_reminder_is_valid_type
  * DESCRIPTION
  *	To check whether the reminder type is valid.
  * PARAMETERS
  *  type		  :[IN]	reminder type		  
  * RETURNS
  *  void  
  *****************************************************************************/
static MMI_BOOL srv_reminder_is_valid_type(srv_reminder_type type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	return (MMI_BOOL)(type < SRV_REMINDER_TYPE_TOTAL);
}


#define GLOBAL_INTERFACE
 /*****************************************************************************
  * Please refer to ReminderSrvGprot.h
  *****************************************************************************/
 srv_reminder_ret_enum srv_reminder_set(srv_reminder_type type, const MYTIME *expiry_time, U32 usr_data)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 												     */
	 /*----------------------------------------------------------------*/
	 
	 /*----------------------------------------------------------------*/
	 /* Code Body													     */
	 /*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_SET);
	return srv_reminder_set_with_callback(type, expiry_time, NULL, NULL, usr_data);
 }
 
 
/*****************************************************************************
  * Please refer to ReminderSrvGprot.h
  *****************************************************************************/
srv_reminder_ret_enum srv_reminder_set_with_callback(srv_reminder_type type,																													  
															 const MYTIME *expiry_time,
															 srv_reminder_result_funcptr result,
															 srv_reminder_compare_funcptr cmp,
															 U32 usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type new_node;
	srv_reminder_ret_enum ret;
	MYTIME curr_time;

	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG2(SRV_RMDR_SET_WITH_CALLBACK, type, usr_data);
	
	RETURN_VAL_IF_FAIL(expiry_time != NULL, SRV_REMINDER_RET_INVALID_TIME);
	
	if(!srv_reminder_is_valid_type(type))
	{
		ret = SRV_REMINDER_RET_INVALID_TYPE;
		goto FAILED;
	}
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_TIME,
				  expiry_time->nYear,
				  expiry_time->nMonth,
				  expiry_time->nDay,
				  expiry_time->nHour,
				  expiry_time->nMin,
				  expiry_time->nSec);

	if (!applib_dt_is_valid((applib_time_struct *)expiry_time))
	{
		ret = SRV_REMINDER_RET_INVALID_TIME;
		goto FAILED;
	}

	applib_dt_get_rtc_time((applib_time_struct *)&curr_time);
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_CURR_TIME,
				  curr_time.nYear, 
				  curr_time.nMonth, 
				  curr_time.nDay, 
				  curr_time.nHour, 
				  curr_time.nMin, 
				  curr_time.nSec);
	
	if (applib_dt_compare_time((applib_time_struct *)&curr_time, (applib_time_struct *)expiry_time, NULL) == DT_TIME_GREATER)
	{
		ret = SRV_REMINDER_RET_INVALID_TIME;
		goto FAILED;
	}

	g_srv_remdr_cntx.result_callback = result;
	
	new_node.type = type;
	new_node.usr_data = usr_data;
	memcpy(&new_node.time, expiry_time, sizeof(MYTIME));

	ret = srv_reminder_q_add_with_callback(g_srv_remdr_cntx.queue, &new_node, cmp);
	if (ret == SRV_REMINDER_RET_OK)
	{
		srv_reminder_do_schedule(MMI_FALSE);
	}

	SRV_RMDR_LOG1(SRV_RMDR_SET_WITH_CALLBACK_RET, ret);
FAILED:
 
	return ret;

 }

																   
/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_reminder_cancel(srv_reminder_type type, U32 usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type q_node;
	srv_reminder_ret_enum ret;

	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG2(SRV_RMDR_CANCEL, type, usr_data);
	
	q_node.type = type;
	q_node.usr_data = usr_data;

	ret = srv_reminder_q_delete(g_srv_remdr_cntx.queue, &q_node);
	
		if (!srv_reminder_q_is_empty(g_srv_remdr_cntx.queue))
		{
			srv_reminder_do_schedule(MMI_FALSE);
		}
		else
		{
			srv_reminder_clear_rtc_alarm();
		}
	
	SRV_RMDR_LOG1(SRV_RMDR_CANCEL_RET, ret);
	
	return (MMI_BOOL)(ret == SRV_REMINDER_RET_OK);
}


 /*****************************************************************************
  * Please refer to ReminderSrvGprot.h
  *****************************************************************************/
 srv_reminder_ret_enum srv_reminder_search(srv_reminder_type type, MYTIME *expiry_time, U32 usr_data)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 												     */
	 /*----------------------------------------------------------------*/
	 U32 index = 0;
	 srv_reminder_q_node_type node;
	 /*----------------------------------------------------------------*/
	 /* Code Body													     */
	 /*----------------------------------------------------------------*/
	 SRV_RMDR_LOG2(SRV_RMDR_SEARCH, type, usr_data);
	 node.type = type;
	 node.usr_data = usr_data;

	 index = srv_reminder_q_search(g_srv_remdr_cntx.queue, &node);
	 if(index < REMINDER_Q_TOTAL)
	 {
	 	memcpy(expiry_time, &node.time, sizeof(MYTIME));
		return SRV_REMINDER_RET_OK;
	 }
	 else
	 {
	 	return SRV_REMINDER_RET_FAIL;
	 }

 }

 /*****************************************************************************
  * Please refer to ReminderSrvGprot.h
  *****************************************************************************/
MMI_BOOL srv_reminder_clear(srv_reminder_type type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
	srv_reminder_ret_enum del_ret;
	MMI_BOOL ret = MMI_FALSE;
	
	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_CLEAR, type);

	if (type == SRV_REMINDER_TYPE_TOTAL)
	{
		srv_reminder_q_empty(g_srv_remdr_cntx.queue);
		
		ret = MMI_TRUE;
	}
	else
	{
		srv_reminder_q_node_type *q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, 0);
		U32 i = 0;
		
		do{
			if (q_node == NULL)
			{
				break;
			}
			
			if (q_node->type == type)
			{
				del_ret = srv_reminder_q_delete_by_index(g_srv_remdr_cntx.queue, i);
				ret = (del_ret == SRV_REMINDER_RET_OK) ? MMI_TRUE : MMI_FALSE;
			}
			else
			{
				i++;
			}
			
			q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, i);

		}while(MMI_TRUE);
		
	}
	
	return ret;
}
 

 /*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_reminder_enable(srv_reminder_type type, MMI_BOOL enable)

 {
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG2(SRV_RMDR_ENABLE, type, enable);
	
	RETURN_VAL_IF_FAIL(type <= SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);
	
	if (enable)
	{
		if (type == SRV_REMINDER_TYPE_TOTAL)
		{
			g_srv_remdr_cntx.disable_mask = 0;
		}
		else
		{
			SRV_REMINDER_TYPE_ENABLE(type);
		}
		
		srv_reminder_do_schedule(MMI_FALSE);
	}
	else
	{
		if (type == SRV_REMINDER_TYPE_TOTAL)
		{
			g_srv_remdr_cntx.disable_mask = SRV_REMINDER_INVALID_TYPE;
		}
		else
		{
			SRV_REMINDER_TYPE_DISABLE(type);
		}		
	}

	return MMI_TRUE;
 }

  
/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_reminder_is_expiring(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
 	MMI_BOOL ret;
	 
	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	ret = (MMI_BOOL)(g_srv_remdr_cntx.active_type != SRV_REMINDER_TYPE_TOTAL
	       && g_srv_remdr_cntx.active_type != SRV_REMINDER_TYPE_POWER_ON_CONFIRM);
	
	SRV_RMDR_LOG2(SRV_RMDR_IS_EXPIRYING, ret, g_srv_remdr_cntx.active_type);
	
	return ret;
}
  

/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
MMI_BOOL srv_reminder_is_in_power_on_confirm(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
 	MMI_BOOL ret;
	 
	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	ret = (MMI_BOOL)(g_srv_remdr_cntx.active_type == SRV_REMINDER_TYPE_POWER_ON_CONFIRM);
	
	return ret;
}

MMI_BOOL srv_reminder_is_reminder_active(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 												     */
	/*----------------------------------------------------------------*/
	 
	/*----------------------------------------------------------------*/
	/* Code Body													     */
	/*----------------------------------------------------------------*/
	return (MMI_BOOL)(srv_reminder_is_expiring() | srv_reminder_is_in_power_on_confirm());
}


/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
void srv_reminder_notify_finish(MMI_BOOL pwr_confirm)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_type prev;
	MMI_BOOL ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_NOTIFY_FINISH, pwr_confirm);

	prev = g_srv_remdr_cntx.active_type;
	g_srv_remdr_cntx.active_type = SRV_REMINDER_TYPE_TOTAL;
		
	/* Schedule next reminder */
	ret = srv_reminder_do_schedule(MMI_FALSE);

	/*
	 * if no recent reminder, we should ask UI for power confirm
	 */

	if (!ret && prev != SRV_REMINDER_TYPE_PWR_RESET && prev != SRV_REMINDER_TYPE_POWER_ON_CONFIRM && 
		prev != SRV_REMINDER_TYPE_TOTAL)
	{
		/* for non-normal power-on mode, Ask reminder app to poweroff the phone. */
		if(srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL)
	{
			srv_reminder_pwrreset_evt_struct evt;
			MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_REMINDER_PWRRESET_REQ);

			evt.pwr_confirm = pwr_confirm;
                g_srv_remdr_cntx.active_type = SRV_REMINDER_TYPE_POWER_ON_CONFIRM;
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
		}
	}
}


/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
void srv_reminder_pwr_on_hdlr(void *msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   		   */
	/*----------------------------------------------------------------*/
	srv_bootup_mode_enum bootup_mode = srv_bootup_get_booting_mode();
	mmi_event_struct evt;
	
	/*----------------------------------------------------------------*/
	/* Code Body													   	   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_PWRON_HDLR);
	
	RETURN_IF_FAIL(bootup_mode == SRV_BOOTUP_MODE_ALARM);

    /* Notify bootup flow control to start booting */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_REMINDER_BOOTUP_START);
    MMI_FRM_CB_EMIT_EVENT(&evt);
}

/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
srv_reminder_type srv_reminder_get_expiry_type(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/

	return g_srv_remdr_cntx.active_type;	
}

#ifndef __MTK_TARGET__
#define __REMINDER_MODIS__
/*****************************************************************************
  * FUNCTION
  *  srv_reminder_expiry_check
  * DESCRIPTION
  *  modis reminder check.
  * PARAMETERS
  *	mytime	:[IN]	current time		  
  * RETURNS
  *  MMI_OK  
  *****************************************************************************/
void srv_reminder_expiry_check(void *mytime)
{
#ifdef __REMINDER_MODIS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node;
    applib_time_struct *alarm_time, *curr_time;
    mmi_eq_alarm_ind_struct msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RETURN_IF_FAIL(mytime != NULL);

	q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, 0);
	RETURN_IF_FAIL(q_node != NULL);

    alarm_time = (applib_time_struct *)&q_node->time;
    curr_time = (applib_time_struct *)mytime;

    if (!srv_reminder_is_expiring() &&
        applib_dt_compare_time(alarm_time, curr_time, NULL) <= DT_TIME_EQUAL)
	{
        msg.rtc_time.rtc_wday = curr_time->DayIndex;
        msg.rtc_time.rtc_year = curr_time->nYear - DT_MIN_YEAR;
        msg.rtc_time.rtc_mon = curr_time->nMonth;
        msg.rtc_time.rtc_day = curr_time->nDay;
        msg.rtc_time.rtc_hour = curr_time->nHour;
        msg.rtc_time.rtc_min = curr_time->nMin;
        msg.rtc_time.rtc_sec = curr_time->nSec;
        
        srv_reminder_expiry_hdlr(&msg);
    }
#endif /* __REMINDER_MODIS__ */
}

#endif /* __MTK_TARGET__ */


/*****************************************************************************
  * FUNCTION
  *  srv_reminder_on_bootup_notify
  * DESCRIPTION
  *  Bootup flow notify callback
  * PARAMETERS
  *	evt		:[evt]	mmi_event_struct		  
  * RETURNS
  *  MMI_OK  
  *****************************************************************************/
mmi_ret srv_reminder_on_bootup_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_BOOTUP_NOTIFY);
	
	if (evt->evt_id == EVT_ID_SRV_BOOTUP_COMPLETED ||
		evt->evt_id == EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE)
	{
		srv_reminder_notify_finish(MMI_FALSE);
	}

	return MMI_OK;
}


/*****************************************************************************
  * FUNCTION
  *  srv_reminder_on_time_change_notify
  * DESCRIPTION
  *  After time has been changed, reminder q should reinit.
  * PARAMETERS
  *	evt		:[evt]	mmi_event_struct		  
  * RETURNS
  *  MMI_OK  
  *****************************************************************************/
mmi_ret srv_reminder_on_time_change_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_TIME_CHANGE_NOTIFY);
	
	g_srv_remdr_cntx.active_type = SRV_REMINDER_TYPE_TOTAL;
	srv_reminder_q_empty(g_srv_remdr_cntx.queue);

	//srv_reminder_notify_all(SRV_REMINDER_NOTIFY_REINIT);
	
	srv_reminder_notify(SRV_REMINDER_NOTIFY_REINIT, SRV_REMINDER_TYPE_TOTAL);
    

	return MMI_OK;
}

/*****************************************************************************
  * FUNCTION
  *  srv_reminder_on_shutdown_notify
  * DESCRIPTION
  *  Shutdown flow notify callback
  * PARAMETERS
  *	evt		:[evt]	mmi_event_struct		  
  * RETURNS
  *  MMI_OK  
  *****************************************************************************/
mmi_ret srv_reminder_on_shutdown_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_BOOTUP_NOTIFY);
	srv_reminder_deinit();
	
	return MMI_OK;
}

#ifdef __REMINDER_UT__

/*****************************************************************************
  * FUNCTION
  *  srv_reminder_dump_queue
  * DESCRIPTION
  *  print all q node info
  * PARAMETERS
  *	void
  * RETURNS
  *  void
  *****************************************************************************/
void srv_reminder_dump_queue(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node;
	U8 i = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_DUMP_QUEUE);
	
	RETURN_IF_FAIL(g_srv_remdr_cntx.queue != NULL);

	q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, 0);
	RETURN_IF_FAIL(q_node != NULL);

	do{
		SRV_RMDR_LOG3(SRV_RMDR_DUMP_QUEUE_DETAIL, i, q_node->type, q_node->usr_data);
		SRV_RMDR_LOG6(SRV_RMDR_LOG_TIME,
				  	q_node->time.nYear,
				  	q_node->time.nMonth,
				  	q_node->time.nDay,
				  	q_node->time.nHour,
				  	q_node->time.nMin,
				  	q_node->time.nSec);
		
		q_node = srv_reminder_q_get(g_srv_remdr_cntx.queue, ++i);
		
	}while(q_node != NULL);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_is_dm_lock
 * DESCRIPTION
 *  This function used to check DM lock status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_reminder_is_dm_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock())
    {
        return MMI_TRUE;
    }
    #endif /* __DM_LAWMO_SUPPORT__ */
	
    return MMI_FALSE;
}

#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_alm_get_sensor_listen_state
 * DESCRIPTION
 *  get the alarm sensor listening state
 * PARAMETERS
 *  type: montion sensor type 
 * RETURNS
 *  MMI_TRUE	  : listening state is ON
 *  MMI_FALSE : listening state is OFF 
 *****************************************************************************/
MMI_BOOL srv_reminder_get_sensor_listen_state(srv_sensor_type_enum type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables											   */
	/*----------------------------------------------------------------*/
	S16 error;
    U8 state; 
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	if(type != SRV_SENSOR_MOTION_TURNOVER)
	{
	    return MMI_FALSE;
	}
	
    ReadValue(NVRAM_REMINDER_TURNOVER_SENSOR_STATE, &state, DS_BYTE, &error);
   
    return state ? MMI_TRUE : MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_alm_set_sensor_listen_state
 * DESCRIPTION
 *  set the alarm sensor listening state
 * PARAMETERS
 * type:   montion sensor type 
 * state:  MMI_TRUE-->set the listening state as on; MMI_FALSE-->set the listening state as off 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_reminder_set_sensor_listen_state(srv_sensor_type_enum type, MMI_BOOL state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables											   */
	/*----------------------------------------------------------------*/
	S16 error;
    U8 temp; 
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	if(type != SRV_SENSOR_MOTION_TURNOVER)
	{
	    return MMI_FALSE;
	}
	temp = state;
    WriteValue(NVRAM_REMINDER_TURNOVER_SENSOR_STATE, &temp, DS_BYTE, &error);
	return MMI_TRUE;
}
#endif

