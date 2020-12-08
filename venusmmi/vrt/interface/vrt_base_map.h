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
 *  vrt_base_map.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Map Container
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

#ifndef __VRT_BASE_MAP_H__
#define __VRT_BASE_MAP_H__

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

typedef struct vrt_map_entry_struct *vrt_map_entry_handle; 
typedef struct vrt_map_struct *vrt_map_handle; 


/***************************************************************************** 
 * Global function
 *****************************************************************************/

extern vrt_map_handle vrt_map_create(
    vrt_allocator_handle allocator,
    vrt_type_info_compare_funcptr_type key_compare_func,
    const vrt_type_info_struct *key_callbacks,
    const vrt_type_info_struct *value_callbacks
    );

extern void vrt_map_release(
    vrt_map_handle map
    );

extern void vrt_map_assign_values(
    vrt_map_handle map,
    const void *keys_buf,
    vrt_u32 keys_pitch_bytes,
    const void *values_buf,
    vrt_u32 value_pitch_bytes,
    vrt_u32 count
    );   

extern void vrt_map_assign_map(
    vrt_map_handle map,
    const vrt_map_handle other_map
    );

extern vrt_size vrt_map_get_size(
    vrt_map_handle map
    );

extern vrt_map_entry_handle vrt_map_insert(
    vrt_map_handle map,
    const void *key,
    const void *value
    );

extern void vrt_map_erase(
    vrt_map_handle map,
    vrt_map_entry_handle pos);

extern void vrt_map_clear(
    vrt_map_handle map
    );

extern vrt_map_entry_handle vrt_map_find(
    vrt_map_handle map,
    const void *key
    );

extern vrt_map_entry_handle vrt_map_get_head(
    vrt_map_handle map
    );

extern vrt_map_entry_handle vrt_map_get_tail(
    vrt_map_handle map
    );

extern const void *vrt_map_entry_get_key(
    vrt_map_entry_handle entry
    );

extern void *vrt_map_entry_get_value(
    vrt_map_entry_handle entry
    );

extern vrt_map_entry_handle vrt_map_entry_get_prev(
    vrt_map_entry_handle entry
    );

extern vrt_map_entry_handle vrt_map_entry_get_next(
    vrt_map_entry_handle entry
    );

#ifdef __cplusplus
} /* extern "C" */
#endif


#ifdef __cplusplus

/***************************************************************************** 
 * Template VrtBaseMapIt
 *****************************************************************************/

template <class Key, class T>
class VrtBaseMapIt
{
// Constructor / Destructor
public:
    // Default constructor
    VrtBaseMapIt() : m_handle(NULL)
    {
    }

    explicit VrtBaseMapIt(vrt_map_entry_handle handle) : m_handle(handle)
    {
    }

    // Copy constructor
    VrtBaseMapIt(const VrtBaseMapIt &other) : m_handle(other.m_handle)
    {
    }

// Operator    
public:
    bool operator == (const VrtBaseMapIt &other) const 
    { 
        return m_handle == other.m_handle; 
    }
      
    bool operator != (const VrtBaseMapIt &other) const 
    { 
        return m_handle != other.m_handle; 
    }

    VrtBaseMapIt &operator ++ ()
    {
        m_handle = vrt_map_entry_get_next(m_handle);
        return *this;
    }
    
    VrtBaseMapIt operator ++ (int)
    {
        vrt_map_entry_handle oldHandle = m_handle;
        m_handle = vrt_map_entry_get_next(m_handle);
        return VrtBaseMapIt(oldHandle);
    }
    
    VrtBaseMapIt &operator -- ()
    {
        m_handle = vrt_map_entry_get_prev(m_handle);
        return *this;
    }
    
    VrtBaseMapIt operator -- (int)
    {
        vrt_map_entry_handle oldHandle = m_handle;
        m_handle = vrt_map_entry_get_prev(m_handle);
        return VrtBaseMapIt(oldHandle);
    }

// Method
public:
    bool isNull() const
    {
        return m_handle == NULL;
    }        

    const Key &getKey() const
    {
        return *(Key *)vrt_map_entry_get_key(m_handle);
    }

