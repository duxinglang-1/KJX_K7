/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmpromnginner.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
 *
*==============================================================================
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef	_VM_PRO_MNG_INNER
#define _VM_PRO_MNG_INNER

#ifdef __cplusplus
extern "C" {
#endif

#include "vmswitch.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmpromng.h"
#include "elf.h"
#include "vmdl.h"
#include "vm4res.h"

#define MAX_CTX_STACK_NUM				(20)

#define SH_TYPE_R9						(1)
#define SH_TYPE_PROCESS_HANDLE		(2)
#define SH_TYPE_FILENAME				(3)
#define SH_TYPE_PCB						(4)


enum {
SM_FIND_BY_R9 						= SH_TYPE_R9,
SM_FIND_BY_HANDLE 				= SH_TYPE_PROCESS_HANDLE,
SM_FIND_BY_FILENAME 				= SH_TYPE_FILENAME,
SM_FIND_BY_PCB 					= SH_TYPE_PCB,
SM_FIND_BY_HANDLER, 	/* Find SM by smHandler */
SM_FIND_BY_SM_INVOKER,
SM_FIND_BY_PCB_EVENT_FILTER
};

typedef enum {
	SCREEN_EVENT = 0,				/**screen event lead to state switch*/
	MOD_EVENT,						/**MOD event lead to state switch*/
	USER_EVENT						/**user event lead to state switch*/
}_VM_STATUS_TRANSFER_EVENT;

typedef enum {
    DEBUG_UNKNOWN,
    VM_DEBUG_PROCESS,
    DEBUG_SHARED_MODULE,
    DEBUG_SHARED_OBJECT
} vm_debug_header_type;


typedef struct {
	VMUINT code_index;
	VMUINT data_index;
	struct _vm_pcb_t* pcb;
} vm_so_index_t;

typedef struct
{
 	VMINT index;
	VMCHAR *symname;
	VMUINT address;
} vm_sym_node_t;

typedef struct
{
	vm_elf_section_head_t	relsec;
	vm_elf_tring 		relstr;
	VMUINT	 		reloffset;
	VMUINT	 		relsize;
	VMUINT	 		    virtualAddress;
	VMUINT8* 			imageBase;
	VMINT               rorw_zip;
} vm_app_node_t;

typedef struct
{
    VMUINT8 *sysv_base;
    VMUINT   sysv_length;
    VMUINT8 *sysv_virt;
    vm_elf_symtbl_entry_t *sysv_symtab;
    VMUINT   sysv_symtab_count;
    char    *sysv_dynstr;
    VMUINT   sysv_dynstr_size;
    void    *sysv_init_array;
    VMUINT   sysv_init_count;
    vm_elf_rel_t *sysv_dynrel;
    VMUINT   sysv_dynrel_count;
    vm_elf_rel_t *sysv_pltrel;
    VMUINT   sysv_pltrel_count;
} vm_sysv_node_t;

typedef struct vm_res_list
{
    VMUINT32 id;
    VMUINT8 *data;
	VMUINT32 size;
    struct vm_res_list *next;
}VM_RES_LIST;

typedef struct
{
    VMUINT32 cur_language;
    VMUINT32 cur_offset;
    VMUINT8 *str_buf;

    VMUINT32 res_count;
    VM_RES_LIST *header_node;

}vm_resource_contex;

typedef enum
{
    VM_LAUNCH_APP_EVT_SUCCESS = 0,
    VM_LAUNCH_APP_ASM_READY,
    VM_LAUNCH_APP_EVT_INTERNEL_ERROR,
    VM_LAUNCH_APP_EVT_QUIT,
    VM_LAUNCH_APP_EVT_END_OF_ENUM
} vm_launch_app_evt_enum;

// forward declaration
typedef struct _vm_so_node_t vm_so_node_t;
typedef struct vm_preload_app_info vm_preload_app_info_t;

typedef void (*vm_launch_app_cb_t) (VMINT16 *app_path, vm_launch_app_evt_enum evt);


/**
 * size = 300 byte
 */
typedef struct _vm_pcb_t
{
    // common header for debugging tools
    vm_file_type_enum  file_type;
    vm_debug_header_type  dtype;
    VMWSTR base_name;
    VMUINT build_id;
    struct _vm_pcb_t* next_pcb;		/**next pcb of same state	*/		
    VMINT  _debugger[2];
    // extra info for ROPI/RWPI
    VMUINT8* codeBase;				/**base address of RO code segment*/
	VMUINT codeSize;				/**size of RO code segment by byte	*/
	VMUINT8* dataBase;				/**base address of date segment	*/
	VMUINT dataSize;					/**size of data by byte	*/
	VMUINT8* heapBase;				/**base address of heap	*/
	VMUINT heapSize;				/**size of heap by byte*/
	// extra info for SysV SO
	vm_sysv_node_t sysv_node;
	// extra info for so
	vm_so_node_t* soHeader;
    VMINT r9;						/**register R9 value*/
	
	VM_P_HANDLE  pHandle;			/**process handle*/
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
									/**process full path name	*/
	VMINT isReDriver;				/**file exist on memory card or not	*/
	struct _vm_pcb_t* father_pcb;		/**pcb of father process, NULL if father process is engine	*/
	VMINT is_support_bg_run;		/**suport background running or not*/
    VMINT is_venus;
//	_VM_STATUS_TRANSFER_EVENT	event;
									/**event lead to state switch*/
	VMUINT initParams[6];			/**initial parameter of elf loader loading*/
	void (*sysEventHandler)(VMINT message, VMINT param);
									/**system event handler of application registered*/
	vm_key_handler_t keyHandler;		/**key event handler of application registered*/
	vm_pen_handler_t penHander;		/**pen event handler of application register*/
	vm_key_handler_ex_t keyExHandler;		/**key event ex handler of application registered*/
	VMFILE fileHandle;				/** vxp file handle*/
	VMINT *	mre_fun_list;			/** function list of sandbox*/
	VMINT app_id;					/** app ID*/
	VMINT is_support_all_pen_and_key_event;
									/* suport all pen and key event or not*/

	_event_filter_t* event_filter;		/** billing engine filter*/
	VMINT res_offset;	/* resource offset when use simple elf */
	VMINT res_size;	/* resource size when use simple elf */

	VMINT index;
					
	VMINT bg_by_user;	/*times of switch to background running by user*/
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
	VMUINT8 * sm_key;
#endif
	VMUINT32  version;	
	VMINT isInited;
	VMINT flag;
	VMWSTR parent_path;
	VMINT (*sysGetFuncHandler)(VMSTR symbol);
	VMINT isNoScreen;
#ifdef __MRE_CORE_APP_COMMUNICATION__
    VMINT (*message_proc)(VM_P_HANDLE sender, VMUINT msg_id, VMINT wparam, VMINT lparam);
#endif
#ifdef WIN32
    VMINT hDll;
#endif
    VMINT sim_id;
    VMUINT32 accountId;
    
    vm_preload_app_info_t *preload_info;

	vm_resource_contex res_data;
	VMUINT8 *res_buf;
	VMFILE resfileHandle;				/** vxp file handle*/
	VMINT volume_type;
}_vm_pcb_t;

/* SM info SM PCB need to keep */
typedef struct _vm_sm_t {
    // common header for debugging tools
    vm_file_type_enum  file_type;
    vm_debug_header_type  dtype;
    VMWSTR base_name;
    VMUINT build_id;
    struct _vm_sm_t *next_sm;
    VMINT  _debugger[2];
    // extra info for ROPI/RWPI
    VMUINT8* codeBase;
	VMUINT codeSize;
	VMUINT8* dataBase;
	VMUINT dataSize;
	VMUINT8* heapBase;
	VMUINT heapSize;
	// extra info for SM
	VMUINT rwSize;				
	VMUINT ziSize;
	_vm_pcb_t* pcb;	
	VMINT r9;
	VMINT app_id;
	
	VMINT handle;
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
	VMFILE fileHandle;
	VMINT isReDriver;
	VMINT *	mre_fun_list;	
	VMINT (*smHandler)(VMINT message, VMINT param);
	VMINT invoker;
	_event_filter_t* event_filter;	/* for billing engine */
    VMINT (*message_proc)(VM_P_HANDLE sender, VMUINT msg_id, VMINT wparam, VMINT lparam);
	VMUINT8* tagName;
	
	VMINT res_offset;	/* resource offset when use simple elf */
	vm_resource_contex res_data;
	VMUINT8 *res_buf;
	VMFILE resfileHandle;				/** vxp file handle*/
} _vm_sm_t;

typedef struct _vm_so_node_t
{
    // common header for debugging tools
    vm_file_type_enum  file_type;
    vm_debug_header_type  dtype;
    VMWSTR base_name;
    VMUINT build_id;
    struct _vm_so_node_t* next;
    VMINT  _debugger[2];
    // extra info for ROPI/RWPI, for compatibly only
    VMUINT8* codeBase;
	VMUINT codeSize;
	VMUINT8* dataBase;
	VMUINT dataSize;
	VMUINT8* heapBase;
	VMUINT heapSize;
	// extra info for SysV SO
	vm_sysv_node_t sysv_node;
	// extra info for so
	_vm_pcb_t *pcb;
	void *entry;
	
	VMUINT handle;
	VMINT memIndex;
	VMWCHAR soname[MAX_APP_NAME_LEN + 1];
	void (*sysEventHandler)(VMINT message, VMINT param);
	vm_sym_node_t* symbols;
	VMUINT size, count;
}vm_so_node_t;

typedef struct vm_pro_ctx_t 
{
	VMINT restore_r9;
	VMINT app_r9;
} vm_pro_ctx_t;

typedef struct vm_pro_ctx_stack_t
{
	VMUINT num;
	vm_pro_ctx_t ctxs[MAX_CTX_STACK_NUM];
} vm_pro_ctx_stack_t;

_vm_pcb_t* _vm_get_pcb_by_phandle(VM_P_HANDLE phandle);

/* MRE billing */
VMINT vm_pmng_set_event_filter(_event_filter_t* be_filter);
VMINT vm_pmng_restore_default_event_filter(void);
VMINT vm_pmng_send_app_sys_event(VM_PROCESS_STATUS pmng_status);

VMINT vm_pmng_current_app_id(void);
void vm_pmng_set_venus_flag(void);

VMUINT vm_get_pool_size_from_ptr(void *_ptr);

/**
 * free application memory
 *
 * pHandle : [IN] handle of application process
 */
void vm_free_mre_app_mem(_vm_pcb_t* tmp);
VMINT vm_pmng_exec_msg_proc(VM_P_HANDLE sender, VM_P_HANDLE receiver, VMUINT msg_id, VMINT wparam, VMINT lparam);
VMINT vm_pmng_exec_sysevent_handler(VMINT phandle, VMUINT msg_id, VMINT param);

#if 0
/* under construction !*/
#endif
/* optimize for SysV */
VMINT vm_parse_sysv_ro_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel, VMUINT roSize );
VMINT vm_parse_sysv_rw_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel, VMUINT roSize );
VMINT vm_parse_sysv_reloc( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, const vm_elf_rel_t* rel );
VMINT vm_resolve_symbol_in_sysv_scope( const vm_sysv_node_t *exe_node, const vm_so_node_t *so_list, VMUINT symbol, VMUINT *abs_value);

