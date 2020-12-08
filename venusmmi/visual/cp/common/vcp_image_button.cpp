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
 *  vcp_img_button.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *  A image button control for Venus UI
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
 *
 *
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
#include "vcp_image_button.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vcp_state_image.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_image_src.h"
#include "vfx_adp_device.h"
#include "vfx_screen.h"
#include "vfx_top_level.h"

#if defined(__COSMOS_MMI__) || defined(__COSMOS_3D_V10__)
#include "mmi_rp_srv_venus_component_button_def.h"
#endif // __COSMOS_MMI__

#define HIDE_DURATION 250

static const VfxFloat VCP_IMG_BUTTON_DEFAULT_RATIO = 1.0f;

static const VfxS32 VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE = VFX_TOUCH_FINGER_WIDTH * 2;
static const VfxS32 VCP_IMAGE_BUTTON_PEN_INNER_MARGIN = VFX_TOUCH_FINGER_WIDTH * 3 / 2;
static const VfxS32 VCP_IMAGE_BUTTON_PEN_OUTER_MARGIN = VFX_TOUCH_FINGER_WIDTH * 2;

#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 


/*****************************************************************************
* Class VcpGlowBaseFrame
*****************************************************************************/

class VcpGlowBaseFrame : public VfxFrame
{
public:
    virtual void createGlow(VfxFrame * parentFrame) = 0;

    virtual void setGlowRect(const VfxRect & rect) = 0;

    virtual void showGlow() = 0;

    virtual void hideGlow() = 0;
};


/*****************************************************************************
* Class VcpGlow2DFrame
*****************************************************************************/

class VcpGlow2DFrame : public VcpGlowBaseFrame
{
public:
	VcpGlow2DFrame():
      m_opacityTimeline(NULL)
    {
    }

    virtual void createGlow(VfxFrame * parentFrame)
    {
        parentFrame->addChildFrame(this);
        setIsUnhittable(VFX_TRUE);
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
#ifdef __COSMOS_MMI__
        VfxImageSrc effectImgSrc(VCP_IMG_BUTTON_GLOW_EFFECT);
        setImgContent(effectImgSrc);
#endif
        VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
        m_opacityTimeline->setTarget(this);
        m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    }

    virtual void setGlowRect(const VfxRect & rect)
    {
        setRect(rect);
    }

    virtual void showGlow()
    {
        m_opacityTimeline->stop();
        setOpacity(1.0);
    }

    virtual void hideGlow()
    {
        m_opacityTimeline->setDurationTime(HIDE_DURATION);
        m_opacityTimeline->setIsFromCurrent(VFX_TRUE);
        m_opacityTimeline->setToValue(0.0f);
        m_opacityTimeline->start();
    }
private:
    VfxFloatTimeline * m_opacityTimeline;
};

VcpGlowBaseFrame * createGlowEffectFrame(VfxObject * parent, VfxFrame * parentFrame, VcpGlowVisualTypeEnum type)
{
    VcpGlowBaseFrame * result;
    VFX_OBJ_CREATE(result, VcpGlow2DFrame, parent);
    result->createGlow(parentFrame);
    result->setCacheMode(VFX_CACHE_MODE_FORCE);
    return result;
}


/*****************************************************************************
 * Global Variable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpImageButton", VcpImageButton, VfxControl);


/*****************************************************************************
 * Class VcpImageButton
 *****************************************************************************/
VcpImageButton::VcpImageButton():
m_isHapticTouchEnabled(VFX_FALSE),
m_state(VCP_IMAGE_BUTTON_STATE_NORMAL),
m_isStretchMode(VFX_FALSE),
m_isHighlight(VFX_FALSE),
m_imageList(0,0,0,0),
m_isEffect(VFX_FALSE),
m_effectRatio(VCP_IMG_BUTTON_DEFAULT_RATIO),
m_effectSize(0, 0),
m_effectOffset(0, 0),
m_id(0),
m_effectRect(0,0,0,0),
m_effectFrame(NULL),
m_effectType(VCP_GLOW_VISUAL_TYPE_2D),
m_timer(NULL)
{

}

