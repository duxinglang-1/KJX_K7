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
 *  vtst_rt_timeline.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for timeline
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
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vrt_canvas.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_app_cat_scr.h"
#include "vfx_timer.h"


/***************************************************************************** 
 * Timeline Create Test Implementation
 *****************************************************************************/

class VtstRtTimelineCreate : public VtstRtScr
{
// Variable
public:
    VfxFrame           *m_frame0;
    VfxPointTimeline   *m_timeline0;
    VfxFrame           *m_frame1;
    VfxPointTimeline   *m_timeline1a;
    VfxColorTimeline   *m_timeline1b;
    VfxFrame           *m_frame2;
    VfxPointTimeline   *m_timeline2a;
    VfxColorTimeline   *m_timeline2b;

// Constructor / Destructor
public:
    VtstRtTimelineCreate() : 
        m_frame1(NULL), 
        m_timeline1a(NULL),
        m_timeline1b(NULL),
        m_frame2(NULL), 
        m_timeline2a(NULL),
        m_timeline2b(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        // Frame #0 (test duration 0)
        VFX_OBJ_CREATE(m_frame0, VfxFrame, this);
        m_frame0->setRect(130, 30, 50, 50);
        m_frame0->setBgColor(VFX_COLOR_RED);
        
        VFX_OBJ_CREATE(m_timeline0, VfxPointTimeline, this);
        m_timeline0->setToValue(VfxPoint(130, 100));
        m_timeline0->setDuration(0);
        m_timeline0->m_signalStopped.connect(this, &VtstRtTimelineCreate::onTimeline0Stopped);

        // Frame #1
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setRect(VfxRect(30, 30, 50, 50));
        m_frame1->setBgColor(VFX_COLOR_RED);
        
        VFX_OBJ_CREATE(m_timeline1a, VfxPointTimeline, this);
        m_timeline1a->setFromValue(VfxPoint(30, 30));
        m_timeline1a->setToValue(VfxPoint(30, 100));
        m_timeline1a->setDuration(1000);

        VFX_OBJ_CREATE(m_timeline1b, VfxColorTimeline, this);
        m_timeline1b->setFromValue(VFX_COLOR_RED);
        m_timeline1b->setToValue(VFX_COLOR_YELLOW);
        m_timeline1b->setDuration(500);
        m_timeline1b->setAutoReversed(VFX_TRUE);
        m_timeline1b->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);

        // Frame #2 in different sequence
        VFX_OBJ_CREATE(m_timeline2b, VfxColorTimeline, this);
        m_timeline2b->setFromValue(VFX_COLOR_RED);
        m_timeline2b->setToValue(VFX_COLOR_YELLOW);
        m_timeline2b->setDuration(500);
        m_timeline2b->setAutoReversed(VFX_TRUE);
        m_timeline2b->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);
        
        VFX_OBJ_CREATE(m_timeline2a, VfxPointTimeline, this);
        m_timeline2a->setFromValue(VfxPoint(80, 30));
        m_timeline2a->setToValue(VfxPoint(80, 100));
        m_timeline2a->setDuration(1000);
        m_timeline2a->setAutoReversed(VFX_TRUE);
        m_timeline2a->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setRect(VfxRect(80, 30, 50, 50));
        m_frame2->setBgColor(VFX_COLOR_RED);
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch(idx)
        {
            case 0:
                // Start timeline #0
                m_timeline0->setTarget(m_frame0);
                m_timeline0->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                m_timeline0->start();
                return -1;

            case 1:
                return -1;
        }        
        return 0;
    }

    void startTimelines()
    {
        // Start in differenct sequence
        m_timeline1a->setTarget(m_frame1);
        m_timeline1a->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_timeline1a->m_signalStopped.connect(this, &VtstRtTimelineCreate::onTimeline1aStopped);
        m_timeline1a->start();

        m_timeline2b->setTarget(m_frame2);
        m_timeline2b->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
        m_timeline2b->start();
        
        m_timeline2a->setTarget(m_frame2);
        m_timeline2a->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_timeline2a->start();

        m_timeline1b->setTarget(m_frame1);
        m_timeline1b->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
        m_timeline1b->start();
    }

    void onTimeline0Stopped(VfxBaseTimeline *source, VfxBool isComplete)
    {
        check(isComplete, VFX_WSTR("Timeline dur=0"));

        startTimelines();
        
        endPhase();
    }

    void onTimeline1aStopped(VfxBaseTimeline *source, VfxBool isComplete)
    {
        check(isComplete, VFX_WSTR("Timeline #1"));
        
        endPhase();
    }
};


VtstTestResultEnum vtst_rt_timeline_create(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineCreate);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Timeline Target Test Implementation
 *****************************************************************************/

