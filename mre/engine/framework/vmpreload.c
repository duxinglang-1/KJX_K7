#include "vmswitch.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "MMI_mre_trc.h"
#include "mmi_trc.h"

#ifdef __MRE_SAL_SOCKET__


#include "vmsock.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmio.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"
#include "vmmod.h"
#include "vmmacrostub.h"
#include "MRESrvDownloadGprot.h"
#include "DtcntSrvIprot.h"
#include "DLAgentSrvGProt.h"

#define LF 10           
#define CR 13    
#define BUFFER_LEN (2*1024)
static kal_char * CONTENT_LENGTH = "Content-Length:";
//#define B_START "--------------------------------96003044DE287"
//#define B_END "----------------------------------96003044DE287--"


typedef struct 
{
    VMINT res_id;
    VMINT p_hdl;
    VMINT app_id;
    VMINT soc_id;
    void * user_data;
    void (*cb)(VMINT hdl, void * para);
    VMCHAR url[256];
    VMINT port;
    VMCHAR host[64];
    VMINT apn;
    VMINT update;
    VMWCHAR path[260];
    VMINT twice_confirmed;
    VMINT g_http_content_length;
    VMINT need_recv_len;
    VMINT status;
    VMBOOL bDLA;
    vm_preload_query_info_t query_info;
}vm_preload_ctx_t;

//static VMINT g_http_content_length = 0;
//static VMINT need_recv_len = 0;
//static vm_preload_ctx_t ctx;
extern const char* applib_inet_get_user_agent_string(void);
static void _vm_preload_free_ctx(vm_preload_ctx_t * ctx_p);
static vm_preload_ctx_t * _vm_preload_malloc_ctx(void);
static vm_preload_ctx_t * _vm_preload_get_ctx(VM_P_HANDLE p_hdl,VMINT id, VMINT type);
extern kal_int32 app_strnicmp(kal_char *s, kal_char *t, int n);
static void _vm_preload_cb(VMINT handle, VMINT event);
static void _vm_preload_clean(vm_preload_ctx_t * ctx_p);
static VMINT _vm_preload_check_valid(vm_preload_ctx_t * ctx_p);

static void PRELOAD_PMNG_WRAP_CALLBACK(VM_P_HANDLE p, void (*cb)(VMINT hdl, void * para), VMINT rid, void * data)
{
    if (vm_pmng_set_ctx(p) == VM_PMNG_OP_OK)
    {
        cb(rid, data);
        vm_pmng_reset_ctx(); 
    }
}

static void vm_preload_do_connection(vm_preload_ctx_t * ctx_p, VMINT n)
{

    vm_apn_info_ext info = {0};
    VMUINT dtacct_id;
    vm_get_encoded_dtacct_id(VM_TCP_APN_CMWAP, &dtacct_id);
    
    if (vm_wifi_is_connected())
    {
        ctx_p->soc_id = vm_tcp_connect(ctx_p->host, ctx_p->port, ctx_p->apn, _vm_preload_cb); 
        MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload cnt wifi1[%s, %d] npx[%d]", 
            ctx_p->host, ctx_p->port, n);
    }
    else
    {
        if (0 == vm_get_apn_info(&info)) // px
        {
            memset(&info, 0, sizeof(info));
            if (0 == vm_get_default_apn_info(&info))
            {
                if (info.apn_info_id)
                {
                    //ctx_p->apn = 2;
                    ctx_p->soc_id = vm_tcp_connect(info.proxy_ip, info.proxy_port, VM_TCP_APN_CMWAP, _vm_preload_cb);
                    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload cnt [%s, %d] px[%d]", 
                        info.proxy_ip, info.proxy_port, n);
                }
                else
                {
                    ctx_p->soc_id = vm_tcp_connect(ctx_p->host, ctx_p->port, ctx_p->apn, _vm_preload_cb); 
                    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload cnt [%s, %d] npx[%d]", 
                        info.proxy_ip, info.proxy_port, n);
                }
            }
            else // wifi without sim
            {
                ctx_p->soc_id = vm_tcp_connect(ctx_p->host, ctx_p->port, ctx_p->apn, _vm_preload_cb); 
                MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload cnt 1[%s, %d] npx[%d]", 
                    ctx_p->host, ctx_p->port, n);
            }
        }
        else // npx
        {
            ctx_p->soc_id = vm_tcp_connect(ctx_p->host, ctx_p->port, ctx_p->apn, _vm_preload_cb); 
            MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload cnt 2[%s, %d] npx[%d]", 
                ctx_p->host, ctx_p->port, n);
        }
    }

}

static void vm_preload_free_resource(VM_P_HANDLE process_handle)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_preload_ctx_t * ctx_p = NULL;
    
    while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_PRELOAD)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p)
            {
                //_vm_preload_clean(ctx_p);
                _vm_preload_free_ctx(ctx_p);
            }
        }
        else
        {
        }
        vm_res_release_data(VM_RES_TYPE_PRELOAD, resHandle);
        vm_res_findclose(VM_RES_TYPE_PRELOAD); 
    }
}

static void vm_preload_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_preload_free_resource(process_handle);
        break;
    }
}


