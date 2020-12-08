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
 *  vfx_object.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Define VfxObject, the base class of Venus UI Framework.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_object.h"

#include "vfx_weak_ptr.h"

// For vfx_sys_mem_get_global_allocator()
#include "vfx_sys_mem_config.h"

#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_context.h"

#include <string.h>

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
#include "vpi_system.h"
#endif

/***************************************************************************** 
 * Class VfxObjHandleEntry
 *****************************************************************************/

struct VfxObjHandleEntry
{
    VfxObject   *obj;
    VfxU32      handle;
};


/***************************************************************************** 
 * Class VfxAttachProperties
 *****************************************************************************/

#define VFX_AP_ENTRY_SIZE(e)    (((e)->propId & 0x80000000) ? 4 : *((VfxU32*)((e)->dataPtr)))

class VfxAttachProperties : public VfxBase
{
    friend class VfxObject;
// Constructor / Destructor
private:
    // Default constructor
    VfxAttachProperties();
    virtual ~VfxAttachProperties();

public:
    VfxBool add(VfxId propId, void *data, VfxU32 size, VfxBool updateIfExist, VfxObject *parent);
    VfxBool remove(VfxId propId);

    void *query(VfxId propId, VfxU32 *size) const;
    VfxU32 count() const { return m_count; }

private:
    typedef struct {
        VfxId propId;
        VfxU8* dataPtr;
    } entry;

    VfxU32 findNearest(VfxId propId) const;
    void freeEntry(entry *item);

private:

    entry *m_buf;
    VfxU32 m_bufLen;
    VfxU32 m_count;

};


VfxAttachProperties::VfxAttachProperties() :
    m_buf(NULL),
    m_bufLen(0),
    m_count(0)
{
}


VfxAttachProperties::~VfxAttachProperties()
{
    if(m_buf)
    {
        entry *s,*e;
        
        for(s=m_buf,e=m_buf+m_count;s<e;s++)
            freeEntry(s);

        VFX_FREE_MEM(m_buf);
    }
}


VfxBool VfxAttachProperties::add(VfxId propId, void *data, VfxU32 size, VfxBool updateIfExist, VfxObject *parent)
{
    if(!propId)
        return VFX_FALSE;

    VfxU32 i, j;

    i = findNearest(propId);
    if(m_buf && (m_buf[i].propId & 0x7FFFFFFF) == propId && i < m_count)
    {
        // update, check size & update
        VfxU32 dSize = VFX_AP_ENTRY_SIZE(&m_buf[i]);
        VfxU32 sSize = size < 4 ? 4 : size;
        if(dSize != sSize || !updateIfExist)
            return VFX_FALSE;
    }
    else
    {
        // add one
        if(m_count == m_bufLen)
        {
            // reallocation
            m_bufLen += 8;
            entry *buf2;
            VFX_ALLOC_MEM(buf2, sizeof(entry) * m_bufLen, parent);
            if(m_buf)
            {
                memcpy(buf2, m_buf, sizeof(entry) * m_count);
                VFX_FREE_MEM(m_buf);
            }
            m_buf = buf2;
        }

        // shift
        for(j=m_count;j>i;j--)
            m_buf[j] = m_buf[j-1];

        m_buf[i].dataPtr = NULL;
        m_buf[i].propId = 0;

        m_count++;
    }

    if(size <= 4)
    {
        m_buf[i].propId = propId | 0x80000000;
        switch(size)
        {
        case 1:
            m_buf[i].dataPtr = (VfxU8*)(*(VfxU8*)data);
            break;
        case 2:
            m_buf[i].dataPtr = (VfxU8*)(*(VfxU16*)data);
            break;
        case 4:
            m_buf[i].dataPtr = (VfxU8*)(*(VfxU32*)data);
            break;
        default:
            VFX_DEV_ASSERT(0);
            return VFX_FALSE;
        }
    }
    else
    {
        m_buf[i].propId = propId;
        if(!m_buf[i].dataPtr)
            VFX_ALLOC_MEM(m_buf[i].dataPtr, size + 4, parent);
        *((VfxU32*)m_buf[i].dataPtr) = size;
        memcpy(m_buf[i].dataPtr + 4, data, size);
    }

    return VFX_TRUE;
}


