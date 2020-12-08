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
 *  vfx_ani_helper.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  Implementation of VfxPageTransition, see vfx_ani_helper.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_page_transition.h"

extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
}

#include "vrt_datatype.h"
#include "vrt_canvas.h"

#include "vfx_animation.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_screen.h"
#include "vfx_control.h"
#include "vfx_auto_animate.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
// by RHR //#include "vfx_pen.h"
#include "vfx_top_level.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

#define DEFAULT_TRANSITION_DURACTION    (VFX_TIMELINE_DEFAULT_DUR_TIME)

#define DEFAULT_SHRINK_PERCENTAGE   80

/***************************************************************************** 
 * Class VfxPageTransition
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxPageTransition", VfxPageTransition, VfxObject);

VfxPageTransition::VfxPageTransition() :
    m_transFlags(0),
    //m_phaseIn(VFX_FALSE), 
    //m_inAnimation(VFX_FALSE), 
    m_ctrl(NULL), 
    m_timer(NULL)
{

}

void VfxPageTransition::prepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
    /* stop ongoing animation */
    stop();

    if(in)
        m_transFlags |= FLAGS_IS_PHASE_IN;
    else
        m_transFlags &= ~FLAGS_IS_PHASE_IN;
    m_direction = direction;
    
    customPrepare(in, direction, param);
}

VfxBool VfxPageTransition::start(VfxControl *target, VfxBool noAnimation, VfxBool closeTarget)
{
    if(noAnimation)
    {
        m_ctrl = target;
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        if(!getIn())
        {
            if(!customOuted())
                closeTarget = VFX_FALSE;
        }
        else
        {
            target->setHidden(VFX_FALSE);
            target->setOpacity(1.0f);
        }
        VfxAutoAnimate::commit();

        if(!getIn() && closeTarget)
            VFX_OBJ_CLOSE(target);

        return VFX_FALSE;
    }
    else
    {
        /* show it when phase in */    
        if(getIn())
            target->setHidden(VFX_FALSE);

        target->setAutoAnimate(VFX_TRUE);
        if(target->getCacheMode() == VFX_CACHE_MODE_AUTO)
            target->setCacheMode(VFX_CACHE_MODE_FREEZE);

        if(target->getIsUnhittable())
            m_transFlags |= FLAGS_OLD_HITTEST;
        else
            m_transFlags &= ~FLAGS_OLD_HITTEST;
        target->setIsUnhittable(VFX_TRUE);

        /* save variable */
        m_ctrl = target;
        m_direction = (VfxS8)m_direction;
        if(closeTarget)
            m_transFlags |= FLAGS_CLOSE_TARGET;
        else
            m_transFlags &= ~FLAGS_CLOSE_TARGET;
        m_transFlags |= FLAGS_IN_ANIMATION;

        customStart(getIn(), m_direction, DEFAULT_TRANSITION_DURACTION);

        /* start a timer with same duration */
        if(!m_timer)
        {
            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
            m_timer->m_signalTick.connect(this, &VfxPageTransition::onStop);
        }
        m_timer->setStartDelay(DEFAULT_TRANSITION_DURACTION);
        m_timer->start();
        
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowTime(DEFAULT_TRANSITION_DURACTION);

        return inAnimation();
    }
}

VfxBool VfxPageTransition::stop()
{
    if(!inAnimation())
        return VFX_FALSE;

    customStop(getIn(), m_direction, DEFAULT_TRANSITION_DURACTION);
    
    m_timer->stop();
    m_transFlags &= ~FLAGS_IN_ANIMATION;

    if(m_ctrl->getCacheMode() == VFX_CACHE_MODE_FREEZE)
        m_ctrl->setCacheMode(VFX_CACHE_MODE_AUTO);

    m_ctrl->setIsUnhittable((m_transFlags & FLAGS_OLD_HITTEST) ? VFX_TRUE : VFX_FALSE);

    // Cache m_ctrl, in case it is closed after m_signalStopped.emit
    VfxWeakPtr<VfxControl> ctrlToClose;
   
    if(!getIn())
    {
        VfxBool ret = customOuted();
        if(ret && (m_transFlags & FLAGS_CLOSE_TARGET))
            ctrlToClose = m_ctrl;
    }

    m_signalStopped.emit(getIn(), m_direction);

    if(ctrlToClose.isValid())
        VFX_OBJ_CLOSE(ctrlToClose);
    return VFX_TRUE;
}

