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
 *  CharBatSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for Power On when Charger connects 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"

#include "Device.h"       /* BATTERY_LEVEL_0 */
#include "Mmiapi_struct.h"
#include "mmi_msg_struct.h"
#include "Mmi_frm_queue_gprot.h"
#include "Mmi_frm_events_gprot.h"
#include "Mmi_cb_mgr_gprot.h"
#include "UcmSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "CharBatSrvGprot.h"
#include "CharBatSrvProt.h"
#include "gpiosrvgprot.h"
#if defined(__KJX_FUN__)
#include "Kjx_prin.h"
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* Tells how  many times Battery low ind has been received. after 10 count it reset to -1 */
U8 batteryLowCount = 0;
U8 lowBatteryAlarmThreshold = LBAT_IDLE_DURCNT_NORMAL;

static srv_charbat_cntx_struct g_srv_charbat = 
{
    SRV_CHARBAT_FLAG_ALLOW_MO,       /* other bit-wise is 0 */
    BATTERY_LEVEL_0, /* battery_level; refer battery_level_enum */
    0                /* notify_mod_id; such as MOD_XXX */
};


/***************************************************************************** 
* Local Function
*****************************************************************************/
static void srv_charbat_emit_notify_event(const srv_charbat_evt_notify_struct *data);
static void srv_charbat_low_battery_common_action(void);
static MMI_BOOL srv_charbat_emit_event(U16 event_id);


#define SRV_CHARBAT_API_START


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_init_event_hdlr
 * DESCRIPTION
 *  This function is to initialize the event handler
 * PARAMETERS:
 *  void
 * RETURNS:
 *  void
 *****************************************************************************/
void srv_charbat_init_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
	MSG_ID_MMI_EQ_BATTERY_STATUS_IND, (PsIntFuncPtr)srv_charbat_status_ind_hdlr, MMI_FALSE);
}

#ifdef __GGT_TASK__
#if defined(__CITY_EASY_MODEL_W__)
extern void city_easy_led_on(U16 led_id);
extern void city_easy_led_off(U16 led_id);
extern void city_easy_led_fast(U16 led_id);
#endif
#endif

