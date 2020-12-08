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
 * AlarmSrv.c
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
#include "nvram_common_defs.h"

#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_srv_reminder_def.h"
#include "mmi_rp_srv_alarm_def.h"
#include "DateTimeGprot.h"
#include "ReminderSrvGprot.h"
#include "AlarmSrvGprot.h"
#include "ShutdownSrvGprot.h"

#include "AlarmSrv.h"

/*****************************************************************************
* Typedef 
*****************************************************************************/
typedef enum{
	RET_OK,
	RET_REPLACE,
	RET_STOP,
	RET_OOM, 
	RET_TOTAL
}Ret;

typedef Ret (*visit_funcptr)(void *data, void* usr_data);

typedef struct{
	srv_alm_node_type *list;
	U8 active_index;
	U8 pwroff_sec;
}srv_alm_cntx;


/*****************************************************************************
* Global Variables 
*****************************************************************************/


/*****************************************************************************
* Local Variables 
*****************************************************************************/
static srv_alm_node_type g_srv_alm_list[NUM_OF_ALM];
static srv_alm_cntx g_srv_alm_cntx;


/*****************************************************************************
 * FUNCTION
 *  srv_alm_at_power_reset
 * DESCRIPTION
 *  AT command reset power
 * PARAMETERS
 *  ind     [?]     
 *  in    msg      no action(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_alm_at_power_reset(void *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_power_reset_ind_struct *msg = (mmi_power_reset_ind_struct*) ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(msg->rtc_timer)
	{
		srv_alm_pwr_reset((MMI_BOOL)msg->poweroff, msg->rtc_timer);
	}
	else
	{
		srv_alm_pwr_reset((MMI_BOOL)msg->poweroff, 3);
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_alm_at_query_alm
 * DESCRIPTION
 *  Handler to process query alarm request from AT command
 * PARAMETERS
 *  mod_id	[IN] L4 or L4_2
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_alm_at_query_alm(void *msg_struct, S32 mod_id)
{
#if !defined(__ULC_AT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_query_res_req_struct *rsp;
    S32 i, j;
    MYTIME almTime;
	srv_alm_node_type *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_at_alarm_query_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_alarm_query_res_req_struct));

    rsp->totalAlarm = NUM_OF_ALM;
    rsp->alarmList = NULL;
    rsp->activeAlarm = srv_alm_active_alms();

    if (rsp->activeAlarm != 0)
    {
        /* This memory will be freed at receiver */
        rsp->alarmList = (mmi_at_alarm_info_struct*)
            OslMalloc(sizeof(mmi_at_alarm_info_struct) * rsp->activeAlarm);

        for (i = 0, j = 0; i < NUM_OF_ALM; i++)
        {
        	node = srv_alm_read(i);
            if (node->State == SET_STATE)
            {
                U8 freq;
				GetDateTime(&almTime);

				almTime.nHour = node->Hour;
				almTime.nMin = node->Min;
                rsp->alarmList[j].alarm_index = i;

                almTime = srv_reminder_calc_time(
								&almTime,
								(srv_reminder_repeat_enum)node->Freq,
								node->Days);

                rsp->alarmList[j].date_time.rtc_year = almTime.nYear - YEARFORMATE;
                rsp->alarmList[j].date_time.rtc_wday = almTime.DayIndex;
                rsp->alarmList[j].date_time.rtc_mon = almTime.nMonth;
                rsp->alarmList[j].date_time.rtc_day = almTime.nDay;
                rsp->alarmList[j].date_time.rtc_hour = almTime.nHour;
                rsp->alarmList[j].date_time.rtc_min = almTime.nMin;
                rsp->alarmList[j].date_time.rtc_sec = almTime.nSec;

                freq = node->Freq;
                
                if (freq == ALM_FREQ_ONCE)
                {
                    rsp->alarmList[j].recurr = 0;
                }
                else if (freq == ALM_FREQ_EVERYDAY)
                {
                    rsp->alarmList[j].recurr = ALM_ALL_DAYS;
                }
                else
                {
                    rsp->alarmList[j].recurr = node->Days;
                }
                j++;
            }
        }
    }

	mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_ALARM_QUERY_RES_REQ, (oslParaType*) rsp, NULL);
