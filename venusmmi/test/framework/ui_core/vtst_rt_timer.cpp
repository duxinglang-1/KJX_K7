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
 *  vtst_rt_timer.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for timer
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_timer.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_draw_context.h"
#include "vfx_app_cat_scr.h"
#include "vfx_context.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_auto_animate.h"


/***************************************************************************** 
 * Timer Test Implementation
 *****************************************************************************/

class VtstRtTimer : public VtstRtScr
{
// Variable
public:
    VfxTimer   *m_timer;
    VfxS32      m_tickCount;

    VfxTimer   *m_timerOnce;
    VfxS32      m_timerOnceCount;
    
    VfxTimer   *m_timerMax1;
    VfxTimer   *m_timerMax2;
    VfxS32      m_timerMax2Count;
    
    VfxTimer   *m_timerOrder0;
    VfxTimer   *m_timerOrder1;
    VfxTimer   *m_timerOrder2;
    VfxS32      m_tickOrder;

    VfxTimer   *m_timerZero;
    VfxS32      m_timerZeroOrder;

    VfxTimer   *m_timerCancel1;
    VfxTimer   *m_timerCancel2;

// Constructor / Destructor
public:
    VtstRtTimer() : m_tickCount(0), m_tickOrder(0), m_timerZeroOrder(0)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Timer Test"));
        
        // Interval Timer
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(100);
        m_timer->setDuration(100);
        m_timer->m_signalTick.connect(this, &VtstRtTimer::onTimerTick);

        // Once Timer 
        VFX_OBJ_CREATE(m_timerOnce, VfxTimer, this);
        m_timerOnce->setStartDelay(300);
        m_timerOnce->m_signalTick.connect(this, &VtstRtTimer::onTimerOnceTick);
        m_timerOnceCount = 3;
        
        // Max Timers
        VFX_OBJ_CREATE(m_timerMax1, VfxTimer, this);
        m_timerMax1->setStartDelay(0x7fffffff);
        m_timerMax1->m_signalTick.connect(this, &VtstRtTimer::onTimerMax1Tick);
        
        VFX_OBJ_CREATE(m_timerMax2, VfxTimer, this);
        m_timerMax2->setStartDelay(50);
        m_timerMax2->setDuration(0x7fffffff);
        m_timerMax2->m_signalTick.connect(this, &VtstRtTimer::onTimerMax2Tick);
        m_timerMax2Count = 5;

        // Test Timers Order
        VFX_OBJ_CREATE(m_timerOrder0, VfxTimer, this);
        m_timerOrder0->setStartDelay(100);
        m_timerOrder0->setDuration(200);
        m_timerOrder0->m_signalTick.connect(this, &VtstRtTimer::onTimerOrderTick);

        VFX_OBJ_CREATE(m_timerOrder2, VfxTimer, this);
        m_timerOrder2->setStartDelay(100);
        m_timerOrder2->setDuration(200);
        m_timerOrder2->m_signalTick.connect(this, &VtstRtTimer::onTimerOrderTick);

        VFX_OBJ_CREATE(m_timerOrder1, VfxTimer, this);
        m_timerOrder1->setStartDelay(100);
        m_timerOrder1->setDuration(200);
        m_timerOrder1->m_signalTick.connect(this, &VtstRtTimer::onTimerOrderTick);

        // Test Timer with 0 start delay
        VFX_OBJ_CREATE(m_timerZero, VfxTimer, this);
        m_timerZero->setStartDelay(0);
        m_timerZero->m_signalTick.connect(this, &VtstRtTimer::onTimerZeroTick);
        m_timerZeroOrder = 100;

        // m_timerCancel1 will cancel m_timerCancel2
        VFX_OBJ_CREATE(m_timerCancel1, VfxTimer, this);
        m_timerCancel1->setStartDelay(400);
        m_timerCancel1->m_signalTick.connect(this, &VtstRtTimer::onTimerCancel1Tick);

        VFX_OBJ_CREATE(m_timerCancel2, VfxTimer, this);
        m_timerCancel2->setStartDelay(400);
        m_timerCancel2->m_signalTick.connect(this, &VtstRtTimer::onTimerCancel2Tick);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        
        m_timer->start();
        m_timerOnce->start();
        m_timerMax1->start();
        m_timerMax2->start();
        m_timerOrder0->start();
        m_timerOrder1->start();
        m_timerOrder2->start();
        m_timerZero->start();
        m_timerCancel1->start();
        m_timerCancel2->start();
        
        m_timerZeroOrder = 200;
        invalidate();
        
        return 1000;
    }

    virtual void end()
    {
        check(m_tickCount > 7, VFX_WSTR("Tick Count"));
        check(m_timerZeroOrder >= 300, VFX_WSTR("Zero Timer #2"));
    }

    virtual void onDraw(VfxDrawContext &dc)
    {
        VFX_UNUSED(dc);

        m_timerZeroOrder++;
    }

