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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include <stdio.h>
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
#include "jam_interface.h"
#include "jam_msg_handler.h"
#include "mmi_frm_gprot.h"
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
#include "FileMgrSrvGProt.h"
#endif

/*************************************************************************
 * Global Definition
 *************************************************************************/
alarmentry_struct *g_jpush_alarmlist_ptr = NULL;
static char _alarm_path[MAX_WCHAR_FILENAME_LEN];
kal_int32 g_timealarm_count = 0;
volatile int jpush_timer_mutex_cnt = 0;
volatile module_type jpush_timer_mutex_tid = MOD_NIL;
 kal_bool g_jam_jpush_support=KAL_FALSE;

/*************************************************************************
 * Global Declaration
 *************************************************************************/
extern event_scheduler *j2me_alarm_es_ptr;
extern kal_int32 g_push_length;
extern mmi_java_push_cntx_struct g_mmi_java_push_cntx;
extern int pushlist_len;
#ifdef __SUPPORT_JAVA_PUSH__
extern void j2me_alarm_timeout_handler(void *msg_ptr);
extern kal_uint64 CurrentTime_md(void);

extern void jam_timealarm_push_ind_handler(
                kal_uint32 type,
                void *callback_entry,
                kal_char *mid_name,
                kal_int32 mid_id,
                kal_char *mid_storagename,
                kal_bool show_popup);

/*************************************************************************
 * Function Definition
 *************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  jpush_timer_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_timer_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI_LOCK; */
    if (kal_get_active_module_id() != jpush_timer_mutex_tid)
    {
        kal_take_mutex(g_jpush_record_mutex);
        jpush_timer_mutex_tid = kal_get_active_module_id();
    }
    ++jpush_timer_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jpush_timer_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_timer_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jpush_timer_mutex_tid == kal_get_active_module_id());

    --jpush_timer_mutex_cnt;

    if (jpush_timer_mutex_cnt == 0)
    {
        jpush_timer_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jpush_record_mutex);
    }
    /* GDI_UNLOCK; */
}

/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_open
 * DESCRIPTION
 *  Open the Alram Registry file, if it exists and populate
 *  an in memory cache of the file contents.
 * PARAMETERS
 *  alarm_path      [?]    
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jpush_alarm_open(char *alarm_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 pushfd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_OPEN);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif

    memcpy(_alarm_path, alarm_path, strlen(alarm_path) + 1);

#if !PERSISTENT_ALARMPUSH
    /* Force to clean all timealarm after re-boot */
    if ((pushfd = jvm_file_open((const char*)alarm_path, O_CREAT | O_TRUNC)) == -1)
    {
        return (-1);
    }
    else
    {
        jvm_file_close(pushfd);
        return (0);
    }
#else /* !PERSISTENT_ALARMPUSH */ 
    /* Now read the registered connections. */
    kal_trace(TRACE_FUNC, JPUSH_ALARM_OPEN_PERSISTENT);

    if ((pushfd = jvm_file_open((const char*)alarm_path, O_RDONLY)) != -1)
    {
        kal_int32 ret;

        /* Read through the file one line at a time */
        if ((ret = jpush_alarm_parse(pushfd)) == -2)
        {
            return (-1);
        }

        /* Close the storage handle */
        jvm_file_close(pushfd);

        if (ret == -1)
        {
            return (-1);
        }

        return (-1);
    }
    else if ((pushfd = jvm_file_open((const char*)alarm_path, O_CREAT | O_RDWR)) == -1)
    {
        jvm_file_close(pushfd);    	
        return (-1);
    }
    jvm_file_close(pushfd);    
    return (0);