static VMINT vm_preload_initialize_resource(void)
{
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_PRELOAD, 
        vm_preload_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.


    return 0;
}

static VMINT vm_preload_finialize_resource(void)
{
    vm_preload_free_resource(-1);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_PRELOAD, NULL);

    return 0;
}

static VMINT vm_preload_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_preload_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_preload_finialize_resource();
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

VMINT _vm_reg_preload_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("PLD", (MOD_EVT_PROCESS)vm_preload_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    
    }

    return res_code;
}

static vm_preload_ctx_t * _vm_preload_get_ctx(VM_P_HANDLE p_hdl,VMINT id, VMINT type)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_preload_ctx_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(p_hdl, VM_RES_TYPE_PRELOAD)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (type == 0)
            {
                if (ctx_p->app_id == id)
                {
                    vm_res_findclose(VM_RES_TYPE_PRELOAD);
                    return ctx_p;
                }
            }
            else if (type == 1)
            {
                if (ctx_p->soc_id == id)
                {
                    vm_res_findclose(VM_RES_TYPE_PRELOAD);
                    return ctx_p;
                }
            }
        }

        while ((resHandle = vm_res_findnext(p_hdl, VM_RES_TYPE_PRELOAD)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (type == 0)
                {
                    if (ctx_p->app_id == id)
                    {
                        vm_res_findclose(VM_RES_TYPE_PRELOAD);
                        return ctx_p;
                    }
                }
                else if (type == 1)
                {
                    if (ctx_p->soc_id == id)
                    {
                        vm_res_findclose(VM_RES_TYPE_PRELOAD);
                        return ctx_p;
                    }
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_PRELOAD);
    }	
    return NULL;

}

static vm_preload_ctx_t * _vm_preload_malloc_ctx(void)
{
    vm_preload_ctx_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_preload_ctx_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_PRELOAD, 
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

static void _vm_preload_free_ctx(vm_preload_ctx_t * ctx_p)
{
    VMINT res_id;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2853 );
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2856 );
        return;
    }
    res_id = ctx_p->res_id;
    _vm_preload_clean(ctx_p);
    if (VM_RES_OK == vm_res_release_data(VM_RES_TYPE_PRELOAD, res_id))
    {
        _vm_kernel_free(ctx_p);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2863 );
}

VMINT vm_preload_query(VMINT apn,
                       const VMCHAR * url, 
                       VMINT port,
                       const vm_preload_query_info_t * info,
                       void (*callback)(VMINT hdl, void * para), 
                       void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    VMCHAR http_host[128] = {0};
    vm_apn_info_ext apn_info;
    vm_common_t common = {E_PRELOAD_QUERYING, NULL};
    vm_preload_ctx_t * ctx_p = NULL;
    //srv_dtcnt_sim_type_enum sim_type;
    VMINT with_port = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2884 );			

    if (NULL == url ||
        0 > port ||
        NULL == info ||
        NULL == info->ua ||
        NULL == callback)
//        NULL == user_data)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2893 );            
        return -2;
    }


    if (VM_TCP_APN_CMNET == apn || 
    VM_TCP_APN_CMNET_ONLY == apn ||
    VM_TCP_APN_WIFI == apn &&
        apn != VM_APN_USER_DEFINE)
    {
        VMINT pos = 7; // http://
        for(; url[pos]; pos ++)
        {
            if (url[pos] == ':')
            {
                with_port = atoi(&url[pos] + 1);
                break;
            }
            if (url[pos] == '/')
                break;
        }
        strncpy(http_host, url + 7, pos - 7);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2907 , http_host);
    }
    else if (VM_TCP_APN_CMWAP == apn ||
    VM_TCP_APN_CMWAP_ONLY == apn)
    {
        VMUINT dtacct_id;
        vm_get_encoded_dtacct_id(VM_TCP_APN_CMWAP, &dtacct_id);
        if (0 == vm_get_apn_info(&apn_info) && !apn_info.apn_info_id)
        {
            VMINT pos = 7; // http://
            for(; url[pos]; pos ++)
            {
                if (url[pos] == ':')
                {
                    with_port = atoi(&url[pos] + 1);
                    break;
                }
                if (url[pos] == '/')
                    break;
            }
            strncpy(http_host, url + 7, pos - 7);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2923 , apn_info.proxy_ip);
        }
        else
        {
            with_port = apn_info.proxy_port;// atoi(&url[pos] + 1);
            strncpy(http_host, apn_info.proxy_ip, sizeof(apn_info.proxy_ip));
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2929 , http_host);
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2933 );            
        return -3;
    }

    ctx_p = _vm_preload_get_ctx(vm_pmng_get_current_handle(), info->app_id, 0);
    if (NULL == ctx_p)
    {
        ctx_p = _vm_preload_malloc_ctx();
        if (NULL == ctx_p)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2943 );            
            return -4;
        }
    }
    /*
    else
    {
        if (1 == ctx_p->update)
        {
            vm_trace("vm_preload_query res not enough -5");            
            return -5;
        }
    }
    */
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->app_id = info->app_id;
    ctx_p->user_data = user_data;
    ctx_p->cb = callback;
    strcpy(ctx_p->url, url);
    ctx_p->port = with_port ? with_port : port;
    strcpy(ctx_p->host, http_host);
    ctx_p->apn = apn;
    ctx_p->update = 0;
    memcpy(&(ctx_p->query_info), info, sizeof(vm_preload_query_info_t));
    ctx_p->twice_confirmed = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2959 , ctx_p->host, ctx_p->port, apn);            
