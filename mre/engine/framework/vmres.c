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

/*******************************************************************************
 * Filename:
 * ---------
 *  vmres.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MRE application resource
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "vmswitch.h"

#ifdef __MRE_LIB_APPRES__
#include "App_mem.h"
#include <string.h>
#include <stdlib.h>
#include "vmio.h"
#include "vmres.h"
#include "elfldr.h"
#include "vmchset.h"
#include "vmdl.h"
#include "vmsys.h"
#include "elf.h"
#include "vmlog.h"
#include "vmsm.h"
#include "vmopt.h"
#include "vmpromnginner.h"
#include "vmstdlib.h"
#include "vmgettag.h"
#include "vmcert.h"
#include "vm4res.h"
#include "fs_type.h"
#include "fs_func.h"
#include "gdi_const.h"
#include "vmresmng.h"
#include "vmmem.h"

//#define __MMI_MRE_SWLA_DEBUG__
extern vm_app_mem_struct g_app_mem_info[];
extern VMINT _vm_sb_stack_push(VMINT r9);
extern VMINT _vm_sb_stack_pop(void);


#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


#ifdef WIN32
#define __packed
#endif

typedef struct {
    VMUINT8 img_offset_type;
    VMUINT8 img_real_type;
} vm_img_map_type;

static const vm_img_map_type g_vm_img_type_map[] = {
    {GDI_IMAGE_TYPE_BMP_FILE_OFFSET, GDI_IMAGE_TYPE_BMP},
	{GDI_IMAGE_TYPE_GIF_FILE_OFFSET, GDI_IMAGE_TYPE_GIF},
    {GDI_IMAGE_TYPE_JPG_FILE_OFFSET, GDI_IMAGE_TYPE_JPG},
    {GDI_IMAGE_TYPE_PNG_FILE_OFFSET, GDI_IMAGE_TYPE_PNG},
    {GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET, GDI_IMAGE_TYPE_DEVICE_BITMAP},
    {GDI_IMAGE_TYPE_WBMP_FILE_OFFSET, GDI_IMAGE_TYPE_WBMP},
    {GDI_IMAGE_TYPE_M3D_FILE_OFFSET, GDI_IMAGE_TYPE_M3D},
    {GDI_IMAGE_TYPE_SVG_FILE_OFFSET, GDI_IMAGE_TYPE_SVG},
    {GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET, GDI_IMAGE_TYPE_SWFLASH},
    {GDI_IMAGE_TYPE_ABM_FILE_OFFSET, GDI_IMAGE_TYPE_ABM},
    {GDI_IMAGE_TYPE_AB2_FILE_OFFSET, GDI_IMAGE_TYPE_AB2},
    {GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET, GDI_IMAGE_TYPE_9SLICE},
    {GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_BMP_SEQUENCE},
    {GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE},
    {GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_JPG_SEQUENCE},
	{GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_PNG_SEQUENCE},
	{GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_ABM_SEQUENCE},
    {GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_AB2_SEQUENCE}
    };

static VMINT32 vm_res_init_string_with_language(VMUINT8 *v4res, VMUINT32 language);
static VMUINT32 vm_res_get_offset(VMUINT32 id, VMUINT8 *v4res, VMUINT32 *size);


#define VM_RES_CHECK_MEM_ALLOC(x) {if (x == NULL){/* log error */ return VM_RES_OUT_OF_MEM;}}

static VMUINT8 *vm_res_id_search(VMUINT32 id, VMUINT32* res_size);
static VMINT32 vm_res_id_add(VMUINT32 id, VMUINT8 *res_data, VMUINT32 res_size);
VMINT32 vm_res_id_delete_all(VMINT is_rom);

static VMINT32 vm_res_get_long(VMUINT8 *v4res);

extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern VMWSTR vm_get_self_filename(void);
extern _vm_sm_t * _vm_sm_list_find(VMINT type, VMINT value);
extern VMINT vm_check_buildin_app(VMUINT8* ptr);

static VMFILE open_elf_file_for_load(VMWSTR filename, VMUINT* res_offset);
static VMINT get_res_offset(VMFILE file, char* res_name, VMINT* res_size);
static VMINT get_res_offset_from_mem(VMUINT8 *ptr, char* res_name, VMINT* res_size);

static VMUINT8* _vm_load_resource(VMWSTR filename, char *res_name, VMINT *res_size, void* buffer, VMINT* offset, VMBOOL is_load);

static void strtolow( VMCHAR * pStr );

/*****************************************************************************
 * FUNCTION
 *  _vm_load_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  res_name        [?]         
 *  res_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 *_vm_load_resource(VMWSTR filename, char *res_name, VMINT *res_size, void* buffer, VMINT* offset, VMBOOL is_load)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	char *str_tab;
	VMFILE file;
	VMINT offset_temp;
	VMINT res_offset = 0;
	VMUINT nread;
	VMUINT8* res = NULL;
	VMUINT8* ptr = NULL;
	vm_elf_head_t *head;
	vm_elf_section_head_t *res_sh, *str_sh;
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_pcb_t* pcb = NULL;
	_vm_sm_t * sm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (filename == NULL)
		return NULL;
	
	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > (MAX_APP_NAME_LEN + 1))
		return NULL;

	if (vm_parse_exec_format(filename) == VM_EXEC_ROM)
	{
		vm_file_type_enum file_type;

		ptr = vm_get_execrom_ptr(filename);
		
		if (ptr == NULL || !vm_check_buildin_app(ptr))
		{
			return NULL;
		}

		if(*offset != 0 && buffer != NULL && *res_size != 0 && is_load == TRUE)
		{
			memcpy(buffer, ptr + *offset, *res_size);
			return buffer;
		}
		
		file_type = vm_get_file_type(filename);

		if(file_type  == VM_SIMPLE_VXP_ADS)
		{
			VMUINT tatal_size;
			vm_simple_elf_info info;
			VMUINT rom_size = *(__packed VMINT*)(ptr - 4);

			offset_temp = *(__packed VMINT*)(ptr + rom_size - 0x0C);

			tatal_size = *(__packed VMINT*)(ptr + offset_temp - 0x04);

			if(sizeof(vm_simple_elf_info) == tatal_size)
			{
				memcpy(&info,(ptr + offset_temp - tatal_size - 0x04),tatal_size);
				
				if(res_size != NULL)
				{
					*res_size = info.res_size;
				}

				res_offset = info.res_offset;

				
				if(strcmp(res_name,"mre-2.0") == 0)
				{
					if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
					{
						pcb->res_offset = res_offset;
					}
					if((sm_ptr	= _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) != NULL)
					{
						sm_ptr->res_offset = res_offset;
					}
				}

				offset_temp = get_res_offset_from_mem(ptr + info.res_offset,
					res_name, res_size);
					
				if(offset_temp>-1)
				{
					offset_temp = res_offset + offset_temp;
				}
			}
		}
		else
		{
			VMINT sh_offset;
			VMINT sh_size;
			VMUINT e_shoff;
			VMUINT16 e_shstrndx;
			VMUINT16 e_shentsize;
			VMUINT16 e_shnum;
			VMINT rorw_zip = 0;
			VMINT bufSize = 4;

			head = (vm_elf_head_t*)ptr;
			vm_memcpy((void*)&e_shoff,(void*)&head->e_shoff,sizeof(VMUINT));
			vm_memcpy((void*)&e_shstrndx,(void*)&head->e_shstrndx,sizeof(VMUINT16));
			vm_memcpy((void*)&e_shentsize,(void*)&head->e_shentsize,sizeof(VMUINT16));
			vm_memcpy((void*)&e_shnum,(void*)&head->e_shnum,sizeof(VMUINT16));

			str_sh = (vm_elf_section_head_t*)(ptr + e_shoff +(e_shstrndx * e_shentsize));
			vm_memcpy((void*)&sh_offset,(void*)&str_sh->sh_offset,4);
			vm_memcpy((void*)&sh_size,(void*)&str_sh->sh_size,4);
			
			str_tab = (char*)(ptr + sh_offset);
			res_sh = get_elf_section_head_by_name(".vm_res", str_tab, sh_size, (vm_elf_section_head_t*)(ptr + e_shoff), e_shnum);

			vm_memcpy((void*)&sh_offset,(void*)&res_sh->sh_offset,4);
			
			
			if (GET_TAG_TRUE != vm_get_vm_tag(filename, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize))
			{
				rorw_zip = 0;
			}
			
			if(rorw_zip != 0)
			{
				if(strcmp(res_name,"mre-2.0") == 0)
				{
					if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
					{
						pcb->res_offset = sh_offset;
					}
					if((sm_ptr	= _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) != NULL)
					{
						sm_ptr->res_offset = sh_offset;
					}
				}
			}
			
			offset_temp = get_res_offset_from_mem(ptr + sh_offset, res_name, res_size);
			
		}
		
		if (offset_temp > -1) 
		{
			*offset = offset_temp;
			
			if(is_load == TRUE)
			{
				if(buffer == NULL)
				{
					if ((res = vm_malloc(*res_size)) != NULL) 
					{
						memcpy(res, ptr + offset_temp, *res_size);
					}
				}
				else
				{
					memcpy(buffer, ptr + offset_temp, *res_size);
				}
			}
		}
	}
	else 
	{		
		if(*offset != 0 && buffer != NULL && *res_size != 0 && is_load == TRUE)
		{
			file = vm_file_open(filename, MODE_READ, TRUE);
						
			if (file > -1) 
			{
				vm_file_seek(file, *offset, BASE_BEGIN);
				vm_file_read(file, buffer, *res_size, &nread);
				vm_file_close(file);
				return buffer;
			}
			else
			{
				MRE_SWLA_STOP("M72");
				return NULL;
			}
		}
		
		file = open_elf_file_for_load(filename, (VMUINT*)&res_offset);
		
		if(strcmp(res_name,"mre-2.0") == 0)
		{
			if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
			{
				pcb->res_offset = res_offset;
			}
			if((sm_ptr	= _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) != NULL)
			{
				sm_ptr->res_offset = res_offset;
			}
		}

		if (file > -1 ) 
		{
			if ((offset_temp = get_res_offset(file, res_name, res_size)) > -1) 
			{	
				*offset = offset_temp + res_offset;
				
				if(is_load == TRUE)
				{
					if(buffer == NULL)
					{
						if ((res = vm_malloc(*res_size)) != NULL) 
						{
							vm_file_seek(file, offset_temp + res_offset, BASE_BEGIN);
							vm_file_read(file, res, *res_size, &nread);
						
						if (nread != *res_size) {
							vm_free(res);
							res = NULL;
						}
					}
				}
				else
					{
						vm_file_seek(file, offset_temp + res_offset, BASE_BEGIN);
						vm_file_read(file, buffer, *res_size, &nread);
						
						if (nread != *res_size) {
							res = NULL;
						}
					}
				}
			}
			vm_file_close(file);
		}
	}
	return res;
}


/*****************************************************************************
 * FUNCTION
 *  vm_load_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_name        [?]     
 *  res_size        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 *vm_load_resource(char *res_name, VMINT *res_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMWCHAR* exec_filename = NULL;
	VMUINT8* ptr = NULL;
	VMINT offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M70");
	
	exec_filename = vm_get_self_filename();

	if (exec_filename == NULL)
	{
        MRE_SWLA_STOP("M70");
		return NULL;
	}
	
	if ((ptr = _vm_load_resource(exec_filename, res_name, res_size, NULL, &offset, TRUE)) == NULL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMRES,  TRC_MRE_VMRES_01, res_name);
	}

    MRE_SWLA_STOP("M70");
	return ptr;
}


VMUINT8 *vm_load_virtual_resource(char *res_name, VMINT *res_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMWCHAR* exec_filename = NULL;
	VMINT offset_temp;
	VMINT res_offset = 0;
	VMUINT8* res = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_pcb_t* pcb = NULL;
	VMFILE fileHandle = -1;

	/*----------------------------------------------------------------*/
	/* Code Body 													 */
	/*----------------------------------------------------------------*/
	exec_filename = vm_get_self_filename();

	if (exec_filename == NULL)
	{
		return NULL;
	}

	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL)
	{
#ifdef __MRE_CORE_SM__
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr && sm_ptr->pcb)
			fileHandle = sm_ptr->fileHandle;
