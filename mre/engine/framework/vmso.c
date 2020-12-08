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
 * vmso.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is so file loader.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_CORE_SO__
#include "app_mem.h"
#include "med_api.h"
#include "med_main.h"
#include "DevConfigDef.h"

#include "vmsys.h"
#include "vmpromnginner.h"
#include "elf.h"
#include "elfldr.h"
#include "vmloader.h"
#include "vmopt.h"
#include "vmlog.h"
#include "vmmem.h"
#include "vmenv.h"
#include "vmchset.h"
#include "vmcermng.h"
#include "vmgettag.h"
#include "vmstdlib.h"
#include "vmso.h"
#include "vmcerter.h"
#include "vmcert.h"
#include "vmdl.h"
#include "vmmacrostub.h"
#include "vmpermng.h"


extern vm_vsm_mem_struct g_vsm_mem_info[];
extern VMINT vm_get_sym_entry(char* symbol);
extern _vm_pcb_t* vm_alloc_pcb(VMWSTR filename, _vm_pcb_t* father, VMINT isRemoveDriver);
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern _vm_pcb_t* vm_pmng_get_pcb_by_status(VM_PROCESS_STATUS status);
extern VMINT * _vm_per_get_mre_fun_list(void);
extern VMINT vm_start_mre_envirment(vm_mre_evt_cb_t vam_cb, VMINT state);
extern void vm_pmng_stop_envirment(void);
extern VMINT vm_alloc_memory(VMUINT memSize);
extern VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount);
extern VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode );
extern VMINT vm_ce_merge_permission(VMWSTR filename);
extern void _vm_per_clear_mre_fun_list(void);
extern void vm_free_pcb(_vm_pcb_t* pcb);
extern VMINT vm_push_pcb_into_status_union(VM_PROCESS_STATUS status, _vm_pcb_t* pcb);
extern _vm_pcb_t* vm_pop_pcb_up_status_union(VM_PROCESS_STATUS status, VM_P_HANDLE pHandle);
extern void vm_free_memory(VMINT handle);

extern vm_sm_builtin_struct mre_buildin_vso_array[MRE_BUILDIN_VSO_COUNT];

