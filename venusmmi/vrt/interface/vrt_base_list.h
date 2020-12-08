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
 *  vrt_base_list.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  List Container
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
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRT_BASE_LIST_H__
#define __VRT_BASE_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vrt_datatype.h"
// For VrtTypeInfo
#include "vrt_base_type_info.h"
// For vrt_allocator_handle
#include "vrt_base_allocator.h"


#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct vrt_list_entry_struct *vrt_list_entry_handle; 
typedef struct vrt_list_struct *vrt_list_handle; 


/***************************************************************************** 
 * Global function
 *****************************************************************************/

extern vrt_list_handle vrt_list_create(
    vrt_allocator_handle allocator,
    const vrt_type_info_struct *callbacks
    );

extern void vrt_list_release(
    vrt_list_handle list
    );

extern void vrt_list_assign_values(
    vrt_list_handle list,
    const void *values_buf,
    vrt_u32 value_pitch_bytes,
    vrt_u32 value_count
    );

extern void vrt_list_assign_list(
    vrt_list_handle list,
    const vrt_list_handle other_list
    );   

extern vrt_list_entry_handle vrt_list_get_head(
    vrt_list_handle list
    );
    
extern vrt_list_entry_handle vrt_list_get_tail(
    vrt_list_handle list
    );

extern vrt_size vrt_list_get_size(
    vrt_list_handle list
    );   

extern void vrt_list_push_front(
    vrt_list_handle list,
    const void *value
    );

extern void vrt_list_pop_front(
    vrt_list_handle list
    );        

extern void vrt_list_push_back(
    vrt_list_handle list,
    const void *value
    );

extern void vrt_list_pop_back(
    vrt_list_handle list
    );        

extern vrt_list_entry_handle vrt_list_insert(
    vrt_list_handle list,
    vrt_list_entry_handle pos,
    const void *value
    );

extern vrt_list_entry_handle vrt_list_erease(
    vrt_list_handle list,
    vrt_list_entry_handle pos
    );

extern vrt_list_entry_handle vrt_list_erease_range(
    vrt_list_handle list,
    vrt_list_entry_handle first,
    vrt_list_entry_handle last
    );

extern void vrt_list_clear(
    vrt_list_handle list
    );

extern void vrt_list_remove_value(
    vrt_list_handle list,
    const void *value,
    vrt_type_info_equal_funcptr_type equal_func
    );

extern vrt_list_entry_handle vrt_list_find(
    vrt_list_handle list,
    const void *value,
    vrt_type_info_equal_funcptr_type equal_func
    );

extern vrt_list_entry_handle vrt_list_entry_get_prev(
    vrt_list_entry_handle entry
    );

extern vrt_list_entry_handle vrt_list_entry_get_next(
    vrt_list_entry_handle entry
    );

extern void *vrt_list_entry_get_value(
    vrt_list_entry_handle entry
    );

#ifdef __cplusplus
} /* extern "C" */
#endif


#ifdef __cplusplus

/***************************************************************************** 
 * Template VrtBaseListIt
 *****************************************************************************/

template <class T>
class VrtBaseListIt
{
public:
    typedef T &Ref;
    typedef T *Pointer;
    
// Constructor / Destructor
public:
    // Default constructor
    VrtBaseListIt() : m_handle(NULL)
    {
    }

    explicit VrtBaseListIt(vrt_list_entry_handle handle) : m_handle(handle)
    {
    }

    // Copy constructor
    VrtBaseListIt(const VrtBaseListIt &other) : m_handle(other.m_handle)
    {
    }

// Operator    
public:
    bool operator == (const VrtBaseListIt &other) const 
    { 
        return m_handle == other.m_handle; 
    }
      
    bool operator != (const VrtBaseListIt &other) const 
    { 
        return m_handle != other.m_handle; 
    }

    Ref operator * () const
    {
        return *(T *)vrt_list_entry_get_value(m_handle);
    }

    Pointer operator -> () const
    {
        return (T *)vrt_list_entry_get_value(m_handle);
    }

    VrtBaseListIt &operator ++ ()
    {
        m_handle = vrt_list_entry_get_next(m_handle);
        return *this;
    }
    
    VrtBaseListIt operator ++ (int)
    {
        vrt_list_entry_handle oldHandle = m_handle;
        m_handle = vrt_list_entry_get_next(m_handle);
        return VrtBaseListIt(oldHandle);
    }
    
    VrtBaseListIt &operator -- ()
    {
        m_handle = vrt_list_entry_get_prev(m_handle);
        return *this;
    }
    
    VrtBaseListIt operator -- (int)
    {
        vrt_list_entry_handle oldHandle = m_handle;
        m_handle = vrt_list_entry_get_prev(m_handle);
        return VrtBaseListIt(oldHandle);
    }

// Method
public:
    Ref getValue() const
    {
        return *(T *)vrt_list_entry_get_value(m_handle);
    }

