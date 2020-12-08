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
 *  ReminderSrvUtility.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#include "BootupSrvGprot.h"
#include "Gpiosrvgprot.h"
#include "ShutdownSrvGprot.h"
#include "USBSrvGprot.h"

#include "ReminderSrvGprot.h"
#include "ReminderSrv.h"
#include "ReminderSrvUtil.h"
#include "dcl.h"
#include "dcl_pw.h"
#include "dcl_wdt.h"
/****************************************************************************
 * Define
 ****************************************************************************/
#define SRV_RMDR_MALLOC_MSG(type) ((type *)OslConstructDataPtr(sizeof(type)))

/****************************************************************************
 * Typedef
 ****************************************************************************/

/****************************************************************************
 * Global variables
 ****************************************************************************/
extern void ResetLanguageSettingFlag(void);
extern void MMICheckDiskDisplay_Ex(MMI_BOOL force_to_display);


/****************************************************************************
 * Local variables
 ****************************************************************************/

/****************************************************************************
 * Global function
 ****************************************************************************/
static const U8 srv_rmdr_day_of_week[] = 
{
	0x01,	/* DAY_SUN */
	0x02,	/* DAY_MON */
	0x04,	/* DAY_TUE */
	0x08,	/* DAY_WED */
	0x10,	/* DAY_THU */
	0x20,	/* DAY_FRI */
	0x40	/* DAY_SAT */
};


/****************************************************************************
 * Local Function
 ****************************************************************************/

#ifdef __MTK_TARGET__
/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_pwroff_rsp
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_reminder_util_pwroff_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	DCL_HANDLE handle;
    DCL_HANDLE dcl_wdt_handle; 	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_close();
    FS_ClearDiskFlag();
    
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_POWEROFF, NULL);
    DclPW_Close(handle);
	
    dcl_wdt_handle=DclWDT_Open(DCL_WDT, 0);
    DclWDT_Control(dcl_wdt_handle, WDT_CMD_DRV_RESET, 0);    
    DclWDT_Close(dcl_wdt_handle);
//    custom_em_pwn_cycle(KAL_FALSE);
//	srv_shutdown_exit_system(0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_send_pwron
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_reminder_util_pwroff_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_reminder_util_pwroff_rsp, MSG_ID_MMI_SMU_POWER_OFF_RSP);
	
	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_SMU_POWER_OFF_REQ, NULL, NULL);
}
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_send_pwron
 * DESCRIPTION
 *  Display check disk screen, reset language, then send power on request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_reminder_util_send_pwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_mode_enum bootup_mode = srv_bootup_get_booting_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	SRV_RMDR_LOG1(SRV_RMDR_UTIL_PWRON, bootup_mode);
	
    ResetLanguageSettingFlag();

    //MMI_ALM_TRACE1(MMI_RTC_ALARM_SEND_PWRON, bootup_mode);

#ifdef __USB_ENABLE__
    if (bootup_mode == SRV_BOOTUP_MODE_USB)
    {
        /* Temporily disable alarm reset in USB boot mode */
        /*
         * mmi_usb_set_reset_type(ALARM_RESET);
         */
        srv_usb_reset_poweron();
    }
    else
#endif /* __USB_ENABLE__ */ 
    {
    #ifdef __MMI_USB_SUPPORT__
        srv_usb_leave_usb_mode();
    #endif
    
    #ifdef __PLUTO_MMI_PACKAGE__  
        if (bootup_mode == SRV_BOOTUP_MODE_CHARGE || bootup_mode == SRV_BOOTUP_MODE_PRECHARGE)
        {
            //ChargingPwnOnThanPwnOn();
            srv_reminder_util_pwron_req();
            /* turn on backlight to make logo visible for the user */
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            return;
        }
    #endif    
        /*
         * Need to force to display "Check Disk Screen" to update gdi buffer.
         * In "Resotre Factory settings" case, we need force to display to make sure gdi buffer content is correct.
         */
        if (bootup_mode != SRV_BOOTUP_MODE_CHARGE)
    	{
	        MMICheckDiskDisplay_Ex(MMI_TRUE);
    	}

		srv_reminder_util_pwron_req();
        /* turn on backlight to make logo visible for the user */
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_util_pwron_req
 * DESCRIPTION
 *  Send power on request to L4. This function is used for RTC power on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_reminder_util_pwron_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_power_on_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = SRV_RMDR_MALLOC_MSG(mmi_eq_power_on_req_struct);
    myMsgPtr->fun = ALARM_RESET;
    myMsgPtr->rst = 0;

	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_ON_REQ, (oslParaType *)myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_send_pwroff
 * DESCRIPTION
 *  Send power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_reminder_util_send_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_mode_enum bootup_mode = srv_bootup_get_booting_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_UTIL_PWROFF, bootup_mode);
    
