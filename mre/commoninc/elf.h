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
 * elf.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * elf
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

#ifndef ELF_H_
#define ELF_H_
#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__
#ifdef __cplusplus
extern "C" {
#endif


#define VM_EI_NIDENT	16

#define VM_ET_NONE		0
#define VM_ET_REL		1
#define VM_ET_EXEC		2
#define VM_ET_DYN		3
#define VM_ET_CORE		4
#define VM_ET_LOPROC	0xff00
#define VM_ET_HIPROC	0xffff

#define VM_EM_ARM		40

#define VM_EV_NONE		0
#define VM_EV_CURRENT	1

#define VM_SHN_UNDEF		0
#define VM_SHN_LORESERVE	0xff00
#define VM_SHN_LOPROC		0xff00
#define VM_SHN_HIPROC		0xff1f
#define VM_SHN_ABS			0xfff1
#define VM_SHN_COMMON		0Xfff2
#define VM_SHN_HIRESERVE	0xffff

typedef struct {
	unsigned char e_ident[VM_EI_NIDENT];
	VMUINT16 e_type;
	VMUINT16 e_machine;
	VMUINT e_version;
	VMUINT e_entry;
	VMUINT e_phoff;
	VMUINT e_shoff;
	VMUINT e_flags;
	VMUINT16 e_ehsize;
	VMUINT16 e_phentsize;
	VMUINT16 e_phnum;
	VMUINT16 e_shentsize;
	VMUINT16 e_shnum;
	VMUINT16 e_shstrndx;
} vm_elf_head_t;

#define VM_SHT_NULL		0
#define VM_SHT_PROGBITS	1
#define VM_SHT_SYMTAB		2
#define VM_SHT_STRTAB		3
#define VM_SHT_RELA		4
#define VM_SHT_HASH		5
#define VM_SHT_DYNAMIC		6
#define VM_SHT_NOTE		7
#define VM_SHT_NOBITS		8
#define VM_SHT_REL			9
#define VM_SHT_SHLIB		10
#define VM_SHT_DYNSYM		11	
#define VM_SHT_LOPROC		0x70000000
#define VM_SHT_HIPROC		0x7fffffff
#define VM_SHT_LOUSER		0x80000000
#define VM_SHT_HIUSER		0x8fffffff

#define VM_SHF_WRITE		0x1
#define VM_SHF_ALLOC		0x2
#define VM_SHF_EXECINSTR	0x4
#define VM_SHF_MASKPROC	0xf0000000

typedef struct {
	VMUINT sh_name;
	VMUINT sh_type;
	VMUINT sh_flags;
	VMUINT sh_addr;
	VMUINT sh_offset;
	VMUINT sh_size;
	VMUINT sh_link;
	VMUINT sh_info;
	VMUINT sh_addralign;
	VMUINT sh_entsize;
} vm_elf_section_head_t;

typedef struct {
	VMUINT st_name;
	VMUINT st_value;
	VMUINT st_size;
	unsigned char st_info;
	unsigned char st_other;
	VMUINT16 st_shndx;
} vm_elf_symtbl_entry_t;


typedef struct {
	int	d_tag;
	union {
		VMUINT	d_val;
		VMUINT	d_ptr;
	} d_un;
} vm_elf_dyn_t;



typedef struct {
	VMUINT r_offset;
	VMUINT r_info;
} vm_elf_rel_t;

typedef struct {
	VMUINT r_offset;
	VMUINT r_info;
	VMINT r_addend;
} vm_elf_rela_t;

#define VM_PT_NULL		0
#define VM_PT_LOAD		1
#define VM_PT_DYNAMIC	2
#define VM_PT_INTERP	3
#define VM_PT_NOTE		4
#define VM_PT_SHLIB	5
#define VM_PT_PHDR		6
#define VM_PT_LOPROC	0x70000000
#define VM_PT_HIPROC	0x7fffffff

#define VM_PF_X		1
#define VM_PF_W		2
#define VM_PF_R		4
#define VM_PF_MASKPROC	0xf0000000

typedef struct {
	VMUINT p_type;
	VMUINT p_offset;
	VMUINT p_vaddr;
	VMUINT p_paddr;
	VMUINT p_filesz;
	VMUINT p_memsz;
	VMUINT p_flags;
	VMUINT p_align;
} vm_elf_prog_head_t;

#define VM_EX_IOERR	-1
#define VM_EX_FMTERR	-2
#define VM_EX_NOMEM	-3


typedef struct {
	char*        s_tab;
	VMUINT  s_size;
} vm_elf_tring;


/*
 * Macros for accessing the fields of r_info.
 */
#define VM_ELF32_R_SYM(info)	((info) >> 8)
#define VM_ELF32_R_TYPE(info)	((info) & 0xff)

/*
 * Macro for constructing r_info from field values.
 */
#define VM_ELF32_R_INFO(sym, type)	(((sym) << 8) + (unsigned char)(type))

/*
 * Macros for accessing the fields of st_info.
 */
#define VM_ELF32_ST_BIND(info)		((info) >> 4)
#define VM_ELF32_ST_TYPE(info)		((info) & 0xf)

/*
 * Macro for constructing st_info from field values.
 */
#define VM_ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

/*
 * Values for relocation
 */
#define	VM_R_ARM_NONE		 0
#define	VM_R_ARM_PC24		 1
#define	VM_R_ARM_ABS32		 2
#define	VM_R_ARM_REL32		 3
#define	VM_R_ARM_PC13		 4
#define	VM_R_ARM_ABS16		 5
#define	VM_R_ARM_ABS12		 6
#define	VM_R_ARM_THM_ABS5	 7
#define	VM_R_ARM_ABS8		 8
#define	VM_R_ARM_SBREL32	 9
#define	VM_R_ARM_THM_PC22	 10
#define	VM_R_ARM_THM_PC8	 11
#define	VM_R_ARM_AMP_VCALL9 12
#define	VM_R_ARM_SWI24		 13
#define	VM_R_ARM_THM_SWI8	 14
#define	VM_R_ARM_XPC25		 15
#define	VM_R_ARM_THM_XPC22	 16
#define	VM_R_ARM_COPY       20	/* Copy data from shared object. */
#define	VM_R_ARM_GLOB_DAT	 21	/* Set GOT entry to data address. */
#define	VM_R_ARM_JUMP_SLOT	 22	/* Set GOT entry to code address. */
#define	VM_R_ARM_RELATIVE	 23	/* Add load address of shared object. */
#define	VM_R_ARM_GOTOFF	 24	/* Add GOT-relative symbol address. */
#define	VM_R_ARM_GOTPC		 25	/* Add PC-relative GOT table address. */
#define	VM_R_ARM_GOT32		 26	/* Add PC-relative GOT offset. */
#define	VM_R_ARM_PLT32		 27	/* Add PC-relative PLT offset. */
#define VM_R_ARM_CALL       28
#define VM_R_ARM_JUMP24     29
#define	VM_R_ARM_COUNT		 33	/* Count of defined relocation types. */

/*
 * Symbol bind type
 */
#define	VM_STB_LOCAL        0
#define	VM_STB_GLOBAL       1
#define	VM_STB_WEAK         2
#define	VM_STB_LOPROC       13
#define	VM_STB_HIPROC       15

/*
 * Symbol type
 */
#define	VM_STT_NOTYPE       0
#define	VM_STT_OBJECT       1
#define	VM_STT_FUNC         2
#define	VM_STT_SECTION      3
#define	VM_STT_FILE         4
#define	VM_STT_LOPROC       13
#define	VM_STT_HIPROC       15

/*
 * sh_flags
 */
#define VM_SHF_WRITE	     0x1
#define VM_SHF_ALLOC	     0x2
#define VM_SHF_EXECINSTR	 0x4
#define VM_SHF_MASKPROC	 0xf0000000



/* Values for d_tag. */
#define VM_DT_NULL		0	/* Terminating entry. */
#define VM_DT_NEEDED	1	/* String table offset of a needed sharedlibrary. */
#define VM_DT_PLTRELSZ	2	/* Total size in bytes of PLT relocations*/
#define VM_DT_PLTGOT	3	/* Processor-dependent address*/
#define VM_DT_HASH		4	/* Address of symbol hash table. */
#define VM_DT_STRTAB	5	/* Address of string table. */
#define VM_DT_SYMTAB	6	/* Address of symbol table. */
#define VM_DT_RELA		7	/* Address of ElfNN_Rela relocations. */
#define VM_DT_RELASZ	8	/* Total size of ElfNN_Rela relocations. */
#define VM_DT_RELAENT	9	/* Size of each ElfNN_Rela relocation entry. */
#define VM_DT_STRSZ	10	/* Size of string table. */
#define VM_DT_SYMENT	11	/* Size of each symbol table entry. */
#define VM_DT_INIT		12	/* Address of initialization function*/
#define VM_DT_FINI		13	/* Address of finalization function*/
#define VM_DT_SONAME	14	/* String table offset of shared object name. */
#define VM_DT_RPATH	15	/* String table offset of library path.*/
#define VM_DT_SYMBOLIC	16	/* Indicates "symbolic" linking. */
#define VM_DT_REL		17	/* Address of ElfNN_Rel relocations. */
#define VM_DT_RELSZ	18	/* Total size of ElfNN_Rel relocations. */
#define VM_DT_RELENT	19	/* Size of each ElfNN_Rel relocation. */
#define VM_DT_PLTREL	20	/* Type of relocation used for PLT*/
#define VM_DT_DEBUG	21	/* Reserved (not used). unused in ARM*/
#define VM_DT_TEXTREL	22	/* Indicates there may be relocations in non-writable segments*/
#define VM_DT_JMPREL	23	/* Address of PLT relocations*/
#define	VM_DT_BIND_NOW	24	

#define	VM_DT_LOPROC	0x70000000	/* First processor-specific type. */
#define	VM_DT_HIPROC	0x7fffffff	/* Last processor-specific type. */


/* file type */
typedef enum
{
	VM_VXP_ADS,            /* 0 */
    VM_VSM_ADS,            /* 1 */
    VM_VXP_RVCT,           /* 2 */
    VM_VSM_RVCT,           /* 3 */
    VM_VSO_RVCT,           /* 4 */
    VM_SIMPLE_VXP_ADS,     /* 5 */
    VM_VXP_GCC,            /* 6 */
    VM_VSO_GCC,            /* 7 */
    VM_VSM_GCC             /* 8 */
}vm_file_type_enum;

typedef struct 
{
	VMUINT ro_offset;
	VMUINT ro_size;
	VMUINT org_ro_size;
	VMUINT rw_offset;
	VMUINT rw_size;
	VMUINT org_rw_size;
	VMUINT zi_size;
	VMUINT res_offset;
	VMUINT res_size;
} vm_simple_elf_info;

typedef struct 
{
	VMUINT pt_load_old_filesize;
	VMUINT pt_load_new_offset;
	VMUINT pt_load_new_filesize;
} vm_compress_elf_info;

#ifdef __cplusplus
}
#endif

#endif

#endif /* __MRE_CORE_BASE__ */

