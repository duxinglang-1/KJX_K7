
#ifndef __GS_MEMORY_H
#define __GS_MEMORY_H

#include "MMIDataType.h"

#define GS_MAX_CONCURRENT_QUERY_NUMBER 20 

typedef void* (*gs_alloc_type)(U32 size); 
typedef void (*gs_free_type)(void * ptr);
typedef void (*gs_destroy_callback)(void *obj);
typedef void (*gs_create_callback)(void *obj);


typedef struct
{
	gs_alloc_type gs_alloc_internal;
	gs_free_type gs_free_internal;
	gs_destroy_callback gs_destroy_internal;
	gs_create_callback gs_create_internal;
}gs_mem_manage;


void* gs_alloc(U32 size);
void gs_free(void * ptr);
void gs_free_proxy(void * ptr);

void srv_service_mem_init(const gs_mem_manage * mem,U32 handle);
void gs_assert(int condition);
void gs_memory_set_handle(U32 handle);
void gs_destroy_service_callback(void *obj );
void gs_create_service_callback(void *obj);
MMI_BOOL gs_is_MRE_free();

#endif

