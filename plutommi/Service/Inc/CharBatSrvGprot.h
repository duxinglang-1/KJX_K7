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
 *  CharBatGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for charger battery service
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CHARGER_BATTERY_GPROT_H
#define _CHARGER_BATTERY_GPROT_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "Device.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
/* DOM-NOT_FOR_SDK-BEGIN */
#define LBAT_IDLE_DURCNT_NORMAL       30       /* 30 * 1min = 30min */
#define LBAT_IDLE_DURCNT_PROHIBIT     3        /* 3 * 1min = 5min */
#define LBAT_TALK_DURCNT_NORMAL       6        /* 6 * 10 sec  = 1min  */
#define LBAT_TALK_DURCNT_PROHIBIT     1        /* 1 * 10 sec  = 10sec  */
#define LBAT_CALLDROP_CNT             3        /* when counter is 3, will end call */
/* DOM-NOT_FOR_SDK-END */

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* ReDefine pmic_status_enum to SRV CharBat status enum */
typedef  pmic_status_enum  srv_charbat_status_enum;

#define   SRV_CHARBAT_STATUS_BAT_LEVEL_IND        PMIC_VBAT_STATUS    /* Notify the battery voltage, BMT_VBAT_STATUS */
#define   SRV_CHARBAT_STATUS_CHARGER_IN        PMIC_CHARGER_IN     /* Charger plug in, BMT_CHARGER_IN */
#define   SRV_CHARBAT_STATUS_CHARGER_OUT        PMIC_CHARGER_OUT    /* Charger plug out, BMT_CHARGER_OUT */
#define   SRV_CHARBAT_STATUS_OVERVOLPROTECT        PMIC_OVERVOLPROTECT    /* The voltage of battery is too high. BMT_OVERVOLPROTECT */
#define   SRV_CHARBAT_STATUS_OVERBATTEMP        PMIC_OVERBATTEMP    /* The temperature of battery is too high. BMT_OVERBATTEMP */
#define   SRV_CHARBAT_STATUS_LOWBATTEMP        PMIC_LOWBATTEMP     /* The temperature of battery is too low. BMT_LOWBATTEMP */
#define   SRV_CHARBAT_STATUS_OVERCHARGECURRENT        PMIC_OVERCHARGECURRENT /* Charge current is too large. BMT_OVERCHARGECURRENT */
#define   SRV_CHARBAT_STATUS_CHARGE_COMPLETE        PMIC_CHARGE_COMPLETE   /* Charge is completed. BMT_CHARGE_COMPLETE */
#define   SRV_CHARBAT_STATUS_INVALID_BATTERY        PMIC_INVALID_BATTERY    /* invalid battery  BMT_INVALID_BAT*/
#define   SRV_CHARBAT_STATUS_INVALID_CHARGER        PMIC_INVALID_CHARGER   /* invalid charger BMT_INVALID_CHARGER*/
#define   SRV_CHARBAT_STATUS_CHARGING_TIMEOUT        PMIC_CHARGING_TIMEOUT /* Bad battery BMT_CHARGE_TIMEOUT */ 
#define   SRV_CHARBAT_STATUS_LOWCHARGECURRENT        PMIC_LOWCHARGECURRENT /* Charge current is too Low. BMT_LOWCHARGECURRENT */
#define   SRV_CHARBAT_STATUS_CHARGE_BAD_CONTACT        PMIC_CHARGE_BAD_CONTACT /* Charger Bad Contact */
#define   SRV_CHARBAT_STATUS_BATTERY_BAD_CONTACT        PMIC_BATTERY_BAD_CONTACT /* Battery Bad Contact */
#define   SRV_CHARBAT_STATUS_USB_CHARGER_IN        PMIC_USB_CHARGER_IN   /* Usb Charger plug in */
#define   SRV_CHARBAT_STATUS_USB_CHARGER_OUT        PMIC_USB_CHARGER_OUT   /* Usb Charger plug out */
#define   SRV_CHARBAT_STATUS_USB_NO_CHARGER_IN        PMIC_USB_NO_CHARGER_IN
#define   SRV_CHARBAT_STATUS_USB_NO_CHARGER_OUT        PMIC_USB_NO_CHARGER_OUT
#define   SRV_CHARBAT_STATUS_BATTERY_IN        PMIC_BATTERY_IN
#define   SRV_CHARBAT_STATUS_BATTERY_OUT        PMIC_BATTERY_OUT
#define   SRV_CHARBAT_STATUS_END_OF_ENUM


