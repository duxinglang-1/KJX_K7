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
 *  vfx_cpp_base.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Core basic definition for C++
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
 * removed!
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
#ifndef __VFX_CPP_BASE_H__
#define __VFX_CPP_BASE_H__

#ifndef __cplusplus
#error "vfx_cpp_base.h is only for c++ code"
#endif 

/* dsiable some VC compile warning */
#ifdef WIN32
/* warning C4786: identifier was truncated to '255' characters in the debug information */
#pragma warning(disable : 4786)
/* warning C4291: no matching operator delete found; memory will not be freed if initialization throws an exception */
#pragma warning(disable : 4291)
/* warning C4996: '_vsnprintf': This function or variable may be unsafe. Consider using _vsnprintf_s instead. */
#pragma warning(disable : 4996)
/* warning C4819: The file contains a character that cannot be represented in the current code page (950).  */
#pragma warning(disable : 4819)
/* warning C4068: unknown pragma */
#pragma warning(disable : 4068)
#endif


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For macros, VfxFloat, etc.
#include "vfx_system.h"
// For VFX_MEM_LOG
#include "vfx_sys_memory.h"
// For vfx_sys_sin(), etc.
#include "vfx_adp_clib.h"

#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include <string.h>

#include "vfx_sys_mem_config.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

// These C++ features are supported by VC and RVCT, not by ADS
#if defined(_MSC_VER) || defined(__RVCT__)

// Converts the poitner to specified class type
#define VFX_STATIC_CAST(_ptr, _type)    (static_cast <_type> (_ptr))
// Remove const attributes from a class type 
#define VFX_CONST_CAST(_ptr, _type)     (const_cast <_type> (_ptr))

#else

#define VFX_STATIC_CAST(_ptr, _type)    ((_type)(_ptr))
#define VFX_CONST_CAST(_ptr, _type)     ((_type)(_ptr))

#endif // defined(_MSC_VER) || defined(__RVCT__)


/*
 * New operator macro.
 *
 * NOTE: Assert if fail.
 *
 * SEE ALSO: VFX_NEW_EX, VFX_DELETE
 *
 * EXAMPLE:
 * <code>
 *  VFX_NEW(ptr, MyClass);
 * </code>
 */
