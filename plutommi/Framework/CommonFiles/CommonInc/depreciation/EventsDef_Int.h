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
 * EventsDef_Int.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for event handler, screen history and interrupt event queue.
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

#ifndef _EVENTSDEF_INT_H
#define _EVENTSDEF_INT_H


/***************************************************************************** 
* Define
*****************************************************************************/
#if defined (__MMI_DUAL_SIM__) || defined (__MMI_DUAL_SIM_SINGLE_CALL__)
    #define MAX_SLAVE_PROTOCOL_EVENT	450         /* max number of events (protocol, timer & hardware) */
#endif /* __MMI_DUAL_SIM__ */

#ifdef OBIGO_Q05A
    #define MAX_PROTOCOL_EVENT 850  /* max number of events (protocol, timer & hardware) */
#else 
    #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__)
        #define MAX_PROTOCOL_EVENT 800  /* max number of events (protocol, timer & hardware) */
    #else /* #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__) */ 
        #if (!defined(LOW_COST_SUPPORT)) || defined(__MMI_GPRS_FEATURES__)
            #define MAX_PROTOCOL_EVENT	450         /* max number of events (protocol, timer & hardware) */
        #else
            #define MAX_PROTOCOL_EVENT	250         /* max number of events (protocol, timer & hardware) */
        #endif
    #endif /* #if defined(__MMI_BT_SUPPORT__) || defined(__MMI_IMPS__) */ 
#endif /* #ifdef OBIGO_Q05A */

#if !defined(LOW_COST_SUPPORT)
    #define MAX_INTERRUPT_EVENT	30       /* max number of interrupt events (protocol, timer & hardware) */
#else
    #define MAX_INTERRUPT_EVENT	20       /* max number of interrupt events (protocol, timer & hardware) */
#endif

#if !defined(LOW_COST_SUPPORT)
    #define MAX_HISTORY		50
#else
    #define MAX_HISTORY		30
#endif

    #define  MIN_HISTORY    0

#ifdef WIN32
    #define MMI_FRM_INTERRUPT_EVENT(flag)   flag##UI64
#else
    #define MMI_FRM_INTERRUPT_EVENT(flag)   flag##ULL
#endif /* WIN32 */

/*
 * Procedure to update interrupt event
 * 1. Define new interrupt event macro by MMI_FRM_INTERRUPT_EVENT
 * 2. Update interrupt event group if it belongs to some group
 * 3. Update boundary of MMI_FRM_COMMON_INT_END by lastest interrupt event
 * 4. Update interrupt events category
 */

