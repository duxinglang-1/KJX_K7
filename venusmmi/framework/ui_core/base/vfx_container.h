/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vfx_container.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Container Classes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_CONTAINER_H__
#define __VFX_CONTAINER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For IVfxAllocatable and VfxBase
#include "vfx_cpp_base.h"
// For VrtBaseList
#include "vrt_base_list.h"
// For VrtBaseArray
#include "vrt_base_array.h"
// For VrtBaseMap
#include "vrt_base_map.h"
// For VrtBaseString, VrtBaseWString
#include "vrt_base_string.h"


/***************************************************************************** 
 * Include
 *****************************************************************************/

template <
    class T, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info
    >
class VfxArray : 
    public VfxBase, 
    public VrtBaseArray <T, valueTypeInfo>
{
// Constructor / Destructor
public:
    // Default constructor
    VfxArray()
    {
    }
    
    // Default constructor
    explicit VfxArray(vrt_allocator_handle allocator) :
        VrtBaseArray <T, valueTypeInfo> (allocator)
    {
    }
    
    // Default constructor
    explicit VfxArray(IVfxAllocatable *owner) : 
        VrtBaseArray <T, valueTypeInfo> (owner->getAllocator())
    {
    }

    // Construct with values
    VfxArray(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount) : 
        VrtBaseArray <T, valueTypeInfo> (owner->getAllocator(), values, valueCount)
    {
    }
    
    // Copy constructor
    VfxArray(IVfxAllocatable *owner, const VfxArray &other) : 
        VrtBaseArray <T, valueTypeInfo> (owner->getAllocator(), other)
    {
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VrtBaseArray <T, valueTypeInfo>::init(allocator);
    }
    
    void init(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount)
    {
        VrtBaseArray <T, valueTypeInfo>::init(allocator, values, valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VfxArray &other)
    {
        VrtBaseArray <T, valueTypeInfo>::init(allocator, other);
    }
    
    void init(IVfxAllocatable *owner)
    {
        VrtBaseArray <T, valueTypeInfo>::init(owner->getAllocator());
    }
    
    void init(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount)
    {
        VrtBaseArray <T, valueTypeInfo>::init(owner->getAllocator(), values, valueCount);
    }
    
    void init(IVfxAllocatable *owner, const VfxArray &other)
    {
        VrtBaseArray <T, valueTypeInfo>::init(owner->getAllocator(), other);
    }    
};


/***************************************************************************** 
 * Template Class VrtList
 *****************************************************************************/

template <
    class T, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info
    >
class VfxList : 
    public VfxBase, 
    public VrtBaseList <T, valueTypeInfo>
{
// Constructor / Destructor
public:
    // Default constructor
    VfxList()
    {
    }
    
    // Default constructor
    explicit VfxList(vrt_allocator_handle allocator) :
        VrtBaseList <T, valueTypeInfo> (allocator)
    {
    }
    
    // Default constructor
    explicit VfxList(IVfxAllocatable *owner) : 
        VrtBaseList <T, valueTypeInfo> (owner->getAllocator())
    {
    }

    // Construct with values
    VfxList(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount) : 
        VrtBaseList <T, valueTypeInfo> (owner->getAllocator(), values, valueCount)
    {
    }
    
    // Copy constructor
    VfxList(IVfxAllocatable *owner, const VfxList &other) : 
        VrtBaseList <T, valueTypeInfo> (owner->getAllocator(), other)
    {
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VrtBaseList <T, valueTypeInfo>::init(allocator);
    }
    
    void init(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount)
    {
        VrtBaseList <T, valueTypeInfo>::init(allocator, values, valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VfxList &other)
    {
        VrtBaseList <T, valueTypeInfo>::init(allocator, other);
    }    

    void init(IVfxAllocatable *owner)
    {
        VrtBaseList <T, valueTypeInfo>::init(owner->getAllocator());
    }
    
    void init(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount)
    {
        VrtBaseList <T, valueTypeInfo>::init(owner->getAllocator(), values, valueCount);
    }
    
    void init(IVfxAllocatable *owner, const VfxList &other)
    {
        VrtBaseList <T, valueTypeInfo>::init(owner->getAllocator(), other);
    }    
};


/***************************************************************************** 
 * Template Class VfxMap
 *****************************************************************************/

template <
    class Key, 
    class T, 
    vrt_type_info_compare_funcptr_type compareFunc = VrtTypeInfo <Key>::compare, 
    const vrt_type_info_struct *keyTypeInfo = &VrtTypeInfo <Key>::s_info, 
    const vrt_type_info_struct *valueTypeInfo = &VrtTypeInfo <T>::s_info 
    >
class VfxMap : 
    public VfxBase, 
    public VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>
{
// Constructor / Destructor
public:
    // Default constructor
    VfxMap()
    {
    }
    
    // Default constructor
    explicit VfxMap(vrt_allocator_handle allocator) :
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo> (allocator)
    {
    }
    
    // Default constructor
    explicit VfxMap(IVfxAllocatable *owner) : 
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo> (owner->getAllocator())
    {
    }

    // Construct with values
    VfxMap(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount) : 
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo> (owner->getAllocator(), values, valueCount)
    {
    }
    
    // Copy constructor
    VfxMap(IVfxAllocatable *owner, const VfxMap &other) : 
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo> (owner->getAllocator(), other)
    {
    }

// Method
public:
    void init(vrt_allocator_handle allocator)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(allocator);
    }
    
    void init(vrt_allocator_handle allocator, const T *values, vrt_u32 valueCount)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(allocator, values, valueCount);
    }
    
    void init(vrt_allocator_handle allocator, const VfxMap &other)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(allocator, other);
    }   

    void init(IVfxAllocatable *owner)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(owner->getAllocator());
    }
    
    void init(IVfxAllocatable *owner, const T *values, vrt_u32 valueCount)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(owner->getAllocator(), values, valueCount);
    }
    
    void init(IVfxAllocatable *owner, const VfxMap &other)
    {
        VrtBaseMap <Key, T, compareFunc, keyTypeInfo, valueTypeInfo>::init(owner->getAllocator(), other);
    }    
};

#endif /* __VFX_CONTAINER_H__ */

