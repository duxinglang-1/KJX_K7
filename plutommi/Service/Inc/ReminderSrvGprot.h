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
 *  ReminderSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of reminder service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __REMINDER_SRV_GPROT_H__
#define __REMINDER_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "mmi_frm_gprot.h"
#include "..\ReminderSrv\ReminderSrvTypeTable.h"
#include "SensorSrvGport.h"
/****************************************************************************
 * Constants
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/
/* Repeat type */
typedef enum
{
    SRV_REMINDER_REPEAT_OFF, /* off */
    SRV_REMINDER_REPEAT_ONCE, /* once */
    SRV_REMINDER_REPEAT_HOURLY, /* hourly */
    SRV_REMINDER_REPEAT_EVERYDAY, /* everyday */
    SRV_REMINDER_REPEAT_DAYS, /* days */
    SRV_REMINDER_REPEAT_WEEKLY, /* weekly */
    SRV_REMINDER_REPEAT_MONTHLY, /* monthly */
    SRV_REMINDER_REPEAT_SEASONLY, /* seasonly */
    SRV_REMINDER_REPEAT_YEARLY, /* yearly */
    SRV_REMINDER_REPEAT_TITHI, /* tithi */
    SRV_REMINDER_REPEAT_CUSTOM,	/* customized repeat type */
    SRV_REMINDER_REPEAT_TOTAL
} srv_reminder_repeat_enum;

/* Reminder return value. */
typedef enum
{
	SRV_REMINDER_RET_OK, /* OK */
	SRV_REMINDER_RET_FAIL, /* fail */
	SRV_REMINDER_RET_INVALID_DATA, /* invalid data */
	SRV_REMINDER_RET_INVALID_TYPE, /* type */
	SRV_REMINDER_RET_INVALID_INDEX, /* invalid index */
	SRV_REMINDER_RET_INVALID_TIME,	/* Invalid time or time is smaller than current time .*/
	SRV_REMINDER_RET_STOP, /* stop here. */
	
	SRV_REMINDER_RET_TOAL
}srv_reminder_ret_enum;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_reminder_compare_funcptr
 * DESCRIPTION
 *  If there is a reminder who's reminder time and time is the same as the current one,
 *		this callback will be called to ask user whether to swap the current one with the one in reminder queue
 * PARAMETERS
 *  exist		: [IN] exist index
 *  curr		: [IN] current index
 * RETURNS
 * 	1  -> to swap the two reminder
 *	0 -> replace the exit one
 *	-1 -> don't swap
 *****************************************************************************/
typedef S32 (*srv_reminder_compare_funcptr)(U32 exist, U32 curr);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_reminder_result_funcptr
 * DESCRIPTION
 *  The callback function will be called when alarm is set.
 * PARAMETERS
 *  MMI_BOOL		: [IN] success or not
 * RETURNS
 * 	void
 *****************************************************************************/
typedef void (*srv_reminder_result_funcptr)(MMI_BOOL);


/****************************************************************************
 * Global functions
 ****************************************************************************/

/*
 * DESCRIPTION
 *  Event ID of Reminder.
 *  Reminder will send evt to notify AP.
 */
 
#ifdef __BUILD_DOM__
/*
 * [INTERNAL]
 *
 * Structure:
 *  srv_reminder_evt_struct
 */
typedef enum
{
    EVT_ID_SRV_REMINDER_BOOTUP_START = SRV_REMINDER_BASE,  /* Alarm power on start. */
    EVT_ID_SRV_REMINDER_BOOTUP_INIT, /* Alarm power on init stage. */
    EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE, /* Alarm power on completed. */
    EVT_ID_SRV_REMINDER_NOTIFY,  /* Reminder service notify. */
    EVT_ID_SRV_REMINDER_PWRRESET_REQ, /* Reset. */
    EVT_ID_SRV_REMINDER_TOTAL /* End. */
} srv_reminder_evt_id_enum;
#endif /* __BUILD_DOM__ */


