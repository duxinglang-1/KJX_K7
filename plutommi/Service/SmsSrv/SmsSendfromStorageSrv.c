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
 *  SmsSendfromStorageSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Archive handler
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MOD_SMSAL__
#include "MMIDataType.h"
#include "SmsSrvGprot.h"

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "MMI_trc_Int.h"
#include "SmsProtSrv.h"
#include "SmsQueueSrv.h"
#include "SmsSendfromStorageSrv.h"
#include "SmsSenderSrv.h"
#include "SmsUtilSrv.h"
#include "SmsConverterSrv.h"
#include "SmsEmsSrv.h"
#include "SmsStorageSrv.h"
#include "ModeSwitchSrvGProt.h"

/**************************************************************
* MARCO
**************************************************************/
#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
#include "SmsStorageSrv.h"
#include "TimerEvents.h"
#include "MMITimer_Int.h"
#include "sim_common_enums.h"           /* For is_test_sim() */

#define SRV_SMS_SEND_TIME_OUT_SEC     (5)
#define SRV_SMS_SEND_TIME_OUT_COUNT   (1000*SRV_SMS_SEND_TIME_OUT_SEC)
#define SRV_SMS_MAX_SEND_SEQUENCE     (3)

/* Normal SIM */
#define SRV_SMS_SEND_SEQUENCE0_DELAY_TIME_SEC     (0)
#define SRV_SMS_SEND_SEQUENCE1_DELAY_TIME_SEC     (120)   /* 2min */
#define SRV_SMS_SEND_SEQUENCE2_DELAY_TIME_SEC     (300)   /* 5min */
#define SRV_SMS_SEND_SEQUENCE3_DELAY_TIME_SEC     (600)
#define SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC     (1800)

/* TEST SIM */
#define SRV_SMS_SEND_SEQUENCE0_DELAY_TIME_SEC_TEST_SIM     (0)
#define SRV_SMS_SEND_SEQUENCE1_DELAY_TIME_SEC_TEST_SIM     (600)  /* 10min */
#define SRV_SMS_SEND_SEQUENCE2_DELAY_TIME_SEC_TEST_SIM     (1200) /* 20min */ 
#define SRV_SMS_SEND_SEQUENCE3_DELAY_TIME_SEC_TEST_SIM     (1800)
#define SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC_TEST_SIM     (1800)
#endif

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
   U16 msg_id;
   srv_sms_msg_data_struct msg_data;
   MMI_BOOL is_valid;
} srv_sms_send_from_storage_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
MMI_BOOL send_from_storage_is_sending = MMI_FALSE;
SMS_HANDLE send_from_storage_handle = NULL;
MMI_BOOL send_from_storage_is_reading = MMI_TRUE;
srv_sms_send_from_storage_struct *reading_data = NULL;
SrvSmsCallbackFunc abort_callback = NULL;
void *abort_user_data = NULL;
#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
static U16 cur_waiting_number = 0;
static U16 timer_started = MMI_FALSE;
static U16 waiting_msg_id[SRV_SMS_MAX_SMS_ENTRY];
static U16 waiting_secs[SRV_SMS_MAX_SMS_ENTRY];
static U8 send_sequence[SRV_SMS_MAX_SMS_ENTRY];
#endif /* __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__ */

/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
static void srv_sms_send_from_storage_add_info_hdlr(U16 msg_id, U8 sequence);
static void srv_sms_send_from_storage_del_info_hdlr(U16 msg_id);
static void srv_sms_send_from_storage_update_info_hdlr(U16 msg_id, U8 sequence);
static U8 srv_sms_send_get_resend_count(U16 msg_id);
static void srv_sms_send_set_resend_count(U16 msg_id, U8 sequence);
static void srv_sms_send_from_storage_time_out_hdlr(void);
static void srv_sms_send_from_storage_start_timer(void);
#endif /* __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__ */
static void srv_sms_send_from_storage_get_msg_rp_rsp(srv_sms_callback_struct *callback_data);
static void srv_sms_send_from_storage_save_rsp(srv_sms_callback_struct *callback_data);
static MMI_BOOL srv_sms_get_unsent_waiting_index(U16 *msg_id);
static void srv_sms_copy_msg_data_to_init(srv_sms_int_msg_data_struct *dest_data, srv_sms_msg_data_struct *src_data);
static void srv_sms_send_from_storage_write_action(srv_sms_callback_struct* callback_data);
static MMI_BOOL srv_sms_check_unsent_waiting(void);
static void srv_sms_send_from_storage_send_req(srv_sms_queue_data_struct* callback_data);
static void srv_sms_send_from_storage_send_rsp(srv_sms_callback_struct* callback_data);
#ifdef __SRV_SMS_MULTI_ADDR__
static void srv_sms_send_from_storage_result(srv_sms_callback_struct* callback_data);
static void srv_sms_send_from_storage_send_failed(srv_sms_callback_struct* callback_data);
#endif
static void srv_sms_send_from_storage_delete_sent_req(U16 msg_id);
static void srv_sms_send_from_storage_delete_sent_rsp(srv_sms_callback_struct* callback_data);
static void srv_sms_send_from_storage_refresh_ind(U16 index, srv_sms_send_status_enum send_stauts, MMI_BOOL is_send_abort);
static MMI_BOOL srv_sms_set_send_from_storage_msg_status(U16 msg_id, srv_sms_send_status_enum status);
static void srv_sms_send_from_storage_abort_send(U16 msg_id);
static void srv_sms_send_from_storage_abort_send_ext(U16 msg_id, SrvSmsCallbackFunc callback, void *user_data);
static void srv_sms_send_from_storage_schedule_without_refresh(void);


/**************************************************************
* Function Defination
**************************************************************/
mmi_ret srv_sms_send_mode_switch_finish_event_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *flight_mode_evt = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((flight_mode_evt->gsm_curr_mode != SRV_MODE_SWITCH_ALL_OFF)
		&&(flight_mode_evt->gsm_select_mode == SRV_MODE_SWITCH_ALL_OFF)
		)
	{
		U16 msg_list_size;
		U16 index;
		U16 msg_id;
		srv_sms_send_status_enum send_status;

		msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

		for (index = 0; index < msg_list_size; index++)
		{
			msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);
			send_status = srv_sms_get_unsent_msg_status(msg_id);

			if ((send_status == SRV_SMS_SEND_SENDING) || (send_status == SRV_SMS_SEND_WAITING))
			{
			   srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
			}
		}
	}

    return MMI_RET_OK;
}


