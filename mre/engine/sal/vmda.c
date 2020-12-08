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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"


#include "vmswitch.h"
#ifdef __MRE_SAL_DA__
#include "vmsys.h"
#include "vmda.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmsock.h"
#include "wps_struct.h"
#include "DLAgentSrvGprot.h"
#include "MMI_trc.h"

typedef struct 
{
    VM_P_HANDLE phdl;
    VMINT res_id;
    VMUINT32 job_id;
    vm_srv_da_http_progress_funcptr_type da_pgs_cb;
    //srv_da_http_aborted_funcptr_type da_op_cb;
}vm_da_ctx_t;

static vm_da_ctx_t * _vm_da_malloc_ctx(void);
static void _vm_da_free_ctx(vm_da_ctx_t * ctx_p);
static vm_da_ctx_t * _vm_da_get_ctx(VMINT id, VMINT type);

static vm_da_ctx_t * _vm_da_get_ctx(VMINT id, VMINT type)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_da_ctx_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_DA)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_DA, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (0 == type)
            {
            if (ctx_p->job_id == (VMUINT)id)
            {
                vm_res_findclose(VM_RES_TYPE_DA);
                return ctx_p;
            }
            }
            else
            if (1 == type)
            {
                if (ctx_p->res_id == id)
                {
                    vm_res_findclose(VM_RES_TYPE_DA);
                    return ctx_p;
                }
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_DA)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_DA, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (0 == type)
                {
                if (ctx_p->job_id == (VMUINT)id)
                {
                    vm_res_findclose(VM_RES_TYPE_DA);
                    return ctx_p;
                }
                }
                else
                if (1 == type)
                {
                    if (ctx_p->res_id == id)
                    {
                        vm_res_findclose(VM_RES_TYPE_DA);
                        return ctx_p;
                    }
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_DA);
    }   
    return NULL;
}

static void vm_da_free_resource(VM_P_HANDLE process_handle)
{
    VMINT resHandle, bufSize;
    vm_da_ctx_t * ctx_p;
    while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_DA)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_DA, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            _vm_da_free_ctx(ctx_p);
        }
        vm_res_release_data(VM_RES_TYPE_DA, resHandle);
        vm_res_findclose(VM_RES_TYPE_DA);
    }

}


static void vm_da_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_da_ctx_t * ctx_p = NULL;

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_da_free_resource(process_handle);

        break;
    }
}


static VMINT vm_da_initialize_resource(void)
{
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_DA, 
        vm_da_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.


    return 0;
}

static VMINT vm_da_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_da_ctx_t* ctx_p = NULL;

    vm_da_free_resource(-1);

    vm_res_type_set_notify_callback(VM_RES_TYPE_DA, NULL);

    return 0;
}

static VMINT vm_da_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_da_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_da_finialize_resource();
        break;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    default:
        return -2;
    }

    return 0;
}

VMINT _vm_reg_da_module(void)
{
    //int res_code = REG_MRE_MODULE_SUCCESS;
    
    return _vm_reg_module("DLA", (MOD_EVT_PROCESS)vm_da_mod_evt_proc);
}

static vm_da_ctx_t * _vm_da_malloc_ctx(void)
{
    vm_da_ctx_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_da_ctx_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_DA, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

static void _vm_da_free_ctx(vm_da_ctx_t * ctx_p)
{
    if (NULL == ctx_p)
    {
        return;
    }
    
    vm_res_release_data(VM_RES_TYPE_DA, ctx_p->res_id);
    _vm_kernel_free(ctx_p);

}

static void vm_srv_da_http_progress_cb(srv_da_download_progress_struct * pgs)
{
    vm_da_ctx_t * ctx_p;
    vm_srv_da_download_progress_struct pgs_int;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_S, 3, __LINE__);
    ctx_p = _vm_da_get_ctx((VMINT)pgs->arg, 0);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E1, 3, __LINE__);
        return;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_LOG, 
        pgs->arg,
        pgs->status,
        pgs->curr_size,
        pgs->cause,
        pgs->user_data,
        pgs->total_size,
        3, __LINE__);

    pgs_int.hdl = ctx_p->res_id;
    pgs_int.status = (vm_wps_dl_status_enum)pgs->status;
    pgs_int.curr_size = pgs->curr_size;
    pgs_int.total_size = pgs->total_size;
    pgs_int.savepath = (VMWSTR)pgs->savepath;
    pgs_int.cause = (vm_wps_result_error_enum)pgs->cause;
    pgs_int.user_data = pgs->user_data;

    PMNG_WRAP_CALLBACK(ctx_p->phdl, 
        ctx_p->da_pgs_cb(&pgs_int));
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E, 3, __LINE__);

}

VMINT vm_da_http_start_download(vm_srv_da_start_download_struct * arg)
{
    vm_da_ctx_t * ctx_p;
    srv_da_start_download_struct da_info = {0};
    U32 job_id = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_S, 1, __LINE__);
    if (NULL == arg)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E1, 1, __LINE__);
        return -2;
    }

    if (VM_E_SOC_SUCCESS != vm_get_encoded_dtacct_id(arg->apn, &(da_info.acc_id)))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E2, 1, __LINE__);
        return -3;
    }

    ctx_p = _vm_da_malloc_ctx();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E3, 1, __LINE__);
        return -4;
    }

    da_info.url = (WCHAR *)arg->url;
    da_info.show_confirm = arg->show_confirm ? MMI_TRUE : MMI_FALSE;
    da_info.dl_progress = vm_srv_da_http_progress_cb;
    da_info.filepath = (U16*)arg->file_path;
    da_info.user_data = arg->user_data;
    //da_info.dl_operation = NULL;

    
    if (0 == (job_id = srv_da_start_http_download(&da_info)))
    {
        _vm_da_free_ctx(ctx_p);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E4, 1, __LINE__);
        return -5;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_LOG, 
        arg->show_confirm,
        arg->apn,
        ctx_p->res_id,
        job_id,
        arg->url,
        arg->dl_progress,
        1, __LINE__);


    
    ctx_p->phdl = vm_pmng_get_current_handle();
    ctx_p->da_pgs_cb = arg->dl_progress;
    //ctx_p->da_op_cb = da_info.dl_operation;
    ctx_p->job_id = (VMUINT32)job_id;
    //arg->dl_operation = vm_srv_da_http_op_cb;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E, 1, __LINE__);
    return ctx_p->res_id;    
}

VMINT vm_da_http_dl_operation(VMINT hdl, vm_srv_da_download_cause_enum cause)
{
    vm_da_ctx_t * ctx_p;
    ctx_p = _vm_da_get_ctx(hdl, 1);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_S, 2, __LINE__);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E1, 2, __LINE__);
        return -2;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_LOG, 
        hdl,
        ctx_p->job_id,
        cause,
        0,
        0,
        0,
        2, __LINE__);
        
    srv_da_http_dl_operation(ctx_p->job_id, (srv_da_download_cause_enum)cause);
    
    if (ctx_p)
    {
        _vm_da_free_ctx(ctx_p);
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E, 2, __LINE__);
    return 0;
}

VMINT vm_da_display_download_list(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_S, 3, __LINE__);
    srv_da_display_download_list();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDA, TRC_MRE_DA_E, 3, __LINE__);
    return 0;
}

#endif /* __MRE_SAL_DA__ */

