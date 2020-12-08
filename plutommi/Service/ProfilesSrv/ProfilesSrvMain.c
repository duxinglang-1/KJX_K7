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
 * ProfilesSrvMain.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   User profiles service source file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Included files
*****************************************************************************/
#include "MMI_features.h"
#include "ProfilesSrv.h"
#include "Gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "CallSetSrvGProt.h"
#include "Resource_audio.h"
#include "Gpiosrvgprot.h"

#include "mdi_audio.h"
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#include "Mmi_theme_mgr.h"
#endif

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
#include "FMRadioProt.h"
#endif

#include "Nvram_interface.h" /* nvram_get_default_value */
#include "mmi_frm_nvram_gprot.h" /* reset nvram record */
#include "Mmi_rp_srv_prof_def.h"

#include "ProtocolEvents.h"

#include "BthScoPathSrvGprot.h"

#include "ShutdownSrvGprot.h"
#include "TimerEvents.h"
#include "mdi_datatype.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProfilesSrvGprot.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "custom_srv_prof_defs.h"
#include "userprofile_nvram_def.h"
#include "ProfilesSrvConfig.h"
#include "kal_public_api.h"
#include "string.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "custom_mmi_default_value.h"
#include "device.h"
#include "nvram_enums.h"
#include "custom_nvram_config.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrSrvGProt.h"
#include "fs_type.h"
#include "fs_func.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "fs_errcode.h"
#include "AlarmDef.h"

static void srv_prof_play_audio_callback(mdi_result result, void *user_data);
static void srv_prof_store_cur_setting_timeout(void);
static void srv_prof_store_buf_setting_timeout(void);

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
srv_prof_cntx_struct g_srv_prof;


/*****************************************************************************
 * FUNCTION
 *  srv_prof_transform_audio_id_for_read_nvram
 * DESCRIPTION
 *  This function is to transform audio id
 *  
 * PARAMETERS
 *  U16  [IN]
 * RETURNS
 *  srv_prof_audio_id
 *****************************************************************************/
srv_prof_audio_id srv_prof_transform_audio_id_for_read_nvram(kal_uint16 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_TRANSFORM_ID,audio_id);

    if(audio_id >= SRV_PROF_AUD_TONE1 && audio_id < SRV_PROF_AUD_TONE_END_OF_ENUM)
    {
        return (srv_prof_audio_id)(audio_id - SRV_PROF_AUD_TONE1 + AUD_ID_PROF_TONE1);
    }

    if(audio_id >= SRV_PROF_AUD_RING1 && audio_id < SRV_PROF_AUD_RING_END_OF_ENUM)
    {
        return (srv_prof_audio_id)(audio_id - SRV_PROF_AUD_RING1 + AUD_ID_PROF_RING1);
    }

    return (srv_prof_audio_id)audio_id;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_copy_settings_for_read_nvram
 * DESCRIPTION
 *  This function is to copy nvram data to setting
 *  
 * PARAMETERS
 *  srv_prof_setting_struct*  [OUT]
 *  nvram_srv_prof_setting_struct*  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_copy_settings_for_read_nvram(srv_prof_setting_struct *dest_setting, nvram_srv_prof_setting_struct *src_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* ring volume level */
    dest_setting->ring_vol = (srv_prof_volume_level)src_setting->ring_vol;
    /* keypad volume level */
    dest_setting->keypad_vol = (srv_prof_volume_level)src_setting->keypad_vol;
    /* message volume level */
    dest_setting->msg_vol = (srv_prof_volume_level)src_setting->msg_vol;
#ifdef __MMI_UNIQUE_MEDIA_VOL__
    /* message volume level */
    dest_setting->media_vol = (srv_prof_volume_level)src_setting->media_vol;
#endif

    /* alert type */
    dest_setting->alert_type = (srv_prof_alert_type_enum)src_setting->alert_type;
    /* notification sound */
    dest_setting->noti_sound = (MMI_BOOL)src_setting->noti_sound;
    /* vibrate */
    dest_setting->vibrate = (MMI_BOOL)src_setting->vibrate;
    /* ring type */
    dest_setting->ring_type = (srv_prof_ring_type_enum)src_setting->ring_type;
    /* intelligent call alert */
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    dest_setting->intelligent_call_alert = (MMI_BOOL)src_setting->intelligent_call_alert;
#endif
    /* system alert */
    dest_setting->system_alert = (MMI_BOOL)src_setting->system_alert;
    /* led color pattern */
    dest_setting->led_pattern = (srv_prof_led_pattern_enum)src_setting->led_pattern;
    /* keypad tone type */
    dest_setting->keypad_tone_type = (srv_prof_keypad_tone_type_enum)src_setting->keypad_tone_type;

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_POWER_ON_OFF_MUTE__
    /* power on tone */
    dest_setting->power_on_tone = srv_prof_transform_audio_id_for_read_nvram(src_setting->power_on_tone);
    /* power off tone */
    dest_setting->power_off_tone = srv_prof_transform_audio_id_for_read_nvram(src_setting->power_off_tone);
    /* power on / off tone switcher */
    dest_setting->power_on_off_tone = (MMI_BOOL)src_setting->power_on_off_tone;
#endif
#ifdef __MMI_CLAMSHELL__
    /* cover open tone */
    dest_setting->cover_open_tone = srv_prof_transform_audio_id_for_read_nvram(src_setting->cover_open_tone);
    /* cover close tone */
    dest_setting->cover_close_tone = srv_prof_transform_audio_id_for_read_nvram(src_setting->cover_close_tone);
#endif
    /* sms tone */
#if (SRV_PROF_SMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_SMS_TONE_AMOUNT; count++)
    {
        dest_setting->sms_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->sms_tone[count]);
    }
#endif

    /* mms tone */
#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MMS_TONE_AMOUNT; count++)
    {
        dest_setting->mms_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->mms_tone[count]);
    }
#endif

    /* email tone */
#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_EMAIL_TONE_AMOUNT; count++)
    {
        dest_setting->email_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->email_tone[count]);
    }
#endif

    /* voice tone */
#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VOICE_TONE_AMOUNT; count++)
    {
        dest_setting->voice_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->voice_tone[count]);
    }
#endif

    /* mt call tone */
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MT_CALL_TONE_AMOUNT; count++)
    {
        dest_setting->mt_call_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->mt_call_tone[count]);
    }
#endif

    /* vt call tone */
#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VT_CALL_TONE_AMOUNT; count++)
    {
        dest_setting->vt_call_tone[count] = srv_prof_transform_audio_id_for_read_nvram(src_setting->vt_call_tone[count]);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_transform_audio_id_for_write_nvram
 * DESCRIPTION
 *  This function is to transform audio id
 *  
 * PARAMETERS
 *  srv_prof_audio_id  [IN]
 * RETURNS
 *  kal_uint16
 *****************************************************************************/
kal_uint16 srv_prof_transform_audio_id_for_write_nvram(srv_prof_audio_id audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_TRANSFORM_ID,audio_id);

    if(audio_id > AUD_ID_PROF_TONE_BEGIN && audio_id < AUD_ID_PROF_TONE_END)
    {
        return (kal_uint16)(audio_id - AUD_ID_PROF_TONE1 + SRV_PROF_AUD_TONE1);
    }

    if(audio_id > AUD_ID_PROF_RING_BEGIN && audio_id < AUD_ID_PROF_RING_END)
    {
        return (kal_uint16)(audio_id - AUD_ID_PROF_RING1 + SRV_PROF_AUD_RING1);
    }

    return (kal_uint16)audio_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_copy_settings_for_write_nvram
 * DESCRIPTION
 *  This function is to copy nvram data to setting
 *  
 * PARAMETERS
 *  nvram_srv_prof_setting_struct*  [OUT]
 *  srv_prof_setting_struct*  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_copy_settings_for_write_nvram(nvram_srv_prof_setting_struct *dest_setting, srv_prof_setting_struct *src_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ring volume level */
    dest_setting->ring_vol = (kal_uint8)src_setting->ring_vol;
    /* keypad volume level */
    dest_setting->keypad_vol = (kal_uint8)src_setting->keypad_vol;
    /* message volume level */
    dest_setting->msg_vol = (kal_uint8)src_setting->msg_vol;
#ifdef __MMI_UNIQUE_MEDIA_VOL__
    dest_setting->media_vol = (kal_uint8)src_setting->media_vol;
#endif

    /* alert type */
    dest_setting->alert_type = (kal_uint8)src_setting->alert_type;
    /* notification sound */
    dest_setting->noti_sound = (kal_bool)src_setting->noti_sound;
    /* vibrate */
    dest_setting->vibrate = (kal_bool)src_setting->vibrate;

    /* ring type */
    dest_setting->ring_type = (kal_uint8)src_setting->ring_type;
    /* intelligent call alert */
#ifdef __MMI_INTELLIGENT_CALL_ALERT__
    dest_setting->intelligent_call_alert = (kal_bool)src_setting->intelligent_call_alert;
#endif
    /* system alert */
    dest_setting->system_alert = (kal_bool)src_setting->system_alert;
    /* led color pattern */
    dest_setting->led_pattern = (kal_uint8)src_setting->led_pattern;
    /* keypad tone type */
    dest_setting->keypad_tone_type = (kal_uint8)src_setting->keypad_tone_type;

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_POWER_ON_OFF_MUTE__
    /* power on tone */
    dest_setting->power_on_tone = srv_prof_transform_audio_id_for_write_nvram(src_setting->power_on_tone);
    /* power off tone */
    dest_setting->power_off_tone = srv_prof_transform_audio_id_for_write_nvram(src_setting->power_off_tone);
    /* power on / off tone switcher */
    dest_setting->power_on_off_tone = (kal_bool)src_setting->power_on_off_tone;
#endif
#ifdef __MMI_CLAMSHELL__
    /* cover open tone */
    dest_setting->cover_open_tone = srv_prof_transform_audio_id_for_write_nvram(src_setting->cover_open_tone);
    /* cover close tone */
    dest_setting->cover_close_tone = srv_prof_transform_audio_id_for_write_nvram(src_setting->cover_close_tone);
#endif
    /* sms tone */
#if (SRV_PROF_SMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_SMS_TONE_AMOUNT; count++)
    {
        dest_setting->sms_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->sms_tone[count]);
    }
#endif

    /* mms tone */
#if (SRV_PROF_MMS_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MMS_TONE_AMOUNT; count++)
    {
        dest_setting->mms_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->mms_tone[count]);
    }
#endif

    /* email tone */
#if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_EMAIL_TONE_AMOUNT; count++)
    {
        dest_setting->email_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->email_tone[count]);
    }
#endif

    /* voice tone */
#if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VOICE_TONE_AMOUNT; count++)
    {
        dest_setting->voice_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->voice_tone[count]);
    }
#endif

    /* mt call tone */
#if (SRV_PROF_MT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_MT_CALL_TONE_AMOUNT; count++)
    {
        dest_setting->mt_call_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->mt_call_tone[count]);
    }
#endif

    /* vt call tone */
#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
    for(count=0; count < SRV_PROF_VT_CALL_TONE_AMOUNT; count++)
    {
        dest_setting->vt_call_tone[count] = srv_prof_transform_audio_id_for_write_nvram(src_setting->vt_call_tone[count]);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_read_nvram_to_setting
 * DESCRIPTION
 *  This function is to read nvram to setting
 *  
 * PARAMETERS
 *  srv_prof_internal_profile_enum  [IN]
 *  srv_prof_setting_struct [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_read_nvram_to_setting(srv_prof_internal_profile_enum profile, srv_prof_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_srv_prof_setting_struct *temp_profile;
    U16 nvram_setting_size = sizeof(nvram_srv_prof_setting_struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_READ_NVRAM,0);

    temp_profile = (nvram_srv_prof_setting_struct*)get_ctrl_buffer(nvram_setting_size);

    if(temp_profile == NULL)
    {
        return;
    }

    ReadRecord(NVRAM_EF_SRV_PROF_SETTING_LID,
               profile,
               temp_profile,
               nvram_setting_size,
               &error);

    if(error != NVRAM_READ_SUCCESS)
    {
        //TODO: reset to default and restore, free buffer

        if(temp_profile != NULL)
        {
            free_ctrl_buffer(temp_profile);
        }

        return;
    }

#ifdef __KJX_FUN__	//xb add 2018-01-11	默认来电铃声及音乐播放铃声及按键声
	temp_profile->ring_vol = 7;
	temp_profile->media_vol = 7;
	temp_profile->keypad_vol = 7;
#endif

    srv_prof_copy_settings_for_read_nvram(setting, temp_profile);

    if(temp_profile != NULL)
    {
        free_ctrl_buffer(temp_profile);
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_read_nvram_to_setting_all
 * DESCRIPTION
 *  This function is to read nvram to setting for all profiles
 *  
 * PARAMETERS
 *  srv_prof_setting_struct [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__

static void srv_prof_read_nvram_to_setting_all(srv_prof_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_srv_prof_setting_struct *temp_profile;
    U16 nvram_setting_size = sizeof(nvram_srv_prof_setting_struct)*SRV_PROF_PROFILES_TOTAL_NUM;
    U8 cont;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_READ_NVRAM,1);

    temp_profile = (nvram_srv_prof_setting_struct*)get_ctrl_buffer(nvram_setting_size);

    if(temp_profile == NULL)
    {
        return;
    }

    memset(temp_profile,0,nvram_setting_size);

    ReadMultiRecord(NVRAM_EF_SRV_PROF_SETTING_LID,
                    1,
                    temp_profile,
                    nvram_setting_size,
                    SRV_PROF_PROFILES_TOTAL_NUM,
                    &error);

    if(error != NVRAM_READ_SUCCESS)
    {
        //TODO: reset to default and restore. free buffer

        if(temp_profile != NULL)
        {
            free_ctrl_buffer(temp_profile);
        }
        return;
    }

    for(cont=0; cont<SRV_PROF_PROFILES_TOTAL_NUM; cont++)
    {
        srv_prof_copy_settings_for_read_nvram(&setting[cont],&temp_profile[cont]);
    }

    if(temp_profile != NULL)
    {
        free_ctrl_buffer(temp_profile);
    }

    return;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_prof_write_nvram_from_setting
 * DESCRIPTION
 *  This function is to write nvram with new setting values
 *  
 * PARAMETERS
 *  srv_prof_internal_profile_enum  [IN]
 *  srv_prof_setting_struct [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_write_nvram_from_setting(srv_prof_internal_profile_enum profile, srv_prof_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_srv_prof_setting_struct *temp_profile;
    U16 nvram_setting_size = sizeof(nvram_srv_prof_setting_struct);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_WRITE_NVRAM);

    temp_profile = (nvram_srv_prof_setting_struct*)get_ctrl_buffer(nvram_setting_size);

    if(temp_profile == NULL)
    {
        return;
    }
    
    memset(temp_profile,0,nvram_setting_size);

    srv_prof_copy_settings_for_write_nvram(temp_profile, setting);

    mmi_frm_write_async_record(NVRAM_EF_SRV_PROF_SETTING_LID,profile,temp_profile,nvram_setting_size);

    if(temp_profile != NULL)
    {
        free_ctrl_buffer(temp_profile);
    }
        

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_AT_set_volume
 * DESCRIPTION
 *  Set volume from AT command
 * PARAMETERS
 *  msg            [IN]
 *  src_mod_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_AT_set_volume(void *msg, S32 src_mod_id)
{
        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_volume_req_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,0);

    msgReq = (mmi_eq_set_volume_req_struct*) msg;

    switch (msgReq->volume_type)
    {
        case MDI_VOLUME_MEDIA:
            if (msgReq->volume_level < SRV_PROF_VOL_LEVEL_END_OF_ENUM)
            {
                if(g_srv_prof.cur_setting.ring_vol != (srv_prof_volume_level)msgReq->volume_level)
                {
                    srv_prof_evt_vol_change_struct evt;                    
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);
                    evt.vol_type = SRV_PROF_VOL_RING;
                    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
                }

                g_srv_prof.cur_setting.ring_vol = (srv_prof_volume_level)msgReq->volume_level;

                if(!srv_prof_is_app_playing())
                {
                    mdi_audio_set_volume(MDI_VOLUME_MEDIA,(U8)MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.ring_vol));
                }
            }
            break;

        case MDI_VOLUME_KEY:
            if (msgReq->volume_level < SRV_PROF_VOL_LEVEL_END_OF_ENUM)
            {
                g_srv_prof.cur_setting.keypad_vol = (srv_prof_volume_level)msgReq->volume_level;
                mdi_audio_set_volume(MDI_VOLUME_MEDIA,(U8)MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.keypad_vol));
            }
            break;

        case MDI_VOLUME_SPH:
            if (msgReq->volume_level < MDI_MAX_VOLUME_LEVEL)
            {
                srv_speech_save_mode_volume(msgReq->volume_level);
            }
            break;

        default:
            break;

    }

    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    rsp_msg->result = MMI_TRUE;

    mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*) rsp_msg, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_AT_query_silent_mode
 * DESCRIPTION
 *  Query silent mode setting from AT command
 * PARAMETERS
 *  msg         [IN]
 *  src_mod_id  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_AT_query_silent_mode(void *msg, S32 src_mod_id)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_silent_mode_res_req_struct *rsp_msg;
    srv_prof_ret result ;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,1);

    rsp_msg =
        (mmi_eq_query_silent_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_silent_mode_res_req_struct));

    result = srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE);

    if(result == SRV_PROF_RET_PROFILE_ACTIVATED)
    {
        rsp_msg->mode = MMI_TRUE;
    }
    else
    {
        rsp_msg->mode = MMI_FALSE;
    }

    mmi_frm_send_ilm((oslModuleType)src_mod_id, PRT_MMI_EQ_QUERY_SILENT_MODE_RES_REQ, (oslParaType*) rsp_msg, NULL);

#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_porf_AT_set_silent_mode
 * DESCRIPTION
 *  Set/Reset silent mode from AT command
 * PARAMETERS
 *  msg          [IN]     Set silent mode on/off request message
 *  src_mod_id   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_porf_AT_set_silent_mode(void *msg, S32 src_mod_id)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_silent_mode_req_ind_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;
    srv_prof_ret result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,2);

    msgReq = (mmi_eq_set_silent_mode_req_ind_struct*) msg;
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

    if (msgReq->mode)
    {
        result = srv_prof_activate_profile_by_external_module(SRV_PROF_SILENT_MODE);

        if(result == SRV_PROF_RET_SUCCESS)
        {
            rsp_msg->result = MMI_TRUE;
        }
        else
        {
            rsp_msg->result = MMI_FALSE;
        }
    }
    else
    {
        if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE)> 0 )
        {
            result = srv_prof_deactivate_profile_by_external_module(SRV_PROF_SILENT_MODE);
        }
        else
        {
            result = SRV_PROF_RET_SUCCESS;
        }

        if(result == SRV_PROF_RET_SUCCESS)
        {
            rsp_msg->result = MMI_TRUE;
        }
        else
        {
            rsp_msg->result = MMI_FALSE;
        }
    }

    mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*) rsp_msg, NULL);

#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_AT_query_vib_mode
 * DESCRIPTION
 *  Query vibrator mode setting from AT command
 * PARAMETERS
 *  msg            [IN]
 *  src_mod_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_AT_query_vib_mode(void *msg, S32 src_mod_id)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_query_vibrator_mode_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,3);

    rsp_msg = (mmi_eq_query_vibrator_mode_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_vibrator_mode_res_req_struct));


    if(srv_prof_if_can_vibrate())
    {
        rsp_msg->mode = MMI_TRUE;
    }
    else
    {
        rsp_msg->mode = MMI_FALSE;
    }

    mmi_frm_send_ilm((oslModuleType)src_mod_id, PRT_MMI_EQ_QUERY_VIBRATOR_MODE_RES_REQ, (oslParaType*) rsp_msg, NULL);

#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_AT_set_vib_mode
 * DESCRIPTION
 *  Set vibrator mode from AT command
 * PARAMETERS
 *  msg     [IN]     Set vibration mode on/off request message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_AT_set_vib_mode(void *msg)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_vibrator_mode_req_ind_struct *msgReq;
    srv_prof_alert_type_enum alert_type;
    srv_prof_settings_enum setting = SRV_PROF_SETTINGS_ALERT_TYPE;
    srv_prof_ret result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,4);

    msgReq = (mmi_eq_set_vibrator_mode_req_ind_struct*) msg;

    result = srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE);

    if(result == SRV_PROF_RET_PROFILE_ACTIVATED)
    {
        return;
    }

    alert_type = g_srv_prof.cur_setting.alert_type;

    if (msgReq->mode == 1)
    {
        if ((alert_type == SRV_PROF_ALERT_TYPE_RING))
        {
            alert_type = SRV_PROF_ALERT_TYPE_VIB_AND_RING;
            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE,&alert_type);
            if(g_srv_prof.app_cb != NULL)
            {
                g_srv_prof.app_cb(SRV_PROF_CB_AT_MODIFIED,(void*)&setting,NULL);
            }
        }
    }
    else if (msgReq->mode == 0)
    {
        if ((alert_type == SRV_PROF_ALERT_TYPE_VIB_AND_RING) || 
            (alert_type == SRV_PROF_ALERT_TYPE_VIB_THEN_RING) ||
            (alert_type == SRV_PROF_ALERT_TYPE_VIB_ONLY))
        {
            alert_type = SRV_PROF_ALERT_TYPE_RING;
            srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_ALERT_TYPE,&alert_type);
            if(g_srv_prof.app_cb != NULL)
            {
                g_srv_prof.app_cb(SRV_PROF_CB_AT_MODIFIED,(void*)&setting,NULL);
            }
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_AT_play_ringtone
 * DESCRIPTION
 *  play ring tone request from AT command
 * PARAMETERS
 *  msg     [IN]     play ringtone request message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_AT_play_rington(void *msg, S32 src_mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_ringtone_play_req_ind_struct *msgReq;
    mmi_eq_ringtone_play_res_req_struct *msgRes;

    U16 tone_num;
    U16 ring_num;

    U8 play_style = DEVICE_AUDIO_PLAY_INFINITE;
    mdi_result play_result = MDI_AUDIO_FAIL;

    srv_prof_audio_id audio_id = 0;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_AT_CMD,5);

    msgReq = (mmi_eq_ringtone_play_req_ind_struct*) msg;
    msgRes = (mmi_eq_ringtone_play_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_ringtone_play_res_req_struct));

    if(msgReq->mode == 2)
    {
        mdi_audio_stop_string();
        msgRes->result = MMI_TRUE;
        mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_EQ_RINGTONE_PLAY_RES_REQ, (oslParaType*)msgRes, NULL);
        return;
    }

    tone_num = AUD_ID_PROF_TONE_END - AUD_ID_PROF_TONE_BEGIN - 1;
    ring_num = AUD_ID_PROF_RING_END - AUD_ID_PROF_RING_BEGIN - 1;

    if(msgReq->sound_id > 0 &&  msgReq->sound_id <= tone_num)
    {
        audio_id = AUD_ID_PROF_TONE1 +  msgReq->sound_id - 1 ;
    }
    else if(msgReq->sound_id > tone_num && msgReq->sound_id <= tone_num + ring_num)
    {
        audio_id = AUD_ID_PROF_RING1 + msgReq->sound_id - tone_num - 1;
    }
    else
    {
        msgRes->result = MMI_FALSE;
        mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_EQ_RINGTONE_PLAY_RES_REQ, (oslParaType*)msgRes, NULL);
        return;
    }

    switch(msgReq->style)
    {
        case 0:
        {
            play_style = DEVICE_AUDIO_PLAY_CRESCENDO;
            break;
        }

        case 1:
        {
            play_style = DEVICE_AUDIO_PLAY_INFINITE;
            break;
        }

        case 2:
        {
            play_style = DEVICE_AUDIO_PLAY_ONCE;
            break;
        }

        case 3:
        {
            play_style = DEVICE_AUDIO_PLAY_DESCENDO;
            break;
        }

    }


    audio_data = get_audio(audio_id, &audio_type, &audio_len);

    if(audio_data == NULL)
    {
        msgRes->result = MMI_FALSE;
        mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_EQ_RINGTONE_PLAY_RES_REQ, (oslParaType*)msgRes, NULL);
        return;
    }

    play_result = mdi_audio_play_string_with_vol_path(
                     (void*)audio_data,
                     audio_len,
                     audio_type,
                     play_style,
                     NULL,
                     NULL,
                     msgReq->volume,
                     msgReq->out_path); 

    if(play_result != MDI_AUDIO_SUCCESS)
    {
        msgRes->result = MMI_FALSE;
    }
    else
    {
        msgRes->result = MMI_TRUE;
    }

    mmi_frm_send_ilm((oslModuleType)src_mod_id, MSG_ID_MMI_EQ_RINGTONE_PLAY_RES_REQ, (oslParaType*)msgRes, NULL);

    return;

}



