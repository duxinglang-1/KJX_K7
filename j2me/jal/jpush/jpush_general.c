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
 *   jam_push.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
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
#include <stdlib.h>     /* for atoll */
#include "jal.h"
#include "jvm_internal.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "tst_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "app_buff_alloc.h"
#include "jpush_interface.h"
#include "jwa_internal.h"
#include "jam_interface.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "l4c_common_enum.h"
#ifdef SUPPORT_JSR_257_PUSH
#include "jcc_internal.h"
#endif
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
#include "FileMgrSrvGProt.h"
#endif
#include "l4a.h"
#define MMIAPI_USING_SMS
#include "mmiapi_struct.h"

/*************************************************************************
 * Global Definition
 *************************************************************************/
#define EUREKA_SMSQUEUE_FILE                 ("eureka_queuefile.txt")
#define EUREKA_SMSQUEUETMP_FILE                 ("eureka_queuefile_tmp.txt")
#define PPUSH_FILE                          ("ppush.txt")
#define PUSHPATH_NAME                           "pushlist.txt"
#define ALARMPATH_NAME                          "alarmlist.txt"

/*
 * Active push list - all game_type's active pushes are on the list, but possible 
 * * save to different _pushlist.txt.
 */
pushentry_struct *g_jpush_pushlist_ptr = NULL;
static kal_bool g_jpush_push_enabled = 1;
kal_int32 g_push_length = 0;
static char _push_path[MAX_WCHAR_FILENAME_LEN];
static kal_bool before_persistent_push_finished = KAL_FALSE;
static kal_int32 ppush_counter = 0;
extern jam_call_back_function_struct jam_call_back_functions;
extern mmi_java_push_cntx_struct g_mmi_java_push_cntx;
int pushlist_len = 0;
WCHAR WCHARFilename_push[MAX_WCHAR_FILENAME_LEN];

/*************************************************************************
 * Global Declaration
 *************************************************************************/

extern alarmentry_struct *g_jpush_alarmlist_ptr;
extern kal_int32 g_timealarm_count;
extern event_scheduler *j2me_alarm_es_ptr;

#ifdef __SUPPORT_JAVA_PUSH__
extern void J2ME_mms_register(char *application_id, int op, int type, int vm_id);
extern int _jwa_sms_receive_binary_msg_req(long port);
extern int _jwa_sms_receive_text_msg_req(long port);
extern unsigned short *_jwa_sms_get_incoming_msg_addr(long portNumber, int *len);
extern kal_bool jwa_sms_get_ori_timestamp(long portNumber, kal_uint8 *time);
extern int _jwa_sms_check_incoming_msg(long portNumber, kal_bool only_new);
extern void jam_timealarm_push_ind_handler(
                kal_uint32 type,
                void *callback_entry,
                kal_char *mid_name,
                kal_int32 mid_id,
                kal_char *mid_storagename,
                kal_bool show_popup);
extern void jpush_timer_mutex_unlock(void);
extern void jpush_timer_mutex_lock(void);
/*************************************************************************
 * Function Definition
 *************************************************************************/




/*****************************************************************************
 * FUNCTION
 *  jpush_push_open
 * DESCRIPTION
 *  Current implementation save different game_typ's pushlist at private
 *  folder, however, g_jpush_pushlist_ptr maintains all active push.
 *  
 *  Open the push Registry file, if it exists and populate
 *  an in memory cache of the file contents.
 * PARAMETERS
 *  game_type       [IN]        
 *  push_path       [?]
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_open(char *push_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 0;
    kal_int32 pushfd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
    work_info_ptr = _jvm_get_builtin_file_info();
    work_sys_dir_path = _jvm_get_dir_path();
    ASSERT((strlen(push_path) + 1) <=  MAX_WCHAR_FILENAME_LEN);
    memcpy(_push_path, push_path, strlen(push_path) + 1);

    //sprintf(_kvmLogStr, "pe->jpush_push_open: game_type=%d, push_path = %s\n", 0, push_path);
    //Kprintf();

#if !PERSISTENT_PUSH
    /* Force to clean all registered push after re-boot */
    if ((pushfd = jvm_file_open(push_path, O_CREAT | O_TRUNC)) == -1)
    {
        result = (-1);
    }
#else /* !PERSISTENT_PUSH */ 

    /* Now read the registered connections. */
    if ((pushfd = jvm_file_open(push_path, O_RDONLY)) != -1)
    {
        /* Read through the file one line at a time */
        if (jpush_push_parse(pushfd) == -2)
        {
            result = (-1);
        }
    }
    else if ((pushfd = jvm_file_open(push_path, O_CREAT | O_TRUNC)) == -1)
    {
        result = (-1);
    }
#endif /* !PERSISTENT_PUSH */ 

    if (pushfd != -1)
    {
        jvm_file_close(pushfd);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_push_save
 * DESCRIPTION
 *  Save the in memory cache of push registrations to a persistent
 *  file for use in subsequent runs.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    kal_int32 pushfd;
    kal_char tmp_buf[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jpush_timer_mutex_lock();
    if ((pushfd = jvm_file_open(_push_path, O_CREAT | O_TRUNC)) != -1)
    {
        /* Write a new list of push registrations to the persistent file */
        for (p = g_jpush_pushlist_ptr; p != NULL; p = p->next)
        {
            jvm_file_write(pushfd, p->connection, strlen(p->connection));
            jvm_file_write(pushfd, ",", 1);
            jvm_file_write(pushfd, p->midlet, strlen(p->midlet));
            jvm_file_write(pushfd, ",", 1);
            jvm_file_write(pushfd, p->filter, strlen(p->filter));
            jvm_file_write(pushfd, ",", 1);
            jvm_file_write(pushfd, p->storagename, strlen(p->storagename));
            jvm_file_write(pushfd, ",", 1);

            tmp_buf[0] = (p->midletid & 0xff000000) >> 24;
            tmp_buf[1] = (p->midletid & 0x00ff0000) >> 16;
            tmp_buf[2] = (p->midletid & 0x0000ff00) >> 8;
            tmp_buf[3] = p->midletid & 0x000000ff;
            jvm_file_write(pushfd, tmp_buf, 4);
            jvm_file_write(pushfd, ",", 1);
			
            tmp_buf[0] = (p->portNo & 0xff000000) >> 24;
            tmp_buf[1] = (p->portNo & 0x00ff0000) >> 16;
            tmp_buf[2] = (p->portNo & 0x0000ff00) >> 8;
            tmp_buf[3] = p->portNo & 0x000000ff;
            jvm_file_write(pushfd, tmp_buf, 4);
            jvm_file_write(pushfd, ",", 1);
            if (p->appid != NULL)
            {
                jvm_file_write(pushfd, p->appid, strlen(p->appid));
            }
            jvm_file_write(pushfd, ",", 1);
            if (p->nfc_url!= NULL)
            {
                jvm_file_write(pushfd, p->nfc_url, strlen(p->nfc_url));
            }
            jvm_file_write(pushfd, ",", 1);
            tmp_buf[0] = (p->push_game_type & 0xff000000) >> 24;
            tmp_buf[1] = (p->push_game_type & 0x00ff0000) >> 16;
            tmp_buf[2] = (p->push_game_type & 0x0000ff00) >> 8;
            tmp_buf[3] = p->push_game_type & 0x000000ff;
            jvm_file_write(pushfd, tmp_buf, 4);
            jvm_file_write(pushfd, "\n", 1);
        }
        /* Close the storage handle */
        jvm_file_close(pushfd);
    }

    jpush_timer_mutex_unlock();
    return (0);
}

/*****************************************************************************
 * FUNCTION
 *  jpush_push_restore_factory_setting
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
/* for fix the issue : after restoring factory_setting the midlet is gone but push is exist */
void jpush_push_restore_factory_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
    work_info_ptr = _jvm_get_builtin_file_info();
    work_sys_dir_path = _jvm_get_dir_path();    
    jpush_timer_mutex_lock();     
    g_jpush_pushlist_ptr = NULL;
    g_jpush_alarmlist_ptr = NULL;
    if(jpush_is_vm_redef_jpush_fs)
    {
        jvm_file_delete(jpush_general_persistent_push_fs_name);
        jvm_file_delete(jpush_alarm_push_fs_name);
        jvm_file_delete(jpush_general_push_fs_name);
    }        
    else    
    {
        jvm_file_delete(PPUSH_FILE);
        jvm_file_delete(ALARMPATH_NAME);
        jvm_file_delete(PUSHPATH_NAME);
    }        
    jpush_timer_mutex_unlock();     

    return ;
    
}

#ifdef SUPPORT_JSR_120

/*****************************************************************************
 * FUNCTION
 *  _jpush_process_port
 * DESCRIPTION
 *  Parse the port number from the connection field
 *  and use it for the connection appropriate open
 *  call. The file descriptor will be included in
 *  the connection registry until needed by the
 *  application level connection open request.
 * PARAMETERS
 *  buffer      [?]   
 *  port        [?]  
 * RETURNS
 *  void
 *****************************************************************************/
static void _jpush_process_port(char *buffer, int *port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p;
    int colon_found = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHPROCESSPORT); 

    p = buffer;
    *port = -1;
    for (; *p != '\0'; p++)
    {
        if (*p == ':')
        {
            colon_found++;
        }
        if (colon_found == 2)
        {
            p++;
            /* Parse the port number from the connection string */
            *port = atoi(p);
            if (strncmp(buffer, "sms://:", 7) == 0)
            {
                J2ME_sms_register(*port, PUSH_REGISTRY);
            }
            break;
        }
    }
    return;
}

#endif

#ifdef SUPPORT_JSR_205
/*****************************************************************************
 * FUNCTION
 *  _jpush_process_appid
 * DESCRIPTION
 *  Parse the application id from the connection field
 *  and use it for the connection appropriate open
 *  call. The file descriptor will be included in
 *  the connection registry until needed by the
 *  application level connection open request.
 * PARAMETERS
 *  buffer              [?]    
 *  applicationId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void _jpush_process_appid(char *buffer, char **applicationId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p;
    char **appid;
    kal_int32 colon_found = 0;
    kal_int32 res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHPROCESSPORT);

    p = buffer;
    appid = applicationId;

    for (; *p != '\0'; p++)
    {
        if (*p == ':')
        {
            colon_found++;
        }
        if (colon_found == 2)
        {
            p++;
            /* Parse the application id from the connection string */
            *appid = jvm_str_dup(p, strlen(p));

            if (*appid != NULL)
            {
                res = jpush_push_checkappid(*appid, PUSH_REGISTRY, -1);
                if (res == NON_REGISTERED)
                {
				    J2ME_mms_register(*appid, 0, PUSH_REGISTRY, -1);
                }
            }
            break;
        }
    }
    return;
}
#endif /* SUPPORT_JSR_205 */


