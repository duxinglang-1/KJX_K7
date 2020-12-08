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
 *   jvm_resource_manager.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Use APIs in this file to manage the reource opened by Java.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "MMI_frm_gprot.h"
#include "j2me_trace.h"
#include "jam_internal.h"
#include "jvm_mem.h"
#include "jvm_resource_manager.h"
#include "jvm_trace_interface.h"

jvm_resource_mgr_array_struct *jvm_resource_mgr_array[JVM_RESOURCE_MGR_MAX_NUM];

static kal_bool jvm_resource_mgr_is_registered(kal_int32 vm_id, kal_int32 device_type, kal_int32 handle);
static jvm_resource_mgr_struct *jvm_resource_mgr_alloc_resource_memory(kal_int32 vm_id);

volatile int jvm_resource_mgr_mutex_cnt = 0;
volatile module_type jvm_resource_mgr_mutex_tid = MOD_NIL;

extern kal_mutexid g_jam_resource_mutex;

/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_resource_mgr_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_get_active_module_id() != jvm_resource_mgr_mutex_tid)
    {
        while (jvm_resource_mgr_mutex_cnt > 0)
            kal_sleep_task(1);
        kal_take_mutex(g_jam_resource_mutex);
        jvm_resource_mgr_mutex_tid = kal_get_active_module_id();
    }
    ++jvm_resource_mgr_mutex_cnt;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_resource_mgr_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(jvm_resource_mgr_mutex_tid == kal_get_active_module_id());

    --jvm_resource_mgr_mutex_cnt;

    if (jvm_resource_mgr_mutex_cnt == 0)
    {
        jvm_resource_mgr_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_resource_mutex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_resource_mgr_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    kal_int32 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_INIT);
    for (i = 0; i < JVM_RESOURCE_MGR_MAX_NUM; i++)
    {
        jvm_resource_mgr_array[i] = (jvm_resource_mgr_array_struct*) jvm_malloc(sizeof(jvm_resource_mgr_array_struct));
        if (jvm_resource_mgr_array[i] == NULL)
        {
            kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_INIT_FAILED,i);
            for( j = 0 ;  j < i ; j++)
                jvm_resource_mgr_finalize(j);
            
            return RESOUCE_FAIL;
        }
        kal_mem_set(jvm_resource_mgr_array[i], 0, sizeof(resource_mgr_array_struct));   /* 20090409: Changed */
    }

    JVM_RES_CS_ENTER();
    for (i = 0; i < JVM_RESOURCE_MGR_MAX_NUM; i++)
    {
        for (j = 0; j < JVM_RESOUCE_ARRAY_SIZE; j++)
        {
            jvm_resource_mgr_array[i]->resouce[j].device_type = JAVA_INVALID_DEVICE;
        }
        jvm_resource_mgr_array[i]->next = NULL;
        jvm_resource_mgr_array[i]->next_free_index = 0;
    }
    JVM_RES_CS_LEAVE();

    return RESOUCE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_finalize_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_resource_mgr_finalize_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_array_struct *temp_array;
    jvm_resource_mgr_array_struct *temp_save;
    kal_int32 i;
    kal_int32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_FINALIZE_ALL);
    
    JVM_RES_CS_ENTER();

    for (i = 0; i < JVM_RESOURCE_MGR_MAX_NUM; i++)
    {
        temp_array = jvm_resource_mgr_array[i];
        while (temp_array != NULL)
        {
            temp_save = temp_array;
        
            for (j = 0; j < JVM_RESOUCE_ARRAY_SIZE; j++)
            {
                if (temp_array->resouce[j].close != NULL)
                {
                    if (temp_array->resouce[j].close(temp_array->resouce[j].handle) != RESOUCE_NO_ERROR)
                    {
                        temp_array->resouce[j].close = NULL;
                    }
                }
            }
            temp_array = temp_array->next;
            jvm_free(temp_save);
        }
        
        jvm_resource_mgr_array[i] = NULL;

    }

    JVM_RES_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_resource_mgr_finalize(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_array_struct *temp_array;
    jvm_resource_mgr_array_struct *temp_save;
    kal_int32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_FINALIZE,vm_id);
    if(vm_id < 0)
        return;
    ////ASSERT(vm_id >= 0 && vm_id <= JVM_RESOURCE_MGR_INVALIDE_VM_ID);

    JVM_RES_CS_ENTER();
    temp_array = jvm_resource_mgr_array[vm_id];
    while (temp_array != NULL)
    {
        temp_save = temp_array;

        for (j = 0; j < JVM_RESOUCE_ARRAY_SIZE; j++)
        {
            if (temp_array->resouce[j].close != NULL)
            {
                if (temp_array->resouce[j].close(temp_array->resouce[j].handle) != RESOUCE_NO_ERROR)
                {
                    temp_array->resouce[j].close = NULL;
                }
            }
        }
        temp_array = temp_array->next;

        if(temp_save != jvm_resource_mgr_array[vm_id])  //don't free the first resource
            jvm_free(temp_save);
    }

    if(jvm_resource_mgr_array[vm_id] != NULL)
    {
        memset(jvm_resource_mgr_array[vm_id],0x00,sizeof(jvm_resource_mgr_array_struct));
    }
    
    JVM_RES_CS_LEAVE();
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id           [IN]        
 *  device_type     [IN]        
 *  handle          [IN]        
 *  suspend         [IN]        
 *  resume          [IN]        
 *  close           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_resource_mgr_register(
            kal_int32 vm_id,
            kal_int32 device_type,
            kal_int32 handle,
            kal_int32(*suspend) (kal_int32 handle),
            kal_int32(*resume) (kal_int32 handle),
            kal_int32(*close) (kal_int32 handle))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_struct *resouce = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_REGISTER,vm_id,handle);
    ASSERT(vm_id >= 0 && vm_id <= JVM_RESOURCE_MGR_INVALIDE_VM_ID);


    JVM_RES_CS_ENTER();
    
    if (jvm_resource_mgr_array[vm_id] == NULL)
    {
        JVM_RES_CS_LEAVE();
        return RESOUCE_FAIL;
    }

    if (jvm_resource_mgr_is_registered(vm_id, device_type, handle) == KAL_TRUE)
    {
        JVM_RES_CS_LEAVE();
        return RESOUCE_EXISTED;
    }

    resouce = jvm_resource_mgr_alloc_resource_memory(vm_id);

    if (resouce != NULL)
    {
        resouce->device_type = device_type;
        resouce->handle = handle;
        resouce->suspend = suspend;
        resouce->resume = resume;
        resouce->close = close;
    }
    else
    {
        ASSERT(0);
    }
    JVM_RES_CS_LEAVE();

    return RESOUCE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_is_registered
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id           [IN]        
 *  device_type     [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool jvm_resource_mgr_is_registered(kal_int32 vm_id, kal_int32 device_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_array_struct *resource_array = jvm_resource_mgr_array[vm_id];
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (resource_array != NULL)
    {
        for (i = 0; i < JVM_RESOUCE_ARRAY_SIZE; i++)
        {
            if ((resource_array->resouce[i].device_type == device_type) &&
                (resource_array->resouce[i].handle == handle))
            {
                return KAL_TRUE;
            }
        }
        resource_array = resource_array->next;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_alloc_resource_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static jvm_resource_mgr_struct *jvm_resource_mgr_alloc_resource_memory(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_array_struct *temp_array = jvm_resource_mgr_array[vm_id];
    jvm_resource_mgr_array_struct *temp_save = NULL;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_array != NULL)
    {
        temp_save = temp_array;

        if (temp_array->next_free_index == -1)
        {
            temp_array = temp_array->next;
        }
        else
        {
            jvm_resource_mgr_struct *empty_entry = &temp_array->resouce[temp_array->next_free_index];

            for (i = 0; i < JVM_RESOUCE_ARRAY_SIZE; i++)
            {
                if ((temp_array->resouce[i].device_type == JAVA_INVALID_DEVICE) && (i != temp_array->next_free_index))
                {
                    temp_array->next_free_index = i;
                    break;
                }
            }

            if (i == JVM_RESOUCE_ARRAY_SIZE)
            {
                temp_array->next_free_index = -1;
            }

            return empty_entry;
        }
    }

    /* Expand array */
    temp_array = (jvm_resource_mgr_array_struct*) jvm_malloc(sizeof(jvm_resource_mgr_array_struct));
    if (temp_array == NULL)
    {
        return NULL;
    }

    kal_mem_set(temp_array, 0, sizeof(jvm_resource_mgr_array_struct));  /* 20090409: Changed */
    for (i = 0; i < JVM_RESOUCE_ARRAY_SIZE; i++)
    {
        temp_array->resouce[i].device_type = JAVA_INVALID_DEVICE;
    }

    temp_array->next = NULL;
    temp_array->next_free_index = 1;
    temp_save->next = temp_array;

    return &temp_array->resouce[0];
}


/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_deregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vm_id           [IN]        
 *  device_type     [IN]        
 *  handle          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_resource_mgr_deregister(kal_int32 vm_id, kal_int32 device_type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_resource_mgr_array_struct *resource_array;
    kal_int32 result;
    kal_int32 i;
    kal_bool finished = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace((trace_class_enum)JVM_TRACE_TYPE_FUNC,FUNC_J2ME_JVM_RES_MGR_DEREGISTER,vm_id,handle);
    ASSERT(vm_id >= 0 && vm_id <= JVM_RESOURCE_MGR_INVALIDE_VM_ID);
    JVM_RES_CS_ENTER();

    resource_array = jvm_resource_mgr_array[vm_id];

    finished = KAL_FALSE;
    result = RESOUCE_NOT_FOUND;

    while (resource_array != NULL && !finished)
    {
        for (i = 0; i < JVM_RESOUCE_ARRAY_SIZE; i++)
        {
            if ((resource_array->resouce[i].device_type == device_type) &&
                (resource_array->resouce[i].handle == handle))
            {
                resource_array->resouce[i].device_type = JAVA_INVALID_DEVICE;
                resource_array->resouce[i].handle = 0;
                resource_array->resouce[i].close = NULL;
                resource_array->resouce[i].resume = NULL;
                resource_array->resouce[i].suspend = NULL;
                if (i < resource_array->next_free_index)
                {
                    resource_array->next_free_index = i;
                }
                result = RESOUCE_NO_ERROR;
                finished = KAL_TRUE;
                break;
            }
        }
        resource_array = resource_array->next;
    }

    JVM_RES_CS_LEAVE();

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  jvm_resource_mgr_get_invalide_vm_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *  
 *****************************************************************************/
kal_int32 jvm_resource_mgr_get_invalide_vm_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return JVM_RESOURCE_MGR_INVALIDE_VM_ID;
}


