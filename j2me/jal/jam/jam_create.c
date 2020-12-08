/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   jam_create.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JAM (Java Application Manager) task create function
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "jal.h"
#include "jvm_adaptor.h"
#include "j2me_custom.h"
#include "gpt_sw.h"
#include "intrCtrl.h"
#include "mmiapi_struct.h"
#include "mmiapi.h"
#include "med_struct.h"
#include "jam_internal.h"
#include "jvm_interface.h"
#include "jma_interface.h"
#include "jma_internal.h"
#include "javaAgencyDef.h"
#include "fmt_struct.h"
#include "jwa_internal.h"
#include "jpush_interface.h"
#include "jpim_internal.h"
#include "j2me_custom_option.h"
#include "JavaAgencyDef.h"
#include "App_mem.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "drm_gprot.h"
#ifdef WAP_SEC_SUPPORT
#include "wap_ps_struct.h"
#endif 
#ifdef __SUPPORT_JBT__
#include "jbt_interface.h"
#include "jbt_internal.h"
#endif /* __SUPPORT_JBT__ */ 
#ifdef SUPPORT_JSR_179
#include "jlbs_internal.h"
#endif
#include "jvm_trace_interface.h"
#include "jui_interface.h"
#include "JavaAppFactorySrvGprot.h"

#ifdef SUPPORT_JSR_257
#include "jcc_internal.h"
#endif
#ifdef SUPPORT_JSR_177
#include "jsatsa_internal.h"
#endif
#include "cbm_api.h"                    /* cbm_register_app_id*/

/*************************************************************************
 * VM Header Files
 *************************************************************************/

/*************************************************************************
 * Global Definition
 *************************************************************************/

/*************************************************************************
 * External API Declaration
 *************************************************************************/
/* Task management */
/* VM main task */
static kal_bool jvm_init(task_indx_type task_indx);
static void jvm_main(task_entry_struct *task_entry_ptr);
/* JAM main task */
static kal_bool jam_init(task_indx_type task_indx);
static void jam_main(task_entry_struct *task_entry_ptr);

/* Java Daemon task */
static void jdaemon_main(task_entry_struct *task_entry_ptr);

/* Storage & File API */
extern void jvm_file_device_ind_handler(ilm_struct *ilm_ptr);

/* LCD UI */
extern void jui_string_init(void);
extern kal_bool jui_util_msg_handler(ilm_struct *ilm_ptr);

/* NetWork */
extern void process_soc_async_ind(ilm_struct *ilm_ptr);

#ifdef SUPPORT_HTTP_OVER_WSP
extern void http_wps_response_handler(ilm_struct *ilm_ptr);
#endif 

#ifdef __J2ME_STREAM_SUPPORT__
extern void j2me_stream_response_handler(ilm_struct *ilm_ptr);
#endif

/*JAM OTA*/
extern void jam_cbm_bearer_info_handler(ilm_struct *ilm_ptr); 

/* Push */

/* MMI API */
extern void mmiapi_register_blocking(module_type mod, kal_char *mutex_name);

/* AMS */
static void jam_jdaemon_timer_expiry_handler(ilm_struct *ilm_ptr);
static void jam_timer_expiry_handler(ilm_struct *ilm_ptr);

extern void jvm_timer_mutex_lock(void);
extern void jvm_timer_mutex_unlock(void);

/* InFusio */
extern void jvm_recv_get_imsi_res(void *msg);
extern void jvm_recv_get_lai_res(void *msg);



#ifdef SUPPORT_JSR_257
extern jcc_nfc_result_enum jcc_nfc_init();
#endif

/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
/*************************************************************************
 * External Variable Declaration
 *************************************************************************/
extern unsigned max_java_use_space;
extern jam_comm_read_ind_handler jam_comm_registered_read_ind_handler;
extern jam_comm_write_ind_handler jam_comm_registered_write_ind_handler;

extern kal_bool g_jam_is_jam_in_busy;

extern kal_char *work_dir_path;
extern kal_char *work_sys_dir_path;

extern kal_char j2me_sys_dir_path[];
#ifdef J2ME_SLIM_MEMORY_SUPPORT
extern kal_char j2me_tck_dir_path[];
#endif
U8 g_mmi_java_app_id = 0;
extern kal_bool g_jam_jpush_support;

/*************************************************************************
 * Global Definition
 *************************************************************************/
/* Task management */
kal_uint32 Java_State = JAVA_ACTIVATED_STATE;
kal_taskid g_jam_task_id;
j2me_custom_resource_info_struct g_jvm_resource_info;

/* JVM Resource Managerment */
kal_mutexid g_jam_resmgr_mutex;

/* Timer */
kal_mutexid g_jam_timer_mutex;
extern event_scheduler *jvm_event_scheduler_ptr;

/*Comm port */
kal_mutexid g_jam_comm_mutex;

/* LCDUI */
kal_mutexid g_jam_lcd_mutex;
kal_mutexid g_jam_ime_mutex;

kal_mutexid g_jam_device_mutex;
kal_mutexid g_jam_drm_mutex;

/* Push and TimeAlarm */
kal_bool pending_pushalarm = KAL_FALSE;
mmi_java_timealarm_push_res_struct pending_pushalarm_action;
stack_timer_struct g_jam_vibrator_timer;
event_scheduler *j2me_alarm_es_ptr;
kal_mutexid g_jpush_record_mutex;

/* revise event group */
kal_eventgrpid g_java_event_group_1;
kal_eventgrpid g_java_event_group_2;
/*---------------*/

/* MMAPI */
kal_mutexid g_jam_param_mutex;
kal_mutexid g_jam_media_mutex;
kal_mutexid g_jam_dynamic_player_mutex;