/*****************************************************************************
 * FUNCTION
 *  srv_prof_init_register_event_hdlrs
 * DESCRIPTION
 *  This function is to initialize external melody
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_init_register_event_hdlrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*AT command*/
    SetProtocolEventHandler(srv_prof_AT_set_volume, PRT_MSG_ID_MMI_EQ_VOLUME_CHANGE_IND);
    SetProtocolEventHandler(srv_prof_AT_query_silent_mode, PRT_MMI_EQ_QUERY_SILENT_MODE_REQ_IND);
    SetProtocolEventHandler(srv_porf_AT_set_silent_mode, PRT_MMI_EQ_SET_SILENT_MODE_REQ_IND);
    SetProtocolEventHandler(srv_prof_AT_query_vib_mode, PRT_MMI_EQ_QUERY_VIBRATOR_MODE_REQ_IND);
    SetProtocolEventHandler(srv_prof_AT_set_vib_mode, PRT_MMI_EQ_SET_VIBRATOR_MODE_REQ_IND);
    SetProtocolEventHandler(srv_prof_AT_play_rington, MSG_ID_MMI_EQ_RINGTONE_PLAY_REQ_IND);
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_init_ext_melody
 * DESCRIPTION
 *  This function is to initialize external melody
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
static void srv_prof_init_ext_melody(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 cont;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(ReadValue(NVRAM_SRV_PROF_EXT_MELODY_BITS, &g_srv_prof.ext_melody.valid_bit, DS_DOUBLE, &error) != -1)
    {
        if(g_srv_prof.ext_melody.valid_bit != 0xFFFFFFFFFFFFFFFF)
        {
            for(cont=1 ; cont<=SRV_PROF_EXT_MELODY_NUM; cont++)
            {
                ReadRecord(NVRAM_EF_SRV_PROF_EXT_MELODY_LID,
                           cont,
                           &g_srv_prof.ext_melody.info[cont-1],
                           sizeof(srv_prof_ext_melody_info_struct),
                           &error);

                if(error == NVRAM_READ_FAIL)
                {
                    break;
                }
            }
        }
    }

    if (error == NVRAM_READ_FAIL || g_srv_prof.ext_melody.valid_bit == 0xFFFFFFFFFFFFFFFF)
    {
        memset(&g_srv_prof.ext_melody, 0, sizeof(srv_prof_ext_melody_struct));
        WriteValue(NVRAM_SRV_PROF_EXT_MELODY_BITS, &g_srv_prof.ext_melody.valid_bit, DS_DOUBLE, &error);

        for(cont=1; cont<=SRV_PROF_EXT_MELODY_NUM; cont++)
        {
            WriteRecord(NVRAM_EF_SRV_PROF_EXT_MELODY_LID, cont, &g_srv_prof.ext_melody.info[cont-1], sizeof(srv_prof_ext_melody_info_struct), &error);
        }
    }

}

#endif
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
void srv_prof_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_INIT);

    nvram_ltable_register(logical_data_item_table_userprofile);

    srv_prof_init_register_event_hdlrs();

    /*Init NVRAM*/
    if(ReadValue(NVRAM_PROFILES_ACTIVATED, &g_srv_prof.cur_prof, DS_BYTE, &error) == -1)
    {
        g_srv_prof.cur_prof = 0xFF;
    }

    if(ReadValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error) == -1)
    {
        g_srv_prof.last_prof = 0xFF;
    }

    if(g_srv_prof.cur_prof == 0xFF || g_srv_prof.cur_prof == 0)
    {
        g_srv_prof.cur_prof = SRV_PROF_PROFILE_1;
        g_srv_prof.last_prof = SRV_PROF_PROFILE_2;
        WriteValue(NVRAM_PROFILES_ACTIVATED, &g_srv_prof.cur_prof, DS_BYTE, &error);
        WriteValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error);
    }

    if(g_srv_prof.last_prof == 0xFF || g_srv_prof.last_prof == 0)
    {
        g_srv_prof.last_prof = SRV_PROF_PROFILE_1;
        WriteValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error);        
    }

    /*Activate Profile*/
    srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &g_srv_prof.cur_setting);

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    /*Read Ext Melody*/
    srv_prof_init_ext_melody();
#endif

    /*Config Audio Path*/
    if(srv_earphone_is_plug_in())
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        srv_speech_set_mode_volume();
    }

/* set touch feedback vib strength */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif

    g_srv_prof.is_inited = MMI_TRUE;
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_cb_evt_hdlr
 * DESCRIPTION
 *  This function is to handle callback events from callback manager.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_prof_cb_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
        case EVT_ID_SRV_SHUTDOWN_DEINIT:
        {
            if(IsMyTimerExist(SRV_PROF_STORE_CUR_TIMER))
            {
                StopTimer(SRV_PROF_STORE_CUR_TIMER);
                srv_prof_store_cur_setting_timeout();
            }
            
            if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
            {
                StopTimer(SRV_PROF_STORE_BUF_TIMER);
                srv_prof_store_buf_setting_timeout();
            }
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_reset_to_default
 * DESCRIPTION
 *  This function is for user profiles app to reset a specific profile to default
 *  value.
 * PARAMETERS
 *  srv_prof_internal_profile_enum
 * RETURNS
 *  srv_prof_ret
 *      SRV_PROF_RET_SUCCESS : reset success
 *      SRV_PROF_RET_FAIL : reset fail
 *****************************************************************************/
srv_prof_ret srv_prof_reset_to_default(srv_prof_internal_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_RESET_DEFAULT);
    
    result = mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 
                                  0,//SRV_PROF, 
                                  NVRAM_EF_SRV_PROF_SETTING_LID, 
                                  profile,
                                  1);
    if(result == 0)
    {
        return SRV_PROF_RET_FAIL;
    }

    if(profile == g_srv_prof.cur_prof)
    {
        StopTimer(SRV_PROF_STORE_CUR_TIMER);
        srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &g_srv_prof.cur_setting);
    }
    else if(profile == g_srv_prof.buf_prof)
    {
        StopTimer(SRV_PROF_STORE_BUF_TIMER);
        srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)g_srv_prof.buf_prof, &g_srv_prof.buf_setting);
    }
    
    return SRV_PROF_RET_SUCCESS;

}



/*****************************************************************************
 * FUNCTION
 *  srv_prof_register_app_callback
 * DESCRIPTION
 *  This function is for user profiles app to register callback. Service could
 *  communicate with app for some information with it.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prof_register_app_callback(srv_profiles_notify_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(callback != NULL);
    g_srv_prof.app_cb = callback;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_setting_available
 * DESCRIPTION
 *  This function is to check if specific setting is supported in current service
 * PARAMETERS
 *  setting     [IN]    which setting item
 * RETURNS
 *  MMI_BOOL      MMI_TRUE : supported
 *                MMI_FALSE : not supported
 *****************************************************************************/
MMI_BOOL srv_prof_is_setting_available(srv_prof_settings_enum setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL support = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    switch(setting)
    {
        case SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL:
        {
        #ifndef __MMI_UNIQUE_MEDIA_VOL__
            support = MMI_FALSE;
        #endif
            break;
        }

        case SRV_PROF_SETTINGS_INTELLIGENT_CALL_ALERT:
        {
        #ifndef __MMI_INTELLIGENT_CALL_ALERT__
            support = MMI_FALSE;
        #endif
            break;
        }

        case SRV_PROF_SETTINGS_TOUCH_VOL:
        {
        #ifndef __MMI_TOUCH_FEEDBACK_SUPPORT__
            support = MMI_FALSE;
        #endif
            break;
        }

        case SRV_PROF_SETTINGS_TOUCH_VIB:
        {
        #ifndef __MMI_TOUCH_FEEDBACK_SUPPORT__
            support = MMI_FALSE;
        #endif
            break;
        }

        case SRV_PROF_SETTINGS_POWER_ON_TONE:
        case SRV_PROF_SETTINGS_POWER_OFF_TONE:
        case SRV_PROF_SETTINGS_POWER_ON_OFF_TONE:
        {
        #ifdef __MMI_POWER_ON_OFF_MUTE__
            support = MMI_FALSE;
        #endif
            break;
        }

        case SRV_PROF_SETTINGS_COVER_OPEN_TONE:
        case SRV_PROF_SETTINGS_COVER_CLOSE_TONE:
        {
        #ifndef __MMI_CLAMSHELL__
            support = MMI_FALSE;
        #endif
            break;
        }

#if 0
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_SMS_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_SMS_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_SMS_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_SMS_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MMS_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MMS_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MMS_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MMS_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_EMAIL_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_EMAIL_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_EMAIL_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_EMAIL_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VOICE_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VOICE_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VOICE_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VOICE_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT < 1)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT < 2)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT < 3)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT < 4)
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

        default:
        {
            if(setting >= SRV_PROF_SETTINGS_END_OF_ENUM)
            {
                support = MMI_FALSE;
            }
            break;
        }
    }   


    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_SETTING_AVAILABLE,setting,support);

    return support;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_ring_vol
 * DESCRIPTION
 *  To easily get ring volume
 *  
 * PARAMETERS
 *  void
 * 
 * RETURNS
 *  srv_prof_volume_level
 * 
 *****************************************************************************/
srv_prof_volume_level srv_prof_get_ring_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_RING_VOL,g_srv_prof.cur_setting.ring_vol);
    return MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.ring_vol);
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_media_vol
 * DESCRIPTION
 *  To easily get media volume
 *  
 * PARAMETERS
 *  void
 * 
 * RETURNS
 *  srv_prof_volume_level
 * 
 *****************************************************************************/
srv_prof_volume_level srv_prof_get_media_vol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//kprob: modify trace
#ifdef __MMI_UNIQUE_MEDIA_VOL__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_RING_VOL,g_srv_prof.cur_setting.media_vol);

    return MDI_AUD_VOL_EX_MUTE(g_srv_prof.cur_setting.media_vol);
#else

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_RING_VOL,7);

    return MDI_AUD_VOL_EX_MUTE(7);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_store_cur_setting_timeout
 * DESCRIPTION
 *  To avoid frequently NVRAM accessing, we use a timer to delay the nvram store 
 *  process for current profile
 * PARAMETERS
 * void  
 *
 * RETURNS
 * void
 * 
 *****************************************************************************/