VfxBool VfxAttachProperties::remove(VfxId propId)
{
    if(!m_count)
        return VFX_FALSE;

    VfxU32 i = findNearest(propId);
    if(i >= m_count)
        return VFX_FALSE;
    if((m_buf[i].propId & 0x7FFFFFFF) != propId)
        return VFX_FALSE;

    freeEntry(&m_buf[i]);

    // shift back
    VfxU32 j;
    for(j=i;j+1<m_count;j++)
        m_buf[j] = m_buf[j+1];

    m_count--;

    m_buf[m_count].propId = 0;
    m_buf[m_count].dataPtr = NULL;
    return VFX_TRUE;
}


void *VfxAttachProperties::query(VfxId propId, VfxU32 *size) const
{
    if(!m_count)
        return NULL;

    VfxU32 i = findNearest(propId);
    if(i >= m_count)
        return NULL;
    if((m_buf[i].propId & 0x7FFFFFFF) != propId)
        return NULL;

    if(size)
        *size = VFX_AP_ENTRY_SIZE(&m_buf[i]);

    if(m_buf[i].propId & 0x80000000)
    {
        return &(m_buf[i].dataPtr);
    }
    else
    {
        return m_buf[i].dataPtr + 4;
    }

}


VfxU32 VfxAttachProperties::findNearest(VfxId propId) const
{
    if(!m_count)
        return 0;
    // binary search
    VfxS32 low, mid, high;

    low = 0;
    high = m_count;
    mid = (low+high)/2;

    do
    {
        if((m_buf[mid].propId & 0x7FFFFFFF) > propId)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }

        mid = (low + high)/2;
    } while(mid != low);

    return (m_buf[low].propId & 0x7FFFFFFF) >= propId ? low : low+1;
}


void VfxAttachProperties::freeEntry(entry *item)
{
    if((item->propId & 0x80000000) == 0)
    {
        VFX_FREE_MEM(item->dataPtr);
    }
    item->propId = 0;
    item->dataPtr = NULL;
}


/***************************************************************************** 
 * Class VfxObject
 *****************************************************************************/
 
const vfx_class_info_struct VfxObject::s_classInfo = {VFX_OBJECT_CLASS_NAME, NULL, NULL};

VfxObjHandleEntry *VfxObject::s_objHandleList = NULL;
VfxU32 VfxObject::s_objHandleListSize = 0;
VfxU32 VfxObject::s_objHandleListCount = 0;
VfxU32 VfxObject::s_objHandleNext = 1;


VfxClassInfo *VfxObject::getVfxObjectClassInfo()
{
    return (VfxClassInfo *)&s_classInfo;
}


VfxWeakPtrFlag *VfxObject::getWeakPtrFlag()
{
    vfx_sys_acquire_weak_obj_hdl_lock();
    if (m_weakPtrFlag == NULL)
    {
        m_weakPtrFlag = VfxWeakPtrFlag::createFlag(this);
    }
    vfx_sys_release_weak_obj_hdl_lock();

    return m_weakPtrFlag;
}


void VfxObject::resetWeakPtrFlag()
{
    VFX_DEV_ASSERT(m_weakPtrFlag != NULL);
    m_weakPtrFlag = NULL;
}


VfxObjHandle VfxObject::getObjHandle() const
{
    VfxObjHandle result = NULL;
    
    vfx_sys_acquire_obj_hdl_lock();    
    
    do 
    {
        if (VFX_FLAG_HAS(m_objFlags, FLAGS_HAS_HANDLE))
        {
            // already has handle, query it
            VfxObjHandleEntry *cur, *end;
            cur = s_objHandleList;
            end = s_objHandleList + s_objHandleListCount;

            while (cur < end)
            {
                if(cur->obj == this)
                {
                    result = (VfxObjHandle)cur->handle;
                    break;
                }

                cur++;
            }
        }
        else
        {
            // no handle, create one
            VFX_FLAG_SET(m_objFlags, FLAGS_HAS_HANDLE);

            if (s_objHandleListCount == s_objHandleListSize)
            {
                // need reallocate
                s_objHandleListSize += 4;

                VfxObjHandleEntry *newList;
                VFX_SYS_ALLOC_MEM(newList, sizeof(VfxObjHandleEntry) * s_objHandleListSize);

                if (s_objHandleList)
                {
                    memcpy(newList, s_objHandleList, sizeof(VfxObjHandleEntry) * s_objHandleListCount);
                    VFX_FREE_MEM(s_objHandleList);
                }
                
                s_objHandleList = newList;
            }

            // make sure no overflow happen
            VFX_ASSERT(s_objHandleListCount == 0 || (s_objHandleList+s_objHandleListCount-1)->handle < s_objHandleNext);

            VfxObjHandleEntry *end = s_objHandleList + s_objHandleListCount;
            end->handle = s_objHandleNext;
            end->obj = const_cast <VfxObject *> (this);
            s_objHandleNext++;
            s_objHandleListCount++;

            result = (VfxObjHandle)end->handle;
        }
    }while(0);

    vfx_sys_release_obj_hdl_lock();

    VFX_DEV_ASSERT(result);
    return result;
}