/* Mutexs */
kal_mutexid g_jam_http_async_mutex;
kal_mutexid g_jam_async_mutex;
kal_mutexid g_jam_resource_mutex;
kal_mutexid g_jam_push_mutex;
kal_mutexid g_jam_vm_event_mutex;
kal_mutexid g_jam_midp_general_mutex;
kal_mutexid g_jam_async_ssl_mutex;
kal_mutexid g_jam_async_sms_mutex;
kal_mutexid g_jam_mvm_mutex;
kal_mutexid g_jam_async_sms_mvm_mutex;
kal_mutexid g_jam_async_mms_mvm_mutex;

/* JSR179 */
#ifdef SUPPORT_JSR_179
kal_mutexid g_jam_gps_mutex;
#endif

/* JSR257 */
#ifdef SUPPORT_JSR_257
kal_mutexid g_jam_nfc_mutex;
kal_semid g_jam_nfc_sem;
#endif

extern kal_semid g_jam_nw_sem; 
#ifndef __MTK_TARGET__
kal_mutexid g_jam_modis_printf_mutex;
#endif 

#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_BASIC_FEATURE)
extern stack_timer_struct java_media_timer;
#if defined (SUPPORT_JSR_135_VIDEO)
extern stack_timer_struct java_stop_time_timer;
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
#endif
#endif /* SUPPORT_MMAPI */ 

/* Misc */
char g_jam_is_op_715;

/* Operator extension */
extern kal_bool jpim_phb_handler(ilm_struct *ilm_ptr);


extern void mmi_java_remove_temp_install_file(void);

#if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern kal_bool g_jma_is_stream_video;
#endif

/*************************************************************************
 * VM Declaration
 *************************************************************************/
#if defined( __NEMO_VM__)  || defined( __IJET_VM__)
/* Alarm Push */
extern int jpush_alarm_del(alarmentry_struct *alarmp);

#endif /*  __NEMO_VM__ or __IJET_VM__ */ 


/*****************************************************************************
 * FUNCTION
 *  jvm_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct jam_handler_info = 
    {
        jam_main,   /* task entry function */
        jam_init,   /* task initialization function */
        NULL,       /* task configuration function */
        NULL,       /* task reset handler */
        NULL,       /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & jam_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jam_init
 * DESCRIPTION
 *  J2ME task - JAM task entry function
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool jam_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_task_state = JAM_TASK_IN_INIT;
    /* added for initialized jvm trace data*/
    jvm_trace_initialize();
    
    /* added for support jvm file full path operation */
    jvm_mvm_file_initialize();

    /* Query customized configuration */
    j2me_custom_resource_info(&g_jvm_resource_info);

    /* Java heap memory which have gc protection */
    javaheap_space = g_jvm_resource_info.javaheap_space;
    javaheap_size = g_jvm_resource_info.javaheap_space_size;
    /* Java runtime memory pool */
    javaruntime_space = g_jvm_resource_info.javaruntimemem_space;
    javaruntime_size = g_jvm_resource_info.javaruntimemem_space_size;

    /* Maximum storage space and default storage drive */
    max_java_use_space = g_jvm_resource_info.max_storage_space;

    /* Update customize drive information */
    #ifdef J2ME_SLIM_MEMORY_SUPPORT
    j2me_tck_dir_path[0] = j2me_sys_dir_path[0] = g_jvm_resource_info.storage_drive;
    #else
    j2me_sys_dir_path[0] = g_jvm_resource_info.storage_drive;
    #endif

    /* Initialize default dir path */
    work_dir_path = work_sys_dir_path = j2me_sys_dir_path;
    g_jam_is_op_715 = g_jvm_resource_info.is_cmcc_715;

/* revise event group */
g_java_event_group_1 = kal_create_event_group("Java event group 1");
g_java_event_group_2 = kal_create_event_group("Java event group 2");
/*----------------*/

    jvm_keypad_init();
    jvm_tp_init();
    g_jam_nw_sem = kal_create_sem("JVM_NW SEM", 1);

    g_jam_resmgr_mutex = kal_create_mutex("J2ME MGR");

    g_jam_comm_mutex = kal_create_mutex("J2ME Comm");
    /* MMI/JVM lcd mutex */
    g_jam_lcd_mutex = kal_create_mutex("J2ME Lcd");
    g_jam_ime_mutex = kal_create_mutex("J2ME IME");
    
    g_jpush_record_mutex = kal_create_mutex("J2ME push");    
    
    /* MMAPI critical section */
    g_jam_task_id = kal_get_task_self_id();
    g_jam_timer_mutex = kal_create_mutex("J2ME timer");
    g_jam_device_mutex = kal_create_mutex("J2ME Dev");
    g_jam_drm_mutex = kal_create_mutex("J2ME drm");
    g_jam_mvm_mutex = kal_create_mutex("JAM MVM mutex");

    g_jam_http_async_mutex = kal_create_mutex("J2ME HTTP");
    g_jam_async_mutex = kal_create_mutex("J2ME Async");
    g_jam_async_ssl_mutex = kal_create_mutex("J2ME SSL Async");
    g_jam_resource_mutex = kal_create_mutex("J2ME Res");
    g_jam_dynamic_player_mutex = kal_create_mutex("J2ME Dyn");
    g_jam_media_mutex = kal_create_mutex("J2ME Audio");
    g_jam_param_mutex = kal_create_mutex("J2ME Flag only For MMAPI");;
    g_jam_push_mutex = kal_create_mutex("JPush");
    g_jam_vm_event_mutex = kal_create_mutex("VM Event");
    g_jam_midp_general_mutex = kal_create_mutex("MIDP mutex");
