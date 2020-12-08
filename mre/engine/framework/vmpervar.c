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
 * vmpermng.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * permng
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__
#include "stdlib.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmgraph.h"
#include "vmmm.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmhttp.h"
#include "vmhttps.h"
#include "vmsock.h"
#include "vmsim.h"
#include "vmres.h"
#include "vmopt.h"
#include "vmsensor.h"
#include "vmcamera.h"
#include "vmtel.h"
#include "vmnvram.h"
#include "vmcermng.h"
#include "vmperdef.h" 
#include "vmpervar.h"
#include "vmfilere.h"
#include "vmrsa.h"
#include "vmdes.h"
#include "vmgettag.h"
#include "vmgfxold.h"
#include "vmbitstream.h"
#include "vmcontact.h"
#include "vmtel.h"
#include "vmsms.h"
#include "vmpromng.h"
#include "vmcell.h"
#include "vmgps.h"
#include "vmmms.h"
#include "vmvideo.h"
#include "vmxml.h"
#include "vmmm.h"
#include "vmmullang.h"
#include "vmkurocore.h"
#include "vmtimer.h"
#include "vmpromnginner.h"
#include "vmsm.h"
#include "vmso.h"
#include "vmtheme.h"
#include "vmstatusbar.h"
#include "vmsrvmng.h"
#include "vmpayment.h"
#include "vmche.h"
#include "vmenv.h"
#include "vmappcomm.h"
#include "vmsettings.h"
#include "vmbtcm.h"
#include "vmbtspp.h"
#include "vmeditor.h"
#include "vmjava.h"
#include "vm4res.h"
#include "vmsettings.h"
#include "vmalarm.h"
#include "vmda.h"
#include "vmsso.h"
#include "vmpn.h"
#include "vmsettings.h"
#include "vmalarm.h"
#include "wgui_include.h"
#include "vmsalui.h"
#include "vmcamera.h"
#include "vmuart.h"
#include "vmtls.h"


extern VMINT vm_send_sms_person(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result));
extern void vm_get_phoneset_info(vm_phoneset_info_struct * phnset_info);
extern void vm_set_phoneset_info(vm_phoneset_info_struct * phnset_info);
extern void vm_play_request_tone(VMINT play_tone);
extern VMINT vm_graphic_active_layer_internal(VMINT handle);
extern VMUINT vm_graphic_get_trans_handle(VMINT handle);
extern VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src);
extern VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);
extern VMWSTR vm_ucs2_string(VMSTR s);


#ifndef __MRE_LIB_XML__
#define vm_xml_set_data_handler (void*)NULL
#define vm_xml_set_data_handler (void*)NULL
#define vm_xml_new_parser (void*)NULL
#define vm_xml_set_element_handlers (void*)NULL
#define vm_xml_get_error (void*)NULL
#define vm_xml_parse (void*)NULL
#define vm_xml_set_doctype_handlers (void*)NULL
#endif

#ifndef __MRE_CORE_SO__
#define vm_load_library (void*)NULL
#define vm_get_symbol (void*)NULL
#define vm_free_library (void*)NULL
#define vm_load_libraryw (void*)NULL
#endif


#ifndef __MRE_CORE_SAFETY__
#define vm_rsa_sign (void*)NULL
#define vm_rsa_sign_by_id (void*)NULL
#define vm_rsa_verify (void*)NULL
#define vm_rsa_verify_by_id (void*)NULL
#define vm_set_sysconf (void*)NULL
#define vm_get_sysconf (void*)NULL
#endif

#ifndef __MRE_CORE_SANDBOX__
#define vm_nvram_get_sym_permission (void*)NULL
#define vm_nvram_set_sym_permission (void*)NULL
#define vm_nvram_set_ban_list (void*)NULL
#define vm_nvram_set_pkey_list (void*)NULL
#endif

#ifndef __MRE_SAL_CHE__
#define vm_che_key_action (void*)NULL
#define vm_che_rsa_private_encrypt (void*)NULL
#define vm_che_process (void*)NULL
#define vm_che_rsa_private_decrypt (void*)NULL
#define vm_che_rsa_public_encrypt (void*)NULL
#define vm_che_set_iv (void*)NULL
#define vm_che_rsa_public_decrypt (void*)NULL
#define vm_che_deinit (void*)NULL
#define vm_che_init (void*)NULL
#endif

#ifndef __MRE_LIB_MULTI_LANG__
#define vm_mul_lang_deinit  (void*)NULL
#define vm_mul_lang_get_lang (void*)NULL
#define  vm_mul_lang_get_string (void*)NULL
#define vm_mul_lang_init (void*)NULL
#define  vm_mul_lang_set_lang (void*)NULL
#define vm_graphic_get_string_width_by_id (void*)NULL
#define vm_graphic_textout_by_id (void*)NULL
#endif

#ifndef __MRE_SAL_STATUS__ 
#define vm_pmng_apply_to_run_in_fg  (void*)NULL
#define vm_graphic_status_icon_bar_hide_callback (void*)NULL
#define vm_graphic_show_status_icon_bar (void*)NULL
#define vm_graphic_show_theme_background (void*)NULL
#define vm_graphic_show_left_softkey (void*)NULL
#define vm_statusbar_new_message (void*)NULL
#define vm_statusbar_set_image (void*)NULL
#endif

#ifndef __MRE_SAL_CHE_DES__
#define vm_des_set_key (void*)NULL
#define vm_des_decrypt (void*)NULL
#define vm_des_reset_key (void*)NULL
#define vm_des_encrypt (void*)NULL
#endif

#ifndef __MRE_LIB_GRAPIC_GFXOLD__
#define vm_dd_active_layer   (void*)NULL
#define vm_dd_blt_all_cutting_frames   (void*)NULL
#define vm_dd_clean   (void*)NULL
#define vm_dd_copy   (void*)NULL
#define vm_dd_flood_4_regional   (void*)NULL
#define vm_dd_get_frame_number   (void*)NULL
#define vm_dd_get_img_property   (void*)NULL
#define vm_dd_img_flood   (void*)NULL
#define vm_dd_initialize_clip_rect   (void*)NULL
#define vm_dd_load_image   (void*)NULL
#define vm_dd_reset_clip   (void*)NULL
#define vm_dd_set_clip   (void*)NULL
#define vm_finalize_screen_buffer   (void*)NULL
#define vm_graph_create_custom_buf   (void*)NULL
#define vm_graph_delete_custom_buf   (void*)NULL
#define vm_graph_drawtext   (void*)NULL
#define vm_graph_move   (void*)NULL
#define vm_graph_release_surface   (void*)NULL
#define vm_graphic_bitblt   (void*)NULL
#define vm_graphic_draw_gif   (void*)NULL
#define vm_graphic_drawline   (void*)NULL
#define vm_graphic_drawrect   (void*)NULL
#define vm_graphic_drawtext   (void*)NULL
#define vm_graphic_fillrect   (void*)NULL
#define vm_graphic_flush_buffer   (void*)NULL
#define vm_graphic_get_buffer   (void*)NULL
#define vm_graphic_lock   (void*)NULL
#define vm_graphic_setpixel   (void*)NULL
#define vm_graphic_unlock   (void*)NULL
#define vm_initialize_screen_buffer   (void*)NULL
#endif


#ifndef __MRE_SAL_BITSTREAM__
#define vm_bitstream_audio_close (void*)NULL
#define vm_bitstream_audio_stop (void*)NULL
#define vm_bitstream_audio_put_data (void*)NULL
#define vm_bitstream_audio_put_frame (void*)NULL
#define vm_bitstream_audio_get_play_time (void*)NULL
#define vm_bitstream_audio_open (void*)NULL
#define vm_bitstream_audio_start (void*)NULL
#define vm_bitstream_audio_get_buffer_status (void*)NULL
#define vm_bitstream_audio_open_pcm (void*)NULL
#define vm_bitstream_audio_register_interrupt_callback (void*)NULL
#define vm_bitstream_audio_clear_interrupt_callback (void*)NULL
#define vm_bitstream_audio_finished (void*)NULL
#endif