#if defined(__KJX_FUN__)
#if defined(CUSTOMER_NAME_TOUR)
#include "..\..\kjx\tour\kjx_main_tour.h"
void kjx_tour_charge_led(U16 led_type);
extern BOOL kjx_is_in_charge;
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_status_ind_hdlr
 * DESCRIPTION
 *  Respond for battery status indication, handle battery level or charger status notify
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
#include "PowerOnChargerProt.h"
extern charbat_context_struct g_charbat_context;
extern void kjx_factory_charge_test_end(void);
void srv_charbat_status_ind_hdlr(void *info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_charbat_evt_notify_struct evt = {0};
	mmi_eq_battery_status_ind_struct *p = (mmi_eq_battery_status_ind_struct*) info;
	static U16 lowPlay = 0;
#if defined(__KJX_BAT_STATUS_LED_SHOW__)
	static BOOL is_low_bat = FALSE;
#endif
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	srv_charbat_send_ack(p->battery_status);
	if (srv_shutdown_is_running())
	{
		return;
	}

	evt.status = (pmic_status_enum)p->battery_status;
	evt.battery_level = (battery_level_enum)p->battery_voltage;

#if defined(__KJX_LOG_OUTPUT__)
	LOGD("status:%d, voltage:%d", p->battery_status, p->battery_voltage);
#endif

	switch (p->battery_status)
	{
	case PMIC_USB_CHARGER_IN: 
	case PMIC_CHARGER_IN:
		{
		#ifdef __GGT_TASK__
		  #if defined(__CITY_EASY_MODEL_W__)
			city_easy_led_on(0);/*充电，红灯常亮*/
		  #endif
		#endif

		#if defined(__KJX_FUN__)
		  #if defined(CUSTOMER_NAME_TOUR)
			kjx_is_in_charge = TRUE;
		   #if defined(__KJX_BAT_STATUS_LED_SHOW__)
			kjx_tour_battery_status_led(BATTERY_CHARGING_STATUS);
		   #else
			kjx_tour_charge_led(0);//LED_FAST
		   #endif

			if((kjx_get_foctory_test_mode() == 1) && (kjx_get_test_mode_charge()==1))
			{
				kjx_factory_charge_test_end();
			}
		  #endif
		#endif

			if (PMIC_CHARGER_IN == p->battery_status) /* pwronUsb, when receive charger_in, will shutdown */
			{
				MMI_TRACE(SRV_CHARBAT_TRC, TRC_SRV_CHARBAT_EXT, 1, uem_get_power_on_mode());
				if ((uem_get_power_on_mode() == POWER_ON_USB) && !srv_reminder_is_reminder_active())
				{
					mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_OFF_REQ, NULL, NULL);
					return;
				}
			}
			srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
			if (srv_charbat_is_low_battery())
			{
				srv_charbat_set_low_bat_flag(MMI_FALSE);
				srv_led_pattern_stop_battery_warning();
			}
			break;
		}
	
	case PMIC_USB_NO_CHARGER_IN:
		{
			//emit event   
			break;
		}
	
	case PMIC_USB_NO_CHARGER_OUT: /* if handle, need Jianhua confirm */
	case PMIC_USB_CHARGER_OUT:
	case PMIC_CHARGER_OUT:
		{
		#ifdef __GGT_TASK__
		  #if defined(__CITY_EASY_MODEL_W__)
			city_easy_led_off(0);/*拔掉充电器*/
		  #endif
		#endif

		#if defined(__KJX_FUN__)
		  #if defined(CUSTOMER_NAME_TOUR)
			kjx_is_in_charge = FALSE;
		  	if(srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL)
			{
			#if defined(__KJX_BAT_STATUS_LED_SHOW__)
				if(p->battery_voltage > BATTERY_LEVEL_0)
				{
					kjx_tour_battery_status_led(BATTERY_NORMAL_STATUS);		  		
				}
				else
				{
					kjx_tour_battery_status_led(BATTERY_LOW_STATUS);
				}
			#else
				kjx_tour_charge_led(3);//LED_OFF
			#endif
			}
		  #endif
		#endif

			srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGER_OUT);
			break;
		}

	case PMIC_CHARGE_COMPLETE:  /* battery full charged. */
		{
		#ifdef __GGT_TASK__
		  #if defined(__CITY_EASY_MODEL_W__)
			/*充满电*/
		  #endif
		#endif

		#if defined(__KJX_FUN__)
		  #if defined(CUSTOMER_NAME_TOUR)
			kjx_is_in_charge = TRUE;
			lowPlay = 0;
		   #if defined(__KJX_BAT_STATUS_LED_SHOW__)
			kjx_tour_battery_status_led(BATTERY_FULL_STATUS);
		   #else
			kjx_tour_charge_led(2);//LED_ON
		   #endif
		  #endif
		#endif
		
		#if defined(__KJX_FUN__)
			srv_charbat_set_bat_level(SRV_CHARBAT_BATTERY_LEVEL_4);
		#else
			srv_charbat_set_bat_level(SRV_CHARBAT_BATTERY_LEVEL_3);
		#endif
		
		#ifdef __COSMOS_MMI_PACKAGE__
			srv_charbat_set_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);
		#endif
			break;
		}

	case PMIC_VBAT_STATUS:
		{
		#ifdef __GGT_TASK__
		  #if defined(__CITY_EASY_MODEL_W__)
			if(p->battery_voltage <= BATTERY_LEVEL_0) /*电量低，快闪*/
				city_easy_led_fast(0);
		  #endif
		#endif

		#if defined(__KJX_FUN__)
		  #if defined(CUSTOMER_NAME_TOUR)
		   #if defined(__KJX_BAT_STATUS_LED_SHOW__)
			if(srv_charbat_is_charging())
			{
				if(g_charbat_context.ChargingComplete == 1)
				{
					kjx_tour_battery_status_led(BATTERY_FULL_STATUS);
				}
				else
				{
					kjx_tour_battery_status_led(BATTERY_CHARGING_STATUS);
				}
			}
			else if(mmi_gpio_is_charging_full())
			{
				kjx_tour_battery_status_led(BATTERY_FULL_STATUS);
			}
			else
			{	
				if(is_low_bat)	//xb add 2016-09-10 防止电池电压在阈值波动时显示异常
				{
					if(p->battery_voltage > BATTERY_LEVEL_0)
					{
						is_low_bat = FALSE;
						kjx_tour_battery_status_led(BATTERY_NORMAL_STATUS);
						srv_charbat_set_low_bat_flag(MMI_FALSE);
					}
					else
					{
						kjx_tour_battery_status_led(BATTERY_LOW_STATUS);
					}					
				}
				else
				{
					if(p->battery_voltage > BATTERY_LEVEL_0)
					{
						kjx_tour_battery_status_led(BATTERY_NORMAL_STATUS);
					}
					else
					{
						is_low_bat = TRUE;
						kjx_tour_battery_status_led(BATTERY_LOW_STATUS);
						srv_charbat_set_low_bat_flag(MMI_TRUE);
					}	
				}
			}
		   #else		  
			if(p->battery_voltage <= BATTERY_LEVEL_0) /*电量低，快闪*/
			{
				if ((!srv_charbat_is_charging())&&(lowPlay<3))
				{
					lowPlay++;
					ChgrPlayLowBatTone();
				}
			}
		   #endif
		  #endif
		#endif

			srv_charbat_set_bat_level(p->battery_voltage);
		#if 0 
			/* under construction !*/
		#endif
			srv_charbat_bat_status_hdlr(p->battery_voltage);
			break;
		}

	case PMIC_INVALID_BATTERY:
	case PMIC_OVERBATTEMP:
	case PMIC_OVERVOLPROTECT:
	case PMIC_OVERCHARGECURRENT:
	case PMIC_LOWBATTEMP:
	case PMIC_CHARGING_TIMEOUT:
	case PMIC_INVALID_CHARGER:
	case PMIC_LOWCHARGECURRENT:
	case PMIC_CHARGE_BAD_CONTACT:
	case PMIC_BATTERY_BAD_CONTACT:
		break;

	default:
		break;
	}

	srv_charbat_emit_notify_event((const srv_charbat_evt_notify_struct *) &evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_emit_notify_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data          [IN]      srv_charbat_evt_notify_struct  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_charbat_emit_notify_event(const srv_charbat_evt_notify_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_charbat_evt_notify_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CHARBAT_NOTIFY);

    evt.status = data->status;
    evt.battery_level = data->battery_level;

    MMI_TRACE(
        SRV_CHARBAT_TRC,
        TRC_SRV_CHARBAT_EMIT_NOTIFY_EVENT,
        evt.status,
        evt.battery_level);

    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_check_if_mo_allow
 * DESCRIPTION
 *  This function checks if outgoing call is allowed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE:  MO allowed
 *  MMI_FALSE: MO not allowed
 *****************************************************************************/
MMI_BOOL srv_charbat_check_if_mo_allow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 1 /* we don't limit make call, if customer want this threshold, pls modify 1 to 0 */
    return MMI_TRUE;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_if_mo_allow
 * DESCRIPTION
 *  This function set flag which indicat if outgoing call is allowed or not.
 * PARAMETERS
 *  allow_flag   [IN]  MMI_TRUE: allow
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_set_mo_allow_flag(MMI_BOOL allow_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (allow_flag)
        SRV_CHARBAT_SET_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_ALLOW_MO);
    else
        SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_ALLOW_MO);
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_get_battery_level
 * DESCRIPTION
 *  This function to get current battery level.
 *  please refer to battery_level_enum for the definition of battery level
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_charbat_battery_level_enum : please refer to battery_level_enum
 *****************************************************************************/