#endif /* !PERSISTENT_ALARMPUSH */ /* !PERSISTENT_PUSH */
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_save
 * DESCRIPTION
 *  Save the in memory cache of alarm registrations to a persistent
 *  file for use in subsequent runs.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_alarm_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp;
    int pushfd;
    int counter = 0;
	kal_char tmp_buf[8] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_SAVE);

    jpush_timer_mutex_lock();
    if ((pushfd = jvm_file_open(_alarm_path, O_CREAT | O_TRUNC | FS_COMMITTED)) != -1)
    {

        /* Write a new list of push registrations to the persistent file */
        for (alarmp = g_jpush_alarmlist_ptr; alarmp; alarmp = alarmp->next)
        {
            kal_trace(TRACE_FUNC, JPUSH_ALARM_SAVE_ENTRY,counter);       
            
            if(alarmp->event_id != NULL)
            {	            
                /* for fix the issue : the performace is low due to committed FS_write()*/
                if(alarmp->executed)
                {
                    jvm_file_write(pushfd, "1", 1);
                }
                else
                {
                    jvm_file_write(pushfd, "0", 1);
                }

				jvm_file_write(pushfd, ",", 1);
				jvm_file_write(pushfd, alarmp->midlet, strlen(alarmp->midlet));
				jvm_file_write(pushfd, ",", 1);
			    tmp_buf[0] = (alarmp->wakeup & 0xff00000000000000) >> 56;
				tmp_buf[1] = (alarmp->wakeup & 0x00ff000000000000) >> 48;
				tmp_buf[2] = (alarmp->wakeup & 0x0000ff0000000000) >> 40;
				tmp_buf[3] = (alarmp->wakeup & 0x000000ff00000000) >> 32;
				tmp_buf[4] = (alarmp->wakeup & 0x00000000ff000000) >> 24;
        		tmp_buf[5] = (alarmp->wakeup & 0x0000000000ff0000) >> 16;
        		tmp_buf[6] = (alarmp->wakeup & 0x000000000000ff00) >> 8;
        		tmp_buf[7] = alarmp->wakeup & 0x00000000000000ff;
        		jvm_file_write(pushfd, tmp_buf, 8);
        		jvm_file_write(pushfd, ",", 1);
				jvm_file_write(pushfd, alarmp->storagename, strlen(alarmp->storagename));
				jvm_file_write(pushfd, ",", 1);
				tmp_buf[0] = (alarmp->midletid& 0xff000000) >> 24;
        		tmp_buf[1] = (alarmp->midletid & 0x00ff0000) >> 16;
        		tmp_buf[2] = (alarmp->midletid & 0x0000ff00) >> 8;
        		tmp_buf[3] = alarmp->midletid & 0x000000ff;
				jvm_file_write(pushfd, tmp_buf, 4);
				jvm_file_write(pushfd, ",", 1);
            	tmp_buf[0] = alarmp->alarm_game_type & 0xff;
            	jvm_file_write(pushfd, tmp_buf, 1);
				jvm_file_write(pushfd, "\n", 1);
            }
            counter++;
        }       
        jvm_file_close(pushfd);
    }
    jpush_timer_mutex_unlock();    
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_del
 * DESCRIPTION
 *  Delete one entry from the alarm registry.
 *  If the entry can not be found, return -1.
 *  On succesful deletion, write a new copy of the file to disk.
 * PARAMETERS
 *  del_alarm       [?]   
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jpush_alarm_del(alarmentry_struct *del_alarm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp = g_jpush_alarmlist_ptr;
    alarmentry_struct *lastp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if the entry already exists? */
    kal_trace(TRACE_FUNC, JPUSH_ALARM_DEL); 
    jpush_timer_mutex_lock();     
    for (lastp = alarmp; alarmp != NULL; alarmp = alarmp->next)
    {
        if (del_alarm == alarmp)
        {
            /* Remove an entry. */
            if (alarmp == g_jpush_alarmlist_ptr)
            {
                g_jpush_alarmlist_ptr = alarmp->next;
            }
            else
            {
                lastp->next = alarmp->next;
            }

            alarmp->next = NULL;
            free_ctrl_buffer(alarmp->midlet);
            alarmp->midlet = NULL;
            free_ctrl_buffer(alarmp->storagename);
            alarmp->storagename = NULL;
            alarmp->event_id = NULL;
            free_ctrl_buffer(alarmp);
            jpush_alarm_save();

            jpush_timer_mutex_unlock(); 
            return (0);
        }
        lastp = alarmp;
    }
    jpush_timer_mutex_unlock(); 
    return (-1);
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_del_file
 * DESCRIPTION
 *  Delete one entry from the alarm registry only in file.
 *  If file can not be opened or the entry can not be found, return -1.
 * PARAMETERS
 *  del_alarm       [?]   
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jpush_alarm_del_file(alarmentry_struct *del_alarm)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp;
    int pushfd;
	kal_char tmp_buf[8] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_DEL_FILE);     
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
    jpush_timer_mutex_lock();   
    if ((pushfd = jvm_file_open(_alarm_path, O_CREAT | O_TRUNC | FS_COMMITTED)) != -1)
    {
        /* Write a new list of push registrations to the persistent file */
        for (alarmp = g_jpush_alarmlist_ptr; alarmp; alarmp = alarmp->next)
        {
            /* for fix the issue the two or more push timeout in a short time */
            /* original : if (del_alarm != alarmp)*/
            if (alarmp->event_id)
            {
                /* for fix the issue : the performace is low due to committed FS_write()*/            
                if(alarmp->executed)
                {
                    jvm_file_write(pushfd, "1", 1);
                }
                else
                {
                    jvm_file_write(pushfd, "0", 1);
                }
  
                jvm_file_write(pushfd, ",", 1);
				jvm_file_write(pushfd, alarmp->midlet, strlen(alarmp->midlet));
				jvm_file_write(pushfd, ",", 1);
			    tmp_buf[0] = (alarmp->wakeup & 0xff00000000000000) >> 56;
				tmp_buf[1] = (alarmp->wakeup & 0x00ff000000000000) >> 48;
				tmp_buf[2] = (alarmp->wakeup & 0x0000ff0000000000) >> 40;
				tmp_buf[3] = (alarmp->wakeup & 0x000000ff00000000) >> 32;
				tmp_buf[4] = (alarmp->wakeup & 0x00000000ff000000) >> 24;
        		tmp_buf[5] = (alarmp->wakeup & 0x0000000000ff0000) >> 16;
        		tmp_buf[6] = (alarmp->wakeup & 0x000000000000ff00) >> 8;
        		tmp_buf[7] = alarmp->wakeup & 0x00000000000000ff;
        		jvm_file_write(pushfd, tmp_buf, 8);
        		jvm_file_write(pushfd, ",", 1);
				jvm_file_write(pushfd, alarmp->storagename, strlen(alarmp->storagename));
				jvm_file_write(pushfd, ",", 1);
				tmp_buf[0] = (alarmp->midletid& 0xff000000) >> 24;
        		tmp_buf[1] = (alarmp->midletid & 0x00ff0000) >> 16;
        		tmp_buf[2] = (alarmp->midletid & 0x0000ff00) >> 8;
        		tmp_buf[3] = alarmp->midletid & 0x000000ff;
				jvm_file_write(pushfd, tmp_buf, 4);
				jvm_file_write(pushfd, ",", 1);
            	tmp_buf[0] = alarmp->alarm_game_type & 0xff;
            	jvm_file_write(pushfd, tmp_buf, 1);
				jvm_file_write(pushfd, "\n", 1);
            }
        }
        jvm_file_close(pushfd);
        jpush_timer_mutex_unlock();
        return (0);
    }

    jpush_timer_mutex_unlock();
    return (-1);
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_set
 * DESCRIPTION
 *  set the alarm registrations to event schedule
 * PARAMETERS
 *  entry_ptr       [?]    
 *  alarmtime       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
