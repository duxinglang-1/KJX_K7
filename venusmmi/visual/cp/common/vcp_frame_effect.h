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
 *  vcp_page.h
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
#ifndef __VCP_FRAME_EFFECT_H__
#define __VCP_FRAME_EFFECT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h" 
#include "vcp_frame_effect_type.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Class VcpBaseEffect
 *  VcpBaseEffect provide a basic effect class. One may inherit this class to
 *  create different type of effect. This effect can be thought as a effect
 *  which means no effect.
 *  
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpBaseEffect : public VfxObject
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpBaseEffect_Constructor/Destructor>
    VcpBaseEffect(); 

// Overridable
public:
    // <group DOM_FrameEffect_VcpBaseEffect_Overridable>
    // This is main entry to start a effect.
    // The property of the active frame which the effect apply on may be changed 
    // by the frame. User should take care of this. We define the forward way of
    // effect is when the end of effect, the active frame will appear to the user.
    // on the other hands, the reverse way means it will disappear to the user.
    // Some effect can change some attribute to have a different view of effect.
    // They can use the *data to pass those parameters. The effect should check
    // the size of *data by dataSize to avoid a serious problem if user pass a
    // wrong parameter
    virtual void onStart(
        VfxFrame *activeFrame,              // [IN/OUT] the active frame
        VfxMsec duration,                   // [IN] the durtion of the effect
        VcpEffectTypeDirection direction,   // [IN] the direction of the effect
        VfxBool isReverse,                  // [IN] reverse effect or not.
        void *data,                         // [IN] parameter to change some attribute
        VfxS32 dataSize                     // [IN] parameter size
        );

// Method
public:
    // <group DOM_FrameEffect_VcpBaseEffect_Method>
    // set Active Frame of VcpBaseEffect
    void setActiveFrame(VfxFrame *activeFrame);

// Override
protected:
    // <group DOM_FrameEffect_VcpBaseEffect_Override>
    // overwrite onDinit to call retore()
    virtual void onDeinit();

// Overridable    
protected:
    // <group DOM_FrameEffect_VcpBaseEffect_Overridable>
    // The effect should restore the frame attribute when Effect is closed
    virtual void restore(VfxFrame *activeFrame);
        
// Event
public:
    // <group DOM_FrameEffect_VcpBaseEffect_Event>
    // notify VcpFrameEffect when effect is finished
    // void YourClass::onEndOfEffect()
    VfxSignal0 m_complete;

// Variable
public:
    // <group DOM_FrameEffect_VcpBaseEffect_Variable>
    VfxFrameWeakPtr m_activeFramePtr;
    
};


/*****************************************************************************
 * Class VcpFrameEffect
 *  VcpFrameEffect is a helper to use frame effect. It help user to create a
 *  instance of different effect which inherit from VcpBaseEffect and do some
 *  communication between VcpFrameEffect and that instance to finish to effect.
 *
 * EXAMPLE
 * <code>
 *  VcpFrameEffect *m_frameEffect;
 *  VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
 *  m_frameEffect->applyEffect(m_frame3, VCP_EFFECT_FLIP, 2000, VCP_EFFECT_DIRECTION_FROM_LEFT);
 * </code>
 *****************************************************************************/
class VcpFrameEffect : public VfxObject
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpFrameEffect_Constructor/Destructor>
    // Default constructor
    VcpFrameEffect(); 

// Method
public:
    // <group DOM_FrameEffect_VcpFrameEffect_Method>
    // to apply an effect on active frame. 
    // The property of the active frame which the effect apply on may be changed 
    // by the frame. User should take care of this. We define the forward way of
    // effect is when the end of effect, the active frame will appear to the user.
    // on the other hands, the reverse way means it will disappear to the user.
    // Some effect can change some attribute to have a different view of effect.
    // They can use the *data to pass those parameters.
    void applyEffect(
        VfxFrame *activeFrame,                                              // [IN/OUT] the active frame
        VcpEffectType EffectType,                                           // [IN] the type of effect
        VfxMsec Duration = -1,                                              // [IN] the durtion of the effect
        VcpEffectTypeDirection direction = VCP_EFFECT_DIRECTION_FROM_NONE,  // [IN] the direction of the effect
        VfxBool isReverse = VFX_FALSE,                                      // [IN] reverse effect or not.
        void *data = NULL,                                                  // [IN] parameter to change some attribute
        VfxS32 dataSize = 0                                                 // [IN] parameter size
        );
    // <group DOM_FrameEffect_VcpFrameEffect_Method>
    // restore the attribute before apply effect.
    void restore();