#ifndef __MRE_SAL_CAMERA__
#define vm_create_camera_instance (void*)NULL
#define vm_release_camera_instance (void*)NULL
#define vm_get_camera_status (void*)NULL
#define vm_camera_register_notify (void*)NULL
#define vm_camera_get_support_preview_size (void*)NULL
#define vm_camera_set_preview_size (void*)NULL
#define vm_camera_set_preview_fps (void*)NULL
#define vm_camera_preview_start (void*)NULL
#define vm_camera_preview_stop (void*)NULL
#define vm_camera_get_frame (void*)NULL
#define vm_camera_get_max_capture_size (void*)NULL
#define vm_camera_set_capture_size (void*)NULL
#define vm_camera_capture (void*)NULL
#define vm_camera_get_capture_data (void*)NULL
#define vm_camera_get_raw_data_frame (void*)NULL
#define vm_camera_get_default_parameter (void*)NULL
#define vm_camera_get_focus_zone (void*)NULL
#define vm_camera_get_osd_layer_buffer (void*)NULL
#define vm_camera_get_osd_layer_handle (void*)NULL
#define vm_camera_set_camera_id (void*)NULL
#define vm_camera_start_autofocus_process (void*)NULL
#define vm_camera_stop_autofocus_process (void*)NULL
#define vm_camera_update_parameter (void*)NULL
#define vm_camera_get_sub_camera_id (void*)NULL
#define vm_camera_get_main_camera_id (void*)NULL
#define vm_camera_get_support_capture_size (void*)NULL
#define vm_camera_is_support_dual_camera (void*)NULL
#define vm_camera_register_rotation_callback (void*)NULL
#define vm_camera_set_capture_rotation (void*)NULL
#define vm_camera_update_para_image_size (void*)NULL
#define vm_camera_set_auto_detect_mode (void*)NULL
#define vm_camera_enable_osd_layer (void*)NULL
#define vm_camera_set_lcd_update (void*)NULL
#define vm_camera_is_horizontal_sensor (void*)NULL
#define vm_camera_set_capture_disable_jaia (void*)NULL
#define vm_camera_rotate_osd_layer (void*)NULL
#define vm_camera_set_preview_origin (void*)NULL
#define vm_camera_use_anonymous_memory (void*)NULL
#endif


#define vm_midi_play (void*)NULL
#define vm_midi_play_ex (void*)NULL
#define vm_set_ringtone (void*)NULL

#ifndef __MRE_SAL_GPS__
#define vm_gps_get_vtg_data NULL
#define vm_gps_get_gll_data NULL
#define vm_gps_close NULL
#define vm_gps_get_rmc_data NULL
#define vm_gps_get_gsv_data NULL
#define vm_gps_open NULL
#define vm_gps_get_gga_data NULL
#define vm_gps_get_gsa_data NULL
#endif
#ifndef __MRE_SAL_CELL__
#define vm_cell_get_nbr_cell_info NULL
#define vm_cell_open NULL
#define vm_cell_close NULL
#define vm_cell_get_nbr_num NULL
#define vm_cell_get_cur_cell_info NULL
#endif

#ifndef __MRE_SAL_VIDEO__
#define vm_video_open_file NULL
#define vm_video_close_file NULL
#define vm_video_open_buffer NULL
#define vm_video_close_buffer NULL
#define vm_video_play NULL
#define vm_video_stop NULL
#define vm_video_pause NULL
#define vm_video_resume NULL
#define vm_video_seek_and_getframe NULL
#define vm_video_snapshot NULL
#define vm_video_set_brightness NULL
#define vm_video_set_contrast NULL
#define vm_video_get_cur_play_time NULL
#define vm_video_play_stream_from_rtsp_link NULL
#define vm_video_play_stream_from_sdp_file NULL
#define vm_video_play_by_filepath NULL
#endif

#ifndef __MRE_SAL_SENSOR__
#define vm_srv_sensor_start_listen (void*)NULL
#define vm_srv_sensor_stop_listen (void*)NULL
#define vm_srv_sensor_enable_mode (void*)NULL
#define vm_srv_sensor_disable_mode (void*)NULL
#endif

#ifndef __MRE_CORE_SM__
#define vm_sm_set_sb_by_handle (void*)NULL
#define vm_sm_set_sb_for_invoker (void*)NULL
#define vm_sm_get_func_entry (void*)NULL
#define vm_sm_exit (void*)NULL
#define vm_sm_load (void*)NULL
#define vm_sm_get_filename (void*)NULL
#define vm_reg_sm_callback (void*)NULL
#define vm_sm_loadw (void*)NULL
#define vm_sm_reset_sb (void*)NULL
#define vm_sm_unload (void*)NULL
#define vm_sm_set_sb_by_ptr (void*)NULL
#define vm_sm_reg_msg_proc (void*)NULL
#define vm_sm_get_handle_by_package_name (void*)NULL
#endif