#ifdef __USB_ENABLE__
    if (bootup_mode == SRV_BOOTUP_MODE_USB)
    {
        srv_usb_set_reset_type(CHARGING_RESET);
        srv_usb_reset_poweron();
    }
    else
#endif /* __USB_ENABLE__ */ 
    {
        srv_shutdown_exit_system(0);
    }
}


/*****************************************************************************
 * Please refer to ReminderSrvGprot.h
 *****************************************************************************/
MYTIME srv_reminder_calc_time(const MYTIME *time, srv_reminder_repeat_enum freq, U8 week_days)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MYTIME currTime, incTime, t;
	S32 diffStatus, diffStatus2;
	U32 hasDate, j;
#ifdef __MMI_INDICAL__
	U32 days_incremented;
	MYTIME indical_task_time;
#endif /* __MMI_INDICAL__ */

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG2(SRV_RMDR_CALC_TIME, freq, week_days);

	DTGetRTCTime(&currTime);
	memset(&incTime, 0, sizeof(incTime));
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_CURR_TIME,
				  currTime.nYear, 
				  currTime.nMonth, 
				  currTime.nDay, 
				  currTime.nHour, 
				  currTime.nMin, 
				  currTime.nSec);
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_TIME,
				  time->nYear,
				  time->nMonth,
				  time->nDay,
				  time->nHour,
				  time->nMin,
				  time->nSec);

	memcpy(&t, time, sizeof(MYTIME));
	hasDate = (t.nMonth != 0 && t.nDay != 0);

	/* If frequency is days, alarm time should be calculated even it is greater than current time */
	if (CompareTime(t, currTime, NULL) != DT_TIME_GREATER || freq == SRV_REMINDER_REPEAT_DAYS) 
	{
		switch (freq)
		{
			case SRV_REMINDER_REPEAT_ONCE:
			case SRV_REMINDER_REPEAT_HOURLY:
			case SRV_REMINDER_REPEAT_EVERYDAY: 		   
			case SRV_REMINDER_REPEAT_WEEKLY:
				t.nYear = currTime.nYear;
				t.nMonth = currTime.nMonth;
				t.nDay = currTime.nDay;
				if (freq == SRV_REMINDER_REPEAT_ONCE || freq == SRV_REMINDER_REPEAT_EVERYDAY || freq == SRV_REMINDER_REPEAT_HOURLY)
				{
					if (freq == SRV_REMINDER_REPEAT_HOURLY)
					{
						t.nHour = currTime.nHour;
						incTime.nHour = 1;
					}
					else
					{
						incTime.nDay = 1;
					}
					diffStatus = CompareTime(t, currTime, NULL);
					if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)
					{
						IncrementTime(t, incTime, &t);
					}
				}				 
				else	/* frequency == ALM_FREQ_WEEKLY */
				{
					if (t.DayIndex == currTime.DayIndex)
					{
						diffStatus = CompareTime(t, currTime, NULL);
						if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)
						{
							incTime.nDay = 7;
							 IncrementTime(t, incTime, &t);
						}
					}
					else
					{
						incTime.nDay = (7 + t.DayIndex - currTime.DayIndex) % 7;
						IncrementTime(t, incTime, &t);
					}
				}
				break;
				
			case SRV_REMINDER_REPEAT_DAYS:
				diffStatus = CompareTime(t, currTime, NULL);
				/* alarm time is larger than current time, calculate next alarm since alarm time. */
				if (diffStatus == DT_TIME_GREATER) 					
				{	  
					memcpy (&currTime, &t, sizeof(MYTIME));
				}						
				for (j = 0; j < 7; j++)
				{
					if (srv_rmdr_day_of_week[(currTime.DayIndex + j) % 7] & week_days)
					{
						break;
					}
				}
				if (!j) /* if it's the same day */
				{
					/* compare HH:MM:SS */
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
					t.nDay = currTime.nDay;
					diffStatus2 = CompareTime(t, currTime, NULL);
					/* alarm time is less than current time and the HH/MM/SS is less than current time*/
					if (diffStatus != DT_TIME_GREATER && diffStatus2 != DT_TIME_GREATER)//(diffStatus2 == TIME_LESS || diffStatus2 == TIME_EQUAL) )
					{
						/* Find Next Day When then the alarm is scheduled */
						for (j = 1; j < 7; j++)
						{
							if (srv_rmdr_day_of_week[(currTime.DayIndex + j) % 7] & week_days)
							{
								break;
							 }
						}
					}
					else
					{
						break;
					}
				}
				if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)
				{
					currTime.nHour = t.nHour;
					currTime.nMin= t.nMin;
					currTime.nSec= t.nSec;
				}
				incTime.nDay = j;
				IncrementTime(currTime, incTime, &t);
				break;
