/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_mem.h
 *
 * Created by Anders Edenbrandt, Wed Sep 26 09:59:07 2001.
 *
 *
 * Revision history:
 *   020402, IPN: Changed to fit Mobile Suite Framework.
 *   021014, IPN: Fixed the internal memory allocator to fit MSF.
 *   021014, IPN: Added an exception function parameter in msf_mem_init.
 *
 */
#ifndef _msf_mem_h
#define _msf_mem_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cfg_h
#include "msf_cfg.h"
#endif

/************************************************************
 * Macros
 ************************************************************/

#define MSF_MEM_INIT                  gmms_msf_mem_init
#define MSF_MEM_FREE_ALL              gmms_msf_mem_free_all

#ifdef MSF_LOG_MEM_ALLOC

#define MSF_MEM_ALLOC(id, s)          gmms_msf_mem_alloc (id, s, __FILE__, __LINE__)
#define MSF_MEM_ALLOCTYPE(id, t) (t *)gmms_msf_mem_alloc (id, sizeof (t), __FILE__, __LINE__)
#define MSF_MEM_FREE(id, p)           gmms_msf_mem_free (id, p, __FILE__, __LINE__)
#define MSF_MEM_CALLOC(id,n,s)        gmms_msf_mem_calloc (id, n, s, __FILE__, __LINE__)

#else

#define MSF_MEM_ALLOC(id, s)          gmms_msf_mem_alloc (id, s)
#define MSF_MEM_ALLOCTYPE(id, t) (t *)gmms_msf_mem_alloc (id, sizeof (t))
#define MSF_MEM_FREE(id, p)           gmms_msf_mem_free (id, p)
#define MSF_MEM_CALLOC(id, n, s)      gmms_msf_mem_calloc (id, n, s)

#endif

#define MSF_MEM_GET_SIZE              gmms_msf_mem_get_size

#define MSF_MEM_GET_AVAILABLE_FREE_MEMORY              HDIa_getAvailableFreeMemory
/************************************************************
 * Typedef
 ************************************************************/

typedef void msf_mem_exception_func_t (void);


/************************************************************
 * Functions
 ************************************************************/

#ifdef MSF_LOG_MEM_ALLOC
void *
gmms_msf_mem_alloc (MSF_UINT8 modId, MSF_UINT32 size, const char *filename, int lineno);
#else
void *
gmms_msf_mem_alloc (MSF_UINT8 modId, MSF_UINT32 size);
#endif

#ifdef MSF_LOG_MEM_ALLOC
void
gmms_msf_mem_free (MSF_UINT8 modId, void *p, const char *filename, int lineno);
#else
void
gmms_msf_mem_free (MSF_UINT8 modId, void *p);
#endif

#ifdef MSF_LOG_MEM_ALLOC
void *
gmms_msf_mem_calloc (MSF_UINT8 modId, int num, MSF_UINT32 size, const char *filename, int lineno);
#else
void *
gmms_msf_mem_calloc (MSF_UINT8 modId, int num, MSF_UINT32 size);
#endif

MSF_UINT32
gmms_msf_mem_get_size (void *mem);

MSF_UINT32
gmms_msf_mem_allocated_bytes (MSF_UINT8 modId);

void
gmms_msf_mem_free_all (MSF_UINT8 modId);

/*
 * Initialise the memory handler. The parameter exceptionHandler is
 * a pointer to an exception function. This function is called when
 * a memory allocation is failed. If the module doesn't have any
 * exception function, set exceptionHandler to NULL, which results
 * in when a memory allocation is failed NULL is returned.
 *
 */
void
gmms_msf_mem_init (MSF_UINT8 modId, msf_mem_exception_func_t* exceptionHandler);

#ifdef MMS_V02_USE_ASM

void gmms_msf_set_mms_app_mem_pool(void *base_addr, MSF_UINT32 pool_size);
void gmms_msf_reset_mms_app_mem_pool(void);

#define MSF_SET_MMS_APP_MEM_POOL gmms_msf_set_mms_app_mem_pool
#define MSF_RESET_MMS_APP_MEM_POOL  gmms_msf_reset_mms_app_mem_pool
#endif

#endif
