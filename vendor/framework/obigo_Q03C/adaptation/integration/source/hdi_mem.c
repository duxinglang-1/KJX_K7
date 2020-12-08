/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   hdi_mem.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating Obigo memory APIs.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if !defined(__MTK_TARGET__) && defined(__MTK_INTERNAL__)
/* under construction !*/
#endif

#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
#include <windows.h>
#endif
#include "msf_def.h"
#include "msf_int.h"
#include "msf_cfg.h"
#include "msf_env.h"
#include "msf_chrs.h"
#include "int_cmmn.h"
#include "mma_mem_cfg.h"
#include "kal_public_api.h"
#include "kal_adm.h"


#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "int_exec.h"
#endif

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
#define HDI_MEM_DEBUG
#else
    #ifdef WAP_MEM_DEBUG
        #define HDI_MEM_DEBUG
    #endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    #define HDI_SYS_MEM_SIZE (MMS_SYS_MEM_SIZE+WAP_MEM_SIZE)
    #define HDI_SYS_MEM_POOL WAP_MEM_POOL
    #define HDI_MEM_POOL_NUM WAP_MEM_POOL_NUM
#else
    #define HDI_SYS_MEM_SIZE MMS_SYS_MEM_SIZE
    #define HDI_SYS_MEM_POOL MMS_V02_SYS_MEM_POOL
    #define HDI_MEM_POOL_NUM MMS_MEM_POOL_NUM
#endif

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif
#endif

static unsigned int mms_sys_mem[HDI_SYS_MEM_SIZE / sizeof(unsigned int)];

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif
#endif

/* Number of dwords in header/footer guard patterns
   Ex: HDI_MEM_GUARD_PATTERN_LEN is 1 -> 4 byte. 
   Increasing the length may help catch memory corruption  */
#define HDI_MEM_GUARD_PATTERN_LEN             (1)

/* Guard pattern in header of allocated chunk */
#define HDI_MEM_HEADER_PATTERN1          (0xbbbbbbbb)
/* Guard pattern in header of released chunk */
#define HDI_MEM_HEADER_PATTERN2          (0xdddddddd)
/* Guard pattern in footer of allocated chunk */
#define HDI_MEM_FOOTER_PATTERN1          (0xcccccccc)
/* Guard pattern in footer of released chunk */
#define HDI_MEM_FOOTER_PATTERN2          (0xeeeeeeee)

MSF_UINT32 gmms_hdi_mem_allocated_bytes(MSF_UINT8 modId);

#ifdef HDI_MEM_DEBUG
/* Header of a chunk (4n bytes) */
typedef struct hdi_mem_header_t
{
    MSF_UINT32 guard_pattern[HDI_MEM_GUARD_PATTERN_LEN];     /* guard pattern */
    struct hdi_mem_header_t *prev;                         /* previous allocated chunk */
    struct hdi_mem_header_t *next;                         /* next allocated chunk */
    MSF_UINT32 chunk_size;                                 /* allocated size round to 4 */
    MSF_UINT32 line;
    const char *filename;
} hdi_mem_header_struct;

/* Footer of a chunk (4n bytes) */
typedef struct
{
    MSF_UINT32 guard_pattern[HDI_MEM_GUARD_PATTERN_LEN];     /* guard pattern */
} hdi_mem_footer_struct;

typedef struct
{
    MSF_UINT32 allocated_bytes;
    MSF_UINT32 allocated_bytes_with_header;
    MSF_UINT32 max_allocated_bytes;
} memory_info_struct;
#endif /* defined(HDI_MEM_DEBUG) */

typedef struct memory_pool_st
{
    KAL_ADM_ID adm_id;
    MSF_UINT32 total_bytes;
    void *pool_addr;
#ifdef HDI_MEM_DEBUG
    hdi_mem_header_struct *head;
    memory_info_struct mod_mem_info[MSF_NUMBER_OF_MODULES];
#endif /* HDI_MEM_DEBUG */
} memory_pool_struct;

#ifndef HDI_MEM_DEBUG
typedef struct memory_info_st
{
    struct memory_info_st *next;
    MSF_UINT32  size;
}memory_info_struct;
#endif /*HDI_MEM_DEBUG*/

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif 
#endif


