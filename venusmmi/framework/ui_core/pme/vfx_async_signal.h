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
 *  vfx_async_signal.h
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
#ifndef __VFX_ASYNC_SIGNAL_H__
#define __VFX_ASYNC_SIGNAL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxBase
#include "vfx_cpp_base.h"
// For VfxObject
#include "vfx_object.h"
// For VfxObjWeakPtr
#include "vfx_weak_ptr.h"

#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_sys_mem_config.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_ASYNC_SIGNAL_QUEUE_CLASS_NAME "AsyncSignalQueue"


/*****************************************************************************
 * Class VfxAsyncSignalQueue
 *****************************************************************************/

// Event callback
typedef void (VfxObject::*VfxAsyncSlotObjMemFuncPtrEx)(void *data);
// VfxAsyncSignal0 callbak
typedef void (VfxObject::*VfxAsyncSlotObjMemFuncPtr)();

class VfxAsyncSignalQueue : public VfxObject
{
    VFX_DECLARE_CLASS(VfxAsyncSignalQueue);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxAsyncSignalQueue);
    
// Constructor / Destructor
public:
    // Default constructor
    VfxAsyncSignalQueue() : m_listHead(NULL), m_listTail(NULL)
    {
    }

    // Destructor    
    virtual ~VfxAsyncSignalQueue()
    {
        clear();
    }

// Methods    
public:
    // Test if the slot list is empty
    VfxBool isEmpty() const
    {
        return m_listHead == NULL;
    }

    // Add a slot into the tail of slot queue
    void putSlot(
        VfxObject *obj, 
        VfxAsyncSlotObjMemFuncPtrEx memFunc,
        void *data
    );

    // Add a slot into the tail of slot queue (without event)
    void putSlot0(
        VfxObject *obj, 
        VfxAsyncSlotObjMemFuncPtr memFunc
    )
    {
        putSlot(obj, (VfxAsyncSlotObjMemFuncPtrEx)memFunc, NULL);
    }
    
    // Clear all slots in the slot list
    void clear();

// Framewrok methods
public:
    void processEmit();

// Overridable
public:
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator()
    {
        return vfx_sys_mem_get_global_allocator();
    }

// Implementation
private:
    class SlotQueueEntry : public VfxBase
    {
    public:
        SlotQueueEntry(
            VfxObject *obj, 
            VfxAsyncSlotObjMemFuncPtrEx memFunc,
            void *data) :
                m_targetPtr(obj),
                m_callback(memFunc),
                m_data(data),
                m_next(NULL)
        {
        }

    public:
        VfxObjWeakPtr               m_targetPtr;
        VfxAsyncSlotObjMemFuncPtrEx m_callback;
        void                       *m_data;
        SlotQueueEntry             *m_next;
    };

    SlotQueueEntry *m_listHead; // Pointer to the first slot entry of queue
    SlotQueueEntry *m_listTail; // Pointer to the last slot entry of queue

    // Get the first slot entry of the queue, and remove it from queue.
    // RETURNS: The first of slot entry of the queue. 
    //          Return NULL if the queue is empty.
    SlotQueueEntry *getSlot();
};


/*****************************************************************************
 * Global Functions
 *****************************************************************************/

// A helper invoke post without type safe. 
// This function is for internal use by framework.
template <class _MemFunc>
inline 
void vfxPostInvoke(VfxObject *obj, _MemFunc func, void *data = NULL)
{
    VfxAsyncSignalQueue *queue = VFX_OBJ_GET_INSTANCE(VfxAsyncSignalQueue);
    queue->putSlot(obj, VFX_STATIC_CAST(func, VfxAsyncSlotObjMemFuncPtrEx), data);
}

#endif /* __VFX_ASYNC_SIGNAL_H__ */

