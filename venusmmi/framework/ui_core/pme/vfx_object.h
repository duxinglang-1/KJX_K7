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
 *  vfx_object.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_OBJECT_H__
#define __VFX_OBJECT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxClassInfo
#include "vfx_class_info.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxObject registered name
#define VFX_OBJECT_CLASS_NAME           "Object"


// Internal used. VfxObject guard pattern for a created object.
#define VFX_OBJ_CREATED_GUARD_PATTERN   0xBABEC0DE
// Internal used. VfxObject guard pattern for a destroyed object.
#define VFX_OBJ_DESTROYED_GUARD_PATTERN 0xDEADBEEF

#if defined __VFX_HEAP_PROFILE__
    #define VFX_HEAP_PROFILE_OBJ_UPDATE(p1,p2,p3)  vfx_heap_profiling_obj_update(p1,p2,p3)
#else
    #define VFX_HEAP_PROFILE_OBJ_UPDATE(p1,p2,p3)  
#endif
/*
 * Macro to check an object is valid. Assert if the pointer is NULL or 
 *  the pointer to the object is invalid.
 *
 * EXAMPLE:
 * <code>
 *  void MyObject::test(MyObject *other)
 *  {
 *      // Assert if the other object is NULL or invalid.
 *      VFX_OBJ_ASSERT_VALID(other);
 *  }
 * </code>
 */
#define VFX_OBJ_ASSERT_VALID(_ptr)       VFX_ASSERT(_ptr != NULL && (_ptr)->isValid())


/*
 * Macro to get the class information ID with a class name.
 *
 * NOTE:
 *  If the _className has not use macro VFX_DECLARE_CLASS, it will cause
 *  compile error.
 *
 * SEE ALSO: VFX_DECLARE_CLASS, VFX_IMPLEMENT_CLASS
 */
#define VFX_OBJ_CLASS_INFO(_className)  (_className::get##_className##ClassInfo())


/*
 * Macro to declare class information.
 */
#define VFX_DECLARE_CLASS(_className)                                           \
    public:                                                                     \
        static const vfx_class_info_struct s_classInfo;                         \
                                                                                \
    public:                                                                     \
        static VfxObject *createInstance(VfxObject *parent);                    \
        static VfxClassInfo *get##_className##ClassInfo();                      \
        static VfxClassInfo *getClassInfoInstance()                             \
        {                                                                       \
            return get##_className##ClassInfo();                                \
        }                                                                       \
                                                                                \
    protected:                                                                  \
        virtual VfxClassInfo *onGetClassInfo() const

/*
 * Macro to implement class information.
 *
 * SEE ALSO: VFX_DECLARE_CLASS
 */
#define VFX_IMPLEMENT_CLASS(_registerName, _className, _parentClassName)        \
                                                                                \
    VfxObject *_className::createInstance(VfxObject *parent)                    \
    {                                                                           \
        _className *ret;                                                        \
        __VFX_OBJ_CREATE(ret, _className, parent);                              \
        return ret;                                                             \
    }                                                                           \
                                                                                \
    VfxClassInfo *_className::get##_className##ClassInfo()                      \
    {                                                                           \
        return (VfxClassInfo *)&s_classInfo;                                     \
    }                                                                           \
                                                                                \
    VfxClassInfo *_className::onGetClassInfo() const                            \
    {                                                                           \
        return get##_className##ClassInfo();                                    \
    }                                                                           \
                                                                                \
    const vfx_class_info_struct _className::s_classInfo = {_registerName, &_parentClassName::s_classInfo, &_className::createInstance};


/*
 * Macro to implement class information.
 *
 * SEE ALSO: VFX_DECLARE_CLASS
 */
#define VFX_IMPLEMENT_VIRTUAL_CLASS(_registerName, _className, _parentClassName) \
                                                                                \
    VfxClassInfo *_className::get##_className##ClassInfo()                      \
    {                                                                           \
        return (VfxClassInfo *)&s_classInfo;                                     \
    }                                                                           \
                                                                                \
    VfxClassInfo *_className::onGetClassInfo() const                            \
    {                                                                           \
        return get##_className##ClassInfo();                                    \
    }                                                                           \
                                                                                \
    const vfx_class_info_struct _className::s_classInfo = {_registerName, &_parentClassName::s_classInfo, NULL};

/*
 * Dynamic cast an object type. Retrun NULL if the object can not cast to the
 * given class name.
 *
 * EXAMPLE:
 * <code>
 *  VfxMyButton *button = VFX_OBJ_DYNAMIC_CAST(control, VfxMyButton);
 *  if (button != NULL)
 *  {
 *      button->click();
 *  }
 * </code>
 */