void VcpImageButton::setIsHighlight(VfxBool isHighlight)
{
    if (m_isHighlight != isHighlight)
    {
        m_isHighlight = isHighlight;
        checkUpdate();
    }
}

void VcpImageButton::setState(VcpImageButtonStateEnum state)
{

    if (m_state != state)
    {
        m_state = state;
        switch(m_state)
        {
        case VCP_IMAGE_BUTTON_STATE_DISABLED:
        case VCP_IMAGE_BUTTON_STATE_NORMAL:
            if (m_isEffect)
            {
                launchHideGlow();
                m_timer->start();
            }
            break;            
        case VCP_IMAGE_BUTTON_STATE_PRESSED:
            if (m_isEffect)
            {
                launchEffect();
            }
            break;
        default:
            break;
        }
        checkUpdate();

        m_signalStateChanged.postEmit(this, m_state);
    }
}

VcpImageButtonStateEnum VcpImageButton::getState() const
{
    return m_state;
}

void VcpImageButton::setImage (const VcpStateImage &imageList)
{
    m_imageList = imageList;
    checkUpdate();
}

void VcpImageButton::setIsStretchMode(VfxBool  isStretchMode)
{
    m_isStretchMode = isStretchMode;
    checkUpdate();
}

void VcpImageButton::setId(VfxId    id)
{
    m_id = id;
}

const VcpStateImage &VcpImageButton::getImage () const
{
    return m_imageList;
}

VfxBool VcpImageButton::getIsStretchMode() const
{
    return m_isStretchMode;
}

VfxId VcpImageButton::getId() const
{
    return m_id;
}

void VcpImageButton::setIsEffect(VfxBool  isEffect)
{
    m_isEffect = isEffect;
    checkUpdate();
}

VfxBool VcpImageButton::getIsEffect() const
{
    return m_isEffect;
}

void VcpImageButton::setEffectRatio(VfxFloat  ratio)
{
    m_effectRatio = ratio;
    visualLayout();
}

VfxFloat VcpImageButton::getEffectRatio() const
{
    return m_effectRatio;
}

void VcpImageButton::setEffectSize(VfxSize size)
{
    m_effectRatio = -1.0f;
    m_effectSize = size;
    visualLayout();
}

VfxSize VcpImageButton::getEffectSize()
{
    if (m_effectRatio >= 0.0f)
    {
        VfxSize visualSize;
        visualSize.width = (int) (m_effectRatio * getSize().width); 
        visualSize.height = (int) (m_effectRatio * getSize().height); 
        return visualSize;
    }
    else
    {
        return m_effectSize;
    }
}

void VcpImageButton::setEffectOffset(VfxPoint offset)
{
    m_effectOffset = offset;
    visualLayout();
}

VfxPoint VcpImageButton::getEffectOffset()
{
    return m_effectOffset;
}

void VcpImageButton::setEffectGlowType(VcpGlowVisualTypeEnum type)
{
    m_effectType = type;
}

VcpGlowVisualTypeEnum VcpImageButton::getEffectGlowType()
{
    return m_effectType;
}

