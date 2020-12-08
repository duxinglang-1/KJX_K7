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
 *    vmloader.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    vxp/vsm/vso loader.
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

#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__
#include "Lzmadec.h"
#include <stdlib.h>
#include "kal_public_api.h"
#include "app_zlib.h"
#include "fs_func.h"
#include "vmloader.h"
#include "cache_sw.h"

#include "vmdl.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmlog.h"
#include "elf.h"
#include "elfldr.h"
#include "vmstdlib.h"

#include "vmopt.h"
#include "vmmem.h"
#include "vmgettag.h"
#include "vmcert.h"

#include "MMI_trc.h"
#include "MMI_mre_trc.h"
#include "devconfigdef.h"
#include "DevConfigGprot.h"
#include "app_mem.h"

#include "vmenv.h"
#include "med_smalloc.h"
#include "vmres.h" 
#include "vmpermng.h"
#include "vmresmng.h"

extern VMINT * _vm_per_get_mre_fun_list(void);
extern void _vm_per_clear_mre_fun_list(void);

extern VMINT vm_ce_merge_permission(VMWSTR filename);

#define min2(a, b) ((a) <= (b) ? (a) : (b))
#define max2(a, b) ((a) >= (b) ? (a) : (b))

static void vm_flush_icache(VMUINT8 *codeBase, VMUINT length)
{
#if !defined(MRE_ON_MODIS) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    VMUINT begin, end;
    
    begin = (VMUINT)codeBase;
    end = (VMUINT)(codeBase + length);
    begin = begin / CPU_CACHE_LINE_SIZE * CPU_CACHE_LINE_SIZE;
    end = (end + CPU_CACHE_LINE_SIZE - 1) / CPU_CACHE_LINE_SIZE * CPU_CACHE_LINE_SIZE;
    clean_dcache(begin, end - begin);
    invalidate_icache(begin, end - begin);
#endif
}

static VMINT is_rorwpi_file(vm_file_type_enum file_type)
{
    switch (file_type) {
    default:
    case VM_VXP_ADS:
    case VM_VSM_ADS:
    case VM_SIMPLE_VXP_ADS:
        return 1;
    case VM_VSO_RVCT:
    case VM_VXP_RVCT:
    case VM_VXP_GCC:
    case VM_VSO_GCC:
	case VM_VSM_RVCT:
	case VM_VSM_GCC:
        return 0;
    }
}

static KAL_ADM_ID g_unzip_adm_id = NULL;

static void *vm_pmng_unzip_malloc(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr = NULL;
    
    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;
    
    buffer_ptr = kal_adm_alloc(g_unzip_adm_id, total_bytes);

    ASSERT(buffer_ptr != NULL);

    return buffer_ptr;

}

static void vm_pmng_unzip_free(void *opaque, void *address)
{
    kal_adm_free(g_unzip_adm_id, address);
    return;
}

static void *vm_zimage_malloc(void *p, unsigned int size)
{
    void *buffer_ptr = NULL;
	
    buffer_ptr = kal_adm_alloc(g_unzip_adm_id, size);


    return buffer_ptr;
}

static void vm_zimage_free(void *p, void *address)
{
    kal_adm_free(g_unzip_adm_id, address);
    return;
}

static VMINT vm_pmng_unzip(VMINT zip_type, void *target, VMUINT target_size, const void *source, VMUINT size)
{
	VMINT ret;

	if(zip_type == 2)
	{
		ELzmaStatus status;
		ISzAlloc alloc = { vm_zimage_malloc, vm_zimage_free };
		VMUINT source_size = size;
		
		source_size -= 5;
		ret = LzmaDecode(target, &target_size, (unsigned char *)source + 5, &source_size,
				  (unsigned char *)source, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &alloc);

		if(0 != ret)
		{
			ret = VM_LOAD_ERR_UNZIP;
		}
		
		return ret;

	}
	else
	{
		VMUINT p_size = target_size;
		ret = uncompress_mtk(target, (uLongf *)&p_size, source, size, vm_pmng_unzip_malloc, vm_pmng_unzip_free);
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MSG_LDR_UNZIP, size, target_size, p_size, ret);
		if (p_size != target_size) {
			ret = VM_LOAD_ERR_UNZIP;
		}
		return ret;
	}
}




static void *load_alloc_working_buffer(VMUINT size, VMUINT asm_index)
{
    void *ptr = NULL;
    
#ifdef __MRE_MEDIA_BUF__ /* PHASE OUT! */
    if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
    {
      if (media_get_ext_buffer_cacheable(MOD_MMI, &ptr, size) != 0)
      {
          ptr = NULL;
      }
    }
    else
#endif
    {
        ptr = (void *)applib_mem_ap_alloc(asm_index, size);
    }
    return ptr;
}

static void load_free_working_buffer(void *ptr)
{
#ifdef __MRE_MEDIA_BUF__ /* PHASE OUT! */
    if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
    {
        media_free_ext_buffer(MOD_MMI, &ptr);
    }
    else
#endif
    {
        applib_mem_ap_free(ptr);
    }
}

static VMINT load_rom_zipped_ads(vm_load_context_t *context)
{
    vm_simple_elf_info elf_info;
    VMUINT8* execImage;
    VMINT runtime_in_app_mem;
    VMUINT8 *runtime_base;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    execImage = vm_get_execrom_ptr((VMWCHAR*)context->fileName);
    if (execImage == NULL) {
        lerr = 1; goto bad;
    }
    
    vm_get_section_info_from_rom(execImage - 4, &elf_info);
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (elf_info.org_ro_size + elf_info.org_rw_size * 2 + PARAM_BLOCK_SIZE)) {
            lerr = 2; info = context->load_size; goto bad;
        }
        
        if ((elf_info.org_ro_size + elf_info.org_rw_size + VM_UNZIP_MEM_SIZE) <= context->load_size) {
            runtime_in_app_mem = 1;
            runtime_base = context->load_buffer + context->load_size - VM_UNZIP_MEM_SIZE;
        }
        else {
            runtime_in_app_mem = 0;
            runtime_base = load_alloc_working_buffer(VM_UNZIP_MEM_SIZE, context->asm_index);
            if (runtime_base == NULL) {
                lerr = 3; info = VM_UNZIP_MEM_SIZE; goto bad;
            }
        }
            
        g_unzip_adm_id = kal_adm_create(runtime_base, VM_UNZIP_MEM_SIZE, NULL, KAL_TRUE);
        
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer, elf_info.org_ro_size, execImage+elf_info.ro_offset, elf_info.ro_size);
        if (ret != 0) {
            lerr = 4; goto free_rt_base;
        }
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer + elf_info.org_ro_size, elf_info.org_rw_size, execImage+elf_info.rw_offset, elf_info.rw_size);
        if (ret != 0) {
            lerr = 5; goto free_rt_base;
        }
        
        /*kal_adm_delete(g_unzip_adm_id);*/ g_unzip_adm_id = NULL;
        if (runtime_in_app_mem==0) load_free_working_buffer(runtime_base);
        runtime_base = NULL;
    }
    
    // it's safe to do this in read preload info mode
    context->codeBase = context->load_buffer;
    context->codeSize = elf_info.org_ro_size;
    context->dataBase = context->codeBase + context->codeSize + elf_info.org_rw_size + PARAM_BLOCK_SIZE;
    context->dataSize = elf_info.org_rw_size + elf_info.zi_size;
    
    context->roSize = elf_info.org_ro_size;
    context->rwSize = elf_info.org_rw_size;
    context->ziSize = elf_info.zi_size;
    
    context->entry = context->codeBase;
    
    return 0;
    