#define VFX_OBJ_DYNAMIC_CAST(_ptr, _className)                                  \
    ((_ptr) ? ((_ptr)->isKindOf(VFX_OBJ_CLASS_INFO(_className)) ?              \
        VFX_STATIC_CAST(_ptr, _className *) :                                     \
        NULL) : NULL)


template <class _className>
_className *vfxObjCreate(VfxObject *_parent)
{
    _className *ptr = new (_parent) _className();
    ptr->_init(_parent);
	return ptr;
}

template <class _className>
_className *vfxObjCreateEx(VfxObject *_parent)
{
    const VfxChar *_filename;
    VfxU32 _line;
    VFX_MEM_FILL_FILENAME(_filename, _line);
    IVfxAllocatable *_a = (IVfxAllocatable *)_parent;
    _className *_p = new (_a, _filename, _line) _className();
    VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d %s", (_a ? _a->getAllocator() : 0), (_a ? _a->_getId() : 0), _p, sizeof(_className), #_className));
    _className *ptr = _p;
    ptr->_init(_parent);
    VFX_HEAP_PROFILE_OBJ_UPDATE((ptr)->getAllocator(), (void*)(ptr)->getSelf(), 0);
	return ptr;
}

#if defined __VFX_HEAP_PROFILE__
#define VFX_OBJ_CREATE(_ptr, _className, _parent)                               \
    do                                                                          \
    {                                                                           \
        (_ptr) = vfxObjCreateEx<_className>(_parent);                            \
    } while (0)
#else
#define VFX_OBJ_CREATE(_ptr, _className, _parent)                               \
    do                                                                          \
    {                                                                           \
        (_ptr) = vfxObjCreate<_className>(_parent);                             \
        VFX_HEAP_PROFILE_OBJ_UPDATE((_ptr)->getAllocator(), (void*)(_ptr)->getSelf(), 0);\
    } while (0)
#endif

#define __VFX_OBJ_CREATE(_ptr, _className, _parent)                             \
    do                                                                          \
    {                                                                           \
        VFX_ALLOC_NEW(_ptr, _className, _parent);                               \
        (_ptr)->_init(_parent);                                                 \
        VFX_HEAP_PROFILE_OBJ_UPDATE((_ptr)->getAllocator(), (void*)(_ptr)->getSelf(), 0);\
    } while (0)

/*
 * Macro to create an object with constructor parameters. 
 * _className must inherit from VfxObject.
 *
 * SEE ALSO: VFX_OBJ_CREATE, VFX_OBJ_CLOSE
 *
 * EXAMPLE:
 * <code>
 *  MyObject *obj;
 *  VFX_OBJ_CREATE_EX(obj, MyObject, this, (param1, param2));
 * </code>
 */
#define VFX_OBJ_CREATE_EX(_ptr, _className, _parent, _param)                    \
    do                                                                          \
    {                                                                           \
        VFX_ALLOC_NEW_EX(_ptr, _className, _parent, _param);                    \
        (_ptr)->_init(_parent); \
        VFX_HEAP_PROFILE_OBJ_UPDATE((_ptr)->getAllocator(), (void*)(_ptr)->getSelf(), 0);\
    } while (0)
 

/*
 * Macro to close an object. _ptr must be a VfxObject
 *
 * SEE ALSO: VFX_OBJ_CREATE
 */
extern void vfxObjClose(VfxObject *ptr);
class VfxObject;
template <class _className> class VfxWeakPtr;
template <class _className>
void vfxObjClose(VfxWeakPtr<_className> ptr)
{
	if (ptr != NULL)
	{
		ptr->_close();
	}
}
#define VFX_OBJ_CLOSE(_ptr)                                          \
	do                                                               \
	{                                                                \
        if ((_ptr) != NULL)                                          \
        {                                                            \
            VFX_MEM_LOG(("[VFX] DELETE %08X", (_ptr)->getSelf()));  \
        }                                                            \
		vfxObjClose(_ptr);                                           \
		(_ptr) = NULL;                                               \
	} while (0)


/*
 * Macro to declare a signalton class
 *
 * SEE ALSO: VFX_OBJ_IMPLEMENT_SINGLETON_CLASS
 */ 
#define VFX_OBJ_DECLARE_SINGLETON_CLASS(_className)                             \
    public:                                                                     \
        static _className *getInstance();                                       \
        static void closeInstance();                                            \
    private:                                                                    \
        static VfxU8 s_InstanceBuf[];                                           \
        static _className *s_instance

/*
 * Macro to implement the signalton class.
 *
 * SEE ALSO: VFX_OBJ_DECLARE_SINGLETON_CLASS
 */