/* Idiograhpic interrupt event */
#define MMI_FRM_INT_CLAM_OPEN                       MMI_FRM_INTERRUPT_EVENT(0x0000000000000001)
#define MMI_FRM_INT_CLAM_CLOSE                      MMI_FRM_INTERRUPT_EVENT(0x0000000000000002)
#define MMI_FRM_INT_AUDIO_PLAY_FINISH               MMI_FRM_INTERRUPT_EVENT(0x0000000000000004)
/* Battery interruption events */
#define MMI_FRM_INT_CHARGER_IN                      MMI_FRM_INTERRUPT_EVENT(0x0000000000000008)
#define MMI_FRM_INT_CHARGER_OUT                     MMI_FRM_INTERRUPT_EVENT(0x0000000000000010)
#define MMI_FRM_INT_CHARGE_COMPLETE                 MMI_FRM_INTERRUPT_EVENT(0x0000000000000020)
#define MMI_FRM_INT_USB_CHARGER_IN                  MMI_FRM_INTERRUPT_EVENT(0x0000000000000040)
#define MMI_FRM_INT_USB_CHARGER_OUT                 MMI_FRM_INTERRUPT_EVENT(0x0000000000000080)
#define MMI_FRM_INT_USB_NO_CHARGER_IN               MMI_FRM_INTERRUPT_EVENT(0x0000000000000100)
#define MMI_FRM_INT_USB_NO_CHARGER_OUT              MMI_FRM_INTERRUPT_EVENT(0x0000000000000200)
/* Gpio interruption events */
#define MMI_FRM_INT_EARPHONE_PLUG_IN                MMI_FRM_INTERRUPT_EVENT(0x0000000000000400)
#define MMI_FRM_INT_EARPHONE_PLUG_OUT               MMI_FRM_INTERRUPT_EVENT(0x0000000000000800)
/* SMS interruption events */
#define MMI_FRM_INT_SMS_DELIVER                     MMI_FRM_INTERRUPT_EVENT(0x0000000000001000)
#define MMI_FRM_INT_SMS_STATUS_REPORT               MMI_FRM_INTERRUPT_EVENT(0x0000000000002000)
#define MMI_FRM_INT_SMS_MSG_WAITING                 MMI_FRM_INTERRUPT_EVENT(0x0000000000004000)
#define MMI_FRM_INT_SMS_APP_DATA                    MMI_FRM_INTERRUPT_EVENT(0x0000000000008000)
/* File manager card interruption events */
#define MMI_FRM_INT_FMGR_CARD_PLUG_IN               MMI_FRM_INTERRUPT_EVENT(0x0000000000010000)
#define MMI_FRM_INT_FMGR_CARD_PLUG_OUT              MMI_FRM_INTERRUPT_EVENT(0x0000000000020000)
/* Low battery indication */
#define MMI_FRM_INT_BATTERY_LOW_WARNING             MMI_FRM_INTERRUPT_EVENT(0x0000000000040000)
#define MMI_FRM_INT_BATTERY_LOW_TX_PROHIBIT         MMI_FRM_INTERRUPT_EVENT(0x0000000000080000)
/* WAP */
#define MMI_FRM_INT_WAP_PMG_NEW_MSG                 MMI_FRM_INTERRUPT_EVENT(0x0000000000100000)
#define MMI_FRM_INT_WAP_PMG_DLG_PUSH_STORAGE_FULL   MMI_FRM_INTERRUPT_EVENT(0x0000000000200000)
#define MMI_FRM_INT_WAP_PMG_REPLACE                 MMI_FRM_INTERRUPT_EVENT(0x0000000000400000)
#define MMI_FRM_INT_WAP_PMG_DLG_SIA_CONFIRM         MMI_FRM_INTERRUPT_EVENT(0x0000000000800000)
#define MMI_FRM_INT_WAP_PMG_DLG_UNKNOWN_ADDR_REQ    MMI_FRM_INTERRUPT_EVENT(0x0000000001000000)
#define MMI_FRM_INT_CCA_SOURCE_UI_INVALID_SETTING   MMI_FRM_INTERRUPT_EVENT(0x0000000002000000)
#define MMI_FRM_INT_CCA_SOURCE_UI_NEW_SETTING       MMI_FRM_INTERRUPT_EVENT(0x0000000004000000)

/* BT interruption event */
#define MMI_FRM_INT_BT_LEVEL_1                      MMI_FRM_INTERRUPT_EVENT(0x0000000008000000)    /* general popup, ex: dis/connected, file received ...  */
#define MMI_FRM_INT_BT_LEVEL_2                      MMI_FRM_INTERRUPT_EVENT(0x0000000010000000)    /* error notification popup, ex: disk full ...*/
#define MMI_FRM_INT_BT_LEVEL_3                      MMI_FRM_INTERRUPT_EVENT(0x0000000020000000)    /* confirmation screen popup, ex: OPPS, FTPS, HID connect accept confirmation screen ... */

/* MMS interruption event */
#define MMI_FRM_INT_MMS                             MMI_FRM_INTERRUPT_EVENT(0x0000000040000000)     /* Non mmi task */
/* JPUSH */
#define MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH         MMI_FRM_INTERRUPT_EVENT(0x0000000080000000)
#define MMI_FRM_INT_CERTMAN_MMI                     MMI_FRM_INTERRUPT_EVENT(0x0000000100000000)
/* USB detect indication */
#define MMI_FRM_INT_USBDETECT                       MMI_FRM_INTERRUPT_EVENT(0x0000000200000000)
/* Incoming call */
#define MMI_FRM_INT_VOIP_CALL_RING                  MMI_FRM_INTERRUPT_EVENT(0x0000000400000000)
#define MMI_FRM_INT_MMI_CC_CALL_RING_IND            MMI_FRM_INTERRUPT_EVENT(0x0000000800000000)
/* JAVA push install */
#define MMI_FRM_INT_MMI_JAVA_PUSH_INSTALL           MMI_FRM_INTERRUPT_EVENT(0x0000001000000000)

