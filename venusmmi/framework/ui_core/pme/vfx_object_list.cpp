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
 *  vfx_object_list.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_object_list.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_datatype.h"


/***************************************************************************** 
 * Class VfxObjListEntry
 *****************************************************************************/
 
VfxObjListEntry *VfxObjListEntry::getValidPrev() const
{
    VfxObjListEntry *i;
    for (i = m_prev; i != NULL; i = i->m_prev)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VfxObjListEntry *VfxObjListEntry::getValidNext() const
{
    VfxObjListEntry *i;
    for (i = m_next; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VfxObjListEntry *VfxObjList::getValidHead() const
{
    VfxObjListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


VfxObjListEntry *VfxObjList::getValidTail() const
{
    VfxObjListEntry *i;
    for (i = m_tail; i != NULL; i = i->m_prev)
    {
        if (i->isValid())
        {
            break;
        }
    }
    return i;
}


/***************************************************************************** 
 * Class VfxObjList
 *****************************************************************************/
 
VfxObjList &VfxObjList::operator =(
    const VfxObjList &other     // [IN] The other object list to be copied
)
{
    clear();
    assignWith(other);
    return *this;
}


VfxU32 VfxObjList::getEntryCount() const
{
    VfxU32 count = 0;
    VfxObjListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        count++;
    }
    return count;
}


VfxU32 VfxObjList::getValidCount() const
{
    VfxU32 count = 0;
    VfxObjListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->isValid())
        {
            count++;
        }
    }
    return count;
}


VfxBool VfxObjList::contains(VfxObject *obj) const
{
    VFX_OBJ_ASSERT_VALID(obj);
    
    VfxObjListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->m_objPtr == obj)
        {
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxObjListEntry *VfxObjList::append(VfxObject *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);

    // Cerate a new list entry
    VfxObjListEntry *newEntry;
    VFX_SYS_NEW_EX(newEntry, VfxObjListEntry, (obj));
    
    // Let it be the first newEntry if list is empty
    if (m_head == NULL)
    {
        m_head = newEntry;
    }
    
    // Add to the tail of the list
    newEntry->m_next = NULL;
    newEntry->m_prev = m_tail;
    if (m_tail != NULL)
    {
        m_tail->m_next = newEntry;
    }
    m_tail = newEntry;

    return newEntry;
}


VfxObjListEntry *VfxObjList::prepend(VfxObject *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);

    // Cerate a new list entry
    VfxObjListEntry *newEntry;
    VFX_SYS_NEW_EX(newEntry, VfxObjListEntry, (obj));
    
    // Let it be the last newEntry if list is empty
    if (m_tail == NULL)
    {
        m_tail = newEntry;
    }
    
    // Add to the front of the list
    newEntry->m_next = m_head;
    newEntry->m_prev = NULL;
    if (m_head != NULL)
    {
        m_head->m_prev = newEntry;
    }
    m_head = newEntry;

    return newEntry;
}


VfxObjListEntry *VfxObjList::insertBefore(VfxObjListEntry *entry, VfxObject *obj)
{
    VFX_ASSERT(entry != NULL);
    VFX_OBJ_ASSERT_VALID(obj);

    // Cerate a new list entry
    VfxObjListEntry *newEntry;
    VFX_SYS_NEW_EX(newEntry, VfxObjListEntry, (obj));
    newEntry->m_prev = entry->m_prev;
    newEntry->m_next = entry;
    
    if (entry->m_prev != NULL)
    {
        entry->m_prev->m_next = newEntry;
    }
    else
    {
        m_head = newEntry;
    }
    entry->m_prev = newEntry;

    return newEntry;
}


VfxObjListEntry *VfxObjList::insertAfter(VfxObjListEntry *entry, VfxObject *obj)
{
    VFX_ASSERT(entry != NULL);
    VFX_OBJ_ASSERT_VALID(obj);

    // Cerate a new list entry
    VfxObjListEntry *newEntry;
    VFX_SYS_NEW_EX(newEntry, VfxObjListEntry, (obj));
    newEntry->m_prev = entry;
    newEntry->m_next = entry->m_next;
    
    if (entry->m_next != NULL)
    {
        entry->m_next->m_prev = newEntry;
    }
    else
    {
        m_tail = newEntry;
    }    
    entry->m_next = newEntry;

    return newEntry;
}


void VfxObjList::removePos(VfxObjListEntry *entry)
{
    VFX_ASSERT(entry != NULL);
    
    if (entry->m_prev != NULL)
    {
        entry->m_prev->m_next = entry->m_next;
    }
    else
    {
        VFX_ASSERT(m_head == entry);
        m_head = entry->m_next;
    }

    if (entry->m_next != NULL)
    {
        entry->m_next->m_prev = entry->m_prev;
    }
    else
    {
        VFX_ASSERT(m_tail == entry);
        m_tail = entry->m_prev;
    }

    entry->m_prev = NULL;
    entry->m_next = NULL;
    
    VFX_SYS_DELETE(entry);
}


VfxBool VfxObjList::removeOne(VfxObject *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);
    
    VfxObjListEntry *i;
    for (i = m_head; i != NULL; i = i->m_next)
    {
        if (i->m_objPtr == obj)
        {
            removePos(i);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxU32 VfxObjList::removeAll(VfxObject *obj)
{
    VFX_OBJ_ASSERT_VALID(obj);

    VfxU32 remove_count = 0;
    VfxObjListEntry *i = m_head;
    while (i != NULL)
    {
        VfxObjListEntry *next = i->m_next;
        
        if (i->m_objPtr == obj)
        {
            removePos(i);
            remove_count++;
        }
        
        i = next;
    }
    return remove_count;
}


void VfxObjList::removeAllInvalidate()
{
    VfxObjListEntry *i = m_head;
    while (i != NULL)
    {
        VfxObjListEntry *next = i->m_next;
        
        if (!i->m_objPtr.isValid())
        {
            removePos(i);
        }
        i = next;
    }
}


void VfxObjList::clear()
{
    VfxObjListEntry *i = m_head;
    while (i != NULL)
    {
        VfxObjListEntry *next = i->m_next;
        
        VFX_SYS_DELETE(i);

        i = next;
    }
    
    m_head = NULL;
    m_tail = NULL;
}


void VfxObjList::assignWith(const VfxObjList &other)
{
    // Must be empty list
    VRT_DEV_ASSERT(m_head == NULL && m_tail == NULL);

    // TODO: revise this code to optimize        
    VfxObjListEntry *i;
    for (i = other.m_head; i != NULL; i = i->m_next)
    {
        VfxObjListEntry *entry;
        VFX_SYS_NEW_EX(entry, VfxObjListEntry, (i->m_objPtr.get()));

        // Let it be the first entry if list is empty
        if (m_head == NULL)
        {
            m_head = entry;
        }
        
        // Add to the tail of the list
        entry->m_next = NULL;
        entry->m_prev = m_tail;
        if (m_tail != NULL)
        {
            m_tail->m_next = entry;
        }
        m_tail = entry;
    }
}