/*****************************************************************************
 * FUNCTION
 *  vm_so_parse_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void vm_so_parse_symbol( VMINT8* strtab, vm_elf_symtbl_entry_t* st, vm_so_node_t* so_node)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_sym_node_t* node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( VM_ELF32_ST_BIND(st->st_info) == VM_STB_GLOBAL && VM_ELF32_ST_TYPE(st->st_info) == VM_STT_FUNC ) 
    {
		node = (vm_sym_node_t*)(&so_node->symbols[so_node->count]);
        node->symname = &strtab[st->st_name];
	 	node->address = (VMUINT)(so_node->sysv_node.sysv_base + st->st_value - so_node->sysv_node.sysv_virt);
	 	so_node->count++;
    }
}


static void _vm_so_list_insert(vm_so_node_t *node)
{
    _vm_pcb_t *father_pcb = node->pcb;
    
    node->next = father_pcb->soHeader;
    father_pcb->soHeader = node;
}

static void _vm_so_list_remove(vm_so_node_t *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t *father_pcb = node->pcb;
    vm_so_node_t **pptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pptr = &father_pcb->soHeader; *pptr; pptr = &((*pptr)->next)) 
    {
        if (*pptr == node) 
        {
            *pptr = node->next;
            return;
        }
    }
    return;
}


    
VMINT vm_so_read_file( vm_so_node_t* so_node)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_exec_format_enum suffix;
    VMINT rorw_zip;
    vm_file_type_enum file_type;
	vm_load_context_t context;
	vm_elf_symtbl_entry_t *syment;
	VMINT index;
	VMINT mem_idx;
	VMINT memSize, bufSize;
	VMINT lerr = 0, info = 0, ret = 0;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	suffix = vm_parse_exec_format(so_node->soname);
    if (suffix != VM_EXEC_ROM && suffix != VM_EXEC_VSO && suffix != VM_EXEC_DLL) {
        lerr = 1; info = suffix; goto unknown_type;
	}
	file_type = vm_get_file_type(so_node->soname);
    if (file_type != VM_VSO_RVCT && file_type != VM_VSO_GCC) {
        lerr = 2; info = file_type; goto unknown_type;
    }

    rorw_zip = 0; bufSize = 4;
    if (vm_get_vm_tag(so_node->soname, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize) != GET_TAG_TRUE) {
        rorw_zip = 0;
    }
    
    memset(&context, 0, sizeof(context));
    context.fileName = so_node->soname;
    context.suffix = suffix;
    context.rorw_zip = rorw_zip;
    context.file_type = file_type;
    context.asm_index = -1;
    context.preload_flags = VM_LOAD_PRELOAD_READ;
    ret = vm_load_normal(&context);
    if (ret != 0) {
        lerr = 3; info = ret; goto unknown_type;
    }
    
    memSize = context.roSize + context.rwSize + context.ziSize + so_node->heapSize;
    mem_idx = vm_alloc_memory(memSize);
    if (mem_idx < 0) {
        lerr = 4; info = mem_idx; goto unknown_type;
    }
    g_vsm_mem_info[mem_idx].p_handle = ((VMINT)so_node > 0) ? (VMINT)so_node : ((VMINT)so_node  * (-1));
    so_node->memIndex = mem_idx;
    
    context.asm_index = mem_idx;
    context.load_buffer = g_vsm_mem_info[mem_idx].mem_base;
    context.load_size   = g_vsm_mem_info[mem_idx].mem_size;
    context.preload_flags = 0;
    ret = vm_load_normal(&context);
    if (ret != 0) {
        lerr = 5; info = ret; goto free_asm;
    }
    
    // copy values from context into pcb
    so_node->codeBase = context.codeBase;
    so_node->codeSize = context.codeSize;
    so_node->dataBase = context.dataBase;
    so_node->dataSize = context.dataSize;
    so_node->heapBase = context.dataBase + context.dataSize;
    so_node->heapSize = (context.load_buffer + context.load_size) - so_node->heapBase;
    so_node->sysv_node = context.sysv_node;
    so_node->entry = context.entry;
    so_node->file_type = file_type;
    
    // parse export symbol table
    if (so_node->sysv_node.sysv_symtab_count) {
        if (so_node->sysv_node.sysv_dynstr == NULL) {
            lerr = 6; info = so_node->sysv_node.sysv_symtab_count; goto free_asm;
        }
        
        so_node->size = so_node->sysv_node.sysv_symtab_count;
        so_node->count = 0;
        so_node->symbols = _vm_kernel_malloc(sizeof(vm_sym_node_t) * so_node->size);
        if (so_node->symbols == NULL) {
            lerr = 7; goto free_asm;
        }
        syment = so_node->sysv_node.sysv_symtab;
        for (index = 0; index < so_node->size; index++, syment++) {
            vm_so_parse_symbol(so_node->sysv_node.sysv_dynstr, syment, so_node);
        }
    }
    
    return 0;
    
free_asm:
    vm_free_memory(g_vsm_mem_info[mem_idx].p_handle);
unknown_type:
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_01, lerr, info, ret);

    {
        static const VMINT err_map[] = { VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM,
             VM_PMNG_ERROR_PARAM, VM_PMNG_NO_MEM,  VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM, VM_PMNG_NO_MEM };
        if (lerr == 3 || lerr == 5) {
            return (ret == VM_LOAD_ERR_OOM) ? VM_PMNG_NO_MEM : VM_PMNG_ERROR_PARAM;
        }
        return err_map[lerr];
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_so_ws_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv         [IN]        
 *  name        [IN]        
 *  wname       [IN]        
 *  wlen        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_so_get_path(VMINT drv, VMWSTR name, VMWSTR wname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT find_hdl;
	struct vm_fileinfo_t info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#ifndef MRE_ON_MODIS
	kal_wsprintf(wname, "%c:\\mre\\%w.vso", drv, name);
#else
	kal_wsprintf(wname, "%c:\\mre\\%w.dlo", drv, name);
#endif
	if((find_hdl = vm_find_first(wname, &info)) >= 0)
	{
		vm_find_close(find_hdl);
		return TRUE;
	}
	return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_so_load_file
 * DESCRIPTION
 *  load so file
 * PARAMETERS
 *  filename : [IN] so file name encoding with UCS format.
 * RETURNS
 *  load so result.
 *****************************************************************************/