#endif /* !defined(__ULC_AT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_at_set_alm
 * DESCRIPTION
 *  AT command set alarm
 * PARAMETERS
 *  msg     [?]     Alarm time/index to be set
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_alm_at_set_alm(void *msg, int mod_id)
{
#if !defined(__ULC_AT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_set_req_ind_struct *req = (mmi_at_alarm_set_req_ind_struct*)msg;
    mmi_at_alarm_set_res_req_struct *rsp;
    MYTIME alarmDateTime;
	srv_alm_node_type node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
    rsp = (mmi_at_alarm_set_res_req_struct *)OslConstructDataPtr(sizeof(mmi_at_alarm_set_res_req_struct));

    if (req->alarm.alarm_index < NUM_OF_ALM)
    {
        alarmDateTime.nSec = req->alarm.date_time.rtc_sec;
        alarmDateTime.nMin = req->alarm.date_time.rtc_min;
        alarmDateTime.nHour = req->alarm.date_time.rtc_hour;
        alarmDateTime.nDay = req->alarm.date_time.rtc_day;
        alarmDateTime.nMonth = req->alarm.date_time.rtc_mon;
        alarmDateTime.nYear = req->alarm.date_time.rtc_year + YEARFORMATE;

		node.Hour = alarmDateTime.nHour;
	    node.Min = alarmDateTime.nMin;
	    node.Snooze = 0;
	    node.State = 1;

	    if (req->alarm.recurr == 0)
	    {
	        node.Freq = ALM_FREQ_ONCE;
	    }
	    else if (req->alarm.recurr == 0x7F)
	    {
	        node.Freq = ALM_FREQ_EVERYDAY;
	    }
	    else
	    {
	        node.Freq = ALM_FREQ_DAYS;
	        node.Days = req->alarm.recurr;
	    }
		srv_alm_write(req->alarm.alarm_index, &node);
		rsp->result = KAL_TRUE;
    }
    else
    {
        rsp->result = KAL_FALSE;
    }	
	
	mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_ALARM_SET_RES_REQ, (oslParaType*) rsp, NULL);
	
#endif /* __ULC_AT__ */
}




/*****************************************************************************
 * FUNCTION
 *  mmi_alm_at_cancel_alm
 * DESCRIPTION
 *  AT command cancel alarm
 * PARAMETERS
 *  msg     [?]     Alarm index to be set
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_alm_at_cancel_alm(void *msg, int mod_id)
{
#if !defined(__ULC_AT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_alarm_delete_req_ind_struct *req = (mmi_at_alarm_delete_req_ind_struct*) msg;
    mmi_at_alarm_delete_res_req_struct *rsp;
	srv_alm_node_type *node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (mmi_at_alarm_delete_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_alarm_delete_res_req_struct));

    if (req->alarm_index < NUM_OF_ALM)
    {
		node = srv_alm_read(req->alarm_index);
		if (node->State == 1)   /* alarm is currently on */
		{
		    srv_reminder_cancel(SRV_REMINDER_TYPE_ALM, req->alarm_index);
		}
		memset(node, 0, sizeof(alm_nvram_struct));
		srv_alm_write(req->alarm_index, node);
		rsp->result = KAL_TRUE;		
    }
    else
    {
        rsp->result = KAL_FALSE;
    }
	

	mmi_frm_send_ilm((oslModuleType)mod_id,MSG_ID_MMI_AT_ALARM_DELETE_RES_REQ, (oslParaType*) rsp, NULL);
#endif /* __ULC_AT__ */

}


void arv_alm_at_handler_init(void)
{
	SetProtocolEventHandler(srv_alm_at_power_reset, MSG_ID_MMI_POWER_RESET_IND);	
	SetProtocolEventHandler(srv_alm_at_set_alm, MSG_ID_MMI_AT_ALARM_SET_REQ_IND);
    SetProtocolEventHandler(srv_alm_at_query_alm, MSG_ID_MMI_AT_ALARM_QUERY_REQ_IND);
    SetProtocolEventHandler(srv_alm_at_cancel_alm, MSG_ID_MMI_AT_ALARM_DELETE_REQ_IND);
}


