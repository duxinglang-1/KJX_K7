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
 * elfldr.h
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

#ifndef ELFLDR_H_
#define ELFLDR_H_
#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__
#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "elf.h"

typedef struct {
	VMFILE file;
	vm_elf_head_t elf_head;
} vm_elf_handle_t;

/**
 * Open ELF file.
 */
int open_elf(VMWSTR filename, vm_elf_handle_t* handle);

/**
 * Close ELF file.
 */
int close_elf(vm_elf_handle_t* handle);

/**
 * Get ELF program head.
 */
int read_elf_prog_head(vm_elf_handle_t* handle, vm_elf_prog_head_t* head);

/**
 * Get ELF program head by index.
 */
int read_elf_prog_head_by_index(vm_elf_handle_t *handle, int idx, vm_elf_prog_head_t *head);

/**
 * Get ELF section by index.
 */
int read_elf_section_head(vm_elf_handle_t* handle, int idx, vm_elf_section_head_t* head);

/**
 * Get ELF section by name.
 */
int read_elf_section_head_by_name(vm_elf_handle_t* handle, char* name, 
	char* string_table, int table_size, vm_elf_section_head_t* head);

/**
 * Get ELF section head by name.
 */
vm_elf_section_head_t* get_elf_section_head_by_name(char *name,
	char *str_tab, int tab_size, vm_elf_section_head_t *sh,
	int sh_num);

/**
 * Get string from string table.
 */
char* get_elf_string(char* string_table, int table_size, int index);

/**
 * Read section into pre-allocated memory.
 */
int read_elf_section(vm_elf_handle_t* handle, vm_elf_section_head_t* head, void* buf);

vm_file_type_enum vm_get_file_type(VMWSTR filename);

VMINT vm_get_section_info_from_file(VMWSTR filename, vm_simple_elf_info *p_info);

VMINT vm_get_section_info_from_rom(VMUINT8* image, vm_simple_elf_info *p_info);

VMINT vm_get_compress_info_from_file(VMWSTR filename, vm_compress_elf_info *p_info);

VMINT vm_get_compress_info_from_rom(VMUINT8* image, vm_compress_elf_info *p_info);

#ifdef __cplusplus
}
#endif

#endif

#endif
