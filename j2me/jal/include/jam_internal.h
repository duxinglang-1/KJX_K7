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
 *   jam_events.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JAM (Java Application Manager) event handling APIs
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _JAM_ADAPTATION_H
#define _JAM_ADAPTATION_H

/*************************************************************************
 * Include Statements
 *************************************************************************/
/* Font */
#include "mmi_frm_gprot.h"
#include "gui.h"
#include "j2me_custom.h"
#include "uart_sw.h"
#include "wap_ps_struct.h"
#include "jpush_interface.h"
#include "jam_interface.h"
#include "mmi_rp_app_java_def.h"

/*************************************************************************
 * Definitions
 *************************************************************************/
#ifdef __JBLENDIA__
    #define MIDSLIST_MEM_POOL_SIZE                     (55*1024)
#else
    #ifdef __PLUTO_MMI_PACKAGE__
        #ifdef J2ME_SLIM_MEMORY_SUPPORT
        #define MIDSLIST_MEM_POOL_SIZE                     (15*1024)
        #else
        #define MIDSLIST_MEM_POOL_SIZE                     (75*1024)
        #endif
    #else/* __PLUTO_MMI_PACKAGE__ */
        #ifdef J2ME_SLIM_MEMORY_SUPPORT
	   #define MIDSLIST_MEM_POOL_SIZE					  (10*1024)
	   #else
           #define MIDSLIST_MEM_POOL_SIZE                     (30*1024)
    #endif
#endif
#endif
#ifdef J2ME_SLIM_MEMORY_SUPPORT
#if(defined(__MMI_APP_MANAGER_SUPPORT__)||defined(__COSMOS_MMI_PACKAGE__))
#define __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__    
#endif
#endif
#if (defined(__COSMOS_MMI_PACKAGE__)&&defined(J2ME_SLIM_MEMORY_SUPPORT))
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
#define J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
#endif
#endif
#define HADDR_0(a)                              (((kal_uint8*)(&a))[0])
#define HADDR_1(a)                              (((kal_uint8*)(&a))[1])
#define HADDR_2(a)                              (((kal_uint8*)(&a))[2])
#define HADDR_3(a)                              (((kal_uint8*)(&a))[3])
/*#if defined(SUPPORT_JSR_179) && !defined(SUPPORT_JSR_257) 
#define TOTAL_SETTINGS                          (36)
#elif !defined(SUPPORT_JSR_179) && defined(SUPPORT_JSR_257) 
#define TOTAL_SETTINGS                          (38)
#elif defined(SUPPORT_JSR_179) && defined(SUPPORT_JSR_257) 
#define TOTAL_SETTINGS                          (45)
#else
#define TOTAL_SETTINGS                          (29)
#endif*/
#define TOTAL_SETTINGS                          (45)

#define JVM_GET_NEXT_EVENT_INDX     (87654321)
extern kal_int32 g_jvm_get_next_event_result;

extern UART_PORT PS_UART_PORT;

extern kal_bool g_jam_install_bearer_switch;