#ifdef WIN32
    //strcpy(ctx_p->host, "172.21.87.241");
#endif
    if (ctx_p->soc_id > 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2965 );       
        vm_tcp_close(ctx_p->soc_id);
    }
    //srv_dtcnt_get_sim_preference(&sim_type);
    if ((stub_tcp_is_support_wifi() && VM_TCP_APN_WIFI == ctx_p->apn)
#ifdef __COSMOS_MMI_PACKAGE__      
      //  || (srv_mre_da_get_account_id(SRV_MRE_DA_WIFI_ONLY) == 1)
      //  || (sim_type == SRV_DTCNT_SIM_TYPE_NONE)
#endif
        )
    {
        if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
        {
            //MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_UDP_E3, 2, __LINE__);
            _vm_preload_free_ctx(ctx_p);
            return -6;
        }
    }

#if 1
    vm_preload_do_connection(ctx_p, 1);
#else
/* under construction !*/
#endif

    if (0 > ctx_p->soc_id)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2973 );       
        _vm_preload_free_ctx(ctx_p);
        return -5;
    }
    
    common.user_data = ctx_p->user_data;
    common.state = E_PRELOAD_CONNECTING;
    PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
        ctx_p->cb, ctx_p->res_id, (void*)&common);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2983 );			

    ctx_p->status = E_PRELOAD_DOWNLOADING;
    
    return ctx_p->res_id;
}
#if defined(MMI_DA_HTTP_DOWNLOAD_SUPPORT)

void vm_preload_download_callback(srv_da_download_progress_struct *report_struct)
{  
    vm_preload_ctx_t * ctx_p = report_struct->user_data;
    VMINT found = 0;
    vm_preload_recv_data_t data;
    found = _vm_preload_check_valid(ctx_p);
    
    if (!found)
    {
        return;
    }

    if (0 == report_struct->status)
    {
        data.head.state = E_PRELOAD_DOWNLOADING;
        ctx_p->status = (VMINT)E_PRELOAD_DOWNLOADING;
    }
    else if (1 == report_struct->status)
    {
        data.head.state = E_PRELOAD_DOWNLOADED;
        ctx_p->status = (VMINT)E_PRELOAD_DOWNLOADED;
    }
    else
    {
	    //srv_da_http_dl_operation(report_struct->arg, SRV_DA_DOWNLOAD_STOP);
        data.head.state = E_PRELOAD_ABORT;
        ctx_p->status = (VMINT)E_PRELOAD_ABORT;
    }
        data.head.user_data = ctx_p->user_data;
        data.received = report_struct->curr_size;
        data.total = report_struct->total_size;
        PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
            ctx_p->cb, ctx_p->res_id, (void*)&data);
    if (data.head.state != E_PRELOAD_DOWNLOADING )     
    {
        //_vm_preload_clean(ctx_p);
        _vm_preload_free_ctx(ctx_p);
    }
    return;
}

void vm_preload_download_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    S8  *url,
    S8  *mime_type_string,
    U32 content_len,
    S8  *content,
    srv_da_setting_struct *setting 
)
{

}

void vm_preload_download_dispatch(
	S32 session_id,
	S32 mime_type,
	S32 mime_subtype,
	S32 action,
	U16 *filepath,
	S8  *url,
	S8  *mime_type_string
)
{

}

#endif