static kal_mutexid hdi_mem_mutex = NULL;

#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    FILE *mem_track = NULL;
#endif

static memory_pool_struct mem_pool[HDI_MEM_POOL_NUM] = {0};

#ifndef HDI_MEM_DEBUG
memory_info_struct* hdi_pool_mem_info[MSF_NUMBER_OF_MODULES] = {0};
#endif /*HDI_MEM_DEBUG*/

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif
#endif

#ifdef MSF_NEW_EXCEPTION_HANDLING
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
MSF_UINT8 MALLOC_EXCEPTION = 0;

static void HDIa_memSetException(MSF_UINT8 modId)
{
	MALLOC_EXCEPTION |= 1<<msf_modules[modId].memPoolId;
}

MSF_UINT8 HDIa_memGetException()
{
	if(MALLOC_EXCEPTION & (1<<WAP_MEM_POOL))
		return WAP_MEM_POOL;
#ifdef WAP_USE_ASM
	if(MALLOC_EXCEPTION & (1<<WAP_APP_MEM_POOL))
		return WAP_APP_MEM_POOL;
#endif
#ifdef MMS_V02_USE_ASM
	if(MALLOC_EXCEPTION & (1<<MMS_V02_APP_MEM_POOL))
		ASSERT(0);
#endif
return WAP_MEM_POOL_NUM;
}

static void HDIa_memClearException(MSF_UINT8 pool_id)
{
	MALLOC_EXCEPTION &= ~(1 << pool_id);
}
#endif
#endif

/* for KAL ADM */
static const kal_uint32 hdi_mem_pool_chunk_size[11] = 
{
    16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 0xffffffff, 0
};

#ifdef HDI_MEM_DEBUG
#define HDI_SIZE_OF_HEAD (sizeof(hdi_mem_header_struct) + sizeof(hdi_mem_footer_struct))
#else
#define HDI_SIZE_OF_HEAD (sizeof(memory_info_struct))
#endif /*HDI_MEM_DEBUG*/

void HDIa_memDumpMemUsageToFile(void);

#ifdef HDI_MEM_DEBUG
/****************************************************************************
 * FUNCTION
 *  HDI_MEM_SET_PATTERN
 * DESCRIPTION
 *  Fill guard pattern
 * PARAMETERS
 *  ptr         [OUT]       data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  void
 *****************************************************************************/
#if HDI_MEM_GUARD_PATTERN_LEN == 1
#define HDI_MEM_SET_PATTERN(ptr, pattern)  do {(*ptr) = (pattern);} while (0)
#else /* HDI_MEM_GUARD_PATTERN_LEN == 1 */
static void HDI_MEM_SET_PATTERN(MSF_UINT32 *ptr, MSF_UINT32 pattern)
{
    MSF_UINT32 i;
    for (i = 0; i < HDI_MEM_GUARD_PATTERN_LEN; i++)
    {
        ptr[i] = pattern;
    }
}
#endif /* HDI_MEM_GUARD_PATTERN_LEN == 1 */


/*****************************************************************************
 * FUNCTION
 *  HDI_MEM_COMP_PATTERN
 * DESCRIPTION
 *  Compare if the guard pattern is correct
 * PARAMETERS
 *  ptr         [IN]        data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  return KAL_FALSE if the guard pattern is corrupted
 *****************************************************************************/
#if HDI_MEM_GUARD_PATTERN_LEN == 1
#define HDI_MEM_COMP_PATTERN(ptr, pattern)  ((*ptr >> 8) == (pattern >> 8))
#else /* HDI_MEM_GUARD_PATTERN_LEN == 1 */
static int HDI_MEM_COMP_PATTERN(const MSF_UINT32 *ptr, MSF_UINT32 pattern)
{
    MSF_UINT32 i;
    for (i = 0; i < HDI_MEM_GUARD_PATTERN_LEN; i++)
    {
        if (i == HDI_MEM_GUARD_PATTERN_LEN - 1)
        {
            if ((ptr[i] >> 8) != (pattern >> 8))
            {
                return 0;
            }
        }
        else if (ptr[i] != pattern)
        {
            return 0;
        }
    }
    return 1;
}
#endif /* HDI_MEM_GUARD_PATTERN_LEN == 1 */
#endif /* HDI_MEM_DEBUG */

