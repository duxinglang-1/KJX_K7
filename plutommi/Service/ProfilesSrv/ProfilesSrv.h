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
 * ProfilesSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   User profiles service internal header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PROFILES_SRV_H
#define PROFILES_SRV_H

#include "MMI_features.h"

#include "ProfilesSrvConfig.h"
#include "ProfilesSrvGProt.h"
#include "FileMgrSrvGProt.h"

#include "custom_srv_prof_defs.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

/*****************************************************************************
 * Enumeration and definitions
 *****************************************************************************/

/* This enum defines the evnet to callback to user profiles app */
typedef enum
{
    SRV_PROF_CB_SLOT_QUERY,       /* Query for external melody slot, [Input]srv_prof_settings_enum, [Output]U8 */
    SRV_PROF_CB_AT_MODIFIED,      /* Setting change by AT command, [Input]srv_prof_settings_enum, [Output]Null */
    SRV_PROF_CB_PROFILE_SWITCHED, /* Profile Switched, [Input]current profile, [Output]NULL */
    SRV_PROF_CB_END_OF_ENUM       /* End of enum */
}srv_prof_cb_enum;


/* This enum defines the profile name for user profiles app to refer to */
typedef enum
{
    SRV_PROF_PROFILE_NULL,          /* Invalid profile */
    SRV_PROF_PROFILE_1,             /* The 1st profile */
    SRV_PROF_PROFILE_2,             /* The 2nd profile */
    SRV_PROF_PROFILE_3,             /* The 3rd profile */
    SRV_PROF_PROFILE_4,             /* The 4th profile */
    SRV_PROF_PROFILE_5,             /* The 5th profile */
    SRV_PROF_PROFILE_6,             /* The 6th profile */
    SRV_PROF_PROFILE_7,             /* The 7th profile */
    SRV_PROF_PROFILE_8,             /* The 8th profile */
    SRV_PROF_PROFILE_END_OF_ENUM    /* End of enum */
}srv_prof_internal_profile_enum;


typedef srv_prof_ret (*srv_profiles_notify_callback) (srv_prof_cb_enum event, void* input, void* output);

#define SRV_PROF_BIT_TEST(b, a)          (( (b) & (0x1 << (a))) >> (a))
#define SRV_PROF_BIT_ON(b, a)            ( (b) |= (0x1 << (a)))
#define SRV_PROF_BIT_OFF(b, a)           ( (b) &= ~(0x1 << (a)))


/***************************************************************************** 
* Structure definitions
*****************************************************************************/

/* Service settings structure */
typedef struct
{
    srv_prof_volume_level ring_vol;             /* ring volume level */
    srv_prof_volume_level keypad_vol;           /* keypad volume level */
    srv_prof_volume_level msg_vol;              /* message volume level */
#ifdef __MMI_UNIQUE_MEDIA_VOL__
    srv_prof_volume_level media_vol;            /* media volume level */
#endif

    srv_prof_alert_type_enum alert_type;        /* alert type */
    MMI_BOOL noti_sound;                        /* notification sound */
    MMI_BOOL vibrate;                           /* if can vibrate */
    srv_prof_ring_type_enum ring_type;          /* ring type */
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    MMI_BOOL intelligent_call_alert;            /* intelligent call alert */
#endif
    MMI_BOOL system_alert;                      /* system alert */
    srv_prof_led_pattern_enum led_pattern;      /* led color pattern */
    srv_prof_keypad_tone_type_enum keypad_tone_type;    /* keypad tone type */

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_POWER_ON_OFF_MUTE__
    srv_prof_audio_id power_on_tone;            /* power on tone */
    srv_prof_audio_id power_off_tone;           /* power off tone */
    MMI_BOOL power_on_off_tone;                 /* power on/off tone siwther */
#endif
#ifdef __MMI_CLAMSHELL__
    srv_prof_audio_id cover_open_tone;          /* cover open tone */
    srv_prof_audio_id cover_close_tone;         /* cover close tone */
#endif

#if (SRV_PROF_SMS_TONE_AMOUNT > 0)
    srv_prof_audio_id sms_tone[SRV_PROF_SMS_TONE_AMOUNT];         /* sms tone series */
#endif 

#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
    srv_prof_audio_id mms_tone[SRV_PROF_MMS_TONE_AMOUNT];         /* mms tone series */
#endif

#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
    srv_prof_audio_id email_tone[SRV_PROF_EMAIL_TONE_AMOUNT];     /* email tone series */
#endif

#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
    srv_prof_audio_id voice_tone[SRV_PROF_VOICE_TONE_AMOUNT];     /* voice tone series */
#endif

#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
    srv_prof_audio_id mt_call_tone[SRV_PROF_MT_CALL_TONE_AMOUNT]; /* mt call tone series */
#endif

#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
    srv_prof_audio_id vt_call_tone[SRV_PROF_VT_CALL_TONE_AMOUNT]; /* vt call tone series */
#endif
} srv_prof_setting_struct;


#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
/* external melody info struct*/
typedef struct
{
    WCHAR filefullpath[SRV_FMGR_PATH_MAX_LEN+1];
}srv_prof_ext_melody_info_struct;