srv_charbat_battery_level_enum srv_charbat_get_battery_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_charbat_battery_level_enum)g_srv_charbat.battery_level;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_bat_level
 * DESCRIPTION
 *  This function set current battery level.
 * PARAMETERS
 *  bat_level   [IN]  U8
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_set_bat_level(U8 bat_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_charbat.battery_level = bat_level;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_low_bat_flag
 * DESCRIPTION
 *  This function set current low battery flag.
 * PARAMETERS
 *  low_flag   [IN]  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_set_low_bat_flag(MMI_BOOL low_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (low_flag)
        SRV_CHARBAT_SET_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_LOW_BATTERY);
    else
        SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_LOW_BATTERY);
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_is_charging
 * DESCRIPTION
 *  This function get current charger status: if chargering
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, is chargering
 *****************************************************************************/
MMI_BOOL srv_charbat_is_charging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGER_IN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_is_charger_connect
 * DESCRIPTION
 *  This function get current charger status: if connect
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, is connect
 *****************************************************************************/
MMI_BOOL srv_charbat_is_charger_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CHARBAT_CHECK_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_CONNECT))
        return MMI_TRUE;
    
    return MMI_FALSE;
}

#if defined(__CITY_EASY_MODEL_W__) ||defined(CUSTOMER_NAME_B603)
extern void cityeasy_alarm_status_set_and_send(U8 state);
#endif /* __CITY_EASY_MODEL_W__ */
#if defined(CUSTOMER_NAME_B603)
extern void cityeasy_battery_low_warring(void);
extern void cityeasy_battery_set_warring_state(kal_bool state);
#endif /* CUSTOMER_NAME_B603 */

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_is_low_battery
 * DESCRIPTION
 *  This function get current battery level: if low
 *  Note: this flag only means BATTERY_LEVEL_WARNING, not PowerOff level
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, battery level is low
 *****************************************************************************/
