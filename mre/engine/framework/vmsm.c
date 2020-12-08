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
 *   vmsm.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   shared module support
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"
#include "vmopt.h"
#ifdef __MRE_CORE_SM__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MMIDataType.h"

#include "vmsys.h"
#include "vmstdlib.h"
#include "vmmem.h"
#include "vmchset.h"
#include "vmgettag.h"
#include "vmcerter.h"
#include "vmcert.h"
#include "vmcermng.h"
#include "vmpermng.h"
#include "vmdes.h"
#include "vmopt.h"

#include "elf.h"
#include "elfldr.h"
#include "vmres.h"
#include "vmenv.h"
#include "vmtimer.h"
#include "vmloader.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "vmpromnginner.h"
#include "vmsm.h"
#include "vmlog.h"
#include "DevConfigDef.h"
#include "DevConfigGprot.h"
#include "app_mem.h"
#include "med_api.h"
#include "med_main.h"
#include "med_smalloc.h"


/**********************************************************************************/
/* from vmpromng.c */
extern VMINT vm_get_running_app_sb(void);
extern void vm_jump_vreapp(unsigned int init_param_addr);
extern void vm_jump_vsm(VMWSTR fileName, unsigned int param);
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern VMINT _vm_sb_stack_push(VMINT r9);
extern VMINT _vm_sb_stack_pop(void);
extern VMINT vm_get_sym_entry(char* symbol);

extern VMINT * _vm_per_get_mre_fun_list(void);
extern void _vm_per_free_mre_fun_list(VMINT * mrefun_list);
extern void _vm_per_clear_mre_fun_list(void);
extern VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode );

extern _vm_pcb_t* vm_alloc_pcb(VMWSTR filename, _vm_pcb_t* father, VMINT isRemoveDriver);
extern VMINT vm_alloc_memory(VMUINT memSize);
extern void vm_free_memory(VMINT handle);
extern VMINT vm_push_pcb_into_status_union(VM_PROCESS_STATUS status, _vm_pcb_t* pcb);
extern _vm_pcb_t* vm_pop_pcb_up_status_union(VM_PROCESS_STATUS status, VM_P_HANDLE pHandle);
extern void vm_cleanup_unload_status_pcb(void);
extern VMINT vm_start_mre_envirment(vm_mre_evt_cb_t vam_cb, VMINT state);
extern void vm_exit_app_by_asm(VM_P_HANDLE p_handle);
extern VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount);

extern mmi_devconfig_system_config_struct sysconf;
extern vm_vsm_mem_struct g_vsm_mem_info[];
extern vm_sm_builtin_struct mre_buildin_vsm_array[];
extern VMINT32 vm_res_id_delete_all(VMINT is_rom);
extern void _vm_init_resource_monitor_cb(VMINT tid);

static _vm_sm_t * sm_list = NULL; 	/* List to store all loaded SMs */

extern vm_res_monitor_init_struct * res_monitor_init_ptr;

extern VMINT vm_ce_merge_permission(VMWSTR filename);

#ifdef MRE_ON_MODIS
extern void vm_release_vsm(VMINT sb);
#endif

/* Insert node at head */


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_list_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void _vm_sm_list_insert(_vm_sm_t * sm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!sm_list)
	{
	    sm_list = sm_ptr;
	    sm_list->next_sm = NULL;
	}    
	else
	{
        sm_ptr->next_sm = sm_list;
        sm_list = sm_ptr;
    }
}

/* Remove specified node */


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_list_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void _vm_sm_list_remove(_vm_sm_t * sm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_sm_t **pptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pptr = &sm_list; *pptr; pptr = &((*pptr)->next_sm)) 
    {
        if (*pptr == sm_ptr) 
        {
            *pptr = sm_ptr->next_sm;
            return;
        }
    }
    
	return ;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_list_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  value       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
_vm_sm_t * _vm_sm_list_find(VMINT type, VMINT value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sm_ptr = sm_list; sm_ptr; sm_ptr = sm_ptr->next_sm)
    {
		switch (type)
		{
		case SM_FIND_BY_R9:
			if (sm_ptr->r9 == value)
			{
				return sm_ptr;
			}
			break;
		case SM_FIND_BY_HANDLE:
			if (sm_ptr->handle == value)
			{
				return sm_ptr;
			}
			break;
		case SM_FIND_BY_PCB:
			if ((VMINT)sm_ptr->pcb == value)
			{
				return sm_ptr;
			}
			break;
		case SM_FIND_BY_PCB_EVENT_FILTER:
			if ((VMINT)sm_ptr->pcb == value && sm_ptr->event_filter)
			{
				return sm_ptr;
			}
			break;
		case SM_FIND_BY_HANDLER:
			if ((VMINT)sm_ptr->smHandler == value)
			{
				return sm_ptr;
			}
			break;
		case SM_FIND_BY_FILENAME:
			if (vm_wstrcmp_ignore_case(sm_ptr->fullFileName, (VMWSTR)value) == 0)
			{
				return sm_ptr;
			}
		default:
			return NULL;
		}
	}
	return NULL;
}