#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
mmi_ret srv_sms_send_from_storage_del_msg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
        srv_sms_event_delete_struct *event_info;
        U16 msg_id;

        event_info = (srv_sms_event_delete_struct*)event_data->event_info;
        msg_id = event_info->msg_id;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_MSG_PROC, msg_id, cur_waiting_number, event_info->msg_info.status);

        if ((cur_waiting_number > 0) && (event_info->msg_info.status & SRV_SMS_STATUS_UNSENT))
        {
            if (send_from_storage_is_sending && send_from_storage_handle != NULL)
            {
                srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) send_from_storage_handle;
                srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

                MMI_ASSERT(hd_data != NULL);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_MSG_PROC_1, hd_data, hd_data->msg_id);

                if (hd_data->msg_id == msg_id)
                {
                    srv_sms_abort_send(send_from_storage_handle);
                }
                else
                {
                    srv_sms_send_from_storage_del_info_hdlr(msg_id);
                }
            }
            else
            {
                srv_sms_send_from_storage_del_info_hdlr(msg_id);
            }
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_add_info_handle
 * DESCRIPTION
 *  Only can add waiting status msg to info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_add_info_hdlr(U16 msg_id, U8 sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 delay_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_ADD_INFO_HDLR, msg_id, sequence, cur_waiting_number);

#ifdef __GEMINI__  
   if ((is_test_sim(SIM1) == KAL_TRUE) || (is_test_sim(SIM2) == KAL_TRUE))
#else
   if (is_test_sim() == KAL_TRUE )
#endif /* __GEMINI__ */ 		   
	{
	   switch (sequence)
	   {
		   case 1:
			   delay_time = SRV_SMS_SEND_SEQUENCE0_DELAY_TIME_SEC_TEST_SIM;
			   break;
		   case 2:
			   delay_time = SRV_SMS_SEND_SEQUENCE1_DELAY_TIME_SEC_TEST_SIM;
			   break;
		   case 3:
			   delay_time = SRV_SMS_SEND_SEQUENCE2_DELAY_TIME_SEC_TEST_SIM;
			   break;  
		   case 4:
			   delay_time = SRV_SMS_SEND_SEQUENCE3_DELAY_TIME_SEC_TEST_SIM;
			   break;
		   case 5:
			   delay_time = SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC_TEST_SIM;
			   break;
		   default:
			   delay_time = SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC_TEST_SIM;
			break;
	   }				
   }
   else
   {
	    switch (sequence)
	    {
	        case 1:
	            delay_time = SRV_SMS_SEND_SEQUENCE0_DELAY_TIME_SEC;
	            break;
	        case 2:
	            delay_time = SRV_SMS_SEND_SEQUENCE1_DELAY_TIME_SEC;
	            break;
	        case 3:
	            delay_time = SRV_SMS_SEND_SEQUENCE2_DELAY_TIME_SEC;
	            break;  
	        case 4:
	            delay_time = SRV_SMS_SEND_SEQUENCE3_DELAY_TIME_SEC;
	            break;
	        case 5:
	            delay_time = SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC;
	            break;
	        default:
	            delay_time = SRV_SMS_SEND_SEQUENCE4_DELAY_TIME_SEC;
	            break;
	    }
   	}

    waiting_secs[msg_id] = delay_time;
    srv_sms_send_set_resend_count(msg_id, sequence);

    if (cur_waiting_number == 0)
    {
        waiting_msg_id[0] = msg_id;
    }
    else
    {
        U32 i = cur_waiting_number;

        while ((i> 0) && waiting_secs[waiting_msg_id[i-1]] > delay_time)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_ADD_INFO_HDLR_1, i, waiting_msg_id[i-1], waiting_secs[waiting_msg_id[i-1]]);

            waiting_msg_id[i] = waiting_msg_id[i-1];
            i--;    
        }

        waiting_msg_id[i] = msg_id;
    }

    cur_waiting_number++;

    if (!timer_started)
    {
        srv_sms_send_from_storage_start_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_del_info_handle
 * DESCRIPTION
 *  waiting status changes to others will remove from info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_del_info_hdlr(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL find_msg = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_INFO_HDLR, msg_id, cur_waiting_number);

    if ((cur_waiting_number == 1) && (waiting_msg_id[0] == msg_id))
    {
        waiting_msg_id[0] = SRV_SMS_INVALID_MSG_ID;
        find_msg = MMI_TRUE;
    }
    else if (cur_waiting_number > 0)
    {
        U32 i = 0;
        U16 max_index = cur_waiting_number - 1;

        while (i <= max_index && waiting_msg_id[i] != msg_id)
        {
            i++;
        }

        if (i <= max_index)
        {
            find_msg = MMI_TRUE;

            while (i < max_index)
            {
                waiting_msg_id[i] = waiting_msg_id[i+1];
                i++;
            }

            waiting_msg_id[i] = SRV_SMS_INVALID_MSG_ID;
        }
    }

    if (find_msg)
    {
        waiting_secs[msg_id] = 0;
        srv_sms_send_set_resend_count(msg_id, SRV_SMS_MAX_SEND_SEQUENCE);
        cur_waiting_number--;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_INFO_HDLR_1, cur_waiting_number);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_update_info_hdlr
 * DESCRIPTION
 *  Only can add waiting status msg to info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_update_info_hdlr(U16 msg_id, U8 sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_UPDATE_INFO_HDLR);

    srv_sms_send_from_storage_del_info_hdlr(msg_id);
    srv_sms_send_from_storage_add_info_hdlr(msg_id, sequence);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_get_send_sequence
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_sms_send_get_resend_count(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_RESEND_COUNT, msg_id, send_sequence[msg_id]);

    return send_sequence[msg_id];
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_set_resend_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_set_resend_count(U16 msg_id, U8 sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_SET_RESEND_COUNT, msg_id, sequence);

    send_sequence[msg_id] = sequence;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_time_out_handlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_time_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 secs = 0;
	MMI_BOOL is_restart = MMI_FALSE;
	MMI_BOOL is_resend = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_TIME_OUT, cur_waiting_number);

    timer_started = MMI_FALSE;

    for (i = 0; i < cur_waiting_number; i++)
    {
        secs = waiting_secs[waiting_msg_id[i]];

        if (secs > 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_TIME_OUT_1, i, waiting_msg_id[i], secs);

            secs = SRV_SMS_SEND_TIME_OUT_SEC;
            break;
        }
    }

    if (secs > 0)
    {
        U32 j;
        for (j = i; j < cur_waiting_number; j++) /* reduce time out sec for all waiting */
        {
            if (waiting_secs[waiting_msg_id[j]] > secs)
            {
                waiting_secs[waiting_msg_id[j]] -= secs;
				is_restart = MMI_TRUE;
            }
            else
            {
                waiting_secs[waiting_msg_id[j]] = 0;
				is_resend = MMI_TRUE;
            }
        }

        if ((cur_waiting_number > 0) && is_restart) /* if one waiting time>0, need start timer */
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_TIME_OUT_2, cur_waiting_number, is_restart);

            srv_sms_send_from_storage_start_timer();
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_TIME_OUT_3, send_from_storage_is_sending);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_TIME_OUT_4, waiting_msg_id[0], waiting_secs[waiting_msg_id[0]]);

    if ((cur_waiting_number > 0)
        && (send_from_storage_is_sending == MMI_FALSE)
        && is_resend
        )
    {
        srv_sms_send_from_storage_schedule();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_start_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 delay = 0;
    U16 secs = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_START_TIMER, cur_waiting_number);

    for (i = 0; i < cur_waiting_number; i++)
    {
        secs = waiting_secs[waiting_msg_id[i]];

        if (secs > 0)
        {
            delay = SRV_SMS_SEND_TIME_OUT_COUNT;
            break;
        }
    }

    if (delay > 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_START_TIMER_1);

        StartTimer(MESSAGES_CONTINUE_SEND_SMS_PROCESS_TIMER_ID, delay, srv_sms_send_from_storage_time_out_hdlr);
        timer_started = MMI_TRUE;
    }
}