#endif
	}
	else
	{
		fileHandle = pcb->fileHandle;
	}

	if (vm_wstrlen(exec_filename) == 0 || vm_wstrlen(exec_filename) > (MAX_APP_NAME_LEN + 1))
		return NULL;

	if (vm_parse_exec_format(exec_filename) == VM_EXEC_ROM)
	{
		vm_file_type_enum file_type;
		VMUINT8* ptr = NULL;

		ptr = vm_get_execrom_ptr(exec_filename);
		
		if (ptr == NULL)
		{
			return NULL;
		}
		
		file_type = vm_get_file_type(exec_filename);

		if(file_type  == VM_SIMPLE_VXP_ADS)
		{
			VMUINT tatal_size;
			vm_simple_elf_info info;
			VMUINT rom_size = *(__packed VMINT*)(ptr - 4);

			offset_temp = *(__packed VMINT*)(ptr + rom_size - 0x0C);

			tatal_size = *(__packed VMINT*)(ptr + offset_temp - 0x04);

			if(sizeof(vm_simple_elf_info) == tatal_size)
			{
				memcpy(&info,(ptr + offset_temp - tatal_size - 0x04),tatal_size);
				
				offset_temp = info.res_offset;
				res_offset = get_res_offset_from_mem(ptr + info.res_offset,
					res_name, res_size);
					
				if(res_offset>-1)
				{
					res_offset = res_offset + offset_temp;
				}
			}
		}
		else
		{
			VMINT sh_offset;
			VMINT sh_size;
			VMUINT e_shoff;
			VMUINT16 e_shstrndx;
			VMUINT16 e_shentsize;
			VMUINT16 e_shnum;
			char *str_tab;
			vm_elf_head_t *head;
			vm_elf_section_head_t *res_sh, *str_sh;

			head = (vm_elf_head_t*)ptr;
			vm_memcpy((void*)&e_shoff,(void*)&head->e_shoff,sizeof(VMUINT));
			vm_memcpy((void*)&e_shstrndx,(void*)&head->e_shstrndx,sizeof(VMUINT16));
			vm_memcpy((void*)&e_shentsize,(void*)&head->e_shentsize,sizeof(VMUINT16));
			vm_memcpy((void*)&e_shnum,(void*)&head->e_shnum,sizeof(VMUINT16));

			str_sh = (vm_elf_section_head_t*)(ptr + e_shoff +(e_shstrndx * e_shentsize));
			vm_memcpy((void*)&sh_offset,(void*)&str_sh->sh_offset,4);
			vm_memcpy((void*)&sh_size,(void*)&str_sh->sh_size,4);
			
			str_tab = (char*)(ptr + sh_offset);
			res_sh = get_elf_section_head_by_name(".vm_res", str_tab, sh_size, (vm_elf_section_head_t*)(ptr + e_shoff), e_shnum);

			vm_memcpy((void*)&sh_offset,(void*)&res_sh->sh_offset,4);
			
			res_offset = get_res_offset_from_mem(ptr + sh_offset, res_name, res_size);
			
		}
		
		if (res_offset > -1) 
		{
		 	res = ptr + res_offset;
		}
	}
	else 
	{
		VMFILE file;
		VMUINT nread;
		VMUINT8 buff[8];

		file = open_elf_file_for_load(exec_filename, (VMUINT*)&offset_temp);

		if (file > -1 ) 
		{
			if ((res_offset = get_res_offset(file, res_name, res_size)) > -1) 
			{	
				VMINT i;
				
				res_offset = offset_temp + res_offset;
						
				res = vm_malloc(16);
							
				if (fileHandle < 0) 
				{
					vm_free(res);
					return NULL;
				}
				
				FS_Seek(fileHandle, res_offset, FS_FILE_BEGIN);
				
				if (FS_Read(fileHandle, buff, 8, &nread) < FS_NO_ERROR)
				{
					vm_free(res);
					return NULL;
				}
			
				for (i=sizeof(g_vm_img_type_map)/sizeof(vm_img_map_type)-1; i>=0; i--)
				{
					if (buff[0] == g_vm_img_type_map[i].img_real_type)
					{
						res[0] = g_vm_img_type_map[i].img_offset_type;
						res[1] = buff[1];
						res[2] = buff[2];
						res[3] = buff[3];
						res[4] = buff[4];
						res[5] = buff[5];
						res[6] = buff[6];
						res[7] = buff[7];
						break;
					}
				}
			
				if (i < 0)
				{
					vm_free(res);
					return NULL;
				}
			
				/* offset in next 4 bytes */
				res[8] = (VMUINT8) (res_offset & 0x000000ff);
				res[9] = (VMUINT8) ((res_offset >> 8) & 0x000000ff);
				res[10] = (VMUINT8) ((res_offset >> 16) & 0x000000ff);
				res[11] = (VMUINT8) ((res_offset >> 24) & 0x000000ff);
			
				/* file handle in next 4 bytes */
				res[12] = (VMUINT8) (fileHandle & 0x000000ff);
				res[13] = (VMUINT8) ((fileHandle >> 8) & 0x000000ff);
				res[14] = (VMUINT8) ((fileHandle >> 16) & 0x000000ff);
				res[15] = (VMUINT8) ((fileHandle >> 24) & 0x000000ff);
			}
		}
		vm_file_close(file);
	}

	return res;
}



