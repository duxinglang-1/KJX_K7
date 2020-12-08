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
 *  vcp_cube.cpp
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

#include "vcp_frame_effect.h"
#include "vcp_frame_effect_3d.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vcp_frame_effect_type.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_image_src.h"
#include <string.h>


/*****************************************************************************
 * Class VcpBaseEffect
 *****************************************************************************/
 
VcpBaseEffect::VcpBaseEffect()
{
}


void VcpBaseEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(activeFrame);
    VFX_UNUSED(duration);
    VFX_UNUSED(isReverse);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);
    VFX_UNUSED(direction);
    m_complete.postEmit();
}
 
void VcpBaseEffect::onDeinit()
{
    if (m_activeFramePtr.isValid())
    {
        restore(m_activeFramePtr.get());
    }
    VfxObject::onDeinit();
}

void VcpBaseEffect::restore(VfxFrame *activeFrame)
{
    VFX_UNUSED(activeFrame);
}

void VcpBaseEffect::setActiveFrame(VfxFrame *activeFrame)
{
    m_activeFramePtr = activeFrame;
}


/*****************************************************************************
 * static function
 *****************************************************************************/
 
static void setupOpacityTimeline(VfxFloatTimeline *timeline, VfxFrame *target, VfxMsec duration, VfxBool isReverse)
{
    timeline->setTarget(target);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    timeline->setDurationTime(duration);
    timeline->setRepeatCount(1);
    if (isReverse)
    {
        timeline->setFromValue(1.0f);
        timeline->setToValue(0);
    }
    else
    {
        timeline->setFromValue(0);
        timeline->setToValue(1.0f);
    }
    timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
}

/***************************************************************************** 
 * Class VcpFrameEffect
 *****************************************************************************/

VcpFrameEffect::VcpFrameEffect() :
    m_effectRunning(VFX_FALSE),
    m_pageEffect(NULL)
{
}


VcpBaseEffect* VcpFrameEffect::createEffect(VcpEffectType type)
{
    VcpBaseEffect *ret = NULL;
    switch (type)
    {
        case VCP_EFFECT_NONE: 
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
            break;
        case VCP_EFFECT_FADE_IN:
            VFX_OBJ_CREATE(ret, VcpFadeInEffect, this);
            break;
		case VCP_EFFECT_FADE_OUT:
    #if !defined(__MMI_VUI_COSMOS_CP_SLIM__)       
            VFX_OBJ_CREATE(ret, VcpFadeOutEffect, this);
    #else
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
    #endif
            break;
        case VCP_EFFECT_FADE_OUT_WAVE:  // Phase out
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
            break;
        case VCP_EFFECT_FLIP:
            VFX_OBJ_CREATE(ret, VcpFlipEffect, this);
            break;
        case VCP_EFFECT_PHOTOWALL:   // Phase out
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
            break;
        case VCP_EFFECT_POPUP:
            VFX_OBJ_CREATE(ret, VcpPopupEffect, this);
            break;
        case VCP_EFFECT_MORPH_FADE_IN:
            VFX_OBJ_CREATE(ret, VcpMorphFadeInEffect, this);
            break;
        case VCP_EFFECT_FLY_OUT:  // Phase out
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
            break;
        case VCP_EFFECT_RECTANGLE_ROTATE_OUT:
    #if !defined(__MMI_VUI_COSMOS_CP_SLIM__)     
            VFX_OBJ_CREATE(ret, VcpRectangleRotateOutEffect, this);
    #else
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
    #endif
            break;
        case VCP_EFFECT_SMALL_FLIP: // Phase out
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
            break;
        case VCP_EFFECT_TRANSFORMER:
    #if !defined(__MMI_VUI_COSMOS_CP_SLIM__)    
            VFX_OBJ_CREATE(ret, VcpTransformerEffect, this);
    #else
            VFX_OBJ_CREATE(ret, VcpBaseEffect, this);
    #endif
            break;
        case VCP_EFFECT_TVCLOSE:
            VFX_OBJ_CREATE(ret, VcpTvCloseEffect, this);
            break;
#ifdef __COSMOS_3D_V10__
        case VCP_EFFECT_3D_CIRCLE:
            VFX_OBJ_CREATE(ret, Vcp3DCircleEffect, this);
            break;
        case VCP_EFFECT_TITLE_BAR_LIGHT:
            VFX_OBJ_CREATE(ret, VcpTitleBarLightEffect, this);
            break;
		case VCP_EFFECT_3D_BLING:
            VFX_OBJ_CREATE(ret, Vcp3DBlingEffect, this);
            break;
        case VCP_EFFECT_3D_BLUR:
            VFX_OBJ_CREATE(ret, Vcp3DBlurEffect, this);
            break;
#endif /* __COSMOS_3D_V10__ */
        default:
            VFX_ASSERT(0);
            break;
    }
    return ret;
}


