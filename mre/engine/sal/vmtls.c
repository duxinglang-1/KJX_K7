#include "mmi_features.h"


#include "vmswitch.h"
#ifdef __MRE_SAL_TLS__

#include "tls_api.h"
#include "MMIDataType.h"
#include "mmi_rp_app_mre_def.h"
#include "APPSDKFrameworkGProt.h"

#include "vmtls.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"


#define VM_TLS_RET_BASE (-200)

extern void _vm_trace(char* fmt, ...);

#ifdef WIN32
#define vm_trace _vm_trace
#else
#define vm_trace(...) _vm_trace(__VA_ARGS__)
#endif

typedef struct 
{
    kal_int32 tls_ctx;
    VMINT res_id;
    kal_int8 soc_id;
    VM_P_HANDLE p_hdl;
    callback_t cb;
}vm_tls_context_t;

static void vm_tls_free_ctx(vm_tls_context_t * ctx_p);
static vm_tls_context_t * vm_tls_malloc_ctx(void);
static vm_tls_context_t * vm_tls_get_ctx_by_tls(kal_int32 tls_ctx);
static vm_tls_context_t * vm_tls_get_ctx_by_soc(kal_int8 soc_id);
static vm_tls_context_t * vm_tls_get_ctx_by_res(VMINT res_id);
static MMI_BOOL vm_tls_notify_ind(void *msg);
static MMI_BOOL vm_tls_alert_ind(void *msg);
static MMI_BOOL vm_tls_invalid_cert_ind(void *msg);
static MMI_BOOL vm_tls_client_auth_ind(void *msg);

static void vm_tls_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_tls_context_t * ctx_p = NULL;

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_TLS)) 
            != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_TLS, 
                resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                // TODO:EXIT
                if (ctx_p->soc_id > 0)
                {
                    vm_tls_delete_conn(resHandle);
                    vm_tls_delete_ctx(resHandle);
                    soc_close(ctx_p->soc_id);
                    ctx_p->soc_id = 0;
                }
            }
            else
            {
            }
            vm_res_release_data(VM_RES_TYPE_TLS, resHandle);
            vm_res_findclose(VM_RES_TYPE_TLS); 
        }
        break;
    }
}


static VMINT vm_tls_initialize_resource(void)
{
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_TLS, 
        vm_tls_notify_process_status) != 0)
    {
        return -1;
    }



    return 0;
}

static VMINT vm_tls_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_tls_context_t* ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TLS)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            // TODO:EXIT
            if (ctx_p->soc_id > 0)
            {
                vm_tls_delete_conn(resHandle);
                vm_tls_delete_ctx(resHandle);
                soc_close(ctx_p->soc_id);
                ctx_p->soc_id = 0;
            }
        }
        else
        {
        }
        vm_res_release_data(VM_RES_TYPE_TLS, resHandle);
        vm_res_findclose(VM_RES_TYPE_TLS);
    }
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_TLS, NULL);


    return 0;
}

static VMINT vm_tls_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_tls_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_tls_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        return -2;
    }

    return 0;
}

VMINT _vm_reg_tls_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("TLS MODULE", (MOD_EVT_PROCESS)vm_tls_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}

static vm_tls_context_t * vm_tls_get_ctx_by_tls(kal_int32 tls_ctx)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_tls_context_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->tls_ctx == tls_ctx)
            {
                vm_res_findclose(VM_RES_TYPE_TLS);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->tls_ctx == tls_ctx)
                {
                    vm_res_findclose(VM_RES_TYPE_TLS);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_TLS);
    }	
    return NULL;
}

static vm_tls_context_t * vm_tls_get_ctx_by_soc(kal_int8 soc_id)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_tls_context_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->soc_id == soc_id)
            {
                vm_res_findclose(VM_RES_TYPE_TLS);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->soc_id == soc_id)
                {
                    vm_res_findclose(VM_RES_TYPE_TLS);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_TLS);
    }	
    return NULL;
}

