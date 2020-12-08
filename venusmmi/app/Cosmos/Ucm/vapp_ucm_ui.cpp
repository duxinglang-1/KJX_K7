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
 *  vapp_ucm_ui.cpp
 *
 * Project:
 * -------- 
 *  COSMOS
 *
 * Description:
 * ------------
 *  UCM call screen files
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "MMI_features.h"

#include "vapp_ucm_def.h"
#include "vapp_ucm_prot.h"
#include "Vcp_global_popup.h"

extern "C"
{
    #include "MMIDataType.h"
    #include "GpioSrvGprot.h"
    #include "DialerCuiGprot.h"
    #include "CallSetSrvGprot.h"
    #include "NwInfoSrvGprot.h"
    #include "BtcmSrvGprot.h"
    #include "GpioSrvGprot.h"
    #include "PhbSrvGprot.h"
    #include "UcmSrvGprot.h"
    #include "UcmGprot.h"
    #include "UcmProt.h"
    #include "UcmCoreProt.h"
    #include "mmi_rp_core_ucm_def.h"
    #include "VolumeHandler.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_util.h"
    #include "BtAudioSrvGprot.h"
#ifdef __PXS_APP_ENABLE__
    #include "SensorSrvGport.h"
#endif /* __PXS_APP_ENABLE__ */
    extern VfxBool mmi_bt_switch_voice_path_incall(VfxBool is_on);
    extern MMI_BOOL srv_speech_is_hand_free(void);
}

#ifdef __PXS_APP_ENABLE__
extern VfxBool vapp_ucm_pxs_on;
#endif /* __PXS_APP_ENABLE__ */

/* because of EnableCategory17Audio in mmi_ucm_play_tone_after_vibration */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_play_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_RINGTONE_P2, 0, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);

    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {
        case SRV_PROF_ALERT_TYPE_RING:
            mmi_ucm_play_tone_with_text();
            break;
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            srv_vibrator_on(); /* O */
            break;
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            srv_vibrator_on();
            mmi_ucm_play_tone_with_text();
            break;
        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            srv_vibrator_on(); /* O */
            StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, MMI_UCM_VIB_THEN_RING_DURATION, vapp_ucm_play_tone_after_vibration);
            break;
        case SRV_PROF_ALERT_TYPE_SILENT:
        case SRV_PROF_ALERT_TYPE_INVALID:
            break;
        default: /* set default as MMI_RING */
            mmi_ucm_play_tone_with_text();
            break;
    }
    srv_led_pattern_start_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id); /* O */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_stop_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_STOP_RINGTONE_P2, 0, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);
    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {
        case SRV_PROF_ALERT_TYPE_RING:
        {
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
        }
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
        {
            srv_vibrator_off();
        }
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
        {

            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
        }    
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
        {
            /* NSC Does not make the mobile go back into Silent Mode */
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
        }
        break;
        
        case SRV_PROF_ALERT_TYPE_SILENT:
        case SRV_PROF_ALERT_TYPE_INVALID:
        {

        }
        break;

        default: /* set default as MMI_RING */
        {
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
        }
        break;
    }

    srv_led_pattern_stop_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id); /* O */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_after_vibration
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_play_tone_after_vibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
    srv_vibrator_off(); /* O */
    mmi_ucm_play_tone_with_text();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_play_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_group;
	S32 incoming_call_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* just for print information */
    num_group = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_INCOMING_TONE, g_ucm_p->call_misc.play_tone, num_group);
    
    incoming_call_count = srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL);
    if (incoming_call_count == 0)
    {
        return;
    }

    if (g_ucm_p->call_misc.play_tone == MMI_UCM_NONE)
    {
        if (g_ucm_p->call_misc.is_ringtone_suppress == MMI_TRUE)
        {
            return;
        }

        if (incoming_call_count == num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 2);
            vapp_ucm_play_ringtone();
        }
        else
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_WAITING_TONE;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 3);
            mmi_ucm_play_waitingtone();
        }
    }
    else if (g_ucm_p->call_misc.play_tone == MMI_UCM_WAITING_TONE)
    {
        if (incoming_call_count == num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 4);
            vapp_ucm_play_ringtone();
        }
        else
        {
            /* do not replay waitingtone */
        }
    }
    else /* g_ucm_p->call_misc.play_tone == MMI_UCM_RING_TONE */
    {
        /* do not replay ringtone */
    }
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_stop_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_STOP_INCOMING_TONE_P1, g_ucm_p->call_misc.play_tone);


    if (g_ucm_p->call_misc.play_tone == MMI_UCM_RING_TONE)
    {
        g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 5);
        vapp_ucm_stop_ringtone();
    }
    else if ( g_ucm_p->call_misc.play_tone == MMI_UCM_WAITING_TONE)
    {
        /* waiting tone */
        g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 6);
        mmi_ucm_stop_waitingtone();
    }
    
}

