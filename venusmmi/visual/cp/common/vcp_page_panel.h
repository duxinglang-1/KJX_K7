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
 *  vcp_page_panel.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Provide a mechanism to transit from a frame to another frame with specific
 *  effect.
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
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_PAGE_H__
#define __VCP_PAGE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_features.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_transform.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_weak_ptr.h"
#include "vfx_animation.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// Pre-define classes

class VcpPagePanel;

enum VcpPageEffectType
{
    VCP_PAGE_EFFECT_NONE,
    VCP_PAGE_EFFECT_FADE_IN,
    VCP_PAGE_EFFECT_FLIP,
    VCP_PAGE_EFFECT_PUSH,
    VCP_PAGE_EFFECT_ENTER,
    VCP_PAGE_EFFECT_LEAVE,
    VCP_PAGE_EFFECT_ZOOM,
    VCP_PAGE_EFFECT_BIG,
    VCP_PAGE_EFFECT_SMALL_FLIP,
    VCP_PAGE_EFFECT_FLIP_OUT_FLIP_IN,
    VCP_PAGE_EFFECT_COSMOS_ENTRY,
    VCP_PAGE_EFFECT_CUBE,
    VCP_PAGE_EFFECT_3D_CIRCLE,
    VCP_PAGE_EFFECT_3D_CUBE_FLY_OUT,
    VCP_PAGE_EFFECT_3D_BLINDS,
    VCP_PAGE_EFFECT_3D_BRICK_FLIP,
    VCP_PAGE_EFFECT_3D_TWIST,
    VCP_PAGE_EFFECT_3D_CURL,
    VCP_PAGE_EFFECT_3D_FUSION,
    VCP_PAGE_EFFECT_3D_RIPPLE,
    VCP_PAGE_EFFECT_END
};

enum VcpPageEffectTypeDirection
{
    VCP_PAGE_DIRECTION_FROM_NONE,
    VCP_PAGE_DIRECTION_FROM_RIGHT,
    VCP_PAGE_DIRECTION_FROM_LEFT,
    VCP_PAGE_DIRECTION_FROM_UP,
    VCP_PAGE_DIRECTION_FROM_BOTTOM,
    VCP_PAGE_DIRECTION_BACKWARD
};

enum VcpPageEffectMode
{
    VCP_PAGE_BOTH,
    VCP_PAGE_TARGET,
    VCP_PAGE_CURRENT
};

class VcpPageFlipPara : public VfxBase
{
public:
    VfxS32 frameWidth;
    VfxS32 frameHeight;
    VfxMatrix4x4 relativeMatrix;
    VfxS32 direction;
    VfxFloat cameraDistance;
    VfxBool isVertical;
};

class VcpPageFlipOutFlipInPara : public VfxBase
{
public:
    VfxS32 frameWidth;
    VfxS32 frameHeight;
    VfxMatrix4x4 relativeMatrix;
    VfxS32 direction;
    VfxBool axisZero;
    VfxFloat cameraDistance;
};

// the input parameter for some effect

struct VcpPageFilpData
{
    VfxFloat cameraDistance;    // camera distance can affect degree of perspective
};

struct VcpPageZoomData
{
    VfxFloat ScaleXonCurrentFrame;  // scale factor in x axis on Current frame (to value)
    VfxFloat ScaleYonCurrentFrame;  // scale factor in y axis on Current frame (to value)
    VfxFloat ScaleXonTargetFrame;   // scale factor in x axis on Target frame  (from value)
    VfxFloat ScaleYonTargetFrame;   // scale factor in y axis on Target frame  (from value)
};

struct VcpPagePageFlipData
{
    VfxBool  outputAlpha;  // scale factor in x axis on Current frame (to value)
    VfxFrame *backSide;
    VfxColor fillColor;
    VfxBool  flipCornerRight;
    VfxBool  C2Mirror;
    VfxBool  C1ShadowDisabled;
    VfxBool  C2ShadowDisabled;
};

