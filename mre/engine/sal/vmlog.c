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
 * vmlog.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vmswitch.h"
#include "Conversions.h"

#include "kal_trace.h"
#include "MMI_trc.h"


#include "vmlog.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmopt.h"
#include "vmstdlib.h"

#include "custom_config.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "fs_func.h"
#include "stack_config.h"
#include "vmmem.h"
#include "MMI_mre_app_info_trc.h"
#include "vmdl.h"

static int log_file;

static int log_init;

extern int logOut;	

extern int logLevel;

extern int logMtk;

/*Temperaly used for compitable with original codes*/
#define def_log_level		logLevel
#define def_log_mtk		logMtk
#define def_log_out		logOut

extern char logModule[MRE_MAX_C_FILE_COUNT * MRE_MAX_C_FILENAME_LEN];


static char _modFile[MRE_MAX_C_FILENAME_LEN];	// = {0}; without this expression, the code size can reduce MRE_MAX_C_FILENAME_LEN

static char * _cache_file_ = NULL;	/*Pointer to the filename of current running file*/
static int _lineNo = 0;				/*Line No. of current running file*/

int _logAllModule = 0;		/*Project wide global BOOL variable, in charege of whether to log all the modules*/
#ifdef __MRE_LIB_LOG__

static void log_it(VMINT level, char* fmt, va_list ap);

void vm_log_init(char* filename, int log_level) {
	
	char wfilename[MAX_APP_NAME_LEN];

   	
	def_log_level = log_level;
	log_init = 0;
	strcpy(logModule, MRE_DEFAULT_LOG_MODULE);
	_modFile[0] = 0;
	_cache_file_ = NULL;
	_lineNo = 0;
	_logAllModule = TRUE;
	
	mmi_chset_convert(
				MMI_CHSET_ASCII, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)filename, 
				(VMCHAR *)wfilename, 
				MAX_APP_NAME_LEN);

	if ((log_file = FS_Open((WCHAR *)wfilename,FS_CREATE_ALWAYS)) < 0) 
	{
		return;
	}

	log_init = 1;
	
}

void _vm_log_debug(char* fmt, ...) {
	va_list ap;

	if ((def_log_level >= VM_DEBUG_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_DEBUG_LEVEL, fmt, ap);
		va_end(ap); 
	}
}

