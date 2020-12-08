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
 *  vfx_signal.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Event in Venus Object Model is used like a type-safe function pointer.
 *  But you can connect one or more functor to one signal. 
 *  Connect a functor into a signal, it will create a signal handler for this 
 *  functor and insert it into the list of signal.
 * 
 *  When you emit an signal, all connected functors will be called one by one. 
 *
 *  A functor may terminate the call sequence by calling vfxStopEmit.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_SIGNAL_H__
#define __VFX_SIGNAL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxObjWeakPtr
#include "vfx_weak_ptr.h"

#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_async_signal.h"
#include "vfx_sys_mem_config.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Predefined class
class VfxObject;
class VfxBaseSignal;

// Internal used.
typedef void (VfxObject::*VfxSlotObjMemFuncPtr)();
// Internal used.
typedef void (*VfxEmitEntryFuncPtr)(VfxObject *obj, VfxSlotObjMemFuncPtr callback, void *arguments);


/*****************************************************************************
 * Define
 *****************************************************************************/

// Null callback object (VfxNullCallback)
#define VFX_CALLBACK_NULL               (VfxNullCallback())

// Internal used. SlotListEntry magic number for a live instance.
#define VFX_SLOT_LIVE_MAGIC_NUMBER 'TSLS'
// Internal used. SlotListEntry magic number for a dead instance.
#define VFX_SLOT_DEAD_MAGIC_NUMBER 'tsls'


// Utility Macro for helping register post emit function
#define VFX_REG_POSTEMIT(_class, _arg, _cb_obj, _cb_func) do { \
    VfxAsyncSignalUtil *asyncSignal = VFX_OBJ_GET_INSTANCE(VfxAsyncSignalUtil); \
    asyncSignal->regPostEmit( \
        this, \
        (VfxEmitEntryFuncPtr)&_class::emitEntry, \
        _arg, \
        _cb_obj, \
        (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(_cb_func, obj_mem_funcptr_type)); \
} while(0)


/*****************************************************************************
 * Class VfxSlot
 *****************************************************************************/

// Internal used. VfxSlot is a base class which stores weak reference of VfxObject and it's member function.
class VfxSlot : public VfxBase
{
// Variable
public:
    VfxObjWeakPtr m_objPtr;          // weak reference to VfxObject object
    VfxSlotObjMemFuncPtr m_callback;    // VfxObject object's member funtion pointer

// Constructor / Destructor
public:    
    // Construct with object and it's member function
    VfxSlot(VfxObject *obj, VfxSlotObjMemFuncPtr callCallback) :
        m_objPtr(obj),
        m_callback(callCallback)
    {
    }

    // Copy constructor
    VfxSlot(const VfxSlot &other) :
        m_objPtr(other.m_objPtr),
        m_callback(other.m_callback)
    {
    }

// Method
public:
    // Whether target object is valid.
    VfxBool isValid() const
    {
        return m_objPtr.isValid();
    }

    // Compare with another slot.
    VfxBool equalTo(const VfxSlot &other) const
    {
        return (m_objPtr == other.m_objPtr) && (m_callback == other.m_callback);
    }

// Operator    
public:
    VfxSlot &operator =(const VfxSlot &other)
    {
        m_objPtr = other.m_objPtr;
        m_callback = other.m_callback;
        return *this;
    }
};


/*****************************************************************************
 * Class VfxSlotList
 *****************************************************************************/

// Internal used. VfxSlotList is a list container which stores slot objects.
class VfxSlotList : public VfxBase
{
// Define
public:

    // Internal used. SlotListEntry is an internal list node of VfxSlotList.
    class SlotListEntry : public VfxBase
    {    
    public:
        // Consturct with object and it's member function.
        SlotListEntry(VfxObject *obj, VfxSlotObjMemFuncPtr memFunc) :
			/*m_magicNumber(VFX_SLOT_LIVE_MAGIC_NUMBER),*/
            m_slot(obj, memFunc),
            m_next(NULL)
        {
        }
        ~SlotListEntry()           
        {
           // m_magicNumber = VFX_SLOT_DEAD_MAGIC_NUMBER;
        }

    private:
     //   VfxU32 m_magicNumber;  //for vfx system memory debug
    public:
        VfxSlot         m_slot;     // slot
        SlotListEntry  *m_next;     // next node
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxSlotList() : m_listHead(NULL)
    {
    }

    // Cioy constructor
    VfxSlotList(const VfxSlotList &other) : m_listHead(NULL)
    {
        assignWithList(other);
    }

    // Destructor    
    ~VfxSlotList()
    {
        clear();
    }

// Methods    
public:
    // Return the head of the slot list
    // RETURNS: The head slot entry of the list. It the slot list is empty,
    //          it will return NULL.
    SlotListEntry *getHead() const
    {
        return m_listHead;
    }

    // Test if the slot list is empty
    VfxBool isEmpty() const
    {
        return m_listHead == NULL;
    }

    // Find a slot in the slot list
    // RETURNS: The slot entry to find. If the slot is not in the slot list,
    //          it will return NULL.
    SlotListEntry *findEntry(
        VfxObject *obj, 
        VfxSlotObjMemFuncPtr memFunc
    ) const;

