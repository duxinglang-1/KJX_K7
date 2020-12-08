
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

/*******************************************************************************
 * Filename:
 * ---------
 * jam_mvm_manager.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define java mvm context and vm instance of  Jam related routines.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "kal_release.h"
#include "kal_public_api.h"
#include "app_str.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "j2me_trace.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "MMI_features.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_internal.h"
#include "jam_mvm_manager.h"
#include "jam_msg_util.h"
#include "jwa_internal.h"
#ifdef SUPPORT_JSR_179
#include "jlbs_internal.h"
#endif
#ifdef SUPPORT_JSR_257
#include "jcc_internal.h"
#endif
#ifdef SUPPORT_JSR_177
#include "jsatsa_internal.h"
#endif

extern kal_mutexid g_jam_mvm_mutex;
extern long *javaheap_space;
extern kal_uint32 javaheap_size;
kal_bool g_jam_heap_is_releasing = KAL_FALSE;
static jam_mvm_context_struct* g_jam_ctxt; 
extern long* g_jam_mvm_whole_heap_space;
extern kal_uint32 g_jam_mvm_whole_heap_size;
kal_bool g_jam_mvm_is_vm_support_bg = KAL_TRUE;

/****************************************************************************************
*  VM status bit define
****************************************************************************************/
#define VM_STOP_IND                 1 /*Indicate whether mid stop req is sended by vm */
#define VM_PAUSE_IND                2 /*Indicate whether mid send a pause ind to MMI */
#define VM_RESUME_IND               3 /*Indicate whether mid send a resume ind to MMI */
#define VM_TERMINATE_IND            4 /*Indicate whether mid send a terminate ind to MMI */
#define VM_CALL_PAUSEAPP_IND        5 /*Indicate whether jal need order vm to call midlet pauseapp. */
#define VM_AUTO_TERMINATED_IND      6 /*Indicate vm auto terminate it */
#define VM_IS_VK_ON_IND             7 /*Indicate vm vk is on */

#define set_vm_ind_status(vm_id,bit)     g_jam_ctxt->vm_list[(vm_id)]->vm_status_ind_flag |=(0x1<<(bit))
#define reset_vm_ind_status(vm_id,bit)   g_jam_ctxt->vm_list[(vm_id)]->vm_status_ind_flag &= ~(0x1<<(bit))
#define is_vm_ind_status_set(vm_id,bit) (kal_bool)((g_jam_ctxt->vm_list[(vm_id)]->vm_status_ind_flag & (0x1<<(bit))) == (0x1<<(bit)))
/****************************************************************************************
*  mem config for java heap and mem context
****************************************************************************************/
#define JAM_MVM_INSTANCE_SIZE 2048
#define JAM_MVM_CONTEXT_MEM_SIZE (MAX_VM_INSTANCE_NUM * JAM_MVM_INSTANCE_SIZE)
static long* g_ctxt_mem = NULL;
static KAL_ADM_ID g_ctxt_adm_id = NULL;
static kal_bool g_jam_mvm_is_alloc_heap = KAL_FALSE;
static void jam_mvm_mem_init(void)
{
    g_ctxt_mem = g_jam_mvm_whole_heap_space;
    javaheap_space =(long *) ((char *)g_jam_mvm_whole_heap_space +JAM_MVM_CONTEXT_MEM_SIZE);
    javaheap_size  = g_jam_mvm_whole_heap_size - JAM_MVM_CONTEXT_MEM_SIZE;
    g_ctxt_adm_id = kal_adm_create(g_ctxt_mem, JAM_MVM_CONTEXT_MEM_SIZE, NULL, KAL_FALSE);
    ASSERT(g_ctxt_adm_id);
}
static jam_mvm_mem_deinit(void)
{
    ASSERT(g_ctxt_adm_id);
    kal_adm_delete(g_ctxt_adm_id);
    g_ctxt_adm_id = NULL;
}
static void* jam_mvm_mem_malloc(kal_uint32 size)
{
    ASSERT(g_ctxt_adm_id);
    return kal_adm_alloc(g_ctxt_adm_id,size);
}
static void jam_mvm_mem_free(void* ptr)
{
    if(ptr)
    {
        ASSERT(g_ctxt_adm_id);
        kal_adm_free(g_ctxt_adm_id,ptr);
    }
}
/***********************************************
*  
***********************************************/
#define JAM_MVM_LOCK      jam_mvm_mutex_lock()
#define JAM_MVM_UNLOCK    jam_mvm_mutex_unlock()
static volatile int g_jam_mvm_mutex_cnt = 0;
static volatile module_type g_jam_mvm_mutex_tid = MOD_NIL;    
static void jam_mvm_mutex_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_jam_mvm_mutex == NULL) return;
    if (stack_get_active_module_id() != g_jam_mvm_mutex_tid)
    {
        while(g_jam_mvm_mutex_cnt > 0)
            kal_sleep_task(1);
        kal_take_mutex(g_jam_mvm_mutex);
        g_jam_mvm_mutex_tid = stack_get_active_module_id();
    }
    ++g_jam_mvm_mutex_cnt;
}
static void jam_mvm_mutex_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_jam_mvm_mutex_tid == stack_get_active_module_id());
    if(g_jam_mvm_mutex == NULL) return;
    --g_jam_mvm_mutex_cnt;

    if (g_jam_mvm_mutex_cnt == 0)
    {
        g_jam_mvm_mutex_tid = MOD_NIL;
        kal_give_mutex(g_jam_mvm_mutex);
    }
}

/***********************************************
*  mvm global resource initializer and deinitializer 
***********************************************/
static kal_int32 jam_mvm_vm_jar_path_init(kal_int32 vm_id);

static jam_mvm_context_initializer g_jam_ctxt_res_initializer_tbl[] = 
{
    /*********Add Res init begin******/
    jam_bg_call_init,
    //jam_backlight_init,   //backlight init should be happen when get device control
    jam_ca_list_init,
    jam_mvm_network_init
#ifdef SUPPORT_JSR_120    
    ,jwa_sms_initialize
#endif    
#ifdef SUPPORT_JSR_205    
    ,jwa_mms_initialize
#endif
// Aries comment
//#ifdef SUPPORT_JSR_179
//    ,jlbs_gps_initialize
//#endif
#ifdef SUPPORT_JSR_257
    ,jcc_nfc_mvm_initialize
#endif
#ifdef SUPPORT_JSR_177
    ,jsatsa_apdu_mvm_initialize
#endif
    /*********Add Res init end******/
};
static jam_mvm_context_deinitializer g_jam_ctxt_res_deinitializer_tbl[] = 
{
    /*********Add Res deinit begin*************/
    jam_mvm_network_deinit,
    jam_ca_list_deinit,
    //jam_backlight_deinit,
    jam_bg_call_deinit
#ifdef SUPPORT_JSR_120  
    ,jwa_sms_finalize
#endif    
#ifdef SUPPORT_JSR_205    
    ,jwa_mms_finalize
#endif
// Aries comment
//#ifdef SUPPORT_JSR_179
//    ,jlbs_gps_finalize
//#endif
#ifdef SUPPORT_JSR_257
    ,jcc_nfc_mvm_finalize
#endif
#ifdef SUPPORT_JSR_177
    ,jsatsa_apdu_mvm_finalize
#endif
    /*********Add Res deinit end*************/
};