#define CallActions
/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_display_popup
 * DESCRIPTION
 *  Display result popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_display_popup(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_id = srv_ucm_query_error_message(result);    
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_vapp_ucm_display_popup_P2, result, string_id);

    //mmi_popup_display((WCHAR*)((UI_string_type) GetString(string_id)), MMI_EVENT_FAILURE, NULL);
    vapp_ucm_display_info((WCHAR*)GetString(string_id));
}

void vapp_ucm_confirm_cb (VfxId id, void *userData) 
{
    mmi_bool_funcptr_type callback = (mmi_bool_funcptr_type)userData;
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            callback(MMI_TRUE);
            break;
        }
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        case VCP_POPUP_BUTTON_NO_PRESSED:
        {
            callback(MMI_FALSE);
            break;
        }

        default:
            break;
    }
}

VfxS32 vapp_ucm_show_confirm(VfxU16* str, mmi_bool_funcptr_type cb)
{
    VfxS32 conf_popup_id = vcp_global_popup_show_confirm_two_button_str(GRP_ID_ROOT,
        VCP_POPUP_TYPE_QUESTION,
        VFX_WSTR_MEM(str),
        VFX_WSTR_RES(STR_GLOBAL_YES),
        VFX_WSTR_RES(STR_GLOBAL_NO),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        vapp_ucm_confirm_cb,
        (void*)cb);
    return conf_popup_id;
}

void vapp_ucm_close_confirm(VfxS32 id)
{
    vcp_global_popup_cancel(id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret vapp_ucm_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct *act_result = (srv_ucm_act_result_evt_struct *) event;
    srv_ucm_act_rsp_struct *dial_rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_CB_P1, act_result->act_op);
    /* the success or fail err popup is always displayed by UCM when receiving dial action notify. */
    /* To call app's dial callback here */
    switch(event->evt_id)
    {
        case EVT_ID_SRV_UCM_ACTION_RESULT:
        {
            switch (act_result->act_op)
            {
                case SRV_UCM_DIAL_ACT:
                case SRV_UCM_HOLD_AND_DIAL_ACT:
                case SRV_UCM_END_ALL_AND_DIAL_ACT:
                {
                    dial_rsp = (srv_ucm_act_rsp_struct*) act_result->act_result;            
                    g_ucm_p->mo_info.callback_para = act_result->user_data;
                    mmi_ucm_exec_dial_cb(&dial_rsp->result_info);
                }
                break;
                case SRV_UCM_ACCEPT_ACT:
                {
                    /* do nothing */
                }
                break;
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__				
                case SRV_UCM_END_ALL_HELD_ACT:
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */					
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__					
                case SRV_UCM_END_ALL_ACTIVE_ACT:
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ */					
                case SRV_UCM_END_ALL_ACT:
                case SRV_UCM_END_SINGLE_ACT:
                case SRV_UCM_END_ALL_PROCESSING_ACT:
                {
                    /* do nothing, because the grey screen will be displayed in disconnect_ind 
                      and end popup will in rel_ind, and the end action result will be handled in end call end_notify */
                }
                break;
                case SRV_UCM_HOLD_ACT:
                {
                    /* do nothing */
                }
                break;
    	    #ifdef __MMI_UCM_DEFLECT__
                case SRV_UCM_DEFLECT_ACT:
                {
                    /* do nothing */
                }
                break;
	        #endif
                case SRV_UCM_RETRIEVE_ACT:
                {
                    /* do nothing */
                }
                break;
                case SRV_UCM_SPLIT_ACT:
                {
                    /* do nothing */
                }
                break;
                case SRV_UCM_SWAP_ACT:
                {
                    /* do nothing */
                }
                break;
                case SRV_UCM_CONFERENCE_ACT:
                case SRV_UCM_END_CONFERENCE_ACT:
	        #ifdef __MMI_UCM_ECT__
                case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
            #endif /* __MMI_UCM_ECT__ */
	        #ifdef __MMI_UCM_TRANSFER__
                case SRV_UCM_TRANSFER_ACT:
            #endif /* __MMI_UCM_TRANSFER__ */
                {
                    /* do nothing */
                }
                break;
                case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__					
                case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */					
                case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:
                case SRV_UCM_HOLD_AND_ACCEPT_ACT:
                {
                    /* do nothing */
                }
                break;
                case SRV_UCM_START_DTMF_ACT:
                case SRV_UCM_STOP_DTMF_ACT:
                {
                    /* do nothing */
                }
                break;
                default:
                {
                    MMI_ASSERT(0);
                }
                break;
            }       	  
        }
        break;
        default:
        {
            MMI_ASSERT(0);
        }
        break;    	
    }
    return MMI_RET_OK; 
}

#ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_play_tone_callback
 * DESCRIPTION
 *  callback function after mdi finishs playing sound.
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_play_tone_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_ANSWER_PLAY_TONE_CALLBACK, result);

    if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1) &&
        (srv_ucm_is_pending_action() == MMI_FALSE))
    {
        vapp_ucm_incoming_call_sendkey();
    }
}
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_auto_answer_action
 * DESCRIPTION
 *  Handle SEND key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_auto_answer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_ANSWER_ACTION); 

    if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1))
    {
    #ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
        audio_data = get_audio(AUD_ID_UCM_AUTO_ANSWER, &audio_type, &audio_len);
        if (audio_data != NULL)
        {
            mmi_ucm_suppress_incoming_tone();
            mdi_audio_play_string_with_vol_path(
                (void*)audio_data,
                audio_len,
                audio_type,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL,
                mmi_ucm_play_tone_callback,
                MDI_AUD_VOL_6,
                MDI_DEVICE_SPEAKER_BOTH);
        }
    #else /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */
        vapp_ucm_incoming_call_sendkey();
    #endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_single_action
 * DESCRIPTION
 *  execute hold single action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_hold_single_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_ucm_result_enum option_check_result = SRV_UCM_RESULT_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_hold_single_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
    // TBD: Should popup error message here
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_conf_action
 * DESCRIPTION
 *  execute hold conference action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_hold_conf_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_hold_conference_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sndrec_in_call_action
 * DESCRIPTION
 *  execute sound recorder action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SOUND_RECORDER__
void vapp_ucm_sndrec_in_call_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_sound_recorder_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }
	else
	{
		//mmi_sndrec_entry_in_call();
	}	
}
#endif /* __MMI_SOUND_RECORDER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_single_action
 * DESCRIPTION
 *  execute retrieve single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_retrieve_single_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_retrieve_single_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }           
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_single_action
 * DESCRIPTION
 *  execute retrieve single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_retrieve_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_retrieve_conference_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }              
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_swap_action
 * DESCRIPTION
 *  execute swap action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_swap_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL act_is_executed;
    srv_ucm_result_enum option_check_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_swap_option(MMI_UCM_EXEC_IF_PERMIT_PASS, &act_is_executed);
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SWAP_ACTION_P2, option_check_result, act_is_executed);
    
    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_conference_action
 * DESCRIPTION
 *  execute conference action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL act_is_executed;
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_conference_option(MMI_UCM_EXEC_IF_PERMIT_PASS, &act_is_executed);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }
    #if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_action
 * DESCRIPTION
 *  execute deflect action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_deflect_action(void)
{
#ifdef __MMI_UCM_DEFLECT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_deflect_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
       vapp_ucm_display_popup(option_check_result);
    }        
#endif /* __MMI_UCM_DEFLECT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_action
 * DESCRIPTION
 *  execute transfer action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_transfer_action(void)
{
#ifdef __MMI_UCM_TRANSFER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_transfer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */
    
    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
       vapp_ucm_display_popup(option_check_result);
    } 
#endif /* __MMI_UCM_TRANSFER__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_explict_call_transfer_action
 * DESCRIPTION
 *  execute ECT action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_explict_call_transfer_action(void)
{
#ifdef __MMI_UCM_ECT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_transfer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
       vapp_ucm_display_popup(option_check_result);
    } 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_end_single_action
 * DESCRIPTION
 *  execute end single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_end_single_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_end_single_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        vapp_ucm_display_popup(option_check_result);
    }    

}



/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_split_action
 * DESCRIPTION
 *  execute split action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_split_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_split_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_end_conference_action
 * DESCRIPTION
 *  execute end conference action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_end_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_end_conference_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        vapp_ucm_display_popup(option_check_result);
    }            
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_end_all_action
 * DESCRIPTION
 *  Execute end all action is permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_end_all_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_end_all_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        vapp_ucm_display_popup(option_check_result);
    }           
}

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_end_all_held_action
 * DESCRIPTION
 *  Execute end all held action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_end_all_held_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_end_all_held_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }   
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */

#ifndef __MMI_UCM_SLIM__
void vapp_ucm_bt_init(void)
{
#ifdef __MMI_BT_SUPPORT__
    if (0 == g_ucm_p->bt_srvHd)
    {
        g_ucm_p->bt_srvHd = srv_btaud_open(BTAUD_LEVEL_NORMAL, BTAUD_CHNL_MONO); 
        srv_btaud_set_notify(g_ucm_p->bt_srvHd, BTAUD_EV_ATTACH_IND | BTAUD_EV_DETACH_IND | BTAUD_EV_SWITCH_IND | BTAUD_EV_SWITCH_FAIL, vapp_ucm_bt_notify, NULL);
    }
#endif
}

void vapp_ucm_bt_deinit(void)
{
#ifdef __MMI_BT_SUPPORT__
    srv_btaud_close(g_ucm_p->bt_srvHd);
    g_ucm_p->bt_srvHd = 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_bt_set_audio_path
 * DESCRIPTION
 *  BT set audio path function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_bt_set_audio_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)

    if (srv_btaud_get_status(BTAUD_CHNL_MONO) == BTAUD_SWITCH_ON)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SET_AUDIO_PATH_TO_AG);
        /* Current voice path in BT, shall transfer to AG */
        srv_btaud_switch(g_ucm_p->bt_srvHd, MMI_FALSE); /* switch to headset */
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SET_AUDIO_PATH_TO_BT);
        /* Current voice path in AG, shall transfer to BT */
        srv_btaud_switch(g_ucm_p->bt_srvHd, MMI_TRUE); /* switch to headset */
    }
#endif /* defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__) */
}    

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_bt_set_audio_path_action
 * DESCRIPTION
 *  Execute set bluetooth audio path action in incall case if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_incall_bt_set_audio_path_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)

    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    option_check_result = mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_CALL_STATE_CONNECTED);
    
    if (SRV_UCM_RESULT_OK == option_check_result)
    {
        vapp_ucm_bt_set_audio_path();
    }
    else
    {
        vapp_ucm_display_popup(option_check_result);
    }
#endif /* defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__) */    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_bt_set_audio_path_action
 * DESCRIPTION
 *  Execute set bluetooth audio path action in incoming call case if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_incoming_bt_set_audio_path_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)

    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    option_check_result = mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_INCOMING_STATE);
    
    if (SRV_UCM_RESULT_OK == option_check_result)
    {
        vapp_ucm_bt_set_audio_path();
    }
    else
    {
        vapp_ucm_display_popup(option_check_result);
    }
#endif /* defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__) */     
}
#endif // __MMI_UCM_SLIM__

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_active_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_end_all_active_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no active calls to drop */
    MMI_ASSERT(srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0);

    option_check_result = mmi_ucm_end_all_active_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }   
}
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__ */
void vapp_ucm_end_key_handler(void)
{
	srv_ucm_group_info_struct group_info;
    srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    if (srv_ucm_is_pending_action() == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_END_KEY_RELEASE_PROCESSING);
        mmi_ucm_end_all_processing_action();
    }
    else
    {
        switch(group_info.call_state)
        {
            case SRV_UCM_OUTGOING_STATE:
            {
                vapp_ucm_outgoing_call_endkey();
            }
            break;
            case SRV_UCM_INCOMING_STATE:
            {
                vapp_ucm_incoming_call_endkey();
            }
            break;
            case SRV_UCM_ACTIVE_STATE:
            case SRV_UCM_HOLD_STATE:
            {
                vapp_ucm_in_call_endkey();
            }
        }
    }    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_call_key_proc
 * DESCRIPTION
 *  background call end key/volumn key handle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK to continue key routing, MMI_RET_STOP_KEY_HANDLE to stop
 *  key routing
 *****************************************************************************/