VMUINT vm_sm_get_pool_size_from_ptr(void *_ptr)
{
	VMINT i;
	VMUINT8 *ptr = (VMUINT8 *)_ptr;
	
	for (i = 0; i < MRE_SUPPORT_MAX_VSM_NUM; i++) {
		if ((g_vsm_mem_info[i].adm_id != NULL)
			   && (g_vsm_mem_info[i].mem_base <= ptr)
			   && (ptr < g_vsm_mem_info[i].mem_base + g_vsm_mem_info[i].mem_size)) {
			   	return g_vsm_mem_info[i].mem_size;
		}
	}
	
	return 0;
}

VMUINT _vm_sm_get_total_memsize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT mem = 0;
	_vm_sm_t * sm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sm_ptr = sm_list; sm_ptr; sm_ptr = sm_ptr->next_sm)
    {
#ifndef MRE_ON_MODIS
        void *ptr = (void *)(sm_ptr->codeBase ? sm_ptr->codeBase : sm_ptr->dataBase);
		mem += vm_sm_get_pool_size_from_ptr(ptr);
#else
        mem += sm_ptr->heapSize;
#endif
	}
	
	return mem;
}

/*****************************************************************************
 * FUNCTION
 *  _vm_sm_is_from_sys_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT _vm_sm_is_from_sys_driver(VMWSTR fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT isloadSysDriver = TRUE;
	VMWCHAR sysDriver = (VMWCHAR)vm_get_system_driver();
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* 判定是否是T卡上的程序 */
	if (sysDriver >= L'A' && sysDriver <= L'Z')
	{
		if (sysDriver == fileName[0] || (sysDriver + (L'a' - L'A')) == fileName[0])
			isloadSysDriver = TRUE;
		else
			isloadSysDriver = FALSE;
	}
	else if (sysDriver >= L'a' && sysDriver <= L'z')
	{
		if (sysDriver == fileName[0] || (sysDriver - (L'a' - L'A')) == fileName[0])
			isloadSysDriver = TRUE;
		else
			isloadSysDriver = FALSE;
	}
	else
	{
		isloadSysDriver = FALSE;
	}

	return isloadSysDriver;
}