static void srv_prof_store_cur_setting_timeout(void)
{
    srv_prof_write_nvram_from_setting((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &g_srv_prof.cur_setting);
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_store_buf_setting_timeout
 * DESCRIPTION
 *  To avoid frequently NVRAM accessing, we use a timer to delay the nvram store 
 *  process for bufferred profile
 * PARAMETERS
 * void  
 *
 * RETURNS
 * void
 * 
 *****************************************************************************/
static void srv_prof_store_buf_setting_timeout(void)
{
    srv_prof_write_nvram_from_setting((srv_prof_internal_profile_enum)g_srv_prof.buf_prof, &g_srv_prof.buf_setting);
}



/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_current_profile_value
 * DESCRIPTION
 *  This function is to get setting value of current profile. The value will be filled
 *  in the second parameter and the caller shall cast it to the type of the setting value
 * PARAMETERS
 *  setting     [IN]    which setting item
 *  value       [OUT]   returns setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : get value success
 *      SRV_PROF_RET_SETTING_NOT_SUPPORTED : requested setting is not supported in 
 *                                           current profile service
 *****************************************************************************/
srv_prof_ret srv_prof_get_current_profile_value(srv_prof_settings_enum setting,void* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_CUR_VALUE_IN,setting);

    if(!srv_prof_is_setting_available(setting))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);
        return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
    }

    switch(setting)
    {
        /* Ring volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_RING_VOL_LEVEL:
        {
            srv_prof_volume_level* vol = (srv_prof_volume_level*)value;
            *vol = MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.ring_vol);
            break;
        }

        /* Keypad volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_KEYPAD_VOL_LEVEL:
        {
            srv_prof_volume_level* vol = (srv_prof_volume_level*)value;
            *vol = MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.keypad_vol);
            break;
        }

        /* Message volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL:
        {
            *((srv_prof_volume_level*)value) = MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.msg_vol);
            break;
        }

    #ifdef __MMI_UNIQUE_MEDIA_VOL__
        /* Media volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL:
        {
            *((srv_prof_volume_level*)value) = MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.media_vol);
            break;
        }
    #endif

        /* Alert type : srv_prof_alert_type_enum */
        case SRV_PROF_SETTINGS_ALERT_TYPE:
        {
            *((srv_prof_alert_type_enum*)value) = g_srv_prof.cur_setting.alert_type;
            break;
        }

        /* Notification sound : MMI_BOOL */
        case SRV_PROF_SETTINGS_NOTIFICATION_SOUND:
        {
            *((MMI_BOOL*)value) = g_srv_prof.cur_setting.noti_sound;
            break;
        }

        /* Vibrate : MMI_BOOL */
        case SRV_PROF_SETTINGS_VIBRATE:
        {
            *((MMI_BOOL*)value) = g_srv_prof.cur_setting.vibrate;
            break;
        }


        /* Ring type : srv_prof_ring_type_enum */
        case SRV_PROF_SETTINGS_RING_TYPE:
        {
            *((srv_prof_ring_type_enum*)value) = g_srv_prof.cur_setting.ring_type;
            break;
        }

        /* Intelligent call alert : MMI_BOOL */
      #ifdef __MMI_INTELLIGENT_CALL_ALERT__
        case SRV_PROF_SETTINGS_INTELLIGENT_CALL_ALERT:
        {
            *((MMI_BOOL*)value) = g_srv_prof.cur_setting.intelligent_call_alert;
            break;
        }
      #endif

    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
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
      
        /* System alert tone : MMI_BOOL */
        case SRV_PROF_SETTINGS_SYSTEM_ALERT:
        {
            *((MMI_BOOL*)value) = g_srv_prof.cur_setting.system_alert;
            break;
        }

        /* Status LED pattern : srv_prof_led_pattern_enum */
        case SRV_PROF_SETTINGS_STATUS_LED:
        {
            *((srv_prof_led_pattern_enum*)value) = g_srv_prof.cur_setting.led_pattern;
            break;
        }

        /* keypad tone : srv_prof_keypad_tone_type_enum */
        case SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE:
        {
            *((srv_prof_keypad_tone_type_enum*)value) = g_srv_prof.cur_setting.keypad_tone_type;
            break;
        }

      #ifndef __MMI_POWER_ON_OFF_MUTE__
        /* Power on tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_POWER_ON_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.power_on_tone;
            break;
        }

        /* Power off tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_POWER_OFF_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.power_off_tone;
            break;
        }

        /* Power on/off tone switcher : MMI_BOOL */
        case SRV_PROF_SETTINGS_POWER_ON_OFF_TONE:
        {
            *((MMI_BOOL*)value) = g_srv_prof.cur_setting.power_on_off_tone;
            break;
        }

      #endif

      #ifdef __MMI_CLAMSHELL__
        /* Cover on tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_COVER_OPEN_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.cover_open_tone;
            break;
        }

        /* Cover off tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_COVER_CLOSE_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.cover_close_tone;
            break;
        }
      #endif

        /* SMS tone, stands for all message tone when message 
        tones are not split : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_SMS_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
            break;
        }

        /* SMS tone - card2 ,stands for all message tone when 
        message tones are not split : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_SMS_CARD2_TONE:
        {
        #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[1];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* SMS tone - card3 ,stands for all message tone when 
        message tones are not split : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_SMS_CARD3_TONE:
        {
        #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[2];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* SMS tone - card4 ,stands for all message tone when 
        message tones are not split : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_SMS_CARD4_TONE:
        {
        #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[3];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* MMS tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MMS_TONE:
        {
        #if (SRV_PROF_MMS_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[0];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* MMS tone - card2 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MMS_CARD2_TONE:
        {
        #if (SRV_PROF_MMS_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[1];
        #elif (SRV_PROF_MMS_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[1];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* MMS tone - card3 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MMS_CARD3_TONE:
        {
        #if (SRV_PROF_MMS_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[2];
        #elif (SRV_PROF_MMS_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[2];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* MMS tone - card4 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MMS_CARD4_TONE:
        {
        #if (SRV_PROF_MMS_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[3];
        #elif (SRV_PROF_MMS_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mms_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[3];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Email tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_EMAIL_TONE:
        {
        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[0];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Email tone - card2 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_EMAIL_CARD2_TONE:
        {
        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[1];
        #elif (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[1];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Email tone - card3 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_EMAIL_CARD3_TONE:
        {
        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[2];
        #elif (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[2];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Email tone - card4 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_EMAIL_CARD4_TONE:
        {
        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[3];
        #elif (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.email_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[3];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Voice tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VOICE_TONE:
        {
        #if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[0];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif        
            break;
        }

        /* Voice tone - card2 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VOICE_CARD2_TONE:
        {
        #if (SRV_PROF_VOICE_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[1];
        #elif (SRV_PROF_VOICE_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[1];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }
        
        /* Voice tone - card3 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VOICE_CARD3_TONE:
        {
        #if (SRV_PROF_VOICE_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[2];
        #elif (SRV_PROF_VOICE_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[2];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Voice tone - card4 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VOICE_CARD4_TONE:
        {
        #if (SRV_PROF_VOICE_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[3];
        #elif (SRV_PROF_VOICE_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.voice_tone[0];
        #elif (SRV_PROF_SMS_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[3];
        #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.sms_tone[0];
        #endif
            break;
        }

        /* Icoming call tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MT_CALL_TONE:
        {
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
            break;
        }

        /* Icoming call tone - card2 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE:
        {
          #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[1];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
            break;
        }

        /* Icoming call tone - card3 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE:
        {
          #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[2];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
            break;
        }

        /* Icoming call tone - card4 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE:
        {
          #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[3];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
            break;
        }

        /* Icoming call tone - video call : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VT_CALL_TONE:
        {
          #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[0];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
            break;
        }

        /* Icoming call tone - video call - card2 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE:
        {
          #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[1];
          #elif (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[0];
          #elif (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[1];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
          break;
        }

        /* Icoming call tone - video call - card3 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE:
        {
          #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[2];
          #elif (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[0];
          #elif (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[2];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
          break;
        }

        /* Icoming call tone - video call - card4 : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE:
        {
          #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[3];
          #elif (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.vt_call_tone[0];
          #elif (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[3];
          #else
            *((srv_prof_audio_id*)value) = g_srv_prof.cur_setting.mt_call_tone[0];
          #endif
          break;
        }
        default:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);
            return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
        }
    }

//can not cast a non U16 pointer to U16 pointer then get value, if it is not aliged well, it will fatal
//    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_CUR_VALUE_OUT,*((U16*)value));

    return SRV_PROF_RET_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_profiles_get_profile_values
 * DESCRIPTION
 *  This function is to get setting values of specific profile. Service will fil
 *  the values into the 2nd parameter.
 * PARAMETERS
 *  profile     [IN]     which profile
 *  setting     [OUT]    retrieve values
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : get value success
 *      SRV_PROF_RET_FAIL : get value fail
 *****************************************************************************/
srv_prof_ret srv_prof_get_profile_values(srv_prof_internal_profile_enum profile,
                                         srv_prof_setting_struct* setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(profile == g_srv_prof.cur_prof)
    {
        memcpy(setting, &g_srv_prof.cur_setting, sizeof(srv_prof_setting_struct));
        return SRV_PROF_RET_SUCCESS;
    }

    if(profile == g_srv_prof.buf_prof)
    {
        memcpy(setting, &g_srv_prof.buf_setting, sizeof(srv_prof_setting_struct));
        return SRV_PROF_RET_SUCCESS;
    }

    if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
    {
        StopTimer(SRV_PROF_STORE_BUF_TIMER);
        srv_prof_store_buf_setting_timeout();
    }

    srv_prof_read_nvram_to_setting(profile, &g_srv_prof.buf_setting);

    memcpy(setting, &g_srv_prof.buf_setting, sizeof(srv_prof_setting_struct));

    g_srv_prof.buf_prof = profile;

    return SRV_PROF_RET_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_cur_value_switched_hdlr
 * DESCRIPTION
 *  This function is to apply new value to system when current profile values changed
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_cur_value_switched_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* set touch feedback vib strength */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_current_profile_value
 * DESCRIPTION
 *  This function is to set setting value of current profile.
 * PARAMETERS
 *  setting     [IN]    which setting item
 *  value       [IN]    the setting value, type of the setting itme is commented 
 *                      in srv_prof_settings_enum
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : get value success
 *      SRV_PROF_RET_SETTING_NOT_SUPPORTED : current profile setting doe not allow to set
 *      SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
srv_prof_ret srv_prof_set_current_profile_value(srv_prof_settings_enum setting,void* value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_SET_CUR_VALUE_IN,setting,g_srv_prof.cur_prof);

    if(SRV_PROF_SUPPORT_SILENT_MODE == TRUE && SRV_PROF_SILENT_MODE_NUM == g_srv_prof.cur_prof)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);    
        return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
    }

    if(!srv_prof_is_setting_available(setting))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);    
        return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
    }

    switch(setting)
    {
        /* Ring volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_RING_VOL_LEVEL:
        {
            if(g_srv_prof.cur_setting.ring_vol != *((srv_prof_volume_level*)value))
            {
                srv_prof_evt_vol_change_struct evt;                    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);
                evt.vol_type = SRV_PROF_VOL_RING;
                MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
            }
            
            g_srv_prof.cur_setting.ring_vol = *((srv_prof_volume_level*)value);
            break;
        }

        /* Keypad volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_KEYPAD_VOL_LEVEL:
        {
            if(g_srv_prof.cur_setting.keypad_vol != *((srv_prof_volume_level*)value))
            {
                srv_prof_evt_vol_change_struct evt;                    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);
                evt.vol_type = SRV_PROF_VOL_KEY;
                MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
            }

            g_srv_prof.cur_setting.keypad_vol = *((srv_prof_volume_level*)value);
            break;
        }

        /* Message volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_MESSAGE_VOL_LEVEL:
        {
            if(g_srv_prof.cur_setting.msg_vol != *((srv_prof_volume_level*)value))
            {
                srv_prof_evt_vol_change_struct evt;                    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);
                evt.vol_type = SRV_PROF_VOL_MESSAGE;
                MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
            }

            g_srv_prof.cur_setting.msg_vol = *((srv_prof_volume_level*)value);
            break;
        }

        /* Media volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL:
        {
        #ifdef __MMI_UNIQUE_MEDIA_VOL__
            if(g_srv_prof.cur_setting.media_vol != *((srv_prof_volume_level*)value))
            {
                srv_prof_evt_vol_change_struct evt;                    
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);
                evt.vol_type = SRV_PROF_VOL_MEDIA;
                MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
            }

            g_srv_prof.cur_setting.media_vol = *((srv_prof_volume_level*)value);
        #endif
            break;
        }

        /* Alert Type : srv_prof_alert_type_enum */
        case SRV_PROF_SETTINGS_ALERT_TYPE:
        {
            g_srv_prof.cur_setting.alert_type = *((srv_prof_alert_type_enum*)value);
            break;
        }

        /* Notification sound : MMI_BOOL */
        case SRV_PROF_SETTINGS_NOTIFICATION_SOUND:
        {
            g_srv_prof.cur_setting.noti_sound = *((MMI_BOOL*)value);
            break;
        }

        /* Vibrate : MMI_BOOL */
        case SRV_PROF_SETTINGS_VIBRATE:
        {
            g_srv_prof.cur_setting.vibrate = *((MMI_BOOL*)value);
            break;
        }

        /* Ring type : srv_prof_ring_type_enum */
        case SRV_PROF_SETTINGS_RING_TYPE:
        {
            g_srv_prof.cur_setting.ring_type = *((srv_prof_ring_type_enum*)value);
            break;
        }

        /* Intelligent call alert : MMI_BOOL */
        case SRV_PROF_SETTINGS_INTELLIGENT_CALL_ALERT:
        {
        #ifdef __MMI_INTELLIGENT_CALL_ALERT__
            g_srv_prof.cur_setting.intelligent_call_alert = *((MMI_BOOL*)value) ;
        #endif
            break;
        }

        /* Touch feedback volume level : srv_prof_volume_level */
        case SRV_PROF_SETTINGS_TOUCH_VOL:
        {
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
        #endif
            break;
        }

        /* Touch feedback vibration level : srv_prof_vib_level */
        case SRV_PROF_SETTINGS_TOUCH_VIB:
        {
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            break;
        }

        /* System alert tone : MMI_BOOL */
        case SRV_PROF_SETTINGS_SYSTEM_ALERT:
        {
             g_srv_prof.cur_setting.system_alert = *((MMI_BOOL*)value);
            break;
        }

        /* Status LED pattern : srv_prof_led_pattern_enum */
        case SRV_PROF_SETTINGS_STATUS_LED:
        {
            g_srv_prof.cur_setting.led_pattern = *((srv_prof_led_pattern_enum*)value);
            break;
        }

        /* keypad tone : srv_prof_keypad_tone_type_enum */
        case SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE:
        {
            g_srv_prof.cur_setting.keypad_tone_type = *((srv_prof_keypad_tone_type_enum*)value);
            break;
        }

    #ifndef __MMI_POWER_ON_OFF_MUTE__
        /* Power on tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_POWER_ON_TONE:
        {
            g_srv_prof.cur_setting.power_on_tone = *((srv_prof_audio_id*)value);
            break;
        }

        /* Power off tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_POWER_OFF_TONE:
        {
            g_srv_prof.cur_setting.power_off_tone = *((srv_prof_audio_id*)value);
            break;
        }

        /* Power on/off tone switcher : MMI_BOOL */
        case SRV_PROF_SETTINGS_POWER_ON_OFF_TONE:
        {
            g_srv_prof.cur_setting.power_on_off_tone = *((MMI_BOOL*)value);
            break;
        }
    #endif

    #ifdef __MMI_CLAMSHELL__
        /* Cover on tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_COVER_OPEN_TONE:
        {
            g_srv_prof.cur_setting.cover_open_tone = *((srv_prof_audio_id*)value);
            break;
        }

        /* Cover off tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_COVER_CLOSE_TONE:
        {
            g_srv_prof.cur_setting.cover_close_tone = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* SMS tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_SMS_TONE:
        {
            g_srv_prof.cur_setting.sms_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }

        /* SMS tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_SMS_CARD2_TONE:
        {
            g_srv_prof.cur_setting.sms_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

    #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_SMS_CARD3_TONE:
        {
            g_srv_prof.cur_setting.sms_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

    #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_SMS_CARD3_TONE:
        {
            g_srv_prof.cur_setting.sms_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* MMS tone : srv_prof_audio_id */
    #if (SRV_PROF_MMS_TONE_AMOUNT > 0)
        case SRV_PROF_SETTINGS_MMS_TONE:
        {
            g_srv_prof.cur_setting.mms_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* MMS tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_MMS_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_MMS_CARD2_TONE:
        {
            g_srv_prof.cur_setting.mms_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* MMS tone - card3 : srv_prof_audio_id */
    #if (SRV_PROF_MMS_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_MMS_CARD3_TONE:
        {
            g_srv_prof.cur_setting.mms_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* MMS tone - card4 : srv_prof_audio_id */
    #if (SRV_PROF_MMS_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_MMS_CARD4_TONE:
        {
            g_srv_prof.cur_setting.mms_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Email tone : srv_prof_audio_id */
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        case SRV_PROF_SETTINGS_EMAIL_TONE:
        {
            g_srv_prof.cur_setting.email_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Email tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_EMAIL_CARD2_TONE:
        {
            g_srv_prof.cur_setting.email_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Email tone - card3 : srv_prof_audio_id */
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_EMAIL_CARD3_TONE:
        {
            g_srv_prof.cur_setting.email_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Email tone - card4 : srv_prof_audio_id */
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_EMAIL_CARD4_TONE:
        {
            g_srv_prof.cur_setting.email_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Voice tone : srv_prof_audio_id */
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
        case SRV_PROF_SETTINGS_VOICE_TONE:
        {
            g_srv_prof.cur_setting.voice_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Voice tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_VOICE_CARD2_TONE:
        {
            g_srv_prof.cur_setting.voice_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Voice tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_VOICE_CARD3_TONE:
        {
            g_srv_prof.cur_setting.voice_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Voice tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_VOICE_CARD4_TONE:
        {
            g_srv_prof.cur_setting.voice_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone : srv_prof_audio_id */
        case SRV_PROF_SETTINGS_MT_CALL_TONE:
        {
            g_srv_prof.cur_setting.mt_call_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }

        /* Icoming call tone - card2 : srv_prof_audio_id */
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE:
        {
            g_srv_prof.cur_setting.mt_call_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - card3 : srv_prof_audio_id */
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE:
        {
            g_srv_prof.cur_setting.mt_call_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - card4 : srv_prof_audio_id */
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE:
        {
            g_srv_prof.cur_setting.mt_call_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - video call : srv_prof_audio_id */
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
        case SRV_PROF_SETTINGS_VT_CALL_TONE:
        {
            g_srv_prof.cur_setting.vt_call_tone[0] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - video call : srv_prof_audio_id */
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1)
        case SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE:
        {
            g_srv_prof.cur_setting.vt_call_tone[1] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - video call : srv_prof_audio_id */
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 2)
        case SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE:
        {
            g_srv_prof.cur_setting.vt_call_tone[2] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif

        /* Icoming call tone - video call : srv_prof_audio_id */
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 3)
        case SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE:
        {
            g_srv_prof.cur_setting.vt_call_tone[3] = *((srv_prof_audio_id*)value);
            break;
        }
    #endif
        default:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);
            return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
        }
    }

    StartTimer(SRV_PROF_STORE_CUR_TIMER, 2000, srv_prof_store_cur_setting_timeout);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_SET_CUR_VALUE_OUT,*((U16*)value));

    return SRV_PROF_RET_SUCCESS;
}


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
srv_prof_ret srv_prof_set_profile_values(srv_prof_internal_profile_enum profile,
                                          srv_prof_setting_struct* setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL done = MMI_FALSE;
    srv_prof_evt_vol_change_struct evt;                    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_VOL_CHANGED);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(profile == g_srv_prof.cur_prof)
    {
        if(g_srv_prof.cur_setting.ring_vol != setting->ring_vol)
        {
            evt.vol_type = SRV_PROF_VOL_RING;
            MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
        }

        if(g_srv_prof.cur_setting.keypad_vol != setting->keypad_vol)
        {
            evt.vol_type = SRV_PROF_VOL_KEY;
            MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
        }

        if(g_srv_prof.cur_setting.msg_vol != setting->msg_vol)
        {
            evt.vol_type = SRV_PROF_VOL_MESSAGE;
            MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
        }

    #ifdef __MMI_UNIQUE_MEDIA_VOL__
        if(g_srv_prof.cur_setting.media_vol != setting->media_vol)
        {
            evt.vol_type = SRV_PROF_VOL_MEDIA;
            MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
        }
    #endif

        memcpy(&g_srv_prof.cur_setting, setting, sizeof(srv_prof_setting_struct));
        StartTimer(SRV_PROF_STORE_CUR_TIMER, 2000, srv_prof_store_cur_setting_timeout);
        done = MMI_TRUE;
        srv_prof_cur_value_switched_hdlr();
    }

    if(profile == g_srv_prof.buf_prof)
    {
        memcpy(&g_srv_prof.buf_setting, setting, sizeof(srv_prof_setting_struct));
        StartTimer(SRV_PROF_STORE_BUF_TIMER, 2000, srv_prof_store_buf_setting_timeout);
        done = MMI_TRUE;
    } 

    if(!done)
    {
        srv_prof_write_nvram_from_setting(profile, setting);
    }

    return SRV_PROF_RET_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_check_midi_size_limit
 * DESCRIPTION
 *  check if it is midi file and if the file size is within the limit
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 * srv_prof_ret
 *  SRV_PROF_RET_SUCCESS : check ok
 *  SRV_PROF_RET_MIDI_FILE_TOO_LARGE : midi file too large
 *  SRV_PROF_RET_MIDI_CHECK_FILE_FAIL : can not check midi file size 
 *****************************************************************************/

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__

static srv_prof_ret srv_prof_check_midi_size_limit(WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_file_type_enum file_ext;
    U8 mdi_type = MDI_FORMAT_SMF;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    file_ext =  srv_fmgr_types_find_type_by_filename_str(path);

    if( file_ext == FMGR_TYPE_IMY || file_ext == FMGR_TYPE_MIDI || file_ext == FMGR_TYPE_MID)
    {
        FS_HANDLE file_hd;
        U32 file_size = 0;

        file_hd = FS_Open(path, FS_READ_ONLY);
        
        if(file_hd)
        {
            FS_GetFileSize(file_hd, &file_size);
            FS_Close(file_hd);
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_CHECK_MIDI_SIZE,1);
            return SRV_PROF_RET_MIDI_CHECK_FILE_FAIL;
        }

        if(file_ext == FMGR_TYPE_IMY)
        {
            mdi_type = MDI_FORMAT_IMELODY;
        }

        if (file_size > mdi_audio_get_size_limit(mdi_type) )
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_CHECK_MIDI_SIZE,2);
            return SRV_PROF_RET_MIDI_FILE_TOO_LARGE;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_CHECK_MIDI_SIZE,0);

    return SRV_PROF_RET_SUCCESS;
    
}
#endif

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
srv_prof_ret srv_prof_set_file_path_to_ext_melody(U8 slot,WCHAR* path)
{
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    S32 str_len = 0;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_SET_EXT_MELODY,slot);

    /* Check if it is midi/imy file and if the size is too large */
    result = srv_prof_check_midi_size_limit((WCHAR*)path);
    if( result != SRV_PROF_RET_SUCCESS)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,result);
        return result;
    }

    /* Check if the file path length is too long */
    str_len = mmi_ucs2strlen((CHAR*)path);
    if (str_len > SRV_FMGR_PATH_MAX_LEN )
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_PATH_TOO_LONG);
        return SRV_PROF_RET_PATH_TOO_LONG;
    }

    if(SRV_PROF_BIT_TEST(g_srv_prof.ext_melody.valid_bit,slot) != 0)
    {
        result = SRV_PROF_RET_EXT_MELODY_REPLACED;
        memset((CHAR*)g_srv_prof.ext_melody.info[slot].filefullpath, 0, sizeof(g_srv_prof.ext_melody.info[slot].filefullpath));
    }

    mmi_ucs2cpy((CHAR*)g_srv_prof.ext_melody.info[slot].filefullpath, (CHAR*) path);

    SRV_PROF_BIT_ON(g_srv_prof.ext_melody.valid_bit,slot);

    WriteValue(NVRAM_SRV_PROF_EXT_MELODY_BITS, &g_srv_prof.ext_melody.valid_bit, DS_DOUBLE, &error);
    WriteRecord(NVRAM_EF_SRV_PROF_EXT_MELODY_LID, slot+1, &g_srv_prof.ext_melody.info[slot], sizeof(srv_prof_ext_melody_info_struct), &error);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,result);
    return result;

#else

    return SRV_PROF_RET_FAIL;

#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_set_current_profile_tone_with_file_path
 * DESCRIPTION
 *  This function is to set current profiles' tone with file path. Only works for tone setting.
 *  If current profile app's design does not allow to set a specific tone with file path, then
 *  then return value would be SRV_PROF_RET_SETTING_NOT_SUPPORTED.
 * PARAMETERS
 *  setting     [IN]    which setting item
 *  path        [IN]    file path to set
 *
 * RETURNS
 * srv_prof_ret    
 *  SRV_PROF_RET_SUCCESS : check ok
 *  SRV_PROF_RET_MIDI_FILE_TOO_LARGE : midi file too large
 *  SRV_PROF_RET_MIDI_CHECK_FILE_FAIL : can not check midi file size
 *  SRV_PROF_RET_STR_TOO_LONG : file path string too long
 *  SRV_PROF_RET_EXT_MELODY_REPLACED : the old file path is replaced
 *  SRV_PROF_RET_SETTING_NOT_SUPPORTED : current profile setting doe not allow to set
 *  SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
srv_prof_ret srv_prof_set_current_profile_tone_with_file_path(srv_prof_settings_enum setting,WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 slot = 0;
    srv_prof_audio_id aud_id;
    srv_prof_ret result = SRV_PROF_RET_FAIL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_SET_CUR_TONE_EXT_MELODY,setting);

    if(SRV_PROF_SUPPORT_SILENT_MODE == TRUE && SRV_PROF_SILENT_MODE_NUM == g_srv_prof.cur_prof)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);
        return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
    }

    if(g_srv_prof.app_cb != NULL)
    {
        result = g_srv_prof.app_cb(SRV_PROF_CB_SLOT_QUERY,(void*)&setting,(void*)&slot);
    }

    if(result != SRV_PROF_RET_SUCCESS || slot >= SRV_PROF_EXT_MELODY_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_SETTING_NOT_SUPPORTED);
        return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
    }

    result = srv_prof_set_file_path_to_ext_melody(slot,path);

    /* file set to external melody ok */
    if(result == SRV_PROF_RET_SUCCESS || result == SRV_PROF_RET_EXT_MELODY_REPLACED)
    {
        aud_id = AUD_ID_PROF_EXT1 + slot;
        srv_prof_set_current_profile_value(setting, (void*)(&aud_id));
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_mute_playing_sounds
 * DESCRIPTION
 *  When silnet mode is activated, need to check and mute current playnig sounds
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_mute_playing_sounds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    /*mute keypad sound*/
    mdi_audio_set_mute(MDI_VOLUME_KEY, MMI_TRUE);

    if(!srv_prof_is_app_playing())
    {
        /*no player is playing media, mute media*/
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);        
    }

}


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
srv_prof_ret srv_prof_activate_profile(srv_prof_internal_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_evt_prof_switch_struct evt;
    S16 error;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_ACTIVATE_PROFILE,profile);

    if(IsMyTimerExist(SRV_PROF_STORE_CUR_TIMER))
    {
        StopTimer(SRV_PROF_STORE_CUR_TIMER);
        srv_prof_store_cur_setting_timeout();
    }

    if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
    {
        StopTimer(SRV_PROF_STORE_BUF_TIMER);
        srv_prof_store_buf_setting_timeout();
    }

    srv_prof_read_nvram_to_setting(profile, &g_srv_prof.cur_setting);

    if(profile == SRV_PROF_SILENT_MODE_NUM)
    {
        srv_prof_mute_playing_sounds();

        if(g_srv_prof.cur_prof == profile)
        {
            return SRV_PROF_RET_SUCCESS;    
        }        
        g_srv_prof.last_prof = g_srv_prof.cur_prof;
    }
    else
    {
        g_srv_prof.last_prof = SRV_PROF_PROFILE_NULL;
    }

    g_srv_prof.cur_prof = profile;

    /* if buf eaquals cur, need to reset buf or when user tries to set cur, which is also buf, 
       it will only set to cur, but not buf*/
    if(g_srv_prof.cur_prof == g_srv_prof.buf_prof)
    {
        g_srv_prof.buf_prof = 0;
    }

    if(g_srv_prof.app_cb != NULL)
    {
        g_srv_prof.app_cb(SRV_PROF_CB_PROFILE_SWITCHED,(void*)&g_srv_prof.cur_prof,NULL);
    }

    WriteValue(NVRAM_PROFILES_ACTIVATED, &g_srv_prof.cur_prof, DS_BYTE, &error);
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error);

    /* post profile switched event */
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_SRV_PROF_PROFILE_SWITCHED);
    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);

    srv_prof_cur_value_switched_hdlr();

    return SRV_PROF_RET_SUCCESS;

}


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
 *  profile     [IN]    profile to activate
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : activate profile success
 *      SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *      SRV_PROF_RET_FAIL : other errors (ex: profile can not be actiaved in current status)
 *****************************************************************************/
srv_prof_ret srv_prof_activate_profile_by_external_module(srv_prof_external_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 new_profile = SRV_PROF_SILENT_MODE_NUM;
    srv_prof_evt_prof_switch_struct evt;
    srv_prof_ret result = SRV_PROF_RET_SUCCESS; 
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_ACTIVATE_PROFILE_EXTERNAL,profile);

    if(profile >= SRV_PROF_MODE_END_OF_ENUM)
    {
        result = SRV_PROF_RET_FAIL;
    }

    if(profile == SRV_PROF_HEADSET_MODE || profile == SRV_PROF_BLUETOOTH_MODE)
    {
        result = SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
    }

    if(SRV_PROF_SUPPORT_MEETING_MODE != TRUE && profile == SRV_PROF_MEETING_MODE)
    {
        result = SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
    }

    if(SRV_PROF_SUPPORT_SILENT_MODE != TRUE && profile == SRV_PROF_SILENT_MODE)
    {
        result = SRV_PROF_RET_PROFILE_NOT_SUPPORTED;    
    }

    if(result != SRV_PROF_RET_SUCCESS)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,result);
        return result;
    }

    if(profile == SRV_PROF_SILENT_MODE)
    {
        new_profile = SRV_PROF_SILENT_MODE_NUM;
    }
    else if(profile == SRV_PROF_MEETING_MODE)
    {
        new_profile = SRV_PROF_MEETING_MODE_NUM;
    }
    else
    {
        ASSERT(0);
    }

    if(new_profile == g_srv_prof.cur_prof)
    {
        return SRV_PROF_RET_SUCCESS;
    }

    if(IsMyTimerExist(SRV_PROF_STORE_CUR_TIMER))
    {
        StopTimer(SRV_PROF_STORE_CUR_TIMER);
        srv_prof_store_cur_setting_timeout();
    }

    if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
    {
        StopTimer(SRV_PROF_STORE_BUF_TIMER);
        srv_prof_store_buf_setting_timeout();
    }

    srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)new_profile, &g_srv_prof.cur_setting);

    if(new_profile == SRV_PROF_SILENT_MODE_NUM)
    {
        g_srv_prof.last_prof = g_srv_prof.cur_prof;
        srv_prof_mute_playing_sounds();
    }
    else
    {
        g_srv_prof.last_prof = SRV_PROF_PROFILE_NULL;
    }
    
    g_srv_prof.cur_prof = new_profile;

    if(g_srv_prof.app_cb != NULL)
    {
        g_srv_prof.app_cb(SRV_PROF_CB_PROFILE_SWITCHED,(void*)&g_srv_prof.cur_prof,NULL);
    }

    WriteValue(NVRAM_PROFILES_ACTIVATED, &g_srv_prof.cur_prof, DS_BYTE, &error);
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error);

    /* post profile switched event */
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_SRV_PROF_PROFILE_SWITCHED);
    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);

    srv_prof_cur_value_switched_hdlr();

    return SRV_PROF_RET_SUCCESS;

}


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
 *  profile     [IN]    profile to deactivate
 * RETURNS
 *  srv_prof_ret    
 *      SRV_PROF_RET_SUCCESS : deactivate profile success
 *      SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *      SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
srv_prof_ret srv_prof_deactivate_profile_by_external_module(srv_prof_external_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cur_profile = SRV_PROF_SILENT_MODE_NUM;
    srv_prof_evt_prof_switch_struct evt;
    S16 error;
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_DEACTIVATE_PROFILE_EXTERNAL,profile);

    /* currently, only silent profile supports deactivation */
    if(profile != SRV_PROF_SILENT_MODE)
    {
        result = SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
    }
    else
    {
        cur_profile = SRV_PROF_SILENT_MODE_NUM;
    }

    /* must be current profile */
    if(cur_profile != g_srv_prof.cur_prof)
    {
        result = SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
    }

    if(result != SRV_PROF_RET_SUCCESS)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,result);
        return result;
    }

    if(IsMyTimerExist(SRV_PROF_STORE_CUR_TIMER))
    {
        StopTimer(SRV_PROF_STORE_CUR_TIMER);
        srv_prof_store_cur_setting_timeout();
    }

    if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
    {
        StopTimer(SRV_PROF_STORE_BUF_TIMER);
        srv_prof_store_buf_setting_timeout();
    }

    g_srv_prof.cur_prof = g_srv_prof.last_prof;
    g_srv_prof.last_prof = SRV_PROF_PROFILE_NULL;

    srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)g_srv_prof.cur_prof, &g_srv_prof.cur_setting);

    WriteValue(NVRAM_PROFILES_ACTIVATED, &g_srv_prof.cur_prof, DS_BYTE, &error);
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &g_srv_prof.last_prof, DS_BYTE, &error);

    if(g_srv_prof.app_cb != NULL)
    {
        g_srv_prof.app_cb(SRV_PROF_CB_PROFILE_SWITCHED,(void*)&g_srv_prof.cur_prof,NULL);
    }

    /* post profile switched event */
    MMI_FRM_INIT_EVENT(&evt,EVT_ID_SRV_PROF_PROFILE_SWITCHED);
    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);

    srv_prof_cur_value_switched_hdlr();

    return SRV_PROF_RET_SUCCESS;

}


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
srv_prof_internal_profile_enum srv_prof_get_activated_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_GET_ACTIVE_PROFILE,g_srv_prof.cur_prof);

    return (srv_prof_internal_profile_enum)g_srv_prof.cur_prof;
}