#ifndef __MTK_TARGET__
    g_jam_modis_printf_mutex = kal_create_mutex("Modis printf mutex");
#endif 
    g_jam_async_sms_mutex = kal_create_mutex("J2ME sms");
    g_jam_async_sms_mvm_mutex = kal_create_mutex("J2ME sms mvm");
    g_jam_async_mms_mvm_mutex = kal_create_mutex("J2ME mms mvm");
#ifdef SUPPORT_JSR_179
    g_jam_gps_mutex = kal_create_mutex("J2ME GPS");
#endif
#ifdef SUPPORT_JSR_257
    g_jam_nfc_mutex = kal_create_mutex("J2ME NFC mutex");
    g_jam_nfc_sem = kal_create_sem("J2ME NFC sem", 1);
#endif
#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_BASIC_FEATURE)
    stack_init_timer(&java_media_timer, "Java Media Timer", MOD_JASYN);
#if defined (SUPPORT_JSR_135_VIDEO)
    stack_init_timer(&java_stop_time_timer, "Java Stop Time Timer", MOD_JASYN);
/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
/* under construction !*/
#endif
#endif
/* MAUI_03121973 wenmin 20120523 end */
#endif
#endif /* SUPPORT_MMAPI */ 

    jvm_init_timer();

    jvm_event_scheduler_ptr = evshed_create("jvm_basic_timer",MOD_JASYN,0,0);
    evshed_set_index(jvm_event_scheduler_ptr,1);

    /* VM vendor initialization */
    jvm_vendor_init();
    /* VM runtime memory initialization*/
    jam_call_back_functions.jam_runtime_memory_initialize(javaruntime_space, javaruntime_size);

    /* For internal midslist memory use */
    jam_listmem_initialize();

    /* Customize LCD module information */
    j2me_custom_lcd_init();

    j2me_custom_file_init();

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jam_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;
    kal_int32 process_res;
    cbm_app_info_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_task_state = JAM_TASK_IN_PRE_MAIN;
    g_jam_is_jam_in_busy = KAL_TRUE;
    stack_int_set_active_module_id(INDX_JAM, MOD_JAM);
    kal_get_my_task_index(&my_index);
    stack_set_active_module_id(my_index, MOD_JAM);

    stack_init_timer(&g_jam_vibrator_timer, "J2ME Vibrator", MOD_JAM);

    /* open pushlist, alarmlist to create push,alarm list */
    /* Remember, the memory should be from system memory pool(control buffer pool) */

    j2me_alarm_es_ptr = evshed_create("J2ME Alarm",MOD_JAM,0,0);
    evshed_set_index(j2me_alarm_es_ptr,1);
    
    info.app_str_id = STR_SCR_JAVA_CAPTION;
    info.app_icon_id = IMG_MENU3108_JAVA;
    info.app_type = DTCNT_APPTYPE_JAVA;
    cbm_register_app_id_with_app_info(&info, &g_mmi_java_app_id);   
    
    
    /* register mmiapi blocking */
    mmiapi_register_blocking(MOD_JAM, "jam");
    mmiapi_register_blocking(MOD_JASYN_D, "jasyn");

	/* Check and generate default files */
    javaFileGenerator(KAL_FALSE);

    jui_string_init();

    jam_call_back_functions.jam_runtime_memory_finalize();
    jam_call_back_functions.jam_runtime_memory_initialize(javaruntime_space, javaruntime_size);

#ifdef __SUPPORT_JBT__
    jbt_init();
#endif 
    /* do the storage recovery only after MMI has entered idle screen */
#ifndef __COSMOS_MMI_PACKAGE__
    while (!jam_has_entered_idle_screen())
    {
        kal_sleep_task(20);
    }
#endif


#ifdef __SUPPORT_JAVA_PUSH__
    g_jam_jpush_support=KAL_TRUE;
    if(jpush_is_vm_redef_jpush_fs)
        jpush_push_open(jpush_general_push_fs_name);        
    else
        jpush_push_open(PUSHPATH_NAME);

    if(jpush_is_vm_redef_jpush_fs)
        jpush_alarm_open(jpush_alarm_push_fs_name);   
    else    
        jpush_alarm_open(ALARMPATH_NAME);
    jpush_init_persistent_push_entries();
#endif
    jam_call_back_functions.jam_init();
    /*applib_mem_ap_register(
        APPLIB_MEM_AP_ID_JAVA,
        STR_SCR_JAVA_CAPTION,
        IMG_MENU3108_JAVA,
        jam_exit_screen_callback_for_asm);*/
    /* help delete temp file last installation of MMI */
    mmi_java_remove_temp_install_file();
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /* delete previous midlet message */
    jvm_util_delete_midlet_msg_temp_file();
#endif
#ifdef __DM_SCOMO_SUPPORT__
        jam_remove_mids_check();
#endif

#ifdef SUPPORT_JSR_257
    jcc_nfc_init();