VfxObject *VfxObject::handleToObject(VfxObjHandle handle)
{
    VfxObject *result = NULL;

    vfx_sys_acquire_obj_hdl_lock();
    do {
        if(!s_objHandleListCount)
            break;

        VfxS32 low, mid, high;

        low = 0;
        high = s_objHandleListCount;
        mid = (low+high)/2;

        do
        {
            if(s_objHandleList[mid].handle > (VfxU32)handle)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }

            mid = (low + high)/2;
        } while(mid != low);

        if(s_objHandleList[low].handle == (VfxU32)handle)
            result = s_objHandleList[low].obj;
    }while(0);

    vfx_sys_release_obj_hdl_lock();
    return result;
}

VfxU32 VfxObject::static_isObjCheck(void* ptr, void** parent_p)
{
    VfxObject *obj = (VfxObject *)ptr;

    if (obj->m_guard == VFX_OBJ_CREATED_GUARD_PATTERN)
    {
        *parent_p = (void*) obj->m_parentObj;
        return 1;
    }
    else
    {
        return 0;
    }

}

VfxObject::VfxObject() : 
    m_guard(VFX_OBJ_CREATED_GUARD_PATTERN),
    m_objFlags(0),
    m_weakPtrFlag(NULL),
    m_parentObj(NULL),
    m_firstChildObj(NULL),
    m_lastChildObj(NULL),
    m_nextObj(NULL),    
    m_prevObj(NULL),
    m_attachProps(NULL)
{
}


VfxObject::~VfxObject()
{
    VFX_DEV_ASSERT(m_guard == VFX_OBJ_CREATED_GUARD_PATTERN);
    
    // NOTE: Must use VFX_CLOSE() to destroy an object or it will cause this assert
    VFX_ASSERT(m_parentObj == NULL);
    
    // Invalidate the weak pointer flag
    if (m_weakPtrFlag != NULL)
    {
        m_weakPtrFlag->invalidate();
        m_weakPtrFlag = NULL;
    }

    if(VFX_FLAG_HAS(m_objFlags, FLAGS_HAS_HANDLE))
    {
        vfx_sys_acquire_obj_hdl_lock();
        
        VfxObjHandleEntry *cur, *end;
        cur = s_objHandleList;
        end = s_objHandleList + s_objHandleListCount;

        while(cur < end)
        {
            if(cur->obj != this)
            {
                cur++;
                continue;
            }

            // found, remove this entry
            while(cur + 1 < end)
            {
                *cur = *(cur+1);
                cur++;
            }
            s_objHandleListCount--;
            break;
        }

        vfx_sys_release_obj_hdl_lock();
    }

    if(m_attachProps)
    {
        VFX_DELETE(m_attachProps);
    }

    // Update the guard patten
    m_guard = VFX_OBJ_DESTROYED_GUARD_PATTERN;
}


void VfxObject::_init(VfxObject *objParent)
{
    // set flags to init
    VFX_FLAG_SET(m_objFlags, FLAGS_OBJ_INITING);

    // Assign the parent object
    setParent(objParent);

    // Callback onInit()
    onInit();
//    onAfterInit();
    onObjectNotify(VFX_OBJECT_NOTIFY_ID_AFTER_INIT, NULL);

    // clear flags
    VFX_FLAG_CLEAR(m_objFlags, FLAGS_OBJ_INITING);
}


