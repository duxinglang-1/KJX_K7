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
 *  vapp_ucm_event_hdlr.cpp
 *
 * Project:
 * -------- 
 *  COSMOS
 *
 * Description:
 * ------------
 *  UCM event handler source file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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

//#ifdef __MMI_UCM__

extern "C"
{
    #include "MMI_features.h"
    #include "mdi_datatype.h"
    #include "mdi_audio.h" /* MMI_EVENT_SUCCESS. in which include custom_events_notify.h */
    #include "Ucmprot.h"
    #include "UcmGprot.h"
    #include "UcmSrvGProt.h"
    #include "UcmCoreProt.h"
    #include "mmi_rp_core_ucm_def.h"
    #include "CallSetSrvGprot.h"
    #include "PowerOnChargerProt.h"
    #include "GpioSrvGprot.h"
    #include "GPSMgrGProt.h"
    #include "wgui_categories_util.h"
    #include "CommonScreens.h"
    #include "SmsSrvGprot.h"
#ifdef __PXS_APP_ENABLE__
    #include "SensorSrvGport.h"
#endif /* __PXS_APP_ENABLE__ */
#ifdef __MMI_USB_SUPPORT__
    #include "UsbSrvGProt.h"
#endif
}
#include "vapp_ucm_def.h"
#include "vapp_ucm_prot.h"
#include "vapp_screen_lock_gprot.h"
#include "Vfx_adp_device.h" /* touch feedback */
#include "mmi_rp_vapp_vol_dialog_def.h"

#define EVENT_HANDLERS

#ifdef __PXS_APP_ENABLE__
extern VfxBool vapp_ucm_pxs_on;
#endif /* __PXS_APP_ENABLE__ */
extern VappUcmSmsStateEnum vapp_ucm_sms_state;
extern VfxBool vapp_ucm_touch_fb_enable;
extern VappUcmCallScreen   *vapp_ucm_scr;
extern mmi_ucm_cntx_struct *g_ucm_p;

/* ==================================================================================== */
/* =============ind/act/cnf ind hdlr=================================================== */
/* ==================================================================================== */