#endif

    g_jam_is_jvm_in_busy = KAL_FALSE;
    g_jam_is_jam_in_busy = KAL_FALSE;    

    g_jam_task_state = JAM_TASK_IN_MAIN;
    while (1)
    {
        msg_receive_extq_for_stack(&current_ilm);
        switch (current_ilm.msg_id)
        {
#ifdef __DM_SCOMO_SUPPORT__
            case MSG_ID_MMI_JAVA_MIDS_REMOVE_RES:
                jam_preinstall_mids_notify();
                break;
#endif                    
                /* MIDlet Start/Stop */
            case MSG_ID_MMI_JAVA_MID_START_REQ:
                jam_mid_start_req_handler(&current_ilm);
                break;

                /* Remove MIDlet Suite */
            case MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ:
                jam_mids_remove_req_handler(&current_ilm);
                break;
                
                /* Update MIDlet Suite */
            case MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ:
                jam_mids_update_req_handler(&current_ilm);
                break;
                /* Install MIDlet Suite */
            case MSG_ID_MMI_JAVA_INSTALL_MIDS_REQ:
                jam_install_mids_req_handler(&current_ilm);
                break;

            case MSG_ID_MMI_JAVA_MIDS_PACKAGE_REQ:
                jam_mids_package_req_handler(&current_ilm);
                break;

#ifdef __JAVA_MANAGER__
               /* Java autoverification : query mids information from java manager. */
            case MSG_ID_MMI_JAVA_CMD_QUERY_REQ:
                mmi_java_cmd_query_req_handler(&current_ilm);
                break;
#endif /* __JAVA_MANAGER__ */ 

            case MSG_ID_RESEND_TIMEALARM_PUSH_REQ:
                 jam_external_mid_start_req_handler(&current_ilm);
                 break;
			case MSG_ID_MMI_JAVA_PLUG_IN_OUT_TCARD_IND:
                 jam_plug_in_out_tcard_handler(&current_ilm);
                 break;
            default:
                if (!j2me_task_general_msg_handler(&current_ilm))
                {
                    /*Discard no handler message*/
                    kal_trace(JAM_JAVAAGENCY_GROUP,JAM_DISCARD_MSG,current_ilm.msg_id);
                }
                break;
        }
        destroy_ilm(&current_ilm)
    }

}


