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
 *  vfx_object_list.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Weak Pointer List
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_OBJECT_LIST_H__
#define __VFX_OBJECT_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxObjWeakPtr
#include "vfx_weak_ptr.h"

#include "vfx_datatype.h"
#include "vfx_object.h"


/***************************************************************************** 
 * define
 *****************************************************************************/

// Internal used. Object List magic number for a live instance.
#define VFX_OBJLIST_LIVE_MAGIC_NUMBER 'TSLO'
// Internal used. Object List magic number for a dead instance.
#define VFX_OBJLIST_DEAD_MAGIC_NUMBER 'tslo'


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxObject;
class VfxObjList;


/***************************************************************************** 
 * Class VfxObjListEntry
 *****************************************************************************/
 
/*
 * The entry of VfxObjList. Use VfxObjListEntry::get to get the object pointer.
 * And VfxObjListEntry::getPrev and VfxObjListEntry::getNext can access the 
 * previous and next enrty of object list.
 *
 * SEE ALSO: VfxObjList
 */
class VfxObjListEntry : public VfxBase
{
// Method    
public:
    // Return the pointer to object.
    // If the object has been closed, it will return NULL.
    //
    // RETURNS: Pointer to the object.
    VfxObject *get()
    {
        return m_objPtr.get();
    }
    
    // Return the constant pointer to object.
    // If the object has been closed, it will return NULL.
    //
    // RETURNS: Constant pointer to the object.
    const VfxObject *get() const
    {
        return m_objPtr.get();
    }
    

    // Check whether the object of the entry is valid.
    //
    // RETURNS: Return VFX_TRUE if the object is valid, 
    //  otherwise return VFX_FALSE.
    VfxBool isValid() const
    {
        return m_objPtr.isValid();
    }


    // Get the prevous entry
    //
    // RETURNS: Pointer to the previous entry.
    VfxObjListEntry *getPrev() const
    {
        return m_prev;
    }
    
    // Get the next entry
    //
    // RETURNS: Pointer to the next entry.
    VfxObjListEntry *getNext() const
    {
        return m_next;
    }

    // Get the prevous entry contains a valid object
    //
    // RETURNS: Pointer to the previous entry.
    VfxObjListEntry *getValidPrev() const;
    
    // Get the next entry contains a valid object
    //
    // RETURNS: Pointer to the next entry.
    VfxObjListEntry *getValidNext() const;
        
private:
    VfxU32 m_magicNumber;
    VfxObjWeakPtr m_objPtr;    
    VfxObjListEntry  *m_prev;
    VfxObjListEntry  *m_next;

    // Internal Used. Construct with specified object. It can only be created in VfxObjList.
    VfxObjListEntry(
        VfxObject *obj      // [IN] object to be inserted into object list.
    ) : 
        m_magicNumber(VFX_OBJLIST_LIVE_MAGIC_NUMBER), m_objPtr(obj), m_prev(NULL), m_next(NULL)
    {
    }

    ~VfxObjListEntry()
    {
        m_magicNumber = VFX_OBJLIST_DEAD_MAGIC_NUMBER;
    }
        
    friend class VfxObjList;
};


/***************************************************************************** 
 * Class VfxObjList
 *****************************************************************************/
 
/*
 * Object Weak Pointer List. Use VfxObjListEntry to iterator the list.
 *
 * SEE ALSO: VfxObjListEntry.
 */
class VfxObjList : public VfxBase
{
// Constructor / Destructor   
public:
    // Default constructor
    VfxObjList() : m_head(NULL), m_tail(NULL)
    {
    }
        
    // Copy constructor
    VfxObjList(
        const VfxObjList &other     // [IN] The other object list to be copied
    ) : 
        m_head(NULL), m_tail(NULL)
    {
        assignWith(other);
    }
    
    // Destructor
    ~VfxObjList()
    {
        clear();
    }

// Operator
public:
    // Assign operator
    VfxObjList &operator = (
        const VfxObjList &other     // [IN] The other object list to be copied
    );

// Method    
public:
    // Swap with other object list
    void swap(
        VfxObjList &other           // [IN] The other object list to be swapped
    )
    {
        vfxSwap(m_head, other.m_head);
        vfxSwap(m_tail, other.m_tail);
    }

    
    // Return the first entry
    //
    // RETURNS: The first entry. Return NULL if the list is emptry.
    VfxObjListEntry *getHead() const
    {
        return m_head;
    }
    
