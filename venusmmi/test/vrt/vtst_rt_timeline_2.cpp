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
 * Timeline Test Implementation
 *****************************************************************************/

class VtstRtTimeline : public VtstRtScr
{
// Variable
public:
    VfxAnimation    *m_animation;
    VfxAnimation    *m_animation2;

// Constructor / Destructor
public:
    VtstRtTimeline() : m_animation(NULL), m_animation2(NULL) {}

// Override
protected:
    virtual void onInit()
    {
        VfxFrame *m_controlRect;

        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Timeline Test"));

        // Create a color rectangle
        VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
        m_controlRect->setPos(VfxPoint(120, 100));
        m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
        m_controlRect->setAnchor(VfxFPoint(0.5, 0.5));
        m_controlRect->setBgColor(VFX_COLOR_RED);
        m_controlRect->setAutoAnimate(VFX_TRUE);    

        // Create an animation with one timeline
        VFX_OBJ_CREATE(m_animation, VfxAnimation, this);

        VfxFloatTimeline *timeline1;
        VFX_OBJ_CREATE(timeline1, VfxFloatTimeline, m_animation);
        timeline1->setTarget(m_controlRect);
        timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        timeline1->setFromValue(1.0f);
        timeline1->setToValue(0.0f);
        timeline1->setDurationTime(2000);
        timeline1->setRepeatCount(1000);
        timeline1->setAutoReversed(VFX_TRUE);

        // Create a color rectangle
        VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
        m_controlRect->setPos(VfxPoint(120, 250));
        m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
        m_controlRect->setAnchor(VfxFPoint(0.5, 0.5));
        m_controlRect->setBgColor(VFX_COLOR_RED);
        m_controlRect->setAutoAnimate(VFX_TRUE);    

        // Create an animation with one timeline
        VFX_OBJ_CREATE(m_animation2, VfxAnimation, this);

        VfxColorTimeline *timeline2;
        VFX_OBJ_CREATE(timeline2, VfxColorTimeline, m_animation2);
        timeline2->setTarget(m_controlRect);
        timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
        timeline2->setFromValue(VFX_COLOR_RED);
        timeline2->setToValue(getBgColor());
        timeline2->setDurationTime(2000);
        timeline2->setRepeatCount(1000);
        timeline2->setAutoReversed(VFX_TRUE);
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        if (idx == 0)
        {                    
             return 0;
        }
        else if (idx == 1)
        {
             m_animation->start();
             m_animation2->start();
             confirm(VFX_WSTR("Result is correct?"));
             return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};


VtstTestResultEnum vtst_rt_timeline(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimeline);
    return VTST_TR_OK;
}


/***************************************************************************** 
 * Timeline Timing function Test Implementation
 *****************************************************************************/

class VtstRtTimelineTiming : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_rect[6];
    VfxPointTimeline *m_timelineRect[6];
    VfxFrame *m_target2[6];

// Constructor / Destructor
public:
    VtstRtTimelineTiming()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Time function test"));
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
            m_timelineRect[i]->setStartDelay(500);
            m_timelineRect[i]->setDurationTime(4000);
            m_timelineRect[i]->setRepeatCount(10);
            m_timelineRect[i]->setAutoReversed(VFX_FALSE);
            m_timelineRect[i]->setFromValue(VfxPoint(10, 50 + 40 * i));
            m_timelineRect[i]->setToValue(VfxPoint(150, 50 + 40 * i));
            
           
            VFX_OBJ_CREATE(m_target2[i], VfxFrame, this);
            m_target2[i]->setRect(VfxRect(150, 50 + 40 * i, 30, 30));
            m_target2[i]->setBorderColor(VFX_COLOR_RED);
            m_target2[i]->setBorderWidth(1);
        }    
        m_timelineRect[0]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_timelineRect[1]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
        m_timelineRect[2]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
        m_timelineRect[3]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_timelineRect[4]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_timelineRect[5]->setTimingFunc(VFX_TIMING_FUNC_ID_DAMPING_OUT);
        

        for (i = 0; i < 6; i++)
        {
            m_timelineRect[i]->start();
        }
        return 1;
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    { 
        confirm(VFX_WSTR("Timing Ok?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_timeline_timing(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTimelineTiming);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