extern "C"
mmi_ret mmi_ucm_bk_call_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    //FuncPtr func_ptr;
    //MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);
    
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
    #ifdef __PXS_APP_ENABLE__
        if (vapp_ucm_pxs_on && (MMI_FALSE == srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD)))
        {
            srv_sensor_pxs_turn_off();
            srv_sensor_pxs_turn_on();
        }
    #endif
        if (key_code == KEY_END && key_type == KEY_EVENT_DOWN)
        {
            vapp_ucm_end_key_handler();
            return MMI_RET_STOP_KEY_HANDLE;
        }
        /*
        else if ((key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN) &&
             (key_type == KEY_EVENT_DOWN || key_type == KEY_LONG_PRESS || key_type == KEY_REPEAT))
        {
             SetDefaultVolumeKeyHandlers();
             func_ptr = mmi_frm_get_key_handler(key_code, key_type);
             if (func_ptr)
             {
                 (* func_ptr)();
             }
             return MMI_RET_STOP_KEY_HANDLE;
        }
        */
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_headset_key_hdlr
 * DESCRIPTION
 *  This function is to handle the headset key (GPIO_EXT_DEV_KEY_1) sent from GPIO
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern "C"
mmi_ret vapp_ucm_headset_key_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if (srv_ucm_query_call_count((srv_ucm_call_state_enum)SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)SRV_UCM_CALL_TYPE_ALL, NULL))
        {
            vapp_ucm_headset_key();
            return MMI_RET_ERR;
        }
    }          
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_quick_end
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_quick_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        /* MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] No calls to drop\n"); */
        return;
    }
     
    else if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL)  > 0 || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] No action when there is MT or MO call\n"); */
        return;
    }
    else if (srv_ucm_is_pending_action() == MMI_TRUE)
    {
        /*MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] can't drop calls during pending actions\n");*/
        StartTimer(CM_AUTO_QUICK_END_TIMER, 1000, mmi_ucm_auto_quick_end);
        return;
    }
    else
    {
        vapp_ucm_end_all_action();
    }
}


void vapp_ucm_incoming_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_answer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        /* if need to popup specific string for differnt result, use option_check_result */
        //mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_ucm_query_error_message(SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT))), MMI_EVENT_FAILURE, NULL);
        vapp_ucm_display_info((WCHAR*)GetString(srv_ucm_query_error_message(option_check_result)));
    }
    else
    {
        if (SRV_CALLSET_ANSWER_MODE_AUTO & srv_callset_answer_mode_get_status())
        {
            StopTimer(UCM_AUTO_ANSWER_TIMER);
        }
    }
    //return option_check_result;
}

void vapp_ucm_incoming_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;
    srv_ucm_call_info_struct call_info;
    srv_ucm_result_enum permit_result; 
    srv_ucm_index_info_struct call_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 1)
    {
        //MMI_ASSERT(0);
        return;
    }

    /* get uid */
    srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
    call_index.call_index = g_ucm_p->call_misc.index_list[0].call_index;
    call_index.group_index = g_ucm_p->call_misc.index_list[0].group_index;
    if (MMI_FALSE == srv_ucm_query_call_data(call_index, &call_info))
    {
        MMI_ASSERT(0);
    }

    memcpy(&(check_act_req.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));

    /* permit check */
    if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
    {
        srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &check_act_req, NULL, vapp_ucm_act_callback);
    }
    else
    {
        vapp_ucm_display_popup(permit_result);
    }
}


void vapp_ucm_outgoing_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct check_act_req;
	srv_ucm_call_info_struct call_info;
    srv_ucm_result_enum permit_result; 
    srv_ucm_index_info_struct call_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);

    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) != 1)
    {
        //MMI_ASSERT(0);
        return;
    }

    /* get uid */
    srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list);
    call_index.call_index = g_ucm_p->call_misc.index_list[0].call_index;
    call_index.group_index = g_ucm_p->call_misc.index_list[0].group_index;
    if (MMI_FALSE == srv_ucm_query_call_data(call_index, &call_info))
    {
        MMI_ASSERT(0);
    }
    
    memcpy(&(check_act_req.action_uid), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));

    /* permit check */
    if ((permit_result = srv_ucm_query_act_permit(SRV_UCM_END_SINGLE_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
    {
        srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, &check_act_req, NULL, vapp_ucm_act_callback);
    }
    else if ((SRV_UCM_RESULT_UCM_BUSY == permit_result) &&
              (SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(SRV_UCM_END_ALL_PROCESSING_ACT, NULL)))
    {
        srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT, NULL, NULL, vapp_ucm_act_callback);
    }
    else
    {
        vapp_ucm_display_popup(permit_result);
    }

}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_in_call_endkey
 * DESCRIPTION
 *  Handle END key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_in_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, NULL) == 1)
    {
        vapp_ucm_end_single_action();
    }
    else if (mmi_ucm_end_conference_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        vapp_ucm_end_conference_action();
    }
    else
    {
        //DisplayIdleScreen();
    }
}