#elif defined(__COSMOS_MMI_PACKAGE__)

mmi_ret srv_sms_send_from_storage_del_msg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
        srv_sms_event_delete_struct *event_info;
        U16 msg_id;

        event_info = (srv_sms_event_delete_struct*)event_data->event_info;
        msg_id = event_info->msg_id;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_MSG_PROC, msg_id, send_from_storage_is_sending, event_info->msg_info.status);

        if (event_info->msg_info.status & SRV_SMS_STATUS_UNSENT)
        {
            if (send_from_storage_is_sending && send_from_storage_handle != NULL)
            {
                srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) send_from_storage_handle;
                srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

                MMI_ASSERT(hd_data != NULL);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DEL_MSG_PROC_1, hd_data, hd_data->msg_id);

                if (hd_data->msg_id == msg_id)
                {
                    srv_sms_abort_send(send_from_storage_handle);
                }
            }
        }
    }

    return MMI_RET_OK;
}
#endif /* __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_get_msg_rp_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_get_msg_rp_rsp(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    SMS_HANDLE save_hd = (srv_sms_handle_struct*)srv_sms_get_save_handle();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result)
    {
        srv_sms_get_msg_reply_path_cb_struct *rp_data = (srv_sms_get_msg_reply_path_cb_struct*)callback_data->action_data;

        if (rp_data->reply_path)
        {
            U16 sc_addr[SRV_SMS_MAX_ADDR_LEN + 1];
            U16 addr_len;

            addr_len = mmi_asc_n_to_ucs2((CHAR*)sc_addr, (CHAR*)rp_data->sc_addr, SRV_SMS_MAX_ADDR_LEN);
            sc_addr[addr_len / ENCODING_LENGTH] = '\0';

            srv_sms_set_sc_address(sms_hd, (CHAR*)sc_addr);
        }
    }

    srv_sms_set_msg_data((SMS_HANDLE)save_hd, &(hd_data->msg_data));

    srv_sms_set_status(save_hd, SRV_SMS_STATUS_UNSENT);

    srv_sms_set_sim_id(save_hd, hd_data->sim_id);

    srv_sms_save_msg(save_hd, srv_sms_send_from_storage_save_rsp, (void*)sms_hd);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_save_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_save_req(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_send_handle_struct *send_hd_data;
    srv_sms_handle_struct *send_hd = (srv_sms_handle_struct*) sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SAVE_REQ, sms_handle);

    send_hd_data = (srv_sms_send_handle_struct*)send_hd->hd_data;

    if (send_hd_data->reply_msg_id == SRV_SMS_INVALID_MSG_ID)
    {
        SMS_HANDLE save_hd = (srv_sms_handle_struct*)srv_sms_get_save_handle();

        srv_sms_set_msg_data((SMS_HANDLE)save_hd, &(send_hd_data->msg_data));

        srv_sms_set_status(save_hd, SRV_SMS_STATUS_UNSENT);

        srv_sms_set_sim_id(save_hd, send_hd_data->sim_id);

        srv_sms_save_msg(save_hd, srv_sms_send_from_storage_save_rsp, (void*)sms_handle);
    }
    else
    {
        srv_sms_get_msg_reply_path(send_hd_data->reply_msg_id, srv_sms_send_from_storage_get_msg_rp_rsp, sms_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_save_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_save_rsp(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    SrvSmsCallbackFunc callback_func = hd_data->callback_func;
    MMI_BOOL is_mms = hd_data->is_mms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SAVE_RSP, sms_hd);

    if (callback_data->result == MMI_TRUE)
    {
        U16 msg_id;
        msg_id = *((U16*)(callback_data->action_data));

        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_WAITING);
    }

    if (callback_func != NULL)
    {
        /* AP's callback */
        hd_data->send_type = SRV_SMS_BG_SEND; /* change type for release buffer */

        srv_sms_send_msg_callback((SMS_HANDLE)sms_hd, callback_data->result, callback_data->cause);
    }

    if (callback_data->result == MMI_FALSE || is_mms == MMI_FALSE)
    {
        /* check if need schedule */
        if (srv_sms_check_unsent_waiting() == MMI_TRUE)
        {
            srv_sms_send_from_storage_schedule();
        }
    }
}


static MMI_BOOL srv_sms_get_unsent_waiting_index(U16 *msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
    U32 index;
    U16 msg_list_size;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_UNSENT_WAITING_MSG_00, cur_waiting_number);

    if (cur_waiting_number > 0)
    {
		U16 i;

		for (i = 0; i < cur_waiting_number; i++)
		{
        	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_UNSENT_WAITING_MSG_01, waiting_msg_id[i], waiting_secs[waiting_msg_id[i]]);

			if (waiting_secs[waiting_msg_id[i]] == 0)
	        {
	            *msg_id = waiting_msg_id[i];
	            return MMI_TRUE;
	        }
		}
    }