    // Add the slot into the head ot slot list
    void pushSlot(
        VfxObject *obj, 
        VfxSlotObjMemFuncPtr memFunc
    );

    // Append the slot into the tail ot slot list
    void appendSlot(
        VfxObject *obj, 
        VfxSlotObjMemFuncPtr memFunc
    );

    // Remove the given slot from the slot list
    void removeSlot(
        VfxObject *obj, 
        VfxSlotObjMemFuncPtr memFunc
    );

    // Clear all slots in the slot list
    void clear();

    // Get number of slot count
    // RETURNS: return number of slot
    VfxS32 getCount() const;

// Implementation
private:
    SlotListEntry *m_listHead;
    
    void assignWithList(const VfxSlotList &other);
    void removeAllInvalidateSlots();

    friend class VfxAsyncSignalUtil;
};



/*****************************************************************************
 * Class VfxSignalArg
 *****************************************************************************/

/*
 *  VfxSignalArg is base class that hold arguments for post emit.
 */
class VfxSignalArg : public VfxBase
{
public:
    VfxSignalArg()
    {
    }

    // Default virtual destructor, 
    //  for VfxSignalArgX member data destructors
    virtual ~VfxSignalArg() 
    {
    }
};


/*****************************************************************************
 * Class VfxSignalArg1
 *****************************************************************************/

// VfxSignalArg1 is a template class which holds one argument for VfxSignal1
template <class _Arg1>
class VfxSignalArg1 : public VfxSignalArg
{
public:
    _Arg1 arg1;    // signal argument 1

    // Construct with argument
    VfxSignalArg1(_Arg1 _arg1) : 
        arg1(_arg1) 
    {
    }
};


/*****************************************************************************
 * Class VfxSignalArg2
 *****************************************************************************/

// VfxSignalArg2 is a template class which holds two arguments for VfxSignal2
template <class _Arg1, class _Arg2>
class VfxSignalArg2 : public VfxSignalArg
{
public:
    _Arg1 arg1;    // signal argument 1
    _Arg2 arg2;    // signal argument 2

    // Construct with arguments
    VfxSignalArg2(_Arg1 _arg1, _Arg2 _arg2) : 
        arg1(_arg1), arg2(_arg2) 
    {
    }
};


/*****************************************************************************
 * Class VfxSignalArg3
 *****************************************************************************/

// VfxSignalArg3 is a template class which holds three arguments for VfxSignal3
template <class _Arg1, class _Arg2, class _Arg3>
class VfxSignalArg3 : public VfxSignalArg
{
public:
    _Arg1 arg1;    // signal argument 1
    _Arg2 arg2;    // signal argument 2
    _Arg3 arg3;    // signal argument 3
    
    // Construct with arguments
    VfxSignalArg3(_Arg1 _arg1, _Arg2 _arg2, _Arg3 _arg3) : 
        arg1(_arg1), arg2(_arg2), arg3(_arg3) 
    {
    }
};


/*****************************************************************************
 * Class VfxSignalArg4
 *****************************************************************************/

// VfxSignalArg4 is a template class which holds four arguments for VfxSignal4
template <class _Arg1, class _Arg2, class _Arg3, class _Arg4>
class VfxSignalArg4 : public VfxSignalArg
{
public:
    _Arg1 arg1;    // signal argument 1
    _Arg2 arg2;    // signal argument 2
    _Arg3 arg3;    // signal argument 3
    _Arg4 arg4;    // signal argument 4
    
    // Construct with arguments
    VfxSignalArg4(_Arg1 _arg1, _Arg2 _arg2, _Arg3 _arg3, _Arg4 _arg4) : 
        arg1(_arg1), arg2(_arg2), arg3(_arg3), arg4(_arg4) 
    {
    }
};


/*****************************************************************************
 * Class VfxCallback
 *****************************************************************************/

// This is an empty class just for have a type to notify the callback to reset its 
// content.
// SEE ALSO: VFX_CALLBACK_NULL
class VfxNullCallback : public VfxBase
{
};


/*****************************************************************************
 * Class VfxCallback0
 *****************************************************************************/

// VfxCallback0 is a callback helper with no function arguments.
// NOTE: the callback object should derived from VfxObject.
//
// EXAMPLE:
// <code>
// // Example 1
// VfxCallback0 callback(this, &VfxControl::onUpdate);
// callback.invoke();
//
// // Example 2
// class VfxMyControl : VfxControl
// {
//     ......
//     void VfxMyControl::onCallback()
//     {
//     }
//
//     void VfxMyControl::registerCallback()
//     {
//         VfxCallback0 cb(this, &VfxMyControl::onCallback);
//         VfxNotifier *notifier = VFX_OBJ_GET_INSTANCE(VfxNotifier);
//         notifier->register(cb);
//     }
// };
//
// class VfxNotifier : public VfxObject
// {
//     VFX_DECLARE_CLASS(VfxNotifier);
//     VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxNotifier);
//
// public:
//     VfxCallback0     m_callback;
//
//     void register(const VfxCallback0 &callback)
//     {
//         m_callback = callback;
//     }
//     
//     void notify()
//     {
//         m_callback.invoke();
//     }
// };
// </code>
class VfxCallback0 : public VfxSlot
{
private:
    typedef void (VfxObject::*MemFunc)();

// Constructor / Distructor
public:
    // Default constructor
    VfxCallback0() : VfxSlot(NULL, NULL)
    {
    }    
    
