/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_bubble_effect.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

#include "vcp_bubble_effect.h"
#include "mmi_rp_srv_venus_component_bubble_effect_def.h"
#include "stdlib.h"     // rand


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * VappLockParticleSystem Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpBubbleEffect", VcpBubbleEffect, VfxFrame);


VcpBubbleEffect::VcpBubbleEffect() 
    : m_isStop(VFX_TRUE),
    m_explodeTimer(NULL),
    m_isInverse(VFX_FALSE),
    m_thresholdY(0),
    m_bubbleCount(VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM),
    m_isSuspendEject(VFX_FALSE)
{  
   initInternal();
}

void VcpBubbleEffect::initInternal()
{
	VfxS32 i;
    for(i=0; i < m_bubbleCount; i++)
    {
        m_watchFrame[i] = NULL;
        m_watchFramesXTimeline[i] = NULL;
        m_watchFramesYTimeline[i] = NULL;
        m_watchFramesLevelTimeline[i] = NULL;
        m_watchFramesVibrationTimeline[i] = NULL;
        m_watchFramesEXTimeline[i] = NULL;
    }
}


VcpBubbleEffect::VcpBubbleEffect(VfxS32 bubbleCount) 
    : m_isStop(VFX_TRUE),
    m_explodeTimer(NULL),
    m_isInverse(VFX_FALSE),
    m_thresholdY(0)
{  
    m_bubbleCount = bubbleCount;
	initInternal();
    
}


void VcpBubbleEffect::onInit()
{

    VfxFrame::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);
    //setBgColor(VFX_COLOR_BLACK);

    VfxS32 i;
    for(i=0; i<m_bubbleCount; i++)
    {
        VFX_OBJ_CREATE(m_watchFrame[i], VfxFrame, this);
        m_watchFrame[i]->setOpacity(0);
        m_watchFrame[i]->setSize(1, 1);
        // store id in bordWidth;
        m_watchFrame[i]->setBorderWidth(i);
        
        VFX_OBJ_CREATE(m_particle[i], VfxImageFrame, this);
        m_particle[i]->setResId(IMG_ID_VCP_BUBBLE_EFFECT_DOT);
        m_particle[i]->setAnchor(0.5, 0.5);
        m_particle[i]->setOpacity(0);
        //m_particle[i]->setHints(VFX_FRAME_HINTS_SW_LINEARTRANSFORM);

        // create X time line for shift
        VFX_OBJ_CREATE(m_watchFramesXTimeline[i], VfxS32Timeline, this);
        m_watchFramesXTimeline[i]->setTarget(m_watchFrame[i]);
        m_watchFramesXTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_watchFramesXTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR); 
        m_watchFramesXTimeline[i]->setDurationTime(500);

    }

    VFX_OBJ_CREATE(m_top, VfxImageFrame, this);
    m_top->setResId(IMG_ID_VCP_BUBBLE_EFFECT_TOP);
    m_top->setAnchor(0.5, 0);
    m_top->setHidden(VFX_TRUE);
    

    VFX_OBJ_CREATE(m_top2, VfxImageFrame, this);
    m_top2->setResId(IMG_ID_VCP_BUBBLE_EFFECT_TOP_2);
    m_top2->setAnchor(0.5, 0);
    m_top2->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_ballMother, VfxFrame, this);
    
    VFX_OBJ_CREATE(m_ball, VfxImageFrame, m_ballMother);
    m_ball->setResId(IMG_ID_VCP_BUBBLE_EFFECT_BALL);
    //m_ball->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
    
    m_ballMother->setSize((VfxS32)(m_ball->getSize().width * 1.11f), (VfxS32)(m_ball->getSize().height * 1.11f));
    m_ballMother->setAnchor(0.5, 0.5);
    m_ballMother->setHidden(VFX_TRUE);
    //m_ballMother->setHints(VFX_FRAME_HINTS_SW_OVERLAY);
    
    // ball timeline;
    VFX_OBJ_CREATE(m_ballSizeTimeline, VfxTransformTimeline, this);
    m_ballSizeTimeline->setTarget(m_ball);
    m_ballSizeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_ballSizeTimeline->setDurationTime(500);
    m_ballSizeTimeline->setAutoReversed(VFX_TRUE);
    m_ballSizeTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

    //m_isInverse = VFX_TRUE;
    
}