/*****************************************************************************
 * FUNCTION
 *  jam_default_commport
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline UART_PORT jam_default_commport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return PS_UART_PORT;
}

typedef enum
{
    JAVA_IO_COMM_DEVICE = 0,
    JAVA_IO_DATAGRAM_DEVICE,
    JAVA_IO_SOCKET_DEVICE,
    JAVA_IO_SSL_DEVICE,
    JAVA_SYS_FILE_DEVICE,
    JAVA_WMA_SMS_DEVICE,
    JAVA_WMA_MMS_DEVICE,
    JAVA_INVALID_DEVICE
} java_device_enum;

typedef enum
{
    JAVA_SCREEN_TYPE_JAVA,
    JAVA_SCREEN_TYPE_JAVA_MMI,
    JAVA_SCREEN_TYPE_UNKNOW,
    JAVA_SCREENT_TOTAL
}JAVA_SCREEN_TYPE_ENUM;
typedef struct suiteStruct_
{
    struct suiteStruct_ *next;
    char *midletsuiteName;
    int len;
    int trusted;
} suiteStruct, *suiteStructPtr;

typedef struct fileStruct_
{
    struct fileStruct_ *next;
    char *fileName;
    int checked;
} fileStruct, *fileStructPtr;

/* This structure contains all the security settings of a MIDlet suite */
/* mids_setting_struct */
typedef struct _mids_setting_struct_t
{
    kal_char permission_http;
    kal_char permission_https;
    kal_char permission_ssl;
    kal_char permission_tcp;
    kal_char permission_tcp_server;
    kal_char permission_udp;
    kal_char permission_udp_server;
    kal_char permission_rtsp;
    kal_char permission_comm;
    kal_char permission_push;
    kal_char permission_sms_server;
    kal_char permission_sms_send;
    kal_char permission_sms_receive;
    kal_char permission_cbs_server;
    kal_char permission_cbs_receive;
    kal_char permission_mms_server;
    kal_char permission_mms_send;
    kal_char permission_mms_receive;
    kal_char permission_mma_record;
    kal_char permission_mma_snap_shot;
    kal_char permission_file_read;
    kal_char permission_file_write;
    kal_char permission_contact_list_read;
    kal_char permission_contact_list_write;
    kal_char permission_event_list_read;
    kal_char permission_event_list_write;
    kal_char permission_todo_list_read;
    kal_char permission_todo_list_write;
	kal_char permission_content_contenthandler;
    kal_char permission_apdu_aid;
    kal_char permission_jcrmi;
    kal_char permission_apdu_sat;
    kal_char permission_contactless_discovery;
    kal_char permission_contactless_write;
    kal_char permission_ndeftag_open;
    kal_char permission_plaintag_open;
    kal_char permission_isoofffft_open;
    kal_char permission_visualtag_open;
	kal_char permission_location; 
    kal_char permission_orientation;
    kal_char permission_proximityListener;
    kal_char permission_landmarkStore_read; 
    kal_char permission_landmarkStore_write;
    kal_char permission_landmarkStore_category;
    kal_char permission_landmarkStore_management;  
    /* reserved for the future */
    //kal_char permission_obex_client;
    //kal_char permission_obex_server;
    //kal_char permission_obex_client_tcp;
    //kal_char permission_obex_servet_tcp;
    //kal_char permission_bt_client;
    //kal_char permission_bt_server;
} mids_setting_struct;

typedef struct _jam_drm_sd_callback_struct_t
{
    kal_int32 get_right_completed;
    kal_int32 wait_time;
    kal_bool need_acquire_right;
    kal_int32 waiting_right_serial;
}jam_drm_sd_callback_struct_t;