    T &getValue() const
    {
        return *(T *)vrt_map_entry_get_value(m_handle);
    }

    // Internal used.
    vrt_map_entry_handle getHandle() const
    {
        return m_handle;
    }
    
private:
    vrt_map_entry_handle m_handle;
};


/***************************************************************************** 
 * Template VrtBaseMap
 *****************************************************************************/

template <
    class Key, 
    class T, 
    vrt_type_info_compare_funcptr_type compareFunc = VrtTypeInfo <Key>::compare, 
    const vrt_type_info_struct *keyTypeInfo = &VrtTypeInfo <Key>::s_info, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info 
    >
class VrtBaseMap
{
public:
    typedef VrtBaseMapIt <Key, T> It;
    typedef VrtBaseMapIt <const Key, const T> ConstIt;
    
// Constructor / Destructor
public:
    // Default constructor
    VrtBaseMap() : m_handle(NULL)
    {
    }

    // Default constructor
    explicit VrtBaseMap(vrt_allocator_handle allocator) : m_handle(NULL)
    {
        init(allocator);
    }
    
    // Construct with values
    VrtBaseMap(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount) : m_handle(NULL)
    {
        init(allocator, values, valueCount);
    }
    
    // Copy constructor
    VrtBaseMap(vrt_allocator_handle allocator, const VrtBaseMap &other) : m_handle(NULL)
    {
        init(allocator, other);
    }
    
    // Destructor    
    ~VrtBaseMap()
    {
        deinit();
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_map_create(allocator, compareFunc, keyTypeInfo, valueTypeInfo);
    }
    
    void init(vrt_allocator_handle allocator, const T *keys, const T *values, vrt_u32 valueCount)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_map_create(allocator, compareFunc, keyTypeInfo, valueTypeInfo);
        vrt_map_assign_values(m_handle, keys, sizeof(Key), values, sizeof(T), valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VrtBaseMap &other)
    {
        VRT_DEV_ASSERT(m_handle == NULL);
        m_handle = vrt_map_create(allocator, compareFunc, keyTypeInfo, valueTypeInfo);
        vrt_map_assign_map(m_handle, other.m_handle);
    }

    void deinit()
    {
        vrt_map_release(m_handle);
        m_handle = NULL;
    }

    It begin()
    {
        return It(vrt_map_get_head(m_handle));
    }

    ConstIt begin() const
    {
        return ConstIt(vrt_map_get_head(m_handle));
    }

    It end()
    {
        return It();
    }

    ConstIt end() const
    {
        return ConstIt();
    }

    bool empty() const
    {
        return vrt_map_get_size(m_handle) == 0;
    }

    vrt_size size() const
    {
        return vrt_map_get_size(m_handle) == 0;
    }

    It insert(const Key &key, const T &value)
    {
        return It(vrt_map_insert(m_handle, &key, &value));
    }

    void erase(It position)
    {
        vrt_map_erase(m_handle, position.getHandle());
    }

    vrt_bool erase(const Key &key)
    {
        vrt_map_entry_handle entry = vrt_map_find(m_handle, &key);
        vrt_map_erase(m_handle, entry);
        return entry != NULL;
    }
    
    void clear()
    {
        vrt_map_clear(m_handle);
    }

    It find(const Key &key)
    {
        return It(vrt_map_find(m_handle, &key));
    }

    ConstIt find(const Key &key) const
    {
        return ConstIt(vrt_map_find(m_handle, &key));
    }

// Operator
public:
    // Assigne operator
    VrtBaseMap &operator = (const VrtBaseMap &other)
    {
        vrt_map_assign_map(m_handle, other,m_handle);
        return *this;
    }

    T& operator [] (const Key &key)
    {
        return *(T *)vrt_map_entry_get_value(vrt_map_insert(m_handle, &key, NULL));
    }    

// Method
public:
    // Internal used.
    vrt_map_handle getHandle() const
    {
        return m_handle;
    }

// Implementation
private:
    // Disable default copy constructor, no implement
    explicit VrtBaseMap(const VrtBaseMap &other);

// Implementation
private:
    vrt_map_handle m_handle;
};

#endif /* __cplusplus */

#endif /* __VRT_ARRAY_H__ */

