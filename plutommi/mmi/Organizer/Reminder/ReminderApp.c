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
 *  ReminderApp.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Test code from reminder service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#include "MMIDataType.h"
#include "ReminderSrvGprot.h"
#include "UsbDeviceGprot.h"
#include "PowerOnChargerProt.h"
#include "AlarmGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_app_alarm_def.h"
#include "BootupSrvGprot.h"
#include "Wgui_categories_util.h"

#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGprot.h"
#endif

/* For auto close timer in mmi_reminder_entry_pwron_confirm()*/
#include "TimerEvents.h"
#include "AlarmFrameworkProt.h"
#include "AlarmDef.h"
#include "GpioSrvGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef MMI_BOOL (*srv_reminder_check_funcptr)(void);

/****************************************************************************
 * Define
 ****************************************************************************/
#define MMI_RMDR_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)

//#define __REMINDER_UT__
/****************************************************************************
 * Global variables
 ****************************************************************************/

/****************************************************************************
 * Local variables
 ****************************************************************************/
static srv_reminder_check_funcptr srv_reminder_util_check_table[] = 
{
	#ifdef __MMI_USB_SUPPORT__
	srv_usb_is_connected,
	#endif
	mmi_gpio_is_charger_connected,
#ifdef __USB_IN_NORMAL_MODE__
	srv_usb_is_in_mass_storage_mode,
#endif /* __USB_IN_NORMAL_MODE__ */
#ifdef __MMI_WEBCAM__
	mmi_usb_webcam_is_active,
#endif /* __MMI_WEBCAM__ */
	NULL
};


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
static MMI_BOOL mmi_reminder_can_pwroff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	U32 count, j;
	MMI_BOOL ret = MMI_TRUE;
	
	srv_bootup_mode_enum bmode = srv_bootup_get_booting_mode();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/	
    if (bmode == SRV_BOOTUP_MODE_ALARM)
	{
	    return MMI_TRUE;
	}
    
	count = sizeof(srv_reminder_util_check_table) / sizeof(srv_reminder_check_funcptr);
	
	for (j = 0; j < count; j++)
	{
		/* if there is any existed AP, don't pwr-off */
		if (srv_reminder_util_check_table[j] != NULL &&
			srv_reminder_util_check_table[j]())
		{
			ret = MMI_FALSE;
			break;
		}
	}

	MMI_RMDR_TRACE1(MMI_RMDR_CAN_PWR_OFF, ret);
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_confirm_int
 * DESCRIPTION
 *  Internal function for handle power on/off confirm 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void mmi_almfrm_confirm_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
	mmi_frm_scrn_close_active_id();	
    srv_reminder_notify_finish(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_almfrm_pwron
 * DESCRIPTION
 *  Check history before sending power off request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_almfrm_pwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_almfrm_confirm_int();
	srv_reminder_util_send_pwron();
}

/*****************************************************************************
* FUNCTION
*  mmi_almfrm_poweroff
* DESCRIPTION
*  Check history before sending power off request.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_almfrm_poweroff(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
    mmi_almfrm_confirm_int();
    srv_reminder_util_send_pwroff();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_reminder_exit_pwron_confirm
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static void mmi_reminder_exit_pwron_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(ALARM_ALERT_NOTIFYDURATION_TIMER);
    if (srv_reminder_is_expiring())
	{
        /* There is another reminder expiry */        
        mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_ALM_PWRON_CONFIRM);	
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_reminder_entry_pwron_confirm
* DESCRIPTION
*  Display confirmation screen to decide power on or not.
*  This screen is used for power off alarm.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_reminder_entry_pwron_confirm(void)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     U8 *guiBuffer;

     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     if (!mmi_frm_scrn_enter(
             GRP_ID_ROOT, 
             SCR_ID_ALM_PWRON_CONFIRM, 
             (FuncPtr)mmi_reminder_exit_pwron_confirm, 
             (FuncPtr)mmi_reminder_entry_pwron_confirm, 
             MMI_FRM_FULL_SCRN))
     {
         return;
     }
     
     //mmi_alm_disable_pwroff();
	 
     guiBuffer = mmi_frm_scrn_get_active_gui_buf();
     
	 EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
     if (!IsMyTimerExist(ALARM_ALERT_NOTIFYDURATION_TIMER))
     {
         StartTimer(ALARM_ALERT_NOTIFYDURATION_TIMER, ALM_EXPIRE_DURATION, mmi_almfrm_poweroff);
     }    
	 srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
     ShowCategory123Screen(
         STR_GLOBAL_ALARM,
         0,
         STR_GLOBAL_YES,
         IMG_GLOBAL_YES,
         STR_GLOBAL_NO,
         IMG_GLOBAL_NO,
         ALARMS_POWER_ON,
         mmi_get_event_based_image(MMI_EVENT_QUERY),
         guiBuffer);

     SetLeftSoftkeyFunction(mmi_almfrm_pwron, KEY_EVENT_UP);
     SetRightSoftkeyFunction(mmi_almfrm_poweroff, KEY_EVENT_UP);
     ClearKeyHandler(KEY_END, KEY_EVENT_UP);
     ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
     SetKeyHandler(mmi_almfrm_pwron, KEY_END, KEY_LONG_PRESS);
     SetCenterSoftkeyFunction(mmi_almfrm_pwron, KEY_EVENT_UP);