free_rt_base:
    if (!runtime_in_app_mem && runtime_base) {
        load_free_working_buffer(runtime_base);
        runtime_base = NULL;
    }
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_Z_ADS, lerr, info, ret);
    {
        static const VMINT err_map[] = {VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM,
                        VM_LOAD_ERR_UNZIP, VM_LOAD_ERR_UNZIP };
        return err_map[lerr];
    }
}

#ifdef __MRE_VM_LOAD_UNALIGNED__
    #define UCOPY(x) vm_memcpy(&(_##x), x, sizeof(*x)); (x) = &(_##x)
#else
    #define UCOPY(x) ((void)(&x))
#endif

static VMINT load_rom_normal_ads(vm_load_context_t *context)
{
    VMUINT8* execImage;
    vm_elf_head_t *head;
    vm_elf_prog_head_t *ph;
    vm_elf_section_head_t *str_sh, *rw_sh, *ro_sh;
#ifdef __MRE_VM_LOAD_UNALIGNED__
    vm_elf_head_t _head;
    vm_elf_prog_head_t _ph;
    vm_elf_section_head_t _str_sh, _rw_sh, _ro_sh;
#endif
    char *str_tab;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    execImage = vm_get_execrom_ptr((VMWCHAR*)context->fileName);
    if (execImage == NULL) {
        lerr = 1; goto bad;
    }
    
    head = (vm_elf_head_t *)execImage;
    if (strncmp((char *)head->e_ident, "\x7f""ELF", 4) != 0) {
        lerr = 2; info = *(VMINT *)(head->e_ident); goto bad;
    }

    head = (vm_elf_head_t *)execImage;
    UCOPY(head);
    ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
    UCOPY(ph);
    str_sh = (vm_elf_section_head_t *)(execImage + head->e_shoff + head->e_shstrndx * head->e_shentsize);
    UCOPY(str_sh);
    // string table in ROM always
    str_tab = (char *)(execImage + str_sh->sh_offset);
    ro_sh = get_elf_section_head_by_name("ER_RO", str_tab, str_sh->sh_size, 
                (vm_elf_section_head_t *)(execImage + head->e_shoff), head->e_shnum);
    UCOPY(ro_sh);
    rw_sh = get_elf_section_head_by_name("ER_RW", str_tab, str_sh->sh_size, 
                (vm_elf_section_head_t *)(execImage + head->e_shoff), head->e_shnum);
    UCOPY(rw_sh);

#ifdef __MRE_VM_LOAD_ADS_ROM_INRAM__
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (ro_sh->sh_size + rw_sh->sh_size * 2 + PARAM_BLOCK_SIZE)) {
            lerr = 3; info = context->load_size; goto bad;
        }
        // copy code & rw to ram
        memcpy(context->load_buffer, execImage + ro_sh->sh_offset, ro_sh->sh_size);
        memcpy(context->load_buffer + ro_sh->sh_size, execImage + rw_sh->sh_offset, rw_sh->sh_size);
    }
    context->codeBase = context->load_buffer;
    context->codeSize = ro_sh->sh_size;
    context->dataBase = context->codeBase + context->codeSize + rw_sh->sh_size + PARAM_BLOCK_SIZE; // ro_sh->sh_size + rw_sh->sh_size == ph->p_filesz
    context->dataSize = (ph->p_memsz - ph->p_filesz) + rw_sh->sh_size;
#else
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        if (context->load_size < (rw_sh->sh_size + PARAM_BLOCK_SIZE)) {
            lerr = 3; info = context->load_size; goto bad;
        }
        // keep code & orig rw in ROM, save some memory so the usable app heap will increase
        //memcpy(context->load_buffer, execImage + rw_sh.sh_offset, rw_sh.sh_size); //the memcpy will be done by ADS init
    }
    context->codeBase = execImage + ro_sh->sh_offset;
    context->codeSize = ro_sh->sh_size;
    context->dataBase = context->load_buffer + PARAM_BLOCK_SIZE;
    context->dataSize = (ph->p_memsz - ph->p_filesz) + rw_sh->sh_size;
#endif
    
    context->roSize = ro_sh->sh_size;
    context->rwSize = rw_sh->sh_size;
    context->ziSize = ph->p_memsz - ph->p_filesz;
    
    context->entry = context->codeBase;
    
    return 0;

bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_N_ADS, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT };
        return err_map[lerr];
    }
}

static VMINT load_file_normal_ads(vm_load_context_t *context)
{
    vm_elf_handle_t handle;
    vm_elf_prog_head_t ph;
    vm_elf_section_head_t str_sh, rw_sh, ro_sh;
    char* str_tab = NULL;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    ret = open_elf(context->fileName, &handle);
    if (ret != 0) {
        lerr = 1; goto open_failed;
    }
    ret = read_elf_prog_head(&handle, &ph);
    if (ret != 0) {
        lerr = 2; goto read_hdr_failed;
    }
    ret = read_elf_section_head(&handle, handle.elf_head.e_shstrndx, &str_sh);
    if (ret != 0) {
        lerr = 3; info = handle.elf_head.e_shstrndx; goto read_hdr_failed;
    }
    str_tab = _vm_kernel_malloc(str_sh.sh_size);
    if (str_tab == NULL) {
        lerr = 4; info = str_sh.sh_size; goto read_hdr_failed;
    }
    ret = read_elf_section(&handle, &str_sh, str_tab);
    if (ret != 0) {
        lerr = 5; goto free_strtab;
    }
    ret = read_elf_section_head_by_name(&handle, "ER_RO", str_tab, str_sh.sh_size, &ro_sh);
    if (ret != 0) {
        lerr = 6; goto free_strtab;
    }
    ret = read_elf_section_head_by_name(&handle, "ER_RW", str_tab, str_sh.sh_size, &rw_sh);
    if (ret != 0) {
        lerr = 7; goto free_strtab;
    }
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (ro_sh.sh_size + rw_sh.sh_size * 2 + PARAM_BLOCK_SIZE)) {
            lerr = 8; info = context->load_size; goto free_strtab;
        }
        
        ret = read_elf_section(&handle, &ro_sh, context->load_buffer);
        if (ret != 0) {
            lerr = 9; goto free_strtab;
        }
        ret = read_elf_section(&handle, &rw_sh, context->load_buffer + ro_sh.sh_size);
        if (ret != 0) {
            lerr = 10; goto free_strtab;
        }
    }
    
    _vm_kernel_free(str_tab);
    close_elf(&handle);
    
    context->codeBase = context->load_buffer;
    context->codeSize = ro_sh.sh_size;
    // ro_sh.sh_size + rw_sh.sh_size == ph.p_filesz, 
    //   pcb->dataBase = imageMem + ph.p_filesz + PARAM_BLOCK_SIZE;
    context->dataBase = context->codeBase + context->codeSize + rw_sh.sh_size + PARAM_BLOCK_SIZE;
    context->dataSize = rw_sh.sh_size + (ph.p_memsz - ph.p_filesz);
    
    context->roSize = ro_sh.sh_size;
    context->rwSize = rw_sh.sh_size;
    context->ziSize = ph.p_memsz - ph.p_filesz;
    
    context->entry = context->codeBase;
    
    return 0;
    
free_strtab: 
    _vm_kernel_free(str_tab);
read_hdr_failed:
    close_elf(&handle);
open_failed:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_N_ADS, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, 
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT };
        return err_map[lerr];
    }
}