/*****************************************************************************
 * FUNCTION
 *  vm_load_resource_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  res_name        [?]         
 *  res_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 *vm_load_resource_from_file(VMWSTR filename, char *res_name, VMINT *res_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *ret;
	VMINT offset = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M71");
	ret = _vm_load_resource(filename, res_name, res_size, NULL, &offset, TRUE);
    MRE_SWLA_STOP("M71");
    return ret;
	
}


VMBOOL vm_load_resource_use_outside_memory(VMWSTR filename, char *res_name, void* buffer, VMINT buffer_size, vm_res_read_hint_struct* hint)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	VMUINT8 * buff = NULL;
	VMINT offset = 0;
	VMINT res_size = 0;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if( buffer == NULL )
    {
    	buff = _vm_load_resource(filename, res_name, &res_size, NULL, &offset, TRUE);
		if(buff == NULL)
		{
			return FALSE;
		}
		else
		{
			hint->res_offset = offset;
			hint->res_size = res_size;
			return TRUE;
		}
	}
	else
	{
		offset = hint->res_offset;
		res_size = buffer_size;
    	buff = _vm_load_resource(filename, res_name, &res_size, buffer, &offset, TRUE);
		
		if(buff == NULL)
		{
			return FALSE;
		}
		else
		{
			return TRUE;
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  open_elf_file_for_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMFILE open_elf_file_for_load(VMWSTR filename, VMUINT* res_offset) 
{
#ifndef MRE_ON_MODIS
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_elf_handle_t elf_hdl;
	int ok = FALSE;
	vm_file_type_enum file_type;

	file_type = vm_get_file_type(filename);

	if(file_type  == VM_SIMPLE_VXP_ADS)
	{
	
		VMUINT offset;
		VMUINT tatal_size;
		VMUINT nread;
		vm_simple_elf_info info;
		
		elf_hdl.file = vm_file_open(filename, MODE_READ, TRUE);
		vm_file_seek(elf_hdl.file, -0x0C, BASE_END);
		vm_file_read(elf_hdl.file, &offset, 4, &nread);
		vm_file_seek(elf_hdl.file, offset - 0x04, BASE_BEGIN);
		vm_file_read(elf_hdl.file, &tatal_size, 4, &nread);
		
		if(sizeof(vm_simple_elf_info) == tatal_size)
		{
			vm_file_seek(elf_hdl.file, offset - tatal_size -  0x04 , BASE_BEGIN);
			vm_file_read(elf_hdl.file, &info, tatal_size, &nread);
			vm_file_seek(elf_hdl.file, info.res_offset, BASE_BEGIN);
			*res_offset = info.res_offset;
			ok = TRUE;
		}
												
	}
	else
	{
		vm_elf_section_head_t res_sh, str_sh;
		char *sh_str_tbl;
		VMINT rorw_zip = 0;
		VMINT bufSize = 4;

		if (GET_TAG_TRUE != vm_get_vm_tag(filename, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize))
		{
			rorw_zip = 0;
		}
			   		
		if(open_elf(filename, &elf_hdl) == 0) 
		{
			if (read_elf_section_head(&elf_hdl, elf_hdl.elf_head.e_shstrndx, &str_sh) == 0) 
			{
				if ((sh_str_tbl = vm_malloc(str_sh.sh_size)) != NULL) 
				{
					if (read_elf_section(&elf_hdl, &str_sh, sh_str_tbl) == 0) 
					{
						if (read_elf_section_head_by_name(&elf_hdl, ".vm_res", sh_str_tbl,
								str_sh.sh_size, &res_sh) == 0)
						{
							if (vm_file_seek(elf_hdl.file, res_sh.sh_offset, BASE_BEGIN) == 0)
								ok = TRUE;
							
							if(rorw_zip)
								*res_offset = res_sh.sh_offset;
							else
								*res_offset = 0;
						}
					}
					vm_free(sh_str_tbl);
				}
			}
			if (!ok && (elf_hdl.file > -1))
				close_elf(&elf_hdl);
		}
	}
	
	return ok ? elf_hdl.file : -1;
#else

	char name[260 * 2 + 1];
	int ok = FALSE;
	VMFILE file;
	VMUINT offset;
	VMUINT nread;
	char res[7];
	
	vm_ucs2_to_ascii(name, 260 * 2, filename);
    *res_offset = 0;
	if ((file = vm_file_open(filename, MODE_READ, TRUE)) >= 0) 
	{
		if (vm_file_seek(file, -0x0C, BASE_END) == 0)
		{
			if(vm_file_read(file, &offset, 4, &nread) == 4)
			{
				if (vm_file_seek(file, offset - 0x04, BASE_BEGIN) == 0)
				{
					if(vm_file_read(file, &offset, 4, &nread) == 4)
					{
						if (vm_file_seek(file, offset + 1 , BASE_BEGIN) == 0)
						{
							if(vm_file_read(file, res, 7, &nread) == 7)
							{
								if(strcmp("vm_res",res) == 0)
								{
									ok = TRUE;
								}
							}
						}
					}
				}
			}
		}		
	}

	if (!ok && (file > -1))
		vm_file_close(file);

	return ok ? file : -1;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  strtolow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pStr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void strtolow( VMCHAR * pStr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT 	i, iLen;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	iLen = strlen( pStr );
	
	for( i=0; i<iLen; i++ )
	{
		if( pStr[i] >= 'A' && pStr[i] <= 'Z' )
			pStr[i] = pStr[i] + 0x20;
	}
	
	return;
} 


/*****************************************************************************
 * FUNCTION
 *  get_res_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file            [IN]        
 *  res_name        [?]         
 *  res_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_res_offset(VMFILE file, char *res_name, VMINT *res_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	char tmp[128], * org_name = NULL;
	VMINT len, offset = -1;
	VMUINT nread;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	org_name = (char *)vm_malloc( strlen(res_name) + 2 );
	if( org_name == NULL )
		return offset;

	memset( org_name, 0x00, strlen(res_name) + 2 );
	strcat( org_name, res_name );

	strtolow( org_name );

	while (TRUE) 
	{
		len = 0;
		do {
			if (vm_file_read(file, tmp + len, 1, &nread) == 1) 
			{
				if (tmp[len] == '\0')
					break;
				len++;
			}
			else
			{
				len = 0;
				break;
			}
		} while (len < 128);

		if (len == 0) 
		{
			offset = -1;
			break;
		}
		
		strtolow( tmp );
		if( strcmp(org_name, tmp) == 0 ) 
		{
			if (vm_file_read(file, &offset, 4, &nread) != 4 )
			{
				offset = -1;
			}
			else if(res_size != NULL && vm_file_read(file, res_size, 4, &nread) != 4)
			{
				offset = -1;
			}
			break;
		}
		else 
		{
			if (vm_file_seek(file, 8, BASE_CURR) != 0)
			{
				offset = -1;
				break;
			}
		}
	}

	vm_free( org_name );

	
	return offset;

}


/*****************************************************************************
 * FUNCTION
 *  get_res_offset_from_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr             [?]     
 *  res_name        [?]     
 *  res_size        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_res_offset_from_mem(VMUINT8 *ptr, char* res_name, VMINT* res_size) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT offset = -1;

	VMINT len = 0;
	VMCHAR* tmpPtr = (VMCHAR*)ptr, *cmpPtr = NULL, *cmPtr2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* 检查是否参数合法 */
	if (ptr == NULL || strlen((char*)ptr) == 0 
		|| res_name == NULL || strlen(res_name) == 0)
	{
		return offset;
	}

	if ((cmPtr2 = vm_calloc(strlen(res_name) + 1)) == NULL)
		return -1;
	strcat(cmPtr2, res_name); 		
	strtolow(cmPtr2);					// cmpPtr2为res_name的小写。 
	
	while ((len = strlen(tmpPtr)) != 0)
	{
		if ((cmpPtr = vm_calloc(len + 1)) == NULL)
			break;
		
		strcat(cmpPtr, tmpPtr);
		strtolow(cmpPtr);				// cmpPtr为res_name的小写。
		
		if (strcmp(cmPtr2, cmpPtr) == 0)
		{
			offset = *((__packed VMINT*)(tmpPtr + len + 1));
			
			if(res_size != NULL)
			{
				*res_size = *((__packed VMINT*)(tmpPtr + len + 5));
			}

			vm_free(cmpPtr);
			break;
		}
		else
		{
			tmpPtr += (len + 9);
			vm_free(cmpPtr);
		}
	}

	vm_free(cmPtr2);
	return offset;
}



/*****************************************************************************
 * FUNCTION
 *  _vm_get_resource_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  res_name        [?]              
 * RETURNS
 *  
 *****************************************************************************/
VMUINT _vm_get_resource_offset(VMWSTR filename, char *res_name, VMINT* p_size)
{
	VMINT offset = 0;
	
	_vm_load_resource(filename, res_name, p_size, NULL, &offset, FALSE);
	return offset;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_resource_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_name        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMUINT vm_get_resource_offset(char *res_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMWCHAR* exec_filename = NULL;
	VMUINT ptr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	exec_filename = vm_get_self_filename();

	if (exec_filename == NULL)
	{
		return 0;
	}
	
	if ((ptr = _vm_get_resource_offset(exec_filename, res_name, NULL)) == 0)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMRES,  TRC_MRE_VMRES_02, res_name);
	}
	
	return ptr;
}

VMUINT vm_get_resource_offset_from_file(VMWSTR filename, char *res_name)
{
	return _vm_get_resource_offset(filename, res_name, NULL);
}

VMUINT vm_get_resource_offset_and_size_from_file(VMWSTR filename, char *res_name, VMINT* res_size)
{
	return _vm_get_resource_offset(filename, res_name, res_size);
}

static vm_resource_contex* vm_res_get_contex_data(void)
{
    VMINT currAppR9 = vm_get_running_app_sb();
    _vm_pcb_t* pcb = NULL;
	vm_resource_contex* p_contex = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
		p_contex = &pcb->res_data;
    }
	else
	{
		_vm_sm_t * sm_ptr  = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			p_contex = &sm_ptr->res_data;
		}
	}
	return p_contex;
}

