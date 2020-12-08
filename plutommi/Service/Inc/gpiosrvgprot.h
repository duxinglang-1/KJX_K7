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
/*******************************************************************************
 * Filename:
 * ---------
 *  GpioSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Header file for GPIO Utility Functions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef GPIO_SRV_GPROT_H
#define GPIO_SRV_GPROT_H

#include "kal_non_specific_general_types.h"
#include "device.h"
#include "custom_uem.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "custom_led_patterns.h"
#include "ProfilesSrvGprot.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/* DOM-NOT_FOR_SDK-END */



/****************************************************************************
* Setting
*****************************************************************************/

/****************************************************************************
* Typedef                                                            
*****************************************************************************/


/* GPIO Event Type */
typedef enum
{

    EVT_ID_MMI_GPIO_BEGIN = SRV_GPIO_BASE,   
    EVT_ID_GPIO_EARPHONE_PLUG_IN,           /* event for earphone plug in */
    EVT_ID_GPIO_EARPHONE_PLUG_OUT,          /* event for earphone plug out */
    EVT_ID_GPIO_EARPHONE_QUERY_CTRL,        /* event for query whether earphone controlled by other app, such as CTM */
    EVT_ID_GPIO_EXT_DEV_KEY_1,              /* event for send key of earphone */
    EVT_ID_GPIO_CLAM_OPEN,                  /* event for clam open */
    EVT_ID_GPIO_CLAM_CLOSE,                 /* event for clam close */
    EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE, /* event for query whether tone can be play when clam open or close */     
    
    EVT_ID_GPIO_LCD_SLEEP_OUT,              /* event for LCD will leave sleep in mode */
    EVT_ID_GPIO_BACKLIGHT_ON,               /* notify special app (screenlock) to do thing */
    EVT_ID_GPIO_BACKLIGHT_DIMMING,          /* event for LCD backlight come to dimming status */
    EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN,        /* event for query all APP whether GPIO can turn off backlight */
    EVT_ID_GPIO_BACKLIGHT_OFF,              /* all APP agree to turn off backlight, then notify special app to do thing */
    EVT_ID_GPIO_LCD_SLEEP_IN,               /* event for LCD will come into sleep in mode, */
    EVT_ID_GPIO_AFTER_LCD_SLEEP_IN,         /* event for LCD already come into sleep in mode, whether can suspend system align timer */
    
    EVT_ID_GPIO_BACKLIGHT_LEVEL_UPDATE,     /* event for backlight level have been set or changed */
    
    EVT_ID_GPIO_ENABLE_HAND_FREE,           /* event for enable hand free */
    EVT_ID_GPIO_DISABLE_HAND_FREE,          /* event for disable hand free */

    EVT_ID_GPIO_MUTE_PHONE,                 /* event for mute phone */
    EVT_ID_GPIO_UNMUTE_PHONE,               /* event for unmute phone */

    EVT_ID_GPIO_PENDING_TRUN_ON_BLT,        /* only use by myself, post to turn on backlihgt if some AP turn on in sleeping */

#ifdef __OP01_FWPBW__
    EVT_ID_GPIO_TRANSMITTER_HOLD_ON,        /* hold on transmitter of fixed phone in hand */
    EVT_ID_GPIO_TRANSMITTER_PUT_DOWN,       /* put down transmitter of fixed phone in phone */
#endif

#if defined(__KJX_RFID__)
    EVT_ID_GPIO_RFID_OPEN,                
    EVT_ID_GPIO_RFID_CLOSE,               
#endif

#if defined(__BLE_MODULE_SUPPORT__)
    EVT_ID_GPIO_BLE_MOD_SPI_OPEN,                
    EVT_ID_GPIO_BLE_MOD_SPI_CLOSE,    
#endif
    
    EVT_ID_SRV_GPIO_END_OF_ENUM
} srv_gpio_event_enum;

/* 
 * Backlight timer mechanism state. APP can use srv_backlight_turn_on() to control 
 * backlight mechanism state. 
 */
typedef enum
{
    SRV_BACKLIGHT_PERMANENT = 0,    /* disable GPIO backlight mechanism, make LCD always bright */
    SRV_BACKLIGHT_SHORT_TIME,       /* keep the GPIO backlight mechanism, make LCD birght short time */
    SRV_BACKLIGHT_TYPE_END_OF_ENUM
} srv_backlight_timer_type_enum;


/* 
 * Backlight timer state. Contains: no timer, timer for half mode, 
 * timer for sleep mdoe, and timer in sleep mode. 
 */
typedef enum
{
    SRV_BACKLIGHT_TIMER_STATE_NO_TIMER,          /* no timer to change lcd backlight state, backlight keep bright */
    SRV_BACKLIGHT_TIMER_STATE_FOR_HALF_MODE,     /* timer state for lcd backlight from bright to half bright */
    SRV_BACKLIGHT_TIMER_STATE_FOR_SLEEP_MODE,    /* timer state for lcd backlight from half bright to dark */
    SRV_BACKLIGHT_TIMER_STATE_IN_SLEEP_MODE,     /* lcd in sleep in mode */
    SRV_BACKLIGHT_TIMER_STATE_END_OF_ENUM
} srv_backlight_timer_state_enum;


/* 
 * Indicates the backlight timer setting is triggered by which module. 
 * By default means this setting is triggered via menu (setting).
 */