extern kal_wchar *g_jam_drm_current_install_jar_path;
#if defined(J2ME_SLIM_MEMORY_SUPPORT) && defined(__PLUTO_MMI_PACKAGE__)
#define j2me_midslist_mem_malloc(x)             jvm_malloc(x)
#define j2me_midslist_mem_free(x)               jvm_free(x)
#elif (defined(__COSMOS_MMI_PACKAGE__)&&defined(J2ME_SLIM_MEMORY_SUPPORT))
#define j2me_midslist_mem_malloc(x)             jvm_malloc(x)
#define j2me_midslist_mem_free(x)               jvm_free(x)
#else
#define j2me_midslist_mem_malloc(x)             jam_listmem_malloc(x)
#define j2me_midslist_mem_free(x)               jam_listmem_free(x)
#endif
extern kal_mutexid g_jam_resource_mutex;
#define RES_CS_ENTER()        kal_take_mutex(g_jam_resource_mutex)
#define RES_CS_LEAVE()        kal_give_mutex(g_jam_resource_mutex)
/* revise event group */
typedef enum
{
    JAVA_EG_PIM_PHB_GETCOUNT          = 0x00000001,//JPIM_PHB_EG_GETCOUNT
    JAVA_EG_PIM_PHB_FETCH_INDEX       = 0x00000002,//JPIM_PHB_EG_FETCH_INDEX
    JAVA_EG_PIM_PHB_APPEND_ENTRY      = 0x00000004,//JPIM_PHB_EG_APPEND_ENTRY
    JAVA_EG_PIM_PHB_UPDATE_ENTRY      = 0x00000008,//JPIM_PHB_EG_UPDATE_ENTRY
    JAVA_EG_PIM_PHB_DELETE_ENTRY      = 0x00000010,//JPIM_PHB_EG_DELETE_ENTRY
    JAVA_EG_PIM_PHB_SEARCH_ENTRY      = 0x00000020,//JPIM_PHB_EG_SEARCH_ENTRY
    JAVA_EG_PIM_PHB_GET_GROUP_COUNT   = 0x00000040,//JPIM_PHB_EG_GET_GROUP_COUNT
    JAVA_EG_PIM_PHB_GET_GROUP_INFO    = 0x00000080,//JPIM_PHB_EG_GET_GROUP_INFO
    JAVA_EG_PIM_PHB_SET_GROUP_INFO    = 0x00000100,//JPIM_PHB_EG_SET_GROUP_INFO

    JAVA_EG_PIM_EVTDB_GETCOUNT        = 0x00000200,//JPIM_EVTDB_EG_GETCOUNT
    JAVA_EG_PIM_EVTDB_FETCH_INDEX     = 0x00000400,//JPIM_EVTDB_EG_FETCH_INDEX
    JAVA_EG_PIM_EVTDB_APPEND_ENTRY    = 0x00000800,//JPIM_EVTDB_EG_APPEND_ENTRY
    JAVA_EG_PIM_EVTDB_UPDATE_ENTRY    = 0x00001000,//JPIM_EVTDB_EG_UPDATE_ENTRY
    JAVA_EG_PIM_EVTDB_DELETE_ENTRY    = 0x00002000,//JPIM_EVTDB_EG_DELETE_ENTRY

    JAVA_EG_SMS_NOTIFY_RETREIVE       = 0x00004000,
    JAVA_EG_SMS_COMPLETE_RETREIVE     = 0x00008000,

    JAVA_EG_MMS_NOTIFY_RETREIVE       = 0x00010000,
    JAVA_EG_MMS_COMPLETE_RETREIVE     = 0x00020000,

    JAVA_EG_PUSH_CHECK_RUNNING        = 0x00040000,

    JAVA_EG_LBS_WAITING_RESULT        = 0x00080000,
    
    JAVA_EG_RESET_MASK                = 0x0FFFFFFF
}java_eventgroup1_event_code_enum;


typedef enum
{
    JAVA_EG_MMI_LOCK_EVENT = 0X00000001,
    JAVA_EG_GETLIST_1 = 0X00000002,
    JAVA_EG_GETLIST_2 = 0X00000004,
    JAVA_EG_GETLIST_3 = 0X00000008,
    JAVA_EG_JVM_GET_NEXT_EVENT_1 = 0X00000010,
    JAVA_EG_JVM_GET_NEXT_EVENT_2 = 0X00000020,
    JAVA_EG_GET_RUNNING_LIST = 0X00000040,
    JAVA_EG_ASM = 0X00000080,
    JAVA_EG_NW_USEABLE = 0X00000100,
    J2ME_EG_GET_IMSI = 0X00000200,
    /* 0x00000400 ~ 0x00004000 is reserved for jbt, check JBT_POWER_OFF_EVENT_ENUM */
    JAVA_EG_COMM_WRITE = 0X00020000,
    JAVA_EG_REVERSE
}java_eventgroup2_event_code_enum;

/*--------------*/
/*************************************************************************
 * Declaration
 *************************************************************************/
/* Task management */
extern kal_uint32 g_jam_Java_State;
extern kal_int32 jam_listmem_initialize(void);
extern int jam_listmem_finalize(void);
extern void *jam_listmem_malloc(int size);
extern void jam_listmem_free(void *ptr);

/* Storage */
extern int storage_recovery(void);

extern kal_uint8 jam_get_vk_permission(void);
extern kal_uint8 jam_get_net_icon_setting(void);
extern kal_uint8 jam_get_app_id(kal_int32 vm_id);
extern kal_uint8 jam_get_sim_setting(void);
extern kal_uint8 jam_mvm_get_app_cbm_sim_id(kal_int32 vm_id);
extern void jam_set_wap_prof_id(wap_get_bra_prof_id_rsp_struct *prof_id);
extern void jam_set_wap_prof_content(wap_get_prof_content_rsp_struct* prof_content);
extern kal_uint8 jam_get_install_app_id(void);

