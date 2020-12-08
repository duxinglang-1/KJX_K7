/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   jam_list.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JAM list function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "jal.h"
#include "jam_internal.h"
#include "jvm_internal.h"
#include "jam_msg_handler.h"

/*************************************************************************
 * Global Definition
 *************************************************************************/
/* Byte boundary for word alignment - Assumes word is 4-bytes */
#define ALIGNMENT                               (0x00000003)
/* Constant to verify a header's validity */
#define MAGIC                                   (0xCAFE)

/*
 * Total memory allocate from Java runtime memory pool, can be accessed 
 * * by these pointers. Meanwhile, they are used to release memory when
 * * clean up.
 */
mids_listfile_struct *saved_mids_listfile_ptr;

typedef struct listmem_struct_t
{
    kal_uint16 magic;   /* magic number */
    char free;          /* 1 == block is free, 0 == block is used */
    char reserved;
    kal_uint32 size;    /* size of block */
} listmem_struct, *listmem_hdr;

/* mids list memory pool */
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
long midslist_mem_pool[MIDSLIST_MEM_POOL_SIZE / sizeof(long)];
#endif
static char *g_jam_midslist_mem_start_p;
static char *g_jam_midslist_mem_end_p;
#ifdef J2ME_SLIM_MEMORY_SUPPORT
kal_bool g_jam_force_free_mids_listfile = KAL_TRUE;
#else
kal_bool g_jam_force_free_mids_listfile = KAL_FALSE;
#endif

/**************************************************************************
 * List memory management
 **************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  jam_listmem_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_listmem_initialize()
{
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    listmem_hdr header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_midslist_mem_start_p = (char*)midslist_mem_pool;
    g_jam_midslist_mem_end_p = g_jam_midslist_mem_start_p + MIDSLIST_MEM_POOL_SIZE;

    header = (listmem_hdr) g_jam_midslist_mem_start_p;
    header->magic = MAGIC;
    header->free = 1;
    header->size = MIDSLIST_MEM_POOL_SIZE - sizeof(listmem_struct);
    return 0;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jam_listmem_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_listmem_finalize()
{
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    listmem_hdr header;
    char *work;
    kal_int32 count, size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    size = 0;

    for (work = g_jam_midslist_mem_start_p; work < g_jam_midslist_mem_end_p;
         work += header->size + sizeof(listmem_struct))
    {

        header = (listmem_hdr) work;

        if (header->magic != MAGIC)
        {
            return -1;
        }
        else if (header->free != 1)
        {
            /* possible leak */
            jam_listmem_free((void*)((char*)header + sizeof(listmem_struct)));
            count += 1;
            size += header->size;
        }
    }
    return count;
#else
	return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jam_listmem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *jam_listmem_malloc(kal_int32 size)
{
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 allocate_size;
    void *loc = NULL;
    listmem_hdr tmp_header = NULL;
    char *temp = NULL, *mem_ptr;
    char *mem_pool_start = g_jam_midslist_mem_start_p;
    char *mem_pool_end = g_jam_midslist_mem_end_p;
    listmem_hdr header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size <= 0)
    {
        return NULL;
    }

    /* 4bytes alignment */
    allocate_size = (size + ALIGNMENT) & 0xfffffffc;

    /* find a free slot */
    for (mem_ptr = mem_pool_start; mem_ptr < mem_pool_end; mem_ptr += header->size + sizeof(listmem_struct))
    {

        header = (listmem_hdr) mem_ptr;
        if (header->magic != MAGIC)
        {
            kal_trace(TRACE_INFO, FUNC_JAM_LIST_MALLOC_CORRUPTION,(kal_int32) mem_ptr);
            break;
        }
        else
        {
            while (1)
            {
                /* coalescing */
                if (header->free == 1)
                {
                    /* if current block is free */
                    temp = (char*)header;
                    temp += header->size + sizeof(listmem_struct);
                    if (temp >= mem_pool_end)
                    {
                        break;
                    }
                    tmp_header = (listmem_hdr) temp;

                    if ((tmp_header->free == 1) && (tmp_header->magic == MAGIC) && (temp < mem_pool_end))
                    {
                        /* and the next block is free too */
                        /* then coalesce */
                        header->size += tmp_header->size + sizeof(listmem_struct);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            if ((header->free == 1) && (header->size >= (unsigned)allocate_size))
            {

                if (header->size > (allocate_size + sizeof(listmem_struct) + 4))
                {
                    listmem_hdr next_header;

                    /* split block */
                    next_header = (listmem_hdr) ((char*)mem_ptr + allocate_size + sizeof(listmem_struct));
                    next_header->magic = MAGIC;
                    next_header->free = 1;
                    next_header->size = header->size - allocate_size - sizeof(listmem_struct);
                    header->size = allocate_size;
                }
                header->free = 0;
                loc = (void*)((char*)header + sizeof(listmem_struct));
                return (loc);
            }
        }
    }
    kal_trace(TRACE_INFO, FUNC_JAM_LIST_MALLOC_MEM_NOT_AVAIL,(kal_int32) mem_ptr);
    return 0;
#else
    kal_prompt_trace(MOD_JAM, "Here used to be list memory malloc.");
    jvm_malloc(size);     
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jam_listmem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_listmem_free(void *ptr)
{
#ifndef J2ME_SLIM_REMOVE_LIST_MEMORY_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    listmem_hdr header;
    char *mem_pool_start = g_jam_midslist_mem_start_p;
    char *mem_pool_end = g_jam_midslist_mem_end_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr == NULL)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_LIST_FREE_NULL);
    }
    else if (((char*)ptr > mem_pool_end) || ((char*)ptr < mem_pool_start))
    {
        kal_trace(TRACE_INFO, FUNC_JAM_LIST_FREE_OUT_OF_SCOPE, (kal_int32) ptr);
    }
    else
    {
        header = (listmem_hdr) ((char*)ptr - sizeof(listmem_struct));

        if (header->magic != MAGIC)
        {
            kal_trace(TRACE_INFO, FUNC_JAM_LIST_FREE_CORRUPTED_MEM, (kal_int32) ptr);
        }
        else if (header->free != 0)
        {
            kal_trace(TRACE_INFO, FUNC_JAM_LIST_FREE_TWICE, (kal_int32) ptr);
        }
        else
        {
            header->free = 1;
        }
    }
#else
    kal_prompt_trace(MOD_JAM, "Here used to be list memory free.");
    jvm_free(ptr);     
#endif	
}
kal_bool jam_is_mmi_cosmos_support()
{
 #ifdef  __COSMOS_MMI_PACKAGE__
       return  KAL_TRUE;
 #else
       return  KAL_FALSE;
 #endif
}
