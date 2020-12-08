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
 *  vcp_marquee.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Marquee Component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_marquee.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vrt_system.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_frame.h"
#include "vfx_font_desc.h"
#include "vfx_basic_type.h"


/***************************************************************************** 
 * Class VcpMarquee 
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("Marquee", VcpMarquee, VfxControl);


VcpMarquee::VcpMarquee() :    
    m_movableFrame(NULL),
    m_movableFrame2(NULL),
    m_scrollTimeline(NULL),
    m_scrollTimeline2(NULL),
    m_scrollTimeline3(NULL),    
    m_isScrolling(VFX_FALSE),      
    m_speed(VcpMarquee::DEFAULT_SPEED),
    m_loop(0),
    m_startDelay(VcpMarquee::DEFAULT_START_DELAY),
    m_direction(VcpMarquee::DIRECTION_NATURAL),
    m_scrollMode(VcpMarquee::SCROLL_MODE_STANDARD),
    m_halign(VcpMarquee::HALIGN_LEFT),
    m_valign(VcpMarquee::VALIGN_CENTER),
	m_autoResized(VFX_FALSE),
	m_scrollAlways(VFX_FALSE)
{
}


VfxS32 VcpMarquee::getSpeed() const
{
    return m_speed;
}


VfxS32 VcpMarquee::getLoop() const
{
    return m_loop;
}


VfxMsec VcpMarquee::getStartDelay() const
{
    return m_startDelay;
}


VcpMarquee::DirectionEnum VcpMarquee::getDirection() const
{
    return m_direction;
}


VcpMarquee::ScrollModeEnum VcpMarquee::getScrollMode() const
{
    return m_scrollMode;
}


VcpMarquee::HalignEnum VcpMarquee::getHalign() const
{
    return m_halign;
}


VcpMarquee::ValignEnum VcpMarquee::getValign() const
{
    return m_valign;
}


void VcpMarquee::setSpeed(VfxS32 value)
{
    m_speed = value;

    // This cannot be handled gracefully
    VFX_ASSERT(!m_isScrolling);
    
}


void VcpMarquee::setLoop(VfxS32 value)
{
    m_loop = value;

    // This cannot be handled gracefully
    VFX_ASSERT(!m_isScrolling);
    
}


void VcpMarquee::setStartDelay(VfxMsec value)
{
    m_startDelay = value;

    // This cannot be handled gracefully
    VFX_ASSERT(!m_isScrolling);
    
}


void VcpMarquee::setDirection(DirectionEnum value)
{
    m_direction = value;

    if (!m_isScrolling)
    {
        layoutMovableFrame();
    }    
}


void VcpMarquee::setScrollMode(ScrollModeEnum value)
{
    m_scrollMode = value;

    // This cannot be handled gracefully
    VFX_ASSERT(!m_isScrolling);    
}


void VcpMarquee::setHalign(HalignEnum value)
{
    m_halign = value;
    
    if (!m_isScrolling)
    {
        layoutMovableFrame();
    }
}


void VcpMarquee::setValign(ValignEnum value)
{
    m_valign = value;

    if (!m_isScrolling)
    {
        layoutMovableFrame();
    }    
}


VfxWString VcpMarquee::getText() const
{
    VfxTextFrame *text = VFX_OBJ_DYNAMIC_CAST(m_movableFrame,VfxTextFrame);

    if (text == NULL)
    {
        return VFX_WSTR_NULL;
    }

    return text->getString();
}


void VcpMarquee::onInit()
{
    VfxControl::onInit();
    
    // Bounds related
    m_signalBoundsChanged.connect(this, &VcpMarquee::onPropertyBoundsChanged);
}


void VcpMarquee::onDeinit()
{
    clearMovableFrame();

    VfxControl::onDeinit();
}


VfxS32 VcpMarquee::computeTimelineDuration(VfxS32 distance)
{
    return 1000 * VFX_ABS(distance) / getSpeed();
}


void VcpMarquee::startTimeline()
{
    if (m_isScrolling)
    {
        VFX_DEV_ASSERT(m_scrollTimeline != NULL);
        // Do nothing.
        return;
    }
    
    VFX_DEV_ASSERT(m_scrollTimeline == NULL);
    VFX_DEV_ASSERT(m_scrollTimeline2 == NULL);
    VFX_DEV_ASSERT(m_scrollTimeline3 == NULL);

    if (!needScroll())
    {
        // No need to scroll, do nothing.
        return;
    }

    m_isScrolling = VFX_TRUE;
        
    VFX_OBJ_CREATE(m_scrollTimeline, VfxS32Timeline, this);
    VFX_OBJ_CREATE(m_scrollTimeline2, VfxS32Timeline, this);
    VFX_OBJ_CREATE(m_scrollTimeline3, VfxS32Timeline, this);
    
    // Use timeline for scrolling animation is more complex than starting a timer in MMI task
    // However, it provides more smooth animation when the system loading is high.
    
    VfxS32 marquee_width = getMarqueeBounds().getWidth();
    VfxS32 movable_width = getMovableBounds().getWidth();

    VFX_OBJ_ASSERT_VALID(m_movableFrame);
    VFX_ASSERT(getSpeed() > 0 && movable_width > 0);

    if (getScrollMode() == SCROLL_MODE_STANDARD)
    {
        // Only setMovableFrame(VfxWString ...) is supported in SCROLL_MODE_STANDARD now
        VFX_OBJ_ASSERT_VALID(m_movableFrame2);
        m_movableFrame2->setHidden(VFX_FALSE); // show frame 2

        // There are three timelines:
        // Timeline 1: move frame 1 outside the marquee (loop once)
        // Timeline 2: move frame 2 after frame 1 (repeated loop)
        // Timeline 3: move frame 1 after frame 2 (repeated loop)
        // The display order will be controlled by timeline 1 -> 2 -> 3 -> 2 -> 3 -> 2 ...
        
        VfxS32 from_x1, to_x1, from_x2, to_x2, from_x3, to_x3;
        from_x1 = to_x1 = from_x2 = to_x2 = from_x3 = to_x3 = 0;
        // x position
        switch (getScrollDirection())
        {
            case DIRECTION_LEFT:
                from_x1 = 0;
                from_x2 = from_x3 = marquee_width;
                to_x1 = to_x2 = to_x3 = -movable_width;
                break;

            case DIRECTION_RIGHT: 
                from_x1 = marquee_width - movable_width;
                from_x2 = from_x3 = -movable_width;
                to_x1 = to_x2 = to_x3 = marquee_width;
                break;

            default:
                VFX_ASSERT(0);
                break;
        }     

        VfxS32 duration1, duration2, duration3;
        duration1 = computeTimelineDuration(from_x1 - to_x1);
        duration2 = computeTimelineDuration(from_x2 - to_x2);
        duration3 = computeTimelineDuration(from_x3 - to_x3);

        VfxS32 repeat_duration2, repeat_duration3;
        repeat_duration2 = repeat_duration3 = computeTimelineDuration((movable_width + DEFAULT_SCROLL_GAP) * 2);

        VfxS32 start_time1, start_time2, start_time3;
        start_time1 = getStartDelay();
		if (movable_width <  marquee_width)
		{
			start_time2 = start_time1 + computeTimelineDuration(movable_width); 
			start_time3 = start_time2 + computeTimelineDuration(marquee_width + movable_width);			
			//repeat_duration2 = computeTimelineDuration((marquee_width + marquee_width));
			repeat_duration2 = repeat_duration3 = computeTimelineDuration((marquee_width + movable_width) * 2);
		}
		else
		{
			start_time2 = start_time1 + computeTimelineDuration(movable_width + DEFAULT_SCROLL_GAP - marquee_width); 
			start_time3 = start_time2 + computeTimelineDuration(movable_width + DEFAULT_SCROLL_GAP);
		}
        

        // setup the timelines
        m_scrollTimeline->setTarget(m_movableFrame);
        m_scrollTimeline2->setTarget(m_movableFrame2);
        m_scrollTimeline3->setTarget(m_movableFrame);
        
        m_scrollTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_scrollTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);        
        m_scrollTimeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);        
        
        m_scrollTimeline->setFromValue(from_x1);
        m_scrollTimeline->setToValue(to_x1);
        m_scrollTimeline2->setFromValue(from_x2);
        m_scrollTimeline2->setToValue(to_x2);
        m_scrollTimeline3->setFromValue(from_x3);
        m_scrollTimeline3->setToValue(to_x3);
                
        m_scrollTimeline->setStartTime(start_time1);
        m_scrollTimeline2->setStartTime(start_time2);
        m_scrollTimeline3->setStartTime(start_time3);        
        
        m_scrollTimeline->setDurationTime(duration1);
        m_scrollTimeline2->setDurationTime(duration2);
        m_scrollTimeline3->setDurationTime(duration3);

        m_scrollTimeline2->setRepeatDuration(repeat_duration2);
        m_scrollTimeline3->setRepeatDuration(repeat_duration3);
        
        m_scrollTimeline->setIsFromCurrent(VFX_FALSE);
        m_scrollTimeline2->setIsFromCurrent(VFX_FALSE);
        m_scrollTimeline3->setIsFromCurrent(VFX_FALSE);
        
        m_scrollTimeline->setAutoReversed(VFX_FALSE);
        m_scrollTimeline2->setAutoReversed(VFX_FALSE);
        m_scrollTimeline3->setAutoReversed(VFX_FALSE);

        VfxS32 loop_count = getLoop();
        if (loop_count == 0)
        {
            m_scrollTimeline->setRepeatCount(2); /* walk around for the time line is removed when the frame is hidden */
            m_scrollTimeline->setRepeatDuration(0x0fffffff); /* walk around for the time line is removed when the frame is hidden */
            m_scrollTimeline2->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            m_scrollTimeline3->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

            // Setting stop callback in either timeline2 or timeline 3 is ok
            m_scrollTimeline2->m_signalStopped.connect(this, &VcpMarquee::onTimelineStop);
            
            // Start timeline
            m_scrollTimeline->start();
            m_scrollTimeline2->start();
            m_scrollTimeline3->start();            
        }
        else
        {
            loop_count--; // the first loop is handled in 1st timeline
            m_scrollTimeline->setRepeatCount(2); /* walk around for the time line is removed when the frame is hidden */
            m_scrollTimeline->setRepeatDuration(0x0fffffff); /* walk around for the time line is removed when the frame is hidden */
            m_scrollTimeline2->setRepeatCount((loop_count / 2) + (loop_count % 2));
            m_scrollTimeline3->setRepeatCount(loop_count / 2);

            if (loop_count == 0)
            {
                m_scrollTimeline->m_signalStopped.connect(this, &VcpMarquee::onTimelineStop);
            }
            else if (loop_count % 2)
            {
                m_scrollTimeline2->m_signalStopped.connect(this, &VcpMarquee::onTimelineStop);
            }
            else
            {
                m_scrollTimeline3->m_signalStopped.connect(this, &VcpMarquee::onTimelineStop);
            }

            m_scrollTimeline->start();
            if (loop_count >= 1)
            {
                m_scrollTimeline2->start();
            }
            if (loop_count >= 2)
            {
                m_scrollTimeline3->start();
            }
        }

    }
    else
    {    
        // loop count
        VfxS32 loop_count = getLoop();
        if (loop_count == 0)
        {
            loop_count = VFX_TIMELINE_REPEAT_INFINITE;
        }
        else if (getScrollMode() == SCROLL_MODE_ALTERNATE)
        {
            loop_count *= 2;
        }

        // x position
        VfxS32 from_x = 0, to_x = 0;
        switch (getScrollDirection())
        {
            case DIRECTION_LEFT:
                from_x = 0;
                to_x = marquee_width - movable_width; // negative
                break;

            case DIRECTION_RIGHT:
                from_x = marquee_width - movable_width; // negative
                to_x = 0;
                break;

            default:
                VFX_ASSERT(0);
                break;
        }

        VfxMsec duration = computeTimelineDuration(from_x - to_x);

        // setup the timeline
        m_scrollTimeline->setTarget(m_movableFrame);
        m_scrollTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        
        m_scrollTimeline->setFromValue(from_x);
        m_scrollTimeline->setToValue(to_x);
        
        m_scrollTimeline->setRepeatCount(loop_count);
        m_scrollTimeline->setStartTime(getStartDelay());
        m_scrollTimeline->setDurationTime(duration);
        m_scrollTimeline->setIsFromCurrent(VFX_FALSE);    
        if (getScrollMode() == SCROLL_MODE_ALTERNATE)
        {
            m_scrollTimeline->setAutoReversed(VFX_TRUE);
        }
        else
        {
            m_scrollTimeline->setAutoReversed(VFX_FALSE);
        }

        // Start timeline        
        m_scrollTimeline->m_signalStopped.connect(this, &VcpMarquee::onTimelineStop);
        m_scrollTimeline->start();
    }
}