static vm_tls_context_t * vm_tls_get_ctx_by_res(VMINT res_id)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_tls_context_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->res_id == res_id)
            {
                vm_res_findclose(VM_RES_TYPE_TLS);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_TLS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_TLS, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->res_id == res_id)
                {
                    vm_res_findclose(VM_RES_TYPE_TLS);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_TLS);
    }	
    return NULL;
}

static vm_tls_context_t * vm_tls_malloc_ctx(void)
{
    vm_tls_context_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_tls_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_TLS, 
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

static void vm_tls_free_ctx(vm_tls_context_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_TLS, ctx_p->res_id);
        _vm_kernel_free(ctx_p);
    }
}

static MMI_BOOL vm_tls_notify_cb(void *msg)
{
    app_soc_notify_ind_struct* ind = (app_soc_notify_ind_struct*)msg;
    vm_tls_context_t * ctx_p = NULL;

    vm_tls_soc_notify_ind_struct cb_data = {0};
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 26, __LINE__);
    if (NULL == ind)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 26, __LINE__);
        return MMI_FALSE;
    }

    ctx_p = vm_tls_get_ctx_by_soc(ind->socket_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 26, __LINE__);
        return MMI_FALSE;
    }

    
    cb_data.msg = VM_MSG_ID_APP_SOC_NOTIFY_IND;
    cb_data.res_id = ctx_p->res_id;
    cb_data.soc_id = ctx_p->soc_id;
    cb_data.event_type = (VMINT)ind->event_type;
    cb_data.result = (VMINT)ind->result;
    cb_data.error_cause = (VMINT)ind->error_cause;
    cb_data.detail_cause = (VMINT)ind->detail_cause;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        cb_data.res_id,
        cb_data.soc_id,
        cb_data.event_type,
        cb_data.result,
        cb_data.error_cause,
        cb_data.detail_cause,
        26, __LINE__);
    
    PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
        (ctx_p->cb)((vm_tls_event_struct*)&cb_data));
    
    switch (ind->event_type)
    {
    case SOC_WRITE:
        {}break;
    case SOC_READ:
        {}break;
    case SOC_CONNECT:
        {
            //tls_handshake(ind->socket_id);
        }break;
    case SOC_CLOSE:
        {}break;

    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 26, __LINE__);
    return MMI_TRUE;
}


static MMI_BOOL vm_tls_notify_ind(void *msg)
{
    app_tls_notify_ind_struct * ind = (app_tls_notify_ind_struct *)msg;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 22, __LINE__);
    if (NULL == ind)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 22, __LINE__);
        return MMI_FALSE;
    }

    ctx_p = vm_tls_get_ctx_by_soc(ind->sock_id);
    if (NULL != ctx_p)
    {
        vm_tls_notify_ind_struct cb_data = {0};
        cb_data.msg = VM_MSG_ID_APP_TLS_NOTIFY_IND;
        cb_data.res_id = ctx_p->res_id;
        cb_data.soc_id = ctx_p->soc_id;
        cb_data.detail_cause = ind->detail_cause;
        cb_data.error = ind->error;
        cb_data.event = ind->event;
        cb_data.result = ind->result;

        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
            cb_data.res_id,
            cb_data.soc_id,
            cb_data.detail_cause,
            cb_data.error,
            cb_data.event,
            cb_data.result,
            22, __LINE__);

        PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
            (ctx_p->cb)((vm_tls_event_struct*)&cb_data));
        
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 22, __LINE__);
        return MMI_TRUE;
    }

    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 22, __LINE__);

    return MMI_FALSE;
}