    // Constructor
    template <class _func_type>
    VfxCallback0(VfxObject *obj, _func_type func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, MemFunc))
    {
    }    

    // Copy constructor
    VfxCallback0(const VfxCallback0 &other) : 
        VfxSlot(other.m_objPtr.get(), other.m_callback)
    {
    }

    // Helper constructor to init a NULL callback
    VfxCallback0(const VfxNullCallback &nullCallback) : VfxSlot(NULL, NULL)
    {
        VFX_UNUSED(nullCallback);
    }

    // Invoke registered callback member function
    void invoke()
    {
        if (m_objPtr.isValid())
        {
            (m_objPtr.get()->*(MemFunc)m_callback)();
        }
    }
};


/*****************************************************************************
 * Class VfxCallback1
 *****************************************************************************/

// VfxCallback1 is a callback helper with 1 function argument
template <typename _Arg1>
class VfxCallback1 : public VfxSlot
{
private:
    typedef void (VfxObject::*MemFunc)(_Arg1 arg1);

// Constructor / Distructor
public:
    // Default constructor
    VfxCallback1() : VfxSlot(NULL, NULL)
    {
    }    

    // Constructor
    template <typename _func_type>
    VfxCallback1(VfxObject *obj, _func_type func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, MemFunc))
    {
    }    

    // Copy constructor
    VfxCallback1(const VfxCallback1 &other) : 
        VfxSlot(other.m_objPtr.get(), other.m_callback)
    {
    }

    // Helper constructor to init a NULL callback
    VfxCallback1(const VfxNullCallback &nullCallback) : VfxSlot(NULL, NULL)
    {
        VFX_UNUSED(nullCallback);
    }

    // Invoke registered callback member function
    void invoke(_Arg1 arg1)
    {
        if (m_objPtr.isValid())
        {
            (m_objPtr.get()->*(MemFunc)m_callback)(arg1);
        }
    }
};


/*****************************************************************************
 * Class VfxCallback2
 *****************************************************************************/

// VfxCallback2 is a callback helper with 2 function arguments
template <typename _Arg1, typename _Arg2>
class VfxCallback2 : public VfxSlot
{
private:
    typedef void (VfxObject::*MemFunc)(_Arg1 arg1, _Arg2 arg2);

// Constructor / Distructor
public:
    // Default constructor
    VfxCallback2() : VfxSlot(NULL, NULL)
    {
    }    

    // Constructor
    template <typename _func_type>
    VfxCallback2(VfxObject *obj, _func_type func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, MemFunc))
    {
    }    

    // Copy constructor
    VfxCallback2(const VfxCallback2 &other) : 
        VfxSlot(other.m_objPtr.get(), other.m_callback)
    {
    }

    // Helper constructor to init a NULL callback
    VfxCallback2(const VfxNullCallback &nullCallback) : VfxSlot(NULL, NULL)
    {
        VFX_UNUSED(nullCallback);
    }

    // Invoke registered callback member function
    void invoke(_Arg1 arg1, _Arg2 arg2)
    {
        if (m_objPtr.isValid())
        {
            (m_objPtr.get()->*(MemFunc)m_callback)(arg1, arg2);
        }
    }
};


/*****************************************************************************
 * Class VfxCallback3
 *****************************************************************************/

// VfxCallback3 is a callback helper with 3 function arguments
template <typename _Arg1, typename _Arg2, typename _Arg3>
class VfxCallback3 : public VfxSlot
{
private:
    typedef void (VfxObject::*MemFunc)(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3);

// Constructor / Distructor
public:
    // Default constructor
    VfxCallback3() : VfxSlot(NULL, NULL)
    {
    }    

    // Constructor
    template <typename _func_type>
    VfxCallback3(VfxObject *obj, _func_type func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, MemFunc))
    {
    }    

    // Copy constructor
    VfxCallback3(const VfxCallback3 &other) : 
        VfxSlot(other.m_objPtr.get(), other.m_callback)
    {
    }

    // Helper constructor to init a NULL callback
    VfxCallback3(const VfxNullCallback &nullCallback) : VfxSlot(NULL, NULL)
    {
        VFX_UNUSED(nullCallback);
    }

    // Invoke registered callback member function
    void invoke(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3)
    {
        if (m_objPtr.isValid())
        {
            (m_objPtr.get()->*(MemFunc)m_callback)(arg1, arg2, arg3);
        }
    }
};


/*****************************************************************************
 * Class VfxCallback4
 *****************************************************************************/

// VfxCallback4 is a callback  helper with 4 function arguments
template <typename _Arg1, typename _Arg2, typename _Arg3, typename _Arg4>
class VfxCallback4 : public VfxSlot
{
private:
    typedef void (VfxObject::*MemFunc)(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4);

// Constructor / Distructor
public:
    // Default constructor
    VfxCallback4() : VfxSlot(NULL, NULL)
    {
    }    