#define VM_LOAD_HIDE_IN_OOM 0x1
/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library_ex
 * DESCRIPTION
 *  This function is used to load a vxp file into memory
 * PARAMETERS
 *  name : [IN]        full path of the vxp file
 *  flags: [IN]        see VM_LOAD_*
 * RETURNS
 *  0 is error
 *  other is the handle
 *****************************************************************************/
VMINT vm_native_load_library_ex(VMWSTR name, VMUINT flags);

/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library
 * DESCRIPTION
 *   This function is used to load a vxp file into memory
 * PARAMETERS
 *  name : [IN]        full path of the vxp file
 * RETURNS
 *  0 is error
 *  other is the handle
 *****************************************************************************/
VMINT vm_native_load_library(VMWSTR name);

/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library_with_callback
 * DESCRIPTION
 *  This function is used to load a vxp file into memory
 * PARAMETERS
 *  name : [IN]        full path of the vxp file
 *  flags: [IN]        see VM_LOAD_*
 * RETURNS
 *  0 is error
 *  other is the handle
 *****************************************************************************/
VMINT vm_native_load_library_with_callback(VMWSTR name, VMUINT flags, vm_launch_app_cb_t app_cb);


VMINT vm_native_preload_library(
    vm_preload_app_info_t *preload_info);