VMINT vm_get_res_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMWCHAR * wfilename = NULL;
	VMINT i = 0;
	VMINT type = 0;
	VMINT size = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wfilename = vm_get_self_filename();
	
	if (wfilename == NULL)
	{
		return 0;
	}	
	
	if (GET_TAG_TRUE == vm_get_vm_tag((VMWCHAR *) wfilename, VM_CE_INFO_VPP_TYPE, (void*)&type, &size))
	{
		if(type != 0)
			type = 8;
	}
	return type;
}


VMINT32 vm_resource_get_data_from_file(VMWSTR filename, VMUINT8 *data, VMUINT32 offset, VMUINT32 size)
{
	VMUINT8* ptr = NULL;
	VMFILE file;
	VMUINT nread;    
    vm_exec_format_enum exec_format;
    VMINT res_offset = 0;


    exec_format = vm_parse_exec_format(filename);

	if (exec_format == VM_EXEC_ROM)
	{
		vm_file_type_enum file_type;
		VMINT32 offset_temp;

		ptr = vm_get_execrom_ptr(filename);
		if (ptr == NULL)
		{
            MRE_SWLA_STOP("M73");
			return 0;
		}

		file_type = vm_get_file_type(filename);

		if(file_type  == VM_SIMPLE_VXP_ADS)
		{
			VMUINT tatal_size;
			vm_simple_elf_info info;
			VMINT res_offset = 0;
			VMUINT rom_size = *(__packed VMINT*)(ptr - 4);
			
			offset_temp = *(__packed VMINT*)(ptr + rom_size - 0x0C);

			tatal_size = *(__packed VMINT*)(ptr + offset_temp - 0x04);

			if(sizeof(vm_simple_elf_info) == tatal_size)
			{
				memcpy(&info,(ptr + offset_temp - tatal_size - 0x04),tatal_size);
				res_offset = info.res_offset;
				offset_temp = res_offset + offset;
			}
		}
		else
		{
			offset_temp = offset;
		}
		
        if ((VMINT32)offset_temp >= 0) 
        {
    		if (data != NULL) 
            {
    			memcpy(data, ptr + offset_temp, size);
    		}
		}
	}
	else 
	{
		file = open_elf_file_for_load(filename, (VMUINT*)&res_offset);

		if (file > -1) 
        {
            if ((VMINT32)offset  >= 0) 
            {
					vm_file_seek(file, offset + res_offset, BASE_BEGIN);
					vm_file_read(file, data, size, &nread);
					if (nread != size) 
                    {
						data = NULL;
					}
			}
			vm_file_close(file);
		}
    }
    
	return exec_format;    
}

VMINT32 vm_resource_get_data(VMUINT8 *data, VMUINT32 offset, VMUINT32 size)
{
	VMWCHAR * exec_name = NULL;

    MRE_SWLA_START("M73");
	exec_name = vm_get_self_filename();
	
	if (exec_name == NULL)
	{
        MRE_SWLA_STOP("M73");
		return 0;
	}
	
	return vm_resource_get_data_from_file(exec_name, data, offset, size);
}


/*****************************************************************************
 * FUNCTION
 *  vm_res_init
 * DESCRIPTION
 *  Init VRE 4.0 resource, will load current language table into RAM
 *  Need to be called before use VRE 4.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
VMINT32 vm_res_init(void)
{
    return vm_res_init_with_language(0);
}

/*****************************************************************************
 * FUNCTION
 *  vm_res_init_with_language
 * DESCRIPTION
 *  Init VRE 4.0 resource, will load language table into RAM
 *  Need to be called before use VRE 4.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
VMINT32 vm_res_init_with_language(VMUINT32 language)
{
	VMUINT32 res_size;
    VMINT currAppR9 = vm_get_running_app_sb();
    _vm_pcb_t* pcb = NULL;
	_vm_sm_t * sm_ptr = NULL;
	vm_exec_format_enum format;

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {		
    	if( pcb->resfileHandle > 0)
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_03);
			return VM_RES_SUCCESS;
    	}
		
		memset(&pcb->res_data, 0, sizeof(vm_resource_contex));
		
		pcb->res_buf = vm_load_resource("mre-2.0", (VMINT*)&res_size);
		
		vm_res_init_string_with_language(pcb->res_buf, language);

    	format = vm_parse_exec_format(pcb->fullFileName);
		
		if(format != VM_EXEC_ROM)
		{
			if(pcb->fileHandle < 0)
			{
				pcb->resfileHandle = (VMINT)FS_Open((WCHAR*)pcb->fullFileName, FS_READ_ONLY);
			}
			else
			{
				pcb->resfileHandle = pcb->fileHandle;
			}
			
			if (pcb->resfileHandle < 0) 
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_04);
				return VM_RES_ITEM_NOT_FOUND;
			}
		}
		else
		{
			pcb->resfileHandle = 1;
		}
		return VM_RES_SUCCESS;
    }
	
	if((sm_ptr  = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) != NULL)
	{
    	if(sm_ptr->resfileHandle > 0)
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_05);
			return VM_RES_SUCCESS;
    	}

		memset(&sm_ptr->res_data, 0, sizeof(vm_resource_contex));
		
		sm_ptr->res_buf = vm_load_resource("mre-2.0", (VMINT*)&res_size);
		
		vm_res_init_string_with_language(sm_ptr->res_buf, language);
		
    	format = vm_parse_exec_format(sm_ptr->fullFileName);
		
		if(format != VM_EXEC_ROM)
		{
			sm_ptr->resfileHandle = (VMINT)FS_Open((WCHAR*)sm_ptr->fullFileName, FS_READ_ONLY);
			
			if (sm_ptr->resfileHandle < 0) 
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_06);
				return VM_RES_ITEM_NOT_FOUND;
			}
		}
		else
		{
			sm_ptr->resfileHandle = 1;
		}
		
		return VM_RES_SUCCESS;
	}

	return VM_RES_ITEM_NOT_FOUND;
	
}


void vm_res_free_res(_vm_pcb_t* pcb)
{
	_vm_sm_t * sm_ptr = NULL;

	if(pcb == NULL)
		return;
	
	if (pcb->resfileHandle > 0) 
	{
		if (pcb->res_data.str_buf != NULL)
		{
			_vm_sb_stack_push(pcb->r9);
			vm_free(pcb->res_data.str_buf);
			if(pcb->resfileHandle == 1)
				
				vm_res_id_delete_all(1);
			else
				vm_res_id_delete_all(0);
			
			vm_free(pcb->res_buf);
			_vm_sb_stack_pop();
		}

		if(pcb->resfileHandle != 1 && pcb->fileHandle < 0)
		{
			FS_Close(pcb->resfileHandle);
		}

		pcb->resfileHandle = -1;

		while ( (sm_ptr = _vm_sm_list_find(SM_FIND_BY_PCB, (VMINT)pcb)) != NULL )
		{
			if (sm_ptr->resfileHandle > 0) 
			{
				if (sm_ptr->res_data.str_buf != NULL)
				{
					_vm_sb_stack_push(sm_ptr->r9);
					vm_free(sm_ptr->res_data.str_buf);

					if(sm_ptr->resfileHandle == 1)
						
						vm_res_id_delete_all(1);
					else
						vm_res_id_delete_all(0);

					vm_free(sm_ptr->res_buf);
					_vm_sb_stack_pop();
				}
				
				if(sm_ptr->resfileHandle != 1)
				{
					FS_Close(sm_ptr->resfileHandle);
				}
				
				sm_ptr->resfileHandle = -1;
			}		
		}
		
	}
}

/*****************************************************************************
 * FUNCTION
 *  vm_res_deinit
 * DESCRIPTION
 *  Release all VRE 4.0 resource, will free all memory of resource
 *  Could be called after use VRE 4.0 Resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
VMINT32 vm_res_deinit(void)
{
    VMINT currAppR9 = vm_get_running_app_sb();
    _vm_pcb_t* pcb = NULL;
	
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
		vm_res_free_res(pcb);
		return VM_RES_SUCCESS;
    }
	else
	{
		_vm_sm_t * sm_ptr  = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		
		if (sm_ptr->resfileHandle > 0) 
		{
			if (sm_ptr->res_data.str_buf != NULL)
			{
				_vm_sb_stack_push(sm_ptr->r9);
				vm_free(sm_ptr->res_data.str_buf);
				
				if(sm_ptr->resfileHandle == 1)
					vm_res_id_delete_all(1);
				else
					vm_res_id_delete_all(0);
				
				vm_free(sm_ptr->res_buf);
				_vm_sb_stack_pop();
			}
			
			if(sm_ptr->resfileHandle != 1)
			{
				FS_Close(sm_ptr->resfileHandle);
			}
			
			sm_ptr->resfileHandle = -1;
		}		
		return VM_RES_SUCCESS;
	}
		
}


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_offset
 * DESCRIPTION
 *  Get the offset of a reousrce ID from resource search table.
 * PARAMETERS
 *  id              [IN]    Resource ID to find
 *  v4res           [IN]    source buffer
 *  size            [IN]    Size of the ID's resource data
 * RETURNS
 *  VMINT32                 offset of the ID's resource data
 *****************************************************************************/