    // Constructor
    template <typename _func_type>
    VfxCallback4(VfxObject *obj, _func_type func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, MemFunc))
    {
    }    

    // Copy constructor
    VfxCallback4(const VfxCallback4 &other) : 
        VfxSlot(other.m_objPtr.get(), other.m_callback)
    {
    }

    // Helper constructor to init a NULL callback
    VfxCallback4(const VfxNullCallback &nullCallback) : VfxSlot(NULL, NULL)
    {
        VFX_UNUSED(nullCallback);
    }

    // Invoke registered callback member function
    void invoke(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4)
    {
        if (m_objPtr.isValid())
        {
            (m_objPtr.get()->*(MemFunc)m_callback)(arg1, arg2, arg3, arg4);
        }
    }
};


/*****************************************************************************
 * Class VfxPostInvoke0
 *****************************************************************************/

// Internal used.
template <class _MemFunc>
class VfxPostInvoke0 : public VfxSlot
{
public:
    typedef void (VfxObject::*ObjMemFunc)();

public:
    VfxPostInvoke0(VfxObject *obj, _MemFunc func) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, ObjMemFunc))
    {
    }
};


/*****************************************************************************
 * Class VfxPostInvoke1
 *****************************************************************************/

// Internal used.
template <class _MemFunc, class _Arg1>
class VfxPostInvoke1 : public VfxSlot
{
public:
    typedef void (VfxObject::*ObjMemFunc)(_Arg1 arg1);

public:
    VfxSignalArg1 <_Arg1> m_args;

public:
    VfxPostInvoke1(VfxObject *obj, _MemFunc func, _Arg1 a1) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, ObjMemFunc)),
        m_args(a1) 
    {
    }
};


/*****************************************************************************
 * Class VfxPostInvoke2
 *****************************************************************************/

// Internal used.
template <class _MemFunc, class _Arg1, class _Arg2>
class VfxPostInvoke2 : public VfxSlot
{
public:
    typedef void (VfxObject::*ObjMemFunc)(_Arg1 arg1, _Arg2 arg2);

public:
    VfxSignalArg2 <_Arg1, _Arg2> m_args;

public:
    VfxPostInvoke2(VfxObject *obj, _MemFunc func, _Arg1 a1, _Arg2 a2) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, ObjMemFunc)),
        m_args(a1, a2) 
    {
    }
};


/*****************************************************************************
 * Class VfxPostInvoke3
 *****************************************************************************/

// Internal used.
template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3>
class VfxPostInvoke3 : public VfxSlot
{
public:
    typedef void (VfxObject::*ObjMemFunc)(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3);

public:
    VfxSignalArg3 <_Arg1, _Arg2, _Arg3> m_args;

public:
    VfxPostInvoke3(VfxObject *obj, _MemFunc func, _Arg1 a1, _Arg2 a2, _Arg3 a3) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, ObjMemFunc)),
        m_args(a1, a2, a3) 
    {
    }
};


/*****************************************************************************
 * Class VfxPostInvoke4
 *****************************************************************************/

// Internal used.
template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3, class _Arg4>
class VfxPostInvoke4 : public VfxSlot
{
public:
    typedef void (VfxObject::*ObjMemFunc)(_Arg1 arg1, _Arg2 arg2, _Arg3 arg3, _Arg4 arg4);

public:
    VfxSignalArg4 <_Arg1, _Arg2, _Arg3, _Arg4> m_args;
    
public:
    VfxPostInvoke4(VfxObject *obj, _MemFunc func, _Arg1 a1, _Arg2 a2, _Arg3 a3, _Arg4 a4) : 
        VfxSlot(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, ObjMemFunc)),
        m_args(a1, a2, a3, a4) 
    {
    }
};


/*****************************************************************************
 * Class VfxAsyncSignalUtil
 *****************************************************************************/

// Internal used. VfxAsyncSignalUtil is a singleton class which helps to process asyncronous signals.
class VfxAsyncSignalUtil : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxAsyncSignalUtil);

// Implementation
private:    
    friend class VfxBaseSignal;
    
// Constructor / Destructor
public:
    // Default constructor
    VfxAsyncSignalUtil()
    {
    }

// Overridable
public:
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator()
    {
        return vfx_sys_mem_get_global_allocator();
    }