#ifdef SUPPORT_JSR_257_PUSH
/*****************************************************************************
 * FUNCTION
 *  _jpush_process_nfc_se
 * DESCRIPTION
 *  Parse the aid from the connection field
 *  and use it for the connection appropriate open
 *  call. The file descriptor will be included in
 *  the connection registry until needed by the
 *  application level connection open request.
 * PARAMETERS
 *  buffer              [?]    
 *  AID       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void _jpush_process_nfc_se(char *buffer, char **AID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p;
    char **tmp_aid;
    kal_int32 colon_found = 0;
    kal_int32 res = 0;

    char *name = NULL;
    char *type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHPROCESSPORT);

    p = buffer;
    tmp_aid = AID;

    *tmp_aid = jvm_str_dup(p, strlen(p));

	// "secure-element:?aid=a00000006203010c0201"
	// type = "se"
	// name = "a00000006203010c0201"
    for (; *p != '\0'; p++)
    {
        if (*p == '=')
        {
            colon_found++;
        }
        if (colon_found == 1)
        {
            p++;
			name = jvm_str_dup(p, strlen(p));
			type = jvm_str_dup("secure-element", strlen("secure-element"));

            jcc_nfc_push_register(JCC_NFC_TARGET_SECURE_ELEMENT_ID);

            break;
        }
    }

	free_ctrl_buffer(type);
	free_ctrl_buffer(name);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  _jpush_process_nfc_tag
 * DESCRIPTION
 *  Parse the tag id from the connection field
 *  and use it for the connection appropriate open
 *  call. The file descriptor will be included in
 *  the connection registry until needed by the
 *  application level connection open request.
 * PARAMETERS
 *  buffer              [?]    
 *  TID       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void _jpush_process_nfc_tag(char *buffer, char **TID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p;
    char **tmp_tid;
    kal_int32 colon_found = 0;
    kal_int32 res = 0;

	char *tmp_p = NULL;
	char *type = NULL;
	int type0 = 0;
	int typef;
	int qmark_found = 0;
	int equal_found = 0;
	
	char *name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHPROCESSPORT);

    p = buffer;
    tmp_tid = TID;

    *tmp_tid = jvm_str_dup(p, strlen(p));

	// "ndef:rtd?name=urn:nfc:wkt:NDEF_TAG"
	// type = "rtd"
	// name = "urn:nfc:wkt:NDEF_TAG"
    for (; *p != '\0'; p++)
    {
        if (*p == ':')
        {
            colon_found++;
        }
        if (*p == '?')
        {
        	qmark_found++;
        }
        if (*p == '=')
        {
        	equal_found++;
        }
        
        
        if (colon_found == 1)
        {
            p++;

			tmp_p = jvm_str_dup(p, strlen(p));
            type0 = (int)p;
            
            colon_found = 0;
        }

        if(qmark_found==1)
        {
        	//p++;
        	typef = (int)p;

        	type = jvm_str_dup(tmp_p, typef-type0);

        	free_ctrl_buffer(tmp_p);
        	
        	tmp_p = jvm_str_dup(p, strlen(p));
        	
        	qmark_found = 0;
        }

        if(equal_found==1)
        {
        	p++;

        	name = jvm_str_dup(p, strlen(p));

        	free_ctrl_buffer(tmp_p);
        	        	
        	equal_found = 0;
        }
        
    }

	free_ctrl_buffer(type);
	free_ctrl_buffer(name);
		
    jcc_nfc_push_register(JCC_NFC_TARGET_NDEF_TAG_ID);

    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  jpush_push_getstoragename
 * DESCRIPTION
 *  Extract the storage name from the connection connection string
 * PARAMETERS
 *  connection      [?]      
 *  field           [IN]        
 *  length          [?]    
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *jpush_push_getstoragename(kal_char *connection, kal_int32 field, kal_int32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *storagefield;
    char *storagename = NULL;
    kal_int32 comma = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storagename = connection;
    *length = 0;

    if (field)
    {
        for (storagefield = connection; *storagefield; storagefield++)
        {
            if (*storagefield == ',')
            {
                comma++;
            }
            /* Push entry contains "connection, midletname, filter, storage" */
            /* Alarm entry contains "midletname, alarm, storage" */
            if (comma == field)
            {
                storagename = storagefield + 1;
                break;
            }
        }
    }

    /* Calculate length */
    storagefield = storagename;
    for (len = 0; *storagefield; storagefield++)
    {
        if (*storagefield == ',')
        {
            break;
        }
        len++;
    }

    *length = len;
    return storagename;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_push_set_unavailable
 * DESCRIPTION
 *  set all push registrations unavailable
 * PARAMETERS
 *  store       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_set_unavailable(char *store)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (strcmp(store, p->storagename) == 0)
        {
            if (p->available)
                p->available = KAL_FALSE;
        }
    }

}

#ifdef SUPPORT_JSR_205

/*****************************************************************************
 * FUNCTION
 *  push_process_recvd_mms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  application_id      [?]    
 * RETURNS
 *  void
 *****************************************************************************/
void *push_process_recvd_mms_ind(char *application_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;
    char *appid = application_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSH_PROCESS_RECVD_SMS_IND);

    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (p->appid != NULL)
            if (strcmp(p->appid, appid) == 0)
            {
                break;
            }
    }

    return p;
}

#endif

