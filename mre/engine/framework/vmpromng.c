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
 * vmpromng.c
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
#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__
#include <stdlib.h>

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
#include "vmloader.h"

#include "vmcermng.h"
#include "vmpromng.h"
#include "vmpromnginner.h"
#include "vmresmng.h"
#include "vmpermng.h"
#include "vmcerter.h"
#include "vmsm.h"
#include "vmappcomm.h"
#include "MMI_trc.h"
#include "MMI_mre_trc.h"
#include "devconfigdef.h"
#include "DevConfigGprot.h"
#include "app_mem.h"
#include "med_api.h"
#include "med_main.h"
#include "gdi_include.h"
#include "kal_release.h"
#include "vmfrm.h"
#ifdef __J2ME__
#include "j2me_custom_option.h"
#include "jam_mvm_manager.h"
#endif
#include "ScreenRotationGprot.h"
#include "mmi_frm_input_gprot.h"
#include "fs_type.h"
#include "fs_func.h"

#include "vmenv.h"
#include "med_smalloc.h"
#include "vmbitstream.h"
#include "vmbtcm.h"
#include "vmbtspp.h"
#include "vmgraph.h"
#include "vmmms.h"
#include "vmsms.h"
#include "vmsim.h"
#include "vmsock.h"
#include "MRESrvGProt.h"
#include "vmjava.h"
#include "vmchset.h" 
#include "vmres.h" 
#include "vmstatusbar.h"
#include "vmeditor.h"
#include "vmmm.h"
#include "vm4res.h"

#include "vmsettings.h"
#include "vmalarm.h"
#include "wgui_include.h"
#include "vmsalui.h"
#include "vmcamera.h"
#include "vmuart.h"

//#define __MMI_MRE_SWLA_DEBUG__

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


/**
 * 模块设置进程context的Stack结构。
 */
static vm_pro_ctx_stack_t stack = 
{
    0,
    {0, 0, 0, 0, 0, 0}
};

static vm_pro_ctx_stack_t stack_vrt = 
{
    0,
    {0, 0, 0, 0, 0, 0}
};

/**
 * 所有状态进程表。
 */
_vm_pcb_t* pcb_table[VM_PMNG_MAX_NUM];

/* The current pcb handle pointer */
_vm_pcb_t *g_cur_pcb;

/**
 * 在还没有加载应用的系统R9 值。
 */
VMINT kernel_r9 = 0;

extern mmi_devconfig_system_config_struct sysconf;
extern VMINT mre_running;
extern VMINT is_gobackhistory;
extern vm_app_mem_struct g_app_mem_info[];
//extern kal_mutexid mre_mutex_id;
extern VMINT g_start_app_flag ;
extern VMWSTR g_parent_path;

extern void vm_mutex_init(vm_mutex_struct *pMutex);

extern void vm_jump_vreapp(unsigned int init_param_addr);
extern VMINT vm_get_running_app_sb(void);
extern void vm_reg_key_handler(void);
extern void vm_reg_pen_handler(void);
extern void vm_stop_mre_envirment(void);
extern VMINT vm_vam_is_in_use(void);
extern VMINT * _vm_per_get_mre_fun_list(void);
extern void _vm_per_free_mre_fun_list(VMINT * mrefun_list);
extern void _vm_per_clear_mre_fun_list(void);
extern VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode );
extern void vm_start_app_success_cb(void);

_vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern int vm_get_sb(void);
extern VMINT vm_per_get_fun_prt(VMINT* fun_list,  VMCHAR* func_name );
extern VMINT _vm_sb_stack_push(VMINT r9);
extern VMINT _vm_sb_stack_pop(void);
extern VMINT vm_ce_merge_permission(VMWSTR filename);
extern VMINT vm_pmng_set_bg_int(_vm_pcb_t* pcb, VM_PROCESS_STATUS status);
extern VMINT vm_get_and_reset_parent_app(void);
extern void vm_res_free_res(_vm_pcb_t* pcb);
extern void vm_get_tag_deinit(VMINT handle);

#ifdef __MRE_CORE_SM__
extern _vm_sm_t * _vm_sm_list_find(VMINT type, VMINT value);
extern VMINT vm_sm_set_sb_by_handle(VMINT sm_hdl);
extern _vm_sm_unload_by_pcb(_vm_pcb_t * pcb);
#endif

static VMINT vm_pmng_delete_process_int(_vm_pcb_t* pcb, VM_PROCESS_STATUS status, VMINT param);
static VMUINT init_address = 0;
static VMUINT init_count = 0;

void vm_reg_func_callback(VMINT (*f)(VMSTR symbol))
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
        vm_log_debug("PCB[%d] register system event handler.", pcb->pHandle);
        pcb->sysGetFuncHandler = f;
    }
    else
    {
        vm_log_error("Dismatch pcb by r9 value=%d.", currAppR9);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_sym_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  symbol      [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_sym_entry(char* symbol) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT returnvalue = -1;
    VMINT currAppR9 = vm_get_running_app_sb();

    _vm_pcb_t* pcb = NULL;
    VMINT *	fun_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(symbol == NULL)
		return 0;
	if(strcmp(symbol,"mre") == 0)
		return 0;

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) == NULL)
    {
#ifdef __MRE_CORE_SM__
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			fun_list = sm_ptr->mre_fun_list;
		}
		else
#endif
        {
            vm_log_warn("vm_get_sym_entry(%s) : get pcb error. R9[%d]", symbol, currAppR9);
            return 0;
        }
    }

	returnvalue = vm_per_get_fun_prt(pcb?pcb->mre_fun_list:fun_list, symbol);
	MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G8_PRO,"[MRE][PRO][PID%d]vm_get_sym_entry : got symbol=%s, returnval=%d", vm_pmng_get_current_handle(),symbol, returnvalue);
	if( returnvalue )
	{
		return returnvalue;
	}

#ifdef __MRE_LIB_C__
	returnvalue = vm_get_base_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_BTCM__
	returnvalue = vm_get_bt_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_SOCKET__
	returnvalue = vm_get_network_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_SIM__
	returnvalue = vm_get_sim_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

	returnvalue = vm_get_sys_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}

#ifdef __MRE_LIB_GRAPIC_IMAGE__
	returnvalue = vm_get_graph_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_LIB_IME__
	returnvalue = vm_get_input_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_CAMERA__
	returnvalue = vm_get_camera_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_CHE__
	returnvalue = vm_get_che_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_AUDIO__
	returnvalue = vm_get_mm_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

#ifdef __MRE_SAL_BITSTREAM__
	returnvalue = vm_get_bitstream_sym(symbol);
	if( returnvalue )
	{
		return returnvalue;
	}
#endif

 	vm_log_fatal("%s is not authorized!, return value is %x", symbol, NULL);
	return 0;			
}



_vm_pcb_t* vm_alloc_pcb(VMWSTR filename, _vm_pcb_t* father, VMINT isRemoveDriver);

void vm_free_pcb(_vm_pcb_t* pcb);

static void vm_close_kernel_exec_file(_vm_pcb_t* pcb);


_vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);

void vm_cleanup_unload_status_pcb(void);

VMINT vm_push_pcb_into_status_union(VM_PROCESS_STATUS status, _vm_pcb_t* pcb);

_vm_pcb_t* vm_pop_pcb_up_status_union(VM_PROCESS_STATUS status, VM_P_HANDLE pHandle);

static VMINT vm_exec_process(_vm_pcb_t* pcb);

//static VMINT vm_load_image_from_mem(VMUINT8* imagePtr, VMUINT8* imageMem, VMINT imageMemSize, _vm_pcb_t* pcb);

//static VMINT vm_load_image_from_file(VMWSTR filename, VMUINT8* imageMem, VMINT imageMemSize, _vm_pcb_t* pcb);

static VMINT  vm_get_parent_process(_vm_pcb_t** pcb);

static void vm_pmng_notify_res_data(_vm_pcb_t* pcb, VMINT process_state);

/**
 *billing event
*/
static VMINT vm_sys_event_be_default_filter(VMINT message, VMINT param){return TRUE;}
static VMINT vm_pen_event_be_default_filter(VMINT pen_event, VMINT x, VMINT y){return TRUE;}
static VMINT vm_key_event_be_default_filter(VMINT key_event, VMINT key_code){return TRUE;}

static _event_filter_t vm_default_filter = {vm_sys_event_be_default_filter, vm_pen_event_be_default_filter, vm_key_event_be_default_filter};

/*****************************************************************************
 * FUNCTION
 *  vm_close_kernel_exec_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_close_kernel_exec_file(_vm_pcb_t* pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcb && pcb->fileHandle >= 0)
    {	
		_vm_sb_stack_push(kernel_r9);
		FS_Close((VMINT)pcb->fileHandle);
		pcb->fileHandle = -1;
		_vm_sb_stack_pop();
    }
#ifdef WIN32
    vm_release_app(pcb);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vm_alloc_pcb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  father          [?]         
 *  isFromCard      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
_vm_pcb_t* vm_alloc_pcb(VMWSTR filename, _vm_pcb_t* father, VMINT isFromCard)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcbPtr = NULL;
    VMINT buffSize = sizeof(VMINT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcbPtr = _vm_kernel_calloc(sizeof(_vm_pcb_t))) == NULL)
        return NULL;
    
    pcbPtr->pHandle = ((VMINT)pcbPtr > 0) ? (VMINT)pcbPtr : ((VMINT)pcbPtr  * (-1));
    pcbPtr->father_pcb = father;
    pcbPtr->isReDriver = isFromCard;
    pcbPtr->event_filter = &vm_default_filter;
	pcbPtr->soHeader = NULL;
	pcbPtr->resfileHandle = -1;

    pcbPtr->is_support_all_pen_and_key_event  = TRUE;
    if (vm_get_vm_tag(filename, VM_CE_INFO_SUPPORT_BG_RUN, 
        (void*)&(pcbPtr->is_support_bg_run), &buffSize) != GET_TAG_TRUE)
    {
        /* 
         * the application without BG tag will be treated as not support all key and pen event, only suport system event
         */
        pcbPtr->is_support_bg_run = FALSE;
        pcbPtr->is_support_all_pen_and_key_event =  FALSE;
    }
    
    vm_wstrncpy(pcbPtr->fullFileName, filename, MAX_APP_NAME_LEN);

	MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_ALLOC_PCB, 
            pcbPtr->pHandle, pcbPtr->isReDriver, pcbPtr->is_support_bg_run);
    
    return pcbPtr;
}


/*****************************************************************************
 * FUNCTION
 *  vm_free_pcb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_free_pcb(_vm_pcb_t* pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcb)
    {
        vm_log_debug("Free PCB[%d]", pcb->pHandle);
        if (pcb != NULL)
        {
			if (pcb->preload_info)
			{
				// don't free preload app's func list
				pcb->mre_fun_list = NULL;
			}
            if (pcb->mre_fun_list != NULL)
            {
                _vm_per_free_mre_fun_list(pcb->mre_fun_list);
                pcb->mre_fun_list = NULL;
            }
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
            if (pcb->sm_key)
            {
            	_vm_kernel_free(pcb->sm_key);
				pcb->sm_key = NULL;
            }
#endif			
			vm_res_free_res(pcb);
        }
        _vm_kernel_free(pcb);
    }
    pcb = NULL;
}


/**
 * 在所有状态表里找指定查找条件的PCB。
 */


/*****************************************************************************
 * FUNCTION
 *  vm_sh_pcb_in_pt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  search_type     [IN]        
 *  value           [IN]        
 *  status          [?]         
 * RETURNS
 *  
 *****************************************************************************/
_vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i = 0;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (search_type != SH_TYPE_R9 && search_type != SH_TYPE_PROCESS_HANDLE
        && search_type != SH_TYPE_FILENAME && search_type != SH_TYPE_PCB)
    {
        return NULL;
    }


    for (i = 0; i < VM_PMNG_MAX_NUM; i++)
    {
        pcb = pcb_table[i];
        
        while (pcb != NULL)
        {
            if (search_type == SH_TYPE_R9)
            {
                if (pcb->r9 == value)
                {
                    if (status)
                    {
                        *status = (VM_PROCESS_STATUS)i;
                    }
                    return pcb;
                }
            }
            else if (search_type == SH_TYPE_PROCESS_HANDLE)
            {
                if (pcb->pHandle == value)
                {
                    if (status)
                    {
                        *status = (VM_PROCESS_STATUS)i;
                    }
                    return pcb;
                }
            }
            else if (search_type == SH_TYPE_PCB)
            {
                if (pcb == (_vm_pcb_t*)value)
                {
                    if (status)
                    {
                        *status = (VM_PROCESS_STATUS)i;
                    }
                    return pcb;
                }
            }
            else
            {
                if (vm_wstrcmp_ignore_case(pcb->fullFileName, (VMWSTR)value) == 0)
                {
                    if (status)
                    {
                        *status = (VM_PROCESS_STATUS)i;
                    }
                    return pcb;
                }
            }

            pcb = pcb->next_pcb;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_push_pcb_into_status_union
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  pcb         [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_push_pcb_into_status_union(VM_PROCESS_STATUS status, _vm_pcb_t *pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* tmp_2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcb == NULL)
        return 0;

	if(pcb->isNoScreen && status == VM_PMNG_FOREGROUND)
	{
		for (tmp_2 = pcb_table[VM_PMNG_BACKGROUND]; tmp_2 != NULL; tmp_2 = tmp_2->next_pcb)
		{
			if (tmp_2 == pcb)
				return 0;
		}
		pcb->next_pcb = pcb_table[VM_PMNG_BACKGROUND];
		pcb_table[VM_PMNG_BACKGROUND] = pcb;
		return 0;
	}
	
    for (tmp_2 = pcb_table[status]; tmp_2 != NULL; tmp_2 = tmp_2->next_pcb)
    {
        if (tmp_2 == pcb)
            return 0;

    }

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
#endif
    pcb->next_pcb = pcb_table[status];
    pcb_table[status] = pcb;

    return 0;
    
}


/*****************************************************************************
 * FUNCTION
 *  vm_pop_pcb_up_status_union
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status      [IN]        
 *  pHandle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
_vm_pcb_t *vm_pop_pcb_up_status_union(VM_PROCESS_STATUS status, VM_P_HANDLE pHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* tmp_1 = NULL, *tmp_2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (tmp_2 = pcb_table[status]; tmp_2 != NULL; tmp_2 = tmp_2->next_pcb)
    {
        if (tmp_2->pHandle == pHandle)
        {
            break;
        }

        tmp_1 = tmp_2;
    }

    if (tmp_2)
    {
        if (!tmp_1)
        {
            pcb_table[status] = tmp_2->next_pcb;
            tmp_2->next_pcb = NULL;
            return tmp_2;
        }
        else
        {
            tmp_1->next_pcb = tmp_2->next_pcb;
            tmp_2->next_pcb = NULL;
            return tmp_2;
        }
    }

    return NULL;
    
}


/*****************************************************************************
 * FUNCTION
 *  _vm_pmng_send_sysevt_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb         [?]         
 *  msg         [IN]        
 *  param       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void _vm_pmng_send_sysevt_msg(_vm_pcb_t * pcb, VMINT msg, VMINT param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT resend = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M05");
	MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_SEND_MSG,pcb->pHandle,msg);
            
    if (msg == VM_MSG_HIDE && param == 0)
    {
        vm_log_debug("pcb->bg_by_user:%d", pcb->bg_by_user);
        pcb->bg_by_user ++;
    }
    
    if (pcb->sysEventHandler)
    {
        vm_log_debug("[SM] _vm_pmng_send_sysevt_msg(%p, %d, %d) - 1", pcb, msg, param);
        
		_vm_sb_stack_push(pcb->r9);

        if (!(pcb->event_filter) || !(pcb->event_filter->sys_event_filter) 
            || pcb->event_filter->sys_event_filter(msg, param))
        {
#ifdef __MRE_CORE_SM__
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_PCB_EVENT_FILTER, (VMINT)pcb);

            vm_log_debug("[SM] _vm_pmng_send_sysevt_msg(%p, %d, %d) - 2, sm_ptr:%p", pcb, msg, param, sm_ptr);
                
            
            if (sm_ptr && sm_ptr->event_filter->sys_event_filter)
            {
                _vm_sb_stack_push(sm_ptr->r9);
                resend = sm_ptr->event_filter->sys_event_filter(msg, param);
                _vm_sb_stack_pop();
                vm_log_debug("[SM] SYS event[%d] filtered by SM[%d]", msg, sm_ptr->handle);
            }
#endif
			if(resend)
            {
                pcb->sysEventHandler(msg, param);
                vm_log_debug("[SM] _vm_pmng_send_sysevt_msg(%p, %d, %d) - 3, sm_ptr:%p", pcb, msg, param, sm_ptr);
            }
		}
		
		_vm_sb_stack_pop();

	}
	MRE_SWLA_STOP("M05");
}

static VMINT g_pmng_create_app_param = 0;
void vm_pmng_set_create_app_param(VMINT param)
{
    g_pmng_create_app_param = param;    
}

VMINT vm_pmng_get_create_app_param(void)
{
    VMINT param = g_pmng_create_app_param;
    g_pmng_create_app_param = 0;
    return param;
}

static VMINT g_pmng_push_app_flag = 0;
static VMUINT g_pmng_push_app_index = 0;

void vm_pmng_set_push_app_flag(U32 index)
{
    g_pmng_push_app_flag = 1;   
    g_pmng_push_app_index = index;
}

VMINT vm_pmng_get_push_app_flag(void)
{
    VMINT flag = g_pmng_push_app_flag;
    g_pmng_push_app_flag = 0;
    return flag;
}


VMINT vm_pmng_get_push_app_index(void)
{
    return g_pmng_push_app_index;
}


/*****************************************************************************
 * FUNCTION
 *  vm_exec_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_exec_process(_vm_pcb_t* pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    _vm_pcb_t* tmpPcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    typedef VMINT (*vm_vxp_entry_fp)(VMUINT symtab);
	typedef VMINT (*vm_vxp_elf_entry_fp)(VMUINT symtab,VMUINT init_address,VMUINT init_count);
    //vm_file_type_enum file_type;
	
    MRE_SWLA_START("M04");
    
    if (pcb)
	{		
        VM_PROCESS_STATUS status;
        
        //file_type = vm_get_file_type(pcb->fullFileName);
        

        vm_push_pcb_into_status_union(VM_PMNG_STARTING, pcb);
		vm_pmng_notify_res_data(pcb,VM_PMNG_STARTING);

        if (pcb->is_support_bg_run)
        {
            /* application support background enter BG first*/
			vm_push_pcb_into_status_union(VM_PMNG_BACKGROUND, 
				vm_pop_pcb_up_status_union(VM_PMNG_STARTING, pcb->pHandle));
            vm_frm_entry_app_screen(pcb->pHandle);    				
		}
		else
		{
		    vm_push_pcb_into_status_union(VM_PMNG_FOREGROUND, 
			    vm_pop_pcb_up_status_union(VM_PMNG_STARTING, pcb->pHandle));
            vm_frm_entry_app_screen(pcb->pHandle);				    
            vm_pmng_notify_res_data(pcb,VM_PMNG_FOREGROUND);				    
	    }            
#ifndef MRE_ON_MODIS
            _vm_sb_stack_push(pcb->r9);
			if((pcb->file_type > VM_VSM_ADS) && (pcb->file_type <= VM_VSO_RVCT))
			{
				vm_vxp_entry_fp vm_vxp_entry_f;
				vm_vxp_entry_f = (vm_vxp_entry_fp)(pcb->initParams[5]);
                MRE_SWLA_START("M08");
				vm_vxp_entry_f((VMUINT)vm_get_sym_entry);
                MRE_SWLA_STOP("M08");
			}
			else if((pcb->file_type <= VM_VSM_ADS) || (pcb->file_type == VM_SIMPLE_VXP_ADS))
			{
                MRE_SWLA_START("M08");
				vm_jump_vreapp((VMUINT)pcb->initParams);
                MRE_SWLA_STOP("M08");
			}
			else if((pcb->file_type == VM_VXP_GCC) || (pcb->file_type == VM_VSO_GCC))
			{
				vm_vxp_elf_entry_fp vm_vxp_entry_f;
				vm_vxp_entry_f = (vm_vxp_elf_entry_fp)(pcb->initParams[5]);
                MRE_SWLA_START("M08");
				vm_vxp_entry_f((VMUINT)vm_get_sym_entry, init_address, init_count);
                MRE_SWLA_STOP("M08");
			}
			else
			{
				vm_log_warn("Not support file type, type = %d", pcb->file_type);
			}
#else
			_vm_sb_stack_push(pcb->r9);
            vm_jump_vreapp((VMUINT)pcb);
            pcb->r9 = (unsigned int)pcb->hDll;                       
#endif

			_vm_sb_stack_pop();

			if ((tmpPcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
				pcb->pHandle, &status)) != NULL && status != VM_PMNG_UNLOAD)
			{
                MRE_SWLA_START("M06");
				_vm_pmng_send_sysevt_msg(pcb, VM_MSG_CREATE, vm_pmng_get_create_app_param());
                MRE_SWLA_STOP("M06");
				vm_post_msg(0, VM_MSG_CREATE, (VMINT)pcb->fullFileName, 0);
			}
			else
			{
			    vm_close_kernel_exec_file(pcb);
			    vm_free_mre_app_mem(pcb);
			    vm_frm_exit_app_screen(pcb->pHandle);

				vm_pop_pcb_up_status_union(VM_PMNG_UNLOAD, pcb->pHandle);
								
				vm_log_warn("Executing PID[%d] exit in loading[UL].", pcb->pHandle);
                
                MRE_SWLA_STOP("M04");
				return -1;
			}

			/* send PAINT message to application */
			if ((tmpPcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
				pcb->pHandle, &status)) != NULL && status != VM_PMNG_UNLOAD)
			{
            if (pcb->is_support_bg_run)
            {
				vm_push_pcb_into_status_union(VM_PMNG_FOREGROUND, 
					vm_pop_pcb_up_status_union(VM_PMNG_BACKGROUND, pcb->pHandle));
				
				vm_pmng_notify_res_data(pcb,VM_PMNG_FOREGROUND);
			}
				if (vm_pmng_get_push_app_flag())
				{
					_vm_pmng_send_sysevt_msg(pcb,VM_MSG_PUSH,vm_pmng_get_push_app_index());
				}
                MRE_SWLA_START("M06");
				_vm_pmng_send_sysevt_msg(pcb, VM_MSG_PAINT, 0);
                MRE_SWLA_STOP("M06");
            }
            else
            {
                vm_close_kernel_exec_file(pcb);
                vm_free_mre_app_mem(pcb);
			    vm_frm_exit_app_screen(pcb->pHandle);

				vm_pop_pcb_up_status_union(VM_PMNG_UNLOAD, pcb->pHandle);

                vm_log_warn("Executing PID[%d] exit in loading[BG].", pcb->pHandle);
                
                MRE_SWLA_STOP("M04");
                return -1;
            }

            /* check application exit or not */
            if ((tmpPcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
                pcb->pHandle, &status)) != NULL && status == VM_PMNG_UNLOAD)
            {
                vm_close_kernel_exec_file(pcb);
                vm_free_mre_app_mem(pcb);
			    vm_frm_exit_app_screen(pcb->pHandle);

				vm_pop_pcb_up_status_union(VM_PMNG_UNLOAD, pcb->pHandle);
				
                vm_log_warn("Executing PID[%d] exit in loading[FG].", pcb->pHandle);

                MRE_SWLA_STOP("M04");
                return -1;
        }      
		StartTimer(0xdefc,0,vm_start_app_success_cb);
        MRE_SWLA_STOP("M04");
        return 0;
    }	

    MRE_SWLA_STOP("M04");
    return -2;
}