static VMUINT32 vm_res_get_offset(VMUINT32 id, VMUINT8 *v4res, VMUINT32 *size)
{
    VMUINT8 *p1 = v4res;
    VMUINT32 index, offset;
    VMUINT32 next_offset;

    do{
        index = vm_res_get_long(p1);
        p1 += 4;
        offset = vm_res_get_long(p1);
        p1 += 4;
    }while(index != id && index != 0xFFFFFFFF);

    if (index == 0xFFFFFFFF)
    {
        /* Didn't find the ID */
        *size = 0;
        return 0;
    }

    vm_res_get_long(p1);
    p1 += 4;
    next_offset = vm_res_get_long(p1);
    p1 += 4;

    *size = next_offset - offset;
    return offset;
}


/****************************************** Tool Functions start ******************************************/


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_long
 * DESCRIPTION
 *  Function to get a 32bit number from the buffer.
 * PARAMETERS
 *  v4res           [IN]    source buffer
 * RETURNS
 *  VMINT32    32bit number
 *****************************************************************************/
static VMINT32 vm_res_get_long(VMUINT8 *v4res)
{
    if (v4res != NULL)
        return *((VMINT32*)v4res);
    else 
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  StrToHex
 * DESCRIPTION
 *  String to Hex
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT32 StrToHex(const VMCHAR* pszStr, VMUINT32 u4Len)
{
	VMUINT32 u4Idx;
	VMUINT32 u4ReturnValue = 0;

	if ((pszStr == NULL) || (u4Len == 0))
	{
		return 0;
	}

	u4Len = (u4Len > 8) ? 8 : u4Len;

	for (u4Idx = 0;
		u4Idx < u4Len;
		u4Idx++)
	{
		if ((pszStr[u4Idx] >= '0') && (pszStr[u4Idx] <= '9'))
		{
			u4ReturnValue = u4ReturnValue << 4;
			u4ReturnValue += (VMUINT32)(VMUINT8)(pszStr[u4Idx] - '0');
		}
		else
		if ((pszStr[u4Idx] >= 'A') && (pszStr[u4Idx] <= 'F'))
		{
			u4ReturnValue = u4ReturnValue << 4;
			u4ReturnValue += (VMUINT32)(VMUINT8)(pszStr[u4Idx] - 'A' ) + 10;
		}
		else
		if ((pszStr[u4Idx] >= 'a') && (pszStr[u4Idx] <= 'f'))
		{
			u4ReturnValue = u4ReturnValue << 4;
			u4ReturnValue += (VMUINT32)(VMUINT8)(pszStr[u4Idx] - 'a') + 10;
		}
		else
		{
			return 0;
		}
	}

	return u4ReturnValue;
}


/*****************************************************************************
 * FUNCTION
 *  StrToDec
 * DESCRIPTION
 *  String to Dec
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT32 StrToDec(const VMCHAR* pszStr, VMUINT32 u4Len)
{
	VMUINT32 u4Idx;
	VMUINT32 u4ReturnValue = 0;

	if ((pszStr == NULL) || (u4Len == 0))
	{
		return 0;
	}

	u4Len = (u4Len > 10) ? 10 : u4Len;

	for (u4Idx = 0;
		u4Idx < u4Len;
		u4Idx++)
	{
		if ((pszStr[u4Idx] >= '0') && (pszStr[u4Idx] <= '9'))
		{
			u4ReturnValue *= 10;
			u4ReturnValue += (VMUINT32)(VMUINT8)(pszStr[u4Idx] - '0');
		}
		else
		{
			return 0;
		}
	}

	return u4ReturnValue;
}


/*****************************************************************************
 * FUNCTION
 *  StrToInt
 * DESCRIPTION
 *  String to Int
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VMUINT32 StrToInt(const VMCHAR* pszStr)
{
	VMUINT32 u4Len;

	if (pszStr == NULL)
	{
		return 0;
	}

	u4Len = strlen(pszStr);

	if (u4Len > 2)
	{
		if ((pszStr[0] == '0') && (pszStr[1] == 'x'))
		{
			return StrToHex(&pszStr[2], u4Len - 2);
		}
	}

	return StrToDec(pszStr, u4Len);
}

/******************************************Tool Functions end ******************************************/


/*****************************************************************************
 * FUNCTION
 *  vm_res_init_string_with_language
 * DESCRIPTION
 *  init string table use some language
 * PARAMETERS
 *  v4res           [IN]    source buffer
 * RETURNS
 *  VM_RES_SUCCESS          Success
 *  VM_RES_OUT_OF_MEM       Out of memory
 *****************************************************************************/
static VMINT32 vm_res_init_string_with_language(VMUINT8 *v4res, VMUINT32 language)
{
	VMUINT32 res_size;    
    VMINT8 language_id[16];
    VMINT8 ssc_str[16];
	vm_resource_contex* p_contex = NULL;
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return VM_RES_OUT_OF_MEM;

	if( language == 0 )
    {
	    /* Get Current Language */
	    vm_get_language_ssc(ssc_str);

	    language_id[0] = ssc_str[2];
	    language_id[1] = ssc_str[3];
	    language_id[2] = ssc_str[4];
	    language_id[3] = ssc_str[5];
	    language_id[4] = 0;

	    p_contex->cur_language =StrToInt(language_id);
	    p_contex->cur_language += 0xFFFF0000;
		
	    /* Get String Data by language */
	    p_contex->cur_offset = vm_res_get_offset(p_contex->cur_language, v4res, &res_size);

		if(p_contex->cur_offset == 0)
		{
			p_contex->cur_language = 0xFFFF002C;
			p_contex->cur_offset = vm_res_get_offset(p_contex->cur_language, v4res, &res_size);

			if(p_contex->cur_offset == 0)
			{
				return VM_RES_ITEM_NOT_FOUND;
			}
		}
	}
	else
	{
		p_contex->cur_language = language;
		p_contex->cur_language += 0xFFFF0000;
		
		p_contex->cur_offset = vm_res_get_offset(p_contex->cur_language, v4res, &res_size);
	}
	
    if (p_contex->str_buf != NULL)
    {
        vm_free(p_contex->str_buf);
    }
    p_contex->str_buf = vm_malloc(res_size);
    VM_RES_CHECK_MEM_ALLOC(p_contex->str_buf)

    /* Get String data */
    vm_resource_get_data(p_contex->str_buf, p_contex->cur_offset, res_size);   

    return VM_RES_SUCCESS;    
}



/*****************************************************************************
 * FUNCTION
 *  vm_res_get_string
 * DESCRIPTION
 *  Get the string by ID. 
 * PARAMETERS
 *  string_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                   String pointer of the ID, only current language, NULL for not found
 *****************************************************************************/
VMUINT8 *vm_res_get_string(VMUINT32 string_id)
{
    VMUINT32 res_offset;     
    VMUINT32 str_count, i;
    VMUINT8 *p1;
    VMUINT32 index = 0;
	vm_resource_contex* p_contex = NULL;
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return NULL;

	p1 = p_contex->str_buf;

    /* Find the ID in current language list */    
    str_count = vm_res_get_long(p1);
    p1 += 4;

    for (i=0; i<str_count; i++)
    {
        index = vm_res_get_long(p1);
        p1 += 8;

        if (index == string_id || index == 0xFFFFFFFF)
        {
            break;
        }
    }

    if (i == str_count || index == 0xFFFFFFFF)
    {
        /* Didn't find the ID */
        return NULL;
    }

    res_offset = vm_res_get_long(p1-4);

    return (p_contex->str_buf + res_offset);
}


VMINT32 vm_res_load_image_start(void)
{
    return VM_RES_SUCCESS;
}


VMINT32 vm_res_load_image_end(void)
{
    return VM_RES_SUCCESS;
}


static VMINT vm_res_get_file_image_internal(VMWSTR filename, VMUINT32 image_id, void* buff, VMUINT32 *size)
{
	VMUINT32 res_offset;     
    VMUINT8 *res_buf = NULL;

    res_buf = vm_load_resource_from_file(filename, "mre-2.0", (VMINT*)size);

	if (res_buf == NULL)
    {
        return FALSE;
    }

    res_offset = vm_res_get_offset(image_id, res_buf, size);
	
	vm_free(res_buf);

    if (*size == 0 || res_offset == 0)
    {
        return FALSE;
    }

	if( buff != NULL )
    {
    	vm_resource_get_data_from_file(filename, buff, res_offset, *size);
	}
	
    return TRUE;
}


VMINT vm_res_get_image_and_size_from_file(VMWSTR filename, VMUINT32 image_id, void* buff, VMUINT32 *size)
{
    return vm_res_get_file_image_internal(filename,image_id,buff,size);
}


VMINT vm_res_get_audio_and_size_from_file(VMWSTR filename, VMUINT32 audio_id, void *buff, VMUINT32 *size)
{
    return vm_res_get_file_image_internal(filename,audio_id,buff,size);
}


static VMINT vm_res_get_string_internal(VMWSTR filename, VMUINT32 string_id, void *buff, VMUINT32 *size)
{
	VMUINT32 res_offset;	 
	VMUINT8 *res_buf = NULL;
    VMUINT32 cur_language;
	VMUINT8 *p1,*p2;
    VMUINT32 str_count;
	VMUINT32 index = 0;
	VMUINT32 i;
	VMINT8 language_id[16];
	VMINT8 ssc_str[16];
	VMUINT32 res_size;	  
	VMUINT8* ptr = NULL;
	
	res_buf = vm_load_resource_from_file(filename, "mre-2.0", (VMINT*)size);

	if (res_buf == NULL)
	{
		return FALSE;
	}
	
	/* Get Current Language */
	vm_get_language_ssc(ssc_str);
	
	language_id[0] = ssc_str[2];
	language_id[1] = ssc_str[3];
	language_id[2] = ssc_str[4];
	language_id[3] = ssc_str[5];
	language_id[4] = 0;
	
	cur_language =StrToInt(language_id);
	cur_language += 0xFFFF0000;
	
	/* Get String Data by language */
	res_offset = vm_res_get_offset(cur_language, res_buf, &res_size);

	vm_free(res_buf);
	
    if (res_size == 0)
    {
        return FALSE;
    }

	
    p1 = vm_malloc(res_size);
    p2 = p1;

	if( p1 != NULL )
	{
		vm_resource_get_data_from_file(filename, p1, res_offset, res_size);
	}

	/* Find the ID in current language list */	  
	str_count = vm_res_get_long(p1);
	p1 += 4;

	for (i=0; i<str_count; i++)
	{
		index = vm_res_get_long(p1);
		p1 += 8;

		if (index == string_id || index == 0xFFFFFFFF)
		{
			break;
		}
	}

	if (i == str_count || index == 0xFFFFFFFF)
	{
		vm_free(p2);
		return FALSE;
	}

	res_offset = vm_res_get_long(p1-4);
	*size = 2*kal_wstrlen((void*)(p2 + res_offset)) + 2;
	
    if( buff != NULL )
	{
		kal_wstrcpy(buff,(void*)(p2 + res_offset));
	}
	
	vm_free(p2);
	
	return TRUE;

}


static VMINT vm_res_get_rom_image_internal(VMWSTR filename, VMUINT32 image_id, void** buff, VMUINT32 *size)
{
	VMUINT32 res_offset;     
    VMUINT8 *res_buf = NULL;
	VMUINT8* ptr = NULL;

    res_buf = vm_load_resource_from_file(filename, "mre-2.0", (VMINT*)size);

	if (res_buf == NULL)
    {
        return FALSE;
    }

    res_offset = vm_res_get_offset(image_id, res_buf, size);
	
	vm_free(res_buf);

    if (*size == 0 || res_offset == 0)
    {
        return FALSE;
    }
	
	ptr = vm_get_execrom_ptr(filename);
	if (ptr == NULL)
	{
		return FALSE;
	}
	
	if ((VMINT32)res_offset >= 0) 
	{
		*buff = (void*)(ptr + res_offset);
	}
	else
	{
		return FALSE;
	}
	
    return TRUE;
}

static VMINT vm_res_get_rom_string_internal(VMWSTR filename, VMUINT32 string_id, void **buff, VMUINT32 *size)
{
	VMUINT32 res_offset;	
	VMUINT32 res_offset1;	
	VMUINT8 *res_buf = NULL;
    VMUINT32 cur_language;
	VMUINT8 *p1,*p2;
    VMUINT32 str_count;
	VMUINT32 index = 0;
	VMUINT32 i;
	VMINT8 language_id[16];
	VMINT8 ssc_str[16];
	VMUINT32 res_size;	  
	VMUINT8* ptr = NULL;
	
	res_buf = vm_load_resource_from_file(filename, "mre-2.0", (VMINT*)size);

	if (res_buf == NULL)
	{
		return FALSE;
	}
	
	/* Get Current Language */
	vm_get_language_ssc(ssc_str);
	
	language_id[0] = ssc_str[2];
	language_id[1] = ssc_str[3];
	language_id[2] = ssc_str[4];
	language_id[3] = ssc_str[5];
	language_id[4] = 0;
	
	cur_language =StrToInt(language_id);
	cur_language += 0xFFFF0000;
	
	/* Get String Data by language */
	res_offset1 = vm_res_get_offset(cur_language, res_buf, &res_size);

	vm_free(res_buf);
	
    if (res_size == 0)
    {
        return FALSE;
    }

	
    p1 = vm_malloc(res_size);
    p2 = p1;

	if( p1 != NULL )
	{
		vm_resource_get_data_from_file(filename, p1, res_offset1, res_size);
	}

	/* Find the ID in current language list */	  
	str_count = vm_res_get_long(p1);
	p1 += 4;

	for (i=0; i<str_count; i++)
	{
		index = vm_res_get_long(p1);
		p1 += 8;

		if (index == string_id || index == 0xFFFFFFFF)
		{
			break;
		}
	}

	if (i == str_count || index == 0xFFFFFFFF)
	{
		vm_free(p2);
		return FALSE;
	}
	
	ptr = vm_get_execrom_ptr(filename);
	if (ptr == NULL)
	{
		vm_free(p2);
		return FALSE;
	}

	res_offset = vm_res_get_long(p1-4);
	*size = 2*kal_wstrlen((void*)(ptr + res_offset + res_offset1)) + 2;
		

	*buff = (void*)(ptr + res_offset + res_offset1);


	vm_free(p2);
	
	return TRUE;

}


VMINT vm_res_get_image_and_size_from_rom(VMWSTR filename, VMUINT32 image_id, void **buff, VMUINT32 *size)
{
	return vm_res_get_rom_image_internal(filename, image_id, buff, size);
}

VMINT vm_res_get_audio_and_size_from_rom(VMWSTR filename, VMUINT32 audio_id, void **buff, VMUINT32 *size)
{
	return vm_res_get_rom_image_internal(filename, audio_id, buff, size);
}

VMINT vm_res_get_string_and_size_from_file(VMWSTR filename, VMUINT32 string_id, void *buff, VMUINT32 *size)
{
	return vm_res_get_string_internal(filename, string_id, buff, size);
}

VMINT vm_res_get_string_and_size_from_rom(VMWSTR filename, VMUINT32 string_id, void **buff, VMUINT32 *size)
{
	return vm_res_get_rom_string_internal(filename, string_id, buff, size);
}


VMUINT8 *vm_res_get_image_and_size(VMUINT32 image_id, VMUINT32 *size)
{
    VMUINT32 res_size;
    VMUINT32 res_offset;     
    VMUINT8 *res_buf = NULL;
    VMUINT8 *res_data = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();
    _vm_pcb_t* pcb = NULL;
	_vm_sm_t * sm_ptr = NULL;
	VMUINT nread;
	VMINT ret;
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_07, image_id);

    if (((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL) && ((sm_ptr  = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) == NULL))
    {
		return NULL;
    }
		

    res_data = vm_res_id_search(image_id, &res_size);
	
    if (res_data != NULL)
    {
		if (size != NULL)
		{
			*size = res_size;
		}
		
        return (VMUINT8*)((VMINT)res_data + vm_get_res_header());
    }

	if(pcb != NULL)
    {
	    if (pcb->res_buf == NULL)
	    {
	        res_buf = vm_load_resource("mre-2.0", (VMINT*)&res_size);
	        if (res_buf == NULL)
	        {
	            return NULL;
	        }
	    }
	    else
	    {
	        res_buf = pcb->res_buf;
	    }

	    res_offset = vm_res_get_offset(image_id, res_buf, &res_size);
		
	    if (res_size == 0)
	    {
	        return NULL;
	    }
				
		if (vm_parse_exec_format(pcb->fullFileName) == VM_EXEC_ROM)
		{
			VMUINT8 * ptr;
			
			ptr = vm_get_execrom_ptr(pcb->fullFileName);
			if (ptr == NULL)
			{
				return 0;
			}
			
			res_data = (VMUINT8*)(ptr + pcb->res_offset + res_offset);
		}
		else
		{
			res_data = vm_malloc(res_size);
			
			if(res_data == NULL)
			{
				return NULL;
			}

			if((ret = FS_Seek(pcb->resfileHandle,pcb->res_offset + res_offset, FS_FILE_BEGIN)) < 0)
			{
				vm_free(res_data);
				return NULL;
			}
			
			if((ret =FS_Read(pcb->resfileHandle, res_data, res_size, (UINT *)&nread)) < 0)
			{
				vm_free(res_data);
				return NULL;
			}
		}
	}
	else
	{
	    if (sm_ptr->res_buf == NULL)
	    {
	        res_buf = vm_load_resource("mre-2.0", (VMINT*)&res_size);
	        if (res_buf == NULL)
	        {
	            return NULL;
	        }
	    }
	    else
	    {
	        res_buf = sm_ptr->res_buf;
	    }

	    res_offset = vm_res_get_offset(image_id, res_buf, &res_size);
		
	    if (res_size == 0)
	    {
	        return NULL;
	    }
		
		if (vm_parse_exec_format(sm_ptr->fullFileName) == VM_EXEC_ROM)
		{
			VMUINT8 * ptr;
			
			ptr = vm_get_execrom_ptr(sm_ptr->fullFileName);
			if (ptr == NULL)
			{
				return 0;
			}
			
			res_data = (VMUINT8*)(ptr + sm_ptr->res_offset + res_offset);
		}
		else
		{
			res_data = vm_malloc(res_size);
			if(res_data == NULL)
			{
				return NULL;
			}

			if((ret = FS_Seek(sm_ptr->resfileHandle,pcb->res_offset + res_offset, FS_FILE_BEGIN)) < 0)
			{
				vm_free(res_data);
				return NULL;
			}
			
			if((ret = FS_Read(sm_ptr->resfileHandle, res_data, res_size, (UINT *)&nread)) < 0)
			{
				vm_free(res_data);
				return NULL;
			}
		}
	}
	
    vm_res_id_add(image_id, res_data, res_size);
	
	if (size != NULL)
	{
		*size = res_size;
	}

    return (VMUINT8*)((VMINT)res_data + vm_get_res_header());
}


/*****************************************************************************
 * FUNCTION
 *  vm_res_get_image
 * DESCRIPTION
 *  Get Image data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID.
 * PARAMETERS
 *  image_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                  Image pointer of the ID
 *****************************************************************************/
VMUINT8 *vm_res_get_image(VMUINT32 image_id)
{
    return vm_res_get_image_and_size(image_id, NULL);
}

VMUINT8 *vm_res_get_virtual_image(VMUINT32 image_id)
{
	VMUINT32 res_size;
	VMUINT32 res_offset; 	
	VMUINT8 *res_buf = NULL;
	VMUINT8 *res_data = NULL;
	VMINT currAppR9 = vm_get_running_app_sb();
	_vm_pcb_t* pcb = NULL;
	VMUINT32 size;
	VMINT i;
	VMUINT8 buff[8];
	VMUINT nread;
	
	/*----------------------------------------------------------------*/
	/* Code Body 													 */
	/*----------------------------------------------------------------*/
	if(vm_get_res_header()==0)
		return NULL;
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL)
	{
		return NULL;
	}

	res_data = vm_res_id_search(image_id, &res_size);
	
	if (res_data != NULL)
	{
		return (VMUINT8*)res_data;
	}

	if (pcb->res_buf == NULL)
	{
		res_buf = vm_load_resource("mre-2.0", (VMINT*)&size);
		
		if (res_buf == NULL)
		{
	   		return NULL;
		}
	}
	else
	{
		res_buf = pcb->res_buf;
	}

	res_offset = vm_res_get_offset(image_id, res_buf, &size);
	
	if (size == 0)
	{
		if (pcb->res_buf == NULL)
		{	
		   vm_free(res_buf);
		}
		return NULL;
	}

	if(vm_parse_exec_format(pcb->fullFileName) == VM_EXEC_ROM)
	{
		VMUINT8 * ptr;
		
		ptr = vm_get_execrom_ptr(pcb->fullFileName);
		if (ptr == NULL)
		{
			return 0;
		}
		
		res_data = (VMUINT8*)(ptr + pcb->res_offset + res_offset);
	}
	else
	{
		res_data = vm_malloc(16);
		
		res_offset = pcb->res_offset + res_offset;

		if (pcb->fileHandle < 0) 
		{
			if (pcb->res_buf == NULL)
			{	
				vm_free(res_buf);
		}
		vm_free(res_data);
		return NULL;
	}
	
	FS_Seek(pcb->fileHandle, res_offset, FS_FILE_BEGIN);
	
	if (FS_Read(pcb->fileHandle, buff, 8, &nread) < FS_NO_ERROR)
	{
		if (pcb->res_buf == NULL)
		{	
			vm_free(res_buf);
		}
		vm_free(res_data);
		return NULL;
	}

	for (i=sizeof(g_vm_img_type_map)/sizeof(vm_img_map_type)-1; i>=0; i--)
	{
		if (buff[0] == g_vm_img_type_map[i].img_real_type)
		{
			res_data[0] = g_vm_img_type_map[i].img_offset_type;
			res_data[1] = buff[1];
			res_data[2] = buff[2];
			res_data[3] = buff[3];
			res_data[4] = buff[4];
			res_data[5] = buff[5];
			res_data[6] = buff[6];
			res_data[7] = buff[7];
            break;
		}
	}

    if (i < 0)
    {
		if (pcb->res_buf == NULL)
		{	
			vm_free(res_buf);
		}
	    vm_free(res_data);
	    return NULL;
    }

	/* offset in next 4 bytes */
	res_data[8] = (VMUINT8) (res_offset & 0x000000ff);
	res_data[9] = (VMUINT8) ((res_offset >> 8) & 0x000000ff);
	res_data[10] = (VMUINT8) ((res_offset >> 16) & 0x000000ff);
	res_data[11] = (VMUINT8) ((res_offset >> 24) & 0x000000ff);

		/* file handle in next 4 bytes */
		res_data[12] = (VMUINT8) (pcb->fileHandle & 0x000000ff);
		res_data[13] = (VMUINT8) ((pcb->fileHandle >> 8) & 0x000000ff);
		res_data[14] = (VMUINT8) ((pcb->fileHandle >> 16) & 0x000000ff);
		res_data[15] = (VMUINT8) ((pcb->fileHandle >> 24) & 0x000000ff);
	}
	
	vm_res_id_add(image_id, res_data, size);

	if (pcb->res_buf == NULL)
	{	
		vm_free(res_buf);
	}
	
	return (VMUINT8*)res_data;
}