/* Reminder notification enum */
typedef enum
{
    SRV_REMINDER_NOTIFY_INIT,	/* Ap should init reminder related data */
    SRV_REMINDER_NOTIFY_EXPIRY,	/* Reminder expiry */
    SRV_REMINDER_NOTIFY_REINIT,	/* If the current time is changed, AP should set all reminder time again */
    SRV_REMINDER_NOTIFY_DEINIT,	/* AT command ask for pwr-off, reminder need to notify all active type. */
    SRV_REMINDER_NOTIFY_TOTAL /* End. */
} srv_reminder_notify_enum;


/*
 * DESCRIPTION
 *  The event structure of EVT_ID_SRV_REMINDER_NOTIFY, to notify AP about reminder's stage.
 * SEE ALSO
 *
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER    
    srv_reminder_notify_enum notify; /* Notify type */
    MMI_BOOL pwr_off;	/* Reminder is coming at poweroff mode */
    srv_reminder_type reminder_type; /* Reminder app type. */
	U32 usr_data; /* User data. */
} srv_reminder_evt_struct;


/* Reset event struct. */
typedef struct
{
    MMI_EVT_PARAM_HEADER  /* Common para. */ 
    MMI_BOOL pwr_confirm;	/* whether to ask about power-on confirm */
} srv_reminder_pwrreset_evt_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_set
 * DESCRIPTION
 *  Set reminder to reminder Queue, if there is already a reminder with the same type, the same usr_data,
 *	reminder will overwrite the exist one.
 * PARAMETERS
 *  type				:[IN]	Reminder type
 *	expiry_time		:[IN]	Reminder expiry time
 *  usr_data			:[IN]	The user data will be saved by reminder, and be sent to AP in expiry event.
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
extern srv_reminder_ret_enum srv_reminder_set(srv_reminder_type type, const MYTIME *expiry_time, U32 usr_data);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_set_with_callback
 * DESCRIPTION
 *  Set reminder to reminder Queue
 * PARAMETERS
 *  type				:[IN]	Reminder type
 *	expiry_time		:[IN]	Expiry time
 *	cmp				:[IN]	If there already is a reminder in Q which has the same expiry time and same type,
 *						  the compare callback will be called to ask AP whether need to swap the on in Q with the current one.
 *  usr_data			:[IN]	The user data will be saved by reminder, and be sent to AP in expiry event.
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
extern srv_reminder_ret_enum srv_reminder_set_with_callback(srv_reminder_type type,																 		 												
																	const MYTIME *expiry_time,
																	srv_reminder_result_funcptr result,
																	srv_reminder_compare_funcptr cmp,
																	U32 usr_data);
																 
/*****************************************************************************
 * FUNCTION
 *  srv_reminder_cancel
 * DESCRIPTION
 *  Cancel the reminder in reminder queue
 * PARAMETERS
 *  type			:[IN]	Reminder type
 *	usr_data	:[IN] 
 * RETURNS
 *  MMI_TRUE	->	success
 *	MMI_FALSE	-> can't found the node
 *****************************************************************************/
extern MMI_BOOL srv_reminder_cancel(srv_reminder_type type, U32 usr_data);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_search
 * DESCRIPTION
 *  search the reminder in reminder queue
 * PARAMETERS
 *    type	    :[IN]	Reminder type
 *	usr_data	    :[IN]      reminder index
 *    expiry_time :[OUT] reminder time
 * RETURNS
 *   
 *	
 *****************************************************************************/

extern srv_reminder_ret_enum srv_reminder_search(srv_reminder_type type, MYTIME *expiry_time, U32 usr_data);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_clear
 * DESCRIPTION
 *  Clear all node of one type
 * PARAMETERS
 *  type	:[IN]	Reminder type
 * RETURNS
 *  MMI_TRUE	->	success
 *	MMI_FALSE	-> can't found this type
 *****************************************************************************/
extern MMI_BOOL srv_reminder_clear(srv_reminder_type type);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_enable
 * DESCRIPTIONsrv_reminder_clear
 *  Disable or enable any type of reminder
 * PARAMETERS
 *  type			:[IN]	Reminder type, SRV_REMINDER_TYPE_TOTAL means disable all type reminders.
 *	enable		:[IN] MMI_TRUE means enable, MMI_FALSE means disable
 * RETURNS
 *  MMI_TRUE	-> success
 *	MMI_FALSE	-> fail
 *****************************************************************************/