/***********************************************
*  mvm vm instance resource initializer and deinitializer 
***********************************************/
static jam_mvm_instance_initializer g_jam_instance_res_initializer_tbl[] = {
    jam_mvm_vm_nw_profile_init,
    jam_mvm_vm_network_init,
    jam_mvm_vm_jar_path_init
#ifdef __DRM_SUPPORT__    
    ,jam_mvm_vm_drm_init
#endif
#ifdef SUPPORT_JSR_120
    ,jwa_sms_initialize_vm
#endif
#ifdef SUPPORT_JSR_205
    ,jwa_mms_initialize_vm
#endif
};
static jam_mvm_instance_deinitializer g_jam_instance_res_deinitializer_tbl[] = {
    jam_mvm_vm_network_deinit,
    jam_mvm_vm_nw_profile_deinit
#ifdef __DRM_SUPPORT__
    ,jam_mvm_vm_drm_deinit
#endif
#ifdef SUPPORT_JSR_120
    ,jwa_sms_finalize_vm
#endif
#ifdef SUPPORT_JSR_205    
    ,jwa_mms_finalize_vm
#endif
};

static jam_mvm_instance_struct* jam_mvm_instance_create(kal_char* storage_name, kal_int32 mid_id)
{
    kal_char* tmpStoragename = NULL;
    kal_int32 len = 0;
    jam_mvm_instance_struct* pInstance = NULL;
    kal_trace(TRACE_STATE, FUNC_JAM_MVM_INSTANCE_CREATE,storage_name, mid_id);
    pInstance = (jam_mvm_instance_struct*)jam_mvm_mem_malloc(sizeof(jam_mvm_instance_struct));
    ASSERT(pInstance != NULL);
    memset(pInstance, 0, sizeof(jam_mvm_instance_struct));
    if(storage_name)
    {
        len = strlen(storage_name);
        tmpStoragename = (kal_char*)jam_mvm_mem_malloc(len+1);
        ASSERT(tmpStoragename);
        strcpy((kal_char * )tmpStoragename,(const kal_char *) storage_name);
        pInstance->storage_name = tmpStoragename;
    }
    else
    {
        pInstance->storage_name = NULL;
    }
    pInstance->mid_id = mid_id;
    pInstance->state = JVM_TERMINATE_STATE;
    pInstance->vm_status_ind_flag = 0;
    return pInstance;
}


static void jam_mvm_instance_destroy(kal_int32 vm_id)
{
    kal_int32 retval = J2ME_NO_ERROR;
    kal_trace(TRACE_STATE, FUNC_JAM_MVM_INSTANCE_DESTROY,vm_id);
    if(g_jam_ctxt->vm_list[vm_id])
    {
        kal_int32 idx =0;
        for(idx = 0; idx <sizeof(g_jam_instance_res_deinitializer_tbl)/sizeof(jam_mvm_instance_deinitializer);idx++)
        {
            retval = g_jam_instance_res_deinitializer_tbl[idx].res_deinitializer(vm_id);
            if(retval!=J2ME_NO_ERROR)
            {
                kal_trace(TRACE_STATE, FUNC_JAM_MVM_INSTANCE_RES_DEINITIALIZER,idx,retval);
            }
        }
        jam_mvm_mem_free(g_jam_ctxt->vm_list[vm_id]->storage_name);
        jam_mvm_mem_free(g_jam_ctxt->vm_list[vm_id]->mid_name);
        jam_mvm_mem_free(g_jam_ctxt->vm_list[vm_id]->running_dir_path);
        jam_mvm_mem_free(g_jam_ctxt->vm_list[vm_id]->jar_file_path);

        jam_mvm_mem_free(g_jam_ctxt->vm_list[vm_id]);
        g_jam_ctxt->vm_list[vm_id] = NULL;
    }
}
static kal_int32 jam_mvm_context_deinit(void)
{
    kal_int32 idx = 0;
    if(g_jam_ctxt == NULL)
    {
        return J2ME_NO_ERROR;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM; idx++)
    {
        jam_mvm_instance_destroy(idx);
    }
    jam_mvm_mem_free(g_jam_ctxt);
    g_jam_ctxt = NULL;
    return J2ME_NO_ERROR;
}

static kal_int32 jam_mvm_context_init(java_mode_enum java_mode)
{
    kal_int32 idx = 0;

    if(g_jam_ctxt != NULL)
    {
       jam_mvm_context_deinit();
    }
    g_jam_ctxt = (jam_mvm_context_struct*)jam_mvm_mem_malloc(sizeof(jam_mvm_context_struct));
    ASSERT(g_jam_ctxt!=NULL);
    memset(g_jam_ctxt,0,sizeof(jam_mvm_context_struct));
    g_jam_ctxt->state = MVM_SHUTDOWN_STATE;
    g_jam_ctxt->java_mode = java_mode;
    g_jam_ctxt->current_vm_id   = INVALIDE_VM_ID;
    g_jam_ctxt->launching_vm_id = INVALIDE_VM_ID;
    g_jam_ctxt->javaheap_space = javaheap_space;
    g_jam_ctxt->javaheap_size = javaheap_size;


    for(idx = 0; idx < sizeof(g_jam_ctxt_res_initializer_tbl)/sizeof(jam_mvm_context_initializer);idx++)
    {
        g_jam_ctxt_res_initializer_tbl[idx].res_initializer();
    }
    return J2ME_NO_ERROR;
}

