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
 * SyncSrvRemoteRegularSync.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm service management.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#include "SyncSrvSync.h"
#include "SyncSrvRemoteSync.h"
#include "SyncSrvRemoteAccnt.h"
#include "SyncSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "custom_mmi_default_value.h"
#include "app_datetime.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

/*****************************************************************************
* Define
*****************************************************************************/


/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef Ret (*srv_sync_remote_regular_visit_funcptr)(U16);

typedef struct{
	U8	regular_flag[NVRAM_EF_SYNCML_ACCOUNT_TOTAL];
	U8	app_to_sync[NVRAM_EF_SYNCML_ACCOUNT_TOTAL];
	U16 regular_sync[NVRAM_EF_SYNCML_ACCOUNT_TOTAL];
	U32 regular_sync_notify[NVRAM_EF_SYNCML_ACCOUNT_TOTAL];
	U32 timestamp[NVRAM_EF_SYNCML_ACCOUNT_TOTAL];
}srv_sync_remote_regular_cntx;


/*****************************************************************************
* Global Variables 
*****************************************************************************/
static srv_sync_remote_regular_cntx g_srv_sync_remote_regular_cntx;

/*****************************************************************************
* Local Variables 
*****************************************************************************/

void srv_sync_remote_unset_regular_notify(U32 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index] = 0;
}


static void srv_sync_remote_set_regular_notify(U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_REGULAR, 
					accnt_index, 
					g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index]);

	/*
	  * Only apply the first regular sync 
	  */
	if (g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index] == 0)
	{
        U32 timestamp = srv_sync_get_current_time();
        
		g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index] = timestamp;
	}

	//srv_sync_check_regular_sync();
}

void srv_sync_remote_set_regular_info(U8 accnt_index, void *accnt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	nvram_ef_syncml_account_struct *accnt_info = (nvram_ef_syncml_account_struct *)accnt;

	if (g_srv_sync_remote_regular_cntx.regular_sync[accnt_index] != accnt_info->regular_sync)
	{
		g_srv_sync_remote_regular_cntx.regular_sync[accnt_index] = accnt_info->regular_sync;
		g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index] = accnt_info->regular_sync_notify;
	}
	g_srv_sync_remote_regular_cntx.timestamp[accnt_index] = accnt_info->timestamp;
	g_srv_sync_remote_regular_cntx.app_to_sync[accnt_index] = accnt_info->app_to_sync;
}

U32 srv_sync_remote_regular_notify(U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, 0);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_REGULAR, 
					accnt_index, 
					g_srv_sync_remote_regular_cntx.regular_sync[accnt_index]);
	
	return g_srv_sync_remote_regular_cntx.regular_sync_notify[accnt_index];
}


U16 srv_sync_remote_accnt_regular(U8 accnt_index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(accnt_index < NVRAM_EF_SYNCML_ACCOUNT_TOTAL, 0);

	SRV_SYNC_LOG2(MMI_SYNC_SRV_RMT_ACCNT_REGULAR, 
					accnt_index, 
					g_srv_sync_remote_regular_cntx.regular_sync[accnt_index]);
	
	return g_srv_sync_remote_regular_cntx.regular_sync[accnt_index];
}
	
void srv_sync_remote_regular_check(U8 regular, U32 usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_REG_CHECK, regular);
	
	for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{	
		if (srv_sync_remote_accnt_regular(i) == regular)
		{
			/* Only one  accnt can have data change regular sync, so break. */
			if (regular == SRV_SYNC_REGULAR_AT_DATA_CHANGE)
			{
				if (!(g_srv_sync_remote_regular_cntx.app_to_sync[i] & usr_data))
				{
					break;
				}

				/* If the accnt who has regular sync at data change is synchronizing, don't trigger its regular sync */
				if (srv_sync_is_synchronizing())
				{
					srv_sync_enum sync = SRV_SYNC_TOTAL;
					U8 index = 0xFF;
					
					if (srv_sync_active_sync_info(&sync, &index) && (index == i))
					{
						continue;
					}
				}			
			}

			srv_sync_remote_set_regular_notify(i);

            /* After synchrhoing, trigger it. */
            if (!srv_sync_is_synchronizing())
            {
                srv_sync_check_regular_sync();
            }
		}
	}

}


/*****************************************************************************
 * FUNCTION
 *	srv_sync_remote_regular_time
 * DESCRIPTION
 *	Sync alarm callback
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void srv_sync_remote_regular_time(
				U8 index, 
				MYTIME *alarmTime, 
				U8 *repeat, 
				U8 *weekday)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MYTIME currTime;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	applib_dt_get_rtc_time((applib_time_struct *)&currTime);

	switch (srv_sync_remote_accnt_regular(index))
	{
		case SRV_SYNC_REGULAR_EVERY_DAY:
			alarmTime->nYear = currTime.nYear;
			alarmTime->nMonth = currTime.nMonth;
			alarmTime->nDay = currTime.nDay;
			alarmTime->nHour = 12;
			alarmTime->nMin = 0;
			alarmTime->nSec = 0;
			*repeat = SRV_REMINDER_REPEAT_EVERYDAY;
			*weekday = 0;
			break;

		case SRV_SYNC_REGULAR_EVERY_WEEK:
			alarmTime->nYear = currTime.nYear;
			alarmTime->nMonth = currTime.nMonth;
			alarmTime->nDay = currTime.nDay;
			alarmTime->DayIndex = applib_dt_dow(alarmTime->nYear, alarmTime->nMonth, alarmTime->nDay);
			alarmTime->nHour = 12;
			alarmTime->nMin = 0;
			alarmTime->nSec = 0;
			*repeat = SRV_REMINDER_REPEAT_DAYS; /* serveral days in a week */
			*weekday = 0x01; /* Sunday */
			break;

		case SRV_SYNC_REGULAR_EVERY_MONTH:
			alarmTime->nYear = currTime.nYear;
			alarmTime->nMonth = currTime.nMonth;
			alarmTime->nDay = 1;
			alarmTime->nHour = 12;
			alarmTime->nMin = 0;
			alarmTime->nSec = 0;
			*repeat = SRV_REMINDER_REPEAT_MONTHLY;
			*weekday = 0;
			break;

		default:
			alarmTime->nYear = 0;
			alarmTime->nMonth = 0;
			alarmTime->nDay = 0;
			alarmTime->nHour = 0;
			alarmTime->nMin = 0;
			alarmTime->nSec = 0;
			*repeat = SRV_REMINDER_REPEAT_OFF;
			*weekday = 0;
			break;
	}
}