/*****************************************************************************
 * FUNCTION
 *  init_memory_pool
 * DESCRIPTION
 *  To initialize specified memory pool for ADM use.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void init_memory_pool(MSF_UINT8 poolId, void *memory_addr, MSF_UINT32 pool_size)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_take_mutex(hdi_mem_mutex);
    
    ASSERT(memory_addr);
    ASSERT(pool_size);

#ifdef MSF_SUPPORT_EXT_MODULE
    if(mem_pool[poolId].adm_id)
    {
        ASSERT(poolId == HDI_SYS_MEM_POOL);
        ASSERT(mem_pool[poolId].total_bytes == pool_size);
        ASSERT(mem_pool[poolId].pool_addr == memory_addr);
        ASSERT(mem_pool[poolId].adm_id);
		#ifdef MSF_NEW_EXCEPTION_HANDLING
			HDIa_memClearException(poolId);
		#endif
   
        kal_give_mutex(hdi_mem_mutex);
      
        return;
    }
#endif
    
    ASSERT(mem_pool[poolId].adm_id== NULL);

    mem_pool[poolId].pool_addr = memory_addr;
    mem_pool[poolId].total_bytes = pool_size;
    
    mem_pool[poolId].adm_id = kal_adm_create(memory_addr, pool_size, (kal_uint32*) hdi_mem_pool_chunk_size, KAL_FALSE);
    ASSERT(mem_pool[poolId].adm_id);
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_NEW_EXCEPTION_HANDLING
	HDIa_memClearException(poolId);
#endif
#endif  
    kal_give_mutex(hdi_mem_mutex);   
}

/*****************************************************************************
 * FUNCTION
 *  initHdiMem
 * DESCRIPTION
 *  initialize context for memory adaptation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void init_hdi_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
#ifndef HDI_MEM_DEBUG
	int i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if(!hdi_mem_mutex)
    {
        hdi_mem_mutex = kal_create_mutex("HDI_MEM_MUTEX");
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
        mem_track = fopen("mem_track.txt", "w");
#endif
    }

#ifndef HDI_MEM_DEBUG
	
		for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
		{
	#ifdef MSF_SUPPORT_EXT_MODULE
		if(i!=MSF_MODID_EXT)
	#endif
        hdi_pool_mem_info[i] = NULL;
		}
#endif

   
    init_memory_pool(HDI_SYS_MEM_POOL, mms_sys_mem, HDI_SYS_MEM_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  init_memory_pool
 * DESCRIPTION
 *  To initialize specified memory pool for ADM use.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void deinit_memory_pool(MSF_UINT8 pool_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_take_mutex(hdi_mem_mutex);

    ASSERT(mem_pool[pool_id].adm_id);

#ifdef MSF_SUPPORT_EXT_MODULE
    if(pool_id == HDI_SYS_MEM_POOL)
    {
   
        kal_give_mutex(hdi_mem_mutex);
       
        return;
    }
#endif

    kal_adm_delete(mem_pool[pool_id].adm_id);

    //mem_pool[pool_id].adm_id = NULL;
    memset(&mem_pool[pool_id], 0, sizeof(memory_pool_struct));


    kal_give_mutex(hdi_mem_mutex);
   
}


/*****************************************************************************
 * FUNCTION
 *  deinit_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
memory_pool_struct *hdi_get_pool_by_modId(MSF_UINT8 modId)
{
    memory_pool_struct *pool_id = NULL;
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    pool_id = &mem_pool[msf_modules[modId].memPoolId];
#else
#ifdef MMS_V02_USE_ASM
    if(modId == MSF_MODID_ASM)
        pool_id = &mem_pool[MMS_V02_APP_MEM_POOL];
    else
#endif        
    pool_id = &mem_pool[HDI_SYS_MEM_POOL];
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
    ASSERT(pool_id);
    return pool_id;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_memAlloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MSF_LOG_MEM_ALLOC
void *gmms_HDIa_memAlloc(MSF_UINT8 modId, MSF_UINT32 size, const char *filename, int lineno)
#else
void *gmms_HDIa_memAlloc(MSF_UINT8 modId, MSF_UINT32 size)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_addr = NULL;
    MSF_UINT32 chunk_size;
    memory_pool_struct *pool;
#ifdef HDI_MEM_DEBUG
    memory_info_struct *mod_mem_info = NULL;
#endif /*HDI_MEM_DEBUG*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        

    kal_take_mutex(hdi_mem_mutex);

    pool = hdi_get_pool_by_modId(modId);        
    chunk_size = (((size + 3) >> 2) << 2);  /* round to multiple of 4 */
    if (chunk_size == 0)
    {
        /* To avoid return NULL when allocated size = 0 */
        chunk_size = 4;
    }
