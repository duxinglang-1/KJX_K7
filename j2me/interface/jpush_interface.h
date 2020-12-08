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
 *  jpush_interface.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef _JPUSH_INTERFACE_H
#define _JPUSH_INTERFACE_H

/*************************************************************************
 * Global Definition
 *************************************************************************/
#include "j2me_custom.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_msg_handler.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" 		/* Task message communiction */
#include "tst_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   		/* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" 		/* Event scheduler */
#include "app_buff_alloc.h"
#include "kal_trace.h"
#include "MMIDataType.h"
/*************************************************************************
 * Global Definition
 *************************************************************************/
/* Reserved feature */
#define PERSISTENT_PUSH                                             (1)

#define PERSISTENT_ALARMPUSH                                        (1)

/* maximum count for time alarm push and general push */
//#if !defined(MT6223C) && !defined(MT6223P) && !defined(MT6223P_S00) 
#ifdef J2ME_SLIM_MEMORY_SUPPORT
#define MAX_PUSH_REGISTRY										    (5)
#else
#define MAX_PUSH_REGISTRY										    (20)
#endif
//#else
//#define MAX_PUSH_REGISTRY										    (3)
//#endif

#define MAX_PUSH_LINE												(512)

#define PPUSH_FILE                          ("ppush.txt")
#define PUSHPATH_NAME                           "pushlist.txt"
#define ALARMPATH_NAME                          "alarmlist.txt"

//#define __SUPPORT_JAVA_PUSH__



#if !(defined(__COSMOS_MMI_PACKAGE__)&&defined(J2ME_SLIM_MEMORY_SUPPORT))//if not cosmos&&slim,we must support jpush
    #ifndef __SUPPORT_JAVA_PUSH__
        #define __SUPPORT_JAVA_PUSH__
        
    #endif
#endif

//First:If supprot mms/nfc/sms,we must support jpush
//Second: As JSR_120 is enabled in default and for reducing size by removing push under cosmos_slim, do not constraint like between JSR_257 and jpush
#if (defined(SUPPORT_JSR_257) ) //||defined(SUPPORT_JSR_205)||defined(SUPPORT_JSR_120)
    #ifndef __SUPPORT_JAVA_PUSH__
        #define __SUPPORT_JAVA_PUSH__
    #endif
#endif
typedef enum
{
	PUSHTYPE_ALARM_PUSH,
	PUSHTYPE_SMS_PUSH,
	PUSHTYPE_MMS_PUSH,
    PUSHTYPE_NFC_PUSH,
	PUSHTYPE_INVALID_PUSH
} pushtype_enum;
	
typedef enum
{
    WMA_REGISTRY,
    PUSH_REGISTRY
} pushregistry_type;

typedef enum
{
    NON_REGISTERED,
    WMA_REGISTERED,
    PUSH_REGISTERED,
    PUSH_CONFLICT_REGISTERED
} sms_port_status;

typedef struct pushentry_struct_t
{
    struct pushentry_struct_t *next;

    int portNo;

    int available;
    char *connection;
    char *midlet;
    char *filter;
    char *storagename;
    int midletid;

    char *appid;

    char *nfc_url;

    game_type_enum push_game_type;
} pushentry_struct;

typedef struct alarmentry_struct_t
{
    struct alarmentry_struct_t *next;

    char *midlet;
    char *storagename;
    int midletid;
    kal_int64 wakeup;
    int executed;
    eventid event_id;

    game_type_enum alarm_game_type;
} alarmentry_struct;

typedef struct _mmi_java_push_vm_status_element_struct_t
{
    char* storage;       
    char* name;
    kal_uint8 vm_id;
               
}mmi_java_push_vm_status_element_struct;

typedef struct _mmi_java_push_cntx_struct_t
{
    /* flag */
    kal_bool is_VM_full;
    kal_bool is_need_to_minimize_midlet;
    kal_bool is_terminate_push_midlet;    

    /* screen group id */
    MMI_ID otion_menu_id;
    MMI_ID vm_status_menu_id;
    
    kal_uint8 vm_status_menu_hilite_idx;
    kal_uint8 option_choice;    

    /* running midlet list */
    mmi_running_mid *running_mid_list;
    kal_int32 running_mid_count;

    /* push table */
    mmi_java_timealarm_push_ind_struct push_entry[MAX_PUSH_REGISTRY];
    kal_bool push_entry_used[MAX_PUSH_REGISTRY];

    kal_bool is_processing;
    kal_uint32 processing_idx;
    kal_bool timer_set;

    kal_bool first_push_during_bgcall_arrive;    
    kal_bool is_launch;    

    kal_bool scrn_force_del_check;
    
    kal_bool is_exit_tskmgr;
    
    kal_uint8 check_mid_running_result;
    
}mmi_java_push_cntx_struct;