/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_num_of_profiles
 * DESCRIPTION
 *  This function is for other modules to get total number of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  U8      total profile numbers
 *****************************************************************************/
U8 srv_prof_get_num_of_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return SRV_PROF_PROFILES_TOTAL_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_num_of_audio_resource
 * DESCRIPTION
 *  This function is to get number of service generated audio resources of
 *  a specific resource type
 *  
 * PARAMETERS
 *  srv_prof_audio_resource_type_enum  [IN]    res_type
 *
 * RETURNS
 *  number of audio resource
 *****************************************************************************/
U16 srv_prof_get_num_of_audio_resource(srv_prof_audio_resource_type_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(res_type)
    {
        case SRV_PROF_AUDIO_RES_TONE:
        {
            num = AUD_ID_PROF_TONE_END - AUD_ID_PROF_TONE_BEGIN - 1;
            break;
        }

        case SRV_PROF_AUDIO_RES_RING:
        {
            num = AUD_ID_PROF_RING_END - AUD_ID_PROF_RING_BEGIN - 1;
            break;
        }

        case SRV_PROF_AUDIO_RES_FILE:
        {
            num = AUD_ID_PROF_EXT_END - AUD_ID_PROF_EXT_BEGIN - 1;
        }

        default:
            break;
    }

    return num;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_audio_id_from_audio_resourece
 * DESCRIPTION
 *  This function is for other modules to get audio id (framework audio)
 *  by input the resource type and index of this type starting from 0.
 * PARAMETERS
 *  srv_prof_audio_resource_type_enum     [IN]    res_type
 *  U16                                   [IN]    index
 * RETURNS
 *  U16     framework audio id
 *****************************************************************************/
U16 srv_prof_get_audio_id_from_audio_resourece(srv_prof_audio_resource_type_enum res_type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(res_type)
    {
        case SRV_PROF_AUDIO_RES_TONE:
        {
            value = AUD_ID_PROF_TONE1 + index;
            break;
        }

        case SRV_PROF_AUDIO_RES_RING:
        {
            value = AUD_ID_PROF_RING1 + index;            
            break;
        }

        case SRV_PROF_AUDIO_RES_FILE:
        {
            value = AUD_ID_PROF_EXT1 + index;
            break;
        }

        default:
            break;
    }

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_resource_info_from_audio_id
 * DESCRIPTION
 *  This function is for other modules to get resource info (resource tyep / index)
 *  by input the audio id (framework audio)
 * PARAMETERS
 *  srv_prof_audio_resource_type_enum     [IN]    res_type
 *  srv_prof_audio_id                     [OUT]   index
 * RETURNS
 *  srv_prof_audio_resource_type_enu
 *****************************************************************************/
srv_prof_audio_resource_type_enum srv_prof_get_audio_info_from_audio_resourece(srv_prof_audio_id audio_id, U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_audio_resource_type_enum type = SRV_PROF_AUDIO_RES_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(audio_id > AUD_ID_PROF_TONE_BEGIN && audio_id < AUD_ID_PROF_TONE_END)
    {
        *index = audio_id - AUD_ID_PROF_TONE1;
        type = SRV_PROF_AUDIO_RES_TONE;
    }

    if(audio_id > AUD_ID_PROF_RING_BEGIN && audio_id < AUD_ID_PROF_RING_END)
    {
        *index = audio_id - AUD_ID_PROF_RING1;
        type = SRV_PROF_AUDIO_RES_RING;
    }

    if(audio_id > AUD_ID_PROF_EXT_BEGIN && audio_id < AUD_ID_PROF_EXT_END)
    {
        *index = audio_id - AUD_ID_PROF_EXT1;
        type = SRV_PROF_AUDIO_RES_FILE;
    }

    return type;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_string_id_from_audio_resourece
 * DESCRIPTION
 *  This function is for other modules to get string id (framework string)
 *  by input the resource type and index of this type starting from 0.
 * PARAMETERS
 *  srv_prof_audio_resource_type_enum     [IN]    res_type
 *  U16                                   [IN]    index
 * RETURNS
 *  U16     framework string id
 *****************************************************************************/
U16 srv_prof_get_string_id_from_audio_resourece(srv_prof_audio_resource_type_enum res_type, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(res_type)
    {
        case SRV_PROF_AUDIO_RES_TONE:
        {
            value = STR_ID_SRV_PROF_TONE_1 + index;
            break;
        }

        case SRV_PROF_AUDIO_RES_RING:
        {
            value = STR_ID_SRV_PROF_RING_1 + index;            
            break;
        }

        default:
            break;
    }

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_string_id_from_srv_audio_id
 * DESCRIPTION
 *  This function is for other modules to get string id (framework string)
 *  by input a service audio id 
 * PARAMETERS
 *  srv_audio_id     [IN]    service audio id
 * RETURNS
 *  U16			framework string id
 *****************************************************************************/
U16 srv_prof_get_string_id_from_srv_audio_id(srv_prof_audio_id srv_audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 value = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(srv_audio_id > AUD_ID_PROF_TONE_BEGIN && srv_audio_id < AUD_ID_PROF_TONE_END)
    {
        value = STR_ID_SRV_PROF_TONE_1 + (srv_audio_id - AUD_ID_PROF_TONE_BEGIN - 1);
    }

    if(srv_audio_id > AUD_ID_PROF_RING_BEGIN && srv_audio_id < AUD_ID_PROF_RING_END)
    {
        value = STR_ID_SRV_PROF_RING_1 + (srv_audio_id - AUD_ID_PROF_RING_BEGIN - 1);
    }

    return value;
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_special_key_tone_audio_id
 * DESCRIPTION
 *  This function is for modules to get audio resource id of digit tone by 
 *  inputs the keypad tone type and the index of keypad. If the keypad tone
 *  type is not of SRV_PROF_KEYPAD_NUM_1 ~ 5, SRV_PROF_KEYPAD_NUM_1 will be 
 *  applied.
 * PARAMETERS
 *  keypad_tone_type     [IN]    keypad tone type of digit tone
 *  index                [IN]    keypad type
 * RETURNS
 *  U16			audio resource id
 *****************************************************************************/
U16 srv_prof_get_special_key_tone_audio_id(srv_prof_keypad_tone_type_enum keypad_tone_type, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) || defined(DIGIT_TONE_SUPPORT)

    if(keypad_tone_type > SRV_PROF_KEYPAD_NUM_5 || keypad_tone_type < SRV_PROF_KEYPAD_NUM_1)
    {
        keypad_tone_type = SRV_PROF_KEYPAD_NUM_1;
    }
    return AUD_ID_PROF_NUM1_0 + 13* (keypad_tone_type - SRV_PROF_KEYPAD_NUM_1) + index ;

#else

    return 0 ;

#endif

} 


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_cust_key_tone_audio_id
 * DESCRIPTION
 *  This function is for modules to get audio resource id of digit tone by 
 *  inputs the keypad tone type. If the keypad tone type is not of
 *  SRV_PROF_KEYPAD_CUST_1 ~ 5, SRV_PROF_KEYPAD_CUST_1 will be applied
 *  will be applied.
 * PARAMETERS
 *  keypad_tone_type     [IN]    keypad tone type of digit tone
 * RETURNS
 *  U16			audio resource id
 *****************************************************************************/
 U16 srv_prof_get_cust_key_tone_audio_id(srv_prof_keypad_tone_type_enum keypad_tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef CUST_KEYPAD_TONE_SUPPORT 

    return AUD_ID_PROF_CUST_1 + (keypad_tone_type - SRV_PROF_KEYPAD_CUST_1);

#else

    return 0 ;

#endif
}

#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_set_audio_type
 * DESCRIPTION
 *  This function is to set audio type for TC01 gain table support
 *  
 * PARAMETERS
 *  srv_prof_tone_enum  [IN]    tone_type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_play_audio_set_audio_type(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(tone_type)
    {
        case SRV_PROF_TONE_ERROR:
        case SRV_PROF_TONE_WARNING:
        case SRV_PROF_TONE_ERROR_INCALL:
        case SRV_PROF_TONE_WARNING_INCALL:
        case SRV_PROF_TONE_BATTERY_LOW:
        case SRV_PROF_TONE_BATTERY_WARNING:
        case SRV_PROF_TONE_AUTH_FAIL:
        case SRV_PROF_TONE_NUM_UNOBTAIN:
        case SRV_PROF_TONE_CALL_DROP:
        case SRV_PROF_TONE_DELETED:
        case SRV_PROF_TONE_PROBLEM:
        case SRV_PROF_TONE_NOT_AVAILABLE:
        case SRV_PROF_TONE_SMS_INCALL:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_ALERT);
            break;
        }

        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_MESSAGE);
            break;            
        }

        case SRV_PROF_TONE_POWER_OFF:
        case SRV_PROF_TONE_POWER_ON:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_POWER_OFF);
            break;
        }

        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_PHONEBOOK:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
            break;
        }

        default:
        {
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_EFFECT);
            break;
        }

    }

}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_info_check_beep
 * DESCRIPTION
 *  This function is to check if need transform to beep
 *  
 * PARAMETERS
 *  srv_prof_tone_enum  [IN]    tone_type
 *
 * RETURNS
 *  srv_prof_volume_level
 *****************************************************************************/
static srv_prof_volume_level srv_prof_play_audio_query_volume(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(tone_type)
    {
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_SMS_INCALL:
        {
            return g_srv_prof.cur_setting.msg_vol;
        }

        case SRV_PROF_TONE_KEYPAD:
        {
            return g_srv_prof.cur_setting.keypad_vol;
        }

        case SRV_PROF_TONE_CCBS:
        case SRV_PROF_TONE_CALL_REMINDER:
        case SRV_PROF_TONE_CONGESTION:
        case SRV_PROF_TONE_AUTH_FAIL:
        case SRV_PROF_TONE_NUM_UNOBTAIN:
        case SRV_PROF_TONE_CALL_DROP:
        case SRV_PROF_TONE_WARNING_INCALL:
        case SRV_PROF_TONE_ERROR_INCALL:
        case SRV_PROF_TONE_CONNECT_INCALL:
        case SRV_PROF_TONE_SUCCESS_INCALL:
        case SRV_PROF_TONE_WAITING_CALL:
        {
            return MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume());
        }

        case SRV_PROF_TONE_ERROR:
        case SRV_PROF_TONE_WARNING:
        case SRV_PROF_TONE_EMPTY_LIST:
        case SRV_PROF_TONE_FILE_ARRIVAL:
        case SRV_PROF_TONE_GENERAL_TONE:
        case SRV_PROF_TONE_AUX:
        case SRV_PROF_TONE_BATTERY_LOW:
        case SRV_PROF_TONE_BATTERY_WARNING:
        case SRV_PROF_TONE_EXPLICITLY_SAVE:
        case SRV_PROF_TONE_SENT:
        case SRV_PROF_TONE_DELETED:
        case SRV_PROF_TONE_PROBLEM:
        case SRV_PROF_TONE_CONFIRM:
        case SRV_PROF_TONE_NOT_AVAILABLE:
        case SRV_PROF_TONE_ANS_PHONE:
        case SRV_PROF_TONE_REMIND:   
        {
            /* alert type tone use default volume 3 as long as system alert is allowed to play */
            return SRV_PROF_VOL_LEVEL_3;
        }
    #ifndef __MMI_PROFILE_HIGH_PRIORITY__
        case SRV_PROF_TONE_ALARM:
        {
            if(g_srv_prof.cur_setting.ring_vol == SRV_PROF_VOL_LEVEL_0)
            {
                return SRV_PROF_VOL_LEVEL_3;
            }
            else
            {
                return g_srv_prof.cur_setting.ring_vol;
            }
        }
    #endif

        default:
        {
            return g_srv_prof.cur_setting.ring_vol;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_info_init
 * DESCRIPTION
 *  This function is for internal play audio
 *  
 * PARAMETERS
 *  srv_prof_play_audio_struct [IN] play information
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_play_audio_info_init(srv_prof_play_audio_struct* play_info, srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    play_info->audio_id = 0;

    play_info->play_style = SRV_PROF_RING_TYPE_ONCE;

    play_info->volume = srv_prof_play_audio_query_volume(tone_type);

    play_info->tone_type = tone_type;

    play_info->play_from_full_struct = MMI_FALSE;

    switch(tone_type)
    {
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_WAP_PUSH:
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        case SRV_PROF_TONE_ALARM:
        {
            play_info->aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }
        default:
        {
            play_info->aud_path = MDI_DEVICE_SPEAKER2;
            break;
        }
    }



}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_info_check_beep
 * DESCRIPTION
 *  This function is to check if need transform to beep
 *  
 * PARAMETERS
 *  srv_prof_audio_id [OUT] audio id
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_play_audio_info_check_beep(srv_prof_audio_id* audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

     if(srv_prof_is_app_playing())
     {
        *audio_id = TONE_GENERAL_BEEP;
     }
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_fail_recover
 * DESCRIPTION
 *  When some tone type plays fail, we need to recover by default audio.
 *  Ex: Incoming call
 *  Only handles tone types who have setting in profile service
 * PARAMETERS
 *  srv_prof_tone_enum [IN] tone_types
 *  U8  [IN] audio path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result srv_prof_play_audio_fail_recover(srv_prof_tone_enum tone_type, U8 aud_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result play_result = MDI_AUDIO_FAIL;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_FAIL_RECOVER,tone_type);

    switch(tone_type)
    {
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        case SRV_PROF_TONE_POC:
        case SRV_PROF_TONE_VOIP:
        {
            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                if(SRV_PROF_RET_YES != g_srv_prof.play_tone.tone_cb(SRV_PROF_RET_TRY_TO_RECOVER))
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,play_result);
                    return play_result;
                }
            }

            audio_data = get_audio(AUD_ID_PROF_RING1, &audio_type, &audio_len);
            ASSERT(audio_data != NULL);

        #ifdef __GAIN_TABLE_SUPPORT__
            srv_prof_play_audio_set_audio_type(tone_type);
        #endif

            play_result = mdi_audio_play_string_with_vol_path(
                             (void*)audio_data,
                             audio_len,
                             audio_type,
                             g_srv_prof.play_tone.play_style,
                             srv_prof_play_audio_callback,
                             NULL,
                             MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.ring_vol),
                             MDI_AUD_PTH_EX(aud_path));

            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_STRING;

            break;
        }
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_POWER_ON:
        case SRV_PROF_TONE_POWER_OFF:
        case SRV_PROF_TONE_COVER_OPEN:
        case SRV_PROF_TONE_COVER_CLOSE:
        {
            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                if(SRV_PROF_RET_YES != g_srv_prof.play_tone.tone_cb(SRV_PROF_RET_TRY_TO_RECOVER))
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,play_result);
                    return play_result;
                }
            }

            audio_data = get_audio(AUD_ID_PROF_TONE1, &audio_type, &audio_len);
            ASSERT(audio_data != NULL);

        #ifdef __GAIN_TABLE_SUPPORT__
            srv_prof_play_audio_set_audio_type(tone_type);
        #endif


            play_result = mdi_audio_play_string_with_vol_path(
                             (void*)audio_data,
                             audio_len,
                             audio_type,
                             g_srv_prof.play_tone.play_style,
                             srv_prof_play_audio_callback,
                             NULL,
                             MDI_AUD_VOL_MUTE(g_srv_prof.cur_setting.msg_vol),
                             MDI_AUD_PTH_EX(aud_path));

            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_STRING;

            break;
        }

        default:
            break;

    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,play_result);
    return play_result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_callback
 * DESCRIPTION
 *  This function is to check if need transform to beep
 *  
 * PARAMETERS
 *  mdi_result  [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_play_audio_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result play_result;
    srv_prof_play_tone_callback tone_cb;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_CALLBACK,result);

    switch(result)
    {
        case MDI_AUDIO_SUCCESS:
        case MDI_AUDIO_TERMINATED:
        case MDI_AUDIO_RESUME:
        case MDI_AUDIO_BLOCKED:
        case MDI_AUDIO_END_OF_FILE:
        {
            g_srv_prof.play_tone.current_tone = SRV_PROF_TONE_NONE;
            g_srv_prof.play_tone.conflict_tone = SRV_PROF_TONE_NONE; 
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_NONE;

            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                tone_cb = g_srv_prof.play_tone.tone_cb;
                g_srv_prof.play_tone.tone_cb = NULL;
                tone_cb(SRV_PROF_RET_PLAY_FINISHED);
            }
            return;
        }

        default:
        {
            break;
        }
    }

    /* play fail */
    /* try to recover */
    play_result = srv_prof_play_audio_fail_recover(g_srv_prof.play_tone.current_tone, g_srv_prof.play_tone.audio_path);

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        return;
    }

    g_srv_prof.play_tone.current_tone = SRV_PROF_TONE_NONE;
    g_srv_prof.play_tone.conflict_tone = SRV_PROF_TONE_NONE;
    g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_NONE;
    g_srv_prof.play_tone.audio_path = MDI_DEVICE_SPEAKER2;

    if(g_srv_prof.play_tone.tone_cb != NULL)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_FAIL);
    }
    return;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_set_paly_style
 * DESCRIPTION
 *  This function is to remap play style from serivce's ring type enum
 * PARAMETERS
 *  play_style     [IN]    play style
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_play_audio_set_paly_style(srv_prof_ring_type_enum play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(play_style)
    {
        case SRV_PROF_RING_TYPE_ONCE:
        case SRV_PROF_RING_TYPE_BEEP_ONCE:
        {
            g_srv_prof.play_tone.play_style = DEVICE_AUDIO_PLAY_ONCE;
            break;
        }

        case SRV_PROF_RING_TYPE_REPEAT:
        {
            g_srv_prof.play_tone.play_style = DEVICE_AUDIO_PLAY_INFINITE;
            break;
        }

        case SRV_PROF_RING_TYPE_ASCENDING:
        {
            g_srv_prof.play_tone.play_style = DEVICE_AUDIO_PLAY_CRESCENDO;
            break;
        }

        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_key_tone
 * DESCRIPTION
 *  This function is for internal play key tone
 *  
 * PARAMETERS
 *  srv_prof_play_audio_struct [IN] play information
 *
 * RETURNS
 *  mdi_result
 *      
 *****************************************************************************/
static mdi_result srv_prof_play_key_tone(srv_prof_play_audio_struct play_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mdi_result play_result = MDI_AUDIO_FAIL;

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) || defined(__MMI_CUST_KEYPAD_TONE__)
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
#endif

    srv_prof_audio_id audio_id = play_info.audio_id;
    srv_prof_volume_level volume = play_info.volume;
    U8 aud_path = play_info.aud_path;
    U8 play_style = DEVICE_AUDIO_PLAY_ONCE;
    srv_prof_play_tone_callback tone_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_PLAY_AUD_ID_IN,audio_id,volume,aud_path,play_info.play_style);

    switch(play_info.play_style)
    {
        case SRV_PROF_RING_TYPE_ONCE:
        case SRV_PROF_RING_TYPE_BEEP_ONCE:
        {
            play_style = DEVICE_AUDIO_PLAY_ONCE;
            break;
        }

        case SRV_PROF_RING_TYPE_REPEAT:
        {
            play_style = DEVICE_AUDIO_PLAY_INFINITE;
            break;
        }

        case SRV_PROF_RING_TYPE_ASCENDING:
        {
            play_style = DEVICE_AUDIO_PLAY_CRESCENDO;
            break;
        }

        default:
            break;
    }


    /* callback preivous tone play about it is terminated by others */
    if(g_srv_prof.play_tone.tone_cb != NULL && audio_id > MAX_TONE_ID)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_PLAY_FINISHED);
    }

/* DTMF */
    if(audio_id < MAX_TONE_ID)
    {
        play_result = mdi_audio_play_id_with_vol_path(
                         audio_id,
                         play_style,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        if(play_result == MDI_AUDIO_SUCCESS)
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_DTMF;
        }
        else
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_NONE;
        }
    }
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
/* Special Number Tone*/
    else if(audio_id > AUD_ID_PROF_NUM_BEGIN && audio_id < AUD_ID_PROF_NUM_END)
    {
        audio_data = get_audio(audio_id, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(SRV_PROF_TONE_KEYPAD);
    #endif


        play_result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_data,
                         audio_len,
                         audio_type,
                         play_style,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        if(play_result == MDI_AUDIO_SUCCESS)
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_STRING;
        }
        else
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_NONE;
        }

    }
#endif /* __MMI_HUMAN_VOICE_KEYPAD_TONE__ */ 
#if defined(__MMI_CUST_KEYPAD_TONE__)
    /* Customer Keypad Tone */
    else if(audio_id > AUD_ID_PROF_CUST_BEGIN && audio_id < AUD_ID_PROF_CUST_END )
    {
        audio_data = get_audio(audio_id, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(SRV_PROF_TONE_KEYPAD);
    #endif

        
        play_result = mdi_audio_play_string_with_vol_path(
                         (void*)audio_data,
                         audio_len,
                         audio_type,
                         play_style,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        if(play_result == MDI_AUDIO_SUCCESS)
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_STRING;
        }
        else
        {
            g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_NONE;
        }

    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 


    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_PLAY_AUD_ID_OUT,play_result,g_srv_prof.play_tone.key_audio_type);

    return play_result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_audio_id
 * DESCRIPTION
 *  This function is for internal play audio
 *  
 * PARAMETERS
 *  srv_prof_play_audio_struct [IN] play information
 *
 * RETURNS
 *  mdi_result
 *      
 *****************************************************************************/
static mdi_result srv_prof_play_audio_id(srv_prof_play_audio_struct play_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mdi_result play_result = MDI_AUDIO_FAIL;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    WCHAR path_buf[SRV_FMGR_PATH_MAX_LEN+1];
#endif
    srv_prof_audio_id audio_id = play_info.audio_id;
    srv_prof_volume_level volume = play_info.volume;
    U8 aud_path = play_info.aud_path;
    srv_prof_play_tone_callback tone_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_PLAY_AUD_ID_IN,audio_id,volume,aud_path,play_info.play_style);

    srv_prof_play_audio_set_paly_style(play_info.play_style);

    /* callback preivous tone play about it is terminated by others */
    if(g_srv_prof.play_tone.tone_cb != NULL && audio_id > MAX_TONE_ID)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_PLAY_FINISHED);
    }