#ifndef __MMI_DEV_NEW_SLIM__
#ifdef __MMI_SUBLCD__
     /* to prevent double displayed this screen */
     mmi_frm_nmgr_notify_sublcd(MMI_SCENARIO_ID_REMINDER_ALARM);
#endif
#endif

}


mmi_ret mmi_reminder_on_pwrreset_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	srv_reminder_pwrreset_evt_struct *pwr_evt;
	srv_bootup_mode_enum mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/
	MMI_ASSERT(evt != NULL);
	
	if (evt->evt_id != EVT_ID_SRV_REMINDER_PWRRESET_REQ)
	{
		return MMI_RET_OK;
	}
	
	pwr_evt = (srv_reminder_pwrreset_evt_struct *)evt;
	mode = srv_bootup_get_booting_mode();
	switch(mode)
	{
		case SRV_BOOTUP_MODE_USB:
		case SRV_BOOTUP_MODE_CHARGE:
		case SRV_BOOTUP_MODE_PRECHARGE:
		{
        	srv_reminder_util_send_pwroff();
            break;
		}

        case SRV_BOOTUP_MODE_ALARM:
		{
			if (!pwr_evt->pwr_confirm)
			{
			    srv_reminder_util_send_pwroff();
			}
			else
			{
                mmi_reminder_entry_pwron_confirm();
			}
			break;
		}

		default:
		{
            srv_reminder_notify_finish(MMI_FALSE);
			break;
		}
	}

	return MMI_RET_OK;
}

/****************************************************************************
 * Test Framework
 ****************************************************************************/
#ifdef __REMINDER_UT__

typedef mmi_ret (*unit_test_func)(void *para);
extern void srv_reminder_dump_queue(void);
extern mmi_ret srv_reminder_on_time_change_notify(mmi_event_struct *evt);

#define ARRAY_COUNT(a) (sizeof(a)/sizeof(a[0]))

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;

static const char *g_ut_type_string[SRV_REMINDER_TYPE_TOTAL + 1] = 
{
	"SRV_REMINDER_TYPE_SPON",
	"SRV_REMINDER_TYPE_THEME",
	"SRV_REMINDER_TYPE_ALM",
    "SRV_REMINDER_TYPE_AZAAN",
	"SRV_REMINDER_TYPE_CAL",
	"SRV_REMINDER_TYPE_TASK",
    "SRV_REMINDER_TYPE_FMSR",
    "SRV_REMINDER_TYPE_FMRDO",            /* FM alarm */
    "SRV_REMINDER_TYPE_SPOF",             /* schedule power off alarm */
    "SRV_REMINDER_TYPE_FACTORY",          /* factory alarm */
    "SRV_REMINDER_TYPE_PWR_RESET",        /* resets alarm */
    "SRV_REMINDER_TYPE_SYNCML",           /* 1 alarm for syncml */
    "SRV_REMINDER_TYPE_LANGLN",           /* language alarm */
	"SRV_REMINDER_TYPE_CUSTOM",
	"SRV_REMINDER_TYPE_TOTAL"
};


static const char *g_ut_ret_string[SRV_REMINDER_RET_TOAL+1] = 
{
	"SRV_REMINDER_RET_OK",
	"SRV_REMINDER_RET_FAIL",
	"SRV_REMINDER_RET_INVALID_DATA",
	"SRV_REMINDER_RET_INVALID_TYPE",
	"SRV_REMINDER_RET_INVALID_INDEX",
	"SRV_REMINDER_RET_INVALID_TIME",
	"SRV_REMINDER_RET_STOP",
	"SRV_REMINDER_RET_TOAL"
};