eventid jpush_alarm_set(alarmentry_struct *entry_ptr, kal_uint32 alarmtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eventid event_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_SET);       
    jpush_timer_mutex_lock();
    event_id = evshed_set_event(
                j2me_alarm_es_ptr,
                (kal_timer_func_ptr) j2me_alarm_timeout_handler,
                entry_ptr,
                alarmtime);
    jpush_timer_mutex_unlock();
    return event_id;
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_cancel
 * DESCRIPTION
 *  cancel the alarm registrations from event schedule
 * PARAMETERS
 *  event_id        [?]  
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_alarm_cancel(eventid *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_CANCEL);     
    jpush_timer_mutex_lock();
    if(*event_id){
        evshed_cancel_event(j2me_alarm_es_ptr, event_id);
    }
    jpush_timer_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jpush_alarm_check(kal_int64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp;
    alarmentry_struct *alarmnext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_CHECK);      
    /* Find any alarm that has expired. */
    for (alarmp = g_jpush_alarmlist_ptr; alarmp != NULL; alarmp = alarmnext)
    {
        alarmnext = alarmp->next;

        if (alarmp->executed == 1)
        {
            continue;
        }

        if ((time - alarmp->wakeup) > 0)
        {
            return alarmp->wakeup;
        }
    }


    return (-1);
}

#if 0
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

/*****************************************************************************
 * FUNCTION
 *  j2me_alarm_timeout_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_ptr       [?]   
 * RETURNS
 *  void
 *****************************************************************************/