static VMINT load_file_zipped_ads(vm_load_context_t *context)
{
    vm_simple_elf_info elf_info;
    VMFILE handle;
    VMINT runtime_in_app_mem, rbuf_in_app_mem;
    VMUINT8 *runtime_base;
    VMUINT8 *rbuf; // read file buffer
    VMINT rbuf_size;
    VMUINT8 *mem_tail;
    VMUINT nread;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    vm_get_section_info_from_file(context->fileName, &elf_info);
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (elf_info.org_ro_size + elf_info.org_rw_size * 2 + PARAM_BLOCK_SIZE)) {
            lerr = 1; info = context->load_size; goto no_rt_base;
        }
        
        rbuf_size = max2(elf_info.ro_size, elf_info.rw_size);
        
        if ((elf_info.org_ro_size + elf_info.org_rw_size + VM_UNZIP_MEM_SIZE + rbuf_size) <= context->load_size)
        {
            /* both uncompress runtime memory and read file buffer can be in app memory */
            runtime_in_app_mem = 1;
            rbuf_in_app_mem = 1;
        }
        else if ((elf_info.org_ro_size + elf_info.org_rw_size + max2(VM_UNZIP_MEM_SIZE, rbuf_size)) <= context->load_size) 
        {
            if (max2(VM_UNZIP_MEM_SIZE, rbuf_size) == VM_UNZIP_MEM_SIZE) {
                runtime_in_app_mem = 1;
                rbuf_in_app_mem = 0;
            }
            else {
                runtime_in_app_mem = 0;
                rbuf_in_app_mem = 1;
            }
        }
        else if ((elf_info.org_ro_size + elf_info.org_rw_size + min2(VM_UNZIP_MEM_SIZE, rbuf_size)) <= context->load_size)
        {
            if (min2(VM_UNZIP_MEM_SIZE, rbuf_size) == VM_UNZIP_MEM_SIZE) {
                runtime_in_app_mem = 1;
                rbuf_in_app_mem = 0;
            }
            else {
                runtime_in_app_mem = 0;
                rbuf_in_app_mem = 1;
            }
        }
        else
        {
            /* neither uncompress runtime memory nor read file buffer can be in app memory */
            runtime_in_app_mem = 0;
            rbuf_in_app_mem = 0;
        }
        
        mem_tail = context->load_buffer + context->load_size;
        if (runtime_in_app_mem) {
            runtime_base = mem_tail = mem_tail - VM_UNZIP_MEM_SIZE;
        }
        else {
            runtime_base = load_alloc_working_buffer(VM_UNZIP_MEM_SIZE, context->asm_index);
            if (runtime_base == NULL) {
                lerr = 2; info = VM_UNZIP_MEM_SIZE; goto no_rt_base;
            }
        }
        
        if (rbuf_in_app_mem) {
            rbuf = mem_tail = mem_tail - rbuf_size;
        }
        else {
            rbuf = load_alloc_working_buffer(rbuf_size, context->asm_index);
            if (rbuf == NULL) {
                lerr = 3; info = rbuf_size; goto free_rt_base;
            }
        }
        
        g_unzip_adm_id = kal_adm_create(runtime_base, VM_UNZIP_MEM_SIZE, NULL, KAL_TRUE);
        
        handle = vm_file_open(context->fileName, MODE_READ, 1);
        if (handle < 0) {
            lerr = 4; info = handle; goto free_rbuf;
        }
        
        vm_file_seek(handle, elf_info.ro_offset, BASE_BEGIN);
        ret = vm_file_read(handle, rbuf, elf_info.ro_size, &nread);
        if (ret < 0) {
            lerr = 5; goto read_failed;
        }
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer, elf_info.org_ro_size, rbuf, elf_info.ro_size);
        if (ret != 0) {
            lerr = 6; goto read_failed;
        }
        
        vm_file_seek(handle, elf_info.rw_offset, BASE_BEGIN);
        ret = vm_file_read(handle, rbuf, elf_info.rw_size, &nread);   
        vm_file_close(handle); handle = -1;
        if (ret < 0) {
            lerr = 7; goto read_failed;
        }
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer + elf_info.org_ro_size, elf_info.org_rw_size, rbuf, elf_info.rw_size);
        if (ret != 0) {
            lerr = 8; goto read_failed;
        }
        
        /*kal_adm_delete(g_unzip_adm_id);*/ g_unzip_adm_id = NULL;
        if (rbuf_in_app_mem == 0) load_free_working_buffer(rbuf); 
        rbuf = NULL;
        if (runtime_in_app_mem == 0) load_free_working_buffer(runtime_base);
        runtime_base = NULL;
    }
    
    context->codeBase = context->load_buffer;
    context->codeSize = elf_info.org_ro_size;
    context->dataBase = context->codeBase + context->codeSize + elf_info.org_rw_size + PARAM_BLOCK_SIZE;
    context->dataSize = elf_info.org_rw_size + elf_info.zi_size;
    
    context->roSize = elf_info.org_ro_size;
    context->rwSize = elf_info.org_rw_size;
    context->ziSize = elf_info.zi_size;
    
    context->entry = context->codeBase;
    
    return 0;

read_failed:
    if (handle != -1) {
        vm_file_close(handle);
    }
free_rbuf:
    if (!rbuf_in_app_mem && rbuf) {
        load_free_working_buffer(rbuf);
        rbuf = NULL;
    }
free_rt_base:
    if (!runtime_in_app_mem && runtime_base) {
        load_free_working_buffer(runtime_base);
        runtime_base = NULL;
    }
no_rt_base:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_Z_ADS, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM, VM_LOAD_ERR_OOM,
             VM_LOAD_ERR_IO, VM_LOAD_ERR_IO, VM_LOAD_ERR_UNZIP, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_IO, 
             VM_LOAD_ERR_UNZIP };
        return err_map[lerr];
    }
}

// call this function when all data are in RAM
static VMINT do_sysv_loadfix(vm_load_context_t *context, vm_elf_head_t *elf_head, 
                                    char *str_tab, VMUINT str_size,
                                    vm_elf_section_head_t *sh_tab, VMINT sh_num)
{
    vm_elf_section_head_t *rw_sh, *ro_sh, *sh;
    vm_elf_rel_t *prel;
    VMINT index;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    ro_sh = get_elf_section_head_by_name(".text", str_tab, str_size, sh_tab, sh_num);
    if (ro_sh == NULL) {
        lerr = 1; goto bad;
    }
    rw_sh = get_elf_section_head_by_name(".data", str_tab, str_size, sh_tab, sh_num);
    if (rw_sh == NULL) {
        lerr = 2; goto bad;
    }
    
    context->codeBase = context->sysv_node.sysv_base + ro_sh->sh_offset;
    context->codeSize = ro_sh->sh_size;
    context->dataBase = context->sysv_node.sysv_base + rw_sh->sh_offset;
    context->dataSize = context->sysv_node.sysv_length - rw_sh->sh_offset;
    
    {
        VMUINT highest_ro = 0, lowest_rw = 0xFFFFFFFF;
        
        for (index = 0, sh = sh_tab; index < sh_num; index++, sh++) {
            if (!(sh->sh_flags & VM_SHF_ALLOC)) {
                // section will not load into memory
                continue;
            }
            if (sh->sh_flags & VM_SHF_WRITE) {
                lowest_rw = min2(lowest_rw, sh->sh_addr);
            }
            else {
                highest_ro = max2(highest_ro, sh->sh_addr + sh->sh_size);
            }
        }
        if (lowest_rw > highest_ro) {
            MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_RORW_OVERLAPPED, lowest_rw, highest_ro);
        }
        
        context->roSize = lowest_rw - (VMUINT)context->sysv_node.sysv_virt;
        // context->rwSize/ziSize will be set outside
    }
    
    if (context->preload_flags == VM_LOAD_PRELOAD_READ) {
        return 0;
    }
    
    sh = get_elf_section_head_by_name(".dynstr", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 3; goto bad;
        }
        
        context->sysv_node.sysv_dynstr = (char *)context->sysv_node.sysv_base + sh->sh_offset;
        context->sysv_node.sysv_dynstr_size = sh->sh_size;
    }
    
    sh = get_elf_section_head_by_name(".dynsym", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 4; goto bad;
        }
        
        context->sysv_node.sysv_symtab = (vm_elf_symtbl_entry_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_symtab_count = sh->sh_size / sizeof(vm_elf_symtbl_entry_t);
    }
    
    sh = get_elf_section_head_by_name(".init_array", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 5; goto bad;
        }
        
        context->sysv_node.sysv_init_array = context->sysv_node.sysv_base + sh->sh_offset;
        context->sysv_node.sysv_init_count = sh->sh_size / 4;
    }
    
    sh = get_elf_section_head_by_name(".rel.dyn", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 6; goto bad;
        }

        context->sysv_node.sysv_dynrel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_dynrel_count = sh->sh_size/sizeof(vm_elf_rel_t);
        
        prel = context->sysv_node.sysv_dynrel;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        {
            for ( index = 0; index < context->sysv_node.sysv_dynrel_count; index++, prel++ ) {
                ret = vm_parse_sysv_reloc( &context->sysv_node, context->so_list, prel );
                if (ret != 0) {
                    lerr = 8; info = index; goto bad;
                }
            }
        }
    }
    
    sh = get_elf_section_head_by_name(".rel.plt", str_tab, str_size, sh_tab, sh_num);
    if (sh != NULL) {
        if (!(sh->sh_flags & VM_SHF_ALLOC)) {
            lerr = 7; goto bad;
        }
        
        context->sysv_node.sysv_pltrel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);
        context->sysv_node.sysv_pltrel_count = sh->sh_size/sizeof(vm_elf_rel_t);
        
        prel = (vm_elf_rel_t *)(context->sysv_node.sysv_base + sh->sh_offset);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        {
            for ( index = 0; index < context->sysv_node.sysv_pltrel_count; index++, prel++ ) {
                ret = vm_parse_sysv_reloc( &context->sysv_node, context->so_list, prel );
                if (ret != 0) {
                    lerr = 10; info = index; goto bad;
                }
            }
        }
    }
    
    return 0;
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_SYSV_FIX, lerr, info, ret);
    return VM_LOAD_ERR_FORMAT;
}