typedef enum
{
    SRV_BACKLIGHT_SET_TIMER_DEFAULT,          /* set backlight timer by GPIO setting */
    SRV_BACKLIGHT_SET_TIMER_BY_APP,           /* set backlight timer by app */
    SRV_BACKLIGHT_RESTORE_TIMER_BY_APP,       /* restore backlight timer to default by app */
    SRV_BACKLIGHT_SET_TIMER_PERMANENT,        /* set backlight always on by app */
    SRV_BACKLIGHT_RESTORE_TIMER_PERMANENT,    /* restore backlight permanent timer to short timer */
    SRV_BACKLIGHT_SET_TIMER_TYPE_END_OF_ENUM
} srv_backlight_set_timer_type_enum;


/* 
 * Indicates LCD type. 
 */
typedef enum
{
    SRV_BACKLIGHT_TYPE_MAINLCD,           /* main lcd backlight */
    SRV_BACKLIGHT_TYPE_SUBLCD,            /* sub lcd backlight */
    SRV_BACKLIGHT_TYPE_KEYPAD,            /* keypad backlight */ 
    SRV_BACKLIGHT_DEVICE_TYPE_END_OF_ENUM
} srv_backlight_device_type_enum;

/* set backlight turn on time, it is permanent on */
#define    SRV_GPIO_BACKLIGHT_PERMANENT_ON_TIME      0x7FFFFFFF

#define SRV_GPIO_BACKLIGHT_MAX_LEVEL     (custom_uem_get_bl_level_num()) /* brightness max level user can set */
#define SRV_GPIO_BACKLIGHT_MIN_LEVEL     (custom_uem_get_bl_level_num() > LED_LIGHT_LEVEL5 ? LED_LIGHT_LEVEL2 : LED_LIGHT_LEVEL1)        /* brightness min level user can set */

/* ReDefine Device type, such as LCD/LED light/Vibrator/FlashLight */
typedef gpio_device_enum srv_gpio_dev_enum;

#define    SRV_GPIO_DEV_MAINLCD        GPIO_DEV_LED_MAINLCD      /* Main LCD backlight */
#define    SRV_GPIO_DEV_SUBLCD         GPIO_DEV_LED_SUBLCD       /* Sub LCD backlight */
#define    SRV_GPIO_DEV_LED_R          GPIO_DEV_LED_STATUS_1     /* Status LED  R*/
#define    SRV_GPIO_DEV_LED_G          GPIO_DEV_LED_STATUS_2     /* Status LED  G*/
#define    SRV_GPIO_DEV_LED_B          GPIO_DEV_LED_STATUS_3     /* Status LED   B*/
#define    SRV_GPIO_DEV_LED_KEY        GPIO_DEV_LED_KEY          /* Keypad backlight */
#define    SRV_GPIO_DEV_VIBRATOR       GPIO_DEV_VIBRATOR         /* Vibrator */
#define    SRV_GPIO_DEV_FLASHLIGHT     GPIO_DEV_FLASHLIGHT       /* FlashLight */
#define    SRV_GPIO_DEV_RESERVED1      GPIO_DEV_FTE_FEEDBACK_VIB      /* touch feedback vibrate */
#define    SRV_GPIO_DEV_RESERVED2      GPIO_DEV_LED_BACKLIGHT_DIMMING /* backlight trun dimming */
#define    SRV_GPIO_DEV_RESERVED3      GPIO_DEV_RESERVED3        /* Reserve_3 */
#define    SRV_GPIO_DEV_RESERVED4      GPIO_DEV_RESERVED4        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED5      GPIO_DEV_RESERVED5        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED6      GPIO_DEV_RESERVED6        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED7      GPIO_DEV_RESERVED7        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED8      GPIO_DEV_RESERVED8        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED9      GPIO_DEV_RESERVED9        /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED10     GPIO_DEV_RESERVED10       /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED11     GPIO_DEV_RESERVED11       /* Reserve_4 */
#define    SRV_GPIO_DEV_RESERVED12     GPIO_DEV_RESERVED12       /* Reserve_4 */
#define    SRV_GPIO_DEV_TOTAL          MAX_GPIO_DEVICE_NUM           



/* ReDefine Device level, such as LCD/LED light/Vibrator/FlashLight level */
typedef gpio_device_led_level_typedef srv_gpio_dev_level_enum;

#define    SRV_GPIO_DEV_LEVEL0          LED_LIGHT_LEVEL0     /* turn off */
#define    SRV_GPIO_DEV_LEVEL1          LED_LIGHT_LEVEL1   
#define    SRV_GPIO_DEV_LEVEL2          LED_LIGHT_LEVEL2   
#define    SRV_GPIO_DEV_LEVEL3          LED_LIGHT_LEVEL3   
#define    SRV_GPIO_DEV_LEVEL4          LED_LIGHT_LEVEL4   
#define    SRV_GPIO_DEV_LEVEL5          LED_LIGHT_LEVEL5   
#define    SRV_GPIO_DEV_LEVEL_MAX       LED_LIGHT_LEVEL_MAX     




/* ReDefine volume_type_enum to GPIO volume type */
typedef volume_type_enum srv_gpio_vol_type_enum;

#define    SRV_GPIO_VOL_TYPE_CTN          VOL_TYPE_CTN      /* call tone attribute */
#define    SRV_GPIO_VOL_TYPE_KEY          VOL_TYPE_KEY      /* keypad tone attribute */
#define    SRV_GPIO_VOL_TYPE_MIC          VOL_TYPE_MIC      /* microphone attribute */
#define    SRV_GPIO_VOL_TYPE_GMI          VOL_TYPE_GMI      /* melody  imelody  midi attribute */
#define    SRV_GPIO_VOL_TYPE_SPH          VOL_TYPE_SPH      /* speech sound attribute */
#define    SRV_GPIO_VOL_TYPE_SID          VOL_TYPE_SID      /* side tone attribute */
#define    SRV_GPIO_VOL_TYPE_MEDIA        VOL_TYPE_MEDIA    /* as MP3, Wave,... attribute */
#define    SRV_GPIO_VOL_TYPE_TOTAL        MAX_VOL_TYPE           



