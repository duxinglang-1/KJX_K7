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
 *  vfx_timer.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus Timer event sub-system
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
#ifndef __VFX_TIMER_H__
#define __VFX_TIMER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_object_list.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxTimerManager registered name
#define VFX_TIMER_MANAGER_CLASS_NAME    "TimerManager"

// The VfxTimer registered name
#define VFX_TIMER_CLASS_NAME  "Timer"

// The VfxBaseTimer registered name
#define VFX_BASETIMER_CLASS_NAME	"BaseTimer"

// The VfxSimpleTimer registered name
#define VFX_SIMPLETIMER_CLASS_NAME	"SimpleTimer"

// To avoid the VFX timer callback too busy, it will bound on 30 sec.
#define VFX_TIMER_MANAGER_MIN_VFX_TIMER 30000

/*
 * Timer flags
 */

#define VFX_TIMER_FLAG_ALIGNED          (1 << 0)
// The timer has been start on backlight-on
#define VFX_TIMER_FLAG_BACKLIGHT_ON     (1 << 1)
#define VFX_TIMER_FLAG_SIMPLE_TIMER		(1 << 2)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Pre-defined classes
class VfxBaseTimer;
class VfxSimpleTimer;
 

/***************************************************************************** 
 * Class VfxAnimationTimerList
 *****************************************************************************/

/*
 * Internal used. It should only be changed by framework.
 */
enum VfxTimerManagerTypeEnum
{
    VFX_TIMER_MANAGER_TYPE_UNKNOWN = 0,
    VFX_TIMER_MANAGER_TYPE_VFX_TIMER,   // Based on system time.
    VFX_TIMER_MANAGER_TYPE_VRT_TIMER,   // Based on VRT frame time.
    VFX_TIMER_MANAGER_TYPE_END_OF_ENUM
};

/*
 * Internal used. It should only be changed by framework.
 */
enum VfxTimerManagerStateEnum
{
    VFX_TIMER_MANAGER_STATE_UNKNOWN = 0,
    VFX_TIMER_MANAGER_STATE_IDLE,       // Idle, on timer started
    VFX_TIMER_MANAGER_STATE_WAIT,       // Wait for next timer time-out
    VFX_TIMER_MANAGER_STATE_EMIT,       // Emitting all time-out timer
    VFX_TIMER_MANAGER_STATE_END_OF_ENUM
};


/*
 * Internal used.
 */
class VfxTimerManager : public VfxObject
{
    VFX_DECLARE_CLASS(VfxTimerManager);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxTimerManager);

// Constructor / Destructor
public:
    // Default constructor
    VfxTimerManager();

// Method
public:
    // Start a timer
    void startTimer(
        VfxBaseTimer *timer // [IN] The timer to be started
    );

    // Stop a timer
    void stopTimer(
        VfxBaseTimer *timer // [IN] The timer to be stopped
    );

    // Return the current time of current time mode
    VfxMsec getCurrentTime() const;

    // Internal used. Switchs timer mode to use system time or frame time.
    void switchTimerType(
        VfxTimerManagerTypeEnum timerType   // [IN] Timer mode.
    );

    // Internal used.
    void sleepIn();
    
    // Internal used.
    void sleepOut();
    
    // Internal used. Commit all enabled timers.
    VfxBool processCommit(VfxMsec currentTime, VfxBool isBacklightOff);

    // Internal used. Get simple timer by callback.
    VfxSimpleTimer *getSimpleTimer(const VfxCallback0 &callback);

// Override
protected:
    virtual vrt_allocator_handle getAllocator();
    virtual void onInit();

// Implemetation
private:
    VfxTimerManagerStateEnum m_state;
    VfxTimerManagerTypeEnum m_timerType;
    VfxTimerManagerTypeEnum m_startedTimerType;
    VfxMsec m_timeUpTime;

    VfxObjList m_queuedTimerList;
    VfxObjList m_enabledTimerList;

    VfxObjListEntry *insertTimerIntoEnabledList(VfxMsec currentTime, VfxBaseTimer *timer);
    VfxMsec getCurrentTime(VfxTimerManagerTypeEnum timerType) const;

    VfxMsec caculateNextVfxDelay(VfxMsec currentTime);
    void startSystemTimer(VfxMsec currentTime, VfxBool isBacklightOff);
    void stopSystemTimer();
    void emitAllTimeUpTimer(VfxMsec currentTime, VfxBool isBacklightOff);

    static void timeUpCallback(void *data);
};


/*****************************************************************************
 * Class VfxBaseTimer
 *****************************************************************************/

/*
 * VfxBaseTimer is used to start a base timer
 */