VfxBool VfxPageTransition::restart()
{
    if(!inAnimation())
        return VFX_FALSE;
        
    customStop(getIn(), m_direction, DEFAULT_TRANSITION_DURACTION);
    //m_timer->stop();
    m_transFlags &= ~FLAGS_IN_ANIMATION;

    if(m_ctrl->getCacheMode() == VFX_CACHE_MODE_FREEZE)
        m_ctrl->setCacheMode(VFX_CACHE_MODE_AUTO);

    m_ctrl->setIsUnhittable((m_transFlags & FLAGS_OLD_HITTEST) ? VFX_TRUE : VFX_FALSE);

    // play trick to keep the timer;
    VfxTimer *oldTimer = m_timer;
    m_timer = NULL;

    VfxBool bRet = start(m_ctrl, VFX_FALSE, (m_transFlags & FLAGS_CLOSE_TARGET) ? VFX_TRUE : VFX_FALSE);

    // restore the old timer
    VFX_OBJ_CLOSE(m_timer);
    m_timer = oldTimer;

    return bRet;
}

void VfxPageTransition::customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
    VFX_UNUSED(in);
    VFX_UNUSED(direction);
    VFX_UNUSED(param);
}

void VfxPageTransition::customStart(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    /* fade in/out */
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    {
        if(in)
            getTarget()->setOpacity(0.0f);
        else
            getTarget()->setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::initAnimateBegin();
    {
        VfxAutoAnimate::setDuration(duration);
        if(in)
            getTarget()->setOpacity(1.0f);
        else
            getTarget()->setOpacity(0.0f);
    }
    VfxAutoAnimate::initAnimateEnd();
    VfxAutoAnimate::commit();
}

void VfxPageTransition::customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    VFX_UNUSED(direction);
    VFX_UNUSED(duration);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    if(in)
    {
        getTarget()->setOpacity(0.0f);
        getTarget()->setOpacity(1.0f);
    }
    else
    {
        getTarget()->setOpacity(1.0f);
        getTarget()->setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();
}

VfxBool VfxPageTransition::customOuted()
{
    getTarget()->setHidden(VFX_TRUE);
    getTarget()->setOpacity(1.0f);
    return VFX_TRUE;
}

void VfxPageTransition::onStop(VfxTimer *timer)
{
    VFX_ASSERT(inAnimation() && (timer == m_timer));

    stop();
}

VFX_IMPLEMENT_CLASS("VfxPageSlideTransition", VfxPageSlideTransition, VfxPageTransition);

void VfxPageSlideTransition::customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
    if(param)
    {
        VfxBool toLand, fromLand;
        toLand = (param->rotateTo == VFX_SCR_ROTATE_TYPE_90) || (param->rotateTo == VFX_SCR_ROTATE_TYPE_270);
        fromLand = (param->rotateFrom == VFX_SCR_ROTATE_TYPE_90) || (param->rotateFrom == VFX_SCR_ROTATE_TYPE_270);
        if(toLand == fromLand || direction >= 0)
            m_customWidth = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width;
        else
            m_customWidth = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().height;
    }
}

void VfxPageSlideTransition::customStart(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    if(direction == 0)
    {
        VfxPageTransition::customStart(in, direction, duration);
    }
    else
    {
        /* slide in/out */
        VfxPoint srcPos, destPos;
        VfxS32 width;
        if(m_customWidth)
            width = m_customWidth;
        else
            width = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width;

        srcPos = destPos = getTarget()->getPos();
        if(in)
        {
            if(direction > 0)
                srcPos.x += width;
            else
                srcPos.x -= width;
        }
        else
        {
            if(direction > 0)
                destPos.x -= width;
            else
                destPos.x += width;
        }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        {
            getTarget()->setPos(destPos);
        }
        VfxAutoAnimate::commit();

        VFX_ASSERT(!m_tl);
        VFX_OBJ_CREATE(m_tl, VfxS32Timeline, this);

        m_tl->setTarget(getTarget());
        m_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        m_tl->setDurationTime(duration);
        m_tl->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_tl->setFromValue(srcPos.x);
        m_tl->setToValue(destPos.x);
        m_tl->start();
#endif
    }
}

