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
 * ProfilesSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   User profiles service global header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PROFILES_SRV_GPROT_H
#define PROFILES_SRV_GPROT_H

/* get app id */
#include "mmidatatype.h"
/* some definitinos shared with nvram config are put in custom common folder */
#include "custom_srv_prof_defs.h"
/* use mdi enum */
//#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "kal_general_types.h"

/*****************************************************************************
 * Enumeration and definitions
 *****************************************************************************/

/* Service result defines, negatives for failure cases */
#define SRV_PROF_RET_SUCCESS 0                  /* Success */
#define SRV_PROF_RET_PROFILE_ACTIVATED 1        /* Profile activated */
#define SRV_PROF_RET_DRM_NOT_FORWARDABLE 2      /* Drm not forwardable */
#define SRV_PROF_RET_TRY_TO_RECOVER 3           /* Play tone file fail and try to recover */
#define SRV_PROF_RET_PLAY_FINISHED 4            /* Play tone finished */
#define SRV_PROF_RET_EXT_MELODY_REPLACED 5      /* External melody replaced */
#define SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK 6 /* Play tone success without callback */
#define SRV_PROF_RET_NOT_PLAY 7                 /* Do not play tone due to some reason */
#define SRV_PROF_RET_YES 0                      /* Yes */
#define SRV_PROF_RET_NO -1                      /* No */
#define SRV_PROF_RET_FAIL -1                    /* Fail */
#define SRV_PROF_RET_PROFILE_NOT_ACTIVATED -2   /* Profile not activated */
#define SRV_PROF_RET_PROFILE_NOT_SUPPORTED -3   /* Profile not supported */
#define SRV_PROF_RET_SETTING_NOT_SUPPORTED -4   /* Setting not supported */
#define SRV_PROF_RET_MIDI_FILE_TOO_LARGE   -5   /* Midi file size too large */
#define SRV_PROF_RET_MIDI_CHECK_FILE_FAIL  -6   /* Midi check file size fail */
#define SRV_PROF_RET_PATH_TOO_LONG         -7   /* File path string too long */

/* Definde audio silent */
#define SRV_PROF_TONE_SILENT 0  /* Defines the tone silent for appliaction to use */

/* This enum defines the profile name for external applications to refer to */
typedef enum
{
    SRV_PROF_MEETING_MODE,          /* Meeting mode */
    SRV_PROF_SILENT_MODE,           /* Silnet mode */
    SRV_PROF_HEADSET_MODE,          /* Headset mode */
    SRV_PROF_BLUETOOTH_MODE,        /* Bluetooth profile */
    SRV_PROF_MODE_END_OF_ENUM       /* End of enum */
}srv_prof_external_profile_enum;


/* This enum defined BT HFP connect type */
typedef enum
{
    SRV_PROF_BT_HFP_ACL,            /* ACL link */
    SRV_PROF_BT_HFP_SCO,            /* SCO link */
    SRV_PROF_BT_HFP_END_OF_ENUM     /* End of enum */
}srv_prof_bt_connect_type_enum;


/* This enum defined BT HFP callback type */
typedef enum
{
    SRV_PROF_BT_IND,                /* Indication */
    SRV_PROF_BT_RSP,                /* Response */
    SRV_PROF_BT_REQ,                /* Request */
    SRV_PROF_BT_END_OF_ENUM         /* End of enum */
}srv_prof_bt_cb_type_enum;


/* This enum defined file deletion type */
typedef enum
{
    SRV_PROF_DEL_FILE,              /* Delete certain file */
    SRV_PROF_DEL_FOLDER,            /* Delete whole folder */
    SRV_PROF_DEL_END_OF_ENUM        /* End of enum */
}srv_prof_del_type_enum;


/* This enum deinfes the audio play type */
typedef enum
{
    SRV_PROF_AUDIO_NONE,             /* None */
    SRV_PROF_AUDIO_DTMF,             /* DTMF tone */
    SRV_PROF_AUDIO_STRING,           /* Profiles generated audio string */
    SRV_PROF_AUDIO_DATA,             /* External audio string */
    SRV_PROF_AUDIO_FILE,             /* File */
    SRV_PROF_AUDIO_TEXT,             /* Text */
    SRV_PROF_AUDIO_TYPE_END_OF_ENUM  /* End of enum*/
}srv_prof_audio_type_enum;

/* This enum deinfes the audio resource type */
typedef enum
{
    SRV_PROF_AUDIO_RES_NONE,            /* None */
    SRV_PROF_AUDIO_RES_TONE,            /* Tone */
    SRV_PROF_AUDIO_RES_RING,            /* Ring */
    SRV_PROF_AUDIO_RES_FILE,            /* File */
    SRV_PROF_AUDIO_RES_END_OF_ENUM      /* End of enum*/
}srv_prof_audio_resource_type_enum;

/* This enum deinfes the volume type */
typedef enum
{
    SRV_PROF_VOL_RING,           /* Ring */
    SRV_PROF_VOL_KEY,            /* Key */
    SRV_PROF_VOL_MESSAGE,        /* Message */
    SRV_PROF_VOL_MEDIA,          /* Media */
    SRV_PROF_VOL_END_OF_ENUM     /* End of enum*/
}srv_prof_vol_type_enum;