void VcpBubbleEffect::initBubble(VfxS32 index)
{
    // init x by m_startPoint;
    m_watchFrame[index]->setPos(m_endPoint);
    m_watchFrame[index]->setBounds(m_startPoint.x, m_startPoint.y, 1, 1);
    
    // init y timeline of watchFrame
    VFX_OBJ_CLOSE(m_watchFramesYTimeline[index]);
    VFX_OBJ_CREATE(m_watchFramesYTimeline[index], VfxS32Timeline, this);
    m_watchFramesYTimeline[index]->setTarget(m_watchFrame[index]);
    m_watchFramesYTimeline[index]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
    m_watchFramesYTimeline[index]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_watchFramesYTimeline[index]->m_signalStopped.connect(this, &VcpBubbleEffect::reejectBubble);

    VfxS32 dur, startDelay; 
    startDelay = 2400 * (rand()%m_bubbleCount)/m_bubbleCount;
    dur = 1400 + 1000 * index / m_bubbleCount;
    m_watchFramesYTimeline[index]->setStartDelay(startDelay);
    m_watchFramesYTimeline[index]->setDurationTime(dur);
    m_watchFramesYTimeline[index]->setFromValue(m_startPoint.y);
    m_watchFramesYTimeline[index]->setToValue(m_endPoint.y);
    
    m_watchFramesYTimeline[index]->start();

    //VFX_TRACE(("start bubble timeline=%08x\n", m_watchFramesYTimeline[index]));

    // init level on filterTiming.
    VFX_OBJ_CLOSE(m_watchFramesLevelTimeline[index]);
    VFX_OBJ_CREATE(m_watchFramesLevelTimeline[index], VfxFloatTimeline, this);
    m_watchFramesLevelTimeline[index]->setTarget(m_watchFrame[index]);
    m_watchFramesLevelTimeline[index]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_watchFramesLevelTimeline[index]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_watchFramesLevelTimeline[index]->setStartDelay(startDelay);
    m_watchFramesLevelTimeline[index]->setDurationTime(dur);
    m_watchFramesLevelTimeline[index]->setFromValue(0);
    m_watchFramesLevelTimeline[index]->setToValue(1.0);
    
    m_watchFramesLevelTimeline[index]->start();

    // init vibration time line on fpeUser0
    
    VFX_OBJ_CLOSE(m_watchFramesVibrationTimeline[index]);
    VFX_OBJ_CREATE(m_watchFramesVibrationTimeline[index], VfxFloatTimeline, this);
    m_watchFramesVibrationTimeline[index]->setTarget(m_watchFrame[index]);
    m_watchFramesVibrationTimeline[index]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
    m_watchFramesVibrationTimeline[index]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_watchFramesVibrationTimeline[index]->setStartDelay(startDelay);
    m_watchFramesVibrationTimeline[index]->setDurationTime(500);
    m_watchFramesVibrationTimeline[index]->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_watchFramesVibrationTimeline[index]->setFromValue(0);
    m_watchFramesVibrationTimeline[index]->setToValue(2 * VFX_PI);
    
    m_watchFramesVibrationTimeline[index]->start();

    
    // init  particle's scale, opacity, amplitude, freqency
    FramePropertyEffectData userData;
    
    VfxFloat scale;
    if(index < m_bubbleCount * 0.6)
    {
        scale = 0.4f + 0.6f * (rand() % 100) / 100;     
    }
    else
    {
        scale = 1.0f + 0.2f * (rand() % 100) / 100;     
    }
    userData.scale = scale;

    VfxFloat opacity = 0.8f + 0.2f * (rand() % 100) / 100;
    userData.opacity= opacity;

    userData.amplitude = (VfxFloat)(20 + (rand() % 30));
    if (rand() % 2 == 0)
    {
        userData.dir = -1;
    }
    else
    {
        userData.dir = 1;
    }
    userData.isInverse = m_isInverse;

    m_particle[index]->setPropertyEffectCallback(
                m_watchFrame[index],
                bubblePathEffectCallback,
                &userData,
                sizeof(userData),
                VRT_FPE_TRIGGER_TYPE_DIRTY);
}