void _vm_log_info(char* fmt, ...) {
	va_list ap;

	if ((def_log_level >= VM_INFO_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_INFO_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_warn(char* fmt, ...) {
	va_list ap;

	if ((def_log_level >= VM_WARN_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_WARN_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_error(char* fmt, ...) {
	va_list ap;

	if ((def_log_level >= VM_ERROR_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_ERROR_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_fatal(char* fmt, ...) {
	va_list ap;

	if ((def_log_level >= VM_FATAL_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_FATAL_LEVEL, fmt, ap);
		va_end(ap);
	}
}



extern VMINT vm_pmng_get_current_handle_ignore_status(void);
void log_it(VMINT level, char* fmt, va_list ap) 
{
	vm_time_t tm;
	VM_P_HANDLE phandle;
	char text[MAX_APP_NAME_LEN], level_text[10] = {0};
	VMUINT written;

	memset(text, 0x00, sizeof(text));
	memset(level_text, 0x00, sizeof(level_text));
	
	switch(level)
	{
	case VM_DEBUG_LEVEL:
		strcpy(level_text, "DEBUG");
		break;
	case VM_INFO_LEVEL:
		strcpy(level_text, "INFO");
		break;
	case VM_WARN_LEVEL:
		strcpy(level_text, "WARN");
		break;
	case VM_ERROR_LEVEL:
		strcpy(level_text, "ERROR");
		break;
	default:
		strcpy(level_text, "FATAL");
		break;
	};
	
	vm_get_time(&tm);
	phandle = vm_pmng_get_current_handle_ignore_status();
	sprintf(text, "%d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d [%s][PID:%d][%s:%d]- ", tm.year, tm.mon, tm.day, tm.hour,
		tm.min, tm.sec, level_text, phandle, _modFile, _lineNo);

	//vsprintf(text + strlen(text), fmt, ap);

#ifdef __MTK_TARGET__
		vsnprintf(text + strlen(text), 150, fmt, ap);
#else 
		_vsnprintf(text + strlen(text), 150, fmt, ap);
#endif 

	strcat(text, "\n\0");
	
    MMI_PRINT(MOD_MRE, TRACE_INFO,"%s", text);

	if(log_init && def_log_mtk == 1)
	{
		if (FS_Write(log_file, text, (VMUINT)strlen(text), &written) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
		if (FS_Commit(log_file) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
	}
	
}

void vm_log_close(void) {
	if (log_init) 
	{
		FS_Commit(log_file);
		FS_Close(log_file);
		log_init = 0;
	}
}

void _vm_log_long(char *fmt, int len)
{
  	if (len > 0 && len < 200) {
		_vm_log_debug("\n%s", fmt);
  	} else if (len > 200) {
		char text[200];
		int i = 0, t_size = sizeof(text); 
		//char *text=(char*)vm_malloc(t_size);
		//if (NULL == text) return;
		_vm_log_debug("\nLONG LOG==================================================");
		while (i < len) {													
			memset(text, 0,  t_size);						
			memcpy(text, fmt+i, t_size-1<len-i ? t_size-1 : len-i);	
			_vm_log_debug("\n%s", text);								
			i += t_size-1; 
		}
		_vm_log_debug("\nLONG LOG==================================================");
		//vm_free(text); 
	}
}

int _vm_log_module(const char* __file__, const int __line__)
{
	static unsigned int _cache_ret_;

	_lineNo = __line__;	
	
	if (_cache_file_ != __file__)	
	{
		int i = 0;
		char * p = NULL;

		/*updating the cache, save the address of constant string __FILE__*/
		_cache_file_ = (char*)__file__;

		/*
		 * set "p" to the start address of "xxxx.c"
		 *			
		 * p = strstr(__file__, ".c");			//1
		 * p = __file__ + strlen(__file__) - 2;	//2
		 * 1 is obviously slower than 2, but more flexible.
		 * A faster but unflexible method is given below:
		 */
		switch (__file__[0])
		{

		case 's':	//"src\core\dlmalloc.c"
			if (strncmp(__file__, "src", 3) == 0 )
			{
			p = (char *)__file__ + 9;	//sizeof("src\\core\\");
			break;
			}
		case 'c':	//"core\dlmalloc.c"
			if (strncmp(__file__, "core", 4) == 0 )
			{
			p = (char *)__file__ + 5;	//sizeof("core\\");
			break;
			}
		case 'v':	//"vendor\mre30\src\arch\mtk\vmsim.c"
			if (strncmp(__file__, "vendor", 6) == 0 )
			{
			p = (char *)__file__ + 26;	//sizeof("vendor\\mre30\\src\\arch\\mtk\");
			break;
			}
		default:	//unexpected source file path.
			//X:\xxx\xxx\src\core\dlmalloc.c, or dlmalloc.c
			p = strstr(__file__, ".c");
			//while (*--p != '\\'); p++;
			while (p != __file__)
			{
				if (*p == '\\' || *p == '/')	//"xxx\xxx, xxx/xxx"
				{
					p ++;
			break;
				}
				p --;
			}
			//break;
			
			//_vm_log_warn("[LOG] unrecognized __FILE__[%p:%s]", __file__, __file__);
			
			//_modFile[0] = 0;	//strcpy(_modFile, __file__);
			//return _cache_ret_ = TRUE;
			//break;
		}

		/*
		 * find "xxxx" in "xxxx.c", and copy "xxxx" to "_modFile"
		 */
		while (*p != '.')	
		{
			if (i < MRE_MAX_C_FILENAME_LEN)
			{
			_modFile[i++] = *p++;
			}
			else 
			{
				_modFile[0] = 0;
				i = 0;
				break;
			}
		}
		_modFile[i] = 0;

		if (_logAllModule || 	/*log all modules*/
			strstr(logModule, _modFile) ) /*log current module*/	// find "_modFile" in logModule configuration string "xxx,xxx,xxx".
		{
			//_vm_log_debug("[LOG] do log MODULE[%s] in __FILE__[%p:%s]", _modFile, __file__, __file__);
			_cache_ret_ = TRUE;
		} 
		else 
		{
			//_vm_log_debug("[LOG] do not log MODULE[%s] in __FILE__[%p:%s]", _modFile, __file__,__file__);
			_cache_ret_ = FALSE;
		}
	}
	return _cache_ret_;
}

#endif
void vm_app_log(char* info)
{
	VM_P_HANDLE phandle;
	char log_buffer[MAX_APP_NAME_LEN];

	phandle = vm_pmng_get_current_handle_ignore_status();
	memset(log_buffer,0,MAX_APP_NAME_LEN);
	sprintf(log_buffer, "%d\t", phandle);
	
	if( strlen(info) > 220)
	{
		strncat(log_buffer, info, 220);
	}
	else
	{
		strcat(log_buffer, info);
	}
	
    MMI_PRINT(MOD_MRE_APP_LOG, TRACE_INFO, "%s", log_buffer);
}

void vm_app_res_info(int pcb_id, int res_id, int total, int used, int peak)
{
    MMI_TRACE(MMI_MRE_APP_TRC_INFO,TRC_MMI_MRE_APP_INFO,pcb_id, res_id, total, used, peak);
}

void vm_app_name_info(int pcb_id, int res_id, unsigned short* name)
{
    VMINT strlen = vm_wstrlen((VMWSTR)name);
    VMINT i;
    VMCHAR* ascii_name = (VMCHAR*)_vm_kernel_malloc(strlen * 4 + 1);

    for (i=0; i<strlen; i++)
    {
        ascii_name[i*4] = name[i]>>12 & 0x000F;
        ascii_name[i*4+1] = name[i]>>8 & 0x000F;
        ascii_name[i*4+2] = name[i]>>4 & 0x000F;
        ascii_name[i*4+3] = name[i] & 0x000F;
    }

    for (i=0; i<(strlen*4); i++)
    {
        if (ascii_name[i]<=9)
        {
            ascii_name[i] += '0';
           
        }
        else if ((ascii_name[i]>=0x0A) && (ascii_name[i]<=0x0F))
        {
            ascii_name[i] =ascii_name[i]-10 + 'A' ;
        }
        else
        {
        }
    }
    *(ascii_name+i)=0;
    
    MMI_PRINT(MOD_MRE_APP_INFO, TRACE_INFO,"%d:%d:%s", pcb_id, res_id,ascii_name);

	_vm_kernel_free(ascii_name);
}

int vm_vsprintf(char *buf, const char *fmt, va_list args)
{
	if(buf == NULL)
		return 0;
	
	return vsprintf(buf, fmt, args);
}

int vm_sscanf(const char *buf, const char *fmt, va_list args)
{
#ifdef __MTK_TARGET__
	return vsscanf(buf, fmt, args);
#else 
	return sscanf(buf, fmt, args);
#endif 
}

