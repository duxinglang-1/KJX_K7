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


#ifndef __JAM_MVM_MANAGER_H__
#define __JAM_MVM_MANAGER_H__
#include "jvm_def.h"
#include "jam_msg_handler.h"
#include "jam_interface.h"
#include "Profile_struct.h"
#include "Dtcntsrvgprot.h"

#define INVALIDE_VM_ID    -1
typedef enum{
    MVM_SHUTDOWN_STATE   = 0,
    MVM_SHUTDOWNING_STATE = 1,
    MVM_ACTIVATED_STATE  = 2    
}jam_mvm_ctxt_state;


typedef struct
{
    kal_int32 (*res_initializer) (kal_int32 vm_id);
} jam_mvm_instance_initializer;
typedef struct
{
    kal_int32 (*res_deinitializer) (kal_int32 vm_id);
} jam_mvm_instance_deinitializer;

typedef struct _jam_mvm_instance_struct{
    kal_char*                           storage_name;
    kal_int32                           mid_id;
    kal_wchar*                          mid_name;
    kal_uint32                          launch_time;
    kal_wchar*                          jad_file_path;
    kal_wchar*                          jar_file_path;
    kal_int32                           drm_consume_id;
    kal_char*                           running_dir_path;
    kal_uint32                          vm_status_ind_flag; /* keep status indication from vm or set by jal, Max 32 event.  */
    jvm_state_enum                      state;  
}jam_mvm_instance_struct;

typedef struct 
{
    kal_int32 (*res_initializer) (void);
} jam_mvm_context_initializer;
typedef struct
{
    kal_int32 (*res_deinitializer) (void);
} jam_mvm_context_deinitializer;

typedef struct _jam_mvm_context_struct{
    java_mode_enum          java_mode;
    jam_mvm_ctxt_state      state;
    kal_int32               vm_count;
    kal_uint32              javaheap_size;
    long*                   javaheap_space;
    kal_uint32              javaruntime_size;
    long*                   javaruntime_space;
    kal_int32               current_vm_id;
    kal_int32               launching_vm_id;
    kal_bool                has_launching_midlet;
    jam_mvm_instance_struct*     vm_list[MAX_VM_INSTANCE_NUM];
}jam_mvm_context_struct;
extern void jam_mvm_set_current_vm_id(kal_int32 vm_id);
extern kal_int32 jam_mvm_get_current_vm_id(void);
extern kal_wchar* jam_mvm_get_current_vm_mid_name(void);
extern kal_int32 jam_mvm_get_vm_instance(kal_char* storage_name, kal_int32 mid_id, java_mode_enum java_mode,kal_int32* error_code);
extern kal_int32 jam_mvm_get_vm_state(kal_int32 vm_id);
extern void jam_mvm_set_vm_state(kal_int32 vm_id,kal_int32 state);
extern void jam_mvm_set_vm_mid_name(kal_int32 vm_id, kal_wchar* mid_name);
extern kal_wchar* jam_mvm_get_vm_mid_name(kal_int32 vm_id);

extern void jam_mvm_set_vm_is_auto_terminated(kal_int32 vm_id,kal_bool auto_terminated);
extern kal_bool jam_mvm_get_vm_is_auto_terminated(kal_int32 vm_id);

extern void jam_mvm_set_vm_jar_path(kal_int32 vm_id, kal_wchar* jar_path);
extern kal_wchar* jam_mvm_get_vm_jar_path(kal_int32 vm_id);
extern void jam_mvm_set_running_dir_path(kal_int32 vm_id, kal_char* running_dir_path); // 20100920: Added
extern kal_char* jam_mvm_get_running_dir_path(kal_int32 vm_id); // 20100920: Added
extern void jam_mvm_set_vm_consume_id(kal_int32 vm_id,kal_int32 consume_id);
extern kal_int32 jam_mvm_get_vm_consume_id(kal_int32 vm_id);
extern kal_int32 jam_mvm_get_vm_id_by_drm_consume_id(kal_int32 consume_id);
extern long* jam_mvm_get_javaheap_space(void);
extern kal_int32 jam_mvm_get_javaheap_size(void);
extern kal_char* jam_mvm_get_storage_name_by_vm_id(kal_int32 vm_id);
extern void jam_mvm_terminate_vm(kal_int32 vm_id);
extern void jam_mvm_shutdown_all_req(void);
extern void jam_mvm_shutdown_all(void);
/*force to set ctxt state shutdowning to block midlet launching,
 *this happened for some exception, this function only can be call in before 
 * jam_jvm_send_shutdown_all_notify()
 */
