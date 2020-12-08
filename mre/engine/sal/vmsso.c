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


#include "vmswitch.h"
#ifdef __MRE_SAL_SSO__

#include "vmsso.h"
#include "SSOSrvGprot.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmpromnginner.h"
#include "vmgettag.h"

#include "mmi_trc.h"

//#define FAKE
#ifdef FAKE

U8 srv_sso_get_provider_count(void)
{return 0;}
U8 srv_sso_get_providers(srv_sso_provider_struct *buffer, U8 buffer_items)
{return 0;}
MMI_BOOL srv_sso_get_provider(U32 provider, srv_sso_provider_struct *buffer)
{
    return 0;
}
WCHAR *srv_sso_get_provider_icon(U32 provider, srv_sso_icon_enum type)
{return 0;}
MMI_BOOL srv_sso_get_provider_name(U32 provider, WCHAR *buffer)
{return 0;}
U8 srv_sso_get_account_count(U32 provider, srv_sso_login_state login_state)
{return 0;}
U8 srv_sso_get_accounts(U32 provider, srv_sso_login_state login_state, srv_sso_account_struct *buffer, U8 buffer_items)
{return 0;}
MMI_BOOL srv_sso_get_account(U32 provider, U8 account, srv_sso_account_struct *buffer)
{
    return 0;
}
MMI_BOOL srv_sso_get_account_name(U32 provider, U8 account, WCHAR *buffer)
{return 0;;}
MMI_BOOL srv_sso_get_credentials(U32 provider, U8 account, srv_sso_credential_struct *buffer)
{return 0;;}
S32 srv_sso_add_account(U32 provider, WCHAR *username, WCHAR *password, srv_sso_account_callback callback, void *user_data)
{return 0;;}
S32 srv_sso_login_account(U32 provider, U8 account, WCHAR *password, srv_sso_account_callback callback, void *user_data)
{return 0;;}
S32 srv_sso_logout_account(U32 provider, U8 account, srv_sso_result_callback callback, void *user_data)
{return 0;;}
S32 srv_sso_del_account(U32 provider, U8 account, srv_sso_result_callback callback, void *user_data)
{return 0;;}
S32 srv_sso_refresh_credentials(U32 provider, U8 account, srv_sso_result_callback callback, void *user_data)
{return 0;}

#endif

extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);


typedef struct 
{
    VM_P_HANDLE p_hdl;
    void * user_data;
    void * cb; // vm_sso_account_callback, vm_sso_result_callback
    S32 req_id;
} vm_sso_ctx_t;

static VMINT vm_is_mtk_cert(void)
{
    // MTK cert
    VMINT ret = 100;
    
#ifndef __MTK_INTERNAL__
    ret = vm_get_curr_app_cert_id();
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 15, __LINE__);
#endif

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 15, ret);
    if (100 == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 15, __LINE__);
        return 1;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 15, __LINE__);
        return 0;
    }
}

static void vm_sso_account_cb(S32 req_id, srv_sso_result result, U32 provider, U8 account, void *user_data)
{
    vm_sso_ctx_t * ctx_p = (vm_sso_ctx_t *)user_data;
    VM_PROCESS_STATUS status = 0;
    _vm_pcb_t * pcb;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 8801, __LINE__);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 8801, __LINE__);
        return;
    }
    
    pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, ctx_p->p_hdl, &status);
    if (NULL == pcb)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 8801, __LINE__);
        return;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        result,
        provider,
        account,
        ctx_p->p_hdl,
        ctx_p->cb,
        ctx_p->user_data,
        88010, __LINE__);
        
    if (ctx_p->cb)
    {
        PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
            (((vm_sso_account_callback)ctx_p->cb)((VMINT)req_id, (vm_sso_result)result, (VMUINT32)provider, (VMUINT8)account, ctx_p->user_data), 
            vm_free(ctx_p)));
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        result,
        provider,
        account,
        status,
        ctx_p->cb,
        ctx_p->user_data,
        88011, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 8801, __LINE__);
}