// Method
public:
    void regPostEmit(
        const VfxBaseSignal         *baseSignal,
        VfxEmitEntryFuncPtr          emit_funcptr, 
        VfxSignalArg                *arguments,
        VfxObject                   *callback_obj,
        VfxSlotObjMemFuncPtr         callback_funcptr
    );

    void processPostEmit(void *data);

    template <class _MemFunc>
    void callback0(void *data)
    {
        typedef VfxPostInvoke0 <_MemFunc> PostInvoke;

        PostInvoke *invoke = (PostInvoke *)data;
        VfxObject *obj = invoke->m_objPtr.get();
        if (obj != NULL)
        {
            typename PostInvoke::ObjMemFunc memFunc = (typename PostInvoke::ObjMemFunc)invoke->m_callback;
            (obj->*memFunc)();
        }
        VFX_SYS_DELETE(invoke);
    }

    template <class _MemFunc, class _Arg1>
    void callback1(void *data)
    {
        typedef VfxPostInvoke1 <_MemFunc, _Arg1> PostInvoke;

        PostInvoke *invoke = (PostInvoke *)data;        
        VfxObject *obj = invoke->m_objPtr.get();
        if (obj != NULL)
        {
            typename PostInvoke::ObjMemFunc memFunc = (typename PostInvoke::ObjMemFunc)invoke->m_callback;
            (obj->*memFunc)(invoke->m_args.arg1);
        }
        VFX_SYS_DELETE(invoke);
    }

    template <class _MemFunc, class _Arg1, class _Arg2>
    void callback2(void *data)
    {
        typedef VfxPostInvoke2 <_MemFunc, _Arg1, _Arg2> PostInvoke;

        PostInvoke *invoke = (PostInvoke *)data;        
        VfxObject *obj = invoke->m_objPtr.get();
        if (obj != NULL)
        {
            typename PostInvoke::ObjMemFunc memFunc = (typename PostInvoke::ObjMemFunc)invoke->m_callback;
            (obj->*memFunc)(invoke->m_args.arg1, invoke->m_args.arg2);
        }
        VFX_SYS_DELETE(invoke);
    }

    template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3>
    void callback3(void *data)
    {
        typedef VfxPostInvoke3 <_MemFunc, _Arg1, _Arg2, _Arg3> PostInvoke;

        PostInvoke *invoke = (PostInvoke *)data;        
        VfxObject *obj = invoke->m_objPtr.get();
        if (obj != NULL)
        {
            typename PostInvoke::ObjMemFunc memFunc = (typename PostInvoke::ObjMemFunc)invoke->m_callback;
            (obj->*memFunc)(invoke->m_args.arg1, invoke->m_args.arg2, invoke->m_args.arg3);
        }
        VFX_SYS_DELETE(invoke);
    }

    template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3, class _Arg4>
    void callback4(void *data)
    {
        typedef VfxPostInvoke4 <_MemFunc, _Arg1, _Arg2, _Arg3, _Arg4> PostInvoke;
        
        PostInvoke *invoke = (PostInvoke *)data;        
        VfxObject *obj = invoke->m_objPtr.get();
        if (obj != NULL)
        {
            typename PostInvoke::ObjMemFunc memFunc = (typename PostInvoke::ObjMemFunc)invoke->m_callback;
            (obj->*memFunc)(invoke->m_args.arg1, invoke->m_args.arg2, invoke->m_args.arg3, invoke->m_args.arg4);
        }
        VFX_SYS_DELETE(invoke);
    }
};


/*****************************************************************************
 * Class VfxBaseSignal
 *****************************************************************************/

// Internal used. VfxBaseSignal is a base class for all VfxSignalX.
class VfxBaseSignal : public VfxBase
{
// Constructor / Distructor
public:
    // Default constructor
    VfxBaseSignal()
    {
    }

    // Base implement for triggering all connected handlers
    void emitImpl(VfxEmitEntryFuncPtr emit_funcptr, void *arguments) const;

    // Real emit signal in slots
    static void emitSlots(const VfxSlotList* slot_list, VfxEmitEntryFuncPtr emit_funcptr, void* arguments);

    // get number of connected slot
    VfxS32 getSlotCount() const;
    
protected:
    // Helper functions
    void baseConnectFront(VfxObject *obj, VfxSlotObjMemFuncPtr func);
    void baseConnect(VfxObject *obj, VfxSlotObjMemFuncPtr func);
    void baseDisconnect(VfxObject *obj, VfxSlotObjMemFuncPtr func);

protected:    
    VfxSlotList m_slotList;
    
// Implementation
private:
    void cleanInvalidSlots();

    friend class VfxAsyncSignalUtil;
};


/*****************************************************************************
 * Class VfxSignal0
 *****************************************************************************/

/*
 * Signal with no parameter
 */
class VfxSignal0 : public VfxBaseSignal
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSignal0);

private:
    typedef void (VfxObject::*obj_mem_funcptr_type)();
        