/* DTMF */
    if(audio_id < MAX_TONE_ID)
    {
        /* if the path is not defined by user, DTMF always plays with speaker2*/
        //if(!play_info.play_from_full_struct)
        //{
        //    aud_path = MDI_DEVICE_SPEAKER2;
        //}

        play_result = mdi_audio_play_id_with_vol_path(
                         audio_id,
                         g_srv_prof.play_tone.play_style,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

    }
/* Internal Generated */
    else if(audio_id > AUD_ID_PROF_INTERNAL_BEGIN && audio_id < AUD_ID_PROF_INTERNAL_END)
    {
        audio_data = get_audio(audio_id, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(play_info.tone_type);
    #endif

        play_result = mdi_audio_play_string_with_vol_path(
                         (void*)audio_data,
                         audio_len,
                         audio_type,
                         g_srv_prof.play_tone.play_style,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;
        g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_STRING;

    }

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
/* External Melody */
    else if( audio_id > AUD_ID_PROF_EXT_BEGIN && audio_id < AUD_ID_PROF_EXT_END )
    {
        U8 slot = audio_id - AUD_ID_PROF_EXT1;

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(play_info.tone_type);
    #endif

        play_result = mdi_audio_play_file_portion_with_vol_path(
                         g_srv_prof.ext_melody.info[slot].filefullpath,
                         0,
                         0,
                         g_srv_prof.play_tone.play_style,
                         NULL,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        /* try to recover */
        if(play_result != MDI_AUDIO_SUCCESS)
        {
            play_result = srv_prof_play_audio_fail_recover(play_info.tone_type, aud_path);
        }
        else
        {
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_FILE;
        }
    }   
#endif
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
/* Special Number Tone*/
    else if(audio_id > AUD_ID_PROF_NUM_BEGIN && audio_id < AUD_ID_PROF_NUM_END)
    {
        audio_data = get_audio(audio_id, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(play_info.tone_type);
    #endif

        play_result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_data,
                         audio_len,
                         audio_type,
                         g_srv_prof.play_tone.play_style,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;
        g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_STRING;

    }
#endif /* __MMI_HUMAN_VOICE_KEYPAD_TONE__ */ 
#if defined(__MMI_CUST_KEYPAD_TONE__)
    /* Customer Keypad Tone */
    else if(audio_id > AUD_ID_PROF_CUST_BEGIN && audio_id < AUD_ID_PROF_CUST_END )
    {
        audio_data = get_audio(audio_id, &audio_type, &audio_len);

        ASSERT(audio_data != NULL);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(play_info.tone_type);
    #endif

        play_result = mdi_audio_play_string_with_vol_path(
                         (void*)audio_data,
                         audio_len,
                         audio_type,
                         g_srv_prof.play_tone.play_style,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;
        g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_STRING;

    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 
#ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __GAIN_TABLE_SUPPORT__
/* under construction !*/
    #endif
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
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    /* Downloadable Theme Tone */
    else if(GetAudioNameWithPathInFileSystem(audio_id, (CHAR*)path_buf) != NULL)
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(play_info.tone_type);
    #endif

        play_result = mdi_audio_play_file_portion_with_vol_path(
                         path_buf,
                         0,
                         0,
                         g_srv_prof.play_tone.play_style,
                         NULL,
                         srv_prof_play_audio_callback,
                         NULL,
                         MDI_AUD_VOL_MUTE(volume),
                         MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        /* try to recover */
        if(play_result != MDI_AUDIO_SUCCESS)
        {
            play_result = srv_prof_play_audio_fail_recover(play_info.tone_type, aud_path);
        }
        else
        {
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_FILE;
        }
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_PLAY_AUD_ID_OUT,play_result,g_srv_prof.play_tone.audio_type);

    return play_result;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_query_mdi_play_mode
 * DESCRIPTION
 *  This function is for play tone user to know what kind of audio resuoce will be
 *  play with the tone_type.
 *  
 * PARAMETERS
 *  srv_prof_tone_enum  [IN]    tone_type
 *
 * RETURNS
 *  MDI_AUDIO_PLAY_MODE_ENUM
 *      MDI_AUDIO_PLAY_ID: play with DTMF tone
 *      MDI_AUDIO_PLAY_STRING: play with audio resource string
 *      MDI_AUDIO_PLAY_FILE: play with file
 *****************************************************************************/
MDI_AUDIO_PLAY_MODE_ENUM srv_prof_play_tone_query_mdi_play_mode(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL in_call = MMI_FALSE;
    MDI_AUDIO_PLAY_MODE_ENUM mode = MDI_AUDIO_PLAY_ID; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check in call*/
    in_call = (MMI_BOOL)srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL);

    if(!in_call)
    {
        switch(tone_type)
        {
        #ifdef __MMI_OP11_PROF_SOUND__
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
            case SRV_PROF_TONE_FILE_ARRIVAL:
            case SRV_PROF_TONE_ALARM:
            {
                mode = MDI_AUDIO_PLAY_STRING;
                break;
            }

            case SRV_PROF_TONE_INCOMING_CALL:
            case SRV_PROF_TONE_INCOMING_CALL_CARD2:
            case SRV_PROF_TONE_INCOMING_CALL_CARD3:
            case SRV_PROF_TONE_INCOMING_CALL_CARD4:
            case SRV_PROF_TONE_VIDEO_CALL:
            case SRV_PROF_TONE_VIDEO_CALL_CARD2:
            case SRV_PROF_TONE_VIDEO_CALL_CARD3:
            case SRV_PROF_TONE_VIDEO_CALL_CARD4:
            case SRV_PROF_TONE_POWER_ON:
            case SRV_PROF_TONE_POWER_OFF:
            case SRV_PROF_TONE_COVER_OPEN:
            case SRV_PROF_TONE_COVER_CLOSE:
            case SRV_PROF_TONE_SMS:
            case SRV_PROF_TONE_SMS_CARD2:
            case SRV_PROF_TONE_SMS_CARD3:
            case SRV_PROF_TONE_SMS_CARD4:
            case SRV_PROF_TONE_MMS:
            case SRV_PROF_TONE_MMS_CARD2:
            case SRV_PROF_TONE_MMS_CARD3:
            case SRV_PROF_TONE_MMS_CARD4:
            case SRV_PROF_TONE_EMAIL:
            case SRV_PROF_TONE_EMAIL_CARD2:
            case SRV_PROF_TONE_EMAIL_CARD3:
            case SRV_PROF_TONE_EMAIL_CARD4:
            case SRV_PROF_TONE_VOICE:
            case SRV_PROF_TONE_VOICE_CARD2:
            case SRV_PROF_TONE_VOICE_CARD3:
            case SRV_PROF_TONE_VOICE_CARD4:
            case SRV_PROF_TONE_WAP_PUSH:
            {
                srv_prof_audio_id audio_id = 0;

                switch(tone_type)
                {                        
                    case SRV_PROF_TONE_INCOMING_CALL:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_TONE, (void*)&audio_id);
                        break;
                    }
                    
                    case SRV_PROF_TONE_INCOMING_CALL_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_INCOMING_CALL_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_INCOMING_CALL_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VIDEO_CALL:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VIDEO_CALL_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VIDEO_CALL_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VIDEO_CALL_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE, (void*)&audio_id);
                        break;
                    }

                #ifndef __MMI_POWER_ON_OFF_MUTE__
                    case SRV_PROF_TONE_POWER_ON:
                    {
                        audio_id = g_srv_prof.cur_setting.power_on_tone ;
                        break;
                    }

                    case SRV_PROF_TONE_POWER_OFF:
                    {
                        audio_id = g_srv_prof.cur_setting.power_off_tone ;
                        break;
                    }
                #endif

                #ifdef __MMI_CLAMSHELL__                
                    case SRV_PROF_TONE_COVER_OPEN:
                    {
                        audio_id = g_srv_prof.cur_setting.cover_open_tone;
                        break;
                    }

                    case SRV_PROF_TONE_COVER_CLOSE:
                    {
                        audio_id = g_srv_prof.cur_setting.cover_close_tone;
                        break;
                    }
                #endif

                    case SRV_PROF_TONE_SMS:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_SMS_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_SMS_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_SMS_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD4_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_MMS:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_MMS_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_MMS_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_MMS_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD4_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_EMAIL:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_EMAIL_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_EMAIL_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_EMAIL_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD4_TONE, (void*)&audio_id);
                        break;
                    }


                    case SRV_PROF_TONE_VOICE:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VOICE_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VOICE_CARD2:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD2_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VOICE_CARD3:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD3_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_VOICE_CARD4:
                    {
                        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD4_TONE, (void*)&audio_id);
                        break;
                    }

                    case SRV_PROF_TONE_WAP_PUSH:
                    {
                        audio_id = g_srv_prof.cur_setting.sms_tone[0];
                        break;
                    }
                    default:
                        break;
                }

                if(audio_id > AUD_ID_PROF_INTERNAL_BEGIN && audio_id < AUD_ID_PROF_INTERNAL_END)
                {
                    mode = MDI_AUDIO_PLAY_STRING;
                }
                else if(audio_id > AUD_ID_PROF_EXT_BEGIN && audio_id < AUD_ID_PROF_EXT_END)
                {
                    mode = MDI_AUDIO_PLAY_FILE;
                }

                break;
            }

        }

    }
    else
    {
        switch(tone_type)
        {
            case SRV_PROF_TONE_POWER_OFF:
            {
            #ifndef __MMI_POWER_ON_OFF_MUTE__
                srv_prof_audio_id audio_id;
                audio_id = g_srv_prof.cur_setting.power_off_tone;

                if(audio_id > AUD_ID_PROF_INTERNAL_BEGIN && audio_id < AUD_ID_PROF_INTERNAL_END)
                {
                    mode = MDI_AUDIO_PLAY_STRING;
                }
                else if(audio_id > AUD_ID_PROF_EXT_BEGIN && audio_id < AUD_ID_PROF_EXT_END)
                {
                    mode = MDI_AUDIO_PLAY_FILE;
                }
            #endif
                break;
            }

            default:
                break;
        }
    }    

    return mode;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_switch_loudness
 * DESCRIPTION
 *  turn on/off loudness
 *  
 * PARAMETERS
 *  srv_prof_tone_enum [IN] tone type
 *  MMI_BOOL           [IN] MMI_TRUE: on
                            MMI_FALSE: off
 *
 * RETURNS
 *  srv_prof_ret
 *      
 *****************************************************************************/
