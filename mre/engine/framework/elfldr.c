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
 * elfldr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * elfldr
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#include <string.h>
#include "vmsys.h"
#include "vmio.h"
#include "elfldr.h"
#include "elf.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "vmpromnginner.h"
#include "vmmem.h"
#include "vmstdlib.h"

#ifdef WIN32
#define __packed
#endif

/*****************************************************************************
 * FUNCTION
 *  vm_get_symbol_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT8*
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_symbol_value( vm_app_node_t* app_node, VMFILE handle, VMINT16 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT readed;
	VMINT16 length;
    vm_elf_symtbl_entry_t    symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	length = sizeof(vm_elf_symtbl_entry_t);
    MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_193 );

	if(app_node->rorw_zip)
	{
		memcpy( &symbol, (void*)(app_node->imageBase + app_node->relsec.sh_offset + index * length), length );
		return symbol.st_value - app_node->virtualAddress; 
	}
	else
	{
		vm_file_seek(handle, app_node->relsec.sh_offset + index * length, BASE_BEGIN);
	
		if (vm_file_read(handle, &symbol, length, &readed) == readed)
		{
    		MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_206 , &app_node->relstr.s_tab[symbol.st_name] );
			return symbol.st_value - app_node->virtualAddress; 
		}
		else
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_211 );
			vm_file_close(handle);
			return 0;
		}	 
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_symbol_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT8*
 * RETURNS
 *  
 *****************************************************************************/
VMINT8* vm_get_symbol_name( vm_app_node_t* app_node, VMFILE handle, VMINT16 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT readed;
	VMINT16 length;
    vm_elf_symtbl_entry_t    symbol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	length = sizeof(vm_elf_symtbl_entry_t);
    MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_193 );

	if(app_node->rorw_zip)
	{
		memcpy( &symbol, (void*)(app_node->imageBase + app_node->relsec.sh_offset + index * length), length );
		return &app_node->relstr.s_tab[symbol.st_name] ; 
	}
	else
	{
		vm_file_seek(handle, app_node->relsec.sh_offset + index * length, BASE_BEGIN);
	
		if (vm_file_read(handle, &symbol, length, &readed) == readed)
		{
    		MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_206 , &app_node->relstr.s_tab[symbol.st_name] );
			return &app_node->relstr.s_tab[symbol.st_name] ; 
		}
		else
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_211 );
			vm_file_close(handle);
			return NULL;
		}	 
	}
	
}