void VcpFrameEffect::applyEffect(
    VfxFrame *activeFrame, 
    VcpEffectType EffectType,
    VfxMsec Duration, 
    VcpEffectTypeDirection direction,
    VfxBool isReverse,
    void *data, 
    VfxS32 dataSize)
{    
    
    
    if (m_effectRunning)
    {
        //m_pageEffect->onCancel(activeFrame, m_isReverse);
        //VFX_OBJ_CLOSE(m_pageEffect);
        m_signalFinished.postEmit(m_activeFramePtr.get(), VFX_FALSE);
    }
    
    if (m_pageEffect)
    {
        VFX_OBJ_CLOSE(m_pageEffect);
        m_pageEffect = NULL;
    }

    m_effectRunning = VFX_TRUE;
    m_activeFramePtr = activeFrame;
    m_isReverse = isReverse;
   
    m_pageEffect = createEffect(EffectType);
    m_pageEffect->setActiveFrame(activeFrame);
    m_pageEffect->m_complete.connect(this, &VcpFrameEffect::onEndOfEffect);
    m_pageEffect->onStart(activeFrame, Duration, direction, isReverse, data, dataSize);
}


void VcpFrameEffect::restore(void)
{
    if (m_effectRunning)
    {
        m_signalFinished.postEmit(m_activeFramePtr.get(), VFX_FALSE);
    }
    if (m_pageEffect)
    {
        VFX_OBJ_CLOSE(m_pageEffect);
        m_pageEffect = NULL;
    }
}


void VcpFrameEffect::onDeinit()
{
    if (m_effectRunning)
    {
        m_signalFinished.postEmit(m_activeFramePtr.get(), VFX_FALSE);
    }
    VfxObject::onDeinit();
}


void VcpFrameEffect::onEndOfEffect(void)
{
    //m_pageEffect->onStop(m_activeFramePtr.get(), m_isReverse);
    //VFX_OBJ_CLOSE(m_pageEffect);
    m_effectRunning = VFX_FALSE;
    m_signalFinished.postEmit(m_activeFramePtr.get(), VFX_TRUE);
}

/*****************************************************************************
 * Class VcpFadeInEffect
 *****************************************************************************/

VcpFadeInEffect::VcpFadeInEffect():
    m_fadeInTimeline(NULL)
{
}


void VcpFadeInEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(direction);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    if (duration == -1)
    {
        duration = 250;
    }

    if (m_fadeInTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_fadeInTimeline, VfxFloatTimeline, this);
    }
    
    setupOpacityTimeline(m_fadeInTimeline, activeFrame, duration, isReverse);
    m_fadeInTimeline->m_signalStopped.connect(this, &VcpFadeInEffect::onEndOfEffect); 
    m_fadeInTimeline->start();
}

void VcpFadeInEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpFadeOutEffect
 *****************************************************************************/

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

VcpFadeOutEffect::VcpFadeOutEffect():
    m_fadeInTimeline(NULL),
    m_smallTimeline(NULL)
{
}

void VcpFadeOutEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(direction);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    if (duration == -1)
    {
        duration = 250;
    }

    if (m_fadeInTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_fadeInTimeline, VfxFloatTimeline, this);
    }
    
    setupOpacityTimeline(m_fadeInTimeline, activeFrame, duration, !isReverse);
    m_fadeInTimeline->m_signalStopped.connect(this, &VcpFadeOutEffect::onEndOfEffect); 
    m_fadeInTimeline->start();

	m_backupPos = activeFrame->getPos();
    m_backupAnchor = activeFrame->getAnchor();
	activeFrame->setPos(VfxPoint(
                            (VfxS32)(m_backupPos.x - activeFrame->getBounds().getWidth() * m_backupAnchor.x + activeFrame->getBounds().getWidth()/2), 
                            (VfxS32)(m_backupPos.y - activeFrame->getBounds().getWidth() * m_backupAnchor.y + activeFrame->getBounds().getHeight()/2))
                            );
	activeFrame->setAnchor(VfxFPoint(0.5,0.5));
	VfxTransform tempTransform;
	tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;       
    tempTransform.data.affine.sx = 0.9f;
    tempTransform.data.affine.sy = 0.9f;

	if (m_smallTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_smallTimeline, VfxTransformTimeline, this);
    }
	m_smallTimeline->setTarget(activeFrame);
    m_smallTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_smallTimeline->setDurationTime(duration/4);
    m_smallTimeline->setRepeatCount(1);
    m_smallTimeline->setFromValue(VfxTransform());
    m_smallTimeline->setToValue(tempTransform);
    m_smallTimeline->setIsFromCurrent(VFX_FALSE);
    m_smallTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
	m_smallTimeline->start();
	
}

void VcpFadeOutEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setPos(m_backupPos);
	activeFrame->setAnchor(m_backupAnchor);
}

void VcpFadeOutEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

#endif

/*****************************************************************************
 * Class VcpFlipEffect
 *****************************************************************************/

VcpFlipEffect::VcpFlipEffect():
    m_flipTimeline(NULL)
{
}


void VcpFlipEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VfxFloat tempCameraDistance = 240;
    VfxBool  isBackCulling = VFX_TRUE;

    if (duration == -1)
    {
        duration = 250;
    }
    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpEffectFilpData));
        tempCameraDistance = ((VcpEffectFilpData*)data)->cameraDistance;
        isBackCulling = ((VcpEffectFilpData*)data)->isBackCulling;
    }
    VcpFlipPara flipPara;

    m_direction = direction;
    m_backupCulling = activeFrame->getCullingType();
    if (isBackCulling)
    {
        activeFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    }
    if (m_flipTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_flipTimeline, VfxTransformTimeline, this);
    }

    m_flipTimeline->setTarget(activeFrame);
    m_flipTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_flipTimeline->setDurationTime(duration);
    m_flipTimeline->setRepeatCount(1);        
    
    
    flipPara.frameWidth = activeFrame->getBounds().getWidth();
    flipPara.frameHeight = activeFrame->getBounds().getHeight();
    flipPara.cameraDistance = tempCameraDistance;
    flipPara.isReverse = isReverse;
    if (direction == VCP_EFFECT_DIRECTION_FROM_RIGHT || direction == VCP_EFFECT_DIRECTION_FROM_UP)
    {
        flipPara.direction = 1;
    }
    else
    {
        flipPara.direction = -1;
    }
            
    if (direction == VCP_EFFECT_DIRECTION_FROM_RIGHT || direction == VCP_EFFECT_DIRECTION_FROM_LEFT)
    {
        flipPara.isVertical = VFX_FALSE;
        if (!isReverse)
        {
            flipPara.relativeMatrix = VfxMatrix4x4(-1,0,0,0,
                                        0,1,0,0,
                                        0,0,-1,0,
                                        (VfxFloat)(activeFrame->getBounds().getWidth()/2),(VfxFloat)(-1*activeFrame->getBounds().getHeight()/2),0,1);
        }
        else
        {
            flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                           0,1,0,0,
                                           0,0,1,0,
                                           (VfxFloat)(-1*activeFrame->getBounds().getWidth()/2),(VfxFloat)(-1*activeFrame->getBounds().getHeight()/2),0,1);
        }
    }
    else
    {
        flipPara.isVertical = VFX_TRUE;
        if (!isReverse)
        {
            flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                       0,-1,0,0,
                                       0,0,-1,0,
                                       (VfxFloat)(-1*activeFrame->getBounds().getWidth()/2),(VfxFloat)(activeFrame->getBounds().getHeight()/2),0,1);
        }
        else
        {
            flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                           0,1,0,0,
                                           0,0,1,0,
                                           (VfxFloat)(-1*activeFrame->getBounds().getWidth()/2),(VfxFloat)(-1*activeFrame->getBounds().getHeight()/2),0,1);
        }
    }
    m_flipTimeline->setCustomInterpolateFunc(VcpFlipEffect::flipTimelineFunc,&flipPara,sizeof(flipPara));
    m_flipTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_flipTimeline->m_signalStopped.connect(this, &VcpFlipEffect::onEndOfEffect); 
    m_flipTimeline->start();
}

void VcpFlipEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setCullingType(m_backupCulling);
}

void VcpFlipEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


VfxTimelineInterpolationRetEnum VcpFlipEffect::flipTimelineFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 data_size)
{
    VFX_UNUSED(fromValue);
    VFX_UNUSED(toValue);
    VFX_ASSERT(typeId == VFX_TYPE_ID_TRANSFORM);
    VFX_ASSERT(data_size == sizeof(VcpFlipPara));
    VcpFlipPara *flipPara = (VcpFlipPara*)data;
    VfxTransform *transform = (VfxTransform*)output;
    VfxFloat tempYAngle =  t * (180) * flipPara->direction;
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
    VfxFloat cameraDistance;

    if (t == 1 && !flipPara->isReverse)
    {
        transform->type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        transform->setIdentity();
        return VFX_TIMELINE_INTERPOLATION_RET_DONE;
    }

    if (flipPara->isVertical)
    {
        RotatebyYMatrix.setRotateByX(VFX_DEG_TO_RAD(tempYAngle));
    }
    else
    {
        RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));
    }
   
    cameraDistance = flipPara->cameraDistance + flipPara->frameWidth/2 * vfxSin(VFX_ABS(tempYAngle)/180 * VFX_PI);

    totalProject.setCamera(
        1.0f,
        1.0f, 
        (VfxFloat)(flipPara->frameWidth/2), 
        (VfxFloat)(flipPara->frameHeight/2), 
        flipPara->cameraDistance, 
        cameraDistance, 
        0.0f,
        0.0f, 
        0.0f);
    
    totalProject *= RotatebyYMatrix;
    totalProject *= flipPara->relativeMatrix;
    totalProject.initMatrix3x3(transform->data.matrix3x3);
    transform->type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    
    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}


/*****************************************************************************
 * Class VcpPopupEffect
 *****************************************************************************/
VcpPopupEffect::VcpPopupEffect():
    m_fadeInTimeline(NULL),
    m_transformTimeline(NULL)
{
}


void VcpPopupEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(direction);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);
    if (duration == -1)
    {
        duration = 500;
    }

    if (m_fadeInTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_fadeInTimeline, VfxFloatTimeline, this);
    }
    setupOpacityTimeline(m_fadeInTimeline, activeFrame, duration, isReverse);
    m_fadeInTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_fadeInTimeline->start();
    
    
    VfxTransform tempTransform;
    
    if (m_transformTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_transformTimeline, VfxTransformTimeline, this);
    }
    m_backupAnchor = activeFrame->getAnchor();
    m_backupPos = activeFrame->getPos();

    // if anchor already 0.5, 0.5 do not setPos and Anchor to avoiding rounding error
    if (m_backupAnchor.x != 0.5f || m_backupAnchor.y != 0.5f)
    {
        activeFrame->setPos(VfxPoint(
                                (VfxS32)(m_backupPos.x - activeFrame->getBounds().getWidth() * m_backupAnchor.x + activeFrame->getBounds().getWidth()/2),
                                (VfxS32)(m_backupPos.y - activeFrame->getBounds().getHeight() * m_backupAnchor.y + activeFrame->getBounds().getHeight()/2)
                                ));
        activeFrame->setAnchor(VfxFPoint(0.5,0.5));
    }

    tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransform.data.affine.sx = 0.5f;
    tempTransform.data.affine.sy = 0.5f;
    
    m_transformTimeline->setTarget(activeFrame);
    m_transformTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_transformTimeline->setDurationTime(duration);
    m_transformTimeline->setRepeatCount(1);

    if (isReverse)
    {
        m_transformTimeline->setFromValue(VfxTransform(VFX_TRANSFORM_TYPE_AFFINE));
        m_transformTimeline->setToValue(tempTransform);
        m_transformTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    }
    else
    {
        m_transformTimeline->setFromValue(tempTransform);
        m_transformTimeline->setToValue(VfxTransform(VFX_TRANSFORM_TYPE_AFFINE));
        m_transformTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_DAMPING_OUT);
        
    }
    m_transformTimeline->m_signalStopped.connect(this, &VcpPopupEffect::onEndOfEffect); 
    m_transformTimeline->start();
    
}


void VcpPopupEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setPos(m_backupPos);
    activeFrame->setAnchor(m_backupAnchor);
}


void VcpPopupEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpMorphFadeInEffect
 *****************************************************************************/

VcpMorphFadeInEffect::VcpMorphFadeInEffect():
    m_fadeInTimeline(NULL),
    m_posTimeline(NULL),
    m_transformTimeline(NULL)
{
}


void VcpMorphFadeInEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(direction);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    if (duration == -1)
    {
        duration = 250;
    }

    VfxRect fromRect = VfxRect(
                            activeFrame->getPos().x + activeFrame->getSize().width, 
                            activeFrame->getPos().y + activeFrame->getSize().height, 
                            activeFrame->getSize().width/2, 
                            activeFrame->getSize().height/2
                            );

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpEffectMorphFadeInData));
        fromRect = ((VcpEffectMorphFadeInData*)data)->fromRect;
    }
    
    if (m_fadeInTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_fadeInTimeline, VfxFloatTimeline, this);
    }
    setupOpacityTimeline(m_fadeInTimeline, activeFrame, duration, isReverse);
    m_fadeInTimeline->m_signalStopped.connect(this, &VcpMorphFadeInEffect::onEndOfEffect); 
    m_fadeInTimeline->start();

    if (m_posTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_posTimeline, VfxPointTimeline, this);
    }
    m_posTimeline->setTarget(activeFrame);
    m_posTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
    m_posTimeline->setDurationTime(duration);
    m_posTimeline->setRepeatCount(1);

    if (isReverse)
    {
        m_posTimeline->setFromValue(VfxPoint(activeFrame->getPos()));
        m_posTimeline->setToValue(VfxPoint(fromRect.getX(), fromRect.getY()));
    }
    else
    {
        m_posTimeline->setFromValue(VfxPoint(fromRect.getX(), fromRect.getY()));
        m_posTimeline->setToValue(activeFrame->getPos());
    }
    m_posTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_posTimeline->start();


    if (m_transformTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_transformTimeline, VfxTransformTimeline, this);
    }
    m_transformTimeline->setTarget(activeFrame);
    m_transformTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_transformTimeline->setDurationTime(duration);
    m_transformTimeline->setRepeatCount(1);

    VfxTransform tempTransform;
    tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
    tempTransform.data.affine.sx = (VfxFloat)fromRect.getWidth()/activeFrame->getSize().width;
    tempTransform.data.affine.sy = (VfxFloat)fromRect.getHeight()/activeFrame->getSize().height;

    if (isReverse)
    {
        m_transformTimeline->setFromValue(VfxTransform());
        m_transformTimeline->setToValue(tempTransform);
    }
    else
    {
        m_transformTimeline->setFromValue(tempTransform);
        m_transformTimeline->setToValue(VfxTransform());
    }
    m_transformTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_transformTimeline->start();

    
}

void VcpMorphFadeInEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpRectangleRotateOutEffect
 *****************************************************************************/
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

VcpRectangleRotateOutEffect::VcpRectangleRotateOutEffect():
    m_fadeInTimeline(NULL),
    m_smallTimeline(NULL),
    m_rotateTimeline(NULL)
{
}

void VcpRectangleRotateOutEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(direction);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    if (duration == -1)
    {
        duration = 250;
    }

    m_activeFrame = activeFrame;
    m_duration = duration;

    if (direction == VCP_EFFECT_DIRECTION_FROM_RIGHT)
    {
        m_direction = 1;
    }
    else
    {
        m_direction = -1;
    }
    
	m_backupPos = activeFrame->getPos();
    m_backupAnchor = activeFrame->getAnchor();
	activeFrame->setPos(VfxPoint(
                            (VfxS32)(m_backupPos.x - activeFrame->getBounds().getWidth() * m_backupAnchor.x + activeFrame->getBounds().getWidth()/2), 
                            (VfxS32)(m_backupPos.y - activeFrame->getBounds().getWidth() * m_backupAnchor.y + activeFrame->getBounds().getHeight()/2))
                            );
	activeFrame->setAnchor(VfxFPoint(0.5,0.5));
	VfxTransform tempTransform;
	tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;

    if (activeFrame->getSize().width > activeFrame->getSize().height)
    {
        tempTransform.data.affine.sx = (VfxFloat)activeFrame->getSize().height / activeFrame->getSize().width; 
    }
    else
    {
        tempTransform.data.affine.sy = activeFrame->getSize().width / (VfxFloat)activeFrame->getSize().height;
    }
	if (m_smallTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_smallTimeline, VfxTransformTimeline, this);
    }
	m_smallTimeline->setTarget(activeFrame);
    m_smallTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_smallTimeline->setDurationTime(duration/2);
    m_smallTimeline->setRepeatCount(1);
    m_smallTimeline->setFromValue(VfxTransform());
    m_smallTimeline->setToValue(tempTransform);
    m_smallTimeline->setIsFromCurrent(VFX_FALSE);
    m_smallTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_smallTimeline->m_signalStopped.connect(this, &VcpRectangleRotateOutEffect::onSmallStop); 
	m_smallTimeline->start();
	
}


void VcpRectangleRotateOutEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setPos(m_backupPos);
	activeFrame->setAnchor(m_backupAnchor);
}


void VcpRectangleRotateOutEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


void VcpRectangleRotateOutEffect::onSmallStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        VfxTransform tempTransform;
        VfxS32 shortEdge;
    	tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;


        tempTransform.data.affine.sx = ((VfxTransformTimeline *)timeline)->getToValue().data.affine.sx / 4;
        tempTransform.data.affine.sy = ((VfxTransformTimeline *)timeline)->getToValue().data.affine.sy / 4;

        if (m_activeFrame->getSize().width > m_activeFrame->getSize().height)
        {
            shortEdge = m_activeFrame->getSize().height;
        }
        else
        {
            shortEdge = m_activeFrame->getSize().width;
        }
        tempTransform.data.affine.tx = (VfxFloat)m_direction * shortEdge/2;
        tempTransform.data.affine.ty = (VfxFloat)m_direction * shortEdge/2;
            
        tempTransform.data.affine.rz = VFX_DEG_TO_RAD(90);

        
    	if (m_rotateTimeline == NULL)
        {
            VFX_OBJ_CREATE(m_rotateTimeline, VfxTransformTimeline, this);
        }
    	m_rotateTimeline->setTarget(m_activeFrame);
        m_rotateTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_rotateTimeline->setDurationTime(m_duration/2);
        m_rotateTimeline->setRepeatCount(1);
        m_rotateTimeline->setFromValue(((VfxTransformTimeline *)timeline)->getToValue());
        m_rotateTimeline->setToValue(tempTransform);
        m_rotateTimeline->setIsFromCurrent(VFX_FALSE);
        m_rotateTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    	m_rotateTimeline->start();

        if (m_fadeInTimeline == NULL)
        {
            VFX_OBJ_CREATE(m_fadeInTimeline, VfxFloatTimeline, this);
        }
        m_fadeInTimeline->setTarget(m_activeFrame);
        m_fadeInTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_fadeInTimeline->setDurationTime(m_duration/2);
        m_fadeInTimeline->setRepeatCount(1);
        
        m_fadeInTimeline->setFromValue(1.0f);
        m_fadeInTimeline->setToValue(0);
            
        m_fadeInTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_fadeInTimeline->m_signalStopped.connect(this, &VcpRectangleRotateOutEffect::onEndOfEffect); 
        m_fadeInTimeline->start();
    }
}

#endif

/*****************************************************************************
 * Class VcpTransformerEffect
 *****************************************************************************/
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

VcpTransformerEffect::VcpTransformerEffect()
{
    VfxS32 i;
    for (i = 0; i < 20; i++)
    {
        m_posTimeline[i] = NULL;
    }
}


void VcpTransformerEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
    m_isReverse = isReverse;
    m_childCount = 0;
    if (!activeFrame->getFirstChildFrame())
    {
        // no chlid
        m_complete.emit();
        return;
    }
    
    // get the total count first
    VfxFrame *tempFrame = activeFrame->getFirstChildFrame();
    while (tempFrame)
    {
        m_childCount ++;
        tempFrame = tempFrame->getNextFrame();
    }

    // current support child effect max number 20
    VFX_ASSERT(m_childCount <= 20);

    // setup each frame timeline
    // each frame duration = 3 time Unit
    // and delay is 1 time unit follow by previous one.
    VfxS32 count = 0;
    VfxMsec timeUnit = duration/(3 + m_childCount - 1);
    tempFrame = activeFrame->getFirstChildFrame();
    
    while (tempFrame)
    {
        m_backupPos[count] = tempFrame->getPos();
        setupTimeline(tempFrame, count, 3 * timeUnit, timeUnit * count, isReverse);
        count ++;
        tempFrame = tempFrame->getNextFrame();
    }

    m_posTimeline[m_childCount-1]->m_signalStopped.connect(this, &VcpTransformerEffect::onEndOfEffect);
    
}