const void * FuncList[TOTAL_COUNTER] = {
// FuncSrc
(void *)vm_graphic_create_canvas_cf,
(void *)vm_pmng_get_handle,
(void *)vm_sso_get_account_count,
(void *)vm_graphic_get_character_height,
(void *)vm_sscanf,
(void *)vm_appmgr_activate_screen_lock,
(void *)vm_editor_set_bg_border_style,
(void *)vm_graph_blt_all_cutting_frames,
(void *)vm_graphic_measure_character,
(void *)vm_graph_create_custom_buf,
(void *)vm_res_get_audio,
(void *)strtol,
(void *)vm_graph_initialize_clip_rect,
(void *)vm_dd_copy,
(void *)strtoi,
(void *)vm_graphic_textout_to_layer_by_baseline,
(void *)vm_graphic_line_cf,
(void *)vm_graphic_textout_to_layer,
(void *)vm_update_download,
(void *)vm_cache_read_char,
(void *)vm_sso_get_accounts,
(void *)rand,
(void *)vm_graphic_rect,
(void *)vm_graphic_is_use_vector_font,
(void *)vm_malloc_topmost,
(void *)vm_dd_line_ex,
(void *)vm_get_language_ssc,
(void *)vm_appmgr_activate_wallpaper,
(void *)vm_uart_close,
(void *)vm_safe_wstrcpy,
(void *)vm_graphic_blt,
(void *)vm_graph_rotate,
(void *)vm_mul_lang_get_lang,
(void *)vm_video_is_support_sdp_file_play,
(void *)vm_lower_case,
(void *)vm_dd_rotate_ex,
(void *)vm_get_path,
(void *)vm_create_service,
(void *)vm_get_vm_tag,
(void *)vm_graphic_draw_gif,
(void *)vm_sso_cancel,
(void *)vm_res_get_image_with_header,
(void *)srand,
(void *)vm_graphic_flatten_canvas_ex,
(void *)vm_graph_drawtext,
(void *)vm_graphic_flush_layer,
(void *)vm_graphic_get_layer_count,
(void *)vm_resource_get_data_from_file,
(void *)vm_load_resource,
(void *)vm_video_is_support_rtsp_link_play,
(void *)vm_graphic_get_char_baseline_alllang,
(void *)vm_graphic_get_canvas_buffer_size,
(void *)vm_is_empty_stack,
(void *)vm_statusbar_set_image_ex,
(void *)vm_graphic_set_pixel,
(void *)vm_graphic_draw_gif_image_from_memory,
(void *)vm_dd_set_clip,
(void *)vm_get_multi_tags,
(void *)wstrcmp,
(void *)vm_graphic_get_pixel_cf,
(void *)vm_graph_blt,
(void *)vm_graphic_get_buffer,
(void *)vm_editor_close,
(void *)vm_free_library,
(void *)vm_dd_blt_all_cutting_frames,
(void *)vm_common_ui_show,
(void *)vm_graphic_line,
(void *)vm_graphic_get_highest_char_height_of_all_language,
(void *)vm_graphic_set_clip,
(void *)vm_pmng_get_current_handle,
(void *)vm_graphic_setpixel,
(void *)vm_ucs2_to_default,
(void *)vm_res_load_image_end,
(void *)vm_graphic_fill_roundrect_cf,
(void *)vm_sso_logout_account,
(void *)vm_graphic_set_font,
(void *)vm_graphic_line_ex,
(void *)vm_graphic_ellipse,
(void *)vm_graphic_fill_ellipse_ex,
(void *)vm_wstarts_with,
(void *)vm_common_ui_cancel,
(void *)vm_graphic_load_image,
(void *)vm_get_mre_modules,
(void *)vm_is_finger_touch_version,
(void *)vm_graphic_get_character_width,
(void *)vm_graph_set_font,
(void *)vm_graphic_getcolor_argb,
(void *)vm_graphic_flatten_canvas,
(void *)vm_graphic_set_pixel_ex,
(void *)vm_sso_get_provider_count,
(void *)vm_appmgr_is_support_launcher,
(void *)vm_graphic_bitblt,
(void *)vm_get_curr_utc,
(void *)vm_mul_lang_set_lang,
(void *)vm_realloc,
(void *)vm_get_resource_offset,
(void *)vm_editor_restore,
(void *)vm_graphic_flush_layer_ex,
(void *)vm_graphic_roundrect,
(void *)vm_wstrcpy,
(void *)vm_graphic_get_pixel,
(void *)vm_graphic_canvas_set_trans_color,
(void *)vm_res_get_audio_and_size_from_file,
(void *)vm_wstrcmp,
(void *)vm_editor_set_text_color,
(void *)vm_graphic_textout_by_baseline,
(void *)vm_graphic_layer_set_trans_color,
(void *)vm_get_sys_scene,
(void *)vm_graphic_gradient_paint_rect,
(void *)vm_graphic_fill_rect_cf,
(void *)vm_graph_get_img_property,
(void *)vm_uncompress,
(void *)wstrncpy,
(void *)vm_free,
(void *)vm_mms_launch,
(void *)vm_get_mre_total_mem_size,
(void *)vm_graph_set_clip,
(void *)vm_mul_lang_init,
(void *)vm_graphic_clear_layer_bg,
(void *)vm_graph_flush_buffer,
(void *)vm_vwsprintf,
(void *)vm_editor_get_active_editor,
(void *)vm_graphic_fill_roundrect,
(void *)vm_graph_get_character_width,
(void *)vm_graphic_load_gif_frame_resized_by_percent,
(void *)vm_reg_pen_callback,
(void *)vm_malloc,
(void *)vm_dd_clean_ex,
(void *)vm_graphic_line_style,
(void *)vm_dd_blt,
(void *)vm_editor_show_from_first_line,
(void *)vm_setting_get_date_format,
(void *)vm_graphic_create_layer,
(void *)vm_graph_clean,
(void *)vm_sm_set_sb_by_ptr,
(void *)vm_graphic_flatten_layer_ex,
(void *)vm_pmng_reset_ctx,
(void *)vm_audio_resume_bg_play,
(void *)vm_startup_email,
(void *)vm_editor_get_size,
(void *)vm_graphic_load_gif_frame_cf,
(void *)vm_dd_flood_4_regional,
(void *)vm_settings_set_wallpaper,
(void *)vm_sso_get_credentials,
(void *)vm_graphic_create_canvas,
(void *)vm_graph_reset_clip,
(void *)vm_graphic_rect_cf,
(void *)get_today_from_2000,
(void *)vm_res_get_image_and_size_from_rom,
(void *)vm_chset_convert,
(void *)vm_sso_get_provider_icon,
(void *)vm_editor_set_multiline_text_font,
(void *)vm_dd_blt_with_opacity,
(void *)vm_get_default_folder_path,
(void *)vm_graphic_canvas_set_trans_color_argb,
(void *)vm_graph_mirror,
(void *)vm_graphic_rotate,
(void *)vm_sm_get_handle_by_package_name,
(void *)vm_graphic_rotate_layer,
(void *)wstrcpy,
(void *)vm_statusbar_get_height,
(void *)vm_graphic_load_gif_frame_resized,
(void *)vm_write_cache,
(void *)vm_appmgr_is_screen_lock_activated,
(void *)vm_editor_set_imui_background_filler,
(void *)vm_app_log,
(void *)vm_pmng_state,
(void *)vm_java_is_removed,
(void *)vm_editor_set_default_text,
(void *)vm_write_to_uart,
(void *)vm_editor_set_cursor_color,
(void *)vm_appmgr_get_installed_list,
(void *)vm_graph_finalize,
(void *)vm_ucs2_to_gb2312,
(void *)vm_graphic_layer_toggle_double,
(void *)vm_appmgr_is_support_widget,
(void *)vm_res_get_image,
(void *)vm_gb2312_string,
(void *)vm_graphic_reset_text_clip,
(void *)vm_graphic_set_alpha_blending_layer,
(void *)vm_mul_lang_deinit,
(void *)vm_pen_configure_sampling_period,
(void *)vm_ascii_to_ucs2,
(void *)vm_graphic_set_layer_clip,
(void *)vm_load_virtual_resource,
(void *)vm_graphic_get_string_width,
(void *)vm_setting_get_date_seperator,
(void *)vm_editor_redraw_floating_ui_within_rect,
(void *)vm_graphic_get_frame_number,
(void *)vm_sso_get_providers,
(void *)vm_update_check_version,
(void *)vm_graphic_get_layer_buffer,
(void *)vm_editor_get_pos,
(void *)vm_graphic_show_status_icon_bar,
(void *)vm_graphic_create_layer_cf,
(void *)vm_get_language,
(void *)vm_dd_rect_ex,
(void *)vm_set_app_desired_input_mode,
(void *)vm_load_resource_from_file,
(void *)vm_editor_set_text,
(void *)vm_graphic_get_layer_buffer_size,
(void *)vm_folder_browser_run,
(void *)vm_editor_get_fit_height,
(void *)vm_finalize_screen_buffer,
(void *)vm_graphic_release_canvas_ex,
(void *)vm_graphic_blt_ex,
(void *)vm_graphic_roundrect_cf,
(void *)vm_graph_draw_gif,
(void *)vm_sso_refresh_credentials,
(void *)vm_get_system_driver,
(void *)vm_graphic_get_char_num_in_width_ex,
(void *)vm_graphic_create_layer_ex,
(void *)vm_graphic_load_image_resized_cf,
(void *)vm_set_mainlcd_brightness,
(void *)vm_graphic_release_canvas,
(void *)vm_graphic_dynamic_switch_cacheable_region,
(void *)vm_graphic_flush_layer_non_block,
(void *)vm_set_key_tone_on,
(void *)vm_graphic_get_string_height,
(void *)vm_graphic_getcolor,
(void *)vm_graph_getpixel,
(void *)vm_update_update_file,
(void *)vm_get_resource_offset_from_file,
(void *)vm_graphic_textout_cf,
(void *)vm_graphic_draw_image_from_memory,
(void *)vm_reg_func_callback,
(void *)vm_graphic_reset_status_icon_bar,
(void *)vm_graphic_fill_polygon,
(void *)vm_calloc,
(void *)vm_statusbar_set_image,
(void *)vm_popup_stack,
(void *)vm_dd_active_layer,
(void *)vm_graphic_layer_set_trans_color_argb,
(void *)vm_read_cache,
(void *)vm_res_load_image_start,
(void *)vm_graphic_flush_layer_non_block_ex,
(void *)vm_graphic_create_layer_cf_double,
(void *)vm_editor_get_cursor_index,
(void *)vm_is_support_downloadable_app_icon,
(void *)vm_dd_load_image,
(void *)vm_graph_get_frame_number,
(void *)vm_sm_unload,
(void *)vm_malloc_nc_topmost,
(void *)vm_get_imei_ext,
(void *)vm_get_symbol,
(void *)vm_is_exist_stack,
(void *)vm_graph_get_screen_width,
(void *)vm_editor_set_pos,
(void *)vm_sms_launch,
(void *)vm_sso_get_provider_name,
(void *)vm_graph_load_image,
(void *)vm_sso_get_provider,
(void *)vm_malloc_nc,
(void *)vm_graphic_fill_rect,
(void *)vm_set_touch_feedback,
(void *)vm_dd_mirror,
(void *)vm_res_get_image_and_size_with_header,
(void *)vm_graphic_rect_ex,
(void *)vm_get_string_width_height_ex,
(void *)vm_get_exec_filename,
(void *)vm_get_filename,
(void *)vm_pmng_set_fg,
(void *)vm_ends_with,
(void *)vm_settings_set_tone,
(void *)vm_graph_move,
(void *)vm_graphic_drawline,
(void *)vm_kbd_set_mode,
(void *)vm_graphic_ellipse_ex,
(void *)vm_editor_set_softkey,
(void *)vm_dd_line,
(void *)vm_graphic_draw_abm_text,
(void *)vm_graphic_flush_screen,
(void *)vm_editor_set_layer_handle,
(void *)vm_create_timer,
(void *)vm_graphic_is_dynamic_switch_cacheable_region,
(void *)vm_dyn_array_del,
(void *)vm_update_cancel,
(void *)vm_graphic_load_image_cf,
(void *)vm_appmgr_is_launcher_activated,
(void *)vm_graphic_set_layer_opacity,
(void *)vm_appmgr_is_support_wallpaper,
(void *)vm_string_equals_ignore_case,
(void *)vm_graph_get_buffer,
(void *)vm_exit_app,
(void *)vm_dyn_array_add,
(void *)vm_editor_set_update_text_callback,
(void *)vm_dd_copy_ex,
(void *)vm_graphic_get_img_property_from_file,
(void *)vm_wends_with,
(void *)vm_graphic_get_layer_position,
(void *)vm_editor_save,
(void *)vm_graph_measure_character,
(void *)vm_wstrlen,
(void *)vm_reg_sysevt_callback,
(void *)vm_global_get_max_alloc_size,
(void *)vm_dd_get_img_property,
(void *)vm_global_free,
(void *)vm_sm_reset_sb,
(void *)vm_set_key_tone_off,
(void *)vm_appmgr_is_wallpaper_activated,
(void *)vm_sla_custom_logging,
(void *)vm_font_set_font_style,
(void *)vm_is_support_pen_touch,
(void *)vm_process_java_app,
(void *)vm_dd_rotate,
(void *)vm_input_text3,
(void *)vm_input_text2,
(void *)vm_resource_get_data,
(void *)vm_multi_touch_set_mode,
(void *)vm_graphic_roundrect_ex,
(void *)vm_create_timer_ex,
(void *)vm_reg_sm_callback,
(void *)vm_create_dyn_array,
(void *)vm_editor_insert_string,
(void *)vm_push_stack,
(void *)vm_sm_get_filename,
(void *)vm_graph_get_string_width,
(void *)vm_sso_get_account,
(void *)vm_get_sys_time_zone,
(void *)vm_graphic_set_pixel_cf,
(void *)vm_graphic_textout,
(void *)vm_get_mre_version,
(void *)vm_dd_fillrect,
(void *)vm_graphic_set_text_clip,
(void *)vm_sso_add_account,
(void *)vm_editor_get_font_attribute,
(void *)vm_graphic_fill_rect_ex,
(void *)vm_graphic_fill_roundrect_ex,
(void *)vm_get_multi_tags_by_lang_id,
(void *)vm_graph_release_surface,
(void *)vm_res_get_string_and_size_from_file,
(void *)vm_reg_keyboard_callback,
(void *)vm_graphic_show_truncated_text,
(void *)vm_graphic_get_character_info,
(void *)vm_editor_create,
(void *)vm_graphic_load_gif_resized_by_percent_cf,
(void *)vm_editor_set_margin,
(void *)vm_dd_reset_clip,
(void *)vm_graphic_get_char_height_alllang,
(void *)vm_graphic_fill_ellipse_cf,
(void *)wstrlen,
(void *)vm_graphic_translate_layer,
(void *)vm_editor_set_size,
(void *)vm_input_set_editor_title,
(void *)vm_graphic_get_bits_per_pixel,
(void *)vm_res_get_string,
(void *)vm_get_sys_property,
(void *)vm_graphic_get_blt_layer,
(void *)vm_graphic_get_string_baseline,
(void *)vm_graph_img_flood,
(void *)vm_res_get_string_and_size_from_rom,
(void *)vm_sm_load,
(void *)vm_editor_get_softkey_height,
(void *)vm_graphic_setcolor_argb,
(void *)vm_sm_exit,
(void *)vm_dd_initialize_clip_rect,
(void *)vm_input_close_screen,
(void *)vm_sim_get_prefer_sim_card,
(void *)vm_url_decode_gb2312,
(void *)atof,
(void *)vm_uriagent_uri_request,
(void *)vm_graphic_textout_by_id,
(void *)vm_dd_getpixel,
(void *)vm_dd_mirror_ex,
(void *)vm_appmgr_get_mem_size,
(void *)vm_ucs2_to_ascii,
(void *)vm_editor_redraw_ime_screen,
(void *)vm_graphic_flush_buffer,
(void *)vm_reset_stack,
(void *)vm_dd_img_flood,
(void *)vm_graphic_get_screen_height,
(void *)vm_res_init,
(void *)vm_res_get_image_and_size_from_file,
(void *)vm_graphic_setpen,
(void *)vm_destroy_stack,
(void *)vm_read_from_uart,
(void *)vm_graphic_active_layer_internal,
(void *)vm_get_current_lang_country_code,
(void *)vm_create_linked_stack,
(void *)vm_graphic_draw_image_from_file,
(void *)vm_get_cache_free_space,
(void *)vm_res_init_with_language,
(void *)vm_input_set_vk_default_enlarge,
(void *)vm_graphic_set_blt_layer,
(void *)vm_audio_suspend_bg_play,
(void *)vm_graph_get_character_height,
(void *)vm_input_move_cursor_to_start,
(void *)vm_graphic_unlock,
(void *)vm_editor_set_cursor_index,
(void *)vm_reg_msg_proc,
(void *)vm_editor_get_text,
(void *)vm_dyn_array_del_all,
(void *)vm_sso_login_account,
(void *)vm_dd_setpixel,
(void *)vm_editor_get_indicator_height,
(void *)vm_res_get_virtual_image,
(void *)vm_graphic_get_img_buffer,
(void *)vm_multi_touch_get_mode,
(void *)vm_statusbar_new_message,
(void *)vm_pmng_set_ctx,
(void *)vm_pmng_get_process_list,
(void *)vm_get_removeable_driver,
(void *)vm_delete_timer_ex,
(void *)vm_dd_rect,
(void *)vm_res_get_image_and_size,
(void *)vm_graph_setpixel,
(void *)vm_editor_activate,
(void *)vm_graph_line,
(void *)vm_graphic_load_gif_frame_resized_by_percent_cf,
(void *)vm_ucs2_string,
(void *)vm_switch_power_saving_mode,
(void *)vm_load_library,
(void *)vm_graph_copy,
(void *)vm_dd_get_frame_number,
(void *)vm_graphic_get_canvas_buffer,
(void *)vm_graph_get_screen_height,
(void *)vm_graphic_get_screen_width,
(void *)vm_graphic_drawtext,
(void *)vm_graphic_load_gif_frame_resized_cf,
(void *)vm_editor_show,
(void *)vm_ucs2_string_by_ascii,
(void *)vm_graphic_fillrect,
(void *)vm_graphic_get_blt_layer_count,
(void *)vm_sm_get_func_entry,
(void *)vm_graphic_draw_resized_image_from_file,
(void *)vm_get_tick_count,
(void *)vm_pmng_get_app_handle,
(void *)vm_get_time,
(void *)vm_graphic_get_string_width_by_id,
(void *)vm_graph_fillrect,
(void *)vm_get_res_header,
(void *)vm_appmgr_install,
(void *)vm_graphic_delete_layer,
(void *)vm_graphic_draw_resized_image_from_memory,
(void *)vm_is_support_gsensor,
(void *)vm_get_customer_name,
(void *)vm_graphic_get_char_num_in_width,
(void *)vm_start_app_with_para,
(void *)vm_graph_delete_custom_buf,
(void *)vm_graphic_ellipse_cf,
(void *)vm_reg_keyboard_callback_ex,
(void *)vm_mul_lang_get_string,
(void *)vm_appmgr_is_installed,
(void *)vm_initialize_screen_buffer,
(void *)vm_get_language_num,
(void *)vm_send_msg,
(void *)vm_post_msg,
(void *)vm_graph_rect,
(void *)vm_dialer_launch,
(void *)vm_sso_get_account_name,
(void *)vm_load_libraryw,
(void *)vm_sm_set_sb_for_invoker,
(void *)vm_camera_startup,
(void *)vm_graphic_is_r2l_state,
(void *)vm_graphic_fill_ellipse,
(void *)vm_sm_set_sb_by_handle,
(void *)vm_appmgr_uninstall,
(void *)vm_get_keypad_type,
(void *)vm_graphic_load_image_resized,
(void *)vm_vsprintf,
(void *)vm_graphic_flatten_layer,
(void *)vm_uart_open,
(void *)vm_upper_case,
(void *)vm_graphic_load_gif_frame,
(void *)vm_appmgr_get_install_info,
(void *)vm_get_malloc_stat,
(void *)vm_dd_clean,
(void *)vm_editor_is_draw_floating_indicator,
(void *)vm_editor_set_bg_image,
(void *)vm_alarm_cancel,
(void *)vm_graphic_get_trans_handle,
(void *)vm_dd_blt_ex,
(void *)vm_graphic_get_img_property_ex,
(void *)vm_graphic_resize_layer,
(void *)vm_alarm_set,
(void *)vm_wstrncpy,
(void *)vm_global_malloc,
(void *)vm_dd_getpixel_ex,
(void *)vm_res_delete,
(void *)vm_delete_timer,
(void *)vm_graphic_setcolor,
(void *)vm_graphic_getpen,
(void *)vm_folder_selector_run,
(void *)vm_input_text,
(void *)vm_get_tag_by_lang_id,
(void *)vm_graphic_draw_resized_gif_image_from_memory,
(void *)vm_realloc_topmost,
(void *)vm_res_deinit,
(void *)vm_multi_touch_register_proc,
(void *)vm_editor_get_extra_imui_layer_handler,
(void *)vm_editor_set_IME,
(void *)vm_free_dyn_array,
(void *)vm_wstrcat,
(void *)vm_graphic_2d_linear_transform,
(void *)vm_editor_set_update_text_with_cursor_rect_callback,
(void *)vm_get_key_tone_state,
(void *)vm_graphic_get_img_property,
(void *)vm_graphic_load_gif_resized_by_percent,
(void *)vm_res_get_audio_and_size_from_rom,
(void *)vm_pmng_get_process_property,
(void *)vm_graphic_mirror,
(void *)vm_dd_setpixel_ex,
(void *)vm_start_app,
(void *)vm_editor_deactivate,
(void *)vm_appmgr_activate_launcher,
(void *)vm_sso_del_account,
(void *)wstrcat,
(void *)vm_graphic_lock,
(void *)vm_is_support_keyborad,
(void *)vm_default_to_ucs2,
(void *)vm_graphic_get_layer_clip,
(void *)vm_get_origin_release_verno,
(void *)vm_appmgr_is_support_screen_lock,
(void *)vm_set_key_tone_state,
(void *)vm_setting_get_time_format,
(void *)vm_editor_show_from_start,
(void *)vm_graphic_reset_clip,
(void *)vm_gb2312_to_ucs2,
(void *)vm_srv_nw_info_get_protocol,
(void *)vm_get_battery_level,
(void *)vm_reg_res_provider,
(void *)vm_peek_stack,
(void *)vm_graphic_drawrect,
(void *)vm_graph_get_bits_per_pixel,
(void *)vm_start_native_browser,
(void *)vm_sm_reg_msg_proc,
(void *)vm_graphic_polygon,
(void *)vm_graph_initialize,
(void *)vm_read_line,
(void *)vm_create_array_stack,
(void *)vm_frm_screen_rotate,
(void *)NULL,
(void *)vm_font_set_font_size,
(void *)vm_graphic_textout_by_baseline_cf,
(void *)vm_graphic_active_layer,
(void *)vm_sm_loadw,

// peraudio
(void *)vm_midi_resume,
(void *)vm_midi_play_by_bytes_ex,
(void *)vm_midi_pause,
(void *)vm_midi_stop,
(void *)vm_midi_play,
(void *)vm_audio_mixed_stop,
(void *)vm_audio_resume,
(void *)vm_midi_play_by_bytes,
(void *)vm_midi_get_time,
(void *)vm_audio_terminate_background_play,
(void *)vm_set_volume,
(void *)vm_audio_mixed_pause,
(void *)vm_audio_mixed_close_all,
(void *)vm_audio_play_beep,
(void *)vm_audio_set_volume_type,
(void *)vm_audio_pause,
(void *)vm_audio_stop_all,
(void *)vm_vibrator_off,
(void *)vm_vibrator_on,
(void *)vm_audio_mixed_get_time,
(void *)vm_audio_mixed_resume,
(void *)vm_audio_stop,
(void *)vm_midi_set_type,
(void *)vm_vibrator_once,
(void *)vm_audio_mixed_set_start_time,
(void *)vm_midi_stop_all,
(void *)vm_audio_register_interrupt_callback,
(void *)vm_audio_play_file,
(void *)vm_audio_bytes_duration,
(void *)vm_audio_duration,
(void *)vm_audio_mixed_open,
(void *)vm_midi_play_ex,
(void *)vm_set_ringtone,
(void *)vm_audio_clear_interrupt_callback,
(void *)vm_audio_mixed_close,
(void *)vm_audio_mixed_play,
(void *)vm_get_volume,
(void *)vm_audio_mixed_set_speedup_mode,
(void *)vm_audio_get_time,
(void *)vm_audio_is_calling,
(void *)vm_audio_play_file_ex,
(void *)vm_audio_is_app_playing,
(void *)vm_audio_play_bytes,
(void *)vm_audio_play_bytes_no_block,

// percallout
(void *)vm_ivr_end,
(void *)vm_ivr_call,
(void *)vm_callout_ex,
(void *)vm_ivr_dial_number,
(void *)vm_callout,

// percam
(void *)vm_get_camera_status,
(void *)vm_camera_get_support_preview_size,
(void *)vm_camera_set_camera_id,
(void *)vm_camera_preview_stop,
(void *)vm_camera_get_sub_camera_id,
(void *)vm_camera_get_capture_data,
(void *)vm_camera_set_preview_size,
(void *)vm_camera_rotate_osd_layer,
(void *)vm_create_camera_instance,
(void *)vm_camera_get_raw_data_frame,
(void *)vm_camera_set_capture_size,
(void *)vm_camera_get_frame,
(void *)vm_camera_start_autofocus_process,
(void *)vm_camera_set_preview_origin,
(void *)vm_camera_set_lcd_update,
(void *)vm_camera_set_capture_rotation,
(void *)vm_camera_stop_autofocus_process,
(void *)vm_camera_register_notify,
(void *)vm_camera_get_max_capture_size,
(void *)vm_camera_capture,
(void *)vm_camera_enable_osd_layer,
(void *)vm_camera_get_osd_layer_handle,
(void *)vm_camera_register_rotation_callback,
(void *)vm_camera_get_main_camera_id,
(void *)vm_camera_get_osd_layer_buffer,
(void *)vm_camera_get_default_parameter,
(void *)vm_camera_set_preview_fps,
(void *)vm_camera_is_horizontal_sensor,
(void *)vm_camera_set_capture_disable_jaia,
(void *)vm_camera_get_support_capture_size,
(void *)vm_camera_set_auto_detect_mode,
(void *)vm_camera_preview_start,
(void *)vm_camera_use_anonymous_memory,
(void *)vm_camera_is_support_dual_camera,
(void *)vm_camera_get_focus_zone,
(void *)vm_camera_update_para_image_size,
(void *)vm_release_camera_instance,
(void *)vm_camera_update_parameter,

// perfile
(void *)vm_find_next,
(void *)vm_find_first_remap_ext,
(void *)vm_find_close,
(void *)vm_selector_run,
(void *)vm_file_delete_remap,
(void *)vm_file_tell,
(void *)vm_file_rename_remap,
(void *)vm_file_rmdir_remap,
(void *)vm_fs_async_abort,
(void *)vm_fs_async_get_working_buf_size,
(void *)vm_fs_async_read,
(void *)vm_file_write,
(void *)vm_find_next_ext,
(void *)vm_fs_async_commit,
(void *)vm_file_copy_abort,
(void *)vm_find_close_ext,
(void *)vm_file_close,
(void *)vm_file_set_attributes_remap,
(void *)vm_get_disk_info,
(void *)vm_fs_async_close,
(void *)vm_fs_async_open,
(void *)vm_file_copy,
(void *)vm_fs_async_delete,
(void *)vm_file_is_eof,
(void *)vm_file_commit,
(void *)vm_file_seek,
(void *)vm_file_getfilesize,
(void *)vm_fs_async_seek,
(void *)vm_file_mkdir_remap,
(void *)vm_file_get_attributes_remap,
(void *)vm_fs_async_write,
(void *)vm_file_read,
(void *)vm_get_disk_free_space,
(void *)vm_file_get_modify_time,
(void *)vm_kbd_is_key_supported,
(void *)vm_find_first_remap,
(void *)vm_file_open_remap,

// perhttp
(void *)vm_https_send_set_channel_req,
(void *)vm_https_send_post_content_res,
(void *)mre_https_init,
(void *)vm_http_reg_sender,
(void *)vm_http_set_current_handle,
(void *)vm_http_recv_data,
(void *)mre_https_send_unset_channel_req,
(void *)vm_http_set_url,
(void *)vm_asyn_http_req,
(void *)get_http_head_number,
(void *)vm_http_reg_receiver,
(void *)get_http_head,
(void *)vm_reg_http_notification,
(void *)vm_https_send_read_content_req,
(void *)vm_da_http_start_download,
(void *)vm_open_wap_url,
(void *)vm_https_is_supported,
(void *)vm_http_set_body,
(void *)vm_url_encode_gb2312,
(void *)vm_da_http_dl_operation,
(void *)mre_https_send_read_content_req,
(void *)vm_http_send_data,
(void *)vm_http_request,
(void *)vm_http_get_current_handle,
(void *)mre_https_send_cancel_req,
(void *)vm_enable_proxy,
(void *)mre_https_send_set_channel_req,
(void *)vm_get_asyn_http_req_handle,
(void *)vm_https_send_req,
(void *)vm_https_register_wps_cntxt_and_callback,
(void *)vm_cancel_asyn_http_req,
(void *)mre_https_send_req,
(void *)vm_cancel_all_http_sessions,
(void *)vm_http_free_handle,
(void *)vm_https_send_req_ext,
(void *)vm_https_send_cancel_req,
(void *)vm_http_fetch_handle,
(void *)vm_http_add_header,
(void *)mre_https_register_wps_cntxt_and_callback,
(void *)get_http_head_by_index,
(void *)vm_https_send_unset_channel_req,
(void *)vm_da_display_download_list,

// perrecord
(void *)vm_record_resume,
(void *)vm_record_stop,
(void *)vm_record_start,
(void *)vm_record_pause,

// persensor
(void *)vm_srv_sensor_stop_listen,
(void *)vm_srv_sensor_start_listen,
(void *)vm_srv_sensor_disable_mode,
(void *)vm_srv_sensor_enable_mode,
(void *)vm_srv_sensor_is_available,

// persim
(void *)vm_get_imsi,
(void *)vm_get_imei,
(void *)vm_get_sim_card_status,
(void *)vm_query_operator_code,
(void *)vm_has_sim_card,
(void *)vm_sim_card_count,
(void *)vm_sim_max_card_count,
(void *)vm_sim_get_iccid,
(void *)vm_set_active_sim_card,
(void *)vm_sim_get_active_sim_card,
(void *)vm_get_operator,

// persmsper
(void *)vm_send_sms_person,
(void *)vm_cancel_send_sms,

// persmssp
(void *)vm_send_sms,
(void *)vm_cancel_send_sms,

// pertcp
(void *)vm_wlan_perfer,
(void *)vm_tls_set_verify,
(void *)vm_soc_get_host_by_name,
(void *)vm_tls_soc_connect,
(void *)vm_tls_get_cipher_info,
(void *)vm_tls_set_identity,
(void *)vm_tls_delete_conn,
(void *)vm_tls_new_ctx,
(void *)vm_cbm_release_bearer,
(void *)vm_tls_write,
(void *)vm_dtacct_select,
(void *)vm_srv_nw_info_channel_supports,
(void *)vm_tcp_connect,
(void *)vm_tls_set_ciphers,
(void *)vm_tls_check_peer_name,
(void *)vm_tls_handshake,
(void *)vm_cbm_hold_bearer,
(void *)vm_wifi_is_connected,
(void *)vm_tls_rehandshake,
(void *)vm_wlan_loc_get_connected_info,
(void *)vm_tls_connect,
(void *)vm_tls_check_invalid_cert,
(void *)vm_tls_read,
(void *)vm_get_default_apn_info,
(void *)vm_tls_get_cipher,
(void *)vm_tcp_close,
(void *)vm_wlan_loc_search_abort,
(void *)vm_is_support_wifi,
(void *)vm_dtacct_set,
(void *)vm_tcp_read,
(void *)vm_tcp_write,
(void *)vm_wlan_loc_search,
(void *)vm_tls_shutdown,
(void *)vm_tls_log_plaintext,
(void *)vm_get_apn_info,
(void *)vm_tls_set_null_client_auth,
(void *)vm_tls_new_conn,
(void *)vm_tls_auto_rehandshake,
(void *)vm_tls_set_client_auth,
(void *)vm_tls_get_peer_cert,
(void *)vm_get_encoded_dtacct_id,
(void *)vm_tls_delete_ctx,

// persysstorage
(void *)vm_storage_read,
(void *)vm_storage_close,
(void *)vm_storage_open,
(void *)vm_storage_write,

// persec
(void *)vm_des_decrypt,
(void *)vm_che_key_action,
(void *)vm_che_rsa_private_encrypt,
(void *)vm_des_set_key,
(void *)vm_che_process,
(void *)vm_che_rsa_private_decrypt,
(void *)vm_che_rsa_public_encrypt,
(void *)vm_des_reset_key,
(void *)vm_che_set_iv,
(void *)vm_che_rsa_public_decrypt,
(void *)vm_che_deinit,
(void *)vm_des_encrypt,
(void *)vm_che_init,

// perbitstream
(void *)vm_bitstream_audio_close,
(void *)vm_bitstream_audio_finished,
(void *)vm_bitstream_audio_stop,
(void *)vm_bitstream_audio_put_data,
(void *)vm_bitstream_audio_put_frame,
(void *)vm_bitstream_audio_clear_interrupt_callback,
(void *)vm_bitstream_audio_get_play_time,
(void *)vm_bitstream_audio_register_interrupt_callback,
(void *)vm_bitstream_audio_open,
(void *)vm_bitstream_audio_start,
(void *)vm_bitstream_audio_open_pcm,
(void *)vm_bitstream_audio_get_buffer_status,

// percontact
(void *)vm_phb_search_contact_syn,
(void *)vm_phb_delete_contact,
(void *)vm_phb_get_contact_syn,
(void *)vm_phb_get_group_list_count,
(void *)vm_phb_search_contact,
(void *)vm_phb_get_total_contacts,
(void *)vm_phb_get_contact,
(void *)vm_phb_add_contact,
(void *)vm_phb_get_used_contacts,
(void *)vm_phb_get_used_contacts_count,
(void *)vm_phb_get_group_name_by_id,
(void *)vm_phb_update_contact,
(void *)vm_phb_search_contact_list,
(void *)vm_phb_get_group_list,

// perlbs
(void *)vm_gps_get_vtg_data,
(void *)vm_gps_get_gll_data,
(void *)vm_gps_close,
(void *)vm_cell_get_nbr_cell_info,
(void *)vm_cell_open,
(void *)vm_gps_get_rmc_data,
(void *)vm_gps_get_gsv_data,
(void *)vm_cell_get_nbr_num,
(void *)vm_gps_open,
(void *)vm_cell_close,
(void *)vm_gps_get_gga_data,
(void *)vm_gps_get_gsa_data,
(void *)vm_cell_get_cur_cell_info,

// permms
(void *)vm_mms_cancel_send_mms,
(void *)vm_mms_cancel_download,
(void *)vm_mms_download,
(void *)vm_mms_send_mms,
(void *)vm_mms_set_interrupt_event_handler,
(void *)vm_mms_delete,
(void *)vm_mms_clear_interrupt_event_handler,

// perpro
(void *)vm_appcomm_init,
(void *)vm_pmng_get_current_handle,
(void *)vm_pmng_set_event_filter,
(void *)vm_pmng_set_bg,
(void *)vm_pmng_apply_to_run_in_fg,
(void *)vm_pmng_send_app_sys_event,
(void *)vm_pmng_state,
(void *)vm_pmng_restore_default_event_filter,
(void *)vm_appcomm_dispatch_msg,
(void *)vm_appcomm_reg_msg_proc,
(void *)vm_appcomm_post_msg,
(void *)vm_appcomm_send_msg,
(void *)vm_appcomm_dereg_msg_proc,

// persmsmng
(void *)vm_sms_set_interrupt_event_handler,
(void *)vm_sms_delete_msg_forpay,
(void *)vm_sms_get_sc_address_syn,
(void *)vm_sms_delete_msg,
(void *)vm_sms_get_sc_address,
(void *)vm_sms_delete_msg_list,
(void *)vm_sms_clear_interrupt_event_handler_forpay,
(void *)vm_sms_get_msg_id,
(void *)vm_sms_set_interrupt_event_handler_forpay,
(void *)vm_sms_get_msg_id_list,
(void *)vm_sms_add_msg,
(void *)vm_sms_clear_interrupt_event_handler,
(void *)vm_sms_read_msg,
(void *)vm_sms_get_box_size,

// pervideo
(void *)vm_video_play_by_filepath,
(void *)vm_video_stop,
(void *)vm_video_close_buffer,
(void *)vm_video_seek_and_getframe,
(void *)vm_video_play,
(void *)vm_video_snapshot,
(void *)vm_video_play_stream_from_rtsp_link,
(void *)vm_video_set_contrast,
(void *)vm_video_set_brightness,
(void *)vm_video_open_buffer,
(void *)vm_video_get_cur_play_time,
(void *)vm_video_open_file,
(void *)vm_video_resume,
(void *)vm_video_play_stream_from_sdp_file,
(void *)vm_video_close_file,
(void *)vm_video_pause,

// perxml
(void *)vm_xml_parse,
(void *)vm_xml_get_error,
(void *)vm_xml_set_element_handlers,
(void *)vm_xml_new_parser,
(void *)vm_xml_set_data_handler,
(void *)vm_xml_set_doctype_handlers,

// perpayment
(void *)vm_purchase_item,
(void *)vm_create_buyer,
(void *)vm_release_buyer,

// persysfile
(void *)vm_sys_file_close,
(void *)vm_sys_file_read,
(void *)vm_sys_file_open,
(void *)vm_sys_file_get_space,
(void *)vm_sys_file_seek,
(void *)vm_sys_file_write,
(void *)vm_sys_file_delete,

// perbt
(void *)vm_btcm_set_host_name,
(void *)vm_btcm_search,
(void *)vm_btspp_get_dev_addr,
(void *)vm_btspp_set_security_level,
(void *)vm_btcm_get_dev_info_by_index,
(void *)vm_btcm_exit,
(void *)vm_btcm_srv_set_visibility,
(void *)vm_btcm_srv_get_visibility,
(void *)vm_btspp_close,
(void *)vm_btspp_write,
(void *)vm_btspp_read,
(void *)vm_btspp_reject,
(void *)vm_btspp_disconnect,
(void *)vm_btcm_get_power_status,
(void *)vm_btspp_get_min_buf_size,
(void *)vm_btspp_connect,
(void *)vm_btcm_init,
(void *)vm_btspp_bind,
(void *)vm_btspp_set_service_name,
(void *)vm_btspp_open,
(void *)vm_btcm_switch_off,
(void *)vm_btspp_connect_ex,
(void *)vm_btcm_get_host_dev_info,
(void *)vm_btcm_search_abort,
(void *)vm_btcm_get_dev_num,
(void *)vm_btcm_switch_on,
(void *)vm_btspp_accept,

// perudp
(void *)vm_udp_recvfrom,
(void *)vm_udp_close,
(void *)vm_udp_sendto,
(void *)vm_udp_create,

// perpn
(void *)vm_pn_reg,
(void *)vm_pn_dereg,
(void *)vm_pn_get_global_setting,
(void *)vm_pn_query,
(void *)vm_pn_get_mps_info_ex,
(void *)vm_pn_is_support,
(void *)vm_pn_get_object,
(void *)vm_pn_get_mps_info,
(void *)vm_pn_set_notify_style,
(void *)vm_pn_set_badge,
};


