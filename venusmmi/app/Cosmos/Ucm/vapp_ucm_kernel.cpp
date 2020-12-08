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
 *  UcmKernel.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM kernel source file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

#ifdef __MMI_UCM__
extern "C"
{
    #include "UCMGProt.h"
    #include "UCMProt.h"
    #include "UcmSrvGProt.h"
    #include "UcmCoreProt.h"
    #include "mmi_rp_core_ucm_def.h"
    #include "mmi_rp_vapp_ucm_def.h"
    #include "mdi_audio.h"
    #include "ProfilesSrvGprot.h"
    #include "SettingGprots.h" /* GetCallTimeDisplay */
    #include "CallSetSrvGprot.h" /* srv_callset_call_time_display_get_mode, srv_callset_ctr_get_mode */
    #include "BootupSrvGprot.h"  /* srv_bootup_is_booting */
    #include "app_usedetails.h" /* applib_ss_string_parsing */
    #include "Resource_audio.h"
    #include "string.h"
    #include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "GlobalResDef.h"
    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "custom_srv_prof_defs.h"
    #include "mmi_frm_timer_gprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "custom_led_patterns.h"
    #include "GpioSrvGprot.h"
    #include "kal_public_api.h"
    #include "Unicodexdcl.h"
    #include "sim_common_enums.h"
    #include "ps_public_enum.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "fs_errcode.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "custom_mmi_default_value.h"
    #include "nvram_common_defs.h"
    #include "GlobalConstants.h"
    #include "CustDataRes.h"
    #include "SimCtrlSrvGprot.h"
    #include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */
    #include "NetSetSrvGprot.h"
    #include "NwInfoSrvGprot.h"
    #include "NwUsabSrvGprot.h"
#ifdef __MMI_BT_SUPPORT__
    #include "BtcmSrvGprot.h"
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    #include "app_datetime.h" /* applib_time_struct */
#endif

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    #include "wgui_categories_multimedia.h"
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_dial_cb
 * DESCRIPTION
 *  Reset index list.
 * PARAMETERS
 *  dial_result_info:            [IN]      result info.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_dial_cb(srv_ucm_result_info_struct *dial_result_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    /* [UCM3.0] */
    /*srv_ucm_result_enum error_cause; mmi_evt_ucm_after_make_call_struct evt */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* mmi_frm_send_event(&evt, g_ucm_p->mo_info.callback, g_ucm_p->mo_info.callback_para); */
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXEC_DIAL_CB_P1, dial_result_info->result);
    
    if (g_ucm_p->mo_info.callback != NULL)
    {
        make_call_cb_para.result = dial_result_info->result;
        make_call_cb_para.user_data = g_ucm_p->mo_info.callback_para;
        g_ucm_p->mo_info.callback(&make_call_cb_para);
        g_ucm_p->mo_info.callback = NULL; /* Make sure the callback is called once */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_dial_cb_by_result
 * DESCRIPTION
 *  execute dial callback by given result
 * PARAMETERS 
 *  result            [IN]            dial result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_dial_cb_by_result(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXEC_DIAL_CB_BY_RESULT_P1, result);

    if (g_ucm_p->mo_info.callback != NULL)
    {
        make_call_cb_para.result = result;
        make_call_cb_para.user_data = g_ucm_p->mo_info.callback_para;
        g_ucm_p->mo_info.callback(&make_call_cb_para);
        g_ucm_p->mo_info.callback = NULL; /* Make sure the callback is called once */
    }
}

/* ==================================================================================== */
/* =============kernel tone related=========================================================== */
/* ==================================================================================== */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_suppress_incoming_tone
 * DESCRIPTION
 *  Suppress incoming tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_suppress_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SUPPRESS_INCOMING_TONE_P1, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);

    if(g_ucm_p->call_misc.is_ringtone_suppress == MMI_TRUE)
    {
        /* Already suppressed */
        return;
    }
    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL,  NULL) != 1)
    {
        return;
    }

    g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
    g_ucm_p->call_misc.is_ringtone_suppress = MMI_TRUE;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 1);
    
    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {            
        case SRV_PROF_ALERT_TYPE_RING:
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
            srv_vibrator_off();
            break;

        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
            srv_vibrator_off();
            break;

        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            srv_vibrator_off();
            break;

        case SRV_PROF_ALERT_TYPE_SILENT:
            break;
        case SRV_PROF_ALERT_TYPE_INVALID:
            break;

        default: /* set default as MMI_RING */
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
            break;
    }

    srv_led_pattern_stop_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id);

}

