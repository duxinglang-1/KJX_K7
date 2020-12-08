/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  DialerCuiClassic.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the classic dialer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "DialerCuiClassic.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "DialerCuiObject.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_cui_dialer_def.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "wgui_categories_CM.h"
#include "DialerCuiGprot.h"
#include "DialerCuiFactory.h"
#include "custom_phb_config.h"
#include "GlobalConstants.h"
#include "DialerCuiCommon.h"
#include "mmi_rp_app_uiframework_def.h"
#include "PhbCuiGprot.h"
#include "UcmSrvGprot.h"
#ifdef __OP01_FWPBW__
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_idle_def.h"
#include "mdi_audio.h"
#include "callsetSrvGprot.h"
#include "profilesSrvGprot.h"
#include "resource_audio.h"
#include "gpiosrvgprot.h"
#include "TimerEvents.h"
#endif

/****************************************************************************
 * Define
 ****************************************************************************/
#ifdef __OP01_FWPBW__
#define CUI_DIALER_DEFAULT_VOLUME  (3)
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_exit
 * DESCRIPTION
 *  This function exits the dialer.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_classic_exit(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_enter
 * DESCRIPTION
 *  This function enters the dialer.
 * PARAMETERS
 *  param               : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_classic_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_classic_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    p = (cui_dialer_classic_struct *)param->user_data;

    if (!mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            (FuncPtr)cui_dialer_classic_exit,
            (FuncPtr)cui_dialer_classic_enter,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_ASSERT(p && p->on_enter);
    p->on_enter((cui_dialer_obj_struct *)p);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_run
 * DESCRIPTION
 *  This function is the run function of the object.
 * PARAMETERS
 *  obj           : [IN]      Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_classic_on_run(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_CUI_DIALER_MAIN,
        (FuncPtr)cui_dialer_classic_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_enter
 * DESCRIPTION
 *  This function handles the enter action.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_classic_on_enter(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_classic_struct *p;
    U8 *history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p = (cui_dialer_classic_struct *)obj;
    history = mmi_frm_scrn_get_gui_buf(p->this_gid, SCR_ID_CUI_DIALER_MAIN);

    if (obj->dial_string_change == MMI_TRUE)
    {
        history = NULL;
        obj->dial_string_change = MMI_FALSE;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);

    /* Setup the handler on this category 16 screen. */
    if (p->on_set_cat_hdlr)
    {
        p->on_set_cat_hdlr();
    }

	if(obj->launch_by_calllog)
	{
		SetDialingInputCursorToFirst();
	}

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadEmergencyFunckey(cui_dialer_is_emergency_call_only());
#endif

    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);

    #ifdef __MMI_MAINLCD_96X64__
	
		ShowCategory16Screen(
			STR_GLOBAL_SAVE,
			NULL,
			STR_GLOBAL_BACK,
			NULL,
			(PU8)p->dial_string,
			CUI_DIALER_MAX_DIAL_STR_LEN,
			history);
	
	#else
    ShowCategory16Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8)p->dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN,
        history);

  #endif
  
    /* RSK handler. */
    SetCategory16RightSoftkeyFunction(cui_dialer_do_close, KEY_EVENT_UP);

    /* Input the first digit, if present. */
    cui_dialer_input_first_char((cui_dialer_obj_struct *)p);

    /* Setup the key handler. */
    cui_dialer_set_handler((cui_dialer_obj_struct *)p);
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_set_cat_hdlr
 * DESCRIPTION
 *  This function is the handler to set the category touch function.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_classic_on_set_cat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(CUI_DIALER_CLASSIC_SUPPORT_CSK)
    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);
#endif

#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadPhonebookHandler(mmi_phb_launch);
#if (MMI_MAX_SIM_NUM >= 2)
#if  defined(__MMI_DIALER_DYNAMIC_CALL_UI__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    cui_dialer_set_dynamic_sim_hdlr(cui_dialer_sim_select_hdlr);
#else
	#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
        cui_dialer_set_touch_send_hdlr(
            cui_dialer_do_send_key_dial_1,
            cui_dialer_do_send_key_dial_2);
	#else
		SetDialingKeypadCallHandler(cui_dialer_do_send_key_dial_1);
	#endif
#endif
#else
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
//#ifdef __MMI_VIDEO_TELEPHONY__
    SetDialingKeypadCallHandler(cui_dialer_do_voice_dial);
#else
    SetDialingKeypadCallHandler(cui_dialer_do_send_key_dial_1);
