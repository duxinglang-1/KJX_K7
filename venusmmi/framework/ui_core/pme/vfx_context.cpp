/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_context.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Framework VfxContext Class
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
#include "GlobalResDef.h"
#include "vfx_sys_mem_config.h"
#ifdef __cplusplus
} /* extern "C"*/
#endif 
#include "vfx_context.h"
// For vfx_sys_mem_get_global_allocator()

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vrt_sub_allocator.h"


/***************************************************************************** 
 * Class VfxContext
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_CONTEXT_CLASS_NAME, VfxContext, VfxObject);

VfxContext::VfxContext() : m_allocatorHandle(NULL), m_buf(NULL), m_bufSize(0)
{
}


VfxContext::~VfxContext()
{
    VFX_DEV_ASSERT(m_allocatorHandle == NULL);
}


void VfxContext::assignPool(mmi_id app_id, VfxU8 *buf, VfxU32 bufSize, VfxBool logFlag)
{
    VFX_ASSERT(buf != NULL && bufSize != 0);
    
    deletePool();
    createPool(app_id, buf, bufSize, logFlag);
}


void VfxContext::assignPool(VfxU8 *buf, VfxU32 bufSize, VfxBool logFlag)
{
    VFX_ASSERT(buf != NULL && bufSize != 0);
    
    deletePool();
    createPool(GRP_ID_INVALID, buf, bufSize, logFlag);
}


void VfxContext::assignPoolWithSlmm(mmi_id app_id, U32 mem_size, VfxBool logFlag)
{
  #if defined __MMI_USE_MMV2__ 
    VFX_ASSERT(mem_size != 0);
    deletePool();
    createPoolWithSlmm(app_id, mem_size, logFlag);
  #else
    VFX_ASSERT(0);    
  #endif
}


VfxU32 VfxContext::backwardEnlargeHeapSize(mmi_id app_id)
{
  #if defined __MMI_USE_MMV2__ 
    VfxU32 size = getShrinkSize(app_id);
    if (size == VFX_CONTEXT_SIZE_NO_CHANGE)
        return 1;
    return vfx_sys_mem_pool_backward_enlarge_slmm_heap(app_id, m_allocatorHandle, getBufSize());
  #else
    VFX_ASSERT(0);    
    return 0;
  #endif
}


VfxU32 VfxContext::shrinkHeapSize(mmi_id app_id)
{
  #if defined __MMI_USE_MMV2__ 
    VfxU32 size = getShrinkSize(app_id);
    if (size == VFX_CONTEXT_SIZE_NO_CHANGE)
        return 1;
    return vfx_sys_mem_pool_shrink_slmm_heap(app_id, m_allocatorHandle, size);
  #else
    VFX_ASSERT(0);    
    return 0;
  #endif
}


VfxU32 VfxContext::enlargeHeapSize(mmi_id app_id, mmi_proc_func func, void *user_data, VfxU32 flag)
{
  #if defined __MMI_USE_MMV2__ 
    VfxU32 shrinkSize = getShrinkSize(app_id);
    VfxU32 size = getBufSize();
    if (shrinkSize == VFX_CONTEXT_SIZE_NO_CHANGE)
        return 1;
    return vfx_sys_mem_pool_enlarge_slmm_heap(app_id, m_allocatorHandle, size,
                                              func, user_data, flag );   
  #else
    VFX_ASSERT(0);    
    return 0;
  #endif
}

void VfxContext::onAfterDeinit()
{
    // All child objects are closed, delete the memory pool
    deletePool();
    
    VfxObject::onAfterDeinit();
}


void VfxContext::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT:
        {
            onAfterDeinit();
            return;
        }
        default:
        {
            VfxObject::onObjectNotify(id, userData);
            return;
        }
    }
}

void VfxContext::statistics(vfx_sys_mem_pool_status_struct &output)
{
    vfx_sys_mem_pool_allocator_get_status(m_allocatorHandle, &output);
}


vrt_allocator_handle VfxContext::getAllocator()
{
    return m_allocatorHandle;
}


void VfxContext::createPool(mmi_id app_id, VfxU8 *buf, VfxU32 bufSize, VfxBool logFlag)
{
    VFX_DEV_ASSERT(buf != NULL && bufSize != 0);
    VFX_DEV_ASSERT(m_allocatorHandle == NULL);
    
#if defined(__VFX_HEAP_PROFILE__)
    vfx_heap_profiling_set_isObj_callback(VfxObject::static_isObjCheck);
    if (!logFlag && vfx_heap_profiling_check(app_id, bufSize))
    {   
        /*Enable the log if the app is profile target*/
        logFlag = VFX_TRUE;
    }