    bool isNull() const
    {
        return m_handle == NULL;
    }

    // Internal used.
    vrt_list_entry_handle getHandle() const
    {
        return m_handle;
    }
    
private:
    vrt_list_entry_handle m_handle;
};


/***************************************************************************** 
 * Template VrtBaseList
 *****************************************************************************/

template <
    class T, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info
    >
class VrtBaseList
{
public:
    typedef VrtBaseListIt <T> It;
    typedef VrtBaseListIt <const T> ConstIt;
    
// Constructor / Destructor
public:
    // Default constructor
    VrtBaseList() : m_handle(NULL)
    {
    }

    // Default constructor
    explicit VrtBaseList(vrt_allocator_handle allocator) : m_handle(NULL)
    {
        init(allocator);
    }
    
    // Construct with values
    VrtBaseList(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount) : m_handle(NULL)
    {
        init(allocator, values, valueCount);
    }
    
    // Copy constructor
    VrtBaseList(vrt_allocator_handle allocator, const VrtBaseList &other) : m_handle(NULL)
    {
        init(allocator, other);
    }
    
    // Destructor    
    ~VrtBaseList()
    {
        deinit();
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_list_create(allocator, valueTypeInfo);
    }
    
    void init(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_list_create(allocator, valueTypeInfo);
        vrt_list_assign_values(m_handle, values, sizeof(T), valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VrtBaseList &other)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_list_create(allocator, valueTypeInfo);
        vrt_list_assign_list(m_handle, other.m_handle);
    }

    void deinit()
    {
        vrt_list_release(m_handle);
        m_handle = NULL;
    }

    It begin()
    {
        return It(vrt_list_get_head(m_handle));
    }

    ConstIt begin() const
    {
        return ConstIt(vrt_list_get_head(m_handle));
    }

    It end()
    {
        return It();
    }

    ConstIt end() const
    {
        return ConstIt();
    }

    It rbegin()
    {
        return It(vrt_list_get_tail(m_handle));
    }

    ConstIt rbegin() const
    {
        return ConstIt(vrt_list_get_tail(m_handle));
    }

    It rend()
    {
        return It();
    }

    ConstIt rend() const
    {
        return ConstIt();
    }

    bool empty() const
    {
        return vrt_list_get_head(m_handle) == NULL;
    }

    vrt_size size() const
    {
        return vrt_list_get_size(m_handle);
    }

    T &front() const
    {
        return *(T *)vrt_list_entry_get_value(vrt_list_get_head(m_handle));
    }

    T &back() const
    {
        return *(T *)vrt_list_entry_get_value(vrt_list_get_tail(m_handle));
    }

    void pushFront(const T &x)
    {
        vrt_list_push_front(m_handle, &x);
    }

    void popFront()
    {
        vrt_list_pop_front(m_handle);
    }

    void pushBack(const T &x)
    {
        vrt_list_push_back(m_handle, &x);
    }

    void popBack()
    {
        vrt_list_pop_back(m_handle);
    }

    It insert(It position, const T &x)
    {
        return It(vrt_list_insert(m_handle, position.getHandle(), &x));
    }

    It erase(It position)
    {
        return It(vrt_list_erease(m_handle, position.getHandle()));
    }

    It erase(It first, It last)
    {
        return It(vrt_list_erease_range(m_handle, first.getHandle(), last.getHandle()));
    }

    void clear()
    {
        vrt_list_clear(m_handle);
    }

    void remove(const T &value)
    {
        vrt_list_remove_value(m_handle, &value, VrtTypeInfo <T>::equal);
    }        

    void remove(const T &value, vrt_type_info_equal_funcptr_type equalFunc)
    {
        vrt_list_remove_value(m_handle, &value, equalFunc);
    }        

    It find(const T &value) const
    {
        return It(vrt_list_find(m_handle, &value, VrtTypeInfo <T>::equal));
    }

    It find(const T &value, vrt_type_info_equal_funcptr_type equalFunc) const
    {
        return It(vrt_list_find(m_handle, &value, equalFunc));
    }
    
// Operator
public:
    // Assigne operator
    VrtBaseList &operator = (const VrtBaseList &other)
    {
        vrt_list_assign_list(m_handle, other,m_handle);
        return *this;
    }

// Method
public:
    // Internal used.
    vrt_list_handle getHandle() const
    {
        return m_handle;
    }

// Implementation
private:
    // Disable default copy constructor, no implement
    explicit VrtBaseList(const VrtBaseList &other);

// Implementation
private:
    vrt_list_handle m_handle;
};

#endif /* __cplusplus */

#endif /* __VRT_BASE_LIST_H__ */