void j2me_alarm_timeout_handler(void *param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *entry_ptr = param_ptr;
    alarmentry_struct *alarmp;
    alarmentry_struct *alarmnext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* timealarm */
    kal_trace(TRACE_FUNC, JPUSH_ALARM_TIMEOUT_HDR);  
    jpush_timer_mutex_lock(); 
    for (alarmp = g_jpush_alarmlist_ptr; alarmp != NULL; alarmp = alarmnext)
    {
        if (alarmp == entry_ptr)
        {
            break;
        }
        alarmnext = alarmp->next;
    }
    /* the timer alarm entry has been removed, do not thing. */
    if (alarmp != entry_ptr)
    {
        jpush_timer_mutex_unlock(); 
        return;
    }
    /* Fix to remove event id immediately, instead MMI response. */
    entry_ptr->event_id = NULL;

    /* the following two functions invoke IO. */
    /* set event id is NULL must be done firstly or it may cause the "cancel another guy's event" */
    jpush_alarm_del_file(entry_ptr);

    jam_timealarm_push_ind_handler(
        PUSHTYPE_ALARM_PUSH,
        (void*)entry_ptr,
        entry_ptr->midlet,
        entry_ptr->midletid,
        entry_ptr->storagename,
        KAL_FALSE);
    
    jpush_timer_mutex_unlock();     
}

#if PERSISTENT_ALARMPUSH


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jpush_alarm_free()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp, *alarmtmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clean up the list */
    jpush_timer_mutex_lock();     
    for (alarmp = g_jpush_alarmlist_ptr; alarmp != NULL; alarmp = alarmtmp)
    {
        alarmtmp = alarmp->next;
        free_ctrl_buffer(alarmp->midlet);
        free_ctrl_buffer(alarmp->storagename);
        free_ctrl_buffer(alarmp);
    }
    jpush_timer_mutex_unlock();     
}


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_parse
 * DESCRIPTION
 *  Parse the persistent alaram registry from disk into the
 *  in memory cache representation.
 * PARAMETERS
 *  pushfd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int jpush_alarm_parse(kal_int32 pushfd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buffer[MAX_PUSH_LINE + 1];
    kal_char tmp_buf[25] = {0}; //maximun for 64bits  wake up time
    kal_bool eof = KAL_FALSE;
    int i;
    alarmentry_struct *pe;
    kal_char *tmp_str;
    kal_int32 tmp_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE); 
    jpush_timer_mutex_lock(); 
    while (eof == KAL_FALSE)
    {
        /* Read a line at a time */
        for (i = 0; i < MAX_PUSH_LINE; i++)
        {
            tmp_len = jvm_file_read(pushfd, &buffer[i], 1);

            /* EOF */
            if (tmp_len == 0 || tmp_len == -1)
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
            if ((pe = (alarmentry_struct*) get_ctrl_buffer(sizeof(alarmentry_struct))) != NULL)
            {
                kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE_START);             
                
                pe->next = g_jpush_alarmlist_ptr;

                tmp_str = pushstorage(buffer, 0, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
                tmp_buf[tmp_len] = 0;                 
                pe->executed = atoi(tmp_str);

                tmp_str = pushstorage(buffer, 1, &tmp_len);
                pe->midlet = jvm_str_dup(tmp_str, tmp_len);
                
                MMI_PRINT(MOD_JAM,TRACE_FUNC,"jpush_alarm_parse: midlet = %s",pe->midlet);

				        tmp_str = pushstorage(buffer, 2, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
			    pe->wakeup = ((((kal_int64)tmp_buf[0]) << 56) & 0xff00000000000000) |
					         ((((kal_int64)tmp_buf[1]) << 48) & 0x00ff000000000000) |
					         ((((kal_int64)tmp_buf[2]) << 40) & 0x0000ff0000000000) |
					         ((((kal_int64)tmp_buf[3]) << 32) & 0x000000ff00000000) |
					         ((((kal_int64)tmp_buf[4]) << 24) & 0x00000000ff000000) |
					         ((((kal_int64)tmp_buf[5]) << 16) & 0x0000000000ff0000) |
					         ((((kal_int64)tmp_buf[6]) << 8) & 0x000000000000ff00) |
					         (((kal_int64)tmp_buf[7]) & 0x00000000000000ff);

                tmp_str = pushstorage(buffer, 3, &tmp_len);
                pe->storagename = jvm_str_dup(tmp_str, tmp_len);

                tmp_str = pushstorage(buffer, 4, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
				pe->midletid = ((tmp_buf[0] & 0xFF) << 24) | ((tmp_buf[1] & 0xFF) << 16) | ((tmp_buf[2] & 0xFF) << 8) | (tmp_buf[3] & 0xFF);

                tmp_str = pushstorage(buffer, 5, &tmp_len);
                kal_mem_cpy(tmp_buf, tmp_str, tmp_len);
                pe->alarm_game_type = tmp_buf[0] & 0xFF;
                
                kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE_END); 

                /* for fix the issue : the store data is incorrect due to unknown reason */
                if ((pe->midlet == NULL) || 
                    (pe->storagename == NULL) ||
                    (pe->midletid == 0) || 
                    (pe->wakeup < 0) || 
                    (pe->alarm_game_type >= GAMETYPE_INVALID_TYPE) || 
                    (pe->executed < 0))
                {
                    if (pe->midlet)
                    {
                        free_ctrl_buffer(pe->midlet);
                    }
                    if (pe->storagename)
                    {
                        free_ctrl_buffer(pe->storagename);
                    }
                    g_jpush_alarmlist_ptr = pe->next;
                    free_ctrl_buffer(pe);
                    pe = NULL;
                    
                    kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE_ERROR_AND_DROP);                     
                    
                }
                else
                {
                    kal_uint32 alarm_period;

                    g_jpush_alarmlist_ptr = pe;

                    if ((pe->wakeup) >= CurrentTime_md())
                    {

                        /* Set timer */
                        alarm_period = j2me_ms_2_tick(pe->wakeup - CurrentTime_md());
                        kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE_A_NON_TIMEOUT_PUSH,alarm_period);                         
                        
                        pe->event_id = jpush_alarm_set(pe, alarm_period);
                    }
                    else
                    {
                        kal_trace(TRACE_FUNC, JPUSH_ALARM_PARSE_A_TIMEOUT_PUSH);      
                        
                        /*for fix the issue : the timeouthandler is too fast to interrupt the parse */
                        /*                    because the Aplix CurrentTime_md() will process timeout msg */
                        pe->event_id = jpush_alarm_set(pe, 2500);
                    }

                }
            }
            else
            {
                jpush_timer_mutex_unlock(); 
                /* alarmListFree(); */
                return -2;
            }
        }
    }
    jpush_timer_mutex_unlock(); 
    return 0;
}
#endif /* PERSISTENT_ALARMPUSH */ 
#endif