#endif
#endif /* if(MMI_MAX_SIM_NUM >= 2) */
#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) && defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
	if (srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_ALL))
	{
        SetDialingKeypadVideoHandler(cui_dialer_do_video_dial);
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_init
 * DESCRIPTION
 *  This function is the init function of the object.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_classic_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_classic_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_on_init(obj);

    p = (cui_dialer_classic_struct *)obj;

    p->type = CUI_DIALER_TYPE_CLASSIC;
    p->on_run = cui_dialer_classic_on_run;
    p->on_enter = cui_dialer_classic_on_enter;
    p->on_set_cat_hdlr = cui_dialer_classic_on_set_cat_hdlr;
}


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_stop_gsm_ring_hdlr
 * DESCRIPTION
 *  This function stop all the ring tone timer and ring.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_stop_gsm_ring_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_DIALER);
	srv_prof_stop_tone(SRV_PROF_TONE_GSM_BUSY);
	StopTimer(DIALER_PLAY_GSM_BUSY_TIMER);
	StopTimer(DIALER_PLAY_GSM_READY_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_gsm_timeout_hdlr
 * DESCRIPTION
 *  This function handles the auto close timeout event.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_gsm_busy_timeout_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    srv_prof_stop_tone(SRV_PROF_TONE_GSM_BUSY);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_gsm_timeout_hdlr
 * DESCRIPTION
 *  This function handles the auto close timeout event.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_gsm_play_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)user_data;
    srv_prof_play_req_struct play_req;
    U8 audio_mode = mdi_audio_get_audio_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_GSM_BUSY);
    play_req.audio_id = TONE_BUSY_CALL_GSM;
    play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
    play_req.audio_type = SRV_PROF_AUDIO_DTMF;
    play_req.aud_path = (audio_mode == AUD_MODE_LOUDSPK) ? MDI_DEVICE_LOUDSPEAKER : MDI_DEVICE_SPEAKER;
    play_req.volume   = CUI_DIALER_DEFAULT_VOLUME;
    srv_prof_play_tone_with_full_struct(&play_req);

    //obj->is_can_make_call = MMI_FALSE;

    StartTimerEx(
            DIALER_PLAY_GSM_BUSY_TIMER,
            60 * 1000,
            cui_dialer_bwt_gsm_busy_timeout_hdlr,
            obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_gsm_timeout_hdlr
 * DESCRIPTION
 *  This function handles the auto close timeout event.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_gsm_timeout_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    srv_prof_stop_tone(SRV_PROF_TONE_DIALER);

    StartTimerEx(
            DIALER_PLAY_GSM_BUSY_DELAY_TIMER,
            100,
            cui_dialer_bwt_gsm_play_hdlr,
            obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_auto_close_timeout_hdlr
 * DESCRIPTION
 *  This function handles the auto close timeout event.
 * PARAMETERS
 *  user_data               : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_auto_close_timeout_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    StopTimer(DIALER_PLAY_GSM_BUSY_TIMER);
    cui_dialer_do_center_key_dial_ex((cui_dialer_obj_struct *)obj);
    obj->is_can_close = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_start_auto_close_timer
 * DESCRIPTION
 *  This function starts the auto close timer.
 * PARAMETERS
 *  obj                 : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_start_delay_dial_timer(cui_dialer_bwt_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 delay_time = srv_callset_delay_dial_get_time();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delay_time == 0)
    {
        return;
    }

    StartTimerEx(
            EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER,
            delay_time * 1000,
            cui_dialer_bwt_auto_close_timeout_hdlr,
            obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_sos_stop_auto_close_timer
 * DESCRIPTION
 *  This function stops the auto close timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_stop_delay_dial_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EMERGENCY_NO_DIALED_TRANSIANT_SCR_TIMER);
}


static void cui_dialer_deinit_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CM_BLACK_LIST__
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)event->user_data;
    srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_REJECT_ALL, MMI_FALSE, NULL);
#endif
    cui_dialer_bwt_stop_gsm_ring_hdlr();
    cui_dialer_bwt_stop_delay_dial_timer();
    mmi_frm_end_scenario(MMI_SCENARIO_ID_DIALER_HOLD_ON);
}


static void cui_dialer_start_hdlr(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_prof_play_req_struct play_req;
	U8 audio_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_DIALER_HOLD_ON))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_DIALER_HOLD_ON);
    }

#ifdef __MMI_CM_BLACK_LIST__
    ((cui_dialer_bwt_struct *)obj)->blacklist_call_set = (srv_callset_blacklist_get_mode(NULL) & SRV_CALLSET_BLACKLIST_REJECT_ALL) ? MMI_TRUE : MMI_FALSE;
    srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_REJECT_ALL, MMI_TRUE, NULL);