/* This enum defines all possible setting items */
typedef enum
{
    SRV_PROF_SETTINGS_RING_VOL_LEVEL,           /* Ring volume level : srv_prof_volume_level */
    SRV_PROF_SETTINGS_KEYPAD_VOL_LEVEL,         /* Keypad volume level : srv_prof_volume_level */
    SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL,        /* Message volume level : srv_prof_volume_level */
    SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL,          /* Message volume level : srv_prof_volume_level */
    SRV_PROF_SETTINGS_ALERT_TYPE,               /* Alert type : srv_prof_alert_type_enum */
    SRV_PROF_SETTINGS_NOTIFICATION_SOUND,       /* Notification sound : MMI_BOOL */
    SRV_PROF_SETTINGS_VIBRATE,                  /* If can vibrate : MMI_BOOL */
    SRV_PROF_SETTINGS_RING_TYPE,                /* Ring type : srv_prof_ring_type_enum */
    SRV_PROF_SETTINGS_INTELLIGENT_CALL_ALERT,   /* Intelligent call alert : MMI_BOOL */
    SRV_PROF_SETTINGS_SYSTEM_ALERT,             /* System alert tone : MMI_BOOL */
    SRV_PROF_SETTINGS_STATUS_LED,               /* Status LED pattern : srv_prof_led_pattern_enum */
    SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE,         /* keypad tone : srv_prof_keypad_tone_type_enum */
    SRV_PROF_SETTINGS_TOUCH_VOL,                /* Touch feedback volume level : srv_prof_volume_level */
    SRV_PROF_SETTINGS_TOUCH_VIB,                /* Touch feedback vibration level : srv_prof_vib_level */

    SRV_PROF_SETTINGS_POWER_ON_TONE,            /* Power on tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_POWER_OFF_TONE,           /* Power off tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_POWER_ON_OFF_TONE,        /* Power on / off tone switcher: MMI_BOOL */
    SRV_PROF_SETTINGS_COVER_OPEN_TONE,          /* Cover on tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_COVER_CLOSE_TONE,         /* Cover off tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_SMS_TONE,                 /* SMS tone, stands for all message tone when message 
                                                   tones are not split : srv_prof_audio_id */
    SRV_PROF_SETTINGS_SMS_CARD2_TONE,           /* SMS tone - card2 ,stands for all message tone when 
                                                   message tones are not split : srv_prof_audio_id */
    SRV_PROF_SETTINGS_SMS_CARD3_TONE,           /* SMS tone - card3 ,stands for all message tone when 
                                                   message tones are not split : srv_prof_audio_id */
    SRV_PROF_SETTINGS_SMS_CARD4_TONE,           /* SMS tone - card4 ,stands for all message tone when 
                                                   message tones are not split : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MMS_TONE,                 /* MMS tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MMS_CARD2_TONE,           /* MMS tone - card2 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MMS_CARD3_TONE,           /* MMS tone - card3 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MMS_CARD4_TONE,           /* MMS tone - card4 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_EMAIL_TONE,               /* Email tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_EMAIL_CARD2_TONE,         /* Email tone - card2 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_EMAIL_CARD3_TONE,         /* Email tone - card3 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_EMAIL_CARD4_TONE,         /* Email tone - card4 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VOICE_TONE,               /* Voice tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VOICE_CARD2_TONE,         /* Voice tone - card2 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VOICE_CARD3_TONE,         /* Voice tone - card3 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VOICE_CARD4_TONE,         /* Voice tone - card4 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MT_CALL_TONE,             /* Icoming call tone : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,       /* Icoming call tone - card2 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE,       /* Icoming call tone - card3 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE,       /* Icoming call tone - card4 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VT_CALL_TONE,             /* Icoming call tone - video call : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE,       /* Icoming call tone - video call - card2 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE,       /* Icoming call tone - video call - card3 : srv_prof_audio_id */
    SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE,       /* Icoming call tone - video call - card4 : srv_prof_audio_id */

    SRV_PROF_SETTINGS_END_OF_ENUM               /* End of enum */
}srv_prof_settings_enum;