static VMINT do_rom_sysv_loadfix(vm_load_context_t *context, VMUINT8 *execImage, vm_elf_head_t *elf_head)
{
    vm_elf_section_head_t *sh_tab, *str_sh;
#ifdef __MRE_VM_LOAD_UNALIGNED__
    VMINT sh_tabsize;
    vm_elf_section_head_t *_sh_tab;
#endif
    char *str_tab;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    if ((elf_head->e_shnum == 0) || (elf_head->e_shentsize == 0)) {
        lerr = 1; info = elf_head->e_shnum; ret = elf_head->e_shentsize; goto bad;
    }
    if (elf_head->e_shstrndx == VM_SHN_UNDEF) {
        lerr = 2; goto bad;
    }
    if (elf_head->e_shstrndx >= elf_head->e_shnum) {
        lerr = 3; info = elf_head->e_shstrndx; ret = elf_head->e_shnum; goto bad;
    }
    
    sh_tab = (vm_elf_section_head_t *)(execImage + elf_head->e_shoff);
#ifdef __MRE_VM_LOAD_UNALIGNED__
    sh_tabsize = elf_head->e_shentsize * elf_head->e_shnum;
    _sh_tab = _vm_kernel_malloc(sh_tabsize);
    if (_sh_tab == NULL) {
        lerr = 4; info = sh_tabsize; goto bad;
    }
    vm_memcpy(_sh_tab, sh_tab, sh_tabsize);
    sh_tab = _sh_tab;
#endif
    str_sh = sh_tab + elf_head->e_shstrndx;
    str_tab = (char *)(execImage + str_sh->sh_offset);
    
    ret = do_sysv_loadfix(context, elf_head, str_tab, str_sh->sh_size, sh_tab, elf_head->e_shnum);
#ifdef __MRE_VM_LOAD_UNALIGNED__
    _vm_kernel_free(_sh_tab);
#endif  
    if (ret != 0) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_SYSV_FIX, 5, info, ret);
    }
    return ret;

bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_SYSV_FIX, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM };
        return err_map[lerr];
    }
}

static VMINT do_file_sysv_loadfix(vm_load_context_t *context, vm_elf_handle_t *handle)
{
    vm_elf_section_head_t *sh_tab, *str_sh;
    VMINT sh_tabsize;
    char* str_tab = NULL;
    VMUINT nread;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    if ((handle->elf_head.e_shnum == 0) || (handle->elf_head.e_shentsize == 0)) {
        lerr = 1; info = handle->elf_head.e_shnum; ret = handle->elf_head.e_shentsize; goto bad;
    }
    if (handle->elf_head.e_shstrndx == VM_SHN_UNDEF) {
        lerr = 2; goto bad;
    }
    if (handle->elf_head.e_shstrndx >= handle->elf_head.e_shnum) {
        lerr = 3; info = handle->elf_head.e_shstrndx; ret = handle->elf_head.e_shnum; goto bad;
    }
    
    // read the whole sectin table in once, each entry is 40B, in GCC generated file, near 22 ==> 880B
    sh_tabsize = handle->elf_head.e_shentsize * handle->elf_head.e_shnum;
    sh_tab = _vm_kernel_malloc(sh_tabsize);
    if (sh_tab == NULL) {
        lerr = 4; info = sh_tabsize; goto bad;
    }
    vm_file_seek(handle->file, handle->elf_head.e_shoff, BASE_BEGIN);
    ret = vm_file_read(handle->file, sh_tab, sh_tabsize, &nread);
    if (ret != sh_tabsize) {
        lerr = 5; goto free_shtab;
    }
    
    str_sh = sh_tab + handle->elf_head.e_shstrndx;
    
    str_tab = _vm_kernel_malloc(str_sh->sh_size);
    if (str_tab == NULL) {
        lerr = 6; info = str_sh->sh_size; goto free_shtab;
    }
    ret = read_elf_section(handle, str_sh, str_tab);
    if (ret != 0) {
        lerr = 7; goto free_strtab;
    }
    
    ret = do_sysv_loadfix(context, &handle->elf_head, str_tab, str_sh->sh_size, sh_tab, handle->elf_head.e_shnum);
    _vm_kernel_free(str_tab);
    _vm_kernel_free(sh_tab);
    if (ret != 0) {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_SYSV_FIX, 8, info, ret);
    }
    return ret;
    
free_strtab:
    _vm_kernel_free(str_tab);
free_shtab:
    _vm_kernel_free(sh_tab);
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_SYSV_FIX, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_INVALID, VM_LOAD_ERR_UNKNOWN,  VM_LOAD_ERR_UNKNOWN,
             VM_LOAD_ERR_INVALID, VM_LOAD_ERR_UNKNOWN };
        return err_map[lerr];
    }
}