extern kal_bool is_resource_suspended(void);

/* Vender providing function */
extern void jvm_vendor_init(void);                          
extern kal_bool jvm_vendor_process_event(ilm_struct *ilm_ptr); 
extern kal_bool jdaemon_vendor_process_event(ilm_struct *ilm_ptr); 
extern void j2me_custom_lcd_init(void); 
extern void j2me_custom_resource_info(j2me_custom_resource_info_struct *info_ptr);//¥Îinclude
extern void jvm_file_get_usedspace(void);

/* custom information */
extern void javaFileGenerator(kal_bool force_remove_all);  //¥Îinclude

/* jam_msg_handler */
extern void jam_remove_all_mids_notify(void);
#ifdef __DM_SCOMO_SUPPORT__
void jam_remove_single_mids_notify(kal_char* storage_name);
extern void jam_remove_mids_check(void);
extern void jam_preinstall_mids_notify(void);
#endif/* __DM_SCOMO_SUPPORT__*/
extern void jam_send_mid_start_req(
									  kal_uint8 wap_prof_id, kal_uint32 mids_id,
									  kal_int32 mid_id, kal_wchar *mid_name,
									  kal_char *storage_name); 
extern void jam_enqueue_sms_req_handler(ilm_struct *ilm_ptr);
    /* TCK verification */
extern void jam_set_mode_req_handler(ilm_struct *ilm_ptr); 
/* jam_screen_switch */
extern void jam_exit_screen_callback_for_asm(void);


/* jam_msg_process */
extern kal_uint8 jam_mvm_get_app_cbm_sim_id(kal_int32 vm_id);
extern kal_bool jam_domain_compare(kal_wchar* domain, kal_int32 domain_index);
#ifdef OGDR_SECURITY_SETTING
extern kal_char *g_jam_operator_domain_str_tbl[];
extern kal_char *g_jam_manufacturer_domain_str_tbl[];
extern kal_char *g_jam_thirdparty_domain_str_tbl[];
extern kal_char *g_jam_untrusted_domain_str_tbl[];

#endif /* OGDR_SECURITY_SETTING */

/* jam_drm */
extern void jam_drm_set_waiting_time(kal_int32 time, kal_char* time_string);

/* jam_screen_switch */
/*************************************************************************
 * extern variable
 *************************************************************************/
extern kal_bool g_jvm_keypad_need_notify;
extern kal_mutexid g_jam_resmgr_mutex;

extern kal_eventgrpid g_java_event_group_1;
extern kal_eventgrpid g_java_event_group_2;

/*************************************************************************
 * extern function
 *************************************************************************/
/* screen switch */
extern void jam_goto_idle_screen_callback(void *data);    /* this function is call by MMI */
extern void jam_goto_idle_screen(void *vm_ptr); /* this function is call by JAVA */
extern void jam_exit_screen_callback(void *data); /* this function is call by MMI */
extern void jam_exit_screen(void *vm_ptr);  /* this function is call by JAVA */
extern void jam_resume_screen(void);    /* this function is call by MMI */
extern void jam_pause_screen(void); /* this function is call by MMI */
extern void jam_enter_screen(kal_int32 vm_id); /* this function is call by MMI */

extern void jam_exit_dummy_screen(void);
extern void jam_pause_dummy_screen(void);
extern void jam_resume_dummy_screen(void);

extern mmi_ret jam_enter_idle_screen_notify(mmi_event_struct *param); /* this function is call by MMI */
extern void jam_delete_screen_notify(kal_int32 vm_id); /* this function is call by MMI */
extern void jam_enter_terminate_mode(kal_int32 vm_id);
extern void jam_enter_terminating_mod(kal_int32 vm_id);
extern void jam_terminate_by_asm(void);
extern void jam_enter_pause_mode(kal_int32 vm_id);
extern void jam_enter_minimize_mode(kal_int32 vm_id,kal_bool pauseapp);
extern void jam_exit_screen_callback_for_asm(void);
extern void jam_asm_free_mem_notification(kal_bool* keep);