#endif

    if (obj->dial_string && obj->dial_string[0] == 0)
    {
    	if(srv_prof_is_tone_playing(SRV_PROF_TONE_POWER_ON))    
    	{
    		srv_prof_stop_tone(SRV_PROF_TONE_POWER_ON);
    	}
		if(srv_prof_is_tone_playing(SRV_PROF_TONE_SMS))         
    	{
    		srv_prof_stop_tone(SRV_PROF_TONE_SMS);
    	}
		if(srv_prof_is_tone_playing(SRV_PROF_TONE_MMS))         
    	{
    		srv_prof_stop_tone(SRV_PROF_TONE_MMS);
    	}
    
        audio_mode = mdi_audio_get_audio_mode();
        
        srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_DIALER);
        play_req.aud_path = (audio_mode == AUD_MODE_LOUDSPK) ? MDI_DEVICE_LOUDSPEAKER : MDI_DEVICE_SPEAKER;
        play_req.audio_type = SRV_PROF_AUDIO_DTMF;
        play_req.audio_id = TONE_CONTINUE_SOUND;
        play_req.play_style = SRV_PROF_RING_TYPE_REPEAT;
	    play_req.volume = CUI_DIALER_DEFAULT_VOLUME;
        srv_prof_play_tone_with_full_struct(&play_req);
 
        StartTimerEx(
                DIALER_PLAY_GSM_READY_TIMER,
                10 * 1000,
                cui_dialer_bwt_gsm_timeout_hdlr,
                obj);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_validation_hdlr
 * DESCRIPTION
 *  This function is the callback to check the dial string.
 * PARAMETERS
 *  dial_string             : [IN]          Dial string
 *  cursor_position         : [IN]          Cursor position in the dial string
 *  length                  : [IN]          Dial string length
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_editor_change_hdlr(
    PU8 dial_string,
    PU8 cursor_position,
    S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)cui_dialer_get_obj_from_group();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (!obj->is_can_make_call)
    {
        return;
    }

    if (mmi_wcslen(obj->dial_string) > 0)
    {
        StopTimer(DIALER_PLAY_GSM_READY_TIMER);
        cui_dialer_bwt_start_delay_dial_timer(obj);
    }
    else
    {
        StartTimerEx(
                DIALER_PLAY_GSM_READY_TIMER,
                10 * 1000,
                cui_dialer_bwt_gsm_timeout_hdlr,
                obj);
		cui_dialer_bwt_stop_delay_dial_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_exit
 * DESCRIPTION
 *  This function exits the dialer.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_exit(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    p = (cui_dialer_bwt_struct *)param->user_data;

    MMI_ASSERT(p && p->on_exit);
    p->on_exit((cui_dialer_obj_struct *)p);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_enter
 * DESCRIPTION
 *  This function enters the dialer.
 * PARAMETERS
 *  param               : [IN]          Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *p;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    p = (cui_dialer_bwt_struct *)param->user_data;

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            (FuncPtr)cui_dialer_bwt_exit,
            (FuncPtr)cui_dialer_bwt_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    MMI_ASSERT(p && p->on_enter);
    p->on_enter((cui_dialer_obj_struct *)p);

    if (p->dial_string[0])
    {
        cui_dialer_bwt_start_delay_dial_timer(p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_enter_contact
 * DESCRIPTION
 *  This function exits the dialer.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_enter_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)cui_dialer_get_obj_from_group();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj->phb_group_id = cui_phb_list_select_contact_create(obj->this_gid);
    if (obj->phb_group_id == GRP_ID_INVALID)
    {
        return;
    }
    
    cui_phb_list_select_contact_set_field_filter(obj->phb_group_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);
    cui_phb_list_select_contact_run(obj->phb_group_id);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler of the dialer CUI.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_bwt_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
        case EVT_ID_PHB_SELECT_CONTACT:
        {
            cui_phb_select_contact_result_struct *select_contact = (cui_phb_select_contact_result_struct*) event;
            cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)mmi_frm_group_get_user_data(
                cui_phb_list_select_contact_get_parent_group(select_contact->sender_id));
            MMI_ASSERT(obj && obj->dial_string);
            mmi_wcscpy(obj->dial_string, select_contact->select_data);
            obj->dial_string_change = MMI_TRUE;
            cui_phb_list_select_contact_close(obj->phb_group_id);
            ret = MMI_RET_OK;
            break;
        }

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)event->user_data;
            if (srv_gpio_transmitter_is_hold_on())
            {

				if(mmi_wcslen(obj->dial_string) > 0)
				{

					ret = MMI_RET_OK;		
					if (mmi_frm_group_is_in_active_serial(obj->this_gid))
                	{
                    	srv_speech_disable_hand_free();
		        	}
				
				}			
            }
            else
            {
                ret = MMI_RET_OK;
                if (mmi_frm_group_is_in_active_serial(obj->this_gid))
                {
                    srv_speech_disable_hand_free();
                }
            }
            break;
        }

        case EVT_ID_GROUP_DEINIT:
        {
            cui_dialer_deinit_hdlr(event);
        }

        default:
            ret = cui_dialer_obj_evt_hdlr(event);
            break;
    }    

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_on_create
 * DESCRIPTION
 *  This function creates the dialer CUI.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  parent_gid          : [IN]              Parent group ID
 * RETURNS
 *  Dialer CUI group ID.
 *****************************************************************************/