VMINT vm_so_load_file(VMWSTR fileName,_vm_pcb_t* father_pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_so_node_t* node;
	VMINT bufSize, ret = -1;
	
#ifdef __MRE_CORE_SAFETY__
	VMINT certres = -1;
	VMUCHAR*  cert_buff;
	VMINT buflen = 3072;		
#endif
	VMCHAR tmp_buf[24];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	node = (vm_so_node_t*)_vm_kernel_calloc(sizeof(vm_so_node_t));

	if( node == NULL )
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_02);
		return VM_PMNG_NO_MEM;
	}

	if (kal_wstrchr(fileName, '\\') == NULL)
	{
		if (!vm_so_get_path(vm_get_removeable_driver(), fileName, node->soname) )
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_03);
			if (!vm_so_get_path(vm_get_system_driver(), fileName, node->soname) )
			{			
				VMUINT i,appcount,smcount,socount;
				VMWCHAR tempName[64];
				VMCHAR tempName1[64];
				
				MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_04);

				vm_init_default_game(&appcount, &smcount, &socount);
				
				for(i = 0; i < socount; i++)
				{
					vm_ascii_to_ucs2((VMWSTR)tempName, 64, (VMSTR)mre_buildin_vso_array[i].file_name);
					if(kal_wstrcmp(tempName, fileName) == 0)
					{
						sprintf(tempName1, "%c:\\%u.rom", 64, mre_buildin_vso_array[i].address);
						vm_ascii_to_ucs2((VMWSTR)node->soname, 64, (VMSTR) tempName1);
						return VM_SO_SUCCESS;
					}
				}
				
				MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_05);

				return VM_SO_FILE_NOT_FOUND;
			}
		}
	}
	else
	{
		vm_wstrcpy(node->soname, fileName);
	}
	
#ifdef __MRE_CORE_SAFETY__
	if ((cert_buff = (VMUCHAR* )_vm_kernel_malloc(buflen)) == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_06);
		return -1;
	}
			
	certres = vm_ce_auth_app_ex(node->soname, cert_buff, buflen, VERIFY_FULL);
	_vm_kernel_free(cert_buff);
	if (certres < VM_CE_VERIFY_OK )
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_07, certres);
		return certres;
	}
#endif	

#ifndef MRE_ON_MODIS
	ret = vm_so_read_file( node );

	if( ret < 0)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_08, ret);
		return ret;
	}
#else
    node->memIndex = vm_alloc_memory(1024*500);
    node->heapBase = g_vsm_mem_info[node->memIndex].mem_base;
    node->heapSize = 1024*500;
#endif

    node->pcb = father_pcb;
    _vm_so_list_insert(node);
	node->base_name = (VMWSTR)wcsrchr((wchar_t *)node->soname, L'\\');
	if (node->base_name != NULL)
	{
	    node->base_name++;
	}
	else
	{
	    node->base_name = node->soname;
	}
	bufSize = 24;
	if (vm_get_vm_tag(node->soname, VM_CE_INFO_ISSUE, (void *)tmp_buf, &bufSize) == GET_TAG_TRUE)
	{
	    node->build_id = (tmp_buf[4] << 24) + (tmp_buf[8] << 16) + (tmp_buf[12] << 8) + tmp_buf[16];
	}
	else
	{
	    node->build_id = 0;
	}
	node->dtype = DEBUG_SHARED_OBJECT;
	    
#ifndef MRE_ON_MODIS
	if(node->file_type == VM_VSO_RVCT)
	{
		typedef VMINT (*vm_rvct_so_entry_fp)(VMUINT symtab);
		vm_rvct_so_entry_fp so_entry;
		so_entry = (vm_rvct_so_entry_fp)(node->entry);
		so_entry((VMUINT)vm_get_sym_entry);
	}
	else if(node->file_type == VM_VSO_GCC)
	{
		typedef VMINT (*vm_gcc_so_entry_fp)(VMUINT symtab, VMUINT address, VMUINT count);
		vm_gcc_so_entry_fp so_entry;

		so_entry = (vm_gcc_so_entry_fp)(node->entry);
		so_entry((VMUINT)vm_get_sym_entry, (VMUINT)node->sysv_node.sysv_init_array, node->sysv_node.sysv_init_count);
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_09);
	}
