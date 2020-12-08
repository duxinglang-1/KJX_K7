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
 *  vrt_base_array.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Array Container
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

#ifndef __VRT_BASE_ARRAY_H__
#define __VRT_BASE_ARRAY_H__

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

typedef struct vrt_array_struct *vrt_array_handle; 


/***************************************************************************** 
 * Global function
 *****************************************************************************/

extern vrt_array_handle vrt_array_create(
    vrt_allocator_handle allocator,
    const vrt_type_info_struct *callbacks
    );

extern void vrt_array_release(
    vrt_array_handle array
    );

extern void vrt_array_assign_values(
    vrt_array_handle array,
    const void *values_buf,
    vrt_size value_pitch_bytes,
    vrt_u32 value_count
    );

extern void vrt_array_assign_array(
    vrt_array_handle array,
    const vrt_array_handle other_array
    );

extern void *vrt_array_get_values(
    const vrt_array_handle array
    );

extern vrt_size vrt_array_get_size(
    const vrt_array_handle array
    );

extern void vrt_array_resize(
    vrt_array_handle array,
    vrt_u32 count,
    const void *value
    );

extern vrt_u32 vrt_array_get_capacity(
    const vrt_array_handle array
    );

extern void vrt_array_reserve(
    vrt_array_handle array,
    vrt_u32 count
    );

extern void *vrt_array_get_value(
    vrt_array_handle array,
    vrt_u32 index
    );

extern void vrt_array_insert(
    vrt_array_handle array,
    vrt_u32 index,
    const void *value
    );

extern void vrt_array_erase(
    vrt_array_handle array,
    vrt_u32 index
    );
    
extern void vrt_array_clear(
    vrt_array_handle array
    );

#ifdef __cplusplus
} /* extern "C" */
#endif


#ifdef __cplusplus

/***************************************************************************** 
 * Template VrtBaseArray
 *****************************************************************************/

template <
    class T, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info
    >
class VrtBaseArray
{
public:
    typedef T &Ref;
    
// Constructor / Destructor
public:
    // Default constructor
    VrtBaseArray() : m_handle(NULL)
    {
    }

    // Default constructor
    explicit VrtBaseArray(vrt_allocator_handle allocator) : m_handle(NULL)
    {
        init(allocator);
    }
    
    // Construct with values
    VrtBaseArray(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount) : m_handle(NULL)
    {
        init(allocator, values, valueCount);
    }
    
    // Copy constructor
    VrtBaseArray(vrt_allocator_handle allocator, const VrtBaseArray &other) : m_handle(NULL)
    {
        init(allocator, other);
    }
    
    // Destructor    
    ~VrtBaseArray()
    {
        deinit();
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_array_create(allocator, valueTypeInfo);
    }
    
    void init(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_array_create(allocator, valueTypeInfo);
        vrt_array_assign_values(m_handle, values, sizeof(T), valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VrtBaseArray &other)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_array_create(allocator, valueTypeInfo);
        vrt_array_assign_array(m_handle, other.m_handle);        
    }

    void deinit()
    {
        vrt_array_release(m_handle);
        m_handle = NULL;
    }

// Method
public:
    vrt_size size() const
    {
        return vrt_array_get_size(m_handle);
    }

    void resize(vrt_u32 size)
    {
        vrt_array_resize(m_handle, size, NULL);
    }

    void resize(vrt_u32 size, const T &init_value)
    {
        vrt_array_resize(m_handle, size, &init_value);        
    }

    vrt_u32 capacity() const
    {
        return vrt_array_get_capacity(m_handle);
    }       

    bool empty() const
    {
        return vrt_array_get_size(m_handle) == 0;
    }

    void reserve(vrt_u32 size)
    {
        vrt_array_reserve(m_handle, size);
    }
    
    Ref at(vrt_u32 index) const
    {
        return *(T *)vrt_array_get_value(m_handle, index);
    }

    Ref front() const
    {
        return *(T *)vrt_array_get_value(m_handle, 0);
    }

    Ref back() const
    {
        return *(T *)vrt_array_get_value(m_handle, vrt_array_get_size(m_handle) - 1);
    }

    void assign(const T *values, vrt_u32 valueCount)
    {
        vrt_array_assign_values(m_handle, values, sizeof(T), valueCount);
    }

    void assign(vrt_u32 count, const T &x)
    {
        vrt_array_assign_values(m_handle, &x, 0, count);
    }

    void pushBack(const T &x)
    {
        vrt_array_insert(m_handle, vrt_array_get_size(m_handle), &x);
    }

    void popBack()
    {
        vrt_array_erase(m_handle, vrt_array_get_size(m_handle) - 1);
    }
        
    void insert(vrt_u32 position, const T &x)
    {
        vrt_array_insert(m_handle, position, &x);
    }

    void erase(vrt_u32 position)
    {
        vrt_array_erase(m_handle, position);
    }

    void clear()
    {
        vrt_array_clear(m_handle);
    }

// Operator
public:
    VrtBaseArray &operator = (const VrtBaseArray &other)
    {
        vrt_array_assign_array(m_handle, other.m_handle);
        return *this;
    }

    T &operator [] (vrt_u32 index) const
    {
        return at(index);
    }

// Method
public:
    // Internal used.
    vrt_array_handle getHandle() const
    {
        return m_handle;
    }

    T *getValues()
    {
        return (T *)vrt_array_get_values(m_handle);
    }

    const T *getValues() const
    {
        return (const T *)vrt_array_get_values(m_handle);
    }

// Implementation
private:
    // Disable default copy constructor, no implement
    explicit VrtBaseArray(const VrtBaseArray &other);

// Implementation
private:
    vrt_array_handle m_handle;
};

#endif /* __cplusplus */

#endif /* __VRT_BASE_ARRAY_H__ */