/*****************************************************************************
* FUNCTION
*   srv_alm_for_each_ext
* DESCRIPTION
*   scan all the node table with start and end index
* PARAMETERS
*	table	:[IN]	list table
*	start	:[IN]	start index
*	end		:[IN]	end index
*	visit		:[IN]	vist function pointer
*	usr_data	:[IN]	user data
* RETURNS
*   S32	-> stop position
*****************************************************************************/
static S32 srv_alm_for_each_ext(
				const srv_alm_node_type *table, 
				U32 start, 
				U32 end,
				visit_funcptr visit,
				void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	U32 i = start;
	Ret ret = RET_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL((table != NULL) &&( visit != NULL) && (start < end), NUM_OF_ALM);
	
	while (i < end)
	{
		ret = visit((void*)&table[i], usr_data);
		if (ret != RET_OK)
		{
			break;
		}
		i++;
	}

	return i;

}

static MMI_BOOL srv_alm_set_reminder(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node;
	MYTIME currTime, almTime;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(index < NUM_OF_ALM, MMI_FALSE);
	
	node = &g_srv_alm_list[index];
	
	RETURN_VAL_IF_FAIL(node != NULL, MMI_FALSE);
	RETURN_VAL_IF_FAIL(node->State == 1, MMI_FALSE);

	GetDateTime(&currTime);
	currTime.nSec = 0;

	almTime = currTime;
	almTime.nHour = node->Hour;
	almTime.nMin = node->Min;

	if (node->Snooze != 0)
	{
		MYTIME incTime;
		memset(&incTime, 0, sizeof(MYTIME));

        incTime.nMin = node->SnoozeInterval;
		IncrementTime(currTime, incTime, &almTime);
	}
	
	almTime = srv_reminder_calc_time(&almTime, (srv_reminder_repeat_enum)node->Freq, node->Days);
	srv_reminder_set(SRV_REMINDER_TYPE_ALM, &almTime, index);

	return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*   srv_alm_init_callback
* DESCRIPTION
*   alarm list init callback
* PARAMETERS
*	data		:[IN]	data
*	usr_data	:[IN]	usr_data
* RETURNS
*	Ret
*****************************************************************************/
static Ret srv_alm_init_callback(void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node = (srv_alm_node_type *)data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
#if 0//def __MMI_ALM_CUSTOMIZE_TONE__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_ALM_CUSTOMIZE_TONE__ */

	if (node->SnoozeInterval == 0)
	{
		node->SnoozeInterval = ALM_SNOOZE_INTERVAL + 1;
	}
	return RET_OK;
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
mmi_id srv_alm_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	U32 count = 0, bytes;
	S16 sError;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_ALM_LOG0(SRV_ALM_INIT);
	
	/* Already init */
	if (g_srv_alm_cntx.list != NULL)
	{
		return MMI_RET_OK;
	}
	
	arv_alm_at_handler_init();
	
	do{
		bytes = ReadMultiRecord(
					NVRAM_EF_ALM_ALARM_DATA_LID,
					(count + 1),
					&g_srv_alm_list[count],
					NVRAM_ALM_ALARM_DATA_SIZE * NUM_OF_ALM,
					NUM_OF_ALM - count,
					&sError);
		
		count += bytes / NVRAM_ALM_ALARM_DATA_SIZE;
		
	}while(count < NUM_OF_ALM);

	g_srv_alm_cntx.list = g_srv_alm_list;
	g_srv_alm_cntx.pwroff_sec = 0;
	
	srv_alm_for_each_ext(g_srv_alm_cntx.list, 0, NUM_OF_ALM, srv_alm_init_callback, NULL);	

	return MMI_RET_OK;
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
srv_alm_node_type *srv_alm_read(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_ALM_LOG1(SRV_ALM_READ, index);
	
    RETURN_VAL_IF_FAIL(index < NUM_OF_ALM, NULL);

	return &g_srv_alm_list[index];
}


/*****************************************************************************
* FUNCTION
*   srv_alm_search_active_alm_callback
* DESCRIPTION
*   scan all the node table with start and end index
* PARAMETERS
*	data		:[IN]	node data
*	usr_data	:[IN]	usr_data
* RETURNS
*	Ret
*****************************************************************************/
static Ret srv_alm_search_active_alm_callback(void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node;
	S32 *count;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_OK);

	node = (srv_alm_node_type *)data;
	if (node->Hour != 0xFF && node->State == SET_STATE)
	{
		count = (S32 *)usr_data;
		*count += 1;
	}

	return RET_OK;
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
U8 srv_alm_active_alms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;

    srv_alm_for_each_ext(g_srv_alm_cntx.list,
		0,
		NUM_OF_ALM,
		srv_alm_search_active_alm_callback,
		&count);

	SRV_ALM_LOG1(SRV_ALM_ACTIVE_ALMS, count);
	
    return count;
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
void srv_alm_write(U8 index, void *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 sError;
	srv_alm_op_evt_struct op_evt;
	srv_alm_node_type *new_node = NULL;
    srv_alm_node_type *old_node = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SRV_ALM_LOG1(SRV_ALM_WRITE, index);
	
    MMI_ASSERT(index < NUM_OF_ALM);
    MMI_ASSERT(node != NULL);
	new_node = (srv_alm_node_type *)node;	
    old_node = &g_srv_alm_list[index];

	/* notify app about data change*/
	MMI_FRM_INIT_EVENT(&op_evt, EVT_ID_SRV_ALM_OP);
	op_evt.index = index;
	if(new_node->State == 0 && old_node->State == 1)
	{
	    op_evt.operation = SRV_ALM_OP_DELETE;
	}
    else if(new_node->State == 1 && old_node->State == 0)
	{
	    op_evt.operation = SRV_ALM_OP_ADD;
	}
	else
	{
	    op_evt.operation = SRV_ALM_OP_MODIFY;
	}
	MMI_FRM_CB_EMIT_POST_EVENT(&op_evt);
	
	if (node != &g_srv_alm_list[index])
	{
	    memcpy(&g_srv_alm_list[index], node, sizeof(srv_alm_node_type));
	}
	
    WriteRecord(NVRAM_EF_ALM_ALARM_DATA_LID, 
                (U16)(index + 1), 
                &g_srv_alm_list[index], 
                NVRAM_ALM_ALARM_DATA_SIZE, 
                &sError);

	/* Set reminder */
	srv_reminder_cancel(SRV_REMINDER_TYPE_ALM, index);
	srv_alm_set_reminder(index);

}

void srv_alm_reset_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node;
	U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < NUM_OF_ALM; i++)
	{
		node = srv_alm_read(i);
		if (node->Snooze != 0)
		{
			node->Snooze = 0;
			srv_alm_write(i, node);
		}
		
		srv_alm_set_reminder(i);
	}
}