/* ReDefine battery_level_enum to SRV CharBat battery level enum */
typedef battery_level_enum srv_charbat_battery_level_enum; 

#define   SRV_CHARBAT_BATTERY_LOW_POWEROFF        BATTERY_LOW_POWEROFF
#define   SRV_CHARBAT_BATTERY_LOW_TX_PROHIBIT        BATTERY_LOW_TX_PROHIBIT
#define   SRV_CHARBAT_BATTERY_LOW_WARNING        BATTERY_LOW_WARNING
#define   SRV_CHARBAT_BATTERY_LEVEL_0        BATTERY_LEVEL_0
#define   SRV_CHARBAT_BATTERY_LEVEL_1        BATTERY_LEVEL_1
#define   SRV_CHARBAT_BATTERY_LEVEL_2        BATTERY_LEVEL_2
#define   SRV_CHARBAT_BATTERY_LEVEL_3        BATTERY_LEVEL_3 
#define   SRV_CHARBAT_BATTERY_LEVEL_4        BATTERY_LEVEL_4
#define   SRV_CHARBAT_BATTERY_LEVEL_5        BATTERY_LEVEL_5
#define   SRV_CHARBAT_BATTERY_LEVEL_6        BATTERY_LEVEL_6
#define   SRV_CHARBAT_BATTERY_LEVEL_END_OF_ENUM        BATTERY_LEVEL_LAST



/* charger battery service event enum */
typedef enum
{
    EVT_ID_SRV_CHARBAT_BEGIN = SRV_CHARBAT_BASE, /* need config res_range */
    EVT_ID_SRV_CHARBAT_NOTIFY,   /* Battery level change; Charger in/out/complete; Abnormal... */
    EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER, /* remind MMI to show low battery level */
    EVT_ID_SRV_CHARBAT_MAX_ITEM  /* Max item, not more than 5 now, or need to enlarge the range */
} evt_id_srv_charbat_enum;


/*
 * Structure for event of notifying charger battery status happen changed.
 * or when battery charger happen abnormal, such as over temperature...
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER             /* Event parameter header */
    srv_charbat_status_enum status;
    srv_charbat_battery_level_enum battery_level;
} srv_charbat_evt_notify_struct;


/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

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
extern MMI_BOOL srv_charbat_check_if_mo_allow(void);


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
extern srv_charbat_battery_level_enum srv_charbat_get_battery_level(void);


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_is_charging
 * DESCRIPTION
 *  This function get current charger status: if chargering or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, is chargering
 *****************************************************************************/
extern MMI_BOOL srv_charbat_is_charging(void);


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_is_low_battery
 * DESCRIPTION
 *  This function get current battery level: if low or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, battery level is low
 *****************************************************************************/
extern MMI_BOOL srv_charbat_is_low_battery(void);


/* DOM-NOT_FOR_SDK-BEGIN */

#define srv_charbat_get_bat_level() srv_charbat_get_battery_level()

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
extern MMI_BOOL srv_charbat_is_charger_connect(void);


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_charger_status
 * DESCRIPTION
 *  This function set current charger status: chargering or charger completed...
 *  Only used by Engineer mode / Factory mode
 * PARAMETERS
 *  status_id  [IN]  srv_charbat_status_enum
 * RETURNS
 *  MMI_BOOL : MMI_TRUE, set success
 *****************************************************************************/
extern MMI_BOOL srv_charbat_set_charger_status(srv_charbat_status_enum status_id);


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_set_low_bat_threshold
 * DESCRIPTION
 *  This function sets the thresh hold for low battery handler
 *  Used by SAT
 * PARAMETERS
 *  cnt     [IN]        The thresh value count
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_charbat_set_low_bat_threshold(U32 threshold);


/*****************************************************************************
 * FUNCTION
 *  srv_charbat_send_ack
 * DESCRIPTION
 *  send ack to PS, after receive MSG_ID_MMI_EQ_BATTERY_STATUS_IND
 * PARAMETERS      
 *  Action       [IN]        battery_status_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_charbat_send_ack(U32 action);

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
 *  srv_charbat_status_ind_hdlr
 * DESCRIPTION
 *  Respond for battery status indication primitive MSG_ID_MMI_EQ_BATTERY_STATUS_IND, 
 *  handle battery level or charger status notify, such as in/out/abnormal
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_charbat_status_ind_hdlr(void *info);


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
extern void srv_charbat_init_event_hdlr(void);

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
extern void srv_charbat_reset_pwron(void);

/* DOM-NOT_FOR_SDK-END */


#endif /* _CHARGER_BATTERY_GPROT_H */ 