#else
    msg_list_size = srv_sms_get_list_size_for_send(SRV_SMS_BOX_UNSENT);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_UNSENT_WAITING_MSG, msg_list_size);

    for (index = 0; index < msg_list_size; index++)
    {
        *msg_id = srv_sms_get_msg_id_for_send(SRV_SMS_BOX_UNSENT, index);

        if (srv_sms_get_unsent_msg_status(*msg_id) == SRV_SMS_SEND_WAITING)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_GET_UNSENT_WAITING_MSG_1, *msg_id);
            return MMI_TRUE;
        }
    }
#endif /* __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__*/

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_data_to_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_copy_msg_data_to_init(srv_sms_int_msg_data_struct *dest_data, srv_sms_msg_data_struct *src_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_COPY_MSG_DATA_INT);

    mmi_ucs2ncpy(dest_data->number, src_data->number, SRV_SMS_MAX_ADDR_LEN);

    dest_data->status = src_data->status;

    if (src_data->para_flag &SRV_SMS_PARA_SCA)
    {
        dest_data->para_flag |= SRV_SMS_PARA_SCA;
        mmi_ucs2ncpy(dest_data->sc_address, src_data->sc_address, SRV_SMS_MAX_ADDR_LEN);
    }

    if (src_data->para_flag &SRV_SMS_PARA_PID)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_PID;
        dest_data->pid = src_data->pid;
    }

    if (src_data->para_flag &SRV_SMS_PARA_DCS)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_DCS;
        dest_data->dcs = src_data->dcs;
    }

    if (src_data->para_flag &SRV_SMS_PARA_REPLY_PATH)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
        dest_data->reply_path = src_data->reply_path;
    }

    if (src_data->para_flag &SRV_SMS_PARA_PORT)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_PORT;
        dest_data->src_port = src_data->src_port;
        dest_data->dest_port = src_data->dest_port;
    }
    if (src_data->para_flag &SRV_SMS_PARA_CONTENT_EMS)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_CONTENT_EMS;
        dest_data->content_ems = src_data->content_ems;
    }
    if (src_data->para_flag &SRV_SMS_PARA_CONTENT_BUFF)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
        dest_data->content_buff = src_data->content_buff;
        dest_data->content_buff_size = src_data->content_buff_size;
    }
    if (src_data->para_flag &SRV_SMS_PARA_CONTENT_FILE)
    {  
        dest_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;
        dest_data->content_file_path = src_data->content_file_path;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_write_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_write_action(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pdu_data = srv_sms_malloc_pdu_data();
    srv_sms_handle_struct *sms_handle;
    srv_sms_send_handle_struct *hd_data;
    srv_sms_send_from_storage_struct *data = (srv_sms_send_from_storage_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_from_storage_is_reading = MMI_FALSE;
    reading_data = NULL;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_WRITE_ACTION, data->is_valid);

    if (data->is_valid == MMI_FALSE)
    {
        U16 msg_id;
        srv_sms_callback_struct callback_data;

        msg_id = data->msg_id;
        srv_sms_free_ems_data(data->msg_data.content_ems);
        OslMfree(data);
        srv_sms_free_pdu_data(pdu_data);

        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
        srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_TRUE);

        if (abort_callback != NULL)
        {
            callback_data.result = MMI_TRUE;
            callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
            callback_data.action = SRV_SMS_ACTION_SEND;
            callback_data.action_data = NULL;
            callback_data.user_data = abort_user_data;
            abort_callback(&callback_data);
            abort_callback = NULL;
            abort_user_data = NULL;
        }

        send_from_storage_handle = NULL;
        send_from_storage_is_sending = MMI_FALSE;
        srv_sms_send_from_storage_schedule();
    }
    else if (callback_data->result == MMI_TRUE)
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        MMI_BOOL check_result = MMI_FALSE;
    #endif
        U32 i;

        sms_handle = OslMalloc(sizeof(srv_sms_handle_struct));
        hd_data = OslMalloc(sizeof(srv_sms_send_handle_struct));

        memset((CHAR*) hd_data, 0, sizeof(srv_sms_send_handle_struct));

        hd_data->send_type = SRV_SMS_BG_SAVE_SEND;

        hd_data->msg_id = data->msg_id;
        hd_data->action_id = SRV_SMS_ACTION_INVALID_ID;
        hd_data->is_abort = MMI_FALSE;

    #ifndef __SRV_SMS_MULTI_SIM__
        hd_data->sim_id = SRV_SMS_SIM_1;
    #else
        hd_data->sim_id = srv_sms_get_msg_sim_id(data->msg_id);
    #endif /* __SRV_SMS_MULTI_SIM__ */

    #ifdef __SRV_SMS_DELIVERY_STATUS__
        hd_data->report_id = SRV_SMS_INVALID_MSG_ID;
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */

        /* copy PDU ????*/
        for (i = 0; i < SRV_SMS_MAX_SEG; i++)
        {
            hd_data->pdu_list[i] = &pdu_data[i * SRV_SMS_MAX_PDU_SIZE];
        }

        srv_sms_copy_msg_data_to_init(&hd_data->msg_data, &(data->msg_data));
        OslMfree(data);

        srv_sms_update_send_msg_profile(hd_data);

    #ifdef __SRV_SMS_MULTI_ADDR__
        if (((hd_data->msg_data.sc_address[0] != '\0') || (hd_data->msg_data.sc_address[1] != '\0'))
            && srv_sms_check_ucs2_number(hd_data->msg_data.sc_address))
        {
            U16 msg_id = hd_data->msg_id;
            U32 max_index = srv_sms_get_msg_addr_num(msg_id) - 1;
            srv_sms_status_enum status;

            while (hd_data->cur_send_index <= max_index)
            {
                srv_sms_get_msg_multi_addr(
                    (WCHAR*)hd_data->msg_data.number,
                    &status,
                    msg_id,
                    hd_data->cur_send_index);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_WRITE_ACTION_1, hd_data->cur_send_index, status);

                if (status & SRV_SMS_STATUS_UNSENT)
                {
                    if (((hd_data->msg_data.number[0] != '\0') || (hd_data->msg_data.number[1] != '\0'))
                        && srv_sms_check_ucs2_number(hd_data->msg_data.number))
                    {
                        check_result = MMI_TRUE;
                        break;
                    }
                }

                hd_data->cur_send_index++;
            }
        }

        if (!check_result)
        {
            srv_sms_callback_struct callback_data;
            callback_data.result = MMI_FALSE;
            callback_data.user_data = sms_handle;
            sms_handle->hd_data = (void*)hd_data;
            srv_sms_free_ems_data(hd_data->msg_data.content_ems);
            srv_sms_send_from_storage_send_failed(&callback_data);
        }
    #else
        if (((hd_data->msg_data.sc_address[0] == '\0') && (hd_data->msg_data.sc_address[1] == '\0'))
            || (srv_sms_check_ucs2_number(hd_data->msg_data.sc_address) == MMI_FALSE)
            || ((hd_data->msg_data.number[0] == '\0') && (hd_data->msg_data.number[1] == '\0'))
            || (srv_sms_check_ucs2_number(hd_data->msg_data.number) == MMI_FALSE))
        {
            srv_sms_callback_struct callback_data;
            callback_data.result = MMI_FALSE;
            callback_data.user_data = sms_handle;
            sms_handle->hd_data = (void*)hd_data;
            srv_sms_free_ems_data(hd_data->msg_data.content_ems);
            srv_sms_send_from_storage_send_rsp(&callback_data);
        }
   #endif
        else
        {
            srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
            error_cause = srv_sms_convert_msg_data_to_pdu(
                hd_data->pdu_list,
                hd_data->pdu_len_list,
                &(hd_data->total_segment),
                NULL,
                &(hd_data->msg_data),
                SRV_SMS_PACK_DEFAULT,
                hd_data->sim_id);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_WRITE_ACTION_2, error_cause);

            if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
            {
                srv_sms_callback_struct callback_data;
                callback_data.result = MMI_FALSE;
                callback_data.user_data = sms_handle;
                sms_handle->hd_data = (void*)hd_data;
                srv_sms_free_ems_data(hd_data->msg_data.content_ems);
            #ifdef __SRV_SMS_MULTI_ADDR__
                srv_sms_send_from_storage_send_failed(&callback_data);
            #else
                srv_sms_send_from_storage_send_rsp(&callback_data);
            #endif
                return;
            }

            hd_data->ref_num = srv_sms_get_curr_concat_ref_num();
            hd_data->is_tp_srr = srv_sms_is_delivery_report_setting(hd_data->sim_id);
        #ifndef __SRV_SMS_MULTI_ADDR__
            srv_sms_free_ems_data(hd_data->msg_data.content_ems);
        #endif
            hd_data->callback_func = srv_sms_send_from_storage_send_rsp;

            hd_data->user_data = (void*) sms_handle;

            sms_handle->hd_data = (void*)hd_data;

            sms_handle->action = SRV_SMS_ACTION_SEND;
            send_from_storage_is_sending = MMI_TRUE;
            send_from_storage_handle = (SMS_HANDLE)sms_handle;

            srv_sms_write_send_bg_action(SRV_SMS_BG_SAVE_SEND, srv_sms_send_from_storage_send_req , (SMS_HANDLE)sms_handle);
        }
    }
    else
    {
        U16 msg_id;
        msg_id = data->msg_id;
        srv_sms_free_ems_data(data->msg_data.content_ems);
        OslMfree(data);
        srv_sms_free_pdu_data(pdu_data);

        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
        srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_FALSE);

        send_from_storage_handle = NULL;
        send_from_storage_is_sending = MMI_FALSE;
        srv_sms_send_from_storage_schedule();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_unsent_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_check_unsent_waiting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (1) /* ?????? */
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_sms_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_send_req(srv_sms_queue_data_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    hd_data->present_seg = 0;
#endif

    srv_sms_bg_send_req(callback_data);
}