MMI_BOOL srv_charbat_is_low_battery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_CHARBAT_CHECK_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_LOW_BATTERY))
    {
	#if defined(__CITY_EASY_MODEL_W__) || defined(CUSTOMER_NAME_B603)
    	cityeasy_alarm_status_set_and_send(0x0a);
	#if defined(CUSTOMER_NAME_B603)
		cityeasy_battery_low_warring();
	#endif /* CUSTOMER_NAME_B603 */
	#endif /* __CITY_EASY_MODEL_W__ */
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_get_charger_status
 * DESCRIPTION
 *  This function get current charger status: chargering or charger completed...
 * PARAMETERS
 *  status_id  [IN]  srv_charbat_flag_enum
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, query status is going
 *****************************************************************************/
MMI_BOOL srv_charbat_get_charger_status(srv_charbat_status_enum status_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL query_ret = MMI_FALSE;      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_id)
    {
        case SRV_CHARBAT_STATUS_CHARGER_IN:
            if (SRV_CHARBAT_CHECK_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGING))
                query_ret = MMI_TRUE;
            break;

        case SRV_CHARBAT_STATUS_CHARGE_COMPLETE:
            if (SRV_CHARBAT_CHECK_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_COMPLETE))
                query_ret = MMI_TRUE;
            break;

        default :
            query_ret = MMI_FALSE;
            ASSERT(0);
            break;
    }
    return query_ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_charger_status
 * DESCRIPTION
 *  This function set current charger status: chargering or charger completed...
 * PARAMETERS
 *  status_id  [IN]  srv_charbat_status_enum
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, set success
 *****************************************************************************/
