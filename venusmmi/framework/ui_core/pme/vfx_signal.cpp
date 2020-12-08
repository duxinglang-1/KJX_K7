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
 *  vfx_signal.cpp
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
 *  A functor may terminate the call sequence by call vfxStopEmit().
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vfx_signal.h"

// For vfxPostInvoke()
#include "vfx_async_signal.h"

#include "vfx_cpp_base.h"
#include "vfx_weak_ptr.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"


/*****************************************************************************
 * Class VfxEmitFrame
 *****************************************************************************/

/*
 *  VfxEmitFrame is a emit stack object. The current running emit loop in stack 
 *   will be handled by this object. 
 */
class VfxEmitFrame : public VfxBase
{
    static VfxEmitFrame *s_pEmitFrameList;
public:
    // Constructor / Distructor
    VfxEmitFrame() : stop(VFX_FALSE), prev(NULL)
    {
    }

// Method
public:
    // Enter this emit stack frame
    void enter()
    {
        prev = s_pEmitFrameList;
        s_pEmitFrameList = this;
    }

    // Leave this emit stack frame
    void leave()
    {
        VFX_ASSERT(s_pEmitFrameList == this);
        s_pEmitFrameList = prev;
    }

    // Stop emit loop
    static void stopEmit()
    {
        VFX_ASSERT(s_pEmitFrameList);
        s_pEmitFrameList->stop = VFX_TRUE;
    }

// Variable
public:
    // whether this emit loop should be stop
    VfxBool         stop;
    // The previous emit frame for pop
    VfxEmitFrame    *prev;
};


VfxEmitFrame* VfxEmitFrame::s_pEmitFrameList = NULL;


void vfxStopEmit()
{
    VfxEmitFrame::stopEmit();
}


/*****************************************************************************
 * Class VfxPostEmitData
 *****************************************************************************/

class VfxPostEmitData : public VfxBase
{
public:
    VfxPostEmitData() {}

    VfxSlotList                 slots;
    VfxEmitEntryFuncPtr         emit_funcptr;
    VfxSignalArg               *arguments;

    VfxObjWeakPtr               callback_obj;
    VfxSlotObjMemFuncPtr        callback_funcptr;
};


/*****************************************************************************
 * Class VfxAsyncSignalUtil
 *****************************************************************************/
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
static void processMREPostEmit(VfxPostEmitData* emitdata)
{
    VfxSlotList::SlotListEntry *i;
    for (i = emitdata->slots.getHead(); i != NULL; i = i->m_next)
    {
        if (i->m_slot.m_objPtr.get() && i->m_slot.m_objPtr->isProxy())
        {
            VfxObject *obj = i->m_slot.m_objPtr.get();
            VfxSlotObjMemFuncPtr callback = (VfxSlotObjMemFuncPtr)i->m_slot.m_callback;
    
            (*emitdata->emit_funcptr)(obj, callback, emitdata->arguments);
            emitdata->slots.removeSlot(obj, callback);
        }
    }
}
#endif


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxAsyncSignalUtil);

void VfxAsyncSignalUtil::regPostEmit(
    const VfxBaseSignal         *baseSignal,
    VfxEmitEntryFuncPtr          emit_funcptr, 
    VfxSignalArg                *arguments,
    VfxObject                   *callback_obj,
    VfxSlotObjMemFuncPtr        callback_funcptr
)
{
    VfxPostEmitData* emitdata;
    VFX_SYS_NEW_EX(emitdata, VfxPostEmitData, ());

    emitdata->slots.assignWithList(baseSignal->m_slotList);
    emitdata->emit_funcptr      = emit_funcptr;
    emitdata->arguments         = arguments;
    emitdata->callback_obj      = callback_obj;
    emitdata->callback_funcptr  = callback_funcptr;

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    processMREPostEmit(emitdata);
#endif

    vfxPostInvoke(this, &VfxAsyncSignalUtil::processPostEmit, (void*)emitdata);
}


void VfxAsyncSignalUtil::processPostEmit(void *data)
{
    VfxPostEmitData* emitdata = (VfxPostEmitData*)data;
    
    // invoke signal
    VfxBaseSignal::emitSlots(
        &emitdata->slots,
        emitdata->emit_funcptr, 
        emitdata->arguments
    );

    // TODO: how about callback_obj is dead
    // callback if assigned callback
    if (emitdata->callback_obj.get() && emitdata->callback_funcptr)
    {
        (*emitdata->emit_funcptr)(
            emitdata->callback_obj.get(),
            emitdata->callback_funcptr,
            emitdata->arguments);
    }

    // free the argument
    VFX_SYS_DELETE(emitdata->arguments);

    // free the post data
    VFX_SYS_DELETE(emitdata);
}


/*****************************************************************************
 * Class VfxSlotList
 *****************************************************************************/
 
VfxSlotList::SlotListEntry *VfxSlotList::findEntry(VfxObject *obj, VfxSlotObjMemFuncPtr memFunc) const
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(memFunc != NULL);

    VfxSlot slot_to_find(obj, memFunc);
    
    /* search if any handler is equal to the given handler */
    SlotListEntry *i;
    for (i = m_listHead; i != NULL; i = i->m_next)
    {
        if (i->m_slot.equalTo(slot_to_find))
        {
            return i;
        }
    }
    return NULL;
}  