static void srv_prof_play_tone_switch_loudness(srv_prof_tone_enum tone_type, MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BES_LOUDNESS_SUPPORT__
    switch(tone_type)
    {
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        {
            if(turn_on)
            {
                mdi_audio_loudness_turn_on();
            }
            else
            {
                mdi_audio_loudness_turn_off();
            }
        }
        default:
            break;
    }
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_setting_check
 * DESCRIPTION
 *  This function is to check if tone_type shall play in current profile setting
 *
 * PARAMETERS
 *  tone_type     [IN]    requested tone type
 * RETURNS
 *  MMI_BOOL
 *     MMI_TRUE: Tone type shall play in current setting
 *     MMI_FALSE: Tone type shall not play in current setting
 *****************************************************************************/
static MMI_BOOL srv_prof_play_tone_setting_check(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL in_call;
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check in call*/
    in_call = (MMI_BOOL)srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL);

    if(!in_call)
    {
        switch(tone_type)
        {
            case SRV_PROF_TONE_ERROR:
            case SRV_PROF_TONE_WARNING:
            case SRV_PROF_TONE_EMPTY_LIST:
            case SRV_PROF_TONE_FILE_ARRIVAL:
            case SRV_PROF_TONE_GENERAL_TONE:
            case SRV_PROF_TONE_AUX:
            case SRV_PROF_TONE_BATTERY_LOW:
            case SRV_PROF_TONE_BATTERY_WARNING:
            case SRV_PROF_TONE_WARNING_INCALL:
            case SRV_PROF_TONE_ERROR_INCALL:
            case SRV_PROF_TONE_EXPLICITLY_SAVE:
            case SRV_PROF_TONE_SENT:
            case SRV_PROF_TONE_DELETED:
            case SRV_PROF_TONE_PROBLEM:
            case SRV_PROF_TONE_CONFIRM:
            case SRV_PROF_TONE_NOT_AVAILABLE:
            case SRV_PROF_TONE_ANS_PHONE:
            case SRV_PROF_TONE_REMIND:
            {
                if (g_srv_prof.cur_setting.system_alert != MMI_TRUE)
                {
                    result = MMI_FALSE;
                }
                break;
            }

            case SRV_PROF_TONE_CONNECT:
            {
            #ifndef __MMI_CONNECT_NOTICE__
                result = MMI_FALSE;
            #else
                if(srv_callset_connect_notice_get_mode() == MMI_FALSE)
                {
                    result = MMI_FALSE;
                }
            #endif

                break;
            }

            case SRV_PROF_TONE_INCOMING_CALL:
            case SRV_PROF_TONE_INCOMING_CALL_CARD2:
            case SRV_PROF_TONE_INCOMING_CALL_CARD3:
            case SRV_PROF_TONE_INCOMING_CALL_CARD4:
            case SRV_PROF_TONE_VIDEO_CALL:
            case SRV_PROF_TONE_VIDEO_CALL_CARD2:
            case SRV_PROF_TONE_VIDEO_CALL_CARD3:
            case SRV_PROF_TONE_VIDEO_CALL_CARD4:
            case SRV_PROF_TONE_SMS:
            case SRV_PROF_TONE_SMS_CARD2:
            case SRV_PROF_TONE_SMS_CARD3:
            case SRV_PROF_TONE_SMS_CARD4:
            case SRV_PROF_TONE_MMS:
            case SRV_PROF_TONE_MMS_CARD2:
            case SRV_PROF_TONE_MMS_CARD3:
            case SRV_PROF_TONE_MMS_CARD4:
            case SRV_PROF_TONE_EMAIL:
            case SRV_PROF_TONE_EMAIL_CARD2:
            case SRV_PROF_TONE_EMAIL_CARD3:
            case SRV_PROF_TONE_EMAIL_CARD4:
            case SRV_PROF_TONE_VOICE:
            case SRV_PROF_TONE_VOICE_CARD2:
            case SRV_PROF_TONE_VOICE_CARD3:
            case SRV_PROF_TONE_VOICE_CARD4:
            case SRV_PROF_TONE_WAP_PUSH:
            case SRV_PROF_TONE_SMS_INCALL:
        #ifdef __MMI_CLAMSHELL__
            case SRV_PROF_TONE_COVER_OPEN:
            case SRV_PROF_TONE_COVER_CLOSE:
        #endif
            {
                if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
                {
                    result = MMI_FALSE;
                }
                break;
            }

        #ifndef __MMI_POWER_ON_OFF_MUTE__
            case SRV_PROF_TONE_POWER_ON:
            case SRV_PROF_TONE_POWER_OFF:
            {
                if (g_srv_prof.cur_setting.power_on_off_tone != MMI_TRUE)
                {
                    result = MMI_FALSE;
                }
                break;
            }
        #endif


            case SRV_PROF_TONE_SUCCESS:
            case SRV_PROF_TONE_SAVE: 
            case SRV_PROF_TONE_CAMP_ON: 
            {
                result = MMI_FALSE;
            }

            default:
                break;
        }
    }
    else
    {
        switch(tone_type)
        {
        #ifndef __MMI_POWER_ON_OFF_MUTE__
            case SRV_PROF_TONE_POWER_OFF:
            {
                if (g_srv_prof.cur_setting.power_on_off_tone != MMI_TRUE)
                {
                    result = MMI_FALSE;
                }
                break;
            }
        #endif

            case SRV_PROF_TONE_SMS_INCALL:
            {

                if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
                {
                    result = MMI_FALSE;
                }
                break;
            } 

            case SRV_PROF_TONE_WARNING_INCALL:
            case SRV_PROF_TONE_ERROR_INCALL:
            case SRV_PROF_TONE_BATTERY_LOW:
            case SRV_PROF_TONE_BATTERY_WARNING:
            case SRV_PROF_TONE_PROBLEM:
            {
                if(g_srv_prof.cur_setting.system_alert != MMI_TRUE)
                {
                    result = MMI_FALSE;
                }
                break;
            }
            
            case SRV_PROF_TONE_CONNECT_INCALL:
            case SRV_PROF_TONE_CONNECT:
            {
            #ifndef __MMI_CONNECT_NOTICE__
                result = MMI_FALSE;
            #else
                if(srv_callset_connect_notice_get_mode() == MMI_FALSE)
                {
                    result = MMI_FALSE;
                }
            #endif
                break;
            }

            case SRV_PROF_TONE_SUCCESS_INCALL:
            {
                result = MMI_FALSE;
            }

            default:
                break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_PLAY_TONE_CHECK,result,in_call);

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_not_in_call
 * DESCRIPTION
 *  Handle not in call cases
 *  
 * PARAMETERS
 *  srv_prof_tone_enum [IN] tone type
 *
 * RETURNS
 *  srv_prof_ret
 *      
 *****************************************************************************/
static srv_prof_ret srv_prof_play_tone_not_in_call(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_play_audio_struct play_info;
    mdi_result play_result = MDI_AUDIO_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_prof_play_audio_info_init(&play_info, tone_type);

    switch(tone_type)
    {
        case SRV_PROF_TONE_CONGESTION:
        case SRV_PROF_TONE_AUTH_FAIL:
        case SRV_PROF_TONE_NUM_UNOBTAIN:
        case SRV_PROF_TONE_CALL_DROP:
        {
            switch(tone_type)
            {
                case SRV_PROF_TONE_CONGESTION:
                {
                    play_info.audio_id = TONE_CONGESTION_GSM;
                    break;
                }

                case SRV_PROF_TONE_AUTH_FAIL:
                {
                    play_info.audio_id = TONE_AUTH_ERROR;
                    break;
                }

                case SRV_PROF_TONE_NUM_UNOBTAIN:
                {
                    play_info.audio_id = TONE_NUM_UNOBTAIN;
                    break;
                }
                
                case SRV_PROF_TONE_CALL_DROP:
                {
                    play_info.audio_id = TONE_RADIO_NA;                    
                    break;
                }
            }

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_ERROR:
        case SRV_PROF_TONE_WARNING:
        case SRV_PROF_TONE_EMPTY_LIST:
        case SRV_PROF_TONE_FILE_ARRIVAL:
        {
            if (g_srv_prof.cur_setting.system_alert != MMI_TRUE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            switch(tone_type)
            {
                case SRV_PROF_TONE_ERROR:
                {
                    play_info.audio_id = TONE_ERROR1;
                    break;
                }

                case SRV_PROF_TONE_WARNING:
                {
                #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
                #else
                    play_info.audio_id = TONE_WARNING1;
                #endif
                    break;
                }

                case SRV_PROF_TONE_EMPTY_LIST:
                {
                #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
                #else
                    play_info.audio_id = TONE_WARNING1;
                #endif
                    break;
                }

                case SRV_PROF_TONE_FILE_ARRIVAL:
                {
                    play_info.audio_id = AUD_ID_PROF_TONE4;
                    break;
                }

                default:
                    break;
            }

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_CONNECT:
        {
        #ifndef __MMI_CONNECT_NOTICE__
            return SRV_PROF_RET_NOT_PLAY;
        #else
            if(srv_callset_connect_notice_get_mode() == MMI_FALSE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }
            play_info.audio_id = TONE_CALL_CONNECT;

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        #endif
        }

        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        {
            if(srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == SRV_PROF_RET_PROFILE_ACTIVATED)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            switch(tone_type)
            {
                case SRV_PROF_TONE_INCOMING_CALL:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_INCOMING_CALL_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_INCOMING_CALL_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_INCOMING_CALL_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_VIDEO_CALL:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_VIDEO_CALL_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE, (void*)&(play_info.audio_id));
                    break;
                }

                case SRV_PROF_TONE_VIDEO_CALL_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE, (void*)&(play_info.audio_id));
                    break;
                }
                
                case SRV_PROF_TONE_VIDEO_CALL_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE, (void*)&(play_info.audio_id));
                    break;
                }
                default:
                    break;
            }
            
            play_info.play_style = g_srv_prof.cur_setting.ring_type;

            if(play_info.play_style == SRV_PROF_RING_TYPE_BEEP_ONCE)
            {
                play_info.audio_id = TONE_GENERAL_BEEP;
            }

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_SUCCESS:
        case SRV_PROF_TONE_SAVE: 
        case SRV_PROF_TONE_CAMP_ON: 
        {
            return SRV_PROF_RET_NOT_PLAY;
        }

        case SRV_PROF_TONE_ALARM:
        {
            play_info.audio_id = AUD_ID_PROF_RING1;
            srv_prof_play_audio_info_check_beep(&play_info.audio_id);
            if(play_info.audio_id != TONE_GENERAL_BEEP)
            {
                play_info.play_style = SRV_PROF_RING_TYPE_ASCENDING;
            }
            play_result = srv_prof_play_audio_id(play_info);
            break;
        }

        case SRV_PROF_TONE_POWER_ON:
        case SRV_PROF_TONE_POWER_OFF:
        case SRV_PROF_TONE_COVER_OPEN:
        case SRV_PROF_TONE_COVER_CLOSE:
        {
            srv_prof_audio_id temp_id;

            switch(tone_type)
            {
            #ifndef __MMI_POWER_ON_OFF_MUTE__
                case SRV_PROF_TONE_POWER_ON:
                {
                    temp_id = g_srv_prof.cur_setting.power_on_tone ;
                    break;
                }

                case SRV_PROF_TONE_POWER_OFF:
                {
                    temp_id = g_srv_prof.cur_setting.power_off_tone ;
                    break;
                }
            #endif

            #ifdef __MMI_CLAMSHELL__                
                case SRV_PROF_TONE_COVER_OPEN:
                {
                    temp_id = g_srv_prof.cur_setting.cover_open_tone;
                    break;
                }

                case SRV_PROF_TONE_COVER_CLOSE:
                {
                    temp_id = g_srv_prof.cur_setting.cover_close_tone;
                    break;
                }
            #endif

                default:
                    return SRV_PROF_RET_NOT_PLAY;

            }

            if(temp_id == SRV_PROF_TONE_SILENT)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            play_info.audio_id = temp_id;
            
            play_result = srv_prof_play_audio_id(play_info);

            break;
        } 

        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_WAP_PUSH:
        {
            srv_prof_audio_id temp_id;

            //temp_id = g_srv_prof.cur_setting.sms_tone;

            switch(tone_type)
            {
                case SRV_PROF_TONE_SMS:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_SMS_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD2_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_SMS_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD3_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_SMS_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_SMS_CARD4_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_MMS:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_MMS_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD2_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_MMS_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD3_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_MMS_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MMS_CARD4_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_EMAIL:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_EMAIL_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD2_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_EMAIL_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD3_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_EMAIL_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_EMAIL_CARD4_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_VOICE:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VOICE_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_VOICE_CARD2:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VOICE_CARD2_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_VOICE_CARD3:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VOICE_CARD3_TONE, (void*)&(temp_id));
                    break;
                }

                case SRV_PROF_TONE_VOICE_CARD4:
                {
                    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_VOICE_CARD4_TONE, (void*)&(temp_id));
                    break;
                }

                default:
                    break;
            }

            if(temp_id == SRV_PROF_TONE_SILENT)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            play_info.audio_id = temp_id;

            if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
            {
                play_info.audio_id = TONE_GENERAL_BEEP;
            }
            else
            {
                srv_prof_play_audio_info_check_beep(&play_info.audio_id);
            }
            
            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_GENERAL_TONE:
        case SRV_PROF_TONE_AUX:
        case SRV_PROF_TONE_BATTERY_LOW:
        case SRV_PROF_TONE_BATTERY_WARNING:
        {
            if (g_srv_prof.cur_setting.system_alert != MMI_TRUE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            switch(tone_type)
            {
                case SRV_PROF_TONE_GENERAL_TONE:
                {
                    play_info.audio_id = TONE_GENERAL_BEEP;
                    break;
                }

                case SRV_PROF_TONE_AUX:
                {
                    play_info.audio_id = TONE_AUX_IND;
                    srv_prof_play_audio_info_check_beep(&play_info.audio_id);
                    break;
                }

                case SRV_PROF_TONE_BATTERY_LOW:
                {
                    play_info.audio_id = TONE_BATTERY_LOW;
                    break;
                }

                case SRV_PROF_TONE_BATTERY_WARNING:
                {
                    play_info.audio_id = TONE_BATTERY_WARNING;
                    break;
                }

            }

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_SMS_INCALL:
        {
            if(g_srv_prof.cur_setting.sms_tone == SRV_PROF_TONE_SILENT)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }
            
            play_info.audio_id = TONE_MT_SMS_IN_CALL;

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_WARNING_INCALL:
        case SRV_PROF_TONE_ERROR_INCALL:
        {
            if(g_srv_prof.cur_setting.system_alert != MMI_TRUE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            switch(tone_type)
            {
                case SRV_PROF_TONE_WARNING_INCALL:
                {
                    play_info.audio_id = TONE_WARNING2;
                    break;
                }
                
                case SRV_PROF_TONE_ERROR_INCALL:
                {
                    play_info.audio_id = TONE_ERROR2;
                    break;
                }

            }

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_DIALER:
        {
        #ifndef __OP01_FWPBW__
            return SRV_PROF_RET_NOT_PLAY;
        #else
            play_info.audio_id = TONE_CONTINUE_SOUND;
            play_result = srv_prof_play_audio_id(play_info);

            break;
        #endif
        }

        case SRV_PROF_TONE_EXPLICITLY_SAVE:
        case SRV_PROF_TONE_SENT:
        case SRV_PROF_TONE_DELETED:
        case SRV_PROF_TONE_PROBLEM:
        case SRV_PROF_TONE_CONFIRM:
        case SRV_PROF_TONE_NOT_AVAILABLE:
        case SRV_PROF_TONE_ANS_PHONE:
        case SRV_PROF_TONE_REMIND:
        {
            if(g_srv_prof.cur_setting.system_alert != MMI_TRUE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

        #ifdef __MMI_OP11_PROF_SOUND__
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
        #else
            return SRV_PROF_RET_NOT_PLAY;
        #endif /*__MMI_OP11_PROF_SOUND__*/

        }

        default:
        {
            return SRV_PROF_RET_NOT_PLAY;
        }
    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_info.audio_id <  MAX_TONE_ID)
        {
            return SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;            
        }
        else
        {
            return SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        return SRV_PROF_RET_FAIL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_in_call
 * DESCRIPTION
 *  Handle in call cases
 *  
 * PARAMETERS
 *  srv_prof_tone_enum [IN] tone type
 *
 * RETURNS
 *  srv_prof_ret
 *      
 *****************************************************************************/
static srv_prof_ret srv_prof_play_tone_in_call(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_play_audio_struct play_info;
    mdi_result play_result = MDI_AUDIO_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_prof_play_audio_info_init(&play_info, tone_type);

    switch(tone_type)
    {
        case SRV_PROF_TONE_CONGESTION:
        case SRV_PROF_TONE_AUTH_FAIL:
        case SRV_PROF_TONE_NUM_UNOBTAIN:
        case SRV_PROF_TONE_CALL_DROP:
        {
            switch(tone_type)
            {
                case SRV_PROF_TONE_CONGESTION:
                {
                    play_info.audio_id = TONE_CONGESTION_GSM;
                    break;
                }

                case SRV_PROF_TONE_AUTH_FAIL:
                {
                    play_info.audio_id = TONE_AUTH_ERROR;
                    break;
                }

                case SRV_PROF_TONE_NUM_UNOBTAIN:
                {
                    play_info.audio_id = TONE_NUM_UNOBTAIN;
                    break;
                }
                
                case SRV_PROF_TONE_CALL_DROP:
                {
                    play_info.audio_id = TONE_RADIO_NA;                    
                    break;
                }
            }

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);
            break;
        }

        case SRV_PROF_TONE_POWER_OFF:
        {
        #ifndef __MMI_POWER_ON_OFF_MUTE__

            if(g_srv_prof.cur_setting.power_off_tone == SRV_PROF_TONE_SILENT)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            play_info.audio_id = g_srv_prof.cur_setting.power_off_tone;
            
            play_result = srv_prof_play_audio_id(play_info);
            break;
        #else
            return SRV_PROF_RET_NOT_PLAY;
        #endif
        } 

        case SRV_PROF_TONE_SMS_INCALL:
        {
            if(g_srv_prof.cur_setting.sms_tone == SRV_PROF_TONE_SILENT)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }
            
            play_info.audio_id = TONE_MT_SMS_IN_CALL;

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }

        case SRV_PROF_TONE_WARNING_INCALL:
        case SRV_PROF_TONE_ERROR_INCALL:
        case SRV_PROF_TONE_BATTERY_LOW:
        case SRV_PROF_TONE_BATTERY_WARNING:
        case SRV_PROF_TONE_PROBLEM:
        {
            if(g_srv_prof.cur_setting.system_alert != MMI_TRUE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            switch(tone_type)
            {
                case SRV_PROF_TONE_WARNING_INCALL:
                case SRV_PROF_TONE_BATTERY_LOW:
                case SRV_PROF_TONE_BATTERY_WARNING:
                {
                    play_info.audio_id = TONE_WARNING2;
                    break;
                }
                
                case SRV_PROF_TONE_ERROR_INCALL:
                case SRV_PROF_TONE_PROBLEM:
                {
                    play_info.audio_id = TONE_ERROR2;
                    break;
                }

            }

            play_result = srv_prof_play_audio_id(play_info);

            break;
        }
        
        case SRV_PROF_TONE_CONNECT_INCALL:
        case SRV_PROF_TONE_CONNECT:
        {
        #ifndef __MMI_CONNECT_NOTICE__
            return SRV_PROF_RET_NOT_PLAY;
        #else
            if(srv_callset_connect_notice_get_mode() == MMI_FALSE)
            {
                return SRV_PROF_RET_NOT_PLAY;
            }

            play_info.audio_id = TONE_CALL_CONNECT;

            srv_prof_play_audio_info_check_beep(&play_info.audio_id);

            play_result = srv_prof_play_audio_id(play_info);

            break;
        #endif
        }

        case SRV_PROF_TONE_SUCCESS_INCALL:
        {
            return SRV_PROF_RET_NOT_PLAY;
        }

        case SRV_PROF_TONE_ALARM:
        case SRV_PROF_TONE_CALL_REMINDER:
        case SRV_PROF_TONE_CCBS:
        {
            play_info.audio_id = TONE_WARNING2;

            play_result = srv_prof_play_audio_id(play_info);
            
            break;
        }

        default:
        {
            return SRV_PROF_RET_NOT_PLAY;
        }

    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_info.audio_id <  MAX_TONE_ID)
        {
            return SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;            
        }
        else
        {
            return SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        return SRV_PROF_RET_FAIL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone
 * DESCRIPTION
 *  This function is for mmi modules to play tone type.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, when mdi audio callback with events, profile 
 *  service will callback with srv_prof_ret. But this only works for non-DTMF tones.
 *  For DTMF tones, the return value of this function will be SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK
 *  ,which means there is no callback for this play request.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, service will try to recover
 *  with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type     [IN]    requested tone type
 *  callback      [IN]    play tone callback
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone(srv_prof_tone_enum tone_type,srv_prof_play_tone_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL in_call = MMI_FALSE;
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE,SRV_PROF_RET_NOT_PLAY,tone_type);
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(tone_type) != MMI_TRUE || tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE,SRV_PROF_RET_NOT_PLAY,tone_type);
        return SRV_PROF_RET_NOT_PLAY;
    }

    srv_prof_play_tone_switch_loudness(tone_type, MMI_TRUE);

    /* check in call*/
    in_call = (MMI_BOOL)srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL);

    if(!in_call)
    {
        result = srv_prof_play_tone_not_in_call(tone_type);
    }
    else
    {
        result = srv_prof_play_tone_in_call(tone_type);
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = callback;
            }

            /* set current play tone */
            g_srv_prof.play_tone.current_tone = tone_type;
            g_srv_prof.play_tone.conflict_tone = tone_type;
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            g_srv_prof.play_tone.current_DTMF_tone = tone_type;

            if(callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE,result,tone_type);
    return result;

}


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
 *  tone_type     [IN]    requested tone type
 *  tone_id       [IN]    tone id to be played
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      SRV_PROF_RET_FAIL : play tone fail and will not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone_with_id(srv_prof_tone_enum tone_type, 
                                        U16 audio_id,
                                        srv_prof_ring_type_enum play_style,
                                        srv_prof_play_tone_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    srv_prof_play_audio_struct play_info;
    mdi_result play_result = MDI_AUDIO_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_ID,SRV_PROF_RET_NOT_PLAY,tone_type,audio_id);
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(tone_type) != MMI_TRUE || tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_ID,SRV_PROF_RET_NOT_PLAY,tone_type,audio_id);
        return SRV_PROF_RET_NOT_PLAY;
    }

    /* keypad tone 0 is for keypad 0 */
    if(audio_id == SRV_PROF_TONE_SILENT && tone_type != SRV_PROF_TONE_KEYPAD)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_ID,SRV_PROF_RET_NOT_PLAY,tone_type,audio_id);
        return SRV_PROF_RET_NOT_PLAY;
    }

    srv_prof_play_audio_info_init(&play_info, tone_type);

    /* in case the audio id passed in is the mapped audio id in nvram */
    audio_id = srv_prof_transform_audio_id_for_read_nvram(audio_id);

    play_info.audio_id = audio_id;
    play_info.play_style = play_style;

    if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
    {
        switch(tone_type)
        {
            case SRV_PROF_TONE_SMS:
            case SRV_PROF_TONE_SMS_CARD2:
            case SRV_PROF_TONE_SMS_CARD3:
            case SRV_PROF_TONE_SMS_CARD4:
            case SRV_PROF_TONE_MMS:
            case SRV_PROF_TONE_MMS_CARD2:
            case SRV_PROF_TONE_MMS_CARD3:
            case SRV_PROF_TONE_MMS_CARD4:
            case SRV_PROF_TONE_EMAIL:
            case SRV_PROF_TONE_EMAIL_CARD2:
            case SRV_PROF_TONE_EMAIL_CARD3:
            case SRV_PROF_TONE_EMAIL_CARD4:
            case SRV_PROF_TONE_VOICE:
            case SRV_PROF_TONE_VOICE_CARD2:
            case SRV_PROF_TONE_VOICE_CARD3:
            case SRV_PROF_TONE_VOICE_CARD4:
            case SRV_PROF_TONE_WAP_PUSH:
            case SRV_PROF_TONE_INCOMING_CALL:
            case SRV_PROF_TONE_INCOMING_CALL_CARD2:
            case SRV_PROF_TONE_INCOMING_CALL_CARD3:
            case SRV_PROF_TONE_INCOMING_CALL_CARD4:
            case SRV_PROF_TONE_VIDEO_CALL:
            case SRV_PROF_TONE_VIDEO_CALL_CARD2:
            case SRV_PROF_TONE_VIDEO_CALL_CARD3:
            case SRV_PROF_TONE_VIDEO_CALL_CARD4:
            {
                play_info.audio_id = TONE_GENERAL_BEEP;
                play_info.play_style = SRV_PROF_RING_TYPE_BEEP_ONCE;
                break;
            }
            default:
                break;
        }
    }

    srv_prof_play_tone_switch_loudness(tone_type, MMI_TRUE);

    if(tone_type == SRV_PROF_TONE_KEYPAD)
    {
        play_result = srv_prof_play_key_tone(play_info);
    }
    else
    {
        play_result = srv_prof_play_audio_id(play_info);
    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_info.audio_id <  MAX_TONE_ID)
        {
            result = SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;
        }
        else
        {
            result = SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        result = SRV_PROF_RET_FAIL;
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = callback;
            }

            g_srv_prof.play_tone.current_tone = tone_type;
            g_srv_prof.play_tone.conflict_tone = tone_type;

            /* set current play tone */
            if(tone_type == SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            /* play DTMF, do not set play tone */
            if(tone_type != SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.current_DTMF_tone = tone_type;
            }
            else
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }

            if(callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_ID,result,tone_type,audio_id);
    return result;

}

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
 *  tone_type                 [IN]    requested tone type
 *  audio_data_ptr          [IN]    audio data memory pointer
 *  audio_data_format    [IN]    audio data format
 *  audio_data_len         [IN]    audio data length
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone_with_audio_data(srv_prof_tone_enum tone_type, 
                                                  U8* audio_data_ptr,
                                                  U8  audio_data_format,
                                                  U32 audio_data_len,
                                                  srv_prof_ring_type_enum play_style,
                                                  srv_prof_play_tone_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    mdi_result play_result = MDI_AUDIO_FAIL;
    srv_prof_volume_level volume;
    MMI_BOOL play_id = MMI_FALSE;
    srv_prof_play_audio_struct play_info;
    U8 aud_path = MDI_DEVICE_SPEAKER2;
    srv_prof_play_tone_callback tone_cb;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_FILE,SRV_PROF_RET_NOT_PLAY,tone_type);    
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(tone_type) != MMI_TRUE || tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_FILE,SRV_PROF_RET_NOT_PLAY,tone_type);
        return SRV_PROF_RET_NOT_PLAY;
    }

    /*check and swith to beep*/
    switch(tone_type)
    {
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_WAP_PUSH:
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        {
            if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
            {
                srv_prof_play_audio_info_init(&play_info, tone_type);
                play_info.audio_id = TONE_GENERAL_BEEP;
                play_info.play_style = SRV_PROF_RING_TYPE_BEEP_ONCE;
                play_id = MMI_TRUE;
            }
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        case SRV_PROF_TONE_ALARM:
        {
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        default:
            break;
    }

    /* callback preivous tone play about it is terminated by others */
    if(g_srv_prof.play_tone.tone_cb != NULL && !play_id)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_PLAY_FINISHED);
    }

    srv_prof_play_tone_switch_loudness(tone_type, MMI_TRUE);

    /*play file*/
    if(!play_id)
    {
        srv_prof_play_audio_set_paly_style(play_style);

        volume = srv_prof_play_audio_query_volume(tone_type);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(tone_type);
    #endif

        play_result = mdi_audio_play_string_with_vol_path(
                        audio_data_ptr,
                        audio_data_len,
                        audio_data_format,
                        g_srv_prof.play_tone.play_style,
                        srv_prof_play_audio_callback,
                        NULL,
                        MDI_AUD_VOL_MUTE(volume),
                        MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        /* try to recover */
        if(play_result != MDI_AUDIO_SUCCESS)
        {
            play_result = srv_prof_play_audio_fail_recover(tone_type, aud_path);
        }
        else
        {
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_DATA;
        }

    }
    /*play beep*/
    else
    {
        play_result = srv_prof_play_audio_id(play_info);
    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_id)
        {
            result = SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;
        }
        else
        {
            result = SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        result = SRV_PROF_RET_FAIL;
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = callback;
            }

            /* set current play tone */
            g_srv_prof.play_tone.current_tone = tone_type;
            g_srv_prof.play_tone.conflict_tone = tone_type;

            if(tone_type == SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            /* play DTMF, do not set play tone */
            if(tone_type != SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.current_DTMF_tone = tone_type;
            }
            else
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }

            if(callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_DATA,result,tone_type);

    return result;


}



/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_filepath
 * DESCRIPTION
 *  This function is for modules to play tone with a prepared file path.
 *  Profile service will check current status ot see if current request can be done.
 *  If the callback is not NULL, when mdi audio callback with events, profile
 *  service will callback with srv_prof_ret.
 *  
 *  When play fail for tone type which have profile setting, service will callback with
 *  SRV_PROF_RET_TRY_TO_RECOVER. If the return value is SRV_PROF_RET_YES, 
 *  service will try to recover with default tone. If not, service will end this play tone request.
 *
 * PARAMETERS
 *  tone_type     [IN]    requested tone type
 *  filepath      [IN]    file path to play
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone_with_filepath(srv_prof_tone_enum tone_type, 
                                              WCHAR* filepath,
                                              srv_prof_ring_type_enum play_style,
                                              srv_prof_play_tone_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    mdi_result play_result = MDI_AUDIO_FAIL;
    srv_prof_volume_level volume;
    MMI_BOOL play_id = MMI_FALSE;
    srv_prof_play_audio_struct play_info;
    U8 aud_path = MDI_DEVICE_SPEAKER2;
    srv_prof_play_tone_callback tone_cb;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_FILE,SRV_PROF_RET_NOT_PLAY,tone_type);    
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(tone_type) != MMI_TRUE || tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_FILE,SRV_PROF_RET_NOT_PLAY,tone_type);
        return SRV_PROF_RET_NOT_PLAY;
    }

    /*check and swith to beep*/
    switch(tone_type)
    {
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_WAP_PUSH:
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        {
            if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
            {
                srv_prof_play_audio_info_init(&play_info, tone_type);
                play_info.audio_id = TONE_GENERAL_BEEP;
                play_info.play_style = SRV_PROF_RING_TYPE_BEEP_ONCE;
                play_id = MMI_TRUE;
            }
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        case SRV_PROF_TONE_ALARM:
        {
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        default:
            break;
    }

    /* callback preivous tone play about it is terminated by others */
    if(g_srv_prof.play_tone.tone_cb != NULL && !play_id)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_PLAY_FINISHED);
    }

    srv_prof_play_tone_switch_loudness(tone_type, MMI_TRUE);

    /*play file*/
    if(!play_id)
    {
        srv_prof_play_audio_set_paly_style(play_style);


        volume = srv_prof_play_audio_query_volume(tone_type);

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(tone_type);
    #endif

        play_result = mdi_audio_play_file_portion_with_vol_path(
                        filepath,
                        0,
                        0,
                        g_srv_prof.play_tone.play_style,
                        NULL,
                        srv_prof_play_audio_callback,
                        NULL,
                        MDI_AUD_VOL_MUTE(volume),
                        MDI_AUD_PTH_EX(aud_path));

        g_srv_prof.play_tone.audio_path = aud_path;

        /* try to recover */
        if(play_result != MDI_AUDIO_SUCCESS)
        {
            play_result = srv_prof_play_audio_fail_recover(tone_type, aud_path);
        }
        else
        {
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_FILE;
        }

    }
    /*play beep*/
    else
    {
        play_result = srv_prof_play_audio_id(play_info);
    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_id)
        {
            result = SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;
        }
        else
        {
            result = SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        result = SRV_PROF_RET_FAIL;
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = callback;
            }

            /* set current play tone */
            g_srv_prof.play_tone.current_tone = tone_type;
            g_srv_prof.play_tone.conflict_tone = tone_type;

            if(tone_type == SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            /* play DTMF, do not set play tone */
            if(tone_type != SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.current_DTMF_tone = tone_type;
            }
            else
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }

            if(callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_FILE,result,tone_type);

    return result;


}

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
 *  tone_type     [IN]    requested tone type
 *  filepath      [IN]    file path to play
 * RETURNS
 *  srv_prof_ret      
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone_with_text(srv_prof_tone_enum tone_type, 
                                          U8* text,
                                          S32 text_speed,
                                          srv_prof_play_tone_callback callback)
{
#ifdef __GENERAL_TTS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    mdi_result play_result = MDI_AUDIO_FAIL;
    srv_prof_volume_level volume;
    MMI_BOOL play_id = MMI_FALSE;
    srv_prof_play_audio_struct play_info;
    U8 aud_path = MDI_DEVICE_SPEAKER2;
    srv_prof_play_tone_callback tone_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_TEXT,SRV_PROF_RET_NOT_PLAY,tone_type);    
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(tone_type) != MMI_TRUE || tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_TEXT,SRV_PROF_RET_NOT_PLAY,tone_type);
        return SRV_PROF_RET_NOT_PLAY;
    }

    /*check and swith to beep*/
    switch(tone_type)
    {
        case SRV_PROF_TONE_SMS:
        case SRV_PROF_TONE_SMS_CARD2:
        case SRV_PROF_TONE_SMS_CARD3:
        case SRV_PROF_TONE_SMS_CARD4:
        case SRV_PROF_TONE_MMS:
        case SRV_PROF_TONE_MMS_CARD2:
        case SRV_PROF_TONE_MMS_CARD3:
        case SRV_PROF_TONE_MMS_CARD4:
        case SRV_PROF_TONE_EMAIL:
        case SRV_PROF_TONE_EMAIL_CARD2:
        case SRV_PROF_TONE_EMAIL_CARD3:
        case SRV_PROF_TONE_EMAIL_CARD4:
        case SRV_PROF_TONE_VOICE:
        case SRV_PROF_TONE_VOICE_CARD2:
        case SRV_PROF_TONE_VOICE_CARD3:
        case SRV_PROF_TONE_VOICE_CARD4:
        case SRV_PROF_TONE_WAP_PUSH:
        case SRV_PROF_TONE_INCOMING_CALL:
        case SRV_PROF_TONE_INCOMING_CALL_CARD2:
        case SRV_PROF_TONE_INCOMING_CALL_CARD3:
        case SRV_PROF_TONE_INCOMING_CALL_CARD4:
        case SRV_PROF_TONE_VIDEO_CALL:
        case SRV_PROF_TONE_VIDEO_CALL_CARD2:
        case SRV_PROF_TONE_VIDEO_CALL_CARD3:
        case SRV_PROF_TONE_VIDEO_CALL_CARD4:
        {
            if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
            {
                srv_prof_play_audio_info_init(&play_info, tone_type);
                play_info.audio_id = TONE_GENERAL_BEEP;
                play_info.play_style = SRV_PROF_RING_TYPE_BEEP_ONCE;
                play_id = MMI_TRUE;
            }
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        case SRV_PROF_TONE_ALARM:
        {
            aud_path = MDI_DEVICE_SPEAKER_BOTH;
            break;
        }

        default:
            break;
    }

    /* callback preivous tone play about it is terminated by others */
    if(g_srv_prof.play_tone.tone_cb != NULL && !play_id)
    {
        tone_cb = g_srv_prof.play_tone.tone_cb;
        g_srv_prof.play_tone.tone_cb = NULL;
        tone_cb(SRV_PROF_RET_PLAY_FINISHED);
    }

    srv_prof_play_tone_switch_loudness(tone_type, MMI_TRUE);

    /*play file*/
    if(!play_id)
    {
        mdi_audio_tts_struct tts_play;

        /* set play style for recover case, currently always set to infinite */
        g_srv_prof.play_tone.play_style = DEVICE_AUDIO_PLAY_INFINITE;

        volume = srv_prof_play_audio_query_volume(tone_type);

        tts_play.text_string = (U16 *)text;
        tts_play.str_type = MDI_TTS_STR_TEXT;
        tts_play.lang = MDI_TTS_LANG_MDN;
        tts_play.app_type = MDI_TTS_TYPE_GENERAL;
        tts_play.gander = MDI_TTS_GENDER_FEMALE;
        tts_play.volume = MDI_AUD_VOL_MUTE(volume);
        tts_play.path = MDI_AUD_PTH_EX(aud_path);
        tts_play.pitch = 50;
        tts_play.speed = 50;    /*normal speed*/
        tts_play.callback = srv_prof_play_audio_callback;

    #ifdef __GAIN_TABLE_SUPPORT__
        srv_prof_play_audio_set_audio_type(tone_type);
    #endif
        
        play_result = mdi_audio_tts_play(tts_play);

        if(play_result == MDI_AUDIO_SUCCESS)
        {
            g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_TEXT;
        }

    }
    /*play beep*/
    else
    {
        play_result = srv_prof_play_audio_id(play_info);
    }

    if(play_result == MDI_AUDIO_SUCCESS)
    {
        if(play_id)
        {
            result = SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;
        }
        else
        {
            result = SRV_PROF_RET_SUCCESS;
        }
    }
    else
    {
        result = SRV_PROF_RET_FAIL;
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = callback;
            }

            /* set current play tone */
            g_srv_prof.play_tone.current_tone = tone_type;
            g_srv_prof.play_tone.conflict_tone = tone_type;

            if(tone_type == SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            /* play DTMF, do not set play tone */
            if(tone_type != SRV_PROF_TONE_KEYPAD)
            {
                g_srv_prof.play_tone.current_DTMF_tone = tone_type;
            }
            else
            {
                g_srv_prof.play_tone.key_playing = MMI_TRUE;
            }

            if(callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);
            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_TEXT,result,tone_type);

    return result;

#else

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_PLAY_TONE_TEXT,SRV_PROF_RET_NOT_PLAY,tone_type);    
    return SRV_PROF_RET_NOT_PLAY;

