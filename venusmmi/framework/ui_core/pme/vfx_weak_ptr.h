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
 *  VfxWeakPtr.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_WEAK_PTR_H__
#define __VFX_WEAK_PTR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxObject
#include "vfx_object.h"

#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_sys_memory.h"

/***************************************************************************** 
 * define
 *****************************************************************************/

// Internal used. Weak Pointer magic number for a live instance.
#define VFX_WEAK_LIVE_MAGIC_NUMBER 'KAEW'
// Internal used. Weak Pointer magic number for a dead instance.
#define VFX_WEAK_DEAD_MAGIC_NUMBER 'kaew'


/***************************************************************************** 
 * Class VfxWeakPtrFlag
 *****************************************************************************/

// Internal used. 
// VfxWeakPtrFlag is an internal class which holds information for object's valid status.
class VfxWeakPtrFlag : public VfxBase
{
public:
    static VfxWeakPtrFlag *createFlag(VfxObject *objPtr);

public:
    explicit VfxWeakPtrFlag(VfxObject *objPtr) :
        m_magicNumber(VFX_WEAK_LIVE_MAGIC_NUMBER), m_objPtr(objPtr), m_refCnt(0)
    {
        VFX_DEV_ASSERT(m_objPtr != NULL);
    }

    ~VfxWeakPtrFlag()
    {
        m_magicNumber= VFX_WEAK_DEAD_MAGIC_NUMBER;
    }

    VfxObject *getObjPtr() const
    {
        return m_objPtr;
    }

    VfxWeakPtrFlag *addRef();
    void decRef();

    void invalidate();
    
// Implmenent 
private:
	VfxU32 m_magicNumber;
    VfxObject *m_objPtr;
    VfxS32 m_refCnt;
};


inline
VfxWeakPtrFlag *VfxWeakPtrFlag::createFlag(VfxObject *objPtr)
{
    VfxWeakPtrFlag *ret;
    VFX_SYS_NEW_EX(ret, VfxWeakPtrFlag, (objPtr));
    return ret;
}


inline
VfxWeakPtrFlag *VfxWeakPtrFlag::addRef()
{
    vfx_sys_acquire_weak_obj_hdl_lock();
    m_refCnt++;
    vfx_sys_release_weak_obj_hdl_lock();

    return this;
}


inline
void VfxWeakPtrFlag::decRef()
{
    VFX_DEV_ASSERT(m_refCnt > 0);

    vfx_sys_acquire_weak_obj_hdl_lock();
    m_refCnt--;
    if (m_refCnt == 0)
    {
        if (m_objPtr != NULL)
        {
            m_objPtr->resetWeakPtrFlag();
        }
        
        VfxWeakPtrFlag *self = this;
        VFX_SYS_DELETE(self);
    }
    vfx_sys_release_weak_obj_hdl_lock();
}


inline
void VfxWeakPtrFlag::invalidate()
{
    VFX_DEV_ASSERT(m_objPtr != NULL);
    m_objPtr = NULL;
}


/***************************************************************************** 
 * Template VfxWeakPtr
 *****************************************************************************/

/*
 * VfxWeakPtr is a template class provide the weak pointer. The pointer must
 *  pointer to a VfxObject.
 */
template <class _objType>
class VfxWeakPtr : public VfxBase
{
// Constructor / Destructor
public:
    // Default constructor.
    VfxWeakPtr() : m_flagPtr(NULL)
    {
    }

    // Construct with a pointer.
    //
    // NOTE: The pointer must pointer a valid object or NULL.
    VfxWeakPtr(_objType *objPtr);

    // Copy constructor.
    VfxWeakPtr(const VfxWeakPtr &other);