MMI_BOOL srv_charbat_set_charger_status(srv_charbat_status_enum status_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status_id)
    {            
        case SRV_CHARBAT_STATUS_CHARGER_OUT:
            SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGING);
            SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_CONNECT);
            SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_COMPLETE);
            break;

        case SRV_CHARBAT_STATUS_CHARGER_IN:
            SRV_CHARBAT_SET_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGING);
            SRV_CHARBAT_SET_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_CONNECT);
            SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_COMPLETE);
            break;

        case SRV_CHARBAT_STATUS_CHARGE_COMPLETE:
            SRV_CHARBAT_SET_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGE_COMPLETE);
            SRV_CHARBAT_CLEAR_BIT(g_srv_charbat.flag, SRV_CHARBAT_FLAG_CHARGING);
            break;

        default :
            //ASSERT(0);
            break;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_bat_status_hdlr
 * DESCRIPTION
 *  This function handle diff battery status, such as TX_PROHIBIT/WARNING.
 * PARAMETERS
 *  bat_level  [U8] battery_level_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_bat_status_hdlr(U8 bat_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, 
        TRC_MMI_GPIO_PMIC_LOW_BATTERY_HANDLER, 
        lowBatteryAlarmThreshold, 
        batteryLowCount, 
        srv_charbat_is_low_battery(),
        srv_charbat_check_if_mo_allow());
    
    switch (bat_level)
    {
        case BATTERY_LOW_POWEROFF: 
        {
            /* MMI will hander this low power off when receive EVT_ID_SRV_CHARBAT_NOTIFY */
            break;
        }
        
        case BATTERY_LOW_TX_PROHIBIT:
        {
            srv_charbat_set_mo_allow_flag(MMI_FALSE);

            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
            {
                srv_charbat_set_low_bat_threshold(LBAT_IDLE_DURCNT_PROHIBIT);
            }
            else
            {
                srv_charbat_set_low_bat_threshold(LBAT_TALK_DURCNT_PROHIBIT);
            }
            srv_charbat_set_low_bat_flag(MMI_TRUE);
            srv_charbat_low_battery_common_action();
            break;
        }
        
        case BATTERY_LOW_WARNING:
        {
            srv_charbat_set_mo_allow_flag(MMI_TRUE);
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
            #endif
            srv_charbat_set_low_bat_threshold(LBAT_IDLE_DURCNT_NORMAL);
            srv_charbat_set_low_bat_flag(MMI_TRUE);
            srv_charbat_low_battery_common_action();
            break;
        }

        case BATTERY_LEVEL_0:   /* pass */
        case BATTERY_LEVEL_1:   /* pass */
        case BATTERY_LEVEL_2:   /* pass */
        case BATTERY_LEVEL_3:   /* pass */
        default:
        {
            batteryLowCount = 0;  /* reset low battery ind count */
			lowBatteryAlarmThreshold = 0; /* reset, to show UI when battery low again */
            srv_charbat_set_low_bat_flag(MMI_FALSE);
            srv_charbat_set_mo_allow_flag(MMI_TRUE);
	#if defined(__CITY_EASY_MODEL_W__) ||defined(CUSTOMER_NAME_B603)
		cityeasy_battery_set_warring_state(MMI_TRUE);
	#endif /* CUSTOMER_NAME_B603 */
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_low_battery_common_action
 * DESCRIPTION
 *  Handles the common action for low battery.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_charbat_low_battery_common_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_booting())
    {
        srv_charbat_reset_low_bat_cnt();
    }
    else
    {
        if (!srv_charbat_is_charging() && batteryLowCount >= lowBatteryAlarmThreshold)
        {
            batteryLowCount = 0;
            srv_charbat_emit_event(EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER); // show UI notify
            srv_led_pattern_start_battery_low();
            MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_LOW_BATTERY);
        }
    }

    batteryLowCount++;
}

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_low_bat_threshold
 * DESCRIPTION
 *  TThis function sets the thresh hold for low battery handler.
 * PARAMETERS
 *  cnt     [IN]        The thresh value count
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_set_low_bat_threshold(U32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*********************************************************/
    /***** The threshold will be changed when:*****/
    /*********************************************************/
    /* 1. MT Call Accepted */
    /* 2. Call END */
    /* 3. Make MO Call */
    /* 4. SAT Call setup */
    /*********************************************************/
    if (lowBatteryAlarmThreshold == cnt)
        return;

    lowBatteryAlarmThreshold = cnt;
    batteryLowCount = lowBatteryAlarmThreshold;
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_reset_low_bat_cnt
 * DESCRIPTION
 *  This function reset battery low alert count.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_reset_low_bat_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Set counter to threshold value so that MMI will alert at next indication
     * (the indication will comes to MMI by 1 minute ( depends on custom setting) 
     */
    batteryLowCount = lowBatteryAlarmThreshold;
}


#define SRV_CHARBAT_ASYNC_MSG_API

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_get_bat_level_req
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_GET_BATTERY_LEVEL_REQ, async to get current battery level
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_get_bat_level_req(void *msg)
{
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
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_start_notify_bat_level_req
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_START_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_start_notify_bat_level_req(void *msg)
{
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
}




/*****************************************************************************
 * FUNCTION
 *  srv_charbat_stop_notify_bat_level_req
 * DESCRIPTION
 *  Handler of MSG_ID_MMIAPI_BATTERY_LEVEL_NOTIFY_STOP_REQ
 * PARAMETERS
 *  msg     [IN]        Requested data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_stop_notify_bat_level_req(void *msg)
{
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
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_notify_bat_level
 * DESCRIPTION
 *  after one MOD_XXX start notify req, will notify battery level to MOD_XXX
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_reset_pwron
 * DESCRIPTION
 *  Fn to be called to power on the phone for long press of End key during pwr_on_charging
 *  on charger.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_reset_pwron(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_power_on_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    myMsgPtr = (mmi_eq_power_on_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_power_on_req_struct));
    myMsgPtr->fun = ALARM_RESET;
    myMsgPtr->rst = 0;
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_CHARGER_POWERKEY_ON);

    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_POWER_ON_REQ, 
                    (oslParaType*) myMsgPtr, NULL);

}


#define SRV_CHARBAT_UTILITY_API

/*****************************************************************************
 * FUNCTION
 *  srv_charbat_send_ack
 * DESCRIPTION
 *  send ack to PS
 * PARAMETERS      
 *  Action       [IN]        battery_status_enum
 * RETURNS
 *  void
 *****************************************************************************/
void srv_charbat_send_ack(U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action == PMIC_CHARGER_IN ||
        action == PMIC_CHARGER_OUT || 
        action == PMIC_USB_CHARGER_IN  || 
        action == PMIC_USB_CHARGER_OUT ||
        action == PMIC_USB_NO_CHARGER_OUT ||
        action == PMIC_USB_NO_CHARGER_IN   )
    {
        mmi_eq_battery_status_res_req_struct *param_ack;
        param_ack = OslConstructDataPtr(sizeof(mmi_eq_battery_status_res_req_struct));

        param_ack->status_type = action;

        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_GPIO_PMIC_SEND_ACK_TO_PS, param_ack->status_type);
        mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_BATTERY_STATUS_RES_REQ, 
                        (oslParaType*) param_ack, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_emit_event
 * DESCRIPTION
 *  emit charger battery event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_charbat_emit_event(U16 event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    mmi_ret ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, event_id);
    ret = mmi_frm_cb_emit_event(&evt);

    if (ret == MMI_RET_OK || ret == MMI_RET_ERR_NO_REG_CB)
        return MMI_TRUE;

    return MMI_FALSE;
}


