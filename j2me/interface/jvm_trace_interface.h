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
 *   jvm_trace_interface.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JVM_TRACE_INTERFACE_H__
#define __JVM_TRACE_INTERFACE_H__
#include "kal_trace.h"
#define JVM_TRACE_DISPLAY_IN_GROUP (1)  /* in group meaning the log will be displayed by filter,otherwise it's displayed in system log */

#define JVM_TRACE_MAX_SIZE  512

typedef enum
{
    JVM_TRACE_TYPE_ALL      = 0,
    JVM_TRACE_TYPE_FUNC     = TRACE_FUNC,
    JVM_TRACE_TYPE_DEBUG    = TRACE_STATE,
    JVM_TRACE_TYPE_INFO     = TRACE_INFO,
    JVM_TRACE_TYPE_WARNING  = TRACE_WARNING,
    JVM_TRACE_TYPE_ERROR    = TRACE_ERROR,

    
    JVM_TRACE_TYPE_JVM      = TRACE_GROUP_3,
    JVM_TRACE_TYPE_JVM_FILE = TRACE_GROUP_3,
    JVM_TRACE_TYPE_JVM_MEM  = TRACE_GROUP_3,
    JVM_TRACE_TYPE_JAM      = TRACE_GROUP_4,
    
    JVM_TRACE_TYPE_OFF,

    JVM_TRACE_TYPE_TOTAL
} jvm_trace_type_enum;
#define JVM_TRACE_TYPE_JUI      TRACE_GROUP_1
#define JVM_TRACE_TYPE_JUI_DEBUG  TRACE_GROUP_2


#define JVM_TRACE           jvm_trace
#define JVM_TRACE_DEBUG     jvm_trace_debug
#define JVM_TRACE_INFO      jvm_trace_info
#define JVM_TRACE_WARNING   jvm_trace_warning
#define JVM_TRACE_ERROR     jvm_trace_error

#define System_out_println  jvm_trace_sys_out
#define System_err_println  jvm_trace_sys_error

extern void jvm_trace_initialize(void);
extern void jvm_trace(const kal_char *message, jvm_trace_type_enum trace_type);
extern void jvm_trace_time(const kal_char *message, jvm_trace_type_enum trace_type);
extern void jvm_trace_debug(const kal_char *fmt, ...);
extern void jvm_trace_info(const kal_char *fmt, ...);
extern void jvm_trace_warning(const kal_char *fmt, ...);
extern void jvm_trace_error(const kal_char *fmt, ...);
extern void jvm_trace_sys_out(kal_char * message);
extern void jvm_trace_sys_error(kal_char * message);
extern void jvm_trace_set_default_level(jvm_trace_type_enum trace_level);
extern kal_int32 jvm_trace_get_default_level(void);

extern void jvm_debug_print(const char * message);
extern kal_char _jvm_log_buffer[JVM_TRACE_MAX_SIZE];
#define _kvmLogStr          _jvm_log_buffer


/*****************************************************************************
 * FUNCTION
 *  Kputs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
__inline void Kputs(char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //jvm_debug_print(s);
    System_out_println(s);
    
}


/*****************************************************************************
 * FUNCTION
 *  Kputchar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline void Kputchar(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char chs[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    chs[0] = ch;
    chs[1] = 0;
    jvm_debug_print(chs);
}

#define Kprintf()                         Kputs(_kvmLogStr)


#endif /* __JVM_TRACE_INTERFACE_H__ */ 