#ifndef HDI_MEM_DEBUG    
    mem_addr = kal_adm_alloc(pool->adm_id, chunk_size + HDI_SIZE_OF_HEAD);
/****************************************************************************/
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    if(mem_addr)
    {
        MSF_UINT32 *ptr = NULL;

        ptr = (MSF_UINT32 *)VirtualAllocEx((HANDLE)-1, NULL, chunk_size + HDI_SIZE_OF_HEAD + sizeof(MSF_UINT32), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        *ptr = (MSF_UINT32)mem_addr;

        mem_addr = ptr + 1;
    }
#endif
/****************************************************************************/
    if(mem_addr)
    {
        memory_info_struct* node = (memory_info_struct*)mem_addr;
        
        mem_addr = node + 1;
        node->size = chunk_size + HDI_SIZE_OF_HEAD;

        node->next = hdi_pool_mem_info[modId];
        hdi_pool_mem_info[modId] = node;
    }
	else
	{
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_NEW_EXCEPTION_HANDLING
		HDIa_memSetException(modId);
#endif
#endif
	}
#else   
    mem_addr = kal_adm_alloc(pool->adm_id, chunk_size + HDI_SIZE_OF_HEAD);
/****************************************************************************/
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    if(mem_addr)
    {
        MSF_UINT32 *ptr = NULL;

        ptr = (MSF_UINT32 *)VirtualAllocEx((HANDLE)-1, NULL, chunk_size + HDI_SIZE_OF_HEAD + sizeof(MSF_UINT32), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        *ptr = (MSF_UINT32)mem_addr;

        mem_addr = ptr + 1;
    }
#endif
/****************************************************************************/
    if (mem_addr == NULL)
    {
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
        HDIa_memDumpMemUsageToFile();
        ASSERT(0);
#else
#ifdef MSF_NEW_EXCEPTION_HANDLING
		HDIa_memSetException(modId);
#endif
#endif
    }

    if(mem_addr)
    {
        hdi_mem_header_struct *header;
        hdi_mem_footer_struct *footer;
        header = (hdi_mem_header_struct*) mem_addr;
        mem_addr = header + 1;
        footer = (hdi_mem_footer_struct*) (((char*)mem_addr) + chunk_size);

        /* header */
    #ifdef MSF_LOG_MEM_ALLOC
        header->filename = filename;
        header->line = lineno;
    #endif

        header->prev = NULL;
        header->chunk_size = chunk_size;
        HDI_MEM_SET_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN1);    
        
        header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] &= 0xFFFFFF00;
        header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] += modId;

        /* footer */    
        HDI_MEM_SET_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN1);

        /* update linked list */
        if(pool->head == NULL)
        {
            header->next = NULL;
            pool->head = header;
        }
        else
        {
            header->next = pool->head;
            pool->head->prev = header;
            pool->head = header;
        }

        mod_mem_info = pool->mod_mem_info;
        
        mod_mem_info[modId].allocated_bytes += chunk_size;
        mod_mem_info[modId].allocated_bytes_with_header += (chunk_size + HDI_SIZE_OF_HEAD);

        if (mod_mem_info[modId].allocated_bytes > mod_mem_info[modId].max_allocated_bytes)
        {
            mod_mem_info[modId].max_allocated_bytes = mod_mem_info[modId].allocated_bytes;
        }
    }