static MMI_BOOL vm_tls_alert_ind(void *msg)
{
    app_tls_alert_ind_struct * ind = (app_tls_alert_ind_struct *)msg;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 23, __LINE__);
    if (NULL == ind)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 23, __LINE__);
        return MMI_FALSE;
    }

    ctx_p = vm_tls_get_ctx_by_soc(ind->sock_id);
    if (NULL != ctx_p)
    {
        vm_tls_alert_ind_struct cb_data = {0};
        cb_data.msg = VM_MSG_ID_APP_TLS_ALERT_IND;
        cb_data.res_id = ctx_p->res_id;
        cb_data.soc_id = ctx_p->soc_id;
        cb_data.alert_level = ind->alert_level;
        cb_data.alert_desc = ind->alert_desc;
        cb_data.cause = ind->cause;
        cb_data.error = ind->error;

        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
            cb_data.res_id,
            cb_data.soc_id,
            cb_data.alert_level,
            cb_data.alert_desc,
            cb_data.cause,
            cb_data.error,
            23, __LINE__);

        

        PMNG_WRAP_CALLBACK(ctx_p->p_hdl,         
            (ctx_p->cb)((vm_tls_event_struct*)&cb_data));
        return MMI_TRUE;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 23, __LINE__);
    return MMI_FALSE;
}
static MMI_BOOL vm_tls_invalid_cert_ind(void *msg)
{
    app_tls_client_auth_ind_struct * ind = (app_tls_client_auth_ind_struct *)msg;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 24, __LINE__);
    if (NULL == ind)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 24, __LINE__);
        return MMI_FALSE;
    }
    
    ctx_p = vm_tls_get_ctx_by_soc(ind->sock_id);
    if (NULL != ctx_p)
    {
        vm_tls_client_auth_ind_struct cb_data = {0};
        cb_data.msg = VM_MSG_ID_APP_TLS_INVALID_CERT_IND;
        memcpy(cb_data.auth_modes, ind->auth_modes, 
            sizeof(cb_data.auth_modes) > sizeof(ind->auth_modes) ? sizeof(ind->auth_modes) : sizeof(cb_data.auth_modes));
        cb_data.auth_mode_num = ind->auth_mode_num;
        cb_data.identity_id = ind->identity_id;
        cb_data.result = ind->result;
        
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
            cb_data.auth_mode_num,
            cb_data.identity_id,
            cb_data.result,
            sizeof(cb_data.auth_modes),
            sizeof(ind->auth_modes),
            0,
            24, __LINE__);
        PMNG_WRAP_CALLBACK(ctx_p->p_hdl,         
            (ctx_p->cb)((vm_tls_event_struct*)&cb_data));
        return MMI_TRUE;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 24, __LINE__);
    return MMI_FALSE;
}
static MMI_BOOL vm_tls_client_auth_ind(void *msg)
{
    app_tls_notify_ind_struct * ind = (app_tls_notify_ind_struct *)msg;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 25, __LINE__);
    if (NULL == ind)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 25, __LINE__);
        return MMI_FALSE;
    }
    
    ctx_p = vm_tls_get_ctx_by_soc(ind->sock_id);
    if (NULL != ctx_p)
    {
        vm_tls_notify_ind_struct cb_data = {0};
        cb_data.msg = VM_MSG_ID_APP_TLS_CLIENT_AUTH_IND;
        cb_data.detail_cause = ind->detail_cause;
        cb_data.error = ind->error;
        cb_data.event = ind->event;
        cb_data.result = ind->result;
        
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
            cb_data.detail_cause,
            cb_data.error,
            cb_data.event,
            cb_data.result,
            0,
            0,
            25, __LINE__);
            
        PMNG_WRAP_CALLBACK(ctx_p->p_hdl,         
            (ctx_p->cb)((vm_tls_event_struct*)&cb_data));
            
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 25, __LINE__);
        return MMI_TRUE;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 25, __LINE__);
    return MMI_FALSE;
}