void VcpBubbleEffect::startFloat(VfxPoint startPoint)
{
    if (m_isStop == VFX_TRUE)
    {
        VFX_OBJ_CLOSE(m_explodeTimer);
        m_startPoint = startPoint;
      //  m_orgStartPoint = startPoint;
        
        if (m_isInverse == VFX_FALSE)
        {
            m_endPoint = VfxPoint(startPoint.x, 30);

            m_top->setAutoAnimate(VFX_FALSE);
            m_top->setPos(startPoint.x, -1 * m_top->getSize().height);
            m_top->setAutoAnimate(VFX_TRUE); 
            m_top->setPos(startPoint.x, 0);

            m_top2->setAutoAnimate(VFX_FALSE);
            m_top2->setPos(startPoint.x, -1 * m_top2->getSize().height);
            
            m_ballMother->setPos(startPoint.x, 30);
        }
        else
        {
            m_endPoint = VfxPoint(startPoint.x, getSize().height - 30);

            m_top->setAutoAnimate(VFX_FALSE);
            m_top->setPos(startPoint.x, getSize().height + m_top->getSize().height);
            m_top->setAutoAnimate(VFX_TRUE); 
            m_top->setPos(startPoint.x, getSize().height);
            
            m_top2->setAutoAnimate(VFX_FALSE);
            m_top2->setPos(startPoint.x, getSize().height + m_top->getSize().height);

            VfxTransform tempTransform;
            tempTransform.data.affine.rz = VFX_DEG_TO_RAD(180.0f);
            m_top->setTransform(tempTransform);
            m_top2->setTransform(tempTransform);
            
            m_ballMother->setPos(startPoint.x, getSize().height - 30);
            m_ballMother->setTransform(tempTransform);
        }

        m_ballMother->setAutoAnimate(VFX_TRUE);

        VfxS32 i;
        for(i=0; i<m_bubbleCount; i++)
        {
            initBubble(i);
        }
        
        m_isStop = VFX_FALSE;
        m_ballMother->setHidden(VFX_FALSE);
        m_top->setHidden(VFX_FALSE);
        m_top2->setHidden(VFX_FALSE);
        // rest Transform to I
        m_ballMother->setTransform(VfxTransform());

        VfxTransform tempTransform;

        m_ballSizeTimeline->setFromValue(VfxTransform());

        tempTransform.data.affine.sx = 1.1f;
        tempTransform.data.affine.sy = 1.1f;
        
        m_ballSizeTimeline->setToValue(tempTransform);
        m_ballSizeTimeline->start();
        
    }
}