/*****************************************************************************
 * FUNCTION
 *  vm_cleanup_unload_status_pcb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_cleanup_unload_status_pcb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* tmp;
	_vm_pcb_t* tmp_next = NULL;
    vm_preload_app_info_t *preload_info;
    
    while ((tmp = pcb_table[VM_PMNG_UNLOAD]) != NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_CLEAN_UNLOAD,tmp->pHandle);
        
        preload_info = tmp->preload_info;
        if (preload_info && preload_info->isMREmem)
        {            
            vm_clean_preload_app_info(preload_info);
            preload_info = NULL;
        }
#ifdef __MRE_CORE_SM__
		_vm_sm_unload_by_pcb(tmp);
#endif        
		vm_close_kernel_exec_file(tmp);
		vm_free_mre_app_mem(tmp);
		vm_frm_exit_app_screen(tmp->pHandle);
		tmp_next = tmp->next_pcb;
		vm_free_pcb(tmp);

		if (pcb_table[VM_PMNG_UNLOAD] == NULL)	 // if tmp is still not free
		{
			break;
		}
		pcb_table[VM_PMNG_UNLOAD] = tmp_next;
		if (preload_info && preload_info->preload_callback) 
		{
			(preload_info->preload_callback)(VM_PRELOAD_EVT_QUIT, preload_info);
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_parent_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pcb     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT  vm_get_parent_process(_vm_pcb_t** pcb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VM_PROCESS_STATUS status =VM_PMNG_UNLOAD;
    VMINT parent_handle = vm_get_and_reset_parent_app();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_handle != 0)
    {
        /* This is APP call vm_app_start case */
       
*pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, parent_handle, &status);
    }
    else
    {
        *pcb = 0;
    }
	return 1;
}

static void vm_set_pcb_flag(_vm_pcb_t* pcb)
{
    pcb->flag = g_start_app_flag;
    g_start_app_flag = 0;
    if (VM_START_APP_RESTART_PARENT & pcb->flag)
    {
        if (g_parent_path)
        {
            pcb->parent_path = g_parent_path;
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  vm_pmng_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pcb_table, 0x00, sizeof(_vm_pcb_t*) * VM_PMNG_MAX_NUM);
    kernel_r9 = vm_get_sb();

    stack.num = 0;
    vm_log_debug("current r9 = %d", kernel_r9);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_finialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_pmng_finialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_pmng_finialize_ex(0);    
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_finialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_pmng_finialize_ex(VMINT param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS i = VM_PMNG_FOREGROUND;
    _vm_pcb_t* pcb = NULL, *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = VM_PMNG_FOREGROUND; i < VM_PMNG_MAX_NUM; i++)
    {
        while ((pcb = pcb_table[i]) != NULL)
        {
            tmp = pcb->next_pcb;
            vm_push_pcb_into_status_union(VM_PMNG_CLOSING, 
                vm_pop_pcb_up_status_union(i, pcb->pHandle));
                
            vm_pmng_notify_res_data(pcb,VM_PMNG_CLOSING);	    
                
            pcb_table[i] = tmp;

            _vm_pmng_send_sysevt_msg(pcb, VM_MSG_QUIT, param);

            vm_push_pcb_into_status_union(VM_PMNG_UNLOAD, 
                vm_pop_pcb_up_status_union(VM_PMNG_CLOSING, pcb->pHandle));
                
            /* Notify N-center APP have exit */
            if (pcb->is_support_bg_run)
            {
                vm_send_msg(0, VM_MSG_QUIT, (VMINT)pcb->fullFileName, 0);
            }

			vm_pmng_notify_res_data(pcb,VM_PMNG_UNLOAD);
            vm_close_kernel_exec_file(pcb);
        }
    }

    vm_cleanup_unload_status_pcb();

    
}


/*****************************************************************************
 * FUNCTION
 *  vm_reg_sysevt_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_sysevt_callback(void (*f)(VMINT message, VMINT param)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
        vm_log_debug("PCB[%d] register system event handler.", pcb->pHandle);
        pcb->sysEventHandler = f;
    }
    else
    {
        vm_log_error("Dismatch pcb by r9 value=%d.", currAppR9);
    }
}

#ifdef __MRE_CORE_APP_COMMUNICATION__

/* vmappcomm.h */
/*****************************************************************************
* FUNCTION
 *  vm_reg_msg_proc
 * DESCRIPTION
 *  register user defined message callback function.
 * PARAMETERS
 *  proc        [IN]        Callback function.
*****************************************************************************/
void vm_reg_msg_proc(VM_MESSAGE_PROC proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
        vm_log_debug("PCB[%d] register user message proc.", pcb->pHandle);
        pcb->message_proc= proc;
    }
    else
    {
        vm_log_error("Dismatch pcb by r9 value=%d.", currAppR9);
    }
}
#endif /* __MRE_CORE_APP_COMMUNICATION__  */


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_create_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fileName        [IN]        
 *  mem_base        [?]         
 * RETURNS
 *  
 *****************************************************************************/
VM_P_HANDLE vm_pmng_create_process(VMWSTR fileName, VMUINT8* mem_base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_exec_format_enum suffix;
    VMINT rorw_zip;
    vm_file_type_enum file_type;
    VMINT is_ads;
    vm_load_context_t context;
    
    VMINT loadFromCard = FALSE;
    _vm_pcb_t *father_pcb, *pcb;
    VMINT asm_index;
    VMINT bufSize;
    VMINT lerr = 0, info = 0, ret = 0;
    VMCHAR tmp_buf[24];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
    extern VMUINT8 * _vm_sm_get_key(void);
    extern void _vm_sm_free_key(void);
#endif

    if (!fileName || fileName[0] == 0)
    {
        lerr = 1; goto unknown_type;
    }

    memset(&context, 0, sizeof(context));
    
    /* father_pcb = NULL; */
    vm_get_parent_process(&father_pcb);
    
    vm_cleanup_unload_status_pcb();

    suffix = vm_parse_exec_format(fileName);
    /* get RO RW is zipped or not */
    rorw_zip = 0; bufSize = 4;
    if (vm_get_vm_tag(fileName, VM_CE_INFO_RO_RW_ZIP, &rorw_zip, &bufSize) != GET_TAG_TRUE) {
        rorw_zip = 0;
    }
    file_type = vm_get_file_type(fileName);
    
    /* error checking */
    if (suffix != VM_EXEC_ROM && suffix != VM_EXEC_VXP && suffix != VM_EXEC_DLL) {
        lerr = 2; info = suffix; goto unknown_type;
    }
    for (asm_index = 0; asm_index < MRE_SUPPORT_MAX_APP_NUM; asm_index++) {
        if (g_app_mem_info[asm_index].mem_base == mem_base) {
            break;
        }
    }
    if (asm_index == MRE_SUPPORT_MAX_APP_NUM) {
        lerr = 3; info = (VMINT)mem_base; goto unknown_type;
    }
    if (suffix == VM_EXEC_VXP || suffix == VM_EXEC_DLL) {
        VMWCHAR sysDriver = (VMWCHAR)vm_get_removeable_driver();
        VMWCHAR fileDriver = fileName[0];
        
        // convert them to upper case first
        if (sysDriver >= L'a' && sysDriver <= L'z') {
            sysDriver -= (L'a' - L'A');
        }
        if (fileDriver >= L'a' && fileDriver <= L'z') {
            fileDriver -= (L'a' - L'A');
        }
        
        // default value of loadFromCard is FALSE
        if (sysDriver >= L'A' && sysDriver <= L'Z') {
            if (fileDriver == sysDriver) {
                loadFromCard = TRUE;
            }
        }
    }
    
    /* allocate resource first */
    pcb = vm_alloc_pcb(fileName, father_pcb, loadFromCard);
    if (pcb == NULL) {
        lerr = 4; goto unknown_type;
    }
    vm_set_pcb_flag(pcb);
    bufSize = 4;
    if (vm_get_vm_tag(fileName, VM_CE_INFO_APP_ID, &(pcb->app_id), &bufSize) != GET_TAG_TRUE) {
        lerr = 5; info = pcb->app_id; goto free_pcb;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fileName, VM_CE_INFO_NO_SCREEN, &(pcb->isNoScreen), &bufSize) != GET_TAG_TRUE) {
        pcb->isNoScreen = 0;
    }
    bufSize = 4;
    if (vm_get_vm_tag(fileName, VM_CE_INFO_CHARSET, &ret, &bufSize) == GET_TAG_TRUE) {
		/* IT's a MRE 2.0 or after app*/
		pcb->version = 2000;
    }
	else {
		/* This is not a charset app, it's a MRE 1.0 APP */
		pcb->version = 1000;
    }
    /* load  function list from file */
    vm_ce_merge_permission(fileName);
    pcb->mre_fun_list = _vm_per_get_mre_fun_list();
    _vm_per_clear_mre_fun_list();
    if (pcb->mre_fun_list == NULL) {
        lerr = 6; goto free_pcb;
    }
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
    pcb->sm_key = _vm_sm_get_key();
#endif
            
    context.fileName = fileName;
    context.suffix = suffix;
    context.rorw_zip = rorw_zip;
    context.file_type = file_type;
    context.asm_index = asm_index;
    context.load_buffer = mem_base;
    context.load_size = g_app_mem_info[asm_index].mem_size;
    
    ret = vm_load_normal(&context);
    if (ret != 0) {
        lerr = 7; info = ret; goto free_funlist;
    }
    
    // copy values from context into pcb
    pcb->codeBase = context.codeBase;
    pcb->codeSize = context.codeSize;
    pcb->dataBase = context.dataBase;
    pcb->dataSize = context.dataSize;
    pcb->sysv_node = context.sysv_node;
    
    is_ads = (file_type == VM_VXP_ADS 
            || file_type == VM_VSM_ADS 
            || file_type == VM_SIMPLE_VXP_ADS);
    if (is_ads) {
        pcb->heapBase = context.dataBase + context.dataSize + HEAP_SIZE;
        pcb->heapSize = (context.load_buffer + context.load_size) - pcb->heapBase - STACK_SIZE;
    }
    else {
        pcb->heapBase = context.dataBase + context.dataSize;
        pcb->heapSize = (context.load_buffer + context.load_size) - pcb->heapBase;
    }
    
    pcb->r9 = (unsigned int)pcb->dataBase;
    
    pcb->initParams[0] = (unsigned int)pcb->dataBase;
    pcb->initParams[1] = (unsigned int)vm_get_sym_entry;
    pcb->initParams[2] = (unsigned int)(pcb->heapBase + pcb->heapSize);
    pcb->initParams[3] = pcb->initParams[2] + HEAP_SIZE;
    pcb->initParams[4] = STACK_SIZE;
    pcb->initParams[5] = (unsigned int)context.entry;
    
    pcb->father_pcb = father_pcb;
    if (suffix == VM_EXEC_VXP || suffix == VM_EXEC_DLL) {
        pcb->fileHandle = (VMINT)FS_Open((WCHAR*)fileName, FS_READ_ONLY | FS_OPEN_SHARED);
        if (pcb->fileHandle < 0) {
            MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PMNG_CREATE_OPEN);
        }
    }
    
    /* set heap segment of app, and create ADM ID */
    g_app_mem_info[asm_index].adm_id = (void *)kal_adm_create((void*)pcb->heapBase, (VMUINT)pcb->heapSize, NULL, KAL_TRUE);
    if (g_app_mem_info[asm_index].adm_id == NULL) {
        lerr = 8; goto free_funlist;
    }
    g_app_mem_info[asm_index].p_handle = pcb->pHandle;
    g_app_mem_info[asm_index].heap_size = pcb->heapSize;
	vm_mutex_init(&(g_app_mem_info[asm_index].mutex));
    
	pcb->file_type = file_type;
	pcb->base_name = (VMWSTR)wcsrchr((wchar_t *)pcb->fullFileName, L'\\');
	if (pcb->base_name != NULL)
	{
	    pcb->base_name++; // skip last '\'
	}
	else
	{
	    pcb->base_name = pcb->fullFileName;
	}
	bufSize = 24;
	if (vm_get_vm_tag(fileName, VM_CE_INFO_ISSUE, (void *)tmp_buf, &bufSize) == GET_TAG_TRUE)
	{
	    pcb->build_id = (tmp_buf[4] << 24) + (tmp_buf[8] << 16) + (tmp_buf[12] << 8) + tmp_buf[16];
	}
	else
	{
	    pcb->build_id = 0;
	}
	pcb->dtype = VM_DEBUG_PROCESS;
	
    ret = vm_exec_process(pcb);
    if (ret != 0) {
        lerr = 9; info = ret; goto reset_asm;
    }
    return pcb->pHandle;

reset_asm:
    g_app_mem_info[asm_index].p_handle = -1;
    if (0 != g_app_mem_info[asm_index].adm_id)
    {
        kal_adm_delete(g_app_mem_info[asm_index].adm_id);
        g_app_mem_info[asm_index].adm_id = 0;
    }
    g_app_mem_info[asm_index].adm_id = NULL;
    g_app_mem_info[asm_index].heap_size = 0;
