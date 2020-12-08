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
 *  vfx_timer.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Timer Input Sub-system
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

#include "vfx_timer.h"

#include "vrt_datatype.h"
#include "vrt_system.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_object_list.h"
#include "vfx_signal.h"
#include "vfx_sys_mem_config.h"

#include "vfx_adp_device.h"

#include "vfx_mmi.h"
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


/***************************************************************************** 
 * Class VfxTimerManager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_TIMER_MANAGER_CLASS_NAME, VfxTimerManager, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxTimerManager);

VfxTimerManager::VfxTimerManager() : 
    m_state(VFX_TIMER_MANAGER_STATE_UNKNOWN),
    m_timerType(VFX_TIMER_MANAGER_TYPE_UNKNOWN),
    m_startedTimerType(VFX_TIMER_MANAGER_TYPE_UNKNOWN),
    m_timeUpTime(0)
{
}


void VfxTimerManager::startTimer(VfxBaseTimer *timer)
{
    VFX_OBJ_ASSERT_VALID(timer);
    VFX_DEV_ASSERT(timer->m_startDelay >= 0);
    
    stopTimer(timer);
    
    VFX_LOG(VFX_INFO, VFX_TIMER_START_TIMER, timer, timer->m_startDelay, timer->onGetDurationValue());
    
    timer->m_queuedListEntry = m_queuedTimerList.append(timer);
}

    
void VfxTimerManager::stopTimer(VfxBaseTimer *timer)
{
    VFX_OBJ_ASSERT_VALID(timer);
    
    VFX_LOG(VFX_INFO, VFX_TIMER_STOP_TIMER, timer);
    
    if (timer->m_queuedListEntry != NULL)
    {
        m_queuedTimerList.removePos(timer->m_queuedListEntry);
        timer->m_queuedListEntry = NULL;
    }
    
    if (timer->m_enabledListEntry != NULL)
    {
        m_enabledTimerList.removePos(timer->m_enabledListEntry);
        timer->m_enabledListEntry = NULL;
    }
}


void VfxTimerManager::switchTimerType(VfxTimerManagerTypeEnum timerType)
{
   if (m_timerType == timerType)
   {
       // Do nothing.
       return;
   }
   
   VFX_LOG(VFX_INFO, VFX_TIMER_SWITCH_TIMER_TYPE, timerType);
   
   // There is no timer started
   if (m_state != VFX_TIMER_MANAGER_STATE_WAIT)
   {
       // Switch to new timer type dirtly
       m_timerType = timerType;
       return;
   }
   
   VfxMsec currentTime = getCurrentTime(timerType);
   VfxBool isBacklightOff = (vfx_adp_sleep_mode_get_state() == VFX_ADP_SLEEP_MODE_STATE_DISABLE);
   
   stopSystemTimer();
   
   m_timerType = timerType;
   
   startSystemTimer(currentTime, isBacklightOff);
}


void VfxTimerManager::sleepIn()
{
    VfxMsec currentTime = getCurrentTime(m_timerType);
    
    stopSystemTimer();
    emitAllTimeUpTimer(currentTime, VFX_TRUE);
    startSystemTimer(currentTime, VFX_TRUE);
}


void VfxTimerManager::sleepOut()
{
    VfxMsec currentTime = getCurrentTime(VFX_TIMER_MANAGER_TYPE_VFX_TIMER);
    
    stopSystemTimer();
    emitAllTimeUpTimer(currentTime, VFX_FALSE);
    startSystemTimer(currentTime, VFX_FALSE);
}


VfxBool VfxTimerManager::processCommit(VfxMsec currentTime, VfxBool isBacklightOff)
{
    if (m_state == VFX_TIMER_MANAGER_STATE_EMIT)
    {
        // Do nothing
        return VFX_FALSE;
    }

    VFX_LOG(VFX_INFO3, VFX_TIMER_COMMIT_BEGIN);

    VfxBool emitAnyTimer = VFX_FALSE;

    // Copy all queued timer to a temp queue
    VfxObjList tempTimerList;
    tempTimerList.swap(m_queuedTimerList);
    VfxObjListEntry *i;
    for (i = tempTimerList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxBaseTimer *timer = (VfxBaseTimer *)i->get();
        timer->m_queuedListEntry = NULL;
    }
    
    while (VFX_TRUE)
    {
        i = tempTimerList.getValidHead();
        if (i == NULL)  // obj list is empty
        {
            break;
        }
        
        VfxBaseTimer *timer = (VfxBaseTimer *)i->get();
        VfxMsec relEmitTime = timer->m_startDelay;
		VfxMsec durationTime = timer->onGetDurationValue();

        // remove from the list
        tempTimerList.removePos(i);

        if (relEmitTime == 0)
        {
            VfxWeakPtr <VfxBaseTimer> timerPtr(timer);
            
            // Directly emit the tick signal if start delay is zero
            timer->onTimer();
            emitAnyTimer = VFX_TRUE;

            // The timer has been deleted or restared
            if (timerPtr == NULL || timer->m_queuedListEntry != NULL)
            {
                continue;
            }

            relEmitTime = durationTime;
        }

        // Insert into enabled timer list
        if (relEmitTime != 0)
        {
            isBacklightOff ? 
                VFX_FLAG_CLEAR(timer->m_timerFlags, VFX_TIMER_FLAG_BACKLIGHT_ON) :
                VFX_FLAG_SET(timer->m_timerFlags, VFX_TIMER_FLAG_BACKLIGHT_ON);
            timer->m_commitDuration = durationTime;
            timer->m_tickTime = currentTime + relEmitTime;
            timer->m_enabledListEntry = insertTimerIntoEnabledList(currentTime, timer);
        }
    }

    // after previous while loop, the timer list should already empty.
    VFX_DEV_ASSERT(tempTimerList.isEmpty());

    VfxObjListEntry *headEntry = m_enabledTimerList.getValidHead();
    if (headEntry == NULL)
    {
        VFX_LOG(VFX_INFO3, VFX_TIMER_COMMIT_END, 1);
        
        // The list is empty, do nothing
        return emitAnyTimer;
    }

    VfxBaseTimer *headTimer = (VfxBaseTimer *)headEntry->get();
    VFX_DEV_ASSERT(headTimer != NULL);

    // If there is no started system timer or the timer is closer, 
    //  reset the system timer
    if (m_state == VFX_TIMER_MANAGER_STATE_IDLE || 
        vfxMsecDiff(headTimer->m_tickTime, m_timeUpTime) < 0)
    {
        stopSystemTimer();
        startSystemTimer(currentTime, isBacklightOff);
    }

    VFX_LOG(VFX_INFO3, VFX_TIMER_COMMIT_END, 0);

    return emitAnyTimer;
}


VfxSimpleTimer *VfxTimerManager::getSimpleTimer(const VfxCallback0 &callback)
{
    VFX_DEV_ASSERT(callback.isValid());
    
    VfxObjListEntry *i;
    VfxBaseTimer *timer = NULL;
    VfxSimpleTimer *simpleTimer = NULL;
    
    for (i = m_queuedTimerList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        timer = (VfxBaseTimer *)i->get();
        if (VFX_FLAG_HAS(timer->m_timerFlags, VFX_TIMER_FLAG_SIMPLE_TIMER))
        {
            simpleTimer = (VfxSimpleTimer*)timer;
            if (simpleTimer->m_callback.equalTo(callback))
            {
                break;
            }
        }
    }
    
    if (i != NULL)
    {
        return (VfxSimpleTimer*)timer;
    }
    
    for (i = m_enabledTimerList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        timer = (VfxBaseTimer *)i->get();
        if (VFX_FLAG_HAS(timer->m_timerFlags, VFX_TIMER_FLAG_SIMPLE_TIMER))
        {
            simpleTimer = (VfxSimpleTimer*)timer;
            if (simpleTimer->m_callback.equalTo(callback))
            {
                break;
            }
        }
    }
    
    if (i == NULL)
    {
        return (VfxSimpleTimer*)NULL;
    }
    
    return (VfxSimpleTimer*)timer;
}


VfxMsec VfxTimerManager::getCurrentTime() const
{
    return getCurrentTime(m_timerType);
}


vrt_allocator_handle VfxTimerManager::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}


void VfxTimerManager::onInit()
{
    VFX_LOG(VFX_INFO, VFX_TIMER_INIT);

    VfxObject::onInit();

    VFX_DEV_ASSERT(m_state == VFX_TIMER_MANAGER_STATE_UNKNOWN);
    m_state = VFX_TIMER_MANAGER_STATE_IDLE;
    m_timerType = VFX_TIMER_MANAGER_TYPE_VFX_TIMER;
}


VfxObjListEntry *VfxTimerManager::insertTimerIntoEnabledList(VfxMsec currentTime, VfxBaseTimer *timer)
{
    VFX_DEV_ASSERT(timer != NULL);
    VFX_DEV_ASSERT(timer->m_enabledListEntry == NULL);
    VFX_DEV_ASSERT(vfxMsecDiff(timer->m_tickTime, currentTime) > 0);

    VfxObjListEntry *i;
    for (i = m_enabledTimerList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxBaseTimer *inListTimer = (VfxBaseTimer *)i->get();

        // Ignore all timer before current time, 
        //  to avoid the MAX_INT delayed timer insert before them.
        if (vfxMsecDiff(inListTimer->m_tickTime, currentTime) <= 0)
        {
            continue;
        }

        // Remark: Append to after, if the time is equal (<= 0). (FIFO)
        if (vfxMsecDiff(timer->m_tickTime, inListTimer->m_tickTime) < 0)
        {
            return m_enabledTimerList.insertBefore(i, timer);
        }
    }
    
    return m_enabledTimerList.append(timer);
}


VfxMsec VfxTimerManager::getCurrentTime(VfxTimerManagerTypeEnum timerType) const
{
    VfxBool isBacklightOff = (vfx_adp_sleep_mode_get_state() == VFX_ADP_SLEEP_MODE_STATE_DISABLE);
    if (isBacklightOff)
    {
        timerType = VFX_TIMER_MANAGER_TYPE_VFX_TIMER;
    }
    
    VfxMsec currentTime = 0;
    switch (timerType)
    {
        case VFX_TIMER_MANAGER_TYPE_VFX_TIMER:
            // VRT timer may offset system timer
            currentTime = vrt_adjust_with_frame_time(vrt_sys_get_time());
            break;

        case VFX_TIMER_MANAGER_TYPE_VRT_TIMER:
            currentTime = vrt_get_current_frame_time();
            break;

        default:
            VFX_ASSERT(0);
            break;
    };
    return currentTime;
}


VfxMsec VfxTimerManager::caculateNextVfxDelay(VfxMsec currentTime)
{
    VfxMsec ret = VFX_TIMER_MANAGER_MIN_VFX_TIMER;

    // Align to VFX_TIMER_MANAGER_MIN_VFX_TIMER. 
    //  to save battery power when LCD backlight off

    // But if there is any align timer before VFX_TIMER_MANAGER_MIN_VFX_TIMER,
    //  we should callback at that time. (or start on backlight on)
    
    VfxObjListEntry *entry;
    for (entry = m_enabledTimerList.getValidHead();
        entry != NULL;
        entry = entry->getValidNext())
    {
        VfxBaseTimer *timer = (VfxBaseTimer *)entry->get();        
        VfxMsec delay = vfxMsecDiff(timer->m_tickTime, currentTime);
        if (delay <= 0)
        {
            ret = 1;
            break;
        }

        if (delay >= VFX_TIMER_MANAGER_MIN_VFX_TIMER)
        {
            // No more timer before VFX_TIMER_MANAGER_MIN_VFX_TIMER
            break;
        }

        if (VFX_FLAG_HAS(timer->m_timerFlags, VFX_TIMER_FLAG_ALIGNED) ||
            VFX_FLAG_HAS(timer->m_timerFlags, VFX_TIMER_FLAG_BACKLIGHT_ON))
        {
            ret = delay;
            break;
        }            
    }

    return ret;
}


void VfxTimerManager::startSystemTimer(VfxMsec currentTime, VfxBool isBacklightOff)
{
    // Must no timer started
    VFX_DEV_ASSERT(m_state == VFX_TIMER_MANAGER_STATE_IDLE);
    VFX_DEV_ASSERT(m_startedTimerType == VFX_TIMER_MANAGER_TYPE_UNKNOWN);
    
    VfxObjListEntry *headEntry = m_enabledTimerList.getValidHead();
    if (headEntry == NULL)
    {
        // The list is empty, do nothing
        return;
    }

    VfxTimerManagerTypeEnum timerType = m_timerType;
    // Always using VFX timer when LCD backlight off
    if (isBacklightOff)
    {
        timerType = VFX_TIMER_MANAGER_TYPE_VFX_TIMER;
    }

    VFX_LOG(VFX_INFO, VFX_TIMER_START_SYS_TIME, timerType, currentTime);

    // Start timer for the next timeup time
    VfxBaseTimer *timer = (VfxBaseTimer *)headEntry->get();
    switch (timerType)
    {
        case VFX_TIMER_MANAGER_TYPE_VFX_TIMER:
            {
                VfxMsec delay = caculateNextVfxDelay(currentTime);
                vfx_sys_timer_start(delay, timeUpCallback, this);
                break;
            }

        case VFX_TIMER_MANAGER_TYPE_VRT_TIMER:
            {
                VFX_DEV_ASSERT(vfx_sys_get_canvas_state() == VFX_SYS_STATE_ENTRY);
                vrt_timer_start(timer->m_tickTime, timeUpCallback, this, vrt_canvas_get_instance());
                break;
            }

        default:
            VFX_ASSERT(0);
            break;
    };
    
    m_state = VFX_TIMER_MANAGER_STATE_WAIT;
    m_startedTimerType = timerType;
    m_timeUpTime = timer->m_tickTime;
}


void VfxTimerManager::stopSystemTimer()
{
    VFX_DEV_ASSERT(m_state != VFX_TIMER_MANAGER_STATE_EMIT);

    if (m_state == VFX_TIMER_MANAGER_STATE_IDLE)
    {
        VFX_DEV_ASSERT(m_startedTimerType == VFX_TIMER_MANAGER_TYPE_UNKNOWN);
        // No timer started, do nothing
        return;
    }
    
    VFX_LOG(VFX_INFO, VFX_TIMER_STOP_SYS_TIME, m_startedTimerType);

    switch (m_startedTimerType)
    {
        case VFX_TIMER_MANAGER_TYPE_UNKNOWN:
            // No timer started, do nothing
            break;
            
        case VFX_TIMER_MANAGER_TYPE_VFX_TIMER:
            vfx_sys_timer_stop();
            break;

        case VFX_TIMER_MANAGER_TYPE_VRT_TIMER:
            vrt_timer_stop(vrt_canvas_get_instance());
            break;

        default:
            VFX_ASSERT(0);
            break;
    };

    m_state = VFX_TIMER_MANAGER_STATE_IDLE;
    m_startedTimerType = VFX_TIMER_MANAGER_TYPE_UNKNOWN;
    m_timeUpTime = 0;
}


void VfxTimerManager::emitAllTimeUpTimer(VfxMsec currentTime, VfxBool isBacklightOff)
{
    VFX_DEV_ASSERT(m_state == VFX_TIMER_MANAGER_STATE_IDLE);
    VFX_DEV_ASSERT(m_startedTimerType == VFX_TIMER_MANAGER_TYPE_UNKNOWN);
        
    m_state = VFX_TIMER_MANAGER_STATE_EMIT;

    while (1)
    {
        VfxObjListEntry *headEntry = m_enabledTimerList.getHead();

        // The enabled list is emptry, stop the loop 
        if (headEntry == NULL)
        {
            break;
        }
        
        VfxBaseTimer *timer = (VfxBaseTimer *)headEntry->get();

        // The timer has been deleted, remove from list.
        if (timer == NULL)
        {
            m_enabledTimerList.removePos(headEntry);
            continue;
        }

        // All timers are not time up, stop the loop
        if (vfxMsecDiff(timer->m_tickTime, currentTime) > 0)
        {
            break;
        }

        m_enabledTimerList.removePos(headEntry);
        timer->m_enabledListEntry = NULL;
        
        if (timer->m_commitDuration != 0)
        {
            isBacklightOff ? 
                VFX_FLAG_CLEAR(timer->m_timerFlags, VFX_TIMER_FLAG_BACKLIGHT_ON) :
                VFX_FLAG_SET(timer->m_timerFlags, VFX_TIMER_FLAG_BACKLIGHT_ON);
                
            // Prepare next tick time
            while (vfxMsecDiff(timer->m_tickTime, currentTime) <= 0)
            {
                timer->m_tickTime += timer->m_commitDuration;
            }
            timer->m_enabledListEntry = insertTimerIntoEnabledList(currentTime, timer);        
        }
        
        VFX_LOG(VFX_INFO2, VFX_TIMER_EMIT, currentTime, timer);

        // Emit the tick signal
        timer->onTimer();
    }

    m_state = VFX_TIMER_MANAGER_STATE_IDLE;
}


void VfxTimerManager::timeUpCallback(void *data)
{
    VfxTimerManager *self = (VfxTimerManager *)data;
    VFX_DEV_ASSERT(self != NULL);

    if (self->m_state != VFX_TIMER_MANAGER_STATE_WAIT)
    {
        VRT_MUST_TRACE(("[VFX] VfxTimerManager::timeUpCallback(): an unknown callback.\n"));
        
        // Reset started timer
        self->m_state = VFX_TIMER_MANAGER_STATE_IDLE;
        self->m_startedTimerType = VFX_TIMER_MANAGER_TYPE_UNKNOWN;

        return;
    }

    // Get current time (timeup time)
    VfxMsec currentTime = self->getCurrentTime(self->m_startedTimerType);
    VfxBool isBacklightOff = (vfx_adp_sleep_mode_get_state() == VFX_ADP_SLEEP_MODE_STATE_DISABLE);

    VFX_LOG(VFX_INFO, VFX_TIMER_TIME_UP, self->m_startedTimerType, currentTime);

    // Reset started timer
    self->m_state = VFX_TIMER_MANAGER_STATE_IDLE;
    self->m_startedTimerType = VFX_TIMER_MANAGER_TYPE_UNKNOWN;
    
    // Emit all time up
    self->emitAllTimeUpTimer(currentTime, isBacklightOff);

    // Start next timer
    self->startSystemTimer(currentTime, isBacklightOff);
}


/*****************************************************************************
 * Class VfxBaseTimer
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_BASETIMER_CLASS_NAME, VfxBaseTimer, VfxObject);

VfxBaseTimer::VfxBaseTimer() :
    m_timerFlags(0),
    m_startDelay(0),
    m_queuedListEntry(NULL),
    m_enabledListEntry(NULL),
    m_commitDuration(0),
    m_tickTime(0)
{
}


void VfxBaseTimer::setIsSimpleTimer(VfxBool value)
{
    if (value)
    {
        VFX_FLAG_SET(m_timerFlags, VFX_TIMER_FLAG_SIMPLE_TIMER);
    }
    else
    {
        VFX_FLAG_CLEAR(m_timerFlags, VFX_TIMER_FLAG_SIMPLE_TIMER);
    }
}


void VfxBaseTimer::onDeinit()
{
    // Stop the timer
    stop();
    
    VfxObject::onDeinit();
}


void VfxBaseTimer::onTimer()
{
}


VfxMsec VfxBaseTimer::onGetDurationValue()
{
    return 0;
}


/***************************************************************************** 
 * Class VfxTimer
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS(VFX_TIMER_CLASS_NAME, VfxTimer, VfxBaseTimer);

VfxMsec VfxTimer::getCurrentTime()
{
    VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    return timelineManager->getCurrentTime();
}


VfxMsec VfxTimer::getCurrentSystemTime()
{
    return vrt_sys_get_time();
}


void VfxTimer::blockUntil(VfxMsec absBlockTime)
{
    if (vfx_adp_sleep_mode_get_state() != VFX_ADP_SLEEP_MODE_STATE_ENABLE)
    {
        return;
    }
    

    vrt_canvas_staue_enum canvasState = vrt_canvas_get_state();
    if (canvasState == VRT_CANVAS_STATE_SHUTDOWN)
    {
        return;
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XTB", SA_start);
#endif

    if (canvasState == VRT_CANVAS_STATE_SUSPEND)
    {
        vrt_canvas_resume();
    }
    
    while (vfxMsecDiff(vrt_get_finish_frame_time(), absBlockTime) < 0)
    {
        kal_sleep_task(1);
    }

    if (canvasState == VRT_CANVAS_STATE_SUSPEND)
    {
        vrt_canvas_suspend();
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XTB", SA_stop);
#endif
}


VfxTimer::VfxTimer() :
    m_duration(0)
{
}


void VfxTimer::onTimer()
{
    m_signalTick.emit(this);
}


VfxMsec VfxTimer::onGetDurationValue()
{
    return m_duration;
}


/*****************************************************************************
 * Class VfxSimpleTimer
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VFX_SIMPLETIMER_CLASS_NAME, VfxSimpleTimer, VfxBaseTimer);

VfxSimpleTimer::VfxSimpleTimer()
{
}


void VfxSimpleTimer::start(const VfxCallback0 &callback, VfxMsec time)
{
    VFX_ASSERT(callback.isValid());
    
    VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    VfxSimpleTimer *simpleTimer = timelineManager->getSimpleTimer(callback);
    if (simpleTimer == NULL)
    {
        __VFX_OBJ_CREATE(simpleTimer, VfxSimpleTimer, callback.m_objPtr.get());
        simpleTimer->setIsSimpleTimer(VFX_TRUE);
        simpleTimer->setCallback(callback);
    }
    simpleTimer->setStartDelay(time);
    simpleTimer->VfxBaseTimer::start();
}


void VfxSimpleTimer::stop(const VfxCallback0 &callback)
{
    VFX_ASSERT(callback.isValid());
    
    VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    VfxSimpleTimer *simpleTimer = timelineManager->getSimpleTimer(callback);
    if (simpleTimer == NULL)
    {
        return ;
    }
    VFX_OBJ_CLOSE(simpleTimer);
}


VfxMsec VfxSimpleTimer::getTickTime(const VfxCallback0 &callback)
{
    VFX_ASSERT(callback.isValid());
    
    VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    VfxSimpleTimer *simpleTimer = timelineManager->getSimpleTimer(callback);
    if (simpleTimer == NULL)
    {
        return (VfxMsec)0;
    }
    return simpleTimer->getAbsoluteTime();
}


void VfxSimpleTimer::onTimer()
{
    VfxCallback0 callback = m_callback;
    
    VfxSimpleTimer *self = this;
    VFX_OBJ_CLOSE(self);
    
    //callback
    callback.invoke();
}