#ifdef __MMI_UCM_VT_MSG__
/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_sms_is_ready_hdlr
 * DESCRIPTION
 *  Handler sms not ready ind
 * PARAMETERS
 *  evt      [IN]            sms_event_sms_ready struct
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern "C" mmi_ret vapp_ucm_sms_is_ready_hdlr(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;
    if (!(event_info->is_sms_ready) && vapp_ucm_scr && 
        vapp_ucm_scr->msgFolderPageExists())
    {
        vapp_ucm_scr->closePagesAboveMainPage();
    }
    return MMI_RET_OK;
}
#endif /* __MMI_UCM_VT_MSG__ */
MMI_BOOL vapp_ucm_is_fdn_blocked()
{
	VfxU16 cause = 0;
	VfxU32 real_length = 0;
	VfxU8 num[SRV_UCM_MAX_NUM_URI_LEN+1];
    sim_interface_enum sim_id = SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        if(g_ucm_p->mo_info.dial_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
        {
            sim_id = SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if(g_ucm_p->mo_info.dial_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
        {
            sim_id = SIM3;
        }
    #if (MMI_MAX_SIM_NUM >= 4)
        else if(g_ucm_p->mo_info.dial_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
        {
            sim_id = SIM4;
        }
    #endif // (MMI_MAX_SIM_NUM >= 4)
    #endif // (MMI_MAX_SIM_NUM >= 3)
    #endif // (MMI_MAX_SIM_NUM >= 2)
	if ('+' == g_ucm_p->mo_info.dial_num.num_uri[0])
	{
		num[0] = 0x91;
	}
	else
	{
		num[0] = 0x81;
	}
	real_length = srv_phb_convert_to_bcd(&num[1], g_ucm_p->mo_info.dial_num.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
	num[real_length + 1] = 0;
	srv_phb_xmgnt_approve_fdn(num, strlen((const char*)num), sim_id, L4C_CALL_OPERATION, &cause);

	if (PHB_APPROVE_FDN_BLOCKED == cause)
	{
		return MMI_TRUE;
	}
	return MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_connect_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_connect_ind(srv_ucm_connect_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = srv_callset_auto_quick_end_get_time();
#endif /* __MMI_CH_QUICK_END__ */
    srv_callset_ctr_struct ctr_info;
    srv_callset_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_stop_inband_tone();
    
	
#ifdef __MMI_CH_QUICK_END__
    if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == MMI_FALSE &&
        quickEndDuration > 0 && 
        srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
        srv_ucm_is_emergency_call() == MMI_FALSE)
        {    
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
#endif /* __MMI_CH_QUICK_END__ */


    /* Start CTR timer if it hasn't started yet */
    result = srv_callset_ctr_get_mode(&ctr_info);
    if ((result == SRV_CALLSET_RESULT_OK) &&
        (ctr_info.mode != SRV_CALLSET_CTR_MODE_OFF) &&
        (IsMyTimerExist(CM_CTR_TIMER) == MMI_FALSE))
    {
        StartTimer(CM_CTR_TIMER, (1000 * ctr_info.time), mmi_ucm_call_time_reminder);
    }
#ifdef __MMI_VIDEO_TELEPHONY__
    if ((SRV_UCM_VIDEO_CALL_TYPE == ind->uid_info.call_type) &&
       (MMI_UCM_VT_INCALL_SCREEN_MODE_NONE == mmi_ucm_vt_get_incall_screen_mode()))
    {
        if (g_ucm_p->vt_cntx.setting.dial_mode == MMI_UCM_VT_DIAL_MODE_STOP_CAMERA)
        {
            mmi_ucm_vt_set_camera_status(MMI_FALSE);
        }
        else
        {
            mmi_ucm_vt_set_camera_status(MMI_TRUE);
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1)
    {
    #ifdef __MMI_CONNECT_NOTICE__
        /* play connect notice according to user defined style */
        mmi_ucm_play_connect_notice();
    #endif /* __MMI_CONNECT_NOTICE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_notify_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_notify_ind(srv_ucm_notify_ind_struct *notify_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    vapp_ucm_show_info_ballon(notify_ind->disp_msg);
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_handle_incoming_call_ind
 * DESCRIPTION
 *  Handler for incoming call ind
 * PARAMETERS
 *  incoming_ind      [IN]            incoming call ind structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_handle_incoming_call_ind(srv_ucm_incoming_call_ind_struct *incoming_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ucs2Number[(SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH];
    
    srv_callset_answer_mode_enum ans_mode_status;
    srv_ucm_caller_res_struct res_info;
    srv_ucm_res_type_enum image_type = SRV_UCM_RES_TYPE_IMAGE_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_HANDLE_INCOMING_CALL_IND);
    
    memset(ucs2Number, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((CHAR*) ucs2Number, (CHAR*) incoming_ind->remote_info.num_uri);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    memcpy(&g_ucm_p->full_mo_mt_display.mo_mt_display, &incoming_ind->display_info, sizeof(srv_ucm_display_info_struct));
    g_ucm_p->full_mo_mt_display.line_icon = incoming_ind->remote_info.line_icon;
#ifdef __MMI_UCM_NUMBER_TYPE__
    g_ucm_p->full_mo_mt_display.num_type_icon = incoming_ind->remote_info.num_type_icon;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    
    wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);
    if (IS_LOW_BATTERY())
    {
        ChgrPlayLowBatTone();
    }

    if (MMI_FALSE == srv_ucm_get_caller_res_info(incoming_ind->uid_info, &res_info))
    {
        MMI_ASSERT(0);
    }

    if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) == 1)
    {
    #ifndef __MMI_UCM_SLIM__
        vapp_ucm_bt_init();
    #endif
        mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_MODE_SWITCHED, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, vapp_ucm_proc, NULL);
    #ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, vapp_ucm_proc, NULL);
    #endif // __MMI_USB_SUPPORT__
    }

    /* Decide visual type */
    if (MMI_FALSE == mmi_ucm_decide_visual_type(res_info.res_type, &image_type))
    {
        MMI_ASSERT(0);
    }
    /* keep value in global, because when stop tone, can not query from call table */ 
    g_ucm_p->full_mo_mt_display.res_type = image_type;

    vapp_ucm_play_incoming_tone();

    /* auto answer is only applicable to the first incoming call */
    ans_mode_status = srv_callset_answer_mode_get_status();

    if (((ans_mode_status & SRV_CALLSET_ANSWER_MODE_AUTO) && (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)) ||
#ifdef __MMI_CM_WHITE_LIST__
    (srv_callset_whitelist_is_auto_answer_number((U8)mmi_ucs2strlen((CHAR*)ucs2Number), (WCHAR*)ucs2Number, NULL) == MMI_TRUE) ||
#endif /* __MMI_CM_WHITE_LIST__ */
    MMI_FALSE)
    {
        StartTimer(UCM_AUTO_ANSWER_TIMER, UI_POPUP_NOTIFYDURATION_TIME_2000, vapp_ucm_auto_answer_action);
    }

#ifdef __PXS_APP_ENABLE__
    if (!vapp_ucm_pxs_on)
    {
        srv_sensor_pxs_turn_on();
        mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_GPIO_EARPHONE_PLUG_IN, vapp_ucm_proc, NULL);
        vapp_ucm_pxs_on = VFX_TRUE;
    }
#endif /* __PXS_APP_ENABLE__ */

    if (vapp_ucm_touch_fb_enable)
    {
        vfx_adp_touch_fb_disable();
        vapp_ucm_touch_fb_enable = VFX_FALSE;
        MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_TOUCH_FB_STATUS, vapp_ucm_touch_fb_enable); 
    }

}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_handle_outgoing_call_ind
 * DESCRIPTION
 *  Handler for outgoing call ind
 * PARAMETERS
 *  outgoing_ind      [IN]            outgoing call ind structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_handle_outgoing_call_ind(srv_ucm_outgoing_call_ind_struct* outgoing_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memcpy(&g_ucm_p->full_mo_mt_display.mo_mt_display, &outgoing_ind->display_info, sizeof(srv_ucm_display_info_struct));
    g_ucm_p->full_mo_mt_display.line_icon = outgoing_ind->remote_info.line_icon;
#ifdef __MMI_UCM_NUMBER_TYPE__
    g_ucm_p->full_mo_mt_display.num_type_icon = outgoing_ind->remote_info.num_type_icon;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    wgui_status_icon_bar_show_icon(STATUS_ICON_CALL_INDICATOR);

#ifdef __PXS_APP_ENABLE__
    if (!vapp_ucm_pxs_on)
    {
        srv_sensor_pxs_turn_on();
        mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_GPIO_EARPHONE_PLUG_IN, vapp_ucm_proc, NULL);
        vapp_ucm_pxs_on = VFX_TRUE;
    }
#endif /* __PXS_APP_ENABLE__ */

    if (vapp_ucm_touch_fb_enable)
    {
        vfx_adp_touch_fb_disable();
        vapp_ucm_touch_fb_enable = VFX_FALSE;
        MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_TOUCH_FB_STATUS, vapp_ucm_touch_fb_enable); 
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1)
    {
    #ifndef __MMI_UCM_SLIM__
        vapp_ucm_bt_init();
    #endif
        mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_MDI_AUDIO_MODE_SWITCHED, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, vapp_ucm_proc, NULL);
    #ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, vapp_ucm_proc, NULL);
        mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, vapp_ucm_proc, NULL);
    #endif /* __MMI_USB_SUPPORT__ */
    #ifdef __MMI_DUAL_MIC_SUPPORT__
        mdi_audio_set_dual_mic_nr(mmi_ucm_get_dual_mic_nr_status());
    #endif /* __MMI_DUAL_MIC_SUPPORT__ */
    }

}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_alert_ind
 * DESCRIPTION
 *  Handler for alert ind
 * PARAMETERS
 *  alert_ind      [IN]            alert indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_alert_ind(srv_ucm_alert_ind_struct *alert_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (alert_ind->local_gen == TRUE)
    {
        mmi_ucm_play_inband_tone();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_query_cnf_ind
 * DESCRIPTION
 *  the g_ucm_p->cnf_scr.conf_ind_cb is alrady assigned or reset before vapp_ucm_query_cnf_ind is called
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_query_cnf_ind(srv_ucm_query_cnf_ind_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->cnf_scr.content != NULL)
    {
        OslMfree(g_ucm_p->cnf_scr.content);
        g_ucm_p->cnf_scr.content = NULL;
    }
    
    /* the g_ucm_p->cnf_scr.conf_ind_cb is alrady assigned or reset before mmi_ucm_display_cnf is called */
    g_ucm_p->cnf_scr.content = (U16*)OslMalloc((mmi_ucs2strlen((CHAR*)cnf->content) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)g_ucm_p->cnf_scr.content, (CHAR*)cnf->content);
    vapp_ucm_enter_confirm();
}

/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_release_ind
 * DESCRIPTION
 *  Handler for release ind
 * PARAMETERS
 *  ind      [IN]            release indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_release_ind(srv_ucm_release_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum ans_mode_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_CALL_INFO_P6, ind->uid_info.group_id, ind->uid_info.call_id, 
    ind->post_action.action, ind->post_action.is_ip_dial, ind->call_duration.nMin, ind->call_duration.nSec);    

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    /* Stop inband tone and incoming tone */    
    mmi_ucm_stop_inband_tone();
    vapp_ucm_stop_incoming_tone();

    /* stop recording if no ACTIVE/HOLD call */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        vapp_ucm_mdi_callback(MDI_AUDIO_SUCCESS, NULL);
    }

    g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
    /* Stop auto answer timer */
    ans_mode_status = srv_callset_answer_mode_get_status();
  
    if (ans_mode_status & SRV_CALLSET_ANSWER_MODE_AUTO)
    {
        StopTimer(UCM_AUTO_ANSWER_TIMER);
    }

    //TBD: Call end UI 
    
    /* Editing message */
    if (VAPP_UCM_SMS_NONE != vapp_ucm_sms_state
        && !mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_EDIT_MSG))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_UCM_EDIT_MSG);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (ind->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
        /* Decide if orig active VT end or MO/MT VT ends to adjst screen_mode. this value will decide if the setting should kept or init */
        /* ex. 1A VT + 1W VT, W-VT ends, should keep orig VT setting, but if 1A-VT end, shoud reset setting */
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE, NULL) == 0)
        {
            if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode())
            {
                mmi_ucm_vt_set_incall_screen_mode(MMI_UCM_VT_INCALL_SCREEN_MODE_NONE); 
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        mmi_event_struct evt;

        if (srv_speech_is_phone_mute() == MMI_TRUE)
        {
        	srv_speech_unmute_phone();
        }
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
    #ifndef __MMI_UCM_SLIM__
        vapp_ucm_bt_deinit();
    #endif // __MMI_UCM_SLIM__
        mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, vapp_ucm_proc, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vapp_ucm_proc, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_MDI_AUDIO_MODE_SWITCHED, vapp_ucm_proc, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, vapp_ucm_proc, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, vapp_ucm_proc, NULL);
    #ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, vapp_ucm_proc, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, vapp_ucm_proc, NULL);
    #endif // __MMI_USB_SUPPORT__
    #ifdef __MMI_DUAL_MIC_SUPPORT__
        mdi_audio_set_dual_mic_nr(MMI_FALSE);
    #endif
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (ind->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
        {
            srv_speech_unmute_phone();     
            mdi_audio_set_mute(MDI_VOLUME_SPH, MMI_FALSE);
            srv_speech_disable_hand_free();
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        g_ucm_p->call_misc.is_dtmf= MMI_TRUE;
        memset(&g_ucm_p->call_cost, 0, sizeof(mmi_ucm_call_cost_cntx_struct));
        
    #ifdef __MMI_CH_QUICK_END__
        StopTimer(CM_AUTO_QUICK_END_TIMER);
    #endif /* __MMI_CH_QUICK_END__ */

    #if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
        mmi_gps_mgr_call_end(); /*x*/
    #endif /* defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__) */

    #ifdef __BT_SPK_VOL_CONTROL__
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_VOL_CONTROL_STOP);
        mdi_audio_bt_clear_volume_sync_callback(VAPP_UCM); /* O */
    #endif /* __BT_SPK_VOL_CONTROL__ */
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CALL_INDICATOR);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_SPEAKER_CALL);

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_UCM_BG_RUN_END);
        MMI_FRM_CB_EMIT_EVENT(&evt);

    }

    /* hide GSM cipher status icon when there is no GSM call */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM1_CALL_TYPE_ALL, NULL) == 0)
    {
    #ifdef __MMI_NETWORK_CIPHER_SUPPORT__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_NETWORK_CIPHER_GSM);
    #endif /* __MMI_NETWORK_CIPHER_SUPPORT__ */
    }