static mmi_ret mmi_rmdr_ut_add0(void *para)
{
	srv_reminder_type type;
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add0()");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	inc_time.nMin = 1;

	type = 0;
	/*1. wrong time 1*/
	DecrementTime(curr_time, inc_time, &expiry_time);
	ret = srv_reminder_set(type, &expiry_time, 0);
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2,
		"[RMDR_UT]srv_reminder_set() type=%s,ret=%s", 
		g_ut_type_string[type], 
		g_ut_ret_string[ret]);

	/*2. wrong time 2*/	
	expiry_time.nYear = 0;
	expiry_time.nMonth = 0;
	ret = srv_reminder_set(type, &expiry_time, 0);
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
		"[RMDR_UT]srv_reminder_set() type=%s,ret=%s",
		g_ut_type_string[type], 
		g_ut_ret_string[ret]);
	
	/*2. wrong type*/
	IncrementTime(curr_time, inc_time, &expiry_time);
	ret = srv_reminder_set(55, &expiry_time, 0);
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
		"[RMDR_UT]srv_reminder_set() type=%d,ret=%s",
		type, 
		g_ut_ret_string[ret]);

	srv_reminder_dump_queue();

	return MMI_RET_OK;
}


static mmi_ret mmi_rmdr_ut_add1(void *para)
{
	srv_reminder_type i;
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add1()");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	inc_time.nMin = 1;
	IncrementTime(curr_time, inc_time, &expiry_time);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add() 1. priority");
	
	for (i = (SRV_REMINDER_TYPE_TOTAL - 1); i>= 0 ; i--)
	{
		ret = srv_reminder_set(i, &expiry_time, 1);
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2,
			"[RMDR_UT]srv_reminder_set() type=%s,ret=%s", 
			g_ut_type_string[i], 
			g_ut_ret_string[ret]);
	}

	srv_reminder_dump_queue();

	return MMI_RET_OK;
}

static mmi_ret mmi_rmdr_ut_add2(void *para)
{
	srv_reminder_type i, type;
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add()2");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	inc_time.nMin = 1;
	IncrementTime(curr_time, inc_time, &expiry_time);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2,
		"[RMDR_UT]mmi_rmdr_ut_add() 2. test full queue ");

	for (i = 0; i < REMINDER_Q_TOTAL; i++)
	{
		type = (i/SRV_REMINDER_TYPE_TOTAL);
		ret = srv_reminder_set(type, &expiry_time, i);
		
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2,
			"[RMDR_UT]srv_reminder_set() type=%s,ret=%s", 
			g_ut_type_string[type], 
			g_ut_ret_string[ret]);
	}

	srv_reminder_dump_queue();

	return MMI_RET_OK;
}


static mmi_ret mmi_rmdr_ut_add3(void *para)
{
	srv_reminder_type i, type;
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add1()");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	inc_time.nMin = 5;
	IncrementTime(curr_time, inc_time, &expiry_time);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add() 1. type");
	
	for (i = 0; i < 59 ; i++)
	{
		type = i/6;
		ret = srv_reminder_set(i/6, &expiry_time, 2);
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
			"[RMDR_UT]srv_reminder_set() type=%s,ret=%s", 
			g_ut_type_string[type], 
			g_ut_ret_string[ret]);
	}

	srv_reminder_dump_queue();

	return MMI_RET_OK;
}

static mmi_ret mmi_rmdr_ut_add4(void *para)
{
	srv_reminder_type i;
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add4()");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add4() 1. priority");
	
	for (i = 0; i < SRV_REMINDER_TYPE_TOTAL ; i++)
	{
		inc_time.nMin = i + 1;
		IncrementTime(curr_time, inc_time, &expiry_time);
		
		ret = srv_reminder_set(i, &expiry_time, 1);
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2,
			"[RMDR_UT]srv_reminder_set() type=%s,ret=%s", 
			g_ut_type_string[i], 
			g_ut_ret_string[ret]);
	}

	srv_reminder_dump_queue();

	return MMI_RET_OK;
}


void mmi_rmdr_result_callback(MMI_BOOL result)
{

}
S32 mmi_rmdr_cmp_replace_callback(U32 exist, U32 curr)
{
	return 0;
}