// Constructor / Distructor
public:
    // default constructor
    VfxSignal0()
    {
    }

    // Set the default slot
    template <class _func_type>
    void connectFront(VfxObject *obj, _func_type func)
    {
        baseConnectFront(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // connect to a member-to-function pointer
    template <class _func_type>
    void connect(VfxObject *obj, _func_type func)
    {
        baseConnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // disconnect from a member-to-function pointer
    template <class _func_type>
    void disconnect(VfxObject *obj, _func_type func)
    {
        baseDisconnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }

    // connect to a callback object
    void connect(VfxCallback0 cb)
    {
        baseConnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // disconnect from a callback object
    void disconnect(VfxCallback0 cb)
    {
        baseDisconnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // invoke a single signal function
    static void emitEntry(VfxObject *obj, VfxSlotObjMemFuncPtr callback, void* arguments)
    {
        VFX_UNUSED(arguments);
        (obj->*(obj_mem_funcptr_type)callback)();
    }

    // trigger this signal
    void emit() const
    {
        if (!m_slotList.isEmpty())
        {
            VfxSlotList tmpSlotList(m_slotList);
            emitSlots(&tmpSlotList, (VfxEmitEntryFuncPtr)&VfxSignal0::emitEntry, NULL);
        }
    }

    // post emit a signal
    template <class _func_type>
    void postEmit(
        VfxObject *obj,          // [IN] after emiting the signal, callback to which object 
        _func_type func          // [IN] after emiting the signal, callback to which member function of this object
    ) const
    {
        VFX_REG_POSTEMIT(VfxSignal0, NULL, obj, func);
    }

    // post emit a signal
    void postEmit() const
    {
        if (!m_slotList.isEmpty())
        {
            VFX_REG_POSTEMIT(VfxSignal0, NULL, NULL, NULL);
        }
    }
};


/*****************************************************************************
 * Class VfxSignal1
 *****************************************************************************/

/*
 * Signal with one parameter
 */
template <class _arg1_type>
class VfxSignal1 : public VfxBaseSignal
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSignal1);

private:
    typedef void (VfxObject::*obj_mem_funcptr_type)(_arg1_type arg1);
    typedef VfxSignalArg1 <_arg1_type> Argument;

public:
    // default constructor
    VfxSignal1()
    {
    }

    // Set the default slot
    template <class _func_type>
    void connectFront(VfxObject *obj, _func_type func)
    {
        baseConnectFront(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // connect to a member-to-function pointer
    template <class _func_type>
    void connect(VfxObject *obj, _func_type func)
    {
        baseConnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // disconnect from a member-to-function pointer
    template <class _func_type>
    void disconnect(VfxObject *obj, _func_type func)
    {
        baseDisconnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }

    // connect to a callback object
    void connect(VfxCallback1<_arg1_type> cb)
    {
        baseConnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // disconnect from a callback object
    void disconnect(VfxCallback1<_arg1_type> cb)
    {
        baseDisconnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // invoke a single signal function
    static void emitEntry(VfxObject *obj, VfxSlotObjMemFuncPtr callback, VfxSignalArg *arguments)
    {
        Argument* arg = (Argument*) arguments;
        (obj->* obj_mem_funcptr_type(callback))(arg->arg1);
    }

    // trigger this signal
    void emit(_arg1_type arg1) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument arg(arg1);
            VfxSlotList tmpSlotList(m_slotList);
            emitSlots(&tmpSlotList, (VfxEmitEntryFuncPtr)&VfxSignal1::emitEntry, (void*)&arg);
        }
    }

    // post emit a signal
    template <class _func_type>
    void postEmit(
        _arg1_type arg1,
        VfxObject *obj,      // [IN] after emiting the signal, callback to which object 
        _func_type func      // [IN] after emiting the signal, callback to which member function of this object
    ) const
    {
        Argument *arg;
        VFX_SYS_NEW_EX(arg, Argument, (arg1));
        VFX_REG_POSTEMIT(VfxSignal1, arg, obj, func);
    }

    // post emit a signal without callback
    void postEmit(
        _arg1_type arg1
    ) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument *arg;
            VFX_SYS_NEW_EX(arg, Argument, (arg1));
            VFX_REG_POSTEMIT(VfxSignal1, arg, NULL, NULL);
        }
    }
};


/*****************************************************************************
 * Class VfxSignal2
 *****************************************************************************/

/*
 * Signal with two parameters
 */
template <class _arg1_type, class _arg2_type>
class VfxSignal2 : public VfxBaseSignal
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSignal2);

private:
    typedef void (VfxObject::*obj_mem_funcptr_type)(_arg1_type arg1, _arg2_type arg2);
    typedef VfxSignalArg2<_arg1_type, _arg2_type> Argument;

public:
    // default constructor
    VfxSignal2()
    {
    }

    // Set the default slot
    template <class _func_type>
    void connectFront(VfxObject *obj, _func_type func)
    {
        baseConnectFront(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // connect to a member-to-function pointer
    template <class _func_type>
    void connect(VfxObject *obj, _func_type func)
    {
        baseConnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // disconnect from a member-to-function pointer
    template <class _func_type>
    void disconnect(VfxObject *obj, _func_type func)
    {
        baseDisconnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }

    // connect to a callback object
    void connect(VfxCallback2<_arg1_type, _arg2_type> cb)
    {
        baseConnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // disconnect from a callback object
    void disconnect(VfxCallback2<_arg1_type, _arg2_type> cb)
    {
        baseDisconnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // invoke a single signal function
    static void emitEntry(VfxObject *obj, VfxSlotObjMemFuncPtr callback, void *arguments)
    {
        Argument* arg = (Argument*) arguments;
        (obj->* obj_mem_funcptr_type(callback))(arg->arg1, arg->arg2);
    }

    // trigger this signal
    void emit(_arg1_type arg1, _arg2_type arg2) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument arg(arg1, arg2);
            VfxSlotList tmpSlotList(m_slotList);
            emitSlots(&tmpSlotList, (VfxEmitEntryFuncPtr)&VfxSignal2::emitEntry, (void*)&arg);
        }
    }

    // post emit a signal
    template <class _func_type>
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2,
        VfxObject *obj,      // [IN] after emiting the signal, callback to which object 
        _func_type func      // [IN] after emiting the signal, callback to which member function of this object
    ) const
    {
        Argument *arg;
        VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2));
        VFX_REG_POSTEMIT(VfxSignal2, arg, obj, func);
    }

    // post emit a signal
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2
    ) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument *arg;
            VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2));
            VFX_REG_POSTEMIT(VfxSignal2, arg, NULL, NULL);
        }
    }
};