#ifdef __MMI_DUAL_SIM_MASTER__

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM2_CALL_TYPE_ALL, NULL) == 0)
    {
    #ifdef __MMI_NETWORK_CIPHER_SUPPORT__
        wgui_status_icon_bar_hide_icon(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    #endif /* __MMI_NETWORK_CIPHER_SUPPORT__ */
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /* stop the CTR time since there is no active/held voice call */
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0 &&
        srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        if(IsMyTimerExist(CM_CTR_TIMER) == MMI_TRUE)
        {
           StopTimer(CM_CTR_TIMER);
        }
    }

    if (!srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
    #ifdef __PXS_APP_ENABLE__
        if (vapp_ucm_pxs_on)
        {
            mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_AWAY, vapp_ucm_proc, NULL);
            mmi_frm_cb_dereg_event(EVT_ID_SENSOR_PXS_DETECT_OBJ_CLOSE, vapp_ucm_proc, NULL);
            mmi_frm_cb_dereg_event(EVT_ID_GPIO_EARPHONE_PLUG_IN, vapp_ucm_proc, NULL);
            srv_sensor_pxs_turn_off();
            vapp_ucm_pxs_on = VFX_FALSE;
        }
    #endif /* __PXS_APP_ENABLE__ */
    
        if (!vapp_ucm_touch_fb_enable)
        {
            vfx_adp_touch_fb_enable();
            vapp_ucm_touch_fb_enable = VFX_TRUE;
            MMI_TRACE(TRACE_GROUP_5, TRC_VAPP_UCM_TOUCH_FB_STATUS, vapp_ucm_touch_fb_enable); 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_ucm_auto_redial_ind
 * DESCRIPTION
 *  Handler for auto reduial indication
 * PARAMETERS
 *  ind      [IN]             auto reduial indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_ucm_auto_redial_ind(srv_ucm_auto_redial_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
    	memcpy(&(g_ucm_p->auto_redial), ind, sizeof(srv_ucm_auto_redial_ind_struct));
        //show auto redial screen
    }
    else
    {	
    	if (ind->abort_hdlr)
        {
            ind->abort_hdlr();
        }
    }
}

void vapp_ucm_accept_act_rsp(srv_ucm_act_rsp_struct *rsp, srv_ucm_act_type_enum act_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    //srv_ucm_act_rsp_struct *rsp = (srv_ucm_act_rsp_struct*)act_struct;
#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = srv_callset_auto_quick_end_get_time();
#endif /* __MMI_CH_QUICK_END__ */
    srv_callset_ctr_struct ctr_info;
    srv_callset_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
        g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
        if (g_ucm_p->call_misc.play_tone != MMI_UCM_NONE)
        {
            vapp_ucm_stop_incoming_tone();
        }
        mmi_ucm_stop_inband_tone();
        /*incoming --> actvie, therefore the accepted call must active currently*/    
    #ifdef __MMI_VIDEO_TELEPHONY__   
        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE, NULL) == 1)
        {
            if (g_ucm_p->vt_cntx.setting.answer_mode == MMI_UCM_VT_ANSWER_MODE_START_CAMERA)
            {
                mmi_ucm_vt_set_camera_status(MMI_TRUE);
            }
            /* for stop and prompt cases  */
            else
            {
                mmi_ucm_vt_set_camera_status(MMI_FALSE);
            }
        }
    #endif /*__MMI_VIDEO_TELEPHONY__*/    
    #ifdef __MMI_CH_QUICK_END__
        if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == FALSE &&
            quickEndDuration > 0 && 
            srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
            srv_ucm_is_emergency_call() == MMI_FALSE)
        {
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
    #endif /* __MMI_CH_QUICK_END__ */

    #ifdef __MMI_DUAL_MIC_SUPPORT__
        if( srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) == 1)
        {
            mdi_audio_set_dual_mic_nr(mmi_ucm_get_dual_mic_nr_status());
        }
    #endif /* __MMI_DUAL_MIC_SUPPORT__ */

        /* Start CTR timer if it hasn't started yet */
        result = srv_callset_ctr_get_mode(&ctr_info);
        if ((result == SRV_CALLSET_RESULT_OK) &&
            (ctr_info.mode != SRV_CALLSET_CTR_MODE_OFF) &&
            (IsMyTimerExist(CM_CTR_TIMER) == MMI_FALSE))
        {
            StartTimer(CM_CTR_TIMER, (1000 * ctr_info.time), mmi_ucm_call_time_reminder);
        }
    }
    else
    {    
    }
}