#ifdef __SRV_SMS_MULTI_ADDR__
static void srv_sms_send_from_storage_result(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U16 msg_id;
    MMI_BOOL send_finish = MMI_TRUE;
    U32 max_index;
    MMI_BOOL is_send_abort = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = hd_data->msg_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_RESULT, msg_id);
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(msg_id >= SRV_SMS_MAX_MSG_NUM && !storage_cntx.is_tsms_ready)
    {
        srv_sms_free_send_handle((SMS_HANDLE)sms_hd);
        send_from_storage_is_sending = MMI_FALSE;
    #ifdef __SRV_SMS_MULTI_ADDR__
        srv_sms_free_ems_data(hd_data->msg_data.content_ems);
    #endif
        srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, is_send_abort);
        srv_sms_send_from_storage_schedule();
        return;
    }
#endif

    max_index = srv_sms_get_msg_addr_num(msg_id);
    if (max_index > 0)
    {
        max_index --;
    }

    if (hd_data->is_abort == MMI_TRUE)
    {
        is_send_abort = MMI_TRUE;
    }

    if (!is_send_abort && (hd_data->cur_send_index < max_index))
    {
        srv_sms_status_enum status;
        hd_data->cur_send_index++;

        while (hd_data->cur_send_index <= max_index)
        {
            srv_sms_get_msg_multi_addr(
                (WCHAR*)hd_data->msg_data.number,
                &status,
                msg_id,
                hd_data->cur_send_index);

            if (status & SRV_SMS_STATUS_UNSENT)
            {
                if (((hd_data->msg_data.number[0] != '\0') || (hd_data->msg_data.number[1] != '\0'))
                    && (srv_sms_check_ucs2_number(hd_data->msg_data.number) != MMI_FALSE))
                {
                
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_RESULT_1, hd_data->cur_send_index);

                    send_finish = MMI_FALSE;
                    break;
                }
            }

            hd_data->cur_send_index++;
        }
    }

    if (send_finish == MMI_FALSE)
    {
        srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
        error_cause = srv_sms_convert_msg_data_to_pdu(
            hd_data->pdu_list,
            hd_data->pdu_len_list,
            &(hd_data->total_segment),
            NULL,
            &(hd_data->msg_data),
            SRV_SMS_PACK_DEFAULT,
            hd_data->sim_id);
    
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_RESULT_2, error_cause);
    
        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
             srv_sms_write_send_bg_action(
                 SRV_SMS_BG_SAVE_SEND,
                 srv_sms_send_from_storage_send_req,
                 (SMS_HANDLE)sms_hd);
        }
        else
        {
            srv_sms_callback_struct callback_data;
            callback_data.result = MMI_FALSE;
            callback_data.cause = error_cause;
            callback_data.user_data = sms_hd;
            callback_data.action = SRV_SMS_ACTION_SEND;
            srv_sms_send_from_storage_send_rsp(&callback_data);
        }
    }
    else
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        MMI_BOOL send_result = MMI_TRUE;
        srv_sms_status_enum status;
        WCHAR addr[SRV_SMS_MAX_ADDR_LEN+1];
        U32 i;

        for (i = 0; i<= max_index; i++)
        {
            srv_sms_get_msg_multi_addr(
                addr,
                &status,
                msg_id,
                i);

            if (!(status & SRV_SMS_STATUS_SENT))
            {
                send_result = MMI_FALSE;
                break;
            }
        }
    #endif

    #ifdef __SRV_SMS_MULTI_ADDR__
        srv_sms_free_ems_data(hd_data->msg_data.content_ems);
    #endif

        send_from_storage_handle = NULL;

        if (send_result)
        {
            MMI_BOOL isSave = srv_sms_is_save_sent_sms_setting(hd_data->sim_id);

            srv_sms_free_send_handle((SMS_HANDLE)sms_hd);

            srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_SUCCESS);
 
            if (isSave)
            {
                send_from_storage_is_sending = MMI_FALSE;
                srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_SUCCESS, MMI_FALSE);
                srv_sms_send_from_storage_schedule();
            }
            else
            {
                /* delete msg , callback_fun will refresh  */
                srv_sms_send_from_storage_delete_sent_req(msg_id);
            }
        }
        else
        {
            srv_sms_free_send_handle((SMS_HANDLE)sms_hd);

        #ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
            if (!is_send_abort && (srv_sms_send_get_resend_count(msg_id) < SRV_SMS_MAX_SEND_SEQUENCE))
            {
                srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_WAITING);
                srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_WAITING, MMI_FALSE);
            }
            else
        #endif
            {
                srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
                srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, is_send_abort);

                if (is_send_abort)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_RESULT_3, is_send_abort, abort_callback);

                    if (abort_callback != NULL)
                    {
                        srv_sms_callback_struct callback_data;
                        callback_data.result = MMI_TRUE;
                        callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
                        callback_data.action = SRV_SMS_ACTION_SEND;
                        callback_data.action_data = NULL;
                        callback_data.user_data = abort_user_data;
                        abort_callback(&callback_data);
                    }
                }
            }

            send_from_storage_is_sending = MMI_FALSE;
            srv_sms_send_from_storage_schedule();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_send_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sms_hd != NULL);
    MMI_ASSERT(hd_data != NULL);

    msg_id = hd_data->msg_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SEND_RSP, msg_id);

    if (hd_data->action_id != SRV_SMS_ACTION_INVALID_ID)
    {
        srv_sms_queue_delete_action(SRV_SMS_QUEUE_BG, hd_data->action_id);
    }

    if (callback_data->cause == SRV_SMS_CAUSE_SEND_ABORT)
    {
        hd_data->is_abort = MMI_TRUE;
    }

    if (callback_data->result == MMI_TRUE)
    {
    #ifdef __SRV_SMS_MULTI_ADDR__
        if (hd_data->cur_send_index > 0)
        {
            srv_sms_update_addr_struct update_info;

            memset(&update_info, 0, sizeof(srv_sms_update_addr_struct));
            update_info.status = SRV_SMS_STATUS_SENT;
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            if (hd_data->is_tp_srr)
            {
                srv_sms_send_msg_cb_struct *send_cb_data = (srv_sms_send_msg_cb_struct*)callback_data->action_data;
                update_info.total_seg = send_cb_data->total_seg;
                update_info.report_id = send_cb_data->report_id;
                memcpy(update_info.msg_ref, send_cb_data->msg_ref, SRV_SMS_MAX_SEG);
            }
        #endif
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
	    if(msg_id >= SRV_SMS_MAX_MSG_NUM )
	    {
		if(storage_cntx.is_tsms_ready)
                {
                    srv_sms_update_tcard_msg_ext_addr(msg_id, (hd_data->cur_send_index -1), &update_info);
                }     
	    }
	    else
        #endif
	    {
	        srv_sms_update_msg_ext_addr(msg_id, (hd_data->cur_send_index -1), &update_info);
	    }            

            srv_sms_send_from_storage_result(callback_data);
        }
        else /* if (hd_data->cur_send_index == 0) */
    #endif
        {
            SMS_HANDLE *save_hd = srv_sms_get_update_handle();

            srv_sms_set_status(save_hd, SRV_SMS_STATUS_SENT);
        #ifdef __SRV_SMS_DELIVERY_STATUS__
            if (hd_data->is_tp_srr)
            {
                srv_sms_send_msg_cb_struct *send_cb_data = (srv_sms_send_msg_cb_struct*)callback_data->action_data;
                srv_sms_set_msg_ref(save_hd, send_cb_data->msg_ref, send_cb_data->total_seg);
                srv_sms_set_delivery_status(save_hd, send_cb_data->report_id);
            }
        #endif

            srv_sms_update_msg(msg_id, save_hd, srv_sms_send_from_storage_result, sms_hd);
        }
    }
    else
    {
        srv_sms_send_from_storage_result(callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_send_failed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_send_failed(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U16 msg_id;
    MMI_BOOL is_send_abort = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sms_hd != NULL);
    MMI_ASSERT(hd_data != NULL);

    msg_id = hd_data->msg_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SEND_FAILED, msg_id);

    if (hd_data->action_id != SRV_SMS_ACTION_INVALID_ID)
    {
        srv_sms_queue_delete_action(SRV_SMS_QUEUE_BG, hd_data->action_id);
    }

    if (hd_data->is_abort == MMI_TRUE)
    {
        is_send_abort = MMI_TRUE;
    }

    send_from_storage_handle = NULL;

    srv_sms_free_send_handle((SMS_HANDLE)sms_hd);

    srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
    srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, is_send_abort);

    if (is_send_abort)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SEND_FAILED_1, is_send_abort, abort_callback);

        if (abort_callback != NULL)
        {
            srv_sms_callback_struct callback_data;
            callback_data.result = MMI_TRUE;
            callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
            callback_data.action = SRV_SMS_ACTION_SEND;
            callback_data.action_data = NULL;
            callback_data.user_data = abort_user_data;
            abort_callback(&callback_data);
        }
    }

    send_from_storage_is_sending = MMI_FALSE;
    srv_sms_send_from_storage_schedule();
}