/*****************************************************************************
 * FUNCTION
 *  vm_native_get_symbol
 * DESCRIPTION
 *  get the symbol from libary
 * PARAMETERS
 *  handle : [IN]        the handle get from vm_native_load_library
 *  name : [IN]         function name
 * RETURNS
 *  0 is error
 *  address of the function
 *****************************************************************************/
VMINT vm_native_get_symbol(VMINT handle, VMSTR name);

/*****************************************************************************
 * FUNCTION
 *  vm_native_free_library
 * DESCRIPTION
 *  unload the library
 * PARAMETERS
 *  handle : [IN]        the handle get from vm_native_load_library
 * RETURNS
 *  0 is right, other is error
 *****************************************************************************/
VMINT vm_native_free_library(VMINT handle);

VMINT vm_get_base_sym(VMCHAR* func_name);
VMINT vm_get_bt_sym(VMCHAR* func_name);
VMINT vm_get_network_sym(VMCHAR* func_name);
VMINT vm_get_sim_sym(VMCHAR* func_name);
VMINT vm_get_sys_sym(VMCHAR* func_name);
VMINT vm_get_graph_sym(VMCHAR* func_name);
VMINT vm_get_input_sym(VMCHAR* func_name);
VMINT vm_get_camera_sym(VMCHAR* func_name);
VMINT vm_get_che_sym(VMCHAR* func_name);
VMINT vm_get_mm_sym(VMCHAR* func_name);
VMINT vm_get_bitstream_sym(VMCHAR* func_name);

#ifdef __cplusplus
}
#endif 
#endif