static void vm_sso_result_cb(S32 req_id, srv_sso_result result, void *user_data)
{
    vm_sso_ctx_t * ctx_p = (vm_sso_ctx_t *)user_data;
    VM_PROCESS_STATUS status = 0;
    _vm_pcb_t * pcb;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 8802, __LINE__);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 8802, __LINE__);
        return;
    }
    
    pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, ctx_p->p_hdl, &status);
    if (NULL == pcb)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 8802, __LINE__);
        return;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        result,
        0,
        0,
        status,
        ctx_p->cb,
        ctx_p->user_data,
        88021, __LINE__);
        
    if (ctx_p->cb)
    {
        PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
            (((vm_sso_result_callback)ctx_p->cb)((VMINT)req_id, (vm_sso_result)result, ctx_p->user_data),
            vm_free(ctx_p)));
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        result,
        0,
        0,
        status,
        ctx_p->cb,
        ctx_p->user_data,
        88022, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 8802, __LINE__);
}



VMINT vm_sso_get_provider_count(void)
{
    VMINT ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 1, __LINE__);

    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 1, __LINE__);
        return -7;
    }
    
    ret = (VMINT)srv_sso_get_provider_count();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        ret,
        0,
        0,
        0,
        0,
        0,
        1, __LINE__);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 1, __LINE__);
    return ret;
}

VMINT vm_sso_get_providers(vm_sso_provider_struct * buffer, VMUINT8 buffer_items)
{
    VMINT ret = 0;
    srv_sso_provider_struct * prov_int;
    VMINT i = 0;
    U8 num = 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 2, __LINE__);
    
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 2, __LINE__);
        return -7;
    }

    if (NULL == buffer || 0 == buffer_items)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 2, __LINE__);
        return -2;
    }



    prov_int = (srv_sso_provider_struct *)vm_calloc(sizeof(srv_sso_provider_struct) * buffer_items);
    if (NULL == prov_int)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 2, __LINE__);
        return -3;
    }
    
    num = srv_sso_get_providers(prov_int, (U8)buffer_items);

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        num,
        buffer_items,
        0,
        0,
        0,
        prov_int,
        20, __LINE__);
        
    if (0 == num)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E4, 2, __LINE__);
        vm_free(prov_int);
        return 0;
    }

    for (i = 0; i < ((num > buffer_items) ? buffer_items : num); i++)
    {
        vm_sso_provider_struct * buf_tmp = &buffer[i];
        srv_sso_provider_struct * prov_int_tmp = &prov_int[i];
        buf_tmp->accounts_loggedin = prov_int_tmp->accounts_loggedin;
        buf_tmp->accounts_total = prov_int_tmp->accounts_total;
        buf_tmp->provider = prov_int_tmp->provider;

        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
            num,
            buffer_items,
            buf_tmp->accounts_loggedin,
            buf_tmp->provider,
            buf_tmp->accounts_total,
            0,
            21, __LINE__);
    }
    
    vm_free(prov_int);

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 2, __LINE__);
    return (VMINT)num;
}

VMINT vm_sso_get_provider(VMUINT32 provider, vm_sso_provider_struct * buffer)
{
    MMI_BOOL ret;
    srv_sso_provider_struct buffer_int;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 13, __LINE__);
    
    if (NULL == buffer)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 13, __LINE__);
        return -2;
    }
    
    ret = srv_sso_get_provider((U32)provider, &buffer_int);
    if (MMI_FALSE == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 13, __LINE__);
        return -8;
    }

    buffer->accounts_loggedin = (VMUINT8)buffer_int.accounts_loggedin;
    buffer->accounts_total = (VMUINT8)buffer_int.accounts_total;
    buffer->provider = (VMUINT32)buffer_int.provider;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        buffer->accounts_loggedin,
        buffer->accounts_total,
        buffer->provider,
        0,
        0,
        131, __LINE__);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 13, __LINE__);

    return 0;
}

VMINT vm_sso_get_provider_icon(VMUINT32 provider, vm_sso_icon_enum type, VMWCHAR ** icon_path)
{
    MMI_BOOL ret = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 3, __LINE__);
    
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 3, __LINE__);
        return -7;
    }

    if (NULL != icon_path ||
        (VM_SSO_ICON_LARGE > type ||
        VM_SSO_ICON_TOTAL <= type))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 3, __LINE__);
        return -2;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        type,
        0,
        0,
        0,
        0,
        3, __LINE__);
    
    *icon_path = srv_sso_get_provider_icon((U32)provider, (srv_sso_icon_enum)type);
    if (NULL == *icon_path)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 3, __LINE__);
        return -3;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 3, __LINE__);
    return 0;
}