#define MMI_FRM_INT_SYNCML_FINISH_SYNC_IND          MMI_FRM_INTERRUPT_EVENT(0x0000002000000000)

#define MMI_FRM_INT_WAP_MMA_GET_MSG                 MMI_FRM_INTERRUPT_EVENT(0x0000004000000000)
#define MMI_FRM_INT_SYNCML_DEVICE_CONN_IND          MMI_FRM_INTERRUPT_EVENT(0x0000008000000000)
/* DM MMI */
#define MMI_FRM_INT_DM                              MMI_FRM_INTERRUPT_EVENT(0x0000010000000000)

/* Interrupt event group */
#define MMI_FRM_INT_CLAM             (MMI_FRM_INT_CLAM_OPEN | MMI_FRM_INT_CLAM_CLOSE)                                        /* 0x00000003 */
#define MMI_FRM_INT_AUDIO_PLAY       (MMI_FRM_INT_AUDIO_PLAY_FINISH)
#define MMI_FRM_INT_CHARGER          (MMI_FRM_INT_CHARGER_IN | MMI_FRM_INT_CHARGER_OUT | MMI_FRM_INT_CHARGE_COMPLETE)        /* 0x00000018 */
#define MMI_FRM_INT_USB_CHARGER      (MMI_FRM_INT_USB_CHARGER_IN | MMI_FRM_INT_USB_CHARGER_OUT)                              /* 0x000000c0 */
#define MMI_FRM_INT_USB_NO_CHARGER   (MMI_FRM_INT_USB_NO_CHARGER_IN | MMI_FRM_INT_USB_NO_CHARGER_OUT)                        /* 0x00000300 */
#define MMI_FRM_INT_EARPHONE         (MMI_FRM_INT_EARPHONE_PLUG_IN | MMI_FRM_INT_EARPHONE_PLUG_OUT)                          /* 0x00000c00 */
#define MMI_FRM_INT_SMS              (MMI_FRM_INT_SMS_DELIVER | MMI_FRM_INT_SMS_STATUS_REPORT | MMI_FRM_INT_SMS_MSG_WAITING | MMI_FRM_INT_SMS_APP_DATA)   /* 0x00007000 */
#define MMI_FRM_INT_FMGR_CARD        (MMI_FRM_INT_FMGR_CARD_PLUG_IN | MMI_FRM_INT_FMGR_CARD_PLUG_OUT)                        /* 0x00018000 */
#define MMI_FRM_INT_WAP_MMS          (MMI_FRM_INT_MMS | MMI_FRM_INT_WAP_MMA_GET_MSG)
#define MMI_FRM_INT_BT_TASK          (MMI_FRM_INT_BT_LEVEL_1 | MMI_FRM_INT_BT_LEVEL_2 | MMI_FRM_INT_BT_LEVEL_3)
#define MMI_FRM_INT_BATTERY_LOW      (MMI_FRM_INT_BATTERY_LOW_WARNING | MMI_FRM_INT_BATTERY_LOW_TX_PROHIBIT)
#define MMI_FRM_INT_WAP              (MMI_FRM_INT_WAP_PMG_NEW_MSG | MMI_FRM_INT_WAP_PMG_DLG_PUSH_STORAGE_FULL | MMI_FRM_INT_WAP_PMG_REPLACE | MMI_FRM_INT_WAP_PMG_DLG_SIA_CONFIRM | MMI_FRM_INT_WAP_PMG_DLG_UNKNOWN_ADDR_REQ | MMI_FRM_INT_CCA_SOURCE_UI_INVALID_SETTING | MMI_FRM_INT_CCA_SOURCE_UI_NEW_SETTING)
#define MMI_FRM_INT_INCOMING_CALL    (MMI_FRM_INT_VOIP_CALL_RING | MMI_FRM_INT_MMI_CC_CALL_RING_IND)
#define MMI_FRM_INT_SYNCML           (MMI_FRM_INT_SYNCML_FINISH_SYNC_IND | MMI_FRM_INT_SYNCML_DEVICE_CONN_IND)
/* Common interrupt events boundary */
#define MMI_FRM_COMMON_INT_BEGIN     (MMI_FRM_INT_CLAM_OPEN)
#define MMI_FRM_COMMON_INT_END       (MMI_FRM_INT_DM)

