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
 * vmoptions.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * options
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_LIB_LOG__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "vmopt.h"
#include "vmio.h"
#include "vmsys.h"
#include "vmchset.h"
#include "vmhttp.h"
#include "vmlog.h"
#include "vminifile.h"
#include "vmsock.h"

extern VMINT vm_get_memory_pool_size(void);

static char options_file[50];


static int options_file_init = 0;


int logOut = TRUE;	

int logLevel = VM_FATAL_LEVEL;

int logMtk = FALSE;

char logModule[MRE_MAX_C_FILE_COUNT * MRE_MAX_C_FILENAME_LEN]; // = {0};
extern int _logAllModule;

static int dMemSize = MRE_SYS_MEMPOOL_SIZE;									


#define section			"Options"
#define log_key 			"log_level"
#define log_out_key		"log_out"
#define log_mtk_key		"log_mtk"
#define memory_key		"dynamic_memory"
#define log_module_key	"log_module"


int mre_get_options_dynamic_memory(void);
int mre_get_options_log_level(void);
int mre_get_options_log_out(void);
int mre_get_options_log_mtk(void);

void mre_set_options_log_level(int log_level);
void mre_set_options_log_out(int log_out);
void mre_set_options_log_mtk(int log_mtk);

void mre_set_options_dynamic_memory(int dy_mem_size);

void mre_set_options_log_level(int log_level) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_level);
	if(vm_write_profile_string(section, log_key, buf, options_file))
	{
		logLevel = log_level;
		MMI_TRACE(MMI_MRE_TRC_MOD_VMOPTIONS, TRC_MRE_VMOPTIONS_165 ,mre_get_options_log_level());
	}
}


void mre_set_options_log_out(int log_out) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_out);
	if(vm_write_profile_string(section, log_out_key, buf, options_file))
	{
		logOut = log_out;
		MMI_TRACE(MMI_MRE_TRC_MOD_VMOPTIONS, TRC_MRE_VMOPTIONS_181 ,mre_get_options_log_out());
	}
}


void mre_set_options_log_mtk(int log_mtk) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_mtk);
	if(vm_write_profile_string(section, log_mtk_key, buf, options_file))
	{
		logMtk = log_mtk;
		MMI_TRACE(MMI_MRE_TRC_MOD_VMOPTIONS, TRC_MRE_VMOPTIONS_197 ,mre_get_options_log_mtk());
	}
}

void mre_set_options_dynamic_memory(int dy_mem_size) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	sprintf(buf,"%d\t",dy_mem_size);
	
	if(vm_write_profile_string(section, memory_key, buf, options_file))
	{	
		dMemSize = dy_mem_size;
		MMI_TRACE(MMI_MRE_TRC_MOD_VMOPTIONS, TRC_MRE_VMOPTIONS_212 ,mre_get_options_dynamic_memory());
	}
}

int mre_get_options_log_level(void) 
{
	return logLevel;
}

int mre_get_options_log_out(void) 
{
	return logOut;
}

int mre_get_options_log_mtk(void) 
{
	return logMtk;
}


int mre_get_options_dynamic_memory(void) 
{
	return dMemSize;
}

VMINT mre_options_init(char* filename)
{
	struct vm_fileinfo_t file;
	VMINT findHandle = -1;
	

	if(!filename || strlen(filename) ==0)
		return FALSE;

	sprintf(options_file, "%s", filename);
	options_file_init = 1;
		
	//if ((findHandle = vm_find_first(vm_ucs2_string(options_file), &file)) >= 0)
	if ((findHandle = vm_find_first(vm_ucs2_string_by_ascii(options_file), &file)) >= 0)
	{
		vm_find_close(findHandle);
		logLevel = vm_read_profile_int(section, log_key, VM_WARN_LEVEL, options_file);
		/**
		dMemSize = vm_read_profile_int(section, memory_key, 
			vm_get_memory_pool_size() , options_file);
			**/
		logOut = vm_read_profile_int(section, log_out_key, TRUE, options_file);

		logMtk = vm_read_profile_int(section, log_mtk_key, FALSE, options_file);
		MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMOPTIONS_261 , logLevel, logOut, logMtk);
	}
	else
	{
		logLevel = VM_WARN_LEVEL;
	
		/**
		dMemSize = vm_get_memory_pool_size();
		**/
		logOut = TRUE;
		logMtk = FALSE;
	}	

	if(!logMtk)
	{
		vm_log_close();
	}
		
	 dMemSize = MRE_SYS_MEMPOOL_SIZE;
	MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMOPTIONS_280 ,
		logLevel, dMemSize, logOut, logMtk, findHandle);

	return (findHandle >= 0 ? TRUE : FALSE);
}
#endif