VMUINT8 *vm_res_get_image_with_header(VMUINT32 image_id)
{
	VMUINT8 * ptr;
  ptr = vm_res_get_image_and_size(image_id, NULL);
  
  if(ptr ==  NULL)
  	return ptr;
  	
	return (VMUINT8*)((VMINT)ptr - vm_get_res_header());
}

VMUINT8 *vm_res_get_image_and_size_with_header(VMUINT32 image_id, VMUINT32 *size)
{
	VMUINT8 * ptr;
  ptr = vm_res_get_image_and_size(image_id, size);
    
  if(ptr ==  NULL)
  	return ptr;
  	
	return (VMUINT8*)((VMINT)ptr - vm_get_res_header());	
}

/*****************************************************************************
 * FUNCTION
 *  vm_res_get_audio
 * DESCRIPTION
 *  Get audio data by ID. Will alloc memory, need to use FreeRes/vm_res_delete to free.
 *  Only alloc 1 time for the same ID.
 * PARAMETERS
 *  audio_id         [IN]      ID to get.
 * RETURNS
 *  VMUINT8 *                  Audio pointer of the ID
 *****************************************************************************/
VMUINT8 *vm_res_get_audio(VMUINT32 audio_id)
{
    return vm_res_get_image(audio_id);
}


/*****************************************************************************
 * FUNCTION
 *  vm_res_id_add
 * DESCRIPTION
 *  Management the list of current allocated resource. This is the add node func
 * PARAMETERS
 *  id         [IN]      ID of the resource
 *  res_data   [IN]      Address of the resource
 * RETURNS
 *  VM_RES_SUCCESS
 *  VM_RES_PARAM_ERROR
 *****************************************************************************/
