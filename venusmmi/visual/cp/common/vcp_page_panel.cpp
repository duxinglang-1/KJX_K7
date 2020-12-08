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
 *  vcp_page_panel.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
#include "vcp_page_panel.h"
#include "vcp_page_panel_3d.h"
#include "vadp_mmi_frm.h"
extern "C" 
{
    #include "MMIDataType.h"
    //#include "pageflip.h"
}
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_basic_type.h"

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
#include "mmi_rp_srv_venus_component_page_panel_def.h"
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Class VcpPageBaseEffect
 *****************************************************************************/
 
VcpPageBaseEffect::VcpPageBaseEffect()
{
}


void VcpPageBaseEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(currentFrame);
    VFX_UNUSED(targetFrame);
    VFX_UNUSED(duration);
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);
    VFX_UNUSED(direction);
    m_complete.postEmit();
}


void VcpPageBaseEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
}


void VcpPageBaseEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
}

/***************************************************************************** 
 * Class VcpPagePanel
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpPagePanel", VcpPagePanel, VfxControl);

VcpPagePanel::VcpPagePanel() :
    m_currentFramePtr(NULL),
    m_previousFramePtr(NULL),
    m_effectRunning(VFX_FALSE)
{
}


void VcpPagePanel::onInit()
{   
    VfxControl::onInit(); 
}


void VcpPagePanel::onDeinit()
{ 
    if (m_effectRunning)
    {
        m_pageEffect->onCancel(this, m_previousFramePtr.get(), m_currentFramePtr.get());
        VFX_OBJ_CLOSE(m_pageEffect);
        m_effectRunning = VFX_FALSE;
        m_signalFinished.postEmit(m_currentFramePtr.get(), VFX_FALSE);
    }
    VfxControl::onDeinit();
}


void VcpPagePanel::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            onAddChild((VfxObject*) userData);
        }
        case VFX_OBJECT_NOTIFY_ID_REMOVE_CHILD:
        {
            onRemoveChild((VfxObject*) userData);
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
        }
    }
}


VcpPageBaseEffect* VcpPagePanel::createEffect(VcpPageEffectType type)
{
    VcpPageBaseEffect *ret = NULL;
    switch (type)
    {
        case VCP_PAGE_EFFECT_NONE: 
            VFX_OBJ_CREATE(ret, VcpPageBaseEffect, this);
            break;
        case VCP_PAGE_EFFECT_FADE_IN:
            VFX_OBJ_CREATE(ret, VcpPageFadeInEffect, this);
            break;
        case VCP_PAGE_EFFECT_FLIP:
            VFX_OBJ_CREATE(ret, VcpPageFlipEffect, this);
            break;
        case VCP_PAGE_EFFECT_PUSH:
            VFX_OBJ_CREATE(ret, VcpPagePushEffect, this);
            break;
        case VCP_PAGE_EFFECT_ENTER:
            {
                VcpPagePushEffect *pushEffect;
                VFX_OBJ_CREATE(pushEffect, VcpPagePushEffect, this);
                pushEffect->m_mode = VCP_PAGE_TARGET;
                ret = pushEffect;
            }
            break;
        case VCP_PAGE_EFFECT_LEAVE:
            {
                VcpPagePushEffect *pushEffect;
                VFX_OBJ_CREATE(pushEffect, VcpPagePushEffect, this);
                pushEffect->m_mode = VCP_PAGE_CURRENT;
                ret = pushEffect;
            }
            break;
        case VCP_PAGE_EFFECT_ZOOM:
            {
                VcpPageZoomEffect *zoomEffect;
                VFX_OBJ_CREATE(zoomEffect, VcpPageZoomEffect, this);
                zoomEffect->m_mode = VCP_PAGE_BOTH;
                ret = zoomEffect;
            }
            break;

		case VCP_PAGE_EFFECT_BIG:  // Phase out
            {
                VFX_OBJ_CREATE(ret, VcpPageBaseEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_SMALL_FLIP:
            {
            #if !defined(__MMI_VUI_COSMOS_CP_SLIM__)    
                VFX_OBJ_CREATE(ret, VcpPageSmallFlipEffect, this);
            #else
                VFX_OBJ_CREATE(ret, VcpPageBaseEffect, this);
            #endif
            }
            break;
        case VCP_PAGE_EFFECT_FLIP_OUT_FLIP_IN: // Phase out
            {
                VFX_OBJ_CREATE(ret, VcpPageBaseEffect, this);
            }
            break;      
        case VCP_PAGE_EFFECT_COSMOS_ENTRY:
            {
                VFX_OBJ_CREATE(ret, VcpPageCosmosEntryEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_CUBE:
            {
                VFX_OBJ_CREATE(ret, VcpPageCubeEffect, this);
            }
            break;
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
  	    case VCP_PAGE_EFFECT_3D_CIRCLE:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DCircleEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_CUBE_FLY_OUT:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DCubeFlyOutEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_BLINDS:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DBlindsEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_BRICK_FLIP:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DBrickFlipEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_TWIST:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DTwistEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_CURL:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DCurlEffect, this);
            }
            break;
         case VCP_PAGE_EFFECT_3D_FUSION:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DFusionEffect, this);
            }
            break;
        case VCP_PAGE_EFFECT_3D_RIPPLE:
            {
                VFX_OBJ_CREATE(ret, VcpPage3DRippleEffect, this);
            }
            break;
#endif /* __COSMOS_3D_V10__ */
        default:
            VFX_ASSERT(0);
            break;
    }
    return ret;
}


void VcpPagePanel::onAddChild(VfxObject *objChild)
{ 
    VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(objChild, VfxFrame);
    if (frame)
    {
        frame->setHidden(VFX_TRUE);
    }
    VfxControl::onAddChild(objChild);
}


void VcpPagePanel::onRemoveChild(VfxObject *objChild)
{ 
    VfxControl::onRemoveChild(objChild);

    VfxFrame *frame = VFX_OBJ_DYNAMIC_CAST(objChild, VfxFrame);
    if (frame)
    {
        frame->setHidden(VFX_FALSE);
    }
}


