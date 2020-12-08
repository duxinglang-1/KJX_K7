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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"
#include "SppSrvGprot.h"

#include "vmswitch.h"
#ifdef __MRE_SAL_BTSPP__

#include "vmbtspp.h"
#include "vmbtcm.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"

#define MAX_MRE_SPP_CLIENT 4

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
    VMINT conn_id[MAX_MRE_SPP_CLIENT];
    VMINT is_connected;
    void (*cb)(VMUINT evt, void * param, void * user_data);
    void * user_data;
}vm_btspp_context_t;

static void vm_btspp_free_ctx(vm_btspp_context_t * ctx_p);
static vm_btspp_context_t * vm_btspp_malloc_ctx(void);
static vm_btspp_context_t * vm_btspp_get_ctx(VMINT id, VMINT type);
static vm_btspp_context_t * vm_btspp_get_ctx_by_shd(VMUINT srv_hd);
static vm_btspp_context_t * vm_btspp_get_ctx_by_cid(VMINT conn_id);
static VMINT vm_btspp_conn_id_slot(vm_btspp_context_t * ctx_p, VMINT conn_id);
static S32 vm_btspp_notifier_cb(U32 evt, void* para);

static void vm_btspp_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btspp_context_t * ctx_p = NULL;
    
    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_BTSPP)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTSPP, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            vm_btspp_close(ctx_p->srv_hd);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_132 );
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_136 );
        }
        vm_res_release_data(VM_RES_TYPE_BTSPP, resHandle);
        vm_res_findclose(VM_RES_TYPE_BTSPP); 
    }

}


static void vm_btspp_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btspp_context_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_121 );
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_btspp_free_resource(process_handle);
        break;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_143 );
}


static VMINT vm_btspp_initialize_resource(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_149 );
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_BTSPP, 
        vm_btspp_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_157 );


    return 0;
}

static VMINT vm_btspp_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btspp_context_t* ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_168 );
    vm_btspp_free_resource(-1);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTSPP, NULL);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_188 );


    return 0;
}

static VMINT vm_btspp_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_btspp_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_btspp_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_210 , event);
        return -2;
    }

    return 0;
}

VMINT _vm_reg_btspp_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_221 );
    if ((res_code = _vm_reg_module("BTSPP MODULE", (MOD_EVT_PROCESS)vm_btspp_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_224 , res_code);
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_227 );
    return res_code;
}

static vm_btspp_context_t * vm_btspp_get_ctx(VMINT id, VMINT type)
{
    
    VMINT resHandle = 0, bufSize = 0;
    vm_btspp_context_t * ctx_p = NULL;
    VMINT i = 0;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_BTSPP)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTSPP, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (0 == type)
            {
                if (ctx_p->srv_hd == id)
                {
                    vm_res_findclose(VM_RES_TYPE_BTSPP);
                    return ctx_p;
                }
            }
            else if (1 == type)
            {
                if (-1 == id)
                    return NULL;
                for (i = 0; i < MAX_MRE_SPP_CLIENT; i++)
                {
                    if (ctx_p->conn_id[i] == id)
                    {
                        vm_res_findclose(VM_RES_TYPE_BTSPP);
                        return ctx_p;
                    }
                }
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_BTSPP)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTSPP, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (0 == type)
                {
                    if (ctx_p->srv_hd == id)
                    {
                        vm_res_findclose(VM_RES_TYPE_BTSPP);
                        return ctx_p;
                    }
                }
                else if (1 == type)
                {
                    for (i = 0; i < MAX_MRE_SPP_CLIENT; i++)
                    {
                        if (ctx_p->conn_id[i] == id)
                        {
                            vm_res_findclose(VM_RES_TYPE_BTSPP);
                            return ctx_p;
                        }
                    }
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_BTSPP);
    }	
    return NULL;
}

static vm_btspp_context_t * vm_btspp_malloc_ctx(void)
{
    vm_btspp_context_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_btspp_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_BTSPP, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            VMINT i = 0;
            for (i = 0; i < MAX_MRE_SPP_CLIENT; i++)
            {
                ctx_p->conn_id[i] = -1;
            }
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

static void vm_btspp_free_ctx(vm_btspp_context_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_BTSPP, ctx_p->res_id);
        _vm_kernel_free(ctx_p);
    }
}

static VMINT vm_btspp_conn_id_slot(vm_btspp_context_t * ctx_p, VMINT conn_id)
{
    VMINT i = 0;
    VMINT found = 0;
    VMINT idx = -1;
    VMINT slot = -1;
    
    ASSERT(ctx_p && -1 != conn_id);
    
    for (i = 0; i < MAX_MRE_SPP_CLIENT; i++)
    {
        // get an empty slot
        if ((-1 == slot) && (-1 == ctx_p->conn_id[i]))
        {
            slot = i;
        }
        // exist conn id
        if (ctx_p->conn_id[i] == conn_id)
        {
            found = 1;
            idx = i;
            break;
        }
    }

    if (0 == found)
    {
        idx = slot;
    }

    return idx;
}