#define VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(_className) \
    _className *_className::getInstance() \
    { \
        if (s_instance == NULL) \
        {\
            s_instance = new (g_vrt_null_allocator, s_InstanceBuf) _className(); \
            s_instance->_init(NULL); \
        } \
        return s_instance; \
    } \
    \
    void _className::closeInstance() \
    { \
        if (s_instance != NULL) \
        { \
            s_instance->_deinit(); \
            s_instance = NULL; \
        } \
    } \
    \
    VFX_ALIGN(4) VfxU8 _className::s_InstanceBuf[sizeof(vrt_allocator_handle) + sizeof(_className)]; \
    _className *_className::s_instance = NULL

/*
 * Macro to get the singalton
 */    
#define VFX_OBJ_GET_INSTANCE(_className) (_className::getInstance())

// TODO: the interface will be phace out.
/*
 * Macro to destroy the signalton
 */
#define VFX_OBJ_CLOSE_INSTANCE(_className) (_className::closeInstance())


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-defined classes
class VfxWeakPtrFlag;
class VfxAttachProperties;

typedef void *VfxObjHandle;


// Event id for onObjectNotify()
//
// SEE ALSO: VfxObject::onObjectNotify()
enum VfxObjectNotifyIdEnum
{
    VFX_OBJECT_NOTIFY_ID_AFTER_INIT,
    VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT,
    VFX_OBJECT_NOTIFY_ID_AFTER_DEINIT,
    VFX_OBJECT_NOTIFY_ID_ADD_CHILD,
    VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD,

    VFX_ANIMATABLE_NOTIFY_ID_ADD_TIMELINE,
    VFX_ANIMATABLE_NOTIFY_ID_REMOVE_TIMELINE,

    VFX_FRAME_NOTIFY_ID_BROADCAST,
    VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED,
    VFX_FRAME_NOTIFY_ID_QUERY_FOCUS_CHANGE,
    VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED,
    VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE,
    VFX_FRAME_NOTIFY_ID_ADJUST_IME_RESIZE,
    VFX_FRAME_NOTIFY_ID_ADJUST_IME_SHIFT,
    VFX_FRAME_NOTIFY_ID_UPDATE_VIEW_FOR_IME,