void VcpMarquee::stopTimeline()
{
    if (!m_isScrolling)
    {
        // Do nothing
        return;
    }

    m_isScrolling = VFX_FALSE;    
    VFX_OBJ_CLOSE(m_scrollTimeline);
    VFX_OBJ_CLOSE(m_scrollTimeline2);
    VFX_OBJ_CLOSE(m_scrollTimeline3);
}


VcpMarquee::DirectionEnum VcpMarquee::getScrollDirection()
{
    DirectionEnum direction = (DirectionEnum)getDirection();
    if (direction == DIRECTION_NATURAL)
    {
        switch (vrt_sys_get_text_dir())
        {
            case MG_TEXT_DIR_TYPE_L2R:
                direction = DIRECTION_LEFT;
                break;

            case MG_TEXT_DIR_TYPE_R2L:
                direction = DIRECTION_RIGHT;
                break;

            default:
                VFX_ASSERT(0);
        }
    }

    return direction;
}


VcpMarquee::HalignEnum VcpMarquee::getHAlign()
{
    HalignEnum align_mode = (HalignEnum) getHalign();
    if (needScroll())
    {
        // Ignore the original align value; otherwise, it will jump abnormally
        switch (getScrollDirection())
        {
            case DIRECTION_LEFT:
                align_mode = HALIGN_LEFT;
                break;

            case DIRECTION_RIGHT:
                align_mode = HALIGN_RIGHT;
                break;

            default:
                VFX_ASSERT(0);
                break;
        }
    }
    else if (align_mode == HALIGN_NATURAL)
    {
        switch (vrt_sys_get_text_dir())
        {
            case MG_TEXT_DIR_TYPE_L2R:
                align_mode = HALIGN_LEFT;
                break;

            case MG_TEXT_DIR_TYPE_R2L:
                align_mode = HALIGN_RIGHT;
                break;

            default:
                VFX_ASSERT(0);
        }
    }

    return align_mode;
}