/*****************************************************************************
 * Class VfxSignal3
 *****************************************************************************/

/*
 * Signal with 3 parameters
 */
template <class _arg1_type, class _arg2_type, class _arg3_type>
class VfxSignal3 : public VfxBaseSignal
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSignal3);

private:
    typedef void (VfxObject::*obj_mem_funcptr_type)(_arg1_type arg1, _arg2_type arg2, _arg3_type arg3);
    typedef VfxSignalArg3<_arg1_type, _arg2_type, _arg3_type> Argument;
    
public:
    // default constructor
    VfxSignal3()
    {
    }

    // Set the default slot
    template <class _func_type>
    void connectFront(VfxObject *obj, _func_type func)
    {
        baseConnectFront(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // connect to a member-to-function pointer
    template <class _func_type>
    void connect(VfxObject *obj, _func_type func)
    {
        baseConnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // disconnect from a member-to-function pointer
    template <class _func_type>
    void disconnect(VfxObject *obj, _func_type func)
    {
        baseDisconnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }

    // connect to a callback object
    void connect(VfxCallback3<_arg1_type, _arg2_type, _arg3_type> cb)
    {
        baseConnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // disconnect from a callback object
    void disconnect(VfxCallback3<_arg1_type, _arg2_type, _arg3_type> cb)
    {
        baseDisconnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // invoke a single signal function
    static void emitEntry(VfxObject *obj, VfxSlotObjMemFuncPtr callback, void *arguments)
    {
        Argument* arg = (Argument*) arguments;
        (obj->* obj_mem_funcptr_type(callback))(arg->arg1, arg->arg2, arg->arg3);
    }

    // trigger this signal
    void emit(_arg1_type arg1, _arg2_type arg2, _arg3_type arg3) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument arg(arg1, arg2, arg3);
            VfxSlotList tmpSlotList(m_slotList);
            emitSlots(&tmpSlotList, (VfxEmitEntryFuncPtr)&VfxSignal3::emitEntry, (void*)&arg);
        }
    }

    // post emit a signal
    template <class _func_type>
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2,
        _arg3_type arg3,
        VfxObject *obj,      // [IN] after emiting the signal, callback to which object 
        _func_type func      // [IN] after emiting the signal, callback to which member function of this object
    ) const
    {
        Argument *arg;
        VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2, arg3));
        VFX_REG_POSTEMIT(VfxSignal3, arg, obj, func);
    }

    // post emit a signal
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2,
        _arg3_type arg3
    ) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument *arg;
            VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2, arg3));
            VFX_REG_POSTEMIT(VfxSignal3, arg, NULL, NULL);
        }
    }
};


/*****************************************************************************
 * Class VfxSignal4
 *****************************************************************************/

/*
 * Signal with 4 parameters
 */
template <class _arg1_type, class _arg2_type, class _arg3_type, class _arg4_type>
class VfxSignal4 : public VfxBaseSignal
{
    VFX_DECLARE_NO_COPY_CLASS(VfxSignal4);

private:
    typedef void (VfxObject::*obj_mem_funcptr_type)(_arg1_type arg1, _arg2_type arg2, _arg3_type arg3, _arg4_type arg4);
    typedef VfxSignalArg4<_arg1_type, _arg2_type, _arg3_type, _arg4_type> Argument;
        
public:
    // default constructor
    VfxSignal4()
    {
    }

    // Set the default slot
    template <class _func_type>
    void connectFront(VfxObject *obj, _func_type func)
    {
        baseConnectFront(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // connect to a member-to-function pointer
    template <class _func_type>
    void connect(VfxObject *obj, _func_type func)
    {
        baseConnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }
    
    // disconnect from a member-to-function pointer
    template <class _func_type>
    void disconnect(VfxObject *obj, _func_type func)
    {
        baseDisconnect(obj, (VfxSlotObjMemFuncPtr)VFX_STATIC_CAST(func, obj_mem_funcptr_type));
    }

    // connect to a callback object
    void connect(VfxCallback4<_arg1_type, _arg2_type, _arg3_type, _arg4_type> cb)
    {
        baseConnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // disconnect from a callback object
    void disconnect(VfxCallback4<_arg1_type, _arg2_type, _arg3_type, _arg4_type> cb)
    {
        baseDisconnect(cb.m_objPtr.get(), cb.m_callback);
    }

    // invoke a single signal function
    static void emitEntry(VfxObject *obj, VfxSlotObjMemFuncPtr callback, void *arguments)
    {
        Argument* arg = (Argument*) arguments;
        (obj->* obj_mem_funcptr_type(callback))(arg->arg1, arg->arg2, arg->arg3, arg->arg4);
    }

    // trigger this signal
    void emit(_arg1_type arg1, _arg2_type arg2, _arg3_type arg3, _arg4_type arg4) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument arg(arg1, arg2, arg3, arg4);
            VfxSlotList tmpSlotList(m_slotList);
            emitSlots(&tmpSlotList, (VfxEmitEntryFuncPtr)&VfxSignal4::emitEntry, (void*)&arg);
        }
    }

    // post emit a signal
    template <class _func_type>
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2,
        _arg3_type arg3,
        _arg4_type arg4,
        VfxObject *obj,      // [IN] after emiting the signal, callback to which object 
        _func_type func      // [IN] after emiting the signal, callback to which member function of this object
    ) const
    {
        Argument *arg;
        VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2, arg3, arg4));
        VFX_REG_POSTEMIT(VfxSignal4, arg, obj, func);
    }

    // post emit a signal
    void postEmit(
        _arg1_type arg1,
        _arg2_type arg2,
        _arg3_type arg3,
        _arg4_type arg4
    ) const
    {
        if (!m_slotList.isEmpty())
        {
            Argument *arg;
            VFX_SYS_NEW_EX(arg, Argument, (arg1, arg2, arg3, arg4));
            VFX_REG_POSTEMIT(VfxSignal4, arg, NULL, NULL);
        }
    }
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