static kal_int32 jam_mvm_vm_jar_path_init(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle = -1;
    kal_int32 returnCode = J2ME_NO_ERROR;
    kal_int32 mids_id = 0;
    kal_wchar* wfilename = NULL;
    kal_char* storage_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( g_jam_ctxt == NULL ||
        g_jam_ctxt->java_mode != JAVA_NORMAL_MODE||
        jam_call_back_functions.jam_get_jar_path_from_storage_name == NULL
    )
    {
        kal_trace(MOD_JAM,FUNC_JAM_MVM_VM_JAR_PATH_INIT_FAIL);
        return returnCode;
    }
    storage_name = (kal_char*)jam_mvm_get_vm_storage_name(vm_id);
    wfilename = jam_call_back_functions.jam_get_jar_path_from_storage_name(jam_listmem_malloc, (kal_char*)storage_name);
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(storage_name);
    if (mids_id > j2me_default_game_count && 
        (handle = FS_Open(wfilename, (FS_READ_ONLY | FS_OPEN_SHARED))) < 0)
    {
        kal_wchar drive_path[4] = { 'c', ':', '\\', 0};
        drive_path[0] = wfilename[0];
        if ((handle = FS_Open(drive_path, (FS_READ_ONLY | FS_OPEN_SHARED))) >= 0)
        {
            FS_Close(handle);
            returnCode = JAR_NOT_FOUND;
        }
        else
        {
            returnCode = DISK_NOT_FOUND;
        }
    }
    else
    {
        if (jam_call_back_functions.jam_restore_default_game && mids_id <= j2me_default_game_count &&
            (kal_char) wfilename[0] != work_sys_dir_path[0])
        {
            if ((handle = FS_Open(wfilename, (FS_READ_ONLY | FS_OPEN_SHARED))) < 0)
            {
                jam_call_back_functions.jam_restore_default_game(mids_id);
            }
            else
            {
                FS_Close(handle);
            }
        }
    }

    if (handle > 0)
    {
        FS_Close(handle);
    }
    jam_mvm_set_vm_jar_path(vm_id,wfilename);
    jam_listmem_free(wfilename);
    return returnCode;
}

static kal_int32 jam_mvm_malloc_vm_id(void)
{
    kal_int32 idx = 0;
    ASSERT(g_jam_ctxt);
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(!g_jam_ctxt->vm_list[idx])
            break;
    }
    if(idx >= MAX_VM_INSTANCE_NUM)
        return INVALIDE_VM_ID;
    return idx;
}

static kal_bool jam_mvm_vm_is_invalid(kal_int32 vm_id)
{
    return (kal_bool)(g_jam_ctxt == NULL ||
            g_jam_ctxt->vm_count == 0 ||
            vm_id < 0 || vm_id >= MAX_VM_INSTANCE_NUM ||
            g_jam_ctxt->vm_list[vm_id] == NULL);

}
static void jam_mvm_set_vm_status_ind(kal_int32 vm_id,  kal_uint32 bit, kal_bool state)
{
    JAM_MVM_LOCK;
    if (jam_mvm_vm_is_invalid(vm_id)||
        is_vm_ind_status_set(vm_id,bit) == state
        ) 
    {
        goto DONE;
    } 
    if(state)
    {
        set_vm_ind_status(vm_id,bit);
    }
    else
    {
        reset_vm_ind_status(vm_id,bit);
    }
    DONE:
        
    JAM_MVM_UNLOCK;
}
static kal_bool jam_mvm_is_vm_status_ind(kal_int32 vm_id,kal_uint32 bit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id)|| is_vm_ind_status_set(vm_id,bit))
    {
        ret = KAL_TRUE;
    } 
    DONE:        
    JAM_MVM_UNLOCK;
    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_storage_name_by_vm_id
 * DESCRIPTION
 *  Get  storage name by vm id.
 * PARAMETERS
 *  vm_id [IN]
 * RETURNS
 *  kal_char*
 *****************************************************************************/
kal_char* jam_mvm_get_storage_name_by_vm_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_jam_ctxt == NULL|| vm_id < 0|| vm_id>MAX_VM_INSTANCE_NUM
        ||g_jam_ctxt->vm_list[vm_id]==NULL)
    {
        return NULL;
    }
    return g_jam_ctxt->vm_list[vm_id]->storage_name;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_id
 * DESCRIPTION
 *  Get vm id by storage name and mid id.
 * PARAMETERS
 *  storage_name [IN]
 *  mid_id  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_vm_id(kal_char* storage_name, kal_int32 mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || storage_name == NULL)
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(g_jam_ctxt->vm_list[idx] != NULL && 
            !strcmp((const kal_char *)(g_jam_ctxt->vm_list[idx]->storage_name), (const kal_char *)storage_name) &&
            (mid_id < 0 || g_jam_ctxt->vm_list[idx]->mid_id == mid_id))
        {
            break;
        }
    }
    if(idx >= MAX_VM_INSTANCE_NUM) 
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
DONE:
    JAM_MVM_UNLOCK;
    return idx;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_running_dir_path_by_storage_name
 * DESCRIPTION
 *  Get running_dir_path by storage name.
 * PARAMETERS
 *  storage_name [IN]
 *  mid_id  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_char* jam_mvm_get_running_dir_path_by_storage_name(kal_char* storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_char* path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || storage_name == NULL)
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(g_jam_ctxt->vm_list[idx] != NULL && 
            !strcmp((const kal_char *)(g_jam_ctxt->vm_list[idx]->storage_name), (const kal_char *)storage_name))
        {
            break;
        }
    }
    if(idx >= MAX_VM_INSTANCE_NUM) 
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
DONE:
    JAM_MVM_UNLOCK;

    if (idx != INVALIDE_VM_ID)
    {
        path = g_jam_ctxt->vm_list[idx]->running_dir_path;
    }
	
    return path;
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_id_by_drm_consume_id
 * DESCRIPTION
 *  Get vm id by drm consume_id
 * PARAMETERS
 *  kal_int32 [IN]                  
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_vm_id_by_drm_consume_id(kal_int32 consume_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || consume_id < 0)
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(g_jam_ctxt->vm_list[idx] != NULL &&
            g_jam_ctxt->vm_list[idx]->drm_consume_id == consume_id)
        {
            break;
        }
    }
    if(idx >= MAX_VM_INSTANCE_NUM) 
    {
        idx = INVALIDE_VM_ID;
        goto DONE;
    }
DONE:
    JAM_MVM_UNLOCK;
    return idx;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_current_vm_instance
 * DESCRIPTION
 *  Get currnet foreground running vm instance.
 * PARAMETERS
 *  void                 
 * RETURNS
 *  jam_mvm_instance_struct*
 *****************************************************************************/
const jam_mvm_instance_struct* jam_mvm_get_current_vm_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const jam_mvm_instance_struct* pInstance = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt && g_jam_ctxt->current_vm_id!=INVALIDE_VM_ID)
    {
        pInstance = (const jam_mvm_instance_struct*)(g_jam_ctxt->vm_list[g_jam_ctxt->current_vm_id]);
    }
    JAM_MVM_UNLOCK;
    return pInstance;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_current_storage_name
 * DESCRIPTION
 *  Get current  running vm instance.
 * PARAMETERS
 *  void                 
 * RETURNS
 *  const kal_char*
 *****************************************************************************/
