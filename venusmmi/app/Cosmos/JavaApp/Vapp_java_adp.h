/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_helloworld.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Common interface between different package
 *
 * Author:
 * -------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_JAVA_ADP_H__
#define __VAPP_JAVA_ADP_H__

#ifdef __J2ME__
/***************************************************************************** 
 * Include
 *****************************************************************************/
 extern "C"
{
#include "jam_msg_handler.h"
#include "JavaAgencyProt.h"
#include "JavaAgencyGprot.h"
#include "USBSrvGprot.h"
#include "Jpush_interface.h"
#include "jam_internal.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

extern "C" mmi_java_mids_getinfo_cnf_struct* mids_getinfo_cnf_msg;
extern "C" kal_char* gJavaPrintableStr;
extern "C" mmi_java_cmd_enum g_mmi_java_current_running_cmd;
extern "C" MMI_BOOL g_mmi_java_is_background_display;
extern "C" MMI_BOOL get_setting_only;
extern "C" MMI_BOOL get_domain_setting;
extern "C" kal_char g_mmi_java_current_selected_mids_root[128];
extern "C" S32 mmi_java_get_perm_menu_item_count(S8 max_level);
extern "C" void mmi_java_send_mids_set_setting_req(void);

extern "C" void mmi_java_set_install_info(U16 *jad_file_name, U16 *jar_file_name, U16 *download_url, MMI_BOOL  del);
extern "C" MMI_BOOL g_mmi_java_is_in_package;
extern "C" U16 *mmi_jad_file_name;            
extern "C"U16 *mmi_jar_file_name;            
extern "C"U16 *mmi_download_url;  
extern "C" U8 g_mmi_java_reinstall_state;
extern "C" U8* g_mmi_java_current_installing_mids_name;
extern "C" U8 g_mmi_java_install_progress;
extern "C" mmi_java_install_confirm_ind_struct mmi_java_mids_install_confirm_ind_msg;
extern "C" void mmi_java_send_mids_install_req(U16 *jad_file_path,U16 *jar_file_path, U16 *download_url);
extern "C" MMI_BOOL  mmi_delete_after_install_fail;
extern "C" void mmi_java_unhide_install_file(void);
extern "C" void mmi_java_backup_install_information(void);
extern "C" void mmi_java_register_push_install(U16* drm_file_path, S32 drm_serial);
extern "C" U16* g_mmi_java_install_drm_path_aquire_right;
extern "C" void mmi_java_clear_install_info(void);
extern "C" S32 g_mmi_java_install_mids_id;
extern "C" MMI_BOOL mmi_java_is_allow_to_popup_screen(void);
extern "C"  void mmi_java_recv_reset_rms_ind(void *MsgStruct);
extern "C"  void mmi_java_set_allow_push_install(MMI_BOOL set);
extern "C" void mmi_java_send_reset_rms_res(S8 confirm);
extern "C" BOOL mmi_java_fmgr_check_drm_rights(U16* filepath, U8 drm_permission, U16 icon_id);
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
extern U8 g_mmi_java_vk_permission;    /* J2ME_Choice in JavaAgencyDef.h */
extern U8 g_mmi_java_aud_volume_level ;  /* 0~6 */
extern U8 g_mmi_java_is_vib_on = MMI_FALSE;        /* on-off */
#endif
extern "C" void mmi_java_nw_get_local_setting(void);
extern "C" mmi_java_nw_cntx g_mmi_java_nw_cntx;
extern "C" void mmi_java_nw_set_local_setting(void);
extern "C" void mmi_java_nw_entry_dtcnt_cui(void);
extern "C" mmi_java_push_cntx_struct g_mmi_java_push_cntx;
extern "C" void mmi_java_push_confirm_hdlr(void);
extern "C" void mmi_java_push_enter_option_screen(void);

extern "C" void jvm_end_key_handler(void);
extern "C" void jvm_home_key_handler(void);
extern "C" void mmi_java_send_get_install_drv_res(S8 drv);
extern "C" U8 mmi_java_mids_install_delete_callback(void *in_param);
extern "C" kal_bool jam_vm_is_busy(void);
extern "C" void mmi_java_get_permission_res(MMI_BOOL result);
extern "C" mmi_running_mid * g_mmi_java_running_mid_list;
extern "C" kal_wchar * g_mmi_java_running_mid_name[MAX_VM_INSTANCE_NUM];
extern "C" kal_int32 running_count;
extern "C" kal_int32 running_index;
extern "C" mmi_java_abort_error_code_enum g_mmi_java_abort_error_code;
extern "C" void mmi_java_entry_drm_acquire_right_confirm(void);
extern "C" void mmi_java_push_vm_terminate_hdlr(void);
extern "C" void mmi_java_local_install_content_routing(U16*);
extern "C" void mmi_java_mids_install_ask_terminate_cb(MMI_BOOL);
extern "C" void mmi_java_set_push_install_info(void);
extern "C" void mmi_java_discard_current_push_install_req(void);
extern "C" void mmi_java_recv_mids_install_cnf(void*);
extern "C" void mmi_java_local_install_content_routing(U16* filepath);
extern "C" void mmi_java_mids_install_abort(void);
extern "C" void mmi_java_close_MIDlet_screen(void);
extern "C" U16* mmi_java_get_push_install_confirm_string(void);
extern "C" S32* mmi_java_get_permission_index;
extern "C" kal_bool g_jam_user_update_setting_exclusive;
extern "C" long* g_jam_mvm_little_mem_space_oom;
extern "C" long* g_jam_mvm_whole_heap_space;
extern "C" kal_int32 g_mmi_java_select_permission_vm_id;
extern "C" CHAR g_java_current_install_app_name[MMI_APP_NAME_MAX_LEN];
#endif
#endif 