void VcpBubbleEffect::shiftFloat(VfxPoint startPoint)
{
    m_startPoint = startPoint;
    if (m_isInverse == VFX_FALSE)
    {
        m_endPoint = VfxPoint(startPoint.x, 30);
        m_top->setPos(startPoint.x, 0);
        m_top2->setPos(startPoint.x, m_top2->getPos().y);
        m_ballMother->setPos(startPoint.x, 30);
        
        VfxTransform tempTransform;
        VfxFloat scale;
        if (m_startPoint.y > m_thresholdY)
        {
            //scale = 1.0f + 0.5f * (1.0f - ((VfxFloat)(m_startPoint.y - m_thresholdY) / (m_orgStartPoint.y - m_thresholdY)));
            scale = 1.0f;
            if (m_top2->getPos().y == 0)
            {
                m_top2->setAutoAnimate(VFX_FALSE);
                m_top2->setPos(startPoint.x, 0);
                m_top2->setAutoAnimate(VFX_TRUE); 
                m_top2->setPos(startPoint.x, -1 * m_top2->getSize().height);
            }
        }
        else
        {
            scale = 1.6f; 
            if (m_top2->getPos().y != 0)
            {
                m_top2->setAutoAnimate(VFX_FALSE);
                m_top2->setPos(startPoint.x, -1 * m_top2->getSize().height);
                m_top2->setAutoAnimate(VFX_TRUE); 
                m_top2->setPos(startPoint.x, 0);
            }
        }

        tempTransform.data.affine.sx = scale;
        tempTransform.data.affine.sy = scale;
        m_ballMother->setTransform(tempTransform);
        
    }
    else
    {
        m_endPoint = VfxPoint(startPoint.x, getSize().height - 30);
        m_top->setPos(startPoint.x, getSize().height);
        m_top2->setPos(startPoint.x, m_top2->getPos().y);
        m_ballMother->setPos(startPoint.x, getSize().height - 30);


        VfxTransform tempTransform;
        VfxFloat scale;
        if (m_startPoint.y < m_thresholdY)
        {
            //scale = 1.0f + 0.5f * (1.0f - ((VfxFloat)(m_startPoint.y - m_thresholdY) / (m_orgStartPoint.y - m_thresholdY)));
            scale = 1.0f;
            if (m_top2->getPos().y == getSize().height)
            {
                m_top2->setAutoAnimate(VFX_FALSE);
                m_top2->setPos(startPoint.x, getSize().height);
                m_top2->setAutoAnimate(VFX_TRUE); 
                m_top2->setPos(startPoint.x, getSize().height + m_top->getSize().height);
            }

        }
        else
        {
            scale = 1.6f;
            if (m_top2->getPos().y != getSize().height)
            {
                m_top2->setAutoAnimate(VFX_FALSE);
                m_top2->setPos(startPoint.x, getSize().height + m_top->getSize().height);
                m_top2->setAutoAnimate(VFX_TRUE); 
                m_top2->setPos(startPoint.x, getSize().height);
            }
        }

        tempTransform.data.affine.sx = scale;
        tempTransform.data.affine.sy = scale;
        m_ballMother->setTransform(tempTransform);
    }

    

    VfxS32 i;
    for(i=0; i<m_bubbleCount; i++)
    {
        if (m_watchFrame[i])
        {
            m_watchFrame[i]->setBounds(m_startPoint.x, m_startPoint.y, 1, 1);
            m_watchFramesXTimeline[i]->setIsFromCurrent(VFX_TRUE);
            m_watchFramesXTimeline[i]->setToValue(m_endPoint.x);
            m_watchFramesXTimeline[i]->start();
        }
    }
}

void VcpBubbleEffect::stopFloat(VfxBool isAnim)
{
    if (m_isStop == VFX_FALSE)
    {
        if (isAnim)
        {
            VFX_DEV_ASSERT(m_explodeTimer == NULL);
            VFX_OBJ_CREATE(m_explodeTimer, VfxTimer, this);
            m_explodeTimer->setStartDelay(300);
            m_explodeTimer->start();
            m_explodeTimer->m_signalTick.connect(this, &VcpBubbleEffect::onTimerStop);

            startExplode();
        }
        else
        {
            stopBubble(); 
            //m_signalOnStopFinished.postEmit();
        }
        m_isStop = VFX_TRUE;
        m_ballMother->setHidden(VFX_TRUE);
        if (m_isInverse == VFX_FALSE)
        {
            m_top->setPos(m_top->getPos().x, -1 * m_top->getSize().height);
            m_top2->setPos(m_top2->getPos().x, -1 * m_top2->getSize().height);
        }
        else
        {
            m_top->setPos(m_top2->getPos().x, getSize().height + m_top->getSize().height);
            m_top2->setPos(m_top2->getPos().x, getSize().height + m_top2->getSize().height);
        }
    }
}


void VcpBubbleEffect::stopBubble(void)
{
    VfxS32 i;
    for(i=0; i<m_bubbleCount; i++)
    {
        if (m_watchFramesYTimeline[i])
        {
            //VFX_TRACE(("stop bubble timeline=%08x\n", m_watchFramesYTimeline[i]));

            if (m_watchFramesYTimeline[i]->getIsEnabled())
            {
                VFX_TRACE(("Bubble close 1 i=%d\n", i));
                VFX_OBJ_CLOSE(m_watchFramesYTimeline[i]);
        
                m_particle[i]->setPropertyEffectCallback(
                                NULL,
                                NULL,
                                NULL,
                                0);
                // work around to reset opacity
                m_particle[i]->setOpacity(1.0f);
                m_particle[i]->setOpacity(0);
            }
        }

        VFX_OBJ_CLOSE(m_watchFramesEXTimeline[i]);
    } 
}

void VcpBubbleEffect::onTimerStop(VfxTimer *source)
{   
    VFX_DEV_ASSERT(m_explodeTimer);
    
    VFX_OBJ_CLOSE(m_explodeTimer);
    stopBubble();
    
    m_signalOnStopFinished.postEmit();
    
    
}