#if !(defined(MMI_DA_HTTP_DOWNLOAD_SUPPORT))
VMBOOL g_no_dla = 1;
#elif (!defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__))
VMBOOL g_no_dla = 1;
#else
VMBOOL g_no_dla = 0;
#endif
VMINT vm_preload_download_ex(VMINT hdl, const VMWCHAR * data, VMBOOL bDLA,void (*callback)(VMINT hdl, void * para), void * user_data)
{
    VMCHAR http_header[BUFFER_LEN] = {0};
    VMINT ret = 0;
    VMINT written = 0;
    vm_preload_ctx_t * ctx_p = NULL;
    VMINT bufSize = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_2997 );			
    if (NULL == data || 0 > hdl)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3000 );         
        return -2;
    }

    if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
        hdl, (void**)&ctx_p, &bufSize) != VM_RES_OK)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3058 , -6);           
        return -6;
    }
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3009 );      
        return -3;
    }
    
    
    vm_wstrcpy(ctx_p->path, (const VMWSTR)data);
    ctx_p->cb = callback;
    ctx_p->user_data = user_data;
    ctx_p->bDLA = bDLA;
    if (!bDLA || g_no_dla)
    {
    if (0 > ctx_p->soc_id && ctx_p->update)
    {
        // host is changed.
        if (0 == strstr(ctx_p->url, ctx_p->host))
        {
            VMINT nspan = 7; // http:// is 7 bytes
            for(nspan = 7; ctx_p->url[nspan] != '\0'; nspan ++)
            {
                if (ctx_p->url[nspan] == ':')
                {
                    ctx_p->port = atoi(&ctx_p->url[nspan + 1]);
                    break;
                }
                if (ctx_p->url[nspan] == '/')
                    break;
            }
            memset(ctx_p->host, 0, sizeof(ctx_p->host));
            memcpy(ctx_p->host, &ctx_p->url[7], nspan - 7);
        }
#if 1
    vm_preload_do_connection(ctx_p, 2);
#else
/* under construction !*/
#endif
        if (0 > ctx_p->soc_id)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3023 );         
            return -4;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3026 );
        
        return 0;
    }
		
    //vm_wstrcpy(ctx_p->path, (const VMWSTR)data);


    //memset(ctx_p->path, 0, sizeof(ctx_p->path));

    // http header
    sprintf(http_header, "GET %s HTTP/1.1\r\nHost: %s:%d\r\n"
#ifdef WIN32
   //"Proxy-Authorization: Basic TXRrODAwMjM6MWFjNmIxMDEx\r\n"
#endif
    "User-Agent: %s\r\n"
    "Accept: %s\r\n"
    "Accept-Language: %s\r\n\r\n",
        ctx_p->url, 
        ctx_p->host, 
        ctx_p->port, 
        (VMCHAR*)applib_inet_get_user_agent_string(),
        "*/*", 
        "en");
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3051 , ctx_p->url, ctx_p->port, ctx_p->host);  

    while (0 < (ret = vm_tcp_write(ctx_p->soc_id, http_header + written, strlen(http_header) - written)))
    {
        written += ret;
    }
    }
    else
    {
#if defined(MMI_DA_HTTP_DOWNLOAD_SUPPORT)   
        VMUINT account_id;
        srv_da_start_download_struct da_param;
        vm_apn_info_ext info = {0};
        
        memset(&da_param,0,sizeof(da_param));
        vm_get_encoded_dtacct_id(VM_TCP_APN_CMWAP, &account_id);
        MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload dla dt[0x%x]", 
            account_id);
        if (0 == vm_get_apn_info(&info)) // px
        {
            if (0 == vm_get_default_apn_info(&info))
            {
                if (info.apn_info_id)
                {
                    vm_get_encoded_dtacct_id(VM_TCP_APN_CMWAP, &account_id);
                    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload dla px[0x%x]", 
                        account_id);
                }
                else
                {
                    vm_get_encoded_dtacct_id(VM_TCP_APN_CMNET, &account_id);
                    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_MOD_VMSOCK,"preload dla npx[0x%x]", 
                        account_id);
                }
            }
            else // wifi without sim
            {
                
            }
        }
        srv_dtcnt_get_auto_acc_id(account_id, &da_param.acc_id);
        mmi_asc_n_to_ucs2((CHAR *)http_header,ctx_p->url,BUFFER_LEN);
        da_param.url = (WCHAR*)http_header;
        //da_param.acc_id = account_id;
        da_param.show_confirm = MMI_FALSE;
        da_param.user_data = ctx_p;
        da_param.filepath = (U16 *)data;
        da_param.dl_progress = vm_preload_download_callback;
        da_param.dispatch_callback = NULL;
        da_param.setting_hdlr = srv_da_bypass_setting;//vm_preload_download_setting;
        if (NULL == srv_da_start_http_download(&da_param))
        {
            //_vm_preload_clean(ctx_p);
            _vm_preload_free_ctx(ctx_p);
            return -5;
        }
#endif        
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3058 , ret);			
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3060 );			
    return 0;
}

VMINT vm_preload_download(VMINT hdl, const VMWCHAR * data, void (*callback)(VMINT hdl, void * para), void * user_data)
{
    return vm_preload_download_ex(hdl,data,0,callback,user_data);
}

VMINT vm_preload_cancel(VMINT hdl)
{
    vm_preload_ctx_t * ctx_p = NULL;
    VMINT bufSize = 0;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3068 );

    if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
        hdl, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
    {
        //_vm_preload_clean(ctx_p);
        _vm_preload_free_ctx(ctx_p);
    }
    
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3075 );
        return -2;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3081 );
    return 0;
}

VMINT vm_preload_status(VMINT app_id)
{
    VMINT result;
    vm_preload_ctx_t* ctx_p = _vm_preload_get_ctx(vm_pmng_get_current_handle(),app_id, 0);
    if (!ctx_p)
    {
        result = -2;
    }
    else
    {
        result = ctx_p->status;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3058 , result);	
    return result;
}