/* This enum defines the tone types for other apps to refer to for play tone request*/
typedef enum
{
    SRV_PROF_TONE_NONE,                 /* None */
    SRV_PROF_TONE_ERROR,                /* Error tone */
    SRV_PROF_TONE_CONNECT,              /* Connect tone */
    SRV_PROF_TONE_CAMP_ON,              /* Camp on tone */
    SRV_PROF_TONE_WARNING,              /* Warning tone */
    SRV_PROF_TONE_INCOMING_CALL,        /* Incoming call tone */
    SRV_PROF_TONE_INCOMING_CALL_CARD2,  /* Incoming call tone - card2 */
    SRV_PROF_TONE_INCOMING_CALL_CARD3,  /* Incoming call tone - card3 */
    SRV_PROF_TONE_INCOMING_CALL_CARD4,  /* Incoming call tone - card4 */
    SRV_PROF_TONE_VIDEO_CALL,           /* Video call tone */
    SRV_PROF_TONE_VIDEO_CALL_CARD2,     /* Video call tone - card2 */

                                        /*11*/
    SRV_PROF_TONE_VIDEO_CALL_CARD3,     /* Video call tone - card3 */
    SRV_PROF_TONE_VIDEO_CALL_CARD4,     /* Video call tone - card4 */
    SRV_PROF_TONE_SMS,                  /* SMS tone */    
    SRV_PROF_TONE_SMS_CARD2,            /* SMS tone - card2 */
    SRV_PROF_TONE_SMS_CARD3,            /* SMS tone - card3 */
    SRV_PROF_TONE_SMS_CARD4,            /* SMS tone - card4 */
    SRV_PROF_TONE_MMS,                  /* MMS tone */
    SRV_PROF_TONE_MMS_CARD2,            /* MMS tone - card2 */
    SRV_PROF_TONE_MMS_CARD3,            /* MMS tone - card3 */
    SRV_PROF_TONE_MMS_CARD4,            /* MMS tone - card4 */

                                        /*21*/
    SRV_PROF_TONE_EMAIL,                /* Email tone */
    SRV_PROF_TONE_EMAIL_CARD2,          /* Email tone - card2 */
    SRV_PROF_TONE_EMAIL_CARD3,          /* Email tone - card3 */
    SRV_PROF_TONE_EMAIL_CARD4,          /* Email tone - card4 */
    SRV_PROF_TONE_VOICE,                /* Voice tone */
    SRV_PROF_TONE_VOICE_CARD2,          /* Voice tone - card2 */
    SRV_PROF_TONE_VOICE_CARD3,          /* Voice tone - card3 */
    SRV_PROF_TONE_VOICE_CARD4,          /* Voice tone - card4 */
    SRV_PROF_TONE_ALARM,                /* Alarm tone */
    SRV_PROF_TONE_POWER_ON,             /* Power on tone */

                                        /*31*/
    SRV_PROF_TONE_POWER_OFF,            /* Power off tone */
    SRV_PROF_TONE_COVER_OPEN,           /* Cover open tone */
    SRV_PROF_TONE_COVER_CLOSE,          /* Cover close tone */
    SRV_PROF_TONE_SUCCESS,              /* Success tone */
    SRV_PROF_TONE_SAVE,                 /* Save tone */
    SRV_PROF_TONE_EMPTY_LIST,           /* Empty tone */
    SRV_PROF_TONE_GENERAL_TONE,         /* General tone */
    SRV_PROF_TONE_AUX,                  /* AUX tone */
    SRV_PROF_TONE_BATTERY_LOW,          /* Battery low tone */
    SRV_PROF_TONE_BATTERY_WARNING,      /* Battery warning tone */

                                        /*41*/
    SRV_PROF_TONE_CALL_REMINDER,        /* Call reminder tone */
    SRV_PROF_TONE_CCBS,                 /* CCBS tone */
    SRV_PROF_TONE_CONGESTION,           /* Congestion tone */
    SRV_PROF_TONE_AUTH_FAIL,            /* Authentication fail tone */
    SRV_PROF_TONE_NUM_UNOBTAIN,         /* Number un-obtained tone */
    SRV_PROF_TONE_CALL_DROP,            /* Call drop tone */
    SRV_PROF_TONE_SMS_INCALL,           /* SMS in call tone */
    SRV_PROF_TONE_WARNING_INCALL,       /* Warning in call tone */
    SRV_PROF_TONE_ERROR_INCALL,         /* Error in call tone */
    SRV_PROF_TONE_CONNECT_INCALL,       /* Connect in call tone */

                                        /*51*/
    SRV_PROF_TONE_SUCCESS_INCALL,       /* Success in call tone */
    SRV_PROF_TONE_IMPS_CONTACT_ONLINE,          /* IMPS tone - contact online */
    SRV_PROF_TONE_IMPS_NEW_MESSAGE,             /* IMPS tone - new message */
    SRV_PROF_TONE_IMPS_CONTACT_INVITATION,      /* IMPS tone - contact invitation */
    SRV_PROF_TONE_IMPS_CHATROOM_NOTIFICATION,   /* IMPS tone - chat room notification */
    SRV_PROF_TONE_FILE_ARRIVAL,         /* File arrival tone */
    SRV_PROF_TONE_SENT,                 /* Sent tone */
    SRV_PROF_TONE_DELETED,              /* Deleted tone */
    SRV_PROF_TONE_PROBLEM,              /* Problem tone */
    SRV_PROF_TONE_CONFIRM,              /* Confirm tone */

                                        /*61*/
    SRV_PROF_TONE_EXPLICITLY_SAVE,      /* Explicitly save tone */
    SRV_PROF_TONE_NOT_AVAILABLE,        /* Not available tone */
    SRV_PROF_TONE_ANS_PHONE,            /* Answer phone tone */
    SRV_PROF_TONE_WAP_PUSH,             /* WAP push tone */
    SRV_PROF_TONE_REMIND,               /* Remind tone */
    SRV_PROF_TONE_KEYPAD,               /* Key pad tone */
    SRV_PROF_TONE_EM,                   /* Engineering mode tone */
    SRV_PROF_TONE_FM,                   /* Factory mode tone */
    SRV_PROF_TONE_PHONEBOOK,            /* Phonebook tone */
    SRV_PROF_TONE_POC,                  /* PoC tone */

                                        /*71*/
    SRV_PROF_TONE_VOIP,                 /* Voip tone */
    SRV_PROF_TONE_SAT,                  /* SAT tone */
    SRV_PROF_TONE_GSM_BUSY,             /* GSM busy */
    SRV_PROF_TONE_WAITING_CALL,         /* Waiting call */
    SRV_PROF_TONE_ALARM_IN_CALL,        /* Alarm in call */
    SRV_PROF_TONE_DIALER,               /* Dialer tone */

    NONE_TONE = SRV_PROF_TONE_NONE,
    ERROR_TONE = SRV_PROF_TONE_ERROR,
    CONNECT_TONE = SRV_PROF_TONE_CONNECT,
    CAMP_ON_TONE = SRV_PROF_TONE_CAMP_ON,
    WARNING_TONE = SRV_PROF_TONE_WARNING,
    INCOMING_CALL_TONE = SRV_PROF_TONE_INCOMING_CALL,
    ALARM_TONE = SRV_PROF_TONE_ALARM,
    POWER_ON_TONE = SRV_PROF_TONE_POWER_ON,
    POWER_OFF_TONE = SRV_PROF_TONE_POWER_OFF,
    COVER_OPEN_TONE = SRV_PROF_TONE_COVER_OPEN,
    COVER_CLOSE_TONE = SRV_PROF_TONE_COVER_CLOSE,
    MESSAGE_TONE = SRV_PROF_TONE_SMS,
    KEYPAD_PLAY_TONE = SRV_PROF_TONE_KEYPAD,
    SUCCESS_TONE = SRV_PROF_TONE_SUCCESS,
    SAVE_TONE = SRV_PROF_TONE_SAVE,
    EMPTY_LIST_TONE = SRV_PROF_TONE_EMPTY_LIST,
    GENERAL_TONE = SRV_PROF_TONE_GENERAL_TONE,
    SMS_IN_CALL_TONE = SRV_PROF_TONE_SMS_INCALL,
    AUX_TONE = SRV_PROF_TONE_AUX,
    WARNING_TONE_IN_CALL = SRV_PROF_TONE_WARNING_INCALL,
    ERROR_TONE_IN_CALL = SRV_PROF_TONE_ERROR_INCALL,
    CONNECT_TONE_IN_CALL = SRV_PROF_TONE_CONNECT_INCALL,
    SUCCESS_TONE_IN_CALL = SRV_PROF_TONE_SUCCESS_INCALL,
    BATTERY_LOW_TONE = SRV_PROF_TONE_BATTERY_LOW,
    BATTERY_WARNING_TONE = SRV_PROF_TONE_BATTERY_WARNING,
    CALL_REMINDER_TONE = SRV_PROF_TONE_CALL_REMINDER,
    CCBS_TONE = SRV_PROF_TONE_CCBS,
    CONGESTION_TONE = SRV_PROF_TONE_CONGESTION,
    AUTH_FAIL_TONE = SRV_PROF_TONE_AUTH_FAIL,
    NUM_UNOBTAIN_TONE = SRV_PROF_TONE_NUM_UNOBTAIN,
    CALL_DROP_TONE = SRV_PROF_TONE_CALL_DROP,
    IMPS_CONTACT_ONLINE_TONE = SRV_PROF_TONE_IMPS_CONTACT_ONLINE,
    IMPS_NEW_MESSAGE_TONE = SRV_PROF_TONE_IMPS_NEW_MESSAGE,
    IMPS_CONTACT_INVITATION_TONE = SRV_PROF_TONE_IMPS_CONTACT_INVITATION,
    IMPS_CHATROOM_NOTIFICATION_TONE = SRV_PROF_TONE_IMPS_CHATROOM_NOTIFICATION,
    CARD2_INCOMING_CALL_TONE = SRV_PROF_TONE_INCOMING_CALL_CARD2,
    CARD2_MESSAGE_TONE = SRV_PROF_TONE_SMS_CARD2,
    FILE_ARRIVAL_TONE = SRV_PROF_TONE_FILE_ARRIVAL,

    /*for op11*/
    SENT_TONE = SRV_PROF_TONE_SENT,
    DELETED_TONE = SRV_PROF_TONE_DELETED,
    PROBLEM_TONE = SRV_PROF_TONE_PROBLEM,
    NETWORK_PROBLEM_TONE = SRV_PROF_TONE_PROBLEM,
    CONFIRM_TONE = SRV_PROF_TONE_CONFIRM,
    EXPLICITLY_SAVE_TONE = SRV_PROF_TONE_EXPLICITLY_SAVE,
    NOT_AVAILABLE_TONE = SRV_PROF_TONE_NOT_AVAILABLE,        /*Oops tone*/
    ANS_PHONE_TONE = SRV_PROF_TONE_ANS_PHONE,
    SMS_TONE = SRV_PROF_TONE_SMS,
    MMS_TONE = SRV_PROF_TONE_MMS,
    EMAIL_TONE = SRV_PROF_TONE_EMAIL,
    VOICE_TONE = SRV_PROF_TONE_VOICE,
    WAP_PUSH_TONE = SRV_PROF_TONE_WAP_PUSH,
    REMIND_TONE = SRV_PROF_TONE_REMIND,

    SRV_PROF_TONE_END_OF_ENUM           /* End of enum */
}srv_prof_tone_enum;


