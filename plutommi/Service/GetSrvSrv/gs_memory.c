
#include "gs_memory.h"
#include "vmlog.h"
#include "mmi_include.h"
#include "vmsys.h"


typedef struct
{
 	S32 handle;
 	gs_free_type gs_free_internal;
	gs_destroy_callback gs_destroy_internal;
}gs_mem_storage;

U32 gs_running_handle ;
S32 gs_index;
gs_mem_storage gs_mem_storage_array[GS_MAX_CONCURRENT_QUERY_NUMBER];
gs_alloc_type gs_alloc_internal;
gs_create_callback gs_create_internal;




void gs_memory_set_handle(U32 handle)
{

	gs_running_handle = handle;
}


U32 gs_memory_get_handle(void)
{

	return gs_running_handle;
}



void srv_service_mem_init( const gs_mem_manage *mem ,U32 handle)
{
    int i=0;

	gs_memory_set_handle(handle);
	gs_alloc_internal = mem->gs_alloc_internal ;
	gs_create_internal = mem->gs_create_internal;
	//find position
   for (i=0;i < GS_MAX_CONCURRENT_QUERY_NUMBER;i++)
   {
		if (gs_mem_storage_array[i].handle == 0)
			break;
   }

   gs_assert(i<=GS_MAX_CONCURRENT_QUERY_NUMBER);

	//store API
	gs_mem_storage_array[i].gs_free_internal = mem ->gs_free_internal;
	gs_mem_storage_array[i].handle = handle;
	gs_mem_storage_array[i].gs_destroy_internal = mem->gs_destroy_internal;

}

void gs_destroy_service_callback(void *obj )
{

	if(gs_mem_storage_array[gs_index].gs_destroy_internal != NULL)
	{
		gs_mem_storage_array[gs_index].gs_destroy_internal(obj);
		return;
	}
	else
	{
		return;
	}

}


void gs_create_service_callback(void *obj)
{
	if(gs_create_internal != NULL)
	{
		gs_create_internal(obj);
	}
}



S32 gs_memory_find_index (U32 handle)
{
 	S32 i=0;
	for(i=0;i<GS_MAX_CONCURRENT_QUERY_NUMBER ;i++)
    {
		if(gs_mem_storage_array[i].handle == handle)
			return i;
	}
	 gs_assert(i<=GS_MAX_CONCURRENT_QUERY_NUMBER);
}

void* gs_alloc(U32 size)
{
	 //MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_ALLOC_MEM,size,gs_running_handle); 
 	 return gs_alloc_internal(size);
}

void gs_free(void * ptr)
{
	//MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_FREE_MEM,ptr,gs_running_handle,gs_index); 
	if(ptr!= NULL)
	{
		gs_mem_storage_array[gs_index].gs_free_internal(ptr);
		gs_mem_storage_array[gs_index].handle =0;
	}
}

void gs_free_proxy(void * ptr)
{

	gs_index=gs_memory_find_index (gs_running_handle);
	//MMI_TRACE(MMI_MRE_TRC_G6, TRC_MMI_GETSRV_FREE_PROXY_MEM,ptr,gs_running_handle,gs_index);
    if(ptr != NULL)
    {
		gs_mem_storage_array[gs_index].gs_free_internal(ptr);
    }
}


void gs_assert(int condition)
{
    ASSERT(condition);
}

MMI_BOOL gs_is_MRE_free()
{
    gs_index=gs_memory_find_index (gs_running_handle);

	if (vm_free == gs_mem_storage_array[gs_index].gs_free_internal)
	{
	    return MMI_TRUE;
	}
	else
	    return MMI_FALSE;
    return MMI_FALSE;
}