static VMINT load_rom_zipped_sysv(vm_load_context_t *context)
{
    VMUINT8* execImage;
    vm_elf_head_t *head;
    vm_elf_prog_head_t *ph;
    
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    
    VMINT runtime_in_app_mem = 0;
    VMUINT8 *runtime_base = NULL;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    execImage = vm_get_execrom_ptr((VMWCHAR*)context->fileName);
    if (execImage == NULL) {
        lerr = 1; goto bad_fn;
    }
    
    head = (vm_elf_head_t *)execImage;
    if (strncmp((char *)head->e_ident, "\x7f""ELF", 4) != 0) {
        lerr = 2; info = *(VMINT *)(head->e_ident); goto bad_fn;
    }
    
    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
    for (index = 0; index < head->e_phnum; index++, ph++) {
        if (ph->p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        
        base_offset = min2(base_offset, ph->p_offset);
        base_virt   = min2(base_virt,   ph->p_vaddr);
        max_virt    = max2(max_virt, ph->p_vaddr + ph->p_memsz);
        if (max_virt == (ph->p_vaddr + ph->p_memsz)) {
            ziSize = (ph->p_memsz - ph->p_filesz);
        }
    }
    
    if (load_count == 0) {
        lerr = 3; goto bad_fn;
    }
    if (base_offset != 0) {
        /* SysV ABI specify it will map all table into memory, including ELF header */
        /* otherwise, it can't conform to SysV ABI, so we can't handle it */
        /* lots of code written depends on this, so we will stop loading it */
        lerr = 4; info = base_offset; goto bad_fn;
    }
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        vm_compress_elf_info com_info;
        
        // check the load buffer is large enough
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 5; info = context->load_size; ret = (max_virt - base_virt); goto bad_fn;
        }
        
        vm_get_compress_info_from_rom(execImage - 4, &com_info);
        
        if ((com_info.pt_load_new_offset + com_info.pt_load_old_filesize + VM_UNZIP_MEM_SIZE) <= context->load_size) {
            runtime_in_app_mem = 1;
            runtime_base = context->load_buffer + context->load_size - VM_UNZIP_MEM_SIZE;
        }
        else {
            runtime_in_app_mem = 0;
            runtime_base = load_alloc_working_buffer(VM_UNZIP_MEM_SIZE, context->asm_index);
            if (runtime_base == NULL) {
                lerr = 6; info = VM_UNZIP_MEM_SIZE; goto bad_fn;
            }
        }
        
        g_unzip_adm_id = kal_adm_create(runtime_base, VM_UNZIP_MEM_SIZE, NULL, KAL_TRUE);
        
        /* read the uncompress part in head of file, include ELF header & table */
        memcpy(context->load_buffer, execImage, com_info.pt_load_new_offset);
        /* decompress */
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer + com_info.pt_load_new_offset, com_info.pt_load_old_filesize, 
                        execImage + com_info.pt_load_new_offset, com_info.pt_load_new_filesize);
        if (ret) {
            lerr = 7; goto free_unzip_adm;
        }
        
        /*kal_adm_delete(g_unzip_adm_id);*/ g_unzip_adm_id = NULL;
        if (runtime_in_app_mem == 0) load_free_working_buffer(runtime_base);
        runtime_base = NULL;
        
        ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
        for (index = 0; index < head->e_phnum; index++, ph++) {
            if (ph->p_type != VM_PT_LOAD) {
                continue;
            }
            memset(context->load_buffer + (ph->p_vaddr - base_virt) + ph->p_filesz, 0, ph->p_memsz - ph->p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = do_rom_sysv_loadfix(context, execImage, head);
    if (ret != 0) {
        lerr = 8; goto free_unzip_adm;
    }
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    // both RVCT & GCC can apply this
    context->entry = (void *)(context->sysv_node.sysv_base + head->e_entry - context->sysv_node.sysv_virt);
    return 0;
    
free_unzip_adm:
    if (!runtime_in_app_mem && runtime_base) {
        load_free_working_buffer(runtime_base);
        runtime_base = NULL;
    }
bad_fn:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_Z_SYSV, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM,  VM_LOAD_ERR_UNZIP, 
             VM_LOAD_ERR_UNKNOWN };
        if (lerr == 8) {
            return ret;
        }
        return err_map[lerr];
    }
}

static VMINT load_rom_normal_sysv(vm_load_context_t *context)
{
    VMUINT8* execImage;
    vm_elf_head_t *head;
    vm_elf_prog_head_t *ph;
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    execImage = vm_get_execrom_ptr((VMWCHAR*)context->fileName);
    if (execImage == NULL) {
        lerr = 1; goto bad_fn;
    }
    
    head = (vm_elf_head_t *)execImage;
    if (strncmp((char *)head->e_ident, "\x7f""ELF", 4) != 0) {
        lerr = 2; info = *(VMINT *)(head->e_ident); goto bad_fn;
    }
    
    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
    for (index = 0; index < head->e_phnum; index++, ph++) {
        if (ph->p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        
        base_offset = min2(base_offset, ph->p_offset);
        base_virt   = min2(base_virt,   ph->p_vaddr);
        max_virt    = max2(max_virt, ph->p_vaddr + ph->p_memsz);
        if (max_virt == (ph->p_vaddr + ph->p_memsz)) {
            ziSize = (ph->p_memsz - ph->p_filesz);
        }
    }
    
    if (load_count == 0) {
        lerr = 3; goto bad_fn;
    }
    if (base_offset != 0) {
        /* SysV ABI specify it will map all table into memory, including ELF header */
        /* otherwise, it can't conform to SysV ABI, so we can't handle it */
        /* lots of code written depends on this, so we will stop loading it */
        lerr = 4; info = base_offset; goto bad_fn;
    }
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 5; info = context->load_size; ret = (max_virt - base_virt); goto bad_fn;
        }
        
        ph = (vm_elf_prog_head_t *)(execImage + head->e_phoff);
        for (index = 0; index < head->e_phnum; index++, ph++) {
            if (ph->p_type != VM_PT_LOAD) {
                continue;
            }
            // do the load
            memcpy(context->load_buffer + (ph->p_vaddr - base_virt), execImage + ph->p_offset, ph->p_filesz); // ph->p_offset == 0
            memset(context->load_buffer + (ph->p_vaddr - base_virt) + ph->p_filesz, 0, ph->p_memsz - ph->p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = do_rom_sysv_loadfix(context, execImage, head);
    if (ret != 0) {
        lerr = 6; goto bad_fn;
    }
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    // both RVCT & GCC can apply this
    context->entry = (void *)(context->sysv_node.sysv_base + head->e_entry - context->sysv_node.sysv_virt);
    return 0;
    
bad_fn:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_ROM_N_SYSV, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,  VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_OOM, VM_LOAD_ERR_IO };
        if (lerr == 6) {
            return ret;
        }
        return err_map[lerr];
    }
}