free_funlist:
    /* pcb->mre_fun_list will be free in vm_free_pcb */
    /* pcb->sm_key will be free in vm_free_pcb */
free_pcb:
    vm_free_pcb(pcb);
unknown_type:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PMNG_CREATE_PROCESS, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM,
            VM_PMNG_ERROR_PARAM, VM_PMNG_NO_MEM,  VM_PMNG_ERROR_IO, VM_PMNG_ERROR_FUNLST, VM_PMNG_ERROR_PARAM,
            VM_PMNG_NO_MEM, VM_PMNG_EXIT };
        if (lerr == 7) {
            return (ret == VM_LOAD_ERR_OOM) ? VM_PMNG_NO_MEM : VM_PMNG_ERROR_PARAM;
        }
        return err_map[lerr];
    }
}

VM_P_HANDLE vm_pmng_create_process_from_preload_info(vm_preload_app_info_t *preload_info, vm_app_mem_struct* mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_exec_format_enum suffix;
    //VMINT rorw_zip;
    VMWSTR fileName = preload_info->fullFileName;
    VMINT loadFromCard = FALSE;
    _vm_pcb_t *father_pcb, *pcb;
    VMINT lerr = 0, info = 0, ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
    extern VMUINT8 * _vm_sm_get_key(void);
    extern void _vm_sm_free_key(void);
#endif

    if (!fileName || fileName[0] == 0)
    {
        lerr = 1; goto unknown_type;
    }
    
    /* father_pcb = NULL; */
    vm_get_parent_process(&father_pcb);
    
    vm_cleanup_unload_status_pcb();

    if (preload_info->saved_context.suffix == VM_EXEC_VXP 
        || preload_info->saved_context.suffix == VM_EXEC_DLL) {
        VMWCHAR sysDriver = (VMWCHAR)vm_get_removeable_driver();
        VMWCHAR fileDriver = fileName[0];
        
        // convert them to upper case first
        if (sysDriver >= L'a' && sysDriver <= L'z') {
            sysDriver -= (L'a' - L'A');
        }
        if (fileDriver >= L'a' && fileDriver <= L'z') {
            fileDriver -= (L'a' - L'A');
        }
        
        // default value of loadFromCard is FALSE
        if (sysDriver >= L'A' && sysDriver <= L'Z') {
            if (fileDriver == sysDriver) {
                loadFromCard = TRUE;
            }
        }
    }
    
    /* allocate resource first */
    pcb = vm_alloc_pcb(fileName, father_pcb, loadFromCard);
    if (pcb == NULL) {
        lerr = 4; goto unknown_type;
    }
    vm_set_pcb_flag(pcb);
    pcb->preload_info = preload_info;
    pcb->app_id = preload_info->app_id;
    pcb->isNoScreen = preload_info->isNoScreen;
    pcb->version = preload_info->version;
    pcb->mre_fun_list = preload_info->mre_fun_list;

#if defined(__MRE_CORE_SMAUTH__) && defined (__MRE_SAL_CHE_DES__)
    pcb->sm_key = _vm_sm_get_key();
#endif
    
    ret = vm_load_preload_app(preload_info);
    if (ret != 0) {
        lerr = 7; info = ret; goto free_funlist;
    }
    
    // copy values from context into pcb
    pcb->codeBase = preload_info->saved_context.codeBase;
    pcb->codeSize = preload_info->saved_context.codeSize;
    pcb->dataBase = preload_info->saved_context.dataBase;
    pcb->dataSize = preload_info->saved_context.dataSize;
    pcb->sysv_node = preload_info->saved_context.sysv_node;
    
    pcb->heapBase = preload_info->heapBase;
    pcb->heapSize = preload_info->heapBufSize;
    
    pcb->r9 = (unsigned int)pcb->dataBase;
    
    pcb->initParams[0] = (unsigned int)pcb->dataBase;
    pcb->initParams[1] = (unsigned int)vm_get_sym_entry;
    pcb->initParams[2] = (unsigned int)(pcb->heapBase + pcb->heapSize);
    pcb->initParams[3] = pcb->initParams[2] + HEAP_SIZE;
    pcb->initParams[4] = STACK_SIZE;
    pcb->initParams[5] = (unsigned int)preload_info->saved_context.entry;
    
    pcb->father_pcb = father_pcb;
    suffix = vm_parse_exec_format(fileName);
    if (suffix == VM_EXEC_VXP || suffix == VM_EXEC_DLL) {
        pcb->fileHandle = (VMINT)FS_Open((WCHAR*)fileName, FS_READ_ONLY | FS_OPEN_SHARED);
        if (pcb->fileHandle < 0) {
            MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PMNG_CREATE_OPEN);
        }
    }
    
    /* set heap segment of app, and create ADM ID */
    mem->adm_id = (void *)kal_adm_create((void*)pcb->heapBase, (VMUINT)pcb->heapSize, NULL, KAL_TRUE);
    if (mem->adm_id == NULL) {
        lerr = 8; goto free_funlist;
    }
    mem->p_handle = pcb->pHandle;
    mem->heap_size = pcb->heapSize;
	vm_mutex_init(&(mem->mutex));
    
	pcb->file_type = preload_info->saved_context.file_type;
	pcb->base_name = (VMWSTR)wcsrchr((wchar_t *)pcb->fullFileName, L'\\');
	if (pcb->base_name != NULL)
	{
	    pcb->base_name++; // skip last '\'
	}
	else
	{
	    pcb->base_name = pcb->fullFileName;
	}
	pcb->build_id = preload_info->build_id;
	pcb->dtype = VM_DEBUG_PROCESS;
	
    ret = vm_exec_process(pcb);
    if (ret != 0) {
        lerr = 9; info = ret; goto reset_asm;
    }
    
    return pcb->pHandle;

reset_asm:
    mem->p_handle = -1;
    if (0 != mem->adm_id)
    {
        kal_adm_delete(mem->adm_id);
        mem->adm_id = 0;
    }
    mem->heap_size = 0;
free_funlist:
    /* pcb->mre_fun_list will be free in vm_free_pcb */
    /* pcb->sm_key will be free in vm_free_pcb */
    pcb->mre_fun_list = NULL; // don't free preload app's fun list
    vm_free_pcb(pcb);
unknown_type:
    MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PMNG_CREATE_PROCESS, lerr, info, ret);
    {
        static const VMINT err_map[] = { VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM, VM_PMNG_ERROR_PARAM,
            VM_PMNG_ERROR_PARAM, VM_PMNG_NO_MEM,  VM_PMNG_ERROR_IO, VM_PMNG_ERROR_FUNLST, VM_PMNG_ERROR_PARAM,
            VM_PMNG_NO_MEM, VM_PMNG_EXIT };
        if (lerr == 7) {
            return (ret == VM_LOAD_ERR_OOM) ? VM_PMNG_NO_MEM : VM_PMNG_ERROR_PARAM;
        }
        return err_map[lerr];
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_exit_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT currAppR9;
    VM_PROCESS_STATUS status;
    _vm_pcb_t* pcb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currAppR9 = vm_get_running_app_sb();
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL)
    {
        vm_pmng_delete_process_int(pcb,status,0);
        if (VM_START_APP_RESTART_PARENT & pcb->flag)
        {
            vm_post_msg(pcb->pHandle,VM_MSG_RESTART_PARENT,(VMINT)pcb->parent_path,0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_exit_and_update_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_exit_and_update_app(void)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_delete_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_delete_process(VM_P_HANDLE p_handle)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, &status)) != NULL
        && status != VM_PMNG_UNLOAD)
    {
        return vm_pmng_delete_process_int(pcb, status, 0);
    }

    return VM_PMNG_PROCESS_NO_EXISTS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_destroy_bg_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_destroy_bg_process(VMWSTR filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_FOREGROUND;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)filename, &status)) != NULL
        && status != VM_PMNG_UNLOAD)
    {
        /* foreground running application returns error */
        if (status == VM_PMNG_FOREGROUND)
        {
            return VM_PMNG_NO_OP_IN_STATUS;
        }

        vm_pmng_delete_process_int(pcb,status,0);
        return VM_PMNG_OP_OK;
    }

    return VM_PMNG_PROCESS_NO_EXISTS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_get_process_lst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  status          [IN]        
 *  pHandle         [IN]        
 *  process_num     [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_get_process_lst(VM_PROCESS_STATUS status, VM_P_HANDLE** pHandle, 
    VMUINT* process_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT i = 0;
    _vm_pcb_t* tmp = NULL;
    VM_P_HANDLE* p_tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status >= VM_PMNG_MAX_NUM || pHandle == NULL || process_num == NULL)
    {
        return VM_PMNG_ERROR_PARAM;
    }

    /* count process number of specified state */
    for (i = 0, tmp = pcb_table[status]; tmp != NULL; tmp = tmp->next_pcb, i++);

    if (i > 0)
    {
        if ((p_tmp = _vm_kernel_malloc(sizeof(VM_P_HANDLE) * i)) == NULL)
        {
            return VM_PMNG_NO_MEM;
        }

        for (i = 0, tmp = pcb_table[status]; tmp != NULL; tmp = tmp->next_pcb, i++)
        {
            *(p_tmp + i) = tmp->pHandle;
        }

        *pHandle = p_tmp;
    }
    else
    {
        *pHandle = 	NULL;
    }

    *process_num = i;

    return VM_PMNG_OP_OK;
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_max_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_max_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MRE_SUPPORT_MAX_APP_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_current_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_current_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT sum = 0, i = VM_PMNG_FOREGROUND;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = VM_PMNG_FOREGROUND; i < VM_PMNG_MAX_NUM; i++)
    {
        for (pcb = pcb_table[i]; pcb; pcb = pcb->next_pcb)
        {
            sum++;
        }
    }

    return sum;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_fg_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VM_P_HANDLE vm_pmng_fg_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pcb_table[VM_PMNG_FOREGROUND])
    {
        return pcb_table[VM_PMNG_FOREGROUND]->pHandle;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VM_PROCESS_STATUS vm_pmng_state(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VM_PMNG_CUR_HANDLE == p_handle)
    {
        VMINT currAppR9 = vm_get_running_app_sb();

        if (vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status) != NULL)
        {
            return status;
        }
#ifdef __MRE_CORE_SM__
		else
		{
			/* Find SM copy by R9 */
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
			if (sm_ptr && sm_ptr->pcb)
			{
				//vm_log_debug("[SM] vm_pmng_state(%d) - SM[%d] copy found by R9[%d]", p_handle, sm_copy->handle, currR9);
				/* Get status of APP PCB that this SM copy is working for */
				if (vm_sh_pcb_in_pt(SH_TYPE_PCB, (VMINT)sm_ptr->pcb, &status) != NULL)
				{
					//vm_log_debug("[SM] vm_pmng_state(%d) - PCB[] status[%d] got by SM copy's pcb[%p]", p_handle, status, sm_copy->pcb);
					return status;
				}
			}
		}
#endif
	}
	else
	{
		if (vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, &status) != NULL)
		{
			return status;
		}
#ifdef __MRE_CORE_SM__
		else 	/* SM copy' handle */
		{
			/* Find SM copy by handle */
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE, p_handle);
			if (sm_ptr && sm_ptr->pcb)
			{
				//vm_log_debug("[SM] vm_pmng_state(%d) - SM[%d] copy found by handle", p_handle, sm_copy->handle);
				/* Get status of APP PCB that this SM copy is working for */
				if (vm_sh_pcb_in_pt(SH_TYPE_PCB, (VMINT)sm_ptr->pcb, &status) != NULL)
				{
					//vm_log_debug("[SM] vm_pmng_state(%d) - PCB[] status[%d] got by SM copy's pcb[%p]", p_handle, status, sm_copy->pcb);
					return status;
				}
			}
		}
#endif
    }

    return VM_PMNG_UNLOAD;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_get_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VM_P_HANDLE vm_pmng_get_handle(VMWSTR file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)file_name, &status)) != NULL)
    {
        return pcb->pHandle;
    }
#ifdef __MRE_CORE_SM__
	else
	{
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_FILENAME, (VMINT)file_name);

		if (sm_ptr)
			return sm_ptr->handle;
	}