#else

/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_send_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_send_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) callback_data->user_data;
    srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_id = hd_data->msg_id;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_SEND, msg_id);

    if (hd_data->action_id != SRV_SMS_ACTION_INVALID_ID)
    {
        srv_sms_queue_delete_action(SRV_SMS_QUEUE_BG, hd_data->action_id);
    }

    send_from_storage_handle = NULL;

    if (callback_data->result == MMI_TRUE)
    {
        MMI_BOOL isSave = srv_sms_is_save_sent_sms_setting(hd_data->sim_id);

        srv_sms_free_send_handle((SMS_HANDLE)sms_hd);


        if (isSave)
        {
            U16 *message_id = OslMalloc(sizeof(U16));

            *message_id = msg_id;

        #ifdef __SRV_SMS_DELIVERY_STATUS__
            {
                srv_sms_send_msg_cb_struct *send_cb_data = (srv_sms_send_msg_cb_struct*)callback_data->action_data;
                SMS_HANDLE *save_hd = srv_sms_get_update_handle();
                srv_sms_set_status(save_hd, SRV_SMS_STATUS_SENT);
                srv_sms_set_msg_ref(save_hd, send_cb_data->msg_ref, send_cb_data->total_seg);
                srv_sms_set_delivery_status(save_hd, send_cb_data->report_id);

                srv_sms_update_msg(msg_id, save_hd, srv_sms_send_from_storage_delete_sent_rsp, (void*)message_id);
            }
        #else /* __SRV_SMS_DELIVERY_STATUS__ */
            srv_sms_change_msg_status(msg_id, SRV_SMS_STATUS_SENT, srv_sms_send_from_storage_delete_sent_rsp, (void*)message_id);
        #endif /* __SRV_SMS_DELIVERY_STATUS__ */
        }
        else
        {
            /* delete msg , callback_fun will refresh  */
            srv_sms_send_from_storage_delete_sent_req(msg_id);
        }
    }
    else
    {
        MMI_BOOL is_send_abort = MMI_FALSE;

        if (callback_data->cause == SRV_SMS_CAUSE_SEND_ABORT)
        {
            is_send_abort = MMI_TRUE;
        }

        srv_sms_free_send_handle((SMS_HANDLE)sms_hd);

    #ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
        if (!is_send_abort && (srv_sms_send_get_resend_count(msg_id) < SRV_SMS_MAX_SEND_SEQUENCE))
        {
            srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_WAITING);
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_WAITING, MMI_FALSE);
        }
        else
    #endif
        {
            srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, is_send_abort);
        }

        send_from_storage_is_sending = MMI_FALSE;

        if (callback_data->cause == SRV_SMS_CAUSE_SEND_ABORT)
        {
            if (abort_callback != NULL)
            {
                srv_sms_callback_struct callback_data;
                callback_data.result = MMI_TRUE;
                callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
                callback_data.action = SRV_SMS_ACTION_SEND;
                callback_data.action_data = NULL;
                callback_data.user_data = abort_user_data;
                abort_callback(&callback_data);
            }
        }

        srv_sms_send_from_storage_schedule();
    }
}
#endif /* __SRV_SMS_MULTI_ADDR__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_delete_sent_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_delete_sent_req(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *message_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DELETE_SENT, msg_id);

    message_id = OslMalloc(sizeof(U16));
    *message_id = msg_id;

    srv_sms_delete_msg(msg_id, srv_sms_send_from_storage_delete_sent_rsp, (void*)message_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_delete_sent_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_send_from_storage_delete_sent_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_DELETE_SENT_RESULT, callback_data->result);

    if (callback_data->result == MMI_TRUE)
    {
        msg_id = *(U16*)(callback_data->user_data);
        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_SUCCESS);
        srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_SUCCESS, MMI_FALSE);
    }
    OslMfree((U16*)callback_data->user_data);

    send_from_storage_is_sending = MMI_FALSE;

    srv_sms_send_from_storage_schedule();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_refresh_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_refresh_ind(U16 index, srv_sms_send_status_enum send_stauts, MMI_BOOL is_send_abort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_update_unsent_msg_status_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_REFRESH_IND, index);

    event_info= OslMalloc(sizeof(srv_sms_event_update_unsent_msg_status_struct));

    event_info->msg_id = index;
    event_info->is_send_abort = is_send_abort;
    event_info->status = send_stauts;
    
    srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS, event_info);
    OslMfree(event_info);

}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_send_from_storage_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_set_send_from_storage_msg_status(U16 msg_id, srv_sms_send_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
    U8 set_sequence = SRV_SMS_MAX_SEND_SEQUENCE;
    U8 sequence;
    srv_sms_send_status_enum old_status = (srv_sms_send_status_enum)srv_sms_get_msg_ext_status(msg_id);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_sms_set_msg_ext_status(msg_id, (U8)status);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_SEND_FROM_STORAGE_MSG_STATUS, msg_id, status);

#ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
    sequence = srv_sms_send_get_resend_count(msg_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_SEND_FROM_STORAGE_MSG_STATUS_1, old_status);

    if (status == SRV_SMS_SEND_FAIL)
    {
        set_sequence = SRV_SMS_MAX_SEND_SEQUENCE;
    }
    else if ((old_status == SRV_SMS_SEND_SENDING) && (status == SRV_SMS_SEND_WAITING))
    {
        set_sequence = sequence + 1;
    }
    else if (((old_status == SRV_SMS_SEND_INVALID) || (old_status == SRV_SMS_SEND_FAIL))
        && (status == SRV_SMS_SEND_WAITING))
    {
        set_sequence = 1;
        sequence = 1;
    }

    if (status == SRV_SMS_SEND_WAITING)
    {
        if (old_status == SRV_SMS_SEND_SENDING)
        {
            srv_sms_send_from_storage_update_info_hdlr(msg_id, set_sequence);
        }
        else
        {
            srv_sms_send_from_storage_add_info_hdlr(msg_id, set_sequence);
        }
    }
    else if ((status != SRV_SMS_SEND_SENDING) && (status != SRV_SMS_SEND_WAITING))
    {
        srv_sms_send_from_storage_del_info_hdlr(msg_id);
    }
#endif /* __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__ */

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_abort_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_abort_send(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    if (send_from_storage_handle != NULL)
    {
        srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) send_from_storage_handle;
        srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_ABORT_SEND, msg_id);

        if (hd_data->msg_id == msg_id)
        {
            srv_sms_abort_send(send_from_storage_handle);
        }

        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
    }
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_abort_send_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_abort_send_ext(U16 msg_id, SrvSmsCallbackFunc callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    if (send_from_storage_handle != NULL)
    {
        srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*) send_from_storage_handle;
        srv_sms_send_handle_struct *hd_data = (srv_sms_send_handle_struct*) sms_hd->hd_data;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_STORAGE_ABORT_SEND, msg_id);

        abort_callback = callback;
        abort_user_data = user_data;

        if (hd_data->msg_id == msg_id)
        {
            srv_sms_abort_send(send_from_storage_handle);
        }

        srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
    }
    else if ((send_from_storage_is_reading == MMI_TRUE) && (reading_data != NULL))
    {
        reading_data->is_valid = MMI_FALSE;
        abort_callback = callback;
        abort_user_data = user_data;
    }
    else
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
    if (callback != NULL)
    {
        srv_sms_callback_struct callback_data;
        callback_data.result = MMI_TRUE;
        callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
        callback_data.action = SRV_SMS_ACTION_SEND;
        callback_data.action_data = NULL;
        callback_data.user_data = user_data;
        callback(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_schedule
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_SCHEDULE, send_from_storage_is_sending);

    if (send_from_storage_is_sending == MMI_FALSE)
    {
        if (srv_sms_is_sms_valid())
        {
            if (srv_sms_get_unsent_waiting_index(&msg_id) == MMI_TRUE)
            {
                srv_sms_send_from_storage_struct *data;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_SCHEDULE_1, msg_id);

                srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_SENDING);
                srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_SENDING, MMI_FALSE);

                data = OslMalloc(sizeof(srv_sms_send_from_storage_struct));
                data->msg_id = msg_id;

                data->msg_data.para_flag = SRV_SMS_PARA_CONTENT_EMS;
                data->msg_data.para_flag |= SRV_SMS_PARA_SCA;
                data->msg_data.content_ems = srv_sms_malloc_ems_data();

                data->is_valid = MMI_TRUE;

                send_from_storage_is_sending = MMI_TRUE;
                send_from_storage_is_reading = MMI_TRUE;
                reading_data = data;
                srv_sms_read_msg(msg_id, MMI_FALSE, &(data->msg_data), srv_sms_send_from_storage_write_action, (void*)data);
            }
        #ifdef __SRV_SMS_BACKGROUND_AUTO_RESEND_SUPPORT__
            else if (cur_waiting_number > 0)
            {
                if (!timer_started)
                {
                    srv_sms_send_from_storage_start_timer();
                }
            }
        #endif
        }
        else if (srv_sms_get_unsent_waiting_index(&msg_id) == MMI_TRUE)
        {
            srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_FALSE);
            srv_sms_send_from_storage_schedule();
        }
    }
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
}


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_schedule_without_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_schedule_without_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_send_from_storage_schedule();
}

