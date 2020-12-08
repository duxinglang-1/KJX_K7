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
 *   jvm_trace.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "kal_release.h"
#include "kal_debug.h"
#include "MMI_frm_gprot.h"
#include "jvm_trace_interface.h"

#include "jvm_interface.h"
#include "j2me_trace.h"

#if (defined(__OP11_ATK__) || defined(__AUTO_ATK__))
#include "mmi_frm_at_util_gprot.h"
#endif /* __MMI_OP11_ATK__ */

static kal_char jvm_trace_buffer[JVM_TRACE_MAX_SIZE];

static kal_int32 jvm_trace_default_level;

static kal_uint32 _jvm_log_index;
kal_char _jvm_log_buffer[JVM_TRACE_MAX_SIZE];

#ifndef __MTK_TARGET__
kal_mutexid g_jam_modis_printf_mutex;
#endif 

/*****************************************************************************
 * FUNCTION
 *  jvm_trace_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_default_level = JVM_TRACE_TYPE_ALL;
    memset(jvm_trace_buffer, 0x00, JVM_TRACE_MAX_SIZE * sizeof(kal_char));
}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace_get_default_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_trace_get_default_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jvm_trace_default_level;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace_set_default_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  trace_level     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_set_default_level(jvm_trace_type_enum trace_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((int) trace_level >= JVM_TRACE_TYPE_ALL && (int) trace_level <= JVM_TRACE_TYPE_OFF);   

    jvm_trace_default_level = trace_level;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message         [IN]        
 *  trace_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace(const kal_char *message, jvm_trace_type_enum trace_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef JVM_TRACE_DISPLAY_IN_GROUP
    MMI_PRINT(MOD_J2ME, (trace_class_enum)trace_type, "%s", message);
#else 
    kal_print((kal_char *)message); /* display in system log */
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  jvm_itrace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message         [IN]        
 *  trace_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_itrace(const kal_uint32 message, jvm_trace_type_enum trace_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NEMO_VM__
#ifdef JVM_TRACE_DISPLAY_IN_GROUP
    kal_uint32 messagenum = JMESSAGE_END__enum - JMESSAGE_0__enum -1;
    if(message==0 || message > messagenum)
    {
        kal_trace((trace_class_enum)trace_type,JMESSAGE_0__enum, NULL);
    }
    else
    {
        kal_trace((trace_class_enum)trace_type, (message+JMESSAGE_0__enum), NULL);
    }
    
#else 
    //kal_print((kal_char *)message); /* display in system log */
#endif 
#endif 
}
/*****************************************************************************
 * FUNCTION
 *  jvm_trace_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message         [IN]        
 *  trace_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_time(const kal_char *message, jvm_trace_type_enum trace_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static kal_uint32 last_time = 0;
    kal_uint32 current_time = jvm_get_currenttime_ms();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef JVM_TRACE_DISPLAY_IN_GROUP
    MMI_PRINT(MOD_J2ME, (trace_class_enum)trace_type, "%s,[time=%d,diff=%d]", message,current_time,(current_time-last_time));
    last_time = current_time;
#else 
    kal_print((kal_char *)message); /* display in system log */
#endif   
}