S32 mmi_rmdr_cmp_append_callback(U32 exist, U32 curr)
{
	return 1;
}

S32 mmi_rmdr_cmp_nocare_callback(U32 exist, U32 curr)
{
	return -1;
}


static mmi_ret mmi_rmdr_ut_add_with_callback(void *para)
{
	srv_reminder_ret_enum ret;
	MYTIME curr_time, inc_time, expiry_time;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add_with_callback(), one type for any usr_data");

	GetDateTime(&curr_time);

	curr_time.nSec = 0;
	memset(&inc_time, 0, sizeof(MYTIME));
	inc_time.nMin = 1;
	IncrementTime(curr_time, inc_time, &expiry_time);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_add_with_callback() 2. test full queue ");

	ret = srv_reminder_set_with_callback(SRV_REMINDER_TYPE_ALM, 
										&expiry_time, 
										mmi_rmdr_result_callback,
										mmi_rmdr_cmp_replace_callback,
										1);
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  "[RMDR_UT]srv_reminder_set_with_callback(replace) type=%s,ret=%s", 
				  g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  g_ut_ret_string[ret]);

	srv_reminder_dump_queue();
	

	ret = srv_reminder_set_with_callback(SRV_REMINDER_TYPE_ALM, 
										&expiry_time, 
										mmi_rmdr_result_callback,
										mmi_rmdr_cmp_append_callback,
										1);
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  "[RMDR_UT]srv_reminder_set_with_callback(append) type=%s,ret=%s", 
				  g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  g_ut_ret_string[ret]);


	srv_reminder_dump_queue();

	ret = srv_reminder_set_with_callback(SRV_REMINDER_TYPE_ALM, 
										&expiry_time, 
										mmi_rmdr_result_callback,
										mmi_rmdr_cmp_nocare_callback,
										1);
	
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  "[RMDR_UT]srv_reminder_set_with_callback(nocare) type=%s,ret=%s", 
				  g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  g_ut_ret_string[ret]);

	srv_reminder_dump_queue();

	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_cancel(void *para)
{
	srv_reminder_type i;
	srv_reminder_ret_enum ret;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_cancel");

	for (i = (SRV_REMINDER_TYPE_TOTAL - 1); i>= 0 ; i--)
	{
		ret = srv_reminder_cancel(i, 2);
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  	"[RMDR_UT]srv_reminder_cancel(type=%s,usr_data=%d) ,ret=%s", 
				  	g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  	2,
				  	g_ut_ret_string[ret]);		
	}
	
	return MMI_RET_OK;
}

static mmi_ret mmi_rmdr_ut_clear(void *para)
{
	static srv_reminder_type type = SRV_REMINDER_TYPE_CUSTOM;
	srv_reminder_ret_enum ret;
	
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_clear()");

	ret = srv_reminder_clear(type);

	if (type == 0)
	{
		type = SRV_REMINDER_TYPE_CUSTOM;
	}
	else
	{
		type--;
	}
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  	"[RMDR_UT]srv_reminder_clear(type=%s) ,ret=%s", 
				  	g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  	g_ut_ret_string[ret]);	

	srv_reminder_dump_queue();
	
	return MMI_RET_OK;
}

static mmi_ret mmi_rmdr_ut_clear_all(void *para)
{
	srv_reminder_type i;
	srv_reminder_ret_enum ret;

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]mmi_rmdr_ut_clear_all()");

	for (i = (SRV_REMINDER_TYPE_TOTAL - 1); i>= 0 ; i--)
	{
		ret = srv_reminder_clear(i);
		kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				  	"[RMDR_UT]srv_reminder_clear(type=%s) ,ret=%s", 
				  	g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				  	g_ut_ret_string[ret]);			
	}
	
	return MMI_RET_OK;
}