extern "C"
U8 vapp_ucm_dummy_pre_key_hdlr(KEYBRD_MESSAGE *msg)
{
    return (U8)MMI_FALSE;
}

extern "C"
mmi_ret vapp_ucm_act_notify_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_rsp_struct *accept_rsp;
    srv_ucm_act_notify_evt_struct *act_notify;
    srv_ucm_act_rsp_struct* dial_rsp;
    srv_ucm_act_rsp_struct *rsp;
    srv_ucm_single_call_act_req_struct *start_notify_req;
    //srv_ucm_act_rsp_struct *end_rsp;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    act_notify = (srv_ucm_act_notify_evt_struct *) para;

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY, act_notify->act_op, act_notify->notify_type);
    switch (act_notify->act_op)
    {
        case SRV_UCM_DIAL_ACT:
        {
            /* 1. START */
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
                //MO_2Steps-BEGIN
                if (srv_ucm_is_emergency_number(g_ucm_p->mo_info.dial_type,
					g_ucm_p->mo_info.dial_num.num_uri)
					|| !vapp_ucm_is_fdn_blocked())
                {
                	vapp_ucm_launch();
            	}
                //MO_2Steps-END
            #ifdef __MMI_TOUCH_SCREEN__
                /* stop virtual keypad tone if necessary. Ex. speed dial case */
                mmi_pen_reset();
                mmi_pen_disable();
            #endif /* __MMI_TOUCH_SCREEN__ */

                /* block all key events */
                mmi_frm_kbd_reg_pre_key_hdlr(vapp_ucm_dummy_pre_key_hdlr);

                /*do nothing, the outgoing call screen will be dispalyed when handling outgoing_ind*/
            }
            /* 2. END */
            else if (SRV_UCM_ACT_NOTIFY_TYPE_END == act_notify->notify_type) 
            {
                dial_rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
                //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, dial_rsp->result_info.result);
                if (dial_rsp->result_info.result != SRV_UCM_RESULT_OK)
                {
                    vapp_ucm_display_info((WCHAR*)dial_rsp->result_info.error_msg);
                    if (vapp_ucm_scr)
                    {
                        vapp_ucm_check_redial_fail();
                    }
                }

                //MO_2Steps-BEGIN
                if (SRV_UCM_RESULT_OK == dial_rsp->result_info.result)
                {
                    vapp_ucm_set_preferred_sim();
                }
                else if (MMI_FALSE == srv_ucm_is_any_call())
                {
                    vapp_ucm_terminate();
                }
                //MO_2Steps-END

            #ifdef __MMI_TOUCH_SCREEN__
                mmi_pen_enable();
            #endif /* __MMI_TOUCH_SCREEN__ */

                /* unblock all key events */
                mmi_frm_kbd_reg_pre_key_hdlr(NULL);
            }
        }
        break;

        case SRV_UCM_ACCEPT_ACT:
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
            }
            else
            {
                accept_rsp = (srv_ucm_act_rsp_struct*)act_notify->ptr;
                //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, accept_rsp->result_info.result);
                /* will trigger enter incall screen if result = T and popup error msg if result = F */
                vapp_ucm_accept_act_rsp(accept_rsp, act_notify->act_type);
                vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_ACT, (void*)act_notify);
            }
        }
        break;       

		#ifdef __MMI_UCM_DEFLECT__
        case SRV_UCM_DEFLECT_ACT:
    #endif
        case SRV_UCM_HOLD_ACT: 
        case SRV_UCM_RETRIEVE_ACT: 
        case SRV_UCM_SPLIT_ACT:  
        case SRV_UCM_CONFERENCE_ACT:
     #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:
     #endif
		#ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:
    #endif
        {
            /* Because for SWAP compound actions, the swapping screen will be displayed when receiving 
            SWAP start notify. Does not show each step, hold and retrieve individually */
            //if (SRV_UCM_SWAP_ACT == act_notify->comp_act_op)
            //{
            //    break;
            //}
            
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {

            }
            else
            {
                vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_ACT, (void*)act_notify);
            }
        }
        break;
      
        case SRV_UCM_END_SINGLE_ACT:
        case SRV_UCM_END_CONFERENCE_ACT:
        case SRV_UCM_END_ALL_ACT: 
        case SRV_UCM_END_ALL_ACTIVE_ACT:
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        case SRV_UCM_END_ALL_HELD_ACT:
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__ */			
        case SRV_UCM_END_ALL_PROCESSING_ACT:
        {     
            /* if there is no call when rece end notify with error result, don't display error popup */
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {

                if (act_notify->act_op == SRV_UCM_END_SINGLE_ACT)
                {
                    start_notify_req = (srv_ucm_single_call_act_req_struct*) act_notify->ptr;
                
                    if (MMI_TRUE == srv_ucm_query_call_exist(&(start_notify_req->action_uid), SRV_UCM_INCOMING_STATE))
                    {
                        vapp_ucm_stop_incoming_tone();
                        /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                        StopTimer(UCM_AUTO_ANSWER_TIMER);
                    }
                }
                else if (act_notify->act_op == SRV_UCM_END_ALL_ACT)
                {
                    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
                    {
                        vapp_ucm_stop_incoming_tone();
                        /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                        StopTimer(UCM_AUTO_ANSWER_TIMER);                       
                    }
                }
                /* if single or conpound _2nd, means these end actions is user-aware, so ues gray screen */
                if (act_notify->act_type == SRV_UCM_ACT_TYPE_SINGLE || act_notify->act_type == SRV_UCM_ACT_TYPE_COMPOUND_SECOND)
                {
                    /* clear hdlr in case user press key many times on purpose before screen is displayed */
                    /* must have disconnecting ind or rel ind to display new screen, the hdlr will recover at that time */
                    // there is no need to set END_KEY handler if no call screen
                    if (vapp_ucm_scr && srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
                    {
                         mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_EVENT_UP);
                         mmi_frm_set_key_handler(mmi_ucm_end_key, KEY_END, KEY_EVENT_DOWN);
                         mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_LONG_PRESS);
                         mmi_frm_set_key_handler(UI_dummy_function, KEY_END, KEY_REPEAT);
                    }
                }
                else /* SRV_UCM_ACT_TYPE_COMPOUND_FIRST, ,means this end action is not user-aware */
                {

                }
            }
            else
            {
                //end_rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;            
                //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, end_rsp->result_info.result);

            }
        }
        break;

		/* compound actions */

        case SRV_UCM_END_ALL_AND_ACCEPT_ACT:
        case SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT:   
        case SRV_UCM_HOLD_AND_ACCEPT_ACT:	
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {   
                /* for it's 2nd action= accept. even */
                vapp_ucm_stop_incoming_tone();
                /* g_ucm_p->call_misc.is_ringtone_suppress will be reset when release ind ;*/
                StopTimer(UCM_AUTO_ANSWER_TIMER);
            }
            else
            {
                if (SRV_UCM_END_ALL_AND_ACCEPT_ACT == act_notify->act_op || SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT == act_notify->act_op)
                {
                    rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
                    if (SRV_UCM_RESULT_OK != rsp->result_info.result)
                    {
                        vapp_ucm_play_incoming_tone();
                    }
                }
            }
        }
        break;    
             
        case SRV_UCM_END_ALL_AND_DIAL_ACT:
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__			
        case SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT:
