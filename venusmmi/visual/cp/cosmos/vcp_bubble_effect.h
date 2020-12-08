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
 *  vcp_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Cube Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_BUBBLE_EFFECT_H__
#define __VCP_BUBBLE_EFFECT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

//
//only used by scrlock cosmos, depend on it.
//
#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"
#include "vfx_primitive_frame.h"
#include "vfx_timer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM                       (18)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Class VcpBubbleEffect
 *  VcpBubbleEffect will eject many bubble when start. The eject position can 
 *  also move when call shiftFloat(). When  call stopFloat(), it will show 
 *  an explosion effect then disappear. The VcpBubbleEffect can be upside down
 *  if set setIsInverse(VFX_TRUE).
 * EXAMPLE
 * <code>
 *  VcpBubbleEffect *m_bubbleEffect;
 *  VFX_OBJ_CREATE(m_bubbleEffect, VcpBubbleEffect, this);
 *  m_bubbleEffect->setBounds(0, 0, getScreenSize().width, getScreenSize().height);
 *  m_bubbleEffect->m_signalOnStopFinished.connect(this, &VappScreenLockFrame::notifyUnlock);
 *  m_bubbleEffect->setThresholdY(m_unlockAreaHeight);
 *
 *  m_bubbleEffect->startFloat(VfxPoint(100, 100));
 *
 *  m_bubbleEffect->shiftFloat(VfxPoint(100, 150));
 *  
 *  m_bubbleEffect->stopFloat();
 * </code>
 *****************************************************************************/
class VcpBubbleEffect : public VfxFrame
{
    VFX_DECLARE_CLASS(VcpBubbleEffect);

// Constructor / Destructor
public:
    // <group DOM_BubbleEffect_VcpBubbleEffect_Constructor/Destructor>
    VcpBubbleEffect();
    // <group DOM_BubbleEffect_VcpBubbleEffect_Constructor/Destructor>
    VcpBubbleEffect(VfxS32 bubbleCount);

private:
    struct FramePropertyEffectData
    {
        VfxFloat scale;
        VfxFloat opacity;
        VfxFloat amplitude;
        VfxFloat frequency;
        VfxS32   dir;
        VfxBool  isInverse;
    };

// Method
public:
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // start to eject bubble
    void startFloat(
        VfxPoint startPoint    // [IN] eject position
        );
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // shift the eject position
    void shiftFloat(
        VfxPoint startPoint    // [IN] eject position
        );
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // stop to eject bubble
    void stopFloat(
        VfxBool isAnim = VFX_TRUE // [IN] explosion effect or not
        );

    void setSuspendEeject(VfxBool value);

    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // set upside down or not
    void setIsInverse(VfxBool value)
    {
        m_isInverse = value;
    }
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // the threshold Y means if over this value,
    // the ball will become large and the background will become glory
    void setThresholdY(VfxS32 y)
    {
        m_thresholdY = y;
    }
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // get upside down or not
    VfxBool getIsInverse()
    {
        return m_isInverse;
    }
    // <group DOM_BubbleEffect_VcpBubbleEffect_Method>
    // get threshold Y
    VfxS32 getThresholdY()
    {
        return m_thresholdY;
    }

// Event
public:
// <group DOM_BubbleEffect_VcpBubbleEffect_Event>
// notify APP when bubble effect is finished.
VfxSignal0  m_signalOnStopFinished;

// Implementation
private:
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    static vrt_render_dirty_type_enum bubblePathEffectCallback(
                vrt_frame_visual_property_struct *target_frame,
                 const vrt_frame_visual_property_struct *watch_frame,
                 void *user_data,
                 vrt_u32 user_data_size);
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    void onTimerStop(VfxTimer *source);
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    void initBubble(VfxS32 index);
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    void stopBubble();
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    void startExplode();
    // <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
    void reejectBubble(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );
	// <group DOM_BubbleEffect_VcpBubbleEffect_Implementation>
	void initInternal();

// Override
protected:
    // <group DOM_BubbleEffect_VcpBubbleEffect_Override>
    virtual void onInit();

// Variable
private:
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxImageFrame               *m_top;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxImageFrame               *m_top2;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxImageFrame               *m_ball;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxFrame                    *m_ballMother;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxImageFrame               *m_particle[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxFrame                    *m_watchFrame[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxPoint                    m_startPoint;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
  //  VfxPoint                    m_orgStartPoint;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxPoint                    m_endPoint;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxBool                      m_isStop;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxS32Timeline              *m_watchFramesEXTimeline[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxS32Timeline              *m_watchFramesXTimeline[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxS32Timeline              *m_watchFramesYTimeline[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxFloatTimeline            *m_watchFramesLevelTimeline[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxFloatTimeline            *m_watchFramesVibrationTimeline[VCP_BUBBLE_EFFECT_MAX_BUBBLE_NUM];
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxTimer                    *m_explodeTimer;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxBool                     m_isInverse;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxS32                      m_thresholdY;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxTransformTimeline        *m_ballSizeTimeline;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxS32                       m_bubbleCount;
    // <group DOM_BubbleEffect_VcpBubbleEffect_Variable>
    VfxBool                      m_isSuspendEject;
};

#endif /* defined(__MMI_VUI_SCREEN_LOCK_COSMOS__) */
#endif /* __VCP_BUBBLE_EFFECT_H__ */