static VMINT _vm_sm_create(_vm_sm_t * sm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT app_id;
	VMINT *fun_list;
	VMINT is_vsm = 0;
    vm_exec_format_enum suffix;
    VMINT rorw_zip;
    vm_file_type_enum file_type;
	vm_load_context_t context;
	
#ifdef __MRE_CORE_SAFETY__
	VMINT certres = -1;
	VMUCHAR*  cert_buff;
	VMINT buflen = 3072;		
#endif
    VMINT mem_idx;
	VMINT memSize = 0, smSize, bufSize;
	
	VMINT lerr = 0, info = 0, ret = 0;
	VMWSTR fileName = sm_ptr->fullFileName;
	VMCHAR tmp_buf[24];

	
	suffix = vm_parse_exec_format(fileName);

	if (suffix != VM_EXEC_ROM) 
	{
	    is_vsm = 1;
	}

	file_type = vm_get_file_type(fileName);
	switch (file_type) {
	case VM_VXP_ADS:
	case VM_VSM_ADS:
	case VM_VSM_RVCT:
	case VM_VSM_GCC:
	case VM_SIMPLE_VXP_ADS:
	    // accepted file type, nothing to do
	    break;
	default:
	case VM_VXP_RVCT:
	case VM_VSO_RVCT:
	case VM_VXP_GCC:
	case VM_VSO_GCC:
	    lerr = 2; info = file_type; goto unknown_type;
	}
	/* VM_VSM_RVCT will be treated as VM_VSM_ADS later, because they have same format */
    
	/* get RO RW is zipped or not */
    rorw_zip = 0; bufSize = 4;
    if (vm_get_vm_tag(fileName, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize) != GET_TAG_TRUE) {
        rorw_zip = 0;
    }
    
#ifdef __MRE_CORE_SAFETY__
	if ((cert_buff = (VMUCHAR* )_vm_kernel_malloc(buflen)) == NULL)
	{
		lerr = 3; goto unknown_type;
	}
		
	certres = vm_ce_auth_app_ex(fileName, cert_buff, buflen, VERIFY_FULL);
	
	_vm_kernel_free(cert_buff);
	
	if (certres < VM_CE_VERIFY_OK )
	{
		lerr = 4; info = certres; goto unknown_type;
	}
#endif
    
    bufSize = 4;
	if (GET_TAG_TRUE != vm_get_vm_tag(fileName, VM_CE_INFO_APP_ID, &app_id, &bufSize))
	{
		lerr = 5; info = app_id; goto unknown_type;
	}
	
	/*get needed memory from tag*/
	bufSize = 4;
	if (vm_get_vm_tag(fileName, VM_CE_INFO_MEM_REQ, &memSize, &bufSize) != GET_TAG_TRUE || memSize <= 0)
	{
		lerr = 6; info = memSize; goto unknown_type;
	}
	memSize = (memSize * 1024); // unit: KB -> B, (a*1024) and (a<<10) is same

    vm_ce_merge_permission(fileName);
    /*挂接funlst*/
	fun_list = _vm_per_get_mre_fun_list();
	_vm_per_clear_mre_fun_list();
	if (fun_list == NULL)
	{
	    lerr = 7; goto unknown_type;
	}
	
	sm_ptr->handle = ((VMINT)sm_ptr > 0) ? (VMINT)sm_ptr : ((VMINT)sm_ptr  * (-1));
	sm_ptr->isReDriver = is_vsm ? !_vm_sm_is_from_sys_driver(fileName) : FALSE;
	sm_ptr->app_id = app_id;
	sm_ptr->heapSize = memSize;
	sm_ptr->mre_fun_list = fun_list;
	sm_ptr->tagName = NULL;
	
	if (vm_get_vm_tag(fileName, VM_CE_INFO_NAME, NULL, &bufSize) == GET_TAG_TRUE)
	{
		sm_ptr->tagName = (VMUINT8 *)_vm_kernel_calloc(bufSize + 1);
		
		if(sm_ptr->tagName)
		{
			if(vm_get_vm_tag(fileName, VM_CE_INFO_NAME, sm_ptr->tagName, &bufSize) != GET_TAG_TRUE)
			{
				_vm_kernel_free(sm_ptr->tagName);
				sm_ptr->tagName = NULL;
			}
		}
	}
		
    memset(&context, 0, sizeof(context));
    context.fileName = sm_ptr->fullFileName;
    context.suffix = suffix;
    context.rorw_zip = rorw_zip;
    context.file_type = file_type;

#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	
    context.asm_index = -1;
    context.preload_flags = VM_LOAD_PRELOAD_READ;
    ret = vm_load_normal(&context);
    if (ret != 0) {
        lerr = 9; info = ret; goto free_funlist;
    }

	if(context.file_type == VM_VSM_ADS  || context.file_type == VM_SIMPLE_VXP_ADS)
    {
    	smSize = sm_ptr->heapSize + context.roSize + 2*context.rwSize + context.ziSize + PARAM_BLOCK_SIZE;
	}
	else if(context.file_type == VM_VSM_RVCT || context.file_type == VM_VSM_GCC)
	{
    	smSize = sm_ptr->heapSize + context.sysv_node.sysv_length + (VMINT)context.sysv_node.sysv_virt;
	}
	else
	{
		smSize = sm_ptr->heapSize;
	}
	
    mem_idx = vm_alloc_memory(smSize);
    if (mem_idx < 0) {
        lerr = 10; info = mem_idx; goto free_funlist;
    }
    g_vsm_mem_info[mem_idx].p_handle = sm_ptr->handle;
    g_vsm_mem_info[mem_idx].heap_size = sm_ptr->heapSize;

#ifdef MRE_ENABLE_MEM_DEBUG
	g_vsm_mem_info[mem_idx].mem_stat.malloc_count = 0;
	g_vsm_mem_info[mem_idx].mem_stat.free_count = 0;
	g_vsm_mem_info[mem_idx].mem_stat.current = 0;
	g_vsm_mem_info[mem_idx].mem_stat.peak = 0;
	g_vsm_mem_info[mem_idx].mem_stat.fail_times = 0;
	g_vsm_mem_info[mem_idx].mem_stat.max_fail_size = sm_ptr->heapSize;
	g_vsm_mem_info[mem_idx].mem_stat.avail_heap_size = sm_ptr->heapSize;
#endif
	/* init resource monitor log */
	if (res_monitor_init_ptr == NULL)
	{
		res_monitor_init_ptr = _vm_kernel_malloc(sizeof (vm_res_monitor_init_struct));
		res_monitor_init_ptr->p_handle = g_vsm_mem_info[mem_idx].p_handle;
		res_monitor_init_ptr->res_type = VM_RES_TYPE_APP_NAME;
		res_monitor_init_ptr->next_app = NULL;
		vm_create_timer(VM_RES_MONITOR_LOG_INTERVAL, (VM_TIMERPROC_T)_vm_init_resource_monitor_cb);
	}
	else
	{
		vm_res_monitor_init_struct* temp_ptr;
		vm_res_monitor_init_struct* tail_ptr;
		temp_ptr = _vm_kernel_malloc(sizeof (vm_res_monitor_init_struct));
		temp_ptr->p_handle = g_vsm_mem_info[mem_idx].p_handle;
		temp_ptr->res_type = VM_RES_TYPE_APP_NAME;
		temp_ptr->next_app = NULL;
		/* find out the tail app node */
		tail_ptr = res_monitor_init_ptr;
		while (tail_ptr->next_app != NULL)
		{
			tail_ptr = tail_ptr->next_app;
		}
		tail_ptr->next_app = temp_ptr;
		
		vm_create_timer(VM_RES_MONITOR_LOG_INTERVAL, (VM_TIMERPROC_T)_vm_init_resource_monitor_cb);
	}
	
    context.asm_index = mem_idx;
    context.load_buffer = g_vsm_mem_info[mem_idx].mem_base;
    context.load_size   = g_vsm_mem_info[mem_idx].mem_size;
    context.preload_flags = 0;
    ret = vm_load_normal(&context);
    if (ret != 0) {
        lerr = 11; info = ret; goto free_asm;
    }
    
    // copy values from context into pcb
    sm_ptr->rwSize = context.rwSize;
    sm_ptr->ziSize = context.ziSize;
	sm_ptr->codeSize = context.codeSize;
	sm_ptr->dataSize = context.dataSize;

	if(context.file_type == VM_VSM_ADS || context.file_type == VM_SIMPLE_VXP_ADS)
	{
	    sm_ptr->codeBase = context.codeBase;
	    sm_ptr->dataBase = context.dataBase;
	    sm_ptr->heapBase = context.dataBase + context.dataSize + HEAP_SIZE;
	    sm_ptr->heapSize = (context.load_buffer + context.load_size) - sm_ptr->heapBase - STACK_SIZE;
	}
	else if(context.file_type == VM_VSM_RVCT || context.file_type == VM_VSM_GCC)
	{
	    sm_ptr->codeBase = context.entry;
	    sm_ptr->dataBase = context.load_buffer + context.sysv_node.sysv_length;
	    sm_ptr->heapBase = context.load_buffer + context.sysv_node.sysv_length + (VMUINT)context.sysv_node.sysv_virt;
	}
	else
	{
	    sm_ptr->codeBase = context.entry;
	    sm_ptr->dataBase = context.load_buffer;
	    sm_ptr->heapBase = context.load_buffer;
	}
	
    sm_ptr->r9 = (unsigned int)sm_ptr->dataBase; 
    sm_ptr->message_proc = NULL;
    
    g_vsm_mem_info[mem_idx].adm_id = (void *)kal_adm_create(sm_ptr->heapBase, sm_ptr->heapSize, NULL, KAL_TRUE);
    if (g_vsm_mem_info[mem_idx].adm_id == NULL) {
        lerr = 12; goto free_asm;
    }
    
	_vm_sm_list_insert(sm_ptr);
	sm_ptr->file_type = file_type;
	sm_ptr->base_name = (VMWSTR)wcsrchr((wchar_t *)sm_ptr->fullFileName, L'\\');
	if (sm_ptr->base_name != NULL)
	{
	    sm_ptr->base_name++; // skip last '\'
	}
	else
	{
	    sm_ptr->base_name = sm_ptr->fullFileName;
	}
	bufSize = 24;
	if (vm_get_vm_tag(fileName, VM_CE_INFO_ISSUE, (void *)tmp_buf, &bufSize) == GET_TAG_TRUE)
	{
	    sm_ptr->build_id = (tmp_buf[4] << 24) + (tmp_buf[8] << 16) + (tmp_buf[12] << 8) + tmp_buf[16];
	}
	else
	{
	    sm_ptr->build_id = 0;
	}
	sm_ptr->dtype = DEBUG_SHARED_MODULE;

	return VM_SM_SUCCESS;
	
free_asm:
    vm_free_memory(sm_ptr->handle);
free_funlist:
    _vm_per_free_mre_fun_list(fun_list);
unknown_type:
	  MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_01, lerr, info, ret);
    return VM_SM_FAILED;
}


