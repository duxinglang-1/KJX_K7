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
 * vmlog.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * log module
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef LOG_H_
#define LOG_H_
#include "vmswitch.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "mmi_trc.h"

#define VM_DEBUG_LEVEL		5
#define VM_INFO_LEVEL		4
#define VM_WARN_LEVEL		3
#define VM_ERROR_LEVEL		2
#define VM_FATAL_LEVEL		1


#define MRE_MAX_C_FILENAME_LEN	(20)		/* max length of .c files in MRE */
#define MRE_MAX_C_FILE_COUNT		(80)		/* max number of .c files in MRE */
/*add modules need to log out in in default case*/
#define MRE_DEFAULT_LOG_MODULE	"*"

void vm_app_log(char* info);
void vm_app_name_info(int pcb_id, int res_id, unsigned short* name);
void vm_app_res_info(int pcb_id, int res_id, int total, int used, int peak);
int vm_vsprintf(char *buf, const char *fmt, va_list args);
int vm_sscanf(const char *buf, const char *fmt, va_list args);

#ifdef __MRE_LIB_LOG__

/*****************************************************************************
 * FUNCTION
 *    vm_log_init
 * DESCRIPTION
 *  initialize mre log file.
 * PARAMETERS
 *  filename : [IN] log file full name.
 *  log_level : [OUT] log level, from 1 to 5. 
*****************************************************************************/
void vm_log_init(char* filename, int log_level);

//void vm_set_log_level(int log_level);

/*****************************************************************************
 * FUNCTION
 *    vm_log_close
 * DESCRIPTION
 *  close mre log file.
*****************************************************************************/
void vm_log_close(void);

void _vm_log_debug(char* fmt, ...);

void _vm_log_info(char* fmt, ...);

void _vm_log_warn(char* fmt, ...);

void _vm_log_error(char* fmt, ...);

void _vm_log_fatal(char* fmt, ...);

int _vm_log_module(const char* __file__, const int __line__);

void _vm_log_long(char *fmt, int len);


#ifdef WIN32
#define vm_log_fatal			_vm_log_fatal
#define vm_log_error			_vm_log_error
#define vm_log_warn			_vm_log_warn
#define vm_log_info			_vm_log_info
#define vm_log_debug		_vm_log_debug
#else
/*****************************************************************************
 * FUNCTION
 *    vm_log_fatal
 * DESCRIPTION
 *  write fatal level log.
 * PARAMETERS
 *  fmt : [IN] format string.
*****************************************************************************/
#define vm_log_fatal(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_fatal(__VA_ARGS__) 

/*****************************************************************************
 * FUNCTION
 *    vm_log_error
 * DESCRIPTION
 *  write error level log.
 * PARAMETERS
 *  fmt : [IN] format string.
*****************************************************************************/
#define vm_log_error(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_error(__VA_ARGS__)

/*****************************************************************************
 * FUNCTION
 *    vm_log_warn
 * DESCRIPTION
 *  write warn level log.
 * PARAMETERS
 *  fmt : [IN] format string.
*****************************************************************************/
#define vm_log_warn(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_warn(__VA_ARGS__)

/*****************************************************************************
 * FUNCTION
 *    vm_log_info
 * DESCRIPTION
 *  write info level log.
 * PARAMETERS
 *  fmt : [IN] format string.
*****************************************************************************/
#define vm_log_info(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_info( __VA_ARGS__)

/*****************************************************************************
 * FUNCTION
 *    vm_log_debug
 * DESCRIPTION
 *  write debug level log.
 * PARAMETERS
 *  fmt : [IN] format string.
*****************************************************************************/
#define vm_log_debug(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_debug(__VA_ARGS__)

#endif

#define vm_log_long		_vm_log_long
#define VM_MMI_TRACE  	MMI_TRACE

#else

#ifdef WIN32
#define vm_log_fatal      
#define vm_log_error 
#define vm_log_warn   
#define vm_log_info      
#define vm_log_debug 

#define vm_log_init  
#define vm_set_log_level  
#define vm_log_close()     
#define vm_log_long 
#define VM_MMI_TRACE
#else
#define vm_log_fatal(...)      
#define vm_log_error(...)    
#define vm_log_warn(...)     
#define vm_log_info(...)       
#define vm_log_debug(...)  

#define vm_log_init(...)   
#define vm_set_log_level(...)  
#define vm_log_close(...) 

#define vm_log_long(...) 
#define VM_MMI_TRACE(...)
#endif

#endif

#ifdef __cplusplus
}
#endif 

#endif