    // Return the last entry
    //
    // RETURNS: The last entry. Return NULL if the list is emptry.
    VfxObjListEntry *getTail() const
    {
        return m_tail;
    }


    // Return the first entry contains a valid object.
    //
    // RETURNS: The first entry contains a valid object. Return NULL if
    //  there is no valid object.
    VfxObjListEntry *getValidHead() const;
    
    // Return the last entry contains a valid object.
    //
    // RETURNS: The last entry contains a valid object. Return NULL if
    //  there is no valid object.
    VfxObjListEntry *getValidTail() const;


    // Check whether the object list is empty.
    //
    // RETURNS: Return VFX_TRUE if the 
    VfxBool isEmpty() const
    {
        return m_head == NULL;
    }

    // Caculate the number of entries of the object list.
    //
    // RETURNS: The number of entries.
    //
    // SEE ALSO: getEntryCount
    VfxU32 getEntryCount() const;

    // Caculate the number of entries contain a valid object.
    //
    // RETURNS: The number of entries.
    //
    // SEE ALSO: getEntryCount
    VfxU32 getValidCount() const;

    // Return the object pointer of the first entry.
    //
    // RETURNS: The object pointer of the first entry. Return NULL if 
    //  the object list is emptry, or the object is closed.
    VfxObject *getFirst() const
    {
        return m_head->m_objPtr.get();
    }
    
    // Return the object pointer of the last entry.
    //
    // RETURNS: The object pointer of the last entry. Return NULL if 
    //  the object list is emptry, or the object is closed.
    VfxObject *getLast() const
    {
        return m_tail->m_objPtr.get();
    }

    // Return the object list whether contains the given object
    //
    // RETURNS: Return VFX_TRUE if the object list contains the given object. 
    //  Otherwise, return VFX_FALSE.
    VfxBool contains(
        VfxObject *obj              // [IN] The object to be test
    ) const;

    // Append an object to the tail of the list.
    //
    // RETURNS: The new entry appended
    VfxObjListEntry *append(
        VfxObject *obj              // [IN] The object to be append.
    );

    // Append an object to the head of the list.
    //
    // RETURNS: The new entry appended
    VfxObjListEntry *prepend(
        VfxObject *obj              // [IN] The object to be append.
    );

    // Insert an object after a given entry position.
    //
    // RETURNS: The new entry inserted
    VfxObjListEntry *insertBefore(
        VfxObjListEntry *entry,     // [IN] The entry position to be inserted
        VfxObject *obj              // [IN] The object to be inserted
    );
    
    // Insert an object before a given entry position.
    //
    // RETURNS: The new entry inserted
    VfxObjListEntry *insertAfter(
        VfxObjListEntry *entry,     // [IN] The entry position to be inserted 
        VfxObject *obj              // [IN] The object to be inserted
    );


    // Remove the entry of the given entry position.
    //
    // NOTE: Given entry will be deleted and do not access any more.
    void removePos(
        VfxObjListEntry *entry      // [IN] The entry poisiton to be removed
    );

    // Search the first entry pointer to the given object and remove it.
    //
    // RETURNS: Return VFX_TRUE if remove an entry. Otherwise, return VFX_FALSE.
    VfxBool removeOne(
        VfxObject *obj              // [IN] The object to be remove from the object list
    );
    
    // Search the all entryies pointer to the given object and remove them.
    //
    // RETURNS: Return the number of entry has been removed.
    VfxU32 removeAll(
        VfxObject *obj              // [IN] The object to be remove from the object list
    );

    // Search the all entryies pointer to invalidate object and remove them.
    void removeAllInvalidate();
    
    // Clear all entris of the object list.
    void clear();

// Implementation
private:
    VfxObjListEntry *m_head;
    VfxObjListEntry *m_tail;

    void assignWith(const VfxObjList &other);
};
    

#endif /* __VFX_OBJECT_LIST_H__ */

