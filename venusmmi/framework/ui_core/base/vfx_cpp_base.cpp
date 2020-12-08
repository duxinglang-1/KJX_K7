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
 *  vfx_cpp_base.cpp
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
 
#include "vfx_cpp_base.h"
// For vrt_allocator_xxx()
#include "vrt_base_allocator.h"
// For vfx_sys_mem_get_global_allocator()
#include "vfx_sys_mem_config.h"

#include <wchar.h>
#include "vfx_datatype.h"


/***************************************************************************** 
 * Class IVfxAllocatable
 *****************************************************************************/

vrt_allocator_handle IVfxAllocatable::getAllocator()
{
    // NOTE: Assert here if forget to override this function
    VFX_ASSERT(0);
    return NULL;
}


VfxU32 IVfxAllocatable::_getId() const
{
    return 0;
}


/***************************************************************************** 
 * Class VfxBase
 *****************************************************************************/

void *VfxBase::allocSysMemory(size_t size)
{
    const VfxChar *filename;
    VfxU32 line;
    vrt_allocator_handle allocator = vfx_sys_mem_get_global_allocator();
    VFX_DEV_ASSERT(allocator != NULL);

    VFX_MEM_FILL_FILENAME(filename, line);
    return vrt_allocator_alloc_int(allocator, size, VRT_ALLOCATOR_ALLOC_FLAG_NONE, filename, line);
}


void *VfxBase::allocSysMemory(size_t size, const char *file, VfxU32 line)
{
    vrt_allocator_handle allocator = vfx_sys_mem_get_global_allocator();
    VFX_DEV_ASSERT(allocator != NULL);
    
    return vrt_allocator_alloc_int(allocator, size, VRT_ALLOCATOR_ALLOC_FLAG_NONE, file, line);
}


void VfxBase::freeSysMemory(void *ptr)
{
    vrt_allocator_free(ptr);
}


void *VfxBase::operator new (size_t size)
{
    return allocSysMemory(size);
}


void VfxBase::operator delete (void *ptr)
{
    freeSysMemory(ptr);
}


void *VfxBase::operator new (size_t size, IVfxAllocatable *allocatable, const char *file, VfxU32 line)
{
    //Note: If AP pass NULL allocatable, will get assert here.
    if (allocatable == NULL)
    {
        VFX_ASSERT(0);
    }

    return vrt_allocator_alloc_int(
        allocatable->getAllocator(), 
        size, 
        VRT_ALLOCATOR_ALLOC_FLAG_NONE,
        file,
        line);
}

void *VfxBase::operator new (size_t size, vrt_allocator_handle allocator, const char *file, VfxU32 line)
{
    //Note: If AP pass NULL allocator, will get assert here.
    if (allocator == NULL)
    {
        VFX_ASSERT(0);
    }

    return vrt_allocator_alloc_int(
        allocator, 
        size, 
        VRT_ALLOCATOR_ALLOC_FLAG_NONE,
        file,
        line);
}


void *VfxBase::operator new (size_t size, vrt_allocator_handle allocator, void *buf)
{
    if (buf == NULL)
    {
        return buf;
    }

    *(vrt_allocator_handle *)buf = allocator;
    return (VfxU8 *)buf + sizeof(vrt_allocator_handle);
}


void *VfxBase::operator new (size_t size, IVfxAllocatable *allocatable)
{
    if (allocatable == NULL)
    {
        VFX_ASSERT(0);
    }

    return vrt_allocator_alloc_int(
        allocatable->getAllocator(), 
        size, 
        VRT_ALLOCATOR_ALLOC_FLAG_NONE,
        NULL,
        0);        
}