VMINT vm_sso_get_provider_name(VMUINT32 provider, VMWCHAR * buffer)
{
    MMI_BOOL ret = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 4, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 4, __LINE__);
        return -7;
    }

    if (NULL == buffer)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 4, __LINE__);
        return -2;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        0,
        0,
        0,
        0,
        0,
        4, __LINE__);

    ret = srv_sso_get_provider_name((U32)provider, (WCHAR *)buffer);
    if (MMI_FALSE == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 4, __LINE__);
        return -8;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 4, __LINE__);
    return 0;
}

VMINT vm_sso_get_account_count(VMUINT32 provider, vm_sso_login_state login_state)
{
    VMINT ret = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 5, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 5, __LINE__);
        return -7;
    }

    if (VM_SSO_LOGIN_DONT_CARE > login_state ||
        VM_SSO_LOGIN_TOTAL <= login_state)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 5, __LINE__);
        return -2;
    }

    ret = (VMINT)srv_sso_get_account_count((U32)provider, (srv_sso_login_state)login_state);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        login_state,
        ret,
        0,
        0,
        0,
        5, __LINE__);
    
    return ret;
}

VMINT vm_sso_get_accounts(VMUINT32 provider, vm_sso_login_state login_state, vm_sso_account_struct * buffer, VMUINT8 buffer_items)
{
    VMINT ret = 0;
    srv_sso_account_struct * acc_int;
    U8 num = 0;
    VMINT i = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 6, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 6, __LINE__);
        return -7;
    }


    if (VM_SSO_LOGIN_DONT_CARE > login_state ||
        VM_SSO_LOGIN_TOTAL <= login_state ||
        NULL == buffer|| 0 == buffer_items)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 6, __LINE__);
        return -2;
    }

    acc_int = (srv_sso_account_struct *)vm_calloc(sizeof(srv_sso_account_struct) * buffer_items);
    if (NULL == acc_int)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 6, __LINE__);
        return -3;
    }


    num = srv_sso_get_accounts((U32)provider, (srv_sso_login_state)login_state, acc_int, buffer_items);

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        login_state,
        buffer_items,
        num,
        0,
        0,
        60, __LINE__);    
        
    if (0 == num)
    {
        vm_free(acc_int);
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E4, 6, __LINE__);
        return 0;
    }

    for (i = 0; i < ((num > buffer_items) ? buffer_items : num); i++)
    {
        vm_sso_account_struct * buf_tmp = &buffer[i];
        srv_sso_account_struct * acc_int_tmp = &acc_int[i];
        buf_tmp->is_login = (VMUINT8)acc_int_tmp->is_login;
        buf_tmp->account = (VMUINT8)acc_int_tmp->account;
        buf_tmp->provider = (VMUINT32)acc_int_tmp->provider;
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
            num,
            buffer_items,
            buf_tmp->account,
            buf_tmp->provider,
            buf_tmp->is_login,
            0,
            61, __LINE__);
    }
    
    vm_free(acc_int);

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 6, __LINE__);
    
    return (VMINT)num;
    
}

VMINT vm_sso_get_account(VMUINT32 provider, VMUINT8 account, vm_sso_account_struct * buffer)
{
    MMI_BOOL ret;
    srv_sso_account_struct account_int;
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 14, __LINE__);

    if (NULL == buffer)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 14, __LINE__);
        return -2;
    }

    ret = srv_sso_get_account((U32)provider, (U8)account, &account_int);
    if (MMI_FALSE == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 14, __LINE__);
        return -8;
    }

    buffer->account = (VMUINT8)account_int.account;
    buffer->is_login = (VMUINT8)account_int.is_login;
    buffer->provider = (VMUINT32)account_int.provider;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        buffer->account,
        buffer->is_login,
        buffer->provider,
        0,
        141, __LINE__);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 14, __LINE__);

    return 0;
}