#endif /* __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__ */			
        case SRV_UCM_HOLD_AND_DIAL_ACT:
        {
            /* do nothing */
        }
        
        break;
        
        case SRV_UCM_SWAP_ACT:	
        {
            /* For swap action, want to show swapping, swapped, not display each step like other compound actions*/
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
            {
                //start process                
            }
            else
            {
                rsp = (srv_ucm_act_rsp_struct*) act_notify->ptr;
                
                //MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_NOTIFY_HDLR_RESULT_P1, rsp->result_info.result);            
            }
            
        }
        break;

        case SRV_UCM_START_DTMF_ACT:
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
                g_ucm_p->call_misc.is_dtmf_start = MMI_TRUE;
            }
            else
            {
                MMI_ASSERT(0); /* these is action without rsp, so it's impossible to get end notify */
            }
        }
        break;

        case SRV_UCM_STOP_DTMF_ACT:	
        {
            if (SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type) 
            {
                g_ucm_p->call_misc.is_dtmf_start = MMI_FALSE;
            }
            else
            {
            	MMI_ASSERT(0); /* these is action without rsp, so it's impossible to get end notify */
            }
        }
        break;

        case SRV_UCM_SEND_DTMF_DIGITS_ACT:
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
    return MMI_RET_OK;
}

extern "C"
mmi_ret vapp_ucm_ind_hdlr(mmi_event_struct* para)
{
    srv_ucm_ind_evt_struct *ind;
    srv_ucm_incoming_call_ind_struct *incoming_ind;
    srv_ucm_outgoing_call_ind_struct *outgoing_ind;
    srv_ucm_alert_ind_struct *alert_ind;
    srv_ucm_notify_ind_struct *notify_ind;
    srv_ucm_connect_ind_struct *connect_ind;
    srv_ucm_release_ind_struct *release_ind;
    srv_ucm_auto_redial_ind_struct *auto_redial_ind;

    ind = (srv_ucm_ind_evt_struct *) para;

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_IND, ind->ind_type);
    switch (ind->ind_type)
    {  
        case SRV_UCM_INCOMING_CALL_IND:
        {
            //UIPerformance-BEGIN
            //As we pre start UCM app before outgoing call ind, just after recieve DIAL_ACT_NOTIFY_START,
            //A call may come during this period, in order to clear all the data stored, simple to terminate APP
            if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1
                && srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1
                && VAPP_UCM_SMS_NONE == vapp_ucm_sms_state)
            {
                vapp_ucm_terminate();
            }
            //UIPerformance-END
            incoming_ind = (srv_ucm_incoming_call_ind_struct*) ind->ptr;
            /* display the incoming call screen */
            if(vapp_ucm_get_app_id() != 0)
            {
                mmi_frm_set_active_group(vapp_ucm_get_app_id());
            }
            vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
            vapp_ucm_handle_incoming_call_ind(incoming_ind);
        }
        break;
        case SRV_UCM_OUTGOING_CALL_IND:
        {
            outgoing_ind = (srv_ucm_outgoing_call_ind_struct*) ind->ptr;
            g_ucm_p->call_misc.get_alert_ind = MMI_FALSE;
            vapp_ucm_handle_outgoing_call_ind(outgoing_ind);
            //MO_2Steps-BEGIN
            vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
            //MO_2Steps-END
        }
        break;        

        case SRV_UCM_ALERT_IND:
        {
            alert_ind = (srv_ucm_alert_ind_struct*)ind->ptr;
            g_ucm_p->call_misc.get_alert_ind = MMI_TRUE;
            vapp_ucm_alert_ind(alert_ind);
        }
        break;

        case SRV_UCM_NOTIFY_IND:
        {
            notify_ind = (srv_ucm_notify_ind_struct*)ind->ptr;
            vapp_ucm_notify_ind(notify_ind);
        }
        break;

        case SRV_UCM_CONNECT_IND:
        {
            connect_ind = (srv_ucm_connect_ind_struct*)ind->ptr;
            vapp_ucm_connect_ind(connect_ind);
            if (vapp_ucm_scr)
            {
                vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
            }
        }
        break;
	
        case SRV_UCM_DISCONNECTING_IND:
        {
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
        }		
        break;
	
        case SRV_UCM_RELEASE_IND:
        {
            release_ind = (srv_ucm_release_ind_struct*) ind->ptr;
            vapp_ucm_release_ind(release_ind);
            if (vapp_ucm_scr)
            {
                vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
            }
            else
            {
                if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)
                {
                    vapp_ucmapp_set_active_call_info(&(g_ucm_p->call_misc.index_list[0]));
                }
            }
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 1)
            {
                srv_ucm_act_opcode_enum curr_op_code = srv_ucm_query_curr_action();
                if (curr_op_code == SRV_UCM_END_ALL_AND_ACCEPT_ACT
                    || curr_op_code == SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT)
                {
                    break;
                }

                if (VAPP_UCM_SMS_NONE == vapp_ucm_sms_state)
                {
                    vapp_ucm_play_incoming_tone();
                }
            }
        }
        break;

        case SRV_UCM_CALL_COST_IND:
        {
        }
        break;

        case SRV_UCM_AUTO_REDIAL_IND:
        {
            auto_redial_ind = (srv_ucm_auto_redial_ind_struct*) ind->ptr;
            vapp_ucm_auto_redial_ind(auto_redial_ind);
            vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
        }
        break;

        case SRV_UCM_AUTO_REDIAL_CANCEL_IND:
        {
        }
        break;
		
        case SRV_UCM_START_PROCESSING_IND:
        {
        }
        break;

        case SRV_UCM_STOP_PROCESSING_IND:
        {
        }
        break;

        case SRV_UCM_QUERY_CANCEL_IND:
        {
            vapp_ucm_cancel_confirm();
        }
        break;

        case SRV_UCM_REFRESH_IND:
        {
            vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
        }
        break;

        case SRV_UCM_START_COUNT_IND:
        {
            vapp_ucm_refresh_screen(VAPP_UCM_REFRESH_TYPE_IND, (void*)para);
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


extern "C"
mmi_ret vapp_ucm_conf_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_cnf_ind_evt_struct *cnf_ind;
    srv_ucm_query_cnf_ind_struct *conf_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cnf_ind = (srv_ucm_cnf_ind_evt_struct *) para;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CONF_IND_HDLR_P1, cnf_ind->op_code);
    
    switch (cnf_ind->op_code)
    {

        case SRV_UCM_QUERY_CNF_IND:
        {
            conf_ind = (srv_ucm_query_cnf_ind_struct*) cnf_ind->ptr;
            g_ucm_p->cnf_scr.conf_ind_cb = cnf_ind->cnf_callback;
            
            vapp_ucm_query_cnf_ind(conf_ind);
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

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_speech_status_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the speech indication EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND sent from mdi
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern "C"
mmi_ret vapp_ucm_speech_status_ind_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct* event = (mmi_evt_mdi_audio_speech_ind_struct*)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

    switch (event->status)
    {
        case MDI_AUDIO_SPH_PRE_SPEECH_ON:
        case MDI_AUDIO_SPH_PRE_VOIP_ENCODE_START:    
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PRE_SPEECH_ON_CB_P1, g_ucm_p->call_misc.play_tone);
            /* If speech-on comes while incoming tone is playing, stop incoming tone before turning on speech */
            if (g_ucm_p->call_misc.play_tone != MMI_UCM_NONE)
            {
                vapp_ucm_stop_incoming_tone();
                g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
            }

            mmi_ucm_stop_inband_tone();
        }
        break;

        case MDI_AUDIO_SPH_POST_SPEECH_ON:
        case MDI_AUDIO_SPH_POST_VOIP_ENCODE_START:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_POST_SPEECH_ON_CB);

        }
        break;

        case MDI_AUDIO_SPH_POST_SPEECH_OFF:
        case MDI_AUDIO_SPH_POST_VOIP_ENCODE_STOP:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PRE_SPEECH_OFF_CB);
        }
        break;
        
        default:
        {
            /* do nothing */
        }
        break;
    }

    return MMI_RET_OK;
}

void vapp_ucm_hdlr_make_call_cb(mmi_ucm_after_make_call_cb_struct* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(p->result != SRV_UCM_RESULT_OK &&
        srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL), MMI_FALSE, NULL) == 0)
    {
        vapp_ucm_terminate();
    }

}

//#endif /* __MMI_UCM__ */