static VMINT32 vm_res_id_add(VMUINT32 id, VMUINT8 *res_data, VMUINT32 res_size)
{
    VM_RES_LIST *new_node;
	
	vm_resource_contex* p_contex = NULL;
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return VM_RES_OUT_OF_MEM;

    if (res_data == NULL)
    {
        return VM_RES_PARAM_ERROR;
    }

    new_node = vm_malloc(sizeof(VM_RES_LIST));
    VM_RES_CHECK_MEM_ALLOC(new_node);

    new_node->data = res_data;
	new_node->size= res_size;
    new_node->id = id;
    new_node->next = p_contex->header_node;

    p_contex->header_node = new_node;
    p_contex->res_count++;
    
    return VM_RES_SUCCESS;
}



/*****************************************************************************
 * FUNCTION
 *  vm_res_delete
 * DESCRIPTION
 *  Management the list of current allocated resource. This is the delete node func
 * PARAMETERS
 *  id         [IN]      ID of the resource
 * RETURNS
 *  VM_RES_SUCCESS
 *  VM_RES_PARAM_ERROR
 *  VM_RES_ITEM_NOT_FOUND
 *****************************************************************************/
VMINT32 vm_res_delete(VMUINT32 id)
{
    VM_RES_LIST *prev_node = NULL;
    VM_RES_LIST *cur_node = NULL;
	vm_resource_contex* p_contex = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();
    _vm_pcb_t* pcb = NULL;
	_vm_sm_t * sm_ptr = NULL;
	
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL && 
		(sm_ptr  = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9)) == NULL)
    {
		return VM_RES_OUT_OF_MEM;
    }
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return VM_RES_OUT_OF_MEM;

	cur_node = p_contex->header_node;
	
    while (cur_node != NULL)
    {
        if (cur_node->id == id)
        {
            /* Found the ID */
            if (prev_node == NULL)
            {
                /* first item, need modify header */
                p_contex->header_node = cur_node->next;
            }
            else
            {
                prev_node->next = cur_node->next;
            }
			
			if((pcb != NULL && pcb->resfileHandle != 1) || (sm_ptr != NULL && sm_ptr->resfileHandle != 1))
            {
            	vm_free(cur_node->data);
			}
			
            vm_free(cur_node);
            return VM_RES_SUCCESS;
        }
        prev_node = cur_node;
        cur_node = cur_node->next;
    }

    return VM_RES_ITEM_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  vm_res_id_delete_all
 * DESCRIPTION
 *  Management the list of current allocated resource. This is the delete all node func
 * PARAMETERS
 *  void
 * RETURNS
 *  VM_RES_SUCCESS
 *****************************************************************************/
