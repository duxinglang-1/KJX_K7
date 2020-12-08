#include "mmi_features.h"
#ifdef __MMI_QUERY_SRV__

#include "gs_base.h"
#include "gs_cbase.h"
#ifdef __cplusplus
extern "C"
{
#include "vmsys.h"
#include "vmresmng.h"
#include "vmpromng.h" 
#include "vmlog.h"
#include "gs_id.h"
void *_vm_kernel_calloc(int size);
void _vm_kernel_free(void* ptr);

}
#endif
    

typedef struct _srv_node_struct
{
    VMINT id;
    void* ptr;
    struct _srv_node_struct* next_cls;
    U8      deleting;
//    struct _srv_node_struct* next_i;
}srv_node_struct;

extern void vm_srv_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state);

srv_node_struct* vm_srv_get_service(VMINT clsid,VMINT handle)
{
    srv_node_struct* resdata;
	VMINT size=4;
    VMINT res;

	res = vm_res_findfirst(handle,VM_RES_TYPE_GET_SERVICE);
	if (VM_RES_NOT_FIND != res)
	{
        if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_GET_SERVICE, res, (void**)&resdata, &size))
    	{
    	    while (resdata != NULL)
    	    {
    	        if (clsid == -1)
    	        {
    	            return resdata;
    	        }
    	        if (clsid == resdata->id)
    	        {
    	            return resdata;
    	        }
    	        resdata = resdata->next_cls;
    	    }
    	}
	}
	return NULL;
}

srv_node_struct* vm_srv_get_service_ex(void* ptr)
{
    srv_node_struct* resdata;
	VMINT res;
    VMINT size = 4;

	res = vm_res_findfirst(-1,VM_RES_TYPE_GET_SERVICE);
    while (VM_RES_NOT_FIND != res)
    {
        if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_GET_SERVICE,res,(void**)&resdata,&size))
        {
            if (resdata->ptr == ptr)
            {
                return resdata;
            }
        }
        res = vm_res_findnext(-1,VM_RES_TYPE_GET_SERVICE);
    }
	return NULL;
}