#endif /* __MRE_CORE_SM__ */ 
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  vm_pmng_is_support_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_is_support_bg(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_handle == VM_PMNG_CUR_HANDLE)
    {
        p_handle = vm_pmng_get_current_handle();
    }
 
    if ((pcb  = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, NULL)) != NULL)
    {
        return pcb->is_support_bg_run;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_send_sys_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle            [IN]        
 *  user_message        [IN]        
 *  memsage_param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_send_sys_msg(VM_P_HANDLE p_handle, VMINT user_message, VMINT memsage_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_message < 5000)
    {
        return VM_PMNG_ERROR_PARAM;
    }

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, &status)) != NULL
        && status != VM_PMNG_UNLOAD)
    {
		_vm_sb_stack_push(pcb->r9);
		if (pcb->sysEventHandler)
		{
			pcb->sysEventHandler(user_message, memsage_param);
		}
		_vm_sb_stack_pop();

        return VM_PMNG_OP_OK;
    }

    return VM_PMNG_PROCESS_NO_EXISTS;
}




/*****************************************************************************
 * FUNCTION
 *  _vm_sb_stack_push
 * DESCRIPTION
 *  
 * PARAMETERS
 *  r9      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_sb_stack_push(VMINT r9)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack.num < MAX_CTX_STACK_NUM)
    {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_STACK_PUSH, 
		        stack.num, stack.num+1, vm_get_running_app_sb(), r9);
		        
		stack.ctxs[stack.num].restore_r9 = vm_get_sb();
		stack.ctxs[stack.num].app_r9 = vm_get_running_app_sb();
		stack.num++;
        VM_RESTORE_PCB_SB(r9);
        return VM_PMNG_OP_OK;
    }
    return VM_PMNG_NO_OP_IN_STATUS;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_sb_stack_pop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_sb_stack_pop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stack.num > 0)
    {
        MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_STACK_POPUP1, 
                stack.num, stack.num-1, vm_get_sb(), stack.ctxs[stack.num-1].restore_r9);
                
        --stack.num;
		MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_STACK_POPUP2,stack.ctxs[stack.num].app_r9);

		vm_restore_sb(stack.ctxs[stack.num].restore_r9);
		g_vm_stub_sb = stack.ctxs[stack.num].app_r9;
        return VM_PMNG_OP_OK;
    }
    return VM_PMNG_NO_OP_IN_STATUS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_ctx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_set_ctx_vrt(VM_P_HANDLE p_handle)
{
    VMINT currR9;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;
    
    ASSERT(p_handle);

    currR9 = vm_get_sb();

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
    p_handle, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        if (stack_vrt.num >= MAX_CTX_STACK_NUM)
        {
            return VM_PMNG_NO_OP_IN_STATUS;
        }
        else
        {
			stack_vrt.ctxs[stack_vrt.num].restore_r9 = currR9;
			stack_vrt.ctxs[stack_vrt.num].app_r9 = vm_get_running_app_sb();
			stack_vrt.num ++;
			vm_restore_sb(pcb->r9);
			g_vm_stub_sb_vrt = pcb->r9;
			return VM_PMNG_OP_OK;
        }
    }
    return VM_PMNG_NO_OP_IN_STATUS;

}

VMINT vm_pmng_reset_ctx_vrt(void)
{
    if (stack_vrt.num > 0)
    {
		//vm_restore_sb(stack_vrt.ctxs[(stack_vrt.num - 1)].restore_r9);
		stack_vrt.num --;
		vm_restore_sb(stack_vrt.ctxs[stack_vrt.num].restore_r9);
		g_vm_stub_sb_vrt = stack_vrt.ctxs[stack_vrt.num].app_r9; 
		return VM_PMNG_OP_OK;
	}
    return VM_PMNG_NO_OP_IN_STATUS;
}
#ifdef __MRE_CORE_SM__

VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT currR9;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_LOCK;
    if (p_handle == 0)
    {
        if (stack.num >= MAX_CTX_STACK_NUM)
        {
            MRE_UNLOCK;
            return VM_PMNG_NO_OP_IN_STATUS;
        }
        else
        {
            currR9 = vm_get_sb();
            stack.ctxs[stack.num].restore_r9 = currR9;
			stack.ctxs[stack.num].app_r9 = vm_get_running_app_sb();
            stack.num++;
            MRE_UNLOCK;
            return VM_PMNG_OP_OK;
        }
    }
    else
    {
        VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
        _vm_pcb_t* pcb = NULL;
        
        if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
            p_handle, &status)) != NULL && status != VM_PMNG_UNLOAD)
        {
            if (stack.num >= MAX_CTX_STACK_NUM)
            {
                MRE_UNLOCK;
                return VM_PMNG_NO_OP_IN_STATUS;
            }
            else
            {
                currR9 = vm_get_sb();
                stack.ctxs[stack.num].restore_r9 = currR9;
				stack.ctxs[stack.num].app_r9 = vm_get_running_app_sb();
                stack.num++;
                VM_RESTORE_PCB_SB(pcb->r9);
                MRE_UNLOCK;
                return VM_PMNG_OP_OK;
            }
        }
        else
        {
            MRE_UNLOCK;
            return vm_sm_set_sb_by_handle(p_handle);
        }
    }
}
#else /* __MRE_CORE_SM__ */ 


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_ctx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT currR9;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_handle == 0)
    {
        if (stack.num >= MAX_CTX_STACK_NUM)
        {
            return VM_PMNG_NO_OP_IN_STATUS;
        }
        else
        {
            currR9 = vm_get_sb();
            stack.ctxs[stack.num].restore_r9 = currR9;
			stack.ctxs[stack.num].app_r9 = vm_get_running_app_sb();
            stack.num++;
            return VM_PMNG_OP_OK;
        }
    }
    else
    {
        VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
        _vm_pcb_t* pcb = NULL;
        
        if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
            p_handle, &status)) != NULL && status != VM_PMNG_UNLOAD)
        {
            if (stack.num >= MAX_CTX_STACK_NUM)
            {
                return VM_PMNG_NO_OP_IN_STATUS;
            }
            else
            {
                currR9 = vm_get_sb();
                stack.ctxs[stack.num].restore_r9 = currR9;
				stack.ctxs[stack.num].app_r9 = vm_get_running_app_sb();
                stack.num++;
                VM_RESTORE_PCB_SB(pcb->r9);
                return VM_PMNG_OP_OK;
            }
        }
        else
        {
            return VM_PMNG_NO_OP_IN_STATUS;
        }
    }
}

#endif /* __MRE_CORE_SM__ */ 


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_reset_ctx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_reset_ctx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_LOCK;
    if (stack.num > 0)
	{
	    stack.num--;
		vm_restore_sb(stack.ctxs[stack.num].restore_r9);
		g_vm_stub_sb = stack.ctxs[stack.num].app_r9; 
		
        MRE_UNLOCK;
        return VM_PMNG_OP_OK;
    }
    MRE_UNLOCK;
    return VM_PMNG_NO_OP_IN_STATUS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle            [IN]        
 *  filename_buf        [?]         
 *  filename_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_file_name(VM_P_HANDLE p_handle, VMWCHAR *filename_buf, VMINT filename_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_buf == NULL || filename_len < 0)
    {
        return VM_PMNG_ERROR_PARAM;
    }

    if (p_handle == VM_PMNG_CUR_HANDLE)
    {
        p_handle = vm_pmng_get_current_handle();
    }

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, &status)) != NULL
        && status != VM_PMNG_UNLOAD)
    {
        vm_wstrncpy(filename_buf, pcb->fullFileName, filename_len);

        return VM_PMNG_OP_OK;
    }

    return VM_PMNG_PROCESS_NO_EXISTS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_get_current_handle_ignore_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_get_current_handle_ignore_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_pmng_get_current_handle();
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_get_current_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VM_P_HANDLE vm_pmng_get_current_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
	{
			return pcb->pHandle;
	}
#ifdef __MRE_CORE_SM__
	else		/* Current R9 is SM copy */
	{
		/* Find SM copy by R9 */
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);

		if (sm_ptr)
			return sm_ptr->handle;
	}
#endif /* __MRE_CORE_SM__ */ 
    return 0;
}

#ifdef __MRE_CORE_SM__


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_get_app_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_get_app_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find APP PCB by current R9 */
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
        return pcb->pHandle;
    }
    else		/* Current R9 is SM copy */
	{
		/* Find SM copy by R9 */
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		/* Return APP's PCB handle that SM copy is working for */
		if (sm_ptr && sm_ptr->pcb)
			return sm_ptr->pcb->pHandle;
	}

	return 0;
}
#endif /* __MRE_CORE_SM__ */ 


/*****************************************************************************
 * FUNCTION
 *  vm_get_exec_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_exec_filename(VMWSTR filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (filename)
	{
		_vm_pcb_t* pcb = NULL;
		VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
		VMINT currAppR9 = vm_get_running_app_sb();
	
		if ((pcb =  vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL 
			&& status != VM_PMNG_UNLOAD)
		{
			vm_wstrcpy(filename, pcb->fullFileName);
		}
#ifdef __MRE_CORE_SM__
		else
		{
			/**
			 * If current executing file is SM, return the APP file name who invoked the SM.
			 */
			 
			/* Find SM copy by R9 */
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);

			/* Find APP PCB that SM copy is working for */
			if (sm_ptr && sm_ptr->pcb)
				vm_wstrcpy(filename, sm_ptr->pcb->fullFileName);
		}
#endif
        return 0;
    }
    
    return -1;
}


 /*****************************************************************************
  * FUNCTION
  *  vm_get_self_filename
  * DESCRIPTION
  *  
  * PARAMETERS
  *  filename		 [OUT]		 
  * RETURNS
  *  
  *****************************************************************************/
VMWSTR vm_get_self_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcb = NULL;
	VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
	VMINT currAppR9 = vm_get_running_app_sb();

	if ((pcb =  vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL 
		&& status != VM_PMNG_UNLOAD)
	{
		return pcb->fullFileName;
	}
#ifdef __MRE_CORE_SM__
	else
	{
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr && sm_ptr->pcb)
			return sm_ptr->fullFileName;
	}
#endif
	return NULL;
	
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_app_id(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, p_handle, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        return pcb->app_id;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_current_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_current_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find APP PCB by current R9 */
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, NULL)) != NULL)
    {
        return pcb->app_id;
    }
#ifdef __MRE_CORE_SM__
	else		/* Current R9 is SM copy */
	{
		/* Find SM copy by R9 */
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		/* Return APP's APP ID that SM copy is working for */
		if (sm_ptr)
			return sm_ptr->app_id;
	}
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_event_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_filter        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_set_event_filter(_event_filter_t* event_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_filter == NULL)
    {
        return -1;
    }

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        pcb->event_filter = event_filter;
        return 0;
    }
#ifdef __MRE_CORE_SM__
    else 	/* Current R9 is SM copy */
	{
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			sm_ptr->event_filter = event_filter;
			return 0;
        }
    }
#endif /* __MRE_CORE_SM__ */ 
    return -2;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_restore_default_event_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_restore_default_event_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9,  &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        pcb->event_filter = &vm_default_filter;
        return 0;
    }
#ifdef __MRE_CORE_SM__
    else 	/* Current R9 is SM copy */
	{
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr)
		{
			sm_ptr->event_filter = &vm_default_filter;
			return 0;
		}
    }
#endif /* __MRE_CORE_SM__ */ 
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_send_app_sys_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pmng_status     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_send_app_sys_event(VM_PROCESS_STATUS pmng_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int flag = FALSE;
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9,  &status)) != NULL 
        && status != VM_PMNG_UNLOAD && pcb->sysEventHandler)
    {
        flag = TRUE;
        vm_log_debug("[SM] vm_pmng_send_app_sys_event - to send [%d] msg to PCB[%d] in SM[%d]", pmng_status, pcb->r9, currAppR9);
    }
    else 	/* Current R9 is SM copy */
	{
#ifdef __MRE_CORE_SM__
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_R9, currAppR9);
		if (sm_ptr && sm_ptr->pcb && sm_ptr->pcb->sysEventHandler)
		{
			flag = TRUE;
			pcb = sm_ptr->pcb;
			vm_log_debug("[SM] vm_pmng_send_app_sys_event - to send [%d] msg to APP[%d] in SM[%d]", pmng_status, pcb->pHandle, sm_ptr->handle);
		}