const void *  SysFileFuncList[PERFILE_COUNTER] = {
(void *)vm_find_next,
(void *)vm_find_first_ext,
(void *)vm_find_close,
(void *)vm_selector_run,
(void *)vm_file_delete,
(void *)vm_file_tell,
(void *)vm_file_rename,
(void *)vm_file_rmdir,
(void *)vm_fs_async_abort,
(void *)vm_fs_async_get_working_buf_size,
(void *)vm_fs_async_read,
(void *)vm_file_write,
(void *)vm_find_next_ext,
(void *)vm_fs_async_commit,
(void *)vm_file_copy_abort,
(void *)vm_find_close_ext,
(void *)vm_file_close,
(void *)vm_file_set_attributes,
(void *)vm_get_disk_info,
(void *)vm_fs_async_close,
(void *)vm_fs_async_open,
(void *)vm_file_copy,
(void *)vm_fs_async_delete,
(void *)vm_file_is_eof,
(void *)vm_file_commit,
(void *)vm_file_seek,
(void *)vm_file_getfilesize,
(void *)vm_fs_async_seek,
(void *)vm_file_mkdir,
(void *)vm_file_get_attributes,
(void *)vm_fs_async_write,
(void *)vm_file_read,
(void *)vm_get_disk_free_space,
(void *)vm_file_get_modify_time,
(void *)vm_kbd_is_key_supported,
(void *)vm_find_first,
(void *)vm_file_open
};


