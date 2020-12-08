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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"
#include "BtcmSrvGprot.h"

#include "vmswitch.h"
#ifdef __MRE_SAL_BTCM__

#include "vmbtcm.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"

extern void _vm_trace(char* fmt, ...);

#ifdef WIN32
#define vm_trace _vm_trace
#else
#define vm_trace(...) _vm_trace(__VA_ARGS__)
#endif


typedef struct
{
    VMINT srv_hd;
    VMINT res_id;
    void (*cb)(VMUINT evt, void * param, void * user_data);
}vm_btcm_context_t;

static void vm_btcm_free_ctx(vm_btcm_context_t * ctx_p);
static vm_btcm_context_t * vm_btcm_malloc_ctx(void);
static vm_btcm_context_t * vm_btcm_get_ctx(VMUINT srv_hd);
static void vm_btcm_notifier_cb(U32 event, void* para);

static void vm_btcm_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btcm_context_t * ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_BTCM)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTCM, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            vm_btcm_exit(ctx_p->res_id);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_117 );
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_121 );
        }
        vm_res_release_data(VM_RES_TYPE_BTCM, resHandle);
        vm_res_findclose(VM_RES_TYPE_BTCM); 
    }

}

static void vm_btcm_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_106 );
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_btcm_free_resource(process_handle);
        break;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_128 );
}


static VMINT vm_btcm_initialize_resource(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_134 );
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_BTCM, 
        vm_btcm_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_142 );


    return 0;
}

static VMINT vm_btcm_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btcm_context_t* ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_153 );
    vm_btcm_free_resource(-1);

    
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTCM, NULL);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_174 );
    ///TODO: Deregister WPS relate functions

    return 0;
}

static VMINT vm_btcm_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_btcm_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_btcm_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_196 , event);
        return -2;
    }

    return 0;
}

VMINT _vm_reg_btcm_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_207 );
    if ((res_code = _vm_reg_module("BTCM MODULE", (MOD_EVT_PROCESS)vm_btcm_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_210 , res_code);
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_213 );
    return res_code;
}

static vm_btcm_context_t * vm_btcm_get_ctx(VMUINT srv_hd)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btcm_context_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_BTCM)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTCM, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->srv_hd == srv_hd)
            {
                vm_res_findclose(VM_RES_TYPE_BTCM);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_BTCM)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTCM, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->srv_hd == srv_hd)
                {
                    vm_res_findclose(VM_RES_TYPE_BTCM);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_BTCM);
    }	
    return NULL;
}


static vm_btcm_context_t * vm_btcm_malloc_ctx(void)
{
    vm_btcm_context_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_btcm_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_BTCM, 
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

static void vm_btcm_free_ctx(vm_btcm_context_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_BTCM, ctx_p->res_id);
        _vm_kernel_free(ctx_p);
    }
}

static void vm_btcm_notifier_cb(U32 event, void* para)
{
    VMINT srv_hd = 0;
    vm_btcm_context_t * ctx_p = NULL;
    void * user_data = NULL;
    VM_P_HANDLE p_handle = 0;

    if (NULL == para)
    {
        return;
    }
    
    srv_hd = *(VMINT *)para;
    user_data = *(void **)((VMINT *)para + 1);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_295 , srv_hd, user_data);
    
    ctx_p = vm_btcm_get_ctx(srv_hd);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_300 );
        return;
    }
    
    p_handle = vm_res_get_process_handle(VM_RES_TYPE_BTCM, ctx_p->res_id);
    if (0 > p_handle)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_309 );
        return;
    }

    *(VMINT *)para = ctx_p->res_id;
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_314 , p_handle, event, para, user_data);
    PMNG_WRAP_CALLBACK(p_handle, ctx_p->cb(event, para, user_data));
    //vm_trace("[BTCM] vm_btcm_notifier_cb srv_hd[%d]", srv_hd);
	*(VMINT *)para = srv_hd;
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
    #endif
    
}

VMINT vm_btcm_init(void (*callback)(VMUINT evt, void * param, void * user_data), 
                   VMUINT evt_mask, 
                   void * user_data)
{
    vm_btcm_context_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_360 );
    
    if (NULL == callback || (0 == evt_mask))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_364 );
        return VM_BT_CM_ERR_BAD_PARAM;
    }

    ctx_p = vm_btcm_malloc_ctx();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_371 );
        return VM_BT_CM_ERR_NO_RESOURCE;
    }
    
    ctx_p->srv_hd = srv_bt_cm_set_notify(vm_btcm_notifier_cb, evt_mask, user_data);
    if (0 > ctx_p->srv_hd)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_378 , ctx_p->srv_hd);
        vm_btcm_free_ctx(ctx_p);
        return VM_BT_CM_ERR_LOGICAL;
    }

	ctx_p->cb = callback;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_384 );

    return ctx_p->res_id;
}

VMINT vm_btcm_exit(VMINT res_hd)
{
    vm_btcm_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_394 );
    
    //ctx_p = vm_btcm_get_ctx(res_hd);
    if (0 == vm_res_get_data(VM_RES_TYPE_BTCM, 
        res_hd, (void**)&ctx_p, &buf_size) == 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_400 );
        return VM_BT_CM_ERR_BAD_PARAM;
    }
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_406 );
        return VM_BT_CM_ERR_BAD_PARAM;
    }
    if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_reset_notify(ctx_p->srv_hd))
    {    
        //memset(&ctx_p, 0, sizeof(vm_btcm_context_t));
    }

    vm_btcm_free_ctx(ctx_p);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_416 );

    return VM_BT_CM_ERR_SUCCESS;
    
}