void VfxObject::_deinit()
{
    // NOTE: Assert here if the object has been closed
    VFX_ASSERT(m_guard == VFX_OBJ_CREATED_GUARD_PATTERN);

    // NOTE: Assert here if the object enter _deinit twice
    VFX_ASSERT(!VFX_FLAG_HAS(m_objFlags, FLAGS_OBJ_DEINITING));

    // NOTE: Assert here if the object be closed when creating it.
    VFX_ASSERT(!VFX_FLAG_HAS(m_objFlags, FLAGS_OBJ_INITING));

    // set flags to deinit
    VFX_FLAG_SET(m_objFlags, FLAGS_OBJ_DEINITING);

    // Callback onDeinit()
//    onBeforeDeinit();    
    onObjectNotify(VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT, NULL);
    onDeinit();    

    // Close all child objects
    releaseAllChild();

    // Callback onAfterDeinit()
//    onAfterDeinit();
    onObjectNotify(VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT, NULL);

    // Remove the relation to parent object
    removeFromParent();
}


void VfxObject::_close()
{
    _deinit();
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    if (VFX_FLAG_HAS(m_objFlags, FLAGS_HAS_PROXY))
    {
        vpiSysCloseProxy(this);
    }
#endif
    delete this;
}


void VfxObject::setParent(VfxObject *objParent)
{
    if (objParent == NULL)
    {
        removeFromParent();
        return;
    }
    
    objParent->addChild(this);
}


// TODO: move all this implement to onRemoveChild()    
void VfxObject::removeFromParent()
{
    if (m_parentObj == NULL)
    {
        // Do nothing
        return;
    }

    // Callback the virtual function
//    m_parentObj->onRemoveChild(this);    
    m_parentObj->onObjectNotify(VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD, (void *)this);

    // Remove from child list of parent
    if (m_prevObj != NULL)
    {
        m_prevObj->m_nextObj = m_nextObj;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentObj->m_firstChildObj == this);
        m_parentObj->m_firstChildObj = m_nextObj;
    }

    if (m_nextObj != NULL)
    {
        m_nextObj->m_prevObj = m_prevObj;
    }
    else
    {
        VFX_DEV_ASSERT(m_parentObj->m_lastChildObj == this);
        m_parentObj->m_lastChildObj = m_prevObj;
    }

    m_parentObj = NULL;
    m_prevObj = NULL;
    m_nextObj = NULL;
}


// TODO: move all this implement to onAddChild()    
void VfxObject::addChild(VfxObject *childObj)
{
    VFX_OBJ_ASSERT_VALID(childObj);
    VFX_ASSERT(childObj != this);

    if (childObj->m_parentObj == this)
    {
        // Do nothing
        return;
    }
 
    // Add reference and make sure the input newFrame has no relation
    childObj->removeFromParent();

    VFX_DEV_ASSERT(childObj->m_parentObj == NULL);
    VFX_DEV_ASSERT(childObj->m_prevObj == NULL);
    VFX_DEV_ASSERT(childObj->m_nextObj == NULL);

    // Assign parent object
    childObj->m_parentObj = this;

    // Append to tail of list
    childObj->m_prevObj = m_lastChildObj;
    childObj->m_nextObj = NULL;
    
    if (m_firstChildObj == NULL)
    {
        m_firstChildObj = childObj;
    }    
    if (m_lastChildObj != NULL)
    {
        m_lastChildObj->m_nextObj = childObj;
    }
    m_lastChildObj = childObj;

    // Callback the virtual function
//    onAddChild(childObj);
    onObjectNotify(VFX_OBJECT_NOTIFY_ID_ADD_CHILD, (void *)childObj);
}


VfxU32 VfxObject::getChildCount() const
{
    VfxU32 count = 0;
    
    VfxObject *i;
    for (i = m_firstChildObj; i != NULL; i = i->m_nextObj)
    {
        count++;
    }
    
    return count;
}