/*
srv_node_struct* vm_srv_get_interface(VMINT iid,srv_node_struct* servie)
{
    srv_node_struct* resdata = servie;
	VMINT size=4;
 
    while (resdata != NULL)
    {
        if (iid == resdata->id)
        {
            return resdata;
        }
        resdata = resdata->next_i;
    }
	return NULL;
}
*/
VMINT vm_srv_save_service(VMINT clsid,void* ptr,VMINT handle)
{
    srv_node_struct* resdata;
	VMINT size=4;
    VMINT res;
    
	srv_node_struct* service =(srv_node_struct* )_vm_kernel_calloc(sizeof(srv_node_struct));
	if (!service)
	{
	    return -2;
    }
    service->id = clsid;
    service->ptr = ptr;
    


	res = vm_res_findfirst(handle,VM_RES_TYPE_GET_SERVICE);
	if (VM_RES_NOT_FIND != res)
	{
        if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_GET_SERVICE, res, (void**)&resdata, &size))
    	{
    	    ASSERT(resdata);
    	    while (resdata->next_cls != NULL)
    	    {
    	        resdata = resdata->next_cls;
    	    }
    	    resdata->next_cls = service;
    	}
	}
	else
	{
	    vm_res_save_data(VM_RES_TYPE_GET_SERVICE, service,4, NULL, handle);
	    vm_res_type_set_notify_callback(VM_RES_TYPE_GET_SERVICE,  (vm_res_release_callback_t)vm_srv_notify_callback);
	}
	return 0;
}
/*
VMINT vm_srv_save_interface(VMINT clsid,VMINT iid,void* ptr,VMINT handle)
{
    srv_node_struct* service;
    srv_node_struct* pinterface;
	VMINT size=4;

    service = vm_srv_get_service(clsid,handle);
    if (!service)
    {
        return -3;
    }
	pinterface = vm_calloc(sizeof(srv_node_struct));
	if (!pinterface)
	{
	    return -2;
    }
    pinterface->id = iid;
    pinterface->ptr = ptr;
    
    while (service->next_i != NULL)
    {
        service = service->next_i;
    }
    service->next_i = pinterface;
    
	return 0;
}
*/
VMINT vm_srv_delete_service(srv_node_struct* service)
{
    srv_node_struct* resdata;
	VMINT res;
    VMINT size = 4;
    
    if (!service)
    {
        return -1;
    }

    if (service->deleting)
    {
        return 0;
    }
    
    service->deleting = 1;
    
    while (((GS_CBase*)service->ptr)->release()!= 0)
    {
    };
    
/*    while(service->next_i)
    {
        srv_node_struct* tmp = service->next_i;
        service->next_i = tmp->next_i;
        vm_free(tmp);
    }*/
    
    if (service->next_cls)
    {
        memcpy(service,service->next_cls,sizeof(srv_node_struct));
        _vm_kernel_free(service->next_cls);
    }
    else
    {
    	res = vm_res_findfirst(-1,VM_RES_TYPE_GET_SERVICE);
        while (VM_RES_NOT_FIND != res)
        {
            if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_GET_SERVICE,res,(void**)&resdata,&size))
            {
                if (resdata == service)
                {
                     _vm_kernel_free(service);
                    return vm_res_release_data(VM_RES_TYPE_GET_SERVICE,res);
                }
            }
            res = vm_res_findnext(-1,VM_RES_TYPE_GET_SERVICE);
        }
        
    }  
}
/*
VMINT vm_srv_delete_interface(srv_node_struct* pinterface,VMINT handle)
{    
    if (pinterface->next_i)
    {
        memcpy(pinterface,pinterface->next_i,sizeof(srv_node_struct));
        vm_free(pinterface->next_i);
    }
    else
    {
        vm_free(pinterface);
    }    
}
*/
void vm_srv_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    srv_node_struct* node;
    
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        while((node = vm_srv_get_service(-1,process_handle))!= NULL)
        {
            vm_srv_delete_service(node);
        };
        break;
    default:
        break;
    }
}

void vm_srv_destroy_service_cb(void *obj)
{
    srv_node_struct* node;
    
    node = vm_srv_get_service_ex(obj);
    vm_srv_delete_service(node);
}

void vm_srv_create_service_cb(void *obj)
{

}

extern "C" VMINT vm_create_service(VMINT clsid, VMINT iid, void ** pptr)

{   
	VMINT  ret = -1;
	gs_mem_manage mem;
	U8* resdata;
	VMINT size=4;
	int i;
	VM_P_HANDLE handle;
	srv_node_struct* service,pinterface;
	
    kal_prompt_trace(MOD_MMI,"vm_create_service begin");
    vm_log_debug("vm_create_service begin");        
	mem.gs_alloc_internal=(gs_alloc_type)vm_malloc;
	mem.gs_free_internal=vm_free;
    mem.gs_destroy_internal= vm_srv_destroy_service_cb;
	mem.gs_create_internal = vm_srv_create_service_cb;

    if (!pptr)
    {
        return -2;
    }    
    handle = vm_pmng_get_current_handle();

    service = vm_srv_get_service(clsid,handle);
    if (service)
    {
	    return ((GS_CBase*)service->ptr)->queryInterface(iid, (GS_IBase**)pptr)?0:-2;;
    }
	
	ret = srv_create_service(clsid,(GS_IBase**) pptr,&mem);
    if (ret)
    {
        return -3;
    }

    ret = vm_srv_save_service(clsid,*pptr,handle);

    if (ret)
    {
        return -4;
    }

    if (((GS_CBase*)*pptr)->queryInterface(iid, (GS_IBase**)pptr))
    {
        return 0;
    }
	return -5;
}

#else
extern "C" VMINT vm_create_service(VMINT clsid, VMINT iid, void ** pptr)
{
    return -1;
}
#endif