VMINT vm_btcm_get_power_status(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_424 );
    
    return (VMINT)srv_bt_cm_get_power_status();
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_428 );
}

VMINT vm_btcm_switch_on(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_433 );
    
    return (VMINT)srv_bt_cm_switch_on();

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_437 );
}

VMINT vm_btcm_switch_off(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_442 );

    srv_bt_cm_switch_off();
    return 0;
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_447 );
}

VMINT vm_btcm_srv_set_visibility(vm_srv_bt_cm_visibility_type type)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_452 );
    
    return (VMINT)srv_bt_cm_set_visibility((srv_bt_cm_visibility_type)type);
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_456 );
}

VMINT vm_btcm_srv_get_visibility(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_461 );

    return (VMINT)srv_bt_cm_get_visibility();
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_465 );
}

VMINT vm_btcm_search(VMUINT8 max_response, VMUINT16 time_out, VMUINT cod, VMBYTE is_name_discovery)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_470 );

    

#ifdef __BT_AUTO_DETECT_SUPPORT__    
        if (!srv_bt_chip_available())
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_477 );
            return VM_BT_CM_ERR_NOT_SUPPORT;
        }
#endif

    return (VMINT)srv_bt_cm_search((U8)max_response, (U16)time_out, (U32)0XFFFFFFFF, (MMI_BOOL)is_name_discovery);

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_484 );
}

VMINT vm_btcm_search_abort(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_489 );
    
    return (VMINT)srv_bt_cm_search_abort();
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_493 );
}

VMINT vm_btcm_set_host_name(VMUINT8 * name)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_498 );
    if (NULL == name)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_501 );
        return SRV_BT_CM_RESULT_FAILED;
    }
    
    return (VMINT)srv_bt_cm_set_host_dev_name((U8*)name);
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_507 );
}

VMINT vm_btcm_get_host_dev_info(vm_srv_bt_cm_dev_struct * info)
{
    srv_bt_cm_dev_struct * info_int;
    vm_srv_bt_cm_bt_addr * dst;
    srv_bt_cm_bt_addr * src;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_513 );

    if (NULL == info)
    {        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_517 );
        return VM_BT_CM_ERR_BAD_PARAM;
    }
    
    info_int = srv_bt_cm_get_host_dev_info();
    if (NULL == info_int)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_524 );
        return VM_BT_CM_ERR_LOGICAL;
    }

    //memcpy(info, info_int, sizeof(srv_bt_cm_dev_struct));
    info->cod = info_int->cod;
    memcpy(info->name, info_int->name, VM_SRV_BT_CM_BD_FNAME_LEN);
    dst = &(info->bd_addr);
    src = &(info_int->bd_addr);
    dst->lap = (VMUINT)src->lap;
    dst->uap = (VMUINT8)src->uap;
    dst->nap = (VMUINT16)src->nap;
    info->attribute = (VMUINT8)info_int->attribute;
    info->service_list_num = (VMUINT8)info_int->service_list_num;
    memcpy(info->service_list, info_int->service_list, VM_SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_530 );

    return VM_BT_CM_ERR_SUCCESS;
}

VMINT vm_btcm_get_dev_num(vm_srv_bt_cm_dev_type_enum dev_type)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_537 );
    return (VMINT)srv_bt_cm_get_dev_num((srv_bt_cm_dev_type_enum)dev_type);
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_539 );
}

VMINT vm_btcm_get_dev_info_by_index(VMUINT idx, vm_srv_bt_cm_dev_type_enum dev_type, vm_srv_bt_cm_dev_struct * info)
{
    const srv_bt_cm_dev_struct * info_int = NULL;
    vm_srv_bt_cm_bt_addr * dst;
    const srv_bt_cm_bt_addr * src;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_546 );
    if (NULL == info)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_549 );
        return VM_BT_CM_ERR_BAD_PARAM;
    }
    
    info_int = srv_bt_cm_get_dev_info_by_index(idx, (srv_bt_cm_dev_type_enum)dev_type);
    if (NULL == info_int)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_556 );
        return VM_BT_CM_ERR_LOGICAL;
    }

    info->cod = info_int->cod;
    memcpy(info->name, info_int->name, VM_SRV_BT_CM_BD_FNAME_LEN);
    
    dst = &(info->bd_addr);
    src = &(info_int->bd_addr);
    dst->lap = (VMUINT)src->lap;
    dst->uap = (VMUINT8)src->uap;
    dst->nap = (VMUINT16)src->nap;
    info->attribute = (VMUINT8)info_int->attribute;
    info->service_list_num = (VMUINT8)info_int->service_list_num;
    memcpy(info->service_list, info_int->service_list, VM_SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_569 );
    return VM_BT_CM_ERR_SUCCESS;
}

VMINT vm_get_bt_sym(VMCHAR* func_name)
{
	return 0;
}

#else
#include "vmsys.h"
#include "mmi_trc.h"
VMINT vm_btcm_init(void (*callback)(VMUINT evt, void * param, void * user_data), 
                   VMUINT evt_mask, 
                   void * user_data)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_579 );
    return -2;
}

#endif /* __MRE_SAL_BTCM__ */