// Override
protected:
    // <group DOM_FrameEffect_VcpFrameEffect_Override>
    virtual void onDeinit();
// Event
public:
    // <group DOM_FrameEffect_VcpFrameEffect_Event>
    // notify APP when effect is finished. the active frame will be passed as 
    // parameter. The effect is complete or not is also passed.
    // void YourClass::onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
    VfxSignal2 <
        VfxFrame *,             // active Frame
        VfxBool                 // is completed
        > m_signalFinished;
// Variable
private:
    // <group DOM_FrameEffect_VcpFrameEffect_Variable>
    VfxFrameWeakPtr m_activeFramePtr;
    // <group DOM_FrameEffect_VcpFrameEffect_Variable>
    VfxBool m_effectRunning;
    // <group DOM_FrameEffect_VcpFrameEffect_Variable>
    VcpBaseEffect *m_pageEffect;
    // <group DOM_FrameEffect_VcpFrameEffect_Variable>
    VfxBool m_isReverse;
    
// Implementation
private:
    // <group DOM_FrameEffect_VcpFrameEffect_Implementation>
    VcpBaseEffect *createEffect(VcpEffectType type);
    // <group DOM_FrameEffect_VcpFrameEffect_Implementation>
    void onEndOfEffect();
   
};

/*****************************************************************************
 * Class VcpFadeInEffect
 *  VcpFadeInEffect provide a Fade-in effect on frame.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Opacity
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpFadeInEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpFadeInEffect_Constructor/Destructor>
    // Default constructor
    VcpFadeInEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpFadeInEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
// Variable
private:
    // <group DOM_FrameEffect_VcpFadeInEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    
// Implementation
private:
    // <group DOM_FrameEffect_VcpFadeInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

/*****************************************************************************
 * Class VcpFadeOutEffect
 *  VcpFadeOutEffect provide a Fade-out effect on frame.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Opacity, Transform, Anchor, Pos
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpFadeOutEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpFadeOutEffect_Constructor/Destructor>
    // Default constructor
    VcpFadeOutEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpFadeOutEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpFadeOutEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
// Variable
private:
    // <group DOM_FrameEffect_VcpFadeOutEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    // <group DOM_FrameEffect_VcpFadeOutEffect_Variable>
    VfxTransformTimeline *m_smallTimeline;
    // <group DOM_FrameEffect_VcpFadeOutEffect_Variable>
    VfxFPoint m_backupAnchor;
    // <group DOM_FrameEffect_VcpFadeOutEffect_Variable>
    VfxPoint  m_backupPos;
// Implementation
private:
    // <group DOM_FrameEffect_VcpFadeOutEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#endif
/*****************************************************************************
 * Class VcpFlipEffect
 *  VcpFlipEffect provide a Flip effect on frame.
 *
 *  support direction:
 *      VCP_EFFECT_DIRECTION_FROM_RIGHT
 *      VCP_EFFECT_DIRECTION_FROM_LEFT
 *      VCP_EFFECT_DIRECTION_FROM_UP
 *      VCP_EFFECT_DIRECTION_FROM_BOTTOM
 *  default direction:
 *      VCP_EFFECT_DIRECTION_FROM_BOTTOM
 *  default duration:
 *      250
 *  affect property:
 *      Transform, Culling
 *  parameter:
 *      VcpEffectFilpData
 *****************************************************************************/
class VcpFlipEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpFlipEffect_Constructor/Destructor>
    // Default constructor
    VcpFlipEffect(); 

// Override
protected:
    // <group DOM_FrameEffect_VcpFlipEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpFlipEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
// Variable
private:
    // <group DOM_FrameEffect_VcpFlipEffect_Variable>
    VfxTransformTimeline *m_flipTimeline;
    // <group DOM_FrameEffect_VcpFlipEffect_Variable>
    VcpEffectTypeDirection m_direction;
    // <group DOM_FrameEffect_VcpFlipEffect_Variable>
    VfxFrameCullingTypeEnum m_backupCulling;
    

// Implementation
private:
    // <group DOM_FrameEffect_VcpFlipEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_FrameEffect_VcpFlipEffect_Implementation>
    static VfxTimelineInterpolationRetEnum flipTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
};