extern MMI_BOOL srv_reminder_enable(srv_reminder_type type, MMI_BOOL enable);


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_is_expiring
 * DESCRIPTION
 *  Has expired reminder right now.
 * PARAMETERS
 *	void 
 * RETURNS
 *  MMI_TRUE	-> there is expiry reminder
 *	MMI_FALSE -> there isn't any expiry reminder
 *****************************************************************************/
extern MMI_BOOL srv_reminder_is_expiring(void);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_is_in_power_on_confirm
 * DESCRIPTION
 *  Phone is in power on confirm stage
 * PARAMETERS
 *	void 
 * RETURNS
 *  MMI_TRUE	-> the phone is in power on confirm stage
 *	MMI_FALSE -> the phone is NOT in power on confirm stage
 *****************************************************************************/
extern MMI_BOOL srv_reminder_is_in_power_on_confirm(void);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_is_reminder_active
 * DESCRIPTION
 *  Phone is in reminder active (check if is reminder expiring and in confirm stage)
 * PARAMETERS
 *	void 
 * RETURNS
 *  MMI_TRUE	-> there is reminder active
 *	MMI_FALSE -> there is no reminder active
 *****************************************************************************/
extern MMI_BOOL srv_reminder_is_reminder_active(void);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_notify_finish
 * DESCRIPTION
 *  After reminder has finished, AP should call this API to tell reminder that AP has finished its process
 *		Reminder service will schedule next reminder.
 * PARAMETERS
 *	pwr_confirm	:[IN] where need to ask usr's confirm if reminder want to poweroff phone. 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_reminder_notify_finish(MMI_BOOL pwr_confirm);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_calc_time
 * DESCRIPTION
 *  Calculates the time when alarm will expire by the frequency and weekdays.
 * PARAMETERS
 *  time      :[IN]	Time of the alarm.
 *  freq		  :[IN]	Repeat of the alarm.  
 *  week_days	:[IN]	Weekdays of the alarm. 
 *                  Each bit is set for every day. 
 *									Bit 0 for sunday and so on, only if the freq is SRV_REMINDER_REPEAT_DAYS, AP need to set this parameter
 * RETURNS
 *  MYTIME	Next expired time of the alarm.
 *****************************************************************************/
extern MYTIME srv_reminder_calc_time(const MYTIME *time, srv_reminder_repeat_enum freq, U8 week_days);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_pwr_on_hdlr
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_reminder_pwr_on_hdlr(void *msg);


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_init
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id srv_reminder_init(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_deinit
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_reminder_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_deinit
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_reminder_util_send_pwroff(void);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_pwroff_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

extern void srv_reminder_util_pwroff_req(void);


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_deinit
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_reminder_util_send_pwron(void);


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_get_expiry_type
 * DESCRIPTION
 *  handler bootup
 * PARAMETERS
 *  msg	:[IN]	can be any type of message
 * RETURNS
 *  srv_reminder_type
 *****************************************************************************/
extern srv_reminder_type srv_reminder_get_expiry_type(void);

#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_reminder_get_sensor_listen_state
 * DESCRIPTION
 *  get the reminder motion sensor listening state
 *  note: just support SRV_SENSOR_MOTION_TURNOVER
 * PARAMETERS
 *  type  :[IN] montion sensor type 
 * RETURNS
 *  MMI_TRUE	  : listening state is ON
 *  MMI_FALSE : listening state is OFF 
 *****************************************************************************/
extern MMI_BOOL srv_reminder_get_sensor_listen_state(srv_sensor_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_set_sensor_listen_state
 * DESCRIPTION
 *  set the reminder motion sensor listening state
  *  note: just support SRV_SENSOR_MOTION_TURNOVER
 * PARAMETERS
 * type:  [IN] montion sensor type 
 * state: [IN] MMI_TRUE-->set the listening state as on; MMI_FALSE-->set the listening state as off 
 * RETURNS
 *  MMI_TRUE	  : set success
 *  MMI_FALSE : set failed
 *****************************************************************************/
extern MMI_BOOL srv_reminder_set_sensor_listen_state(srv_sensor_type_enum type, MMI_BOOL state);
#endif

#endif /* __REMINDER_SRV_GPROT_H__ */