const kal_char* jam_mvm_get_current_storage_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_char* storagename = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt && g_jam_ctxt->current_vm_id!=INVALIDE_VM_ID)
    {
        ASSERT(g_jam_ctxt->vm_list[g_jam_ctxt->current_vm_id]);
        storagename = (const kal_char*)(g_jam_ctxt->vm_list[g_jam_ctxt->current_vm_id]->storage_name);
    }
    JAM_MVM_UNLOCK;
    return storagename;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_reset_current_vm_id
 * DESCRIPTION
 * Set current vm_id  .
 * PARAMETERS
 *  kal_int32 vm_id              
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void jam_mvm_set_current_vm_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || g_jam_ctxt->current_vm_id == vm_id)
    {
        goto DONE;   
    }
    g_jam_ctxt->current_vm_id = vm_id;
DONE:
    JAM_MVM_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_current_vm_id
 * DESCRIPTION
 *  Get currnet foreground running midlet vm_id.
 * PARAMETERS
 *  void                 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_current_vm_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = INVALIDE_VM_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt && g_jam_ctxt->current_vm_id!=INVALIDE_VM_ID)
    {
        vm_id = g_jam_ctxt->current_vm_id;
    }
    JAM_MVM_UNLOCK;
    return vm_id;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_current_vm_mid_name
 * DESCRIPTION
 *  Get currnet foreground running midlet mid name.
 * PARAMETERS
 *  void                 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_wchar* jam_mvm_get_current_vm_mid_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_jam_ctxt)
        return jam_mvm_get_vm_mid_name(g_jam_ctxt->current_vm_id);
    else
        return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_terminate_vm
 * DESCRIPTION
 *  termiante vm instance by vm_id, can only be call by JAM.
 * PARAMETERS
 *  vm_id                 [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_terminate_vm(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        return;
    }
    kal_trace(TRACE_STATE, FUNC_JAM_MVM_TERMINATE_VM,vm_id,g_jam_ctxt->vm_count);
    JAM_MVM_LOCK;
    jam_mvm_instance_destroy(vm_id);
    g_jam_ctxt->vm_list[vm_id] = NULL;
    if(g_jam_ctxt->state == MVM_ACTIVATED_STATE || g_jam_ctxt->state == MVM_SHUTDOWNING_STATE)
    {
        --g_jam_ctxt->vm_count;
        if(g_jam_ctxt->vm_count == 0 && !jam_is_busy())
        {
            /*Since no midlet running, request to shutdown vm env*/
            jam_mvm_shutdown_all_req();
        }
    }
    else
    {
        jam_mvm_shutdown_all();
    }
    JAM_MVM_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_shutdown_all
 * DESCRIPTION
 *  After received mmi request to shut down  all vm environment,
 *  then jam call this to request vm shutdown.
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_shutdown_all_req(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || 
        g_jam_ctxt->state == MVM_SHUTDOWN_STATE ||
        g_jam_ctxt->state == MVM_SHUTDOWNING_STATE)
    {
        goto DONE;
    }
    g_jam_ctxt->state = MVM_SHUTDOWNING_STATE;
    kal_trace(TRACE_STATE, FUNC_JAM_MVM_SHUTDOWN_ALL_REQ);
    jam_shutdownAllExternal(KAL_FALSE);    
DONE:    
    JAM_MVM_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_shutdown_all
 * DESCRIPTION
 *  After received vm notify that all vm environment is shutdowned,
 *  then jam call this to release all resource.
 * PARAMETERS
 *  void 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void jam_mvm_shutdown_all(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    for(idx = 0; idx < sizeof(g_jam_ctxt_res_deinitializer_tbl)/sizeof(jam_mvm_context_deinitializer);idx++)
    {
       g_jam_ctxt_res_deinitializer_tbl[idx].res_deinitializer();
    }
    g_jam_ctxt->state = MVM_SHUTDOWN_STATE;
    jam_mvm_context_deinit();
    jam_mvm_mem_deinit();
    JAM_MVM_UNLOCK;
    g_jam_heap_is_releasing = KAL_TRUE;
    jam_mvm_whole_heap_release();
    g_jam_heap_is_releasing = KAL_FALSE;
    kal_trace(TRACE_STATE,FUNC_JAM_MVM_SHUTDOWN_ALL);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_instance
 * DESCRIPTION
 *  Create a vm instance and return vm_id, can only be call by JAM.
 * PARAMETERS
 *  storage_name       [IN] 
 *  mid_id                 [IN]
 *  java_mode           [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_vm_instance(kal_char* storage_name, kal_int32 mid_id, java_mode_enum java_mode,kal_int32* error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 retval = J2ME_NO_ERROR;
    kal_int32 vm_id= INVALIDE_VM_ID;
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(!g_jam_ctxt)
    {
        g_jam_mvm_is_alloc_heap = KAL_TRUE;
        retval = jam_mvm_whole_heap_alloc(java_mode);
        g_jam_mvm_is_alloc_heap = KAL_FALSE;
        if(retval != J2ME_NO_ERROR)
        {        
            kal_trace(TRACE_STATE, FUNC_JAM_MVM_GET_WHOLE_JAVA_HEAP,retval);
            goto DONE;
        }
        jam_mvm_mem_init();
        jam_mvm_context_init(java_mode);
    }
    g_jam_ctxt->has_launching_midlet = KAL_TRUE;
    if(g_jam_ctxt->state == MVM_SHUTDOWNING_STATE)
    {
        kal_trace(TRACE_STATE, FUNC_JAM_MVM_VM_ENV_SHUTDOWNING);
        retval = J2ME_VM_IS_BUSY;
        g_jam_ctxt->has_launching_midlet = KAL_FALSE;
        goto DONE;
    }
    if(g_jam_ctxt->current_vm_id != INVALIDE_VM_ID)
    {
        kal_trace(TRACE_STATE, FUNC_JAM_MVM_VM_GET_CURRENT_ID,g_jam_ctxt->current_vm_id);
        retval = J2ME_VM_IS_BUSY;
        g_jam_ctxt->has_launching_midlet = KAL_FALSE;
        goto DONE;
    }
    vm_id = jam_mvm_get_vm_id( storage_name, mid_id);
    if(vm_id==INVALIDE_VM_ID)
    {
        jam_mvm_instance_struct* pInstance = NULL;
        vm_id = jam_mvm_malloc_vm_id();
        if(vm_id<0)
        {
            kal_trace(TRACE_STATE, FUNC_JAM_MVM_OVER_MAX_VM_NUM);
            retval = OVER_MAX_VM_NUM;
            g_jam_ctxt->has_launching_midlet = KAL_FALSE;
            goto DONE;
        }
        pInstance = (jam_mvm_instance_struct*)jam_mvm_instance_create(storage_name, mid_id);
        ASSERT(pInstance);
        g_jam_ctxt->vm_list[vm_id] = pInstance;
        
    }
    g_jam_ctxt->launching_vm_id = vm_id;
    ++g_jam_ctxt->vm_count;
    JAM_MVM_UNLOCK;
    for(idx = 0; idx < sizeof(g_jam_instance_res_initializer_tbl)/sizeof(jam_mvm_instance_initializer);idx++)
    {
        retval = g_jam_instance_res_initializer_tbl[idx].res_initializer(vm_id);
        if(retval != J2ME_NO_ERROR)
        {        
            kal_trace(TRACE_STATE, FUNC_JAM_MVM_INSTANCE_RES_INITIALIZER,idx,retval);
            *error_code = retval;
            g_jam_ctxt->has_launching_midlet = KAL_FALSE;
            return vm_id;
        }
    } 
    JAM_MVM_LOCK;
    kal_get_time((kal_uint32 *)&(g_jam_ctxt->vm_list[vm_id]->launch_time));
    g_jam_ctxt->state = MVM_ACTIVATED_STATE;
DONE:
    JAM_MVM_UNLOCK;
    *error_code = retval;
    return vm_id;
}
kal_bool jam_mvm_has_running_vm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_int32 state;
    kal_bool ret = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if (g_jam_ctxt == NULL) 
    {
        ret = KAL_FALSE;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(g_jam_ctxt->vm_list[idx])
        {
            state = g_jam_ctxt->vm_list[idx]->state;
            if (state != JVM_TERMINATE_STATE && state != JVM_TERMINATING_STATE)
            {
                ret = KAL_TRUE;
                goto DONE;
            }
        }
    }
DONE:
    JAM_MVM_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_state
 * DESCRIPTION
 *  Get vm state by vm_id.
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_vm_state(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_state_enum state = JVM_TERMINATE_STATE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
        goto DONE;
    state =g_jam_ctxt->vm_list[vm_id]->state;
DONE:
    JAM_MVM_UNLOCK;
    return state;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_state
 * DESCRIPTION
 *  set vm state by vm_id. only can be call be jam
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
void jam_mvm_set_vm_state(kal_int32 vm_id,kal_int32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    g_jam_ctxt->vm_list[vm_id]->state = (jvm_state_enum)state;
    if(state == JVM_FG_RUNNING_STATE || state == JVM_FG_MMI_RUNNING_STATE)
    {
        ASSERT(g_jam_ctxt->current_vm_id == INVALIDE_VM_ID || g_jam_ctxt->current_vm_id == vm_id);
        g_jam_ctxt->has_launching_midlet = KAL_FALSE;
        reset_vm_ind_status(vm_id,VM_PAUSE_IND);
        reset_vm_ind_status(vm_id,VM_RESUME_IND);
        reset_vm_ind_status(vm_id,VM_TERMINATE_IND);
        reset_vm_ind_status(vm_id,VM_CALL_PAUSEAPP_IND);
        reset_vm_ind_status(vm_id,VM_AUTO_TERMINATED_IND);
    }
    
    if((state == JVM_TERMINATE_STATE ||
        (state == JVM_TERMINATING_STATE && is_vm_ind_status_set(vm_id,VM_AUTO_TERMINATED_IND)== KAL_FALSE))
        &&!jam_mvm_has_running_vm()
        && g_jam_ctxt->has_launching_midlet == KAL_FALSE
        &&!jam_is_busy())
    {
        jam_mvm_shutdown_all_req();
    }
DONE:
    JAM_MVM_UNLOCK;
}
void jam_mvm_set_vm_consume_id(kal_int32 vm_id,kal_int32 consume_id)
{
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }

    g_jam_ctxt->vm_list[vm_id]->drm_consume_id = consume_id;
DONE:
    JAM_MVM_UNLOCK;
}
kal_int32 jam_mvm_get_vm_consume_id(kal_int32 vm_id)
{
    if(jam_mvm_vm_is_invalid(vm_id))
        return JVM_TERMINATE_STATE;
    return g_jam_ctxt->vm_list[vm_id]->drm_consume_id;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_mid_name
 * DESCRIPTION
 *  set vm mdi name by vm_id. only can be call be jam
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_vm_mid_name(kal_int32 vm_id, kal_wchar* mid_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wchar* tmpMidName = NULL;
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    if(mid_name)
    {
        kal_int32 len = app_ucs2_strlen((const kal_int8 *)mid_name);
        tmpMidName = (kal_wchar*)jam_mvm_mem_malloc((len+1)<<1);
        ASSERT(tmpMidName);
        app_ucs2_strcpy((kal_int8 * )tmpMidName,(const kal_int8 *) mid_name);
    }else{
        tmpMidName = NULL;
    }
    if(g_jam_ctxt->vm_list[vm_id]->mid_name)
    {
        jam_mvm_mem_free((void *)g_jam_ctxt->vm_list[vm_id]->mid_name);
    }    
    g_jam_ctxt->vm_list[vm_id]->mid_name = tmpMidName;
DONE:
    JAM_MVM_UNLOCK;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_mid_name
 * DESCRIPTION
 *  Get vm mid name by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
kal_wchar* jam_mvm_get_vm_mid_name(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar* tmpMidName = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    tmpMidName = g_jam_ctxt->vm_list[vm_id]->mid_name;
DONE:
    JAM_MVM_UNLOCK;
    return tmpMidName;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_storage_name
 * DESCRIPTION
 *  set vm storage name by vm_id. This may be used before tck launch, called by vm.
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_vm_storage_name(kal_int32 vm_id, kal_char* storagename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* tmpstoragename = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    if(storagename)
    {
        kal_int32 len = strlen((const kal_char *)storagename);
        tmpstoragename = (kal_char*)jam_mvm_mem_malloc(len+1);
        ASSERT(tmpstoragename);
        strcpy((kal_char* )tmpstoragename,(const kal_char *) storagename);
    }
    else
    {
        tmpstoragename = NULL;
    }
    if(g_jam_ctxt->vm_list[vm_id]->storage_name)
    {
        jam_mvm_mem_free((void *)g_jam_ctxt->vm_list[vm_id]->storage_name );
    }
    g_jam_ctxt->vm_list[vm_id]->storage_name = tmpstoragename;
DONE:
    JAM_MVM_UNLOCK;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_storage_name
 * DESCRIPTION
 *  Get vm storage name by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  kal_char*
 *****************************************************************************/
kal_char* jam_mvm_get_vm_storage_name(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* storagename = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    storagename = g_jam_ctxt->vm_list[vm_id]->storage_name;
DONE:
    JAM_MVM_UNLOCK;
    return storagename;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_jar_path
 * DESCRIPTION
 *  set vm jar path by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 *  jar_path       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_vm_jar_path(kal_int32 vm_id, kal_wchar* jar_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar* tmpjarpath = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    if(jar_path)
    {
        kal_int32 len = app_ucs2_strlen((const kal_int8 *) jar_path);
        tmpjarpath = (kal_wchar*)jam_mvm_mem_malloc((len+1)<<1);
        ASSERT(tmpjarpath);
        app_ucs2_strcpy((kal_int8 *) tmpjarpath,(const kal_int8 *) jar_path);
    }
    else
    {
        tmpjarpath = NULL;
    }
    if(g_jam_ctxt->vm_list[vm_id]->jar_file_path)
    {
        jam_mvm_mem_free((void *)g_jam_ctxt->vm_list[vm_id]->jad_file_path);
    } 
    g_jam_ctxt->vm_list[vm_id]->jar_file_path = tmpjarpath;

DONE:
    JAM_MVM_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_jar_path
 * DESCRIPTION
 *  Get vm jar path by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
kal_wchar* jam_mvm_get_vm_jar_path(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar* jar_path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    jar_path = (kal_wchar*)g_jam_ctxt->vm_list[vm_id]->jar_file_path;
DONE:
    JAM_MVM_UNLOCK;
    return jar_path;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_running_dir_path
 * DESCRIPTION
 *  set running_dir_path by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 *  running_dir_path       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
// 20100920: Added for running_dir_path
void jam_mvm_set_running_dir_path(kal_int32 vm_id, kal_char* running_dir_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* tmppath = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    if(running_dir_path)
    {
        kal_int32 len = strlen(running_dir_path);
        tmppath = (kal_char*)jam_mvm_mem_malloc(len+1);
        ASSERT(tmppath);
        strcpy(tmppath, running_dir_path);
    }

    if(g_jam_ctxt->vm_list[vm_id]->running_dir_path)
    {
        jam_mvm_mem_free((void *)g_jam_ctxt->vm_list[vm_id]->running_dir_path);
    } 
    g_jam_ctxt->vm_list[vm_id]->running_dir_path = tmppath;

DONE:
    JAM_MVM_UNLOCK;
}

// 20100920: Added for running_dir_path
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_running_dir_path
 * DESCRIPTION
 *  Get running_dir_path by vm_id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  running_dir_path
 *****************************************************************************/
kal_char* jam_mvm_get_running_dir_path(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    path = (kal_char*)g_jam_ctxt->vm_list[vm_id]->running_dir_path;
DONE:
    JAM_MVM_UNLOCK;
    return path;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_storage_name
 * DESCRIPTION
 *  set vm mid_id by vm_id. This may be used before tck launch, called by vm.
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_vm_mid_id(kal_int32 vm_id, kal_int32 mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(jam_mvm_vm_is_invalid(vm_id))
    {
        goto DONE;
    }
    g_jam_ctxt->vm_list[vm_id]->mid_id= mid_id;
DONE:
    JAM_MVM_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_midlet_is_running
 * DESCRIPTION
 *  Check whether a midlet is running by storage name and mid id. 
 * PARAMETERS
 *  storage_name       [IN] 
 *  mid_id       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_midlet_is_running(kal_char* storage_name, kal_int32 mid_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = INVALIDE_VM_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_id = jam_mvm_get_vm_id((kal_char *)storage_name, mid_id);
    if(vm_id==INVALIDE_VM_ID)
        return KAL_FALSE;
    return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_midlet_is_bg_running_by_vm_id
 * DESCRIPTION
 *  Check whether a midlet is bg running by vm id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_midlet_is_bg_running_by_vm_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_state_enum state = JVM_TERMINATE_STATE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state =(jvm_state_enum)jam_mvm_get_vm_state(vm_id);
    if(state == JVM_BG_RUNNING_STATE)
        return KAL_TRUE;
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_has_running_midlet_in_mids
 * DESCRIPTION
 *  Check whether current suite has a running midlet by storage name. 
 * PARAMETERS
 *  storage_name       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_has_running_midlet_in_mids(kal_char* storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   vm_id = INVALIDE_VM_ID;
    kal_int32   idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || storage_name == NULL)
    {
        vm_id = INVALIDE_VM_ID;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if( g_jam_ctxt->vm_list[idx] != NULL && 
            g_jam_ctxt->vm_list[idx]->storage_name != NULL &&
            !strcmp((const kal_char *)(g_jam_ctxt->vm_list[idx]->storage_name), (const kal_char *)storage_name))
        {
            vm_id = idx;
            break;
        }
    }
    if(vm_id >= MAX_VM_INSTANCE_NUM) 
    {
        vm_id = INVALIDE_VM_ID;
    }
DONE:
    JAM_MVM_UNLOCK;
    return (vm_id == INVALIDE_VM_ID ? KAL_FALSE : KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_has_terminating_midlet_in_mids
 * DESCRIPTION
 *  Check whether current suite has a terminating midlet by storage name. 
 * PARAMETERS
 *  storage_name       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_has_terminating_midlet_in_mids(kal_char* storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   vm_id = INVALIDE_VM_ID;
    kal_int32   idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt == NULL || storage_name == NULL)
    {
        vm_id = INVALIDE_VM_ID;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if( g_jam_ctxt->vm_list[idx] != NULL && 
            g_jam_ctxt->vm_list[idx]->storage_name != NULL &&
            !strcmp((const kal_char *)(g_jam_ctxt->vm_list[idx]->storage_name), (const kal_char *)storage_name)
            &&g_jam_ctxt->vm_list[idx]->state == JVM_TERMINATING_STATE)
        {
            vm_id = idx;
            break;
        }
    }
    if(vm_id >= MAX_VM_INSTANCE_NUM) 
    {
        vm_id = INVALIDE_VM_ID;
    }
DONE:
    JAM_MVM_UNLOCK;
    return (vm_id == INVALIDE_VM_ID ? KAL_FALSE : KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_midlet_is_running_by_vm_id
 * DESCRIPTION
 *  Check whether current suite has a terminating midlet by vm id. 
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_midlet_is_running_by_vm_id(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_jam_ctxt == NULL ||g_jam_ctxt->vm_list[vm_id]==NULL)
        return KAL_FALSE;
    return KAL_TRUE;
}

kal_int32 jam_mvm_get_javaheap_size(void)
{
    ASSERT(g_jam_ctxt);
    return g_jam_ctxt->javaheap_size;
}
long* jam_mvm_get_javaheap_space(void)
{
    ASSERT(g_jam_ctxt);
    return g_jam_ctxt->javaheap_space;
}
java_mode_enum jam_mvm_get_java_mode(void)
{
    if(g_jam_ctxt==NULL)
    {
        return JAVA_NORMAL_MODE;
    }
    else
    {
        return g_jam_ctxt->java_mode;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_running_count
 * DESCRIPTION
 *  Get current running mdilet count.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_running_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(g_jam_ctxt != NULL)
    {
        idx = g_jam_ctxt->vm_count;
    }
    JAM_MVM_UNLOCK;
    return idx;
}

kal_int32 jam_mvm_get_bg_running_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_int32 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM; idx++)
    if(g_jam_ctxt != NULL)
    {
        if(g_jam_ctxt->vm_list[idx] != NULL&&
            g_jam_ctxt->vm_list[idx]->state == JVM_BG_RUNNING_STATE)
            count++;
    }
    JAM_MVM_UNLOCK;
    return count;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_shutdowning
 * DESCRIPTION
 *  Get current vm environment is shutdowning.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_shutdowning(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)((g_jam_heap_is_releasing == KAL_TRUE)||
            (g_jam_ctxt != NULL && 
            g_jam_ctxt->state == MVM_SHUTDOWNING_STATE));
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_shutdown
 * DESCRIPTION
 *  Get current vm environment is shutdown.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_shutdown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)(g_jam_ctxt == NULL || g_jam_ctxt->state == MVM_SHUTDOWN_STATE);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_find_vm_instance
 * DESCRIPTION
 *  Find and get mvm instance by vm_id.
 * PARAMETERS
 *  vm_id       [IN] 
 * RETURNS
 *  jam_mvm_instance_struct*
 *****************************************************************************/
jam_mvm_instance_struct* jam_mvm_find_vm_instance(kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_mvm_instance_struct* pInstance = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if(vm_id>INVALIDE_VM_ID && vm_id < MAX_VM_INSTANCE_NUM &&
        g_jam_ctxt && g_jam_ctxt->vm_list[vm_id] != NULL)
        pInstance = g_jam_ctxt->vm_list[vm_id];
    JAM_MVM_UNLOCK;
    return pInstance;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_has_work_instance
 * DESCRIPTION
 *  Check whether there are  work instance in mvm context.
 * PARAMETERS
 *  driver       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_has_work_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_int32 state;
    kal_bool ret = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if (g_jam_ctxt == NULL) 
    {
        ret = KAL_FALSE;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM;idx++)
    {
        if(g_jam_ctxt->vm_list[idx])
        {
            state = g_jam_ctxt->vm_list[idx]->state;
            if (state == JVM_FG_RUNNING_STATE || state == JVM_FG_MMI_RUNNING_STATE || 
                state == JVM_BG_RUNNING_STATE)
            {
                ret = KAL_TRUE;
                goto DONE;
            }
        }
    }
DONE:
    JAM_MVM_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_has_running_vm_on_driver
 * DESCRIPTION
 *  Check whether there are some midlet running on  given driver.
 * PARAMETERS
 *  driver       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_has_running_vm_on_driver(kal_int8 driver)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    kal_int32 idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JAM_MVM_LOCK;
    if (g_jam_ctxt == NULL) 
    {
        ret = KAL_FALSE;
        goto DONE;
    }
    for(idx = 0; idx < MAX_VM_INSTANCE_NUM; idx++)
    {
        if( (g_jam_ctxt->vm_list[idx] != NULL)&&
            (g_jam_ctxt->vm_list[idx]->running_dir_path != NULL) &&
            (g_jam_ctxt->vm_list[idx]->running_dir_path[0] == driver))
        {
            ret = KAL_TRUE;
            break;
        }
    }
DONE:
    JAM_MVM_UNLOCK;
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_running_mids_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  driver       [IN] 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
mmi_running_mid* jam_mvm_get_running_mids_list(kal_int32* err_code, kal_int32 * count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_running_mid* mid_list_ptr = NULL;
    kal_int32 idx = 0, jdx = 0, inserted_count = 0;
    kal_int32 name_len = 0;
    kal_int32 list_order[MAX_VM_INSTANCE_NUM] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *count = 0;
    JAM_MVM_LOCK;
    if (g_jam_ctxt == NULL ||
        g_jam_ctxt->vm_count == 0 ) 
    {
        *err_code = J2ME_NO_ERROR;
        goto DONE;
    }    
    /* order by launch time*/
    for(idx = 0, inserted_count = 0; idx < MAX_VM_INSTANCE_NUM; idx++)
    {
        list_order[idx] = INVALIDE_VM_ID;
        if(g_jam_ctxt->vm_list[idx] == NULL)
            continue;
        ++inserted_count;
        list_order[inserted_count-1] = idx;
        for(jdx = inserted_count -1;jdx>0;jdx--)
        {
            kal_int32 jdx_1_vm_id = list_order[jdx-1];
            kal_int32 jdx_vm_id = list_order[jdx];
            if(g_jam_ctxt->vm_list[jdx_vm_id]->launch_time < g_jam_ctxt->vm_list[jdx_1_vm_id]->launch_time) 
            {
                list_order[jdx-1] = jdx_vm_id;
                list_order[jdx] = jdx_1_vm_id;
            }
            else
            {
                break;
            }
        }
        
    }

    mid_list_ptr = (mmi_running_mid* )get_ctrl_buffer(sizeof(mmi_running_mid) * g_jam_ctxt->vm_count );
    for(idx = 0; idx < g_jam_ctxt->vm_count; idx++)
    {
        kal_int32 vm_id = list_order[idx];
        mid_list_ptr[idx].vm_id = vm_id;
        name_len = app_ucs2_strlen((const kal_int8 * )g_jam_ctxt->vm_list[vm_id]->mid_name);
        mid_list_ptr[idx].mid_name = (kal_wchar *)get_ctrl_buffer((name_len + 1)* 2);
        app_ucs2_strcpy((kal_int8*)mid_list_ptr[idx].mid_name,(const kal_int8*) g_jam_ctxt->vm_list[vm_id]->mid_name);
    }
    *count = g_jam_ctxt->vm_count;
    
DONE:
    JAM_MVM_UNLOCK;
    kal_trace(TRACE_STATE, FUNC_JAM_MVM_GET_RUNNING_LIST,*count);

    return mid_list_ptr;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_has_fg_running_vm
 * DESCRIPTION
 *  Get if there is fg runing vm
 * PARAMETERS
 *  void                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_has_fg_running_vm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)(g_jam_ctxt && g_jam_ctxt->current_vm_id!=INVALIDE_VM_ID);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_max_num
 * DESCRIPTION
 *  Get max midlet num, which can be run.
 * PARAMETERS
 *  void                 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_get_max_vm_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MAX_VM_INSTANCE_NUM;
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_notifyed_stopped
 * DESCRIPTION
 *  This function is used by JVM task to check whether this vm has been requested to stop,
 * if yes, then no need to send jam_jvm_send_mid_stop_req.
 * Otherwise, send jam_jvm_send_mid_stop_req
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_vm_notifyed_stopped(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_STOP_IND);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_notifyed_stopped
 * DESCRIPTION
 *  if jvm send jam_jvm_send_mid_stop_req. then set vm instance flag, 
 * so that it will not be send again.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_vm_notifyed_stopped(kal_int32 vm_id)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_STOP_IND,KAL_TRUE);
}

 /*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_pause_ind
 * DESCRIPTION
 *  if jvm send jam_mvm_send_pause_ind. then set vm instance flag, 
 * so that it will not be send again.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_vm_pause_ind(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_PAUSE_IND);
}
void    jam_mvm_set_vm_pause_ind(kal_int32 vm_id, kal_bool state)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_PAUSE_IND,state);
}
/*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_resume_ind
 * DESCRIPTION
 *  if jvm send jam_mvm_send_resume_ind. then set vm instance flag, 
 * so that it will not be send again.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_vm_resume_ind(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_RESUME_IND);
}
void    jam_mvm_set_vm_resume_ind(kal_int32 vm_id, kal_bool state)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_RESUME_IND,state);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_resume_ind
 * DESCRIPTION
 *  if jvm send jam_mvm_send_resume_ind. then set vm instance flag, 
 * so that it will not be send again.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_is_vm_terminate_ind(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_TERMINATE_IND);
}
void    jam_mvm_set_vm_terminate_ind(kal_int32 vm_id, kal_bool state)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_TERMINATE_IND,state);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_vm_is_auto_terminated
 * DESCRIPTION
 *  check if vm is auto terminated itself.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_mvm_get_vm_is_auto_terminated(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_AUTO_TERMINATED_IND);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_is_auto_terminated
 * DESCRIPTION
 *  set if vm is auto terminated itself.
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void  jam_mvm_set_vm_is_auto_terminated(kal_int32 vm_id, kal_bool auto_teriminated)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_AUTO_TERMINATED_IND,auto_teriminated);
}

kal_bool jam_mvm_is_vm_need_call_pauseapp(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_CALL_PAUSEAPP_IND);
}
void jam_mvm_set_vm_need_call_pauseapp(kal_int32 vm_id, kal_bool state)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_CALL_PAUSEAPP_IND,state);
}
kal_bool jam_mvm_is_vm_vk_on(kal_int32 vm_id)
{
    return jam_mvm_is_vm_status_ind(vm_id,VM_IS_VK_ON_IND);
}
void jam_mvm_set_vm_vk_on(kal_int32 vm_id, kal_bool is_on)
{
    jam_mvm_set_vm_status_ind(vm_id,VM_IS_VK_ON_IND,is_on);
}

 /*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_support_bg
 * DESCRIPTION
 * Query if current MIDlet suite can enable background running.
 * PARAMETERS
 *  vm_id            
 * RETURNS
 *  Support or not
 *****************************************************************************/
 kal_bool jam_mvm_is_vm_support_bg(kal_int32 vm_id)
 {
#ifdef J2ME_SUPPORT_BACKGROUND
    kal_bool is_on;
    if(srv_java_appfactory_get_bg_enabled(&is_on, vm_id) == KAL_FALSE)
    {
        return KAL_TRUE;
    }
    return is_on;
#else
    return KAL_FALSE;
#endif
 }

 /*****************************************************************************
 * FUNCTION
 *  jam_mvm_is_vm_support_disable_bg
 * DESCRIPTION
 * Query if we support background running diable. This feature only supported on Cosmos slim project
 * PARAMETERS
 *  vm_id            
 * RETURNS
 *  Support or not
 *****************************************************************************/
 kal_bool jam_mvm_is_vm_support_disable_bg(kal_int32 vm_id)
 {
     kal_int32 heapsize = DEFAULTHEAPSIZE; 
	 
#if defined (J2ME_SUPPORT_BACKGROUND) && defined (__COSMOS_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT) 
    if(heapsize > 2*1024*1024 + 500 *1024)
    {
        return KAL_TRUE; 
    }
    else
    {
        return KAL_FALSE;
    }
#else
    return KAL_FALSE;
#endif

 }

 /*****************************************************************************
 * FUNCTION
 *  jam_mvm_disable_vm_support_bg
 * DESCRIPTION
 * Set background running enable or disable
 * PARAMETERS
 *  vm_id            
 * RETURNS
 *  Success or not
 *****************************************************************************/
kal_bool jam_mvm_disable_vm_support_bg(kal_int32 vm_id)
{
#ifdef J2ME_SUPPORT_BACKGROUND

		return srv_java_appfactory_set_bg_enabled(KAL_FALSE, vm_id);
#else
		return KAL_TRUE;
#endif

}


 /*****************************************************************************
 * FUNCTION
 *  jam_mvm_set_vm_notifyed_stopped
 * DESCRIPTION
 * Force to set ctxt state shutdowning to block midlet launching,
 * this happened for some exception, this function only can be call in before 
 * jam_jvm_send_shutdown_all_notify()
 * PARAMETERS
 *  kal_int32                 
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_set_ctxt_shutdowning(void)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    JAM_MVM_LOCK;
    if (g_jam_ctxt == NULL) 
    {
        goto DONE;
    } 
    g_jam_ctxt->state = MVM_SHUTDOWNING_STATE;
    DONE:        
    JAM_MVM_UNLOCK;
    return ;

}


kal_bool jam_mvm_get_bg_running_vm(kal_bool * vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(vm_id != NULL);
    for( idx = 0 ; idx < MAX_VM_INSTANCE_NUM ; idx ++)
        vm_id[idx] = KAL_FALSE;
    
    if(g_jam_ctxt == NULL)
        return KAL_FALSE;
    
    JAM_MVM_LOCK;

    for(idx = 0; idx < MAX_VM_INSTANCE_NUM; idx++)
    {
        if(g_jam_ctxt->vm_list[idx] != NULL&&g_jam_ctxt->vm_list[idx]->state == JVM_BG_RUNNING_STATE)
            vm_id[idx] = KAL_TRUE;
    }
    JAM_MVM_UNLOCK;
    return KAL_TRUE;
}


kal_bool jam_mvm_has_launching_midlet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jam_ctxt)
    {
        return (g_jam_ctxt->has_launching_midlet || g_jam_mvm_is_alloc_heap);
    }
    return KAL_FALSE;
}

extern kal_eventgrpid g_java_event_group_2;
void jam_mvm_retrieve_asm_eg_event(void)
{
    U32 event_group;
    if(g_jam_mvm_mutex_tid == stack_get_active_module_id())
    {
        JAM_MVM_UNLOCK;
        kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_ASM, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
        JAM_MVM_LOCK;
    }
    else
    {
        kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_ASM, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
    }
}