#endif /* HDI_MEM_DEBUG */


    kal_give_mutex(hdi_mem_mutex);

#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    fprintf(mem_track, "Alloc: %x\t%s\t%d\n", mem_addr, filename, lineno);
    fflush(mem_track);
#endif
    return mem_addr;
}

/*****************************************************************************
 * FUNCTION
 *  gmms_HDIa_getAvailableFreeMemory
 * DESCRIPTION
 *  It returns Available Free memory in MMS MEM POOL
 * PARAMETERS
 *  void        
 * RETURNS
 *  MSF_UINT32
 *****************************************************************************/
MSF_UINT32 gmms_HDIa_getAvailableFreeMemory( )
{
   MSF_UINT8 poolId = HDI_SYS_MEM_POOL;
   MSF_UINT32 available_memory;
    

    kal_take_mutex(hdi_mem_mutex);


   available_memory = mem_pool[poolId].total_bytes;
    
   if (mem_pool[poolId].adm_id)
   {
       available_memory =  kal_adm_get_total_left_size(mem_pool[poolId].adm_id);
       ASSERT(mem_pool[poolId].total_bytes > available_memory);
   }

    kal_give_mutex(hdi_mem_mutex);
  
   return available_memory;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MSF_LOG_MEM_ALLOC
void gmms_HDIa_memFree(MSF_UINT8 modId, void *p, const char *filename, int lineno)
#else
void gmms_HDIa_memFree(MSF_UINT8 modId, void *p)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    memory_pool_struct *pool;
#ifdef HDI_MEM_DEBUG
    int modid;
    hdi_mem_header_struct *header, *prev_node;
    hdi_mem_footer_struct *footer;
    memory_info_struct *mod_mem_info = NULL;
#else
    memory_info_struct *node=NULL, *list=NULL;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
    {
        return;
    }
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    fprintf(mem_track, "Free: %x\t%s\t%d\n", p, filename, lineno);
    fflush(mem_track);
#endif


    kal_take_mutex(hdi_mem_mutex);
   
    pool = hdi_get_pool_by_modId(modId);        

    ASSERT(p && ((((MSF_UINT32)(p)) & 3) == 0));

#ifndef HDI_MEM_DEBUG    
    {
        node = p;
        list = hdi_pool_mem_info[modId];
        
        ASSERT(list);
        
        node--;
        
        if(list == node)
        {
            list = list->next;
            hdi_pool_mem_info[modId] = list;
        }
        else
        {
            while(list)
            {
                if(node == list->next)
                {
                    list->next = list->next->next;
                    break;
                }
                list = list->next;
            }
        }
    }

/****************************************************************************/
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    {
        MSF_UINT32 *ptr = (MSF_UINT32*)node - 1;

        node = (memory_info_struct*)*ptr;

        VirtualFreeEx((HANDLE)-1, ptr, 0, MEM_DECOMMIT);
    }
#endif
/****************************************************************************/
    kal_adm_free(pool->adm_id, node);
#else
    header = ((hdi_mem_header_struct*) p) - 1;
    footer = (hdi_mem_footer_struct*) (((char*)p) + header->chunk_size);

    ASSERT(HDI_MEM_COMP_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN1) && 
           HDI_MEM_COMP_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN1));

    modid = header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] % 256;

    if(modid != modId)
    {
        ASSERT(0);
    }

    /* Detach the node from the list */
    prev_node = header->prev;
    if(prev_node == NULL)
    {
        ASSERT(header == pool->head);
        pool->head = header->next;
        if(pool->head)
        {
            pool->head->prev = NULL;
        }
    }
    else
    {
        prev_node->next = header->next;
        if(header->next)
        {
            header->next->prev = prev_node;
        }
    }
    
    /* Set guard pattern */
    HDI_MEM_SET_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN2);

    header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] &= 0xFFFFFF00;
    header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] += modId;
      
    HDI_MEM_SET_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN2);

#ifdef MSF_LOG_MEM_ALLOC
    header->filename = filename;
    header->line = lineno;