/* ReDefine audio_type_enum to GPIO audio device type */
typedef audio_type_enum srv_gpio_audio_device_enum;

#define    SRV_GPIO_AUDDEV_SPEAKER          AUDIO_DEVICE_SPEAKER        /* Tone  Keypad sound to play on audio device. */
#define    SRV_GPIO_AUDDEV_MISROPHONE       AUDIO_DEVICE_MICROPHONE     /* Microphone sound to send on audio device. */
#define    SRV_GPIO_AUDDEV_BUZZER           AUDIO_DEVICE_BUZZER         /* Ring tone sound to play on audio device. */
#define    SRV_GPIO_AUDDEV_GMI              AUDIO_DEVICE_GMI            /* MIDI/Melody sound to play on audio device */
#define    SRV_GPIO_AUDDEV_SPEAKER2         AUDIO_DEVICE_SPEAKER2       /* earphone, carkit */
#define    SRV_GPIO_AUDDEV_LOUDSPEAKER      AUDIO_DEVICE_LOUDSPEAKER    /* loudspeaker for free sound */
#define    SRV_GPIO_AUDDEV_SPEAKER_BOTH     AUDIO_DEVICE_SPEAKER_BOTH 
#define    SRV_GPIO_AUDDEV_TOTAL            MAX_AUDIO_DEVICE_NUM      



/* Redefine PATTERN_ID to GPIO Pattern ID */
typedef PATTERN_ID srv_gpio_pattern_id_enum;

/* LED status pattern */
#define    SRV_GPIO_PATN_LED_BEGIN         LED_PATTERN_BEGIN 
#define    SRV_GPIO_PATN_LED_PWRON         LED_POWER_ON 
#define    SRV_GPIO_PATN_LED_PWROFF         LED_POWER_OFF 
#define    SRV_GPIO_PATN_LED_BATTERY_WARNING         LED_BATTERY_WARNING 
#define    SRV_GPIO_PATN_LED_BATTERY_LOW         LED_BATTERY_LOW 
#define    SRV_GPIO_PATN_LED_CONN900         LED_Connect900 
#define    SRV_GPIO_PATN_LED_CONN1800         LED_Connect1800 
#define    SRV_GPIO_PATN_LED_ONCHARGING         LED_OnCharging 
#define    SRV_GPIO_PATN_LED_FULLCHARGING         LED_FullCharging 
#define    SRV_GPIO_PATN_LED_MSG_IN         LED_MessageIn 
#define    SRV_GPIO_PATN_LED_MSG_REMIND         LED_MessageRemind 
#define    SRV_GPIO_PATN_LED_CALLER1         LED_Caller1 
#define    SRV_GPIO_PATN_LED_CALLER2         LED_Caller2 
#define    SRV_GPIO_PATN_LED_CALLER3         LED_Caller3 
#define    SRV_GPIO_PATN_LED_CALLER4         LED_Caller4 
#define    SRV_GPIO_PATN_LED_CALLER5         LED_Caller5 
#define    SRV_GPIO_PATN_LED_CALLER6         LED_Caller6 
#define    SRV_GPIO_PATN_LED_LIMITSERVICE         LED_LimitService 
#define    SRV_GPIO_PATN_LED_NOSERVICE         LED_NoService 
#define    SRV_GPIO_PATN_LED_CONN1900         LED_Connect1900 
#define    SRV_GPIO_PATN_LED_ROAMING         LED_Roaming 
#define    SRV_GPIO_PATN_LED_END         LED_PATTERN_END 

/* LCD backlight pattern */
#define    SRV_GPIO_PATN_LCD_BEGIN     LCD_PATTERN_BEGIN 
#define    SRV_GPIO_PATN_LCD_1         LCD_PATTERN_1 
#define    SRV_GPIO_PATN_LCD_2         LCD_PATTERN_2 
#define    SRV_GPIO_PATN_LCD_END       LCD_PATTERN_END 

/* Vibrator pattern */
#define    SRV_GPIO_PATN_VIB_BEGIN     VIB_PATTERN_BEGIN 
#define    SRV_GPIO_PATN_VIB_1         VIB_PATTERN_1 
#define    SRV_GPIO_PATN_VIB_2         VIB_PATTERN_2 
#define    SRV_GPIO_PATN_VIB_3         VIB_PATTERN_3   /* Incomming SMS */
#define    SRV_GPIO_PATN_VIB_END       VIB_PATTERN_END 

#define    SRV_GPIO_PATN_TOTAL         MAX_PATTERN_ID



/* Redefine PATTERN_TYPE to GPIO Pattern type */
typedef PATTERN_TYPE srv_gpio_pattern_type_enum;

#define    SRV_GPIO_PATN_PLAY_STOP    PLAY_STOP 
#define    SRV_GPIO_PATN_PLAY_START   PLAY_REPEAT 
#define    SRV_GPIO_PATN_PLAY_ONCE    PLAY_ONCE 
#define    SRV_GPIO_PATN_PLAY_TYPE_TOTAL   MAX_PATTERN_TYPE



/****************************************************************************
* Global Function
*****************************************************************************/
  
/*****************************************************************************
 * FUNCTION
 *  srv_speech_enable_hand_free
 * DESCRIPTION
 *  To enable handsfree mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_enable_hand_free(void);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_disable_hand_free
 * DESCRIPTION
 *  To disable handsfree mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_disable_hand_free(void);

 
/*****************************************************************************
 * FUNCTION
 *  srv_earphone_is_plug_in
 * DESCRIPTION
 *  To query if earphone is plug-in
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if plug_in, FALSE if plug_out
 *****************************************************************************/ 