/* ==================================================================================== */
/* =============VT related============================================================= */
/* ==================================================================================== */

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_init
 * DESCRIPTION
 *  Initialize VT related context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_init_setting();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_init_setting
 * DESCRIPTION
 *  Init vt setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_init_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* answer mode */

    /* dial mode */

    /* auto redial voice mode */
    
    /* Mirror setting */
    
    /* video quality*/

    /* audio option */

    /* incall image */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_init_incall_setting
 * DESCRIPTION
 *  Init incall setting before entering incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_init_incall_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.ev = MMI_UCM_VT_DEFAULT_EV;
    g_ucm_p->vt_cntx.incall_screen.zoom_step = MMI_UCM_VT_DEFAULT_ZOOM;
    g_ucm_p->vt_cntx.incall_screen.curr_hilite_index = 0;
    
    /* g_ucm_p->vt_cntx.incall_screen.is_camera_on should be set in dial MO or answer MT call */

    /* because audio option menu is removed, so here always is_mic_off = 0 */
    if (g_ucm_p->vt_cntx.setting.is_mic_off)
    {
        mmi_ucm_vt_set_mic_status(MMI_FALSE);
    }
    else
    {
        mmi_ucm_vt_set_mic_status(MMI_TRUE);
    }

    if (g_ucm_p->vt_cntx.setting.is_speaker_off)
    {
        mmi_ucm_vt_set_speaker_status(MMI_FALSE);
    }
    else
    {
        mmi_ucm_vt_set_speaker_status(MMI_TRUE);
    }
    
    g_ucm_p->vt_cntx.incall_screen.is_main_camera = MMI_FALSE;
    g_ucm_p->vt_cntx.incall_screen.is_image_switch = MMI_FALSE;
    g_ucm_p->vt_cntx.incall_screen.is_small_region_hide = MMI_FALSE;
    g_ucm_p->vt_cntx.incall_screen.night_mode = MMI_VT_NIGHT_MODE_OFF;
    /* mirror and quality should be a persistent value, should get from NVRAM */
    g_ucm_p->vt_cntx.incall_screen.mode = MMI_UCM_VT_INCALL_SCREEN_MODE_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_answer_modes
 * DESCRIPTION
 *  get answer mode in VT setting
 * PARAMETERS
 *  void
 * RETURNS
 *  answer mode
 *****************************************************************************/
mmi_ucm_vt_answer_mode_enum mmi_ucm_vt_get_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.setting.answer_mode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_answer_mode
 * DESCRIPTION
 *  Set answer mode
 * PARAMETERS
 *  status:     [IN] answer mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_answer_mode(mmi_ucm_vt_answer_mode_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_SET_ANSWER_MODE, status);
    g_ucm_p->vt_cntx.setting.answer_mode = status; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_dial_mode
 * DESCRIPTION
 *  get dial mode in VT setting
 * PARAMETERS
 *  void
 * RETURNS
 *  dial mode
 *****************************************************************************/