#endif

    VfxFlag flags = VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE;

    if (logFlag)
    {
        VFX_FLAG_SET(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING);
    }

    m_allocatorHandle = vfx_sys_mem_pool_allocator_create(
        buf, 
        bufSize,
        flags);
    vfx_sys_mem_pool_set_property(
        (vfx_sys_mem_pool_handle)vrt_allocator_get_info(m_allocatorHandle)->user_data, 
        (void*)app_id, 
        VFX_SYS_MEM_POOL_SET_APP_ID_PROPERTY_FLAG);
    
    m_buf = buf;
    m_bufSize = bufSize;
}


void VfxContext::createPoolWithSlmm(mmi_id app_id, U32 mem_size, VfxBool logFlag)
{
#if defined(__MMI_USE_MMV2__)
    VFX_DEV_ASSERT(m_allocatorHandle == NULL);

    VfxFlag flags = VFX_SYS_MEM_POOL_CREATE_FLAG_ASM_SLMM | VFX_SYS_MEM_POOL_CREATE_FLAG_THREAD_SAFE;
    
#if defined(__VFX_HEAP_PROFILE__)
    vfx_heap_profiling_set_isObj_callback(VfxObject::static_isObjCheck);
    if (!logFlag && vfx_heap_profiling_check(app_id, mem_size))
    {   
        /*Enable the log if the app is profile target*/
        logFlag = VFX_TRUE;
    }
#endif /* defined(__VFX_HEAP_PROFILE__)*/

    if (logFlag)
    {
        VFX_FLAG_SET(flags, VFX_SYS_MEM_POOL_CREATE_FLAG_ENABLE_LOGGING);
    }

    m_allocatorHandle = vfx_sys_mem_pool_allocator_create((VfxU8 *)app_id, mem_size, flags);
    m_bufSize = mem_size;

#else /* defined(__MMI_USE_MMV2__) */
    VFX_ASSERT(0);
#endif /* defined(__MMI_USE_MMV2__) */
}


void VfxContext::deletePool()
{
    if (m_allocatorHandle == NULL)
    {
        // Do nothing
        return;

    }

    vrt_allocator_release(m_allocatorHandle);

    // Reset all data
    m_allocatorHandle = NULL;
    m_buf = NULL;
    m_bufSize = 0;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
void VfxContext::assignPoolWithAllocator(vrt_allocator_handle allocator, VfxBool logFlag)
{
    m_allocatorHandle = allocator;
    m_buf = NULL;
    m_bufSize = 0;
}
#endif

/***************************************************************************** 
 * Class VfxSysGlobalContext
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VfxSysGlobalContext", VfxSysGlobalContext, VfxContext);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxSysGlobalContext);

vrt_allocator_handle VfxSysGlobalContext::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}


/***************************************************************************** 
 * Class VfxSubContext
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxSubContext", VfxSubContext, VfxContext);

VfxSubContext::VfxSubContext() : m_allocator(NULL)
{
}


void VfxSubContext::setContext(VfxContext *parent)
{
    VFX_ASSERT(parent && !m_allocator);
    m_allocator = vrt_sub_allocator_create(parent->getAllocator());
}


void VfxSubContext::onDeinit()
{
    vrt_allocator_release(m_allocator);
}


vrt_allocator_handle VfxSubContext::getAllocator()
{
    VFX_ASSERT(m_allocator);
    return m_allocator;
}


/***************************************************************************** 
 * Class VfxTmpContext
 *****************************************************************************/

VfxTmpContext::VfxTmpContext()
{
    m_allocator = vrt_sub_allocator_create(vfx_sys_mem_get_global_allocator());
}


VfxTmpContext::~VfxTmpContext()
{
    vrt_allocator_release(m_allocator);
}


vrt_allocator_handle VfxTmpContext::getAllocator()
{
    VFX_ASSERT(m_allocator);
    return m_allocator;
}