/*****************************************************************************
 * FUNCTION
 *  vm_parse_dynrel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb             [?]         
 *  app_node        [?]         
 *  handle          [IN]        
 *  rel             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void vm_parse_dynrel( _vm_pcb_t* pcb, vm_app_node_t* app_node, VMFILE handle, vm_elf_rel_t* rel )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT8 type;
	VMUINT symbol;
	VMINT8* name = NULL;
	VMUINT* address;
	vm_sym_node_t* node;
	VMUINT index;
	vm_so_node_t* so_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = VM_ELF32_R_TYPE(rel->r_info);
	symbol = VM_ELF32_R_SYM(rel->r_info);
	
	switch (type) 
	{
	case VM_R_ARM_CALL:
		break; 
		
	case VM_R_ARM_JUMP24:
		break;
		
	case VM_R_ARM_ABS32:
	case VM_R_ARM_GLOB_DAT:
		{
			address = (VMUINT*)(app_node->imageBase + rel->r_offset - app_node->virtualAddress );
			*(int*)address = *(int*)address + (VMINT)app_node->imageBase + vm_get_symbol_value(app_node, handle, symbol);
		}
		break;
	case VM_R_ARM_JUMP_SLOT:
		if(pcb->soHeader == NULL)
		{
			return;
		}
		
		name = vm_get_symbol_name( app_node, handle, symbol );

		if( name != NULL )
		{
			address = (VMUINT*)(app_node->imageBase + rel->r_offset);
			
			MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_280 ,name, rel->r_offset, address);
			
			so_node = pcb->soHeader;
			
			while( so_node != NULL )
			{
				for( index = 0; index < so_node->count; index++ )
				{
					node = (vm_sym_node_t*)( &so_node->symbols[index]);
												
					if( strcmp( name, node->symname ) == 0 )
					{
						MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_292  ); 
						*address = (VMUINT)node->address;
						break;
					}
				}

				so_node = so_node->next;
			}
		}

		break;
	case VM_R_ARM_RELATIVE:
		{
			address = (VMUINT*)(app_node->imageBase + rel->r_offset - app_node->virtualAddress );
			*address = (VMUINT)app_node->imageBase + (*address) - app_node->virtualAddress;
		}

		break;
	default:
		break;
	}
	
}

VMINT vm_resolve_symbol_sysv( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, VMUINT symbol, VMUINT *abs_value)
{
    vm_elf_symtbl_entry_t *syment;
    char *symname; 
    int found = 0;
    const vm_so_node_t *so_node;
    VMINT index;
    
    if (symbol == 0 /*STN_UNDEF*/) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE1);
        return -1;
    }
    
    if (symbol >= exe_node->sysv_symtab_count) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE2, symbol, exe_node->sysv_symtab_count);
        return -2;
    }
    
    syment = exe_node->sysv_symtab + symbol;
    symname = exe_node->sysv_dynstr + syment->st_name;
    
    if (syment->st_shndx != VM_SHN_UNDEF) {
        *abs_value = syment->st_value + (VMUINT)(exe_node->sysv_base - exe_node->sysv_virt);
        return 0;
    }
    
    for (so_node = so_list; so_node; so_node = so_node->next) {
        /* search in whole symbol table, not just global function */
        vm_elf_symtbl_entry_t *ent = so_node->sysv_node.sysv_symtab;
        for (index = 1; index < so_node->sysv_node.sysv_symtab_count; index++, ent++) {
            if (ent->st_shndx == VM_SHN_UNDEF || VM_ELF32_ST_BIND(ent->st_info) != VM_STB_GLOBAL) {
                // ignore undefined or non-global symbols
                continue;
            }
            if (strcmp(symname, so_node->sysv_node.sysv_dynstr + ent->st_name) == 0) {
                *abs_value = ent->st_value + (VMUINT)(so_node->sysv_node.sysv_base - so_node->sysv_node.sysv_virt);
                found = 1;
                break;
            }
        }
        if (found) {
            return 0;
        }
    }
    
    if (VM_ELF32_ST_BIND(syment->st_info) == VM_STB_WEAK) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE3);
        return 0;
    }
    else {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RESOLVE4, symbol);
        return -3;
    }
}

VMINT vm_parse_sysv_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel )
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT8 type;
	VMUINT symbol;
    VMUINT *fix_address;
    VMINT ret;
    VMUINT symvalue;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	type = VM_ELF32_R_TYPE(rel->r_info);
	symbol = VM_ELF32_R_SYM(rel->r_info);
	
	fix_address = (VMUINT *)(exe_node->sysv_base + rel->r_offset - exe_node->sysv_virt);
	
	switch (type) 
	{
	default:
	case VM_R_ARM_CALL:  /* R_ARM_CALL is not a dynamic relocation in aaelf.pdf */
	case VM_R_ARM_JUMP24:/* R_ARM_JUMP24 is not a dynamic relocation in aaelf.pdf */
	    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC1, type);
		return -1;
		 
	case VM_R_ARM_COPY:  /* R_ARM_COPY is a dynamic relocation, but we can't support it */
	    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC2, type);
	    return -2;
	    
	case VM_R_ARM_RELATIVE:
		*fix_address += (VMUINT)(exe_node->sysv_base - exe_node->sysv_virt);
		return 0;
		
	case VM_R_ARM_ABS32:   /* R_ARM_ABS32 is not a dynamic relocation in aaelf.pdf */
	case VM_R_ARM_GLOB_DAT:
	case VM_R_ARM_JUMP_SLOT:
	    ret = vm_resolve_symbol_sysv(exe_node, so_list, symbol, &symvalue);
	    if (ret == 0) {
	        *fix_address += symvalue;
	        return 0;
	    }
	    else {
	        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_ELFLDR_RELOC3, symbol, ret);
	        return -3;
	    }
	}
}

VMINT vm_parse_sysv_ro_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel, VMUINT roSize )
{
    VMUINT fix_address;
    
    fix_address = (VMUINT)(exe_node->sysv_base + rel->r_offset - exe_node->sysv_virt);
    if (fix_address >= (VMUINT)exe_node->sysv_base + roSize) {
        return 0;
    }
    return vm_parse_sysv_reloc(exe_node, so_list, rel);
}