void VcpTransformerEffect::restore(VfxFrame *activeFrame)
{
    VfxS32 count = 0;
    VfxFrame *tempFrame = activeFrame->getFirstChildFrame();
    if (tempFrame == NULL)
    {   
        // no child
        return;
    }

    while (tempFrame)
    {
        tempFrame->setPos(m_backupPos[count]);
        count ++;
        tempFrame = tempFrame->getNextFrame();
    }  
}
    
void VcpTransformerEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        m_complete.emit();
    }
}


void VcpTransformerEffect::setupTimeline(VfxFrame *frame, VfxU32 index, VfxMsec duration, VfxMsec delay, VfxBool isReverse)
{
    VfxS32 midPointX = frame->getRect().getMidX();
    VfxS32 midPointY = frame->getRect().getMidY();
    
    VfxS32 difX;
    VfxS32 difY;

    VfxFrame *parent = frame->getParentFrame();
    VfxBool fromLeft, fromUp;

    if (midPointX <= parent->getSize().width/2)
    {
        fromLeft = VFX_TRUE;
        difX = midPointX;
    }
    else
    {
        fromLeft = VFX_FALSE;
        difX = parent->getSize().width - midPointX;
    }

    if (midPointY <= parent->getSize().height/2)
    {
        fromUp= VFX_TRUE;
        difY = midPointY;
    }
    else
    {
        fromUp= VFX_FALSE;
        difY = parent->getSize().height - midPointY;
    }

    VfxPoint fromValue;

    if (difX <= difY)
    {
        if (fromLeft)
        {
            fromValue = VfxPoint((VfxS32)(0 - (1 - frame->getAnchor().x) * frame->getSize().width), frame->getPos().y);
        }
        else
        {
            fromValue = VfxPoint((VfxS32)(parent->getSize().width + frame->getAnchor().x * frame->getSize().width), frame->getPos().y);
        }
    }
    else
    {
        if (fromUp)
        {
            fromValue = VfxPoint(frame->getPos().x, (VfxS32)(0 - (1 - frame->getAnchor().y) * frame->getSize().height));
        }
        else
        {
            fromValue = VfxPoint(frame->getPos().x, (VfxS32)(parent->getSize().height + frame->getAnchor().y * frame->getSize().height));
        }
    }

    VFX_OBJ_CREATE(m_posTimeline[index], VfxPointTimeline, this);
    m_posTimeline[index]->setTarget(frame);
    m_posTimeline[index]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
    m_posTimeline[index]->setDurationTime(duration);
    m_posTimeline[index]->setStartTime(delay);
    //m_posTimeline[index]->m_signalStopped.connect(this, &VcpTransformerEffect::onEndOfEffect);

    if (isReverse)
    {
        m_posTimeline[index]->setFromValue(frame->getPos());
        m_posTimeline[index]->setToValue(fromValue);
    }
    else
    {
        m_posTimeline[index]->setFromValue(fromValue);
        m_posTimeline[index]->setToValue(frame->getPos());
        // delay time should be at fromValue
        frame->setPos(fromValue);
    }
    m_posTimeline[index]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_posTimeline[index]->start();
}

#endif

/*****************************************************************************
 * Class VcpTvCloseEffect
 *****************************************************************************/

VcpTvCloseEffect::VcpTvCloseEffect() :
    m_tlSy(NULL),
    m_tlSx(NULL),
    m_tlOpacity(NULL),
    m_whiteFrame(NULL),
    m_backupAnchor(0.0f, 0.0f),
    m_backupPos(0, 0)
{
}