void VcpPagePanel::switchTo(
    VfxFrame *frame, 
    VcpPageEffectType effectType,
    VfxMsec duration, 
    VcpPageEffectTypeDirection direction,
    VfxBool deletePrevious, 
    void *data, 
    VfxS32 dataSize)
{
    VFX_ASSERT(frame->getParentFrame() == this);

    if (m_currentFramePtr == frame)
    {
        // the current frame already eqaul the frame switchTo do nothing
        return;
    }
    
    if (m_effectRunning)
    {
        m_pageEffect->onCancel(this, m_previousFramePtr.get(), m_currentFramePtr.get());
        VFX_OBJ_CLOSE(m_pageEffect);
        if (m_deletePrevious)
        {
            VFX_OBJ_CLOSE(m_previousFramePtr);
        }
        else
        {
            if (m_previousFramePtr.isValid())
            {
                m_previousFramePtr->setHidden(VFX_TRUE);
            }
        }
        m_signalFinished.postEmit(m_currentFramePtr.get(), VFX_FALSE);
    }

    m_effectRunning = VFX_TRUE;
   
    m_deletePrevious = deletePrevious;
    frame->bringToFront();
    frame->setHidden(VFX_FALSE);
    m_pageEffect = createEffect(effectType);
    m_pageEffect->m_complete.connect(this, &VcpPagePanel::onEndOfEffect);
    m_pageEffect->onStart(this, m_currentFramePtr.get(), frame, duration, direction, data, dataSize);
    m_previousFramePtr = m_currentFramePtr;
    m_currentFramePtr = frame;
 
}


void VcpPagePanel::setCurrentFrame(VfxFrame *frame)
{
    VFX_ASSERT(frame->getParentFrame() == this);

    if (m_currentFramePtr.isValid())
    {
        m_currentFramePtr->setHidden(VFX_TRUE);
    }

    if (m_effectRunning)
    {
        m_pageEffect->onCancel(this, m_previousFramePtr.get(), m_currentFramePtr.get());
        VFX_OBJ_CLOSE(m_pageEffect);
        m_effectRunning = VFX_FALSE;
        if (m_deletePrevious)
        {
            VFX_OBJ_CLOSE(m_previousFramePtr);
        }
        else
        {
            if (m_previousFramePtr.isValid())
            {
                m_previousFramePtr->setHidden(VFX_TRUE);
            }
        }
        m_signalFinished.postEmit(m_currentFramePtr.get(), VFX_FALSE);
    }


    frame->bringToFront();
    frame->setHidden(VFX_FALSE);
    m_currentFramePtr = frame;
}


void VcpPagePanel::onEndOfEffect(void)
{
    if (m_pageEffect)
    {
        // m_pageEffect sometime NULL!?
        m_pageEffect->onStop(this, m_previousFramePtr.get(), m_currentFramePtr.get());
        VFX_OBJ_CLOSE(m_pageEffect);
    }
    m_effectRunning = VFX_FALSE;
    if (m_deletePrevious)
    {
        VFX_OBJ_CLOSE(m_previousFramePtr);
    }
    else
    {
        if (m_previousFramePtr.isValid())
        {
            m_previousFramePtr->setHidden(VFX_TRUE);
        }
    }
    m_signalFinished.postEmit(m_currentFramePtr.get(), VFX_TRUE);
}

/*****************************************************************************
 * Class VcpPageFadeInEffect
 *****************************************************************************/

VcpPageFadeInEffect::VcpPageFadeInEffect():
    m_fadeInTimeline(NULL)
{
}


void VcpPageFadeInEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(currentFrame);
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
    m_fadeInTimeline->setTarget(targetFrame);
    m_fadeInTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_fadeInTimeline->setDurationTime(duration);
    m_fadeInTimeline->setRepeatCount(1);
    m_fadeInTimeline->setFromValue(0);
    m_fadeInTimeline->setToValue(1.0f);
    m_fadeInTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_fadeInTimeline->m_signalStopped.connect(this, &VcpPageFadeInEffect::onEndOfEffect); 
    m_fadeInTimeline->start();
}


void VcpPageFadeInEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
}


void VcpPageFadeInEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
    m_fadeInTimeline->stop();
}


void VcpPageFadeInEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPageFlipEffect
 *****************************************************************************/

VcpPageFlipEffect::VcpPageFlipEffect()
{
    m_flipTimeline[0] = NULL;
    m_flipTimeline[1] = NULL;
}


void VcpPageFlipEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }
    VfxFloat tempCameraDistance = 240;
    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPageFilpData));
        tempCameraDistance = ((VcpPageFilpData*)data)->cameraDistance;
    }
    VcpPageFlipPara flipPara;
    
    if (currentFrame)
    {
        m_backupCulling[0] = currentFrame->getCullingType();
        currentFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        if (m_flipTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_flipTimeline[0], VfxTransformTimeline, this);
        }
        m_flipTimeline[0]->setTarget(currentFrame);
        m_flipTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_flipTimeline[0]->setDurationTime(duration);
        m_flipTimeline[0]->setRepeatCount(1);        
        flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                           0,1,0,0,
                                           0,0,1,0,
                                           (VfxFloat)(-1 * pagePanel->getBounds().getWidth()/2),(VfxFloat)(-1 * pagePanel->getBounds().getHeight()/2),0,1);
        flipPara.frameWidth = pagePanel->getBounds().getWidth();
        flipPara.frameHeight = pagePanel->getBounds().getHeight();
        flipPara.cameraDistance = tempCameraDistance;
        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_UP)
        {
            flipPara.direction = 1;
        }
        else
        {
            flipPara.direction = -1;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_LEFT)
        {
            flipPara.isVertical = VFX_FALSE;
        }
        else
        {
            flipPara.isVertical = VFX_TRUE;
        }
        m_flipTimeline[0]->setCustomInterpolateFunc(VcpPageFlipEffect::flipTimelineFunc,&flipPara,sizeof(flipPara));
        m_flipTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_flipTimeline[0]->start();
    }
    
    m_backupCulling[1] = targetFrame->getCullingType();
    targetFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    if (m_flipTimeline[1] == NULL)
    {
        VFX_OBJ_CREATE(m_flipTimeline[1], VfxTransformTimeline, this);
    }

    m_flipTimeline[1]->setTarget(targetFrame);
    m_flipTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_flipTimeline[1]->setDurationTime(duration);
    m_flipTimeline[1]->setRepeatCount(1);        
    
    
    flipPara.frameWidth = pagePanel->getBounds().getWidth();
    flipPara.frameHeight = pagePanel->getBounds().getHeight();
    flipPara.cameraDistance = tempCameraDistance;
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_UP)
    {
        flipPara.direction = 1;
    }
    else
    {
        flipPara.direction = -1;
    }
            
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_LEFT)
    {
        flipPara.relativeMatrix = VfxMatrix4x4(-1,0,0,0,
                                       0,1,0,0,
                                       0,0,-1,0,
                                       (VfxFloat)(pagePanel->getBounds().getWidth()/2),(VfxFloat)(-1*pagePanel->getBounds().getHeight()/2),0,1);
        flipPara.isVertical = VFX_FALSE;
    }
    else
    {
        flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                       0,-1,0,0,
                                       0,0,-1,0,
                                       (VfxFloat)(-1*pagePanel->getBounds().getWidth()/2),(VfxFloat)(pagePanel->getBounds().getHeight()/2),0,1);
        flipPara.isVertical = VFX_TRUE;
    }
    m_flipTimeline[1]->setCustomInterpolateFunc(VcpPageFlipEffect::flipTimelineFunc,&flipPara,sizeof(flipPara));
    m_flipTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_flipTimeline[1]->m_signalStopped.connect(this, &VcpPageFlipEffect::onEndOfEffect); 
    m_flipTimeline[1]->start();
}


void VcpPageFlipEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
    currentFrame->setCullingType(m_backupCulling[1]);
}


void VcpPageFlipEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (m_flipTimeline[0])
    {
        m_flipTimeline[0]->stop();
    }
    m_flipTimeline[1]->stop();
    
    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
	// the current frame may destory by app first when cancel
	if (currentFrame)
	{
		currentFrame->setCullingType(m_backupCulling[1]);
	}
}


void VcpPageFlipEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


VfxTimelineInterpolationRetEnum VcpPageFlipEffect::flipTimelineFunc(
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
    VFX_ASSERT(data_size == sizeof(VcpPageFlipPara));
    VcpPageFlipPara *flipPara = (VcpPageFlipPara*)data;
    VfxTransform *transform = (VfxTransform*)output;
    VfxFloat tempYAngle =  t * (180) * flipPara->direction;
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
    VfxFloat cameraDistance;

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
 * Class VcpPagePushEffect
 *****************************************************************************/

VcpPagePushEffect::VcpPagePushEffect():
    m_mode(VCP_PAGE_BOTH)
{
    m_pointTimeline[0] = NULL;
    m_pointTimeline[1] = NULL;
}


void VcpPagePushEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_UNUSED(data);
    VFX_UNUSED(dataSize);
    
    if (duration == -1)
    {
        duration = 250;
    }
    VfxPoint tempPoint;
       
    if (currentFrame && (m_mode == VCP_PAGE_BOTH || m_mode == VCP_PAGE_CURRENT))
    {
        if (m_mode == VCP_PAGE_CURRENT)
        {
            //let current frame be the last child of page
            currentFrame->bringToFront();
        }
        if (m_pointTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_pointTimeline[0], VfxPointTimeline, this);
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_LEFT)
        {
            tempPoint = VfxPoint(currentFrame->getPos().x + pagePanel->getBounds().getWidth(), currentFrame->getPos().y);
        }
        else if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT)
        {
            tempPoint = VfxPoint(currentFrame->getPos().x - pagePanel->getBounds().getWidth(), currentFrame->getPos().y);
        }
        else if (direction == VCP_PAGE_DIRECTION_FROM_UP)
        {
            tempPoint = VfxPoint(currentFrame->getPos().x, currentFrame->getPos().y + pagePanel->getBounds().getHeight());
        }
        else
        {
            tempPoint = VfxPoint(currentFrame->getPos().x, currentFrame->getPos().y - pagePanel->getBounds().getHeight());
        }
        m_pointTimeline[0]->setTarget(currentFrame);
        m_pointTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_pointTimeline[0]->setDurationTime(duration);
        m_pointTimeline[0]->setRepeatCount(1);
        m_pointTimeline[0]->setFromValue(currentFrame->getPos());
        m_pointTimeline[0]->setToValue(tempPoint);
        m_pointTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        if (m_mode == VCP_PAGE_CURRENT)
        {
            m_pointTimeline[0]->m_signalStopped.connect(this, &VcpPagePushEffect::onEndOfEffect); 
        }
        m_pointTimeline[0]->start();
    }
    if (m_mode == VCP_PAGE_BOTH || m_mode == VCP_PAGE_TARGET)
    {
        if (m_pointTimeline[1] == NULL)
        {
            VFX_OBJ_CREATE(m_pointTimeline[1], VfxPointTimeline, this);
        }
        if (direction == VCP_PAGE_DIRECTION_FROM_LEFT)
        {
            tempPoint = VfxPoint(targetFrame->getPos().x - pagePanel->getBounds().getWidth(), targetFrame->getPos().y);
        }
        else if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT)
        {
            tempPoint = VfxPoint(targetFrame->getPos().x + pagePanel->getBounds().getWidth(), targetFrame->getPos().y);
        }
        else if (direction == VCP_PAGE_DIRECTION_FROM_UP)
        {
            tempPoint = VfxPoint(targetFrame->getPos().x, targetFrame->getPos().y - pagePanel->getBounds().getHeight());
        }
        else
        {
            tempPoint = VfxPoint(targetFrame->getPos().x, targetFrame->getPos().y + pagePanel->getBounds().getHeight());
        }
        m_pointTimeline[1]->setTarget(targetFrame);
        m_pointTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        m_pointTimeline[1]->setDurationTime(duration);
        m_pointTimeline[1]->setRepeatCount(1);
        m_pointTimeline[1]->setFromValue(tempPoint);
        m_pointTimeline[1]->setToValue(targetFrame->getPos());
        m_pointTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_pointTimeline[1]->m_signalStopped.connect(this, &VcpPagePushEffect::onEndOfEffect); 
        m_pointTimeline[1]->start();
    }
}


void VcpPagePushEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
}


void VcpPagePushEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
    if (m_pointTimeline[0])
    {
        m_pointTimeline[0]->stop();
    }
    if (m_pointTimeline[1])
    {
        m_pointTimeline[1]->stop();
    }
}


void VcpPagePushEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPageZoomEffect
 *****************************************************************************/

VcpPageZoomEffect::VcpPageZoomEffect():
    m_mode(VCP_PAGE_BOTH)
{
    m_transformTimeline[0] = NULL;
    m_transformTimeline[1] = NULL;
    m_opacityTimeline[0] = NULL;
    m_opacityTimeline[1] = NULL;
}


void VcpPageZoomEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }
    VfxFloat sx1 = 2.0f;
    VfxFloat sy1 = 2.0f;
    VfxFloat sx2 = 0.2f;
    VfxFloat sy2 = 0.2f;
    if (data != NULL)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPageZoomData));
        sx1 = ((VcpPageZoomData*)data)->ScaleXonCurrentFrame;
        sy1 = ((VcpPageZoomData*)data)->ScaleYonCurrentFrame;
        sx2 = ((VcpPageZoomData*)data)->ScaleXonTargetFrame;
        sy2 = ((VcpPageZoomData*)data)->ScaleXonTargetFrame;
    }
    VfxTransform tempTransform;

    if (currentFrame && (m_mode == VCP_PAGE_BOTH || m_mode == VCP_PAGE_CURRENT))
    {
        if (m_mode == VCP_PAGE_CURRENT)
        {
            //let current frame be the last child of page
            currentFrame->bringToFront();
            currentFrame->setHidden(VFX_FALSE);
        }
        if (m_transformTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_transformTimeline[0], VfxTransformTimeline, this);
        }
        m_backupAnchor[0] = currentFrame->getAnchor();
        m_backupPos[0] = currentFrame->getPos();
        currentFrame->setPos(VfxPoint(
                                (VfxS32)(m_backupPos[0].x - currentFrame->getBounds().getWidth() * m_backupAnchor[0].x + currentFrame->getBounds().getWidth()/2) ,
                                (VfxS32)(m_backupPos[0].y - currentFrame->getBounds().getHeight() * m_backupAnchor[0].y + currentFrame->getBounds().getHeight()/2) 
                                ));
        currentFrame->setAnchor(VfxFPoint(0.5,0.5));
        tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            tempTransform.data.affine.sx = sx2;
            tempTransform.data.affine.sy = sy2;
        }
        else
        {
            tempTransform.data.affine.sx = sx1;
            tempTransform.data.affine.sy = sy1;
        }
        
        m_transformTimeline[0]->setTarget(currentFrame);
        m_transformTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_transformTimeline[0]->setDurationTime(duration);
        m_transformTimeline[0]->setRepeatCount(1);
        m_transformTimeline[0]->setFromValue(currentFrame->getTransform());
        m_transformTimeline[0]->setToValue(tempTransform);
        m_transformTimeline[0]->setIsFromCurrent(VFX_FALSE);
        m_transformTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        if (m_mode == VCP_PAGE_CURRENT)
        {
            m_transformTimeline[0]->m_signalStopped.connect(this, &VcpPageZoomEffect::onEndOfEffect); 
        }
        m_transformTimeline[0]->start();

        if (m_opacityTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_opacityTimeline[0], VfxFloatTimeline, this);
        }
        
        m_opacityTimeline[0]->setTarget(currentFrame);
        m_opacityTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_opacityTimeline[0]->setDurationTime(duration);
        m_opacityTimeline[0]->setRepeatCount(1);
        m_opacityTimeline[0]->setFromValue(currentFrame->getOpacity());
        m_opacityTimeline[0]->setToValue(0.0f);
        m_opacityTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_opacityTimeline[0]->start();
    }
    if (m_mode == VCP_PAGE_BOTH || m_mode == VCP_PAGE_TARGET)
    {
        if (m_transformTimeline[1] == NULL)
        {
            VFX_OBJ_CREATE(m_transformTimeline[1], VfxTransformTimeline, this);
        }
        m_backupAnchor[1] = targetFrame->getAnchor();
        m_backupPos[1] = targetFrame->getPos();
        targetFrame->setPos(VfxPoint(
                                (VfxS32)(m_backupPos[1].x - targetFrame->getBounds().getWidth() * m_backupAnchor[1].x + targetFrame->getBounds().getWidth()/2),
                                (VfxS32)(m_backupPos[1].y - targetFrame->getBounds().getHeight() * m_backupAnchor[1].y + targetFrame->getBounds().getHeight()/2)
                                ));
        targetFrame->setAnchor(VfxFPoint(0.5,0.5));
        tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            tempTransform.data.affine.sx = sx1;
            tempTransform.data.affine.sy = sy1;
        }
        else
        {
            tempTransform.data.affine.sx = sx2;
            tempTransform.data.affine.sy = sy2;
        }
        
        m_transformTimeline[1]->setTarget(targetFrame);
        m_transformTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_transformTimeline[1]->setDurationTime(duration);
        m_transformTimeline[1]->setRepeatCount(1);
        m_transformTimeline[1]->setFromValue(tempTransform);
        m_transformTimeline[1]->setToValue(VfxTransform(VFX_TRANSFORM_TYPE_AFFINE));
        m_transformTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_transformTimeline[1]->m_signalStopped.connect(this, &VcpPageZoomEffect::onEndOfEffect); 
        m_transformTimeline[1]->start();

        if (m_opacityTimeline[1] == NULL)
        {
            VFX_OBJ_CREATE(m_opacityTimeline[1], VfxFloatTimeline, this);
        }
        
        m_opacityTimeline[1]->setTarget(targetFrame);
        m_opacityTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
        m_opacityTimeline[1]->setDurationTime(duration);
        m_opacityTimeline[1]->setRepeatCount(1);
        m_opacityTimeline[1]->setFromValue(0.0f);
        m_opacityTimeline[1]->setToValue(1.0f);
        m_opacityTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        m_opacityTimeline[1]->start();
    }
    
}


void VcpPageZoomEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    if (lastFrame)
    {
        lastFrame->setPos(m_backupPos[0]);
        lastFrame->setAnchor(m_backupAnchor[0]);
    }
    currentFrame->setPos(m_backupPos[1]);
    currentFrame->setAnchor(m_backupAnchor[1]);
    VfxAutoAnimate::commit();
}


void VcpPageZoomEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (m_transformTimeline[0])
    {
        m_transformTimeline[0]->stop();
        m_opacityTimeline[0]->stop();
    }
    if (m_transformTimeline[1])
    {
        m_transformTimeline[1]->stop();
        m_opacityTimeline[1]->stop();
    }
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    if (lastFrame)
    {
        lastFrame->setPos(m_backupPos[0]);
        lastFrame->setAnchor(m_backupAnchor[0]);
    }
    // the current frame may destory by app first when cancel
	  if (currentFrame)
    {   
        currentFrame->setPos(m_backupPos[1]);
        currentFrame->setAnchor(m_backupAnchor[1]);
    }
    VfxAutoAnimate::commit();
}


void VcpPageZoomEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPageSmallFlipEffect
 *****************************************************************************/

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)    

VcpPageSmallFlipEffect::VcpPageSmallFlipEffect()
{
    m_flipTimeline[0] = NULL;
    m_flipTimeline[1] = NULL;
}


void VcpPageSmallFlipEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }
    VfxFloat tempCameraDistance = 480;
    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPageFilpData));
        tempCameraDistance = ((VcpPageFilpData*)data)->cameraDistance;
    }
    VcpPageFlipPara flipPara;
    
    if (currentFrame)
    {
        m_backupCulling[0] = currentFrame->getCullingType();
        currentFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        if (m_flipTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_flipTimeline[0], VfxTransformTimeline, this);
        }
        m_flipTimeline[0]->setTarget(currentFrame);
        m_flipTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_flipTimeline[0]->setDurationTime(duration);
        m_flipTimeline[0]->setRepeatCount(1);        
        flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                           0,1,0,0,
                                           0,0,1,0,
                                           (VfxFloat)(-1 * pagePanel->getBounds().getWidth()/2),(VfxFloat)(-1 * pagePanel->getBounds().getHeight()/2),0,1);
        flipPara.frameWidth = pagePanel->getBounds().getWidth();
        flipPara.frameHeight = pagePanel->getBounds().getHeight();
        flipPara.cameraDistance = tempCameraDistance;
        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_UP)
        {
            flipPara.direction = 1;
        }
        else
        {
            flipPara.direction = -1;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_LEFT)
        {
            m_flipTimeline[0]->setCustomInterpolateFunc(VcpPageSmallFlipEffect::flipHorizontalTimelineFunc,&flipPara,sizeof(flipPara));
        }
        else
        {
            m_flipTimeline[0]->setCustomInterpolateFunc(VcpPageSmallFlipEffect::flipVerticalTimelineFunc,&flipPara,sizeof(flipPara));
        }
        m_flipTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_flipTimeline[0]->start();
    }
    
    m_backupCulling[1] = targetFrame->getCullingType();
    targetFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    if (m_flipTimeline[1] == NULL)
    {
        VFX_OBJ_CREATE(m_flipTimeline[1], VfxTransformTimeline, this);
    }

    m_flipTimeline[1]->setTarget(targetFrame);
    m_flipTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_flipTimeline[1]->setDurationTime(duration);
    m_flipTimeline[1]->setRepeatCount(1);        
    
    
    flipPara.frameWidth = pagePanel->getBounds().getWidth();
    flipPara.frameHeight = pagePanel->getBounds().getHeight();
    flipPara.cameraDistance = tempCameraDistance;
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_UP)
    {
        flipPara.direction = 1;
    }
    else
    {
        flipPara.direction = -1;
    }
            
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_LEFT)
    {
        flipPara.relativeMatrix = VfxMatrix4x4(-1,0,0,0,
                                       0,1,0,0,
                                       0,0,-1,0,
                                       (VfxFloat)(pagePanel->getBounds().getWidth()/2),(VfxFloat)(-1*pagePanel->getBounds().getHeight()/2),0,1);
        m_flipTimeline[1]->setCustomInterpolateFunc(VcpPageSmallFlipEffect::flipHorizontalTimelineFunc,&flipPara,sizeof(flipPara));
    }
    else
    {
        flipPara.relativeMatrix = VfxMatrix4x4(1,0,0,0,
                                       0,-1,0,0,
                                       0,0,-1,0,
                                       (VfxFloat)(-1*pagePanel->getBounds().getWidth()/2),(VfxFloat)(pagePanel->getBounds().getHeight()/2),0,1);
        m_flipTimeline[1]->setCustomInterpolateFunc(VcpPageSmallFlipEffect::flipVerticalTimelineFunc,&flipPara,sizeof(flipPara));
    }
    m_flipTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_flipTimeline[1]->m_signalStopped.connect(this, &VcpPageSmallFlipEffect::onEndOfEffect); 
    m_flipTimeline[1]->start();
}


void VcpPageSmallFlipEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
    currentFrame->setCullingType(m_backupCulling[1]);
}


void VcpPageSmallFlipEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (m_flipTimeline[0])
    {
        m_flipTimeline[0]->stop();
    }
    m_flipTimeline[1]->stop();
    
    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
    // the current frame may destory by app first when cancel
	if (currentFrame)
    {   
        currentFrame->setCullingType(m_backupCulling[1]);
    }
}


void VcpPageSmallFlipEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


VfxTimelineInterpolationRetEnum VcpPageSmallFlipEffect::flipHorizontalTimelineFunc(
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
    VFX_ASSERT(data_size == sizeof(VcpPageFlipPara));
    VcpPageFlipPara *flipPara = (VcpPageFlipPara*)data;
    VfxTransform *transform = (VfxTransform*)output;
    VfxFloat tempYAngle;
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
    VfxFloat cameraDistance;

    if (t < 0.1)
    {
        cameraDistance = flipPara->cameraDistance + (t / 0.2f) * 0.2f * flipPara->cameraDistance;
        tempYAngle = t/0.1f * (10) * flipPara->direction;
    }
    if (t < 0.2)
    {
         cameraDistance = flipPara->cameraDistance + (t / 0.2f) * 0.2f * flipPara->cameraDistance;
         tempYAngle = (10.0f) * flipPara->direction;
    }
    else if (t < 0.8)
    {
        cameraDistance = 1.2f * flipPara->cameraDistance;
        tempYAngle =  ((t - 0.2f)/0.6f * (160) + 10) * flipPara->direction;
    }
    else if (t < 0.9)
    {
        cameraDistance = flipPara->cameraDistance + (1- ((t - 0.8f) / 0.2f)) * 0.2f * flipPara->cameraDistance;
        tempYAngle =  (170.0f) * flipPara->direction;
    }
    else
    {
        cameraDistance = flipPara->cameraDistance + (1- ((t - 0.8f) / 0.2f)) * 0.2f * flipPara->cameraDistance;
        tempYAngle =  ((t - 0.9f)/0.1f * (10) + (170)) * flipPara->direction;
    }

    RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));
   
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


VfxTimelineInterpolationRetEnum VcpPageSmallFlipEffect::flipVerticalTimelineFunc(
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
    VFX_ASSERT(data_size == sizeof(VcpPageFlipPara));
    VcpPageFlipPara *flipPara = (VcpPageFlipPara*)data;
    VfxTransform *transform = (VfxTransform*)output;
    VfxFloat tempYAngle;
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
    VfxFloat cameraDistance;

    if (t < 0.1)
    {
        cameraDistance = flipPara->cameraDistance + (t / 0.2f) * 0.2f * flipPara->cameraDistance;
        tempYAngle = t/0.1f * (10) * flipPara->direction;
    }
    if (t < 0.2)
    {
         cameraDistance = flipPara->cameraDistance + (t / 0.2f) * 0.2f * flipPara->cameraDistance;
         tempYAngle = (10.0f) * flipPara->direction;
    }
    else if (t < 0.8)
    {
        cameraDistance = 1.2f * flipPara->cameraDistance;
        tempYAngle =  ((t - 0.2f)/0.6f * (160) + 10) * flipPara->direction;
    }
    else if (t < 0.9)
    {
        cameraDistance = flipPara->cameraDistance + (1- ((t - 0.8f) / 0.2f)) * 0.2f * flipPara->cameraDistance;
        tempYAngle =  (170.0f) * flipPara->direction;
    }
    else
    {
        cameraDistance = flipPara->cameraDistance + (1- ((t - 0.8f) / 0.2f)) * 0.2f * flipPara->cameraDistance;
        tempYAngle =  ((t - 0.9f)/0.1f * (10) + (170)) * flipPara->direction;
    }

    RotatebyYMatrix.setRotateByX(VFX_DEG_TO_RAD(tempYAngle));

    totalProject.setCamera( 
        1.0f,
        1.0f, 
        (VfxFloat)flipPara->frameWidth/2, 
        (VfxFloat)flipPara->frameHeight/2, 
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

#endif

/*****************************************************************************
 * Class VcpPageCosmosEntryEffect
 *****************************************************************************/

VcpPageCosmosEntryEffect::VcpPageCosmosEntryEffect() : 
    m_fpeTimeline(NULL)
{
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    m_currentFrame = NULL;
    m_targetFrame = NULL;
#endif
}


void VcpPageCosmosEntryEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{

    if (duration == -1)
    {
        duration = 350;
    }

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VfxBool useBuff = VFX_FALSE;


    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }
#endif

    VfxFrame *currentFrame1 = currentFrame;
    VfxFrame *targetFrame1 = targetFrame;

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)

    VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;

    if (useBuff)
    {
        if (currentFrame)
        {
            currentFrame->setHidden(VFX_TRUE);

            VFX_OBJ_CREATE(m_currentFrame, VfxFrame, pagePanel);
            currentFrame1 = m_currentFrame;
            currentFrame1->setHidden(VFX_FALSE);
            currentFrame1->setSize(currentFrame->getSize());
          
            VfxMaterial *material;
            VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));
            currentFrame1->setMaterial(material);

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, material);
            material->setPass(0, pass);

            VfxShaderProgram *program;
            VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_RES_ID_NULL, VCP_FRG_PAGE_PANEL_SIMPLE));
            pass->setShaderProgram(program);

            VfxShaderUniforms *uniforms;
            VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);

            VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
            pass->addShaderUniforms(uniforms);

            VfxImage2D *img;
            VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (bufferData->oldImageSrc));

            VfxTexture2D *texture;
            VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
            var->setValue(texture);

            VfxCompositingMode *cm;
            VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
            cm->setDepthTestEnable(VFX_FALSE);
            pass->setCompositingMode(cm);

            VfxBlender *blender;
            VFX_OBJ_CREATE(blender, VfxBlender, cm);
            cm->setBlender(blender);
    
        }

        if (targetFrame)
        {
            targetFrame->setHidden(VFX_TRUE);

            VFX_OBJ_CREATE(m_targetFrame, VfxFrame, pagePanel);
            targetFrame1 = m_targetFrame;
            targetFrame1->setHidden(VFX_FALSE);
            targetFrame1->setSize(targetFrame->getSize());

            VfxMaterial *material;
            VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));
            targetFrame1->setMaterial(material);
           

            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, material);
            material->setPass(0, pass);

            VfxShaderProgram *program;
            VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_RES_ID_NULL, VCP_FRG_PAGE_PANEL_SIMPLE));
            pass->setShaderProgram(program);

            VfxShaderUniforms *uniforms;
            VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);

            VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
            pass->addShaderUniforms(uniforms);

            VfxImage2D *img;
            VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (bufferData->newImageSrc));

            VfxTexture2D *texture;
            VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
            var->setValue(texture);

            VfxCompositingMode *cm;
            VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
            cm->setDepthTestEnable(VFX_FALSE);
            pass->setCompositingMode(cm);
            

            VfxBlender *blender;
            VFX_OBJ_CREATE(blender, VfxBlender, cm);
            cm->setBlender(blender);
        }
    }