#endif /* __GENERAL_TTS__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_req_struct_init
 * DESCRIPTION
 *  This function is to init the play structure for playwith full struct
 *  The default values are shown as below.
 *    audio_id  : 0     (MUST revise again if play id)
 *    file_path : NULL  (MUST revise again if play file)
 *    audio_type: SRV_PROF_AUDIO_NONE (MUST revise according to play id or file)
 *    aud_path  : MDI_DEVICE_SPEAKER2
 *    callback  : NULL
 *    paly_style: SRV_PROF_RING_TYPE_REPEAT
 *    tone_type : tone_type
 *    volumn    : depends on tone type, for message kinds, the message volume are applied,
 *                otherwise, ring volume are applied.
 * PARAMETERS
 *  play_struct     [IN]    play struct to init
 *  tone_type       [IN]    tone type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prof_play_req_struct_init(srv_prof_play_req_struct* play_struct, srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    play_struct->audio_id = 0;
    play_struct->filepath = NULL;
    play_struct->text = NULL;
    play_struct->text_speed = 50;

    play_struct->audio_data_ptr = NULL;
    play_struct->audio_data_format = 0;
    play_struct->audio_data_len = 0;

    play_struct->audio_type = SRV_PROF_AUDIO_NONE;
    play_struct->aud_path = MDI_DEVICE_SPEAKER2;
    play_struct->callback = NULL;
    play_struct->play_style = SRV_PROF_RING_TYPE_REPEAT;
    play_struct->tone_type = tone_type;
    play_struct->volume = srv_prof_play_audio_query_volume(tone_type);

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_play_tone_with_full_struct
 * DESCRIPTION
 *  This function is for modules to play according to its own configure.
 *  Plz remember to use srv_prof_play_req_struct_init to initiate the configurations
 *  and update the audio_id / filepath and audio_type
 * PARAMETERS
 *  play_struct     [IN]    play structure
 * RETURNS
 * RETURNS
 *  srv_prof_ret
 *      SRV_PROF_RET_SUCCESS : play tone success and will have callback
 *      SRV_PROF_RET_NOT_PLAY : not play tone due to current setting and do not have callback
 *      SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK: play tone success but do not have callback (DTMF)
 *      SRV_PROF_RET_FAIL : play tone fail and do not have callback
 *****************************************************************************/
srv_prof_ret srv_prof_play_tone_with_full_struct(srv_prof_play_req_struct* play_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret result = SRV_PROF_RET_SUCCESS;
    mdi_result play_result = MDI_AUDIO_FAIL;
    srv_prof_play_tone_callback tone_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,
                MMI_PROF_SRV_TRC_PLAY_TONE_STRUCT,
                play_struct->tone_type,
                play_struct->audio_type,
                play_struct->audio_id,
                play_struct->play_style,
                play_struct->volume,
                play_struct->aud_path
                );

#ifdef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    if(g_srv_prof.play_tone.conflict_tone == play_struct->tone_type)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
        return SRV_PROF_RET_NOT_PLAY;
    }