extern kal_bool jam_is_in_terminate_menu(void);
extern kal_bool jam_mvm_is_vm_running(kal_int32 vm_id);
extern kal_bool jam_mvm_is_minimize_mode(kal_int32 vm_id);
extern kal_bool jam_mvm_is_pause_mode(kal_int32 vm_id);
extern kal_bool jam_mvm_is_teminate_mode(kal_int32 vm_id);
extern kal_bool jam_mvm_is_vm_terminating(kal_int32 vm_id);
extern kal_int32 jam_mvm_whole_heap_alloc(java_mode_enum java_mode);
extern kal_int32 jam_mvm_whole_heap_release(void);
#define jam_is_minimize_mode() jam_mvm_is_minimize_mode(0)
#define jam_is_pause_mode() jam_mvm_is_pause_mode(0)
#define jam_is_teminate_mode() jam_mvm_is_teminate_mode(0)

extern kal_bool jam_is_in_background_long_time(kal_int32 vm_id);
extern kal_bool jam_is_own_mmi_screen(kal_int32 vm_id);
extern kal_bool jam_is_in_fg_screen(kal_int32 vm_id);
extern kal_bool jam_is_in_fg_mmi_screen(kal_int32 vm_id);
extern kal_bool jam_vm_canbe_paused(kal_int32 vm_id);
extern kal_bool jam_vm_canbe_minimize(kal_int32 vm_id);

extern kal_bool jam_is_own_screen(void);
extern kal_bool jam_is_own_java_screen(kal_int32 vm_id);

extern kal_bool jam_is_enter_fg_mmi_screen(void);
extern kal_bool jam_is_enter_in_fg_mmi_screen_2(kal_uint16 screenId);
extern kal_bool jam_is_enter_fg_mmi_pluto_screen(void);
extern void jam_notify_vm(void);
extern void jam_delete_fg_mmi_screen(void);
extern void jam_change_vm_state(kal_int32 vm_id,kal_uint16 oldScreenId, kal_uint16 newScreenId);
extern void jam_exit_fg_mmi_screen_callback(kal_uint16 oldScreenId, kal_uint16 newScreenId,void (*mmi_screen_enter_func)());
extern void jam_resume_fg_mmi_screen_callback(kal_uint16 oldScreenId,kal_uint16 newScreenId,kal_int32 previous_screen,kal_int32 next_screen);
extern kal_bool jam_vm_canbe_paused(kal_int32 vm_id);
extern kal_bool jam_vm_canbe_minimize(kal_int32 vm_id);
extern kal_bool jam_has_entered_idle_screen(void); /* called by JVM */
extern kal_bool jam_no_network_connection(void);
extern kal_bool jam_is_allow_format(CHAR drive);
extern kal_bool jam_usb_mode_check(void);
extern void jam_enter_usb_mode(void);
extern mmi_ret jam_enter_usb_ms_callback(mmi_event_struct *evt);
extern void jam_shutdownAllExternal(kal_bool is_forced);
extern void jam_initVMExternal(kal_int32 vm_id);
extern void jam_resumeVMExternal(kal_int32 vm_id,kal_int32 src, kal_int32 dst);
extern void jam_pauseVMExternal(kal_int32 vm_id,kal_int32 src, kal_int32 dst);
extern void jam_minimizeVMExternal(kal_int32 vm_id, kal_int32 src, kal_int32 dst);
extern void jam_activeVMExternal(kal_int32 vm_id, kal_int32 src, kal_int32 dst);
extern void jam_stopVMExternal(kal_int32 vm_id);
extern void jam_stop_FS_action(void);
extern mmi_ret jam_PR_outgoing_call_deleted_CB(mmi_event_struct *ucm_data);
extern mmi_ret jam_sg_proc(mmi_event_struct *evt);
extern void jam_get_certs_handler(ilm_struct *ilm_ptr);

extern void j2me_custom_file_init(void);
extern kal_bool jam_nw_is_default_network_setting_exist(void);
extern void jam_preinstall_mids_notify_mainmenu(void);
extern kal_bool jam_is_mmi_cosmos_support();
#endif /* _JAM_ADAPTATION_H */ 