#define VFX_NEW(_ptr, _className)                                               \
    do                                                                          \
    {                                                                           \
        (_ptr) = new _className();                                              \
        VFX_MEM_LOG(("[VFX] NEW 00000000 00000000 %08X %d %s", (_ptr), sizeof(_className), #_className)); \
    } while(0)

/*
 * new operator macro with constructor parameters
 *
 * NOTE: Assert if fail.
 *
 * SEE ALSO: VFX_NEW, VFX_DELETE
 *
 * EXAMPLE:
 * <code>
 *  VFX_NEW_EX(ptr, MyClass, (param1, param2));
 * </code>
 */
#define VFX_NEW_EX(_ptr, _className, _param)                                    \
    do                                                                          \
    {                                                                           \
        (_ptr) = new _className _param;                                         \
        VFX_MEM_LOG(("[VFX] NEW 00000000 00000000 %08X %d %s", (_ptr), sizeof(_className), #_className)); \
    } while(0)

/*
 * Safe delete macro. If the given pointer is not NULL, delete the target 
 * and reset the pointer to be NULL.
 *
 * SEE ALSO: VFX_NEW, VFX_NEW_EX
 */
#define VFX_DELETE(_ptr)                                                        \
    do                                                                          \
    {                                                                           \
        if (_ptr != NULL)                                                       \
        {                                                                       \
            VFX_MEM_LOG(("[VFX] DELETE %08X", (_ptr)));                        \
            delete (_ptr);                                                      \
            (_ptr) = NULL;                                                      \
        }                                                                       \
    } while(0)


/*
 * Use allocator to allocate a block of memory
 */
#define VFX_ALLOC_MEM(_ptr, _size, _owner) \
    do \
    { \
        VFX_DEV_ASSERT(_owner);                \
        IVfxAllocatable *_a = (_owner);        \
        const VfxChar *_filename;              \
        VfxU32 _line;                           \
        VFX_MEM_FILL_FILENAME(_filename, _line); \
        (*(void **)(&(_ptr))) = vrt_allocator_alloc_int(_a->getAllocator(), _size, VRT_ALLOCATOR_ALLOC_FLAG_NONE, _filename, _line); \
        VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d <MEM>", _a->getAllocator(), _a->_getId(), (_ptr), (_size))); \
    } while(0)

/*
 * Use allocator to allocate a block of memory
 */
#define VFX_ALLOC_MEM_EX(_ptr, _size, _flags, _owner) \
    do \
    { \
        VFX_DEV_ASSERT(_owner);                 \
        IVfxAllocatable *_a = (_owner);         \
        const VfxChar *_filename;               \
        VfxU32 _line;                            \
        VFX_MEM_FILL_FILENAME(_filename, _line);  \
        (*(void **)(&(_ptr))) = vrt_allocator_alloc_int(_a->getAllocator(), _size, _flags, _filename, _line); \
        VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d <MEM>", _a->getAllocator(), _a->_getId(), (_ptr), (_size))); \
    } while(0)

/*
 * Free a memory created from VFX_ALLOC_MEM
 */
#define VFX_FREE_MEM(_ptr)                                                      \
    do                                                                          \
    {                                                                           \
        if (_ptr)                                                               \
        {                                                                       \
            VFX_MEM_LOG(("[VFX] DELETE %08X", (_ptr)));                        \
            VfxBase::freeSysMemory(_ptr);                                          \
            (_ptr) = NULL;                                                      \
        }                                                                       \
    } while(0)

/*
 * Use allocator to allocate a block of memory
 */
#define VFX_SYS_ALLOC_MEM(_ptr, _size)                                            \
    do                                                                            \
    {                                                                             \
        const VfxChar *_filename;                                                 \
        VfxU32 _line;                                                             \
        VFX_MEM_FILL_FILENAME(_filename, _line);                                  \
        (*(void **)(&(_ptr))) = VfxBase::allocSysMemory(_size, _filename, _line);      \
        VFX_MEM_LOG(("[VFX] NEW 00000000 00000000 %08X %d <MEM>", (_ptr), (_size)));    \
    } while(0)

    
/*
 * Free a memory created from VFX_SYS_ALLOC_MEM
 */
#define VFX_SYS_FREE_MEM(_ptr)                                                  \
    do                                                                          \
    {                                                                           \
        if (_ptr)                                                               \
        {                                                                       \
            VFX_MEM_LOG(("[VFX] DELETE %08X", (_ptr)));                        \
            VfxBase::freeSysMemory(_ptr);                                          \
            (_ptr) = NULL;                                                      \
        }                                                                       \
    } while(0)

    
/*
 * Use allocator to new an object
 */
#define VFX_ALLOC_NEW(_ptr, _className, _owner)  \
    do                                           \
    {                                            \
        IVfxAllocatable *_a = (_owner);          \
        const VfxChar *_filename;                \
        VfxU32 _line;                            \
        VFX_MEM_FILL_FILENAME(_filename, _line); \
        _className *_p = new (_a, _filename, _line) _className(); \
        VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d %s", (_a ? _a->getAllocator() : 0), (_a ? _a->_getId() : 0), _p, sizeof(_className), #_className)); \
        (_ptr) = _p; \
    } while(0)

/*
 * Use allocator to new an object with constructor parameters
 */
#define VFX_ALLOC_NEW_EX(_ptr, _className, _owner, _param) \
    do \
    { \
        IVfxAllocatable *_a = (_owner);          \
        const VfxChar *_filename;                \
        VfxU32 _line;                            \
        VFX_MEM_FILL_FILENAME(_filename, _line); \
        _className *_p = new (_a, _filename, _line) _className _param; \
        VFX_MEM_LOG(("[VFX] NEW %08X %08X %08X %d %s", (_a ? _a->getAllocator() : 0), (_a ? _a->_getId() : 0), _p, sizeof(_className), #_className)); \
        (_ptr) = _p; \
    } while(0) 
/*
 * Internal used. System new operator macro.
 *
 * NOTE: Assert if fail.
 */
#define VFX_SYS_NEW(_ptr, _className)             \
    do                                            \
    {                                             \
        const VfxChar *_filename;                 \
        VfxU32 _line;                             \
        VFX_MEM_FILL_FILENAME(_filename, _line);  \
        _className *_p = new (vfx_sys_mem_get_global_allocator(), _filename, _line) _className; \
        VFX_MEM_LOG(("[VFX] NEW 00000000 00000000 %08X %d %s", _p, sizeof(_className), #_className)); \
        (_ptr) = _p; \
    } while(0)

/*
 * Internal used. System new operator macro.
 *
 * NOTE: Assert if fail.
 */
#define VFX_SYS_NEW_EX(_ptr, _className, _param) \
    do                                           \
    {                                            \
        const VfxChar *_filename;                \
        VfxU32 _line;                            \
        VFX_MEM_FILL_FILENAME(_filename, _line); \
        _className *_p = new (vfx_sys_mem_get_global_allocator(), _filename, _line) _className _param; \
        VFX_MEM_LOG(("[VFX] NEW 00000000 00000000 %08X %d %s", _p, sizeof(_className), #_className)); \
        (_ptr) = _p; \
    } while(0)

/*
 * Internal used. System delete operator macro.
 */
#define VFX_SYS_DELETE(_ptr)                                                    \
    do                                                                          \
    {                                                                           \
        if (_ptr)                                                               \
        {                                                                       \
            VFX_MEM_LOG(("[VFX] DELETE %08X", (_ptr)));                        \
            delete (_ptr);                                                      \
            (_ptr) = NULL;                                                      \
        }                                                                       \
    } while(0)


/*
 * Define a class can not be copied. If you try to copy this object, 
 * it will cause a compile error.
 *
 * EXAMPLE:
 *  <code>
 *  class MyClass
 *  {
 *      VFX_DECLARE_NO_COPY_CLASS(MyClass);
 *
 *  public:
 *      // class define
 *  };
 *  </code> 
 */
#define VFX_DECLARE_NO_COPY_CLASS(className)                                    \
    private:                                                                    \
        className(const className&);                                            \
        className &operator = (const className &)

/*
 * Define a class can not be assigned. If you try to assign with other object, 
 * it will cause a compile error.
 *
 * EXAMPLE:
 *  <code>
 *  class MyClass
 *  {
 *      VFX_DECLARE_NO_ASSIGN_CLASS(MyClass);
 *
 *  public:
 *      // class define
 *  };
 *  </code> 
 */
#define VFX_DECLARE_NO_ASSIGN_CLASS(className)                                  \
    private:                                                                    \
        className &operator = (const className &)


/*
 * Define a constant object
 */
#define VFX_DEFINE_CONST(_varName, _className) \
    extern const _className &get_##_varName()

/*
 * Implement a constant object
 */
#define VFX_IMPLEMENT_CONST(_varName, _className, _param) \
    static VfxU32 _varName##_buf[(sizeof(_className) + sizeof(VfxU32) - 1) / sizeof(VfxU32)]; \
    static VfxBool _varName##_flag = VFX_FALSE; \
    \
    const _className &get_##_varName() \
    { \
        if (!_varName##_flag) \
        { \
            new (_varName##_buf) _className _param; \
            _varName##_flag = VFX_TRUE; \
        } \
        return *(_className *)_varName##_buf; \
    }

/*
 * Get the constant object
 */
#define VFX_GET_CONST(_varName)         get_##_varName()


/***************************************************************************** 
 * Interface IVfxAllocatable
 *****************************************************************************/

/*
 * IVfxAllocatable is a interface defined to support memory allocation
 */
class IVfxAllocatable
{
public:
    // Get the allocator
    virtual vrt_allocator_handle getAllocator();
    // Get ID
    virtual VfxU32 _getId() const;
};


/***************************************************************************** 
 * Class VfxBase
 *****************************************************************************/

/*
 * VfxBase is the base of all class in the Venus, all classes must inherit 
 * from this class.
 */
class VfxBase
{
// Static method    
public:
    // Allocate a block of memory from memory pool.
    //
    // RETURNS: The allocated memory
    static void *allocSysMemory(
        size_t size     // [IN] memory size to allocate
    );
    // Allocate a block of memory from memory pool.
    //
    // RETURNS: The allocated memory
    static void *allocSysMemory(
        size_t size,                // [IN] memory size to allocate
        const char *file,           // [IN] Filename (for logging)
        VfxU32 line                 // [IN] line (for logging)
    );
    // Free a given memory to memory pool.
    //
    // SEE ALSO: allocSysMemory
    static void freeSysMemory(
        void *ptr       // [IN] the pointer to free
    );

// Operator
public:
    // Internal used. Override new operator to dynamically allocate instance.
    //
    // SEE ALSO: VFX_NEW
    //
    // RETURNS: The allocated memory
    static void *operator new (
        size_t size     // [IN] allocate size
    );
    
    // Internal used. Override free operator to free instance
    //
    // SEE ALSO: VFX_DELETE
    static void operator delete (
        void *ptr       // [IN] pointer to instance
    );

    // Internal used. Override placement new operator.
    //
    // EXAMPLE:
    // <code>
    //  VfxU8 someBuffer[1024];
    //  MyObject *s = new (someBuffer) MyObject();
    // </code>
    static void *operator new (
        size_t size,    // [IN] The memory size to allocate
        void *buf       // [IN] The buffer to be allocated
    )
    {
        VFX_UNUSED(size);
        return buf;
    }

    // Internal used. new an object by allocator
    //
    // EXAMPLE:
    // <code>
    //  MyObject *s = new (myAllocator, filename, line) MyObject();
    // </code>
    static void *operator new (
        size_t size,                // [IN] The memory size to allocate
        IVfxAllocatable *allocator, // [IN] The allocator to be allocate from
        const char *file,           // [IN] Filename (for logging)
        VfxU32 line                 // [IN] line (for logging)
    );

    // Internal used. new an object by allocator
    //
    // EXAMPLE:
    // <code>
    //  MyObject *s = new (myAllocator, filename, line) MyObject();
    // </code>
    static void *operator new (
        size_t size,                // [IN] The memory size to allocate
        vrt_allocator_handle allocator, // [IN] The allocator to be allocate from
        const char *file,           // [IN] Filename (for logging)
        VfxU32 line                 // [IN] line (for logging)
    );

    // Internal used. new an object by allocator
    static void *operator new (
        size_t size,                // [IN] The memory size to allocate
        IVfxAllocatable *allocator // [IN] The allocator to be allocate from
    );

    // Internal used. Placement new and assign a allocator
    static void *operator new (
        size_t size,                    // [IN] The memory size to allocate
        vrt_allocator_handle allocator, // [IN] The allocator to put before 
        void *buf                       // [IN] The buffer to be allocated
    );
    
private:    
    // Do not use C++ new array operator
    // NOTE:
    //  New arrary operator has many problems on most C++ compiler, 
    //  so disable it.
    static void *operator new[] (
        size_t size     // [IN] allocate size
    )
    {
        VFX_UNUSED(size);
        return NULL;
    }

    // Do not use C++ new array operator
    static void operator delete[] (
        void *ptr       // [IN] pointer to instance array
    )
    {
        VFX_UNUSED(ptr);
        VFX_ASSERT(0);
    }
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

// Swap two variables.
template <class _type>
inline 
void vfxSwap(
    _type &lhs, //  [INOUT] The first variable to be swapped
    _type &rhs  //  [INOUT] The second variable to be swapped
)
{
    _type temp = rhs;
    rhs = lhs;
    lhs = temp;
}


// Compare two variables and return the larger one.
template <class _type>
inline 
const _type &vfxMax(
    const _type &lhs,   // [IN] The first variable to be compared
    const _type &rhs    // [IN] The second variable to be compared
)
{
    return lhs > rhs ? lhs : rhs;
}


// Compare two variables and return the smaller one.
template <class _type>
inline 
const _type &vfxMin(
    const _type &lhs,   // [IN] The first variable to be compared 
    const _type &rhs    // [IN] The second variable to be compared
)
{
    return lhs < rhs ? lhs : rhs;
}


// Return the absolute value of given value
template <class _type>
inline 
_type vfxAbs(
    const _type &x      // [IN] The given value
)
{
    return x < 0 ? -x : x;
}


// Cosine funtion
//
// RETURNS: The cosine of an angle
inline 
VfxFloat vfxCos(
    VfxFloat rad        // [IN] An angle in radians
)
{
    return vfx_sys_cos(rad);
}


// Sine function
//
// Returns: The sine of an angle
inline 
VfxFloat vfxSin(
    VfxFloat rad        // [IN] An angle in radians
)
{
    return vfx_sys_sin(rad);
}


// Caculate square root
//
// RETURNS: The square root of x
inline 
VfxFloat vfxSqrt(
    VfxFloat x          // [IN] A positive floating value
)
{
    return vfx_sys_sqrt(x);
}


// Caculate floor
//
// RETURNS: The floor of x
inline 
VfxFloat vfxFloor(
    VfxFloat x          // [IN] A positive floating value
)
{
    return vfx_sys_floor(x);
}


// Caculate ceil
//
// RETURNS: The ceil of x
inline 
VfxFloat vfxCeil(
    VfxFloat x          // [IN] A positive floating value
)
{
    return vfx_sys_ceil(x);
}


// Caculate the diffenece of two VfxMsec
//
// RETURNS: The diffenece of two VfxMsec
inline
VfxMsec vfxMsecDiff(
    VfxMsec testTime,   // [IN] The time to diff
    VfxMsec baseTime    // [IN] The base time to diff
)
{
    return VRT_MSEC_DIFF(testTime, baseTime);
}

#endif /* __VFX_CPP_BASE_H__ */

