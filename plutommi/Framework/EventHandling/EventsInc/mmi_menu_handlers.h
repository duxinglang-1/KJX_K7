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
 *  mmi_menu_handlers.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Hilite handlers and Hint handlers of menuitems
 *
 * Author:
 * -------
 *  Resource Generator
 *
*==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef _MENUHANDLER_H
#define _MENUHANDLER_H

/* need typedef void (*FuncPtr) (void); before include this file */

/* #define MENU_HILITE_HANDLER_COUNT   120; */
/* #define MENU_HINT_HANDLER_COUNT     11; */

#include "mmi_rp_all_defs.h"
/* Extern functions of Hilite Handler */
extern void mmi_frm_highlight_inline_generic_done(void);
extern void mmi_frm_highlight_input_method_generic(void);
extern void DataConnectGSMHiliteHandler(void);
extern void mmi_fmgr_highlight_to_phb(void);
extern void mmi_fmgr_highlight_to_sms(void);
extern void mmi_fmgr_highlight_audio_play(void);
extern void mmi_mre_shortcut_calculator_highlight_hdlr(void);
extern void mmi_mre_shortcut_health_highlight_hdlr(void);
extern void mmi_mre_shortcut_stopwatch_highlight_hdlr(void);
extern void mmi_mre_shortcut_converter_highlight_hdlr(void);
extern void mmi_mre_shortcut_zakat_highlight_hdlr(void);
extern void mmi_mre_shortcut_egyptcode_highlight_hdlr(void);
extern void mmi_mre_shortcut_girlslot_highlight_hdlr(void);
extern void mmi_mre_shortcut_goldminer_highlight_hdlr(void);
extern void mmi_mre_shortcut_happyegg_highlight_hdlr(void);
extern void mmi_mre_shortcut_happywar_highlight_hdlr(void);
extern void mmi_mre_shortcut_kingcombat_highlight_hdlr(void);
extern void mmi_mre_shortcut_moto_highlight_hdlr(void);
extern void mmi_mre_shortcut_parkour_highlight_hdlr(void);
extern void mmi_mre_shortcut_twitter_highlight_hdlr(void);
extern void mmi_mre_shortcut_gameloft_live_highlight_hdlr(void);
extern void mmi_mre_shortcut_gmobi_appstore_highlight_hdlr(void);
extern void mmi_mre_shortcut_mbounce_appstore_highlight_hdlr(void);
extern void HighlightConnectivity(void);
extern void mmi_ime_commonscreens_highlight_imeoptions(void);
extern void NPR_TTS_MainScreenHighlight(void);
extern void NPR_TTS_MenuScrenHighlight(void);
extern void NPR_TTS_IncomingCallHighlight(void);
extern void NPR_TTS_KeyplayHighlight(void);
extern void NPR_TTS_AboutScreenHighlight(void);
extern void NPR_TTS_VolumeScreenHighlight(void);
extern void NPR_TTS_SmsReadSetingHighlight(void);
extern void NPR_TTS_SmsRecvHighlight(void);
extern void NPR_TTS_SmsAutoHighlight(void);
extern void GB_WG_Search_Web_Highlight_Hdlr(void);
extern void mmi_bt_main_hilight_handler(void);
extern void mmi_secset_main_menu_highlight_hdlr(void);
extern void mmi_camera_hilight_app(void);
extern void mmi_camera_hilight_forward_to_mms(void);
extern void mmi_camera_hilight_app(void);
extern void mmi_imgview_highlight_app(void);
extern void mmi_sndrec_hightlight_main(void);
extern void HighlightWCMenu(void);
extern void HighlightWcBrowseCity(void);
extern void mmi_uc_highlight_send(void);
extern void mmi_uc_highlight_opt_picture_options(void);
extern void mmi_uc_highlight_remove_image(void);
extern void mmi_uc_highlight_opt_sound_options(void);
extern void mmi_uc_highlight_remove_audio(void);
extern void mmi_uc_highlight_opt_video_options(void);
extern void mmi_uc_highlight_remove_video(void);
extern void mmi_uc_highlight_opt_attachment_options(void);
extern void mmi_uc_highlight_remove_attachment(void);
extern void mmi_uc_highlight_opt_add_picture(void);
extern void mmi_uc_highlight_insert_image(void);
extern void mmi_uc_highlight_opt_add_sound(void);
extern void mmi_uc_highlight_insert_audio(void);
extern void mmi_uc_highlight_opt_add_video(void);
extern void mmi_uc_highlight_insert_video(void);
extern void mmi_uc_highlight_opt_preview(void);
extern void mmi_uc_highlight_opt_slide_opt(void);
extern void mmi_uc_highlight_slide_opt_insert(void);
extern void mmi_uc_highlight_slide_opt_insert_before(void);
extern void mmi_uc_highlight_slide_opt_timing(void);
extern void mmi_uc_highlight_slide_opt_delete(void);
extern void mmi_uc_highlight_slide_opt_next(void);
extern void mmi_uc_highlight_slide_opt_previous(void);
extern void mmi_uc_highlight_opt_advance_options(void);
extern void mmi_uc_highlight_insert_text_template(void);
extern void mmi_uc_highlight_insert_attachment(void);
extern void mmi_uc_highlight_save_to_draft(void);
extern void mmi_uc_highlight_opt_remove(void);
extern void mmi_uc_highlight_remove_image(void);
extern void mmi_uc_highlight_remove_audio(void);
extern void mmi_uc_highlight_remove_video(void);
extern void mmi_uc_highlight_remove_attachment(void);
extern void mmi_uc_highlight_done_opt_send(void);
extern void mmi_uc_highlight_exit_opt_save(void);
extern void mmi_uc_highlight_exit_opt_exit(void);
extern void mmi_rmgr_highlight_list_ro(void);
extern void mmi_rmgr_highlight_info(void);
extern void mmi_rmgr_highlight_main(void);
extern void mmi_rmgr_highlight_db_proc(void);
extern void mmi_data_connection_sim_hilite_hdlr(void);
extern void DataConnectHiliteHandler(void);
extern void highlight_mainmenu_profiles(void);
extern void mmi_rmgr_highlight_more_rits(void);
extern void HighlightPhnsetScr(void);
extern void mmi_ime_settings_inputmethodsettings_highlight(void);
extern void HighlightRstScr(void);
extern void mmi_highlight_netset_main(void);
extern void mmi_service_hilite_sat_hdlr(void);
extern void mmi_highlight_shortcuts(void);
extern void HighlightCalcMenu(void);
extern void HighlightAlmMenu(void);
extern void HighlightClndrMenu(void);
extern void mmi_tdl_highlight_menu(void);
extern void mmi_ucm_highlight_call_type_voice(void);
extern void mmi_mot_highlight_app(void);
extern void highlight_mainmenu_messages(void);
extern void mmi_um_highlight_write_msg(void);
extern void mmi_um_highlight_inbox(void);
extern void mmi_um_highlight_draft(void);
extern void mmi_um_highlight_unsent(void);
extern void mmi_um_highlight_sent(void);
extern void mmi_um_highlight_template(void);
extern void mmi_um_highlight_setting(void);
extern void highlight_mainmenu_filemngr(void);
extern void highlight_mainmenu_phonebook(void);
extern void highlight_mainmenu_funandgames(void);
extern void highlight_mainmenu_extra(void);
extern void highlight_mainmenu_calllog(void);
extern void highlight_mainmenu_multimedia(void);
extern void highlight_mainmenu_services(void);
extern void highlight_mainmenu_organizer(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_callcenter(void);
extern void highlight_mainmenu_tools(void);
extern void mmi_nss_hilight(void);


/* Extern functions of Hint Handler */
extern void NPR_TTS_MenuStatus_Hint(U16);
extern void NPR_TTS_IncomingCallHint(U16);
extern void NPR_TTS_KeyplayHint(U16);
extern void NPR_TTS_SmsRecvHint(U16);
extern void NPR_TTS_SmsAutoReadHint(U16);
extern void mmi_rmgr_db_hint(U16);
extern void mmi_rmgr_hint_scan_disk(U16);
extern void mmi_wap_push_enable_push_hint_hdlr(U16);
extern void mmi_wap_push_sl_setting_hint_hdlr(U16);
extern void mmi_fmgri_main_hint_sort(U16);
extern void HintPhnsetPreferedInputMethod(U16);

const mmi_frm_hilite_hdlr_struct mmi_frm_const_hilite_hdlr_table[] = {
    {MENU_DONE_OPTION_ID, mmi_frm_highlight_inline_generic_done},
    {MENU_INPUT_METHOD_OPTION_ID, mmi_frm_highlight_input_method_generic},
    {SERVICES_DATA_CONNECT_MENU_ID, DataConnectGSMHiliteHandler},
    {MENU_ID_FMGR_FWD_CONTACT, mmi_fmgr_highlight_to_phb},
    {MENU_ID_FMGR_FWD_SMS, mmi_fmgr_highlight_to_sms},
    {MENU_ID_FMGR_AUD_OPTION_PLAY, mmi_fmgr_highlight_audio_play},
    {MENU_ID_MRE_APP_CALCULATOR_SHORTCUT, mmi_mre_shortcut_calculator_highlight_hdlr},
    {MENU_ID_MRE_APP_HEALTH_SHORTCUT, mmi_mre_shortcut_health_highlight_hdlr},
    {MENU_ID_MRE_APP_STOPWATCH_SHORTCUT, mmi_mre_shortcut_stopwatch_highlight_hdlr},
    {MENU_ID_MRE_APP_CONVERTER_SHORTCUT, mmi_mre_shortcut_converter_highlight_hdlr},
    {MENU_ID_MRE_APP_ZAKAT_SHORTCUT, mmi_mre_shortcut_zakat_highlight_hdlr},
    {MENU_ID_MRE_APP_EGYPTCODE_SHORTCUT, mmi_mre_shortcut_egyptcode_highlight_hdlr},
    {MENU_ID_MRE_APP_GIRLSLOT_SHORTCUT, mmi_mre_shortcut_girlslot_highlight_hdlr},
    {MENU_ID_MRE_APP_GOLDMINER_SHORTCUT, mmi_mre_shortcut_goldminer_highlight_hdlr},
    {MENU_ID_MRE_APP_HAPPYEGG_SHORTCUT, mmi_mre_shortcut_happyegg_highlight_hdlr},
    {MENU_ID_MRE_APP_HAPPYWAR_SHORTCUT, mmi_mre_shortcut_happywar_highlight_hdlr},
    {MENU_ID_MRE_APP_KINGCOMBAT_SHORTCUT, mmi_mre_shortcut_kingcombat_highlight_hdlr},
    {MENU_ID_MRE_APP_MOTO_SHORTCUT, mmi_mre_shortcut_moto_highlight_hdlr},
    {MENU_ID_MRE_APP_PARKOUR_SHORTCUT, mmi_mre_shortcut_parkour_highlight_hdlr},
    {MENU_ID_MRE_APP_TWITTER_SHORTCUT, mmi_mre_shortcut_twitter_highlight_hdlr},
    {MENU_ID_MRE_APP_GAMELOFT_LIVE_SHORTCUT, mmi_mre_shortcut_gameloft_live_highlight_hdlr},
    {MENU_ID_MRE_APP_GMOBI_APPSTORE_SHORTCUT, mmi_mre_shortcut_gmobi_appstore_highlight_hdlr},
    {MENU_ID_MRE_APP_MBOUNCE_APPSTORE_SHORTCUT, mmi_mre_shortcut_mbounce_appstore_highlight_hdlr},
    {MENU_ID_CONNECTIVITY, HighlightConnectivity},
    {MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, mmi_ime_commonscreens_highlight_imeoptions},
    {MENU_ID_TTS_SETTING, NPR_TTS_MainScreenHighlight},
    {MENU_ID_TTS_MENU_READ, NPR_TTS_MenuScrenHighlight},
    {MENU_ID_TTS_INCOMING_CALL_READ, NPR_TTS_IncomingCallHighlight},
    {MENU_ID_TTS_KEYPAD_READ, NPR_TTS_KeyplayHighlight},
    {MENU_ID_TTS_ABOUT, NPR_TTS_AboutScreenHighlight},
    {MENU_ID_TTS_VOL_SET, NPR_TTS_VolumeScreenHighlight},
    {MENU_ID_TTS_SMS_READ_SET, NPR_TTS_SmsReadSetingHighlight},
    {MENU_ID_TTS_SMS_RECV_READ, NPR_TTS_SmsRecvHighlight},
    {MENU_ID_TTS_SMS_AUTO_READ, NPR_TTS_SmsAutoHighlight},
    {MENU_ID_SEARCH_WEB_WINGUO_ENTRY, GB_WG_Search_Web_Highlight_Hdlr},
    {MENU_CONN_BT_MAIN, mmi_bt_main_hilight_handler},
    {MENU_ID_SECSET_MAIN_MENU, mmi_secset_main_menu_highlight_hdlr},
    {MAIN_MENU_OPTION_CAMERA_APP, mmi_camera_hilight_app},
    {MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS, mmi_camera_hilight_forward_to_mms},
    {MENU_ID_CAMERA_APP, mmi_camera_hilight_app},
    {MENU_ID_IMGVIEW_APP, mmi_imgview_highlight_app},
    {MENU_ID_SNDREC_MAIN, mmi_sndrec_hightlight_main},
    {ORGANIZER_WORLDCLOCK_MENU, HighlightWCMenu},
    {MITEM_WORLDCLOCK_BROWSECITY, HighlightWcBrowseCity},
    {MENU_ID_UC_OPT_SEND, mmi_uc_highlight_send},
    {MENU_ID_UC_OPT_PICTURE_OPTIONS, mmi_uc_highlight_opt_picture_options},
    {MENU_ID_UC_OPT_PICTURE_OPT_IMAGE_REMOVE, mmi_uc_highlight_remove_image},
    {MENU_ID_UC_OPT_SOUND_OPTIONS, mmi_uc_highlight_opt_sound_options},
    {MENU_ID_UC_OPT_AUDIO_OPT_AUDIO_REMOVE, mmi_uc_highlight_remove_audio},
    {MENU_ID_UC_OPT_VIDEO_OPTIONS, mmi_uc_highlight_opt_video_options},
    {MENU_ID_UC_OPT_VIDEO_OPT_VIDEO_REMOVE, mmi_uc_highlight_remove_video},
    {MENU_ID_UC_OPT_ATTACHMENT_OPTIONS, mmi_uc_highlight_opt_attachment_options},
    {MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REMOVE, mmi_uc_highlight_remove_attachment},
    {MENU_ID_UC_OPT_ADD_PICTURE, mmi_uc_highlight_opt_add_picture},
    {MENU_ID_UC_OPT_INSERT_IMAGE, mmi_uc_highlight_insert_image},
    {MENU_ID_UC_OPT_ADD_SOUND, mmi_uc_highlight_opt_add_sound},
    {MENU_ID_UC_OPT_INSERT_AUDIO, mmi_uc_highlight_insert_audio},
    {MENU_ID_UC_OPT_ADD_VIDEO, mmi_uc_highlight_opt_add_video},
    {MENU_ID_UC_OPT_INSERT_VIDEO, mmi_uc_highlight_insert_video},
    {MENU_ID_UC_OPT_PREVIEW, mmi_uc_highlight_opt_preview},
    {MENU_ID_UC_OPT_SLIDE_OPT, mmi_uc_highlight_opt_slide_opt},
    {MENU_ID_UC_OPT_SLIDE_OPT_INSERT, mmi_uc_highlight_slide_opt_insert},
    {MENU_ID_UC_OPT_SLIDE_OPT_INSERT_BEFORE, mmi_uc_highlight_slide_opt_insert_before},
    {MENU_ID_UC_OPT_SLIDE_OPT_TIMING, mmi_uc_highlight_slide_opt_timing},
    {MENU_ID_UC_OPT_SLIDE_OPT_DELETE, mmi_uc_highlight_slide_opt_delete},
    {MENU_ID_UC_OPT_SLIDE_OPT_NEXT, mmi_uc_highlight_slide_opt_next},
    {MENU_ID_UC_OPT_SLIDE_OPT_PREVIOUS, mmi_uc_highlight_slide_opt_previous},
    {MENU_ID_UC_OPT_ADVANCED, mmi_uc_highlight_opt_advance_options},
    {MENU_ID_UC_OPT_INSERT_TEXT_TEMPLATE, mmi_uc_highlight_insert_text_template},
    {MENU_ID_UC_OPT_INSERT_ATTACHMENT, mmi_uc_highlight_insert_attachment},
    {MENU_ID_UC_OPT_SAVE_TO_DRAFT, mmi_uc_highlight_save_to_draft},
    {MENU_ID_UC_OPT_REMOVE, mmi_uc_highlight_opt_remove},
    {MENU_ID_UC_OPT_REMOVE_IMAGE, mmi_uc_highlight_remove_image},
    {MENU_ID_UC_OPT_REMOVE_AUDIO, mmi_uc_highlight_remove_audio},
    {MENU_ID_UC_OPT_REMOVE_VIDEO, mmi_uc_highlight_remove_video},
    {MENU_ID_UC_OPT_REMOVE_ATTACHMENT, mmi_uc_highlight_remove_attachment},
    {MENU_ID_UC_OPT_DONE_SEND, mmi_uc_highlight_done_opt_send},
    {MENU_ID_UC_EXIT_OPT_SAVE, mmi_uc_highlight_exit_opt_save},
    {MENU_ID_UC_EXIT_OPT_EXIT, mmi_uc_highlight_exit_opt_exit},
    {MENU_ID_RMGR_LIST_RO, mmi_rmgr_highlight_list_ro},
    {MENU_ID_RMGR_INFO, mmi_rmgr_highlight_info},
    {MENU_ID_RMGR, mmi_rmgr_highlight_main},
    {MENU_ID_RMGR_DB_PROC, mmi_rmgr_highlight_db_proc},
    {MENU_ID_DATA_CONNECTION_SIM, mmi_data_connection_sim_hilite_hdlr},
    {SERVICES_DATA_CONNECT_MAIN_MENU_ID, DataConnectHiliteHandler},
    {MAIN_MENU_PROFILES_MENUID, highlight_mainmenu_profiles},
    {MENU_ID_FMGR_GEN_OPTION_MORE_RITS, mmi_rmgr_highlight_more_rits},
    {MENU9102_INITIAL_SETUP, HighlightPhnsetScr},
    {MENU_SETTING_PREFERED_INPUT_METHOD, mmi_ime_settings_inputmethodsettings_highlight},
    {MENU_SETTING_RESTORE, HighlightRstScr},
    {MENU_ID_NETSET_MAIN, mmi_highlight_netset_main},
    {MENU_ID_SAT1_ENTRY, mmi_service_hilite_sat_hdlr},
    {EXTRA_SHORTCUTS_MENUID, mmi_highlight_shortcuts},
    {EXTRA_CALCULATOR_MENU, HighlightCalcMenu},
    {ORGANIZER_ALARM_MENU, HighlightAlmMenu},
    {ORGANIZER_CALENDER_MENU, HighlightClndrMenu},
    {ORGANIZER_TODOLIST_MENU, mmi_tdl_highlight_menu},
    {MENU_ID_UCM_CALL_TYPE_VOICE, mmi_ucm_highlight_call_type_voice},
    {MENU_ID_MOT_APP, mmi_mot_highlight_app},
    {MAIN_MENU_MESSAGES_MENUID, highlight_mainmenu_messages},
    {MENU_ID_UM_WRITE_MSG, mmi_um_highlight_write_msg},
    {MENU_ID_UM_INBOX, mmi_um_highlight_inbox},
    {MENU_ID_UM_DRAFT, mmi_um_highlight_draft},
    {MENU_ID_UM_UNSENT, mmi_um_highlight_unsent},
    {MENU_ID_UM_SENT, mmi_um_highlight_sent},
    {MENU_ID_UM_TEMPLATE, mmi_um_highlight_template},
    {MENU_ID_UM_SETTING, mmi_um_highlight_setting},
    {MAIN_MENU_FILE_MNGR_MENUID, highlight_mainmenu_filemngr},
    {MAIN_MENU_PHONEBOOK_MENUID, highlight_mainmenu_phonebook},
    {MAIN_MENU_FUNANDGAMES_MENUID, highlight_mainmenu_funandgames},
    {MAIN_MENU_EXTRA_MENUID, highlight_mainmenu_extra},
    {MAIN_MENU_CALL_LOG, highlight_mainmenu_calllog},
    {MAIN_MENU_MULTIMEDIA_MENUID, highlight_mainmenu_multimedia},
    {MAIN_MENU_SERVICES_MENUID, highlight_mainmenu_services},
    {MAIN_MENU_ORGANIZER_MENUID, highlight_mainmenu_organizer},
    {MAIN_MENU_SETTINGS_MENUID, highlight_mainmenu_settings},
    {MAIN_MENU_SETTINGS_NO_SIM_MENUID, highlight_mainmenu_settings},
    {MAIN_MENU_CALL_CENTER, highlight_mainmenu_callcenter},
    {MAIN_MENU_TOOLS_MENUID, highlight_mainmenu_tools},
    {MENU_ID_NSS_APP, mmi_nss_hilight},
};

const mmi_frm_hint_hdlr_struct mmi_frm_const_hint_hdlr_table[] = {
    {MENU_ID_TTS_MENU_READ, NPR_TTS_MenuStatus_Hint},
    {MENU_ID_TTS_INCOMING_CALL_READ, NPR_TTS_IncomingCallHint},
    {MENU_ID_TTS_KEYPAD_READ, NPR_TTS_KeyplayHint},
    {MENU_ID_TTS_SMS_RECV_READ, NPR_TTS_SmsRecvHint},
    {MENU_ID_TTS_SMS_AUTO_READ, NPR_TTS_SmsAutoReadHint},
    {MENU_ID_RMGR_DB_CHECK, mmi_rmgr_db_hint},
    {MENU_ID_RMGR_SCAN_DISK, mmi_rmgr_hint_scan_disk},
    {MENU_ID_SERVICE_MSG_ENABLE, mmi_wap_push_enable_push_hint_hdlr},
    {MENU_ID_SERVICE_MSG_SL_SETTING, mmi_wap_push_sl_setting_hint_hdlr},
    {MENU_ID_FMGR_GEN_OPTION_SORT, mmi_fmgri_main_hint_sort},
    {MENU_SETTING_PREFERED_INPUT_METHOD, HintPhnsetPreferedInputMethod},
};

#endif /* _MENUHANDLER_H */ 