VMINT vm_sso_get_account_name(VMUINT32 provider, VMUINT8 account, VMWCHAR * buffer)
{
    MMI_BOOL ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 7, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 7, __LINE__);
        return -7;
    }

    if (NULL == buffer)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 7, __LINE__);
        return -2;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        0,
        0,
        0,
        0,
        7, __LINE__);
        
    ret = srv_sso_get_account_name((U32)provider, (U8)account, (WCHAR *)buffer);
    if (MMI_FALSE == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 7, __LINE__);
        return -8;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 7, __LINE__);
    return 0;
}

VMINT vm_sso_get_credentials(VMUINT32 provider, VMUINT8 account, vm_sso_credential_struct * buffer)
{
    MMI_BOOL ret = 0;
    srv_sso_credential_struct cre_int = {0};

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 8, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 8, __LINE__);
        return -7;
    }

    if (NULL == buffer)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 8, __LINE__);
        return -2;
    }

    ret = srv_sso_get_credentials((U32)provider, (U8)account, &cre_int);
    if (MMI_FALSE == ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 8, __LINE__);
        return -8;
    }
    
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        cre_int.type,
        0,
        0,
        0,
        8, __LINE__);

    switch (cre_int.type)
    {
    case SRV_SSO_CREDENTIAL_OAUTH:
        {
            memcpy(buffer->value.oauth.access_token, cre_int.value.oauth.access_token, VM_SSO_ACCESS_TOKEN);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.oauth.access_token);
            //buffer->value.oauth.created_ts = cre_int.value.oauth.created_ts;
            //buffer->value.oauth.expires_in = cre_int.value.oauth.expires_in;
            memcpy(buffer->value.oauth.refresh_token, cre_int.value.oauth.refresh_token, VM_SSO_REFRESH_TOKEN);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.oauth.refresh_token);
            memcpy(buffer->value.oauth.scope, cre_int.value.oauth.scope, VM_SSO_SCOPE);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.oauth.scope);
            memcpy(buffer->value.oauth.extension, cre_int.value.oauth.extension, VM_SSO_EXTENSION);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.oauth.extension);
        }break;
    case SRV_SSO_CREDENTIAL_USERPASS:
        {
            memcpy(buffer->value.userpass.username, cre_int.value.userpass.username, VM_SSO_NAME_SIZE);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.userpass.username);
            memcpy(buffer->value.userpass.password, cre_int.value.userpass.password, VM_SSO_NAME_SIZE);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.userpass.password);
        }break;
    case SRV_SSO_CREDENTIAL_YAHOO:
        {
            memcpy(buffer->value.yahoo.security_token, cre_int.value.yahoo.security_token, VM_SSO_ACCESS_TOKEN);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.yahoo.security_token);
            //buffer->value.yahoo.created_ts = cre_int.value.yahoo.created_ts;
            //buffer->value.yahoo.expires_in = cre_int.value.yahoo.expires_in;
            //memcpy(buffer->value.yahoo.refresh_token, cre_int.value.yahoo.refresh_token, VM_SSO_REFRESH_TOKEN);
            //memcpy(buffer->value.yahoo.scope, cre_int.value.yahoo.scope, VM_SSO_SCOPE);
            memcpy(buffer->value.yahoo.ycookie, cre_int.value.yahoo.ycookie, VM_SSO_EXT_YAHOO_COOKIE);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.yahoo.ycookie);
            memcpy(buffer->value.yahoo.tcookie, cre_int.value.yahoo.tcookie, VM_SSO_EXT_YAHOO_COOKIE);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.yahoo.tcookie);
            memcpy(buffer->value.yahoo.crumb, cre_int.value.yahoo.crumb, VM_SSO_EXT_YAHOO_CRUMB);
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_SSO, "[SSO][%s]", buffer->value.yahoo.crumb);
        }break;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 8, __LINE__);
    return 0;
}

VMINT vm_sso_add_account(VMUINT32 provider, const VMWCHAR * username, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data)
{
    S32 ret = 0;
    vm_sso_ctx_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 9, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 9, __LINE__);
        return -7;
    }


    ctx_p = (vm_sso_ctx_t *)vm_calloc(sizeof(vm_sso_ctx_t));

    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 9, __LINE__);
        return -3;
    }

    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;
    ctx_p->cb = (void *)callback;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        ctx_p->p_hdl,
        0,
        0,
        ctx_p->user_data,
        ctx_p->cb,
        8, __LINE__);
        
    ret = srv_sso_add_account((U32)provider, (WCHAR *)username, (WCHAR *)password, vm_sso_account_cb, (void *)ctx_p);

    if (SRV_SSO_OK > ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 9, __LINE__);
        return -8;
    }

    ctx_p->req_id = ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 9, ctx_p->req_id);
    return ret;
}