static VMINT load_file_zipped_sysv(vm_load_context_t *context)
{
    vm_elf_handle_t handle;
    vm_elf_prog_head_t ph;
    
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    VMUINT nread;
    
    VMINT runtime_in_app_mem = 0, rbuf_in_app_mem = 0;
    VMUINT8 *runtime_base = NULL;
    VMUINT8 *rbuf = NULL; 
    VMINT rbuf_size;
    VMUINT8 *mem_tail;
    
    FS_FileLocationHint MyHint[2];
	VMINT mtk_file_id = -1;
    VMINT lerr = 0, info = 0, ret = 0;
    
    ret = open_elf(context->fileName, &handle);
    if (ret != 0) {
        lerr = 1; goto open_failed;
    }
    
    
    MyHint[0].Index = handle.elf_head.e_phoff;
    MyHint[1].Index = handle.elf_head.e_shoff;
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle.file, &mtk_file_id) == VM_RES_OK)
	{
		FS_SetSeekHint(mtk_file_id, 2, MyHint);
	}

    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    for (index = 0; index < handle.elf_head.e_phnum; index++) {
        ret = read_elf_prog_head_by_index(&handle, index, &ph);
        if (ret != 0) {
            lerr = 2; info = index; goto read_failed;
        }
        
        if (ph.p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        if (ph.p_vaddr != ph.p_paddr) {
            /* for normal application, this 2 fields must be equal */
            /* if they are different, maybe it's an OS image or some bare image, we can't load */
            lerr = 3; info = ph.p_vaddr; ret = ph.p_paddr; goto read_failed;
        }
        
        base_offset = min2(base_offset, ph.p_offset);
        base_virt   = min2(base_virt,   ph.p_vaddr);
        max_virt    = max2(max_virt, ph.p_vaddr + ph.p_memsz);
        if (max_virt == (ph.p_vaddr + ph.p_memsz)) {
            ziSize = (ph.p_memsz - ph.p_filesz);
        }
    }

    if (load_count == 0) {
        lerr = 4; goto read_failed;
    }
    if (base_offset != 0) {
        /* SysV ABI specify it will map all table into memory, including ELF header */
        /* otherwise, it can't conform to SysV ABI, so we can't handle it */
        /* lots of code written depends on this, so we will stop loading it */
        lerr = 5; info = base_offset; goto read_failed;
    }
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        vm_compress_elf_info com_info;
        vm_get_compress_info_from_file(context->fileName, &com_info);
        rbuf_size = com_info.pt_load_new_filesize;
        
        // check the load buffer is large enough
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 6; info = context->load_size; ret = (max_virt - base_virt); goto read_failed;
        }
        
        if ((com_info.pt_load_new_offset + com_info.pt_load_old_filesize + VM_UNZIP_MEM_SIZE + rbuf_size) <= context->load_size)
        {
            runtime_in_app_mem = 1;
            rbuf_in_app_mem = 1;
        }
        else if((com_info.pt_load_new_offset + com_info.pt_load_old_filesize + max2(VM_UNZIP_MEM_SIZE, rbuf_size)) <= context->load_size)
        {
            if (max2(VM_UNZIP_MEM_SIZE, rbuf_size) == VM_UNZIP_MEM_SIZE) {
                runtime_in_app_mem = 1;
                rbuf_in_app_mem = 0;
            }
            else {
                runtime_in_app_mem = 0;
                rbuf_in_app_mem = 1;
            }
        }
        else if((com_info.pt_load_new_offset + com_info.pt_load_old_filesize + min2(VM_UNZIP_MEM_SIZE, rbuf_size)) <= context->load_size)
        {
            if (min2(VM_UNZIP_MEM_SIZE, rbuf_size) == VM_UNZIP_MEM_SIZE) {
                runtime_in_app_mem = 1;
                rbuf_in_app_mem = 0;
            }
            else {
                runtime_in_app_mem = 0;
                rbuf_in_app_mem = 1;
            }
        }
        else
        {
            /* neither uncompress runtime memory nor read file buffer can be in app memory */
            runtime_in_app_mem = 0;
            rbuf_in_app_mem = 0;
        }
        
        mem_tail = context->load_buffer + context->load_size;
        if (runtime_in_app_mem) {
            runtime_base = mem_tail = mem_tail - VM_UNZIP_MEM_SIZE;
        }
        else {
            runtime_base = load_alloc_working_buffer(VM_UNZIP_MEM_SIZE, context->asm_index);
            if (runtime_base == NULL) {
                lerr = 7; info = VM_UNZIP_MEM_SIZE; goto read_failed;
            }
        }
        
        if (rbuf_in_app_mem) {
            rbuf = mem_tail = mem_tail - rbuf_size;
        }
        else {
            rbuf = load_alloc_working_buffer(rbuf_size, context->asm_index);
            if (rbuf == NULL) {
                lerr = 8; info = rbuf_size; goto free_runtime_base;
            }
        }
        
        g_unzip_adm_id = kal_adm_create(runtime_base, VM_UNZIP_MEM_SIZE, NULL, KAL_TRUE);
        
        /* read the uncompress part in head of file, include ELF header & table */
        vm_file_seek(handle.file, 0, BASE_BEGIN);
        ret = vm_file_read(handle.file, context->load_buffer, com_info.pt_load_new_offset, &nread);
        if (ret < 0) {
            lerr = 9; info = nread; goto free_unzip_adm;
        }
    
        /* read the compressed data */
        vm_file_seek(handle.file, com_info.pt_load_new_offset, BASE_BEGIN);
        ret = vm_file_read(handle.file, rbuf, com_info.pt_load_new_filesize, &nread);
        if (ret < 0) {
            lerr = 10; info = nread; goto free_unzip_adm;
        }
        /* decompress it */
        ret = vm_pmng_unzip(context->rorw_zip, context->load_buffer + com_info.pt_load_new_offset, com_info.pt_load_old_filesize, 
                    rbuf, com_info.pt_load_new_filesize);
        if (ret) {
            lerr = 11; goto free_unzip_adm;
        }
        
        /*kal_adm_delete(g_unzip_adm_id);*/ g_unzip_adm_id = NULL;
        if (runtime_in_app_mem == 0) load_free_working_buffer(runtime_base); 
        runtime_base = NULL;
        if (rbuf_in_app_mem == 0) load_free_working_buffer(rbuf); 
        rbuf = NULL;
        
        for (index = 0; index < handle.elf_head.e_phnum; index++) {
            ret = read_elf_prog_head_by_index(&handle, index, &ph);
            if (ret != 0) {
                lerr = 12; info = index; goto free_unzip_adm;
            }
            
            if (ph.p_type != VM_PT_LOAD) {
                continue;
            }
            
            memset(context->load_buffer + (ph.p_vaddr - base_virt) + ph.p_filesz, 0, ph.p_memsz - ph.p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = do_file_sysv_loadfix(context, &handle);
    if (ret != 0) {
        lerr = 13; goto free_unzip_adm;
    }
    close_elf(&handle);
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    // both RVCT & GCC can apply this
    context->entry = (void *)(context->sysv_node.sysv_base + handle.elf_head.e_entry - context->sysv_node.sysv_virt);
    
    return 0;
    
free_unzip_adm:
    g_unzip_adm_id = NULL;
free_rbuf:
    if (!rbuf_in_app_mem && rbuf) {
        load_free_working_buffer(rbuf); rbuf = NULL;
    }
free_runtime_base:
    if (!runtime_in_app_mem && runtime_base) {
        load_free_working_buffer(runtime_base); runtime_base = NULL;
    }
read_failed:
    close_elf(&handle);
open_failed:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_Z_SYSV, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_IO,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,  VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_OOM, VM_LOAD_ERR_OOM,
             VM_LOAD_ERR_IO,  VM_LOAD_ERR_IO, VM_LOAD_ERR_UNZIP, VM_LOAD_ERR_IO, VM_LOAD_ERR_UNKNOWN };
        if (lerr == 13) {
            return ret;
        }
        return err_map[lerr];
    }
}