VfxBool VcpImageButton::onPenInput(VfxPenEvent &event)
{
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            if (!getIsDisabled() )
            {
                if(getIsHapticTouchEnabled())
                {
                    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                }
                setPressed(VFX_TRUE);
            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                VfxRect bounds = getBounds();
                if (m_state == VCP_IMAGE_BUTTON_STATE_PRESSED)
                {   // reset button while move out of button
                    VfxRect outerBounds(bounds.getX() - VCP_IMAGE_BUTTON_PEN_OUTER_MARGIN, bounds.getY() - VCP_IMAGE_BUTTON_PEN_OUTER_MARGIN,
                        bounds.getWidth() + 2 * VCP_IMAGE_BUTTON_PEN_OUTER_MARGIN, bounds.getHeight() + 2 * VCP_IMAGE_BUTTON_PEN_OUTER_MARGIN);
                    VfxBool isInOuterBounds = outerBounds.contains(event.getRelPos(this) );
                    if (!isInOuterBounds)
                    {
                        setPressed(VFX_FALSE);
                    }
                }
                else if (!getIsDisabled() )
                {
                    VfxRect innerBounds(bounds.getX() - VCP_IMAGE_BUTTON_PEN_INNER_MARGIN, bounds.getY() - VCP_IMAGE_BUTTON_PEN_INNER_MARGIN,
                        bounds.getWidth() + 2 * VCP_IMAGE_BUTTON_PEN_INNER_MARGIN, bounds.getHeight() + 2 * VCP_IMAGE_BUTTON_PEN_INNER_MARGIN);
                    VfxBool isInInnerBounds = innerBounds.contains(event.getRelPos(this) );
                    if (isInInnerBounds)
                    {
                        if(getIsHapticTouchEnabled())
                        {
                            vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                        }
                        setPressed(VFX_TRUE);
                    }
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_state == VCP_IMAGE_BUTTON_STATE_PRESSED)
            {
                setPressed(VFX_FALSE);
                VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                renderer->blockAfterNextCommit(1, VfxCallback0(this, &VcpImageButton::onAfterClick));
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            if (m_state == VCP_IMAGE_BUTTON_STATE_PRESSED)
            {
                setPressed(VFX_FALSE);
            }
            break;

        default:
            break;
    }

    // handle all events
    return VFX_TRUE;
}

VfxBool VcpImageButton::onContainPoint(const VfxPoint &point) const
{
    VfxRect bounds = getBounds();
    if (bounds.size.width < VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.x -= (VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE - bounds.size.width) / 2;
        bounds.size.width = VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE;
    }
    if (bounds.size.height < VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.y -= (VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE - bounds.size.height) / 2;
        bounds.size.height = VCP_IMAGE_BUTTON_TOUCH_MINIMAL_SIZE;
    }
    return bounds.contains(point);
}

void VcpImageButton::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbI", SA_start); 
#endif
    VfxControl::onInit();

    setAutoAnimate(VFX_TRUE);
    setFuzzy(VFX_TRUE);

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &VcpImageButton::stopEffect);
    m_timer->setStartDelay(HIDE_DURATION);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbI", SA_stop); 
#endif	
}


VfxBool VcpImageButton::onKeyInput(VfxKeyEvent &event)
{
    return VfxControl::onKeyInput(event);
}

void VcpImageButton::setIsHapticTouchEnabled(VfxBool state)
{
       m_isHapticTouchEnabled = state;
}

VfxBool VcpImageButton::getIsHapticTouchEnabled()
{
    return m_isHapticTouchEnabled;
}


void VcpImageButton::visualLayout()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbV", SA_start); 
#endif
    VfxPoint    visualPos;
    VfxSize     visualSize;
    VfxSize     buttonSize;

    buttonSize = getSize();

    if (m_effectRatio >= 0.0f)
    {
        visualSize.width = (int) (m_effectRatio * buttonSize.width); 
        visualSize.height = (int) (m_effectRatio * buttonSize.height); 
    }
    else
    {
        visualSize = m_effectSize;
    }

    visualPos.x = -(visualSize.width - buttonSize.width) / 2;
    visualPos.y = -(visualSize.height - buttonSize.height) / 2;
    visualPos.x += m_effectOffset.x;
    visualPos.y += m_effectOffset.y;

    m_effectRect = VfxRect(visualPos, visualSize);
    checkUpdate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbV", SA_stop); 
#endif	
}


void VcpImageButton::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

    visualLayout();
}


void VcpImageButton::setBounds(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height)
{
    setBounds(VfxRect(x, y, width, height));
}