void VfxSlotList::pushSlot(VfxObject *obj, VfxSlotObjMemFuncPtr memFunc)
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(memFunc != NULL);

    removeAllInvalidateSlots();

    SlotListEntry *entry = findEntry(obj, memFunc);
    if (entry != NULL)
    {
        // Do nothing if exist
        return;
    }
    
    // Cerate a new list entry
    VFX_SYS_NEW_EX(entry, SlotListEntry, (obj, memFunc));
    
    // Add this slot to the end of list
    if (m_listHead == NULL)
    {
        m_listHead = entry;
    }
    else
    {
        entry->m_next = m_listHead;
        m_listHead = entry;
    }
}


void VfxSlotList::appendSlot(VfxObject *obj, VfxSlotObjMemFuncPtr memFunc)
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(memFunc != NULL);

    removeAllInvalidateSlots();

    SlotListEntry *entry = findEntry(obj, memFunc);
    if (entry != NULL)
    {
        // Do nothing if exist
        return;
    }
    
    // Cerate a new list entry
    VFX_SYS_NEW_EX(entry, SlotListEntry, (obj, memFunc));
    
    // Add this slot to the end of list
    if (m_listHead == NULL)
    {
        m_listHead = entry;
    }
    else
    {
        SlotListEntry *tmp = m_listHead;
        while (tmp->m_next != NULL)
        {
            tmp = tmp->m_next;
        }
        tmp->m_next = entry;
    }
}


void VfxSlotList::removeSlot(VfxObject *obj, VfxSlotObjMemFuncPtr memFunc)
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(memFunc != NULL);

    removeAllInvalidateSlots();

    // Find the slot and remove from the list
    VfxSlot slot_to_find(obj, memFunc);
    SlotListEntry **entryPtr = &m_listHead;
    while (*entryPtr != NULL)
    {
        SlotListEntry *entry = *entryPtr;
        if (entry->m_slot.equalTo(slot_to_find))
        {
            *entryPtr = entry->m_next;
            VFX_SYS_DELETE(entry);
            return;
        }
        entryPtr = &(entry->m_next);
    }
}


void VfxSlotList::clear()
{
    SlotListEntry *i = m_listHead;
    while (i != NULL)
    {
        SlotListEntry *next = i->m_next;
        
        VFX_SYS_DELETE(i);

        i = next;
    }    
    m_listHead = NULL;
}


VfxS32 VfxSlotList::getCount() const
{
    VfxS32 cnt = 0;
    SlotListEntry *i = m_listHead;
    while (i != NULL)
    {
        cnt++;
        i = i->m_next;
    }    
    return cnt;
}


void VfxSlotList::assignWithList(const VfxSlotList &other)
{
    // Must be empty list
    VRT_ASSERT(m_listHead == NULL);

    SlotListEntry **entryPtr = &m_listHead;
    SlotListEntry *i;
    for (i = other.m_listHead; i != NULL; i = i->m_next)
    {
        SlotListEntry *entry;
        VFX_SYS_NEW_EX(entry, SlotListEntry, (i->m_slot.m_objPtr.get(), i->m_slot.m_callback));    

        *entryPtr = entry;
        entryPtr = &(entry->m_next);
    }
}


void VfxSlotList::removeAllInvalidateSlots()
{
    SlotListEntry **entryPtr = &m_listHead;
    while (*entryPtr != NULL)
    {
        SlotListEntry *entry = *entryPtr;
        if (!entry->m_slot.isValid())
        {
            *entryPtr = entry->m_next;
            VFX_SYS_DELETE(entry);
        }
        else
        {
            entryPtr = &(entry->m_next);
        }
    }
}


/*****************************************************************************
 * class VfxBaseSignal
 *****************************************************************************/

VfxS32 VfxBaseSignal::getSlotCount() const
{
    return m_slotList.getCount();
}


void VfxBaseSignal::emitImpl(VfxEmitEntryFuncPtr emit_funcptr, void *arguments) const
{
    VfxSlotList tmpSlotList(m_slotList);
    emitSlots(&tmpSlotList, emit_funcptr, arguments);
}


void VfxBaseSignal::emitSlots(const VfxSlotList *slot_list, VfxEmitEntryFuncPtr emit_funcptr, void *arguments)
{
    VfxEmitFrame emitFrame;
    emitFrame.enter();

    // for all signal handler in callback list
    VfxSlotList::SlotListEntry *i = slot_list->getHead();
    for (; i != NULL; i = i->m_next)
    {
        if (!i->m_slot.isValid())
        {
            continue;
        }
        
        // Callback the object slot member method
        VfxObject *obj = i->m_slot.m_objPtr.get();
        VfxSlotObjMemFuncPtr callback = (VfxSlotObjMemFuncPtr)i->m_slot.m_callback;

        // Callback by emit function
        (*emit_funcptr)(obj, callback, arguments);

        // break if handler is not return
        if (emitFrame.stop)
        {
            break;
        }
    }
    emitFrame.leave();
}


void VfxBaseSignal::baseConnectFront(VfxObject *obj, VfxSlotObjMemFuncPtr func)
{
    // Ignore NULL object pointer
    if (obj == NULL)
    {
        return;
    }
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(func != NULL);

    m_slotList.pushSlot(obj, func);
}


void VfxBaseSignal::baseConnect(VfxObject *obj, VfxSlotObjMemFuncPtr func)
{
    // Ignore NULL object pointer
    if (obj == NULL)
    {
        return;
    }
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(func != NULL);
        
    m_slotList.appendSlot(obj, func);
}


void VfxBaseSignal::baseDisconnect(VfxObject *obj, VfxSlotObjMemFuncPtr func)
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(func != NULL);
        
    m_slotList.removeSlot(obj, func);
}