void vapp_ucm_endkey_hdlr(void)
{
    srv_ucm_group_info_struct group_info;
    srv_ucm_index_info_struct call_index;
    call_index.call_index = g_ucm_p->call_misc.hilite_index;
    call_index.group_index = g_ucm_p->call_misc.hilite_tab;
    srv_ucm_query_group_data(call_index.group_index, &group_info); 

    switch (group_info.call_state)
    {
        case SRV_UCM_OUTGOING_STATE:
        {
            vapp_ucm_outgoing_call_endkey();
            break;
        }
        case SRV_UCM_INCOMING_STATE:
        {
            vapp_ucm_incoming_call_endkey();
            break;
        }
        case SRV_UCM_ACTIVE_STATE:
        case SRV_UCM_HOLD_STATE:
        {
            vapp_ucm_in_call_endkey();
            break;
        }
        default:
        {
            break;
        }

    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_dtmf_key_down
 * DESCRIPTION
 *  Send DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_dtmf_key_down(U8 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dtmf_struct check_act_req;
    S32 group_index = 0;
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;
    srv_ucm_group_info_struct group_info;
	S32 group_index_array[SRV_UCM_MAX_GROUP];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_DOWN);
	check_act_req.digit = keyCode;
	if ((g_ucm_p->call_misc.is_dtmf == MMI_TRUE) &&
		(SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(SRV_UCM_START_DTMF_ACT, &check_act_req)))
    {
        /* get current active call type */
        group_index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD);
        
        if (group_index != -1)
        {
        	srv_ucm_query_group_data(group_index, &group_info);
            call_type = group_info.call_type;
        }
        else
        {
			if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, srv_ucm_call_type_enum(SRV_UCM_VOICE_CALL_TYPE_ALL), MMI_FALSE, group_index_array) > 0)
			{
				srv_ucm_query_group_data(group_index_array[0], &group_info);
				call_type = group_info.call_type;
			}
		}

        if (call_type && (MMI_TRUE == srv_ucm_is_valid_dtmf_digit(call_type,keyCode)))
        {
            if (srv_speech_is_phone_mute() == MMI_FALSE)
            {
                
                srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE);
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_DOWN_SEND_START, call_type);
            
            /* call start dtmf API */    
            srv_ucm_act_request(SRV_UCM_START_DTMF_ACT, &check_act_req, NULL, NULL);
        }
    }
  
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_dtmf_key_up
 * DESCRIPTION
 *  Stop sending DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_dtmf_key_up(U8 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_call_type_enum call_type = SRV_UCM_VOICE_CALL_TYPE;
    srv_ucm_group_info_struct group_info;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_UP);
	if ((g_ucm_p->call_misc.is_dtmf == MMI_TRUE) &&
		(SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(SRV_UCM_STOP_DTMF_ACT, NULL)))
    {
        /* get current active call type */
        group_index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD);
        
        if (group_index != -1)
        {
        	srv_ucm_query_group_data(group_index, &group_info);
            call_type = group_info.call_type;
        }
		else
        {
			if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, srv_ucm_call_type_enum(SRV_UCM_VOICE_CALL_TYPE_ALL), MMI_FALSE, group_index_array) > 0)
			{
				srv_ucm_query_group_data(group_index_array[0], &group_info);
				call_type = group_info.call_type;
			}
		}
        
        if (call_type && (MMI_TRUE == srv_ucm_is_valid_dtmf_digit(call_type,keycode)))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_UP_SEND_STOP, call_type);
            /* call start dtmf API */    
            srv_ucm_act_request(SRV_UCM_STOP_DTMF_ACT, NULL, NULL, NULL);
        }
                    
        if (srv_speech_is_phone_mute() == MMI_FALSE)
        {
            srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_replace
 * DESCRIPTION
 *  Deflect function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_replace_option(MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        vapp_ucm_display_popup(option_check_result);
    }        
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_auto_redial_abort
 * DESCRIPTION
 *  Auto redial abort function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_auto_redial_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_REDIAL_ABORT);
    
    if (g_ucm_p->auto_redial.abort_hdlr)
    {
        g_ucm_p->auto_redial.abort_hdlr();
        memset(&g_ucm_p->auto_redial, 0, sizeof(srv_ucm_auto_redial_ind_struct));
    }
}

mmi_ret mmi_ucm_act_callback(mmi_event_struct *event)
{
    return vapp_ucm_act_callback(event);
}