#else
	node->memIndex = vm_entry_vso(node->soname, (unsigned int)vm_get_sym_entry);
#endif

	if (node->sysEventHandler)
	{
		node->sysEventHandler(VM_SO_MSG_LOAD, 0);
	}
	
    return node->memIndex;
	
}


/*****************************************************************************
 * FUNCTION
 *  vm_so_free_mem
 * DESCRIPTION
 *  l
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void vm_so_free_mem(vm_so_node_t* node)
{
   if(node->symbols != NULL)
   {
	   _vm_kernel_free(node->symbols);
   }
   
#ifdef __MRE_MEDIA_BUF__ /* PHASE OUT! */
   if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
   {
	   media_free_ext_buffer(MOD_MMI, (void**)&g_vsm_mem_info[node->memIndex].mem_base);
	   g_vsm_mem_info[node->memIndex].mem_base = NULL;
	   g_vsm_mem_info[node->memIndex].mem_size = 0;
	   g_vsm_mem_info[node->memIndex].p_handle = -1;
   }
   else
#endif
   {
	   applib_mem_ap_free((void*)g_vsm_mem_info[node->memIndex].mem_base);
	   g_vsm_mem_info[node->memIndex].mem_base = NULL;
	   g_vsm_mem_info[node->memIndex].mem_size = 0;
	   g_vsm_mem_info[node->memIndex].p_handle = -1;
   }
   
   _vm_so_list_remove(node);
   _vm_kernel_free(node);

}


/*****************************************************************************
 * FUNCTION
 *  vm_load_library
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_load_library(VMSTR name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret = -1;
	_vm_pcb_t* pcbPtr = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	VMWCHAR w_name[MAX_APP_NAME_LEN+1];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(name == NULL || strlen(name) == 0 || strlen(name) > MAX_APP_NAME_LEN)
		return VM_SO_PARAM_ERROR;
	
	if ((pcbPtr = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
	{
		vm_ascii_to_ucs2((VMWSTR)w_name, MAX_APP_NAME_LEN, (VMSTR)name);
		ret = vm_so_load_file(w_name,pcbPtr);		
	}
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_10, name, ret );

	return ret;
	
}

/*****************************************************************************
 * FUNCTION
 *  vm_load_libraryw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_load_libraryw(VMWSTR name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT ret = -1;
	_vm_pcb_t* pcbPtr = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if ( kal_wstrlen(name)>MAX_APP_NAME_LEN )
		return VM_SO_PARAM_ERROR;
	
	if ((pcbPtr = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
	{
		ret = vm_so_load_file(name, pcbPtr);		
	}
	
	return ret;
	
}


/*****************************************************************************
 * FUNCTION
 *  vm_free_library
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_free_library(VMINT handle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcbPtr = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	VMINT total_count = 0;
	VMINT free_count = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MRE_ON_MODIS
	if ((pcbPtr = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
	{
		vm_so_node_t* nodePtr;

		nodePtr = pcbPtr->soHeader;
		
		while(nodePtr != NULL)
		{
			total_count++;
			
			if(nodePtr->handle == handle)
			{
				free_count++;
				vm_so_free_mem(nodePtr);
			}
			
			nodePtr = nodePtr->next;
		}

		if( (total_count == 1) && free_count)
		{
			pcbPtr->soHeader = NULL;
		}
	}
	
	return -1;
#else
	vm_unload_vso(handle);
#endif
	
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_symbol(VMINT handle, VMSTR name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcbPtr = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MRE_ON_MODIS
	if ((pcbPtr = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
	{
		vm_so_node_t* nodePtr;
		VMUINT j;

		nodePtr = pcbPtr->soHeader;

		while(nodePtr != NULL)
		{
			if(nodePtr->handle == handle)
			{
				for(j = 0; j < nodePtr->count; j++ )
				{
					if(strcmp(nodePtr->symbols[j].symname, name) == 0)
					{
						MMI_TRACE(MMI_MRE_TRC_MOD_VMSO, TRC_MRE_VMSO_11, name);
						return nodePtr->symbols[j].address;
					}
				}
				
			}
			nodePtr = nodePtr->next;
		}
	}

	return -1;
#else
	return vm_get_so_sym(handle, name);
#endif
	
}

#endif