    VFX_OBJECT_NOTIFY_ID_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxObject
 *****************************************************************************/

/*
 * VfxObject is the base class of all Venus UI objects
 */
class VfxObject : 
    public VfxBase, 
    public IVfxAllocatable
{
    VFX_DECLARE_CLASS(VfxObject);
    VFX_DECLARE_NO_COPY_CLASS(VfxObject);

// Object-tree hierarchy method
public:
    // Return the parent object of the object
    //
    // RETURNS: The parent object of the object    
    VfxObject *getParent() const
    {
        return m_parentObj;
    }

    // Caculate the number of child objects.
    //
    // RETURNS: The number of child objects.
    VfxU32 getChildCount() const;

// Object-tree hierarchy method
private:
    // Internal Used.
    void setParent(
        VfxObject *objParent        // [IN] New object to be set as parent
    );

    // Internal Used.
    void removeFromParent();

    // Internal Used.
    void addChild(
        VfxObject *childObj         // [IN] The child object to be added
    );

    // Internal Used.
    void removeChild(
        VfxObject *childObj         // [IN] The child object to be removed
    );

// Attached property method
public:
    // Attach property to this object, the ID should be unique and is used
    // to retrive property back later.
    // App should use range 0x0000 ~ 0xFFFF
    // VFX should use range 0x10000 ~ 0x1FFFF
    // VCP should use range 0x20000 ~ 0x2FFFF
    //
    // RETURNS: VFX_TRUE if succeed, VFX_FALSE is failed
    VfxBool setAttachProperty(
        VfxId propId,   // unique ID of property
        void* data,     // property value pointer
        VfxU32 size     // size of property value
    );

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    VfxBool setAttachPropertyForVPI(
        VfxId propId,   // unique ID of property
        void* data,     // property value pointer
        VfxU32 size     // size of property value
    );
#endif

    // Query value of property from this object.
    //    
    // RETURN: pointer to internal buffer
    void *getAttachProperty(
        VfxId propId,   // unique ID of property
        VfxU32 size     // size of property value
    ) const;

// Framework methods
public:
    VfxObject *getSelf()
    {
        return this;
    }

    // Internal used. Initialize the object.
    void _init(VfxObject *objParent);
    
    // Internal used. Deinitialize the object.
    void _deinit();

    // Internal used. Deinitialize and delete this object. 
    // Use macro VFX_OBJ_CLOSE directly.
    void _close();
    
    // Internal used. Get class info of the instance. 
    // Concrete class must handle virtual function onGetClassInfo to 
    // return its class info.
    //
    // RETURNS: Pointer to VfxClassInfo of the object
    //
    // SEE ALSO: VFX_OBJ_CLASS_INFO
    VfxClassInfo *getClassInfo() const
    {
        return onGetClassInfo();
    }
    
    // Check the object whatever inherit from the given class.
    //
    // RETURNS: Return VFX_TRUE if the object inherit from the given class.
    //  Otherwise, return VFX_FALSE.
    VfxBool isKindOf(const VfxClassInfo *classInfo) const
    {
        return onGetClassInfo()->isKindOf(classInfo);
    }

    // Return an unique weak handle to this object. This handle is guranteed 
    // to be unique for a very long time.
    // Use handleToObject() to query the object pointer from handle.
    // 
    // RETURNS: an unique weak handle
    VfxObjHandle getObjHandle() const;

    // Convert handle returned by getObjHandle() to VfxObject pointer.
    // Note. If the object is dead, this API return NULL.
    // 
    // RETURNS: Object pointer or NULL if the object is already dead
    static VfxObject *handleToObject(VfxObjHandle handle);

    // Internal used.
    VfxBool isValid() const
    {
        return m_guard == VFX_OBJ_CREATED_GUARD_PATTERN;
    }
    
    // Internal used.
    VfxWeakPtrFlag *getWeakPtrFlag();
    void resetWeakPtrFlag();
    // To check if ptr is a VfxObject
    static VfxU32 static_isObjCheck(void* ptr, void** parent_p);

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    // Internal used.
    void setHasProxy(VfxBool value);
    void setIsProxy(VfxBool value);
    VfxBool isProxy();
#endif

// Constructor / Destructor
public:
    // Default constructor
    VfxObject();

public:    
    // Destructor
    virtual ~VfxObject();

// Overridable
protected:
    // Overridable virtual function. Called after construct the object.
    //
    // SEE ALSO: VFX_OBJ_CREATE
    virtual void onInit();
    
    // Overridable virtual function. Called before destruct the object.
    //
    // SEE ALSO: VFX_OBJ_CLOSE
    virtual void onDeinit();

    // Overridable virtual function. Called when there is notification about the object.
    //
    // SEE ALSO: VfxObjectNotifyIdEnum
    virtual void onObjectNotify(VfxId id, void *userData);

    // Called after the object is initialized.
    //
    // SEE ALSO: VFX_OBJ_CREATE, onInit
    void onAfterInit();
    
    // Called before the onDeinit is invoked.
    //
    // SEE ALSO: VFX_OBJ_CLOSE, onDeinit
    void onBeforeDeinit();

    // Called after the onDeinit is invoked.
    //
    // NOTE: Remove the object relation at this stage 
    //
    // SEE ALSO: VFX_OBJ_CLOSE, onDeinit
    void onAfterDeinit();

    // Called on adding a child object.
    //
    // SEE ALSO: setParent, addChild
    void onAddChild(
        VfxObject *childObj         // [IN] The child object to be added
    );

    // Called on removing a child object.
    //
    // SEE ALSO: setParent, removeFromParent, removeChild, 
    void onRemoveChild(
        VfxObject *childObj         // [IN] The child object to be removed
    );

// Overridable
public:
    // Overridable virtual function.
    virtual vrt_allocator_handle getAllocator();

// Implemetation
private:
    enum
    {
        // If object occupy unique handle
        FLAGS_HAS_HANDLE        = 1 << 0,
        FLAGS_OBJ_INITING       = 1 << 1,
        FLAGS_OBJ_DEINITING     = 1 << 2,
        FLAGS_HAS_PROXY         = 1 << 3,
        FLAGS_IS_PROXY          = 1 << 4
    };

// Implemetation
private:
    // Guard pattern
    VfxU32 m_guard;

    // Object Flags
    mutable VfxFlag m_objFlags;

    // Weak pointer flag
    VfxWeakPtrFlag *m_weakPtrFlag;

    VfxObject *m_parentObj;
    VfxObject *m_firstChildObj;
    VfxObject *m_lastChildObj;
    VfxObject *m_nextObj;
    VfxObject *m_prevObj;

    // attach properties
    class VfxAttachProperties *m_attachProps;

    void releaseAllChild();

// Implemetation
private:    
    static struct VfxObjHandleEntry *s_objHandleList;
    static VfxU32 s_objHandleListSize;
    static VfxU32 s_objHandleListCount;
    static VfxU32 s_objHandleNext;
};


inline
void VfxObject::removeChild(VfxObject *childObj)
{
    VFX_OBJ_ASSERT_VALID(childObj);
    VFX_ASSERT(childObj->m_parentObj == this);
    childObj->removeFromParent();
}

#endif /* __VFX_OBJECT_H__ */