extern void jam_mvm_set_ctxt_shutdowning(void);

extern kal_char* jam_mvm_get_vm_storage_name(kal_int32 vm_id);
extern kal_int32 jam_mvm_get_vm_id(kal_char* storage_name, kal_int32 mid_id);
extern kal_char* jam_mvm_get_running_dir_path_by_storage_name(kal_char* storage_name); // 20100920: Added
extern kal_bool jam_mvm_midlet_is_running(kal_char* storage_name, kal_int32 mid_id);
extern kal_bool jam_mvm_midlet_is_running_by_vm_id(kal_int32 vm_id);
extern kal_bool jam_mvm_midlet_is_bg_running_by_vm_id(kal_int32 vm_id);
extern kal_bool jam_mvm_is_vm_notifyed_stopped(kal_int32 vm_id);
extern void    jam_mvm_set_vm_notifyed_stopped(kal_int32 vm_id);
extern kal_bool jam_mvm_is_vm_pause_ind(kal_int32 vm_id);
extern void    jam_mvm_set_vm_pause_ind(kal_int32 vm_id, kal_bool state);
extern kal_bool jam_mvm_is_vm_resume_ind(kal_int32 vm_id);
extern void    jam_mvm_set_vm_resume_ind(kal_int32 vm_id, kal_bool state);
extern kal_bool jam_mvm_is_vm_terminate_ind(kal_int32 vm_id);
extern void    jam_mvm_set_vm_terminate_ind(kal_int32 vm_id, kal_bool state);
extern kal_bool jam_mvm_is_vm_need_call_pauseapp(kal_int32 vm_id);
extern void    jam_mvm_set_vm_need_call_pauseapp(kal_int32 vm_id, kal_bool state);
extern kal_bool jam_mvm_is_vm_vk_on(kal_int32 vm_id);
extern void jam_mvm_set_vm_vk_on(kal_int32 vm_id,kal_bool is_on);
extern kal_bool jam_mvm_is_vm_support_bg(kal_int32 vm_id);
extern kal_bool jam_mvm_disable_vm_support_bg(kal_int32 vm_id);
extern kal_bool jam_mvm_is_vm_support_disable_bg(kal_int32 vm_id);

extern java_mode_enum jam_mvm_get_java_mode(void);
extern kal_int32 jam_mvm_get_running_count(void);
extern kal_int32 jam_mvm_get_bg_running_count(void);
extern jam_mvm_instance_struct* jam_mvm_find_vm_instance(kal_int32 vm_id);

// 20100403: Added
extern kal_bool jam_mvm_has_work_instance(void);
extern kal_bool jam_mvm_has_running_vm(void);
extern kal_bool jam_mvm_has_running_vm_on_driver(kal_int8 driver);
extern kal_bool jam_mvm_has_running_midlet_in_mids(kal_char* storage_name);
extern kal_bool jam_mvm_has_terminating_midlet_in_mids(kal_char* storage_name);
extern mmi_running_mid* jam_mvm_get_running_mids_list(kal_int32* err_code, kal_int32 * count);\
extern kal_uint32 jam_mvm_get_account_id(kal_int32 vm_id);
extern srv_dtcnt_prof_proxy_info_cnf_struct* jam_mvm_get_network_profile_by_vm_id(kal_int32 vm_id);
extern kal_bool jam_mvm_is_shutdowning(void);
extern kal_bool jam_mvm_is_shutdown(void);
extern kal_bool jam_mvm_has_fg_running_vm(void);
extern kal_int32 jam_mvm_get_max_vm_num(void);

extern kal_bool jam_mvm_get_bg_running_vm(kal_bool * vm_id);
extern void jam_mvm_retrieve_asm_eg_event(void);

extern kal_bool jam_mvm_has_launching_midlet(void);

#endif /*__JAM_MVM_MANAGER_H__*/