void vm_preload_show_download_list(void)
{
#if defined(MMI_DA_HTTP_DOWNLOAD_SUPPORT)
    srv_da_display_download_list();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static void _vm_preload_try_query(vm_preload_ctx_t * ctx_p)
{
    VMCHAR http_header[BUFFER_LEN] = {0};
    VMCHAR http_body[BUFFER_LEN] = {0};
    VMINT ret = 0;
    VMINT written = 0;
    vm_common_t head = {E_PRELOAD_QUERYING, NULL};
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3114 );			
    // vm_preload_cancel check
    if (NULL == ctx_p->cb)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3117 );            
        return;
    }

    //memset(ctx_p->path, 0, sizeof(ctx_p->path));
    //vm_wstrcpy(ctx_p->path, (VMWSTR)data);
    //app_id=%d; ver=\"%s\"; imsi=\"%s\"; imei=\"%s\"; sc=\"%s\"; skb=\"%s\"; stch=\"%s\"; sgs=\"%s\"; scs=\"%s\"; w=%d; h=%d\r\n\
    // http body

    head.state = E_PRELOAD_QUERYING;
    head.user_data = ctx_p->user_data;
    PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
        ctx_p->cb, ctx_p->res_id, (void*)&head);
    // vm_preload_cancel check
    if (NULL == ctx_p->cb)
    {
        return;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3130 );			
    #ifndef _POST_

    // http header
    sprintf(http_header, "GET %s?%s HTTP/1.1\r\nHost: %s:%d\r\n"
    #ifdef WIN32
    //"Proxy-Authorization: Basic TXRrODAwMjM6MWFjNmIxMDEx\r\n"
    #endif
    "User-Agent: %s\r\n"
    "Accept: %s\r\n"
    "Accept-Language: %s\r\n\r\n",
        ctx_p->url, 
/*        ctx_p->query_info.app_id,
        ctx_p->query_info.ver,  
        ctx_p->query_info.imsi,
        ctx_p->query_info.imei, */
        ctx_p->query_info.ua,
        ctx_p->host, 
        ctx_p->port, 
        (VMCHAR*)applib_inet_get_user_agent_string(),
        "*/*", 
        "en");


    #else
    //app_id=%d; ver=\"%s\"; imsi=\"%s\"; imei=\"%s\"; sc=\"%s\"; skb=\"%s\"; stch=\"%s\"; sgs=\"%s\"; scs=\"%s\"; w=%d; h=%d\r\n\r\n
    //app_id: %d\r\nver: %s\r\nimsi: %s\r\nimei: %s\r\nsc: %s\r\nskb: %s\r\nstch: %s\r\nsgs: %s\r\nscs: %s\r\nw: %d\r\nh: %d\r\n\r\n
/*    sprintf(http_body, "app_id=%d&ver=%s&imsi=%s&imei=%s&ua=%s&w=128&h=320&asdfasdf=asdfasdf&hahsdj=asdf&sss=fff",
        ctx_p->query_info.app_id,
        ctx_p->query_info.ver, 
        ctx_p->query_info.imsi,
        ctx_p->query_info.imei, 
        ctx_p->query_info.ua);*/
    strcpy(http_body,ctx_p->query_info.ua);
        
    sprintf(http_header, "POST %s HTTP/1.1\r\nHost: %s:%d\r\nProxy-Authorization: Basic TXRrODAwMjM6MWFjNmIxMDEx\r\n\
    User-Agent: %s\r\n\
    Accept: %s\r\n\
    Accept-Language: %s\r\n\
    Accept-Charset: %s\r\n\
    Accept-Encoding: %s\r\n\
    Connection: %s\r\n\
    Content-Type: %s\r\n\
    Content-Length: %d\r\n\r\n", 
        ctx_p->url, ctx_p->host, ctx_p->port, 
        (VMCHAR*)applib_inet_get_user_agent_string(),
        "*/*", 
        "zh_CN,zh",
        "UTF-8,ISO-8859-1,US-ASCII,ISO-10646-UCS-2;q=0.6",
        "identity",
        "Keep-Alive",
        "form-data/application/x-www-form-urlencoded", 
        strlen(http_body));

    strcat(http_header, http_body);

    #endif
    
    while (0 < (ret = vm_tcp_write(ctx_p->soc_id, http_header + written, strlen(http_header) - written)))
    {
        written += ret;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3190 , written);            
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3200 , ret);			
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3201 );			
}

static VMINT vm_preload_is_url_valid(const VMCHAR * body, vm_preload_ctx_t * ctx_p)
{
    const VMCHAR * stamp = "<go href=\"";
    VMCHAR * p;
    VMINT i = 0;
    VMINT len = strlen(body);

    p = strstr(body, stamp);
    if (NULL == p)
    {
        return 1;
    }
    
    p = p + strlen(stamp);
    while (i < len)
    {
        if ('\"' == p[i++])
            break;
    }
    
    //memset(ctx_p->url, 0, sizeof(ctx_p->url));
    //memcpy(ctx_p->url, p, i - 1);

    len = i - 1;

    for (i = len - 1; i >= 0; i--)
    {
        if ('&' == p[i] || ';' == p[i])
        {
            break;
        }
    }
    
    strcat(ctx_p->query_info.ua, "&");
    strncat(ctx_p->query_info.ua, &p[i + 1], len - i - 1);

    return 0;

}
static void _vm_preload_clean_and_free_ctx(vm_preload_ctx_t * ctx_p, void *data)
{
    PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
        ctx_p->cb, ctx_p->res_id, data);
    //_vm_preload_clean(ctx_p);
    _vm_preload_free_ctx(ctx_p);
}