static VMINT g_ref_count = 0;
VMINT vm_tls_new_ctx(vm_tls_version_enum ver, vm_socket_type_enum sock_type, VMINT apn, vm_tls_side_enum side, callback_t cb)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    VMUINT acct_id = 0;
    kal_uint8 val;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 1, __LINE__);

    
    ctx_p = vm_tls_malloc_ctx();

    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 1, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_new_ctx((tls_version_enum)ver,
        (tls_side_enum)side,
        MOD_MMI,
        STR_MRE_TITLE);

    if (ret < 0)
    {
        vm_tls_free_ctx(ctx_p);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 1, ret);
        return ret;
    }

    ctx_p->tls_ctx = ret;
    ctx_p->cb = cb;
    ctx_p->soc_id = 0;
    ctx_p->p_hdl = vm_pmng_get_current_handle();


    if (VM_E_SOC_SUCCESS != vm_get_encoded_dtacct_id(apn, &acct_id))
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E3, 1, __LINE__);
        return VM_TLS_RET_BASE -3;
    }

    
    ctx_p->soc_id = soc_create(SOC_PF_INET, sock_type, 0, MOD_MMI, acct_id);
    if (0 > ctx_p->soc_id)
    {
        // TODO: print ctx_p->soc_id
        ctx_p->soc_id = 0;
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E4, 1, __LINE__);
        return VM_TLS_RET_BASE -3;
    }
    
    val = KAL_TRUE;
    ret = soc_setsockopt(ctx_p->soc_id, SOC_NBIO, &val, sizeof(val));
    if (ret < 0)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E5, 1, __LINE__);
        return VM_TLS_RET_BASE -5;
    }

    val = SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE;
    ret = soc_setsockopt(ctx_p->soc_id, SOC_ASYNC, &val, sizeof(val));
    if (ret < 0)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E6, 1, __LINE__);
        return VM_TLS_RET_BASE -6;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        ctx_p->tls_ctx,
        ctx_p->soc_id,
        ctx_p->p_hdl,
        0,
        0,
        ctx_p->cb,
        1, __LINE__);
    
    if (0 == g_ref_count++)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_tls_notify_cb, MMI_TRUE);
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_TLS_NOTIFY_IND, (PsIntFuncPtr)vm_tls_notify_ind, MMI_TRUE);
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_TLS_ALERT_IND, (PsIntFuncPtr)vm_tls_alert_ind, MMI_TRUE);
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_TLS_INVALID_CERT_IND, (PsIntFuncPtr)vm_tls_invalid_cert_ind, MMI_TRUE);
        mmi_frm_set_protocol_event_handler(MSG_ID_APP_TLS_CLIENT_AUTH_IND, (PsIntFuncPtr)vm_tls_client_auth_ind, MMI_TRUE);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E7, 1, __LINE__);
    }

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 1, ctx_p->res_id);
    return ctx_p->res_id;
    
    
}

VMINT vm_tls_delete_ctx(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 21, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 21, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_delete_ctx(ctx_p->tls_ctx);
    vm_tls_free_ctx(ctx_p);

    
    if (0 == --g_ref_count)
    {
        mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_tls_notify_cb);
        mmi_frm_clear_protocol_event_handler(MSG_ID_APP_TLS_NOTIFY_IND, (PsIntFuncPtr)vm_tls_notify_ind);
        mmi_frm_clear_protocol_event_handler(MSG_ID_APP_TLS_ALERT_IND, (PsIntFuncPtr)vm_tls_alert_ind);
        mmi_frm_clear_protocol_event_handler(MSG_ID_APP_TLS_INVALID_CERT_IND, (PsIntFuncPtr)vm_tls_invalid_cert_ind);
        mmi_frm_clear_protocol_event_handler(MSG_ID_APP_TLS_CLIENT_AUTH_IND, (PsIntFuncPtr)vm_tls_client_auth_ind);
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 21, __LINE__);
    }

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 21, ret);
    return ret;
}

VMINT vm_tls_set_ciphers(VMINT res_id, const vm_tls_cipher_enum ciphers[], VMINT num)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 20, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 20, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_set_ciphers(ctx_p->tls_ctx, (const tls_cipher_enum *)ciphers, (kal_int32)num);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 20, ret);
        return ret;
    }

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 20, __LINE__);
    return 0;
}

VMINT vm_tls_set_verify(VMINT res_id, VMUINT32 cert_id[], VMINT cert_num, vm_tls_filetype_enum type)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 19, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 19, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_set_verify(ctx_p->tls_ctx, (kal_uint32*)cert_id, (kal_uint8)cert_num, (tls_filetype_enum)type, NULL, NULL);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 19, ret);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 19, __LINE__);
    return 0;
}