static S32 vm_btspp_notifier_cb(U32 evt, void* para)
{
    VMINT srv_hd = 0;
    vm_btspp_context_t * ctx_p = NULL;
    VM_P_HANDLE p_handle = 0;
    void * user_data = NULL;
    srv_spp_event_cntx * protocol_data = NULL;
    VMINT idx = 0;
    vm_srv_spp_event_cntx data; 
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_339 , evt);

    if (NULL == para)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_343 );
        return MMI_RET_DONT_CARE;
    }

    protocol_data = (srv_spp_event_cntx *)para;

    srv_hd = (VMINT)protocol_data->user_data;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_351 , srv_hd);
    
    ctx_p = vm_btspp_get_ctx(srv_hd, 0);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_356 );
        return MMI_RET_DONT_CARE;
    }
    
    p_handle = vm_res_get_process_handle(VM_RES_TYPE_BTSPP, ctx_p->res_id);
    if (0 > p_handle)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_363 );
        return MMI_RET_DONT_CARE;
    }


    if ((VM_SRV_SPP_EVENT_CONNECT == evt || VM_SRV_SPP_EVENT_SCO_CONNECT == evt) &&
        0 == protocol_data->ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
            evt,
            0, 
            111, __LINE__ );
    }
    else
    {
        idx = vm_btspp_conn_id_slot(ctx_p, (VMINT)protocol_data->para);
        if (-1 >= idx || idx >= MAX_MRE_SPP_CLIENT)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
                evt,
                protocol_data->para, 
                112, __LINE__ );
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_E1, 11, __LINE__);
            return MMI_RET_DONT_CARE;
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
            idx,
            protocol_data->para, 
            113, __LINE__ );
        ctx_p->conn_id[idx] = (VMINT)protocol_data->para;
    }

    
    data.conn_id = ctx_p->conn_id[idx];
    data.res_hd = ctx_p->res_id;
    data.ret = protocol_data->ret;
    data.user_data = ctx_p->user_data;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_385 , 
                                idx, srv_hd, data.user_data, data.ret, data.conn_id);
    
    PMNG_WRAP_CALLBACK(p_handle, ctx_p->cb(evt, (void *)&data, data.user_data));

    if (VM_SRV_SPP_EVENT_CONNECT == evt || 
        VM_SRV_SPP_EVENT_SCO_CONNECT == evt)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_369 );
        ctx_p->is_connected = (~0);
    }
    else if (VM_SRV_SPP_EVENT_DISCONNECT == evt || 
        VM_SRV_SPP_EVENT_SCO_DISCONNECT == evt)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_375 );
        ctx_p->is_connected = (0);
        ctx_p->conn_id[idx] = -1;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_390 );

    return MMI_RET_OK;

    
}

VMINT vm_btspp_get_min_buf_size(void)
{
    vm_trace("[BTSPP] vm_btspp_get_min_buf_size S");
    return SRV_SPP_MIN_BUFF_SIZE;
}

VMINT vm_btspp_open(VMUINT evt_mask, 
                    void (*callback)(VMUINT evt, void * param, void * user_data), 
                    void * user_data)
{
    vm_btspp_context_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_403 );
    
    if (NULL == callback ||(0 == evt_mask))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_407 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    ctx_p = vm_btspp_malloc_ctx();

    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_415 );
        return VM_BT_SPP_ERR_NO_RESOURCE;
    }

    ctx_p->srv_hd = srv_spp_open();
    //ctx_p->conn_id = -1;
    ctx_p->is_connected = 0;
    
    if (SRV_SPP_INVALID_HANDLE == ctx_p->srv_hd)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_425 );
        return VM_BT_SPP_ERR_LOGICAL;
    }

    ctx_p->cb = callback;
    ctx_p->user_data = user_data;
    
    srv_spp_set_notify_hdlr((SppHandle)ctx_p->srv_hd, (U32)evt_mask, (btSppNotify)vm_btspp_notifier_cb, (void*)ctx_p->srv_hd);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_434 );

    return ctx_p->res_id;
    
}

VMINT vm_btspp_close(VMINT res_hd)
{
    
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_446 );
    
    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_451 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    if (ctx_p->is_connected)
    {
        VMINT i = 0;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_457 );
        for (i = 0; i < MAX_MRE_SPP_CLIENT; i++)
        {
            if (-1 != ctx_p->conn_id[i])
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
                    ctx_p->conn_id[i],
                    0, 
                    2, __LINE__ );
                vm_btspp_disconnect(ctx_p->conn_id[i]);
            }
        }
    }

    srv_spp_close(ctx_p->srv_hd);

    // srv_spp_reset_notify_hdlr 
    
    vm_btspp_free_ctx(ctx_p);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_467 );
    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_disconnect(VMINT conn_id)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_475 );

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_480 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }
    
    srv_spp_disconnect((S32)conn_id);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_486 );

    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_write(VMUINT conn_id, void * buf, VMUINT size)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_495 );

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
        conn_id,
        size, 
        3, __LINE__ );

    if (NULL == buf || 0 == size)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_499 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_506 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    return (VMINT)srv_spp_write((U32)conn_id, buf, (U32)size);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_512 );
    
}