static void _vm_preload_read_address(vm_preload_ctx_t * ctx_p)
{
    //VMCHAR http_header[BUFFER_LEN*2] = {0};
    //VMCHAR http_buffer[BUFFER_LEN] = {0};
    static VMINT len = 0;
    static VMINT wblock = 0;
    VMINT i = 0, j = 0;
    VMINT http_header_received = 0;
    VMINT http_content_downloaded = 0;
    VMINT http_content_length = 0;
    VMINT http_header_len = 0;
    VMINT file_handle = -1;
    VMINT ret = 0;
    VMINT feed_back = 0;
    VMBYTE * http_header = NULL; 
    static VMBYTE * buf = NULL;
    vm_common_t head = {E_PRELOAD_QUERYING, NULL};
    const VMCHAR * http_ver = "HTTP/1.1 ";

    // read block
    if (!wblock)
    {
        buf = (VMBYTE *)_vm_kernel_malloc(2*BUFFER_LEN);
        memset(buf, 0, sizeof(2*BUFFER_LEN));
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3223 );			
    while ((ret = vm_tcp_read (ctx_p->soc_id, buf + len, 2*BUFFER_LEN - len)) > 0)
    {
        len += ret;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3227 , ret, len);         
    }
    
    // read block
    http_header = _vm_kernel_malloc(BUFFER_LEN); 
    memset(http_header, 0, sizeof(BUFFER_LEN));
    for(i = 0; i < len; i++)
    {
        http_header[http_header_len++] = buf[i];
        if (http_header_len >= 2)
        {
            if (http_header[http_header_len - 1] == LF && http_header[http_header_len - 2] == CR)
            {
                if (http_header_len == 2) // 2
                {
                    http_content_downloaded += len - i - 1;
                    j = i + 1;
                    //data.received += len - i - 1;
                }
                else // 1
                {
                    http_header_len = 0;
                    if (app_strnicmp((kal_char *)http_header, (kal_char *)CONTENT_LENGTH, strlen(CONTENT_LENGTH)) == 0)
                    {
                        //http_header[http_header_len - 2] = '\0';
                        http_content_downloaded = 0;
                        http_content_length = atoi((const char *)http_header + strlen(CONTENT_LENGTH) + 1);

                    }

                    if (0 == app_strnicmp((kal_char*)http_header, (kal_char*)http_ver, strlen(http_ver)))
                    {
                        feed_back = atoi((const char *)http_header + strlen(http_ver));
                    }

                }
            }
        }
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3264 , http_content_length, feed_back);
    // read block
    if (http_content_length > http_content_downloaded)
    {
        // recveived partitial data.
        wblock = 1;
        //_vm_preload_read_address(ctx_p);
        _vm_kernel_free(http_header);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3227 , -2, len);         
        return;
    }
    else // not read block
    {
        wblock = 0;
        len = 0;
    }

    //if (200 == feed_back) 
    {
        // judge whether the url belong to the g-mobi(some times operator will rsp to client fristly when with wap.
        VMINT pos = 0, ctx_len = http_content_downloaded < http_content_length ? http_content_downloaded - 1 : http_content_length;
        while (0 != *(buf + j + pos) && pos < ctx_len)
        {
            if (*(buf + j + pos) == '\r' && *(buf + j + pos + 1) == '\n')
                break;
        
            pos++;
        }
        
        *(buf + j + pos) = 0;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3284 , buf + j);         
        if (vm_preload_is_url_valid((const VMCHAR *)buf + j, ctx_p))//if (0 == strstr(buf + j, "go href")) // confirm the data form server.
        {
            ctx_p->twice_confirmed = 1;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3287 );
            if (200 == feed_back && 0 < http_content_length)
                ctx_p->update = 1;
        }
    }


    if (ctx_p->update)
    {
        strncpy((char*)ctx_p->url, (const char*)buf + j, http_content_length);
        //strcpy(ctx_p->url, buf + 2);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3297 );         
        head.state = E_PRELOAD_AVAILABLE_UPDATE;
        if (ctx_p->soc_id > 0)
        {
            vm_tcp_close(ctx_p->soc_id);
            ctx_p->soc_id = -1;
        }
    }
    else
    {
        head.state = E_PRELOAD_NO_UPDATE;
        ctx_p->status = (VMINT)E_PRELOAD_NO_UPDATE;
        if (0 == ctx_p->twice_confirmed)
        {
            _vm_preload_try_query(ctx_p);
            ctx_p->twice_confirmed = 1;
            _vm_kernel_free(buf);
            _vm_kernel_free(http_header);
            return;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3318 );         
        head.user_data = ctx_p->user_data;
        _vm_preload_clean_and_free_ctx(ctx_p, &head);
        _vm_kernel_free(buf);
        _vm_kernel_free(http_header);
        return;
    }
    
    head.user_data = ctx_p->user_data;
    PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
        ctx_p->cb, ctx_p->res_id, (void*)&head);

    _vm_kernel_free(buf);
    _vm_kernel_free(http_header);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3335 );			
}

