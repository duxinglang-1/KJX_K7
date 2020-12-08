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
 *  vfx_async_signal.cpp
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

#include "vfx_async_signal.h"


#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"

#include "vadp_sys_trc.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


#define VFX_ASYNC_SIGNAL_EMIT_LOOP_THRESHOLD    1000
#define VFX_ASYNC_SIGNAL_EMIT_BURST_THRESHOLD   3000


/*****************************************************************************
 * Class VfxAsyncSignalQueue
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_ASYNC_SIGNAL_QUEUE_CLASS_NAME, VfxAsyncSignalQueue, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxAsyncSignalQueue);

void VfxAsyncSignalQueue::putSlot(
    VfxObject *obj, 
    VfxAsyncSlotObjMemFuncPtrEx memFunc,
    void *data)
{
    VFX_OBJ_ASSERT_VALID(obj);
    VFX_ASSERT(memFunc != NULL);

    // Cerate a new list entry
    SlotQueueEntry *entry;    
    VFX_SYS_NEW_EX(entry, SlotQueueEntry, (obj, memFunc, data));

    vfx_sys_acquire_post_lock();

    // Add the slot to the tail of list
    if (m_listTail != NULL)
    {
        m_listTail->m_next = entry;
    }
    m_listTail = entry;

    // Add to the head if the list is empty
    if (m_listHead == NULL)
    {
        m_listHead = entry;
    }

    vfx_sys_release_post_lock();

    // Notify MMI task to handle the signal
    vfx_sys_notify_mmitask();
}


void VfxAsyncSignalQueue::clear()
{
    vfx_sys_acquire_post_lock();

    SlotQueueEntry *i = m_listHead;
    while (i != NULL)
    {
        SlotQueueEntry *next = i->m_next;

        VFX_SYS_DELETE(i);

        i = next;
    }    
    m_listHead = NULL;

    vfx_sys_release_post_lock();
}


void VfxAsyncSignalQueue::processEmit()
{
    VFX_LOG(VFX_INFO3, VFX_MMI_CHECK_UPDATE_BEGIN);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XCU", SA_start);
#endif

    VfxS32 loopCountDown = VFX_ASYNC_SIGNAL_EMIT_LOOP_THRESHOLD;
    do
    {
        // NOTE: 
        //  Assert here if it have infinit loop with post emit.
        //  For example, emit a post in callback ltself
        VFX_ASSERT(loopCountDown != 0);
        loopCountDown--;
        
        VfxS32 burstCountDown = VFX_ASYNC_SIGNAL_EMIT_BURST_THRESHOLD;
        while (1)
        {
            // NOTE: 
            //  Assert here if there are burst post emits
            //  For example, emit so many post in one loop
            VFX_ASSERT(burstCountDown > 0);
            burstCountDown--;
            
            SlotQueueEntry *entry = getSlot();
            if (entry == NULL)
            {
                // No more entry in the queue
                break;
            }

            // The target is invalid, ignore it
            VfxObject *obj = entry->m_targetPtr.get();
            if (obj == NULL)
            {
                continue;
            }

            VFX_OBJ_ASSERT_VALID(obj);

            VfxAsyncSlotObjMemFuncPtrEx callback = entry->m_callback;
            (obj->*callback)(entry->m_data);

            VFX_SYS_DELETE(entry);
        } // while (1)
    } while (!isEmpty());

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XCU", SA_stop);
#endif
    VFX_LOG(VFX_INFO3, VFX_MMI_CHECK_UPDATE_END);
}


VfxAsyncSignalQueue::SlotQueueEntry *VfxAsyncSignalQueue::getSlot()
{
    vfx_sys_acquire_post_lock();
    
    SlotQueueEntry *firstEntry = m_listHead;
    if (firstEntry != NULL)
    {
        m_listHead = firstEntry->m_next;

        if (m_listHead == NULL)
        {
            // If the queue becomes empty, pointer the last entry to NULL
            m_listTail = NULL;
        }
    }

    vfx_sys_release_post_lock();

    return firstEntry;
}