void VcpImageButton::setIsDisabled(VfxBool isDisabled)
{
    if (VfxControl::getIsDisabled() == isDisabled)
        return;
    VfxControl::setIsDisabled(isDisabled);
    if (isDisabled == VFX_TRUE)
        setState(VCP_IMAGE_BUTTON_STATE_DISABLED);
    else
        setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    checkUpdate();
}


void VcpImageButton::setPressed(VfxBool isPressed)
{
    if (isPressed && (m_state == VCP_IMAGE_BUTTON_STATE_NORMAL))
    {
        setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
    }
    else if (!isPressed && (m_state == VCP_IMAGE_BUTTON_STATE_PRESSED))
    {
        setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
    }
}

void  VcpImageButton::onUpdate()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbU", SA_start); 
#endif
    VfxImageSrc   img;
    switch(m_state)
    {
    case VCP_IMAGE_BUTTON_STATE_NORMAL:
        if (m_isHighlight == VFX_FALSE)
            img = m_imageList.getImageNormal();
        else
            img = m_imageList.getImageHighlight();
        break;

    case VCP_IMAGE_BUTTON_STATE_PRESSED:
        img = m_imageList.getImagePressed();
        break;

    case VCP_IMAGE_BUTTON_STATE_DISABLED:
        img = m_imageList.getImageDisabled();
        break;

    default:
        break;
    }
    setImgContent(img);

    if (m_isStretchMode)
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    else
        setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("IbU", SA_stop); 
#endif	
}

void VcpImageButton::onAfterClick()
{
    m_signalClicked.postEmit(this, m_id);
}

void VcpImageButton::launchEffect()
{       
    VfxFrame * bindingParent = findBindingParent();
    if (bindingParent == NULL)
    {
        return;
    }
    if(!m_effectFrame)
    {
        m_effectFrame = createGlowEffectFrame(this, bindingParent, m_effectType);
    }
    VfxPoint posInScreen;
    VfxRect rectOnScreen;
    posInScreen = bindingParent->convertPointFrom(m_effectRect.origin, this);
    rectOnScreen = VfxRect(posInScreen, m_effectRect.size);

    m_effectFrame->setGlowRect(rectOnScreen);
    m_effectFrame->showGlow();
}

void VcpImageButton::stopEffect(VfxTimer *timer)
{
    if(timer)
    {
        timer->stop();
    }
    if(m_effectFrame)
    {
        VFX_OBJ_CLOSE(m_effectFrame);
    }
}

VfxFrame* VcpImageButton::findBindingScreen()
{
    VfxFrame*   frame;
    for (   frame = this;
            frame != NULL && (NULL == VFX_OBJ_DYNAMIC_CAST(frame, VfxScreen)) &&
            (NULL == VFX_OBJ_DYNAMIC_CAST(frame, VfxTopLevel));
            frame = frame->getParentFrame());
    return frame;
}

VfxFrame* VcpImageButton::findBindingParent()
{
    VfxFrame*   screen = findBindingScreen();
    if (screen == NULL)
    {
        return NULL;
    }

    VfxFrame*   bindingFrame = this;
    VfxFrame*   frame = bindingFrame;
    while (frame != NULL)
    {
        if (screen == frame)
        {
            return screen;
        }
        VfxRect glowRect = screen->convertRectFrom(m_effectRect, bindingFrame);
        VfxRect frameRect = screen->convertRectFrom(frame->getBounds(), frame);
        glowRect.intersectWith(screen->getBounds());
        frameRect.intersectWith(screen->getBounds());
        VfxRect tempRect = frameRect;
		tempRect.unionWith(glowRect);
        if (tempRect == frameRect && glowRect != frameRect)
        {
            return frame;
        }

        frame = frame->getParentFrame();
    }
    return frame;
}

void  VcpImageButton::launchHideGlow()
{
    if(m_effectFrame)
    {
        m_effectFrame->hideGlow();
    }
}