static mmi_id cui_dialer_bwt_on_create(cui_dialer_obj_struct *obj, mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;
    cui_dialer_bwt_struct *bwt_obj = (cui_dialer_bwt_struct *)obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    this_gid = mmi_frm_group_create(
                parent_gid,
                GRP_ID_AUTO_GEN,
                cui_dialer_bwt_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_gid = parent_gid;
    obj->this_gid = this_gid;
    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_bwt_on_want_to_run
 * DESCRIPTION
 *  This function checks if the dialer wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL cui_dialer_bwt_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK || srv_gpio_transmitter_is_hold_on()) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_run
 * DESCRIPTION
 *  This function is the run function of the object.
 * PARAMETERS
 *  obj           : [IN]      Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_bwt_on_run(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_dialer_start_hdlr(obj);
    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_CUI_DIALER_MAIN,
        (FuncPtr)cui_dialer_bwt_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_enter
 * DESCRIPTION
 *  This function handles the enter action.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_bwt_on_enter(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *p;
    U8 *history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (cui_dialer_bwt_struct *)obj;
    history = mmi_frm_scrn_get_gui_buf(p->this_gid, SCR_ID_CUI_DIALER_MAIN);

    if (obj->dial_string_change == MMI_TRUE)
    {
        history = NULL;
        obj->dial_string_change = MMI_FALSE;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);

    /* Setup the handler on this category 16 screen. */
    if (p->on_set_cat_hdlr)
    {
        p->on_set_cat_hdlr();
    }

    ShowCategory16Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_ID_IDLE_CONTACT,
        IMG_GLOBAL_BACK,
        (PU8)p->dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN,
        history);

    /* RSK handler. */
    SetCategory16RightSoftkeyFunction(cui_dialer_bwt_enter_contact, KEY_EVENT_UP);

    /* Input the first digit, if present. */
    cui_dialer_input_first_char((cui_dialer_obj_struct *)p);

    /* Setup the key handler. */
    cui_dialer_set_handler((cui_dialer_obj_struct *)p);

    /* Setup the dial string validation callback. */
    wgui_inputs_register_validation_func(cui_dialer_bwt_editor_change_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_exit
 * DESCRIPTION
 *  This function handles the exit action.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_bwt_on_exit(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_stop_gsm_ring_hdlr();
    cui_dialer_bwt_stop_delay_dial_timer();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_set_cat_hdlr
 * DESCRIPTION
 *  This function is the handler to set the category touch function.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_bwt_on_set_cat_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_dialer_classic_on_set_cat_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_classic_on_init
 * DESCRIPTION
 *  This function is the init function of the object.
 * PARAMETERS
 *  obj           : [IN]        Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_bwt_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_bwt_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_on_init(obj);

    p = (cui_dialer_bwt_struct *)obj;

    p->type = CUI_DIALER_TYPE_BWT;
    p->is_can_make_call = MMI_TRUE;
    p->on_create = cui_dialer_bwt_on_create;
    p->on_run = cui_dialer_bwt_on_run;
    p->on_enter = cui_dialer_bwt_on_enter;
    p->on_exit = cui_dialer_bwt_on_exit;
    p->on_set_cat_hdlr = cui_dialer_bwt_on_set_cat_hdlr;
}


void cui_dialer_bwt_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj = cui_dialer_get_obj_in_history();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!obj)
    {
        return;
    }

    if (obj->type == CUI_DIALER_TYPE_BWT)
    {
        ((cui_dialer_bwt_struct *)obj)->is_can_close = MMI_TRUE;
    }
    cui_dialer_emit_close_req((cui_dialer_obj_struct *)obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dialer_handfree_key_hdlr
 * DESCRIPTION
 *  handfree key handle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK to continue key routing, MMI_RET_STOP_KEY_HANDLE to stop
 *  key routing
 *****************************************************************************/
mmi_ret cui_dialer_bwt_process_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    cui_dialer_bwt_struct *obj = (cui_dialer_bwt_struct *)cui_dialer_get_obj_in_active_serial();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(obj);

    if (obj->type == CUI_DIALER_TYPE_BWT)
    {
        return MMI_RET_OK;
        //return MMI_RET_KEY_HANDLED;
    }
    else
    {
        return MMI_RET_OK;
    }
}

#endif