/*****************************************************************************
 * Class VcpPopupEffect
 *  VcpFlipEffect provide popup-like effect on frame.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      500
 *  affect property:
 *      Opacity, Transform, Anchor, Pos
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpPopupEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpPopupEffect_Constructor/Destructor>
    // Default constructor
    VcpPopupEffect(); 

// Override
protected:
    // <group DOM_FrameEffect_VcpPopupEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpPopupEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
// Variable
private:
    // <group DOM_FrameEffect_VcpPopupEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    // <group DOM_FrameEffect_VcpPopupEffect_Variable>
    VfxTransformTimeline  *m_transformTimeline;
    // <group DOM_FrameEffect_VcpPopupEffect_Variable>
    VfxFPoint m_backupAnchor;
    // <group DOM_FrameEffect_VcpPopupEffect_Variable>
    VfxPoint  m_backupPos;

// Implementation
private:
    // <group DOM_FrameEffect_VcpPopupEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpMorphFadeInEffect
 *  VcpFadeInEffect provide morphing from one rectangle to the frame rectangle
 *  with fade in effect.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Opacity, Transform, Pos
 *  parameter:
 *      VcpEffectMorphFadeInData
 *****************************************************************************/
class VcpMorphFadeInEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Constructor/Destructor>
    // Default constructor
    VcpMorphFadeInEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
// Variable
private:
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Variable>
    VfxPointTimeline *m_posTimeline;
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Variable>
    VfxTransformTimeline *m_transformTimeline;
    
// Implementation
private:
    // <group DOM_FrameEffect_VcpMorphFadeInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

/*****************************************************************************
 * Class VcpRectangleRotateOutEffect
 *  VcpFadeOutEffect will become rectangle fist, then rotate out to a direction.
 *
 *  support direction:
 *      VCP_EFFECT_DIRECTION_FROM_LEFT
 *      VCP_EFFECT_DIRECTION_FROM_RIGHT
 *  default direction:
 *      VCP_EFFECT_DIRECTION_FROM_LEFT
 *  default duration:
 *      250
 *  affect property:
 *      Opacity, Transform, Anchor, Pos
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpRectangleRotateOutEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Constructor/Destructor>
    // Default constructor
    VcpRectangleRotateOutEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
// Variable
private:
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxTransformTimeline *m_smallTimeline;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxTransformTimeline *m_rotateTimeline;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxFPoint m_backupAnchor;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxPoint  m_backupPos;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxFrame *m_activeFrame;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxMsec   m_duration;
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Variable>
    VfxS32    m_direction;
// Implementation
private:
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_FrameEffect_VcpRectangleRotateOutEffect_Implementation>
    void onSmallStop(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#endif

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
/*****************************************************************************
 * Class VcpTransformerEffect
 *  VcpFadeInEffect provide morphing from one rectangle to the frame rectangle
 *  with fade in effect.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Opacity, Transform, Pos
 *  parameter:
 *      VcpEffectMorphFadeInData
 *****************************************************************************/
class VcpTransformerEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpTransformerEffect_Constructor/Destructor>
    // Default constructor
    VcpTransformerEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
    
// Variable
private:
		// <group DOM_FrameEffect_VcpTransformerEffect_Variable>
    // current support 20 child to effect;
    VfxPointTimeline *m_posTimeline[20];
    // <group DOM_FrameEffect_VcpTransformerEffect_Variable>
    VfxPoint          m_backupPos[20];
    // <group DOM_FrameEffect_VcpTransformerEffect_Variable>
    VfxS32            m_childCount;
    // <group DOM_FrameEffect_VcpTransformerEffect_Variable>
    VfxBool           m_isReverse;
    
// Implementation
private:
    // <group DOM_FrameEffect_VcpTransformerEffect_Implementation>
    void setupTimeline(VfxFrame *frame, VfxU32 index, VfxMsec duration, VfxMsec delay, VfxBool isReverse);
    // <group DOM_FrameEffect_VcpTransformerEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#endif

/*****************************************************************************
 * Class VcpTvCloseEffect
 *  VcpTvCloseEffect provides a TV-Close effect on frame.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Transform
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpTvCloseEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpTvCloseEffect_Constructor/Destructor>
    // Default constructor
    VcpTvCloseEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpTvCloseEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );

    // <group DOM_FrameEffect_VcpTvCloseEffect_Override>
    virtual void restore(VfxFrame *activeFrame);

// Variable
private:
    VfxFloatTimeline *m_tlSy;
    VfxFloatTimeline *m_tlSx;
    VfxFloatTimeline *m_tlOpacity;
    VfxFrame *m_whiteFrame;
    VfxFPoint m_backupAnchor;
    VfxPoint m_backupPos;
    VfxCacheModeEnum m_backupCacheMode;
    
// Implementation
private:
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


#endif /* __VCP_FRAME_EFFECT_H__ */