static VfxFloat VcpTvCloseTimingFuncCallback(VfxFloat t, void *data, VfxU32 dataSize)
{
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);

    VfxFloat x = 1.0f - t;
    VfxFloat v = 1.0f - x*x*x*x;

    v = (v < 0.0f) ? (0.0f) : (v);
    v = (v > 1.0f) ? (1.0f) : (v);
    return v;
}


void VcpTvCloseEffect::onStart(VfxFrame *activeFrame, VfxMsec duration, VcpEffectTypeDirection direction, VfxBool isReverse, void *data, VfxS32 dataSize)
{
    VfxMsec duration1 = duration * 7 / 8;
    VfxMsec duration2 = duration - duration1;

    // backup cacheMode
    m_backupCacheMode = activeFrame->getCacheMode();
    activeFrame->setCacheMode(VFX_CACHE_MODE_FREEZE);

    // backup anchor and pos
    m_backupAnchor = activeFrame->getAnchor();
    m_backupPos = activeFrame->getPos();

    // if anchor already 0.5, 0.5 do not setPos and Anchor to avoiding rounding error
    if (m_backupAnchor.x != 0.5f || m_backupAnchor.y != 0.5f)
    {
        activeFrame->setPos(VfxPoint(
                                (VfxS32)(m_backupPos.x - activeFrame->getBounds().getWidth() * m_backupAnchor.x + activeFrame->getBounds().getWidth()/2),
                                (VfxS32)(m_backupPos.y - activeFrame->getBounds().getHeight() * m_backupAnchor.y + activeFrame->getBounds().getHeight()/2)
                                ));

        activeFrame->setAnchor(VfxFPoint(0.5f, 0.5f));
    }

    // create white frame
    if (m_whiteFrame == NULL)
    {
        VFX_OBJ_CREATE(m_whiteFrame, VfxFrame, activeFrame);
        m_whiteFrame->setBgColor(VFX_COLOR_WHITE);
        m_whiteFrame->setOpacity(0.0f);
        m_whiteFrame->setSize(activeFrame->getSize());
    }

    // scale Y timeline
    if (m_tlSy == NULL)
    {
        VFX_OBJ_CREATE(m_tlSy, VfxFloatTimeline, this);
    }
    m_tlSy->setTarget(activeFrame);
    m_tlSy->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SY);
    m_tlSy->setDurationTime(duration1);
    m_tlSy->setRepeatCount(1);
    //m_tlSy->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tlSy->setCustomTimingFunc(VcpTvCloseTimingFuncCallback, NULL, 0);
    m_tlSy->setFromValue(1.0f);
    m_tlSy->setToValue(1.0f/activeFrame->getSize().height);

    // scale X timeline
    if (m_tlSx == NULL)
    {
        VFX_OBJ_CREATE(m_tlSx, VfxFloatTimeline, this);
    }
    m_tlSx->setTarget(activeFrame);
    m_tlSx->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_SX);
    m_tlSx->setStartTime(duration1);
    m_tlSx->setDurationTime(duration2);
    m_tlSx->setRepeatCount(1);
    //m_tlSx->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tlSx->setCustomTimingFunc(VcpTvCloseTimingFuncCallback, NULL, 0);
    m_tlSx->setFromValue(1.0f);
    m_tlSx->setToValue(0.0f);

    // opacity timeline
    if (m_tlOpacity == NULL)
    {
        VFX_OBJ_CREATE(m_tlOpacity, VfxFloatTimeline, this);
    }
    m_tlOpacity->setTarget(m_whiteFrame);
    m_tlOpacity->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_tlOpacity->setDurationTime(duration1 + duration2);
    m_tlOpacity->setRepeatCount(1);
    //m_tlOpacity->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tlOpacity->setCustomTimingFunc(VcpTvCloseTimingFuncCallback, NULL, 0);
    m_tlOpacity->setFromValue(0.0f);
    m_tlOpacity->setToValue(1.0f);

    m_tlOpacity->m_signalStopped.connect(this, &VcpTvCloseEffect::onEndOfEffect); 

    m_tlSy->start();
    m_tlSx->start();
    m_tlOpacity->start();
}


void VcpTvCloseEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setPos(m_backupPos);
    activeFrame->setAnchor(m_backupAnchor);

    activeFrame->setCacheMode(m_backupCacheMode);

    VFX_OBJ_CLOSE(m_whiteFrame);
}


void VcpTvCloseEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        m_complete.emit();
    }
}