const VMINT HashList[TOTAL_COUNTER] = { 
// FuncSrc
-2139985952, -2133449860, -2094625572, -2089671906, -2082999174, -2077204688, -2075048454, 
-2073761308, -2060042108, -2053131938, -2049083076, -2028665410, -2026596322, -2025537690, -2021903076, 
-2018946654, -2017535538, -2006024534, -2004475522, -1989567002, -1986453592, -1970543738, -1961094102, 
-1960679206, -1957456102, -1943230264, -1940341600, -1930295720, -1906312368, -1900257298, -1895061868, 
-1873709934, -1868520998, -1867160362, -1856808188, -1847820792, -1845684348, -1844948842, -1830197712, 
-1826024078, -1812299706, -1807345468, -1799088654, -1797276696, -1795771854, -1786896266, -1780461472, 
-1772885688, -1765284628, -1743677930, -1735822698, -1714251734, -1705762038, -1702625230, -1698099708, 
-1689754830, -1689516232, -1683337178, -1666762536, -1640994334, -1638847910, -1621998696, -1599433244, 
-1598091200, -1585009456, -1584217022, -1576809604, -1571547602, -1570390990, -1543235038, -1541970148, 
-1536717748, -1518437338, -1514730702, -1511178808, -1504772712, -1504756690, -1504637476, -1499331970, 
-1498806410, -1488646468, -1478022060, -1476067558, -1468628020, -1454183152, -1435353266, -1420652984, 
-1410222786, -1404765866, -1404078024, -1386246318, -1377840896, -1365786434, -1352630298, -1351404626, 
-1351263742, -1350289626, -1349658976, -1340657824, -1334985536, -1307747648, -1295211244, -1294647018, 
-1280934172, -1270424444, -1248564378, -1239828468, -1217717402, -1208229698, -1202290140, -1199810314, 
-1199135650, -1188369542, -1188218132, -1182856882, -1181167370, -1180102452, -1168859826, -1154253574, 
-1144884444, -1142591970, -1138960166, -1135058928, -1123666318, -1123132496, -1122711914, -1119532468, 
-1118707160, -1111655700, -1109164898, -1096953288, -1091452960, -1086163258, -1079389646, -1074460012, 
-1072989168, -1066236890, -1064637022, -1057076918, -1024358182, -1023387588, -1022867532, -1004811560, 
-974323870, -956135586, -948157596, -946956076, -917565370, -907735558, -896246078, -888466600, 
-881265226, -871685530, -868176918, -855518826, -820102414, -820070360, -819906844, -790782856, 
-789303652, -781805056, -767252656, -765046686, -761358226, -749432342, -747390214, -744902324, 
-733374340, -713773158, -676181256, -663415696, -658669730, -649291106, -620754524, -616620926, 
-608684772, -606538630, -602220926, -598983068, -581241830, -579390964, -575586058, -571137142, 
-532230174, -521377658, -521358976, -518293822, -514488704, -481145294, -476763052, -471089070, 
-458072312, -456438440, -455783712, -448294952, -426057564, -419753018, -412520670, -405071040, 
-403173230, -400457642, -370985668, -370147248, -367553574, -366914390, -360667258, -355022846, 
-352655436, -340541034, -338768650, -330088838, -318212432, -309930480, -308987640, -305808424, 
-302508320, -293245432, -280891488, -255932338, -248452126, -226389482, -225270266, -222317458, 
-214137152, -210527326, -205962096, -202225582, -178001118, -165413150, -146028000, -142254904, 
-136292516, -135343010, -133254118, -129216470, -124940550, -116174434, -108853160, -92284198, 
-89372394, -65548648, -54028264, -38779052, -36268212, -25507776, 7845096, 17235444, 
39028500, 41390328, 46985424, 49496474, 58994888, 67075250, 73561178, 94262038, 
95131310, 102164374, 114829900, 126577792, 131790768, 142218308, 160754880, 161791022, 
175173316, 175609902, 187188348, 187839076, 222712654, 227861898, 230644638, 235051658, 
249967066, 258593670, 261669724, 264840798, 264929640, 276927968, 309892326, 314633808, 
332511678, 342768256, 349165034, 355870562, 382982994, 386610540, 388059594, 390387472, 
391527100, 399213134, 400568278, 403580332, 405856298, 411322406, 412438816, 412950702, 
418442730, 418542928, 420243866, 438903014, 445791222, 456367702, 471091526, 479551760, 
487139514, 502164830, 502644236, 502852138, 504291556, 518214290, 524002674, 531736782, 
543344484, 543468914, 557228752, 559601768, 563678278, 568412034, 582440940, 594488760, 
594841526, 596359550, 599090714, 601119556, 604300888, 633466900, 634316628, 637859420, 
638120898, 639119520, 641457180, 643822838, 675037540, 676587646, 678146640, 679449930, 
688918496, 699808426, 704405824, 709534930, 711515486, 712654290, 723230204, 727293734, 
727893006, 751752912, 753124572, 755441832, 782946602, 795021642, 813773842, 832503548, 
842414028, 850399838, 859613052, 869095926, 875172746, 891064552, 895495436, 905182568, 
913957412, 924764512, 933293740, 940514946, 957607832, 961733732, 969512050, 970297824, 
977292090, 987023176, 994707334, 998524912, 1007239302, 1014728892, 1015226716, 1017695544, 
1024860678, 1036842770, 1038482082, 1041225172, 1052130058, 1052197934, 1060409778, 1070199460, 
1072344670, 1074013078, 1082951436, 1092580238, 1093199734, 1095631132, 1115769268, 1130621286, 
1130819854, 1132096846, 1134289686, 1142312546, 1146232872, 1156351252, 1160525662, 1171922718, 
1175014814, 1191822448, 1192703844, 1198093600, 1206307156, 1208910840, 1209974106, 1215662900, 
1225158842, 1240247378, 1240633598, 1253217038, 1255131998, 1256829738, 1263312996, 1274046212, 
1286642154, 1302496670, 1302984640, 1305902706, 1305968086, 1311534016, 1312294062, 1312975610, 
1320247762, 1326667872, 1335211652, 1336504070, 1350418532, 1351054694, 1351964408, 1352657270, 
1358675996, 1358891212, 1369970452, 1370245308, 1394496062, 1413039752, 1425860090, 1426068920, 
1428376494, 1434058678, 1440280084, 1447597144, 1450289144, 1463292594, 1466676554, 1469191202, 
1486708712, 1493923622, 1502617044, 1508165274, 1510465036, 1511700148, 1516078640, 1517007980, 
1521755652, 1526365344, 1526743712, 1537184910, 1550427978, 1556604518, 1563295434, 1569228970, 
1570067650, 1583396328, 1584143092, 1585419518, 1599748994, 1603100914, 1605342882, 1616308888, 
1617006536, 1624564234, 1641430912, 1644269130, 1646478718, 1649180136, 1649214852, 1653917750, 
1655321590, 1667766222, 1673668120, 1696487550, 1702773360, 1703553874, 1708537680, 1718184024, 
1736255300, 1736474196, 1759746074, 1761871358, 1763941046, 1777642732, 1780157166, 1787305638, 
1810305070, 1818698232, 1823096670, 1831021724, 1843833490, 1848585480, 1857056128, 1857793606, 
1863617466, 1873548138, 1880533608, 1888672096, 1897150514, 1903245580, 1916965660, 1921849350, 
1934235504, 1939386120, 1941770122, 1951187454, 1965236360, 1968096918, 1984183988, 1990457924, 
1991348130, 2012987526, 2024942774, 2026298666, 2059715358, 2061438378, 2062632466, 2065354226, 
2074716604, 2078899204, 2079891732, 2092339420, 2094017454, 2100168492, 2136730296, 2139702586, 
2139967020, 

// peraudio
-1901640864, -1890974006, -1883092624, -1771510658, -1577144398, -1523950664, -1265387364, 
-1204892488, -1094263058, -1053394310, -947963458, -786166422, -524229132, -483722748, -291368920, 
-234631148, -100105152, -64380580, 21056614, 44401016, 153456206, 183438098, 383473008, 
475822988, 592290284, 625951980, 701199930, 762881936, 855330146, 915599044, 934226352, 
978041812, 1207945728, 1262291470, 1444818566, 1467222796, 1495025778, 1610975952, 1730352498, 
1788904390, 2036169026, 2038699834, 2132481544, 2139701436, 

// percallout
-1891608898, -1473954896, -1292658266, -532919782, 161243828, 

// percam
-2055954872, -2017936740, -1896314728, -1585421264, -1309589404, -1293865996, -1257512760, 
-1188748176, -1174529952, -799137486, -738031986, -661229402, -601179306, -395842642, -322246010, 
-60129632, 98829346, 165785232, 180311854, 199621094, 410111404, 456588998, 483532634, 
772020228, 774083904, 873451450, 1077510192, 1189383420, 1192873788, 1457992194, 1582967516, 
1721174892, 1771173800, 1856930582, 1976624874, 2042104516, 2136432026, 2140786062, 

// perfile
-1961546186, -1654189642, -1560275080, -1495649412, -1428797080, -1262299424, -1208083674, 
-1187201214, -1066493830, -792254732, -764844250, -724874700, -696128164, -532456798, -515133038, 
-488056106, -448419764, -258821624, -240166694, 56089738, 104157068, 174517260, 221781418, 
418192528, 436027584, 515834790, 561360428, 655745028, 1135900612, 1136402900, 1144337694, 
1242544384, 1255564252, 1398153482, 1583090486, 1740217816, 2014698598, 

// perhttp
-2134499316, -2052205722, -2015992468, -1690929000, -1642908914, -1638111606, -1636719458, 
-1593735922, -1484172440, -1292059502, -1216445006, -1190014786, -1142559758, -984645938, -933661442, 
-913948622, -836750600, -727734154, -705799018, -588062716, -483370876, -427676348, -425133482, 
-148803142, 103440154, 106134798, 187892170, 242580736, 333668718, 491616798, 610395714, 
665435264, 750775522, 813972138, 1314688132, 1439060772, 1444477510, 1578267158, 1652536476, 
1952994328, 1996198772, 2079845190, 

// perrecord
-57515188, 729969762, 1643919894, 1745925284, 

// persensor
-750526272, 773786244, 1105448390, 1412599936, 1908880034, 

// persim
-1705142012, -904797914, -500281938, -443702956, -228993066, -117907196, 792386496, 
824788802, 834570318, 909520010, 1810952778, 

// persmsper
-1730625384, 857589992, 

// persmssp
-1532598934, 857589992, 

// pertcp
-2082431002, -1896881790, -1842126238, -1731307946, -1672061826, -1310492260, -1276083390, 
-1255906932, -1254577222, -1222812558, -1044235494, -1001783552, -891310902, -483512160, -395639380, 
-302208368, -277670636, -115516976, -23039752, 20528444, 69218030, 152362500, 198142162, 
204709424, 234242032, 366864330, 668225648, 672217852, 705890468, 1106741222, 1171545694, 
1230493110, 1283047468, 1331246876, 1521629632, 1535499188, 1662306212, 1676949152, 1818271784, 
1914401592, 1966968480, 2058552894, 

// persysstorage
-1325985480, 380903172, 916596686, 1162575452, 

// persec
-1762315932, -1153771336, -981107256, -663868616, -244741162, -2461338, 490322348, 
532836588, 852891948, 1400992498, 1555163494, 1748376254, 1775978676, 

// perbitstream
-2145476500, -1690683368, -84850650, 109377824, 425376862, 441528058, 539850306, 
733681510, 1038457094, 1583115946, 1759970480, 2026687280, 

// percontact
-1998421644, -1890143108, -1487473864, -845498542, -784216692, -540011386, -469829704, 
-355669316, -239897120, -172186704, 4512474, 147801180, 1250753250, 1500355026, 

// perlbs
-1871126164, -1640252222, -1318541394, -1313425970, -1237095490, -1082786190, -999119604, 
-110691576, 925389848, 993118036, 1126180668, 1135242032, 2135135220, 

// permms
-1865560558, -1557082370, -1286164296, -1125414812, -349930338, 379903030, 807937098, 

// perpro
-1756987016, -1543235038, -1366891546, -1266634780, -1218594616, -1065238048, -744902324, 
-264163052, 388623548, 649339838, 774951056, 1611883464, 2120449116, 

// persmsmng
-1387794500, -1341125230, -900210230, -731432026, -706487050, -270743712, -117023912, 
268324284, 418089008, 768383602, 860542798, 1449022468, 1725332158, 1743990912, 

// pervideo
-2134417058, -1856326270, -830624992, -706187270, -232385786, -142326866, -97466286, 
31394982, 292500414, 333973646, 503011678, 794838820, 830665708, 832655962, 899094382, 
1803346564, 

// perxml
-697653352, -558174176, 1298636922, 1666290034, 1857876864, 2065476132, 

// perpayment
-1483233494, -1387850874, 127533304, 

// persysfile
-1840173274, -569091718, 432601040, 875641482, 1314027992, 1997717754, 2010303966, 

// perbt
-2067146402, -2059519958, -2004574536, -1994450688, -1745793510, -1685342104, -1608290404, 
-1318233104, -1102699308, -938083156, -827874712, -510128550, -276770018, -30621734, 232155474, 
339584932, 605904070, 732001368, 773316038, 821892926, 1277601514, 1349547382, 1481971488, 
1583904852, 1655551636, 1674659188, 1927562686, 

// perudp
-399354126, 669079284, 833556774, 2129153370, 

// perpn
-2042887786, -1594472160, -1414954742, -941776884, -188205414, 621499500, 742864454, 
1311800296, 1545613280, 2048338418, 

};

const VMINT	SecList[PER_TOTAL-PER_BASE+1] = {
				AUDIO_START_COUNTER,
				CALLOUT_START_COUNTER,
				CAM_START_COUNTER,
				FILE_START_COUNTER,
				HTTP_START_COUNTER,
				RECORD_START_COUNTER,
				SENSOR_START_COUNTER,
				SIM_SATRT_COUNTER,
				SMSPER_START_COUNTER,
				SMSSP_START_COUNTER,
				TCP_START_COUNTER,
				SYSSTORAGE_START_COUNTER,
				SEC_START_COUNTER,
				BITSTREAM_START_COUNTER,
				CONTACT_START_COUNTER,
				LBS_START_COUNTER,
				MMS_START_COUNTER,
				PRO_START_COUNTER,
				SMSMNG_START_COUNTER,
				VIDEO_START_COUNTER,
				XML_START_COUNTER,
				PAYMENT_START_COUNTER,
				SYSFILE_START_COUNTER,
				BT_START_COUNTER,
  			UDP_START_COUNTER,
  			PN_START_COUNTER,
				TOTAL_COUNTER
};


//the flags for remap sections
VMINT	cur_file_sys_per;

#endif