static VMINT vm_sm_get_path(VMINT drv, VMWSTR name, VMWSTR wname)
{
	VMINT find_hdl;
	struct vm_fileinfo_t info;
	
#ifndef MRE_ON_MODIS
	kal_wsprintf((WCHAR *)wname, "%c:\\mre\\%w.vsm", drv, name);
#else
	kal_wsprintf((WCHAR *)wname, "%c:\\mre\\%w.dlm", drv, name);
#endif
	if((find_hdl = vm_find_first(wname, &info)) >= 0)
	{
		vm_find_close(find_hdl);
		return TRUE;
	}
	return FALSE;
}


#ifdef MRE_SM_LOAD_VER_CMP
static VMINT _vm_sm_ver_cmp(VMWSTR sm1, VMWSTR sm2)
{
	VMCHAR verBuf[5], verBuf2[5];
	VMINT verSize=4, verSize2=4;
	VMINT ver1=0, ver2=0;

	if (vm_get_vm_tag(sm1, VM_CE_INFO_VER, verBuf, &verSize) == GET_TAG_TRUE)
	{
		if (vm_get_vm_tag(sm2, VM_CE_INFO_VER, verBuf2, &verSize2) == GET_TAG_TRUE)
		{
			ver1 = verBuf[1]*100 + verBuf[2]*10 + verBuf[3];
			ver2 = verBuf2[1]*100 + verBuf2[2]*10 + verBuf2[3];
		}
	}
	return ver1 - ver2;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  vm_sm_name_preprocess
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_name         [IN]        
 *  sm_wpath        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_sm_name_preprocess(VMWSTR sm_name, VMWSTR sm_wname)
{
	if (kal_wstrchr((WCHAR *)sm_name, '\\') == NULL)
	{
		if (!vm_sm_get_path(vm_get_removeable_driver(), sm_name, sm_wname) )
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_02);
			if (!vm_sm_get_path(vm_get_system_driver(), sm_name, sm_wname) )
			{
				VMUINT i,appcount,smcount,socount;
				VMWCHAR tempName[64];
				VMCHAR tempName1[64];
				
				MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_03);
				vm_init_default_game(&appcount, &smcount, &socount);
				
				for(i = 0; i < smcount; i++)
				{
					vm_ascii_to_ucs2((VMWSTR)tempName, 64, (VMSTR)mre_buildin_vsm_array[i].file_name);
					if(kal_wstrcmp((WCHAR *)tempName, (WCHAR *)sm_name) == 0)
					{
						sprintf(tempName1, "%c:\\%u.rom", 64, mre_buildin_vsm_array[i].address);
						vm_ascii_to_ucs2((VMWSTR)sm_wname, 64, (VMSTR) tempName1);
						return VM_SM_SUCCESS;
					}
				}
				
				MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_04);

				return VM_SM_FILE_NOT_FOUND;
			}
		}