struct VcpPage3DCurlEffectData
{
    VfxBool inverse;  
};

class VcpPage3DImageBufferData : public VfxBase
{
public:
    VfxImageSrc oldImageSrc;
    VfxImageSrc newImageSrc;
};

class VcpPageCubePara : public VfxBase
{
public:
    VfxS32 frameWidth;
    VfxS32 frameHeight;
    VfxMatrix4x4 relativeMatrix;
    VfxS32 direction;
    VfxFloat cameraDistance;
};

/*****************************************************************************
 * Class VcpPageBaseEffect
 *  VcpPageBaseEffect provide a basic page effect class. One may inherit this 
 *  class to create different type of effect. This effect can be thought as a 
 *  effect which means no effect.
 *  The effect developer should provide the following information for AP use.
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPageBaseEffect : public VfxObject
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageBaseEffect_Constructor/Destructor>
    // Default constructor
    VcpPageBaseEffect(); 

// Overridable
public:
    // <group DOM_PagePanel_VcpPageBaseEffect_Overridable>
    // to apply an effect on a transition from current frame to target frame.
    // The property of the current frame and target frame may be changed during
    // the effect, but it will reset when the effect is finished.
    // Some effect can change some attribute to have a different view of effect.
    // They can use the *data to pass those parameters. The effect should check
    // the size of *data by dataSize to avoid a serious problem if user pass a
    // wrong parameter.
    virtual void onStart(
        VcpPagePanel *pagePanel,                // [IN] page panel
        VfxFrame *currentFrame,                 // [IN] current frame which will disappear 
        VfxFrame *targetFrame,                  // [IN] target frame which will appear
        VfxMsec duration,                       // [IN] the durtion of the effect
        VcpPageEffectTypeDirection direction,   // [IN] the direction of the effect
        void *data,                             // [IN] parameter to change some attribute
        VfxS32 dataSize                         // [IN] parameter size
        );
    // <group DOM_PagePanel_VcpPageBaseEffect_Overridable>
    // This will be called when effect is finish. The effect can do something about 
    // the active frame. usually reset the frame attribute.
    virtual void onStop(
        VcpPagePanel *pagePanel,                // [IN] page panel
        VfxFrame *lastFrame,                    // [IN] last frame which has disappeared
        VfxFrame *currentFrame                  // [IN] current frame which has appeared
        );
    // <group DOM_PagePanel_VcpPageBaseEffect_Overridable>
    // This will be called when effect is cancel. usually user apply a new effect
    // when the old one is not finished. The effect can do something about the
    // active frame. usually stop the last animation and reset the frame attribute.
    virtual void onCancel(
        VcpPagePanel *pagePanel,                // [IN] page panel
        VfxFrame *lastFrame,                    // [IN] last frame which will disappear
        VfxFrame *currentFrame                  // [IN] current frame which will appear
        );
// Event
public:
    // <group DOM_PagePanel_VcpPageBaseEffect_Event>
    // notify VcpFrameEffect when effect is finished
    // void YourClass::onEndOfEffect()
    VfxSignal0 m_complete;
    
};


/*****************************************************************************
 * Class VcpPagePanel
 *  VcpPagePanel is a helper to switch one frame to another with some effect. It 
 *  help user to create a instance of different effect which inherit from 
 *  VcpPageBaseEffect and do some communication between VcpFrameEffect and that 
 *  instance to finish to effect. The frames that VcpPagePanel will affect must the 
 *  children of VcpPagePanel, and call addChild() of VcpPage will auto hidden that
 *  frame until call switchTo. One may call setCurrentFrame() to unhidden that
 *  frame without do any effect.
 *
 * EXAMPLE
 * <code>
 *  VcpPagePanel *m_pagePanel;
 *  VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
 *  VFX_OBJ_CREATE(m_frame1, VfxFrame, m_pagePanel);
 *  VFX_OBJ_CREATE(m_frame2, VfxFrame, m_pagePanel);
 *  m_pagePanel->setCurrentFrame(m_frame1);
 *  m_pagePanel->switchTo(m_frame2, VCP_PAGE_EFFECT_FLIP, 2000, VCP_PAGE_DIRECTION_FROM_LEFT);
 * </code>
 *****************************************************************************/