/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
void srv_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state, U8 *freq, U8 *days)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
    srv_alm_node_type *node;
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
	SRV_ALM_LOG1(SRV_ALM_GET_INFO, index);
	
    MMI_ASSERT(index < NUM_OF_ALM);

	node = (srv_alm_node_type *)srv_alm_read(index);
	*hour = node->Hour;
	*min = node->Min;
	*state = node->State;
    *freq = node->Freq;
    *days = (U8)node->Days;
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
MMI_BOOL srv_alm_get_alm_time(MYTIME *ActualTime, U8 index, MMI_BOOL snooze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_alm_node_type *node;
	MYTIME mytime;
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    RETURN_VAL_IF_FAIL((index < NUM_OF_ALM) && (ActualTime!= NULL), MMI_FALSE);

	node = (srv_alm_node_type *)srv_alm_read(index);

	GetDateTime(&mytime);
	mytime.nHour = node->Hour;
	mytime.nMin = node->Min;

	if (snooze)
	{
		MYTIME inctime;
		memset(&inctime, 0, sizeof(MYTIME));
		inctime.nMin = node->Snooze * node->SnoozeInterval;
		IncrementTime(mytime, inctime, &mytime);
	}

	// Should be mmi_alm_get_freq(node->Freq)
    *ActualTime = srv_reminder_calc_time(&mytime, (srv_reminder_repeat_enum)node->Freq, node->Days);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_search_default_callback
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
static MMI_BOOL srv_alm_search_default_callback(void* data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node;
    MYTIME alm_time, *search_time;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, MMI_FALSE);
	
	node = (srv_alm_node_type*)data;
    if (node->State != 1 || node->Hour == 0xFF)
	{
		return MMI_FALSE;
	}

	GetDateTime(&alm_time);
	alm_time.nHour = node->Hour;
	alm_time.nMin = node->Min;
	alm_time.nSec = 0;

	search_time = (MYTIME *)usr_data;
    ret = CompareTime(alm_time, *search_time, NULL);
    if (ret == DT_TIME_EQUAL || ret == DT_TIME_GREATER)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_alm_compare_default_callback
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
static MMI_BOOL srv_alm_compare_default_callback(U8 index1, U8 index2, MMI_BOOL snooze)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                						*/
    /*----------------------------------------------------------------*/
    MYTIME alarmTime1, alarmTime2;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					*/
    /*----------------------------------------------------------------*/
    srv_alm_get_alm_time(&alarmTime1, index1, snooze);
    srv_alm_get_alm_time(&alarmTime2, index2, snooze);
    
    ret = CompareTime(alarmTime1, alarmTime2, NULL);
    if (ret == DT_TIME_EQUAL || ret == DT_TIME_GREATER)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
void srv_alm_sort(U8 *list, U8 len, MMI_BOOL snooze, srv_alm_cmp_funcptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
    U8 i, j, temp;
    srv_alm_cmp_funcptr funcptr;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					*/
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list != NULL);

    funcptr = callback ? callback : srv_alm_compare_default_callback;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (funcptr(list[i], list[j], snooze))
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}


