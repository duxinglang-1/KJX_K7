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
 *  vcp_waiting_icon.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Waiting icon component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_waiting_icon.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_control.h"
#include "vfx_basic_type.h"
#include "mmi_rp_srv_venus_component_waiting_icon_def.h"
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
void VcpWaitingIcon::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_image, VcpWaitingIconShell, this);    
	m_image->onPlay(VcpWaitingIconShell::TYPE_NORMAL);
    setSize(m_image->getSize());
}


void VcpWaitingIcon::setBounds(const VfxRect &value)
{
    if (value != m_bounds)
    {
        onSize(value);
    }

    VfxFrame::setBounds(value);
}


void VcpWaitingIcon::onSize(const VfxRect &bounds)
{
    if (m_image)
    {
        m_image->setSize(bounds.size);
        m_image->setPos(bounds.size.width / 2, bounds.size.height / 2);
    }
}


void VcpWaitingIcon::start()
{
    if (m_isAnimating)
    {
        return;
    }

    setHidden(VFX_FALSE);

   // m_image->setVisualType(VfxVisual::TYPE_HIGHLIGHT, VFX_TRUE);
	m_image->onPlay(VcpWaitingIconShell::TYPE_HIGHLIGHT);
    m_isAnimating = VFX_TRUE;
}


void VcpWaitingIcon::stop()
{
    if (m_isAnimating)
    {
       // m_image->setVisualType(VfxVisual::TYPE_NORMAL, VFX_TRUE);
		m_image->onPlay(VcpWaitingIconShell::TYPE_NORMAL);
        m_isAnimating = VFX_FALSE;
    }

    // auto hidden if stopped
    if (getHiddenWhenStopped())
    {
        setHidden(VFX_TRUE);
    }
}
#define BALL_SCALE_RATIO 1.8f
void VcpWaitingIconShell::onInit()
{
    VfxControl::onInit();    

    for (VfxS32 i = 0; i < BALL_NUM; i++)
    {            
        VFX_OBJ_CREATE(m_ball[i], VfxImageFrame, this);
        m_ball[i]->setAnchor(0.5f, 0.5f);
        
        m_ball[i]->setResId(VCP_IMG_WAITING_ICON);
    }    
    setAnchor(0.5f, 0.5f);
    m_signalBoundsChanged.connect(this, &VcpWaitingIconShell::onBoundsChanged);
    setSize(WIDTH, HEIGHT);
}


void VcpWaitingIconShell::onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    if (source->getSize() == oldBounds.size)
    {
        return;
    }

    VfxPoint center = VfxPoint(source->getSize().width / 2, source->getSize().height / 2);
    VfxS32   radius = VFX_MIN(center.x, center.y);
    
    radius -= VFX_MAX(m_ball[0]->getSize().width, m_ball[0]->getSize().height);

    // put each ball on the circle euqally
    for (VfxS32 i = 0; i < BALL_NUM; i++)
    {
        m_ball[i]->setPos(
                    center.x + (VfxS32)(radius * (VfxFloat)vfxCos(VFX_DEG_TO_RAD(360 / BALL_NUM * i - 90))),
                    center.y + (VfxS32)(radius * (VfxFloat)vfxSin(VFX_DEG_TO_RAD(360 / BALL_NUM * i - 90))));  
    }    
}

void VcpWaitingIconShell::onPlay(VfxS32 visualType)
{        
    switch (visualType)
    {
        case TYPE_NORMAL:
            // stop playing
            if (m_ballTl[0])
            {
                for (VfxS32 i = 0; i < BALL_NUM * 2; i++)
                {
                    VFX_OBJ_CLOSE(m_ballTl[i]);
                }
            }         
            break;

        case TYPE_HIGHLIGHT:
            if (m_ballTl[0] == NULL)    
            {
                // start playing
                VfxTransform identity, tran;
                VfxTransformTimeline *tl;

                tran.data.affine.sx = BALL_SCALE_RATIO;
                tran.data.affine.sy = BALL_SCALE_RATIO;

                // each ball got 2 timelines to achieve scale up and down
                for (VfxS32 i = 0; i < BALL_NUM; i++)
                {                                    
                    // scale up
                    VFX_OBJ_CREATE(m_ballTl[2 * i], VfxTransformTimeline, m_ball[i]);
                    tl = m_ballTl[2 * i];
                    tl->setTarget(m_ball[i]);
                    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                    tl->setFromValue(identity);
                    tl->setToValue(tran);
                    tl->setStartTime(BALL_TIME * i);        
                    tl->setDurationTime(REPEAT_DURATION / BALL_NUM / 2);
                    tl->setRepeatDuration(REPEAT_DURATION);
                    tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                    tl->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
                    tl->start();

                    // scale down
                    VFX_OBJ_CREATE(m_ballTl[2 * i + 1], VfxTransformTimeline, m_ball[i]);
                    tl = m_ballTl[2 * i + 1];                
                    tl->setTarget(m_ball[i]);
                    tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
                    tl->setFromValue(tran);
                    tl->setToValue(identity);
                    tl->setStartTime(BALL_TIME * i + BALL_TIME / 2);        
                    tl->setDurationTime(REPEAT_DURATION / BALL_NUM / 2);
                    tl->setRepeatDuration(REPEAT_DURATION);
                    tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
                    tl->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);        
                    tl->start();
                }    
            }
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