VfxBool VcpMarquee::needScroll()
{
   if (m_movableFrame && getMarqueeBounds().getWidth() > 0 && 
	   getIsScrollAlways())
   {
	   return VFX_TRUE;
   }
	
	if (m_movableFrame && getMarqueeBounds().getWidth() > 0 && 
        (getMarqueeBounds().getWidth() < getMovableBounds().getWidth()))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VcpMarquee::startScroll()
{
    startTimeline();
}


void VcpMarquee::stopScroll()
{
    stopTimeline();
}


void VcpMarquee::onTimelineStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    if (!isCompleted)
    {
        // Do nothing
        return;
    }
    
    stopTimeline();

    if (m_movableFrame2)
    {
        VFX_OBJ_ASSERT_VALID(m_movableFrame2);
        m_movableFrame2->setHidden(VFX_TRUE); // hide frame 2
    }

    layoutMovableFrame();

    m_signalScrollFinished.postEmit(this);
}


void VcpMarquee::clearMovableFrame()
{
    stopScroll();

    VFX_OBJ_CLOSE(m_movableFrame);
    VFX_OBJ_CLOSE(m_movableFrame2);    

}

void VcpMarquee::setMovableFrame(const VfxWChar *text, const VfxFontDesc &font)
{
    setMovableFrame(VFX_WSTR_MEM(text), font);
}