/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
void srv_alm_search(U8 *list, 
                         U8 size,
                         U8 *count,
                         void *filter, 
                         srv_alm_search_funcptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_alm_search_funcptr funcptr;
    U8 i, cnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list != NULL && count != NULL && filter != NULL);

    cnt = 0;
    funcptr = callback ? callback : srv_alm_search_default_callback;
	
    for (i = 0; i < NUM_OF_ALM; i++)
    {
        if (funcptr(&g_srv_alm_cntx.list[i], filter))
        {
            list[cnt++] = i;
        }
    }

    *count = cnt;
	
	SRV_ALM_LOG1(SRV_ALM_SEARCH, cnt);
}


/*****************************************************************************
* FUNCTION
*   srv_alm_index_callback
* DESCRIPTION
*   alarm list get index callback
* PARAMETERS
*	data		:[IN]	data
*	usr_data	:[IN]	usr_data
* RETURNS
*	Ret
*****************************************************************************/
static Ret srv_alm_index_callback(void *data, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_alm_node_type *node = (srv_alm_node_type *)data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	if (node->Hour == 0xFF)
	{
		return RET_STOP;
	}
	return RET_OK;
}



/*****************************************************************************
 *	Please refer to AlarmSrvGprot.h 
 *****************************************************************************/
U8 srv_alm_get_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	index = srv_alm_for_each_ext(g_srv_alm_cntx.list, 0, NUM_OF_ALM, srv_alm_index_callback, NULL);
	
	return ((index < NUM_OF_ALM) ? index : 0xFF);
}

static void srv_alm_pwr_reset_callback(MMI_BOOL result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	SRV_ALM_LOG1(SRV_ALM_PWR_RESET_CALLBACK, result);
	{
#ifdef __MTK_TARGET__
		srv_reminder_util_pwroff_req();
#else
		exit(0);
#endif	

	}

}