#else

/*****************************************************************************
 * FUNCTION
 *  srv_sms_send_from_storage_schedule_without_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_send_from_storage_schedule_without_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    U16 msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_SCHEDULE, send_from_storage_is_sending);

    if (send_from_storage_is_sending == MMI_FALSE)
    {
        if (srv_sms_is_sms_valid())
        {
            if (srv_sms_get_unsent_waiting_index(&msg_id) == MMI_TRUE)
            {
                srv_sms_send_from_storage_struct *data;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SEND_FROM_SCHEDULE_1, msg_id);

                srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_SENDING);
                //srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_SENDING, MMI_FALSE);

                data = OslMalloc(sizeof(srv_sms_send_from_storage_struct));
                data->msg_id = msg_id;

                data->msg_data.para_flag = SRV_SMS_PARA_CONTENT_EMS;
                data->msg_data.para_flag |= SRV_SMS_PARA_SCA;
                data->msg_data.content_ems = srv_sms_malloc_ems_data();

                data->is_valid = MMI_TRUE;

                send_from_storage_is_sending = MMI_TRUE;
                send_from_storage_is_reading = MMI_TRUE;
                reading_data = data;
                srv_sms_read_msg(msg_id, MMI_FALSE, &(data->msg_data),srv_sms_send_from_storage_write_action, (void*)data);
            }
        }
        else if (srv_sms_get_unsent_waiting_index(&msg_id) == MMI_TRUE)
        {
            srv_sms_set_send_from_storage_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_FALSE);
            srv_sms_send_from_storage_schedule();
        }
    }
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
}
#endif /* __COSMOS_MMI_PACKAGE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_unsent_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_set_unsent_msg_status(U16 msg_id, srv_sms_send_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_send_status_enum present_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    present_status = srv_sms_get_unsent_msg_status(msg_id);

    if (present_status == status)
    {
        return MMI_TRUE;
    }

    result = srv_sms_set_send_from_storage_msg_status(msg_id, status);

#ifdef __COSMOS_MMI_PACKAGE__
    if (present_status != 0xFF && present_status != SRV_SMS_SEND_INVALID)
    {
        if (status == SRV_SMS_SEND_FAIL)
        {
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_TRUE);
        }
        else
        {
            srv_sms_send_from_storage_refresh_ind(msg_id, status, MMI_FALSE);
        }
    }
#endif

    if ((present_status == SRV_SMS_SEND_SENDING) && (status == SRV_SMS_SEND_FAIL))
    {
        srv_sms_send_from_storage_abort_send(msg_id);
    }

    if ((present_status == SRV_SMS_SEND_FAIL) && (status == SRV_SMS_SEND_WAITING))
    {
        srv_sms_send_from_storage_schedule_without_refresh();
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_unsent_msg_status_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_unsent_msg_status_ext(U16 msg_id, srv_sms_send_status_enum status, SrvSmsCallbackFunc callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_send_status_enum present_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    present_status = srv_sms_get_unsent_msg_status(msg_id);

    result = srv_sms_set_send_from_storage_msg_status(msg_id, status);

#ifdef __COSMOS_MMI_PACKAGE__
    if (present_status != 0xFF && present_status != SRV_SMS_SEND_INVALID)
    {
        if (status == SRV_SMS_SEND_FAIL)
        {
            srv_sms_send_from_storage_refresh_ind(msg_id, SRV_SMS_SEND_FAIL, MMI_TRUE);
        }
        else
        {
            srv_sms_send_from_storage_refresh_ind(msg_id, status, MMI_FALSE);
        }
    }
#endif

    if ((result == MMI_TRUE) && (present_status == SRV_SMS_SEND_SENDING) && (status == SRV_SMS_SEND_FAIL))
    {
        srv_sms_send_from_storage_abort_send_ext(msg_id, callback, user_data);
    }
    else
    {
        if ((present_status == SRV_SMS_SEND_FAIL) && (status == SRV_SMS_SEND_WAITING))
        {
            srv_sms_send_from_storage_schedule_without_refresh();
        }

        if (callback != NULL)
        {
            srv_sms_callback_struct callback_data;
            callback_data.result = result;
            callback_data.cause = SRV_SMS_CAUSE_SEND_ABORT;
            callback_data.action = SRV_SMS_ACTION_SEND;
            callback_data.action_data = NULL;
            callback_data.user_data = user_data;
            callback(&callback_data);
        }
    }
}

#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */

#endif /* __MOD_SMSAL__ */