class VcpPagePanel : public VfxControl
{
    VFX_DECLARE_CLASS(VcpPagePanel);
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPagePanel_Constructor/Destructor>
    // Default constructor
    VcpPagePanel(); 

// Method
public:
    // <group DOM_PagePanel_VcpPagePanel_Method>
    // to switch to target frame from current frame with specify effect.
    // The property of the current frame and target frame may be changed during
    // the effect, but it will reset when the effect is finished.
    // Some effect can change some attribute to have a different view of effect.
    // They can use the *data to pass those parameters.
    void switchTo(
        VfxFrame *frame,                                                    // [IN] frame which will switch to
        VcpPageEffectType effectType,                                       // [IN] the effect type
        VfxMsec duration = -1,                                              // [IN] the durtion of the effect
        VcpPageEffectTypeDirection direction = VCP_PAGE_DIRECTION_FROM_NONE,// [IN] the direction of the effect
        VfxBool deletePrevious = VFX_FALSE,                                 // [IN] delete the current frame or not
        void *data = NULL,                                                  // [IN] parameter to change some attribute
        VfxS32 dataSize = 0);                                               // [IN] parameter size
    // <group DOM_PagePanel_VcpPagePanel_Method>
    // set current frame and unhidden
    void setCurrentFrame(
        VfxFrame *frame                                                     // [IN/OUT] new current frame 
        );

    // <group DOM_PagePanel_VcpPagePanel_Method>
    // get current frame of page panel 
    VfxFrame *getCurrentFrame()
    {
        return m_currentFramePtr.get();
    }
    
// Override
protected:
    // <group DOM_PagePanel_VcpPagePanel_Override>
    // Init function.
    virtual void onInit();
    // <group DOM_PagePanel_VcpPagePanel_Override>
    // Deinit function.
    virtual void onDeinit();
    // <group DOM_PagePanel_VcpPagePanel_Override>
    virtual void onObjectNotify(VfxId id, void *userData);
    // <group DOM_PagePanel_VcpPagePanel_Implementation>
    void onAddChild(VfxObject *objChild);
    // <group DOM_PagePanel_VcpPagePanel_Implementation>
    void onRemoveChild(VfxObject *objChild);
    
// Event
public:
    // <group DOM_PagePanel_VcpPagePanel_Event>
    // notify APP when effect is finished. the frame which is switched to 
    // will be passed as parameter. The effect is complete or not is also passed.
    // void YourClass::onPagePanelEffectFinished(VfxFrame *targetFrame, VfxBool isCompleted)
    VfxSignal2 <
        VfxFrame *,             // target frame
        VfxBool                 // is completed
        > m_signalFinished;
// Variable
private:
    // <group DOM_PagePanel_VcpPagePanel_Variable>
    VfxFrameWeakPtr m_currentFramePtr;
    // <group DOM_PagePanel_VcpPagePanel_Variable>
    VfxFrameWeakPtr m_previousFramePtr;
    // <group DOM_PagePanel_VcpPagePanel_Variable>
    VfxBool m_deletePrevious;
    // <group DOM_PagePanel_VcpPagePanel_Variable>
    VfxBool m_effectRunning;
    // <group DOM_PagePanel_VcpPagePanel_Variable>
    VcpPageBaseEffect *m_pageEffect;
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPagePanel_Implementation>
    VcpPageBaseEffect *createEffect(VcpPageEffectType type);
    // <group DOM_PagePanel_VcpPagePanel_Implementation>
    void onEndOfEffect();
   
};