#endif

    mod_mem_info = pool->mod_mem_info;

    mod_mem_info[modId].allocated_bytes -= header->chunk_size;
    mod_mem_info[modId].allocated_bytes_with_header -= (header->chunk_size + HDI_SIZE_OF_HEAD);
/****************************************************************************/
#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
    {
        MSF_UINT32 *ptr = (MSF_UINT32*)header - 1;

        header = (hdi_mem_header_struct*)*ptr;

        VirtualFreeEx((HANDLE)-1, ptr, 0, MEM_DECOMMIT);
    }
#endif
/****************************************************************************/
    kal_adm_free(pool->adm_id, header);
#endif /* HDI_MEM_DEBUG */


    kal_give_mutex(hdi_mem_mutex);

    return;
}



/*****************************************************************************
 * FUNCTION
 *  HDIa_memExternalAlloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *gmms_HDIa_memExternalAlloc(MSF_UINT8 modId, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memExternalFree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_memExternalFree(MSF_UINT8 modId, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  gmms_hdi_mem_allocated_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
MSF_UINT32 gmms_hdi_mem_allocated_bytes(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 alloc_mem_bytes = 0;
#ifdef HDI_MEM_DEBUG	
    int i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef HDI_MEM_DEBUG    
    for(i = 0; i < HDI_MEM_POOL_NUM; i++)
    {
        if(mem_pool[i].adm_id)
        {
            alloc_mem_bytes += mem_pool[i].mod_mem_info[modId].allocated_bytes_with_header;
        }
    }
#else
    {
        memory_info_struct* list = hdi_pool_mem_info[modId];
        while(list)
        {
            alloc_mem_bytes += list->size;
            list = list->next;
        }
    }
#endif
    return alloc_mem_bytes;
}

/*****************************************************************************
 * FUNCTION
 *  gmms_hdi_mem_free_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  p           [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_hdi_mem_free_all(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_take_mutex(hdi_mem_mutex);
 	
#ifdef HDI_MEM_DEBUG
	{
	    int i;
		MSF_UINT8 modid;
		hdi_mem_header_struct *head = NULL, *temp = NULL;
		memory_pool_struct *pool;
	    hdi_mem_header_struct *header, *prev_node;
	    hdi_mem_footer_struct *footer;
	    memory_info_struct *mod_mem_info = NULL;
	
	    for(i = 0; i < HDI_MEM_POOL_NUM; i++)
	    {
	        if(mem_pool[i].adm_id)
	        {
	            head = mem_pool[i].head;
	            while(head && (mem_pool[i].mod_mem_info[modId].allocated_bytes > 0))
	            {
	                temp = head;
	                head = head->next;

					header = (hdi_mem_header_struct*) temp;
					footer = (hdi_mem_footer_struct*) (((char*)(temp+1)) + header->chunk_size);

					ASSERT(HDI_MEM_COMP_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN1) && 
						   HDI_MEM_COMP_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN1));					
					
	                modid = temp->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] % 256;
					
	                if(modid == modId)
	                {
						#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
							fprintf(mem_track, "Free: %x\t%s\t%d\n", (void*)(temp + 1), __FILE__, __LINE__);
							fflush(mem_track);
						#endif
						
						pool = hdi_get_pool_by_modId(modId);
						
					    /* Detach the node from the list */
					    prev_node = header->prev;
					    if(prev_node == NULL)
					    {
					        ASSERT(header == pool->head);
					        pool->head = header->next;
					        if(pool->head)
					        {
					            pool->head->prev = NULL;
					        }
					    }
					    else
					    {
					        prev_node->next = header->next;
					        if(header->next)
					        {
					            header->next->prev = prev_node;
					        }
					    }
					    
					    /* Set guard pattern */
					    HDI_MEM_SET_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN2);

					    header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] &= 0xFFFFFF00;
					    header->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] += modId;
					      
					    HDI_MEM_SET_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN2);

						#ifdef MSF_LOG_MEM_ALLOC
					    header->filename = __FILE__;
					    header->line = __LINE__;
						#endif

					    mod_mem_info = pool->mod_mem_info;

					    mod_mem_info[modId].allocated_bytes -= header->chunk_size;
					    mod_mem_info[modId].allocated_bytes_with_header -= (header->chunk_size + HDI_SIZE_OF_HEAD);
						/****************************************************************************/
						#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
					    {
					        MSF_UINT32 *ptr = (MSF_UINT32*)header - 1;

					        header = (hdi_mem_header_struct*)*ptr;

					        VirtualFreeEx((HANDLE)-1, ptr, 0, MEM_DECOMMIT);
					    }
						#endif
						/****************************************************************************/
					    kal_adm_free(pool->adm_id, header);
	                }
	            }
	#ifdef OBIGO_Q03C_BROWSER
	            if(modId == MSF_MODID_BRS)
	            {
	                /*mem_pool[i].mod_mem_info[modId] = {0, 0, 0};*/
					memset(&(mem_pool[i].mod_mem_info[modId]), 0, sizeof(mem_pool[i].mod_mem_info[modId]));
	            }
	#endif /*OBIGO_Q03C_BROWSER*/
	        }
	    }
	}