#endif
    }
    
    vm_log_debug("[SM] vm_pmng_send_app_sys_event - flag:%d", flag);
    if (flag)
    {
		_vm_sb_stack_push(pcb->r9);
        switch (pmng_status)
        {
        case VM_PMNG_FOREGROUND:
            if (!(pcb->is_support_bg_run))
            {
                pcb->sysEventHandler(VM_MSG_ACTIVE, 0);
            }
            
            pcb->sysEventHandler(VM_MSG_PAINT, 0);
            break;
        case VM_PMNG_BACKGROUND:
            if (!(pcb->is_support_bg_run))
            {
                pcb->sysEventHandler(VM_MSG_INACTIVE, 0);
            }
            else
            {
                pcb->sysEventHandler(VM_MSG_HIDE, 0);
            }
            break;
        case VM_PMNG_UNLOAD:
            pcb->sysEventHandler(VM_MSG_QUIT, 0);
            break;
        default:
            // do nothing.
            break;
        }
		_vm_sb_stack_pop();
    }

    vm_cleanup_unload_status_pcb();

    return 0;
}

/* vmenv.h */


/*****************************************************************************
 * FUNCTION
 *  vm_vam_app_is_running
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vxp_filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_vam_app_is_running(VMWSTR vxp_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vxp_filename || vxp_filename[0] == 0)
        return FALSE;

    if ((vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)vxp_filename, &status)) != NULL &&
        status != VM_PMNG_UNLOAD)
    {
        return TRUE;
    }

    return FALSE;
}

void vm_pmng_set_venus_flag(void)
{
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
#endif    
}

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
#endif

/* vmio.h */


/*****************************************************************************
 * FUNCTION
 *  vm_reg_keyboard_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyBoardHandler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_keyboard_callback(vm_key_handler_t keyBoardHandler) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        vm_log_debug("PCB[%d] registier keyborad handler.", pcb->pHandle);
        pcb->keyHandler = keyBoardHandler;
    }
}

_vm_pcb_t ** vm_pmng_get_pcb_ptr()
{
    return pcb_table;
}

VMINT vm_reg_keyboard_callback_ex(vm_key_handler_ex_t keyBoardExHandler) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        vm_log_debug("PCB[%d] registier keyborad EX handler.", pcb->pHandle);
        pcb->keyExHandler = keyBoardExHandler;
    }
    else
    {
        return -2;
    }

    return 0;
}

/* vmio.h */


/*****************************************************************************
 * FUNCTION
 *  vm_reg_pen_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  penHandler      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_reg_pen_callback(vm_pen_handler_t penHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL && status != VM_PMNG_UNLOAD)
    {
        vm_log_debug("PCB[%d] registier pen handler.", pcb->pHandle);
        pcb->penHander = penHandler;
    }
}

/* vmproevt.h */


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_deal_key_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vmKeyCode       [IN]        
 *  vmKeyEvent      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_deal_key_event(VMINT vmKeyCode, VMINT vmKeyEvent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcb = pcb_table[VM_PMNG_FOREGROUND];
	VMINT resend = TRUE;
	VMINT ret = 0;

    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_KEY_EVENT, vmKeyCode,vmKeyEvent);
  
    if ((pcb)&&((pcb->keyHandler) || pcb->keyExHandler))
    {
       _vm_sb_stack_push(pcb->r9);
        
        if (!(pcb->event_filter) || !(pcb->event_filter->key_event_filter)
            || pcb->event_filter->key_event_filter(vmKeyEvent, vmKeyCode))
        {
#ifdef __MRE_CORE_SM__
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_PCB_EVENT_FILTER, (VMINT)pcb);

			if (sm_ptr && sm_ptr->event_filter->key_event_filter)
			{

				_vm_sb_stack_push(sm_ptr->r9);
			    resend = sm_ptr->event_filter->key_event_filter(vmKeyEvent, vmKeyCode);
				_vm_sb_stack_pop();
				
				vm_log_debug("[SM] Key event[] filtered by SM[%d]", sm_ptr->handle);
			}
#endif
			if(resend)
			{
				if (pcb->is_support_all_pen_and_key_event)
				{
				    if (pcb->keyHandler)
				    {
                                    pcb->keyHandler(vmKeyEvent, vmKeyCode);
                                    ret = 1;
                                }
                                if (pcb->keyExHandler)
                                {
                                    ret = pcb->keyExHandler(vmKeyEvent, vmKeyCode);
                                }
                                _vm_sb_stack_pop();
                   
                                return ret;
				}
				else
				{
					if ((vmKeyCode != VM_KEY_VOL_UP 
						&& vmKeyCode != VM_KEY_VOL_DOWN)
						&& (vmKeyEvent != VM_KEY_EVENT_LONG_PRESS 
						&& vmKeyEvent != VM_KEY_EVENT_REPEAT))
					{
                                        if (pcb->keyHandler)
                                        {
                                            pcb->keyHandler(vmKeyEvent, vmKeyCode);
                                            ret = 1;
                                        }
                                        if (pcb->keyExHandler)
                                        {
                                            ret = pcb->keyExHandler(vmKeyEvent, vmKeyCode);
                                        }
                                        _vm_sb_stack_pop();                      
                        
                                        return ret;
					}
				}
			}
#ifdef __MRE_CORE_SM__
		}
#endif

        _vm_sb_stack_pop();
    }
    return 0;
}

/* vmproevt.h */
extern S32 MMI_status_bar_height;

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_deal_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vmPenEvent      [IN]        
 *  x               [IN]        
 *  y               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_deal_pen_event(VMINT vmPenEvent, VMINT x, VMINT y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcb = pcb_table[VM_PMNG_FOREGROUND];
	VMINT resend = TRUE;
    mmi_pen_point_struct  pos;
    mmi_pen_event_type_enum eventType;
    static VMINT should_show_ncenter = 0;

    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_PEN_EVENT,vmPenEvent,x,y);
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if	(defined __MRE_LIB_EDITOR__ && defined __MMI_TOUCH_SCREEN__)
    pos.x = x;
    pos.y = y;
    switch (vmPenEvent)
    {
        case VM_PEN_EVENT_TAP:
            eventType = MMI_PEN_EVENT_DOWN;
            break;
        case VM_PEN_EVENT_RELEASE:
            eventType = MMI_PEN_EVENT_UP;
            break;
        case VM_PEN_EVENT_MOVE:
            eventType = MMI_PEN_EVENT_MOVE;
            break;
        case VM_PEN_EVENT_LONG_TAP:
            eventType = MMI_PEN_EVENT_LONG_TAP;
            break;
        case VM_PEN_EVENT_DOUBLE_CLICK:
            eventType = MMI_PEN_EVENT_DOUBLE_CLICK;
            break;
        case VM_PEN_EVENT_REPEAT:
            eventType = MMI_PEN_EVENT_REPEAT;
            break;
        case VM_PEN_EVENT_ABORT:
            eventType = MMI_PEN_EVENT_ABORT;
            break;
        default:
            break;
    }
    if (vm_editor_get_active_editor() && wgui_editor_process_pen(pos, eventType))
    {
        return 1;
    }
#endif

#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    if (VM_PEN_EVENT_TAP == vmPenEvent && y < MMI_status_bar_height)
    {
        should_show_ncenter = 1;
    }
    else if (VM_PEN_EVENT_RELEASE == vmPenEvent)
    {
        should_show_ncenter = 0;
    }
    if(wgui_status_icon_bar_is_display(WGUI_STATUS_ICON_BAR_H_BAR)&&VM_PEN_EVENT_MOVE == vmPenEvent)
    {
        if(y > MMI_status_bar_height && should_show_ncenter)
        {
            vapp_ncenter_entry(NULL);
            should_show_ncenter = 0;
        }
    }
#endif

#ifdef __MRE_CORE_SM__
    while(pcb!=NULL && pcb->penHander== NULL)
    {
        pcb = pcb->next_pcb;
    }
#endif    
    if ((pcb)&&(pcb->penHander))
	{
	    _vm_sb_stack_push(pcb->r9);
		if (!(pcb->event_filter) || !(pcb->event_filter->pen_event_filter)
			|| pcb->event_filter->pen_event_filter(vmPenEvent, x, y))
		{
#ifdef __MRE_CORE_SM__
			_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_PCB_EVENT_FILTER, (VMINT)pcb);

			if (sm_ptr && sm_ptr->event_filter->pen_event_filter)
			{
				_vm_sb_stack_push(sm_ptr->r9);
				resend = sm_ptr->event_filter->pen_event_filter(vmPenEvent, x, y);
				_vm_sb_stack_pop();
				vm_log_debug("[SM] Pen event[] filtered by SM[%d]", sm_ptr->handle);
			}
#endif
		if(resend)
		{
			if (pcb->is_support_all_pen_and_key_event)
			{
				pcb->penHander(vmPenEvent, x, y);
                _vm_sb_stack_pop();                
 
				return 1;
			}
			else
			{
                if (vmPenEvent != VM_PEN_EVENT_LONG_TAP 
                    && vmPenEvent != VM_PEN_EVENT_DOUBLE_CLICK
                    && vmPenEvent != VM_PEN_EVENT_REPEAT)
                {
                    pcb->penHander(vmPenEvent, x, y);
                    _vm_sb_stack_pop();
                                      
                    return 1;
                }
            }
        }
#ifdef __MRE_CORE_SM__
    }
#endif
        _vm_sb_stack_pop();
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_flush_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_flush_screen(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t *pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &status)) != NULL && status == VM_PMNG_FOREGROUND)
	{
		if (pcb->sysEventHandler)
		{
			_vm_sb_stack_push(pcb->r9);
			pcb->sysEventHandler(VM_MSG_PAINT, 0);
			_vm_sb_stack_pop();
		}
	}
}


mmi_ret vm_pmng_deal_orientation_event(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_auto_rotate_evt_struct *evt = (mmi_frm_auto_rotate_evt_struct*)param;
    _vm_pcb_t *pcb = NULL, *tmp = NULL;
	vm_screen_rotate_enum rotate = VM_SCREEN_ROTATE_0;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mre_running)
        return MMI_RET_OK;
        
    switch (evt->new_degree)
    {
    case MMI_FRM_SCREEN_ROTATE_0:
        rotate = VM_SCREEN_ROTATE_0;
        break;
    case MMI_FRM_SCREEN_ROTATE_90:
        rotate = VM_SCREEN_ROTATE_90;
        break;
    case MMI_FRM_SCREEN_ROTATE_180:
        rotate = VM_SCREEN_ROTATE_180;
        break;
    case MMI_FRM_SCREEN_ROTATE_270:
        rotate = VM_SCREEN_ROTATE_270;
        break;
    }
	
	for (tmp = pcb_table[VM_PMNG_FOREGROUND]; tmp != NULL; tmp = pcb)
	{
		pcb = tmp->next_pcb;	
		_vm_pmng_send_sysevt_msg(tmp, VM_MSG_SCREEN_ROTATE, rotate);			
	}

    return MMI_RET_OK;
}



/* vmproevt.h */


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_deal_card_plug_out_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  exitProcessNum      [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMUINT vm_pmng_deal_card_plug_out_event(VMUINT* exitProcessNum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT num = 0, existNum = 0;
    VM_PROCESS_STATUS i = VM_PMNG_UNLOAD;
    _vm_pcb_t *pcb = NULL, *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = VM_PMNG_FOREGROUND, num = 0, existNum = 0; i < VM_PMNG_MAX_NUM; i++)
    {
        for (tmp = pcb_table[i]; tmp != NULL; tmp = pcb)
        {
            pcb = tmp->next_pcb;
            
            if (tmp->isReDriver)
			{
                vm_pmng_delete_process_int(tmp,i,VM_QUIT_CARD_PLUG_OUT);

                num++;
            }
            else
            {
                _vm_pmng_send_sysevt_msg(tmp, VM_MSG_CARD_PLUG_OUT, 0);
                existNum++;
            }
        }
    }	

    if (exitProcessNum)
    {
        *exitProcessNum = num;
    }    
    vm_get_tag_deinit(0);
    return existNum;
}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_exec_msg_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sender          [IN]        
 *  receiver        [IN]        
 *  msg_id          [IN]        
 *  wparam          [IN]        
 *  lparam          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_exec_msg_proc(VM_P_HANDLE sender, VM_P_HANDLE receiver, VMUINT msg_id, VMINT wparam, VMINT lparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* receiver_pcb = NULL;
    VM_PROCESS_STATUS receiver_status = VM_PMNG_UNLOAD;
    VMINT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_MSG_PROC,sender, receiver, msg_id);
    if ((receiver_pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, receiver, &receiver_status)) != NULL 
        && (receiver_status != VM_PMNG_UNLOAD)
        && (receiver_pcb->message_proc))
    {
	    _vm_sb_stack_push(receiver_pcb->r9);
        ret = receiver_pcb->message_proc(sender, msg_id, wparam, lparam);
        _vm_sb_stack_pop();
        
    }