/* Interrupt events category */
#define MMI_FRM_INT_GPIO             (MMI_FRM_INT_CLAM | MMI_FRM_INT_EARPHONE)
#define MMI_FRM_INT_BATTERY          (MMI_FRM_INT_CHARGER | MMI_FRM_INT_USB_CHARGER | MMI_FRM_INT_USB_NO_CHARGER | MMI_FRM_INT_BATTERY_LOW)
/* Non mmi task interrupt events can't be blocked like common interrupt events for its occurrence is not accompany with the message */
#define MMI_FRM_INT_NON_MMI_TASK_EVENTS     (MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK)
/* All interrupt events including popup screen and other special operation, for instance operating clam */
#define MMI_FRM_INT_TOTAL_INTERRUPT_EVENT   (MMI_FRM_INT_GPIO | MMI_FRM_INT_AUDIO_PLAY_FINISH | MMI_FRM_INT_COMMON_INTERRUPT_EVENT)
/* All the interrupt events which could invoke popup screen */
#define MMI_FRM_INT_COMMON_INTERRUPT_EVENT   (MMI_FRM_INT_EARPHONE | MMI_FRM_INT_BATTERY | MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK | MMI_FRM_INT_FMGR_CARD | MMI_FRM_INT_SMS | MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH | MMI_FRM_INT_CERTMAN_MMI | MMI_FRM_INT_WAP \
                                              | MMI_FRM_INT_USBDETECT | MMI_FRM_INT_INCOMING_CALL | MMI_FRM_INT_MMI_JAVA_PUSH_INSTALL | MMI_FRM_INT_SYNCML | MMI_FRM_INT_DM)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef U64 mmi_frm_int_event_type;
typedef U8(*interrupt_event_hdlr)(mmi_frm_int_event_type);


/***************************************************************************** 
* Notification Service
*****************************************************************************/

/* HIGH priority first */
typedef enum {
    MMI_FRM_SCENARIO_CALL_INCOMMING,
    MMI_FRM_SCENARIO_CALL_OUTGOING,
    MMI_FRM_SCENARIO_CONCURRENT_INCALL_SNDREC,  /* concurrent */
    MMI_FRM_SCENARIO_CALL_INCALL,
    MMI_FRM_SCENARIO_SNDREC_REC,

    /* add scenario above */
    MMI_FRM_SCENARIO_GENERAL,  /* no real scenario, just used for general behavior table */
    MMI_FRM_SCENARIO_END,
    MMI_FRM_SCENARIO_INVALID = 255  /* set to 255 since we use U8 for mmi_concurrent_scenario */
} mmi_frm_scenario_enum;

#define MMI_FRM_SCENARIO_NUM                    (MMI_FRM_SCENARIO_GENERAL)
#define MMI_FRM_BEHAVIOR_TABLE_SCENARIO_NUM     (MMI_FRM_SCENARIO_END)

/* interrupt event type for Interrupt Central Control */
typedef enum {
    MMI_INT_INCOMING_CALL,
    MMI_INT_ALARM_EXPIRES,
    MMI_INT_CALENDAR_ALERTS,
    MMI_INT_NEW_MSG_ARRIVES,
    MMI_INT_VOBJECT_RECEIVED,
    MMI_INT_MEM_CARD_PLUG_IN,
    MMI_INT_MEM_CARD_PLUG_OUT,
    MMI_INT_USB_PLUG_IN,
    MMI_INT_USB_PLUG_OUT,
    MMI_INT_CHARGER_PLUG_IN,
    MMI_INT_CHARGER_PLUG_OUT,
    MMI_INT_CHARGING_COMPLETE,
    MMI_INT_LOW_BATTERY_WARNING,
    MMI_INT_EARPHONE_PLUT_IN,
    MMI_INT_EARPHONE_PLUT_OUT,
    MMI_INT_BT_REQUEST,
    MMI_INT_FILE_RECEIVED_VIA_BT,
    MMI_INT_SERVICE_MSG_ARRIVES,
    MMI_INT_NEW_PROVISIONING_ARRIVES,
    MMI_INT_JAVA_PUSH_ARRIVES,
    MMI_INT_END
} mmi_frm_int_enum;