static void _vm_preload_read_data(vm_preload_ctx_t * ctx_p)
{
    VMCHAR *body = (VMCHAR *)_vm_kernel_calloc(BUFFER_LEN);
    //VMCHAR http_buffer[BUFFER_LEN] = {0};
    VMINT len = 0, i = 0;
    VMINT http_header_received = 0;
    VMINT first_downloaded = 0;
    VMINT http_header_len = 0;
    VMINT file_handle = -1;
    VMINT ret = 0;
    VMBYTE * buf = NULL;
    VMFILE f_handle = -1;
    VMUINT written = 0;
    vm_preload_recv_data_t data = {{E_PRELOAD_QUERYING, NULL}, 0, 0}; 

    
    data.head.user_data = ctx_p->user_data;

    //memset(buf, 0, sizeof(2*BUFFER_LEN));

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3358 , ctx_p->g_http_content_length);       

    // read the header
    if (0 == ctx_p->g_http_content_length)
    {
        
        buf = (VMBYTE *)_vm_kernel_malloc(BUFFER_LEN);
        memset(buf, 0, sizeof(BUFFER_LEN));
        while ((ret = vm_tcp_read (ctx_p->soc_id, buf + len, BUFFER_LEN - len)) > 0)
        {
            len += ret;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3369 , ret, len);         
        }
        
        for(i = 1; i < len; i++)
        {
            if (buf[i] == LF && buf[i - 1] == CR)
            {
                if (app_strnicmp((kal_char *)&buf[http_header_len], (kal_char *)CONTENT_LENGTH, strlen(CONTENT_LENGTH)) == 0)
                {
                    buf[i - 1] = '\0';
                    first_downloaded = 0;
                    ctx_p->g_http_content_length = atoi((const char *)&buf[http_header_len] + strlen(CONTENT_LENGTH) + 1);
                    ctx_p->need_recv_len = ctx_p->g_http_content_length;
                    //data.total = http_content_length;I
                    
                    ctx_p->update = 1;
                }

                http_header_len = i + 1;

                if ((i + 2) < len && 
                (buf[i + 2] == LF && buf[i + 1] == CR))
                {
					http_header_len += 2;
                    first_downloaded = len - http_header_len;					
					break;
                }
            }
        }
        
        //strncpy(body, buf + 2, first_downloaded);
        memcpy(body, &buf[http_header_len], first_downloaded);
        _vm_kernel_free(buf);
        
        // preparing file
        f_handle = vm_file_open(ctx_p->path, MODE_READ, 1);
        if (0 <= f_handle)
        {
            vm_file_close(f_handle);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3411 );
            vm_file_delete(ctx_p->path);
        }
        f_handle = vm_file_open(ctx_p->path, MODE_CREATE_ALWAYS_WRITE, 1);
    }

    // preparing file
    if (0 > f_handle)
    {
        f_handle = vm_file_open(ctx_p->path, MODE_APPEND, 1);
    }

    if (0 > f_handle)
    {
        VMCHAR buf[260];
        vm_ucs2_to_ascii(buf, 260, ctx_p->path);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3429 , buf);
        data.head.state = E_PRELOAD_ERR_PATH;
        ctx_p->status = E_PRELOAD_ERR_PATH;
        _vm_preload_clean_and_free_ctx(ctx_p, &data);
        _vm_kernel_free(body);
        return;
    }

    // no disk space
    {
        VMWCHAR drv_wname[4] = {0};  
        VMUINT size = 0;
        vm_wstrncpy(drv_wname, ctx_p->path, 1);
        size = vm_get_disk_free_space(drv_wname);

        if (size < (VMUINT)ctx_p->g_http_content_length)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3429 , (VMCHAR*)drv_wname);
            data.head.state = E_PRELOAD_FAILURE;
            ctx_p->status = E_PRELOAD_FAILURE;
            if (0 <= f_handle)
            {
                vm_file_close(f_handle);
				vm_file_delete(ctx_p->path);
            }               
            _vm_preload_clean_and_free_ctx(ctx_p, &data);
            _vm_kernel_free(body);
            return;
        }
     
    }


    do
    {
        len = first_downloaded;

        while ((ret = vm_tcp_read (ctx_p->soc_id, body + len, 
            (ctx_p->g_http_content_length > BUFFER_LEN ? BUFFER_LEN : ctx_p->g_http_content_length) - len)) > 0)
        {
            // would block
            if (0 == ret)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3448 );
                break;
            }
            len += ret;
            if (BUFFER_LEN == len)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3454 );
                break;
            }
        }
        
        ctx_p->g_http_content_length -= len;
        first_downloaded = 0;
    
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3462 , len);            
        data.head.state = E_PRELOAD_DOWNLOADING;
        ctx_p->status = (VMINT)E_PRELOAD_DOWNLOADING;
        data.total = ctx_p->need_recv_len;
        data.received = ctx_p->need_recv_len - ctx_p->g_http_content_length;
        //data.buf = body;
        //data.size = len;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3469 , data.received, data.total);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3470 );

        vm_file_write(f_handle, body, len, &written);
    
        PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
            ctx_p->cb, ctx_p->res_id, (void*)&data);
        
    } while (BUFFER_LEN == len && 0 != ret); // would block break

    vm_file_close(f_handle);

    if (0 == ctx_p->g_http_content_length)
    {
        data.head.state = E_PRELOAD_DOWNLOADED;
        ctx_p->status = (VMINT)E_PRELOAD_DOWNLOADED;
        data.total = ctx_p->g_http_content_length;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3485 , data.total);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3486 );
        _vm_preload_clean_and_free_ctx(ctx_p, &data);
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
    
    _vm_kernel_free(body);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3582 );            
}