#ifdef __MRE_CORE_SM__
	else
	{
		_vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE, receiver);
		
		if (sm_ptr && sm_ptr->message_proc)	
	    {
	    	_vm_sb_stack_push(sm_ptr->r9);
        	ret = sm_ptr->message_proc(sender, msg_id, wparam, lparam);
        	_vm_sb_stack_pop();
		}
	}
#endif
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  vm_pmng_exec_sysevent_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phandle     [IN]        
 *  msg_id      [IN]        
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_exec_sysevent_handler(VM_P_HANDLE phandle, VMUINT msg_id, VMINT param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t* pcb = NULL;
    VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    VMINT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_SYS_HANDLE,phandle, msg_id, param);
            
    if (msg_id == VM_MSG_QUIT)
    {
        /* if quit, just clean memory */
        vm_cleanup_unload_status_pcb();
        {
            VMINT exit = TRUE;
            VMINT i = 0;
            
            
            for (i = VM_PMNG_FOREGROUND, exit = TRUE; i < VM_PMNG_MAX_NUM; i++)
            {
                if (pcb_table[i] != NULL)
                {
                    exit = FALSE;
                    break;
                }
            }
        
            if (exit && (!vm_vam_is_in_use()))
            {
                vm_stop_mre_envirment();
            }
        }
		return ret;
	}
    else if (VM_MSG_RESTART_PARENT == msg_id)
    {
        VMINT exec_ret;
        
        if (!mre_running)
        {
            vm_start_mre_envirment(NULL,0);
        }
        
        exec_ret = vm_execute((VMWSTR)param,NULL);
        
        MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G8_PRO,"[MRE][PRO]VM_MSG_RESTART_PARENT path=%s,ret=%d", 
            param, exec_ret);
            
        _vm_kernel_free((void*)param);
        return 0;
    }
    
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, 
        phandle, &status)) != NULL && status != VM_PMNG_UNLOAD)
	{
	    
		_vm_sb_stack_push(pcb->r9);

        switch (msg_id)
        {
            case VM_MSG_CREATE:
                /* used for starting application async */
                if (!(pcb->event_filter) || !(pcb->event_filter->sys_event_filter) 
                    || pcb->event_filter->sys_event_filter(VM_MSG_CREATE, 0))
                {
                    pcb->sysEventHandler(VM_MSG_CREATE, 0);
                }
                break;
            case VM_MSG_PAINT:
                /* used for starting application async */
                if (!(pcb->event_filter) || !(pcb->event_filter->sys_event_filter) 
                    || pcb->event_filter->sys_event_filter(VM_MSG_PAINT, 0))
                {
                    pcb->sysEventHandler(VM_MSG_PAINT, 0);                    
                }
                pcb->isInited = 1;
                /* callback the start application success callback */
                vm_start_app_success_cb();
                break;

            default:
                /* used for starting application async */
                if (!(pcb->event_filter) || !(pcb->event_filter->sys_event_filter) 
                    || pcb->event_filter->sys_event_filter(VM_MSG_PAINT, 0))
                {
                    pcb->sysEventHandler(msg_id, 0);                    
                }
                /* callback the start application success callback */				
                break;
        }
        _vm_sb_stack_pop();
        
    }
    else
    {
        vm_start_app_success_cb();
        ret = 0;
    }

    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_is_fg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_is_fg(VM_P_HANDLE p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

        /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (p_handle == VM_PMNG_CUR_HANDLE)
    {
        p_handle = vm_pmng_get_current_handle();
    }
    
        if (pcb_table[VM_PMNG_FOREGROUND] 
            && pcb_table[VM_PMNG_FOREGROUND]->pHandle == p_handle)
        {
            return TRUE;
        }
#ifdef __MRE_CORE_SM__
        else
        {
            /* Find SM copy by R9 */
        _vm_sm_t * sm_ptr = _vm_sm_list_find(SM_FIND_BY_HANDLE, p_handle);
            if (sm_ptr && sm_ptr->pcb==pcb_table[VM_PMNG_FOREGROUND])
            {
                return TRUE;
            }
        }
#endif


    return FALSE;
}

static VM_P_HANDLE vm_pmng_set_fg_int(_vm_pcb_t* pcb, VM_PROCESS_STATUS status)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t *pcb2 = NULL;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_SET_FG,pcb->pHandle, status);
            
	vm_frm_entry_app_screen(pcb->pHandle);		
//	pcb->event = USER_EVENT;

	pcb2 = pcb_table[VM_PMNG_FOREGROUND];
	if (pcb2)
	{
		vm_pmng_set_bg_int(pcb2,VM_PMNG_FOREGROUND);
	}				

	ASSERT(NULL == pcb_table[VM_PMNG_FOREGROUND]);
	
	vm_push_pcb_into_status_union(VM_PMNG_FOREGROUND, 
		vm_pop_pcb_up_status_union(status, pcb->pHandle));
	
	vm_pmng_notify_res_data(pcb,VM_PMNG_FOREGROUND);
	if (pcb->sysEventHandler)
	{
		if (!(pcb->is_support_bg_run))
		{
			_vm_pmng_send_sysevt_msg(pcb, VM_MSG_ACTIVE, 0);
		}

        if (vm_pmng_get_push_app_flag())
		{
			_vm_pmng_send_sysevt_msg(pcb,VM_MSG_PUSH,vm_pmng_get_push_app_index());
		}
		_vm_pmng_send_sysevt_msg(pcb, VM_MSG_PAINT, 0);
	}
   	
    /* send hide message to N-Center */
    if (pcb->is_support_bg_run)
    {
        vm_send_msg(0, VM_MSG_PAINT, (VMINT)pcb->fullFileName, 0);
    }
    
	return pcb->pHandle;
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_fg
 * DESCRIPTION
 *  bring an application from bg to fg
 * PARAMETERS
 *  fileName        [IN]        
 *  filename(?)     [IN]        Application file name encoding with USC2 format.
 * RETURNS
 *  start app result.
 *****************************************************************************/
VM_P_HANDLE vm_pmng_set_fg(VMWSTR fileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    _vm_pcb_t *pcb = NULL;
    VM_PROCESS_STATUS processStatus = VM_PMNG_UNLOAD;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (NULL == fileName)
	{
		return VM_PMNG_ERROR_PARAM;
	}
    
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)fileName, &processStatus)) != NULL)
    {   
    	switch (processStatus)
    	{
    	case VM_PMNG_FOREGROUND:
    		return pcb->pHandle;
		case VM_PMNG_BACKGROUND:
		case VM_PMNG_INACTIVE:
			return vm_pmng_set_fg_int(pcb,processStatus);
		default:
			return VM_PMNG_NO_SCHEDULE;
    	} 
    }
    else
    {
        return VM_PMNG_NO_SCHEDULE;
    }

}

VM_P_HANDLE vm_pmng_set_fg_ex(VM_P_HANDLE pHandle)
{
	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	_vm_pcb_t* pcb = NULL;
	VM_PROCESS_STATUS processStatus = VM_PMNG_UNLOAD;
 
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	if (NULL == pHandle)
	{
		return NULL;
	}
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, (VMINT)pHandle, &processStatus)) != NULL)
	{	
	
		switch (processStatus)
    	{
    	case VM_PMNG_FOREGROUND:
    		return pcb->pHandle;
		case VM_PMNG_BACKGROUND:
		case VM_PMNG_INACTIVE:
			return vm_pmng_set_fg_int(pcb,processStatus);
		default:
			return VM_PMNG_NO_SCHEDULE;
    	} 
	}
	else
	{
		return VM_PMNG_NO_SCHEDULE;
	}
}

static VMINT vm_pmng_can_set_bg(_vm_pcb_t* pcb)
{
	VMUINT bgmem;
	VMBOOL inlist;
	_vm_pcb_t *ipcb;
	vm_so_node_t *so;
	void *ptr;

#if (defined (__COSMOS_MMI_PACKAGE__) && defined (J2ME_SUPPORT_BACKGROUND) \
&& defined (__GADGET_SUPPORT__) && !defined (__VM_CONCURRENCE__))||(defined(LOW_COST_SUPPORT)\
&&defined (J2ME_SUPPORT_BACKGROUND)&& !defined (__VM_CONCURRENCE__))
  if (jam_mvm_get_bg_running_count() > 0) {
  	return 0;
  }
#endif

	if (MRE_SYS_BGMEM_SIZE == -1) {		
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_ALWAYS_CAN_ENTER_BG);
		return 1;
	}
	
	if (MRE_SYS_BGMEM_SIZE == 0) {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_ALWAYS_CANNOT_ENTER_BG);
		return 0;
	}	
	
	bgmem = 0;
	inlist = 0;
	for (ipcb = pcb_table[VM_PMNG_BACKGROUND]; ipcb != NULL; ipcb = ipcb->next_pcb) {
        ptr = (void *)(ipcb->codeBase ? ipcb->codeBase : ipcb->heapBase);
		bgmem += vm_get_pool_size_from_ptr(ptr);
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_SET_BG_APP_MEM_SIZE, ipcb->pHandle, bgmem);
		for (so = ipcb->soHeader; so != NULL; so = so->next) {
            ptr = (void *)(so->codeBase ? so->codeBase : so->heapBase);
			bgmem += vm_get_pool_size_from_ptr(ptr);
			MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_SET_BG_SO_MEM_SIZE, so->memIndex, bgmem);
		}
	
		if (ipcb == pcb) {
			inlist = 1;
		}
	}

	if (!inlist) {
		ptr = (void *)(pcb->codeBase ? pcb->codeBase : pcb->heapBase);
		bgmem += vm_get_pool_size_from_ptr(ptr);
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_SET_BG_APP_MEM_SIZE, pcb->pHandle, bgmem);
		for (so = pcb->soHeader; so != NULL; so = so->next) {
            ptr = (void *)(so->codeBase ? so->codeBase : so->heapBase);
			bgmem += vm_get_pool_size_from_ptr(ptr);
			MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_SET_BG_SO_MEM_SIZE, so->memIndex, bgmem);
		}
	}
	
	bgmem += _vm_sm_get_total_memsize();
	MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_SET_BG_VSM_MEM_SIZE, bgmem);
	
	if (bgmem > (MRE_SYS_BGMEM_SIZE)) {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_CANNOT_ENTER_BG, bgmem, (MRE_SYS_BGMEM_SIZE));
		return 0;
	}
	else {
		MMI_TRACE(MMI_MRE_TRC_G8_PRO, TRC_MRE_PRO_CAN_ENTER_BG, bgmem, (MRE_SYS_BGMEM_SIZE));
		return 1;
	}
}

static VMINT vm_pmng_set_bg_int(_vm_pcb_t* pcb, VM_PROCESS_STATUS status)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
    
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_SET_BG,pcb->pHandle, status);
            

    if (pcb->is_support_bg_run)
    {
	    vm_push_pcb_into_status_union(VM_PMNG_BACKGROUND, 
            vm_pop_pcb_up_status_union(status, pcb->pHandle));

        /* send hide message to N-Center */
        if (pcb->is_support_bg_run)
        {
            vm_send_msg(0, VM_MSG_HIDE, (VMINT)pcb->fullFileName, 0);
        }
        
        _vm_pmng_send_sysevt_msg(pcb, VM_MSG_HIDE, 0);

        vm_log_debug("[Process Module]process = %d in %d status.", pcb->pHandle, VM_PMNG_BACKGROUND);
        vm_pmng_notify_res_data(pcb,VM_PMNG_BACKGROUND);        

        vm_frm_exit_app_screen(pcb->pHandle);
        
        if (!vm_pmng_can_set_bg(pcb)) 
	    {
	          /* notify AM to show popup */
            vm_send_msg(0,VM_MSG_CONFIRM_EXIT,0,0);
            vm_pmng_delete_process_int(pcb,VM_PMNG_BACKGROUND,1);
        }
    }
    else
    { 
		vm_pmng_delete_process_int(pcb,status,1);
    }      
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_set_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_set_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS processStatus = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;
    VMINT currAppR9 = vm_get_running_app_sb();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_R9, currAppR9, &processStatus)) != NULL
        && (VM_PMNG_FOREGROUND == processStatus || VM_PMNG_INACTIVE == processStatus))
    {
        return vm_pmng_set_bg_int(pcb,processStatus);
    }
	else if (VM_PMNG_BACKGROUND == processStatus)
	{
		return 0;
	}
    return VM_PMNG_NO_OP_IN_STATUS;
}