/*************************************************************************
 * Global Declaration
 *************************************************************************/
 extern char *jpush_push_findconn(char *str);
 extern char *jpush_push_findsuite(char *store, kal_bool available);
 extern void* push_process_recvd_sms_ind(int port);

 #ifdef __SUPPORT_JAVA_PUSH__
extern int jpush_push_open(char *push_path);
extern void jpush_push_enable(kal_bool enable);
extern void jpush_push_set_unavailable(char *store);
extern void jpush_push_deletesuite(char *store);
extern kal_char *jpush_push_getstoragename(kal_char *connection, kal_int32 field, kal_int32 *length);
extern int jpush_push_checkappid(char *application_id, int type, int vm_id);

extern void jpush_push_restore_factory_setting(void);

extern kal_mutexid g_jpush_record_mutex;
/* TimeAlarm */
extern int jpush_alarm_open(char *alarm_path);
extern int jpush_alarm_add(char *str, kal_int64 alarm, kal_int64 *lastalarm);
extern eventid jpush_alarm_set(alarmentry_struct *entry_ptr, kal_uint32 alarmtime);
extern void jpush_alarm_cancel(eventid *event_id);
extern void jpush_alarm_save(void);
extern int jpush_alarm_del(alarmentry_struct *del_alarm);
extern kal_int64 jpush_alarm_check(kal_int64 time);

	#ifdef __SUPPORT_INFUSIO__
extern kal_int32 jpush_eureka_init(void);	
	#endif /* __SUPPORT_INFUSIO__ */
	
#if PERSISTENT_PUSH
extern int jpush_push_parse(int pushfd);
extern void jpush_push_free(void);

extern int jpush_alarm_parse(int alarmfd);
extern void jpush_alarm_free(void);

extern void jpush_push_clear(void);

extern kal_char* pushstorage(kal_char *connection, kal_int32 field, kal_int32 *length);
#endif /* PERSISTENT_PUSH */ 

extern kal_int32 jpush_add_persistent_push(kal_uint32 port_no, kal_uint32 alarmpush_type,
    kal_char *mid_name, kal_int32 mid_id, kal_char *mid_storagename, kal_char* filter, kal_char* connection, kal_char* app_id, kal_char* nfc_url);
extern kal_int32 jpush_search_and_delete_persistent_push(kal_int32 port_no,
    kal_uint32 alarmpush_type, kal_char *mid_name, kal_int32 mid_id, kal_char *mid_storagename, kal_char* filter, kal_char* connection,
    kal_char* app_no, kal_char* nfc_url, kal_bool delete_found_record);
extern kal_int32 jpush_ppush_retrieval_init(void);
extern kal_int32 jpush_ppush_retrieval_next(game_type_enum *game_type, kal_uint32* port_no, 
    kal_uint32 *alarmpush_type, kal_char **mid_name,kal_int32 *mid_id, kal_char **mid_storagename, kal_char ** filter,
    kal_char **connection, kal_char** app_no, kal_char **nfc_url);
extern kal_int32 jpush_ppush_retrieval_final(void);
extern kal_int32 jpush_init_persistent_push_entries(void);
extern kal_mutexid g_jam_push_mutex;
extern void jpush_push_set_unavailable_by_connection(char *connection);
extern int j2me_check_push_register_port(int port, int type, int vm_id);
extern void* j2me_process_recvd_sms_ind(ilm_struct *ilm_ptr);
extern void* j2me_process_recvd_mms_ind(ilm_struct *ilm_ptr);
extern void* push_process_recvd_mms_ind(char *application_id);

extern int jpush_push_read_entries_count(int *number);
extern int jpush_push_read_entry(int index, int *handle);
extern int jpush_push_read_connection_string(int *handle, char *buffer, int *length);
extern int jpush_push_trigger(int *handle, char *buffer, int length);
extern int jpush_push_read_trigger(int *handle, char *buffer, int *length);

/*************************************************************************
 * jpush file name Config
 *************************************************************************/
static kal_bool jpush_is_vm_redef_jpush_fs = KAL_FALSE;
static kal_char jpush_general_push_fs_name[15] = "pushlist.txt";
static kal_char jpush_general_persistent_push_fs_name[15] = "ppush.txt";
static kal_char jpush_alarm_push_fs_name[15] = "alarmlist.txt";

static void jpush_config_file_name(kal_char* general_push_fs_name, kal_char* general_persistent_push_fs_name, kal_char* alarm_push_fs_name)
{
    jpush_is_vm_redef_jpush_fs = KAL_TRUE; 
    strncpy(jpush_general_push_fs_name, general_push_fs_name, 14);
    strncpy(jpush_general_persistent_push_fs_name, general_persistent_push_fs_name, 14);
    strncpy(jpush_alarm_push_fs_name, alarm_push_fs_name, 14);    

}
#endif

#endif /* _JPUSH_INTERFACE_H */ 