static mmi_ret mmi_rmdr_ut_deinit(void *para)
{
	srv_reminder_deinit();

	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_reinit(void *para)
{
	srv_reminder_on_time_change_notify(NULL);

	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_empty(void *para)
{
	MMI_BOOL ret;
	
	ret = srv_reminder_clear(SRV_REMINDER_TYPE_TOTAL);
	
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				"[RMDR_UT]srv_reminder_clear(type=%s) ,ret=%d", 
				g_ut_type_string[SRV_REMINDER_TYPE_TOTAL],
				ret);

	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_disable(void *para)
{
	MMI_BOOL ret = srv_reminder_enable(SRV_REMINDER_TYPE_ALM, MMI_FALSE);
	
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				"[RMDR_UT]srv_reminder_clear(type=%s) ,ret=%d", 
				g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				ret);

	return MMI_RET_OK;	
}
static mmi_ret mmi_rmdr_ut_disable_all(void *para)
{
	MMI_BOOL ret = srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				"[RMDR_UT]srv_reminder_enable(type=%s) ,ret=%d", 
				g_ut_type_string[SRV_REMINDER_TYPE_TOTAL],
				ret);
	
	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_enable(void *para)
{
	MMI_BOOL ret = srv_reminder_enable(SRV_REMINDER_TYPE_ALM, MMI_TRUE);

	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				"[RMDR_UT]srv_reminder_enable(type=%s) ,ret=%d", 
				g_ut_type_string[SRV_REMINDER_TYPE_ALM],
				ret);
	
	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_enable_all(void *para)
{
	MMI_BOOL ret = srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_TRUE);
	
	kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, 
				"[RMDR_UT]srv_reminder_enable(type=%s) ,ret=%d", 
				g_ut_type_string[SRV_REMINDER_TYPE_TOTAL],
				ret);
	
	return MMI_RET_OK;	
}

static mmi_ret mmi_rmdr_ut_reset(void *para)
{
	//srv_alm_pwr_reset(MMI_FALSE, 3);
	
	return MMI_RET_OK;	
}


static const mmi_unit_test_struct g_mmi_rmdr_ut[] = 
{
	{1,  mmi_rmdr_ut_add0},
	{2,  mmi_rmdr_ut_add1},
	{3,  mmi_rmdr_ut_add2},
	{4,  mmi_rmdr_ut_add3},
	{5,  mmi_rmdr_ut_add4},
	{6,  mmi_rmdr_ut_cancel},
	{7,  mmi_rmdr_ut_deinit},
	{8,  mmi_rmdr_ut_reinit},
	{9,  mmi_rmdr_ut_empty},	
	{10, mmi_rmdr_ut_disable},
	{11, mmi_rmdr_ut_disable_all},
	{12, mmi_rmdr_ut_enable},
	{13, mmi_rmdr_ut_enable_all},
	{14, mmi_rmdr_ut_add_with_callback},
	{15, mmi_rmdr_ut_clear},
	{16, mmi_rmdr_ut_clear_all},
	{17, mmi_rmdr_ut_reset}
};

static void mmi_reminder_ut_timer(void)
{
    static U32  count = 0;
    g_mmi_rmdr_ut[count].test(NULL);
    count++;
    if (count < ARRAY_COUNT(g_mmi_rmdr_ut))
    { 
        StartTimer(KEY_TIMER_ID_NONE, 1000, mmi_reminder_ut_timer);
    }    
}

#endif /* __REMINDER_UT__ */

mmi_ret mmi_remdr_ut_notify_hdlr(mmi_event_struct *evt)
{
#ifdef __REMINDER_UT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if(evt == NULL)
	{
		return MMI_RET_ERR;
	}
	
	if(evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_INIT");
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_EXPIRY");
			srv_reminder_notify_finish(MMI_TRUE);
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			mmi_rmdr_ut_add1(NULL);
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_REINIT");
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_2, "[RMDR_UT]SRV_REMINDER_NOTIFY_DEINIT");
			srv_reminder_notify_finish(MMI_TRUE);
			break;

		default:
			break;
	}


	return MMI_RET_ERR;
#else /* __REMINDER_UT__ */
	return MMI_RET_OK;
#endif /* __REMINDER_UT__ */

}

void mmi_reminder_ut(U8 index)
{
#ifdef __REMINDER_UT__

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI, "[ReminderApp.c] welcome to Reminder UT! ");
	
    if (index == 0)
    {
        StartTimer(KEY_TIMER_ID_NONE, 2000, mmi_reminder_ut_timer);
    }
    else
    {
        for (i = 0; i < ARRAY_COUNT(g_mmi_rmdr_ut); i++)
        {
            if (g_mmi_rmdr_ut[i].index == index)
            {
                g_mmi_rmdr_ut[i].test(NULL);
				break;
            }
        }
    }
#else
	kal_prompt_trace(MOD_MMI, "[ReminderApp.c] Please open UT mode! ");	  
#endif /* __REMINDER_UT__ */
}