typedef U8 srv_prof_volume_level;
typedef U8 srv_prof_vib_level;
typedef U16 srv_prof_audio_id;
typedef S32 srv_prof_ret;
typedef srv_prof_ret (*srv_prof_play_tone_callback)(srv_prof_ret result);

/* Play request structure */ 
typedef struct
{
    srv_prof_audio_id audio_id;             /* audio id to play */
    WCHAR* filepath;                        /* filepath to play */
    U8* text;                               /* text to play */
    S32 text_speed;                         /* text speed in Msec */
    U8* audio_data_ptr;                     /* customer string data */
    U8  audio_data_format;                  /* customer string format */
    U32 audio_data_len;                     /* customer string len */
    srv_prof_ring_type_enum play_style;     /* play style */
    srv_prof_volume_level volume;           /* volume */
    srv_prof_tone_enum tone_type;           /* tone type */
    U8  aud_path;                           /* audio path */
    srv_prof_audio_type_enum audio_type;    /* audio type */
    srv_prof_play_tone_callback callback;   /* callback */
} srv_prof_play_req_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Mute event structure */ 
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_prof_evt_mute_struct; 

/* Switch profile event structure */ 
typedef struct
{
    MMI_EVT_PARAM_HEADER
} srv_prof_evt_prof_switch_struct; 

