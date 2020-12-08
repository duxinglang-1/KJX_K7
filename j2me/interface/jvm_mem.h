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
 *   jvm_mem.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JVM_MEM_H__
#define __JVM_MEM_H__

//#define JVM_MEM_DEBUG   //using for debug information

////#define JVM_MEM_MONITOR_SUPPORT

typedef void * JVM_MEM_ID;

JVM_MEM_ID  jvm_mem_initialize_impl(void * start_adress, kal_int32 size,kal_char * file_name,kal_int32 lineno);
void        jvm_mem_finalize_impl(JVM_MEM_ID id,kal_char * file_name,kal_int32 lineno);
void *      jvm_mem_malloc_impl(JVM_MEM_ID id,kal_int32 size,kal_char * file_name,kal_int32 lineno);
void        jvm_mem_free_impl(JVM_MEM_ID id,void * buffer,kal_char *file_name,kal_int32 lineno);
kal_int32   jvm_mem_get_free_size_impl(JVM_MEM_ID id,kal_char * file_name,kal_int32 lineno);
void *      jvm_mem_remalloc_impl(JVM_MEM_ID id, void *ptr,kal_int32 size,kal_char * file_name,kal_int32 lineno);

#ifdef JVM_MEM_DEBUG
#define JVM_MEM_INITIALIZE(start_address,size)      jvm_mem_initialize_impl(start_address,size,__FILE__,__LINE__)
#define JVM_MEM_FINALIZE(id)                        jvm_mem_finalize_impl(id,__FILE__,__LINE__)
#define JVM_MEM_MALLOC(id,size)                     jvm_mem_malloc_impl(id,size,__FILE__,__LINE__)
#define JVM_MEM_FREE(id,buffer)                     jvm_mem_free_impl(id,buffer,__FILE__,__LINE__)
#define JVM_MEM_GET_FREE_SIZE(id)                   jvm_mem_get_free_size_impl(id,__FILE__,__LINE__)
#else /* JVM_MEM_DEBUG */
#define JVM_MEM_INITIALIZE(start_address,size)      jvm_mem_initialize_impl(start_address,size,(kal_char *)NULL,0);
#define JVM_MEM_FINALIZE(id)                        jvm_mem_finalize_impl(id,(kal_char *)NULL,0)
#define JVM_MEM_MALLOC(id,size)                     jvm_mem_malloc_impl(id,size,(kal_char *)NULL,0)
#define JVM_MEM_FREE(id,buffer)                     jvm_mem_free_impl(id,buffer,(kal_char *)NULL,0)
#define JVM_MEM_GET_FREE_SIZE(id)                   jvm_mem_get_free_size_impl(id,(kal_char *)NULL,0)
#endif /* JVM_MEM_DEBUG */


typedef void *(*jvm_malloc_handler) (kal_int32, char *, kal_int32);
typedef void (*jvm_free_handler) (void *, char *, kal_int32);

extern void jvm_mem_config(jvm_malloc_handler jvm_small_malloc, jvm_free_handler jvm_small_free,jvm_malloc_handler jvm_large_alloc, jvm_free_handler jvm_large_free);
extern void * jvm_malloc_impl(kal_int32 size, char *filename, kal_int32 lineno);
extern void   jvm_free_impl(void *ptr, char *filename, kal_int32 lineno);
extern void  jvmCheckFreeMemory_Ext(int size);
#define jvm_malloc(size)                        jvm_malloc_impl(size, __FILE__, __LINE__)
#define jvm_free(ptr)                           jvm_free_impl(ptr, __FILE__, __LINE__)

#ifdef JVM_MEM_MONITOR_SUPPORT

#define JVM_MEM_MONITOR_NUM 3
#define JVM_MEM_MONITOR_RECORD_TBL_SIZE 3072
#define JVM_MEM_MONITOR_FILE_NAME_LENGTH    32

typedef struct
{
    void *ptr;
    kal_int32 line;
    kal_int32 size;
    kal_int32 seq;
    kal_char filename[JVM_MEM_MONITOR_FILE_NAME_LENGTH+1];
} jvm_mem_monitor_record;

extern void      jvm_mem_monitor_initialize(kal_int32 monitor_id);
extern void      jvm_mem_monitor_finialize(kal_int32 monitor_id);
extern void      jvm_mem_monitor_dump(kal_int32 monitor_id);
extern kal_int32 jvm_mem_monitor_find_rec(kal_int32 monitor_id,void *ptr);
extern kal_int32 jvm_mem_monitor_del_rec(kal_int32 monitor_id,void* ptr);
extern kal_int32 jvm_mem_monitor_add_rec(kal_int32 monitor_id,void* ptr, kal_int32 size, const char* file_name, int line);
extern kal_int32 jvm_mem_monitor_readd_rec(kal_int32 monitor_id,void* ptr, kal_int32 size);
extern kal_int32 jvm_mem_monitor_get_id(JVM_MEM_ID mem_id);

#endif /* JVM_MEM_MONITOR_SUPPORT */

kal_int32 jvm_mem_get_runtime_tempmemory_size(void);
#endif /* __JVM_MEM_H__ */
