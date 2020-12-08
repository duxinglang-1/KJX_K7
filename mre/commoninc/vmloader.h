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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VM_LOADER_H
#define _VM_LOADER_H

#include "vmpromnginner.h"

#ifdef __cplusplus
extern "C" {
#endif

#define __MRE_VM_LOAD_UNALIGNED__
#define __MRE_VM_LOAD_ADS_ROM_INRAM__

/* vmpromnginner.h ==> here  */
#define STACK_SIZE 						(3 * 1024)
#define HEAP_SIZE 						(1024 * 2)
#define PARAM_BLOCK_SIZE 				(128)

/* zlib runtime memory 80 KByte */
#define VM_UNZIP_MEM_SIZE 81920

#define VM_LOAD_ERR_UNKNOWN  (-1)
#define VM_LOAD_ERR_FORMAT   (-2)
#define VM_LOAD_ERR_IO       (-3)
#define VM_LOAD_ERR_OOM      (-4)
#define VM_LOAD_ERR_UNZIP    (-6)
#define VM_LOAD_ERR_RELOC    (-7)
#define VM_LOAD_ERR_UNINIT   (-8)
#define VM_LOAD_ERR_INVALID  (-9)

#define VM_LOAD_PRELOAD      0x1 // deprecated
#define VM_LOAD_PRELOAD_READ 0x2

typedef struct vm_preload_app_info vm_preload_app_info_t;
typedef struct vm_load_context     vm_load_context_t;

struct vm_load_context 
{
    VMWCHAR* fileName;
    vm_exec_format_enum suffix;
    VMINT rorw_zip;
    vm_file_type_enum file_type;
    VMINT asm_index;
    VMUINT8 preload_flags;
    vm_so_node_t *so_list; 
    
    VMUINT8 *load_buffer;
    VMUINT load_size;
    
    // output
    VMUINT8 *codeBase, *dataBase;
    VMUINT   codeSize,  dataSize;
    VMUINT roSize,  rwSize,  ziSize;
    void *entry;
    
    // for sysv abi only
    vm_sysv_node_t sysv_node;
};

// vm_load_normal also serve as a signal of debug enabled version
VMINT vm_load_normal(vm_load_context_t *p_context);
VMINT vm_load_preload_app(vm_preload_app_info_t *preload_info);

#define VM_PRELOAD_MAGIC_INIT 'prld'
#define VM_PRELOAD_MAGIC_LOAD 'PRLD'

struct vm_preload_app_info
{
	VMINT magic;
	// 由vm_read_app_preload_info 从file 中读取
	VMINT loadSize, heapSize, resSize;

	// 由APP 自己申请
	void *loadBase, *heapBase, *resBase;
	VMINT loadBufSize, heapBufSize, resBufSize;
    void  (*preload_callback)(VMINT evt, vm_preload_app_info_t *preload_app);
    
    // cached tags
    VMUINT platform_version;
    VMUINT version;
    VMUINT is_support_vp;
    VMUINT resolution;
    VMUINT app_id;
    VMUINT isNoScreen;
    VMUINT build_id;
    VMINT  *mre_fun_list;
    VMFILE fileHandle;
    
	// 内部使用
	// vm_preload_app 中设置
	vm_load_context_t saved_context;
	VMUINT backupSize;
	VMUINT8 *rwBackupBase;
	void *entry;
	
	VMINT flags;
	VMINT isMREmem;
	vm_app_mem_struct* mem;
	void* user_data;
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
};

#define VM_PRELOAD_EVT_QUIT  0x1

#define VM_PRELOAD_RORW 0x1
#define VM_PRELOAD_RES  0x2
#define VM_PRELOAD_ALL (VM_PRELOAD_RORW | VM_PRELOAD_RES)

void  vm_init_preload_app_info(vm_preload_app_info_t *preload_info);
void  vm_clean_preload_app_info(vm_preload_app_info_t *preload_info);

VMINT vm_read_preload_app_info(vm_preload_app_info_t *preload_info, const VMWSTR fullFileName);
VMINT vm_preload_app(vm_preload_app_info_t *info, VMINT flags);

#ifdef __cplusplus
}
#endif 
#endif