#endif

    /* check profile setting */
    if(srv_prof_play_tone_setting_check(play_struct->tone_type) != MMI_TRUE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
        return SRV_PROF_RET_NOT_PLAY;
    }

    if( play_struct->audio_type == SRV_PROF_AUDIO_NONE || play_struct->tone_type == SRV_PROF_TONE_NONE)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);    
        return SRV_PROF_RET_NOT_PLAY;
    }

    if(g_srv_prof.cur_setting.ring_type == SRV_PROF_RING_TYPE_BEEP_ONCE)
    {
        switch(play_struct->tone_type)
        {
            case SRV_PROF_TONE_SMS:
            case SRV_PROF_TONE_SMS_CARD2:
            case SRV_PROF_TONE_SMS_CARD3:
            case SRV_PROF_TONE_SMS_CARD4:
            case SRV_PROF_TONE_MMS:
            case SRV_PROF_TONE_MMS_CARD2:
            case SRV_PROF_TONE_MMS_CARD3:
            case SRV_PROF_TONE_MMS_CARD4:
            case SRV_PROF_TONE_EMAIL:
            case SRV_PROF_TONE_EMAIL_CARD2:
            case SRV_PROF_TONE_EMAIL_CARD3:
            case SRV_PROF_TONE_EMAIL_CARD4:
            case SRV_PROF_TONE_VOICE:
            case SRV_PROF_TONE_VOICE_CARD2:
            case SRV_PROF_TONE_VOICE_CARD3:
            case SRV_PROF_TONE_VOICE_CARD4:
            case SRV_PROF_TONE_WAP_PUSH:
            case SRV_PROF_TONE_INCOMING_CALL:
            case SRV_PROF_TONE_INCOMING_CALL_CARD2:
            case SRV_PROF_TONE_INCOMING_CALL_CARD3:
            case SRV_PROF_TONE_INCOMING_CALL_CARD4:
            case SRV_PROF_TONE_VIDEO_CALL:
            case SRV_PROF_TONE_VIDEO_CALL_CARD2:
            case SRV_PROF_TONE_VIDEO_CALL_CARD3:
            case SRV_PROF_TONE_VIDEO_CALL_CARD4:
            {
                play_struct->audio_id = TONE_GENERAL_BEEP;
                play_struct->play_style = SRV_PROF_RING_TYPE_BEEP_ONCE;
                play_struct->audio_type = SRV_PROF_AUDIO_DTMF;
                break;
            }
            default:
                break;
        }
    }


    srv_prof_play_tone_switch_loudness(play_struct->tone_type, MMI_TRUE);

    switch(play_struct->audio_type)
    {
        case SRV_PROF_AUDIO_DTMF:
        case SRV_PROF_AUDIO_STRING:
        {
            srv_prof_play_audio_struct play_info;
            srv_prof_audio_id audio_id;

            /* in case the audio id passed in is the mapped audio id in nvram */
            audio_id = srv_prof_transform_audio_id_for_read_nvram(play_struct->audio_id);

            if(audio_id == SRV_PROF_TONE_SILENT && play_struct->tone_type != SRV_PROF_TONE_KEYPAD)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
                return SRV_PROF_RET_NOT_PLAY;
            }

            play_info.audio_id = audio_id;
            play_info.play_style = play_struct->play_style;
            play_info.aud_path = play_struct->aud_path;
            play_info.tone_type = play_struct->tone_type;
            play_info.volume = play_struct->volume;
            play_info.play_from_full_struct = MMI_TRUE;
            
            play_result = srv_prof_play_audio_id(play_info);

            if(play_result == MDI_AUDIO_SUCCESS)
            {
                if(play_info.audio_id <  MAX_TONE_ID)
                {
                    result = SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK;
                }
                else
                {
                    result = SRV_PROF_RET_SUCCESS;
                }
            }
            else
            {
                result = SRV_PROF_RET_FAIL;
            }
            
            break;
        }

        case SRV_PROF_AUDIO_DATA:
        {
            if(play_struct->audio_data_ptr == NULL || play_struct->audio_data_len == 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
                return SRV_PROF_RET_NOT_PLAY;            
            }

            srv_prof_play_audio_set_paly_style(play_struct->play_style);

            /* callback preivous tone play about it is terminated by others */
            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                tone_cb = g_srv_prof.play_tone.tone_cb;
                g_srv_prof.play_tone.tone_cb = NULL;
                tone_cb(SRV_PROF_RET_PLAY_FINISHED);
            }
        
        #ifdef __GAIN_TABLE_SUPPORT__
            srv_prof_play_audio_set_audio_type(play_struct->tone_type);
        #endif

            play_result = mdi_audio_play_string_with_vol_path(
                            play_struct->audio_data_ptr,
                            play_struct->audio_data_len,
                            play_struct->audio_data_format,
                            g_srv_prof.play_tone.play_style,
                            srv_prof_play_audio_callback,
                            NULL,
                            MDI_AUD_VOL_MUTE(play_struct->volume),
                            MDI_AUD_PTH_EX(play_struct->aud_path));
                
            g_srv_prof.play_tone.audio_path = play_struct->aud_path;
        
            /* try to recover */
            if(play_result != MDI_AUDIO_SUCCESS)
            {
                play_result = srv_prof_play_audio_fail_recover(play_struct->tone_type, play_struct->aud_path);
            }
            else
            {
                g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_DATA;
            }
        
            if(play_result == MDI_AUDIO_SUCCESS)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            else
            {
                result = SRV_PROF_RET_FAIL;
            }
        
            break;
        }

        case SRV_PROF_AUDIO_FILE:
        {

            if(play_struct->filepath == NULL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
                return SRV_PROF_RET_NOT_PLAY;            
            }

            srv_prof_play_audio_set_paly_style(play_struct->play_style);


            /* callback preivous tone play about it is terminated by others */
            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                tone_cb = g_srv_prof.play_tone.tone_cb;
                g_srv_prof.play_tone.tone_cb = NULL;
                tone_cb(SRV_PROF_RET_PLAY_FINISHED);
            }

        #ifdef __GAIN_TABLE_SUPPORT__
            srv_prof_play_audio_set_audio_type(play_struct->tone_type);
        #endif

            play_result = mdi_audio_play_file_portion_with_vol_path(
                            play_struct->filepath,
                            0,
                            0,
                            g_srv_prof.play_tone.play_style,
                            NULL,
                            srv_prof_play_audio_callback,
                            NULL,
                            MDI_AUD_VOL_MUTE(play_struct->volume),
                            MDI_AUD_PTH_EX(play_struct->aud_path));

            g_srv_prof.play_tone.audio_path = play_struct->aud_path;

            /* try to recover */
            if(play_result != MDI_AUDIO_SUCCESS)
            {
                play_result = srv_prof_play_audio_fail_recover(play_struct->tone_type, play_struct->aud_path);
            }
            else
            {
                g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_FILE;
            }

            if(play_result == MDI_AUDIO_SUCCESS)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            else
            {
                result = SRV_PROF_RET_FAIL;
            }

            break;
        }

        case SRV_PROF_AUDIO_TEXT:
        {
        #if __GENERAL_TTS__
            mdi_audio_tts_struct tts_play;

            if(play_struct->text == NULL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
                return SRV_PROF_RET_NOT_PLAY;
            }

            srv_prof_play_audio_set_paly_style(play_struct->play_style);


            /* callback preivous tone play about it is terminated by others */
            if(g_srv_prof.play_tone.tone_cb != NULL)
            {
                tone_cb = g_srv_prof.play_tone.tone_cb;
                g_srv_prof.play_tone.tone_cb = NULL;
                tone_cb(SRV_PROF_RET_PLAY_FINISHED);
            }
        
            tts_play.text_string = (U16 *)play_struct->text;
            tts_play.str_type = MDI_TTS_STR_TEXT;
            tts_play.lang = MDI_TTS_LANG_MDN;
            tts_play.app_type = MDI_TTS_TYPE_GENERAL;
            tts_play.gander = MDI_TTS_GENDER_FEMALE;
            tts_play.volume = MDI_AUD_VOL_MUTE(play_struct->volume);
            tts_play.path = MDI_AUD_PTH_EX(play_struct->aud_path);
            tts_play.pitch = 50;
            tts_play.speed = play_struct->text_speed;
            tts_play.callback = srv_prof_play_audio_callback;
        
        #ifdef __GAIN_TABLE_SUPPORT__
            srv_prof_play_audio_set_audio_type(play_struct->tone_type);
        #endif
            
            play_result = mdi_audio_tts_play(tts_play);

            g_srv_prof.play_tone.audio_path = play_struct->aud_path;

            /* try to recover */
            if(play_result != MDI_AUDIO_SUCCESS)
            {
                play_result = srv_prof_play_audio_fail_recover(play_struct->tone_type, play_struct->aud_path);
            }
            else
            {
                g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_TEXT;
            }

            if(play_result == MDI_AUDIO_SUCCESS)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            else
            {
                result = SRV_PROF_RET_FAIL;
            }
            break;

        #else

            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,SRV_PROF_RET_NOT_PLAY);
            return SRV_PROF_RET_NOT_PLAY;

        #endif /* __GENERAL_TTS__ */
        }
    }

    switch(result)
    {
        case SRV_PROF_RET_SUCCESS:
        {
            /* register callback */
            if(play_struct->callback != NULL)
            {
                g_srv_prof.play_tone.tone_cb = play_struct->callback;
            }

            /* set current play tone */
            g_srv_prof.play_tone.current_tone = play_struct->tone_type;
            g_srv_prof.play_tone.conflict_tone = play_struct->tone_type;
            break;
        }

        case SRV_PROF_RET_PLAY_SUCCESS_WO_CALLBACK:
        {
            g_srv_prof.play_tone.current_DTMF_tone = play_struct->tone_type;

            if(play_struct->callback == NULL)
            {
                result = SRV_PROF_RET_SUCCESS;
            }
            break;
        }

        default:
        {
            srv_prof_play_tone_switch_loudness(play_struct->tone_type, MMI_FALSE);

            break;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_RESULT,result);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_profiles_stop_tone
 * DESCRIPTION
 *  This function is to stop the requested tone which is requested to play before.
 * PARAMETERS
 *  tone_type     [IN]    requested tone type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_profiles_stop_tone(srv_prof_tone_enum tone_type)
{
    srv_prof_stop_tone(tone_type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_stop_key_tone
 * DESCRIPTION
 *  This function is to stop key tone
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_prof_stop_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_srv_prof.play_tone.key_playing)
    {
        switch(g_srv_prof.play_tone.key_audio_type)
        {
            case SRV_PROF_AUDIO_DTMF:
            {
                mdi_audio_stop_id(TONE_KEY_CLICK);
                break;
            }

            case SRV_PROF_AUDIO_STRING:
            {
                /* to avoid callback again */
                g_srv_prof.play_tone.tone_cb = NULL;
                mdi_audio_stop_string();
                break;
            }

            default:
                break;
        }
    }

    g_srv_prof.play_tone.key_playing = MMI_FALSE;
    g_srv_prof.play_tone.key_audio_type = SRV_PROF_AUDIO_NONE;

    /*when key tone is playing with non-DTMF, current tone will also be keypad*/
    if(g_srv_prof.play_tone.current_tone == SRV_PROF_TONE_KEYPAD)
    {
        g_srv_prof.play_tone.current_tone = SRV_PROF_TONE_NONE;
        g_srv_prof.play_tone.conflict_tone = SRV_PROF_TONE_NONE;
        g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_stop_tone
 * DESCRIPTION
 *  This function is to stop the requested tone which is requested to play before.
 * PARAMETERS
 *  tone_type     [IN]    requested tone type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prof_stop_tone(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_STOP_TONE,tone_type,g_srv_prof.play_tone.current_tone, g_srv_prof.play_tone.current_DTMF_tone);

    if(tone_type != g_srv_prof.play_tone.current_tone && tone_type != g_srv_prof.play_tone.current_DTMF_tone && tone_type != SRV_PROF_TONE_KEYPAD)
    {
        return;
    }

    if(tone_type == SRV_PROF_TONE_KEYPAD)
    {
        srv_prof_stop_key_tone();
        return;
    }

    if(tone_type == g_srv_prof.play_tone.current_DTMF_tone)
    {
        mdi_audio_stop_id(TONE_GENERAL_BEEP);
        g_srv_prof.play_tone.current_DTMF_tone = SRV_PROF_TONE_NONE;
        srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);

        /* stop both tone if needed */
        if(tone_type != g_srv_prof.play_tone.current_tone)
        {
            return;
        }
    }

    /*non DTMF*/
    g_srv_prof.play_tone.tone_cb = NULL;

    switch(g_srv_prof.play_tone.audio_type)
    {
        case SRV_PROF_AUDIO_TEXT:
        {
        #ifdef __GENERAL_TTS__
            mdi_audio_tts_stop();
        #endif
            break;
        }
    
        case SRV_PROF_AUDIO_STRING:
        {
            mdi_audio_stop_string();
            break;
        }

        case SRV_PROF_AUDIO_FILE:
        {
            mdi_audio_stop_file();
            break;
        }

        default:
            break;
    }

    g_srv_prof.play_tone.current_tone = SRV_PROF_TONE_NONE;
    g_srv_prof.play_tone.conflict_tone = SRV_PROF_TONE_NONE;
    g_srv_prof.play_tone.audio_type = SRV_PROF_AUDIO_NONE;

    srv_prof_play_tone_switch_loudness(tone_type, MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_app_playing
 * DESCRIPTION
 *  This function is to check if there is any application playing currently
 *  
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_prof_is_app_playing(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_evt_mute_struct evt;
    mmi_ret result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_PROF_IS_PLAYING);
    result = MMI_FRM_CB_EMIT_EVENT(&evt);

    if(result != MMI_RET_OK)
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
 *  srv_prof_is_tone_playing
 * DESCRIPTION
 *  This function is to check if the tone_type is crrently playing
 *  Only checks for non DTMF tone, since we are not able to track DTMF status
 * PARAMETERS
 *  tone_type     [IN]    query tone type
 * RETURNS
 *  MMI_BOOL      MMI_TRUE : tone_type is playing
 *                MMI_FALSE : tone_type is not playing
 *****************************************************************************/
MMI_BOOL srv_prof_is_tone_playing(srv_prof_tone_enum tone_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(tone_type == g_srv_prof.play_tone.conflict_tone)
    {
        result = MMI_TRUE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_IS_TONE_PLAYING,tone_type,result);

    return result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_audio_id_available
 * DESCRIPTION
 *  This function is to check if audio file of the audio id still exists
 *  including external melody, theme tone ... etc.
 * PARAMETERS
 *  audio_id     [IN]    audio id to query
 * RETURNS
 *  MMI_BOOL      MMI_TRUE : audio id still exists
 *                MMI_FALSE : audio id does not exist anymore
 *****************************************************************************/
MMI_BOOL srv_prof_is_audio_id_available(srv_prof_audio_id audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
    /*Externl melody*/
    if(audio_id > AUD_ID_PROF_EXT_BEGIN && audio_id < AUD_ID_PROF_EXT_END)
    {
        FS_HANDLE file_hd;
        file_hd = FS_GetAttributes((U16*)g_srv_prof.ext_melody.info[audio_id-AUD_ID_PROF_EXT1].filefullpath);
        if (file_hd < 0)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
#endif

    /*Tone*/
    if(audio_id > AUD_ID_PROF_TONE_BEGIN && audio_id < AUD_ID_PROF_TONE_END)
    {
        return MMI_TRUE;
    }

    /*Ring*/
    if(audio_id > AUD_ID_PROF_RING_BEGIN && audio_id < AUD_ID_PROF_RING_END)
    {
        return MMI_TRUE;
    }

    /*DTMF*/
    if(audio_id < MAX_TONE_ID)
    {
        return MMI_TRUE;
    }
    
    /*Theme tone*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {
        WCHAR file_path[SRV_FMGR_PATH_MAX_LEN+1];
        FS_HANDLE file_hd;
        if(GetAudioNameWithPathInFileSystem(audio_id, (CHAR*)file_path) != NULL)
        {
            file_hd = FS_Open((PU16)file_path, FS_READ_ONLY);
            if (file_hd >= FS_NO_ERROR)
            {
                FS_Close(file_hd);
                return MMI_TRUE;
            }
        }
    }    
#endif

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_reset_tone_with_audio_id
 * DESCRIPTION
 *  This function is for other modules to reset a specific tone to default. This will apply to 
 *  all profiles. ex: MMI Theme is deleted, so it needs to reset all incoming call tone which
 *  are set as theme tone (the audio_id input) to default.
 * 
 *  Currenlty only support call realted tones
 *
 * PARAMETERS
 *  tone_setting    [IN]    tone setting item (ex: SRV_PROF_SETTINGS_MT_CALL_TONE)
 *  audio_id        [IN]    audio_id for check and reset
 * RETURNS
 *  srv_prof_ret_enum
 *      SRV_PROF_RET_SUCCESS : reset tone success
 *      SRV_PROF_RET_SETTING_NOT_SUPPORTED : setting is not supported in current profile service
 *      SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
srv_prof_ret srv_prof_reset_tone_with_audio_id(srv_prof_settings_enum tone_setting, srv_prof_audio_id audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cont;
    srv_prof_setting_struct* temp_setting;
    nvram_srv_prof_setting_struct* default_setting;
    MMI_BOOL need_store;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_RESET_TONE_WITH_ID,tone_setting,audio_id);

    //default_setting = (nvram_srv_prof_setting_struct*)get_ctrl_buffer(sizeof(nvram_srv_prof_setting_struct));

    //ASSERT(default_setting != NULL);

    for(cont=1 ; cont < SRV_PROF_PROFILES_TOTAL_NUM+1 ; cont++)
    {
        need_store = MMI_FALSE;

        if(cont != g_srv_prof.cur_prof)
        {
            if(IsMyTimerExist(SRV_PROF_STORE_BUF_TIMER))
            {
                StopTimer(SRV_PROF_STORE_BUF_TIMER);
                srv_prof_store_buf_setting_timeout();
            }
            srv_prof_read_nvram_to_setting((srv_prof_internal_profile_enum)cont,&g_srv_prof.buf_setting);
            temp_setting = &g_srv_prof.buf_setting;
            g_srv_prof.buf_prof = cont;
        }
        else
        {
            temp_setting = &g_srv_prof.cur_setting;
        }

        nvram_get_default_value(NVRAM_EF_SRV_PROF_SETTING_LID, cont, (kal_uint8**)&default_setting);

        switch(tone_setting)
        {
            case SRV_PROF_SETTINGS_MT_CALL_TONE:
            {
                if(temp_setting->mt_call_tone[0] == audio_id)
                {
                    temp_setting->mt_call_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[0]);
                    need_store = MMI_TRUE;
                }
                break;
            }

        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
            case SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE:
            {
                if(temp_setting->mt_call_tone[1] == audio_id)
                {
                    temp_setting->mt_call_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[1]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
            case SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE:
            {
                if(temp_setting->mt_call_tone[2] == audio_id)
                {
                    temp_setting->mt_call_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[2]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif
        #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
            case SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE:
            {
                if(temp_setting->mt_call_tone[3] == audio_id)
                {
                    temp_setting->mt_call_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[3]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
            case SRV_PROF_SETTINGS_VT_CALL_TONE:
            {
                if(temp_setting->vt_call_tone[0] == audio_id)
                {
                    temp_setting->vt_call_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[0]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1)
            case SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE:
            {
                if(temp_setting->vt_call_tone[1] == audio_id)
                {
                    temp_setting->vt_call_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[1]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 2)
            case SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE:
            {
                if(temp_setting->vt_call_tone[2] == audio_id)
                {
                    temp_setting->vt_call_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[2]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif
        #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 3)
            case SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE:
            {
                if(temp_setting->vt_call_tone[3] == audio_id)
                {
                    temp_setting->vt_call_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[3]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

            case SRV_PROF_SETTINGS_SMS_TONE:
            {
                if(temp_setting->sms_tone[0] == audio_id)
                {
                    temp_setting->sms_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[0]);
                    need_store = MMI_TRUE;
                }
                break;
            }

        #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
            case SRV_PROF_SETTINGS_SMS_CARD2_TONE:
            {
                if(temp_setting->sms_tone[1] == audio_id)
                {
                    temp_setting->sms_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[1]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
            case SRV_PROF_SETTINGS_SMS_CARD3_TONE:
            {
                if(temp_setting->sms_tone[2] == audio_id)
                {
                    temp_setting->sms_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[2]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
            case SRV_PROF_SETTINGS_SMS_CARD4_TONE:
            {
                if(temp_setting->sms_tone[3] == audio_id)
                {
                    temp_setting->sms_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[3]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
            case SRV_PROF_SETTINGS_EMAIL_TONE:
            {
                if(temp_setting->email_tone[0] == audio_id)
                {
                    temp_setting->email_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[0]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
            case SRV_PROF_SETTINGS_EMAIL_CARD2_TONE:
            {
                if(temp_setting->email_tone[1] == audio_id)
                {
                    temp_setting->email_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[1]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 2)
            case SRV_PROF_SETTINGS_EMAIL_CARD3_TONE:
            {
                if(temp_setting->email_tone[2] == audio_id)
                {
                    temp_setting->email_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[2]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

        #if (SRV_PROF_EMAIL_TONE_AMOUNT > 3)
            case SRV_PROF_SETTINGS_EMAIL_CARD4_TONE:
            {
                if(temp_setting->email_tone[3] == audio_id)
                {
                    temp_setting->email_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[3]);
                    need_store = MMI_TRUE;
                }
                break;
            }
        #endif

            default:
            {
                return SRV_PROF_RET_SETTING_NOT_SUPPORTED;
            }
        }

        if(need_store)
        {
            srv_prof_write_nvram_from_setting((srv_prof_internal_profile_enum)cont,temp_setting);
        }
    }

    //if(default_setting != NULL)
    //{
    //    free_ctrl_buffer(default_setting);
    //}

    return SRV_PROF_RET_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_reset_deleted_audio_id
 * DESCRIPTION
 *  This function is to reset all tones to default if it is set to audio_id (external melody)
 *
 * PARAMETERS
 *  audio_id        [IN]    audio_id for check and reset
 * RETURNS
 *  srv_prof_ret_enum
 *      SRV_PROF_RET_SUCCESS : reset tone success
 *      SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
static srv_prof_ret srv_prof_reset_deleted_audio_id(srv_prof_audio_id audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 cont;
    srv_prof_setting_struct* settings = NULL;
    srv_prof_setting_struct* temp_setting;
    nvram_srv_prof_setting_struct* default_setting;
    MMI_BOOL need_store;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_RESET_DELETED_ID,audio_id);

    settings = (srv_prof_setting_struct*)get_ctrl_buffer(sizeof(srv_prof_setting_struct)*SRV_PROF_PROFILES_TOTAL_NUM);

    ASSERT(settings != NULL);

    srv_prof_read_nvram_to_setting_all(settings);

    for(cont=1 ; cont <= SRV_PROF_PROFILES_TOTAL_NUM ; cont++)
    {
        need_store = MMI_FALSE;

        if(cont == g_srv_prof.cur_prof)
        {
            temp_setting = &g_srv_prof.cur_setting;
        }
        else if(cont == g_srv_prof.buf_prof)
        {
            temp_setting = &g_srv_prof.buf_setting;
        }
        else
        {
            temp_setting = &settings[cont-1];     
        }

        nvram_get_default_value(NVRAM_EF_SRV_PROF_SETTING_LID, cont, (kal_uint8**)&default_setting);

    #ifndef __MMI_POWER_ON_OFF_MUTE__
        if(temp_setting->power_on_tone == audio_id)
        {
            temp_setting->power_on_tone = srv_prof_transform_audio_id_for_read_nvram(default_setting->power_on_tone);
            need_store = MMI_TRUE;
        }
        if(temp_setting->power_off_tone == audio_id)
        {
            temp_setting->power_on_tone = srv_prof_transform_audio_id_for_read_nvram(default_setting->power_off_tone);
            need_store = MMI_TRUE;
        }
    #endif

    #ifdef __MMI_CLAMSHELL__
        if(temp_setting->cover_open_tone == audio_id)
        {
            temp_setting->cover_open_tone = srv_prof_transform_audio_id_for_read_nvram(default_setting->cover_open_tone);
            need_store = MMI_TRUE;
        }
        if(temp_setting->cover_close_tone == audio_id)
        {
            temp_setting->cover_close_tone = srv_prof_transform_audio_id_for_read_nvram(default_setting->cover_close_tone);
            need_store = MMI_TRUE;
        }
    #endif
        if(temp_setting->sms_tone[0] == audio_id)
        {
            temp_setting->sms_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[0]);
            need_store = MMI_TRUE;
        }
    #if (SRV_PROF_SMS_TONE_AMOUNT > 1)
        if(temp_setting->sms_tone[1] == audio_id)
        {
            temp_setting->sms_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_SMS_TONE_AMOUNT > 2)
        if(temp_setting->sms_tone[2] == audio_id)
        {
            temp_setting->sms_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_SMS_TONE_AMOUNT > 3)
        if(temp_setting->sms_tone[3] == audio_id)
        {
            temp_setting->sms_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->sms_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif

    #if (SRV_PROF_MMS_TONE_AMOUNT > 0)
        if(temp_setting->mms_tone[0] == audio_id)
        {
            temp_setting->mms_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mms_tone[0]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_MMS_TONE_AMOUNT > 1)    
        if(temp_setting->mms_tone[1] == audio_id)
        {
            temp_setting->mms_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mms_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_MMS_TONE_AMOUNT > 2)
        if(temp_setting->mms_tone[2] == audio_id)
        {
            temp_setting->mms_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mms_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_MMS_TONE_AMOUNT > 3)
        if(temp_setting->mms_tone[3] == audio_id)
        {
            temp_setting->mms_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mms_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif
  
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 0)
        if(temp_setting->email_tone[0] == audio_id)
        {
            temp_setting->email_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[0]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 1)
        if(temp_setting->email_tone[1] == audio_id)
        {
            temp_setting->email_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 2)
        if(temp_setting->email_tone[2] == audio_id)
        {
            temp_setting->email_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_EMAIL_TONE_AMOUNT > 3)
        if(temp_setting->email_tone[3] == audio_id)
        {
            temp_setting->email_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->email_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif

    #if (SRV_PROF_VOICE_TONE_AMOUNT > 0)
        if(temp_setting->voice_tone[0] == audio_id)
        {
            temp_setting->voice_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->voice_tone[0]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 1)
        if(temp_setting->voice_tone[1] == audio_id)
        {
            temp_setting->voice_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->voice_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 2)
        if(temp_setting->voice_tone[2] == audio_id)
        {
            temp_setting->voice_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->voice_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VOICE_TONE_AMOUNT > 3)
        if(temp_setting->voice_tone[3] == audio_id)
        {
            temp_setting->voice_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->voice_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif

        if(temp_setting->mt_call_tone[0] == audio_id)
        {
            temp_setting->mt_call_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[0]);
            need_store = MMI_TRUE;
        }
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 1)
        if(temp_setting->mt_call_tone[1] == audio_id)
        {
            temp_setting->mt_call_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 2)
        if(temp_setting->mt_call_tone[2] == audio_id)
        {
            temp_setting->mt_call_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_MT_CALL_TONE_AMOUNT > 3)
        if(temp_setting->mt_call_tone[3] == audio_id)
        {
            temp_setting->mt_call_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->mt_call_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif

    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 0)
        if(temp_setting->vt_call_tone[0] == audio_id)
        {
            temp_setting->vt_call_tone[0] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[0]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1)
        if(temp_setting->vt_call_tone[1] == audio_id)
        {
            temp_setting->vt_call_tone[1] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[1]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 2)
        if(temp_setting->vt_call_tone[2] == audio_id)
        {
            temp_setting->vt_call_tone[2] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[2]);
            need_store = MMI_TRUE;
        }
    #endif
    #if (SRV_PROF_VT_CALL_TONE_AMOUNT > 3)
        if(temp_setting->vt_call_tone[3] == audio_id)
        {
            temp_setting->vt_call_tone[3] = srv_prof_transform_audio_id_for_read_nvram(default_setting->vt_call_tone[3]);
            need_store = MMI_TRUE;
        }
    #endif

        if(need_store)
        {
            srv_prof_write_nvram_from_setting((srv_prof_internal_profile_enum)cont,temp_setting);
        }

    }

    if(settings != NULL)
    {
        free_ctrl_buffer(settings);
    }

    return SRV_PROF_RET_SUCCESS;
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_prof_delete_file_update_hdlr
 * DESCRIPTION
 *  This function is to update tone setting when file is deleted from other module.
 * 
 * PARAMETERS
 *  del_path        [IN]    file path which has been deleted
 *  del_type        [IN]    type of deletion (ex: SRV_PROF_DEL_FILE)
 * RETURNS
 *  srv_prof_ret_enum
 *      SRV_PROF_RET_SUCCESS : update success
 *      SRV_PROF_RET_FAIL : other errors
 *****************************************************************************/
srv_prof_ret srv_prof_delete_file_update_hdlr(WCHAR* del_path, srv_prof_del_type_enum del_type)
{
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__

    U8 cont;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_DELETE_FILE_UPDATE,del_type,g_srv_prof.ext_melody.valid_bit);

    if(g_srv_prof.ext_melody.valid_bit == 0)
    {
        return SRV_PROF_RET_SUCCESS;
    }

    switch (del_type)
    {
        case SRV_PROF_DEL_FILE:
        {
            for(cont=0 ; cont< SRV_PROF_EXT_MELODY_NUM ; cont++)
            {
                if(SRV_PROF_BIT_TEST(g_srv_prof.ext_melody.valid_bit,cont) == 0)
                {
                    continue;
                }

                if( mmi_ucs2cmp((const CHAR*)g_srv_prof.ext_melody.info[cont].filefullpath, (const CHAR*)del_path) == 0)
                {
                    srv_prof_reset_deleted_audio_id(AUD_ID_PROF_EXT1+cont);
                }
            }

            break;
        }

        case SRV_PROF_DEL_FOLDER:
        {
            U8 cont;
            S32 len1, len2;
            CHAR* path;

            /* check deleted file path */
            len1 = mmi_ucs2strlen((const CHAR*)del_path);
            
            for (cont=0 ; cont < SRV_PROF_EXT_MELODY_NUM ; cont++)
            {
                if(SRV_PROF_BIT_TEST(g_srv_prof.ext_melody.valid_bit,cont) == 0)
                {
                    continue;
                }

                path = (CHAR*) g_srv_prof.ext_melody.info[cont].filefullpath;

                len2 = mmi_ucs2strlen((const CHAR*)path);

                if(len1 > len2)
                {
                    continue;
                }

                /* compare folder path */
                if(mmi_ucs2ncmp((const CHAR*)del_path, path, len1) == 0)
                {
                    if(!srv_prof_is_audio_id_available(AUD_ID_PROF_EXT1+cont))
                    {
                        srv_prof_reset_deleted_audio_id(AUD_ID_PROF_EXT1+cont);
                    }
                }
            }
            break;
        }
        default:
            return SRV_PROF_RET_FAIL;

    }
#endif

    return SRV_PROF_RET_SUCCESS;


}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_get_file_path_by_audio_id
 * DESCRIPTION
 *  This function is to get file path (external file) with audio id
 * 
 * PARAMETERS
 *  path_buf        [OUT]   file path of request audio id
 *  audio_id        [IN]    audio id to query
 * RETURNS
 *  srv_prof_ret_enum
 *      SRV_PROF_RET_SUCCESS : success
 *      SRV_PROF_RET_FAIL : other errors (ex: audio id not in the correct range)
 *****************************************************************************/
srv_prof_ret srv_prof_get_file_path_by_audio_id(WCHAR* path_buf, srv_prof_audio_id audio_id)
{
#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__

    U8 slot;

    if(audio_id <= AUD_ID_PROF_EXT_BEGIN || audio_id >= AUD_ID_PROF_EXT_END)
    {
        return SRV_PROF_RET_FAIL;
    }
    slot = audio_id - AUD_ID_PROF_EXT1 ;

    if(SRV_PROF_BIT_TEST(g_srv_prof.ext_melody.valid_bit,slot) == 0)
    {
        return SRV_PROF_RET_FAIL;
    }

    ASSERT(path_buf != NULL);

    memcpy(path_buf, &g_srv_prof.ext_melody.info[slot], sizeof(srv_prof_ext_melody_info_struct));

    return SRV_PROF_RET_SUCCESS;

#else

    return SRV_PROF_RET_FAIL;

#endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_is_profile_activated
 * DESCRIPTION
 *  This function is to check if a specific profile is currently activated.
 *  If there is no such profile cofigured for profile service, the return
 *  value will be SRV_PROF_RET_PROFILE_NOT_SUPPORTED.
 * PARAMETERS
 *  profile     [IN]    profile enum to be checked
 * RETURNS
 *  srv_profiles_ret_enum
 *      SRV_PROF_RET_PROFILE_ACTIVATED     : profile activated
 *      SRV_PROF_RET_PROFILE_NOT_ACTIVATED : profile not activated
 *      SRV_PROF_RET_PROFILE_NOT_SUPPORTED : profile is not supported in current profile service
 *****************************************************************************/
srv_prof_ret srv_prof_is_profile_activated(srv_prof_external_profile_enum profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_IS_PROFILE_ACTIVATED,profile,g_srv_prof.cur_prof);

    /* Currently not support headset and bluetooth profile*/
    if(profile == SRV_PROF_HEADSET_MODE || profile == SRV_PROF_BLUETOOTH_MODE)
    {
        return SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
    }

    if(profile == SRV_PROF_SILENT_MODE)
    {
        if(SRV_PROF_SUPPORT_SILENT_MODE == FALSE)
        {
            return SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
        }

        if(g_srv_prof.cur_prof == SRV_PROF_SILENT_MODE_NUM)
        {
            return SRV_PROF_RET_PROFILE_ACTIVATED;
        }
        else
        {
            return SRV_PROF_RET_PROFILE_NOT_ACTIVATED;
        }
    }

    if(profile == SRV_PROF_MEETING_MODE)
    {
        if(SRV_PROF_SUPPORT_MEETING_MODE == FALSE)
        {
            return SRV_PROF_RET_PROFILE_NOT_SUPPORTED;
        }
        else
        {
            if(g_srv_prof.cur_prof == SRV_PROF_MEETING_MODE_NUM)
            {
                return SRV_PROF_RET_PROFILE_ACTIVATED;
            }
            else
            {
                return SRV_PROF_RET_PROFILE_NOT_ACTIVATED;
            }
        }
    }

    return SRV_PROF_RET_PROFILE_NOT_SUPPORTED;

}


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
MMI_BOOL srv_prof_if_can_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL can_vibrate = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_IF_CAN_VIBRATE,g_srv_prof.cur_setting.alert_type,g_srv_prof.cur_setting.vibrate);

#ifndef __COSMOS_MMI_PACKAGE__
    if(g_srv_prof.cur_setting.alert_type != SRV_PROF_ALERT_TYPE_RING && g_srv_prof.cur_setting.alert_type != SRV_PROF_ALERT_TYPE_SILENT)
    {
        can_vibrate = MMI_TRUE;
    }
#else
    if(g_srv_prof.cur_setting.vibrate)
    {
        can_vibrate = MMI_TRUE;
    }
#endif

    return can_vibrate;

}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_if_can_ring
 * DESCRIPTION
 *  This function will tell the caller if he shall ring based on current 
 *  profile's setting.
 *  In plutommi profile app, we will check alert type and
 *  reutrns MMI_TRUE if the setting is not SRV_PROF_ALERT_TYPE_VIB_ONLY. 
 *  Please be aware that in plutommi, this is only for users who is intersted
 *  in alert type setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_prof_if_can_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL can_ring = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_PROF_SRV_TRC_IF_CAN_RING,g_srv_prof.cur_setting.alert_type,g_srv_prof.cur_setting.noti_sound);

#ifndef __COSMOS_MMI_PACKAGE__
    if(g_srv_prof.cur_setting.alert_type != SRV_PROF_ALERT_TYPE_VIB_ONLY && g_srv_prof.cur_setting.alert_type != SRV_PROF_ALERT_TYPE_SILENT)
    {
        can_ring = MMI_TRUE;
    }
#else
    if(g_srv_prof.cur_setting.noti_sound)
    {
        can_ring = MMI_TRUE;
    }
#endif

    return can_ring;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_earphone_plugin_hdlr
 * DESCRIPTION
 *  This function is for other modules to inform profile service of earphone
 *  plug in event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 
mmi_ret srv_prof_earphone_plugin_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_EARPHONE_IN);

    if(g_srv_prof.is_inited)
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);

        srv_speech_set_mode_volume();

    #ifdef __MMI_BT_AUDIO_SUPPORT__
        srv_btsco_switch_profile_path(MMI_FALSE);
     #endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_earphone_plugout_hdlr
 * DESCRIPTION
 *  This function is for other modules to inform profile service of earphone 
 *  plug out event.
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_prof_earphone_plugout_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_EARPHONE_OUT);

    if(g_srv_prof.is_inited)
    {

    #ifdef __MMI_BT_AUDIO_SUPPORT__
        srv_btsco_switch_profile_path(MMI_TRUE);
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

        if (mdi_audio_get_audio_mode() != AUD_MODE_LOUDSPK)
        {
            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
            srv_speech_set_mode_volume();
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_bt_connected_hdlr
 * DESCRIPTION
 *  This function is for BTCM to inform profile service of bt connected.
 * PARAMETERS
 *  connect_type    [IN]    connect type (ex: ACL/SCO)
 *  callback_type   [IN]    callback type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prof_bt_connected_hdlr(srv_prof_bt_connect_type_enum connect_type, srv_prof_bt_cb_type_enum callback_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_BT_CONNECT,connect_type,callback_type);

    switch (connect_type)
    {
    #ifdef __MMI_BT_AUDIO_SUPPORT__
        case SRV_PROF_BT_HFP_ACL:
        {
            if (callback_type == SRV_PROF_BT_IND || callback_type == SRV_PROF_BT_RSP)
            { 
                srv_btsco_hfp_connect_callback(callback_type);
            }
            break;
        }
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

        default:
            break;
    }


}


/*****************************************************************************
 * FUNCTION
 *  srv_prof_notify_hdlr
 * DESCRIPTION
 *  This function is to handle all the notification manager's events
 *  
 * PARAMETERS
 *  mmi_event_struct    [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/ 
mmi_ret srv_prof_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {

        case EVT_ID_GPIO_EARPHONE_PLUG_IN:
        {
            return srv_prof_earphone_plugin_hdlr(evt);
        }

        case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
        {
            return srv_prof_earphone_plugout_hdlr(evt);
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *adv_action;
            SRV_FMGR_FILEINFO_HANDLE file_info_handle;
            MMI_BOOL is_folder;
            srv_prof_del_type_enum del_type = SRV_PROF_DEL_FILE;

            adv_action = (srv_fmgr_notification_adv_action_event_struct*)evt;

            if(adv_action->state != SRV_FMGR_NOTIFICATION_STATE_AFTER || 
               adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_COPY ||
               adv_action->action == SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER)
            {
                return MMI_RET_OK;
            }

            srv_fmgr_fileinfo_create((WCHAR*)adv_action->src_filepath, &file_info_handle);
            is_folder = srv_fmgr_fileinfo_is_folder(file_info_handle);
            srv_fmgr_fileinfo_destroy(file_info_handle);

            if(is_folder && adv_action->result < 0)
            {
                return MMI_RET_OK;
            }

            if(is_folder)
            {
                del_type = SRV_PROF_DEL_FOLDER;
            }

            srv_prof_delete_file_update_hdlr((WCHAR*)adv_action->src_filepath, del_type);

            return MMI_RET_OK;
        }

    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_prof_bt_disconnected_hdlr
 * DESCRIPTION
 *  This function is for BTCM service to inform profile service of bt disconnected.
 * PARAMETERS
 *  connect_type    [IN]    connect type (ex: ACL/SCO)
 *  callback_type   [IN]    callback type
 * RETURNS
 *  void 
 *****************************************************************************/
void srv_prof_bt_disconnected_hdlr(srv_prof_bt_connect_type_enum connect_type, srv_prof_bt_cb_type_enum callback_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_BT_DISCONNECT,connect_type,callback_type);

    switch (connect_type)
    {
    #ifdef __MMI_BT_AUDIO_SUPPORT__
        case SRV_PROF_BT_HFP_ACL:
        {
            srv_btsco_hfp_disconnect_callback((U8)callback_type);

            if (callback_type == SRV_PROF_BT_IND || callback_type == SRV_PROF_BT_RSP)
            {
                if (srv_earphone_is_plug_in())
                {
                    mdi_audio_set_audio_mode(AUD_MODE_HEADSET); 
                } 
            }
            break;
        }
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

        default:
            break;

    }

}


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
void srv_prof_handfree_volume_sync_hdlr(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PROF_SRV_TRC_HFP_VOL,volume);

    /*normal screen*/ 
    if(volume >= SRV_PROF_VOL_LEVEL_END_OF_ENUM)
    {
        volume = SRV_PROF_VOL_LEVEL_END_OF_ENUM -1 ;
    }

    g_srv_prof.cur_setting.ring_vol = volume;

}
#endif /*__BT_SPK_VOL_CONTROL__*/