/* external melody struct*/
typedef struct
{
    U64 valid_bit;
    srv_prof_ext_melody_info_struct info[SRV_PROF_EXT_MELODY_NUM];
}srv_prof_ext_melody_struct;
#endif


/* Play tone context structure*/
typedef struct
{
    srv_prof_play_tone_callback tone_cb;          /* play tone callback */
    srv_prof_audio_type_enum audio_type;          /* current playing audio type */
    srv_prof_audio_type_enum key_audio_type;      /* current key tone audio type */    
    MMI_BOOL key_playing;                         /* if key is playing */
    U8 audio_path;                                /* audio path */
    srv_prof_tone_enum current_tone;              /* current playing tone */
    srv_prof_tone_enum current_DTMF_tone;         /* current playing tone */
    srv_prof_tone_enum conflict_tone;             /* current playing non DTMF tone, for preventing conflict playing */
    U8 play_style;                                /* current playing style, for recover usage */    
}srv_prof_play_tone_struct;


/* Service contect structure */
typedef struct
{
    S8 cur_prof;                                  /* cur profile */
    S8 last_prof;                                 /* last profile */
    U8 buf_prof;                                  /* buffered profile */
    srv_profiles_notify_callback app_cb;          /* profile app notify callback */
    MMI_BOOL is_inited;                           /* is initialized */
    srv_prof_play_tone_struct play_tone;          /* play tone context */
    srv_prof_setting_struct cur_setting;          /* current setting */
    srv_prof_setting_struct buf_setting;          /* buffer setting */
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    srv_prof_ext_melody_struct ext_melody;        /* external melody context */
#endif
} srv_prof_cntx_struct;


typedef struct
{
    srv_prof_audio_id audio_id;             /* audio id to play*/
    srv_prof_ring_type_enum play_style;     /* play style */
    srv_prof_volume_level volume;           /* volume */
    srv_prof_tone_enum tone_type;           /* tone type */
    U8  aud_path;                           /* audio path */
    MMI_BOOL play_from_full_struct;         /* play from full struct */
} srv_prof_play_audio_struct;

/***************************************************************************** 
* Internal Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_prof_reset_to_default
 * DESCRIPTION
 *  This function is for user profiles app to reset a specific profile to default
 *  value.
 * PARAMETERS
 *  srv_prof_internal_profile_enum    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern srv_prof_ret srv_prof_reset_to_default(srv_prof_internal_profile_enum profile);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_register_app_callback
 * DESCRIPTION
 *  This function is for user profiles app to register callback function. When some  
 *  events happens, like profile automaically switched, profile service will
 *  notity the event with this callback. There is only one callback hdlr, so only 
 *  one module could register it.
 * PARAMETERS
 *  srv_profiles_notify_callback    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_prof_register_app_callback(srv_profiles_notify_callback callback);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_profile_values
 * DESCRIPTION
 *  This function is to get setting value of specific profile. The value will be filled
 *  in the third parameter and the caller shall cast it to the type of the setting value
 * PARAMETERS
 *  profile     [IN]     which profile
 *  setting     [OUT]    return values
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : get value success
 *      SRV_PROF_RET_FAIL : get value fail
 *****************************************************************************/
extern srv_prof_ret srv_prof_get_profile_values(srv_prof_internal_profile_enum profile,
                                                srv_prof_setting_struct* setting);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_profile_values
 * DESCRIPTION
 *  This function is to set setting values of specific profile.
 * PARAMETERS
 *  profile     [IN]     which profile
 *  setting     [IN]    setting values
 * RETURNS
 *  srv_prof_ret
 *      SRV_PROF_RET_SUCCESS : get value success
 *      SRV_PROF_RET_FAIL : get value fail
 *****************************************************************************/
extern srv_prof_ret srv_prof_set_profile_values(srv_prof_internal_profile_enum profile,
                                                srv_prof_setting_struct* setting);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_activate_profile
 * DESCRIPTION
 *  This function is to activate specific profile, shall be used only for profile app
 * PARAMETERS
 *  profile     [IN]    which profile
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : activate profile success
 *      SRV_PROF_RET_FAIL : other errors 
 *****************************************************************************/
extern srv_prof_ret srv_prof_activate_profile(srv_prof_internal_profile_enum profile);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_activated_profile
 * DESCRIPTION
 *  This function is to get activated profile number
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_prof_internal_profile_enum
 *  
 *****************************************************************************/
extern srv_prof_internal_profile_enum srv_prof_get_activated_profile(void);


/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_file_path_to_ext_melody
 * DESCRIPTION
 *  This function is to set a specific slot with external melody
 *  
 * PARAMETERS
 *  slot        [IN]    slot to set
 *  path        [IN]    file path to set
 *
 * RETURNS
 * srv_prof_ret    
 *  SRV_PROF_RET_SUCCESS : check ok
 *  SRV_PROF_RET_MIDI_FILE_TOO_LARGE : midi file too large
 *  SRV_PROF_RET_MIDI_CHECK_FILE_FAIL : can not check midi file size
 *  SRV_PROF_RET_STR_TOO_LONG : file path string too long
 *  SRV_PROF_RET_EXT_MELODY_REPLACED : the old file path is replaced
 *  SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
extern srv_prof_ret srv_prof_set_file_path_to_ext_melody(U8 slot,WCHAR* path);

#endif /* PROFILES_SRV_H */