VMINT32 vm_res_id_delete_all(VMINT is_rom)
{
    VM_RES_LIST *cur_node = NULL;
	vm_resource_contex* p_contex = NULL;
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return VM_RES_OUT_OF_MEM;

	cur_node = p_contex->header_node;
	
    while (cur_node != NULL)
    {
        p_contex->header_node = p_contex->header_node->next;

		if(!is_rom)
		{
			vm_free(cur_node->data);
        }
		
        vm_free(cur_node);

        cur_node = p_contex->header_node;
    }

    return VM_RES_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  vm_res_id_search
 * DESCRIPTION
 *  Management the list of current allocated resource. This is the find node func
 * PARAMETERS
 *  id         [IN]         ID of the resource
 * RETURNS
 *  VMUINT8 *               Address of the Node. NULL for not found
 *****************************************************************************/
static VMUINT8 *vm_res_id_search(VMUINT32 id, VMUINT32* res_size)
{
    VM_RES_LIST *cur_node = NULL;
	vm_resource_contex* p_contex = NULL;
	
	p_contex = vm_res_get_contex_data();

	if(p_contex == NULL )
		return NULL;

	cur_node = p_contex->header_node;

    while (cur_node != NULL)
    {
        if (cur_node->id == id)
        {
        	*res_size = cur_node->size;
            return cur_node->data;
        }
        cur_node = cur_node->next;
    }
    return NULL;
}

static VMINT vm_res_get_name_from_memory(VMWSTR filename, VMINT file_type, VMUINT32 image_id, VMUINT8 *res_src, VMWSTR image_filename)
{
	VMWCHAR temp1[16];
	VMWCHAR temp2[16];
	VMINT result = -1;

	
	vm_get_filename(filename,temp1);


	if(file_type == 1)
	{
		kal_wstrcpy((WCHAR*)temp2, (const WCHAR*)kal_toWCHAR("wav"));
		result = 0;
	}
	else
	{
		VMUINT8 img_type = res_src[0];

		switch (img_type)
		{
			case GDI_IMAGE_TYPE_GIF:
				kal_wstrcpy((WCHAR*)temp2, (const WCHAR*)kal_toWCHAR("gif"));
				result = 0;
				break;
			case GDI_IMAGE_TYPE_JPG:
				kal_wstrcpy((WCHAR*)temp2, (const WCHAR*)kal_toWCHAR("jpg"));
				result = 0;
				break;
			case GDI_IMAGE_TYPE_AB2:
				kal_wstrcpy((WCHAR*)temp2, (const WCHAR*)kal_toWCHAR("abm"));
				result = 0;
				break;
			default:
				MMI_TRACE(MMI_MRE_TRC_MOD_VMRES, TRC_MRE_VMRES_08, img_type);
				return result;
		}
	}
	kal_wsprintf((WCHAR*)image_filename,"%w.%u.%w",temp1,image_id,temp2);

	return result;
}

static VMINT vm_res_extract_file(VMWSTR filename, VMINT file_type, VMUINT32 begin_id, VMWSTR image_filepath)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	VMUINT32 index_size = 0;
	VMUINT8 *index_buff = NULL;
	VMUINT32 image_id = begin_id;
	VMUINT32 res_offset;	 
	VMINT fileHandle;
	VMWCHAR *image_filepath_temp = NULL;
	VMINT mem_idx;
	
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	image_filepath_temp = _vm_kernel_calloc(sizeof(VMWCHAR) * (MAX_APP_NAME_LEN + 1));

	if(image_filepath_temp == NULL)
		return 0;
	
	index_buff = vm_load_resource_from_file(filename, "mre-2.0", (VMINT *)&index_size);
    
	for (mem_idx=0; mem_idx<MRE_SUPPORT_MAX_APP_NUM; mem_idx++)
	{
	   if (g_app_mem_info[mem_idx].mem_base == NULL)
	   {
		   break;
	   }
	}

	if(mem_idx == MRE_SUPPORT_MAX_APP_NUM)
		return 0;

	if(index_size > 0 && index_buff != NULL)
	{
		while(1)
		{
			VMUINT8 *res_buf = NULL;
			VMUINT32 res_size = 0;
			VMWCHAR name[48];
			VMUINT32 written = 0;
			
			res_offset = vm_res_get_offset(image_id, index_buff, &res_size);

			if(res_size == 0)
				break;
			
			res_buf = (VMUINT8 *)applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MRE_APP0+mem_idx, res_size);

			if( res_buf == NULL )
			{
				_vm_kernel_free(image_filepath_temp);
	            return 0;
			}
			
			vm_resource_get_data_from_file(filename, res_buf, res_offset, res_size);
			vm_res_get_name_from_memory(filename, file_type, image_id,res_buf, name);
      		vm_wstrncpy(image_filepath_temp, image_filepath, MAX_APP_NAME_LEN);
			kal_wstrcat((WCHAR*)image_filepath_temp, (WCHAR*)name);

	        fileHandle = (VMINT)FS_Open((WCHAR*)image_filepath_temp, FS_READ_WRITE | FS_CREATE);
			
	        if (fileHandle < 0) 
			{
				applib_mem_ap_free(res_buf);
				_vm_kernel_free(image_filepath_temp);
	            return 0;
	        }
            
			if(file_type == 2)
			{
			    FS_Write(fileHandle, (void*)(res_buf + 8), res_size-8 , (UINT *)&written);
            }
            else
            {
			    FS_Write(fileHandle, (void*)(res_buf), res_size , (UINT *)&written);
            }
            
			applib_mem_ap_free(res_buf);
			
			FS_Close(fileHandle);

			image_id++;
			
		}
	}
	
	_vm_kernel_free(image_filepath_temp);
	return 0;
}


static VMINT vm_res_delete_file(VMWSTR filename, VMINT file_type, VMUINT32 begin_id, VMWSTR image_filepath)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	VMUINT32 index_size = 0;
	VMUINT8 *index_buff = NULL;
	VMUINT32 image_id = begin_id;
	VMWCHAR *image_filepath_temp = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	image_filepath_temp = _vm_kernel_calloc(sizeof(VMWCHAR) * (MAX_APP_NAME_LEN + 1));

	if(image_filepath_temp == NULL)
		return 0;

	index_buff = vm_load_resource_from_file(filename, "mre-2.0", (VMINT *)&index_size);

	if(index_size > 0 && index_buff != NULL)
	{
		while(1)
		{
			VMUINT8 res_buf ;
			VMUINT32 res_size = 0;
			VMWCHAR name[48];
			VMUINT32 res_offset;	 
			
			res_offset = vm_res_get_offset(image_id, index_buff, &res_size);

			if(res_size == 0)
				break;
			
			res_size = 1;

			vm_resource_get_data_from_file(filename, &res_buf, res_offset, res_size);
						
			vm_res_get_name_from_memory(filename, file_type, image_id,&res_buf, name);
    		vm_wstrncpy(image_filepath_temp, image_filepath, MAX_APP_NAME_LEN);
			kal_wstrcat((WCHAR*)image_filepath_temp, (WCHAR*)name);

	        FS_Delete((WCHAR*)image_filepath_temp);

			image_id++;
			
		}
	}
	
	_vm_kernel_free(image_filepath_temp);

	return 0;
}


VMINT vm_res_extract_images (VMWSTR filename, VMUINT32 image_begin_id, VMWSTR image_filepath)
{
	return vm_res_extract_file(filename, 2, image_begin_id, image_filepath);
}

VMINT vm_res_extract_audios (VMWSTR filename, VMUINT32 audio_begin_id,VMWSTR audio_filepath)
{
	return vm_res_extract_file(filename, 1, audio_begin_id, audio_filepath);
}

VMINT vm_res_delete_images (VMWSTR filename, VMUINT32 image_begin_id, VMWSTR image_filepath)
{
	return vm_res_delete_file(filename, 2, image_begin_id, image_filepath);
}

VMINT vm_res_delete_audios (VMWSTR filename, VMUINT32 audio_begin_id,VMWSTR audio_filepath)
{
	return vm_res_delete_file(filename, 1, audio_begin_id, audio_filepath);
}


static VMINT vm_res_generate_filename(VMWSTR filename, VMINT file_type, VMUINT32 image_id, VMWSTR image_filename)
{
	VMUINT32 index_size = 0;
	VMUINT8 *index_buff = NULL;
	VMUINT32 res_offset;	 
	VMINT result = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	index_buff = vm_load_resource_from_file(filename, "mre-2.0", (VMINT *)&index_size);

	if(index_size > 0 && index_buff != NULL)
	{
		VMUINT8 res_buf;
		VMUINT32 res_size = 0;

		res_offset = vm_res_get_offset(image_id, index_buff, &res_size);

		if(res_size == 0)
			goto finish;
						
		vm_resource_get_data_from_file(filename, &res_buf, res_offset, 1);
						
		vm_res_get_name_from_memory(filename, file_type, image_id,&res_buf, image_filename);

		result = kal_wstrlen((WCHAR *)image_filename);

		vm_free(index_buff);
	}

finish:
	return result;
	
}


VMINT vm_res_generate_image_filename(VMWSTR filename, VMUINT32 image_id, VMWSTR image_filename)
{
	return vm_res_generate_filename(filename, 2, image_id, image_filename);
}

VMINT vm_res_generate_audio_filename(VMWSTR filename, VMUINT32 audio_id, VMWSTR audio_filename)
{
	return vm_res_generate_filename(filename, 1, audio_id, audio_filename);
}


#endif /* __MRE_LIB_APPRES__ */

