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
 *  
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#ifndef __VAPP_JAVA_SRV_H__
#define __VAPP_JAVA_SRV_H__
#ifdef __J2ME__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_java_def.h"
#endif
#ifdef __cplusplus
extern "C"
{
#endif /*__cplusplus*/
    #include "JavaAgencyUIOptionMenu.h"
    #include "JavaAgencyUITextField.h"
    #include "JavaAgencyUIDateField.h"
    #include "j2me_trace.h"
#ifdef __cplusplus
}
#endif /*__cplusplus*/
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MTK_TARGET__) 
#define JAVA_TRACE(msg) MMI_PRINT(MOD_JAM, TRACE_GROUP_5,msg)
#define JAVA_TRACE_PARA(msg,para) MMI_PRINT(MOD_JAM, TRACE_GROUP_5,msg,para)
#else
#define JAVA_TRACE(msg) VFX_TRACE((msg))
#define JAVA_TRACE_PARA(msg,para) VFX_TRACE((msg,para));
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void(*java_get_file_info_callback)(java_filengr_info_struct* info, kal_bool result);

/***************************************************************************** 
 * Class 
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
  typedef enum
{
    VJAVA_POPUP_NULL = 100,
    VJAVA_POPUP_INDICATOR_ACTIVITY,
    VJAVA_POPUP_CONFIRM_TYPE_INFO,
    VJAVA_POPUP_WARNING,
    VJAVA_POPUP_STOP,
    VJAVA_POPUP_FAILURE,
    VJAVA_POPUP_INFO,
    VJAVA_POPUP_SUCCESS,
    VJAVA_POPUP_PROGRESS,
    VJAVA_POPUP_QUESTION,
    VJAVA_POPUP_MAX
}vapp_java_popup_type_enum;

typedef enum 
{
    VAPP_JAVA_ENTRY_NONE,
    VAPP_JAVA_ENTRY_LAUNCH_AFTER_INSTALL,
    VAPP_JAVA_ENTRY_RIGHT_MANAGER,
    VAPP_JAVA_ENTRY_REINSTALL,
    VAPP_JAVA_ENTRY_CLOSE_JAVA_APP,
    VAPP_JAVA_ENTRY_CLOSE_MIDLET_SCREEN,
    VAPP_JAVA_ENTRY_SKIP,
    VAPP_JAVA_ENTRY_END
} vapp_java_entry_after_popup_enum;
extern S32 g_vjava_force_resume_global_popup;
extern S32 g_vjava_terminate_confirm_global_popup;
extern S32 g_vjava_global_popup;
extern mmi_id g_vjava_screen_switch;
extern kal_bool g_vjava_is_select_screen_active;
 extern void vapp_java_send_get_setting_req(void);
extern U16* vapp_jave_get_permission(kal_uint8 idx);
extern S32 vapp_java_get_permission_item_count(kal_int32 index);
extern S8 vapp_jave_get_permission_level_by_index(kal_uint8 idx);
extern void vapp_java_update_mids_setting(void);
extern void vapp_java_entry_reset_rms_res(void);
extern void vapp_java_entry_auth(void);
extern void vapp_java_local_install_content_routing(void* file_path);
extern void vapp_java_get_mids_info_by_app_name(CHAR * app_name);

extern void vapp_java_event_init(void);
extern void vapp_java_set_install_event_handler(void);
extern kal_bool  vapp_java_check_and_display_is_busy(void);
extern void vapp_java_mid_select_entry(void);
extern void vapp_java_close_venus_screen(void);
extern void vapp_java_get_permission_entry(void);
extern void vapp_java_task_manager_entry(kal_bool is_push);
extern void vapp_java_indicating_entry(void);

extern void vapp_java_display_popup(S32 str_id, S32 popup_tpye, vapp_java_entry_after_popup_enum entry);
extern void vapp_java_display_popup_str(WCHAR* str,S32 type,vapp_java_entry_after_popup_enum entry);
extern void vapp_java_close_MIDelt_screen(void);
extern kal_bool vapp_java_display_is_busy(void);
extern void vapp_java_refreash_setting_page(void);
extern MMI_BOOL vapp_java_entry_force_resume_dialog_nmgr(mmi_scenario_id scen_id, void *arg);
extern  void vapp_java_request_ncenter_leave(kal_int32 cell_id);
extern kal_bool vapp_java_is_in_task_manager(void);
extern kal_bool vapp_java_is_in_per_dialog(void);
extern void vapp_java_entry_terminate_dialog(void);
extern kal_bool vapp_java_is_permission_force_fgmmi(void);


/* Java UI */
extern void vapp_java_ui_option_menu_launch(mmi_java_ui_option_menu_data_struct* option_menu);
extern void vapp_java_ui_option_menu_exit(void);
extern void vapp_java_ui_option_menu_hide(kal_bool is_permission);
extern kal_bool vapp_java_ui_is_option_menu_existed(void);
extern void vapp_java_ui_textfield_launch(mmi_java_ui_textfield_data_struct* textfield);
extern void vapp_java_ui_textfield_hide(void);
extern void vapp_java_ui_datefield_date_launch(mmi_java_ui_clndr_context_struct* datefield);
extern void vapp_java_ui_datefield_time_launch(mmi_java_ui_time_context_struct* datefield);
extern void vapp_java_ui_datefield_hide(void);
extern void vapp_java_entry_mids_install_start(void);
extern void vapp_java_update_install_progress_bar(S32 value);  
extern void vapp_java_entry_mids_install_confirm(U16* str);
extern void vapp_java_entry_terminate_vm_confirm(void);
extern void vapp_java_entry_push_install_confirm(void);
extern void vapp_java_entry_dm_install_confirm(void);
extern void vapp_java_entry_select_install_drv(void);
extern void vapp_java_entry_delete_mids_menu_confirm(void);
extern mmi_ret vapp_java_gpio_event_hdlr(mmi_event_struct *evt);
extern  void vapp_java_mids_del_notify(kal_int32 error_code);
extern void vapp_java_disable_lock_screen(void);
extern void vapp_java_enable_lock_screen(void);

extern kal_bool vapp_java_is_in_low_battery(void);

#define vapp_java_display_push_popup(str_id) vapp_java_display_popup(str_id,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_SKIP)

#ifdef __cplusplus
}
#endif

#endif /*__J2ME__*/

#endif /*__VAPP_JAVA_SRV_H__*/