#ifdef MRE_SM_LOAD_VER_CMP
		else
		{
			VMWCHAR sm_wname2[MAX_APP_NAME_LEN+1];
			 if (vm_sm_get_path(vm_get_system_driver(), sm_name, sm_wname2) )
			 {
				
				if (_vm_sm_ver_cmp(sm_wname, sm_wname2) < 0)
				{
					vm_wstrcpy(sm_wname, sm_wname2);
					return VM_SM_SUCCESS;
				}
			 }
		}
#endif
	}
	else
	{
		VMINT find_hdl;
		struct vm_fileinfo_t info;
		
		vm_wstrcpy(sm_wname, sm_name);

		if((find_hdl = vm_find_first(sm_wname, &info)) >= 0)
		{
			vm_find_close(find_hdl);
		}
		else
		{
			return VM_SM_FILE_NOT_FOUND;
		}
	}
	return VM_SM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_ptr      [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT _vm_sm_destroy(_vm_sm_t * sm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_ptr)
	{
	
		if (sm_ptr->smHandler)
		{
			_vm_sb_stack_push(sm_ptr->r9);
			sm_ptr->smHandler(VM_SM_MSG_UNLOAD, sm_ptr->handle);
			vm_res_notify_data_by_process(sm_ptr->handle, VM_PMNG_UNLOAD);
			_vm_sb_stack_pop();
		}
		
		/* Remove SM from static list */
		_vm_sm_list_remove(sm_ptr);
		
		/* Free APP MEM of SM */
		vm_free_memory(sm_ptr->handle);

		
		/* Free function list of SM */
		if (sm_ptr->mre_fun_list)
			_vm_per_free_mre_fun_list(sm_ptr->mre_fun_list);

		if(sm_ptr->tagName != NULL)
			_vm_kernel_free(sm_ptr->tagName);
		
#ifdef MRE_ON_MODIS
		vm_release_vsm(sm_ptr->r9);
#endif

		/* Free SM memory */
		_vm_kernel_free(sm_ptr);
		
		return VM_SM_SUCCESS;
	}
	return VM_SM_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_unload_by_pcb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_sm_unload_by_pcb(_vm_pcb_t * pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (pcb)
	{
		_vm_sm_t * sm_str = NULL, * sm_str_cache = NULL;
		
		while ( (sm_str = _vm_sm_list_find(SM_FIND_BY_PCB, (VMINT)pcb)) != NULL )
		{
			if (sm_str == sm_str_cache) 
			{
				break;
			}

			if (sm_str->resfileHandle > 0) 
			{
				if (sm_str->res_data.str_buf != NULL)
				{
					_vm_sb_stack_push(sm_str->r9);
					vm_free(sm_str->res_data.str_buf);
					
					if(sm_str->resfileHandle == 1)
						vm_res_id_delete_all(1);
					else
						vm_res_id_delete_all(0);
					
					vm_free(sm_str->res_buf);
					_vm_sb_stack_pop();
				}
				if(sm_str->resfileHandle != 1)
				FS_Close(sm_str->resfileHandle);
				sm_str->resfileHandle = -1;
			}		
			
			sm_str_cache = sm_str;
			_vm_sm_destroy(sm_str);
		}
		return VM_SM_SUCCESS;
	}
	return VM_SM_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  vm_reg_sm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  smHandler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_sm_callback(VMINT (*smHandler)(VMINT message, VMINT param)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (smHandler)
	{
		VMINT currAppR9 = vm_get_running_app_sb();
		
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			sm_ptr->smHandler = smHandler;
		}
	}
}

VMINT vm_sm_loadw(VMWSTR sm_name)
{
	VMINT ret = 0;
	_vm_pcb_t * app_pcb = NULL;
	_vm_sm_t * sm_ptr = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	
	if ( kal_wstrlen((WCHAR *)sm_name) == 0 || kal_wstrlen((WCHAR *)sm_name)>MAX_APP_NAME_LEN )
		return VM_SM_PARAM_ERROR;
	
	if ((app_pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL)
	{
		return VM_SM_INVALID_INVOKER;
	}
	
	sm_ptr = _vm_kernel_calloc(sizeof(_vm_sm_t));
	
    if (sm_ptr == NULL) 
	{
        return VM_SM_MEMORY_INSUFFICIENT;
    }

	ret = vm_sm_name_preprocess(sm_name, sm_ptr->fullFileName);
	
	if (ret != VM_SM_SUCCESS)
	{
		_vm_kernel_free(sm_ptr);
		return ret;
	}
	
	ret = _vm_sm_create(sm_ptr);
	
	if (ret == VM_SM_SUCCESS)
	{		

		VMUINT initParams[6];
		typedef VMINT (*vm_vxp_entry_fp)(VMUINT symtab);
		typedef VMINT (*vm_vxp_elf_entry_fp)(VMUINT symtab,VMUINT init_address,VMUINT init_count);

		initParams[0] = sm_ptr->r9;
		initParams[1] = (VMUINT)vm_get_sym_entry;
		initParams[2] = (VMUINT)sm_ptr->dataBase+sm_ptr->dataSize;
		initParams[3] = initParams[2] + HEAP_SIZE;
		initParams[4] = (STACK_SIZE);
		initParams[5] = (VMUINT)sm_ptr->codeBase;

		_vm_sb_stack_push(sm_ptr->r9);
#ifndef MRE_ON_MODIS
		if(sm_ptr->file_type == VM_VSM_ADS  || sm_ptr->file_type == VM_SIMPLE_VXP_ADS)
		{
			vm_jump_vreapp((VMUINT)initParams);
		}
		else if(sm_ptr->file_type == VM_VSM_RVCT)
		{
			vm_vxp_entry_fp vm_vxp_entry_f;
			vm_vxp_entry_f = (vm_vxp_entry_fp)(initParams[5]);
			vm_vxp_entry_f((VMUINT)vm_get_sym_entry);
		}
		else if(sm_ptr->file_type == VM_VSM_GCC)
		{
			vm_vxp_elf_entry_fp vm_vxp_entry_f;
			vm_vxp_entry_f = (vm_vxp_elf_entry_fp)(initParams[5]);
			vm_vxp_entry_f((VMUINT)vm_get_sym_entry, 0, 0);
		}
		else
		{
			vm_log_warn("Not support file type, type = %d", sm_ptr->file_type);
		}
#else
		vm_jump_vsm(sm_ptr->fullFileName, (VMUINT)vm_get_sym_entry);
#endif
		_vm_sb_stack_pop();

	}
	else
	{
		_vm_kernel_free(sm_ptr);
		return VM_SM_CREATE_FAILED;
	}
	
	if (sm_ptr->smHandler)
	{
		sm_ptr->pcb = app_pcb;
		sm_ptr->invoker = app_pcb->pHandle;

		_vm_sb_stack_push(sm_ptr->r9);
		sm_ptr->smHandler(VM_SM_MSG_LOAD, sm_ptr->handle);
		_vm_sb_stack_pop();		
	}
	
	return sm_ptr->handle;
	
}

VMINT vm_sm_load(VMSTR sm_name)
{
	VMWCHAR sm_wname[MAX_APP_NAME_LEN];
	VMINT ret = 0;

	if(sm_name == NULL || strlen(sm_name) == 0 || strlen(sm_name) > MAX_APP_NAME_LEN)
		return VM_SM_PARAM_ERROR;
	
	vm_ascii_to_ucs2((VMWSTR)sm_wname, MAX_APP_NAME_LEN, (VMSTR)sm_name);

	ret = vm_sm_loadw(sm_wname);

	MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_05, sm_name, ret);

	return ret;
	
}

/*****************************************************************************
 * FUNCTION
 *  vm_sm_get_func_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_hdl      [IN]        
 *  api_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_get_func_entry(VMINT sm_hdl, VMINT api_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret = 0;
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_hdl < 0)
		return 0;

	sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE ,sm_hdl);

	if (sm_ptr)
	{
		if (sm_ptr->smHandler)
		{
			_vm_sb_stack_push(sm_ptr->r9);
			ret = sm_ptr->smHandler(VM_SM_MSG_QUERY, api_id);
			_vm_sb_stack_pop();
		}
	}
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_06, api_id, ret);

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  vm_sm_unload
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_hdl      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_unload(VMINT sm_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_hdl < 0)
		return VM_SM_PARAM_ERROR;
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_07, sm_hdl);

	sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE ,sm_hdl);

	_vm_sm_destroy(sm_ptr);

	return VM_SM_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  vm_sm_get_app_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_hdl      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_get_app_handle(VMINT sm_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_hdl < 0)
		return VM_SM_PARAM_ERROR;

	sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE ,sm_hdl);
	
	if (sm_ptr && sm_ptr->pcb)
		return sm_ptr->pcb->pHandle;
	
	return VM_SM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_sm_set_sb_by_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_set_sb_by_ptr(VMINT ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!ptr)
		return VM_SM_PARAM_ERROR;

	sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLER, ptr);
		
	if (sm_ptr)
	{
		return _vm_sb_stack_push(sm_ptr->r9);
	}
	return VM_SM_FAILED;
}

/* Set R9 to SM copy by handle */


/*****************************************************************************
 * FUNCTION
 *  vm_sm_set_sb_by_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_hdl      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_set_sb_by_handle(VMINT sm_hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_hdl < 0)
		return VM_SM_PARAM_ERROR;

	sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE, sm_hdl);

	if (sm_ptr)
	{
		return _vm_sb_stack_push(sm_ptr->r9);
	}
	return VM_SM_FAILED;
}



/*****************************************************************************
 * FUNCTION
 *  vm_sm_set_sb_for_invoker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_set_sb_for_invoker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_ptr)
	{
		if (sm_ptr->pcb)
		{
			return _vm_sb_stack_push(sm_ptr->pcb->r9);
		}
	}
	return VM_SM_FAILED;
}

/* Reset R9 by stack */


/*****************************************************************************
 * FUNCTION
 *  vm_sm_reset_sb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_reset_sb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return _vm_sb_stack_pop();
}

/*****************************************************************************
 * FUNCTION
 *  vm_sm_get_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_sm_get_filename(VMWSTR filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (filename)
	{
		VMINT currAppR9 = vm_get_running_app_sb();	
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			vm_wstrcpy(filename, sm_ptr->fullFileName);
			return VM_SM_SUCCESS;
		}
	}
	return VM_SM_FAILED;
}


/* SM exit itself */


/*****************************************************************************
 * FUNCTION
 *  vm_sm_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_sm_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	_vm_sm_destroy(sm_ptr);

}

void vm_sm_reg_msg_proc(VM_MESSAGE_PROC proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT currAppR9 = vm_get_running_app_sb();
	_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sm_ptr != NULL)
    {
        sm_ptr->message_proc= proc;
    }
    else
    {
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSM, TRC_MRE_VMSM_08);
    }
}


VMINT vm_sm_get_handle_by_package_name(VMSTR name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_sm_t * sm_ptr;
		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sm_ptr = sm_list; sm_ptr; sm_ptr = sm_ptr->next_sm)
    {
		if(sm_ptr->tagName != NULL)
		{
			if(strcmp((const char *)name, (const char *)sm_ptr->tagName) == 0)
				return sm_ptr->handle;
		}
	}
	
	return 0;
}

#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_des_decrypt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_key              [?]         
 *  cryptext            [?]         
 *  cryptext_len        [IN]        
 *  out_len             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMUINT8 * _vm_sm_des_decrypt(VMUINT8 * sm_key, VMUINT8 * cryptext, VMINT cryptext_len, VMINT * out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT8 * text=NULL, * text2=NULL;
	VMINT text_len=0, text2_len=0;
	VMUINT8 des_key[DES_BLOCK_SIZE+1];
	
	/* Got cryptext from VSM */
	VMDESHANDLE des_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Get DES KEY2 */
	memcpy(des_key, sm_key+DES_BLOCK_SIZE, DES_BLOCK_SIZE);
	des_key[DES_BLOCK_SIZE] = 0;
	des_hdl = vm_des_set_key(des_key);
	if (des_hdl >= 0)
	{
		text = vm_des_decrypt(des_hdl, cryptext, cryptext_len, &text_len);
		vm_des_reset_key(des_hdl);
		if (text)
		{
			text[text_len] = 0;

			/* DES decrypt ok for the 1st time */

			/* Get DES KEY1 */
			memcpy(des_key, sm_key, DES_BLOCK_SIZE);
			des_key[DES_BLOCK_SIZE] = 0;
			des_hdl = vm_des_set_key(des_key);
			if (des_hdl >= 0)
			{
				text2 = vm_des_decrypt(des_hdl, text, text_len, &text2_len);
				vm_des_reset_key(des_hdl);
				if (text2)
				{
					vm_free(text);
					
					text2[text2_len] = 0;

					* out_len = text2_len;

					return text2;
				}
			}
		}
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_authrize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sm_name             [IN]        
 *  sm_wfilename        [IN]        
 *  app_pcb             [?]         
 * RETURNS
 *  
 *****************************************************************************/
static VMINT _vm_sm_authrize(VMSTR sm_name, VMWSTR sm_wfilename, _vm_pcb_t * app_pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret;
	VMINT private = TRUE;
	VMINT buf_size = sizeof(VMINT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = vm_get_vm_tag(sm_wfilename, VM_CE_INFO_SM_PRIVATE, (void*)&private, &buf_size);
	if (ret == GET_TAG_NOT_FOUND) 	//not private
	{
		private = FALSE;
	}
	
	if (!private) 	/* Not private SM */
	{
		return VM_SM_SUCCESS;
	}
	else
	{
		if (app_pcb && app_pcb->sm_key)
		{
			VMUINT8 * cryptext=NULL;
			VMINT cryptext_len=0;
						
			ret = vm_get_vm_tag(sm_wfilename, VM_CE_INFO_SM_CRYPTEXT, NULL, &cryptext_len);
			if (ret == GET_TAG_TRUE && cryptext_len>0)
			{
				cryptext = vm_malloc(cryptext_len+1);
				if (cryptext)
				{
					ret = vm_get_vm_tag(sm_wfilename, VM_CE_INFO_SM_CRYPTEXT, (void*)cryptext, &cryptext_len);
					cryptext[cryptext_len] = 0;
					if (ret == GET_TAG_TRUE)
					{
						VMINT text2_len = 0;
						VMUINT8 * text2 = _vm_sm_des_decrypt(app_pcb->sm_key, cryptext, cryptext_len, &text2_len);
						if (text2)
						{
							if (memcmp(sm_name, text2, text2_len) == 0)
							{
								vm_free(text2);
								vm_free(cryptext);
								return VM_SM_SUCCESS;
							}
						}
						if (text2) vm_free(text2);
					}
				}
			}
			if (cryptext) vm_free(cryptext);
		}
	}
	return VM_SM_FAILED;
}


/* For SM Privatization */
VMUINT8 * sm_key = NULL;


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_set_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  certdig     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_sm_set_key(VMUCHAR * certdig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (certdig && *(certdig+DIG_MD5_LEN) )
	{
		VMUINT8 * sm_key_ptr = certdig + DIG_MD5_LEN;
		sm_key = _vm_kernel_malloc(DIG_MD5_LEN);

		if (sm_key)
		{
			memcpy(sm_key, sm_key_ptr, DIG_MD5_LEN);
			return 0;
		}
	}
	sm_key = NULL;
	return -1;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_get_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 * _vm_sm_get_key()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_key)
	{
		VMUINT8 * key = sm_key;
		sm_key = NULL;
		return key;
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sm_free_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void _vm_sm_free_key()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sm_key)
	{
		_vm_kernel_free(sm_key);
		sm_key = NULL;
	}
}
#endif /* __MRE_SAL_CHE_DES__ */ 

#endif /* __MRE_CORE_SM__ */ 