VMINT vm_tls_set_client_auth(VMINT res_id, vm_tls_auth_mode_enum modes[], VMINT num)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 18, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 18, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_set_client_auth(ctx_p->tls_ctx, (tls_auth_mode_enum*)modes, (kal_uint8)num);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 18, ret);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 18, __LINE__);
    return 0;
}

VMINT vm_tls_set_identity(VMINT res_id, VMUINT32 cert_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 17, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 17, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_set_identity(ctx_p->tls_ctx, (kal_uint32)cert_id);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 17, ret);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 17, __LINE__);
    return 0;
}

VMINT vm_tls_new_conn(VMINT res_id, vm_sockaddr_ex_struct * faddr)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    sockaddr_struct int_faddr = {0};
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 2, __LINE__);
    if (NULL == faddr)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 2, __LINE__);
        return VM_TLS_RET_BASE -3;
    }

    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 2, __LINE__);
        return VM_TLS_RET_BASE -2;
    }


    int_faddr.addr_len = faddr->addr_len;
    memcpy(int_faddr.addr, faddr->addr, int_faddr.addr_len);
    int_faddr.port = faddr->port;
    int_faddr.sock_type = faddr->sock_type;
    ret = tls_new_conn(ctx_p->tls_ctx, ctx_p->soc_id, (sockaddr_struct *)&int_faddr);
    //ret = tls_connect(ctx_p->soc_id, (sockaddr_struct *)&int_faddr);
    
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        int_faddr.addr_len,
        int_faddr.addr[0],
        int_faddr.addr[1],
        int_faddr.addr[2],
        int_faddr.addr[3],
        int_faddr.port,
        2, int_faddr.sock_type);
        
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E3, 2, ret);
        return ret;
    }

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 2, __LINE__);
    return ret;
    
}

VMINT vm_tls_delete_conn(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 16, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 16, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    if (ctx_p->soc_id <= 0)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 16, __LINE__);
        return VM_TLS_RET_BASE -3;
    }
    
    ret = tls_delete_conn((kal_int8)ctx_p->soc_id);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E3, 16, __LINE__);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 16, __LINE__);
    return 0;

}

VMINT vm_tls_get_cipher(VMINT res_id, vm_tls_ciphersuites_enum * cipher)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 15, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 15, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_get_cipher((kal_int8)ctx_p->soc_id, (tls_ciphersuites_enum*)cipher);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 15, __LINE__);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 15, __LINE__);
    return 0;
}

VMINT vm_tls_get_cipher_info(VMINT res_id, vm_tls_cipher_info_struct *cipher_info)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 14, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 14, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_get_cipher_info((kal_int8)ctx_p->soc_id, (tls_cipher_info_struct *)cipher_info);
    
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 14, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 14, __LINE__);
    return 0;
}

VMINT vm_tls_get_peer_cert(VMINT res_id, vm_tls_cert_struct *cert)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 14, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 14, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_get_peer_cert((kal_int8)ctx_p->soc_id, (tls_cert_struct *)cert);

    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 14, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 14, __LINE__);
    return 0;
}

VMINT vm_tls_check_invalid_cert(VMINT res_id, VMINT onoff)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 13, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 13, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_check_invalid_cert((kal_int8)ctx_p->soc_id, (kal_bool)onoff);

    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 13, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 13, __LINE__);
    return 0;
}

VMINT vm_tls_set_null_client_auth(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 12, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 12, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_set_null_client_auth((kal_int8)ctx_p->soc_id);
    
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 12, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 12, __LINE__);
    return 0;
}

VMINT vm_tls_check_peer_name(VMINT res_id, const VMCHAR * name)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 11, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 11, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = vm_tls_check_peer_name((kal_int8)ctx_p->soc_id, (const VMCHAR *const)name);
    
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 11, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 11, __LINE__);
    return 0;
}

VMINT vm_tls_auto_rehandshake(VMINT res_id, VMINT onoff)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 10, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 10, __LINE__);
        return VM_TLS_RET_BASE -2;
    }
    
    ret = tls_auto_rehandshake((kal_int8)(ctx_p->soc_id), onoff);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 10, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 10, __LINE__);
    return 0;
}