#ifdef __MMI_INDICAL__
#ifdef __MMI_TODOLIST__
			case SRV_REMINDER_REPEAT_TITHI:
				indical_task_time = t;
				diffStatus = CompareTime(t, currTime, NULL);
				if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)
				{					 
					mmi_indical_find_dow(currTime, &indical_task_time);
					indical_task_time.nHour = t.nHour;
					indical_task_time.nMin = t.nMin;
					indical_task_time.nSec = t.nSec;
					diffStatus = CompareTime(indical_task_time, currTime, NULL);
					while (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL) 				   
					{
						days_incremented = mmi_indical_get_date_for_next_tithi(&indical_task_time, t);
						indical_task_time.nHour = t.nHour;
						indical_task_time.nMin = t.nMin;
						indical_task_time.nSec = t.nSec;
						diffStatus = CompareTime(indical_task_time, currTime, NULL);
					}
					t.nYear = indical_task_time.nYear;
					t.nMonth = indical_task_time.nMonth;
					t.nDay = indical_task_time.nDay;
				}
				break;
#endif /* __MMI_TODOLIST__ */                
#endif /* __MMI_INDICAL__ */
				
			default:
				break;
		}
	}

	/* for yearly, monthly, seasonally, whether alarm time is before or afeter current time, next expiry time should be re-calculated. */
	switch (freq)
	{
#if defined (__MMI_TODOLIST__) || defined (__SYNCML_SUPPORT__) || defined (__COSMOS_MMI_PACKAGE__)
		case SRV_REMINDER_REPEAT_MONTHLY:
				if (!hasDate)
				{
					t.nDay = 1;
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
				}
				else if(CompareTime(t, currTime, NULL) != DT_TIME_GREATER)
				{					
					t.nYear = currTime.nYear;
					t.nMonth = currTime.nMonth;
				}

			diffStatus = CompareTime(t, currTime, NULL);
			if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)	/* || (LastDayOfMonth(t.nMonth, t.nYear) < t.nDay)) */
			{
				if (currTime.nMonth == 12)
				{
						t.nMonth = 1;
					t.nYear++;
				}
				else
				{
						t.nMonth++;
				}
			}
				j = t.nMonth;				 

			for (; j <= 12; j++)
			{
				if (LastDayOfMonth(t.nMonth, t.nYear) >= t.nDay)
				{
					break;
				}
			}
			break;
#endif
#if defined (__MMI_TODOLIST__) || defined (__COSMOS_MMI_PACKAGE__)

		case SRV_REMINDER_REPEAT_YEARLY:
			if (!hasDate)
			{
				t.nYear = currTime.nYear;
				t.nMonth = 1;
				t.nDay = 1;
				}
				else if(CompareTime(t, currTime, NULL) != DT_TIME_GREATER)
				{
					t.nYear = currTime.nYear;
			}

			diffStatus = CompareTime(t, currTime, NULL);
			if (diffStatus == DT_TIME_LESS || diffStatus == DT_TIME_EQUAL)
			{
				if (t.nMonth == 2 && t.nDay == 29)
				{
					incTime.nYear = 4 - ((t.nYear) % 4);
					IncrementTime(t, incTime, &t);
				}
				else
				{
					t.nYear++;
				}
			}
			
			break;
#endif
#ifdef __MMI_THEMES_APPLICATION__ 
		case SRV_REMINDER_REPEAT_SEASONLY:
			t.nYear = currTime.nYear;
			if (!hasDate)
			{
				t.nDay = 1;
			}
			switch (currTime.nMonth)
			{
				case 1:
				case 2:
				case 3:
					t.nMonth = 4;
					break;
				case 4:
				case 5:
				case 6:
					t.nMonth = 7;
					break;
				case 7:
				case 8:
				case 9:
					t.nMonth = 10;
					break;
				default:	/* case 10: case 11: case 12: */
					t.nMonth = 1;
					t.nYear = (currTime.nYear + 1);
					break;
			}
			break;
#endif  /*__MMI_THEMES_APPLICATION__*/
			
		default:
			break;
	}
	
	SRV_RMDR_LOG6(SRV_RMDR_LOG_TIME,
				  t.nYear,
				  t.nMonth,
				  t.nDay,
				  t.nHour,
				  t.nMin,
				  t.nSec);

	return t;
}