void VfxPageSlideTransition::customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    if(direction == 0)
    {
        VfxPageTransition::customStop(in, direction, duration);
    }
    else
    {
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        VFX_ASSERT(m_tl);
        VFX_OBJ_CLOSE(m_tl);
#endif        
    }
    
    m_customWidth = 0;
}


VFX_IMPLEMENT_CLASS("VfxPageCosmosTransition", VfxPageCosmosTransition, VfxPageTransition);

void VfxPageCosmosTransition::customPrepare(VfxBool in, VfxS32 direction, const VfxScreenRotateParam *param)
{
    if(param)
    {
        VfxBool toLand, fromLand;
        toLand = (param->rotateTo == VFX_SCR_ROTATE_TYPE_90) || (param->rotateTo == VFX_SCR_ROTATE_TYPE_270);
        fromLand = (param->rotateFrom == VFX_SCR_ROTATE_TYPE_90) || (param->rotateFrom == VFX_SCR_ROTATE_TYPE_270);
        if(toLand == fromLand || direction >= 0)
            m_customWidth = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width;
        else
            m_customWidth = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().height;
    }
}

void VfxPageCosmosTransition::customStart(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    if(direction == 0)
    {
        VfxPageTransition::customStart(in, direction, duration);
    }
    else
    {
        /* FTO page effect */
        VfxAutoAnimate::begin();
        VfxAutoAnimate::initAnimateBegin();
        VfxAutoAnimate::setDuration(duration);

        if(!in)
        {
            /* 1. Shrink it */
            VfxTransform t;
            t.data.affine.sx = (VfxFloat)DEFAULT_SHRINK_PERCENTAGE/100;
            t.data.affine.sy = (VfxFloat)DEFAULT_SHRINK_PERCENTAGE/100;
            getTarget()->setTransform(t);

            /* 2. Move it */
            VfxPoint p = getTarget()->getPos();
            VfxSize fs = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize();
            p.y += ((fs.height/2)-p.y) * (100-DEFAULT_SHRINK_PERCENTAGE) / 100;
            if(direction < 0)
                p.x += fs.width * (10+100-DEFAULT_SHRINK_PERCENTAGE) / 100;
            else
                p.x -= fs.width * (10) / 100;

            getTarget()->setPos(p);

            /* 3. Fade it */
            getTarget()->setOpacity(0.5f);
        }
        else
        {
            VfxPoint srcPos, destPos;
            VfxS32 w;
            if(m_customWidth)
                w = m_customWidth;
            else
                w = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getSize().width;

            srcPos = destPos = getTarget()->getPos();
            if(in)
            {
                if(direction > 0)
                    srcPos.x += w;
                else
                    srcPos.x -= w;
            }

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            getTarget()->setPos(srcPos);
            VfxAutoAnimate::commit();

            getTarget()->setPos(destPos);
            getTarget()->bringToFront();
        }
        
        VfxAutoAnimate::initAnimateEnd();
        VfxAutoAnimate::commit();
    }
}

void VfxPageCosmosTransition::customStop(VfxBool in, VfxS32 direction, VfxMsec duration)
{
    if(direction == 0)
    {
        VfxPageTransition::customStop(in, direction, duration);
    }
    else
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        VfxPoint pos = getTarget()->getPos();
        pos.x ++;
        getTarget()->setPos(pos);
        pos.x --;
        getTarget()->setPos(pos);

        getTarget()->setTransform(VfxTransform());
        
        getTarget()->setOpacity(1.0f);

        VfxAutoAnimate::commit();
    }
    
    m_customWidth = 0;
}