#endif

    if (currentFrame1)
    {
        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            currentFrame1->setPropertyEffectCallback(
                    pagePanel,
                    secondEffectCallback,
                    NULL,
                    0,
                    VRT_FPE_TRIGGER_TYPE_DIRTY);
        }
        else
        {
            currentFrame1->setPropertyEffectCallback(
                    pagePanel,
                    firstEffectCallback,
                    NULL,
                    0,
                    VRT_FPE_TRIGGER_TYPE_DIRTY);
        }
    }

    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        targetFrame1->setPropertyEffectCallback(
                    pagePanel,
                    firstEffectCallback,
                    NULL,
                    0,
                    VRT_FPE_TRIGGER_TYPE_DIRTY);
    }
    else
    {
        targetFrame1->setPropertyEffectCallback(
                    pagePanel,
                    secondEffectCallback,
                    NULL,
                    0,
                    VRT_FPE_TRIGGER_TYPE_DIRTY);
    }

    if (m_fpeTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_fpeTimeline, VfxFloatTimeline, this);
    }
    
    m_fpeTimeline->setTarget(pagePanel);
    m_fpeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_fpeTimeline->setDurationTime(duration);
    m_fpeTimeline->setRepeatCount(1);
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        m_fpeTimeline->setFromValue(1.0f);
        m_fpeTimeline->setToValue(0.0f);
    }
    else
    {
        m_fpeTimeline->setFromValue(0.0f);
        m_fpeTimeline->setToValue(1.0f);
    }
    m_fpeTimeline->setIsFromCurrent(VFX_FALSE);
    m_fpeTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_fpeTimeline->m_signalStopped.connect(this, &VcpPageCosmosEntryEffect::onEndOfEffect); 
	m_fpeTimeline->start();
    
}


void VcpPageCosmosEntryEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setPropertyEffectCallback(
                                NULL,
                                NULL,
                                NULL,
                                0);
    }
    if (currentFrame)
    {
        currentFrame->setPropertyEffectCallback(
                                NULL,
                                NULL,
                                NULL,
                                0);
    }
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CLOSE(m_currentFrame);
    VFX_OBJ_CLOSE(m_targetFrame);
#endif
}


void VcpPageCosmosEntryEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);

    if (lastFrame)
    {
        lastFrame->setPropertyEffectCallback(
                                NULL,
                                NULL,
                                NULL,
                                0);
    }
    if (currentFrame)
    {
        currentFrame->setPropertyEffectCallback(
                                    NULL,
                                    NULL,
                                    NULL,
                                    0);
    }
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CLOSE(m_currentFrame);
    VFX_OBJ_CLOSE(m_targetFrame);
#endif
}


void VcpPageCosmosEntryEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

vrt_render_dirty_type_enum VcpPageCosmosEntryEffect::firstEffectCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame);
    VFX_DEV_ASSERT(watch_frame);
    VfxFloat t = watch_frame->filter_timing;
    VfxFloat i = 1.5f * t;
    if ( i > 1.0f)
    {
        i = 1.0f;
    }

    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = 1.0f + 0.5f * i * i * i * i;
    target_frame->transform.data.affine.sy = 1.0f + 0.5f * i * i * i * i;

    target_frame->opacity = 1.0f - i * i;
    
    target_frame->anchor_point.x = 0.5f; 
    target_frame->anchor_point.y = 0.5f;
    target_frame->pos.x = (VfxS32)(watch_frame->bounds.size.width/2.0f);
    target_frame->pos.y = (VfxS32)(watch_frame->bounds.size.height * 0.8f * i * i * i + watch_frame->bounds.size.height / 2);
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


vrt_render_dirty_type_enum VcpPageCosmosEntryEffect::secondEffectCallback(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame);
    VFX_DEV_ASSERT(watch_frame);

    VfxFloat t = watch_frame->filter_timing;

    VfxFloat i = (t - 0.5f) * 2;
    if (i < 0)
    {
        i = 0;
    }
    VfxFloat j = 1.0f - i;

    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;
    target_frame->transform.data.affine.sx = 1.0f - 0.6f * j * j * j * j;
    target_frame->transform.data.affine.sy = 1.0f - 0.6f * j * j * j * j;

    if (i == 0)
    {
        target_frame->opacity = 0;
    }
    else
    {
        target_frame->opacity = target_frame->transform.data.affine.sx;
    }
    
    target_frame->anchor_point.x = 0.5f; 
    target_frame->anchor_point.y = 0.5f;
    target_frame->pos.x = (VfxS32)(watch_frame->bounds.size.width/2.0f);
    target_frame->pos.y = (VfxS32)(watch_frame->bounds.size.height/2.0f);
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


/*****************************************************************************
 * Class VcpPageCubeEffect
 *****************************************************************************/

VcpPageCubeEffect::VcpPageCubeEffect()
{
    m_flipTimeline[0] = NULL;
    m_flipTimeline[1] = NULL;
}


void VcpPageCubeEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }
    VfxFloat tempCameraDistance = 520;
    
    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPageFilpData));
        tempCameraDistance = ((VcpPageFilpData*)data)->cameraDistance;
    }
    
    if (currentFrame)
    {
        m_backupCulling[0] = currentFrame->getCullingType();
        currentFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
        if (m_flipTimeline[0] == NULL)
        {
            VFX_OBJ_CREATE(m_flipTimeline[0], VfxTransformTimeline, this);
        }
        m_flipTimeline[0]->setTarget(currentFrame);
        m_flipTimeline[0]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
        m_flipTimeline[0]->setDurationTime(duration);
        m_flipTimeline[0]->setRepeatCount(1);

        // config rotate parameters
        VcpPageCubePara cubePara;

        cubePara.frameWidth = pagePanel->getBounds().getWidth();
        cubePara.frameHeight = pagePanel->getBounds().getHeight();
        cubePara.cameraDistance = tempCameraDistance;
        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT)
        {
            cubePara.direction = 1;
        }
        else
        {
            cubePara.direction = -1;
        }
        VfxMatrix4x4 relativeMatirx;
        relativeMatirx.setTranslation((VfxFloat)(-1 * cubePara.frameWidth/2), 
                        (VfxFloat)(-1 * cubePara.frameHeight/2), 
                        (VfxFloat)(-1 * cubePara.frameWidth/2));
        cubePara.relativeMatrix = relativeMatirx;

        m_flipTimeline[0]->setCustomInterpolateFunc(VcpPageCubeEffect::rotateTimelineFunc,&cubePara,sizeof(cubePara));
        m_flipTimeline[0]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
        m_flipTimeline[0]->start();
    }

    m_backupCulling[1] = targetFrame->getCullingType();
    targetFrame->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    if (m_flipTimeline[1] == NULL)
    {
        VFX_OBJ_CREATE(m_flipTimeline[1], VfxTransformTimeline, this);
    }

    m_flipTimeline[1]->setTarget(targetFrame);
    m_flipTimeline[1]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_flipTimeline[1]->setDurationTime(duration);
    m_flipTimeline[1]->setRepeatCount(1);        
    
    // config rotate parameters

    VcpPageCubePara cubePara;

    cubePara.frameWidth = pagePanel->getBounds().getWidth();
    cubePara.frameHeight = pagePanel->getBounds().getHeight();
    cubePara.cameraDistance = tempCameraDistance;

    VfxMatrix4x4 relativeMatirx;
    VfxMatrix4x4 temp;
    relativeMatirx.setTranslation((VfxFloat)(-1 * cubePara.frameWidth/2), 
                    (VfxFloat)(-1 * cubePara.frameHeight/2), 
                    (VfxFloat)(-1 * cubePara.frameWidth/2));
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT)
    {
        cubePara.direction = 1;

        temp = VfxMatrix4x4(0,0,1,0,
                         0,1,0,0,
                         -1,0,0,0,
                         (VfxFloat)(cubePara.frameWidth-1),0,0,1);
    }
    else
    {
        cubePara.direction = -1;

        temp = VfxMatrix4x4(0,0,-1,0,
                         0,1,0,0,
                         1,0,0,0,
                         0,0,(VfxFloat)(cubePara.frameWidth-1),1);
        
    }
    
    cubePara.relativeMatrix = relativeMatirx * temp;
   

    m_flipTimeline[1]->setCustomInterpolateFunc(VcpPageCubeEffect::rotateTimelineFunc,&cubePara,sizeof(cubePara));    
    m_flipTimeline[1]->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_flipTimeline[1]->m_signalStopped.connect(this, &VcpPageCubeEffect::onEndOfEffect); 
    m_flipTimeline[1]->start();
}


void VcpPageCubeEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
    // the current frame may destory by app first when cancel
	if (currentFrame)
    {   
        currentFrame->setCullingType(m_backupCulling[1]);
    }
}


void VcpPageCubeEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (m_flipTimeline[0])
    {
        m_flipTimeline[0]->stop();
    }
    m_flipTimeline[1]->stop();

    if (lastFrame)
    {
        lastFrame->setCullingType(m_backupCulling[0]);
    }
    // the current frame may destory by app first when cancel
	if (currentFrame)
    {   
        currentFrame->setCullingType(m_backupCulling[1]);
    }
}


void VcpPageCubeEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

VfxTimelineInterpolationRetEnum VcpPageCubeEffect::rotateTimelineFunc(
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
    VFX_ASSERT(typeId == VRT_TYPE_ID_TRANSFORM);
    VFX_ASSERT(data_size == sizeof(VcpPageCubePara));
    VcpPageCubePara *rotatePara = (VcpPageCubePara*)data;
    VfxTransform *transform = (VfxTransform*)output;
    VfxFloat tempYAngle =  t * (90.0f) * rotatePara->direction;
    VfxMatrix4x4 RotatebyYMatrix;
    VfxMatrix4x4 totalProject;
    VfxFloat cameraDistance;

    RotatebyYMatrix.setRotateByY(VFX_DEG_TO_RAD(tempYAngle));

    /* 0.414214 = sqrt(2) - 1 */
    cameraDistance = rotatePara->cameraDistance + 0.414214f * rotatePara->frameWidth/2 * vfxSin(VFX_ABS(tempYAngle)/90.0f * VFX_PI);

    totalProject.setCamera( 
        1.0f,
        1.0f, 
        (VfxFloat)(rotatePara->frameWidth/2), 
        (VfxFloat)(rotatePara->frameHeight/2), 
        rotatePara->cameraDistance - rotatePara->frameWidth/2, 
        cameraDistance, 
        0,
        0, 
        0);
    
    totalProject *= RotatebyYMatrix;
    totalProject *= rotatePara->relativeMatrix;
    totalProject.initMatrix3x3(transform->data.matrix3x3);
    transform->type = VRT_TRANSFORM_TYPE_MATRIX3X3;
    
    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}