// When a slot want to stop the signal emiting, 
//   it can call this API to stop the emit process.
void vfxStopEmit();


// Post invoke a member function without
template <class _MemFunc>
void vfxPostInvoke0(
    VfxObject *obj,     // [IN] the callback object
    _MemFunc func     // [IN] the callback object member function
)
{
    typedef VfxPostInvoke0 <_MemFunc> PostInvoke;
    PostInvoke *invoke;
    VFX_SYS_NEW_EX(invoke, PostInvoke, (obj, func));
    vfxPostInvoke(
        VFX_OBJ_GET_INSTANCE(VfxAsyncSignalUtil), 
        &VfxAsyncSignalUtil::callback0 <_MemFunc>, 
        invoke);
}


// Post invoke a member function with 1 arguments
template <class _MemFunc, class _Arg1>
void vfxPostInvoke1(
    VfxObject *obj,     // [IN] the callback object
    _MemFunc func,    // [IN] the callback object member function
    _Arg1 arg1     // [IN] the 1'st argument
)
{
    typedef VfxPostInvoke1 <_MemFunc, _Arg1> PostInvoke;
    PostInvoke *invoke;
    VFX_SYS_NEW_EX(invoke, PostInvoke, (obj, func, arg1));
    vfxPostInvoke(
        VFX_OBJ_GET_INSTANCE(VfxAsyncSignalUtil), 
        &VfxAsyncSignalUtil::callback1 <_MemFunc, _Arg1>, 
        invoke);
}


// Post invoke a member function with 2 arguments
template <class _MemFunc, class _Arg1, class _Arg2>
void vfxPostInvoke2(
    VfxObject *obj,     // [IN] the callback object
    _MemFunc func,    // [IN] the callback object member function
    _Arg1 arg1,    // [IN] the 1'st argument
    _Arg2 arg2     // [IN] the 2'nd argument
)
{
    typedef VfxPostInvoke2 <_MemFunc, _Arg1, _Arg2> PostInvoke;
    PostInvoke *invoke;
    VFX_SYS_NEW_EX(invoke, PostInvoke, (obj, func, arg1, arg2));
    vfxPostInvoke(
        VFX_OBJ_GET_INSTANCE(VfxAsyncSignalUtil), 
        &VfxAsyncSignalUtil::callback2 <_MemFunc, _Arg1, _Arg2>, 
        invoke);
}


// Post invoke a member function with 3 arguments
template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3>
void vfxPostInvoke3(
    VfxObject *obj,     // [IN] the callback object
    _MemFunc func,    // [IN] the callback object member function
    _Arg1 arg1,    // [IN] the 1'st argument
    _Arg2 arg2,    // [IN] the 2'nd argument
    _Arg3 arg3     // [IN] the 3'rd argument
)
{
    typedef VfxPostInvoke3 <_MemFunc, _Arg1, _Arg2, _Arg3> PostInvoke;
    PostInvoke *invoke;
    VFX_SYS_NEW_EX(invoke, PostInvoke, (obj, func, arg1, arg2, arg3));
    vfxPostInvoke(
        VFX_OBJ_GET_INSTANCE(        VfxAsyncSignalUtil), 
        &VfxAsyncSignalUtil::callback3 <_MemFunc, _Arg1, _Arg2, _Arg3>, 
        invoke);
}


// Post invoke a member function with 4 arguments
template <class _MemFunc, class _Arg1, class _Arg2, class _Arg3, class _Arg4>
void vfxPostInvoke4(
    VfxObject *obj,     // [IN] the callback object
    _MemFunc func,    // [IN] the callback object member function
    _Arg1 arg1,    // [IN] the 1'st argument
    _Arg2 arg2,    // [IN] the 2'nd argument
    _Arg3 arg3,    // [IN] the 3'rd argument
    _Arg4 arg4     // [IN] the 4'th argument
)
{
    typedef VfxPostInvoke4 <_MemFunc, _Arg1, _Arg2, _Arg3, _Arg4> PostInvoke;
    PostInvoke *invoke;
    VFX_SYS_NEW_EX(invoke, PostInvoke, (obj, func, arg1, arg2, arg3, arg4));
    vfxPostInvoke(
        VFX_OBJ_GET_INSTANCE(VfxAsyncSignalUtil), 
        &VfxAsyncSignalUtil::callback4 <_MemFunc, _Arg1, _Arg2, _Arg3, _Arg4>, 
        invoke);
}

#endif /* __VFX_SIGNAL_H__ */