/* defer callback type */
typedef void (*mmi_frm_defer_cb_type)(mmi_frm_scenario_enum scenario, mmi_frm_int_enum interrupt, void *arg);

/* behavior type */

typedef enum {
    MMI_FRM_BEHAVIOR_ALL_NONE       = 0x00,
    
    MMI_FRM_BEHAVIOR_IF_NONE        = 0x00,  /* event interface */
    MMI_FRM_BEHAVIOR_SND_NONE       = 0x00,  /* volume */
    MMI_FRM_BEHAVIOR_IND_NO_CHANGE  = 0x00,  /* indicator */
    MMI_FRM_BEHAVIOR_VIB_NONE       = 0x00,  /* vibrator */
    MMI_FRM_BEHAVIOR_BL_NO_CHANGE   = 0x00,  /* backlight */

    /* bit0 ~ bit1 : event interface */
    MMI_FRM_BEHAVIOR_IF_TOP         = 0x01,
    MMI_FRM_BEHAVIOR_IF_IDLE        = 0x02,
    MMI_FRM_BEHAVIOR_IF_DEFER       = 0x03,
    
    /* bit2 ~ bit3 : volume */
    MMI_FRM_BEHAVIOR_SND_PROFILE    = 0x04,
    MMI_FRM_BEHAVIOR_SND_SUBTLE     = 0x08,

    /* if 0x0C is used, MMI_FRM_BEHAVIOR_GENERAL should be modified, 
       and maybe extend mmi_frm_behavior_type as well */
    MMI_FRM_BEHAVIOR_GENERAL        = 0x0C,  /* refer to general behavior */
    
    /* bit4 : indicator */
    MMI_FRM_BEHAVIOR_IND_CHANGE     = 0x10,
    
    /* bit5 : vibrator */
    MMI_FRM_BEHAVIOR_VIB_PROFILE    = 0x20,
    
    /* bit6 ~ bit7 : backlight */
    MMI_FRM_BEHAVIOR_BL_SHORT_ON    = 0x40,
    MMI_FRM_BEHAVIOR_BL_ALWAYS_ON   = 0x80,
    MMI_FRM_BEHAVIOR_BL_TWINKLE     = 0xC0,
    
    MMI_FRM_BEHAVIOR_END
    /* if bits used is changed, shall mmi_frm_behavior_type as well */
} mmi_frm_behavior_enum;

typedef U8 mmi_frm_behavior_type;

#define MMI_FRM_BEHAVIOR_MASK_IF    (MMI_FRM_BEHAVIOR_IF_TOP|MMI_FRM_BEHAVIOR_IF_IDLE|MMI_FRM_BEHAVIOR_IF_DEFER)
#define MMI_FRM_BEHAVIOR_MASK_SND   (MMI_FRM_BEHAVIOR_SND_PROFILE|MMI_FRM_BEHAVIOR_SND_SUBTLE)
#define MMI_FRM_BEHAVIOR_MASK_IND   (MMI_FRM_BEHAVIOR_IND_CHANGE)
#define MMI_FRM_BEHAVIOR_MASK_VIB   (MMI_FRM_BEHAVIOR_VIB_PROFILE)
#define MMI_FRM_BEHAVIOR_MASK_BL    (MMI_FRM_BEHAVIOR_BL_SHORT_ON|MMI_FRM_BEHAVIOR_BL_ALWAYS_ON|MMI_FRM_BEHAVIOR_BL_TWINKLE)
#define MMI_FRM_BEHAVIOR_MASK_ALL   (MMI_FRM_BEHAVIOR_MASK_IF|MMI_FRM_BEHAVIOR_MASK_SND|MMI_FRM_BEHAVIOR_MASK_IND|MMI_FRM_BEHAVIOR_MASK_VIB|MMI_FRM_BEHAVIOR_MASK_BL)

typedef struct {
    mmi_frm_behavior_type ev_interface;
    mmi_frm_behavior_type sound;
    mmi_frm_behavior_type indicator;
    mmi_frm_behavior_type vibrator;
    mmi_frm_behavior_type backlight;
} mmi_frm_int_behavior_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

#endif /* _EVENTSDEF_INT_H */ 