VMINT vm_btspp_read(VMUINT conn_id, void * buf, VMUINT size)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_520 );

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_LOG, 
    conn_id,
    size, 
    4, __LINE__ );
    
    if (NULL == buf || 0 == size)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_524 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_531 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    return (VMINT)srv_spp_read((U32)conn_id, buf, (U32)size);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_537 );
}

VMINT vm_btspp_get_dev_addr(VMINT conn_id, vm_srv_bt_cm_bt_addr * bt_addr)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_544 );

    if (NULL == bt_addr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_548 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_555 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_get_dev_addr((U32)conn_id, (srv_bt_cm_bt_addr *)bt_addr);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_561 );

    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_set_security_level(VMINT res_hd, VMINT level)
{
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_571 );

    // TODO:
/*
    if (0 == level)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_577 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }
*/
    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_584 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }
    
    srv_spp_set_security_level((SppHandle)ctx_p->srv_hd, (SppSecurityLevel)level);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_590 );

    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_set_service_name(VMINT res_hd, VMWCHAR * name)
{
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_600 );

    if (NULL == name)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_604 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_611 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_set_service_name((SppHandle)ctx_p->srv_hd, (WCHAR *)name);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_617 );

    return VM_BT_SPP_ERR_SUCCESS;
}

/* SPP SERVER USING START*/
VMINT vm_btspp_bind(VMINT res_hd, VMUINT16 uuid)
{
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_628 );

    // TODO:
    /*
    if (0 == uuid)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_634 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }
    */
    
    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_642 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_bind((SppHandle)ctx_p->srv_hd, (U32)uuid);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_648 );

    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_accept(VMINT conn_id,
						void * buf, 
						VMUINT tx_size,
						VMUINT rx_size
						)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_661 );

    if (NULL == buf || 0 == tx_size || 0 == rx_size)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_665 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_672 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_accept((S32)conn_id, buf, (U32)tx_size, (U32)rx_size);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_678 );

    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_reject(VMINT conn_id)
{
    vm_btspp_context_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_687 );

    ctx_p = vm_btspp_get_ctx(conn_id, 1);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_692 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_reject((S32)conn_id);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_698 );

    return VM_BT_SPP_ERR_SUCCESS;
}
/* SPP SERVER USING END */


/* SPP CLIENT USING START */
VMINT vm_btspp_connect(VMINT res_hd,
					const vm_srv_bt_cm_bt_addr * bt_addr,
					void * buf,
					VMUINT tx_size,
					VMUINT rx_size,
					VMUINT16 uuid)
{
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_716 );

    if (NULL == bt_addr || 
        NULL == buf ||
        (SRV_SPP_MIN_BUFF_SIZE / 2) < tx_size ||
        (SRV_SPP_MIN_BUFF_SIZE / 2) < rx_size)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_723 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_730 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    
    
    srv_spp_connect((SppHandle)ctx_p->srv_hd, (U32)uuid, (srv_bt_cm_bt_addr *)bt_addr, buf, (U32)tx_size, (U32)rx_size);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_738 );
    return VM_BT_SPP_ERR_SUCCESS;
}

VMINT vm_btspp_connect_ex(VMINT res_hd, 
						const vm_srv_bt_cm_bt_addr * bt_addr,
						void * buf,
						VMUINT tx_size,
						VMUINT rx_size,
						vm_srv_spp_connect_type conn_type, 
						VMUINT16 uuid)
{
    vm_btspp_context_t * ctx_p = NULL;
    VMINT buf_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_753 );

    if (NULL == bt_addr || 
        NULL == buf ||
        (SRV_SPP_MIN_BUFF_SIZE / 2) < tx_size ||
        (SRV_SPP_MIN_BUFF_SIZE / 2) < rx_size)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_760 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    if ((0 != vm_res_get_data(VM_RES_TYPE_BTSPP, 
        res_hd, (void**)&ctx_p, &buf_size)) || NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_767 );
        return VM_BT_SPP_ERR_BAD_PARAM;
    }

    srv_spp_connect_ex((SppHandle)ctx_p->srv_hd, (U32)uuid, (srv_bt_cm_bt_addr *)bt_addr, buf, (U32)tx_size, (U32)rx_size, (srv_spp_connect_type)conn_type);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_773 );
    return VM_BT_SPP_ERR_SUCCESS;
}

#else
#include "vmsys.h"
#include "mmi_trc.h"
VMINT vm_btspp_open(VMUINT evt_mask, 
                    void (*callback)(VMUINT evt, void * param, void * user_data), 
                    void * user_data)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_783 );
    return -2;
}
#endif /* __MRE_SAL_BTSPP__ */