#else
    {
		memory_pool_struct *pool;
		memory_info_struct *node=NULL, *list=NULL, *temp = NULL;
		
	    list = hdi_pool_mem_info[modId];
		
	        while(list)
	        {
	            temp = list;
	            list = list->next;
				
				#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
			    fprintf(mem_track, "Free: %x\t%s\t%d\n", (void*)(temp+1), __FILE__, __LINE__);
			    fflush(mem_track);
				#endif
				
				pool = hdi_get_pool_by_modId(modId);
				
				{
			        node = temp+1;
			        list = hdi_pool_mem_info[modId];
			        
			        ASSERT(list);
			        
			        node--;
			        
			        if(list == node)
			        {
			            list = list->next;
			            hdi_pool_mem_info[modId] = list;
			        }
			        else
			        {
			            while(list)
			            {
			                if(node == list->next)
			                {
			                    list->next = list->next->next;
			                    break;
			                }
			                list = list->next;
			            }
			        }
			    }
				
				/****************************************************************************/
				#ifdef HDI_MEM_WINDOWS_MALLOC_DEBUG
				    {
				        MSF_UINT32 *ptr = (MSF_UINT32*)node - 1;

				        node = (memory_info_struct*)*ptr;

				        VirtualFreeEx((HANDLE)-1, ptr, 0, MEM_DECOMMIT);
				    }
				#endif
				/****************************************************************************/
				
				kal_adm_free(pool->adm_id, node);				
			}
	        hdi_pool_mem_info[modId] = NULL;
	}    
#endif
    ASSERT(gmms_hdi_mem_allocated_bytes(modId) == 0);

    kal_give_mutex(hdi_mem_mutex);
	
}


#ifdef MMS_V02_USE_ASM
void gmms_msf_set_mms_app_mem_pool(void *base_addr, MSF_UINT32 pool_size)
{
    init_memory_pool(MMS_V02_APP_MEM_POOL, base_addr, pool_size);
}

void gmms_msf_reset_mms_app_mem_pool()
{
    deinit_memory_pool(MMS_V02_APP_MEM_POOL);
}
#endif


#ifdef HDI_MEM_DEBUG
/*****************************************************************************
 * FUNCTION
 *  hdi_mem_screen_is_valid_block
 * DESCRIPTION
 *  Check if a screen-based ASM memory block is valid by 
 *      1. Inspecting its guard patterns
 *      2. Checking if it belongs to the current MMI screen.
 *
 *  This function can be used in non-MMI task. 
 * PARAMETERS
 *  mem_ptr     [IN]        Memory block to check
 * RETURNS
 *  Return KAL_TRUE if 'mem_ptr' is a valid block
 *****************************************************************************/