VMINT vm_pmng_set_bg_ex(VM_P_HANDLE pHandle)
{
	_vm_pcb_t* pcb = NULL;
	VM_PROCESS_STATUS processStatus = VM_PMNG_UNLOAD;
	
	if (NULL == pHandle)
	{
		return 0;
	}
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, (VMINT)pHandle, &processStatus)) != NULL
        && (VM_PMNG_FOREGROUND == processStatus || VM_PMNG_INACTIVE == processStatus))
    {
        return vm_pmng_set_bg_int(pcb,processStatus);
    }
	else if (VM_PMNG_BACKGROUND == processStatus)
	{
		return 0;
	}
    return VM_PMNG_NO_OP_IN_STATUS;
}

VMINT vm_pmng_set_inactive(VM_P_HANDLE pHandle)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                    */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcb = NULL;
	VM_PROCESS_STATUS processStatus = VM_PMNG_UNLOAD;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_SET_INACTIVE,pHandle);
            
    if (!mre_running)
        return 0;

	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, (VMINT)pHandle, &processStatus)) != NULL
				&& VM_PMNG_FOREGROUND == processStatus)
	{
        vm_push_pcb_into_status_union(VM_PMNG_INACTIVE, 
            vm_pop_pcb_up_status_union(VM_PMNG_FOREGROUND, pcb->pHandle));


        if (pcb->is_support_bg_run)
        {
            vm_sysevt_param_t param;
            //is it usefull ?? YES!
            param.evt_cause = SCREEN_POPUP;
            _vm_pmng_send_sysevt_msg(pcb, VM_MSG_HIDE, (VMINT)&param);
        }
        else
        {
            _vm_pmng_send_sysevt_msg(pcb, VM_MSG_INACTIVE, 0);
        }
        
        vm_pmng_notify_res_data(pcb,VM_PMNG_INACTIVE);	
        
        /* send hide message to N-Center */
/*        if (pcb->is_support_bg_run)
        {
            vm_send_msg(0, VM_MSG_HIDE, (VMINT)pcb->fullFileName, 0);
        }*/

    }
    return VM_PMNG_NO_OP_IN_STATUS;
}

/*****************************************************************************
 * FUNCTION
 *  vm_pmng_delete_process_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_handle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_pmng_delete_process_int(_vm_pcb_t* pcb, VM_PROCESS_STATUS status, VMINT param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT exit,i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G8_PRO,TRC_MRE_PRO_DELETE,pcb->pHandle,status,param);
            
    if (VM_PMNG_CLOSING == status || VM_PMNG_UNLOAD == status)
    {
        return VM_PMNG_OP_OK;
    }
    
    vm_push_pcb_into_status_union(VM_PMNG_CLOSING, 
        vm_pop_pcb_up_status_union(status, pcb->pHandle));
        
    vm_pmng_notify_res_data(pcb,VM_PMNG_CLOSING);	
        
    if (vm_get_running_app_sb() != pcb->r9)
    {
        _vm_pmng_send_sysevt_msg(pcb, VM_MSG_QUIT, param);
    }     

    vm_push_pcb_into_status_union(VM_PMNG_UNLOAD, 
        vm_pop_pcb_up_status_union(VM_PMNG_CLOSING, pcb->pHandle));
        
    vm_pmng_notify_res_data(pcb,VM_PMNG_UNLOAD);	
	
#ifdef __MRE_CORE_SM__
    /* Unload SMs invoked by PCB */
    _vm_sm_unload_by_pcb(pcb);
#endif

    /* send hide message to N-Center */
    if (pcb->is_support_bg_run)
    {
        vm_send_msg(0, VM_MSG_QUIT, (VMINT)pcb->fullFileName, 0);
    }

    if (vm_get_running_app_sb() == pcb->r9)
    {
        /* if delete process from MRE Application, clean up applicaiton memory async */
        vm_post_msg(pcb->pHandle,VM_MSG_QUIT,0,0);
        return VM_PMNG_OP_OK;
    }
    else
    {
        vm_cleanup_unload_status_pcb(); 
    }
 	
        
    for (i = VM_PMNG_FOREGROUND, exit = TRUE; i < VM_PMNG_MAX_NUM; i++)
    {
        if (pcb_table[i] != NULL)
        {
            exit = FALSE;
            break;
        }
    }
    
    if (exit && (!vm_vam_is_in_use()))
    {
        vm_stop_mre_envirment();
    }

    return VM_PMNG_OP_OK;
}

_vm_pcb_t* vm_pmng_get_pcb_by_status(VM_PROCESS_STATUS status)
{
	return pcb_table[status];
}

void vm_pmng_stop_envirment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT exit = TRUE, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   for (i = VM_PMNG_FOREGROUND, exit = TRUE; i < VM_PMNG_MAX_NUM; i++)
   {
      if (pcb_table[i] != NULL)
      {
         exit = FALSE;
         break;
      }
   }
        
   if (exit && (!vm_vam_is_in_use()))
   {
       vm_stop_mre_envirment();
   }

}

VMBOOL vm_pmng_is_support_screen(VM_P_HANDLE phandle)
{
	VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
	_vm_pcb_t* pcb = NULL;
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, phandle, &status)) != NULL)
	{
		return !pcb->isNoScreen;
	}

	return VM_TRUE;
}

_vm_pcb_t* _vm_get_pcb_by_phandle(VM_P_HANDLE phandle)
{
	VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
	_vm_pcb_t* pcb = NULL;
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, phandle, &status)) != NULL)
	{
		return pcb;
	}
	else
	{
		return NULL;
	}
}

static void vm_pmng_notify_res_data(_vm_pcb_t* pcb, VMINT process_state)
{
    _vm_sb_stack_push(pcb->r9);
    vm_res_notify_data_by_process(pcb->pHandle, process_state);
    _vm_sb_stack_pop();
}

static void vm_native_launch_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
	return;
}

/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_native_load_library_ex(VMWSTR name, VMUINT flags)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mre_launch_app_result_enum result = SRV_MRE_LAUNCH_APP_SUCCESS;
	VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M00");
	result = srv_mre_launch_app((VMUWSTR)name, vm_native_launch_cb);

	if (result != SRV_MRE_LAUNCH_APP_SUCCESS)
	{
            MRE_SWLA_STOP("M00");
	    return 0;
	}
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)name, &status)) == NULL) 
	{
            MRE_SWLA_STOP("M00");
	    return 0;
	}
		
    if (flags) 
    {
        if (flags & VM_LOAD_HIDE_IN_OOM) 
        {
            VMINT i;
            
            for (i=0; i<MRE_SUPPORT_MAX_APP_NUM; i++)
            {
                if (g_app_mem_info[i].p_handle == pcb->pHandle)
                {
                    applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_MRE_APP0+i, KAL_TRUE); 
                    break;
                }
            }
        }
        // more flags handling
    }
    MRE_SWLA_STOP("M00");
    return pcb->pHandle;
}


/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library_with_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_native_load_library_with_callback(VMWSTR name, VMUINT flags, vm_launch_app_cb_t app_cb)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mre_launch_app_result_enum result = SRV_MRE_LAUNCH_APP_SUCCESS;
	VM_PROCESS_STATUS status = VM_PMNG_UNLOAD;
    _vm_pcb_t* pcb = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M09");

	if(app_cb == NULL)
		return 0;
	
	result = srv_mre_launch_app((VMUWSTR)name, (srv_mre_launch_app_cb_t)app_cb);

	if (result != SRV_MRE_LAUNCH_APP_SUCCESS)
	{
            MRE_SWLA_STOP("M09");
	    return 0;
	}
	
	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)name, &status)) == NULL) 
	{
            MRE_SWLA_STOP("M09");
	    return 0;
	}
		
    if (flags) 
    {
        if (flags & VM_LOAD_HIDE_IN_OOM) 
        {
            VMINT i;
            
            for (i=0; i<MRE_SUPPORT_MAX_APP_NUM; i++)
            {
                if (g_app_mem_info[i].p_handle == pcb->pHandle)
                {
                    applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_MRE_APP0+i, KAL_TRUE); 
                    break;
                }
            }
        }
        // more flags handling
    }
    MRE_SWLA_STOP("M09");
    return pcb->pHandle;
}


/*****************************************************************************
 * FUNCTION
 *  vm_native_load_library
 * DESCRIPTION
 *  
 * PARAMETERS
 *  VMINT
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_native_load_library(VMWSTR name)
{
    return vm_native_load_library_ex(name, 0);
}


static void vm_native_preload_callback(VMUWSTR fileName, VAM_START_MRE_EVT evt)
{
}


VMINT vm_native_preload_library(vm_preload_app_info_t *preload_info)
{
    _vm_pcb_t *pcb;
    VM_PROCESS_STATUS status;
    VMINT ret;
    
    mre_running = TRUE;
    ret = vm_execute_preload_app(preload_info, vm_native_preload_callback); 
    if (ret != VM_EXECUTE_APP_SUCCESS)
    {
        if (vm_pmng_current_counter()<=0)
        {
            mre_running = FALSE;
        }
        return 0;
    }

    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)preload_info->fullFileName, &status)) == NULL) 
    {
        if (vm_pmng_current_counter()<=0)
        {
            mre_running = FALSE;
        }
        return 0;
    }

    return pcb->pHandle;
}


VMINT vm_native_get_symbol(VMINT handle, VMSTR name)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	_vm_pcb_t* pcb;
	VMINT address = 0;
			   
	/*----------------------------------------------------------------*/
	/* Code Body 													 */
	/*----------------------------------------------------------------*/
	pcb = _vm_get_pcb_by_phandle(handle);

	if ((pcb)&&(pcb->sysGetFuncHandler))
	{

	   _vm_sb_stack_push(pcb->r9);
	   address = pcb->sysGetFuncHandler(name);
	   _vm_sb_stack_pop();
	}
	else
	{
	   vm_log_error("get function error");
	}
	return address;
}


VMINT vm_native_free_library(VMINT handle)
{
	return vm_pmng_delete_process(handle);
}

VMINT vm_pmng_get_process_list(VM_P_HANDLE *handle_list, VMUINT *num)
{
    VMUINT index = 0, i;
    _vm_pcb_t* pcb = NULL;
    
    if (NULL == num)
    {
        return -2;
    }
    
    if (NULL == handle_list)
    {
        *num = vm_pmng_current_counter();
        return *num;
    }

    for (i = VM_PMNG_FOREGROUND; i < VM_PMNG_MAX_NUM, index < *num; i++)
    {        
        for (pcb = pcb_table[i]; pcb, index < *num; pcb = pcb->next_pcb)
        {
            handle_list[index] = pcb->pHandle;
            index ++;
        }
    }

    return index;
}

VMINT vm_pmng_get_process_property(VM_P_HANDLE handle, vm_process_property *property)
{
    VMINT i;
    _vm_pcb_t* pcb = NULL;

    if (NULL == property)
    {
        return -2;
    }
    
    for (i = VM_PMNG_FOREGROUND; i < VM_PMNG_MAX_NUM; i++)
    {        
        for (pcb = pcb_table[i]; pcb; pcb = pcb->next_pcb)
        {
            if (handle == pcb->pHandle)
            {
                property->pHandle = handle;
                property->appID = pcb->app_id;
                property->status = i;
                if (pcb->father_pcb)
                {
                    property->pParentHandle = pcb->father_pcb->pHandle;
                }
                else
                {
                    property->pParentHandle = NULL;
                }
                // TODO: type
                kal_wstrcpy(property->filePath,pcb->fullFileName);
                return 0;
            }
        }
    }

    
    return -3;
}

VMINT vm_send_system_message(VM_P_HANDLE handle,VMINT msg, VMINT param)
{
    _vm_pcb_t* pcb;
    VM_PROCESS_STATUS status;
    
    if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, (VMINT)handle, &status)) != NULL
        && status != VM_PMNG_UNLOAD) 
    {
        _vm_pmng_send_sysevt_msg(pcb, msg, param);
        return 0;
    }
    return -1;
}
#endif /* __MRE_CORE_BASE__ */