/*****************************************************************************
 * Class VcpPageFadeInEffect
 *  VcpPageFadeInEffect provide a Fade-in effect between frames.
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
class VcpPageFadeInEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Constructor/Destructor>
    // Default constructor
    VcpPageFadeInEffect(); 

// Override
public:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Variable>
    VfxFloatTimeline *m_fadeInTimeline;
    // <group DOM_PagePanel_VcpPageFadeInEffect_Variable>
    VfxFloat m_backupOpacity;
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPageFlipEffect
 *  VcpPageFlipEffect provide a Flip effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_RIGHT,
 *      VCP_PAGE_DIRECTION_FROM_LEFT,
 *      VCP_PAGE_DIRECTION_FROM_UP,
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM
 *  default duration:
 *      250
 *  affect property:
 *      Culling, Transform
 *  parameter:
 *      VcpPageFilpData    
 *****************************************************************************/
class VcpPageFlipEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipEffect_Constructor/Destructor>
    // Default constructor
    VcpPageFlipEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFlipEffect_Variable>
    VfxTransformTimeline *m_flipTimeline[2];
    // <group DOM_PagePanel_VcpPageFlipEffect_Variable>
    VfxFrameCullingTypeEnum m_backupCulling[2];
    // <group DOM_PagePanel_VcpPageFlipEffect_Variable>
    VfxTransform m_backupTransform[2];

// Implementation
private:
    // <group DOM_PagePanel_VcpPageFlipEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_PagePanel_VcpPageFlipEffect_Implementation>
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
 * Class VcpPagePushEffect
 *  VcpPagePushEffect provide a Push effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_RIGHT,
 *      VCP_PAGE_DIRECTION_FROM_LEFT,
 *      VCP_PAGE_DIRECTION_FROM_UP,
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM
 *  default duration:
 *      250
 *  affect property:
 *      Pos
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpPagePushEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPagePushEffect_Constructor/Destructor>
    // Default constructor
    VcpPagePushEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPagePushEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPagePushEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPagePushEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
public:
    // <group DOM_PagePanel_VcpPagePushEffect_Variable>
    VcpPageEffectMode m_mode;
private:
    // <group DOM_PagePanel_VcpPagePushEffect_Variable>
    VfxPointTimeline *m_pointTimeline[2];
    // <group DOM_PagePanel_VcpPagePushEffect_Variable>
    VfxPoint m_backupPos[2];
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPagePushEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPageZoomEffect
 *  VcpPageZoomEffect provide a zoom-in(out) effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE,
 *      VCP_PAGE_DIRECTION_BACKWARD
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      250
 *  affect property:
 *      Transform, Opacity,Anchor,Pos
 *  parameter:
 *      VcpPageZoomData
 *****************************************************************************/
class VcpPageZoomEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageZoomEffect_Constructor/Destructor>
    // Default constructor
    VcpPageZoomEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageZoomEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageZoomEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageZoomEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);

// Variable
public:
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VcpPageEffectMode m_mode;
private:
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxTransformTimeline  *m_transformTimeline[2];
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxFloatTimeline *m_opacityTimeline[2];
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxFPoint m_backupAnchor[2];
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxPoint  m_backupPos[2];
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxTransform  m_backupTransform[2];
    // <group DOM_PagePanel_VcpPageZoomEffect_Variable>
    VfxFloat m_backupOpacity[2];
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPageZoomEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPageBigEffect
 *  VcpPageZoomEffect provide a big effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE,
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      300
 *  affect property:
 *      Anchor,Pos
 *  parameter:
 *      NULL
 *****************************************************************************/
class VcpPageBigEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageBigEffect_Constructor/Destructor>
    // Default constructor
    VcpPageBigEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageBigEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageBigEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageBigEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxTransformTimeline  *m_transformTimeline;
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxRectTimeline *m_boundsTimeline;
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxPointTimeline *m_posTimeline;
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxFPoint m_backupAnchor[2];
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxPoint  m_backupPos[2];
    // <group DOM_PagePanel_VcpPageBigEffect_Variable>
    VfxTransform m_backTransform;
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPageBigEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

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
#endif


/*****************************************************************************
 * Class VcpPageSmallFlipEffect
 *  VcpPageSmallFlipEffect provide a small and Flip effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_RIGHT,
 *      VCP_PAGE_DIRECTION_FROM_LEFT,
 *      VCP_PAGE_DIRECTION_FROM_UP,
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM
 *  default duration:
 *      250
 *  affect property:
 *      Culling, Transform
 *  parameter:
 *      VcpPageFilpData 
 *****************************************************************************/
class VcpPageSmallFlipEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Constructor/Destructor>
    // Default constructor
    VcpPageSmallFlipEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
		// <group DOM_PagePanel_VcpPageSmallFlipEffect_Variable>
    VfxTransformTimeline *m_flipTimeline[2];
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Variable>
    VfxFrameCullingTypeEnum m_backupCulling[2];
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Variable>
    VfxTransform m_backupTransform[2];

// Implementation
private:
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Implementation>
    static VfxTimelineInterpolationRetEnum flipHorizontalTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
    // <group DOM_PagePanel_VcpPageSmallFlipEffect_Implementation>
    static VfxTimelineInterpolationRetEnum flipVerticalTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
};


/*****************************************************************************
 * Class VcpPageFlipOutFlipInEffect
 *  VcpPageFlipOutFlipInEffect provide one frame flip out and another frame
 *  flip in effect
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_RIGHT,
 *      VCP_PAGE_DIRECTION_FROM_LEFT,
 *      VCP_PAGE_DIRECTION_FROM_UP,
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM   
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_BOTTOM
 *  default duration:
 *      250
 *  affect property:
 *      Transform
 *  parameter:
 *      VcpPageFilpData  
 *****************************************************************************/
class VcpPageFlipOutFlipInEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPageFlipOutFlipInEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Variable>
    VfxTransformTimeline *m_flipTimeline[2];

// Implementation
private:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    static VfxTimelineInterpolationRetEnum flipHorizontalTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    static VfxTimelineInterpolationRetEnum flipVerticalTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
};


/*****************************************************************************
 * Class VcpPageCosmosEntryEffect
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPageCosmosEntryEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPageCosmosEntryEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Variable>
    VfxFloatTimeline *m_fpeTimeline;

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Variable>
    VfxFrame *m_currentFrame;
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Variable>
    VfxFrame *m_targetFrame;
#endif
// Implementation
private:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);

    static vrt_render_dirty_type_enum firstEffectCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);

    static vrt_render_dirty_type_enum secondEffectCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size);
    
};


/*****************************************************************************
 * Class VcpPageCubeEffect
 *  VcpPageFlipEffect provide a Flip effect between frames.
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_RIGHT,
 *      VCP_PAGE_DIRECTION_FROM_LEFT,  
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_LEFT
 *  default duration:
 *      250
 *  affect property:
 *      Transform
 *  parameter:
 *      VcpPageFilpData    
 *****************************************************************************/
class VcpPageCubeEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipEffect_Constructor/Destructor>
    // Default constructor
    VcpPageCubeEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFlipEffect_Variable>
    VfxTransformTimeline *m_flipTimeline[2];
    // <group DOM_PagePanel_VcpPageFlipEffect_Variable>
    VfxFrameCullingTypeEnum m_backupCulling[2];

// Implementation
private:
    // <group DOM_PagePanel_VcpPageFlipEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    // <group DOM_PagePanel_VcpPageFlipEffect_Implementation>
    static VfxTimelineInterpolationRetEnum rotateTimelineFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 data_size);
};



#endif /* __VCP_PAGE_H__ */