void VcpMarquee::setMovableFrame(const VfxResId resId, const VfxFontDesc &font)
{
    setMovableFrame(VFX_WSTR_RES(resId), font);
}

void VcpMarquee::setMovableFrame(const VfxWString &text, const VfxFontDesc &font)
{
    // Create frame
    VfxTextFrame *text_frame;
    VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
    text_frame->setString(text);
    text_frame->setFont(font);
    text_frame->forceUpdate();

    VfxTextFrame *text_frame2;
    VFX_OBJ_CREATE(text_frame2, VfxTextFrame, this);
    text_frame2->setString(text);
    text_frame2->setFont(font);
    text_frame2->forceUpdate();

    setMovableFrame((VfxFrame *) text_frame, (VfxFrame *) text_frame2);
}


void VcpMarquee::setTextColor(const VfxColor &textColor)
{
    VfxTextFrame *textFrame = VFX_OBJ_DYNAMIC_CAST(m_movableFrame, VfxTextFrame);
    if (textFrame != NULL)
    {
        textFrame->setColor(textColor);
    }

    VfxTextFrame *textFrame2 = VFX_OBJ_DYNAMIC_CAST(m_movableFrame2, VfxTextFrame);
    if (textFrame2 != NULL)
    {
        textFrame2->setColor(textColor);
    }
}