static mmi_ret srv_alm_rmdr_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_ALM_LOG0(SRV_ALM_RMDL_NOTIFY_HDLR);
	RETURN_VAL_IF_FAIL(evt != NULL, MMI_RET_ERR);
	RETURN_VAL_IF_FAIL(evt->evt_id == EVT_ID_SRV_REMINDER_NOTIFY, MMI_RET_OK);
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	SRV_ALM_LOG3(SRV_ALM_RMDL_NOTIFY_HDLR_1,remdr_evt->notify, remdr_evt->pwr_off,remdr_evt->reminder_type);
	
	RETURN_VAL_IF_FAIL(remdr_evt->reminder_type == SRV_REMINDER_TYPE_PWR_RESET || 
					   remdr_evt->reminder_type == SRV_REMINDER_TYPE_TOTAL, 
					   MMI_RET_OK);
	
	switch(remdr_evt->notify)
	{		
		case SRV_REMINDER_NOTIFY_EXPIRY:
			if (remdr_evt->pwr_off)
			{
				srv_reminder_util_send_pwron();
			}			
            else
            {
                // schedule next alarm or other RTC alarm will not be set.
                srv_reminder_notify_finish(MMI_FALSE);
            }
			break;
			
		default:
			break;
	}

	return MMI_RET_OK;
}

static mmi_ret srv_alm_shutdown_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	MYTIME incTime, alarmTime;

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	if (g_srv_alm_cntx.pwroff_sec != 0)
	{
	    SRV_ALM_LOG0(SRV_ALM_SHUTDOWN_HDLR);
		DTGetRTCTime(&alarmTime);
		memset(&incTime, 0, sizeof(MYTIME));
		
		incTime.nSec = (g_srv_alm_cntx.pwroff_sec % 60);
		incTime.nMin = (g_srv_alm_cntx.pwroff_sec / 60);
		IncrementTime(alarmTime, incTime, &alarmTime);

		srv_reminder_set_with_callback(SRV_REMINDER_TYPE_PWR_RESET, &alarmTime, srv_alm_pwr_reset_callback, NULL, 0);

		g_srv_alm_cntx.pwroff_sec = 0;
	}

	return MMI_RET_OK;
}


mmi_ret srv_alm_notify_hdlr(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
    SRV_ALM_LOG1(SRV_ALM_NOTIFY_HDLR, evt->evt_id);
    RETURN_VAL_IF_FAIL(evt != NULL, MMI_RET_ERR);
	
	switch(evt->evt_id)
	{		
		case EVT_ID_SRV_REMINDER_NOTIFY:
			srv_alm_rmdr_notify_hdlr(evt);		
			break;
			
		case EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT:
			srv_alm_shutdown_hdlr(evt);
			break;
			
		default:
			break;
	}

	return MMI_RET_OK;
}

void srv_alm_normal_reset(MMI_BOOL pwr_off, U8 sec)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	SRV_ALM_LOG2(SRV_ALM_NORMAL_RESET, pwr_off, sec);
	
	g_srv_alm_cntx.pwroff_sec = sec;
    
	srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);
	srv_reminder_enable(SRV_REMINDER_TYPE_PWR_RESET, MMI_TRUE);
    
	srv_shutdown_normal_start(0);
}

void srv_alm_pwr_reset(MMI_BOOL pwr_off, U8 sec)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	MYTIME incTime, alarmTime;
	
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	SRV_ALM_LOG2(SRV_ALM_PWR_RESET, pwr_off, sec);
	
	DTGetRTCTime(&alarmTime);
    memset(&incTime, 0, sizeof(MYTIME));
	incTime.nSec = (sec % 60);
	incTime.nMin = (sec / 60);
	IncrementTime(alarmTime, incTime, &alarmTime);
	
	/* PRW_RESET reminder must be set successfully at this moment */
	srv_reminder_enable(SRV_REMINDER_TYPE_TOTAL, MMI_FALSE);
	srv_reminder_enable(SRV_REMINDER_TYPE_PWR_RESET, MMI_TRUE);
	
	srv_reminder_set_with_callback(
		SRV_REMINDER_TYPE_PWR_RESET, 
		&alarmTime,
		srv_alm_pwr_reset_callback,
		NULL,
		0);	
}