class VfxBaseTimer : public VfxObject
{
public:
    VFX_DECLARE_CLASS(VfxBaseTimer);

// Constructor / Destructor
public:
    // Default constructor
    VfxBaseTimer();

// Property
public:
    // The first time emit signal after start the timer, in mili-second.
    //
    //NOTE: Default value is 0.
    VfxMsec getStartDelay() const
    {
        return m_startDelay;
    }
    
    // SEE ALSO: VfxBaseTimer::getStartDelay.
    void setStartDelay(VfxMsec value)
    {
        VFX_ASSERT(value >= 0);
        m_startDelay = value;
    }
    
    //TODO: Phase out the method
    void setIsAligned(VfxBool value)
    {
        VFX_UNUSED(value);
    }
    
    // The next absolute time to emit tick
    VfxMsec getAbsoluteTime() const
    {
        return m_tickTime;
    }
    
    // Set the timer for simple timer
    void setIsSimpleTimer(VfxBool value);
	
// Method
public:
    // Return if the timer is started.
    //
    // RETURNS: 
    //	Return VFX_TURE if the timer is enabled, otherwise return VFX_FALSE
    VfxBool getIsEnabled() const
    {
        return m_queuedListEntry != NULL || m_enabledListEntry != NULL;
    }
    
    // Start the timer.
    //
    // NOTE: If the timer started, it will stop and restart.
    void start()
    {
        VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
        timelineManager->startTimer(this);
    }
    
    // Stop the timer.
    // NOTE: If the timer does not started, it will do nothing.
    void stop()
    {
        VfxTimerManager *timelineManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
        timelineManager->stopTimer(this);
    }

// Override
protected:
    virtual void onDeinit();
    virtual void onTimer();
    virtual VfxMsec onGetDurationValue();

// Implementation
private:
    friend class VfxTimerManager;
	friend class VfxBaseTimeline;
    
    VfxFlag m_timerFlags;
    VfxMsec m_startDelay;
    
    // TODO: reduce one
    VfxObjListEntry *m_queuedListEntry;
    VfxObjListEntry *m_enabledListEntry;
    
    VfxMsec m_commitDuration;
    // The next absolute time to emit tick
    VfxMsec m_tickTime;
};


/***************************************************************************** 
 * Class VfxTimer
 *****************************************************************************/

/*
 * VfxTimer is used to start a timer.
 */
class VfxTimer : public VfxBaseTimer
{
public:
    VFX_DECLARE_CLASS(VfxTimer);

public:
    // Get current time.
    //
    // RETURNS: Current frame time in millisecond.
    static VfxMsec getCurrentTime();

    // Get current system time (not adjust by VRT)
    //
    // RETURNS: Current system time in millisecond.
    static VfxMsec getCurrentSystemTime();

    // Blocking MMI task until the given time
    static void blockUntil(
        VfxMsec absBlockTime    // the absolute time will block to
    );

// Constructor / Destructor
public:
    // Default constructor
    VfxTimer();

// Property
public:    
    // The interval time to emit signal, in mili-second. 
    //
    // NOTE: Default value is 0. 
    //  The value 0 means the timer will emit signal only one time.
    VfxMsec getDuration() const
    {
        return m_duration;
    }
    
    // SEE ALSO: VfxTimer::getDuration.
    void setDuration(VfxMsec value)
    {
        VFX_ASSERT(value >= 0);
        m_duration = value;
    }
    
// Signal
public:
    // Emit when time up.
    VfxSignal1 <VfxTimer *> m_signalTick;    

// Override
protected:
    virtual void onTimer();
    virtual VfxMsec onGetDurationValue();

// Implementation
private:
    VfxMsec m_duration;
};


/***************************************************************************** 
 * Class VfxSimpleTimer
 *****************************************************************************/

/*
 * VfxSimpleTimer is used to start a simple timer.
 */
class VfxSimpleTimer : public VfxBaseTimer
{
public:
    VFX_DECLARE_CLASS(VfxSimpleTimer);

// Constructor / Destructor
private:
    // Default constructor
    VfxSimpleTimer();

// Property
public: 
    // set callback function to emit timeout to app.
    void setCallback(const VfxCallback0 &callback)
    {
        VFX_ASSERT(callback.isValid());
        m_callback = callback;
    }

//Method
public:
    // Start the simple timer by VfxCallback0.
    //
    // NOTE: If the timer started, it will stop and restart.
    static void start(const VfxCallback0 &callback, VfxMsec time);
    
    // Stop the simple timer by VfxCallback0.
    // NOTE: If the timer does not started, it will do nothing.
    static void stop(const VfxCallback0 &callback);
    
    // Get tickTime of Simple Timer by VfxCallback0.
    static VfxMsec getTickTime(const VfxCallback0 &callback);

// Callback
private:
    friend class VfxTimerManager;
	
    //Emit when time out.
    VfxCallback0 m_callback;

// Override
protected:
    virtual void onTimer();
};

#endif /* __VFX_TIMER_H__ */

