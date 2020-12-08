/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   jvm_mem.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements general memory initializer/finalizer, allocator/deallocator API
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
* Include header files
*************************************************************************/
#include "mmi_frm_gprot.h"
#include "jvm_internal.h"
#include "jvm_mem.h"
#include "kal_adm.h"
#include "cache_sw.h"
#include "j2me_trace.h"
#include "memory.h"
/*************************************************************************
* Global Definition
*************************************************************************/
static jvm_malloc_handler jvm_small_allocator;
static jvm_free_handler jvm_small_deallocator;

static jvm_malloc_handler jvm_large_allocator;
static jvm_free_handler jvm_large_deallocator;

#define DIVIDING_LINE_SIZE 0x4000       /* 16K //0x8000 // 32K */

kal_bool g_j2me_slim_screen_meory_support = KAL_FALSE;
#ifdef JVM_MEM_MONITOR_SUPPORT

static jvm_mem_monitor_record jvm_mem_montior_record_tbl[JVM_MEM_MONITOR_NUM][JVM_MEM_MONITOR_RECORD_TBL_SIZE];
static kal_int32 jvm_mem_monitor_seq[JVM_MEM_MONITOR_NUM] ;
static kal_int32 jvm_mem_monitor_pool_id[JVM_MEM_MONITOR_NUM];
#endif /* JVM_MEM_MONITOR_SUPPORT */
/*************************************************************************
* Function Definition
*************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_config
 * DESCRIPTION
 *
 * PARAMETERS
 *  allocator       [IN]
 *  deallocator     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_config(jvm_malloc_handler jvm_small_alloc, jvm_free_handler jvm_small_free,jvm_malloc_handler jvm_large_alloc, jvm_free_handler jvm_large_free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_small_allocator = jvm_small_alloc;
    jvm_small_deallocator = jvm_small_free;

    jvm_large_allocator = jvm_large_alloc;
    jvm_large_deallocator = jvm_large_free;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_malloc_impl
 * DESCRIPTION
 *
 * PARAMETERS
 *  size            [IN]
 *  filename        [?]
 *  lineno          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void * jvm_malloc_impl(kal_int32 size, char *filename, kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_small_allocator);
    ASSERT(jvm_large_allocator);

    if(size >= DIVIDING_LINE_SIZE)
    {
        ptr = (*jvm_large_allocator) (size, filename, lineno);
    }
    else
    {
        ptr = (*jvm_small_allocator) (size, filename, lineno);
    }
    return ptr;
}

/*****************************************************************************
* FUNCTION 
* jvmCheckFreeMemory_Ext
* DESCRIPTION
* 
* PARAMETERS
* int size
* RETURNS 
* void  
*modify/add date: 2012-10-19
*modify/add time: 11:38:21
*****************************************************************************/
void  jvmCheckFreeMemory_Ext(int size)     
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (J2ME_SUPPORT_BACKGROUND) && defined (__COSMOS_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT) 
    jvmCheckFreeMemory(size);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jvm_free_impl
 * DESCRIPTION
 *
 * PARAMETERS
 *  ptr             [?]
 *  filename        [?]
 *  lineno          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_free_impl(void *ptr, char *filename, kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_small_deallocator);
    ASSERT(jvm_large_deallocator);

    (*jvm_small_deallocator) (ptr, filename, lineno);
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_initialize_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_adress        [?]         
 *  size                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JVM_MEM_ID jvm_mem_initialize_impl(void *start_address, kal_int32 size,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JVM_MEM_ID id = NULL;
#ifdef  JVM_MEM_MONITOR_SUPPORT 
    kal_int32 monitor_id = 0;
    kal_int32 i = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_MEM_DEBUG
    id =  (JVM_MEM_ID) kal_adm_create(start_address, size, NULL, KAL_TRUE);
#else
    id =  (JVM_MEM_ID) kal_adm_create(start_address, size, NULL, KAL_FALSE);
#endif /* JVM_MEM_DEBUG */
    kal_trace(TRACE_FUNC,JVM_MEM_MSG_INITIALIZE,start_address,size,id);

#ifdef  JVM_MEM_MONITOR_SUPPORT

    monitor_id = -1;
    for( i = 0 ; i < JVM_MEM_MONITOR_NUM ; i ++)
    {
        if( jvm_mem_monitor_pool_id[i] == (kal_int32)id)
        {
            monitor_id = i;
            break;
        }
    }

    if(monitor_id < 0)
    {
        for( i = 0 ; i < JVM_MEM_MONITOR_NUM ; i ++)
        {
            if( jvm_mem_monitor_pool_id[i] == 0)
            {
                jvm_mem_monitor_pool_id[i] = (kal_int32)id;
                break;
            }
        }
        monitor_id = jvm_mem_monitor_get_id(id);
    }

    jvm_mem_monitor_initialize(monitor_id);
#endif /* JVM_MEM_MONITOR_SUPPORT */
    return id;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_finalize_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_finalize_impl(JVM_MEM_ID id,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC,JVM_MEM_MSG_FINALIZE,"[jvm_mem_finalize_impl]poolId=%p",id);

    ASSERT(id != NULL);

    kal_adm_delete((KAL_ADM_ID) id);

#ifdef  JVM_MEM_MONITOR_SUPPORT
    jvm_mem_monitor_finialize(jvm_mem_monitor_get_id(id));
#endif /* JVM_MEM_MONITOR_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_malloc_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *jvm_mem_malloc_impl(JVM_MEM_ID id, kal_int32 size,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(id != NULL);  
    buffer =  kal_adm_alloc((KAL_ADM_ID) id, size); 	
    
    
#ifdef JVM_MEM_DEBUG
    jvm_trace_info("[jvm_mem_malloc_impl]id=%p,size=%d,buffer=%p,file=%s,lineno=%d\n",id,size,buffer,file_name,lineno);
#endif /* JVM_MEM_DEBUG */

#ifdef  JVM_MEM_MONITOR_SUPPORT
    jvm_mem_monitor_add_rec(jvm_mem_monitor_get_id(id),buffer,size,file_name,lineno);
#endif /* JVM_MEM_MONITOR_SUPPORT */

    return buffer;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_free_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_free_impl(JVM_MEM_ID id, void *buffer,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(id != NULL);
    kal_adm_free((KAL_ADM_ID) id, buffer);

#ifdef JVM_MEM_DEBUG
    jvm_trace_info("[jvm_mem_free_impl]id=%p,buffer=%p,file=%s,lineno=%d\n",id,buffer,file_name,lineno);
#endif /* JVM_MEM_DEBUG */  

#ifdef  JVM_MEM_MONITOR_SUPPORT
    jvm_mem_monitor_del_rec(jvm_mem_monitor_get_id(id),buffer);
#endif /* JVM_MEM_MONITOR_SUPPORT */

}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_remalloc_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void *jvm_mem_remalloc_impl(JVM_MEM_ID id, void *ptr,kal_int32 size,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * buffer = NULL;
   #ifdef  JVM_MEM_MONITOR_SUPPORT 
    int    oldsize   = 0;
   #endif
extern JVM_MEM_ID runtimeMemoryId;
extern JVM_MEM_ID heapMemoryId;
extern int runtimeMemoryAllocated;
extern int heapMemoryAllocated;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(id != NULL);
    buffer =  kal_adm_realloc((KAL_ADM_ID) id, ptr, size);
		
    ASSERT(buffer == ptr);    
	
#ifdef JVM_MEM_DEBUG
    jvm_trace_info("[jvm_mem_remalloc_impl]id=%p,size=%d,buffer=%p,file=%s,lineno=%d\n",id,size,buffer,file_name,lineno);
#endif /* JVM_MEM_DEBUG */

 
#ifdef  JVM_MEM_MONITOR_SUPPORT

    oldsize = jvm_mem_monitor_block_size(jvm_mem_monitor_get_id(id),ptr);

    jvm_mem_monitor_readd_rec(jvm_mem_monitor_get_id(id),buffer,size);


    if(runtimeMemoryId == id)
    {
        runtimeMemoryAllocated -= (oldsize - size);
    }
    else if(heapMemoryId == id)
    {
        heapMemoryAllocated -= (oldsize - size);
    }

#endif /* JVM_MEM_MONITOR_SUPPORT */
    return buffer;

}



/*****************************************************************************
 * FUNCTION
 *  jvm_mem_get_free_size_impl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mem_get_free_size_impl(JVM_MEM_ID id,kal_char * file_name,kal_int32 lineno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return kal_adm_get_total_left_size((KAL_ADM_ID) id);
}

kal_int32 jvm_mem_get_runtime_tempmemory_size()
{
    return JVM_RUNTIME_TEMP_MEMORY_SIZE;
}

#ifdef JVM_MEM_MONITOR_SUPPORT

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_monitor_get_id
 * DESCRIPTION
 *  get monitor Id by memory id
 * PARAMETERS
 *  file    [IN]    filename
 *  line    [IN]    lin number
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jvm_mem_monitor_get_id(JVM_MEM_ID mem_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for( i = 0 ; i < JVM_MEM_MONITOR_NUM ; i ++)
    {
        if( jvm_mem_monitor_pool_id[i] == (kal_int32)mem_id)
            return i;
    }

    ASSERT(0);

}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_set_start_eval
 * DESCRIPTION
 *  start to evalute memory
 * PARAMETERS
 *  file    [IN]    filename
 *  line    [IN]    lin number
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_monitor_initialize(kal_int32 monitor_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    jvm_trace_debug("[jvm_mem.c]jvm_mem_monitor_initialize,monitor_id=%d\n",monitor_id);
    ////jvm_mem_monitor_dump(monitor_id);
    
    memset(jvm_mem_montior_record_tbl[monitor_id], 0, sizeof(jvm_mem_montior_record_tbl[monitor_id]));
    jvm_mem_monitor_seq[monitor_id] = 0;
}



/*****************************************************************************
 * FUNCTION
 *  jvm_mem_set_start_eval
 * DESCRIPTION
 *  start to evalute memory
 * PARAMETERS
 *  file    [IN]    filename
 *  line    [IN]    lin number
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_monitor_finialize(kal_int32 monitor_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_mem_monitor_pool_id[monitor_id] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mem_find_rec
 * DESCRIPTION
 *  1. find a position which is not in used in record table
 *  2. find a specific memory address
 * PARAMETERS
 *  ptr     [IN]    the address want to find
 * RETURNS
 *  > 0, success, return the index
 *  - 1, fail
 *****************************************************************************/

kal_int32 jvm_mem_monitor_find_rec(kal_int32 monitor_id,void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ptr == NULL)
    {
        for(i = 0 ;i < JVM_MEM_MONITOR_RECORD_TBL_SIZE; i++)
        {
            if (jvm_mem_montior_record_tbl[monitor_id][i].ptr == NULL )
            {

                return i;
            }
        }
        return -1;
    }
    else
    {

        for(i = 0 ;i < JVM_MEM_MONITOR_RECORD_TBL_SIZE; i++)
        {
            if (jvm_mem_montior_record_tbl[monitor_id][i].ptr == ptr )
            {

                return i;
            }
        }
        return -1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_del_rec
 * DESCRIPTION
 *  delete a record
 * PARAMETERS
 *  ptr     [IN]    the memory address which want to delete
 * RETURNS
 *  0: success
 *  -1: fail
 *****************************************************************************/

kal_int32 jvm_mem_monitor_del_rec(kal_int32 monitor_id,void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ptr != NULL)
    {    
        index = jvm_mem_monitor_find_rec(monitor_id,ptr);
        if (index >= 0)
        {
            memset( &jvm_mem_montior_record_tbl[monitor_id][index], 0, sizeof(jvm_mem_monitor_record));
		    return 0;
        }
        
    }

    jvm_trace_warning("[JVM_mem.c][monitor_del]can't del %p,monitor=%d\n",ptr,monitor_id);
	return -1;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_readd_rec
 * DESCRIPTION
 *  delete a record
 * PARAMETERS
 *  ptr     [IN]    the memory address which want to delete
 * RETURNS
 *  0: success
 *  -1: fail
 *****************************************************************************/

kal_int32 jvm_mem_monitor_readd_rec(kal_int32 monitor_id,void* ptr,kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    /*----------------------------------------------------------------*/
  
    if (ptr != NULL)
    {    
        index = jvm_mem_monitor_find_rec(monitor_id,ptr);
        if (index >= 0)
        {
            jvm_mem_montior_record_tbl[monitor_id][index].size = size;

            return 0;
        }
        
    }

    jvm_trace_warning("[JVM_mem.c][monitor_readd]can't readd %p,monitor=%d\n",ptr,monitor_id);
    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_add_rec
 * DESCRIPTION
 *  add a memory address into record table
 * PARAMETERS
 *  ptr     [IN]    memory address
 *  size    [IN]    memory size
 *  filename    [IN]    filename
 *  line        [IN]    line number
 * RETURNS
 *  0:  success
 *  -1: fail
 *****************************************************************************/

kal_int32 jvm_mem_monitor_add_rec(kal_int32 monitor_id,void* ptr, kal_int32 size, const char* file_name, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    kal_int32 file_name_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    index = jvm_mem_monitor_find_rec(monitor_id,NULL);

    if (index >= 0 )
    {
        file_name_length = strlen(file_name);
        if(file_name_length > 0)
        {
            if(file_name_length > JVM_MEM_MONITOR_FILE_NAME_LENGTH)
            {
                strncpy(jvm_mem_montior_record_tbl[monitor_id][index].filename, file_name+file_name_length-JVM_MEM_MONITOR_FILE_NAME_LENGTH, JVM_MEM_MONITOR_FILE_NAME_LENGTH);
                jvm_mem_montior_record_tbl[monitor_id][index].filename[JVM_MEM_MONITOR_FILE_NAME_LENGTH] = 0; 
            }
            else
            {
                strncpy(jvm_mem_montior_record_tbl[monitor_id][index].filename, file_name,file_name_length);
                jvm_mem_montior_record_tbl[monitor_id][index].filename[file_name_length] = 0; 
            }
            


        }
      
        jvm_mem_montior_record_tbl[monitor_id][index].line = line;
        jvm_mem_montior_record_tbl[monitor_id][index].ptr = ptr;
        jvm_mem_montior_record_tbl[monitor_id][index].size = size;
        jvm_mem_montior_record_tbl[monitor_id][index].seq = jvm_mem_monitor_seq[monitor_id];
        jvm_mem_monitor_seq[monitor_id]++;
		return 0;
    }
	else
	{
        ASSERT(0);
		return -1;
	}
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mem_show_eval
 * DESCRIPTION
 *  Show evaluate result
 * PARAMETERS
 *  show_log    [IN]    need to show log or not
 *  file        [IN]    filename
 *  line        [IN]    line number
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mem_monitor_dump(kal_int32 monitor_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_warning("[JVM][MEM][MONITOR] monitor=%d,start....\n",monitor_id);

    for( i = 0 ;i < JVM_MEM_MONITOR_RECORD_TBL_SIZE; i++)
    {
        if (jvm_mem_montior_record_tbl[monitor_id][i].ptr != NULL )
        {
            jvm_trace_warning("[MONITOR]file=%s, line=%d, ptr=%p, size=%d, seq=%d\n",
                jvm_mem_montior_record_tbl[monitor_id][i].filename, 
                jvm_mem_montior_record_tbl[monitor_id][i].line, 
                jvm_mem_montior_record_tbl[monitor_id][i].ptr,
                jvm_mem_montior_record_tbl[monitor_id][i].size, 
                jvm_mem_montior_record_tbl[monitor_id][i].seq);

            if(count ++ % 10 == 0)
                kal_sleep_task(5);
        }
    }
    jvm_trace_warning("[JVM][MEM][MONITOR] end....\n");
}


#endif /* #ifdef JVM_MEM_MONITOR_SUPPORT */