static VMINT load_file_normal_sysv(vm_load_context_t *context)
{
    vm_elf_handle_t handle;
    vm_elf_prog_head_t ph;
    VMINT index;
    VMINT load_count;
    VMINT base_offset, base_virt, max_virt;
    VMUINT ziSize = 0;
    VMUINT nread;
    FS_FileLocationHint MyHint[2];
	VMINT mtk_file_id = -1;
    VMINT lerr = 0, info = 0, ret = 0;
    
    ret = open_elf(context->fileName, &handle);
    if (ret != 0) {
        lerr = 1; goto open_failed;
    }
    
    MyHint[0].Index = handle.elf_head.e_phoff;
    MyHint[1].Index = handle.elf_head.e_shoff;
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle.file, &mtk_file_id) == VM_RES_OK)
	{
		FS_SetSeekHint(mtk_file_id, 2, MyHint);
	}

    base_offset = 0xFFFFFFFF;
    base_virt = 0xFFFFFFFF;
    max_virt = 0;
    load_count = 0;
    for (index = 0; index < handle.elf_head.e_phnum; index++) {
        ret = read_elf_prog_head_by_index(&handle, index, &ph);
        if (ret != 0) {
            lerr = 2; info = index; goto read_failed;
        }
        
        if (ph.p_type != VM_PT_LOAD) {
            continue;
        }
        load_count++;
        if (ph.p_vaddr != ph.p_paddr) {
            /* for normal application, this 2 fields must be equal */
            /* if they are different, maybe it's an OS image or some bare image, we can't load */
            lerr = 3; info = ph.p_vaddr; ret = ph.p_paddr; goto read_failed;
        }
        
        base_offset = min2(base_offset, ph.p_offset);
        base_virt   = min2(base_virt,   ph.p_vaddr);
        max_virt    = max2(max_virt, ph.p_vaddr + ph.p_memsz);
        if (max_virt == (ph.p_vaddr + ph.p_memsz)) {
            ziSize = (ph.p_memsz - ph.p_filesz);
        }
    }
    
    if (load_count == 0) {
        lerr = 4; goto read_failed;
    }
    
    if (base_offset != 0) {
        /* SysV ABI specify it will map all table into memory, including ELF header */
        /* otherwise, it can't conform to SysV ABI, so we can't handle it */
        /* lots of code written depends on this, so we will stop loading it */
        lerr = 5; info = base_offset; goto read_failed;
    }
    
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        // check the load buffer is large enough
        if (context->load_size < (max_virt - base_virt)) {
            lerr = 6; info = context->load_size; ret = (max_virt - base_virt); goto read_failed;
        }
        
        for (index = 0; index < handle.elf_head.e_phnum; index++) {
            ret = read_elf_prog_head_by_index(&handle, index, &ph);
            if (ret != 0) {
                lerr = 7; info = index; goto read_failed;
            }
            
            if (ph.p_type != VM_PT_LOAD) {
                continue;
            }
            
            vm_file_seek(handle.file, ph.p_offset, BASE_BEGIN);
            ret = vm_file_read(handle.file, context->load_buffer + (ph.p_vaddr - base_virt), ph.p_filesz, &nread);
            if (ret < 0) {
                lerr = 8; info = index; goto read_failed;
            }
            memset(context->load_buffer + (ph.p_vaddr - base_virt) + ph.p_filesz, 0, ph.p_memsz - ph.p_filesz);
        }
    }
    
    context->sysv_node.sysv_base = context->load_buffer;
    context->sysv_node.sysv_length = max_virt - base_virt;
    context->sysv_node.sysv_virt = (VMUINT8 *)base_virt;
    ret = do_file_sysv_loadfix(context, &handle);
    if (ret != 0) {
        lerr = 9; goto read_failed;
    }
    close_elf(&handle);
    
    context->rwSize = context->sysv_node.sysv_length - context->roSize - ziSize;
    context->ziSize = ziSize;
    // both RVCT & GCC can apply this
    context->entry = (void *)(context->sysv_node.sysv_base + handle.elf_head.e_entry - context->sysv_node.sysv_virt);
    
    return 0;
    
read_failed:
    close_elf(&handle);
open_failed:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_LDR_FILE_N_SYSV, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_IO,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,  VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_IO, VM_LOAD_ERR_IO,
             VM_LOAD_ERR_UNKNOWN };
        if (lerr == 9) {
            return ret;
        }
        return err_map[lerr];
    }
}

#ifdef MRE_ON_MODIS
static VMINT load_file_modis(vm_load_context_t *context)
{
    if (context->preload_flags != VM_LOAD_PRELOAD_READ) {
        context->codeBase = context->dataBase = context->load_buffer;
    }
    context->codeSize = context->dataSize = context->roSize = context->rwSize = context->ziSize = 0;

    return 0;
}
#endif

typedef VMINT (*vm_load_file_t)(vm_load_context_t *context);
static const vm_load_file_t load_file_functions[2][2][2] = 
{
    /* ROM */
    {
        /* zipped */
        { /* ADS */ load_rom_zipped_ads, /* RVCT&GCC */ load_rom_zipped_sysv },
        /* normal */
        { /* ADS */ load_rom_normal_ads, /* RVCT&GCC */ load_rom_normal_sysv }
    },
    /* file */
    {
        /* zipped */
        { /* ADS */ load_file_zipped_ads, /* RVCT&GCC */ load_file_zipped_sysv },
        /* normal */
        { /* ADS */ load_file_normal_ads, /* RVCT&GCC */ load_file_normal_sysv }
    }
};

VMINT vm_load_normal(vm_load_context_t *p_context)
{
    vm_load_file_t load_func;
    VMINT is_ads;
    VMINT ret;
    vm_sysv_node_t *p_sysv_node;
    
    is_ads = is_rorwpi_file(p_context->file_type);
                    
#ifdef MRE_ON_MODIS
    load_func = load_file_modis;
#else
    load_func = load_file_functions[p_context->suffix == VM_EXEC_ROM ? 0 : 1]
                   [p_context->rorw_zip ? 0 : 1]
                   [is_ads ? 0 : 1];
#endif
    /* if (load_func == NULL) ... */
    ret = (*load_func)(p_context);
    
    if (ret == 0 && p_context->preload_flags == 0) {
        vm_flush_icache(p_context->load_buffer, p_context->roSize);
    }
    
    return ret;
}

void  vm_init_preload_app_info(vm_preload_app_info_t *preload_info)
{
    memset(preload_info, 0, sizeof(*preload_info));
    preload_info->fileHandle = -1;
    preload_info->magic = VM_PRELOAD_MAGIC_INIT;
}

void  vm_clean_preload_app_info(vm_preload_app_info_t *preload_info)
{
    if (preload_info->mre_fun_list) {
        _vm_kernel_free(preload_info->mre_fun_list);
        preload_info->mre_fun_list = NULL;
    }
    if (preload_info->fileHandle != -1) {
        vm_file_close(preload_info->fileHandle);
        preload_info->fileHandle = -1;
    }
    if (preload_info->mem)
    {
        preload_info->mem->adm_id = 0;
    }
    vm_init_preload_app_info(preload_info);
}

VMINT vm_read_preload_app_info(vm_preload_app_info_t *preload_info, const VMWSTR fullFileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_exec_format_enum suffix;
    VMINT rorw_zip;
    vm_file_type_enum file_type;
    VMINT is_ads;
    vm_load_context_t *p_context;
    VMUINT memSize;
    VMINT bufSize = 4;
    VMINT lerr = 0, info = 0, ret = 0;
    
    if (!fullFileName || fullFileName[0] == 0)
    {
        lerr = 1; goto bad;
    }
    if (preload_info->magic != VM_PRELOAD_MAGIC_INIT)
    {
        lerr = 1; goto bad;
    }
    
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_MEM_REQ, &memSize, &bufSize) != GET_TAG_TRUE || memSize <= 0) {
        lerr = 2; info = memSize; goto bad;
    }
    memSize = memSize * 1024; // unit: KB -> B

    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_PLAT_REQ, &preload_info->platform_version, &bufSize) != GET_TAG_TRUE) {
        preload_info->platform_version = 0xFFFFFFFF;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_RESOLUTION_REQ, &preload_info->resolution, &bufSize) != GET_TAG_TRUE) {
        preload_info->resolution = 0xFFFFFFFF;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_SUPPORT_VP, &preload_info->is_support_vp, &bufSize) != GET_TAG_TRUE) {
        preload_info->is_support_vp = 0;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_APP_ID, &preload_info->app_id, &bufSize) != GET_TAG_TRUE) {
        preload_info->app_id = 0;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_NO_SCREEN, &preload_info->isNoScreen, &bufSize) != GET_TAG_TRUE) {
        preload_info->isNoScreen = 0;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_CHARSET, &preload_info->version, &bufSize) == GET_TAG_TRUE) {
        preload_info->version = 2000;
    }
    else {
        preload_info->version = 1000;
    }
    
    p_context = &preload_info->saved_context;
    
    vm_wstrncpy(preload_info->fullFileName, fullFileName, MAX_APP_NAME_LEN);
    
    suffix = vm_parse_exec_format(fullFileName);
    /* get RO RW is zipped or not */
    rorw_zip = 0; bufSize = 4;
    if (vm_get_vm_tag(fullFileName, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize) != GET_TAG_TRUE) {
        rorw_zip = 0;
    }
    file_type = vm_get_file_type(fullFileName);
    is_ads = is_rorwpi_file(file_type);

    /* error checking */
    if (suffix != VM_EXEC_VXP && suffix != VM_EXEC_DLL && suffix != VM_EXEC_ROM) {
        lerr = 3; info = suffix; goto bad;
    }
    
    p_context->fileName = preload_info->fullFileName;
    p_context->suffix = suffix;
    p_context->rorw_zip = rorw_zip;
    p_context->file_type = file_type;
    p_context->preload_flags = VM_LOAD_PRELOAD_READ;
    
    ret = vm_load_normal(p_context);
    if (ret != 0) {
        lerr = 4; goto bad;
    }
    
    // copy values in context into info
    preload_info->loadSize = p_context->roSize + p_context->rwSize + p_context->ziSize;
    if (!preload_info->isMREmem)
    {
        preload_info->backupSize = p_context->rwSize;
    }        