VfxBool VfxObject::setAttachProperty(VfxId propId, void* data, VfxU32 size)
{
    VfxBool bRet = VFX_FALSE;
    if(!data)
    {
        if(m_attachProps)
        {
            bRet = m_attachProps->remove(propId);
            if(m_attachProps->count() == 0)
            {
                VFX_DELETE(m_attachProps);
            }
        }
    }
    else
    {
        if(!m_attachProps)
        {
            VFX_ALLOC_NEW(m_attachProps, VfxAttachProperties, this);
        }

        bRet = m_attachProps->add(propId, data, size, VFX_TRUE, this);
    }

    return bRet;
}


#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
VfxBool VfxObject::setAttachPropertyForVPI(VfxId propId, void* data, VfxU32 size)
{
    VfxBool bRet = VFX_FALSE;
    if(!data)
    {
        if(m_attachProps)
        {
            bRet = m_attachProps->remove(propId);
            if(m_attachProps->count() == 0)
            {
                VFX_DELETE(m_attachProps);
            }
        }
    }
    else
    {
        vrt_allocator_handle allocator = vrt_allocator_get_owner(this);

        if(!m_attachProps)
        {
            if (allocator == g_vrt_null_allocator)
            {
                VFX_ALLOC_NEW(m_attachProps, VfxAttachProperties, VFX_SYS_GLOBAL_CONTEXT);
            }
            else
            {
                VFX_ALLOC_NEW(m_attachProps, VfxAttachProperties, this);
            }
        }

        if (allocator == g_vrt_null_allocator)
        {
            bRet = m_attachProps->add(propId, data, size, VFX_TRUE, VFX_SYS_GLOBAL_CONTEXT);
        }
        else
        {
            bRet = m_attachProps->add(propId, data, size, VFX_TRUE, this);
        }
    }

    return bRet;
}


void VfxObject::setHasProxy(VfxBool value)
{
    value ?
        VFX_FLAG_SET(m_objFlags, FLAGS_HAS_PROXY) :
        VFX_FLAG_CLEAR(m_objFlags, FLAGS_HAS_PROXY);
}


void VfxObject::setIsProxy(VfxBool value)
{
    value ?
        VFX_FLAG_SET(m_objFlags, FLAGS_IS_PROXY) :
        VFX_FLAG_CLEAR(m_objFlags, FLAGS_IS_PROXY);
}


VfxBool VfxObject::isProxy()
{
    return VFX_FLAG_HAS(m_objFlags, FLAGS_IS_PROXY);
}
#endif /* __MMI_VENUS_PLUG_IN_ENGINE__ */



void *VfxObject::getAttachProperty(VfxId propId, VfxU32 size) const
{
    if(!m_attachProps)
        return NULL;

    VfxU32 dSize;
    void *data = m_attachProps->query(propId, &dSize);

    if(size < 4)
        size = 4;
    if(dSize != size)
        return NULL;

    return data;
}

void VfxObject::releaseAllChild()
{
    // Because the child will remove itself from the child object list,
    // So we only need to see if the list is empty
    while (m_lastChildObj != NULL)
    {
        VfxObject *obj = m_lastChildObj;
        VFX_OBJ_CLOSE(obj);
    }

    // The list must be empty
    VFX_DEV_ASSERT(m_lastChildObj == NULL);
}


VfxClassInfo *VfxObject::onGetClassInfo() const
{
    return getVfxObjectClassInfo();
}


void VfxObject::onInit()
{
    // do nothing
}


void VfxObject::onDeinit()
{
    // do nothing
}


void VfxObject::onObjectNotify(VfxId id, void *userData)
{
    // do nothing
}


void VfxObject::onAfterInit()
{
    // do nothing
}


void VfxObject::onBeforeDeinit()
{
    // do nothing
}


void VfxObject::onAfterDeinit()
{
    // do nothing
}


void VfxObject::onAddChild(VfxObject *child)
{
    VFX_UNUSED(child);
    // do nothing
}


void VfxObject::onRemoveChild(VfxObject *child)
{
    VFX_UNUSED(child);
    // do nothing
}


vrt_allocator_handle VfxObject::getAllocator()
{
    vrt_allocator_handle allocator = vrt_allocator_get_owner(this);

    if (allocator == g_vrt_null_allocator)
    {
        // NOTE:
        // assert here because AP do not override getAllocator 
	    VFX_ASSERT(0);
    }

    return allocator;
}


void vfxObjClose(VfxObject *ptr)
{
    if (ptr != NULL)
    {
        ptr->_close();
    }
}