void srv_sync_remote_regular_set_reminder(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME almTime, expTime;
	U8 freq, wday;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_SYNC_LOG1(MMI_SYNC_SRV_RMT_SET_RMDR, index);
	
	if (srv_sync_remote_accnt_regular(index) < SRV_SYNC_REGULAR_EVERY_DAY)
	{
		return;
	}
	
	srv_sync_remote_regular_time(
		index,
		&almTime,
		&freq,
		&wday);
	
	expTime = srv_reminder_calc_time(&almTime, (srv_reminder_repeat_enum)freq, wday);
	
	srv_reminder_set(SRV_REMINDER_TYPE_SYNCML,
					 &expTime,
					 index);	

}

mmi_ret srv_sync_remote_rmdr_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_SYNCML &&
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}

	SRV_SYNC_LOG0(MMI_SYNC_SRV_RMT_RMDR_NOTIFY);
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
		case SRV_REMINDER_NOTIFY_DEINIT:
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
		{
			srv_reminder_notify_finish(MMI_FALSE);
			/* set regular flag*/
			srv_sync_remote_set_regular_notify(remdr_evt->usr_data);
            srv_sync_check_regular_sync();
			break;
		}
		
		case SRV_REMINDER_NOTIFY_REINIT:
		{
			U16 regular;
			U32 i;
			
			for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
			{
				regular = srv_sync_remote_accnt_regular(i);
				if (regular >= SRV_SYNC_REGULAR_EVERY_DAY && 
					regular < SRV_SYNC_REGULAR_TOTAL)
				{
					srv_sync_remote_regular_set_reminder(i);
				}
			}
			break;
		}
		
		default:
			break;
	}

	return MMI_RET_OK;

}


static Ret srv_sync_regular_check_pwron_callback(U16 regular)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/

	if (regular == SRV_SYNC_REGULAR_AT_PWRON)
	{
		return RET_STOP;
	}
	
	return RET_OK;
}

static Ret srv_sync_regular_check_reminder_callback(U16 regular)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/

	if (regular >= SRV_SYNC_REGULAR_EVERY_DAY &&
		regular <= SRV_SYNC_REGULAR_EVERY_MONTH)
	{
		return RET_STOP;
	}
	
	return RET_OK;
}

static Ret srv_sync_regular_check_data_callback(U16 regular)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/

	if (regular == SRV_SYNC_REGULAR_AT_DATA_CHANGE)
	{
		return RET_STOP;
	}
	
	return RET_OK;
}


static U8 srv_sync_remote_foreach_regular(srv_sync_remote_regular_visit_funcptr visit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/

	for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		if (g_srv_sync_remote_regular_cntx.regular_sync_notify[i] != 0 &&
			visit(g_srv_sync_remote_regular_cntx.regular_sync[i]) != RET_OK)
		{
			break;
		}
	}

	return i;
}

void srv_sync_check_regular_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_sync_ask_sync_evt_struct evt;
	U8 index = MAX_SYNCML_SV_PROFILES, i = 0;
	
	srv_sync_remote_regular_visit_funcptr func_tbl[3] =
	{
		/* Power-on sync has the hightest priority */
		srv_sync_regular_check_pwron_callback,
		srv_sync_regular_check_reminder_callback,
		srv_sync_regular_check_data_callback,
	};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/	
	do {
		
		index = srv_sync_remote_foreach_regular(func_tbl[i]);
		i++;
		
	}while(i < 3 && index == MAX_SYNCML_SV_PROFILES);
	
	if (index < MAX_SYNCML_SV_PROFILES)
	{
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SYNC_ASK_SYNC);
		evt.notify_timestamp = g_srv_sync_remote_regular_cntx.regular_sync_notify[index];
		evt.regular = srv_sync_remote_accnt_regular(index);
		evt.accnt_index = index;
		evt.sync = SRV_SYNC_REMOTE;
	
		MMI_FRM_CB_EMIT_POST_EVENT(&evt);
	}
}

S32 srv_sync_has_regular_sync(U16 regular_sync)
{
	U32 i;

	for (i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		if (g_srv_sync_remote_regular_cntx.regular_sync[i] == regular_sync)
		{
			return (S32)i;
		}
	}

	return -1;
}

void srv_sync_finish_regular_sync(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (index < MAX_SYNCML_SV_PROFILES)
	{
		g_srv_sync_remote_regular_cntx.regular_sync_notify[index] = 0;
		srv_sync_remote_regular_set_reminder(index);
	}
	
	srv_sync_check_regular_sync();
}