static int hdi_mem_screen_is_valid_block(void *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    hdi_mem_header_struct *header;
    hdi_mem_footer_struct *footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mem_ptr || ((((MSF_UINT32)(mem_ptr)) & 3) != 0))
    {
        return 0;
    }
    
    header = ((hdi_mem_header_struct*) mem_ptr) - 1;
    footer = (hdi_mem_footer_struct*) (((char*)mem_ptr) + header->chunk_size);

    return (HDI_MEM_COMP_PATTERN(header->guard_pattern, HDI_MEM_HEADER_PATTERN1) &&
        HDI_MEM_COMP_PATTERN(footer->guard_pattern, HDI_MEM_FOOTER_PATTERN1));
    
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_memCheckMemCorrupted
 * DESCRIPTION
 *  to check the integrity of memory pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_memCheckAppMemIntegrity(MSF_UINT8 poolId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    hdi_mem_header_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_take_mutex(hdi_mem_mutex);
    
    node = mem_pool[poolId].head;
    while (node)
    {
        ASSERT(hdi_mem_screen_is_valid_block(node + 1));
        node = node->next;
    }

    kal_give_mutex(hdi_mem_mutex);
    
}


void HDIa_memADMIntegrityCheck(MSF_UINT8 modId)
{
    memory_pool_struct *pool;   
    void *bad = NULL;

    pool = hdi_get_pool_by_modId(modId);

    bad = kal_adm_check_integrity(pool->adm_id);

    if(bad)
    {
        ASSERT(0);
    }
}

#include "fat_fs.h"         /* file system */
#include "mmi_platform.h"
#include "FileManagerGProt.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"

/*****************************************************************************
 * FUNCTION
 *  HDIa_memDumpMemUsageToFile
 * DESCRIPTION
 *  This function is used to print all memory usage inforamtion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_memDumpMemUsageToFile(void)
{
#ifdef MSF_LOG_MEM_ALLOC
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    hdi_mem_header_struct *node;
    char buf[1000] = {0};
    char filePath1[100] = {0};
    char filePath2[100] = {0};    
    int handle = -1;
    UINT written = 0;
    MSF_UINT32 size = 0;
    MSF_UINT32 i = 0, j = 0;
    long srcLen = 0;
    long destLen = 100;
    int modid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(filePath1,"%c:\\mms_mem_usage_trace.txt", SRV_FMGR_PUBLIC_DRV);
    srcLen = strlen(filePath1);
    msf_charset_utf8_to_ucs2le(filePath1, &srcLen, filePath2, &destLen);                
    FS_Delete((kal_wchar*)filePath2);
    handle = FS_Open((kal_wchar*)filePath2,  FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (handle < 0)
    {
        sprintf(filePath1,"%c:\\mms_mem_usage_trace.txt", SRV_FMGR_SYSTEM_DRV);
        srcLen = strlen(filePath1);
        msf_charset_utf8_to_ucs2le(filePath1, &srcLen, filePath2, &destLen); 
        
        /*Backup mechanism*/
        FS_Delete((kal_wchar*)filePath2);
        handle = FS_Open((kal_wchar*)filePath2,  FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (handle < 0)
        {
            return;
        }
    }
    applib_dt_time2rfc1123dateString(HDIa_timeGetCurrent(), buf);
    strcat(buf, "\r\n");
    FS_Write(handle, buf, strlen(buf), &written);
    if (written != strlen(buf))
    {
        /*No file space*/
        goto exit;
    }            
    for(j = 0; j < HDI_MEM_POOL_NUM; j++)
    {
    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {
        size = 0;
            node = mem_pool[j].head;
        while (node)
        {
            modid = node->guard_pattern[HDI_MEM_GUARD_PATTERN_LEN - 1] % 256;            
            ASSERT(hdi_mem_screen_is_valid_block(node + 1));
            if (modid == i)
            {
                sprintf(buf, "size:%u,Filename:%s,Line:%u\r\n", node->chunk_size, node->filename, node->line);
                FS_Write(handle, buf, strlen(buf), &written);
                if (written != strlen(buf))
                {
                    /*No file space*/
                    goto exit;
                }
                size += node->chunk_size;
            }
            node = node->next;
        }
        sprintf(buf, "ModId:%lu, total memory usage :%lu\r\n", i, size);        
        FS_Write(handle, buf, strlen(buf), &written);
        if (written != strlen(buf))
        {
            /*No file space*/
            goto exit;
        }        
    } 
    }
exit:    
    FS_Close(handle);
#endif    
}
#endif /* HDI_MEM_DEBUG */