//false,normal mode
//true, reducing mode, no more new bubble.
void VcpBubbleEffect::setSuspendEeject(VfxBool value)
{
    m_isSuspendEject = value;

    if (m_isSuspendEject == VFX_FALSE)
    {
        VfxS32 i;
        for(i=0; i < m_bubbleCount; i++)
        {
            if(m_watchFramesYTimeline[i] == NULL)
            {
                initBubble(i);
            }
        }
    }
}

void VcpBubbleEffect::reejectBubble(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    if(isCompleted)
    {
        VFX_OBJ_ASSERT_VALID(timeline);
        //stopBubble();
        VfxFrame *watchFrame = (VfxFrame *)timeline->getTarget();
        if (m_isSuspendEject || m_isStop)
        {
            VfxS32 i = watchFrame->getBorderWidth();

            VFX_TRACE(("Bubble close 2 i=%d\n", i));
            VFX_OBJ_CLOSE(m_watchFramesYTimeline[i]);
            m_particle[i]->setPropertyEffectCallback(
                                NULL,
                                NULL,
                                NULL,
                                0);
            // work around to reset opacity
            m_particle[i]->setOpacity(1.0f);
            m_particle[i]->setOpacity(0);
        }
        else
        {
            initBubble(watchFrame->getBorderWidth());
        }
    }
}


void VcpBubbleEffect::startExplode()
{    

    VfxS32 i;
    for(i=0; i<m_bubbleCount; i++)
    {
        VFX_OBJ_CREATE(m_watchFramesEXTimeline[i], VfxS32Timeline, this);
        m_watchFramesEXTimeline[i]->setTarget(m_watchFrame[i]);
        m_watchFramesEXTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_watchFramesEXTimeline[i]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR); 
        m_watchFramesEXTimeline[i]->setDurationTime(500);
        
        if (i % 2 == 0)
        {
            if (m_watchFrame[i])
            {
                //m_watchFramesXTimeline[i]->setFromValue(m_watchFrame[i]->getPos().x);
                m_watchFramesEXTimeline[i]->setIsFromCurrent(VFX_TRUE);
                m_watchFramesEXTimeline[i]->setToValue(m_endPoint.x - 100);
                m_watchFramesEXTimeline[i]->start();
            }
        }
        else
        {
            if (m_watchFrame[i])
            {
                //m_watchFramesXTimeline[i]->setFromValue(m_watchFrame[i]->getPos().x);
                m_watchFramesEXTimeline[i]->setIsFromCurrent(VFX_TRUE);
                m_watchFramesEXTimeline[i]->setToValue(m_endPoint.x + 100);
                m_watchFramesEXTimeline[i]->start();
            }
        }
    }
}


vrt_render_dirty_type_enum VcpBubbleEffect::bubblePathEffectCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame);
    VFX_DEV_ASSERT(watch_frame);
    VFX_DEV_ASSERT(user_data_size == sizeof(FramePropertyEffectData));
    
    FramePropertyEffectData *userData = (FramePropertyEffectData *)user_data;
    VfxFloat level = watch_frame->filter_timing;
    VfxFloat amplitude = (1.0f - level) * userData->amplitude;
    
    target_frame->pos.x = (vrt_s32)(watch_frame->pos.x + userData->dir * amplitude * vfxSin(watch_frame->fpe_user_0));
    target_frame->pos.y = watch_frame->pos.y;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VfxFloat opacity = userData->opacity;
    if (level == 0  || level == 1.0f)
    {
        opacity = 0;
    }
    
    target_frame->opacity = opacity;

    // check less than start point
    if (userData->isInverse)
    {
        if (target_frame->pos.y <  watch_frame->bounds.origin.y)
        {
            target_frame->opacity = 0;
        }
    }
    else
    {
        if (target_frame->pos.y >  watch_frame->bounds.origin.y)
        {
            target_frame->opacity = 0;
        }
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    VfxFloat scale = (0.2f - userData->scale) * level + userData->scale;
    target_frame->transform.data.affine.sx = scale;
    target_frame->transform.data.affine.sy = scale;

    //target_frame->background_color = VFX_COLOR_RED;

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}
#endif /* defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)  */