/*****************************************************************************
 * FUNCTION
 *  jvm_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jvm_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct jvm_handler_info = 
    {
        jvm_main,   /* task entry function */
        NULL,       /* task initialization function */
        NULL,       /* task configuration function */
        NULL,       /* task reset handler */
        NULL,       /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & jvm_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;
    kal_int32 process_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_int_set_active_module_id(INDX_J2ME, MOD_JASYN_D);
    kal_get_my_task_index(&my_index);
    stack_set_active_module_id(my_index, MOD_JASYN_D);

    while (1)
    {
        msg_receive_extq_for_stack(&current_ilm);
        switch (current_ilm.msg_id)
        {

        case MSG_ID_MMI_EM_JAVA_PERFORMANCE_TEST_REQ: 
        {
#if defined (__MMI_EM_MISC_JAVA_PERFORMANCE__)
/* under construction !*/
/* under construction !*/
#endif /* defined (__MMI_EM_MISC_JAVA_PERFORMANCE__) */
        }
        break;

        default:
            jvm_vendor_process_event(&current_ilm);
        break;
        }
        destroy_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jdaemon_create
 * DESCRIPTION
 *  Java asnychronization thread is to receive socket async indication and
 *  to notifiy blocked JAM thread which should process incoming indication.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jdaemon_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct jasyn_handler_info = 
    {
        jdaemon_main,   /* task entry function */
        NULL,           /* task initialization function */
        NULL,           /* task configuration function */
        NULL,           /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & jasyn_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jdaemon_main
 * DESCRIPTION
 *  JASYN thread entry function
 * PARAMETERS
 *  task_entry_ptr      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jdaemon_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_int_set_active_module_id(INDX_JASYN, MOD_JASYN);

    /* Reset disk mout information */
    disk_changed = KAL_FALSE;

    while (1)
    {
        /* Process queued request */
        while (receive_msg_int_q(task_entry_ptr->task_indx, &current_ilm))
        {
            switch (current_ilm.msg_id)
            {
                default:
                    break;
            }
            destroy_ilm(&current_ilm);
        }

        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);

        jui_widget_mvm_fire_event_listener_void_void(0,JUI_EVENT_VM_ACTIVE_NOTIFY); //added to notify vm need to process event
        
        switch (current_ilm.msg_id)
        {
                /* UART */
            case MSG_ID_UART_READY_TO_READ_IND:
                if (jam_comm_registered_read_ind_handler)
                {
                    (*jam_comm_registered_read_ind_handler) (((uart_ready_to_read_ind_struct*) current_ilm.
                                                              local_para_ptr)->port);
                }
                break;

            case MSG_ID_UART_READY_TO_WRITE_IND:
                if (jam_comm_registered_write_ind_handler)
                {
                    (*jam_comm_registered_write_ind_handler) (((uart_ready_to_write_ind_struct*) current_ilm.
                                                               local_para_ptr)->port);
                }
                break;

                /* Network */
            case MSG_ID_APP_SOC_NOTIFY_IND:
            case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
            case MSG_ID_APP_SOC_GET_HOST_BY_ADDR_IND:
            case MSG_ID_APP_CBM_BEARER_INFO_IND:
            case MSG_ID_APP_CBM_BEARER_EVENT_NOTIFY_IND:
        #if defined (SUPPORT_MMAPI) && defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
                if (g_jma_is_stream_video)
                {
                    jma_stream_player_process_bearer_event(&current_ilm);
                }
                else
        #endif
                {
                    process_soc_async_ind(&current_ilm);
                }
                break;
        #ifdef WAP_SEC_SUPPORT
            case MSG_ID_WPS_SEC_GET_CERT_IDS_RSP:
            case MSG_ID_WPS_SEC_GET_CERT_RSP:
                jam_get_certs_handler(&current_ilm);
                break;
        #endif /* WAP_SEC_SUPPORT */
        #ifdef __MMI_MExE_SUPPORT__
            case MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_IND:
            case MSG_ID_MMI_GET_SIM_CERTIFICATE_RSP:
                jam_get_certs_handler(&current_ilm);
                break;

        #endif /* __MMI_MExE_SUPPORT__ */       

        #ifdef __SSL_SUPPORT__
            case MSG_ID_APP_TLS_NOTIFY_IND:
            case MSG_ID_APP_TLS_ALERT_IND:
            case MSG_ID_APP_TLS_INVALID_CERT_IND:
            case MSG_ID_APP_TLS_CLIENT_AUTH_IND:
                process_tls_async_ind(&current_ilm);
                break;
        #endif
            /* HTTP over WSP indication, response */
            case MSG_ID_WPS_SET_CHANNEL_RSP:
            case MSG_ID_WPS_UNSET_CHANNEL_RSP:
            case MSG_ID_WPS_HTTP_RSP:
            case MSG_ID_WPS_READ_CONTENT_RSP:
            case MSG_ID_WPS_POST_CONTENT_IND:
            case MSG_ID_WPS_CANCEL_RSP:
            case MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP:
            case MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP:
            case MSG_ID_WPS_HTTP_AUTH_IND:
            case MSG_ID_WPS_RECONFIG_CHANNEL_RSP:
                http_wps_response_handler(&current_ilm);
                break;

            case MSG_ID_WPS_CREATE_STREAM_CONNECTION_RSP:
            case MSG_ID_WPS_STREAM_CONNECTION_CLOSED_IND:
            case MSG_ID_WPS_CLOSE_STREAM_CONNECTION_RSP:
            case MSG_ID_WPS_STREAM_DATA_SEND_RSP:
#ifdef __J2ME_STREAM_SUPPORT__                
            case MSG_ID_WPS_STREAM_DATA_READ_RSP:
                j2me_stream_response_handler(&current_ilm);
                break;
#endif  /*__J2ME_STREAM_SUPPORT__*/
                /* File API storage device indication */
            case MSG_ID_FMT_MMI_CARD_PLUG_IN_IND:
            case MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND:
                jvm_file_device_ind_handler(&current_ilm);
                break;

#ifdef SUPPORT_JSR_120
        #ifdef __SUPPORT_INFUSIO__
            case MSG_ID_JAVA_JAVA_ENQUEUE_SMS_REQ:
                jam_enqueue_sms_req_handler(&current_ilm);
                break;
        #endif /* __SUPPORT_INFUSIO__ */ 
#endif        

        #ifdef SUPPORT_JSR_205
                /* WMAPI */
            case MSG_ID_WAP_MMC_SEND_APPMMS_RSP:
            case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_IND:
            case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_RSP:
            case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_RSP:
            case MSG_ID_WAP_MMC_RECV_APPMMS_RSP:
            case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_RSP:
            case MSG_ID_WAP_MMC_ABORT_APPMMS_RSP:
                J2ME_mms_response_handler(&current_ilm);
                break;
                /* WMA Push */
            case MSG_ID_WAP_MMC_APPMMS_NEW_MMS_IND:
                jam_appmms_new_mms_ind_handler(&current_ilm);
                break;
        #endif /* SUPPORT_JSR_205 */ 

#ifdef SUPPORT_JSR_120
            case MSG_ID_MMIAPI_SMS_REGISTER_PORT_RSP:
            case MSG_ID_MMIAPI_SMS_SEND_RSP:
            case MSG_ID_MMIAPI_SMS_SEND_ABORT_RSP:
                J2ME_sms_response_handler(&current_ilm);
                break;
            case MSG_ID_MMIAPI_SMS_GET_SMSC_ADDR_RSP:
                jwa_sms_get_smsc_addr_handler(&current_ilm);
                break;
            case MSG_ID_MMIAPI_SMS_IND:
                jam_mmiapi_sms_ind_handler(&current_ilm);
                break;
#endif

#ifdef SUPPORT_JSR_257
          case MSG_ID_NFC_LIB_INIT_RSP:
                jcc_nfc_driver_init_callback(&current_ilm);
                break;
          case MSG_ID_NFC_LIB_DEINIT_RSP:
                jcc_nfc_driver_deinit_callback(&current_ilm);
                break;
          case MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_RSP: 
                jcc_nfc_register_rsp_handle(&current_ilm);
                break;
	      case MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_CB_IND: 
                jcc_nfc_register_cb_ind_handle(&current_ilm);
                break;
				
	      case MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_RSP: 
                jcc_nfc_unregister_rsp_handle(&current_ilm);
                break;	

          case MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_RSP:
                jcc_nfc_check_presence_rsp_handler(&current_ilm);
                break;
				
	      case MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_CB_IND:
                jcc_nfc_check_presence_cb_ind_handler(&current_ilm);
                break;
		
	      case MSG_ID_NFC_REMOTE_DEV_CONNECT_RSP: 
                jcc_nfc_connect_rsp_handle(&current_ilm);
                break;

	     
	      case MSG_ID_NFC_REMOTE_DEV_CONNECT_CB_IND: 
                jcc_nfc_connect_cb_ind_handle(&current_ilm);
                break;	
		
		
	      case MSG_ID_NFC_REMOTE_DEV_DISCONNECT_RSP: 
                jcc_nfc_close_rsp_handle(&current_ilm);
                break;	

		
	      case MSG_ID_NFC_REMOTE_DEV_DISCONNECT_CB_IND: 
                jcc_nfc_close_cb_ind_handle(&current_ilm);
                break;			

		case MSG_ID_NFC_NDEF_WRITE_RSP: 
                jcc_nfc_write_ndef_rsp_handle(&current_ilm);
                break;	

		case MSG_ID_NFC_NDEF_WRITE_CB_IND: 
                jcc_nfc_write_ndef_cb_ind_handle(&current_ilm);
                break;			

		case MSG_ID_NFC_NDEF_READ_RSP: 
                jcc_nfc_read_ndef_rsp_handle(&current_ilm);
                break;	

		case MSG_ID_NFC_NDEF_READ_CB_IND: 
                jcc_nfc_read_ndef_cb_ind_handle(&current_ilm);
                break;				

		case MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_RSP: 
                jcc_nfc_transceive_rsp_handle(&current_ilm);
                break;		

		case MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_CB_IND: 
                jcc_nfc_transceive_cb_ind_handle(&current_ilm);
                break;		

		case MSG_ID_NFC_NDEF_CHECK_NDEF_RSP: 
                jcc_nfc_check_ndef_rsp_handle(&current_ilm);
                break;

		case MSG_ID_NFC_NDEF_CHECK_NDEF_CB_IND: 
                jcc_nfc_check_ndef_cb_ind_handle(&current_ilm);
                break;

		case MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_RSP: 
                jcc_nfc_check_configure_discover_rsp_handler(&current_ilm);
                break;
		
		case MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_CB_IND: 
                jcc_nfc_check_configure_discover_cb_ind(&current_ilm);
                break;

		case MSG_ID_NFC_SE_GET_SECURE_ELEMENT_LIST_RSP: 
                jcc_nfc_se_get_secure_element_rsp_handler(&current_ilm);
                break;

		case MSG_ID_NFC_SE_NTF_REGISTER_RSP:
				jcc_nfc_se_register_rsp_handle(&current_ilm);
				break;

		case MSG_ID_NFC_SE_SET_MODE_RSP:
				jcc_nfc_se_set_mode_rsp_handler(&current_ilm);
				break;
			
		case MSG_ID_NFC_SE_SET_MODE_CB_IND:
				jcc_nfc_se_set_mode_cb_ind_handler(&current_ilm);
				break;

		case MSG_ID_NFC_SE_NTF_REGISTER_CB_IND:
				jcc_nfc_se_register_cb_ind_handler(&current_ilm);			
				break;

		case MSG_ID_NFC_SE_NTF_UNREGISTER_RSP:
				jcc_nfc_se_unregister_rsp_handle(&current_ilm);
				break;
#endif

#ifdef SUPPORT_JSR_177
            case MSG_ID_SIM_JSR177_ATR_CNF:
                jsatsa_apdu_sim_get_atr_rsp_handler(&current_ilm);
                break;
            case MSG_ID_SIM_JSR177_APDU_CNF:
                jsatsa_apdu_send_apdu_rsp_handler(&current_ilm);
                break;
#endif

            case MSG_ID_MMI_JAVA_GET_IMSI_RES:
                jvm_recv_get_imsi_res((void*)current_ilm.local_para_ptr);
                break;
            case MSG_ID_MMI_JAVA_GET_LAI_RES:
                jvm_recv_get_lai_res((void*)current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMIAPI_DEVICE_GET_CTRL_RSP:
            case MSG_ID_MMIAPI_DEVICE_PLAY_RSP:
            case MSG_ID_MMIAPI_BACKLIGHT_CONTROL_RSP:
                break;

            case MSG_ID_TIMER_EXPIRY:
                jam_jdaemon_timer_expiry_handler(&current_ilm);
                break;
            case MSG_ID_JAVA_MMA_EVENT_CALLBACK:
                jma_audio_player_message_hdlr(&current_ilm);        
                break;
		#ifdef SUPPORT_JSR_179
			case MSG_ID_GPS_UART_RAW_DATA:
				mdi_message_dispatcher(&current_ilm);
				break;
			case MSG_ID_MMI_JAVA_SET_AGPS_RSP:
				jlbs_gps_response_handler(&current_ilm);
				break;
		#endif
            default:            

            #ifdef __DRM_SUPPORT__
                if (DRM_app_common_hdlr(&current_ilm))
                {
                    break;
                }
            #endif /* __DRM_SUPPORT__ */     
                if (jdaemon_vendor_process_event(&current_ilm))
                {
                    break;
                }
            #if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
                else if (jpim_phb_handler(&current_ilm))
                {
                    break;
                }
            #endif /* defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC) */ 
            #if defined(SUPPORT_JSR_75_PIM)
                else if (jpim_evtdb_handler(&current_ilm))
                {
                    break;
                }
            #endif /* defined(SUPPORT_JSR_75_PIM) */            
            #ifdef __SUPPORT_JBT__
                else if (jbt_main(&current_ilm))
                {
                    break;
                }
            #endif /* __SUPPORT_JBT__ */ 
            #if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_ADVANCED_FEATURE)       
                if (jma_transfer_mdi_message_hdlr(&current_ilm))
                {
                    break;
                }       
            #endif /* SUPPORT_MMAPI */ 
                break;
        }
        destroy_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  j2me_task_general_msg_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool j2me_task_general_msg_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
         /* Abort */
        case MSG_ID_MMI_JAVA_ABORT_REQ:
            jam_abort_req_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_ASM_ABORT_REQ:
            jam_asm_abort_handler(ilm_ptr);
            break;
                /* Restore factory */
        case MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_REQ:
            jam_restore_factory_mode_req_handler(ilm_ptr);
            break;

        case MSG_ID_JAM_JVM_GENERAL_ASSIST_REQ:
            jam_jvm_general_assist_req_handler(ilm_ptr);
            break;

        case MSG_ID_JAM_JVM_TCK_START_CNF:
            jam_jvm_tck_start_cnf_handler(ilm_ptr);
            break;

        case MSG_ID_JAM_JVM_TCK_STOP_REQ:
            jam_jvm_tck_stop_req_handler(ilm_ptr);
            break;
            
        case MSG_ID_JAM_JVM_MID_STOP_REQ:
            jam_jvm_mid_stop_req_handler(ilm_ptr);
            break;
            
        case MSG_ID_JAM_JVM_SHUTDOWN_ALL_IND:
            jam_jvm_shutdown_all_ind_handler(ilm_ptr);
            break;
            
       case MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_REQ:
            jam_delete_menu_abort_req_handler(ilm_ptr);
            break;
            
        case MSG_ID_MMI_JAVA_TERMINATE_NOTIFY_IND:
             jam_internal_mid_start_req_terminate_notify_handler(ilm_ptr);
            break;

        case MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_REQ:
            jam_mvm_get_running_mids_list_req_hdlr(ilm_ptr);
            break;

        #ifdef WAP_SEC_SUPPORT
        case MSG_ID_WPS_SEC_GET_CERT_IDS_RSP:
        case MSG_ID_WPS_SEC_GET_CERT_RSP:
            jam_get_certs_handler(ilm_ptr);
            break;
        #endif /* WAP_SEC_SUPPORT */
        case MSG_ID_JAVA_KEYPAD_NOTIFY_IND:
            break;

            /* Get MIDlet Suite information */
        case MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ:
            jam_mids_getinfo_req_handler(ilm_ptr);
            break;

            /* Get/Set MIDlet Suite settings */
        case MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ:
            jam_mids_get_setting_req_handler(ilm_ptr);
            break;

        case MSG_ID_MMI_JAVA_PUSH_GET_SETTING_REQ:
            jam_push_get_setting_req_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ:
            jam_mids_set_setting_req_handler(ilm_ptr);
            break;

            /* Get MIDlet Suite/MIDlet List */
        case MSG_ID_MMI_JAVA_MIDS_GETLIST_REQ:
            jam_mids_getlist_req_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_MID_GETLIST_REQ:
            jam_mid_getlist_req_handler(ilm_ptr);
            break;
            /* Push Alarm permission */
    #ifdef __SUPPORT_JAVA_PUSH__
        case MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES:
            jam_timealarm_push_res_handler(ilm_ptr);
            break;
    #endif
        case MSG_ID_JAM_JVM_MID_START_CNF:
            jam_jvm_mid_start_cnf_handler(ilm_ptr);
           break;


        case MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_REQ:
            jam_nw_get_global_setting_req_handler(ilm_ptr);
            break;
    
        case MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_REQ:
            jam_nw_set_global_setting_req_handler(ilm_ptr);
            break;
    
        case MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_REQ:
            jam_nw_get_local_setting_req_handler(ilm_ptr);
            break;
    
        case MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_REQ:
            jam_nw_set_local_setting_req_handler(ilm_ptr);
            break;
    
        case MSG_ID_MMI_JAVA_NW_GET_PROFILE_REQ:
            jam_nw_get_profile_req_handler(ilm_ptr);
            break;
   
        case MSG_ID_MMI_JAVA_NW_SET_PROFILE_REQ:
            jam_nw_set_profile_req_handler(ilm_ptr);
            break;
          
        case MSG_ID_MMI_JAVA_NW_UPDATE_SETTING_REQ:
            jam_nw_update_setting_req_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_NW_UPDATE_CONN_TYPE_REQ:    
            jam_nw_update_conn_req_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_SET_AUDIO_VOLUME_REQ:
            jam_set_audio_volume_req_handler(ilm_ptr);
            break;
    #ifdef OGDR_SECURITY_SETTING
            /* Security setting for OGDR 5.0 */
        case MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_REQ:
            jam_get_domain_list_req(ilm_ptr);
            break;

        case MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ:
            jam_get_default_domain_req(ilm_ptr);
            break;

        case MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ:
            jam_set_default_domain_req(ilm_ptr);
            break;

        case MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_REQ:
            jam_reset_default_domain_req(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_REQ:
            jam_mids_reset_domain_setting_hdlr(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_REQ:
            jam_get_domain_status_req(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_REQ:
            jam_set_domain_status_req(ilm_ptr);
            break;
    #endif /* OGDR_SECURITY_SETTING */ 
            /* TCK verification request handler */
        case MSG_ID_MMI_JAVA_SET_MODE_REQ:
            jam_set_mode_req_handler(ilm_ptr);
            break;

            /* General timer expiry handlers */
        case MSG_ID_TIMER_EXPIRY:
            jam_timer_expiry_handler(ilm_ptr);
            break;
    #ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_HOMESCREEN__ */       
        case MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_REQ:
            jam_getlist_detect_response(ilm_ptr);
            break; 
        case MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ:
            jam_check_is_running_mids(ilm_ptr);
            break;      
        case MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_IND:
            jam_nw_update_dtcnt_ind_handler(ilm_ptr);
            break;
        case MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_IND:
            jam_nw_delete_dtcnt_ind_handler(ilm_ptr);
            break;
        case MSG_ID_APP_CBM_BEARER_INFO_IND:
            jam_cbm_bearer_info_handler(ilm_ptr);
            break;
		case MSG_ID_MMI_JAVA_GET_APPMGR_INFO_REQ:
			jam_get_appmgr_info_req_handler(ilm_ptr);
			break;
        default:
            #ifdef __DRM_SUPPORT__
                if (DRM_app_common_hdlr(ilm_ptr))
                {
                    return KAL_TRUE;
                }
            #endif /* __DRM_SUPPORT__ */ 

            return KAL_FALSE;   /* this message no one handle it :Q */
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jam_jdaemon_timer_expiry_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_jdaemon_timer_expiry_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stack_timer_struct *timer = (stack_timer_struct*) (ilm_ptr->local_para_ptr);
    kal_uint16 timer_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timer_index = evshed_get_index(ilm_ptr);
    switch(timer_index)
    {
        case 1:
            evshed_timer_handler(jvm_event_scheduler_ptr);
            break;
        default:
            break;

    }
#if defined(SUPPORT_MMAPI) || defined(JSR135_AUDIO_BASIC_FEATURE)
    if (timer == &java_media_timer)
    {
        /* check dependency mutex first */
        do
        {
            if (jma_mutex_lock_no_wait(KAL_TRUE))
            {
                break;
            }
        } while (1);
        
        if (stack_is_time_out_valid(&java_media_timer))
        {
            kal_trace(TRACE_GROUP_4, FUNC_J2ME_TIMER_EXPIRY_HANDLER, timer->timer_indx);
            if (timer->timer_indx == JAVA_MEDIA_TIMER_AUDIO_PDL_PLAYER)
            {
                jma_audio_player_cache_buffering_cyclic();
            }
            #ifdef JSR135_AUDIO_RECORDER
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_AUDIO_RECORDER &&
                     timer->timer_indx < JAVA_MEDIA_TIMER_AUDIO_RECORDER + JVM_NUM)
            {
                jma_audio_recorder_timer_expired(timer->timer_indx - JAVA_MEDIA_TIMER_AUDIO_RECORDER);
            }
            #endif
    #if defined (SUPPORT_JSR_135_VIDEO)    
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_ANIMA_PLAYER && 
                     timer->timer_indx < JAVA_MEDIA_TIMER_ANIMA_PLAYER + JVM_NUM)
            {
                jma_anima_player_draw_frame_cyclic(timer->timer_indx - JAVA_MEDIA_TIMER_ANIMA_PLAYER);
            }
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_ANIMA_PARSE_INFO &&
                     timer->timer_indx < JAVA_MEDIA_TIMER_ANIMA_PARSE_INFO + JVM_NUM)
            {
                jma_anima_player_parse_info_cyclic(timer->timer_indx - JAVA_MEDIA_TIMER_ANIMA_PARSE_INFO);
            }
    #endif /* defined (SUPPORT_JSR_135_VIDEO) */
    #if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_VIDEO_RECORDER && 
                     timer->timer_indx < JAVA_MEDIA_TIMER_VIDEO_RECORDER + JVM_NUM)
            {
                jma_video_recorder_timer_expired(timer->timer_indx - JAVA_MEDIA_TIMER_VIDEO_RECORDER);
            }
    #endif /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_RECORDER__) */ 
    #if defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
    #ifdef __MMI_VIDEO_STREAM__
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_STREAM_PLAYER &&
                     timer->timer_indx < JAVA_MEDIA_TIMER_STREAM_PLAYER + JVM_NUM)
            {
                jma_stream_player_buffering_cyclic(timer->timer_indx - JAVA_MEDIA_TIMER_STREAM_PLAYER);
            }
    #endif /* __MMI_VIDEO_STREAM__ */ 
    #ifdef __MMI_VIDEO_PDL__
            else if (timer->timer_indx >= JAVA_MEDIA_TIMER_PDL_PLAYER &&
                     timer->timer_indx < JAVA_MEDIA_TIMER_PDL_PLAYER + JVM_NUM)
            {
                jma_video_player_cache_buffering_cyclic(timer->timer_indx - JAVA_MEDIA_TIMER_PDL_PLAYER);
            }
    #endif /* __MMI_VIDEO_PDL__ */ 
    #endif /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */ 
        }

        /* MUST be invoked even if JMA wants to ignore the time out message */
        stack_process_time_out(&java_media_timer);

        /* Remember to unlock the additional lock. */
        jma_media_player_dependency_mutex_unlock();
    }
#if defined (SUPPORT_JSR_135_VIDEO)
        else if (timer == &java_stop_time_timer)
        {
            /* check dependency mutex first */
            do
            {
                if (jma_mutex_lock_no_wait(KAL_TRUE))
                {
                    break;
                }
            } while (1);
    
            if (stack_is_time_out_valid(&java_stop_time_timer))
            {   
                jma_anima_player_check_stop_time_cyclic(timer->timer_indx - JAVA_MEDIA_TIMER_ANIMA_PLAYER);           
            }
    
            /* MUST be invoked even if JMA wants to ignore the time out message */
            stack_process_time_out(&java_stop_time_timer);
    
            /* Remember to unlock the additional lock. */
            jma_media_player_dependency_mutex_unlock();
            
        }
		
		/* MAUI_03121973 wenmin 20120523 begin */
#if 0
#if defined (__MMI_BACKGROUND_CALL__) && defined (SUPPORT_JSR_135_VIDEO)
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
#endif
#endif
		/* MAUI_03121973 wenmin 20120523 end */

#endif /* defined (SUPPORT_JSR_135_VIDEO) */
#endif /* SUPPORT_MMAPI */
}


/*****************************************************************************
 * FUNCTION
 *  jam_timer_expiry_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_timer_expiry_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 timer_index = 0;
    stack_timer_struct *timer = (stack_timer_struct*) (ilm_ptr->local_para_ptr);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    timer_index = evshed_get_index(ilm_ptr);
    switch(timer_index)
    {
        case 1:
			jvm_timer_mutex_lock();
            evshed_timer_handler(j2me_alarm_es_ptr);
			jvm_timer_mutex_unlock();
            break;
        default:
            break;
    }
    if (timer == &g_jam_vibrator_timer)
    {
        if (stack_is_time_out_valid(&g_jam_vibrator_timer))
        {
            jvm_stopVibrate_call_by_Jdaemon();
        }
        /* Should be paired with stack_is_time_out_valid() */
        stack_process_time_out(&g_jam_vibrator_timer);
    }    
}