extern MMI_BOOL srv_earphone_is_plug_in(void);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_device_mute
 * DESCRIPTION
 *  To set Device to mute on/off, Device type: AUDDEV_SPEAKER...(AUDDEV_XXX).
 *  Caller can set MicroPhone/Speaker/Speaker2 to mute on or off
 * PARAMETERS
 *  device   : [IN] srv_gpio_audio_device_enum, refer audio_type_enum defined in Device.h
 *  mute_on  : [IN] MMI_TRUE: mute on; MMI_FALSE: mute off
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_gpio_set_device_mute(srv_gpio_audio_device_enum device, MMI_BOOL mute_on);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_play_pattern
 * DESCRIPTION
 *  To start or stop LED/LCD/vibrator Pattern, e.g. Battery status pattern,
 *  Network Info status pattern, ...
 * PARAMETERS
 *  pattern  :   [IN] srv_gpio_pattern_id_enum, refer PATTERN_ID defined in Device.h
 *  action   :   [IN] srv_gpio_pattern_type_enum, refer PATTERN_TYPE
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_gpio_play_pattern(srv_gpio_pattern_id_enum pattern, srv_gpio_pattern_type_enum action);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_play_vibrate
 * DESCRIPTION
 *  To post vibrate primitive to play once/repeat/stop
 * PARAMETERS
 *  id   : [IN]  srv_gpio_pattern_id_enum (PATTERN_ID), from VIB_PATTERN_BEGIN to VIB_PATTERN_END
 *  type : [IN]  srv_gpio_pattern_type_enum (PATTERN_TYPE)
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_play_vibrate(srv_gpio_pattern_id_enum id, srv_gpio_pattern_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_off_keypad_light
 * DESCRIPTION
 *  Turn off keypad backlight 
 * PARAMETERS: 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_backlight_turn_off_keypad_light(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_half_mode
 * DESCRIPTION
 *  Take backlight from full drak mode to half bright mode, when current is full drak mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_backlight_half_mode(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_on
 * DESCRIPTION
 *  To turn on the LCD backlight and set backlight timer mechanism
 * PARAMETERS
 *  time_enum : [IN] disable backlight timer mechanism or not
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_backlight_turn_on(srv_backlight_timer_type_enum time_enum);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_off
 * DESCRIPTION
 *  Resume LCD backlight timer mechanism from Permanent to Short time.
 *  This API is matched with srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT).
 *  Note: this API don't swtich backlight to full drak immediately, it need through half bright mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_backlight_turn_off(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_close
 * DESCRIPTION
 *  In clam phone, this API will turn off LCD backlight in 15 seconds,
 *  else in bar phone, this API will turn off LCD backlight immediately
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_backlight_close(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_is_lcd_sleep
 * DESCRIPTION
 *  Query if LCD is in sleep mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/ 
extern MMI_BOOL srv_backlight_is_lcd_sleep(void);


/*****************************************************************************
 * FUNCTION
 *  srv_clam_is_close
 * DESCRIPTION
 *  Query if Clam is close; it will always return MMI_FALSE if in bar phone
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL : TRUE if yes, FALSE if no
 *****************************************************************************/ 
extern MMI_BOOL srv_clam_is_close(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_get_timer_state
 * DESCRIPTION
 *  Query the current timer state of backlight
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_backlight_timer_state_enum
 *****************************************************************************/ 
extern srv_backlight_timer_state_enum srv_backlight_get_timer_state(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_get_level
 * DESCRIPTION
 *  Query the current backlight level of MainLCD, SubLCD, Keypad
 * PARAMETERS
 *  lcd_type : [IN] refer to srv_backlight_device_type_enum
 * RETURNS
 *  U8 : refer to srv_gpio_dev_level_enum
 *****************************************************************************/ 
extern U8 srv_backlight_get_level(srv_backlight_device_type_enum lcd_type);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_get_hf_time
 * DESCRIPTION
 *  Query current backlight duration from bright to half bright
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/ 
extern S32 srv_backlight_get_hf_time(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_is_on
 * DESCRIPTION
 *  To get current LCD backlight status, backlight on or off
 * PARAMETERS
 *  lcd_type : [IN] refer to srv_backlight_device_type_enum
 * RETURNS
 *  MMI_BOOL: TRUE if backlight is on, FALSE if backlight is off
 *****************************************************************************/
extern MMI_BOOL srv_backlight_is_on(srv_backlight_device_type_enum lcd_type);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_is_phone_mute
 * DESCRIPTION
 *  Query current is mute or not
 * PARAMETERS
 *  void   
 * RETURNS
 *  returns MMI_TRUE if muted, else MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_speech_is_phone_mute(void);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_mute_phone
 * DESCRIPTION
 *  To make phone mute, and emit event to notify Applicate current in mute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_mute_phone(void);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_unmute_phone
 * DESCRIPTION
 *  To make phone unmute, and emit event to notify Applicate current in unmute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_unmute_phone(void);

#define SRV_GPIO_SDK_EXPORT_END
/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_device_level
 * DESCRIPTION
 *  to send MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_REQ to L4C to set GPIO device level.
 * PARAMETERS
 *  device : [IN] gpio_device_enum, such as: LED, LCD, Vibrator, etc.
 *  level  : [IN] gpio_device_led_level_typedef, Level 0 - 5, such as the level of device light.
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_set_device_level(srv_gpio_dev_enum device, srv_gpio_dev_level_enum level);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_turn_off_ext
 * DESCRIPTION
 *  Immediate turn off Backlight to full dark, no matter when full bright or half bright currently,
 *  not going through Half Mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_backlight_turn_off_ext(void);


extern void srv_backlight_set_timer_int(srv_backlight_set_timer_type_enum type, U32 hf_time, U8 dim_time);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_timer
 * DESCRIPTION
 *
 *  SET_TIMER_DEFAULT is only used by GPIO setting.
 *
 *  If App wants set backlight permanent bright timer, should use SET_TIMER_PERMANENT,
 *  and pass 0 to the 2nd and 3rd parameter
 *  If App wants customize backlight timer, should use SET_TIMER_BY_APP, App can only
 *  set hf_time, or only set dim_time, or both; pass 0 to the 2nd or 3rd paramenter means
 *  don't customize this filed.
 *
 *  Must notes: 
 *  After SET_TIMER_PERMANENT, caller should remerber to call this API to RESTORE_TIMER_PERMANENT 
 *  After SET_TIMER_BY_APP, caller should remerber to call this API to RESTORE_TIMER_BY_APP
 *
 * PARAMETERS
 *  type          [IN]        
 *  hf_time       [IN]
 *  dim_time      [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
#define srv_backlight_set_timer(_type, _hf_time, _dim_time)  \
    do                                                       \
    {                                                        \
        kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_8,     \
            "srv_backlight_set_timer: file:%s, line:%d", __FILE__, __LINE__);  \
        srv_backlight_set_timer_int((srv_backlight_set_timer_type_enum)(_type), (U32)(_hf_time), (U8)(_dim_time));                             \
    } while(0)


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_hf_time
 * DESCRIPTION
 *  Set backlight half mode timer
 * PARAMETERS
 *  type  : [IN] refer to MMI_GPIO_BACKLIGHT_TIMER_PROFILE
 *  time  : [IN] time which wants to set
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_backlight_set_hf_time(srv_backlight_set_timer_type_enum type, S32 time);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_get_lcd_state
 * DESCRIPTION
 *  Gets current LCD's backlight status, full light or half light or full dark
 * PARAMETERS:
 *  lcd_type
 * Return Value
 *  if query MAIN_LCD state: 0 = dark, 1 = half light, 2 = full light
 *  if query SUB_LCD state: 0 = dark, 1 = half light, 2 = full light
 *  if query KEYPAD state: 0 = dark. 1 = light
 *****************************************************************************/
extern S32 srv_backlight_get_lcd_state(srv_backlight_device_type_enum lcd_type);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_setting_set_hf_time
 * DESCRIPTION
 *  set backlight time, which include half brightness time and dimming time,
 *  that to say, it is form turn on backlight to full drak (not dimming).
 * PARAMETERS
 *  bl_sec   :  [IN]  want to set backlight time in sec (from full bright to full dark)
 * RETURNS
 *  MMI_BOOL: will return MMI_TRUE when set success, else return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_gpio_setting_set_bl_time(S32 bl_sec);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_set_mode_volume
 * DESCRIPTION
 *  to initialize the speech volume for each profile mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_set_mode_volume(void);

 
/*****************************************************************************
 * FUNCTION
 *  srv_speech_save_mode_volume
 * DESCRIPTION
 *  to save the speech volume for current audio mode
 * PARAMETERS
 *  level : [IN] speech volume 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_speech_save_mode_volume(U8 level);


/*****************************************************************************
 * FUNCTION
 *  srv_speech_get_mode_volume
 * DESCRIPTION
 *  to get the speech volume for current audio mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 srv_speech_get_mode_volume(void);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_volume
 * DESCRIPTION
 *  To set Volume device with Volume level, e.g. VOL_TYPE_KEY... (VOL_TYPE_XXX)
 *  can set rigner/keypad/speech/... volume
 * PARAMETERS
 *  type   : [IN] srv_gpio_vol_type_enum, refer volume_type_enum defined in Device.h
 *  volume : [IN] volume level, no more than MAX_VOL_LEVEL
 * RETURNS
 *  void
 *****************************************************************************/
 #if 0
/* under construction !*/
#endif

/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  SRV_GPIO_PWRON_READY_NOTIFIER
 * DESCRIPTION
 *  when gpio detect done, will call this callback to bootup
 * PARAMETERS
 *  para :        [IN]  Reserved para (mostly be NULL)
 *  user_data :   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
typedef void(*SRV_GPIO_PWRON_READY_NOTIFIER) (void *para, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_check_pwron_ready
 * DESCRIPTION
 *  check if device aux detect is done. if detect is done (means gpio is ready), 
 *  will return MMI_TRUE and don't callback notifier;
 *  else, detect unfinish (means gpio is not ready), 
 *  will return MMI_FALSE and store this cbk, then callback notifier until detect done
 * PARAMETERS
 *  notifier :      [IN] callback function
 *  user_data :     [IN]
 * RETURNS
 *  MMI_TRUE: GPIO is ready
 *****************************************************************************/ 
extern MMI_BOOL srv_gpio_check_pwron_ready(SRV_GPIO_PWRON_READY_NOTIFIER notifier,
                                            void *user_data);



typedef enum
{
    SRV_GPIO_PROPERTY_KEYPAD_LOCKED_FLAG, // Need fill keypad_locked
    SRV_GPIO_PROPERTY_SET_CURR_MODE,      // Need fill curr_mode
    SRV_GPIO_PROPERTY_INFO_END_OF_ENUM
} srv_gpio_property_info_enum;


typedef struct
{
    MMI_BOOL keypad_locked;      // MMI_TRUE: locked, MMI_FALSE: not locked
    U8       curr_mode;          // 0: NORMAL_MODE, 1: ENGINEERING_MODE, 2: FACTORY_MODE
} srv_gpio_property_info_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_property_info
 * DESCRIPTION
 *  set gpio service property data, caller only need fill the field info in info_struct, 
 *  relation with info_type para
 * PARAMETERS
 *  info_type :      [IN] refer srv_gpio_property_info_enum
 *  info_struct :    [IN] refer srv_gpio_property_info_struct
 * RETURNS
 *  MMI_BOOL : set success, return MMI_TRUE;
 *****************************************************************************/ 
extern MMI_BOOL srv_gpio_set_property_info(srv_gpio_property_info_enum info_type,
                                       srv_gpio_property_info_struct *info_struct);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_set_event_hdlr
 * DESCRIPTION
 *  set gpio event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_set_event_hdlr(void);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_shutdown_hdlr
 * DESCRIPTION
 *  to enable necessary indication when shutdown
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern mmi_ret srv_gpio_shutdown_hdlr(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_detect_ind_hdlr
 * DESCRIPTION
 *  Event handler of gpio detect indication 
 * PARAMETERS:     
 *  info        [IN]        gpio detect indication information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_gpio_detect_ind_hdlr(void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_detect_send_ack
 * DESCRIPTION
 *  send ack to PS
 * PARAMETERS
 *  gpio_device       [IN]        device type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_gpio_detect_send_ack(U8 gpio_device);


/*****************************************************************************
 * FUNCTION
 *  srv_pattern_play_req
 * DESCRIPTION
 *  will be phased out, please use new SDK API: srv_gpio_play_pattern
 *  Plays a pattern on vibrator or LED 
 * PARAMETERS:
 *  pattern     [IN]        pattern type to be played
 *  action      [IN]        ON/OFF
 * Returns
 * void
 *****************************************************************************/
extern void srv_pattern_play_req(U8 pattern, U8 action);


/*****************************************************************************
 * FUNCTION
 *  srv_pattern_send_req_to_hw
 * DESCRIPTION
 *  Send pattern request to H/W 
 * PARAMETERS:
 *  pattern     [IN]        pattern to be played
 *  action      [IN]        ON/OFF
 * Returns
 *  void
 *****************************************************************************/
extern void srv_pattern_send_req_to_hw(U8 pattern, U8 action);


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_set_flag
 * DESCRIPTION
 *  set led pattern flag
 * PARAMETERS
 *  flag     [IN]        led pattern flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_led_pattern_set_flag(MMI_BOOL flag);


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_start_caller_group
 * DESCRIPTION
 *  Plays pattern as caller group functionality
 * PARAMETERS
 *  pattern: [IN] pattern id which defined in custom file (custom_mmi_default_value.h)
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_led_pattern_start_caller_group(U16 pattern);


/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_start_caller_group
 * DESCRIPTION
 *  Stops pattern as caller group functionality
 * PARAMETERS
 *  pattern: [IN] pattern id which defined in custom file (custom_mmi_default_value.h)
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_led_pattern_stop_caller_group(U16 pattern);

/*****************************************************************************
 * FUNCTION
 *  srv_led_pattern_get_bg_pattern
 * DESCRIPTION
 *  get background led pattern
 *  
 *  PARAMETERS:
 *
 *  RETURNS 
 *  background pattern
 *****************************************************************************/
extern U8 srv_led_pattern_get_bg_pattern(void);


/*****************************************************************************
 * FUNCTION
 *  srv_earphone_status_changed
 * DESCRIPTION
 *  to query if earphone status changed
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: MMI_TRUE if earphone status changed, otherwise return MMI_FALSE. 
 *****************************************************************************/ 
extern MMI_BOOL srv_earphone_status_changed(void);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_play_req
 * DESCRIPTION
 *  Other module control gpio device 
 *  PARAMETERS:
 *  p_type      [IN]        the device type to be played
 *  p_level     [IN]        the level to be played
 * RETURNS
 *  if play successfully, return 1, otherwise return 0
 *****************************************************************************/
extern kal_uint8 srv_gpio_play_req(kal_uint8 p_type, kal_uint8 p_level);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_init_context_early
 * DESCRIPTION
 *  set the bl hf time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_backlight_init_context_early(void);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_real_level
 * DESCRIPTION
 *  sets current backlight level 
 *  PARAMETERS: 
 *  lcd_type    [IN]        lcd type
 *  level       [IN]        backlight level
 * RETURNS
 *  void
   *****************************************************************************/
extern void srv_backlight_set_real_level(srv_backlight_device_type_enum lcd_type, U8 level);



/*****************************************************************************
 * FUNCTION
 *  srv_clam_set_state
 * DESCRIPTION
 *  Set clam state
 * PARAMETERS
 *  clam_state      [IN]        Clam state
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_clam_set_state(U16 clam_state);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_detect_send_ack
 * DESCRIPTION
 *  send an ack of MSG_ID_MMI_EQ_GPIO_DETECT_IND
 * PARAMETERS
 *  gpio_device : [IN] device type of received MSG_ID_MMI_EQ_GPIO_DETECT_IND 
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_detect_send_ack(U8 gpio_device);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_set_mode_exe
 * DESCRIPTION
 *  Sets BackLight Mode
 *  
 *  PARAMETERS: void
 *  mode        [IN]        
 *****************************************************************************/
extern void srv_backlight_set_mode_exe(U8 mode);


/*****************************************************************************
 * FUNCTION
 *  srv_backlight_is_ctrl
 * DESCRIPTION
 *  check backlight if controled by IMY or other AP
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: yes, backlihgt is controled by IMY or other AP
 *****************************************************************************/
 #if 0
/* under construction !*/
 #endif


/*****************************************************************************
 * FUNCTION
 *  srv_speech_is_hand_free
 * DESCRIPTION
 *  Query if phone is in Hands Free Mode
 * PARAMETERS:
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_speech_is_hand_free(void);


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  srv_gpio_transmitter_is_hold_on
 * DESCRIPTION
 *  Check current fixed phone transmitter's states, if it is hold on
 * PARAMETERS:
 *  void
 * RETURNS:
 *  MMI_BOOL, return MMI_TRUE if transmitter is hold on,
 *            return MMI_FALSE if transmitter is put down
 *****************************************************************************/
extern MMI_BOOL srv_gpio_transmitter_is_hold_on(void);
#endif /* __OP01_FWPBW__ */

/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_post_req
 * DESCRIPTION
 *  to post vibrator on/off event
 * PARAMETERS
 *  on : [IN]  on or off
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_vibrator_post_req(PATTERN_ID id, PATTERN_TYPE type);


/*****************************************************************************
 * FUNCTION
 *  srv_vibrator_play_req
 * DESCRIPTION
 *  Directly handle vibrate to play or stop, not send primitive to myself
 * PARAMETERS
 *  id   : [IN]  PATTERN_ID
 *  type : [IN]  PATTERN_TYPE
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_vibrator_play_req(PATTERN_ID id, PATTERN_TYPE type);


/****************************************************************************
* Define
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* Will be phased out, Please use new SDK API : srv_gpio_set_volume */
#define srv_gpio_set_ringer_volume(volume) mdi_audio_set_volume(VOL_TYPE_MEDIA,(U8)(volume))
/* Will be phased out, Please use new SDK API : srv_gpio_set_volume */
#define srv_gpio_set_keypad_volume(volume) mdi_audio_set_volume(VOL_TYPE_KEY,(U8)(volume))
/* Will be phased out, Please use new SDK API : srv_gpio_set_volume */
#define srv_speech_set_volume(volume) mdi_audio_set_volume(VOL_TYPE_SPH,(U8)(volume))




/* Will be phased out, Please use new SDK API : srv_gpio_set_device_mute */
#define srv_speech_mute_on_microphone() srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_mute */
#define srv_speech_mute_off_microphone() srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_mute */
#define srv_speech_mute_on_speaker() srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_SPEAKER, MMI_TRUE)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_mute */
#define srv_speech_mute_off_speaker() srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_SPEAKER, MMI_FALSE)


/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_all_lcd_on() srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);\
                                   srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_all_lcd_off() srv_gpio_set_device_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL0);\
                                    srv_gpio_set_device_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL0);
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_keypad_on() srv_gpio_set_device_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_keypad_off() srv_gpio_set_device_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_off()  srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);\
                                    srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);\
                                    srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_red_on()      srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_green_on()    srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_blue_on()     srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_red_off()     srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_green_off()   srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0)
/* Will be phased out, Please use new SDK API : srv_gpio_set_device_level */
#define srv_backlight_status_blue_off()    srv_gpio_set_device_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0)


/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */
#define srv_led_pattern_start_power_on()          srv_gpio_play_pattern(LED_POWER_ON, PLAY_REPEAT)
#define srv_led_pattern_stop_power_on()           srv_gpio_play_pattern(LED_POWER_ON, PLAY_STOP)
#define srv_led_pattern_start_power_off()         srv_gpio_play_pattern(LED_POWER_OFF, PLAY_REPEAT)
#define srv_led_pattern_stop_power_off()          srv_gpio_play_pattern(LED_POWER_OFF, PLAY_STOP)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */

/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */
#define srv_led_pattern_start_connect900()          srv_gpio_play_pattern(LED_Connect900, PLAY_REPEAT)
#define srv_led_pattern_stop_connect900()           srv_gpio_play_pattern(LED_Connect900, PLAY_STOP)
#define srv_led_pattern_start_connect1800()         srv_gpio_play_pattern(LED_Connect1800, PLAY_REPEAT)
#define srv_led_pattern_stop_connect1800()          srv_gpio_play_pattern(LED_Connect1800, PLAY_STOP)
#define srv_led_pattern_start_connect1900()         srv_gpio_play_pattern(LED_Connect1900, PLAY_REPEAT)
#define srv_led_pattern_stop_connect1900()          srv_gpio_play_pattern(LED_Connect1900, PLAY_STOP)
#define srv_led_pattern_start_roaming()             srv_gpio_play_pattern(LED_Roaming, PLAY_REPEAT)
#define srv_led_pattern_stop_roaming()              srv_gpio_play_pattern(LED_Roaming, PLAY_STOP)
#define srv_led_pattern_start_limit_service()       srv_gpio_play_pattern(LED_LimitService, PLAY_REPEAT)
#define srv_led_pattern_stop_limit_service()        srv_gpio_play_pattern(LED_LimitService, PLAY_STOP)
#define srv_led_pattern_start_no_service()          srv_gpio_play_pattern(LED_NoService, PLAY_REPEAT)
#define srv_led_pattern_stop_no_service()           srv_gpio_play_pattern(LED_NoService, PLAY_STOP)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */

/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */
#define srv_led_pattern_start_battery_warning()      srv_gpio_play_pattern(LED_BATTERY_WARNING, PLAY_REPEAT)
#define srv_led_pattern_stop_battery_warning()       srv_gpio_play_pattern(LED_BATTERY_WARNING, PLAY_STOP)
#define srv_led_pattern_start_battery_low()          srv_gpio_play_pattern(LED_BATTERY_LOW, PLAY_REPEAT)
#define srv_led_pattern_stop_battery_low()           srv_gpio_play_pattern(LED_BATTERY_LOW, PLAY_STOP)
#define srv_led_pattern_start_charging()             srv_gpio_play_pattern(LED_OnCharging, PLAY_REPEAT)
#define srv_led_pattern_stop_charging()              srv_gpio_play_pattern(LED_OnCharging, PLAY_STOP)
#define srv_led_pattern_start_full_charging()        srv_gpio_play_pattern(LED_FullCharging, PLAY_REPEAT)
#define srv_led_pattern_stop_full_charging()         srv_gpio_play_pattern(LED_FullCharging, PLAY_STOP)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */

/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */
#define srv_led_pattern_start_message_in()           srv_gpio_play_pattern(LED_MessageIn, PLAY_REPEAT)
#define srv_led_pattern_stop_message_in()            srv_gpio_play_pattern(LED_MessageIn, PLAY_STOP)
#define srv_led_pattern_start_message_remind()       srv_gpio_play_pattern(LED_MessageRemind, PLAY_REPEAT)
#define srv_led_pattern_stop_message_remind()        srv_gpio_play_pattern(LED_MessageRemind, PLAY_STOP)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */

/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */
#define srv_led_pattern_start_caller1()          srv_gpio_play_pattern(LED_Caller1, PLAY_REPEAT)
#define srv_led_pattern_stop_caller1()           srv_gpio_play_pattern(LED_Caller1, PLAY_STOP)
#define srv_led_pattern_start_caller2()          srv_gpio_play_pattern(LED_Caller2, PLAY_REPEAT)
#define srv_led_pattern_stop_caller2()           srv_gpio_play_pattern(LED_Caller2, PLAY_STOP)
#define srv_led_pattern_start_caller3()          srv_gpio_play_pattern(LED_Caller3, PLAY_REPEAT)
#define srv_led_pattern_stop_caller3()           srv_gpio_play_pattern(LED_Caller3, PLAY_STOP)
#define srv_led_pattern_start_caller4()          srv_gpio_play_pattern(LED_Caller4, PLAY_REPEAT)
#define srv_led_pattern_stop_caller4()           srv_gpio_play_pattern(LED_Caller4, PLAY_STOP)
#define srv_led_pattern_start_caller5()          srv_gpio_play_pattern(LED_Caller5, PLAY_REPEAT)
#define srv_led_pattern_stop_caller5()           srv_gpio_play_pattern(LED_Caller5, PLAY_STOP)
#define srv_led_pattern_start_caller6()          srv_gpio_play_pattern(LED_Caller6, PLAY_REPEAT)
#define srv_led_pattern_stop_caller6()           srv_gpio_play_pattern(LED_Caller6, PLAY_STOP)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */

#define srv_led_pattern_start_background()            srv_gpio_play_pattern(srv_led_pattern_get_bg_pattern(), PLAY_REPEAT)
#define srv_led_pattern_stop_background()             srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), 0)


/* Begin, Will be phased out, Please use new SDK API : srv_gpio_play_vibrate */
#define srv_vibrator_on() srv_gpio_play_vibrate(VIB_PATTERN_1, PLAY_REPEAT)
#define srv_vibrator_off()  srv_gpio_play_vibrate(VIB_PATTERN_1, PLAY_STOP)
#define srv_vibrator_play_once() srv_gpio_play_vibrate(VIB_PATTERN_1, PLAY_ONCE)
#define srv_vibrator_play_sms_once() srv_gpio_play_vibrate(VIB_PATTERN_3, PLAY_ONCE)
/* End, Will be phased out, Please use new SDK API : srv_gpio_play_pattern */


typedef struct
{
    U32 duration;  /* in milliseconds, duration of vibration */
    srv_gpio_dev_level_enum level;  /* vibration level */
} srv_gpio_vibrate_req_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_gpio_start_vibrate
 * DESCRIPTION
 *  Vibrate extend Interface, Caller can play vibartor for specified duration 
 *  at specified level
 * PARAMETERS
 *  req   [IN]  srv_gpio_vibrate_req_struct
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_start_vibrate(srv_gpio_vibrate_req_struct *req);


/*****************************************************************************
 * FUNCTION
 *  srv_gpio_stop_vibrate
 * DESCRIPTION
 *  Vibrate extend Interface, will turn off vibrator 
 * PARAMETERS
 *  req   [IN]  srv_gpio_vibrate_req_struct
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_gpio_stop_vibrate(void);


/* begin: only used by GPIO APP, other APP don't use */
typedef struct
{
    S32 bl_setting_level;
    S32 bl_setting_hftime;
    U8 led_setting;
    U8 bl_setting;
    U8 cover_close_back_to_idle;
    U8 cover_close_reject_call;
    U8 cover_close_keypad_lock;
    S32 MainCntrst;
#ifdef __MMI_SUBLCD__
    S32 SubCntrst;
#endif
#ifdef __MMI_CABC__
    U8 cabc; /* 1:on, 0:off*/
#endif
}mmi_phnset_gpio_cntx_struct;

extern mmi_phnset_gpio_cntx_struct *g_phnset_gpio_cntx_p;
extern void srv_gpio_setting_init(void);
extern void srv_gpio_setting_set_bl_level(S32 level, MMI_BOOL save_flag);
extern void srv_gpio_setting_set_hf_time(S32 hf_sec, MMI_BOOL save_flag);
extern void srv_gpio_setting_bl_restore(void);

extern MMI_BOOL srv_gpio_setting_contrast_restore(void);
extern void srv_gpio_setting_set_mianlcd_contrast(U8 level);
extern void srv_gpio_setting_set_sublcd_contrast(U8 level);
#ifdef __MMI_CABC__
extern void srv_gpio_setting_set_cabc(U8 flag);
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern S32 srv_gpio_setting_get_hf_time(void);
#endif

extern MMI_BOOL srv_gpio_allow_clam_tone(void);
/* end: only used by GPIO APP, other APP don't use */

#endif /* MMI_GENERALDEVICE_GPROT_H */ 
/* DOM-NOT_FOR_SDK-END */