VMINT vm_parse_sysv_rw_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel, VMUINT roSize )
{
    VMUINT fix_address;
    
    fix_address = (VMUINT)(exe_node->sysv_base + rel->r_offset - exe_node->sysv_virt);
    if (fix_address < (VMUINT)exe_node->sysv_base + roSize) {
        return 0;
    }
    return vm_parse_sysv_reloc(exe_node, so_list, rel);
}


/*****************************************************************************
 * FUNCTION
 *  get_elf_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_table        [?]         
 *  table_size          [IN]        
 *  index               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *get_elf_string(char *string_table, int table_size, int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return string_table + index;
}


/*****************************************************************************
 * FUNCTION
 *  open_elf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  handle          [?]         
 * RETURNS
 *  
 *****************************************************************************/
int open_elf(VMWSTR filename, vm_elf_handle_t *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((handle->file = vm_file_open(filename, MODE_READ, TRUE)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_365 );
        return VM_EX_IOERR;
    }
        
    if ((nread = vm_file_read(handle->file, &handle->elf_head, 
        sizeof(vm_elf_head_t), &nread)) != sizeof(vm_elf_head_t)) 
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_372 ,
            handle->file, sizeof(vm_elf_head_t), nread);
        vm_file_close(handle->file);
        return VM_EX_FMTERR;
    }
    
    if ((handle->elf_head.e_ident[0] != 0x7f) ||
        (handle->elf_head.e_ident[1] != 'E') ||
        (handle->elf_head.e_ident[2] != 'L') ||
        (handle->elf_head.e_ident[3] != 'F'))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_383 );
        vm_file_close(handle->file);
        return VM_EX_FMTERR;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  close_elf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 * RETURNS
 *  
 *****************************************************************************/