void VcpMarquee::setTextColor(const VfxColor &textColor, const VfxColor &borderColor)
{
    VfxTextFrame *textFrame = VFX_OBJ_DYNAMIC_CAST(m_movableFrame, VfxTextFrame);
    if (textFrame != NULL)
    {
        textFrame->setColor(textColor);
        textFrame->setBorderColor(borderColor);
    }

    VfxTextFrame *textFrame2 = VFX_OBJ_DYNAMIC_CAST(m_movableFrame2, VfxTextFrame);
    if (textFrame2 != NULL)
    {
        textFrame2->setColor(textColor);
        textFrame2->setBorderColor(borderColor);
    }
}

void VcpMarquee::setMovableFrame(VfxFrame *frame, VfxFrame *frame2)
{
    clearMovableFrame();

    VFX_OBJ_ASSERT_VALID(frame);
	addChildFrame(frame);
    
    m_movableFrame = frame;

    if (frame2)
    {
        VFX_OBJ_ASSERT_VALID(frame2);
        //frame2->setParent(this);
		addChildFrame(frame2);
        frame2->setHidden(VFX_TRUE); // hide by default
        m_movableFrame2 = frame2;
    }
    
    layoutMovableFrame();
}


void VcpMarquee::layoutMovableFrame()
{
    if (!m_movableFrame)
    {
        return;
    }
    
	if (m_autoResized && getMovableBounds().getHeight() > getMarqueeBounds().getHeight())
	{
		this->setSize(getMarqueeBounds().getWidth(), getMovableBounds().getHeight());
	}
    
    VfxPoint pt;

    switch (getHAlign())
    {
        case HALIGN_LEFT:
            pt.x = 0;
            break;
        
        case HALIGN_CENTER:
            pt.x = (getMarqueeBounds().getWidth() - getMovableBounds().getWidth()) / 2;
            break;
            
        case HALIGN_RIGHT:
            pt.x = getMarqueeBounds().getWidth() - getMovableBounds().getWidth();
            break;

        default:
            VFX_ASSERT(0);
    }

    switch (getValign())
    {
        case VALIGN_TOP:
            pt.y = 0;
            break;
        
        case VALIGN_CENTER:
            pt.y = (getMarqueeBounds().getHeight() - getMovableBounds().getHeight()) / 2;
            break;
            
        case VALIGN_BOTTOM:
            pt.y = getMarqueeBounds().getHeight() - getMovableBounds().getHeight();
            break;

        default:
            VFX_ASSERT(0);
    }

    m_movableFrame->setPos(pt);
    if (m_movableFrame2)
    {
        pt.x = getMarqueeBounds().getWidth(); // move outside the marquee
        m_movableFrame2->setPos(pt);
    }
}


void VcpMarquee::onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    
    if (m_isScrolling)
    {
        // The scrolling scenario is changed
        stopScroll();
		layoutMovableFrame();
        startScroll();
    }
    else
    {
        layoutMovableFrame();
    }
}