typedef struct  
{
    MMI_EVT_PARAM_HEADER
    srv_prof_vol_type_enum vol_type;  
} srv_prof_evt_vol_change_struct;

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_prof_transform_audio_id_for_read_nvram
 * DESCRIPTION
 *  This function is to transform audio id
 *  
 * PARAMETERS
 *  audio_id  : [IN]    nvram audio id
 * RETURNS
 *  resource audio id
 *****************************************************************************/
extern srv_prof_audio_id srv_prof_transform_audio_id_for_read_nvram(kal_uint16 audio_id);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_transform_audio_id_for_write_nvram
 * DESCRIPTION
 *  This function is to transform audio id
 *  
 * PARAMETERS
 *  audio_id  : [IN]    resource audio id
 * RETURNS
 *  nvram audio id
 *****************************************************************************/
extern kal_uint16 srv_prof_transform_audio_id_for_write_nvram(srv_prof_audio_id audio_id);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_init
 * DESCRIPTION
 *  This function is to initialize user profiles service, including getting 
 *  data from NVRAM and other context initialization. This function is an 
 *  external API that can only be used one time during bootup procedure.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_prof_init(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_setting_available
 * DESCRIPTION
 *  This function is to check if specific setting is supported in current service
 * PARAMETERS
 *  setting  : [IN]    which setting item
 * RETURNS
 *  MMI_TRUE : supported
 *  MMI_FALSE : not supported
 *****************************************************************************/
extern MMI_BOOL srv_prof_is_setting_available(srv_prof_settings_enum setting);

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_ring_vol
 * DESCRIPTION
 *  To easily get ring volume
 * PARAMETERS
 *  void
 * RETURNS
 *  ring volume level
 *****************************************************************************/
extern srv_prof_volume_level srv_prof_get_ring_vol(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_media_vol
 * DESCRIPTION
 *  To easily get media volume
 * PARAMETERS
 *  void
 * RETURNS
 *  media volume level
 *****************************************************************************/
extern srv_prof_volume_level srv_prof_get_media_vol(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_current_profile_value
 * DESCRIPTION
 *  This function is to get setting value of current profile. The value will be filled
 *  in the second parameter and the caller shall cast it to the type of the setting value
 * PARAMETERS
 *  setting  : [IN]    which setting item
 *  value    : [OUT]   returns setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : get value success
 *  SRV_PROF_RET_SETTING_NOT_SUPPORTED : requested setting is not supported in 
 *                                       current profile service
 *****************************************************************************/
extern srv_prof_ret srv_prof_get_current_profile_value(srv_prof_settings_enum setting,void* value);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_current_profile_value
 * DESCRIPTION
 *  This function is to set setting value of current profile.
 * PARAMETERS
 *  setting  :  [IN]    which setting item
 *  value    :  [IN]    the setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : get value success
 *  SRV_PROF_RET_SETTING_NOT_SUPPORTED : setting is not supported in current profile service
 *  SRV_PROF_RET_FAIL : other errors (ex: current profile can not set this value)
 *****************************************************************************/
extern srv_prof_ret srv_prof_set_current_profile_value(srv_prof_settings_enum setting,void* value);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_current_profile_tone_with_file_path
 * DESCRIPTION
 *  This function is to set current profiles' tone with file path. Only works for tone setting.
 *  If current profile app's design does not allow to set a specific tone with file path, then
 *  then return value would be SRV_PROF_RET_SETTING_NOT_SUPPORTED.
 * PARAMETERS
 *  setting  :  [IN]    which setting item
 *  path     :  [IN]    file path to set
 *
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : get value success
 *  SRV_PROF_RET_SETTING_NOT_SUPPORTED : setting is not supported in current profile service
 *  SRV_PROF_RET_FAIL : other errors (ex: file path too long)
 *****************************************************************************/
extern srv_prof_ret srv_prof_set_current_profile_tone_with_file_path(srv_prof_settings_enum setting,WCHAR* path);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_activate_profile_by_external_module
 * DESCRIPTION
 *  This function is to activte specific profile and will not provide any pop up actions.
 *  It will also check if the requested profile can be activated in cureent status. 
 *  Ex: when earphone is plugged in, and current profile is in earphone profie, then 
 *  request to activate meeting profile will not be allowed.
 *  When silent profile is not supported, request to activte silent mode will turn on
 *  silent flag for all profiles.
 * PARAMETERS
 *  profile  :  [IN]    profile to activate
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : activate profile success
 *  SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *  SRV_PROF_RET_FAIL : other errors (ex: profile can not be actiaved in current status)
 *****************************************************************************/
extern srv_prof_ret srv_prof_activate_profile_by_external_module(srv_prof_external_profile_enum profile);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_deactivate_profile_by_external_module
 * DESCRIPTION
 *  This function is to deactivate specific profile and will not provide any pop up actions.
 *  It will also check if the requested profile can be activated in cureent status.
 *  Ex: when earphone is plugged in, and current profile is in earphone profie, then 
 *  request to activate meeting profile will not be allowed.
 *  When silent profile is not supported, request to deactivte silent mode will turn off
 *  silent flag for all profiles.
 * PARAMETERS
 *  profile  :  [IN]    profile to deactivate
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : deactivate profile success
 *  SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *  SRV_PROF_RET_FAIL : other errors (ex: profile can not be deactiaved in current status)
 *****************************************************************************/
extern srv_prof_ret srv_prof_deactivate_profile_by_external_module(srv_prof_external_profile_enum profile);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_num_of_profiles
 * DESCRIPTION
 *  This function is for other modules to get total number of profiles.s
 * PARAMETERS
 *  void
 * RETURNS
 *  total profile numbers
 *****************************************************************************/
extern U8 srv_prof_get_num_of_profiles(void);

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_num_of_audio_resource
 * DESCRIPTION
 *  This function is to get number of service generated audio resources of
 *  a specific resource type
 * PARAMETERS
 *  res_type  : [IN]    resource type
 * RETURNS
 *  number of audio resource
 *****************************************************************************/
extern U16 srv_prof_get_num_of_audio_resource(srv_prof_audio_resource_type_enum res_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_string_id_from_audio_resourece
 * DESCRIPTION
 *  This function is for other modules to get string id (framework string)
 *  by input the resource type and index of this type starting from 0.
 * PARAMETERS
 *  res_type  :  [IN]    resource type
 *  index     :  [IN]    index
 * RETURNS
 *  framework string id
 *****************************************************************************/
extern U16 srv_prof_get_string_id_from_audio_resourece(srv_prof_audio_resource_type_enum res_type, U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_audio_id_from_audio_resourece
 * DESCRIPTION
 *  This function is for other modules to get audio id (framework audio)
 *  by input the resource type and index of this type starting from 0.
 * PARAMETERS
 *  res_type  :  [IN]    respirce type
 *  index     :  [IN]    index
 * RETURNS
 *  framework audio id
 *****************************************************************************/
extern U16 srv_prof_get_audio_id_from_audio_resourece(srv_prof_audio_resource_type_enum res_type, U16 index);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_resource_info_from_audio_id
 * DESCRIPTION
 *  This function is for other modules to get resource info (resource tyep / index)
 *  by input the audio id (framework audio)
 * PARAMETERS
 *  res_type  :  [IN]    resource type
 *  index     :  [OUT]   index
 * RETURNS
 *  srv_prof_audio_resource_type_enu
 *****************************************************************************/
srv_prof_audio_resource_type_enum srv_prof_get_audio_info_from_audio_resourece(srv_prof_audio_id audio_id, U16 *index);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_string_id_from_srv_audio_id
 * DESCRIPTION
 *  This function is for other modules to get string id (framework string)
 *  by input a service audio id 
 * PARAMETERS
 *  srv_audio_id  :  [IN]    service audio id
 * RETURNS
 *  framework string id
 *****************************************************************************/
extern U16 srv_prof_get_string_id_from_srv_audio_id(srv_prof_audio_id srv_audio_id);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_special_key_tone_audio_id
 * DESCRIPTION
 *  This function is for modules to get audio resource id of digit tone by 
 *  inputs the keypad tone type and the index of keypad. If the keypad tone
 *  type is not of SRV_PROF_KEYPAD_NUM_1 ~ 5, SRV_PROF_KEYPAD_NUM_1 will be 
 *  applied.
 * PARAMETERS
 *  keypad_tone_type  :  [IN]    keypad tone type of digit tone
 *  index             :  [IN]    keypad type
 * RETURNS
 *  audio resource id
 *****************************************************************************/
extern U16 srv_prof_get_special_key_tone_audio_id(srv_prof_keypad_tone_type_enum keypad_tone_type, U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_cust_key_tone_audio_id
 * DESCRIPTION
 *  This function is for modules to get audio resource id of digit tone by 
 *  inputs the keypad tone type. If the keypad tone type is not of
 *  SRV_PROF_KEYPAD_CUST_1 ~ 5, SRV_PROF_KEYPAD_CUST_1 will be applied
 *  will be applied.
 * PARAMETERS
 *  keypad_tone_type  :  [IN]    keypad tone type of digit tone
 * RETURNS
 *  audio resource id
 *****************************************************************************/
extern U16 srv_prof_get_cust_key_tone_audio_id(srv_prof_keypad_tone_type_enum keypad_tone_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_query_mdi_play_mode
 * DESCRIPTION
 *  This function is for play tone user to know what kind of audio resuoce will be
 *  play with the tone_type.
 *  
 * PARAMETERS
 *  srv_prof_tone_enum  :  [IN]    tone_type
 *
 * RETURNS
 *  MDI_AUDIO_PLAY_ID: play with DTMF tone
 *  MDI_AUDIO_PLAY_STRING: play with audio resource string
 *  MDI_AUDIO_PLAY_FILE: play with file
 *****************************************************************************/
extern MDI_AUDIO_PLAY_MODE_ENUM srv_prof_play_tone_query_mdi_play_mode(srv_prof_tone_enum tone_type);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone
 * DESCRIPTION
 *  This function is for mmi modules to play tone type.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, when mdi audio callback with events, profile 
 *  service will callback with srv_prof_ret. But this only works for non-DTMF tones.
 *  For DTMF tones, the return value of this function will be SRV_PROF_RET_SUCCESS_WO_CALLBACK
 *  ,which means there is no callback for this play request.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, service will try to recover
 *  with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type  :  [IN]    requested tone type
 *  callback   :  [IN]    play tone callback
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *  SRV_PROF_RET_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *  SRV_PROF_RET_FAIL : play tone fail and will not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone(srv_prof_tone_enum tone_type, 
                                       srv_prof_play_tone_callback callback);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_id
 * DESCRIPTION
 *  This function is for some modules which keeps thier own tone id to play.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, hen mdi audio callback with events, profile
 *  service will callback with srv_prof_ret. But this only works for non-DTMF tones.
 *  For DTMF tones, the return value of this function will be SRV_PROF_RET_SUCCESS_WO_CALLBACK
 *  which means there is no callback for this play request.
 *
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, service will try to recover
 *  with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type  :  [IN]    requested tone type
 *  tone_id    :  [IN]    tone id to be played
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *  SRV_PROF_RET_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *  SRV_PROF_RET_FAIL : play tone fail and will not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone_with_id(srv_prof_tone_enum tone_type, 
                                               U16 audio_id,
                                               srv_prof_ring_type_enum play_type,
                                               srv_prof_play_tone_callback callback);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_audio_data
 * DESCRIPTION
 *  This function is for modules to play tone with generated audio data (audio string).
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, when mdi audio callback with events, profile
 *  service will callback with srv_prof_ret.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, 
 *  service will try to recover with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type     :            [IN]    requested tone type
 *  audio_data_ptr   :       [IN]    audio data memory pointer
 *  audio_data_format  :   [IN]    audio data format
 *  audio_data_len     :    [IN]    audio data length
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone_with_audio_data(srv_prof_tone_enum tone_type, 
                                                       U8* audio_data_ptr,
                                                       U8  audio_data_format,
                                                       U32 audio_data_len,
                                                       srv_prof_ring_type_enum play_style,
                                                       srv_prof_play_tone_callback callback);

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_filepath
 * DESCRIPTION
 *  This function is for modules to play tone with a prepared file path.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, hen mdi audio callback with events, profile
 *  service will callback with srv_prof_ret.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, 
 *  service will try to recover with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type  :  [IN]    requested tone type
 *  filepath   :  [IN]    file path to play
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *  SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *  SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone_with_filepath(srv_prof_tone_enum tone_type, 
                                                     WCHAR* filepath,
                                                     srv_prof_ring_type_enum play_type,
                                                     srv_prof_play_tone_callback callback);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_text
 * DESCRIPTION
 *  This function is for modules to play tone with text words. Currently is used for
 *  intelligent call alert for incoming call.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, hen mdi audio callback with events, profile
 *  service will callback with srv_prof_ret.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, 
 *  service will try to recover with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type  :  [IN]    requested tone type
 *  text       :  [IN]    text to play
 *  text_speed :  [IN]    text play speed in msec.
 *  callback   :  [IN]    callback function
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *  SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *  SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone_with_text(srv_prof_tone_enum tone_type, 
                                                 U8* text,
                                                 S32 text_speed,
                                                 srv_prof_play_tone_callback callback);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_req_struct_init
 * DESCRIPTION
 *  This function is to init the play structure for playwith full struct
 *  The default values are shown as below.
 *    audio_id  : 0     (MUST revise again if play id)
 *    file_path : NULL  (MUST revise again if play file)
 *    audio_type: SRV_PROF_AUDIO_NONE (MUST revise according to play id or file)
 *    aud_path  : MDI_AUD_PTH_EX(MDI_DEVICE_SPEAKER2)
 *    callback  : NULL
 *    paly_style: SRV_PROF_RING_TYPE_REPEAT
 *    tone_type : tone_type
 *    volumn    : depends on tone type, for message kinds, the message volume are applied,
 *                otherwise, ring volume are applied.
 * PARAMETERS
 *  play_struct  :  [IN]    play struct to init
 *  tone_type    :  [IN]    tone type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_prof_play_req_struct_init(srv_prof_play_req_struct* play_struct, srv_prof_tone_enum tone_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_full_struct
 * DESCRIPTION
 *  This function is for modules to play according to its own configure.
 *  Plz remember to use srv_prof_play_req_struct_init to initiate the configurations
 *  and update the audio_id / filepath and audio_type
 * PARAMETERS
 *  play_struct  :  [IN]    play structure
 * RETURNS
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *  SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *  SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *  SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
extern srv_prof_ret srv_prof_play_tone_with_full_struct(srv_prof_play_req_struct* play_struct);

 

/*****************************************************************************
 * FUNCTION
 *  srv_prof_stop_tone
 * DESCRIPTION
 *  This function is to stop the requested tone which is requested to play before.
 * PARAMETERS
 *  tone_type  :  [IN]    requested tone type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_prof_stop_tone(srv_prof_tone_enum tone_type);
/* DOM-NOT_FOR_SDK-BEGIN */
extern void srv_profiles_stop_tone(srv_prof_tone_enum tone_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_tone_playing
 * DESCRIPTION
 *  This function is to check if the tone_type is crrently playing
 * PARAMETERS
 *  tone_type  :  [IN]    query tone type
 * RETURNS
 *  MMI_TRUE : tone_type is playing
 *  MMI_FALSE : tone_type is not playing
 *****************************************************************************/
extern MMI_BOOL srv_prof_is_tone_playing(srv_prof_tone_enum tone_type);

/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_audio_id_available
 * DESCRIPTION
 *  This function is to check if audio file of the audio id still exists
 *  including external melody, theme tone ... etc.
 * PARAMETERS
 *  audio_id  :  [IN]    audio id to query
 * RETURNS
 *  MMI_TRUE : audio id still exists
 *  MMI_FALSE : audio id does not exist anymore
 *****************************************************************************/
extern MMI_BOOL srv_prof_is_audio_id_available(srv_prof_audio_id audio_id);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_reset_tone_with_audio_id
 * DESCRIPTION
 *  This function is for other modules to reset a specific tone to default. This will apply to 
 *  all profiles. ex: MMI Theme is deleted, so it needs to reset all incoming call tone which
 *  are set as theme tone (the audio_id input) to default.
 * 
 * PARAMETERS
 *  tone_setting  :  [IN]    tone setting item (ex: SRV_PROF_SETTINGS_MT_CALL_TONE)
 *  audio_id      :  [IN]    audio_id for check and reset
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : reset tone success
 *  SRV_PROF_RET_SETTING_NOT_SUPPORTED : setting is not supported in current profile service
 *  SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
extern srv_prof_ret srv_prof_reset_tone_with_audio_id(srv_prof_settings_enum tone_setting, srv_prof_audio_id audio_id);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_delete_file_update_hdlr
 * DESCRIPTION
 *  This function is to update tone setting when file is deleted from other module.
 * 
 * PARAMETERS
 *  del_path  :  [IN]    file path which has been deleted
 *  del_type  :  [IN]    type of deletion (ex: SRV_PROF_DEL_FILE)
 * RETURNS
 *  SRV_PROF_RET_SUCCESS : update success
 *  SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
extern srv_prof_ret srv_prof_delete_file_update_hdlr(WCHAR* del_path, srv_prof_del_type_enum del_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_file_path_by_audio_id
 * DESCRIPTION
 *  This function is to get file path (external file) with audio id
 * 
 * PARAMETERS
 *  path_buf  :  [OUT]   file path of request audio id
 *  audio_id  :  [IN]    audio id to query
 * RETURNS 
 *  SRV_PROF_RET_SUCCESS : success
 *  SRV_PROF_RET_FAIL : other errors (ex: audio id not in the correct range)
 *****************************************************************************/
extern srv_prof_ret srv_prof_get_file_path_by_audio_id(WCHAR* path_buf, srv_prof_audio_id audio_id);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_profile_activated
 * DESCRIPTION
 *  This function is to check if a specific profile is currently activated.
 *  If there is no such profile cofigured for profile service, the return
 *  value will be SRV_PROF_RET_PROFILE_NOT_SUPPORTED.
 * PARAMETERS
 *  profile  :  [IN]    profile enum to be checked
 * RETURNS
 *  SRV_PROF_RET_PROFILE_ACTIVATED     : profile activated
 *  SRV_PROF_RET_PROFILE_NOT_ACTIVATED : profile not activated
 *  SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *****************************************************************************/
extern srv_prof_ret srv_prof_is_profile_activated(srv_prof_external_profile_enum profile);

/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_app_playing
 * DESCRIPTION
 *  This function is to check if there is any application playing currently
 *  by emiting EVT_ID_SRV_PROF_IS_PLAYING to query registered applications
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_TRUE : some app is playing audio
 *  MMI_FASLE : no app is plyaing audio
 *****************************************************************************/
extern MMI_BOOL srv_prof_is_app_playing(void);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_if_can_vibrate
 * DESCRIPTION
 *  This function will tell the caller if he shall vibrate based on current 
 *  profile's setting. In plutommi profile app, we will check alert type and
 *  reutrns MMI_TRUE if the setting is not SRV_PROF_ALERT_TYPE_RING. Please be 
 *  aware that in plutommi, this is only for users who is intersted in alert
 *  type setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_prof_if_can_vibrate(void);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_if_can_ring
 * DESCRIPTION
 *  This function will tell the caller if he shall ring based on current 
 *  profile's setting. In plutommi profile app, we will check alert type and
 *  reutrns MMI_TRUE if the setting is not SRV_PROF_ALERT_TYPE_VIB_ONLY. 
 *  Please be aware that in plutommi, this is only for users who is intersted
 *  in alert type setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_prof_if_can_ring(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_prof_bt_connected_hdlr
 * DESCRIPTION
 *  This function is for BTCM to inform profile service of bt connected.
 * PARAMETERS
 *  connect_type  :  [IN]    connect type (ex: ACL/SCO)
 *  callback_type :  [IN]    callback type
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_prof_bt_connected_hdlr(srv_prof_bt_connect_type_enum connect_type, srv_prof_bt_cb_type_enum callback_type);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_bt_disconnected_hdlr
 * DESCRIPTION
 *  This function is for BTCM service to inform profile service of bt disconnected.
 * PARAMETERS
 *  connect_type  :  [IN]    connect type (ex: ACL/SCO)
 *  callback_type :  [IN]    callback type
 * RETURNS
 *  void 
 *****************************************************************************/
extern void srv_prof_bt_disconnected_hdlr(srv_prof_bt_connect_type_enum connect_type, srv_prof_bt_cb_type_enum callback_type);


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  srv_prof_handfree_volume_sync_hdlr
 * DESCRIPTION
 *  This function is for mdi_audio to sync handfree volume. If the notify callback 
 *  is registered, then profile service will callback and wait for app to set volume.
 *  If it is not registered, then profile service will set the sync volume to activat
 *  profile's ring volume level.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prof_handfree_volume_sync_hdlr(U8 volume);
#endif /*__BT_SPK_VOL_CONTROL__*/
/* DOM-NOT_FOR_SDK-END */

#endif /* PROFILES_SRV_GPROT_H */