mmi_ucm_vt_dial_mode_enum mmi_ucm_vt_get_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.setting.dial_mode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_dial_mode
 * DESCRIPTION
 *  Set dial mode
 * PARAMETERS
 *  status:     [IN] dial mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_dial_mode(mmi_ucm_vt_dial_mode_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_SET_DIAL_MODE,g_ucm_p->vt_cntx.setting.curr_hilite_index);

    g_ucm_p->vt_cntx.setting.dial_mode = status;
    /* apply it to camera status */ 
    /* ps. if user select use picture before, then change dial mode to start camera, will overwrite previous setting */
    if (MMI_UCM_VT_DIAL_MODE_START_CAMERA == g_ucm_p->vt_cntx.setting.dial_mode)
    {
        mmi_ucm_vt_set_camera_status(MMI_TRUE);
    }
    else
    {
        mmi_ucm_vt_set_camera_status(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_camera_status
 * DESCRIPTION
 *  get camera status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_True means camera is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_camera_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.is_camera_on;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_camera_status
 * DESCRIPTION
 *  set camera status
 * PARAMETERS
 *  status:     [IN] camera status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_camera_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.is_camera_on = status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_mic_status
 * DESCRIPTION
 *  get mic status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means mic is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_mic_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.is_mic_on;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_mic_status
 * DESCRIPTION
 *  set mic status
 * PARAMETERS
 *  status:     [IN] main mic status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_mic_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.is_mic_on = status;
    /*only apply to HW when VT call exists*/
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
        if (g_ucm_p->vt_cntx.incall_screen.is_mic_on)
        {
            srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);     /* O */   
        }
        else
        {
            srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE);  /* O */ 
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_speaker_status
 * DESCRIPTION
 *  get speaker status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means speaker is turned on. Otherwise false.
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_speaker_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.is_speaker_on;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_speaker_status
 * DESCRIPTION
 *  set speaker status
 * PARAMETERS
 *  status:     [IN] speaker status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_speaker_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.is_speaker_on = status;
    
    /*only apply to HW when VT call exists*/
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
        if (g_ucm_p->vt_cntx.incall_screen.is_speaker_on)
        {
            mdi_audio_set_mute(MDI_VOLUME_SPH, MMI_FALSE); /* O */  
        }
        else
        {
            mdi_audio_set_mute(MDI_VOLUME_SPH, MMI_TRUE); /* O */
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_pic_switch_status
 * DESCRIPTION
 *  get picture switch status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means picture is switched. Peer image is in small area and 
 *  local image is in main area.
 *  False means peer image is in main area and local image is in small area.
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_pic_switch_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.is_image_switch;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_pic_switch_status
 * DESCRIPTION
 *  set picture switch status
 * PARAMETERS
 *  status:     [IN] picture switch status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_pic_switch_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.is_image_switch = status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_hide_small_pic_status
 * DESCRIPTION
 *  get hide small pic status
 * PARAMETERS
 *  void
 * RETURNS
 *  True means the small picture is hidden.
 *  False means the small picture is displayed.
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_hide_small_pic_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.is_small_region_hide;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_hide_small_pic_status
 * DESCRIPTION
 *  set small picture status
 * PARAMETERS
 *  status:     [IN] small picture status
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_hide_small_pic_status(MMI_BOOL status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.is_small_region_hide = status;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_file_name
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  file_path:     [IN] file path
 * RETURNS
 *  file name pointer
 *****************************************************************************/
U16* mmi_ucm_vt_get_file_name(U16* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_path_len = mmi_ucs2strlen((CHAR*)file_path);
    U16* cur_position;
    U16* pre_position;
    S32 i = file_path_len - 1;
    U8 pattern[3 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pattern, 0, sizeof(pattern));
    mmi_asc_n_to_ucs2((CHAR*)pattern, "\\", 1);
    
    for (; i >= 0 ; i--)
    {
        cur_position = &(file_path[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((CHAR*)pre_position, (CHAR*)pattern, 1) == 0)
        {
            return cur_position;
        }
    }

    return file_path;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_incall_pic
 * DESCRIPTION
 *  Get file name
 * PARAMETERS
 *  file_path:     [IN] file path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_incall_pic(U16* file_path, mmi_ucm_vt_incall_pic_type_enum pic_type)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_incall_pic
 * DESCRIPTION
 *  Get file name for incall picture
 * PARAMETERS
 *  default_pic_id :  [OUT]  image resource id if return value is MMI_UCM_VT_INCALL_PIC_STATUS_BUILT_IN
 *  file_unicode_str_ptr :  [OUT] file path if return value is MMI_UCM_VT_INCALL_PIC_STATUS_FILE
 * RETURNS
 *  mmi_ucm_vt_incall_pic_status_enum
 *****************************************************************************/
mmi_ucm_vt_incall_pic_status_enum mmi_ucm_vt_get_incall_pic(U16* default_pic_id, CHAR** file_unicode_str_ptr, mmi_ucm_vt_incall_pic_type_enum pic_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    length = mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.setting.incall_image_file_path[pic_type]);

    if (length == 0)
    {
        *default_pic_id = (U8)MMI_TRUE;
        file_unicode_str_ptr = NULL;

        return MMI_UCM_VT_INCALL_PIC_STATUS_BUILT_IN;
    }
    else
    {
        *default_pic_id = 0;
        *file_unicode_str_ptr = (CHAR*)g_ucm_p->vt_cntx.setting.incall_image_file_path[pic_type];

        return MMI_UCM_VT_INCALL_PIC_STATUS_FILE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_incall_screen_mode
 * DESCRIPTION
 *  get incall screen mode
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ucm_vt_incall_screen_mode_enum
 *****************************************************************************/
mmi_ucm_vt_incall_screen_mode_enum mmi_ucm_vt_get_incall_screen_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->vt_cntx.incall_screen.mode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_incall_screen_mode
 * DESCRIPTION
 *  set incall screen mode
 * PARAMETERS
 *  status:     [IN]  incall screen mode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_incall_screen_mode(mmi_ucm_vt_incall_screen_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.incall_screen.mode = mode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_remote_num_uri
 * DESCRIPTION
 *  get remote num uri
 * PARAMETERS
 *  U16* ucs2_num_uri, if user give NULL buffer or num is 0. means he only want to check T/F, don't want to get uri string
 *  U32 uri_max_len - how many characters (UCS2), the num_uri buffer should be +1  
 * RETURNS
 *  display name
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_remote_num_uri(U16* ucs2_num_uri, S32 max_ucs2_char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_info_struct call_info;
    S32 UCS2_char_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_num_uri != NULL)
    {
        memset(ucs2_num_uri, 0, (max_ucs2_char_num + 1) * ENCODING_LENGTH);
    }

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)    
    {
        if (srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info))
        {
            if (strlen((char*)call_info.remote_info.num_uri) > 0)
            {
                if ((NULL != ucs2_num_uri) && (max_ucs2_char_num > 0))
                {
                    /* call_info.remote_info.num_uri is ASCII*/
                    UCS2_char_num = (SRV_UCM_MAX_NUM_URI_LEN > max_ucs2_char_num) ? (max_ucs2_char_num) : (SRV_UCM_MAX_NUM_URI_LEN);
                    mmi_asc_n_to_ucs2((CHAR*)ucs2_num_uri, (CHAR*)call_info.remote_info.num_uri, UCS2_char_num);
                }
                return MMI_TRUE;
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    /* if no num_uri, ex, caller hide his number, will return F */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_GET_REMOTE_NUM_URI_ERROR);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_call_start_time
 * DESCRIPTION
 *  get start time
 * PARAMETERS
 *  void
 * RETURNS
 *  start time of the video call
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_call_start_time(applib_time_struct* start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(start_time, 0, sizeof(applib_time_struct));
    
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)    
    {
        if (srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info))
        {
            memcpy(start_time, &(call_info.start_time), sizeof(applib_time_struct));
            return MMI_TRUE;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_GET_CALL_START_TIME_ERROR);    
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_get_call_timer_display_setting
 * DESCRIPTION
 *  get call timer display setting,
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_TRUE if the setting is on, and MMI_FALSE otherwise
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_get_call_timer_display_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_callset_call_time_display_get_mode())  /* O */
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /*__MMI_VIDEO_TELEPHONY__*/

#endif /* __MMI_UCM__ */