static VMINT _vm_preload_check_valid(vm_preload_ctx_t * ctx_p)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_preload_ctx_t * ctx_tmp_p = NULL;
    VMINT found = 0;
    do
    {
        if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_PRELOAD)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
                resHandle, (void**)&ctx_tmp_p, &bufSize) == 0 && ctx_tmp_p != NULL)
            {
                if (ctx_tmp_p == ctx_p)
                {
                    vm_res_findclose(VM_RES_TYPE_PRELOAD);
                    found = 1;
                    break;
                }
            }

            while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_PRELOAD)) != VM_RES_NOT_FIND)
            {
                if (vm_res_get_data(VM_RES_TYPE_PRELOAD, 
                resHandle, (void**)&ctx_tmp_p, &bufSize) == 0 && ctx_tmp_p != NULL)
                {
                    if (ctx_tmp_p == ctx_p)
                    {
                        found = 1;
                        break;
                    }
                }
            }
            vm_res_findclose(VM_RES_TYPE_PRELOAD);
        }	
    }
    while (0);

    return found;
}

static void _vm_preload_clean(vm_preload_ctx_t * ctx_p)
{
    VMINT found = 0;

    found = _vm_preload_check_valid(ctx_p);

    if (found)
    {
        if (E_PRELOAD_DOWNLOADED != ctx_p->status)
        {
            vm_file_delete(ctx_p->path);
        }
        if (0 < ctx_p->soc_id)
        {
            vm_tcp_close(ctx_p->soc_id);
        }
        memset(ctx_p, 0, sizeof(vm_preload_ctx_t));
        //ctx_p->p_hdl = 0;
        ctx_p->soc_id = -1;
        //ctx_p->res_id = -10;
    }
}

static void _vm_preload_cb(VMINT handle, VMINT event)
{	    
    vm_common_t common = {E_PRELOAD_QUERYING, NULL};

    vm_preload_ctx_t * ctx_p = NULL;

    ctx_p = _vm_preload_get_ctx((VM_P_HANDLE)-1, handle, 1);
    
    // vm_preload_cancel check
    if (NULL == ctx_p)
    {
        return;
    }
    
    common.user_data = ctx_p->user_data;

    switch (event)
    {
    case VM_TCP_EVT_HOST_NOT_FOUND : 
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3622 );
            common.state = E_PRELOAD_HOST_NOT_FOUND;
            ctx_p->status = (VMINT)E_PRELOAD_HOST_NOT_FOUND;
            _vm_preload_clean_and_free_ctx(ctx_p, &common);
        }break;
    case VM_TCP_EVT_CONNECTED : 
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3630 );
            //_set_status(HTTP_STATUS_CONNECTED);
            if (0 == ctx_p->update)
            {
                common.state = E_PRELOAD_CONNECTED;
                PRELOAD_PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    ctx_p->cb, ctx_p->res_id, (void*)&common);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3637 );			
                // vm_preload_cancel check
                if (ctx_p->cb)
                {
                    _vm_preload_try_query(ctx_p);
                }
            }
            else
            {
                vm_preload_download_ex(ctx_p->res_id, ctx_p->path, ctx_p->bDLA,ctx_p->cb, ctx_p->user_data);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3643 );			
            }
        
        }break;
    case VM_TCP_EVT_CAN_WRITE :
        { 
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3649 );
            //vm_tcp_write(handle, layer_buffer,length);
        }break;
    case VM_TCP_EVT_CAN_READ :
        {
            if (0 == ctx_p->update)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3656 );
                _vm_preload_read_address(ctx_p);
                //ctx_p->update = 1;
            }
            else
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3662 );
                _vm_preload_read_data(ctx_p);
                //ctx_p->update = 0;
            }
            
        }break;
    case VM_TCP_EVT_PIPE_BROKEN :
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3670 );
            common.state = E_PRELOAD_PIPE_BROKEN;
            ctx_p->status = (VMINT)E_PRELOAD_PIPE_BROKEN;
            _vm_preload_clean_and_free_ctx(ctx_p, &common);
        }break;
    case VM_TCP_EVT_PIPE_CLOSED :
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3678 );
            
            common.state = E_PRELOAD_PIPE_CLOSED;
            ctx_p->status = (VMINT)E_PRELOAD_PIPE_CLOSED;
            _vm_preload_clean_and_free_ctx(ctx_p, &common);
        }break;
    default:
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_3689 );
            common.state = E_PRELOAD_FAILURE;
            ctx_p->status = (VMINT)E_PRELOAD_FAILURE;
            _vm_preload_clean_and_free_ctx(ctx_p, &common);
        }break;
    }
}


#endif /* __MRE_SAL_SOCKET__ */