/*****************************************************************************
 * FUNCTION
 *  jvm_trace_debug
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_debug(const kal_char *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list ap;
    //int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JVM_TRACE_TYPE_DEBUG < jvm_trace_default_level)
        return;

    va_start(ap, fmt);
    vsprintf(jvm_trace_buffer, fmt, ap);
    va_end(ap);

    jvm_trace(jvm_trace_buffer, JVM_TRACE_TYPE_DEBUG);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_info(const char *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list ap;
    //int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JVM_TRACE_TYPE_INFO < jvm_trace_default_level)
        return;

    va_start(ap, fmt);
    vsprintf(jvm_trace_buffer, fmt, ap);
    va_end(ap);

    jvm_trace(jvm_trace_buffer, JVM_TRACE_TYPE_INFO);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace_warning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_warning(const kal_char *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list ap;
    //int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JVM_TRACE_TYPE_WARNING < jvm_trace_default_level)
        return;

    va_start(ap, fmt);
    vsprintf(jvm_trace_buffer, fmt, ap);
    va_end(ap);

    jvm_trace(jvm_trace_buffer, JVM_TRACE_TYPE_WARNING);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_trace_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_error(const kal_char *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list ap;
    //int result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JVM_TRACE_TYPE_ERROR < jvm_trace_default_level)
        return;

    va_start(ap, fmt);
    vsprintf(jvm_trace_buffer, fmt, ap);
    va_end(ap);

    jvm_trace(jvm_trace_buffer, JVM_TRACE_TYPE_ERROR);
}

/*****************************************************************************
 * FUNCTION
 *  jvm_debug_print
 * DESCRIPTION
 *  debug print
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_debug_print(const char * message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_print((char *)message); /* display in system log */   
}
//#define SUPPORT_JAVA_SYS_TRACE_TO_FILE
#ifdef SUPPORT_JAVA_SYS_TRACE_TO_FILE
#include "FileMgrSrvGProt.h"
void jvm_trace_sys_log_to_file(char* message)
{
    kal_wchar wfilepath[50];
    kal_int32 handle = -1;
    kal_int32 msglen = 0 ;
    kal_int32 written = 0;
    if(message==NULL|| ((msglen = strlen(message))<= 0))
    {
        kal_prompt_trace(MOD_J2ME,"jvm_trace_sys_log_to_file handle message==NULL|| ((msglen = strlen(message))<= 0");
        return;
    }
    kal_wsprintf(wfilepath, "%c:\\java_sys_output.log\0", SRV_FMGR_PUBLIC_DRV); 
    handle = FS_Open((U16*) wfilepath, FS_CREATE | FS_READ_WRITE);
    if (handle < 0)
    {
        kal_prompt_trace(MOD_J2ME,"jvm_trace_sys_log_to_file handle=%d",handle);
        return;
    }

    FS_Seek(handle, 0, FS_FILE_END);
    FS_Write(handle, (void*)message, msglen, (kal_uint32 *) & written);   
#ifdef __MTK_TARGET__
    FS_Write(handle, (void*)"\n", 1, (kal_uint32 *) & written);
#endif
    FS_Close(handle);   
}
#endif
/*****************************************************************************
 * FUNCTION
 *  jvm_trace_sys_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_sys_log(kal_char * message, kal_int8 type)
{

#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char ch;
    kal_uint32 indx = 0, str_len = strlen(message);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (indx < str_len)
    {
        ch = message[indx];
        indx++;
        if (ch == '\0' || ch == '\n' || ch == '\r' || (_jvm_log_index >= JVM_TRACE_MAX_SIZE - 2))
        {
            if (_jvm_log_index >= JVM_TRACE_MAX_SIZE - 2)
            {
              _jvm_log_buffer[_jvm_log_index++] = ch;
            }

            _jvm_log_buffer[_jvm_log_index++] = '\0';
            #ifdef SUPPORT_JAVA_SYS_TRACE_TO_FILE
            jvm_trace_sys_log_to_file(_jvm_log_buffer);
            #endif
            #if (defined(__OP11_ATK__) || defined(__AUTO_ATK__))
               if(type == 0)
                     mmi_frm_send_at_app_info_output_res_req(0,1,(kal_uint16)str_len,(kal_uint8 *)_jvm_log_buffer);
               else
                     mmi_frm_send_at_app_info_output_res_req(0,0,(kal_uint16)str_len,(kal_uint8 *)_jvm_log_buffer);

            #else
              kal_print(_jvm_log_buffer);
            #endif
              _jvm_log_index = 0;
        }
        else
        {
          _jvm_log_buffer[_jvm_log_index++] = ch;
        }
    }

    if (_jvm_log_index != 0 && str_len > 1)
    {   /* if the str_len is 1, we'll treat it as Kputchar from Java level */
        _jvm_log_buffer[_jvm_log_index++] = '\0';
        #ifdef SUPPORT_JAVA_SYS_TRACE_TO_FILE
        jvm_trace_sys_log_to_file(_jvm_log_buffer);
        #endif
  
        #if (defined(__OP11_ATK__) || defined(__AUTO_ATK__))
        if(type == 0)
        {
            mmi_frm_send_at_app_info_output_res_req(0,1,(kal_uint16)str_len,(kal_uint8 *)_jvm_log_buffer);
        }
        else
        {
            mmi_frm_send_at_app_info_output_res_req(0,0,(kal_uint16)str_len,(kal_uint8 *)_jvm_log_buffer);
        }
        #else
        kal_print(_jvm_log_buffer);
        #endif
        _jvm_log_index = 0;
    }
#else /* __MTK_TARGET__ */ 
    #ifdef SUPPORT_JAVA_SYS_TRACE_TO_FILE
    jvm_trace_sys_log_to_file(message);
    #endif
    kal_take_mutex(g_jam_modis_printf_mutex);
    printf("%s", message);
    kal_give_mutex(g_jam_modis_printf_mutex);
#endif /* __MTK_TARGET__ */
}


void jvm_trace_sys_out(kal_char * message)
{
    jvm_trace_sys_log(message,0);
}

/*****************************************************************************
 * FUNCTION
 *  jvm_trace_sys_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_trace_sys_error(kal_char * message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_sys_log(message,1);
}