int close_elf(vm_elf_handle_t *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_IOERR;
        
    vm_file_close(handle->file);
    handle->file = -1;
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  read_elf_prog_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 *  head        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int read_elf_prog_head(vm_elf_handle_t *handle, vm_elf_prog_head_t *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;
    VMUINT phnum;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_IOERR;

    for ( phnum = 0; phnum < handle->elf_head.e_phnum; phnum++ )
    {
        vm_file_seek( handle->file, handle->elf_head.e_phoff + phnum * sizeof( vm_elf_prog_head_t ), BASE_BEGIN );
            
        if ( vm_file_read( handle->file, head, sizeof( vm_elf_prog_head_t ),&nread ) != sizeof( vm_elf_prog_head_t ) )
        {
                return VM_EX_IOERR;
        }
        else
        {
            if(head->p_type == VM_PT_LOAD)
                break;
        }
    }
        
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  read_elf_prog_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 *  head        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int read_elf_prog_head_by_index(vm_elf_handle_t *handle, int idx, vm_elf_prog_head_t *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_IOERR;

    if (idx >= handle->elf_head.e_phnum)
    {
        return VM_EX_FMTERR;
    }
    
    vm_file_seek( handle->file, handle->elf_head.e_phoff + idx * sizeof( vm_elf_prog_head_t ), BASE_BEGIN );
    if ( vm_file_read( handle->file, head, sizeof( vm_elf_prog_head_t ),&nread ) != sizeof( vm_elf_prog_head_t ) )
    {
            return VM_EX_IOERR;
    }
        
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  read_elf_section_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]         
 *  idx         [IN]        
 *  head        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int read_elf_section_head(vm_elf_handle_t *handle, int idx, vm_elf_section_head_t *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_IOERR;
        
    if (idx < handle->elf_head.e_shnum) {
        vm_file_seek(handle->file, handle->elf_head.e_shoff + idx * 
            handle->elf_head.e_shentsize, BASE_BEGIN);
        if (vm_file_read(handle->file, head, sizeof(vm_elf_section_head_t), 
            &nread) != sizeof(vm_elf_section_head_t))
            return VM_EX_IOERR;
    }
    else {
        return VM_EX_FMTERR;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  get_elf_section_head_by_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [?]         
 *  str_tab         [?]         
 *  tab_size        [IN]        
 *  sh              [?]         
 *  sh_num          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
vm_elf_section_head_t *get_elf_section_head_by_name(
                        char *name,
                        char *str_tab,
                        int tab_size,
                        vm_elf_section_head_t *sh,
                        int sh_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
	vm_elf_section_head_t temp;

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sh_num; i++) {
		vm_memcpy((void*)&temp,(void*)&sh[i],sizeof(vm_elf_section_head_t));
        if (strcmp(name, get_elf_string(str_tab, tab_size,
            temp.sh_name)) == 0)
            return sh + i;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  read_elf_section_head_by_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [?]         
 *  name                [?]         
 *  string_table        [?]         
 *  table_size          [IN]        
 *  head                [?]         
 * RETURNS
 *  
 *****************************************************************************/
int read_elf_section_head_by_name(
        vm_elf_handle_t *handle,
        char *name,
        char *string_table,
        int table_size,
        vm_elf_section_head_t *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_FMTERR;

    for (i = 0; i < handle->elf_head.e_shnum; i++) {
        if (read_elf_section_head(handle, i, head) == 0) {
            if (strcmp(name, get_elf_string(string_table, table_size, 
                head->sh_name)) == 0)
                return 0;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  read_elf_section
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     
 *  head        [?]     
 *  buf         [?]     
 * RETURNS
 *  
 *****************************************************************************/
int read_elf_section(vm_elf_handle_t *handle, vm_elf_section_head_t *head, void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->file < 0)
        return VM_EX_FMTERR;

    vm_file_seek(handle->file, head->sh_offset, BASE_BEGIN);
    if (vm_file_read(handle->file, buf, head->sh_size, &nread) == head->sh_size)
        return 0;
    else
        return VM_EX_IOERR;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
vm_file_type_enum vm_get_file_type(VMWSTR filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT liner_type;
    VMINT buffSize = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_get_vm_tag(filename, VM_CE_INFO_FILE_TYPE, (void*)&liner_type, &buffSize) != GET_TAG_TRUE)
    {
        return VM_VXP_ADS;
    }
    else
    {
        return (vm_file_type_enum)liner_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_section_info_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  p_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_section_info_from_file(VMWSTR filename, vm_simple_elf_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_file_type_enum file_type;
    VMUINT nread;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( p_info == NULL )
	{
		return -1;
	}
	
    file_type = vm_get_file_type(filename);

    if(file_type  == VM_SIMPLE_VXP_ADS)
    {
        VMFILE file;
        VMUINT offset;
        VMUINT tatal_size;

        if ((file = vm_file_open(filename, MODE_READ, TRUE)) >= 0) 
        {
            /* get attachment offset */
            if (vm_file_seek(file, -0x0C, BASE_END) == 0)
            {
                if(vm_file_read(file, &offset, 4, &nread) == 4)
                {
                    /* get offset of size */
                    if (vm_file_seek(file, offset - 0x04, BASE_BEGIN) == 0)
                    {
                        if(vm_file_read(file, &tatal_size, 4, &nread) == 4)
                        {
                            if(sizeof(vm_simple_elf_info) == tatal_size)
                            {
                                if (vm_file_seek(file, offset - tatal_size -  0x04 , BASE_BEGIN) == 0)
                                {
                                    if(vm_file_read(file, p_info, tatal_size, &nread) == tatal_size)
                                    {
										vm_file_close(file);
                                    	return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        vm_file_close(file);
    }
    else
    {
        vm_elf_handle_t handle;
        vm_elf_prog_head_t ph;
        vm_elf_section_head_t str_sh, rw_sh, ro_sh;
        char* str_tab;

        if (open_elf(filename, &handle) == 0) 
        {
            if (read_elf_prog_head(&handle, &ph)== 0) 
            {
                if (read_elf_section_head(&handle, handle.elf_head.e_shstrndx, &str_sh) == 0)
                {
                    if ((str_tab =  _vm_kernel_malloc(str_sh.sh_size)) != NULL) 
                    {
                        if (read_elf_section(&handle, &str_sh, str_tab)== 0) 
                        {
                            if (read_elf_section_head_by_name(&handle, "ER_RW",str_tab, str_sh.sh_size, &rw_sh) == 0)
                            {
                                p_info->rw_offset = rw_sh.sh_offset;
                                p_info->rw_size = rw_sh.sh_size;
								p_info->org_rw_size = rw_sh.sh_size;
                            }

                            if (read_elf_section_head_by_name(&handle, "ER_RO",str_tab, str_sh.sh_size, &ro_sh) == 0)
                            {
                                p_info->ro_offset = ro_sh.sh_offset;
                                p_info->ro_size = ro_sh.sh_size;
								p_info->org_ro_size = ro_sh.sh_size;
                            }

                            p_info->zi_size = ph.p_memsz - ph.p_filesz;
                        }
                    }
                }
            }
        }

        close_elf(&handle);
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_section_info_from_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image           [?]     
 *  p_info       [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_section_info_from_rom(VMUINT8* image, vm_simple_elf_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT liner_type;
    VMINT buffSize = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( p_info == NULL )
	{
		return -1;
	}
	
	if (vm_get_vm_tag_from_rom(image, VM_CE_INFO_FILE_TYPE, (void*)&liner_type, &buffSize) != GET_TAG_TRUE)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ELFLDR, TRC_MRE_ELFLDR_793 , VM_VXP_ADS);
        liner_type = VM_VXP_ADS;
    }

    if(liner_type  == VM_SIMPLE_VXP_ADS)
    {
        VMUINT offset;
        VMUINT tatal_size;
		VMUINT rom_size = *(__packed VMUINT*)image;

		offset = *(__packed VMUINT*)(image + 4 + rom_size - 0x0C);

		tatal_size = *(__packed VMUINT*)(image + 4 + offset - 0x04);

		if(sizeof(vm_simple_elf_info) == tatal_size)
		{
			memcpy(p_info,(void*)(image + 4 + offset - tatal_size - 0x04),tatal_size);
        }		
    }
    else
    {
        vm_elf_head_t *head;
        vm_elf_prog_head_t* ph;
        vm_elf_section_head_t *str_sh, *rw_sh, *ro_sh;
        VMCHAR *str_tab;
        VMUINT8* imagePtr= image;
		VMINT str_offset;
		VMINT str_size;
		VMINT ro_offset;
		VMINT ro_size;
		VMINT rw_offset;
		VMINT rw_size;

        head = (vm_elf_head_t*)imagePtr;
        ph = (vm_elf_prog_head_t*)(imagePtr + head->e_phoff);
		

        str_sh = (vm_elf_section_head_t*)(imagePtr + head->e_shoff +
                (head->e_shstrndx * head->e_shentsize));

		vm_memcpy((void*)&str_offset, (void*)&str_sh->sh_offset, 4);
		vm_memcpy((void*)&str_size, (void*)&str_sh->sh_size, 4);

		
        str_tab = (char*)(imagePtr + str_offset);

        ro_sh = get_elf_section_head_by_name("ER_RO", str_tab, str_size, 
                (vm_elf_section_head_t*)(imagePtr + head->e_shoff), head->e_shnum);

		vm_memcpy((void*)&ro_offset, (void*)&ro_sh->sh_offset, 4);
		vm_memcpy((void*)&ro_size, (void*)&ro_sh->sh_size, 4);

        p_info->ro_offset = ro_offset;
        p_info->ro_size = ro_size;
        p_info->org_ro_size = ro_size;    
		
        rw_sh = get_elf_section_head_by_name("ER_RW", str_tab, str_size,
                    (vm_elf_section_head_t*)(imagePtr + head->e_shoff),head->e_shnum);

		vm_memcpy((void*)&rw_offset, (void*)&rw_sh->sh_offset, 4);
		vm_memcpy((void*)&rw_size, (void*)&rw_sh->sh_size, 4);

        p_info->rw_offset = rw_offset;
        p_info->rw_size = rw_size;
		p_info->org_rw_size = rw_size;
        p_info->zi_size = 	ph->p_memsz - ph->p_filesz;
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_compress_info_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  p_info       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_compress_info_from_file(VMWSTR filename, vm_compress_elf_info *p_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT nread;
	VMFILE file;
	VMUINT offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( p_info == NULL )
	{
		return -1;
	}
	
    if ((file = vm_file_open(filename, MODE_READ, TRUE)) >= 0) 
    {
        /* get attachment offset */
        if (vm_file_seek(file, -0x0C, BASE_END) == 0)
        {
            if(vm_file_read(file, &offset, 4, &nread) == 4)
            {
                /* get offset of size */
                if (vm_file_seek(file, offset - 0xc, BASE_BEGIN) == 0)
                {
                    if(vm_file_read(file, p_info, 0xc, &nread) ==  0xc)
                    {
						vm_file_close(file);
                        return 0;
                    }
                }
            }
        }
    }

	return 0;
}

VMINT vm_get_compress_info_from_rom(VMUINT8* image, vm_compress_elf_info *p_info)
{
    VMUINT offset;
	VMUINT rom_size = *(__packed VMUINT*)image;
	
	offset = *(__packed VMUINT*)(image + 4 + rom_size - 0x0C);
	vm_memcpy(p_info, (void *)(image + 4 + offset - 0xc), sizeof(*p_info));
	
	return 0;
}

#endif /* __MRE_CORE_BASE__ */ 