#ifndef MRE_ON_MODIS
    if (is_ads) {
        preload_info->loadSize += PARAM_BLOCK_SIZE + p_context->rwSize;
    }
#endif
    preload_info->loadSize += preload_info->backupSize;
    if (preload_info->loadSize > memSize) {
        lerr = 5; goto bad;
    }
    preload_info->heapSize = (memSize - preload_info->loadSize);
    preload_info->resSize  = 0;
    p_context->asm_index = -1;
    
    preload_info->magic    = VM_PRELOAD_MAGIC_INIT;
    
    return 0;
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRELDR_READ, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT };
        if (lerr == 4) {
            return ret;
        }
        return err_map[lerr];
    }
}

static VMINT vm_preload_app_rorw_tag(vm_preload_app_info_t *preload_info)
{
    vm_load_context_t *p_context = &preload_info->saved_context;
    const VMWSTR fullFileName = preload_info->fullFileName;
    //elf_handle_t elf_handle;
    //elf_section_head_t *sh_tab, *str_sh;
    //VMINT sh_tabsize;
    //char* str_tab;
    //VMUINT nread;
    //VMINT is_ads;
    VMUINT8 *backupPtr;
    VMINT bufSize;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    //is_ads = is_rorwpi_file(p_context->file_type);
    if (p_context->asm_index == -1) {
        p_context->asm_index = APPLIB_MEM_AP_ID_MRE_CORE - APPLIB_MEM_AP_ID_MRE_APP0;
    }
    p_context->load_buffer = (VMUINT8 *)preload_info->loadBase + preload_info->backupSize;
    p_context->load_size = preload_info->loadBufSize - preload_info->backupSize;
    p_context->preload_flags = 0;
#if 0
/* under construction !*/
#endif
    
    ret = vm_load_normal(p_context);
    if (ret != 0) {
        lerr = 1; goto bad;
    }

#ifndef MRE_ON_MODIS
    // copy the backup
    if (preload_info->backupSize)
    {
        backupPtr = preload_info->loadBase;
        if ((p_context->load_buffer - backupPtr) < p_context->rwSize) {
            lerr = 2; info = (p_context->load_buffer - backupPtr); ret = p_context->rwSize; goto bad;
        }
        memcpy(backupPtr, p_context->load_buffer + p_context->roSize, p_context->rwSize);
        preload_info->rwBackupBase = backupPtr;
        backupPtr += p_context->rwSize;
    }
#endif

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
    
    vm_ce_merge_permission(fullFileName);
    preload_info->mre_fun_list = _vm_per_get_mre_fun_list();
    _vm_per_clear_mre_fun_list();
    if (preload_info->mre_fun_list == NULL) {
        lerr = 3; goto bad;
    }
    
    return 0;
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRELDR_PRELOAD_RORW, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_INVALID };
        if (lerr == 1) {
            return ret;
        }
        return err_map[lerr];
    } 
}

static VMINT vm_preload_app_res(vm_preload_app_info_t *preload_info)
{
    return -1;
}

VMINT vm_preload_app(vm_preload_app_info_t *preload_info, VMINT flags)
{
    VMINT lerr = 0, info = 0, ret = 0;
    
    if (preload_info->magic != VM_PRELOAD_MAGIC_INIT) {
        lerr = 1; info = preload_info->magic; goto bad;
    }
    
    /* error checking */
    if (preload_info->saved_context.suffix != VM_EXEC_VXP 
        && preload_info->saved_context.suffix != VM_EXEC_DLL  && preload_info->saved_context.suffix != VM_EXEC_ROM) {
        lerr = 2; info = preload_info->saved_context.suffix; goto bad;
    }
        
    if (flags & VM_PRELOAD_RORW) {
        if (preload_info->loadBufSize < preload_info->loadSize) {
            lerr = 3; info = preload_info->loadBufSize; ret = preload_info->loadSize; goto bad;
        }
        
        ret = vm_preload_app_rorw_tag(preload_info);
        if (ret == 0) {
			preload_info->magic = VM_PRELOAD_MAGIC_LOAD;
		}
		else {
            lerr = 4; goto bad;
        }
    }
    
    if (flags & VM_PRELOAD_RES) {
        if (preload_info->resBufSize < preload_info->resSize) {
            lerr = 5; info = preload_info->resBufSize; ret = preload_info->resSize; goto bad;
        }
        
        ret = vm_preload_app_res(preload_info);
        if (ret != 0) {
            lerr = 6; goto bad;
        }
    }
    
    return 0;

bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRELDR_PRELOAD, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_FORMAT, VM_LOAD_ERR_FORMAT,
             VM_LOAD_ERR_INVALID, VM_LOAD_ERR_UNKNOWN,  
             VM_LOAD_ERR_INVALID, VM_LOAD_ERR_UNKNOWN };
        if (lerr == 4 || lerr == 6) {
            return ret;
        }
        return err_map[lerr];
    } 
}

VMINT vm_load_preload_app(struct vm_preload_app_info *preload_info)
{   
    vm_load_context_t *p_context = &preload_info->saved_context;
    VMUINT8 *ptr;
    //elf_rel_t *prel;
    //VMINT index;
    
    VMINT lerr = 0, info = 0, ret = 0;
    
    if (preload_info->magic != VM_PRELOAD_MAGIC_LOAD) {
        lerr = 1; info = preload_info->magic; goto bad;
    }
    
#ifndef MRE_ON_MODIS
    if (preload_info->backupSize)
    {
        // copy backup RW to its place
        ptr = (VMUINT8 *)(preload_info->loadBase) + preload_info->backupSize + p_context->roSize;
        memcpy(ptr, preload_info->rwBackupBase, p_context->rwSize);
    }
    if (!is_rorwpi_file(p_context->file_type)) {
        ptr = (VMUINT8 *)(preload_info->loadBase) + preload_info->backupSize + p_context->roSize 
                    + p_context->rwSize;
        memset(ptr, 0, p_context->ziSize);
    }
    else {
        // nothing to do, since the ZI is executed by c init runtime
    }
           
    vm_flush_icache((VMUINT8 *)preload_info->loadBase + preload_info->backupSize, p_context->roSize);
    
#endif
    
    return 0;
    
bad:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRELDR_LOAD, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_LOAD_ERR_UNKNOWN, VM_LOAD_ERR_UNINIT, VM_LOAD_ERR_RELOC };
        return err_map[lerr];
    }
}

#endif