/*****************************************************************************
 * FUNCTION
 *  jpush_alarm_add
 * DESCRIPTION
 *  Add one entry to the alarm registry.
 *  If the entry already exists return previous alarm time.
 *  On succesful registration, write a new copy of the file to disk.
 * PARAMETERS
 *  str             [?]     
 *  alarm           [IN]        
 *  lastalarm       [?]      
 * RETURNS
 *  
 *****************************************************************************/
int jpush_alarm_add(char *str, kal_int64 alarm, kal_int64 *lastalarm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    alarmentry_struct *alarmp;
    alarmentry_struct *lastp = g_jpush_alarmlist_ptr;
    alarmentry_struct *pe = NULL;
    kal_char *storage_name;
    kal_char *midlet_name;
    kal_int32 alarm_num = 0;
    kal_uint32 alarm_period;
    kal_int32 i;
    kal_int32 storage_len, midlet_len;
    kal_int32 midletid;
    kal_char tmp_buf[16];
    kal_char *tmp_str;
    kal_int32 tmp_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_JAVA_PUSH__
    kal_trace(TRACE_FUNC, JPUSH_ALARM_ADD);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return;
    }
#endif
    jpush_timer_mutex_lock(); 
    *lastalarm = 0;

    storage_name = jpush_push_getstoragename(str, 2, &storage_len);
    midlet_name = jpush_push_getstoragename(str, 0, &midlet_len);
    tmp_str = jpush_push_getstoragename(str, 3, &tmp_len);
    memcpy(tmp_buf, tmp_str, tmp_len);
    tmp_buf[tmp_len] = 0;
    sscanf(tmp_buf, "%d", &midletid);

	
    /* Check if the entry already exists? */
    for (alarmp = g_jpush_alarmlist_ptr; alarmp; alarmp = alarmp->next)
    {
        alarm_num++;

        if (strncmp(midlet_name, alarmp->midlet, midlet_len) == 0 &&
            strncmp(storage_name, alarmp->storagename, storage_len) == 0 &&
            midletid == alarmp->midletid &&
            alarmp->midlet[midlet_len] == 0 && alarmp->storagename[storage_len] == 0)
        {
            kal_int64 temp = alarmp->wakeup;
            *lastalarm = alarmp->wakeup; // 20110321: Fix MIDP OTA TCK: PushRegistry WakeUp

            kal_trace(TRACE_FUNC, JPUSH_ALARM_ADD_REGISTERED);
            
           
            /* Cancel timer, Fix to check if valid event */
            if (alarmp->event_id)
            {
             
                jpush_alarm_cancel(&alarmp->event_id);
                              
            }
            for (i = 0; i < MAX_PUSH_REGISTRY; i++)
            {
                /* remove the push indication memorized by MMI */
                if (g_mmi_java_push_cntx.push_entry_used[i])
                {
                    if (strcmp(alarmp->storagename, g_mmi_java_push_cntx.push_entry[i].mids_storage_name) == 0 &&
						alarmp->midletid == g_mmi_java_push_cntx.push_entry[i].mid_id &&
                        strcmp(alarmp->midlet, g_mmi_java_push_cntx.push_entry[i].mid_class_name) == 0)
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
            alarmp->event_id = NULL;

            if (alarm == 0)
            {
                /* Remove an entry. */
                if (alarmp == g_jpush_alarmlist_ptr)
                {
                    g_jpush_alarmlist_ptr = alarmp->next;
                }
                else
                {
                    lastp->next = alarmp->next;
                }

                alarmp->next = NULL;
                free_ctrl_buffer(alarmp->midlet);
                alarmp->midlet = NULL;
                free_ctrl_buffer(alarmp->storagename);
                alarmp->storagename = NULL;
                free_ctrl_buffer(alarmp);

                jpush_alarm_save();

            }
            else
            {
                /* Replace an entry. */
                alarmp->wakeup = alarm;
                alarmp->executed = 0;

                if (alarm >= CurrentTime_md())
                {

                    alarm_period = j2me_ms_2_tick(alarm - CurrentTime_md());
                                       
                    alarmp->event_id = jpush_alarm_set(alarmp, alarm_period);

                    jpush_alarm_save();
                }
                else
                {
                    j2me_alarm_timeout_handler(alarmp);
                }
            }

            ///*lastalarm = temp; // 20110321: Reomved for MIDP OTA TCK: PushRegistry WakeUp
            jpush_timer_mutex_unlock(); 
            return 0;
        }

        lastp = alarmp;
    }
    g_timealarm_count = alarm_num;
    kal_trace(TRACE_FUNC, JPUSH_ALARM_ADD_NEW,(g_timealarm_count));

    /* Add a new entry. */
    if (alarm &&
        alarm_num + g_push_length < MAX_PUSH_REGISTRY &&
        ((pe = (alarmentry_struct*) get_ctrl_buffer(sizeof(alarmentry_struct))) != NULL))
    {
        pe->next = g_jpush_alarmlist_ptr;
        pe->wakeup = alarm;
        pe->executed = 0;

        pe->midlet = jvm_str_dup(midlet_name, midlet_len);

        pe->storagename = jvm_str_dup(storage_name, storage_len);

        pe->midletid = midletid;

        pe->alarm_game_type = 0;

        if ((pe->midlet == NULL) || (pe->midletid <= 0) || (pe->storagename == NULL))
        {
            free_ctrl_buffer(pe->midlet);
            pe->midlet = NULL;
            free_ctrl_buffer(pe->storagename);
            pe->storagename = NULL;
            free_ctrl_buffer(pe);
            pe = NULL;
        }
        else
        {
            g_jpush_alarmlist_ptr = pe;

            /* Set timer */
            if(alarm > CurrentTime_md())
            {
                alarm_period = j2me_ms_2_tick(alarm - CurrentTime_md());
                pe->event_id = jpush_alarm_set(pe, alarm_period);
          
            }
            else
            {
                j2me_alarm_timeout_handler(pe);
            }
        }
    }

    if (pe == NULL)
    {
        jpush_timer_mutex_unlock(); 
        return (-2);
    }
    
    jpush_timer_mutex_unlock(); 
    jpush_alarm_save();  
#endif
    return (0);
}