    // Destructor
    ~VfxWeakPtr()
    {
        clearFlag();
    }

// Operator
public:
    // Assigned with a pointer.
    //
    // NOTE: The pointer must pointer a valid object or NULL.
    //
    // RETURNS: Reference to the weak pointer.
    VfxWeakPtr &operator =(_objType *objPtr);

    
    // Assigned with another weak pointer
    //
    // RETURNS: Reference to the weak pointer.
    VfxWeakPtr &operator =(const VfxWeakPtr &other);

    // Compared with a pointer.
    //
    // RETURNS: Return VFX_TRUE the pointer is equal to the other.    
    VfxBool operator ==(const _objType *objPtr) const
    {
        return get() == objPtr;
    }
    
    // Compared with another weak pointer.
    //
    // RETURNS: Return VFX_TRUE the pointer is equal to the other.    
    VfxBool operator ==(const VfxWeakPtr &other) const
    {
        return get() == other.get();
    }
    
    // Compared with a pointer.
    //
    // RETURNS: Return VFX_TRUE the pointer is *NOT* equal to the other.    
    VfxBool operator !=(const _objType *objPtr) const
    {
        return get() != objPtr;
    }
    
    // Compared with another weak pointer.
    //
    // RETURNS: Return VFX_TRUE the pointer is *NOT* equal to the other.    
    VfxBool operator !=(const VfxWeakPtr &other) const
    {
        return get() != other.get();
    }

// TODO: Disabled because a linker bug of ASD 
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Member by pointer operator.
    //
    // NOTE: You must make sure the pointer of the weak pointer is valid.
    //
    // RETURNS: The pointer of the weak pointer.
    _objType *operator ->() const
    {
        //VFX_ASSERT(isValid());
        return (_objType *)m_flagPtr->getObjPtr();
    }
    
// Method
public:
    // Return the pointer of the weak pointer. 
    //
    // RETURNS: The pointer of the weak pointer. If the pointer is invalid,
    //  returns NULL.
    _objType *get() const
    {
        return m_flagPtr ? (_objType *)m_flagPtr->getObjPtr() : NULL;
    }

    // Whether the pointer of the weak pointer is valid.
    //
    // RETURNS: Return VFX_TRUE if the pointer is valid. Otherwise, return VFX_FALSE.
    VfxBool isValid() const
    {
        return m_flagPtr ? (m_flagPtr->getObjPtr() != NULL) : VFX_FALSE;
    }

// Implemetation
private:
    // The validity flag of the object
    VfxWeakPtrFlag *m_flagPtr;

    void clearFlag();
};


template <class _objType>
VfxWeakPtr <_objType>::VfxWeakPtr(_objType *objPtr) :
    m_flagPtr(NULL)
{
    if (objPtr != NULL)
    {
        m_flagPtr = objPtr->getWeakPtrFlag()->addRef();
    }
}


template <class _objType>
VfxWeakPtr <_objType>::VfxWeakPtr(const VfxWeakPtr &other) : m_flagPtr(NULL)
{
    if (other.m_flagPtr != NULL)
    {
        m_flagPtr = other.m_flagPtr->addRef();
    }
}


template <class _objType>
VfxWeakPtr <_objType> &VfxWeakPtr <_objType>::operator =(_objType *objPtr)
{
    clearFlag();
    
    if (objPtr != NULL)
    {
        m_flagPtr = objPtr->getWeakPtrFlag()->addRef();
    }

    return *this;
}


template <class _objType>
VfxWeakPtr <_objType> &VfxWeakPtr <_objType>::operator =(const VfxWeakPtr &other)
{
    clearFlag();

    if (other.m_flagPtr != NULL)
    {
        m_flagPtr = other.m_flagPtr->addRef();
    }
    
    return *this;
}


template <class _objType>
void VfxWeakPtr <_objType>::clearFlag()
{
    if (m_flagPtr != NULL)
    {
        m_flagPtr->decRef();

        m_flagPtr = NULL;
    }    
}


// Weak Pointer to VfxObject
typedef VfxWeakPtr <VfxObject> VfxObjWeakPtr;


#endif /* __VFX_WEAK_PTR_H__ */