#ifdef SUPPORT_JSR_257_PUSH
/*****************************************************************************
 * FUNCTION
 *  push_process_recvd_nfc_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *push_process_recvd_nfc_ind(char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;
    char *nfc_url = url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSH_PROCESS_RECVD_NFC_IND);

    kal_take_mutex(g_jam_push_mutex);

    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (p->nfc_url != NULL)
            if (strcmp(p->nfc_url, nfc_url) == 0)
            {
                break;
            }
    }

    if (p == NULL)
    {
        sprintf(_kvmLogStr, "push_process_recvd_nfc_ind, p = NULL\n");
        Kprintf();
    }
    else
    {
        sprintf(_kvmLogStr, "push_process_recvd_nfc_ind, p = %x\n", (int)p);
        Kprintf();
    }

    kal_give_mutex(g_jam_push_mutex);

    return p;
}
#endif

#ifdef SUPPORT_JSR_205

/*****************************************************************************
 * FUNCTION
 *  jpush_push_checkappid
 * DESCRIPTION
 *  check if this appid is registered by mms push or not.
 *  if it is registered, tell it is registered by the same midlet or not.
 * PARAMETERS
 *  application_id      [?]    
 *  type                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_checkappid(char *application_id, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *appid = application_id;
    pushentry_struct *p;
    int result = NON_REGISTERED;
    kal_char *cur_suite;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_CHECK_PUSH_REGISTER_PORT);

    /* Find the entry to pass off the open file descriptor. */
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (p->appid != NULL)
        {
            if (strcmp(appid, p->appid) == 0)
            {

                cur_suite = jam_mvm_get_storage_name_by_vm_id(vm_id);
            #ifdef MIDP_PUSH_DEBUG
                if (cur_suite)
                {
                    sprintf(_kvmLogStr, "J2ME Debug: jpush_push_checkappid commandstate: %s", cur_suite);
                    Kprintf();
                }
                sprintf(_kvmLogStr, "J2ME Debug: jpush_push_checkappid check: %s", p->storagename);
                Kprintf();
            #endif /* MIDP_PUSH_DEBUG */ 

                if (cur_suite && (strcmp(p->storagename, cur_suite) == 0))
                {
                    /* The same midletsuite register the port. */
                    result = PUSH_REGISTERED;
                }
                else
                {
                    /* Already register by other midlet suite */
                    result = PUSH_CONFLICT_REGISTERED;
                }

                break;
            }
        }
    }
    return result;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  j2me_push_timeout_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_ptr       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_push_timeout_handler(void *param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *pe = param_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pe->next = g_jpush_pushlist_ptr;

#ifdef SUPPORT_JSR_257_PUSH
    if (strncmp(pe->connection, "secure-element:?", 16) == 0)
    {
        _jpush_process_nfc_se(pe->connection, &(pe->nfc_url));
    }

    else if (strncmp(pe->connection, "ndef:rtd?", 9) == 0
             || strncmp(pe->connection, "ndef:external_rtd?",18)==0
             || strncmp(pe->connection, "ndef:mime?",10)==0
             || strncmp(pe->connection, "ndef:uri?",9)==0   )
    {
        _jpush_process_nfc_tag(pe->connection, &(pe->nfc_url));
    }
    else
#endif
#ifdef SUPPORT_JSR_205
    if (strncmp(pe->connection, "mms://:", 7) == 0)
    {
        _jpush_process_appid(pe->connection, &(pe->appid));
    }
    else
#endif /* SUPPORT_JSR_205 */
    {
#ifdef SUPPORT_JSR_120    
        _jpush_process_port(pe->connection, &(pe->portNo));
#endif
    }

    g_jpush_pushlist_ptr = pe;
    g_push_length++;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_push_init_alarm_set
 * DESCRIPTION
 *  set the alarm registrations to event schedule
 * PARAMETERS
 *  entry_ptr       [?]    
 *  alarmtime       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
eventid jpush_push_init_alarm_set(pushentry_struct *entry_ptr, kal_uint32 alarmtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eventid event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_trace(TRACE_FUNC, JPUSH_ALARM_SET);       
    jpush_timer_mutex_lock();
    event_id = evshed_set_event(
                j2me_alarm_es_ptr,
                (kal_timer_func_ptr) j2me_push_timeout_handler,
                entry_ptr,
                alarmtime);
    jpush_timer_mutex_unlock();
    return event_id;
}


int jpush_push_read_entries_count(int *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JVM_TRACE_DEBUG("jpush_push_read_entries_count(), %d \n", __LINE__);
   

    if (number == NULL)
    {
        return -3;
    }

    for(p = g_jpush_pushlist_ptr, size = 0; p != NULL; p = p->next, size++)
  	{
  		/*	DO NOTHING
  		**/
  		//JVM_TRACE_DEBUG("jpush_push_read_entries_count(), %d, size=%d \n", __LINE__, size);
  	}

    *number = size;


    return 0;
}


int jpush_push_read_entry(int index, int *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //REPORT_INFO1(LC_JSR257, "contactless_push_read_entry(%x)", index);
    JVM_TRACE_DEBUG("jpush_push_read_entry(), %d, index=%d\n", __LINE__, index);

   	if (*handle == NULL)
   	{
    	return -3;
   	}

    *handle = 0;

    for(p = g_jpush_pushlist_ptr, i = 0; p != NULL; p = p->next, i++)
   	{
   		//JVM_TRACE_DEBUG("push_get(), %d, i=%d \n", __LINE__, i);
    	if(i == index)
      	{
	      	JVM_TRACE_DEBUG("jpush_push_read_entry(), %d, i=%d p=0x%08X \n", __LINE__, i, p);
        	*handle = (int) p;
            break;
      	}
   	}

  	return 0;
}


int jpush_push_read_connection_string(int *handle, char *buffer, int *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *pe = (pushentry_struct *)handle;
    pushentry_struct *p;
   	int i;
   	int len = 0;
   	int tmplen = 0;
    int index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JVM_TRACE_DEBUG("jpush_push_read_connection_string(), %d, handle=0x%08X\n", __LINE__, handle);

   	if((buffer == NULL) || (length == NULL))
   	{
    	return -3;
   	}

    for(p = g_jpush_pushlist_ptr, i = 0; p != NULL; p = p->next, i++)
   	{
    	if(p == pe)
      	{
   			JVM_TRACE_DEBUG("jpush_push_read_connection_string(), %d p=0x%08X pe=0x%08X \n", __LINE__, p, pe);
         	index = i;
            break;
      	}
   	}

   	if(index >= 0)
   	{
   		char *bufPtr = (char*)buffer;

  		tmplen = 0;
    	while(pe->connection[tmplen] != '\0')
    	{
    		bufPtr[len++] = (char)pe->connection[tmplen++];
    	}
      	bufPtr[len++] = ',';
		//
  		tmplen = 0;
    	while(pe->midlet[tmplen] != '\0')
    	{
    		bufPtr[len++] = pe->midlet[tmplen++];
    	}
      	bufPtr[len++] = ',';		
      	//
  		tmplen = 0;
    	while(pe->filter[tmplen] != '\0')
    	{
    		bufPtr[len++] = pe->filter[tmplen++];
    	}
      	bufPtr[len] = '\0';

      	*length = len;
   	}
   	else
   	{
      	*length = 0;
   	}

    JVM_TRACE_DEBUG("jpush_push_read_connection_string(), %d, *length=%d, handle=0x%08X, buffer='%s' \n", __LINE__, *length, handle, buffer);

   	return 0;
}


int jpush_push_trigger(int *handle, char *buffer, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *url = NULL;
    //contactless_push_entry_t *pe = (contactless_push_entry_t *)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(length==1)
    {
	    JVM_TRACE_DEBUG("jpush_push_trigger(), %d, fd=0x%08X buffer[0]=0x%08X length=%d \n", __LINE__, *handle, buffer[0], length);
    }
    else
    {
	    JVM_TRACE_DEBUG("jpush_push_trigger(), %d, fd=0x%08X buffer='%s' length=%d \n", __LINE__, *handle, buffer, length);
    }

    JVM_TRACE_DEBUG("jpush_push_trigger(), %d, HERE IGNORED IF CONFIRMED.. \n", __LINE__);

    return 0;
}


int jpush_push_read_trigger(int *handle, char *buffer, int *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *pe = (pushentry_struct *)handle;
    pushentry_struct *p;
    int i;
    int len = 0;
    int tmplen = 0;
    int index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JVM_TRACE_DEBUG("j2me_push_read_trigger(), %d, <NOT IMPLEMENTED>.. \n", __LINE__);

	JVM_TRACE_DEBUG("... UNDER CONSTRUCTION..., %d \n", __LINE__);
	JVM_TRACE_DEBUG("... HERE MUST KNOW WHICH CONTENT TO RETURN, %d \n", __LINE__);

	if((buffer == NULL) || (length == NULL))
   	{
    	return -3;
   	}

    for(p = g_jpush_pushlist_ptr, i = 0; p != NULL; p = p->next, i++)
   	{
    	if(p == pe)
      	{
   			JVM_TRACE_DEBUG("j2me_push_read_trigger(), %d p=0x%08X pe=0x%08X \n", __LINE__, p, pe);
         	index = i;
            break;
      	}
   	}

   	if(index >= 0)
   	{
   		char *bufPtr = (char*)buffer;

   		JVM_TRACE_DEBUG("... CONSIDER 'SE' CASE AND 'TAG' CASE \n", __LINE__);

  		tmplen = 0;
    	while(pe->connection[tmplen] != '\0')
    	{
    		bufPtr[len++] = pe->connection[tmplen++];
    	}
      	bufPtr[len] = '\0';
      	
      	*length = len;
   	}
   	else
   	{
    	*length = 0;
   	}

   	return 0;
}


#ifdef SUPPORT_JSR_120

#ifdef __SUPPORT_INFUSIO__

/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_eureka_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int result = 0;
    int smsq_fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    work_info_ptr = _jvm_get_builtin_file_info();
    work_sys_dir_path = _jvm_get_dir_path();
    /* Now read the pending sms in queue */
    if ((smsq_fd = jvm_file_open(EUREKA_SMSQUEUE_FILE, O_RDONLY)) != -1)
    {
        /* If need to do something */
    }
    else if ((smsq_fd = jvm_file_open(EUREKA_SMSQUEUE_FILE, O_CREAT | O_TRUNC)) == -1)
    {
        result = -1;
    }

    if (smsq_fd > 0)
    {
        jvm_file_close(smsq_fd);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_enqueue_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  len             [IN]        
 *  port            [IN]        
 *  buf             [?]         
 *  addr            [?]         
 *  addr_len        [IN]        
 *  timestamp       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32
jpush_eureka_enqueue_sms(
    int type,
    int len,
    int port,
    char *buf,
    kal_uint16 *addr,
    kal_uint8 addr_len,
    kal_uint8 *timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int smsq_fd;
    kal_uint8 tmp_buf[30];
    int result;
    j2me_custom_file_info_struct *old_info_ptr = work_info_ptr;
    kal_char *old_sys_dir = work_sys_dir_path;
    kal_char *old_dir = work_dir_path;
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    work_sys_dir_path = _jvm_get_dir_path();
    work_dir_path = work_sys_dir_path;
    work_info_ptr = _jvm_get_builtin_file_info();

    sprintf(_kvmLogStr, "jpush_eureka_enqueue_sms: game_type = %d, work_sys_dir_path = %s\n", type, work_sys_dir_path);
    Kprintf();

    /* Now read the pending sms in queue */
    if ((smsq_fd = jvm_file_open(EUREKA_SMSQUEUE_FILE, O_RDWR)) < 0)
    {
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return (-1);
    }

    jvm_file_lseek(smsq_fd, 0, SEEK_END);

    tmp_buf[i++] = (kal_uint8) ((type & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((type & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((type & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (type & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) ((len & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((len & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((len & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (len & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) ((port & 0xff000000) >> 24);
    tmp_buf[i++] = (kal_uint8) ((port & 0x00ff0000) >> 16);
    tmp_buf[i++] = (kal_uint8) ((port & 0x0000ff00) >> 8);
    tmp_buf[i++] = (kal_uint8) (port & 0x000000ff);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = (kal_uint8) (timestamp[0] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[1] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[2] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[3] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[4] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[5] & 0xFF);
    tmp_buf[i++] = (kal_uint8) (timestamp[6] & 0xFF);
    tmp_buf[i++] = ' ';
    tmp_buf[i++] = addr_len;
    tmp_buf[i++] = ' ';

    sprintf(_kvmLogStr, "buf: %s\n", tmp_buf);
    Kprintf();

    /* "type len port timestamp addr_len addr buf\n " */
    result = jvm_file_write(smsq_fd, tmp_buf, i);   /* 25 */
    ASSERT(result >= 0);

    if (addr_len)
    {
        result = jvm_file_write(smsq_fd, addr, addr_len);
        ASSERT(result >= 0);

        tmp_buf[0] = ' ';
        result = jvm_file_write(smsq_fd, tmp_buf, 1);
        ASSERT(result >= 0);
    }

    if (len)
    {
        result = jvm_file_write(smsq_fd, buf, len);
        ASSERT(result >= 0);
    }
    jvm_file_write(smsq_fd, "\n", 1);

    jvm_file_close(smsq_fd);

    work_sys_dir_path = old_sys_dir;
    work_dir_path = old_dir;
    work_info_ptr = old_info_ptr;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_dequeue_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [?]         
 *  len                 [?]         
 *  dequeue_port        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jpush_eureka_dequeue_sms(int *type, int *len, int dequeue_port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 addr_ucs2[6 + MAX_CC_ADDR_LEN + 7];
    kal_uint8 timestamp[7];
    int smsq_fd, new_smsq_fd;
    kal_uint8 *buf = NULL;
    kal_uint8 tmp_buf[128];
    kal_uint8 tmp_buf_short[2];
    kal_uint32 size, entry_size, rw_len;
    int result;
    j2me_custom_file_info_struct *old_info_ptr = work_info_ptr;
    kal_char *old_sys_dir = work_sys_dir_path;
    kal_char *old_dir = work_dir_path;
    int port;
    kal_bool found = KAL_FALSE;
    kal_uint8 addr_len = 0;
    int temp_type = 0;
    int temp_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize invalid value */
    *type = -1;
    *len = -1;

    work_sys_dir_path = _jvm_get_dir_path();
    work_dir_path = work_sys_dir_path;
    work_info_ptr = _jvm_get_builtin_file_info(GAMETYPE_INFUSIO_EUREKA);

    sprintf(
        _kvmLogStr,
        "jpush_eureka_dequeue_sms: game_type = %d, work_sys_dir_path = %s\n",
        (int)type,
        work_sys_dir_path);
    Kprintf();

    if ((new_smsq_fd = jvm_file_open(EUREKA_SMSQUEUETMP_FILE, O_CREAT | O_TRUNC)) < 0)
    {
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return buf;
    }
    if ((smsq_fd = jvm_file_open(EUREKA_SMSQUEUE_FILE, O_RDONLY)) < 0)
    {
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return buf;
    }

    jvm_file_lseek(smsq_fd, 0, SEEK_SET);
    jvm_file_lseek(new_smsq_fd, 0, SEEK_SET);

    if (jvm_file_getsize(smsq_fd, &size) < 0)
    {
        jvm_file_close(smsq_fd);
        jvm_file_close(new_smsq_fd);
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return buf;
    }

    while (size > 0)
    {
        sprintf(_kvmLogStr, "size = %d\n", size);
        Kprintf();
        result = jvm_file_read(smsq_fd, tmp_buf, 25);   /* "type len port timestamp addr_len " */
        //              *type = tmp_buf[0]<<24 | tmp_buf[1]<<16 | tmp_buf[2] << 8 | tmp_buf[3];
        //              *len = tmp_buf[5]<<24 | tmp_buf[6]<<16 | tmp_buf[7] << 8 | tmp_buf[8];
        //              port = tmp_buf[10]<<24 | tmp_buf[11]<<16 | tmp_buf[12] << 8 | tmp_buf[13];
        temp_type =
            ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3] &
                                                                                                      0xFF);
        temp_len =
            ((tmp_buf[5] & 0xFF) << 24) | ((tmp_buf[6] & 0xFF) << 16) | ((tmp_buf[7] & 0xFF) << 8) | (tmp_buf[8] &
                                                                                                      0xFF);
        port =
            ((tmp_buf[10] & 0xFF) << 24) | ((tmp_buf[11] & 0xFF) << 16) | ((tmp_buf[12] & 0xFF) << 8) | (tmp_buf[13] &
                                                                                                         0xFF);

        timestamp[0] = (tmp_buf[15] & 0xFF);
        timestamp[1] = (tmp_buf[16] & 0xFF);
        timestamp[2] = (tmp_buf[17] & 0xFF);
        timestamp[3] = (tmp_buf[18] & 0xFF);
        timestamp[4] = (tmp_buf[19] & 0xFF);
        timestamp[5] = (tmp_buf[20] & 0xFF);
        timestamp[6] = (tmp_buf[21] & 0xFF);

        addr_len = (tmp_buf[23] & 0xFF);

        ASSERT(result >= 0);

        memset(addr_ucs2, 0x00, sizeof(addr_ucs2));
        if (addr_len > 0)
        {
            result = jvm_file_read(smsq_fd, addr_ucs2, addr_len);
            ASSERT(result >= 0);

            /* For the space in the tail */
            addr_len++;

            /* For the space in the tail */
            result = jvm_file_read(smsq_fd, tmp_buf_short, 1);
            ASSERT(result >= 0);
        }

        if (port == dequeue_port && found == KAL_FALSE)
        {
            *type = temp_type;
            *len = temp_len;
            buf = (kal_uint8*) get_ctrl_buffer((*len) + 1);
            memset(buf, 0x00, ((*len) + 1));
            ASSERT(buf);
            result = jvm_file_read(smsq_fd, buf, *len);
            ASSERT(result >= 0);
            found = KAL_TRUE;
        }
        else
        {
            /* Copy the entry to tmp file */
            result = jvm_file_write(new_smsq_fd, tmp_buf, 25);
            ASSERT(result >= 0);

            if (addr_len > 0)
            {
                result = jvm_file_write(new_smsq_fd, addr_ucs2, (addr_len - 1));
                ASSERT(result >= 0);

                tmp_buf_short[0] = ' ';
                result = jvm_file_write(new_smsq_fd, tmp_buf_short, 1);
                ASSERT(result >= 0);
            }

            entry_size = temp_len;
            while (entry_size > 0)
            {
                rw_len = (entry_size > 128 ? 128 : entry_size);
                result = jvm_file_read(smsq_fd, tmp_buf, rw_len);
                ASSERT(result > 0);
                result = jvm_file_write(new_smsq_fd, tmp_buf, rw_len);
                ASSERT(result > 0);
                entry_size -= rw_len;
            }
            result = jvm_file_write(new_smsq_fd, "\n", 1);  /* "\n" */
            ASSERT(result >= 0);
        }

        result = jvm_file_read(smsq_fd, tmp_buf_short, 1);  /* "\n" */
        ASSERT(result >= 0);
        size -= (25 + addr_len + temp_len + 1);
    }

    jvm_file_close(smsq_fd);
    jvm_file_close(new_smsq_fd);

    /* Delete old queue file, and update new queue file */
    result = jvm_file_delete(EUREKA_SMSQUEUE_FILE);
    ASSERT(result == 0);
    result = jvm_file_rename(EUREKA_SMSQUEUETMP_FILE, EUREKA_SMSQUEUE_FILE);
    ASSERT(result == 0);

    work_sys_dir_path = old_sys_dir;
    work_dir_path = old_dir;
    work_info_ptr = old_info_ptr;

    return buf;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_check_smsqueue_without_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [?]         
 *  len             [?]         
 *  check_port      [IN]        
 *  addr            [?]         
 *  timestamp       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jpush_eureka_check_smsqueue_without_remove(
            int *type,
            int *len,
            int check_port,
            kal_uint16 *addr,
            kal_uint8 *timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int smsq_fd;
    kal_uint8 *buf = NULL;
    kal_uint8 tmp_buf[128];
    kal_uint32 size;
    int result;
    j2me_custom_file_info_struct *old_info_ptr = work_info_ptr;
    kal_char *old_sys_dir = work_sys_dir_path;
    kal_char *old_dir = work_dir_path;
    int port;
    kal_uint8 addr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize invalid value */
    *type = -1;
    *len = -1;
    work_sys_dir_path = _jvm_get_dir_path();
    work_dir_path = work_sys_dir_path;
    work_info_ptr = _jvm_get_builtin_file_info();

    sprintf(
        _kvmLogStr,
        "jpush_eureka_check_smsqueue_without_remove: game_type = %d, work_sys_dir_path = %s\n",
        *type,
        work_sys_dir_path);
    Kprintf();

    if ((smsq_fd = jvm_file_open(EUREKA_SMSQUEUE_FILE, O_RDONLY)) < 0)
    {
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return buf;
    }

    jvm_file_lseek(smsq_fd, 0, SEEK_SET);

    if (jvm_file_getsize(smsq_fd, &size) < 0)
    {
        jvm_file_close(smsq_fd);
        work_sys_dir_path = old_sys_dir;
        work_dir_path = old_dir;
        work_info_ptr = old_info_ptr;
        return buf;
    }

    while (size > 0)
    {
        result = jvm_file_read(smsq_fd, tmp_buf, 25);   /* "type len port timestamp addr_len " */
        //              *type = tmp_buf[0]<<24 | tmp_buf[1]<<16 | tmp_buf[2] << 8 | tmp_buf[3];
        //              *len = tmp_buf[5]<<24 | tmp_buf[6]<<16 | tmp_buf[7] << 8 | tmp_buf[8];
        //              port = tmp_buf[10]<<24 | tmp_buf[11]<<16 | tmp_buf[12] << 8 | tmp_buf[13];
        *type =
            ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3] &
                                                                                                      0xFF);
        *len =
            ((tmp_buf[5] & 0xFF) << 24) | ((tmp_buf[6] & 0xFF) << 16) | ((tmp_buf[7] & 0xFF) << 8) | (tmp_buf[8] &
                                                                                                      0xFF);
        port =
            ((tmp_buf[10] & 0xFF) << 24) | ((tmp_buf[11] & 0xFF) << 16) | ((tmp_buf[12] & 0xFF) << 8) | (tmp_buf[13] &
                                                                                                         0xFF);

        timestamp[0] = (tmp_buf[15] & 0xFF);
        timestamp[1] = (tmp_buf[16] & 0xFF);
        timestamp[2] = (tmp_buf[17] & 0xFF);
        timestamp[3] = (tmp_buf[18] & 0xFF);
        timestamp[4] = (tmp_buf[19] & 0xFF);
        timestamp[5] = (tmp_buf[20] & 0xFF);
        timestamp[6] = (tmp_buf[21] & 0xFF);

        addr_len = (tmp_buf[23] & 0xFF);

        ASSERT(result >= 0);

        memset(addr, 0x00, sizeof(addr));
        if (addr_len > 0)
        {
            result = jvm_file_read(smsq_fd, addr, addr_len);
            ASSERT(result >= 0);

            /* For the space in the tail */
            result = jvm_file_read(smsq_fd, tmp_buf, 1);
            ASSERT(result >= 0);

            addr_len++;
        }

        if (port == check_port)
        {
            buf = (kal_uint8*) get_ctrl_buffer((*len) + 1);
            memset(buf, 0x00, ((*len) + 1));
            ASSERT(buf);
            result = jvm_file_read(smsq_fd, buf, *len);
            ASSERT(result >= 0);
            break;
        }

        result = jvm_file_read(smsq_fd, tmp_buf, 1);    /* "\n" */
        ASSERT(result >= 0);
        size -= (25 + addr_len + *len + 1);
    }

    jvm_file_close(smsq_fd);

    work_sys_dir_path = old_sys_dir;
    work_dir_path = old_dir;
    work_info_ptr = old_info_ptr;

    return buf;
}

/*
 * The function will retrieve SMS and save to Eureka private persistent queues.
 * * Meanwhile, the function is executed in JVM context.
 */


/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_process_pending_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_ind     [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jpush_eureka_process_pending_sms(mmiapi_sms_ind_struct *sms_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 scts[7];
    long portnumber = sms_ind->port_number;
    int result;
    int len = 0;
    char *buf = NULL;
    int type;
    kal_uint16 *addr = NULL;
    kal_uint8 addr_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* JVM issue request, polling, and JDaemon received */
    type = _jwa_sms_check_incoming_msg(portnumber, KAL_FALSE);
    while ((result = jwa_sms_get_response_primitive()) != MSG_J2ME_SMS_CHECK_INCOMING_MSG_RSP);
    type = jwa_sms_get_primitive_result();

    if (type != MSG_J2ME_SMS_TEXT && type != MSG_J2ME_SMS_BINARY)
        return (-1);

    /* Synchronous API */
    addr = (kal_uint16*) _jwa_sms_get_incoming_msg_addr(portnumber, (int*)&addr_len);
    ASSERT(jwa_sms_get_ori_timestamp(portnumber, scts));

    switch (type)
    {
        case MSG_J2ME_SMS_TEXT:
            _jwa_sms_receive_text_msg_req(portnumber);
            while ((result = jwa_sms_get_response_primitive()) != MSG_J2ME_SMS_GET_INCOMING_MSG_RSP);
            result = jwa_sms_get_primitive_result();

            buf = (char*)jwa_sms_receive_text_msg_rsp(&len);
            jpush_eureka_enqueue_sms(type, len, portnumber, buf, addr, addr_len, scts);
            J2ME_sms_free_data();

            break;
        case MSG_J2ME_SMS_BINARY:
            _jwa_sms_receive_binary_msg_req(portnumber);
            while ((result = jwa_sms_get_response_primitive()) != MSG_J2ME_SMS_GET_INCOMING_MSG_RSP);
            result = jwa_sms_get_primitive_result();

            buf = jwa_sms_receive_binary_msg_rsp(&len);
            jpush_eureka_enqueue_sms(type, len, portnumber, buf, addr, addr_len, scts);
            J2ME_sms_free_data();

            break;
        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_eureka_check_smsqueue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 *  len         [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *jpush_eureka_check_smsqueue(int port, int *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *len = -1;
    return jpush_eureka_dequeue_sms(&type, len, port);
}

#endif /* __SUPPORT_INFUSIO__ */ 

#endif

#if PERSISTENT_PUSH


/*****************************************************************************
 * FUNCTION
 *  pushstorage
 * DESCRIPTION
 *  Extract the storage name from the connection connection string
 * PARAMETERS
 *  connection      [?]         [CHAR*]
 *  field           [IN]        
 *  length          [?]         [IN*]
 * RETURNS
 *  void
 *****************************************************************************/
kal_char *pushstorage(kal_char *connection, kal_int32 field, kal_int32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *storagefield;
    char *storagename = NULL;
    kal_int32 comma = 0, len = 0, offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storagename = connection;
    *length = 0;

    if (field)
    {
        /* for (storagefield = connection; *storagefield; storagefield++) { */
        storagefield = connection;
        while (pushlist_len > offset)
        {
            if (*storagefield == ',')
                comma++;
            /* Push entry contains "connection, midletname, filter, storage" */
            /* Alarm entry contains "midletname, alarm, storage" */
            if (comma == field)
            {
                storagename = storagefield + 1;
                break;
            }
            offset++;
            storagefield++;
        }
    }

    /* Calculate length */
    storagefield = storagename;
    offset = pushlist_len - offset - 1;
    while (offset > len)
    {
        if (*storagefield == ',')
            break;
        storagefield++;
        len++;
    }
    //      for (len=0; *storagefield; storagefield++) {
    //              if (*storagefield == ',') break;
    //              len++;
    //      }

    *length = len;
    return storagename;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_push_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_free()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *pushp, *pushtmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean up the list */
    for (pushp = g_jpush_pushlist_ptr; pushp != NULL; pushp = pushtmp)
    {
        pushtmp = pushp->next;

        free_ctrl_buffer(pushp->connection);
        free_ctrl_buffer(pushp->midlet);
        free_ctrl_buffer(pushp->filter);
        free_ctrl_buffer(pushp->storagename);
        free_ctrl_buffer(pushp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpush_push_parse
 * DESCRIPTION
 *  Parse the persistent push registry from disk into the
 *  in memory cache representation.
 * PARAMETERS
 *  pushfd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_parse(kal_int32 pushfd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buffer[MAX_PUSH_LINE + 1];
    char tmp_buf[16];
    kal_bool eof = KAL_FALSE;
    int i;

    pushentry_struct *pe;
    kal_char *tmp_str;
    kal_int32 tmp_len = 0;
    kal_int32 counter = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PARSEPUSHLIST);

    kal_take_mutex(g_jam_push_mutex);
    while (eof == KAL_FALSE)
    {
        /* Read a line at a time */
        for (i = 0; i < MAX_PUSH_LINE; i++)
        {
            tmp_len = jvm_file_read(pushfd, &buffer[i], 1);

            /* EOF */
            if (tmp_len <= 0)
            {
                eof = KAL_TRUE;
                break;
            }

            /* EOL */
            if ((buffer[i] == '\n') || (i == MAX_PUSH_LINE))
            {
                buffer[i] = 0;
                break;
            }
            /* Ignore carriage returns */
            if (buffer[i] == '\r')
            {
                i--;
            }
        }

        pushlist_len = i;

        /* Skip comment lines which begin  with '#' */
        if (eof == KAL_FALSE && buffer[0] != '#')
        {
            if ((pe = (pushentry_struct*) get_ctrl_buffer(sizeof(pushentry_struct))) != NULL)
            {
                //pe->next = g_jpush_pushlist_ptr;

                tmp_str = pushstorage(buffer, 0, &tmp_len);
                pe->connection = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 1, &tmp_len);
                pe->midlet = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 2, &tmp_len);
                pe->filter = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 3, &tmp_len);
                pe->storagename = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 4, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
				pe->midletid =
                    ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3]
                                                                                                              & 0xFF);

                tmp_str = pushstorage(buffer, 5, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
                pe->portNo =
                    ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3]
                                                                                                              & 0xFF);

                tmp_str = pushstorage(buffer, 6, &tmp_len);
                pe->appid = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 7, &tmp_len);
                pe->nfc_url= jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 8, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
                /* pe->push_game_type = (tmp_buf[0]<<24) | (tmp_buf[1]<<16) | (tmp_buf[2]<<8) | tmp_buf[3]; */
                pe->push_game_type =
                    ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3]
                                                                                                              & 0xFF);

                //sprintf(_kvmLogStr, "tmp_len = %d, pe->push_game_type = %d\n", tmp_len, pe->push_game_type);
                //Kprintf();

                if ((pe->connection == NULL) || (pe->midlet == NULL) ||
                    (pe->filter == NULL) || (pe->storagename == NULL))
                {
                    if (pe->connection)
                    {
                        free_ctrl_buffer(pe->connection);
                    }
                    if (pe->midlet)
                    {
                        free_ctrl_buffer(pe->midlet);
                    }
                    if (pe->filter)
                    {
                        free_ctrl_buffer(pe->filter);
                    }
                    if (pe->storagename)
                    {
                        free_ctrl_buffer(pe->storagename);
                    }
                    if (pe->appid)
                    {
                        free_ctrl_buffer(pe->appid);
                    }
                    if (pe->nfc_url)
                    {
                        free_ctrl_buffer(pe->nfc_url);
                    }
                    free_ctrl_buffer(pe);

                    kal_give_mutex(g_jam_push_mutex);
                    return (-2);
                }
                else
                {
                    /* register push connection */
                    pe->portNo = -1;
                    pe->available = KAL_FALSE;
                    pe->appid = NULL;
                    pe->nfc_url = NULL;
                    
                    jpush_push_init_alarm_set(pe, 2000 + counter * 500);
                    counter++;
                }
            }
            else
            {
                jpush_push_free();
                kal_give_mutex(g_jam_push_mutex);
                return -2;
            }
        }
    }

    kal_give_mutex(g_jam_push_mutex);
    return 0;
}
#endif /* PERSISTENT_PUSH */ 


/*****************************************************************************
 * FUNCTION
 *  jpush_push_deletesuite
 * DESCRIPTION
 *  Clear all the push entry
 * PARAMETERS
 *  store       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *pushp;
    pushentry_struct *pushnext;

    alarmentry_struct *alarmp;
    alarmentry_struct *alarmnext;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find all of the entries to remove */
    kal_take_mutex(g_jam_push_mutex);
    for (pushp = g_jpush_pushlist_ptr; pushp != NULL; pushp = pushnext)
    {
        pushnext = pushp->next;

        /* Unregister the sms port */
        if (pushp->portNo != -1)
        {
   #ifdef SUPPORT_JSR_120     
            J2ME_sms_unregister_by_push(pushp->portNo, PUSH_REGISTRY);
   #endif
        }
    #ifdef SUPPORT_JSR_205
        else if (pushp->appid != NULL)
        {
            J2ME_mms_register_by_push(pushp->appid, 1, PUSH_REGISTRY);
            //J2ME_mms_register(pushp->appid, 1, PUSH_REGISTRY);      /* 1 for unregister */
        }
    #endif /* SUPPORT_JSR_205 */
    #ifdef SUPPORT_JSR_257_PUSH
        else if (pushp->nfc_url != NULL && strncmp(pushp->nfc_url, "secure-element:?", 16) == 0)
        {
            jcc_nfc_push_unregister(JCC_NFC_TARGET_SECURE_ELEMENT_ID);
        }
        else if (pushp->nfc_url != NULL
                 && (strncmp(pushp->nfc_url, "ndef:rtd?", 9) == 0
			     || strncmp(pushp->nfc_url, "ndef:external_rtd?",18)==0
			     || strncmp(pushp->nfc_url, "ndef:mime?",10)==0
			     || strncmp(pushp->nfc_url, "ndef:uri?",9)==0))
        {
                jcc_nfc_push_unregister(JCC_NFC_TARGET_NDEF_TAG_ID);
        }
    #endif

        free_ctrl_buffer(pushp->connection);
        free_ctrl_buffer(pushp->midlet);
        free_ctrl_buffer(pushp->filter);
        free_ctrl_buffer(pushp->storagename);
        if (pushp->appid != NULL)
        {
            free_ctrl_buffer(pushp->appid);
        }
        if (pushp->nfc_url != NULL)
        {
            free_ctrl_buffer(pushp->nfc_url);
        }
        free_ctrl_buffer(pushp);   
    }

    for (i = 0; i < MAX_PUSH_REGISTRY; i++)
    {
        /* remove the push indication memorized by MMI */
        if (g_mmi_java_push_cntx.push_entry_used[i])
        {
            g_mmi_java_push_cntx.push_entry_used[i] = KAL_FALSE;
            g_mmi_java_push_cntx.push_entry[i].mids_storage_name = NULL;
        }
    }

    g_jpush_pushlist_ptr = NULL;
    g_push_length = 0;
    kal_give_mutex(g_jam_push_mutex);

    /* Find all of the alarm entries to remove */
    for (alarmp = g_jpush_alarmlist_ptr; alarmp != NULL; alarmp = alarmnext)
    {
        alarmnext = alarmp->next;

        jpush_alarm_cancel(&alarmp->event_id);
    
        free_ctrl_buffer(alarmp->midlet);
        alarmp->midlet = NULL;
        free_ctrl_buffer(alarmp->storagename);
        alarmp->storagename = NULL;
        free_ctrl_buffer(alarmp);
    }
    g_jpush_alarmlist_ptr = NULL;
    g_timealarm_count = 0;

    ppush_counter = 0;
    before_persistent_push_finished = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_add_persistent_push
 * DESCRIPTION
 *  Add a push entry to persistent push file. The system will check the peristent push file and if
 *  there is any un-executed push, the system will launch the pushed MIDlet suite again.
 *  
 *  File format:
 *  Push entry size (2 bytes) | game type (1 byte) | alarm or sms push (1 byte) | port number (4 bytes)
 *  MIDlet name (Ascii string with 0-terminator) | MIDlet storage name (Ascii string with 0-terminator) |
 *  Application id for MMS (Ascii string with 0-terminator)
 * PARAMETERS
 *  game_type           [IN]        Game type of the push
 *  port_no             [IN]        
 *  alarmpush_type      [IN]        Time alarm push or normal push
 *  mid_name            [?]         MIDlet name of push target.
 *  mid_storagename     [?]         MIDlet storage name of push target.
 *  filter              [?]         
 *  connection          [?]         
 *  app_id              [?]         
 *  nfc_url              [?]   
 * RETURNS
 *  0 if success
 *  -1 if fail
 *****************************************************************************/
kal_int32 jpush_add_persistent_push(
            kal_uint32 port_no,
            kal_uint32 alarmpush_type,
            kal_char *mid_name,
            kal_int32 mid_id,
            kal_char *mid_storagename,
            kal_char *filter,
            kal_char *connection,
            kal_char *app_id,
            kal_char* nfc_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int handle;
    char temp[4];
    char temp2[1];
    kal_int32 push_entry_size;
    kal_uint32 written_len = 0;
    kal_int32 nfcurl_len = (nfc_url == NULL ? 0 : strlen(nfc_url));
    kal_int32 appid_len = (app_id == NULL ? 0 : strlen(app_id));
    kal_int32 conection_len = (connection == NULL ? 0 : strlen(connection));
    kal_int32 filter_len = (filter == NULL ? 0 : strlen(filter));
    kal_char *filter_buffer = (filter == NULL ? temp2 : filter);
    kal_char *appid_buffer = (app_id == NULL ? temp2 : app_id);
    kal_char *nfcurl_buffer = (nfc_url == NULL ? temp2 : nfc_url);
    kal_char *connection_buffer = (connection == NULL ? temp2 : connection);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_PRINT(MOD_JAM,TRACE_FUNC,"Add Ppush: %s",mid_name);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return -1;
    }
#endif
    jpush_timer_mutex_lock();
    if (!before_persistent_push_finished)
    {
        jpush_timer_mutex_unlock();
        return 0;
    }
    if (ppush_counter > MAX_PUSH_REGISTRY - 1)
    {
        jpush_timer_mutex_unlock();
        return -1;
    }
    temp2[0] = 0;
    if(jpush_is_vm_redef_jpush_fs)
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, jpush_general_persistent_push_fs_name);    
    else       
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, PPUSH_FILE);
    handle = FS_Open(WCHARFilename_push, FS_CREATE | FS_READ_WRITE | FS_OPEN_SHARED | FS_COMMITTED);
    if (handle < 0)
    {
        jpush_timer_mutex_unlock();
        return -1;
    }

    if (FS_Seek(handle, 0, SEEK_END) < 0)
    {
        goto error_close;
    }

    push_entry_size = 18 + strlen(mid_name) + strlen(mid_storagename) + appid_len + filter_len + conection_len + nfcurl_len;
    temp[0] = (push_entry_size << 24) >> 24;
    temp[1] = (push_entry_size << 16) >> 24;

    FS_Write(handle, temp, 2, &written_len);
    if (written_len != 2)
    {
        goto error_close;
    }

    temp[0] = 0;
    FS_Write(handle, temp, 1, &written_len);
    if (written_len != 1)
    {
        goto error_close;
    }

    temp[0] = alarmpush_type;
    FS_Write(handle, temp, 1, &written_len);
    if (written_len != 1)
    {
        goto error_close;
    }

    temp[0] = (mid_id << 24) >> 24;
    temp[1] = (mid_id << 16) >> 24;
    temp[2] = (mid_id << 8) >> 24;
    temp[3] = (mid_id) >> 24;

    FS_Write(handle, temp, 4, &written_len);
    if (written_len != 4)
    {
        goto error_close;
    }

    temp[0] = (port_no << 24) >> 24;
    temp[1] = (port_no << 16) >> 24;
    temp[2] = (port_no << 8) >> 24;
    temp[3] = (port_no) >> 24;

    FS_Write(handle, temp, 4, &written_len);
    if (written_len != 4)
    {
        goto error_close;
    }

    FS_Write(handle, mid_name, strlen(mid_name) + 1, &written_len);

    if (written_len != strlen(mid_name) + 1)
    {
        goto error_close;
    }

    FS_Write(handle, mid_storagename, strlen(mid_storagename) + 1, &written_len);

    if (written_len != strlen(mid_storagename) + 1)
    {
        goto error_close;
    }

    FS_Write(handle, filter_buffer, filter_len + 1, &written_len);

    if (written_len != filter_len + 1)
    {
        goto error_close;
    }

    FS_Write(handle, connection_buffer, conection_len + 1, &written_len);

    if (written_len != conection_len + 1)
    {
        goto error_close;
    }

    FS_Write(handle, appid_buffer, appid_len + 1, &written_len);

    if (written_len != appid_len + 1)
    {
        goto error_close;
    }

    FS_Write(handle, nfcurl_buffer, nfcurl_len + 1, &written_len);

    if (written_len != nfcurl_len + 1)
    {
        goto error_close;
    }

    FS_Close(handle);
    ppush_counter++;
    jpush_timer_mutex_unlock();
    return 0;
  error_close:
    FS_Close(handle);
    jpush_timer_mutex_unlock();
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_search_and_delete_persistent_push
 * DESCRIPTION
 *  Remove push entry from persistent push file.
 *  File format: refer to jpush_add_persistent_push
 * PARAMETERS
 *  game_type               [IN]        Game type of the push
 *  port_no                 [IN]        
 *  alarmpush_type          [IN]        Time alarm push or normal push
 *  mid_name                [?]         MIDlet name of push target.
 *  mid_storagename         [?]         MIDlet storage name of push target.
 *  filter                  [?]         
 *  connection              [?]         
 *  app_no                  [?]         
 *  nfc_url                  [?] 
 *  delete_found_record     [IN]        
 * RETURNS
 *  0 if found
 *  -1 if not found
 *****************************************************************************/
kal_int32 jpush_search_and_delete_persistent_push(
            kal_int32 port_no,
            kal_uint32 alarmpush_type,
            kal_char *mid_name,
            kal_int32 mid_id,
            kal_char *mid_storagename,
            kal_char *filter,
            kal_char *connection,
            kal_char *app_no,
            kal_char *nfc_url,
            kal_bool delete_found_record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int handle;
    char temp[4];
    char temp2[1];
    kal_int32 scan_entry_base = 0;
    kal_int32 scan_pos = 0;
    kal_int32 entry_size = 0;
    kal_int32 file_size = 0;
    kal_int32 temp_port_no = 0;
	kal_int32 temp_mid_id = 0;
    kal_uint32 temp_len = 0;
    kal_int32 nfcurl_len = (nfc_url == NULL ? 0 : strlen(nfc_url));
    kal_int32 appid_len = (app_no == NULL ? 0 : strlen(app_no));
    kal_int32 connection_len = (connection == NULL ? 0 : strlen(connection));
    kal_int32 filter_len = (filter == NULL ? 0 : strlen(filter));
    kal_char *filter_buffer = (filter == NULL ? temp2 : filter);
    kal_char *appid_buffer = (app_no == NULL ? temp2 : app_no);
    kal_char *nfcurl_buffer = (nfc_url == NULL ? temp2 : nfc_url);
    kal_char *connection_buffer = (connection == NULL ? temp2 : connection);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp2[0] = 0;
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return -1;
    }
#endif
    jpush_timer_mutex_lock();
    if(jpush_is_vm_redef_jpush_fs)
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, jpush_general_persistent_push_fs_name);    
    else       
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, PPUSH_FILE);
    handle = FS_Open(WCHARFilename_push, FS_CREATE | FS_READ_WRITE | FS_OPEN_SHARED);
    if (handle < 0)
    {
        jpush_timer_mutex_unlock();
        return -1;
    }
    /* if the file size is zero, or can not get the file size, we couldn't remove any push entry */
    if ((file_size = FS_Seek(handle, 0, SEEK_END)) <= 0)
    {
        goto error_close;
    }

    while (scan_entry_base + entry_size < file_size)
    {
        scan_entry_base += entry_size;
        if (FS_Seek(handle, scan_entry_base, SEEK_SET) < 0)
        {
            goto error_close;
        }
        FS_Read(handle, temp, 2, &temp_len);
        if (temp_len != 2)
        {
            goto error_close;
        }
        entry_size = temp[0] + (temp[1] << 8);

        FS_Read(handle, temp, 1, &temp_len);
        if (temp_len != 1)
        {
            goto error_close;
        }
        if (temp[0] != 0)
        {
            continue;
        }

        FS_Read(handle, temp, 1, &temp_len);
        if (temp_len != 1)
        {
            goto error_close;
        }
        if (temp[0] != alarmpush_type)
        {
            continue;
        }
	FS_Read(handle, temp, 4, &temp_len);
        if (temp_len != 4)
        {
            goto error_close;
        }
        temp_mid_id = temp[0] + (temp[1] << 8) + (temp[2] << 16) + (temp[3] << 24);

        if (temp_mid_id != mid_id)
        {
            continue;
        }

        FS_Read(handle, temp, 4, &temp_len);

        if (temp_len != 4)
        {
            goto error_close;
        }
        temp_port_no = temp[0] + (temp[1] << 8) + (temp[2] << 16) + (temp[3] << 24);

        if (temp_port_no != port_no)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (mid_name[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;

        if (scan_pos != strlen(mid_name))
        {
            continue;
        }
        if (mid_name[scan_pos] != 0)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (mid_storagename[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;

        if (scan_pos != strlen(mid_storagename))
        {
            continue;
        }
        if (mid_storagename[scan_pos] != 0)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (filter_buffer[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;

        if (scan_pos != filter_len)
        {
            continue;
        }
        if (filter_buffer[scan_pos] != 0)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (connection_buffer[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;

        if (scan_pos != connection_len)
        {
            continue;
        }
        if (connection_buffer[scan_pos] != 0)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (appid_buffer[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;
        if (scan_pos != appid_len)
        {
            continue;
        }
        if (appid_buffer[scan_pos] != 0)
        {
            continue;
        }

        scan_pos = 0;
        do
        {
            FS_Read(handle, temp, 1, &temp_len);
            if (temp_len != 1)
            {
                goto error_close;
            }
            if (nfcurl_buffer[scan_pos] != temp[0])
            {
                break;
            }
            scan_pos++;
        } while (temp[0] != 0);
        scan_pos--;
        if (nfcurl_buffer[scan_pos] != 0)
        {
            continue;
        }
		
        /* found the push entry */
        if (scan_pos == nfcurl_len)
        {
            kal_int32 copy_size;
            kal_char *temp_buffer;

            if (!delete_found_record)
            {
                jpush_timer_mutex_unlock();
                return 0;
            }
            copy_size = file_size - entry_size - scan_entry_base;
			if(copy_size==0)
						continue;

            temp_buffer = (kal_char*) get_ctrl_buffer(copy_size);
            if (copy_size > 0)
            {
                FS_Read(handle, temp_buffer, copy_size, &temp_len);
                if (temp_len != copy_size)
                {
                    free_ctrl_buffer(temp_buffer);
                    goto error_close;
                }
            }
            if (FS_Seek(handle, scan_entry_base, SEEK_SET) < 0)
            {
                free_ctrl_buffer(temp_buffer);
                goto error_close;
            }
            if (copy_size > 0)
            {
                FS_Write(handle, temp_buffer, copy_size, &temp_len);
                if (temp_len != copy_size)
                {
                    free_ctrl_buffer(temp_buffer);
                    goto error_close;
                }
            }
            free_ctrl_buffer(temp_buffer);
            if (FS_Truncate(handle) < 0)
            {
                goto error_close;
            }

            FS_Close(handle);
            ppush_counter--;
            jpush_timer_mutex_unlock();
            return 0;
        }

    }

  error_close:
    FS_Close(handle);
    jpush_timer_mutex_unlock();   
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_ppush_retrieval_init
 * DESCRIPTION
 *  Initialize to retrieve persistent push entry from file system.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 if success
 *  -1 if fail
 *****************************************************************************/
static kal_char *ppush_buffer = NULL;
static kal_int32 ppush_handle = -1;
kal_int32 jpush_ppush_retrieval_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ppush_buffer != NULL)
    {
        jam_listmem_free(ppush_buffer);
        ppush_buffer = NULL;
    }
    if(jpush_is_vm_redef_jpush_fs)
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, jpush_general_persistent_push_fs_name);    
    else       
        kal_wsprintf(WCHARFilename_push, "%s\\%s", j2me_sys_dir_path, PPUSH_FILE);
    ppush_handle = FS_Open(WCHARFilename_push, FS_READ_WRITE | FS_OPEN_SHARED);
    if (ppush_handle < 0)
    {
        return -1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_ppush_retrieval_next
 * DESCRIPTION
 *  Get next persistent push entry.
 * PARAMETERS
 *  game_type           [IN]        Game type of the push
 *  port_no             [?]         
 *  alarmpush_type      [?]         Time alarm push or normal push
 *  mid_name            [IN]        MIDlet name of push target.
 *  mid_storagename     [IN]        MIDlet storage name of push target.
 *  filter              [IN]        
 *  connection          [IN]        
 *  app_no              [IN]        
 *  nfc_url              [IN]   
 * RETURNS
 *  0 if success
 *  -1 if fail
 *****************************************************************************/
kal_int32 jpush_ppush_retrieval_next(
            game_type_enum *game_type,
            kal_uint32 *port_no,
            kal_uint32 *alarmpush_type,
            kal_char **mid_name,
            kal_int32 *mid_id,
            kal_char **mid_storagename,
            kal_char **filter,
            kal_char **connection,
            kal_char **app_no,
            kal_char **nfc_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char temp[4];
    kal_uint32 temp_len;
    kal_int32 entry_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ppush_handle < 0)
    {
        return -1;
    }
    if (ppush_buffer != NULL)
    {
        jam_listmem_free(ppush_buffer);
        ppush_buffer = NULL;
    }
    FS_Read(ppush_handle, temp, 2, &temp_len);
    if (temp_len != 2)
    {
        goto error_close;
    }
    entry_size = temp[0] + (temp[1] << 8);

    FS_Read(ppush_handle, temp, 1, &temp_len);
    if (temp_len != 1)
    {
        goto error_close;
    }
    *game_type = temp[0];

    FS_Read(ppush_handle, temp, 1, &temp_len);
    if (temp_len != 1)
    {
        goto error_close;
    }
    *alarmpush_type = temp[0];

    FS_Read(ppush_handle, temp, 4, &temp_len);
    if (temp_len != 4)
    {
        goto error_close;
    }
    *mid_id = temp[0] + (temp[1] << 8) + (temp[1] << 16) + (temp[1] << 24);

    FS_Read(ppush_handle, temp, 4, &temp_len);
    if (temp_len != 4)
    {
        goto error_close;
    }
    *port_no = temp[0] + (temp[1] << 8) + (temp[1] << 16) + (temp[1] << 24);

    ppush_buffer = (kal_char*) jam_listmem_malloc(entry_size - 8);
    ASSERT(ppush_buffer != NULL);

    FS_Read(ppush_handle, ppush_buffer, entry_size - 12, &temp_len);
    if (temp_len != entry_size - 12)
    {
        goto error_close;
    }
    *mid_name = ppush_buffer;
    *mid_storagename = ppush_buffer + strlen(ppush_buffer) + 1;
    *filter = **mid_storagename == 0 ? *mid_storagename + 1 : *mid_storagename + strlen(*mid_storagename) + 1;
    *connection = **filter == 0 ? *filter + 1 : *filter + strlen(*filter) + 1;
    *app_no = **connection == 0 ? *connection + 1 : *connection + strlen(*connection) + 1;
    *nfc_url = **app_no == 0 ? *app_no + 1 : *app_no + strlen(*app_no) + 1;
    return 0;
  error_close:
    jpush_ppush_retrieval_final();
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_ppush_retrieval_final
 * DESCRIPTION
 *  Clean resource used by persistent push retrieval.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 if success
 *  -1 if fail
 *****************************************************************************/
kal_int32 jpush_ppush_retrieval_final(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ppush_buffer != NULL)
    {
        jam_listmem_free(ppush_buffer);
        ppush_buffer = NULL;
    }
    if (ppush_handle >= 0)
    {
        FS_Seek(ppush_handle, 0, SEEK_SET);
        FS_Truncate(ppush_handle);
        FS_Close(ppush_handle);
        ppush_handle = -1;
        return 0;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpush_init_persistent_push_entries
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jpush_init_persistent_push_entries(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    game_type_enum game_type;
    kal_uint32 port_no;
    kal_uint32 alarmpush_type;
    kal_char *mid_name;
    kal_int32 mid_id;
    kal_char *mid_storagename;
    kal_char *filter;
    kal_char *connection;
    kal_char *app_id;
    kal_char *nfc_url;
    alarmentry_struct *alarm_pe = NULL;
    pushentry_struct *push_pe = NULL;
    kal_int32 counter = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return -1;
    }
#endif
    if (jpush_ppush_retrieval_init() < 0)
    {
        before_persistent_push_finished = KAL_TRUE;
        return -1;
    }
    while (jpush_ppush_retrieval_next(
            &game_type,
            &port_no,
            &alarmpush_type,
            &mid_name,
            &mid_id,
            &mid_storagename,
            &filter,
            &connection,
            &app_id,
            &nfc_url) >= 0)
    {
        work_sys_dir_path = _jvm_get_dir_path();

        if (jam_call_back_functions.jam_get_mids_id_from_push_name(mid_storagename) < 0)
        {
            continue;
        }

        //ppush_counter++;
        if (alarmpush_type == PUSHTYPE_ALARM_PUSH)
        {
            alarmentry_struct *alpe;

            alpe = (alarmentry_struct*) get_ctrl_buffer(sizeof(alarmentry_struct));

            alarm_pe = alpe;
            alpe->alarm_game_type = game_type;
            alpe->executed = KAL_FALSE;
            alpe->event_id = NULL;
            alpe->midlet = jvm_str_dup(mid_name, strlen(mid_name));
            alpe->storagename = jvm_str_dup(mid_storagename, strlen(mid_storagename));
            alpe->midletid = mid_id;
            alpe->next = NULL;
            if (g_jpush_alarmlist_ptr == NULL)
            {
                g_jpush_alarmlist_ptr = alpe;
            }
            else
            {
                alarm_pe->next = g_jpush_alarmlist_ptr;
                g_jpush_alarmlist_ptr = alarm_pe;
            }
            alpe->event_id = jpush_alarm_set(alpe, 2000 + counter * 500);
            counter++;
            //jam_timealarm_push_ind_handler(game_type, alarmpush_type, alpe, alpe->midlet, alpe->storagename);
        }
        else
        {
            pushentry_struct *pe;
            pushentry_struct *p;

            for (p = g_jpush_pushlist_ptr; p != NULL; p = p->next)
            {
                if (strncmp(connection, p->connection, strlen(connection)) == 0)
                {
                    break;
                }
                push_pe = p;
            }
            if (p == NULL)
            {
                pe = (pushentry_struct*) get_ctrl_buffer(sizeof(pushentry_struct));
                if (g_jpush_pushlist_ptr == NULL)
                {
                    g_jpush_pushlist_ptr = pe;
                }
                else
                {
                    push_pe->next = pe;
                }
                push_pe = pe;
                pe->storagename = jvm_str_dup(mid_storagename, strlen(mid_storagename));
                pe->midlet = jvm_str_dup(mid_name, strlen(mid_name));
                pe->appid = app_id[0] == 0 ? NULL : jvm_str_dup(app_id, strlen(app_id));
                pe->nfc_url= nfc_url[0] == 0 ? NULL : jvm_str_dup(nfc_url, strlen(nfc_url));
                pe->filter = filter[0] == 0 ? NULL : jvm_str_dup(filter, strlen(filter));
                pe->connection = connection[0] == 0 ? NULL : jvm_str_dup(connection, strlen(connection));
                pe->push_game_type = game_type;
                pe->midletid = mid_id;
                pe->next = NULL;
            }
            else
            {
                pe = p;
            }
            jam_timealarm_push_ind_handler(alarmpush_type, pe, pe->midlet, pe->midletid, pe->storagename, KAL_FALSE);
        }

    }
    before_persistent_push_finished = KAL_TRUE;
    jpush_ppush_retrieval_final();
    work_sys_dir_path = _jvm_get_dir_path();
    return 0;
}

#endif


#ifdef SUPPORT_JSR_120 

/*****************************************************************************
 * FUNCTION
 *  j2me_check_push_register_port
 * DESCRIPTION
 *  check if this port is registered by sms push or not.
 *  if it is registered, tell it is registered by the same midlet or not.
 * PARAMETERS
 *  port        [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int j2me_check_push_register_port(int port, int type, int vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    kal_char *cur_suite;
    kal_int32 result = NON_REGISTERED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_CHECK_PUSH_REGISTER_PORT);
#ifdef __SUPPORT_JAVA_PUSH__
    /* Find the entry to pass off the open file descriptor. */
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (port == p->portNo)
        {
            cur_suite = jam_mvm_get_storage_name_by_vm_id(vm_id);

        #ifdef MIDP_PUSH_DEBUG
            if (cur_suite)
            {
                sprintf(_kvmLogStr, "J2ME Debug: j2me_check_push_register_port commandstate: %s", cur_suite);
                Kprintf();
            }
            sprintf(_kvmLogStr, "J2ME Debug: j2me_check_push_register_port check: %s", p->storagename);
            Kprintf();
        #endif /* MIDP_PUSH_DEBUG */ 

            if (cur_suite && (strcmp(p->storagename, cur_suite) == 0))
            {
                /* The same midletsuite register the port. */
                result = PUSH_REGISTERED;
            }
            else
            {
                /* Already register by other midlet suite */
                result = PUSH_CONFLICT_REGISTERED;
            }

            break;
        }
    }
#endif
    return result;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  jpush_push_set_unavailable_by_connection
 * DESCRIPTION
 *  set all push registrations unavailable
 * PARAMETERS
 *  store       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_set_unavailable_by_connection(char *connection)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    pushentry_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (strcmp(connection, p->connection) == 0)
        {
            if (p->available)
                p->available = KAL_FALSE;
        }
    }
#endif
}

#ifdef SUPPORT_JSR_120

/*****************************************************************************
 * FUNCTION
 *  push_process_recvd_sms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  port        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *push_process_recvd_sms_ind(int port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSH_PROCESS_RECVD_SMS_IND);
#ifdef __SUPPORT_JAVA_PUSH__
    kal_take_mutex(g_jam_push_mutex);

    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (port == p->portNo)
        {
            break;
        }
    }

    /*if (p == NULL)
    {
        sprintf(_kvmLogStr, "push_process_recvd_sms_ind, p = NULL\n");
        Kprintf();
    }
    else
    {
        sprintf(_kvmLogStr, "push_process_recvd_sms_ind, p = %x\n", (int)p);
        Kprintf();
    }*/

    kal_give_mutex(g_jam_push_mutex);
    
#endif
    return p;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  jpush_push_deletesuite
 * DESCRIPTION
 *  Delete all of connections for a suite, using the storage name
 * PARAMETERS
 *  store       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_deletesuite(char *store)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    pushentry_struct *pushp;
    pushentry_struct **pPrevNext = &g_jpush_pushlist_ptr;
    pushentry_struct *pushnext;

    alarmentry_struct *alarmp;
    alarmentry_struct **alarmpPrevNext = &g_jpush_alarmlist_ptr;
    alarmentry_struct *alarmnext;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHDELETESUITE);

    /* Find all of the entries to remove */
    kal_take_mutex(g_jam_push_mutex);
    for (pushp = g_jpush_pushlist_ptr; pushp != NULL; pushp = pushnext)
    {
        pushnext = pushp->next;
        if (strcmp(store, pushp->storagename) == 0)
        {
            for (i = 0; i < MAX_PUSH_REGISTRY; i++)
            {
                /* remove the push indication memorized by MMI */
                if (g_mmi_java_push_cntx.push_entry_used[i])
                {
                    if (strcmp(store, g_mmi_java_push_cntx.push_entry[i].mids_storage_name) == 0)
                    {
                        jpush_search_and_delete_persistent_push(
														pushp->portNo,
                            g_mmi_java_push_cntx.push_entry[i].pushalarm_type,
                            g_mmi_java_push_cntx.push_entry[i].mid_class_name,
                            g_mmi_java_push_cntx.push_entry[i].mid_id,
                            g_mmi_java_push_cntx.push_entry[i].mids_storage_name,
                            pushp->filter,
                            pushp->connection,
                            pushp->appid,
                            pushp->nfc_url,
                            KAL_TRUE);
                        g_mmi_java_push_cntx.push_entry_used[i] = KAL_FALSE;
                        g_mmi_java_push_cntx.push_entry[i].mids_storage_name = NULL;
                    }
                }
            }

            /* Unregister the sms port */
            if (pushp->portNo != -1)
            {
            #ifdef SUPPORT_JSR_120
                J2ME_sms_unregister_by_push(pushp->portNo, PUSH_REGISTRY);
            #endif
            }
        #ifdef SUPPORT_JSR_205
            else if (pushp->appid != NULL)
            {
                J2ME_mms_register_by_push(pushp->appid, 1, PUSH_REGISTRY);
                //J2ME_mms_register(pushp->appid, 1, PUSH_REGISTRY);      /* 1 for unregister */
            }
        #endif /* SUPPORT_JSR_205 */
        #ifdef SUPPORT_JSR_257_PUSH
            else if (pushp->nfc_url != NULL && strncmp(pushp->nfc_url, "secure-element:?", 16) == 0)
            {
                jcc_nfc_push_unregister(JCC_NFC_TARGET_SECURE_ELEMENT_ID);
            }
            else if (pushp->nfc_url != NULL
                 && (strncmp(pushp->nfc_url, "ndef:rtd?", 9) == 0
			     || strncmp(pushp->nfc_url, "ndef:external_rtd?",18)==0
			     || strncmp(pushp->nfc_url, "ndef:mime?",10)==0
			     || strncmp(pushp->nfc_url, "ndef:uri?",9)==0))
            {
                jcc_nfc_push_unregister(JCC_NFC_TARGET_NDEF_TAG_ID);
            }
        #endif

            free_ctrl_buffer(pushp->connection);
            free_ctrl_buffer(pushp->midlet);
            free_ctrl_buffer(pushp->filter);
            free_ctrl_buffer(pushp->storagename);
            if (pushp->appid != NULL)
            {
                free_ctrl_buffer(pushp->appid);
            }
            if (pushp->nfc_url != NULL)
            {
                free_ctrl_buffer(pushp->nfc_url);
            }
            *pPrevNext = pushp->next;
            free_ctrl_buffer(pushp);
            g_push_length--;            
            continue;
        }
        pPrevNext = &pushp->next;
    }
    kal_give_mutex(g_jam_push_mutex);
    jpush_push_save();

    /* Find all of the alarm entries to remove */
    for (alarmp = g_jpush_alarmlist_ptr; alarmp != NULL; alarmp = alarmnext)
    {
        alarmnext = alarmp->next;
        if (strcmp(store, alarmp->storagename) == 0)
        {
            for (i = 0; i < MAX_PUSH_REGISTRY; i++)
            {
                /* remove the push indication memorized by MMI */
                if (g_mmi_java_push_cntx.push_entry_used[i])
                {
                    if (strcmp(store, g_mmi_java_push_cntx.push_entry[i].mids_storage_name) == 0)
                    {
                        jpush_search_and_delete_persistent_push(
                            0,
                            g_mmi_java_push_cntx.push_entry[i].pushalarm_type,
                            g_mmi_java_push_cntx.push_entry[i].mid_class_name,
                            g_mmi_java_push_cntx.push_entry[i].mid_id,
                            g_mmi_java_push_cntx.push_entry[i].mids_storage_name,
                            NULL,
                            NULL,
                            NULL,
                            NULL,
                            KAL_TRUE);
                        g_mmi_java_push_cntx.push_entry_used[i] = KAL_FALSE;
                        g_mmi_java_push_cntx.push_entry[i].mids_storage_name = NULL;
                    }
                }
            }
            *alarmpPrevNext = alarmp->next;

            free_ctrl_buffer(alarmp->midlet);
            alarmp->midlet = NULL;
            free_ctrl_buffer(alarmp->storagename);
            alarmp->storagename = NULL;
            free_ctrl_buffer(alarmp);
            continue;
        }
        alarmpPrevNext = &alarmp->next;
    }

    jpush_alarm_save();
#endif
}



/*****************************************************************************
 * FUNCTION
 *  jpush_push_findsuite
 * DESCRIPTION
 *  Lookup the midlet name given the storagename
 * PARAMETERS
 *  store           [?]  
 *  available       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
char *jpush_push_findsuite(char *store, kal_bool available)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    kal_uint32 len = 0, total_len = 0;
    char *connlist = NULL;
    char *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHFINDSUITE);
#ifdef __SUPPORT_JAVA_PUSH__
    /* 2 phase parse */
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (strcmp(store, p->storagename) == 0)
        {
            if (available && (p->available == KAL_FALSE))
                continue;
            total_len += strlen(p->connection) + 1;
        }
    }

    if (total_len)
    {
        connlist = ptr = jvm_malloc(total_len);

        if (connlist == NULL)
        {
            return NULL;
        }

        for (p = g_jpush_pushlist_ptr; p; p = p->next)
        {
            if (strcmp(store, p->storagename) == 0)
            {
                if (available && (p->available == KAL_FALSE))
                    continue;
                len = strlen(p->connection);
                kal_mem_cpy(ptr, p->connection, len);
                ptr[len] = ',';
                ptr += len + 1;
            }
        }

        connlist[total_len - 1] = 0;
    }

#ifdef MIDP_PUSH_DEBUG
    if (connlist)
    {
        sprintf(_kvmLogStr, "J2ME Debug: pushfindsuite %s", connlist);
        Kprintf();
    }
#endif /* MIDP_PUSH_DEBUG */ 
#endif
    return connlist;
}



/*****************************************************************************
 * FUNCTION
 *  jpush_push_add
 * DESCRIPTION
 *  Add one entry to the push registry.
 *  If the entry already exists return -1.
 *  On succesful registration, write a new copy of the file to disk.
 * PARAMETERS
 *  str     [?]     - push midletsuite storage name
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_add(char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    pushentry_struct *pe;
    kal_char *tmp_str;
    kal_int32 tmp_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    kal_trace(TRACE_FUNC, FUNC_J2ME_ADDPUSHENTRY);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
#ifdef MIDP_PUSH_DEBUG
    sprintf(_kvmLogStr, "J2ME Debug: addpushentry %s", str);
    Kprintf();
#endif /* MIDP_PUSH_DEBUG */ 

    kal_take_mutex(g_jam_push_mutex);

    tmp_str = jpush_push_getstoragename(str, 0, &tmp_len);

    /* Check if the entry already exists? */
    for (p = g_jpush_pushlist_ptr; p != NULL; p = p->next)
    {
        if (strncmp(tmp_str, p->connection, tmp_len) == 0)
        {
            kal_give_mutex(g_jam_push_mutex);
            return -1;
        }
    }

    if (g_push_length + g_timealarm_count >= MAX_PUSH_REGISTRY)
    {
        kal_give_mutex(g_jam_push_mutex);
        return -2;
    }

    /* Add the new entry. */
    if ((pe = (pushentry_struct*) get_ctrl_buffer(sizeof(pushentry_struct))) != NULL)
    {
        kal_char tmp_buf[16];

        pe->next = g_jpush_pushlist_ptr;

        tmp_str = jpush_push_getstoragename(str, 0, &tmp_len);
        pe->connection = jvm_str_dup(tmp_str, tmp_len);

        tmp_str = jpush_push_getstoragename(str, 1, &tmp_len);
        pe->midlet = jvm_str_dup(tmp_str, tmp_len);

        tmp_str = jpush_push_getstoragename(str, 2, &tmp_len);
        pe->filter = jvm_str_dup(tmp_str, tmp_len);

        tmp_str = jpush_push_getstoragename(str, 3, &tmp_len);
        pe->storagename = jvm_str_dup(tmp_str, tmp_len);

        tmp_str = jpush_push_getstoragename(str, 4, &tmp_len);
        memcpy(tmp_buf, tmp_str, tmp_len);
        tmp_buf[tmp_len] = 0;
        sscanf(tmp_buf, "%d", &(pe->midletid));

        pe->push_game_type = 0;
        pe->portNo = -1;
        pe->available = KAL_FALSE;
        pe->appid = NULL;
        pe->nfc_url = NULL;
        if ((pe->connection == NULL) || (pe->midlet == NULL) || (pe->filter == NULL) || (pe->storagename == NULL))
        {
            if (pe->connection)
            {
                free_ctrl_buffer(pe->connection);
            }
            if (pe->midlet)
            {
                free_ctrl_buffer(pe->midlet);
            }
            if (pe->filter)
            {
                free_ctrl_buffer(pe->filter);
            }
            if (pe->storagename)
            {
                free_ctrl_buffer(pe->storagename);
            }
            free_ctrl_buffer(pe);
            kal_give_mutex(g_jam_push_mutex);
            return (-2);
        }
        else
        {
        #ifdef SUPPORT_JSR_257_PUSH
            if (strncmp(pe->connection, "secure-element:?", 16) == 0)
            {
                _jpush_process_nfc_se(pe->connection, &(pe->nfc_url));
            }

            else if (strncmp(pe->connection, "ndef:rtd?", 9) == 0
			     || strncmp(pe->connection, "ndef:external_rtd?",18)==0
			     || strncmp(pe->connection, "ndef:mime?",10)==0
			     || strncmp(pe->connection, "ndef:uri?",9)==0   )
            {
                _jpush_process_nfc_tag(pe->connection, &(pe->nfc_url));
            }
            else
        #endif
        #ifdef SUPPORT_JSR_205
            if (strncmp(pe->connection, "mms://:", 7) == 0)
            {
                _jpush_process_appid(pe->connection, &(pe->appid));
            }
            else 
        #endif /* SUPPORT_JSR_205 */
        #ifdef SUPPORT_JSR_120
            if (strncmp(pe->connection, "sms://:", 7) == 0)
            {
                _jpush_process_port(pe->connection, &(pe->portNo));
            }
            else
        #endif
            {
                if (pe->connection)
                {
                    free_ctrl_buffer(pe->connection);
                }
                if (pe->midlet)
                {
                    free_ctrl_buffer(pe->midlet);
                }
                if (pe->filter)
                {
                    free_ctrl_buffer(pe->filter);
                }
                if (pe->storagename)
                {
                    free_ctrl_buffer(pe->storagename);
                }
                free_ctrl_buffer(pe);
                kal_give_mutex(g_jam_push_mutex);
                return (-2);

            }
            g_jpush_pushlist_ptr = pe;
            g_push_length++;
        }
    }

    if (pe != NULL)
    {
        if (jpush_push_save() == 0)
        {
            kal_give_mutex(g_jam_push_mutex);
            return 0;
        }
    }
    kal_give_mutex(g_jam_push_mutex);
#endif
    return -2;
}



/*****************************************************************************
 * FUNCTION
 *  jpush_push_findconn
 * DESCRIPTION
 *  Extract the storage name from the connection connection string
 * PARAMETERS
 *  str     [?]  
 * RETURNS
 *  void
 *****************************************************************************/
char *jpush_push_findconn(char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;
    char *entry = NULL;
    kal_uint32 total_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_PUSHFINDCONN);
#ifdef __SUPPORT_JAVA_PUSH__
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (strcmp(str, p->connection) == 0)
        {
            break;
        }
    }

    if (p)
    {
        kal_char midletIdString[10];
        sprintf(midletIdString, "%d", p->midletid);

        total_len = strlen(p->connection) + 1 +
            strlen(p->midlet) + 1 + strlen(p->filter) + 1 + strlen(p->storagename) + 1;

        total_len += (strlen(midletIdString) + 1);

        entry = jvm_malloc(total_len);

        if (entry == NULL)
        {
            return NULL;
        }

        sprintf(entry, "%s,%s,%s,%s,%s", p->connection, p->midlet, p->filter, p->storagename, midletIdString);
    }

#ifdef MIDP_PUSH_DEBUG
    if (entry)
    {
        sprintf(_kvmLogStr, "J2ME Debug: pushfindconn %s", entry);
        Kprintf();
    }
#endif /* MIDP_PUSH_DEBUG */ 
#endif
    return entry;
}



/*****************************************************************************
 * FUNCTION
 *  jpush_push_remove
 * DESCRIPTION
 *  remove the push registeration correspounding to the Connection and storagename
 * PARAMETERS
 *  str         [?]   
 *  store       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_push_remove(char *str, char *store)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p;
    pushentry_struct *lastp;
    kal_int32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_REMOVEPUSHENTRY);
#ifdef __SUPPORT_JAVA_PUSH__
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
#ifdef MIDP_PUSH_DEBUG
    sprintf(_kvmLogStr, "J2ME Debug: removepushEntry %s %s", str, store);
    Kprintf();
#endif /* MIDP_PUSH_DEBUG */ 

    kal_take_mutex(g_jam_push_mutex);

    lastp = g_jpush_pushlist_ptr;
    /* Find the entry to remove */
    for (p = g_jpush_pushlist_ptr; p; p = p->next)
    {
        if (strncmp(str, p->connection, strlen(str)) == 0)
        {
            /* Check if the connection belongs to another suite. */
            if (strcmp(store, p->storagename) != 0)
            {
                ret = -2;
                continue;
            }
        #ifdef SUPPORT_JSR_257_PUSH
            if (strncmp(str, "secure-element:?", 16) == 0)
            {
                jcc_nfc_push_unregister(JCC_NFC_TARGET_SECURE_ELEMENT_ID);
            }
            else if (strncmp(str, "ndef:rtd?", 9) == 0
			     || strncmp(str, "ndef:external_rtd?",18)==0
			     || strncmp(str, "ndef:mime?",10)==0
			     || strncmp(str, "ndef:uri?",9)==0)
            {
                jcc_nfc_push_unregister(JCC_NFC_TARGET_NDEF_TAG_ID);
            }
            else
        #endif
        #ifdef SUPPORT_JSR_205
            if (strncmp(str, "mms://", 6) == 0)
            {
			    J2ME_mms_register(p->appid, 1, PUSH_REGISTRY, -1);  /* 1 for unregister */
            }
            else
        #endif /* SUPPORT_JSR_205 */
            {
            #ifdef SUPPORT_JSR_120
                J2ME_sms_unregister_by_push(p->portNo, PUSH_REGISTRY);
            #endif
            }

            /* Remove the registration entry. */
            if (p == g_jpush_pushlist_ptr)
            {
                /* Replace the top of the list. */
                g_jpush_pushlist_ptr = p->next;
            }
            else
            {
                lastp->next = p->next;
            }

            g_push_length--;

            if (p->connection != NULL)
            {
                free_ctrl_buffer(p->connection);
            }
            if (p->midlet != NULL)
            {
                free_ctrl_buffer(p->midlet);
            }
            if (p->filter != NULL)
            {
                free_ctrl_buffer(p->filter);
            }
            if (p->storagename != NULL)
            {
                free_ctrl_buffer(p->storagename);
            }
            if (p->appid != NULL)
            {
                free_ctrl_buffer(p->appid);
            }
            if (p->nfc_url)
            {
                free_ctrl_buffer(p->nfc_url);
            }
            free_ctrl_buffer(p);

            if (jpush_push_save() == 0)
            {
                kal_give_mutex(g_jam_push_mutex);
                return 0;
            }
        }
        lastp = p;
    }
    kal_give_mutex(g_jam_push_mutex);
#endif
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  jpush_push_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_push_enable(kal_bool enable)
{
#ifdef __SUPPORT_JAVA_PUSH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jpush_push_enabled = enable;
#endif
}