class VtstRtTimelineTarget : public VtstRtScr
{
// Variable
public:
    VfxFrame           *m_frame;
    VfxPointTimeline   *m_timeline;
    VfxTimer           *m_timer;

// Constructor / Destructor
public:
    VtstRtTimelineTarget() : 
        m_frame(NULL), 
        m_timeline(NULL),
        m_timer(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(30, 30, 50, 50);
        m_frame->setBgColor(VFX_COLOR_RED);
        
        VFX_OBJ_CREATE(m_timeline, VfxPointTimeline, this);
        m_timeline->setTarget(m_frame);
        m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_timeline->setFromValue(VfxPoint(30, 30));
        m_timeline->setToValue(VfxPoint(30, 100));
        m_timeline->setDuration(1000);
        m_timeline->setAutoReversed(VFX_TRUE);
        m_timeline->setRepeatCount(VRT_TIMELINE_REPEAT_INFINITE);

        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        m_timer->setStartDelay(200);
        m_timer->setDuration(200);
        m_timer->m_signalTick.connect(this, &VtstRtTimelineTarget::onTimerTick);
    }

    virtual int start()
    {
        m_timeline->start();
        m_timer->start();
        
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("Result is correct?"));
        return -1;
    }
    
// Slot
protected:
    void onTimerTick(VfxTimer *source)
    {
        m_frame->setHidden(!m_frame->getHidden());
    }
};


VtstTestResultEnum vtst_rt_timeline_target(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineTarget);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Timeline Sync Test Implementation
 *****************************************************************************/

class VtstRtTimelineSync : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_rect[6];
    VfxPointTimeline *m_timelineRect[6];
    VfxFrame *m_target[6];
    VfxPointTimeline *m_timelineTarget[6];
    VfxFrame *m_target2[6];

// Constructor / Destructor
public:
    VtstRtTimelineSync()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Testing..."));
    }

    virtual int start()
    {
        VfxS32 i;
        for (i = 0; i < 6; i++)
        {
            VFX_OBJ_CREATE(m_rect[i], VfxFrame, this);
            m_rect[i]->setRect(VfxRect(10, 50 + 40 * i, 30, 30));
            m_rect[i]->setBgColor(VFX_COLOR_YELLOW);
            
            VFX_OBJ_CREATE(m_timelineRect[i], VfxPointTimeline, this);
            m_timelineRect[i]->setTarget(m_rect[i]);
            m_timelineRect[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
            m_timelineRect[i]->setStartDelay(i * 500);
            m_timelineRect[i]->setDurationTime(500);
            m_timelineRect[i]->setRepeatCount(2);
            m_timelineRect[i]->setAutoReversed(VFX_TRUE);
            m_timelineRect[i]->setFromValue(VfxPoint(10, 50 + 40 * i));
            m_timelineRect[i]->setToValue(VfxPoint(200, 50 + 40 * i));
            
            VFX_OBJ_CREATE(m_target[i], VfxFrame, this);
            m_target[i]->setRect(VfxRect(10, 50 + 40 * i, 30, 30));
            m_target[i]->setBorderColor(VFX_COLOR_RED);
            m_target[i]->setBorderWidth(1);
            
            VFX_OBJ_CREATE(m_timelineTarget[i], VfxPointTimeline, this);
            m_timelineTarget[i]->setTarget(m_target[i]);
            m_timelineTarget[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
            m_timelineTarget[i]->setStartDelay(i * 500);
            m_timelineTarget[i]->setDurationTime(500);
            m_timelineTarget[i]->setRepeatCount(2);
            m_timelineTarget[i]->setAutoReversed(VFX_TRUE);
            m_timelineTarget[i]->setFromValue(VfxPoint(10, 50 + 40 * i));
            m_timelineTarget[i]->setToValue(VfxPoint(200, 50 + 40 * i));

            VFX_OBJ_CREATE(m_target2[i], VfxFrame, this);
            m_target2[i]->setRect(VfxRect(10 + 20 * i, 50 + 40 * i, 30, 30));
            m_target2[i]->setBorderColor(VFX_COLOR_RED);
            m_target2[i]->setBorderWidth(1);
            m_target2[i]->setHidden(VFX_TRUE);
        }        
        return 3;
    }

    VfxS32 phase0()
    {
        VfxS32 i;
        for (i = 0; i < 6; i++)
        {
            m_timelineRect[i]->start();
            m_timelineTarget[i]->start();
        }        
        return 3000;
    }

    VfxS32 phase1()
    {
        VfxS32 i;
        for (i = 0; i < 6; i++)
        {
            m_rect[i]->setPos(VfxPoint(10 + 20 * i, 50 + 40 * i));
        }        
        return 1000;
    }
    
    VfxS32 phase2()
    {
        VfxS32 i;
        for (i = 0; i < 6; i++)
        {
            VFX_OBJ_CLOSE(m_timelineRect[i]);

            m_target[i]->setHidden(VFX_TRUE);
            m_target2[i]->setHidden(VFX_FALSE);
        }        
        setTitle(VFX_WSTR("Done"));
        confirm(VFX_WSTR("Yellow blocks in red boxes?"));
        return -1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    { 
        VfxS32 ret = 0;
        
        switch (idx)
        {
            case 0:
                ret = phase0();
                break;
                
            case 1:
                ret = phase1();
                break;

            case 2:
                ret = phase2();
                break;
        }
        
        return ret;
    }
};


VtstTestResultEnum vtst_rt_timeline_sync(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineSync);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