VMINT vm_sso_login_account(VMUINT32 provider, VMUINT8 account, const VMWCHAR * password, vm_sso_account_callback callback, void * user_data)
{
    S32 ret = 0;
    vm_sso_ctx_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 9, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 9, __LINE__);
        return -7;
    }

    ctx_p = (vm_sso_ctx_t *)vm_calloc(sizeof(vm_sso_ctx_t));

    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 9, __LINE__);
        return -3;
    }

    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;
    ctx_p->cb = (void *)callback;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        ctx_p->p_hdl,
        0,
        ctx_p->user_data,
        ctx_p->cb,
        9, __LINE__);

    ret = srv_sso_login_account((U32)provider, (U8)account, (WCHAR *)password, vm_sso_account_cb, (void *)ctx_p);
    if (SRV_SSO_OK > ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 9, __LINE__);
        return -8;
    }
    
    ctx_p->req_id = ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 9, ctx_p->req_id);
    return ret;
}

VMINT vm_sso_logout_account(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    S32 ret = 0;
    vm_sso_ctx_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 10, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 10, __LINE__);
        return -7;
    }

    ctx_p = (vm_sso_ctx_t *)vm_calloc(sizeof(vm_sso_ctx_t));
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 10, __LINE__);
        return -3;
    }

    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;
    ctx_p->cb = (void *)callback;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        ctx_p->p_hdl,
        0,
        ctx_p->user_data,
        ctx_p->cb,
        10, __LINE__);
        
    ret = srv_sso_logout_account((U32)provider, (U8)account, vm_sso_result_cb, (void *)ctx_p);
    if (SRV_SSO_OK > ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 10, __LINE__);
        return -8;
    }

    ctx_p->req_id = ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 10, ctx_p->req_id);
    return ret;
}

VMINT vm_sso_del_account(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    S32 ret = 0;
    vm_sso_ctx_t * ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 11, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 11, __LINE__);
        return -7;
    }

    ctx_p = (vm_sso_ctx_t *)vm_calloc(sizeof(vm_sso_ctx_t));
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 11, __LINE__);
        return -3;
    }

    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;
    ctx_p->cb = (void *)callback;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        ctx_p->p_hdl,
        0,
        ctx_p->user_data,
        ctx_p->cb,
        11, __LINE__);
        
    ret = srv_sso_del_account((U32)provider, (U8)account, vm_sso_result_cb, (void *)ctx_p);
    if (SRV_SSO_OK > ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 11, __LINE__);
        return -8;
    }

    ctx_p->req_id = ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 11, ctx_p->req_id);
    return ret;
}

VMINT vm_sso_refresh_credentials(VMUINT32 provider, VMUINT8 account, vm_sso_result_callback callback, void * user_data)
{
    S32 ret = 0;
    vm_sso_ctx_t * ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 12, __LINE__);
    if (!vm_is_mtk_cert())
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E1, 12, __LINE__);
        return -7;
    }
    
    ctx_p = (vm_sso_ctx_t *)vm_calloc(sizeof(vm_sso_ctx_t));
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E2, 12, __LINE__);
        return -3;
    }
    
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;
    ctx_p->cb = (void *)callback;

    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_LOG, 
        provider,
        account,
        ctx_p->p_hdl,
        0,
        ctx_p->user_data,
        ctx_p->cb,
        12, __LINE__);
        
    ret = srv_sso_refresh_credentials((U32)provider, (U8)account, vm_sso_result_cb, (void *)ctx_p);
    if (SRV_SSO_OK > ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E3, 12, __LINE__);
        return -8;
    }
    
    ctx_p->req_id = ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 12, ctx_p->req_id);
    return ret;
}

VMINT vm_sso_cancel(VMINT req_id)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_S, 16, __LINE__);
    srv_sso_cancel((S32)req_id);
    MMI_TRACE(MMI_MRE_TRC_MOD_SSO, TRC_MRE_SSO_E, 16, req_id);
    return 0;
}

#endif /* __MRE_SAL_SSO__ */