// Slot
protected:
    void onTimerTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        VfxWString str;
        str.format("Get Tick: %d", m_tickCount);
        setStatus(str);
        m_tickCount ++;
        
    }

    void onTimerOnceTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        // Only the first time will be emit
        check(m_timerOnceCount == 3, VFX_WSTR("Timer Once"));
        m_timerOnceCount++;
    }
    
    void onTimerMax1Tick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        // Should not emit
        check(0, VFX_WSTR("Max Timer #1"));
    }

    void onTimerMax2Tick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        // Only the first time will be emit
        check(m_timerMax2Count == 5, VFX_WSTR("Max Timer #2"));
        m_timerMax2Count++;
    }
    
    void onTimerOrderTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        if (source == m_timerOrder0)
        {
            check(m_tickOrder == 0, VFX_WSTR("Order Timer #0"));
            m_tickOrder = 1;
        }
        else if (source == m_timerOrder1)
        {
            check(m_tickOrder == 1, VFX_WSTR("Order Timer #1"));
            m_tickOrder = 2;
        }
        else if (source == m_timerOrder2)
        {
            check(m_tickOrder == 2, VFX_WSTR("Order Timer #2"));
            m_tickOrder = 0;
        }
        else
        {
            check(0, VFX_WSTR("Unknown timer"));
        }
    }

    void onTimerZeroTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        check(m_timerZeroOrder == 201, VFX_WSTR("Zero Timer #1"));

        m_timerZeroOrder = 300;
    }

    void onTimerCancel1Tick(VfxTimer *source)
    {
        VFX_UNUSED(source);

        m_timerCancel2->stop();        
    }

    void onTimerCancel2Tick(VfxTimer *source)
    {
        VFX_UNUSED(source);

        // m_timerCancel2 should be canceled by m_timerCancel1
        check(0, VFX_WSTR("Timer Cancel #1"));
    }    
};


VtstTestResultEnum vtst_rt_timer(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtTimer);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Timer Switch Test Implementation
 *****************************************************************************/

class VtstRtTimerSwitch : public VtstRtScr
{
// Variable
public:
    VfxContext *m_context;
    
    VfxS32      m_timerCount;
    VfxTimer   *m_timer;

    VfxTimer   *m_timerNoise1;
    VfxTimer   *m_timerNoise2;

// Constructor / Destructor
public:
    VtstRtTimerSwitch() : 
        m_context(NULL),
        m_timerCount(0),
        m_timer(NULL),         
        m_timerNoise1(NULL),
        m_timerNoise2(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setTitle(VFX_WSTR("Timer Switch"));
        
        // Leave VRT and Re-entry
        m_context = VtstRtScr::getContext();
        check(m_context != NULL, VFX_WSTR("Check context"));
        
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(150);
        m_timer->setDuration(150);
        m_timer->m_signalTick.connect(this, &VtstRtTimerSwitch::onTimerTick);

        VFX_OBJ_CREATE(m_timerNoise1, VfxTimer, this);
        m_timerNoise1->setStartDelay(100);
        m_timerNoise1->setDuration(100);
        m_timerNoise1->m_signalTick.connect(this, &VtstRtTimerSwitch::onTimerNoiseTick);

        VFX_OBJ_CREATE(m_timerNoise2, VfxTimer, this);
        m_timerNoise2->setStartDelay(100);
        m_timerNoise2->setDuration(100);
        m_timerNoise2->m_signalTick.connect(this, &VtstRtTimerSwitch::onTimerNoiseTick);
    }

    virtual int start()
    {
        m_timerNoise1->start();
        
        m_timerCount = 101;
        m_timer->start();
        
        m_timerNoise2->start();
        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        VFX_UNUSED(idx);
        
        return 500;
    }

    virtual void end()
    {
        check(m_timerCount == 102, VFX_WSTR("Timer Switch #2"));
    }

// Slot
protected:
    void onTimerTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        // Should be callbacked only one time
        check(m_timerCount == 101, VFX_WSTR("Timer Switch #1"));
        
        m_timer->stop();

        m_timerCount++;

        leaveCanvas();
        entryCanvas(m_context);
        //EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        //GoBackHistory();
    }

    void onTimerNoiseTick(VfxTimer *source)
    {
        VFX_UNUSED(source);

        // Do nothing
    }
};


VtstTestResultEnum vtst_rt_timer_switch(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtTimerSwitch);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Timeline and Timer Test Implementation
 *****************************************************************************/

class VtstRtTimelineTimer : public VtstRtScr
{
// Variable
public:
    VfxFrame           *m_box0;
    VfxFrame           *m_box1;
    VfxFrame           *m_frame;
    VfxTimer           *m_timer;
    VfxS32              m_tickCount;

// Constructor / Destructor
public:
    VtstRtTimelineTimer() : m_tickCount(0) 
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        VFX_OBJ_CREATE(m_box0, VfxFrame, this);
        m_box0->setRect(VfxRect(10, 50, 30, 30));
        m_box0->setBgColor(VFX_COLOR_RED);

        VFX_OBJ_CREATE(m_box0, VfxFrame, this);
        m_box0->setRect(VfxRect(170, 50, 30, 30));
        m_box0->setBgColor(VFX_COLOR_RED);

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(VfxRect(100, 50, 30, 30));
        m_frame->setBgColor(VFX_COLOR_YELLOW);
        m_frame->setAutoAnimate(VFX_TRUE);

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setDuration(2000);
        m_timer->m_signalTick.connect(this, &VtstRtTimelineTimer::onTimerTick);
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
        VFX_UNUSED(idx);
        
        if (idx == 0)
        {
            setTitle(VFX_WSTR("VRT Timer Test #1"));
            m_timer->setStartDelay(1000);
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(1000);
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
            m_frame->setPos(VfxPoint(10, 50));
            VfxAutoAnimate::commit();
        }
        else
        {
            setTitle(VFX_WSTR("VRT Timer Test #2"));
            m_timer->setStartDelay(0);
        }
        
        m_timer->start();
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }

// Slot
protected:
    void onTimerTick(VfxTimer *source)
    {
        VFX_UNUSED(source);
        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(2000);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
            
        if (m_tickCount & 0x1)
        {
            m_frame->setPos(VfxPoint(10, 50));
        }
        else
        {
            m_frame->setPos(VfxPoint(170, 50));
        }

        VfxAutoAnimate::commit();

        m_tickCount++;
    }
};


VtstTestResultEnum vtst_rt_vrt_timer(VfxU32 param)
{
    VFX_UNUSED(param);
    VTST_START_SCRN(VtstRtTimelineTimer);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