VMINT vm_tls_handshake(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 9, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 9, __LINE__);
        return VM_TLS_RET_BASE -2;
    }
    
    ret = tls_handshake((kal_int8)(ctx_p->soc_id));
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 9, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 9, __LINE__);
    return 0;
}

VMINT vm_tls_rehandshake(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 8, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 8, __LINE__);
        return VM_TLS_RET_BASE -2;
    }
    
    ret = tls_rehandshake((kal_int8)(ctx_p->soc_id));
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 8, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 8, __LINE__);
    return 0;
}

VMINT vm_tls_read(VMINT res_id, void* buf, VMINT32 len)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 7, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 7, __LINE__);
        return VM_TLS_RET_BASE -2;
    }
    
    ret = tls_read((kal_int8)(ctx_p->soc_id), (void *)buf, (kal_int32)len);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 7, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 7, __LINE__);
    return 0;
}

VMINT vm_tls_write(VMINT res_id, const void* buf, VMINT32 len)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 6, __LINE__);
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 6, __LINE__);
        return VM_TLS_RET_BASE -2;
    }
    
    ret = tls_write((kal_int8)(ctx_p->soc_id), (const void *)buf, (kal_int32)len);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 6, ret);
        return ret;
    }
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 6, __LINE__);
    return 0;
}

VMINT vm_tls_shutdown(VMINT res_id)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 5, __LINE__);
    
    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 5, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    ret = tls_shutdown(ctx_p->soc_id);
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 5, ret);
        return ret;
    }

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 5, ret);
    
    return ret;
}

VMINT vm_tls_connect(VMINT res_id, vm_sockaddr_ex_struct * faddr)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    sockaddr_struct int_faddr = {0};

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 3, __LINE__);
    if (NULL == faddr)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 3, __LINE__);
        return VM_TLS_RET_BASE -3;
    }

    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 3, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    int_faddr.addr_len = faddr->addr_len;
    memcpy(int_faddr.addr, faddr->addr, int_faddr.addr_len);
    int_faddr.port = faddr->port;
    int_faddr.sock_type = faddr->sock_type;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        int_faddr.addr_len,
        int_faddr.addr[0],
        int_faddr.addr[1],
        int_faddr.addr[2],
        int_faddr.addr[3],
        int_faddr.port,
        3, int_faddr.sock_type);
        
    ret = tls_connect(ctx_p->soc_id, &int_faddr);
    
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E3, 3, ret);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 3, __LINE__);
    return ret;
}

VMINT vm_tls_soc_connect(VMINT res_id, vm_sockaddr_ex_struct * faddr)
{
    kal_int32 ret;
    vm_tls_context_t * ctx_p = NULL;
    sockaddr_struct int_faddr = {0};

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 27, __LINE__);
    if (NULL == faddr)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E1, 27, __LINE__);
        return VM_TLS_RET_BASE -3;
    }

    ctx_p = vm_tls_get_ctx_by_res(res_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E2, 27, __LINE__);
        return VM_TLS_RET_BASE -2;
    }

    int_faddr.addr_len = faddr->addr_len;
    memcpy(int_faddr.addr, faddr->addr, int_faddr.addr_len);
    int_faddr.port = faddr->port;
    int_faddr.sock_type = faddr->sock_type;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_DLS_LOG, 
        int_faddr.addr_len,
        int_faddr.addr[0],
        int_faddr.addr[1],
        int_faddr.addr[2],
        int_faddr.addr[3],
        int_faddr.port,
        27, int_faddr.sock_type);
        
    ret = soc_connect(ctx_p->soc_id, &int_faddr);
    
    if (TLS_ERR_NONE != ret)
    {
        MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E3, 27, ret);
        return ret;
    }
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 27, __LINE__);
    return ret;
}

VMINT vm_tls_log_plaintext(VMINT onoff)
{
    //vm_tls_context_t * ctx_p = NULL;

    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_S, 4, __LINE__);
    
    tls_log_plaintext((kal_bool)onoff);
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MRE_SSL_E, 4, onoff);
    return 0;
    
}

#endif /*__MRE_SAL_TLS__*/

